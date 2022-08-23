CBS
===

.. contents:: :local:
    :depth: 3

CBS in MAC mode
---------------

Rate-limiting Host Port Ingress on AM625-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Connect eth0 of AM625-SK to eth1 of J7VCL.

**Steps:**

1. Create and run the following script on AM625-SK:

::

    #!/bin/sh

    ifconfig eth0 down
    ifconfig eth1 down
    ethtool -L eth0 tx 8
    ifconfig eth0 up
    ifconfig eth0 192.168.1.1

    sleep 10

    tc qdisc replace dev eth0 handle 100: parent root mqprio num_tc 3 \
    map 0 0 0 0 0 0 1 2 0 0 0 0 0 0 0 0 queues 1@0 1@6 1@7 hw 0

    echo 106 > /sys/class/net/eth0/queues/tx-7/tx_maxrate
    echo 212 > /sys/class/net/eth0/queues/tx-6/tx_maxrate

    tc qdisc add dev eth0 clsact
    tc filter add dev eth0 egress protocol ip prio 1 u32 match ip dport 5001 0xffff action skbedit priority 7
    tc filter add dev eth0 egress protocol ip prio 1 u32 match ip dport 5002 0xffff action skbedit priority 6

In the above script,  the tx queues that send data to the host port are rate-
limited using the following commands:

::

    # Rate limit tx queue 7 of eth0 to 106 Mbps
    echo 106 > /sys/class/net/eth0/queues/tx-7/tx_maxrate
    # Rate limit tx queue 6 of eth0 to 212 Mbps
    echo 212 > /sys/class/net/eth0/queues/tx-6/tx_maxrate

2. Next, assign IP address of 192.168.1.2 to Port-1 of the CPSW5G ports on J7VCL using:

::

    ifconfig eth1 192.168.1.2

3. Next, start an iperf server on J7VCL by running:

::

    iperf3 -s -p 5001&
    iperf3 -s -p 5002&
    iperf3 -s -p 5003&

4. Now, run the iperf client on AM625-SK using:

::

    iperf3 -c 192.168.1.2 -t10 -p5001 -Tpri7 & \
    iperf3 -c 192.168.1.2 -t10 -p5002 -Tpri6 & \
    iperf3 -c 192.168.1.2 -t10 -p5003 -Tpri0

**Results:**

On AM625-SK:

::

    pri0:  - - - - - - - - - - - - - - - - - - - - - - - - -
    pri0:  [ ID] Interval           Transfer     Bitrate         Retr
    pri0:  [  5]   0.00-10.00  sec   738 MBytes   619 Mbits/sec  162             sender
    pri0:  [  5]   0.00-10.00  sec   735 MBytes   617 Mbits/sec                  receiver
    pri0:
    pri0:  iperf Done.
    pri6:  - - - - - - - - - - - - - - - - - - - - - - - - -
    pri6:  [ ID] Interval           Transfer     Bitrate         Retr
    pri6:  [  5]   0.00-10.00  sec   221 MBytes   185 Mbits/sec   69             sender
    pri6:  [  5]   0.00-10.01  sec   220 MBytes   184 Mbits/sec                  receiver
    pri6:
    pri6:  iperf Done.
    pri7:  - - - - - - - - - - - - - - - - - - - - - - - - -
    pri7:  [ ID] Interval           Transfer     Bitrate         Retr
    pri7:  [  5]   0.00-10.00  sec   115 MBytes  96.5 Mbits/sec   37             sender
    pri7:  [  5]   0.00-10.01  sec   114 MBytes  95.9 Mbits/sec                  receiver
    pri7:
    pri7:  iperf Done.

Rate-limiting Host Port Ingress on J7VCL
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Connect eth1 of J7VCL to eth0 of AM625-SK.

**Steps:**

1. Create and run the following script on J7VCL:

::

    #!/bin/sh

    ifconfig eth1 down
    ifconfig eth2 down
    ifconfig eth3 down
    ifconfig eth4 down
    ethtool -L eth1 tx 8
    ifconfig eth1 up
    ifconfig eth1 192.168.1.1

    sleep 10

    tc qdisc replace dev eth1 handle 100: parent root mqprio num_tc 3 \
    map 0 0 0 0 0 0 1 2 0 0 0 0 0 0 0 0 queues 1@0 1@6 1@7 hw 0

    echo 106 > /sys/class/net/eth1/queues/tx-7/tx_maxrate
    echo 212 > /sys/class/net/eth1/queues/tx-6/tx_maxrate

    tc qdisc add dev eth1 clsact
    tc filter add dev eth1 egress protocol ip prio 1 u32 match ip dport 5001 0xffff action skbedit priority 7
    tc filter add dev eth1 egress protocol ip prio 1 u32 match ip dport 5002 0xffff action skbedit priority 6

In the above script,  the tx queues that send data to the host port are rate-
limited using the following commands:

::

    # Rate limit tx queue 7 of eth0 to 106 Mbps
    echo 106 > /sys/class/net/eth0/queues/tx-7/tx_maxrate
    # Rate limit tx queue 6 of eth0 to 212 Mbps
    echo 212 > /sys/class/net/eth0/queues/tx-6/tx_maxrate

2. Next, assign IP address of 192.168.1.2 to Port-1 of the CPSW3G ports on AM625-SK using:

::

    ifconfig eth0 192.168.1.2

3. Next, start an iperf server on AM625-SK by running:

::

    iperf3 -s -p 5001&
    iperf3 -s -p 5002&
    iperf3 -s -p 5003&

4. Now, run the iperf client on J7VCL using:

::

    iperf3 -c 192.168.1.2 -t10 -p5001 -Tpri7 & \
    iperf3 -c 192.168.1.2 -t10 -p5002 -Tpri6 & \
    iperf3 -c 192.168.1.2 -t10 -p5003 -Tpri0

**Results:**

On J7VCL:

::

    pri0:  - - - - - - - - - - - - - - - - - - - - - - - - -
    pri0:  [ ID] Interval           Transfer     Bitrate         Retr
    pri0:  [  5]   0.00-10.00  sec   759 MBytes   637 Mbits/sec    0             sender
    pri0:  [  5]   0.00-10.00  sec   756 MBytes   635 Mbits/sec                  receiver
    pri0:
    pri0:  iperf Done.
    pri7:  - - - - - - - - - - - - - - - - - - - - - - - - -
    pri7:  [ ID] Interval           Transfer     Bitrate         Retr
    pri7:  [  5]   0.00-10.00  sec   118 MBytes  98.7 Mbits/sec    0             sender
    pri7:  [  5]   0.00-10.01  sec   117 MBytes  97.9 Mbits/sec                  receiver
    pri7:
    pri7:  iperf Done.
    pri6:  - - - - - - - - - - - - - - - - - - - - - - - - -
    pri6:  [ ID] Interval           Transfer     Bitrate         Retr
    pri6:  [  5]   0.00-10.00  sec   234 MBytes   196 Mbits/sec    0             sender
    pri6:  [  5]   0.00-10.01  sec   233 MBytes   195 Mbits/sec                  receiver
    pri6:
    pri6:  iperf Done.

Rate-limiting Switch Egress on AM625-SK (Data sent from Host Port of AM625-SK to J7VCL)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Connect eth0 of AM625-SK to eth1 of J7VCL.

**Steps:**

1. Create and run the following script on AM625-SK:

::

    #!/bin/sh

    ifconfig eth0 down
    ifconfig eth1 down
    ethtool -L eth0 tx 8
    ifconfig eth0 up
    ifconfig eth0 192.168.1.1

    sleep 10

    tc qdisc add dev eth0 parent root handle 100: mqprio num_tc 3 \
    map 0 0 0 0 0 0 1 2 0 0 0 0 0 0 0 0 \
    queues 1@0 1@6 1@7 hw 1 mode channel \
    shaper bw_rlimit min_rate 0 212mbit 106mbit max_rate 0 250mbit 150mbit

    echo 106 > /sys/class/net/eth0/queues/tx-7/tx_maxrate
    echo 212 > /sys/class/net/eth0/queues/tx-6/tx_maxrate

    tc qdisc add dev eth0 clsact
    tc filter add dev eth0 egress protocol ip prio 1 u32 match ip dport 5001 0xffff action skbedit priority 7
    tc filter add dev eth0 egress protocol ip prio 1 u32 match ip dport 5002 0xffff action skbedit priority 6

2. Assign IP address of 192.168.1.2 to Port-1 of the CPSW5G ports on J7VCL using:

::

    ifconfig eth1 192.168.1.2

3. Next, start an iperf server on J7VCL using:

::

    iperf3 -s -p 5001&
    iperf3 -s -p 5002&
    iperf3 -s -p 5003&

4. Now, run the iperf client on AM625-SK using:

::

    iperf3 -c 192.168.1.2 -t10 -p5001 -Tpri7 & \
    iperf3 -c 192.168.1.2 -t10 -p5002 -Tpri6 & \
    iperf3 -c 192.168.1.2 -t10 -p5003 -Tpri0

**Results:**

On AM625-SK:

::

    pri7:  - - - - - - - - - - - - - - - - - - - - - - - - -
    pri7:  [ ID] Interval           Transfer     Bitrate         Retr
    pri7:  [  5]   0.00-10.00  sec   116 MBytes  97.1 Mbits/sec   17             sender
    pri7:  [  5]   0.00-10.00  sec   115 MBytes  96.5 Mbits/sec                  receiver
    pri7:
    pri7:  iperf Done.
    pri6:  - - - - - - - - - - - - - - - - - - - - - - - - -
    pri6:  [ ID] Interval           Transfer     Bitrate         Retr
    pri6:  [  5]   0.00-10.00  sec   226 MBytes   190 Mbits/sec   33             sender
    pri6:  [  5]   0.00-10.01  sec   225 MBytes   189 Mbits/sec                  receiver
    pri6:
    pri6:  iperf Done.
    pri0:  - - - - - - - - - - - - - - - - - - - - - - - - -
    pri0:  [ ID] Interval           Transfer     Bitrate         Retr
    pri0:  [  5]   0.00-10.00  sec   716 MBytes   601 Mbits/sec   42             sender
    pri0:  [  5]   0.00-10.00  sec   714 MBytes   598 Mbits/sec                  receiver
    pri0:
    pri0:  iperf Done.

Rate-limiting Switch Egress on J7VCL (Data sent from Host Port of J7VCL to AM625-SK)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Connect eth1 of J7VCL to eth0 of AM625-SK.

**Steps:**

1. Create and run the following script on J7VCL:

::

    #!/bin/sh

    ifconfig eth1 down
    ifconfig eth2 down
    ifconfig eth3 down
    ifconfig eth4 down
    ethtool -L eth1 tx 8
    ifconfig eth1 up
    ifconfig eth1 192.168.1.1

    sleep 10

    tc qdisc add dev eth1 parent root handle 100: mqprio num_tc 3 \
    map 0 0 0 0 0 0 1 2 0 0 0 0 0 0 0 0 \
    queues 1@0 1@6 1@7 hw 1 mode channel \
    shaper bw_rlimit min_rate 0 212mbit 106mbit max_rate 0 250mbit 150mbit

    echo 106 > /sys/class/net/eth1/queues/tx-7/tx_maxrate
    echo 212 > /sys/class/net/eth1/queues/tx-6/tx_maxrate

    tc qdisc add dev eth1 clsact
    tc filter add dev eth1 egress protocol ip prio 1 u32 match ip dport 5001 0xffff action skbedit priority 7
    tc filter add dev eth1 egress protocol ip prio 1 u32 match ip dport 5002 0xffff action skbedit priority 6

2. Assign IP address of 192.168.1.2 to Port-1 of the CPSW3G ports on AM625-SK using:

::

    ifconfig eth0 192.168.1.2

3. Next, start an iperf server on AM625-SK using:

::

    iperf3 -s -p 5001&
    iperf3 -s -p 5002&
    iperf3 -s -p 5003&

4. Now, run the iperf client on J7VCL using:

::

    iperf3 -c 192.168.1.2 -t10 -p5001 -Tpri7 & \
    iperf3 -c 192.168.1.2 -t10 -p5002 -Tpri6 & \
    iperf3 -c 192.168.1.2 -t10 -p5003 -Tpri0

**Results:**

On J7VCL:

::

    pri0:  - - - - - - - - - - - - - - - - - - - - - - - - -
    pri0:  [ ID] Interval           Transfer     Bitrate         Retr
    pri0:  [  5]   0.00-10.00  sec   746 MBytes   626 Mbits/sec    0             sender
    pri0:  [  5]   0.00-10.00  sec   744 MBytes   624 Mbits/sec                  receiver
    pri0:
    pri0:  iperf Done.
    pri6:  - - - - - - - - - - - - - - - - - - - - - - - - -
    pri6:  [ ID] Interval           Transfer     Bitrate         Retr
    pri6:  [  5]   0.00-10.00  sec   234 MBytes   196 Mbits/sec    0             sender
    pri6:  [  5]   0.00-10.01  sec   233 MBytes   195 Mbits/sec                  receiver
    pri6:
    pri6:  iperf Done.
    pri7:  - - - - - - - - - - - - - - - - - - - - - - - - -
    pri7:  [ ID] Interval           Transfer     Bitrate         Retr
    pri7:  [  5]   0.00-10.00  sec   119 MBytes  99.4 Mbits/sec    0             sender
    pri7:  [  5]   0.00-10.01  sec   117 MBytes  98.3 Mbits/sec                  receiver
    pri7:
    pri7:  iperf Done.

CBS in Switch mode
------------------

Rate-limiting is implemented on the sender and the switch, with the rate-
limiting on the switch being stricter than the sender. This is done due
to the size limit of the TX FIFO queue.

.. note::

    All three devices (AM625-SK, AM64-SK and J7VCL) must be a part of the
    same VLAN, to ensure that the priority field is included in the
    packets, enabling the switch to identify the priority and rate-limit
    traffic accordingly.

Rate limiting Switch Egress on AM625-SK (Data sent from AM64-SK to J7VCL via AM625-SK switch)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Connect AM64-SK's eth0 to AM625-SK's eth0 and J7VCL's eth1 to AM625-SK's
eth1.

**Steps:**

1. Create and run the following script on AM625-SK:

::

    #!/bin/sh
    ifconfig eth0 down
    ifconfig eth1 down
    ethtool -L eth1 tx 8
    ethtool --set-priv-flags eth1 p0-rx-ptype-rrobin off

    devlink dev param set platform/8000000.ethernet name switch_mode value true cmode runtime
    ip link add name br0 type bridge
    ip link set dev br0 type bridge ageing_time 1000
    ip link set dev eth0 up
    ip link set dev eth1 up
    sleep 10

    ip link set dev eth0 master br0
    ip link set dev eth1 master br0
    ip link set dev br0 up
    ip link set dev br0 type bridge vlan_filtering 1
    bridge vlan add dev br0 vid 1 pvid untagged self
    bridge vlan add dev eth0 vid 100 master
    bridge vlan add dev eth1 vid 100 master


    tc qdisc add dev eth1 parent root handle 100: mqprio num_tc 3 \
    map 0 0 0 0 0 0 1 2 0 0 0 0 0 0 0 0 \
    queues 1@0 1@6 1@7 hw 1 mode channel \
    shaper bw_rlimit min_rate 99mbit 211mbit 105mbit max_rate 100mbit 212mbit 106mbit

2. Create and run the following script on AM64-SK:

::

    #!/bin/sh

    ifconfig eth0 down
    ifconfig eth1 down
    ethtool -L eth0 tx 8
    ifconfig eth0 up
    sleep 5

    ip link add link eth0 name eth0.100 type vlan id 100
    ip link set eth0.100 type vlan egress 0:0 1:1 2:2 3:3 4:4 5:5 6:6 7:7
    sleep 5
    ifconfig eth0.100 192.168.1.1 netmask 255.255.255.0
    sleep 2

    echo 106 > /sys/class/net/eth0/queues/tx-7/tx_maxrate
    echo 212 > /sys/class/net/eth0/queues/tx-6/tx_maxrate

    tc qdisc add dev eth0.100 clsact
    tc filter add dev eth0.100 egress protocol ip prio 1 u32 match ip dport 5001 0xffff action skbedit priority 7
    tc filter add dev eth0.100 egress protocol ip prio 1 u32 match ip dport 5002 0xffff action skbedit priority 6

    tc qdisc add dev eth0 parent root handle 100: mqprio num_tc 3 \
    map 0 0 0 0 0 0 1 2 0 0 0 0 0 0 0 0 \
    queues 1@0 1@6 1@7 hw 1 mode channel \
    shaper bw_rlimit min_rate 101mbit 213mbit 107mbit max_rate 102mbit 214mbit 108mbit

3. Create and run the following scripts on J7VCL:

::

    #!/bin/sh

    ip link add link eth1 name eth1.100 type vlan id 100
    sleep 5
    ifconfig eth1.100 192.168.1.2 netmask 255.255.255.0
    sleep 2
    iperf3 -s -p 5001&
    iperf3 -s -p 5002&
    iperf3 -s -p 5003&

4. Now, run the iperf client on AM64-SK using the following commands:

::

    iperf3 -c 192.168.1.2 -u -b108M -t10 -p5001 -Tpri7 & \
    iperf3 -c 192.168.1.2 -u -b214M -t10 -p5002 -Tpri6 & \
    iperf3 -c 192.168.1.2 -u -b102M -t10 -p5003 -Tpri0

**Results:**

::

    pri7:  - - - - - - - - - - - - - - - - - - - - - - - - -
    pri7:  [ ID] Interval           Transfer     Bitrate         Jitter    Lost/Total Datagrams
    pri7:  [  5]   0.00-10.00  sec   120 MBytes   101 Mbits/sec  0.000 ms  0/87099 (0%)  sender
    pri7:  [  5]   0.00-10.01  sec   115 MBytes  96.6 Mbits/sec  0.027 ms  3682/87099 (4.2%)  receiver
    pri7:
    pri7:  iperf Done.
    pri6:  - - - - - - - - - - - - - - - - - - - - - - - - -
    pri6:  [ ID] Interval           Transfer     Bitrate         Jitter    Lost/Total Datagrams
    pri6:  [  5]   0.00-10.00  sec   241 MBytes   202 Mbits/sec  0.000 ms  0/174308 (0%)  sender
    pri6:  [  5]   0.00-10.00  sec   228 MBytes   191 Mbits/sec  0.104 ms  9203/174308 (5.3%)  receiver
    pri6:
    pri6:  iperf Done.
    pri0:  - - - - - - - - - - - - - - - - - - - - - - - - -
    pri0:  [ ID] Interval           Transfer     Bitrate         Jitter    Lost/Total Datagrams
    pri0:  [  5]   0.00-10.00  sec   116 MBytes  97.3 Mbits/sec  0.000 ms  0/84000 (0%)  sender
    pri0:  [  5]   0.00-10.00  sec   114 MBytes  95.3 Mbits/sec  0.028 ms  1700/83958 (2%)  receiver
    pri0:
    pri0:  iperf Done.

Rate-limiting Switch Egress on J7VCL (Data sent from AM64-SK to AM625-SK via J7VCL switch)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Connect AM64-SK's eth0 to J7VCL's eth1 and AM625-SK's eth0 to J7VCL's eth2.

**Steps:**

1. Create and run the following script on J7VCL:

::

    #!/bin/sh
    ifconfig eth1 down
    ifconfig eth2 down
    ifconfig eth3 down
    ifconfig eth4 down
    ethtool -L eth2 tx 8
    ethtool --set-priv-flags eth2 p0-rx-ptype-rrobin off

    devlink dev param set platform/c000000.ethernet name switch_mode value true cmode runtime
    ip link add name br0 type bridge
    ip link set dev br0 type bridge ageing_time 1000
    ip link set dev eth1 up
    ip link set dev eth2 up
    sleep 10

    ip link set dev eth1 master br0
    ip link set dev eth2 master br0
    ip link set dev br0 up
    ip link set dev br0 type bridge vlan_filtering 1
    bridge vlan add dev br0 vid 1 pvid untagged self
    bridge vlan add dev eth1 vid 100 master
    bridge vlan add dev eth2 vid 100 master


    tc qdisc add dev eth2 parent root handle 100: mqprio num_tc 3 \
    map 0 0 0 0 0 0 1 2 0 0 0 0 0 0 0 0 \
    queues 1@0 1@6 1@7 hw 1 mode channel \
    shaper bw_rlimit min_rate 99mbit 211mbit 105mbit max_rate 100mbit 212mbit 106mbit

2. Create and run the following script on AM64-SK:

::

    #!/bin/sh

    ifconfig eth0 down
    ifconfig eth1 down
    ethtool -L eth0 tx 8
    ifconfig eth0 up
    sleep 5

    ip link add link eth0 name eth0.100 type vlan id 100
    ip link set eth0.100 type vlan egress 0:0 1:1 2:2 3:3 4:4 5:5 6:6 7:7
    sleep 5
    ifconfig eth0.100 192.168.1.1 netmask 255.255.255.0
    sleep 2

    echo 106 > /sys/class/net/eth0/queues/tx-7/tx_maxrate
    echo 212 > /sys/class/net/eth0/queues/tx-6/tx_maxrate

    tc qdisc add dev eth0.100 clsact
    tc filter add dev eth0.100 egress protocol ip prio 1 u32 match ip dport 5001 0xffff action skbedit priority 7
    tc filter add dev eth0.100 egress protocol ip prio 1 u32 match ip dport 5002 0xffff action skbedit priority 6

    tc qdisc add dev eth0 parent root handle 100: mqprio num_tc 3 \
    map 0 0 0 0 0 0 1 2 0 0 0 0 0 0 0 0 \
    queues 1@0 1@6 1@7 hw 1 mode channel \
    shaper bw_rlimit min_rate 101mbit 213mbit 107mbit max_rate 102mbit 214mbit 108mbit

3. Create and run the following script on AM625-SK:

::

    #!/bin/sh

    ip link add link eth0 name eth0.100 type vlan id 100
    sleep 5
    ifconfig eth0.100 192.168.1.2 netmask 255.255.255.0
    sleep 2
    iperf3 -s -p 5001&
    iperf3 -s -p 5002&
    iperf3 -s -p 5003&

4. Now, run the iperf client on AM64-SK using the following commands:

::

    iperf3 -c 192.168.1.2 -u -b108M -t10 -p5001 -Tpri7 & \
    iperf3 -c 192.168.1.2 -u -b214M -t10 -p5002 -Tpri6 & \
    iperf3 -c 192.168.1.2 -u -b102M -t10 -p5003 -Tpri0

**Results:**

::

    pri6:  - - - - - - - - - - - - - - - - - - - - - - - - -
    pri6:  [ ID] Interval           Transfer     Bitrate         Jitter    Lost/Total Datagrams
    pri6:  [  5]   0.00-10.00  sec   240 MBytes   201 Mbits/sec  0.000 ms  0/173574 (0%)  sender
    pri6:  [  5]   0.00-10.03  sec   215 MBytes   180 Mbits/sec  0.083 ms  18116/173574 (10%)  receiver
    pri6:
    pri6:  iperf Done.
    pri7:  - - - - - - - - - - - - - - - - - - - - - - - - -
    pri7:  [ ID] Interval           Transfer     Bitrate         Jitter    Lost/Total Datagrams
    pri7:  [  5]   0.00-10.00  sec   120 MBytes   101 Mbits/sec  0.000 ms  0/86842 (0%)  sender
    pri7:  [  5]   0.00-10.05  sec   117 MBytes  97.5 Mbits/sec  0.010 ms  2279/86842 (2.6%)  receiver
    pri7:
    pri7:  iperf Done.
    pri0:  - - - - - - - - - - - - - - - - - - - - - - - - -
    pri0:  [ ID] Interval           Transfer     Bitrate         Jitter    Lost/Total Datagrams
    pri0:  [  5]   0.00-10.00  sec   116 MBytes  97.2 Mbits/sec  0.000 ms  0/83913 (0%)  sender
    pri0:  [  5]   0.00-10.01  sec   113 MBytes  95.1 Mbits/sec  0.009 ms  1683/83848 (2%)  receiver
    pri0:
    pri0:  iperf Done.
