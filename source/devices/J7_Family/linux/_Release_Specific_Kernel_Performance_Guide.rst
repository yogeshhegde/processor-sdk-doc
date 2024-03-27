
======================================
 Linux 09.02.00 Performance Guide
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

    "af_unix_sock_stream_latency (microsec)","19.31","16.18","14.77","19.06","19.05","24.67","17.91"
    "af_unix_socket_stream_bandwidth (MBs)","2131.64","1723.44","1671.29","2051.41","2031.24","1070.38","3496.57"
    "bw_file_rd-io-1mb (MB/s)","3057.00","3358.21","3126.15","3041.14","1249.48","1187.25","3553.39"
    "bw_file_rd-o2c-1mb (MB/s)","1516.17","618.27","1519.76","1789.98","940.20","642.88","1671.89"
    "bw_mem-bcopy-16mb (MB/s)","3809.07","3445.31","2373.18","2866.36","2804.07","1750.36","3730.47"
    "bw_mem-bcopy-1mb (MB/s)","4779.41","9822.44","3261.70","4759.29","4608.29","1880.98","9849.36"
    "bw_mem-bcopy-2mb (MB/s)","4035.96","4687.22","2521.61","3958.26","2938.63","1660.85","5397.63"
    "bw_mem-bcopy-4mb (MB/s)","3217.50","4087.19","2333.72","3923.88","3857.90","1677.85","4633.20"
    "bw_mem-bcopy-8mb (MB/s)","3778.34","3615.00","2369.32","3127.85","3725.55","1752.08","3942.83"
    "bw_mem-bzero-16mb (MB/s)","10936.43","10862.19","2306.47","9612.50","10886.21","6614.30","10838.27"
    "bw_mem-bzero-1mb (MB/s)","9024.86 (min 4779.41, max 13270.31)","11787.81 (min 9822.44, max 13753.17)","4067.02 (min 3261.70, max 4872.34)","8640.83 (min 4759.29, max 12522.36)","8827.83 (min 4608.29, max 13047.36)","4236.41 (min 1880.98, max 6591.84)","11802.51 (min 9849.36, max 13755.66)"
    "bw_mem-bzero-2mb (MB/s)","7917.13 (min 4035.96, max 11798.29)","9180.60 (min 4687.22, max 13673.98)","2716.41 (min 2521.61, max 2911.21)","8040.85 (min 3958.26, max 12123.44)","7297.48 (min 2938.63, max 11656.33)","4131.90 (min 1660.85, max 6602.95)","9549.40 (min 5397.63, max 13701.17)"
    "bw_mem-bzero-4mb (MB/s)","7121.43 (min 3217.50, max 11025.36)","8180.78 (min 4087.19, max 12274.37)","2402.96 (min 2333.72, max 2472.19)","7870.36 (min 3923.88, max 11816.84)","7420.44 (min 3857.90, max 10982.98)","4143.62 (min 1677.85, max 6609.39)","8454.89 (min 4633.20, max 12276.58)"
    "bw_mem-bzero-8mb (MB/s)","7374.26 (min 3778.34, max 10970.17)","7489.32 (min 3615.00, max 11363.64)","2362.87 (min 2356.41, max 2369.32)","7331.77 (min 3127.85, max 11535.69)","7334.73 (min 3725.55, max 10943.91)","4182.37 (min 1752.08, max 6612.66)","7597.30 (min 3942.83, max 11251.76)"
    "bw_mem-cp-16mb (MB/s)","2173.91","2453.24","981.11","1559.15","2204.46","869.33","2537.27"
    "bw_mem-cp-1mb (MB/s)","7951.95 (min 2676.86, max 13227.03)","8846.38 (min 3958.53, max 13734.22)","3056.57 (min 1263.99, max 4849.14)","7156.81 (min 1739.80, max 12573.82)","7939.06 (min 2670.23, max 13207.89)","1140.55 (min 856.60, max 1424.50)","8753.32 (min 3770.87, max 13735.77)"
    "bw_mem-cp-2mb (MB/s)","6971.19 (min 2186.59, max 11755.78)","8195.73 (min 2756.72, max 13634.73)","1969.16 (min 1021.80, max 2916.51)","6868.74 (min 1553.28, max 12184.20)","6999.84 (min 2192.58, max 11807.10)","1040.68 (min 844.12, max 1237.24)","8324.00 (min 2997.38, max 13650.62)"
    "bw_mem-cp-4mb (MB/s)","6601.90 (min 2190.58, max 11013.22)","7807.22 (min 2843.94, max 12770.49)","1705.76 (min 954.88, max 2456.63)","6689.54 (min 1507.44, max 11871.64)","6569.93 (min 2152.85, max 10987.00)","1077.95 (min 891.07, max 1264.82)","7665.19 (min 3049.36, max 12281.02)"
    "bw_mem-cp-8mb (MB/s)","6576.64 (min 2183.11, max 10970.17)","6937.27 (min 2514.93, max 11359.60)","1641.70 (min 950.01, max 2333.38)","6525.43 (min 1456.66, max 11594.20)","6558.63 (min 2193.88, max 10923.37)","1114.52 (min 910.64, max 1318.39)","6977.08 (min 2612.67, max 11341.49)"
    "bw_mem-fcp-16mb (MB/s)","3769.58","3406.79","2420.21","2833.36","3710.14","1591.25","3703.70"
    "bw_mem-fcp-1mb (MB/s)","8623.95 (min 3977.58, max 13270.31)","10091.73 (min 6430.28, max 13753.17)","4103.72 (min 3335.09, max 4872.34)","8148.65 (min 3774.94, max 12522.36)","6523.68 (min 0.00, max 13047.36)","4084.84 (min 1577.84, max 6591.84)","10204.83 (min 6653.99, max 13755.66)"
    "bw_mem-fcp-2mb (MB/s)","7857.63 (min 3916.96, max 11798.29)","8824.27 (min 3974.56, max 13673.98)","2696.96 (min 2482.71, max 2911.21)","8043.35 (min 3963.25, max 12123.44)","7741.31 (min 3826.29, max 11656.33)","3995.68 (min 1388.41, max 6602.95)","9172.85 (min 4644.52, max 13701.17)"
    "bw_mem-fcp-4mb (MB/s)","7346.20 (min 3667.03, max 11025.36)","8103.37 (min 3932.36, max 12274.37)","2427.28 (min 2382.37, max 2472.19)","7823.40 (min 3829.95, max 11816.84)","7379.77 (min 3776.55, max 10982.98)","4099.29 (min 1589.19, max 6609.39)","8359.28 (min 4441.98, max 12276.58)"
    "bw_mem-fcp-8mb (MB/s)","7319.39 (min 3668.60, max 10970.17)","7464.62 (min 3565.59, max 11363.64)","2387.58 (min 2356.41, max 2418.75)","7319.24 (min 3102.78, max 11535.69)","7347.25 (min 3750.59, max 10943.91)","4106.65 (min 1600.64, max 6612.66)","7566.69 (min 3881.61, max 11251.76)"
    "bw_mem-frd-16mb (MB/s)","4693.46","3905.77","6317.45","4798.32","4529.37","1779.76","4368.60"
    "bw_mem-frd-1mb (MB/s)","4719.68 (min 3977.58, max 5461.77)","7181.15 (min 6430.28, max 7932.01)","4804.66 (min 3335.09, max 6274.22)","4630.20 (min 3774.94, max 5485.46)","2586.21 (min 0.00, max 5172.41)","1691.12 (min 1577.84, max 1804.40)","7307.46 (min 6653.99, max 7960.92)"
    "bw_mem-frd-2mb (MB/s)","4578.57 (min 3916.96, max 5240.17)","4169.22 (min 3974.56, max 4363.88)","4441.36 (min 2482.71, max 6400.00)","4901.34 (min 3963.25, max 5839.42)","4478.58 (min 3826.29, max 5130.86)","1523.39 (min 1388.41, max 1658.37)","4708.02 (min 4644.52, max 4771.52)"
    "bw_mem-frd-4mb (MB/s)","4206.00 (min 3667.03, max 4744.96)","4139.31 (min 3932.36, max 4346.25)","4315.58 (min 2382.37, max 6248.78)","4746.33 (min 3829.95, max 5662.71)","4182.98 (min 3776.55, max 4589.41)","1656.05 (min 1589.19, max 1722.90)","4745.33 (min 4441.98, max 5048.68)"
    "bw_mem-frd-8mb (MB/s)","4186.21 (min 3668.60, max 4703.81)","3943.40 (min 3565.59, max 4321.21)","4357.50 (min 2418.75, max 6296.24)","4256.38 (min 3102.78, max 5409.97)","3407.86 (min 3065.13, max 3750.59)","1636.18 (min 1600.64, max 1671.72)","4431.08 (min 3881.61, max 4980.54)"
    "bw_mem-fwr-16mb (MB/s)","10945.78","10832.77","2326.93","9605.28","10888.06","1344.42","10788.94"
    "bw_mem-fwr-1mb (MB/s)","9344.40 (min 5461.77, max 13227.03)","10833.12 (min 7932.01, max 13734.22)","5561.68 (min 4849.14, max 6274.22)","9029.64 (min 5485.46, max 12573.82)","9190.15 (min 5172.41, max 13207.89)","1614.45 (min 1424.50, max 1804.40)","10848.35 (min 7960.92, max 13735.77)"
    "bw_mem-fwr-2mb (MB/s)","8497.98 (min 5240.17, max 11755.78)","8999.31 (min 4363.88, max 13634.73)","4658.26 (min 2916.51, max 6400.00)","9011.81 (min 5839.42, max 12184.20)","8468.98 (min 5130.86, max 11807.10)","1447.81 (min 1237.24, max 1658.37)","9211.07 (min 4771.52, max 13650.62)"
    "bw_mem-fwr-4mb (MB/s)","7879.09 (min 4744.96, max 11013.22)","8558.37 (min 4346.25, max 12770.49)","4352.71 (min 2456.63, max 6248.78)","8767.18 (min 5662.71, max 11871.64)","7788.21 (min 4589.41, max 10987.00)","1493.86 (min 1264.82, max 1722.90)","8664.85 (min 5048.68, max 12281.02)"
    "bw_mem-fwr-8mb (MB/s)","7836.99 (min 4703.81, max 10970.17)","7840.41 (min 4321.21, max 11359.60)","4314.81 (min 2333.38, max 6296.24)","8502.09 (min 5409.97, max 11594.20)","6994.25 (min 3065.13, max 10923.37)","1495.06 (min 1318.39, max 1671.72)","8161.02 (min 4980.54, max 11341.49)"
    "bw_mem-rd-16mb (MB/s)","5482.27","4679.73","6571.74","5144.79","5286.63","1853.78","5156.30"
    "bw_mem-rd-1mb (MB/s)","6632.61 (min 3016.59, max 10248.62)","16342.63 (min 15381.73, max 17303.53)","11322.92 (min 7686.54, max 14959.29)","5797.33 (min 2857.14, max 8737.52)","9011.97 (min 7361.06, max 10662.88)","1924.89 (min 1754.08, max 2095.70)","14048.57 (min 12790.06, max 15307.07)"
    "bw_mem-rd-2mb (MB/s)","4937.22 (min 3291.88, max 6582.56)","5508.64 (min 3539.25, max 7478.03)","4018.98 (min 978.31, max 7059.65)","4088.96 (min 1693.77, max 6484.15)","3913.77 (min 3034.90, max 4792.63)","1695.82 (min 1563.48, max 1828.15)","5677.73 (min 3802.28, max 7553.17)"
    "bw_mem-rd-4mb (MB/s)","3968.97 (min 2341.58, max 5596.36)","4576.25 (min 3892.31, max 5260.19)","3720.72 (min 787.09, max 6654.34)","3838.05 (min 1360.31, max 6315.79)","3887.78 (min 2393.78, max 5381.77)","1722.43 (min 1605.78, max 1839.08)","5068.92 (min 4065.73, max 6072.11)"
    "bw_mem-rd-8mb (MB/s)","3870.25 (min 2287.18, max 5453.31)","4524.64 (min 3851.09, max 5198.18)","3665.13 (min 746.97, max 6583.28)","3751.04 (min 1732.16, max 5769.92)","3757.99 (min 2218.83, max 5297.14)","1783.74 (min 1735.55, max 1831.92)","4947.96 (min 3975.48, max 5920.44)"
    "bw_mem-rdwr-16mb (MB/s)","2231.83","2777.78","752.27","1816.53","1867.63","1749.78","2940.64"
    "bw_mem-rdwr-1mb (MB/s)","4265.72 (min 2676.86, max 5854.58)","6773.40 (min 3958.53, max 9588.27)","2713.27 (min 1263.99, max 4162.54)","2304.50 (min 1739.80, max 2869.20)","3701.98 (min 2670.23, max 4733.73)","1203.36 (min 856.60, max 1550.12)","6637.77 (min 3770.87, max 9504.66)"
    "bw_mem-rdwr-2mb (MB/s)","2580.84 (min 2186.59, max 2975.08)","3755.40 (min 2756.72, max 4754.07)","1004.65 (min 987.49, max 1021.80)","1396.51 (min 1239.73, max 1553.28)","2253.89 (min 2192.58, max 2315.20)","1133.81 (min 844.12, max 1423.49)","3794.30 (min 2997.38, max 4591.21)"
    "bw_mem-rdwr-4mb (MB/s)","2274.19 (min 2190.58, max 2357.80)","3104.34 (min 2843.94, max 3364.74)","874.86 (min 794.83, max 954.88)","1786.25 (min 1507.44, max 2065.05)","2237.70 (min 2152.85, max 2322.54)","1253.07 (min 891.07, max 1615.07)","3442.84 (min 3049.36, max 3836.32)"
    "bw_mem-rdwr-8mb (MB/s)","2231.16 (min 2183.11, max 2279.20)","2826.71 (min 2514.93, max 3138.49)","853.15 (min 756.29, max 950.01)","1829.96 (min 1456.66, max 2203.25)","2231.69 (min 2193.88, max 2269.50)","1312.40 (min 910.64, max 1714.16)","3112.48 (min 2612.67, max 3612.28)"
    "bw_mem-wr-16mb (MB/s)","2270.15","3081.66","742.46","1805.87","2233.70","1742.54","3137.87"
    "bw_mem-wr-1mb (MB/s)","4435.59 (min 3016.59, max 5854.58)","13445.90 (min 9588.27, max 17303.53)","5924.54 (min 4162.54, max 7686.54)","2863.17 (min 2857.14, max 2869.20)","7698.31 (min 4733.73, max 10662.88)","1652.10 (min 1550.12, max 1754.08)","11147.36 (min 9504.66, max 12790.06)"
    "bw_mem-wr-2mb (MB/s)","3133.48 (min 2975.08, max 3291.88)","4146.66 (min 3539.25, max 4754.07)","982.90 (min 978.31, max 987.49)","1466.75 (min 1239.73, max 1693.77)","2675.05 (min 2315.20, max 3034.90)","1493.49 (min 1423.49, max 1563.48)","4196.75 (min 3802.28, max 4591.21)"
    "bw_mem-wr-4mb (MB/s)","2349.69 (min 2341.58, max 2357.80)","3628.53 (min 3364.74, max 3892.31)","790.96 (min 787.09, max 794.83)","1712.68 (min 1360.31, max 2065.05)","2358.16 (min 2322.54, max 2393.78)","1610.43 (min 1605.78, max 1615.07)","3951.03 (min 3836.32, max 4065.73)"
    "bw_mem-wr-8mb (MB/s)","2283.19 (min 2279.20, max 2287.18)","3494.79 (min 3138.49, max 3851.09)","751.63 (min 746.97, max 756.29)","1967.71 (min 1732.16, max 2203.25)","2244.17 (min 2218.83, max 2269.50)","1724.86 (min 1714.16, max 1735.55)","3793.88 (min 3612.28, max 3975.48)"
    "bw_mmap_rd-mo-1mb (MB/s)","8554.79","12552.30","12324.93","8337.68","6150.51","2064.34","12801.48"
    "bw_mmap_rd-o2c-1mb (MB/s)","1337.79","311.82","1538.46","1416.43","1281.58","596.93","2246.80"
    "bw_pipe (MB/s)","829.58","665.14","683.54","827.99","818.75","655.46","915.58"
    "bw_unix (MB/s)","2131.64","1723.44","1671.29","2051.41","2031.24","1070.38","3496.57"
    "lat_connect (us)","34.39","34.47","34.73","33.46","34.99","57.80","33.90"
    "lat_ctx-2-128k (us)","3.34","3.24","3.29","3.25","3.25","6.01","5.69"
    "lat_ctx-2-256k (us)","2.61","2.40","2.59","2.70","2.57","7.86","4.98"
    "lat_ctx-4-128k (us)","3.31","4.00","3.24","3.02","3.26","5.17","3.83"
    "lat_ctx-4-256k (us)","2.15","2.57","2.17","2.15","2.12","4.00","2.75"
    "lat_fs-0k (num_files)","447.00","459.00","544.00","455.00","511.00","295.00","476.00"
    "lat_fs-10k (num_files)","171.00","225.00","191.00","174.00","188.00","110.00","213.00"
    "lat_fs-1k (num_files)","239.00","308.00","282.00","260.00","262.00","194.00","300.00"
    "lat_fs-4k (num_files)","302.00","316.00","287.00","309.00","305.00","149.00","315.00"
    "lat_mem_rd-stride128-sz1000k (ns)","11.62","5.65","10.18","10.69","11.99","32.51","5.70"
    "lat_mem_rd-stride128-sz125k (ns)","5.57","5.65","5.57","5.57","5.57","6.27","5.42"
    "lat_mem_rd-stride128-sz250k (ns)","5.57","5.65","5.57","5.57","5.57","6.53","5.65"
    "lat_mem_rd-stride128-sz31k (ns)","4.67","3.40","5.12","3.36","4.67","4.09","3.85"
    "lat_mem_rd-stride128-sz50 (ns)","2.00","2.00","2.00","2.00","2.00","2.40","2.00"
    "lat_mem_rd-stride128-sz500k (ns)","5.59","5.65","5.58","5.57","6.00","14.53","5.65"
    "lat_mem_rd-stride128-sz62k (ns)","5.34","5.65","4.89","5.12","4.67","5.85","5.21"
    "lat_mmap-1m (us)","34.00","34.00","34.00","33.00","27.00","64.00","33.00"
    "lat_ops-double-add (ns)","1.96","1.96","1.96","1.96","1.96","3.20","1.96"
    "lat_ops-double-div (ns)","9.01","9.01","9.01","9.01","9.01","17.63","9.00"
    "lat_ops-double-mul (ns)","2.00","2.00","2.00","2.00","2.00","3.21","2.00"
    "lat_ops-float-add (ns)","1.96","1.96","1.96","1.96","1.96","3.20","1.96"
    "lat_ops-float-div (ns)","5.50","5.50","5.50","5.51","5.51","10.41","5.50"
    "lat_ops-float-mul (ns)","2.00","2.00","2.00","2.00","2.00","3.20","2.00"
    "lat_ops-int-add (ns)","0.50","0.50","0.50","0.50","0.50","0.80","0.50"
    "lat_ops-int-bit (ns)","0.33","0.33","0.33","0.33","0.33","0.53","0.33"
    "lat_ops-int-div (ns)","4.09","4.00","4.00","4.00","4.01","4.81","4.00"
    "lat_ops-int-mod (ns)","4.80","4.67","4.67","4.67","4.67","5.07","4.67"
    "lat_ops-int-mul (ns)","1.52","1.52","1.52","1.52","1.52","3.44","1.52"
    "lat_ops-int64-add (ns)","0.51","0.50","0.50","0.50","0.50","0.80","0.50"
    "lat_ops-int64-bit (ns)","0.34","0.33","0.33","0.33","0.33","0.53","0.33"
    "lat_ops-int64-div (ns)","3.00","3.00","3.00","3.00","3.00","7.61","3.00"
    "lat_ops-int64-mod (ns)","5.66","5.67","5.67","5.67","5.67","5.88","5.67"
    "lat_ops-int64-mul (ns)","2.52","2.52","2.52","2.52","2.52","3.98","2.52"
    "lat_pagefault (us)","0.56","0.55","0.56","0.55","0.57","1.54","0.55"
    "lat_pipe (us)","11.84","12.19","11.79","11.65","12.90","21.87","12.27"
    "lat_proc-exec (us)","445.08","413.85","459.00","394.85","452.18","835.14","408.36"
    "lat_proc-fork (us)","372.67","344.19","370.86","328.75","372.80","668.50","340.06"
    "lat_proc-proccall (us)","0.00","0.00","0.00","0.00","0.00","0.01","0.00"
    "lat_select (us)","10.86","10.86","10.82","10.90","10.85","37.39","10.80"
    "lat_sem (us)","1.34","1.29","1.51","1.49","1.52","2.27","2.28"
    "lat_sig-catch (us)","2.77","2.67","2.77","2.66","2.78","5.95","2.73"
    "lat_sig-install (us)","0.50","0.51","0.52","0.50","0.60","0.72","0.50"
    "lat_sig-prot (us)","0.49","0.46","0.32","0.39","0.48","0.53","0.47"
    "lat_syscall-fstat (us)","1.16","1.17","1.19","1.21","1.19","2.81","1.21"
    "lat_syscall-null (us)","0.37","0.37","0.37","0.37","0.37","0.52","0.37"
    "lat_syscall-open (us)","140.50","3148.50","152.87","138.17","149.57","149.23","113.84"
    "lat_syscall-read (us)","0.50","0.50","0.50","0.50","0.51","0.86","0.50"
    "lat_syscall-stat (us)","1.86","1.90","1.86","1.89","1.90","4.13","1.90"
    "lat_syscall-write (us)","0.43","0.44","0.45","0.43","0.43","0.72","0.42"
    "lat_tcp (us)","0.76","0.78","0.75","0.78","0.85","1.05","0.77"
    "lat_unix (us)","19.31","16.18","14.77","19.06","19.05","24.67","17.91"
    "latency_for_0.50_mb_block_size (nanosec)","5.59","5.65","5.58","5.57","6.00","14.53","5.65"
    "latency_for_1.00_mb_block_size (nanosec)","5.81 (min 0.00, max 11.62)","2.82 (min 0.00, max 5.65)","5.09 (min 0.00, max 10.18)","5.34 (min 0.00, max 10.69)","5.99 (min 0.00, max 11.99)","16.26 (min 0.00, max 32.51)","2.85 (min 0.00, max 5.70)"
    "pipe_bandwidth (MBs)","829.58","665.14","683.54","827.99","818.75","655.46","915.58"
    "pipe_latency (microsec)","11.84","12.19","11.79","11.65","12.90","21.87","12.27"
    "procedure_call (microsec)","0.00","0.00","0.00","0.00","0.00","0.01","0.00"
    "select_on_200_tcp_fds (microsec)","10.86","10.86","10.82","10.90","10.85","37.39","10.80"
    "semaphore_latency (microsec)","1.34","1.29","1.51","1.49","1.52","2.27","2.28"
    "signal_handler_latency (microsec)","0.50","0.51","0.52","0.50","0.60","0.72","0.50"
    "signal_handler_overhead (microsec)","2.77","2.67","2.77","2.66","2.78","5.95","2.73"
    "tcp_ip_connection_cost_to_localhost (microsec)","34.39","34.47","34.73","33.46","34.99","57.80","33.90"
    "tcp_latency_using_localhost (microsec)","0.76","0.78","0.75","0.78","0.85","1.05","0.77"




Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

Execute the benchmark with the following:

::

    runDhrystone

.. csv-table:: Dhrystone Benchmarks
    :header: "Benchmarks","am68_sk-fs: perf","am69_sk-fs: perf","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j722s_evm-fs: perf","j784s4-evm: perf"

    "cpu_clock (MHz)","2000.00","2000.00","2000.00","2000.00","2000.00","1250.00","2000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","4.70","4.40","4.40","5.70","4.70","2.90","4.40"
    "dhrystone_per_second (DhrystoneP)","16666667.00","15384615.00","15384615.00","20000000.00","16666667.00","6451613.00","15384615.00"




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

    "linpack (Kflops)","2496970.00","2480733.00","2477153.00","2613882.00","2612887.00","515670.00","2359679.00"




NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html

.. csv-table:: NBench Benchmarks
    :header: "Benchmarks","am68_sk-fs: perf","am69_sk-fs: perf","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j722s_evm-fs: perf","j784s4-evm: perf"

    "assignment (Iterations)","30.69","30.58","30.55","30.73","30.84","12.42","30.76"
    "fourier (Iterations)","53395.00","50296.00","65122.00","64540.00","65180.00","20213.00","50293.00"
    "fp_emulation (Iterations)","214.62","214.61","214.64","214.63","214.63","82.44","214.64"
    "huffman (Iterations)","2384.60","2386.00","2374.80","2384.00","2383.80","1044.00","2380.80"
    "idea (Iterations)","7995.10","7996.30","7995.00","7995.50","7993.10","3075.50","7995.70"
    "lu_decomposition (Iterations)","1344.30","1338.00","1355.60","1360.00","1368.20","477.34","1361.80"
    "neural_net (Iterations)","29.36","29.19","30.23","28.98","30.29","7.87","27.62"
    "numeric_sort (Iterations)","849.32","853.19","847.65","854.21","842.76","525.89","851.20"
    "string_sort (Iterations)","392.16","413.96","398.55","414.70","414.43","147.26","425.30"




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

    "add (MB/s)","6486.00","6100.30","5456.50","5346.30","6470.60","2419.60","6219.40"
    "copy (MB/s)","7762.90","6089.20","4777.70","5630.80","7784.00","3577.70","6376.10"
    "scale (MB/s)","7866.30","6059.00","4846.00","5487.70","7900.40","3148.30","6367.40"
    "triad (MB/s)","6486.50","6079.20","5467.50","5352.20","6476.50","2167.50","6206.70"




CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.


.. csv-table:: CoreMarkPro Benchmarks
    :header: "Benchmarks","am68_sk-fs: perf","am69_sk-fs: perf","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j722s_evm-fs: perf","j784s4-evm: perf"

    "cjpeg-rose7-preset (workloads/)","83.33","81.97","83.33","83.33","83.33","37.59","83.33"
    "core (workloads/)","0.78","0.78","0.78","0.78","0.78","0.27","0.78"
    "coremark-pro ()","2486.15","2486.54","2436.24","2487.62","2477.94","843.40","2495.01"
    "linear_alg-mid-100x100-sp (workloads/)","81.97","79.24","80.13","80.65","80.65","13.11","81.83"
    "loops-all-mid-10k-sp (workloads/)","2.47","2.47","2.46","2.46","2.46","0.64","2.46"
    "nnet_test (workloads/)","3.63","3.64","3.63","3.65","3.64","0.97","3.63"
    "parser-125k (workloads/)","11.11","10.87","10.99","11.24","11.11","7.81","10.87"
    "radix2-big-64k (workloads/)","256.15","274.95","225.12","258.33","253.04","66.22","271.89"
    "sha-test (workloads/)","158.73","158.73","156.25","158.73","158.73","72.99","158.73"
    "zip-test (workloads/)","47.62","47.62","47.62","47.62","47.62","19.61","47.62"



 
 


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

    "4m-check (workloads/)","896.38","1050.42","933.18","925.93","877.19","377.53","1053.52"
    "4m-check-reassembly (workloads/)","155.28","203.25","122.55","148.81","150.38","116.69","201.61"
    "4m-check-reassembly-tcp (workloads/)","99.21","119.05","91.58","100.81","98.81","55.93","117.93"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","42.05","36.74","40.93","45.08","41.61","30.14","41.01"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","2.69","4.80","2.69","2.72","2.70","1.74","4.87"
    "4m-cmykw2 (workloads/)","315.46","602.41","313.97","318.47","269.54","214.13","606.06"
    "4m-cmykw2-rotatew2 (workloads/)","58.88","46.48","58.48","62.70","60.00","44.98","54.25"
    "4m-reassembly (workloads/)","130.21","149.03","109.17","131.23","130.55","81.37","151.29"
    "4m-rotatew2 (workloads/)","70.13","53.97","71.07","74.63","69.06","48.83","48.83"
    "4m-tcp-mixed (workloads/)","262.30","275.86","258.07","275.86","262.30","109.59","271.19"
    "4m-x264w2 (workloads/)","2.78","4.97","2.78","2.79","2.73","1.79","5.09"
    "empty-wld (workloads/)","","","1.00","1.00","","",""
    "idct-4m (workloads/)","34.93","35.14","34.89","35.10","34.95","17.20","35.12"
    "idct-4mw1 (workloads/)","34.98","35.14","34.94","35.00","34.95","17.21","35.14"
    "ippktcheck-4m (workloads/)","913.41","1050.86","941.62","930.06","884.33","378.16","1048.22"
    "ippktcheck-4mw1 (workloads/)","918.78","1049.10","944.82","925.24","886.53","377.59","1052.19"
    "ipres-4m (workloads/)","169.11","201.07","159.07","182.48","164.29","103.95","204.36"
    "ipres-4mw1 (workloads/)","169.11","199.73","157.56","182.26","161.81","103.38","202.98"
    "md5-4m (workloads/)","46.30","47.87","46.08","40.45","45.81","26.18","47.87"
    "md5-4mw1 (workloads/)","45.93","47.92","45.96","49.16","46.10","26.18","47.71"
    "rgbcmyk-4m (workloads/)","163.27","164.20","163.13","163.00","163.27","56.13","163.53"
    "rgbcmyk-4mw1 (workloads/)","163.00","163.93","163.13","163.93","162.87","56.24","163.93"
    "rotate-4ms1 (workloads/)","51.65","55.13","51.87","54.53","51.18","21.40","54.70"
    "rotate-4ms1w1 (workloads/)","51.65","54.95","52.25","54.53","51.76","21.42","54.88"
    "rotate-4ms64 (workloads/)","52.30","55.56","53.02","55.80","52.41","21.76","55.49"
    "rotate-4ms64w1 (workloads/)","52.80","55.62","53.02","55.43","52.03","21.83","55.74"
    "x264-4mq (workloads/)","1.42","1.41","1.43","1.43","1.43","0.52","1.45"
    "x264-4mqw1 (workloads/)","1.42","1.41","1.43","1.44","1.43","0.52","1.43"



 
 



|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: Boot time MMCSD
    :header: "Boot Configuration","am68_sk-fs: boot time (sec)","am69_sk-fs: boot time (sec)","j7200-evm: boot time (sec)","j721e-idk-gw: boot time (sec)","j721s2-evm: boot time (sec)","j722s_evm-fs: boot time (sec)","j784s4-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","14.32 (min 14.12, max 14.51)","14.00 (min 13.47, max 14.65)","13.85 (min 13.68, max 14.04)","19.13 (min 18.85, max 19.43)","17.23 (min 16.89, max 17.48)","16.67 (min 15.54, max 19.01)","15.75 (min 15.26, max 16.52)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","4.34 (min 4.32, max 4.37)","5.15 (min 5.13, max 5.19)","4.14 (min 4.11, max 4.16)","4.93 (min 4.91, max 4.97)","5.34 (min 5.28, max 5.38)","4.30 (min 4.26, max 4.32)","6.26 (min 6.22, max 6.32)"



 
 



|

ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64


.. csv-table:: Audio Capture
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "11025","352791.00","0.19"
    "16000","511992.00","0.31"
    "22050","705578.00","0.27"
    "24000","705584.00","0.29"
    "32000","1023981.00","0.20"
    "44100","1411176.00","0.51"
    "48000","1535975.00","0.68"
    "88200","2822353.00","0.86"
    "96000","3071941.00","0.39"




.. csv-table:: Audio Playback
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "11025","352938.00","0.21"
    "16000","512203.00","0.31"
    "22050","705867.00","0.29"
    "24000","705874.00","0.29"
    "32000","1024402.00","0.43"
    "44100","1411756.00","0.47"
    "48000","1536607.00","0.64"
    "88200","2823514.00","0.81"
    "96000","3073213.00","1.10"

 
 



 



|

Graphics SGX/RGX Driver
-------------------------
 




Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table:: Glmark2 Performance
    :header: "Benchmark","am68_sk-fs: Score","am69_sk-fs: Score","j721e-idk-gw: Score","j721s2-evm: Score","j722s_evm-fs: Score","j784s4-evm: Score"

    "Glmark2-DRM","56.00","56.00","9.00","57.00","9.00"
    "Glmark2-Wayland","1281.00","1402.00","1170.00","1277.00","787.00","1437.00"

 
 

 

 



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

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","182.29","13.80","181.94","2.96","1465.91","65.74","1846.14","74.64","1859.89","72.34","1853.95","61.97","1859.93","19.54"




.. rubric::  TCP Bidirectional Throughput Interrupt Pacing
   :name: CPSW2g-tcp-bidirectional-throughput-interrupt-pacing

.. csv-table:: CPSW2g TCP Bidirectional Throughput Interrupt Pacing
    :header: "Command Used","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j722s_evm-fs: THROUGHPUT (Mbits/sec)","j722s_evm-fs: CPU Load % (LOCAL_CPU_UTIL)","j784s4-evm: THROUGHPUT (Mbits/sec)","j784s4-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1587.92","43.56","1868.04","31.89","1874.63","40.55","1753.96","31.10","1876.82","8.23"




.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table:: CPSW2g UDP Egress Throughput 0 loss
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: Packets Per Second (kPPS)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: Packets Per Second (kPPS)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: Packets Per Second (kPPS)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j784s4-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j784s4-evm: THROUGHPUT (Mbits/sec)","j784s4-evm: Packets Per Second (kPPS)","j784s4-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","32.25","224.00","92.04","18.00","36.47","253.00","90.74","18.00","33.04","229.00","93.11","18.00","34.00","236.00","23.61"
    "128","82.00","159.79","244.00","92.18","82.00","163.64","249.00","90.65","82.00","151.35","231.00","91.88","82.00","140.17","214.00","23.57"
    "256","210.00","411.79","245.00","92.09","210.00","422.84","252.00","90.15","210.00","27.72","17.00","12.50","210.00","387.93","231.00","23.01"
    "1024","978.00","928.93","119.00","63.38","978.00","95.45","12.00","2.89","978.00","935.35","120.00","57.58"
    "1518","1472.00","956.17","81.00","60.88","1472.00","862.88","73.00","33.56","1472.00","953.59","81.00","35.55"




.. csv-table:: CPSW2g UDP Ingress Throughput 0 loss
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: Packets Per Second (kPPS)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: Packets Per Second (kPPS)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: Packets Per Second (kPPS)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j784s4-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j784s4-evm: THROUGHPUT (Mbits/sec)","j784s4-evm: Packets Per Second (kPPS)","j784s4-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.25","9.00","11.16","18.00","5.60","39.00","14.81","18.00","1.15","8.00","6.50"
    "128","82.00","7.02","11.00","7.71","82.00","22.11","34.00","13.57","82.00","11.55","18.00","12.55","82.00","27.62","42.00","4.60"
    "256","210.00","31.92","19.00","15.43","210.00","54.09","32.00","13.40","210.00","21.67","13.00","6.30","210.00","313.71","187.00","11.71"
    "1024","978.00","143.18","18.00","18.10","978.00","101.71","13.00","8.01","978.00","100.15","13.00","8.55"
    "1518","1472.00","113.05","10.00","11.78","1472.00","547.56","46.00","35.30","1472.00","279.09","24.00","18.89"




.. csv-table:: CPSW2g UDP Ingress Throughput possible loss
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j7200-evm: THROUGHPUT (Mbits/sec)","j7200-evm: Packets Per Second (kPPS)","j7200-evm: CPU Load % (LOCAL_CPU_UTIL)","j7200-evm: Packet Loss %","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: Packets Per Second (kPPS)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: Packet Loss %","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: Packets Per Second (kPPS)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: Packet Loss %","j784s4-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j784s4-evm: THROUGHPUT (Mbits/sec)","j784s4-evm: Packets Per Second (kPPS)","j784s4-evm: CPU Load % (LOCAL_CPU_UTIL)","j784s4-evm: Packet Loss %"

    "64","18.00","22.55","157.00","83.97","0.05","18.00","59.80","415.00","88.92","1.34","18.00","18.74","130.00","71.94","0.03"
    "128","82.00","261.32","398.00","91.71","8.36","82.00","272.40","415.00","91.14","3.54","82.00","90.57","138.00","74.61","3.01","82.00","275.75","420.00","22.18","47.38"
    "256","210.00","408.27","243.00","83.77","0.65","210.00","676.31","403.00","92.83","5.27","210.00","581.43","346.00","92.03","8.69","210.00","596.99","355.00","22.09","19.03"
    "1024","978.00","934.38","119.00","83.80","0.02","978.00","928.07","119.00","82.80","0.13","978.00","861.92","110.00","81.90","6.59"
    "1518","1472.00","947.57","80.00","83.54","0.04","1472.00","945.92","80.00","60.89","0.01","1472.00","956.62","81.00","68.02","0.02"

 
 

 

 
 



|

PCIe Driver
-------------------------

PCIe-ETH
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: PCIe Ethernet performance
    :header: "TCP Window Size(Kbytes)","j7200-evm: Bandwidth (Mbits/sec)","j721e-idk-gw: Bandwidth (Mbits/sec)","j721s2-evm: Bandwidth (Mbits/sec)"

    "8","226.40","0.00"
    "16","223.20","0.00"
    "32","0.00","0.00"
    "64","600.80","0.00"
    "128","738.40","0.00","0.00"
    "256","808.00","0.00","0.00"



 


PCIe-NVMe-SSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^
 

 


J721E-IDK-GW
"""""""""""""""""""""""""""




.. csv-table:: PCIE SSD EXT4 FIO 10G
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","719.00","12.44","1523.00","6.21"
    "4m","719.00","11.28","1524.00","4.45"
    "4k","191.00","48.45","167.00","35.78"
    "256k","736.00","12.42","1516.00","11.35"



- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY
 


J7200-EVM
"""""""""""""""""""""""""""




.. csv-table:: PCIE SSD EXT4 FIO 10G
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","813.00","16.77","1510.00","5.75"
    "4m","810.00","15.21","1524.00","4.43"
    "4k","192.00","48.56","166.00","36.04"
    "256k","816.00","14.22","1519.00","11.51"



- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY
 


J721S2-EVM
"""""""""""""""""""""""""""




.. csv-table:: PCIE SSD EXT4 FIO 10G
    :header: "Buffer size (bytes)","j721s2-evm: Write EXT4 Throughput (Mbytes/sec)","j721s2-evm: Write EXT4 CPU Load (%)","j721s2-evm: Read EXT4 Throughput (Mbytes/sec)","j721s2-evm: Read EXT4 CPU Load (%)"

    "1m","736.00","18.20","774.00","5.56"
    "4m","737.00","15.92","775.00","5.50"
    "4k","196.00","52.08","282.00","52.72"
    "256k","736.00","16.87","780.00","8.02"



- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY
 

 
 
 

 



|

OSPI Flash Driver
-------------------------

 

 

 

 


J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^




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

    "102400","0.17 (min 0.12, max 0.27)","13.60 (min 12.50, max 14.60)","28.50","6.90"
    "262144","0.13 (min 0.10, max 0.17)","12.41 (min 10.67, max 13.79)","28.33","6.90"
    "524288","0.13 (min 0.10, max 0.17)","13.18 (min 12.30, max 14.81)","28.18","10.00"
    "1048576","0.13 (min 0.10, max 0.17)","13.21 (min 12.01, max 14.20)","28.00","9.68"




RAW
"""""""""""""""""""""""""""

.. csv-table:: OSPI Raw Flash Driver
    :header: "File size (Mbytes)","j722s_evm-fs: Raw Read Throughput (Mbytes/sec)"

    "50","37.59"

 
 


J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^




RAW
"""""""""""""""""""""""""""

.. csv-table:: OSPI Raw Flash Driver
    :header: "File size (Mbytes)","j7200-evm: Raw Read Throughput (Mbytes/sec)"

    "50","125.00"

 
 

 


J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^




RAW
"""""""""""""""""""""""""""

.. csv-table:: OSPI Raw Flash Driver
    :header: "File size (Mbytes)","j784s4-evm: Raw Read Throughput (Mbytes/sec)"

    "50","263.16"

 
 

 

 
 

 



|

UBoot QSPI/OSPI Driver
-------------------------

 








J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT QSPI or OSPI
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","1548.00","37577.98"
    "800000","1550.05","39196.17"
    "1000000","1550.34","39766.99"
    "2000000","1550.85","40255.53"






J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT QSPI or OSPI
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","350.47","204800.00"
    "800000","353.15","248242.42"
    "1000000","353.35","277694.92"
    "2000000","353.03","300623.85"




J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT QSPI or OSPI
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "400000","374.65","204800.00"
    "800000","375.57","248242.42"
    "1000000","376.84","282482.76"
    "2000000","371.28","300623.85"

















 
 

 

 



|

UBoot UFS Driver
-------------------------


J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT UFS RAW
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","93090.91","372363.64"
    "800000","98698.80","481882.35"
    "1000000","93622.86","630153.85"







 
 



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

.. csv-table:: EMMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","60.10","1.47","314.00","1.41"
    "4m","60.20","1.37","314.00","1.01"
    "4k","56.40","26.38","56.00","23.26"
    "256k","60.00","1.84","316.00","2.96"




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: EMMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","60.40","1.39","175.00","1.05"
    "4m","60.50","1.18","175.00","0.73"
    "4k","48.70","22.68","56.00","23.63"
    "256k","60.60","1.70","174.00","2.11"




J722S-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: EMMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j722s_evm-fs: Write EXT4 Throughput (Mbytes/sec)","j722s_evm-fs: Write EXT4 CPU Load (%)","j722s_evm-fs: Read EXT4 Throughput (Mbytes/sec)","j722s_evm-fs: Read EXT4 CPU Load (%)"

    "1m","89.40","1.46","291.00","2.76"
    "4m","89.80","1.20","291.00","2.16"
    "4k","78.40","29.45","92.50","27.17"
    "256k","89.30","1.94","291.00","3.92"




J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: EMMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j721s2-evm: Write EXT4 Throughput (Mbytes/sec)","j721s2-evm: Write EXT4 CPU Load (%)","j721s2-evm: Read EXT4 Throughput (Mbytes/sec)","j721s2-evm: Read EXT4 CPU Load (%)"

    "1m","45.10","3.26","300.00","3.15"
    "4m","45.40","3.06","299.00","3.19"
    "4k","5.26","5.01","36.30","18.46"
    "256k","36.40","3.06","283.00","5.26"




J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: EMMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j784s4-evm: Write EXT4 Throughput (Mbytes/sec)","j784s4-evm: Write EXT4 CPU Load (%)","j784s4-evm: Read EXT4 Throughput (Mbytes/sec)","j784s4-evm: Read EXT4 CPU Load (%)"

    "1m","88.80","0.41","172.00","0.36"
    "4m","95.30","0.43","169.00","0.24"
    "4k","63.80","8.90","93.50","11.03"
    "256k","89.20","0.66","171.00","0.55"



 





 
 

 











 
 



|

UBoot EMMC Driver
-------------------------

 






J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT EMMC RAW
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "2000000","59904.94","309132.08"
    "4000000","60907.06","324435.64"




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT EMMC RAW
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "2000000","60681.48","173375.66"
    "4000000","60737.72","176646.90"




J722S-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT EMMC RAW
    :header: "File size (bytes in hex)","j722s_evm-fs: Write Throughput (Kbytes/sec)","j722s_evm-fs: Read Throughput (Kbytes/sec)"

    "2000000","96093.84","204800.00"
    "4000000","98107.78","243628.25"




J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT EMMC RAW
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "2000000","61134.33","309132.08"
    "4000000","61826.42","322837.44"




J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT EMMC RAW
    :header: "File size (bytes in hex)","j784s4-evm: Write Throughput (Kbytes/sec)","j784s4-evm: Read Throughput (Kbytes/sec)"

    "2000000","100207.95","239182.48"
    "4000000","98254.87","234057.14"













 
 

 



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

.. csv-table:: MMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","19.10","0.77","86.60","0.81"
    "4m","19.40","0.70","86.50","0.54"
    "4k","5.35","3.14","16.70","7.28"
    "256k","19.30","0.75","84.60","1.28"




J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: MMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j721s2-evm: Write EXT4 Throughput (Mbytes/sec)","j721s2-evm: Write EXT4 CPU Load (%)","j721s2-evm: Read EXT4 Throughput (Mbytes/sec)","j721s2-evm: Read EXT4 CPU Load (%)"

    "1m","43.40","1.52","87.30","0.93"
    "4m","42.50","1.20","87.80","0.77"
    "4k","3.66","2.66","16.40","8.01"
    "256k","39.40","1.87","85.70","1.39"




J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: MMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j784s4-evm: Write EXT4 Throughput (Mbytes/sec)","j784s4-evm: Write EXT4 CPU Load (%)","j784s4-evm: Read EXT4 Throughput (Mbytes/sec)","j784s4-evm: Read EXT4 CPU Load (%)"

    "1m","18.50","0.16","87.00","0.28"
    "4m","18.50","0.16","86.80","0.18"
    "4k","4.53","0.79","16.70","2.29"
    "256k","17.90","0.17","85.10","0.38"




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. csv-table:: MMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","33.10","0.94","43.60","0.48"
    "4m","34.10","0.81","43.60","0.44"
    "4k","3.52","1.99","13.90","5.76"
    "256k","33.20","0.97","43.10","0.65"



 
 


J722S-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: MMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","j722s_evm-fs: Write EXT4 Throughput (Mbytes/sec)","j722s_evm-fs: Write EXT4 CPU Load (%)","j722s_evm-fs: Read EXT4 Throughput (Mbytes/sec)","j722s_evm-fs: Read EXT4 CPU Load (%)"

    "1m","42.80","1.43","87.50","1.94"
    "4m","42.40","1.16","87.60","1.29"
    "4k","3.59","3.57","16.50","11.83"
    "256k","39.40","1.72","85.60","2.26"















 

 

 





 

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

    "400000","15693.49","34133.33"
    "800000","17138.08","39574.88"
    "1000000","23472.78","43002.62"




J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT MMCSD FAT
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","19980.49","71859.65"
    "800000","17925.60","81108.91"
    "1000000","20029.34","87148.94"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card



J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT MMCSD FAT
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "400000","19980.49","60235.29"
    "800000","20531.33","73142.86"
    "1000000","23574.10","81920.00"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card



J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT MMCSD FAT
    :header: "File size (bytes in hex)","j784s4-evm: Write Throughput (Kbytes/sec)","j784s4-evm: Read Throughput (Kbytes/sec)"

    "400000","30340.74","59362.32"
    "800000","33165.99","73801.80"
    "1000000","41478.48","81920.00"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
















 
 



|

USB Driver
-------------------------
 


USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^










.. csv-table:: USBDEVICE HIGHSPEED SLAVE_READ_THROUGHPUT
    :header: "Number of Blocks","j721e-idk-gw: Throughput (MB/sec)","j721s2-evm: Throughput (MB/sec)","j722s_evm-fs: Throughput (MB/sec)"

    "150","41.40","31.80","44.10"




.. csv-table:: USBDEVICE HIGHSPEED SLAVE_WRITE_THROUGHPUT
    :header: "Number of Blocks","j721e-idk-gw: Throughput (MB/sec)","j721s2-evm: Throughput (MB/sec)","j722s_evm-fs: Throughput (MB/sec)"

    "150","39.60","30.60","38.40"





 
 
 



|

CRYPTO Driver
-------------------------


OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: OpenSSL Performance
    :header: "Algorithm","Buffer Size (in bytes)","am68_sk-fs: throughput (KBytes/Sec)","am69_sk-fs: throughput (KBytes/Sec)","j721e-idk-gw: throughput (KBytes/Sec)","j721s2-evm: throughput (KBytes/Sec)","j722s_evm-fs: throughput (KBytes/Sec)","j784s4-evm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","46219.61","45987.50","49408.00","45677.57","25610.92","45419.86"
    "aes-128-cbc","16","897.43","894.22","946.55","831.49","512.58","899.09"
    "aes-128-cbc","16384","186957.82","175276.03","193413.12","183850.33","86152.53","169132.03"
    "aes-128-cbc","256","13754.54","13582.93","14763.09","14012.16","7709.18","13863.59"
    "aes-128-cbc","64","3592.32","3577.05","3830.27","3615.42","2049.07","3598.89"
    "aes-128-cbc","8192","153198.59","143092.39","161284.10","145823.06","73588.74","137611.95"
    "aes-128-ecb","1024","46746.62","41643.69","49753.77","47092.74","26260.14","46291.97"
    "aes-128-ecb","16","909.08","776.04","958.29","913.68","525.00","681.72"
    "aes-128-ecb","16384","189579.26","185969.32","198322.86","184609.45","89150.81","180218.54"
    "aes-128-ecb","256","14032.47","13853.44","14782.38","14197.85","7934.72","13852.59"
    "aes-128-ecb","64","3635.90","3594.94","3808.36","3310.76","2083.61","2982.42"
    "aes-128-ecb","8192","155454.12","152253.78","164817.58","154692.27","76327.59","153720.15"
    "aes-192-cbc","1024","45947.56","35716.44","48542.38","46088.53","24917.67","44411.56"
    "aes-192-cbc","16","897.35","872.18","966.01","909.74","512.35","882.73"
    "aes-192-cbc","16384","176297.30","161256.79","180595.37","174708.05","78599.51","175073.96"
    "aes-192-cbc","256","13902.34","10548.48","14778.20","13266.43","7586.13","10452.31"
    "aes-192-cbc","64","3623.06","2832.38","3810.82","3484.01","2051.69","3243.01"
    "aes-192-cbc","8192","146036.05","128983.04","153201.32","147865.60","67966.29","145028.44"
    "aes-192-ecb","1024","46595.75","36850.69","48642.39","43572.22","25586.35","45551.27"
    "aes-192-ecb","16","911.23","660.45","947.21","906.10","524.34","881.22"
    "aes-192-ecb","16384","183151.27","167586.47","184975.36","182648.83","80483.67","180841.13"
    "aes-192-ecb","256","14106.03","10830.59","14612.14","13891.33","7698.35","13754.03"
    "aes-192-ecb","64","3648.75","3200.21","3775.17","3606.78","2065.43","3553.07"
    "aes-192-ecb","8192","150653.61","133335.72","156778.50","150331.39","69167.79","149484.89"
    "aes-256-cbc","1024","45510.66","44430.34","47835.14","42647.21","24110.76","37212.84"
    "aes-256-cbc","16","911.73","671.08","955.90","878.69","511.72","892.56"
    "aes-256-cbc","16384","162906.11","153152.17","168181.76","164457.13","70336.51","155746.30"
    "aes-256-cbc","256","13937.75","13514.50","14649.94","13874.77","7574.95","11620.10"
    "aes-256-cbc","64","3635.24","3553.26","3808.43","3583.81","2044.14","3475.52"
    "aes-256-cbc","8192","137975.13","135533.91","144351.23","137134.08","61844.14","126771.20"
    "aes-256-ecb","1024","46123.69","44726.95","48585.05","46061.57","24802.65","45205.16"
    "aes-256-ecb","16","910.54","760.35","958.18","908.34","520.55","839.22"
    "aes-256-ecb","16384","169497.94","163916.46","173861.55","165877.08","73493.16","168438.44"
    "aes-256-ecb","256","14080.34","13823.66","14745.77","14043.48","7726.59","13910.95"
    "aes-256-ecb","64","3643.16","3577.37","3817.90","3288.47","2075.61","3586.09"
    "aes-256-ecb","8192","141986.47","139892.05","148368.04","142748.33","64550.23","138160.81"
    "des3","1024","39734.61","37462.02","40844.29","37248.68","","39184.38"
    "des3","16","914.21","884.54","941.56","909.13","","808.66"
    "des3","16384","96572.76","96114.01","97069.74","96501.76","","96228.69"
    "des3","256","13136.64","11315.11","13912.32","12889.00","","11677.61"
    "des3","64","3634.60","3574.19","3803.29","3601.05","","2891.41"
    "des3","8192","87419.56","87547.90","88754.86","87539.71","","87531.52"
    "sha1","1024","60428.29","57236.14","60178.43","59168.77","","58725.38"
    "sha1","16","1023.05","961.74","1016.55","952.77","","1003.29"
    "sha1","16384","466616.32","462132.57","476752.55","450641.92","","462214.49"
    "sha1","256","15941.46","15094.87","15998.12","15508.82","","15473.49"
    "sha1","64","4034.73","3827.73","4026.01","3779.16","","3922.18"
    "sha1","8192","322565.46","310441.30","323283.63","302290.26","","319081.13"
    "sha256","1024","59517.61","58307.58","60958.72","57433.77","32804.86","57337.51"
    "sha256","16","1019.41","982.17","1024.24","987.32","547.75","963.46"
    "sha256","16384","466168.49","462629.55","471083.69","465218.22","254339.75","452722.69"
    "sha256","256","15718.23","15341.06","16132.44","13991.34","8690.18","14971.90"
    "sha256","64","3993.83","3860.29","4064.32","3872.53","2185.47","3812.31"
    "sha256","8192","320124.25","315045.21","323149.82","314496.34","174833.66","310531.41"
    "sha512","1024","45422.93","45898.07","46159.19","45979.65","22928.73","44440.23"
    "sha512","16","979.99","958.16","988.06","867.03","537.77","955.70"
    "sha512","16384","149924.52","149520.38","150650.88","149897.22","61620.22","148914.18"
    "sha512","256","14362.03","14038.36","14230.36","14264.06","7665.92","13901.31"
    "sha512","64","3890.88","3846.21","3974.59","3827.86","2148.61","3757.89"
    "sha512","8192","129783.13","129785.86","131284.99","120733.70","55265.96","128805.55"




.. csv-table:: OpenSSL CPU Load
    :header: "Algorithm","am68_sk-fs: CPU Load","am69_sk-fs: CPU Load","j721e-idk-gw: CPU Load","j721s2-evm: CPU Load","j722s_evm-fs: CPU Load","j784s4-evm: CPU Load"

    "aes-128-cbc","32.00","34.00","34.00","33.00","34.00","34.00"
    "aes-128-ecb","34.00","33.00","35.00","33.00","35.00","33.00"
    "aes-192-cbc","34.00","33.00","34.00","33.00","33.00","34.00"
    "aes-192-ecb","34.00","34.00","35.00","33.00","34.00","34.00"
    "aes-256-cbc","32.00","33.00","34.00","33.00","32.00","33.00"
    "aes-256-ecb","33.00","32.00","34.00","33.00","33.00","33.00"
    "des3","30.00","30.00","31.00","29.00","","30.00"
    "sha1","98.00","98.00","99.00","97.00","","99.00"
    "sha256","97.00","98.00","99.00","98.00","98.00","99.00"
    "sha512","81.00","98.00","99.00","96.00","98.00","99.00"



Listed for each algorithm are the code snippets used to run each
  benchmark test.

::

    time -v openssl speed -elapsed -evp aes-128-cbc

 




IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: IPSec Software Performance
    :header: "Algorithm","j721e-idk-gw: Throughput (Mbps)","j721e-idk-gw: Packets/Sec","j721e-idk-gw: CPU Load"

    "3des","207.90","18.00","31.78"
    "aes128","738.50","65.00","57.88"
    "aes192","736.00","65.00","58.01"
    "aes256","724.60","64.00","58.31"

 
 

|

DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.




