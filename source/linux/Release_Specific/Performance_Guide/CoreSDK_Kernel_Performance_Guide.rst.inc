.. http://processors.wiki.ti.com/index.php/CoreSDK_Linux_Kernel_Performance_Guide


======================================
 Linux 08.04.00 Performance Guide
======================================

.. rubric::  **Read This First**
   :name: read-this-first-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| J721e EVM      | J721e Evaluation Module rev E2 with ARM running at 2GHz, DDR data rate 4266 MT/S, L3 Cache size 3MB            |
+----------------+----------------------------------------------------------------------------------------------------------------+
| J7200 EVM      | J7200 Evaluation Module rev E1 with ARM running at 2GHz, DDR data rate 2666 MT/S, L3 Cache size 3MB            |
+----------------+----------------------------------------------------------------------------------------------------------------+
| J721s2 EVM     | J721s2 Evaluation Module rev E2 with ARM running at 2GHz, DDR data rate 4266 MT/S, L3 Cache size 3MB           |
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
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "af_unix_sock_stream_latency (microsec)","20.00","20.12","19.18"
    "af_unix_socket_stream_bandwidth (MBs)","1587.90","3293.39","2837.74"
    "bw_file_rd-io-1mb (MB/s)","1691.76","2861.74","2687.21"
    "bw_file_rd-o2c-1mb (MB/s)","875.50","1458.26","1284.17"
    "bw_mem-bcopy-16mb (MB/s)","1513.15","2900.65","3387.68"
    "bw_mem-bcopy-1mb (MB/s)","1471.67","4712.71","4252.17"
    "bw_mem-bcopy-2mb (MB/s)","1441.70","4017.53","3545.40"
    "bw_mem-bcopy-4mb (MB/s)","1492.35","3903.20","3369.84"
    "bw_mem-bcopy-8mb (MB/s)","1523.52","3158.31","3377.90"
    "bw_mem-bzero-16mb (MB/s)","1140.58","9642.91","10490.08"
    "bw_mem-bzero-1mb (MB/s)","1555.06 (min 1471.67, max 1638.45)","8781.49 (min 4712.71, max 12850.26)","8760.04 (min 4252.17, max 13267.90)"
    "bw_mem-bzero-2mb (MB/s)","1310.82 (min 1179.94, max 1441.70)","8187.39 (min 4017.53, max 12357.24)","7525.53 (min 3545.40, max 11505.65)"
    "bw_mem-bzero-4mb (MB/s)","1315.57 (min 1138.79, max 1492.35)","7965.51 (min 3903.20, max 12027.81)","6992.98 (min 3369.84, max 10616.11)"
    "bw_mem-bzero-8mb (MB/s)","1331.97 (min 1140.41, max 1523.52)","7336.62 (min 3158.31, max 11514.93)","6932.40 (min 3377.90, max 10486.89)"
    "bw_mem-cp-16mb (MB/s)","966.77","1577.13","2101.67"
    "bw_mem-cp-1mb (MB/s)","1291.52 (min 942.80, max 1640.24)","7280.94 (min 1624.55, max 12937.32)","7834.72 (min 2326.48, max 13342.95)"
    "bw_mem-cp-2mb (MB/s)","1056.12 (min 929.51, max 1182.73)","6822.02 (min 1508.58, max 12135.45)","6831.85 (min 2145.16, max 11518.53)"
    "bw_mem-cp-4mb (MB/s)","1045.35 (min 950.12, max 1140.58)","6784.04 (min 1517.74, max 12050.33)","6355.27 (min 2096.44, max 10614.10)"
    "bw_mem-cp-8mb (MB/s)","1050.32 (min 959.58, max 1141.06)","6487.69 (min 1512.00, max 11463.37)","6322.74 (min 2084.42, max 10561.06)"
    "bw_mem-fcp-16mb (MB/s)","1535.07","3013.75","3231.34"
    "bw_mem-fcp-1mb (MB/s)","1560.11 (min 1481.76, max 1638.45)","8504.70 (min 4159.13, max 12850.26)","8625.62 (min 3983.34, max 13267.90)"
    "bw_mem-fcp-2mb (MB/s)","1307.54 (min 1179.94, max 1435.13)","8102.71 (min 3848.17, max 12357.24)","7440.43 (min 3375.21, max 11505.65)"
    "bw_mem-fcp-4mb (MB/s)","1319.30 (min 1138.79, max 1499.81)","7871.61 (min 3715.40, max 12027.81)","6919.14 (min 3222.17, max 10616.11)"
    "bw_mem-fcp-8mb (MB/s)","1337.96 (min 1140.41, max 1535.51)","7328.56 (min 3142.18, max 11514.93)","6862.23 (min 3237.56, max 10486.89)"
    "bw_mem-frd-16mb (MB/s)","5600.28","4785.40","4162.87"
    "bw_mem-frd-1mb (MB/s)","3780.71 (min 1481.76, max 6079.66)","4651.49 (min 4159.13, max 5143.84)","4478.35 (min 3983.34, max 4973.36)"
    "bw_mem-frd-2mb (MB/s)","3508.43 (min 1435.13, max 5581.72)","4782.25 (min 3848.17, max 5716.33)","3993.08 (min 3375.21, max 4610.95)"
    "bw_mem-frd-4mb (MB/s)","3531.55 (min 1499.81, max 5563.28)","4677.58 (min 3715.40, max 5639.76)","3712.30 (min 3222.17, max 4202.42)"
    "bw_mem-frd-8mb (MB/s)","3558.62 (min 1535.51, max 5581.72)","4232.88 (min 3142.18, max 5323.57)","3692.75 (min 3237.56, max 4147.94)"
    "bw_mem-fwr-16mb (MB/s)","1140.17","9628.40","10515.94"
    "bw_mem-fwr-1mb (MB/s)","3859.95 (min 1640.24, max 6079.66)","9040.58 (min 5143.84, max 12937.32)","9158.16 (min 4973.36, max 13342.95)"
    "bw_mem-fwr-2mb (MB/s)","3382.23 (min 1182.73, max 5581.72)","8925.89 (min 5716.33, max 12135.45)","8064.74 (min 4610.95, max 11518.53)"
    "bw_mem-fwr-4mb (MB/s)","3351.93 (min 1140.58, max 5563.28)","8845.05 (min 5639.76, max 12050.33)","7408.26 (min 4202.42, max 10614.10)"
    "bw_mem-fwr-8mb (MB/s)","3361.39 (min 1141.06, max 5581.72)","8393.47 (min 5323.57, max 11463.37)","7354.50 (min 4147.94, max 10561.06)"
    "bw_mem-rd-16mb (MB/s)","5083.40","5113.45","4885.50"
    "bw_mem-rd-1mb (MB/s)","3668.57 (min 1011.46, max 6325.68)","8463.89 (min 7975.69, max 8952.08)","10988.70 (min 7838.13, max 14139.27)"
    "bw_mem-rd-2mb (MB/s)","2963.24 (min 765.70, max 5160.78)","4213.60 (min 1836.21, max 6590.99)","4285.40 (min 2825.86, max 5744.93)"
    "bw_mem-rd-4mb (MB/s)","2906.91 (min 745.02, max 5068.79)","3838.77 (min 1323.85, max 6353.69)","3635.33 (min 2303.48, max 4967.18)"
    "bw_mem-rd-8mb (MB/s)","2883.13 (min 742.18, max 5024.07)","3555.88 (min 1287.21, max 5824.54)","3543.17 (min 2202.34, max 4884.00)"
    "bw_mem-rdwr-16mb (MB/s)","745.36","1821.70","2123.42"
    "bw_mem-rdwr-1mb (MB/s)","966.21 (min 942.80, max 989.61)","2851.51 (min 1624.55, max 4078.46)","4505.86 (min 2326.48, max 6685.24)"
    "bw_mem-rdwr-2mb (MB/s)","847.56 (min 765.60, max 929.51)","1380.17 (min 1251.76, max 1508.58)","2371.28 (min 2145.16, max 2597.40)"
    "bw_mem-rdwr-4mb (MB/s)","848.82 (min 747.52, max 950.12)","1495.25 (min 1472.75, max 1517.74)","2186.04 (min 2096.44, max 2275.64)"
    "bw_mem-rdwr-8mb (MB/s)","852.58 (min 745.57, max 959.58)","1934.03 (min 1512.00, max 2356.06)","2125.20 (min 2084.42, max 2165.97)"
    "bw_mem-wr-16mb (MB/s)","743.01","1780.55","2178.35"
    "bw_mem-wr-1mb (MB/s)","1000.54 (min 989.61, max 1011.46)","6027.08 (min 4078.46, max 7975.69)","10412.26 (min 6685.24, max 14139.27)"
    "bw_mem-wr-2mb (MB/s)","765.65 (min 765.60, max 765.70)","1543.99 (min 1251.76, max 1836.21)","2711.63 (min 2597.40, max 2825.86)"
    "bw_mem-wr-4mb (MB/s)","746.27 (min 745.02, max 747.52)","1398.30 (min 1323.85, max 1472.75)","2289.56 (min 2275.64, max 2303.48)"
    "bw_mem-wr-8mb (MB/s)","743.88 (min 742.18, max 745.57)","1821.64 (min 1287.21, max 2356.06)","2184.16 (min 2165.97, max 2202.34)"
    "bw_mmap_rd-mo-1mb (MB/s)","6219.90","8873.60","8298.76"
    "bw_mmap_rd-o2c-1mb (MB/s)","1223.35","1418.69","1268.58"
    "bw_pipe (MB/s)","617.88","921.27","899.69"
    "bw_unix (MB/s)","1587.90","3293.39","2837.74"
    "lat_connect (us)","47.92","38.94","40.00"
    "lat_ctx-2-128k (us)","3.04","2.83","2.69"
    "lat_ctx-2-256k (us)","10.72","2.58","2.46"
    "lat_ctx-4-128k (us)","5.02","3.18","3.19"
    "lat_ctx-4-256k (us)","3.68","2.33","2.40"
    "lat_fs-0k (num_files)","557.00","538.00","535.00"
    "lat_fs-10k (num_files)","163.00","218.00","187.00"
    "lat_fs-1k (num_files)","246.00","329.00","331.00"
    "lat_fs-4k (num_files)","284.00","351.00","348.00"
    "lat_mem_rd-stride128-sz1000k (ns)","17.41","12.53","12.98"
    "lat_mem_rd-stride128-sz125k (ns)","5.16","5.16","5.16"
    "lat_mem_rd-stride128-sz250k (ns)","5.17","5.16","5.16"
    "lat_mem_rd-stride128-sz31k (ns)","3.56","3.61","3.25"
    "lat_mem_rd-stride128-sz50 (ns)","2.00","2.00","2.00"
    "lat_mem_rd-stride128-sz500k (ns)","12.40","9.00","5.17"
    "lat_mem_rd-stride128-sz62k (ns)","4.77","4.97","5.16"
    "lat_mmap-1m (us)","20.00","21.00","27.00"
    "lat_ops-double-add (ns)","0.32","0.32","0.32"
    "lat_ops-double-mul (ns)","2.00","2.00","2.00"
    "lat_ops-float-add (ns)","0.32","0.32","0.32"
    "lat_ops-float-mul (ns)","2.00","2.00","2.00"
    "lat_ops-int-add (ns)","0.50","0.50","0.50"
    "lat_ops-int-bit (ns)","0.33","0.33","0.33"
    "lat_ops-int-div (ns)","4.01","4.00","4.00"
    "lat_ops-int-mod (ns)","4.67","4.67","4.67"
    "lat_ops-int-mul (ns)","1.52","1.52","1.52"
    "lat_ops-int64-add (ns)","0.50","0.50","0.50"
    "lat_ops-int64-bit (ns)","0.33","0.33","0.33"
    "lat_ops-int64-div (ns)","3.00","3.00","3.00"
    "lat_ops-int64-mod (ns)","5.68","5.67","5.67"
    "lat_pagefault (us)","0.60","0.46","0.47"
    "lat_pipe (us)","10.92","10.71","10.67"
    "lat_proc-exec (us)","791.00","481.18","532.20"
    "lat_proc-fork (us)","650.11","396.21","476.54"
    "lat_proc-proccall (us)","0.00","0.00","0.00"
    "lat_select (us)","11.86","11.80","11.78"
    "lat_sem (us)","1.47","1.26","1.38"
    "lat_sig-catch (us)","2.50","2.49","2.52"
    "lat_sig-install (us)","0.48","0.50","0.49"
    "lat_sig-prot (us)","0.51","0.46","0.43"
    "lat_syscall-fstat (us)","0.67","0.67","0.68"
    "lat_syscall-null (us)","0.34","0.35","0.34"
    "lat_syscall-open (us)","206.43","139.08","164.69"
    "lat_syscall-read (us)","0.44","0.44","0.46"
    "lat_syscall-stat (us)","1.70","1.77","1.76"
    "lat_syscall-write (us)","0.42","0.42","0.41"
    "lat_tcp (us)","0.70","0.72","0.69"
    "lat_unix (us)","20.00","20.12","19.18"
    "latency_for_0.50_mb_block_size (nanosec)","12.40","9.00","5.17"
    "latency_for_1.00_mb_block_size (nanosec)","8.71 (min 0.00, max 17.41)","6.26 (min 0.00, max 12.53)","6.49 (min 0.00, max 12.98)"
    "pipe_bandwidth (MBs)","617.88","921.27","899.69"
    "pipe_latency (microsec)","10.92","10.71","10.67"
    "procedure_call (microsec)","0.00","0.00","0.00"
    "select_on_200_tcp_fds (microsec)","11.86","11.80","11.78"
    "semaphore_latency (microsec)","1.47","1.26","1.38"
    "signal_handler_latency (microsec)","0.48","0.50","0.49"
    "signal_handler_overhead (microsec)","2.50","2.49","2.52"
    "tcp_ip_connection_cost_to_localhost (microsec)","47.92","38.94","40.00"
    "tcp_latency_using_localhost (microsec)","0.70","0.72","0.69"


Table:  **LM Bench Metrics**



Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.
  
.. csv-table::
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "cpu_clock (MHz)","2000.00","2000.00","2000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","5.20","5.70","5.70"
    "dhrystone_per_second (DhrystoneP)","18181818.00","20000000.00","20000000.00"


Table:  **Dhrystone Benchmark**



Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "whetstone (MIPS)","10000.00","10000.00","10000.00"


Table:  **Whetstone Benchmark**



Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "linpack (Kflops)","2383432.00","2548876.00","2625876.00"


Table:  **Linpack Benchmark**



NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html


.. csv-table::
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "assignment (Iterations)","29.65","29.70","29.68"
    "fourier (Iterations)","55155.00","53976.00","53743.00"
    "fp_emulation (Iterations)","250.00","250.08","250.08"
    "huffman (Iterations)","2428.60","2431.10","2425.30"
    "idea (Iterations)","7996.40","7996.70","7996.90"
    "lu_decomposition (Iterations)","1410.60","1430.70","1429.30"
    "neural_net (Iterations)","24.51","27.31","27.35"
    "numeric_sort (Iterations)","871.57","871.77","876.93"
    "string_sort (Iterations)","425.55","431.08","432.44"


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
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "add (MB/s)","3866.80","5368.80","6546.60"
    "copy (MB/s)","3075.40","5662.30","7790.90"
    "scale (MB/s)","3106.40","5452.00","7897.70"
    "triad (MB/s)","3873.70","5336.50","6542.70"


Table:  **Stream**



CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.


.. csv-table::
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "cjpeg-rose7-preset (workloads/)","82.64","82.64","81.97"
    "core (workloads/)","0.78","0.78","0.78"
    "coremark-pro ()","2239.09","2488.74","2476.52"
    "linear_alg-mid-100x100-sp (workloads/)","79.49","82.10","81.83"
    "loops-all-mid-10k-sp (workloads/)","2.22","2.41","2.48"
    "nnet_test (workloads/)","3.63","3.64","3.81"
    "parser-125k (workloads/)","10.64","11.90","11.90"
    "radix2-big-64k (workloads/)","126.39","248.39","233.81"
    "sha-test (workloads/)","158.73","158.73","158.73"
    "zip-test (workloads/)","45.45","47.62","45.45"


Table:  **CoreMarkPro**



.. csv-table::
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "cjpeg-rose7-preset (workloads/)","158.73","163.93","163.93"
    "core (workloads/)","1.55","1.55","1.54"
    "coremark-pro ()","3283.95","4405.67","4559.00"
    "linear_alg-mid-100x100-sp (workloads/)","161.29","160.26","162.87"
    "loops-all-mid-10k-sp (workloads/)","3.19","4.11","4.34"
    "nnet_test (workloads/)","7.54","7.26","7.60"
    "parser-125k (workloads/)","8.00","22.73","22.47"
    "radix2-big-64k (workloads/)","71.17","266.74","300.03"
    "sha-test (workloads/)","312.50","312.50","303.03"
    "zip-test (workloads/)","74.07","76.92","86.96"


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
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "4m-check (workloads/)","787.40","1012.56","958.59"
    "4m-check-reassembly (workloads/)","104.60","148.81","154.56"
    "4m-check-reassembly-tcp (workloads/)","79.87","98.04","95.79"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","33.02","45.80","43.01"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","2.55","2.75","2.70"
    "4m-cmykw2 (workloads/)","301.66","316.46","310.56"
    "4m-cmykw2-rotatew2 (workloads/)","51.41","61.79","59.94"
    "4m-reassembly (workloads/)","92.85","126.10","123.92"
    "4m-rotatew2 (workloads/)","53.85","74.35","70.97"
    "4m-tcp-mixed (workloads/)","262.30","258.07","250.00"
    "4m-x264w2 (workloads/)","2.64","2.79","2.76"
    "idct-4m (workloads/)","34.71","35.03","34.89"
    "idct-4mw1 (workloads/)","34.75","35.06","34.94"
    "ippktcheck-4m (workloads/)","783.70","1032.63","974.66"
    "ippktcheck-4mw1 (workloads/)","780.28","1036.91","972.76"
    "ipres-4m (workloads/)","141.51","202.98","185.41"
    "ipres-4mw1 (workloads/)","140.32","203.25","184.05"
    "md5-4m (workloads/)","39.92","51.23","48.22"
    "md5-4mw1 (workloads/)","39.67","51.65","48.57"
    "rgbcmyk-4m (workloads/)","161.94","163.27","162.08"
    "rgbcmyk-4mw1 (workloads/)","161.94","163.00","162.47"
    "rotate-4ms1 (workloads/)","50.30","56.56","53.08"
    "rotate-4ms1w1 (workloads/)","49.85","56.37","53.02"
    "rotate-4ms64 (workloads/)","50.51","56.88","53.76"
    "rotate-4ms64w1 (workloads/)","49.65","56.75","53.53"
    "x264-4mq (workloads/)","1.39","1.44","1.42"
    "x264-4mqw1 (workloads/)","1.41","1.44","1.42"


Table:  **Multibench**


 
 


Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","j7200-evm: boot time (sec)","j721e-idk-gw: boot time (sec)","j721s2-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","17.23 (min 17.16, max 17.36)","30.87 (min 29.69, max 31.72)","19.03 (min 18.83, max 19.22)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","4.23","8.92 (min 8.88, max 8.98)","4.54 (min 4.52, max 4.58)"

Table:  **Boot time MMC/SD**


 
 


ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64


.. csv-table::
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "11025","352800.00","0.27"
    "16000","512000.00","0.28"
    "22050","705600.00","0.29"
    "24000","705600.00","0.32"
    "32000","1023999.00","0.34"
    "44100","1411199.00","0.36"
    "48000","1535999.00","0.40"
    "88200","2822396.00","0.47"
    "96000","3071995.00","0.55"

Table:  **Audio Capture**


|


.. csv-table::
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "11025","352945.00","0.35"
    "16000","512211.00","0.28"
    "22050","705891.00","0.32"
    "24000","705891.00","0.28"
    "32000","1024422.00","0.33"
    "44100","1411781.00","0.68"
    "48000","1536632.00","0.40"
    "88200","2823560.00","1.09"
    "96000","3073263.00","0.55"

Table:  **Audio Playback**
 

|

 



 


Graphics SGX/RGX Driver
-------------------------
 


GFXBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Run GFXBench and capture performance reported (Score and Display rate in fps). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","j721e-idk-gw: Score","j721e-idk-gw: Fps","j721s2-evm: Score","j721s2-evm: Fps"

    " GFXBench 3.x gl_manhattan_off","1252.97","20.21"
    " GFXBench 3.x gl_trex_off","1921.94","34.32"
    " GFXBench 4.x gl_4_off","427.99","7.24","262.38","4.44"
    " GFXBench 5.x gl_5_high_off","181.59","2.82","116.30","1.81"


Table:  **GFXBench**



Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","j721s2-evm: Score"

    "Glmark2-DRM","9.00"
    "Glmark2-Wayland","1163.00"
    "Glmark2-Wayland test disable snoop filter","1138.00"


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





MPEG4
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Resolution","j721e-idk-gw: Fps","j721e-idk-gw: IVA Freq (MHz)","j721e-idk-gw: IPU Freq (MHz)"

    "CIF","30.00","",""
    "QVGA","30.00","",""
    "VGA","31.87","",""


Table:  **GStreamer MPEG4 in 3GP Container Decode Performance**
|




MPEG2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Resolution","j721e-idk-gw: Fps","j721e-idk-gw: IVA Freq (MHz)","j721e-idk-gw: IPU Freq (MHz)"

    "1080p","60.00","",""
    "720p","29.97","",""


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
    :header: "Command Used","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1354.28","58.72","1845.78","73.70","1858.12","71.73"

Table: **CPSW TCP Bidirectional Throughput**
|



.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","35.30","95.50","18.00","32.99","88.56","18.00","32.76","94.84"
    "128","82.00","156.79","95.36","82.00","147.81","86.40","82.00","149.83","95.26"
    "256","210.00","412.50","93.37","210.00","373.64","91.07"
    "512","466.00","875.11","78.32"
    "1024","978.00","914.96","63.95","978.00","932.23","52.72","978.00","904.15","56.89"
    "1518","1472.00","956.42","49.66","1472.00","956.92","35.29","1472.00","957.05","38.51"

Table: **CPSW UDP Egress Throughput**
|



.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","2.15","8.90","18.00","13.88","25.91","18.00","20.17","69.73"
    "128","82.00","173.05","58.66","82.00","112.07","72.10"
    "256","210.00","75.43","23.42","210.00","306.82","46.93","210.00","232.97","70.16"
    "1024","978.00","929.25","76.43","978.00","933.63","76.73"
    "1518","1472.00","949.91","60.60","1472.00","937.18","64.96"


Table: **CPSW UDP Ingress Throughput (0% loss)**

|



.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j7200-evm: Packet Loss %","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: Packet Loss %","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: Packet Loss %"

    "64","18.00","35.90","76.09","0.22","18.00","55.80","81.99","16.71","18.00","20.17","69.73","0.00"
    "128","82.00","251.96","85.01","11.66","82.00","112.07","72.10","0.00"
    "256","210.00","454.22","81.54","0.23","210.00","640.01","88.09","13.26","210.00","210.16","67.28","0.16"
    "1024","978.00","929.25","76.43","0.00","978.00","933.63","76.73","0.00"
    "1518","1472.00","949.91","60.60","0.00","1472.00","937.18","64.96","0.00"

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

    "netperf -H 192.168.1.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.1.1 -j -c -C -l 60 -t TCP_MAERTS","1870.31","79.20","1861.79","75.82"

Table: **CPSW9g Virtual Ethernet Driver - TCP Bidirectional Throughput**
|




.. rubric::  UDP Throughput 
   :name: CPSW9g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","26.58","79.75","18.00","26.41","79.22"
    "128","82.00","111.58","75.56","82.00","120.98","78.72"
    "256","210.00","238.60","66.34","210.00","319.42","79.89"
    "512","466.00","706.43","80.56"
    "1024","978.00","836.66","65.27","978.00","840.38","54.19"
    "1280","1234.00","938.46","50.30"
    "1518","1472.00","955.28","52.36","1472.00","956.74","46.25"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Egress Throughput**
|



.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.17","3.12","18.00","1.34","4.79"
    "128","82.00","6.63","6.38","82.00","6.04","2.99"
    "256","210.00","18.14","2.53","210.00","17.64","5.71"
    "512","466.00","44.36","4.57"
    "1024","978.00","83.71","9.60","978.00","146.30","13.96"
    "1280","1234.00","148.07","10.89"
    "1518","1472.00","143.66","9.76","1472.00","936.00","64.09"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Ingress Throughput(0% loss)**

|




.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j7200-evm: Packet Loss %","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: Packet Loss %"

    "64","18.00","37.46","73.12","40.21","18.00","42.63","72.20","28.81"
    "128","82.00","171.38","75.71","37.16","82.00","196.08","75.74","37.06"
    "256","210.00","419.88","76.02","40.26","210.00","497.61","77.55","28.68"
    "512","466.00","873.51","73.40","0.26"
    "1024","978.00","932.56","74.69","0.45","978.00","935.97","74.82","0.08"
    "1280","1234.00","844.10","68.85","11.07"
    "1518","1472.00","954.74","72.35","0.24","1472.00","956.84","65.35","0.02"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Ingress Throughput (possible loss)**

|
 
 

 
 


PCIe Driver
-------------------------

PCIe-ETH
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "TCP Window Size(Kbytes)","j721e-idk-gw: Bandwidth (Mbits/sec)"

    "128","0.00"
    "256","0.00"

Table: **PCI Ethernet**


 


PCIe-NVMe-SSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^
 

 


J721E-IDK-GW
"""""""""""""""""""""""""""




.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","443.00","10.93","1524.00","6.30"
    "4m","719.00","12.19","1523.00","5.42"
    "4k","193.00","47.90","167.00","35.60"
    "256k","719.00","11.91","1519.00","12.06"

 

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY
 


J7200-EVM
"""""""""""""""""""""""""""




.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","719.00","17.54","1532.00","10.75"
    "4m","717.00","16.20","1491.00","8.59"
    "4k","172.00","49.58","160.00","37.97"
    "256k","746.00","21.77","1530.00","16.39"

 

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY
 
 
 

 


OSPI Flash Driver
-------------------------

 

 


J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^


UBIFS
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write UBIFS Throughput (Mbytes/sec)","j721e-idk-gw: Write UBIFS CPU Load (%)","j721e-idk-gw: Read UBIFS Throughput (Mbytes/sec)","j721e-idk-gw: Read UBIFS CPU Load (%)"

    "102400","0.57 (min 0.45, max 1.02)","22.86 (min 20.60, max 23.98)","32.31","0.00"
    "262144","0.45 (min 0.35, max 0.48)","21.77 (min 20.93, max 22.34)","32.22","15.38"
    "524288","0.44 (min 0.34, max 0.48)","21.57 (min 21.06, max 22.59)","32.05","7.69"
    "1048576","0.41 (min 0.31, max 0.47)","22.56 (min 21.39, max 24.04)","31.78","7.69"




RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","j721e-idk-gw: Raw Read Throughput (Mbytes/sec)"

    "50","38.17"

 
 


J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^


UBIFS
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write UBIFS Throughput (Mbytes/sec)","j7200-evm: Write UBIFS CPU Load (%)","j7200-evm: Read UBIFS Throughput (Mbytes/sec)","j7200-evm: Read UBIFS CPU Load (%)"

    "102400","0.17 (min 0.12, max 0.27)","44.75 (min 44.35, max 45.55)","77.53","33.33"
    "262144","0.14 (min 0.11, max 0.18)","45.16 (min 44.93, max 45.44)","73.89","40.00"
    "524288","0.14 (min 0.11, max 0.18)","44.79 (min 44.36, max 45.39)","72.11","33.33"
    "1048576","0.14 (min 0.11, max 0.18)","44.99 (min 44.92, max 45.14)","73.07","33.33"




RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","j7200-evm: Raw Read Throughput (Mbytes/sec)"

    "50","192.31"

 
 

 

 
 

 


UBoot QSPI/OSPI Driver
-------------------------




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","1633.83","186181.82"
    "800000","1639.38","240941.18"
    "1000000","1640.37","277694.92"
    "2000000","1641.19","300623.85"





J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","358.48","204800.00"
    "800000","360.67","248242.42"
    "1000000","363.54","277694.92"
    "2000000","366.68","300623.85"

















 
 

 

 


UBoot UFS Driver
-------------------------
|


J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","93090.91","341333.33"
    "800000","85333.33","512000.00"
    "1000000","105025.64","528516.13"

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




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","57.70","1.40","175.00","1.09"
    "4m","55.20","1.26","172.00","0.86"
    "4k","51.10","21.31","56.30","20.41"
    "256k","57.70","1.54","174.00","1.86"

|


 

 

 

 











 
 


UBoot EMMC Driver
-------------------------
|


J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "2000000","55633.28","264258.06"
    "4000000","28895.94","322837.44"

|



J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "2000000","59041.44","174297.87"
    "4000000","58462.09","178086.96"

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

 





 








 

 


J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","13.00","1.11","88.70","2.03"
    "4m","15.50","0.92","89.90","1.64"
    "4k","5.19","5.36","15.30","10.12"
    "256k","12.70","1.40","86.80","2.59"

|




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","18.90","0.95","43.10","0.64"
    "4m","19.10","0.85","42.80","0.53"
    "4k","4.73","2.84","13.50","5.92"
    "256k","18.50","0.94","42.50","0.82"

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

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","15114.39","21787.23"
    "800000","14397.19","22755.56"
    "1000000","16616.63","23173.97"




J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","15226.77","77283.02"
    "800000","20029.34","86231.58"
    "1000000","18941.04","89530.05"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card


















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


















J721E-IDK-GW
"""""""""""""""""""""""""""""""
|

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","410.00","8.80","413.00","2.65"
    "4m","415.00","7.28","413.00","2.26"
    "4k","61.40","31.46","61.50","28.94"
    "256k","388.00","10.28","403.00","5.02"

|




 

|
 


USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^










.. csv-table::
    :header: "Number of Blocks","j721e-idk-gw: Throughput (MB/sec)","j721s2-evm: Throughput (MB/sec)"

    "150","39.60","31.10"

Table: **USBDEVICE HIGHSPEED SLAVE READ THROUGHPUT**

|
|



.. csv-table::
    :header: "Number of Blocks","j721e-idk-gw: Throughput (MB/sec)","j721s2-evm: Throughput (MB/sec)"

    "150","39.30","30.20"

Table: **USBDEVICE HIGHSPEED SLAVE WRITE THROUGHPUT**

|
|




 
 
 


CRYPTO Driver
-------------------------

 




IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","j721e-idk-gw: Throughput (Mbps)","j721e-idk-gw: Packets/Sec","j721e-idk-gw: CPU Load"

    "3des","115.20","10.00","21.34"
    "aes128","614.80","54.00","57.54"
    "aes192","455.90","40.00","57.62"
    "aes256","682.30","60.00","57.69"

 
 

DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.



