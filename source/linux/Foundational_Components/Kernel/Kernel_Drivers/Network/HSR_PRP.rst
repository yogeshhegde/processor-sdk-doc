.. include:: /replacevars.rst.inc

=======
HSR PRP
=======

.. rubric:: **Introduction**

High-availability Seamless Redundancy (HSR) and Parellel Redundancy
Protocol (PRP) are protocols supporting redundant network connections defined
by IEC 62439-3. Both operate by using two ethernet ports together, and
duplicating every frame to be sent over both ports, so if one connection
fails, the transmission succeeds. Frames are tagged with a sequence number,
so the receiving node can identify and discard duplicates. HSR/PRP provides
an advantage over other protocols that handle link failure (e.g. STP/RSTP)
because there is no downtime or packet loss on link failure. This is
required in some industrial networking situations.

The major difference between HSR and PRP is that HSR networks are configured
as a ring, then frames are sent both directions around the ring by all nodes.
PRP networks can take any configuration, and all connections are simply
physically duplicated. Additionally, PRP nodes can interoperate with standard
ethernet networks, while HSR cannot. (See more details below and full details
in IEC 62439-3)

.. rubric:: **Linux HSR PRP Support**

Linux supports HSR/PRP protocol to be run over two EMAC ports where Linux
takes care of duplicating the packets sent over the two ethernet ports and
discarding the received duplicate packet. This is the non-offload HSR/PRP
mechanism.

.. rubric:: *Getting Started*

To try out HSR/PRP (assuming two supported platforms are set up already,
and the ethernet ports are eth1/eth2):

1) Connect the Ethernet ports between devices, eth1 to eth1 and eth2 to eth2.
(This acts as a 2 node ring for HSR, or a 2 node point-to-point for PRP)

2) Bring down both the ethernet interfaces

::

  ip link set eth1 down && ip link set eth2 down

3) Configure both ports to have the same MAC address

::

  ip link set dev eth1 address 70:FF:76:1C:0E:8C && ip link set dev eth2 address 70:FF:76:1C:0E:8C

4) Bring up both the ethernet interfaces

::

  ip link set eth1 up && ip link set eth2 up

5) Create HSR or PRP feature

For HSR
::

  ip link add name hsr0 type hsr slave1 eth1 slave2 eth2 supervision 45 version 1

For PRP
::

  ip link add name prp0 type hsr slave1 eth1 slave2 eth2 supervision 45 proto 1

6) Assign an IP address to the HSR/PRP interface

For HSR
::

  ip addr add 192.168.2.20 dev hsr0

For PRP
::

  ip addr add 192.168.2.20 dev prp0

With the above configuration, if a ping is run between the two platforms on the
HSR/PRP interface, the ping will continue even if one of the connections is removed.

For VLAN
::

  ifconfig hsr0 0.0.0.0
  ip link add link hsr0 name hsr0.2 type vlan id 2
  ip link add link hsr0 name hsr0.3 type vlan id 3

  ip addr add 192.168.2.3 dev hsr0.2
  ip addr add 192.168.3.3 dev hsr0.3

  With the above configuration, tracing using tcpdump -i <hsr0> -xxx on the remote
  side will show VLAN header with id information.
