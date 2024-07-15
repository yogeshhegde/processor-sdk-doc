**********************************
PRU_ICSSG Two Port Ethernet Switch
**********************************

PRU_ICSSG can operate as VLAN aware Switch mode with two external physical ports
and one internal host port. By default, interfaces come up in Dual independent
EMAC mode and can be changed to operate in Switch mode at runtime.
Note that changing from Dual EMAC to Switch mode needs loading of
different firmwares to various PRU cores and thus have to follow
specific sequence as shown in below sections:

Enabling Switch mode
""""""""""""""""""""

Example assuming ETH1 and ETH2 as ICSSG0 interfaces:

::

 ip link add name br0 type bridge
 ip link set dev eth1 master br0
 ip link set dev eth2 master br0
 ip link set dev br0 up
 bridge vlan add dev br0 vid 1 pvid untagged self

Going back to Dual EMAC mode
""""""""""""""""""""""""""""

::

 ip link set dev br0 down
 ip link set dev eth1 nomaster
 ip link set dev eth2 nomaster
 ip link del name br0 type bridge

Turn On/Off Spanning Tree Protocol (STP)
""""""""""""""""""""""""""""""""""""""""

::

	ip link set dev br0 type bridge stp_state 1/0

VLAN configuration
""""""""""""""""""

::

  bridge vlan add dev br0 vid 1 pvid untagged self <---- add cpu port to VLAN 1

This step is mandatory for bridge/default_pvid.

Adding extra VLANs
""""""""""""""""""

 1. untagged::

	bridge vlan add dev eth1 vid 100 pvid untagged master
	bridge vlan add dev eth1 vid 100 pvid untagged master
	bridge vlan add dev br0 vid 100 pvid untagged self <---- Add cpu port to VLAN100

 2. tagged::

	bridge vlan add dev eth1 vid 100 master
	bridge vlan add dev eth1 vid 100 master
	bridge vlan add dev br0 vid 100 pvid tagged self <---- Add cpu port to VLAN100

Forwarding Data Bases (FDBs)
""""""""""""""""""""""""""""

Forwarding entries for MAC addresses are automatically added on the
appropriate switch port upon detection as default operation as an
unmanaged bridge. For managed bridge operation manually add FDB entries
as required.

Manually adding FDBs::

    bridge fdb add aa:bb:cc:dd:ee:ff dev eth1 master vlan 100
    bridge fdb add aa:bb:cc:dd:ee:fe dev eth1 master <---- Add on all VLANs

Multicast Data Bases (MDBs)
"""""""""""""""""""""""""""

Multicast entries are automatically added on the appropriate switch port
upon detection as default operation as an unmanaged bridge. For managed
bridge operation manually add MDB entries as required.

Manually adding MDBs::

  bridge mdb add dev br0 port eth1 grp 239.1.1.1 permanent vid 100
  bridge mdb add dev br0 port eth1 grp 239.1.1.1 permanent <---- Add on all VLANs

Multicast flooding
""""""""""""""""""

CPU port mcast_flooding is always on

Turning flooding on/off on switch ports::

  bridge link set dev eth1 mcast_flood on/off

Limitations of switch mode offloading support
"""""""""""""""""""""""""""""""""""""""""""""

* VLAN offloading is limited to 0-256 VIDs.
* MDB/FDB static entries are limited to 511 entries and different FDBs can
  hash to same bucket and thus may not be completely offloaded

Cut Through Forwarding
""""""""""""""""""""""

.. Caution::

    The Cut Through configuration interface could be changed significantly in the future depending on Linux Kernel mainline development.

ICSSG Switch firmware now supports cut through forwarding. Cut Through feature allows forwarding packet from one external port to another without being stored in Port FIFOs thus reducing overall latency for packet forwarding.

**Limitations**

#. Feature is not available in dual EMAC mode.
#. Cut Through forwarding is only supported between external ports and no support for Cut Through to host port currently.
#. Cut Through is not supported with 10/100 half-duplex.
#. Cut Through is not supported with any form of flow control.
#. If Intersperced Express Traffic (IET) is enabled, then Cut Through can only be enabled on an express priority queue and not on preemptible queues.

Assuming eth1 and eth2 are the active ports of ICSSG2 on AM654x-IDK, to enable cut through run below commands,

::

  ip link set eth1 down
  ip link set eth2 down
  devlink dev param set platform/icssg2-eth name cut_thru value 1 cmode runtime # To enable cut thru for tx0 queue
  devlink dev param set platform/icssg2-eth name cut_thru value 2 cmode runtime # To enable cut thru for tx1 queue
  devlink dev param set platform/icssg2-eth name cut_thru value 3 cmode runtime # To enable cut thru for tx0 and tx1 queues
  ip link set eth1 up
  ip link set eth2 up

To enable cut through for multiple (assume q1, q2 and q3) queues. Pass the value 2\ :sup:`q1` + 2\ :sup:`q2` + 2\ :sup:`q3` to the devlink command.

To show the current cut through status, run the below command,
::

  devlink dev param show platform/icssg2-eth name cut_thru

  platform/icssg2-eth:
    name cut_thru type driver-specific
      values:
        cmode runtime value 133

Here the value is shown as 133 (Binary 10000101). This means that cut through is enabled for q0, q2 and q7 queues. As bit 0,1 and 7 are set in the binary representation of the value 133.

To disable cut through on all queues
::
  devlink dev param set platform/icssg2-eth name cut_thru value 0 cmode runtime

SRAM Requirement
""""""""""""""""

* The ICSSG Ethernet driver can be used in switch mode. Two icssg ports are used per switch.
* SRAM Required for each switch (per two ports) is 256 KB.
* For each ICSSG switch, the SRAM required needs to be contiguous.
* PRUETH only uses the required amount of SRAM from the SRAM/MSMC pool. If PRUETH doesn't get the required amount of SRAM, the prueth_probe() API will return with -ENOMEM error.