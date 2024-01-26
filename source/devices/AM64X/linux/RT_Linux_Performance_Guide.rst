===========================
 RT-linux Performance Guide
===========================

.. rubric::  **Read This First**

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+---------------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                         |
+================+=====================================================================================================================+
| AM64x EVM      | AM64x Starter Kit rev A with ARM running at 1GHz, LPDDR4 data rate 1600 MT/S                                        |
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

LMBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
LMBench is a collection of microbenchmarks of which the memory bandwidth 
and latency related ones are typically used to estimate processor 
memory system performance. More information about lmbench at 
http://lmbench.sourceforge.net/whatis_lmbench.html and
http://lmbench.sourceforge.net/man/lmbench.8.html

  
**Latency**: lat_mem_rd-stride128-szN, where N is equal to or smaller than the cache
size at given level measures the cache miss penalty. N that is at least
double the size of last level cache is the latency to external memory.

**Bandwidth**: bw_mem_bcopy-N, where N is equal to or smaller than the cache size at
a given level measures the achievable memory bandwidth from software doing
a memcpy() type operation. Typical use is for external memory bandwidth
calculation. The bandwidth is calculated as byte read and written counts
as 1 which should be roughly half of STREAM copy result.

Execute the LMBench with the following:

::

    cd /opt/ltp
    ./runltp -P j721e-idk-gw -f ddt/lmbench -s LMBENCH_L_PERF_0001

.. csv-table::
    :header: "Benchmarks","am64xx-hsevm: perf"

    "af_unix_sock_stream_latency (microsec)","34.49"
    "af_unix_socket_stream_bandwidth (MBs)","578.92"
    "bw_file_rd-io-1mb (MB/s)","840.90"
    "bw_file_rd-o2c-1mb (MB/s)","510.55"
    "bw_mem-bcopy-16mb (MB/s)","851.38"
    "bw_mem-bcopy-1mb (MB/s)","997.21"
    "bw_mem-bcopy-2mb (MB/s)","941.62"
    "bw_mem-bcopy-4mb (MB/s)","956.71"
    "bw_mem-bcopy-8mb (MB/s)","976.80"
    "bw_mem-bzero-16mb (MB/s)","2119.77"
    "bw_mem-bzero-1mb (MB/s)","1559.24 (min 997.21, max 2121.27)"
    "bw_mem-bzero-2mb (MB/s)","1529.76 (min 941.62, max 2117.90)"
    "bw_mem-bzero-4mb (MB/s)","1537.31 (min 956.71, max 2117.90)"
    "bw_mem-bzero-8mb (MB/s)","1547.72 (min 976.80, max 2118.64)"
    "bw_mem-cp-16mb (MB/s)","520.16"
    "bw_mem-cp-1mb (MB/s)","659.86 (min 529.57, max 790.14)"
    "bw_mem-cp-2mb (MB/s)","686.72 (min 578.95, max 794.49)"
    "bw_mem-cp-4mb (MB/s)","689.96 (min 556.95, max 822.96)"
    "bw_mem-cp-8mb (MB/s)","707.95 (min 576.70, max 839.19)"
    "bw_mem-fcp-16mb (MB/s)","891.81"
    "bw_mem-fcp-1mb (MB/s)","1615.27 (min 1109.26, max 2121.27)"
    "bw_mem-fcp-2mb (MB/s)","1601.25 (min 1084.60, max 2117.90)"
    "bw_mem-fcp-4mb (MB/s)","1612.51 (min 1107.11, max 2117.90)"
    "bw_mem-fcp-8mb (MB/s)","1615.50 (min 1112.35, max 2118.64)"
    "bw_mem-frd-16mb (MB/s)","1261.23"
    "bw_mem-frd-1mb (MB/s)","1187.09 (min 1109.26, max 1264.91)"
    "bw_mem-frd-2mb (MB/s)","1208.97 (min 1084.60, max 1333.33)"
    "bw_mem-frd-4mb (MB/s)","1209.62 (min 1107.11, max 1312.12)"
    "bw_mem-frd-8mb (MB/s)","1197.41 (min 1112.35, max 1282.46)"
    "bw_mem-fwr-16mb (MB/s)","837.52"
    "bw_mem-fwr-1mb (MB/s)","1027.53 (min 790.14, max 1264.91)"
    "bw_mem-fwr-2mb (MB/s)","1063.91 (min 794.49, max 1333.33)"
    "bw_mem-fwr-4mb (MB/s)","1067.54 (min 822.96, max 1312.12)"
    "bw_mem-fwr-8mb (MB/s)","1060.83 (min 839.19, max 1282.46)"
    "bw_mem-rd-16mb (MB/s)","1353.75"
    "bw_mem-rd-1mb (MB/s)","1108.24 (min 854.55, max 1361.93)"
    "bw_mem-rd-2mb (MB/s)","1103.44 (min 847.94, max 1358.93)"
    "bw_mem-rd-4mb (MB/s)","1110.83 (min 855.07, max 1366.59)"
    "bw_mem-rd-8mb (MB/s)","1120.03 (min 890.08, max 1349.98)"
    "bw_mem-rdwr-16mb (MB/s)","874.17"
    "bw_mem-rdwr-1mb (MB/s)","682.15 (min 529.57, max 834.72)"
    "bw_mem-rdwr-2mb (MB/s)","692.92 (min 578.95, max 806.89)"
    "bw_mem-rdwr-4mb (MB/s)","697.85 (min 556.95, max 838.75)"
    "bw_mem-rdwr-8mb (MB/s)","714.84 (min 576.70, max 852.97)"
    "bw_mem-wr-16mb (MB/s)","891.91"
    "bw_mem-wr-1mb (MB/s)","844.64 (min 834.72, max 854.55)"
    "bw_mem-wr-2mb (MB/s)","827.42 (min 806.89, max 847.94)"
    "bw_mem-wr-4mb (MB/s)","846.91 (min 838.75, max 855.07)"
    "bw_mem-wr-8mb (MB/s)","871.53 (min 852.97, max 890.08)"
    "bw_mmap_rd-mo-1mb (MB/s)","1301.60"
    "bw_mmap_rd-o2c-1mb (MB/s)","503.61"
    "bw_pipe (MB/s)","528.22"
    "bw_unix (MB/s)","578.92"
    "lat_connect (us)","77.65"
    "lat_ctx-2-128k (us)","6.01"
    "lat_ctx-2-256k (us)","15.74"
    "lat_ctx-4-128k (us)","7.02"
    "lat_ctx-4-256k (us)","10.76"
    "lat_fs-0k (num_files)","231.00"
    "lat_fs-10k (num_files)","91.00"
    "lat_fs-1k (num_files)","138.00"
    "lat_fs-4k (num_files)","138.00"
    "lat_mem_rd-stride128-sz1000k (ns)","48.10"
    "lat_mem_rd-stride128-sz125k (ns)","7.84"
    "lat_mem_rd-stride128-sz250k (ns)","10.53"
    "lat_mem_rd-stride128-sz31k (ns)","3.06"
    "lat_mem_rd-stride128-sz50 (ns)","3.01"
    "lat_mem_rd-stride128-sz500k (ns)","44.07"
    "lat_mem_rd-stride128-sz62k (ns)","7.37"
    "lat_mmap-1m (us)","75.00"
    "lat_ops-double-add (ns)","4.02"
    "lat_ops-double-div (ns)","22.11"
    "lat_ops-double-mul (ns)","4.02"
    "lat_ops-float-add (ns)","4.02"
    "lat_ops-float-div (ns)","13.06"
    "lat_ops-float-mul (ns)","4.02"
    "lat_ops-int-add (ns)","1.01"
    "lat_ops-int-bit (ns)","0.67"
    "lat_ops-int-div (ns)","6.03"
    "lat_ops-int-mod (ns)","6.37"
    "lat_ops-int-mul (ns)","4.33"
    "lat_ops-int64-add (ns)","1.01"
    "lat_ops-int64-bit (ns)","0.67"
    "lat_ops-int64-div (ns)","9.55"
    "lat_ops-int64-mod (ns)","7.37"
    "lat_ops-int64-mul (ns)","4.99"
    "lat_pagefault (us)","1.46"
    "lat_pipe (us)","21.32"
    "lat_proc-exec (us)","1189.20"
    "lat_proc-fork (us)","963.00"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","43.00"
    "lat_sem (us)","2.74"
    "lat_sig-catch (us)","5.89"
    "lat_sig-install (us)","0.90"
    "lat_sig-prot (us)","0.67"
    "lat_syscall-fstat (us)","4.36"
    "lat_syscall-null (us)","0.58"
    "lat_syscall-open (us)","286.84"
    "lat_syscall-read (us)","0.97"
    "lat_syscall-stat (us)","5.62"
    "lat_syscall-write (us)","0.80"
    "lat_tcp (us)","1.13"
    "lat_unix (us)","34.49"
    "latency_for_0.50_mb_block_size (nanosec)","44.07"
    "latency_for_1.00_mb_block_size (nanosec)","24.05 (min 0.00, max 48.10)"
    "pipe_bandwidth (MBs)","528.22"
    "pipe_latency (microsec)","21.32"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","43.00"
    "semaphore_latency (microsec)","2.74"
    "signal_handler_latency (microsec)","0.90"
    "signal_handler_overhead (microsec)","5.89"
    "tcp_ip_connection_cost_to_localhost (microsec)","77.65"
    "tcp_latency_using_localhost (microsec)","1.13"


Table:  **LM Bench Metrics**



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



Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am64xx-hsevm: perf"

    "whetstone (MIPS)","5000.00"


Table:  **Whetstone Benchmark**



Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am64xx-hsevm: perf"

    "linpack (Kflops)","410097.00"


Table:  **Linpack Benchmark**


CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.


.. csv-table::
    :header: "Benchmarks","am64xx-hsevm: perf"

    "cjpeg-rose7-preset (workloads/)","29.85"
    "core (workloads/)","0.21"
    "coremark-pro ()","587.59"
    "linear_alg-mid-100x100-sp (workloads/)","10.43"
    "loops-all-mid-10k-sp (workloads/)","0.49"
    "nnet_test (workloads/)","0.77"
    "parser-125k (workloads/)","5.56"
    "radix2-big-64k (workloads/)","19.28"
    "sha-test (workloads/)","58.14"
    "zip-test (workloads/)","15.38"


Table:  **CoreMarkPro**

| 

Stress-ng and Cyclic Test
^^^^^^^^^^^^^^^^^^^^^^^^^

.. _RT-linux-performance:

stress-ng (next-generation) will stress test a embedded platform in various selectable ways.
It was designed to exercise various physical subsystems as well as the various
operating system kernel interfaces. stress-ng can also measure test throughput rates;
this can be useful to observe performance changes across different operating system or types of hardware.

Cyclictest is most commonly used for benchmarking RT systems.
It is one of the most frequently used tools for evaluating the relative performance of real-time systems.
Some performance tests which use Cyclictest are System benchmarking, Latency debugging with tracing and
approximating application performance.

Test command for running stress-ng and cyclictest together

``stress-ng --cpu-method=all -c 4 &``

``cyclictest -m -Sp98 -D6h -h400 -i200 -q``

.. csv-table::
    :header: "Latencies", "am64xx-hsevm:per-core"

     "Minimum (usec)","5,5"
    "Average (usec)","7,7"
    "Maximum (usec)","72,48"
 

Table:  **Stress-ng and Cyclic Test**


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


CPSW/CPSW2g/CPSW3g Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- CPSW3g: AM64x


.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1148.97","73.07"

Table: **CPSW TCP Bidirectional Throughput**

|


.. rubric::  UDP Throughput 
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-hsevm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: Packets Per Second (kPPS)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","12.62","88.00","89.72"
    "128","82.00","53.57","82.00","86.97"
    "256","210.00","130.25","78.00","89.70"
    "1024","978.00","108.73","14.00","18.98"
    "1518","1472.00","944.16","80.00","93.31"

Table: **CPSW UDP Egress Throughput**

|



.. csv-table::
    :header: "Frame Size(bytes)","am64xx-hsevm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: Packets Per Second (kPPS)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.22","8.00","7.88"
    "128","82.00","5.58","9.00","8.38"
    "256","210.00","13.78","8.00","0.98"
    "1024","978.00","75.89","10.00","8.46"
    "1518","1472.00","115.40","10.00","8.97"

Table: **CPSW UDP Ingress Throughput (0% loss)**

|



.. csv-table::
    :header: "Frame Size(bytes)","am64xx-hsevm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: Packets Per Second (kPPS)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)","am64xx-hsevm: Packet Loss %"

    "64","18.00","19.67","137.00","76.58","77.46"
    "128","82.00","88.72","135.00","79.04","75.23"
    "256","210.00","222.84","133.00","82.94","70.27"
    "1024","978.00","889.55","114.00","87.28","5.04"
    "1518","1472.00","902.13","77.00","81.60","4.88"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|
 
 


ICSSG Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput 
   :name: tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_MAERTS","235.83","77.11"

Table: **ICSSG TCP Bidirectional Throughput**

|



.. rubric::  TCP Bidirectional Throughput Interrupt Pacing
   :name: ICSSG-tcp-bidirectional-throughput-interrupt-pacing

.. csv-table::
    :header: "Command Used","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_MAERTS","240.18","58.85"

Table: **ICSSG TCP Bidirectional Throughput Interrupt Pacing**

|





.. csv-table::
    :header: "Frame Size(bytes)","am64xx-hsevm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: Packets Per Second (kPPS)","am64xx-hsevm: CPU Load %"

    "64","18.00","1.93","13.00","22.35"
    "128","82.00","13.71","21.00","22.53"
    "256","210.00","40.49","24.00","13.07"
    "1518","1472.00","314.02","27.00","63.21"

Table: **ICSSG UDP Ingress Throughput (0% loss)**

|
 
 
 


PCIe Driver
-------------------------

PCIe-ETH
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "TCP Window Size(Kbytes)","am64xx-hsevm: Bandwidth (Mbits/sec)"

    "8","197.60"
    "16","193.60"
    "32","339.20"
    "64","519.20"
    "128","688.80"
    "256","792.80"

Table: **PCI Ethernet**


 
 

 




EMMC Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

|

 
 

 


AM64XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-hsevm: Write EXT4 Throughput (Mbytes/sec)","am64xx-hsevm: Write EXT4 CPU Load (%)","am64xx-hsevm: Read EXT4 Throughput (Mbytes/sec)","am64xx-hsevm: Read EXT4 CPU Load (%)"

    "1m","60.90","3.32","175.00","5.85"
    "4m","61.10","2.51","175.00","4.71"
    "4k","48.50","51.42","55.50","52.60"
    "256k","60.80","5.05","174.00","7.20"

|



 

 


MMC/SD Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

| 

 

 


AM64XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-hsevm: Write EXT4 Throughput (Mbytes/sec)","am64xx-hsevm: Write EXT4 CPU Load (%)","am64xx-hsevm: Read EXT4 Throughput (Mbytes/sec)","am64xx-hsevm: Read EXT4 CPU Load (%)"

    "1m","18.10","1.39","86.50","3.71"
    "4m","17.60","1.07","86.40","2.72"
    "4k","4.51","9.00","16.20","18.19"
    "256k","17.20","1.99","84.00","4.77"

|


 

 

 

 

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|
 

  


CRYPTO Driver
-------------------------


OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am64xx-hsevm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","22739.29"
    "aes-128-cbc","16","378.75"
    "aes-128-cbc","16384","143851.52"
    "aes-128-cbc","256","6019.33"
    "aes-128-cbc","64","1508.22"
    "aes-128-cbc","8192","104630.95"
    "aes-128-ecb","1024","24544.60"
    "aes-128-ecb","16","398.81"
    "aes-128-ecb","16384","147860.14"
    "aes-128-ecb","256","6688.51"
    "aes-128-ecb","64","1671.17"
    "aes-128-ecb","8192","107479.04"
    "aes-192-cbc","1024","23729.15"
    "aes-192-cbc","16","409.47"
    "aes-192-cbc","16384","134272.34"
    "aes-192-cbc","256","6536.36"
    "aes-192-cbc","64","1659.58"
    "aes-192-cbc","8192","100264.62"
    "aes-192-ecb","1024","23268.69"
    "aes-192-ecb","16","416.16"
    "aes-192-ecb","16384","138996.39"
    "aes-192-ecb","256","6693.55"
    "aes-192-ecb","64","1668.74"
    "aes-192-ecb","8192","103675.22"
    "aes-256-cbc","1024","21606.40"
    "aes-256-cbc","16","406.22"
    "aes-256-cbc","16384","126844.93"
    "aes-256-cbc","256","6054.23"
    "aes-256-cbc","64","1509.59"
    "aes-256-cbc","8192","96400.73"
    "aes-256-ecb","1024","24218.28"
    "aes-256-ecb","16","419.88"
    "aes-256-ecb","16384","130389.33"
    "aes-256-ecb","256","6658.39"
    "aes-256-ecb","64","1684.99"
    "aes-256-ecb","8192","98375.00"
    "sha256","1024","24721.07"
    "sha256","16","412.99"
    "sha256","16384","197940.57"
    "sha256","256","6479.53"
    "sha256","64","1634.05"
    "sha256","8192","133772.63"
    "sha512","1024","17315.84"
    "sha512","16","401.58"
    "sha512","16384","46945.62"
    "sha512","256","5716.57"
    "sha512","64","1604.86"
    "sha512","8192","42052.27"


|
|



.. csv-table::
    :header: "Algorithm","am64xx-hsevm: CPU Load"

    "aes-128-cbc","44.00"
    "aes-128-ecb","46.00"
    "aes-192-cbc","45.00"
    "aes-192-ecb","45.00"
    "aes-256-cbc","43.00"
    "aes-256-ecb","45.00"
    "sha256","97.00"
    "sha512","97.00"

 

|
| Listed for each algorithm are the code snippets used to run each
  benchmark test.

|





IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am64xx-hsevm: Throughput (Mbps)","am64xx-hsevm: Packets/Sec","am64xx-hsevm: CPU Load"

    "3des","53.00","4.00","51.59"
    "aes128","0.70","0.00","56.73"
    "aes256","3.00","0.00","42.79"
