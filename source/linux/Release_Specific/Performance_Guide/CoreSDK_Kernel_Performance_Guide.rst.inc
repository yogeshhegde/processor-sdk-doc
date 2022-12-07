.. http://processors.wiki.ti.com/index.php/CoreSDK_Linux_Kernel_Performance_Guide


======================================
 Linux 08.05.00 Performance Guide
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
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "af_unix_sock_stream_latency (microsec)","19.66","21.07","19.69"
    "af_unix_socket_stream_bandwidth (MBs)","1542.79","3084.84","3057.47"
    "bw_file_rd-io-1mb (MB/s)","1345.64","2711.99","2903.28"
    "bw_file_rd-o2c-1mb (MB/s)","829.02","1396.16","1191.69"
    "bw_mem-bcopy-16mb (MB/s)","1515.44","2903.28","3807.71"
    "bw_mem-bcopy-1mb (MB/s)","1484.23","4806.80","4728.58"
    "bw_mem-bcopy-2mb (MB/s)","1426.28","4031.58","4017.68"
    "bw_mem-bcopy-4mb (MB/s)","1488.10","3872.97","3833.62"
    "bw_mem-bcopy-8mb (MB/s)","1516.88","3147.95","3790.27"
    "bw_mem-bzero-16mb (MB/s)","1142.12","9605.28","10893.62"
    "bw_mem-bzero-1mb (MB/s)","1535.30 (min 1484.23, max 1586.36)","8862.44 (min 4806.80, max 12918.07)","8550.68 (min 4728.58, max 12372.78)"
    "bw_mem-bzero-2mb (MB/s)","1325.14 (min 1223.99, max 1426.28)","8235.17 (min 4031.58, max 12438.75)","7937.32 (min 4017.68, max 11856.95)"
    "bw_mem-bzero-4mb (MB/s)","1313.53 (min 1138.95, max 1488.10)","7958.32 (min 3872.97, max 12043.66)","7424.43 (min 3833.62, max 11015.24)"
    "bw_mem-bzero-8mb (MB/s)","1329.87 (min 1142.86, max 1516.88)","7361.64 (min 3147.95, max 11575.33)","7363.35 (min 3790.27, max 10936.43)"
    "bw_mem-cp-16mb (MB/s)","964.90","1586.67","2181.62"
    "bw_mem-cp-1mb (MB/s)","1228.07 (min 895.26, max 1560.87)","7349.97 (min 1727.78, max 12972.15)","7990.94 (min 2476.19, max 13505.69)"
    "bw_mem-cp-2mb (MB/s)","1050.46 (min 922.37, max 1178.55)","6975.36 (min 1526.14, max 12424.57)","7086.94 (min 2211.69, max 11962.18)"
    "bw_mem-cp-4mb (MB/s)","1034.84 (min 928.61, max 1141.06)","6838.43 (min 1605.14, max 12071.72)","6583.48 (min 2143.62, max 11023.33)"
    "bw_mem-cp-8mb (MB/s)","1048.01 (min 956.25, max 1139.76)","6562.73 (min 1501.78, max 11623.68)","6552.89 (min 2161.87, max 10943.91)"
    "bw_mem-fcp-16mb (MB/s)","1527.30","3021.15","3602.39"
    "bw_mem-fcp-1mb (MB/s)","1530.52 (min 1474.68, max 1586.36)","8869.75 (min 4821.43, max 12918.07)","8470.33 (min 4567.88, max 12372.78)"
    "bw_mem-fcp-2mb (MB/s)","1327.18 (min 1223.99, max 1430.36)","8155.32 (min 3871.88, max 12438.75)","7796.94 (min 3736.92, max 11856.95)"
    "bw_mem-fcp-4mb (MB/s)","1319.10 (min 1138.95, max 1499.25)","7907.20 (min 3770.74, max 12043.66)","7335.78 (min 3656.31, max 11015.24)"
    "bw_mem-fcp-8mb (MB/s)","1335.23 (min 1142.86, max 1527.59)","7359.58 (min 3143.83, max 11575.33)","7273.54 (min 3610.65, max 10936.43)"
    "bw_mem-frd-16mb (MB/s)","5557.49","4827.27","4674.26"
    "bw_mem-frd-1mb (MB/s)","3821.52 (min 1474.68, max 6168.36)","5492.10 (min 4821.43, max 6162.77)","4883.42 (min 4567.88, max 5198.96)"
    "bw_mem-frd-2mb (MB/s)","3495.02 (min 1430.36, max 5559.67)","4825.07 (min 3871.88, max 5778.26)","4458.18 (min 3736.92, max 5179.43)"
    "bw_mem-frd-4mb (MB/s)","3518.27 (min 1499.25, max 5537.29)","4754.81 (min 3770.74, max 5738.88)","4187.84 (min 3656.31, max 4719.37)"
    "bw_mem-frd-8mb (MB/s)","3543.99 (min 1527.59, max 5560.38)","4257.38 (min 3143.83, max 5370.93)","4141.09 (min 3610.65, max 4671.53)"
    "bw_mem-fwr-16mb (MB/s)","1140.98","9635.65","10865.87"
    "bw_mem-fwr-1mb (MB/s)","3864.62 (min 1560.87, max 6168.36)","9567.46 (min 6162.77, max 12972.15)","9352.33 (min 5198.96, max 13505.69)"
    "bw_mem-fwr-2mb (MB/s)","3369.11 (min 1178.55, max 5559.67)","9101.42 (min 5778.26, max 12424.57)","8570.81 (min 5179.43, max 11962.18)"
    "bw_mem-fwr-4mb (MB/s)","3339.18 (min 1141.06, max 5537.29)","8905.30 (min 5738.88, max 12071.72)","7871.35 (min 4719.37, max 11023.33)"
    "bw_mem-fwr-8mb (MB/s)","3350.07 (min 1139.76, max 5560.38)","8497.31 (min 5370.93, max 11623.68)","7807.72 (min 4671.53, max 10943.91)"
    "bw_mem-rd-16mb (MB/s)","5069.71","5112.64","5422.81"
    "bw_mem-rd-1mb (MB/s)","507.69 (min 1.00, max 1014.37)","6503.82 (min 4145.28, max 8862.36)","6939.71 (min 4576.24, max 9303.17)"
    "bw_mem-rd-2mb (MB/s)","2945.03 (min 762.87, max 5127.19)","3914.84 (min 1317.52, max 6512.16)","4735.63 (min 3009.22, max 6462.04)"
    "bw_mem-rd-4mb (MB/s)","2902.36 (min 745.99, max 5058.72)","3798.64 (min 1278.16, max 6319.12)","3949.08 (min 2347.42, max 5550.74)"
    "bw_mem-rd-8mb (MB/s)","2910.35 (min 745.36, max 5075.34)","3560.55 (min 1257.07, max 5864.03)","3844.14 (min 2268.22, max 5420.05)"
    "bw_mem-rdwr-16mb (MB/s)","745.92","1933.30","2225.00"
    "bw_mem-rdwr-1mb (MB/s)","942.36 (min 895.26, max 989.45)","2628.60 (min 1727.78, max 3529.41)","3465.47 (min 2476.19, max 4454.74)"
    "bw_mem-rdwr-2mb (MB/s)","845.16 (min 767.95, max 922.37)","1481.46 (min 1436.78, max 1526.14)","2591.18 (min 2211.69, max 2970.66)"
    "bw_mem-rdwr-4mb (MB/s)","838.77 (min 748.92, max 928.61)","1991.10 (min 1605.14, max 2377.06)","2232.80 (min 2143.62, max 2321.98)"
    "bw_mem-rdwr-8mb (MB/s)","851.16 (min 746.06, max 956.25)","1952.09 (min 1501.78, max 2402.40)","2203.27 (min 2161.87, max 2244.67)"
    "bw_mem-wr-16mb (MB/s)","743.25","1817.36","2238.08"
    "bw_mem-wr-1mb (MB/s)","1001.91 (min 989.45, max 1014.37)","3837.35 (min 3529.41, max 4145.28)","4515.49 (min 4454.74, max 4576.24)"
    "bw_mem-wr-2mb (MB/s)","765.41 (min 762.87, max 767.95)","1377.15 (min 1317.52, max 1436.78)","2989.94 (min 2970.66, max 3009.22)"
    "bw_mem-wr-4mb (MB/s)","747.46 (min 745.99, max 748.92)","1827.61 (min 1278.16, max 2377.06)","2334.70 (min 2321.98, max 2347.42)"
    "bw_mem-wr-8mb (MB/s)","745.71 (min 745.36, max 746.06)","1829.74 (min 1257.07, max 2402.40)","2256.45 (min 2244.67, max 2268.22)"
    "bw_mmap_rd-mo-1mb (MB/s)","6324.11","9210.27","8987.42"
    "bw_mmap_rd-o2c-1mb (MB/s)","1098.90","1499.75","1324.75"
    "bw_pipe (MB/s)","501.71","953.89","923.31"
    "bw_unix (MB/s)","1542.79","3084.84","3057.47"
    "lat_connect (us)","50.69","40.02","39.64"
    "lat_ctx-2-128k (us)","4.00","2.99","2.92"
    "lat_ctx-2-256k (us)","7.41","2.60","2.66"
    "lat_ctx-4-128k (us)","4.21","3.19","3.28"
    "lat_ctx-4-256k (us)","8.08","2.29","2.41"
    "lat_fs-0k (num_files)","562.00","551.00","565.00"
    "lat_fs-10k (num_files)","158.00","218.00","215.00"
    "lat_fs-1k (num_files)","262.00","292.00","326.00"
    "lat_fs-4k (num_files)","292.00","332.00","339.00"
    "lat_mem_rd-stride128-sz1000k (ns)","17.56","12.16","13.09"
    "lat_mem_rd-stride128-sz125k (ns)","5.16","5.16","5.16"
    "lat_mem_rd-stride128-sz250k (ns)","5.18","5.16","5.16"
    "lat_mem_rd-stride128-sz31k (ns)","3.64","3.61","3.22"
    "lat_mem_rd-stride128-sz50 (ns)","2.00","2.00","2.00"
    "lat_mem_rd-stride128-sz500k (ns)","12.08","5.17","5.33"
    "lat_mem_rd-stride128-sz62k (ns)","4.97","5.16","5.16"
    "lat_mmap-1m (us)","30.00","27.00","21.00"
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
    "lat_ops-int64-div (ns)","3.00","3.00","3.01"
    "lat_ops-int64-mod (ns)","5.68","5.67","5.67"
    "lat_pagefault (us)","0.66","0.46","0.48"
    "lat_pipe (us)","10.85","11.00","10.84"
    "lat_proc-exec (us)","784.57","476.90","515.73"
    "lat_proc-fork (us)","637.67","406.08","443.00"
    "lat_proc-proccall (us)","0.00","0.00","0.00"
    "lat_select (us)","11.86","11.85","11.85"
    "lat_sem (us)","1.59","1.54","1.54"
    "lat_sig-catch (us)","2.48","2.54","2.52"
    "lat_sig-install (us)","0.48","0.48","0.48"
    "lat_sig-prot (us)","0.41","0.43","0.38"
    "lat_syscall-fstat (us)","0.66","0.68","0.68"
    "lat_syscall-null (us)","0.34","0.34","0.34"
    "lat_syscall-open (us)","162.79","140.23","124.58"
    "lat_syscall-read (us)","0.44","0.46","0.42"
    "lat_syscall-stat (us)","1.45","1.50","1.50"
    "lat_syscall-write (us)","0.40","0.44","0.42"
    "lat_tcp (us)","0.73","0.74","0.72"
    "lat_unix (us)","19.66","21.07","19.69"
    "latency_for_0.50_mb_block_size (nanosec)","12.08","5.17","5.33"
    "latency_for_1.00_mb_block_size (nanosec)","8.78 (min 0.00, max 17.56)","6.08 (min 0.00, max 12.16)","6.55 (min 0.00, max 13.09)"
    "pipe_bandwidth (MBs)","501.71","953.89","923.31"
    "pipe_latency (microsec)","10.85","11.00","10.84"
    "procedure_call (microsec)","0.00","0.00","0.00"
    "select_on_200_tcp_fds (microsec)","11.86","11.85","11.85"
    "semaphore_latency (microsec)","1.59","1.54","1.54"
    "signal_handler_latency (microsec)","0.48","0.48","0.48"
    "signal_handler_overhead (microsec)","2.48","2.54","2.52"
    "tcp_ip_connection_cost_to_localhost (microsec)","50.69","40.02","39.64"
    "tcp_latency_using_localhost (microsec)","0.73","0.74","0.72"


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

    "linpack (Kflops)","2648156.00","2576611.00","2647135.00"


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

    "assignment (Iterations)","29.64","29.73","29.68"
    "fourier (Iterations)","55195.00","55050.00","55086.00"
    "fp_emulation (Iterations)","249.93","250.08","250.08"
    "huffman (Iterations)","2428.50","2425.60","2431.00"
    "idea (Iterations)","7993.30","7997.20","7996.80"
    "lu_decomposition (Iterations)","1411.50","1411.50","1430.30"
    "neural_net (Iterations)","27.25","27.11","26.10"
    "numeric_sort (Iterations)","867.84","869.35","875.41"
    "string_sort (Iterations)","407.10","429.12","430.68"


Table:  **NBench Benchmarks**





CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.


.. csv-table::
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "cjpeg-rose7-preset (workloads/)","81.97","82.64","82.64"
    "core (workloads/)","0.78","0.78","0.78"
    "coremark-pro ()","2154.95","2506.57","2478.81"
    "linear_alg-mid-100x100-sp (workloads/)","80.78","81.83","80.65"
    "loops-all-mid-10k-sp (workloads/)","2.20","2.47","2.48"
    "nnet_test (workloads/)","3.62","3.63","3.86"
    "parser-125k (workloads/)","9.09","11.90","11.76"
    "radix2-big-64k (workloads/)","105.21","260.01","229.78"
    "sha-test (workloads/)","158.73","158.73","156.25"
    "zip-test (workloads/)","45.45","47.62","47.62"


Table:  **CoreMarkPro**



.. csv-table::
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "cjpeg-rose7-preset (workloads/)","161.29","163.93","161.29"
    "core (workloads/)","1.55","1.55","1.55"
    "coremark-pro ()","3260.79","4477.19","4496.34"
    "linear_alg-mid-100x100-sp (workloads/)","158.73","162.34","160.26"
    "loops-all-mid-10k-sp (workloads/)","3.06","3.96","3.79"
    "nnet_test (workloads/)","7.14","7.13","7.32"
    "parser-125k (workloads/)","7.49","22.73","20.62"
    "radix2-big-64k (workloads/)","75.61","272.18","326.69"
    "sha-test (workloads/)","312.50","312.50","312.50"
    "zip-test (workloads/)","76.92","90.91","90.91"


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

    "4m-check (workloads/)","787.65","1022.08","978.86"
    "4m-check-reassembly (workloads/)","105.93","149.93","156.50"
    "4m-check-reassembly-tcp (workloads/)","80.39","99.60","95.06"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","33.41","45.28","42.83"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","2.56","2.74","2.70"
    "4m-cmykw2 (workloads/)","302.12","314.96","311.53"
    "4m-cmykw2-rotatew2 (workloads/)","50.21","61.54","57.86"
    "4m-reassembly (workloads/)","93.11","129.70","123.92"
    "4m-rotatew2 (workloads/)","55.49","74.35","71.12"
    "4m-tcp-mixed (workloads/)","258.07","280.70","246.15"
    "4m-x264w2 (workloads/)","2.62","2.79","2.77"
    "idct-4m (workloads/)","34.70","35.00","34.94"
    "idct-4mw1 (workloads/)","34.71","35.00","34.89"
    "ippktcheck-4m (workloads/)","782.96","1023.75","978.09"
    "ippktcheck-4mw1 (workloads/)","784.44","1022.91","952.74"
    "ipres-4m (workloads/)","143.13","204.64","182.48"
    "ipres-4mw1 (workloads/)","140.71","206.90","182.70"
    "md5-4m (workloads/)","39.54","51.39","47.87"
    "md5-4mw1 (workloads/)","40.39","51.87","48.69"
    "rgbcmyk-4m (workloads/)","161.94","162.87","162.60"
    "rgbcmyk-4mw1 (workloads/)","162.08","162.87","162.60"
    "rotate-4ms1 (workloads/)","50.56","56.24","53.08"
    "rotate-4ms1w1 (workloads/)","51.02","56.37","53.30"
    "rotate-4ms64 (workloads/)","51.60","56.75","53.71"
    "rotate-4ms64w1 (workloads/)","50.81","56.82","53.53"
    "x264-4mq (workloads/)","1.41","1.45","1.43"
    "x264-4mqw1 (workloads/)","1.40","1.44","1.43"


Table:  **Multibench**


 
 


Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","j7200-evm: boot time (sec)","j721e-idk-gw: boot time (sec)","j721s2-evm: boot time (sec)","j784s4-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","18.00 (min 17.60, max 18.26)","24.15 (min 23.56, max 24.99)","17.63 (min 17.52, max 17.71)","22.26 (min 21.85, max 22.78)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","3.97 (min 3.92, max 3.98)","8.91 (min 8.89, max 8.94)","4.55 (min 4.53, max 4.58)","7.54 (min 7.40, max 7.91)"

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
    "22050","705600.00","0.44"
    "24000","705600.00","0.45"
    "32000","1023999.00","0.31"
    "44100","1411199.00","0.66"
    "48000","1535999.00","0.38"
    "88200","2822396.00","1.06"
    "96000","3071995.00","0.57"

Table:  **Audio Capture**


|


.. csv-table::
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)","j721s2-evm: Throughput (bits/sec)","j721s2-evm: CPU Load (%)"

    "11025","352945.00","0.27","282350.00","0.50"
    "16000","512211.00","0.27","409761.00","0.50"
    "22050","705891.00","0.43","564698.00","0.59"
    "24000","705891.00","0.47","614633.00","0.65"
    "32000","1024422.00","0.32","819530.00","0.68"
    "44100","1411781.00","0.66","1129322.00","0.84"
    "48000","1536632.00","0.39","1229150.00","0.85"
    "88200","2823560.00","0.56","1229146.00","0.83"
    "96000","3073263.00","0.57","1229150.00","0.89"

Table:  **Audio Playback**
 

|

 



 


Graphics SGX/RGX Driver
-------------------------
 


GFXBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Run GFXBench and capture performance reported (Score and Display rate in fps). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","j721e-idk-gw: Score","j721e-idk-gw: Fps","j721s2-evm: Score","j721s2-evm: Fps","j784s4-evm: Score","j784s4-evm: Fps"

    " GFXBench 3.x gl_manhattan_off","1249.14","20.15"
    " GFXBench 3.x gl_trex_off","1537.90","27.46"
    " GFXBench 4.x gl_4_off","428.67","7.25","260.87","4.41"
    " GFXBench 5.x gl_5_high_off","182.08","2.83","113.96","1.77","107.69","1.67"


Table:  **GFXBench**



Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","j721e-idk-gw: Score","j721s2-evm: Score","j784s4-evm: Score"

    "Glmark2-DRM","9.00","9.00"
    "Glmark2-Wayland","790.00","879.00","768.00"


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

- CPSW2g: AM65x, J7200, J721e, J721S2, J784S4
- CPSW3g: AM64x


.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1407.98","61.25","1845.46","72.32","1857.42","72.82"

Table: **CPSW TCP Bidirectional Throughput**
|



.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","32.06","92.89","18.00","22.66","82.03","18.00","30.41","93.25"
    "128","82.00","120.71","89.73","82.00","133.33","89.43"
    "256","210.00","387.25","92.62","210.00","310.17","91.50","210.00","200.80","65.92"
    "512","466.00","873.69","92.67","466.00","557.77","74.06"
    "1024","978.00","495.71","32.52","978.00","685.41","50.13","978.00","780.54","50.43"
    "1518","1472.00","956.84","47.60","1472.00","763.94","37.55","1472.00","956.89","40.32"

Table: **CPSW UDP Egress Throughput**
|



.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","9.42","35.89","18.00","5.14","12.82","18.00","14.96","50.79"
    "128","82.00","45.59","39.78","82.00","78.32","32.87","82.00","91.71","71.35"
    "256","210.00","66.53","20.43","210.00","178.24","30.89","210.00","282.75","73.30"
    "1024","978.00","228.46","19.46","978.00","474.78","42.17","978.00","496.82","38.08"
    "1518","1472.00","949.84","58.19","1472.00","954.12","64.48"


Table: **CPSW UDP Ingress Throughput (0% loss)**

|



.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j7200-evm: Packet Loss %","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: Packet Loss %","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: Packet Loss %"

    "64","18.00","22.90","73.00","0.03","18.00","54.44","81.94","17.46","18.00","20.29","68.53","0.01"
    "128","82.00","96.88","71.85","8.20","82.00","251.74","84.76","15.43","82.00","91.71","71.35","0.00"
    "256","210.00","374.43","80.52","3.91","210.00","630.64","87.14","14.53","210.00","282.75","73.30","0.00"
    "1024","978.00","934.69","81.03","0.01","978.00","474.78","42.17","0.00","978.00","450.35","58.93","51.87"
    "1518","1472.00","949.84","58.19","0.00","1472.00","954.12","64.48","0.00"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|
 
 


CPSW5g/CPSW9g Virtual Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- CPSW5g: J7200
- CPSW9g: J721e, J784S4


.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW9g-tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.1.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.1.1 -j -c -C -l 60 -t TCP_MAERTS","1862.32","75.34"

Table: **CPSW9g Virtual Ethernet Driver - TCP Bidirectional Throughput**
|




.. rubric::  UDP Throughput 
   :name: CPSW9g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","19.28","75.59"
    "128","82.00","48.79","50.33"
    "256","210.00","226.40","73.40"
    "512","466.00","464.56","71.08"
    "1024","978.00","576.91","51.20"
    "1280","1234.00","723.57","50.36"
    "1518","1472.00","765.54","48.66"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Egress Throughput**
|



.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.32","4.65"
    "128","82.00","7.61","6.05"
    "256","210.00","23.02","7.06"
    "512","466.00","54.43","7.52"
    "1024","978.00","86.06","5.30"
    "1280","1234.00","135.24","11.49"
    "1518","1472.00","487.52","31.82"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Ingress Throughput(0% loss)**

|




.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: Packet Loss %"

    "64","18.00","42.59","72.38","31.28"
    "128","82.00","192.78","74.37","31.29"
    "256","210.00","486.16","76.28","29.15"
    "512","466.00","873.65","73.50","0.24"
    "1024","978.00","935.33","73.81","0.15"
    "1280","1234.00","855.61","67.84","9.86"
    "1518","1472.00","956.94","63.59","0.01"

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

    "1m","706.00","12.95","1523.00","6.67"
    "4m","708.00","12.32","1523.00","5.71"
    "4k","115.00","36.46","166.00","35.72"
    "256k","707.00","12.28","1519.00","11.89"

 

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY
 


J7200-EVM
"""""""""""""""""""""""""""




.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","719.00","18.09","1527.00","10.72"
    "4m","715.00","16.70","1527.00","8.42"
    "4k","172.00","48.88","153.00","37.36"
    "256k","720.00","22.35","1524.00","14.55"

 

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

    "102400","0.57 (min 0.45, max 1.02)","22.10 (min 21.29, max 22.78)","32.31","8.33"
    "262144","0.44 (min 0.34, max 0.48)","22.29 (min 21.92, max 22.63)","31.98","0.00"
    "524288","0.44 (min 0.34, max 0.48)","23.19 (min 22.11, max 24.20)","31.84","14.29"
    "1048576","0.44 (min 0.34, max 0.47)","22.20 (min 20.86, max 23.47)","31.64","8.33"




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

    "102400","0.17 (min 0.12, max 0.26)","41.67 (min 40.19, max 42.32)","73.81","57.14"
    "262144","0.14 (min 0.11, max 0.18)","41.75 (min 40.70, max 42.30)","71.74","40.00"
    "524288","0.14 (min 0.11, max 0.18)","42.53 (min 42.17, max 42.99)","73.89","25.00"
    "1048576","0.14 (min 0.11, max 0.18)","42.02 (min 41.28, max 42.76)","72.76","20.00"




RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","j7200-evm: Raw Read Throughput (Mbytes/sec)"

    "50","178.57"

 
 

 

 

 

 
 

 


UBoot QSPI/OSPI Driver
-------------------------




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","1556.23","37577.98"
    "800000","1558.30","39009.52"
    "1000000","1559.34","39766.99"
    "2000000","1559.12","40206.13"





J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","394.42","195047.62"
    "800000","398.48","240941.18"
    "1000000","399.41","277694.92"
    "2000000","404.26","300623.85"




J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "400000","379.79","204800.00"
    "800000","377.04","248242.42"
    "1000000","376.32","282482.76"
    "2000000","374.37","300623.85"



















 
 

 

 


UBoot UFS Driver
-------------------------
|


J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","91022.22","372363.64"
    "800000","97523.81","481882.35"
    "1000000","93622.86","528516.13"

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

    "1m","60.10","1.60","174.00","1.15"
    "4m","60.10","1.40","174.00","0.93"
    "4k","49.40","20.97","56.20","21.13"
    "256k","60.10","1.72","173.00","2.11"

|



J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721s2-evm: Write EXT4 Throughput (Mbytes/sec)","j721s2-evm: Write EXT4 CPU Load (%)","j721s2-evm: Read EXT4 Throughput (Mbytes/sec)","j721s2-evm: Read EXT4 CPU Load (%)"

    "1m","44.60","1.59","299.00","1.69"
    "4m","44.90","1.38","299.00","1.42"
    "4k","5.23","3.06","36.00","15.51"
    "256k","35.90","1.46","282.00","3.14"

|



J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j784s4-evm: Write EXT4 Throughput (Mbytes/sec)","j784s4-evm: Write EXT4 CPU Load (%)","j784s4-evm: Read EXT4 Throughput (Mbytes/sec)","j784s4-evm: Read EXT4 CPU Load (%)"

    "1m","57.30","2.40","306.00","3.03"
    "4m","57.40","2.26","304.00","2.73"
    "4k","33.90","17.60","42.70","17.68"
    "256k","57.80","2.76","299.00","4.75"

|


 

 

 

 











 
 


UBoot EMMC Driver
-------------------------
|


J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "2000000","59254.97","292571.43"
    "4000000","60346.22","312076.19"

|



J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "2000000","60235.29","173375.66"
    "4000000","59254.97","177124.32"

|



J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "2000000","59362.32","292571.43"
    "4000000","60794.06","321254.90"

|



J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j784s4-evm: Write Throughput (Kbytes/sec)","j784s4-evm: Read Throughput (Kbytes/sec)"

    "2000000","59254.97","83591.84"
    "4000000","60014.65","84453.61"

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

    "1m","19.90","1.15","87.00","1.56"
    "4m","19.80","1.14","87.50","1.11"
    "4k","5.00","5.25","16.70","10.65"
    "256k","19.30","1.67","84.80","2.60"

|



J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721s2-evm: Write EXT4 Throughput (Mbytes/sec)","j721s2-evm: Write EXT4 CPU Load (%)","j721s2-evm: Read EXT4 Throughput (Mbytes/sec)","j721s2-evm: Read EXT4 CPU Load (%)"

    "1m","19.40","0.89","43.80","0.76"
    "4m","17.60","0.76","42.20","0.65"
    "4k","4.80","3.31","14.10","6.96"
    "256k","18.50","1.14","43.30","0.98"

|






J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","19.30","0.79","43.40","0.67"
    "4m","19.50","0.81","43.30","0.58"
    "4k","4.97","3.05","13.70","5.82"
    "256k","18.80","0.87","42.80","0.84"

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

    "400000","15398.50","21903.74"
    "800000","18875.58","22567.49"
    "1000000","16499.50","23043.60"




J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","15753.85","80313.73"
    "800000","22443.84","86231.58"
    "1000000","15086.56","89530.05"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card




J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "400000","13884.75","40156.86"
    "800000","18450.45","42666.67"
    "1000000","14867.51","44043.01"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card




J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j784s4-evm: Write Throughput (Kbytes/sec)","j784s4-evm: Read Throughput (Kbytes/sec)"

    "400000","18618.18","21787.23"
    "800000","20844.78","22755.56"
    "1000000","20739.24","23141.24"


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

    "1m","409.00","8.59","412.00","2.70"
    "4m","414.00","7.31","412.00","2.53"
    "4k","61.30","29.22","61.50","28.29"
    "256k","386.00","10.65","408.00","4.33"

|








 

|
 


USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^










.. csv-table::
    :header: "Number of Blocks","j721e-idk-gw: Throughput (MB/sec)","j721s2-evm: Throughput (MB/sec)"

    "150","39.70","31.60"

Table: **USBDEVICE HIGHSPEED SLAVE READ THROUGHPUT**

|
|



.. csv-table::
    :header: "Number of Blocks","j721e-idk-gw: Throughput (MB/sec)","j721s2-evm: Throughput (MB/sec)"

    "150","38.10","30.20"

Table: **USBDEVICE HIGHSPEED SLAVE WRITE THROUGHPUT**

|
|




 
 
 


CRYPTO Driver
-------------------------


OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","j721s2-evm: throughput (KBytes/Sec)","j784s4-evm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","46339.75","19011.24"
    "aes-128-cbc","16","911.39","330.79"
    "aes-128-cbc","16384","184188.93","135905.28"
    "aes-128-cbc","256","14008.75","5298.94"
    "aes-128-cbc","64","3564.10","1328.17"
    "aes-128-cbc","8192","150544.38","93620.91"
    "aes-192-cbc","1024","45462.19","20230.49"
    "aes-192-cbc","16","906.25","319.14"
    "aes-192-cbc","16384","177192.96","132027.73"
    "aes-192-cbc","256","14049.54","5423.96"
    "aes-192-cbc","64","3625.28","1428.05"
    "aes-192-cbc","8192","145164.97","92231.00"
    "aes-256-cbc","1024","44661.08","19661.48"
    "aes-256-cbc","16","911.23","339.93"
    "aes-256-cbc","16384","165549.40","121050.45"
    "aes-256-cbc","256","13967.27","5173.16"
    "aes-256-cbc","64","3688.81","1310.83"
    "aes-256-cbc","8192","138179.93","87539.71"
    "des-cbc","1024","47462.06","44314.28"
    "des-cbc","16","10546.76","5121.30"
    "des-cbc","16384","49829.21","49233.92"
    "des-cbc","256","40634.37","32683.86"
    "des-cbc","64","26056.45","16341.01"
    "des-cbc","8192","49684.48","48807.94"
    "des3","1024","40402.60","18732.71"
    "des3","16","933.46","335.41"
    "des3","16384","96332.46","79751.85"
    "des3","256","13476.78","5220.95"
    "des3","64","3651.01","1305.00"
    "des3","8192","87441.41","64170.67"
    "md5","1024","89550.51","34099.20"
    "md5","16","1925.00","608.87"
    "md5","16384","261991.08","192976.21"
    "md5","256","28524.12","9483.35"
    "md5","64","7544.38","2427.63"
    "md5","8192","231555.07","147043.67"
    "sha1","1024","54630.74","21438.81"
    "sha1","16","932.11","340.05"
    "sha1","16384","459494.74","233242.62"
    "sha1","256","14710.02","5454.08"
    "sha1","64","3729.05","1367.02"
    "sha1","8192","306449.07","137732.10"
    "sha224","1024","101343.23","36327.42"
    "sha224","16","1805.74","601.92"
    "sha224","16384","593177.26","345199.96"
    "sha224","256","28659.63","9234.86"
    "sha224","64","7267.26","2325.74"
    "sha224","8192","447209.47","219583.83"
    "sha256","1024","54692.52","19995.31"
    "sha256","16","905.67","322.45"
    "sha256","16384","448872.45","229457.92"
    "sha256","256","14230.19","5106.18"
    "sha256","64","3597.63","1279.25"
    "sha256","8192","302268.42","133373.95"
    "sha384","1024","68318.55","32282.62"
    "sha384","16","1715.40","623.87"
    "sha384","16384","158504.28","132797.78"
    "sha384","256","23644.42","9216.51"
    "sha384","64","6857.26","2483.43"
    "sha384","8192","145604.61","109049.17"
    "sha512","1024","43713.54","19493.89"
    "sha512","16","908.63","342.44"
    "sha512","16384","146817.02","112252.25"
    "sha512","256","13383.34","5348.95"
    "sha512","64","3639.40","1381.55"
    "sha512","8192","126831.27","83749.55"


|
|



.. csv-table::
    :header: "Algorithm","j721s2-evm: CPU Load","j784s4-evm: CPU Load"

    "aes-128-cbc","35.00","44.00"
    "aes-192-cbc","35.00","42.00"
    "aes-256-cbc","34.00","44.00"
    "des-cbc","99.00","98.00"
    "des3","32.00","46.00"
    "md5","99.00","98.00"
    "sha1","99.00","98.00"
    "sha224","99.00","98.00"
    "sha256","99.00","98.00"
    "sha384","99.00","98.00"
    "sha512","99.00","98.00"

 

Listed for each algorithm are the code snippets used to run each
  benchmark test.

::
    time -v openssl speed -elapsed -evp aes-128-cbc

 




IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","j7200-evm: Throughput (Mbps)","j7200-evm: Packets/Sec","j7200-evm: CPU Load","j721e-idk-gw: Throughput (Mbps)","j721e-idk-gw: Packets/Sec","j721e-idk-gw: CPU Load"

    "3des","197.20","17.00","48.90","31.20","2.00","19.35"
    "aes128","449.30","40.00","57.00","0.00","0.00","104.79"
    "aes192","445.00","39.00","56.74","0.00","0.00","78.53"
    "aes256","445.60","39.00","57.60","0.10","0.00","81.30"

 
 

DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.

