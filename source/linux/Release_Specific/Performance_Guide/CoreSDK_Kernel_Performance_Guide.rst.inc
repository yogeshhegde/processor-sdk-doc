.. http://processors.wiki.ti.com/index.php/CoreSDK_Linux_Kernel_Performance_Guide


======================================
 Linux 08.03.00 Performance Guide
======================================

.. rubric::  **Read This First**
   :name: read-this-first-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| AM62x EVM      | AM62x Evaluation Module rev E2 with ARM running at 1200 MHz, DDR data rate 1600 MT/S                           |
+----------------+----------------------------------------------------------------------------------------------------------------+

Table:  Evaluation Modules

|

.. rubric::  About This Manual
   :name: about-this-manual-kernel-perf-guide

This document provides performance data for each of the device drivers
which are part of the Process SDK Linux package. This document should be
used in conjunction with release notes and user guides provided with the
Process SDK Linux package for information on specific issues present
with drivers included in a particular release.

.. rubric::  If You Need Assistance
   :name: if-you-need-assistance-kernel-perf-guide

For further information or to report any problems, contact
http://e2e.ti.com/ or http://support.ti.com/


System Benchmarks
-------------------


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

.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf"

    "af_unix_sock_stream_latency (microsec)","39.23"
    "af_unix_socket_stream_bandwidth (MBs)","1223.54"
    "bw_file_rd-io-1mb (MB/s)","819.94"
    "bw_file_rd-o2c-1mb (MB/s)","447.96"
    "bw_mem-bcopy-16mb (MB/s)","801.64"
    "bw_mem-bcopy-1mb (MB/s)","905.63"
    "bw_mem-bcopy-2mb (MB/s)","796.81"
    "bw_mem-bcopy-4mb (MB/s)","858.92"
    "bw_mem-bcopy-8mb (MB/s)","879.70"
    "bw_mem-bzero-16mb (MB/s)","1836.97"
    "bw_mem-bzero-1mb (MB/s)","1370.71 (min 905.63, max 1835.78)"
    "bw_mem-bzero-2mb (MB/s)","1302.08 (min 796.81, max 1807.34)"
    "bw_mem-bzero-4mb (MB/s)","1346.89 (min 858.92, max 1834.86)"
    "bw_mem-bzero-8mb (MB/s)","1358.02 (min 879.70, max 1836.34)"
    "bw_mem-cp-16mb (MB/s)","466.38"
    "bw_mem-cp-1mb (MB/s)","1224.11 (min 459.35, max 1988.86)"
    "bw_mem-cp-2mb (MB/s)","1183.27 (min 455.58, max 1910.95)"
    "bw_mem-cp-4mb (MB/s)","1189.98 (min 495.54, max 1884.42)"
    "bw_mem-cp-8mb (MB/s)","1195.48 (min 521.14, max 1869.81)"
    "bw_mem-fcp-16mb (MB/s)","709.66"
    "bw_mem-fcp-1mb (MB/s)","1355.34 (min 874.89, max 1835.78)"
    "bw_mem-fcp-2mb (MB/s)","1302.34 (min 797.34, max 1807.34)"
    "bw_mem-fcp-4mb (MB/s)","1327.39 (min 819.92, max 1834.86)"
    "bw_mem-fcp-8mb (MB/s)","1337.20 (min 838.05, max 1836.34)"
    "bw_mem-frd-16mb (MB/s)","1158.66"
    "bw_mem-frd-1mb (MB/s)","1075.90 (min 874.89, max 1276.91)"
    "bw_mem-frd-2mb (MB/s)","977.04 (min 797.34, max 1156.74)"
    "bw_mem-frd-4mb (MB/s)","984.35 (min 819.92, max 1148.77)"
    "bw_mem-frd-8mb (MB/s)","999.24 (min 838.05, max 1160.43)"
    "bw_mem-fwr-16mb (MB/s)","1853.14"
    "bw_mem-fwr-1mb (MB/s)","1632.89 (min 1276.91, max 1988.86)"
    "bw_mem-fwr-2mb (MB/s)","1533.85 (min 1156.74, max 1910.95)"
    "bw_mem-fwr-4mb (MB/s)","1516.60 (min 1148.77, max 1884.42)"
    "bw_mem-fwr-8mb (MB/s)","1515.12 (min 1160.43, max 1869.81)"
    "bw_mem-rd-16mb (MB/s)","1180.46"
    "bw_mem-rd-1mb (MB/s)","1044.77 (min 727.14, max 1362.40)"
    "bw_mem-rd-2mb (MB/s)","919.05 (min 663.35, max 1174.74)"
    "bw_mem-rd-4mb (MB/s)","964.38 (min 761.90, max 1166.86)"
    "bw_mem-rd-8mb (MB/s)","996.02 (min 818.50, max 1173.54)"
    "bw_mem-rdwr-16mb (MB/s)","831.13"
    "bw_mem-rdwr-1mb (MB/s)","594.85 (min 459.35, max 730.35)"
    "bw_mem-rdwr-2mb (MB/s)","566.43 (min 455.58, max 677.28)"
    "bw_mem-rdwr-4mb (MB/s)","627.57 (min 495.54, max 759.59)"
    "bw_mem-rdwr-8mb (MB/s)","673.97 (min 521.14, max 826.79)"
    "bw_mem-wr-16mb (MB/s)","887.02"
    "bw_mem-wr-1mb (MB/s)","728.75 (min 727.14, max 730.35)"
    "bw_mem-wr-2mb (MB/s)","670.32 (min 663.35, max 677.28)"
    "bw_mem-wr-4mb (MB/s)","760.75 (min 759.59, max 761.90)"
    "bw_mem-wr-8mb (MB/s)","822.65 (min 818.50, max 826.79)"
    "bw_mmap_rd-mo-1mb (MB/s)","1327.27"
    "bw_mmap_rd-o2c-1mb (MB/s)","447.09"
    "bw_pipe (MB/s)","492.24"
    "bw_unix (MB/s)","1223.54"
    "lat_connect (us)","55.35"
    "lat_ctx-2-128k (us)","5.39"
    "lat_ctx-2-256k (us)","3.25"
    "lat_ctx-4-128k (us)","4.01"
    "lat_ctx-4-256k (us)","6.45"
    "lat_fs-0k (num_files)","242.00"
    "lat_fs-10k (num_files)","118.00"
    "lat_fs-1k (num_files)","162.00"
    "lat_fs-4k (num_files)","161.00"
    "lat_mem_rd-stride128-sz1000k (ns)","50.76"
    "lat_mem_rd-stride128-sz125k (ns)","6.49"
    "lat_mem_rd-stride128-sz250k (ns)","6.80"
    "lat_mem_rd-stride128-sz31k (ns)","4.26"
    "lat_mem_rd-stride128-sz50 (ns)","2.50"
    "lat_mem_rd-stride128-sz500k (ns)","13.27"
    "lat_mem_rd-stride128-sz62k (ns)","6.14"
    "lat_mmap-1m (us)","54.00"
    "lat_ops-double-add (ns)","0.61"
    "lat_ops-double-mul (ns)","3.34"
    "lat_ops-float-add (ns)","0.61"
    "lat_ops-float-mul (ns)","3.34"
    "lat_ops-int-add (ns)","0.83"
    "lat_ops-int-bit (ns)","0.56"
    "lat_ops-int-div (ns)","5.01"
    "lat_ops-int-mod (ns)","5.29"
    "lat_ops-int-mul (ns)","2.53"
    "lat_ops-int64-add (ns)","0.84"
    "lat_ops-int64-bit (ns)","0.56"
    "lat_ops-int64-div (ns)","7.93"
    "lat_ops-int64-mod (ns)","6.12"
    "lat_pagefault (us)","1.35"
    "lat_pipe (us)","20.93"
    "lat_proc-exec (us)","1193.40"
    "lat_proc-fork (us)","922.00"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","41.12"
    "lat_sem (us)","1.95"
    "lat_sig-catch (us)","5.71"
    "lat_sig-install (us)","0.55"
    "lat_sig-prot (us)","0.57"
    "lat_syscall-fstat (us)","1.34"
    "lat_syscall-null (us)","0.33"
    "lat_syscall-open (us)","164.94"
    "lat_syscall-read (us)","0.69"
    "lat_syscall-stat (us)","3.65"
    "lat_syscall-write (us)","0.54"
    "lat_tcp (us)","0.72"
    "lat_unix (us)","39.23"
    "latency_for_0.50_mb_block_size (nanosec)","13.27"
    "latency_for_1.00_mb_block_size (nanosec)","25.38 (min 0.00, max 50.76)"
    "pipe_bandwidth (MBs)","492.24"
    "pipe_latency (microsec)","20.93"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","41.12"
    "semaphore_latency (microsec)","1.95"
    "signal_handler_latency (microsec)","0.55"
    "signal_handler_overhead (microsec)","5.71"
    "tcp_ip_connection_cost_to_localhost (microsec)","55.35"
    "tcp_latency_using_localhost (microsec)","0.72"


Table:  **LM Bench Metrics**



Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.
  
.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf"

    "cpu_clock (MHz)","1200.00"
    "dhrystone_per_mhz (DMIPS/MHz)","3.00"
    "dhrystone_per_second (DhrystoneP)","6250000.00"


Table:  **Dhrystone Benchmark**



Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf"

    "whetstone (MIPS)","5000.00"


Table:  **Whetstone Benchmark**



Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf"

    "linpack (Kflops)","500924.00"


Table:  **Linpack Benchmark**





Stream
^^^^^^^^^^^^^^^^^^^^^^^^^^^
STREAM is a microbenchmark for measuring data memory system performance without
any data reuse. It is designed to miss on caches and exercise data prefetcher
and speculative accesses.
It uses double precision floating point (64bit) but in
most modern processors the memory access will be the bottleneck.
The four individual scores are copy, scale as in multiply by constant,
add two numbers, and triad for multiply accumulate.
For bandwidth, a byte read counts as one and a byte written counts as one,
resulting in a score that is double the bandwidth LMBench will show.

.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf"

    "add (MB/s)","1452.80"
    "copy (MB/s)","1679.20"
    "scale (MB/s)","1835.30"
    "triad (MB/s)","1456.40"


Table:  **Stream**



CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.


.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf"

    "cjpeg-rose7-preset (workloads/)","36.10"
    "core (workloads/)","0.26"
    "coremark-pro ()","792.87"
    "linear_alg-mid-100x100-sp (workloads/)","12.58"
    "loops-all-mid-10k-sp (workloads/)","0.59"
    "nnet_test (workloads/)","0.94"
    "parser-125k (workloads/)","7.41"
    "radix2-big-64k (workloads/)","55.15"
    "sha-test (workloads/)","69.44"
    "zip-test (workloads/)","18.87"


Table:  **CoreMarkPro**



.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf"

    "cjpeg-rose7-preset (workloads/)","71.43"
    "core (workloads/)","0.52"
    "coremark-pro ()","1339.97"
    "linear_alg-mid-100x100-sp (workloads/)","25.14"
    "loops-all-mid-10k-sp (workloads/)","1.04"
    "nnet_test (workloads/)","1.87"
    "parser-125k (workloads/)","11.63"
    "radix2-big-64k (workloads/)","37.65"
    "sha-test (workloads/)","138.89"
    "zip-test (workloads/)","35.71"


Table:  **CoreMarkPro for Two Cores**
 
 


MultiBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
MultiBench™ is a suite of benchmarks that allows processor and system designers to
analyze, test, and improve multicore processors. It uses three forms of concurrency:
Data decomposition: multiple threads cooperating on achieving a unified goal and
demonstrating a processor’s support for fine grain parallelism.
Processing multiple data streams: uses common code running over multiple threads and
demonstrating how well a processor scales over scalable data inputs.
Multiple workload processing: shows the scalability of general-purpose processing,
demonstrating concurrency over both code and data.
MultiBench combines a wide variety of application-specific workloads with the EEMBC
Multi-Instance-Test Harness (MITH), compatible and portable with most any multicore
processors and operating systems. MITH uses a thread-based API (POSIX-compliant) to
establish a common programming model that communicates with the benchmark through an
abstraction layer and provides a flexible interface to allow a wide variety of
thread-enabled workloads to be tested.

.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf"

    "4m-check (workloads/)","351.57"
    "4m-check-reassembly (workloads/)","69.16"
    "4m-check-reassembly-tcp (workloads/)","42.88"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","23.91"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.59"
    "4m-cmykw2 (workloads/)","183.99"
    "4m-cmykw2-rotatew2 (workloads/)","37.55"
    "4m-reassembly (workloads/)","53.91"
    "4m-rotatew2 (workloads/)","41.95"
    "4m-tcp-mixed (workloads/)","97.56"
    "4m-x264w2 (workloads/)","1.56"
    "empty-wld (workloads/)","1.00"
    "idct-4m (workloads/)","16.23"
    "idct-4mw1 (workloads/)","16.22"
    "ippktcheck-4m (workloads/)","349.70"
    "ippktcheck-4mw1 (workloads/)","350.83"
    "ipres-4m (workloads/)","61.93"
    "ipres-4mw1 (workloads/)","62.29"
    "md5-4m (workloads/)","25.17"
    "md5-4mw1 (workloads/)","24.88"
    "rgbcmyk-4m (workloads/)","55.02"
    "rgbcmyk-4mw1 (workloads/)","55.13"
    "rotate-4ms1 (workloads/)","17.31"
    "rotate-4ms1w1 (workloads/)","17.28"
    "rotate-4ms64 (workloads/)","17.39"
    "rotate-4ms64w1 (workloads/)","17.56"
    "x264-4mq (workloads/)","0.49"
    "x264-4mqw1 (workloads/)","0.48"


Table:  **Multibench**


 
 


Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am62xx-sk: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","19.38 (min 18.47, max 19.93)"

Table:  **Boot time MMC/SD**



 


Graphics SGX/RGX Driver
-------------------------
 


GFXBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Run GFXBench and capture performance reported (Score and Display rate in fps). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am62xx-sk: Score","am62xx-sk: Fps"

    " GFXBench 3.x gl_manhattan_off","82.49","1.33"
    " GFXBench 3.x gl_trex_off","135.92","2.43"
    " GFXBench 5.x gl_5_high_off","10.99","0.17"


Table:  **GFXBench**



Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am62xx-sk: Score"

    "Glmark2-Wayland","204.00"


Table:  **Glmark2**
 
 
|

 

 


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

- CPSW2g: AM65x, J7200, J721e
- CPSW3g: AM64x


.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","am62xx-sk: THROUGHPUT (Mbits/sec)","am62xx-sk: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1542.46","41.63"

Table: **CPSW TCP Bidirectional Throughput**
|



.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am62xx-sk: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx-sk: THROUGHPUT (Mbits/sec)","am62xx-sk: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","17.22","43.38"
    "128","82.00","78.36","43.38"
    "256","210.00","206.08","43.96"
    "1024","978.00","928.62","44.05"
    "1518","1472.00","951.60","42.44"

Table: **CPSW UDP Egress Throughput**
|



.. csv-table::
    :header: "Frame Size(bytes)","am62xx-sk: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx-sk: THROUGHPUT (Mbits/sec)","am62xx-sk: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","11.26","14.14"
    "128","82.00","15.94","6.10"
    "256","210.00","74.93","9.87"
    "1024","978.00","936.71","39.66"
    "1518","1472.00","957.00","40.75"


Table: **CPSW UDP Ingress Throughput (0% loss)**

|



.. csv-table::
    :header: "Frame Size(bytes)","am62xx-sk: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx-sk: THROUGHPUT (Mbits/sec)","am62xx-sk: CPU Load % (LOCAL_CPU_UTIL)","am62xx-sk: Packet Loss %"

    "64","18.00","23.37","37.33","63.54"
    "128","82.00","105.21","38.92","63.21"
    "256","210.00","258.67","40.09","64.88"
    "1024","978.00","935.29","40.03","0.16"
    "1518","1472.00","956.43","41.28","0.07"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|
 
 

 

 
 

 

 

 

 

 

 

 

 


EMMC Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

|






AM62XX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","am62xx-sk: Write EXT4 Throughput (Mbytes/sec)","am62xx-sk: Write EXT4 CPU Load (%)","am62xx-sk: Read EXT4 Throughput (Mbytes/sec)","am62xx-sk: Read EXT4 CPU Load (%)"

    "1m","57.80","1.44","173.00","1.95"
    "4m","57.90","1.25","174.00","1.74"
    "4k","51.00","20.10","55.70","19.06"
    "256k","58.50","1.63","173.00","2.55"

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

 





 


AM62XX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","am62xx-sk: Write EXT4 Throughput (Mbytes/sec)","am62xx-sk: Write EXT4 CPU Load (%)","am62xx-sk: Read EXT4 Throughput (Mbytes/sec)","am62xx-sk: Read EXT4 CPU Load (%)"

    "1m","9.13","0.50","75.70","1.41"
    "4m","8.65","1.10","85.70","1.43"
    "4k","3.09","1.95","25.60","7.32"
    "256k","9.18","0.59","75.20","1.65"

|





 

 




 













 

 

 





 
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
    :header: "Algorithm","Buffer Size (in bytes)","am62xx-sk: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","209475.24"
    "aes-128-cbc","16","4548.46"
    "aes-128-cbc","16384","632335.02"
    "aes-128-cbc","256","66454.78"
    "aes-128-cbc","64","17944.49"
    "aes-128-cbc","8192","558333.95"
    "aes-192-cbc","1024","199166.63"
    "aes-192-cbc","16","4551.72"
    "aes-192-cbc","16384","543342.59"
    "aes-192-cbc","256","65624.23"
    "aes-192-cbc","64","17926.36"
    "aes-192-cbc","8192","488540.84"
    "aes-256-cbc","1024","190219.26"
    "aes-256-cbc","16","4545.40"
    "aes-256-cbc","16384","488243.20"
    "aes-256-cbc","256","64551.25"
    "aes-256-cbc","64","17750.98"
    "aes-256-cbc","8192","443083.43"
    "des-cbc","1024","22458.03"
    "des-cbc","16","4685.29"
    "des-cbc","16384","23811.41"
    "des-cbc","256","18987.35"
    "des-cbc","64","11756.22"
    "des-cbc","8192","23721.30"
    "des3","1024","9426.26"
    "des3","16","3653.49"
    "des3","16384","9655.64"
    "des3","256","8768.68"
    "des3","64","6835.54"
    "des3","8192","9639.25"
    "md5","1024","43770.54"
    "md5","16","956.34"
    "md5","16384","134321.49"
    "md5","256","13857.11"
    "md5","64","3703.36"
    "md5","8192","117940.22"
    "sha1","1024","53661.70"
    "sha1","16","935.48"
    "sha1","16384","332338.52"
    "sha1","256","14544.30"
    "sha1","64","3712.70"
    "sha1","8192","246718.46"
    "sha224","1024","52768.43"
    "sha224","16","914.61"
    "sha224","16384","342518.44"
    "sha224","256","14247.59"
    "sha224","64","3625.60"
    "sha224","8192","250396.67"
    "sha256","1024","51911.34"
    "sha256","16","913.85"
    "sha256","16384","342502.06"
    "sha256","256","14230.44"
    "sha256","64","3627.22"
    "sha256","8192","250025.30"
    "sha384","1024","38473.05"
    "sha384","16","882.59"
    "sha384","16384","108030.63"
    "sha384","256","12552.96"
    "sha384","64","3522.30"
    "sha384","8192","96384.34"
    "sha512","1024","38417.41"
    "sha512","16","880.41"
    "sha512","16384","107992.41"
    "sha512","256","12429.65"
    "sha512","64","3516.54"
    "sha512","8192","96324.27"


|
|



.. csv-table::
    :header: "Algorithm","am62xx-sk: CPU Load"

    "aes-128-cbc","98.00"
    "aes-192-cbc","98.00"
    "aes-256-cbc","98.00"
    "des-cbc","98.00"
    "des3","98.00"
    "md5","98.00"
    "sha1","98.00"
    "sha224","98.00"
    "sha256","98.00"
    "sha384","98.00"
    "sha512","98.00"

 

Listed for each algorithm are the code snippets used to run each
  benchmark test.

::
    time -v openssl speed -elapsed -evp aes-128-cbc

 




IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am62xx-sk: Throughput (Mbps)","am62xx-sk: Packets/Sec","am62xx-sk: CPU Load"

    "3des","64.80","5.00","26.06"
    "aes128","230.50","20.00","27.59"
    "aes192","215.80","19.00","27.63"
    "aes256","216.70","19.00","27.68"

 
 

DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.



