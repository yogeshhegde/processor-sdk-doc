.. http://processors.wiki.ti.com/index.php/CoreSDK_Linux_Kernel_Performance_Guide

======================================
 Linux 09.01.00 Performance Guide
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
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j784s4-evm: perf"

    "af_unix_sock_stream_latency (microsec)","19.71","16.34","15.97","19.30"
    "af_unix_socket_stream_bandwidth (MBs)","1661.35","2043.72","1896.16","3568.72"
    "bw_file_rd-io-1mb (MB/s)","3093.16","2979.52","2971.77","3213.61"
    "bw_file_rd-o2c-1mb (MB/s)","1545.86","1620.45","1300.39","1815.87"
    "bw_mem-bcopy-16mb (MB/s)","2378.83","2826.36","3623.19","3098.37"
    "bw_mem-bcopy-1mb (MB/s)","3343.89","4626.20","4645.98","10037.39"
    "bw_mem-bcopy-2mb (MB/s)","2484.91","3977.58","3791.47","4490.50"
    "bw_mem-bcopy-4mb (MB/s)","2354.79","3715.40","3511.85","3644.98"
    "bw_mem-bcopy-8mb (MB/s)","2374.94","3090.59","3524.75","3220.18"
    "bw_mem-bzero-16mb (MB/s)","2340.21","9644.36","10700.55","10852.98"
    "bw_mem-bzero-1mb (MB/s)","4096.42 (min 3343.89, max 4848.94)","8563.10 (min 4626.20, max 12500.00)","8748.23 (min 4645.98, max 12850.47)","11891.55 (min 10037.39, max 13745.70)"
    "bw_mem-bzero-2mb (MB/s)","2712.78 (min 2484.91, max 2940.64)","8049.40 (min 3977.58, max 12121.21)","7620.58 (min 3791.47, max 11449.68)","9090.87 (min 4490.50, max 13691.23)"
    "bw_mem-bzero-4mb (MB/s)","2418.67 (min 2354.79, max 2482.54)","7790.22 (min 3715.40, max 11865.04)","7151.61 (min 3511.85, max 10791.37)","7984.15 (min 3644.98, max 12323.31)"
    "bw_mem-bzero-8mb (MB/s)","2365.16 (min 2355.37, max 2374.94)","7355.03 (min 3090.59, max 11619.46)","7136.66 (min 3524.75, max 10748.56)","7274.81 (min 3220.18, max 11329.44)"
    "bw_mem-cp-16mb (MB/s)","987.78","1595.21","2176.87","2398.08"
    "bw_mem-cp-1mb (MB/s)","2967.00 (min 1234.57, max 4699.43)","7233.78 (min 1766.78, max 12700.78)","7712.52 (min 2484.71, max 12940.33)","8694.63 (min 3655.96, max 13733.29)"
    "bw_mem-cp-2mb (MB/s)","1978.59 (min 1043.84, max 2913.33)","6865.20 (min 1539.65, max 12190.75)","6742.25 (min 2197.40, max 11287.09)","8186.90 (min 2710.95, max 13662.85)"
    "bw_mem-cp-4mb (MB/s)","1719.30 (min 984.98, max 2453.61)","6747.19 (min 1589.61, max 11904.76)","6438.20 (min 2092.78, max 10783.61)","7536.43 (min 2756.24, max 12316.61)"
    "bw_mem-cp-8mb (MB/s)","1647.87 (min 985.59, max 2310.14)","6566.20 (min 1536.10, max 11596.30)","6439.05 (min 2162.45, max 10715.65)","6886.01 (min 2450.60, max 11321.42)"
    "bw_mem-fcp-16mb (MB/s)","2408.91","2837.89","3503.01","3047.62"
    "bw_mem-fcp-1mb (MB/s)","4083.15 (min 3317.36, max 4848.94)","8238.43 (min 3976.86, max 12500.00)","8309.78 (min 3769.09, max 12850.47)","10224.18 (min 6702.66, max 13745.70)"
    "bw_mem-fcp-2mb (MB/s)","2768.78 (min 2596.92, max 2940.64)","8064.25 (min 4007.29, max 12121.21)","7588.08 (min 3726.48, max 11449.68)","8878.83 (min 4066.42, max 13691.23)"
    "bw_mem-fcp-4mb (MB/s)","2439.95 (min 2397.36, max 2482.54)","7873.14 (min 3881.23, max 11865.04)","7124.59 (min 3457.81, max 10791.37)","7946.10 (min 3568.88, max 12323.31)"
    "bw_mem-fcp-8mb (MB/s)","2374.58 (min 2355.37, max 2393.78)","7380.00 (min 3140.54, max 11619.46)","7148.38 (min 3548.20, max 10748.56)","7249.09 (min 3168.74, max 11329.44)"
    "bw_mem-frd-16mb (MB/s)","6295.91","4795.44","4308.02","3471.85"
    "bw_mem-frd-1mb (MB/s)","5433.77 (min 3317.36, max 7550.17)","4719.18 (min 3976.86, max 5461.50)","4611.98 (min 3769.09, max 5454.87)","7311.73 (min 6702.66, max 7920.79)"
    "bw_mem-frd-2mb (MB/s)","4516.77 (min 2596.92, max 6436.62)","4899.05 (min 4007.29, max 5790.81)","4287.07 (min 3726.48, max 4847.65)","4189.55 (min 4066.42, max 4312.67)"
    "bw_mem-frd-4mb (MB/s)","4361.36 (min 2397.36, max 6325.36)","4766.47 (min 3881.23, max 5651.71)","3911.12 (min 3457.81, max 4364.43)","3704.44 (min 3568.88, max 3840.00)"
    "bw_mem-frd-8mb (MB/s)","4354.45 (min 2393.78, max 6315.12)","4262.97 (min 3140.54, max 5385.39)","3931.60 (min 3548.20, max 4314.99)","3467.02 (min 3168.74, max 3765.30)"
    "bw_mem-fwr-16mb (MB/s)","2321.53","9616.83","10688.04","10821.78"
    "bw_mem-fwr-1mb (MB/s)","6124.80 (min 4699.43, max 7550.17)","9081.14 (min 5461.50, max 12700.78)","9197.60 (min 5454.87, max 12940.33)","10827.04 (min 7920.79, max 13733.29)"
    "bw_mem-fwr-2mb (MB/s)","4674.98 (min 2913.33, max 6436.62)","8990.78 (min 5790.81, max 12190.75)","8067.37 (min 4847.65, max 11287.09)","8987.76 (min 4312.67, max 13662.85)"
    "bw_mem-fwr-4mb (MB/s)","4389.49 (min 2453.61, max 6325.36)","8778.24 (min 5651.71, max 11904.76)","7574.02 (min 4364.43, max 10783.61)","8078.31 (min 3840.00, max 12316.61)"
    "bw_mem-fwr-8mb (MB/s)","4312.63 (min 2310.14, max 6315.12)","8490.85 (min 5385.39, max 11596.30)","7515.32 (min 4314.99, max 10715.65)","7543.36 (min 3765.30, max 11321.42)"
    "bw_mem-rd-16mb (MB/s)","6570.84","5125.74","5025.13","4029.72"
    "bw_mem-rd-1mb (MB/s)","9785.54 (min 4586.24, max 14984.83)","7708.92 (min 5851.98, max 9565.86)","7384.25 (min 7199.56, max 7568.93)","16035.25 (min 15543.07, max 16527.42)"
    "bw_mem-rd-2mb (MB/s)","4025.38 (min 977.36, max 7073.39)","4163.76 (min 1735.81, max 6591.70)","4432.40 (min 2871.50, max 5993.30)","4685.54 (min 3738.32, max 5632.75)"
    "bw_mem-rd-4mb (MB/s)","3720.44 (min 785.31, max 6655.57)","3799.89 (min 1321.44, max 6278.34)","3764.36 (min 2381.66, max 5147.06)","4136.17 (min 3806.62, max 4465.71)"
    "bw_mem-rd-8mb (MB/s)","3662.14 (min 748.57, max 6575.70)","4007.63 (min 2144.77, max 5870.48)","3660.03 (min 2281.48, max 5038.58)","4085.19 (min 3732.50, max 4437.87)"
    "bw_mem-rdwr-16mb (MB/s)","750.19","1836.76","2217.91","2651.64"
    "bw_mem-rdwr-1mb (MB/s)","2861.63 (min 1234.57, max 4488.68)","2973.85 (min 1766.78, max 4180.92)","3319.10 (min 2484.71, max 4153.48)","6616.56 (min 3655.96, max 9577.16)"
    "bw_mem-rdwr-2mb (MB/s)","1017.14 (min 990.43, max 1043.84)","1809.15 (min 1539.65, max 2078.64)","2508.15 (min 2197.40, max 2818.89)","3470.76 (min 2710.95, max 4230.57)"
    "bw_mem-rdwr-4mb (MB/s)","889.79 (min 794.60, max 984.98)","1995.29 (min 1589.61, max 2400.96)","2238.82 (min 2092.78, max 2384.86)","2982.74 (min 2756.24, max 3209.24)"
    "bw_mem-rdwr-8mb (MB/s)","870.76 (min 755.93, max 985.59)","1932.54 (min 1536.10, max 2328.97)","2201.68 (min 2162.45, max 2240.90)","2728.21 (min 2450.60, max 3005.82)"
    "bw_mem-wr-16mb (MB/s)","742.18","1754.77","2232.77","3078.11"
    "bw_mem-wr-1mb (MB/s)","4537.46 (min 4488.68, max 4586.24)","5016.45 (min 4180.92, max 5851.98)","5861.21 (min 4153.48, max 7568.93)","13052.29 (min 9577.16, max 16527.42)"
    "bw_mem-wr-2mb (MB/s)","983.90 (min 977.36, max 990.43)","1907.23 (min 1735.81, max 2078.64)","2845.20 (min 2818.89, max 2871.50)","3984.45 (min 3738.32, max 4230.57)"
    "bw_mem-wr-4mb (MB/s)","789.96 (min 785.31, max 794.60)","1861.20 (min 1321.44, max 2400.96)","2383.26 (min 2381.66, max 2384.86)","3507.93 (min 3209.24, max 3806.62)"
    "bw_mem-wr-8mb (MB/s)","752.25 (min 748.57, max 755.93)","2236.87 (min 2144.77, max 2328.97)","2261.19 (min 2240.90, max 2281.48)","3369.16 (min 3005.82, max 3732.50)"
    "bw_mmap_rd-mo-1mb (MB/s)","12348.06","8420.28","8469.90","12913.79"
    "bw_mmap_rd-o2c-1mb (MB/s)","1611.93","1532.27","1248.66","2377.90"
    "bw_pipe (MB/s)","666.39","793.05","825.01","658.04"
    "bw_unix (MB/s)","1661.35","2043.72","1896.16","3568.72"
    "lat_connect (us)","34.10","34.05","34.72","34.20"
    "lat_ctx-2-128k (us)","3.36","3.30","3.26","3.27"
    "lat_ctx-2-256k (us)","2.60","2.52","2.64","4.32"
    "lat_ctx-4-128k (us)","3.29","3.31","3.39","4.26"
    "lat_ctx-4-256k (us)","2.34","2.47","2.38","2.34"
    "lat_fs-0k (num_files)","540.00","459.00","546.00","518.00"
    "lat_fs-10k (num_files)","176.00","204.00","182.00","212.00"
    "lat_fs-1k (num_files)","267.00","263.00","289.00","290.00"
    "lat_fs-4k (num_files)","296.00","310.00","300.00","309.00"
    "lat_mem_rd-stride128-sz1000k (ns)","11.00","11.37","12.93","5.65"
    "lat_mem_rd-stride128-sz125k (ns)","5.57","5.57","5.57","5.65"
    "lat_mem_rd-stride128-sz250k (ns)","5.57","5.57","5.57","5.65"
    "lat_mem_rd-stride128-sz31k (ns)","4.66","4.67","4.66","3.85"
    "lat_mem_rd-stride128-sz50 (ns)","2.00","2.00","2.00","2.00"
    "lat_mem_rd-stride128-sz500k (ns)","5.57","5.60","5.57","5.65"
    "lat_mem_rd-stride128-sz62k (ns)","5.57","5.57","5.12","5.65"
    "lat_mmap-1m (us)","36.00","33.00","28.00","33.00"
    "lat_ops-double-add (ns)","1.96","1.96","1.96","1.96"
    "lat_ops-double-div (ns)","9.01","9.01","9.01","9.01"
    "lat_ops-double-mul (ns)","2.00","2.00","2.00","2.00"
    "lat_ops-float-add (ns)","1.96","1.96","1.96","1.96"
    "lat_ops-float-div (ns)","5.51","5.50","5.50","5.51"
    "lat_ops-float-mul (ns)","2.00","2.00","2.00","2.00"
    "lat_ops-int-add (ns)","0.50","0.50","0.50","0.50"
    "lat_ops-int-bit (ns)","0.33","0.33","0.33","0.33"
    "lat_ops-int-div (ns)","4.00","4.00","4.00","4.00"
    "lat_ops-int-mod (ns)","4.67","4.67","4.67","4.67"
    "lat_ops-int-mul (ns)","1.52","1.52","1.52","1.52"
    "lat_ops-int64-add (ns)","0.50","0.50","0.50","0.50"
    "lat_ops-int64-bit (ns)","0.33","0.33","0.33","0.33"
    "lat_ops-int64-div (ns)","3.00","3.00","3.00","3.00"
    "lat_ops-int64-mod (ns)","5.72","5.67","5.67","5.68"
    "lat_ops-int64-mul (ns)","2.52","2.52","2.52","2.52"
    "lat_pagefault (us)","0.53","0.51","0.53","0.53"
    "lat_pipe (us)","11.95","11.92","12.00","12.13"
    "lat_proc-exec (us)","441.54","391.64","448.69","367.81"
    "lat_proc-fork (us)","372.60","337.20","360.40","362.13"
    "lat_proc-proccall (us)","0.00","0.00","0.00","0.00"
    "lat_select (us)","10.92","10.90","10.81","13.03"
    "lat_sem (us)","1.32","1.62","1.61","1.14"
    "lat_sig-catch (us)","3.20","3.19","3.21","3.19"
    "lat_sig-install (us)","0.50","0.50","0.50","0.50"
    "lat_sig-prot (us)","0.33","0.43","0.34","0.45"
    "lat_syscall-fstat (us)","1.20","1.20","1.22","1.24"
    "lat_syscall-null (us)","0.38","0.39","0.37","0.37"
    "lat_syscall-open (us)","371.76","136.93","425.77","96.33"
    "lat_syscall-read (us)","0.48","0.47","0.47","0.48"
    "lat_syscall-stat (us)","1.54","1.54","1.54","1.57"
    "lat_syscall-write (us)","0.42","0.41","0.42","0.41"
    "lat_tcp (us)","0.77","0.79","0.79","0.79"
    "lat_unix (us)","19.71","16.34","15.97","19.30"
    "latency_for_0.50_mb_block_size (nanosec)","5.57","5.60","5.57","5.65"
    "latency_for_1.00_mb_block_size (nanosec)","5.50 (min 0.00, max 11.00)","5.68 (min 0.00, max 11.37)","6.46 (min 0.00, max 12.93)","2.82 (min 0.00, max 5.65)"
    "pipe_bandwidth (MBs)","666.39","793.05","825.01","658.04"
    "pipe_latency (microsec)","11.95","11.92","12.00","12.13"
    "procedure_call (microsec)","0.00","0.00","0.00","0.00"
    "select_on_200_tcp_fds (microsec)","10.92","10.90","10.81","13.03"
    "semaphore_latency (microsec)","1.32","1.62","1.61","1.14"
    "signal_handler_latency (microsec)","0.50","0.50","0.50","0.50"
    "signal_handler_overhead (microsec)","3.20","3.19","3.21","3.19"
    "tcp_ip_connection_cost_to_localhost (microsec)","34.10","34.05","34.72","34.20"
    "tcp_latency_using_localhost (microsec)","0.77","0.79","0.79","0.79"


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
    "dhrystone_per_mhz (DMIPS/MHz)","4.70","4.70","5.20","4.40"
    "dhrystone_per_second (DhrystoneP)","16666667.00","16666667.00","18181818.00","15384615.00"


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

    "linpack (Kflops)","2505169.00","2421252.00","2456768.00","2509747.00"


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

    "assignment (Iterations)","30.74","30.64","30.78","30.65"
    "fourier (Iterations)","60221.00","55852.00","53535.00","53542.00"
    "fp_emulation (Iterations)","214.62","214.62","214.55","214.62"
    "huffman (Iterations)","2382.90","2384.90","2381.40","2388.10"
    "idea (Iterations)","7996.90","7996.00","7996.80","7996.50"
    "lu_decomposition (Iterations)","1362.80","1365.40","1359.40","1350.10"
    "neural_net (Iterations)","28.68","30.39","29.84","29.84"
    "numeric_sort (Iterations)","854.74","849.41","845.29","850.33"
    "string_sort (Iterations)","419.63","413.55","417.23","413.59"


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

    "add (MB/s)","5462.40","5346.60","6200.70","6180.00"
    "copy (MB/s)","4784.00","5606.40","6933.90","6662.80"
    "scale (MB/s)","4848.90","5469.20","7060.60","6678.60"
    "triad (MB/s)","5464.70","5323.60","6223.60","6182.90"


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

    "cjpeg-rose7-preset (workloads/)","81.30","81.97","83.33","82.64"
    "core (workloads/)","0.78","0.78","0.78","0.78"
    "coremark-pro ()","2436.87","2476.52","2473.59","2487.47"
    "linear_alg-mid-100x100-sp (workloads/)","81.97","81.70","79.87","80.91"
    "loops-all-mid-10k-sp (workloads/)","2.48","2.43","2.48","2.47"
    "nnet_test (workloads/)","3.57","3.82","3.72","3.62"
    "parser-125k (workloads/)","10.99","10.87","10.87","10.75"
    "radix2-big-64k (workloads/)","224.47","249.07","249.50","272.48"
    "sha-test (workloads/)","158.73","158.73","158.73","158.73"
    "zip-test (workloads/)","47.62","47.62","47.62","47.62"


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

    "4m-check (workloads/)","924.56","922.85","871.99","1041.67"
    "4m-check-reassembly (workloads/)","122.40","149.70","150.15","199.60"
    "4m-check-reassembly-tcp (workloads/)","92.94","102.04","96.15","115.21"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","40.57","44.44","41.44","40.57"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","2.70","2.72","2.65","4.88"
    "4m-cmykw2 (workloads/)","312.50","318.47","310.56","604.23"
    "4m-cmykw2-rotatew2 (workloads/)","59.00","62.83","59.29","50.80"
    "4m-reassembly (workloads/)","107.41","130.72","123.76","146.63"
    "4m-rotatew2 (workloads/)","71.02","74.40","70.62","56.50"
    "4m-tcp-mixed (workloads/)","262.30","271.19","262.30","253.97"
    "4m-x264w2 (workloads/)","2.75","2.80","2.75","5.09"
    "idct-4m (workloads/)","34.95","35.10","35.00","35.14"
    "idct-4mw1 (workloads/)","34.92","35.08","35.00","35.14"
    "ippktcheck-4m (workloads/)","943.40","935.98","846.31","1028.81"
    "ippktcheck-4mw1 (workloads/)","920.47","923.53","858.22","1042.97"
    "ipres-4m (workloads/)","156.74","178.36","164.84","199.73"
    "ipres-4mw1 (workloads/)","159.07","179.00","163.93","202.43"
    "md5-4m (workloads/)","45.77","48.69","45.93","47.62"
    "md5-4mw1 (workloads/)","45.87","49.00","46.08","47.96"
    "rgbcmyk-4m (workloads/)","163.40","163.67","163.13","164.20"
    "rgbcmyk-4mw1 (workloads/)","163.13","163.80","162.08","164.20"
    "rotate-4ms1 (workloads/)","52.14","54.76","51.55","54.88"
    "rotate-4ms1w1 (workloads/)","52.36","55.07","51.87","55.07"
    "rotate-4ms64 (workloads/)","52.63","55.80","52.63","55.62"
    "rotate-4ms64w1 (workloads/)","52.74","55.62","52.25","55.87"
    "x264-4mq (workloads/)","1.42","1.43","1.42","1.42"
    "x264-4mqw1 (workloads/)","1.43","1.43","1.42","1.43"


Table:  **Multibench**


 
 


Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","j7200-evm: boot time (sec)","j721e-idk-gw: boot time (sec)","j721s2-evm: boot time (sec)","j784s4-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","13.44 (min 13.33, max 13.54)","17.31 (min 17.19, max 17.55)","18.77 (min 18.51, max 18.94)","15.57 (min 15.44, max 15.89)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","4.18 (min 4.17, max 4.21)","5.06 (min 5.01, max 5.07)","5.33 (min 5.28, max 5.38)","6.43 (min 6.39, max 6.48)"

Table:  **Boot time MMC/SD**


 
 


ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64


.. csv-table::
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "11025","352793.00","0.15"
    "16000","511992.00","0.29"
    "22050","705578.00","0.21"
    "24000","705584.00","0.25"
    "32000","1023981.00","0.38"
    "44100","1411176.00","0.41"
    "48000","1535975.00","0.24"
    "88200","2822353.00","0.76"
    "96000","3071948.00","1.12"

Table:  **Audio Capture**


|


.. csv-table::
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "11025","352938.00","0.17"
    "16000","512203.00","0.28"
    "22050","705867.00","0.25"
    "24000","705874.00","0.25"
    "32000","1024402.00","0.37"
    "44100","1411756.00","0.47"
    "48000","1536607.00","0.60"
    "88200","2823514.00","0.76"
    "96000","3073213.00","1.17"

Table:  **Audio Playback**
 

|

 



 


Graphics SGX/RGX Driver
-------------------------
 




Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","j721e-idk-gw: Score","j721s2-evm: Score","j784s4-evm: Score"

    "Glmark2-DRM","28.00","28.00"
    "Glmark2-Wayland","1180.00","1286.00","1333.00"


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
    :header: "Command Used","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j784s4-evm: THROUGHPUT (Mbits/sec)","j784s4-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1834.33","73.50","1849.46","73.40","1855.53","18.66"

Table: **CPSW TCP Bidirectional Throughput**

|



.. rubric::  TCP Bidirectional Throughput Interrupt Pacing
   :name: CPSW2g-tcp-bidirectional-throughput-interrupt-pacing

.. csv-table::
    :header: "Command Used","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1859.60","34.09","1867.98","45.94"

Table: **CPSW TCP Bidirectional Throughput Interrupt Pacing**

|



.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: Packets Per Second (kPPS)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: Packets Per Second (kPPS)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","32.39","225.00","88.25","18.00","30.00","208.00","91.26"
    "128","82.00","146.16","223.00","88.80","82.00","131.44","200.00","89.55"
    "256","210.00","368.14","219.00","87.76","210.00","27.55","16.00","12.52"
    "1024","978.00","675.97","86.00","35.83","978.00","700.58","90.00","50.47"
    "1518","1472.00","592.23","50.00","23.48","1472.00","955.98","81.00","42.40"

Table: **CPSW UDP Egress Throughput**
|



.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: Packets Per Second (kPPS)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: Packets Per Second (kPPS)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","7.26","50.00","18.15","18.00","1.28","9.00","6.56"
    "128","82.00","8.20","13.00","5.59","82.00","20.53","31.00","21.86"
    "256","210.00","18.31","11.00","4.62","210.00","76.44","46.00","29.70"
    "1024","978.00","107.19","14.00","8.80","978.00","180.73","23.00","15.57"
    "1518","1472.00","216.68","18.00","13.52","1472.00","956.98","81.00","64.71"


Table: **CPSW UDP Ingress Throughput (0% loss)**

|



.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: Packets Per Second (kPPS)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: Packet Loss %","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: Packets Per Second (kPPS)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: Packet Loss %"

    "64","18.00","59.08","410.00","88.04","1.78","18.00","18.61","129.00","71.03","0.04"
    "128","82.00","261.28","398.00","90.62","1.68","82.00","86.81","132.00","72.16","4.34"
    "256","210.00","669.82","399.00","92.76","1.82","210.00","234.27","139.00","80.60","0.06"
    "1024","978.00","928.84","119.00","83.35","0.03","978.00","930.94","119.00","84.56","0.61"
    "1518","1472.00","949.65","81.00","60.31","0.02","1472.00","956.98","81.00","64.71","0.00"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|
 
 

 

 
 


PCIe Driver
-------------------------

PCIe-ETH
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "TCP Window Size(Kbytes)","j7200-evm: Bandwidth (Mbits/sec)","j721e-idk-gw: Bandwidth (Mbits/sec)"

    "8","209.60","271.20"
    "16","224.00","239.20"
    "32","348.00","376.80"
    "64","574.40","598.40"
    "128","717.60","751.20"
    "256","808.00","796.80"

Table: **PCI Ethernet**


 


PCIe-NVMe-SSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^
 

 


J721E-IDK-GW
"""""""""""""""""""""""""""




.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","720.00","13.11","1521.00","6.09"
    "4m","721.00","11.86","1523.00","5.01"
    "4k","187.00","48.64","166.00","36.34"
    "256k","740.00","12.56","1520.00","11.87"

 

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY
 


J7200-EVM
"""""""""""""""""""""""""""




.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","717.00","14.80","1525.00","6.68"
    "4m","713.00","13.96","1525.00","5.65"
    "4k","186.00","48.63","167.00","36.12"
    "256k","746.00","13.93","1523.00","11.57"

 

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY
 


J721S2-EVM
"""""""""""""""""""""""""""




.. csv-table::
    :header: "Buffer size (bytes)","j721s2-evm: Write EXT4 Throughput (Mbytes/sec)","j721s2-evm: Write EXT4 CPU Load (%)","j721s2-evm: Read EXT4 Throughput (Mbytes/sec)","j721s2-evm: Read EXT4 CPU Load (%)"

    "1m","737.00","17.93","774.00","6.38"
    "4m","737.00","15.64","776.00","5.39"
    "4k","184.00","51.83","277.00","51.83"
    "256k","736.00","15.94","778.00","8.22"

 

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY
 

 
 
 

 


OSPI Flash Driver
-------------------------

 

 


J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^




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

    "50","217.39"

 
 

 


J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^




RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","j784s4-evm: Raw Read Throughput (Mbytes/sec)"

    "50","263.16"

 
 

 

 
 

 


UBoot QSPI/OSPI Driver
-------------------------




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","1632.52","195047.62"
    "800000","1634.15","240941.18"
    "1000000","1632.20","277694.92"
    "2000000","1631.06","300623.85"





J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","344.75","195047.62"
    "800000","348.08","240941.18"
    "1000000","348.80","277694.92"
    "2000000","349.88","300623.85"




J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "400000","377.58","204800.00"
    "800000","380.07","248242.42"
    "1000000","378.37","282482.76"
    "2000000","370.11","303407.41"



















 
 

 

 


UBoot UFS Driver
-------------------------
|


J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","99902.44","372363.64"
    "800000","98698.80","512000.00"
    "1000000","95255.81","606814.81"

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


J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","56.10","1.38","314.00","1.82"
    "4m","56.40","1.20","309.00","1.33"
    "4k","55.30","26.10","55.80","24.01"
    "256k","56.30","1.71","314.00","3.56"

|



J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","59.50","1.25","175.00","1.02"
    "4m","59.10","1.10","175.00","0.66"
    "4k","49.80","23.01","56.60","23.65"
    "256k","58.90","1.70","174.00","1.93"

|



J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721s2-evm: Write EXT4 Throughput (Mbytes/sec)","j721s2-evm: Write EXT4 CPU Load (%)","j721s2-evm: Read EXT4 Throughput (Mbytes/sec)","j721s2-evm: Read EXT4 CPU Load (%)"

    "1m","60.40","3.76","315.00","3.47"
    "4m","60.30","3.43","314.00","3.61"
    "4k","59.00","32.34","56.40","27.76"
    "256k","60.20","4.00","316.00","5.24"

|



J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j784s4-evm: Write EXT4 Throughput (Mbytes/sec)","j784s4-evm: Write EXT4 CPU Load (%)","j784s4-evm: Read EXT4 Throughput (Mbytes/sec)","j784s4-evm: Read EXT4 CPU Load (%)"

    "1m","89.00","0.45","174.00","0.31"
    "4m","88.60","0.43","174.00","0.20"
    "4k","63.10","9.19","93.10","11.17"
    "256k","88.80","0.57","173.00","0.52"

|


 

 

 

 











 
 


UBoot EMMC Driver
-------------------------
|


J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "2000000","56109.59","309132.08"
    "4000000","57136.88","300623.85"

|



J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "2000000","61020.48","173375.66"
    "4000000","60290.71","177124.32"

|



J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "2000000","60235.29","309132.08"
    "4000000","60681.48","303407.41"

|



J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j784s4-evm: Write Throughput (Kbytes/sec)","j784s4-evm: Read Throughput (Kbytes/sec)"

    "2000000","100824.62","151004.61"
    "4000000","95394.47","260063.49"

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

    "1m","19.20","0.78","87.00","0.78"
    "4m","19.10","0.68","86.70","0.60"
    "4k","5.19","3.25","16.70","7.41"
    "256k","18.70","0.85","84.10","0.98"

|



J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721s2-evm: Write EXT4 Throughput (Mbytes/sec)","j721s2-evm: Write EXT4 CPU Load (%)","j721s2-evm: Read EXT4 Throughput (Mbytes/sec)","j721s2-evm: Read EXT4 CPU Load (%)"

    "1m","20.00","0.81","86.60","0.94"
    "4m","19.70","0.79","86.70","0.76"
    "4k","4.81","3.22","16.70","7.74"
    "256k","19.20","0.93","84.30","1.33"

|



J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j784s4-evm: Write EXT4 Throughput (Mbytes/sec)","j784s4-evm: Write EXT4 CPU Load (%)","j784s4-evm: Read EXT4 Throughput (Mbytes/sec)","j784s4-evm: Read EXT4 CPU Load (%)"

    "1m","18.20","0.15","86.70","0.21"
    "4m","18.40","0.16","86.30","0.20"
    "4k","4.75","0.84","16.60","2.23"
    "256k","18.10","0.15","84.30","0.36"

|




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","18.80","0.70","43.50","0.48"
    "4m","19.40","0.59","43.50","0.45"
    "4k","4.75","2.76","13.70","5.93"
    "256k","18.50","0.70","42.80","0.71"

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

    "400000","1043.30","34133.33"
    "800000","605.96","39574.88"
    "1000000","1281.80","43115.79"




J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","17355.93","73142.86"
    "800000","18492.10","81920.00"
    "1000000","27536.13","87148.94"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card




J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "400000","13429.51","61134.33"
    "800000","21501.31","73801.80"
    "1000000","32251.97","82331.66"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card




J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j784s4-evm: Write Throughput (Kbytes/sec)","j784s4-evm: Read Throughput (Kbytes/sec)"

    "400000","21903.74","56109.59"
    "800000","22321.53","70017.09"
    "1000000","23043.60","80313.73"


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

    "1m","396.00","7.74","426.00","2.52"
    "4m","399.00","6.93","425.00","2.12"
    "4k","30.90","23.86","61.80","27.34"
    "256k","363.00","11.81","405.00","5.49"

|








 

|
 


USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^










.. csv-table::
    :header: "Number of Blocks","j721e-idk-gw: Throughput (MB/sec)","j721s2-evm: Throughput (MB/sec)"

    "150","39.90","31.70"

Table: **USBDEVICE HIGHSPEED SLAVE READ THROUGHPUT**

|
|



.. csv-table::
    :header: "Number of Blocks","j721e-idk-gw: Throughput (MB/sec)","j721s2-evm: Throughput (MB/sec)"

    "150","38.20","30.90"

Table: **USBDEVICE HIGHSPEED SLAVE WRITE THROUGHPUT**

|
|




 
 
 


CRYPTO Driver
-------------------------


OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","j721e-idk-gw: throughput (KBytes/Sec)","j721s2-evm: throughput (KBytes/Sec)","j784s4-evm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","48453.63","45772.12","44823.89"
    "aes-128-cbc","16","942.70","888.04","676.94"
    "aes-128-cbc","16384","193320.28","186985.13","184582.14"
    "aes-128-cbc","256","14607.87","13907.54","13579.01"
    "aes-128-cbc","64","3768.34","3648.83","3144.62"
    "aes-128-cbc","8192","161095.68","153356.97","151259.82"
    "aes-128-ecb","1024","49528.49","46890.67","36290.22"
    "aes-128-ecb","16","937.08","910.89","676.62"
    "aes-128-ecb","16384","199983.10","187077.97","187711.49"
    "aes-128-ecb","256","14722.99","13981.01","10468.52"
    "aes-128-ecb","64","3802.43","3476.31","2711.68"
    "aes-128-ecb","8192","165606.74","155216.55","141399.38"
    "aes-192-cbc","1024","48661.85","46075.22","44281.17"
    "aes-192-cbc","16","953.85","912.28","807.53"
    "aes-192-cbc","16384","183009.28","173249.88","175134.04"
    "aes-192-cbc","256","14654.89","13748.31","13618.26"
    "aes-192-cbc","64","3799.55","3545.00","3516.25"
    "aes-192-cbc","8192","153946.79","146650.45","146090.67"
    "aes-192-ecb","1024","49100.80","44446.72","44505.09"
    "aes-192-ecb","16","955.56","905.09","661.71"
    "aes-192-ecb","16384","187389.27","180655.45","179879.94"
    "aes-192-ecb","256","14733.48","13853.10","13811.20"
    "aes-192-ecb","64","3814.57","3580.12","3079.34"
    "aes-192-ecb","8192","155828.22","150451.54","149214.55"
    "aes-256-cbc","1024","48290.13","44231.34","43749.72"
    "aes-256-cbc","16","953.80","907.91","691.89"
    "aes-256-cbc","16384","169547.09","165096.11","163829.08"
    "aes-256-cbc","256","14762.15","13807.10","13485.91"
    "aes-256-cbc","64","3805.87","3607.72","2964.33"
    "aes-256-cbc","8192","144089.09","138824.36","137885.01"
    "aes-256-ecb","1024","48545.45","45822.29","43770.20"
    "aes-256-ecb","16","948.38","899.13","686.00"
    "aes-256-ecb","16384","174631.59","167646.55","170120.53"
    "aes-256-ecb","256","14718.12","13825.79","11266.39"
    "aes-256-ecb","64","3791.81","3463.36","2742.27"
    "aes-256-ecb","8192","148307.97","141860.86","141713.41"
    "des3","1024","40902.31","39253.67","32882.01"
    "des3","16","940.37","910.05","684.22"
    "des3","16384","97107.97","96343.38","95300.27"
    "des3","256","13781.33","12932.18","10467.84"
    "des3","64","3764.35","3632.41","2742.49"
    "des3","8192","88888.66","87258.45","82507.09"
    "sha1","1024","57184.26","57512.62","57071.96"
    "sha1","16","949.11","932.65","956.85"
    "sha1","16384","460554.24","464382.63","459745.96"
    "sha1","256","15081.47","15106.99","14994.43"
    "sha1","64","3774.25","3758.81","3785.98"
    "sha1","8192","311825.75","309021.35","310326.61"
    "sha256","1024","57045.33","57306.45","56020.65"
    "sha256","16","943.25","945.89","944.29"
    "sha256","16384","451608.58","453432.66","449462.27"
    "sha256","256","15084.89","14586.03","14753.96"
    "sha256","64","3774.19","3762.97","3740.31"
    "sha256","8192","307664.21","307727.02","300007.42"
    "sha512","1024","45960.53","45791.23","44510.21"
    "sha512","16","958.94","938.88","933.77"
    "sha512","16384","150350.51","150033.75","149924.52"
    "sha512","256","14068.39","14111.32","13743.02"
    "sha512","64","3823.89","3833.47","3722.45"
    "sha512","8192","130717.01","128614.40","129111.38"


|
|



.. csv-table::
    :header: "Algorithm","j721e-idk-gw: CPU Load","j721s2-evm: CPU Load","j784s4-evm: CPU Load"

    "aes-128-cbc","33.00","33.00","34.00"
    "aes-128-ecb","35.00","34.00","34.00"
    "aes-192-cbc","34.00","33.00","34.00"
    "aes-192-ecb","34.00","34.00","33.00"
    "aes-256-cbc","33.00","33.00","32.00"
    "aes-256-ecb","33.00","34.00","32.00"
    "des3","30.00","30.00","30.00"
    "sha1","99.00","99.00","99.00"
    "sha256","99.00","99.00","99.00"
    "sha512","99.00","99.00","99.00"

 

Listed for each algorithm are the code snippets used to run each
  benchmark test.

::
    time -v openssl speed -elapsed -evp aes-128-cbc

 




IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","j721e-idk-gw: Throughput (Mbps)","j721e-idk-gw: Packets/Sec","j721e-idk-gw: CPU Load"

    "3des","211.80","18.00","34.62"
    "aes128","654.10","58.00","57.73"
    "aes192","722.50","64.00","57.72"
    "aes256","721.90","64.00","57.56"

 
 

DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.

