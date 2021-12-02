.. http://processors.wiki.ti.com/index.php/CoreSDK_Linux_Kernel_Performance_Guide

======================================
 Linux 08.01.00 Performance Guide
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

**Bandwidth**: bw_mem_bcopy-N, where N is equal to or smaller than the cache size at
a given level measures the achievable memory bandwidth from software doing
a memcpy() type operation. Typical use is for external memory bandwidth
calculation. The bandwidth is calculated as byte read and written counts
as 1 which should be roughly half of STREAM copy result.

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am43xx-gpevm: perf","am57xx-evm: perf","am64xx-evm: perf","j7200-evm: perf","j721e-idk-gw: perf"

    "af_unix_sock_stream_latency (microsec)","44.89","34.29","38.67","40.80","19.71","17.57"
    "af_unix_socket_stream_bandwidth (MB/s)","164.78","173.34","2112.53","565.54","912.09","2622.74"
    "bw_file_rd-io-1mb (MB/s)","186.36","198.08","1633.99","1036.45","2467.73","3696.17"
    "bw_file_rd-o2c-1mb (MB/s)","145.71","164.69","1086.27","591.63","1187.45","2060.09"
    "bw_mem-bcopy-16mb (MB/s)","168.11","194.12","2093.01","888.99","1117.16","2651.20"
    "bw_mem-bcopy-1mb (MB/s)","202.41","200.28","5120.57","865.65","1140.03","4996.43"
    "bw_mem-bcopy-2mb (MB/s)","200.28","197.90","3104.52","865.68","1120.03","3243.24"
    "bw_mem-bcopy-4mb (MB/s)","197.23","196.13","2221.81","899.18","1116.07","3195.40"
    "bw_mem-bcopy-8mb (MB/s)","209.86","198.95","2114.16","906.72","1119.51","2790.86"
    "bw_mem-bzero-16mb (MB/s)","996.39","672.92","5563.28","2126.53","1140.17","10304.30"
    "bw_mem-bzero-1mb (MB/s)","594.22 (min 202.41, max 986.03)","438.55 (min 200.28, max 676.82)","5731.53 (min 5120.57, max 6342.49)","1495.72 (min 865.65, max 2125.78)","1366.99 (min 1140.03, max 1593.94)","8869.96 (min 4996.43, max 12743.49)"
    "bw_mem-bzero-2mb (MB/s)","596.83 (min 200.28, max 993.38)","436.39 (min 197.90, max 674.88)","4642.15 (min 3104.52, max 6179.78)","1495.54 (min 865.68, max 2125.40)","1149.55 (min 1120.03, max 1179.07)","7935.89 (min 3243.24, max 12628.54)"
    "bw_mem-bzero-4mb (MB/s)","599.06 (min 197.23, max 1000.88)","435.05 (min 196.13, max 673.97)","4081.57 (min 2221.81, max 5941.33)","1513.42 (min 899.18, max 2127.66)","1128.33 (min 1116.07, max 1140.58)","7883.52 (min 3195.40, max 12571.64)"
    "bw_mem-bzero-8mb (MB/s)","607.07 (min 209.86, max 1004.27)","435.98 (min 198.95, max 673.00)","3906.34 (min 2114.16, max 5698.51)","1516.77 (min 906.72, max 2126.81)","1130.94 (min 1119.51, max 1142.37)","7430.64 (min 2790.86, max 12070.41)"
    "bw_mem-cp-16mb (MB/s)","168.52","196.02","1106.19","603.27","687.94","1064.33"
    "bw_mem-cp-1mb (MB/s)","590.15 (min 192.34, max 987.95)","439.16 (min 201.15, max 677.16)","5104.85 (min 3892.46, max 6317.24)","1420.68 (min 591.63, max 2249.72)","1173.77 (min 704.60, max 1642.94)","6842.64 (min 978.79, max 12706.48)"
    "bw_mem-cp-2mb (MB/s)","587.40 (min 189.25, max 985.55)","437.04 (min 199.88, max 674.20)","3727.37 (min 1256.96, max 6197.77)","1400.45 (min 593.38, max 2207.51)","933.37 (min 688.71, max 1178.03)","6825.41 (min 1042.75, max 12608.07)"
    "bw_mem-cp-4mb (MB/s)","595.76 (min 188.75, max 1002.76)","437.05 (min 200.12, max 673.97)","3532.03 (min 1122.73, max 5941.33)","1382.04 (min 594.88, max 2169.20)","916.11 (min 690.01, max 1142.20)","6878.42 (min 1185.19, max 12571.64)"
    "bw_mem-cp-8mb (MB/s)","589.95 (min 195.27, max 984.62)","437.72 (min 201.75, max 673.68)","3402.61 (min 1106.19, max 5699.02)","1374.81 (min 599.66, max 2149.96)","914.90 (min 687.76, max 1142.04)","6723.34 (min 1053.19, max 12393.49)"
    "bw_mem-fcp-16mb (MB/s)","284.44","148.99","1199.76","858.78","1199.49","2561.64"
    "bw_mem-fcp-1mb (MB/s)","641.67 (min 297.31, max 986.03)","414.07 (min 151.31, max 676.82)","4779.45 (min 3216.40, max 6342.49)","1489.37 (min 852.95, max 2125.78)","1408.86 (min 1223.78, max 1593.94)","9004.25 (min 5265.01, max 12743.49)"
    "bw_mem-fcp-2mb (MB/s)","645.24 (min 297.09, max 993.38)","411.76 (min 148.63, max 674.88)","3754.85 (min 1329.91, max 6179.78)","1481.52 (min 837.64, max 2125.40)","1190.59 (min 1179.07, max 1202.10)","7942.64 (min 3256.74, max 12628.54)"
    "bw_mem-fcp-4mb (MB/s)","648.48 (min 296.08, max 1000.88)","411.22 (min 148.47, max 673.97)","3561.12 (min 1180.90, max 5941.33)","1484.53 (min 841.40, max 2127.66)","1169.99 (min 1140.58, max 1199.40)","7862.49 (min 3153.33, max 12571.64)"
    "bw_mem-fcp-8mb (MB/s)","651.98 (min 299.69, max 1004.27)","411.00 (min 148.99, max 673.00)","3451.94 (min 1205.36, max 5698.51)","1488.44 (min 850.07, max 2126.81)","1170.89 (min 1142.37, max 1199.40)","7384.96 (min 2699.51, max 12070.41)"
    "bw_mem-frd-16mb (MB/s)","249.61","208.75","1061.36","1510.57","5584.64","5107.74"
    "bw_mem-frd-1mb (MB/s)","283.99 (min 270.67, max 297.31)","186.04 (min 151.31, max 220.77)","3151.27 (min 3086.14, max 3216.40)","1148.63 (min 852.95, max 1444.30)","3898.96 (min 1223.78, max 6574.14)","5604.28 (min 5265.01, max 5943.54)"
    "bw_mem-frd-2mb (MB/s)","274.84 (min 252.59, max 297.09)","176.28 (min 148.63, max 203.92)","1865.11 (min 1329.91, max 2400.30)","1149.42 (min 837.64, max 1461.19)","3422.42 (min 1202.10, max 5642.74)","4601.80 (min 3256.74, max 5946.85)"
    "bw_mem-frd-4mb (MB/s)","272.81 (min 249.53, max 296.08)","177.79 (min 148.47, max 207.10)","1195.92 (min 1180.90, max 1210.93)","1175.04 (min 841.40, max 1508.67)","3392.02 (min 1199.40, max 5584.64)","4544.58 (min 3153.33, max 5935.82)"
    "bw_mem-frd-8mb (MB/s)","274.56 (min 249.42, max 299.69)","179.50 (min 148.99, max 210.00)","1138.80 (min 1072.24, max 1205.36)","1179.47 (min 850.07, max 1508.86)","3393.97 (min 1199.40, max 5588.54)","4178.61 (min 2699.51, max 5657.71)"
    "bw_mem-fwr-16mb (MB/s)","996.08","673.23","5577.83","2136.18","1141.15","10299.32"
    "bw_mem-fwr-1mb (MB/s)","629.31 (min 270.67, max 987.95)","448.97 (min 220.77, max 677.16)","4701.69 (min 3086.14, max 6317.24)","1847.01 (min 1444.30, max 2249.72)","4108.54 (min 1642.94, max 6574.14)","9325.01 (min 5943.54, max 12706.48)"
    "bw_mem-fwr-2mb (MB/s)","619.07 (min 252.59, max 985.55)","439.06 (min 203.92, max 674.20)","4299.04 (min 2400.30, max 6197.77)","1834.35 (min 1461.19, max 2207.51)","3410.39 (min 1178.03, max 5642.74)","9277.46 (min 5946.85, max 12608.07)"
    "bw_mem-fwr-4mb (MB/s)","626.15 (min 249.53, max 1002.76)","440.54 (min 207.10, max 673.97)","3576.13 (min 1210.93, max 5941.33)","1838.94 (min 1508.67, max 2169.20)","3363.42 (min 1142.20, max 5584.64)","9253.73 (min 5935.82, max 12571.64)"
    "bw_mem-fwr-8mb (MB/s)","617.02 (min 249.42, max 984.62)","441.84 (min 210.00, max 673.68)","3385.63 (min 1072.24, max 5699.02)","1829.41 (min 1508.86, max 2149.96)","3365.29 (min 1142.04, max 5588.54)","9025.60 (min 5657.71, max 12393.49)"
    "bw_mem-rd-16mb (MB/s)","252.53","427.98","3158.73","1510.86","5084.21","5111.82"
    "bw_mem-rd-1mb (MB/s)","629.55 (min 272.26, max 986.84)","339.73 (min 274.54, max 404.91)","12176.06 (min 10892.64, max 13459.48)","1207.49 (min 943.04, max 1471.94)","3639.50 (min 976.09, max 6302.90)","11161.95 (min 10482.56, max 11841.33)"
    "bw_mem-rd-2mb (MB/s)","619.23 (min 252.27, max 986.19)","341.71 (min 271.00, max 412.41)","8941.54 (min 8912.82, max 8970.25)","1255.07 (min 1007.22, max 1502.91)","2978.58 (min 760.55, max 5196.60)","4041.09 (min 1420.45, max 6661.73)"
    "bw_mem-rd-4mb (MB/s)","617.21 (min 252.46, max 981.96)","345.79 (min 271.46, max 420.12)","2596.15 (min 1724.58, max 3467.71)","1298.34 (min 1095.74, max 1500.94)","2919.23 (min 752.16, max 5086.29)","3740.47 (min 1364.72, max 6116.21)"
    "bw_mem-rd-8mb (MB/s)","627.25 (min 251.87, max 1002.63)","348.06 (min 271.90, max 424.22)","2295.70 (min 1394.46, max 3196.93)","1335.73 (min 1154.57, max 1516.88)","2911.06 (min 742.74, max 5079.37)","3515.44 (min 1315.57, max 5715.31)"
    "bw_mem-rdwr-16mb (MB/s)","203.53","295.96","1257.37","1091.63","745.05","1212.49"
    "bw_mem-rdwr-1mb (MB/s)","200.37 (min 192.34, max 208.40)","249.81 (min 201.15, max 298.46)","5724.11 (min 3892.46, max 7555.76)","772.19 (min 591.63, max 952.74)","841.38 (min 704.60, max 978.15)","3734.39 (min 978.79, max 6489.99)"
    "bw_mem-rdwr-2mb (MB/s)","196.95 (min 189.25, max 204.65)","246.55 (min 199.88, max 293.21)","2806.72 (min 1256.96, max 4356.47)","777.69 (min 593.38, max 962.00)","725.89 (min 688.71, max 763.07)","1155.39 (min 1042.75, max 1268.03)"
    "bw_mem-rdwr-4mb (MB/s)","196.42 (min 188.75, max 204.09)","248.01 (min 200.12, max 295.90)","1287.65 (min 1122.73, max 1452.56)","793.35 (min 594.88, max 991.82)","719.19 (min 690.01, max 748.36)","1228.33 (min 1185.19, max 1271.46)"
    "bw_mem-rdwr-8mb (MB/s)","199.56 (min 195.27, max 203.85)","249.04 (min 201.75, max 296.32)","1194.07 (min 1106.19, max 1281.95)","826.91 (min 599.66, max 1054.16)","716.56 (min 687.76, max 745.36)","1180.51 (min 1053.19, max 1307.83)"
    "bw_mem-wr-16mb (MB/s)","996.39","271.73","1365.42","1166.27","744.71","1842.68"
    "bw_mem-wr-1mb (MB/s)","597.62 (min 208.40, max 986.84)","286.50 (min 274.54, max 298.46)","10507.62 (min 7555.76, max 13459.48)","947.89 (min 943.04, max 952.74)","977.12 (min 976.09, max 978.15)","9165.66 (min 6489.99, max 11841.33)"
    "bw_mem-wr-2mb (MB/s)","595.42 (min 204.65, max 986.19)","282.11 (min 271.00, max 293.21)","6663.36 (min 4356.47, max 8970.25)","984.61 (min 962.00, max 1007.22)","761.81 (min 760.55, max 763.07)","1344.24 (min 1268.03, max 1420.45)"
    "bw_mem-wr-4mb (MB/s)","593.03 (min 204.09, max 981.96)","283.68 (min 271.46, max 295.90)","1588.57 (min 1452.56, max 1724.58)","1043.78 (min 991.82, max 1095.74)","750.26 (min 748.36, max 752.16)","1318.09 (min 1271.46, max 1364.72)"
    "bw_mem-wr-8mb (MB/s)","603.24 (min 203.85, max 1002.63)","284.11 (min 271.90, max 296.32)","1338.21 (min 1281.95, max 1394.46)","1104.37 (min 1054.16, max 1154.57)","744.05 (min 742.74, max 745.36)","1311.70 (min 1307.83, max 1315.57)"
    "bw_mmap_rd-mo-1mb (MB/s)","263.68","188.50","4119.37","1474.93","6347.95","8983.72"
    "bw_mmap_rd-o2c-1mb (MB/s)","167.22","145.60","1245.57","659.20","1563.11","2064.34"
    "bw_pipe (MB/s)","307.12","370.05","604.36","1437.90","3242.13","4229.99"
    "bw_unix (MB/s)","164.78","173.34","2112.53","565.54","912.09","2622.74"
    "lat_connect (us)","83.97","71.35","49.49","63.33","31.87","27.55"
    "lat_ctx-2-128k (us)","25.26","2.00","9.28","29.03","10.24","4.25"
    "lat_ctx-2-256k (us)","4.00","13.71","2.73","79.76","22.66","4.45"
    "lat_ctx-4-128k (us)","37.79","0.00","10.67","50.06","21.20","5.44"
    "lat_ctx-4-256k (us)","0.00","0.00","0.00","61.55","27.20","6.16"
    "lat_fs-0k (num_files)","214.00","242.00","721.00","219.00","528.00","538.00"
    "lat_fs-10k (num_files)","66.00","79.00","321.00","78.00","75.00","202.00"
    "lat_fs-1k (num_files)","97.00","122.00","412.00","83.00","63.00","251.00"
    "lat_fs-4k (num_files)","109.00","132.00","455.00","80.00","75.00","214.00"
    "lat_mem_rd-stride128-sz1000k (ns)","223.73","97.16","12.83","41.80","18.59","8.70"
    "lat_mem_rd-stride128-sz125k (ns)","11.61","16.04","12.69","7.57","5.15","5.15"
    "lat_mem_rd-stride128-sz250k (ns)","59.18","27.27","12.83","8.15","5.15","5.15"
    "lat_mem_rd-stride128-sz31k (ns)","3.04","9.24","7.72","3.03","2.00","2.00"
    "lat_mem_rd-stride128-sz50 (ns)","3.00","4.00","2.67","3.01","2.00","2.00"
    "lat_mem_rd-stride128-sz500k (ns)","182.26","89.77","12.83","36.61","5.37","5.15"
    "lat_mem_rd-stride128-sz62k (ns)","8.89","16.92","12.07","6.42","5.15","5.15"
    "lat_mmap-1m (us)","74.00","112.00","50.00","22.00","8.62","8.71"
    "lat_ops-double-add (ns)","2.37","1.01","0.73","0.73","0.32","0.32"
    "lat_ops-double-mul (ns)","11.07","7.02","3.34","4.01","2.00","2.00"
    "lat_ops-float-add (ns)","2.28","0.91","0.73","0.73","0.32","0.32"
    "lat_ops-float-mul (ns)","10.02","6.02","3.34","4.01","2.00","2.00"
    "lat_ops-int-add (ns)","1.00","1.03","0.67","1.00","0.50","0.50"
    "lat_ops-int-bit (ns)","0.67","0.76","0.45","0.67","0.33","0.33"
    "lat_ops-int-div (ns)","72.91","95.90","60.20","6.02","4.00","4.00"
    "lat_ops-int-mod (ns)","24.53","24.09","8.91","6.35","4.67","4.67"
    "lat_ops-int-mul (ns)","6.06","4.04","2.09","3.04","1.52","1.52"
    "lat_ops-int64-add (ns)","1.21","1.16","0.83","1.00","0.50","0.50"
    "lat_ops-int64-bit (ns)","1.06","1.01","0.67","0.67","0.33","0.33"
    "lat_ops-int64-div (ns)","191.60","186.09","108.61","9.53","3.00","3.00"
    "lat_ops-int64-mod (ns)","52.17","46.87","22.47","7.35","5.67","5.67"
    "lat_pagefault (us)","1.81","1.66","1.08","2.62","1.27","1.15"
    "lat_pipe (us)","33.97","24.85","30.64","25.23","11.33","11.17"
    "lat_proc-exec (us)","1888.00","1682.00","935.83","2075.33","1433.50","734.67"
    "lat_proc-fork (us)","1529.50","1353.25","852.08","1701.25","1311.75","652.63"
    "lat_proc-proccall (us)","0.02","0.01","0.01","0.01","0.00","0.00"
    "lat_select (us)","39.88","32.09","23.54","46.27","9.49","9.57"
    "lat_sem (us)","4.51","5.91","3.93","2.75","1.36","1.49"
    "lat_sig-catch (us)","5.88","4.60","2.97","6.74","2.31","2.27"
    "lat_sig-install (us)","1.41","0.90","0.61","0.66","0.42","0.42"
    "lat_sig-prot (us)","0.30","","0.49","0.68","0.43","0.41"
    "lat_syscall-fstat (us)","2.01","1.59","0.91","1.59","0.60","0.59"
    "lat_syscall-null (us)","0.53","0.38","0.27","0.40","0.29","0.27"
    "lat_syscall-open (us)","271.58","286.81","178.50","282.85","199.61","130.56"
    "lat_syscall-read (us)","0.90","0.68","0.35","0.78","0.35","0.35"
    "lat_syscall-stat (us)","5.29","4.24","2.99","4.36","1.35","1.33"
    "lat_syscall-write (us)","0.70","0.55","0.33","0.64","0.33","0.33"
    "lat_tcp (us)","1.11","0.80","0.54","0.84","0.58","0.56"
    "lat_unix (us)","44.89","34.29","38.67","40.80","19.71","17.57"
    "latency_for_0.50_mb_block_size (nanosec)","182.26","89.77","12.83","36.61","5.37","5.15"
    "latency_for_1.00_mb_block_size (nanosec)","111.87 (min 0.00, max 223.73)","48.58 (min 0.00, max 97.16)","6.42 (min 0.00, max 12.83)","20.90 (min 0.00, max 41.80)","9.29 (min 0.00, max 18.59)","4.35 (min 0.00, max 8.70)"
    "pipe_bandwidth (MBs)","307.12","370.05","604.36","1437.90","3242.13","4229.99"
    "pipe_latency (microsec)","33.97","24.85","30.64","25.23","11.33","11.17"
    "procedure_call (microsec)","0.02","0.01","0.01","0.01","0.00","0.00"
    "select_on_200_tcp_fds (microsec)","39.88","32.09","23.54","46.27","9.49","9.57"
    "semaphore_latency (microsec)","4.51","5.91","3.93","2.75","1.36","1.49"
    "signal_handler_latency (microsec)","1.41","0.90","0.61","0.66","0.42","0.42"
    "signal_handler_overhead (microsec)","5.88","4.60","2.97","6.74","2.31","2.27"
    "tcp_ip_connection_cost_to_localhost (microsec)","83.97","71.35","49.49","63.33","31.87","27.55"
    "tcp_latency_using_localhost (microsec)","1.11","0.80","0.54","0.84","0.58","0.56"

Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am43xx-gpevm: perf","am57xx-evm: perf","am64xx-evm: perf","j7200-evm: perf","j721e-idk-gw: perf"

    "cpu_clock (MHz)","1000.00","1000.00","1500.00","1000.00","2000.00","2000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.00","2.47","3.45","3.00","5.70","5.70"
    "dhrystone_per_second (DhrystoneP)","3508772.00","4347826.00","9090909.00","5263158.00","20000000.00","20000000.00"

Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am43xx-gpevm: perf","am57xx-evm: perf","am64xx-evm: perf","j7200-evm: perf","j721e-idk-gw: perf"

    "whetstone (MIPS)","833.30","3333.30","5000.00","5000.00","10000.00","10000.00"

Table:  **Whetstone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am43xx-gpevm: perf","am57xx-evm: perf","am64xx-evm: perf","j7200-evm: perf","j721e-idk-gw: perf"

    "linpack (Kflops)","52692.00","180740.00","965640.00","422174.00","2634945.00","2638996.00"

Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am43xx-gpevm: perf","am57xx-evm: perf","am64xx-evm: perf","j7200-evm: perf","j721e-idk-gw: perf"

    "assignment (Iterations)","7.56","7.68","16.71","9.76","29.68","29.68"
    "fourier (Iterations)","2864.50","13316.00","26354.00","16339.00","59191.00","54408.00"
    "fp_emulation (Iterations)","79.72","84.90","169.07","76.57","250.04","250.11"
    "huffman (Iterations)","714.61","854.70","1409.30","838.76","2431.70","2426.10"
    "idea (Iterations)","1286.20","1373.90","3650.10","2454.30","7997.20","7997.20"
    "lu_decomposition (Iterations)","75.41","330.06","830.88","403.49","1430.00","1430.40"
    "neural_net (Iterations)","2.15","9.19","25.10","5.61","27.11","27.34"
    "numeric_sort (Iterations)","461.07","425.86","609.78","360.92","879.25","879.27"
    "string_sort (Iterations)","60.94","52.72","118.08","118.41","431.92","431.08"

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
    :header: "Benchmarks","am335x-evm: perf","am43xx-gpevm: perf","am57xx-evm: perf","am64xx-evm: perf","j7200-evm: perf","j721e-idk-gw: perf"

    "add (MB/s)","367.70","385.40","3883.60","1897.10","3862.80","5610.90"
    "copy (MB/s)","415.40","399.70","4218.00","1967.40","3081.40","5927.30"
    "scale (MB/s)","589.60","654.40","4796.70","2454.20","3108.20","5622.50"
    "triad (MB/s)","428.90","586.20","3841.80","1930.10","3868.30","5530.20"

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

    "cjpeg-rose7-preset (workloads/)","29.76","82.64","83.33"
    "core (workloads/)","0.21","0.78","0.78"
    "coremark-pro ()","602.65","2282.94","2571.75"
    "linear_alg-mid-100x100-sp (workloads/)","10.51","82.51","82.64"
    "loops-all-mid-10k-sp (workloads/)","0.49","2.23","2.50"
    "nnet_test (workloads/)","0.78","3.67","3.88"
    "parser-125k (workloads/)","6.29","11.49","12.20"
    "radix2-big-64k (workloads/)","19.85","126.18","266.60"
    "sha-test (workloads/)","57.80","158.73","156.25"
    "zip-test (workloads/)","16.39","47.62","52.63"

Table:  **CoreMarkPro**

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf","j7200-evm: perf","j721e-idk-gw: perf"

    "cjpeg-rose7-preset (workloads/)","58.82","158.73","166.67"
    "core (workloads/)","0.42","1.55","1.56"
    "coremark-pro ()","1081.76","3224.25","4518.20"
    "linear_alg-mid-100x100-sp (workloads/)","20.92","165.02","165.02"
    "loops-all-mid-10k-sp (workloads/)","0.90","3.19","3.71"
    "nnet_test (workloads/)","1.54","7.32","7.34"
    "parser-125k (workloads/)","7.30","8.23","23.26"
    "radix2-big-64k (workloads/)","31.18","56.86","261.64"
    "sha-test (workloads/)","116.28","312.50","312.50"
    "zip-test (workloads/)","30.30","76.92","100.00"

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

    "4m-check (workloads/)","344.40","761.50","1079.45"
    "4m-check-reassembly (workloads/)","83.82","123.15","243.90"
    "4m-check-reassembly-tcp (workloads/)","45.37","89.61","124.38"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","16.99","33.71","46.62"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","0.78","2.57","2.78"
    "4m-cmykw2 (workloads/)","91.37","308.17","320.51"
    "4m-cmykw2-rotatew2 (workloads/)","22.63","53.10","65.79"
    "4m-reassembly (workloads/)","83.26","125.95","255.10"
    "4m-rotatew2 (workloads/)","27.29","62.89","75.64"
    "4m-tcp-mixed (workloads/)","93.57","262.30","262.30"
    "4m-x264w2 (workloads/)","0.79","2.62","2.82"
    "empty-wld (workloads/)","1.00","",""
    "idct-4m (workloads/)","13.72","34.81","35.12"
    "idct-4mw1 (workloads/)","13.78","34.79","35.15"
    "ippktcheck-4m (workloads/)","343.83","773.52","1086.48"
    "ippktcheck-4mw1 (workloads/)","344.69","762.20","1074.81"
    "ipres-4m (workloads/)","72.99","146.48","214.59"
    "ipres-4mw1 (workloads/)","74.15","146.63","213.37"
    "md5-4m (workloads/)","19.46","35.00","52.49"
    "md5-4mw1 (workloads/)","19.77","34.73","53.48"
    "rgbcmyk-4m (workloads/)","45.90","163.27","164.20"
    "rgbcmyk-4mw1 (workloads/)","45.74","163.13","164.34"
    "rotate-4ms1 (workloads/)","19.55","52.30","57.21"
    "rotate-4ms1w1 (workloads/)","19.52","52.25","57.27"
    "rotate-4ms64 (workloads/)","19.62","52.74","57.67"
    "rotate-4ms64w1 (workloads/)","19.69","52.69","57.67"
    "x264-4mq (workloads/)","0.41","1.40","1.45"
    "x264-4mqw1 (workloads/)","0.41","1.40","1.45"

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
    :header: "Boot Configuration","am43xx-gpevm: boot time (sec)","am57xx-evm: boot time (sec)","am64xx-evm: boot time (sec)","j7200-evm: boot time (sec)","j721e-idk-gw: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","51.16 (min 49.89, max 54.92)","35.10 (min 31.18, max 36.48)","29.75 (min 28.28, max 32.35)","18.21 (min 17.50, max 19.06)","25.74 (min 25.39, max 26.00)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","10.90 (min 10.90, max 10.91)","4.50 (min 4.42, max 4.62)","3.80 (min 3.77, max 3.82)","7.03 (min 6.99, max 7.04)"

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
    :header: "Sampling Rate (Hz)","am335x-evm: Throughput (bits/sec)","am335x-evm: CPU Load (%)","am43xx-gpevm: Throughput (bits/sec)","am43xx-gpevm: CPU Load (%)","am57xx-evm: Throughput (bits/sec)","am57xx-evm: CPU Load (%)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "8000","256000.00","1.48","255998.00","0.64","255844.00","0.09","",""
    "11025","352799.00","4.26","352798.00","0.77","352588.00","0.09","352800.00","0.15"
    "16000","511998.00","1.12","511997.00","0.17","511687.00","0.18","512000.00","0.12"
    "22050","705597.00","8.33","705595.00","1.59","705176.00","0.19","705600.00","0.13"
    "24000","705597.00","8.13","705595.00","1.51","705176.00","0.21","705600.00","0.13"
    "32000","1023997.00","47.16","1023993.00","8.59","1023375.00","0.26","1023999.00","33.42"
    "44100","1411191.00","41.94","1411190.00","3.09","1410351.00","0.30","1411199.00","0.50"
    "48000","1535989.00","22.26","1535989.00","0.19","1535062.00","0.39","1535999.00","0.24"
    "88200","2822368.00","28.79","2822375.00","5.91","2820698.00","0.65","2822395.00","0.94"
    "96000","2961730.00","25.46","3071973.00","0.08","3070123.00","0.59","3071994.00","0.41"

Table:  **Audio Capture**

|

.. csv-table::
    :header: "Sampling Rate (Hz)","am335x-evm: Throughput (bits/sec)","am335x-evm: CPU Load (%)","am43xx-gpevm: Throughput (bits/sec)","am43xx-gpevm: CPU Load (%)","am57xx-evm: Throughput (bits/sec)","am57xx-evm: CPU Load (%)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "8000","256102.00","1.36","256102.00","0.94","255938.00","0.07","",""
    "11025","352941.00","4.05","352941.00","0.72","352717.00","0.10","352945.00","0.15"
    "16000","512204.00","1.19","512205.00","0.18","511875.00","0.10","512211.00","0.12"
    "22050","705880.00","7.96","705882.00","1.53","705434.00","0.19","705891.00","0.13"
    "24000","705880.00","7.88","705882.00","1.23","705434.00","0.12","705891.00","0.14"
    "32000","1024407.00","63.12","1024409.00","0.12","1023750.00","0.20","1024422.00","0.16"
    "44100","1411757.00","43.10","1411763.00","2.95","1410868.00","0.28","1411781.00","0.19"
    "48000","1536606.00","1.50","1536613.00","0.17","1535625.00","0.45","1536632.00","0.25"
    "88200","2823499.00","27.90","2823522.00","5.65","2821735.00","0.51","2823560.00","0.32"
    "96000","3073193.00","51.74","3073220.00","0.34","3071248.00","0.39","3073262.00","0.41"

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

    " GFXBench 3.x gl_trex_off","1953.13","34.88"
    " GFXBench 5.x gl_5_high_off","178.15","2.77"

Table:  **GFXBench**

Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","j721e-idk-gw: Score"

    "Glmark2-Wayland","1144.00"

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
    :header: "Command Used","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1592.44","58.43","1854.65","64.56"

Table: **CPSW TCP Bidirectional Throughput**

|

.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","7.48","86.32","18.00","14.75","50.77","18.00","32.34","88.89"
    "128","82.00","33.82","85.90","82.00","67.36","50.09","82.00","119.23","73.80"
    "256","210.00","84.12","85.10","210.00","267.39","70.77","210.00","181.52","50.03"
    "512","466.00","392.68","50.13","466.00","857.22","82.92"
    "1024","978.00","377.79","84.10","978.00","567.68","35.91","978.00","936.70","32.07"
    "1518","1472.00","569.36","84.54","1472.00","952.26","46.25","1472.00","957.07","34.40"

Table: **CPSW UDP Egress Throughput**

|

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","5.44","24.23","18.00","5.36","12.24"
    "128","82.00","6.63","4.81","82.00","11.02","10.69"
    "256","210.00","16.80","4.76","210.00","35.45","12.44","210.00","23.18","4.08"
    "1024","978.00","81.37","18.16","978.00","127.53","11.21"
    "1518","1472.00","122.46","18.25","1472.00","2.36","0.25","1472.00","949.86","50.72"

Table: **CPSW UDP Ingress Throughput (0% loss)**

|

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","am64xx-evm: Packet Loss %","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j7200-evm: Packet Loss %","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: Packet Loss %"

    "64","18.00","23.75","67.82","2.84","18.00","56.83","74.48","16.82"
    "128","82.00","68.64","58.39","72.41","82.00","133.89","50.68","7.61"
    "256","210.00","161.46","55.91","73.82","210.00","211.85","50.18","45.81","210.00","655.15","81.18","11.80"
    "1024","978.00","647.70","54.14","30.84","978.00","685.10","61.54","0.01"
    "1518","1472.00","860.42","69.12","10.09","1472.00","545.15","36.77","0.01","1472.00","949.86","50.72","0.00"

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

    "netperf -H 192.168.1.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.1.1 -j -c -C -l 60 -t TCP_MAERTS","1858.54","70.13","1801.87","53.84"

Table: **CPSW9g Virtual Ethernet Driver - TCP Bidirectional Throughput**

|

.. rubric::  UDP Throughput 
   :name: CPSW9g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","22.63","64.11","18.00","33.75","84.91"
    "128","82.00","141.07","84.84","82.00","167.99","89.87"
    "256","210.00","333.94","78.62","210.00","235.09","56.54"
    "1024","978.00","933.27","57.70","978.00","917.51","50.54"
    "1518","1472.00","943.06","44.87","1472.00","956.93","37.78"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Egress Throughput**

|

.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","2.92","8.98","18.00","1.67","4.11"
    "128","82.00","8.13","4.54","82.00","7.54","5.74"
    "256","210.00","17.30","5.03","210.00","16.80","4.98"
    "1024","978.00","89.97","8.77"
    "1518","1472.00","194.29","13.72","1472.00","956.97","49.88"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Ingress Throughput (0% loss)**

|

.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j7200-evm: Packet Loss %","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: Packet Loss %"

    "64","18.00","47.10","73.80","27.58","18.00","53.08","72.82","20.74"
    "128","82.00","209.81","77.14","22.08","82.00","241.87","75.50","24.86"
    "256","210.00","554.44","79.05","25.01","210.00","664.90","80.42","6.32"
    "1024","978.00","356.83","50.90","61.91"
    "1518","1472.00","956.88","64.02","0.02","1472.00","956.97","49.88","0.00"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Ingress Throughput (possible loss)**

|

CPSW Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput 
   :name: tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","am335x-evm: THROUGHPUT (Mbits/sec)","am335x-evm: CPU Load % (LOCAL_CPU_UTIL)","am43xx-gpevm: THROUGHPUT (Mbits/sec)","am43xx-gpevm: CPU Load % (LOCAL_CPU_UTIL)","am57xx-evm: THROUGHPUT (Mbits/sec)","am57xx-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","397.96","100.00","334.71","100.00","908.56","57.51"

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

    "1m","383.00","13.14","398.00","7.75"
    "4m","382.00","12.19","398.00","7.54"
    "4k","82.70","51.53","110.00","47.91"
    "256k","382.00","15.12","398.00","9.58"


- File size used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x1
- SSD being used: Lite-On Technology Corporation M8Pe Series NVMe SSD [14a4:22f1] (rev 01)

J721E-IDK-GW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","717.00","10.90","1527.00","4.10"
    "4m","716.00","10.63","1529.00","3.17"
    "4k","189.00","47.91","167.00","36.74"
    "256k","717.00","10.65","1526.00","8.31"

- File size used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY

J7200-EVM
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","795.00","16.81","1523.00","5.47"
    "4m","794.00","16.49","1523.00","4.84"
    "4k","157.00","49.45","150.00","37.89"
    "256k","800.00","20.48","1519.00","10.43"

- File size used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY

NAND Driver
-------------------------

AM335X-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write UBIFS Throughput (Mbytes/sec)","am335x-evm: Write UBIFS CPU Load (%)","am335x-evm: Read UBIFS Throughput (Mbytes/sec)","am335x-evm: Read UBIFS CPU Load (%)"

    "102400","3.80 (min 3.74, max 3.96)","62.89 (min 61.90, max 63.56)","5.36","38.53"
    "262144","3.70 (min 3.66, max 3.79)","63.19 (min 62.78, max 63.46)","5.34","33.91"
    "524288","3.76 (min 3.72, max 3.77)","63.26 (min 62.81, max 63.95)","5.39","36.97"
    "1048576","3.75 (min 3.71, max 3.77)","63.59 (min 63.02, max 64.30)","5.38","37.09"
    "5242880","3.63 (min 3.20, max 3.78)","89.84 (min 63.81, max 100.00)","5.31","36.50"

AM43XX-GPEVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am43xx-gpevm: Write UBIFS Throughput (Mbytes/sec)","am43xx-gpevm: Write UBIFS CPU Load (%)","am43xx-gpevm: Read UBIFS Throughput (Mbytes/sec)","am43xx-gpevm: Read UBIFS CPU Load (%)"

    "102400","6.43 (min 6.25, max 6.84)","67.93 (min 66.00, max 69.27)","10.23","38.62"
    "262144","6.31 (min 6.25, max 6.35)","68.56 (min 67.76, max 69.10)","10.23","38.11"
    "524288","6.33 (min 6.27, max 6.37)","68.76 (min 68.06, max 69.27)","10.26","39.68"
    "1048576","6.33 (min 6.27, max 6.37)","68.64 (min 67.80, max 69.29)","10.26","39.52"
    "5242880","6.31 (min 6.27, max 6.37)","68.88 (min 67.86, max 69.60)","10.16","40.20"

OSPI Flash Driver
-------------------------

AM64XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

UBIFS
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write UBIFS Throughput (Mbytes/sec)","am64xx-evm: Write UBIFS CPU Load (%)","am64xx-evm: Read UBIFS Throughput (Mbytes/sec)","am64xx-evm: Read UBIFS CPU Load (%)"

    "102400","0.17 (min 0.12, max 0.29)","44.84 (min 43.21, max 48.48)","63.52","33.33"
    "262144","0.13 (min 0.10, max 0.18)","45.50 (min 43.80, max 46.81)","64.62","33.33"
    "524288","0.13 (min 0.10, max 0.18)","45.40 (min 44.10, max 46.52)","64.66","57.14"
    "1048576","0.13 (min 0.10, max 0.18)","45.92 (min 44.00, max 46.74)","64.57","20.00"

RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","am64xx-evm: Raw Read Throughput (Mbytes/sec)"

    "50","178.57"

J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^

UBIFS
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write UBIFS Throughput (Mbytes/sec)","j721e-idk-gw: Write UBIFS CPU Load (%)","j721e-idk-gw: Read UBIFS Throughput (Mbytes/sec)","j721e-idk-gw: Read UBIFS CPU Load (%)"

    "102400","0.61 (min 0.48, max 1.09)","22.32 (min 22.01, max 22.68)","33.57","8.33"
    "262144","0.47 (min 0.35, max 0.52)","22.26 (min 21.27, max 23.66)","33.53","15.38"
    "524288","0.47 (min 0.35, max 0.52)","21.88 (min 20.91, max 23.39)","33.55","8.33"
    "1048576","0.46 (min 0.35, max 0.52)","20.23 (min 18.77, max 22.22)","33.51","8.33"

RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","j721e-idk-gw: Raw Read Throughput (Mbytes/sec)"

    "50","38.46"

J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

UBIFS
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write UBIFS Throughput (Mbytes/sec)","j7200-evm: Write UBIFS CPU Load (%)","j7200-evm: Read UBIFS Throughput (Mbytes/sec)","j7200-evm: Read UBIFS CPU Load (%)"

    "102400","0.18 (min 0.13, max 0.30)","40.72 (min 39.32, max 42.41)","87.62","40.00"
    "262144","0.16 (min 0.11, max 0.19)","40.47 (min 39.95, max 40.90)","86.58","25.00"
    "524288","0.16 (min 0.11, max 0.19)","40.68 (min 38.85, max 42.13)","83.72","20.00"
    "1048576","0.16 (min 0.11, max 0.19)","39.75 (min 38.52, max 40.69)","83.15","25.00"

RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","j7200-evm: Raw Read Throughput (Mbytes/sec)"

    "50","208.33"

QSPI Flash Driver
-------------------------

UBoot QSPI/OSPI Driver
-------------------------

J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","1543.91","37577.98"
    "800000","1546.54","39009.52"
    "1000000","1547.12","39766.99"
    "2000000","1547.63","40206.13"

J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","393.81","195047.62"
    "800000","395.06","248242.42"
    "1000000","397.36","282482.76"
    "2000000","399.25","300623.85"

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
    "800000","98698.80","431157.89"
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

AM64XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","59.50","3.07","281.00","2.06"
    "4m","59.60","2.37","296.00","0.47"
    "4k","46.40","45.10","54.80","47.75"
    "256k","59.90","4.39","173.00","5.91"

|

UBoot EMMC Driver
-------------------------
|

J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "2000000","58306.05","297890.91"
    "4000000","58514.29","319687.80"

|

J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "2000000","59795.62","173375.66"
    "4000000","60625.35","176646.90"

|

SATA Driver
-------------------------

.. rubric::  AM57XX-EVM
   :name: am57xx-evm-sata

|

.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)"

    "102400","122.70 (min 88.13, max 132.09)","10.61 (min 6.88, max 24.25)","133.60","10.89"
    "262144","126.49 (min 115.56, max 130.49)","11.69 (min 6.41, max 32.04)","133.74","10.20"
    "524288","127.38 (min 117.88, max 130.15)","11.72 (min 6.29, max 31.87)","133.85","9.93"
    "1048576","127.68 (min 117.65, max 130.74)","11.68 (min 6.27, max 32.04)","134.17","9.81"
    "5242880","127.10 (min 114.95, max 130.70)","12.09 (min 6.36, max 31.90)","134.03","10.38"

|

.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "102400","127.97 (min 126.88, max 129.16)","11.86 (min 7.58, max 27.31)","133.63","10.54"
    "262144","129.05 (min 126.15, max 130.19)","11.40 (min 7.03, max 26.86)","132.79","10.43"
    "524288","128.25 (min 127.43, max 128.86)","11.60 (min 6.80, max 28.64)","132.91","9.94"
    "1048576","128.08 (min 125.27, max 128.97)","11.60 (min 6.90, max 28.14)","132.64","10.13"
    "5242880","128.64 (min 127.13, max 129.39)","10.61 (min 6.82, max 23.76)","132.69","9.63"

|

-  File size used is : 1G
-  SATA II Hard disk used is: Seagate ST3500514NS 500G

mSATA Driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  AM57XX-EVM
   :name: am57xx-evm-msata

|

.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write VFAT Throughput (Mbytes/sec)","am57xx-evm: Write VFAT CPU Load (%)","am57xx-evm: Read VFAT Throughput (Mbytes/sec)","am57xx-evm: Read VFAT CPU Load (%)"

    "102400","61.92 (min 51.68, max 64.64)","10.64 (min 7.32, max 20.59)","221.54","20.00"
    "262144","62.88 (min 52.43, max 65.84)","10.29 (min 7.34, max 20.90)","228.48","19.95"
    "524288","62.62 (min 52.65, max 65.45)","10.42 (min 7.31, max 21.21)","241.66","20.41"
    "1048576","62.62 (min 52.36, max 66.21)","10.52 (min 7.44, max 21.15)","246.64","20.12"
    "5242880","62.18 (min 51.89, max 65.12)","10.29 (min 7.40, max 21.12)","243.71","20.45"

|

.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)"

    "102400","64.34 (min 63.16, max 64.76)","4.05 (min 2.58, max 8.56)","226.22","17.86"
    "262144","65.35 (min 64.31, max 67.17)","4.70 (min 2.95, max 11.02)","234.75","18.54"
    "524288","69.21 (min 65.62, max 72.06)","4.97 (min 3.05, max 11.86)","250.13","19.63"
    "1048576","66.11 (min 64.40, max 71.50)","4.81 (min 3.10, max 10.64)","260.48","20.08"
    "5242880","64.41 (min 63.88, max 64.87)","4.60 (min 2.73, max 10.58)","265.76","20.26"

|

.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "102400","64.14 (min 62.55, max 65.20)","5.42 (min 3.85, max 10.68)","230.51","18.54"
    "262144","66.98 (min 64.45, max 71.41)","4.60 (min 3.53, max 8.16)","238.80","19.22"
    "524288","64.39 (min 63.92, max 65.11)","4.78 (min 3.70, max 8.80)","255.04","18.58"
    "1048576","64.76 (min 63.61, max 65.79)","4.92 (min 3.57, max 9.95)","265.68","20.44"
    "5242880","64.64 (min 64.08, max 65.26)","4.57 (min 3.52, max 7.84)","271.64","20.93"

|

-  Filesize used is : 1G
-  MSATA Hard disk used is: SMS200S3/30G Kingston mSATA SSD drive

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

    "1m","18.80","1.90","86.80","3.27"
    "4m","19.20","1.48","86.00","2.73"
    "4k","5.01","8.82","16.60","16.96"
    "256k","18.50","2.50","84.20","4.28"

|

J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","13.30","0.78","99.10","1.67"
    "4m","14.10","0.62","97.10","1.51"
    "4k","5.19","5.07","18.30","10.60"
    "256k","13.30","0.94","96.90","2.16"

|

J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","18.90","0.68","43.40","0.53"
    "4m","19.00","0.66","43.30","0.50"
    "4k","4.72","2.56","13.60","6.12"
    "256k","18.50","0.78","42.90","0.65"

|

AM335X-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write EXT4 Throughput (Mbytes/sec)","am335x-evm: Write EXT4 CPU Load (%)","am335x-evm: Read EXT4 Throughput (Mbytes/sec)","am335x-evm: Read EXT4 CPU Load (%)"

    "1m","8.79","5.08","36.30","12.15"
    "4m","9.35","4.45","36.40","9.21"
    "4k","2.02","28.42","7.45","66.95"
    "256k","9.27","6.50","36.30","12.97"

|

AM43XX-GPEVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","am43xx-gpevm: Write EXT4 Throughput (Mbytes/sec)","am43xx-gpevm: Write EXT4 CPU Load (%)","am43xx-gpevm: Read EXT4 Throughput (Mbytes/sec)","am43xx-gpevm: Read EXT4 CPU Load (%)"

    "1m","9.48","2.92","36.50","9.68"
    "4m","8.38","2.33","37.90","9.57"
    "4k","3.04","15.68","8.42","36.82"
    "256k","8.88","3.89","35.80","10.66"

|

AM57XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "1m","9.72","0.41","34.40","0.78"
    "4m","10.50","0.48","34.40","0.78"
    "4k","3.91","3.53","10.00","8.25"
    "256k","9.63","0.58","34.30","0.92"

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

    "400000","17964.91","21445.03"
    "800000","17655.17","22443.84"
    "1000000","20004.88","23076.06"

J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

|

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","16995.85","80313.73"
    "800000","20428.93","86231.58"
    "1000000","18897.35","89043.48"

|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card

|

AM43XX-GPEVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

|

.. csv-table::
    :header: "File size (bytes in hex)","am43xx-gpevm: Write Throughput (Kbytes/sec)","am43xx-gpevm: Read Throughput (Kbytes/sec)"

    "400000","13003.17","19051.16"
    "800000","14422.54","19320.75"
    "1000000","8636.79","19412.32"

|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card

|

AM57XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

|

.. csv-table::
    :header: "File size (bytes in hex)","am57xx-evm: Write Throughput (Kbytes/sec)","am57xx-evm: Read Throughput (Kbytes/sec)"

    "400000","17808.70","21113.40"
    "800000","7677.60","21787.23"
    "1000000","14948.91","22200.54"

|

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

AM64XX-EVM
"""""""""""""""""""""""""""""""
|

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","36.80","5.51","37.30","5.20"
    "4m","36.00","5.03","37.80","4.98"
    "4k","17.40","28.36","17.90","27.47"
    "256k","35.40","7.98","36.40","6.54"

|

J721E-IDK-GW
"""""""""""""""""""""""""""""""
|

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","429.00","7.09","427.00","1.88"
    "4m","394.00","5.72","400.00","1.57"
    "4k","61.50","28.33","61.60","25.78"
    "256k","411.00","7.96","409.00","3.35"

|

J7200-EVM
"""""""""""""""""""""""""""""""
|

.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","38.80","2.34","38.80","1.52"
    "4m","38.90","2.37","38.90","1.54"
    "4k","21.60","20.02","21.80","18.96"
    "256k","37.00","2.95","38.00","2.19"

|

USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Number of Blocks","am335x-evm: Throughput (MB/sec)","am43xx-gpevm: Throughput (MB/sec)","am57xx-evm: Throughput (MB/sec)","j721e-idk-gw: Throughput (MB/sec)"

    "150","18.20","25.30","25.60","37.40"

Table: **USBDEVICE HIGHSPEED SLAVE READ THROUGHPUT**

|

.. csv-table::
    :header: "Number of Blocks","am335x-evm: Throughput (MB/sec)","am43xx-gpevm: Throughput (MB/sec)","am57xx-evm: Throughput (MB/sec)","j721e-idk-gw: Throughput (MB/sec)"

    "150","8.10","28.10","34.80","33.50"

Table: **USBDEVICE HIGHSPEED SLAVE WRITE THROUGHPUT**

|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am335x-evm: throughput (KBytes/Sec)","am57xx-evm: throughput (KBytes/Sec)","am64xx-evm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","12099.58","15314.94","26829.82"
    "aes-128-cbc","16","2304.16","5552.25","477.00"
    "aes-128-cbc","16384","17984.17","35405.82","171480.41"
    "aes-128-cbc","256","4191.66","5354.07","7592.96"
    "aes-128-cbc","64","7517.18","16580.63","1892.18"
    "aes-128-cbc","8192","19404.12","32475.82","125195.61"
    "aes-192-cbc","1024","11927.55","15298.90","27345.24"
    "aes-192-cbc","16","2358.37","5564.76","478.45"
    "aes-192-cbc","16384","17438.04","33647.27","155287.55"
    "aes-192-cbc","256","4239.70","5312.51","7633.15"
    "aes-192-cbc","64","7449.66","16211.18","1889.58"
    "aes-192-cbc","8192","19002.71","32492.20","118778.54"
    "aes-256-cbc","1024","11818.67","15270.23","26313.73"
    "aes-256-cbc","16","2292.87","5316.70","483.55"
    "aes-256-cbc","16384","16760.83","33663.66","142731.95"
    "aes-256-cbc","256","4157.53","5302.44","7526.40"
    "aes-256-cbc","64","7054.10","15458.28","1932.54"
    "aes-256-cbc","8192","18503.00","32475.82","109000.02"
    "des-cbc","1024","18540.54","9432.06","18701.65"
    "des-cbc","16","15100.33","323.15","4136.59"
    "des-cbc","16384","19447.81","16012.63","19786.41"
    "des-cbc","256","19131.73","4102.31","16051.71"
    "des-cbc","64","18229.31","1219.35","10166.98"
    "des-cbc","8192","19423.23","15297.19","19731.80"
    "des3","1024","6882.65","9321.47","7846.91"
    "des3","16","6273.10","319.09","3215.05"
    "des3","16384","6892.20","15652.18","8033.62"
    "des3","256","6855.68","4057.09","7353.60"
    "des3","64","6598.70","1205.99","5830.81"
    "des3","8192","6695.59","14155.78","8017.24"
    "md5","1024","8464.04","10224.30","35999.74"
    "md5","16","503.47","1029.27","782.73"
    "md5","16384","43226.45","65710.76","111684.27"
    "md5","256","3012.27","2868.22","11364.95"
    "md5","64","2020.71","4041.71","3029.70"
    "md5","8192","36260.52","48147.11","97812.48"
    "sha1","1024","8398.85","10207.57","42828.12"
    "sha1","16","486.99","998.89","746.58"
    "sha1","16384","42183.34","65945.60","271968.94"
    "sha1","256","2999.47","2810.03","11616.26"
    "sha1","64","1846.34","3922.20","2953.75"
    "sha1","8192","35695.27","48300.03","200499.20"
    "sha224","1024","8288.94","10151.94","43106.99"
    "sha224","16","459.64","903.67","746.52"
    "sha224","16384","42079.57","65432.23","281810.26"
    "sha224","256","2925.23","2865.49","11613.78"
    "sha224","64","1761.75","3424.09","2951.19"
    "sha224","8192","34485.59","47813.97","206009.69"
    "sha256","1024","8041.81","10115.41","25750.53"
    "sha256","16","457.72","910.57","429.34"
    "sha256","16384","45279.91","65699.84","221265.92"
    "sha256","256","3009.54","2850.22","6724.35"
    "sha256","64","1757.23","3459.99","1709.99"
    "sha256","8192","35353.94","47958.70","146696.87"
    "sha384","1024","17606.31","10375.51","25192.11"
    "sha384","16","456.49","836.06","707.01"
    "sha384","16384","39365.29","77561.86","53417.30"
    "sha384","256","6161.83","2866.18","9450.84"
    "sha384","64","1882.65","3351.77","2834.45"
    "sha384","8192","35231.06","53269.85","49722.71"
    "sha512","1024","17623.38","10304.85","18434.73"
    "sha512","16","469.36","842.11","423.00"
    "sha512","16384","39299.75","79178.41","50883.24"
    "sha512","256","6280.62","2826.33","6064.55"
    "sha512","64","1822.66","3369.62","1698.01"
    "sha512","8192","35130.03","54782.63","45380.95"

|

.. csv-table::
    :header: "Algorithm","am335x-evm: CPU Load","am57xx-evm: CPU Load","am64xx-evm: CPU Load"

    "aes-128-cbc","42.00","40.00","40.00"
    "aes-192-cbc","42.00","40.00","39.00"
    "aes-256-cbc","42.00","40.00","43.00"
    "des-cbc","97.00","12.00","98.00"
    "des3","97.00","12.00","98.00"
    "md5","59.00","50.00","98.00"
    "sha1","60.00","51.00","98.00"
    "sha224","60.00","50.00","98.00"
    "sha256","60.00","50.00","98.00"
    "sha384","96.00","61.00","98.00"
    "sha512","97.00","52.00","98.00"

|
 Listed for each algorithm are the code snippets used to run each
  benchmark test.

|

::

    time -v openssl speed -elapsed -evp aes-128-cbc

IPSec Hardware Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Note: queue\_len is set to 300 and software fallback threshold set to 9
to enable software support for optimal performance

.. csv-table::
    :header: "Algorithm","am43xx-gpevm: Throughput (Mbps)","am43xx-gpevm: Packets/Sec","am43xx-gpevm: CPU Load"

    "aes128","0.00","0.00","99.69"

IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am43xx-gpevm: Throughput (Mbps)","am43xx-gpevm: Packets/Sec","am43xx-gpevm: CPU Load","j7200-evm: Throughput (Mbps)","j7200-evm: Packets/Sec","j7200-evm: CPU Load","j721e-idk-gw: Throughput (Mbps)","j721e-idk-gw: Packets/Sec","j721e-idk-gw: CPU Load"

    "3des","186.10","16.00","37.64","230.20","20.00","36.79"
    "aes128","82.40","7.00","100.18","588.10","52.00","57.00","785.30","70.00","56.57"
    "aes192","77.20","6.00","100.24","570.70","50.00","56.96","443.80","39.00","56.90"
    "aes256","69.10","6.00","100.23","578.70","51.00","57.00","768.60","68.00","56.34"

DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.

Power Management
-------------------------

