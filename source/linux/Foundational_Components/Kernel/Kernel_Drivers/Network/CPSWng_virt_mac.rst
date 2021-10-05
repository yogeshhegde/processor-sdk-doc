.. include:: /replacevars.rst.inc

CPSWng virtual MAC (remoteproc)
-------------------------------

.. contents:: :local:
    :depth: 3

Introduction
============

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
       | main_r5fss_cpswng_virt_mac0       | rpmsg_remotedev_eth_switch_ops API
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
            |  |  CPSWnG    <--------+                  |  |
            |  +------------+        +------------------+  |
            |                                              |
            +----------------------------------------------+


Drivers initialization
""""""""""""""""""""""

The Linux TI remoteproc core ensures proper R5F core initialization, loads and starts the EthSwitch firmware,
and creates the default virtio devices for interacting with this firmware.
The virtio_rpmsg_bus driver performs discovery of the RPMSG devices and creates an rpmsg-kdrv device,
which, in turn, will trigger the rpmsg-kdrv core to discover "mpu_1_0_ethswitch-device-0" and probe the rpmsg_kdrv_switch driver

The j721e-cpsw-virt-mac driver is started separately by the Linux core once the corresponding main_r5fss_cpswng_virt_macX device has been created by the Linux DT parsing code.
Once started, the j721e-cpsw-virt-mac driver will wait for rpmsg_kdrv_switch driver to be probed.
 
.. note::

   The EthSwitch FW may also be loaded by the bootloader, and, in this case, the remoteproc components will be started in "IPC-only" mode.

rpmsg_kdrv_switch driver
""""""""""""""""""""""""

The rpmsg_kdrv_switch driver (drivers/rpmsg-kdrv/rpmsg_kdrv_switch.c) does not perform any functions by iteslf,
except checking for the supported EthSwitch FW version. It's intended to provide the RPMSG-KDRV rpmsg_remotedev API interface to be used by the j721e-cpsw-virt-mac driver.
Features controlled by the RPMSG-KDRV rpmsgi_remotedev API include:
- DMA resources allocation: TX UDMA channel and RX Flow
- MAC addresses assignment
- ARP helper for ARP requests processing from remote Net Hosts
- dbg: IPC ping
- dbg: CPSW0 register access
- dbg: statistic print request on R5F console (ioctl)

j721e-cpsw-virt-mac driver
""""""""""""""""""""""""""

The j721e-cpsw-virt-mac driver (drivers/net/ethernet/ti/j721e-cpsw-virt-mac.c) follows the standard Linux network interface architecture and supports the following features:

   - Network device up/down
   - Automatic (or manual) MAC address assignment
   - IP address assignment
   - Basic Ethertool functions
   - RX/TX csum offload (if enabled by EthSwitch FW)
   - SW Interrupt Pacing using timers.

*Not supported*:

- HW Interrupt Pacing is not supported.

Network data flow
"""""""""""""""""

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
              |  |  CPSWnG    <--------+                  |  |
              |  +------------+        +------------------+  |
              |                                              |
              +----------------------------------------------+

TThe EthSwitch FW needs to know which traffic to segregate to the Linux Host; therefore, the j721e-cpsw-virt-mac driver
registers the MAC address assigned to the virt_mac Network device within EthSwitch FW using Control path.

Once configured, the network data can be passed between the Linux virt_mac Network device and the CPSW0 without interaction with EthSwitch FW.

Driver Configuration
====================

The |__SDK_FULL_NAME__| package has a |__PART_FAMILY_NAME__| rpmsg_kdrv_switch and j721e-cpsw-virt-mac drivers enabled by default and built as modules.
In case of custom builds, please ensure following configs are enabled.

::

   CONFIG_RPMSG_KDRV
   CONFIG_RPMSG_KDRV_ETH_SWITCH
   CONFIG_TI_RDEV_ETH_SWITCH_VIRT_EMAC


Device tree bindings
====================

The DT bindings description can be found at:

|   `Documentation/devicetree/bindings/net/ti,cpsw-virt-mac.txt <https://git.ti.com/ti-linux-kernel/ti-linux-kernel/blobs/ti-linux-5.10.y/Documentation/devicetree/bindings/net/ti,cpsw-virt-mac.txt>`__
|

User guide
==========

Starting the interface
""""""""""""""""""""""

Eth0 can be started by default or configured manually:

*DHCP*

::

      udhcpc -i ethX
      ip link set dev ethX up

*Manual IP address configuration*

::

    ip addr add <ip>/24 dev ethX
    ip link set dev ethX up

    < or >

    ifconfig ethX <ip> netmask <mask> up

Set MAC address
"""""""""""""""

The j721e-cpsw-virt-mac supports changing the HW MAC address, but this operation can be performed only when the network device is inactive (down).

::

   ip link set dev ethX down
   ip link set dev ethX address <MAC-addr>
   ip link set dev ethX up

ethtool interface
"""""""""""""""""

Get driver information
^^^^^^^^^^^^^^^^^^^^^^

The CPSW0 interface can be identified by using ``ethtool -i|--driver`` command.
It also provides some information about supported features.

::

    # ethtool -i <dev>
    ...

Display standard information about device/link
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

::

   # ethtool eth0

.. note::
   This command is supported, but not very useful, as the link is always up and no PHY.

Show permanent hardware address
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

::

           # ethtool -P eth0
           Permanent address: a0:f6:fd:a6:46:6e"

RX/TX checksum offload
^^^^^^^^^^^^^^^^^^^^^^

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

Driver testing
^^^^^^^^^^^^^^

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

Interrupt pacing
""""""""""""""""

The Interrupt pacing (IRQ coalescing) based on hrtimers for RX/TX data path separately can be enabled by ethtool commands (min value is 20us):

::

  #  ethtool -C ethX tx-usecs N
  #  ethtool -C ethX rx-usecs N

The Interrupt pacing (IRQ coalescing) configuration can be retrieved by commands:

::

  #  ethtool -c ethX

It is also possible to use standard Linux Net core hard irqs deferral feature which can be enabled by configuring:

::

 /sys/class/net/ethX/
  gro_flush_timeout (in ns)
  napi_defer_hard_irqs (number of retries)

Enabling of hard IRQ will be deferred napi_defer_hard_irqs times with gro_flush_timeout timeout.

The main difference of the hard irqs deferral feature from ethtool interrupt pacing (IRQ coalescing) is that it affects on both RX/TX data path simultaneously.
