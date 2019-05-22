
Introduction
"""""""""""""

The TI AM654 SoC Gigabit Ethernet Switch subsystem (CPSW NUSS) has two ports and
provides Ethernet packet communication for the device. It supports MII interfaces
the Reduced Gigabit Media Independent Interface (RGMII), Reduced Media Independent
Interface (RMII), and the Management Data Input/Output (MDIO) interface for
physical layer device (PHY) management.

The TI AM654 SoC has integrated two-port Gigabit Ethernet Switch subsystem
into device MCU domain named MCU_CPSW0 and has only one external Ethernet port (port 1)
with selectable RGMII and RMII interfaces and an internal Communications
Port Programming Interface (CPPI) port (Host port 0). Host Port 0 CPPI Packet
Streaming Interface interface supports 8 TX channels and one RX channel
operating by TI AM654 NAVSS Unified DMA Peripheral Root Complex (UDMA-P) controller.

The driver follows the standard Linux network interface architecture and
supports the following features:

#. 100/1000 Mbps mode of operation.
#. Auto negotiation.
#. Linux NAPI support
#. VLAN filtering
#. Ethertool
#. CPTS

*Not supported*:

- Interrupt Pacing is not supported by HW. NAPI is used by driver.

.. rubric:: **Driver Configuration**
   :name: k3-driver-configuration-cpsw

The TI Processor SDK has AM65x MCU CPSW2g driver enabled by default.

To enable/disable Networking support manually, start the *Linux Kernel Configuration*
tool:

::

    $ make ARCH=arm64 menuconfig

| Select *Device Drivers* from the main menu ->
| Select *Network device support* ->
| Select *Ethernet driver support* ->
| Select ** as shown here:

::

       ...
       [*]   Texas Instruments (TI) devices
       -*-     TI DaVinci MDIO Support
       -*-     TI CPSW ALE Support
       <*>     TI K3 CPSW Ethernet driver
       <*>     TI K3 AM65x CPTS
       ...

Kernel Kconfig options:

::

    CONFIG_TI_DAVINCI_MDIO
    CONFIG_TI_CPSW_ALE
    CONFIG_TI_AM65_CPSW_NUSS
    CONFIG_TI_AM65_CPTS

.. rubric:: **Module Build**
   :name: k3-module-build

Module build for the cpsw driver is supported. To do this, at all the
places mentioned in the section above select module build (short-cut key
**M**).

.. rubric:: **Device tree bindings**
   :name: k3-dt-binding

The DT bindings description can be found at:

|   `Documentation/devicetree/bindings/net/ti,am654-cpsw-nuss.txt <https://git.ti.com/ti-linux-kernel/ti-linux-kernel/blobs/ti-linux-4.19.y/Documentation/devicetree/bindings/net/ti,am654-cpsw-nuss.txt>`__

|   `Documentation/devicetree/bindings/net/ti,am654-cpts.txt <https://git.ti.com/ti-linux-kernel/ti-linux-kernel/blobs/ti-linux-4.19.y/Documentation/devicetree/bindings/net/ti,am654-cpts.txt>`__


.. rubric:: Bringing Up interface
   :name: k3-bringing-up-interfaces

Eth0 can be up by-default or configured manually:

*DHCP*
::

    ifup eth0

*Manual IP address configuration*
::

    ifconfig eth0 <ip> netmask <mask> up

.. rubric:: Get driver information
   :name: k3-ethtool-i-driver

The MCU_CPSW0 interface can be identified by using ethtool -i\|--driver command.
It also provides some information about supported features.

::

    # ethtool -i <dev>                                              
    driver: am65-cpsw-nuss                                                          
    version: 0.1                                                                    
    firmware-version:                                                               
    expansion-rom-version:                                                          
    bus-info: 46000000.ethernet                                                     
    supports-statistics: yes                                                        
    supports-test: no                                                               
    supports-eeprom-access: no                                                      
    supports-register-dump: yes                                                     
    supports-priv-flags: yes

.. rubric:: ethtool - Display standard information about device/link
   :name: k3-ethtool-display-standard-information-about-device

::

           # ethtool eth0
        Supported ports: [ TP MII ]
        Supported link modes:   10baseT/Half 10baseT/Full 
                                100baseT/Half 100baseT/Full 
                                1000baseT/Half 1000baseT/Full 
        Supported pause frame use: Symmetric Receive-only
        Supports auto-negotiation: Yes
        Supported FEC modes: Not reported
        Advertised link modes:  10baseT/Half 10baseT/Full 
                                100baseT/Half 100baseT/Full 
                                1000baseT/Half 1000baseT/Full 
        Advertised pause frame use: No
        Advertised auto-negotiation: Yes
        Advertised FEC modes: Not reported
        Link partner advertised link modes:  10baseT/Half 10baseT/Full 
                                             100baseT/Half 100baseT/Full 
        Link partner advertised pause frame use: Symmetric
        Link partner advertised auto-negotiation: Yes
        Link partner advertised FEC modes: Not reported
        Speed: 100Mb/s
        Duplex: Full
        Port: MII
        PHYAD: 0
        Transceiver: internal
        Auto-negotiation: on
        Supports Wake-on: d
        Wake-on: d
        Current message level: 0x00000000 (0)
                               
        Link detected: yes

.. rubric:: RX checksum offload
   :name: k3-rx-csum-offload

The Driver enables RX checksum offload by default. it can be disabled/enabled by
using ethtool -K command:

::

    # ethtool -k <dev>
    ....
    rx-checksumming: on

::

    ethtool -K <dev> rx-checksum on|off

.. note::

    TX checksum offload implemented, but disabled by default due to errata i2027.


.. rubric:: **VLAN Config**
   :name: k3-vlan-config

VLAN can be added/deleted using ``vconfig`` utility.

|

*VLAN Add*

``vconfig add eth0 5``

*VLAN del*

``vconfig rem eth0 5``

*VLAN IP assigning*

IP address can be assigned to the VLAN interface either via udhcpc
when a VLAN aware dhcp server is present or via static ip assigning
using ifconfig.

Once VLAN is added, it will create a new entry in Ethernet interfaces
like eth0.5, below is an example how it check the vlan interface

::

    # ifconfig eth0.5
    eth0.5    Link encap:Ethernet  HWaddr 20:CD:39:2B:C7:BE
              inet addr:192.168.10.5  Bcast:192.168.10.255  Mask:255.255.255.0
              UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
              RX packets:0 errors:0 dropped:0 overruns:0 frame:0
              TX packets:0 errors:0 dropped:0 overruns:0 carrier:0
              collisions:0 txqueuelen:0
              RX bytes:0 (0.0 B)  TX bytes:0 (0.0 B)

*VLAN Packet Send/Receive*

To Send or receive packets with the VLAN tag, bind the socket to the
proper Ethernet interface shown above and can send/receive via that
socket-fd.

|

.. rubric:: **Multicast Add/Delete**
   :name: k3-multicast-adddelete

Multicast MAC address can be added/deleted using *ip maddr* commands or Linux
socket ioctl SIOCADDMULTI/SIOCDELMULTI.

*Show muliticast address*

::

    # ip maddr show dev <dev>
    2:      eth0
        link  01:00:5e:00:00:01
        link  01:80:c2:00:00:00
        link  01:80:c2:00:00:03
        link  01:80:c2:00:00:0e
        link  01:00:5e:00:00:fc
        inet  224.0.0.252
        inet  224.0.0.1

*Add muliticast address*

::

    # ip maddr add 01:00:5e:00:00:05 dev eth0                                                                             
    # ip maddr show dev eth0
    2:      eth0
        link  01:00:5e:00:00:01
        link  01:80:c2:00:00:00
        link  01:80:c2:00:00:03
        link  01:80:c2:00:00:0e
        link  01:00:5e:00:00:fc
        link  01:00:5e:00:00:05 static
        inet  224.0.0.252
        inet  224.0.0.1

*Delete muliticast address*

::

    # ip maddr del 01:00:5e:00:00:05 dev eth0

| 

.. rubric:: ethtool -P\|--show-permaddr DEVNAME Show permanent hardware
   address
   :name: k3-ethtool-show-permaddr

::

           # ethtool -P eth0
           Permanent address: a0:f6:fd:a6:46:6e"

.. rubric:: ethtool -s\|--change DEVNAME Change generic options
   :name: k3-ethtool-change-generic-options

Below commands will be redirected to the phy driver:

::

       # ethtool -s <dev>
       [ speed %d ]
       [ duplex half|full ]
       [ autoneg on|off ]
       [ wol p|u|m|b|a|g|s|d... ]
       [ sopass %x:%x:%x:%x:%x:%x ]

.. note::

    CPSW driver do not perform any kind of WOL specific actions or
    configurations.

::

           #ethtool -s eth0 duplex half speed 100
           [ 3550.892112] cpsw 48484000.ethernet eth0: Link is Down
           [ 3556.088704] cpsw 48484000.ethernet eth0: Link is Up - 100Mbps/Half - flow control off

Sets the driver message type flags by name or number

::

           [ msglvl %d | msglvl type on|off ... ]
           # ethtool -s eth0 msglvl drv off
           # ethtool -s eth0 msglvl ifdown off
           # ethtool -s eth0 msglvl ifup off 
           # ethtool eth0
           Current message level: 0x00000031 (49)
                                  drv ifdown ifup

.. rubric:: ethtool -r\|--negotiate DEVNAME Restart N-WAY negotiation
   :name: k3-ethtool-restart-n-way-negotiation

::

           # ethtool -r eth0
           [ 4338.167685] cpsw 48484000.ethernet eth0: Link is Down
           [ 4341.288695] cpsw 48484000.ethernet eth0: Link is Up - 1Gbps/Full - flow control rx/tx"

.. rubric:: ethtool -a\|--show-pause DEVNAME Show pause options
   :name: k3-ethtool-show-pause-options

::

           # ethtool -a eth0
           Pause parameters for eth0:
           Autonegotiate:  off
           RX:             off
           TX:             off

.. rubric:: ethtool -A\|--pause DEVNAME Set pause options
   :name: k3-ethtool-set-pause-options

::

           # ethtool -A eth0 rx on tx on
           cpsw 48484000.ethernet eth0: Link is Up - 1Gbps/Full - flow control rx/tx
           # ethtool -a eth0
           Pause parameters for eth0:
           Autonegotiate:  off
           RX:             on
           TX:             on

.. rubric:: ethtool -g\|--show-ring DEVNAME Query RX/TX ring parameters
   :name: k3-ethtool-query-rxtx-ring-parameters

::

           # ethtool -g eth0 
           Ring parameters for eth0:
           Pre-set maximums:
           RX:             0
           RX Mini:        0
           RX Jumbo:       0
           TX:             0
           Current hardware settings:
           RX:             500
           RX Mini:        0
           RX Jumbo:       0
           TX:             512

.. rubric:: ethtool -S\|--statistics DEVNAME Show adapter statistics
   :name: k3-ethtool-show-adapter-statistics

"ethtool -S" command displays statistic for both external Port 1 and Host port 0.
Host port 0 statistics prefixed with *p0_*.

::

     # ethtool -S eth0
    NIC statistics:
         p0_rx_good_frames: 347
         p0_rx_broadcast_frames: 4
         p0_rx_multicast_frames: 264
         p0_rx_crc_errors: 0
         p0_rx_oversized_frames: 0
         p0_rx_undersized_frames: 0
         p0_ale_drop: 0
         p0_ale_overrun_drop: 0
         p0_rx_octets: 25756
         p0_tx_good_frames: 4816
         p0_tx_broadcast_frames: 3629
         p0_tx_multicast_frames: 1120
         p0_tx_octets: 878055
         p0_tx_64B_frames: 735
         p0_tx_65_to_127B_frames: 1023
         ...
         rx_good_frames: 4816
         rx_broadcast_frames: 3629
         rx_multicast_frames: 1120
         rx_pause_frames: 0
         rx_crc_errors: 0
         rx_align_code_errors: 0
         rx_oversized_frames: 0
         rx_jabber_frames: 0
         rx_undersized_frames: 0
         rx_fragments: 0
         ale_drop: 0
         ale_overrun_drop: 0
         rx_octets: 878055
         tx_good_frames: 347
         tx_broadcast_frames: 4
         tx_multicast_frames: 264
         tx_pause_frames: 0
         tx_deferred_frames: 0
         tx_collision_frames: 0
         tx_single_coll_frames: 0
         tx_mult_coll_frames: 0
         tx_excessive_collisions: 0
         tx_late_collisions: 0
         ...

.. rubric:: ethtool -T\|--show-time-stamping DEVNAME Show time stamping
   capabilities.
   :name: k3-ethtool-show-time-stamping-capabilities.

Accessible when CPTS is enabled.

::

           # ethtool -T eth0
         Time stamping parameters for eth0:
         Capabilities:
                 hardware-transmit     (SOF_TIMESTAMPING_TX_HARDWARE)
                 software-transmit     (SOF_TIMESTAMPING_TX_SOFTWARE)
                 hardware-receive      (SOF_TIMESTAMPING_RX_HARDWARE)
                 software-receive      (SOF_TIMESTAMPING_RX_SOFTWARE)
                 software-system-clock (SOF_TIMESTAMPING_SOFTWARE)
                 hardware-raw-clock    (SOF_TIMESTAMPING_RAW_HARDWARE)
         PTP Hardware Clock: 1
         Hardware Transmit Timestamp Modes:
                 off                   (HWTSTAMP_TX_OFF)
                 on                    (HWTSTAMP_TX_ON)
         Hardware Receive Filter Modes:
                 none                  (HWTSTAMP_FILTER_NONE)
                 all                   (HWTSTAMP_FILTER_ALL)

.. rubric:: ethtool-l\|--show-channels DEVNAME Query Channels
   :name: k3-ethtool-query-channels

::

           # ethtool -l eth0
         Channel parameters for eth0:
         Pre-set maximums:
         RX:             1
         TX:             8
         Other:          0
         Combined:       0
         Current hardware settings:
         RX:             1
         TX:             8
         Other:          0
         Combined:       0

.. rubric:: ethtool --show-eee DEVNAME Show EEE settings
   :name: k3-ethtool-show-eee-settings

::

           #ethtool --show-eee eth0
           EEE Settings for eth0:
                   EEE status: not supported

.. rubric:: ethtool --set-eee DEVNAME Set EEE settings.
   :name: k3-ethtool-set-eee-settings.

.. note::

    Full EEE is not supported in driver, but it enables reading
    and writing of EEE advertising settings in Ethernet PHY. This way one
    can disable advertising EEE for certain speeds.

.. rubric:: ethtool -d\|--register-dump DEVNAME Do a register dump
   :name: k3-ethtool-do-a-register-dump

This command dumps all CPSW MMIO regions in the below format.
The TI switch-config tool can be used for CPSW NUSS register dump parsing.

+------------------------------------------------------------------+
| MMIO region header (8 Bytes)                                     |
+====================+=============================================+
| module_id          | MMIO region id                              |
| (u32)              | NUSS = 1,                                   |
|                    | RGMII_STATUS = 2,                           |
|                    | MDIO = 3,                                   |
|                    | CPSW = 4,                                   |
|                    | CPSW_P0 = 5,                                |
|                    | CPSW_P1 = 6,                                |
|                    | CPSW_CPTS = 7,                              |
|                    | CPSW_ALE = 8,                               |
|                    | CPSW_ALE_TBL = 9                            |
+--------------------+---------------------------------------------+
| len (u32)          | MMIO region dump length, including header   |
+--------------------+---------------------------------------------+
| MMIO region registers dump (num_regs * 8 Bytes)                  |
+--------------------+---------------------------------------------+
| reg_offset (u32)   | resgister offset from the start             |
|                    | of MCU NAVSS MMIO space                     |
+--------------------+---------------------------------------------+
| reg_value (u32)    | MMIO region dump length, including header   |
+--------------------+---------------------------------------------+

Exception: ALE table dumped as raw array of ALE records (3 * u32 per record).

::

           # ethtool -d eth0
           Offset          Values
           ------          ------
           0x0000:         01 00 00 00 48 00 00 00 00 00 00 00 00 71 a0 6b 
           0x0010:         04 00 00 00 00 00 00 00 08 00 00 00 00 00 00 00 
           0x0020:         0c 00 00 00 00 00 00 00 10 00 00 00 01 00 00 00 
           0x0030:         14 00 00 00 00 00 00 00 18 00 00 00 00 00 00 00 
           0x0040:         1c 00 00 00 00 00 00 00 02 00 00 00 48 00 00 00 
           0x0050:         30 00 00 00 0b 00 00 00 34 00 00 00 00 00 00 00 
           0x0060:         38 00 00 00 00 00 00 00 3c 00 00 00 00 00 00 00 
           ...



Common Platform Time Sync (CPTS) module
""""""""""""""""""""""""""""""""""""""""

The Common Platform Time Sync (CPTS) module is used to facilitate host
control of time sync operations. It enables compliance with the IEEE
1588-2008 standard for a precision clock synchronization protocol.

The support for CPTS module can be enabled by Kconfig option
CONFIG_TI_AM65_CPTS or through menuconfig tool. The PTP packet
timestamping can be enabled only for one CPSW port.

When CPTS module is enabled it will exports a kernel interface for
specific clock drivers and a PTP clock API user space interface and
enable support for SIOCSHWTSTAMP and SIOCGHWTSTAMP socket ioctls. The
PTP exposes the PHC as a character device with standardized ioctls which
usually can be found at path:

::

       /dev/ptpN

Supported PTP hardware clock functionality:

::

    Basic clock operations
       - Set time
       - Get time
       - Shift the clock by a given offset atomically
       - Adjust clock frequency

::

    Ancillary clock features
       - Time stamp external events
       - Periodic output signals configurable from user space
       - Synchronization of the Linux system time via the PPS subsystem

Supported parameters for SIOCSHWTSTAMP and SIOCGHWTSTAMP:

::

    SIOCSHWTSTAMP
       hwtstamp_config.flags = 0
       hwtstamp_config.tx_type 
           HWTSTAMP_TX_ON - enables hardware time stamping for outgoing packets
           HWTSTAMP_TX_OFF - no outgoing packet will need hardware time stamping
       hwtstamp_config.rx_filter
           HWTSTAMP_FILTER_NONE - time stamp no incoming packet at all
           HWTSTAMP_FILTER_ALL - time stamp any incoming packet

CPTS PTP packet timestamping default configuration when enabled
(SIOCSHWTSTAMP):


::

    CPSW_PN_TS_CTL_REG
       TS_MSG_TYPE_EN = 0xF (Sync, Delay_Req, Pdelay_Req, and Pdelay_Resp.)
       TS_TX_ANNEX_F_EN = 1
       TS_TX_ANNEX_E_EN = 1
       TS_TX_ANNEX_D_EN = 1
       TS_TX_VLAN_LTYPE1_E = 1

::

    CPSW_PN_TS_CTL_LTYPE2_REG
       TS_TTL_NONZERO = 1
       TS_320 = 1
       TS_319 = 1
       TS_132 = 1
       TS_131 = 1
       TS_130 = 1
       TS_129 = 1
       TS_107 = 1
       TS_LTYPE1 = 0x88F7 (ETH_P_1588)

::

    CPSW_PN_TS_SEQ_LTYPE_REG
       TS_SEQ_ID_OFFSET = 0x1e
       TS_LTYPE1 = 0x88F7 (ETH_P_1588)

::

    CPSW_PN_TS_VLAN_LTYPE_REG
       TS_VLAN_LTYPE1 =  0x8100 (ETH_P_8021Q)
       
For more information about PTP clock API and Network timestamping see
Linux kernel documentation

| `Documentation/ptp/ptp.txt <https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/plain/Documentation/ptp/ptp.txt>`__
| `include/uapi/linux/ptp\_clock.h <https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/plain/include/uapi/linux/ptp_clock.h>`__
| `Documentation/ABI/testing/sysfs-ptp <https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/plain/Documentation/ABI/testing/sysfs-ptp>`__
| `Documentation/networking/timestamping.txt <https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/plain/Documentation/networking/timestamping.txt>`__
| `Documentation/pps/pps.txt <https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/plain/Documentation/pps/pps.txt>`__
|
| Code examples and tools:
| `tools/testing/selftests/ptp/testptp.c <https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/plain/tools/testing/selftests/ptp/testptp.c>`__
| `tools/testing/selftests/networking/timestamping/timestamping.c <https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/plain/tools/testing/selftests/networking/timestamping/timestamping.c>`__
|
| `Open Source Project linuxptp <http://linuxptp.sourceforge.net/>`__
| `Linux PPS tools <https://github.com/redlab-i/pps-tools>`__

.. rubric:: Testing using ptp4l tool from linuxptp project
   :name: k3-testing-using-ptp4l-tool-from-linuxptp-project

To check the ptp clock adjustment with PTP protocol, a PTP slave
(client) and a PTP master (server) applications are needed to run on
separate devices (EVM or PC). Open source application package linuxptp
can be used as slave and as well as master. Hence TX timestamp
generation can be delayed (especially with low speed links) the ptp4l
"tx_timestamp_timeout" parameter need to be set for ptp4l to work.

- create file ptp.cfg with content as below:

::

    [global]
    tx_timestamp_timeout     400

- pass configuration file to ptp4l using "-f" option:

::

     ptp4l -E -2 -H -i eth0  -l 6 -m -q -p /dev/ptpN -f ptp.cfg

-  Slave Side Examples

The following command can be used to run a ptp-over-L4 client on the evm
in slave mode

::

       ./ptp4l -E -4 -H -i eth0 -s -l 7 -m -q -p /dev/ptpN

For ptp-over-L2 client, use the command

::

       ./ptp4l -E -2 -H -i eth0 -s -l 7 -m -q -p /dev/ptpN

-  Master Side Examples

ptp4l can also be run in master mode. For example, the following command
starts a ptp4l-over-L2 master on an EVM using hardware timestamping,

::

       ./ptp4l -E -2 -H -i eth0 -l 7 -m -q -p /dev/ptpN 

On a Linux PC which does not supoort hardware timestamping, the
following command starts a ptp4l-over-L2 master using software
timestamping.

::

       ./ptp4l -E -2 -S -i eth0 -l 7 -m -q

.. rubric:: Testing using testptp tool from Linux kernel
   :name: k3-testing-using-testptp-tool-from-linux-kernel

-  get the ptp clock time

::

       # testptp -d /dev/ptpN -g
       clock time: 1493255613.608918429 or Thu Apr 27 01:13:33 2017

-  query the ptp clock's capabilities

::

       # testptp -d /dev/ptpN -c
       capabilities:
         10000000 maximum frequency adjustment (ppb)
         0 programmable alarms
         4 external time stamp channels
         2 programmable periodic signals
         1 pulse per second
         0 programmable pins
         0 cross timestamping

-  Sanity testing of cpts ref frequency

Time difference between to testptp -g calls should be equal sleep time

::

       # testptp -g -d /dev/ptpN && sleep 5 && testptp -g -d /dev/ptpN
       clock time: 1493255884.565859901 or Thu Apr 27 01:18:04 2017
       clock time: 1493255889.611065421 or Thu Apr 27 01:18:09 2017

-  shift the ptp clock time by 'val' seconds

::

       # testptp -g -d /dev/ptpN && testptp -t 100 && testptp -g -d /dev/ptpN
       clock time: 1493256107.640649117 or Thu Apr 27 01:21:47 2017
       time shift okay
       clock time: 1493256207.678819093 or Thu Apr 27 01:23:27 2017

-  set the ptp clock time to 'val' seconds

::

       # testptp -g -d /dev/ptpN && testptp -T 1000000 && testptp -g -d /dev/ptpN
       clock time: 1493256277.568238925 or Thu Apr 27 01:24:37 2017
       set time okay
       clock time: 100.018944504 or Thu Jan  1 00:01:40 1970

-  adjust the ptp clock frequency by 'val' ppb

::

       # testptp -g -d /dev/ptpN && testptp -f 1000000 && testptp -g -d /dev/ptpN
       clock time: 151.347795184 or Thu Jan  1 00:02:31 1970
       frequency adjustment okay
       clock time: 151.386187454 or Thu Jan  1 00:02:31 1970

.. rubric:: Example of using Time stamp external events
   :name: k3-example-of-using-time-stamp-external-events

Timestamping of external events can be tested using
testptp tool. Before testing the proper CPTS signal routing has to be done by
using timesync router in DT.

For example, output of GENF0 can be routed to HW3_TS_PUSH_EN input.
It's required to rebuild kernel with below changes first

::

   #define TS_OFFSET(pa, val)     (0x4+(pa)*4) (0x80000000 | val)

   &timesync_router {
      pinctrl-names = "default";
      pinctrl-0 = <&mcu_cpts>;

          /* Example of the timesync routing */
              mcu_cpts: mcu_cpts {
                      pinctrl-single,pins = <
                              /* pps [cpts genf0] in12 -> out24 [cpts hw4_push] */
                              TS_OFFSET(24, 12)
                      >;
              };
   };

Then execute::

       # testptp -d /dev/ptpN -p 500000000 -i 0
       # testptp -d /dev/ptpN -e 100 -i 2 
       event index 2 at 384.250000025
       event index 2 at 384.750000025
       event index 2 at 385.250000025
       event index 2 at 385.750000025

.. rubric:: PPS Pulse Per Second support
   :name: k3-cpts-pps-support

By default, PPS support for AM65x is implemented and enabled in TI SDK by wiring
GENF1 output to HW3_TS_PUSH_EN input::

       k3-am654-base-board.dts
       #define TS_OFFSET(pa, val)     (0x4+(pa)*4) (0x80000000 | val)

       &timesync_router {
              pinctrl-names = "default";
              pinctrl-0 = <&mcu_cpts>;

              /* Example of the timesync routing */
              mcu_cpts: mcu_cpts {
                     pinctrl-single,pins = <
                            /* pps [cpts genf1] in13 -> out25 [cpts hw4_push] */
                            TS_OFFSET(25, 13)
                     >;
              };
       };

       &mcu_cpsw {
              ...
              cpts {
                     ti,pps = <3 1>;
              };
       };

Once enabled, PPS can be tested using testptp and ppstest tools::

       # ./testptp -d /dev/ptp1 -P 1
       pps for system time request okay
       # ./ppstest /dev/pps0
       trying PPS source "/dev/pps0"
       found PPS source "/dev/pps0"
       ok, found 1 source(s), now start fetching data...
       source 0 - assert 198.000000700, sequence: 7 - clear  0.000000000, sequence: 0
       source 0 - assert 199.000000700, sequence: 8 - clear  0.000000000, sequence: 0

.. rubric:: TI AM65x switch-config tool
   :name: k3-am65x-switch-config

The TI Processor SDK includes precompiled correct version of AM65x switch-config tool.

The TI AM65x switch-config tool sources for AM65x SoC can be found at::

       git@git.ti.com:switch-config/switch-config.git

branch::

       origin/am65x-v1.0

Usage::

       # switch-config -h 
       Switch configuration commands.....
       switch-config -I,--ndev <dev> <command>

       commands:
       switch-config -d,--dump-ale :dump ALE table
       switch-config -D,--dump=<0..9> :dump registers (0 - all)
       switch-config -v,--version

       dump values:
        :1 - cpsw-nuss regs
        :2 - cpsw-nuss-rgmii-status regs
        :3 - cpsw-nuss-mdio regs
        :4 - cpsw-nu regs
        :5 - cpsw-nu-p0 regs
        :6 - cpsw-nu-p1 regs
        :7 - cpsw-nu-cpts regs
        :8 - cpsw-nu-ale regs
        :9 - cpsw-nu-ale-tbl regs

Example, ALE table dump::

        # switch-config -d
        K3 cpsw dump version (1) len(6328)
        ALE table dump ents(64): 
        0   : type: vlan , vid = 0, untag_force = 0x3, reg_mcast = 0x0, unreg_mcast = 0x0, member_list = 0x3
        1   : type: ucast, addr = f4:84:4c:eb:a0:00, ucast_type = persistant, port_num = 0x0, Secure
        2   : type: mcast, addr = ff:ff:ff:ff:ff:ff, mcast_state = f, no super, port_mask = 0x3
        3   : type: mcast, addr = 01:00:5e:00:00:01, mcast_state = f, no super, port_mask = 0x3
        4   : type: mcast, addr = 01:80:c2:00:00:00, mcast_state = f, no super, port_mask = 0x3
        5   : type: mcast, addr = 01:80:c2:00:00:03, mcast_state = f, no super, port_mask = 0x3
        6   : type: mcast, addr = 01:80:c2:00:00:0e, mcast_state = f, no super, port_mask = 0x3
        8   : type: mcast, addr = 01:00:5e:00:00:fc, mcast_state = f, no super, port_mask = 0x3
        9   : type: ucast, vid = 0, addr = 9c:b6:d0:89:0d:85, ucast_type = touched   , port_num = 0x1
        26  : type: ucast, vid = 0, addr = c4:71:54:a9:6e:b4, ucast_type = touched   , port_num = 0x1
        27  : type: ucast, vid = 0, addr = 00:25:22:a9:4c:b3, ucast_type = touched   , port_num = 0x1

Example, CPTS registers dump::

        switch-config -D7
        K3 cpsw dump version (1) len(6328)
        cpsw-nu-cpts regdump: num_regs(38)
        0003d000:reg(4E8A2109)
        0003d004:reg(00000C21)
        0003d008:reg(00000000)
        0003d00c:reg(00000000)
        0003d010:reg(7EA3BA9B)
        0003d014:reg(00000000)
        0003d018:reg(00000000)
        0003d01c:reg(00000000)
        0003d020:reg(00000000)
        0003d024:reg(00000000)
        0003d028:reg(00000001)
        0003d02c:reg(00000000)
        0003d030:reg(00000000)
        0003d034:reg(C7298A99)
        0003d038:reg(03300000)
        0003d03c:reg(00000000)
        0003d040:reg(0000028E)
        0003d044:reg(00000000)
        0003d048:reg(00000000)

