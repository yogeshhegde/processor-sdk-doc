===========================
 RT-linux Performance Guide
===========================

.. rubric::  **Read This First**

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+---------------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                         |
+================+=====================================================================================================================+
| AM64x EVM      | AM64x SR2.0 Evaluation Module rev C with ARM running at 1GHz, DDR data rate 1600 MT/S                               |
+----------------+---------------------------------------------------------------------------------------------------------------------+

Table:  Evaluation Modules

.. rubric::  About This Manual

This document provides performance data for each of the device drivers
which are part of the Process SDK Linux package. This document should be
used in conjunction with release notes and user guides provided with the
Process SDK Linux package for information on specific issues present
with drivers included in a particular release.

.. rubric::  If You Need Assistance

For further information or to report any problems, contact
http://e2e.ti.com/ or http://support.ti.com/

System Benchmarks
-------------------------

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

.. csv-table::
    :header: "Benchmarks","am64xx-hsevm: perf"

    "cpu_clock (MHz)","1000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.90"
    "dhrystone_per_second (DhrystoneP)","5128205.00"


Table:  **Dhrystone Benchmark**

|

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am64xx-hsevm: perf"

    "whetstone (MIPS)","5000.00"


Table:  **Whetstone Benchmark**


Cyclictest
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Cyclictest is most commonly used for benchmarking RT systems.
It is one of the most frequently used tools for evaluating the relative performance of real-time systems.
Some performance tests which use Cyclictest are System benchmarking, Latency debugging with tracing and
approximating application performance.

Test command: 
cyclictest -l10000000 -m -Sp90 -i400 -h400 -q

.. csv-table::
    :header: "Latencies", "am64xx-hsevm:per-core"

    "Minimum (usec)", "6,6"
    "Average (usec)", "8,8"
    "Maximum (usec)", "152,82"


Table:  **Cyclictest**


Ethernet
-----------------
Ethernet performance benchmarks were measured using Netperf 2.7.1 https://hewlettpackard.github.io/netperf/doc/netperf.html
Test procedures were modeled after those defined in RFC-2544:
https://tools.ietf.org/html/rfc2544, where the DUT is the TI device 
and the "tester" used was a Linux PC. To produce consistent results,
it is recommended to carry out performance tests in a private network and to avoid 
running NFS on the same interface used in the test. In these results, 
CPU utilization was captured as the total percentage used across all cores on the device,
while running the performance test over one external interface.  

UDP Throughput (0% loss) was measured by the procedure defined in RFC-2544 section 26.1: Throughput.
In this scenario, netperf options burst_size (-b) and wait_time (-w) are used to limit bandwidth
during different trials of the test, with the goal of finding the highest rate at which 
no loss is seen. For example, to limit bandwidth to 500Mbits/sec with 1472B datagram:

::

   burst_size = <bandwidth (bits/sec)> / 8 (bits -> bytes) / <UDP datagram size> / 100 (seconds -> 10 ms)
   burst_size = 500000000 / 8 / 1472 / 100 = 425 

   wait_time = 10 milliseconds (minimum supported by Linux PC used for testing)

UDP Throughput (possible loss) was measured by capturing throughput and packet loss statistics when
running the netperf test with no bandwidth limit (remove -b/-w options). 

In order to start a netperf client on one device, the other device must have netserver running.
To start netserver:

::

   netserver [-p <port_number>] [-4 (IPv4 addressing)] [-6 (IPv6 addressing)]
 
Running the following shell script from the DUT will trigger netperf clients to measure 
bidirectional TCP performance for 60 seconds and report CPU utilization. Parameter -k is used in
client commands to summarize selected statistics on their own line and -j is used to gain 
additional timing measurements during the test.  

::

   #!/bin/bash
   for i in 1
   do
      netperf -H <tester ip> -j -c -l 60 -t TCP_STREAM --
         -k DIRECTION,THROUGHPUT,MEAN_LATENCY,LOCAL_CPU_UTIL,REMOTE_CPU_UTIL,LOCAL_BYTES_SENT,REMOTE_BYTES_RECVD,LOCAL_SEND_SIZE &
      
      netperf -H <tester ip> -j -c -l 60 -t TCP_MAERTS --
         -k DIRECTION,THROUGHPUT,MEAN_LATENCY,LOCAL_CPU_UTIL,REMOTE_CPU_UTIL,LOCAL_BYTES_SENT,REMOTE_BYTES_RECVD,LOCAL_SEND_SIZE &
   done

Running the following commands will trigger netperf clients to measure UDP burst performance for 
60 seconds at various burst/datagram sizes and report CPU utilization. 

- For UDP egress tests, run netperf client from DUT and start netserver on tester.

::

   netperf -H <tester ip> -j -c -l 60 -t UDP_STREAM -b <burst_size> -w <wait_time> -- -m <UDP datagram size> 
      -k DIRECTION,THROUGHPUT,MEAN_LATENCY,LOCAL_CPU_UTIL,REMOTE_CPU_UTIL,LOCAL_BYTES_SENT,REMOTE_BYTES_RECVD,LOCAL_SEND_SIZE 

- For UDP ingress tests, run netperf client from tester and start netserver on DUT. 

::

   netperf -H <DUT ip> -j -C -l 60 -t UDP_STREAM -b <burst_size> -w <wait_time> -- -m <UDP datagram size>
      -k DIRECTION,THROUGHPUT,MEAN_LATENCY,LOCAL_CPU_UTIL,REMOTE_CPU_UTIL,LOCAL_BYTES_SENT,REMOTE_BYTES_RECVD,LOCAL_SEND_SIZE 

|


ICSSG Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput 
   :name: tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.3.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.3.1 -j -c -C -l 60 -t TCP_MAERTS","877","67.65"

Table: **ICSSG TCP Bidirectional Throughput**

|



.. rubric::  UDP Throughput 
   :name: udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-hsevm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","14.47","81.94"
    "128","82.00","68.91","81.03"
    "256","210.00","171.43","79.55"
    "1024","978.00","721.12","76.78"
    "1518","1472.00","751.92","75.12"

Table: **ICSSG UDP Egress Throughput**

|



.. csv-table::
    :header: "Frame Size(bytes)","am64xx-hsevm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: CPU Load %"

    "64","18.00","16.26","82.50"
    "128","82.00","71.19","81.43"
    "256","210.00","169.31","79.13"
    "1024","978.00","542.50","86.03"
    "1518","1472.00","806.16","88.00"

Table: **ICSSG UDP Ingress Throughput (0% loss)**

|


CRYPTO Driver
-------------------------


OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am64xx-hsevm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","20062.21"
    "aes-128-cbc","16","332.70"
    "aes-128-cbc","16384","132732.25"
    "aes-128-cbc","256","5345.11"
    "aes-128-cbc","64","1332.37"
    "aes-128-cbc","8192","95373.99"
    "aes-192-cbc","1024","19713.71"
    "aes-192-cbc","16","335.01"
    "aes-192-cbc","16384","124764.16"
    "aes-192-cbc","256","5042.69"
    "aes-192-cbc","64","1343.32"
    "aes-192-cbc","8192","91837.78"
    "aes-256-cbc","1024","19805.87"
    "aes-256-cbc","16","336.49"
    "aes-256-cbc","16384","119029.76"
    "aes-256-cbc","256","5365.16"
    "aes-256-cbc","64","1341.50"
    "aes-256-cbc","8192","88342.53"
    "des-cbc","1024","18436.44"
    "des-cbc","16","3300.41"
    "des-cbc","16384","19682.65"
    "des-cbc","256","15145.05"
    "des-cbc","64","8823.30"
    "des-cbc","8192","19567.96"
    "des3","1024","7789.57"
    "des3","16","2598.29"
    "des3","16384","8006.31"
    "des3","256","7109.97"
    "des3","64","5242.26"
    "des3","8192","7951.70"
    "md5","1024","33933.99"
    "md5","16","722.06"
    "md5","16384","106255.70"
    "md5","256","10574.51"
    "md5","64","2822.44"
    "md5","8192","93164.89"
    "sha1","1024","40485.89"
    "sha1","16","699.75"
    "sha1","16384","243750.23"
    "sha1","256","10880.85"
    "sha1","64","2779.93"
    "sha1","8192","181403.65"
    "sha224","1024","39455.74"
    "sha224","16","680.43"
    "sha224","16384","248479.74"
    "sha224","256","10603.09"
    "sha224","64","2708.10"
    "sha224","8192","182255.62"
    "sha256","1024","24089.94"
    "sha256","16","400.79"
    "sha256","16384","199360.51"
    "sha256","256","6325.08"
    "sha256","64","1599.49"
    "sha256","8192","133584.21"
    "sha384","1024","24240.81"
    "sha384","16","655.17"
    "sha384","16384","52101.12"
    "sha384","256","8866.56"
    "sha384","64","2637.61"
    "sha384","8192","48201.73"
    "sha512","1024","17496.06"
    "sha512","16","395.08"
    "sha512","16384","49479.68"
    "sha512","256","5674.07"
    "sha512","64","1576.41"
    "sha512","8192","43895.47"


|



.. csv-table::
    :header: "Algorithm","am64xx-hsevm: CPU Load"

    "aes-128-cbc","44.00"
    "aes-192-cbc","43.00"
    "aes-256-cbc","43.00"
    "des-cbc","97.00"
    "des3","97.00"
    "md5","97.00"
    "sha1","97.00"
    "sha224","97.00"
    "sha256","97.00"
    "sha384","97.00"
    "sha512","97.00"

 

|

Listed for each algorithm are the code snippets used to run each benchmark test.

::

    time -v openssl speed -elapsed -evp aes-128-cbc

|


IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am64xx-hsevm: Throughput (Mbps)","am64xx-hsevm: Packets/Sec","am64xx-hsevm: CPU Load"

    "3des","52.40","4.00","59.49"
    "aes256","91.30","8.00","36.35"

