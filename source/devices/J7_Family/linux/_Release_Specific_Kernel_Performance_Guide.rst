======================================
 Linux 09.01.00 Performance Guide
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
    :header: "Benchmarks","am68_sk-fs: perf","am69_sk-fs: perf","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j784s4-evm: perf"

    "af_unix_sock_stream_latency (microsec)","15.56","18.82","17.83","15.71","15.95","15.85"
    "af_unix_socket_stream_bandwidth (MBs)","2072.79","3520.26","1626.69","2043.75","1896.16","3458.34"
    "bw_file_rd-io-1mb (MB/s)","3013.75","3577.82","2254.79","2922.91","2818.49","3684.21"
    "bw_file_rd-o2c-1mb (MB/s)","1260.81","323.89","1168.42","1557.63","1270.88","982.16"
    "bw_mem-bcopy-16mb (MB/s)","3395.23","3180.91","2380.60","2858.67","3456.84","3226.78"
    "bw_mem-bcopy-1mb (MB/s)","4492.70","10149.37","3305.79","5123.34","4535.15","9825.33"
    "bw_mem-bcopy-2mb (MB/s)","3589.38","4738.47","2496.88","4054.74","3639.01","4982.21"
    "bw_mem-bcopy-4mb (MB/s)","3414.72","3865.48","2350.18","3734.83","3477.05","3954.13"
    "bw_mem-bcopy-8mb (MB/s)","3396.55","3337.04","2357.45","3104.38","3439.87","3414.91"
    "bw_mem-bzero-16mb (MB/s)","10491.80","10856.66","2334.06","9657.46","10533.25","10851.14"
    "bw_mem-bzero-1mb (MB/s)","8602.66 (min 4492.70, max 12712.62)","11957.50 (min 10149.37, max 13765.62)","4109.68 (min 3305.79, max 4913.56)","8869.34 (min 5123.34, max 12615.33)","8611.39 (min 4535.15, max 12687.63)","11792.99 (min 9825.33, max 13760.64)"
    "bw_mem-bzero-2mb (MB/s)","7443.35 (min 3589.38, max 11297.31)","9201.31 (min 4738.47, max 13664.15)","2706.70 (min 2496.88, max 2916.51)","8111.44 (min 4054.74, max 12168.14)","7420.70 (min 3639.01, max 11202.39)","9347.84 (min 4982.21, max 13713.46)"
    "bw_mem-bzero-4mb (MB/s)","7013.34 (min 3414.72, max 10611.96)","8083.25 (min 3865.48, max 12301.01)","2411.57 (min 2350.18, max 2472.95)","7806.54 (min 3734.83, max 11878.25)","7055.79 (min 3477.05, max 10634.53)","8115.36 (min 3954.13, max 12276.58)"
    "bw_mem-bzero-8mb (MB/s)","6967.38 (min 3396.55, max 10538.20)","7339.27 (min 3337.04, max 11341.49)","2355.89 (min 2354.33, max 2357.45)","7370.37 (min 3104.38, max 11636.36)","7010.07 (min 3439.87, max 10580.26)","7352.19 (min 3414.91, max 11289.47)"
    "bw_mem-cp-16mb (MB/s)","2112.21","2426.08","989.18","1592.36","2157.21","2403.85"
    "bw_mem-cp-1mb (MB/s)","7732.12 (min 2526.23, max 12938.01)","8698.15 (min 3663.00, max 13733.29)","3058.84 (min 1257.18, max 4860.49)","7217.42 (min 1790.33, max 12644.51)","7491.85 (min 2401.63, max 12582.06)","8711.93 (min 3688.09, max 13735.77)"
    "bw_mem-cp-2mb (MB/s)","6702.26 (min 2067.54, max 11336.98)","8191.09 (min 2708.19, max 13673.98)","1952.08 (min 1003.51, max 2900.65)","6851.59 (min 1444.30, max 12258.88)","6744.02 (min 2197.11, max 11290.93)","8247.34 (min 2778.74, max 13715.94)"
    "bw_mem-cp-4mb (MB/s)","6321.63 (min 2029.43, max 10613.83)","7599.41 (min 2841.92, max 12356.90)","1717.41 (min 978.95, max 2455.87)","6762.76 (min 1624.92, max 11900.60)","6279.20 (min 1938.92, max 10619.47)","7794.84 (min 2853.07, max 12736.60)"
    "bw_mem-cp-8mb (MB/s)","6316.27 (min 2087.14, max 10545.39)","6952.10 (min 2475.63, max 11428.57)","1637.61 (min 987.53, max 2287.68)","6574.27 (min 1541.72, max 11606.82)","6357.83 (min 2116.12, max 10599.54)","6904.54 (min 2449.48, max 11359.60)"
    "bw_mem-fcp-16mb (MB/s)","3362.05","3140.95","2399.16","2830.86","3381.59","3170.83"
    "bw_mem-fcp-1mb (MB/s)","8344.74 (min 3976.86, max 12712.62)","10022.08 (min 6278.54, max 13765.62)","4095.83 (min 3278.09, max 4913.56)","8198.88 (min 3782.42, max 12615.33)","8272.29 (min 3856.94, max 12687.63)","10249.47 (min 6738.30, max 13760.64)"
    "bw_mem-fcp-2mb (MB/s)","7391.16 (min 3485.00, max 11297.31)","8715.67 (min 3767.19, max 13664.15)","2716.12 (min 2515.72, max 2916.51)","8062.13 (min 3956.12, max 12168.14)","7366.94 (min 3531.49, max 11202.39)","8995.77 (min 4278.07, max 13713.46)"
    "bw_mem-fcp-4mb (MB/s)","7007.82 (min 3403.68, max 10611.96)","7981.67 (min 3662.33, max 12301.01)","2432.89 (min 2392.82, max 2472.95)","7884.65 (min 3891.05, max 11878.25)","7001.90 (min 3369.27, max 10634.53)","8022.60 (min 3768.61, max 12276.58)"
    "bw_mem-fcp-8mb (MB/s)","6945.78 (min 3353.36, max 10538.20)","7315.48 (min 3289.47, max 11341.49)","2383.26 (min 2354.33, max 2412.18)","7364.18 (min 3091.99, max 11636.36)","6996.13 (min 3412.00, max 10580.26)","7287.67 (min 3285.87, max 11289.47)"
    "bw_mem-frd-16mb (MB/s)","4156.38","3706.28","6312.47","4801.20","4147.76","3757.63"
    "bw_mem-frd-1mb (MB/s)","4716.20 (min 3976.86, max 5455.54)","7073.40 (min 6278.54, max 7868.25)","5002.49 (min 3278.09, max 6726.89)","4480.45 (min 3782.42, max 5178.47)","4487.02 (min 3856.94, max 5117.10)","7342.42 (min 6738.30, max 7946.54)"
    "bw_mem-frd-2mb (MB/s)","4107.50 (min 3485.00, max 4730.00)","4107.72 (min 3767.19, max 4448.25)","4461.85 (min 2515.72, max 6407.97)","4882.40 (min 3956.12, max 5808.68)","4132.14 (min 3531.49, max 4732.79)","4696.12 (min 4278.07, max 5114.16)"
    "bw_mem-frd-4mb (MB/s)","3796.45 (min 3403.68, max 4189.21)","3913.78 (min 3662.33, max 4165.22)","4342.92 (min 2392.82, max 6293.02)","4762.92 (min 3891.05, max 5634.79)","3778.88 (min 3369.27, max 4188.48)","4074.89 (min 3768.61, max 4381.16)"
    "bw_mem-frd-8mb (MB/s)","3760.02 (min 3353.36, max 4166.67)","3670.05 (min 3289.47, max 4050.63)","4354.21 (min 2412.18, max 6296.24)","4243.69 (min 3091.99, max 5395.38)","3781.41 (min 3412.00, max 4150.81)","3760.46 (min 3285.87, max 4235.04)"
    "bw_mem-fwr-16mb (MB/s)","10529.78","10827.27","2319.18","9637.10","10548.87","10788.94"
    "bw_mem-fwr-1mb (MB/s)","9196.78 (min 5455.54, max 12938.01)","10800.77 (min 7868.25, max 13733.29)","5793.69 (min 4860.49, max 6726.89)","8911.49 (min 5178.47, max 12644.51)","8849.58 (min 5117.10, max 12582.06)","10841.16 (min 7946.54, max 13735.77)"
    "bw_mem-fwr-2mb (MB/s)","8033.49 (min 4730.00, max 11336.98)","9061.12 (min 4448.25, max 13673.98)","4654.31 (min 2900.65, max 6407.97)","9033.78 (min 5808.68, max 12258.88)","8011.86 (min 4732.79, max 11290.93)","9415.05 (min 5114.16, max 13715.94)"
    "bw_mem-fwr-4mb (MB/s)","7401.52 (min 4189.21, max 10613.83)","8261.06 (min 4165.22, max 12356.90)","4374.45 (min 2455.87, max 6293.02)","8767.70 (min 5634.79, max 11900.60)","7403.98 (min 4188.48, max 10619.47)","8558.88 (min 4381.16, max 12736.60)"
    "bw_mem-fwr-8mb (MB/s)","7356.03 (min 4166.67, max 10545.39)","7739.60 (min 4050.63, max 11428.57)","4291.96 (min 2287.68, max 6296.24)","8501.10 (min 5395.38, max 11606.82)","7375.18 (min 4150.81, max 10599.54)","7797.32 (min 4235.04, max 11359.60)"
    "bw_mem-rd-16mb (MB/s)","4879.54","4424.17","6558.27","5117.54","4889.98","4507.68"
    "bw_mem-rd-1mb (MB/s)","7372.07 (min 5745.06, max 8999.08)","15998.07 (min 14764.13, max 17232.00)","13177.14 (min 11446.01, max 14908.26)","7757.05 (min 6240.25, max 9273.84)","7848.88 (min 6117.38, max 9580.38)","16288.46 (min 15269.95, max 17306.96)"
    "bw_mem-rd-2mb (MB/s)","4418.29 (min 2980.63, max 5855.94)","5099.74 (min 3926.19, max 6273.28)","4025.35 (min 973.55, max 7077.14)","3813.60 (min 1367.99, max 6259.20)","4379.04 (min 3065.13, max 5692.94)","5741.09 (min 4901.96, max 6580.22)"
    "bw_mem-rd-4mb (MB/s)","3625.22 (min 2268.22, max 4982.21)","4438.31 (min 3909.43, max 4967.18)","3712.52 (min 787.87, max 6637.17)","3791.61 (min 1314.71, max 6268.50)","3670.04 (min 2354.33, max 4985.75)","4716.87 (min 4098.36, max 5335.37)"
    "bw_mem-rd-8mb (MB/s)","3541.03 (min 2236.51, max 4845.55)","4372.35 (min 3792.67, max 4952.03)","3662.75 (min 748.71, max 6576.78)","3583.48 (min 1315.79, max 5851.16)","3571.44 (min 2252.89, max 4889.98)","4478.75 (min 3750.00, max 5207.49)"
    "bw_mem-rdwr-16mb (MB/s)","2141.90","2639.83","752.09","1919.62","2167.73","2657.37"
    "bw_mem-rdwr-1mb (MB/s)","3511.32 (min 2526.23, max 4496.40)","6608.86 (min 3663.00, max 9554.71)","2534.81 (min 1257.18, max 3812.43)","3156.33 (min 1790.33, max 4522.33)","3945.05 (min 2401.63, max 5488.47)","6594.42 (min 3688.09, max 9500.75)"
    "bw_mem-rdwr-2mb (MB/s)","2357.27 (min 2067.54, max 2647.00)","3516.05 (min 2708.19, max 4323.90)","995.58 (min 987.65, max 1003.51)","1945.89 (min 1444.30, max 2447.48)","2611.99 (min 2197.11, max 3026.86)","3557.39 (min 2778.74, max 4336.04)"
    "bw_mem-rdwr-4mb (MB/s)","2135.64 (min 2029.43, max 2241.84)","3092.09 (min 2841.92, max 3342.25)","885.48 (min 792.00, max 978.95)","2016.74 (min 1624.92, max 2408.55)","2141.97 (min 1938.92, max 2345.01)","3155.15 (min 2853.07, max 3457.22)"
    "bw_mem-rdwr-8mb (MB/s)","2140.67 (min 2087.14, max 2194.19)","2820.72 (min 2475.63, max 3165.81)","871.48 (min 755.43, max 987.53)","1936.36 (min 1541.72, max 2331.00)","2176.94 (min 2116.12, max 2237.76)","2842.43 (min 2449.48, max 3235.37)"
    "bw_mem-wr-16mb (MB/s)","2200.22","3061.03","742.15","1820.87","2225.93","3030.88"
    "bw_mem-wr-1mb (MB/s)","5120.73 (min 4496.40, max 5745.06)","13393.36 (min 9554.71, max 17232.00)","7629.22 (min 3812.43, max 11446.01)","5381.29 (min 4522.33, max 6240.25)","5802.93 (min 5488.47, max 6117.38)","13403.86 (min 9500.75, max 17306.96)"
    "bw_mem-wr-2mb (MB/s)","2813.82 (min 2647.00, max 2980.63)","4125.05 (min 3926.19, max 4323.90)","980.60 (min 973.55, max 987.65)","1907.74 (min 1367.99, max 2447.48)","3046.00 (min 3026.86, max 3065.13)","4619.00 (min 4336.04, max 4901.96)"
    "bw_mem-wr-4mb (MB/s)","2255.03 (min 2241.84, max 2268.22)","3625.84 (min 3342.25, max 3909.43)","789.94 (min 787.87, max 792.00)","1861.63 (min 1314.71, max 2408.55)","2349.67 (min 2345.01, max 2354.33)","3777.79 (min 3457.22, max 4098.36)"
    "bw_mem-wr-8mb (MB/s)","2215.35 (min 2194.19, max 2236.51)","3479.24 (min 3165.81, max 3792.67)","752.07 (min 748.71, max 755.43)","1823.40 (min 1315.79, max 2331.00)","2245.33 (min 2237.76, max 2252.89)","3492.69 (min 3235.37, max 3750.00)"
    "bw_mmap_rd-mo-1mb (MB/s)","8828.72","12916.14","8124.08","8448.12","6874.77","12917.93"
    "bw_mmap_rd-o2c-1mb (MB/s)","1159.42","311.53","1587.02","1529.57","1171.87","930.23"
    "bw_pipe (MB/s)","830.52","670.16","671.55","795.56","801.99","907.75"
    "bw_unix (MB/s)","2072.79","3520.26","1626.69","2043.75","1896.16","3458.34"
    "lat_connect (us)","35.55","34.20","35.22","34.38","35.57","34.83"
    "lat_ctx-2-128k (us)","3.17","5.39","3.30","3.25","3.29","3.12"
    "lat_ctx-2-256k (us)","2.49","4.86","2.56","2.55","2.56","2.42"
    "lat_ctx-4-128k (us)","3.28","4.01","3.36","3.22","3.30","3.82"
    "lat_ctx-4-256k (us)","2.04","2.35","2.15","2.14","2.18","3.53"
    "lat_fs-0k (num_files)","530.00","562.00","435.00","557.00","544.00","450.00"
    "lat_fs-10k (num_files)","160.00","218.00","150.00","201.00","201.00","239.00"
    "lat_fs-1k (num_files)","269.00","265.00","277.00","270.00","287.00","296.00"
    "lat_fs-4k (num_files)","301.00","309.00","283.00","297.00","251.00","309.00"
    "lat_mem_rd-stride128-sz1000k (ns)","12.01","5.65","10.48","11.15","13.40","5.71"
    "lat_mem_rd-stride128-sz125k (ns)","5.57","5.65","5.57","5.57","5.57","5.65"
    "lat_mem_rd-stride128-sz250k (ns)","5.57","5.65","5.58","5.57","5.57","5.65"
    "lat_mem_rd-stride128-sz31k (ns)","3.79","4.75","2.00","4.67","3.34","4.77"
    "lat_mem_rd-stride128-sz50 (ns)","2.00","2.00","2.00","2.00","2.00","2.00"
    "lat_mem_rd-stride128-sz500k (ns)","5.57","5.65","5.57","5.57","5.57","5.65"
    "lat_mem_rd-stride128-sz62k (ns)","5.57","5.20","5.58","5.12","5.12","5.20"
    "lat_mmap-1m (us)","34.00","27.00","27.00","33.00","27.00","27.00"
    "lat_ops-double-add (ns)","1.96","1.96","1.96","1.96","1.96","1.96"
    "lat_ops-double-div (ns)","9.01","9.01","9.01","9.01","9.01","9.01"
    "lat_ops-double-mul (ns)","2.00","2.00","2.00","2.00","2.00","2.00"
    "lat_ops-float-add (ns)","1.96","1.96","1.96","1.96","1.96","1.96"
    "lat_ops-float-div (ns)","5.50","5.51","5.51","5.50","5.50","5.50"
    "lat_ops-float-mul (ns)","2.00","2.00","2.02","2.00","2.01","2.00"
    "lat_ops-int-add (ns)","0.50","0.50","0.50","0.50","0.50","0.50"
    "lat_ops-int-bit (ns)","0.33","0.33","0.33","0.33","0.33","0.33"
    "lat_ops-int-div (ns)","4.00","4.00","4.01","4.00","4.00","4.00"
    "lat_ops-int-mod (ns)","4.67","4.67","4.67","4.67","4.67","4.67"
    "lat_ops-int-mul (ns)","1.52","1.52","1.52","1.52","1.52","1.52"
    "lat_ops-int64-add (ns)","0.50","0.50","0.50","0.50","0.50","0.50"
    "lat_ops-int64-bit (ns)","0.33","0.33","0.33","0.33","0.33","0.33"
    "lat_ops-int64-div (ns)","3.00","3.00","3.00","3.00","3.00","3.00"
    "lat_ops-int64-mod (ns)","5.68","5.67","5.67","5.67","5.67","5.67"
    "lat_ops-int64-mul (ns)","2.52","2.52","2.52","2.52","2.52","2.52"
    "lat_pagefault (us)","0.52","0.51","0.51","0.50","0.53","0.51"
    "lat_pipe (us)","11.90","12.08","11.98","11.86","11.56","12.38"
    "lat_proc-exec (us)","435.91","405.00","441.50","379.20","442.54","425.50"
    "lat_proc-fork (us)","355.31","364.00","376.43","323.88","356.21","349.27"
    "lat_proc-proccall (us)","0.00","0.00","0.00","0.00","0.00","0.00"
    "lat_select (us)","10.89","13.09","10.87","10.81","10.80","10.90"
    "lat_sem (us)","1.59","1.17","1.43","1.29","1.49","1.21"
    "lat_sig-catch (us)","3.06","3.24","3.14","3.05","3.06","3.09"
    "lat_sig-install (us)","0.50","0.50","0.50","0.50","0.50","0.50"
    "lat_sig-prot (us)","0.48","0.30","0.45","0.52","0.49","0.45"
    "lat_syscall-fstat (us)","1.13","1.21","1.14","1.12","1.15","1.17"
    "lat_syscall-null (us)","0.37","0.37","0.37","0.37","0.37","0.37"
    "lat_syscall-open (us)","110.37","2866.00","105.18","164.79","151.26","153.57"
    "lat_syscall-read (us)","0.47","0.46","0.47","0.47","0.47","0.46"
    "lat_syscall-stat (us)","1.43","1.57","1.47","1.40","1.41","1.45"
    "lat_syscall-write (us)","0.42","0.43","0.42","0.44","0.42","0.42"
    "lat_tcp (us)","0.78","0.79","0.78","0.78","0.78","0.79"
    "lat_unix (us)","15.56","18.82","17.83","15.71","15.95","15.85"
    "latency_for_0.50_mb_block_size (nanosec)","5.57","5.65","5.57","5.57","5.57","5.65"
    "latency_for_1.00_mb_block_size (nanosec)","6.01 (min 0.00, max 12.01)","2.82 (min 0.00, max 5.65)","5.24 (min 0.00, max 10.48)","5.58 (min 0.00, max 11.15)","6.70 (min 0.00, max 13.40)","2.86 (min 0.00, max 5.71)"
    "pipe_bandwidth (MBs)","830.52","670.16","671.55","795.56","801.99","907.75"
    "pipe_latency (microsec)","11.90","12.08","11.98","11.86","11.56","12.38"
    "procedure_call (microsec)","0.00","0.00","0.00","0.00","0.00","0.00"
    "select_on_200_tcp_fds (microsec)","10.89","13.09","10.87","10.81","10.80","10.90"
    "semaphore_latency (microsec)","1.59","1.17","1.43","1.29","1.49","1.21"
    "signal_handler_latency (microsec)","0.50","0.50","0.50","0.50","0.50","0.50"
    "signal_handler_overhead (microsec)","3.06","3.24","3.14","3.05","3.06","3.09"
    "tcp_ip_connection_cost_to_localhost (microsec)","35.55","34.20","35.22","34.38","35.57","34.83"
    "tcp_latency_using_localhost (microsec)","0.78","0.79","0.78","0.78","0.78","0.79"


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
    :header: "Benchmarks","am68_sk-fs: perf","am69_sk-fs: perf","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j784s4-evm: perf"

    "cpu_clock (MHz)","2000.00","2000.00","2000.00","2000.00","2000.00","2000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","5.20","4.40","5.20","4.40","4.10","4.40"
    "dhrystone_per_second (DhrystoneP)","18181818.00","15384615.00","18181818.00","15384615.00","14285714.00","15384615.00"


Table:  **Dhrystone Benchmark**



Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Whetstone is a benchmark primarily measuring floating-point arithmetic performance.

Execute the benchmark with the following:

::

    runWhetstone

.. csv-table::
    :header: "Benchmarks","am68_sk-fs: perf","am69_sk-fs: perf","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j784s4-evm: perf"

    "whetstone (MIPS)","10000.00","10000.00","10000.00","10000.00","10000.00","10000.00"


Table:  **Whetstone Benchmark**



Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am68_sk-fs: perf","am69_sk-fs: perf","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j784s4-evm: perf"

    "linpack (Kflops)","2592175.00","2486122.00","2391734.00","2459408.00","2372725.00","2601996.00"


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

    "assignment (Iterations)","30.86","30.81","30.80","30.73"
    "fourier (Iterations)","53004.00","64902.00","65145.00","50203.00"
    "fp_emulation (Iterations)","214.60","214.63","214.64","214.62"
    "huffman (Iterations)","2381.20","2376.80","2383.80","2378.00"
    "idea (Iterations)","7996.80","7997.00","7996.80","7996.70"
    "lu_decomposition (Iterations)","1375.00","1364.40","1360.50","1360.80"
    "neural_net (Iterations)","29.49","29.78","28.96","29.91"
    "numeric_sort (Iterations)","855.31","848.33","854.56","853.11"
    "string_sort (Iterations)","413.85","425.25","417.58","417.49"


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
    :header: "Benchmarks","am68_sk-fs: perf","am69_sk-fs: perf","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j784s4-evm: perf"

    "add (MB/s)","6364.50","6216.20","5459.10","5380.80","6340.50","6150.90"
    "copy (MB/s)","6930.30","7145.70","4779.80","5631.00","7001.30","7047.50"
    "scale (MB/s)","7063.10","7159.50","4836.90","5504.10","7133.30","7073.70"
    "triad (MB/s)","6372.60","6213.70","5460.50","5361.60","6350.40","6150.40"


Table:  **Stream**



CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.


.. csv-table::
    :header: "Benchmarks","am68_sk-fs: perf","am69_sk-fs: perf","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j784s4-evm: perf"

    "cjpeg-rose7-preset (workloads/)","82.64","82.64","82.64","83.33","81.97","82.64"
    "core (workloads/)","0.77","0.78","0.78","0.78","0.78","0.78"
    "coremark-pro ()","2504.00","2518.83","2424.25","2465.22","2475.03","2499.36"
    "linear_alg-mid-100x100-sp (workloads/)","80.52","79.87","79.62","80.52","80.91","81.57"
    "loops-all-mid-10k-sp (workloads/)","2.47","2.47","2.45","2.46","2.49","2.47"
    "nnet_test (workloads/)","3.64","3.84","3.58","3.61","3.65","3.59"
    "parser-125k (workloads/)","11.11","10.87","11.11","10.99","11.11","10.87"
    "radix2-big-64k (workloads/)","283.29","274.35","216.64","250.56","253.94","267.95"
    "sha-test (workloads/)","158.73","158.73","158.73","156.25","156.25","158.73"
    "zip-test (workloads/)","47.62","50.00","47.62","47.62","47.62","50.00"


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
    :header: "Benchmarks","am68_sk-fs: perf","am69_sk-fs: perf","j7200-evm: perf","j721e-idk-gw: perf","j721s2-evm: perf","j784s4-evm: perf"

    "4m-check (workloads/)","901.55","1035.20","935.28","931.79","888.73","1050.42"
    "4m-check-reassembly (workloads/)","153.37","202.84","120.92","147.28","148.81","200.40"
    "4m-check-reassembly-tcp (workloads/)","99.21","115.74","93.28","101.22","94.34","116.28"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","41.52","36.25","40.82","44.05","41.61","38.61"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","2.67","4.67","2.70","2.72","2.67","4.89"
    "4m-cmykw2 (workloads/)","314.96","604.23","313.48","317.46","313.48","598.80"
    "4m-cmykw2-rotatew2 (workloads/)","58.54","48.00","58.88","62.24","59.23","53.86"
    "4m-reassembly (workloads/)","125.95","152.44","108.70","129.87","126.58","150.15"
    "4m-rotatew2 (workloads/)","71.53","52.85","70.87","74.02","70.87","56.53"
    "4m-tcp-mixed (workloads/)","250.00","253.97","280.70","280.70","266.67","271.19"
    "4m-x264w2 (workloads/)","2.75","4.78","2.76","2.76","2.72","5.10"
    "idct-4m (workloads/)","35.00","35.15","34.94","35.09","34.98","35.11"
    "idct-4mw1 (workloads/)","35.01","35.11","34.94","35.08","34.98","35.14"
    "ippktcheck-4m (workloads/)","893.82","1035.63","926.27","928.68","851.79","1042.10"
    "ippktcheck-4mw1 (workloads/)","913.74","1025.43","951.29","916.09","884.02","1028.38"
    "ipres-4m (workloads/)","168.73","208.04","158.06","179.86","163.40","202.98"
    "ipres-4mw1 (workloads/)","169.68","202.98","155.44","181.60","165.20","201.61"
    "md5-4m (workloads/)","45.50","47.57","45.87","48.61","44.68","47.87"
    "md5-4mw1 (workloads/)","46.27","47.44","45.68","48.85","46.17","47.30"
    "rgbcmyk-4m (workloads/)","163.13","164.20","163.13","163.93","163.13","164.07"
    "rgbcmyk-4mw1 (workloads/)","163.13","163.80","163.13","163.80","161.81","163.93"
    "rotate-4ms1 (workloads/)","52.25","55.07","52.36","54.64","51.76","54.70"
    "rotate-4ms1w1 (workloads/)","52.14","55.07","52.47","54.95","51.49","55.01"
    "rotate-4ms64 (workloads/)","52.85","55.56","52.91","55.37","52.19","55.49"
    "rotate-4ms64w1 (workloads/)","52.80","55.62","53.08","55.25","52.74","55.37"
    "x264-4mq (workloads/)","1.42","1.41","1.42","1.43","1.42","1.43"
    "x264-4mqw1 (workloads/)","1.41","1.43","1.42","1.44","1.41","1.43"


Table:  **Multibench**


 
 


Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am68_sk-fs: boot time (sec)","am69_sk-fs: boot time (sec)","j7200-evm: boot time (sec)","j721e-idk-gw: boot time (sec)","j721s2-evm: boot time (sec)","j784s4-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","13.81 (min 13.69, max 13.89)","14.55 (min 14.47, max 14.68)","13.55 (min 13.28, max 14.12)","17.38 (min 17.05, max 18.16)","18.58 (min 18.49, max 18.79)","16.22 (min 15.57, max 18.18)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","4.58 (min 4.57, max 4.61)","5.22 (min 5.20, max 5.24)","4.31 (min 4.28, max 4.33)","5.03 (min 5.01, max 5.07)","5.33 (min 5.32, max 5.33)","6.41 (min 6.29, max 6.45)"

Table:  **Boot time MMC/SD**


 
 


ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64


.. csv-table::
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "11025","352793.00","0.16"
    "16000","511992.00","0.28"
    "22050","705576.00","0.23"
    "24000","705583.00","0.27"
    "32000","1023980.00","0.36"
    "44100","1411175.00","0.45"
    "48000","1535974.00","0.27"
    "88200","2822351.00","0.83"
    "96000","3071946.00","1.12"

Table:  **Audio Capture**


|


.. csv-table::
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "11025","352935.00","0.14"
    "16000","512198.00","0.19"
    "22050","705872.00","0.23"
    "24000","705872.00","0.24"
    "32000","1024396.00","0.32"
    "44100","1411745.00","0.42"
    "48000","1536594.00","0.45"
    "88200","2823489.00","0.79"
    "96000","2964662.00","1.25"

Table:  **Audio Playback**
 

|

 



 


Graphics SGX/RGX Driver
-------------------------
 




Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am68_sk-fs: Score","am69_sk-fs: Score","j721e-idk-gw: Score","j721s2-evm: Score","j784s4-evm: Score"

    "Glmark2-DRM","56.00","56.00","28.00","28.00"
    "Glmark2-Wayland","1332.00","1401.00","1180.00","1286.00","1333.00"


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
    :header: "Command Used","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j784s4-evm: THROUGHPUT (Mbits/sec)","j784s4-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1834.33","73.50","1864.35","75.70","1855.53","18.66"

Table: **CPSW TCP Bidirectional Throughput**

|



.. rubric::  TCP Bidirectional Throughput Interrupt Pacing
   :name: CPSW2g-tcp-bidirectional-throughput-interrupt-pacing

.. csv-table::
    :header: "Command Used","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1859.60","34.09","1873.43","38.54"

Table: **CPSW TCP Bidirectional Throughput Interrupt Pacing**

|



.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: Packets Per Second (kPPS)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: Packets Per Second (kPPS)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","32.39","225.00","88.25","18.00","3.63","25.00","18.05"
    "128","82.00","146.16","223.00","88.80","82.00","138.80","212.00","90.72"
    "256","210.00","368.14","219.00","87.76","210.00","27.55","16.00","12.52"
    "1024","978.00","675.97","86.00","35.83","978.00","936.05","120.00","55.72"
    "1518","1472.00","592.23","50.00","23.48","1472.00","955.98","81.00","42.40"

Table: **CPSW UDP Egress Throughput**
|



.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: Packets Per Second (kPPS)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: Packets Per Second (kPPS)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","7.26","50.00","18.15","18.00","1.28","9.00","6.56"
    "128","82.00","8.20","13.00","5.59","82.00","20.53","31.00","21.86"
    "256","210.00","18.31","11.00","4.62","210.00","76.44","46.00","29.70"
    "1024","978.00","107.19","14.00","8.80","978.00","180.73","23.00","15.57"
    "1518","1472.00","216.68","18.00","13.52","1472.00","956.98","81.00","64.71"


Table: **CPSW UDP Ingress Throughput (0% loss)**

|



.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721e-idk-gw: THROUGHPUT (Mbits/sec)","j721e-idk-gw: Packets Per Second (kPPS)","j721e-idk-gw: CPU Load % (LOCAL_CPU_UTIL)","j721e-idk-gw: Packet Loss %","j721s2-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","j721s2-evm: THROUGHPUT (Mbits/sec)","j721s2-evm: Packets Per Second (kPPS)","j721s2-evm: CPU Load % (LOCAL_CPU_UTIL)","j721s2-evm: Packet Loss %"

    "64","18.00","59.08","410.00","88.04","1.78","18.00","18.61","129.00","71.03","0.04"
    "128","82.00","261.28","398.00","90.62","1.68","82.00","86.81","132.00","72.16","4.34"
    "256","210.00","669.82","399.00","92.76","1.82","210.00","234.27","139.00","80.60","0.06"
    "1024","978.00","928.84","119.00","83.35","0.03","978.00","930.94","119.00","84.56","0.61"
    "1518","1472.00","949.65","81.00","60.31","0.02","1472.00","956.98","81.00","64.71","0.00"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|
 
 

 

 
 


PCIe Driver
-------------------------

PCIe-ETH
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "TCP Window Size(Kbytes)","j7200-evm: Bandwidth (Mbits/sec)","j721e-idk-gw: Bandwidth (Mbits/sec)"

    "8","225.60","268.00"
    "16","225.60","243.20"
    "32","357.60","367.20"
    "64","561.60","595.20"
    "128","737.60","751.20"
    "256","808.00","808.00"

Table: **PCI Ethernet**


 


PCIe-NVMe-SSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^
 

 


J721E-IDK-GW
"""""""""""""""""""""""""""




.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","720.00","13.11","1521.00","6.09"
    "4m","721.00","11.86","1523.00","5.01"
    "4k","187.00","48.64","166.00","36.34"
    "256k","740.00","12.56","1520.00","11.87"

 

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY
 


J7200-EVM
"""""""""""""""""""""""""""




.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","722.00","14.86","1524.00","6.79"
    "4m","718.00","13.94","1524.00","5.74"
    "4k","184.00","48.57","166.00","36.55"
    "256k","742.00","14.18","1521.00","11.99"

 

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY
 


J721S2-EVM
"""""""""""""""""""""""""""




.. csv-table::
    :header: "Buffer size (bytes)","j721s2-evm: Write EXT4 Throughput (Mbytes/sec)","j721s2-evm: Write EXT4 CPU Load (%)","j721s2-evm: Read EXT4 Throughput (Mbytes/sec)","j721s2-evm: Read EXT4 CPU Load (%)"

    "1m","744.00","17.41","781.00","5.54"
    "4m","744.00","15.43","782.00","5.31"
    "4k","184.00","51.52","284.00","51.48"
    "256k","744.00","16.66","780.00","7.99"

 

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

    "50","38.17"

 
 


J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^




RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","j7200-evm: Raw Read Throughput (Mbytes/sec)"

    "50","208.33"

 
 

 


J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^




RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","j784s4-evm: Raw Read Throughput (Mbytes/sec)"

    "50","263.16"

 
 

 

 
 

 


UBoot QSPI/OSPI Driver
-------------------------




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","1539.85","37577.98"
    "800000","1541.59","39009.52"
    "1000000","1542.89","39766.99"
    "2000000","1542.75","40206.13"





J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","345.83","204800.00"
    "800000","349.46","240941.18"
    "1000000","348.70","277694.92"
    "2000000","343.68","300623.85"




J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "400000","377.86","204800.00"
    "800000","379.70","248242.42"
    "1000000","381.30","277694.92"
    "2000000","375.68","300623.85"



















 
 

 

 


UBoot UFS Driver
-------------------------
|


J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","93090.91","341333.33"
    "800000","97523.81","481882.35"
    "1000000","91530.73","606814.81"

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

    "1m","56.20","1.52","314.00","1.92"
    "4m","56.40","1.27","314.00","1.31"
    "4k","54.50","25.02","55.90","23.44"
    "256k","56.30","1.67","314.00","3.42"

|



J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","59.50","1.25","175.00","1.02"
    "4m","59.10","1.10","175.00","0.66"
    "4k","49.80","23.01","56.60","23.65"
    "256k","58.90","1.70","174.00","1.93"

|



J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721s2-evm: Write EXT4 Throughput (Mbytes/sec)","j721s2-evm: Write EXT4 CPU Load (%)","j721s2-evm: Read EXT4 Throughput (Mbytes/sec)","j721s2-evm: Read EXT4 CPU Load (%)"

    "1m","45.20","3.56","301.00","3.76"
    "4m","45.30","3.35","278.00","3.54"
    "4k","5.27","5.12","36.20","19.00"
    "256k","36.40","3.18","284.00","5.53"

|



J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j784s4-evm: Write EXT4 Throughput (Mbytes/sec)","j784s4-evm: Write EXT4 CPU Load (%)","j784s4-evm: Read EXT4 Throughput (Mbytes/sec)","j784s4-evm: Read EXT4 CPU Load (%)"

    "1m","90.80","0.45","173.00","0.30"
    "4m","97.50","0.50","150.00","0.20"
    "4k","63.50","8.85","93.20","10.70"
    "256k","90.80","0.59","172.00","0.55"

|


 

 

 

 











 
 


UBoot EMMC Driver
-------------------------
|


J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "2000000","56109.59","309132.08"
    "4000000","56496.55","321254.90"

|



J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "2000000","59686.70","173375.66"
    "4000000","60513.39","176646.90"

|



J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "2000000","60014.65","303407.41"
    "4000000","60346.22","303407.41"

|



J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j784s4-evm: Write Throughput (Kbytes/sec)","j784s4-evm: Read Throughput (Kbytes/sec)"

    "2000000","98402.40","159067.96"
    "4000000","97090.37","186181.82"

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

    "1m","19.40","0.77","86.30","0.68"
    "4m","19.90","0.66","86.40","0.53"
    "4k","5.42","3.35","16.70","7.25"
    "256k","19.40","0.88","84.30","1.19"

|



J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721s2-evm: Write EXT4 Throughput (Mbytes/sec)","j721s2-evm: Write EXT4 CPU Load (%)","j721s2-evm: Read EXT4 Throughput (Mbytes/sec)","j721s2-evm: Read EXT4 CPU Load (%)"

    "1m","20.40","2.83","86.20","2.42"
    "4m","20.70","2.77","86.40","2.82"
    "4k","5.64","5.67","16.60","9.83"
    "256k","20.00","2.48","83.80","3.17"

|



J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j784s4-evm: Write EXT4 Throughput (Mbytes/sec)","j784s4-evm: Write EXT4 CPU Load (%)","j784s4-evm: Read EXT4 Throughput (Mbytes/sec)","j784s4-evm: Read EXT4 CPU Load (%)"

    "1m","18.50","0.15","86.90","0.21"
    "4m","19.00","0.18","86.90","0.18"
    "4k","4.65","0.83","16.50","2.18"
    "256k","18.10","0.17","84.80","0.38"

|




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","18.80","0.70","43.50","0.48"
    "4m","19.40","0.59","43.50","0.45"
    "4k","4.75","2.76","13.70","5.93"
    "256k","18.50","0.70","42.80","0.71"

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

    "400000","27125.83","35617.39"
    "800000","28743.86","40554.46"
    "1000000","36167.77","43574.47"




J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","19230.05","71859.65"
    "800000","21903.74","81108.91"
    "1000000","14615.52","85780.10"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card




J721S2-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721s2-evm: Write Throughput (Kbytes/sec)","j721s2-evm: Read Throughput (Kbytes/sec)"

    "400000","34133.33","60235.29"
    "800000","21671.96","73142.86"
    "1000000","20924.65","82331.66"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card




J784S4-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j784s4-evm: Write Throughput (Kbytes/sec)","j784s4-evm: Read Throughput (Kbytes/sec)"

    "400000","24380.95","56888.89"
    "800000","17886.46","70620.69"
    "1000000","18347.14","80313.73"


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

    "1m","402.00","8.33","426.00","2.42"
    "4m","405.00","7.11","425.00","2.34"
    "4k","30.90","24.50","61.70","28.20"
    "256k","351.00","12.18","404.00","4.72"

|








 

|
 


USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^










.. csv-table::
    :header: "Number of Blocks","j721e-idk-gw: Throughput (MB/sec)","j721s2-evm: Throughput (MB/sec)"

    "150","42.40","32.80"

Table: **USBDEVICE HIGHSPEED SLAVE READ THROUGHPUT**

|
|



.. csv-table::
    :header: "Number of Blocks","j721e-idk-gw: Throughput (MB/sec)","j721s2-evm: Throughput (MB/sec)"

    "150","42.60","29.90"

Table: **USBDEVICE HIGHSPEED SLAVE WRITE THROUGHPUT**

|
|




 
 
 


CRYPTO Driver
-------------------------


OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am68_sk-fs: throughput (KBytes/Sec)","am69_sk-fs: throughput (KBytes/Sec)","j721e-idk-gw: throughput (KBytes/Sec)","j721s2-evm: throughput (KBytes/Sec)","j784s4-evm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","46429.53","45751.30","49285.46","46068.05","45405.18"
    "aes-128-cbc","16","899.54","896.65","965.25","873.54","688.66"
    "aes-128-cbc","16384","186493.61","172474.37","194794.84","183850.33","183298.73"
    "aes-128-cbc","256","13901.14","13697.19","14749.70","13769.05","13555.80"
    "aes-128-cbc","64","3633.73","3591.83","3860.18","3516.78","3462.95"
    "aes-128-cbc","8192","153777.49","147262.12","161376.94","152171.86","150792.87"
    "aes-128-ecb","1024","46818.65","44624.21","49023.32","46254.42","45046.44"
    "aes-128-ecb","16","909.09","681.99","951.10","897.44","691.49"
    "aes-128-ecb","16384","188459.69","187711.49","196504.23","187411.11","172862.12"
    "aes-128-ecb","256","14010.37","10779.90","14685.01","13238.87","13818.28"
    "aes-128-ecb","64","3613.55","2715.75","3786.73","3571.09","2784.11"
    "aes-128-ecb","8192","154271.74","154959.87","165019.65","155901.95","135113.39"
    "aes-192-cbc","1024","45590.87","45221.21","48857.77","45721.60","43852.12"
    "aes-192-cbc","16","908.77","893.10","961.37","900.54","843.21"
    "aes-192-cbc","16384","175876.78","169558.02","182856.36","176062.46","174729.90"
    "aes-192-cbc","256","13746.01","13827.50","14706.94","13150.55","13602.13"
    "aes-192-cbc","64","3624.64","3574.81","3836.20","3602.20","3517.42"
    "aes-192-cbc","8192","146046.98","145697.45","153318.74","148149.59","144788.14"
    "aes-192-ecb","1024","46128.81","43304.62","48797.70","45928.45","45101.74"
    "aes-192-ecb","16","909.42","705.83","952.48","869.00","669.34"
    "aes-192-ecb","16384","182621.53","181600.26","186772.14","184232.62","180240.38"
    "aes-192-ecb","256","13871.62","12962.39","14603.09","13866.41","11489.54"
    "aes-192-ecb","64","3624.51","3164.12","3799.83","3612.59","2712.49"
    "aes-192-ecb","8192","150522.54","150000.98","156499.97","149656.92","148531.88"
    "aes-256-cbc","1024","45124.95","36672.17","48109.23","45196.97","43773.27"
    "aes-256-cbc","16","906.81","665.95","958.40","868.80","819.19"
    "aes-256-cbc","16384","164719.27","163119.10","168564.05","164620.97","163856.38"
    "aes-256-cbc","256","13724.76","10673.07","14615.81","13721.26","13660.50"
    "aes-256-cbc","64","3626.05","2970.82","3816.23","3614.87","3540.99"
    "aes-256-cbc","8192","139332.27","138343.77","144236.54","137336.15","138859.86"
    "aes-256-ecb","1024","45514.75","45401.43","48356.35","45915.48","44286.98"
    "aes-256-ecb","16","907.07","668.95","950.36","907.41","779.80"
    "aes-256-ecb","16384","167832.23","170366.29","173850.62","169590.78","169749.16"
    "aes-256-ecb","256","13864.96","13832.87","14673.07","13498.88","13754.88"
    "aes-256-ecb","64","3630.02","3580.22","3791.19","3584.51","3547.41"
    "aes-256-ecb","8192","142980.44","142453.42","148744.87","143480.15","142060.20"
    "des3","1024","39280.64","39346.18","41344.68","38780.93","38940.67"
    "des3","16","906.81","856.34","964.57","886.84","823.60"
    "des3","16384","95901.01","96485.38","97086.12","95917.40","96266.92"
    "des3","256","13052.33","13075.29","13924.35","13061.21","12959.74"
    "des3","64","3618.90","3584.28","3846.66","3593.13","3550.76"
    "des3","8192","87111.00","87569.75","88896.85","87192.92","87545.17"
    "sha1","1024","58287.79","56244.22","59582.81","59465.39","58433.54"
    "sha1","16","971.70","941.21","994.48","1005.63","979.65"
    "sha1","16384","466239.49","460155.56","460565.16","461651.97","466337.79"
    "sha1","256","15351.38","14636.97","15500.03","15607.98","15352.15"
    "sha1","64","3890.01","3716.97","3922.92","3873.47","3886.74"
    "sha1","8192","310583.30","308401.49","316347.73","319629.99","318354.77"
    "sha256","1024","58359.13","56272.21","57865.22","57578.50","57274.71"
    "sha256","16","982.96","945.89","967.27","990.46","960.04"
    "sha256","16384","465906.35","448664.92","459806.04","456873.30","455010.99"
    "sha256","256","15389.18","14776.75","15104.26","15438.08","15057.83"
    "sha256","64","3863.55","3746.39","3846.72","3906.03","3792.98"
    "sha256","8192","314160.47","302336.68","311252.31","315692.37","310941.01"
    "sha512","1024","46239.06","45265.58","47265.11","46406.31","45240.32"
    "sha512","16","987.65","953.66","1006.12","991.33","948.78"
    "sha512","16384","149990.06","149946.37","151273.47","149908.14","150017.37"
    "sha512","256","14336.60","14068.39","14751.57","14560.77","13920.60"
    "sha512","64","3937.83","3831.42","4029.18","3834.90","3780.39"
    "sha512","8192","130927.27","130034.35","131989.50","130588.67","129982.46"


|
|



.. csv-table::
    :header: "Algorithm","am68_sk-fs: CPU Load","am69_sk-fs: CPU Load","j721e-idk-gw: CPU Load","j721s2-evm: CPU Load","j784s4-evm: CPU Load"

    "aes-128-cbc","34.00","34.00","34.00","34.00","33.00"
    "aes-128-ecb","34.00","33.00","35.00","34.00","34.00"
    "aes-192-cbc","33.00","33.00","34.00","33.00","33.00"
    "aes-192-ecb","34.00","33.00","35.00","34.00","33.00"
    "aes-256-cbc","33.00","32.00","34.00","33.00","33.00"
    "aes-256-ecb","33.00","33.00","34.00","33.00","33.00"
    "des3","30.00","29.00","30.00","30.00","30.00"
    "sha1","98.00","98.00","99.00","99.00","99.00"
    "sha256","98.00","98.00","99.00","99.00","99.00"
    "sha512","98.00","98.00","99.00","99.00","99.00"

 

Listed for each algorithm are the code snippets used to run each
  benchmark test.

::
    time -v openssl speed -elapsed -evp aes-128-cbc

 




IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","j721e-idk-gw: Throughput (Mbps)","j721e-idk-gw: Packets/Sec","j721e-idk-gw: CPU Load"

    "3des","215.30","19.00","33.54"
    "aes128","650.30","58.00","57.70"
    "aes192","639.60","57.00","57.70"
    "aes256","626.50","55.00","57.58"

 
 

DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.




