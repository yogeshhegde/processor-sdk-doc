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

    "bw_mmap_rd-mo-1mb","268.89","3078.04","1502.63","810.90","133.14"
    "lat_sig-catch","9.69","3.52","6.46","5.40","26.48"
    "lat_ops-int-bit","0.67","0.45","0.84","0.67","2.54"
    "bw_mem-bzero-8mb","606.75 (min 219.09, max 994.41)","3525.03 (min 1963.43, max 5086.63)","2575.70 (min 984.01, max 4167.39)","2336.96 (min 1230.58, max 3443.33)","147.53 (min 100.90, max 194.15)"
    "latency_for_0.50_mb_block_size","481.67","12.83","10.48","35.92","231.62"
    "lat_ops-double-mul","11.06","3.34","5.02","5.01","99.54"
    "lat_ops-int64-bit","1.03","0.68","0.84","1.02","2.64"
    "lat_proc-exec","1302.75","740.75","1251.00","940.67","7266.00"
    "lat_fs-10k","79.00","143.00","94.00","81.00","10.00"
    "bw_mem-fwr-16mb","995.83","4955.86","4186.29","3316.75","194.46"
    "bw_mem-bzero-1mb","584.22 (min 187.41, max 981.03)","5355.94 (min 4930.45, max 5781.42)","2720.67 (min 1128.67, max 4312.67)","2899.98 (min 1323.50, max 4476.45)","146.47 (min 96.97, max 195.96)"
    "bw_mem-frd-1mb","280.76 (min 269.03, max 292.48)","2962.70 (min 2833.36, max 3092.03)","1271.65 (min 1122.33, max 1420.96)","716.06 (min 601.68, max 830.43)","105.68 (min 78.22, max 133.14)"
    "bw_mem-bcopy-1mb","187.41","4930.45","1128.67","1323.50","96.97"
    "bw_mem-rdwr-8mb","203.00 (min 202.79, max 203.21)","987.00 (min 930.56, max 1043.43)","755.23 (min 502.13, max 1008.32)","580.38 (min 559.48, max 601.28)","114.87 (min 111.73, max 118.01)"
    "lat_syscall-write","0.69","0.35","0.66","0.52","2.08"
    "select_on_200_tcp_fds","41.98","28.09","54.21","47.61","180.15"
    "bw_mem-rd-8mb","617.83 (min 251.53, max 984.13)","2184.23 (min 1305.27, max 3063.18)","1138.73 (min 1047.26, max 1230.20)","1546.86 (min 684.81, max 2408.91)","442.67 (min 144.05, max 741.29)"
    "lat_ops-int-add","1.01","0.67","1.26","1.01","1.68"
    "bw_mem-rd-1mb","633.35 (min 273.82, max 992.88)","12280.07 (min 10871.64, max 13688.49)","1384.24 (min 1283.70, max 1484.78)","1763.28 (min 845.59, max 2680.97)","437.12 (min 142.57, max 731.66)"
    "semaphore_latency","5.13","2.32","2.30","5.49","70.16"
    "lat_syscall-read","1.02","0.42","0.97","0.62","3.10"
    "bw_mem-fwr-2mb","623.10 (min 252.65, max 993.54)","3885.11 (min 2261.59, max 5508.63)","2821.17 (min 1362.17, max 4280.16)","2749.41 (min 1477.10, max 4021.72)","163.96 (min 135.24, max 192.68)"
    "bw_mem-rdwr-4mb","200.21 (min 197.18, max 203.24)","1071.86 (min 1051.11, max 1092.60)","777.33 (min 505.88, max 1048.77)","568.78 (min 562.51, max 575.04)","109.59 (min 101.21, max 117.96)"
    "bw_mem-fcp-8mb","645.93 (min 297.45, max 994.41)","3070.26 (min 1053.88, max 5086.63)","2598.63 (min 1029.87, max 4167.39)","2024.03 (min 604.73, max 3443.33)","137.23 (min 80.31, max 194.15)"
    "bw_mem-cp-2mb","595.43 (min 197.32, max 993.54)","3355.64 (min 1202.65, max 5508.63)","2396.89 (min 513.61, max 4280.16)","2310.89 (min 600.06, max 4021.72)","149.50 (min 106.32, max 192.68)"
    "bw_mem-fcp-1mb","636.76 (min 292.48, max 981.03)","4307.39 (min 2833.36, max 5781.42)","2717.50 (min 1122.33, max 4312.67)","2539.07 (min 601.68, max 4476.45)","137.09 (min 78.22, max 195.96)"
    "lat_syscall-null","0.56","0.32","0.46","0.46","1.96"
    "bw_mem-wr-8mb","593.46 (min 202.79, max 984.13)","1117.92 (min 930.56, max 1305.27)","1027.79 (min 1008.32, max 1047.26)","622.15 (min 559.48, max 684.81)","429.65 (min 118.01, max 741.29)"
    "bw_mem-bzero-16mb","996.39","4952.03","4186.84","3357.11","194.67"
    "lat_ctx-2-256k","632.12","9.80","27.76","121.95","156.08"
    "bw_mem-rd-4mb","626.84 (min 251.68, max 1002.00)","2479.40 (min 1608.15, max 3350.64)","1169.75 (min 1076.86, max 1262.63)","1552.09 (min 687.99, max 2416.19)","438.28 (min 143.83, max 732.73)"
    "signal_handler_latency","1.42","0.63","0.76","0.96","4.89"
    "pipe_bandwidth","260.60","575.38","875.32","370.31","29.61"
    "latency_for_1.00_mb_block_size","275.56 (min 0.00, max 551.12)","6.41 (min 0.00, max 12.83)","20.77 (min 0.00, max 41.55)","62.97 (min 0.00, max 125.94)","115.90 (min 0.00, max 231.81)"
    "lat_ops-int64-div","208.70","118.62","11.93","185.42","854.85"
    "bw_file_rd-io-1mb","190.01","1155.85","985.55","577.20","44.83"
    "procedure_call","0.02","0.01","0.01","0.01","0.07"
    "bw_mem-frd-4mb","272.26 (min 249.33, max 295.18)","1068.31 (min 1065.81, max 1070.81)","1152.06 (min 1026.56, max 1277.55)","655.11 (min 588.32, max 721.89)","104.05 (min 73.49, max 134.61)"
    "lat_pipe","34.55","26.59","23.99","42.57","457.57"
    "lat_syscall-stat","7.36","5.28","6.66","7.91","70.48"
    "bw_mem-bzero-2mb","594.45 (min 206.42, max 982.48)","4327.46 (min 3051.69, max 5603.22)","2626.50 (min 1006.71, max 4246.28)","2610.56 (min 1228.31, max 3992.81)","144.91 (min 97.06, max 192.75)"
    "bw_mem-bcopy-4mb","208.40","2029.43","986.07","1218.77","95.34"
    "bw_mem-fwr-8mb","625.61 (min 249.08, max 1002.13)","3039.65 (min 921.34, max 5157.96)","2716.52 (min 1255.49, max 4177.55)","2057.40 (min 722.09, max 3392.71)","164.24 (min 134.68, max 193.79)"
    "lat_fs-0k","228.00","341.00","284.00","223.00","23.00"
    "bw_mem-cp-1mb","594.42 (min 196.77, max 992.06)","4810.52 (min 3954.80, max 5666.24)","2503.39 (min 577.92, max 4428.86)","2782.23 (min 603.96, max 4960.50)","148.22 (min 106.35, max 190.08)"
    "lat_mem_rd-stride128-sz62k","9.14","11.44","8.03","20.06","214.61"
    "bw_mem-fcp-4mb","639.17 (min 295.18, max 983.16)","3184.92 (min 1065.81, max 5304.03)","2598.79 (min 1026.56, max 4171.01)","2126.00 (min 588.32, max 3663.67)","133.69 (min 73.49, max 193.88)"
    "lat_syscall-open","232.00","153.61","200.42","202.21","1481.50"
    "tcp_ip_connection_cost_to_localhost","72.08","52.54","59.38","82.97","974.83"
    "lat_tcp","1.05","0.54","0.76","0.81","9.25"
    "lat_ctx-4-128k","463.22","12.35","19.53","81.59","179.25"
    "lat_sem","5.13","2.32","2.30","5.49","70.16"
    "lat_ops-int-mul","6.06","2.09","3.80","3.14","6.69"
    "bw_pipe","260.60","575.38","875.32","370.31","29.61"
    "bw_mmap_rd-o2c-1mb","179.28","1244.22","766.87","442.80","86.81"
    "lat_connect","72.08","52.54","59.38","82.97","974.83"
    "lat_mem_rd-stride128-sz50","3.01","2.67","3.76","4.01","5.04"
    "bw_mem-rdwr-1mb","201.79 (min 196.77, max 206.80)","5436.28 (min 3954.80, max 6917.76)","897.55 (min 577.92, max 1217.18)","638.51 (min 603.96, max 673.06)","111.60 (min 106.35, max 116.85)"
    "bw_mem-cp-16mb","157.65","1046.57","501.63","597.93","190.08"
    "lat_select","41.98","28.09","54.21","47.61","180.15"
    "bw_mem-rdwr-16mb","202.79","914.29","1003.20","558.52","117.88"
    "af_unix_sock_stream_latency","42.73","24.45","43.85","51.13","640.11"
    "lat_ctx-4-256k","682.62","12.40","130.93","82.21","218.67"
    "lat_syscall-fstat","3.02","2.19","2.91","3.77","18.15"
    "bw_mem-fcp-16mb","274.72","1064.40","1030.73","604.00","195.96"
    "bw_unix","184.42","2212.44","1152.93","644.43","32.13"
    "lat_ops-float-add","2.28","0.73","0.91","1.09","21.52"
    "bw_mem-cp-4mb","590.54 (min 197.18, max 983.89)","3168.87 (min 1051.11, max 5286.63)","2346.45 (min 505.88, max 4187.02)","2086.08 (min 575.04, max 3597.12)","147.18 (min 101.21, max 193.15)"
    "bw_mem-fwr-4mb","616.61 (min 249.33, max 983.89)","3178.72 (min 1070.81, max 5286.63)","2732.29 (min 1277.55, max 4187.02)","2159.51 (min 721.89, max 3597.12)","163.88 (min 134.61, max 193.15)"
    "bw_mem-frd-8mb","273.27 (min 249.08, max 297.45)","987.61 (min 921.34, max 1053.88)","1142.68 (min 1029.87, max 1255.49)","663.41 (min 604.73, max 722.09)","107.50 (min 80.31, max 134.68)"
    "pipe_latency","34.55","26.59","23.99","42.57","457.57"
    "lat_sig-install","1.42","0.63","0.76","0.96","4.89"
    "lat_unix","42.73","24.45","43.85","51.13","640.11"
    "lat_proc-proccall","0.02","0.01","0.01","0.01","0.07"
    "bw_mem-bcopy-8mb","219.09","1963.43","984.01","1230.58","100.90"
    "lat_mem_rd-stride128-sz31k","3.01","6.46","3.79","14.07","172.55"
    "tcp_latency_using_localhost","1.05","0.54","0.76","0.81","9.25"
    "lat_mem_rd-stride128-sz1000k","551.12","12.83","41.55","125.94","231.81"
    "bw_mem-rd-16mb","251.77","3040.09","1225.77","2417.28","143.85"
    "bw_mem-rdwr-2mb","200.20 (min 197.32, max 203.07)","2515.04 (min 1202.65, max 3827.42)","841.26 (min 513.61, max 1168.91)","581.17 (min 562.27, max 600.06)","111.96 (min 106.32, max 117.59)"
    "lat_pagefault","1.75","0.96","2.99","1.68","7.38"
    "bw_mem-wr-2mb","593.50 (min 203.07, max 983.93)","6834.63 (min 3827.42, max 9841.83)","1195.52 (min 1168.91, max 1222.12)","625.61 (min 562.27, max 688.94)","424.23 (min 117.59, max 730.86)"
    "bw_file_rd-o2c-1mb","158.60","897.99","673.51","459.00","40.47"
    "af_unix_socket_stream_bandwidth","184.42","2212.44","1152.93","644.43","32.13"
    "lat_ops-float-mul","10.04","3.34","5.02","5.02","66.08"
    "lat_fs-1k","122.00","203.00","94.00","128.00","12.00"
    "bw_mem-frd-16mb","249.41","1994.02","1258.16","1470.05","134.73"
    "signal_handler_overhead","9.69","3.52","6.46","5.40","26.48"
    "bw_mem-fwr-1mb","630.55 (min 269.03, max 992.06)","4379.14 (min 3092.03, max 5666.24)","2924.91 (min 1420.96, max 4428.86)","2895.47 (min 830.43, max 4960.50)","161.61 (min 133.14, max 190.08)"
    "lat_fs-4k","126.00","212.00","92.00","130.00","13.00"
    "bw_mem-wr-4mb","602.62 (min 203.24, max 1002.00)","1350.38 (min 1092.60, max 1608.15)","1062.82 (min 1048.77, max 1076.86)","625.25 (min 562.51, max 687.99)","425.35 (min 117.96, max 732.73)"
    "lat_ctx-2-128k","172.89","15.18","9.33","16.55","166.00"
    "bw_mem-bcopy-16mb","155.38","1941.51","979.19","1226.62","40.47"
    "lat_mem_rd-stride128-sz125k","11.72","12.68","9.46","20.06","216.69"
    "bw_mem-rd-2mb","618.92 (min 253.90, max 983.93)","9126.61 (min 8411.39, max 9841.83)","1288.91 (min 1222.12, max 1355.70)","1551.79 (min 688.94, max 2414.63)","436.93 (min 142.99, max 730.86)"
    "lat_mem_rd-stride128-sz500k","481.67","12.83","10.48","35.92","231.62"
    "lat_ops-double-add","2.38","0.73","0.91","1.10","35.08"
    "bw_mem-fcp-2mb","636.65 (min 290.82, max 982.48)","3396.67 (min 1190.12, max 5603.22)","2642.98 (min 1039.68, max 4246.28)","2293.41 (min 594.00, max 3992.81)","134.92 (min 77.09, max 192.75)"
    "bw_mem-wr-16mb","995.95","1275.31","1044.11","684.46","742.94"
    "lat_ops-int64-add","1.21","0.74","1.25","1.11","5.28"
    "bw_mem-bzero-4mb","595.78 (min 208.40, max 983.16)","3666.73 (min 2029.43, max 5304.03)","2578.54 (min 986.07, max 4171.01)","2441.22 (min 1218.77, max 3663.67)","144.61 (min 95.34, max 193.88)"
    "bw_mem-frd-2mb","271.74 (min 252.65, max 290.82)","1725.86 (min 1190.12, max 2261.59)","1200.93 (min 1039.68, max 1362.17)","1035.55 (min 594.00, max 1477.10)","106.17 (min 77.09, max 135.24)"
    "lat_proc-fork","1109.60","652.33","1128.40","835.43","6664.00"
    "lat_sig-prot","0.51","0.37","0.53","0.40","1.20"
    "lat_ops-int-mod","23.50","8.94","7.95","13.39","87.31"
    "bw_mem-cp-8mb","602.67 (min 203.21, max 1002.13)","3100.70 (min 1043.43, max 5157.96)","2339.84 (min 502.13, max 4177.55)","1997.00 (min 601.28, max 3392.71)","152.76 (min 111.73, max 193.79)"
    "lat_ops-int64-mod","55.90","22.04","9.19","33.10","253.74"
    "lat_mem_rd-stride128-sz250k","49.74","12.83","10.11","20.16","217.91"
    "bw_mem-wr-1mb","599.84 (min 206.80, max 992.88)","10303.13 (min 6917.76, max 13688.49)","1250.44 (min 1217.18, max 1283.70)","759.33 (min 673.06, max 845.59)","424.26 (min 116.85, max 731.66)"
    "lat_ops-int-div","73.12","60.13","7.53","90.29","190.73"
    "lat_mmap-1m","55.00","46.00","21.00","88.00","559.00"
    "bw_mem-bcopy-2mb","206.42","3051.69","1006.71","1228.31","97.06"


Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.
  
.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am57xx-evm: perf","am654x-evm: perf","k2g-evm: perf","omapl138-lcdk: perf"

    "cpu_clock","1000.00","1500.00","800.00","","230.00"
    "dhrystone_per_second","3846153.80","9523810.00","4166666.80","6451613.00","743494.40"
    "dhrystone_per_mhz","2.20","3.60","2.95","3.60","1.80"


Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am57xx-evm: perf","am654x-evm: perf","k2g-evm: perf","omapl138-lcdk: perf"

    "whetstone","555.60","3333.30","2500.00","2500.00","31.90"


Table:  **Whetstone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
sloving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am57xx-evm: perf","am654x-evm: perf","k2g-evm: perf","omapl138-lcdk: perf"

    "linpack","55980.00","1049949.00","333220.00","692554.00","7470.00"


Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am57xx-evm: perf","am654x-evm: perf","k2g-evm: perf","omapl138-lcdk: perf"

    "assignment","8.18","17.06","8.43","11.58","0.99"
    "idea","1533.00","4381.60","1958.20","3006.40","453.45"
    "string_sort","66.79","141.00","94.82","93.98","8.22"
    "numeric_sort","388.96","662.68","450.74","473.54","103.34"
    "fp_emulation","80.30","169.34","62.51","113.06","19.32"
    "fourier","1830.10","12630.00","6826.90","8436.60","128.28"
    "huffman","806.85","1401.50","638.27","935.07","220.22"
    "lu_decomposition","75.30","832.60","321.04","556.14","5.86"
    "neural_net","2.00","22.88","4.32","15.22","0.19"


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

    "triad","459.20","3714.70","1637.60","2261.40"
    "add","489.40","3702.10","1771.80","2327.40"
    "scale","534.80","4254.60","2266.10","2366.90"
    "copy","435.50","3843.10","2144.80","2448.20"


Table:  **Stream**

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am335x-evm: boot time (sec)","am57xx-evm: boot time (sec)","am654x-evm: boot time (sec)","k2g-evm: boot time (sec)","omapl138-lcdk: boot time (sec)"

    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","5.60 (min 5.57, max 5.62)","5.96 (min 5.89, max 5.99)","7.57 (min 7.53, max 7.59)","11.21 (min 11.07, max 11.63)"
    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","30.01 (min 29.09, max 31.90)","16.51 (min 16.35, max 16.78)","17.44 (min 16.83, max 18.04)","26.60 (min 26.16, max 27.34)","95.34 (min 94.66, max 95.91)"

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

    "11025","352799.00","2.78","352778.00","0.13","352793.00","0.13","352797.00","0.40","352809.00","2.89"
    "24000","705598.00","4.70","705555.00","0.24","705586.00","0.23","705595.00","0.74","705635.00","5.51"
    "8000","256000.00","0.94","255981.00","0.09","255995.00","0.12","352797.00","0.39","256005.00","1.92"
    "16000","511999.00","11.01","511963.00","0.17","511990.00","0.09","352797.00","0.40","512018.00","4.72"
    "44100","1411191.00","8.14","1411110.00","0.47","1411171.00","0.40","1411188.00","1.54","1411333.00","10.41"
    "22050","705597.00","4.86","705555.00","0.22","705586.00","0.22","705595.00","0.76","705635.00","5.40"
    "88200","2822367.00","17.77","2822217.00","0.78","2822338.00","0.87","2822374.00","2.64","2729761.00","23.23"
    "48000","1535990.00","35.06","1535887.00","0.51","1535969.00","0.21","1411188.00","1.50","1536158.00","11.37"
    "96000","3071963.00","48.15","3071772.00","0.89","3071931.00","1.28","2822374.00","2.84","2962214.00","25.13"
    "32000","1023995.00","0.90","1023925.00","0.31","1023980.00","0.53","705595.00","0.71","1024072.00","7.24"

Table:  **Audio Capture**

|

.. csv-table::
    :header: "Sampling Rate (Hz)","am335x-evm: Throughput (bits/sec)","am335x-evm: CPU Load (%)","am57xx-evm: Throughput (bits/sec)","am57xx-evm: CPU Load (%)","am654x-evm: Throughput (bits/sec)","am654x-evm: CPU Load (%)","k2g-evm: Throughput (bits/sec)","k2g-evm: CPU Load (%)","omapl138-lcdk: Throughput (bits/sec)","omapl138-lcdk: CPU Load (%)"

    "11025","352940.00","2.70","352915.00","0.14","319684.00","0.13","352942.00","0.40","352951.00","2.89"
    "24000","705878.00","4.68","705830.00","0.25","641445.00","0.20","705883.00","0.72","705917.00","5.21"
    "8000","256101.00","2.37","256081.00","0.09","250088.00","0.12","352942.00","0.38","256108.00","2.11"
    "16000","512202.00","3.03","512162.00","0.18","472141.00","0.24","352942.00","0.39","512224.00","4.35"
    "44100","1411753.00","8.37","1411658.00","0.47","1143048.00","0.35","1411765.00","1.33","1411900.00","10.87"
    "22050","705878.00","4.58","705829.00","0.26","661576.00","0.22","705883.00","0.75","705918.00","5.22"
    "88200","2823490.00","15.98","2823315.00","0.83","2349407.00","0.64","2823528.00","2.67","2731835.00","22.92"
    "48000","1536601.00","11.72","1536484.00","0.47","1125199.00","0.18","1411765.00","1.35","1536773.00","11.80"
    "96000","3073187.00","8.53","3072966.00","0.78","1812433.00","0.76","2823528.00","2.70","2964646.00","24.76"
    "32000","1024402.00","0.95","1024323.00","0.39","923271.00","0.42","705883.00","0.70","1024482.00","7.39"

Table:  **Audio Playback**

|

Sensor Capture
-------------------------

Capture video frames (MMAP buffers) with v4l2c-ctl and record the
reported fps

.. csv-table::
    :header: "Resolution","Format","am57xx-evm: Fps","am57xx-evm: Sensor"

    "160x128","rgb4","40.88 (min 40.79, max 41.00)","mt9t111"
    "2048x1536","rgb4","6.63 (min 6.14, max 6.68)","mt9t111"
    "2048x1536","nv12","6.63 (min 6.14, max 6.68)","mt9t111"
    "160x128","nv12","40.87 (min 40.79, max 41.00)","mt9t111"

Table:  **Sensor Capture**

|

Display Driver
-------------------------


.. csv-table::
    :header: "Mode","am335x-evm: Fps","am57xx-evm: Fps","am654x-evm: Fps","k2g-evm: Fps"

    "480x272\@60","","","","59.94 (min 59.93, max 59.98)"
    "800x480\@60","","59.52 (min 59.51, max 59.54)","",""
    "800x480\@62","61.86 (min 60.88, max 62.55)","","",""
    "1280x800\@60","","","59.99 (min 59.99, max 60.00)",""


Table:  **Display performance (LCD)**

|

|

Table:  **Display performance (DVI)**

|


.. csv-table::
    :header: "Mode","am335x-evm: Fps","am57xx-evm: Fps","am654x-evm: Fps","k2g-evm: Fps"

    "640x480\@60","59.97 (min 59.02, max 60.01)","60.00 (min 59.99, max 60.02)","",""
    "1680x1050\@75","","74.89 (min 74.86, max 74.92)","",""
    "1400x1050\@60","","59.98 (min 59.95, max 60.00)","",""
    "1600x1200\@65","","65.00 (min 64.98, max 65.02)","",""
    "1152x864\@75","","75.00 (min 74.97, max 75.03)","",""
    "1280x768\@60","","59.87 (min 59.85, max 59.89)","",""
    "800x600\@56","56.25 (min 56.25, max 56.26)","56.25 (min 56.23, max 56.27)","",""
    "1280x1024\@75","","75.02 (min 75.00, max 75.06)","",""
    "1280x720\@60","59.95 (min 59.01, max 60.01)","60.00 (min 59.98, max 60.02)","","60.00 (min 60.00, max 60.01)"
    "1680x945\@60","","60.02 (min 59.91, max 60.14)","",""
    "800x600\@72","72.14 (min 70.79, max 72.41)","72.19 (min 72.16, max 72.22)","","72.19 (min 72.18, max 72.20)"
    "800x600\@75","74.93 (min 72.57, max 75.01)","75.00 (min 74.97, max 75.03)","","75.00 (min 74.99, max 75.01)"
    "2048x1152\@60","","60.00 (min 59.97, max 60.02)","",""
    "1280x960\@60","","60.00 (min 59.98, max 60.03)","",""
    "848x480\@60","59.91 (min 59.02, max 60.01)","60.00 (min 59.85, max 60.15)","",""
    "1024x768\@75","","75.03 (min 75.00, max 75.06)","",""
    "1280x800\@75","","74.93 (min 74.90, max 74.96)","",""
    "1024x768\@70","","70.07 (min 70.04, max 70.10)","",""
    "1920x1080\@60","","60.00 (min 59.97, max 60.03)","",""
    "1440x900\@75","","74.98 (min 74.95, max 75.02)","",""
    "1024x576\@60","59.95 (min 58.98, max 60.44)","59.97 (min 59.95, max 59.99)","","60.01 (min 60.00, max 60.01)"
    "1600x1200\@60","","60.00 (min 59.97, max 60.03)","",""
    "640x480\@73","72.74 (min 71.61, max 73.28)","72.81 (min 72.78, max 72.84)","",""
    "1680x1050\@60","","59.95 (min 59.89, max 60.02)","",""
    "640x480\@75","74.92 (min 72.57, max 75.02)","75.00 (min 74.97, max 75.04)","",""
    "1600x900\@60","","60.00 (min 59.98, max 60.02)","",""
    "1400x1050\@75","","74.87 (min 74.84, max 74.91)","",""
    "1360x768\@60","","59.95 (min 59.93, max 59.96)","",""
    "1280x768\@75","","74.89 (min 74.86, max 74.92)","",""
    "1600x1200\@70","","70.00 (min 69.97, max 70.03)","",""
    "1280x1024\@60","","60.02 (min 60.00, max 60.04)","",""
    "720x400\@70","70.03 (min 68.92, max 70.09)","70.08 (min 70.05, max 70.11)","",""
    "800x600\@60","60.28 (min 59.22, max 60.43)","60.32 (min 60.28, max 60.34)","",""
    "1024x768\@60","","60.00 (min 59.99, max 60.02)","",""
    "1280x800\@60","","59.81 (min 59.79, max 59.83)","",""
    "832x624\@75","74.47 (min 73.32, max 74.57)","74.55 (min 74.52, max 74.59)","","74.57 (min 74.54, max 74.60)"
    "1440x900\@60","","59.89 (min 59.87, max 59.91)","",""


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
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Fps","am57xx-evm: Test Number","am57xx-evm: Fps"

    "GLB25_EgyptTestC24Z24MS4 test","2500003.00","5.17 (min 2.00, max 11.61)","2500003.00","44.05 (min 20.24, max 60.24)"
    "GLB25_EgyptTestC24Z16_PVRTC4 test","2501101.00","6.02 (min 2.36, max 13.77)","2501101.00","45.41 (min 20.83, max 60.72)"
    "GLB25_EgyptTestC24Z16_ETC1to565 test","2501401.00","6.20 (min 2.41, max 14.09)","2501401.00","45.45 (min 20.93, max 60.23)"
    "GLB25_EgyptTestC24Z16_ETC1 test","2501001.00","6.19 (min 2.17, max 13.97)","2501001.00","45.50 (min 20.88, max 60.12)"
    "GLB25_EgyptTestC24Z16FixedTime test","2500005.00","5.09 (min 2.39, max 13.99)","2500005.00","38.78 (min 21.73, max 59.62)"
    "GLB25_EgyptTestStandard_inherited test","2000000.00","23.84 (min 15.28, max 34.74)","2000000.00","59.53 (min 59.25, max 59.73)"


Table:  **GLBenchmark 2.5 Performance**

Vertex Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Rate (triangles/sec)","am57xx-evm: Test Number","am57xx-evm: Rate (triangles/sec)"

    "GLB25_TriangleTexTestC24Z16 test","2500301.00","11216341.00","2500301.00","105554640.00"
    "GLB25_TriangleTexVertexLitTestC24Z16 test","2500411.00","3748245.00","2500411.00","40060944.00"
    "GLB25_TriangleTexFragmentLitTestC24Z16 test","2500511.00","2205167.00","2500511.00","32872350.00"


Table:  **GLBenchmark 2.5 Vertex Throughput**

Pixel Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Rate (texel/sec)","am335x-evm: Fps","am57xx-evm: Test Number","am57xx-evm: Rate (texel/sec)","am57xx-evm: Fps"

    "GLB25_FillTestC24Z16 test","2500101.00","106066112.00","4.33 (min 4.18, max 5.02)","2500101.00","1435972864.00","58.33 (min 51.59, max 59.52)"


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

    "720p","59940.00","532.00",""
    "1080i","30300.00","532.00",""
    "720x480","24.17","532.00",""
    "800x480","30.00","532.00",""
    "1080p","59.50","532.00",""
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

    "720p","29.97","532.00",""
    "1080p","","532.00",""


Table:  **GStreamer MPEG2 in MP4 Container Decode Performance**

|

|
Ethernet Driver
-------------------------

TCP Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "TCP Window Size (KBytes)","am335x-evm: Throughput (Mbits/sec)","am335x-evm: CPU Load ","am57xx-evm: Throughput (Mbits/sec)","am57xx-evm: CPU Load ","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load ","k2g-evm: Throughput (Mbits/sec)","k2g-evm: CPU Load ","omapl138-lcdk: Throughput (Mbits/sec)","omapl138-lcdk: CPU Load "

    "16","288.80","","555.20","","672.80","","702.40","","44.56",""
    "32","348.64","","792.80","","872.80","","769.60","","29.44",""
    "64","386.16","","1072.00","","696.00","","859.20","","65.44",""
    "128","382.88","","1200.80","","735.76","","822.40","","32.32",""
    "8","237.52","","601.60","","598.40","","452.80","","34.08",""
    "256","367.76","","1161.60","","709.60","","843.20","","31.04",""

Table: **TCP Throughput**

.. rubric::  TCP Throughput Interrupt Pacing
   :name: tcp-throughput-interrupt-pacing

.. csv-table::
    :header: "TCP Window Size (KBytes)","am335x-evm: Throughput (Mbits/sec)","am335x-evm: CPU Load ","am57xx-evm: Throughput (Mbits/sec)","am57xx-evm: CPU Load ","omapl138-lcdk: Throughput (Mbits/sec)","omapl138-lcdk: CPU Load "

    "16","294.40","","592.80","","44.48",""
    "32","341.04","","752.00","","28.00",""
    "64","382.16","","958.40","","65.04",""
    "128","378.24","","1062.40","","63.12",""
    "8","220.00","","348.80","","33.84",""
    "256","368.80","","1042.40","","61.92",""

Table: **TCP Throughput Interrupt Pacing**


UDP Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  UDP Throughput Egress
   :name: udp-throughput-egress

.. csv-table::
    :header: "UDP Packet Size(bytes)","am335x-evm: Throughput (Mbits/sec)","am335x-evm: CPU Load ","am335x-evm: Packets Per Second (kpps) ","am57xx-evm: Throughput (Mbits/sec)","am57xx-evm: CPU Load ","am57xx-evm: Packets Per Second (kpps) ","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load ","am654x-evm: Packets Per Second (kpps) ","k2g-evm: Throughput (Mbits/sec)","k2g-evm: CPU Load ","k2g-evm: Packets Per Second (kpps) ","omapl138-lcdk: Throughput (Mbits/sec)","omapl138-lcdk: CPU Load ","omapl138-lcdk: Packets Per Second (kpps) "

    "1024","335.00","99.90","40.00","716.00","80.30","87.00","364.00","99.90","44.00","25.60","96.30","3.00"
    "1500","315.00","99.90","26.00","658.00","81.00","54.00","920.00","66.30","76.00","405.00","99.90","33.00","26.60","95.90","2.00"
    "1470","474.00","99.90","40.00","927.00","77.50","78.00","956.00","57.90","81.00","512.00","99.90","43.00","32.40","95.60","2.00"
    "64","22.90","99.90","42.00","49.00","80.60","95.00"
    "128","45.30","99.90","43.00","94.10","79.00","91.00","47.60","99.90","45.00"
    "512","176.50","99.90","42.00","370.00","80.20","90.00","183.20","99.90","44.00","13.70","96.50","3.00"
    "256","88.30","99.80","42.00","194.20","79.70","94.00","7.40","96.00","3.00"

Table: **UDP Throughput Egress**

.. rubric::  UDP Throughput Ingress
   :name: udp-throughput-ingress

.. csv-table::
    :header: "UDP Packet Size(bytes)","am335x-evm: Throughput (Mbits/sec)","am335x-evm: CPU Load ","am335x-evm: Packets Per Second (kpps) ","am57xx-evm: Throughput (Mbits/sec)","am57xx-evm: CPU Load ","am57xx-evm: Packets Per Second (kpps) ","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load ","am654x-evm: Packets Per Second (kpps) ","k2g-evm: Throughput (Mbits/sec)","k2g-evm: CPU Load ","k2g-evm: Packets Per Second (kpps) ","omapl138-lcdk: Throughput (Mbits/sec)","omapl138-lcdk: CPU Load ","omapl138-lcdk: Packets Per Second (kpps) "

    "1024","203.90","97.10","24.00","468.00","77.10","57.00","30.20","82.10","3.00"
    "1500","204.00","100.00","17.00","519.00","88.90","43.00","250.00","29.90","20.00","32.60","87.30","2.00"
    "1470","216.30","83.40","18.00","810.00","69.90","68.00","833.00","49.70","70.00","34.50","87.10","2.00"
    "64","11.40","93.50","21.00","28.30","74.90","54.00","33.80","43.20","64.00","33.50","99.80","64.00"
    "128","27.20","95.20","26.00","12.10","64.90","11.00","67.70","44.80","65.00","75.10","99.60","73.00"
    "512","105.80","97.90","25.00","369.00","68.30","90.00","276.00","45.50","67.00","1.40","52.50","0.00"
    "256","60.30","97.00","29.00","120.00","93.60","58.00","141.70","47.00","68.00","93.60","82.50","45.00"

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

    "16","744.80"
    "32","965.60"
    "64","1192.00"
    "128","0.00","1304.80"
    "8","689.60"
    "256","1354.40"

Table: **PCI Ethernet**

NAND Driver
-------------------------



AM335X-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write UBIFS Throughput (Mbytes/sec)","am335x-evm: Write UBIFS CPU Load (%)","am335x-evm: Read UBIFS Throughput (Mbytes/sec)","am335x-evm: Read UBIFS CPU Load (%)"

    "262144","4.36 (min 4.32, max 4.39)","100.00","7.36","100.00"
    "102400","4.32 (min 4.30, max 4.38)","100.00","7.35","99.93"
    "1048576","4.41 (min 4.37, max 4.44)","100.00","7.39","100.00"
    "524288","4.40 (min 4.36, max 4.42)","100.00","7.42","100.00"
    "5242880","4.43 (min 4.41, max 4.45)","100.00","7.43","100.00"










OMAPL138-LCDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","omapl138-lcdk: Write UBIFS Throughput (Mbytes/sec)","omapl138-lcdk: Write UBIFS CPU Load (%)","omapl138-lcdk: Read UBIFS Throughput (Mbytes/sec)","omapl138-lcdk: Read UBIFS CPU Load (%)"

    "262144","1.43 (min 1.42, max 1.47)","100.00","1.96","100.00"
    "102400","1.38 (min 1.17, max 1.43)","99.99 (min 99.97, max 100.00)","1.97","100.00"
    "1048576","1.44 (min 1.42, max 1.47)","100.00 (min 99.99, max 100.00)","1.96","100.00"
    "524288","1.44 (min 1.43, max 1.48)","100.00","1.96","100.00"
    "5242880","1.44 (min 1.43, max 1.48)","100.00","1.96","100.00"





QSPI Flash Driver
-------------------------








AM654x-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
UBIFS
"""""""""""""""""""""""""""
.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write UBIFS Throughput (Mbytes/sec)","am654x-evm: Write UBIFS CPU Load (%)","am654x-evm: Read UBIFS Throughput (Mbytes/sec)","am654x-evm: Read UBIFS CPU Load (%)"

    "262144","0.44 (min 0.35, max 0.48)","46.66 (min 41.05, max 50.14)","54.54","13.33"
    "102400","0.76 (min 0.46, max 1.28)","41.77 (min 25.08, max 56.03)","59.56","14.29"
    "1048576","0.48 (min 0.34, max 0.68)","43.69 (min 42.19, max 45.49)","53.83","13.33"
    "524288","0.44 (min 0.35, max 0.46)","47.27 (min 37.99, max 54.12)","60.68","14.29"




RAW
"""""""""""""""""""""""""""
.. csv-table::
    :header: "File size (Mbytes)","am654x-evm: Raw Read Throughput (Mbytes/sec)"

    "50","128.21"













K2G-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write UBIFS Throughput (Mbytes/sec)","k2g-evm: Write UBIFS CPU Load (%)","k2g-evm: Read UBIFS Throughput (Mbytes/sec)","k2g-evm: Read UBIFS CPU Load (%)"

    "262144","0.36 (min 0.31, max 0.47)","100.00","13.50","25.00"
    "102400","0.47 (min 0.31, max 0.82)","100.00","13.55","20.00"
    "1048576","0.38 (min 0.32, max 0.47)","100.00","13.35","42.86"
    "524288","0.37 (min 0.31, max 0.48)","100.00","13.44","20.00"





SPI Flash Driver
-------------------------



K2G-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write UBIFS Throughput (Mbytes/sec)","k2g-evm: Write UBIFS CPU Load (%)","k2g-evm: Read UBIFS Throughput (Mbytes/sec)","k2g-evm: Read UBIFS CPU Load (%)"

    "262144","0.09 (min 0.08, max 0.09)","72.50 (min 70.36, max 73.95)","0.23","11.29"
    "102400","0.10 (min 0.08, max 0.14)","67.00 (min 49.57, max 73.77)","0.22","5.41"
    "1048576","0.09 (min 0.08, max 0.09)","72.91 (min 69.86, max 75.10)","0.23","8.25"
    "524288","0.09 (min 0.08, max 0.09)","73.15 (min 71.35, max 74.89)","0.22","8.25"





AM654X-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write UBIFS Throughput (Mbytes/sec)","am654x-evm: Write UBIFS CPU Load (%)","am654x-evm: Read UBIFS Throughput (Mbytes/sec)","am654x-evm: Read UBIFS CPU Load (%)"

    "262144","0.27 (min 0.24, max 0.29)","37.44 (min 36.59, max 39.14)","1.11","25.03"
    "102400","0.32 (min 0.26, max 0.55)","38.60 (min 33.81, max 45.52)","1.11","25.03"
    "1048576","0.27 (min 0.24, max 0.30)","38.21 (min 36.51, max 39.65)","1.11","25.00"
    "524288","0.27 (min 0.24, max 0.29)","39.82 (min 37.28, max 44.09)","1.11","25.13"





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

    "262144","12.26 (min 11.71, max 12.56)","2.67 (min 2.11, max 4.48)","67.72","8.77"
    "102400","12.29 (min 11.77, max 12.55)","2.57 (min 1.81, max 4.23)","65.86","8.60"
    "1048576","12.24 (min 11.79, max 12.51)","2.68 (min 2.16, max 4.17)","74.33","9.89"
    "524288","12.28 (min 11.34, max 12.54)","2.67 (min 1.81, max 4.66)","72.48","8.07"
    "5242880","12.26 (min 11.79, max 12.57)","2.87 (min 1.99, max 4.92)","74.80","10.25"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)"

    "262144","12.33 (min 11.84, max 12.54)","2.53 (min 1.81, max 3.80)","72.56","8.97"
    "102400","12.47 (min 12.21, max 12.58)","2.60 (min 2.17, max 4.03)","69.20","8.58"
    "1048576","12.35 (min 11.91, max 12.55)","2.61 (min 1.88, max 3.94)","78.85","7.92"
    "524288","12.46 (min 12.21, max 12.55)","2.83 (min 2.39, max 4.48)","77.40","8.46"
    "5242880","12.46 (min 12.20, max 12.56)","2.67 (min 1.93, max 4.42)","78.78","6.84"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "262144","12.35 (min 11.80, max 12.54)","2.53 (min 2.03, max 3.62)","73.81","8.80"
    "102400","12.15 (min 11.63, max 12.34)","2.25 (min 1.60, max 3.32)","70.01","6.83"
    "1048576","12.35 (min 11.84, max 12.52)","2.39 (min 1.80, max 3.34)","79.79","7.63"
    "524288","12.33 (min 11.80, max 12.54)","2.54 (min 2.04, max 3.64)","78.19","5.73"
    "5242880","12.50 (min 12.39, max 12.57)","2.25 (min 1.80, max 3.38)","79.85","7.34"

|










AM654x-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write VFAT Throughput (Mbytes/sec)","am654x-evm: Write VFAT CPU Load (%)","am654x-evm: Read VFAT Throughput (Mbytes/sec)","am654x-evm: Read VFAT CPU Load (%)"

    "262144","36.42 (min 33.34, max 37.62)","3.08 (min 2.52, max 4.86)","143.09","8.65"
    "102400","35.96 (min 31.97, max 37.17)","3.31 (min 2.63, max 5.80)","136.43","8.52"
    "1048576","36.45 (min 33.44, max 37.69)","3.12 (min 2.57, max 4.95)","161.49","10.04"
    "524288","36.26 (min 33.07, max 37.42)","3.13 (min 2.50, max 4.97)","156.97","10.74"
    "5242880","36.31 (min 33.25, max 37.48)","3.15 (min 2.51, max 5.07)","161.83","9.38"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write EXT2 Throughput (Mbytes/sec)","am654x-evm: Write EXT2 CPU Load (%)","am654x-evm: Read EXT2 Throughput (Mbytes/sec)","am654x-evm: Read EXT2 CPU Load (%)"

    "262144","37.29 (min 36.17, max 37.67)","1.90 (min 1.61, max 2.67)","146.37","9.47"
    "102400","36.99 (min 36.20, max 37.52)","2.04 (min 1.70, max 2.85)","133.49","7.07"
    "1048576","37.05 (min 35.99, max 37.62)","1.89 (min 1.50, max 2.74)","172.53","9.50"
    "524288","36.92 (min 36.07, max 37.45)","1.88 (min 1.60, max 2.75)","162.32","10.69"
    "5242880","37.28 (min 36.11, max 37.63)","1.95 (min 1.61, max 2.67)","171.67","9.80"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write EXT4 Throughput (Mbytes/sec)","am654x-evm: Write EXT4 CPU Load (%)","am654x-evm: Read EXT4 Throughput (Mbytes/sec)","am654x-evm: Read EXT4 CPU Load (%)"

    "262144","38.33 (min 37.81, max 38.60)","2.08 (min 1.94, max 2.44)","150.30","8.30"
    "102400","35.33 (min 34.73, max 35.83)","2.05 (min 1.86, max 2.40)","124.89","6.61"
    "1048576","38.25 (min 37.63, max 38.46)","2.08 (min 1.83, max 2.42)","181.80","9.17"
    "524288","38.17 (min 37.40, max 38.43)","1.98 (min 1.83, max 2.32)","168.64","8.91"
    "5242880","38.20 (min 37.44, max 38.59)","2.05 (min 1.82, max 2.67)","180.77","10.30"

|




































K2G-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write VFAT Throughput (Mbytes/sec)","k2g-evm: Write VFAT CPU Load (%)","k2g-evm: Read VFAT Throughput (Mbytes/sec)","k2g-evm: Read VFAT CPU Load (%)"

    "262144","21.15 (min 19.91, max 21.68)","16.02 (min 13.67, max 23.90)","40.43","16.41"
    "102400","21.29 (min 20.07, max 21.63)","16.05 (min 13.07, max 24.38)","39.95","14.68"
    "1048576","21.14 (min 20.07, max 21.73)","15.85 (min 12.78, max 24.57)","42.63","14.75"
    "524288","21.20 (min 20.15, max 21.69)","16.04 (min 13.62, max 24.62)","41.69","15.26"
    "5242880","21.18 (min 19.92, max 21.79)","15.97 (min 13.62, max 23.65)","42.61","15.79"

|



.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write EXT2 Throughput (Mbytes/sec)","k2g-evm: Write EXT2 CPU Load (%)","k2g-evm: Read EXT2 Throughput (Mbytes/sec)","k2g-evm: Read EXT2 CPU Load (%)"

    "262144","21.75 (min 20.34, max 22.16)","14.40 (min 12.31, max 21.53)","41.31","16.21"
    "102400","21.72 (min 20.52, max 22.28)","14.32 (min 12.18, max 22.11)","40.43","14.96"
    "1048576","21.63 (min 20.51, max 22.04)","14.17 (min 11.79, max 22.31)","43.07","12.55"
    "524288","21.70 (min 20.20, max 22.25)","14.34 (min 12.13, max 21.51)","42.69","13.99"
    "5242880","21.58 (min 20.61, max 21.87)","13.91 (min 11.39, max 22.09)","43.02","13.64"

|



.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write EXT4 Throughput (Mbytes/sec)","k2g-evm: Write EXT4 CPU Load (%)","k2g-evm: Read EXT4 Throughput (Mbytes/sec)","k2g-evm: Read EXT4 CPU Load (%)"

    "262144","21.18 (min 20.51, max 21.53)","14.00 (min 11.70, max 18.59)","38.54","14.13"
    "102400","21.09 (min 20.17, max 21.51)","13.39 (min 11.52, max 17.34)","40.47","14.96"
    "1048576","20.90 (min 20.49, max 21.17)","14.09 (min 12.96, max 17.58)","41.97","13.60"
    "524288","20.88 (min 20.40, max 21.22)","13.66 (min 12.07, max 17.51)","41.23","12.80"
    "5242880","21.20 (min 20.56, max 21.63)","14.30 (min 12.66, max 18.11)","43.51","13.45"

|



SATA Driver
-------------------------



.. rubric::  AM57XX-EVM
   :name: am57xx-evm


|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)"

    "262144","120.52 (min 106.20, max 124.49)","10.37 (min 5.60, max 26.09)","133.40","11.30"
    "102400","122.00 (min 107.45, max 127.28)","10.65 (min 6.61, max 25.04)","135.11","12.48"
    "1048576","122.66 (min 119.24, max 124.74)","10.91 (min 5.86, max 28.78)","133.11","11.35"
    "524288","122.66 (min 118.91, max 124.65)","10.26 (min 5.56, max 27.77)","132.97","11.62"
    "5242880","119.66 (min 107.24, max 125.24)","10.26 (min 6.00, max 25.49)","132.83","12.68"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "262144","117.26 (min 114.75, max 119.62)","9.47 (min 6.34, max 18.21)","125.34","11.06"
    "102400","115.71 (min 113.31, max 118.97)","10.12 (min 6.61, max 21.76)","126.77","11.55"
    "1048576","119.53 (min 117.09, max 122.31)","8.63 (min 6.90, max 14.63)","124.46","10.79"
    "524288","117.03 (min 114.25, max 118.52)","8.50 (min 6.23, max 15.64)","130.32","10.72"
    "5242880","115.49 (min 113.62, max 117.52)","8.06 (min 5.86, max 13.58)","130.29","10.85"

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

    "262144","64.07 (min 63.46, max 64.55)","4.48 (min 3.13, max 9.50)","234.23","21.85"
    "102400","64.09 (min 63.34, max 64.83)","4.30 (min 2.78, max 9.53)","226.10","23.33"
    "1048576","64.39 (min 63.83, max 64.94)","3.64 (min 2.64, max 5.95)","256.99","21.80"
    "524288","63.95 (min 63.04, max 64.49)","3.47 (min 2.74, max 4.72)","248.72","21.81"
    "5242880","64.44 (min 63.71, max 64.90)","3.62 (min 2.78, max 5.32)","257.49","21.08"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "262144","64.40 (min 63.97, max 64.92)","3.62 (min 3.13, max 5.03)","238.49","22.67"
    "102400","64.65 (min 63.57, max 65.59)","3.85 (min 3.21, max 5.53)","225.65","21.34"
    "1048576","64.71 (min 64.28, max 65.74)","3.78 (min 3.28, max 5.07)","265.56","21.94"
    "524288","64.66 (min 63.76, max 65.67)","4.08 (min 3.42, max 6.17)","255.10","21.52"
    "5242880","64.42 (min 64.05, max 65.11)","3.78 (min 3.21, max 5.36)","271.47","23.61"

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

    "262144","8.13 (min 7.70, max 9.07)","9.24 (min 7.63, max 14.80)","20.25","19.24"
    "102400","8.25 (min 7.65, max 8.95)","9.39 (min 7.46, max 14.36)","20.12","21.70"
    "1048576","7.69 (min 6.73, max 8.61)","8.88 (min 7.11, max 12.54)","21.06","19.07"
    "524288","7.53 (min 6.13, max 8.39)","8.49 (min 7.34, max 10.19)","20.98","17.36"
    "5242880","7.89 (min 7.05, max 8.84)","9.30 (min 7.45, max 14.63)","20.41","15.57"

|



.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write EXT2 Throughput (Mbytes/sec)","am335x-evm: Write EXT2 CPU Load (%)","am335x-evm: Read EXT2 Throughput (Mbytes/sec)","am335x-evm: Read EXT2 CPU Load (%)"

    "262144","8.86 (min 8.73, max 9.03)","8.77 (min 7.33, max 13.47)","21.47","21.78"
    "102400","7.86 (min 4.98, max 9.23)","7.37 (min 6.96, max 7.93)","21.10","24.80"
    "1048576","8.42 (min 6.87, max 10.49)","8.14 (min 6.08, max 10.37)","22.36","17.75"
    "524288","8.95 (min 8.55, max 9.39)","8.65 (min 7.15, max 12.17)","22.15","18.72"
    "5242880","9.30 (min 8.42, max 9.90)","9.65 (min 7.10, max 14.95)","22.28","16.63"

|



.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write EXT4 Throughput (Mbytes/sec)","am335x-evm: Write EXT4 CPU Load (%)","am335x-evm: Read EXT4 Throughput (Mbytes/sec)","am335x-evm: Read EXT4 CPU Load (%)"

    "262144","8.19 (min 6.42, max 9.21)","7.64 (min 7.18, max 8.16)","21.66","20.93"
    "102400","8.35 (min 7.60, max 9.75)","7.84 (min 6.29, max 11.73)","17.27","17.14"
    "1048576","8.33 (min 8.00, max 8.59)","7.84 (min 6.82, max 10.31)","22.59","17.95"
    "524288","8.52 (min 7.90, max 9.10)","7.85 (min 7.17, max 9.01)","22.30","18.86"
    "5242880","8.30 (min 7.40, max 8.90)","7.92 (min 7.19, max 9.45)","22.83","17.07"

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

    "262144","8.70 (min 7.52, max 9.23)","1.99 (min 1.28, max 3.27)","37.87","4.55"
    "102400","9.65 (min 8.36, max 10.36)","2.02 (min 1.64, max 2.88)","38.56","3.02"
    "1048576","6.05 (min 5.59, max 6.60)","1.38 (min 0.85, max 2.24)","40.21","4.62"
    "524288","7.33 (min 6.72, max 7.74)","1.77 (min 1.40, max 2.57)","39.31","5.08"
    "5242880","7.43 (min 6.49, max 8.37)","1.75 (min 1.27, max 2.46)","40.73","5.62"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)"

    "262144","10.26 (min 9.64, max 10.80)","2.23 (min 1.59, max 2.85)","40.21","3.87"
    "102400","9.65 (min 6.64, max 10.73)","1.91 (min 1.59, max 2.41)","39.46","1.56"
    "1048576","9.99 (min 8.45, max 11.93)","2.12 (min 1.26, max 3.39)","43.21","4.55"
    "524288","11.18 (min 10.36, max 11.41)","2.39 (min 1.86, max 3.57)","42.55","4.07"
    "5242880","10.17 (min 9.23, max 10.71)","2.00 (min 1.41, max 3.48)","43.22","5.13"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "262144","8.87 (min 7.73, max 10.20)","1.68 (min 1.22, max 2.64)","40.11","3.49"
    "102400","10.21 (min 8.88, max 11.55)","1.73 (min 1.40, max 2.39)","39.57","3.99"
    "1048576","9.45 (min 7.42, max 10.52)","1.71 (min 1.56, max 1.99)","43.41","2.94"
    "524288","9.00 (min 7.83, max 10.13)","1.77 (min 1.47, max 2.10)","42.82","3.51"
    "5242880","8.93 (min 6.75, max 10.77)","1.68 (min 1.57, max 1.81)","43.37","4.55"

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

    "262144","16.20 (min 12.97, max 17.32)","1.40 (min 1.19, max 2.17)","22.47","1.50"
    "102400","16.89 (min 15.78, max 17.32)","1.67 (min 1.19, max 3.09)","22.19","1.38"
    "1048576","16.77 (min 16.02, max 17.29)","1.51 (min 1.16, max 2.60)","23.06","1.54"
    "524288","16.23 (min 13.80, max 17.27)","1.45 (min 0.89, max 2.64)","22.88","1.53"
    "5242880","16.81 (min 15.96, max 17.22)","1.51 (min 1.08, max 2.70)","23.06","1.76"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write EXT2 Throughput (Mbytes/sec)","am654x-evm: Write EXT2 CPU Load (%)","am654x-evm: Read EXT2 Throughput (Mbytes/sec)","am654x-evm: Read EXT2 CPU Load (%)"

    "262144","16.52 (min 14.06, max 17.27)","0.89 (min 0.64, max 1.36)","22.98","1.48"
    "102400","17.23 (min 16.86, max 17.38)","0.89 (min 0.78, max 1.13)","22.61","1.35"
    "1048576","16.58 (min 13.86, max 17.34)","0.89 (min 0.74, max 1.06)","23.65","1.13"
    "524288","16.50 (min 14.05, max 17.31)","0.87 (min 0.70, max 1.16)","23.48","1.23"
    "5242880","17.17 (min 16.84, max 17.31)","0.95 (min 0.82, max 1.17)","23.64","1.19"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write EXT4 Throughput (Mbytes/sec)","am654x-evm: Write EXT4 CPU Load (%)","am654x-evm: Read EXT4 Throughput (Mbytes/sec)","am654x-evm: Read EXT4 CPU Load (%)"

    "262144","19.88 (min 19.61, max 20.04)","1.11 (min 0.99, max 1.36)","23.10","1.22"
    "102400","18.65 (min 17.10, max 19.94)","1.11 (min 0.94, max 1.36)","22.79","1.36"
    "1048576","19.68 (min 19.58, max 19.81)","1.10 (min 0.98, max 1.35)","23.82","1.08"
    "524288","19.35 (min 18.45, max 19.81)","1.02 (min 0.91, max 1.32)","23.64","1.30"
    "5242880","19.67 (min 19.46, max 19.85)","1.09 (min 0.99, max 1.31)","23.75","1.30"

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

    "262144","8.21 (min 7.10, max 9.25)","6.52 (min 4.48, max 12.69)","21.40","10.73"
    "102400","8.04 (min 6.97, max 8.64)","5.93 (min 4.68, max 8.95)","21.03","9.88"
    "1048576","8.68 (min 8.47, max 9.07)","6.84 (min 5.04, max 11.56)","21.99","8.46"
    "524288","8.18 (min 7.27, max 8.67)","6.50 (min 5.00, max 11.10)","21.94","8.07"
    "5242880","7.55 (min 6.48, max 8.64)","5.83 (min 4.45, max 9.53)","22.22","8.53"

|



.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write EXT2 Throughput (Mbytes/sec)","k2g-evm: Write EXT2 CPU Load (%)","k2g-evm: Read EXT2 Throughput (Mbytes/sec)","k2g-evm: Read EXT2 CPU Load (%)"

    "262144","6.95 (min 5.87, max 7.89)","5.15 (min 3.79, max 9.13)","22.04","8.82"
    "102400","6.33 (min 5.72, max 7.31)","4.24 (min 3.44, max 6.40)","21.71","9.48"
    "1048576","6.86 (min 5.61, max 7.99)","4.76 (min 2.90, max 6.89)","22.54","7.73"
    "524288","7.50 (min 7.12, max 7.77)","5.15 (min 4.15, max 8.17)","22.39","7.11"
    "5242880","6.91 (min 5.90, max 7.82)","4.55 (min 3.26, max 7.65)","22.72","7.21"

|



.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write EXT4 Throughput (Mbytes/sec)","k2g-evm: Write EXT4 CPU Load (%)","k2g-evm: Read EXT4 Throughput (Mbytes/sec)","k2g-evm: Read EXT4 CPU Load (%)"

    "262144","7.00 (min 5.97, max 8.11)","4.87 (min 4.23, max 5.42)","22.10","8.26"
    "102400","6.65 (min 5.57, max 7.94)","4.51 (min 3.04, max 6.96)","18.29","6.70"
    "1048576","7.42 (min 6.64, max 8.24)","5.10 (min 4.49, max 6.26)","22.82","7.21"
    "524288","6.89 (min 5.76, max 7.99)","4.90 (min 3.83, max 7.69)","22.62","6.15"
    "5242880","7.31 (min 6.74, max 8.33)","4.84 (min 4.20, max 6.64)","22.81","7.00"

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

    "262144","6.51 (min 4.50, max 7.24)","66.45 (min 54.28, max 73.54)","14.77","57.38"
    "102400","6.35 (min 4.47, max 7.07)","79.70 (min 61.78, max 98.46)","15.20","60.33"
    "1048576","6.25 (min 4.72, max 6.88)","59.67 (min 52.64, max 68.95)","14.41","50.51"
    "524288","6.72 (min 4.74, max 7.42)","63.42 (min 54.44, max 69.79)","14.66","54.53"
    "5242880","6.25 (min 4.64, max 6.99)","60.87 (min 53.45, max 68.38)","14.12","56.97"

|



.. csv-table::
    :header: "Buffer size (bytes)","omapl138-lcdk: Write EXT2 Throughput (Mbytes/sec)","omapl138-lcdk: Write EXT2 CPU Load (%)","omapl138-lcdk: Read EXT2 Throughput (Mbytes/sec)","omapl138-lcdk: Read EXT2 CPU Load (%)"

    "262144","6.95 (min 6.07, max 7.43)","51.57 (min 43.19, max 60.88)","15.51","59.50"
    "102400","6.59 (min 3.14, max 8.02)","53.18 (min 33.27, max 63.36)","15.68","61.91"
    "1048576","7.25 (min 6.80, max 7.46)","52.52 (min 48.46, max 60.71)","15.90","57.55"
    "524288","7.53 (min 6.94, max 8.37)","54.46 (min 51.33, max 60.85)","15.70","57.34"
    "5242880","7.22 (min 6.79, max 7.42)","50.62 (min 46.76, max 61.35)","15.20","61.74"

|



.. csv-table::
    :header: "Buffer size (bytes)","omapl138-lcdk: Write EXT4 Throughput (Mbytes/sec)","omapl138-lcdk: Write EXT4 CPU Load (%)","omapl138-lcdk: Read EXT4 Throughput (Mbytes/sec)","omapl138-lcdk: Read EXT4 CPU Load (%)"

    "262144","7.61 (min 7.23, max 7.82)","72.82 (min 67.96, max 79.11)","15.71","59.50"
    "102400","6.41 (min 5.75, max 6.86)","75.31 (min 63.80, max 86.90)","14.43","58.52"
    "1048576","7.19 (min 6.87, max 7.83)","67.73 (min 58.92, max 77.02)","16.00","56.54"
    "524288","7.42 (min 7.09, max 7.88)","72.93 (min 64.11, max 87.39)","15.96","57.84"
    "5242880","7.07 (min 6.25, max 7.57)","65.50 (min 57.39, max 80.01)","16.21","60.63"

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

**Setup** : Western Digital 1TB (My Book Essential) USB hard disk is
connected to usb0 port. File read/write performance data on usb0 port is
captured.

|


.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write VFAT Throughput (Mbytes/sec)","am335x-evm: Write VFAT CPU Load (%)","am335x-evm: Read VFAT Throughput (Mbytes/sec)","am335x-evm: Read VFAT CPU Load (%)","am654x-evm: Write VFAT Throughput (Mbytes/sec)","am654x-evm: Write VFAT CPU Load (%)","am654x-evm: Read VFAT Throughput (Mbytes/sec)","am654x-evm: Read VFAT CPU Load (%)","k2g-evm: Write VFAT Throughput (Mbytes/sec)","k2g-evm: Write VFAT CPU Load (%)","k2g-evm: Read VFAT Throughput (Mbytes/sec)","k2g-evm: Read VFAT CPU Load (%)"

    "262144","21.74 (min 20.76, max 22.21)","32.23 (min 27.10, max 43.27)","13.35","54.31","38.13 (min 35.04, max 39.00)","3.58 (min 2.72, max 5.44)","40.08","3.26","35.37 (min 32.38, max 36.25)","29.11 (min 24.91, max 39.94)","37.11","24.63"
    "102400","21.79 (min 20.71, max 22.18)","32.75 (min 28.38, max 42.58)","13.35","54.93","37.73 (min 33.75, max 38.79)","3.90 (min 2.97, max 5.98)","40.07","2.71","35.27 (min 32.26, max 36.11)","29.66 (min 25.80, max 40.25)","37.14","23.13"

Table: **USB Host VFAT**



.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write EXT2 Throughput (Mbytes/sec)","am335x-evm: Write EXT2 CPU Load (%)","am335x-evm: Read EXT2 Throughput (Mbytes/sec)","am335x-evm: Read EXT2 CPU Load (%)","am654x-evm: Write EXT2 Throughput (Mbytes/sec)","am654x-evm: Write EXT2 CPU Load (%)","am654x-evm: Read EXT2 Throughput (Mbytes/sec)","am654x-evm: Read EXT2 CPU Load (%)","k2g-evm: Write EXT2 Throughput (Mbytes/sec)","k2g-evm: Write EXT2 CPU Load (%)","k2g-evm: Read EXT2 Throughput (Mbytes/sec)","k2g-evm: Read EXT2 CPU Load (%)"

    "102400","22.27 (min 20.94, max 22.69)","28.05 (min 23.54, max 42.36)","13.29","57.08","39.55 (min 38.03, max 40.05)","2.78 (min 2.20, max 3.71)","39.94","3.07","35.76 (min 32.29, max 36.80)","26.78 (min 23.49, max 37.78)","37.09","25.99"
    "1048576","22.39 (min 21.11, max 22.77)","25.15 (min 21.13, max 38.70)","13.33","58.39","39.79 (min 38.56, max 40.25)","2.47 (min 2.11, max 3.14)","39.92","3.63","35.84 (min 32.59, max 36.76)","25.59 (min 21.32, max 38.22)","37.02","26.52"
    "5242880","22.40 (min 20.90, max 22.83)","25.72 (min 20.64, max 39.91)","13.31","56.87","39.77 (min 38.36, max 40.27)","2.59 (min 2.12, max 3.48)","39.67","3.98","35.86 (min 32.39, max 36.81)","25.50 (min 21.19, max 37.93)","37.04","25.72"

Table: **USB Host EXT2**





CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. csv-table::
    :header: "Algorithm","Buffer Size","am335x-evm: throughput","am57xx-evm: throughput","am654x-evm: throughput"

    "sha1","1024","9364.14","12825.94","185589.76"
    "des-cbc","16","2619.04","316.59","53904.84"
    "aes-192-cbc","8192","23306.24","31435.43","30158028.80"
    "aes-256-cbc","8192","21703.34","31435.43","7214694.40"
    "sha1","8192","41552.55","54777.17","1506690.84"
    "aes-256-cbc","64","7231.19","13089.45","88535.04"
    "sha1","64","1733.42","3099.78","10788.59"
    "sha1","16","450.67","786.73","2645.18"
    "aes-128-cbc","8192","22771.03","31793.15","10434150.40"
    "md5","256","3493.46","4363.43","50641.42"
    "aes-192-cbc","64","7864.70","14199.64","88936.96"
    "aes-192-cbc","16","2610.46","4523.69","18428.80"
    "aes-256-cbc","1024","11444.91","14174.21","454122.06"
    "des3","64","4075.86","1207.10","448691.20"
    "des3","1024","5848.06","9154.90","674201.60"
    "des-cbc","64","6835.37","1198.42","187261.71"
    "md5","64","1930.97","3514.58","10752.82"
    "sha1","256","3491.58","4647.00","45702.04"
    "aes-192-cbc","256","4670.38","5058.39","193908.62"
    "md5","16","478.16","891.13","2852.27"
    "des-cbc","256","11326.98","3944.70","559623.31"
    "des-cbc","1024","13918.21","9253.21","2234521.60"
    "aes-128-cbc","256","4830.63","5044.74","347269.12"
    "aes-256-cbc","16","2555.78","4131.27","27700.40"
    "md5","8192","41751.89","56655.87","1256516.27"
    "aes-128-cbc","1024","12121.43","14582.10","1055948.80"
    "aes-192-cbc","1024","11621.03","14212.44","708232.53"
    "aes-128-cbc","16","2684.54","4358.76","13817.40"
    "des-cbc","8192","14674.60","15141.55",""
    "des3","8192","5857.28","14827.52","20538163.20"
    "des3","256","5395.71","3938.99","194087.82"
    "aes-256-cbc","256","4584.70","5053.10","247833.60"
    "des3","16","2037.96","320.05","19491.73"
    "aes-128-cbc","64","8201.62","14479.74","40152.44"
    "md5","1024","9724.93","13874.18","207196.16"


|
|

.. csv-table::
    :header: "Algorithm","am335x-evm: CPU Load","am57xx-evm: CPU Load","am654x-evm: CPU Load"

    "des3","98.00","23.00","41.00"
    "sha1","75.00","75.00","99.00"
    "aes-256-cbc","50.00","52.00","44.00"
    "md5","76.00","73.00","99.00"
    "des-cbc","98.00","24.00","99.00"
    "aes-192-cbc","51.00","52.00","44.00"
    "aes-128-cbc","50.00","51.00","45.00"



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

    "3des","17.10","1.00","74.70"
    "aes128","9.90","0.00","40.00","147.50","13.00","63.10","220.00","19.00","32.10"
    "aes256","23.00","2.00","82.30","119.00","10.00","53.80","230.00","20.00","32.30"
    "aes192","10.90","0.00","81.20","118.40","10.00","52.20","230.00","20.00","32.20"



DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.

Power Management
-------------------------



AM335x-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric:: At each OPP
   :name: each-opp

This section indicates the power measured for all power rails at various OPPs
Measurements were taken while Linux was idle at command prompt.


.. csv-table::
    :header: "Power Rail","am335x-evm: 300M (mw)","am335x-evm: 600M (mw)","am335x-evm: 720M (mw)","am335x-evm: 800M (mw)","am335x-evm: 1000M (mw)"

    "vdds_rtc_power","0.66","0.66","0.66","0.66","0.66"
    "vddshv4_power","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)"
    "vdds_pll_ddr_power","3.92","3.92","3.92","3.92","3.92"
    "vdda_1p8v_usb0_1_power","33.22 (min 32.89, max 33.35)","32.85 (min 32.82, max 32.87)","32.85 (min 32.83, max 32.87)","32.89 (min 32.88, max 32.90)","32.90 (min 32.89, max 32.92)"
    "vddshv3_power","0.15 (min 0.15, max 0.16)","0.15","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)"
    "vddshv5_power","50.97 (min 50.86, max 51.87)","50.99 (min 50.89, max 51.82)","51.05 (min 50.89, max 51.95)","51.07 (min 50.93, max 51.79)","51.05 (min 50.97, max 51.41)"
    "vddshv6_power","35.92 (min 35.91, max 35.92)","35.92 (min 35.91, max 35.92)","35.92 (min 35.91, max 35.92)","35.93","35.93 (min 35.93, max 35.94)"
    "vdds_osc_power","1.23","1.23","1.23","1.23","1.23"
    "vdds_ddr_power","142.72 (min 142.12, max 143.24)","143.20 (min 142.56, max 143.61)","143.10 (min 142.40, max 143.52)","142.61 (min 142.10, max 143.75)","143.05 (min 142.59, max 143.52)"
    "vdd_mpu_power","46.26 (min 45.65, max 47.03)","77.79 (min 75.38, max 81.78)","115.01 (min 98.96, max 180.20)","117.60 (min 110.70, max 121.97)","154.61 (min 140.37, max 208.95)"
    "vddshv1_power","0.40 (min 0.39, max 0.40)","0.39 (min 0.39, max 0.40)","0.39 (min 0.39, max 0.40)","0.39 (min 0.39, max 0.40)","0.39 (min 0.38, max 0.40)"
    "vdds_power","2.42 (min 2.41, max 2.42)","2.41 (min 2.41, max 2.42)","2.42 (min 2.41, max 2.42)","2.42 (min 2.41, max 2.42)","2.42 (min 2.41, max 2.42)"
    "vdds_a3p3v_usb0_1_power","11.10 (min 11.10, max 11.11)","11.10","11.10","11.10","11.09 (min 11.09, max 11.10)"
    "vddshv2_power","2.58 (min 2.57, max 2.58)","2.58 (min 2.57, max 2.58)","2.58 (min 2.57, max 2.58)","2.58 (min 2.57, max 2.58)","2.58 (min 2.57, max 2.58)"
    "vdds_sram_core_bg_power","2.10 (min 2.09, max 2.10)","2.12 (min 2.11, max 2.13)","2.12 (min 2.11, max 2.12)","2.15 (min 2.14, max 2.15)","2.17"
    "vdds_sram_mpu_bb_power","2.83 (min 2.82, max 2.84)","2.88 (min 2.87, max 2.89)","2.90 (min 2.88, max 2.91)","3.43 (min 3.43, max 3.44)","4.11 (min 4.09, max 4.13)"
    "vdds_pll_core_lcd_power","13.14 (min 13.14, max 13.15)","13.15 (min 13.14, max 13.15)","13.15 (min 13.14, max 13.15)","13.15","13.15"
    "vdd_core_power","206.96 (min 206.70, max 207.40)","207.26 (min 207.16, max 207.34)","207.43 (min 207.23, max 207.82)","207.50 (min 207.34, max 207.65)","207.73 (min 207.60, max 207.83)"
    "vdda_adc_power","7.45 (min 7.35, max 7.52)","7.48 (min 7.37, max 7.53)","7.53 (min 7.49, max 7.56)","7.51 (min 7.47, max 7.56)","7.51 (min 7.46, max 7.52)"
    "vdds_pll_mpu_power","2.03","3.71","4.33","4.56","5.62"
    "total_power","566.14 (min 564.94, max 566.99)","599.86 (min 597.23, max 604.15)","637.90 (min 622.41, max 702.83)","640.94 (min 634.10, max 645.55)","680.36 (min 665.87, max 735.20)"

Table: **Active Power Consumption at various OPPs with idle system**



.. csv-table::
    :header: "Power Rail","am335x-evm: 300M (mw)","am335x-evm: 600M (mw)","am335x-evm: 720M (mw)","am335x-evm: 800M (mw)","am335x-evm: 1000M (mw)"

    "vdds_rtc_power","0.66","0.66","0.66","0.66","0.66"
    "vddshv4_power","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)"
    "vdds_pll_ddr_power","3.92","3.92","3.92","3.92","3.92"
    "vdda_1p8v_usb0_1_power","32.89 (min 32.86, max 32.91)","32.91 (min 32.88, max 32.92)","32.90 (min 32.89, max 32.91)","7.30 (min 7.28, max 7.31)","32.89 (min 32.88, max 32.90)"
    "vddshv3_power","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15","0.15 (min 0.15, max 0.16)"
    "vddshv5_power","51.13 (min 50.92, max 52.12)","51.07 (min 50.98, max 51.43)","51.19 (min 50.96, max 52.12)","51.33 (min 50.96, max 52.15)","51.19 (min 51.00, max 51.96)"
    "vddshv6_power","35.93","35.93 (min 35.93, max 35.94)","35.93 (min 35.92, max 35.93)","34.83 (min 34.82, max 34.83)","35.92 (min 35.92, max 35.93)"
    "vdds_osc_power","1.23","1.23","1.23","1.23","1.23"
    "vdds_ddr_power","150.86 (min 149.10, max 152.06)","150.20 (min 149.55, max 150.96)","150.91 (min 150.36, max 151.94)","151.00 (min 149.70, max 152.08)","150.60 (min 149.83, max 151.81)"
    "vdd_mpu_power","55.65 (min 53.56, max 56.83)","102.23 (min 97.78, max 106.06)","153.13 (min 140.09, max 198.76)","168.77 (min 159.11, max 180.05)","207.44 (min 187.90, max 219.68)"
    "vddshv1_power","0.39 (min 0.39, max 0.41)","0.39 (min 0.38, max 0.39)","0.39 (min 0.38, max 0.39)","0.39 (min 0.39, max 0.40)","0.39"
    "vdds_power","2.42 (min 2.41, max 2.43)","2.42 (min 2.41, max 2.42)","2.42 (min 2.41, max 2.42)","2.41 (min 2.41, max 2.42)","2.42 (min 2.41, max 2.42)"
    "vdds_a3p3v_usb0_1_power","11.10","11.09","11.09","6.67","11.09"
    "vddshv2_power","2.58 (min 2.57, max 2.58)","2.57 (min 2.57, max 2.58)","2.57 (min 2.57, max 2.58)","2.57 (min 2.57, max 2.58)","2.57 (min 2.57, max 2.58)"
    "vdds_sram_core_bg_power","2.27 (min 2.25, max 2.28)","2.30 (min 2.28, max 2.33)","2.30 (min 2.29, max 2.30)","2.28 (min 2.26, max 2.30)","2.32 (min 2.31, max 2.33)"
    "vdds_sram_mpu_bb_power","2.99 (min 2.97, max 3.00)","3.14 (min 3.11, max 3.20)","3.12 (min 3.09, max 3.16)","3.61 (min 3.59, max 3.62)","4.29 (min 4.25, max 4.32)"
    "vdds_pll_core_lcd_power","13.15","13.15","13.15","13.15","13.15"
    "vdd_core_power","243.26 (min 239.69, max 247.47)","243.22 (min 240.57, max 248.59)","245.02 (min 239.33, max 249.76)","245.39 (min 241.48, max 247.59)","243.57 (min 240.57, max 248.06)"
    "vdda_adc_power","7.06 (min 7.00, max 7.16)","7.16 (min 7.06, max 7.25)","7.19 (min 7.12, max 7.24)","7.27 (min 7.22, max 7.32)","7.31 (min 7.26, max 7.35)"
    "vdds_pll_mpu_power","2.03","3.71","4.33","4.56","5.62"
    "total_power","619.76 (min 612.97, max 623.54)","667.54 (min 660.46, max 676.70)","721.69 (min 703.28, max 768.43)","707.59 (min 699.00, max 719.19)","776.83 (min 755.83, max 792.66)"

Table: **Active Power Consumption at various OPPs with 3D Graphics**



.. csv-table::
    :header: "Power Rail","am335x-evm: 300M (mw)","am335x-evm: 600M (mw)","am335x-evm: 720M (mw)","am335x-evm: 800M (mw)","am335x-evm: 1000M (mw)"

    "vdds_rtc_power","0.66","0.66","0.66","0.66","0.66"
    "vddshv4_power","0.08 (min 0.08, max 0.09)","1.82 (min 0.08, max 8.76)","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.08"
    "vdds_pll_ddr_power","3.92","3.92","3.92 (min 3.92, max 3.93)","3.92","3.92"
    "vdda_1p8v_usb0_1_power","32.90 (min 32.89, max 32.91)","32.91 (min 32.90, max 32.92)","33.23 (min 33.02, max 33.35)","32.91 (min 32.89, max 32.93)","32.90 (min 32.88, max 32.91)"
    "vddshv3_power","0.15 (min 0.14, max 0.15)","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15","0.15"
    "vddshv5_power","51.04 (min 50.92, max 51.97)","51.10 (min 50.97, max 51.35)","51.25 (min 51.01, max 52.22)","51.20 (min 50.99, max 52.01)","51.01 (min 50.96, max 51.15)"
    "vddshv6_power","30.77 (min 30.55, max 30.93)","35.94 (min 35.93, max 35.94)","30.75 (min 30.45, max 30.93)","30.64 (min 30.50, max 30.80)","30.73 (min 30.45, max 30.88)"
    "vdds_osc_power","1.23","1.23","1.23","1.23","1.23"
    "vdds_ddr_power","142.07 (min 141.76, max 142.73)","142.87 (min 142.36, max 143.73)","142.39 (min 142.19, max 142.78)","142.57 (min 142.01, max 143.23)","142.68 (min 142.33, max 143.03)"
    "vdd_mpu_power","49.60 (min 45.33, max 79.95)","77.89 (min 75.72, max 79.17)","114.41 (min 94.56, max 187.30)","111.78 (min 108.62, max 115.69)","134.25 (min 130.87, max 139.02)"
    "vddshv1_power","0.39 (min 0.38, max 0.39)","0.39 (min 0.39, max 0.40)","0.39 (min 0.38, max 0.39)","0.40 (min 0.39, max 0.41)","0.39 (min 0.39, max 0.40)"
    "vdds_power","2.56 (min 2.55, max 2.56)","2.51 (min 2.41, max 2.87)","2.56 (min 2.56, max 2.57)","2.56 (min 2.55, max 2.57)","2.55 (min 2.55, max 2.56)"
    "vdds_a3p3v_usb0_1_power","11.10","11.10","11.10 (min 11.09, max 11.10)","11.09 (min 11.09, max 11.10)","11.09 (min 11.09, max 11.10)"
    "vddshv2_power","9.34 (min 9.11, max 9.52)","2.57 (min 2.57, max 2.58)","9.27 (min 9.09, max 9.43)","9.40 (min 9.09, max 9.52)","9.24 (min 9.06, max 9.44)"
    "vdds_sram_core_bg_power","2.13 (min 2.13, max 2.15)","2.16 (min 2.15, max 2.18)","2.18 (min 2.18, max 2.19)","2.17 (min 2.17, max 2.18)","2.17 (min 2.16, max 2.18)"
    "vdds_sram_mpu_bb_power","2.87 (min 2.86, max 2.90)","2.93 (min 2.92, max 2.94)","2.95 (min 2.94, max 2.96)","3.45 (min 3.44, max 3.46)","4.10 (min 4.08, max 4.12)"
    "vdds_pll_core_lcd_power","13.15","13.15 (min 13.15, max 13.16)","13.16","13.15 (min 13.15, max 13.16)","13.15"
    "vdd_core_power","208.26 (min 207.78, max 210.51)","207.98 (min 207.53, max 209.12)","208.64 (min 208.57, max 208.69)","208.55 (min 208.46, max 208.70)","208.56 (min 208.49, max 208.69)"
    "vdda_adc_power","7.42 (min 7.23, max 7.51)","7.50 (min 7.40, max 7.54)","7.51 (min 7.49, max 7.52)","7.52 (min 7.51, max 7.53)","7.51 (min 7.49, max 7.51)"
    "vdds_pll_mpu_power","2.03","3.71","4.33","4.56","5.62"
    "total_power","571.66 (min 566.71, max 604.82)","602.50 (min 597.44, max 612.16)","640.17 (min 620.42, max 712.19)","638.00 (min 634.28, max 641.47)","661.99 (min 658.83, max 666.65)"

Table: **Active Power Consumption at various OPPs with video+audio**



.. csv-table::
    :header: "Power Rail","am335x-evm: 300M (mw)","am335x-evm: 600M (mw)","am335x-evm: 720M (mw)","am335x-evm: 800M (mw)","am335x-evm: 1000M (mw)"

    "vdds_rtc_power","0.66","0.66","0.66","0.66","0.66"
    "vddshv4_power","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.08","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)"
    "vdds_pll_ddr_power","3.92","3.92","3.92","3.92","3.92"
    "vdda_1p8v_usb0_1_power","32.88 (min 32.87, max 32.89)","32.90 (min 32.89, max 32.92)","32.86 (min 32.83, max 32.89)","33.37 (min 33.32, max 33.41)","33.35 (min 33.22, max 33.43)"
    "vddshv3_power","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15"
    "vddshv5_power","51.14 (min 50.94, max 52.06)","50.98 (min 50.95, max 51.07)","50.98 (min 50.92, max 51.18)","51.13 (min 51.01, max 51.56)","51.04 (min 50.99, max 51.19)"
    "vddshv6_power","30.80 (min 30.45, max 30.96)","30.74 (min 30.60, max 30.90)","30.78 (min 30.48, max 30.89)","30.70 (min 30.47, max 30.90)","30.64 (min 30.47, max 30.99)"
    "vdds_osc_power","1.23","1.23","1.23","1.23","1.23"
    "vdds_ddr_power","141.90 (min 141.57, max 142.08)","142.69 (min 142.55, max 143.07)","142.93 (min 142.30, max 143.46)","143.14 (min 142.61, max 144.82)","142.84 (min 141.90, max 144.54)"
    "vdd_mpu_power","46.69 (min 45.34, max 47.62)","75.82 (min 73.79, max 77.99)","125.42 (min 94.76, max 239.53)","111.68 (min 109.11, max 114.42)","139.07 (min 129.07, max 145.33)"
    "vddshv1_power","0.39 (min 0.39, max 0.40)","0.39 (min 0.39, max 0.40)","0.39 (min 0.39, max 0.40)","0.39 (min 0.39, max 0.40)","0.39 (min 0.38, max 0.40)"
    "vdds_power","2.56 (min 2.55, max 2.56)","2.56 (min 2.55, max 2.57)","2.55 (min 2.55, max 2.56)","2.56 (min 2.55, max 2.56)","2.56"
    "vdds_a3p3v_usb0_1_power","11.10","11.10","11.10","11.09","11.09"
    "vddshv2_power","9.34 (min 9.04, max 9.55)","9.32 (min 9.04, max 9.44)","9.35 (min 9.20, max 9.48)","9.27 (min 9.07, max 9.48)","9.36 (min 9.15, max 9.47)"
    "vdds_sram_core_bg_power","2.13 (min 2.13, max 2.15)","2.14 (min 2.14, max 2.15)","2.14 (min 2.13, max 2.15)","2.18 (min 2.17, max 2.19)","2.18 (min 2.18, max 2.19)"
    "vdds_sram_mpu_bb_power","2.88 (min 2.86, max 2.90)","3.01 (min 2.90, max 3.28)","2.92 (min 2.91, max 2.93)","3.46 (min 3.44, max 3.47)","4.11 (min 4.09, max 4.12)"
    "vdds_pll_core_lcd_power","13.15","13.15","13.15","13.15 (min 13.15, max 13.16)","13.15"
    "vdd_core_power","208.06 (min 207.87, max 208.21)","208.34 (min 208.24, max 208.44)","208.30 (min 208.22, max 208.40)","208.76 (min 208.65, max 208.86)","208.78 (min 208.66, max 208.86)"
    "vdda_adc_power","7.46 (min 7.36, max 7.51)","7.53 (min 7.51, max 7.58)","7.52 (min 7.51, max 7.54)","7.54 (min 7.50, max 7.58)","7.51 (min 7.50, max 7.52)"
    "vdds_pll_mpu_power","2.03","3.71","4.33","4.56","5.62"
    "total_power","568.58 (min 566.76, max 569.51)","600.43 (min 598.59, max 602.28)","650.78 (min 620.00, max 764.36)","639.04 (min 636.42, max 640.84)","667.73 (min 658.08, max 675.85)"

Table: **Active Power Consumption at various OPPs with network load**



.. csv-table::
    :header: "Power Rail","am335x-evm: 300M (mw)","am335x-evm: 600M (mw)","am335x-evm: 720M (mw)","am335x-evm: 800M (mw)","am335x-evm: 1000M (mw)"

    "vdds_rtc_power","0.66","0.66","0.66","0.66","0.66"
    "vddshv4_power","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.08","0.08 (min 0.08, max 0.09)","0.08"
    "vdds_pll_ddr_power","3.92","3.92","3.92 (min 3.92, max 3.93)","3.92 (min 3.92, max 3.93)","3.93 (min 3.92, max 3.93)"
    "vdda_1p8v_usb0_1_power","32.92 (min 32.91, max 32.94)","32.93 (min 32.92, max 32.94)","32.93 (min 32.92, max 32.94)","32.93 (min 32.91, max 32.94)","33.17 (min 32.91, max 33.36)"
    "vddshv3_power","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15","0.15 (min 0.15, max 0.16)","0.15"
    "vddshv5_power","51.11 (min 50.99, max 51.58)","51.10 (min 51.09, max 51.10)","51.37 (min 51.15, max 52.19)","51.64 (min 51.25, max 52.47)","51.51 (min 51.31, max 52.22)"
    "vddshv6_power","30.77 (min 30.46, max 30.93)","30.78 (min 30.56, max 31.01)","30.86 (min 30.74, max 31.02)","30.84 (min 30.66, max 30.96)","30.74 (min 30.46, max 30.94)"
    "vdds_osc_power","1.23","1.23","1.23","1.22 (min 1.22, max 1.23)","1.22"
    "vdds_ddr_power","143.03 (min 142.59, max 143.34)","143.60 (min 143.46, max 143.74)","143.32 (min 143.21, max 143.53)","143.14 (min 142.52, max 145.24)","142.87 (min 142.33, max 143.06)"
    "vdd_mpu_power","112.64 (min 104.69, max 113.69)","304.65 (min 304.42, max 304.81)","438.69 (min 430.15, max 441.34)","545.51 (min 545.07, max 545.76)","727.87 (min 666.66, max 744.40)"
    "vddshv1_power","0.39 (min 0.38, max 0.40)","0.39","0.39 (min 0.38, max 0.39)","0.39 (min 0.38, max 0.39)","0.39 (min 0.38, max 0.39)"
    "vdds_power","2.55 (min 2.55, max 2.56)","2.56","2.56 (min 2.55, max 2.56)","2.56 (min 2.55, max 2.57)","2.56"
    "vdds_a3p3v_usb0_1_power","11.10","11.09 (min 11.08, max 11.09)","11.07 (min 11.07, max 11.08)","11.06 (min 11.06, max 11.07)","11.04 (min 11.04, max 11.05)"
    "vddshv2_power","9.33 (min 9.09, max 9.54)","9.37 (min 9.06, max 9.56)","9.33 (min 9.10, max 9.54)","9.31 (min 9.06, max 9.47)","9.45 (min 9.35, max 9.54)"
    "vdds_sram_core_bg_power","2.16 (min 2.15, max 2.17)","2.22 (min 2.22, max 2.23)","2.28 (min 2.27, max 2.29)","2.36 (min 2.34, max 2.37)","2.44 (min 2.41, max 2.46)"
    "vdds_sram_mpu_bb_power","4.77 (min 4.75, max 4.79)","7.27 (min 7.26, max 7.28)","8.35 (min 8.32, max 8.36)","9.31 (min 9.29, max 9.33)","11.52 (min 10.37, max 11.85)"
    "vdds_pll_core_lcd_power","13.15","13.16","13.16","13.16","13.16 (min 13.16, max 13.17)"
    "vdd_core_power","206.09 (min 205.70, max 209.20)","206.68 (min 206.62, max 206.74)","207.84 (min 207.21, max 210.31)","207.84 (min 207.73, max 207.94)","208.57 (min 208.35, max 208.74)"
    "vdda_adc_power","7.56 (min 7.53, max 7.61)","7.59 (min 7.56, max 7.62)","7.59 (min 7.58, max 7.62)","7.56 (min 7.55, max 7.61)","7.60 (min 7.54, max 7.62)"
    "vdds_pll_mpu_power","2.03","3.71","4.33","4.56 (min 4.55, max 4.56)","5.62 (min 5.61, max 5.62)"
    "total_power","635.66 (min 627.73, max 639.64)","833.14 (min 832.77, max 833.52)","970.11 (min 960.37, max 973.90)","1078.21 (min 1076.68, max 1079.44)","1264.54 (min 1203.05, max 1281.89)"

Table: **Active Power Consumption at various OPPs with Dhrystone**



.. csv-table::
    :header: "Power Rail","am335x-evm: 300M (mw)","am335x-evm: 600M (mw)","am335x-evm: 720M (mw)","am335x-evm: 800M (mw)","am335x-evm: 1000M (mw)"

    "vdds_rtc_power","0.66","0.66","0.66","0.66","0.66"
    "vddshv4_power","0.08 (min 0.08, max 0.09)","0.08","0.09","0.08 (min 0.08, max 0.09)","0.08"
    "vdds_pll_ddr_power","3.92 (min 3.92, max 3.93)","3.92","3.93","3.93","3.92"
    "vdda_1p8v_usb0_1_power","32.92 (min 32.91, max 32.94)","32.92 (min 32.91, max 32.93)","32.92 (min 32.92, max 32.93)","32.92 (min 32.92, max 32.93)","32.92 (min 32.90, max 32.92)"
    "vddshv3_power","0.15 (min 0.14, max 0.15)","0.15","0.15 (min 0.15, max 0.16)","0.15","0.15"
    "vddshv5_power","51.11 (min 50.99, max 51.66)","51.07 (min 51.06, max 51.07)","51.12 (min 51.12, max 51.13)","51.12 (min 51.11, max 51.13)","51.34 (min 51.16, max 52.03)"
    "vddshv6_power","30.76 (min 30.48, max 31.01)","30.72 (min 30.46, max 30.86)","30.73 (min 30.46, max 31.03)","30.80 (min 30.46, max 30.96)","30.73 (min 30.46, max 30.90)"
    "vdds_osc_power","1.23","1.23","1.23","1.23","1.23"
    "vdds_ddr_power","148.08 (min 143.33, max 151.80)","149.52 (min 144.31, max 157.93)","151.71 (min 144.32, max 156.78)","152.22 (min 144.49, max 157.99)","149.70 (min 144.69, max 158.09)"
    "vdd_mpu_power","87.25 (min 81.08, max 92.32)","209.37 (min 206.90, max 213.43)","291.16 (min 285.78, max 299.07)","347.52 (min 343.46, max 362.53)","463.34 (min 445.47, max 475.18)"
    "vddshv1_power","0.39 (min 0.38, max 0.39)","0.39 (min 0.38, max 0.39)","0.39 (min 0.38, max 0.39)","0.39 (min 0.38, max 0.39)","0.38 (min 0.38, max 0.39)"
    "vdds_power","2.56 (min 2.55, max 2.57)","2.56","2.56 (min 2.55, max 2.56)","2.56 (min 2.55, max 2.56)","2.56 (min 2.56, max 2.57)"
    "vdds_a3p3v_usb0_1_power","11.10 (min 11.09, max 11.10)","11.08 (min 11.08, max 11.09)","11.08","11.08","11.07 (min 11.06, max 11.07)"
    "vddshv2_power","9.34 (min 9.07, max 9.53)","9.40 (min 9.11, max 9.56)","9.35 (min 9.19, max 9.44)","9.28 (min 9.05, max 9.54)","9.26 (min 9.05, max 9.47)"
    "vdds_sram_core_bg_power","2.17 (min 2.16, max 2.18)","2.22","2.26 (min 2.25, max 2.26)","2.27 (min 2.26, max 2.27)","2.32 (min 2.30, max 2.32)"
    "vdds_sram_mpu_bb_power","3.87 (min 3.79, max 3.99)","4.77 (min 4.54, max 4.92)","4.91 (min 4.68, max 5.24)","5.37 (min 5.10, max 5.77)","6.45 (min 5.87, max 6.83)"
    "vdds_pll_core_lcd_power","13.16 (min 13.15, max 13.16)","13.16","13.16","13.16","13.16"
    "vdd_core_power","213.93 (min 210.94, max 217.39)","218.05 (min 214.64, max 221.89)","218.90 (min 216.27, max 222.71)","221.68 (min 216.65, max 223.27)","221.85 (min 218.52, max 224.14)"
    "vdda_adc_power","7.51 (min 7.51, max 7.52)","7.54 (min 7.52, max 7.56)","7.53 (min 7.51, max 7.57)","7.53 (min 7.51, max 7.55)","7.53 (min 7.51, max 7.56)"
    "vdds_pll_mpu_power","2.03","3.71","4.33","4.56","5.62"
    "total_power","622.23 (min 615.01, max 633.15)","752.51 (min 745.00, max 763.67)","838.17 (min 835.01, max 842.97)","898.50 (min 889.34, max 901.37)","1014.27 (min 1003.99, max 1023.10)"

Table: **Active Power Consumption at various OPPs with Memory Tester**


.. rubric:: Power-Saving States
   :name: power-saving-states

This section indicates the power measured for all power rails when system is
in suspended state (via suspend-to-ram) and in standby state.


.. csv-table::
    :header: "Power Rail","am335x-evm: Suspend Power (mw)","am335x-evm: Standby Power (mw)"

    "vdds_rtc_power","0.04","0.04"
    "vddshv4_power","0.09 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)"
    "vdds_pll_ddr_power","0.00","0.00"
    "vdda_1p8v_usb0_1_power","0.00","0.00"
    "vddshv3_power","0.12 (min 0.11, max 0.13)","0.16"
    "vddshv5_power","0.11 (min 0.11, max 0.12)","0.11 (min 0.11, max 0.12)"
    "vddshv6_power","0.54 (min 0.54, max 0.55)","0.54 (min 0.54, max 0.55)"
    "vdds_osc_power","0.00","1.24"
    "vdds_ddr_power","0.75 (min 0.74, max 0.76)","0.75 (min 0.75, max 0.76)"
    "vdd_mpu_power","0.26 (min 0.25, max 0.27)","0.31 (min 0.30, max 0.32)"
    "vddshv1_power","0.28 (min 0.27, max 0.29)","0.42 (min 0.41, max 0.42)"
    "vdds_power","1.30 (min 1.29, max 1.33)","0.88 (min 0.88, max 0.89)"
    "vdds_a3p3v_usb0_1_power","0.07","0.08 (min 0.07, max 0.08)"
    "vddshv2_power","0.08 (min 0.08, max 0.09)","0.08"
    "vdds_sram_core_bg_power","0.83 (min 0.82, max 0.86)","1.87 (min 1.86, max 1.89)"
    "vdds_sram_mpu_bb_power","0.01","0.01"
    "vdds_pll_core_lcd_power","0.00","0.00"
    "vdd_core_power","1.19 (min 1.16, max 1.25)","13.34 (min 13.25, max 13.46)"
    "vdda_adc_power","0.00","0.00 (min 0.00, max 0.01)"
    "vdds_pll_mpu_power","0.00","0.00"
    "total_power","5.68 (min 5.63, max 5.82)","19.94 (min 19.83, max 20.10)"


.. rubric:: Wakeup Times
   :name: wakeup-times

This section indicates the time it takes to resume the board from suspend and standby state.
Two wakeup mechanisms (UART console and Real Time Clock) were used.


.. csv-table::
    :header: "Wakeup time","am335x-evm: Suspend UART (ms)","am335x-evm: Standby UART (ms)","am335x-evm: Suspend RTC (ms)","am335x-evm: Standby RTC (ms)","am335x-evm: Suspend GPIO (ms)"

    "resume_time","2347.37 (min 2342.50, max 2351.52)","2490.67 (min 2486.81, max 2494.47)","2346.59 (min 2343.35, max 2351.21)","2493.32 (min 2488.24, max 2495.87)","2346.15 (min 2342.67, max 2349.94)"




.. rubric:: With different Governors
   :name: different-governors

This section indicates the power measured for all power rails with different power management policies.


.. csv-table::
    :header: "Power Rail","am335x-evm: idle (mw)","am335x-evm: 3D graphics (mw)","am335x-evm: video+audio (mw)","am335x-evm: network load (mw)","am335x-evm: Dhrystone (mw)","am335x-evm: memtester (mw)"

    "vdds_rtc_power","0.66","0.66","0.66","0.66","0.66","0.66"
    "vddshv4_power","0.08","0.08 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.08","0.08"
    "vdds_pll_ddr_power","3.92","3.92","3.92","3.92 (min 3.92, max 3.93)","3.93 (min 3.92, max 3.93)","3.92"
    "vdda_1p8v_usb0_1_power","32.90 (min 32.88, max 32.92)","32.91","32.89 (min 32.86, max 32.90)","32.90 (min 32.88, max 32.91)","33.30 (min 33.20, max 33.34)","32.88 (min 32.87, max 32.89)"
    "vddshv3_power","0.15 (min 0.14, max 0.15)","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15","0.15 (min 0.15, max 0.16)","0.15"
    "vddshv5_power","51.17 (min 50.94, max 52.13)","51.15 (min 50.97, max 51.87)","50.95 (min 50.94, max 50.96)","51.14 (min 50.98, max 51.77)","51.56 (min 51.30, max 52.51)","51.34 (min 51.15, max 51.68)"
    "vddshv6_power","30.74 (min 30.53, max 30.95)","30.75 (min 30.54, max 30.96)","30.83 (min 30.63, max 30.98)","30.70 (min 30.46, max 31.00)","30.92 (min 30.75, max 31.00)","30.75 (min 30.44, max 30.90)"
    "vdds_osc_power","1.23","1.23","1.23","1.23","1.22","1.23"
    "vdds_ddr_power","142.14 (min 141.39, max 142.43)","150.21 (min 149.09, max 151.70)","142.16 (min 141.92, max 142.38)","142.09 (min 141.53, max 142.49)","142.54 (min 142.32, max 142.89)","149.76 (min 144.75, max 158.04)"
    "vdd_mpu_power","63.26 (min 60.42, max 68.14)","104.55 (min 99.73, max 111.57)","106.26 (min 60.46, max 275.88)","64.82 (min 61.40, max 67.53)","738.09 (min 727.14, max 743.29)","462.84 (min 443.28, max 475.80)"
    "vddshv1_power","0.39 (min 0.38, max 0.40)","0.39 (min 0.38, max 0.39)","0.40 (min 0.39, max 0.41)","0.39","0.38 (min 0.38, max 0.39)","0.38 (min 0.38, max 0.39)"
    "vdds_power","2.55 (min 2.54, max 2.57)","2.56 (min 2.55, max 2.56)","2.56 (min 2.55, max 2.56)","2.56 (min 2.55, max 2.56)","2.56 (min 2.55, max 2.57)","2.56 (min 2.55, max 2.57)"
    "vdds_a3p3v_usb0_1_power","11.10 (min 11.09, max 11.10)","11.09","11.10","11.10","11.04 (min 11.04, max 11.05)","11.06"
    "vddshv2_power","9.33 (min 9.04, max 9.52)","9.10 (min 9.04, max 9.32)","9.31 (min 9.06, max 9.43)","9.38 (min 9.11, max 9.52)","9.30 (min 9.10, max 9.50)","9.28 (min 9.07, max 9.54)"
    "vdds_sram_core_bg_power","2.15 (min 2.14, max 2.16)","2.29 (min 2.27, max 2.30)","2.14 (min 2.13, max 2.16)","2.16 (min 2.15, max 2.17)","2.44 (min 2.41, max 2.46)","2.32 (min 2.30, max 2.32)"
    "vdds_sram_mpu_bb_power","2.92 (min 2.90, max 2.94)","3.13 (min 3.09, max 3.24)","2.93 (min 2.91, max 2.95)","2.94 (min 2.92, max 2.96)","11.81 (min 11.77, max 11.84)","6.44 (min 5.87, max 6.83)"
    "vdds_pll_core_lcd_power","13.15","13.15","13.15","13.15","13.16","13.16"
    "vdd_core_power","208.59 (min 208.43, max 208.94)","245.03 (min 242.19, max 249.35)","208.56 (min 208.35, max 208.70)","208.57 (min 208.43, max 208.74)","208.89 (min 208.44, max 210.18)","221.81 (min 218.49, max 224.01)"
    "vdda_adc_power","7.47 (min 7.38, max 7.53)","7.10 (min 7.05, max 7.19)","7.48 (min 7.39, max 7.51)","7.40 (min 7.29, max 7.51)","7.57 (min 7.55, max 7.62)","7.53 (min 7.51, max 7.56)"
    "vdds_pll_mpu_power","3.00 (min 2.79, max 3.30)","3.42 (min 3.12, max 3.71)","3.06 (min 2.81, max 3.29)","2.97 (min 2.80, max 3.13)","5.62","5.62"
    "total_power","586.91 (min 583.83, max 592.63)","672.87 (min 663.94, max 681.94)","629.83 (min 584.76, max 799.72)","588.31 (min 584.31, max 591.50)","1275.24 (min 1263.88, max 1281.38)","1013.77 (min 1003.00, max 1024.03)"

Table: **Power Consumption with ondemand governor**



.. csv-table::
    :header: "Power Rail","am335x-evm: idle (mw)","am335x-evm: 3D graphics (mw)","am335x-evm: video+audio (mw)","am335x-evm: network load (mw)","am335x-evm: Dhrystone (mw)","am335x-evm: memtester (mw)"

    "vdds_rtc_power","0.66","0.66","0.66","0.66","0.66","0.66"
    "vddshv4_power","0.08 (min 0.07, max 0.09)","0.09 (min 0.08, max 0.09)","0.08","0.08 (min 0.08, max 0.09)","0.08","0.08"
    "vdds_pll_ddr_power","3.92","3.92","3.92","3.92","3.93 (min 3.92, max 3.93)","3.92"
    "vdda_1p8v_usb0_1_power","32.90 (min 32.85, max 32.93)","32.93 (min 32.92, max 32.93)","32.91 (min 32.90, max 32.92)","33.26 (min 33.14, max 33.34)","33.30 (min 33.20, max 33.34)","32.88 (min 32.87, max 32.89)"
    "vddshv3_power","0.15 (min 0.14, max 0.15)","0.15","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15"
    "vddshv5_power","51.09 (min 50.99, max 51.97)","51.27 (min 51.05, max 51.88)","51.21 (min 50.98, max 52.09)","50.99 (min 50.99, max 51.00)","51.56 (min 51.30, max 52.51)","51.34 (min 51.15, max 51.68)"
    "vddshv6_power","30.72 (min 30.44, max 30.91)","30.72 (min 30.45, max 30.96)","30.79 (min 30.50, max 30.98)","30.82 (min 30.64, max 30.97)","30.92 (min 30.75, max 31.00)","30.75 (min 30.44, max 30.90)"
    "vdds_osc_power","1.23","1.23","1.23","1.23","1.22","1.23"
    "vdds_ddr_power","142.43 (min 142.21, max 142.62)","150.17 (min 149.27, max 151.37)","142.85 (min 142.66, max 142.94)","143.03 (min 142.64, max 143.45)","142.54 (min 142.32, max 142.89)","149.76 (min 144.75, max 158.04)"
    "vdd_mpu_power","135.73 (min 129.86, max 144.62)","203.02 (min 199.59, max 206.90)","135.88 (min 131.30, max 142.35)","142.04 (min 135.01, max 153.23)","738.09 (min 727.14, max 743.29)","462.84 (min 443.28, max 475.80)"
    "vddshv1_power","0.39 (min 0.38, max 0.40)","0.39","0.39 (min 0.39, max 0.40)","0.39 (min 0.39, max 0.40)","0.38 (min 0.38, max 0.39)","0.38 (min 0.38, max 0.39)"
    "vdds_power","2.56 (min 2.55, max 2.57)","2.56 (min 2.55, max 2.56)","2.56 (min 2.55, max 2.56)","2.56 (min 2.55, max 2.57)","2.56 (min 2.55, max 2.57)","2.56 (min 2.55, max 2.57)"
    "vdds_a3p3v_usb0_1_power","11.09","11.09 (min 11.08, max 11.09)","11.09","11.09 (min 11.09, max 11.10)","11.04 (min 11.04, max 11.05)","11.06"
    "vddshv2_power","9.33 (min 9.05, max 9.52)","9.32 (min 9.06, max 9.55)","9.30 (min 9.08, max 9.49)","9.37 (min 9.10, max 9.55)","9.30 (min 9.10, max 9.50)","9.28 (min 9.07, max 9.54)"
    "vdds_sram_core_bg_power","2.17 (min 2.17, max 2.18)","2.35 (min 2.34, max 2.37)","2.17 (min 2.16, max 2.18)","2.17 (min 2.16, max 2.18)","2.44 (min 2.41, max 2.46)","2.32 (min 2.30, max 2.32)"
    "vdds_sram_mpu_bb_power","4.10 (min 4.10, max 4.11)","4.33 (min 4.32, max 4.35)","4.10 (min 4.09, max 4.12)","4.09 (min 4.08, max 4.11)","11.81 (min 11.77, max 11.84)","6.44 (min 5.87, max 6.83)"
    "vdds_pll_core_lcd_power","13.15","13.15","13.15","13.15","13.16","13.16"
    "vdd_core_power","208.55 (min 208.46, max 208.68)","246.02 (min 242.06, max 249.88)","208.61 (min 208.52, max 208.73)","208.60 (min 208.55, max 208.70)","208.89 (min 208.44, max 210.18)","221.81 (min 218.49, max 224.01)"
    "vdda_adc_power","7.51 (min 7.50, max 7.55)","7.32 (min 7.26, max 7.35)","7.51 (min 7.50, max 7.52)","7.51 (min 7.51, max 7.52)","7.57 (min 7.55, max 7.62)","7.53 (min 7.51, max 7.56)"
    "vdds_pll_mpu_power","5.62","5.62","5.62","5.62","5.62","5.62"
    "total_power","663.39 (min 657.30, max 672.52)","776.30 (min 768.32, max 780.37)","664.18 (min 660.73, max 670.41)","670.75 (min 663.86, max 681.76)","1275.24 (min 1263.88, max 1281.38)","1013.77 (min 1003.00, max 1024.03)"

Table: **Power Consumption with performance governor**



.. csv-table::
    :header: "Power Rail","am335x-evm: idle (mw)","am335x-evm: 3D graphics (mw)","am335x-evm: video+audio (mw)","am335x-evm: network load (mw)","am335x-evm: Dhrystone (mw)","am335x-evm: memtester (mw)"

    "vdds_rtc_power","0.66","0.66","0.66","0.66","0.66","0.66"
    "vddshv4_power","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.09","0.08","0.09 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)"
    "vdds_pll_ddr_power","3.92","3.92","3.92","3.92","3.92","3.92 (min 3.92, max 3.93)"
    "vdda_1p8v_usb0_1_power","32.89 (min 32.87, max 32.92)","32.88 (min 32.87, max 32.90)","32.91 (min 32.89, max 32.91)","32.90 (min 32.89, max 32.91)","32.89 (min 32.88, max 32.90)","32.92"
    "vddshv3_power","0.15 (min 0.14, max 0.16)","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15 (min 0.14, max 0.15)"
    "vddshv5_power","50.96 (min 50.91, max 51.30)","50.92 (min 50.91, max 50.93)","51.13 (min 50.95, max 51.74)","50.94 (min 50.93, max 50.95)","51.19 (min 50.94, max 52.15)","51.13 (min 51.00, max 51.65)"
    "vddshv6_power","30.80 (min 30.44, max 30.99)","30.78 (min 30.54, max 30.90)","30.66 (min 30.44, max 30.91)","30.76 (min 30.50, max 31.00)","30.75 (min 30.52, max 30.98)","30.74 (min 30.46, max 30.99)"
    "vdds_osc_power","1.23","1.23","1.23","1.23","1.23","1.23"
    "vdds_ddr_power","141.88 (min 141.67, max 142.25)","149.93 (min 149.21, max 150.61)","142.31 (min 141.86, max 142.90)","142.21 (min 141.95, max 142.53)","142.77 (min 142.51, max 143.03)","147.69 (min 143.23, max 151.59)"
    "vdd_mpu_power","46.48 (min 45.04, max 47.47)","54.84 (min 52.63, max 56.63)","52.93 (min 45.23, max 79.81)","49.45 (min 45.44, max 58.61)","108.70 (min 108.63, max 108.78)","87.00 (min 80.75, max 92.06)"
    "vddshv1_power","0.39 (min 0.38, max 0.40)","0.39","0.39 (min 0.39, max 0.40)","0.39 (min 0.39, max 0.40)","0.39 (min 0.39, max 0.40)","0.39 (min 0.38, max 0.39)"
    "vdds_power","2.56 (min 2.54, max 2.56)","2.56 (min 2.55, max 2.56)","2.56 (min 2.55, max 2.57)","2.56","2.56 (min 2.55, max 2.57)","2.56 (min 2.55, max 2.56)"
    "vdds_a3p3v_usb0_1_power","11.10 (min 11.09, max 11.10)","11.10","11.10 (min 11.09, max 11.10)","11.10","11.10","11.09 (min 11.09, max 11.10)"
    "vddshv2_power","9.33 (min 9.11, max 9.52)","9.22 (min 9.04, max 9.52)","9.40 (min 9.35, max 9.55)","9.50 (min 9.36, max 9.55)","9.44 (min 9.40, max 9.48)","9.34 (min 9.19, max 9.51)"
    "vdds_sram_core_bg_power","2.13 (min 2.12, max 2.15)","2.27 (min 2.26, max 2.27)","2.15 (min 2.14, max 2.17)","2.13 (min 2.13, max 2.14)","2.14","2.17 (min 2.17, max 2.18)"
    "vdds_sram_mpu_bb_power","2.88 (min 2.86, max 2.90)","2.98 (min 2.96, max 2.99)","2.91 (min 2.89, max 2.93)","2.95 (min 2.87, max 3.24)","4.64","3.87 (min 3.80, max 3.98)"
    "vdds_pll_core_lcd_power","13.15","13.15","13.15 (min 13.15, max 13.16)","13.15","13.15","13.15 (min 13.15, max 13.16)"
    "vdd_core_power","208.04 (min 207.90, max 208.24)","244.46 (min 239.25, max 247.40)","208.59 (min 208.08, max 210.34)","207.99 (min 207.84, max 208.12)","205.68 (min 205.64, max 205.71)","213.94 (min 211.07, max 216.71)"
    "vdda_adc_power","7.44 (min 7.38, max 7.51)","7.04 (min 6.94, max 7.12)","7.42 (min 7.38, max 7.50)","7.46 (min 7.38, max 7.50)","7.56 (min 7.54, max 7.58)","7.52 (min 7.52, max 7.53)"
    "vdds_pll_mpu_power","2.03","2.03","2.03","2.03","2.03","2.03"
    "total_power","568.09 (min 566.44, max 569.05)","620.60 (min 615.56, max 624.76)","575.69 (min 567.60, max 605.08)","571.57 (min 567.83, max 580.65)","631.02 (min 630.41, max 632.19)","621.61 (min 615.02, max 631.91)"

Table: **Power Consumption with powersave governor**



.. csv-table::
    :header: "Power Rail","am335x-evm: idle (mw)","am335x-evm: 3D graphics (mw)","am335x-evm: video+audio (mw)","am335x-evm: network load (mw)","am335x-evm: Dhrystone (mw)","am335x-evm: memtester (mw)"

    "vdds_rtc_power","0.66","0.66","0.66","0.66","0.66","0.66"
    "vddshv4_power","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)"
    "vdds_pll_ddr_power","3.92","3.92","3.92","3.92 (min 3.92, max 3.93)","3.92 (min 3.92, max 3.93)","3.93 (min 3.92, max 3.93)"
    "vdda_1p8v_usb0_1_power","32.88 (min 32.87, max 32.90)","32.89 (min 32.88, max 32.90)","32.90 (min 32.89, max 32.92)","32.92 (min 32.91, max 32.95)","32.81 (min 32.80, max 32.83)","32.89 (min 32.87, max 32.91)"
    "vddshv3_power","0.15 (min 0.15, max 0.16)","0.15","0.16 (min 0.15, max 0.16)","0.15","0.15","0.15"
    "vddshv5_power","50.97 (min 50.90, max 51.43)","51.18 (min 50.94, max 52.11)","51.35 (min 50.95, max 52.16)","50.99 (min 50.97, max 51.00)","51.54 (min 51.27, max 52.49)","51.16 (min 51.14, max 51.17)"
    "vddshv6_power","30.83 (min 30.63, max 30.99)","30.67 (min 30.43, max 30.88)","30.71 (min 30.54, max 30.98)","30.79 (min 30.45, max 30.99)","30.75 (min 30.56, max 30.93)","30.77 (min 30.66, max 30.88)"
    "vdds_osc_power","1.23","1.23","1.23","1.23","1.22","1.23 (min 1.22, max 1.23)"
    "vdds_ddr_power","142.20 (min 141.97, max 142.52)","149.10 (min 148.56, max 149.86)","142.06 (min 141.84, max 142.25)","141.89 (min 141.18, max 142.14)","142.05 (min 141.91, max 142.31)","152.12 (min 144.79, max 157.41)"
    "vdd_mpu_power","49.03 (min 46.32, max 63.27)","73.57 (min 53.62, max 106.34)","51.58 (min 46.43, max 69.12)","46.77 (min 46.06, max 48.03)","738.53 (min 725.68, max 742.44)","457.22 (min 445.08, max 475.57)"
    "vddshv1_power","0.39 (min 0.39, max 0.40)","0.39","0.39 (min 0.39, max 0.40)","0.39 (min 0.39, max 0.40)","0.38 (min 0.38, max 0.39)","0.39 (min 0.38, max 0.39)"
    "vdds_power","2.55 (min 2.55, max 2.56)","2.56 (min 2.56, max 2.57)","2.56 (min 2.55, max 2.57)","2.56 (min 2.55, max 2.56)","2.56 (min 2.55, max 2.57)","2.56 (min 2.55, max 2.56)"
    "vdds_a3p3v_usb0_1_power","11.10","11.10","11.10","11.10 (min 11.09, max 11.10)","11.04","11.06 (min 11.06, max 11.07)"
    "vddshv2_power","9.33 (min 9.05, max 9.45)","9.18 (min 9.04, max 9.45)","9.25 (min 9.04, max 9.54)","9.31 (min 9.22, max 9.37)","9.31 (min 9.06, max 9.55)","9.21 (min 9.04, max 9.45)"
    "vdds_sram_core_bg_power","2.12 (min 2.11, max 2.13)","2.28 (min 2.27, max 2.30)","2.14 (min 2.13, max 2.16)","2.16 (min 2.15, max 2.17)","2.42 (min 2.40, max 2.45)","2.32 (min 2.30, max 2.33)"
    "vdds_sram_mpu_bb_power","2.90 (min 2.85, max 3.23)","3.12 (min 2.99, max 3.48)","2.90 (min 2.88, max 2.92)","2.92 (min 2.90, max 2.93)","11.79 (min 11.72, max 11.83)","6.45 (min 5.89, max 6.83)"
    "vdds_pll_core_lcd_power","13.15","13.15","13.15 (min 13.15, max 13.16)","13.16 (min 13.15, max 13.16)","13.16","13.16"
    "vdd_core_power","208.02 (min 207.81, max 208.30)","245.02 (min 239.84, max 249.43)","208.30 (min 208.08, max 208.52)","208.55 (min 208.24, max 209.13)","209.18 (min 208.42, max 211.97)","222.88 (min 218.50, max 224.19)"
    "vdda_adc_power","7.38 (min 7.24, max 7.46)","6.97 (min 6.86, max 7.10)","7.45 (min 7.41, max 7.49)","7.37 (min 7.24, max 7.47)","7.58 (min 7.55, max 7.61)","7.54 (min 7.51, max 7.57)"
    "vdds_pll_mpu_power","2.20 (min 2.03, max 3.71)","2.49 (min 2.03, max 4.33)","2.03","2.03","5.62 (min 5.61, max 5.62)","5.62"
    "total_power","571.11 (min 568.38, max 584.61)","639.74 (min 619.84, max 677.18)","573.93 (min 568.88, max 592.17)","568.95 (min 567.60, max 570.29)","1274.77 (min 1260.97, max 1279.65)","1011.39 (min 1004.95, max 1023.28)"

Table: **Power Consumption with conservative governor**














    

