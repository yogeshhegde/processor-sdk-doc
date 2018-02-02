.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_HSR_PRP
.. rubric:: Overview
   :name: overview

In both HSR and PRP protocols, the DAN (Dual Attached Node) sends an
identical frame to both the interfaces and uses a sequence number in the
tag to allow drop duplicates at the Rx node to achieve redundancy. This
section describes the different software components of a Linux based
HSR/PRP solution to support redundancy.

.. rubric:: Features
   :name: features

-  Enhanced ICSS cut-through switch with HSR capability
-  HSR End Node (DANH) complying to IEC62439-3 Edition 2 Clause 5
-  PRP End Node (DANP) complying to IEC6239-3 Edition 2 Clause 4
-  10/100 Mbits/s Full Duplex Ethernet Interface
-  Store & forward with data integrity check
-  VLAN over HSR/PRP interface
-  node table size 256
-  Statistics & Node Table MIB support
-  HSR Modes H;N,T,U,M - mode changethrough SNMP SET
-  Duplicate Accept/Reject configuration change through SNMP SET
-  Run time change of Protocol at PRU Ethernet

.. rubric:: Software Architecture
   :name: software-architecture

The diagram below highlights the software components that are modified
or developed specifically for HSR/PRP. These along with other standard
Linux OS components are used to implement the Linux HSR/PRP DAN (Dual
Attached Node).

-  Linux Kernel drivers

   -  HSR/PRP driver
   -  Ethernet driver

-  User space

   -  Net-SNMP
   -  iproute2

.. Image:: ../images/Linux-hsr-architecture.png

.. rubric:: Linux HSR/PRP Driver
   :name: linux-hsrprp-driver

The Linux networking subsystem in upstream kernel has added support for
HSR driver starting in v3.12 (HSRv0 - IEC 62439-3:2010) and enhanced the
same to support HSRv1 (IEC 62439-3:2012) in v4.6. This driver allows
user to create an HSR network device with a pair of slave network
interfaces (A and B) that are standard Ethernet interfaces. For example
on TI's AM572x IDK EVM, there are two Ethernet interfaces (10/100) per
each PRU ICSS. The PRU Emac driver available for ICSS PRU Ethernet h/w
supports two Ethernet ports. Using ip link command, user will be able to
setup a HSR interface on this EVM that pair the two PRU Ethernet
interfaces to create a HSR node or **DAN-H**.

TI has enhanced the Linux HSR driver and ip link command in iproute2
package to support PRP defined in IEC 62439-3 clause 4. With this
change, user will be able to create a Doubly Attached Node with PRP
(**DAN-P**) using standard Ethernet interfaces. As in the case of HSR,
using ip link command, user will be able to setup a prp interface using
two Ethernet interfaces such as the one provided by PRU EMAC driver.

Linux HSR/PRP driver provides a standard Ethernet interface to
application layer and hide the details of the redundancy protocol under
the driver layer. Linux HSR/PRP driver implements the Link Redundancy
Entity (LRE) that is central to implementing redundancy using respective
protocol.

HSR LRE functions and L2 routing can be offloaded to the firmware
running on the PRU cores of ICSS. The diagram below shows the
architecture of an Offloaded HSR/PRP driver. The upper layer driver is
existing Linux HSR/PRP driver described in the previous section. The PRU
Ethernet driver exports HSR/PRP capabilities in the NetDev feature
flags. The green blocks in the Redundancy layer shows the software
blocks that gets offloaded to PRUs in ICSS which is shown green as well.
The upper layer HSR/PRP driver uses the feature flags exported by the
PRU Ethernet driver to disable corresponding functions in its layer. The
firmware is a re-use from the TI RTOS implementation that is discussed
above. Re-use means the data structures and API should be re-used across
both TI RTOS and Linux driver implementations. A common PRU Ethernet
driver is developed to support existing EMAC device as well HSR/PRP

.. Image:: ../images/Hsr-prp-offload.png

.. rubric:: Ethernet Driver
   :name: ethernet-driver

Starting from Processor SDK 04.00.00 release, the PRU Ethernet driver
supports HSR/PRP firmware offload. More specifically, based on a module
parameter configured at boot time, the PRU Ethernet driver loads either
a PRU EMAC firmware, PRU HSR firmware or PRU PRP firmware. The first
case (EMAC) is the non-offload case, while the latter 2 cases are the
firmware offload cases. When a HSR/PRP firmware is loaded, the PRU
Ethernet driver will do proper firmware configurations and indicate
offload capabilities in the netdev feature flag. The Linux HSR/PRP
driver stack use these feature flag to determine if offload is supported
or not at the lower level Ethernet driver and disable certain processing
at the its layer.

Notice that, from the user point of view, other than providing a module
parameter to specify which firmware to load, all of the above mentioned
driver behavior is transparent to the user.

.. rubric:: PRU Ethernet Driver (EMAC/HSR/PRP)
   :name: pru-ethernet-driver-emachsrprp

Starting from Processor SDK 04.00.00 release, the PRU Ethernet driver
supports HSR/PRP firmware offload. More specifically, based on a module
parameter configured at boot time, the PRU Ethernet driver loads either
a PRU EMAC firmware, PRU HSR firmware or PRU PRP firmware. The first
case (EMAC) is the non-offload case, while the latter 2 cases are the
firmware offload cases. When a HSR/PRP firmware is loaded, the PRU
Ethernet driver will do proper firmware configurations and notify the
Linux HSR/PRP driver stack that offload has been enabled. From then on,
LRE functionality is carried out in firmware.

Notice that, from the user point of view, other than providing a module
parameter to specify which firmware to load, all of the above mentioned
driver behavior is transparent to the user.

.. rubric:: Queue Usage and VLAN PCP to Queue Map
   :name: queue-usage-and-vlan-pcp-to-queue-map

At the Ingress, there are two queues assigned for packets coming from
each port or PRU. Here is how the PCP values of incoming packets mapped
to the each of the two queues. Firmware maintains a mapping table in the
shared memory that is configured by the PRU Ethernet driver for HSR/PRP.
For EMAC, the firmware has a similar mapping that is hard coded.

Ingress Host PCP to priority Queue map table in shared memory for
HSR/PRP/EMAC

::

      byte 0 => PRU 0 (eth2), PCP 0-3 => Q1 
      byte 1 => PRU 0 (eth2), PCP 4-7 => Q0
      byte 2 => Unused.
      byte 3 => Unused.
      byte 4 => PRU 1 (eth3), PCP 0-3 => Q3 
      byte 5 => PRU 1 (eth3), PCP 4-7 => Q2 
      byte 6 => Unused
      byte 7 => Unused

The convention is that higher queue value corresponds to lower priority

At the Ingress, two separate irq handlers are assigned to each port to
process the packets. Driver handler first process packets from the high
priority queue followed by packets from the lower priority queue.

At the Egress, there are 4 queues where driver enqueue the packets for
Egress transmission. Following are the PCP to queue map used for Egress
that are same across all protocols.

::

     low  - pcp 0..1 maps to Q3
                2..3 maps to Q2
                4..5 maps to Q1
     high - pcp 6..7 maps to Q0.

Firmware sends the frames first from Q1, and then from the next higher
queue (Q2) and so forth.

| 

| 

.. rubric:: Changing protocol at PRU Ethernet
   :name: changing-protocol-at-pru-ethernet

PRU Ethernet driver support multiple protocols based on the firmware
loaded on ICSS PRU. In Processor SDK 04.00.00, a capability was added to
change the protocol running on the PRU at boot time through bootargs.
This is described at
`Processor\_SDK\_Linux\_HSR\_PRP#Testing\_HSR.2FPRP\_Firmware\_Offload </index.php/Processor_SDK_Linux_HSR_PRP#Testing_HSR.2FPRP_Firmware_Offload>`__.
Starting Processor SDK 04.01.00, The driver can be configured to switch
the protocol while the board is powered up and running Linux kernel. By
default, the PRU Ethernet driver is probed to be in the EMAC mode and
EMAC firmware is loaded on to the PRU unless user set the
pruss2\_ethtype to run HSR (1) or PRP (2). Two feature names are added
to help offload HSR or PRP in the PRU Ethernet driver :- hsr-rx-offload
and prp-rx-offload. PRU Firmware essentially offload the rx side
processing of LRE, such as duplicate detection and drop, node table
update, stats update etc. To reflect the same, the features are named
with a rx-offload suffx to the protocol name. Ethtool command has an
option -K to set or clear the feature in a network device. So this flag
can be set or reset rx offload feature in the PRU Ethernet device. As
the device may be hooked up to a upper HSR/PRP network device, user is
expected to delete the hsr or prp interface before changing the flag at
the PRU Ethernet device. General procedure to change protocol at PRU
Ethernet device is as follows:-

Below assumes that hsr or prp interface using the PRU Ethernet devices
is currently deleted. Here are the steps at a high level:-

1. Bring down the two PRU Ethernet interfaces using ifconfig and
unassign the ip address using ifconfig. For example

::

    ifconfig eth2 down 0.0.0.0
    ifconfig eth3 down 0.0.0.0

2. If the PRU Ethernet device is currently running HSR or PRP offload
feature, the same has to be disabled before switching to EMAC or another
protocol using ethtool -K option. For example if HSR is currently
running, do

::

       ethtool -K eth2 hsr-rx-offload off
       ethtool -K eth3 hsr-rx-offload off

Similarly if PRP is currently running, do

::

       ethtool -K eth2 prp-rx-offload off
       ethtool -K eth3 prp-rx-offload off

3. If user would like to offload HSR, enable the feature hsr-rx-offload
on both devices.

::

      ethtool -K eth2 hsr-rx-offload on
      ethtool -K eth3 hsr-rx-offload on

4. Now the PRU Ethernet devices can be paired to create an HSR interface
using ip link command. To offload PRP user does following command in
step 3

::

      ethtool -K eth2 prp-rx-offload on
      ethtool -K eth3 prp-rx-offload on

To display the offload feature currently active at the PRU Ethernet,
user may type following command for example for eth2

::

      ethtool -k eth2

| 

| 

.. rubric:: Sample commands
   :name: sample-commands

Before using these commands, save the MAC address of both interfaces.
These sample commands assumes a MAC address of 70:FF:76:1C:0E:8C for
both PRU Ethernet interfaces and an IP address of 192.168.2.20 for the
hsr/prp interface. Eth3 MAC address is assumed to be 70:FF:76:1C:0E:8E.
Also assumes user create hsr0 or prp0 interface using eth2 and eth3
interfaces. Please note that for each DAN, user needs to assign unique
MAC address and IP address from the same subnet.

-  To switch from EMAC to HSR

::

    ifconfig eth2 0.0.0.0 down
    ifconfig eth3 0.0.0.0 down
    ifconfig eth2 hw ether 70:FF:76:1C:0E:8C
    ifconfig eth3 hw ether 70:FF:76:1C:0E:8C
    ethtool -K eth2 hsr-rx-offload on
    ethtool -K eth3 hsr-rx-offload on
    ifconfig eth2 up
    ifconfig eth3 up
    ip link add name hsr0 type hsr slave1 eth2 slave2 eth3 supervision 45 version 1
    ifconfig hsr0 192.168.2.20

-  To switch from HSR to PRP

::

    ip link delete hsr0
    ifconfig eth2 down
    ifconfig eth3 down
    ethtool -K eth2 hsr-rx-offload off
    ethtool -K eth3 hsr-rx-offload off
    ethtool -K eth2 prp-rx-offload on
    ethtool -K eth3 prp-rx-offload on
    ifconfig eth2 up
    ifconfig eth3 up
    ip link add name prp0 type prp slave1 eth2 slave2 eth3 supervision 45
    ifconfig prp0 192.168.2.20

-  To switch from PRP to HSR

::

    ip link delete prp0
    ifconfig eth2 down
    ifconfig eth3 down
    ethtool -K eth2 prp-rx-offload off
    ethtool -K eth3 prp-rx-offload off
    ethtool -K eth2 hsr-rx-offload on
    ethtool -K eth3 hsr-rx-offload on
    ifconfig eth2 up
    ifconfig eth3 up
    ip link add name hsr0 type hsr slave1 eth2 slave2 eth3 supervision 45 version 1
    ifconfig hsr0 192.168.2.20

-  To switch from HSR to EMAC

::

    ip link delete hsr0
    ifconfig eth2 down
    ifconfig eth3 down
    #Restore eth3 MAC address
    ifconfig eth3 hw ether 70:FF:76:1C:0E:8E
    ethtool -K eth2 hsr-rx-offload off
    ethtool -K eth3 hsr-rx-offload off
    ifconfig eth2 192.168.2.20
    ifconfig eth3 192.168.3.20

-  To switch from PRP to EMAC

::

    ip link delete prp0
    ifconfig eth2 down
    ifconfig eth3 down
    ethtool -K eth2 prp-rx-offload off
    ethtool -K eth3 prp-rx-offload off
    #Restore eth3 MAC address
    ifconfig eth3 hw ether 70:FF:76:1C:0E:8E
    ifconfig eth2 192.168.2.20
    ifconfig eth3 192.168.3.20

.. rubric:: PRP EMAC mode
   :name: prp-emac-mode

PRP EMAC mode is a special mode of PRP Ethernet type where the driver
configures the PRP firmware to work like EMAC firmware. This is because
currently PTP support is available only in PRU PRP firmware. So the
current implementation of SAN with PTP requires PRUETH driver to be
configured as PRP using bootargs. User needs to configure the PRP
Firmware in PRP EMAC mode before bringing up the Ethernet interfaces. It
is expected to add the PTP support to EMAC firmware in a future release.
Until then this intermediate solution is used. Here are the steps to use
PRUETH as SAN with PTP

-  Boot the IDK EVM with prussX\_ethtype in bootargs set to PRP as
   described at
   `#Testing\_HSR.2FPRP\_Firmware\_Offload <#Testing_HSR.2FPRP_Firmware_Offload>`__
-  Once the EVM boots up and user login, first thing to verify is if
   PRUETH is configured as PRP Ethernet type. See above section for
   details
-  Configure PRP EMAC mode in the PRP firmware by issuing the following
   command at the console

::

     echo 1 > /sys/kernel/debug/prueth-ethX/prp_emac_mode
     where X is 2 or 3 or 4 or 5

-  Now bring up Ethernet interfaces as usual and the device is ready to
   be used as SAN. PTP support can be enabled at this time. See section
   on
   [`[1] <http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_HSR_PRP#Linux_PTP>`__]
   for the details.

**NOTE: run time protocol switch is not supported for switch to SAN PTP
for now and required boot time configuration and above debugfs command
once device is boot up in PRP mode**

.. rubric:: VLAN over PRU Ethernet
   :name: vlan-over-pru-ethernet

Virtual LAN (VLAN) is a standard Linux feature that can be enabled over
PRU Ethernet devices. There are many websites that describes how Linux
VLAN works. Some of them are at
[`[2] <https://wiki.archlinux.org/index.php/VLAN>`__] or at
[`[3] <http://www.linuxjournal.com/article/10821>`__] and some
configuration details are also discussed at
[`[4] <https://www.cyberciti.biz/tips/howto-configure-linux-virtual-local-area-network-vlan.html>`__].

User may use ip link command to setup vlan interface over prueth
interfaces. For example, over a hsr interface, if user would like to
setup two vlan interfaces say, hsr0.2 and hsr0.3, user execute the
following commands assuming the hsr0 interface is already setup:-

Node-1

::

    ifconfig hsr0 0.0.0.0
    ip link add link hsr0 name hsr0.2 type vlan id 2
    ip link add link hsr0 name hsr0.3 type vlan id 3
    ifconfig hsr0.2 192.168.2.40
    ifconfig hsr0.3 192.168.3.40
    ip link set hsr0.2 type vlan egress 0:0 
    ip link set hsr0.3 type vlan egress 0:7

Node-2

::

    ifconfig hsr0 0.0.0.0
    ip link add link hsr0 name hsr0.2 type vlan id 2
    ip link add link hsr0 name hsr0.3 type vlan id 3
    ifconfig hsr0.2 192.168.2.50
    ifconfig hsr0.3 192.168.3.50
    ip link set hsr0.2 type vlan egress 0:0
    ip link set hsr0.3 type vlan egress 0:7

The above assume we have a network with two nodes connected back to
back. The procedure is same if more than two nodes are present in the
network. Using similar commands, user would be able to overlay multiple
virtual LANs over the physical LAN created. The egress option of ip link
command allow mapping packet priority to VLAN PCP values. In the example
the packets on VLAN ID 2 is mapped to PCP value of 0 and VLAN ID 3 is
mapped to PCP value of 7. At the Egress PRU Ethernet device looks at the
PCP value and places it into one of the 4 queues. PRU scan the high
priority queue first for packets and transmits them before transmitting
packets from the lower priority queues. At the ingress, the PRU checks
the PCP value of the packet in the VLAN header and places the frame into
one of the ingress queues. More details on Queue usage is available at
`#Queue\_Usage\_and\_VLAN\_PCP\_to\_Queue\_Map <#Queue_Usage_and_VLAN_PCP_to_Queue_Map>`__

In the above example, after passing some UDP traffic over hsr0.2 and
hsr0.3, the user may check following statistics to verify if the packets
are going over the right VLAN interface

On Node-1

::

    cat /proc/net/vlan/hsr0.3
    hsr0.3  VID: 3   REORDER_HDR: 1  dev->priv_flags: 1001
             total frames received        68090
              total bytes received     52598480
          Broadcast/Multicast Rcvd           52

::

          total frames transmitted        68090
           total bytes transmitted     52598459
    Device: hsr0
    INGRESS priority mappings: 0:0  1:0  2:0  3:0  4:0  5:0  6:0 7:0
     EGRESS priority mappings: 0:7
    root@am57xx-evm:~# cat /proc/net/vlan/hsr0.2
    hsr0.2  VID: 2   REORDER_HDR: 1  dev->priv_flags: 1001
            total frames received        68105
             total bytes received     52604702
          Broadcast/Multicast Rcvd           53

          total frames transmitted        68074
           total bytes transmitted     52583138
    Device: hsr0
    INGRESS priority mappings: 0:0  1:0  2:0  3:0  4:0  5:0  6:0 7:0
     EGRESS priority mappings: 0:0
    root@am57xx-evm:~# cat /sys/kernel/debug/prueth-eth2/stats
       TxQ-0    TxQ-1    TxQ-2    TxQ-3    RxQ-0    RxQ-1
    =====================================================
       68041        0        0    68908    67809    68925
    root@am57xx-evm:~# cat /sys/kernel/debug/prueth-eth3/stats
       TxQ-0    TxQ-1    TxQ-2    TxQ-3    RxQ-2    RxQ-3
    =====================================================
       68041        0        0    68912      234      695

Similar procedure can be used for setting up VLAN interfaces over PRU
EMAC and HSR Ethernet types.

.. rubric:: Net-SNMP
   :name: net-snmp

The TI SDK release ships tisdk-rootfs-image-am57xx-evm.tar.xz with
Net-SNMP 5.7.3 binaries pre-installed and snmpd is started as part of
the user space initialization. TI has developed a Net-SNMP module to
support IEC-62439-3 related MIB access at the DAN using snmp commands
such as snmpwalk, snmpget etc. **NOTE:** IEC-62439-3 MIB is supported
only in the offloaded case. So user is expected to create HSR/PRP
interface with offload. For details on how to setup HSR/PRP interface
with offload, please refer `HSR-PRP
Offload </index.php/Processor_SDK_Linux_HSR_PRP#Testing_HSR.2FPRP_Firmware_Offload>`__

.. rubric:: Command examples
   :name: command-examples

An example snmpwalk command execution is shown below where 192.168.2.20
is the IP address of the remote DAN-P or DAN-H prp/hsr interface.

::

    root@am57xx-evm:/etc/snmp# snmpwalk -v 2c -c public 192.168.2.20 iec62439
    IEC-62439-3-MIB::lreManufacturerName.0 = STRING: TI LRE
    IEC-62439-3-MIB::lreInterfaceCount.0 = INTEGER: 1
    IEC-62439-3-MIB::lreRowStatus.1 = INTEGER: active(1)
    IEC-62439-3-MIB::lreNodeType.1 = INTEGER: hsr(2)
    IEC-62439-3-MIB::lreNodeName.1 = STRING: hsr0
    IEC-62439-3-MIB::lreVersionName.1 = ""
    IEC-62439-3-MIB::lreMacAddress.1 = STRING: d2:ef:e6:2a:1f:5b
    IEC-62439-3-MIB::lrePortAdminStateA.1 = INTEGER: active(2)
    IEC-62439-3-MIB::lrePortAdminStateB.1 = INTEGER: active(2)
    IEC-62439-3-MIB::lreLinkStatusA.1 = INTEGER: up(1)
    IEC-62439-3-MIB::lreLinkStatusB.1 = INTEGER: up(1)
    IEC-62439-3-MIB::lreDuplicateDiscard.1 = INTEGER: discard(2)
    IEC-62439-3-MIB::lreTransparentReception.1 = INTEGER: 0
    IEC-62439-3-MIB::lreHsrLREMode.1 = INTEGER: modeh(1)
    IEC-62439-3-MIB::lreSwitchingEndNode.1 = INTEGER: hsrnode(5)
    IEC-62439-3-MIB::lreRedBoxIdentity.1 = INTEGER: id1a(2)
    IEC-62439-3-MIB::lreEvaluateSupervision.1 = INTEGER: true(1)
    IEC-62439-3-MIB::lreNodesTableClear.1 = INTEGER: noOp(0)
    IEC-62439-3-MIB::lreProxyNodeTableClear.1 = INTEGER: noOp(0)
    IEC-62439-3-MIB::lreDupListResideMaxTime.1 = INTEGER: 26214 binaryFractionOfSecond
    IEC-62439-3-MIB::lreCntTxA.1 = Counter32: 7384
    IEC-62439-3-MIB::lreCntTxB.1 = Counter32: 7385
    IEC-62439-3-MIB::lreCntTxC.1 = Counter32: 4032
    IEC-62439-3-MIB::lreCntErrWrongLanA.1 = Counter32: 0
    IEC-62439-3-MIB::lreCntErrWrongLanB.1 = Counter32: 0
    IEC-62439-3-MIB::lreCntErrWrongLanC.1 = Counter32: 0
    IEC-62439-3-MIB::lreCntRxA.1 = Counter32: 4024
    IEC-62439-3-MIB::lreCntRxB.1 = Counter32: 4025
    IEC-62439-3-MIB::lreCntRxC.1 = Counter32: 0
    IEC-62439-3-MIB::lreCntErrorsA.1 = Counter32: 3351
    IEC-62439-3-MIB::lreCntErrorsB.1 = Counter32: 3351
    IEC-62439-3-MIB::lreCntErrorsC.1 = Counter32: 0
    IEC-62439-3-MIB::lreCntNodes.1 = INTEGER: 1
    IEC-62439-3-MIB::lreCntProxyNodes.1 = INTEGER: 0
    IEC-62439-3-MIB::lreCntUniqueA.1 = Counter32: 4
    IEC-62439-3-MIB::lreCntUniqueB.1 = Counter32: 4
    IEC-62439-3-MIB::lreCntUniqueC.1 = Counter32: 0
    IEC-62439-3-MIB::lreCntDuplicateA.1 = Counter32: 0
    IEC-62439-3-MIB::lreCntDuplicateB.1 = Counter32: 0
    IEC-62439-3-MIB::lreCntDuplicateC.1 = Counter32: 3992
    IEC-62439-3-MIB::lreCntMultiA.1 = Counter32: 0
    IEC-62439-3-MIB::lreCntMultiB.1 = Counter32: 0
    IEC-62439-3-MIB::lreCntMultiC.1 = Counter32: 0
    IEC-62439-3-MIB::lreCntOwnRxA.1 = Counter32: 0
    IEC-62439-3-MIB::lreCntOwnRxB.1 = Counter32: 0
    IEC-62439-3-MIB::lreNodesMacAddress.1.1 = STRING: 70:ff:76:1c:f:8d
    IEC-62439-3-MIB::lreTimeLastSeenA.1.1 = Timeticks: (0) 0:00:00.00
    IEC-62439-3-MIB::lreTimeLastSeenB.1.1 = Timeticks: (1) 0:00:00.01
    IEC-62439-3-MIB::lreRemNodeType.1.1 = INTEGER: danh(3)

Individual MIB variable may be queried or set using snmpset or snmpget
commands. Below are some examples:- snmpset

::

    snmpset -v 2c -c private 192.168.2.20 IEC-62439-3-MIB::lreHsrLREMode.1 i 3

snmpget

::

    snmpget -v 2c -c public 192.168.2.20 IEC-62439-3-MIB::lreManufacturerName.0

.. rubric:: MIB Support
   :name: mib-support

+---------------------------+----------------------------------+---------------------------------+--------------------+
| MIB variable              | Group                            | Actions Specified by Standard   | Action supported   |
+===========================+==================================+=================================+====================+
| lreManufacturerName       | lreConfigurationGeneralGroup     | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreInterfaceCount         | lreConfigurationGeneralGroup     | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreInterfaceConfigTable   | lreConfigurationInterfaceGroup   | NA                              | NA                 |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreInterfaceConfigEntry   | lreConfigurationInterfaceGroup   | NA                              | NA                 |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreInterfaceConfigIndex   | lreConfigurationInterfaceGroup   | NA                              | NA                 |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreRowStatus              | lreConfigurationInterfaceGroup   | NA                              | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreNodeType               | lreConfigurationInterfaceGroup   | get/set                         | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreNodeName               | lreConfigurationInterfaceGroup   | get/set                         | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreVersionName            | lreConfigurationInterfaceGroup   | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreMacAddress             | lreConfigurationInterfaceGroup   | get/set                         | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lrePortAdminStateA        | lreConfigurationInterfaceGroup   | get/set                         | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lrePortAdminStateB        | lreConfigurationInterfaceGroup   | get/set                         | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreLinkStatusA            | lreConfigurationInterfaceGroup   | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreLinkStatusB            | lreConfigurationInterfaceGroup   | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreDuplicateDiscard       | lreConfigurationInterfaceGroup   | get/set                         | get/set            |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreTransparentReception   | lreConfigurationInterfaceGroup   | get/set                         | get/set            |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreHsrLREMode             | lreConfigurationInterfaceGroup   | get/set                         | get/set            |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreSwitchingEndNode       | lreConfigurationInterfaceGroup   | get/set                         | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreRedBoxIdentity         | lreConfigurationInterfaceGroup   | get/set                         | NS                 |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreEvaluateSupervision    | lreConfigurationInterfaceGroup   | get/set                         | NS                 |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreNodesTableClear        | lreConfigurationInterfaceGroup   | get/set                         | get/set            |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreProxyNodeTableClear    | lreConfigurationInterfaceGroup   | get/set                         | NS                 |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreDupListResideMaxTime   | lreConfigurationInterfaceGroup   | get/set                         | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreInterfaceStatsTable    | lreStatisticsInterfaceGroup      | NA                              | NA                 |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreInterfaceStatsEntry    | lreStatisticsInterfaceGroup      | NA                              | NA                 |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreInterfaceStatsIndex    | lreStatisticsInterfaceGroup      | NA                              | Yes                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntTxA                 | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntTxB                 | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntTxC                 | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntErrWrongLanA        | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntErrWrongLanB        | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntErrWrongLanC        | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntRxA                 | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntRxB                 | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntRxC                 | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntErrorsA             | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntErrorsB             | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntErrorsC             | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntNodes               | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntProxyNodes          | lreStatisticsInterfaceGroup      | get                             | NS                 |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntUniqueA             | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntUniqueB             | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntUniqueC             | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntDuplicateA          | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntDuplicateB          | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntDuplicateC          | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntMultiA              | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntMultiB              | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntMultiC              | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntOwnRxA              | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreCntOwnRxB              | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreNodesTable             | lreStatisticsInterfaceGroup      | NA                              | Yes                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreNodesIndex             | lreStatisticsInterfaceGroup      | NA                              | Yes                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreNodesMacAddress        | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreTimeLastSeenA          | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreTimeLastSeenB          | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreRemNodeType            | lreStatisticsInterfaceGroup      | get                             | get                |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreProxyNodeTable         | lreStatisticsInterfaceGroup      |                                 | NS                 |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreProxyNodeEntry         | lreStatisticsInterfacesGroup     | NA                              | NS                 |
+---------------------------+----------------------------------+---------------------------------+--------------------+
| lreProxyNodeMacAddress    | lreStatisticsInterfacesGroup     | get                             | NS                 |
+---------------------------+----------------------------------+---------------------------------+--------------------+

**Note** NS: Not supported, NA: Not Applicable

.. rubric:: iproute2
   :name: iproute2

iproute2 is enhanced to allow creating a prp interface similar to hsr
interface using two slave interfaces.

.. rubric:: Linux PTP
   :name: linux-ptp

Linux PTP documentation is available at
[`[5] <http://processors.wiki.ti.com/index.php/Processor_SDK_LINUX_PTP>`__]

.. rubric:: Linux HSR/PRP Driver source code and Kconfig option
   :name: linux-hsrprp-driver-source-code-and-kconfig-option

The driver source code is located under net/hsr-prp folder of the Linux
source tree. To build kernel with this driver, set Kconfig option
CONFIG\_HSR\_PRP=y in the dotconfig or enable it from the menu.

.. rubric:: Supported Platforms
   :name: supported-platforms

-  AM571x, AM572x IDK (Only eth2 and eth3)

.. rubric:: Test Procedure
   :name: test-procedure

.. rubric:: Testing HSR/PRP Firmware Offload
   :name: testing-hsrprp-firmware-offload

The setup of the IDKs for testing HSR/PRP firmware offload and the
configuration of the HSR/PRP interfaces after kernel boot up are no
different than the case without firmware offload. The differences are,
in the case of firmware offload, the correct PRU firmware needs to be
loaded and the PRUETH driver needs to be configured to interface with
the type of firmware loaded, during boot up.

The module parameter "ti\_prueth.pruss1\_ethtype" and
"ti\_prueth.pruss2\_ethtype" are used for instructing the PRU Ethernet
driver what type of PRU firmware is to be loaded to PRU-ICSS1 and
PRU-ICSS2 respectively. These type values are:

+---------------------------------------+-----------------+
| ti\_prueth.prussX\_ethtype, X = 1,2   | firmware type   |
+=======================================+=================+
| 0                                     | EMAC            |
+---------------------------------------+-----------------+
| 1                                     | HSR             |
+---------------------------------------+-----------------+
| 2                                     | PRP             |
+---------------------------------------+-----------------+

These ti\_prueth.prussX\_type values can be set up in the Kernel boot
argument in Uboot. For example, to load HSR firmware to PRU-ICSS1 and
PRP firmware to PRU-ICSS2, and assuming boot using NFS rootfs, the
Kernel boot argument can be configured as follows. Under Uboot prompt,

::

     => setenv netargs 'setenv bootargs console=${console} ${optargs} root=/dev/nfs nfsroot=${serverip}:${rootpath},${nfsopts} rw ip=dhcp
    ti_prueth.pruss1_ethtype=${pruss1_ethtype} ti_prueth.pruss2_ethtype=${pruss2_ethtype}'
     => setenv pruss1_ethtype 1
     => setenv pruss2_ethtype 2
     => saveenv

**NOTE** If using mmc rootfs, update args\_mmc as below

::

     => setenv args_mmc 'run finduuid;setenv bootargs console=${console} ${optargs} root=PARTUUID=${uuid} rw rootfstype=${mmcrootfstype}
    ti_prueth.pruss1_ethtype=${pruss1_ethtype} ti_prueth.pruss2_ethtype=${pruss2_ethtype}'

Just change the value of pruss1\_ethtype or pruss2\_ethtype in the above
example to switch to a different type of firmware (see the above table).
If a ti\_prueth.prussX\_ethtype is not configured, ie. does not appear
in Kernel boot argument, the default EMAC firmware will be loaded to the
corresponding PRU-ICSSX. In this case, if user sets up HSR/PRP
interface, it will work without offload using the PRU EMAC firmware and
driver. So using offload or no offload is controlled via selecting
appropriate firmware at boot up and is transparent to user.

Remarks:

#. Setting ti\_prueth.prussX\_ethtype to 0 is the same as not using it
   in the Kernel argument. In either case, default EMAC firmware is
   loaded.
#. "ti\_prueth.prussX\_ethtype=", ie. setting the module parameter but
   without a value, is incorrect.
#. On AM572x IDK, only PRU-ICSS2 is supported. Hence only
   prueth.pruss2\_type takes effect.

To verify PRU Ethernet type after boot, do following that display TI PRU
ethernet type

::

    dmesg | grep "TI PRU ethernet (type"

For PRU Emac, the string displayed will be

::

    prueth pruss2_eth: TI PRU ethernet (type 0) driver initialized

For PRU HSR, the string displayed will be

::

    prueth pruss2_eth: TI PRU ethernet (type 1) driver initialized

For PRU PRP, the string displayed will be

::

    prueth pruss2_eth: TI PRU ethernet (type 2) driver initialized

Where type is what is set in the bootargs and is listed in the table at
the beginning of this section

.. rubric:: Node Tables (firmware offload)
   :name: node-tables-firmware-offload

In the case of HSR/PRP firmware offload, the Node Table can be displayed
as follows. Note: the locations are different from those when there is
no firmware offload.

To show the **HSR Node Table**, under the kernel prompt on the terminal
connected to the IDK, do

-  root@am57xx-evm:~# cat /sys/kernel/debug/**prueth-hsr**/node\_table
-  Sample display

::

     root@am57xx-evm:~# cat /sys/kernel/debug/prueth-hsr/node_table 
     
     Remote nodes in network: 1
     
     Node[1]:
     MAC ADDR: 70:ff:76:1c:0f:99
     state: valid
     DANH
     RxA=2992 SupRxA=148
     RxB=2992 SupRxB=148
     Time Last Seen: Sup=0 RxA=0 RxB=0

To show the **PRP Node Table**, under the kernel prompt on the terminal
connected to the IDK, do

-  root@am57xx-evm:~# cat /sys/kernel/debug/**prueth-prp**/node\_table
-  Sample display

::

     root@am57xx-evm:~# cat /sys/kernel/debug/prueth-prp/node_table 
     
     Remote nodes in network: 1
     
     Node[1]:
     MAC ADDR: 70:ff:76:1c:0f:99
     state: valid
     DupDiscard (0x80)
     DANP
     RxA=17 SupRxA=17
     RxB=17 SupRxB=17
     Time Last Seen: Sup=0 RxA=0 RxB=0
     PRP LineID Err: A=0 B=0

.. rubric:: LRE Statistics (firmware offload)
   :name: lre-statistics-firmware-offload

The LRE statistics is displayed as part the interface statistics using
the "ethtool -S DEVNAME" command, where DEVNAME, in the case AM572x IDK,
is eth2 or eth3. The fields pertaining to LRE statistics are prefixed
with "lre". Since LRE statistics are LRE specific, instead of interface
specific, so either "ethtool -S eth2" or "ethtool -S eth3" will show the
same LRE statistics.

Sample display:

::

     root@am57xx-evm:~# ethtool -S eth2     
     NIC statistics:
          txBcast: 1
          txMcast: 11635
          txUcast: 3
          txOctets: 816642
          rxBcast: 0
          rxMcast: 36
          rxUcast: 17
          rxOctets: 4841
          tx64byte: 6
          tx65_127byte: 11633
          tx128_255byte: 0
          tx256_511byte: 0
          tx512_1023byte: 0
          tx1024byte: 0
          rx64byte: 4
          rx65_127byte: 49
          rx128_255byte: 0
          rx256_511byte: 0
          rx512_1023byte: 0
          rx1024byte: 0
          lateColl: 0
          singleColl: 0
          multiColl: 0
          excessColl: 0
          rxMisAlignmentFrames: 0
          stormPrevCounter: 0
          macRxError: 0
          SFDError: 0
          defTx: 0
          macTxError: 0
          rxOverSizedFrames: 0
          rxUnderSizedFrames: 0
          rxCRCFrames: 0
          droppedPackets: 0
          txHWQOverFlow: 0
          txHWQUnderFlow: 0
          lreTxA: 11636
          lreTxB: 11639
          lreTxC: 66
          lreErrWrongLanA: 0
          lreErrWrongLanB: 0
          lreErrWrongLanC: 0
          lreRxA: 40
          lreRxB: 40
          lreRxC: 0
          lreErrorsA: 11560
          lreErrorsB: 11559
          lreErrorsC: 0
          lreNodes: 0
          lreProxyNodes: 0
          lreUniqueRxA: 0
          lreUniqueRxB: 0
          lreUniqueRxC: 0
          lreDuplicateRxA: 0
          lreDuplicateRxB: 0
          lreDuplicateRxC: 0
          lreMultiRxA: 0
          lreMultiRxB: 0
          lreMultiRxC: 0
          lreOwnRxA: 0
          lreOwnRxB: 0
          lreDuplicateDiscard: 2
          lreTransRecept: 1
          lreNtLookupErrA: 0
          lreNtLookupErrB: 0
          lreNodeTableFull: 0

.. rubric:: HSR Testing
   :name: hsr-testing

To test HSR, user would need two AM572x EVMs.

#. Setup HSR Ring network as per diagram below. Connect the PRU2ETH0
   (See the marking on the EVM) Ethernet ports of the two EVMs together
   (corresponds to Linux interface eth2) as shown below. Similarly,
   connect the PRU2ETH1 ports (Linux interface eth3) as well.
#. Configure the bootargs to boot PRU with HSR firmware as described
   above at
   `Processor\_SDK\_Linux\_HSR\_PRP#Testing\_HSR.2FPRP\_Firmware\_Offload </index.php/Processor_SDK_Linux_HSR_PRP#Testing_HSR.2FPRP_Firmware_Offload>`__
#. Boot the EVMs using the pre-built images from the Processor SDK
   release. These images are built with Linux HSR/PRP driver enabled.
   Login to the console using root user name.
#. Note the MAC Address of eth2 at DAN-H-1(Say MAC-A) using the ifconfig
   command. Do ifconfig eth2 at the Linux console of DAN-H-1
#. Note the MAC Address of eth2 at DAN-H-2(Say MAC-B) using the ifconfig
   command. Do ifconfig eth2 at the Linux console of DAN-H-2

   #. ifconfig eth2 down
   #. ifconfig eth3 down
   #. ifconfig eth3 hw ether <MAC-A>
   #. ifconfig eth2 up
   #. ifconfig eth3 up
   #. ip link add name hsr0 type hsr slave1 eth2 slave2 eth3 supervision
      45 version 1
   #. ifconfig hsr0 <IP Address of hsr interface at DAN-H-1> up

#. Repeat the above steps for DAN-H-2, but this time use MAC-B in step
   4.3 above. And use IP Address from the same subnet as that of DAN-H-1
   hsr interface hsr0.

.. Image:: ../images/Hsr-network-setup-v2.jpg

For example use Ip Address 192.168.2.20 for DAN-H-1 and 192.168.2.30 for
DAN-H-2. Assume CPSW ports at the EVM are on a different Subnet than the
HSR interface.

Once both hsr0 interfaces are created, user should be able to do a ping
from DAN-H-1 to DAN-H-2 or vice-versa. Disconnect Ethernet cable at eth2
or eth3. The Ping should continue to go through. User could run iperf
between the two HSR interfaces and test the iperf is not affected when
one of the cable is disconnected. This verifies redundancy.

A Sample script that automates the steps 4.1 to 4.7, say setup.sh, is
below

::


    #!/bin/sh
    if [ $# -lt 3 ]
    then
            echo "setup.sh <hsr/prp> <MAC-Address for both slaves> <ip address for hsr/prp interface>"
            exit
    fi
      
    if [ "$1" != "hsr" ] && [ "$1" != "prp" ]
    then
        echo "use hsr or prp as first argument"
        exit
    fi
     
    echo "Setting up $10 interface with MAC address $2 for slaves and IP address $3"
     
    ifconfig eth2 down
    ifconfig eth3 down
    ifconfig eth2 hw ether $2
    ifconfig eth3 hw ether $2
    ifconfig eth2 up
    ifconfig eth3 up
     
    if [ "$1" == "hsr" ]
    then
            ip link add name hsr0 type hsr slave1 eth2 slave2 eth3 supervision 45 version 1
            ifconfig hsr0 $3 up
    else
            ip link add name prp0 type prp slave1 eth2 slave2 eth3 supervision 45
            ifconfig prp0 $3 up
    fi

Using this script, user can setup hsr interface as

::

     
    /setup.sh hsr <MAC-A> <IP Address of the interface>

where it is assumed that the setup.sh is copied to the root directory of
the target file system and is made executable

Below script can be used to teardown the hsr interface (say teardown.sh)

::

    #!/bin/sh
    if [ $# -lt 1 ]
    then
            echo "teardown.sh <hsr/prp>"
            exit
    fi

    if [ "$1" != "hsr" ] && [ "$1" != "prp" ]
    then
        echo "use hsr or prp as first argument"
        exit
    fi

    if [ "$1" == "hsr" ]
    then
            ip link del hsr0
    else
            ip link del prp0
    fi

Using the above script, user teardown the hsr interface as

::

    /teardown.sh hsr

Sample logs are shown here `DAN-H-1 </index.php/DAN-H-1>`__,
`DAN-H-2 </index.php/DAN-H-2>`__

.. rubric:: PRP Testing
   :name: prp-testing

.. Image:: ../images/Prp-network-setup.jpg

For Testing PRP, user is required to use the setup shown in the above
diagram. A DAN-P is attached to two independent networks (A and B) each
of which is shown as a separate Ethernet switch. Do the following steps
to setup the prp interface. Note that in the below example Linux
interface eth2 is Link-A (slave1 in ip link command) and eth3 is Link-B
(slave2 in ip link command). Link-A is the Ethernet cable that connects
DUT to Switch A and Link-B is the Ethernet cable that connects to
Switch-B. **This is very important for PRP as swapping them is an
incorrect connection and can produce undesirable results.**

#. Connect the DAN-P-1 EVM, PRU2ETH0 (marking on EVM) to a port at
   Ethernet switch A and PRU2ETH1 to a port at Ethernet switch B
#. Similarly, connect DAN-P-2 EVM, PRU2ETH0 to a port at Ethernet switch
   A and PRU2ETH1 to a port at Ethernet switch B
#. Configure the PRU to load PRP firmware by setting env variable as
   discussed at
   `Processor\_SDK\_Linux\_HSR\_PRP#Testing\_HSR.2FPRP\_Firmware\_Offload </index.php/Processor_SDK_Linux_HSR_PRP#Testing_HSR.2FPRP_Firmware_Offload>`__
#. Boot the EVMs using the pre-built images from the Processor SDK
   release. These images are built with Linux HSR/PRP driver enabled.
   Login to the console using root user name.
#. This time user may use the script (setup.sh) to create the prp
   interface. Note the MAC-A and MAC-B as in the case of HSR (MAC
   address of eth2)
#. setup the prp interface at DAN-P-1 as follows

   #. /setup.sh prp <MAC-A> <IP Address of prp interface>

#. setup the prp interface at DAN-P-2 as follows:-

   #. /setup.sh prp <MAC-B> <IP Address of prp interface>

If PRP interface uses IP address 192.168.2.20 and eth2 MAC address is
70:ff:76:1c:0f:8d, following example command may be used at DAN-P-1

::

    /setup.sh prp 70:ff:76:1c:0f:8d 192.168.2.20

If PRP interface uses IP address 192.168.2.30 and eth2 MAC address is
70:ff:76:1c:0f:8e following example command may be use at DAN-P-2

::

    /setup.sh prp 70:ff:76:1c:0f:8e 192.168.2.30

To teardown the prp interface do

::

    /teardown.sh prp

Sample logs are shown here `DAN-P-1 </index.php/DAN-P-1>`__,
`DAN-P-2 </index.php/DAN-P-2>`__

.. rubric:: Performance Test and Logs
   :name: performance-test-and-logs

Boot up two AM571x/572x EVM to configure PRU Ethernet in HSR or PRP mode
as described at
`Processor\_SDK\_Linux\_HSR\_PRP#Testing\_HSR.2FPRP\_Firmware\_Offload </index.php/Processor_SDK_Linux_HSR_PRP#Testing_HSR.2FPRP_Firmware_Offload>`__.
They are connected over eth2 and eth3 as described in
`Processor\_SDK\_Linux\_HSR\_PRP#HSR
Test </index.php/Processor_SDK_Linux_HSR_PRP#HSR_Test>`__ or
`Processor\_SDK\_Linux\_HSR\_PRP#PRP
Test </index.php/Processor_SDK_Linux_HSR_PRP#PRP_Test>`__

.. rubric:: UDP
   :name: udp

Sample iperf UDP test showing no packet loss for MTU sized packets. For
HSR/PRP, there are 6 bytes of Tag effectively reducing pay load size to
1466 (1500 - 6 - 20 - 8)

Server Side

::

    root@am57xx-evm:~# iperf -s -u
    ------------------------------------------------------------
    Server listening on UDP port 5001
    Receiving 1470 byte datagrams
    UDP buffer size:  160 KByte (default)
    ------------------------------------------------------------
    [  3] local 192.168.2.20 port 5001 connected with 192.168.2.30 port 34255
    [ ID] Interval       Transfer     Bandwidth        Jitter   Lost/Total Datagrams
    [  3]  0.0-60.0 sec   630 MBytes  88.1 Mbits/sec   0.002 ms    0/450887 (0%)
    [  3]  0.0-60.0 sec  1 datagrams received out-of-order

Client side

::

    root@am57xx-evm:~# iperf -c 192.168.2.20 -u -b88M -l1466 -t60
    ------------------------------------------------------------
    Client connecting to 192.168.2.20, UDP port 5001
    Sending 1466 byte datagrams
    UDP buffer size:  160 KByte (default)
    ------------------------------------------------------------
    [  3] local 192.168.2.30 port 34255 connected with 192.168.2.20 port 5001
    [ ID] Interval       Transfer     Bandwidth
    [  3]  0.0-60.0 sec   630 MBytes  88.1 Mbits/sec
    [  3] Sent 450888 datagrams
    [  3] Server Report:
    [  3]  0.0-60.0 sec   630 MBytes  88.1 Mbits/sec   0.002 ms    0/450887 (0%)
    [  3]  0.0-60.0 sec  1 datagrams received out-of-order

**NOTE:** When doing UDP test, user may observe out of order packets
sometimes. This is normal as the driver doesn't use NAPI and packets may
get queued to backlog queues of each CPU which may get delivered out of
sequence to the iperf application. Out of order delivery of UDP packets
are normal and kernel doesn't guarantee in sequence delivery of UDP
packets to application. So iperf may show some packets lost during the
test. User may use some of the tools available to migrate the rx irq
threads and iperf server to same CPU, example CPU 0, to mitigate out of
order issue and get a no loss iperf stats for udp tests.

For example, here is a snapshot of the test that shows packet lost
during the test. The test also shows 106 datagram received out of order.

::

    root@am57xx-evm:~# iperf -s -u
    ------------------------------------------------------------
    Server listening on UDP port 5001
    Receiving 1470 byte datagrams
    UDP buffer size:  160 KByte (default)
    ------------------------------------------------------------
    [  3] local 192.168.2.30 port 5001 connected with 192.168.2.20 port 41976
    [ ID] Interval       Transfer     Bandwidth        Jitter   Lost/Total Datagrams
    [  3]  0.0-600.0 sec  6.15 GBytes  88.0 Mbits/sec   0.004 ms    5/4501411 (0.00011%)
    [  3]  0.0-600.0 sec  106 datagrams received out-of-order

| 
| Here is how to re-run the test by migrating the iperf server and irq
  threads to CPU 0

Run the iperf -s -u & Do ps command and find the PID of the iperf and
migrate the process to CPU 0 as follows

::

    root@am57xx-evm:~# ps
     PID TTY          TIME CMD
     964 ttyS2    00:00:00 login
    1063 ttyS2    00:00:00 sh
    1135 ttyS2    00:00:00 iperf
    1141 ttyS2    00:00:00 ps
    root@am57xx-evm:~# taskset -cp 0 1135
    pid 1135's current affinity list: 0,1
    pid 1135's new affinity list: 0

Now find the irq thread for eth2, eth3 devices using

::

    root@am57xx-evm:~# ps -ef  | grep "eth3"
    root      1464     2  0 06:01 ?        00:00:00 [irq/498-eth3]
    root      1495  1065  0 06:04 ttyS2    00:00:00 grep irq/498-eth3
    root@am57xx-evm:~# ps -ef  | grep "eth2"
    root      1462     2  0 06:01 ?        00:00:00 [irq/496-eth2]
    root      1497  1065  0 06:04 ttyS2    00:00:00 grep irq/496-eth2

In the above example 1462 is the process id of irq/496-eth2 thread and
1464 is the process ID of irq/498-eth3 . Do following to migrate them to
CPU 0.

::

    root@am57xx-evm:~# taskset -cp 0 1464
    pid 1464's current affinity list: 0,1
    pid 1464's new affinity list: 0
    root@am57xx-evm:~# taskset -cp 0 1462
    pid 1462's current affinity list: 0,1
    pid 1462's new affinity list: 0
    root@am57xx-evm:~#
    root@am57xx-evm:~#

Now start iperf client on the other side. The server side log below with
these tuning shows no packet loss.

::

    [  4] local 192.168.2.30 port 5001 connected with 192.168.2.20 port 36415
    [  4]  0.0-600.0 sec  6.15 GBytes  88.0 Mbits/sec   0.007 ms    0/4501355 (0%)
    [  4]  0.0-600.0 sec  1 datagrams received out-of-order

| 

+---------------+----------------------------------------+
| Packet Size   | Tput with no packet loss (Mbits/sec)   |
+===============+========================================+
| 1466          | 88                                     |
+---------------+----------------------------------------+
| 1024          | 88                                     |
+---------------+----------------------------------------+
| 512           | 64                                     |
+---------------+----------------------------------------+
| 256           | 45                                     |
+---------------+----------------------------------------+

Table:  UDP Performance for HSR

+---------------+----------------------------------------+
| Packet Size   | Tput with no packet loss (Mbits/sec)   |
+===============+========================================+
| 1466          | 88                                     |
+---------------+----------------------------------------+
| 1024          | 88                                     |
+---------------+----------------------------------------+
| 512           | 60                                     |
+---------------+----------------------------------------+
| 256           | 38                                     |
+---------------+----------------------------------------+

Table:  UDP Performance for PRP

| 

**NOTE-1:**\ Test ran for 1 minute with single direction traffic (Client
to Server). Reduced the traffic from 88Mbits/sec until there is no out
of order or lost packets in the iperf stats

.. rubric:: TCP
   :name: tcp

.. rubric:: HSR
   :name: hsr

Server side

::

    root@am57xx-evm:~# iperf -s   
    ------------------------------------------------------------
    Server listening on TCP port 5001
    TCP window size: 85.3 KByte (default)
    ------------------------------------------------------------
    [  4] local 192.168.2.20 port 5001 connected with 192.168.2.30 port 54148
    [ ID] Interval       Transfer     Bandwidth
    [  4]  0.0-60.0 sec   663 MBytes  92.7 Mbits/sec

Client side

::

    root@am57xx-evm:~# iperf -c 192.168.2.20  -t60
    ------------------------------------------------------------
    Client connecting to 192.168.2.20, TCP port 5001
    TCP window size: 43.8 KByte (default)
    ------------------------------------------------------------
    [  3] local 192.168.2.30 port 54148 connected with 192.168.2.20 port 5001
    [ ID] Interval       Transfer     Bandwidth
    [  3]  0.0-60.0 sec   663 MBytes  92.7 Mbits/sec

.. rubric:: PRP
   :name: prp

Server side

::

    root@am57xx-evm:~# iperf -s
    ------------------------------------------------------------
    Server listening on TCP port 5001
    TCP window size: 85.3 KByte (default)
    ------------------------------------------------------------
    [  4] local 192.168.2.20 port 5001 connected with 192.168.2.30 port 54150
    [ ID] Interval       Transfer     Bandwidth
    [  4]  0.0-60.0 sec   660 MBytes  92.3 Mbits/sec

Client side

::

    root@am57xx-evm:~# iperf -c 192.168.2.20 -t60               
    ------------------------------------------------------------
    Client connecting to 192.168.2.20, TCP port 5001
    TCP window size: 43.8 KByte (default)
    ------------------------------------------------------------
    [  3] local 192.168.2.30 port 54150 connected with 192.168.2.20 port 5001
    [ ID] Interval       Transfer     Bandwidth
    [  3]  0.0-60.0 sec   660 MBytes  92.3 Mbits/sec

.. rubric:: Redundancy Test and Logs
   :name: redundancy-test-and-logs

For HSR and PRP redundancy is implemented using duplicate links and
sending frame over both links and discarding the duplicate at the
receive side. The test requires two DAN-P or DAN-H nodes connected over
eth2 and eth3 Ethernet Links. Boot up the EVM with bootargs set to
configure PRU Ethernet in HSR or PRP mode as described at
`Processor\_SDK\_Linux\_HSR\_PRP#Testing\_HSR.2FPRP\_Firmware\_Offload </index.php/Processor_SDK_Linux_HSR_PRP#Testing_HSR.2FPRP_Firmware_Offload>`__
Do an iperf UDP test at 88Mbits/sec for MTU sized packets (size = 1466)
and then pull out either eth2 or eth3 Ethernet cable. Make sure iperf
stats doesn't show packet loss during the test period. Here is the log
for HSR that show link failed during the test and there was no packet
loss.

eth3 link failed

::

    root@am57xx-evm:~# iperf -c 192.168.2.20 -u -b88M -l1466 -t60
    ------------------------------------------------------------
    Client connecting to 192.168.2.20, UDP port 5001
    Sending 1466 byte datagrams
    UDP buffer size:  160 KByte (default)
    ------------------------------------------------------------
    [  3] local 192.168.2.30 port 50443 connected with 192.168.2.20 port 5001
    [  108.740402] prueth pruss2_eth eth3: Link is Down
    [ ID] Interval       Transfer     Bandwidth
    [  3]  0.0-60.0 sec   631 MBytes  88.2 Mbits/sec
    [  3] Sent 451002 datagrams
    [  3] Server Report:
    [  3]  0.0-60.0 sec   631 MBytes  88.2 Mbits/sec   0.003 ms    0/451001 (0%)
    [  3]  0.0-60.0 sec  1 datagrams received out-of-order
    root@am57xx-evm:~# [  181.444988] prueth pruss2_eth eth3: Link is Up - 100Mbps/Full - flow control off

eth2 link failed

::

    root@am57xx-evm:~# iperf -c 192.168.2.20 -u -b88M -l1466 -t60
    ------------------------------------------------------------
    Client connecting to 192.168.2.20, UDP port 5001
    Sending 1466 byte datagrams
    UDP buffer size:  160 KByte (default)
    ------------------------------------------------------------
    [  3] local 192.168.2.30 port 49260 connected with 192.168.2.20 port 5001
    [  204.253286] prueth pruss2_eth eth2: Link is Down
    [ ID] Interval       Transfer     Bandwidth
    [  3]  0.0-60.0 sec   631 MBytes  88.2 Mbits/sec
    [  3] Sent 451028 datagrams
    [  3] Server Report:
    [  3]  0.0-60.0 sec   631 MBytes  88.2 Mbits/sec   0.005 ms    0/451027 (0%)
    [  3]  0.0-60.0 sec  1 datagrams received out-of-order
    root@am57xx-evm:~# uname -a
    Linux am57xx-evm 4.9.41-rt23-gc038d21a22 #2 SMP PREEMPT RT Wed Sep 27 06:34:09 EDT 2017 armv7l GNU/Linux

.. rubric:: Useful Commands
   :name: useful-commands

For Non offload case following commands are available. To dump stats

-  cat /sys/kernel/debug/hsr/stats

To dump Node\_Table

-  cat /sys/kernel/debug/hsr/node\_table

For PRP, replace hsr in the above paths with prp

For Offloaded case following commands are available to change mode To
change HSR mode do both commands below.

-  echo 1 > /sys/kernel/debug/hsr/hsr\_mode
-  echo 1 > /sys/kernel/debug/prueth-prp/hsr\_mode

To see the node table entries for offloaded case, do

-  cat /sys/kernel/debug/prueth-prp/new\_nt\_bins

or

-  cat /sys/kernel/debug/prueth-hsr/new\_nt\_bins

where 1 is for Mode-H

Other values are 2 (Mode-N), 3 (Mode-T), 4 (Mode-U), 5 (Mode-M)

.. rubric:: FAQ
   :name: faq

#. How to disable udhcpc from sending DHCP request over prueth Ethernet
   interfaces (eth2-eth3) when it is configured to run HSR/PRP protocol
   in firmware?

Linux HSR/PRP driver uses the eth2/eth3 interface as slave interfaces to
implement the protocol on top of it. Application is expected to send or
receive packets over the hsr or prp lre interface also known as C port.
However prueth also support plain Ethernet and the file system
/etc/systemd/network/10-eth.network has a general rule to enable DHCP
over all of the interface matching eth\*. Modify the file to match
unique name instead of generic name wild cards. For example to do DHCP
over only eth0 interface, 10-eth.network may be modified as follows:-

root@am57xx-evm:~# cat /etc/systemd/network/10-eth.network

::

    [Match]
    Name=eth0
    KernelCommandLine=!root=/dev/nfs

    [Network]
    DHCP=yes

To do DHCP over hsr0 or prp0 interfaces, user may add additional files
to /etc/systemd/network/ one for each prp0 or hsr0 similar to eth0, by
using a Match name string of hsr0 or prp0. More details on this is at
[`[6] <https://wiki.archlinux.org/index.php/systemd-networkd#Configuration_files>`__]

.. raw:: html

