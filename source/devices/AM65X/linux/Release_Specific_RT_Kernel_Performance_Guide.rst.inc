..  http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_RT_Kernel_Performance_Guide

..  http://lcpdresults.itg.ti.com/LCPD/RT-linux/performance/publish/data/07.03.00/am654x-evm/rst/

.. rubric::  **Read This First**
   :name: read-this-first-rt-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+---------------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                         |
+================+=====================================================================================================================+
| AM65x EVM      | AM65x Evaluation Module rev 1.0 with ARM running at 800MHz, DDR4-2400 (1600 MT/S), TMDX654GPEVM                     |
+----------------+---------------------------------------------------------------------------------------------------------------------+

Table:  Evaluation Modules

|

.. rubric::  About This Manual
   :name: about-this-manual-rt-kernel-perf-guide

This document provides performance data for each of the device drivers
which are part of the Process SDK Linux package. This document should be
used in conjunction with release notes and user guides provided with the
Process SDK Linux package for information on specific issues present
with drivers included in a particular release.

.. rubric::  If You Need Assistance
   :name: if-you-need-assistance-rt-kernel-perf-guide

For further information or to report any problems, contact
http://community.ti.com/ or http://support.ti.com/

System Benchmarks
-------------------------

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
    :header: "Benchmarks","am654x-evm: perf"

    "af_unix_sock_stream_latency (microsec)","52.76"
    "af_unix_socket_stream_bandwidth (MB/s)","1135.57"
    "bw_file_rd-io-1mb (MB/s)","948.77"
    "bw_file_rd-o2c-1mb (MB/s)","520.74"
    "bw_mem-bcopy-16mb (MB/s)","871.55"
    "bw_mem-bcopy-1mb (MB/s)","1031.14"
    "bw_mem-bcopy-2mb (MB/s)","869.69"
    "bw_mem-bcopy-4mb (MB/s)","870.32"
    "bw_mem-bcopy-8mb (MB/s)","875.18"
    "bw_mem-bzero-16mb (MB/s)","1641.03"
    "bw_mem-bzero-1mb (MB/s)","2716.37 (min 1031.14, max 4401.59)"
    "bw_mem-bzero-2mb (MB/s)","1582.95 (min 869.69, max 2296.21)"
    "bw_mem-bzero-4mb (MB/s)","1275.26 (min 870.32, max 1680.20)"
    "bw_mem-bzero-8mb (MB/s)","1258.02 (min 875.18, max 1640.86)"
    "bw_mem-cp-16mb (MB/s)","583.94"
    "bw_mem-cp-1mb (MB/s)","2606.57 (min 664.23, max 4548.90)"
    "bw_mem-cp-2mb (MB/s)","1455.08 (min 590.41, max 2319.74)"
    "bw_mem-cp-4mb (MB/s)","1132.90 (min 580.30, max 1685.49)"
    "bw_mem-cp-8mb (MB/s)","1117.30 (min 590.36, max 1644.23)"
    "bw_mem-fcp-16mb (MB/s)","810.41"
    "bw_mem-fcp-1mb (MB/s)","2684.82 (min 968.05, max 4401.59)"
    "bw_mem-fcp-2mb (MB/s)","1549.96 (min 803.70, max 2296.21)"
    "bw_mem-fcp-4mb (MB/s)","1242.11 (min 804.02, max 1680.20)"
    "bw_mem-fcp-8mb (MB/s)","1226.19 (min 811.52, max 1640.86)"
    "bw_mem-frd-16mb (MB/s)","1266.93"
    "bw_mem-frd-1mb (MB/s)","1266.09 (min 968.05, max 1564.13)"
    "bw_mem-frd-2mb (MB/s)","1092.46 (min 803.70, max 1381.22)"
    "bw_mem-frd-4mb (MB/s)","1037.34 (min 804.02, max 1270.65)"
    "bw_mem-frd-8mb (MB/s)","1035.58 (min 811.52, max 1259.64)"
    "bw_mem-fwr-16mb (MB/s)","1642.54"
    "bw_mem-fwr-1mb (MB/s)","3056.52 (min 1564.13, max 4548.90)"
    "bw_mem-fwr-2mb (MB/s)","1850.48 (min 1381.22, max 2319.74)"
    "bw_mem-fwr-4mb (MB/s)","1478.07 (min 1270.65, max 1685.49)"
    "bw_mem-fwr-8mb (MB/s)","1451.94 (min 1259.64, max 1644.23)"
    "bw_mem-rd-16mb (MB/s)","1284.83"
    "bw_mem-rd-1mb (MB/s)","2950.72 (min 2745.10, max 3156.33)"
    "bw_mem-rd-2mb (MB/s)","1152.68 (min 895.92, max 1409.44)"
    "bw_mem-rd-4mb (MB/s)","1021.75 (min 748.36, max 1295.13)"
    "bw_mem-rd-8mb (MB/s)","1004.46 (min 733.00, max 1275.92)"
    "bw_mem-rdwr-16mb (MB/s)","726.98"
    "bw_mem-rdwr-1mb (MB/s)","1622.33 (min 664.23, max 2580.42)"
    "bw_mem-rdwr-2mb (MB/s)","737.88 (min 590.41, max 885.35)"
    "bw_mem-rdwr-4mb (MB/s)","653.13 (min 580.30, max 725.95)"
    "bw_mem-rdwr-8mb (MB/s)","658.03 (min 590.36, max 725.69)"
    "bw_mem-wr-16mb (MB/s)","735.77"
    "bw_mem-wr-1mb (MB/s)","2868.38 (min 2580.42, max 3156.33)"
    "bw_mem-wr-2mb (MB/s)","890.64 (min 885.35, max 895.92)"
    "bw_mem-wr-4mb (MB/s)","737.16 (min 725.95, max 748.36)"
    "bw_mem-wr-8mb (MB/s)","729.35 (min 725.69, max 733.00)"
    "bw_mmap_rd-mo-1mb (MB/s)","2596.95"
    "bw_mmap_rd-o2c-1mb (MB/s)","563.06"
    "bw_pipe (MB/s)","345.64"
    "bw_unix (MB/s)","1135.57"
    "lat_connect (us)","94.79"
    "lat_ctx-2-128k (us)","5.03"
    "lat_ctx-2-256k (us)","2.44"
    "lat_ctx-4-128k (us)","4.61"
    "lat_ctx-4-256k (us)","0.35"
    "lat_fs-0k (num_files)","193.00"
    "lat_fs-10k (num_files)","81.00"
    "lat_fs-1k (num_files)","120.00"
    "lat_fs-4k (num_files)","117.00"
    "lat_mem_rd-stride128-sz1000k (ns)","26.75"
    "lat_mem_rd-stride128-sz125k (ns)","9.70"
    "lat_mem_rd-stride128-sz250k (ns)","10.25"
    "lat_mem_rd-stride128-sz31k (ns)","6.41"
    "lat_mem_rd-stride128-sz50 (ns)","3.77"
    "lat_mem_rd-stride128-sz500k (ns)","11.65"
    "lat_mem_rd-stride128-sz62k (ns)","9.19"
    "lat_mmap-1m (us)","80.00"
    "lat_ops-double-add (ns)","0.92"
    "lat_ops-double-mul (ns)","5.05"
    "lat_ops-float-add (ns)","0.91"
    "lat_ops-float-mul (ns)","5.03"
    "lat_ops-int-add (ns)","1.26"
    "lat_ops-int-bit (ns)","0.84"
    "lat_ops-int-div (ns)","7.56"
    "lat_ops-int-mod (ns)","7.97"
    "lat_ops-int-mul (ns)","3.82"
    "lat_ops-int64-add (ns)","1.26"
    "lat_ops-int64-bit (ns)","0.84"
    "lat_ops-int64-div (ns)","11.97"
    "lat_ops-int64-mod (ns)","9.23"
    "lat_pagefault (us)","1.79"
    "lat_pipe (us)","26.40"
    "lat_proc-exec (us)","1355.50"
    "lat_proc-fork (us)","1223.40"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","54.45"
    "lat_sem (us)","7.15"
    "lat_sig-catch (us)","9.80"
    "lat_sig-install (us)","1.02"
    "lat_sig-prot (us)","0.49"
    "lat_syscall-fstat (us)","2.70"
    "lat_syscall-null (us)","0.45"
    "lat_syscall-open (us)","267.50"
    "lat_syscall-read (us)","1.16"
    "lat_syscall-stat (us)","7.10"
    "lat_syscall-write (us)","0.75"
    "lat_tcp (us)","0.86"
    "lat_unix (us)","52.76"
    "latency_for_0.50_mb_block_size (nanosec)","11.65"
    "latency_for_1.00_mb_block_size (nanosec)","13.38 (min 0.00, max 26.75)"
    "pipe_bandwidth (MB/s)","345.64"
    "pipe_latency (microsec)","26.40"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","54.45"
    "semaphore_latency (microsec)","7.15"
    "signal_handler_latency (microsec)","1.02"
    "signal_handler_overhead (microsec)","9.80"
    "tcp_ip_connection_cost_to_localhost (microsec)","94.79"
    "tcp_latency_using_localhost (microsec)","0.86"


Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "cpu_clock (MHz)","800.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.96"
    "dhrystone_per_second (DhrystoneP)","4166666.80"


Table:  **Dhrystone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "linpack (Kflops)","332510.00"


Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks 
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html


.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "assignment (Iterations)","7.75"
    "fourier (Iterations)","13045.00"
    "fp_emulation (Iterations)","61.14"
    "huffman (Iterations)","669.49"
    "idea (Iterations)","1959.60"
    "lu_decomposition (Iterations)","312.69"
    "neural_net (Iterations)","4.48"
    "numeric_sort (Iterations)","288.37"
    "string_sort (Iterations)","94.58"


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
    :header: "Benchmarks","am654x-evm: perf"

    "add (MB/s)","1609.10"
    "copy (MB/s)","1763.90"
    "scale (MB/s)","1770.60"
    "triad (MB/s)","1505.10"


Table:  **Stream**

|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am654x-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","15.41 (min 15.18, max 15.68)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","5.09 (min 5.03, max 5.33)"

Table:  **Boot time MMC/SD**

|
