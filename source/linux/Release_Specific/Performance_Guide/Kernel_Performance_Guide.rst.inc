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
   :name: about-this-manual-kernel-perf-guide

This document provides performance data for each of the device drivers
which are part of the Process SDK Linux package. This document should be
used in conjunction with release notes and user guides provided with the
Process SDK Linux package for information on specific issues present
with drivers included in a particular release.

.. rubric::  If You Need Assistance
   :name: if-you-need-assistance-kernel-perf-guide

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

    "af_unix_sock_stream_latency (microsec)","43.11","28.31","42.81","47.32","678.71"
    "af_unix_socket_stream_bandwidth (MBs)","173.98","2075.27","1175.86","656.56","30.64"
    "bw_file_rd-io-1mb (MB/s)","179.95","1503.19","1190.71","713.14","43.99"
    "bw_file_rd-o2c-1mb (MB/s)","154.06","1066.29","790.51","543.38","39.71"
    "bw_mem-bcopy-16mb (MB/s)","211.31","1950.27","816.62","1244.85","39.71"
    "bw_mem-bcopy-1mb (MB/s)","199.04","4934.52","1542.32","1350.57","96.69"
    "bw_mem-bcopy-2mb (MB/s)","200.68","2764.07","921.66","1253.92","96.92"
    "bw_mem-bcopy-4mb (MB/s)","207.23","2033.55","826.28","1247.86","98.63"
    "bw_mem-bcopy-8mb (MB/s)","218.14","1963.67","818.16","1246.88","96.51"
    "bw_mem-bzero-16mb (MB/s)","995.77","4986.75","1959.34","3401.00","192.97"
    "bw_mem-bzero-1mb (MB/s)","591.49 (min 199.04, max 983.93)","5322.83 (min 4934.52, max 5711.13)","2927.55 (min 1542.32, max 4312.77)","2910.03 (min 1350.57, max 4469.49)","143.77 (min 96.69, max 190.84)"
    "bw_mem-bzero-2mb (MB/s)","598.10 (min 200.68, max 995.52)","4128.79 (min 2764.07, max 5493.50)","2571.75 (min 921.66, max 4221.84)","2588.13 (min 1253.92, max 3922.34)","144.65 (min 96.92, max 192.38)"
    "bw_mem-bzero-4mb (MB/s)","595.68 (min 207.23, max 984.13)","3667.10 (min 2033.55, max 5300.65)","1619.78 (min 826.28, max 2413.27)","2446.75 (min 1247.86, max 3645.64)","145.78 (min 98.63, max 192.92)"
    "bw_mem-bzero-8mb (MB/s)","603.14 (min 218.14, max 988.14)","3541.02 (min 1963.67, max 5118.36)","1407.96 (min 818.16, max 1997.75)","2370.17 (min 1246.88, max 3493.45)","144.83 (min 96.51, max 193.15)"
    "bw_mem-cp-16mb (MB/s)","197.05","1044.66","482.38","605.26","189.47"
    "bw_mem-cp-1mb (MB/s)","593.40 (min 194.40, max 992.39)","4957.56 (min 4215.54, max 5699.58)","2638.47 (min 839.35, max 4437.58)","2620.03 (min 607.63, max 4632.43)","147.53 (min 105.59, max 189.47)"
    "bw_mem-cp-2mb (MB/s)","592.35 (min 192.47, max 992.23)","3418.66 (min 1219.33, max 5617.98)","2399.73 (min 546.60, max 4252.85)","2280.00 (min 604.59, max 3955.41)","149.47 (min 106.72, max 192.22)"
    "bw_mem-cp-4mb (MB/s)","600.71 (min 199.53, max 1001.88)","3173.29 (min 1041.53, max 5305.04)","1453.98 (min 491.40, max 2416.55)","2125.09 (min 601.87, max 3648.30)","149.78 (min 106.20, max 193.36)"
    "bw_mem-cp-8mb (MB/s)","603.92 (min 202.80, max 1005.03)","3053.62 (min 1018.98, max 5088.25)","1238.98 (min 481.70, max 1996.26)","2037.28 (min 610.36, max 3464.20)","148.30 (min 103.48, max 193.12)"
    "bw_mem-fcp-16mb (MB/s)","298.12","1077.08","808.24","610.31","190.84"
    "bw_mem-fcp-1mb (MB/s)","638.55 (min 293.17, max 983.93)","4317.30 (min 2923.47, max 5711.13)","2908.97 (min 1505.17, max 4312.77)","2537.59 (min 605.69, max 4469.49)","133.43 (min 76.02, max 190.84)"
    "bw_mem-fcp-2mb (MB/s)","645.02 (min 294.51, max 995.52)","3350.98 (min 1208.46, max 5493.50)","2568.52 (min 915.19, max 4221.84)","2264.80 (min 607.26, max 3922.34)","134.84 (min 77.29, max 192.38)"
    "bw_mem-fcp-4mb (MB/s)","639.20 (min 294.27, max 984.13)","3189.92 (min 1079.19, max 5300.65)","1617.78 (min 822.28, max 2413.27)","2123.08 (min 600.51, max 3645.64)","134.92 (min 76.92, max 192.92)"
    "bw_mem-fcp-8mb (MB/s)","643.89 (min 299.63, max 988.14)","3096.17 (min 1073.97, max 5118.36)","1404.76 (min 811.77, max 1997.75)","2052.80 (min 612.14, max 3493.45)","134.11 (min 75.07, max 193.15)"
    "bw_mem-frd-16mb (MB/s)","249.26","1054.23","1317.20","825.38","134.30"
    "bw_mem-frd-1mb (MB/s)","280.67 (min 268.17, max 293.17)","3008.32 (min 2923.47, max 3093.16)","1508.89 (min 1505.17, max 1512.61)","770.66 (min 605.69, max 935.63)","104.51 (min 76.02, max 133.00)"
    "bw_mem-frd-2mb (MB/s)","273.47 (min 252.43, max 294.51)","1743.18 (min 1208.46, max 2277.90)","1231.14 (min 915.19, max 1547.09)","720.76 (min 607.26, max 834.26)","105.47 (min 77.29, max 133.65)"
    "bw_mem-frd-4mb (MB/s)","271.78 (min 249.28, max 294.27)","1144.19 (min 1079.19, max 1209.19)","1117.48 (min 822.28, max 1412.68)","713.69 (min 600.51, max 826.87)","105.72 (min 76.92, max 134.52)"
    "bw_mem-frd-8mb (MB/s)","274.42 (min 249.21, max 299.63)","1070.39 (min 1066.81, max 1073.97)","1066.39 (min 811.77, max 1321.00)","719.08 (min 612.14, max 826.02)","104.83 (min 75.07, max 134.58)"
    "bw_mem-fwr-16mb (MB/s)","995.21","4972.80","1956.23","3376.24","193.23"
    "bw_mem-fwr-1mb (MB/s)","630.28 (min 268.17, max 992.39)","4396.37 (min 3093.16, max 5699.58)","2975.10 (min 1512.61, max 4437.58)","2784.03 (min 935.63, max 4632.43)","161.24 (min 133.00, max 189.47)"
    "bw_mem-fwr-2mb (MB/s)","622.33 (min 252.43, max 992.23)","3947.94 (min 2277.90, max 5617.98)","2899.97 (min 1547.09, max 4252.85)","2394.84 (min 834.26, max 3955.41)","162.94 (min 133.65, max 192.22)"
    "bw_mem-fwr-4mb (MB/s)","625.58 (min 249.28, max 1001.88)","3257.12 (min 1209.19, max 5305.04)","1914.62 (min 1412.68, max 2416.55)","2237.59 (min 826.87, max 3648.30)","163.94 (min 134.52, max 193.36)"
    "bw_mem-fwr-8mb (MB/s)","627.12 (min 249.21, max 1005.03)","3077.53 (min 1066.81, max 5088.25)","1658.63 (min 1321.00, max 1996.26)","2145.11 (min 826.02, max 3464.20)","163.85 (min 134.58, max 193.12)"
    "bw_mem-rd-16mb (MB/s)","252.03","3041.83","1290.22","2437.91","143.96"
    "bw_mem-rd-1mb (MB/s)","628.47 (min 273.00, max 983.93)","12180.05 (min 10906.36, max 13453.74)","2087.09 (min 2037.01, max 2137.17)","1784.65 (min 869.72, max 2699.58)","438.39 (min 142.57, max 734.21)"
    "bw_mem-rd-2mb (MB/s)","619.92 (min 255.59, max 984.25)","8883.72 (min 8807.20, max 8960.24)","1794.40 (min 1748.86, max 1839.93)","1584.61 (min 702.25, max 2466.96)","440.33 (min 144.28, max 736.38)"
    "bw_mem-rd-4mb (MB/s)","629.79 (min 251.76, max 1007.81)","2480.41 (min 1610.74, max 3350.08)","1231.95 (min 1057.92, max 1405.98)","1572.43 (min 706.21, max 2438.65)","438.37 (min 143.87, max 732.87)"
    "bw_mem-rd-8mb (MB/s)","618.04 (min 251.59, max 984.49)","2189.89 (min 1304.42, max 3075.35)","1113.83 (min 932.94, max 1294.71)","1564.93 (min 700.83, max 2429.03)","441.79 (min 144.27, max 739.30)"
    "bw_mem-rdwr-16mb (MB/s)","203.03","1186.68","886.52","668.59","117.15"
    "bw_mem-rdwr-1mb (MB/s)","200.55 (min 194.40, max 206.70)","5900.68 (min 4215.54, max 7585.81)","1365.93 (min 839.35, max 1892.51)","708.35 (min 607.63, max 809.06)","111.33 (min 105.59, max 117.07)"
    "bw_mem-rdwr-2mb (MB/s)","197.81 (min 192.47, max 203.15)","2686.15 (min 1219.33, max 4152.97)","1122.34 (min 546.60, max 1698.08)","638.54 (min 604.59, max 672.49)","111.99 (min 106.72, max 117.26)"
    "bw_mem-rdwr-4mb (MB/s)","201.34 (min 199.53, max 203.14)","1208.05 (min 1041.53, max 1374.57)","764.44 (min 491.40, max 1037.48)","636.17 (min 601.87, max 670.47)","112.10 (min 106.20, max 118.00)"
    "bw_mem-rdwr-8mb (MB/s)","202.78 (min 202.75, max 202.80)","1113.72 (min 1018.98, max 1208.46)","690.49 (min 481.70, max 899.28)","640.95 (min 610.36, max 671.54)","110.44 (min 103.48, max 117.40)"
    "bw_mem-wr-16mb (MB/s)","996.14","1278.67","921.29","698.60","740.19"
    "bw_mem-wr-1mb (MB/s)","595.32 (min 206.70, max 983.93)","10519.78 (min 7585.81, max 13453.74)","1964.76 (min 1892.51, max 2037.01)","839.39 (min 809.06, max 869.72)","425.64 (min 117.07, max 734.21)"
    "bw_mem-wr-2mb (MB/s)","593.70 (min 203.15, max 984.25)","6556.61 (min 4152.97, max 8960.24)","1723.47 (min 1698.08, max 1748.86)","687.37 (min 672.49, max 702.25)","426.82 (min 117.26, max 736.38)"
    "bw_mem-wr-4mb (MB/s)","605.48 (min 203.14, max 1007.81)","1492.66 (min 1374.57, max 1610.74)","1047.70 (min 1037.48, max 1057.92)","688.34 (min 670.47, max 706.21)","425.44 (min 118.00, max 732.87)"
    "bw_mem-wr-8mb (MB/s)","593.62 (min 202.75, max 984.49)","1256.44 (min 1208.46, max 1304.42)","916.11 (min 899.28, max 932.94)","686.19 (min 671.54, max 700.83)","428.35 (min 117.40, max 739.30)"
    "bw_mmap_rd-mo-1mb (MB/s)","263.05","4126.30","2080.08","1558.44","133.05"
    "bw_mmap_rd-o2c-1mb (MB/s)","174.28","1318.52","962.46","618.52","85.01"
    "bw_pipe (MB/s)","288.71","579.06","1012.37","417.20","28.06"
    "bw_unix (MB/s)","173.98","2075.27","1175.86","656.56","30.64"
    "lat_connect (us)","78.87","56.58","66.19","88.75","1079.50"
    "lat_ctx-2-128k (us)","27.34","3.37","9.19","6.12","178.77"
    "lat_ctx-2-256k (us)","4.00","4.00","10.87","4.00","155.50"
    "lat_ctx-4-128k (us)","57.19","5.59","12.29","3.49","199.85"
    "lat_ctx-4-256k (us)","0.00","0.00","17.86","0.00","155.58"
    "lat_fs-0k (num_files)","215.00","340.00","259.00","194.00","18.00"
    "lat_fs-10k (num_files)","75.00","138.00","76.00","88.00","8.00"
    "lat_fs-1k (num_files)","117.00","199.00","84.00","132.00","11.00"
    "lat_fs-4k (num_files)","117.00","200.00","76.00","119.00","11.00"
    "lat_mem_rd-stride128-sz1000k (ns)","222.64","12.82","29.73","124.53","231.42"
    "lat_mem_rd-stride128-sz125k (ns)","11.76","12.68","9.48","20.05","220.64"
    "lat_mem_rd-stride128-sz250k (ns)","49.41","12.82","10.14","20.16","219.59"
    "lat_mem_rd-stride128-sz31k (ns)","3.01","6.44","3.82","12.05","178.08"
    "lat_mem_rd-stride128-sz50 (ns)","3.01","2.67","3.77","4.01","5.07"
    "lat_mem_rd-stride128-sz500k (ns)","185.70","12.82","10.47","37.20","231.51"
    "lat_mem_rd-stride128-sz62k (ns)","9.14","12.68","8.03","20.06","221.60"
    "lat_mmap-1m (us)","63.00","52.00","23.00","77.00","686.00"
    "lat_ops-double-add (ns)","2.38","0.73","0.91","1.09","35.21"
    "lat_ops-double-mul (ns)","11.08","3.35","5.01","5.01","100.11"
    "lat_ops-float-add (ns)","2.28","0.73","0.91","1.09","21.51"
    "lat_ops-float-mul (ns)","10.06","3.34","5.02","5.01","66.18"
    "lat_ops-int-add (ns)","1.01","0.67","1.26","1.00","1.68"
    "lat_ops-int-bit (ns)","0.67","0.45","0.84","0.67","2.54"
    "lat_ops-int-div (ns)","58.24","58.50","7.53","87.73","190.70"
    "lat_ops-int-mod (ns)","23.50","10.27","7.94","15.40","88.39"
    "lat_ops-int-mul (ns)","6.07","2.10","3.80","3.14","6.60"
    "lat_ops-int64-add (ns)","1.20","0.74","1.25","1.10","5.29"
    "lat_ops-int64-bit (ns)","1.04","0.68","0.84","1.02","2.58"
    "lat_ops-int64-div (ns)","245.07","126.32","11.93","190.00","835.74"
    "lat_ops-int64-mod (ns)","71.19","22.71","9.19","34.12","253.38"
    "lat_pagefault (us)","1.69","1.01","3.19","1.73","8.51"
    "lat_pipe (us)","34.29","24.37","24.40","34.30","494.95"
    "lat_proc-exec (us)","2045.67","979.17","1379.75","1218.20","7480.00"
    "lat_proc-fork (us)","1644.50","918.83","1272.40","1176.80","6863.00"
    "lat_proc-proccall (us)","0.02","0.01","0.01","0.01","0.07"
    "lat_select (us)","45.65","28.83","59.07","49.01","237.82"
    "lat_sem (us)","4.87","2.48","4.72","9.25","144.85"
    "lat_sig-catch (us)","6.44","3.53","7.34","5.78","38.82"
    "lat_sig-install (us)","1.39","0.63","0.90","0.97","6.22"
    "lat_sig-prot (us)","0.46","0.39","0.65","0.24","0.74"
    "lat_syscall-fstat (us)","3.22","2.40","3.53","3.52","9.18"
    "lat_syscall-null (us)","0.56","0.31","0.55","0.46","2.12"
    "lat_syscall-open (us)","290.10","151.26","200.77","206.44","1544.75"
    "lat_syscall-read (us)","1.10","0.47","1.24","0.68","4.23"
    "lat_syscall-stat (us)","7.90","5.21","7.57","7.88","48.72"
    "lat_syscall-write (us)","0.74","0.38","0.83","0.57","3.92"
    "lat_tcp (us)","1.04","0.59","1.04","0.87","2.81"
    "lat_unix (us)","43.11","28.31","42.81","47.32","678.71"
    "latency_for_0.50_mb_block_size (nanosec)","185.70","12.82","10.47","37.20","231.51"
    "latency_for_1.00_mb_block_size (nanosec)","111.32 (min 0.00, max 222.64)","6.41 (min 0.00, max 12.82)","14.86 (min 0.00, max 29.73)","62.26 (min 0.00, max 124.53)","115.71 (min 0.00, max 231.42)"
    "pipe_bandwidth (MBs)","288.71","579.06","1012.37","417.20","28.06"
    "pipe_latency (microsec)","34.29","24.37","24.40","34.30","494.95"
    "procedure_call (microsec)","0.02","0.01","0.01","0.01","0.07"
    "select_on_200_tcp_fds (microsec)","45.65","28.83","59.07","49.01","237.82"
    "semaphore_latency (microsec)","4.87","2.48","4.72","9.25","144.85"
    "signal_handler_latency (microsec)","1.39","0.63","0.90","0.97","6.22"
    "signal_handler_overhead (microsec)","6.44","3.53","7.34","5.78","38.82"
    "tcp_ip_connection_cost_to_localhost (microsec)","78.87","56.58","66.19","88.75","1079.50"
    "tcp_latency_using_localhost (microsec)","1.04","0.59","1.04","0.87","2.81"


Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.
  
.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am57xx-evm: perf","am654x-evm: perf","k2g-evm: perf","omapl138-lcdk: perf"

    "cpu_clock (MHz)","1000.00","1500.00","400.00","50.00","230.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.00","3.30","5.90","67.00","1.80"
    "dhrystone_per_second (DhrystoneP)","3571428.50","8695652.00","4166666.80","5882353.00","735294.10"


Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am57xx-evm: perf","am654x-evm: perf","k2g-evm: perf","omapl138-lcdk: perf"

    "whetstone (MIPS)","1000.00","3333.30","3333.30","2500.00","31.60"


Table:  **Whetstone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
sloving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am57xx-evm: perf","am654x-evm: perf","k2g-evm: perf","omapl138-lcdk: perf"

    "linpack (Kflops)","52763.00","948697.00","336535.00","626121.00","7465.00"


Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am57xx-evm: perf","am654x-evm: perf","k2g-evm: perf","omapl138-lcdk: perf"

    "assignment (Iterations)","8.07","19.89","7.71","13.23","0.99"
    "fourier (Iterations)","2372.50","18969.00","8257.80","12539.00","121.72"
    "fp_emulation (Iterations)","51.80","92.60","61.53","61.65","19.80"
    "huffman (Iterations)","706.28","1355.30","673.88","903.17","220.32"
    "idea (Iterations)","1561.60","4297.20","1920.50","2862.80","451.90"
    "lu_decomposition (Iterations)","75.84","822.57","323.40","550.96","5.85"
    "neural_net (Iterations)","2.07","23.07","4.22","15.53","0.19"
    "numeric_sort (Iterations)","443.49","758.50","299.10","510.06","103.72"
    "string_sort (Iterations)","66.75","140.98","94.71","93.94","7.97"


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

    "add (MB/s)","396.30","3815.80","1759.00","2431.40"
    "copy (MB/s)","441.80","3933.10","1944.20","2517.60"
    "scale (MB/s)","640.70","4371.20","1988.20","2412.60"
    "triad (MB/s)","425.40","3875.10","1652.10","2404.80"


Table:  **Stream**

CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.



Table:  **CoreMarkPro**

MultiBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
MultiBench is a suite of benchmarks that allows processor and system designers to
analyze, test, and improve multicore processors. It uses three forms of concurrency:
Data decomposition: multiple threads cooperating on achieving a unified goal and
demonstrating a processors support for fine grain parallelism.
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




Table:  **Spec2K6**


Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am335x-evm: boot time (sec)","am57xx-evm: boot time (sec)","am654x-evm: boot time (sec)","k2g-evm: boot time (sec)","omapl138-lcdk: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","45.61 (min 45.41, max 45.76)","26.74 (min 26.19, max 27.94)","15.08 (min 14.38, max 15.84)","34.52 (min 34.38, max 34.89)","125.64 (min 125.15, max 126.21)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","5.60 (min 5.57, max 5.62)","6.90 (min 6.88, max 6.92)","7.53 (min 7.49, max 7.54)","9.18 (min 8.84, max 10.43)"

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

    "8000","255998.00","3.00","255982.00","0.13","255995.00","0.26","352798.00","0.45","256004.00","2.54"
    "11025","352797.00","3.66","352778.00","0.17","352793.00","0.28","352798.00","0.43","352808.00","3.25"
    "16000","511995.00","8.65","511963.00","0.22","511990.00","0.41","352797.00","0.41","512017.00","5.12"
    "22050","705593.00","7.74","705556.00","0.27","705586.00","0.43","705595.00","0.81","705623.00","5.76"
    "24000","705593.00","7.72","705556.00","0.30","705587.00","0.41","705595.00","0.72","705632.00","5.84"
    "32000","1023988.00","0.97","1023926.00","0.40","1023980.00","0.72","705595.00","0.75","1024067.00","8.33"
    "44100","1411182.00","14.49","1411111.00","0.46","1411172.00","0.66","1411189.00","1.38","1411327.00","11.63"
    "48000","1535979.00","4.93","1535888.00","0.59","1535969.00","1.02","1411189.00","1.33","1536154.00","12.88"
    "88200","2822349.00","28.55","2822220.00","0.95","2822339.00","1.12","2822375.00","2.80","2729819.00","26.42"
    "96000","3071942.00","31.13","3071774.00","1.05","3071934.00","1.12","2822375.00","2.56","2962574.00","27.33"

Table:  **Audio Capture**

|

.. csv-table::
    :header: "Sampling Rate (Hz)","am335x-evm: Throughput (bits/sec)","am335x-evm: CPU Load (%)","am57xx-evm: Throughput (bits/sec)","am57xx-evm: CPU Load (%)","k2g-evm: Throughput (bits/sec)","k2g-evm: CPU Load (%)","omapl138-lcdk: Throughput (bits/sec)","omapl138-lcdk: CPU Load (%)"

    "8000","256100.00","2.97","256081.00","0.10","352941.00","0.37","256109.00","2.73"
    "11025","352938.00","3.73","352915.00","0.14","352941.00","0.45","352952.00","3.21"
    "16000","512199.00","5.30","512162.00","0.17","352941.00","0.37","512225.00","6.06"
    "22050","705874.00","7.52","705830.00","0.18","705882.00","0.61","705919.00","5.80"
    "24000","705875.00","7.45","705830.00","0.22","705882.00","0.64","705918.00","5.81"
    "32000","1024397.00","0.98","1024324.00","0.23","705882.00","0.75","1024481.00","8.42"
    "44100","1411745.00","14.07","1411660.00","0.41","1411764.00","1.30","1411895.00","11.57"
    "48000","1536593.00","12.59","1536486.00","0.40","1411764.00","1.20","1536769.00","12.05"
    "88200","2823476.00","27.83","2823317.00","0.83","2823524.00","2.66","2731891.00","25.40"
    "96000","3073192.00","4.38","3072969.00","0.96","2823525.00","2.66","2964839.00","27.60"

Table:  **Audio Playback**

|

Sensor Capture
-------------------------

Capture video frames (MMAP buffers) with v4l2c-ctl and record the
reported fps

.. csv-table::
    :header: "Resolution","Format","am57xx-evm: Fps","am57xx-evm: Sensor"

    "1280x800","nv12","30.03","ov10635"
    "1280x800","rgb4","30.03","ov10635"
    "160x128","nv12","40.81 (min 40.60, max 40.91)","mt9t111"
    "160x128","rgb4","40.81 (min 40.60, max 40.91)","mt9t111"
    "2048x1536","nv12","6.64 (min 6.10, max 6.70)","mt9t111"
    "2048x1536","rgb4","6.64 (min 6.10, max 6.70)","mt9t111"
    "320x240","nv12","30.03","ov10635"
    "320x240","rgb4","30.03","ov10635"

Table:  **Sensor Capture**

|

Display Driver
-------------------------


.. csv-table::
    :header: "Mode","am335x-evm: Fps","am57xx-evm: Fps","am654x-evm: Fps","k2g-evm: Fps"

    "1280x800\@60","","","59.99 (min 59.98, max 60.01)",""
    "480x272\@60","","","","59.94 (min 59.93, max 59.95)"
    "800x480\@60","","59.52 (min 59.50, max 59.54)","",""
    "800x480\@62","61.89 (min 61.89, max 61.90)","","",""


Table:  **Display performance (LCD)**

|

|

Table:  **Display performance (DVI)**

|


.. csv-table::
    :header: "Mode","am335x-evm: Fps","am57xx-evm: Fps","am654x-evm: Fps","k2g-evm: Fps"

    "1024x576\@60","59.97 (min 59.96, max 59.98)","59.97 (min 59.95, max 59.99)","","60.01 (min 60.00, max 60.01)"
    "1024x768\@60","","60.00 (min 59.99, max 60.02)","",""
    "1024x768\@70","","70.07 (min 70.04, max 70.11)","",""
    "1024x768\@75","","75.03 (min 74.97, max 75.08)","",""
    "1152x864\@75","","75.00 (min 74.97, max 75.02)","",""
    "1280x1024\@60","","60.02 (min 60.00, max 60.06)","",""
    "1280x1024\@75","","75.03 (min 75.00, max 75.05)","",""
    "1280x720\@60","60.00 (min 59.97, max 60.03)","60.00 (min 59.98, max 60.02)","","60.00"
    "1280x768\@60","","59.87 (min 59.85, max 59.90)","",""
    "1280x768\@75","","74.89 (min 74.80, max 74.99)","",""
    "1280x800\@60","","59.81 (min 59.79, max 59.83)","",""
    "1280x800\@75","","74.93 (min 74.91, max 74.99)","",""
    "1280x960\@60","","60.00 (min 59.98, max 60.02)","",""
    "1360x768\@60","","59.95 (min 59.93, max 59.98)","",""
    "1400x1050\@60","","59.98 (min 59.96, max 60.01)","",""
    "1400x1050\@75","","74.87 (min 74.75, max 74.96)","",""
    "1440x900\@60","","59.89 (min 59.86, max 59.91)","",""
    "1440x900\@75","","74.98 (min 74.96, max 75.01)","",""
    "1600x1200\@60","","60.00 (min 59.97, max 60.03)","",""
    "1600x1200\@65","","65.00 (min 64.98, max 65.02)","",""
    "1600x1200\@70","","70.00 (min 69.97, max 70.02)","",""
    "1600x900\@60","","60.00 (min 59.98, max 60.02)","",""
    "1680x1050\@60","","59.96 (min 59.93, max 59.98)","",""
    "1680x1050\@75","","74.89 (min 74.85, max 74.94)","",""
    "1680x945\@60","","60.02 (min 59.93, max 60.09)","",""
    "1920x1080\@60","","60.00 (min 59.97, max 60.03)","",""
    "2048x1152\@60","","60.00 (min 59.98, max 60.02)","",""
    "640x480\@60","60.00 (min 59.99, max 60.01)","60.00 (min 59.98, max 60.02)","",""
    "640x480\@73","72.81 (min 72.79, max 72.82)","72.81 (min 72.67, max 72.94)","",""
    "640x480\@75","75.00 (min 74.99, max 75.01)","75.00 (min 74.81, max 75.19)","",""
    "720x400\@70","70.08 (min 70.07, max 70.09)","70.08 (min 70.05, max 70.11)","",""
    "800x600\@56","56.25 (min 56.24, max 56.26)","56.25 (min 56.22, max 56.27)","",""
    "800x600\@60","60.32 (min 60.31, max 60.32)","60.32 (min 60.30, max 60.34)","",""
    "800x600\@72","72.19 (min 72.17, max 72.20)","72.19 (min 72.16, max 72.21)","","72.19 (min 72.18, max 72.19)"
    "800x600\@75","75.00 (min 74.99, max 75.01)","75.00 (min 74.97, max 75.02)","","75.00 (min 74.99, max 75.01)"
    "832x624\@75","74.55 (min 74.51, max 74.59)","74.55 (min 74.53, max 74.59)","","74.57 (min 74.56, max 74.58)"
    "848x480\@60","60.00 (min 59.99, max 60.01)","60.00 (min 59.98, max 60.02)","",""


Table:  **Display performance (HDMI)**

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

.. csv-table::
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Fps","am57xx-evm: Test Number","am57xx-evm: Fps"

    "GLB25_EgyptTestC24Z16FixedTime test","2500005.00","5.15 (min 2.43, max 13.93)","2500005.00","37.99 (min 20.66, max 59.39)"
    "GLB25_EgyptTestC24Z16_ETC1 test","2501001.00","6.27 (min 2.33, max 14.53)","2501001.00","45.12 (min 20.66, max 60.12)"
    "GLB25_EgyptTestC24Z16_ETC1to565 test","2501401.00","6.26 (min 2.33, max 14.36)","2501401.00","45.14 (min 20.65, max 60.47)"
    "GLB25_EgyptTestC24Z16_PVRTC4 test","2501101.00","6.09 (min 2.18, max 14.06)","2501101.00","44.98 (min 20.61, max 60.34)"
    "GLB25_EgyptTestC24Z24MS4 test","2500003.00","5.00 (min 0.55, max 11.79)","2500003.00","43.68 (min 19.42, max 60.38)"
    "GLB25_EgyptTestStandard_inherited test","2000000.00","23.77 (min 15.13, max 35.86)","2000000.00","59.52 (min 59.26, max 59.80)"


.. csv-table::
    :header: "Benchmark","am57xx-evm: Test Number","am57xx-evm: Fps"

    "GLB25_EgyptTestC24Z16_ETC1_Offscreen test","2501011.00","29.00"
    "GLB25_EgyptTestStandardOffscreen_inherited test","2000010.00","98.00"


Table:  **GLBenchmark 2.5 Performance**

Vertex Throughput
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Rate (triangles/sec)","am57xx-evm: Test Number","am57xx-evm: Rate (triangles/sec)","am654x-evm: Test Number","am654x-evm: Rate (triangles/sec)"

    "GLB25_TriangleTexFragmentLitTestC24Z16 test","2500511.00","2205212.00","2500511.00","24883830.00"
    "GLB25_TriangleTexTestC24Z16 test","2500301.00","11232073.00","2500301.00","105217912.00","2500301.00","16715124.00"
    "GLB25_TriangleTexVertexLitTestC24Z16 test","2500411.00","3745968.50","2500411.00","39240892.00"


Table:  **GLBenchmark 2.5 Vertex Throughput**

Pixel Throughput
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Rate (texel/sec)","am335x-evm: Fps","am57xx-evm: Test Number","am57xx-evm: Rate (texel/sec)","am57xx-evm: Fps","am654x-evm: Test Number","am654x-evm: Rate (texel/sec)","am654x-evm: Fps"

    "GLB25_FillTestC24Z16 test","2500101.00","105899912.00","4.32 (min 4.18, max 5.02)","2500101.00","1440882048.00","58.54 (min 55.56, max 59.52)","2500101.00","543738496.00","22.12 (min 21.29, max 22.62)"


Table:  **GLBenchmark 2.5 Pixel Throughput**

GFXBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Run GFXBench and capture performance reported (Score and Display rate in fps). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests



Table:  **GFXBench**

Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests



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
    "VGA","","532.00",""


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

    "8","256.96","","629.12","","620.00","","514.40","","33.84",""
    "16","289.60","","772.00","","839.20","","641.60","","43.76",""
    "32","321.60","","1024.00","","1099.20","","792.80","","55.20",""
    "64","366.00","","1185.60","","1573.60","","812.00","","62.80",""
    "128","395.44","","1136.00","","1608.00","","928.00","","64.40",""
    "256","388.32","","1124.80","","1569.60","","920.00","","63.60",""

Table: **TCP Throughput**

.. rubric::  TCP Throughput Interrupt Pacing
   :name: tcp-throughput-interrupt-pacing

.. csv-table::
    :header: "TCP Window Size (KBytes)","am335x-evm: Throughput (Mbits/sec)","am335x-evm: CPU Load ","am57xx-evm: Throughput (Mbits/sec)","am57xx-evm: CPU Load ","omapl138-lcdk: Throughput (Mbits/sec)","omapl138-lcdk: CPU Load "

    "8","246.32","","583.76","","33.60",""
    "16","267.20","","632.00","","43.36",""
    "32","319.20","","868.80","","54.64",""
    "64","385.04","","1168.00","","62.40",""
    "128","391.52","","1120.00","","68.16",""
    "256","373.76","","1110.40","","67.68",""

Table: **TCP Throughput Interrupt Pacing**


UDP Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  UDP Throughput Egress
   :name: udp-throughput-egress

.. csv-table::
    :header: "UDP Packet Size(bytes)","am335x-evm: Throughput (Mbits/sec)","am335x-evm: CPU Load ","am335x-evm: Packets Per Second (kpps) ","am57xx-evm: Throughput (Mbits/sec)","am57xx-evm: CPU Load ","am57xx-evm: Packets Per Second (kpps) ","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load ","am654x-evm: Packets Per Second (kpps) ","k2g-evm: Throughput (Mbits/sec)","k2g-evm: CPU Load ","k2g-evm: Packets Per Second (kpps) ","omapl138-lcdk: Throughput (Mbits/sec)","omapl138-lcdk: CPU Load ","omapl138-lcdk: Packets Per Second (kpps) "

    "64","20.90","99.90","39.00","48.10","82.60","93.00","23.80","100.00","44.00","1.60","98.30","1.00"
    "128","40.40","99.90","39.00","92.80","80.60","89.00","46.70","100.00","44.00","3.20","98.00","2.00"
    "256","79.80","99.80","38.00","183.50","80.50","89.00","92.50","100.00","44.00","6.40","97.90","2.00"
    "512","157.60","99.90","38.00","362.00","81.40","88.00","181.60","100.00","44.00","12.40","98.30","2.00"
    "1024","305.00","99.90","37.00","678.00","80.50","82.00","477.00","100.00","58.00","358.00","100.00","43.00","24.50","98.20","2.00"
    "1470","428.00","99.90","36.00","891.00","76.90","75.00","954.00","62.90","81.00","503.00","100.00","42.00","34.30","98.50","2.00"
    "1500","316.00","100.00","26.00","580.00","75.70","48.00","780.00","66.50","65.00","388.00","100.00","32.00","27.60","98.20","2.00"
    "4000","934.00","73.30","29.00","956.00","49.20","29.00"
    "8000","941.00","68.20","14.00","955.00","45.70","14.00","66.50","97.90","1.00"

Table: **UDP Throughput Egress**

.. rubric::  UDP Throughput Ingress
   :name: udp-throughput-ingress

.. csv-table::
    :header: "UDP Packet Size(bytes)","am335x-evm: Throughput (Mbits/sec)","am335x-evm: CPU Load ","am335x-evm: Packets Per Second (kpps) ","am57xx-evm: Throughput (Mbits/sec)","am57xx-evm: CPU Load ","am57xx-evm: Packets Per Second (kpps) ","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load ","am654x-evm: Packets Per Second (kpps) ","k2g-evm: Throughput (Mbits/sec)","k2g-evm: CPU Load ","k2g-evm: Packets Per Second (kpps) ","omapl138-lcdk: Throughput (Mbits/sec)","omapl138-lcdk: CPU Load ","omapl138-lcdk: Packets Per Second (kpps) "

    "64","21.60","98.60","41.00","57.00","88.20","111.00","51.60","46.60","99.00","27.00","100.00","52.00"
    "128","30.00","99.60","29.00","116.50","90.10","113.00","51.10","35.00","49.00","70.70","99.80","68.00","8.60","80.90","7.00"
    "256","54.90","96.80","26.00","72.20","73.90","35.00","94.80","39.80","45.00","141.40","99.80","68.00","11.60","80.50","5.00"
    "512","113.80","99.40","27.00","464.00","91.00","113.00","213.00","38.80","52.00","308.00","97.30","75.00","13.10","81.10","3.00"
    "1024","230.00","99.80","28.00","917.00","94.50","111.00","438.00","37.00","53.00","402.00","100.00","49.00","7.80","84.10","0.00"
    "1470","340.00","100.00","28.00","785.00","69.60","66.00","957.00","42.60","81.00","459.00","97.80","39.00","46.80","82.50","3.00"
    "1500","222.00","100.00","18.00","484.00","83.60","40.00","374.00","38.50","31.00","274.00","100.00","22.00","31.50","93.90","2.00"
    "4000","954.00","82.80","29.00","746.00","37.60","23.00","63.20","91.90","1.00"
    "8000","843.00","68.10","13.00","937.00","35.10","14.00","77.50","92.90","1.00"

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

    "8","638.32"
    "16","733.60"
    "32","971.20"
    "64","1193.60"
    "128","1016.80","1309.60"
    "256","1120.80","1354.40"

Table: **PCI Ethernet**

NAND Driver
-------------------------



AM335X-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write UBIFS Throughput (Mbytes/sec)","am335x-evm: Write UBIFS CPU Load (%)","am335x-evm: Read UBIFS Throughput (Mbytes/sec)","am335x-evm: Read UBIFS CPU Load (%)"

    "102400","4.33 (min 4.30, max 4.38)","100.00","7.33","100.00"
    "262144","4.36 (min 4.33, max 4.38)","100.00","7.37","100.00"
    "524288","4.39 (min 4.35, max 4.42)","99.99 (min 99.96, max 100.00)","7.39","100.00"
    "1048576","4.40 (min 4.38, max 4.42)","100.00","7.41","100.00"
    "5242880","4.43 (min 4.42, max 4.44)","100.00","7.38","100.00"










OMAPL138-LCDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","omapl138-lcdk: Write UBIFS Throughput (Mbytes/sec)","omapl138-lcdk: Write UBIFS CPU Load (%)","omapl138-lcdk: Read UBIFS Throughput (Mbytes/sec)","omapl138-lcdk: Read UBIFS CPU Load (%)"

    "102400","1.41 (min 1.40, max 1.42)","100.00","2.01","100.00"
    "262144","1.43 (min 1.42, max 1.47)","100.00","2.01","100.00"
    "524288","1.43 (min 1.42, max 1.47)","100.00","2.01","100.00"
    "1048576","1.43 (min 1.41, max 1.47)","100.00","2.02","100.00"
    "5242880","1.44 (min 1.42, max 1.46)","100.00","2.00","100.00"





QSPI Flash Driver
-------------------------








AM654x-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
UBIFS
"""""""""""""""""""""""""""
.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write UBIFS Throughput (Mbytes/sec)","am654x-evm: Write UBIFS CPU Load (%)","am654x-evm: Read UBIFS Throughput (Mbytes/sec)","am654x-evm: Read UBIFS CPU Load (%)"

    "102400","0.64 (min 0.50, max 1.15)","44.69 (min 26.95, max 50.51)","45.56","16.67"
    "262144","0.48 (min 0.36, max 0.54)","42.43 (min 31.49, max 49.52)","43.77","21.05"
    "524288","0.48 (min 0.36, max 0.54)","41.94 (min 41.17, max 43.42)","45.17","25.00"
    "1048576","0.48 (min 0.36, max 0.54)","37.40 (min 30.22, max 49.39)","40.14","27.27"




RAW
"""""""""""""""""""""""""""
.. csv-table::
    :header: "File size (Mbytes)","am654x-evm: Raw Read Throughput (Mbytes/sec)"

    "50","208.33"













K2G-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write UBIFS Throughput (Mbytes/sec)","k2g-evm: Write UBIFS CPU Load (%)","k2g-evm: Read UBIFS Throughput (Mbytes/sec)","k2g-evm: Read UBIFS CPU Load (%)"

    "102400","0.48 (min 0.32, max 0.83)","100.00","13.60","7.69"
    "262144","0.40 (min 0.28, max 0.58)","100.00","13.50","0.00"
    "524288","0.42 (min 0.26, max 0.54)","100.00","13.46","14.29"
    "1048576","0.40 (min 0.28, max 0.59)","100.00","13.38","20.00"





SPI Flash Driver
-------------------------



K2G-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write UBIFS Throughput (Mbytes/sec)","k2g-evm: Write UBIFS CPU Load (%)","k2g-evm: Read UBIFS Throughput (Mbytes/sec)","k2g-evm: Read UBIFS CPU Load (%)"

    "102400","0.09 (min 0.08, max 0.13)","62.36 (min 42.87, max 69.73)","0.21","4.41"
    "262144","0.08 (min 0.08, max 0.09)","67.99 (min 65.36, max 70.17)","0.21","1.78"
    "524288","0.08 (min 0.08, max 0.09)","67.79 (min 65.03, max 69.35)","0.21","3.14"
    "1048576","0.08 (min 0.08, max 0.09)","68.50 (min 66.09, max 70.87)","0.20","0.80"





AM654X-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write UBIFS Throughput (Mbytes/sec)","am654x-evm: Write UBIFS CPU Load (%)","am654x-evm: Read UBIFS Throughput (Mbytes/sec)","am654x-evm: Read UBIFS CPU Load (%)"

    "102400","0.33 (min 0.26, max 0.59)","25.31 (min 21.84, max 26.70)","2.66","3.80"
    "262144","0.27 (min 0.24, max 0.29)","26.45 (min 26.22, max 26.82)","2.67","2.88"
    "524288","0.27 (min 0.25, max 0.30)","25.46 (min 24.79, max 25.89)","2.67","3.49"
    "1048576","0.28 (min 0.25, max 0.30)","25.35 (min 24.15, max 26.22)","2.67","2.56"





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

    "102400","12.31 (min 11.80, max 12.63)","2.23 (min 1.58, max 4.57)","65.53","9.35"
    "262144","12.30 (min 11.18, max 12.63)","2.15 (min 1.52, max 4.18)","67.76","7.24"
    "524288","12.28 (min 11.75, max 12.60)","2.17 (min 1.43, max 4.66)","72.83","8.04"
    "1048576","12.32 (min 11.81, max 12.64)","2.18 (min 1.38, max 4.47)","74.82","8.24"
    "5242880","12.29 (min 11.81, max 12.61)","2.29 (min 1.52, max 4.57)","75.06","8.30"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)"

    "102400","12.59 (min 12.31, max 12.68)","1.89 (min 1.39, max 3.60)","69.20","5.10"
    "262144","12.56 (min 12.25, max 12.67)","1.86 (min 1.03, max 3.87)","72.14","8.22"
    "524288","12.56 (min 12.29, max 12.65)","1.95 (min 1.21, max 4.22)","77.01","6.32"
    "1048576","12.54 (min 12.25, max 12.63)","1.91 (min 1.15, max 3.64)","78.53","0.00"
    "5242880","12.56 (min 12.25, max 12.67)","1.88 (min 1.16, max 3.98)","78.55","0.00"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "102400","12.24 (min 11.94, max 12.45)","1.72 (min 1.26, max 2.86)","69.99","7.38"
    "262144","12.44 (min 11.70, max 12.68)","1.90 (min 1.52, max 2.91)","72.94","7.34"
    "524288","12.54 (min 12.43, max 12.63)","1.85 (min 1.46, max 2.92)","78.04","6.44"
    "1048576","12.57 (min 12.39, max 12.65)","1.79 (min 1.33, max 2.91)","79.66","7.95"
    "5242880","12.53 (min 12.39, max 12.62)","1.87 (min 1.51, max 2.80)","79.91","8.33"

|










AM654x-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write VFAT Throughput (Mbytes/sec)","am654x-evm: Write VFAT CPU Load (%)","am654x-evm: Read VFAT Throughput (Mbytes/sec)","am654x-evm: Read VFAT CPU Load (%)"

    "102400","20.29 (min 19.40, max 20.65)","1.95 (min 1.40, max 3.66)","128.33","7.17"
    "262144","20.29 (min 18.97, max 20.69)","1.80 (min 1.38, max 3.26)","134.43","6.84"
    "524288","20.29 (min 19.01, max 20.77)","1.86 (min 1.29, max 3.27)","152.49","7.04"
    "1048576","20.28 (min 19.07, max 20.69)","1.85 (min 1.43, max 3.37)","151.98","7.35"
    "5242880","20.29 (min 18.89, max 20.74)","1.77 (min 1.34, max 3.20)","149.59","8.60"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write EXT2 Throughput (Mbytes/sec)","am654x-evm: Write EXT2 CPU Load (%)","am654x-evm: Read EXT2 Throughput (Mbytes/sec)","am654x-evm: Read EXT2 CPU Load (%)"

    "102400","21.07 (min 20.86, max 21.21)","1.18 (min 0.91, max 1.77)","130.67","5.75"
    "262144","21.06 (min 20.61, max 21.81)","1.13 (min 0.95, max 1.62)","140.22","7.12"
    "524288","21.34 (min 20.96, max 21.86)","1.16 (min 1.00, max 1.62)","161.05","7.36"
    "1048576","20.92 (min 20.53, max 21.09)","1.07 (min 0.91, max 1.47)","168.52","7.69"
    "5242880","21.14 (min 20.85, max 21.46)","1.13 (min 0.95, max 1.59)","168.33","8.54"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write EXT4 Throughput (Mbytes/sec)","am654x-evm: Write EXT4 CPU Load (%)","am654x-evm: Read EXT4 Throughput (Mbytes/sec)","am654x-evm: Read EXT4 CPU Load (%)"

    "102400","20.76 (min 20.52, max 21.35)","1.22 (min 1.03, max 1.54)","120.01","6.32"
    "262144","20.66 (min 20.09, max 21.40)","1.17 (min 1.03, max 1.53)","134.06","7.07"
    "524288","20.89 (min 20.71, max 21.01)","1.16 (min 0.95, max 1.54)","166.96","6.85"
    "1048576","21.69 (min 21.40, max 21.79)","1.26 (min 1.09, max 1.63)","180.86","7.42"
    "5242880","20.85 (min 20.59, max 20.93)","1.17 (min 0.95, max 1.47)","180.90","9.48"

|




































K2G-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write VFAT Throughput (Mbytes/sec)","k2g-evm: Write VFAT CPU Load (%)","k2g-evm: Read VFAT Throughput (Mbytes/sec)","k2g-evm: Read VFAT CPU Load (%)"

    "102400","21.71 (min 19.28, max 22.68)","12.70 (min 10.06, max 21.11)","39.65","16.35"
    "262144","21.75 (min 19.11, max 22.49)","13.30 (min 10.99, max 21.25)","40.36","16.22"
    "524288","21.48 (min 19.17, max 22.16)","12.57 (min 9.85, max 21.32)","41.57","13.71"
    "1048576","21.76 (min 19.16, max 22.65)","12.86 (min 10.30, max 21.76)","42.62","14.98"
    "5242880","21.52 (min 19.13, max 22.15)","13.02 (min 10.19, max 21.21)","42.56","13.22"

|



.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write EXT2 Throughput (Mbytes/sec)","k2g-evm: Write EXT2 CPU Load (%)","k2g-evm: Read EXT2 Throughput (Mbytes/sec)","k2g-evm: Read EXT2 CPU Load (%)"

    "102400","22.23 (min 20.70, max 22.74)","11.05 (min 8.42, max 21.18)","40.31","14.17"
    "262144","22.27 (min 20.89, max 22.73)","11.84 (min 9.01, max 21.19)","41.21","13.01"
    "524288","22.43 (min 20.99, max 22.98)","11.77 (min 9.01, max 20.68)","42.69","14.86"
    "1048576","22.36 (min 20.87, max 22.85)","11.39 (min 8.66, max 21.07)","43.05","14.29"
    "5242880","22.32 (min 20.99, max 22.70)","11.47 (min 8.70, max 21.00)","43.01","12.86"

|



.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write EXT4 Throughput (Mbytes/sec)","k2g-evm: Write EXT4 CPU Load (%)","k2g-evm: Read EXT4 Throughput (Mbytes/sec)","k2g-evm: Read EXT4 CPU Load (%)"

    "102400","21.98 (min 21.13, max 22.51)","10.76 (min 8.75, max 16.46)","40.47","14.57"
    "262144","22.06 (min 20.83, max 22.59)","11.42 (min 9.94, max 16.60)","40.11","13.57"
    "524288","21.70 (min 20.77, max 22.11)","10.87 (min 8.90, max 16.17)","39.85","9.13"
    "1048576","21.74 (min 20.84, max 22.13)","10.90 (min 8.81, max 16.73)","41.59","12.35"
    "5242880","22.10 (min 21.51, max 22.43)","11.18 (min 9.40, max 16.74)","43.45","13.28"

|



SATA Driver
-------------------------



.. rubric::  AM57XX-EVM
   :name: am57xx-evm-sata


|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)"

    "102400","120.74 (min 106.80, max 127.84)","11.13 (min 6.05, max 30.91)","134.97","11.77"
    "262144","122.70 (min 111.39, max 126.15)","11.73 (min 5.90, max 33.02)","133.25","11.54"
    "524288","124.22 (min 120.07, max 126.26)","11.40 (min 5.89, max 31.44)","133.11","11.25"
    "1048576","123.35 (min 118.07, max 125.98)","11.29 (min 6.06, max 31.30)","133.11","10.59"
    "5242880","124.45 (min 118.82, max 127.27)","11.49 (min 6.30, max 31.19)","132.83","9.72"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "102400","123.56 (min 121.15, max 127.36)","10.97 (min 7.01, max 25.50)","130.66","11.39"
    "262144","119.87 (min 117.97, max 122.95)","10.80 (min 7.32, max 23.44)","132.73","10.36"
    "524288","121.84 (min 112.38, max 126.66)","10.66 (min 6.42, max 25.36)","132.10","10.85"
    "1048576","124.30 (min 120.66, max 127.52)","10.76 (min 6.86, max 24.81)","133.37","11.32"
    "5242880","119.94 (min 118.63, max 120.83)","10.76 (min 7.01, max 24.90)","129.19","10.41"

|




















|

|

|

-  Filesize used is : 1G
-  SATA II Harddisk used is: Seagate ST3500514NS 500G


mSATA Driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^




.. rubric::  AM57XX-EVM
   :name: am57xx-evm-msata


|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)"

    "102400","64.43 (min 63.67, max 65.01)","4.62 (min 2.68, max 11.78)","225.91","19.34"
    "262144","64.27 (min 63.24, max 64.77)","4.54 (min 2.78, max 10.79)","234.83","20.12"
    "524288","64.24 (min 63.88, max 64.58)","3.53 (min 2.69, max 6.02)","248.93","20.05"
    "1048576","64.44 (min 63.93, max 65.00)","3.42 (min 2.69, max 5.50)","257.56","20.28"
    "5242880","64.27 (min 63.93, max 64.56)","3.43 (min 2.84, max 5.39)","258.07","18.37"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "102400","64.47 (min 64.18, max 64.82)","4.05 (min 2.94, max 6.38)","230.92","20.97"
    "262144","64.25 (min 63.78, max 64.52)","4.25 (min 3.44, max 6.95)","237.18","19.01"
    "524288","64.54 (min 63.91, max 65.36)","4.38 (min 3.40, max 7.29)","254.33","20.05"
    "1048576","64.16 (min 63.43, max 64.59)","4.14 (min 3.31, max 6.78)","264.97","23.74"
    "5242880","65.36 (min 63.87, max 68.40)","4.49 (min 3.45, max 7.39)","271.22","21.48"

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

    "102400","9.33 (min 8.78, max 9.69)","9.83 (min 8.40, max 14.06)","20.39","23.83"
    "262144","9.25 (min 8.64, max 9.76)","9.57 (min 7.87, max 13.92)","20.63","21.82"
    "524288","8.48 (min 7.25, max 9.66)","8.82 (min 6.77, max 12.02)","21.13","20.61"
    "1048576","8.67 (min 6.66, max 9.78)","8.91 (min 7.50, max 10.90)","21.24","18.48"
    "5242880","8.74 (min 7.67, max 9.87)","8.95 (min 7.40, max 12.07)","21.31","18.89"

|



.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write EXT2 Throughput (Mbytes/sec)","am335x-evm: Write EXT2 CPU Load (%)","am335x-evm: Read EXT2 Throughput (Mbytes/sec)","am335x-evm: Read EXT2 CPU Load (%)"

    "102400","8.60 (min 3.82, max 10.07)","7.18 (min 5.88, max 8.06)","21.16","23.27"
    "262144","9.55 (min 7.84, max 10.16)","8.30 (min 7.32, max 10.93)","21.57","23.42"
    "524288","9.66 (min 8.24, max 10.22)","8.60 (min 7.49, max 12.12)","22.18","17.57"
    "1048576","10.11 (min 9.62, max 10.28)","9.03 (min 7.17, max 14.38)","22.44","18.26"
    "5242880","10.15 (min 9.78, max 10.29)","8.76 (min 7.05, max 13.56)","22.53","14.98"

|



.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write EXT4 Throughput (Mbytes/sec)","am335x-evm: Write EXT4 CPU Load (%)","am335x-evm: Read EXT4 Throughput (Mbytes/sec)","am335x-evm: Read EXT4 CPU Load (%)"

    "102400","9.71 (min 9.26, max 10.59)","8.69 (min 7.49, max 12.70)","17.93","19.96"
    "262144","9.80 (min 9.11, max 10.30)","8.52 (min 7.60, max 11.09)","21.70","23.08"
    "524288","9.55 (min 9.10, max 9.76)","8.54 (min 7.53, max 11.23)","22.33","17.65"
    "1048576","9.84 (min 9.62, max 9.91)","8.69 (min 7.73, max 11.78)","22.65","16.48"
    "5242880","9.71 (min 9.05, max 9.90)","8.13 (min 7.35, max 10.43)","22.80","16.63"

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

    "102400","7.37 (min 6.11, max 8.71)","1.51 (min 0.94, max 3.15)","21.26","2.74"
    "262144","6.08 (min 5.70, max 6.53)","1.19 (min 0.82, max 2.40)","21.48","1.87"
    "524288","6.02 (min 5.40, max 6.82)","1.08 (min 0.76, max 2.09)","22.12","2.74"
    "1048576","8.05 (min 7.42, max 8.74)","1.45 (min 0.89, max 2.92)","22.11","2.22"
    "5242880","8.05 (min 7.08, max 8.62)","1.52 (min 1.12, max 2.81)","22.10","2.43"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)"

    "102400","9.24 (min 7.75, max 10.05)","1.33 (min 0.84, max 2.48)","21.61","1.87"
    "262144","10.45 (min 10.24, max 10.61)","1.68 (min 1.05, max 3.23)","21.99","1.69"
    "524288","10.42 (min 9.91, max 10.58)","1.59 (min 1.22, max 2.90)","22.55","2.05"
    "1048576","10.50 (min 10.15, max 10.62)","1.66 (min 1.06, max 3.11)","22.74","1.96"
    "5242880","10.50 (min 10.26, max 10.60)","1.63 (min 1.11, max 3.19)","22.74","2.70"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "102400","9.68 (min 8.49, max 10.52)","1.48 (min 1.06, max 2.32)","21.69","1.57"
    "262144","9.88 (min 9.65, max 10.25)","1.48 (min 1.07, max 2.57)","22.04","2.01"
    "524288","9.62 (min 9.02, max 9.80)","1.36 (min 1.13, max 1.95)","22.59","2.16"
    "1048576","9.63 (min 9.14, max 10.28)","1.42 (min 1.07, max 2.34)","22.83","2.07"
    "5242880","8.37 (min 6.58, max 9.57)","1.33 (min 0.97, max 2.38)","22.83","1.86"

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

    "102400","16.56 (min 15.29, max 17.07)","1.69 (min 1.20, max 3.36)","22.15","1.43"
    "262144","16.57 (min 15.47, max 16.94)","1.57 (min 1.12, max 3.10)","22.35","1.44"
    "524288","15.94 (min 13.81, max 16.85)","1.50 (min 0.96, max 2.98)","22.73","1.14"
    "1048576","15.85 (min 13.78, max 16.97)","1.47 (min 0.92, max 2.89)","22.61","1.08"
    "5242880","15.84 (min 13.59, max 17.14)","1.51 (min 0.94, max 3.01)","22.57","1.24"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write EXT2 Throughput (Mbytes/sec)","am654x-evm: Write EXT2 CPU Load (%)","am654x-evm: Read EXT2 Throughput (Mbytes/sec)","am654x-evm: Read EXT2 CPU Load (%)"

    "102400","16.78 (min 16.60, max 16.87)","0.98 (min 0.80, max 1.46)","22.58","1.35"
    "262144","16.17 (min 13.83, max 16.94)","0.91 (min 0.69, max 1.37)","22.96","1.26"
    "524288","15.48 (min 13.78, max 16.85)","0.87 (min 0.66, max 1.28)","23.44","0.95"
    "1048576","16.61 (min 16.12, max 16.80)","0.88 (min 0.72, max 1.35)","23.57","1.24"
    "5242880","16.69 (min 16.29, max 16.87)","0.94 (min 0.80, max 1.36)","23.15","1.22"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write EXT4 Throughput (Mbytes/sec)","am654x-evm: Write EXT4 CPU Load (%)","am654x-evm: Read EXT4 Throughput (Mbytes/sec)","am654x-evm: Read EXT4 CPU Load (%)"

    "102400","16.84 (min 16.66, max 17.08)","1.03 (min 0.93, max 1.35)","22.68","1.14"
    "262144","16.34 (min 13.85, max 17.12)","0.96 (min 0.79, max 1.24)","23.06","1.27"
    "524288","17.08 (min 16.85, max 17.41)","1.00 (min 0.90, max 1.28)","23.58","1.40"
    "1048576","17.00 (min 16.80, max 17.10)","0.99 (min 0.90, max 1.20)","23.79","0.11"
    "5242880","17.01 (min 16.88, max 17.14)","0.97 (min 0.85, max 1.25)","23.77","1.08"

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

    "102400","9.29 (min 8.24, max 10.33)","5.68 (min 3.64, max 10.58)","21.04","8.37"
    "262144","9.57 (min 8.93, max 9.79)","6.08 (min 4.23, max 11.22)","21.47","9.24"
    "524288","9.66 (min 8.67, max 9.93)","6.20 (min 4.75, max 10.31)","22.08","6.87"
    "1048576","9.64 (min 8.70, max 9.93)","6.25 (min 4.89, max 10.57)","22.36","8.14"
    "5242880","9.42 (min 7.95, max 9.96)","5.90 (min 4.29, max 9.52)","22.28","7.51"

|



.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write EXT2 Throughput (Mbytes/sec)","k2g-evm: Write EXT2 CPU Load (%)","k2g-evm: Read EXT2 Throughput (Mbytes/sec)","k2g-evm: Read EXT2 CPU Load (%)"

    "102400","8.89 (min 8.10, max 9.24)","4.70 (min 3.43, max 8.26)","21.69","8.51"
    "262144","9.95 (min 9.59, max 10.16)","4.93 (min 3.42, max 9.77)","22.02","8.82"
    "524288","9.61 (min 9.12, max 9.93)","4.91 (min 3.59, max 9.38)","22.55","7.13"
    "1048576","7.79 (min 6.79, max 8.84)","3.81 (min 2.57, max 8.23)","22.50","6.91"
    "5242880","9.51 (min 9.17, max 10.06)","4.88 (min 3.61, max 8.94)","22.72","7.39"

|



.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write EXT4 Throughput (Mbytes/sec)","k2g-evm: Write EXT4 CPU Load (%)","k2g-evm: Read EXT4 Throughput (Mbytes/sec)","k2g-evm: Read EXT4 CPU Load (%)"

    "102400","9.06 (min 7.91, max 10.38)","4.55 (min 3.45, max 7.97)","21.76","7.56"
    "262144","9.62 (min 9.40, max 10.03)","4.88 (min 4.07, max 7.39)","22.09","6.85"
    "524288","9.58 (min 8.98, max 10.06)","4.92 (min 3.96, max 7.13)","22.64","6.74"
    "1048576","9.47 (min 8.95, max 9.62)","4.88 (min 4.21, max 7.18)","22.83","7.17"
    "5242880","8.26 (min 7.41, max 8.95)","4.38 (min 3.26, max 7.03)","22.80","6.77"

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

    "102400","6.89 (min 4.34, max 7.86)","87.64 (min 60.78, max 97.36)","14.79","69.44"
    "262144","7.50 (min 4.59, max 8.48)","80.22 (min 52.84, max 89.80)","14.67","64.08"
    "524288","7.46 (min 4.62, max 8.42)","80.12 (min 52.40, max 90.86)","15.00","61.58"
    "1048576","7.20 (min 4.45, max 8.32)","79.24 (min 63.67, max 89.67)","15.17","62.39"
    "5242880","7.34 (min 4.65, max 8.47)","78.78 (min 54.62, max 88.22)","13.06","57.47"

|



.. csv-table::
    :header: "Buffer size (bytes)","omapl138-lcdk: Write EXT2 Throughput (Mbytes/sec)","omapl138-lcdk: Write EXT2 CPU Load (%)","omapl138-lcdk: Read EXT2 Throughput (Mbytes/sec)","omapl138-lcdk: Read EXT2 CPU Load (%)"

    "102400","6.10 (min 3.55, max 7.34)","60.52 (min 51.91, max 66.96)","15.90","61.53"
    "262144","7.82 (min 7.47, max 8.04)","59.76 (min 54.70, max 75.64)","15.68","59.47"
    "524288","7.63 (min 6.60, max 8.19)","61.84 (min 51.12, max 73.80)","15.99","60.19"
    "1048576","7.65 (min 6.98, max 8.16)","66.09 (min 60.16, max 79.19)","16.28","58.19"
    "5242880","7.92 (min 7.54, max 8.35)","60.72 (min 52.82, max 70.53)","15.75","60.03"

|



.. csv-table::
    :header: "Buffer size (bytes)","omapl138-lcdk: Write EXT4 Throughput (Mbytes/sec)","omapl138-lcdk: Write EXT4 CPU Load (%)","omapl138-lcdk: Read EXT4 Throughput (Mbytes/sec)","omapl138-lcdk: Read EXT4 CPU Load (%)"

    "102400","6.70 (min 5.69, max 7.08)","83.88 (min 80.33, max 90.82)","15.85","60.60"
    "262144","8.30 (min 7.56, max 8.62)","80.31 (min 75.08, max 90.97)","15.83","58.45"
    "524288","8.28 (min 7.02, max 8.71)","83.11 (min 81.10, max 86.37)","16.24","57.58"
    "1048576","8.06 (min 7.16, max 8.69)","79.22 (min 71.51, max 87.91)","16.32","57.23"
    "5242880","7.83 (min 7.06, max 8.74)","80.06 (min 67.43, max 93.41)","16.20","58.43"

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
    :header: "Buffer size (bytes)","am335x-evm: Write VFAT Throughput (Mbytes/sec)","am335x-evm: Write VFAT CPU Load (%)","am335x-evm: Read VFAT Throughput (Mbytes/sec)","am335x-evm: Read VFAT CPU Load (%)","am57xx-evm: Write VFAT Throughput (Mbytes/sec)","am57xx-evm: Write VFAT CPU Load (%)","am57xx-evm: Read VFAT Throughput (Mbytes/sec)","am57xx-evm: Read VFAT CPU Load (%)","am654x-evm: Write VFAT Throughput (Mbytes/sec)","am654x-evm: Write VFAT CPU Load (%)","am654x-evm: Read VFAT Throughput (Mbytes/sec)","am654x-evm: Read VFAT CPU Load (%)"

    "102400","19.91 (min 18.72, max 20.32)","27.92 (min 24.90, max 37.32)","18.19","32.75","264.27 (min 137.71, max 297.79)","55.65 (min 50.34, max 58.21)","341.30","37.04","37.19 (min 32.84, max 38.37)","4.61 (min 3.77, max 6.93)","38.64","4.07"
    "262144","19.34 (min 17.97, max 19.85)","28.14 (min 25.64, max 35.75)","18.21","32.46","263.30 (min 136.60, max 295.77)","54.46 (min 48.67, max 56.52)","325.27","32.76","37.59 (min 33.66, max 38.60)","4.24 (min 3.52, max 5.93)","38.83","2.84"




Table: **USB Host EXT2**

.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write EXT2 Throughput (Mbytes/sec)","am335x-evm: Write EXT2 CPU Load (%)","am335x-evm: Read EXT2 Throughput (Mbytes/sec)","am335x-evm: Read EXT2 CPU Load (%)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)","am654x-evm: Write EXT2 Throughput (Mbytes/sec)","am654x-evm: Write EXT2 CPU Load (%)","am654x-evm: Read EXT2 Throughput (Mbytes/sec)","am654x-evm: Read EXT2 CPU Load (%)"

    "102400","20.25 (min 18.85, max 20.64)","25.64 (min 22.93, max 34.08)","18.18","32.46","284.87 (min 153.04, max 318.47)","51.47 (min 50.00, max 53.85)","337.42","32.08","38.85 (min 37.31, max 39.26)","3.32 (min 2.84, max 4.63)","38.33","4.41"
    "1048576","19.81 (min 18.37, max 20.30)","25.41 (min 23.33, max 32.97)","18.17","34.74","285.20 (min 151.71, max 319.04)","50.71 (min 49.18, max 53.23)","368.98","32.00","38.95 (min 37.43, max 39.42)","3.34 (min 2.84, max 4.05)","38.19","3.86"
    "5242880","19.84 (min 18.34, max 20.35)","25.40 (min 22.11, max 33.88)","18.29","32.26","284.92 (min 152.66, max 319.09)","51.58 (min 45.61, max 56.06)","363.15","37.04","39.00 (min 37.35, max 39.54)","3.30 (min 2.94, max 4.30)","38.24","5.12"




|
|

|
|

|
|

|
|

Table: **USBDEVICE NCM IPERF TCP THROUGHPUT**

.. csv-table::
    :header: "Window Size (kbytes)","am335x-evm: TX Throughput (Mbits/sec)","am335x-evm: RX Throughput (Mbits/sec)","am57xx-evm: TX Throughput (Mbits/sec)","am57xx-evm: RX Throughput (Mbits/sec)","am654x-evm: TX Throughput (Mbits/sec)","am654x-evm: RX Throughput (Mbits/sec)"

    "8","99.12","12.83","180.10","32.60","216.60","44.00"
    "16","89.60","21.01","209.30","55.40","218.00","78.70"
    "32","80.40","59.60","261.40","188.70","285.10","200.80"
    "64","83.00","72.60","278.30","257.00","356.70","345.00"
    "128","83.30","73.70","278.80","260.00","357.70","355.00"


|
|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. csv-table::
    :header: "Algorithm","Buffer Size","am335x-evm: throughput","am57xx-evm: throughput","am654x-evm: throughput"

    "aes-128-cbc","1024","10707.97","14142.81","21044.22"
    "aes-128-cbc","16","2038.86","3963.51","356.28"
    "aes-128-cbc","256","3951.62","5149.10","5730.56"
    "aes-128-cbc","64","6522.79","13341.33","1434.92"
    "aes-128-cbc","8192","19802.79","31099.56","106181.97"
    "aes-192-cbc","1024","10326.36","14168.75","20696.75"
    "aes-192-cbc","16","1993.16","3831.26","359.53"
    "aes-192-cbc","256","3996.42","5107.11","5647.53"
    "aes-192-cbc","64","6216.17","12637.14","1425.26"
    "aes-192-cbc","8192","19761.83","31074.99","100941.82"
    "aes-256-cbc","1024","10310.31","14148.95","20603.90"
    "aes-256-cbc","16","1999.13","3957.61","384.85"
    "aes-256-cbc","256","3471.27","5114.71","5640.70"
    "aes-256-cbc","64","6079.68","12663.32","1431.91"
    "aes-256-cbc","8192","18085.21","31176.02","96266.92"
    "des-cbc","1024","11829.93","9155.93","14641.49"
    "des-cbc","16","2053.66","312.67","3281.91"
    "des-cbc","256","9820.33","3907.33","12553.39"
    "des-cbc","64","5579.50","1186.24","8016.38"
    "des-cbc","8192","12836.86","15029.59","15387.31"
    "des3","1024","5160.28","9041.24","20194.99"
    "des3","16","1643.03","314.46","521.75"
    "des3","256","4683.61","3923.11","5811.88"
    "des3","64","3328.68","1190.19","1697.88"
    "des3","8192","5163.69","14731.95","69080.41"
    "md5","1024","8355.84","13727.40","30480.73"
    "md5","16","403.34","926.36","672.86"
    "md5","256","3364.27","4427.01","9729.96"
    "md5","64","1589.03","3626.33","2612.84"
    "md5","8192","36227.75","56011.43","80442.71"
    "sha1","1024","8345.60","13240.66","37263.70"
    "sha1","16","362.45","831.46","653.37"
    "sha1","256","3155.11","4829.10","10138.97"
    "sha1","64","1424.68","3245.29","2594.97"
    "sha1","8192","34947.07","55170.39","168102.57"


|
|

.. csv-table::
    :header: "Algorithm","am335x-evm: CPU Load","am57xx-evm: CPU Load","am654x-evm: CPU Load"

    "aes-128-cbc","36.00","52.00","45.00"
    "aes-192-cbc","51.00","51.00","45.00"
    "aes-256-cbc","52.00","52.00","45.00"
    "des-cbc","98.00","21.00","99.00"
    "des3","97.00","22.00","46.00"
    "md5","81.00","73.00","99.00"
    "sha1","59.00","75.00","99.00"



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
    :header: "Algorithm","am335x-evm: Throughput","am335x-evm: Packets/Sec","am335x-evm: CPU Load","am57xx-evm: Throughput","am57xx-evm: Packets/Sec","am57xx-evm: CPU Load","am654x-evm: Throughput","am654x-evm: Packets/Sec","am654x-evm: CPU Load"

    "3des","17.90","1.00","75.50"
    "aes128","4.40","0.00","54.00","104.00","8.00","53.30","186.60","15.00","32.50"
    "aes192","25.10","2.00","91.10","144.30","12.00","60.70"
    "aes256","29.60","2.00","78.50","144.30","12.00","60.10"

-

