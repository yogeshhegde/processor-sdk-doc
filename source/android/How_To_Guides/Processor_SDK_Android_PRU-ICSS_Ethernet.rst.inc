*********************************************************************************
How to enable the PRU Ethernet ports on AM57xx IDK board
*********************************************************************************

Starting from Processor SDK Android 05.02.00 release, PRU Ethernet ports have been
enabled by default for the AM57xx IDK boards.

The PRU Ethernet firmware can be found from the filesystem at the location below:

.. code-block:: console

   am57xevm:/ # ls -l /vendor/firmware/ti-pruss/
   total 24
   -rw-r--r-- 1 root root 5028 2018-12-21 17:40 am57xx-pru0-prueth-fw.elf
   -rw-r--r-- 1 root root 5060 2018-12-21 17:40 am57xx-pru1-prueth-fw.elf

The related kernel modules are listed below:

.. code-block:: console

   am57xevm:/ # lsmod | grep pru
   prueth                 20480  0
   pru_rproc              20480  1 prueth
   pruss                  16384  2 prueth,pru_rproc
   pruss_intc             16384  5 pru_rproc
   pruss_soc_bus          16384  0


With only eth2 (pruss2-eth port 0) plugged in when booting the EVM, the eth2 port gets the IP address dynamically assigned, e.g.,

.. code-block:: console

   eth2      Link encap:Ethernet  HWaddr 9a:34:d8:2f:36:cf  Driver prueth
             inet addr:192.168.0.241  Bcast:192.168.0.255  Mask:255.255.255.0
             inet6 addr: fe80::f072:bd3a:d883:a695/64 Scope: Link
             UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
             RX packets:176 errors:0 dropped:0 overruns:0 frame:0
             TX packets:186 errors:0 dropped:0 overruns:0 carrier:0
             collisions:0 txqueuelen:1000
             RX bytes:15810 TX bytes:16520

Plug in an Ethernet cable to eth3 (pruss2-eth port 1), and a static IP address can be assigned by running the commands below, e.g.,

.. code-block:: console

       ip addr add 192.168.0.112 dev eth3  [note: assign static IP address 192.168.0.112 for eth3]
       ip link set eth3 up
       ifconfig
       ip route add 192.168.0.0/24 dev eth3
       ip route add default via 192.168.0.216 dev eth3  [note: 192.168.0.216 is the IP address of the host PC]
       ip rule add from all lookup main pref 99

Plug in an Ethernet cable to eth0 (CPSW port 1) , and a static IP address can be assigned as follows:


.. code-block:: console

       ip addr add 192.168.0.110 dev eth0  [note: static IP address 192.168.0.110 for eth0]
       ip link set eth0 up

After the steps above, ifconfig shows all the three ports: eth0, eth2, and eth3. All the three ports can be pinged from the host PC also.

.. code-block:: console

   am57xevm:/ # ifconfig
   lo        Link encap:Local Loopback
             inet addr:127.0.0.1  Mask:255.0.0.0
             inet6 addr: ::1/128 Scope: Host
             UP LOOPBACK RUNNING  MTU:65536  Metric:1
             RX packets:0 errors:0 dropped:0 overruns:0 frame:0
             TX packets:0 errors:0 dropped:0 overruns:0 carrier:0
             collisions:0 txqueuelen:1000
             RX bytes:0 TX bytes:0

   eth3      Link encap:Ethernet  HWaddr b2:cd:fa:17:b7:51  Driver prueth
             inet addr:192.168.0.112  Bcast:0.0.0.0  Mask:255.255.255.255
             inet6 addr: fe80::b0cd:faff:fe17:b751/64 Scope: Link
             UP BROADCAST MULTICAST  MTU:1500  Metric:1
             RX packets:36 errors:0 dropped:0 overruns:0 frame:0
             TX packets:11 errors:0 dropped:0 overruns:0 carrier:0
             collisions:0 txqueuelen:1000
             RX bytes:3693 TX bytes:838

   eth2      Link encap:Ethernet  HWaddr 9a:34:d8:2f:36:cf  Driver prueth
             inet addr:192.168.0.241  Bcast:192.168.0.255  Mask:255.255.255.0
             inet6 addr: fe80::f072:bd3a:d883:a695/64 Scope: Link
             UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
             RX packets:328 errors:0 dropped:0 overruns:0 frame:0
             TX packets:320 errors:0 dropped:0 overruns:0 carrier:0
             collisions:0 txqueuelen:1000
             RX bytes:35558 TX bytes:27916

   eth0      Link encap:Ethernet  HWaddr a0:f6:fd:ae:a8:70  Driver cpsw
             inet addr:192.168.0.110  Bcast:0.0.0.0  Mask:255.255.255.255
             inet6 addr: fe80::a2f6:fdff:feae:a870/64 Scope: Link
             UP BROADCAST RUNNING MULTICAST  MTU:1500  Metric:1
             RX packets:49 errors:0 dropped:0 overruns:0 frame:0
             TX packets:15 errors:0 dropped:0 overruns:0 carrier:0
             collisions:0 txqueuelen:1000
             RX bytes:4431 TX bytes:1134
             Interrupt:85
