.. http://processors.wiki.ti.com/index.php/CoreSDK_Linux_Kernel_Performance_Guide

======================================
 Linux 08.00.00 Performance Guide
======================================

.. rubric::  **Read This First**
   :name: read-this-first-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| AM335x         | AM335x Evaluation Module rev 1.5B with ARM running at 1000MHz, DDR3-400 (400MHz/800 MT/S), TMDXEVM3358         |
+----------------+----------------------------------------------------------------------------------------------------------------+
| AM437x-gpevm   | AM437x-gpevm Evaluation Module rev 1.5A with ARM running at 1000MHz, DDR3-400 (400MHz/800 MT/S), TMDSEVM437X   |
+----------------+----------------------------------------------------------------------------------------------------------------+
| AM572x EVM     | AM57xx Evaluation Module rev A2 with ARM running at 1500MHz, DDR3L-533 (533 MHz/1066 MT/S), TMDSEVM572x        |
+----------------+----------------------------------------------------------------------------------------------------------------+
| K2HK EVM       | K2 Hawkings Evaluation Module rev 40 with ARM running at 1200MHz, DDR3-1600 (800 MHz/1600 MT/S), EVMK2H        |
+----------------+----------------------------------------------------------------------------------------------------------------+
| K2G EVM        | K2 Galileo Evaluation Module rev C, DDR3-1333 (666 MHz/1333 MT/S), EVMK2G                                      |
+----------------+----------------------------------------------------------------------------------------------------------------+
| AM64x EVM      | AM64x Evaluation Module rev E1 with ARM running at 1GHz, DDR data rate 1600 MT/S                               |
+----------------+----------------------------------------------------------------------------------------------------------------+
| AM65x EVM      | AM65x Evaluation Module rev 1.0 with ARM running at 800MHz, DDR4-2400 (1600 MT/S), TMDX654GPEVM                |
+----------------+----------------------------------------------------------------------------------------------------------------+
| J721e EVM      | J721e Evaluation Module rev E2 with ARM running at 2GHz, DDR data rate 4266 MT/S, L3 Cache size 3MB            |
+----------------+----------------------------------------------------------------------------------------------------------------+
| J7200 EVM      | J7200 Evaluation Module rev E1 with ARM running at 2GHz, DDR data rate 2666 MT/S, L3 Cache size 3MB            |
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

**Bandwidth**: bw_mem_bcopy-N, where N is is equal to or smaller than the cache size at
a given level measures the achievable memory bandwidth from software doing
a memcpy() type operation. Typical use is for external memory bandwidth
calculation. The bandwidth is calculated as byte read and written counts
as 1 which should be roughly half of STREAM copy result.

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf","j7200-evm: perf","j721e-idk-gw: perf"

    "af_unix_sock_stream_latency (microsec)","43.65","18.88","19.42"
    "af_unix_socket_stream_bandwidth (MBs)","570.51","909.84","2595.97"
    "bw_file_rd-io-1mb (MB/s)","1026.48","2420.41","3718.16"
    "bw_file_rd-o2c-1mb (MB/s)","572.41","1003.18","1967.80"
    "bw_mem-bcopy-16mb (MB/s)","905.49","1112.58","2613.10"
    "bw_mem-bcopy-1mb (MB/s)","867.90","1137.23","5048.68"
    "bw_mem-bcopy-2mb (MB/s)","893.52","1115.86","3282.28"
    "bw_mem-bcopy-4mb (MB/s)","875.47","1115.45","3206.41"
    "bw_mem-bcopy-8mb (MB/s)","913.97","1113.59","2763.39"
    "bw_mem-bzero-16mb (MB/s)","2125.96","1140.58","10254.77"
    "bw_mem-bzero-1mb (MB/s)","1497.22 (min 867.90, max 2126.53)","1387.84 (min 1137.23, max 1638.45)","8858.24 (min 5048.68, max 12667.80)"
    "bw_mem-bzero-2mb (MB/s)","1509.46 (min 893.52, max 2125.40)","1147.64 (min 1115.86, max 1179.42)","7905.69 (min 3282.28, max 12529.09)"
    "bw_mem-bzero-4mb (MB/s)","1501.57 (min 875.47, max 2127.66)","1128.99 (min 1115.45, max 1142.53)","7840.21 (min 3206.41, max 12474.01)"
    "bw_mem-bzero-8mb (MB/s)","1519.97 (min 913.97, max 2125.96)","1127.49 (min 1113.59, max 1141.39)","7586.45 (min 2763.39, max 12409.51)"
    "bw_mem-cp-16mb (MB/s)","596.13","688.56","1080.72"
    "bw_mem-cp-1mb (MB/s)","1429.04 (min 581.90, max 2276.18)","1171.86 (min 704.97, max 1638.75)","6825.52 (min 981.51, max 12669.52)"
    "bw_mem-cp-2mb (MB/s)","1391.44 (min 585.48, max 2197.40)","933.47 (min 689.42, max 1177.51)","6782.77 (min 1040.94, max 12524.60)"
    "bw_mem-cp-4mb (MB/s)","1373.05 (min 579.63, max 2166.46)","916.39 (min 688.94, max 1143.84)","6846.16 (min 1222.12, max 12470.20)"
    "bw_mem-cp-8mb (MB/s)","1369.62 (min 588.11, max 2151.12)","914.70 (min 688.65, max 1140.74)","6727.97 (min 1067.24, max 12388.70)"
    "bw_mem-fcp-16mb (MB/s)","858.55","1194.74","2534.85"
    "bw_mem-fcp-1mb (MB/s)","1468.72 (min 810.90, max 2126.53)","1427.71 (min 1216.97, max 1638.45)","8835.63 (min 5003.45, max 12667.80)"
    "bw_mem-fcp-2mb (MB/s)","1480.70 (min 836.00, max 2125.40)","1186.28 (min 1179.42, max 1193.14)","7876.58 (min 3224.07, max 12529.09)"
    "bw_mem-fcp-4mb (MB/s)","1489.64 (min 851.61, max 2127.66)","1168.82 (min 1142.53, max 1195.10)","7824.62 (min 3175.23, max 12474.01)"
    "bw_mem-fcp-8mb (MB/s)","1489.88 (min 853.79, max 2125.96)","1168.16 (min 1141.39, max 1194.92)","7540.76 (min 2672.01, max 12409.51)"
    "bw_mem-frd-16mb (MB/s)","1483.13","5613.05","4867.66"
    "bw_mem-frd-1mb (MB/s)","1110.81 (min 810.90, max 1410.72)","3905.58 (min 1216.97, max 6594.19)","5469.09 (min 5003.45, max 5934.72)"
    "bw_mem-frd-2mb (MB/s)","1130.25 (min 836.00, max 1424.50)","3422.93 (min 1193.14, max 5652.71)","4544.59 (min 3224.07, max 5865.10)"
    "bw_mem-frd-4mb (MB/s)","1131.65 (min 851.61, max 1411.68)","3400.14 (min 1195.10, max 5605.18)","4393.65 (min 3175.23, max 5612.07)"
    "bw_mem-frd-8mb (MB/s)","1168.87 (min 853.79, max 1483.95)","3399.56 (min 1194.92, max 5604.20)","4063.59 (min 2672.01, max 5455.17)"
    "bw_mem-fwr-16mb (MB/s)","2137.89","1141.39","10251.48"
    "bw_mem-fwr-1mb (MB/s)","1843.45 (min 1410.72, max 2276.18)","4116.47 (min 1638.75, max 6594.19)","9302.12 (min 5934.72, max 12669.52)"
    "bw_mem-fwr-2mb (MB/s)","1810.95 (min 1424.50, max 2197.40)","3415.11 (min 1177.51, max 5652.71)","9194.85 (min 5865.10, max 12524.60)"
    "bw_mem-fwr-4mb (MB/s)","1789.07 (min 1411.68, max 2166.46)","3374.51 (min 1143.84, max 5605.18)","9041.14 (min 5612.07, max 12470.20)"
    "bw_mem-fwr-8mb (MB/s)","1817.54 (min 1483.95, max 2151.12)","3372.47 (min 1140.74, max 5604.20)","8921.94 (min 5455.17, max 12388.70)"
    "bw_mem-rd-16mb (MB/s)","1483.13","5104.48","5190.59"
    "bw_mem-rd-1mb (MB/s)","1157.11 (min 929.66, max 1384.56)","3646.07 (min 976.72, max 6315.41)","10997.91 (min 10294.64, max 11701.17)"
    "bw_mem-rd-2mb (MB/s)","1222.08 (min 984.57, max 1459.59)","2980.75 (min 760.46, max 5201.04)","4110.54 (min 1479.51, max 6741.57)"
    "bw_mem-rd-4mb (MB/s)","1270.80 (min 1066.67, max 1474.93)","2935.43 (min 765.55, max 5105.30)","3779.09 (min 1438.85, max 6119.33)"
    "bw_mem-rd-8mb (MB/s)","1282.85 (min 1096.19, max 1469.51)","2923.27 (min 742.87, max 5103.67)","3646.12 (min 1394.70, max 5897.53)"
    "bw_mem-rdwr-16mb (MB/s)","1091.03","745.16","1247.76"
    "bw_mem-rdwr-1mb (MB/s)","746.74 (min 581.90, max 911.58)","842.12 (min 704.97, max 979.27)","3812.40 (min 981.51, max 6643.29)"
    "bw_mem-rdwr-2mb (MB/s)","766.23 (min 585.48, max 946.97)","726.34 (min 689.42, max 763.26)","1183.71 (min 1040.94, max 1326.48)"
    "bw_mem-rdwr-4mb (MB/s)","773.32 (min 579.63, max 967.00)","718.72 (min 688.94, max 748.50)","1272.44 (min 1222.12, max 1322.75)"
    "bw_mem-rdwr-8mb (MB/s)","830.11 (min 588.11, max 1072.10)","718.30 (min 688.65, max 747.94)","1191.84 (min 1067.24, max 1316.44)"
    "bw_mem-wr-16mb (MB/s)","1107.88","742.53","1978.24"
    "bw_mem-wr-1mb (MB/s)","920.62 (min 911.58, max 929.66)","978.00 (min 976.72, max 979.27)","9172.23 (min 6643.29, max 11701.17)"
    "bw_mem-wr-2mb (MB/s)","965.77 (min 946.97, max 984.57)","761.86 (min 760.46, max 763.26)","1403.00 (min 1326.48, max 1479.51)"
    "bw_mem-wr-4mb (MB/s)","1016.84 (min 967.00, max 1066.67)","757.03 (min 748.50, max 765.55)","1380.80 (min 1322.75, max 1438.85)"
    "bw_mem-wr-8mb (MB/s)","1084.15 (min 1072.10, max 1096.19)","745.41 (min 742.87, max 747.94)","1355.57 (min 1316.44, max 1394.70)"
    "bw_mmap_rd-mo-1mb (MB/s)","1361.16","6372.91","8634.09"
    "bw_mmap_rd-o2c-1mb (MB/s)","646.73","1252.46","1896.09"
    "bw_pipe (MB/s)","735.25","1143.76","1738.40"
    "bw_unix (MB/s)","570.51","909.84","2595.97"
    "lat_connect (us)","63.88","29.97","27.57"
    "lat_ctx-2-128k (us)","30.46","9.40","3.98"
    "lat_ctx-2-256k (us)","78.06","22.16","4.24"
    "lat_ctx-4-128k (us)","52.44","20.47","5.51"
    "lat_ctx-4-256k (us)","62.81","26.38","6.09"
    "lat_fs-0k (num_files)","251.00","658.00","626.00"
    "lat_fs-10k (num_files)","92.00","76.00","211.00"
    "lat_fs-1k (num_files)","89.00","75.00","207.00"
    "lat_fs-4k (num_files)","83.00","69.00","203.00"
    "lat_mem_rd-stride128-sz1000k (ns)","42.72","18.59","8.70"
    "lat_mem_rd-stride128-sz125k (ns)","7.57","5.15","5.15"
    "lat_mem_rd-stride128-sz250k (ns)","8.16","5.15","5.15"
    "lat_mem_rd-stride128-sz31k (ns)","3.03","2.00","2.00"
    "lat_mem_rd-stride128-sz50 (ns)","3.01","2.00","2.00"
    "lat_mem_rd-stride128-sz500k (ns)","37.17","5.45","5.15"
    "lat_mem_rd-stride128-sz62k (ns)","6.41","5.15","5.15"
    "lat_mmap-1m (us)","22.00","8.87","9.09"
    "lat_ops-double-add (ns)","0.73","0.32","0.32"
    "lat_ops-double-mul (ns)","4.01","2.00","2.00"
    "lat_ops-float-add (ns)","0.73","0.32","0.32"
    "lat_ops-float-mul (ns)","4.01","2.00","2.00"
    "lat_ops-int-add (ns)","1.00","0.50","0.50"
    "lat_ops-int-bit (ns)","0.67","0.33","0.33"
    "lat_ops-int-div (ns)","6.01","4.00","4.00"
    "lat_ops-int-mod (ns)","6.35","4.67","4.67"
    "lat_ops-int-mul (ns)","3.04","1.52","1.52"
    "lat_ops-int64-add (ns)","1.00","0.50","0.50"
    "lat_ops-int64-bit (ns)","0.67","0.33","0.33"
    "lat_ops-int64-div (ns)","9.52","3.00","3.00"
    "lat_ops-int64-mod (ns)","7.35","5.67","5.67"
    "lat_pagefault (us)","2.54","1.25","1.16"
    "lat_pipe (us)","25.22","11.03","10.93"
    "lat_proc-exec (us)","2063.00","1415.80","719.25"
    "lat_proc-fork (us)","1721.33","1300.20","606.90"
    "lat_proc-proccall (us)","0.01","0.00","0.00"
    "lat_select (us)","46.28","9.42","9.49"
    "lat_sem (us)","2.59","1.27","1.43"
    "lat_sig-catch (us)","6.92","2.40","2.39"
    "lat_sig-install (us)","0.66","0.42","0.44"
    "lat_sig-prot (us)","0.57","0.23","0.34"
    "lat_syscall-fstat (us)","1.63","0.59","0.58"
    "lat_syscall-null (us)","0.42","0.27","0.27"
    "lat_syscall-open (us)","304.61","185.00","132.79"
    "lat_syscall-read (us)","0.77","0.35","0.37"
    "lat_syscall-stat (us)","4.47","1.50","1.43"
    "lat_syscall-write (us)","0.64","0.33","0.33"
    "lat_tcp (us)","0.84","0.55","0.57"
    "lat_unix (us)","43.65","18.88","19.42"
    "latency_for_0.50_mb_block_size (nanosec)","37.17","5.45","5.15"
    "latency_for_1.00_mb_block_size (nanosec)","21.36 (min 0.00, max 42.72)","9.29 (min 0.00, max 18.59)","4.35 (min 0.00, max 8.70)"
    "pipe_bandwidth (MBs)","735.25","1143.76","1738.40"
    "pipe_latency (microsec)","25.22","11.03","10.93"
    "procedure_call (microsec)","0.01","0.00","0.00"
    "select_on_200_tcp_fds (microsec)","46.28","9.42","9.49"
    "semaphore_latency (microsec)","2.59","1.27","1.43"
    "signal_handler_latency (microsec)","0.66","0.42","0.44"
    "signal_handler_overhead (microsec)","6.92","2.40","2.39"
    "tcp_ip_connection_cost_to_localhost (microsec)","63.88","29.97","27.57"
    "tcp_latency_using_localhost (microsec)","0.84","0.55","0.57"

Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.
  
.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf","j7200-evm: perf","j721e-idk-gw: perf"

    "cpu_clock (MHz)","1000.00","2000.00","2000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","3.00","5.7","5.7"
    "dhrystone_per_second (DhrystoneP)","5263158.00","20000000.00","20000000.00"

Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf","j7200-evm: perf","j721e-idk-gw: perf"

    "whetstone (MIPS)","3333.30","10000.00","10000.00"

Table:  **Whetstone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf","j7200-evm: perf","j721e-idk-gw: perf"

    "linpack (Kflops)","421501.00","2640010.00","2645095.00"

Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf","j7200-evm: perf","j721e-idk-gw: perf"

    "assignment (Iterations)","9.76","29.69","29.69"
    "fourier (Iterations)","16338.00","59221.00","49615.00"
    "fp_emulation (Iterations)","76.52","250.03","250.10"
    "huffman (Iterations)","838.70","2432.30","2430.70"
    "idea (Iterations)","2453.00","7997.20","7997.70"
    "lu_decomposition (Iterations)","403.53","1430.60","1431.60"
    "neural_net (Iterations)","5.61","27.34","27.34"
    "numeric_sort (Iterations)","360.90","879.34","879.45"
    "string_sort (Iterations)","118.40","418.78","429.64"

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
    :header: "Benchmarks","am64xx-evm: perf","j7200-evm: perf","j721e-idk-gw: perf"

    "add (MB/s)","1882.60","3866.60","5625.20"
    "copy (MB/s)","2023.00","3078.20","5945.10"
    "scale (MB/s)","2454.60","3107.60","5621.30"
    "triad (MB/s)","1915.70","3868.90","5528.70"

Table:  **Stream**

CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf","j7200-evm: perf","j721e-idk-gw: perf"

    "cjpeg-rose7-preset (workloads/)","30.03","82.64","83.33"
    "core (workloads/)","0.21","0.78","0.78"
    "coremark-pro ()","602.93","2278.76","2543.12"
    "linear_alg-mid-100x100-sp (workloads/)","10.49","82.37","82.64"
    "loops-all-mid-10k-sp (workloads/)","0.49","2.23","2.50"
    "nnet_test (workloads/)","0.78","3.67","3.67"
    "parser-125k (workloads/)","6.29","11.63","12.20"
    "radix2-big-64k (workloads/)","19.79","124.78","268.24"
    "sha-test (workloads/)","57.80","156.25","156.25"
    "zip-test (workloads/)","16.39","47.62","50.00"

Table:  **CoreMarkPro**

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf","j7200-evm: perf","j721e-idk-gw: perf"

    "cjpeg-rose7-preset (workloads/)","59.52","163.93","166.67"
    "core (workloads/)","0.43","1.55","1.56"
    "coremark-pro ()","1082.13","3262.58","4466.88"
    "linear_alg-mid-100x100-sp (workloads/)","20.94","162.87","164.47"
    "loops-all-mid-10k-sp (workloads/)","0.90","3.23","3.77"
    "nnet_test (workloads/)","1.55","7.34","7.37"
    "parser-125k (workloads/)","7.38","8.33","23.26"
    "radix2-big-64k (workloads/)","31.02","58.05","255.36"
    "sha-test (workloads/)","111.11","312.50","312.50"
    "zip-test (workloads/)","30.30","80.00","90.91"

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
    :header: "Benchmarks","am64xx-evm: perf","j7200-evm: perf","j721e-idk-gw: perf"

    "4m-check (workloads/)","343.83","785.42","1086.01"
    "4m-check-reassembly (workloads/)","83.68","122.70","234.74"
    "4m-check-reassembly-tcp (workloads/)","45.37","89.61","126.90"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","16.99","33.80","46.95"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","0.78","2.57","2.76"
    "4m-cmykw2 (workloads/)","90.99","305.81","321.54"
    "4m-cmykw2-rotatew2 (workloads/)","22.64","52.77","65.57"
    "4m-reassembly (workloads/)","82.99","125.95","243.31"
    "4m-rotatew2 (workloads/)","27.53","62.97","75.19"
    "4m-tcp-mixed (workloads/)","93.57","262.30","266.67"
    "4m-x264w2 (workloads/)","0.79","2.59","2.82"
    "empty-wld (workloads/)","1.00","",""
    "idct-4m (workloads/)","13.74","34.73","34.98"
    "idct-4mw1 (workloads/)","13.74","34.76","35.12"
    "ippktcheck-4m (workloads/)","344.50","783.45","1090.27"
    "ippktcheck-4mw1 (workloads/)","345.64","783.95","1088.38"
    "ipres-4m (workloads/)","74.07","146.92","208.91"
    "ipres-4mw1 (workloads/)","73.78","146.34","208.33"
    "md5-4m (workloads/)","20.18","35.56","51.95"
    "md5-4mw1 (workloads/)","19.76","35.45","53.05"
    "rgbcmyk-4m (workloads/)","45.76","163.13","164.34"
    "rgbcmyk-4mw1 (workloads/)","45.75","163.40","164.34"
    "rotate-4ms1 (workloads/)","19.52","52.03","57.08"
    "rotate-4ms1w1 (workloads/)","19.33","52.14","57.08"
    "rotate-4ms64 (workloads/)","19.52","51.87","57.54"
    "rotate-4ms64w1 (workloads/)","19.46","52.52","57.41"
    "x264-4mq (workloads/)","0.41","1.40","1.45"
    "x264-4mqw1 (workloads/)","0.41","1.41","1.44"

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

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","j721e-idk-gw: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","15.70 (min 15.57, max 15.82)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","6.99 (min 6.94, max 7.14)"

Table:  **Boot time MMC/SD**

Boot media: NAND
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Table:  **Boot time MMC/SD**

ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64

.. csv-table::
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "11025","352800.00","0.17"
    "16000","512000.00","0.11"
    "22050","705600.00","0.13"
    "24000","705600.00","0.29"
    "32000","1023999.00","0.16"
    "44100","1411199.00","0.20"
    "48000","1535999.00","0.22"
    "88200","2822395.00","0.92"
    "96000","3071994.00","0.35"

Table:  **Audio Capture**

|

.. csv-table::
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "11025","352945.00","0.08"
    "16000","512211.00","0.09"
    "22050","705891.00","0.27"
    "24000","705891.00","0.28"
    "32000","1024422.00","0.13"
    "44100","1411781.00","0.43"
    "48000","1536632.00","0.23"
    "88200","2823560.00","0.91"
    "96000","3073262.00","0.37"

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

.. csv-table::
    :header: "Benchmark","j721e-idk-gw: Score","j721e-idk-gw: Fps"

    " GFXBench 3.x gl_trex_off","1943.33","34.70"
    " GFXBench 4.x gl_4_off","425.87","7.21"
    " GFXBench 5.x gl_5_high_off","84.31","1.31"

Table:  **GFXBench**

Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","j721e-idk-gw: Score"

    "Glmark2-Wayland","1298.00"

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

Machine Learning
-------------------------

TensorFlow Lite
^^^^^^^^^^^^^^^^^^^^^^^^^^^
TensorFlow Lite https://www.tensorflow.org/lite/ is open source deep
learning runtime for on-device inference. Processor SDK supports
TensorFlow Lite execution on Cortex A cores on all Sitara devices.

The table below lists TensorFlow Lite performance benchmarks when running
several well-known models on Sitara devices. The benchmarking data are
obtained with the benchmark_model binary, which is released in the
TensorFlow Lite source package and included in Processor SDK Linux filesystem.

Table:  **TensorFlow Lite Performance**

|

TI Deep Learning
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Accelerates deep learning inference on C66x DSP cores and on
Embedded Vision Engine (EVE) subsystems.

Table:  **TIDL Performance**

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
    :header: "Command Used","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1019.78","98.22","1512.81","54.71","1843.63","61.06"

Table: **CPSW TCP Bidirectional Throughput**

|

.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","7.62","86.37","18.00","34.86","94.81","18.00","15.97","50.04"
    "128","82.00","34.27","85.92","82.00","126.46","82.15","82.00","73.69","50.05"
    "256","210.00","86.84","85.68","210.00","177.87","50.08","210.00","211.31","53.75"
    "512","466.00","544.90","62.94","466.00","607.19","58.20"
    "1024","978.00","392.03","85.39","978.00","885.91","54.02","978.00","926.24","49.95"
    "1518","1472.00","571.25","84.36","1472.00","956.99","42.83","1472.00","957.08","36.36"

Table: **CPSW UDP Egress Throughput**

|

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.73","8.13","18.00","1.40","4.75"
    "128","82.00","5.97","13.72","82.00","14.24","12.54"
    "256","210.00","17.30","17.95","210.00","45.53","11.51","210.00","21.17","6.54"
    "1024","978.00","82.15","18.72","978.00","114.23","11.17"
    "1518","1472.00","122.47","17.82","1472.00","37.68","1.92","1472.00","957.04","50.18"

Table: **CPSW UDP Ingress Throughput (0% loss)**

|

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","am64xx-evm: Packet Loss %","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j7200-evm: Packet Loss %","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: Packet Loss %"

    "64","18.00","4.66","51.06","76.00","18.00","45.11","70.33","0.40"
    "128","82.00","64.42","52.01","73.11","82.00","132.44","71.42","2.49"
    "256","210.00","156.88","54.50","73.76","210.00","552.93","79.56","14.99","210.00","486.15","73.93","0.59"
    "1024","978.00","752.12","65.72","19.71","978.00","439.51","55.92","53.07"
    "1518","1472.00","868.03","73.03","9.30","1472.00","949.51","63.65","0.04","1472.00","957.04","50.18","0.00"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|

CPSW5g/CPSW9g Virtual Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- CPSW5g: J7200
- CPSW9g: J721e

.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW9g-tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.1.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.1.1 -j -c -C -l 60 -t TCP_MAERTS","1789.37","68.46","1832.16","52.10"

Table: **CPSW9g Virtual Ethernet Driver - TCP Bidirectional Throughput**

|

.. rubric::  UDP Throughput 
   :name: CPSW9g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","39.66","96.38"
    "128","82.00","82.70","50.08"
    "256","210.00","205.35","48.11"
    "1024","978.00","936.63","50.29"
    "1518","1472.00","957.02","37.56"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Egress Throughput**

|

.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.66","5.19"
    "128","82.00","9.25","7.02"
    "256","210.00","29.57","10.18"
    "1518","1472.00","956.99","49.88"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Ingress Throughput (0% loss)**

|

.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: Packet Loss %"

    "64","18.00","52.00","73.01","0.53"
    "128","82.00","238.79","75.99","0.12"
    "256","210.00","635.78","80.36","4.70"
    "1518","1472.00","957.03","49.76","0.01"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Ingress Throughput (possible loss)**

|

CPSW Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput 
   :name: tcp-bidirectional-throughput

Table: **CPSW TCP Bidirectional Throughput**

.. rubric::  UDP Throughput
   :name: udp-throughput-0-loss

Table: **CPSW UDP Egress Throughput**

Table: **CPSW UDP Ingress Throughput (0% loss)**

Table: **CPSW UDP Ingress Throughput (possible loss)**

|

PCIe Driver
-------------------------

PCIe-ETH
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Table: **PCI Ethernet**

PCIe-EP
^^^^^^^^^^^^^^^^^^^^^^^^^^^

PCIe-NVMe-SSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

AM64xx-EVM
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","355.00","100.00","397.00","97.53"
    "4m","364.00","95.07","398.00","96.32"
    "4k","23.00","99.99","45.90","99.81"
    "256k","288.00","99.58","360.00","97.27"

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x1
- SSD being used: Lite-On Technology Corporation M8Pe Series NVMe SSD [14a4:22f1] (rev 01)

J721E-IDK-GW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","715.00","11.15","1526.00","4.01"
    "4m","723.00","10.92","1532.00","3.28"
    "4k","191.00","47.30","168.00","35.45"
    "256k","718.00","10.21","1480.00","7.44"

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY

J7200-EVM
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","814.00","17.40","1523.00","5.58"
    "4m","814.00","16.77","1522.00","4.98"
    "4k","150.00","49.34","148.00","37.86"
    "256k","818.00","20.96","1518.00","10.66"

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY

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

    "102400","0.19 (min 0.13, max 0.32)","45.17 (min 44.23, max 47.05)","28.52","20.00"
    "262144","0.16 (min 0.11, max 0.20)","45.49 (min 44.27, max 46.53)","28.22","13.33"
    "524288","0.16 (min 0.11, max 0.20)","46.30 (min 43.61, max 48.69)","28.17","18.75"
    "1048576","0.16 (min 0.11, max 0.20)","45.65 (min 44.11, max 46.77)","27.97","18.75"

RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","am64xx-evm: Raw Read Throughput (Mbytes/sec)"

    "50","36.23"

J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^

UBIFS
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write UBIFS Throughput (Mbytes/sec)","j721e-idk-gw: Write UBIFS CPU Load (%)","j721e-idk-gw: Read UBIFS Throughput (Mbytes/sec)","j721e-idk-gw: Read UBIFS CPU Load (%)"

    "102400","0.62 (min 0.49, max 1.11)","21.16 (min 19.54, max 22.97)","33.75","7.69"
    "262144","0.48 (min 0.36, max 0.54)","21.10 (min 19.67, max 22.76)","33.68","0.00"
    "524288","0.48 (min 0.36, max 0.54)","21.42 (min 20.11, max 22.93)","33.32","15.38"
    "1048576","0.47 (min 0.36, max 0.53)","20.78 (min 17.74, max 22.15)","33.36","0.00"

RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","j721e-idk-gw: Raw Read Throughput (Mbytes/sec)"

    "50","38.76"

J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","j7200-evm: Raw Read Throughput (Mbytes/sec)"

    "50","200.00"

QSPI Flash Driver
-------------------------

UBoot QSPI/OSPI Driver
-------------------------

J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","1616.42","37577.98"
    "800000","1617.69","39009.52"
    "1000000","1619.77","39863.75"
    "2000000","1620.01","40255.53"

J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","398.17","204800.00"
    "800000","397.81","248242.42"
    "1000000","399.77","277694.92"
    "2000000","397.07","300623.85"

SPI Flash Driver
-------------------------

UFS Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

|

UBoot UFS Driver
-------------------------
|

J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","93090.91","341333.33"
    "800000","103696.20","390095.24"
    "1000000","99296.97","564965.52"

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

    "4m","59.90","2.52","",""

|

UBoot EMMC Driver
-------------------------
|

J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "2000000","57893.99","303407.41"
    "4000000","58254.22","312076.19"

|

J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "2000000","59578.18","172463.16"
    "4000000","62534.35","177604.34"

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

    "1m","18.60","1.81","86.60","2.91"
    "4m","19.00","1.52","87.00","2.67"
    "4k","5.19","9.09","16.60","17.58"
    "256k","18.20","2.56","84.20","4.00"

|

J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","19.30","0.83","86.10","0.96"
    "4m","19.50","0.73","86.20","0.73"
    "4k","5.26","4.68","16.10","10.28"
    "256k","19.30","1.07","83.90","1.62"

|

J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","12.80","0.45","46.60","0.39"
    "4m","14.60","0.39","46.90","0.34"
    "4k","5.36","2.81","13.20","5.51"
    "256k","13.00","0.42","47.60","0.62"

|

|

|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|

UBoot MMC/SD Driver
-------------------------
| 

J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","18962.96","21787.23"
    "800000","21005.13","22692.52"
    "1000000","18788.99","23108.60"

J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","31751.94","80313.73"
    "800000","38824.64","85333.33"
    "1000000","23272.73","89530.05"

|
The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
|

|

|

|

|

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

**Setup** : Inateck ASM1153E USB hard disk is
connected to usb0 port. File read/write performance data on usb0 port is
captured.

|

AM64XX-EVM
"""""""""""""""""""""""""""""""
|

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","32.00","100.00","32.20","100.00"
    "4m","32.00","100.00","32.80","99.99"
    "256k","30.20","100.00","30.30","100.00"

|

J7200-EVM
"""""""""""""""""""""""""""""""
|

.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","38.80","2.50","38.80","1.62"
    "4m","38.90","2.59","38.90","1.46"
    "4k","21.60","19.55","21.80","15.93"
    "256k","37.90","3.87","38.00","2.69"

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
|

.. csv-table::
    :header: "Number of Blocks","am64xx-evm: Throughput (MB/sec)","j721e-idk-gw: Throughput (MB/sec)"

    "150","92.40","38.90"

Table: **USBDEVICE HIGHSPEED SLAVE READ THROUGHPUT**

|
|

.. csv-table::
    :header: "Number of Blocks","am64xx-evm: Throughput (MB/sec)","j721e-idk-gw: Throughput (MB/sec)"

    "150","92.10","38.40"

Table: **USBDEVICE HIGHSPEED SLAVE WRITE THROUGHPUT**

|
|

|
|

|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am64xx-evm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","25815.04"
    "aes-128-cbc","16","472.31"
    "aes-128-cbc","16384","167406.25"
    "aes-128-cbc","256","7574.02"
    "aes-128-cbc","64","1875.58"
    "aes-128-cbc","8192","124133.38"
    "aes-192-cbc","1024","25829.03"
    "aes-192-cbc","16","476.71"
    "aes-192-cbc","16384","154998.10"
    "aes-192-cbc","256","7637.25"
    "aes-192-cbc","64","1913.24"
    "aes-192-cbc","8192","114423.13"
    "aes-256-cbc","1024","26376.53"
    "aes-256-cbc","16","472.77"
    "aes-256-cbc","16384","142049.28"
    "aes-256-cbc","256","7483.99"
    "aes-256-cbc","64","1899.69"
    "aes-256-cbc","8192","109324.97"
    "des-cbc","1024","18670.93"
    "des-cbc","16","3973.90"
    "des-cbc","16384","19824.64"
    "des-cbc","256","15906.22"
    "des-cbc","64","9898.28"
    "des-cbc","8192","19693.57"
    "des3","1024","7847.25"
    "des3","16","3094.53"
    "des3","16384","8011.78"
    "des3","256","7308.03"
    "des3","64","5737.00"
    "des3","8192","8019.97"
    "md5","1024","36382.38"
    "md5","16","790.09"
    "md5","16384","111771.65"
    "md5","256","11495.59"
    "md5","64","3077.99"
    "md5","8192","98126.51"
    "sha1","1024","42932.22"
    "sha1","16","745.04"
    "sha1","16384","273279.66"
    "sha1","256","11590.31"
    "sha1","64","2960.64"
    "sha1","8192","201007.10"
    "sha224","1024","42985.81"
    "sha224","16","742.46"
    "sha224","16384","282503.85"
    "sha224","256","11595.69"
    "sha224","64","2956.52"
    "sha224","8192","205635.58"
    "sha256","1024","25647.79"
    "sha256","16","425.53"
    "sha256","16384","222079.66"
    "sha256","256","6759.00"
    "sha256","64","1709.42"
    "sha256","8192","147040.94"
    "sha384","1024","25643.01"
    "sha384","16","721.97"
    "sha384","16384","53493.76"
    "sha384","256","9588.48"
    "sha384","64","2865.02"
    "sha384","8192","49785.51"
    "sha512","1024","18319.02"
    "sha512","16","421.99"
    "sha512","16384","50642.94"
    "sha512","256","6016.60"
    "sha512","64","1679.74"
    "sha512","8192","45432.83"

|
|

.. csv-table::
    :header: "Algorithm","am64xx-evm: CPU Load"

    "aes-128-cbc","38.00"
    "aes-192-cbc","31.00"
    "aes-256-cbc","37.00"
    "des-cbc","98.00"
    "des3","98.00"
    "md5","98.00"
    "sha1","98.00"
    "sha224","98.00"
    "sha256","97.00"
    "sha384","98.00"
    "sha512","98.00"

-

|
| Listed for each algorithm are the code snippets used to run each
  benchmark test.

|

::

    time -v openssl speed -elapsed -evp aes-128-cbc

-

IPSec Hardware Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Note: queue\_len is set to 300 and software fallback threshold set to 9
to enable software support for optimal performance

IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","j7200-evm: Throughput (Mbps)","j7200-evm: Packets/Sec","j7200-evm: CPU Load","j721e-idk-gw: Throughput (Mbps)","j721e-idk-gw: Packets/Sec","j721e-idk-gw: CPU Load"

    "3des","148.80","13.00","32.04","183.60","16.00","29.11"
    "aes128","574.30","51.00","56.60","758.30","67.00","56.75"
    "aes192","579.20","51.00","56.51","750.30","66.00","56.28"
    "aes256","568.70","50.00","56.86","757.20","67.00","56.64"

DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.

Power Management
-------------------------

