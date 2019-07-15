.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Kernel_Performance_Guide


.. rubric::  **Read This First**
   :name: read-this-first

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
| AM65x EVM      | AM65x Evaluation Module rev 1.0 with ARM running at 800MHz, DDR4-2400 (1333 MT/S), TMDX654GPEVM                |
+----------------+----------------------------------------------------------------------------------------------------------------+

Table:  Evaluation Modules

|

.. rubric::  About This Manual
   :name: about-this-manual

This document provides performance data for each of the device drivers
which are part of the Process SDK Linux package. This document should be
used in conjunction with release notes and user guides provided with the
Process SDK Linux package for information on specific issues present
with drivers included in a particular release.

.. rubric::  If You Need Assistance
   :name: if-you-need-assistance

For further information or to report any problems, contact
http://community.ti.com/ or http://support.ti.com/

System Benchmarks
-------------------

LMBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
LMBench is a collection of microbenchmarks of which the memory bandwidth 
and latency related ones are typically used to estimate processor 
memory system performance.
  
**Latency**: lat_mem_rd-stride128-szN, where N is equal to or smaller than the cache
size at given level measures the cache miss penalty. N that is at least
double the size of last level cache is the latency to external memory.

**Bandwidth**: bw_mem_bcopy-N, where N is is equal to or smaller than the cache size at
a given level measures the achivable memory bandwidth from software doing
a memcpy() type operation. Typical use is for external memory bandwidth
calculation. The bandwidth is calculated as byte read and written counts
as 1 which should be roughly half of STREAM copy result.

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am57xx-evm: perf","am654x-evm: perf","k2g-evm: perf","omapl138-lcdk: perf"

    "af_unix_sock_stream_latency (microsec)","40.78","27.84","48.46","47.67","781.57"
    "af_unix_socket_stream_bandwidth (MBs)","178.07","2032.00","1249.24","655.40","34.03"
    "bw_file_rd-io-1mb (MB/s)","180.51","1240.26","1193.79","617.76","48.71"
    "bw_file_rd-o2c-1mb (MB/s)","153.19","952.56","805.67","468.68","44.92"
    "bw_mem-bcopy-16mb (MB/s)","155.03","1939.39","815.08","1243.49","99.80"
    "bw_mem-bcopy-1mb (MB/s)","195.77","4939.74","1543.47","1337.15","99.58"
    "bw_mem-bcopy-2mb (MB/s)","201.96","2930.94","925.07","1247.08","99.12"
    "bw_mem-bcopy-4mb (MB/s)","210.49","2027.37","826.45","1228.50","99.30"
    "bw_mem-bcopy-8mb (MB/s)","218.33","1955.03","817.33","1248.05","100.97"
    "bw_mem-bzero-16mb (MB/s)","996.08","4955.09","1959.34","3421.73","251.37"
    "bw_mem-bzero-1mb (MB/s)","589.21 (min 195.77, max 982.64)","5425.27 (min 4939.74, max 5910.80)","2929.34 (min 1543.47, max 4315.20)","2815.30 (min 1337.15, max 4293.45)","174.45 (min 99.58, max 249.31)"
    "bw_mem-bzero-2mb (MB/s)","599.74 (min 201.96, max 997.51)","4319.05 (min 2930.94, max 5707.15)","2596.25 (min 925.07, max 4267.43)","2612.80 (min 1247.08, max 3978.52)","174.22 (min 99.12, max 249.31)"
    "bw_mem-bzero-4mb (MB/s)","595.74 (min 210.49, max 980.99)","3684.36 (min 2027.37, max 5341.35)","1622.60 (min 826.45, max 2418.75)","2436.08 (min 1228.50, max 3643.65)","174.74 (min 99.30, max 250.17)"
    "bw_mem-bzero-8mb (MB/s)","611.30 (min 218.33, max 1004.27)","3534.24 (min 1955.03, max 5113.45)","1406.42 (min 817.33, max 1995.51)","2379.70 (min 1248.05, max 3511.34)","175.82 (min 100.97, max 250.67)"
    "bw_mem-cp-16mb (MB/s)","158.43","1041.26","480.60","605.35","105.80"
    "bw_mem-cp-1mb (MB/s)","588.37 (min 192.64, max 984.09)","4942.73 (min 4091.07, max 5794.39)","2665.64 (min 858.66, max 4472.61)","2629.09 (min 594.35, max 4663.82)","177.88 (min 106.60, max 249.16)"
    "bw_mem-cp-2mb (MB/s)","589.06 (min 191.75, max 986.36)","3369.84 (min 1201.56, max 5538.12)","2433.42 (min 551.42, max 4315.42)","2329.94 (min 583.09, max 4076.78)","178.00 (min 106.78, max 249.22)"
    "bw_mem-cp-4mb (MB/s)","590.52 (min 196.91, max 984.13)","3188.45 (min 1037.34, max 5339.56)","1457.29 (min 492.91, max 2421.67)","2106.41 (min 549.15, max 3663.67)","177.52 (min 105.06, max 249.98)"
    "bw_mem-cp-8mb (MB/s)","593.83 (min 202.91, max 984.74)","3051.47 (min 1039.64, max 5063.29)","1239.59 (min 482.42, max 1996.76)","2036.90 (min 608.60, max 3465.20)","179.17 (min 107.12, max 251.22)"
    "bw_mem-fcp-16mb (MB/s)","277.65","1173.54","812.64","616.33","86.03"
    "bw_mem-fcp-1mb (MB/s)","638.64 (min 294.64, max 982.64)","4544.95 (min 3179.09, max 5910.80)","2910.61 (min 1506.02, max 4315.20)","2449.62 (min 605.79, max 4293.45)","166.67 (min 84.03, max 249.31)"
    "bw_mem-fcp-2mb (MB/s)","646.36 (min 295.20, max 997.51)","3504.51 (min 1301.87, max 5707.15)","2591.59 (min 915.75, max 4267.43)","2287.68 (min 596.84, max 3978.52)","167.23 (min 85.14, max 249.31)"
    "bw_mem-fcp-4mb (MB/s)","639.94 (min 298.89, max 980.99)","3259.87 (min 1178.38, max 5341.35)","1621.41 (min 824.06, max 2418.75)","2112.65 (min 581.65, max 3643.65)","167.93 (min 85.69, max 250.17)"
    "bw_mem-fcp-8mb (MB/s)","653.00 (min 301.72, max 1004.27)","3146.09 (min 1178.72, max 5113.45)","1404.68 (min 813.84, max 1995.51)","2063.91 (min 616.48, max 3511.34)","169.22 (min 87.77, max 250.67)"
    "bw_mem-frd-16mb (MB/s)","248.90","1034.39","1318.93","824.95","143.64"
    "bw_mem-frd-1mb (MB/s)","282.71 (min 270.78, max 294.64)","3135.74 (min 3092.39, max 3179.09)","1512.31 (min 1506.02, max 1518.60)","772.38 (min 605.79, max 938.97)","112.77 (min 84.03, max 141.50)"
    "bw_mem-frd-2mb (MB/s)","274.04 (min 252.88, max 295.20)","1654.95 (min 1301.87, max 2008.03)","1244.97 (min 915.75, max 1574.18)","715.90 (min 596.84, max 834.96)","113.74 (min 85.14, max 142.33)"
    "bw_mem-frd-4mb (MB/s)","274.18 (min 249.47, max 298.89)","1179.34 (min 1178.38, max 1180.29)","1120.25 (min 824.06, max 1416.43)","703.62 (min 581.65, max 825.59)","114.50 (min 85.69, max 143.30)"
    "bw_mem-frd-8mb (MB/s)","275.46 (min 249.19, max 301.72)","1113.88 (min 1049.04, max 1178.72)","1068.85 (min 813.84, max 1323.85)","720.61 (min 616.48, max 824.74)","115.58 (min 87.77, max 143.39)"
    "bw_mem-fwr-16mb (MB/s)","996.26","4958.93","1957.19","3376.60","251.39"
    "bw_mem-fwr-1mb (MB/s)","627.44 (min 270.78, max 984.09)","4443.39 (min 3092.39, max 5794.39)","2995.61 (min 1518.60, max 4472.61)","2801.40 (min 938.97, max 4663.82)","195.33 (min 141.50, max 249.16)"
    "bw_mem-fwr-2mb (MB/s)","619.62 (min 252.88, max 986.36)","3773.08 (min 2008.03, max 5538.12)","2944.80 (min 1574.18, max 4315.42)","2455.87 (min 834.96, max 4076.78)","195.78 (min 142.33, max 249.22)"
    "bw_mem-fwr-4mb (MB/s)","616.80 (min 249.47, max 984.13)","3259.93 (min 1180.29, max 5339.56)","1919.05 (min 1416.43, max 2421.67)","2244.63 (min 825.59, max 3663.67)","196.64 (min 143.30, max 249.98)"
    "bw_mem-fwr-8mb (MB/s)","616.97 (min 249.19, max 984.74)","3056.17 (min 1049.04, max 5063.29)","1660.31 (min 1323.85, max 1996.76)","2144.97 (min 824.74, max 3465.20)","197.31 (min 143.39, max 251.22)"
    "bw_mem-rd-16mb (MB/s)","252.25","3037.21","1302.40","2442.38","154.73"
    "bw_mem-rd-1mb (MB/s)","633.94 (min 271.37, max 996.51)","12173.90 (min 10894.06, max 13453.74)","2081.90 (min 2022.06, max 2141.74)","1774.30 (min 868.66, max 2679.94)","534.94 (min 152.02, max 917.85)"
    "bw_mem-rd-2mb (MB/s)","617.45 (min 250.00, max 984.90)","8264.20 (min 7754.80, max 8773.60)","1837.80 (min 1786.67, max 1888.93)","1579.10 (min 702.49, max 2455.71)","536.14 (min 154.71, max 917.57)"
    "bw_mem-rd-4mb (MB/s)","614.07 (min 252.05, max 976.09)","2460.29 (min 1609.87, max 3310.71)","1221.10 (min 1068.09, max 1374.10)","1568.11 (min 700.16, max 2436.05)","538.49 (min 154.04, max 922.93)"
    "bw_mem-rd-8mb (MB/s)","625.31 (min 251.73, max 998.88)","2184.92 (min 1303.14, max 3066.70)","1114.48 (min 934.25, max 1294.71)","1569.19 (min 699.36, max 2439.02)","538.53 (min 154.54, max 922.51)"
    "bw_mem-rdwr-16mb (MB/s)","202.46","1181.25","889.93","665.23","131.34"
    "bw_mem-rdwr-1mb (MB/s)","199.65 (min 192.64, max 206.65)","5813.44 (min 4091.07, max 7535.80)","1385.17 (min 858.66, max 1911.68)","700.73 (min 594.35, max 807.10)","118.32 (min 106.60, max 130.04)"
    "bw_mem-rdwr-2mb (MB/s)","197.37 (min 191.75, max 202.98)","2503.73 (min 1201.56, max 3805.90)","1111.83 (min 551.42, max 1672.24)","626.89 (min 583.09, max 670.69)","118.62 (min 106.78, max 130.45)"
    "bw_mem-rdwr-4mb (MB/s)","200.00 (min 196.91, max 203.09)","1204.54 (min 1037.34, max 1371.74)","767.22 (min 492.91, max 1041.53)","610.43 (min 549.15, max 671.70)","118.14 (min 105.06, max 131.21)"
    "bw_mem-rdwr-8mb (MB/s)","202.70 (min 202.49, max 202.91)","1121.96 (min 1039.64, max 1204.28)","694.26 (min 482.42, max 906.10)","638.42 (min 608.60, max 668.23)","119.26 (min 107.12, max 131.40)"
    "bw_mem-wr-16mb (MB/s)","994.47","1274.39","918.38","697.71","925.12"
    "bw_mem-wr-1mb (MB/s)","601.58 (min 206.65, max 996.51)","10494.77 (min 7535.80, max 13453.74)","1966.87 (min 1911.68, max 2022.06)","837.88 (min 807.10, max 868.66)","523.95 (min 130.04, max 917.85)"
    "bw_mem-wr-2mb (MB/s)","593.94 (min 202.98, max 984.90)","5780.35 (min 3805.90, max 7754.80)","1729.46 (min 1672.24, max 1786.67)","686.59 (min 670.69, max 702.49)","524.01 (min 130.45, max 917.57)"
    "bw_mem-wr-4mb (MB/s)","589.59 (min 203.09, max 976.09)","1490.81 (min 1371.74, max 1609.87)","1054.81 (min 1041.53, max 1068.09)","685.93 (min 671.70, max 700.16)","527.07 (min 131.21, max 922.93)"
    "bw_mem-wr-8mb (MB/s)","600.69 (min 202.49, max 998.88)","1253.71 (min 1204.28, max 1303.14)","920.18 (min 906.10, max 934.25)","683.80 (min 668.23, max 699.36)","526.96 (min 131.40, max 922.51)"
    "bw_mmap_rd-mo-1mb (MB/s)","261.85","4125.56","2089.86","1551.19","141.54"
    "bw_mmap_rd-o2c-1mb (MB/s)","167.17","1303.78","997.01","615.95","90.38"
    "bw_pipe (MB/s)","264.03","498.72","973.89","352.10","30.63"
    "bw_unix (MB/s)","178.07","2032.00","1249.24","655.40","34.03"
    "lat_connect (us)","75.31","56.06","65.61","86.92","996.33"
    "lat_ctx-2-128k (us)","27.66","3.39","8.93","6.08","167.00"
    "lat_ctx-2-256k (us)","4.00","4.00","10.36","4.00","148.08"
    "lat_ctx-4-128k (us)","35.10","5.89","10.65","2.87","183.50"
    "lat_ctx-4-256k (us)","0.00","0.00","17.31","0.00","210.75"
    "lat_fs-0k (num_files)","194.00","335.00","261.00","197.00","19.00"
    "lat_fs-10k (num_files)","81.00","138.00","84.00","83.00","8.00"
    "lat_fs-1k (num_files)","114.00","192.00","77.00","126.00","13.00"
    "lat_fs-4k (num_files)","109.00","199.00","79.00","127.00","14.00"
    "lat_mem_rd-stride128-sz1000k (ns)","220.92","12.83","29.74","123.25","214.92"
    "lat_mem_rd-stride128-sz125k (ns)","11.77","12.68","9.46","20.05","203.47"
    "lat_mem_rd-stride128-sz250k (ns)","74.86","12.83","10.12","20.16","203.72"
    "lat_mem_rd-stride128-sz31k (ns)","3.01","6.46","3.78","16.06","163.69"
    "lat_mem_rd-stride128-sz50 (ns)","3.01","2.67","3.76","4.00","5.05"
    "lat_mem_rd-stride128-sz500k (ns)","183.29","12.83","10.47","47.61","213.82"
    "lat_mem_rd-stride128-sz62k (ns)","9.14","11.45","8.03","20.05","203.46"
    "lat_mmap-1m (us)","63.00","47.00","23.00","77.00","612.00"
    "lat_ops-double-add (ns)","2.37","0.73","0.91","1.09","35.03"
    "lat_ops-double-mul (ns)","11.06","3.34","5.01","5.04","99.91"
    "lat_ops-float-add (ns)","2.29","0.73","0.91","1.09","21.35"
    "lat_ops-float-mul (ns)","10.06","3.34","5.01","5.01","66.06"
    "lat_ops-int-add (ns)","1.00","0.67","1.25","1.00","1.68"
    "lat_ops-int-bit (ns)","0.67","0.45","0.84","0.67","2.54"
    "lat_ops-int-div (ns)","58.39","58.42","7.52","88.16","190.47"
    "lat_ops-int-mod (ns)","23.43","10.26","7.95","15.41","87.17"
    "lat_ops-int-mul (ns)","6.05","2.09","3.80","3.14","6.62"
    "lat_ops-int64-add (ns)","1.21","0.74","1.25","1.10","5.31"
    "lat_ops-int64-bit (ns)","1.04","0.68","0.84","1.02","2.57"
    "lat_ops-int64-div (ns)","239.74","125.73","11.90","188.04","854.85"
    "lat_ops-int64-mod (ns)","71.27","22.69","9.21","34.11","254.59"
    "lat_pagefault (us)","1.70","0.99","3.17","1.71","7.28"
    "lat_pipe (us)","36.35","25.80","23.95","39.01","443.59"
    "lat_proc-exec (us)","2018.33","959.83","1421.75","1279.20","6891.00"
    "lat_proc-fork (us)","1722.75","911.33","1323.20","1178.00","6385.00"
    "lat_proc-proccall (us)","0.02","0.01","0.01","0.01","0.05"
    "lat_select (us)","45.87","28.88","58.20","49.05","335.31"
    "lat_sem (us)","5.25","2.20","3.92","9.26","63.76"
    "lat_sig-catch (us)","6.30","3.68","7.38","5.63","29.16"
    "lat_sig-install (us)","1.41","0.64","0.90","0.98","5.89"
    "lat_sig-prot (us)","0.42","0.24","0.59","0.70","1.41"
    "lat_syscall-fstat (us)","3.39","2.55","3.67","3.64","18.17"
    "lat_syscall-null (us)","0.56","0.31","0.54","0.46","1.37"
    "lat_syscall-open (us)","243.00","152.52","199.36","199.82","1525.50"
    "lat_syscall-read (us)","1.09","0.47","1.21","0.68","4.55"
    "lat_syscall-stat (us)","7.84","5.42","7.95","8.73","83.16"
    "lat_syscall-write (us)","0.73","0.38","0.84","0.57","3.57"
    "lat_tcp (us)","1.06","0.59","1.01","0.88","2.80"
    "lat_unix (us)","40.78","27.84","48.46","47.67","781.57"
    "latency_for_0.50_mb_block_size (nanosec)","183.29","12.83","10.47","47.61","213.82"
    "latency_for_1.00_mb_block_size (nanosec)","110.46 (min 0.00, max 220.92)","6.41 (min 0.00, max 12.83)","14.87 (min 0.00, max 29.74)","61.63 (min 0.00, max 123.25)","107.46 (min 0.00, max 214.92)"
    "pipe_bandwidth (MBs)","264.03","498.72","973.89","352.10","30.63"
    "pipe_latency (microsec)","36.35","25.80","23.95","39.01","443.59"
    "procedure_call (microsec)","0.02","0.01","0.01","0.01","0.05"
    "select_on_200_tcp_fds (microsec)","45.87","28.88","58.20","49.05","335.31"
    "semaphore_latency (microsec)","5.25","2.20","3.92","9.26","63.76"
    "signal_handler_latency (microsec)","1.41","0.64","0.90","0.98","5.89"
    "signal_handler_overhead (microsec)","6.30","3.68","7.38","5.63","29.16"
    "tcp_ip_connection_cost_to_localhost (microsec)","75.31","56.06","65.61","86.92","996.33"
    "tcp_latency_using_localhost (microsec)","1.06","0.59","1.01","0.88","2.80"


Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.
  
.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am57xx-evm: perf","am654x-evm: perf","k2g-evm: perf","omapl138-lcdk: perf"

    "cpu_clock (MHz)","1000.00","1500.00","400.00","50.00","230.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.10","3.40","5.90","67.00","1.90"
    "dhrystone_per_second (DhrystoneP)","3636363.80","9090909.00","4166666.80","5882353.00","763358.80"


Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am57xx-evm: perf","am654x-evm: perf","k2g-evm: perf","omapl138-lcdk: perf"

    "whetstone (MIPS)","833.30","5000.00","3333.30","2500.00","31.70"


Table:  **Whetstone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
sloving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am57xx-evm: perf","am654x-evm: perf","k2g-evm: perf","omapl138-lcdk: perf"

    "linpack (Kflops)","52772.00","1003312.00","336568.00","644334.00","7471.00"


Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am57xx-evm: perf","am654x-evm: perf","k2g-evm: perf","omapl138-lcdk: perf"

    "assignment (Iterations)","7.92","19.91","7.71","13.29","0.98"
    "fourier (Iterations)","2372.80","18677.00","8264.30","12520.00","121.00"
    "fp_emulation (Iterations)","51.80","92.61","61.54","61.64","19.24"
    "huffman (Iterations)","706.36","1356.20","673.97","903.08","221.26"
    "idea (Iterations)","1561.80","4297.70","1920.80","2863.20","452.51"
    "lu_decomposition (Iterations)","75.96","827.36","323.47","552.87","5.87"
    "neural_net (Iterations)","2.07","23.29","4.23","14.97","0.19"
    "numeric_sort (Iterations)","443.17","767.30","299.17","501.94","102.54"
    "string_sort (Iterations)","66.76","141.00","94.73","93.94","7.73"


Table:  **NBench Benchmarks**

Stream
^^^^^^^^^^^^^^^^^^^^^^^^^^^
STREAM is a microbenchmarks for measuring data memory system performance without
any data reuse. It is designed to miss on caches and exercise data prefetcher and
apeculative accesseses. it uses double precision floating point (64bit) but in
most modern processors the memory access will be the bottleck. The four individual
scores are copy, scale as in multiply by constant, add two numbers, and triad for
multiply accumulate. For bandwidth a byte read counts as one and a byte written
counts as one resulting in a score that is double the bandwidth LMBench will show.

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am57xx-evm: perf","am654x-evm: perf","k2g-evm: perf"

    "add (MB/s)","387.20","3803.20","1762.20","2334.00"
    "copy (MB/s)","442.20","3923.50","1947.50","2450.10"
    "scale (MB/s)","589.20","4377.50","1988.80","2386.30"
    "triad (MB/s)","417.20","3869.20","1652.30","2346.90"


Table:  **Stream**

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am335x-evm: boot time (sec)","am57xx-evm: boot time (sec)","am654x-evm: boot time (sec)","k2g-evm: boot time (sec)","omapl138-lcdk: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","45.17 (min 44.65, max 45.46)","24.63 (min 23.97, max 25.07)","14.55 (min 13.77, max 14.98)","34.49 (min 34.42, max 34.56)","131.96 (min 128.08, max 133.68)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","5.59 (min 5.47, max 6.08)","6.90 (min 6.86, max 7.02)","7.37 (min 7.32, max 7.43)","8.53 (min 8.28, max 9.38)"

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
    :header: "Sampling Rate (Hz)","am335x-evm: Throughput (bits/sec)","am335x-evm: CPU Load (%)","am57xx-evm: Throughput (bits/sec)","am57xx-evm: CPU Load (%)","am654x-evm: Throughput (bits/sec)","am654x-evm: CPU Load (%)","k2g-evm: Throughput (bits/sec)","k2g-evm: CPU Load (%)","omapl138-lcdk: Throughput (bits/sec)","omapl138-lcdk: CPU Load (%)"

    "8000","256000.00","0.94","255989.00","0.11","255995.00","0.08","352797.00","0.40","256006.00","2.40"
    "11025","352799.00","3.82","352789.00","0.12","352794.00","0.16","352797.00","0.40","352811.00","3.28"
    "16000","511999.00","0.96","511979.00","0.15","511991.00","0.11","352797.00","0.39","512022.00","4.47"
    "22050","705598.00","7.70","705577.00","0.24","705587.00","0.28","705595.00","0.80","705638.00","5.87"
    "24000","705598.00","7.65","705577.00","0.20","705587.00","0.28","705595.00","0.73","705638.00","6.28"
    "32000","1023996.00","1.05","1023957.00","0.36","1023981.00","0.17","705595.00","0.74","1024077.00","7.80"
    "44100","1411192.00","14.27","1411154.00","0.44","1411173.00","0.45","1411189.00","1.45","1411341.00","11.53"
    "48000","1535992.00","0.86","1535936.00","0.49","1535971.00","0.22","1411189.00","1.43","1536166.00","12.49"
    "88200","2822370.00","27.39","2822307.00","0.82","2822342.00","0.84","2822375.00","2.80","2729810.00","25.46"
    "96000","3071988.00","1.46","3071868.00","0.50","3071935.00","0.41","2822375.00","2.80","2962622.00","30.60"

Table:  **Audio Capture**

|

.. csv-table::
    :header: "Sampling Rate (Hz)","am335x-evm: Throughput (bits/sec)","am335x-evm: CPU Load (%)","am57xx-evm: Throughput (bits/sec)","am57xx-evm: CPU Load (%)","k2g-evm: Throughput (bits/sec)","k2g-evm: CPU Load (%)","omapl138-lcdk: Throughput (bits/sec)","omapl138-lcdk: CPU Load (%)"

    "8000","256101.00","2.35","256092.00","0.08","352940.00","0.48","256108.00","2.53"
    "11025","352939.00","3.53","352930.00","0.11","352940.00","0.44","352952.00","3.16"
    "16000","512202.00","0.84","512184.00","0.18","352940.00","0.45","512225.00","4.54"
    "22050","705877.00","7.46","705860.00","0.26","705879.00","0.75","705920.00","5.77"
    "24000","705878.00","7.33","705860.00","0.20","705879.00","0.75","705920.00","5.75"
    "32000","1024402.00","28.48","1024367.00","0.20","705879.00","0.77","1024484.00","7.76"
    "44100","1411752.00","13.97","1411719.00","0.40","1411758.00","1.47","1411903.00","11.37"
    "48000","1536600.00","1.61","1536550.00","0.48","1411758.00","1.30","1536776.00","12.13"
    "88200","2823489.00","27.86","2823317.00","0.77","2823513.00","2.39","2731759.00","24.60"
    "96000","3073182.00","0.91","3072969.00","0.70","2823513.00","2.76","2964732.00","27.43"

Table:  **Audio Playback**

|

Sensor Capture
-------------------------

Capture video frames (MMAP buffers) with v4l2c-ctl and record the
reported fps

.. csv-table::
    :header: "Resolution","Format","am57xx-evm: Fps","am57xx-evm: Sensor"

    "160x128","nv12","40.81 (min 40.60, max 40.91)","mt9t111"
    "160x128","rgb4","40.81 (min 40.60, max 40.91)","mt9t111"
    "2048x1536","nv12","6.64 (min 6.10, max 6.70)","mt9t111"
    "2048x1536","rgb4","6.64 (min 6.10, max 6.70)","mt9t111"

Table:  **Sensor Capture**

|

Display Driver
-------------------------


.. csv-table::
    :header: "Mode","am335x-evm: Fps","am57xx-evm: Fps","am654x-evm: Fps","k2g-evm: Fps"

    "1280x800\@60","","","59.99 (min 59.99, max 60.00)",""
    "480x272\@60","","","","59.94 (min 59.93, max 59.94)"
    "800x480\@60","","59.52 (min 59.50, max 59.55)","",""
    "800x480\@62","61.89 (min 61.89, max 61.90)","","",""


Table:  **Display performance (LCD)**

|

|

Table:  **Display performance (DVI)**

|


.. csv-table::
    :header: "Mode","am335x-evm: Fps","am57xx-evm: Fps","am654x-evm: Fps","k2g-evm: Fps"

    "1024x576\@60","59.97 (min 59.96, max 59.97)","59.97 (min 59.95, max 60.00)","","60.01 (min 60.00, max 60.01)"
    "1024x768\@60","","60.00 (min 59.46, max 60.55)","",""
    "1024x768\@70","","70.07 (min 70.05, max 70.10)","",""
    "1024x768\@75","","75.03 (min 74.93, max 75.11)","",""
    "1152x864\@75","","75.00 (min 74.98, max 75.02)","",""
    "1280x1024\@60","","60.02 (min 60.00, max 60.04)","",""
    "1280x1024\@75","","75.02 (min 75.00, max 75.05)","",""
    "1280x720\@60","60.00 (min 59.99, max 60.01)","60.00 (min 59.98, max 60.03)","","60.00"
    "1280x768\@60","","59.87 (min 59.85, max 59.90)","",""
    "1280x768\@75","","74.89 (min 74.87, max 74.92)","",""
    "1280x800\@60","","59.81 (min 59.79, max 59.83)","",""
    "1280x800\@75","","74.93 (min 74.90, max 74.98)","",""
    "1280x960\@60","","60.00 (min 59.45, max 60.56)","",""
    "1360x768\@60","","59.95 (min 59.93, max 59.98)","",""
    "1400x1050\@60","","59.98 (min 59.96, max 60.00)","",""
    "1400x1050\@75","","74.87 (min 74.83, max 74.93)","",""
    "1440x900\@60","","59.89 (min 59.86, max 59.91)","",""
    "1440x900\@75","","74.98 (min 74.95, max 75.03)","",""
    "1600x1200\@60","","60.00 (min 59.98, max 60.02)","",""
    "1600x1200\@65","","65.00 (min 64.96, max 65.04)","",""
    "1600x1200\@70","","70.00 (min 69.96, max 70.04)","",""
    "1600x900\@60","","60.00 (min 59.95, max 60.05)","",""
    "1680x1050\@60","","59.95 (min 59.93, max 59.97)","",""
    "1680x1050\@75","","74.89 (min 74.85, max 74.93)","",""
    "1680x945\@60","","60.02 (min 59.96, max 60.07)","",""
    "1920x1080\@60","","60.00 (min 59.98, max 60.02)","",""
    "2048x1152\@60","","60.00 (min 59.98, max 60.02)","",""
    "640x480\@60","60.00 (min 59.99, max 60.01)","60.00 (min 59.98, max 60.02)","",""
    "640x480\@73","72.81 (min 72.80, max 72.82)","72.81 (min 72.79, max 72.83)","",""
    "640x480\@75","75.00 (min 74.90, max 75.09)","75.00 (min 74.92, max 75.07)","",""
    "720x400\@70","70.08 (min 70.07, max 70.09)","70.08 (min 70.05, max 70.12)","",""
    "800x600\@56","56.25 (min 56.24, max 56.26)","56.25 (min 56.24, max 56.26)","",""
    "800x600\@60","60.32 (min 60.31, max 60.32)","60.32 (min 60.29, max 60.34)","",""
    "800x600\@72","72.19 (min 72.18, max 72.20)","72.19 (min 72.16, max 72.23)","","72.19 (min 72.18, max 72.19)"
    "800x600\@75","75.00 (min 74.99, max 75.01)","75.00 (min 74.98, max 75.02)","","75.00 (min 74.99, max 75.01)"
    "832x624\@75","74.55 (min 74.54, max 74.56)","74.55 (min 74.52, max 74.59)","","74.57 (min 74.57, max 74.58)"
    "848x480\@60","60.00 (min 59.99, max 60.01)","60.00 (min 59.98, max 60.03)","",""


Table:  **Display performance (HDMI)**

|

Graphics SGX Driver
-------------------------

Run GLBenchmark and capture performance reported Display rate (Fps),
Fill rate, Vertex Throughput, etc. All display outputs (HDMI and LCD)
are connected when running these tests

Performance (Fps)
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Fps","am57xx-evm: Test Number","am57xx-evm: Fps","am654x-evm: Test Number","am654x-evm: Fps"

    "GLB25_EgyptTestC24Z16FixedTime test","2500005.00","5.14 (min 2.41, max 14.00)","2500005.00","38.04 (min 20.69, max 59.30)","2500005.00","18.63 (min 9.55, max 41.29)"
    "GLB25_EgyptTestC24Z16_ETC1 test","2501001.00","6.26 (min 2.33, max 14.49)","2501001.00","45.13 (min 20.58, max 60.30)","2501001.00","24.96 (min 9.60, max 59.99)"
    "GLB25_EgyptTestC24Z16_ETC1to565 test","2501401.00","6.25 (min 2.24, max 14.29)","2501401.00","45.10 (min 20.65, max 59.89)","2501401.00","24.98 (min 9.65, max 60.01)"
    "GLB25_EgyptTestC24Z16_PVRTC4 test","2501101.00","6.09 (min 2.19, max 14.12)","2501101.00","45.02 (min 20.61, max 60.45)","2501101.00","24.79 (min 9.58, max 59.99)"
    "GLB25_EgyptTestC24Z24MS4 test","2500003.00","4.98 (min 0.86, max 11.80)","2500003.00","43.73 (min 19.74, max 60.27)","2500003.00","22.53 (min 9.11, max 56.08)"
    "GLB25_EgyptTestStandard_inherited test","2000000.00","23.79 (min 15.40, max 36.44)","2000000.00","59.51 (min 58.30, max 59.75)","2000000.00","59.84 (min 54.69, max 60.51)"


Table:  **GLBenchmark 2.5 Performance**

Vertex Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Rate (triangles/sec)","am57xx-evm: Test Number","am57xx-evm: Rate (triangles/sec)","am654x-evm: Test Number","am654x-evm: Rate (triangles/sec)"

    "GLB25_TriangleTexFragmentLitTestC24Z16 test","2500511.00","2204723.75","2500511.00","24925044.00","2500511.00","10879404.00"
    "GLB25_TriangleTexTestC24Z16 test","2500301.00","11248532.00","2500301.00","105213576.00","2500301.00","39578940.00"
    "GLB25_TriangleTexVertexLitTestC24Z16 test","2500411.00","3065270.50","2500411.00","39262272.00","2500411.00","12307329.00"


Table:  **GLBenchmark 2.5 Vertex Throughput**

Pixel Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Rate (texel/sec)","am335x-evm: Fps","am57xx-evm: Test Number","am57xx-evm: Rate (texel/sec)","am57xx-evm: Fps","am654x-evm: Test Number","am654x-evm: Rate (texel/sec)","am654x-evm: Fps"

    "GLB25_FillTestC24Z16 test","2500101.00","106066112.00","4.33 (min 4.13, max 5.09)","2500101.00","1438427520.00","58.43 (min 53.57, max 59.52)","2500101.00","543738496.00","22.12 (min 21.29, max 22.62)"


Table:  **GLBenchmark 2.5 Pixel Throughput**

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

.. csv-table::
    :header: "Resolution","am57xx-evm: Fps","am57xx-evm: IVA Freq (MHz)","am57xx-evm: IPU Freq (MHz)"

    "1080i","30300.00","532.00",""
    "1080p","60.00","532.00",""
    "720p","59940.00","532.00",""
    "720x480","24.17","532.00",""
    "800x480","30.00","532.00",""
    "CIF","90000.00","532.00",""

Table:  **Gstreamer H264 in AVI Container Decode Performance**

|

MPEG4
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Resolution","am57xx-evm: Fps","am57xx-evm: IVA Freq (MHz)","am57xx-evm: IPU Freq (MHz)"

    "CIF","30.00","532.00",""
    "QVGA","30.00","532.00",""


Table:  **GStreamer MPEG4 in 3GP Container Decode Performance**

|

MPEG2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Resolution","am57xx-evm: Fps","am57xx-evm: IVA Freq (MHz)","am57xx-evm: IPU Freq (MHz)"

    "1080p","60.00","532.00",""
    "720p","29.97","532.00",""


Table:  **GStreamer MPEG2 in MP4 Container Decode Performance**

|

|
Ethernet Driver
-------------------------

TCP Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "TCP Window Size (KBytes)","am335x-evm: Throughput (Mbits/sec)","am335x-evm: CPU Load ","am57xx-evm: Throughput (Mbits/sec)","am57xx-evm: CPU Load ","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load ","k2g-evm: Throughput (Mbits/sec)","k2g-evm: CPU Load ","omapl138-lcdk: Throughput (Mbits/sec)","omapl138-lcdk: CPU Load "

    "8","233.28","99.84 (min 99.03, max 100.00)","582.48","","763.20","36.89 (min 29.07, max 39.54)","512.80","75.35 (min 73.32, max 76.42)","33.60","99.73 (min 99.25, max 100.00)"
    "16","289.60","99.69 (min 97.52, max 100.00)","716.00","","691.20","31.16 (min 30.58, max 31.70)","733.60","98.37 (min 97.81, max 98.82)","44.64","99.61 (min 96.35, max 100.00)"
    "32","336.88","","859.20","53.19 (min 52.03, max 53.90)","1158.40","","767.20","99.96 (min 99.80, max 100.00)","55.04","99.22 (min 95.58, max 100.00)"
    "64","376.00","99.90 (min 98.95, max 100.00)","1188.80","74.04 (min 69.46, max 76.93)","1592.00","57.10 (min 55.23, max 57.99)","823.20","100.00","64.24","93.14 (min 89.83, max 100.00)"
    "128","380.00","99.34 (min 93.87, max 100.00)","1130.40","67.30 (min 66.63, max 67.74)","1273.60","42.36 (min 41.67, max 42.89)","908.00","100.00","64.88","97.95 (min 94.40, max 100.00)"
    "256","361.60","99.41 (min 95.63, max 100.00)","1112.80","65.74 (min 65.12, max 66.91)","1216.80","41.26 (min 40.52, max 41.97)","916.80","100.00","64.16","98.12 (min 94.50, max 100.00)"

Table: **TCP Throughput**

.. rubric::  TCP Throughput Interrupt Pacing
   :name: tcp-throughput-interrupt-pacing

.. csv-table::
    :header: "TCP Window Size (KBytes)","am335x-evm: Throughput (Mbits/sec)","am335x-evm: CPU Load ","am57xx-evm: Throughput (Mbits/sec)","am57xx-evm: CPU Load ","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load ","omapl138-lcdk: Throughput (Mbits/sec)","omapl138-lcdk: CPU Load "

    "8","246.96","","593.84","","0.00","","35.60","99.60 (min 98.45, max 100.00)"
    "16","282.40","","640.80","40.04 (min 36.48, max 44.35)","0.00","","44.00","99.93 (min 98.97, max 100.00)"
    "32","323.20","98.98 (min 94.31, max 99.81)","912.00","56.06 (min 50.77, max 59.81)","0.00","","53.28","99.16 (min 96.24, max 100.00)"
    "64","378.00","99.88 (min 99.07, max 100.00)","1136.00","66.29 (min 62.16, max 69.54)","0.00","","64.32","92.65 (min 88.69, max 100.00)"
    "128","380.00","","1093.60","62.23 (min 60.73, max 64.34)","0.00","","68.40","98.23 (min 96.12, max 100.00)"
    "256","376.00","","1085.60","63.89 (min 62.25, max 65.71)","0.00","","68.96","98.22 (min 93.82, max 100.00)"

Table: **TCP Throughput Interrupt Pacing**


UDP Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  UDP Throughput Egress
   :name: udp-throughput-egress

.. csv-table::
    :header: "UDP Packet Size(bytes)","am335x-evm: Throughput (Mbits/sec)","am335x-evm: CPU Load ","am335x-evm: Packets Per Second (kpps) ","am57xx-evm: Throughput (Mbits/sec)","am57xx-evm: CPU Load ","am57xx-evm: Packets Per Second (kpps) ","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load ","am654x-evm: Packets Per Second (kpps) ","k2g-evm: Throughput (Mbits/sec)","k2g-evm: CPU Load ","k2g-evm: Packets Per Second (kpps) ","omapl138-lcdk: Throughput (Mbits/sec)","omapl138-lcdk: CPU Load ","omapl138-lcdk: Packets Per Second (kpps) "

    "64","20.30","99.90","39.00","48.20","81.00","93.00","35.10","46.70","68.00","23.60","100.00","44.00","1.70","98.70","1.00"
    "128","40.30","99.90","39.00","95.80","81.10","92.00","37.30","0.20","36.00","47.10","100.00","45.00","3.30","98.40","2.00"
    "256","79.50","99.80","38.00","189.20","81.30","92.00","78.10","0.20","38.00","93.50","100.00","45.00","6.80","98.80","2.00"
    "512","156.80","99.90","38.00","365.00","81.00","89.00","269.00","0.20","65.00","181.50","100.00","44.00","13.20","98.20","3.00"
    "1024","302.00","99.90","36.00","688.00","79.20","83.00","467.00","100.00","57.00","359.00","100.00","43.00","25.90","98.30","3.00"
    "1470","421.00","99.90","35.00","895.00","75.80","76.00","712.00","42.30","60.00","504.00","100.00","42.00","36.20","98.40","3.00"
    "1500","315.00","100.00","26.00","635.00","80.00","52.00","518.00","43.00","43.00","394.00","100.00","32.00","28.90","98.80","2.00"
    "4000","774.00","49.10","24.00"
    "8000","954.00","42.10","14.00"

Table: **UDP Throughput Egress**

.. rubric::  UDP Throughput Ingress
   :name: udp-throughput-ingress

.. csv-table::
    :header: "UDP Packet Size(bytes)","am335x-evm: Throughput (Mbits/sec)","am335x-evm: CPU Load ","am335x-evm: Packets Per Second (kpps) ","am57xx-evm: Throughput (Mbits/sec)","am57xx-evm: CPU Load ","am57xx-evm: Packets Per Second (kpps) ","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load ","am654x-evm: Packets Per Second (kpps) ","k2g-evm: Throughput (Mbits/sec)","k2g-evm: CPU Load ","k2g-evm: Packets Per Second (kpps) ","omapl138-lcdk: Throughput (Mbits/sec)","omapl138-lcdk: CPU Load ","omapl138-lcdk: Packets Per Second (kpps) "

    "64","28.20","100.00","54.00","22.10","74.30","42.00","23.10","43.40","44.00","28.60","99.70","54.00"
    "128","46.30","99.30","44.00","116.10","90.80","113.00","92.50","47.90","89.00","60.70","100.00","58.00","7.70","82.50","6.00"
    "256","62.30","100.00","30.00","232.00","90.60","113.00","177.80","47.40","86.00","145.10","99.60","70.00","14.90","83.00","6.00"
    "512","103.90","100.00","25.00","338.00","63.20","82.00","182.00","38.20","44.00","291.00","99.90","71.00","16.70","88.10","3.00"
    "1024","212.00","100.00","25.00","922.00","94.70","112.00","712.00","49.10","86.00","507.00","100.00","61.00","6.20","83.80","0.00"
    "1470","270.00","100.00","22.00","804.00","66.50","68.00","461.00","46.00","39.00","484.00","97.10","41.00","46.00","87.50","3.00"
    "1500","187.70","100.00","15.00","490.00","83.80","40.00","250.00","35.00","20.00","392.00","100.00","32.00","32.40","95.00","2.00"
    "4000","390.00","34.70","12.00"
    "8000","752.00","36.00","11.00"

Table: **UDP Throughput Ingress**

|

-  iperf version 2.0.5
-  For receive performance, on DUT, invoke iperf in server mode.

::

    iperf -s -u

-  For transmit performance, on DUT, invoke iperf in client mode.

::

    iperf -c <server ip> -b <bandwidth limit> -f M -t 60

|

PCIe Driver
-------------------------

PCIe-ETH
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "TCP Window Size(Kbytes)","am654x-evm: Bandwidth (Mbits/sec)","k2g-evm: Bandwidth (Mbits/sec)"

    "8","686.96"
    "16","739.20"
    "32","975.20"
    "64","1195.20"
    "128","1016.80","1310.40"
    "256","1113.60","1361.60"

Table: **PCI Ethernet**

NAND Driver
-------------------------



AM335X-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write UBIFS Throughput (Mbytes/sec)","am335x-evm: Write UBIFS CPU Load (%)","am335x-evm: Read UBIFS Throughput (Mbytes/sec)","am335x-evm: Read UBIFS CPU Load (%)"

    "102400","4.32 (min 4.29, max 4.38)","100.00","7.33","100.00"
    "262144","4.35 (min 4.32, max 4.37)","100.00","7.37","100.00"
    "524288","4.38 (min 4.33, max 4.41)","100.00","7.40","100.00"
    "1048576","4.39 (min 4.36, max 4.41)","100.00","7.42","100.00"
    "5242880","4.41 (min 4.39, max 4.43)","100.00","7.42","100.00"










OMAPL138-LCDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","omapl138-lcdk: Write UBIFS Throughput (Mbytes/sec)","omapl138-lcdk: Write UBIFS CPU Load (%)","omapl138-lcdk: Read UBIFS Throughput (Mbytes/sec)","omapl138-lcdk: Read UBIFS CPU Load (%)"

    "102400","1.36 (min 1.10, max 1.43)","100.00","2.01","100.00"
    "262144","1.43 (min 1.42, max 1.46)","100.00","2.01","100.00"
    "524288","1.44 (min 1.42, max 1.48)","100.00","2.02","100.00"
    "1048576","1.43 (min 1.41, max 1.46)","100.00","2.01","100.00"
    "5242880","1.44 (min 1.43, max 1.47)","100.00","2.00","100.00"





QSPI Flash Driver
-------------------------








AM654x-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
UBIFS
"""""""""""""""""""""""""""
.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write UBIFS Throughput (Mbytes/sec)","am654x-evm: Write UBIFS CPU Load (%)","am654x-evm: Read UBIFS Throughput (Mbytes/sec)","am654x-evm: Read UBIFS CPU Load (%)"

    "102400","0.64 (min 0.50, max 1.15)","39.04 (min 26.89, max 43.05)","54.98","7.69"
    "262144","0.48 (min 0.36, max 0.54)","41.67 (min 34.68, max 47.82)","62.83","14.29"
    "524288","0.48 (min 0.36, max 0.54)","44.70 (min 42.19, max 49.29)","54.86","13.33"
    "1048576","0.48 (min 0.36, max 0.54)","38.26 (min 31.08, max 43.44)","58.57","14.29"




RAW
"""""""""""""""""""""""""""
.. csv-table::
    :header: "File size (Mbytes)","am654x-evm: Raw Read Throughput (Mbytes/sec)"

    "50","125.00"













K2G-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write UBIFS Throughput (Mbytes/sec)","k2g-evm: Write UBIFS CPU Load (%)","k2g-evm: Read UBIFS Throughput (Mbytes/sec)","k2g-evm: Read UBIFS CPU Load (%)"

    "102400","0.47 (min 0.31, max 0.83)","100.00","13.51","7.14"
    "262144","0.39 (min 0.26, max 0.58)","100.00","13.46","29.41"
    "524288","0.42 (min 0.26, max 0.57)","100.00","13.41","7.69"
    "1048576","0.39 (min 0.27, max 0.58)","99.97 (min 99.85, max 100.00)","13.34","25.00"





SPI Flash Driver
-------------------------



K2G-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write UBIFS Throughput (Mbytes/sec)","k2g-evm: Write UBIFS CPU Load (%)","k2g-evm: Read UBIFS Throughput (Mbytes/sec)","k2g-evm: Read UBIFS CPU Load (%)"

    "102400","0.09 (min 0.08, max 0.13)","58.31 (min 38.67, max 64.65)","0.19","1.53"
    "262144","0.08 (min 0.08, max 0.09)","63.93 (min 60.71, max 65.95)","0.20","2.04"
    "524288","0.08 (min 0.08, max 0.09)","63.55 (min 61.44, max 65.38)","0.20","1.87"
    "1048576","0.08 (min 0.08, max 0.09)","64.63 (min 61.19, max 67.54)","0.20","1.21"








EMMC Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

|









AM57XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write VFAT Throughput (Mbytes/sec)","am57xx-evm: Write VFAT CPU Load (%)","am57xx-evm: Read VFAT Throughput (Mbytes/sec)","am57xx-evm: Read VFAT CPU Load (%)"

    "102400","12.08 (min 11.48, max 12.25)","2.43 (min 1.70, max 4.97)","65.18","9.03"
    "262144","12.05 (min 11.40, max 12.25)","2.29 (min 1.53, max 4.37)","67.98","7.62"
    "524288","11.95 (min 11.44, max 12.27)","2.43 (min 1.72, max 4.23)","72.70","9.69"
    "1048576","11.95 (min 10.84, max 12.26)","2.26 (min 1.59, max 4.26)","75.14","9.32"
    "5242880","11.94 (min 11.42, max 12.27)","2.31 (min 1.59, max 4.43)","74.88","9.32"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)"

    "102400","12.20 (min 11.93, max 12.30)","1.87 (min 1.24, max 3.77)","69.55","8.33"
    "262144","12.19 (min 11.96, max 12.27)","2.00 (min 1.30, max 4.11)","72.93","8.39"
    "524288","12.04 (min 11.57, max 12.26)","2.06 (min 1.44, max 3.54)","76.97","6.37"
    "1048576","12.05 (min 11.28, max 12.28)","1.96 (min 1.24, max 3.51)","78.50","3.16"
    "5242880","12.21 (min 11.97, max 12.28)","2.08 (min 1.24, max 3.95)","78.51","0.00"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "102400","12.10 (min 11.63, max 12.47)","1.87 (min 1.39, max 3.20)","70.19","7.77"
    "262144","12.40 (min 11.84, max 12.63)","2.00 (min 1.42, max 3.09)","73.62","8.45"
    "524288","12.41 (min 11.86, max 12.63)","1.88 (min 1.45, max 2.91)","78.12","9.23"
    "1048576","12.53 (min 12.40, max 12.59)","2.00 (min 1.51, max 3.27)","79.66","7.31"
    "5242880","12.44 (min 12.03, max 12.62)","1.95 (min 1.44, max 3.09)","79.79","8.71"

|










AM654x-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write VFAT Throughput (Mbytes/sec)","am654x-evm: Write VFAT CPU Load (%)","am654x-evm: Read VFAT Throughput (Mbytes/sec)","am654x-evm: Read VFAT CPU Load (%)"

    "102400","36.15 (min 31.19, max 37.52)","3.33 (min 2.57, max 6.11)","134.80","7.82"
    "262144","36.43 (min 32.33, max 37.56)","3.14 (min 2.42, max 5.71)","141.59","5.90"
    "524288","36.37 (min 32.28, max 37.59)","3.16 (min 2.32, max 5.62)","153.52","7.38"
    "1048576","36.62 (min 32.34, max 37.75)","3.17 (min 2.43, max 5.49)","151.78","7.66"
    "5242880","36.56 (min 32.48, max 37.71)","3.10 (min 2.43, max 5.43)","149.72","8.27"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write EXT2 Throughput (Mbytes/sec)","am654x-evm: Write EXT2 CPU Load (%)","am654x-evm: Read EXT2 Throughput (Mbytes/sec)","am654x-evm: Read EXT2 CPU Load (%)"

    "102400","21.01 (min 20.82, max 21.23)","1.15 (min 0.96, max 1.77)","130.72","8.10"
    "262144","21.00 (min 20.57, max 21.78)","1.11 (min 0.85, max 1.67)","139.66","7.07"
    "524288","20.85 (min 20.38, max 21.06)","1.07 (min 0.95, max 1.41)","160.46","6.25"
    "1048576","20.82 (min 20.35, max 20.96)","1.14 (min 0.90, max 1.70)","168.37","6.94"
    "5242880","20.98 (min 20.41, max 21.76)","1.14 (min 0.95, max 1.66)","168.75","8.16"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write EXT4 Throughput (Mbytes/sec)","am654x-evm: Write EXT4 CPU Load (%)","am654x-evm: Read EXT4 Throughput (Mbytes/sec)","am654x-evm: Read EXT4 CPU Load (%)"

    "102400","37.20 (min 36.70, max 37.62)","2.21 (min 1.89, max 2.88)","130.42","8.44"
    "262144","37.62 (min 36.56, max 38.32)","2.11 (min 1.78, max 2.62)","149.93","7.19"
    "524288","37.94 (min 37.06, max 38.23)","2.13 (min 1.82, max 2.82)","167.75","8.03"
    "1048576","37.99 (min 37.12, max 38.27)","2.01 (min 1.73, max 2.66)","181.19","9.01"
    "5242880","37.81 (min 37.06, max 38.30)","2.05 (min 1.73, max 2.92)","180.59","8.70"

|




































K2G-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write VFAT Throughput (Mbytes/sec)","k2g-evm: Write VFAT CPU Load (%)","k2g-evm: Read VFAT Throughput (Mbytes/sec)","k2g-evm: Read VFAT CPU Load (%)"

    "102400","21.33 (min 19.01, max 21.97)","13.78 (min 11.27, max 22.74)","39.63","17.56"
    "262144","21.57 (min 18.85, max 22.31)","13.50 (min 10.73, max 22.30)","40.60","16.47"
    "524288","21.33 (min 18.83, max 22.17)","13.62 (min 10.88, max 22.40)","41.64","16.00"
    "1048576","21.48 (min 18.87, max 22.32)","13.77 (min 11.13, max 22.02)","42.66","15.85"
    "5242880","21.58 (min 18.78, max 22.35)","13.48 (min 10.78, max 21.05)","42.71","15.57"

|



.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write EXT2 Throughput (Mbytes/sec)","k2g-evm: Write EXT2 CPU Load (%)","k2g-evm: Read EXT2 Throughput (Mbytes/sec)","k2g-evm: Read EXT2 CPU Load (%)"

    "102400","22.52 (min 21.06, max 23.03)","12.48 (min 9.45, max 22.16)","40.24","15.69"
    "262144","22.53 (min 20.79, max 23.05)","11.78 (min 8.65, max 21.63)","41.29","16.21"
    "524288","22.28 (min 20.74, max 22.92)","11.68 (min 8.70, max 21.43)","42.71","11.49"
    "1048576","22.33 (min 21.11, max 22.78)","12.15 (min 9.29, max 21.50)","43.03","14.46"
    "5242880","22.53 (min 20.80, max 23.02)","12.21 (min 9.45, max 21.00)","43.03","13.03"

|



.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write EXT4 Throughput (Mbytes/sec)","k2g-evm: Write EXT4 CPU Load (%)","k2g-evm: Read EXT4 Throughput (Mbytes/sec)","k2g-evm: Read EXT4 CPU Load (%)"

    "102400","21.65 (min 20.58, max 22.14)","11.39 (min 9.03, max 17.39)","37.85","15.64"
    "262144","21.24 (min 20.33, max 21.60)","11.82 (min 9.75, max 17.70)","38.94","15.30"
    "524288","21.34 (min 20.56, max 21.76)","11.91 (min 9.83, max 17.52)","39.99","13.79"
    "1048576","21.69 (min 20.94, max 22.10)","11.97 (min 10.21, max 17.67)","43.45","14.52"
    "5242880","21.72 (min 20.63, max 22.12)","12.50 (min 10.25, max 17.75)","43.47","15.92"

|



SATA Driver
-------------------------



.. rubric::  AM57XX-EVM
   :name: am57xx-evm


|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)"

    "102400","120.69 (min 110.35, max 125.62)","11.58 (min 5.69, max 33.70)","134.82","13.17"
    "262144","121.58 (min 108.30, max 125.61)","11.87 (min 6.27, max 33.53)","133.25","11.69"
    "524288","124.48 (min 121.38, max 125.52)","11.90 (min 6.11, max 33.81)","133.11","11.94"
    "1048576","123.96 (min 118.93, max 125.86)","11.81 (min 6.28, max 32.57)","133.11","10.99"
    "5242880","123.61 (min 120.95, max 125.26)","11.85 (min 5.93, max 32.55)","132.97","11.79"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "102400","120.83 (min 117.84, max 125.24)","10.84 (min 6.63, max 25.91)","130.43","11.33"
    "262144","120.64 (min 117.00, max 123.87)","10.57 (min 6.34, max 25.68)","129.18","10.98"
    "524288","117.18 (min 112.35, max 118.85)","10.92 (min 7.01, max 25.46)","130.05","10.62"
    "1048576","120.96 (min 116.91, max 124.70)","10.78 (min 6.62, max 25.19)","132.46","10.61"
    "5242880","123.51 (min 118.94, max 127.69)","11.42 (min 6.92, max 27.59)","133.33","11.10"

|




















|

|

|

-  Filesize used is : 1G
-  SATA II Harddisk used is: Seagate ST3500514NS 500G


mSATA Driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^




.. rubric::  AM57XX-EVM
   :name: am57xx-evm


|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)"

    "102400","64.03 (min 63.32, max 64.65)","4.80 (min 2.70, max 12.29)","225.49","22.10"
    "262144","64.13 (min 63.16, max 64.42)","4.84 (min 2.91, max 11.67)","235.13","21.09"
    "524288","64.04 (min 62.91, max 64.57)","3.54 (min 2.88, max 5.10)","249.58","21.84"
    "1048576","64.37 (min 62.99, max 64.89)","3.60 (min 2.90, max 5.27)","257.61","22.46"
    "5242880","64.08 (min 63.38, max 64.61)","3.41 (min 2.68, max 5.65)","257.34","20.88"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "102400","64.68 (min 64.12, max 65.00)","4.50 (min 3.67, max 6.54)","230.67","21.20"
    "262144","64.47 (min 64.17, max 64.74)","4.41 (min 3.57, max 7.28)","238.79","24.05"
    "524288","65.01 (min 63.70, max 67.14)","4.94 (min 3.64, max 9.36)","254.37","21.42"
    "1048576","67.76 (min 65.50, max 69.89)","4.89 (min 3.61, max 8.34)","265.18","22.25"
    "5242880","71.29 (min 67.31, max 75.80)","5.26 (min 4.09, max 8.94)","271.06","23.26"

|

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




AM335x-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write VFAT Throughput (Mbytes/sec)","am335x-evm: Write VFAT CPU Load (%)","am335x-evm: Read VFAT Throughput (Mbytes/sec)","am335x-evm: Read VFAT CPU Load (%)"

    "102400","9.69 (min 8.87, max 9.91)","9.87 (min 8.75, max 13.94)","20.59","23.61"
    "262144","9.55 (min 8.95, max 9.76)","9.79 (min 8.20, max 14.63)","20.66","22.49"
    "524288","9.50 (min 8.74, max 9.72)","9.78 (min 8.55, max 14.36)","21.14","19.02"
    "1048576","7.65 (min 6.90, max 8.60)","8.28 (min 6.58, max 13.63)","21.38","19.75"
    "5242880","9.60 (min 8.61, max 9.88)","9.83 (min 8.40, max 13.92)","21.33","18.46"

|



.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write EXT2 Throughput (Mbytes/sec)","am335x-evm: Write EXT2 CPU Load (%)","am335x-evm: Read EXT2 Throughput (Mbytes/sec)","am335x-evm: Read EXT2 CPU Load (%)"

    "102400","7.86 (min 3.91, max 10.11)","6.27 (min 4.32, max 7.36)","21.16","24.08"
    "262144","9.99 (min 8.75, max 10.59)","9.06 (min 7.29, max 15.12)","21.42","21.76"
    "524288","9.83 (min 8.91, max 10.24)","8.36 (min 6.59, max 12.55)","22.14","18.42"
    "1048576","9.97 (min 9.64, max 10.41)","8.98 (min 7.25, max 13.88)","22.36","16.12"
    "5242880","10.06 (min 9.26, max 10.28)","8.45 (min 7.16, max 12.49)","22.57","16.92"

|



.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write EXT4 Throughput (Mbytes/sec)","am335x-evm: Write EXT4 CPU Load (%)","am335x-evm: Read EXT4 Throughput (Mbytes/sec)","am335x-evm: Read EXT4 CPU Load (%)"

    "102400","9.66 (min 9.33, max 10.55)","8.42 (min 7.10, max 12.44)","18.02","19.55"
    "262144","9.23 (min 7.71, max 10.21)","8.67 (min 5.73, max 11.86)","21.72","22.85"
    "524288","9.82 (min 9.51, max 9.93)","8.84 (min 7.77, max 11.57)","22.36","18.53"
    "1048576","9.78 (min 9.45, max 9.89)","8.79 (min 7.55, max 11.90)","22.68","17.21"
    "5242880","9.74 (min 9.17, max 9.90)","8.68 (min 7.56, max 10.88)","22.85","17.18"

|


|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|







|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|



AM57XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write VFAT Throughput (Mbytes/sec)","am57xx-evm: Write VFAT CPU Load (%)","am57xx-evm: Read VFAT Throughput (Mbytes/sec)","am57xx-evm: Read VFAT CPU Load (%)"

    "102400","10.03 (min 9.06, max 10.98)","1.93 (min 1.19, max 3.60)","38.93","6.46"
    "262144","10.06 (min 9.07, max 10.40)","1.88 (min 1.43, max 3.39)","38.73","4.12"
    "524288","10.02 (min 9.47, max 10.29)","1.90 (min 1.32, max 3.63)","40.29","4.28"
    "1048576","10.05 (min 9.00, max 10.36)","1.88 (min 1.48, max 3.40)","41.13","4.36"
    "5242880","10.05 (min 9.07, max 10.31)","1.84 (min 1.23, max 3.43)","41.44","4.96"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)"

    "102400","9.85 (min 7.81, max 11.03)","1.47 (min 1.16, max 2.61)","38.92","1.92"
    "262144","10.94 (min 10.52, max 11.31)","1.83 (min 1.20, max 3.52)","40.12","4.78"
    "524288","11.71 (min 11.35, max 11.83)","1.78 (min 1.08, max 3.32)","42.02","3.05"
    "1048576","11.67 (min 11.30, max 11.81)","1.80 (min 1.13, max 3.47)","42.67","4.67"
    "5242880","11.26 (min 10.14, max 11.70)","1.79 (min 1.07, max 3.52)","42.66","5.07"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "102400","10.65 (min 9.51, max 12.20)","1.81 (min 1.37, max 2.99)","39.64","4.37"
    "262144","10.72 (min 10.40, max 11.06)","1.57 (min 1.12, max 2.64)","40.82","5.05"
    "524288","10.43 (min 10.20, max 10.51)","1.70 (min 1.41, max 2.64)","42.72","4.87"
    "1048576","10.46 (min 9.82, max 11.10)","1.63 (min 1.06, max 2.58)","43.53","2.75"
    "5242880","10.48 (min 10.34, max 10.53)","1.57 (min 1.21, max 2.72)","43.42","6.31"

|


|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|







|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|







|

The performance numbers were captured using the following:

-  SanDisk 8GB SDHC UHS Memory Card
-  Partition was mounted with async option

|



AM654x-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write VFAT Throughput (Mbytes/sec)","am654x-evm: Write VFAT CPU Load (%)","am654x-evm: Read VFAT Throughput (Mbytes/sec)","am654x-evm: Read VFAT CPU Load (%)"

    "102400","16.39 (min 15.23, max 16.76)","1.62 (min 1.19, max 3.31)","22.09","1.37"
    "262144","15.82 (min 13.59, max 16.88)","1.47 (min 0.88, max 3.09)","22.38","1.29"
    "524288","15.64 (min 13.92, max 16.60)","1.51 (min 1.00, max 3.09)","22.71","1.36"
    "1048576","15.78 (min 13.72, max 16.82)","1.46 (min 0.92, max 2.95)","22.55","1.35"
    "5242880","15.38 (min 13.39, max 16.74)","1.42 (min 0.94, max 2.65)","22.61","1.24"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write EXT2 Throughput (Mbytes/sec)","am654x-evm: Write EXT2 CPU Load (%)","am654x-evm: Read EXT2 Throughput (Mbytes/sec)","am654x-evm: Read EXT2 CPU Load (%)"

    "102400","16.85 (min 16.61, max 16.93)","0.95 (min 0.81, max 1.43)","22.61","1.08"
    "262144","16.75 (min 16.37, max 16.91)","0.93 (min 0.80, max 1.29)","22.96","0.88"
    "524288","16.46 (min 15.65, max 16.83)","0.93 (min 0.75, max 1.32)","23.45","1.67"
    "1048576","16.74 (min 16.36, max 16.90)","0.89 (min 0.77, max 1.29)","23.57","1.01"
    "5242880","16.62 (min 15.80, max 16.90)","0.87 (min 0.76, max 1.21)","23.56","1.52"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write EXT4 Throughput (Mbytes/sec)","am654x-evm: Write EXT4 CPU Load (%)","am654x-evm: Read EXT4 Throughput (Mbytes/sec)","am654x-evm: Read EXT4 CPU Load (%)"

    "102400","17.23 (min 16.71, max 17.48)","1.04 (min 0.96, max 1.24)","22.70","1.25"
    "262144","16.89 (min 16.50, max 17.45)","0.98 (min 0.88, max 1.22)","23.11","1.27"
    "524288","16.45 (min 13.85, max 17.36)","0.95 (min 0.76, max 1.24)","23.62","1.13"
    "1048576","16.18 (min 13.85, max 17.44)","0.90 (min 0.85, max 0.96)","23.79","1.92"
    "5242880","17.12 (min 16.96, max 17.37)","0.96 (min 0.81, max 1.27)","23.79","0.23"

|


|

The performance numbers were captured using the following:

-  SanDisk 8GB SDHC UHS Memory Card
-  Partition was mounted with async option

|







|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|







|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|







|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|







|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|



K2G-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write VFAT Throughput (Mbytes/sec)","k2g-evm: Write VFAT CPU Load (%)","k2g-evm: Read VFAT Throughput (Mbytes/sec)","k2g-evm: Read VFAT CPU Load (%)"

    "102400","9.22 (min 6.16, max 10.45)","13.02 (min 4.92, max 44.25)","21.33","10.41"
    "262144","9.54 (min 8.95, max 9.76)","6.58 (min 5.00, max 11.69)","21.42","9.48"
    "524288","9.61 (min 8.60, max 9.87)","6.14 (min 4.55, max 10.42)","22.06","9.64"
    "1048576","9.38 (min 8.35, max 9.76)","6.03 (min 4.66, max 10.69)","22.27","8.92"
    "5242880","8.90 (min 8.25, max 9.56)","5.86 (min 4.24, max 10.27)","22.24","8.92"

|



.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write EXT2 Throughput (Mbytes/sec)","k2g-evm: Write EXT2 CPU Load (%)","k2g-evm: Read EXT2 Throughput (Mbytes/sec)","k2g-evm: Read EXT2 CPU Load (%)"

    "102400","8.86 (min 8.06, max 9.18)","4.70 (min 3.50, max 8.10)","21.70","5.41"
    "262144","9.79 (min 9.50, max 10.05)","5.43 (min 4.00, max 9.98)","21.87","7.86"
    "524288","9.91 (min 9.50, max 10.10)","5.25 (min 3.91, max 9.39)","22.55","7.58"
    "1048576","9.69 (min 9.24, max 10.06)","5.21 (min 3.77, max 9.76)","22.73","6.99"
    "5242880","9.40 (min 9.15, max 9.82)","4.87 (min 3.60, max 9.28)","22.54","7.33"

|



.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write EXT4 Throughput (Mbytes/sec)","k2g-evm: Write EXT4 CPU Load (%)","k2g-evm: Read EXT4 Throughput (Mbytes/sec)","k2g-evm: Read EXT4 CPU Load (%)"

    "102400","8.90 (min 8.52, max 9.47)","5.02 (min 3.98, max 8.31)","21.76","10.08"
    "262144","9.13 (min 8.79, max 9.52)","5.01 (min 3.80, max 7.63)","22.09","7.68"
    "524288","9.19 (min 8.74, max 9.63)","4.69 (min 3.78, max 7.75)","22.63","8.97"
    "1048576","9.74 (min 9.44, max 10.08)","5.64 (min 4.24, max 8.70)","22.82","6.81"
    "5242880","9.45 (min 9.08, max 9.64)","5.35 (min 4.33, max 8.09)","22.83","7.24"

|


|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|



OMAPL138-LCDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","omapl138-lcdk: Write VFAT Throughput (Mbytes/sec)","omapl138-lcdk: Write VFAT CPU Load (%)","omapl138-lcdk: Read VFAT Throughput (Mbytes/sec)","omapl138-lcdk: Read VFAT CPU Load (%)"

    "102400","6.59 (min 4.31, max 7.56)","85.87 (min 67.18, max 97.29)","14.99","66.62"
    "262144","6.60 (min 4.50, max 7.61)","74.81 (min 55.46, max 81.54)","14.58","61.99"
    "524288","6.74 (min 4.61, max 7.76)","72.87 (min 56.39, max 79.58)","14.98","59.11"
    "1048576","6.48 (min 4.49, max 7.32)","75.17 (min 55.56, max 87.81)","13.93","63.66"
    "5242880","6.66 (min 4.77, max 7.58)","77.34 (min 58.03, max 84.41)","13.29","55.18"

|



.. csv-table::
    :header: "Buffer size (bytes)","omapl138-lcdk: Write EXT2 Throughput (Mbytes/sec)","omapl138-lcdk: Write EXT2 CPU Load (%)","omapl138-lcdk: Read EXT2 Throughput (Mbytes/sec)","omapl138-lcdk: Read EXT2 CPU Load (%)"

    "102400","5.90 (min 3.67, max 6.93)","59.33 (min 53.15, max 67.00)","14.63","65.08"
    "262144","6.66 (min 6.21, max 6.98)","53.96 (min 46.74, max 61.55)","15.39","59.04"
    "524288","6.87 (min 6.39, max 7.36)","55.80 (min 49.04, max 63.02)","15.90","57.05"
    "1048576","6.77 (min 6.25, max 7.51)","56.50 (min 47.72, max 64.72)","16.14","55.40"
    "5242880","7.03 (min 6.62, max 7.36)","56.29 (min 51.51, max 66.25)","15.83","56.39"

|



.. csv-table::
    :header: "Buffer size (bytes)","omapl138-lcdk: Write EXT4 Throughput (Mbytes/sec)","omapl138-lcdk: Write EXT4 CPU Load (%)","omapl138-lcdk: Read EXT4 Throughput (Mbytes/sec)","omapl138-lcdk: Read EXT4 CPU Load (%)"

    "102400","6.99 (min 5.88, max 7.95)","85.39 (min 76.51, max 91.99)","15.07","63.36"
    "262144","7.62 (min 7.30, max 8.38)","83.85 (min 77.98, max 88.48)","15.58","58.07"
    "524288","7.83 (min 7.33, max 8.31)","86.96 (min 82.56, max 91.45)","15.86","57.10"
    "1048576","7.94 (min 7.48, max 8.27)","84.82 (min 78.71, max 90.98)","16.22","55.99"
    "5242880","7.30 (min 6.27, max 8.30)","84.77 (min 78.43, max 91.46)","15.78","61.22"

|


|

|

|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|

UART Driver
-------------------------

Performance and Benchmarks not available in this release.

|

I2C Driver
-------------------------

Performance and Benchmarks not available in this release.

|

EDMA Driver
-------------------------

Performance and Benchmarks not available in this release.

|

Touchscreen Driver
-------------------------

Performance and Benchmarks not available in this release.

|

USB Driver
-------------------------

MUSB/XHCI Host controller
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


Table: **USB Host VFAT**

.. csv-table:: 
    :header: "Buffer size (bytes)","am335x-evm: Write VFAT Throughput (Mbytes/sec)","am335x-evm: Write VFAT CPU Load (%)","am335x-evm: Read VFAT Throughput (Mbytes/sec)","am335x-evm: Read VFAT CPU Load (%)"

    "102400","20.34 (min 18.93, max 20.75)","30.87 (min 28.45, max 38.26)","13.78","33.92"
    "262144","20.54 (min 19.09, max 21.00)","29.58 (min 26.75, max 38.36)","13.82","35.10"

.. csv-table:: 
    :header: "Buffer size (bytes)","am57xx-evm: Write VFAT Throughput (Mbytes/sec)","am57xx-evm: Write VFAT CPU Load (%)","am57xx-evm: Read VFAT Throughput (Mbytes/sec)","am57xx-evm: Read VFAT CPU Load (%)"

    "102400","282.3","53.4","337.0","41.2"
    "262144","250.4","51.2","309.0","39.0"

.. csv-table:: 
    :header: "Buffer size (bytes)","am654x-evm: Write VFAT Throughput (Mbytes/sec)","am654x-evm: Write VFAT CPU Load (%)","am654x-evm: Read VFAT Throughput (Mbytes/sec)","am654x-evm: Read VFAT CPU Load (%)"

    "102400","37.8","3.9","40.1","3.2"
    "262144","38.1","3.6","40.1","2.8"


Table: **USB Host EXT2**


.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write EXT2 Throughput (Mbytes/sec)","am335x-evm: Write EXT2 CPU Load (%)","am335x-evm: Read EXT2 Throughput (Mbytes/sec)","am335x-evm: Read EXT2 CPU Load (%)"

    "102400","20.97 (min 19.35, max 21.41)","27.10 (min 23.68, max 36.06)","13.76","36.50"
    "1048576","20.92 (min 19.37, max 21.35)","27.65 (min 24.12, max 37.96)","13.76","37.11"
    "5242880","20.94 (min 19.45, max 21.36)","26.09 (min 22.94, max 35.70)","13.76","34.71"

.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)"

    "102400","301.6","47.2","336.0","36.1"
    "1048576","302.3","48.0","377.3","36.2"
    "5242880","301.9","48.8", "375.8","41.2"

.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write EXT2 Throughput (Mbytes/sec)","am654x-evm: Write EXT2 CPU Load (%)","am654x-evm: Read EXT2 Throughput (Mbytes/sec)","am654x-evm: Read EXT2 CPU Load (%)"

    "102400","38.0","2.8","39.9","3.1"
    "1048576","38.6","2.5","39.7","3.6"
    "5242880","38.4","2.6", "40.0","4.0"


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
    :header: "Algorithm","Buffer Size","am335x-evm: throughput","am57xx-evm: throughput","am654x-evm: throughput"

    "aes-128-cbc","1024","12440.58","14302.55","537919.83"
    "aes-128-cbc","16","2399.79","4464.27","70455.33"
    "aes-128-cbc","16384","","","602073.77"
    "aes-128-cbc","256","4754.60","5116.07","399948.54"
    "aes-128-cbc","64","7921.56","14317.91","209192.30"
    "aes-128-cbc","8192","20179.63","31984.30","598048.77"
    "aes-192-cbc","1024","12243.63","14341.12","414869.50"
    "aes-192-cbc","16","2440.83","4335.48","67160.60"
    "aes-192-cbc","16384","","","452558.85"
    "aes-192-cbc","256","4536.23","5152.77","326766.25"
    "aes-192-cbc","64","7748.16","13682.07","185853.16"
    "aes-192-cbc","8192","18882.56","31921.49","449609.73"
    "aes-256-cbc","1024","12170.92","14287.87","347074.56"
    "aes-256-cbc","16","2372.08","4394.19","65066.67"
    "aes-256-cbc","16384","","","373074.60"
    "aes-256-cbc","256","4468.22","5142.02","283101.10"
    "aes-256-cbc","64","7417.77","13389.85","170202.03"
    "aes-256-cbc","8192","18112.51","31910.57","371520.85"
    "des-cbc","1024","14922.07","9233.75","14609.75"
    "des-cbc","16","2445.70","314.63","11813.42"
    "des-cbc","16384","","","14658.22"
    "des-cbc","256","12132.27","3934.21","14425.00"
    "des-cbc","64","6800.45","1184.30","13793.62"
    "des-cbc","8192","16102.74","15332.69","14660.95"
    "des3","1024","6383.27","9119.40","5196.46"
    "des3","16","2018.98","314.70","4828.97"
    "des3","16384","","","5204.65"
    "des3","256","5835.86","3907.75","5176.58"
    "des3","64","4259.39","1187.20","5097.94"
    "des3","8192","6640.98","14273.19","5201.92"
    "md5","1024","9895.25","13707.26","90096.98"
    "md5","16","506.38","871.53","7840.18"
    "md5","16384","","","108702.38"
    "md5","256","3665.15","4848.30","58302.12"
    "md5","64","2010.39","3414.53","24150.68"
    "md5","8192","37019.65","57387.69","107096.75"
    "sha1","1024","9667.24","13008.21","232010.75"
    "sha1","16","462.61","778.33","9778.00"
    "sha1","16384","","","360890.37"
    "sha1","256","3646.38","4681.56","109169.75"
    "sha1","64","1847.68","3040.75","34852.76"
    "sha1","8192","36549.97","55577.26","348312.92"


|
|

.. csv-table::
    :header: "Algorithm","am335x-evm: CPU Load","am57xx-evm: CPU Load","am654x-evm: CPU Load"

    "aes-128-cbc","51.00","52.00","99.00"
    "aes-192-cbc","51.00","52.00","99.00"
    "aes-256-cbc","51.00","52.00","99.00"
    "des-cbc","98.00","23.00","99.00"
    "des3","98.00","23.00","99.00"
    "md5","78.00","77.00","99.00"
    "sha1","76.00","75.00","99.00"



-

|
| Listed for each algorithm are the code snippets used to run each
  benchmark test.

|

::

    time -v openssl speed -elapsed -evp aes-128-cbc

-

IPSec Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Note: queue\_len is set to 300 and software fallback threshold set to 9
to enable software support for optimal performance

.. csv-table::
    :header: "Algorithm","am335x-evm: Throughput","am335x-evm: Packets/Sec","am335x-evm: CPU Load","am57xx-evm: Throughput","am57xx-evm: Packets/Sec","am57xx-evm: CPU Load"

    "3des","7.00","0.00","87.80"
    "aes128","5.80","0.00","55.20","106.40","9.00","53.20"
    "aes192","11.90","0.00","74.60","144.30","12.00","61.10"
    "aes256","16.00","1.00","76.00","144.40","12.00","62.10"



DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.

Power Management
-------------------------













    




    

