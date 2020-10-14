.. include:: /replacevars.rst.inc

CPSW9g virtual MAC (remoteproc)
-------------------------------------------------------

Introduction
""""""""""""

The TI |__PART_FAMILY_NAME__| SoC has integrated nine-port Gigabit Ethernet Switch subsystem
into device MAIN domain named CPSW0 and has 8 external Ethernet ports.

The |__SDK_FULL_NAME__| on the |__PART_FAMILY_NAME__| family of SoC's does not allow direct access to CPSW0 from Linux and
the CPSW0 is placed under exclusive control of the EthSwitch firmware running on one of the R5F cores (main_r5fss0_core0 by default).

Only the EthSwitch firmware has full control over |__PART_FAMILY_NAME__| CPSW0 and allows segregate
Ethernet traffic for each attached Remote CPU by using programable ALE classifiers and
exclusive UDMA TX channels and RX flows. The EthSwitch firmware supports the rpmsg-kdrv protocol and presents itself
as a rpmsg-kdrv device, which provides CPSW0 resource management and debugging services for each attached Remote CPU.

The |__SDK_FULL_NAME__| on the |__PART_FAMILY_NAME__| family of SoC's contains a solution to allow sending/receiving Ethernet traffic
directed to/from CPU Core running Linux using a standard Linux network device.
The provided solution is implemented by two drivers:
- drivers/rpmsg-kdrv/rpmsg_kdrv_switch.c
- drivers/net/ethernet/ti/j721e-cpsw-virt-mac.c

This solution is illustrated below.

.. note::

   Overall TI remoteproc/virtio/rpmsg/rpmsg-kdrv description is out of scope of this section.

::

 User space           +------+
 +--------------------+ethX  +----------------------------------------+
                      +--^---+
                        |
                        |
                +-------v-----+
                |Net core     |
                +-----^-------+
                      |
       +--------------v--------------------+ rpmsg_remotedev/
       | main_r5fss_cpsw9g_virt_mac0       | rpmsg_remotedev_eth_switch_ops API
       | ethernet/ti/j721e-cpsw-virt-mac.c <--------+
       +-----------------------------------+        |
                                                    |
                           +------------------------v------+
                           | mpu_1_0_ethswitch-device-0    |
                           | rpmsg-kdrv/rpmsg_kdrv_switch.c|
                           +-------------^-----------------+
        rpmsg_kdr Bus                    |
      +---------------------^--------+--------------------------+
                            |
                       +----+--------+
                       | rpmsg-kdrv  |
                       |             |
                       +----^--------+
        RPMSG Bus           |
      +---------------------+-----------------^-----------------+
                                              |
                                     +--------+--------------+
                                     |   virtio_rpmsg_bus    |
                                     |                       |
                                     +--------^--------------+
                                              |
                                              |
                                     +--------v--------------+
                                     | remoteproc            |
                                     | ti_k3_r5_remoteproc   |
                                     +--------+--------------+
 Kernel                                       |
 +--------------------------------------------|------------------------+                                              |
            +---------------------------------v------------+
            |SoC                                           |
            |  +------------+        +------------------+  |
            |  |            |        |main_r5fss0_core0 |  |
            |  |  CPSW9G    <--------+                  |  |
            |  +------------+        +------------------+  |
            |                                              |
            +----------------------------------------------+


.. rubric:: **Drivers initialization**
   :name: k3-cpsw-virt-mac-init

The Linux TI remoteproc core ensures proper R5F core initialization, loads and starts the EthSwitch firmware,
and creates the default virtio devices for interacting with this firmware.
The virtio_rpmsg_bus driver performs discovery of the RPMSG devices and creates an rpmsg-kdrv device,
which, in turn, will trigger the rpmsg-kdrv core to discover "mpu_1_0_ethswitch-device-0" and probe the rpmsg_kdrv_switch driver

The j721e-cpsw-virt-mac driver is started separately by the Linux core once the corresponding main_r5fss_cpsw9g_virt_macX device has been created by the Linux DT parsing code.
Once started, the j721e-cpsw-virt-mac driver will wait for rpmsg_kdrv_switch driver to be probed.
 
.. note::

   The EthSwitch FW may also be loaded by the bootloader, and, in this case, the remoteproc components will be started in "IPC-only" mode.

.. rubric:: **rpmsg_kdrv_switch driver**
   :name: k3-rpmsg_kdrv_switch-drv

The rpmsg_kdrv_switch driver (drivers/rpmsg-kdrv/rpmsg_kdrv_switch.c) does not perform any functions by iteslf,
except checking for the supported EthSwitch FW version. It's intended to provide the RPMSG-KDRV rpmsg_remotedev API interface to be used by the j721e-cpsw-virt-mac driver.
Features controlled by the RPMSG-KDRV rpmsgi_remotedev API include:
- DMA resources allocation: TX UDMA channel and RX Flow
- MAC addresses assignment
- ARP helper for ARP requests processing from remote Net Hosts
- dbg: IPC ping
- dbg: CPSW0 register access
- dbg: statistic print request on R5F console (ioctl)

.. rubric:: **j721e-cpsw-virt-mac driver**
   :name: k3-j721e-cpsw-virt-mac-drv

The j721e-cpsw-virt-mac driver (drivers/net/ethernet/ti/j721e-cpsw-virt-mac.c) follows the standard Linux network interface architecture and supports the following features:

   - Network device up/down
   - Automatic (or manual) MAC address assignment
   - IP address assignment
   - Basic Ethertool functions
   - RX/TX csum offload (if enabled by EthSwitch FW)

*Not supported*:

- Interrupt Pacing is not supported by HW. NAPI is used by driver.

.. rubric:: **Network data flow**
   :name: k3-j721e-cpsw-virt-mac-data-flow

The EthSwitch FW is responsible for UDMA resource management and allocation between attached remote cores.
The j721e-cpsw-virt-mac driver requests the EthSwitch FW for available UDMA resources during initialization by performing an attach operation: TX channel and RX flow through the Control path (rpmsg_remotedev API).
In the current design, the EthSwitch FW allocates dedicated (not shared) TX UDMA channel for each attached core,
but the EthSwitch FW controls RX UDMA channel and only provides dedicated UDMA RX flow to attached cores.

Hence, after allocation, the j721e-cpsw-virt-mac driver is responsible for the full TX UDMA channel initialization (including TX and TX completion ring initialization).
The j721e-cpsw-virt-mac driver also starts/stops the TX UDMA channel.
For RX side, the j721e-cpsw-virt-mac driver only performs UDMA RX flow initialization (including RX free descriptor and RX ring initialization).


::

        User space          +------+
       +--------------------+ethX  +----------------------------------------+
                            +--^---+
                               |
                               |
                       +-------v-----+
                       |Net core     |
                       +-----^-------+
                             |
              +--------------v-------+
              | j721e-cpsw-virt-mac  |   Control Path
              |                      <----------+
              +----+---^-------------+          |
                   |   |                        |
                   |   |                        |
                   |   |              +---------v---------+
       TX channel  |   |RX flow       | rpmsg_kdrv_switch |
                   |   |              |                   |
                   |   |              +---------^---------+
                   |   |                        |
                Data Path                       |
              +----+---+-------------------------------------+
              |    |   |                        |      SoC   |
              |  +-v---+------+                 |            |
              |  |            |                 |            |
              |  |  UDMA      |                 |            |
              |  +---+--------+                 |            |
              |      |                          |            |
              |  +---v--------+        +--------v---------+  |
              |  |            |        |main_r5fss0_core0 |  |
              |  |  CPSW9G    <--------+                  |  |
              |  +------------+        +------------------+  |
              |                                              |
              +----------------------------------------------+

TThe EthSwitch FW needs to know which traffic to segregate to the Linux Host; therefore, the j721e-cpsw-virt-mac driver
registers the MAC address assigned to the virt_mac Network device within EthSwitch FW using Control path.

Once configured, the network data can be passed between the Linux virt_mac Network device and the CPSW0 without interaction with EthSwitch FW.
|
|

Enabling j721e-cpsw-virt-mac driver
"""""""""""""""""""""""""""""""""""

The |__SDK_FULL_NAME__| package has a |__PART_FAMILY_NAME__| rpmsg_kdrv_switch and j721e-cpsw-virt-mac drivers enabled by default to be built as modules.

To enable/disable j721e-cpsw-virt-mac driver support manually, start the *Linux Kernel Configuration*
tool:

::

    # make ARCH=arm64 menuconfig

| Select *Device Drivers* from the main menu ->
| Select *Rpmsg virtual device drivers* ->
| Select ** as shown here:

::

   -*- RPMSG virtual device interface
   <M> RPMSG virtual eth switch device support
    ...

| Select *Device Drivers* from the main menu ->
| Select *Network device support* ->
| Select *Ethernet driver support* ->
| Select ** as shown here:

::

    [*]   Texas Instruments (TI) devices
    <M>     TI Virtual Eth MAC driver
    ...

Kernel Kconfig options:

::

   CONFIG_RPMSG_KDRV
   CONFIG_RPMSG_KDRV_ETH_SWITCH
   CONFIG_TI_RDEV_ETH_SWITCH_VIRT_EMAC


.. rubric:: **Device tree bindings**
   :name: k3-j721e-cpsw-virt-mac-dt-binding

The DT bindings description can be found at:

|   `Documentation/devicetree/bindings/net/ti,cpsw-virt-mac.txt <https://git.ti.com/ti-linux-kernel/ti-linux-kernel/blobs/ti-linux-4.19.y/Documentation/devicetree/bindings/net/ti,cpsw-virt-mac.txt>`__
|
|

User space interface
""""""""""""""""""""

.. rubric:: Starting the interface
   :name: k3-j721e-cpsw-virt-mac-bringing-up-interfaces

Eth0 can be started by default or configured manually:

*DHCP*

::

      udhcpc -i ethX
      ifup eth0

*Manual IP address configuration*

::

    ifconfig eth0 <ip> netmask <mask> up

.. rubric:: ifconfig - Set MAC address
   :name: k3-j721e-cpsw-virt-mac-set-mac

The j721e-cpsw-virt-mac supports changing the HW MAC address, but this operation can be performed only when the network device is inactive (down).

::

   # ifconfig <dev> down
   # ifconfig <dev> hw ether <MAC-addr>
    

.. rubric:: ethtool - Get driver information
   :name: k3-j721e-cpsw-virt-mac-ethtool-i-driver

The CPSW0 interface can be identified by using ``ethtool -i|--driver`` command.
It also provides some information about supported features.

::

    # ethtool -i <dev>
    ...

.. rubric:: ethtool - Display standard information about device/link
   :name: k3-j721e-cpsw-virt-mac-ethtool-display-info

::

   # ethtool eth0

.. note::
   This command is supported, but not very useful, as the link is always up and no PHY.

.. rubric:: ethtool - Show permanent hardware address
   address
   :name: k3-j721e-cpsw-virt-mac-ethtool-show-permaddr

::

           # ethtool -P eth0
           Permanent address: a0:f6:fd:a6:46:6e"

.. rubric:: ethtool - RX/TX checksum offload
   :name: k3-j721e-cpsw-virt-mac-csum-offload

The driver enables RX checksum offload by default. The current status can be obtained by using "ethtool -k" command:

::

    # ethtool -k <dev>
    ....
    rx-checksumming: on
    tx-checksumming: off
        tx-checksum-ipv4: off [fixed]
        tx-checksum-ip-generic: off

It can be disabled/enabled by using "ethtool -K" command:

::

    ethtool -K <dev> rx-checksum on|off
    ethtool -K <dev> tx-checksum-ip-generic on|off

.. note::

    TX checksum offload enablement is controlled by EthSwitch FW and current status provided to j721e-cpsw-virt-mac driver.

.. rubric:: ethtool - driver testing
   :name: k3-j721e-cpsw-virt-mac-test

::

   # ethtool -t|--test <dev>
   ...
   RPMSG Ping test
   RPMSG Read reg
   RPMSG Dump stat

The j721e-cpsw-virt-mac can run several types of tests (if enabled by EthSwitch FW):
   - RPMSG Ping test: sends ping command to EthSwitch FW and checks if the same data returned back
   - RPMSG Read reg: sends CPSW0 CPSW_SS_CPSW_NUSS_IDVER_REG (0x0C000000) read register command to EthSwitch FW
   - RPMSG Dump stat: sends command to EthSwitch FW to dump current status and statistics

