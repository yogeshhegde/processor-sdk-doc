.. http://processors.wiki.ti.com/index.php/CoreSDK_Linux_Kernel_Performance_Guide


======================================
 Linux 08.02.00 Performance Guide
======================================

.. rubric::  **Read This First**
   :name: read-this-first-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| AM335x EVM     | AM335x Evaluation Module rev 1.5B with ARM running at 1000MHz, DDR3-400 (400MHz/800 MT/S), TMDXEVM3358         |
+----------------+----------------------------------------------------------------------------------------------------------------+
| AM437x-gpevm   | AM437x-gpevm Evaluation Module rev 1.5A with ARM running at 1000MHz, DDR3-400 (400MHz/800 MT/S), TMDSEVM437X   |
+----------------+----------------------------------------------------------------------------------------------------------------+
| AM572x EVM     | AM57xx Evaluation Module rev A2 with ARM running at 1500MHz, DDR3L-533 (533 MHz/1066 MT/S), TMDSEVM572x        |
+----------------+----------------------------------------------------------------------------------------------------------------+
| AM64x EVM      | AM64x Evaluation Module rev E1 with ARM running at 1GHz, DDR data rate 1600 MT/S                               |
+----------------+----------------------------------------------------------------------------------------------------------------+
| J721e EVM      | J721e Evaluation Module rev E2 with ARM running at 2GHz, DDR data rate 4266 MT/S, L3 Cache size 3MB            |
+----------------+----------------------------------------------------------------------------------------------------------------+
| J721s2 EVM     | J721s2 Evaluation Module rev E2 with ARM running at 2GHz, DDR data rate 4266 MT/S, L3 Cache size 3MB            |
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
    :header: "Benchmarks","am335x-evm: perf","am43xx-gpevm: perf","am57xx-evm: perf","am64xx-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "af_unix_sock_stream_latency (microsec)","44.94","34.57","34.32","41.18","17.58","17.59"
    "af_unix_socket_stream_bandwidth (MBs)","135.21","171.75","2161.12","567.49","2600.92","2581.27"
    "bw_file_rd-io-1mb (MB/s)","154.32","194.93","1633.84","1038.96","3613.54","3688.00"
    "bw_file_rd-o2c-1mb (MB/s)","130.15","161.19","1170.39","589.88","1876.17","1754.39"
    "bw_mem-bcopy-16mb (MB/s)","182.60","193.91","2064.25","890.92","2498.05","2921.84"
    "bw_mem-bcopy-1mb (MB/s)","180.44","200.02","5114.61","850.46","4758.42","5342.49"
    "bw_mem-bcopy-2mb (MB/s)","188.48","198.73","2921.04","891.40","3060.44","3219.46"
    "bw_mem-bcopy-4mb (MB/s)","181.23","195.65","2178.85","905.49","3078.11","3899.27"
    "bw_mem-bcopy-8mb (MB/s)","183.79","198.65","2113.98","909.92","2643.75","2955.30"
    "bw_mem-bzero-16mb (MB/s)","967.82","673.23","5563.28","2126.53","9634.20","10758.11"
    "bw_mem-bzero-1mb (MB/s)","573.92 (min 180.44, max 967.40)","438.42 (min 200.02, max 676.82)","5742.02 (min 5114.61, max 6369.43)","1488.12 (min 850.46, max 2125.78)","8295.83 (min 4758.42, max 11833.24)","8491.86 (min 5342.49, max 11641.22)"
    "bw_mem-bzero-2mb (MB/s)","579.43 (min 188.48, max 970.37)","436.69 (min 198.73, max 674.65)","4538.97 (min 2921.04, max 6156.90)","1511.04 (min 891.40, max 2130.68)","7398.98 (min 3060.44, max 11737.51)","7270.80 (min 3219.46, max 11322.13)"
    "bw_mem-bzero-4mb (MB/s)","575.53 (min 181.23, max 969.83)","434.64 (min 195.65, max 673.63)","4060.09 (min 2178.85, max 5941.33)","1516.39 (min 905.49, max 2127.28)","7357.24 (min 3078.11, max 11636.36)","7375.57 (min 3899.27, max 10851.87)"
    "bw_mem-bzero-8mb (MB/s)","576.87 (min 183.79, max 969.95)","436.06 (min 198.65, max 673.46)","3906.50 (min 2113.98, max 5699.02)","1518.37 (min 909.92, max 2126.81)","7132.66 (min 2643.75, max 11621.57)","6885.80 (min 2955.30, max 10816.29)"
    "bw_mem-cp-16mb (MB/s)","166.56","195.88","1083.20","603.20","1046.44","1576.04"
    "bw_mem-cp-1mb (MB/s)","569.71 (min 171.67, max 967.75)","439.26 (min 201.47, max 677.05)","5318.33 (min 4208.08, max 6428.57)","1442.93 (min 596.21, max 2289.64)","6564.84 (min 1316.53, max 11813.14)","6916.92 (min 2148.02, max 11685.82)"
    "bw_mem-cp-2mb (MB/s)","567.24 (min 174.78, max 959.69)","437.58 (min 200.16, max 674.99)","3735.83 (min 1274.47, max 6197.18)","1396.60 (min 597.01, max 2196.19)","6464.22 (min 1176.30, max 11752.14)","6408.93 (min 1493.65, max 11324.20)"
    "bw_mem-cp-4mb (MB/s)","568.41 (min 170.39, max 966.42)","436.44 (min 199.36, max 673.51)","3525.77 (min 1125.10, max 5926.44)","1382.78 (min 601.05, max 2164.50)","6421.96 (min 1171.47, max 11672.44)","6414.89 (min 1981.83, max 10847.95)"
    "bw_mem-cp-8mb (MB/s)","555.20 (min 150.35, max 960.04)","437.66 (min 201.75, max 673.57)","3396.17 (min 1108.49, max 5683.84)","1374.86 (min 600.33, max 2149.38)","6289.96 (min 1031.73, max 11548.18)","6030.71 (min 1272.47, max 10788.94)"
    "bw_mem-fcp-16mb (MB/s)","261.94","148.81","1210.84","865.19","2427.18","2716.93"
    "bw_mem-fcp-1mb (MB/s)","614.87 (min 262.33, max 967.40)","413.88 (min 150.94, max 676.82)","4764.43 (min 3159.42, max 6369.43)","1473.20 (min 820.61, max 2125.78)","8393.18 (min 4953.12, max 11833.24)","8558.16 (min 5475.10, max 11641.22)"
    "bw_mem-fcp-2mb (MB/s)","613.94 (min 257.50, max 970.37)","411.63 (min 148.61, max 674.65)","3731.93 (min 1306.95, max 6156.90)","1490.33 (min 849.98, max 2130.68)","7408.70 (min 3079.88, max 11737.51)","7081.27 (min 2840.40, max 11322.13)"
    "bw_mem-fcp-4mb (MB/s)","616.44 (min 263.04, max 969.83)","410.68 (min 147.73, max 673.63)","3577.46 (min 1213.59, max 5941.33)","1491.22 (min 855.16, max 2127.28)","7354.87 (min 3073.38, max 11636.36)","7293.06 (min 3734.25, max 10851.87)"
    "bw_mem-fcp-8mb (MB/s)","614.40 (min 258.84, max 969.95)","411.13 (min 148.80, max 673.46)","3453.56 (min 1208.09, max 5699.02)","1481.86 (min 836.91, max 2126.81)","7099.03 (min 2576.49, max 11621.57)","6763.62 (min 2710.95, max 10816.29)"
    "bw_mem-frd-16mb (MB/s)","221.37","211.55","1083.28","1506.45","4778.97","4647.79"
    "bw_mem-frd-1mb (MB/s)","242.77 (min 223.21, max 262.33)","193.17 (min 150.94, max 235.40)","3127.14 (min 3094.85, max 3159.42)","1128.05 (min 820.61, max 1435.49)","5474.50 (min 4953.12, max 5995.88)","5758.16 (min 5475.10, max 6041.22)"
    "bw_mem-frd-2mb (MB/s)","238.84 (min 220.17, max 257.50)","177.16 (min 148.61, max 205.70)","1843.41 (min 1306.95, max 2379.86)","1143.00 (min 849.98, max 1436.01)","4434.82 (min 3079.88, max 5789.76)","4175.57 (min 2840.40, max 5510.73)"
    "bw_mem-frd-4mb (MB/s)","242.29 (min 221.54, max 263.04)","178.82 (min 147.73, max 209.91)","1222.23 (min 1213.59, max 1230.86)","1172.05 (min 855.16, max 1488.93)","4325.12 (min 3073.38, max 5576.86)","4201.63 (min 3734.25, max 4669.00)"
    "bw_mem-frd-8mb (MB/s)","240.56 (min 222.28, max 258.84)","177.79 (min 148.80, max 206.78)","1153.65 (min 1099.20, max 1208.09)","1160.78 (min 836.91, max 1484.64)","3964.73 (min 2576.49, max 5352.96)","3679.37 (min 2710.95, max 4647.79)"
    "bw_mem-fwr-16mb (MB/s)","968.52","673.15","5563.28","2145.63","9680.83","10731.05"
    "bw_mem-fwr-1mb (MB/s)","595.48 (min 223.21, max 967.75)","456.23 (min 235.40, max 677.05)","4761.71 (min 3094.85, max 6428.57)","1862.57 (min 1435.49, max 2289.64)","8904.51 (min 5995.88, max 11813.14)","8863.52 (min 6041.22, max 11685.82)"
    "bw_mem-fwr-2mb (MB/s)","589.93 (min 220.17, max 959.69)","440.35 (min 205.70, max 674.99)","4288.52 (min 2379.86, max 6197.18)","1816.10 (min 1436.01, max 2196.19)","8770.95 (min 5789.76, max 11752.14)","8417.47 (min 5510.73, max 11324.20)"
    "bw_mem-fwr-4mb (MB/s)","593.98 (min 221.54, max 966.42)","441.71 (min 209.91, max 673.51)","3578.65 (min 1230.86, max 5926.44)","1826.72 (min 1488.93, max 2164.50)","8624.65 (min 5576.86, max 11672.44)","7758.48 (min 4669.00, max 10847.95)"
    "bw_mem-fwr-8mb (MB/s)","591.16 (min 222.28, max 960.04)","440.18 (min 206.78, max 673.57)","3391.52 (min 1099.20, max 5683.84)","1817.01 (min 1484.64, max 2149.38)","8450.57 (min 5352.96, max 11548.18)","7718.37 (min 4647.79, max 10788.94)"
    "bw_mem-rd-16mb (MB/s)","224.00","425.67","3158.73","1506.73","5085.82","5389.02"
    "bw_mem-rd-1mb (MB/s)","598.52 (min 227.44, max 969.59)","346.31 (min 273.45, max 419.17)","9994.40 (min 6553.80, max 13435.00)","1188.93 (min 918.27, max 1459.59)","11551.45 (min 10829.59, max 12273.31)","12023.40 (min 10276.53, max 13770.26)"
    "bw_mem-rd-2mb (MB/s)","593.90 (min 223.56, max 964.23)","346.03 (min 271.41, max 420.65)","7984.49 (min 6553.80, max 9415.17)","1263.75 (min 1020.06, max 1507.44)","3993.06 (min 1413.18, max 6572.94)","4551.41 (min 2689.98, max 6412.83)"
    "bw_mem-rd-4mb (MB/s)","595.86 (min 224.83, max 966.88)","345.54 (min 271.91, max 419.16)","2591.57 (min 1724.73, max 3458.41)","1280.77 (min 1063.12, max 1498.41)","3783.97 (min 1375.99, max 6191.95)","3898.27 (min 2261.16, max 5535.37)"
    "bw_mem-rd-8mb (MB/s)","594.61 (min 223.74, max 965.48)","346.92 (min 271.02, max 422.81)","2291.87 (min 1394.46, max 3189.28)","1327.10 (min 1156.07, max 1498.13)","3524.88 (min 1270.45, max 5779.30)","3809.97 (min 2211.78, max 5408.15)"
    "bw_mem-rdwr-16mb (MB/s)","183.65","296.44","1254.31","1103.22","1974.82","2176.87"
    "bw_mem-rdwr-1mb (MB/s)","178.92 (min 171.67, max 186.17)","249.08 (min 201.47, max 296.69)","5892.61 (min 4208.08, max 7577.14)","762.71 (min 596.21, max 929.20)","3941.57 (min 1316.53, max 6566.60)","4685.42 (min 2148.02, max 7222.82)"
    "bw_mem-rdwr-2mb (MB/s)","179.73 (min 174.78, max 184.67)","247.90 (min 200.16, max 295.64)","2303.60 (min 1274.47, max 3332.72)","807.07 (min 597.01, max 1017.12)","1232.57 (min 1176.30, max 1288.83)","2084.24 (min 1493.65, max 2674.82)"
    "bw_mem-rdwr-4mb (MB/s)","177.33 (min 170.39, max 184.26)","247.52 (min 199.36, max 295.68)","1290.75 (min 1125.10, max 1456.40)","826.43 (min 601.05, max 1051.80)","1222.27 (min 1171.47, max 1273.07)","2090.62 (min 1981.83, max 2199.41)"
    "bw_mem-rdwr-8mb (MB/s)","166.84 (min 150.35, max 183.32)","248.84 (min 201.75, max 295.92)","1192.16 (min 1108.49, max 1275.82)","843.20 (min 600.33, max 1086.07)","1341.12 (min 1031.73, max 1650.51)","1693.88 (min 1272.47, max 2115.28)"
    "bw_mem-wr-16mb (MB/s)","969.93","271.62","1361.93","1169.33","1876.61","2195.99"
    "bw_mem-wr-1mb (MB/s)","577.88 (min 186.17, max 969.59)","285.07 (min 273.45, max 296.69)","10506.07 (min 7577.14, max 13435.00)","923.74 (min 918.27, max 929.20)","9419.96 (min 6566.60, max 12273.31)","10496.54 (min 7222.82, max 13770.26)"
    "bw_mem-wr-2mb (MB/s)","574.45 (min 184.67, max 964.23)","283.53 (min 271.41, max 295.64)","6373.95 (min 3332.72, max 9415.17)","1018.59 (min 1017.12, max 1020.06)","1351.01 (min 1288.83, max 1413.18)","2682.40 (min 2674.82, max 2689.98)"
    "bw_mem-wr-4mb (MB/s)","575.57 (min 184.26, max 966.88)","283.80 (min 271.91, max 295.68)","1590.57 (min 1456.40, max 1724.73)","1057.46 (min 1051.80, max 1063.12)","1324.53 (min 1273.07, max 1375.99)","2230.29 (min 2199.41, max 2261.16)"
    "bw_mem-wr-8mb (MB/s)","574.40 (min 183.32, max 965.48)","283.47 (min 271.02, max 295.92)","1335.14 (min 1275.82, max 1394.46)","1121.07 (min 1086.07, max 1156.07)","1460.48 (min 1270.45, max 1650.51)","2163.53 (min 2115.28, max 2211.78)"
    "bw_mmap_rd-mo-1mb (MB/s)","218.60","190.44","4119.37","1347.03","9197.94","9485.87"
    "bw_mmap_rd-o2c-1mb (MB/s)","151.40","145.48","1353.44","661.49","1851.85","1716.57"
    "bw_pipe (MB/s)","270.82","362.77","587.89","742.96","4604.84","2756.33"
    "bw_unix (MB/s)","135.21","171.75","2161.12","567.49","2600.92","2581.27"
    "lat_connect (us)","103.95","72.30","48.93","62.94","27.44","27.80"
    "lat_ctx-2-128k (us)","19.35","0.00","9.48","28.43","3.87","3.89"
    "lat_ctx-2-256k (us)","4.00","0.00","1.88","73.96","4.26","4.65"
    "lat_ctx-4-128k (us)","43.72","0.00","11.40","53.04","4.99","5.18"
    "lat_ctx-4-256k (us)","0.00","0.00","0.00","61.31","5.89","6.07"
    "lat_fs-0k (num_files)","174.00","245.00","721.00","277.00","618.00","624.00"
    "lat_fs-10k (num_files)","58.00","75.00","279.00","77.00","214.00","175.00"
    "lat_fs-1k (num_files)","99.00","116.00","412.00","82.00","201.00","192.00"
    "lat_fs-4k (num_files)","85.00","131.00","449.00","85.00","205.00","182.00"
    "lat_mem_rd-stride128-sz1000k (ns)","255.75","97.10","12.84","41.93","8.88","9.19"
    "lat_mem_rd-stride128-sz125k (ns)","27.81","16.02","12.69","7.56","5.15","5.15"
    "lat_mem_rd-stride128-sz250k (ns)","69.74","40.52","12.83","8.15","5.15","5.15"
    "lat_mem_rd-stride128-sz31k (ns)","3.14","4.01","6.46","3.03","2.00","2.00"
    "lat_mem_rd-stride128-sz50 (ns)","3.08","4.01","2.67","3.01","2.00","2.00"
    "lat_mem_rd-stride128-sz500k (ns)","211.16","90.21","12.83","36.73","5.15","5.15"
    "lat_mem_rd-stride128-sz62k (ns)","9.17","16.91","12.69","6.41","5.15","5.15"
    "lat_mmap-1m (us)","77.00","57.00","49.00","22.00","8.48","8.51"
    "lat_ops-double-add (ns)","2.44","1.00","0.73","0.73","0.32","0.32"
    "lat_ops-double-mul (ns)","11.33","7.02","3.35","4.01","2.00","2.00"
    "lat_ops-float-add (ns)","2.35","0.91","0.73","0.73","0.32","0.32"
    "lat_ops-float-mul (ns)","10.31","6.02","3.34","4.01","2.00","2.00"
    "lat_ops-int-add (ns)","1.03","1.03","0.67","1.00","0.50","0.50"
    "lat_ops-int-bit (ns)","0.69","0.76","0.45","0.67","0.33","0.33"
    "lat_ops-int-div (ns)","76.96","96.05","60.20","6.01","4.00","4.00"
    "lat_ops-int-mod (ns)","25.13","24.01","8.97","6.35","4.67","4.67"
    "lat_ops-int-mul (ns)","6.21","4.05","2.09","3.04","1.52","1.52"
    "lat_ops-int64-add (ns)","1.24","1.17","0.83","1.00","0.50","0.50"
    "lat_ops-int64-bit (ns)","2.59","1.02","0.67","0.67","0.33","0.33"
    "lat_ops-int64-div (ns)","197.60","186.42","108.61","9.53","3.00","3.00"
    "lat_ops-int64-mod (ns)","52.43","46.99","22.49","7.35","5.67","5.67"
    "lat_pagefault (us)","2.08","1.63","1.08","2.69","1.14","1.18"
    "lat_pipe (us)","35.44","26.05","31.07","24.98","10.67","10.87"
    "lat_proc-exec (us)","2190.60","1696.33","930.75","2091.67","716.63","834.00"
    "lat_proc-fork (us)","1741.34","1350.00","840.46","1733.25","655.00","766.22"
    "lat_proc-proccall (us)","0.02","0.01","0.01","0.01","0.00","0.00"
    "lat_select (us)","40.69","31.82","22.21","47.84","9.73","9.71"
    "lat_sem (us)","4.68","3.81","3.92","3.19","1.39","1.36"
    "lat_sig-catch (us)","6.20","4.51","3.00","6.87","2.52","2.52"
    "lat_sig-install (us)","1.44","0.92","0.61","0.66","0.40","0.44"
    "lat_sig-prot (us)","0.13","0.05","0.35","0.60","0.28","0.28"
    "lat_syscall-fstat (us)","1.99","1.47","0.97","1.62","0.61","0.61"
    "lat_syscall-null (us)","0.54","0.39","0.27","0.40","0.29","0.31"
    "lat_syscall-open (us)","280.32","299.11","203.04","321.78","151.47","124.33"
    "lat_syscall-read (us)","0.92","0.67","0.35","0.77","0.37","0.36"
    "lat_syscall-stat (us)","5.51","4.33","2.87","4.80","1.56","1.66"
    "lat_syscall-write (us)","0.72","0.53","0.33","0.66","0.34","0.34"
    "lat_tcp (us)","1.16","0.80","0.54","0.81","0.60","0.57"
    "lat_unix (us)","44.94","34.57","34.32","41.18","17.58","17.59"
    "latency_for_0.50_mb_block_size (nanosec)","211.16","90.21","12.83","36.73","5.15","5.15"
    "latency_for_1.00_mb_block_size (nanosec)","127.87 (min 0.00, max 255.75)","48.55 (min 0.00, max 97.10)","6.42 (min 0.00, max 12.84)","20.97 (min 0.00, max 41.93)","4.44 (min 0.00, max 8.88)","4.60 (min 0.00, max 9.19)"
    "pipe_bandwidth (MBs)","270.82","362.77","587.89","742.96","4604.84","2756.33"
    "pipe_latency (microsec)","35.44","26.05","31.07","24.98","10.67","10.87"
    "procedure_call (microsec)","0.02","0.01","0.01","0.01","0.00","0.00"
    "select_on_200_tcp_fds (microsec)","40.69","31.82","22.21","47.84","9.73","9.71"
    "semaphore_latency (microsec)","4.68","3.81","3.92","3.19","1.39","1.36"
    "signal_handler_latency (microsec)","1.44","0.92","0.61","0.66","0.40","0.44"
    "signal_handler_overhead (microsec)","6.20","4.51","3.00","6.87","2.52","2.52"
    "tcp_ip_connection_cost_to_localhost (microsec)","103.95","72.30","48.93","62.94","27.44","27.80"
    "tcp_latency_using_localhost (microsec)","1.16","0.80","0.54","0.81","0.60","0.57"


Table:  **LM Bench Metrics**



Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.
  
.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am43xx-gpevm: perf","am57xx-evm: perf","am64xx-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "cpu_clock (MHz)","1000.00","1000.00","1500.00","1000.00","2000.00","2000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.10","2.50","3.40","2.92","3.70","5.17"
    "dhrystone_per_second (DhrystoneP)","3636363.80","4347826.00","9090909.00","5128205.00","20000000.00","18181818.00"


Table:  **Dhrystone Benchmark**



Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am43xx-gpevm: perf","am57xx-evm: perf","am64xx-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "whetstone (MIPS)","833.30","3333.30","5000.00","5000.00","10000.00","10000.00"


Table:  **Whetstone Benchmark**



Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am43xx-gpevm: perf","am57xx-evm: perf","am64xx-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "linpack (Kflops)","51162.00","179939.00","953704.00","421061.00","2652247.00","2645095.00"


Table:  **Linpack Benchmark**



NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html


.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am43xx-gpevm: perf","am57xx-evm: perf","am64xx-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "assignment (Iterations)","7.52","7.70","16.66","9.76","29.68","29.68"
    "fourier (Iterations)","2851.00","13312.00","26366.00","16329.00","49524.00","55155.00"
    "fp_emulation (Iterations)","78.77","84.95","169.12","76.53","250.05","250.13"
    "huffman (Iterations)","709.42","854.95","1405.60","838.18","2429.00","2425.30"
    "idea (Iterations)","1280.00","1372.90","3649.80","2453.00","7997.30","7996.90"
    "lu_decomposition (Iterations)","74.58","342.21","833.50","403.14","1431.80","1431.10"
    "neural_net (Iterations)","2.13","9.19","25.09","5.60","27.33","27.34"
    "numeric_sort (Iterations)","458.12","425.56","621.94","361.19","879.39","879.30"
    "string_sort (Iterations)","60.60","52.72","118.05","118.49","422.86","427.73"


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
    :header: "Benchmarks","am335x-evm: perf","am43xx-gpevm: perf","am57xx-evm: perf","am64xx-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "add (MB/s)","382.90","386.60","3887.50","1898.30","5472.80","6148.20"
    "copy (MB/s)","435.70","399.50","4224.80","2499.60","5748.20","6799.00"
    "scale (MB/s)","611.20","654.80","4796.80","2462.60","5468.80","6962.00"
    "triad (MB/s)","447.70","590.80","3862.60","1918.50","5379.00","6113.70"


Table:  **Stream**



CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.


.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "cjpeg-rose7-preset (workloads/)","29.67","82.64","83.33"
    "core (workloads/)","0.21","0.78","0.78"
    "coremark-pro ()","602.74","2558.25","2541.78"
    "linear_alg-mid-100x100-sp (workloads/)","10.50","82.51","82.64"
    "loops-all-mid-10k-sp (workloads/)","0.49","2.50","2.50"
    "nnet_test (workloads/)","0.78","3.67","3.67"
    "parser-125k (workloads/)","6.29","12.20","12.05"
    "radix2-big-64k (workloads/)","19.84","267.24","252.78"
    "sha-test (workloads/)","58.14","158.73","158.73"
    "zip-test (workloads/)","16.39","52.63","52.63"


Table:  **CoreMarkPro**



.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "cjpeg-rose7-preset (workloads/)","59.17","161.29","166.67"
    "core (workloads/)","0.43","1.55","1.55"
    "coremark-pro ()","1085.32","4454.76","4606.24"
    "linear_alg-mid-100x100-sp (workloads/)","20.95","164.47","165.02"
    "loops-all-mid-10k-sp (workloads/)","0.89","3.78","3.85"
    "nnet_test (workloads/)","1.55","7.34","7.73"
    "parser-125k (workloads/)","7.25","23.26","22.99"
    "radix2-big-64k (workloads/)","31.02","259.54","290.02"
    "sha-test (workloads/)","116.28","312.50","312.50"
    "zip-test (workloads/)","30.77","90.91","100.00"


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
    :header: "Benchmarks","am64xx-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf"

    "4m-check (workloads/)","344.21","1086.01","991.28"
    "4m-check-reassembly (workloads/)","82.30","235.85","237.53"
    "4m-check-reassembly-tcp (workloads/)","45.37","128.87","121.95"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","16.82","46.91","43.57"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","0.78","2.78","2.74"
    "4m-cmykw2 (workloads/)","90.87","320.51","287.77"
    "4m-cmykw2-rotatew2 (workloads/)","22.74","65.36","61.54"
    "4m-reassembly (workloads/)","80.45","247.53","227.79"
    "4m-rotatew2 (workloads/)","26.87","75.30","72.05"
    "4m-tcp-mixed (workloads/)","93.02","280.70","250.00"
    "4m-x264w2 (workloads/)","0.79","2.82","2.79"
    "empty-wld (workloads/)","1.00","",""
    "idct-4m (workloads/)","13.73","35.12","35.03"
    "idct-4mw1 (workloads/)","13.73","35.14","35.03"
    "ippktcheck-4m (workloads/)","344.12","1086.96","992.06"
    "ippktcheck-4mw1 (workloads/)","344.26","1077.12","1005.23"
    "ipres-4m (workloads/)","73.96","208.04","185.19"
    "ipres-4mw1 (workloads/)","74.00","208.62","185.41"
    "md5-4m (workloads/)","19.74","51.36","47.19"
    "md5-4mw1 (workloads/)","19.62","52.36","47.26"
    "rgbcmyk-4m (workloads/)","45.71","164.20","163.40"
    "rgbcmyk-4mw1 (workloads/)","45.89","164.20","163.53"
    "rotate-4ms1 (workloads/)","19.55","57.14","54.05"
    "rotate-4ms1w1 (workloads/)","19.43","57.14","54.05"
    "rotate-4ms64 (workloads/)","19.68","57.60","54.47"
    "rotate-4ms64w1 (workloads/)","19.65","57.54","54.59"
    "x264-4mq (workloads/)","0.41","1.46","1.44"
    "x264-4mqw1 (workloads/)","0.41","1.45","1.44"


Table:  **Multibench**


 
 


Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am43xx-gpevm: boot time (sec)","am57xx-evm: boot time (sec)","am64xx-evm: boot time (sec)","j721e-idk-gw: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","51.70 (min 51.44, max 51.89)","29.16 (min 28.52, max 29.48)","28.79 (min 28.37, max 29.23)","23.06 (min 22.64, max 23.69)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","9.88 (min 9.83, max 9.93)","11.33 (min 11.29, max 11.34)","4.30 (min 4.27, max 4.42)","8.77 (min 8.74, max 8.79)"

Table:  **Boot time MMC/SD**


 
 


ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64


.. csv-table::
    :header: "Sampling Rate (Hz)","am335x-evm: Throughput (bits/sec)","am335x-evm: CPU Load (%)","am43xx-gpevm: Throughput (bits/sec)","am43xx-gpevm: CPU Load (%)","am57xx-evm: Throughput (bits/sec)","am57xx-evm: CPU Load (%)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "8000","255999.00","7.02","255998.00","0.73","255833.00","0.22","",""
    "11025","352799.00","9.49","352797.00","0.77","352573.00","0.16","352800.00",""
    "16000","511997.00","18.97","511996.00","1.68","511665.00","0.20","512000.00","0.10"
    "22050","705596.00","11.97","705594.00","1.75","705145.00","0.27","705600.00","0.14"
    "24000","705596.00","12.02","705594.00","1.60","705146.00","0.25","705600.00","0.29"
    "32000","1023993.00","11.78","1023991.00","0.31","1023330.00","0.30","1023999.00","0.17"
    "44100","1411188.00","15.28","1411187.00","3.12","1410291.00","0.49","1411199.00","0.50"
    "48000","1535987.00","14.98","1535986.00","0.34","1534995.00","0.53","1535999.00","0.22"
    "88200","2822344.00","29.67","2822370.00","6.07","2820577.00","0.78","2822395.00","0.96"
    "96000","3071955.00","9.38","3071966.00","0.50","3069989.00","0.87","3071994.00","0.35"

Table:  **Audio Capture**


|


.. csv-table::
    :header: "Sampling Rate (Hz)","am335x-evm: Throughput (bits/sec)","am335x-evm: CPU Load (%)","am43xx-gpevm: Throughput (bits/sec)","am43xx-gpevm: CPU Load (%)","am57xx-evm: Throughput (bits/sec)","am57xx-evm: CPU Load (%)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)","j721s2-evm: Throughput (bits/sec)","j721s2-evm: CPU Load (%)"

    "8000","256103.00","9.16","256102.00","0.16","255934.00","0.14","","","",""
    "11025","352941.00","3.98","352941.00","0.76","352712.00","0.12","352945.00","0.09","352942.00","0.53"
    "16000","512205.00","23.81","512205.00","0.20","511867.00","0.14","512211.00","0.13","512200.00","1.03"
    "22050","705882.00","7.71","705882.00","1.60","705424.00","0.19","705891.00","0.30","705869.00","0.46"
    "24000","705882.00","7.75","705882.00","1.52","705424.00","0.18","705891.00","","768289.00","0.49"
    "32000","1024408.00","1.22","1024409.00","0.37","1023734.00","0.28","1024422.00","0.18","1024410.00","1.98"
    "44100","1411760.00","14.14","1411763.00","2.96","1410847.00","0.35","1411781.00","0.23","1411639.00","0.85"
    "48000","1536608.00","19.33","1536613.00","12.22","1535601.00","0.37","1536632.00","0.26","1536446.00","0.96"
    "88200","2823504.00","27.90","2823522.00","5.77","2821692.00","0.68","2823560.00","0.37","1536448.00","1.93"
    "96000","3073224.00","54.47","3073221.00","0.15","3071200.00","0.70","3073262.00","0.33","1536433.00","2.91"

Table:  **Audio Playback**
 

|

 


Sensor Capture
-------------------------

Capture video frames (MMAP buffers) with v4l2c-ctl and record the
reported fps

.. csv-table::
    :header: "Resolution","Format","am57xx-evm: Fps","am57xx-evm: Sensor"

    "1280x800","nv12","30.01","ov10635"
    "1280x800","rgb4","30.01","ov10635"
    "320x240","nv12","30.01","ov10635"
    "320x240","rgb4","30.01","ov10635"

Table:  **Sensor Capture**

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
    :header: "Benchmark","am57xx-evm: Test Number","am57xx-evm: Fps"

    "GLB25_EgyptTestC24Z16FixedTime test","2500005.00","25.96 (min 14.87, max 58.51)"
    "GLB25_EgyptTestC24Z16_ETC1 test","2501001.00","32.28 (min 14.87, max 59.49)"
    "GLB25_EgyptTestC24Z16_ETC1to565 test","2501401.00","32.75 (min 14.87, max 59.49)"
    "GLB25_EgyptTestC24Z16_PVRTC4 test","2501101.00","32.01 (min 14.87, max 59.49)"
    "GLB25_EgyptTestC24Z24MS4 test","2500003.00","28.41 (min 14.87, max 59.49)"
    "GLB25_EgyptTestStandard_inherited test","2000000.00","59.45 (min 57.51, max 59.50)"




Table:  **GLBenchmark 2.5 Performance**
 


Vertex Throughput
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Benchmark","am57xx-evm: Test Number","am57xx-evm: Rate (triangles/sec)"

    "GLB25_TriangleTexFragmentLitTestC24Z16 test","2500511.00","32411748.00"
    "GLB25_TriangleTexTestC24Z16 test","2500301.00","98864944.00"
    "GLB25_TriangleTexVertexLitTestC24Z16 test","2500411.00","39399896.00"


Table:  **GLBenchmark 2.5 Vertex Throughput**



Pixel Throughput
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Benchmark","am57xx-evm: Test Number","am57xx-evm: Rate (texel/sec)","am57xx-evm: Fps"

    "GLB25_FillTestC24Z16 test","2500101.00","731048896.00","29.74"


Table:  **GLBenchmark 2.5 Pixel Throughput**
 
 


GFXBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Run GFXBench and capture performance reported (Score and Display rate in fps). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","j721e-idk-gw: Score","j721e-idk-gw: Fps"

    " GFXBench 3.x gl_trex_off","1860.10","33.22"
    " GFXBench 4.x gl_4_off","426.47","7.22"
    " GFXBench 5.x gl_5_high_off","180.17","2.80"


Table:  **GFXBench**



Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am335x-evm: Score","am57xx-evm: Score","j721e-idk-gw: Score"

    "Glmark2-DRM","39.00","56.00"
    "Glmark2-Wayland","39.00","294.00","1147.00"


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
    :header: "Command Used","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1011.89","97.74","1848.95","75.91","1840.07","71.12"

Table: **CPSW TCP Bidirectional Throughput**
|



.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","7.35","87.10","18.00","35.25","92.52","18.00","3.24","4.27"
    "128","82.00","33.57","87.29","82.00","154.88","90.33","82.00","70.71","50.03"
    "256","210.00","83.43","86.13","210.00","195.47","50.03","210.00","194.16","50.03"
    "512","466.00","439.18","50.03"
    "1024","978.00","373.56","85.62","978.00","922.86","50.05","978.00","848.98","50.37"
    "1518","1472.00","546.71","83.86","1472.00","957.08","35.92","1472.00","615.88","23.10"

Table: **CPSW UDP Egress Throughput**
|



.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.20","15.34","18.00","28.87","39.42","18.00","24.93","66.88"
    "128","82.00","6.82","14.90","82.00","125.56","40.90","82.00","113.97","69.07"
    "256","210.00","317.75","41.76","210.00","279.40","69.34"
    "1024","978.00","79.02","5.98","978.00","923.46","72.10"
    "1518","1472.00","121.29","18.44","1472.00","949.86","50.76","1472.00","941.88","60.84"


Table: **CPSW UDP Ingress Throughput (0% loss)**

|



.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","am64xx-evm: Packet Loss %","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: Packet Loss %","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: Packet Loss %"

    "64","18.00","19.17","79.10","60.18","18.00","58.37","73.50","19.11","18.00","24.93","66.88","0.00"
    "128","82.00","86.77","81.76","55.70","82.00","264.26","78.14","18.48","82.00","99.81","63.71","4.56"
    "256","210.00","634.69","78.76","13.63","210.00","279.40","69.34","0.00"
    "1024","978.00","806.82","79.29","0.67","978.00","923.46","72.10","0.00"
    "1518","1472.00","818.05","75.67","4.68","1472.00","949.86","50.76","0.00","1472.00","941.88","60.84","0.00"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|
 
 


CPSW5g/CPSW9g Virtual Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- CPSW5g: J7200
- CPSW9g: J721e


.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW9g-tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.1.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.1.1 -j -c -C -l 60 -t TCP_MAERTS","1845.19","68.50"

Table: **CPSW9g Virtual Ethernet Driver - TCP Bidirectional Throughput**
|




.. rubric::  UDP Throughput 
   :name: CPSW9g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","34.28","87.08"
    "128","82.00","27.16","21.52"
    "256","210.00","255.13","58.96"
    "512","466.00","450.70","50.08"
    "1024","978.00","936.29","51.03"
    "1280","1234.00","949.12","46.67"
    "1518","1472.00","956.93","37.61"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Egress Throughput**
|



.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.71","3.64"
    "128","82.00","11.68","6.75"
    "256","210.00","61.15","14.83"
    "512","466.00","111.09","13.86"
    "1024","978.00","351.29","26.62"
    "1280","1234.00","949.21","62.13"
    "1518","1472.00","957.04","49.77"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Ingress Throughput(0% loss)**

|




.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: Packet Loss %"

    "64","18.00","56.01","72.58","23.42"
    "128","82.00","248.20","74.89","18.26"
    "256","210.00","625.36","77.51","16.44"
    "512","466.00","874.79","74.06","0.08"
    "1024","978.00","936.52","75.65","0.03"
    "1280","1234.00","949.21","62.13","0.00"
    "1518","1472.00","957.04","49.77","0.00"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Ingress Throughput (possible loss)**

|
 
 


CPSW Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput 
   :name: tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","am335x-evm: THROUGHPUT (Mbits/sec)","am335x-evm: CPU Load % (LOCAL_CPU_UTIL)","am43xx-gpevm: THROUGHPUT (Mbits/sec)","am43xx-gpevm: CPU Load % (LOCAL_CPU_UTIL)","am57xx-evm: THROUGHPUT (Mbits/sec)","am57xx-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","391.00","100.00","333.32","100.00","951.88","54.32"

Table: **CPSW TCP Bidirectional Throughput**




 
 
 


PCIe Driver
-------------------------


 


PCIe-NVMe-SSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

AM64xx-EVM
"""""""""""""""""""""""""""




.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","382.00","13.14","398.00","8.02"
    "4m","382.00","12.58","398.00","7.87"
    "4k","81.10","51.49","107.00","47.61"
    "256k","381.00","15.40","397.00","9.78"



- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x1
- SSD being used: Lite-On Technology Corporation M8Pe Series NVMe SSD [14a4:22f1] (rev 01)
 

 


J721E-IDK-GW
"""""""""""""""""""""""""""




.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","718.00","11.19","1523.00","4.23"
    "4m","721.00","11.23","1523.00","3.49"
    "4k","192.00","47.65","167.00","35.89"
    "256k","719.00","10.55","1520.00","7.99"

 

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY
 

 
 
 


NAND Driver
-------------------------




AM335X-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write UBIFS Throughput (Mbytes/sec)","am335x-evm: Write UBIFS CPU Load (%)","am335x-evm: Read UBIFS Throughput (Mbytes/sec)","am335x-evm: Read UBIFS CPU Load (%)"

    "102400","3.96 (min 3.92, max 4.09)","64.09 (min 63.38, max 64.80)","5.28","36.06"
    "262144","3.58 (min 3.55, max 3.64)","63.73 (min 63.29, max 64.36)","5.50","36.96"
    "524288","3.90 (min 3.89, max 3.92)","64.43 (min 63.83, max 65.21)","5.30","35.69"
    "1048576","3.90 (min 3.89, max 3.92)","63.66 (min 63.06, max 65.01)","5.28","35.65"
    "5242880","3.91 (min 3.89, max 3.92)","64.20 (min 63.97, max 64.38)","5.29","35.70"




AM43XX-GPEVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am43xx-gpevm: Write UBIFS Throughput (Mbytes/sec)","am43xx-gpevm: Write UBIFS CPU Load (%)","am43xx-gpevm: Read UBIFS Throughput (Mbytes/sec)","am43xx-gpevm: Read UBIFS CPU Load (%)"

    "102400","6.37 (min 6.18, max 6.81)","68.59 (min 66.02, max 69.57)","10.22","38.99"
    "262144","6.24 (min 6.16, max 6.31)","69.82 (min 69.03, max 70.29)","10.26","38.14"
    "524288","6.26 (min 6.22, max 6.31)","69.53 (min 69.19, max 70.04)","10.24","39.11"
    "1048576","6.26 (min 6.22, max 6.30)","69.47 (min 69.18, max 69.98)","10.21","39.66"
    "5242880","6.24 (min 6.21, max 6.30)","69.63 (min 68.99, max 70.35)","10.26","39.78"





 
 


OSPI Flash Driver
-------------------------


AM64XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^


UBIFS
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write UBIFS Throughput (Mbytes/sec)","am64xx-evm: Write UBIFS CPU Load (%)","am64xx-evm: Read UBIFS Throughput (Mbytes/sec)","am64xx-evm: Read UBIFS CPU Load (%)"

    "102400","0.17 (min 0.12, max 0.28)","47.98 (min 46.88, max 48.81)","62.43","42.86"
    "262144","0.13 (min 0.10, max 0.17)","48.63 (min 48.25, max 49.06)","63.63","40.00"
    "524288","0.13 (min 0.10, max 0.18)","49.20 (min 48.31, max 49.96)","62.68","33.33"
    "1048576","0.13 (min 0.10, max 0.17)","49.36 (min 47.97, max 50.14)","63.22","50.00"




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

    "102400","0.58 (min 0.46, max 1.04)","21.11 (min 20.21, max 22.73)","33.59","8.33"
    "262144","0.41 (min 0.30, max 0.48)","21.64 (min 20.44, max 23.64)","33.48","8.33"
    "524288","0.41 (min 0.29, max 0.50)","21.58 (min 19.98, max 22.90)","33.48","8.33"
    "1048576","0.44 (min 0.33, max 0.49)","21.13 (min 19.26, max 22.11)","33.39","15.38"




RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","j721e-idk-gw: Raw Read Throughput (Mbytes/sec)"

    "50","38.46"

 
 

 

 

 
 

 


UBoot QSPI/OSPI Driver
-------------------------




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","1631.87","37577.98"
    "800000","1634.15","39009.52"
    "1000000","1635.46","39766.99"
    "2000000","1635.78","40255.53"




















 
 

 

 


UBoot UFS Driver
-------------------------
|


J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","97523.81","372363.64"
    "800000","96376.47","481882.35"
    "1000000","96946.75","528516.13"

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

    "1m","58.80","1.00","175.00","0.60"
    "4m","59.20","1.09","175.00","0.42"
    "4k","50.00","21.30","55.80","20.93"
    "256k","58.30","1.19","174.00","1.31"

|



AM64XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","58.00","3.40","313.00","6.65"
    "4m","58.80","2.46","312.00","5.83"
    "4k","55.90","50.73","55.70","48.26"
    "256k","58.10","4.73","313.00","9.47"

|
 
 

 











 
 


UBoot EMMC Driver
-------------------------
|




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "2000000","60907.06","173375.66"
    "4000000","61826.42","177124.32"

|












 
 



SATA Driver
-------------------------



.. rubric::  AM57XX-EVM
   :name: am57xx-evm-sata

|





.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)"

    "102400","121.86 (min 89.84, max 130.44)","9.90 (min 5.82, max 24.17)","133.60","11.54"
    "262144","126.69 (min 118.46, max 129.38)","11.61 (min 6.09, max 32.19)","134.17","11.71"
    "524288","126.32 (min 116.93, max 130.24)","11.40 (min 6.05, max 30.93)","134.03","10.75"
    "1048576","126.67 (min 119.65, max 129.25)","11.60 (min 6.31, max 31.77)","133.74","10.80"
    "5242880","127.08 (min 117.61, max 129.64)","11.24 (min 6.08, max 30.33)","133.89","10.34"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "102400","125.87 (min 124.12, max 129.29)","11.49 (min 7.17, max 27.08)","133.20","10.65"
    "262144","127.07 (min 125.81, max 128.05)","11.55 (min 7.02, max 27.32)","130.24","10.13"
    "524288","124.11 (min 122.95, max 124.97)","11.55 (min 7.57, max 26.44)","129.19","9.79"
    "1048576","124.08 (min 123.55, max 124.79)","10.57 (min 7.17, max 23.22)","129.12","10.04"
    "5242880","123.92 (min 121.87, max 125.60)","11.02 (min 7.41, max 24.51)","128.88","8.61"

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
    :header: "Buffer size (bytes)","am57xx-evm: Write VFAT Throughput (Mbytes/sec)","am57xx-evm: Write VFAT CPU Load (%)","am57xx-evm: Read VFAT Throughput (Mbytes/sec)","am57xx-evm: Read VFAT CPU Load (%)"

    "102400","62.41 (min 52.31, max 65.06)","10.21 (min 7.08, max 21.30)","220.29","20.50"
    "262144","62.23 (min 51.78, max 65.05)","10.52 (min 7.50, max 20.89)","228.85","21.31"
    "524288","62.34 (min 51.82, max 65.20)","10.58 (min 7.85, max 20.92)","241.67","21.89"
    "1048576","62.92 (min 51.74, max 66.16)","10.70 (min 7.37, max 20.88)","246.65","21.92"
    "5242880","62.65 (min 51.64, max 65.75)","10.57 (min 7.61, max 20.87)","243.72","21.22"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)"

    "102400","64.55 (min 63.06, max 65.61)","4.86 (min 2.64, max 12.28)","225.78","18.32"
    "262144","64.89 (min 63.89, max 66.03)","4.61 (min 3.00, max 10.64)","234.40","19.67"
    "524288","64.79 (min 64.32, max 65.50)","4.84 (min 3.16, max 10.79)","249.80","22.06"
    "1048576","65.93 (min 62.13, max 68.10)","4.99 (min 3.18, max 11.42)","260.06","21.05"
    "5242880","65.39 (min 64.03, max 67.35)","4.60 (min 3.14, max 9.33)","265.28","20.40"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "102400","64.78 (min 63.95, max 65.67)","4.85 (min 3.45, max 9.40)","230.42","17.37"
    "262144","65.69 (min 63.86, max 66.93)","4.64 (min 3.89, max 7.45)","237.43","19.20"
    "524288","67.24 (min 63.78, max 73.80)","5.20 (min 3.60, max 10.60)","254.59","20.58"
    "1048576","64.05 (min 63.17, max 64.99)","4.74 (min 3.49, max 9.34)","264.88","16.99"
    "5242880","64.37 (min 63.46, max 65.15)","4.60 (min 3.31, max 8.95)","271.15","22.86"

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

 





 


AM64XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","19.80","1.97","86.10","3.10"
    "4m","19.70","1.43","85.90","2.54"
    "4k","5.21","9.36","16.40","15.89"
    "256k","19.00","2.57","83.30","4.34"

|



 

 





J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","18.80","0.52","43.50","0.31"
    "4m","18.90","0.54","43.40","0.27"
    "4k","4.74","2.66","13.70","5.67"
    "256k","19.10","0.59","42.90","0.52"

|


 
 




AM43XX-GPEVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","am43xx-gpevm: Write EXT4 Throughput (Mbytes/sec)","am43xx-gpevm: Write EXT4 CPU Load (%)","am43xx-gpevm: Read EXT4 Throughput (Mbytes/sec)","am43xx-gpevm: Read EXT4 CPU Load (%)"

    "1m","9.54","3.22","36.30","9.91"
    "4m","9.66","3.08","36.50","9.52"
    "4k","3.00","16.74","8.52","37.21"
    "256k","9.44","3.95","35.90","10.69"

|



AM57XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "1m","15.70","0.95","22.70","0.92"
    "4m","15.00","0.55","22.70","0.71"
    "4k","2.10","2.01","10.80","7.99"
    "256k","16.40","0.66","22.30","0.93"

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

    "400000","15170.37","21557.89"
    "800000","14681.00","22505.49"
    "1000000","16855.97","23011.24"








AM43XX-GPEVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","am43xx-gpevm: Write Throughput (Kbytes/sec)","am43xx-gpevm: Read Throughput (Kbytes/sec)"

    "400000","13128.21","19051.16"
    "800000","14271.78","19320.75"
    "1000000","11932.99","19504.76"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card




AM57XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","am57xx-evm: Write Throughput (Kbytes/sec)","am57xx-evm: Read Throughput (Kbytes/sec)"

    "400000","15515.15","20480.00"
    "800000","11586.99","21557.89"
    "1000000","10382.76","22051.14"


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

    "1m","37.50","5.78","38.60","5.02"
    "4m","37.90","4.99","38.90","4.63"
    "4k","17.60","31.38","17.70","27.90"
    "256k","36.80","8.22","37.60","6.30"

|







J721E-IDK-GW
"""""""""""""""""""""""""""""""
|

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","423.00","7.42","427.00","1.74"
    "4m","402.00","6.41","398.00","2.04"
    "4k","61.40","28.93","61.50","27.34"
    "256k","411.00","8.16","409.00","3.33"

|




 

|
 


USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^










.. csv-table::
    :header: "Number of Blocks","am335x-evm: Throughput (MB/sec)","am43xx-gpevm: Throughput (MB/sec)","am57xx-evm: Throughput (MB/sec)","am64xx-evm: Throughput (MB/sec)","j721e-idk-gw: Throughput (MB/sec)","j721s2-evm: Throughput (MB/sec)"

    "150","18.40","27.90","29.70","42.90","40.00","33.10"

Table: **USBDEVICE HIGHSPEED SLAVE READ THROUGHPUT**

|
|



.. csv-table::
    :header: "Number of Blocks","am335x-evm: Throughput (MB/sec)","am43xx-gpevm: Throughput (MB/sec)","am57xx-evm: Throughput (MB/sec)","am64xx-evm: Throughput (MB/sec)","j721e-idk-gw: Throughput (MB/sec)","j721s2-evm: Throughput (MB/sec)"

    "150","7.30","28.90","34.10","35.10","40.10","30.30"

Table: **USBDEVICE HIGHSPEED SLAVE WRITE THROUGHPUT**

|
|




 
 
 


CRYPTO Driver
-------------------------


OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am335x-evm: throughput (KBytes/Sec)","am57xx-evm: throughput (KBytes/Sec)","am64xx-evm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","11951.45","15162.71","26676.22"
    "aes-128-cbc","16","2244.12","4787.94","471.80"
    "aes-128-cbc","16384","19027.29","35400.36","170175.15"
    "aes-128-cbc","256","4342.36","5261.99","7439.79"
    "aes-128-cbc","64","7720.51","14860.25","1862.42"
    "aes-128-cbc","8192","16422.23","32418.47","126042.11"
    "aes-192-cbc","1024","12137.13","15172.27","26891.95"
    "aes-192-cbc","16","2314.85","4755.16","472.88"
    "aes-192-cbc","16384","18568.53","35400.36","154102.44"
    "aes-192-cbc","256","4103.08","5300.65","7444.05"
    "aes-192-cbc","64","7259.07","14542.93","1880.28"
    "aes-192-cbc","8192","17238.70","32374.78","118022.14"
    "aes-256-cbc","1024","11621.38","14195.03","26321.92"
    "aes-256-cbc","16","2291.91","4735.74","472.73"
    "aes-256-cbc","16384","18508.46","34925.23","145025.71"
    "aes-256-cbc","256","4151.98","4993.79","7415.55"
    "aes-256-cbc","64","7065.24","14100.12","1880.45"
    "aes-256-cbc","8192","16878.25","31735.81","111375.70"
    "des-cbc","1024","18736.81","9410.90","18674.01"
    "des-cbc","16","14756.21","310.05","4000.98"
    "des-cbc","16384","18191.70","16018.09","19830.10"
    "des-cbc","256","17943.89","4062.46","15979.61"
    "des-cbc","64","17629.38","1206.51","9990.68"
    "des-cbc","8192","18841.60","15275.35","19759.10"
    "des3","1024","6455.64","9299.29","7857.49"
    "des3","16","6119.14","317.07","3094.26"
    "des3","16384","6673.75","15657.64","8033.62"
    "des3","256","6648.58","4052.05","7327.40"
    "des3","64","6517.23","1203.75","5752.83"
    "des3","8192","6537.22","14237.70","8017.24"
    "md5","1024","8201.56","10049.54","35903.83"
    "md5","16","470.95","1035.95","784.67"
    "md5","16384","36104.87","65677.99","111230.98"
    "md5","256","3028.99","2848.34","11368.96"
    "md5","64","1917.93","4063.47","3034.71"
    "md5","8192","33431.55","47756.63","97135.27"
    "sha1","1024","7756.12","10084.35","42932.22"
    "sha1","16","455.04","1004.29","745.07"
    "sha1","16384","35722.58","65574.23","273683.80"
    "sha1","256","2911.32","2833.24","11626.75"
    "sha1","64","1827.95","3927.64","2952.83"
    "sha1","8192","33095.68","47920.47","201039.87"
    "sha224","1024","8175.96","9947.48","42698.41"
    "sha224","16","440.38","909.10","740.62"
    "sha224","16384","36459.86","65399.47","279390.89"
    "sha224","256","2873.86","2828.46","11443.71"
    "sha224","64","1626.35","3454.42","2939.01"
    "sha224","8192","32453.97","47652.86","204658.01"
    "sha256","1024","8065.71","9984.34","25620.48"
    "sha256","16","441.24","927.07","427.43"
    "sha256","16384","35170.99","65519.62","220861.78"
    "sha256","256","2830.76","2826.75","6711.72"
    "sha256","64","1674.62","3498.22","1700.65"
    "sha256","8192","32396.63","47770.28","146653.18"
    "sha384","1024","16733.87","10157.06","25275.05"
    "sha384","16","437.67","851.57","708.54"
    "sha384","16384","37453.82","78533.97","53302.61"
    "sha384","256","5769.73","2844.76","9457.66"
    "sha384","64","1787.31","3409.11","2840.70"
    "sha384","8192","34461.01","54149.12","49648.98"
    "sha512","1024","16081.92","10170.71","18292.39"
    "sha512","16","431.02","849.40","419.06"
    "sha512","16384","37218.99","78790.66","50708.48"
    "sha512","256","5985.71","2816.09","6040.32"
    "sha512","64","1792.66","3419.54","1689.39"
    "sha512","8192","33557.16","54255.62","45151.57"


|
|



.. csv-table::
    :header: "Algorithm","am335x-evm: CPU Load","am57xx-evm: CPU Load","am64xx-evm: CPU Load"

    "aes-128-cbc","42.00","40.00","47.00"
    "aes-192-cbc","42.00","40.00","46.00"
    "aes-256-cbc","41.00","44.00","46.00"
    "des-cbc","94.00","12.00","97.00"
    "des3","95.00","11.00","97.00"
    "md5","58.00","50.00","97.00"
    "sha1","58.00","50.00","97.00"
    "sha224","58.00","51.00","97.00"
    "sha256","58.00","50.00","97.00"
    "sha384","94.00","52.00","97.00"
    "sha512","93.00","52.00","97.00"

 

Listed for each algorithm are the code snippets used to run each
  benchmark test.

::
    time -v openssl speed -elapsed -evp aes-128-cbc

 


IPSec Hardware Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Note: queue\_len is set to 300 and software fallback threshold set to 9
to enable software support for optimal performance

.. csv-table::
    :header: "Algorithm","am335x-evm: Throughput (Mbps)","am335x-evm: Packets/Sec","am335x-evm: CPU Load","am43xx-gpevm: Throughput (Mbps)","am43xx-gpevm: Packets/Sec","am43xx-gpevm: CPU Load","am57xx-evm: Throughput (Mbps)","am57xx-evm: Packets/Sec","am57xx-evm: CPU Load"

    "3des","54.80","4.00","55.19"
    "aes128","0.00","0.00","99.44","0.00","0.00","99.39","0.10","0.00","50.00"
    "aes192","0.10","0.00","100.46","6.20","0.00","53.51"
    "aes256","0.20","0.00","100.40","4.10","0.00","52.75"




IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am335x-evm: Throughput (Mbps)","am335x-evm: Packets/Sec","am335x-evm: CPU Load","am43xx-gpevm: Throughput (Mbps)","am43xx-gpevm: Packets/Sec","am43xx-gpevm: CPU Load","am57xx-evm: Throughput (Mbps)","am57xx-evm: Packets/Sec","am57xx-evm: CPU Load","j721e-idk-gw: Throughput (Mbps)","j721e-idk-gw: Packets/Sec","j721e-idk-gw: CPU Load"

    "3des","235.20","20.00","37.13"
    "aes128","0.60","0.00","101.49","1.40","0.00","100.00","6.50","0.00","50.35","780.50","69.00","56.38"
    "aes192","1.10","0.00","100.65","1.40","0.00","100.00","194.20","17.00","53.29","696.90","62.00","56.49"
    "aes256","1.40","0.00","98.45","1.40","0.00","100.01","5.40","0.00","50.36","772.60","68.00","56.31"

 
 

DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.



