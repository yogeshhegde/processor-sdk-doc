***********************
Linux Performance Guide
***********************


.. rubric::  **Read This First**

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+-------------------------------------------------------------------------------------------+
| Name           | Description                                                                               |
+================+===========================================================================================+
| AM62x EVM      | AM62x Starter Kit rev E2 and E3 with ARM running at 1400 MHz, DDR4 data rate 1600 MT/S    |
+----------------+-------------------------------------------------------------------------------------------+
| AM62x SK LP    | AM62x LP Starter Kit rev E1 with ARM running at 1250 MHz, LPDDR4 data rate 1600 MT/S      |
+----------------+-------------------------------------------------------------------------------------------+
| AM62SIP SK     | AM62SIP Starter Kit rev E1 with ARM running at 1400 MHz, 512MB LPDDR4 data rate 1600 MT/S |
+----------------+-------------------------------------------------------------------------------------------+

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

    "af_unix_sock_stream_latency (microsec)","26.96","22.33","22.46"
    "af_unix_socket_stream_bandwidth (MBs)","553.77","627.47","754.95"
    "bw_file_rd-io-1mb (MB/s)","775.67","887.63","878.89"
    "bw_file_rd-o2c-1mb (MB/s)","431.72","518.05","494.72"
    "bw_mem-bcopy-16mb (MB/s)","663.51","763.43","749.45"
    "bw_mem-bcopy-1mb (MB/s)","723.98","805.54","773.99"
    "bw_mem-bcopy-2mb (MB/s)","666.33","787.19","755.29"
    "bw_mem-bcopy-4mb (MB/s)","695.65","785.78","717.62"
    "bw_mem-bcopy-8mb (MB/s)","703.54","810.95","746.34"
    "bw_mem-bzero-16mb (MB/s)","1672.24","1757.86","1747.49"
    "bw_mem-bzero-1mb (MB/s)","1194.63 (min 723.98, max 1665.28)","1271.43 (min 805.54, max 1737.32)","1252.05 (min 773.99, max 1730.10)"
    "bw_mem-bzero-2mb (MB/s)","1165.81 (min 666.33, max 1665.28)","1260.45 (min 787.19, max 1733.70)","1241.21 (min 755.29, max 1727.12)"
    "bw_mem-bzero-4mb (MB/s)","1182.90 (min 695.65, max 1670.15)","1259.19 (min 785.78, max 1732.60)","1220.51 (min 717.62, max 1723.40)"
    "bw_mem-bzero-8mb (MB/s)","1197.26 (min 703.54, max 1690.97)","1278.17 (min 810.95, max 1745.39)","1247.87 (min 746.34, max 1749.40)"
    "bw_mem-cp-16mb (MB/s)","384.05","450.03","425.96"
    "bw_mem-cp-1mb (MB/s)","497.71 (min 392.00, max 603.41)","593.38 (min 443.26, max 743.49)","536.28 (min 407.77, max 664.78)"
    "bw_mem-cp-2mb (MB/s)","470.29 (min 370.44, max 570.13)","565.51 (min 440.04, max 690.97)","518.57 (min 428.13, max 609.01)"
    "bw_mem-cp-4mb (MB/s)","512.35 (min 401.73, max 622.96)","606.88 (min 447.03, max 766.72)","511.38 (min 395.80, max 626.96)"
    "bw_mem-cp-8mb (MB/s)","526.34 (min 400.78, max 651.89)","637.55 (min 498.63, max 776.47)","520.21 (min 406.96, max 633.46)"
    "bw_mem-fcp-16mb (MB/s)","665.61","740.30","745.50"
    "bw_mem-fcp-1mb (MB/s)","1221.60 (min 777.91, max 1665.28)","1315.49 (min 893.66, max 1737.32)","1261.75 (min 793.40, max 1730.10)"
    "bw_mem-fcp-2mb (MB/s)","1191.77 (min 718.26, max 1665.28)","1288.38 (min 843.05, max 1733.70)","1263.88 (min 800.64, max 1727.12)"
    "bw_mem-fcp-4mb (MB/s)","1208.35 (min 746.55, max 1670.15)","1315.94 (min 899.28, max 1732.60)","1231.87 (min 740.33, max 1723.40)"
    "bw_mem-fcp-8mb (MB/s)","1228.23 (min 765.48, max 1690.97)","1331.83 (min 918.27, max 1745.39)","1274.18 (min 798.96, max 1749.40)"
    "bw_mem-frd-16mb (MB/s)","976.92","1100.11","1072.82"
    "bw_mem-frd-1mb (MB/s)","963.89 (min 777.91, max 1149.87)","1080.78 (min 893.66, max 1267.89)","1012.90 (min 793.40, max 1232.39)"
    "bw_mem-frd-2mb (MB/s)","869.86 (min 718.26, max 1021.45)","974.01 (min 843.05, max 1104.97)","937.86 (min 800.64, max 1075.08)"
    "bw_mem-frd-4mb (MB/s)","878.77 (min 746.55, max 1010.99)","1011.52 (min 899.28, max 1123.75)","899.55 (min 740.33, max 1058.76)"
    "bw_mem-frd-8mb (MB/s)","892.23 (min 765.48, max 1018.98)","1010.25 (min 918.27, max 1102.23)","953.73 (min 798.96, max 1108.49)"
    "bw_mem-fwr-16mb (MB/s)","647.93","822.45","636.51"
    "bw_mem-fwr-1mb (MB/s)","876.64 (min 603.41, max 1149.87)","1005.69 (min 743.49, max 1267.89)","948.59 (min 664.78, max 1232.39)"
    "bw_mem-fwr-2mb (MB/s)","795.79 (min 570.13, max 1021.45)","897.97 (min 690.97, max 1104.97)","842.05 (min 609.01, max 1075.08)"
    "bw_mem-fwr-4mb (MB/s)","816.98 (min 622.96, max 1010.99)","945.24 (min 766.72, max 1123.75)","842.86 (min 626.96, max 1058.76)"
    "bw_mem-fwr-8mb (MB/s)","835.44 (min 651.89, max 1018.98)","939.35 (min 776.47, max 1102.23)","870.98 (min 633.46, max 1108.49)"
    "bw_mem-rd-16mb (MB/s)","1041.26","1138.06","1123.04"
    "bw_mem-rd-1mb (MB/s)","860.45 (min 552.28, max 1168.61)","999.07 (min 699.91, max 1298.22)","934.45 (min 589.88, max 1279.01)"
    "bw_mem-rd-2mb (MB/s)","765.66 (min 500.38, max 1030.93)","856.75 (min 592.42, max 1121.08)","838.03 (min 554.55, max 1121.50)"
    "bw_mem-rd-4mb (MB/s)","796.81 (min 568.10, max 1025.51)","919.68 (min 707.34, max 1132.02)","844.02 (min 569.31, max 1118.72)"
    "bw_mem-rd-8mb (MB/s)","833.08 (min 636.28, max 1029.87)","934.69 (min 735.90, max 1133.47)","847.05 (min 578.03, max 1116.07)"
    "bw_mem-rdwr-16mb (MB/s)","676.16","794.44","590.10"
    "bw_mem-rdwr-1mb (MB/s)","477.85 (min 392.00, max 563.70)","572.26 (min 443.26, max 701.26)","503.06 (min 407.77, max 598.35)"
    "bw_mem-rdwr-2mb (MB/s)","427.41 (min 370.44, max 484.38)","510.34 (min 440.04, max 580.64)","485.36 (min 428.13, max 542.59)"
    "bw_mem-rdwr-4mb (MB/s)","486.01 (min 401.73, max 570.29)","561.58 (min 447.03, max 676.13)","480.91 (min 395.80, max 566.01)"
    "bw_mem-rdwr-8mb (MB/s)","508.13 (min 400.78, max 615.48)","635.72 (min 498.63, max 772.80)","495.26 (min 406.96, max 583.56)"
    "bw_mem-wr-16mb (MB/s)","683.12","829.10","593.01"
    "bw_mem-wr-1mb (MB/s)","557.99 (min 552.28, max 563.70)","700.59 (min 699.91, max 701.26)","594.12 (min 589.88, max 598.35)"
    "bw_mem-wr-2mb (MB/s)","492.38 (min 484.38, max 500.38)","586.53 (min 580.64, max 592.42)","548.57 (min 542.59, max 554.55)"
    "bw_mem-wr-4mb (MB/s)","569.20 (min 568.10, max 570.29)","691.74 (min 676.13, max 707.34)","567.66 (min 566.01, max 569.31)"
    "bw_mem-wr-8mb (MB/s)","625.88 (min 615.48, max 636.28)","754.35 (min 735.90, max 772.80)","580.80 (min 578.03, max 583.56)"
    "bw_mmap_rd-mo-1mb (MB/s)","1153.59","1275.05","1261.03"
    "bw_mmap_rd-o2c-1mb (MB/s)","383.34","493.66","453.79"
    "bw_pipe (MB/s)","425.37","475.12","526.86"
    "bw_unix (MB/s)","553.77","627.47","754.95"
    "lat_connect (us)","61.94","56.09","55.66"
    "lat_ctx-2-128k (us)","5.66","5.13","4.77"
    "lat_ctx-2-256k (us)","4.84","5.35","3.87"
    "lat_ctx-4-128k (us)","5.21","3.78","5.07"
    "lat_ctx-4-256k (us)","3.83","3.24","0.00"
    "lat_fs-0k (num_files)","233.00","291.00","285.00"
    "lat_fs-10k (num_files)","88.00","100.00","106.00"
    "lat_fs-1k (num_files)","156.00","176.00","177.00"
    "lat_fs-4k (num_files)","145.00","174.00","149.00"
    "lat_mem_rd-stride128-sz1000k (ns)","57.66","52.46","52.86"
    "lat_mem_rd-stride128-sz125k (ns)","6.20","5.54","5.55"
    "lat_mem_rd-stride128-sz250k (ns)","6.53","5.83","5.84"
    "lat_mem_rd-stride128-sz31k (ns)","4.70","2.16","2.16"
    "lat_mem_rd-stride128-sz50 (ns)","2.40","2.15","2.15"
    "lat_mem_rd-stride128-sz500k (ns)","20.81","16.90","17.91"
    "lat_mem_rd-stride128-sz62k (ns)","5.81","5.24","5.24"
    "lat_mmap-1m (us)","57.00","62.00","50.00"
    "lat_ops-double-add (ns)","3.20","2.86","2.86"
    "lat_ops-double-div (ns)","17.62","15.73","15.74"
    "lat_ops-double-mul (ns)","3.21","2.86","2.86"
    "lat_ops-float-add (ns)","3.21","2.86","2.86"
    "lat_ops-float-div (ns)","10.41","9.30","9.30"
    "lat_ops-float-mul (ns)","3.21","2.86","2.86"
    "lat_ops-int-add (ns)","0.80","0.72","0.72"
    "lat_ops-int-bit (ns)","0.53","0.48","0.48"
    "lat_ops-int-div (ns)","4.81","4.29","4.29"
    "lat_ops-int-mod (ns)","5.07","4.53","4.53"
    "lat_ops-int-mul (ns)","3.44","3.07","3.08"
    "lat_ops-int64-add (ns)","0.80","0.72","0.72"
    "lat_ops-int64-bit (ns)","0.53","0.48","0.48"
    "lat_ops-int64-div (ns)","7.61","6.79","6.79"
    "lat_ops-int64-mod (ns)","5.88","5.25","5.25"
    "lat_ops-int64-mul (ns)","4.09","3.59","3.59"
    "lat_pagefault (us)","1.72","1.52","1.53"
    "lat_pipe (us)","22.27","19.99","19.87"
    "lat_proc-exec (us)","1116.60","1003.20","1013.80"
    "lat_proc-fork (us)","891.33","769.25","803.43"
    "lat_proc-proccall (us)","0.01","0.01","0.01"
    "lat_select (us)","37.01","32.95","33.05"
    "lat_sem (us)","2.34","1.90","1.40"
    "lat_sig-catch (us)","6.05","5.45","5.41"
    "lat_sig-install (us)","0.72","0.65","0.64"
    "lat_sig-prot (us)","0.59","0.52","0.58"
    "lat_syscall-fstat (us)","2.72","2.44","2.44"
    "lat_syscall-null (us)","0.52","0.46","0.46"
    "lat_syscall-open (us)","160.63","163.36","168.47"
    "lat_syscall-read (us)","0.84","0.75","0.75"
    "lat_syscall-stat (us)","3.80","3.41","3.38"
    "lat_syscall-write (us)","0.73","0.66","0.66"
    "lat_tcp (us)","1.02","0.91","0.91"
    "lat_unix (us)","26.96","22.33","22.46"
    "latency_for_0.50_mb_block_size (nanosec)","20.81","16.90","17.91"
    "latency_for_1.00_mb_block_size (nanosec)","28.83 (min 0.00, max 57.66)","26.23 (min 0.00, max 52.46)","26.43 (min 0.00, max 52.86)"
    "pipe_bandwidth (MBs)","425.37","475.12","526.86"
    "pipe_latency (microsec)","22.27","19.99","19.87"
    "procedure_call (microsec)","0.01","0.01","0.01"
    "select_on_200_tcp_fds (microsec)","37.01","32.95","33.05"
    "semaphore_latency (microsec)","2.34","1.90","1.40"
    "signal_handler_latency (microsec)","0.72","0.65","0.64"
    "signal_handler_overhead (microsec)","6.05","5.45","5.41"
    "tcp_ip_connection_cost_to_localhost (microsec)","61.94","56.09","55.66"
    "tcp_latency_using_localhost (microsec)","1.02","0.91","0.91"

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
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "cpu_clock (MHz)","1250.00","1400.00","1400.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.90","2.90","3.00"
    "dhrystone_per_second (DhrystoneP)","6451613.00","7142857.00","7407407.50"

Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Whetstone is a benchmark primarily measuring floating-point arithmetic performance.

Execute the benchmark with the following:

::

    runWhetstone

.. csv-table::
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "whetstone (MIPS)","5000.00","5000.00","10000.00"

Table:  **Whetstone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "linpack (Kflops)","517068.00","579612.00","577710.00"

Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html

.. csv-table::
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "assignment (Iterations)","12.40","13.90","13.90"
    "fourier (Iterations)","20210.00","22638.00","22639.00"
    "fp_emulation (Iterations)","82.38","92.29","92.29"
    "huffman (Iterations)","1043.90","1169.50","1169.40"
    "idea (Iterations)","3075.40","3444.90","3444.90"
    "lu_decomposition (Iterations)","476.63","533.76","534.01"
    "neural_net (Iterations)","7.87","8.82","8.82"
    "numeric_sort (Iterations)","530.31","598.66","598.49"
    "string_sort (Iterations)","147.26","164.96","164.94"

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
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "add (MB/s)","1371.30","1452.70","1396.80"
    "copy (MB/s)","1445.80","1644.40","1525.30"
    "scale (MB/s)","1589.80","1839.30","1569.20"
    "triad (MB/s)","1348.50","1490.80","1372.90"

Table:  **Stream**

CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.

.. csv-table::
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf","am62xxsip_sk-fs: perf"

    "cjpeg-rose7-preset (workloads/)","37.45","41.67","41.84"
    "core (workloads/)","0.27","0.30","0.30"
    "coremark-pro ()","809.96","903.14","839.36"
    "linear_alg-mid-100x100-sp (workloads/)","13.11","14.69","14.69"
    "loops-all-mid-10k-sp (workloads/)","0.60","0.67","0.67"
    "nnet_test (workloads/)","0.97","1.09","1.09"
    "parser-125k (workloads/)","7.35","8.26","8.20"
    "radix2-big-64k (workloads/)","55.19","60.83","31.57"
    "sha-test (workloads/)","71.94","80.65","80.65"
    "zip-test (workloads/)","18.87","20.83","20.83"

Table:  **CoreMarkPro**

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

    "4m-check (workloads/)","269.37","306.34","301.68"
    "4m-check-reassembly (workloads/)","58.65","65.45","64.18"
    "4m-check-reassembly-tcp (workloads/)","38.11","43.10","42.02"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","21.70","24.14","24.32"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.61","1.80","1.80"
    "4m-cmykw2 (workloads/)","178.41","200.60","201.01"
    "4m-cmykw2-rotatew2 (workloads/)","34.99","39.55","39.04"
    "4m-reassembly (workloads/)","47.13","52.38","51.12"
    "4m-rotatew2 (workloads/)","40.00","44.82","46.04"
    "4m-tcp-mixed (workloads/)","91.95","103.23","103.90"
    "4m-x264w2 (workloads/)","1.68","1.86","1.87"
    "empty-wld (workloads/)","1.00","1.00","1.00"
    "idct-4m (workloads/)","16.74","18.61","18.59"
    "idct-4mw1 (workloads/)","16.76","18.57","18.58"
    "ippktcheck-4m (workloads/)","271.15","305.74","303.84"
    "ippktcheck-4mw1 (workloads/)","273.85","306.71","303.62"
    "ipres-4m (workloads/)","57.43","64.35","63.48"
    "ipres-4mw1 (workloads/)","57.89","63.99","63.37"
    "md5-4m (workloads/)","23.40","26.14","26.26"
    "md5-4mw1 (workloads/)","23.10","26.33","26.29"
    "rgbcmyk-4m (workloads/)","56.67","63.76","63.57"
    "rgbcmyk-4mw1 (workloads/)","56.59","63.55","63.55"
    "rotate-4ms1 (workloads/)","16.57","18.32","18.49"
    "rotate-4ms1w1 (workloads/)","16.42","18.35","18.48"
    "rotate-4ms64 (workloads/)","16.64","18.63","18.66"
    "rotate-4ms64w1 (workloads/)","16.64","18.58","18.57"
    "x264-4mq (workloads/)","0.50","0.56","0.56"
    "x264-4mqw1 (workloads/)","0.50","0.56","0.56"

Table:  **Multibench**

|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am62xx_lp_sk-fs: boot time (sec)","am62xx_sk-fs: boot time (sec)","am62xxsip_sk-fs: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","22.05 (min 21.32, max 23.96)","25.25 (min 21.31, max 31.45)","20.70 (min 20.32, max 21.51)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","7.02 (min 6.95, max 7.30)","7.00 (min 6.94, max 7.09)","6.87 (min 6.79, max 7.04)"

Table:  **Boot time MMC/SD**

|

ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64

.. csv-table::
    :header: "Sampling Rate (Hz)","am62xx_lp_sk-fs: Throughput (bits/sec)","am62xx_lp_sk-fs: CPU Load (%)","am62xx_sk-fs: Throughput (bits/sec)","am62xx_sk-fs: CPU Load (%)","am62xxsip_sk-fs: Throughput (bits/sec)","am62xxsip_sk-fs: CPU Load (%)"

    "8000","255998.00","0.10","256000.00","0.09","255999.00","0.07"
    "11025","352798.00","0.17","352800.00","0.15","352799.00","0.15"
    "16000","511997.00","0.12","512000.00","0.10","511999.00","0.09"
    "22050","705595.00","0.30","705601.00","0.27","705599.00","0.25"
    "24000","705595.00","0.29","705601.00","0.26","705598.00","0.26"
    "32000","1023991.00","0.19","1024001.00","0.16","1023995.00","0.15"
    "44100","1411188.00","0.46","1411201.00","0.42","1411193.00","0.42"
    "48000","1535987.00","0.20","1536001.00","0.17","1535993.00","0.19"
    "88200","2822371.00","0.94","2822399.00","0.86","2822385.00","0.85"
    "96000","3071968.00","0.44","3071999.00","0.39","3071982.00","0.30"

Table:  **Audio Capture**

|

Graphics SGX/RGX Driver
-------------------------

Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am62xx_lp_sk-fs: Score","am62xx_sk-fs: Score","am62xxsip_sk-fs: Score"

    "Glmark2-DRM","35.00","40.00","38.00"
    "Glmark2-Wayland","217.00","238.00","230.00"

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

CPSW/CPSW2g/CPSW3g Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- CPSW3g: AM64x, AM62x, AM62ax, AM62px

.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xxsip_sk-fs: THROUGHPUT (Mbits/sec)","am62xxsip_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1764.41","67.11","1784.22","65.02","1788.42","64.54"

Table: **CPSW TCP Bidirectional Throughput**

.. rubric::  TCP Bidirectional Throughput Interrupt Pacing
   :name: CPSW2g-tcp-bidirectional-throughput-interrupt-pacing

.. csv-table::
    :header: "Command Used","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xxsip_sk-fs: THROUGHPUT (Mbits/sec)","am62xxsip_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1681.71","52.08","1701.46","49.02","1693.09","47.36"

Table: **CPSW TCP Bidirectional Throughput Interrupt Pacing**

.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am62xx_lp_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: Packets Per Second (kPPS)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_sk-fs: Packets Per Second (kPPS)","am62xx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xxsip_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xxsip_sk-fs: THROUGHPUT (Mbits/sec)","am62xxsip_sk-fs: Packets Per Second (kPPS)","am62xxsip_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","12.80","89.00","31.58","18.00","18.57","129.00","41.92","18.00","18.76","130.00","41.95"
    "128","82.00","76.25","116.00","41.45","82.00","83.20","127.00","41.48","82.00","83.40","127.00","41.47"
    "256","210.00","193.02","115.00","41.32","210.00","105.12","63.00","26.64","210.00","210.37","125.00","41.32"
    "1024","978.00","883.73","113.00","41.11","978.00","933.22","119.00","46.45","978.00","936.10","120.00","46.60"
    "1518","1472.00","954.17","81.00","37.26","1472.00","955.35","81.00","33.48","1472.00","955.81","81.00","32.63"

Table: **CPSW UDP Egress Throughput**

.. csv-table::
    :header: "Frame Size(bytes)","am62xx_lp_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: Packets Per Second (kPPS)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_sk-fs: Packets Per Second (kPPS)","am62xx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xxsip_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xxsip_sk-fs: THROUGHPUT (Mbits/sec)","am62xxsip_sk-fs: Packets Per Second (kPPS)","am62xxsip_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","3.20","22.00","25.04","18.00","1.71","12.00","13.17","18.00","8.55","59.00","27.42"
    "128","82.00","4.79","7.00","9.66","82.00","31.16","48.00","28.85","82.00","5.84","9.00","10.76"
    "256","210.00","29.90","18.00","19.82","210.00","80.96","48.00","30.11","210.00","99.61","59.00","31.65"
    "1024","978.00","12.52","2.00","3.69","978.00","83.72","11.00","15.54","978.00","936.64","120.00","41.88"
    "1518","1472.00","932.85","79.00","40.40","1472.00","920.50","78.00","38.46","1472.00","957.06","81.00","39.77"

Table: **CPSW UDP Ingress Throughput (0% loss)**

.. csv-table::
    :header: "Frame Size(bytes)","am62xx_lp_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: Packets Per Second (kPPS)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_lp_sk-fs: Packet Loss %","am62xx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_sk-fs: Packets Per Second (kPPS)","am62xx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_sk-fs: Packet Loss %","am62xxsip_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xxsip_sk-fs: THROUGHPUT (Mbits/sec)","am62xxsip_sk-fs: Packets Per Second (kPPS)","am62xxsip_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xxsip_sk-fs: Packet Loss %"

    "64","18.00","25.98","180.00","38.16","52.91","18.00","27.39","190.00","38.09","52.36","18.00","27.37","190.00","37.59","67.89"
    "128","82.00","97.62","149.00","38.39","0.01","82.00","124.48","190.00","40.19","48.12","82.00","125.02","191.00","40.57","64.11"
    "256","210.00","275.02","164.00","40.94","56.12","210.00","312.12","186.00","41.01","47.40","210.00","318.76","190.00","41.69","56.46"
    "1024","978.00","935.47","120.00","41.55","0.01","978.00","936.27","120.00","42.24","0.03","978.00","920.74","118.00","41.28","0.02"
    "1518","1472.00","932.85","79.00","40.40","0.00","1472.00","953.25","81.00","39.35","0.02","1472.00","938.86","80.00","38.99","0.02"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|

OSPI Flash Driver
-------------------------

AM62XX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

UBIFS
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Buffer size (bytes)","am62xx_sk-fs: Write UBIFS Throughput (Mbytes/sec)","am62xx_sk-fs: Write UBIFS CPU Load (%)","am62xx_sk-fs: Read UBIFS Throughput (Mbytes/sec)","am62xx_sk-fs: Read UBIFS CPU Load (%)"

    "102400","0.16 (min 0.12, max 0.26)","12.76 (min 12.15, max 13.22)","59.79","14.29"
    "262144","0.13 (min 0.10, max 0.18)","12.78 (min 12.05, max 14.24)","58.26","25.00"
    "524288","0.13 (min 0.10, max 0.18)","12.31 (min 11.79, max 12.96)","56.96","20.00"
    "1048576","0.13 (min 0.10, max 0.18)","12.22 (min 10.86, max 13.21)","57.03","20.00"

UBIFS
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Buffer size (bytes)","am62xxsip_sk-fs: Write UBIFS Throughput (Mbytes/sec)","am62xxsip_sk-fs: Write UBIFS CPU Load (%)","am62xxsip_sk-fs: Read UBIFS Throughput (Mbytes/sec)","am62xxsip_sk-fs: Read UBIFS CPU Load (%)"

    "102400","0.19 (min 0.13, max 0.31)","12.87 (min 12.02, max 13.51)","58.66","20.00"
    "262144","0.16 (min 0.11, max 0.20)","12.84 (min 12.07, max 13.18)","57.54","25.00"
    "524288","0.16 (min 0.11, max 0.20)","12.70 (min 11.25, max 13.79)","56.75","14.29"
    "1048576","0.16 (min 0.11, max 0.20)","12.87 (min 12.45, max 13.45)","56.55","20.00"

RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","am62xxsip_sk-fs: Raw Read Throughput (Mbytes/sec)"

    "50","135.13"

|

UBoot QSPI/OSPI Driver
-------------------------

AM62XX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","am62xxsip_sk-fs: Write Throughput (Kbytes/sec)","am62xxsip_sk-fs: Read Throughput (Kbytes/sec)"

    "400000","388.21","195047.62"
    "800000","390.00","240941.18"
    "1000000","390.90","268590.16"
    "2000000","385.63","284939.13"

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
    :header: "Buffer size (bytes)","am62xx_lp_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62xx_lp_sk-fs: Write EXT4 CPU Load (%)","am62xx_lp_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62xx_lp_sk-fs: Read EXT4 CPU Load (%)"

    "1m","57.40","1.58","175.00","2.39"
    "4m","57.60","1.14","175.00","1.85"
    "4k","51.70","20.37","56.60","19.88"
    "256k","57.30","1.73","174.00","2.82"

.. csv-table::
    :header: "Buffer size (bytes)","am62xxsip_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62xxsip_sk-fs: Write EXT4 CPU Load (%)","am62xxsip_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62xxsip_sk-fs: Read EXT4 CPU Load (%)"

    "1m","90.60","2.18","171.00","1.73"
    "4m","96.80","2.01","171.00","1.77"
    "4k","63.40","24.34","91.70","26.20"
    "256k","90.90","2.25","171.00","2.13"

|

UBoot EMMC Driver
-------------------------

AM62XX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","am62xx_sk-fs: Write Throughput (Kbytes/sec)","am62xx_sk-fs: Read Throughput (Kbytes/sec)"

    "2000000","57690.14","170666.67"
    "4000000","58150.84","173375.66"

.. csv-table::
    :header: "File size (bytes in hex)","am62xx_lp_sk-fs: Write Throughput (Kbytes/sec)","am62xx_lp_sk-fs: Read Throughput (Kbytes/sec)"

    "2000000","60907.06","170666.67"
    "4000000","61593.98","174297.87"

.. csv-table::
    :header: "File size (bytes in hex)","am62xxsip_sk-fs: Write Throughput (Kbytes/sec)","am62xxsip_sk-fs: Read Throughput (Kbytes/sec)"

    "2000000","98402.40","172463.16"
    "4000000","99750.38","175229.95"
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

    "1m","20.00","0.77","85.60","1.09"
    "4m","20.00","0.64","85.00","0.97"
    "4k","7.04","3.03","21.30","6.91"
    "256k","20.00","0.74","82.90","1.38"

.. csv-table::
    :header: "Buffer size (bytes)","am62xx_lp_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62xx_lp_sk-fs: Write EXT4 CPU Load (%)","am62xx_lp_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62xx_lp_sk-fs: Read EXT4 CPU Load (%)"

    "1m","14.00","0.65","84.50","1.16"
    "4m","17.40","0.53","84.60","0.98"
    "4k","3.28","1.95","15.40","5.59"
    "256k","12.90","0.66","82.60","1.24"

.. csv-table::
    :header: "Buffer size (bytes)","am62xxsip_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62xxsip_sk-fs: Write EXT4 CPU Load (%)","am62xxsip_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62xxsip_sk-fs: Read EXT4 CPU Load (%)"

    "1m","19.10","0.73","87.00","1.12"
    "4m","19.00","0.64","86.50","0.97"
    "4k","5.36","2.49","16.50","5.37"
    "256k","18.90","0.73","84.40","1.26"

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|

UBoot MMC/SD Driver
-------------------------

AM62XX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","am62xxsip_sk-fs: Write Throughput (Kbytes/sec)","am62xxsip_sk-fs: Read Throughput (Kbytes/sec)"

    "400000","24380.95","58514.29"
    "800000","20428.93","71859.65"
    "1000000","18450.45","80709.36"

|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am62xxsip_sk-fs: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","24663.38"
    "aes-128-cbc","16","466.56"
    "aes-128-cbc","16384","130635.09"
    "aes-128-cbc","256","7063.64"
    "aes-128-cbc","64","1860.91"
    "aes-128-cbc","8192","98405.03"
    "aes-128-ecb","1024","24689.32"
    "aes-128-ecb","16","483.56"
    "aes-128-ecb","16384","130940.93"
    "aes-128-ecb","256","7378.01"
    "aes-128-ecb","64","1928.58"
    "aes-128-ecb","8192","98680.83"
    "aes-192-cbc","1024","24661.67"
    "aes-192-cbc","16","464.09"
    "aes-192-cbc","16384","120056.49"
    "aes-192-cbc","256","7008.51"
    "aes-192-cbc","64","1852.25"
    "aes-192-cbc","8192","98096.47"
    "aes-192-ecb","1024","24688.98"
    "aes-192-ecb","16","481.90"
    "aes-192-ecb","16384","126424.41"
    "aes-192-ecb","256","7266.30"
    "aes-192-ecb","64","1933.27"
    "aes-192-ecb","8192","98410.50"
    "aes-256-cbc","1024","24650.75"
    "aes-256-cbc","16","467.16"
    "aes-256-cbc","16384","112377.86"
    "aes-256-cbc","256","6966.87"
    "aes-256-cbc","64","1848.64"
    "aes-256-cbc","8192","90603.52"
    "aes-256-ecb","1024","24663.04"
    "aes-256-ecb","16","482.38"
    "aes-256-ecb","16384","117041.83"
    "aes-256-ecb","256","7217.83"
    "aes-256-ecb","64","1925.93"
    "aes-256-ecb","8192","96594.60"
    "sha256","1024","32706.90"
    "sha256","16","571.74"
    "sha256","16384","271717.72"
    "sha256","256","8548.69"
    "sha256","64","2174.59"
    "sha256","8192","190261.93"
    "sha512","1024","24541.87"
    "sha512","16","539.64"
    "sha512","16384","68048.21"
    "sha512","256","7564.29"
    "sha512","64","2168.47"
    "sha512","8192","60377.77"

.. csv-table::
    :header: "Algorithm","am62xxsip_sk-fs: CPU Load"

    "aes-128-cbc","37.00"
    "aes-128-ecb","38.00"
    "aes-192-cbc","37.00"
    "aes-192-ecb","37.00"
    "aes-256-cbc","36.00"
    "aes-256-ecb","37.00"
    "sha256","98.00"
    "sha512","98.00"

Listed for each algorithm are the code snippets used to run each benchmark test.

::

    time -v openssl speed -elapsed -evp aes-128-cbc

IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am62xx_lp_sk-fs: Throughput (Mbps)","am62xx_lp_sk-fs: Packets/Sec","am62xx_lp_sk-fs: CPU Load","am62xx_sk-fs: Throughput (Mbps)","am62xx_sk-fs: Packets/Sec","am62xx_sk-fs: CPU Load","am62xxsip_sk-fs: Throughput (Mbps)","am62xxsip_sk-fs: Packets/Sec","am62xxsip_sk-fs: CPU Load"

    "3des","63.10","5.00","25.13","69.40","6.00","24.77","70.70","6.00","25.27"
    "aes128","261.30","23.00","46.94","279.20","24.00","47.14","281.20","25.00","47.24"
    "aes192","257.20","22.00","46.94","288.80","25.00","47.45","282.70","25.00","47.35"
    "aes256","288.90","25.00","47.43"
