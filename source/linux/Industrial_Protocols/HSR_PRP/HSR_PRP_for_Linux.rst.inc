Overview
---------

In both HSR and PRP protocols, the DAN (Dual Attached Node) sends an
identical frame to both the interfaces and uses a sequence number in the
tag to allow drop duplicates at the Rx node to achieve redundancy. This
section describes the different software components of a Linux based
HSR/PRP solution to support redundancy.

Features supported
------------------

-  **HSR/PRP**

   -  100 Mbits/s Full Duplex Ethernet Interface
   -  The implementation is as per IEC 62439-3 Ed 2.0
   -  Operates as a DAN (Dual Attached Node)

-  **HSR**

   -  Operates as a DANH
   -  As per clause 5 of the standard
   -  Support for modes – H, T, U and N as per standard
   -  Modes can be changed at run time
   -  Cut-through switching

-  **PRP**

   -  Operates as a DANP
   -  As per clause 6 of the standard
   -  Two ports as per standard, Port A and Port B

-  **Support for Node Table**

   -  Total 128 entries on AMICx, AM335x, AM437x
   -  Total 256 entries on AM57xx & K2G
   -  Hash Table for faster lookup
   -  Node Table statistics

-  **Support for Multicast Filtering**

   -  Supported on all SoCs
   -  Hash Table of 256 entries for faster lookup
   -  O(1) complexity
   -  User configurable mask to select bits for hashing

-  **Support for VLAN over HSR/PRP interface**

-  **Support for VLAN Filtering**

   -  VLAN filter table of 4096 entries for perfect match
   -  O(1) complexity

-  **Duplicate Discard Table**

   -  Duplicate discard on Port to Host path (HSR and PRP)
   -  Duplicate discard table on Port to Port path (HSR)
   -  Data integrity (CRC) check during port to port forwarding, except cut through (HSR)

-  **QoS scheme** : 3-bit VLAN PCP

   -  No of levels supported : 2
   -  Number of host queues : 2 \| 2 QoS levels per host queue
   -  Number of port queues : 2 \| 2 QoS levels per port queue

-  **Statistics**

   -  Supports all MIB statistics as per standard
   -  Node Table statistics for debugging

-  **Storm Prevention** : Yes. Configurable per port

-  **Dual instance of HSR/PRP using two PRU-ICSS on AM571x**

-  **VLAN tag support in Supervision frames**

-  **Run time change of Protocol at PRU-ICSS without reboot**

Software Architecture
----------------------

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

HSR/PRP Driver source code and Kconfig option
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The driver source code is located under net/hsr-prp folder of the Linux
source tree. To build kernel with this driver, set Kconfig option
CONFIG\_HSR\_PRP=y in the dotconfig or enable it from the menu.

Linux HSR/PRP Driver
^^^^^^^^^^^^^^^^^^^^^^^^

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

.. _PLSDK_HSR_PRP_id_if_number_mapping:

PRU-ICSS Subsystem Driver
^^^^^^^^^^^^^^^^^^^^^^^^^

PRU-ICSS Subsystem Driver provide a set of functions to client driver
such as PRU Ethernet (described in next section) to load and run firmware
on a specific core, such as PRU on a PRU-ICSS. On a SoC, there can be 1 or
2 instance of the PRU-ICSS and client driver might want to know which
instance it is referring to. For example, PRU Ethernet driver calls
pruss_get() to get the instance ID. Also PRU-ICSS and PRU Ethernet
driver support sysfs and debugfs files specific to an instance and user
might have to know what instance the file refers to. Following mapping is
used for the ID based on the SoC and the PRU-ICSS instance.

+---------------------------+------+-----------+--------------------+
| SoC                       | ID   | if number | ICSS TRM reference |
+===========================+======+===========+====================+
| AM3                       |  0   | eth0/1    | PRU-ICSS           |
+---------------------------+------+-----------+--------------------+
| AM4                       |  0   | eth1/2    | PRU-ICSS0          |
+---------------------------+------+-----------+--------------------+
| AM571                     |  1   | eth2/3    | PRU-ICSS1          |
+---------------------------+------+-----------+--------------------+
| AM571                     |  2   | eth4/5    | PRU-ICSS2          |
+---------------------------+------+-----------+--------------------+
| AM572/4                   |  2   | eth2/3    | PRU-ICSS2          |
+---------------------------+------+-----------+--------------------+
| K2G                       |  0   | eth1/2    | PRU-ICSS0          |
+---------------------------+------+-----------+--------------------+
| K2G                       |  1   | eth3/4    | PRU-ICSS1          |
+---------------------------+------+-----------+--------------------+

In the following section, the PRU-ICSS ID is used in the debugfs or
sysfs file path and the same can be obtained from the table above to
know which PRU-ICSS the file refers to.

You can also check which PRU-ICSS an ethernet interface belongs to via command
line, e.g. eth2 on different platforms:

AM571x:
::

 root@am57xx-evm:~# ls -l /sys/class/net/eth2 | grep device
 lrwxrwxrwx    1 root     root             0 Jun 10 11:29 device -> ../../../pruss1_eth

AM572x:
::

 root@am57xx-evm:~# ls -l /sys/class/net/eth2 | grep device
 lrwxrwxrwx    1 root     root             0 Jun 10 11:29 device -> ../../../pruss2_eth

PRU Ethernet Driver (EMAC/HSR/PRP)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

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

.. note:: For all discussion and examples shown, AM57xx device is used as
	   example, but different devices will use different ports. Please
	   see :ref:`PLSDK_HSR_PRP_id_if_number_mapping` for interface
	   number and PRU-ICSS ID information for different SoCs.

As of Processor SDK 5.1.x, the driver supports 2 instances of HSR/PRP
one on each of PRU-ICSS on AM5xxx as per table below.

 +------------+-----------+
 | PRU-ICSS1  | PRU-ICSS2 |
 +============+===========+
 | HSR        |    HSR    |
 +------------+-----------+
 | HSR        |    PRP    |
 +------------+-----------+
 | PRP        |    PRP    |
 +------------+-----------+
 | PRP        |    HSR    |
 +------------+-----------+

Queue Usage and VLAN PCP to Queue Map
""""""""""""""""""""""""""""""""""""""

At the Ingress, there are two queues available for queueing the frames
coming from each port or PRU to Host and two queues available for packets
from Host to each PRU. At the Egress, there are additionally two more
queues used for forward traffic from PRU1 to PRU0 and vice-versa. PRUETH
driver configures the PCP to Queue MAP in Shared RAM which is used by firmware
to decide which queue to pick to enqueue frames towards Host or other
PRU. Priority queues are assigned based on the PCP value in VLAN tag
of an Ethernet frame. Untagged frame is treated like PCP 0. Here is
the mapping value configured by driver in 4 bytes starting at offset
QUEUE_2_PCP_MAP_OFFSET (defined in hsr_prp_firmware.h). Same mapping is
used for Ingress and Egress traffic.

The convention is that higher queue value corresponds to lower priority

**For HSR/PRP Ethernet types**

- At ingress to Host

::

 byte 0 - To host from PRU 1, PCP 0-3 => Q3
 byte 1 - To host from PRU 1, PCP 4-7 => Q2
 byte 2 - To host from PRU 0, PCP 0-3 => Q1
 byte 3 - To host from PRU 0, PCP 4-7 => Q0

At the ingress, firmware inspect the PCP value in the incoming Ethernet
frame's VLAN tag and choose a priority queue to enqueue the frame based on
the above mapping.

- At egress from host to wire/network

::

 PRU0/PRU1
 ---------
 byte 0 - from Host to PRU, PCP 0-3 => Q3
 byte 1 - from Host to PRU, PCP 4-7 => Q2

 PRU0
 -----
 byte 2 - from PRU1 to PRU0, PCP 0-3 => Q1
 byte 3 - from PRU1 to PRU0, PCP 4-7 => Q0

 PRU1
 -----
 byte 2 - from PRU0 to PRU1, PCP 0-3 => Q1
 byte 3 - from PRU0 to PRU1, PCP 4-7 => Q0

Driver choose the priority queue for egress transmission based on the
PCP value of the Ethernet frame received from the upper layer.  Firmware
sends the frames first from Q0 and Q2 in a round robin fashion. Once these
queues are drained, it then sends from the next higher queues Q1 and Q3
again in a round robin fashion. At the egress, Q0/Q1 are port queues and
Q2/Q3 are host queues.

**For Dual EMAC Ethernet type**

In Dual EMAC case, mapping is hard coded in firmware.

- At ingress to Host

::

 From PRU0 to Host, PCP 0-3 => Q1
 From PRU0 to Host, PCP 4-7 => Q0

 From PRU1 to Host, PCP 0-3 => Q3
 From PRU1 to Host, PCP 4-7 => Q2

- At egress from host to wire/network

::

 PRU0/PRU1
 -- ---------
 From Host to PRU0/PRU1, PCP 0-1 => Q3
 From Host to PRU0/PRU1, PCP 2-3 => Q2
 From Host to PRU0/PRU1, PCP 4-5 => Q1
 From Host to PRU0/PRU1, PCP 6-7 => Q0

Firmware sends the frames first from Q1, and then from the next higher
queue (Q2) and so forth.

For all ethernet types, at the Ingress, two separate irq handlers are
assigned to each port to process the packets. Driver handler first process
packets from the high priority queue followed by packets from the lower
priority queue.

Changing protocol at PRU Ethernet
"""""""""""""""""""""""""""""""""""

PRU Ethernet driver supports multiple protocols based on the firmware
loaded on ICSS PRU. In Processor SDK 04.00.00, a capability was added to
change the protocol running on the PRU at boot time through bootargs.
This is described at :ref:`PLSDK_HSR_PRP_Testing_Firmware_Offload`.
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

.. _PLSDK_PRP_EMAC_Mode-label:

PRP EMAC mode
""""""""""""""

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
   described at :ref:`PLSDK_HSR_PRP_Testing_Firmware_Offload`
-  Once the EVM boots up and user login, first thing to verify is if
   PRUETH is configured as PRP Ethernet type. See above section for
   details
-  Configure PRP EMAC mode in the PRP firmware by issuing the following
   command at the console

::

  echo 1 > /sys/devices/platform/pruss<ID>_eth/net/eth<if number>/prp_emac_mode

where <ID> and <if number> are described in section :ref:`PLSDK_HSR_PRP_id_if_number_mapping`

-  Now bring up Ethernet interfaces as usual and the device is ready to
   be used as SAN. PTP support can be enabled at this time. See section
   on
   [`[1] <http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_HSR_PRP#Linux_PTP>`__]
   for the details.

**NOTE: run time protocol switch is not supported for switch to SAN PTP
for now and required boot time configuration and above debugfs command
once device is boot up in PRP mode**

Multicast filtering
--------------------

Multicast filtering is an Ethernet frame filtering feature in PRU firmware based
on the destination MAC address of the received frame. The PRU provides a
Multicast filter table in Data RAM1 of PRU with a size of 256 entries of 1
byte each. Firmware implements an imperfect match for filtering the frames based
on a hash calculated using the destination MAC address of the frame and a
configurable mask if the destination address is a multicast MAC address.

::

 Hash = (MAC_ADDR[0] AND MASK[0]) XOR
        (MAC_ADDR[1] AND MASK[1]) XOR
        (MAC_ADDR[2] AND MASK[2]) XOR
        (MAC_ADDR[3] AND MASK[3]) XOR
        (MAC_ADDR[4] AND MASK[4]) XOR
        (MAC_ADDR[5] AND MASK[5])

Where MASK is a user configurable value provided at boot time and MAC_ADDR is
the multicast MAC address which is extracted from the destination address
of the Ethernet frame and AND is the bitwise AND operation. In other words,
a bitwise AND operation is performed between each byte of MAC address and
a corresponding MASK byte and the resulting bytes are XOR-ed together to
get the hash value. The hash is used to index into the Multicast filter
table to check if it is set (1) or reset (0). If set, the frame is forwarded
to ARM core (a.k.a Host). If reset, the frame is dropped at the PRU. This
is an imperfect match since there can be multiple MAC addresses that produces
the same hash value. So these frames will get forwarded to the ARM core.

ti_prueth.pruss<ID>_port<PORT>_mc_mask is the module parameter for MASK where <ID> is
described in section :ref:`PLSDK_HSR_PRP_id_if_number_mapping` and <PORT> is
'0' in HSR/PRP case since both ports share the same MASK (port 1 does not need 
to be set and has no effect), and '0' or '1' in Dual
EMAC case since both ports can be configured independently.

Sample bootargs with MASK configured (HSR/PRP)

::

 setenv pruss1_port0_mc_mask "FF:FF:FF:FF:00:00"
 setenv pruss2_port0_mc_mask "FF:FF:FF:FF:00:00"
 setenv args_mmc 'run finduuid;setenv bootargs console=${console} ${optargs} root=PARTUUID=${uuid} rw rootfstype=${mmcrootfstype}  ti_prueth.pruss1_ethtype=${pruss1_ethtype} ti_prueth.pruss2_ethtype=${pruss2_ethtype} ti_prueth.pruss1_port0_mc_mask=${pruss1_port0_mc_mask} ti_prueth.pruss2_port0_mc_mask=${pruss2_port0_mc_mask}'

A comparable sample bootargs with MASK configured for Dual EMAC

::

 setenv pruss1_port0_mc_mask "FF:FF:FF:FF:00:00"
 setenv pruss1_port1_mc_mask "FF:FF:FF:FF:00:00"
 setenv pruss2_port0_mc_mask "FF:FF:FF:FF:00:00"
 setenv pruss2_port1_mc_mask "FF:FF:FF:FF:00:00"
 setenv args_mmc 'run finduuid;setenv bootargs console=${console} ${optargs} root=PARTUUID=${uuid} rw rootfstype=${mmcrootfstype}  ti_prueth.pruss1_ethtype=${pruss1_ethtype} ti_prueth.pruss2_ethtype=${pruss2_ethtype} ti_prueth.pruss1_port0_mc_mask=${pruss1_port0_mc_mask} ti_prueth.pruss1_port1_mc_mask=${pruss1_port1_mc_mask} ti_prueth.pruss2_port0_mc_mask=${pruss2_port0_mc_mask} ti_prueth.pruss2_port1_mc_mask=${pruss2_port1_mc_mask}'

Typically, an application joins the multicast group either using a raw
socket of type SOCK_DGRAM and use setsockopt() API to Join or leave the
multicast group. An interesting article on this is available at

http://www.tenouk.com/Module41c.html

This causes the Multicast MAC address to be added to the mc_list of the
socket and the associated network device in kernel and finally get passed
to the Ethernet device driver (in our case, it is PRU Ethernet device
driver). The relevant API is ndo_set_rx_mode() of the net_device_ops
structure in Linux kernel associated with the network device. The PRU
Ethernet device driver calculates the hash as described above and then
writes 1 to MC filter table using the hash value as index. The PRU Ethernet
device driver also supports allmulti which is used to enable receieve of
all multicast frames at an interface. This is an option passed to the
ifconfig command.

::

 Example
 >ifconfig eth2 192.168.2.20 allmulti

 To remove the option
 >ifconfig eth2 192.168.2.20 -allmulti

 To display the Multicast address list of an interface, say eth2, user types
 >ip maddr show dev eth2

sample display

::

 root@am57xx-evm:~# ip maddr show dev eth2
 6:      eth2
         link  33:33:00:00:00:01 users 2
         link  01:00:5e:00:00:01 users 2
         link  33:33:ff:1c:16:e0 users 2
         link  01:00:5e:00:00:fb
         link  01:00:5e:00:00:fc
         link  33:33:00:01:00:03 users 2
         link  33:33:00:00:00:fb users 2
         inet  224.0.0.1
         inet6 ff02::fb
         inet6 ff02::1:3
         inet6 ff02::1:ff1c:16e0
         inet6 ff02::1
         inet6 ff01::1

PRU Ethernet driver also provides a debugfs file mc_filter to display MC filter
table in the memory

::

 /sys/kernel/debug/prueth-prp-<ID>/mc_filter


or

::

 /sys/kernel/debug/prueth-hsr-<ID>/mc_filter


or (for Dual EMAC)

::

 /sys/kernel/debug/prueth-eth<if number>/mc_filter


where ID/'if number' is described in section :ref:`PLSDK_HSR_PRP_id_if_number_mapping`

Sample display

::

 root@am57xx-evm:~# cat /sys/kernel/debug/prueth-prp-2/mc_filter
 MC Filter : enabled
 MC Mask : ff:ff:ff:ff:0:0
 MC Filter table below 1 - Allowed, 0 - Dropped

   0: 1 1 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  10: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  20: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  30: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  40: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  50: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
  60: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  70: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  80: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  90: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  a0: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  b0: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  c0: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  d0: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0
  e0: 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0
  f0: 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0

Dual EMAC 
^^^^^^^^^^^^^^^^^^

If using Dual EMAC, the only interface differences are the debugfs paths and the
mask parameters, as mentioned above. Internally, the multicast filter table(s)
are stored in each PRU's Data RAM (PRU0->Data RAM0, PRU1->Data RAM1) instead of
one table in Data RAM1 as for HSR/PRP.

VLAN over PRU Ethernet
-----------------------

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
`Queue Usage and VLAN PCP to Queue Map <#queue-usage-and-vlan-pcp-to-queue-map>`__

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

VLAN Filtering
---------------

The PRU has a 4096 entry VLAN filter table that allows filtering out
unwanted VLAN traffic to the host. As soon a VLAN interface is created,
the 802.1q Linux kernel module sends the VID information down to the
lower layer HSR or PRP Linux device which in turn pass it down to the
slave Ethernet devices below it (or directly to the Ethernet device in the
case of Dual EMAC). The PRU Ethernet driver gets the VID
information via net_device_ops:ndo_vlan_rx_add_vid(). On receiving this,
PRU Ethernet driver sets the entry at the VID index in VLAN filter table
to 1. When the VLAN interface is deleted, the driver receives the same
information through ndo_vlan_rx_kill_vid() and reset the entry at the
VID index.

PRU firmware on receiving a VLAN frame, extracts the VID and look up the
VLAN filter table for an entry at the VID if VLAN filtering is enabled
in firmware. If the entry is 1, it forwards the frame to the Host.
Otherwise the frame is dropped. There are additional controls to allow
priority tagged frames to Host if the corrsponding bit is set in firmware
shared memory. PRU Ethernet driver always enables Priority tagged frames
to the Host. User may setup a VLAN interface with VID 0 to send or
receive priority tagged frames. See section `VLAN <#vlan-over-pru-ethernet>`_ for details
on how to assign egress priority mapping for the priority tagged VLAN
interface.

.. rubric:: Useful commands
   :name: Useful-commands

User can use the following command to view the VLAN filter table at PRU.
(Similar commands apply for HSR and Dual EMAC)

::

 cat /sys/kernel/debug/prueth-prp-<ID>/vlan_filter

Where ID is described at :ref:`PLSDK_HSR_PRP_id_if_number_mapping`

::

 root@am57xx-evm:~# cat /sys/kernel/debug/prueth-prp-2/vlan_filter
 VLAN Filter : enabled
 VLAN Filter untagged : allowed to Host
 VLAN Filter priority tagged: allowed to Host

    0: 0011000000000000000000000000000000000000000000000000000000000000
   64: 0000000000000000000000000000000000000000000000000000000000000000
  128: 0000000000000000000000000000000000000000000000000000000000000000
  192: 0000000000000000000000000000000000000000000000000000000000000000
  256: 0000000000000000000000000000000000000000000000000000000000000000
  320: 0000000000000000000000000000000000000000000000000000000000000000
  384: 0000000000000000000000000000000000000000000000000000000000000000
  448: 0000000000000000000000000000000000000000000000000000000000000000
  512: 0000000000000000000000000000000000000000000000000000000000000000
  576: 0000000000000000000000000000000000000000000000000000000000000000
  640: 0000000000000000000000000000000000000000000000000000000000000000
  704: 0000000000000000000000000000000000000000000000000000000000000000
  768: 0000000000000000000000000000000000000000000000000000000000000000
  832: 0000000000000000000000000000000000000000000000000000000000000000
  896: 0000000000000000000000000000000000000000000000000000000000000000
  960: 0000000000000000000000000000000000000000000000000000000000000000
 1024: 0000000000000000000000000000000000000000000000000000000000000000
 1088: 0000000000000000000000000000000000000000000000000000000000000000
 1152: 0000000000000000000000000000000000000000000000000000000000000000
 1216: 0000000000000000000000000000000000000000000000000000000000000000
 1280: 0000000000000000000000000000000000000000000000000000000000000000
 1344: 0000000000000000000000000000000000000000000000000000000000000000
 1408: 0000000000000000000000000000000000000000000000000000000000000000
 1472: 0000000000000000000000000000000000000000000000000000000000000000
 1536: 0000000000000000000000000000000000000000000000000000000000000000
 1600: 0000000000000000000000000000000000000000000000000000000000000000
 1664: 0000000000000000000000000000000000000000000000000000000000000000
 1728: 0000000000000000000000000000000000000000000000000000000000000000
 1792: 0000000000000000000000000000000000000000000000000000000000000000
 1856: 0000000000000000000000000000000000000000000000000000000000000000
 1920: 0000000000000000000000000000000000000000000000000000000000000000
 1984: 0000000000000000000000000000000000000000000000000000000000000000
 2048: 0000000000000000000000000000000000000000000000000000000000000000
 2112: 0000000000000000000000000000000000000000000000000000000000000000
 2176: 0000000000000000000000000000000000000000000000000000000000000000
 2240: 0000000000000000000000000000000000000000000000000000000000000000
 2304: 0000000000000000000000000000000000000000000000000000000000000000
 2368: 0000000000000000000000000000000000000000000000000000000000000000
 2432: 0000000000000000000000000000000000000000000000000000000000000000
 2496: 0000000000000000000000000000000000000000000000000000000000000000
 2560: 0000000000000000000000000000000000000000000000000000000000000000
 2624: 0000000000000000000000000000000000000000000000000000000000000000
 2688: 0000000000000000000000000000000000000000000000000000000000000000
 2752: 0000000000000000000000000000000000000000000000000000000000000000
 2816: 0000000000000000000000000000000000000000000000000000000000000000
 2880: 0000000000000000000000000000000000000000000000000000000000000000
 2944: 0000000000000000000000000000000000000000000000000000000000000000
 3008: 0000000000000000000000000000000000000000000000000000000000000000
 3072: 0000000000000000000000000000000000000000000000000000000000000000
 3136: 0000000000000000000000000000000000000000000000000000000000000000
 3200: 0000000000000000000000000000000000000000000000000000000000000000
 3264: 0000000000000000000000000000000000000000000000000000000000000000
 3328: 0000000000000000000000000000000000000000000000000000000000000000
 3392: 0000000000000000000000000000000000000000000000000000000000000000
 3456: 0000000000000000000000000000000000000000000000000000000000000000
 3520: 0000000000000000000000000000000000000000000000000000000000000000
 3584: 0000000000000000000000000000000000000000000000000000000000000000
 3648: 0000000000000000000000000000000000000000000000000000000000000000
 3712: 0000000000000000000000000000000000000000000000000000000000000000
 3776: 0000000000000000000000000000000000000000000000000000000000000000
 3840: 0000000000000000000000000000000000000000000000000000000000000000
 3904: 0000000000000000000000000000000000000000000000000000000000000000
 3968: 0000000000000000000000000000000000000000000000000000000000000000
 4032: 0000000000000000000000000000000000000000000000000000000000000000

Dual EMAC 
^^^^^^^^^^^^^^^^^^

If using Dual EMAC, the only interface differences are the debugfs paths.

::

 /sys/kernel/debug/prueth-eth<if number>/vlan_filter

Internally, the VLAN filter table(s) are stored in each PRU's Data RAM 
(PRU0->Data RAM0, PRU1->Data RAM1) instead of one table in Shared RAM 
as for HSR/PRP.

.. rubric:: Limitation

Currently, the PRU firmware is configured to receive all of the
untagged frames from the network when the VLAN filtering is enabled.
However there is no support for port VLAN which allows these frames
to be received at a designated VLAN interface.

Broadcast Storm Prevention
--------------------------
Broadcast storm is defined as an excessive amount of Layer 2
broadcast Ethernet frames at the ingress of a network interface
causing resources being wasted in the device for processing
these frames and thereby affecting the device performance.

PRUETH driver implements a control mechanism that user can
enable to drop these frames if the number of frames received
during a window (100 msec) reaches a threshold. PRUETH uses
a credit value as the threshold which is user configurable
on a per interface basis. There is a sysfs entry

::

  /sys/devices/platform/pruss<ID>_eth/net/eth<if number>/nsp_credit

Where ID and if number are obtained from the table under the section
:ref:`PLSDK_HSR_PRP_id_if_number_mapping`. The driver writes the credit value in DRAM
based on the sysfs entry from user. The PRU firmware uses the credit
value as a counter. The driver refreshes the counter every 100 msec.
i.e write the credit value to memory every 100 msec. PRU Firmware
upon receiving a broadcast frame decrements this counter until it
becomes zero.  Firmware forwards the broadcast frames to Host or ARM
until the counter is non zero. PRU Firmware drops the broadcast frames
if the counter is zero. Since driver writes the credit value to DRAM
every 100 msec, the number of broadcast frames sent to host or ARM
during a 100 msec window is limited to the credit value and anything
beyond that is dropped by the firmware. Firmware maintains a statistics
counter, stormPrevCounter, for the number of frames dropped due to
storm prevention control and can be seen using ethtool -S command.

Note that this feature is disabled by default and user needs to
configure it explicitely to enable the feature. A write of non zero
value to the sysfs file enables the feature and zero disables the
feature. The value to be used may be experimented in a particular
network situation and configured by the user. In a typical network,
there will be few of these per 100 msec window such as ARP broadcast,
DHCP broadcast, router advetisement etc. So user may observe the
broadcast traffic in the network using network tools such as wireshark
and set the credit value accordingly.

Example

To enable do

::

 >echo 10 > /sys/devices/platform/pruss2_eth/net/eth2/nsp_credit

for setting credit value to 10 for eth2. Similarly for other interfaces.

To disable do

::

 >echo 0 > /sys/devices/platform/pruss2_eth/net/eth2/nsp_credit

Receive Interrupt Pacing
------------------------

Currently PRUETH driver receives one interrupt per frame from each
port. This results in lesser performance due to interrupt handling
overhead in the Linux kernel especially for small size frames such
as that used in grid infrastructure networks.

A well-known technique used in rx packet processing of a network driver
is to use rx interrupt pacing to accumulate the Ethernet frames at the
hardware or underlying network device’s buffer so as to generate less
number of interrupts per packet to the host. This reduces the overhead
in Linux kernel associated with interrupt handling by distributing the
same over muliple packets, thereby reducing CPU usage. In this case
PRUETH firmware accumulates the frames in the ingress ring buffer
between host and PRU for a configurable period of time and raise an
interrupt on timeout expiry (timeout equals to the configured period)
there by resulting in lesser number of interrupts per frame. PRUETH
firmware implements a Rx Pacing timer and the same gets configured by
the PRUETH driver for HSR/PRP Ethernet types when the network device
is opened and stopped when the device is closed. This timer is
implemented per interface since driver has separate interrupts per
PRU or interface.

The user may show the timer value using the ethtool –c option which
is a standard Linux command to show different coalesce parameters at
the network device. –C option allows user to override the default value
at the device. The driver uses a default timeout value of 123 usec
(Duration of an MTU frame). User is not expected to change this as
there are limited number of buffers in the receive path between Host
and PRU and using a bigger value can result in packet loss. However
ethtool –c option is implemented in the PRUETH driver to show current
setting in the driver and -C to change it if needed. Driver supports
rx-usecs and adaptive-rx parameters from the available list of
parameters and can be changed using –C option. When adaptive-rx is
turned ON, every time a frame is received at the PRU and the buffer
is empty, the PRU firmware raises an interrupt. However if the buffer
is already occupied with some frames and the timer is already running,
it will wait until timer expiry to raise the next interrupt. This would
be useful to improve latency when using interrupts pacing. Currently
this is disabled by default as enabling the same result in a lower
throughput. However user may enable the same through ethtool –C
command if needed.

Example

To show the current value of pacing timer, use

::

 >ethtool –c <Ethernet interface>

To change the current value, use

::

 >ethtool –C <Ethernet interface> <param> <value> <param> <value>

For example for eth2, user type

::

 >ethtool –c eth2

Note that this changes the timer at both PRUs (for HSR/PRP). So the command
may be issued to one of the pair of Ethernet interfaces used for the HSR
or PRP interface.
i.e for ICSS2 (assuming eth2 and eth3), user may use either of the below
command to set the timer

::

 >ethtool –C eth2 rx-usecs 123

or

::

 >ethtool –C eth3 rx-usecs 123

Similarly to enable adaptive-rx, user types

::

 >ethtool –C eth2 adaptive-rx on

or

::

 >ethtool –C eth3 adaptive-rx on

Both parameters may be updated in one go as

::

 >ethtool –C eth2 rx-usecs 123 adaptive-rx on

More details on the command syntax are available by typing man ethtool
on a Linux PC as this is a standard Linux command.


VLAN Tag in Supervision frame
-----------------------------

HSR/PRP protocol standard IEC62439-3 defines that the PRP_Supervision frame
as well as HSR_Supervision frames optionally include a VLAN tag header.
Starting with Processor SDK 5.1.x, VLAN tag is supprted in Linux HSR/PRP
implementation.

In Linux, user use the ip link add command to create an HSR/PRP
interface. ip link command is supported by the iproute2 package which is an open
source software. hsr or prp type is currently a supported link type by ip
link command. To support VLAN tag in SV frames, the command now accepts
3 more parameters from user. They are:-

 * VLAN Identifier (VID) - sv_vid
 * Priority code point (PCP) - sv_pcp
 * Drop eligible indicator  (DEI) or formerly known as Canonical Format Indicator (CFI) - sv_dei

User provides following values in the ip link add command for this purpose.

::

 sv_vid <vid value> sv_pcp <pcp value> sv_dei <dei value>

These are all optional parameters. At least one of the value to be provided
to use vlan. A default value of zero is used if not supplied by the user.

Node Table
----------

HSR/PRP offloaded LRE supports a Node Table (NT) of 256 entries on AM5/K2G
devices and 128 entries on AM3/4 devices. NT entries are maintained in
shared RAM of the PRU ICSS. For HSR, an entry containing the MAC address
of the remote node is inserted to the Node table when a supervison(SV) frame
is received from that node. For PRP, this gets added for any frame received
from the node. Firmware first looks up the address in the NT upon receiving
a SV frame. The look up status is indicated in a bit in the buffer descriptor.
The same is checked by the driver and if the look up status indicates no
success, the MAC entry is inserted to the NT by driver.  For subsequent
frames received from the node, the firmware updates the NT and the insertion
process is skipped in the driver.

The driver also runs an ageing timer to forget the node if there was no
frame received from the remote node for a period of time as specified by
the standard. During the timeout, if the entry is aged, then the same is
deleted from the NT.

In Summary, search/update of an NT entry is done in firmware and insert/
delete of an entry is done by the driver.

The NT entries can be displayed by the user at the console using the proc
file /proc/<if_name>/node-table.

Example: If the interface name is prp0, a sample command is shown below to
display the NT entries.

::

 root@am57xx-evm:~# cat /proc/prp0/node-table
 
 Remote nodes in network: 1
 
 Node[0]:
 MAC ADDR: 70:ff:76:1c:16:ef
 DANP
 Time Last Seen: RxA=0 RxB=0

Net-SNMP
--------

The TI SDK release ships tisdk-rootfs-image-am57xx-evm.tar.xz with
Net-SNMP 5.8 binaries pre-installed and snmpd is started as part of
the user space initialization. TI has developed a Net-SNMP module to
support IEC-62439-3 related MIB access at the DAN using snmp commands
such as snmpwalk, snmpget etc. **NOTE:** IEC-62439-3 MIB is supported
only in the offloaded case. So user is expected to create HSR/PRP
interface with offload. For details on how to setup HSR/PRP interface
with offload, please refer :ref:`PLSDK_HSR_PRP_Testing_Firmware_Offload`

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

Individual MIB variable may be queried or set using snmpset or snmpget commands. Below are some examples:-

snmpset

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

iproute2
--------

iproute2 is enhanced to allow creating a prp interface similar to hsr
interface using two slave interfaces.

Test Procedure
---------------
.. _PLSDK_HSR_PRP_Testing_Firmware_Offload:

Testing HSR/PRP Firmware Offload
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

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

Node Tables (firmware offload)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

In the case of HSR/PRP firmware offload, the Node Table can be displayed
as follows. Note: the locations are different from those when there is
no firmware offload.

To show the **HSR Node Table**, under the kernel prompt on the terminal
connected to the IDK, do

-  root@am57xx-evm:~# cat /sys/kernel/debug/**prueth-hsr-<ID>**/node\_table
-  Sample display

::

     root@am57xx-evm:~# cat /sys/kernel/debug/prueth-hsr-2/node_table
     
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

-  root@am57xx-evm:~# cat /sys/kernel/debug/**prueth-prp-<ID>**/node\_table
-  Sample display

::

     root@am57xx-evm:~# cat /sys/kernel/debug/prueth-prp-2/node_table
     
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

LRE Statistics (firmware offload)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

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

.. _PLSDK_HSR_Testing:

HSR Testing
^^^^^^^^^^^^^^

To test HSR, user would need two AM572x EVMs.

#. Setup HSR Ring network as per diagram below. Connect the PRU2ETH0
   (See the marking on the EVM) Ethernet ports of the two EVMs together
   (corresponds to Linux interface eth2) as shown below. Similarly,
   connect the PRU2ETH1 ports (Linux interface eth3) as well.
#. Configure the bootargs to boot PRU with HSR firmware as described
   above at :ref:`PLSDK_HSR_PRP_Testing_Firmware_Offload`
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

Sample script below can be used to create two instances of HSR/PRP at PRU-ICSS1 and PRU-ICSS2 on AM571x. For other platform
where applicable, this can be customized by changing the slave eth interface names to match with that on the specific
platform. The script also allows configuring the LRE to use VLAN tag for Supervision frames by providing an optional vlan
string in the command line of the script as documented in the script.

**On PRU-ICSS1 of AM571x**
::

 #!/bin/sh
 if [ $# -lt 4 ]
 then
 	echo "setup-pruss1.sh <hsr/prp> <MAC-Address of slave-A>"
 	echo "   <ip address for hsr/prp interface>"
 	echo "	<if_name of hsr/prp interface>  [vlan]" 
 	echo " vlan is optional and if present use vlan tag"
 	echo " in the SV frame. Use values of vid, pcp and"
 	echo " and dei hardcoded in the script"
 	exit
 fi

 if [ "$1" != "hsr" ] && [ "$1" != "prp" ]
 then
 	echo "use hsr or prp as first argument"
 	exit
 fi

 if_a=eth2
 if_b=eth3
 if_name=$4
 vl=$5
 #change this as needed
 vid=10
 pcp=5
 dei=0

 ifconfig $if_a down
 ifconfig $if_b down
 ifconfig $if_a hw ether $2
 ifconfig $if_b hw ether $2
 ifconfig $if_a up
 ifconfig $if_b up

 echo "Setting up $if_name with MAC address $2 for slaves and IP address $3"
 echo "          using $if_a and $if_b"

 if [ "$1" = "hsr" ]; then
  	if [ "$vl" = "vlan" ]; then
 	options="version 1 sv_vid $vid sv_pcp $pcp sv_dei $dei"
  		echo $options
 	else
		options="version 1"
 	fi
 else
 	if [ "$vl" = "vlan" ]; then
 		options="sv_vid $vid sv_pcp $pcp sv_dei $dei"
 	else
 		options=""
 	fi
 fi

 ip link add name $if_name type $1 slave1 $if_a slave2 $if_b supervision 0 $options
 ifconfig $if_name $3 up


**On PRU-ICSS2 of AM571x**

::

 #!/bin/sh
 if [ $# -lt 4 ]
 then
 	echo "setup-pruss2.sh <hsr/prp> <MAC-Address of slave-A>"
 	echo "   <ip address for hsr/prp interface>"
 	echo "	<if_name of hsr/prp interface>  [vlan]" 
 	echo " vlan is optional and if present use vlan tag"
 	echo " in the SV frame. Use values of vid, pcp and"
 	echo " and dei hardcoded in the script"
 	exit
 fi
 
 if [ "$1" != "hsr" ] && [ "$1" != "prp" ]
 then
 	echo "use hsr or prp as first argument"
 	exit
 fi
 
 if_a=eth4
 if_b=eth5
 if_name=$4
 vl=$5
 #change this as needed
 vid=10
 pcp=5
 dei=0
 
 ifconfig $if_a down
 ifconfig $if_b down
 ifconfig $if_a hw ether $2
 ifconfig $if_b hw ether $2
 ifconfig $if_a up
 ifconfig $if_b up
 
 echo "Setting up $if_name with MAC address $2 for slaves and IP address $3"
 echo "          using $if_a and $if_b"
 
 if [ "$1" = "hsr" ]; then
 	if [ "$vl" = "vlan" ]; then
 		options="version 1 sv_vid $vid sv_pcp $pcp sv_dei $dei"
 		echo $options
 	else
  		options="version 1"
 	fi
 else
 	if [ "$vl" = "vlan" ]; then
 		options="sv_vid $vid sv_pcp $pcp sv_dei $dei"
 	else
 		options=""
 	fi
 fi
 
 ip link add name $if_name type $1 slave1 $if_a slave2 $if_b supervision 0 $options
 ifconfig $if_name $3 up
 
Sample logs are shown below:

**DAN-H-1**

::

    root@am57xx-evm:~# ifconfig eth2
    eth2      Link encap:Ethernet  HWaddr 70:FF:76:1C:0F:8D  [   38.944687] random: nonblocking pool is initialized
              BROADCAST MULTICAST  MTU:1500  Metric:1
              RX packets:0 errors:0 dropped:0 overruns:0 frame:0
              TX packets:0 errors:0 dropped:0 overruns:0 carrier:0
              collisions:0 txqueuelen:1000
               RX bytes:0 (0.0 B)  TX bytes:0 (0.0 B)

    root@am57xx-evm:~# /setup.sh hsr 70:FF:76:1C:0F:8D 192.168.2.20
    Setting up hsr0 interface with MAC address 70:FF:76:1C:0F:8D for slaves and IP address 192.168.2.20
    [   62.319328]  remoteproc6: powering up 4b2b4000.pru0
    [   62.325015]  remoteproc6: Booting fw image ti-pruss/am57xx-pru0-prueth-fw.elf, size 4350
    [   62.335303] ti-pruss 4b280000.pruss: configured system_events = 0x0000060000500000 intr_channels = 0x00000095 host_intr = 0x00000115
    [   62.348724]  remoteproc6: remote processor 4b2b4000.pru0 is now up
    [   62.354947] net eth2: started
    [   62.360842] IPv6: ADDRCONF(NETDEV_UP): eth2: link is not ready
    [   62.408479]  remoteproc7: powering up 4b2b8000.pru1
    [   62.413790]  remoteproc7: Booting fw image ti-pruss/am57xx-pru1-prueth-fw.elf, size 4382
    [   62.422088] ti-pruss 4b280000.pruss: configured system_events = 0x0060000000a00000 intr_channels = 0x0000012a host_intr = 0x0000022a
    [   62.434059]  remoteproc7: remote processor 4b2b8000.pru1 is now up
    [   62.440281] net eth3: started
    [   62.444625] IPv6: ADDRCONF(NETDEV_UP): eth3: link is not ready
    [   62.509276] device eth2 entered promiscuous mode
    [   62.549502] device eth3 entered promiscuous mode
    [   62.593878] hsr0: Slave A (eth2) is not up; please bring it up to get a fully working HSR network
    [   62.604214] IPv6: ADDRCONF(NETDEV_UP): hsr0: link is not ready
    [   62.614722] IPv6: ADDRCONF(NETDEV_CHANGE): hsr0: link becomes ready
    root@am57xx-evm:~#
    root@am57xx-evm:~# [   63.648569] eth2: Link is Up - 100Mbps/Full - flow control off
    [   63.654446] IPv6: ADDRCONF(NETDEV_CHANGE): eth2: link becomes ready
    [   63.748602] eth3: Link is Up - 100Mbps/Full - flow control off
    [   63.754477] IPv6: ADDRCONF(NETDEV_CHANGE): eth3: link becomes ready

    =========Setup hsr0 on DAN-H-2=============================================

    root@am57xx-evm:~# ping 192.168.2.30
    PING 192.168.2.30 (192.168.2.30): 56 data bytes
    64 bytes from 192.168.2.30: seq=0 ttl=64 time=0.400 ms
    64 bytes from 192.168.2.30: seq=1 ttl=64 time=0.190 ms
    64 bytes from 192.168.2.30: seq=2 ttl=64 time=0.200 ms

    --- 192.168.2.30 ping statistics ---
    3 packets transmitted, 3 packets received, 0% packet loss
    round-trip min/avg/max = 0.190/0.263/0.400 ms
    root@am57xx-evm:~#
    root@am57xx-evm:~# iperf -s
    ------------------------------------------------------------
    Server listening on TCP port 5001
    TCP window size: 85.3 KByte (default)
    ------------------------------------------------------------
    [  4] local 192.168.2.20 port 5001 connected with 192.168.2.30 port 33546
    [ ID] Interval       Transfer     Bandwidth
    [  4]  0.0-10.0 sec   108 MBytes  90.7 Mbits/sec
    root@am57xx-evm:~# iperf -s -u
    ------------------------------------------------------------
    Server listening on UDP port 5001
    Receiving 1470 byte datagrams
    UDP buffer size:  160 KByte (default)
    ------------------------------------------------------------
    [  3] local 192.168.2.20 port 5001 connected with 192.168.2.30 port 47913
    [ ID] Interval       Transfer     Bandwidth        Jitter   Lost/Total Datagrams
    [  3]  0.0-10.0 sec   106 MBytes  89.0 Mbits/sec   0.078 ms  587/76246 (0.77%)
    [  3]  0.0-10.0 sec  1 datagrams received out-of-order
    root@am57xx-evm:~#
    root@am57xx-evm:~# cat /proc/hsr0/node-table 
    
    Remote nodes in network: 1
    
    Node[0]:
    MAC ADDR: d6:ab:09:0d:f0:e5
    DANH
    Time Last Seen: RxA=0 RxB=0

    root@am57xx-evm:~# cat /proc/hsr0/lre-stats  
    LRE statistics:
    Rx Offloaded: 1
        lreTxA: 15915369
        lreTxB: 15915369
        lreTxC: 673
        lreErrWrongLanA: 207816
        lreErrWrongLanB: 207789
        lreErrWrongLanC: 0
        lreRxA: 0
        lreRxB: 27
        lreRxC: 15707590
        lreErrorsA: 0
        lreErrorsB: 0
        lreErrorsC: 0
        lreNodes: 1
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


**DAN-H-2**

::

    root@am57xx-evm:~# ifconfig eth2
    eth2      Link encap:Ethernet  HWaddr D6:AB:09:0D:F0:E5
              BROADCAST MULTICAST  MTU:1500  Metric:1
              RX packets:0 errors:0 dropped:0 overruns:0 frame:0
              TX packets:0 errors:0 dropped:0 overruns:0 carrier:0
              collisions:0 txqueuelen:1000
              RX bytes:0 (0.0 B)  TX bytes:0 (0.0 B)

    root@am57xx-evm:~# /setup.sh hsr D6:AB:09:0D:F0:E5 192.168.2.30
    Setting up hsr0 interface with MAC address D6:AB:09:0D:F0:E5 for slaves and IP address
    192.168.2.30
    [   66.015629]  remoteproc6: powering up 4b2b4000.pru0
    [   66.021263]  remoteproc6: Booting fw image ti-pruss/am57xx-pru0-prueth-fw.elf, size 4350
    [   66.031502] ti-pruss 4b280000.pruss: configured system_events = 0x0000060000500000
    intr_channels = 0x00000095 host_intr = 0x00000115
    [   66.044965]  remoteproc6: remote processor 4b2b4000.pru0 is now up
    [   66.052043] net eth2: started
    [   66.055419] IPv6: ADDRCONF(NETDEV_UP): eth2: link is not ready
    [   66.108268]  remoteproc7: powering up 4b2b8000.pru1
    [   66.113562]  remoteproc7: Booting fw image ti-pruss/am57xx-pru1-prueth-fw.elf, size 4382
    [   66.123585] ti-pruss 4b280000.pruss: configured system_events = 0x0060000000a00000
    intr_channels = 0x0000012a host_intr = 0x0000022a
    [   66.136973]  remoteproc7: remote processor 4b2b8000.pru1 is now up
    [   66.143998] net eth3: started
    [   66.147284] IPv6: ADDRCONF(NETDEV_UP): eth3: link is not ready
    [   66.218855] device eth2 entered promiscuous mode
    [   66.258015] device eth3 entered promiscuous mode
    [   66.303911] hsr0: Slave A (eth2) is not up; please bring it up to get a fully working HSR
    network
    [   66.313621] IPv6: ADDRCONF(NETDEV_UP): hsr0: link is not ready
    [   66.323162] IPv6: ADDRCONF(NETDEV_CHANGE): hsr0: link becomes ready
    root@am57xx-evm:~# [   67.358460] eth2: Link is Up - 100Mbps/Full - flow control off
    [   67.364336] IPv6: ADDRCONF(NETDEV_CHANGE): eth2: link becomes ready
    [   67.518489] eth3: Link is Up - 100Mbps/Full - flow control off
    [   67.524363] IPv6: ADDRCONF(NETDEV_CHANGE): eth3: link becomes ready

    root@am57xx-evm:~# iperf -c 192.168.2.20
    ------------------------------------------------------------
    Client connecting to 192.168.2.20, TCP port 5001
    TCP window size: 70.0 KByte (default)
    ------------------------------------------------------------
    [  3] local 192.168.2.30 port 33546 connected with 192.168.2.20 port 5001
    [ ID] Interval       Transfer     Bandwidth
    [  3]  0.0-10.0 sec   108 MBytes  90.9 Mbits/sec
    root@am57xx-evm:~# iperf -c 192.168.2.20 -u -b 90M
    ------------------------------------------------------------
    Client connecting to 192.168.2.20, UDP port 5001
    Sending 1470 byte datagrams
    UDP buffer size:  160 KByte (default)
    ------------------------------------------------------------
    [  3] local 192.168.2.30 port 47913 connected with 192.168.2.20 port 5001
    [ ID] Interval       Transfer     Bandwidth
    [  3]  0.0-10.0 sec   107 MBytes  89.7 Mbits/sec
    [  3] Sent 76247 datagrams
    [  3] Server Report:
    [  3]  0.0-10.0 sec   106 MBytes  89.0 Mbits/sec   0.078 ms  587/76246 (0.77%)
    [  3]  0.0-10.0 sec  1 datagrams received out-of-order

    root@am57xx-evm:~# cat /proc/hsr0/node-table 
    
    Remote nodes in network: 1
    
    Node[0]:
    MAC ADDR: 70:ff:76:1c:0f:8d
    DANH
    Time Last Seen: RxA=0 RxB=0

    root@am57xx-evm:/# cat /proc/prp0/lre-stats  
    LRE statistics:
    Rx Offloaded: 1

        lreTxA: 208128
        lreTxB: 208128
        lreTxC: 31305063
        lreErrWrongLanA: 0
        lreErrWrongLanB: 0
        lreErrWrongLanC: 0
        lreRxA: 0
        lreRxB: 0
        lreRxC: 208
        lreErrorsA: 0
        lreErrorsB: 0
        lreErrorsC: 0
        lreNodes: 1
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


.. _PLSDK_PTP_Testing:

PRP Testing
^^^^^^^^^^^^^^

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
   discussed at :ref:`PLSDK_HSR_PRP_Testing_Firmware_Offload`
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

Sample logs are shown below:

**DAN-P-1**

::

    root@am57xx-evm:~# ifconfig eth2
    eth2      Link encap:Ethernet  HWaddr 70:FF:76:1C:0F:8D
              inet6 addr: fe80::72ff:76ff:fe1c:f8d%3068183320/64 Scope:Link
              UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
              RX packets:80429 errors:0 dropped:0 overruns:0 frame:593
              TX packets:40905 errors:0 dropped:0 overruns:0 carrier:0
              collisions:0 txqueuelen:1000
              RX bytes:121704175 (116.0 MiB)  TX bytes:2716445 (2.5 MiB)

    root@am57xx-evm:~# /setup.sh prp 70:FF:76:1C:0F:8D 192.168.2.20
    Setting up prp0 interface with MAC address 70:FF:76:1C:0F:8D for slaves and IP address
    192.168.2.20
    [21649.978346] ti-pruss 4b280000.pruss: unconfigured system_events = 0x0000060000500000
    host_intr = 0x00000115
    [21649.988138]  remoteproc6: stopped remote processor 4b2b4000.pru0
    [21649.994196] net eth2: stopped
    [21650.048408] ti-pruss 4b280000.pruss: unconfigured system_events = 0x0060000000a00000
    host_intr = 0x0000022a
    [21650.058199]  remoteproc7: stopped remote processor 4b2b8000.pru1
    [21650.064258] net eth3: stopped
    [21650.084733]  remoteproc6: powering up 4b2b4000.pru0
    [21650.090419]  remoteproc6: Booting fw image ti-pruss/am57xx-pru0-prueth-fw.elf, size 4350
    [21650.098711] ti-pruss 4b280000.pruss: configured system_events = 0x0000060000500000
    intr_channels = 0x00000095 host_intr = 0x00000115
    [21650.110746]  remoteproc6: remote processor 4b2b4000.pru0 is now up
    [21650.117709] net eth2: started
    [21650.121113] IPv6: ADDRCONF(NETDEV_UP): eth2: link is not ready
    [21650.131268]  remoteproc7: powering up 4b2b8000.pru1
    [21650.136538]  remoteproc7: Booting fw image ti-pruss/am57xx-pru1-prueth-fw.elf, size 4382
    [21650.144871] ti-pruss 4b280000.pruss: configured system_events = 0x0060000000a00000
    intr_channels = 0x0000012a host_intr = 0x0000022a
    [21650.156838]  remoteproc7: remote processor 4b2b8000.pru1 is now up
    [21650.163795] net eth3: started
    [21650.167169] IPv6: ADDRCONF(NETDEV_UP): eth3: link is not ready
    [21650.188520] IPv6: ADDRCONF(NETDEV_CHANGE): eth2: link becomes ready
    [21650.248510] device eth2 entered promiscuous mode
    [21650.287995] device eth3 entered promiscuous mode
    [21650.328127] IPv6: ADDRCONF(NETDEV_CHANGE): eth3: link becomes ready

    root@am57xx-evm:~# ping 192.168.2.30
    PING 192.168.2.30 (192.168.2.30): 56 data bytes
    64 bytes from 192.168.2.30: seq=0 ttl=64 time=0.401 ms
    64 bytes from 192.168.2.30: seq=1 ttl=64 time=0.189 ms
    64 bytes from 192.168.2.30: seq=2 ttl=64 time=0.186 ms
    ^C
    --- 192.168.2.30 ping statistics ---
    3 packets transmitted, 3 packets received, 0% packet loss
    round-trip min/avg/max = 0.186/0.258/0.401 ms
    root@am57xx-evm:~#
    root@am57xx-evm:~#
    root@am57xx-evm:~#
    root@am57xx-evm:~# iperf -s
    ------------------------------------------------------------
    Server listening on TCP port 5001
    TCP window size: 85.3 KByte (default)
    ------------------------------------------------------------
    [  4] local 192.168.2.20 port 5001 connected with 192.168.2.30 port 38900
    [ ID] Interval       Transfer     Bandwidth
    [  4]  0.0-10.0 sec   109 MBytes  91.5 Mbits/sec
    ^Croot@am57xx-evm:~# iperf -s  -u
    ------------------------------------------------------------
    Server listening on UDP port 5001
    Receiving 1470 byte datagrams
    UDP buffer size:  160 KByte (default)
    ------------------------------------------------------------
    [  3] local 192.168.2.20 port 5001 connected with 192.168.2.30 port 43497
    [ ID] Interval       Transfer     Bandwidth        Jitter   Lost/Total Datagrams
    [  3]  0.0-10.0 sec   106 MBytes  88.8 Mbits/sec   0.070 ms  0/76109 (0.0%)
    [  3]  0.0-10.0 sec  1 datagrams received out-of-order
    ^Croot@am57xx-evm:~#
    root@am57xx-evm:~#
    root@am57xx-evm:~#
    root@am57xx-evm:/# cat /proc/prp0/node-table 
   
    Remote nodes in network: 1
   
    Node[0]:
    MAC ADDR: 2a:da:8c:50:1b:86 
    DANP
    Time Last Seen: RxA=0 RxB=0

    root@am57xx-evm:/# cat /proc/prp0/lre-stats  
    LRE statistics:
    Rx Offloaded: 1

        lreTxA: 208128
        lreTxB: 208128
        lreTxC: 31305063
        lreErrWrongLanA: 0
        lreErrWrongLanB: 0
        lreErrWrongLanC: 0
        lreRxA: 0
        lreRxB: 0
        lreRxC: 208
        lreErrorsA: 0
        lreErrorsB: 0
        lreErrorsC: 0
        lreNodes: 1
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

**DAN-P-2**

::

    root@am57xx-evm:~# ifconfig eth2
    eth2      Link encap:Ethernet  HWaddr 2A:DA:8C:50:1B:86
             inet6 addr: fe80::28da:8cff:fe50:1b86%3068203800/64 Scope:Link
             UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
             RX packets:40881 errors:0 dropped:10 overruns:0 frame:64
             TX packets:81022 errors:0 dropped:3528075 overruns:0 carrier:0
             collisions:0 txqueuelen:1000
             RX bytes:2718950 (2.5 MiB)  TX bytes:122601929 (116.9 MiB)

    root@am57xx-evm:~# /setup.sh prp 2A:DA:8C:50:1B:86 192.168.2.30
    Setting up prp0 interface with MAC address 2A:DA:8C:50:1B:86 for slaves and IP address
    192.168.2.30
    [21684.048303] ti-pruss 4b280000.pruss: unconfigured system_events = 0x0000060000500000
    host_intr = 0x00000115
    [21684.058095]  remoteproc6: stopped remote processor 4b2b4000.pru0
    [21684.064152] net eth2: stopped
    [21684.118368] ti-pruss 4b280000.pruss: unconfigured system_events = 0x0060000000a00000
    host_intr = 0x0000022a
    [21684.128160]  remoteproc7: stopped remote processor 4b2b8000.pru1
    [21684.134217] net eth3: stopped
    [21684.158347]  remoteproc6: powering up 4b2b4000.pru0
    [21684.164069]  remoteproc6: Booting fw image ti-pruss/am57xx-pru0-prueth-fw.elf, size 4350
    [21684.172524] ti-pruss 4b280000.pruss: configured system_events = 0x0000060000500000
    intr_channels = 0x00000095 host_intr = 0x00000115
    [21684.184563]  remoteproc6: remote processor 4b2b4000.pru0 is now up
    [21684.191761] net eth2: started
    [21684.195184] IPv6: ADDRCONF(NETDEV_UP): eth2: link is not ready
    [21684.205638]  remoteproc7: powering up 4b2b8000.pru1
    [21684.210960]  remoteproc7: Booting fw image ti-pruss/am57xx-pru1-prueth-fw.elf, size 4382
    [21684.219252] ti-pruss 4b280000.pruss: configured system_events = 0x0060000000a00000
    intr_channels = 0x0000012a host_intr = 0x0000022a
    [21684.231220]  remoteproc7: remote processor 4b2b8000.pru1 is now up
    [21684.238235] net eth3: started
    [21684.241684] IPv6: ADDRCONF(NETDEV_UP): eth3: link is not ready
    [21684.339123] device eth2 entered promiscuous mode
    [21684.377962] device eth3 entered promiscuous mode
    [21684.425802] prp0: Slave A (eth2) is not up; please bring it up to get a fully working HSR
    network
    [21684.436772] IPv6: ADDRCONF(NETDEV_UP): prp0: link is not ready
    [21684.443615] IPv6: ADDRCONF(NETDEV_CHANGE): prp0: link becomes ready
    root@am57xx-evm:~# [21684.488601] IPv6: ADDRCONF(NETDEV_CHANGE): eth2: link becomes ready
    [21684.518615] IPv6: ADDRCONF(NETDEV_CHANGE): eth3: link becomes ready

    root@am57xx-evm:~# iperf -c 192.168.2.20
    ------------------------------------------------------------
    Client connecting to 192.168.2.20, TCP port 5001
    TCP window size: 43.8 KByte (default)
    ------------------------------------------------------------
    [  3] local 192.168.2.30 port 38900 connected with 192.168.2.20 port 5001
    [ ID] Interval       Transfer     Bandwidth
    [  3]  0.0-10.0 sec   109 MBytes  91.5 Mbits/sec
    root@am57xx-evm:~# iperf -c 192.168.2.20 -u -b 88M
    ------------------------------------------------------------
    Client connecting to 192.168.2.20, UDP port 5001
    Sending 1470 byte datagrams
    UDP buffer size:  160 KByte (default)
    ------------------------------------------------------------
    [  3] local 192.168.2.30 port 43497 connected with 192.168.2.20 port 5001
    [ ID] Interval       Transfer     Bandwidth
    [  3]  0.0-10.0 sec   107 MBytes  89.5 Mbits/sec
    [  3] Sent 76110 datagrams
    [  3] Server Report:
    [  3]  0.0-10.0 sec   106 MBytes  88.8 Mbits/sec   0.069 ms  0/76109 (0.0%)
    [  3]  0.0-10.0 sec  1 datagrams received out-of-order
    Remote nodes in network: 1
   
    Node[0]:
    MAC ADDR: 70:ff:76:1c:0f:8d
    DANP
    Time Last Seen: RxA=0 RxB=0

    root@am57xx-evm:/# cat /proc/prp0/lre-stats  
    LRE statistics:
    Rx Offloaded: 1

        lreTxA: 208128
        lreTxB: 208128
        lreTxC: 31305063
        lreErrWrongLanA: 0
        lreErrWrongLanB: 0
        lreErrWrongLanC: 0
        lreRxA: 0
        lreRxB: 0
        lreRxC: 208
        lreErrorsA: 0
        lreErrorsB: 0
        lreErrorsC: 0
        lreNodes: 1
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

|

Performance Test and Logs
-------------------------

Boot up two AM571x/572x EVM to configure PRU Ethernet in HSR or PRP mode
as described at :ref:`PLSDK_HSR_PRP_Testing_Firmware_Offload`
They are connected over eth2 and eth3 as described in
:ref:`PLSDK_HSR_Testing` or :ref:`PLSDK_PTP_Testing`

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
+===============+=========+=========+=========+==========+
|               | AM335x  | AM437x  | AM57xx  |   K2G    |
+---------------+---------+---------+---------+----------+
| 1472          | 30      | 64      | 88      | 30       |
+---------------+---------+---------+---------+----------+
| 1024          | 29      | 52      | 86      | 26       |
+---------------+---------+---------+---------+----------+
| 512           | 18      | 36      | 52      | 16       |
+---------------+---------+---------+---------+----------+
| 256           | 11      | 22      | 25      | 10       |
+---------------+---------+---------+---------+----------+

Table:  UDP Performance for HSR

+---------------+----------------------------------------+
| Packet Size   | Tput with no packet loss (Mbits/sec)   |
+===============+=========+=========+=========+==========+
|               | AM335x  | AM437x  | AM57xx  |   K2G    |
+---------------+---------+---------+---------+----------+
| 1472          | 30      | 64      | 88      | 30       |
+---------------+---------+---------+---------+----------+
| 1024          | 27      | 52      | 88      | 26       |
+---------------+---------+---------+---------+----------+
| 512           | 19      | 34      | 46      | 15       |
+---------------+---------+---------+---------+----------+
| 256           | 11      | 22      | 28      | 9        |
+---------------+---------+---------+---------+----------+

Table:  UDP Performance for PRP

| 

**NOTE-1:**\ Test ran for 1 minute with single direction traffic (Client
to Server). Both ports were individually disconnected and then reconnected
during the test. Reduced the traffic from 88Mbits/sec until there is no out
of order or lost packets in the iperf stats i.e. iperf command client side
::

    iperf3 -c <IP> -u -l1472 -b<Rate>M -t60 -i5

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

Redundancy Test and Logs
------------------------

For HSR and PRP redundancy is implemented using duplicate links and
sending frame over both links and discarding the duplicate at the
receive side. The test requires two DAN-P or DAN-H nodes connected over
eth2 and eth3 Ethernet Links. Boot up the EVM with bootargs set to
configure PRU Ethernet in HSR or PRP mode as described at
`Processor\_SDK\_Linux\_HSR\_PRP#Testing\_HSR.2FPRP\_Firmware\_Offload <Industrial_Protocols_HSR_PRP.html#plsdk-hsr-prp-testing-firmware-offload>`__
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

Useful Commands
---------------

 **Linux HSR/PRP driver help commands**

To dump lre_info such as sv_vid, sv_pcp, sv_dei, protocol etc used at the LRE of
Linux HSR/PRP driver

-  cat /sys/kernel/debug/<hsr/prp-if_name>/lre_info
   example
   cat /sys/kernel/debug/hsr0/lre_info

To dump Node\_Table

-  cat /proc/<hsr/prp-if_name>/node-table

To set hsr-mode
-  echo 1 > /proc/<hsr/prp-if_name>/hsr-mode

where 1 is for Mode-H
Other values are 2 (Mode-N), 3 (Mode-T), 4 (Mode-U), 5 (Mode-M)

To clear node table
-  echo 1 > /proc/<hsr/prp-if_name>/clear-nt

To change duplicate detection mode
-  echo 1 > /proc/<hsr/prp-if_name>/dd-mode

To change duplicate list max resident time
-  echo 1000 > /proc/<hsr/prp-if_name>/dlrmt

To change prp transparent reception mode
-  echo 1 > /proc/<hsr/prp-if_name>/prp-tr

To disable SV frame transmission
-  echo 1 > /proc/<hsr/prp-if_name>/disable-sv_frame

 **PRU Ethernet driver help commands**


To see queue stats

-  cat /sys/kernel/debug/prueth-eth<if_number>/stats

To see lre_config

-  cat /sys/kernel/debug/prueth-<hsr/prp>-<ID>>/lre_config

To dump node table

-  cat /sys/kernel/debug/prueth-<hsr/prp>-<ID>>/node_table

Also

-  cat /sys/kernel/debug/prueth-<hsr/prp-<ID>/new\_nt\_bins

In the above commands ID and if_numbers are chosen as described
in section :ref:`PLSDK_HSR_PRP_id_if_number_mapping`

FAQ
----

*  How to disable udhcpc from sending DHCP request over prueth Ethernet
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

*  Why do I see duplicate frames displayed by ping when I use PRP interface?

In ICSS firmware, PRU-0 is assumed to be for Link-A and PRU-1 for Link-B
of a LRE in the case DANP. So in PRP case, Link-A should be connected
network A and Link-B should be connected to Network B of a PRP network
since net-id has to match as per duplicate detect alogrithm. If this
convention is not followed, duplicate detection logic fails and duplicates
are sent to upper layer causing ping application to complain about duplicates.
So when creating prp interface, make sure ip link command parameter slave 1
use linux interface associated with PRU-0 and slave 2 use interface associated
with PRU-1. Also when making network connection make sure that PRU-0 port is
connected to Network A and PRU-1 port to Network B.
