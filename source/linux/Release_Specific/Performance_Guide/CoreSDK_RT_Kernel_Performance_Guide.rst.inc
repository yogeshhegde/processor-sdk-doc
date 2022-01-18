..  http://processors.wiki.ti.com/index.php/CoreSDK_Linux_RT_Kernel_Performance_Guide


======================================
RT-linux 08.01.00 Performance Guide
======================================

.. rubric::  **Read This First**
  :name: read-this-first-rt-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+---------------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                         |
+================+=====================================================================================================================+
| AM335x         | AM335x Evaluation Module rev 1.5B with ARM running at 1000MHz, DDR3-400 (400MHz/800 MT/S), TMDXEVM3358              |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| AM437x-gpevm   | AM437x-gpevm Evaluation Module rev 1.5A with ARM running at 1000MHz, DDR3-400 (400MHz/800 MT/S), TMDSEVM437X        |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| AM572x IDK     | AM57xx Evaluation Module rev A2 with ARM running at 1500MHz, DDR3L-533 (533 MHz/1066 MT/S), TMDXIDK5278             |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| AM574x IDK     | AM57xx Industrial Development Kit rev 1.0A  with ARM running at 1500MHz, DDR3L-533 (533 MHz/1066 MT/S), TMDXIDK5278 |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| AM64x EVM      | AM64x Evaluation Module rev E1 with ARM running at 1GHz, DDR data rate 1600 MT/S                                    |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| AM65x EVM      | AM65x Evaluation Module rev 1.0 with ARM running at 800MHz, DDR4-2400 (1600 MT/S), TMDX654GPEVM                     |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| J721e EVM      | J721e Evaluation Module rev E2 with ARM running at 2GHz, DDR data rate 4266 MT/S, L3 Cache size 3MB                 |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| J7200 EVM      | J7200 Evaluation Module rev E2 with ARM running at 2GHz, DDR data rate 2666 MT/S, L3 Cache size 3MB                 |
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
   :header: "Benchmarks","am64xx-evm: perf","am654x-evm: perf"

   "af_unix_sock_stream_latency (microsec)","51.25","64.10"
   "af_unix_socket_stream_bandwidth (MB/s)","726.10","1131.62"
   "bw_file_rd-io-1mb (MB/s)","833.75","969.18"
   "bw_file_rd-o2c-1mb (MB/s)","495.70","515.64"
   "bw_mem-bcopy-16mb (MB/s)","868.81","878.78"
   "bw_mem-bcopy-1mb (MB/s)","915.75","1028.98"
   "bw_mem-bcopy-2mb (MB/s)","898.07","876.42"
   "bw_mem-bcopy-4mb (MB/s)","911.68","865.89"
   "bw_mem-bcopy-8mb (MB/s)","923.25","881.74"
   "bw_mem-bzero-16mb (MB/s)","2125.40","1645.75"
   "bw_mem-bzero-1mb (MB/s)","1520.77 (min 915.75, max 2125.78)","2766.74 (min 1028.98, max 4504.50)"
   "bw_mem-bzero-2mb (MB/s)","1507.24 (min 898.07, max 2116.40)","1602.94 (min 876.42, max 2329.45)"
   "bw_mem-bzero-4mb (MB/s)","1517.79 (min 911.68, max 2123.89)","1283.89 (min 865.89, max 1701.89)"
   "bw_mem-bzero-8mb (MB/s)","1524.04 (min 923.25, max 2124.83)","1264.17 (min 881.74, max 1646.60)"
   "bw_mem-cp-16mb (MB/s)","522.21","576.95"
   "bw_mem-cp-1mb (MB/s)","1523.89 (min 574.71, max 2473.06)","2603.03 (min 662.25, max 4543.80)"
   "bw_mem-cp-2mb (MB/s)","1368.88 (min 551.57, max 2186.19)","1467.98 (min 596.39, max 2339.57)"
   "bw_mem-cp-4mb (MB/s)","1345.86 (min 532.27, max 2159.44)","1146.42 (min 587.80, max 1705.03)"
   "bw_mem-cp-8mb (MB/s)","1373.59 (min 606.43, max 2140.75)","1125.90 (min 597.37, max 1654.43)"
   "bw_mem-fcp-16mb (MB/s)","811.11","819.46"
   "bw_mem-fcp-1mb (MB/s)","1489.15 (min 852.51, max 2125.78)","2740.37 (min 976.24, max 4504.50)"
   "bw_mem-fcp-2mb (MB/s)","1491.98 (min 867.55, max 2116.40)","1574.79 (min 820.12, max 2329.45)"
   "bw_mem-fcp-4mb (MB/s)","1477.58 (min 831.26, max 2123.89)","1261.63 (min 821.36, max 1701.89)"
   "bw_mem-fcp-8mb (MB/s)","1521.24 (min 917.64, max 2124.83)","1236.40 (min 826.19, max 1646.60)"
   "bw_mem-frd-16mb (MB/s)","1267.43","1284.73"
   "bw_mem-frd-1mb (MB/s)","1099.21 (min 852.51, max 1345.90)","1257.88 (min 976.24, max 1539.51)"
   "bw_mem-frd-2mb (MB/s)","1080.82 (min 867.55, max 1294.08)","1113.54 (min 820.12, max 1406.96)"
   "bw_mem-frd-4mb (MB/s)","1076.13 (min 831.26, max 1321.00)","1057.83 (min 821.36, max 1294.29)"
   "bw_mem-frd-8mb (MB/s)","1153.63 (min 917.64, max 1389.61)","1052.59 (min 826.19, max 1278.98)"
   "bw_mem-fwr-16mb (MB/s)","2136.18","1650.17"
   "bw_mem-fwr-1mb (MB/s)","1909.48 (min 1345.90, max 2473.06)","3041.66 (min 1539.51, max 4543.80)"
   "bw_mem-fwr-2mb (MB/s)","1740.14 (min 1294.08, max 2186.19)","1873.27 (min 1406.96, max 2339.57)"
   "bw_mem-fwr-4mb (MB/s)","1740.22 (min 1321.00, max 2159.44)","1499.66 (min 1294.29, max 1705.03)"
   "bw_mem-fwr-8mb (MB/s)","1765.18 (min 1389.61, max 2140.75)","1466.71 (min 1278.98, max 1654.43)"
   "bw_mem-rd-16mb (MB/s)","1386.60","1294.71"
   "bw_mem-rd-1mb (MB/s)","1166.48 (min 932.14, max 1400.81)","3369.67 (min 3097.67, max 3641.66)"
   "bw_mem-rd-2mb (MB/s)","1136.15 (min 878.09, max 1394.21)","1182.05 (min 919.54, max 1444.56)"
   "bw_mem-rd-4mb (MB/s)","1143.20 (min 887.31, max 1399.09)","1034.64 (min 755.43, max 1313.84)"
   "bw_mem-rd-8mb (MB/s)","1161.72 (min 926.78, max 1396.65)","1017.34 (min 741.43, max 1293.24)"
   "bw_mem-rdwr-16mb (MB/s)","917.27","730.59"
   "bw_mem-rdwr-1mb (MB/s)","729.60 (min 574.71, max 884.49)","1912.52 (min 662.25, max 3162.79)"
   "bw_mem-rdwr-2mb (MB/s)","692.34 (min 551.57, max 833.10)","714.23 (min 596.39, max 832.06)"
   "bw_mem-rdwr-4mb (MB/s)","686.79 (min 532.27, max 841.31)","666.55 (min 587.80, max 745.30)"
   "bw_mem-rdwr-8mb (MB/s)","719.49 (min 606.43, max 832.55)","665.53 (min 597.37, max 733.68)"
   "bw_mem-wr-16mb (MB/s)","945.18","741.91"
   "bw_mem-wr-1mb (MB/s)","908.32 (min 884.49, max 932.14)","3402.23 (min 3162.79, max 3641.66)"
   "bw_mem-wr-2mb (MB/s)","855.60 (min 833.10, max 878.09)","875.80 (min 832.06, max 919.54)"
   "bw_mem-wr-4mb (MB/s)","864.31 (min 841.31, max 887.31)","750.37 (min 745.30, max 755.43)"
   "bw_mem-wr-8mb (MB/s)","879.67 (min 832.55, max 926.78)","737.56 (min 733.68, max 741.43)"
   "bw_mmap_rd-mo-1mb (MB/s)","1246.44","2758.15"
   "bw_mmap_rd-o2c-1mb (MB/s)","464.83","532.86"
   "bw_pipe (MB/s)","268.03","320.04"
   "bw_unix (MB/s)","726.10","1131.62"
   "lat_connect (us)","90.68","101.45"
   "lat_ctx-2-128k (us)","8.77","8.43"
   "lat_ctx-2-256k (us)","23.90","5.51"
   "lat_ctx-4-128k (us)","9.32","7.91"
   "lat_ctx-4-256k (us)","7.57","3.37"
   "lat_fs-0k (num_files)","159.00","173.00"
   "lat_fs-10k (num_files)","74.00","74.00"
   "lat_fs-1k (num_files)","101.00","108.00"
   "lat_fs-4k (num_files)","108.00","97.00"
   "lat_mem_rd-stride128-sz1000k (ns)","46.80","26.62"
   "lat_mem_rd-stride128-sz125k (ns)","7.78","9.74"
   "lat_mem_rd-stride128-sz250k (ns)","15.67","10.23"
   "lat_mem_rd-stride128-sz31k (ns)","5.11","7.35"
   "lat_mem_rd-stride128-sz50 (ns)","3.01","3.76"
   "lat_mem_rd-stride128-sz500k (ns)","43.31","11.62"
   "lat_mem_rd-stride128-sz62k (ns)","7.29","9.18"
   "lat_mmap-1m (us)","74.00","76.00"
   "lat_ops-double-add (ns)","0.73","0.92"
   "lat_ops-double-mul (ns)","4.03","5.05"
   "lat_ops-float-add (ns)","0.73","0.91"
   "lat_ops-float-mul (ns)","4.04","5.02"
   "lat_ops-int-add (ns)","1.01","1.26"
   "lat_ops-int-bit (ns)","0.67","0.83"
   "lat_ops-int-div (ns)","6.06","7.52"
   "lat_ops-int-mod (ns)","6.38","7.96"
   "lat_ops-int-mul (ns)","3.05","3.81"
   "lat_ops-int64-add (ns)","1.01","1.26"
   "lat_ops-int64-bit (ns)","0.67","0.84"
   "lat_ops-int64-div (ns)","9.54","11.98"
   "lat_ops-int64-mod (ns)","7.36","9.21"
   "lat_pagefault (us)","1.85","1.95"
   "lat_pipe (us)","26.60","33.55"
   "lat_proc-exec (us)","1909.33","1696.00"
   "lat_proc-fork (us)","1576.00","1462.00"
   "lat_proc-proccall (us)","0.01","0.01"
   "lat_select (us)","42.20","53.35"
   "lat_sem (us)","3.93","8.24"
   "lat_sig-catch (us)","7.95","9.88"
   "lat_sig-install (us)","0.82","1.03"
   "lat_sig-prot (us)","0.39","0.61"
   "lat_syscall-fstat (us)","1.94","2.43"
   "lat_syscall-null (us)","0.40","0.52"
   "lat_syscall-open (us)","407.71","305.50"
   "lat_syscall-read (us)","0.77","0.96"
   "lat_syscall-stat (us)","5.32","6.63"
   "lat_syscall-write (us)","0.65","0.81"
   "lat_tcp (us)","0.80","1.01"
   "lat_unix (us)","51.25","64.10"
   "latency_for_0.50_mb_block_size (nanosec)","43.31","11.62"
   "latency_for_1.00_mb_block_size (nanosec)","23.40 (min 0.00, max 46.80)","13.31 (min 0.00, max 26.62)"
   "pipe_bandwidth (MBs)","268.03","320.04"
   "pipe_latency (microsec)","26.60","33.55"
   "procedure_call (microsec)","0.01","0.01"
   "select_on_200_tcp_fds (microsec)","42.20","53.35"
   "semaphore_latency (microsec)","3.93","8.24"
   "signal_handler_latency (microsec)","0.82","1.03"
   "signal_handler_overhead (microsec)","7.95","9.88"
   "tcp_ip_connection_cost_to_localhost (microsec)","90.68","101.45"
   "tcp_latency_using_localhost (microsec)","0.80","1.01"

Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

.. csv-table::
   :header: "Benchmarks","am64xx-evm: perf","am654x-evm: perf"

   "cpu_clock (MHz)","1000.00","800.00"
   "dhrystone_per_mhz (DMIPS/MHz)","2.92","2.96"
   "dhrystone_per_second (DhrystoneP)","5128205.00","4166666.80"

Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
   :header: "Benchmarks","am64xx-evm: perf","am654x-evm: perf"

   "whetstone (MIPS)","3333.30","3333.30"

Table:  **Whetstone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
   :header: "Benchmarks","am64xx-evm: perf","am654x-evm: perf"

   "linpack (Kflops)","396230.00","326906.00"

Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks 
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html

.. csv-table::
   :header: "Benchmarks","am64xx-evm: perf","am654x-evm: perf"

   "assignment (Iterations)","9.75","7.81"
   "fourier (Iterations)","16243.00","13069.00"
   "fp_emulation (Iterations)","76.56","61.25"
   "huffman (Iterations)","837.98","670.76"
   "idea (Iterations)","2452.10","1962.90"
   "lu_decomposition (Iterations)","390.58","313.06"
   "neural_net (Iterations)","5.60","4.48"
   "numeric_sort (Iterations)","360.40","289.24"
   "string_sort (Iterations)","118.45","94.76"

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
   :header: "Benchmarks","am64xx-evm: perf","am654x-evm: perf"

   "add (MB/s)","1690.80","1630.00"
   "copy (MB/s)","1955.60","1787.20"
   "scale (MB/s)","2326.70","1809.40"
   "triad (MB/s)","1693.50","1524.10"

Table:  **Stream**

CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.

.. csv-table::
   :header: "Benchmarks","am64xx-evm: perf"

   "cjpeg-rose7-preset (workloads/)","29.85"
   "core (workloads/)","0.21"
   "coremark-pro ()","582.00"
   "linear_alg-mid-100x100-sp (workloads/)","10.45"
   "loops-all-mid-10k-sp (workloads/)","0.49"
   "nnet_test (workloads/)","0.78"
   "parser-125k (workloads/)","4.95"
   "radix2-big-64k (workloads/)","19.39"
   "sha-test (workloads/)","57.80"
   "zip-test (workloads/)","15.63"

Table:  **CoreMarkPro**

.. csv-table::
   :header: "Benchmarks","am64xx-evm: perf"

   "cjpeg-rose7-preset (workloads/)","57.14"
   "core (workloads/)","0.43"
   "coremark-pro ()","1070.90"
   "linear_alg-mid-100x100-sp (workloads/)","20.54"
   "loops-all-mid-10k-sp (workloads/)","0.89"
   "nnet_test (workloads/)","1.55"
   "parser-125k (workloads/)","6.56"
   "radix2-big-64k (workloads/)","34.47"
   "sha-test (workloads/)","114.94"
   "zip-test (workloads/)","28.99"

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
   :header: "Benchmarks","am64xx-evm: perf"

   "4m-check (workloads/)","322.21"
   "4m-check-reassembly (workloads/)","62.66"
   "4m-check-reassembly-tcp (workloads/)","37.99"
   "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","15.42"
   "4m-check-reassembly-tcp-x264w2 (workloads/)","0.76"
   "4m-cmykw2 (workloads/)","87.72"
   "4m-cmykw2-rotatew2 (workloads/)","18.09"
   "4m-reassembly (workloads/)","52.00"
   "4m-rotatew2 (workloads/)","25.13"
   "4m-tcp-mixed (workloads/)","84.66"
   "4m-x264w2 (workloads/)","0.77"
   "empty-wld (workloads/)","1.00"
   "idct-4m (workloads/)","13.69"
   "idct-4mw1 (workloads/)","13.70"
   "ippktcheck-4m (workloads/)","323.16"
   "ippktcheck-4mw1 (workloads/)","322.46"
   "ipres-4m (workloads/)","67.75"
   "ipres-4mw1 (workloads/)","69.00"
   "md5-4m (workloads/)","18.68"
   "md5-4mw1 (workloads/)","18.86"
   "rgbcmyk-4m (workloads/)","44.73"
   "rgbcmyk-4mw1 (workloads/)","44.63"
   "rotate-4ms1 (workloads/)","17.12"
   "rotate-4ms1w1 (workloads/)","17.23"
   "rotate-4ms64 (workloads/)","17.32"
   "rotate-4ms64w1 (workloads/)","17.33"
   "x264-4mq (workloads/)","0.41"
   "x264-4mqw1 (workloads/)","0.41"

Table:  **Multibench**

Spec2K6
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CPU2006 is a set of benchmarks designed to test the CPU performance of a modern server
computer system. It is split into two components, the first being CINT2006,
the other being CFP2006 (SPECfp), for floating point testing.

SPEC defines a base runtime for each of the 12 benchmark programs.
For SPECint2006, that number ranges from 1000 to 3000 seconds. The timed test is run on
the system, and the time of the test system is compared to the reference time, and a ratio
is computed. That ratio becomes the SPECint score for that test. (This differs from the rating
in SPECINT2000, which multiplies the ratio by 100.)

As an example for SPECint2006, consider a processor which can run 400.perlbench in 2000 seconds.
The time it takes the reference machine to run the benchmark is 9770 seconds. Thus the ratio is 4.885.
Each ratio is computed, and then the geometric mean of those ratios is computed to produce an overall value.

Rate (Multiple Cores)

Table:  **Spec2K6**

Speed (Single Core)

Table:  **Spec2K6 Speed**

Maximum Latency under different use cases
------------------------------------------

Shield (dedicated core) Case
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
| The following tests measure worst-case latency under different
 scenarios or use cases.
| Cyclictest application was used to measured latency. Each test ran for
 4 hours.
| Two cgroups were used using shield\_shell procedure shown below.
| The application running the use case and cyclictest ran on a dedicated
 cpu (rt) while the rest of threads ran on nonrt cpu.

::

   shield_shell()
   {
   create_cgroup nonrt 0
   create_cgroup rt 1
   for pid in $(cat /sys/fs/cgroup/tasks); do /bin/echo $pid > /sys/fs/cgroup/nonrt/tasks; done
   /bin/echo $$ > /sys/fs/cgroup/rt/tasks
   }

|


AM64XX-EVM
"""""""""""""""""""""""""""""""

.. csv-table::
    :header: "Benchmarks","Core #1 (nonrt)","Core#2 (rt)"

    "Min Latencies","6", "6"
    "Avg Latencies","8", "8"
    "Max Latencies","92", "72"

Table:  **Cyclic test for Two Cores**

AM654X-EVM
"""""""""""""""""""""""""""""""
.. csv-table::
    :header: "Benchmarks","Core #1 (nonrt)","Core#2 (rt)", "Core#3 (rt)" ,"Core#4 (rt)"

    "Min Latencies","9", "9", "9", "9"
    "Avg Latencies","12", "12", "12", "13"
    "Max Latencies","54", "48", "50", "60"

Table:  **Cyclic test for Four Cores**

|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am64xx-evm: boot time (sec)","am654x-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","28.74 (min 27.17, max 32.35)","25.77 (min 25.09, max 26.70)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","3.43 (min 3.42, max 3.47)","4.91 (min 4.87, max 5.02)"

Table:  **Boot time MMC/SD**

Boot media: NAND
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Table:  **Boot time NAND**

ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64

.. csv-table::
   :header: "Sampling Rate (Hz)","am654x-evm: Throughput (bits/sec)","am654x-evm: CPU Load (%)"

   "8000","255999.00","0.24"
   "11025","352798.00","0.40"
   "16000","511997.00","0.30"
   "22050","705596.00","0.63"
   "24000","705596.00","0.65"
   "32000","1023994.00","2.78"
   "44100","1411191.00","1.11"
   "48000","1535990.00","0.58"
   "88200","2822377.00","2.13"
   "96000","3071974.00","0.98"

Table:  **Audio Capture**

|

.. csv-table::
   :header: "Sampling Rate (Hz)","am654x-evm: Throughput (bits/sec)","am654x-evm: CPU Load (%)"

   "8000","256100.00","0.20"
   "11025","352937.00","0.19"
   "16000","512201.00","0.22"
   "22050","705870.00","0.34"
   "24000","768288.00","0.32"
   "32000","1024404.00","0.35"
   "44100","1411638.00","0.45"
   "48000","1536437.00","0.49"
   "88200","1536436.00","0.47"
   "96000","1536437.00","0.49"

Table:  **Audio Playback**

|

Sensor Capture
-------------------------

Capture video frames (MMAP buffers) with v4l2c-ctl and record the
reported fps

.. csv-table::
   :header: "Resolution","Format","am654x-evm: Fps","am654x-evm: Sensor"

   "176x144","uyvy","30.02","ov5640"
   "1920x1080","uyvy","30.00","ov5640"

Table:  **Sensor Capture**

|

Display Driver
-------------------------

|

Graphics SGX/RGX Driver
-------------------------

GLBenchmark
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run GLBenchmark and capture performance reported Display rate (Fps),
Fill rate, Vertex Throughput, etc. All display outputs (HDMI, Displayport and/or LCD)
are connected when running these tests

Performance (Fps)
"""""""""""""""""""""""""""

Table:  **GLBenchmark 2.5 Performance**

Vertex Throughput
"""""""""""""""""""""""""""

Table:  **GLBenchmark 2.5 Vertex Throughput**

Pixel Throughput
"""""""""""""""""""""""""""

Table:  **GLBenchmark 2.5 Pixel Throughput**

GFXBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Run GFXBench and capture performance reported (Score and Display rate in fps). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

Table:  **GFXBench**

Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

Table:  **Glmark2**

|

Multimedia (Decode)
-------------------------

Run gstreamer pipeline "gst-launch-1.0 playbin uri=\ file://\ <Path to
stream> video-sink="kmssink sync=false connector=<connector id>"
audio-sink=fakesink" and calculate performance based on the execution
time reported. All display display outputs (HDMI and LCD) were connected
when running these tests, but playout was forced to LCD via the
connector=<connector id> option.

H264
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Table:  **Gstreamer H264 in AVI Container Decode Performance**

|

MPEG4
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Table:  **GStreamer MPEG4 in 3GP Container Decode Performance**

|

MPEG2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Table:  **GStreamer MPEG2 in MP4 Container Decode Performance**

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
   :header: "Command Used","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: CPU Load % (LOCAL_CPU_UTIL)"

   "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1004.34","97.86","1548.57","59.72"

Table: **CPSW TCP Bidirectional Throughput**

|

.. rubric::  UDP Throughput 
  :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
   :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","am654x-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: CPU Load % (LOCAL_CPU_UTIL)"

   "64","18.00","7.47","87.20","18.00","9.95","48.66"
   "128","82.00","33.10","86.56","82.00","45.76","49.13"
   "256","210.00","84.16","86.45","210.00","116.08","48.98"
   "512","466.00","264.81","49.04"
   "1024","978.00","373.49","84.69","978.00","516.50","49.20"
   "1518","1472.00","554.49","84.63","1472.00","767.00","50.01"

Table: **CPSW UDP Egress Throughput**

|

.. csv-table::
   :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","am654x-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: CPU Load % (LOCAL_CPU_UTIL)"

   "64","18.00","1.05","3.68"
   "128","82.00","5.90","4.12","82.00","8.00","7.52"
   "256","210.00","16.97","16.92","210.00","20.50","7.01"
   "512","466.00","49.95","7.06"
   "1024","978.00","80.59","18.04","978.00","140.05","9.80"
   "1518","1472.00","122.46","6.78","1472.00","127.18","7.03"

Table: **CPSW UDP Ingress Throughput**

|

.. csv-table::
   :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","am64xx-evm: Packet Loss %","am654x-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: CPU Load % (LOCAL_CPU_UTIL)","am654x-evm: Packet Loss %"

   "64","18.00","16.75","39.08","48.26"
   "128","82.00","67.31","56.35","70.71","82.00","73.69","38.40","50.99"
   "256","210.00","165.79","55.32","53.79","210.00","184.71","39.49","47.93"
   "512","466.00","397.44","39.76","50.34"
   "1024","978.00","639.22","52.44","31.65","978.00","791.87","39.75","15.47"
   "1518","1472.00","868.78","64.40","9.13","1472.00","934.74","39.72","2.33"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|

ICSSG Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput 
  :name: tcp-bidirectional-throughput

.. csv-table::
   :header: "Command Used","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: CPU Load % (LOCAL_CPU_UTIL)"

   "netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_MAERTS","151.16","25.52"

Table: **ICSSG TCP Bidirectional Throughput**

|

.. rubric::  UDP Throughput 
  :name: udp-throughput-0-loss

.. csv-table::
   :header: "Frame Size(bytes)","am654x-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: CPU Load % (LOCAL_CPU_UTIL)"

   "64","18.00","10.10","48.69"
   "128","82.00","45.52","48.26"
   "256","210.00","117.48","48.14"
   "1024","978.00","23.47","9.34"
   "1518","1472.00","747.33","49.86"

Table: **ICSSG UDP Egress Throughput**

|

.. csv-table::
   :header: "Frame Size(bytes)","am654x-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: CPU Load %"

   "64","18.00","1.61","8.11"
   "128","82.00","7.74","9.78"
   "256","210.00","19.82","10.97"
   "1518","1472.00","95.73","14.20"

Table: **ICSSG UDP Ingress Throughput**

|

PCIe Driver
-------------------------

PCIe-ETH
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
   :header: "TCP Window Size(Kbytes)","am654x-evm: Bandwidth (Mbits/sec)"

   "128","0.00"
   "256","0.00"

Table: **PCI Ethernet**

PCIe-EP
^^^^^^^^^^^^^^^^^^^^^^^^^^^

PCIe-NVMe-SSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

AM64xx-EVM
"""""""""""""""""""""""""""

.. csv-table::
   :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

   "1m","363.00","19.88","398.00","15.30"
   "4m","360.00","16.75","398.00","13.50"
   "4k","64.90","52.04","82.20","49.69"
   "256k","374.00","25.95","397.00","16.77"

- File size used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x1
- SSD being used: Lite-On Technology Corporation M8Pe Series NVMe SSD [14a4:22f1] (rev 01)

NAND Driver
-------------------------

OSPI Flash Driver
-------------------------

AM64XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

UBIFS
"""""""""""""""""""""""""""

.. csv-table::
   :header: "Buffer size (bytes)","am64xx-evm: Write UBIFS Throughput (Mbytes/sec)","am64xx-evm: Write UBIFS CPU Load (%)","am64xx-evm: Read UBIFS Throughput (Mbytes/sec)","am64xx-evm: Read UBIFS CPU Load (%)"

   "102400","0.18 (min 0.12, max 0.29)","54.67 (min 54.31, max 54.92)","44.95","60.00"
   "262144","0.14 (min 0.10, max 0.18)","54.16 (min 53.83, max 54.53)","45.34","50.00"
   "524288","0.14 (min 0.10, max 0.18)","54.40 (min 53.92, max 54.92)","47.01","44.44"
   "1048576","0.14 (min 0.10, max 0.18)","54.19 (min 53.58, max 54.61)","43.81","44.44"

RAW
"""""""""""""""""""""""""""

.. csv-table::
   :header: "File size (Mbytes)","am64xx-evm: Raw Read Throughput (Mbytes/sec)"

   "50","131.58"

QSPI Flash Driver
-------------------------

SPI Flash Driver
-------------------------

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

   "1m","58.60","4.69","313.00","14.37"
   "4m","58.90","3.17","312.00","11.71"
   "4k","41.80","53.05","54.60","65.23"
   "256k","59.20","6.95","313.00","18.62"

|

SATA Driver
-------------------------

|

-  File size used is : 1G
-  SATA II Hard disk used is: Seagate ST3500514NS 500G

mSATA Driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^

|

-  File size used is : 1G
-  MSATA Hard disk used is: SMS200S3/30G Kingston mSATA SSD drive

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

   "1m","19.80","2.46","87.50","5.23"
   "4m","18.50","2.10","84.50","3.96"
   "4k","4.95","11.61","16.70","20.55"
   "256k","19.00","3.41","85.30","6.76"

|

AM654x-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
   :header: "Buffer size (bytes)","am654x-evm: Write EXT4 Throughput (Mbytes/sec)","am654x-evm: Write EXT4 CPU Load (%)","am654x-evm: Read EXT4 Throughput (Mbytes/sec)","am654x-evm: Read EXT4 CPU Load (%)"

   "1m","25.20","0.90","86.60","1.38"
   "4m","24.20","0.81","85.30","1.26"
   "4k","2.28","2.62","12.10","9.20"
   "256k","22.10","1.15","83.90","2.25"

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

USB Driver
-------------------------

USB Host Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. warning::

 **IMPORTANT**: For Mass-storage applications, the performance numbers can be severely
 affected if the media is mounted in sync mode. Hot plug scripts in the
 filesystem mount removable media in sync mode to ensure data
 integrity. For performance sensitive applications, umount the
 auto-mounted filesystem and re-mount in async mode.

|

**Setup** : SAMSUNG 850 PRO 2.5" 128GB SATA III Internal Solid State Drive (SSD) used with Inateck ASM1153E enclosure is
connected to usb port under test. File read/write performance data is captured.

|

AM64XX-EVM
"""""""""""""""""""""""""""""""
|

.. csv-table::
   :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

   "1m","37.00","8.03","37.40","7.27"
   "4m","37.70","7.39","37.80","6.79"
   "4k","15.20","35.51","16.20","32.52"
   "256k","35.30","10.20","36.40","11.06"

|

USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

Table: **USBDEVICE HIGHSPEED SLAVE READ THROUGHPUT**

.. csv-table::
   :header: "Number of Blocks","am64xx-evm: Throughput (MB/sec)","am654x-evm: Throughput (MB/sec)"

   "150","39.30","34.70"

|

Table: **USBDEVICE HIGHSPEED SLAVE WRITE THROUGHPUT**

.. csv-table::
   :header: "Number of Blocks","am64xx-evm: Throughput (MB/sec)","am654x-evm: Throughput (MB/sec)"

   "150","25.50","32.50"

|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

|

 Listed for each algorithm are the code snippets used to run each
 benchmark test.

|

::

   time -v openssl speed -elapsed -evp aes-128-cbc

IPSec Hardware Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Note: queue\_len is set to 300 and software fallback threshold set to 9
to enable software support for optimal performance

IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
   :header: "Algorithm","am64xx-evm: Throughput (Mbps)","am64xx-evm: Packets/Sec","am64xx-evm: CPU Load","am654x-evm: Throughput (Mbps)","am654x-evm: Packets/Sec","am654x-evm: CPU Load"

   "3des","51.20","4.00","50.33"
   "aes256","4.20","0.00","31.81"

PRU Ethernet
------------

Table: **PRU UDP Throughput Egress**

Table: **PRU UDP Throughput Ingress**

DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.

Power Management
-----------------

Power Measurements
^^^^^^^^^^^^^^^^^^^

.. warning::

 Active power is slightly higher on this release
 because PRUSS is enabled by default. Customers not using PRUSS are
 advised to disable it to reduce power consumption.


