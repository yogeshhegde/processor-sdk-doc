
HSR stands for High Availability Seamless Redundancy. This is a protocol
used to support redundant networks needed for industrial applications
such as factory automation, substation automation etc. The standard is
defined in IEC 62439-3 clause 5. HSR Ethernet frames are not compatible
with standard Ethernet frames. HSR frames are identified uniquely by the
HSR tag. So only HSR frames are possible in the network which is not
identifiable by a standard Ethernet device. Factory or field devices are
connected to a Double Attached Node HSR (DANH). Typically these nodes
are connected in a Ring topology and only DANH compliant nodes can be
connected to the HSR network. Other standard Ethernet devices (Singly
Attached Nodes, SANs) needs to be connected through a Redundancy Box
(RedBox) to work with HSR networks. HSR tag is used to manage redundancy
in HSR network.

A DANH node has two ports operated in parallel. A source DANH prefixes a
frame passed from its upper layers with an HSR tag to identify frame
duplicates and sends the frame over each port.

A destination DANH receives, in the fault-free state, two identical
frames (one from each port) within a certain interval. It removes the
HSR tag of the first frame before passing it to its upper layers and
discards any duplicate. The nodes support the IEEE 802.1D bridge
functionality and forward frames from one port to the other, except if
they already sent the same frame in that same direction. In particular,
the node will not forward a frame that it injected into the ring. 

