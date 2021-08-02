..  http://processors.wiki.ti.com/index.php/CoreSDK_Linux_RT_Kernel_Performance_Guide


======================================
 RT-linux 08.00.00 Performance Guide
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
| K2HK EVM       | K2 Hawkings Evaluation Module rev 40 with ARM running at 1200MHz, DDR3-1600 (800 MHz/1600 MT/S), EVMK2H             |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| K2G EVM        | K2 Galileo Evaluation Module rev C, DDR3-1333 (666 MHz/1333 MT/S), EVMK2G                                           |
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

**Bandwidth**: bw_mem_bcopy-N, where N is is equal to or smaller than the cache size at
a given level measures the achievable memory bandwidth from software doing
a memcpy() type operation. Typical use is for external memory bandwidth
calculation. The bandwidth is calculated as byte read and written counts
as 1 which should be roughly half of STREAM copy result.

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf","am654x-evm: perf"

    "af_unix_sock_stream_latency (microsec)","48.56","60.45"
    "af_unix_socket_stream_bandwidth (MBs)","740.33","1119.71"
    "bw_file_rd-io-1mb (MB/s)","833.89","976.37"
    "bw_file_rd-o2c-1mb (MB/s)","458.65","524.38"
    "bw_mem-bcopy-16mb (MB/s)","886.52","878.64"
    "bw_mem-bcopy-1mb (MB/s)","1048.22","1033.77"
    "bw_mem-bcopy-2mb (MB/s)","1056.52","882.35"
    "bw_mem-bcopy-4mb (MB/s)","1094.84","871.84"
    "bw_mem-bcopy-8mb (MB/s)","1077.73","882.03"
    "bw_mem-bzero-16mb (MB/s)","2125.12","1649.99"
    "bw_mem-bzero-1mb (MB/s)","1586.81 (min 1048.22, max 2125.40)","2682.56 (min 1033.77, max 4331.35)"
    "bw_mem-bzero-2mb (MB/s)","1587.21 (min 1056.52, max 2117.90)","1607.26 (min 882.35, max 2332.17)"
    "bw_mem-bzero-4mb (MB/s)","1608.99 (min 1094.84, max 2123.14)","1292.58 (min 871.84, max 1713.31)"
    "bw_mem-bzero-8mb (MB/s)","1601.28 (min 1077.73, max 2124.83)","1263.72 (min 882.03, max 1645.41)"
    "bw_mem-cp-16mb (MB/s)","524.13","590.80"
    "bw_mem-cp-1mb (MB/s)","1413.78 (min 558.27, max 2269.29)","2613.87 (min 673.17, max 4554.56)"
    "bw_mem-cp-2mb (MB/s)","1372.63 (min 551.88, max 2193.38)","1464.26 (min 589.10, max 2339.41)"
    "bw_mem-cp-4mb (MB/s)","1348.09 (min 539.45, max 2156.72)","1145.11 (min 584.45, max 1705.76)"
    "bw_mem-cp-8mb (MB/s)","1369.88 (min 593.25, max 2146.50)","1121.70 (min 596.79, max 1646.60)"
    "bw_mem-fcp-16mb (MB/s)","792.75","820.81"
    "bw_mem-fcp-1mb (MB/s)","1501.76 (min 878.12, max 2125.40)","2647.84 (min 964.32, max 4331.35)"
    "bw_mem-fcp-2mb (MB/s)","1502.87 (min 887.84, max 2117.90)","1576.60 (min 821.02, max 2332.17)"
    "bw_mem-fcp-4mb (MB/s)","1469.28 (min 815.41, max 2123.14)","1265.70 (min 818.08, max 1713.31)"
    "bw_mem-fcp-8mb (MB/s)","1512.77 (min 900.70, max 2124.83)","1235.97 (min 826.53, max 1645.41)"
    "bw_mem-frd-16mb (MB/s)","1323.30","1285.66"
    "bw_mem-frd-1mb (MB/s)","1081.50 (min 878.12, max 1284.88)","1262.35 (min 964.32, max 1560.37)"
    "bw_mem-frd-2mb (MB/s)","1073.45 (min 887.84, max 1259.05)","1076.85 (min 821.02, max 1332.67)"
    "bw_mem-frd-4mb (MB/s)","1075.38 (min 815.41, max 1335.34)","1057.24 (min 818.08, max 1296.39)"
    "bw_mem-frd-8mb (MB/s)","1081.77 (min 900.70, max 1262.83)","1048.89 (min 826.53, max 1271.25)"
    "bw_mem-fwr-16mb (MB/s)","2121.73","1647.45"
    "bw_mem-fwr-1mb (MB/s)","1777.09 (min 1284.88, max 2269.29)","3057.47 (min 1560.37, max 4554.56)"
    "bw_mem-fwr-2mb (MB/s)","1726.22 (min 1259.05, max 2193.38)","1836.04 (min 1332.67, max 2339.41)"
    "bw_mem-fwr-4mb (MB/s)","1746.03 (min 1335.34, max 2156.72)","1501.08 (min 1296.39, max 1705.76)"
    "bw_mem-fwr-8mb (MB/s)","1704.67 (min 1262.83, max 2146.50)","1458.93 (min 1271.25, max 1646.60)"
    "bw_mem-rd-16mb (MB/s)","1386.84","1303.04"
    "bw_mem-rd-1mb (MB/s)","958.73 (min 951.84, max 965.62)","2888.16 (min 2624.67, max 3151.65)"
    "bw_mem-rd-2mb (MB/s)","1110.87 (min 836.70, max 1385.04)","1163.58 (min 914.22, max 1412.93)"
    "bw_mem-rd-4mb (MB/s)","1101.89 (min 861.05, max 1342.73)","1033.24 (min 755.43, max 1311.05)"
    "bw_mem-rd-8mb (MB/s)","1128.58 (min 910.13, max 1347.03)","1024.03 (min 741.29, max 1306.76)"
    "bw_mem-rdwr-16mb (MB/s)","883.54","730.96"
    "bw_mem-rdwr-1mb (MB/s)","683.93 (min 558.27, max 809.59)","1818.07 (min 673.17, max 2962.96)"
    "bw_mem-rdwr-2mb (MB/s)","656.46 (min 551.88, max 761.04)","742.25 (min 589.10, max 895.39)"
    "bw_mem-rdwr-4mb (MB/s)","693.19 (min 539.45, max 846.92)","663.63 (min 584.45, max 742.80)"
    "bw_mem-rdwr-8mb (MB/s)","736.14 (min 593.25, max 879.02)","664.87 (min 596.79, max 732.94)"
    "bw_mem-wr-16mb (MB/s)","946.19","742.25"
    "bw_mem-wr-1mb (MB/s)","880.72 (min 809.59, max 951.84)","3057.31 (min 2962.96, max 3151.65)"
    "bw_mem-wr-2mb (MB/s)","798.87 (min 761.04, max 836.70)","904.81 (min 895.39, max 914.22)"
    "bw_mem-wr-4mb (MB/s)","853.99 (min 846.92, max 861.05)","749.12 (min 742.80, max 755.43)"
    "bw_mem-wr-8mb (MB/s)","894.58 (min 879.02, max 910.13)","737.12 (min 732.94, max 741.29)"
    "bw_mmap_rd-mo-1mb (MB/s)","1328.24","2540.83"
    "bw_mmap_rd-o2c-1mb (MB/s)","476.72","537.35"
    "bw_pipe (MB/s)","263.99","320.24"
    "bw_unix (MB/s)","740.33","1119.71"
    "lat_connect (us)","93.82","105.29"
    "lat_ctx-2-128k (us)","9.60","7.47"
    "lat_ctx-2-256k (us)","11.84","5.66"
    "lat_ctx-4-128k (us)","9.30","7.50"
    "lat_ctx-4-256k (us)","0.00","3.26"
    "lat_fs-0k (num_files)","195.00","147.00"
    "lat_fs-10k (num_files)","86.00","63.00"
    "lat_fs-1k (num_files)","111.00","108.00"
    "lat_fs-4k (num_files)","106.00","92.00"
    "lat_mem_rd-stride128-sz1000k (ns)","47.58","27.49"
    "lat_mem_rd-stride128-sz125k (ns)","7.81","9.77"
    "lat_mem_rd-stride128-sz250k (ns)","10.90","10.22"
    "lat_mem_rd-stride128-sz31k (ns)","3.02","7.35"
    "lat_mem_rd-stride128-sz50 (ns)","3.01","3.76"
    "lat_mem_rd-stride128-sz500k (ns)","42.70","12.52"
    "lat_mem_rd-stride128-sz62k (ns)","7.33","9.21"
    "lat_mmap-1m (us)","62.00","94.00"
    "lat_ops-double-add (ns)","0.73","0.91"
    "lat_ops-double-mul (ns)","4.02","5.02"
    "lat_ops-float-add (ns)","0.73","0.91"
    "lat_ops-float-mul (ns)","4.01","5.02"
    "lat_ops-int-add (ns)","1.00","1.26"
    "lat_ops-int-bit (ns)","0.67","0.84"
    "lat_ops-int-div (ns)","6.02","7.54"
    "lat_ops-int-mod (ns)","6.37","7.94"
    "lat_ops-int-mul (ns)","3.05","3.82"
    "lat_ops-int64-add (ns)","1.01","1.26"
    "lat_ops-int64-bit (ns)","0.67","0.84"
    "lat_ops-int64-div (ns)","9.54","11.96"
    "lat_ops-int64-mod (ns)","7.37","9.21"
    "lat_pagefault (us)","1.78","1.97"
    "lat_pipe (us)","26.78","33.33"
    "lat_proc-exec (us)","1948.00","1694.75"
    "lat_proc-fork (us)","1602.00","1521.50"
    "lat_proc-proccall (us)","0.01","0.01"
    "lat_select (us)","42.05","52.94"
    "lat_sem (us)","3.87","8.03"
    "lat_sig-catch (us)","7.90","9.73"
    "lat_sig-install (us)","0.81","1.03"
    "lat_sig-prot (us)","0.24","0.30"
    "lat_syscall-fstat (us)","1.96","2.44"
    "lat_syscall-null (us)","0.42","0.51"
    "lat_syscall-open (us)","489.18","301.35"
    "lat_syscall-read (us)","0.80","0.99"
    "lat_syscall-stat (us)","5.09","6.25"
    "lat_syscall-write (us)","0.64","0.81"
    "lat_tcp (us)","0.81","1.00"
    "lat_unix (us)","48.56","60.45"
    "latency_for_0.50_mb_block_size (nanosec)","42.70","12.52"
    "latency_for_1.00_mb_block_size (nanosec)","23.79 (min 0.00, max 47.58)","13.75 (min 0.00, max 27.49)"
    "pipe_bandwidth (MBs)","263.99","320.24"
    "pipe_latency (microsec)","26.78","33.33"
    "procedure_call (microsec)","0.01","0.01"
    "select_on_200_tcp_fds (microsec)","42.05","52.94"
    "semaphore_latency (microsec)","3.87","8.03"
    "signal_handler_latency (microsec)","0.81","1.03"
    "signal_handler_overhead (microsec)","7.90","9.73"
    "tcp_ip_connection_cost_to_localhost (microsec)","93.82","105.29"
    "tcp_latency_using_localhost (microsec)","0.81","1.00"

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

    "linpack (Kflops)","397929.00","330685.00"

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

    "assignment (Iterations)","9.75","7.80"
    "fourier (Iterations)","16336.00","13068.00"
    "fp_emulation (Iterations)","76.55","61.25"
    "huffman (Iterations)","838.46","670.66"
    "idea (Iterations)","2453.60","1962.90"
    "lu_decomposition (Iterations)","391.34","312.35"
    "neural_net (Iterations)","5.61","4.49"
    "numeric_sort (Iterations)","358.05","288.74"
    "string_sort (Iterations)","118.43","94.75"

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

    "add (MB/s)","1684.50","1626.20"
    "copy (MB/s)","2307.30","1783.50"
    "scale (MB/s)","2347.90","1807.10"
    "triad (MB/s)","1676.30","1523.00"

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

    "cjpeg-rose7-preset (workloads/)","29.50"
    "core (workloads/)","0.21"
    "coremark-pro ()","586.89"
    "linear_alg-mid-100x100-sp (workloads/)","10.44"
    "loops-all-mid-10k-sp (workloads/)","0.49"
    "nnet_test (workloads/)","0.78"
    "parser-125k (workloads/)","5.38"
    "radix2-big-64k (workloads/)","19.37"
    "sha-test (workloads/)","58.14"
    "zip-test (workloads/)","15.63"

Table:  **CoreMarkPro**

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "cjpeg-rose7-preset (workloads/)","58.82"
    "core (workloads/)","0.42"
    "coremark-pro ()","1064.08"
    "linear_alg-mid-100x100-sp (workloads/)","20.88"
    "loops-all-mid-10k-sp (workloads/)","0.89"
    "nnet_test (workloads/)","1.55"
    "parser-125k (workloads/)","6.37"
    "radix2-big-64k (workloads/)","34.52"
    "sha-test (workloads/)","112.36"
    "zip-test (workloads/)","28.17"

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

    "4m-check (workloads/)","322.54"
    "4m-check-reassembly (workloads/)","62.38"
    "4m-check-reassembly-tcp (workloads/)","37.88"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","15.42"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","0.77"
    "4m-cmykw2 (workloads/)","88.69"
    "4m-cmykw2-rotatew2 (workloads/)","17.71"
    "4m-reassembly (workloads/)","51.20"
    "4m-rotatew2 (workloads/)","24.58"
    "4m-tcp-mixed (workloads/)","82.90"
    "4m-x264w2 (workloads/)","0.78"
    "empty-wld (workloads/)","1.00"
    "idct-4m (workloads/)","13.70"
    "idct-4mw1 (workloads/)","13.68"
    "ippktcheck-4m (workloads/)","323.00"
    "ippktcheck-4mw1 (workloads/)","322.79"
    "ipres-4m (workloads/)","69.54"
    "ipres-4mw1 (workloads/)","67.08"
    "md5-4m (workloads/)","19.33"
    "md5-4mw1 (workloads/)","19.30"
    "rgbcmyk-4m (workloads/)","44.68"
    "rgbcmyk-4mw1 (workloads/)","44.61"
    "rotate-4ms1 (workloads/)","17.21"
    "rotate-4ms1w1 (workloads/)","17.21"
    "rotate-4ms64 (workloads/)","17.13"
    "rotate-4ms64w1 (workloads/)","17.35"
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
| The application running the use case and cyclictest ran on a dedicated cpu (cgroup rt, assigned to core #1) while the rest of threads ran on the other cpu (cgroup nonrt, assigned to core #0).

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
    "Max Latencies","92", "68"

Table:  **Cyclic test for Two Cores**

AM654X-EVM
"""""""""""""""""""""""""""""""
.. csv-table::
    :header: "Benchmarks","Core #1 (nonrt)","Core#2 (rt)", "Core#3 (rt)" ,"Core#4 (rt)"

    "Min Latencies","8", "8", "8", "9"
    "Avg Latencies","10", "11", "11", "11"
    "Max Latencies","83", "109", "75", "77"

Table:  **Cyclic test for Four Cores**

|

|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

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

Table:  **Audio Capture**

|

Table:  **Audio Playback**

|

Sensor Capture
-------------------------

Capture video frames (MMAP buffers) with v4l2c-ctl and record the
reported fps

Table:  **Sensor Capture**

|

Display Driver
-------------------------

|

|

|

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

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1032.05","98.74","1663.12","65.01"

Table: **CPSW TCP Bidirectional Throughput**

|

.. rubric::  UDP Throughput 
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","7.81","87.94"
    "128","82.00","33.77","85.84"
    "256","210.00","75.50","70.36"
    "1024","978.00","382.15","84.71"
    "1518","1472.00","564.46","84.41"

Table: **CPSW UDP Egress Throughput**

|

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","am654x-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.12","4.45","18.00","1.12","3.35"
    "128","82.00","6.04","5.27"
    "256","210.00","17.30","4.59"
    "1024","978.00","76.67","17.36"
    "1518","1472.00","123.64","19.25"

Table: **CPSW UDP Ingress Throughput**

|

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","am64xx-evm: Packet Loss %","am654x-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: CPU Load % (LOCAL_CPU_UTIL)","am654x-evm: Packet Loss %"

    "64","18.00","15.86","59.89","45.95","18.00","18.08","40.51","38.43"
    "128","82.00","70.65","55.81","68.56"
    "256","210.00","172.91","56.60","75.08"
    "1024","978.00","662.19","52.87","29.30"
    "1518","1472.00","866.84","69.26","8.40"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|

ICSSG Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput 
   :name: tcp-bidirectional-throughput

Table: **ICSSG TCP Bidirectional Throughput**

|

.. rubric::  UDP Throughput 
   :name: udp-throughput-0-loss

Table: **ICSSG UDP Egress Throughput**

|

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

    "1m","360.00","96.35","391.00","94.96"
    "4m","365.00","96.39","397.00","93.64"
    "4k","26.80","99.55","37.00","98.98"
    "256k","275.00","97.10","341.00","96.13"

- Filesize used is: 10G
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

    "102400","0.19 (min 0.13, max 0.31)","53.69 (min 53.27, max 54.33)","25.06","12.50"
    "262144","0.16 (min 0.11, max 0.20)","54.08 (min 53.28, max 54.64)","24.40","12.50"
    "524288","0.16 (min 0.11, max 0.19)","54.43 (min 53.76, max 56.64)","24.27","13.33"
    "1048576","0.16 (min 0.11, max 0.20)","53.89 (min 53.39, max 54.44)","24.02","12.50"

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

    "4m","59.50","3.17","",""

|

SATA Driver
-------------------------

|

|

|

-  Filesize used is : 1G
-  SATA II Harddisk used is: Seagate ST3500514NS 500G

mSATA Driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^

|

|

-  Filesize used is : 1G
-  MSATA Harddisk used is: SMS200S3/30G Kingston mSATA SSD drive

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

    "1m","18.40","2.22","86.00","5.46"
    "4m","18.90","1.87","86.50","3.87"
    "4k","5.05","11.50","16.50","21.25"
    "256k","18.00","3.40","83.50","6.88"

|

|

|

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

    "1m","30.70","93.27","30.90","94.72"
    "4m","31.10","94.41","31.50","92.10"
    "4k","6.48","96.12","7.35","97.38"
    "256k","27.90","94.44","28.00","92.03"

|

|
|

USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

|
|

|
|

|
|

|
|

Table: **USBDEVICE HIGHSPEED SLAVE READ THROUGHPUT**

.. csv-table::
    :header: "Number of Blocks","am64xx-evm: Throughput (MB/sec)","am654x-evm: Throughput (MB/sec)"

    "150","39.90","33.40"

|
|

Table: **USBDEVICE HIGHSPEED SLAVE WRITE THROUGHPUT**

.. csv-table::
    :header: "Number of Blocks","am64xx-evm: Throughput (MB/sec)","am654x-evm: Throughput (MB/sec)"

    "150","31.60","31.60"

|
|

|
|

|
|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

|
|

|
| Listed for each algorithm are the code snippets used to run each
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

    "3des","52.30","4.00","50.24"
    "aes256","2.10","0.00","31.98"

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
    
