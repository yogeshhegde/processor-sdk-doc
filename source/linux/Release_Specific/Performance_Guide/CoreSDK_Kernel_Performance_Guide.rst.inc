.. http://processors.wiki.ti.com/index.php/CoreSDK_Linux_Kernel_Performance_Guide


======================================
 Linux 08.06.00 Performance Guide
======================================

.. rubric::  **Read This First**
   :name: read-this-first-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| AM62x SK	 | AM62x Starter Kit rev E2 and E3 with ARM running at 1400 MHz, DDR4 data rate 1600 MT/S			  |
+----------------+----------------------------------------------------------------------------------------------------------------+
| AM62x SK LP	 | AM62x LP Starter Kit rev E1 with ARM running at 1250 MHz, LPDDR4 data rate 1600 MT/S		                  |
+----------------+----------------------------------------------------------------------------------------------------------------+

Table:  Evaluation Modules

|

.. rubric::  About This Manual
   :name: about-this-manual-kernel-perf-guide

This document provides performance data for each of the device drivers
which are part of the Processor SDK Linux package. This document should be
used in conjunction with release notes and user guides provided with the
Processor SDK Linux package for information on specific issues present
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
    :header: "Benchmarks","am62xx-sk: perf","am62xx_lp_sk-fs: perf"

    "af_unix_sock_stream_latency (microsec)","32.39","36.80"
    "af_unix_socket_stream_bandwidth (MBs)","1199.02","1056.21"
    "bw_file_rd-io-1mb (MB/s)","804.76","760.60"
    "bw_file_rd-o2c-1mb (MB/s)","480.31","464.47"
    "bw_mem-bcopy-16mb (MB/s)","768.38","668.78"
    "bw_mem-bcopy-1mb (MB/s)","839.77","720.98"
    "bw_mem-bcopy-2mb (MB/s)","759.30","672.04"
    "bw_mem-bcopy-4mb (MB/s)","786.32","686.81"
    "bw_mem-bcopy-8mb (MB/s)","816.16","717.30"
    "bw_mem-bzero-16mb (MB/s)","1736.49","1668.58"
    "bw_mem-bzero-1mb (MB/s)","1287.94 (min 839.77, max 1736.11)","1191.06 (min 720.98, max 1661.13)"
    "bw_mem-bzero-2mb (MB/s)","1246.96 (min 759.30, max 1734.61)","1170.05 (min 672.04, max 1668.06)"
    "bw_mem-bzero-4mb (MB/s)","1260.97 (min 786.32, max 1735.61)","1176.51 (min 686.81, max 1666.20)"
    "bw_mem-bzero-8mb (MB/s)","1275.86 (min 816.16, max 1735.55)","1203.60 (min 717.30, max 1689.90)"
    "bw_mem-cp-16mb (MB/s)","441.34","377.89"
    "bw_mem-cp-1mb (MB/s)","1172.98 (min 475.74, max 1870.21)","1088.08 (min 367.51, max 1808.65)"
    "bw_mem-cp-2mb (MB/s)","1074.07 (min 439.90, max 1708.23)","1056.13 (min 369.48, max 1742.77)"
    "bw_mem-cp-4mb (MB/s)","1130.11 (min 469.70, max 1790.51)","1040.42 (min 358.42, max 1722.41)"
    "bw_mem-cp-8mb (MB/s)","1122.44 (min 470.45, max 1774.43)","1055.11 (min 397.34, max 1712.88)"
    "bw_mem-fcp-16mb (MB/s)","687.85","650.38"
    "bw_mem-fcp-1mb (MB/s)","1291.64 (min 847.17, max 1736.11)","1203.98 (min 746.83, max 1661.13)"
    "bw_mem-fcp-2mb (MB/s)","1247.03 (min 759.45, max 1734.61)","1171.76 (min 675.45, max 1668.06)"
    "bw_mem-fcp-4mb (MB/s)","1240.46 (min 745.30, max 1735.61)","1191.46 (min 716.72, max 1666.20)"
    "bw_mem-fcp-8mb (MB/s)","1241.43 (min 747.31, max 1735.55)","1204.02 (min 718.13, max 1689.90)"
    "bw_mem-frd-16mb (MB/s)","1138.22","1026.30"
    "bw_mem-frd-1mb (MB/s)","1045.48 (min 847.17, max 1243.78)","943.00 (min 746.83, max 1139.17)"
    "bw_mem-frd-2mb (MB/s)","934.56 (min 759.45, max 1109.67)","826.17 (min 675.45, max 976.88)"
    "bw_mem-frd-4mb (MB/s)","936.03 (min 745.30, max 1126.76)","865.98 (min 716.72, max 1015.23)"
    "bw_mem-frd-8mb (MB/s)","937.51 (min 747.31, max 1127.71)","859.51 (min 718.13, max 1000.88)"
    "bw_mem-fwr-16mb (MB/s)","1757.28","1691.51"
    "bw_mem-fwr-1mb (MB/s)","1557.00 (min 1243.78, max 1870.21)","1473.91 (min 1139.17, max 1808.65)"
    "bw_mem-fwr-2mb (MB/s)","1408.95 (min 1109.67, max 1708.23)","1359.83 (min 976.88, max 1742.77)"
    "bw_mem-fwr-4mb (MB/s)","1458.64 (min 1126.76, max 1790.51)","1368.82 (min 1015.23, max 1722.41)"
    "bw_mem-fwr-8mb (MB/s)","1451.07 (min 1127.71, max 1774.43)","1356.88 (min 1000.88, max 1712.88)"
    "bw_mem-rd-16mb (MB/s)","1152.24","1012.47"
    "bw_mem-rd-1mb (MB/s)","993.19 (min 697.47, max 1288.90)","855.30 (min 550.96, max 1159.64)"
    "bw_mem-rd-2mb (MB/s)","871.06 (min 619.58, max 1122.54)","757.57 (min 485.26, max 1029.87)"
    "bw_mem-rd-4mb (MB/s)","898.79 (min 691.68, max 1105.89)","801.65 (min 576.20, max 1027.09)"
    "bw_mem-rd-8mb (MB/s)","960.42 (min 791.37, max 1129.46)","825.49 (min 625.59, max 1025.38)"
    "bw_mem-rdwr-16mb (MB/s)","853.65","641.54"
    "bw_mem-rdwr-1mb (MB/s)","580.16 (min 475.74, max 684.58)","468.28 (min 367.51, max 569.04)"
    "bw_mem-rdwr-2mb (MB/s)","524.74 (min 439.90, max 609.57)","437.36 (min 369.48, max 505.24)"
    "bw_mem-rdwr-4mb (MB/s)","587.65 (min 469.70, max 705.59)","452.55 (min 358.42, max 546.67)"
    "bw_mem-rdwr-8mb (MB/s)","626.77 (min 470.45, max 783.09)","483.27 (min 397.34, max 569.19)"
    "bw_mem-wr-16mb (MB/s)","815.79","650.75"
    "bw_mem-wr-1mb (MB/s)","691.03 (min 684.58, max 697.47)","560.00 (min 550.96, max 569.04)"
    "bw_mem-wr-2mb (MB/s)","614.58 (min 609.57, max 619.58)","495.25 (min 485.26, max 505.24)"
    "bw_mem-wr-4mb (MB/s)","698.64 (min 691.68, max 705.59)","561.44 (min 546.67, max 576.20)"
    "bw_mem-wr-8mb (MB/s)","787.23 (min 783.09, max 791.37)","597.39 (min 569.19, max 625.59)"
    "bw_mmap_rd-mo-1mb (MB/s)","1277.37","1152.83"
    "bw_mmap_rd-o2c-1mb (MB/s)","504.03","452.83"
    "bw_pipe (MB/s)","499.88","454.06"
    "bw_unix (MB/s)","1199.02","1056.21"
    "lat_connect (us)","70.08","77.00"
    "lat_ctx-2-128k (us)","4.54","4.71"
    "lat_ctx-2-256k (us)","4.16","5.31"
    "lat_ctx-4-128k (us)","4.28","4.31"
    "lat_ctx-4-256k (us)","3.35","4.04"
    "lat_fs-0k (num_files)","276.00","251.00"
    "lat_fs-10k (num_files)","114.00","102.00"
    "lat_fs-1k (num_files)","194.00","146.00"
    "lat_fs-4k (num_files)","198.00","176.00"
    "lat_mem_rd-stride128-sz1000k (ns)","52.11","57.76"
    "lat_mem_rd-stride128-sz125k (ns)","5.53","6.22"
    "lat_mem_rd-stride128-sz250k (ns)","5.83","6.55"
    "lat_mem_rd-stride128-sz31k (ns)","3.65","4.70"
    "lat_mem_rd-stride128-sz50 (ns)","2.15","2.40"
    "lat_mem_rd-stride128-sz500k (ns)","13.10","20.67"
    "lat_mem_rd-stride128-sz62k (ns)","5.24","5.86"
    "lat_mmap-1m (us)","47.00","54.00"
    "lat_ops-double-add (ns)","0.52","0.58"
    "lat_ops-double-mul (ns)","2.86","3.21"
    "lat_ops-float-add (ns)","0.52","0.58"
    "lat_ops-float-mul (ns)","2.86","3.20"
    "lat_ops-int-add (ns)","0.72","0.80"
    "lat_ops-int-bit (ns)","0.48","0.53"
    "lat_ops-int-div (ns)","4.29","4.81"
    "lat_ops-int-mod (ns)","4.53","5.08"
    "lat_ops-int-mul (ns)","2.17","2.43"
    "lat_ops-int64-add (ns)","0.72","0.80"
    "lat_ops-int64-bit (ns)","0.48","0.53"
    "lat_ops-int64-div (ns)","6.80","7.67"
    "lat_ops-int64-mod (ns)","5.24","5.88"
    "lat_pagefault (us)","1.24","1.40"
    "lat_pipe (us)","17.74","19.85"
    "lat_proc-exec (us)","1167.60","1312.00"
    "lat_proc-fork (us)","923.00","1029.20"
    "lat_proc-proccall (us)","0.01","0.01"
    "lat_select (us)","35.68","40.42"
    "lat_sem (us)","1.56","1.95"
    "lat_sig-catch (us)","4.45","4.98"
    "lat_sig-install (us)","0.47","0.54"
    "lat_sig-prot (us)","0.54","0.65"
    "lat_syscall-fstat (us)","1.15","1.29"
    "lat_syscall-null (us)","0.29","0.32"
    "lat_syscall-open (us)","161.65","166.22"
    "lat_syscall-read (us)","0.57","0.65"
    "lat_syscall-stat (us)","3.16","3.53"
    "lat_syscall-write (us)","0.48","0.54"
    "lat_tcp (us)","0.59","0.67"
    "lat_unix (us)","32.39","36.80"
    "latency_for_0.50_mb_block_size (nanosec)","13.10","20.67"
    "latency_for_1.00_mb_block_size (nanosec)","26.06 (min 0.00, max 52.11)","28.88 (min 0.00, max 57.76)"
    "pipe_bandwidth (MBs)","499.88","454.06"
    "pipe_latency (microsec)","17.74","19.85"
    "procedure_call (microsec)","0.01","0.01"
    "select_on_200_tcp_fds (microsec)","35.68","40.42"
    "semaphore_latency (microsec)","1.56","1.95"
    "signal_handler_latency (microsec)","0.47","0.54"
    "signal_handler_overhead (microsec)","4.45","4.98"
    "tcp_ip_connection_cost_to_localhost (microsec)","70.08","77.00"
    "tcp_latency_using_localhost (microsec)","0.59","0.67"


Table:  **LM Bench Metrics**



Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

Execute the benchmark with the following:

::

    runDhrystone

.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf","am62xx_lp_sk-fs: perf"

    "cpu_clock (MHz)","1400.00","1250.00"
    "dhrystone_per_mhz (DMIPS/MHz)","3.00","3.00"
    "dhrystone_per_second (DhrystoneP)","7407407.50","6666666.50"


Table:  **Dhrystone Benchmark**



Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Whetstone is a benchmark primarily measuring floating-point arithmetic performance.

Execute the benchmark with the following:

::

    runWhetstone

.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf","am62xx_lp_sk-fs: perf"

    "whetstone (MIPS)","5000.00","5000.00"


Table:  **Whetstone Benchmark**



Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf","am62xx_lp_sk-fs: perf"

    "linpack (Kflops)","581773.00","521347.00"


Table:  **Linpack Benchmark**



NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html


.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf"

    "assignment (Iterations)","13.63"
    "fourier (Iterations)","22879.00"
    "fp_emulation (Iterations)","107.20"
    "huffman (Iterations)","1174.50"
    "idea (Iterations)","3436.40"
    "lu_decomposition (Iterations)","542.73"
    "neural_net (Iterations)","7.85"
    "numeric_sort (Iterations)","505.15"
    "string_sort (Iterations)","165.88"


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

Execute the benchmark with the following:

::

    stream_c

.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf","am62xx_lp_sk-fs: perf"

    "add (MB/s)","1446.10","1381.50"
    "copy (MB/s)","1640.40","1459.20"
    "scale (MB/s)","1810.50","1545.00"
    "triad (MB/s)","1487.90","1344.60"


Table:  **Stream**



CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.


.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf","am62xx_lp_sk-fs: perf"

    "cjpeg-rose7-preset (workloads/)","41.67","37.45"
    "core (workloads/)","0.30","0.27"
    "coremark-pro ()","904.65","805.20"
    "linear_alg-mid-100x100-sp (workloads/)","14.66","13.09"
    "loops-all-mid-10k-sp (workloads/)","0.66","0.59"
    "nnet_test (workloads/)","1.09","0.97"
    "parser-125k (workloads/)","8.47","7.52"
    "radix2-big-64k (workloads/)","59.17","51.13"
    "sha-test (workloads/)","80.00","71.94"
    "zip-test (workloads/)","21.74","19.23"


Table:  **CoreMarkPro**



.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf","am62xx_lp_sk-fs: perf"

    "cjpeg-rose7-preset (workloads/)","83.33","74.07"
    "core (workloads/)","0.60","0.54"
    "coremark-pro ()","1518.99","1352.66"
    "linear_alg-mid-100x100-sp (workloads/)","29.33","26.16"
    "loops-all-mid-10k-sp (workloads/)","1.14","1.02"
    "nnet_test (workloads/)","2.18","1.94"
    "parser-125k (workloads/)","12.42","10.87"
    "radix2-big-64k (workloads/)","42.58","37.39"
    "sha-test (workloads/)","161.29","142.86"
    "zip-test (workloads/)","39.22","35.71"


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
    :header: "Benchmarks","am62xx-sk: perf","am62xx_lp_sk-fs: perf"

    "4m-check (workloads/)","361.38","322.83"
    "4m-check-reassembly (workloads/)","58.00","60.64"
    "4m-check-reassembly-tcp (workloads/)","44.56","39.94"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","24.70","22.02"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.73","1.30"
    "4m-cmykw2 (workloads/)","200.20","178.25"
    "4m-cmykw2-rotatew2 (workloads/)","39.84","34.97"
    "4m-reassembly (workloads/)","53.91","48.43"
    "4m-rotatew2 (workloads/)","45.91","39.37"
    "4m-tcp-mixed (workloads/)","108.84","96.39"
    "4m-x264w2 (workloads/)","1.87","1.62"
    "empty-wld (workloads/)","1.00",""
    "idct-4m (workloads/)","18.59","16.74"
    "idct-4mw1 (workloads/)","18.58","16.70"
    "ippktcheck-4m (workloads/)","364.01","321.01"
    "ippktcheck-4mw1 (workloads/)","360.33","321.79"
    "ipres-4m (workloads/)","60.85","53.84"
    "ipres-4mw1 (workloads/)","61.10","53.86"
    "md5-4m (workloads/)","28.42","25.03"
    "md5-4mw1 (workloads/)","28.21","25.35"
    "rgbcmyk-4m (workloads/)","63.49","56.55"
    "rgbcmyk-4mw1 (workloads/)","63.71","56.79"
    "rotate-4ms1 (workloads/)","18.44","16.53"
    "rotate-4ms1w1 (workloads/)","18.48","16.63"
    "rotate-4ms64 (workloads/)","18.56","16.65"
    "rotate-4ms64w1 (workloads/)","18.59","16.56"
    "x264-4mq (workloads/)","0.56","0.50"
    "x264-4mqw1 (workloads/)","0.51","0.50"


Table:  **Multibench**


 
 

 

 



 


Graphics SGX/RGX Driver
-------------------------
 


GFXBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Run GFXBench and capture performance reported (Score and Display rate in fps). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am62xx-sk: Score","am62xx-sk: Fps","am62xx_lp_sk-fs: Score","am62xx_lp_sk-fs: Fps"

    " GFXBench 5.x gl_5_high_off","11.48","0.18","11.55","0.18"


Table:  **GFXBench**



Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am62xx-sk: Score","am62xx_lp_sk-fs: Score"

    "Glmark2-Wayland","186.00","161.00"


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

- CPSW2g: AM65x, J7200, J721e, J721S2, J784S4
- CPSW3g: AM64x


.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","am62xx-sk: THROUGHPUT (Mbits/sec)","am62xx-sk: CPU Load % (LOCAL_CPU_UTIL)","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1719.54","46.31","1597.36","49.45"

Table: **CPSW TCP Bidirectional Throughput**
|



.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am62xx-sk: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx-sk: THROUGHPUT (Mbits/sec)","am62xx-sk: CPU Load % (LOCAL_CPU_UTIL)","am62xx_lp_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","13.77","37.27","18.00","12.17","37.08"
    "128","82.00","61.93","37.11","82.00","50.41","35.16"
    "256","210.00","157.63","37.11","210.00","129.66","35.32"
    "1024","978.00","882.49","42.39","978.00","348.05","21.80"
    "1518","1472.00","135.42","3.10","1472.00","870.39","37.10"

Table: **CPSW UDP Egress Throughput**
|



.. csv-table::
    :header: "Frame Size(bytes)","am62xx-sk: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx-sk: THROUGHPUT (Mbits/sec)","am62xx-sk: CPU Load % (LOCAL_CPU_UTIL)","am62xx_lp_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","8.55","17.12","18.00","2.33","4.67"
    "128","82.00","11.15","3.70","82.00","6.30","8.57"
    "256","210.00","109.53","16.04","210.00","21.17","4.87"
    "1024","978.00","212.03","12.93","978.00","132.22","3.52"
    "1518","1472.00","957.04","39.57","1472.00","314.41","14.81"


Table: **CPSW UDP Ingress Throughput (0% loss)**

|



.. csv-table::
    :header: "Frame Size(bytes)","am62xx-sk: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx-sk: THROUGHPUT (Mbits/sec)","am62xx-sk: CPU Load % (LOCAL_CPU_UTIL)","am62xx-sk: Packet Loss %","am62xx_lp_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_lp_sk-fs: Packet Loss %"

    "64","18.00","25.42","39.69","36.21","18.00","18.70","35.22","63.02"
    "128","82.00","115.68","41.30","53.69","82.00","81.03","41.40","16.75"
    "256","210.00","281.24","44.48","53.92","210.00","211.33","37.66","62.92"
    "1024","978.00","935.93","39.21","0.06","978.00","863.78","40.17","7.06"
    "1518","1472.00","956.59","39.46","0.04","1472.00","956.46","40.52","0.06"

Table: **CPSW UDP Ingress Throughput (possible loss)**

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

    "1m","18.00","0.87","87.60","1.41"
    "4m","18.30","0.75","80.60","1.30"
    "4k","5.35","2.84","16.80","6.02"
    "256k","19.00","1.17","85.30","1.72"

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
    :header: "Algorithm","Buffer Size (in bytes)","am62xx-sk: throughput (KBytes/Sec)","am62xx_lp_sk-fs: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","231939.41","206916.95"
    "aes-128-cbc","16","4927.82","4407.99"
    "aes-128-cbc","16384","654098.43","582920.87"
    "aes-128-cbc","256","72672.43","64460.89"
    "aes-128-cbc","64","19475.09","17233.51"
    "aes-128-cbc","8192","579556.69","517499.56"
    "aes-192-cbc","1024","219130.20","196784.47"
    "aes-192-cbc","16","4923.08","4388.95"
    "aes-192-cbc","16384","565848.75","507177.64"
    "aes-192-cbc","256","70948.35","63612.67"
    "aes-192-cbc","64","19254.91","17231.59"
    "aes-192-cbc","8192","512087.38","456583.85"
    "aes-256-cbc","1024","211012.61","188492.12"
    "aes-256-cbc","16","4903.49","4380.55"
    "aes-256-cbc","16384","515320.49","461253.29"
    "aes-256-cbc","256","70183.34","62652.59"
    "aes-256-cbc","64","19079.66","17062.51"
    "aes-256-cbc","8192","469909.50","419575.13"
    "des-cbc","1024","26105.17","23241.73"
    "des-cbc","16","5203.38","4599.06"
    "des-cbc","16384","27667.11","24657.92"
    "des-cbc","256","21917.10","19489.79"
    "des-cbc","64","13308.95","11832.21"
    "des-cbc","8192","27552.43","24565.08"
    "des3","1024","10566.66","9791.49"
    "des3","16","4052.52","3605.03"
    "des3","16384","11239.42","10037.93"
    "des3","256","8542.98","9054.89"
    "des3","64","7796.95","6948.31"
    "des3","8192","11231.23","10013.35"
    "md5","1024","51471.70","46592.00"
    "md5","16","1120.82","1024.30"
    "md5","16384","153938.60","136942.93"
    "md5","256","16328.79","14823.94"
    "md5","64","4373.87","3987.99"
    "md5","8192","135965.35","121014.95"
    "sha1","1024","62358.53","55603.54"
    "sha1","16","1086.12","964.98"
    "sha1","16384","363550.04","323234.47"
    "sha1","256","16986.45","15101.35"
    "sha1","64","4329.37","3840.28"
    "sha1","8192","273566.38","243627.35"
    "sha224","1024","60982.27","54327.64"
    "sha224","16","1063.24","946.01"
    "sha224","16384","371081.22","329531.39"
    "sha224","256","16469.42","14688.51"
    "sha224","64","4200.04","3748.67"
    "sha224","8192","275884.71","244607.66"
    "sha256","1024","61202.09","54808.58"
    "sha256","16","1061.38","955.08"
    "sha256","16384","370130.94","330541.74"
    "sha256","256","16495.10","14846.46"
    "sha256","64","4202.71","3783.10"
    "sha256","8192","274909.87","245429.59"
    "sha384","1024","36339.37","32865.28"
    "sha384","16","1037.43","948.48"
    "sha384","16384","74257.75","66398.89"
    "sha384","256","13717.85","12512.43"
    "sha384","64","4153.30","3808.11"
    "sha384","8192","69307.05","62040.75"
    "sha512","1024","36271.79","32656.73"
    "sha512","16","1031.84","937.09"
    "sha512","16384","74290.52","66207.74"
    "sha512","256","13665.19","12335.70"
    "sha512","64","4131.11","3752.19"
    "sha512","8192","69296.13","61743.10"


|
|



.. csv-table::
    :header: "Algorithm","am62xx-sk: CPU Load","am62xx_lp_sk-fs: CPU Load"

    "aes-128-cbc","98.00","98.00"
    "aes-192-cbc","98.00","98.00"
    "aes-256-cbc","98.00","98.00"
    "des-cbc","98.00","98.00"
    "des3","96.00","98.00"
    "md5","98.00","98.00"
    "sha1","98.00","98.00"
    "sha224","98.00","98.00"
    "sha256","98.00","98.00"
    "sha384","98.00","98.00"
    "sha512","98.00","98.00"

 

Listed for each algorithm are the code snippets used to run each
  benchmark test.

::
    time -v openssl speed -elapsed -evp aes-128-cbc

 




IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am62xx-sk: Throughput (Mbps)","am62xx-sk: Packets/Sec","am62xx-sk: CPU Load","am62xx_lp_sk-fs: Throughput (Mbps)","am62xx_lp_sk-fs: Packets/Sec","am62xx_lp_sk-fs: CPU Load"

    "3des","69.00","6.00","25.06","60.60","5.00","24.61"
    "aes128","238.00","21.00","25.50","222.60","19.00","25.52"
    "aes192","237.90","21.00","25.46","210.00","18.00","25.57"
    "aes256","239.30","21.00","25.51","221.00","19.00","25.59"

 

