
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

.. csv-table:: LMBench Benchmarks
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "af_unix_sock_stream_latency (microsec)","25.35","22.15","24.22"
    "af_unix_socket_stream_bandwidth (MBs)","590.14","636.97","756.44"
    "bw_file_rd-io-1mb (MB/s)","825.49","875.81","868.96"
    "bw_file_rd-o2c-1mb (MB/s)","486.78","524.66","492.13"
    "bw_mem-bcopy-16mb (MB/s)","702.37","762.52","736.41"
    "bw_mem-bcopy-1mb (MB/s)","736.51","786.91","750.33"
    "bw_mem-bcopy-2mb (MB/s)","702.12","761.81","735.29"
    "bw_mem-bcopy-4mb (MB/s)","730.99","784.01","712.25"
    "bw_mem-bcopy-8mb (MB/s)","750.40","806.86","734.08"
    "bw_mem-bzero-16mb (MB/s)","1771.68","1750.16","1749.97"
    "bw_mem-bzero-1mb (MB/s)","1253.06 (min 736.51, max 1769.60)","1262.42 (min 786.91, max 1737.92)","1237.24 (min 750.33, max 1724.14)"
    "bw_mem-bzero-2mb (MB/s)","1234.45 (min 702.12, max 1766.78)","1248.06 (min 761.81, max 1734.30)","1230.61 (min 735.29, max 1725.92)"
    "bw_mem-bzero-4mb (MB/s)","1249.93 (min 730.99, max 1768.87)","1261.19 (min 784.01, max 1738.37)","1218.82 (min 712.25, max 1725.38)"
    "bw_mem-bzero-8mb (MB/s)","1272.67 (min 750.40, max 1794.93)","1284.10 (min 806.86, max 1761.34)","1243.27 (min 734.08, max 1752.46)"
    "bw_mem-cp-16mb (MB/s)","407.63","450.35","432.04"
    "bw_mem-cp-1mb (MB/s)","524.79 (min 392.77, max 656.81)","591.78 (min 437.70, max 745.85)","541.69 (min 413.91, max 669.46)"
    "bw_mem-cp-2mb (MB/s)","496.65 (min 390.70, max 602.59)","546.84 (min 431.87, max 661.81)","519.64 (min 428.40, max 610.87)"
    "bw_mem-cp-4mb (MB/s)","544.49 (min 430.76, max 658.22)","608.11 (min 470.37, max 745.85)","515.34 (min 399.36, max 631.31)"
    "bw_mem-cp-8mb (MB/s)","567.80 (min 441.99, max 693.60)","625.42 (min 467.75, max 783.09)","523.71 (min 414.36, max 633.06)"
    "bw_mem-fcp-16mb (MB/s)","690.19","745.23","780.22"
    "bw_mem-fcp-1mb (MB/s)","1288.88 (min 808.15, max 1769.60)","1313.64 (min 889.36, max 1737.92)","1272.18 (min 820.21, max 1724.14)"
    "bw_mem-fcp-2mb (MB/s)","1237.12 (min 707.46, max 1766.78)","1300.12 (min 865.93, max 1734.30)","1254.45 (min 782.98, max 1725.92)"
    "bw_mem-fcp-4mb (MB/s)","1285.12 (min 801.36, max 1768.87)","1293.95 (min 849.53, max 1738.37)","1237.36 (min 749.34, max 1725.38)"
    "bw_mem-fcp-8mb (MB/s)","1300.21 (min 805.48, max 1794.93)","1339.86 (min 918.38, max 1761.34)","1280.03 (min 807.59, max 1752.46)"
    "bw_mem-frd-16mb (MB/s)","1089.92","1125.02","1069.73"
    "bw_mem-frd-1mb (MB/s)","1004.73 (min 808.15, max 1201.30)","1070.80 (min 889.36, max 1252.24)","1030.90 (min 820.21, max 1241.58)"
    "bw_mem-frd-2mb (MB/s)","874.84 (min 707.46, max 1042.21)","963.66 (min 865.93, max 1061.38)","931.45 (min 782.98, max 1079.91)"
    "bw_mem-frd-4mb (MB/s)","939.98 (min 801.36, max 1078.60)","985.93 (min 849.53, max 1122.33)","930.85 (min 749.34, max 1112.35)"
    "bw_mem-frd-8mb (MB/s)","944.67 (min 805.48, max 1083.86)","1021.86 (min 918.38, max 1125.33)","958.43 (min 807.59, max 1109.26)"
    "bw_mem-fwr-16mb (MB/s)","692.25","817.66","634.12"
    "bw_mem-fwr-1mb (MB/s)","929.06 (min 656.81, max 1201.30)","999.05 (min 745.85, max 1252.24)","955.52 (min 669.46, max 1241.58)"
    "bw_mem-fwr-2mb (MB/s)","822.40 (min 602.59, max 1042.21)","861.60 (min 661.81, max 1061.38)","845.39 (min 610.87, max 1079.91)"
    "bw_mem-fwr-4mb (MB/s)","868.41 (min 658.22, max 1078.60)","934.09 (min 745.85, max 1122.33)","871.83 (min 631.31, max 1112.35)"
    "bw_mem-fwr-8mb (MB/s)","888.73 (min 693.60, max 1083.86)","954.21 (min 783.09, max 1125.33)","871.16 (min 633.06, max 1109.26)"
    "bw_mem-rd-16mb (MB/s)","1099.66","1142.53","1107.34"
    "bw_mem-rd-1mb (MB/s)","914.01 (min 603.59, max 1224.42)","985.93 (min 702.12, max 1269.73)","950.51 (min 608.55, max 1292.47)"
    "bw_mem-rd-2mb (MB/s)","795.24 (min 504.10, max 1086.37)","885.09 (min 625.68, max 1144.49)","832.95 (min 546.08, max 1119.82)"
    "bw_mem-rd-4mb (MB/s)","851.53 (min 613.87, max 1089.18)","921.44 (min 710.86, max 1132.02)","838.70 (min 564.73, max 1112.66)"
    "bw_mem-rd-8mb (MB/s)","878.38 (min 673.63, max 1083.13)","957.35 (min 788.88, max 1125.81)","849.72 (min 581.02, max 1118.41)"
    "bw_mem-rdwr-16mb (MB/s)","728.03","755.32","592.97"
    "bw_mem-rdwr-1mb (MB/s)","484.49 (min 392.77, max 576.20)","535.11 (min 437.70, max 632.51)","506.72 (min 413.91, max 599.52)"
    "bw_mem-rdwr-2mb (MB/s)","446.42 (min 390.70, max 502.13)","525.10 (min 431.87, max 618.33)","479.17 (min 428.40, max 529.94)"
    "bw_mem-rdwr-4mb (MB/s)","512.43 (min 430.76, max 594.09)","583.38 (min 470.37, max 696.38)","477.42 (min 399.36, max 555.48)"
    "bw_mem-rdwr-8mb (MB/s)","559.04 (min 441.99, max 676.08)","637.31 (min 467.75, max 806.86)","498.73 (min 414.36, max 583.09)"
    "bw_mem-wr-16mb (MB/s)","733.81","833.77","592.83"
    "bw_mem-wr-1mb (MB/s)","589.90 (min 576.20, max 603.59)","667.32 (min 632.51, max 702.12)","604.04 (min 599.52, max 608.55)"
    "bw_mem-wr-2mb (MB/s)","503.12 (min 502.13, max 504.10)","622.01 (min 618.33, max 625.68)","538.01 (min 529.94, max 546.08)"
    "bw_mem-wr-4mb (MB/s)","603.98 (min 594.09, max 613.87)","703.62 (min 696.38, max 710.86)","560.11 (min 555.48, max 564.73)"
    "bw_mem-wr-8mb (MB/s)","674.86 (min 673.63, max 676.08)","797.87 (min 788.88, max 806.86)","582.06 (min 581.02, max 583.09)"
    "bw_mmap_rd-mo-1mb (MB/s)","1222.28","1257.86","1260.13"
    "bw_mmap_rd-o2c-1mb (MB/s)","439.43","470.81","446.83"
    "bw_pipe (MB/s)","444.93","491.71","538.24"
    "bw_unix (MB/s)","590.14","636.97","756.44"
    "lat_connect (us)","62.19","55.53","55.75"
    "lat_ctx-2-128k (us)","5.00","4.74","4.86"
    "lat_ctx-2-256k (us)","4.83","4.49","4.58"
    "lat_ctx-4-128k (us)","6.29","4.83","4.44"
    "lat_ctx-4-256k (us)","5.25","4.85","3.44"
    "lat_fs-0k (num_files)","255.00","245.00","245.00"
    "lat_fs-10k (num_files)","91.00","103.00","114.00"
    "lat_fs-1k (num_files)","157.00","150.00","179.00"
    "lat_fs-4k (num_files)","146.00","141.00","147.00"
    "lat_mem_rd-stride128-sz1000k (ns)","54.51","52.23","52.68"
    "lat_mem_rd-stride128-sz125k (ns)","6.22","5.54","5.59"
    "lat_mem_rd-stride128-sz250k (ns)","6.53","5.83","5.85"
    "lat_mem_rd-stride128-sz31k (ns)","2.42","2.17","3.64"
    "lat_mem_rd-stride128-sz50 (ns)","2.40","2.15","2.15"
    "lat_mem_rd-stride128-sz500k (ns)","16.00","14.50","15.05"
    "lat_mem_rd-stride128-sz62k (ns)","5.06","5.21","5.22"
    "lat_mmap-1m (us)","71.00","51.00","66.00"
    "lat_ops-double-add (ns)","3.20","2.86","2.86"
    "lat_ops-double-div (ns)","17.63","15.73","15.74"
    "lat_ops-double-mul (ns)","3.21","2.86","2.86"
    "lat_ops-float-add (ns)","3.21","2.86","2.86"
    "lat_ops-float-div (ns)","10.42","9.30","9.30"
    "lat_ops-float-mul (ns)","3.21","2.86","2.86"
    "lat_ops-int-add (ns)","0.80","0.72","0.72"
    "lat_ops-int-bit (ns)","0.53","0.48","0.48"
    "lat_ops-int-div (ns)","4.81","4.29","4.29"
    "lat_ops-int-mod (ns)","5.07","4.53","4.53"
    "lat_ops-int-mul (ns)","3.44","3.07","3.07"
    "lat_ops-int64-add (ns)","0.80","0.72","0.72"
    "lat_ops-int64-bit (ns)","0.53","0.48","0.48"
    "lat_ops-int64-div (ns)","7.61","6.79","6.80"
    "lat_ops-int64-mod (ns)","5.88","5.25","5.25"
    "lat_ops-int64-mul (ns)","4.09","3.71","3.65"
    "lat_pagefault (us)","1.81","1.66","1.67"
    "lat_pipe (us)","21.91","19.71","19.75"
    "lat_proc-exec (us)","1081.40","1009.40","1065.60"
    "lat_proc-fork (us)","849.86","795.43","792.00"
    "lat_proc-proccall (us)","0.01","0.01","0.01"
    "lat_select (us)","37.42","33.73","33.41"
    "lat_sem (us)","1.70","1.95","1.78"
    "lat_sig-catch (us)","6.10","5.40","5.41"
    "lat_sig-install (us)","0.73","0.67","0.67"
    "lat_sig-prot (us)","0.46","0.45","0.42"
    "lat_syscall-fstat (us)","3.01","2.68","2.71"
    "lat_syscall-null (us)","0.52","0.46","0.46"
    "lat_syscall-open (us)","193.30","163.47","167.13"
    "lat_syscall-read (us)","0.84","0.75","0.75"
    "lat_syscall-stat (us)","4.30","3.83","3.83"
    "lat_syscall-write (us)","0.75","0.67","0.67"
    "lat_tcp (us)","1.01","0.91","0.91"
    "lat_unix (us)","25.35","22.15","24.22"
    "latency_for_0.50_mb_block_size (nanosec)","16.00","14.50","15.05"
    "latency_for_1.00_mb_block_size (nanosec)","27.26 (min 0.00, max 54.51)","26.11 (min 0.00, max 52.23)","26.34 (min 0.00, max 52.68)"
    "pipe_bandwidth (MBs)","444.93","491.71","538.24"
    "pipe_latency (microsec)","21.91","19.71","19.75"
    "procedure_call (microsec)","0.01","0.01","0.01"
    "select_on_200_tcp_fds (microsec)","37.42","33.73","33.41"
    "semaphore_latency (microsec)","1.70","1.95","1.78"
    "signal_handler_latency (microsec)","0.73","0.67","0.67"
    "signal_handler_overhead (microsec)","6.10","5.40","5.41"
    "tcp_ip_connection_cost_to_localhost (microsec)","62.19","55.53","55.75"
    "tcp_latency_using_localhost (microsec)","1.01","0.91","0.91"




Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

Execute the benchmark with the following:

::

    runDhrystone

.. csv-table:: Dhrystone Benchmarks
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

.. csv-table:: Whetstone Benchmarks
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "whetstone (MIPS)","5000.00","10000.00","10000.00"




Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table:: Linpack Benchmarks
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "linpack (Kflops)","514126.00","579026.00","578928.00"




NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html

.. csv-table:: NBench Benchmarks
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "assignment (Iterations)","12.38","13.94","13.91"
    "fourier (Iterations)","20213.00","22640.00","22633.00"
    "fp_emulation (Iterations)","82.44","92.34","92.34"
    "huffman (Iterations)","1044.10","1169.50","1169.50"
    "idea (Iterations)","3075.80","3445.00","3444.80"
    "lu_decomposition (Iterations)","476.45","536.79","534.30"
    "neural_net (Iterations)","7.83","8.77","8.77"
    "numeric_sort (Iterations)","534.46","598.40","595.47"
    "string_sort (Iterations)","138.69","155.34","155.33"




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

.. csv-table:: Stream Benchmarks
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "add (MB/s)","1460.50","1444.40","1736.40"
    "copy (MB/s)","1546.60","1642.50","1890.90"
    "scale (MB/s)","1668.90","1837.40","1914.10"
    "triad (MB/s)","1430.60","1487.10","1698.80"




CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.



.. csv-table:: CoreMarkPro Benchmarks
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "cjpeg-rose7-preset (workloads/)","37.31","42.02","42.02"
    "core (workloads/)","0.27","0.30","0.30"
    "coremark-pro ()","811.35","902.24","888.68"
    "linear_alg-mid-100x100-sp (workloads/)","13.09","14.69","14.69"
    "loops-all-mid-10k-sp (workloads/)","0.60","0.67","0.67"
    "nnet_test (workloads/)","0.97","1.09","1.09"
    "parser-125k (workloads/)","7.41","8.20","8.26"
    "radix2-big-64k (workloads/)","55.49","60.22","52.59"
    "sha-test (workloads/)","72.46","80.65","80.00"
    "zip-test (workloads/)","18.87","20.83","20.83"





.. csv-table:: CoreMarkProTwoCore Benchmarks
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "cjpeg-rose7-preset (workloads/)","74.07","83.33","84.03"
    "core (workloads/)","0.54","0.60","0.60"
    "coremark-pro ()","1345.72","1477.45","1572.24"
    "linear_alg-mid-100x100-sp (workloads/)","26.21","29.36","29.36"
    "loops-all-mid-10k-sp (workloads/)","1.03","1.16","1.24"
    "nnet_test (workloads/)","1.94","2.17","2.18"
    "parser-125k (workloads/)","10.47","11.76","13.25"
    "radix2-big-64k (workloads/)","37.94","37.18","48.60"
    "sha-test (workloads/)","142.86","158.73","161.29"
    "zip-test (workloads/)","34.48","37.04","40.00"

 
 


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

.. csv-table:: Multibench Benchmarks
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "4m-check (workloads/)","285.16","307.47","303.10"
    "4m-check-reassembly (workloads/)","62.38","66.53","64.14"
    "4m-check-reassembly-tcp (workloads/)","40.26","42.81","42.09"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","22.67","24.21","24.34"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.63","1.79","1.79"
    "4m-cmykw2 (workloads/)","188.15","199.60","200.60"
    "4m-cmykw2-rotatew2 (workloads/)","36.59","39.40","38.78"
    "4m-reassembly (workloads/)","50.81","53.42","51.76"
    "4m-rotatew2 (workloads/)","41.79","44.98","46.21"
    "4m-tcp-mixed (workloads/)","94.67","102.56","102.56"
    "4m-x264w2 (workloads/)","1.70","1.87","1.86"
    "empty-wld (workloads/)","1.00","1.00","1.00"
    "idct-4m (workloads/)","16.82","18.59","18.52"
    "idct-4mw1 (workloads/)","16.82","18.59","18.58"
    "ippktcheck-4m (workloads/)","285.39","306.41","303.84"
    "ippktcheck-4mw1 (workloads/)","285.42","306.26","302.77"
    "ipres-4m (workloads/)","62.09","63.64","63.75"
    "ipres-4mw1 (workloads/)","60.90","64.82","63.53"
    "md5-4m (workloads/)","23.99","26.21","26.08"
    "md5-4mw1 (workloads/)","23.92","26.02","25.89"
    "rgbcmyk-4m (workloads/)","57.47","63.84","63.59"
    "rgbcmyk-4mw1 (workloads/)","57.13","63.67","63.53"
    "rotate-4ms1 (workloads/)","17.16","18.42","18.45"
    "rotate-4ms1w1 (workloads/)","17.18","18.42","18.40"
    "rotate-4ms64 (workloads/)","17.40","18.57","18.66"
    "rotate-4ms64w1 (workloads/)","17.39","18.46","18.59"
    "x264-4mq (workloads/)","0.50","0.56","0.56"
    "x264-4mqw1 (workloads/)","0.50","0.56","0.56"



 
 



|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: Boot time MMCSD
    :header: "Boot Configuration","am62xx_sk-fs: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","15.77 (min 15.31, max 16.17)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","3.50 (min 3.47, max 3.52)"



 
 



|

ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64


.. csv-table:: Audio Capture
    :header: "Sampling Rate (Hz)","am62xx_lp_sk-fs: Throughput (bits/sec)","am62xx_lp_sk-fs: CPU Load (%)","am62xx_sk-fs: Throughput (bits/sec)","am62xx_sk-fs: CPU Load (%)","am62xxsip_sk-fs: Throughput (bits/sec)","am62xxsip_sk-fs: CPU Load (%)"

    "8000","255998.00","0.16","255997.00","0.20","255999.00","0.30"
    "11025","352797.00","0.18","352797.00","0.15","352798.00","0.14"
    "16000","511996.00","0.13","511996.00","0.43","511998.00","0.81"
    "22050","705595.00","0.30","705595.00","0.28","705598.00","0.25"
    "24000","705594.00","0.30","705594.00","0.26","705596.00","0.24"
    "32000","1023989.00","0.71","1023990.00","0.17","1023992.00","0.74"
    "44100","1411185.00","0.47","1411186.00","0.41","1411190.00","0.38"
    "48000","1535982.00","0.23","1535985.00","0.21","1535990.00","0.20"
    "88200","2822366.00","0.94","2822365.00","0.86","2822380.00","0.78"
    "96000","3071964.00","2.17","3071967.00","0.32","3071977.00","0.30"



 
 



 



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

.. csv-table:: CPSW2g TCP Bidirectional Throughput
    :header: "Command Used","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xxsip_sk-fs: THROUGHPUT (Mbits/sec)","am62xxsip_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1779.49","66.66","1801.91","64.51","1799.86","64.65"




.. rubric::  TCP Bidirectional Throughput Interrupt Pacing
   :name: CPSW2g-tcp-bidirectional-throughput-interrupt-pacing

.. csv-table:: CPSW2g TCP Bidirectional Throughput Interrupt Pacing
    :header: "Command Used","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xxsip_sk-fs: THROUGHPUT (Mbits/sec)","am62xxsip_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1669.02","52.26","1526.73","44.96","1502.65","40.60"




.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table:: CPSW2g UDP Egress Throughput 0 loss
    :header: "Frame Size(bytes)","am62xx_lp_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: Packets Per Second (kPPS)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_sk-fs: Packets Per Second (kPPS)","am62xx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xxsip_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xxsip_sk-fs: THROUGHPUT (Mbits/sec)","am62xxsip_sk-fs: Packets Per Second (kPPS)","am62xxsip_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","16.22","113.00","40.06","18.00","18.25","127.00","39.96","18.00","20.11","140.00","42.05"
    "128","82.00","73.19","112.00","39.85","82.00","80.72","123.00","39.95","82.00","89.22","136.00","41.41"
    "256","210.00","188.81","112.00","39.89","210.00","210.45","125.00","40.29","210.00","214.83","128.00","40.52"
    "1024","978.00","874.21","112.00","40.01","978.00","935.21","120.00","45.98","978.00","935.15","120.00","42.09"
    "1518","1472.00","890.71","76.00","34.33","1472.00","955.28","81.00","33.99","1472.00","955.93","81.00","33.28"





.. csv-table:: CPSW2g UDP Ingress Throughput 0 loss
    :header: "Frame Size(bytes)","am62xx_lp_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: Packets Per Second (kPPS)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_sk-fs: Packets Per Second (kPPS)","am62xx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xxsip_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xxsip_sk-fs: THROUGHPUT (Mbits/sec)","am62xxsip_sk-fs: Packets Per Second (kPPS)","am62xxsip_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","6.42","45.00","26.15","18.00","1.71","12.00","12.76","18.00","7.57","53.00","28.32"
    "128","82.00","53.13","81.00","32.83","82.00","9.71","15.00","20.60","82.00","4.33","7.00","8.40"
    "256","210.00","239.00","142.00","40.46","210.00","28.22","17.00","22.47","210.00","30.58","18.00","18.20"
    "1024","978.00","936.50","120.00","42.40","978.00","936.61","120.00","42.47","978.00","936.74","120.00","42.69"
    "1518","1472.00","951.32","81.00","41.59","1472.00","941.84","80.00","39.63","1472.00","957.11","81.00","40.05"





.. csv-table:: CPSW2g UDP Ingress Throughput possible loss
    :header: "Frame Size(bytes)","am62xx_lp_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: Packets Per Second (kPPS)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_lp_sk-fs: Packet Loss %","am62xx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_sk-fs: Packets Per Second (kPPS)","am62xx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_sk-fs: Packet Loss %","am62xxsip_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xxsip_sk-fs: THROUGHPUT (Mbits/sec)","am62xxsip_sk-fs: Packets Per Second (kPPS)","am62xxsip_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xxsip_sk-fs: Packet Loss %"

    "64","18.00","25.40","176.00","38.75","61.81","18.00","27.33","190.00","38.86","50.27","18.00","30.40","211.00","38.98","75.61"
    "128","82.00","94.83","145.00","38.33","0.01","82.00","124.40","190.00","41.01","52.39","82.00","137.60","210.00","40.71","72.13"
    "256","210.00","262.95","157.00","41.45","5.79","210.00","312.68","186.00","41.82","52.80","210.00","339.55","202.00","42.15","36.26"
    "1024","978.00","936.50","120.00","42.40","0.00","978.00","936.61","120.00","42.47","0.00","978.00","936.25","120.00","42.41","0.04"
    "1518","1472.00","951.32","81.00","41.59","0.00","1472.00","954.00","81.00","40.10","0.02","1472.00","956.90","81.00","39.99","0.02"

 
 

 

 
 

 

 

 

 



|

UBoot QSPI/OSPI Driver
-------------------------

AM62XX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^






.. csv-table:: UBOOT QSPI or OSPI
    :header: "File size (bytes in hex)","am62xxsip_sk-fs: Write Throughput (Kbytes/sec)","am62xxsip_sk-fs: Read Throughput (Kbytes/sec)"

    "400000","383.09","195047.62"
    "800000","384.08","240941.18"
    "1000000","386.04","268590.16"
    "2000000","382.39","284939.13"

 
 

 

 

 



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


.. csv-table:: EMMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","am62xx_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62xx_sk-fs: Write EXT4 CPU Load (%)","am62xx_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62xx_sk-fs: Read EXT4 CPU Load (%)"

    "1m","59.70","1.26","175.00","1.55"
    "4m","59.90","1.04","175.00","1.28"
    "4k","51.50","18.42","55.80","17.37"
    "256k","59.60","1.66","174.00","2.11"




.. csv-table:: EMMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","am62xx_lp_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62xx_lp_sk-fs: Write EXT4 CPU Load (%)","am62xx_lp_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62xx_lp_sk-fs: Read EXT4 CPU Load (%)"

    "1m","61.40","1.50","175.00","1.84"
    "4m","61.40","1.13","175.00","1.69"
    "4k","51.70","20.23","56.80","19.24"
    "256k","61.60","1.79","174.00","2.59"




.. csv-table:: EMMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","am62xxsip_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62xxsip_sk-fs: Write EXT4 CPU Load (%)","am62xxsip_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62xxsip_sk-fs: Read EXT4 CPU Load (%)"

    "1m","91.70","1.76","172.00","1.56"
    "4m","97.70","1.54","172.00","1.53"
    "4k","63.80","23.68","91.00","25.57"
    "256k","91.50","1.92","171.00","2.06"

  
 



|

UBoot EMMC Driver
-------------------------

AM62XX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^



.. csv-table:: UBOOT EMMC RAW
    :header: "File size (bytes in hex)","am62xx_sk-fs: Write Throughput (Kbytes/sec)","am62xx_sk-fs: Read Throughput (Kbytes/sec)"

    "2000000","56790.29","169782.38"
    "4000000","57437.34","173375.66"





.. csv-table:: UBOOT EMMC RAW
    :header: "File size (bytes in hex)","am62xx_lp_sk-fs: Write Throughput (Kbytes/sec)","am62xx_lp_sk-fs: Read Throughput (Kbytes/sec)"

    "2000000","61134.33","171560.21"
    "4000000","61768.14","173835.54"





.. csv-table:: UBOOT EMMC RAW
    :header: "File size (bytes in hex)","am62xxsip_sk-fs: Write Throughput (Kbytes/sec)","am62xxsip_sk-fs: Read Throughput (Kbytes/sec)"

    "2000000","99296.97","172463.16"
    "4000000","97523.81","175229.95"

 
 
 



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


.. csv-table:: MMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","am62xx_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62xx_sk-fs: Write EXT4 CPU Load (%)","am62xx_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62xx_sk-fs: Read EXT4 CPU Load (%)"

    "1m","20.00","0.73","85.60","1.04"
    "4m","19.90","0.51","85.50","0.84"
    "4k","7.10","2.98","21.60","6.86"
    "256k","19.80","0.81","82.90","1.39"




.. csv-table:: MMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","am62xx_lp_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62xx_lp_sk-fs: Write EXT4 CPU Load (%)","am62xx_lp_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62xx_lp_sk-fs: Read EXT4 CPU Load (%)"

    "1m","13.40","0.68","90.70","1.35"
    "4m","15.80","0.56","90.90","1.08"
    "4k","5.29","2.86","15.50","5.79"
    "256k","13.30","0.72","88.00","1.48"




.. csv-table:: MMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","am62xxsip_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62xxsip_sk-fs: Write EXT4 CPU Load (%)","am62xxsip_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62xxsip_sk-fs: Read EXT4 CPU Load (%)"

    "1m","18.60","0.64","87.30","1.02"
    "4m","18.50","0.63","83.90","1.05"
    "4k","4.88","2.15","16.80","5.39"
    "256k","17.70","0.76","85.40","1.14"

 



 

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|

UBoot MMC/SD Driver
-------------------------

AM62XX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^







.. csv-table:: UBOOT MMCSD FAT
    :header: "File size (bytes in hex)","am62xxsip_sk-fs: Write Throughput (Kbytes/sec)","am62xxsip_sk-fs: Read Throughput (Kbytes/sec)"

    "400000","38280.37","62060.61"
    "800000","33573.77","74472.73"
    "1000000","49349.40","82747.47"

  
  


 
 

 



|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: OpenSSL Performance
    :header: "Algorithm","Buffer Size (in bytes)","am62xxsip_sk-fs: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","27663.70"
    "aes-128-cbc","16","538.77"
    "aes-128-cbc","16384","136964.78"
    "aes-128-cbc","256","8214.44"
    "aes-128-cbc","64","2144.13"
    "aes-128-cbc","8192","106700.80"
    "aes-128-ecb","1024","28235.78"
    "aes-128-ecb","16","547.69"
    "aes-128-ecb","16384","141989.21"
    "aes-128-ecb","256","8426.50"
    "aes-128-ecb","64","2193.66"
    "aes-128-ecb","8192","110455.47"
    "aes-192-cbc","1024","27530.58"
    "aes-192-cbc","16","536.29"
    "aes-192-cbc","16384","129264.30"
    "aes-192-cbc","256","8147.37"
    "aes-192-cbc","64","2133.99"
    "aes-192-cbc","8192","101856.60"
    "aes-192-ecb","1024","28363.43"
    "aes-192-ecb","16","551.74"
    "aes-192-ecb","16384","133393.07"
    "aes-192-ecb","256","8342.02"
    "aes-192-ecb","64","2199.23"
    "aes-192-ecb","8192","105299.97"
    "aes-256-cbc","1024","27312.13"
    "aes-256-cbc","16","534.94"
    "aes-256-cbc","16384","119821.65"
    "aes-256-cbc","256","8049.07"
    "aes-256-cbc","64","2132.80"
    "aes-256-cbc","8192","96236.89"
    "aes-256-ecb","1024","27939.84"
    "aes-256-ecb","16","553.75"
    "aes-256-ecb","16384","124436.48"
    "aes-256-ecb","256","8252.84"
    "aes-256-ecb","64","2191.64"
    "aes-256-ecb","8192","100291.93"
    "sha256","1024","35595.26"
    "sha256","16","595.92"
    "sha256","16384","279445.50"
    "sha256","256","9329.49"
    "sha256","64","2350.44"
    "sha256","8192","190690.65"
    "sha512","1024","25202.69"
    "sha512","16","580.97"
    "sha512","16384","68736.34"
    "sha512","256","8311.81"
    "sha512","64","2326.34"
    "sha512","8192","61530.11"





.. csv-table:: OpenSSL CPU Load
    :header: "Algorithm","am62xxsip_sk-fs: CPU Load"

    "aes-128-cbc","36.00"
    "aes-128-ecb","38.00"
    "aes-192-cbc","36.00"
    "aes-192-ecb","37.00"
    "aes-256-cbc","36.00"
    "aes-256-ecb","36.00"
    "sha256","98.00"
    "sha512","98.00"



Listed for each algorithm are the code snippets used to run each
  benchmark test.

::

    time -v openssl speed -elapsed -evp aes-128-cbc

IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: IPSec Software Performance
    :header: "Algorithm","am62xx_lp_sk-fs: Throughput (Mbps)","am62xx_lp_sk-fs: Packets/Sec","am62xx_lp_sk-fs: CPU Load","am62xx_sk-fs: Throughput (Mbps)","am62xx_sk-fs: Packets/Sec","am62xx_sk-fs: CPU Load","am62xxsip_sk-fs: Throughput (Mbps)","am62xxsip_sk-fs: Packets/Sec","am62xxsip_sk-fs: CPU Load"

    "3des","61.60","5.00","25.12","69.10","6.00","25.12","71.70","6.00","25.13"
    "aes128","239.40","21.00","46.47","274.00","24.00","47.12","318.20","28.00","47.70"
    "aes192","242.80","21.00","46.55","276.40","24.00","47.04","321.10","28.00","47.64"
    "aes256","331.70","29.00","48.03"

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
