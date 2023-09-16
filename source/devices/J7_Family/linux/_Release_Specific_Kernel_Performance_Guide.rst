.. http://processors.wiki.ti.com/index.php/CoreSDK_Linux_Kernel_Performance_Guide

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

    "af_unix_sock_stream_latency (microsec)","16.41","14.81","16.47","24.57"
    "af_unix_socket_stream_bandwidth (MBs)","1592.88","1995.08","2020.45","3428.50"
    "bw_file_rd-io-1mb (MB/s)","2920.24","3112.41","2890.70","2995.13"
    "bw_file_rd-o2c-1mb (MB/s)","1522.65","1597.44","1356.39","1665.56"
    "bw_mem-bcopy-16mb (MB/s)","2378.83","2850.53","3398.11","3509.16"
    "bw_mem-bcopy-1mb (MB/s)","3270.35","5347.59","4972.27","10230.65"
    "bw_mem-bcopy-2mb (MB/s)","2495.99","3960.40","3573.34","5047.77"
    "bw_mem-bcopy-4mb (MB/s)","2360.35","3843.94","3462.00","4430.50"
    "bw_mem-bcopy-8mb (MB/s)","2361.28","3102.58","3394.63","3740.65"
    "bw_mem-bzero-16mb (MB/s)","2343.98","9624.06","10596.03","10880.65"
    "bw_mem-bzero-1mb (MB/s)","4078.49 (min 3270.35, max 4886.63)","8930.60 (min 5347.59, max 12513.60)","8977.33 (min 4972.27, max 12982.39)","12002.89 (min 10230.65, max 13775.13)"
    "bw_mem-bzero-2mb (MB/s)","2709.45 (min 2495.99, max 2922.91)","8031.64 (min 3960.40, max 12102.87)","7356.20 (min 3573.34, max 11139.06)","9368.27 (min 5047.77, max 13688.76)"
    "bw_mem-bzero-4mb (MB/s)","2417.23 (min 2360.35, max 2474.10)","7854.49 (min 3843.94, max 11865.04)","7083.71 (min 3462.00, max 10705.41)","8369.10 (min 4430.50, max 12307.69)"
    "bw_mem-bzero-8mb (MB/s)","2354.87 (min 2348.45, max 2361.28)","7246.26 (min 3102.58, max 11389.93)","7027.99 (min 3394.63, max 10661.34)","7548.11 (min 3740.65, max 11355.57)"
    "bw_mem-cp-16mb (MB/s)","985.34","1498.83","2139.04","2464.19"
    "bw_mem-cp-1mb (MB/s)","3009.43 (min 1272.96, max 4745.90)","7174.32 (min 1670.07, max 12678.57)","7789.08 (min 2533.13, max 13045.03)","8722.00 (min 3718.16, max 13725.84)"
    "bw_mem-cp-2mb (MB/s)","1956.00 (min 1025.47, max 2886.52)","6896.73 (min 1584.79, max 12208.66)","6749.89 (min 2104.89, max 11394.89)","8309.37 (min 2925.05, max 13693.69)"
    "bw_mem-cp-4mb (MB/s)","1707.19 (min 976.09, max 2438.28)","6628.94 (min 1375.99, max 11881.88)","6413.43 (min 2116.40, max 10710.46)","7639.06 (min 2952.57, max 12325.54)"
    "bw_mem-cp-8mb (MB/s)","1657.75 (min 980.75, max 2334.74)","6492.23 (min 1512.86, max 11471.59)","6376.57 (min 2107.76, max 10645.38)","6956.31 (min 2546.96, max 11365.65)"
    "bw_mem-fcp-16mb (MB/s)","2416.92","2828.35","3359.23","3514.17"
    "bw_mem-fcp-1mb (MB/s)","4044.46 (min 3202.28, max 4886.63)","8303.69 (min 4093.78, max 12513.60)","8609.84 (min 4237.29, max 12982.39)","10177.04 (min 6578.95, max 13775.13)"
    "bw_mem-fcp-2mb (MB/s)","2728.66 (min 2534.40, max 2922.91)","8046.72 (min 3990.57, max 12102.87)","7308.33 (min 3477.59, max 11139.06)","8900.07 (min 4111.38, max 13688.76)"
    "bw_mem-fcp-4mb (MB/s)","2441.87 (min 2409.64, max 2474.10)","7886.03 (min 3907.01, max 11865.04)","7061.23 (min 3417.05, max 10705.41)","8253.22 (min 4198.74, max 12307.69)"
    "bw_mem-fcp-8mb (MB/s)","2377.60 (min 2348.45, max 2406.74)","7248.37 (min 3106.80, max 11389.93)","7031.11 (min 3400.88, max 10661.34)","7527.07 (min 3698.57, max 11355.57)"
    "bw_mem-frd-16mb (MB/s)","6305.83","4814.93","4172.64","4238.41"
    "bw_mem-frd-1mb (MB/s)","4791.23 (min 3202.28, max 6380.18)","4805.64 (min 4093.78, max 5517.50)","4626.26 (min 4237.29, max 5015.22)","7134.91 (min 6578.95, max 7690.86)"
    "bw_mem-frd-2mb (MB/s)","4482.06 (min 2534.40, max 6429.72)","4875.58 (min 3990.57, max 5760.58)","4110.19 (min 3477.59, max 4742.79)","4488.36 (min 4111.38, max 4865.33)"
    "bw_mem-frd-4mb (MB/s)","4364.38 (min 2409.64, max 6319.12)","4786.37 (min 3907.01, max 5665.72)","3820.09 (min 3417.05, max 4223.12)","4575.06 (min 4198.74, max 4951.37)"
    "bw_mem-frd-8mb (MB/s)","4365.93 (min 2406.74, max 6325.11)","4243.38 (min 3106.80, max 5379.96)","3783.41 (min 3400.88, max 4165.94)","4249.77 (min 3698.57, max 4800.96)"
    "bw_mem-fwr-16mb (MB/s)","2317.83","9567.95","10592.52","10807.16"
    "bw_mem-fwr-1mb (MB/s)","5563.04 (min 4745.90, max 6380.18)","9098.04 (min 5517.50, max 12678.57)","9030.13 (min 5015.22, max 13045.03)","10708.35 (min 7690.86, max 13725.84)"
    "bw_mem-fwr-2mb (MB/s)","4658.12 (min 2886.52, max 6429.72)","8984.62 (min 5760.58, max 12208.66)","8068.84 (min 4742.79, max 11394.89)","9279.51 (min 4865.33, max 13693.69)"
    "bw_mem-fwr-4mb (MB/s)","4378.70 (min 2438.28, max 6319.12)","8773.80 (min 5665.72, max 11881.88)","7466.79 (min 4223.12, max 10710.46)","8638.46 (min 4951.37, max 12325.54)"
    "bw_mem-fwr-8mb (MB/s)","4329.93 (min 2334.74, max 6325.11)","8425.78 (min 5379.96, max 11471.59)","7405.66 (min 4165.94, max 10645.38)","8083.31 (min 4800.96, max 11365.65)"
    "bw_mem-rd-16mb (MB/s)","6599.75","5105.30","4888.48","5003.13"
    "bw_mem-rd-1mb (MB/s)","10238.35 (min 5205.21, max 15271.49)","7011.91 (min 3821.66, max 10202.15)","7249.40 (min 4067.40, max 10431.40)","15981.18 (min 14755.07, max 17207.28)"
    "bw_mem-rd-2mb (MB/s)","4032.60 (min 979.27, max 7085.92)","4038.96 (min 1640.96, max 6436.96)","4325.76 (min 3072.20, max 5579.32)","7219.65 (min 5631.82, max 8807.47)"
    "bw_mem-rd-4mb (MB/s)","3734.81 (min 785.62, max 6684.00)","3818.32 (min 1367.05, max 6269.59)","3672.19 (min 2361.28, max 4983.09)","4996.70 (min 4017.68, max 5975.72)"
    "bw_mem-rd-8mb (MB/s)","3659.61 (min 748.92, max 6570.30)","4023.40 (min 2074.42, max 5972.38)","3578.20 (min 2272.40, max 4884.00)","4910.89 (min 3931.85, max 5889.93)"
    "bw_mem-rdwr-16mb (MB/s)","748.36","1926.78","2137.32","2762.43"
    "bw_mem-rdwr-1mb (MB/s)","2269.53 (min 1272.96, max 3266.09)","2065.27 (min 1670.07, max 2460.46)","3605.96 (min 2533.13, max 4678.78)","6580.35 (min 3718.16, max 9442.53)"
    "bw_mem-rdwr-2mb (MB/s)","1010.33 (min 995.19, max 1025.47)","1778.40 (min 1584.79, max 1972.00)","2456.10 (min 2104.89, max 2807.30)","3608.45 (min 2925.05, max 4291.85)"
    "bw_mem-rdwr-4mb (MB/s)","885.27 (min 794.44, max 976.09)","1896.21 (min 1375.99, max 2416.43)","2182.75 (min 2116.40, max 2249.09)","3277.76 (min 2952.57, max 3602.95)"
    "bw_mem-rdwr-8mb (MB/s)","867.20 (min 753.65, max 980.75)","1942.85 (min 1512.86, max 2372.83)","2138.19 (min 2107.76, max 2168.61)","2991.45 (min 2546.96, max 3435.93)"
    "bw_mem-wr-16mb (MB/s)","742.05","1815.71","2220.68","3082.85"
    "bw_mem-wr-1mb (MB/s)","4235.65 (min 3266.09, max 5205.21)","3141.06 (min 2460.46, max 3821.66)","4373.09 (min 4067.40, max 4678.78)","13324.91 (min 9442.53, max 17207.28)"
    "bw_mem-wr-2mb (MB/s)","987.23 (min 979.27, max 995.19)","1806.48 (min 1640.96, max 1972.00)","2939.75 (min 2807.30, max 3072.20)","4961.84 (min 4291.85, max 5631.82)"
    "bw_mem-wr-4mb (MB/s)","790.03 (min 785.62, max 794.44)","1891.74 (min 1367.05, max 2416.43)","2305.19 (min 2249.09, max 2361.28)","3810.32 (min 3602.95, max 4017.68)"
    "bw_mem-wr-8mb (MB/s)","751.29 (min 748.92, max 753.65)","2223.63 (min 2074.42, max 2372.83)","2220.51 (min 2168.61, max 2272.40)","3683.89 (min 3435.93, max 3931.85)"
    "bw_mmap_rd-mo-1mb (MB/s)","12421.21","8615.95","8302.58","12702.50"
    "bw_mmap_rd-o2c-1mb (MB/s)","1566.48","1428.06","1211.28","2125.78"
    "bw_pipe (MB/s)","674.09","799.72","817.27","681.23"
    "bw_unix (MB/s)","1592.88","1995.08","2020.45","3428.50"
    "lat_connect (us)","33.74","33.74","34.32","34.76"
    "lat_ctx-2-128k (us)","3.37","3.43","3.37","5.96"
    "lat_ctx-2-256k (us)","2.68","2.60","2.76","2.55"
    "lat_ctx-4-128k (us)","3.36","3.43","3.56","4.16"
    "lat_ctx-4-256k (us)","2.42","2.41","2.53","2.64"
    "lat_fs-0k (num_files)","474.00","460.00","509.00","491.00"
    "lat_fs-10k (num_files)","187.00","205.00","200.00","217.00"
    "lat_fs-1k (num_files)","278.00","269.00","295.00","309.00"
    "lat_fs-4k (num_files)","298.00","293.00","311.00","322.00"
    "lat_mem_rd-stride128-sz1000k (ns)","11.51","10.50","12.73","5.65"
    "lat_mem_rd-stride128-sz125k (ns)","5.57","5.57","5.57","5.65"
    "lat_mem_rd-stride128-sz250k (ns)","5.57","5.57","5.57","5.65"
    "lat_mem_rd-stride128-sz31k (ns)","3.36","5.12","4.66","3.40"
    "lat_mem_rd-stride128-sz50 (ns)","2.00","2.00","2.00","2.00"
    "lat_mem_rd-stride128-sz500k (ns)","5.57","5.57","5.57","5.65"
    "lat_mem_rd-stride128-sz62k (ns)","5.12","5.57","5.57","5.20"
    "lat_mmap-1m (us)","27.00","33.00","27.00","33.00"
    "lat_ops-double-add (ns)","1.96","1.96","1.96","1.96"
    "lat_ops-double-div (ns)","9.01","9.01","9.01","9.01"
    "lat_ops-double-mul (ns)","2.01","2.00","2.00","2.00"
    "lat_ops-float-add (ns)","1.96","1.96","1.96","1.96"
    "lat_ops-float-div (ns)","5.51","5.50","5.50","5.50"
    "lat_ops-float-mul (ns)","2.00","2.00","2.00","2.00"
    "lat_ops-int-add (ns)","0.50","0.50","0.50","0.50"
    "lat_ops-int-bit (ns)","0.33","0.33","0.33","0.33"
    "lat_ops-int-div (ns)","4.00","4.00","4.00","4.00"
    "lat_ops-int-mod (ns)","4.67","4.67","4.67","4.67"
    "lat_ops-int-mul (ns)","1.52","1.52","1.52","1.52"
    "lat_ops-int64-add (ns)","0.50","0.50","0.50","0.50"
    "lat_ops-int64-bit (ns)","0.33","0.33","0.33","0.33"
    "lat_ops-int64-div (ns)","3.00","3.00","3.00","3.00"
    "lat_ops-int64-mod (ns)","5.67","5.67","5.67","5.67"
    "lat_ops-int64-mul (ns)","2.52","2.52","2.52","2.52"
    "lat_pagefault (us)","0.50","0.49","0.51","0.52"
    "lat_pipe (us)","11.79","11.89","11.99","12.36"
    "lat_proc-exec (us)","422.92","380.07","446.92","407.86"
    "lat_proc-fork (us)","361.79","322.83","373.29","376.87"
    "lat_proc-proccall (us)","0.00","0.00","0.00","0.00"
    "lat_select (us)","11.10","10.81","11.09","11.12"
    "lat_sem (us)","1.41","1.35","1.41","2.34"
    "lat_sig-catch (us)","2.70","2.71","2.63","2.79"
    "lat_sig-install (us)","0.49","0.50","0.52","0.51"
    "lat_sig-prot (us)","0.38","0.42","0.49","0.40"
    "lat_syscall-fstat (us)","1.28","1.31","1.27","1.31"
    "lat_syscall-null (us)","0.37","0.38","0.38","0.38"
    "lat_syscall-open (us)","106.19","137.89","149.50","96.60"
    "lat_syscall-read (us)","0.48","0.46","0.50","0.48"
    "lat_syscall-stat (us)","1.65","1.61","1.63","1.74"
    "lat_syscall-write (us)","0.42","0.42","0.42","0.42"
    "lat_tcp (us)","0.75","0.75","0.75","0.75"
    "lat_unix (us)","16.41","14.81","16.47","24.57"
    "latency_for_0.50_mb_block_size (nanosec)","5.57","5.57","5.57","5.65"
    "latency_for_1.00_mb_block_size (nanosec)","5.75 (min 0.00, max 11.51)","5.25 (min 0.00, max 10.50)","6.37 (min 0.00, max 12.73)","2.82 (min 0.00, max 5.65)"
    "pipe_bandwidth (MBs)","674.09","799.72","817.27","681.23"
    "pipe_latency (microsec)","11.79","11.89","11.99","12.36"
    "procedure_call (microsec)","0.00","0.00","0.00","0.00"
    "select_on_200_tcp_fds (microsec)","11.10","10.81","11.09","11.12"
    "semaphore_latency (microsec)","1.41","1.35","1.41","2.34"
    "signal_handler_latency (microsec)","0.49","0.50","0.52","0.51"
    "signal_handler_overhead (microsec)","2.70","2.71","2.63","2.79"
    "tcp_ip_connection_cost_to_localhost (microsec)","33.74","33.74","34.32","34.76"
    "tcp_latency_using_localhost (microsec)","0.75","0.75","0.75","0.75"


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
    "dhrystone_per_mhz (DMIPS/MHz)","4.70","4.70","4.70","4.40"
    "dhrystone_per_second (DhrystoneP)","16666667.00","16666667.00","16666667.00","15384615.00"


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

Execute the benchmark with the following:

::

    linpack

.. csv-table::
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j784s4-evm: perf"

    "linpack (Kflops)","2549821.00","2490630.00","2453258.00","2422959.00"


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

    "assignment (Iterations)","30.50","30.59","30.78","30.49"
    "fourier (Iterations)","65182.00","65157.00","53653.00","53576.00"
    "fp_emulation (Iterations)","214.64","214.62","214.62","214.64"
    "huffman (Iterations)","2382.60","2377.40","2384.60","2383.20"
    "idea (Iterations)","7996.60","7996.00","7995.60","7996.80"
    "lu_decomposition (Iterations)","1351.50","1360.50","1360.60","1325.20"
    "neural_net (Iterations)","28.94","30.03","28.26","29.82"
    "numeric_sort (Iterations)","832.56","836.69","845.11","849.72"
    "string_sort (Iterations)","416.90","398.15","417.45","416.94"


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

    "add (MB/s)","5457.30","5345.80","6381.80","6236.70"
    "copy (MB/s)","4776.80","5618.40","6982.00","7105.10"
    "scale (MB/s)","4839.70","5479.20","7108.60","7119.70"
    "triad (MB/s)","5464.60","5312.40","6391.30","6235.50"


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

    "cjpeg-rose7-preset (workloads/)","29.67","81.97","82.64","81.97"
    "core (workloads/)","0.26","0.78","0.78","0.78"
    "coremark-pro ()","1034.87","2456.24","2476.54","2515.32"
    "linear_alg-mid-100x100-sp (workloads/)","27.12","79.87","80.13","81.43"
    "loops-all-mid-10k-sp (workloads/)","0.87","2.43","2.49","2.48"
    "nnet_test (workloads/)","1.26","3.54","3.61","3.54"
    "parser-125k (workloads/)","4.72","10.99","11.11","10.87"
    "radix2-big-64k (workloads/)","124.64","252.53","254.52","289.44"
    "sha-test (workloads/)","62.89","158.73","158.73","158.73"
    "zip-test (workloads/)","45.45","47.62","47.62","50.00"


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

    "4m-check (workloads/)","939.14","960.06","872.60","1040.37"
    "4m-check-reassembly (workloads/)","120.92","149.03","151.29","209.21"
    "4m-check-reassembly-tcp (workloads/)","92.25","102.88","98.81","121.36"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","40.57","44.64","41.87","37.13"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","2.69","2.72","2.66","4.91"
    "4m-cmykw2 (workloads/)","312.99","316.46","313.48","602.41"
    "4m-cmykw2-rotatew2 (workloads/)","58.48","63.16","59.29","52.40"
    "4m-reassembly (workloads/)","107.64","129.03","128.21","156.01"
    "4m-rotatew2 (workloads/)","70.32","74.18","71.07","44.39"
    "4m-tcp-mixed (workloads/)","280.70","280.70","266.67","275.86"
    "4m-x264w2 (workloads/)","2.75","2.78","2.73","5.08"
    "idct-4m (workloads/)","34.97","35.11","35.00","35.14"
    "idct-4mw1 (workloads/)","34.97","35.08","35.00","35.15"
    "ippktcheck-4m (workloads/)","924.56","939.14","872.60","1037.34"
    "ippktcheck-4mw1 (workloads/)","936.33","938.79","871.69","1033.06"
    "ipres-4m (workloads/)","155.60","179.64","166.48","209.21"
    "ipres-4mw1 (workloads/)","154.48","180.07","167.97","208.62"
    "md5-4m (workloads/)","45.87","48.33","45.81","47.53"
    "md5-4mw1 (workloads/)","45.43","48.92","45.58","47.66"
    "rgbcmyk-4m (workloads/)","163.00","163.80","163.13","164.20"
    "rgbcmyk-4mw1 (workloads/)","163.27","163.80","163.13","164.07"
    "rotate-4ms1 (workloads/)","52.25","55.07","51.60","55.07"
    "rotate-4ms1w1 (workloads/)","52.14","55.07","51.71","54.88"
    "rotate-4ms64 (workloads/)","52.85","55.68","52.36","55.31"
    "rotate-4ms64w1 (workloads/)","53.02","55.31","52.47","55.74"
    "x264-4mq (workloads/)","1.43","1.43","1.43","1.44"
    "x264-4mqw1 (workloads/)","1.42","1.44","1.42","1.43"


Table:  **Multibench**






Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","j7200-evm: boot time (sec)","j721e-idk-gw: boot time (sec)","j721s2-evm: boot time (sec)","j784s4-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","16.98 (min 16.86, max 17.06)","18.67 (min 18.52, max 18.79)","17.41 (min 17.10, max 17.78)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","4.16 (min 4.13, max 4.18)","4.83 (min 4.82, max 4.87)","5.13","6.04 (min 5.99, max 6.09)"

Table:  **Boot time MMC/SD**






ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64


.. csv-table::
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "11025","352792.00","0.19"
    "16000","511991.00","0.29"
    "22050","705578.00","0.27"
    "24000","705584.00","0.27"
    "32000","1023980.00","0.39"
    "44100","1411175.00","0.48"
    "48000","1535973.00","0.65"
    "88200","2822350.00","0.84"
    "96000","3071946.00","1.17"

Table:  **Audio Capture**


|


.. csv-table::
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "11025","352937.00","0.20"
    "16000","512202.00","0.26"
    "22050","705866.00","0.26"
    "24000","705872.00","0.29"
    "32000","1024401.00","0.38"
    "44100","1411754.00","0.48"
    "48000","1536605.00","0.57"
    "88200","2823510.00","0.78"
    "96000","3073209.00","0.46"

Table:  **Audio Playback**


|








Graphics SGX/RGX Driver
-------------------------





Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","j721e-idk-gw: Score","j721s2-evm: Score"

    "Glmark2-DRM","0.00","9.00"


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
    :header: "Command Used","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j784s4-evm: THROUGHPUT (Mbits/sec)","j784s4-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1284.85","63.07","1840.86","73.41","1858.87","70.58","1844.07","18.49"

Table: **CPSW TCP Bidirectional Throughput**

|



.. rubric::  TCP Bidirectional Throughput Interrupt Pacing
   :name: CPSW2g-tcp-bidirectional-throughput-interrupt-pacing

.. csv-table::
    :header: "Command Used","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j784s4-evm: THROUGHPUT (Mbits/sec)","j784s4-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1434.28","55.52","1852.99","33.77","1867.02","39.79","1871.41","8.15"

Table: **CPSW TCP Bidirectional Throughput Interrupt Pacing**

|



.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: Packets Per Second (kPPS)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: Packets Per Second (kPPS)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: Packets Per Second (kPPS)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j784s4-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j784s4-evm: THROUGHPUT (Mbits/sec)","j784s4-evm: Packets Per Second (kPPS)","j784s4-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","30.39","211.00","89.29","18.00","32.58","226.00","87.16","18.00","30.90","215.00","90.62","18.00","32.05","223.00","22.68"
    "128","82.00","142.94","218.00","90.68","82.00","149.33","228.00","87.95","82.00","28.73","44.00","18.40"
    "256","210.00","322.78","192.00","88.31","210.00","383.84","228.00","87.94","210.00","359.07","214.00","90.26"
    "1024","978.00","659.01","84.00","82.86","978.00","933.67","119.00","52.92","978.00","936.07","120.00","56.09"
    "1518","1472.00","955.74","81.00","65.04","1472.00","955.17","81.00","36.49","1472.00","957.00","81.00","40.96"

Table: **CPSW UDP Egress Throughput**
|



.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: Packets Per Second (kPPS)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: Packets Per Second (kPPS)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: Packets Per Second (kPPS)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.11","8.00","7.10","18.00","5.53","38.00","13.65","18.00","1.22","8.00","4.97"
    "128","82.00","10.23","16.00","6.22","82.00","21.71","33.00","12.60","82.00","5.25","8.00","6.54"
    "256","210.00","17.64","11.00","8.80","210.00","17.64","11.00","3.93","210.00","32.59","19.00","13.86"
    "1024","978.00","85.28","11.00","9.52","978.00","123.61","16.00","9.98","978.00","336.82","43.00","29.84"
    "1518","1472.00","44.75","4.00","4.60","1472.00","949.39","81.00","59.83","1472.00","361.47","31.00","25.00"


Table: **CPSW UDP Ingress Throughput (0% loss)**

|



.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: Packets Per Second (kPPS)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j7200-evm: Packet Loss %","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: Packets Per Second (kPPS)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: Packet Loss %","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: Packets Per Second (kPPS)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: Packet Loss %"

    "64","18.00","20.77","144.00","82.20","0.13","18.00","59.73","415.00","87.35","6.99","18.00","19.07","132.00","51.54","0.03"
    "128","82.00","262.90","401.00","91.43","8.63","82.00","277.41","423.00","92.34","5.73","82.00","110.74","169.00","83.04","0.05"
    "256","210.00","374.52","223.00","89.57","13.22","210.00","697.80","415.00","93.57","5.23","210.00","270.12","161.00","81.92","0.07"
    "1024","978.00","929.46","119.00","83.65","0.60","978.00","927.67","119.00","83.24","0.12","978.00","898.80","115.00","80.41","0.11"
    "1518","1472.00","956.42","81.00","86.29","0.04","1472.00","949.39","81.00","59.83","0.00","1472.00","949.61","81.00","67.41","0.03"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|









PCIe Driver
-------------------------

PCIe-ETH
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "TCP Window Size(Kbytes)","j7200-evm: Bandwidth (Mbits/sec)","j721e-idk-gw: Bandwidth (Mbits/sec)","j721s2-evm: Bandwidth (Mbits/sec)"

    "8","222.40","0.00"
    "16","222.40","0.00"
    "32","0.00","0.00"
    "64","567.20","0.00"
    "128","724.00","0.00","0.00"
    "256","800.00","0.00","0.00"

Table: **PCI Ethernet**





PCIe-NVMe-SSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^




J784S4-EVM
"""""""""""""""""""""""""""




.. csv-table::
    :header: "Buffer size (bytes)","j784s4-evm: Write EXT4 Throughput (Mbytes/sec)","j784s4-evm: Write EXT4 CPU Load (%)","j784s4-evm: Read EXT4 Throughput (Mbytes/sec)","j784s4-evm: Read EXT4 CPU Load (%)"

    "1m","1698.00","5.51","2461.00","2.61"
    "4m","1733.00","6.21","2460.00","1.80"
    "4k","184.00","12.61","285.00","12.55"
    "256k","2113.00","7.18","2455.00","4.25"



- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based
- Platform: Speed 8GT/s, Width x4
- SSD being used: INTEL OPTANE SSD 900P



J721E-IDK-GW
"""""""""""""""""""""""""""




.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","723.00","12.96","1523.00","6.40"
    "4m","722.00","12.27","1520.00","5.29"
    "4k","184.00","48.05","166.00","36.58"
    "256k","723.00","12.61","1520.00","11.65"



- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY



J7200-EVM
"""""""""""""""""""""""""""




.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","705.00","14.69","1527.00","6.85"
    "4m","704.00","13.82","1523.00","5.71"
    "4k","186.00","47.87","166.00","36.16"
    "256k","708.00","13.60","1524.00","11.72"



- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY



J721S2-EVM
"""""""""""""""""""""""""""




.. csv-table::
    :header: "Buffer size (bytes)","j721s2-evm: Write EXT4 Throughput (Mbytes/sec)","j721s2-evm: Write EXT4 CPU Load (%)","j721s2-evm: Read EXT4 Throughput (Mbytes/sec)","j721s2-evm: Read EXT4 CPU Load (%)"

    "1m","743.00","15.05","780.00","3.72"
    "4m","743.00","13.60","781.00","3.27"
    "4k","196.00","50.14","287.00","50.09"
    "256k","743.00","15.09","779.00","6.43"



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

    "50","238.09"
















UBoot QSPI/OSPI Driver
-------------------------




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","1537.54","37577.98"
    "800000","1539.85","39009.52"
    "1000000","1540.72","39766.99"
    "2000000","1541.66","40206.13"





J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","348.63","195047.62"
    "800000","350.55","248242.42"
    "1000000","353.19","277694.92"
    "2000000","354.63","300623.85"




J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "400000","383.77","204800.00"
    "800000","385.34","248242.42"
    "1000000","389.19","282482.76"
    "2000000","394.76","300623.85"



























UBoot UFS Driver
-------------------------
|


J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","97523.81","372363.64"
    "800000","95255.81","481882.35"
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


J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","56.20","1.53","314.00","1.75"
    "4m","56.00","1.31","306.00","1.12"
    "4k","54.90","25.36","55.90","23.71"
    "256k","56.30","1.66","314.00","3.26"

|



J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","58.80","1.46","175.00","0.97"
    "4m","59.20","1.33","175.00","0.87"
    "4k","48.60","22.90","56.70","23.76"
    "256k","58.90","1.68","174.00","2.08"

|



J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721s2-evm: Write EXT4 Throughput (Mbytes/sec)","j721s2-evm: Write EXT4 CPU Load (%)","j721s2-evm: Read EXT4 Throughput (Mbytes/sec)","j721s2-evm: Read EXT4 CPU Load (%)"

    "1m","56.30","1.58","314.00","1.67"
    "4m","56.30","1.35","292.00","1.24"
    "4k","59.10","29.79","56.30","25.55"
    "256k","56.30","1.71","314.00","3.45"

|



J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j784s4-evm: Write EXT4 Throughput (Mbytes/sec)","j784s4-evm: Write EXT4 CPU Load (%)","j784s4-evm: Read EXT4 Throughput (Mbytes/sec)","j784s4-evm: Read EXT4 CPU Load (%)"

    "1m","89.60","0.45","293.00","0.40"
    "4m","96.70","0.46","248.00","0.23"
    "4k","76.70","11.19","90.90","10.61"
    "256k","90.30","0.47","292.00","0.81"

|
























UBoot EMMC Driver
-------------------------
|


J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "2000000","56790.29","303407.41"
    "4000000","56938.31","309132.08"

|



J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "2000000","59041.44","173375.66"
    "4000000","58357.97","175699.73"

|



J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "2000000","57186.74","312076.19"
    "4000000","57690.14","319687.80"

|



J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j784s4-evm: Write Throughput (Kbytes/sec)","j784s4-evm: Read Throughput (Kbytes/sec)"

    "2000000","100207.95","282482.76"
    "4000000","101448.92","295207.21"

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

    "1m","19.40","0.73","87.00","0.75"
    "4m","19.60","0.61","87.00","0.67"
    "4k","5.13","3.18","16.60","7.40"
    "256k","18.20","0.79","84.50","1.28"

|








J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","18.30","0.60","43.50","0.52"
    "4m","18.00","0.51","43.40","0.36"
    "4k","4.89","2.80","13.70","5.81"
    "256k","18.00","0.78","43.00","0.60"

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

    "400000","17808.70","34420.17"
    "800000","18703.20","39766.99"
    "1000000","17925.60","43002.62"




J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","12603.08","71859.65"
    "800000","19412.32","81108.91"
    "1000000","22692.52","86687.83"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card




J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "400000","30117.65","62060.61"
    "800000","35008.55","74472.73"
    "1000000","18919.17","82331.66"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card




J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j784s4-evm: Write Throughput (Kbytes/sec)","j784s4-evm: Read Throughput (Kbytes/sec)"

    "400000","19412.32","56888.89"
    "800000","33300.81","70620.69"
    "1000000","24975.61","80313.73"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card


















|



USB Driver
-------------------------



USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^










.. csv-table::
    :header: "Number of Blocks","j721s2-evm: Throughput (MB/sec)","j784s4-evm: Throughput (MB/sec)"

    "150","30.30","41.10"

Table: **USBDEVICE HIGHSPEED SLAVE READ THROUGHPUT**

|
|



.. csv-table::
    :header: "Number of Blocks","j721s2-evm: Throughput (MB/sec)","j784s4-evm: Throughput (MB/sec)"

    "150","29.50","31.30"

Table: **USBDEVICE HIGHSPEED SLAVE WRITE THROUGHPUT**

|
|









CRYPTO Driver
-------------------------






IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","j721e-idk-gw: Throughput (Mbps)","j721e-idk-gw: Packets/Sec","j721e-idk-gw: CPU Load"

    "3des","174.90","15.00","28.19"
    "aes128","724.30","64.00","57.65"
    "aes192","77.30","6.00","101.88"
    "aes256","568.60","50.00","82.50"




DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.

