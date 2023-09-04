
HSR (High-availability Seamless Redundancy) and PRP (Parellel Redundancy
Protocol) are protocols supporting redundant network connections defined by
IEC 62439-3. Both operate by using two ethernet ports together, and duplicating
every frame to be sent over both ports, so if one connection fails, the
transmission succeeds. Frames are tagged with a sequence number, so the
receiving node can identify and discard duplicates. HSR/PRP provides an
advantage over other protocols that handle link failure (e.g. STP/RSTP)
because there is no downtime or packet loss on link failure. This is
required in some industrial networking situations.

The major difference between HSR and PRP is that HSR networks are configured
as a ring, then frames are sent both directions around the ring by all nodes.
PRP networks can take any configuration, and all connections are simply
physically duplicated. Additionally, PRP nodes can interoperate with standard
ethernet networks, while HSR cannot. (See more details below and full
details in IEC 62439-3)

The HSR/PRP protocols can be run by the Linux kernel, and function over
standard ethernet ports, but the advantage of using the PRU-ICSS supported
industrial ethernet ports is that the PRU-ICSS HSR/PRP firmware offloads much
of the protocol functionality to firmware, allowing more processing bandwidth
for an application, and in the case of HSR, providing faster cut-through
switching as frames pass through ring nodes.

