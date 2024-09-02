
======================================
 Linux 10.00 Performance Guide
======================================

.. rubric::  **Read This First**
   :name: read-this-first-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| AM68 SK        | AM68 SK Evaluation Module  with ARM running at 2GHz, DDR data rate 2666 MT/S, L3 Cache size 3MB                |
+----------------+----------------------------------------------------------------------------------------------------------------+
| AM69 SK        | AM69 SK Evaluation Module  with ARM running at 2GHz, DDR data rate 2666 MT/S, L3 Cache size 3MB                |
+----------------+----------------------------------------------------------------------------------------------------------------+
| J721e EVM      | J721e Evaluation Module rev E2 with ARM running at 2GHz, DDR data rate 4266 MT/S, L3 Cache size 3MB            |
+----------------+----------------------------------------------------------------------------------------------------------------+
| J7200 EVM      | J7200 Evaluation Module rev E1 with ARM running at 2GHz, DDR data rate 2666 MT/S, L3 Cache size 3MB            |
+----------------+----------------------------------------------------------------------------------------------------------------+
| J721S2 EVM     | J721S2 Evaluation Module rev E2 with ARM running at 2GHz, DDR data rate 2666 MT/S, L3 Cache size 3MB           |
+----------------+----------------------------------------------------------------------------------------------------------------+
| J784S4 EVM     | J784S4 Evaluation Module Beta rev E1 with ARM running at 2GHz, DDR data rate 2666 MT/S, L3 Cache size 1MB      |
+----------------+----------------------------------------------------------------------------------------------------------------+
| J722S EVM      | J722S Evaluation Module rev E1 with ARM running at 1.4GHz, DDR data rate 3200 MT/S                             |
+----------------+----------------------------------------------------------------------------------------------------------------+

Table:  Evaluation Modules

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

.. csv-table:: LMBench Benchmarks
    :header: "Benchmarks","am68_sk-fs: perf","am69_sk-fs: perf","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j722s_evm-fs: perf","j784s4-evm: perf"

    "af_unix_sock_stream_latency (microsec)","17.02","18.55","16.98","20.90","16.84","29.12","15.99"
    "af_unix_socket_stream_bandwidth (MBs)","2277.72","3801.82","1732.01","2096.54","1623.67","1112.48","3790.06"
    "bw_file_rd-io-1mb (MB/s)","3078.59","3391.18","3118.69","3108.00","1769.91","1219.09","3625.82"
    "bw_file_rd-o2c-1mb (MB/s)","1590.11","336.98","1431.64","1656.54","903.02","672.27","1978.42"
    "bw_mem-bcopy-16mb (MB/s)","3808.62","2760.05","2303.48","2821.87","3657.14","1767.57","3350.79"
    "bw_mem-bcopy-1mb (MB/s)","4532.27","9665.57","3361.05","4702.78","0.00","1862.89","9194.56"
    "bw_mem-bcopy-2mb (MB/s)","4019.73","3869.83","2472.19","3911.11","3803.73","1419.65","4642.03"
    "bw_mem-bcopy-4mb (MB/s)","3875.97","3255.74","2367.56","3836.56","3724.39","1641.14","4054.74"
    "bw_mem-bcopy-8mb (MB/s)","3819.22","2895.40","2373.89","3034.13","3661.33","1741.78","3520.61"
    "bw_mem-bzero-16mb (MB/s)","10910.33","10867.72","2341.24","9625.51","10723.86","6613.39","10830.94"
    "bw_mem-bzero-1mb (MB/s)","8769.03 (min 4532.27, max 13005.78)","11702.73 (min 9665.57, max 13739.88)","4067.16 (min 3361.05, max 4773.27)","8654.31 (min 4702.78, max 12605.83)","6534.09 (min 0.00, max 13068.18)","4236.79 (min 1862.89, max 6610.68)","11470.13 (min 9194.56, max 13745.70)"
    "bw_mem-bzero-2mb (MB/s)","7864.45 (min 4019.73, max 11709.16)","8779.30 (min 3869.83, max 13688.76)","2682.75 (min 2472.19, max 2893.31)","8044.38 (min 3911.11, max 12177.65)","7657.53 (min 3803.73, max 11511.33)","4009.01 (min 1419.65, max 6598.37)","9146.96 (min 4642.03, max 13651.88)"
    "bw_mem-bzero-4mb (MB/s)","7442.57 (min 3875.97, max 11009.17)","7769.49 (min 3255.74, max 12283.24)","2413.61 (min 2367.56, max 2459.65)","7896.83 (min 3836.56, max 11957.10)","7254.00 (min 3724.39, max 10783.61)","4124.17 (min 1641.14, max 6607.20)","8153.50 (min 4054.74, max 12252.25)"
    "bw_mem-bzero-8mb (MB/s)","7386.25 (min 3819.22, max 10953.28)","7105.41 (min 2895.40, max 11315.42)","2365.67 (min 2357.45, max 2373.89)","7350.10 (min 3034.13, max 11666.06)","7210.63 (min 3661.33, max 10759.92)","4176.13 (min 1741.78, max 6610.48)","7394.11 (min 3520.61, max 11267.61)"
    "bw_mem-cp-16mb (MB/s)","2187.88","2173.03","991.14","1539.94","2165.09","865.57","2287.35"
    "bw_mem-cp-1mb (MB/s)","7803.00 (min 2493.77, max 13112.23)","8499.05 (min 3276.30, max 13721.80)","3100.37 (min 1299.67, max 4901.07)","6865.64 (min 1727.41, max 12003.87)","7630.47 (min 2269.29, max 12991.64)","3878.60 (min 851.64, max 6905.56)","8589.29 (min 3457.69, max 13720.89)"
    "bw_mem-cp-2mb (MB/s)","6955.46 (min 2181.82, max 11729.10)","8081.78 (min 2487.12, max 13676.44)","1973.17 (min 1021.28, max 2925.05)","6874.44 (min 1534.04, max 12214.84)","6863.59 (min 2211.57, max 11515.60)","3802.14 (min 864.30, max 6739.98)","8117.97 (min 2608.53, max 13627.40)"
    "bw_mem-cp-4mb (MB/s)","6580.87 (min 2154.59, max 11007.15)","7386.96 (min 2521.67, max 12252.25)","1725.21 (min 982.80, max 2467.61)","6752.79 (min 1574.18, max 11931.39)","6490.34 (min 2140.56, max 10840.11)","3772.27 (min 885.64, max 6658.90)","7474.40 (min 2703.16, max 12245.63)"
    "bw_mem-cp-8mb (MB/s)","6553.66 (min 2157.79, max 10949.53)","6746.80 (min 2216.07, max 11277.53)","1675.09 (min 989.24, max 2360.93)","6565.63 (min 1426.79, max 11704.46)","6428.27 (min 2151.12, max 10705.41)","3780.48 (min 909.81, max 6651.15)","6824.72 (min 2353.98, max 11295.45)"
    "bw_mem-fcp-16mb (MB/s)","3782.06","2699.06","2392.70","2780.67","3623.60","1614.21","3347.63"
    "bw_mem-fcp-1mb (MB/s)","8461.76 (min 3917.73, max 13005.78)","10141.48 (min 6543.08, max 13739.88)","4056.23 (min 3339.19, max 4773.27)","8259.17 (min 3912.50, max 12605.83)","8490.27 (min 3912.36, max 13068.18)","4082.14 (min 1553.60, max 6610.68)","10150.62 (min 6555.53, max 13745.70)"
    "bw_mem-fcp-2mb (MB/s)","7815.37 (min 3921.57, max 11709.16)","8602.47 (min 3516.17, max 13688.76)","2703.39 (min 2513.46, max 2893.31)","8031.95 (min 3886.24, max 12177.65)","7636.78 (min 3762.23, max 11511.33)","4044.07 (min 1489.76, max 6598.37)","8680.54 (min 3709.20, max 13651.88)"
    "bw_mem-fcp-4mb (MB/s)","7425.82 (min 3842.46, max 11009.17)","7707.18 (min 3131.12, max 12283.24)","2422.43 (min 2385.21, max 2459.65)","7912.79 (min 3868.47, max 11957.10)","5391.81 (min 0.00, max 10783.61)","4099.31 (min 1591.41, max 6607.20)","8013.63 (min 3775.01, max 12252.25)"
    "bw_mem-fcp-8mb (MB/s)","7375.38 (min 3797.47, max 10953.28)","7061.47 (min 2807.51, max 11315.42)","2373.11 (min 2357.45, max 2388.77)","7305.52 (min 2944.97, max 11666.06)","7196.22 (min 3632.51, max 10759.92)","4110.40 (min 1610.31, max 6610.48)","7358.19 (min 3448.77, max 11267.61)"
    "bw_mem-frd-16mb (MB/s)","4723.25","3185.98","6331.62","4791.14","4371.58","1780.94","3924.45"
    "bw_mem-frd-1mb (MB/s)","4567.56 (min 3917.73, max 5217.39)","7152.53 (min 6543.08, max 7761.97)","4948.59 (min 3339.19, max 6557.99)","4668.19 (min 3912.50, max 5423.87)","4470.69 (min 3912.36, max 5029.01)","1728.64 (min 1553.60, max 1903.67)","6986.83 (min 6555.53, max 7418.13)"
    "bw_mem-frd-2mb (MB/s)","4567.86 (min 3921.57, max 5214.15)","3662.85 (min 3516.17, max 3809.52)","4468.72 (min 2513.46, max 6423.98)","4858.57 (min 3886.24, max 5830.90)","4288.52 (min 3762.23, max 4814.81)","1514.59 (min 1489.76, max 1539.41)","4108.12 (min 3709.20, max 4507.04)"
    "bw_mem-frd-4mb (MB/s)","4300.57 (min 3842.46, max 4758.67)","3358.32 (min 3131.12, max 3585.51)","4357.16 (min 2385.21, max 6329.11)","4759.10 (min 3868.47, max 5649.72)","2209.60 (min 0.00, max 4419.19)","1635.10 (min 1591.41, max 1678.79)","4029.60 (min 3775.01, max 4284.18)"
    "bw_mem-frd-8mb (MB/s)","4258.27 (min 3797.47, max 4719.07)","3182.59 (min 2807.51, max 3557.66)","4347.97 (min 2388.77, max 6307.16)","4185.27 (min 2944.97, max 5425.57)","3989.78 (min 3632.51, max 4347.04)","1692.86 (min 1610.31, max 1775.41)","3863.04 (min 3448.77, max 4277.31)"
    "bw_mem-fwr-16mb (MB/s)","10921.50","10825.44","2347.42","9663.29","10731.05","6632.58","10871.41"
    "bw_mem-fwr-1mb (MB/s)","9164.81 (min 5217.39, max 13112.23)","10741.89 (min 7761.97, max 13721.80)","5729.53 (min 4901.07, max 6557.99)","8713.87 (min 5423.87, max 12003.87)","9010.33 (min 5029.01, max 12991.64)","4404.62 (min 1903.67, max 6905.56)","10569.51 (min 7418.13, max 13720.89)"
    "bw_mem-fwr-2mb (MB/s)","8471.63 (min 5214.15, max 11729.10)","8742.98 (min 3809.52, max 13676.44)","4674.52 (min 2925.05, max 6423.98)","9022.87 (min 5830.90, max 12214.84)","8165.21 (min 4814.81, max 11515.60)","4139.70 (min 1539.41, max 6739.98)","9067.22 (min 4507.04, max 13627.40)"
    "bw_mem-fwr-4mb (MB/s)","7882.91 (min 4758.67, max 11007.15)","7918.88 (min 3585.51, max 12252.25)","4398.36 (min 2467.61, max 6329.11)","8790.56 (min 5649.72, max 11931.39)","7629.65 (min 4419.19, max 10840.11)","4168.85 (min 1678.79, max 6658.90)","8264.91 (min 4284.18, max 12245.63)"
    "bw_mem-fwr-8mb (MB/s)","7834.30 (min 4719.07, max 10949.53)","7417.60 (min 3557.66, max 11277.53)","4334.05 (min 2360.93, max 6307.16)","8565.02 (min 5425.57, max 11704.46)","7526.23 (min 4347.04, max 10705.41)","4213.28 (min 1775.41, max 6651.15)","7786.38 (min 4277.31, max 11295.45)"
    "bw_mem-rd-16mb (MB/s)","5473.83","3782.95","6580.75","5074.53","5091.49","1847.36","4700.35"
    "bw_mem-rd-1mb (MB/s)","6343.94 (min 4313.58, max 8374.29)","16452.23 (min 15613.38, max 17291.07)","7864.06 (min 5708.85, max 10019.27)","6053.34 (min 3564.43, max 8542.25)","9838.90 (min 9415.53, max 10262.26)","1868.11 (min 1652.89, max 2083.33)","16188.05 (min 15072.57, max 17303.53)"
    "bw_mem-rd-2mb (MB/s)","4576.04 (min 2875.11, max 6276.97)","4825.11 (min 2863.28, max 6786.93)","4032.28 (min 978.63, max 7085.92)","4186.02 (min 1878.52, max 6493.51)","4572.41 (min 3348.84, max 5795.98)","1718.56 (min 1603.59, max 1833.52)","5372.66 (min 4173.19, max 6572.12)"
    "bw_mem-rd-4mb (MB/s)","3995.93 (min 2406.38, max 5585.48)","3711.54 (min 3454.83, max 3968.25)","3729.74 (min 786.63, max 6672.85)","3753.04 (min 1353.41, max 6152.66)","3762.18 (min 2384.86, max 5139.50)","1752.72 (min 1662.97, max 1842.47)","4455.07 (min 3661.66, max 5248.48)"
    "bw_mem-rd-8mb (MB/s)","3885.18 (min 2289.97, max 5480.39)","3613.50 (min 3216.30, max 4010.70)","3661.86 (min 748.01, max 6575.70)","4028.04 (min 2116.96, max 5939.12)","3677.96 (min 2252.25, max 5103.67)","1778.05 (min 1725.44, max 1830.66)","4393.23 (min 3544.00, max 5242.46)"
    "bw_mem-rdwr-16mb (MB/s)","2265.01","2379.54","752.41","1852.28","2202.34","1769.13","2606.71"
    "bw_mem-rdwr-1mb (MB/s)","3248.79 (min 2493.77, max 4003.81)","6292.65 (min 3276.30, max 9308.99)","3411.76 (min 1299.67, max 5523.84)","2536.54 (min 1727.41, max 3345.66)","3345.08 (min 2269.29, max 4420.87)","1252.42 (min 851.64, max 1653.20)","6387.81 (min 3457.69, max 9317.93)"
    "bw_mem-rdwr-2mb (MB/s)","2532.61 (min 2181.82, max 2883.40)","3334.82 (min 2487.12, max 4182.51)","1003.82 (min 986.36, max 1021.28)","1518.79 (min 1503.53, max 1534.04)","2661.60 (min 2211.57, max 3111.63)","1165.69 (min 864.30, max 1467.08)","3200.49 (min 2608.53, max 3792.45)"
    "bw_mem-rdwr-4mb (MB/s)","2298.30 (min 2154.59, max 2442.00)","2735.22 (min 2521.67, max 2948.77)","888.39 (min 793.97, max 982.80)","1982.19 (min 1574.18, max 2390.20)","2242.62 (min 2140.56, max 2344.67)","1256.16 (min 885.64, max 1626.68)","2952.35 (min 2703.16, max 3201.54)"
    "bw_mem-rdwr-8mb (MB/s)","2232.22 (min 2157.79, max 2306.64)","2526.23 (min 2216.07, max 2836.38)","873.81 (min 758.37, max 989.24)","1908.50 (min 1426.79, max 2390.20)","2187.91 (min 2151.12, max 2224.69)","1312.36 (min 909.81, max 1714.90)","2742.96 (min 2353.98, max 3131.93)"
    "bw_mem-wr-16mb (MB/s)","2273.05","2763.39","744.60","1764.64","2210.25","1750.74","2844.95"
    "bw_mem-wr-1mb (MB/s)","4158.70 (min 4003.81, max 4313.58)","13300.03 (min 9308.99, max 17291.07)","5616.35 (min 5523.84, max 5708.85)","3455.05 (min 3345.66, max 3564.43)","6918.20 (min 4420.87, max 9415.53)","1653.05 (min 1652.89, max 1653.20)","13310.73 (min 9317.93, max 17303.53)"
    "bw_mem-wr-2mb (MB/s)","2879.26 (min 2875.11, max 2883.40)","3522.90 (min 2863.28, max 4182.51)","982.50 (min 978.63, max 986.36)","1691.03 (min 1503.53, max 1878.52)","3230.24 (min 3111.63, max 3348.84)","1535.34 (min 1467.08, max 1603.59)","3982.82 (min 3792.45, max 4173.19)"
    "bw_mem-wr-4mb (MB/s)","2424.19 (min 2406.38, max 2442.00)","3201.80 (min 2948.77, max 3454.83)","790.30 (min 786.63, max 793.97)","1871.81 (min 1353.41, max 2390.20)","2364.77 (min 2344.67, max 2384.86)","1644.83 (min 1626.68, max 1662.97)","3431.60 (min 3201.54, max 3661.66)"
    "bw_mem-wr-8mb (MB/s)","2298.31 (min 2289.97, max 2306.64)","3026.34 (min 2836.38, max 3216.30)","753.19 (min 748.01, max 758.37)","2253.58 (min 2116.96, max 2390.20)","2238.47 (min 2224.69, max 2252.25)","1720.17 (min 1714.90, max 1725.44)","3337.97 (min 3131.93, max 3544.00)"
    "bw_mmap_rd-mo-1mb (MB/s)","6248.30","12913.32","12254.46","8898.78","6253.45","2041.20","12916.91"
    "bw_mmap_rd-o2c-1mb (MB/s)","1422.22","321.34","1533.22","1381.76","1131.86","632.51","2202.64"
    "bw_pipe (MB/s)","950.73","874.64","743.85","875.38","902.35","719.06","987.48"
    "bw_unix (MB/s)","2277.72","3801.82","1732.01","2096.54","1623.67","1112.48","3790.06"
    "lat_connect (us)","33.11","32.95","32.71","33.09","34.04","56.52","33.10"
    "lat_ctx-2-128k (us)","3.80","3.69","3.81","3.82","3.73","7.18","6.20"
    "lat_ctx-2-256k (us)","2.98","2.84","2.94","3.02","2.90","5.54","2.89"
    "lat_ctx-4-128k (us)","3.42","4.79","3.49","3.50","3.45","6.44","4.69"
    "lat_ctx-4-256k (us)","2.59","3.26","2.33","2.42","2.55","5.04","2.03"
    "lat_fs-0k (num_files)","542.00","517.00","537.00","508.00","520.00","269.00","491.00"
    "lat_fs-10k (num_files)","197.00","204.00","176.00","178.00","177.00","131.00","224.00"
    "lat_fs-1k (num_files)","276.00","274.00","247.00","247.00","241.00","167.00","285.00"
    "lat_fs-4k (num_files)","268.00","302.00","280.00","261.00","259.00","177.00","318.00"
    "lat_mem_rd-stride128-sz1000k (ns)","11.35","5.84","12.13","10.98","13.11","32.94","5.99"
    "lat_mem_rd-stride128-sz125k (ns)","5.57","5.65","5.57","5.57","5.57","6.25","5.65"
    "lat_mem_rd-stride128-sz250k (ns)","5.57","5.65","5.57","5.57","5.57","6.55","5.65"
    "lat_mem_rd-stride128-sz31k (ns)","3.35","3.37","3.36","3.34","3.80","2.42","3.82"
    "lat_mem_rd-stride128-sz50 (ns)","2.00","2.00","2.00","2.00","2.00","2.40","2.00"
    "lat_mem_rd-stride128-sz500k (ns)","5.57","5.65","5.57","6.27","5.57","11.65","5.65"
    "lat_mem_rd-stride128-sz62k (ns)","5.57","5.65","5.57","5.57","5.12","5.88","5.19"
    "lat_mmap-1m (us)","39.00","30.00","29.00","37.00","30.00","67.00","36.00"
    "lat_ops-double-add (ns)","1.96","1.96","1.96","1.96","1.96","3.21","1.96"
    "lat_ops-double-div (ns)","9.01","9.01","9.01","9.01","9.01","17.63","9.01"
    "lat_ops-double-mul (ns)","2.00","2.00","2.00","2.00","2.00","3.20","2.00"
    "lat_ops-float-add (ns)","1.96","1.96","1.96","1.96","1.96","3.20","1.96"
    "lat_ops-float-div (ns)","5.51","5.50","5.51","5.51","5.51","10.41","5.51"
    "lat_ops-float-mul (ns)","2.00","2.00","2.00","2.00","2.00","3.20","2.00"
    "lat_ops-int-add (ns)","0.50","0.50","0.50","0.50","0.50","0.80","0.50"
    "lat_ops-int-bit (ns)","0.33","0.33","0.33","0.33","0.33","0.53","0.33"
    "lat_ops-int-div (ns)","4.01","4.00","4.00","4.00","4.00","4.81","4.00"
    "lat_ops-int-mod (ns)","4.67","4.67","4.67","4.67","4.67","5.08","4.67"
    "lat_ops-int-mul (ns)","1.52","1.52","1.52","1.52","1.52","3.45","1.52"
    "lat_ops-int64-add (ns)","0.50","0.50","0.50","0.50","0.50","0.80","0.50"
    "lat_ops-int64-bit (ns)","0.33","0.33","0.33","0.33","0.33","0.53","0.33"
    "lat_ops-int64-div (ns)","3.00","3.00","3.00","3.00","3.00","7.62","3.00"
    "lat_ops-int64-mod (ns)","5.67","5.67","5.67","5.67","5.68","5.88","5.67"
    "lat_ops-int64-mul (ns)","2.52","2.52","2.52","2.52","2.52","3.98","2.52"
    "lat_pagefault (us)","0.61","0.60","0.61","0.59","0.63","1.42","0.61"
    "lat_pipe (us)","13.04","18.59","13.19","13.02","12.89","24.52","19.32"
    "lat_proc-exec (us)","471.92","471.82","484.09","434.79","482.73","888.50","457.21"
    "lat_proc-fork (us)","375.71","381.57","380.92","354.13","395.23","677.50","385.69"
    "lat_proc-proccall (us)","0.00","0.00","0.00","0.00","0.00","0.01","0.00"
    "lat_select (us)","13.86","13.65","13.88","12.30","13.61","40.42","13.64"
    "lat_sem (us)","1.52","1.65","1.56","1.44","1.47","2.10","1.54"
    "lat_sig-catch (us)","3.36","2.79","2.81","2.84","2.82","6.06","2.82"
    "lat_sig-install (us)","0.51","0.52","0.51","0.51","0.53","0.73","0.53"
    "lat_sig-prot (us)","0.57","0.61","0.52","0.57","0.59","0.98","0.54"
    "lat_syscall-fstat (us)","0.79","0.81","0.79","0.81","0.80","1.88","0.83"
    "lat_syscall-null (us)","0.36","0.39","0.38","0.38","0.37","0.52","0.38"
    "lat_syscall-open (us)","95.54","3979.00","151.94","138.88","150.62","154.73","116.19"
    "lat_syscall-read (us)","0.49","0.48","0.52","0.49","0.50","0.86","0.51"
    "lat_syscall-stat (us)","1.84","1.87","1.88","1.84","1.85","4.53","1.87"
    "lat_syscall-write (us)","0.44","0.47","0.47","0.45","0.47","0.76","0.46"
    "lat_tcp (us)","0.80","0.79","0.79","0.77","0.78","1.05","0.79"
    "lat_unix (us)","17.02","18.55","16.98","20.90","16.84","29.12","15.99"
    "latency_for_0.50_mb_block_size (nanosec)","5.57","5.65","5.57","6.27","5.57","11.65","5.65"
    "latency_for_1.00_mb_block_size (nanosec)","5.68 (min 0.00, max 11.35)","2.92 (min 0.00, max 5.84)","6.06 (min 0.00, max 12.13)","5.49 (min 0.00, max 10.98)","6.55 (min 0.00, max 13.11)","16.47 (min 0.00, max 32.94)","2.99 (min 0.00, max 5.99)"
    "pipe_bandwidth (MBs)","950.73","874.64","743.85","875.38","902.35","719.06","987.48"
    "pipe_latency (microsec)","13.04","18.59","13.19","13.02","12.89","24.52","19.32"
    "procedure_call (microsec)","0.00","0.00","0.00","0.00","0.00","0.01","0.00"
    "select_on_200_tcp_fds (microsec)","13.86","13.65","13.88","12.30","13.61","40.42","13.64"
    "semaphore_latency (microsec)","1.52","1.65","1.56","1.44","1.47","2.10","1.54"
    "signal_handler_latency (microsec)","0.51","0.52","0.51","0.51","0.53","0.73","0.53"
    "signal_handler_overhead (microsec)","3.36","2.79","2.81","2.84","2.82","6.06","2.82"
    "tcp_ip_connection_cost_to_localhost (microsec)","33.11","32.95","32.71","33.09","34.04","56.52","33.10"
    "tcp_latency_using_localhost (microsec)","0.80","0.79","0.79","0.77","0.78","1.05","0.79"




Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed.

Please take note, different run may produce different slightly results.
This is advised to run this test multiple times in order to get maximum 
performance numbers.


Execute the benchmark with the following:

::

    runDhrystone

.. csv-table:: Dhrystone Benchmarks
    :header: "Benchmarks","am68_sk-fs: perf","am69_sk-fs: perf","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j722s_evm-fs: perf","j784s4-evm: perf"

    "cpu_clock (MHz)","2000.00","2000.00","2000.00","2000.00","2000.00","1250.00","2000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","5.70","5.20","4.40","5.70","5.70","2.90","5.70"
    "dhrystone_per_second (DhrystoneP)","20000000.00","18181818.00","15384615.00","20000000.00","20000000.00","6451613.00","20000000.00"




Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Whetstone is a benchmark primarily measuring floating-point arithmetic performance.

Execute the benchmark with the following:

::

    runWhetstone

.. csv-table:: Whetstone Benchmarks
    :header: "Benchmarks","am68_sk-fs: perf","am69_sk-fs: perf","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j722s_evm-fs: perf","j784s4-evm: perf"

    "whetstone (MIPS)","10000.00","10000.00","10000.00","10000.00","10000.00","5000.00","10000.00"




Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table:: Linpack Benchmarks
    :header: "Benchmarks","am68_sk-fs: perf","am69_sk-fs: perf","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j722s_evm-fs: perf","j784s4-evm: perf"

    "linpack (Kflops)","2610899.00","2462937.00","2498787.00","2521729.00","2437582.00","513511.00","2369450.00"




NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html

.. csv-table:: NBench Benchmarks
    :header: "Benchmarks","am68_sk-fs: perf","am69_sk-fs: perf","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j784s4-evm: perf"

    "assignment (Iterations)","31.83","31.91","31.95","31.88","31.85","31.87"
    "fourier (Iterations)","59979.00","52980.00","64632.00","52970.00","59190.00","60010.00"
    "fp_emulation (Iterations)","387.90","387.97","388.00","387.97","387.96","388.01"
    "huffman (Iterations)","2489.50","2488.50","2495.30","2486.00","2483.00","2494.30"
    "idea (Iterations)","7996.70","7996.70","7996.90","7996.90","7996.60","7996.70"
    "lu_decomposition (Iterations)","1381.10","1357.80","1389.80","1391.90","1374.60","1367.40"
    "neural_net (Iterations)","28.68","28.98","28.73","28.76","26.56","28.74"
    "numeric_sort (Iterations)","880.44","875.30","886.93","886.54","875.82","878.29"
    "string_sort (Iterations)","352.29","350.41","358.20","353.73","358.21","353.69"




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

.. csv-table:: Stream Benchmarks
    :header: "Benchmarks","am68_sk-fs: perf","am69_sk-fs: perf","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j722s_evm-fs: perf","j784s4-evm: perf"

    "add (MB/s)","6470.90","5696.10","5458.60","5287.90","6176.60","2416.20","5752.90"
    "copy (MB/s)","6987.50","5577.80","4780.10","5534.10","6894.20","3592.40","5493.60"
    "scale (MB/s)","7123.10","5551.50","4836.20","5407.60","7012.90","3144.20","5484.50"
    "triad (MB/s)","6477.20","5692.20","5461.10","5265.90","6173.60","2163.80","5751.70"




CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.


.. csv-table:: CoreMarkPro Benchmarks
    :header: "Benchmarks","am68_sk-fs: perf","am69_sk-fs: perf","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j722s_evm-fs: perf","j784s4-evm: perf"

    "cjpeg-rose7-preset (workloads/)","82.64","83.33","81.97","81.97","81.97","37.59","80.65"
    "core (workloads/)","0.78","0.78","0.78","0.78","0.78","0.27","0.78"
    "coremark-pro ()","2510.01","2533.76","2484.51","2518.11","2499.84","830.90","2511.93"
    "linear_alg-mid-100x100-sp (workloads/)","80.39","82.24","79.62","80.39","80.26","13.12","81.70"
    "loops-all-mid-10k-sp (workloads/)","2.48","2.46","2.47","2.47","2.47","0.64","2.47"
    "nnet_test (workloads/)","3.64","3.68","3.68","3.67","3.68","0.97","3.63"
    "parser-125k (workloads/)","11.11","10.87","11.11","11.24","11.11","7.94","10.87"
    "radix2-big-64k (workloads/)","285.06","306.56","262.88","291.21","275.63","55.79","297.80"
    "sha-test (workloads/)","158.73","158.73","158.73","158.73","158.73","72.99","158.73"
    "zip-test (workloads/)","47.62","47.62","47.62","47.62","47.62","20.00","47.62"



 
 


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

.. csv-table:: Multibench Benchmarks
    :header: "Benchmarks","am68_sk-fs: perf","am69_sk-fs: perf","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j722s_evm-fs: perf","j784s4-evm: perf"

    "4m-check (workloads/)","843.17","1021.24","896.70","876.89","858.52","381.56","1020.41"
    "4m-check-reassembly (workloads/)","149.03","184.84","119.90","145.99","143.68","113.51","185.53"
    "4m-check-reassembly-tcp (workloads/)","95.06","105.04","92.25","98.81","93.28","54.35","107.30"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","42.58","37.55","40.90","45.11","40.93","29.70","39.14"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","2.68","4.62","2.69","2.71","2.65","1.73","4.72"
    "4m-cmykw2 (workloads/)","313.97","607.90","313.97","315.46","312.99","217.16","607.90"
    "4m-cmykw2-rotatew2 (workloads/)","60.48","43.38","59.00","63.63","59.82","44.98","47.51"
    "4m-reassembly (workloads/)","124.22","131.58","105.26","130.21","119.33","76.05","130.38"
    "4m-rotatew2 (workloads/)","70.57","45.75","70.13","73.15","69.49","48.59","51.39"
    "4m-tcp-mixed (workloads/)","262.30","262.30","266.67","271.19","262.30","107.38","246.15"
    "4m-x264w2 (workloads/)","2.75","4.94","2.78","2.74","2.73","1.75","5.07"
    "empty-wld (workloads/)","1.00","","","","","1.00",""
    "idct-4m (workloads/)","34.84","35.11","34.93","35.08","34.70","17.23","35.10"
    "idct-4mw1 (workloads/)","34.73","35.15","34.90","35.08","34.94","17.24","35.12"
    "ippktcheck-4m (workloads/)","840.90","1025.01","875.35","877.81","838.08","381.45","991.28"
    "ippktcheck-4mw1 (workloads/)","844.60","1026.27","896.38","903.51","829.74","381.16","1017.50"
    "ipres-4m (workloads/)","167.41","174.83","158.90","182.26","163.76","102.74","182.48"
    "ipres-4mw1 (workloads/)","166.48","174.22","156.90","181.60","162.87","103.02","182.26"
    "md5-4m (workloads/)","46.21","47.04","46.15","49.63","45.91","26.03","46.97"
    "md5-4mw1 (workloads/)","46.06","47.33","45.64","49.51","46.08","26.22","47.13"
    "rgbcmyk-4m (workloads/)","162.87","163.27","163.27","163.67","162.87","56.05","163.93"
    "rgbcmyk-4mw1 (workloads/)","162.73","164.07","163.00","163.80","162.73","56.02","164.07"
    "rotate-4ms1 (workloads/)","51.23","53.48","51.44","54.05","50.71","21.55","53.19"
    "rotate-4ms1w1 (workloads/)","51.07","53.42","51.02","53.42","50.61","21.51","53.30"
    "rotate-4ms64 (workloads/)","52.19","54.76","52.63","55.37","52.30","21.73","54.95"
    "rotate-4ms64w1 (workloads/)","52.58","54.88","52.58","55.74","52.47","21.75","54.95"
    "x264-4mq (workloads/)","1.42","1.40","1.42","1.43","1.41","0.52","1.42"
    "x264-4mqw1 (workloads/)","1.42","1.42","1.43","1.42","1.41","0.52","1.42"



 
 



|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: Boot time MMCSD
    :header: "Boot Configuration","am68_sk-fs: boot time (sec)","am69_sk-fs: boot time (sec)","j7200-evm: boot time (sec)","j721e-idk-gw: boot time (sec)","j721s2-evm: boot time (sec)","j722s_evm-fs: boot time (sec)","j784s4-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","15.61 (min 15.47, max 15.68)","19.95 (min 19.77, max 20.09)","15.05 (min 14.74, max 15.35)","20.59 (min 20.15, max 21.06)","16.94 (min 16.76, max 17.12)","17.51 (min 16.33, max 17.93)","18.90 (min 18.42, max 19.59)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","5.81 (min 5.77, max 5.85)","10.68 (min 10.64, max 10.69)","5.65 (min 5.62, max 5.69)","9.07 (min 9.03, max 9.10)","5.67 (min 5.63, max 5.74)","5.12 (min 5.11, max 5.13)","9.27 (min 9.22, max 9.33)"



 
 



|

ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64


.. csv-table:: Audio Capture
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)","j722s_evm-fs: Throughput (bits/sec)","j722s_evm-fs: CPU Load (%)"

    "8000","","","255987.00","0.35"
    "11025","352792.00","0.16","331809.00","0.38"
    "16000","511991.00","0.29","511976.00","0.44"
    "22050","705576.00","0.26","663630.00","0.50"
    "24000","705584.00","0.27","663610.00","0.49"
    "32000","1023981.00","0.18","1023923.00","0.57"
    "44100","1411175.00","0.51","1327224.00","0.65"
    "48000","1535974.00","0.62","1535905.00","0.68"
    "88200","2822350.00","0.78","2654467.00","1.01"
    "96000","3071874.00","1.04","3071822.00","1.08"




.. csv-table:: Audio Playback
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "11025","352938.00","0.16"
    "16000","512203.00","0.28"
    "22050","705866.00","0.26"
    "24000","705873.00","0.26"
    "32000","1024402.00","0.37"
    "44100","1411756.00","0.45"
    "48000","1536606.00","0.66"
    "88200","2823512.00","0.86"
    "96000","3073211.00","0.41"

 
 



 



|

Graphics SGX/RGX Driver
-------------------------
 


GFXBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Run GFXBench and capture performance reported (Score and Display rate in fps). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table:: GFXBench Performance
    :header: "Benchmark","am68_sk-fs: Score","am68_sk-fs: Fps","j721s2-evm: Score","j721s2-evm: Fps","j784s4-evm: Score","j784s4-evm: Fps"

    " GFXBench 3.x gl_manhattan_off","937.47","15.12","889.58","14.35"
    " GFXBench 3.x gl_trex_off","1591.94","28.43","1516.95","27.09"
    " GFXBench 4.x gl_4_off","259.93","4.40","259.40","4.39","251.01","4.25"
    " GFXBench 5.x gl_5_high_off","113.98","1.77","114.51","1.78","112.04","1.74"




Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table:: Glmark2 Performance
    :header: "Benchmark","am68_sk-fs: Score","am69_sk-fs: Score","j721e-idk-gw: Score","j721s2-evm: Score","j722s_evm-fs: Score","j784s4-evm: Score"

    "Glmark2-DRM","522.00","527.00","110.00","281.00","159.00"
    "Glmark2-Wayland","1272.00","1330.00","1141.00","1284.00","683.00","1322.00"
    "Glmark2-Wayland 4000x4000","81.00","88.00","76.00","84.00"

 
 

 

 



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


CPSW/CPSW2g/CPSW3g Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- CPSW2g: AM65x, J7200, J721e, J721S2, J784S4
- CPSW3g: AM64x, AM62x, AM62ax, AM62px


.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table:: CPSW2g TCP Bidirectional Throughput
    :header: "Command Used","am68_sk-fs: THROUGHPUT (Mbits/sec)","am68_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am69_sk-fs: THROUGHPUT (Mbits/sec)","am69_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j722s_evm-fs: THROUGHPUT (Mbits/sec)","j722s_evm-fs: CPU Load % (LOCAL_CPU_UTIL)","j784s4-evm: THROUGHPUT (Mbits/sec)","j784s4-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","942.16","13.80","182.22","3.19","1465.91","65.74","1856.02","82.25","1855.74","83.92","1854.47","60.63","1833.57","21.76"




.. rubric::  TCP Bidirectional Throughput Interrupt Pacing
   :name: CPSW2g-tcp-bidirectional-throughput-interrupt-pacing

.. csv-table:: CPSW2g TCP Bidirectional Throughput Interrupt Pacing
    :header: "Command Used","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j722s_evm-fs: THROUGHPUT (Mbits/sec)","j722s_evm-fs: CPU Load % (LOCAL_CPU_UTIL)","j784s4-evm: THROUGHPUT (Mbits/sec)","j784s4-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1835.16","47.28","1864.26","42.83","1854.45","61.18","1753.96","31.10","1876.82","8.23"




.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table:: CPSW2g UDP Egress Throughput 0 loss
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: Packets Per Second (kPPS)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: Packets Per Second (kPPS)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: Packets Per Second (kPPS)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j722s_evm-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j722s_evm-fs: THROUGHPUT (Mbits/sec)","j722s_evm-fs: Packets Per Second (kPPS)","j722s_evm-fs: CPU Load % (LOCAL_CPU_UTIL)","j784s4-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j784s4-evm: THROUGHPUT (Mbits/sec)","j784s4-evm: Packets Per Second (kPPS)","j784s4-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","30.57","212.00","89.79","18.00","30.55","212.00","87.51","18.00","29.84","207.00","91.58","18.00","16.11","112.00","40.88","18.00","25.67","178.00","24.06"
    "128","82.00","113.98","173.00","88.93","82.00","143.07","218.00","88.96","82.00","121.51","185.00","85.02","82.00","72.62","111.00","40.39","82.00","126.97","194.00","23.15"
    "256","210.00","367.12","219.00","89.59","210.00","208.53","124.00","82.93","210.00","309.34","184.00","89.06","210.00","180.79","108.00","40.33","210.00","301.14","179.00","23.93"
    "1024","978.00","936.62","120.00","58.19","978.00","936.40","120.00","58.37","978.00","935.60","120.00","55.02","978.00","936.77","120.00","14.16","978.00","936.77","120.00","14.16"
    "1518","1472.00","957.03","81.00","39.10","1472.00","1380.98","117.00","83.68","1472.00","956.90","81.00","41.73","1472","956.11","81.00","9.41","1472","956.11","81.00","9.41"




.. csv-table:: CPSW2g UDP Ingress Throughput 0 loss
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: Packets Per Second (kPPS)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: Packets Per Second (kPPS)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: Packets Per Second (kPPS)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j722s_evm-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j722s_evm-fs: THROUGHPUT (Mbits/sec)","j722s_evm-fs: Packets Per Second (kPPS)","j722s_evm-fs: CPU Load % (LOCAL_CPU_UTIL)","j784s4-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j784s4-evm: THROUGHPUT (Mbits/sec)","j784s4-evm: Packets Per Second (kPPS)","j784s4-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","6.77","47.00","30.61","18.00","1.70","12.00","5.83","18.00","1.17","8.00","7.70","18.00","1.02","7.00","1.46","18.00","18.13","126.00","20.66"
    "128","82.00","15.02","23.00","10.51","82.00","12.79","19.00","8.66","82.00","5.25","8.00","3.72","82.00","7.15","11.00","1.79","82.00","80.88","123.00","20.49"
    "256","210.00","64.17","38.00","24.71","210.00","371.29","221.00","86.97","210.00","17.3","10.00","7.89","210.00","61.99","37.00","14.7","210.00","202.78","121.00","21.09"
    "1024","978.00","142.39","18.00","12.02","978.00","77.46","10.00","3.78","978.00","68.07","9.00","8.46","978.00","199.51","25.00","8.41","978.00","929.78","119.00","21.32"
    "1518","1472.00","343.84","29.00","23.06","1472.00","948.90","81.00","57.80","1472.00","521.50","44.00","33.49","1472.00","957.02","81.00","14.70","1472.00","957.02","81.00","14.70"




.. csv-table:: CPSW2g UDP Ingress Throughput possible loss
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: Packets Per Second (kPPS)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j7200-evm: Packet Loss %","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: Packets Per Second (kPPS)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: Packet Loss %","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: Packets Per Second (kPPS)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: Packet Loss %","j722s_evm-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j722s_evm-fs: THROUGHPUT (Mbits/sec)","j722s_evm-fs: Packets Per Second (kPPS)","j722s_evm-fs: CPU Load % (LOCAL_CPU_UTIL)","j722s_evm-fs: Packet Loss %","j784s4-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j784s4-evm: THROUGHPUT (Mbits/sec)","j784s4-evm: Packets Per Second (kPPS)","j784s4-evm: CPU Load % (LOCAL_CPU_UTIL)","j784s4-evm: Packet Loss %"

    "64","18.00","21.45","149.00","83.97","2.82","18.00","55.86","388.00","88.45","7.96","18.00","50.09","348.00","87.82","5.23","18.00","33.06","230.00","43.9","73.29","18.00","64.8","450.00","22.86","22.68"
    "128","82.00","241.53","368.00","91.12","9.22","82.00","256.38","391.00","91.49","7.33","82.00","214.43","327.00","86.78","28.93","82.00","150.26","229.00","44.97","69.59","82.00","256.65","391.00","22.8","20.7"
    "256","210.00","392.00","233.00","81.19","2.72","210.00","634.37","378.00","90.96","8.39","210.00","528.49","315.00","87.71","19.31","210.00","264.56","157.00","38.56","22.62","210.00","561.87","334.00","23.05","20.13"
    "1024","978.00","928.71","119.00","79.88","0.78","978.00","924.46","118.00","78.08","0.51","978.00","909.56","116.00","81.27","2.9","978.00","936.10","120.00","39.75","0.07","978.00","804.34","103.00","21.24","0.03"
    "1518","1472.00","956.75","81.00","67.09","0.01","1472.00","949.76","81.00","61.08","0.01","1472.00","948.4","81.00","65.47","0.1","1472.00","957.02","81.00","14.70","0.00","1472.00","957.02","81.00","14.70","0.00"

 
 

 

 
 



|

PCIe Driver
-------------------------

PCIe-ETH
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: PCIe Ethernet performance
    :header: "TCP Window Size(Kbytes)","am68-sk: Bandwidth (Mbits/sec)","am69-sk: Bandwidth (Mbits/sec)","j721e-idk-gw: Bandwidth (Mbits/sec)","j7200-evm: Bandwidth (Mbits/sec)","j721s2-evm: Bandwidth (Mbits/sec)","j784s4-evm: Bandwidth (Mbits/sec)","j722s-evm: Bandwidth (Mbits/sec)"

    "8","185","185","185","185","185","185","179"
    "16","438","439","440","440","438","439","416"
    "32","583","587","589","589","583","588","549"
    "64","926","936","937","934","926","937","912"
    "128","938","939","938","938","938","939","937"
    "256","938","940","939","939","938","940","938"

- Command: iperf3 -c $server_ip -w $window_size
- PCIe-Ethernet Card being used: Intel® 82574L Gigabit Ethernet Controller

PCIe-NVMe-SSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^
 
AM68-SK
"""""""

.. csv-table:: PCIE SSD EXT4 FIO 10G
    :header: "Buffer size (bytes)","am68-sk: Write EXT4 Throughput (Mibytes/sec)","am68-sk: Write EXT4 CPU Load (%)","am68-sk: Read EXT4 Throughput (Mibytes/sec)","am68-sk: Read EXT4 CPU Load (%)"

    "4k","183","50.42","277","49.81"
    "256k","1138","22.87","1545","13.11"
    "1m","1426","26.07","1563","6.23"
    "4m","1428","22.64","1564","4.13"

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based
- Negotiated link speed and width: Speed 8GT/s, Width x2
- SSD being used: Samsung 970 EVO Plus PCIe 3.0 SSD

AM69-SK
"""""""

.. csv-table:: PCIE SSD EXT4 FIO 10G
    :header: "Buffer size (bytes)","am69-sk: Write EXT4 Throughput (Mibytes/sec)","am69-sk: Write EXT4 CPU Load (%)","am69-sk: Read EXT4 Throughput (Mibytes/sec)","am69-sk: Read EXT4 CPU Load (%)"

    "4k","178","12.59","271","12.51"
    "256k","1086","4.24","1545","3.25"
    "1m","1401","4.44","1563","1.60"
    "4m","1407","5.24","1563","0.93"

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based
- Negotiated link speed and width: Speed 8GT/s, Width x2
- SSD being used: Samsung 970 EVO Plus PCIe 3.0 SSD

J721E-IDK-GW
"""""""""""""""""""""""""""

.. csv-table:: PCIE SSD EXT4 FIO 10G
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mibytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mibytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "4k","187","50.32","285","50.29"
    "256k","1409","26.65","1569","14.69"
    "1m","1394","25.13","1569","8.79"
    "4m","1372","22.31","1537","7.52"

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based
- Negotiated link speed and width: Speed 8GT/s, Width x2
- SSD being used: Intel Optane SSD 900P

J7200-EVM
"""""""""""""""""""""""""""

.. csv-table:: PCIE SSD EXT4 FIO 10G
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mibytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mibytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "4k","189","50.34","292","50.28"
    "256k","1403","28.05","1569","14.34"
    "1m","1366","28.61","1569","8.19"
    "4m","1321","26.68","1540","7.67"

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based
- Negotiated link speed and width: Speed 8GT/s, Width x2
- SSD being used: Intel Optane SSD 900P

J721S2-EVM
"""""""""""""""""""""""""""

.. csv-table:: PCIE SSD EXT4 FIO 10G
    :header: "Buffer size (bytes)","j721s2-evm: Write EXT4 Throughput (Mibytes/sec)","j721s2-evm: Write EXT4 CPU Load (%)","j721s2-evm: Read EXT4 Throughput (Mibytes/sec)","j721s2-evm: Read EXT4 CPU Load (%)"

    "4k","198","50.35","291","50.33"
    "256k","748","15.69","786","7.61"
    "1m","730","15.09","771","4.20"
    "4m","732","14.16","771","3.89"

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based
- Negotiated link speed and width: Speed 8GT/s, Width x1
- SSD being used: Intel Optane SSD 900P

J784S4-EVM
"""""""""""""""""""""""""""

.. csv-table:: PCIE SSD EXT4 FIO 10G
    :header: "Buffer size (bytes)","j784s4-evm: Write EXT4 Throughput (Mibytes/sec)","j784s4-evm: Write EXT4 CPU Load (%)","j784s4-evm: Read EXT4 Throughput (Mibytes/sec)","j784s4-evm: Read EXT4 CPU Load (%)"

    "4k","184","12.63","281","12.62"
    "256k","2143","8.06","2458","5.45"
    "1m","1642","5.64","2496","3.18"
    "4m","1590","6.00","2443","2.24"

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based
- Negotiated link speed and width: Speed 8GT/s, Width x2
- SSD being used: Intel Optane SSD 900P

J722S-EVM
"""""""""""""""""""""""""""

.. csv-table:: PCIE SSD EXT4 FIO 10G
    :header: "Buffer size (bytes)","j722s-evm: Write EXT4 Throughput (Mibytes/sec)","j722s-evm: Write EXT4 CPU Load (%)","j722s-evm: Read EXT4 Throughput (Mibytes/sec)","j722s-evm: Read EXT4 CPU Load (%)"

    "4k","110","25.37","166","25.27"
    "256k","751","11.76","785","9.79"
    "1m","733","9.90","772","8.23"
    "4m","734","8.34","775","7.42"

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based
- Negotiated link speed and width: Speed 8GT/s, Width x1
- SSD being used: Intel Optane SSD 900P

|

Linux OSPI Flash Driver
-------------------------

 

 

 

 


J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^


UBIFS
"""""""""""""""""""""""""""

.. csv-table:: OSPI Flash Driver
    :header: "Buffer size (bytes)","j721e-idk-gw: Write UBIFS Throughput (Mbytes/sec)","j721e-idk-gw: Write UBIFS CPU Load (%)","j721e-idk-gw: Read UBIFS Throughput (Mbytes/sec)","j721e-idk-gw: Read UBIFS CPU Load (%)"

    "102400","0.59 (min 0.47, max 1.03)","24.17 (min 22.17, max 25.92)","31.60","7.69"
    "262144","0.45 (min 0.35, max 0.51)","23.89 (min 22.56, max 24.84)","31.58","7.69"
    "524288","0.45 (min 0.35, max 0.51)","22.67 (min 20.88, max 24.49)","31.49","0.00"
    "1048576","0.43 (min 0.32, max 0.51)","24.04 (min 22.05, max 26.69)","31.29","7.69"




RAW
"""""""""""""""""""""""""""

.. csv-table:: OSPI Raw Flash Driver
    :header: "File size (Mbytes)","j721e-idk-gw: Raw Read Throughput (Mbytes/sec)"

    "50","38.76"

 
 


J722S-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^


UBIFS
"""""""""""""""""""""""""""

.. csv-table:: OSPI Flash Driver
    :header: "Buffer size (bytes)","j722s_evm-fs: Write UBIFS Throughput (Mbytes/sec)","j722s_evm-fs: Write UBIFS CPU Load (%)","j722s_evm-fs: Read UBIFS Throughput (Mbytes/sec)","j722s_evm-fs: Read UBIFS CPU Load (%)"

    "102400","0.16 (min 0.12, max 0.25)","13.98 (min 13.13, max 15.05)","31.17","11.11"
    "262144","0.13 (min 0.10, max 0.16)","13.70 (min 13.36, max 14.22)","31.22","7.41"
    "524288","0.13 (min 0.10, max 0.18)","13.86 (min 13.45, max 14.13)","30.78","10.71"
    "1048576","0.13 (min 0.12, max 0.16)","13.83 (min 13.12, max 14.40)","30.66","13.79"




RAW
"""""""""""""""""""""""""""

.. csv-table:: OSPI Raw Flash Driver
    :header: "File size (Mbytes)","j722s_evm-fs: Raw Read Throughput (Mbytes/sec)"

    "50","44.64"

 
 


AM68-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^


UBIFS
"""""""""""""""""""""""""""

.. csv-table:: OSPI Flash Driver
    :header: "Buffer size (bytes)","am68_sk-fs: Write UBIFS Throughput (Mbytes/sec)","am68_sk-fs: Write UBIFS CPU Load (%)","am68_sk-fs: Read UBIFS Throughput (Mbytes/sec)","am68_sk-fs: Read UBIFS CPU Load (%)"

    "102400","0.17 (min 0.12, max 0.28)","25.79 (min 23.76, max 26.69)","2.45","50.00"
    "262144","0.14 (min 0.11, max 0.18)","25.36 (min 24.84, max 25.64)","2.44","50.58"
    "524288","0.14 (min 0.11, max 0.19)","25.21 (min 24.19, max 27.17)","2.44","49.71"
    "1048576","0.14 (min 0.11, max 0.19)","26.08 (min 25.03, max 27.84)","2.44","50.58"




RAW
"""""""""""""""""""""""""""

.. csv-table:: OSPI Raw Flash Driver
    :header: "File size (Mbytes)","am68_sk-fs: Raw Read Throughput (Mbytes/sec)"

    "50","2.40"

 
 



AM69-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^


UBIFS
"""""""""""""""""""""""""""

.. csv-table:: OSPI Flash Driver
    :header: "Buffer size (bytes)","am69_sk-fs: Write UBIFS Throughput (Mbytes/sec)","am69_sk-fs: Write UBIFS CPU Load (%)","am69_sk-fs: Read UBIFS Throughput (Mbytes/sec)","am69_sk-fs: Read UBIFS CPU Load (%)"

    "102400","0.17 (min 0.12, max 0.28)","6.35 (min 6.06, max 6.61)","2.43","12.59"
    "262144","0.13 (min 0.10, max 0.18)","6.21 (min 5.55, max 6.89)","2.43","12.46"
    "524288","0.14 (min 0.10, max 0.18)","6.05 (min 5.52, max 7.02)","2.43","12.46"
    "1048576","0.13 (min 0.10, max 0.17)","6.08 (min 5.17, max 7.01)","2.43","12.59"




RAW
"""""""""""""""""""""""""""

.. csv-table:: OSPI Raw Flash Driver
    :header: "File size (Mbytes)","am69_sk-fs: Raw Read Throughput (Mbytes/sec)"

    "50","2.38"

 
 


J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^




RAW
"""""""""""""""""""""""""""

.. csv-table:: OSPI Raw Flash Driver
    :header: "File size (Mbytes)","j7200-evm: Raw Read Throughput (Mbytes/sec)"

    "50","37.88"

 
 

 


J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^


UBIFS
"""""""""""""""""""""""""""

.. csv-table:: OSPI Flash Driver
    :header: "Buffer size (bytes)","j784s4-evm: Write UBIFS Throughput (Mbytes/sec)","j784s4-evm: Write UBIFS CPU Load (%)","j784s4-evm: Read UBIFS Throughput (Mbytes/sec)","j784s4-evm: Read UBIFS CPU Load (%)"

    "102400","0.17 (min 0.12, max 0.28)","6.71 (min 6.19, max 7.58)","2.43","12.46"
    "262144","0.14 (min 0.10, max 0.18)","6.35 (min 5.77, max 6.77)","2.43","12.72"
    "524288","0.14 (min 0.11, max 0.18)","6.46 (min 5.55, max 7.44)","2.43","12.45"
    "1048576","0.13 (min 0.10, max 0.18)","6.65 (min 6.28, max 7.07)","2.43","12.57"



 
 

 

 
 

 

 

 

 



|

UBoot UFS Driver
-------------------------


J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT UFS RAW
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","95255.81","372363.64"
    "800000","102400.00","481882.35"
    "1000000","103044.03","606814.81"








J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT UFS RAW
    :header: "File size (bytes in hex)","j784s4-evm: Write Throughput (Kbytes/sec)","j784s4-evm: Read Throughput (Kbytes/sec)"

    "400000","91022.22","341333.33"
    "800000","98698.80","481882.35"
    "1000000","94160.92","606814.81"

 
 



|

EMMC Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.


J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^


EXT4
"""""""""""""""""""""""""""

.. csv-table:: EMMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","59.50","1.50","314.00","1.91"
    "4m","59.40","1.39","314.00","1.35"
    "4k","53.50","20.63","56.30","18.99"
    "256k","59.70","1.75","312.00","3.48"




RAW
"""""""""""""""""""""""""""

.. csv-table:: EMMC RAW FIO 1G
    :header: "Buffer size (bytes)","j7200-evm: Write Raw Throughput (Mbytes/sec)","j7200-evm: Write Raw CPU Load (%)","j7200-evm: Read Raw Throughput (Mbytes/sec)","j7200-evm: Read Raw CPU Load (%)"

    "1m","61.20","1.52","315.00","1.85"
    "4m","61.00","1.36","314.00","1.23"
    "4k","63.60","12.42","59.80","16.68"
    "256k","61.10","1.63","317.00","3.62"

 
 


J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^


EXT4
"""""""""""""""""""""""""""

.. csv-table:: EMMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","57.40","1.43","175.00","1.25"
    "4m","57.60","1.20","175.00","0.78"
    "4k","51.70","20.08","56.80","18.70"
    "256k","57.40","1.50","174.00","2.07"




RAW
"""""""""""""""""""""""""""

.. csv-table:: EMMC RAW FIO 1G
    :header: "Buffer size (bytes)","j721e-idk-gw: Write Raw Throughput (Mbytes/sec)","j721e-idk-gw: Write Raw CPU Load (%)","j721e-idk-gw: Read Raw Throughput (Mbytes/sec)","j721e-idk-gw: Read Raw CPU Load (%)"

    "1m","60.30","1.35","175.00","1.30"
    "4m","60.70","1.24","175.00","0.96"
    "4k","52.70","13.96","54.50","13.70"
    "256k","59.80","1.59","174.00","2.01"

 
 


J722S-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^


EXT4
"""""""""""""""""""""""""""

.. csv-table:: EMMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j722s_evm-fs: Write EXT4 Throughput (Mbytes/sec)","j722s_evm-fs: Write EXT4 CPU Load (%)","j722s_evm-fs: Read EXT4 Throughput (Mbytes/sec)","j722s_evm-fs: Read EXT4 CPU Load (%)"

    "1m","92.60","1.89","265.00","3.02"
    "4m","88.90","1.39","282.00","2.56"
    "4k","78.70","25.60","91.10","22.65"
    "256k","91.00","2.26","292.00","4.46"




RAW
"""""""""""""""""""""""""""

.. csv-table:: EMMC RAW FIO 1G
    :header: "Buffer size (bytes)","j722s_evm-fs: Write Raw Throughput (Mbytes/sec)","j722s_evm-fs: Write Raw CPU Load (%)","j722s_evm-fs: Read Raw Throughput (Mbytes/sec)","j722s_evm-fs: Read Raw CPU Load (%)"

    "1m","95.80","1.77","293.00","3.15"
    "4m","96.40","1.22","293.00","2.59"
    "4k","74.90","9.96","71.30","8.17"
    "256k","95.80","2.15","293.00","4.54"


 


J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^


EXT4
"""""""""""""""""""""""""""

.. csv-table:: EMMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j721s2-evm: Write EXT4 Throughput (Mbytes/sec)","j721s2-evm: Write EXT4 CPU Load (%)","j721s2-evm: Read EXT4 Throughput (Mbytes/sec)","j721s2-evm: Read EXT4 CPU Load (%)"

    "1m","45.20","3.30","300.00","3.91"
    "4m","45.40","2.54","300.00","3.01"
    "4k","5.28","4.09","36.20","15.47"
    "256k","36.40","3.40","283.00","4.83"




RAW
"""""""""""""""""""""""""""

.. csv-table:: EMMC RAW FIO 1G
    :header: "Buffer size (bytes)","j721s2-evm: Write Raw Throughput (Mbytes/sec)","j721s2-evm: Write Raw CPU Load (%)","j721s2-evm: Read Raw Throughput (Mbytes/sec)","j721s2-evm: Read Raw CPU Load (%)"

    "1m","58.50","4.02","313.00","4.29"
    "4m","58.50","3.23","313.00","3.65"
    "4k","62.10","16.09","57.80","22.70"
    "256k","58.80","3.95","309.00","5.26"

 
 


J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^


EXT4
"""""""""""""""""""""""""""

.. csv-table:: EMMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j784s4-evm: Write EXT4 Throughput (Mbytes/sec)","j784s4-evm: Write EXT4 CPU Load (%)","j784s4-evm: Read EXT4 Throughput (Mbytes/sec)","j784s4-evm: Read EXT4 CPU Load (%)"

    "1m","89.90","0.45","285.00","0.42"
    "4m","95.40","0.48","287.00","0.25"
    "4k","78.50","10.92","91.50","8.87"
    "256k","89.70","0.48","286.00","1.08"




RAW
"""""""""""""""""""""""""""

.. csv-table:: EMMC RAW FIO 1G
    :header: "Buffer size (bytes)","j784s4-evm: Write Raw Throughput (Mbytes/sec)","j784s4-evm: Write Raw CPU Load (%)","j784s4-evm: Read Raw Throughput (Mbytes/sec)","j784s4-evm: Read Raw CPU Load (%)"

    "1m","97.40","0.55","294.00","0.60"
    "4m","98.10","0.54","294.00","0.36"
    "4k","91.40","5.66","87.60","5.72"
    "256k","97.60","0.69","294.00","0.97"

 
 



AM69-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^


EXT4
"""""""""""""""""""""""""""

.. csv-table:: EMMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","am69_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am69_sk-fs: Write EXT4 CPU Load (%)","am69_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am69_sk-fs: Read EXT4 CPU Load (%)"

    "1m","91.40","0.49","288.00","0.42"
    "4m","97.30","0.45","286.00","0.27"
    "4k","77.00","9.49","90.60","8.56"
    "256k","91.90","0.49","288.00","0.99"



 
 

 





 
 

 











 
 



|

UBoot EMMC Driver
-------------------------

 






J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT EMMC RAW
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "2000000","60235.29","312076.19"
    "4000000","60963.72","310597.16"




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT EMMC RAW
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "2000000","62534.35","173375.66"
    "4000000","62415.24","176646.90"




J722S-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT EMMC RAW
    :header: "File size (bytes in hex)","j722s_evm-fs: Write Throughput (Kbytes/sec)","j722s_evm-fs: Read Throughput (Kbytes/sec)"

    "2000000","96946.75","237449.28"
    "4000000","95672.99","262144.00"




J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT EMMC RAW
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "2000000","59686.70","309132.08"
    "4000000","60401.84","318135.92"




J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT EMMC RAW
    :header: "File size (bytes in hex)","j784s4-evm: Write Throughput (Kbytes/sec)","j784s4-evm: Read Throughput (Kbytes/sec)"

    "2000000","98107.78","289982.30"
    "4000000","101922.24","265327.94"





AM69-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^














 
 

 



|

MMC/SD Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

 

 

 

 

 





 

 







 

 


J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^


EXT4
"""""""""""""""""""""""""""

.. csv-table:: MMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","20.40","0.75","87.50","0.89"
    "4m","19.70","0.76","83.80","0.72"
    "4k","4.72","3.28","13.60","6.35"
    "256k","19.90","1.01","84.10","1.31"




RAW
"""""""""""""""""""""""""""

.. csv-table:: MMC RAW FIO 1G
    :header: "Buffer size (bytes)","j7200-evm: Write Raw Throughput (Mbytes/sec)","j7200-evm: Write Raw CPU Load (%)","j7200-evm: Read Raw Throughput (Mbytes/sec)","j7200-evm: Read Raw CPU Load (%)"

    "1m","21.40","0.84","88.40","0.85"
    "4m","21.50","0.75","88.50","0.76"
    "4k","6.11","3.27","18.70","7.39"
    "256k","21.10","0.92","86.60","1.41"


 


J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^


EXT4
"""""""""""""""""""""""""""

.. csv-table:: MMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j721s2-evm: Write EXT4 Throughput (Mbytes/sec)","j721s2-evm: Write EXT4 CPU Load (%)","j721s2-evm: Read EXT4 Throughput (Mbytes/sec)","j721s2-evm: Read EXT4 CPU Load (%)"

    "1m","19.20","0.86","87.80","0.96"
    "4m","18.70","0.76","84.10","0.76"
    "4k","4.00","3.16","13.60","6.63"
    "256k","18.50","1.01","82.90","1.27"




RAW
"""""""""""""""""""""""""""

.. csv-table:: MMC RAW FIO 1G
    :header: "Buffer size (bytes)","j721s2-evm: Write Raw Throughput (Mbytes/sec)","j721s2-evm: Write Raw CPU Load (%)","j721s2-evm: Read Raw Throughput (Mbytes/sec)","j721s2-evm: Read Raw CPU Load (%)"

    "1m","21.40","3.28","87.30","3.03"
    "4m","21.50","2.81","87.50","3.12"
    "4k","5.53","5.42","17.20","9.69"
    "256k","21.30","2.76","85.50","3.42"


 


AM68-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^


EXT4
"""""""""""""""""""""""""""

.. csv-table:: MMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","am68_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am68_sk-fs: Write EXT4 CPU Load (%)","am68_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am68_sk-fs: Read EXT4 CPU Load (%)"

    "1m","17.60","0.98","83.30","0.95"
    "4m","18.00","0.69","83.40","0.84"
    "4k","4.10","3.30","13.40","6.84"
    "256k","17.20","0.92","79.60","1.11"




 


J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^


EXT4
"""""""""""""""""""""""""""

.. csv-table:: MMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j784s4-evm: Write EXT4 Throughput (Mbytes/sec)","j784s4-evm: Write EXT4 CPU Load (%)","j784s4-evm: Read EXT4 Throughput (Mbytes/sec)","j784s4-evm: Read EXT4 CPU Load (%)"

    "1m","18.40","0.15","86.50","0.22"
    "4m","19.30","0.18","86.80","0.19"
    "4k","4.04","0.80","14.50","1.92"
    "256k","17.90","0.17","82.70","0.34"




RAW
"""""""""""""""""""""""""""

.. csv-table:: MMC RAW FIO 1G
    :header: "Buffer size (bytes)","j784s4-evm: Write Raw Throughput (Mbytes/sec)","j784s4-evm: Write Raw CPU Load (%)","j784s4-evm: Read Raw Throughput (Mbytes/sec)","j784s4-evm: Read Raw CPU Load (%)"

    "1m","20.10","0.14","86.60","0.20"
    "4m","19.80","0.14","86.70","0.18"
    "4k","6.77","1.07","23.60","3.24"
    "256k","19.90","0.21","83.80","0.29"


 


AM69-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^


EXT4
"""""""""""""""""""""""""""

.. csv-table:: MMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","am69_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am69_sk-fs: Write EXT4 CPU Load (%)","am69_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am69_sk-fs: Read EXT4 CPU Load (%)"

    "1m","19.40","0.17","83.60","0.17"
    "4m","19.50","0.18","83.30","0.18"
    "4k","4.37","0.83","13.80","1.63"
    "256k","18.70","0.18","79.90","0.34"




 


J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^


EXT4
"""""""""""""""""""""""""""

.. csv-table:: MMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","32.40","0.96","41.90","0.55"
    "4m","32.50","0.79","42.00","0.43"
    "4k","2.81","1.90","11.30","4.97"
    "256k","30.30","1.20","42.90","0.70"




RAW
"""""""""""""""""""""""""""

.. csv-table:: MMC RAW FIO 1G
    :header: "Buffer size (bytes)","j721e-idk-gw: Write Raw Throughput (Mbytes/sec)","j721e-idk-gw: Write Raw CPU Load (%)","j721e-idk-gw: Read Raw Throughput (Mbytes/sec)","j721e-idk-gw: Read Raw CPU Load (%)"

    "1m","13.40","0.54","43.70","0.54"
    "4m","14.30","0.53","43.70","0.46"
    "4k","5.40","2.75","13.00","5.08"
    "256k","13.10","0.70","43.20","0.74"



 
 


J722S-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^


EXT4
"""""""""""""""""""""""""""

.. csv-table:: MMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j722s_evm-fs: Write EXT4 Throughput (Mbytes/sec)","j722s_evm-fs: Write EXT4 CPU Load (%)","j722s_evm-fs: Read EXT4 Throughput (Mbytes/sec)","j722s_evm-fs: Read EXT4 CPU Load (%)"

    "1m","42.70","1.39","85.10","1.62"
    "4m","41.20","0.92","84.70","1.25"
    "4k","2.83","1.80","13.40","4.79"
    "256k","38.40","1.40","84.30","1.73"




RAW
"""""""""""""""""""""""""""

.. csv-table:: MMC RAW FIO 1G
    :header: "Buffer size (bytes)","j722s_evm-fs: Write Raw Throughput (Mbytes/sec)","j722s_evm-fs: Write Raw CPU Load (%)","j722s_evm-fs: Read Raw Throughput (Mbytes/sec)","j722s_evm-fs: Read Raw CPU Load (%)"

    "1m","19.40","0.69","87.80","1.44"
    "4m","19.40","0.63","87.80","1.10"
    "4k","5.85","2.59","17.10","5.79"
    "256k","19.40","0.87","85.30","1.61"
















 

 

 





 

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option
 



|

UBoot MMC/SD Driver
-------------------------

  








J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT MMCSD FAT
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","23405.71","33032.26"
    "800000","28444.44","39009.52"
    "1000000","19073.34","42555.84"




J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT MMCSD FAT
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","44043.01","71859.65"
    "800000","42666.67","80313.73"
    "1000000","48188.24","86687.83"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card



J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT MMCSD FAT
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "400000","18123.89","55351.35"
    "800000","15003.66","69423.73"
    "1000000","18347.14","79533.98"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card






J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT MMCSD FAT
    :header: "File size (bytes in hex)","j784s4-evm: Write Throughput (Kbytes/sec)","j784s4-evm: Read Throughput (Kbytes/sec)"

    "400000","36900.90","48188.24"
    "800000","43115.79","63503.88"
    "1000000","47216.14","75851.85"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card



AM69-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT MMCSD FAT
    :header: "File size (bytes in hex)","am69_sk-fs: Write Throughput (Kbytes/sec)","am69_sk-fs: Read Throughput (Kbytes/sec)"

    "400000","13653.33","46545.45"
    "800000","19412.32","62534.35"
    "1000000","19551.31","74812.79"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
















 
 



|

USB Driver
-------------------------
 


USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^










.. csv-table:: USBDEVICE HIGHSPEED SLAVE_READ_THROUGHPUT
    :header: "Number of Blocks","j721s2-evm: Throughput (MB/sec)","j722s_evm-fs: Throughput (MB/sec)","j784s4-evm: Throughput (MB/sec)"

    "150","31.80","44.30","44.70"




.. csv-table:: USBDEVICE HIGHSPEED SLAVE_WRITE_THROUGHPUT
    :header: "Number of Blocks","j721s2-evm: Throughput (MB/sec)","j722s_evm-fs: Throughput (MB/sec)","j784s4-evm: Throughput (MB/sec)"

    "150","28.40","38.90","35.90"





 
 
 



|

CRYPTO Driver
-------------------------


OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: OpenSSL Performance
    :header: "Algorithm","Buffer Size (in bytes)","am68_sk-fs: throughput (KBytes/Sec)","am69_sk-fs: throughput (KBytes/Sec)","j7200-evm: throughput (KBytes/Sec)","j721e-idk-gw: throughput (KBytes/Sec)","j721s2-evm: throughput (KBytes/Sec)","j722s_evm-fs: throughput (KBytes/Sec)","j784s4-evm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","44123.14","43311.79","39362.22","47834.79","44717.06","24387.58","43676.33"
    "aes-128-cbc","16","867.66","827.70","767.72","910.34","856.45","433.89","856.38"
    "aes-128-cbc","16384","186160.47","181791.40","187585.88","191561.73","181059.58","85480.79","180218.54"
    "aes-128-cbc","256","13246.89","13141.33","11764.65","14352.64","13207.72","7280.98","13137.24"
    "aes-128-cbc","64","3452.14","3308.44","3045.06","3649.47","3437.82","1927.91","3393.02"
    "aes-128-cbc","8192","152474.97","150025.56","148985.17","160970.07","149012.48","72531.97","148780.37"
    "aes-128-ecb","1024","44908.89","36299.78","39626.07","48542.38","45071.36","24922.11","36696.41"
    "aes-128-ecb","16","882.23","845.03","767.29","926.68","864.38","445.30","866.28"
    "aes-128-ecb","16384","187919.02","186433.54","187514.88","198666.92","185920.17","88380.76","169596.25"
    "aes-128-ecb","256","13665.19","13440.77","11864.49","14459.22","13531.82","7450.88","13041.49"
    "aes-128-ecb","64","3530.05","3021.23","3071.59","3700.12","3460.42","1976.73","3434.73"
    "aes-128-ecb","8192","154555.73","149102.59","150039.21","164265.98","151314.43","74686.46","133109.08"
    "aes-192-cbc","1024","43741.87","43582.81","39367.68","47418.03","44194.13","23779.33","34785.62"
    "aes-192-cbc","16","864.35","857.22","772.84","916.86","863.19","434.04","843.82"
    "aes-192-cbc","16384","176013.31","162791.42","185117.35","181452.80","174724.44","77075.80","171780.78"
    "aes-192-cbc","256","13119.06","13139.11","11862.53","14233.09","13241.94","7243.09","13131.52"
    "aes-192-cbc","64","3476.80","3396.84","3067.01","3665.45","3440.77","1926.74","3220.71"
    "aes-192-cbc","8192","145175.89","128360.45","146784.26","152977.41","145364.31","66245.97","139422.38"
    "aes-192-ecb","1024","44594.52","43496.79","39721.64","47726.59","44520.45","24160.94","43664.73"
    "aes-192-ecb","16","885.87","700.74","774.78","927.09","868.54","448.71","849.27"
    "aes-192-ecb","16384","182315.69","178727.59","185204.74","185974.78","181474.65","79855.62","178891.43"
    "aes-192-ecb","256","13590.36","13229.23","11916.03","14343.77","13403.22","7430.40","13134.68"
    "aes-192-ecb","64","3523.03","3283.67","3090.13","3678.78","3460.93","1964.27","3381.38"
    "aes-192-ecb","8192","149285.55","146366.46","148630.19","155544.23","147947.52","68646.23","147344.04"
    "aes-256-cbc","1024","44028.93","43511.81","39152.30","47063.04","43742.55","23134.55","43651.41"
    "aes-256-cbc","16","873.05","826.71","771.35","918.75","857.93","434.86","847.11"
    "aes-256-cbc","16384","163233.79","161742.85","175811.24","167936.00","164249.60","70696.96","160650.58"
    "aes-256-cbc","256","13272.41","13136.90","11743.49","14246.23","13190.66","7174.49","13130.75"
    "aes-256-cbc","64","3525.57","3254.59","3056.55","3683.63","3417.22","1928.38","3383.40"
    "aes-256-cbc","8192","137999.70","135528.45","140962.47","143250.77","137308.84","61835.95","133985.62"
    "aes-256-ecb","1024","44036.10","43601.92","39234.22","47605.76","44116.31","23820.63","43643.56"
    "aes-256-ecb","16","877.39","783.16","768.19","925.50","862.62","447.51","823.58"
    "aes-256-ecb","16384","169334.10","167941.46","182534.14","173746.86","168241.83","72510.12","165756.93"
    "aes-256-ecb","256","13316.44","13170.77","11848.70","14369.02","13395.46","7315.46","13134.25"
    "aes-256-ecb","64","3507.71","3434.71","3090.65","3691.54","3464.51","1953.58","3287.83"
    "aes-256-ecb","8192","142439.77","139973.97","145899.52","147576.15","140563.80","63381.50","137349.80"
    "des3","1024","38702.42","37706.07","37452.80","40062.29","38724.95","","37846.70"
    "des3","16","873.32","747.44","762.97","924.46","858.33","","849.71"
    "des3","16384","95857.32","95649.79","119357.44","96987.82","95704.41","","95966.55"
    "des3","256","12963.33","10115.16","11323.65","13194.75","12754.69","","12409.51"
    "des3","64","3503.51","3071.81","3049.34","3680.30","3442.05","","2975.19"
    "des3","8192","87430.49","86777.86","102856.02","88451.75","87149.23","","85928.62"
    "sha1","1024","53978.79","53416.62","55069.70","55547.90","55075.50","","53468.50"
    "sha1","16","907.71","848.90","914.84","941.14","905.42","","875.96"
    "sha1","16384","449500.50","442253.31","452444.16","455917.57","452520.62","","444066.47"
    "sha1","256","14321.58","13908.74","14417.49","14617.94","14470.31","","13754.11"
    "sha1","64","3640.13","3408.53","3641.94","3709.48","3638.78","","3457.37"
    "sha1","8192","299819.01","295848.62","303437.14","304406.53","306358.95","","300010.15"
    "sha256","1024","53243.90","51470.68","53679.10","54240.26","53675.01","30794.41","52570.79"
    "sha256","16","909.54","872.57","894.22","939.93","892.58","512.16","862.73"
    "sha256","16384","445011.29","432395.61","439522.65","450925.91","444847.45","244454.74","435825.32"
    "sha256","256","14011.14","13438.55","14033.75","14335.23","14072.92","8034.47","13711.53"
    "sha256","64","3542.06","3404.33","3546.09","3630.87","3560.00","2036.01","3478.34"
    "sha256","8192","298519.21","289005.57","293178.03","303398.91","298650.28","165456.55","291097.26"
    "sha512","1024","43712.17","41995.26","43342.85","44528.64","43428.18","22118.40","42614.78"
    "sha512","16","910.47","863.99","894.39","941.55","900.90","510.58","885.94"
    "sha512","16384","145659.22","145511.77","146210.82","147139.24","146538.50","60664.49","146052.44"
    "sha512","256","13119.91","12862.63","13264.98","13693.44","13124.86","7281.15","13126.66"
    "sha512","64","3611.33","3459.58","3612.10","3769.90","3604.86","2043.24","3543.47"
    "sha512","8192","126440.79","124895.23","125804.54","127606.78","126383.45","54209.19","125441.37"




.. csv-table:: OpenSSL CPU Load
    :header: "Algorithm","am68_sk-fs: CPU Load","am69_sk-fs: CPU Load","j7200-evm: CPU Load","j721e-idk-gw: CPU Load","j721s2-evm: CPU Load","j722s_evm-fs: CPU Load","j784s4-evm: CPU Load"

    "aes-128-cbc","33.00","33.00","33.00","34.00","33.00","35.00","33.00"
    "aes-128-ecb","33.00","34.00","33.00","34.00","33.00","36.00","34.00"
    "aes-192-cbc","33.00","34.00","33.00","34.00","33.00","34.00","33.00"
    "aes-192-ecb","33.00","33.00","33.00","34.00","33.00","35.00","33.00"
    "aes-256-cbc","32.00","33.00","33.00","33.00","33.00","34.00","33.00"
    "aes-256-ecb","33.00","33.00","33.00","33.00","33.00","34.00","33.00"
    "des3","30.00","30.00","31.00","30.00","29.00","","29.00"
    "sha1","98.00","98.00","98.00","98.00","98.00","","98.00"
    "sha256","98.00","98.00","98.00","98.00","98.00","98.00","98.00"
    "sha512","98.00","93.00","98.00","98.00","98.00","98.00","99.00"



Listed for each algorithm are the code snippets used to run each
  benchmark test.

::

    time -v openssl speed -elapsed -evp aes-128-cbc

 



 
 

 

Performance and Benchmarks not available in this release.




