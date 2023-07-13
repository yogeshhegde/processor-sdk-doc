
======================================
 Linux 09.00.00 Performance Guide
======================================

.. rubric::  **Read This First**
   :name: read-this-first-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| AM64x EVM      | AM64x Evaluation Module rev E1 with ARM running at 1GHz, DDR data rate 1600 MT/S                               |
+----------------+----------------------------------------------------------------------------------------------------------------+
| AM62x SK       | AM62x Starter Kit rev E2 and E3 with ARM running at 1400 MHz, DDR4 data rate 1600 MT/S                         |
+----------------+----------------------------------------------------------------------------------------------------------------+
| AM62x SK LP    | AM62x LP Starter Kit rev E1 with ARM running at 1250 MHz, LPDDR4 data rate 1600 MT/S                           |
+----------------+----------------------------------------------------------------------------------------------------------------+
| AM62A SK       | AM62A Starter Kit rev E2 with ARM running at 1200MHz, LPDDR4 data rate 1866 MT/S				  |
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
    :header: "Benchmarks","am62axx_sk-fs: perf","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf"

    "af_unix_sock_stream_latency (microsec)","28.05","29.76","26.64"
    "af_unix_socket_stream_bandwidth (MBs)","1103.86","568.11","623.96"
    "bw_file_rd-io-1mb (MB/s)","1226.99","785.18","890.31"
    "bw_file_rd-o2c-1mb (MB/s)","736.24","428.94","517.42"
    "bw_mem-bcopy-16mb (MB/s)","1879.48","664.51","759.45"
    "bw_mem-bcopy-1mb (MB/s)","1945.15","722.28","816.46"
    "bw_mem-bcopy-2mb (MB/s)","1795.98","685.28","762.34"
    "bw_mem-bcopy-4mb (MB/s)","1849.85","688.71","768.05"
    "bw_mem-bcopy-8mb (MB/s)","1843.74","707.40","809.14"
    "bw_mem-bzero-16mb (MB/s)","7318.19","1686.52","1753.42"
    "bw_mem-bzero-1mb (MB/s)","4621.56 (min 1945.15, max 7297.97)","1194.89 (min 722.28, max 1667.50)","1272.99 (min 816.46, max 1729.51)"
    "bw_mem-bzero-2mb (MB/s)","4550.17 (min 1795.98, max 7304.35)","1177.09 (min 685.28, max 1668.89)","1247.27 (min 762.34, max 1732.20)"
    "bw_mem-bzero-4mb (MB/s)","4587.26 (min 1849.85, max 7324.67)","1180.01 (min 688.71, max 1671.31)","1251.83 (min 768.05, max 1735.61)"
    "bw_mem-bzero-8mb (MB/s)","4556.25 (min 1843.74, max 7268.76)","1199.73 (min 707.40, max 1692.05)","1280.04 (min 809.14, max 1750.93)"
    "bw_mem-cp-16mb (MB/s)","942.17","383.47","448.28"
    "bw_mem-cp-1mb (MB/s)","1232.92 (min 943.25, max 1522.59)","498.16 (min 379.99, max 616.33)","591.47 (min 441.24, max 741.70)"
    "bw_mem-cp-2mb (MB/s)","1172.16 (min 952.53, max 1391.79)","467.11 (min 371.47, max 562.75)","574.66 (min 446.83, max 702.49)"
    "bw_mem-cp-4mb (MB/s)","1172.96 (min 957.51, max 1388.41)","511.73 (min 402.33, max 621.12)","618.87 (min 471.75, max 765.99)"
    "bw_mem-cp-8mb (MB/s)","1191.57 (min 992.31, max 1390.82)","538.27 (min 417.28, max 659.25)","648.09 (min 497.14, max 799.04)"
    "bw_mem-fcp-16mb (MB/s)","1631.82","671.25","748.54"
    "bw_mem-fcp-1mb (MB/s)","4505.45 (min 1712.92, max 7297.97)","1214.05 (min 760.60, max 1667.50)","1295.42 (min 861.33, max 1729.51)"
    "bw_mem-fcp-2mb (MB/s)","4464.36 (min 1624.37, max 7304.35)","1199.01 (min 729.13, max 1668.89)","1307.60 (min 883.00, max 1732.20)"
    "bw_mem-fcp-4mb (MB/s)","4426.67 (min 1528.66, max 7324.67)","1210.75 (min 750.19, max 1671.31)","1318.46 (min 901.31, max 1735.61)"
    "bw_mem-fcp-8mb (MB/s)","4424.43 (min 1580.09, max 7268.76)","1226.80 (min 761.54, max 1692.05)","1319.71 (min 888.49, max 1750.93)"
    "bw_mem-frd-16mb (MB/s)","1907.49","1020.28","1131.38"
    "bw_mem-frd-1mb (MB/s)","1815.82 (min 1712.92, max 1918.72)","957.23 (min 760.60, max 1153.85)","1056.90 (min 861.33, max 1252.46)"
    "bw_mem-frd-2mb (MB/s)","1703.61 (min 1624.37, max 1782.85)","866.32 (min 729.13, max 1003.51)","983.12 (min 883.00, max 1083.23)"
    "bw_mem-frd-4mb (MB/s)","1681.06 (min 1528.66, max 1833.46)","881.75 (min 750.19, max 1013.30)","1011.35 (min 901.31, max 1121.39)"
    "bw_mem-frd-8mb (MB/s)","1657.54 (min 1580.09, max 1734.98)","891.82 (min 761.54, max 1022.10)","1006.52 (min 888.49, max 1124.54)"
    "bw_mem-fwr-16mb (MB/s)","1391.30","673.29","817.49"
    "bw_mem-fwr-1mb (MB/s)","1720.66 (min 1522.59, max 1918.72)","885.09 (min 616.33, max 1153.85)","997.08 (min 741.70, max 1252.46)"
    "bw_mem-fwr-2mb (MB/s)","1587.32 (min 1391.79, max 1782.85)","783.13 (min 562.75, max 1003.51)","892.86 (min 702.49, max 1083.23)"
    "bw_mem-fwr-4mb (MB/s)","1610.94 (min 1388.41, max 1833.46)","817.21 (min 621.12, max 1013.30)","943.69 (min 765.99, max 1121.39)"
    "bw_mem-fwr-8mb (MB/s)","1562.90 (min 1390.82, max 1734.98)","840.68 (min 659.25, max 1022.10)","961.79 (min 799.04, max 1124.54)"
    "bw_mem-rd-16mb (MB/s)","1980.20","1041.40","1143.43"
    "bw_mem-rd-1mb (MB/s)","1979.04 (min 1831.17, max 2126.91)","866.74 (min 560.15, max 1173.32)","1003.37 (min 698.81, max 1307.92)"
    "bw_mem-rd-2mb (MB/s)","1814.31 (min 1687.19, max 1941.43)","775.39 (min 518.07, max 1032.70)","885.45 (min 643.92, max 1126.97)"
    "bw_mem-rd-4mb (MB/s)","1838.14 (min 1694.44, max 1981.83)","799.35 (min 580.89, max 1017.81)","918.45 (min 709.35, max 1127.55)"
    "bw_mem-rd-8mb (MB/s)","1819.77 (min 1665.45, max 1974.09)","837.73 (min 645.99, max 1029.47)","962.47 (min 791.30, max 1133.63)"
    "bw_mem-rdwr-16mb (MB/s)","1666.67","682.74","847.86"
    "bw_mem-rdwr-1mb (MB/s)","1336.51 (min 943.25, max 1729.77)","463.22 (min 379.99, max 546.45)","565.33 (min 441.24, max 689.42)"
    "bw_mem-rdwr-2mb (MB/s)","1207.40 (min 952.53, max 1462.26)","442.94 (min 371.47, max 514.40)","536.90 (min 446.83, max 626.96)"
    "bw_mem-rdwr-4mb (MB/s)","1307.26 (min 957.51, max 1657.00)","473.02 (min 402.33, max 543.70)","587.80 (min 471.75, max 703.85)"
    "bw_mem-rdwr-8mb (MB/s)","1305.14 (min 992.31, max 1617.96)","523.08 (min 417.28, max 628.88)","629.45 (min 497.14, max 761.76)"
    "bw_mem-wr-16mb (MB/s)","1669.27","683.12","808.73"
    "bw_mem-wr-1mb (MB/s)","1780.47 (min 1729.77, max 1831.17)","553.30 (min 546.45, max 560.15)","694.12 (min 689.42, max 698.81)"
    "bw_mem-wr-2mb (MB/s)","1574.73 (min 1462.26, max 1687.19)","516.24 (min 514.40, max 518.07)","635.44 (min 626.96, max 643.92)"
    "bw_mem-wr-4mb (MB/s)","1675.72 (min 1657.00, max 1694.44)","562.30 (min 543.70, max 580.89)","706.60 (min 703.85, max 709.35)"
    "bw_mem-wr-8mb (MB/s)","1641.71 (min 1617.96, max 1665.45)","637.44 (min 628.88, max 645.99)","776.53 (min 761.76, max 791.30)"
    "bw_mmap_rd-mo-1mb (MB/s)","2104.52","1154.54","1288.90"
    "bw_mmap_rd-o2c-1mb (MB/s)","667.22","429.31","470.44"
    "bw_pipe (MB/s)","613.53","403.05","485.60"
    "bw_unix (MB/s)","1103.86","568.11","623.96"
    "lat_connect (us)","58.41","62.84","56.39"
    "lat_ctx-2-128k (us)","5.97","5.96","5.34"
    "lat_ctx-2-256k (us)","6.54","5.32","5.89"
    "lat_ctx-4-128k (us)","6.43","5.02","6.32"
    "lat_ctx-4-256k (us)","5.95","5.31","8.36"
    "lat_fs-0k (num_files)","258.00","212.00","246.00"
    "lat_fs-10k (num_files)","129.00","95.00","95.00"
    "lat_fs-1k (num_files)","184.00","142.00","158.00"
    "lat_fs-4k (num_files)","184.00","163.00","146.00"
    "lat_mem_rd-stride128-sz1000k (ns)","31.07","57.64","52.11"
    "lat_mem_rd-stride128-sz125k (ns)","6.30","6.23","5.56"
    "lat_mem_rd-stride128-sz250k (ns)","6.64","6.53","5.85"
    "lat_mem_rd-stride128-sz31k (ns)","4.10","4.09","4.66"
    "lat_mem_rd-stride128-sz50 (ns)","2.41","2.40","2.15"
    "lat_mem_rd-stride128-sz500k (ns)","13.65","16.84","14.44"
    "lat_mem_rd-stride128-sz62k (ns)","5.91","5.87","5.25"
    "lat_mmap-1m (us)","56.00","73.00","76.00"
    "lat_ops-double-add (ns)","3.22","3.20","2.86"
    "lat_ops-double-div (ns)","17.69","17.62","15.75"
    "lat_ops-double-mul (ns)","3.22","3.20","2.86"
    "lat_ops-float-add (ns)","3.22","3.21","2.86"
    "lat_ops-float-div (ns)","10.44","10.42","9.30"
    "lat_ops-float-mul (ns)","3.22","3.21","2.86"
    "lat_ops-int-add (ns)","0.80","0.80","0.72"
    "lat_ops-int-bit (ns)","0.54","0.53","0.48"
    "lat_ops-int-div (ns)","4.82","4.81","4.29"
    "lat_ops-int-mod (ns)","5.10","5.08","4.53"
    "lat_ops-int-mul (ns)","3.45","3.44","3.07"
    "lat_ops-int64-add (ns)","0.80","0.80","0.72"
    "lat_ops-int64-bit (ns)","0.54","0.53","0.48"
    "lat_ops-int64-div (ns)","7.63","7.61","6.80"
    "lat_ops-int64-mod (ns)","5.89","5.88","5.25"
    "lat_ops-int64-mul (ns)","3.98","3.98","3.55"
    "lat_pagefault (us)","1.47","1.70","1.52"
    "lat_pipe (us)","22.37","22.13","19.60"
    "lat_proc-exec (us)","958.33","1115.40","984.33"
    "lat_proc-fork (us)","744.14","897.14","776.14"
    "lat_proc-proccall (us)","0.01","0.01","0.01"
    "lat_select (us)","37.06","36.47","32.53"
    "lat_sem (us)","3.32","1.85","2.23"
    "lat_sig-catch (us)","6.05","6.01","5.40"
    "lat_sig-install (us)","0.74","0.73","0.66"
    "lat_sig-prot (us)","0.45","0.51","0.43"
    "lat_syscall-fstat (us)","3.02","3.00","2.67"
    "lat_syscall-null (us)","0.53","0.53","0.47"
    "lat_syscall-open (us)","132.97","2113.86","166.47"
    "lat_syscall-read (us)","0.86","0.85","0.76"
    "lat_syscall-stat (us)","4.32","4.20","3.73"
    "lat_syscall-write (us)","0.73","0.73","0.65"
    "lat_tcp (us)","1.03","1.03","0.92"
    "lat_unix (us)","28.05","29.76","26.64"
    "latency_for_0.50_mb_block_size (nanosec)","13.65","16.84","14.44"
    "latency_for_1.00_mb_block_size (nanosec)","15.53 (min 0.00, max 31.07)","28.82 (min 0.00, max 57.64)","26.06 (min 0.00, max 52.11)"
    "pipe_bandwidth (MBs)","613.53","403.05","485.60"
    "pipe_latency (microsec)","22.37","22.13","19.60"
    "procedure_call (microsec)","0.01","0.01","0.01"
    "select_on_200_tcp_fds (microsec)","37.06","36.47","32.53"
    "semaphore_latency (microsec)","3.32","1.85","2.23"
    "signal_handler_latency (microsec)","0.74","0.73","0.66"
    "signal_handler_overhead (microsec)","6.05","6.01","5.40"
    "tcp_ip_connection_cost_to_localhost (microsec)","58.41","62.84","56.39"
    "tcp_latency_using_localhost (microsec)","1.03","1.03","0.92"


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
    :header: "Benchmarks","am62axx_sk-fs: perf","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf"

    "cpu_clock (MHz)","1250.00","1250.00","1400.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.90","2.90","2.90"
    "dhrystone_per_second (DhrystoneP)","6451613.00","6451613.00","7142857.00"


Table:  **Dhrystone Benchmark**



Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Whetstone is a benchmark primarily measuring floating-point arithmetic performance.

Execute the benchmark with the following:

::

    runWhetstone

.. csv-table::
    :header: "Benchmarks","am62axx_sk-fs: perf","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf"

    "whetstone (MIPS)","5000.00","10000.00","10000.00"


Table:  **Whetstone Benchmark**



Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am62axx_sk-fs: perf","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf"

    "linpack (Kflops)","514704.00","517419.00","573082.00"


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

Execute the benchmark with the following:

::

    stream_c

.. csv-table::
    :header: "Benchmarks","am62axx_sk-fs: perf","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf"

    "add (MB/s)","2444.50","1451.30","1443.90"
    "copy (MB/s)","3488.90","1535.10","1650.80"
    "scale (MB/s)","3225.80","1666.60","1839.90"
    "triad (MB/s)","2235.80","1425.40","1494.50"


Table:  **Stream**



CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.


.. csv-table::
    :header: "Benchmarks","am62axx_sk-fs: perf","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf"

    "cjpeg-rose7-preset (workloads/)","36.50","37.45","41.67"
    "core (workloads/)","0.27","0.27","0.30"
    "coremark-pro ()","784.02","809.67","902.06"
    "linear_alg-mid-100x100-sp (workloads/)","13.03","13.11","14.69"
    "loops-all-mid-10k-sp (workloads/)","0.62","0.60","0.67"
    "nnet_test (workloads/)","0.97","0.97","1.09"
    "parser-125k (workloads/)","7.35","7.41","8.20"
    "radix2-big-64k (workloads/)","39.30","54.96","60.62"
    "sha-test (workloads/)","72.46","71.43","80.65"
    "zip-test (workloads/)","19.61","18.87","20.83"


Table:  **CoreMarkPro**



.. csv-table::
    :header: "Benchmarks","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf"

    "cjpeg-rose7-preset (workloads/)","74.07","81.97"
    "core (workloads/)","0.54","0.60"
    "coremark-pro ()","1332.23","1475.30"
    "linear_alg-mid-100x100-sp (workloads/)","26.21","29.34"
    "loops-all-mid-10k-sp (workloads/)","1.05","1.15"
    "nnet_test (workloads/)","1.94","2.18"
    "parser-125k (workloads/)","10.00","11.49"
    "radix2-big-64k (workloads/)","34.97","38.46"
    "sha-test (workloads/)","142.86","161.29"
    "zip-test (workloads/)","35.09","36.36"


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
    :header: "Benchmarks","am62axx_sk-fs: perf","am62xx_lp_sk-fs: perf","am62xx_sk-fs: perf"

    "4m-check (workloads/)","355.77","283.74","305.74"
    "4m-check-reassembly (workloads/)","112.36","62.07","66.53"
    "4m-check-reassembly-tcp (workloads/)","54.00","40.13","42.96"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","24.07","22.66","24.23"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.47","1.62","1.81"
    "4m-cmykw2 (workloads/)","161.81","173.46","200.60"
    "4m-cmykw2-rotatew2 (workloads/)","36.86","36.59","39.53"
    "4m-reassembly (workloads/)","81.04","49.55","53.59"
    "4m-rotatew2 (workloads/)","42.21","41.89","44.76"
    "4m-tcp-mixed (workloads/)","106.67","94.67","103.23"
    "4m-x264w2 (workloads/)","1.49","1.69","1.88"
    "empty-wld (workloads/)","","1.00","1.00"
    "idct-4m (workloads/)","17.13","16.82","18.60"
    "idct-4mw1 (workloads/)","17.13","16.83","18.60"
    "ippktcheck-4m (workloads/)","356.84","284.54","306.00"
    "ippktcheck-4mw1 (workloads/)","356.58","284.97","304.66"
    "ipres-4m (workloads/)","103.52","60.83","63.86"
    "ipres-4mw1 (workloads/)","103.73","61.70","64.66"
    "md5-4m (workloads/)","24.46","23.87","26.07"
    "md5-4mw1 (workloads/)","24.52","23.84","25.83"
    "rgbcmyk-4m (workloads/)","58.88","57.19","63.80"
    "rgbcmyk-4mw1 (workloads/)","58.77","57.18","64.10"
    "rotate-4ms1 (workloads/)","21.40","17.13","18.39"
    "rotate-4ms1w1 (workloads/)","21.21","17.09","18.41"
    "rotate-4ms64 (workloads/)","21.51","17.30","19.30"
    "rotate-4ms64w1 (workloads/)","21.41","17.27","18.51"
    "x264-4mq (workloads/)","0.51","0.50","0.56"
    "x264-4mqw1 (workloads/)","0.51","0.50","0.56"


Table:  **Multibench**










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
    :header: "Command Used","am62axx_sk-fs: THROUGHPUT (Mbits/sec)","am62axx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1855.62","85.03","1775.87","68.38","1796.57","64.14"

Table: **CPSW TCP Bidirectional Throughput**

|





.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am62xx_lp_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: Packets Per Second (kPPS)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_sk-fs: Packets Per Second (kPPS)","am62xx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","16.47","114.00","40.34","18.00","18.47","128.00","40.71"
    "128","82.00","71.91","110.00","41.52","82.00","81.16","124.00","40.28"
    "256","210.00","176.37","105.00","40.93","210.00","209.80","125.00","40.25"
    "1024","978.00","97.40","12.00","22.47","978.00","935.70","120.00","46.01"
    "1518","1472.00","955.10","81.00","41.21","1472.00","956.28","81.00","33.56"

Table: **CPSW UDP Egress Throughput**
|



.. csv-table::
    :header: "Frame Size(bytes)","am62xx_lp_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: Packets Per Second (kPPS)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_sk-fs: Packets Per Second (kPPS)","am62xx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","3.28","23.00","24.56","18.00","1.71","12.00","12.94"
    "128","82.00","5.44","8.00","9.74"
    "256","210.00","35.45","21.00","23.21","210.00","95.42","57.00","32.03"
    "1024","978.00","25.82","3.00","7.05","978.00","936.53","120.00","42.55"
    "1518","1472.00","956.78","81.00","43.81","1472.00","957.02","81.00","40.13"


Table: **CPSW UDP Ingress Throughput (0% loss)**

|



.. csv-table::
    :header: "Frame Size(bytes)","am62xx_lp_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_lp_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_lp_sk-fs: Packets Per Second (kPPS)","am62xx_lp_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_lp_sk-fs: Packet Loss %","am62xx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx_sk-fs: THROUGHPUT (Mbits/sec)","am62xx_sk-fs: Packets Per Second (kPPS)","am62xx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xx_sk-fs: Packet Loss %"

    "64","18.00","25.85","180.00","40.43","59.78","18.00","27.36","190.00","38.15","50.24"
    "128","82.00","97.63","149.00","41.08","0.36"
    "256","210.00","277.88","165.00","41.44","57.22","210.00","299.48","178.00","40.30","50.54"
    "1024","978.00","936.26","120.00","44.21","0.04","978.00","936.53","120.00","42.55","0.00"
    "1518","1472.00","956.78","81.00","43.81","0.00","1472.00","957.02","81.00","40.13","0.00"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|









IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am62axx_sk-fs: Throughput (Mbps)","am62axx_sk-fs: Packets/Sec","am62axx_sk-fs: CPU Load","am62xx_lp_sk-fs: Throughput (Mbps)","am62xx_lp_sk-fs: Packets/Sec","am62xx_lp_sk-fs: CPU Load","am62xx_sk-fs: Throughput (Mbps)","am62xx_sk-fs: Packets/Sec","am62xx_sk-fs: CPU Load"

    "3des","65.00","5.00","24.76","63.50","5.00","25.23","70.50","6.00","25.14"
    "aes128","371.40","33.00","49.15","232.60","20.00","25.21","272.50","24.00","47.11"
    "aes192","352.50","31.00","49.41","230.10","20.00","25.25","279.50","24.00","47.14"
    "aes256","0.00","0.00","75.96","231.70","20.00","25.30","243.20","21.00","25.16"



