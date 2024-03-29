
======================================
 Linux 09.02.00 Performance Guide
======================================

.. rubric::  **Read This First**
   :name: read-this-first-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| AM62x SK       | AM62x Starter Kit rev E2 and E3 with ARM running at 1.4GHz, DDR data rate 1600 MT/S                            |
+----------------+----------------------------------------------------------------------------------------------------------------+
| AM62x LP SK    | AM62x LP Starter Kit rev E1 with ARM running at 1.25GHz, LPDDR4 data rate 1600 MT/S                            |
+----------------+----------------------------------------------------------------------------------------------------------------+
| AM62SIP SK     | AM62SIP Starter Kit rev E1 with ARM running at 1.4GHz, 512MB LPDDR4 data rate 1600 MT/S                        |
+----------------+----------------------------------------------------------------------------------------------------------------+

Table:  Evaluation Modules

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

Execute the LMBench with the following:

::

    cd /opt/ltp
    ./runltp -P j721e-idk-gw -f ddt/lmbench -s LMBENCH_L_PERF_0001

.. csv-table::
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "af_unix_sock_stream_latency (microsec)","24.64","22.49","21.85"
    "af_unix_socket_stream_bandwidth (MBs)","569.66","633.94","752.71"
    "bw_file_rd-io-1mb (MB/s)","780.64","861.77","881.68"
    "bw_file_rd-o2c-1mb (MB/s)","465.91","500.92","517.15"
    "bw_mem-bcopy-16mb (MB/s)","668.84","766.72","749.24"
    "bw_mem-bcopy-1mb (MB/s)","719.55","821.15","773.51"
    "bw_mem-bcopy-2mb (MB/s)","672.83","814.77","745.43"
    "bw_mem-bcopy-4mb (MB/s)","694.57","788.57","724.38"
    "bw_mem-bcopy-8mb (MB/s)","709.16","815.16","742.25"
    "bw_mem-bzero-16mb (MB/s)","1686.70","1759.79","1742.54"
    "bw_mem-bzero-1mb (MB/s)","1192.83 (min 719.55, max 1666.11)","1278.78 (min 821.15, max 1736.41)","1249.65 (min 773.51, max 1725.79)"
    "bw_mem-bzero-2mb (MB/s)","1169.33 (min 672.83, max 1665.83)","1275.14 (min 814.77, max 1735.51)","1235.38 (min 745.43, max 1725.33)"
    "bw_mem-bzero-4mb (MB/s)","1181.08 (min 694.57, max 1667.59)","1262.97 (min 788.57, max 1737.37)","1225.75 (min 724.38, max 1727.12)"
    "bw_mem-bzero-8mb (MB/s)","1201.68 (min 709.16, max 1694.20)","1284.10 (min 815.16, max 1753.04)","1243.44 (min 742.25, max 1744.63)"
    "bw_mem-cp-16mb (MB/s)","385.75","452.35","433.87"
    "bw_mem-cp-1mb (MB/s)","492.33 (min 370.03, max 614.63)","590.83 (min 437.38, max 744.27)","532.15 (min 396.41, max 667.89)"
    "bw_mem-cp-2mb (MB/s)","468.34 (min 369.55, max 567.13)","550.49 (min 425.08, max 675.90)","527.83 (min 435.40, max 620.25)"
    "bw_mem-cp-4mb (MB/s)","486.58 (min 396.20, max 576.95)","601.70 (min 463.88, max 739.51)","518.59 (min 404.16, max 633.01)"
    "bw_mem-cp-8mb (MB/s)","536.42 (min 422.05, max 650.78)","642.91 (min 476.76, max 809.06)","526.14 (min 415.89, max 636.39)"
    "bw_mem-fcp-16mb (MB/s)","663.57","752.52","779.69"
    "bw_mem-fcp-1mb (MB/s)","1207.80 (min 749.48, max 1666.11)","1299.47 (min 862.52, max 1736.41)","1272.26 (min 818.73, max 1725.79)"
    "bw_mem-fcp-2mb (MB/s)","1205.22 (min 744.60, max 1665.83)","1291.37 (min 847.22, max 1735.51)","1262.40 (min 799.47, max 1725.33)"
    "bw_mem-fcp-4mb (MB/s)","1212.59 (min 757.58, max 1667.59)","1313.73 (min 890.08, max 1737.37)","1238.80 (min 750.47, max 1727.12)"
    "bw_mem-fcp-8mb (MB/s)","1226.36 (min 758.51, max 1694.20)","1341.75 (min 930.45, max 1753.04)","1273.04 (min 801.44, max 1744.63)"
    "bw_mem-frd-16mb (MB/s)","1031.33","1136.53","1072.17"
    "bw_mem-frd-1mb (MB/s)","949.68 (min 749.48, max 1149.87)","1050.51 (min 862.52, max 1238.50)","1035.15 (min 818.73, max 1251.56)"
    "bw_mem-frd-2mb (MB/s)","882.68 (min 744.60, max 1020.76)","974.88 (min 847.22, max 1102.54)","958.08 (min 799.47, max 1116.69)"
    "bw_mem-frd-4mb (MB/s)","880.30 (min 757.58, max 1003.01)","997.91 (min 890.08, max 1105.74)","921.83 (min 750.47, max 1093.19)"
    "bw_mem-frd-8mb (MB/s)","894.32 (min 758.51, max 1030.13)","1029.80 (min 930.45, max 1129.15)","954.43 (min 801.44, max 1107.42)"
    "bw_mem-fwr-16mb (MB/s)","671.99","811.28","642.85"
    "bw_mem-fwr-1mb (MB/s)","882.25 (min 614.63, max 1149.87)","991.39 (min 744.27, max 1238.50)","959.73 (min 667.89, max 1251.56)"
    "bw_mem-fwr-2mb (MB/s)","793.95 (min 567.13, max 1020.76)","889.22 (min 675.90, max 1102.54)","868.47 (min 620.25, max 1116.69)"
    "bw_mem-fwr-4mb (MB/s)","789.98 (min 576.95, max 1003.01)","922.63 (min 739.51, max 1105.74)","863.10 (min 633.01, max 1093.19)"
    "bw_mem-fwr-8mb (MB/s)","840.46 (min 650.78, max 1030.13)","969.11 (min 809.06, max 1129.15)","871.91 (min 636.39, max 1107.42)"
    "bw_mem-rd-16mb (MB/s)","1032.52","1137.33","1121.94"
    "bw_mem-rd-1mb (MB/s)","867.72 (min 545.36, max 1190.07)","985.74 (min 689.18, max 1282.29)","938.54 (min 605.05, max 1272.03)"
    "bw_mem-rd-2mb (MB/s)","757.25 (min 486.56, max 1027.93)","890.89 (min 650.72, max 1131.06)","834.60 (min 545.18, max 1124.02)"
    "bw_mem-rd-4mb (MB/s)","796.49 (min 567.21, max 1025.77)","915.68 (min 699.18, max 1132.18)","842.91 (min 570.37, max 1115.45)"
    "bw_mem-rd-8mb (MB/s)","806.37 (min 591.15, max 1021.58)","962.05 (min 789.66, max 1134.43)","848.45 (min 579.88, max 1117.01)"
    "bw_mem-rdwr-16mb (MB/s)","679.06","790.59","589.80"
    "bw_mem-rdwr-1mb (MB/s)","456.46 (min 370.03, max 542.89)","551.64 (min 437.38, max 665.89)","489.71 (min 396.41, max 583.01)"
    "bw_mem-rdwr-2mb (MB/s)","424.64 (min 369.55, max 479.73)","518.54 (min 425.08, max 612.00)","484.37 (min 435.40, max 533.33)"
    "bw_mem-rdwr-4mb (MB/s)","478.14 (min 396.20, max 560.07)","580.19 (min 463.88, max 696.50)","482.63 (min 404.16, max 561.09)"
    "bw_mem-rdwr-8mb (MB/s)","530.26 (min 422.05, max 638.47)","622.41 (min 476.76, max 768.05)","496.99 (min 415.89, max 578.08)"
    "bw_mem-wr-16mb (MB/s)","702.99","855.43","595.46"
    "bw_mem-wr-1mb (MB/s)","544.13 (min 542.89, max 545.36)","677.54 (min 665.89, max 689.18)","594.03 (min 583.01, max 605.05)"
    "bw_mem-wr-2mb (MB/s)","483.15 (min 479.73, max 486.56)","631.36 (min 612.00, max 650.72)","539.26 (min 533.33, max 545.18)"
    "bw_mem-wr-4mb (MB/s)","563.64 (min 560.07, max 567.21)","697.84 (min 696.50, max 699.18)","565.73 (min 561.09, max 570.37)"
    "bw_mem-wr-8mb (MB/s)","614.81 (min 591.15, max 638.47)","778.86 (min 768.05, max 789.66)","578.98 (min 578.08, max 579.88)"
    "bw_mmap_rd-mo-1mb (MB/s)","1152.26","1279.01","1274.81"
    "bw_mmap_rd-o2c-1mb (MB/s)","405.79","467.58","449.71"
    "bw_pipe (MB/s)","425.97","482.09","539.14"
    "bw_unix (MB/s)","569.66","633.94","752.71"
    "lat_connect (us)","62.42","56.26","54.37"
    "lat_ctx-2-128k (us)","5.79","4.99","4.80"
    "lat_ctx-2-256k (us)","4.96","3.56","4.54"
    "lat_ctx-4-128k (us)","5.03","4.45","4.29"
    "lat_ctx-4-256k (us)","5.60","5.50","4.51"
    "lat_fs-0k (num_files)","213.00","267.00","242.00"
    "lat_fs-10k (num_files)","106.00","114.00","112.00"
    "lat_fs-1k (num_files)","172.00","161.00","181.00"
    "lat_fs-4k (num_files)","160.00","167.00","175.00"
    "lat_mem_rd-stride128-sz1000k (ns)","57.66","52.37","52.67"
    "lat_mem_rd-stride128-sz125k (ns)","6.22","5.56","5.54"
    "lat_mem_rd-stride128-sz250k (ns)","6.54","5.83","5.84"
    "lat_mem_rd-stride128-sz31k (ns)","4.08","4.19","2.16"
    "lat_mem_rd-stride128-sz50 (ns)","2.40","2.15","2.15"
    "lat_mem_rd-stride128-sz500k (ns)","20.28","16.17","14.51"
    "lat_mem_rd-stride128-sz62k (ns)","5.85","5.23","5.26"
    "lat_mmap-1m (us)","57.00","63.00","50.00"
    "lat_ops-double-add (ns)","3.20","2.86","2.86"
    "lat_ops-double-div (ns)","17.63","15.73","15.73"
    "lat_ops-double-mul (ns)","3.21","2.86","2.86"
    "lat_ops-float-add (ns)","3.20","2.86","2.86"
    "lat_ops-float-div (ns)","10.41","9.29","9.30"
    "lat_ops-float-mul (ns)","3.21","2.86","2.86"
    "lat_ops-int-add (ns)","0.80","0.72","0.72"
    "lat_ops-int-bit (ns)","0.53","0.48","0.48"
    "lat_ops-int-div (ns)","4.81","4.29","4.29"
    "lat_ops-int-mod (ns)","5.07","4.53","4.53"
    "lat_ops-int-mul (ns)","3.44","3.07","3.07"
    "lat_ops-int64-add (ns)","0.80","0.72","0.72"
    "lat_ops-int64-bit (ns)","0.53","0.48","0.48"
    "lat_ops-int64-div (ns)","7.61","6.79","6.79"
    "lat_ops-int64-mod (ns)","5.87","5.24","5.25"
    "lat_ops-int64-mul (ns)","3.98","3.55","3.55"
    "lat_pagefault (us)","1.82","1.67","1.63"
    "lat_pipe (us)","21.71","19.40","19.43"
    "lat_proc-exec (us)","1129.20","1027.50","1024.00"
    "lat_proc-fork (us)","876.00","763.00","843.00"
    "lat_proc-proccall (us)","0.01","0.01","0.01"
    "lat_select (us)","37.39","33.39","33.37"
    "lat_sem (us)","1.61","1.64","1.19"
    "lat_sig-catch (us)","5.92","5.32","5.31"
    "lat_sig-install (us)","0.73","0.64","0.66"
    "lat_sig-prot (us)","0.57","0.50","0.49"
    "lat_syscall-fstat (us)","3.08","2.72","2.71"
    "lat_syscall-null (us)","0.52","0.46","0.46"
    "lat_syscall-open (us)","194.33","168.39","164.81"
    "lat_syscall-read (us)","0.86","0.77","0.77"
    "lat_syscall-stat (us)","4.40","3.86","3.90"
    "lat_syscall-write (us)","0.72","0.64","0.64"
    "lat_tcp (us)","1.05","0.93","0.94"
    "lat_unix (us)","24.64","22.49","21.85"
    "latency_for_0.50_mb_block_size (nanosec)","20.28","16.17","14.51"
    "latency_for_1.00_mb_block_size (nanosec)","28.83 (min 0.00, max 57.66)","26.18 (min 0.00, max 52.37)","26.34 (min 0.00, max 52.67)"
    "pipe_bandwidth (MBs)","425.97","482.09","539.14"
    "pipe_latency (microsec)","21.71","19.40","19.43"
    "procedure_call (microsec)","0.01","0.01","0.01"
    "select_on_200_tcp_fds (microsec)","37.39","33.39","33.37"
    "semaphore_latency (microsec)","1.61","1.64","1.19"
    "signal_handler_latency (microsec)","0.73","0.64","0.66"
    "signal_handler_overhead (microsec)","5.92","5.32","5.31"
    "tcp_ip_connection_cost_to_localhost (microsec)","62.42","56.26","54.37"
    "tcp_latency_using_localhost (microsec)","1.05","0.93","0.94"

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

Execute the benchmark with the following:

::

    runDhrystone

.. csv-table::
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "cpu_clock (MHz)","1250.00","1400.00","1400.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.90","3.00","3.00"
    "dhrystone_per_second (DhrystoneP)","6451613.00","7407407.50","7407407.50"

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Whetstone is a benchmark primarily measuring floating-point arithmetic performance.

Execute the benchmark with the following:

::

    runWhetstone

.. csv-table::
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "whetstone (MIPS)","5000.00","10000.00","5000.00"

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "linpack (Kflops)","516446.00","574713.00","579906.00"

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html

.. csv-table::
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "assignment (Iterations)","12.38","13.90","13.93"
    "fourier (Iterations)","20211.00","22639.00","22640.00"
    "fp_emulation (Iterations)","82.42","92.34","92.34"
    "huffman (Iterations)","1044.00","1169.00","1169.40"
    "idea (Iterations)","3075.50","3444.90","3444.90"
    "lu_decomposition (Iterations)","475.71","533.67","535.06"
    "neural_net (Iterations)","7.87","8.82","8.82"
    "numeric_sort (Iterations)","533.57","595.13","588.49"
    "string_sort (Iterations)","147.27","164.94","164.96"

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
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "add (MB/s)","1374.40","1450.20","1728.10"
    "copy (MB/s)","1450.80","1653.90","1862.40"
    "scale (MB/s)","1555.90","1830.00","1902.50"
    "triad (MB/s)","1351.10","1481.90","1693.50"

CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.

Table:  **CoreMarkPro Benchmarks**

.. csv-table::
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "cjpeg-rose7-preset (workloads/)","37.31","41.84","42.02"
    "core (workloads/)","0.27","0.30","0.30"
    "coremark-pro ()","804.80","900.93","928.54"
    "linear_alg-mid-100x100-sp (workloads/)","13.11","14.71","14.69"
    "loops-all-mid-10k-sp (workloads/)","0.59","0.67","0.70"
    "nnet_test (workloads/)","0.97","1.09","1.09"
    "parser-125k (workloads/)","7.41","8.13","8.55"
    "radix2-big-64k (workloads/)","52.76","60.13","68.05"
    "sha-test (workloads/)","71.94","80.65","81.30"
    "zip-test (workloads/)","18.87","20.83","21.74"

Table:  **CoreMarkProTwoCore Benchmarks**

.. csv-table::
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "cjpeg-rose7-preset (workloads/)","74.07","82.64","84.03"
    "core (workloads/)","0.54","0.60","0.60"
    "coremark-pro ()","1309.74","1485.99","1534.09"
    "linear_alg-mid-100x100-sp (workloads/)","26.19","29.34","29.39"
    "loops-all-mid-10k-sp (workloads/)","1.03","1.16","1.24"
    "nnet_test (workloads/)","1.94","2.17","2.17"
    "parser-125k (workloads/)","9.52","11.56","11.70"
    "radix2-big-64k (workloads/)","32.72","38.10","44.28"
    "sha-test (workloads/)","142.86","161.29","161.29"
    "zip-test (workloads/)","34.48","38.46","40.00"

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
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "4m-check (workloads/)","272.36","306.67","363.16"
    "4m-check-reassembly (workloads/)","58.38","66.23","79.05"
    "4m-check-reassembly-tcp (workloads/)","38.46","42.81","50.00"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","21.65","24.04","29.13"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.61","1.80","1.87"
    "4m-cmykw2 (workloads/)","179.37","200.60","236.13"
    "4m-cmykw2-rotatew2 (workloads/)","34.92","39.47","46.44"
    "4m-reassembly (workloads/)","46.75","53.28","62.34"
    "4m-rotatew2 (workloads/)","39.79","44.86","53.56"
    "4m-tcp-mixed (workloads/)","91.95","103.23","114.29"
    "4m-x264w2 (workloads/)","1.67","1.88","1.95"
    "empty-wld (workloads/)","1.00","","1.00"
    "idct-4m (workloads/)","16.76","18.59","19.11"
    "idct-4mw1 (workloads/)","16.76","18.60","19.11"
    "ippktcheck-4m (workloads/)","273.08","305.96","362.63"
    "ippktcheck-4mw1 (workloads/)","272.36","307.50","362.74"
    "ipres-4m (workloads/)","57.54","63.24","76.88"
    "ipres-4mw1 (workloads/)","57.54","63.29","77.08"
    "md5-4m (workloads/)","23.28","26.23","27.82"
    "md5-4mw1 (workloads/)","23.74","26.22","27.84"
    "rgbcmyk-4m (workloads/)","56.50","64.08","65.02"
    "rgbcmyk-4mw1 (workloads/)","56.75","64.04","64.91"
    "rotate-4ms1 (workloads/)","16.47","18.95","21.82"
    "rotate-4ms1w1 (workloads/)","16.44","18.23","21.88"
    "rotate-4ms64 (workloads/)","16.63","18.40","21.96"
    "rotate-4ms64w1 (workloads/)","16.95","18.42","22.02"
    "x264-4mq (workloads/)","0.50","0.56","0.57"
    "x264-4mqw1 (workloads/)","0.50","0.56","0.57"

|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am62xx_sk-fs: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","18.06 (min 17.90, max 18.15)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","3.45 (min 3.42, max 3.47)"

|

ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64

.. csv-table::
    :header: "Sampling Rate (Hz)","am62xx_lp_sk-fs: Throughput (bits/sec)","am62xx_lp_sk-fs: CPU Load (%)","am62xx_sk-fs: Throughput (bits/sec)","am62xx_sk-fs: CPU Load (%)","am62xxsip_sk-fs: Throughput (bits/sec)","am62xxsip_sk-fs: CPU Load (%)"

    "8000","255998.00","0.11","256000.00","0.11","255998.00","0.22"
    "11025","352797.00","0.17","352799.00","0.18","352798.00","0.17"
    "16000","511997.00","0.59","512000.00","0.13","511997.00","0.13"
    "22050","705596.00","0.29","705601.00","0.29","705596.00","0.28"
    "24000","705594.00","0.30","705599.00","0.28","705596.00","0.28"
    "32000","1023990.00","0.18","1023997.00","0.17","1023993.00","0.19"
    "44100","1411187.00","0.45","1411197.00","0.47","1411190.00","0.42"
    "48000","1535987.00","0.20","1535997.00","0.21","1535989.00","0.21"
    "88200","2822372.00","0.95","2822392.00","0.83","2822377.00","0.79"
    "96000","3071969.00","2.63","3071989.00","0.42","3071974.00","0.38"

|

Graphics SGX/RGX Driver
-------------------------

Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am62xx_lp_sk-fs: Score","am62xx_sk-fs: Score","am62xxsip_sk-fs: Score"

    "Glmark2-DRM","35.00","40.00","38.00"
    "Glmark2-Wayland","201.00","219.00","213.00"
    "Glmark2-Wayland 1920x1080","62.00","219.00"

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

CPSW/CPSW2g/CPSW3g Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- CPSW3g: AM62x

.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xxsip_sk-fs: THROUGHPUT (Mbits/sec)","am62xxsip_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1778.41","66.34","1778.47","64.23","1830.66","64.38"

.. rubric::  TCP Bidirectional Throughput Interrupt Pacing
   :name: CPSW2g-tcp-bidirectional-throughput-interrupt-pacing

.. csv-table::
    :header: "Command Used","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xxsip_sk-fs: THROUGHPUT (Mbits/sec)","am62xxsip_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1669.02","52.26","1442.31","43.05","1403.67","41.42"

.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

Table:  **CPSW2g UDP Egress Throughput 0 loss**

.. csv-table::
    :header: "Frame Size(bytes)","am62xx_lp_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: Packets Per Second (kPPS)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_sk-fs: Packets Per Second (kPPS)","am62xx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xxsip_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xxsip_sk-fs: THROUGHPUT (Mbits/sec)","am62xxsip_sk-fs: Packets Per Second (kPPS)","am62xxsip_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","16.96","118.00","40.50","18.00","18.25","127.00","39.96","18.00","19.33","134.00","41.03"
    "128","82.00","72.11","110.00","39.15","82.00","80.35","122.00","39.50","82.00","85.86","131.00","40.46"
    "256","210.00","186.71","111.00","39.68","210.00","206.59","123.00","39.59","210.00","201.91","120.00","39.37"
    "1024","978.00","847.62","108.00","39.26","978.00","934.04","119.00","45.48","978.00","934.84","119.00","43.37"
    "1518","1472.00","955.66","81.00","38.92","1472.00","955.09","81.00","34.42","1472.00","955.84","81.00","36.69"

Table:  **CPSW2g UDP Ingress Throughput 0 loss**

.. csv-table::
    :header: "Frame Size(bytes)","am62xx_lp_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: Packets Per Second (kPPS)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_sk-fs: Packets Per Second (kPPS)","am62xx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xxsip_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xxsip_sk-fs: THROUGHPUT (Mbits/sec)","am62xxsip_sk-fs: Packets Per Second (kPPS)","am62xxsip_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","6.42","45.00","26.15","18.00","1.71","12.00","10.98","18.00","5.64","39.00","20.43"
    "128","82.00","53.13","81.00","32.83","82.00","7.74","12.00","13.71","82.00","4.26","6.00","7.23"
    "256","210.00","124.32","74.00","33.91","210.00","21.50","13.00","14.96","210.00","89.88","54.00","32.91"
    "1024","978.00","482.73","62.00","29.08","978.00","932.64","119.00","42.34","978.00","935.75","120.00","41.89"
    "1518","1472.00","951.32","81.00","41.59","1472.00","955.58","81.00","40.11","1472.00","910.69","77.00","39.46"

Table:  **CPSW2g UDP Ingress Throughput possible loss**

.. csv-table::
    :header: "Frame Size(bytes)","am62xx_lp_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: Packets Per Second (kPPS)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_lp_sk-fs: Packet Loss %","am62xx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_sk-fs: Packets Per Second (kPPS)","am62xx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_sk-fs: Packet Loss %","am62xxsip_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xxsip_sk-fs: THROUGHPUT (Mbits/sec)","am62xxsip_sk-fs: Packets Per Second (kPPS)","am62xxsip_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xxsip_sk-fs: Packet Loss %"

    "64","18.00","25.40","176.00","38.75","61.81","18.00","27.35","190.00","38.81","47.47","18.00","29.74","207.00","38.40","74.76"
    "128","82.00","94.83","145.00","38.33","0.01","82.00","124.24","189.00","40.35","50.55","82.00","135.88","207.00","40.03","72.34"
    "256","210.00","243.14","145.00","40.28","0.97","210.00","305.90","182.00","41.25","48.43","210.00","333.03","198.00","40.89","37.88"
    "1024","978.00","936.27","120.00","41.60","0.01","978.00","918.11","117.00","41.92","0.05","978.00","923.81","118.00","41.54","0.01"
    "1518","1472.00","951.32","81.00","41.59","0.00","1472.00","947.27","80.00","39.56","0.02","1472.00","891.28","76.00","38.53","0.01"

|

UBoot QSPI/OSPI Driver
-------------------------

AM62XX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","am62xxsip_sk-fs: Write Throughput (Kbytes/sec)","am62xxsip_sk-fs: Read Throughput (Kbytes/sec)"

    "400000","387.81","195047.62"
    "800000","388.85","240941.18"
    "1000000","392.83","268590.16"
    "2000000","396.01","287438.60"

|

EMMC Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

AM62XX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am62xx_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62xx_sk-fs: Write EXT4 CPU Load (%)","am62xx_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62xx_sk-fs: Read EXT4 CPU Load (%)"

    "1m","59.70","1.26","175.00","1.55"
    "4m","59.90","1.04","175.00","1.28"
    "4k","51.50","18.42","55.80","17.37"
    "256k","59.60","1.66","174.00","2.11"

.. csv-table::
    :header: "Buffer size (bytes)","am62xx_lp_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62xx_lp_sk-fs: Write EXT4 CPU Load (%)","am62xx_lp_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62xx_lp_sk-fs: Read EXT4 CPU Load (%)"

    "1m","57.50","1.32","175.00","2.04"
    "4m","57.80","1.15","175.00","1.60"
    "4k","51.50","19.91","56.60","19.32"
    "256k","57.60","1.93","174.00","2.54"

.. csv-table::
    :header: "Buffer size (bytes)","am62xxsip_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62xxsip_sk-fs: Write EXT4 CPU Load (%)","am62xxsip_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62xxsip_sk-fs: Read EXT4 CPU Load (%)"

    "1m","90.30","2.12","172.00","1.84"
    "4m","96.70","2.02","172.00","1.86"
    "4k","63.10","24.14","90.80","26.07"
    "256k","90.90","2.29","171.00","2.27"

|

UBoot EMMC Driver
-------------------------

AM62XX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Table:  **UBOOT EMMC RAW**

.. csv-table::
    :header: "File size (bytes in hex)","am62xx_sk-fs: Write Throughput (Kbytes/sec)","am62xx_sk-fs: Read Throughput (Kbytes/sec)"

    "2000000","57186.74","169782.38"
    "4000000","57387.04","173375.66"

Table:  **UBOOT EMMC RAW**

.. csv-table::
    :header: "File size (bytes in hex)","am62xx_lp_sk-fs: Write Throughput (Kbytes/sec)","am62xx_lp_sk-fs: Read Throughput (Kbytes/sec)"

    "2000000","58202.49","168907.22"
    "4000000","58566.58","172918.21"

Table:  **UBOOT EMMC RAW**

.. csv-table::
    :header: "File size (bytes in hex)","am62xxsip_sk-fs: Write Throughput (Kbytes/sec)","am62xxsip_sk-fs: Read Throughput (Kbytes/sec)"

    "2000000","97523.81","143091.70"
    "4000000","97234.42","175229.95"

|

MMC/SD Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

AM62XX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am62xx_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62xx_sk-fs: Write EXT4 CPU Load (%)","am62xx_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62xx_sk-fs: Read EXT4 CPU Load (%)"

    "1m","20.00","0.70","85.70","0.87"
    "4m","20.10","0.58","85.70","0.84"
    "4k","5.79","2.50","22.10","6.83"
    "256k","19.90","0.82","83.00","1.34"

.. csv-table::
    :header: "Buffer size (bytes)","am62xx_lp_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62xx_lp_sk-fs: Write EXT4 CPU Load (%)","am62xx_lp_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62xx_lp_sk-fs: Read EXT4 CPU Load (%)"

    "1m","13.40","0.68","90.70","1.35"
    "4m","15.80","0.56","90.90","1.08"
    "4k","5.29","2.86","15.50","5.79"
    "256k","13.30","0.72","88.00","1.48"

.. csv-table::
    :header: "Buffer size (bytes)","am62xxsip_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62xxsip_sk-fs: Write EXT4 CPU Load (%)","am62xxsip_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62xxsip_sk-fs: Read EXT4 CPU Load (%)"

    "1m","43.00","1.05","87.60","0.96"
    "4m","42.60","0.85","87.50","1.02"
    "4k","3.55","1.65","16.50","4.98"
    "256k","39.80","1.00","85.50","1.09"

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|

UBoot MMC/SD Driver
-------------------------

AM62XX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Table:  **UBOOT MMCSD FAT**

.. csv-table::
    :header: "File size (bytes in hex)","am62xxsip_sk-fs: Write Throughput (Kbytes/sec)","am62xxsip_sk-fs: Read Throughput (Kbytes/sec)"

    "400000","40156.86","63015.38"
    "800000","46022.47","74472.73"
    "1000000","48761.90","82747.47"

|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Table:  **OpenSSL Performance**

.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am62xxsip_sk-fs: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","24669.18"
    "aes-128-cbc","16","475.82"
    "aes-128-cbc","16384","130607.79"
    "aes-128-cbc","256","7160.66"
    "aes-128-cbc","64","1875.20"
    "aes-128-cbc","8192","98429.61"
    "aes-128-ecb","1024","24693.08"
    "aes-128-ecb","16","487.43"
    "aes-128-ecb","16384","131082.92"
    "aes-128-ecb","256","7465.90"
    "aes-128-ecb","64","1949.82"
    "aes-128-ecb","8192","98689.02"
    "aes-192-cbc","1024","24658.94"
    "aes-192-cbc","16","476.10"
    "aes-192-cbc","16384","120285.87"
    "aes-192-cbc","256","7100.25"
    "aes-192-cbc","64","1869.53"
    "aes-192-cbc","8192","97984.51"
    "aes-192-ecb","1024","24676.69"
    "aes-192-ecb","16","494.55"
    "aes-192-ecb","16384","126582.78"
    "aes-192-ecb","256","7417.60"
    "aes-192-ecb","64","1963.95"
    "aes-192-ecb","8192","98254.85"
    "aes-256-cbc","1024","24656.90"
    "aes-256-cbc","16","472.99"
    "aes-256-cbc","16384","112405.16"
    "aes-256-cbc","256","7022.76"
    "aes-256-cbc","64","1854.44"
    "aes-256-cbc","8192","90963.97"
    "aes-256-ecb","1024","24686.25"
    "aes-256-ecb","16","494.91"
    "aes-256-ecb","16384","117882.88"
    "aes-256-ecb","256","7353.34"
    "aes-256-ecb","64","1968.19"
    "aes-256-ecb","8192","98066.43"
    "sha256","1024","32369.32"
    "sha256","16","551.01"
    "sha256","16384","262886.74"
    "sha256","256","8377.86"
    "sha256","64","2138.65"
    "sha256","8192","185161.05"
    "sha512","1024","24544.60"
    "sha512","16","535.81"
    "sha512","16384","68053.67"
    "sha512","256","7481.17"
    "sha512","64","2151.08"
    "sha512","8192","60377.77"

Table:  **OpenSSL CPU Load**

.. csv-table::
    :header: "Algorithm","am62xxsip_sk-fs: CPU Load"

    "aes-128-cbc","37.00"
    "aes-128-ecb","38.00"
    "aes-192-cbc","36.00"
    "aes-192-ecb","37.00"
    "aes-256-cbc","36.00"
    "aes-256-ecb","36.00"
    "sha256","98.00"
    "sha512","98.00"

Listed for each algorithm are the code snippets used to run each benchmark test.

::

    time -v openssl speed -elapsed -evp aes-128-cbc

IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am62xx_lp_sk-fs: Throughput (Mbps)","am62xx_lp_sk-fs: Packets/Sec","am62xx_lp_sk-fs: CPU Load","am62xx_sk-fs: Throughput (Mbps)","am62xx_sk-fs: Packets/Sec","am62xx_sk-fs: CPU Load","am62xxsip_sk-fs: Throughput (Mbps)","am62xxsip_sk-fs: Packets/Sec","am62xxsip_sk-fs: CPU Load"

    "3des","62.60","5.00","25.12","70.20","6.00","25.08","70.10","6.00","25.14"
    "aes128","240.30","21.00","46.55","267.40","23.00","46.90","270.00","24.00","46.98"
    "aes192","240.60","21.00","46.60","276.90","24.00","47.30","274.50","24.00","47.19"
    "aes256","274.00","24.00","47.04"

Low Power Performance
-------------------------

Table:  **Deep sleep**

.. csv-table::
    :header: "Rail name","Rail voltage(V)","am62xx_sk-fs"

    "vdd_core","0.85","9.82"
    "vddr_core","0.85","n/a"
    "soc_dvdd_3v3","3.30","6.33"
    "soc_dvdd_1v8","1.80","4.00"
    "vdda_1v8","1.80","1.80"
    "vdd_lpddr4/vdd_ddr4","1.10","8.60"
    "Total"," ","30.55"

Table:  **MCU only**

.. csv-table::
    :header: "Rail name","Rail voltage(V)","am62xx_sk-fs"

    "vdd_core","0.85","107.97"
    "vddr_core","0.85","n/a"
    "soc_dvdd_3v3","3.30","5.02"
    "soc_dvdd_1v8","1.80","4.80"
    "vdda_1v8","1.80","10.80"
    "vdd_lpddr4/vdd_ddr4","1.10","8.06"
    "Total"," ","136.66"

Partial I/O Data
- All voltage rails were measured to be near 0V

Further optimizations are possible for these low power modes. Please refer to the AM62x Power Consumption App Note (https://www.ti.com/lit/pdf/spradg1)
