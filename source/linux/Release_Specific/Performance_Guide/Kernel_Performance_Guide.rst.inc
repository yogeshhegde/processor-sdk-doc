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

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am654x-evm: perf","k2g-evm: perf","omapl138-lcdk: perf"

    "bw_mmap_rd-mo-1mb","272.15","1406.96","1106.40","132.71"
    "lat_sig-catch","13.36","6.42","4.98","37.72"
    "lat_ops-int-bit","0.67","0.84","0.67","2.54"
    "bw_mem-bzero-8mb","608.85 (min 219.57, max 998.13)","2527.02 (min 913.97, max 4140.07)","2347.64 (min 1229.07, max 3466.20)","149.60 (min 105.20, max 193.99)"
    "latency_for_0.50_mb_block_size","373.79","10.51","37.88","231.60"
    "lat_ops-double-mul","11.03","5.01","5.02","99.52"
    "lat_ops-int64-bit","1.03","0.84","1.02","2.51"
    "lat_proc-exec","1372.25","1248.60","887.67","7349.00"
    "lat_fs-10k","77.00","87.00","90.00","10.00"
    "bw_mem-fwr-16mb","995.27","4145.61","3325.71","194.71"
    "bw_mem-bzero-1mb","589.86 (min 195.31, max 984.41)","2656.01 (min 1055.04, max 4256.97)","2844.15 (min 1332.57, max 4355.72)","142.47 (min 94.78, max 190.15)"
    "bw_mem-frd-1mb","281.89 (min 268.49, max 295.29)","1198.08 (min 1004.86, max 1391.30)","725.10 (min 609.29, max 840.90)","63.43 (min 55.65, max 71.21)"
    "bw_mem-bcopy-1mb","195.31","1055.04","1332.57","94.78"
    "bw_mem-rdwr-8mb","202.89 (min 202.86, max 202.92)","706.81 (min 471.00, max 942.62)","585.15 (min 566.21, max 604.09)","112.23 (min 107.52, max 116.93)"
    "lat_syscall-write","0.69","0.66","0.52","2.71"
    "select_on_200_tcp_fds","42.56","53.88","46.75","176.57"
    "bw_mem-rd-8mb","617.93 (min 251.96, max 983.89)","1067.62 (min 976.32, max 1158.92)","1554.54 (min 692.88, max 2416.19)","442.47 (min 143.92, max 741.02)"
    "lat_ops-int-add","1.00","1.25","1.00","1.65"
    "bw_mem-rd-1mb","627.31 (min 270.53, max 984.09)","1314.22 (min 1193.72, max 1434.72)","1763.27 (min 860.88, max 2665.65)","440.39 (min 142.76, max 738.01)"
    "semaphore_latency","4.94","2.37","8.30","75.03"
    "lat_syscall-read","1.02","0.92","0.62","4.13"
    "bw_mem-fwr-2mb","618.44 (min 255.04, max 981.84)","2783.25 (min 1276.32, max 4290.17)","2389.02 (min 741.70, max 4036.33)","162.89 (min 133.45, max 192.33)"
    "bw_mem-rdwr-4mb","200.35 (min 197.60, max 203.09)","716.33 (min 468.33, max 964.32)","572.67 (min 570.13, max 575.21)","111.38 (min 104.80, max 117.95)"
    "bw_mem-fcp-8mb","648.19 (min 298.24, max 998.13)","2551.79 (min 963.51, max 4140.07)","2039.22 (min 612.23, max 3466.20)","138.91 (min 83.83, max 193.99)"
    "bw_mem-cp-2mb","587.48 (min 193.12, max 981.84)","2382.53 (min 474.89, max 4290.17)","2319.37 (min 602.41, max 4036.33)","148.88 (min 105.43, max 192.33)"
    "bw_mem-fcp-1mb","639.85 (min 295.29, max 984.41)","2630.92 (min 1004.86, max 4256.97)","2482.51 (min 609.29, max 4355.72)","130.68 (min 71.21, max 190.15)"
    "lat_syscall-null","0.56","0.46","0.46","1.37"
    "bw_mem-wr-8mb","593.38 (min 202.86, max 983.89)","959.47 (min 942.62, max 976.32)","629.55 (min 566.21, max 692.88)","428.98 (min 116.93, max 741.02)"
    "bw_mem-bzero-16mb","996.39","4162.33","3363.11","194.20"
    "lat_ctx-2-256k","573.15","30.17","108.24","163.83"
    "bw_mem-rd-4mb","617.99 (min 251.73, max 984.25)","1088.86 (min 998.13, max 1179.59)","1546.93 (min 696.50, max 2397.36)","437.69 (min 143.84, max 731.53)"
    "signal_handler_latency","1.38","0.78","0.99","3.98"
    "pipe_bandwidth","261.42","874.10","382.59","29.27"
    "latency_for_1.00_mb_block_size","181.56 (min 0.00, max 363.13)","22.21 (min 0.00, max 44.43)","62.82 (min 0.00, max 125.63)","57.76 (min 0.00, max 231.02)"
    "lat_ops-int64-div","208.51","11.90","188.45","854.55"
    "bw_file_rd-io-1mb","191.42","937.03","576.29","44.24"
    "procedure_call","0.02","0.01","0.01","0.25"
    "bw_mem-frd-4mb","263.93 (min 233.17, max 294.68)","1080.76 (min 963.74, max 1197.78)","660.78 (min 592.42, max 729.13)","102.77 (min 71.01, max 134.52)"
    "lat_pipe","33.50","24.75","36.90","471.58"
    "lat_syscall-stat","7.60","6.74","7.99","78.99"
    "bw_mem-bzero-2mb","592.68 (min 200.46, max 984.90)","2586.29 (min 932.84, max 4239.74)","2599.31 (min 1237.43, max 3961.18)","142.70 (min 92.69, max 192.70)"
    "bw_mem-bcopy-4mb","211.38","917.33","1226.62","91.19"
    "bw_mem-fwr-8mb","621.81 (min 249.33, max 994.28)","2668.15 (min 1180.46, max 4155.84)","2067.53 (min 726.94, max 3408.12)","164.51 (min 134.58, max 194.43)"
    "lat_fs-0k","229.00","269.00","202.00","22.00"
    "bw_mem-cp-1mb","592.34 (min 200.26, max 984.41)","2454.09 (min 529.19, max 4378.98)","2741.32 (min 603.68, max 4878.96)","146.85 (min 103.59, max 190.11)"
    "lat_mem_rd-stride128-sz62k","9.14","8.02","20.06","218.69"
    "bw_mem-fcp-4mb","639.35 (min 294.68, max 984.01)","2558.00 (min 963.74, max 4152.25)","2125.03 (min 592.42, max 3657.64)","132.08 (min 71.01, max 193.15)"
    "lat_syscall-open","270.80","199.32","204.92","1558.00"
    "tcp_ip_connection_cost_to_localhost","","","81.84",""
    "lat_tcp","1.07","0.77","0.78","2.66"
    "lat_ctx-4-128k","470.67","22.99","72.40","177.17"
    "lat_sem","4.94","2.37","8.30","75.03"
    "lat_ops-int-mul","6.08","3.81","3.14","6.59"
    "bw_pipe","261.42","874.10","382.59","29.27"
    "bw_mmap_rd-o2c-1mb","179.86","769.08","434.72","85.46"
    "lat_connect","72.48","59.06","81.84","1000.71"
    "lat_mem_rd-stride128-sz50","3.02","3.76","4.01","5.05"
    "bw_mem-rdwr-1mb","203.37 (min 200.26, max 206.48)","817.08 (min 529.19, max 1104.97)","643.08 (min 603.68, max 682.48)","110.19 (min 103.59, max 116.78)"
    "bw_mem-cp-16mb","156.87","470.48","601.62","7.00"
    "lat_select","42.56","53.88","46.75","176.57"
    "bw_mem-rdwr-16mb","202.99","940.57","530.64","117.77"
    "af_unix_sock_stream_latency","42.07","49.29","45.54","709.57"
    "lat_ctx-4-256k","690.75","144.40","74.74","226.00"
    "lat_syscall-fstat","3.17","2.94","3.55","24.25"
    "bw_mem-fcp-16mb","274.58","962.06","609.76","25.90"
    "bw_unix","167.25","1061.84","696.21","31.54"
    "lat_ops-float-add","2.28","0.91","1.11","20.97"
    "bw_mem-cp-4mb","597.43 (min 197.60, max 997.26)","2302.42 (min 468.33, max 4136.50)","2081.97 (min 575.21, max 3588.73)","149.27 (min 104.80, max 193.74)"
    "bw_mem-fwr-4mb","615.22 (min 233.17, max 997.26)","2667.14 (min 1197.78, max 4136.50)","2158.93 (min 729.13, max 3588.73)","164.13 (min 134.52, max 193.74)"
    "bw_mem-frd-8mb","273.79 (min 249.33, max 298.24)","1071.99 (min 963.51, max 1180.46)","669.59 (min 612.23, max 726.94)","109.21 (min 83.83, max 134.58)"
    "pipe_latency","33.50","24.75","36.90","471.58"
    "lat_sig-install","1.38","0.78","0.99","3.98"
    "lat_unix","42.07","49.29","45.54","709.57"
    "lat_proc-proccall","0.02","0.01","0.01","0.25"
    "bw_mem-bcopy-8mb","219.57","913.97","1229.07","105.20"
    "lat_mem_rd-stride128-sz31k","3.01","3.78","16.07","175.14"
    "tcp_latency_using_localhost","1.07","0.77","0.78","2.66"
    "lat_mem_rd-stride128-sz1000k","363.13","44.43","125.63","231.02"
    "bw_mem-rd-16mb","252.01","1152.07","2421.67","143.82"
    "bw_mem-rdwr-2mb","198.14 (min 193.12, max 203.15)","781.12 (min 474.89, max 1087.35)","585.74 (min 569.07, max 602.41)","75.54 (min 45.64, max 105.43)"
    "lat_pagefault","1.73","2.89","1.68","7.66"
    "bw_mem-wr-2mb","593.54 (min 203.15, max 983.93)","1109.29 (min 1087.35, max 1131.22)","632.67 (min 569.07, max 696.26)","390.92 (min 45.64, max 736.20)"
    "bw_file_rd-o2c-1mb","157.18","622.47","441.24","40.71"
    "af_unix_socket_stream_bandwidth","167.25","1061.84","696.21","31.54"
    "lat_ops-float-mul","10.03","5.01","5.12","66.02"
    "lat_fs-1k","122.00","88.00","135.00","14.00"
    "bw_mem-frd-16mb","249.45","1182.47","726.94","134.44"
    "signal_handler_overhead","13.36","6.42","4.98","37.72"
    "bw_mem-fwr-1mb","626.45 (min 268.49, max 984.41)","2885.14 (min 1391.30, max 4378.98)","2859.93 (min 840.90, max 4878.96)","122.88 (min 55.65, max 190.11)"
    "lat_fs-4k","112.00","88.00","122.00","12.00"
    "bw_mem-wr-4mb","593.67 (min 203.09, max 984.25)","981.23 (min 964.32, max 998.13)","633.32 (min 570.13, max 696.50)","424.74 (min 117.95, max 731.53)"
    "lat_ctx-2-128k","190.46","9.77","14.04","174.00"
    "bw_mem-bcopy-16mb","155.07","913.87","1232.29","30.56"
    "lat_mem_rd-stride128-sz125k","11.65","9.45","20.06","217.84"
    "bw_mem-rd-2mb","619.19 (min 254.45, max 983.93)","1209.22 (min 1131.22, max 1287.21)","1566.80 (min 696.26, max 2437.33)","440.29 (min 144.38, max 736.20)"
    "lat_mem_rd-stride128-sz500k","373.79","10.51","37.88","231.60"
    "lat_ops-double-add","2.37","0.91","1.10","35.09"
    "bw_mem-fcp-2mb","639.58 (min 294.25, max 984.90)","2607.28 (min 974.82, max 4239.74)","2282.25 (min 603.32, max 3961.18)","131.51 (min 70.31, max 192.70)"
    "bw_mem-wr-16mb","996.33","971.11","689.71","743.05"
    "lat_ops-int64-add","1.21","1.26","1.11","5.27"
    "bw_mem-bzero-4mb","597.70 (min 211.38, max 984.01)","2534.79 (min 917.33, max 4152.25)","2442.13 (min 1226.62, max 3657.64)","142.17 (min 91.19, max 193.15)"
    "bw_mem-frd-2mb","274.65 (min 255.04, max 294.25)","1125.57 (min 974.82, max 1276.32)","672.51 (min 603.32, max 741.70)","101.88 (min 70.31, max 133.45)"
    "lat_proc-fork","1196.25","1118.80","818.43","6728.00"
    "lat_sig-prot","0.09","0.54","0.50","0.38"
    "lat_ops-int-mod","23.51","7.95","13.39","88.39"
    "bw_mem-cp-8mb","598.60 (min 202.92, max 994.28)","2313.42 (min 471.00, max 4155.84)","2006.11 (min 604.09, max 3408.12)","150.98 (min 107.52, max 194.43)"
    "lat_ops-int64-mod","55.66","9.21","33.70","253.56"
    "lat_mem_rd-stride128-sz250k","29.90","10.10","20.16","218.88"
    "bw_mem-wr-1mb","595.29 (min 206.48, max 984.09)","1149.35 (min 1104.97, max 1193.72)","771.68 (min 682.48, max 860.88)","427.40 (min 116.78, max 738.01)"
    "lat_ops-int-div","72.98","7.52","90.35","190.00"
    "lat_mmap-1m","53.00","20.00","75.00","593.00"
    "bw_mem-bcopy-2mb","200.46","932.84","1237.43","92.69"


Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am57xx-evm: perf","am654x-evm: perf","k2g-evm: perf","omapl138-lcdk: perf"

    "cpu_clock","1000.00","1500.00","800.00","","230.00"
    "dhrystone_per_second","3846153.80","9523810.00","4255319.00","6451613.00","751879.70"
    "dhrystone_per_mhz","2.20","3.60","3.05","3.60","1.90"


Table:  **Dhrystone Benchmark**

Whestone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am57xx-evm: perf","am654x-evm: perf","k2g-evm: perf","omapl138-lcdk: perf"

    "whetstone","555.60","3333.30","2000.00","2500.00","25.70"


Table:  **Whestone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am57xx-evm: perf","am654x-evm: perf","k2g-evm: perf","omapl138-lcdk: perf"

    "linpack","55455.00","1050431.00","333253.00","693813.00","7479.00"


Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am57xx-evm: perf","am654x-evm: perf","k2g-evm: perf","omapl138-lcdk: perf"

    "assignment","8.15","17.05","8.43","11.45","0.99"
    "idea","1532.90","4511.30","1958.40","2916.50","452.24"
    "string_sort","66.81","139.64","94.89","93.91","7.78"
    "numeric_sort","388.86","687.54","450.87","460.92","103.47"
    "fp_emulation","80.17","169.65","62.52","113.06","19.51"
    "fourier","1829.70","12626.00","6829.80","8399.60","124.22"
    "huffman","806.85","1403.90","638.37","934.25","219.70"
    "lu_decomposition","75.27","822.88","321.10","554.00","5.87"
    "neural_net","2.00","22.38","4.32","15.18","0.19"


Table:  **NBench Benchmarks**

Stream
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf","am57xx-evm: perf","am654x-evm: perf","k2g-evm: perf"

    "triad","459.20","3693.90","1580.80","2304.70"
    "add","489.00","3709.30","1679.30","2389.40"
    "scale","534.80","4264.30","2089.30","2406.80"
    "copy","435.50","3845.30","1993.20","2495.20"


Table:  **Stream**

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am335x-evm: boot time (sec)","am57xx-evm: boot time (sec)","am654x-evm: boot time (sec)","k2g-evm: boot time (sec)"

    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","5.58 (min 5.57, max 5.62)","5.99 (min 5.89, max 6.14)","13.97 (min 13.89, max 14.19)","7.62 (min 7.59, max 7.69)"
    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","29.22 (min 28.74, max 30.04)","16.93 (min 15.88, max 19.98)","13.80 (min 13.67, max 13.92)","27.19 (min 26.09, max 28.41)"

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
    :header: "Sampling Rate (Hz)","am335x-evm: Throughput (bits/sec)","am335x-evm: CPU Load (%)","am57xx-evm: Throughput (bits/sec)","am57xx-evm: CPU Load (%)","k2g-evm: Throughput (bits/sec)","k2g-evm: CPU Load (%)","omapl138-lcdk: Throughput (bits/sec)","omapl138-lcdk: CPU Load (%)"

    "11025","352796.00","2.77","352790.00","0.12","352799.00","0.42","352810.00","2.98"
    "24000","705590.00","4.75","705580.00","0.22","705599.00","0.70","705636.00","4.98"
    "8000","255997.00","2.45","255990.00","0.10","352799.00","0.38","256006.00","2.20"
    "16000","511993.00","3.30","511980.00","0.15","352799.00","0.40","512020.00","3.46"
    "44100","1411176.00","8.30","1411159.00","0.43","1411197.00","1.49","1411336.00","9.78"
    "22050","705590.00","4.96","705580.00","0.24","705599.00","0.79","705636.00","5.14"
    "88200","2822341.00","16.68","2822316.00","0.83","2822390.00","2.61","2729797.00","21.14"
    "48000","1535974.00","8.77","1535941.00","0.51","1411197.00","1.37","1536160.00","10.59"
    "96000","3071934.00","1.43","3071879.00","0.59","2822390.00","2.44","2962616.00","23.92"
    "32000","1023987.00","12.63","1023961.00","0.23","705599.00","0.74","1024074.00","6.17"

Table:  **Audio Capture**

|

.. csv-table::
    :header: "Sampling Rate (Hz)","am335x-evm: Throughput (bits/sec)","am335x-evm: CPU Load (%)","am57xx-evm: Throughput (bits/sec)","am57xx-evm: CPU Load (%)","k2g-evm: Throughput (bits/sec)","k2g-evm: CPU Load (%)","omapl138-lcdk: Throughput (bits/sec)","omapl138-lcdk: CPU Load (%)"

    "11025","352942.00","2.73","352934.00","0.12","352940.00","0.34","352953.00","2.82"
    "24000","705880.00","4.94","705869.00","0.20","705880.00","0.65","705923.00","5.16"
    "8000","256103.00","0.90","256095.00","0.08","352940.00","0.48","256110.00","2.46"
    "16000","512205.00","0.89","512190.00","0.13","352940.00","0.39","512228.00","3.95"
    "44100","1411761.00","8.65","1411737.00","0.39","1411759.00","1.28","1411911.00","9.85"
    "22050","705882.00","4.30","705869.00","0.30","705880.00","0.76","705922.00","6.01"
    "88200","2823508.00","12.83","2823354.00","0.77","2823516.00","2.70","2731863.00","20.48"
    "48000","1536610.00","1.29","1536570.00","0.37","1411759.00","1.28","1536787.00","11.42"
    "96000","3073205.00","1.24","3073008.00","0.91","2823516.00","2.40","2964986.00","23.45"
    "32000","1024409.00","0.88","1024380.00","0.50","705880.00","0.70","1024490.00","6.05"

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
    "160x128","nv12","40.88 (min 40.79, max 41.00)","mt9t111"

Table:  **Sensor Capture**

|

Display Driver
-------------------------

.. csv-table::
    :header: "Mode","am335x-evm: Fps","am57xx-evm: Fps","am654x-evm: Fps","k2g-evm: Fps"

    "800x480\@60","","59.52 (min 59.51, max 59.54)","",""
    "800x480\@62","61.84 (min 60.88, max 61.90)","","",""
    "1280x800\@60","","","59.99 (min 59.99, max 60.00)",""


Table:  **Display performance (LCD)**

|

|

Table:  **Display performance (DVI)**

|


.. csv-table::
    :header: "Mode","am335x-evm: Fps","am57xx-evm: Fps","am654x-evm: Fps","k2g-evm: Fps"

    "640x480\@60","59.98 (min 59.02, max 60.00)","60.00 (min 59.98, max 60.02)","",""
    "1400x1050\@60","","59.98 (min 59.96, max 60.00)","",""
    "1600x1200\@65","","65.00 (min 64.97, max 65.03)","",""
    "1152x864\@75","","75.00 (min 74.82, max 75.21)","",""
    "1280x768\@60","","59.87 (min 59.75, max 59.99)","",""
    "800x600\@56","56.23 (min 55.33, max 56.79)","56.25 (min 56.23, max 56.27)","",""
    "1280x1024\@75","","75.03 (min 74.99, max 75.07)","",""
    "1280x720\@60","59.98 (min 59.02, max 60.01)","60.00 (min 59.92, max 60.07)","","60.00"
    "1680x945\@60","","60.02 (min 59.99, max 60.05)","",""
    "800x600\@72","72.17 (min 71.00, max 72.20)","72.19 (min 72.05, max 72.35)","","72.19 (min 72.18, max 72.20)"
    "800x600\@75","74.93 (min 73.77, max 75.01)","75.00 (min 74.97, max 75.03)","","75.00 (min 74.99, max 75.01)"
    "2048x1152\@60","","60.00 (min 59.95, max 60.05)","",""
    "1280x960\@60","","60.00 (min 59.98, max 60.02)","",""
    "848x480\@60","60.00 (min 59.93, max 60.07)","60.00 (min 59.98, max 60.02)","",""
    "1024x768\@75","","75.03 (min 74.99, max 75.06)","",""
    "1280x800\@75","","74.93 (min 74.76, max 75.08)","",""
    "1024x768\@70","","70.07 (min 70.03, max 70.13)","",""
    "1920x1080\@60","","60.00 (min 59.98, max 60.02)","",""
    "1440x900\@75","","74.98 (min 74.95, max 75.02)","",""
    "1024x576\@60","59.97 (min 59.84, max 60.09)","59.97 (min 59.95, max 59.99)","","60.01 (min 60.00, max 60.01)"
    "1600x1200\@60","","60.00 (min 59.81, max 60.18)","",""
    "640x480\@73","72.74 (min 71.60, max 72.82)","72.81 (min 72.78, max 72.84)","",""
    "1680x1050\@60","","59.95 (min 59.93, max 59.98)","",""
    "640x480\@75","74.92 (min 72.58, max 75.01)","75.00 (min 74.97, max 75.03)","",""
    "1600x900\@60","","60.00 (min 59.98, max 60.02)","",""
    "1400x1050\@75","","74.87 (min 74.82, max 74.94)","",""
    "1360x768\@60","","59.95 (min 59.93, max 59.97)","",""
    "1280x768\@75","","74.89 (min 74.86, max 74.92)","",""
    "1280x1024\@60","","60.02 (min 60.00, max 60.04)","",""
    "720x400\@70","70.03 (min 68.93, max 70.17)","70.08 (min 69.86, max 70.30)","",""
    "800x600\@60","60.30 (min 59.31, max 60.33)","60.32 (min 60.30, max 60.34)","",""
    "1024x768\@60","","60.00 (min 59.98, max 60.02)","",""
    "1280x800\@60","","59.81 (min 59.79, max 59.83)","",""
    "832x624\@75","74.48 (min 73.33, max 74.56)","74.55 (min 74.52, max 74.58)","","74.57 (min 74.56, max 74.58)"
    "1440x900\@60","","59.89 (min 59.86, max 59.93)","",""


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

    "GLB25_EgyptTestC24Z24MS4 test","2500003.00","5.19 (min 1.95, max 11.58)","2500003.00","44.13 (min 20.30, max 60.24)"
    "GLB25_EgyptTestC24Z16_PVRTC4 test","2501101.00","6.02 (min 2.36, max 13.77)","2501101.00","45.42 (min 20.89, max 60.53)"
    "GLB25_EgyptTestC24Z16_ETC1to565 test","2501401.00","6.20 (min 2.19, max 14.10)","2501401.00","45.48 (min 20.97, max 60.50)"
    "GLB25_EgyptTestC24Z16_ETC1 test","2501001.00","6.21 (min 2.40, max 14.06)","2501001.00","45.48 (min 21.02, max 60.06)"
    "GLB25_EgyptTestC24Z16FixedTime test","2500005.00","5.09 (min 2.39, max 13.99)","2500005.00","38.70 (min 21.52, max 59.35)"
    "GLB25_EgyptTestStandard_inherited test","2000000.00","23.85 (min 15.28, max 35.62)","2000000.00","59.52 (min 59.25, max 59.74)"


Table:  **GLBenchmark 2.5 Performance**

Vertex Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Rate (triangles/sec)","am57xx-evm: Test Number","am57xx-evm: Rate (triangles/sec)"

    "GLB25_TriangleTexTestC24Z16 test","2500301.00","11216748.00","2500301.00","105539456.00"
    "GLB25_TriangleTexVertexLitTestC24Z16 test","2500411.00","3738773.25","2500411.00","40481356.00"
    "GLB25_TriangleTexFragmentLitTestC24Z16 test","2500511.00","2205556.75","2500511.00","33001496.00"


Table:  **GLBenchmark 2.5 Vertex Throughput**

Pixel Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Rate (texel/sec)","am335x-evm: Fps","am57xx-evm: Test Number","am57xx-evm: Rate (texel/sec)","am57xx-evm: Fps"

    "GLB25_FillTestC24Z16 test","2500101.00","106066112.00","4.33 (min 4.18, max 5.09)","2500101.00","1435972864.00","58.33 (min 51.59, max 59.53)"


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
    "1080p","60.00","532.00",""
    "CIF","90000.00","532.00",""

Table:  **Gstreamer H264 in AVI Container Decode Performance**

|

MPEG4
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Resolution","am57xx-evm: Fps","am57xx-evm: IVA Freq (MHz)","am57xx-evm: IPU Freq (MHz)"

    "QVGA","30.00","532.00",""
    "CIF","30.00","532.00",""


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

    "16","249.36","","650.40","","792.00","","710.40","","42.48",""
    "32","288.00","","765.60","","944.00","","762.40",""
    "64","378.40","","1056.00","","897.20","","843.20","","60.64",""
    "128","375.36","","1179.20","","896.80","","833.60","","33.92",""
    "8","231.76","100.00","532.80","","660.80","","507.20",""
    "256","320.64","","1128.00","","885.76","","827.20","","57.36",""

Table: **TCP Throughput**

.. rubric::  TCP Throughput Interrupt Pacing
   :name: tcp-throughput-interrupt-pacing

.. csv-table::
    :header: "TCP Window Size (KBytes)","am335x-evm: Throughput (Mbits/sec)","am335x-evm: CPU Load ","am57xx-evm: Throughput (Mbits/sec)","am57xx-evm: CPU Load ","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load ","omapl138-lcdk: Throughput (Mbits/sec)","omapl138-lcdk: CPU Load "

    "16","292.00","","551.20","","0.00","","42.64",""
    "32","332.32","","736.80","","0.00","","26.32",""
    "64","376.72","","950.40","","0.00",""
    "128","0.00","","1023.20","","0.00","","63.92",""
    "8","168.96","","460.80","","0.00","","17.28",""
    "256","375.28","","1044.00","","0.00","","62.56",""

Table: **TCP Throughput Interrupt Pacing**


UDP Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  UDP Throughput Egress
   :name: udp-throughput-egress

.. csv-table::
    :header: "UDP Packet Size(bytes)","am335x-evm: Throughput (Mbits/sec)","am335x-evm: CPU Load ","am335x-evm: Packets Per Second (kpps) ","am57xx-evm: Throughput (Mbits/sec)","am57xx-evm: CPU Load ","am57xx-evm: Packets Per Second (kpps) ","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load ","am654x-evm: Packets Per Second (kpps) "

    "1024","250.00","99.90","30.00","719.00","80.70","87.00"
    "1500","280.00","100.00","23.00","662.00","81.00","55.00","457.00","100.00","38.00"
    "1470","469.00","99.90","39.00","880.00","73.70","74.00","480.00","100.00","40.00"
    "64","17.80","99.90","33.00","49.10","81.20","95.00"
    "128","35.60","99.90","34.00","94.60","79.30","91.00"
    "512","168.90","99.90","41.00","372.00","80.40","90.00"
    "256","72.00","99.90","35.00","195.70","80.10","95.00"

Table: **UDP Throughput Egress**

.. rubric::  UDP Throughput Ingress
   :name: udp-throughput-ingress

.. csv-table::
    :header: "UDP Packet Size(bytes)","am335x-evm: Throughput (Mbits/sec)","am335x-evm: CPU Load ","am335x-evm: Packets Per Second (kpps) ","am57xx-evm: Throughput (Mbits/sec)","am57xx-evm: CPU Load ","am57xx-evm: Packets Per Second (kpps) ","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load ","am654x-evm: Packets Per Second (kpps) "

    "1024","203.60","99.30","24.00","468.00","95.00","57.00","565.00","47.70","68.00"
    "1470","189.90","100.00","16.00","826.00","70.70","70.00","820.00","48.40","69.00"
    "1500","128.80","97.80","10.00","529.00","91.80","44.00","328.00","33.10","27.00"
    "64","15.50","85.20","29.00","34.90","75.50","66.00","31.50","43.20","60.00"
    "128","31.30","95.70","30.00","91.90","69.60","88.00","67.60","45.30","65.00"
    "512","490.00","97.00","119.00","139.00","41.50","33.00"
    "256","44.40","99.40","21.00","115.00","77.00","56.00","70.50","38.30","34.00"

Table: **UDP Throughput Ingress**


PCIe Driver
-------------------------

PCIe-ETH
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "TCP Window Size(Kbytes)","am654x-evm: Bandwidth (Mbits/sec)","k2g-evm: Bandwidth (Mbits/sec)"

    "16","745.60"
    "32","966.40"
    "64","1192.00"
    "128","616.80","1304.80"
    "8","688.08"
    "256","552.00","1357.60"

Table: **PCI Ethernet**

NAND Driver
-------------------------

AM335X-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write UBIFS Throughput (Mbytes/sec)","am335x-evm: Write UBIFS CPU Load (%)","am335x-evm: Read UBIFS Throughput (Mbytes/sec)","am335x-evm: Read UBIFS CPU Load (%)"

    "262144","4.34 (min 4.29, max 4.36)","100.00","7.35","99.93"
    "102400","4.31 (min 4.28, max 4.37)","100.00","7.33","100.00"
    "1048576","4.39 (min 4.37, max 4.42)","100.00","7.43","100.00"
    "524288","4.38 (min 4.33, max 4.41)","100.00","7.41","100.00"
    "5242880","4.41 (min 4.39, max 4.44)","100.00","7.43","100.00"









OMAPL138-LCDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^
.. csv-table::
    :header: "Buffer size (bytes)","omapl138-lcdk: Write UBIFS Throughput (Mbytes/sec)","omapl138-lcdk: Write UBIFS CPU Load (%)","omapl138-lcdk: Read UBIFS Throughput (Mbytes/sec)","omapl138-lcdk: Read UBIFS CPU Load (%)"

    "262144","1.42 (min 1.42, max 1.43)","100.00 (min 99.99, max 100.00)","1.93","100.00"
    "102400","1.42 (min 1.39, max 1.43)","100.00","1.95","100.00"
    "1048576","1.43 (min 1.41, max 1.47)","100.00","1.95","100.00"
    "524288","1.44 (min 1.43, max 1.48)","100.00","1.95","100.00"
    "5242880","1.44 (min 1.43, max 1.46)","100.00","1.94","100.00"





QSPI Flash Driver
-------------------------

AM654x-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write UBIFS Throughput (Mbytes/sec)","am654x-evm: Write UBIFS CPU Load (%)","am654x-evm: Read UBIFS Throughput (Mbytes/sec)","am654x-evm: Read UBIFS CPU Load (%)"

    "262144","0.41 (min 0.33, max 0.43)","40.37 (min 30.96, max 49.01)","16.76","8.16"
    "102400","0.68 (min 0.43, max 1.11)","35.63 (min 25.07, max 48.62)","17.33","8.51"
    "1048576","0.63 (min 0.40, max 1.11)","32.71 (min 25.07, max 40.78)","17.21","14.00"
    "524288","0.41 (min 0.33, max 0.43)","40.12 (min 30.08, max 50.79)","16.72","6.25"













K2G-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write UBIFS Throughput (Mbytes/sec)","k2g-evm: Write UBIFS CPU Load (%)","k2g-evm: Read UBIFS Throughput (Mbytes/sec)","k2g-evm: Read UBIFS CPU Load (%)"

    "262144","0.37 (min 0.31, max 0.47)","100.00","13.51","14.29"
    "102400","0.47 (min 0.32, max 0.82)","100.00","13.57","20.00"
    "1048576","0.38 (min 0.32, max 0.48)","100.00","13.36","33.33"
    "524288","0.37 (min 0.31, max 0.49)","100.00","13.47","14.29"





SPI Flash Driver
-------------------------

K2G-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
   :name: k2g-evm

.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write UBIFS Throughput (Mbytes/sec)","k2g-evm: Write UBIFS CPU Load (%)","k2g-evm: Read UBIFS Throughput (Mbytes/sec)","k2g-evm: Read UBIFS CPU Load (%)"

    "262144","0.09 (min 0.08, max 0.09)","72.85 (min 70.31, max 74.52)","0.23","7.61"
    "102400","0.10 (min 0.08, max 0.14)","67.45 (min 49.42, max 74.05)","0.23","7.48"
    "1048576","0.09 (min 0.08, max 0.09)","73.29 (min 70.62, max 75.00)","0.23","8.08"
    "524288","0.09 (min 0.08, max 0.09)","72.97 (min 70.65, max 75.07)","0.23","6.15"





EMMC Driver
-------------------------

.. raw:: html

   <div style="padding:5px; background: #eeeeee; color: #348017">

| **IMPORTANT**
| The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

.. raw:: html

   </div>

|








AM57XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write VFAT Throughput (Mbytes/sec)","am57xx-evm: Write VFAT CPU Load (%)","am57xx-evm: Read VFAT Throughput (Mbytes/sec)","am57xx-evm: Read VFAT CPU Load (%)"

    "262144","12.35 (min 11.94, max 12.49)","2.73 (min 1.98, max 4.07)","71.28","10.74"
    "102400","12.38 (min 12.06, max 12.50)","2.73 (min 1.98, max 4.33)","65.70","8.28"
    "1048576","12.21 (min 11.67, max 12.49)","2.69 (min 2.21, max 4.40)","74.41","8.27"
    "524288","12.36 (min 11.92, max 12.49)","2.91 (min 2.39, max 4.28)","74.26","9.86"
    "5242880","12.23 (min 11.83, max 12.48)","2.85 (min 2.27, max 4.48)","74.23","7.97"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)"

    "262144","12.30 (min 11.83, max 12.49)","2.42 (min 1.59, max 3.69)","75.28","6.91"
    "102400","12.43 (min 12.17, max 12.53)","2.68 (min 2.16, max 4.42)","69.48","7.69"
    "1048576","12.48 (min 12.25, max 12.56)","2.22 (min 1.45, max 4.15)","78.71","6.87"
    "524288","12.29 (min 11.77, max 12.52)","2.56 (min 1.79, max 4.14)","78.74","5.38"
    "5242880","12.48 (min 12.19, max 12.59)","2.31 (min 1.68, max 4.03)","78.72","7.20"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "262144","12.48 (min 12.37, max 12.53)","2.20 (min 1.68, max 3.38)","76.61","6.34"
    "102400","12.21 (min 12.09, max 12.25)","2.44 (min 2.06, max 3.18)","70.38","7.17"
    "1048576","12.35 (min 11.95, max 12.50)","2.33 (min 1.72, max 3.13)","79.75","8.02"
    "524288","12.35 (min 11.84, max 12.52)","2.08 (min 1.68, max 2.74)","79.68","7.63"
    "5242880","12.46 (min 12.37, max 12.51)","2.17 (min 1.92, max 2.61)","79.67","7.98"

|









AM654x-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write VFAT Throughput (Mbytes/sec)","am654x-evm: Write VFAT CPU Load (%)","am654x-evm: Read VFAT Throughput (Mbytes/sec)","am654x-evm: Read VFAT CPU Load (%)"

    "262144","32.96 (min 29.94, max 34.08)","2.85 (min 2.27, max 4.85)","154.20","10.99"
    "102400","32.47 (min 28.90, max 33.79)","3.13 (min 2.38, max 5.44)","124.77","7.55"
    "1048576","33.06 (min 30.36, max 34.01)","2.85 (min 2.23, max 4.64)","180.46","11.64"
    "524288","32.93 (min 29.82, max 34.01)","2.94 (min 2.44, max 4.63)","179.76","11.21"
    "5242880","33.28 (min 31.27, max 34.17)","2.93 (min 2.18, max 5.20)","180.57","11.35"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write EXT2 Throughput (Mbytes/sec)","am654x-evm: Write EXT2 CPU Load (%)","am654x-evm: Read EXT2 Throughput (Mbytes/sec)","am654x-evm: Read EXT2 CPU Load (%)"

    "262144","31.20 (min 30.28, max 31.56)","1.72 (min 1.43, max 2.45)","149.76","8.96"
    "102400","31.15 (min 30.82, max 31.40)","1.82 (min 1.42, max 2.78)","124.01","8.04"
    "1048576","31.31 (min 30.37, max 31.79)","1.80 (min 1.43, max 2.46)","162.60","9.38"
    "524288","31.18 (min 30.21, max 31.61)","1.67 (min 1.42, max 2.45)","159.94","8.81"
    "5242880","31.29 (min 30.65, max 31.75)","1.61 (min 1.36, max 2.19)","159.64","8.49"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write EXT4 Throughput (Mbytes/sec)","am654x-evm: Write EXT4 CPU Load (%)","am654x-evm: Read EXT4 Throughput (Mbytes/sec)","am654x-evm: Read EXT4 CPU Load (%)"

    "262144","34.36 (min 33.81, max 34.97)","1.93 (min 1.72, max 2.50)","162.34","8.20"
    "102400","31.83 (min 31.31, max 32.40)","1.90 (min 1.67, max 2.24)","122.92","7.37"
    "1048576","34.22 (min 33.38, max 34.62)","1.97 (min 1.67, max 2.36)","212.02","11.68"
    "524288","34.26 (min 33.87, max 34.67)","1.93 (min 1.74, max 2.35)","211.35","12.50"
    "5242880","34.26 (min 33.86, max 34.69)","1.97 (min 1.74, max 2.27)","212.30","13.50"

|



































K2G-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write VFAT Throughput (Mbytes/sec)","k2g-evm: Write VFAT CPU Load (%)","k2g-evm: Read VFAT Throughput (Mbytes/sec)","k2g-evm: Read VFAT CPU Load (%)"

    "262144","21.34 (min 20.50, max 21.62)","15.98 (min 13.10, max 24.56)","41.50","14.92"
    "102400","21.44 (min 20.44, max 21.97)","16.45 (min 14.31, max 24.37)","39.74","14.23"
    "1048576","21.53 (min 20.39, max 22.01)","16.12 (min 13.49, max 24.90)","42.61","15.10"
    "524288","21.54 (min 20.26, max 22.04)","16.15 (min 13.93, max 23.78)","42.62","15.10"
    "5242880","21.57 (min 20.21, max 21.98)","15.79 (min 13.14, max 24.62)","42.70","15.10"

|



.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write EXT2 Throughput (Mbytes/sec)","k2g-evm: Write EXT2 CPU Load (%)","k2g-evm: Read EXT2 Throughput (Mbytes/sec)","k2g-evm: Read EXT2 CPU Load (%)"

    "262144","21.13 (min 20.05, max 21.50)","13.58 (min 10.40, max 21.46)","42.11","13.17"
    "102400","21.18 (min 19.95, max 21.62)","14.05 (min 11.83, max 20.58)","40.32","16.22"
    "1048576","21.18 (min 19.84, max 21.60)","14.02 (min 11.62, max 22.28)","43.06","13.64"
    "524288","21.22 (min 19.80, max 21.63)","13.92 (min 11.43, max 20.76)","43.08","12.55"
    "5242880","21.15 (min 19.79, max 21.72)","13.83 (min 11.59, max 20.91)","43.07","15.10"

|



.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write EXT4 Throughput (Mbytes/sec)","k2g-evm: Write EXT4 CPU Load (%)","k2g-evm: Read EXT4 Throughput (Mbytes/sec)","k2g-evm: Read EXT4 CPU Load (%)"

    "262144","20.87 (min 20.00, max 21.26)","14.14 (min 12.40, max 19.17)","38.21","12.92"
    "102400","20.95 (min 20.42, max 21.22)","13.64 (min 12.40, max 17.09)","37.84","13.65"
    "1048576","21.30 (min 20.72, max 21.59)","13.83 (min 12.35, max 18.00)","43.46","15.16"
    "524288","21.32 (min 20.79, max 21.59)","14.12 (min 12.45, max 19.41)","43.48","14.46"
    "5242880","21.32 (min 20.68, max 21.60)","13.69 (min 12.03, max 17.60)","43.46","13.03"

|



SATA Driver
-------------------------


.. rubric::  AM57XX-EVM
   :name: am57xx-evm


|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)"

    "262144","120.20 (min 107.98, max 124.74)","10.57 (min 5.81, max 28.90)","133.11","11.94"
    "102400","122.29 (min 104.64, max 127.25)","10.28 (min 6.12, max 25.24)","134.82","12.75"
    "1048576","123.34 (min 118.70, max 125.56)","11.02 (min 6.17, max 29.84)","132.83","10.32"
    "524288","122.02 (min 118.05, max 124.24)","10.70 (min 5.51, max 29.35)","132.97","10.57"
    "5242880","122.67 (min 119.03, max 124.22)","11.28 (min 5.80, max 30.92)","133.25","10.32"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "262144","117.50 (min 115.38, max 119.66)","8.56 (min 6.80, max 15.00)","126.14","10.66"
    "102400","118.36 (min 117.08, max 119.86)","10.00 (min 6.38, max 21.67)","129.75","11.98"
    "1048576","116.02 (min 113.49, max 118.52)","8.41 (min 6.70, max 14.40)","129.10","9.36"
    "524288","116.35 (min 114.30, max 119.41)","8.60 (min 6.54, max 15.59)","124.62","10.31"
    "5242880","117.98 (min 113.51, max 121.37)","8.21 (min 5.88, max 14.61)","131.06","11.64"

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

    "262144","63.98 (min 63.20, max 64.43)","4.10 (min 2.69, max 8.30)","242.55","21.34"
    "102400","63.96 (min 63.11, max 64.52)","4.24 (min 2.66, max 9.61)","225.49","21.27"
    "1048576","63.92 (min 62.57, max 64.60)","3.64 (min 2.84, max 6.22)","258.88","22.58"
    "524288","64.00 (min 63.42, max 64.57)","3.59 (min 2.84, max 5.39)","253.85","23.60"
    "5242880","64.00 (min 63.28, max 64.52)","3.89 (min 3.25, max 5.70)","257.46","24.72"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "262144","63.93 (min 63.33, max 64.67)","3.77 (min 3.09, max 5.41)","247.24","20.86"
    "102400","64.05 (min 63.74, max 64.63)","3.88 (min 3.01, max 6.56)","216.63","20.07"
    "1048576","63.83 (min 63.59, max 64.06)","3.62 (min 2.99, max 5.08)","269.99","22.49"
    "524288","63.94 (min 63.51, max 64.28)","3.77 (min 3.04, max 5.27)","261.09","22.78"
    "5242880","64.05 (min 63.81, max 64.36)","3.61 (min 2.94, max 5.45)","271.11","22.55"

|

|

|

-  Filesize used is : 1G
-  MSATA Harddisk used is: SMS200S3/30G Kingston mSATA SSD drive

|

MMC/SD Driver
-------------------------

.. raw:: html

   <div style="padding:5px; background: #eeeeee; color: #348017">

| **IMPORTANT**
| The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

.. raw:: html

   </div>

| 



AM335x-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write VFAT Throughput (Mbytes/sec)","am335x-evm: Write VFAT CPU Load (%)","am335x-evm: Read VFAT Throughput (Mbytes/sec)","am335x-evm: Read VFAT CPU Load (%)"

    "262144","8.31 (min 7.91, max 8.87)","9.67 (min 7.99, max 14.47)","21.37","19.71"
    "102400","8.27 (min 7.62, max 9.63)","9.30 (min 6.85, max 15.24)","20.15","22.64"
    "1048576","8.31 (min 7.56, max 9.01)","9.91 (min 7.69, max 14.40)","21.25","18.28"
    "524288","8.32 (min 7.57, max 8.87)","9.90 (min 8.04, max 14.90)","21.46","17.63"
    "5242880","8.51 (min 7.79, max 8.97)","9.75 (min 8.20, max 14.70)","20.63","18.74"

|



.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write EXT2 Throughput (Mbytes/sec)","am335x-evm: Write EXT2 CPU Load (%)","am335x-evm: Read EXT2 Throughput (Mbytes/sec)","am335x-evm: Read EXT2 CPU Load (%)"

    "262144","8.89 (min 8.51, max 9.35)","22.62 (min 7.66, max 77.46)","22.01","20.64"
    "102400","8.04 (min 4.48, max 9.35)","7.35 (min 6.67, max 8.39)","21.14","20.58"
    "1048576","8.16 (min 7.88, max 8.80)","8.08 (min 6.54, max 11.84)","22.49","16.02"
    "524288","8.56 (min 7.28, max 9.26)","8.15 (min 7.23, max 9.44)","22.41","18.57"
    "5242880","8.40 (min 6.71, max 9.12)","7.86 (min 6.96, max 9.41)","22.25","15.67"

|



.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write EXT4 Throughput (Mbytes/sec)","am335x-evm: Write EXT4 CPU Load (%)","am335x-evm: Read EXT4 Throughput (Mbytes/sec)","am335x-evm: Read EXT4 CPU Load (%)"

    "262144","8.09 (min 7.62, max 8.54)","7.37 (min 5.91, max 9.46)","22.12","21.28"
    "102400","8.05 (min 7.57, max 8.63)","7.77 (min 6.57, max 9.60)","17.95","20.59"
    "1048576","8.68 (min 7.97, max 9.42)","8.11 (min 7.09, max 9.78)","22.73","15.08"
    "524288","8.41 (min 7.67, max 9.02)","7.75 (min 6.85, max 9.47)","22.52","17.94"
    "5242880","8.72 (min 7.74, max 9.55)","8.73 (min 7.07, max 13.02)","22.80","16.59"

|











AM57XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write VFAT Throughput (Mbytes/sec)","am57xx-evm: Write VFAT CPU Load (%)","am57xx-evm: Read VFAT Throughput (Mbytes/sec)","am57xx-evm: Read VFAT CPU Load (%)"

    "262144","7.95 (min 7.20, max 9.10)","1.94 (min 1.51, max 3.35)","39.67","5.84"
    "102400","10.42 (min 9.80, max 11.50)","2.39 (min 1.83, max 4.03)","38.48","6.03"
    "1048576","7.93 (min 7.77, max 8.08)","1.96 (min 1.49, max 3.38)","40.93","4.53"
    "524288","7.70 (min 7.30, max 8.14)","1.83 (min 1.35, max 2.90)","40.76","4.70"
    "5242880","7.84 (min 7.02, max 8.72)","1.90 (min 1.48, max 2.64)","40.15","4.99"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)"

    "262144","10.29 (min 9.78, max 10.88)","2.15 (min 1.45, max 3.59)","41.83","3.24"
    "102400","9.46 (min 6.28, max 10.69)","1.94 (min 1.67, max 2.21)","39.39","3.44"
    "1048576","9.87 (min 8.58, max 10.70)","2.09 (min 1.24, max 4.11)","43.19","4.13"
    "524288","10.02 (min 9.44, max 10.74)","2.13 (min 1.44, max 3.64)","43.17","3.93"
    "5242880","10.35 (min 9.56, max 11.00)","2.03 (min 1.53, max 2.93)","43.16","4.54"

|



.. csv-table::
    :header: "Buffer size (bytes)","am57xx-evm: Write EXT4 Throughput (Mbytes/sec)","am57xx-evm: Write EXT4 CPU Load (%)","am57xx-evm: Read EXT4 Throughput (Mbytes/sec)","am57xx-evm: Read EXT4 CPU Load (%)"

    "262144","9.70 (min 8.38, max 10.49)","1.71 (min 1.51, max 2.08)","31.24","2.86"
    "102400","10.17 (min 9.55, max 10.72)","2.01 (min 1.52, max 3.10)","39.58","3.82"
    "1048576","9.94 (min 8.96, max 10.71)","1.87 (min 1.37, max 2.71)","43.50","3.35"
    "524288","9.61 (min 8.34, max 10.19)","1.77 (min 1.16, max 2.48)","43.49","4.94"
    "5242880","9.25 (min 6.84, max 11.57)","1.77 (min 1.18, max 2.17)","43.52","4.17"

|
















AM654x-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write EXT2 Throughput (Mbytes/sec)","am654x-evm: Write EXT2 CPU Load (%)","am654x-evm: Read EXT2 Throughput (Mbytes/sec)","am654x-evm: Read EXT2 CPU Load (%)"

    "262144","24.81 (min 23.89, max 25.13)","1.63 (min 1.43, max 2.16)","83.10","4.58"
    "102400","25.02 (min 24.68, max 25.35)","1.61 (min 1.38, max 2.06)","74.41","5.15"
    "1048576","24.88 (min 24.01, max 25.24)","1.59 (min 1.14, max 2.01)","87.68","5.22"
    "524288","24.88 (min 24.27, max 25.08)","1.58 (min 1.37, max 2.03)","87.59","4.82"
    "5242880","24.81 (min 24.16, max 25.30)","1.58 (min 1.33, max 2.13)","87.62","5.82"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write EXT4 Throughput (Mbytes/sec)","am654x-evm: Write EXT4 CPU Load (%)","am654x-evm: Read EXT4 Throughput (Mbytes/sec)","am654x-evm: Read EXT4 CPU Load (%)"

    "262144","25.31 (min 25.10, max 25.72)","1.67 (min 1.51, max 2.04)","84.98","4.48"
    "102400","24.11 (min 21.86, max 25.75)","1.69 (min 1.41, max 2.04)","76.96","4.43"
    "1048576","25.59 (min 24.55, max 26.00)","1.67 (min 1.42, max 1.93)","90.22","5.58"
    "524288","25.71 (min 24.87, max 26.11)","1.65 (min 1.36, max 1.96)","90.42","4.75"
    "5242880","25.68 (min 24.91, max 26.20)","1.68 (min 1.31, max 2.14)","89.97","5.16"

|



























K2G-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write VFAT Throughput (Mbytes/sec)","k2g-evm: Write VFAT CPU Load (%)","k2g-evm: Read VFAT Throughput (Mbytes/sec)","k2g-evm: Read VFAT CPU Load (%)"

    "262144","8.47 (min 7.92, max 9.29)","6.75 (min 5.22, max 12.19)","21.69","9.32"
    "102400","8.37 (min 8.06, max 8.53)","6.36 (min 5.06, max 11.02)","21.33","9.26"
    "1048576","8.60 (min 7.97, max 9.09)","6.67 (min 5.23, max 11.57)","22.23","7.92"
    "524288","8.51 (min 7.96, max 8.96)","6.75 (min 5.03, max 11.51)","22.23","8.51"
    "5242880","8.57 (min 7.87, max 9.23)","6.99 (min 5.33, max 12.26)","22.22","8.53"

|



.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write EXT2 Throughput (Mbytes/sec)","k2g-evm: Write EXT2 CPU Load (%)","k2g-evm: Read EXT2 Throughput (Mbytes/sec)","k2g-evm: Read EXT2 CPU Load (%)"

    "262144","6.82 (min 5.93, max 7.34)","4.64 (min 3.67, max 7.29)","22.38","6.74"
    "102400","7.10 (min 6.18, max 7.82)","4.95 (min 3.38, max 6.79)","21.72","8.16"
    "1048576","7.50 (min 5.92, max 8.79)","5.28 (min 3.62, max 10.16)","22.54","7.73"
    "524288","7.37 (min 6.29, max 8.71)","5.14 (min 3.95, max 7.46)","22.72","7.17"
    "5242880","6.59 (min 5.90, max 7.21)","4.61 (min 3.27, max 7.91)","20.49","6.11"

|



.. csv-table::
    :header: "Buffer size (bytes)","k2g-evm: Write EXT4 Throughput (Mbytes/sec)","k2g-evm: Write EXT4 CPU Load (%)","k2g-evm: Read EXT4 Throughput (Mbytes/sec)","k2g-evm: Read EXT4 CPU Load (%)"

    "262144","7.56 (min 6.74, max 8.40)","4.96 (min 3.92, max 6.81)","21.44","9.46"
    "102400","6.54 (min 5.19, max 7.71)","4.38 (min 3.48, max 5.01)","21.77","6.41"
    "1048576","7.27 (min 6.67, max 8.06)","4.67 (min 3.83, max 6.02)","22.81","6.80"
    "524288","6.51 (min 5.47, max 7.96)","4.28 (min 3.67, max 5.02)","22.81","7.41"
    "5242880","7.36 (min 6.78, max 8.05)","4.79 (min 4.03, max 6.72)","22.82","7.00"

|



OMAPL138-LCDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","omapl138-lcdk: Write VFAT Throughput (Mbytes/sec)","omapl138-lcdk: Write VFAT CPU Load (%)","omapl138-lcdk: Read VFAT Throughput (Mbytes/sec)","omapl138-lcdk: Read VFAT CPU Load (%)"

    "262144","6.16 (min 4.61, max 6.86)","62.38 (min 54.21, max 70.74)","14.98","57.91"
    "102400","6.30 (min 4.15, max 7.05)","79.47 (min 57.51, max 97.48)","14.84","66.62"
    "1048576","5.90 (min 4.68, max 6.73)","63.48 (min 58.10, max 70.75)","14.64","56.60"
    "524288","5.94 (min 4.74, max 7.12)","60.14 (min 52.65, max 69.83)","14.42","53.13"
    "5242880","5.53 (min 4.63, max 5.90)","59.86 (min 54.08, max 62.49)","13.68","56.26"

|



.. csv-table::
    :header: "Buffer size (bytes)","omapl138-lcdk: Write EXT2 Throughput (Mbytes/sec)","omapl138-lcdk: Write EXT2 CPU Load (%)","omapl138-lcdk: Read EXT2 Throughput (Mbytes/sec)","omapl138-lcdk: Read EXT2 CPU Load (%)"

    "262144","7.11 (min 6.04, max 7.74)","45.42 (min 41.63, max 50.40)","16.01","57.21"
    "102400","6.56 (min 3.30, max 7.84)","47.68 (min 33.95, max 52.88)","15.60","60.59"
    "1048576","6.92 (min 6.08, max 7.59)","45.14 (min 41.15, max 50.63)","16.20","54.53"
    "524288","6.61 (min 6.11, max 7.41)","44.67 (min 40.57, max 53.30)","16.17","54.27"
    "5242880","6.99 (min 6.33, max 7.21)","46.89 (min 42.86, max 54.09)","15.74","57.17"

|



.. csv-table::
    :header: "Buffer size (bytes)","omapl138-lcdk: Write EXT4 Throughput (Mbytes/sec)","omapl138-lcdk: Write EXT4 CPU Load (%)","omapl138-lcdk: Read EXT4 Throughput (Mbytes/sec)","omapl138-lcdk: Read EXT4 CPU Load (%)"

    "262144","7.37 (min 6.89, max 7.68)","74.72 (min 70.16, max 86.34)","15.91","60.19"
    "102400","6.33 (min 5.22, max 7.45)","76.74 (min 68.97, max 90.98)","15.28","67.97"
    "1048576","6.66 (min 5.97, max 7.16)","69.44 (min 57.26, max 83.21)","16.05","60.97"
    "524288","6.61 (min 6.05, max 7.75)","64.61 (min 61.04, max 66.75)","16.25","57.07"
    "5242880","7.30 (min 7.04, max 7.86)","70.64 (min 61.95, max 83.64)","16.17","63.48"

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

.. raw:: html

   <div style="padding:5px; background: #eeeeee; color: #348017">

| **IMPORTANT**
| For Mass-storage applications, the performance numbers can be severely
  affected if the media is mounted in sync mode. Hot plug scripts in the
  filesystem mount removable media in sync mode to ensure data
  integrity. For performance sensitive applications, umount the
  auto-mounted filesystem and re-mount in async mode.

.. raw:: html

   </div>

|

**Setup** : Western Digital 1TB (My Book Essential) USB hard disk is
connected to usb0 port. File read/write performance data on usb0 port is
captured.

|


.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write VFAT Throughput (Mbytes/sec)","am335x-evm: Write VFAT CPU Load (%)","am335x-evm: Read VFAT Throughput (Mbytes/sec)","am335x-evm: Read VFAT CPU Load (%)","am654x-evm: Write VFAT Throughput (Mbytes/sec)","am654x-evm: Write VFAT CPU Load (%)","am654x-evm: Read VFAT Throughput (Mbytes/sec)","am654x-evm: Read VFAT CPU Load (%)"

    "262144","21.77 (min 20.86, max 22.15)","33.89 (min 29.00, max 45.53)","13.40","50.77","37.98 (min 35.08, max 38.75)","3.86 (min 3.24, max 5.37)","38.64","3.24"
    "102400","21.78 (min 20.82, max 22.19)","32.71 (min 29.28, max 42.98)","13.37","55.42","37.53 (min 34.01, max 38.51)","4.10 (min 3.48, max 5.85)","38.65","4.12"

Table: **USB Host VFAT**



.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write EXT2 Throughput (Mbytes/sec)","am335x-evm: Write EXT2 CPU Load (%)","am335x-evm: Read EXT2 Throughput (Mbytes/sec)","am335x-evm: Read EXT2 CPU Load (%)","am57xx-evm: Write EXT2 Throughput (Mbytes/sec)","am57xx-evm: Write EXT2 CPU Load (%)","am57xx-evm: Read EXT2 Throughput (Mbytes/sec)","am57xx-evm: Read EXT2 CPU Load (%)","am654x-evm: Write EXT2 Throughput (Mbytes/sec)","am654x-evm: Write EXT2 CPU Load (%)","am654x-evm: Read EXT2 Throughput (Mbytes/sec)","am654x-evm: Read EXT2 CPU Load (%)"

    "102400","22.08 (min 20.69, max 22.63)","26.57 (min 21.07, max 36.67)","13.34","48.54","211.16 (min 143.39, max 230.98)","50.19 (min 48.28, max 53.85)","221.18","32.05","39.42 (min 38.01, max 39.83)","2.62 (min 2.29, max 3.37)","38.57","3.05"
    "1048576","22.32 (min 21.07, max 22.66)","26.19 (min 21.03, max 39.11)","13.37","52.02","209.83 (min 141.88, max 232.59)","51.39 (min 49.44, max 55.26)","253.66","28.17","39.53 (min 38.07, max 39.99)","2.60 (min 2.10, max 3.54)","38.56","3.51"
    "5242880","22.08 (min 21.16, max 22.46)","25.27 (min 18.43, max 38.39)","13.33","53.02","210.69 (min 143.11, max 229.96)","50.80 (min 48.86, max 54.17)","260.04","39.02","39.57 (min 38.16, max 40.00)","2.53 (min 2.20, max 3.20)","38.56","3.15"

Table: **USB Host EXT2**





CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","Buffer Size","am335x-evm: throughput","am57xx-evm: throughput","am654x-evm: throughput"

    "sha1","1024","9418.41","12896.94","168984.52"
    "des-cbc","16","2617.34","320.65","46124.86"
    "aes-192-cbc","8192","22724.61","31012.18","16438340.27"
    "aes-256-cbc","8192","21558.61","30957.57","29794030.93"
    "sha1","8192","41721.86","54351.19","1256767.11"
    "aes-256-cbc","64","6835.65","14909.99","171469.57"
    "sha1","64","1771.26","2999.72","10718.28"
    "sha1","16","452.61","759.39","3236.78"
    "aes-128-cbc","8192","23658.50","30968.49","16211616.91"
    "md5","256","3483.99","4673.02","44613.49"
    "aes-192-cbc","64","7084.99","15389.38","134523.80"
    "aes-192-cbc","16","2619.14","4926.58","32754.54"
    "aes-256-cbc","1024","11785.56","14155.09","1778897.07"
    "des3","64","4103.98","1202.01","99695.54"
    "des3","1024","5857.96","9109.85","909107.20"
    "des-cbc","64","6842.88","1207.04","155913.41"
    "md5","64","1926.89","3453.65","12872.34"
    "sha1","256","3390.38","4605.53","43089.18"
    "aes-192-cbc","256","4811.78","5049.51","598522.09"
    "md5","16","493.38","895.54","2783.57"
    "des-cbc","256","11576.23","3966.12","561773.71"
    "des-cbc","1024","13696.00","9207.47","2235852.80"
    "aes-128-cbc","256","4759.72","5057.11","613956.92"
    "aes-256-cbc","16","2586.63","4762.37","50425.31"
    "md5","8192","42385.41","54736.21","1510277.12"
    "aes-128-cbc","1024","12065.79","14165.67","2267496.84"
    "aes-192-cbc","1024","11817.98","14154.41","2485566.58"
    "aes-128-cbc","16","2692.50","4706.33","36940.27"
    "des-cbc","8192","14469.80","14977.71","4644864.00"
    "des3","8192","5892.78","14729.22",""
    "des3","256","5408.00","3933.87","428518.40"
    "aes-256-cbc","256","4720.38","5072.21","566321.30"
    "des3","16","2136.82","318.99","30868.62"
    "aes-128-cbc","64","7537.62","15600.19","174583.04"
    "md5","1024","9832.45","13131.09","170644.95"


|
|

.. csv-table::
    :header: "Algorithm","am335x-evm: CPU Load","am57xx-evm: CPU Load","am654x-evm: CPU Load"

    "des3","98.00","23.00","99.00"
    "sha1","76.00","75.00","99.00"
    "aes-256-cbc","50.00","52.00","99.00"
    "md5","76.00","75.00","99.00"
    "des-cbc","98.00","24.00","99.00"
    "aes-192-cbc","51.00","52.00","99.00"
    "aes-128-cbc","51.00","52.00","99.00"



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

    "3des","22.00","1.00","99.80"
    "aes128","45.10","4.00","100.00","148.80","13.00","69.10"
    "aes256","43.80","3.00","99.20"
    "aes192","44.40","3.00","100.00"



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
    "vddshv4_power","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)"
    "vdds_pll_ddr_power","3.93 (min 3.92, max 3.93)","3.92","3.92 (min 3.92, max 3.93)","3.93 (min 3.92, max 3.93)","3.92"
    "vdda_1p8v_usb0_1_power","32.97 (min 32.95, max 33.04)","32.97 (min 32.93, max 33.06)","32.95 (min 32.93, max 32.97)","32.97 (min 32.95, max 32.98)","32.98 (min 32.96, max 33.00)"
    "vddshv3_power","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.16 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)"
    "vddshv5_power","51.35 (min 51.22, max 52.32)","50.35 (min 50.04, max 50.91)","51.23 (min 51.12, max 51.88)","51.12 (min 51.00, max 51.64)","51.10 (min 50.99, max 51.69)"
    "total_power","569.52 (min 568.81, max 570.96)","601.08 (min 599.54, max 602.71)","622.94 (min 620.66, max 625.37)","639.36 (min 635.32, max 646.00)","664.98 (min 659.08, max 671.53)"
    "vddshv6_power","30.93 (min 30.65, max 31.02)","30.92 (min 30.59, max 31.10)","30.86 (min 30.61, max 31.17)","30.94 (min 30.63, max 31.19)","30.90 (min 30.61, max 31.17)"
    "vdds_osc_power","1.23","1.23","1.23","1.23","1.23"
    "vdds_ddr_power","142.10 (min 141.81, max 142.54)","143.24 (min 142.64, max 143.82)","142.97 (min 142.71, max 143.55)","142.70 (min 142.45, max 143.00)","142.72 (min 142.24, max 143.15)"
    "vdd_mpu_power","47.00 (min 46.05, max 47.60)","76.55 (min 75.52, max 78.02)","97.11 (min 95.07, max 99.38)","112.76 (min 109.43, max 120.03)","136.65 (min 130.29, max 143.45)"
    "vddshv1_power","0.40 (min 0.38, max 0.40)","0.40 (min 0.39, max 0.40)","0.40 (min 0.39, max 0.40)","0.39 (min 0.39, max 0.40)","0.39 (min 0.39, max 0.40)"
    "vdds_power","2.56 (min 2.55, max 2.56)","2.59 (min 2.57, max 2.60)","2.56 (min 2.55, max 2.57)","2.56 (min 2.55, max 2.57)","2.56 (min 2.56, max 2.57)"
    "vdds_a3p3v_usb0_1_power","11.11","11.11","11.11 (min 11.10, max 11.11)","11.10 (min 11.10, max 11.11)","11.10"
    "vddshv2_power","9.40 (min 9.09, max 9.57)","9.29 (min 9.08, max 9.55)","9.28 (min 9.09, max 9.48)","9.37 (min 9.15, max 9.60)","9.33 (min 9.10, max 9.60)"
    "vdds_sram_core_bg_power","2.13 (min 2.12, max 2.14)","2.12 (min 2.11, max 2.13)","2.14 (min 2.13, max 2.14)","2.16 (min 2.16, max 2.17)","2.17 (min 2.16, max 2.18)"
    "vdds_sram_mpu_bb_power","2.87 (min 2.86, max 2.88)","2.87 (min 2.86, max 2.90)","2.90 (min 2.89, max 2.91)","3.43 (min 3.42, max 3.44)","4.09 (min 4.07, max 4.11)"
    "vdds_pll_core_lcd_power","13.15 (min 13.15, max 13.16)","13.15","13.15","13.16 (min 13.15, max 13.16)","13.15 (min 13.15, max 13.16)"
    "vdd_core_power","208.10 (min 207.94, max 208.21)","208.28 (min 208.15, max 208.44)","208.41 (min 208.23, max 209.13)","208.60 (min 208.51, max 208.69)","208.69 (min 208.57, max 208.76)"
    "vdda_adc_power","7.39 (min 7.24, max 7.48)","7.48 (min 7.47, max 7.53)","7.49 (min 7.43, max 7.54)","7.47 (min 7.44, max 7.50)","7.47 (min 7.46, max 7.48)"
    "vdds_pll_mpu_power","2.03","3.71","4.33","4.56","5.62"

Table: **Active Power Consumption at various OPPs with idle system**



.. csv-table::
    :header: "Power Rail","am335x-evm: 300M (mw)","am335x-evm: 600M (mw)","am335x-evm: 720M (mw)","am335x-evm: 800M (mw)","am335x-evm: 1000M (mw)"

    "vdds_rtc_power","0.66","0.66","0.66","0.66","0.66"
    "vddshv4_power","0.08 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)"
    "vdds_pll_ddr_power","3.92","3.92","3.92","3.93 (min 3.92, max 3.93)","3.92 (min 3.92, max 3.93)"
    "vdda_1p8v_usb0_1_power","32.92 (min 32.91, max 32.94)","32.97 (min 32.96, max 32.98)","33.23 (min 33.07, max 33.35)","32.97 (min 32.96, max 32.98)","32.98 (min 32.97, max 32.98)"
    "vddshv3_power","0.15 (min 0.15, max 0.16)","0.15","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)"
    "vddshv5_power","50.30 (min 49.95, max 51.14)","51.19 (min 50.95, max 51.62)","51.27 (min 51.26, max 51.28)","51.03 (min 51.02, max 51.04)","51.52 (min 51.28, max 52.48)"
    "total_power","621.26 (min 607.04, max 627.75)","676.36 (min 670.03, max 684.74)","712.84 (min 706.72, max 720.85)","749.41 (min 744.78, max 755.00)","823.27 (min 775.73, max 980.48)"
    "vddshv6_power","30.86 (min 30.59, max 31.05)","30.94 (min 30.61, max 31.17)","30.85 (min 30.64, max 31.05)","30.88 (min 30.66, max 31.12)","30.96 (min 30.67, max 31.16)"
    "vdds_osc_power","1.23","1.23","1.23","1.23","1.23"
    "vdds_ddr_power","150.09 (min 148.55, max 151.53)","149.66 (min 148.50, max 150.98)","150.40 (min 149.42, max 151.36)","150.12 (min 149.23, max 151.24)","150.28 (min 149.03, max 151.15)"
    "vdd_mpu_power","55.38 (min 52.78, max 57.79)","109.92 (min 104.99, max 114.69)","140.27 (min 136.73, max 143.43)","176.77 (min 175.15, max 179.27)","248.40 (min 198.72, max 411.08)"
    "vddshv1_power","0.39 (min 0.39, max 0.40)","0.39 (min 0.39, max 0.40)","0.39","0.39","0.40 (min 0.39, max 0.40)"
    "vdds_power","2.59 (min 2.58, max 2.60)","2.57 (min 2.55, max 2.58)","2.56 (min 2.55, max 2.56)","2.57 (min 2.56, max 2.58)","2.56 (min 2.55, max 2.57)"
    "vdds_a3p3v_usb0_1_power","11.11","11.10","11.10","11.10","11.10 (min 11.09, max 11.10)"
    "vddshv2_power","9.33 (min 9.08, max 9.57)","9.39 (min 9.15, max 9.59)","9.40 (min 9.08, max 9.50)","9.36 (min 9.09, max 9.55)","9.31 (min 9.09, max 9.58)"
    "vdds_sram_core_bg_power","2.24 (min 2.22, max 2.26)","2.29 (min 2.29, max 2.30)","2.28 (min 2.27, max 2.30)","2.31 (min 2.30, max 2.32)","2.31 (min 2.30, max 2.34)"
    "vdds_sram_mpu_bb_power","2.96 (min 2.93, max 2.97)","3.27 (min 3.07, max 4.06)","3.13 (min 3.09, max 3.14)","3.79 (min 3.59, max 4.49)","4.31 (min 4.27, max 4.34)"
    "vdds_pll_core_lcd_power","13.15","13.16 (min 13.15, max 13.16)","13.15","13.15 (min 13.15, max 13.16)","13.16"
    "vdd_core_power","244.77 (min 233.39, max 249.49)","242.68 (min 239.45, max 246.78)","247.19 (min 242.75, max 251.18)","247.15 (min 240.81, max 251.38)","246.99 (min 243.48, max 250.04)"
    "vdda_adc_power","7.08 (min 6.97, max 7.22)","7.06 (min 7.01, max 7.14)","7.25 (min 7.21, max 7.30)","7.20 (min 7.14, max 7.27)","7.32 (min 7.30, max 7.36)"
    "vdds_pll_mpu_power","2.03","3.71","4.33","4.56","5.62"

Table: **Active Power Consumption at various OPPs with 3D Graphics**



.. csv-table::
    :header: "Power Rail","am335x-evm: 300M (mw)","am335x-evm: 600M (mw)","am335x-evm: 720M (mw)","am335x-evm: 800M (mw)","am335x-evm: 1000M (mw)"

    "vdds_rtc_power","0.66","0.66","0.66","0.66","0.66"
    "vddshv4_power","0.08 (min 0.07, max 0.09)","0.08 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)"
    "vdds_pll_ddr_power","3.93","3.93 (min 3.92, max 3.93)","3.93","3.92 (min 3.92, max 3.93)","3.92"
    "vdda_1p8v_usb0_1_power","32.98 (min 32.97, max 33.00)","32.98 (min 32.96, max 32.99)","32.99 (min 32.98, max 33.01)","32.97 (min 32.95, max 33.00)","32.96 (min 32.94, max 32.97)"
    "vddshv3_power","0.15 (min 0.15, max 0.16)","0.16 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15","0.15 (min 0.15, max 0.16)"
    "vddshv5_power","51.57 (min 51.30, max 52.04)","51.39 (min 51.03, max 51.58)","51.65 (min 51.61, max 51.68)","51.75 (min 51.60, max 52.28)","51.76 (min 51.61, max 52.20)"
    "total_power","644.69 (min 591.44, max 667.82)","738.80 (min 603.19, max 815.66)","863.42 (min 681.37, max 912.03)","925.17 (min 701.66, max 984.80)","1107.28 (min 1038.06, max 1134.00)"
    "vddshv6_power","41.74 (min 20.59, max 51.56)","40.63 (min 20.61, max 51.68)","48.16 (min 42.15, max 52.29)","47.20 (min 43.38, max 51.19)","48.08 (min 45.41, max 50.66)"
    "vdds_osc_power","1.23","1.23","1.23","1.23","1.23"
    "vdds_ddr_power","144.60 (min 142.01, max 145.58)","144.58 (min 142.34, max 146.24)","145.23 (min 141.28, max 147.96)","146.34 (min 144.19, max 147.67)","147.56 (min 141.93, max 149.78)"
    "vdd_mpu_power","88.11 (min 79.28, max 92.91)","190.81 (min 76.38, max 234.76)","287.67 (min 114.69, max 333.91)","347.70 (min 133.16, max 402.81)","522.71 (min 466.11, max 545.13)"
    "vddshv1_power","0.39 (min 0.38, max 0.40)","0.39 (min 0.38, max 0.40)","0.38 (min 0.38, max 0.39)","0.38 (min 0.38, max 0.39)","0.38 (min 0.38, max 0.39)"
    "vdds_power","2.88 (min 2.25, max 3.15)","2.76 (min 2.27, max 3.21)","2.93 (min 2.26, max 3.18)","2.96 (min 2.28, max 3.17)","2.97 (min 2.25, max 3.19)"
    "vdds_a3p3v_usb0_1_power","11.10 (min 11.10, max 11.11)","11.10 (min 11.09, max 11.10)","11.09 (min 11.08, max 11.09)","11.08 (min 11.08, max 11.09)","11.07 (min 11.07, max 11.08)"
    "vddshv2_power","23.18 (min 0.10, max 30.40)","13.46 (min 0.10, max 30.01)","28.79 (min 26.99, max 30.68)","29.18 (min 27.66, max 30.31)","27.78 (min 26.64, max 29.10)"
    "vdds_sram_core_bg_power","2.16 (min 2.15, max 2.17)","2.20 (min 2.18, max 2.22)","2.26 (min 2.21, max 2.28)","2.26 (min 2.22, max 2.29)","2.30 (min 2.25, max 2.33)"
    "vdds_sram_mpu_bb_power","3.56 (min 2.90, max 3.79)","4.73 (min 4.53, max 4.96)","5.39 (min 5.11, max 5.58)","5.86 (min 5.34, max 6.19)","7.08 (min 6.91, max 7.33)"
    "vdds_pll_core_lcd_power","13.16 (min 13.15, max 13.16)","13.16 (min 13.15, max 13.16)","13.16","13.16 (min 13.15, max 13.16)","13.16 (min 13.15, max 13.16)"
    "vdd_core_power","213.69 (min 210.37, max 215.85)","213.45 (min 208.56, max 216.78)","215.79 (min 207.48, max 218.11)","216.19 (min 207.33, max 218.98)","220.27 (min 212.50, max 222.44)"
    "vdda_adc_power","7.49 (min 7.47, max 7.52)","7.39 (min 6.86, max 7.57)","7.53 (min 7.51, max 7.58)","7.53 (min 7.51, max 7.56)","7.54 (min 7.50, max 7.57)"
    "vdds_pll_mpu_power","2.03","3.71","4.33","4.56 (min 4.55, max 4.56)","5.62 (min 5.61, max 5.62)"

Table: **Active Power Consumption at various OPPs with video+audio**



.. csv-table::
    :header: "Power Rail","am335x-evm: 300M (mw)","am335x-evm: 600M (mw)","am335x-evm: 720M (mw)","am335x-evm: 800M (mw)","am335x-evm: 1000M (mw)"

    "vdds_rtc_power","0.66","0.66","0.66","0.66","0.66"
    "vddshv4_power","0.09 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)","0.08","0.08 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)"
    "vdds_pll_ddr_power","3.93","3.93","3.92","3.92 (min 3.92, max 3.93)","3.92"
    "vdda_1p8v_usb0_1_power","32.97 (min 32.96, max 32.99)","32.96 (min 32.94, max 32.97)","32.95 (min 32.94, max 32.96)","32.96 (min 32.94, max 32.98)","32.97 (min 32.95, max 32.98)"
    "vddshv3_power","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15","0.16 (min 0.15, max 0.16)"
    "vddshv5_power","51.37 (min 51.24, max 51.90)","51.25 (min 51.24, max 51.26)","51.21 (min 51.20, max 51.22)","51.30 (min 51.19, max 51.70)","51.27 (min 51.23, max 51.37)"
    "total_power","570.25 (min 569.05, max 572.93)","622.80 (min 601.48, max 703.68)","623.51 (min 621.47, max 624.79)","641.49 (min 637.99, max 646.73)","670.49 (min 662.72, max 680.63)"
    "vddshv6_power","30.90 (min 30.63, max 31.10)","30.95 (min 30.91, max 31.05)","31.02 (min 30.93, max 31.10)","30.95 (min 30.74, max 31.06)","30.96 (min 30.70, max 31.16)"
    "vdds_osc_power","1.23","1.23","1.23","1.23","1.23"
    "vdds_ddr_power","142.10 (min 141.90, max 142.33)","142.84 (min 142.27, max 143.15)","142.76 (min 142.38, max 142.99)","143.09 (min 142.78, max 143.28)","142.95 (min 142.53, max 143.19)"
    "vdd_mpu_power","47.30 (min 46.24, max 48.36)","97.42 (min 76.00, max 178.69)","97.60 (min 95.67, max 99.63)","114.32 (min 110.19, max 119.56)","141.94 (min 133.90, max 152.26)"
    "vddshv1_power","0.40 (min 0.39, max 0.40)","0.39","0.39 (min 0.39, max 0.40)","0.40 (min 0.39, max 0.41)","0.39 (min 0.39, max 0.40)"
    "vdds_power","2.56 (min 2.55, max 2.57)","2.56 (min 2.55, max 2.56)","2.56 (min 2.54, max 2.56)","2.56 (min 2.55, max 2.57)","2.56 (min 2.55, max 2.56)"
    "vdds_a3p3v_usb0_1_power","11.11","11.11 (min 11.10, max 11.11)","11.11","11.11","11.10 (min 11.10, max 11.11)"
    "vddshv2_power","9.38 (min 9.08, max 9.60)","9.45 (min 9.29, max 9.56)","9.32 (min 9.09, max 9.47)","9.42 (min 9.27, max 9.56)","9.34 (min 9.08, max 9.55)"
    "vdds_sram_core_bg_power","2.13 (min 2.13, max 2.15)","2.14 (min 2.14, max 2.15)","2.13 (min 2.12, max 2.14)","2.15 (min 2.14, max 2.15)","2.15 (min 2.14, max 2.16)"
    "vdds_sram_mpu_bb_power","2.88 (min 2.87, max 2.90)","2.91 (min 2.89, max 2.92)","3.18 (min 2.89, max 4.34)","3.56 (min 3.40, max 4.15)","4.05 (min 4.05, max 4.06)"
    "vdds_pll_core_lcd_power","13.15 (min 13.15, max 13.16)","13.15 (min 13.15, max 13.16)","13.15","13.15","13.15"
    "vdd_core_power","208.46 (min 208.13, max 210.14)","208.41 (min 208.24, max 208.56)","208.27 (min 208.17, max 208.33)","208.44 (min 208.23, max 208.60)","208.52 (min 208.39, max 208.66)"
    "vdda_adc_power","7.44 (min 7.35, max 7.52)","7.50 (min 7.49, max 7.54)","7.47 (min 7.45, max 7.50)","7.47 (min 7.47, max 7.48)","7.47 (min 7.45, max 7.48)"
    "vdds_pll_mpu_power","2.03","3.71","4.33","4.56","5.62"

Table: **Active Power Consumption at various OPPs with network load**



.. csv-table::
    :header: "Power Rail","am335x-evm: 300M (mw)","am335x-evm: 600M (mw)","am335x-evm: 720M (mw)","am335x-evm: 800M (mw)","am335x-evm: 1000M (mw)"

    "vdds_rtc_power","0.66","0.66","0.66","0.66","0.66"
    "vddshv4_power","0.08 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)","0.08","0.08 (min 0.08, max 0.09)"
    "vdds_pll_ddr_power","3.92 (min 3.92, max 3.93)","3.93","3.93","3.93","3.93"
    "vdda_1p8v_usb0_1_power","32.90 (min 32.87, max 33.04)","32.92 (min 32.91, max 32.92)","32.92 (min 32.92, max 32.93)","32.99 (min 32.97, max 33.01)","33.01 (min 33.00, max 33.02)"
    "vddshv3_power","0.15 (min 0.14, max 0.15)","0.16 (min 0.15, max 0.16)","0.15","0.15","0.15"
    "vddshv5_power","51.17 (min 51.04, max 51.86)","51.61 (min 51.44, max 52.24)","51.53 (min 51.28, max 52.48)","51.49 (min 51.31, max 52.18)","50.69 (min 50.34, max 51.57)"
    "total_power","636.49 (min 635.74, max 638.06)","833.95 (min 833.34, max 835.21)","972.43 (min 969.74, max 976.71)","1062.88 (min 1005.25, max 1077.73)","1277.91 (min 1275.62, max 1280.12)"
    "vddshv6_power","30.99 (min 30.75, max 31.19)","30.91 (min 30.73, max 31.07)","31.02 (min 30.69, max 31.26)","31.02 (min 30.68, max 31.25)","31.14 (min 31.05, max 31.22)"
    "vdds_osc_power","1.23","1.23","1.23","1.23","1.23"
    "vdds_ddr_power","142.84 (min 142.62, max 143.10)","143.23 (min 142.98, max 143.48)","142.65 (min 142.12, max 142.93)","142.71 (min 142.50, max 142.93)","143.00 (min 142.93, max 143.07)"
    "vdd_mpu_power","113.39 (min 113.01, max 113.57)","305.40 (min 305.10, max 305.70)","440.67 (min 440.20, max 441.11)","530.60 (min 473.48, max 545.27)","742.42 (min 740.79, max 743.29)"
    "vddshv1_power","0.39","0.39 (min 0.39, max 0.40)","0.39 (min 0.38, max 0.39)","0.39 (min 0.38, max 0.39)","0.39 (min 0.38, max 0.39)"
    "vdds_power","2.56 (min 2.55, max 2.58)","2.55 (min 2.54, max 2.57)","2.57 (min 2.57, max 2.58)","2.57 (min 2.56, max 2.57)","2.61 (min 2.60, max 2.61)"
    "vdds_a3p3v_usb0_1_power","11.11","11.10 (min 11.10, max 11.11)","11.08 (min 11.08, max 11.09)","11.07 (min 11.07, max 11.08)","11.06 (min 11.05, max 11.06)"
    "vddshv2_power","9.42 (min 9.13, max 9.57)","9.36 (min 9.12, max 9.58)","9.35 (min 9.11, max 9.56)","9.28 (min 9.10, max 9.45)","9.32 (min 9.14, max 9.46)"
    "vdds_sram_core_bg_power","2.15 (min 2.15, max 2.16)","2.20","2.29 (min 2.28, max 2.30)","2.34 (min 2.32, max 2.35)","2.41 (min 2.39, max 2.43)"
    "vdds_sram_mpu_bb_power","4.78 (min 4.77, max 4.79)","7.23 (min 7.23, max 7.24)","8.35 (min 8.32, max 8.37)","9.28 (min 9.26, max 9.30)","11.04 (min 8.16, max 11.79)"
    "vdds_pll_core_lcd_power","13.16","13.16","13.16","13.16 (min 13.16, max 13.17)","13.17 (min 13.16, max 13.17)"
    "vdd_core_power","206.03 (min 205.76, max 207.51)","206.57 (min 206.50, max 206.62)","208.50 (min 207.43, max 212.69)","207.84 (min 207.58, max 208.00)","208.44 (min 208.12, max 208.56)"
    "vdda_adc_power","7.52 (min 7.50, max 7.56)","7.55 (min 7.52, max 7.56)","7.56 (min 7.54, max 7.57)","7.54 (min 7.52, max 7.57)","7.55 (min 7.53, max 7.57)"
    "vdds_pll_mpu_power","2.03","3.71","4.33","4.56","5.62 (min 5.61, max 5.62)"

Table: **Active Power Consumption at various OPPs with Dhrystone**



.. csv-table::
    :header: "Power Rail","am335x-evm: 300M (mw)","am335x-evm: 600M (mw)","am335x-evm: 720M (mw)","am335x-evm: 800M (mw)","am335x-evm: 1000M (mw)"

    "vdds_rtc_power","0.66","0.66","0.66","0.66","0.66"
    "vddshv4_power","0.08 (min 0.08, max 0.09)","0.08","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)"
    "vdds_pll_ddr_power","3.92","3.92","3.93","3.93","3.92 (min 3.92, max 3.93)"
    "vdda_1p8v_usb0_1_power","32.93 (min 32.90, max 32.96)","32.93 (min 32.92, max 32.95)","32.94 (min 32.92, max 32.96)","32.97 (min 32.90, max 33.11)","32.98 (min 32.96, max 33.00)"
    "vddshv3_power","0.15","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15"
    "vddshv5_power","51.02 (min 50.42, max 51.73)","51.56 (min 51.31, max 52.52)","51.52 (min 51.34, max 52.11)","51.59 (min 51.38, max 52.34)","50.80 (min 50.71, max 50.83)"
    "total_power","621.96 (min 615.65, max 627.71)","756.99 (min 748.80, max 764.16)","838.88 (min 835.28, max 842.85)","897.54 (min 889.31, max 902.09)","1014.34 (min 1004.28, max 1024.27)"
    "vddshv6_power","31.03 (min 30.83, max 31.18)","30.92 (min 30.78, max 31.08)","30.93 (min 30.80, max 31.15)","30.88 (min 30.66, max 31.12)","30.94 (min 30.64, max 31.20)"
    "vdds_osc_power","1.23","1.23","1.23","1.23","1.23"
    "vdds_ddr_power","148.17 (min 143.56, max 151.93)","151.93 (min 144.51, max 157.01)","150.81 (min 144.48, max 157.51)","152.36 (min 144.68, max 158.34)","149.97 (min 144.88, max 158.36)"
    "vdd_mpu_power","86.98 (min 82.71, max 88.08)","210.41 (min 207.71, max 213.47)","291.25 (min 285.69, max 299.84)","347.04 (min 343.17, max 361.79)","463.72 (min 444.93, max 476.22)"
    "vddshv1_power","0.39 (min 0.39, max 0.40)","0.39 (min 0.38, max 0.39)","0.39","0.39","0.39"
    "vdds_power","2.57 (min 2.56, max 2.58)","2.56 (min 2.55, max 2.57)","2.56 (min 2.55, max 2.57)","2.57 (min 2.56, max 2.58)","2.58 (min 2.58, max 2.59)"
    "vdds_a3p3v_usb0_1_power","11.11","11.10","11.10 (min 11.09, max 11.10)","11.09","11.08"
    "vddshv2_power","9.41 (min 9.14, max 9.59)","9.45 (min 9.25, max 9.57)","9.30 (min 9.13, max 9.44)","9.29 (min 9.09, max 9.57)","9.22 (min 9.09, max 9.47)"
    "vdds_sram_core_bg_power","2.12 (min 2.11, max 2.13)","2.17","2.22 (min 2.21, max 2.22)","2.24 (min 2.24, max 2.25)","2.29 (min 2.27, max 2.29)"
    "vdds_sram_mpu_bb_power","3.81 (min 3.63, max 3.93)","4.70 (min 4.48, max 4.84)","4.86 (min 4.63, max 5.21)","5.33 (min 5.06, max 5.74)","6.40 (min 5.83, max 6.79)"
    "vdds_pll_core_lcd_power","13.15","13.15","13.16","13.16","13.16"
    "vdd_core_power","213.71 (min 210.83, max 216.70)","218.45 (min 214.50, max 221.35)","219.93 (min 216.00, max 222.61)","220.50 (min 216.69, max 223.14)","221.63 (min 218.19, max 223.97)"
    "vdda_adc_power","7.48 (min 7.47, max 7.48)","7.50 (min 7.48, max 7.53)","7.51 (min 7.49, max 7.54)","7.51 (min 7.50, max 7.53)","7.50 (min 7.49, max 7.52)"
    "vdds_pll_mpu_power","2.03","3.71","4.33","4.56","5.62"

Table: **Active Power Consumption at various OPPs with Memory Tester**


.. rubric:: Power-Saving States
   :name: power-saving-states

This section indicates the power measured for all power rails when system is
in suspended state (via suspend-to-ram) and in standby state.


.. csv-table::
    :header: "Power Rail","am335x-evm: Suspend Power (mw)","am335x-evm: Standby Power (mw)"

    "vdds_rtc_power","0.04","0.04"
    "vddshv4_power","0.09 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)"
    "vdds_pll_ddr_power","0.00","0.00"
    "vdda_1p8v_usb0_1_power","0.00 (min 0.00, max 0.01)","0.00"
    "vddshv3_power","0.12 (min 0.11, max 0.13)","0.16"
    "vddshv5_power","0.11 (min 0.11, max 0.12)","0.11 (min 0.11, max 0.12)"
    "total_power","5.63 (min 5.59, max 5.76)","19.77 (min 19.68, max 19.89)"
    "vddshv6_power","0.55 (min 0.54, max 0.56)","0.55 (min 0.54, max 0.55)"
    "vdds_osc_power","0.00","1.25"
    "vdds_ddr_power","0.74 (min 0.74, max 0.76)","0.75 (min 0.74, max 0.75)"
    "vdd_mpu_power","0.25 (min 0.24, max 0.28)","0.30 (min 0.30, max 0.31)"
    "vddshv1_power","0.28 (min 0.27, max 0.29)","0.42 (min 0.42, max 0.43)"
    "vdds_power","1.28 (min 1.27, max 1.31)","0.88"
    "vdds_a3p3v_usb0_1_power","0.07","0.08"
    "vddshv2_power","0.08 (min 0.08, max 0.09)","0.08"
    "vdds_sram_core_bg_power","0.82 (min 0.82, max 0.85)","1.85 (min 1.83, max 1.86)"
    "vdds_sram_mpu_bb_power","0.01","0.01"
    "vdds_pll_core_lcd_power","0.00","0.00"
    "vdd_core_power","1.16 (min 1.15, max 1.22)","13.20 (min 13.11, max 13.30)"
    "vdda_adc_power","0.00","0.01 (min 0.00, max 0.01)"
    "vdds_pll_mpu_power","0.00","0.00"



.. rubric:: Wakeup Times
   :name: wakeup-times

This section indicates the time it takes to resume the board from suspend and standby state.
Two wakeup mechanisms (UART console and Real Time Clock) were used.


.. csv-table::
    :header: "Wakeup time","am335x-evm: Suspend UART (ms)","am335x-evm: Standby UART (ms)","am335x-evm: Suspend RTC (ms)","am335x-evm: Standby RTC (ms)","am335x-evm: Suspend GPIO (ms)"

    "resume_time","2347.23 (min 2343.78, max 2349.87)","926.99 (min 923.71, max 932.69)","2346.89 (min 2344.22, max 2351.26)","927.97 (min 923.84, max 933.30)","2347.36 (min 2344.16, max 2351.32)"




.. rubric:: With different Governors
   :name: different-governors

This section indicates the power measured for all power rails with different power management policies.


.. csv-table::
    :header: "Power Rail","am335x-evm: idle (mw)","am335x-evm: 3D graphics (mw)","am335x-evm: video+audio (mw)","am335x-evm: network load (mw)","am335x-evm: Dhrystone (mw)","am335x-evm: memtester (mw)"

    "vdds_rtc_power","0.66","0.66","0.66","0.66","0.66","0.66"
    "vddshv4_power","0.09 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)"
    "vdds_pll_ddr_power","3.93 (min 3.92, max 3.93)","3.92","3.92 (min 3.92, max 3.93)","3.92","3.93 (min 3.92, max 3.93)","3.93"
    "vdda_1p8v_usb0_1_power","32.95 (min 32.93, max 32.97)","32.96 (min 32.94, max 32.96)","32.91 (min 32.88, max 32.93)","32.93 (min 32.92, max 32.96)","32.98 (min 32.95, max 33.02)","33.02 (min 32.96, max 33.20)"
    "vddshv3_power","0.15 (min 0.14, max 0.15)","0.15 (min 0.15, max 0.16)","0.15","0.15 (min 0.14, max 0.16)","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)"
    "vddshv5_power","51.34 (min 51.22, max 51.90)","51.49 (min 51.25, max 52.45)","51.66 (min 51.60, max 51.70)","51.27 (min 51.18, max 51.57)","51.80 (min 51.57, max 52.67)","51.53 (min 51.43, max 51.86)"
    "total_power","589.11 (min 584.18, max 594.72)","671.73 (min 664.52, max 678.25)","1119.53 (min 1058.28, max 1142.23)","591.55 (min 589.49, max 593.89)","1277.83 (min 1272.06, max 1285.54)","1014.24 (min 1001.77, max 1025.66)"
    "vddshv6_power","30.87 (min 30.61, max 31.08)","31.01 (min 30.86, max 31.12)","47.98 (min 44.45, max 51.39)","30.81 (min 30.58, max 30.97)","30.96 (min 30.72, max 31.16)","30.85 (min 30.68, max 31.03)"
    "vdds_osc_power","1.23","1.23","1.23","1.23","1.23 (min 1.22, max 1.23)","1.23"
    "vdds_ddr_power","142.32 (min 141.99, max 142.59)","149.69 (min 149.28, max 150.11)","147.75 (min 143.07, max 149.65)","143.19 (min 142.27, max 145.63)","142.71 (min 142.35, max 143.02)","148.82 (min 144.67, max 157.96)"
    "vdd_mpu_power","64.98 (min 60.13, max 70.65)","102.56 (min 95.66, max 109.11)","533.54 (min 477.54, max 557.30)","66.93 (min 62.21, max 69.72)","739.74 (min 735.13, max 741.55)","463.64 (min 445.12, max 476.42)"
    "vddshv1_power","0.39 (min 0.39, max 0.40)","0.39","0.39 (min 0.38, max 0.39)","0.39","0.39 (min 0.38, max 0.39)","0.39"
    "vdds_power","2.56 (min 2.55, max 2.57)","2.56 (min 2.55, max 2.58)","2.96 (min 2.26, max 3.18)","2.56 (min 2.55, max 2.56)","2.56 (min 2.55, max 2.57)","2.56 (min 2.55, max 2.57)"
    "vdds_a3p3v_usb0_1_power","11.11 (min 11.10, max 11.11)","11.10","11.07 (min 11.07, max 11.08)","11.11 (min 11.10, max 11.11)","11.05 (min 11.05, max 11.06)","11.07 (min 11.07, max 11.08)"
    "vddshv2_power","9.37 (min 9.10, max 9.58)","9.38 (min 9.10, max 9.58)","27.61 (min 25.91, max 29.85)","9.32 (min 9.09, max 9.49)","9.38 (min 9.21, max 9.58)","9.35 (min 9.15, max 9.57)"
    "vdds_sram_core_bg_power","2.14 (min 2.13, max 2.16)","2.29 (min 2.27, max 2.31)","2.30 (min 2.24, max 2.33)","2.12 (min 2.11, max 2.13)","2.40 (min 2.37, max 2.42)","2.32 (min 2.30, max 2.32)"
    "vdds_sram_mpu_bb_power","2.92 (min 2.90, max 2.93)","3.11 (min 3.07, max 3.13)","7.11 (min 6.83, max 7.36)","2.89 (min 2.88, max 2.92)","11.72 (min 11.59, max 11.78)","6.45 (min 5.87, max 6.84)"
    "vdds_pll_core_lcd_power","13.15 (min 13.15, max 13.16)","13.15","13.16 (min 13.15, max 13.16)","13.15","13.16","13.16"
    "vdd_core_power","208.51 (min 208.40, max 208.71)","245.34 (min 242.31, max 250.79)","221.90 (min 217.84, max 223.43)","208.42 (min 208.22, max 208.65)","209.74 (min 208.30, max 215.32)","221.87 (min 218.29, max 224.37)"
    "vdda_adc_power","7.42 (min 7.32, max 7.47)","7.09 (min 7.04, max 7.15)","7.53 (min 7.50, max 7.56)","7.40 (min 7.36, max 7.47)","7.56 (min 7.52, max 7.58)","7.53 (min 7.50, max 7.55)"
    "vdds_pll_mpu_power","3.02 (min 2.73, max 3.71)","3.57 (min 3.24, max 3.71)","5.62","3.02 (min 2.88, max 3.11)","5.62 (min 5.61, max 5.62)","5.62"

Table: **Power Consumption with ondemand governor**



.. csv-table::
    :header: "Power Rail","am335x-evm: idle (mw)","am335x-evm: 3D graphics (mw)","am335x-evm: video+audio (mw)","am335x-evm: network load (mw)","am335x-evm: Dhrystone (mw)","am335x-evm: memtester (mw)"

    "vdds_rtc_power","0.66","0.66","0.66","0.66","0.66","0.66"
    "vddshv4_power","0.09 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)"
    "vdds_pll_ddr_power","3.92","3.93","3.93 (min 3.92, max 3.93)","3.92 (min 3.92, max 3.93)","3.93 (min 3.92, max 3.93)","3.93"
    "vdda_1p8v_usb0_1_power","32.95 (min 32.93, max 32.96)","32.99 (min 32.97, max 33.01)","32.95 (min 32.94, max 32.97)","32.97 (min 32.96, max 32.98)","32.98 (min 32.95, max 33.02)","33.02 (min 32.96, max 33.20)"
    "vddshv3_power","0.16 (min 0.15, max 0.16)","0.16 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15 (min 0.14, max 0.15)","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)"
    "vddshv5_power","51.35 (min 51.05, max 52.30)","51.05 (min 50.80, max 51.88)","51.78 (min 51.66, max 52.06)","51.30","51.80 (min 51.57, max 52.67)","51.53 (min 51.43, max 51.86)"
    "total_power","666.69 (min 660.98, max 679.09)","775.04 (min 756.82, max 782.92)","1108.89 (min 1030.66, max 1135.77)","667.40 (min 662.69, max 673.22)","1277.83 (min 1272.06, max 1285.54)","1014.24 (min 1001.77, max 1025.66)"
    "vddshv6_power","30.90 (min 30.60, max 31.13)","31.00 (min 30.92, max 31.06)","48.24 (min 44.96, max 51.80)","30.96 (min 30.70, max 31.07)","30.96 (min 30.72, max 31.16)","30.85 (min 30.68, max 31.03)"
    "vdds_osc_power","1.23","1.23","1.23","1.23","1.23 (min 1.22, max 1.23)","1.23"
    "vdds_ddr_power","143.25 (min 142.15, max 145.65)","150.32 (min 149.08, max 151.81)","147.97 (min 142.61, max 149.99)","142.89 (min 142.52, max 143.04)","142.71 (min 142.35, max 143.02)","148.82 (min 144.67, max 157.96)"
    "vdd_mpu_power","137.74 (min 131.63, max 149.37)","201.77 (min 188.08, max 211.63)","523.40 (min 456.97, max 542.61)","137.06 (min 133.79, max 140.26)","739.74 (min 735.13, max 741.55)","463.64 (min 445.12, max 476.42)"
    "vddshv1_power","0.39 (min 0.39, max 0.40)","0.39 (min 0.39, max 0.40)","0.39 (min 0.38, max 0.39)","0.39 (min 0.39, max 0.40)","0.39 (min 0.38, max 0.39)","0.39"
    "vdds_power","2.56 (min 2.55, max 2.57)","2.58 (min 2.57, max 2.60)","2.96 (min 2.26, max 3.19)","2.56 (min 2.55, max 2.56)","2.56 (min 2.55, max 2.57)","2.56 (min 2.55, max 2.57)"
    "vdds_a3p3v_usb0_1_power","11.11 (min 11.10, max 11.11)","11.10 (min 11.09, max 11.10)","11.07 (min 11.07, max 11.08)","11.10","11.05 (min 11.05, max 11.06)","11.07 (min 11.07, max 11.08)"
    "vddshv2_power","9.31 (min 9.08, max 9.54)","9.40 (min 9.09, max 9.56)","27.43 (min 25.85, max 28.88)","9.41 (min 9.26, max 9.54)","9.38 (min 9.21, max 9.58)","9.35 (min 9.15, max 9.57)"
    "vdds_sram_core_bg_power","2.14","2.34 (min 2.31, max 2.36)","2.33 (min 2.27, max 2.36)","2.18 (min 2.17, max 2.19)","2.40 (min 2.37, max 2.42)","2.32 (min 2.30, max 2.32)"
    "vdds_sram_mpu_bb_power","4.06 (min 4.03, max 4.19)","4.31 (min 4.28, max 4.34)","7.10 (min 6.55, max 7.33)","4.11 (min 4.09, max 4.13)","11.72 (min 11.59, max 11.78)","6.45 (min 5.87, max 6.84)"
    "vdds_pll_core_lcd_power","13.15","13.16","13.16","13.16 (min 13.15, max 13.16)","13.16","13.16"
    "vdd_core_power","208.63 (min 208.37, max 210.35)","245.65 (min 239.88, max 250.67)","220.92 (min 212.89, max 223.54)","210.15 (min 208.65, max 216.01)","209.74 (min 208.30, max 215.32)","221.87 (min 218.29, max 224.37)"
    "vdda_adc_power","7.48 (min 7.46, max 7.49)","7.31 (min 7.22, max 7.37)","7.52 (min 7.49, max 7.55)","7.48 (min 7.48, max 7.49)","7.56 (min 7.52, max 7.58)","7.53 (min 7.50, max 7.55)"
    "vdds_pll_mpu_power","5.62 (min 5.61, max 5.62)","5.62","5.62","5.62","5.62 (min 5.61, max 5.62)","5.62"

Table: **Power Consumption with performance governor**



.. csv-table::
    :header: "Power Rail","am335x-evm: idle (mw)","am335x-evm: 3D graphics (mw)","am335x-evm: video+audio (mw)","am335x-evm: network load (mw)","am335x-evm: Dhrystone (mw)","am335x-evm: memtester (mw)"

    "vdds_rtc_power","0.66","0.66","0.66","0.66","0.66","0.66"
    "vddshv4_power","0.08 (min 0.08, max 0.09)","0.08","0.08","0.08 (min 0.08, max 0.09)","0.08","0.08"
    "vdds_pll_ddr_power","3.92 (min 3.92, max 3.93)","3.92 (min 3.92, max 3.93)","3.93","3.92","3.92","3.92"
    "vdda_1p8v_usb0_1_power","32.94 (min 32.93, max 32.95)","32.93 (min 32.92, max 32.95)","32.97 (min 32.96, max 32.98)","32.95 (min 32.94, max 32.96)","32.97 (min 32.96, max 32.97)","32.93 (min 32.91, max 32.94)"
    "vddshv3_power","0.15 (min 0.14, max 0.16)","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15","0.15","0.15"
    "vddshv5_power","50.67 (min 49.96, max 51.93)","51.40 (min 51.16, max 52.36)","51.27 (min 50.20, max 51.58)","51.27 (min 51.18, max 51.56)","51.35 (min 51.21, max 51.88)","51.42 (min 51.24, max 52.11)"
    "total_power","569.68 (min 567.58, max 573.31)","622.58 (min 614.99, max 627.74)","636.99 (min 592.48, max 668.07)","569.72 (min 568.21, max 570.72)","637.06 (min 636.15, max 640.19)","622.50 (min 616.08, max 631.86)"
    "vddshv6_power","30.99 (min 30.66, max 31.17)","30.84 (min 30.58, max 31.05)","40.98 (min 20.60, max 52.04)","30.87 (min 30.70, max 31.03)","30.87 (min 30.60, max 31.12)","30.92 (min 30.61, max 31.17)"
    "vdds_osc_power","1.23","1.23","1.23","1.23","1.23","1.23"
    "vdds_ddr_power","142.45 (min 141.69, max 145.01)","149.85 (min 148.87, max 151.02)","143.57 (min 141.24, max 145.56)","142.05 (min 141.89, max 142.24)","143.29 (min 142.77, max 143.60)","147.03 (min 143.58, max 151.83)"
    "vdd_mpu_power","47.24 (min 45.78, max 48.31)","54.73 (min 53.01, max 55.88)","86.85 (min 79.64, max 93.09)","47.09 (min 46.06, max 48.69)","113.22 (min 112.67, max 113.49)","88.40 (min 86.66, max 92.04)"
    "vddshv1_power","0.39 (min 0.39, max 0.40)","0.39","0.39 (min 0.38, max 0.41)","0.39 (min 0.39, max 0.40)","0.39","0.39"
    "vdds_power","2.57 (min 2.56, max 2.59)","2.56 (min 2.55, max 2.57)","2.75 (min 2.25, max 3.18)","2.55 (min 2.55, max 2.56)","2.55 (min 2.54, max 2.57)","2.56 (min 2.55, max 2.57)"
    "vdds_a3p3v_usb0_1_power","11.11 (min 11.10, max 11.11)","11.11","11.11 (min 11.10, max 11.11)","11.11","11.11","11.11"
    "vddshv2_power","9.40 (min 9.12, max 9.59)","9.40 (min 9.25, max 9.54)","19.53 (min 0.09, max 30.10)","9.42 (min 9.22, max 9.57)","9.40 (min 9.32, max 9.55)","9.32 (min 9.11, max 9.56)"
    "vdds_sram_core_bg_power","2.13 (min 2.11, max 2.15)","2.26 (min 2.25, max 2.26)","2.16 (min 2.15, max 2.17)","2.12 (min 2.11, max 2.13)","2.13 (min 2.13, max 2.14)","2.14 (min 2.13, max 2.14)"
    "vdds_sram_mpu_bb_power","2.86 (min 2.85, max 2.88)","2.99 (min 2.97, max 3.00)","3.53 (min 2.90, max 3.75)","2.87 (min 2.85, max 2.87)","4.66 (min 4.27, max 4.76)","3.78 (min 3.66, max 3.95)"
    "vdds_pll_core_lcd_power","13.15","13.15","13.16","13.15","13.15","13.15"
    "vdd_core_power","208.30 (min 207.94, max 210.32)","245.81 (min 240.23, max 249.38)","213.35 (min 209.82, max 217.58)","208.35 (min 207.92, max 209.56)","206.36 (min 205.56, max 209.00)","213.76 (min 210.99, max 216.03)"
    "vdda_adc_power","7.39 (min 7.21, max 7.47)","7.08 (min 7.00, max 7.14)","7.29 (min 6.45, max 7.54)","7.45 (min 7.43, max 7.47)","7.52 (min 7.50, max 7.57)","7.49 (min 7.48, max 7.50)"
    "vdds_pll_mpu_power","2.03","2.03","2.03","2.03","2.03","2.03"

Table: **Power Consumption with powersave governor**



.. csv-table::
    :header: "Power Rail","am335x-evm: idle (mw)","am335x-evm: 3D graphics (mw)","am335x-evm: video+audio (mw)","am335x-evm: network load (mw)","am335x-evm: Dhrystone (mw)","am335x-evm: memtester (mw)"

    "vdds_rtc_power","0.66","0.66","0.66","0.66","0.66","0.66"
    "vddshv4_power","0.08 (min 0.08, max 0.09)","0.09 (min 0.08, max 0.09)","0.08","0.08 (min 0.08, max 0.09)","0.08 (min 0.08, max 0.09)","0.08 (min 0.07, max 0.09)"
    "vdds_pll_ddr_power","3.92","3.93 (min 3.92, max 3.93)","3.93","3.93 (min 3.92, max 3.93)","3.93 (min 3.92, max 3.93)","3.92 (min 3.92, max 3.93)"
    "vdda_1p8v_usb0_1_power","32.93 (min 32.91, max 32.95)","32.96 (min 32.95, max 32.97)","32.96 (min 32.94, max 32.97)","32.97 (min 32.96, max 32.98)","32.95 (min 32.95, max 32.96)","32.97 (min 32.95, max 32.98)"
    "vddshv3_power","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15 (min 0.15, max 0.16)","0.15","0.15 (min 0.14, max 0.15)"
    "vddshv5_power","51.26 (min 51.18, max 51.61)","51.46 (min 51.20, max 52.43)","51.72 (min 51.65, max 51.77)","51.23 (min 51.23, max 51.25)","51.56 (min 51.53, max 51.58)","51.37 (min 51.36, max 51.39)"
    "total_power","571.95 (min 569.44, max 579.03)","639.97 (min 620.08, max 697.05)","1083.21 (min 934.16, max 1131.27)","570.53 (min 570.07, max 571.54)","1278.39 (min 1277.32, max 1279.52)","1008.85 (min 993.80, max 1018.70)"
    "vddshv6_power","30.92 (min 30.65, max 31.16)","30.84 (min 30.62, max 30.99)","47.86 (min 43.92, max 51.85)","30.99 (min 30.88, max 31.10)","30.88 (min 30.62, max 31.17)","30.96 (min 30.79, max 31.03)"
    "vdds_osc_power","1.23","1.23","1.23","1.23","1.23 (min 1.22, max 1.23)","1.23"
    "vdds_ddr_power","142.51 (min 142.16, max 143.22)","149.68 (min 148.65, max 151.32)","147.91 (min 146.14, max 149.08)","141.95 (min 141.52, max 142.20)","142.54 (min 142.38, max 142.60)","150.06 (min 144.91, max 157.97)"
    "vdd_mpu_power","49.11 (min 46.43, max 55.06)","70.81 (min 54.90, max 129.10)","500.60 (min 359.55, max 543.70)","47.95 (min 47.47, max 49.29)","742.12 (min 741.62, max 742.38)","457.30 (min 444.86, max 475.60)"
    "vddshv1_power","0.39 (min 0.39, max 0.40)","0.39","0.38 (min 0.38, max 0.39)","0.39","0.39 (min 0.39, max 0.40)","0.39 (min 0.38, max 0.39)"
    "vdds_power","2.55 (min 2.54, max 2.56)","2.56 (min 2.55, max 2.56)","2.96 (min 2.28, max 3.17)","2.56 (min 2.55, max 2.56)","2.56 (min 2.55, max 2.56)","2.56 (min 2.55, max 2.57)"
    "vdds_a3p3v_usb0_1_power","11.11","11.11","11.07 (min 11.06, max 11.08)","11.11 (min 11.10, max 11.11)","11.06 (min 11.05, max 11.06)","11.07 (min 11.07, max 11.08)"
    "vddshv2_power","9.41 (min 9.09, max 9.58)","9.38 (min 9.10, max 9.56)","25.99 (min 20.32, max 29.51)","9.32 (min 9.08, max 9.56)","9.29 (min 9.09, max 9.43)","9.45 (min 9.38, max 9.52)"
    "vdds_sram_core_bg_power","2.10 (min 2.10, max 2.11)","2.27 (min 2.26, max 2.29)","2.32 (min 2.25, max 2.36)","2.14 (min 2.13, max 2.16)","2.39 (min 2.36, max 2.41)","2.28 (min 2.28, max 2.29)"
    "vdds_sram_mpu_bb_power","2.87 (min 2.84, max 2.97)","3.05 (min 3.00, max 3.12)","7.07 (min 6.67, max 7.21)","2.89 (min 2.88, max 2.91)","11.74 (min 11.70, max 11.77)","6.40 (min 5.83, max 6.79)"
    "vdds_pll_core_lcd_power","13.15","13.15","13.16","13.15 (min 13.15, max 13.16)","13.16","13.16"
    "vdd_core_power","208.17 (min 207.87, max 209.45)","246.34 (min 242.72, max 251.27)","220.01 (min 208.73, max 223.81)","208.39 (min 208.21, max 208.72)","208.55 (min 208.14, max 209.88)","221.71 (min 218.26, max 224.15)"
    "vdda_adc_power","7.38 (min 7.24, max 7.53)","7.07 (min 6.94, max 7.20)","7.53 (min 7.51, max 7.57)","7.41 (min 7.34, max 7.46)","7.55 (min 7.53, max 7.57)","7.51 (min 7.49, max 7.54)"
    "vdds_pll_mpu_power","2.03","2.82 (min 2.03, max 4.33)","5.62","2.03","5.61 (min 5.61, max 5.62)","5.62"

Table: **Power Consumption with conservative governor**














    

