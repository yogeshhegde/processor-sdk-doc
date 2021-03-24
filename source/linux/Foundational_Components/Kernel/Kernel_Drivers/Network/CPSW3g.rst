.. include:: /replacevars.rst.inc

CPSW3g
------

.. contents:: :local:
    :depth: 3

Introduction
============

The TI |__PART_FAMILY_DEVICE_NAMES__| family of devices have multi port
Gigabit Ethernet Switch subsystem. SoCs may have more than 2 external
port with selectable RGMII and RMII interfaces and an internal
Communications Port Programming Interface (CPPI) port (Host port 0).
Host Port 0 CPPI Packet Streaming Interface interface supports 8 TX
channels and one RX channel DMA channel.

Multi port Gigabit Ethernet Switch subsystem support both independent
MAC mode of operation supporting multiple independent Ethernet
interfaces with complete isolation (no packet switching between external
ports), or can be configured in Switch mode with IEEE 802.1Q HW bridge
in managed or learning mode between each of the individual MAC ports.

The driver follows the standard Linux network interface architecture and
supports the following features:

#. Mulitple indpendent MAC mode
#. Switch mode as per IEEE 802.1Q
#. Cut Through forwarding in Switch mode
#. 10/100/1000 Mbps mode of operation.
#. Auto negotiation.
#. Linux NAPI support
#. VLAN filtering
#. Ethertool
#. CPTS/PTP as per 802.1AS-2011 (TSN)
#. EST/TAS offload as per 802.1Q-2018 (TSN)
#. IET/preemption offload as per 802.1Q-2018 (TSN)


.. note::
 Default mode of operation is multiple indpendent MAC ports.

Supported platforms
"""""""""""""""""""
+-----------+-------------------------------+
| SoC       | Number of external ports      |
+===========+===============================+
| AM64X     | 2 external port (CPSW3g)      |
+-----------+-------------------------------+


Driver Configuration
====================

Default SDK build will have these configurations enabled. In case of
custom builds, please ensure following configs are enabled.

::

 CONFIG_TI_K3_AM65_CPSW_NUSS
 CONFIG_TI_K3_AM65_CPSW_SWITCHDEV
 CONFIG_TI_K3_AM65_CPTS
 CONFIG_TI_DAVINCI_MDIO
 CONFIG_TI_CPSW_ALE
 CONFIG_TI_AM65_CPSW_TAS

.. rubric:: **Module Build**
   :name: k3-module-build

Module build for the cpsw driver is supported. To do this, use option 'm' for above configs, where applicable.

Device tree bindings
====================

The DT bindings description can be found at:

|   `Documentation/devicetree/bindings/net/ti,am654-cpsw-nuss.txt <https://git.ti.com/ti-linux-kernel/ti-linux-kernel/blobs/ti-linux-5.4.y/Documentation/devicetree/bindings/net/ti,am654-cpsw-nuss.txt>`__

|   `Documentation/devicetree/bindings/net/ti,am654-cpts.txt <https://git.ti.com/ti-linux-kernel/ti-linux-kernel/blobs/ti-linux-5.4.y/Documentation/devicetree/bindings/net/ti,am654-cpts.txt>`__
|

Multi MAC mode
==============

.. note::
 This section documents Independent MAC mode of operation with
 CPSW3g.

.. include:: K3-CPSW-common.inc.rst

Multi port Switch mode
======================

.. note::

 This section documents the Switch mode features available with
 CPSW3g

The Switch mode can be enabled by configuring devlink driver parameter
"switch_mode" to 1/true::

        devlink dev param set platform/8000000.ethernet \
        name switch_mode value true cmode runtime

Above setting can be done regardless of the state of Port's netdev
devices - UP/DOWN, but Port's netdev devices have to be in UP state
before joining the bridge. This is to avoid overwriting of bridge
configuration as CPSW switch driver completely reloads its configuration
when first port changes its state to UP.

When all the interfaces have joined the bridge - CPSW switch driver will
enable marking packets with offload_fwd_mark flag.

All configuration is implemented via switchdev API.

Bridge setup
""""""""""""

::

        devlink dev param set platform/8000000.ethernet \
        name switch_mode value true cmode runtime

	ip link add name br0 type bridge
	ip link set dev br0 type bridge ageing_time 1000
	ip link set dev eth0 up
	ip link set dev eth1 up
	ip link set dev eth0 master br0
	ip link set dev eth1 master br0

	[*] bridge vlan add dev br0 vid 1 pvid untagged self

	[*] if vlan_filtering=1, where default_pvid=1

	Note: Steps [*] are mandatory.


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

	bridge vlan add dev eth0 vid 100 pvid untagged master
	bridge vlan add dev sw0p2 vid 100 pvid untagged master
	bridge vlan add dev br0 vid 100 pvid untagged self <---- Add cpu port to VLAN100

 2. tagged::

	bridge vlan add dev eth0 vid 100 master
	bridge vlan add dev sw0p2 vid 100 master
	bridge vlan add dev br0 vid 100 pvid tagged self <---- Add cpu port to VLAN100

Forwarding Data Bases (FDBs)
""""""""""""""""""""""""""""

Forwarding entries for MAC addresses are automatically added on the
appropriate switch port upon detection as default operation as an
unmanaged bridge. For managed bridge operation manually add FDB entries
as required.

Manually adding FDBs::

    bridge fdb add aa:bb:cc:dd:ee:ff dev eth0 master vlan 100
    bridge fdb add aa:bb:cc:dd:ee:fe dev sw0p2 master <---- Add on all VLANs

Multicast Data Bases (MDBs)
"""""""""""""""""""""""""""

Multicast entries are automatically added on the appropriate switch port
upon detection as default operation as an unmanaged bridge. For managed
bridge operation manually add MDB entries as required.

Manually adding MDBs::

  bridge mdb add dev br0 port eth0 grp 239.1.1.1 permanent vid 100
  bridge mdb add dev br0 port eth0 grp 239.1.1.1 permanent <---- Add on all VLANs

Multicast flooding
""""""""""""""""""

CPU port mcast_flooding is always on

Turning flooding on/off on switch ports::

  bridge link set dev eth0 mcast_flood on/off

Enabling Cut Through forwarding
"""""""""""""""""""""""""""""""

.. Caution::

    The Cut Through configuration interface could be changed significantly in the future depending on Linux Kernel mainline development.

Cut Through feature allows forwarding packet from one external port to
another without being stored in Port FIFOs thus reducing overall latency
for packet forwarding.

**Limitations:**

* Feature is only available in switch mode.
* Cut Through forwarding is only supported between external ports and no
  support for Cut Through to host port currently.
* Cut-Thru is not supported with 10/100 half-duplex.
* Cut-Thru is not supported with any form of flow control.
* If Intersperced Express Traffic (IET) is enabled, then Cut Through can
  only be enabled on an express priority queue and not on preemptible
  queues.

.. note::
 Currently per port priority mask is set via debugfs entries. This may
 change in future.

Here is the commands to setup cut-through for priority 0 traffic

::

 ip link set dev eth0 down
 ip link set dev eth1 down

 devlink dev param set platform/8000000.ethernet name switch_mode value

 echo 1 > /sys/kernel/debug/8000000.ethernet/Port1/cut_thru_rx_pri_mask
 echo 1 > /sys/kernel/debug/8000000.ethernet/Port1/cut_thru_tx_pri_mask
 echo 1 > /sys/kernel/debug/8000000.ethernet/Port2/cut_thru_rx_pri_mask
 echo 1 > /sys/kernel/debug/8000000.ethernet/Port2/cut_thru_tx_pri_mask

 ip link add name br0 type bridge
 ip link set dev br0 type bridge ageing_time 1000

 ip link set dev eth0 up
 sleep 1
 ip link set dev eth1 up
 sleep 1

 ip link set dev eth0 master br0
 ip link set dev eth1 master br0
 ip link set dev br0 type bridge stp_state 1
 ip link set dev br0 up

 ip addr add 10.0.0.1/8 dev br0

 bridge vlan add dev br0 vid 1 pvid untagged self

The value being written to cut_thru_rx_pri_mask and cut_thru_tx_pri_mask
represents the priorties queues for which cut through feature needs to
be enabled. Can be configured only when all external ports are down.

With above settings, generate a iperf3 traffic from client on Port1 to
client on Port 2 and observe the ethtool statistics to see cut through
taking effect

::

 root@evm:~# ethtool -S eth1 | grep col
     tx_collision_frames: 1796093
     tx_single_coll_frames: 0
     tx_mult_coll_frames: 3
     tx_excessive_collisions: 0
     tx_late_collisions: 0
  root@evm:~# ethtool -S eth0 | grep col
     tx_collision_frames: 3
     tx_single_coll_frames: 0
     tx_mult_coll_frames: 2002396
     tx_excessive_collisions: 52
     tx_late_collisions: 23

 tx_collision_frames:      Enet_Pn_TxCut Enet Port n Cut Thru with and without delay (full-duplex)
 tx_single_coll_frames:    Enet_pn_TxCut_SAF Enet Port n Tx Store and Forward (full-duplex)
 tx_mult_coll_frames:      Enet_Pn_RxCut_NoDelay Enet Port n Rx Cut Thru with no delay (full-duplex)
 tx_excessive_collisions:  Enet_Pn_RxCut_Delay Enet Port n Rx Cut Thru with delay (full-duplex)
 tx_late_collisions:       Enet_Pn_RxCut_SAF Enet Port n Rx Store and Forward (full-duplex)
