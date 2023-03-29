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
| J721e EVM      | J721e Evaluation Module rev E2 with ARM running at 2GHz, DDR data rate 4266 MT/S, L3 Cache size 3MB            |
+----------------+----------------------------------------------------------------------------------------------------------------+
| J7200 EVM      | J7200 Evaluation Module rev E1 with ARM running at 2GHz, DDR data rate 2666 MT/S, L3 Cache size 3MB            |
+----------------+----------------------------------------------------------------------------------------------------------------+
| J721S2 EVM     | J721S2 Evaluation Module rev E2 with ARM running at 2GHz, DDR data rate 2666 MT/S, L3 Cache size 3MB           |
+----------------+----------------------------------------------------------------------------------------------------------------+
| J784S4 EVM     | J784S4 Evaluation Module Beta rev E1 with ARM running at 2GHz, DDR data rate 2666 MT/S, L3 Cache size 1MB      |
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
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j784s4-evm: perf"

    "af_unix_sock_stream_latency (microsec)","20.47","19.88","19.91","19.30"
    "af_unix_socket_stream_bandwidth (MBs)","2811.71","3054.68","3047.35","3650.94"
    "bw_file_rd-io-1mb (MB/s)","2182.97","2783.96","2539.45","3528.72"
    "bw_file_rd-o2c-1mb (MB/s)","1064.40","1488.93","1205.86","1447.44"
    "bw_mem-bcopy-16mb (MB/s)","2353.29","2861.23","3389.47","3575.02"
    "bw_mem-bcopy-1mb (MB/s)","3297.91","5326.97","4697.48","9316.77"
    "bw_mem-bcopy-2mb (MB/s)","2473.50","3954.13","3570.72","5129.14"
    "bw_mem-bcopy-4mb (MB/s)","2341.46","3917.73","3450.06","4493.54"
    "bw_mem-bcopy-8mb (MB/s)","2360.23","3129.07","3393.67","3765.89"
    "bw_mem-bzero-16mb (MB/s)","2343.29","9657.46","10521.12","10854.82"
    "bw_mem-bzero-1mb (MB/s)","4098.55 (min 3297.91, max 4899.19)","9189.22 (min 5326.97, max 13051.47)","8810.78 (min 4697.48, max 12924.07)","11539.95 (min 9316.77, max 13763.13)"
    "bw_mem-bzero-2mb (MB/s)","2693.42 (min 2473.50, max 2913.33)","8172.21 (min 3954.13, max 12390.29)","7542.41 (min 3570.72, max 11514.10)","9410.19 (min 5129.14, max 13691.23)"
    "bw_mem-bzero-4mb (MB/s)","2405.87 (min 2341.46, max 2470.28)","7987.50 (min 3917.73, max 12057.27)","7050.25 (min 3450.06, max 10650.44)","8769.26 (min 4493.54, max 13044.97)"
    "bw_mem-bzero-8mb (MB/s)","2355.21 (min 2350.18, max 2360.23)","7369.00 (min 3129.07, max 11608.92)","6979.98 (min 3393.67, max 10566.29)","7681.10 (min 3765.89, max 11596.30)"
    "bw_mem-cp-16mb (MB/s)","988.26","1576.04","2116.68","2503.91"
    "bw_mem-cp-1mb (MB/s)","3075.75 (min 1226.35, max 4925.14)","7365.23 (min 1715.27, max 13015.18)","7248.95 (min 2425.83, max 12072.07)","8785.62 (min 3837.02, max 13734.22)"
    "bw_mem-cp-2mb (MB/s)","1970.78 (min 1019.71, max 2921.84)","7037.70 (min 1615.51, max 12459.88)","6600.78 (min 1953.76, max 11247.80)","8306.61 (min 2902.23, max 13710.99)"
    "bw_mem-cp-4mb (MB/s)","1720.37 (min 981.47, max 2459.27)","6869.08 (min 1644.96, max 12093.19)","6379.47 (min 2111.19, max 10647.74)","8086.02 (min 2956.94, max 13215.09)"
    "bw_mem-cp-8mb (MB/s)","1668.40 (min 985.59, max 2351.21)","6564.73 (min 1533.15, max 11596.30)","6284.75 (min 2100.01, max 10469.49)","7100.68 (min 2581.89, max 11619.46)"
    "bw_mem-fcp-16mb (MB/s)","2402.40","2962.96","3244.78","3399.55"
    "bw_mem-fcp-1mb (MB/s)","4108.89 (min 3318.58, max 4899.19)","8745.90 (min 4440.33, max 13051.47)","8621.66 (min 4319.25, max 12924.07)","10806.07 (min 7849.00, max 13763.13)"
    "bw_mem-fcp-2mb (MB/s)","2710.92 (min 2508.51, max 2913.33)","8134.84 (min 3879.39, max 12390.29)","7411.77 (min 3309.43, max 11514.10)","9278.71 (min 4866.18, max 13691.23)"
    "bw_mem-fcp-4mb (MB/s)","2427.99 (min 2385.69, max 2470.28)","7915.43 (min 3773.58, max 12057.27)","6864.57 (min 3078.70, max 10650.44)","8690.90 (min 4336.83, max 13044.97)"
    "bw_mem-fcp-8mb (MB/s)","2375.03 (min 2350.18, max 2399.88)","7356.86 (min 3104.79, max 11608.92)","6902.36 (min 3238.43, max 10566.29)","7583.34 (min 3570.37, max 11596.30)"
    "bw_mem-frd-16mb (MB/s)","6299.21","4787.55","4175.91","4230.01"
    "bw_mem-frd-1mb (MB/s)","4687.37 (min 3318.58, max 6056.16)","5184.59 (min 4440.33, max 5928.85)","4568.19 (min 4319.25, max 4817.13)","7831.48 (min 7813.95, max 7849.00)"
    "bw_mem-frd-2mb (MB/s)","4453.12 (min 2508.51, max 6397.73)","4847.20 (min 3879.39, max 5815.01)","3985.27 (min 3309.43, max 4661.10)","4876.37 (min 4866.18, max 4886.56)"
    "bw_mem-frd-4mb (MB/s)","4346.80 (min 2385.69, max 6307.90)","4720.66 (min 3773.58, max 5667.73)","3649.06 (min 3078.70, max 4219.41)","4674.23 (min 4336.83, max 5011.63)"
    "bw_mem-frd-8mb (MB/s)","4343.98 (min 2399.88, max 6288.07)","4241.47 (min 3104.79, max 5378.15)","3709.08 (min 3238.43, max 4179.73)","4220.87 (min 3570.37, max 4871.37)"
    "bw_mem-fwr-16mb (MB/s)","2340.89","9660.38","10538.45","10880.65"
    "bw_mem-fwr-1mb (MB/s)","5490.65 (min 4925.14, max 6056.16)","9472.02 (min 5928.85, max 13015.18)","8444.60 (min 4817.13, max 12072.07)","10774.09 (min 7813.95, max 13734.22)"
    "bw_mem-fwr-2mb (MB/s)","4659.79 (min 2921.84, max 6397.73)","9137.45 (min 5815.01, max 12459.88)","7954.45 (min 4661.10, max 11247.80)","9298.78 (min 4886.56, max 13710.99)"
    "bw_mem-fwr-4mb (MB/s)","4383.59 (min 2459.27, max 6307.90)","8880.46 (min 5667.73, max 12093.19)","7433.58 (min 4219.41, max 10647.74)","9113.36 (min 5011.63, max 13215.09)"
    "bw_mem-fwr-8mb (MB/s)","4319.64 (min 2351.21, max 6288.07)","8487.23 (min 5378.15, max 11596.30)","7324.61 (min 4179.73, max 10469.49)","8245.42 (min 4871.37, max 11619.46)"
    "bw_mem-rd-16mb (MB/s)","6594.31","5098.79","4884.75","5106.93"
    "bw_mem-rd-1mb (MB/s)","6132.77 (min 2507.61, max 9757.93)","5561.84 (min 2814.42, max 8309.25)","7803.85 (min 6583.76, max 9023.94)","16458.77 (min 15616.49, max 17301.04)"
    "bw_mem-rd-2mb (MB/s)","4040.61 (min 994.04, max 7087.17)","4289.29 (min 2044.99, max 6533.58)","4421.94 (min 3082.26, max 5761.61)","6867.61 (min 5148.45, max 8586.76)"
    "bw_mem-rd-4mb (MB/s)","3720.64 (min 784.47, max 6656.80)","3807.43 (min 1404.74, max 6210.11)","3642.95 (min 2293.91, max 4991.98)","5231.61 (min 4379.56, max 6083.65)"
    "bw_mem-rd-8mb (MB/s)","3667.21 (min 745.71, max 6588.70)","3624.63 (min 1367.99, max 5881.27)","3555.62 (min 2214.53, max 4896.71)","5062.80 (min 4156.56, max 5969.04)"
    "bw_mem-rdwr-16mb (MB/s)","749.41","1868.07","2069.86","2893.83"
    "bw_mem-rdwr-1mb (MB/s)","2952.69 (min 1226.35, max 4679.02)","2396.89 (min 1715.27, max 3078.50)","3556.53 (min 2425.83, max 4687.22)","6707.09 (min 3837.02, max 9577.16)"
    "bw_mem-rdwr-2mb (MB/s)","1009.86 (min 1000.00, max 1019.71)","1449.30 (min 1283.08, max 1615.51)","2344.87 (min 1953.76, max 2735.98)","4063.45 (min 2902.23, max 5224.66)"
    "bw_mem-rdwr-4mb (MB/s)","887.41 (min 793.34, max 981.47)","2070.92 (min 1644.96, max 2496.88)","2176.46 (min 2111.19, max 2241.73)","3214.28 (min 2956.94, max 3471.62)"
    "bw_mem-rdwr-8mb (MB/s)","869.87 (min 754.15, max 985.59)","1997.16 (min 1533.15, max 2461.16)","2112.85 (min 2100.01, max 2125.68)","3095.73 (min 2581.89, max 3609.57)"
    "bw_mem-wr-16mb (MB/s)","742.18","1858.74","2201.43","3150.85"
    "bw_mem-wr-1mb (MB/s)","3593.32 (min 2507.61, max 4679.02)","2946.46 (min 2814.42, max 3078.50)","5635.49 (min 4687.22, max 6583.76)","13439.10 (min 9577.16, max 17301.04)"
    "bw_mem-wr-2mb (MB/s)","997.02 (min 994.04, max 1000.00)","1664.04 (min 1283.08, max 2044.99)","2909.12 (min 2735.98, max 3082.26)","5186.56 (min 5148.45, max 5224.66)"
    "bw_mem-wr-4mb (MB/s)","788.91 (min 784.47, max 793.34)","1950.81 (min 1404.74, max 2496.88)","2267.82 (min 2241.73, max 2293.91)","3925.59 (min 3471.62, max 4379.56)"
    "bw_mem-wr-8mb (MB/s)","749.93 (min 745.71, max 754.15)","1914.58 (min 1367.99, max 2461.16)","2170.11 (min 2125.68, max 2214.53)","3883.07 (min 3609.57, max 4156.56)"
    "bw_mmap_rd-mo-1mb (MB/s)","8532.74","8877.98","8992.48","12942.03"
    "bw_mmap_rd-o2c-1mb (MB/s)","1379.85","1586.46","1260.58","1725.13"
    "bw_pipe (MB/s)","741.34","943.63","917.57","975.15"
    "bw_unix (MB/s)","2811.71","3054.68","3047.35","3650.94"
    "lat_connect (us)","42.87","41.74","43.66","42.11"
    "lat_ctx-2-128k (us)","2.78","2.96","2.84","2.70"
    "lat_ctx-2-256k (us)","2.13","2.15","2.16","1.81"
    "lat_ctx-4-128k (us)","3.04","2.94","3.01","2.11"
    "lat_ctx-4-256k (us)","1.79","1.87","1.89","0.72"
    "lat_fs-0k (num_files)","617.00","507.00","493.00","541.00"
    "lat_fs-10k (num_files)","184.00","180.00","189.00","241.00"
    "lat_fs-1k (num_files)","293.00","312.00","307.00","329.00"
    "lat_fs-4k (num_files)","306.00","332.00","327.00","326.00"
    "lat_mem_rd-stride128-sz1000k (ns)","11.66","12.70","14.32","6.61"
    "lat_mem_rd-stride128-sz125k (ns)","5.57","5.57","5.57","5.65"
    "lat_mem_rd-stride128-sz250k (ns)","5.57","5.57","5.57","5.65"
    "lat_mem_rd-stride128-sz31k (ns)","5.12","3.34","3.36","3.38"
    "lat_mem_rd-stride128-sz50 (ns)","2.00","2.00","2.00","2.00"
    "lat_mem_rd-stride128-sz500k (ns)","5.57","5.58","5.69","5.65"
    "lat_mem_rd-stride128-sz62k (ns)","5.57","5.12","5.57","5.42"
    "lat_mmap-1m (us)","22.00","28.00","22.00","21.00"
    "lat_ops-double-add (ns)","0.32","0.32","0.32","0.32"
    "lat_ops-double-mul (ns)","2.00","2.00","2.00","2.00"
    "lat_ops-float-add (ns)","0.32","0.32","0.32","0.32"
    "lat_ops-float-mul (ns)","2.00","2.00","2.00","2.00"
    "lat_ops-int-add (ns)","0.50","0.50","0.50","0.50"
    "lat_ops-int-bit (ns)","0.33","0.33","0.33","0.33"
    "lat_ops-int-div (ns)","4.00","4.00","4.01","4.00"
    "lat_ops-int-mod (ns)","4.67","4.67","4.67","4.67"
    "lat_ops-int-mul (ns)","1.52","1.52","1.52","1.52"
    "lat_ops-int64-add (ns)","0.50","0.50","0.50","0.50"
    "lat_ops-int64-bit (ns)","0.33","0.33","0.33","0.33"
    "lat_ops-int64-div (ns)","3.00","3.00","3.00","3.00"
    "lat_ops-int64-mod (ns)","5.67","5.67","5.68","5.68"
    "lat_pagefault (us)","0.50","0.46","0.48","0.47"
    "lat_pipe (us)","10.89","10.96","10.88","10.66"
    "lat_proc-exec (us)","518.30","493.20","525.70","485.09"
    "lat_proc-fork (us)","458.75","403.69","456.45","443.00"
    "lat_proc-proccall (us)","0.00","0.00","0.00","0.00"
    "lat_select (us)","10.16","10.18","10.13","13.17"
    "lat_sem (us)","1.47","1.30","1.31","2.07"
    "lat_sig-catch (us)","2.53","2.54","2.60","2.24"
    "lat_sig-install (us)","0.49","0.50","0.49","0.49"
    "lat_sig-prot (us)","0.27","0.27","0.28","0.50"
    "lat_syscall-fstat (us)","0.70","0.69","0.68","0.69"
    "lat_syscall-null (us)","0.33","0.35","0.33","0.34"
    "lat_syscall-open (us)","151.03","143.16","127.65","499.45"
    "lat_syscall-read (us)","0.42","0.42","0.44","0.46"
    "lat_syscall-stat (us)","1.43","1.44","1.40","1.57"
    "lat_syscall-write (us)","0.41","0.41","0.42","0.41"
    "lat_tcp (us)","0.72","0.71","0.72","0.71"
    "lat_unix (us)","20.47","19.88","19.91","19.30"
    "latency_for_0.50_mb_block_size (nanosec)","5.57","5.58","5.69","5.65"
    "latency_for_1.00_mb_block_size (nanosec)","5.83 (min 0.00, max 11.66)","6.35 (min 0.00, max 12.70)","7.16 (min 0.00, max 14.32)","3.31 (min 0.00, max 6.61)"
    "pipe_bandwidth (MBs)","741.34","943.63","917.57","975.15"
    "pipe_latency (microsec)","10.89","10.96","10.88","10.66"
    "procedure_call (microsec)","0.00","0.00","0.00","0.00"
    "select_on_200_tcp_fds (microsec)","10.16","10.18","10.13","13.17"
    "semaphore_latency (microsec)","1.47","1.30","1.31","2.07"
    "signal_handler_latency (microsec)","0.49","0.50","0.49","0.49"
    "signal_handler_overhead (microsec)","2.53","2.54","2.60","2.24"
    "tcp_ip_connection_cost_to_localhost (microsec)","42.87","41.74","43.66","42.11"
    "tcp_latency_using_localhost (microsec)","0.72","0.71","0.72","0.71"


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
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j784s4-evm: perf"

    "cpu_clock (MHz)","2000.00","2000.00","2000.00","2000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","5.70","5.70","5.70","5.20"
    "dhrystone_per_second (DhrystoneP)","20000000.00","20000000.00","20000000.00","18181818.00"


Table:  **Dhrystone Benchmark**



Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Whetstone is a benchmark primarily measuring floating-point arithmetic performance.

Execute the benchmark with the following:

::

    runWhetstone

.. csv-table::
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j784s4-evm: perf"

    "whetstone (MIPS)","10000.00","10000.00","10000.00","10000.00"


Table:  **Whetstone Benchmark**



Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j784s4-evm: perf"

    "linpack (Kflops)","2362114.00","2588265.00","2536634.00","2589241.00"


Table:  **Linpack Benchmark**



NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html


.. csv-table::
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j784s4-evm: perf"

    "assignment (Iterations)","29.59","29.64","29.59","29.57"
    "fourier (Iterations)","55895.00","55485.00","59224.00","55162.00"
    "fp_emulation (Iterations)","250.10","250.04","250.06","250.02"
    "huffman (Iterations)","2422.60","2425.30","2422.90","2423.80"
    "idea (Iterations)","7996.60","7997.10","7996.50","7997.20"
    "lu_decomposition (Iterations)","1384.80","1399.10","1398.80","1379.00"
    "neural_net (Iterations)","26.69","27.32","27.00","26.87"
    "numeric_sort (Iterations)","860.09","861.28","872.70","864.55"
    "string_sort (Iterations)","431.65","427.17","429.38","417.31"


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
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j784s4-evm: perf"

    "add (MB/s)","3070.60","5402.70","6367.20","6281.20"
    "copy (MB/s)","3188.50","5648.50","7066.80","6737.10"
    "scale (MB/s)","3117.70","5523.00","7180.10","6726.90"
    "triad (MB/s)","3088.60","5357.40","6372.70","6268.30"


Table:  **Stream**



CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.


.. csv-table::
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j784s4-evm: perf"

    "cjpeg-rose7-preset (workloads/)","54.95","82.64","82.64","82.64"
    "core (workloads/)","0.78","0.78","0.78","0.78"
    "coremark-pro ()","1711.88","2486.71","2459.36","2494.70"
    "linear_alg-mid-100x100-sp (workloads/)","60.10","81.83","78.99","81.30"
    "loops-all-mid-10k-sp (workloads/)","1.80","2.44","2.47","2.45"
    "nnet_test (workloads/)","2.83","3.84","3.63","3.62"
    "parser-125k (workloads/)","10.00","11.24","11.11","10.99"
    "radix2-big-64k (workloads/)","82.41","245.22","243.13","274.50"
    "sha-test (workloads/)","158.73","158.73","158.73","158.73"
    "zip-test (workloads/)","20.83","47.62","47.62","47.62"


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
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j784s4-evm: perf"

    "4m-check (workloads/)","1008.88","1031.78","959.33","1035.63"
    "4m-check-reassembly (workloads/)","120.19","148.81","155.28","206.61"
    "4m-check-reassembly-tcp (workloads/)","88.97","100.81","97.28","114.68"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","40.76","45.73","42.11","63.09"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","2.68","2.73","2.71","4.86"
    "4m-cmykw2 (workloads/)","310.08","313.97","309.12","613.50"
    "4m-cmykw2-rotatew2 (workloads/)","58.82","61.73","58.54","108.70"
    "4m-reassembly (workloads/)","103.31","132.10","122.40","148.37"
    "4m-rotatew2 (workloads/)","71.28","74.52","70.57","43.22"
    "4m-tcp-mixed (workloads/)","271.19","258.07","266.67","238.81"
    "4m-x264w2 (workloads/)","2.77","2.77","2.76","4.98"
    "idct-4m (workloads/)","34.86","35.06","34.94","35.12"
    "idct-4mw1 (workloads/)","34.87","35.03","34.88","35.11"
    "ippktcheck-4m (workloads/)","1039.07","1022.91","946.97","1032.20"
    "ippktcheck-4mw1 (workloads/)","1008.88","1030.50","948.77","1031.35"
    "ipres-4m (workloads/)","166.11","201.88","183.37","210.67"
    "ipres-4mw1 (workloads/)","165.75","205.48","186.10","212.77"
    "md5-4m (workloads/)","48.43","50.97","48.69","46.36"
    "md5-4mw1 (workloads/)","47.89","51.31","47.62","47.35"
    "rgbcmyk-4m (workloads/)","162.60","163.13","162.60","164.07"
    "rgbcmyk-4mw1 (workloads/)","162.87","163.13","162.60","163.80"
    "rotate-4ms1 (workloads/)","52.36","55.13","52.25","55.25"
    "rotate-4ms1w1 (workloads/)","52.25","55.49","51.76","55.07"
    "rotate-4ms64 (workloads/)","52.74","56.05","52.52","55.68"
    "rotate-4ms64w1 (workloads/)","52.97","55.43","52.30","55.74"
    "x264-4mq (workloads/)","1.42","1.42","1.43","1.43"
    "x264-4mqw1 (workloads/)","1.42","1.44","1.42","1.44"


Table:  **Multibench**


 
 


Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","j7200-evm: boot time (sec)","j721e-idk-gw: boot time (sec)","j721s2-evm: boot time (sec)","j784s4-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","15.91 (min 15.71, max 16.01)","22.47 (min 21.95, max 23.09)","16.90 (min 16.62, max 17.21)","17.62 (min 17.31, max 18.13)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","4.41 (min 4.38, max 4.43)","9.11 (min 9.08, max 9.15)","5.53 (min 5.49, max 5.54)","8.54 (min 8.52, max 8.57)"

Table:  **Boot time MMC/SD**


 
 


ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64


.. csv-table::
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "11025","352800.00","0.26"
    "16000","512000.00","0.26"
    "22050","705600.00","0.32"
    "24000","705600.00","0.45"
    "32000","1023999.00","0.32"
    "44100","1411199.00","0.36"
    "48000","1535999.00","0.38"
    "88200","2822396.00","0.46"
    "96000","3071995.00","0.53"

Table:  **Audio Capture**


|


.. csv-table::
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "11025","352945.00","0.33"
    "16000","512211.00","0.26"
    "22050","705891.00","0.27"
    "24000","705891.00","0.43"
    "32000","1024422.00","0.30"
    "44100","1411781.00","0.66"
    "48000","1536633.00","0.39"
    "88200","2823561.00","1.06"
    "96000","3073263.00","0.55"

Table:  **Audio Playback**
 

|

 



 


Graphics SGX/RGX Driver
-------------------------
 


GFXBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Run GFXBench and capture performance reported (Score and Display rate in fps). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","j721e-idk-gw: Score","j721e-idk-gw: Fps","j721s2-evm: Score","j721s2-evm: Fps","j784s4-evm: Score","j784s4-evm: Fps"

    " GFXBench 3.x gl_manhattan_off","1227.25","19.79"
    " GFXBench 3.x gl_trex_off","1832.25","32.72"
    " GFXBench 4.x gl_4_off","427.60","7.24","260.76","4.41"
    " GFXBench 5.x gl_5_high_off","181.50","2.82","114.00","1.77","113.53","1.77"


Table:  **GFXBench**



Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","j721e-idk-gw: Score","j721s2-evm: Score","j784s4-evm: Score"

    "Glmark2-DRM","9.00","9.00"
    "Glmark2-Wayland","963.00","1364.00"


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

.. note::

    | To reduce CPU Load and improve throughput, it is recommended to enable Interrupt Pacing. Interrupt Pacing can be enabled through ethtool command.
    | For example, to enable Interrupt Pacing with tx coalesce parameter (tx-usecs) set to 250 microseconds and rx coalesce parameter (rx-usecs) set to 250 microseconds, the following command can be used for interface eth0:
    | **ethtool -C eth0 tx-usecs 250 rx-usecs 250**

CPSW/CPSW2g/CPSW3g Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- CPSW2g: AM65x, J7200, J721e, J721S2, J784S4
- CPSW3g: AM64x


.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j784s4-evm: THROUGHPUT (Mbits/sec)","j784s4-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1615.13","30.79","1844.71","27.81","1866.78","30.55","1846.33","24.94"

Table: **CPSW TCP Bidirectional Throughput**
|



.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j784s4-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j784s4-evm: THROUGHPUT (Mbits/sec)","j784s4-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","20.99","83.64","18.00","29.17","84.60","18.00","28.35","89.33","18.00","9.37","8.66"
    "128","82.00","132.49","86.77","82.00","135.50","86.58","82.00","127.36","88.56"
    "256","210.00","28.06","11.93","210.00","42.00","13.14","210.00","307.21","83.83"
    "512","466.00","30.57","0.47"
    "1024","978.00","670.09","51.88","978.00","819.21","49.67","978.00","759.89","50.04","978.00","93.69","1.29"
    "1518","1472.00","864.45","49.82","1472.00","956.96","40.08","1472.00","595.86","21.05","1472.00","95.72","0.92"

Table: **CPSW UDP Egress Throughput**
|



.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j784s4-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j784s4-evm: THROUGHPUT (Mbits/sec)","j784s4-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","9.96","39.40","18.00","11.82","26.74","18.00","15.55","54.30","18.00","20.41","17.62"
    "128","82.00","42.38","21.07","82.00","61.53","28.79","82.00","32.01","30.22"
    "256","210.00","114.24","33.49","210.00","157.58","29.34","210.00","75.26","19.26"
    "512","466.00","67.42","2.95"
    "1024","978.00","550.80","46.24","978.00","427.97","33.92","978.00","251.52","26.67","978.00","93.10","1.97"
    "1518","1472.00","949.85","52.11","1472.00","854.70","58.43","1472.00","94.21","1.38"


Table: **CPSW UDP Ingress Throughput (0% loss)**

|



.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j7200-evm: Packet Loss %","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: Packet Loss %","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: Packet Loss %","j784s4-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j784s4-evm: THROUGHPUT (Mbits/sec)","j784s4-evm: CPU Load % (LOCAL_CPU_UTIL)","j784s4-evm: Packet Loss %"

    "64","18.00","22.85","74.63","0.29","18.00","54.49","83.14","11.32","18.00","20.84","67.34","0.01","18.00","20.41","17.62","0.00"
    "128","82.00","178.95","88.07","35.28","82.00","220.68","80.89","17.31","82.00","66.63","38.43","4.67"
    "256","210.00","331.41","89.20","16.37","210.00","623.77","88.86","11.70","210.00","191.40","65.79","0.01"
    "512","466.00","67.42","2.95","0.00"
    "1024","978.00","932.18","78.34","0.01","978.00","928.99","76.52","0.02","978.00","814.90","71.13","6.27","978.00","93.10","1.97","0.00"
    "1518","1472.00","949.85","52.11","0.00","1472.00","854.70","58.43","0.00","1472.00","95.25","1.57","0.01"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|
 
 


CPSW5g/CPSW9g Virtual Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- CPSW5g: J7200
- CPSW9g: J721e, J784S4


.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW9g-tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.1.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.1.1 -j -c -C -l 60 -t TCP_MAERTS","1821.15","63.97","1876.53","30.83"

Table: **CPSW9g Virtual Ethernet Driver - TCP Bidirectional Throughput**
|




.. rubric::  UDP Throughput 
   :name: CPSW9g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","10.42","73.34","18.00","12.29","50.24"
    "128","82.00","45.97","72.00","82.00","63.22","52.40"
    "256","210.00","98.89","67.58","210.00","237.10","69.69"
    "512","466.00","35.79","1.84"
    "1024","978.00","518.78","73.35","978.00","675.00","50.83"
    "1280","1234.00","825.16","50.28"
    "1518","1472.00","684.78","63.02","1472.00","956.76","50.28"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Egress Throughput**
|



.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.14","2.09","18.00","1.28","3.73"
    "128","82.00","6.30","2.66","82.00","7.08","6.12"
    "256","210.00","17.30","5.34","210.00","19.32","4.43"
    "512","466.00","51.07","8.61"
    "1024","978.00","120.49","7.10","978.00","116.57","7.50"
    "1280","1234.00","132.28","10.11"
    "1518","1472.00","160.14","11.73","1472.00","216.68","15.42"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Ingress Throughput(0% loss)**

|




.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j7200-evm: Packet Loss %","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: Packet Loss %"

    "64","18.00","19.53","79.34","66.36","18.00","40.34","74.53","30.19"
    "128","82.00","84.20","80.99","67.55","82.00","180.83","76.26","27.79"
    "256","210.00","208.36","80.62","68.93","210.00","489.92","80.12","26.98"
    "512","466.00","872.66","76.56","0.30"
    "1024","978.00","916.01","86.02","2.21","978.00","935.68","77.80","0.11"
    "1280","1234.00","948.59","74.53","0.05"
    "1518","1472.00","951.76","79.04","0.54","1472.00","955.09","50.41","0.20"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Ingress Throughput (possible loss)**

|
 
 

 
 


PCIe Driver
-------------------------

PCIe-ETH
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "TCP Window Size(Kbytes)","j7200-evm: Bandwidth (Mbits/sec)","j721e-idk-gw: Bandwidth (Mbits/sec)"

    "8","232.80","279.20"
    "16","227.20","427.20"
    "32","372.80","468.80"
    "64","582.40","661.60"
    "128","756.00","637.60"
    "256","832.00","768.00"

Table: **PCI Ethernet**


 


PCIe-NVMe-SSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^
 

 


J721E-IDK-GW
"""""""""""""""""""""""""""




.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","752.00","13.17","1531.00","6.49"
    "4m","755.00","13.26","1499.00","5.47"
    "4k","189.00","48.74","167.00","36.72"
    "256k","753.00","13.37","1531.00","12.11"

 

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY
 


J7200-EVM
"""""""""""""""""""""""""""




.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","709.00","20.24","1527.00","17.92"
    "4m","706.00","16.92","1527.00","13.01"
    "4k","64.00","50.83","104.00","50.66"
    "256k","721.00","25.81","1524.00","35.65"

 

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY
 


J721S2-EVM
"""""""""""""""""""""""""""




.. csv-table::
    :header: "Buffer size (bytes)","j721s2-evm: Write EXT4 Throughput (Mbytes/sec)","j721s2-evm: Write EXT4 CPU Load (%)","j721s2-evm: Read EXT4 Throughput (Mbytes/sec)","j721s2-evm: Read EXT4 CPU Load (%)"

    "1m","739.00","15.54","778.00","3.61"
    "4m","739.00","14.43","778.00","3.80"
    "4k","200.00","50.25","290.00","50.40"
    "256k","739.00","14.27","776.00","6.67"

 

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

    "102400","0.57 (min 0.45, max 1.01)","21.70 (min 20.51, max 23.39)","32.02","7.69"
    "262144","0.44 (min 0.34, max 0.48)","22.00 (min 20.72, max 22.76)","32.09","0.00"
    "524288","0.44 (min 0.34, max 0.47)","21.11 (min 20.16, max 21.86)","31.73","7.69"
    "1048576","0.44 (min 0.34, max 0.47)","21.48 (min 21.08, max 21.97)","31.47","7.69"




RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","j721e-idk-gw: Raw Read Throughput (Mbytes/sec)"

    "50","38.17"

 
 


J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^




RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","j7200-evm: Raw Read Throughput (Mbytes/sec)"

    "50","200.00"

 
 

 

 

 

 
 

 


UBoot QSPI/OSPI Driver
-------------------------




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","1541.01","37236.36"
    "800000","1541.88","39009.52"
    "1000000","1542.60","39863.75"
    "2000000","1542.39","40206.13"





J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","351.53","204800.00"
    "800000","353.07","240941.18"
    "1000000","356.24","277694.92"
    "2000000","359.67","300623.85"




J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "400000","376.96","204800.00"
    "800000","374.15","248242.42"
    "1000000","373.71","282482.76"
    "2000000","369.26","300623.85"



















 
 

 

 


UBoot UFS Driver
-------------------------
|


J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","91022.22","372363.64"
    "800000","84453.61","481882.35"
    "1000000","103696.20","528516.13"

|



 

 

 
 

 


UBoot EMMC Driver
-------------------------
|


J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "2000000","59148.01","306242.99"
    "4000000","61020.48","313569.38"

|



J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "2000000","58202.49","173375.66"
    "4000000","57387.04","175229.95"

|



J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "2000000","60457.56","309132.08"
    "4000000","60179.98","324435.64"

|



J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j784s4-evm: Write Throughput (Kbytes/sec)","j784s4-evm: Read Throughput (Kbytes/sec)"

    "2000000","57588.75","83591.84"
    "4000000","57996.46","84453.61"

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

    "1m","19.30","0.92","87.20","1.11"
    "4m","19.30","0.87","86.80","0.95"
    "4k","5.17","3.44","16.80","7.81"
    "256k","18.80","1.07","84.50","1.39"

|








J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","18.00","0.73","43.30","0.58"
    "4m","18.10","0.71","43.20","0.55"
    "4k","4.65","2.89","13.60","6.06"
    "256k","17.60","0.88","42.70","0.84"

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

    "400000","18044.05","21787.23"
    "800000","15603.81","22505.49"
    "1000000","17808.70","23108.60"




J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","17429.79","78769.23"
    "800000","14760.36","86231.58"
    "1000000","16701.33","90021.98"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card




J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "400000","14271.78","40156.86"
    "800000","18450.45","42666.67"
    "1000000","22882.68","44043.01"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card




J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j784s4-evm: Write Throughput (Kbytes/sec)","j784s4-evm: Read Throughput (Kbytes/sec)"

    "400000","14075.60","21445.03"
    "800000","20277.23","22443.84"
    "1000000","15814.67","22978.96"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card


















|



USB Driver
-------------------------
 


USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^










.. csv-table::
    :header: "Number of Blocks","j721e-idk-gw: Throughput (MB/sec)","j721s2-evm: Throughput (MB/sec)","j784s4-evm: Throughput (MB/sec)"

    "150","42.20","31.70","44.00"

Table: **USBDEVICE HIGHSPEED SLAVE READ THROUGHPUT**

|
|



.. csv-table::
    :header: "Number of Blocks","j721e-idk-gw: Throughput (MB/sec)","j721s2-evm: Throughput (MB/sec)","j784s4-evm: Throughput (MB/sec)"

    "150","38.20","31.90","39.10"

Table: **USBDEVICE HIGHSPEED SLAVE WRITE THROUGHPUT**

|
|




 
 
 


CRYPTO Driver
-------------------------


OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","j721s2-evm: throughput (KBytes/Sec)","j784s4-evm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","46507.35","17632.60"
    "aes-128-cbc","16","920.84","303.14"
    "aes-128-cbc","16384","187225.43","129531.90"
    "aes-128-cbc","256","14067.03","4898.56"
    "aes-128-cbc","64","3635.63","1303.27"
    "aes-128-cbc","8192","151835.99","86406.49"
    "aes-192-cbc","1024","45220.52","18487.98"
    "aes-192-cbc","16","922.36","356.85"
    "aes-192-cbc","16384","175412.57","127041.54"
    "aes-192-cbc","256","14011.65","5029.21"
    "aes-192-cbc","64","3682.62","1400.19"
    "aes-192-cbc","8192","145074.86","89071.62"
    "aes-256-cbc","1024","44186.28","20350.98"
    "aes-256-cbc","16","886.54","322.25"
    "aes-256-cbc","16384","162196.14","117303.98"
    "aes-256-cbc","256","13996.71","5024.34"
    "aes-256-cbc","64","3635.95","1367.62"
    "aes-256-cbc","8192","135487.49","89636.86"
    "des-cbc","1024","47202.30","44218.37"
    "des-cbc","16","10097.64","5814.19"
    "des-cbc","16384","49790.98","48371.03"
    "des-cbc","256","39800.92","34500.10"
    "des-cbc","64","24835.29","17762.50"
    "des-cbc","8192","49599.83","48054.27"
    "des3","1024","40529.92","19184.64"
    "des3","16","881.24","332.38"
    "des3","16384","96305.15","80150.53"
    "des3","256","13565.01","5362.26"
    "des3","64","3591.87","1356.69"
    "des3","8192","86433.79","63214.93"
    "md5","1024","84417.54","29446.14"
    "md5","16","1828.97","507.20"
    "md5","16384","258228.22","180458.84"
    "md5","256","26644.05","7911.08"
    "md5","64","7114.03","2014.23"
    "md5","8192","227270.66","133414.91"
    "sha1","1024","53441.19","19604.48"
    "sha1","16","880.63","315.15"
    "sha1","16384","451685.03","218234.88"
    "sha1","256","13949.10","5036.89"
    "sha1","64","3513.26","1276.54"
    "sha1","8192","301509.29","125534.21"
    "sha224","1024","100553.39","30852.44"
    "sha224","16","1757.40","507.96"
    "sha224","16384","594870.27","294715.39"
    "sha224","256","27369.22","7930.79"
    "sha224","64","7010.52","2052.69"
    "sha224","8192","447883.95","185417.73"
    "sha256","1024","52388.52","18298.88"
    "sha256","16","867.23","298.02"
    "sha256","16384","437136.04","206034.26"
    "sha256","256","13651.80","4712.70"
    "sha256","64","3455.21","1189.61"
    "sha256","8192","290821.46","120736.43"
    "sha384","1024","68233.90","26625.02"
    "sha384","16","1745.96","519.94"
    "sha384","16384","158870.19","122765.31"
    "sha384","256","24044.97","7811.75"
    "sha384","64","6992.04","2072.62"
    "sha384","8192","145795.75","97006.93"
    "sha512","1024","42033.83","17075.20"
    "sha512","16","855.38","299.06"
    "sha512","16384","145200.47","106048.17"
    "sha512","256","12812.37","4660.82"
    "sha512","64","3435.52","1198.89"
    "sha512","8192","124417.37","78924.46"


|
|



.. csv-table::
    :header: "Algorithm","j721s2-evm: CPU Load","j784s4-evm: CPU Load"

    "aes-128-cbc","37.00","45.00"
    "aes-192-cbc","37.00","43.00"
    "aes-256-cbc","34.00","50.00"
    "des-cbc","99.00","98.00"
    "des3","31.00","46.00"
    "md5","99.00","98.00"
    "sha1","99.00","98.00"
    "sha224","99.00","98.00"
    "sha256","99.00","97.00"
    "sha384","99.00","98.00"
    "sha512","99.00","98.00"

 

Listed for each algorithm are the code snippets used to run each
  benchmark test.

::
    time -v openssl speed -elapsed -evp aes-128-cbc

 




IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","j721e-idk-gw: Throughput (Mbps)","j721e-idk-gw: Packets/Sec","j721e-idk-gw: CPU Load"

    "3des","233.10","20.00","43.72"
    "aes128","644.70","57.00","57.22"
    "aes192","651.90","58.00","57.25"
    "aes256","630.60","56.00","57.51"

 
 

DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.

