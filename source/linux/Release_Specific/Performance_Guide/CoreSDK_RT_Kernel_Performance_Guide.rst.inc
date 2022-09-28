..  http://processors.wiki.ti.com/index.php/CoreSDK_Linux_RT_Kernel_Performance_Guide


======================================
 RT-linux 08.04.01 Performance Guide
======================================

.. rubric::  **Read This First**
   :name: read-this-first-rt-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+---------------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                         |
+================+=====================================================================================================================+
| AM64x HS EVM   | AM64x Evaluation Module rev C with ARM running at 1GHz, DDR4, DDR data rate 1600 MT/S                               |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| AM64x SK       | AM64x Evaluation Module rev E2 with ARM running at 1GHz, LPDDR4, DDR data rate 1600 MT/S                            |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| AM64x EVM      | AM64x Evaluation Module rev E1 with ARM running at 1GHz, DDR4, DDR data rate 1600 MT/S                              |
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
    :header: "Benchmarks","am64xx-evm: perf","am64xx-hsevm: perf"

    "af_unix_sock_stream_latency (microsec)","44.18","44.98"
    "af_unix_socket_stream_bandwidth (MBs)","745.03","775.60"
    "bw_file_rd-io-1mb (MB/s)","819.00","837.66"
    "bw_file_rd-o2c-1mb (MB/s)","495.95","483.71"
    "bw_mem-bcopy-16mb (MB/s)","868.90","888.40"
    "bw_mem-bcopy-1mb (MB/s)","951.02","956.94"
    "bw_mem-bcopy-2mb (MB/s)","946.67","941.92"
    "bw_mem-bcopy-4mb (MB/s)","967.47","974.90"
    "bw_mem-bcopy-8mb (MB/s)","985.10","958.77"
    "bw_mem-bzero-16mb (MB/s)","2125.40","2119.49"
    "bw_mem-bzero-1mb (MB/s)","1533.90 (min 951.02, max 2116.78)","1537.23 (min 956.94, max 2117.52)"
    "bw_mem-bzero-2mb (MB/s)","1536.60 (min 946.67, max 2126.53)","1532.16 (min 941.92, max 2122.39)"
    "bw_mem-bzero-4mb (MB/s)","1546.25 (min 967.47, max 2125.02)","1548.84 (min 974.90, max 2122.77)"
    "bw_mem-bzero-8mb (MB/s)","1554.83 (min 985.10, max 2124.55)","1542.09 (min 958.77, max 2125.40)"
    "bw_mem-cp-16mb (MB/s)","553.12","560.50"
    "bw_mem-cp-1mb (MB/s)","1408.25 (min 541.61, max 2274.88)","1409.56 (min 556.25, max 2262.87)"
    "bw_mem-cp-2mb (MB/s)","1360.62 (min 541.79, max 2179.44)","1373.15 (min 553.71, max 2192.58)"
    "bw_mem-cp-4mb (MB/s)","1364.87 (min 583.43, max 2146.31)","1373.69 (min 586.77, max 2160.60)"
    "bw_mem-cp-8mb (MB/s)","1357.65 (min 610.31, max 2104.99)","1366.59 (min 586.38, max 2146.79)"
    "bw_mem-fcp-16mb (MB/s)","791.84","792.63"
    "bw_mem-fcp-1mb (MB/s)","1481.91 (min 847.03, max 2116.78)","1469.10 (min 820.68, max 2117.52)"
    "bw_mem-fcp-2mb (MB/s)","1485.56 (min 844.59, max 2126.53)","1496.04 (min 869.69, max 2122.39)"
    "bw_mem-fcp-4mb (MB/s)","1506.56 (min 888.10, max 2125.02)","1520.00 (min 917.22, max 2122.77)"
    "bw_mem-fcp-8mb (MB/s)","1519.94 (min 915.33, max 2124.55)","1520.26 (min 915.12, max 2125.40)"
    "bw_mem-frd-16mb (MB/s)","1390.10","1390.34"
    "bw_mem-frd-1mb (MB/s)","1058.73 (min 847.03, max 1270.42)","1069.23 (min 820.68, max 1317.77)"
    "bw_mem-frd-2mb (MB/s)","1101.41 (min 844.59, max 1358.23)","1087.48 (min 869.69, max 1305.27)"
    "bw_mem-frd-4mb (MB/s)","1122.82 (min 888.10, max 1357.54)","1148.98 (min 917.22, max 1380.74)"
    "bw_mem-frd-8mb (MB/s)","1144.60 (min 915.33, max 1373.86)","1147.46 (min 915.12, max 1379.79)"
    "bw_mem-fwr-16mb (MB/s)","2133.05","2136.75"
    "bw_mem-fwr-1mb (MB/s)","1772.65 (min 1270.42, max 2274.88)","1790.32 (min 1317.77, max 2262.87)"
    "bw_mem-fwr-2mb (MB/s)","1768.84 (min 1358.23, max 2179.44)","1748.93 (min 1305.27, max 2192.58)"
    "bw_mem-fwr-4mb (MB/s)","1751.93 (min 1357.54, max 2146.31)","1770.67 (min 1380.74, max 2160.60)"
    "bw_mem-fwr-8mb (MB/s)","1739.43 (min 1373.86, max 2104.99)","1763.29 (min 1379.79, max 2146.79)"
    "bw_mem-rd-16mb (MB/s)","1403.14","1380.38"
    "bw_mem-rd-1mb (MB/s)","1112.23 (min 820.21, max 1404.25)","1106.70 (min 822.10, max 1391.30)"
    "bw_mem-rd-2mb (MB/s)","1126.13 (min 874.38, max 1377.88)","1122.47 (min 861.57, max 1383.37)"
    "bw_mem-rd-4mb (MB/s)","1188.39 (min 982.08, max 1394.70)","1169.11 (min 942.29, max 1395.92)"
    "bw_mem-rd-8mb (MB/s)","1188.58 (min 980.51, max 1396.65)","1234.57 (min 1062.42, max 1406.72)"
    "bw_mem-rdwr-16mb (MB/s)","1041.60","1034.53"
    "bw_mem-rdwr-1mb (MB/s)","688.66 (min 541.61, max 835.70)","657.78 (min 556.25, max 759.30)"
    "bw_mem-rdwr-2mb (MB/s)","684.69 (min 541.79, max 827.59)","696.14 (min 553.71, max 838.57)"
    "bw_mem-rdwr-4mb (MB/s)","763.53 (min 583.43, max 943.62)","753.16 (min 586.77, max 919.54)"
    "bw_mem-rdwr-8mb (MB/s)","747.59 (min 610.31, max 884.86)","795.45 (min 586.38, max 1004.52)"
    "bw_mem-wr-16mb (MB/s)","1071.24","1089.70"
    "bw_mem-wr-1mb (MB/s)","827.96 (min 820.21, max 835.70)","790.70 (min 759.30, max 822.10)"
    "bw_mem-wr-2mb (MB/s)","850.99 (min 827.59, max 874.38)","850.07 (min 838.57, max 861.57)"
    "bw_mem-wr-4mb (MB/s)","962.85 (min 943.62, max 982.08)","930.92 (min 919.54, max 942.29)"
    "bw_mem-wr-8mb (MB/s)","932.69 (min 884.86, max 980.51)","1033.47 (min 1004.52, max 1062.42)"
    "bw_mmap_rd-mo-1mb (MB/s)","1387.79","1279.71"
    "bw_mmap_rd-o2c-1mb (MB/s)","506.67","506.16"
    "bw_pipe (MB/s)","463.62","459.50"
    "bw_unix (MB/s)","745.03","775.60"
    "lat_connect (us)","94.22","100.98"
    "lat_ctx-2-128k (us)","8.45","9.54"
    "lat_ctx-2-256k (us)","18.43","19.34"
    "lat_ctx-4-128k (us)","9.21","10.12"
    "lat_ctx-4-256k (us)","9.01","5.24"
    "lat_fs-0k (num_files)","238.00","213.00"
    "lat_fs-10k (num_files)","101.00","88.00"
    "lat_fs-1k (num_files)","155.00","150.00"
    "lat_fs-4k (num_files)","157.00","128.00"
    "lat_mem_rd-stride128-sz1000k (ns)","47.57","47.55"
    "lat_mem_rd-stride128-sz125k (ns)","7.82","7.79"
    "lat_mem_rd-stride128-sz250k (ns)","12.50","14.06"
    "lat_mem_rd-stride128-sz31k (ns)","3.02","3.03"
    "lat_mem_rd-stride128-sz50 (ns)","3.01","3.01"
    "lat_mem_rd-stride128-sz500k (ns)","43.48","42.99"
    "lat_mem_rd-stride128-sz62k (ns)","7.33","7.37"
    "lat_mmap-1m (us)","65.00","65.00"
    "lat_ops-double-add (ns)","0.73","0.73"
    "lat_ops-double-mul (ns)","4.01","4.01"
    "lat_ops-float-add (ns)","0.73","0.73"
    "lat_ops-float-mul (ns)","4.01","4.01"
    "lat_ops-int-add (ns)","1.00","1.00"
    "lat_ops-int-bit (ns)","0.67","0.67"
    "lat_ops-int-div (ns)","6.02","6.01"
    "lat_ops-int-mod (ns)","6.37","6.35"
    "lat_ops-int-mul (ns)","3.04","3.04"
    "lat_ops-int64-add (ns)","1.00","1.00"
    "lat_ops-int64-bit (ns)","0.67","0.67"
    "lat_ops-int64-div (ns)","9.53","9.52"
    "lat_ops-int64-mod (ns)","7.35","7.35"
    "lat_pagefault (us)","1.64","1.65"
    "lat_pipe (us)","25.69","26.16"
    "lat_proc-exec (us)","1712.00","1798.00"
    "lat_proc-fork (us)","1387.75","1442.25"
    "lat_proc-proccall (us)","0.01","0.01"
    "lat_select (us)","49.43","49.23"
    "lat_sem (us)","3.36","3.02"
    "lat_sig-catch (us)","7.13","7.49"
    "lat_sig-install (us)","0.67","0.79"
    "lat_sig-prot (us)","0.51","0.63"
    "lat_syscall-fstat (us)","1.67","1.82"
    "lat_syscall-null (us)","0.40","0.54"
    "lat_syscall-open (us)","387.00","396.83"
    "lat_syscall-read (us)","0.78","0.90"
    "lat_syscall-stat (us)","4.44","4.63"
    "lat_syscall-write (us)","0.66","0.77"
    "lat_tcp (us)","0.84","1.09"
    "lat_unix (us)","44.18","44.98"
    "latency_for_0.50_mb_block_size (nanosec)","43.48","42.99"
    "latency_for_1.00_mb_block_size (nanosec)","23.79 (min 0.00, max 47.57)","23.78 (min 0.00, max 47.55)"
    "pipe_bandwidth (MBs)","463.62","459.50"
    "pipe_latency (microsec)","25.69","26.16"
    "procedure_call (microsec)","0.01","0.01"
    "select_on_200_tcp_fds (microsec)","49.43","49.23"
    "semaphore_latency (microsec)","3.36","3.02"
    "signal_handler_latency (microsec)","0.67","0.79"
    "signal_handler_overhead (microsec)","7.13","7.49"
    "tcp_ip_connection_cost_to_localhost (microsec)","94.22","100.98"
    "tcp_latency_using_localhost (microsec)","0.84","1.09"


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
    :header: "Benchmarks","am64xx-evm: perf","am64xx-hsevm: perf","am64xx-sk: perf"

    "whetstone (MIPS)","5000.00","3333.30","3333.30"


Table:  **Whetstone Benchmark**



Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf","am64xx-hsevm: perf"

    "linpack (Kflops)","415507.00","405280.00"


Table:  **Linpack Benchmark**



NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks 
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html


.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf","am64xx-hsevm: perf"

    "assignment (Iterations)","9.75","9.40"
    "fourier (Iterations)","16233.00","16230.00"
    "fp_emulation (Iterations)","76.50","75.82"
    "huffman (Iterations)","838.22","833.37"
    "idea (Iterations)","2452.90","2437.00"
    "lu_decomposition (Iterations)","389.65","382.69"
    "neural_net (Iterations)","5.61","5.57"
    "numeric_sort (Iterations)","360.17","356.15"
    "string_sort (Iterations)","118.39","117.44"


Table:  **NBench Benchmarks**



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
    :header: "Benchmarks","am64xx-evm: perf"

    "add (MB/s)","1808.30"
    "copy (MB/s)","2060.80"
    "scale (MB/s)","2288.00"
    "triad (MB/s)","1767.20"


Table:  **Stream**



CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.


.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf","am64xx-hsevm: perf"

    "cjpeg-rose7-preset (workloads/)","30.03","30.03"
    "core (workloads/)","0.21","0.21"
    "coremark-pro ()","593.72","589.19"
    "linear_alg-mid-100x100-sp (workloads/)","10.46","10.48"
    "loops-all-mid-10k-sp (workloads/)","0.49","0.49"
    "nnet_test (workloads/)","0.78","0.78"
    "parser-125k (workloads/)","5.88","4.98"
    "radix2-big-64k (workloads/)","19.31","21.21"
    "sha-test (workloads/)","57.14","58.14"
    "zip-test (workloads/)","15.87","15.63"


Table:  **CoreMarkPro**



.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf","am64xx-hsevm: perf"

    "cjpeg-rose7-preset (workloads/)","58.14","28.01"
    "core (workloads/)","0.42","0.18"
    "coremark-pro ()","1037.26","531.91"
    "linear_alg-mid-100x100-sp (workloads/)","20.75","10.61"
    "loops-all-mid-10k-sp (workloads/)","0.88","0.40"
    "nnet_test (workloads/)","1.55","0.74"
    "parser-125k (workloads/)","5.68","4.29"
    "radix2-big-64k (workloads/)","31.91","16.31"
    "sha-test (workloads/)","105.26","58.82"
    "zip-test (workloads/)","29.85","14.81"


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
    :header: "Benchmarks","am64xx-evm: perf","am64xx-hsevm: perf"

    "4m-check (workloads/)","329.38","211.67"
    "4m-check-reassembly (workloads/)","67.20","28.56"
    "4m-check-reassembly-tcp (workloads/)","39.00","13.83"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","15.34","6.28"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","0.77","0.32"
    "4m-cmykw2 (workloads/)","88.93","36.69"
    "4m-cmykw2-rotatew2 (workloads/)","20.64","10.15"
    "4m-reassembly (workloads/)","57.74","26.09"
    "4m-rotatew2 (workloads/)","24.06","10.96"
    "4m-tcp-mixed (workloads/)","88.89","41.99"
    "4m-x264w2 (workloads/)","0.78","0.33"
    "empty-wld (workloads/)","1.00","1.00"
    "idct-4m (workloads/)","13.74","11.48"
    "idct-4mw1 (workloads/)","13.72","9.60"
    "ippktcheck-4m (workloads/)","328.13","208.07"
    "ippktcheck-4mw1 (workloads/)","329.60","208.80"
    "ipres-4m (workloads/)","70.59","37.80"
    "ipres-4mw1 (workloads/)","70.22","40.93"
    "md5-4m (workloads/)","20.53","10.00"
    "md5-4mw1 (workloads/)","20.51","10.33"
    "rgbcmyk-4m (workloads/)","44.86","38.88"
    "rgbcmyk-4mw1 (workloads/)","44.82","33.14"
    "rotate-4ms1 (workloads/)","17.14","10.02"
    "rotate-4ms1w1 (workloads/)","17.18","10.21"
    "rotate-4ms64 (workloads/)","17.36","11.56"
    "rotate-4ms64w1 (workloads/)","17.46","10.68"
    "x264-4mq (workloads/)","0.41","0.31"
    "x264-4mqw1 (workloads/)","0.41","0.33"


Table:  **Multibench**


 
 

 


Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am64xx-evm: boot time (sec)","am64xx-hsevm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","23.19 (min 22.87, max 23.56)","22.78 (min 22.56, max 23.23)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","4.72","4.89 (min 4.86, max 4.91)"

Table:  **Boot time MMC/SD**


 
 

 



 

 

 


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
    :header: "Command Used","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","am64xx-sk: THROUGHPUT (Mbits/sec)","am64xx-sk: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","182.54","27.27","179.58","39.17"

Table: **CPSW TCP Bidirectional Throughput**

|



.. rubric::  UDP Throughput 
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","12.11","74.10"
    "128","82.00","52.99","72.48"
    "256","210.00","76.02","45.13"
    "1518","1472.00","914.04","86.89"

Table: **CPSW UDP Egress Throughput**

|



.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.31","2.65"
    "128","82.00","5.90","3.96"
    "256","210.00","16.63","10.28"
    "1024","978.00","85.28","8.85"
    "1518","1472.00","124.82","16.87"

Table: **CPSW UDP Ingress Throughput (0% loss)**

|



.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","am64xx-evm: Packet Loss %"

    "64","18.00","21.07","77.35","28.30"
    "128","82.00","94.30","78.68","59.94"
    "256","210.00","237.46","80.16","29.46"
    "1024","978.00","931.43","84.86","0.46"
    "1518","1472.00","953.70","84.16","0.35"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|
 
 


ICSSG Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^



.. rubric::  UDP Throughput 
   :name: udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","12.59","73.65"
    "128","82.00","49.50","66.91"
    "256","210.00","76.03","41.45"
    "1024","978.00","93.67","14.74"
    "1518","1472.00","94.21","14.17"

Table: **ICSSG UDP Egress Throughput**

|



.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load %"

    "128","82.00","5.05","9.92"
    "256","210.00","13.78","5.07"
    "1024","978.00","93.32","17.50"
    "1518","1472.00","115.40","15.90"

Table: **ICSSG UDP Ingress Throughput (0% loss)**

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

 

 

 


AM64XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","59.60","4.37","174.00","6.73"
    "4m","59.70","3.47","174.00","5.37"
    "4k","44.20","46.71","55.30","49.10"
    "256k","59.50","6.49","173.00","9.28"

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
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","13.40","2.11","96.40","5.25"
    "4m","14.60","2.07","80.50","3.64"
    "4k","5.25","10.54","17.40","17.99"
    "256k","13.10","3.25","93.60","7.11"

|


 



 

 

 

 

 

 

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

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

    "aes-128-cbc","1024","21186.56"
    "aes-128-cbc","16","348.52"
    "aes-128-cbc","16384","109494.27"
    "aes-128-cbc","256","5583.19"
    "aes-128-cbc","64","1369.66"
    "aes-128-cbc","8192","86512.98"
    "aes-192-cbc","1024","21343.23"
    "aes-192-cbc","16","351.33"
    "aes-192-cbc","16384","113459.20"
    "aes-192-cbc","256","5420.63"
    "aes-192-cbc","64","1353.32"
    "aes-192-cbc","8192","84118.19"
    "aes-256-cbc","1024","20676.61"
    "aes-256-cbc","16","365.44"
    "aes-256-cbc","16384","104983.21"
    "aes-256-cbc","256","5549.65"
    "aes-256-cbc","64","1395.69"
    "aes-256-cbc","8192","77796.69"
    "des-cbc","1024","15404.37"
    "des-cbc","16","2716.06"
    "des-cbc","16384","17061.21"
    "des-cbc","256","12618.15"
    "des-cbc","64","7378.62"
    "des-cbc","8192","17222.31"
    "des3","1024","6455.98"
    "des3","16","2080.44"
    "des3","16384","6717.44"
    "des3","256","5637.80"
    "des3","64","4770.79"
    "des3","8192","6867.63"
    "md5","1024","34277.03"
    "md5","16","603.36"
    "md5","16384","106643.46"
    "md5","256","8881.24"
    "md5","64","2513.17"
    "md5","8192","92558.68"
    "sha1","1024","34250.41"
    "sha1","16","553.99"
    "sha1","16384","202571.78"
    "sha1","256","9384.19"
    "sha1","64","2280.04"
    "sha1","8192","162630.31"
    "sha224","1024","34882.22"
    "sha224","16","584.94"
    "sha224","16384","222773.25"
    "sha224","256","9260.20"
    "sha224","64","2427.01"
    "sha224","8192","152152.75"
    "sha256","1024","18452.14"
    "sha256","16","341.88"
    "sha256","16384","159514.62"
    "sha256","256","5452.63"
    "sha256","64","1363.95"
    "sha256","8192","103948.29"
    "sha384","1024","22296.58"
    "sha384","16","569.46"
    "sha384","16384","42177.88"
    "sha384","256","7751.25"
    "sha384","64","2214.06"
    "sha384","8192","39212.37"
    "sha512","1024","10548.91"
    "sha512","16","328.66"
    "sha512","16384","40878.08"
    "sha512","256","4961.19"
    "sha512","64","1362.47"
    "sha512","8192","36954.11"


|
|



.. csv-table::
    :header: "Algorithm","am64xx-hsevm: CPU Load"

    "aes-128-cbc","28.00"
    "aes-192-cbc","31.00"
    "aes-256-cbc","27.00"
    "des-cbc","79.00"
    "des3","81.00"
    "md5","87.00"
    "sha1","81.00"
    "sha224","84.00"
    "sha256","78.00"
    "sha384","80.00"
    "sha512","78.00"

 

|
| Listed for each algorithm are the code snippets used to run each
  benchmark test.

|

::
    time -v openssl speed -elapsed -evp aes-128-cbc

 




IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am64xx-evm: Throughput (Mbps)","am64xx-evm: Packets/Sec","am64xx-evm: CPU Load","am64xx-hsevm: Throughput (Mbps)","am64xx-hsevm: Packets/Sec","am64xx-hsevm: CPU Load"

    "3des","52.90","4.00","52.18","52.00","4.00","52.50"
    "aes128","187.20","16.00","54.89","181.90","16.00","55.33"
    "aes192","189.50","16.00","55.77"
    "aes256","185.10","16.00","54.84","188.70","16.00","55.89"

 
 

 

DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.

    

    
