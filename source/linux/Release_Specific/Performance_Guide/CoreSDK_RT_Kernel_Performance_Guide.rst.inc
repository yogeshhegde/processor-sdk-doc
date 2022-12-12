..  http://processors.wiki.ti.com/index.php/CoreSDK_Linux_RT_Kernel_Performance_Guide


======================================
 RT-linux 08.05.00 Performance Guide
======================================

.. rubric::  **Read This First**
   :name: read-this-first-rt-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+---------------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                         |
+================+=====================================================================================================================+
| AM64x EVM      | AM64x Evaluation Module rev E1 with ARM running at 1GHz, DDR data rate 1600 MT/S                                    |
+----------------+---------------------------------------------------------------------------------------------------------------------+


Table:  Evaluation Modules

|

.. rubric::  About This Manual
   :name: about-this-manual-rt-kernel-perf-guide

This document provides performance data for each of the device drivers
which are part of the Process SDK Linux package. This document should be
used in conjunction with release notes and user guides provided with the
Process SDK Linux package for information on specific issues present
with drivers included in a particular release.

.. rubric::  If You Need Assistance
   :name: if-you-need-assistance-rt-kernel-perf-guide

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
    "dhrystone_per_mhz (DMIPS/MHz)","3.00"
    "dhrystone_per_second (DhrystoneP)","5263158.00"


Table:  **Dhrystone Benchmark**



Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am64xx-hsevm: perf"

    "whetstone (MIPS)","5000.00"


Table:  **Whetstone Benchmark**








 



 
 

 

 

 



 

 

 


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

    "netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_MAERTS","182.62","54.53"

Table: **ICSSG TCP Bidirectional Throughput**

|



.. rubric::  UDP Throughput 
   :name: udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-hsevm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","7.71","87.73"
    "128","82.00","34.93","87.12"
    "256","210.00","87.26","86.74"
    "1024","978.00","93.65","28.07"
    "1518","1472.00","12.95","1.07"

Table: **ICSSG UDP Egress Throughput**

|



.. csv-table::
    :header: "Frame Size(bytes)","am64xx-hsevm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: CPU Load %"

    "128","82.00","4.79","6.25"
    "256","210.00","13.61","11.26"
    "1518","1472.00","101.27","22.72"

Table: **ICSSG UDP Ingress Throughput (0% loss)**

|
 
 
 

 

 

 

 



 

 

 


UART Driver
-------------------------

Performance and Benchmarks not available in this release.

|

I2C Driver
-------------------------

Performance and Benchmarks not available in this release.

|

EDMA Driver
-------------------------

Performance and Benchmarks not available in this release.

|

Touchscreen Driver
-------------------------

Performance and Benchmarks not available in this release.

|

  


CRYPTO Driver
-------------------------


OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am64xx-hsevm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","19115.69"
    "aes-128-cbc","16","315.56"
    "aes-128-cbc","16384","133715.29"
    "aes-128-cbc","256","5069.14"
    "aes-128-cbc","64","1242.15"
    "aes-128-cbc","8192","95073.62"
    "aes-192-cbc","1024","18768.90"
    "aes-192-cbc","16","313.53"
    "aes-192-cbc","16384","124512.94"
    "aes-192-cbc","256","4968.70"
    "aes-192-cbc","64","1259.48"
    "aes-192-cbc","8192","89221.80"
    "aes-256-cbc","1024","18947.41"
    "aes-256-cbc","16","313.94"
    "aes-256-cbc","16384","118827.69"
    "aes-256-cbc","256","4989.70"
    "aes-256-cbc","64","1255.45"
    "aes-256-cbc","8192","86502.06"
    "des-cbc","1024","18385.24"
    "des-cbc","16","3327.00"
    "des-cbc","16384","19671.72"
    "des-cbc","256","15153.92"
    "des-cbc","64","8863.38"
    "des-cbc","8192","19589.80"
    "des3","1024","7784.79"
    "des3","16","2621.05"
    "des3","16384","8006.31"
    "des3","256","7118.93"
    "des3","64","5304.75"
    "des3","8192","7962.62"
    "md5","1024","32986.45"
    "md5","16","697.15"
    "md5","16384","106157.40"
    "md5","256","10225.24"
    "md5","64","2706.62"
    "md5","8192","92476.76"
    "sha1","1024","38778.54"
    "sha1","16","667.54"
    "sha1","16384","240866.65"
    "sha1","256","10428.07"
    "sha1","64","2650.18"
    "sha1","8192","176196.27"
    "sha224","1024","38411.26"
    "sha224","16","663.64"
    "sha224","16384","245727.23"
    "sha224","256","10264.92"
    "sha224","64","2642.90"
    "sha224","8192","179041.62"
    "sha256","1024","23579.65"
    "sha256","16","390.46"
    "sha256","16384","195805.18"
    "sha256","256","6143.91"
    "sha256","64","1552.47"
    "sha256","8192","130979.16"
    "sha384","1024","23836.33"
    "sha384","16","639.47"
    "sha384","16384","52144.81"
    "sha384","256","8699.39"
    "sha384","64","2564.52"
    "sha384","8192","48278.19"
    "sha512","1024","17529.86"
    "sha512","16","393.03"
    "sha512","16384","49561.60"
    "sha512","256","5683.88"
    "sha512","64","1576.21"
    "sha512","8192","43980.12"


|
|



.. csv-table::
    :header: "Algorithm","am64xx-hsevm: CPU Load"

    "aes-128-cbc","43.00"
    "aes-192-cbc","42.00"
    "aes-256-cbc","41.00"
    "des-cbc","97.00"
    "des3","97.00"
    "md5","97.00"
    "sha1","97.00"
    "sha224","97.00"
    "sha256","97.00"
    "sha384","97.00"
    "sha512","97.00"

 

|
| Listed for each algorithm are the code snippets used to run each
  benchmark test.

|

::
    time -v openssl speed -elapsed -evp aes-128-cbc

 




IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am64xx-hsevm: Throughput (Mbps)","am64xx-hsevm: Packets/Sec","am64xx-hsevm: CPU Load"

    "3des","52.50","4.00","53.48"

 
 

 

DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.

    

