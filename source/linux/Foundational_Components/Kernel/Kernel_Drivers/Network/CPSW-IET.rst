IET
===

.. contents:: :local:
    :depth: 2

Warning: IET with Fixed-Link Interface
--------------------------------------

If one of the interfaces which takes part in IET is in fixed-link mode,
then do NOT enable MAC verify for IET on either of the devices
connected to each other directly by the LAN cable. This is because, in
the case of fixed-link, the link state cannot be detected by interfaces
on either side of the link. The process of IET MAC Verification depends
on the link state being toggled, with the verification starting
immediately after the link comes up and lasting for 1 second. Thus,
unless this process starts roughly simultaneously on both interfaces
connected over the link (Which would happen in the non fixed-link case),
IET MAC Verification would fail with a Timeout message, thereby causing
frame fragmentation to fail.

Thus, if either of the interfaces that are directly connected by a LAN
cable, is in fixed-link mode, then do NOT enable MAC verify on BOTH the
interfaces. Simply enable IET Frame Preemption on both devices and IET
will work. The rest of the steps are the same as documented in the
upcoming sectionss.

IET MAC Verification in ethtool corresponds to:

::

    iet-mac-verify

IET Frame Preemption in ethtool corresponds to:

::

    iet-frame-preemption

IET in MAC mode
---------------

AM625-SK fragments frames and J7VCL assembles them
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Connect eth0 of AM625-SK to eth1 of J7VCL.

**Steps:**

1. Create and run the following script on J7VCL:

::

    #!/bin/sh

    ifconfig eth1 down
    ifconfig eth2 down
    ifconfig eth3 down
    ifconfig eth4 down
    ethtool -L eth1 tx 2
    ethtool --set-priv-flags eth1 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth1 iet-frame-preemption on
    ethtool --set-priv-flags eth1 iet-mac-verify on
    ifconfig eth1 up
    sleep 5

    iperf3 -s -i30 -p5002&
    iperf3 -s -i30 -p5003&

2. Create and run the following script on AM625-SK:

::

    #!/bin/sh

    ifconfig eth0 down
    ifconfig eth1 down
    ethtool -L eth0 tx 2
    ethtool --set-priv-flags eth0 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth0 iet-frame-preemption on
    ethtool --set-priv-flags eth0 iet-mac-verify on
    ifconfig eth0 up
    sleep 5

    tc qdisc replace dev eth0 handle 100: parent root mqprio \
        num_tc 2 \
        map 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 \
        queues 1@0 1@1 \
        hw 0

    tc -g class show dev eth0
    tc qdisc add dev eth0 clsact
    tc filter add dev eth0 egress protocol ip prio 1 u32 match ip dport 5002 0xffff action skbedit priority 2
    tc filter add dev eth0 egress protocol ip prio 1 u32 match ip dport 5003 0xffff action skbedit priority 3
    ip addr add 192.168.100.20/24 dev eth0
    sleep 2

3. On J7VCL, run the following command:

::

    ifconfig eth1 192.168.100.30

4. Now, run the following commands on AM625-SK:

::

    iperf3 -c 192.168.100.30 -u -b200M -l1472 -u -t30 -i30 -p5002&
    iperf3 -c 192.168.100.30 -u -b50M -l1472 -u -t30 -i30 -p5003&

**Results:**

On AM625-SK (Sender):

::

    root@am62xx-evm:~/IET# ethtool -S eth0 | grep 'tx_pri1'
         p0_tx_pri1: 0
         p0_tx_pri1_bcnt: 0
         p0_tx_pri1_drop: 0
         p0_tx_pri1_drop_bcnt: 0
         tx_pri1: 127400
         tx_pri1_bcnt: 193357542
         tx_pri1_drop: 0
         tx_pri1_drop_bcnt: 0
    root@am62xx-evm:~/IET# ethtool -S eth0 | grep 'tx_pri0'
         p0_tx_pri0: 67
         p0_tx_pri0_bcnt: 10496
         p0_tx_pri0_drop: 0
         p0_tx_pri0_drop_bcnt: 0
         tx_pri0: 509608
         tx_pri0_bcnt: 773438547
         tx_pri0_drop: 0
         tx_pri0_drop_bcnt: 0
    root@am62xx-evm:~/IET# ethtool -S eth0 | grep iet
         iet_rx_assembly_err: 0
         iet_rx_assembly_ok: 0
         iet_rx_smd_err: 63
         iet_rx_frag: 0
         iet_tx_hold: 0
         iet_tx_frag: 120056

On J7VCL (Receiver):

::

    root@j7200-evm:~/IET# ethtool -S eth1 | grep iet
         iet_rx_assembly_err: 0
         iet_rx_assembly_ok: 32334
         iet_rx_smd_err: 1
         iet_rx_frag: 120056
         iet_tx_hold: 0
         iet_tx_frag: 0

**Explanation:**

::

    On AM625-SK, the higher priority traffic preempts the lower priority
    traffic, thereby resulting in the fragmentation of frames of lower
    priority. This can be seen in the iet_tx_frag statistic on AM625-SK.

    Similarly, on J7VCL, the received fragmented frames can be observed
    in the iet_rx_frag statistic, while the assembled frames can be seen
    in the iet_rx_assembly_ok statistic.

J7VCL fragments frames and AM625-SK assembles them
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Connect eth1 of J7VCL to eth0 of AM625-SK.

**Steps:**

1. Create and run the following script on AM625-SK:

::

    #!/bin/sh

    ifconfig eth0 down
    ifconfig eth1 down
    ethtool -L eth0 tx 2
    ethtool --set-priv-flags eth0 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth0 iet-frame-preemption on
    ethtool --set-priv-flags eth0 iet-mac-verify on
    ifconfig eth0 up
    sleep 5

    iperf3 -s -i30 -p5002&
    iperf3 -s -i30 -p5003&

2. Create and run the following script on J7VCL:

::

    #!/bin/sh

    ifconfig eth1 down
    ifconfig eth2 down
    ifconfig eth3 down
    ifconfig eth4 down
    ethtool -L eth1 tx 2
    ethtool --set-priv-flags eth1 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth1 iet-frame-preemption on
    ethtool --set-priv-flags eth1 iet-mac-verify on
    ifconfig eth1 up
    sleep 5

    tc qdisc replace dev eth1 handle 100: parent root mqprio \
        num_tc 2 \
        map 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 \
        queues 1@0 1@1 \
        hw 0

    tc -g class show dev eth1
    tc qdisc add dev eth1 clsact
    tc filter add dev eth1 egress protocol ip prio 1 u32 match ip dport 5002 0xffff action skbedit priority 2
    tc filter add dev eth1 egress protocol ip prio 1 u32 match ip dport 5003 0xffff action skbedit priority 3
    ip addr add 192.168.100.20/24 dev eth1
    sleep 2

3. Run the following command on AM625-SK:

::

    ifconfig eth0 192.168.100.30

4. Next, run the following commands on J7VCL:

::

    iperf3 -c 192.168.100.30 -u -b200M -l1472 -u -t30 -i30 -p5002&
    iperf3 -c 192.168.100.30 -u -b50M -l1472 -u -t30 -i30 -p5003&

**Results:**

On J7VCL (Sender):

::

    root@j7200-evm:~/IET# ethtool -S eth1 | grep 'tx_pri1'
         p0_tx_pri1: 0
         p0_tx_pri1_bcnt: 0
         p0_tx_pri1_drop: 0
         p0_tx_pri1_drop_bcnt: 0
         tx_pri1: 254787
         tx_pri1_bcnt: 386711048
         tx_pri1_drop: 0
         tx_pri1_drop_bcnt: 0
    root@j7200-evm:~/IET# ethtool -S eth1 | grep 'tx_pri0'
         p0_tx_pri0: 110
         p0_tx_pri0_bcnt: 16002
         p0_tx_pri0_drop: 0
         p0_tx_pri0_drop_bcnt: 0
         tx_pri0: 1019126
         tx_pri0_bcnt: 1546856078
         tx_pri0_drop: 0
         tx_pri0_drop_bcnt: 0
    root@j7200-evm:~/IET# ethtool -S eth1 | grep iet
         iet_rx_assembly_err: 0
         iet_rx_assembly_ok: 0
         iet_rx_smd_err: 36
         iet_rx_frag: 0
         iet_tx_hold: 0
         iet_tx_frag: 42

On AM625-SK (Receiver):

::

    root@am62xx-evm:~/IET# ethtool -S eth0 | grep iet
         iet_rx_assembly_err: 0
         iet_rx_assembly_ok: 29
         iet_rx_smd_err: 1
         iet_rx_frag: 42
         iet_tx_hold: 0
         iet_tx_frag: 0

**Explanation:**

::

    On J7VCL, the higher priority traffic preempts the lower priority
    traffic, thereby resulting in the fragmentation of frames of lower
    priority. This can be seen in the iet_tx_frag statistic on J7VCL.

    Similarly, on AM625-SK, the received fragmented frames can be observed
    in the iet_rx_frag statistic, while the assembled frames can be seen
    in the iet_rx_assembly_ok statistic.

IET in Switch mode
------------------

3 Devices are connected: Sender, Switch and Receiver.

3 Cases:

1. Frame is preempted on Sender and Assembled on Switch Ingress Port.
2. Frame is preempted on Switch Egress Port and Assembled on Receiver.
3. Frame is preempted on Sender and Assembled on Switch Ingress Port, and also, frame is preempted on Switch Egress Port and Assembled on Receiver.

Devices Used:

1. AM625-SK (As Switch/Sender)
2. J7VCL (As Switch/Sender)
3. AM64-SK (As Receiver)

CASE-1: Frame is preempted on Sender and Assembled on Switch Ingress Port
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Preemption on AM625-SK (Sender) and Assembly on J7VCL (Switch) Ingress Port and sent to AM64-SK (Receiver)
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

Connect eth0 of AM625-SK to eth1 of J7VCL and eth0 of AM64-SK to eth2 of J7VCL.

**Steps:**

1. On J7VCL, create and run the following script:

::

    #!/bin/sh

    ifconfig eth1 down
    ifconfig eth2 down
    ifconfig eth3 down
    ifconfig eth4 down
    ethtool -L eth1 tx 2
    ethtool --set-priv-flags eth1 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth1 iet-frame-preemption on
    ethtool --set-priv-flags eth1 iet-mac-verify on
    ifconfig eth1 up
    ifconfig eth2 up
    sleep 5

    devlink dev param set platform/c000000.ethernet name switch_mode value true cmode runtime
    ip link add name br0 type bridge
    ip link set dev br0 type bridge ageing_time 1000
    ip link set dev eth1 up
    ip link set dev eth2 up
    ip link set dev eth1 master br0
    ip link set dev eth2 master br0
    ip link set dev br0 up
    ip link set dev br0 type bridge vlan_filtering 1
    bridge vlan add dev br0 vid 1 pvid untagged self

2. On AM625-SK, create and run the following script:

::

    #!/bin/sh

    ifconfig eth0 down
    ifconfig eth1 down
    ethtool -L eth0 tx 2
    ethtool --set-priv-flags eth0 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth0 iet-frame-preemption on
    ethtool --set-priv-flags eth0 iet-mac-verify on
    ifconfig eth0 up
    sleep 5

    tc qdisc replace dev eth0 handle 100: parent root mqprio \
        num_tc 2 \
        map 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 \
        queues 1@0 1@1 \
        hw 0

    tc -g class show dev eth0
    tc qdisc add dev eth0 clsact
    tc filter add dev eth0 egress protocol ip prio 1 u32 match ip dport 5002 0xffff action skbedit priority 2
    tc filter add dev eth0 egress protocol ip prio 1 u32 match ip dport 5003 0xffff action skbedit priority 3
    ifconfig eth0 192.168.100.20 netmask 255.255.255.0
    sleep 2

3. On AM64-SK, run the following commands:

::

    ifconfig eth0 192.168.100.30
    iperf3 -s -i30 -p5002& \
    iperf3 -s -i30 -p5003&

4. Then, on AM625-SK, run the following commands:

::

    iperf3 -c 192.168.100.30 -u -b200M -l1472 -u -t30 -i30 -p5002& \
    iperf3 -c 192.168.100.30 -u -b50M -l1472 -u -t30 -i30 -p5003&

**Results:**

On AM625-SK (Sender):

::

    root@am62xx-evm:~/IET# ethtool -S eth0 | grep 'tx_pri1'
         p0_tx_pri1: 0
         p0_tx_pri1_bcnt: 0
         p0_tx_pri1_drop: 0
         p0_tx_pri1_drop_bcnt: 0
         tx_pri1: 127395
         tx_pri1_bcnt: 193357336
         tx_pri1_drop: 0
         tx_pri1_drop_bcnt: 0
    root@am62xx-evm:~/IET# ethtool -S eth0 | grep 'tx_pri0'
         p0_tx_pri0: 165
         p0_tx_pri0_bcnt: 34444
         p0_tx_pri0_drop: 0
         p0_tx_pri0_drop_bcnt: 0
         tx_pri0: 509721
         tx_pri0_bcnt: 773459795
         tx_pri0_drop: 0
         tx_pri0_drop_bcnt: 0
    root@am62xx-evm:~/IET# ethtool -S eth0 | grep iet
         iet_rx_assembly_err: 0
         iet_rx_assembly_ok: 0
         iet_rx_smd_err: 128
         iet_rx_frag: 0
         iet_tx_hold: 0
         iet_tx_frag: 114

On J7VCL (Switch):

::

    root@j7200-evm:~/IET# ethtool -S eth1 | grep iet
         iet_rx_assembly_err: 0
         iet_rx_assembly_ok: 108
         iet_rx_smd_err: 1
         iet_rx_frag: 114
         iet_tx_hold: 0
         iet_tx_frag: 0

Preemption on J7VCL (Sender) and Assembly on AM625-SK (Switch) Ingress Port and sent to AM64-SK (Receiver)
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

Connect eth1 of J7VCL to eth0 of AM625-SK and eth0 of AM64-SK to eth1 of AM625-SK.

**Steps:**

1. On AM625-SK, create and run the following script:

::

    #!/bin/sh

    ifconfig eth0 down
    ifconfig eth1 down
    ethtool -L eth0 tx 2
    ethtool --set-priv-flags eth0 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth0 iet-frame-preemption on
    ethtool --set-priv-flags eth0 iet-mac-verify on
    ifconfig eth0 up
    ifconfig eth1 up
    sleep 5

    devlink dev param set platform/8000000.ethernet name switch_mode value true cmode runtime
    ip link add name br0 type bridge
    ip link set dev br0 type bridge ageing_time 1000
    ip link set dev eth0 up
    ip link set dev eth1 up
    ip link set dev eth0 master br0
    ip link set dev eth1 master br0
    ip link set dev br0 up
    ip link set dev br0 type bridge vlan_filtering 1
    bridge vlan add dev br0 vid 1 pvid untagged self

2. On J7VCL, create and run the following script:

::

    #!/bin/sh

    ifconfig eth1 down
    ifconfig eth2 down
    ifconfig eth3 down
    ifconfig eth4 down
    ethtool -L eth1 tx 2
    ethtool --set-priv-flags eth1 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth1 iet-frame-preemption on
    ethtool --set-priv-flags eth1 iet-mac-verify on
    ifconfig eth1 up
    sleep 5

    tc qdisc replace dev eth1 handle 100: parent root mqprio \
        num_tc 2 \
        map 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 \
        queues 1@0 1@1 \
        hw 0

    tc -g class show dev eth1
    tc qdisc add dev eth1 clsact
    tc filter add dev eth1 egress protocol ip prio 1 u32 match ip dport 5002 0xffff action skbedit priority 2
    tc filter add dev eth1 egress protocol ip prio 1 u32 match ip dport 5003 0xffff action skbedit priority 3
    ifconfig eth1 192.168.100.20 netmask 255.255.255.0
    sleep 2

3. On AM64-SK, run the following commands:

::

    ifconfig eth0 192.168.100.30
    iperf3 -s -i30 -p5002& \
    iperf3 -s -i30 -p5003&

4. Then, on J7VCL, run the following commands:

::

    iperf3 -c 192.168.100.30 -u -b200M -l1472 -u -t30 -i30 -p5002& \
    iperf3 -c 192.168.100.30 -u -b50M -l1472 -u -t30 -i30 -p5003&

**Results:**

On J7VCL (Sender):

::

    root@j7200-evm:~/IET# ethtool -S eth1 | grep 'tx_pri1'
         p0_tx_pri1: 0
         p0_tx_pri1_bcnt: 0
         p0_tx_pri1_drop: 0
         p0_tx_pri1_drop_bcnt: 0
         tx_pri1: 127396
         tx_pri1_bcnt: 193356005
         tx_pri1_drop: 0
         tx_pri1_drop_bcnt: 0
    root@j7200-evm:~/IET# ethtool -S eth1 | grep 'tx_pri0'
         p0_tx_pri0: 76
         p0_tx_pri0_bcnt: 14563
         p0_tx_pri0_drop: 0
         p0_tx_pri0_drop_bcnt: 0
         tx_pri0: 509604
         tx_pri0_bcnt: 773435752
         tx_pri0_drop: 0
         tx_pri0_drop_bcnt: 0
    root@j7200-evm:~/IET# ethtool -S eth1 | grep iet
         iet_rx_assembly_err: 0
         iet_rx_assembly_ok: 0
         iet_rx_smd_err: 10
         iet_rx_frag: 0
         iet_tx_hold: 0
         iet_tx_frag: 77331

On AM625-SK (Switch):

::

    root@am62xx-evm:~/IET# ethtool -S eth0 | grep iet
         iet_rx_assembly_err: 11
         iet_rx_assembly_ok: 20790
         iet_rx_smd_err: 1092
         iet_rx_frag: 77300
         iet_tx_hold: 0
         iet_tx_frag: 0

CASE-2: Frame is preempted on Switch Egress Port and Assembled on Receiver
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. note::

    For the following tests, all interfaces which are a part of the test
    need to be a part of the same VLAN, since the switch needs to receive
    priority of the frames in order to perform preemption.

In addition to the Sender, the Switch's Host Port also transmits traffic
of lower priority to the receiver. This is done to ensure a higher chance
of frame preemption and therefore frame fragmentation on the Switch' Egress
Port.

Highest priority frame sent by AM625-SK with preemption on J7VCL's (Switch) Egress Port and Assembly on AM64-SK
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

Connect eth0 of AM625-SK to eth1 of J7VCL and eth0 of AM64-SK to eth2 of
J7VCL.

**Steps:**

1. Create and run the following script on J7VCL:

::

    #!/bin/sh

    ifconfig eth1 down
    ifconfig eth2 down
    ifconfig eth3 down
    ifconfig eth4 down
    ethtool -L eth2 tx 2
    ethtool --set-priv-flags eth2 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth2 iet-frame-preemption on
    ethtool --set-priv-flags eth2 iet-mac-verify on
    ifconfig eth1 up
    ifconfig eth2 up
    sleep 5

    tc qdisc replace dev eth2 handle 100: parent root mqprio \
        num_tc 2 \
        map 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 \
        queues 1@0 1@1 \
        hw 0

    tc -g class show dev eth2

    devlink dev param set platform/c000000.ethernet name switch_mode value true cmode runtime
    ip link add name br0 type bridge
    ip link set dev br0 type bridge ageing_time 1000
    ip link set dev eth1 up
    ip link set dev eth2 up
    ip link set dev eth1 master br0
    ip link set dev eth2 master br0
    ip link set dev br0 up
    sleep 2

    ip link set dev br0 type bridge vlan_filtering 1
    bridge vlan add dev br0 vid 100 pvid tagged self
    bridge vlan add dev eth1 vid 100 master
    bridge vlan add dev eth2 vid 100 master
    sleep 2

    ip link add link br0 name br0.100 type vlan id 100
    ip link set br0.100 type vlan egress 0:0 1:1 2:2 3:3 4:4 5:5 6:6 7:7
    sleep 2

    tc qdisc add dev br0.100 clsact
    tc filter add dev br0.100 egress protocol ip prio 1 u32 match ip dport 5002 0xffff action skbedit priority 2
    sleep 2

2. Create and run the following script on AM64-SK:

::

    #!/bin/sh

    ifconfig eth0 down
    ifconfig eth1 down
    ethtool -L eth0 tx 2
    ethtool --set-priv-flags eth0 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth0 iet-frame-preemption on
    ethtool --set-priv-flags eth0 iet-mac-verify on
    ifconfig eth0 up
    sleep 5

    ip link add link eth0 name eth0.100 type vlan id 100
    sleep 5
    ifconfig eth0.100 192.168.100.30
    iperf3 -s -i30 -p5001&
    iperf3 -s -i30 -p5002&
    iperf3 -s -i30 -p5003&

3. Create and run the following script on AM625-SK:

::

    #!/bin/sh

    ifconfig eth0 down
    ifconfig eth1 down
    ethtool -L eth0 tx 2
    ethtool --set-priv-flags eth0 p0-rx-ptype-rrobin off
    ifconfig eth0 up
    sleep 5
    ip link add link eth0 name eth0.100 type vlan id 100
    ip link set eth0.100 type vlan egress 0:0 1:1 2:2 3:3 4:4 5:5 6:6 7:7
    sleep 5

    tc qdisc add dev eth0.100 clsact
    tc filter add dev eth0.100 egress protocol ip prio 1 u32 match ip dport 5003 0xffff action skbedit priority 3
    ifconfig eth0.100 192.168.100.20 netmask 255.255.255.0
    sleep 2

4. Run the following commands on J7VCL:

::

    ifconfig br0.100 192.168.100.10
    sleep 10
    iperf3 -c 192.168.100.30 -u -b100M -l1472 t30 -i30 -p5001&
    iperf3 -c 192.168.100.30 -u -b100M -l1472 t30 -i30 -p5002&

5. Now, run the following command on AM625-SK:

::

    iperf3 -c 192.168.100.30 -u -b50M -l1472 -t30 -i30 -p5003&

**Results:**

On J7VCL (Switch):

::

    root@j7200-evm:~/IET# ethtool -S eth2 | grep 'tx_pri0'
         p0_tx_pri0: 173
         p0_tx_pri0_bcnt: 31039
         p0_tx_pri0_drop: 0
         p0_tx_pri0_drop_bcnt: 0
         tx_pri0: 85135
         tx_pri0_bcnt: 129274224
         tx_pri0_drop: 0
         tx_pri0_drop_bcnt: 0
    root@j7200-evm:~/IET# ethtool -S eth2 | grep 'tx_pri2'
         p0_tx_pri2: 0
         p0_tx_pri2_bcnt: 0
         p0_tx_pri2_drop: 0
         p0_tx_pri2_drop_bcnt: 0
         tx_pri2: 84932
         tx_pri2_bcnt: 129237975
         tx_pri2_drop: 0
         tx_pri2_drop_bcnt: 0
    root@j7200-evm:~/IET# ethtool -S eth2 | grep 'tx_pri3'
         p0_tx_pri3: 0
         p0_tx_pri3_bcnt: 0
         p0_tx_pri3_drop: 0
         p0_tx_pri3_drop_bcnt: 0
         tx_pri3: 3775
         tx_pri3_bcnt: 5717026
         tx_pri3_drop: 0
         tx_pri3_drop_bcnt: 0
    root@j7200-evm:~/IET# ethtool -S eth2 | grep iet
         iet_rx_assembly_err: 0
         iet_rx_assembly_ok: 0
         iet_rx_smd_err: 2
         iet_rx_frag: 0
         iet_tx_hold: 0
         iet_tx_frag: 107

On AM64-SK (Receiver):

::

    root@am64xx-evm:~# ethtool -S eth0 | grep iet
         iet_rx_assembly_err: 1
         iet_rx_assembly_ok: 94
         iet_rx_smd_err: 72
         iet_rx_frag: 106
         iet_tx_hold: 0
         iet_tx_frag: 0

Highest priority frame sent by J7VCL with preemption on AM625-SK's (Switch) Egress Port and Assembly on AM64-SK
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

Connect eth1 of J7VCL to eth0 of AM625-SK and eth0 of AM64-SK to eth1 of
AM625-SK.

**Steps:**

1. On AM625-SK, create and run the following script:

::

    #!/bin/sh

    ifconfig eth0 down
    ifconfig eth1 down
    ethtool -L eth1 tx 2
    ethtool --set-priv-flags eth1 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth1 iet-frame-preemption on
    ethtool --set-priv-flags eth1 iet-mac-verify on
    ifconfig eth0 up
    ifconfig eth1 up
    sleep 5

    tc qdisc replace dev eth1 handle 100: parent root mqprio \
        num_tc 2 \
        map 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 \
        queues 1@0 1@1 \
        hw 0

    tc -g class show dev eth1

    devlink dev param set platform/8000000.ethernet name switch_mode value true cmode runtime
    ip link add name br0 type bridge
    ip link set dev br0 type bridge ageing_time 1000
    ip link set dev eth0 up
    ip link set dev eth1 up
    ip link set dev eth0 master br0
    ip link set dev eth1 master br0
    ip link set dev br0 up
    sleep 2

    ip link set dev br0 type bridge vlan_filtering 1
    bridge vlan add dev br0 vid 100 pvid tagged self
    bridge vlan add dev eth0 vid 100 master
    bridge vlan add dev eth1 vid 100 master
    sleep 2

    ip link add link br0 name br0.100 type vlan id 100
    ip link set br0.100 type vlan egress 0:0 1:1 2:2 3:3 4:4 5:5 6:6 7:7
    sleep 2

    tc qdisc add dev br0.100 clsact
    tc filter add dev br0.100 egress protocol ip prio 1 u32 match ip dport 5002 0xffff action skbedit priority 2
    sleep 2

2. On AM64-SK, create and run the following script:

::

    #!/bin/sh

    ifconfig eth0 down
    ifconfig eth1 down
    ethtool -L eth0 tx 2
    ethtool --set-priv-flags eth0 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth0 iet-frame-preemption on
    ethtool --set-priv-flags eth0 iet-mac-verify on
    ifconfig eth0 up
    sleep 5

    ip link add link eth0 name eth0.100 type vlan id 100
    sleep 5
    ifconfig eth0.100 192.168.100.30
    iperf3 -s -i30 -p5002&
    iperf3 -s -i30 -p5003&

3. On J7VCL, create and run the following script:

::

    #!/bin/sh

    ifconfig eth1 down
    ifconfig eth2 down
    ifconfig eth3 down
    ifconfig eth4 down
    ethtool -L eth1 tx 2
    ethtool --set-priv-flags eth1 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth1 iet-frame-preemption on
    ethtool --set-priv-flags eth1 iet-mac-verify on
    ifconfig eth1 up
    sleep 5

    tc qdisc replace dev eth1 handle 100: parent root mqprio \
        num_tc 2 \
        map 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 \
        queues 1@0 1@1 \
        hw 0

    tc -g class show dev eth1

    ip link add link eth1 name eth1.100 type vlan id 100
    ip link set eth1.100 type vlan egress 0:0 1:1 2:2 3:3 4:4 5:5 6:6 7:7
    sleep 5

    tc qdisc add dev eth1.100 clsact
    tc filter add dev eth1.100 egress protocol ip prio 1 u32 match ip dport 5003 0xffff action skbedit priority 3
    ifconfig eth1.100 192.168.100.20 netmask 255.255.255.0
    sleep 2

4. Run the following commands on AM625-SK:

::

    ifconfig br0.100 192.168.100.10
    sleep 10
    iperf3 -c 192.168.100.30 -u -b100M -l1472 t30 -i30 -p5001& \
    iperf3 -c 192.168.100.30 -u -b100M -l1472 t30 -i30 -p5002&

5. Now, on J7VCL, run the following command:

::

    iperf3 -c 192.168.100.30 -u -b50M -l1472 -t30 -i30 -p5003&

**Results:**

On AM625-SK (Switch):

::

    root@am62xx-evm:~/IET# ethtool -S eth1 | grep 'tx_pri0
         p0_tx_pri0: 228
         p0_tx_pri0_bcnt: 44010
         p0_tx_pri0_drop: 0
         p0_tx_pri0_drop_bcnt: 0
         tx_pri0: 792
         tx_pri0_bcnt: 938162
         tx_pri0_drop: 0
         tx_pri0_drop_bcnt: 0
    root@am62xx-evm:~/IET# ethtool -S eth1 | grep 'tx_pri2'
         p0_tx_pri2: 0
         p0_tx_pri2_bcnt: 0
         p0_tx_pri2_drop: 0
         p0_tx_pri2_drop_bcnt: 0
         tx_pri2: 706
         tx_pri2_bcnt: 1047447
         tx_pri2_drop: 0
         tx_pri2_drop_bcnt: 0
    root@am62xx-evm:~/IET# ethtool -S eth1 | grep 'tx_pri3'
         p0_tx_pri3: 0
         p0_tx_pri3_bcnt: 0
         p0_tx_pri3_drop: 0
         p0_tx_pri3_drop_bcnt: 0
         tx_pri3: 127393
         tx_pri3_bcnt: 193865046
         tx_pri3_drop: 0
         tx_pri3_drop_bcnt: 0
    root@am62xx-evm:~/IET# ethtool -S eth1 | grep iet
         iet_rx_assembly_err: 0
         iet_rx_assembly_ok: 0
         iet_rx_smd_err: 0
         iet_rx_frag: 0
         iet_tx_hold: 0
         iet_tx_frag: 54

On AM64-SK (Receiver):

::

    root@am64xx-evm:~# ethtool -S eth0 | grep iet
         iet_rx_assembly_err: 0
         iet_rx_assembly_ok: 23
         iet_rx_smd_err: 120
         iet_rx_frag: 54
         iet_tx_hold: 0
         iet_tx_frag: 0

CASE-3: Frame is preempted on both Sender and Switch Egress Port
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. note::

    For the following tests, all interfaces which are a part of the test
    need to be a part of the same VLAN, since the switch needs to receive
    priority of the frames in order to perform preemption.

In addition to the Sender, the Switch's Host Port also transmits traffic
of lower priority to the receiver. This is done to ensure a higher chance
of frame preemption and therefore frame fragmentation on the Switch' Egress
Port.

CASE-3 is the same as CASE-1 and CASE-2 combined.

Frame sent by AM625-SK with preemption on AM625-SK Egress Port and Assembled on J7VCL's (Switch) Ingress Port followed by preemption on J7VCL's (Switch) Egress Port and Assembled on AM64-SK
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

Connect eth0 of AM625-SK to eth1 of J7VCL and eth0 of AM64-SK to eth2 of
J7VCL.

**Steps:**

1. Create and run the following script on J7VCL:

::

    #!/bin/sh

    ifconfig eth1 down
    ifconfig eth2 down
    ifconfig eth3 down
    ifconfig eth4 down
    ethtool -L eth1 tx 2
    ethtool --set-priv-flags eth1 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth1 iet-frame-preemption on
    ethtool --set-priv-flags eth1 iet-mac-verify on
    ethtool -L eth2 tx 2
    ethtool --set-priv-flags eth2 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth2 iet-frame-preemption on
    ethtool --set-priv-flags eth2 iet-mac-verify on
    ifconfig eth1 up
    ifconfig eth2 up
    sleep 5

    tc qdisc replace dev eth2 handle 100: parent root mqprio \
        num_tc 2 \
        map 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 \
        queues 1@0 1@1 \
        hw 0

    tc -g class show dev eth2

    devlink dev param set platform/c000000.ethernet name switch_mode value true cmode runtime
    ip link add name br0 type bridge
    ip link set dev br0 type bridge ageing_time 1000
    ip link set dev eth1 up
    ip link set dev eth2 up
    ip link set dev eth1 master br0
    ip link set dev eth2 master br0
    ip link set dev br0 up
    sleep 2

    ip link set dev br0 type bridge vlan_filtering 1
    bridge vlan add dev br0 vid 100 pvid tagged self
    bridge vlan add dev eth1 vid 100 master
    bridge vlan add dev eth2 vid 100 master
    sleep 2

    ip link add link br0 name br0.100 type vlan id 100
    ip link set br0.100 type vlan egress 0:0 1:1 2:2 3:3 4:4 5:5 6:6 7:7
    sleep 2

    tc qdisc add dev br0.100 clsact
    tc filter add dev br0.100 egress protocol ip prio 1 u32 match ip dport 5002 0xffff action skbedit priority 2
    sleep 2

2. Create and run the following script on AM64-SK:

::

    #!/bin/sh

    ifconfig eth0 down
    ifconfig eth1 down
    ethtool -L eth0 tx 2
    ethtool --set-priv-flags eth0 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth0 iet-frame-preemption on
    ethtool --set-priv-flags eth0 iet-mac-verify on
    ifconfig eth0 up
    sleep 5

    ip link add link eth0 name eth0.100 type vlan id 100
    sleep 5
    ifconfig eth0.100 192.168.100.30
    iperf3 -s -i30 -p5001&
    iperf3 -s -i30 -p5002&
    iperf3 -s -i30 -p5003&
    iperf3 -s -i30 -p5004&
    iperf3 -s -i30 -p5005&

3. Create and run the following script on AM625-SK:

::

    #!/bin/sh

    ifconfig eth0 down
    ifconfig eth1 down
    ethtool -L eth0 tx 2
    ethtool --set-priv-flags eth0 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth0 iet-frame-preemption on
    ethtool --set-priv-flags eth0 iet-mac-verify on
    ifconfig eth0 up
    sleep 5
    ip link add link eth0 name eth0.100 type vlan id 100
    ip link set eth0.100 type vlan egress 0:0 1:1 2:2 3:3 4:4 5:5 6:6 7:7
    sleep 5

    tc qdisc add dev eth0.100 clsact
    tc filter add dev eth0.100 egress protocol ip prio 1 u32 match ip dport 5003 0xffff action skbedit priority 2
    tc filter add dev eth0.100 egress protocol ip prio 1 u32 match ip dport 5004 0xffff action skbedit priority 3
    ifconfig eth0.100 192.168.100.20 netmask 255.255.255.0
    sleep 2

4. Run the following commands on J7VCL:

::

    ifconfig br0.100 192.168.100.10
    sleep 10
    iperf3 -c 192.168.100.30 -u -b100M -l1472 t30 -i30 -p5001& \
    iperf3 -c 192.168.100.30 -u -b100M -l1472 t30 -i30 -p5002&

5. Now, run the following commands on AM625-SK:

::

   iperf3 -c 192.168.100.30 -u -b100M -l1472 -t30 -i30 -p5003& \
   iperf3 -c 192.168.100.30 -u -b50M -l1472 -t30 -i30 -p5004& \
   iperf3 -c 192.168.100.30 -u -b100M -l1472 -t30 -i30 -p5005&

**Results:**

On AM625-SK (Sender):

::

    root@am62xx-evm:~/IET# ethtool -S eth0 | grep iet
         iet_rx_assembly_err: 0
         iet_rx_assembly_ok: 0
         iet_rx_smd_err: 63
         iet_rx_frag: 0
         iet_tx_hold: 0
         iet_tx_frag: 4

On J7VCL (Switch):

::

    root@j7200-evm:~/IET# ethtool -S eth1 | grep iet
         iet_rx_assembly_err: 0
         iet_rx_assembly_ok: 4
         iet_rx_smd_err: 1
         iet_rx_frag: 4
         iet_tx_hold: 0
         iet_tx_frag: 0
    root@j7200-evm:~/IET# ethtool -S eth2 | grep iet
         iet_rx_assembly_err: 0
         iet_rx_assembly_ok: 0
         iet_rx_smd_err: 1
         iet_rx_frag: 0
         iet_tx_hold: 0
         iet_tx_frag: 127

On AM64-SK (Receiver):

::

    root@am64xx-evm:~# ethtool -S eth0 | grep iet
         iet_rx_assembly_err: 0
         iet_rx_assembly_ok: 68
         iet_rx_smd_err: 34
         iet_rx_frag: 127
         iet_tx_hold: 0
         iet_tx_frag: 0

Frame sent by J7VCL with preemption on J7VCL Egress Port and Assembled on AM625-SK's (Switch) Ingress Port followed by preemption on AM625-SK's (Switch) Egress Port and Assembled on AM64-SK
""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

Connect eth1 of J7VCL to eth0 of AM625-SK and eth0 of AM64-SK to eth1 of
AM625-SK.

**Steps:**

1. Create and run the following script on AM625-SK:

::

    #!/bin/sh

    ifconfig eth0 down
    ifconfig eth1 down
    ethtool -L eth0 tx 2
    ethtool --set-priv-flags eth0 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth0 iet-frame-preemption on
    ethtool --set-priv-flags eth0 iet-mac-verify on
    ethtool -L eth1 tx 2
    ethtool --set-priv-flags eth1 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth1 iet-frame-preemption on
    ethtool --set-priv-flags eth1 iet-mac-verify on
    ifconfig eth0 up
    ifconfig eth1 up
    sleep 5

    tc qdisc replace dev eth1 handle 100: parent root mqprio \
        num_tc 2 \
        map 0 0 0 1 0 0 0 0 0 0 0 0 0 0 0 0 \
        queues 1@0 1@1 \
        hw 0

    tc -g class show dev eth1

    devlink dev param set platform/8000000.ethernet name switch_mode value true cmode runtime
    ip link add name br0 type bridge
    ip link set dev br0 type bridge ageing_time 1000
    ip link set dev eth0 up
    ip link set dev eth1 up
    ip link set dev eth0 master br0
    ip link set dev eth1 master br0
    ip link set dev br0 up
    sleep 2

    ip link set dev br0 type bridge vlan_filtering 1
    bridge vlan add dev br0 vid 100 pvid tagged self
    bridge vlan add dev eth0 vid 100 master
    bridge vlan add dev eth1 vid 100 master
    sleep 2

    ip link add link br0 name br0.100 type vlan id 100
    ip link set br0.100 type vlan egress 0:0 1:1 2:2 3:3 4:4 5:5 6:6 7:7
    sleep 2

    tc qdisc add dev br0.100 clsact
    tc filter add dev br0.100 egress protocol ip prio 1 u32 match ip dport 5002 0xffff action skbedit priority 2
    sleep 2

2. Create and run the following script on AM64-SK:

::

    #!/bin/sh

    ifconfig eth0 down
    ifconfig eth1 down
    ethtool -L eth0 tx 2
    ethtool --set-priv-flags eth0 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth0 iet-frame-preemption on
    ethtool --set-priv-flags eth0 iet-mac-verify on
    ifconfig eth0 up
    sleep 5

    ip link add link eth0 name eth0.100 type vlan id 100
    sleep 5
    ifconfig eth0.100 192.168.100.30
    iperf3 -s -i30 -p5001&
    iperf3 -s -i30 -p5002&
    iperf3 -s -i30 -p5003&
    iperf3 -s -i30 -p5004&
    iperf3 -s -i30 -p5005&

3. Create and run the following script on J7VCL:

::

    #!/bin/sh

    ifconfig eth1 down
    ifconfig eth2 down
    ifconfig eth3 down
    ifconfig eth4 down
    ethtool -L eth1 tx 2
    ethtool --set-priv-flags eth1 p0-rx-ptype-rrobin off
    ethtool --set-priv-flags eth1 iet-frame-preemption on
    ethtool --set-priv-flags eth1 iet-mac-verify on
    ifconfig eth1 up
    sleep 5
    ip link add link eth1 name eth1.100 type vlan id 100
    ip link set eth1.100 type vlan egress 0:0 1:1 2:2 3:3 4:4 5:5 6:6 7:7
    sleep 5

    tc qdisc add dev eth1.100 clsact
    tc filter add dev eth1.100 egress protocol ip prio 1 u32 match ip dport 5003 0xffff action skbedit priority 2
    tc filter add dev eth1.100 egress protocol ip prio 1 u32 match ip dport 5004 0xffff action skbedit priority 3
    ifconfig eth1.100 192.168.100.20 netmask 255.255.255.0
    sleep 2

4. Run the following commands on AM625-SK:

::

    ifconfig br0.100 192.168.100.10
    sleep 10
    iperf3 -c 192.168.100.30 -u -b100M -l1472 t30 -i30 -p5001& \
    iperf3 -c 192.168.100.30 -u -b100M -l1472 t30 -i30 -p5002&

5. Now, run the following commands on J7VCL:

::

    iperf3 -c 192.168.100.30 -u -b100M -l1472 -t30 -i30 -p5003& \
    iperf3 -c 192.168.100.30 -u -b50M -l1472 -t30 -i30 -p5004& \
    iperf3 -c 192.168.100.30 -u -b100M -l1472 -t30 -i30 -p5005&

**Results:**

On J7VCL (Sender):

::

    root@j7200-evm:~/IET# ethtool -S eth1 | grep iet
         iet_rx_assembly_err: 0
         iet_rx_assembly_ok: 0
         iet_rx_smd_err: 55
         iet_rx_frag: 0
         iet_tx_hold: 0
         iet_tx_frag: 220

On AM625-SK (Switch):

::

    root@am62xx-evm:~/IET# ethtool -S eth0 | grep iet
         iet_rx_assembly_err: 0
         iet_rx_assembly_ok: 106
         iet_rx_smd_err: 4
         iet_rx_frag: 220
         iet_tx_hold: 0
         iet_tx_frag: 0
    root@am62xx-evm:~/IET# ethtool -S eth1 | grep iet
         iet_rx_assembly_err: 0
         iet_rx_assembly_ok: 0
         iet_rx_smd_err: 0
         iet_rx_frag: 0
         iet_tx_hold: 0
         iet_tx_frag: 212

On AM64-SK (Receiver):

::

    root@am64xx-evm:~# ethtool -S eth0 | grep iet
         iet_rx_assembly_err: 0
         iet_rx_assembly_ok: 148
         iet_rx_smd_err: 109
         iet_rx_frag: 212
         iet_tx_hold: 0
         iet_tx_frag: 0
