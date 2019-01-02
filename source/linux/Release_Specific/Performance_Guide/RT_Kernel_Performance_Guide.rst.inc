..  http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_RT_Kernel_Performance_Guide

.. rubric::  **Read This First**
   :name: read-this-first

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+---------------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                         |
+================+=====================================================================================================================+
| AM335x         | AM335x Evaluation Module rev 1.5B with ARM running at 1000MHz, DDR3-400 (400MHz/800 MT/S), TMDXEVM3358              |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| AM437x-gpevm   | AM437x-gpevm Evaluation Module rev 1.5A with ARM running at 1000MHz, DDR3-400 (400MHz/800 MT/S), TMDSEVM437X        |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| AM572x IDK     | AM57xx Evaluation Module rev A2 with ARM running at 1500MHz, DDR3L-533 (533 MHz/1066 MT/S), TMDXIDK5278             |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| AM574x IDK     | AM57xx Industrial Development Kit rev 1.0A  with ARM running at 1500MHz, DDR3L-533 (533 MHz/1066 MT/S), TMDXIDK5278 |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| K2HK EVM       | K2 Hawkings Evaluation Module rev 40 with ARM running at 1200MHz, DDR3-1600 (800 MHz/1600 MT/S), EVMK2H             |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| K2G EVM        | K2 Galileo Evaluation Module rev C, DDR3-1333 (666 MHz/1333 MT/S), EVMK2G                                           |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| AM65x EVM      | AM65x Evaluation Module rev 1.0 with ARM running at 800MHz, DDR4-2400 (1333 MT/S), TMDX654GPEVM                     |
+----------------+---------------------------------------------------------------------------------------------------------------------+


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
-------------------------

LMBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
LMBench is a collection of microbenchmarks of which the memory bandwidth 
and latency related ones are typically used to estimate processor 
memory system performance.
  
  Latency    
  lat_mem_rd-stride128-szN , where N is equal to or smaller than the cache 
  size at given level measures the cache miss penalty. N that is at least
  double the size of last level cache is the latency to external memory.
  
  Bandwidth
  bw_mem_bcopy-N , where N is is equal to or smaller than the cache size at
  a given level measures the achivable memory bandwidth from software doing
  a memcpy() type operation. Typical use is for external memory bandwidth
  calculation. The bandwidth is calculated as byte read and written counts
  as 1 which should be roughly half of STREAM copy result.

.. csv-table::
    :header: "Benchmarks","am654x-idk: perf"

    "bw_mmap_rd-mo-1mb","1449.80"
    "lat_sig-catch","11.00"
    "lat_ops-int-bit","0.84"
    "bw_mem-bzero-8mb","2595.85 (min 972.29, max 4219.41)"
    "latency_for_0.50_mb_block_size","10.59"
    "lat_ops-double-mul","5.04"
    "lat_ops-int64-bit","0.84"
    "lat_proc-exec","1390.00"
    "lat_fs-10k","69.00"
    "bw_mem-fwr-16mb","4180.82"
    "bw_mem-bzero-1mb","2713.72 (min 1107.01, max 4320.43)"
    "bw_mem-frd-1mb","1323.76 (min 1104.57, max 1542.95)"
    "bw_mem-bcopy-1mb","1107.01"
    "bw_mem-rdwr-8mb","749.46 (min 498.54, max 1000.38)"
    "lat_syscall-write","0.66"
    "select_on_200_tcp_fds","48.72"
    "bw_mem-rd-8mb","1131.14 (min 1035.46, max 1226.81)"
    "lat_ops-int-add","1.26"
    "bw_mem-rd-1mb","1394.82 (min 1296.54, max 1493.09)"
    "semaphore_latency","6.49"
    "lat_syscall-read","1.00"
    "bw_mem-fwr-2mb","2822.72 (min 1330.45, max 4314.99)"
    "bw_mem-rdwr-4mb","762.06 (min 501.76, max 1022.36)"
    "bw_mem-fcp-8mb","2614.69 (min 1009.97, max 4219.41)"
    "bw_mem-cp-2mb","2410.76 (min 506.52, max 4314.99)"
    "bw_mem-fcp-1mb","2712.50 (min 1104.57, max 4320.43)"
    "lat_syscall-null","0.48"
    "bw_mem-wr-8mb","1017.92 (min 1000.38, max 1035.46)"
    "bw_mem-bzero-16mb","4218.30"
    "lat_ctx-2-256k","29.52"
    "bw_mem-rd-4mb","1163.32 (min 1075.85, max 1250.78)"
    "signal_handler_latency","1.52"
    "pipe_bandwidth","592.21"
    "latency_for_1.00_mb_block_size","20.76 (min 0.00, max 41.51)"
    "lat_ops-int64-div","11.97"
    "bw_file_rd-io-1mb","983.48"
    "procedure_call","0.01"
    "bw_mem-frd-4mb","1134.27 (min 1013.43, max 1255.10)"
    "lat_pipe","28.06"
    "lat_syscall-stat","11.87"
    "bw_mem-bzero-2mb","2644.00 (min 1002.84, max 4285.16)"
    "bw_mem-bcopy-4mb","973.71"
    "bw_mem-fwr-8mb","2706.65 (min 1236.48, max 4176.82)"
    "lat_fs-0k","163.00"
    "bw_mem-cp-1mb","2525.98 (min 551.67, max 4500.28)"
    "lat_mem_rd-stride128-sz62k","8.05"
    "bw_mem-fcp-4mb","2624.24 (min 1013.43, max 4235.04)"
    "lat_syscall-open","237.61"
    "tcp_ip_connection_cost_to_localhost","88.94"
    "lat_tcp","0.77"
    "lat_ctx-4-128k","20.18"
    "lat_sem","6.49"
    "lat_ops-int-mul","3.83"
    "bw_pipe","592.21"
    "bw_mmap_rd-o2c-1mb","727.40"
    "lat_connect","88.94"
    "lat_mem_rd-stride128-sz50","3.77"
    "bw_mem-rdwr-1mb","887.94 (min 551.67, max 1224.20)"
    "bw_mem-cp-16mb","500.70"
    "lat_select","48.72"
    "bw_mem-rdwr-16mb","985.10"
    "af_unix_sock_stream_latency","55.43"
    "lat_ctx-4-256k","121.29"
    "lat_syscall-fstat","6.24"
    "bw_mem-fcp-16mb","1011.57"
    "bw_unix","1089.45"
    "lat_ops-float-add","0.92"
    "bw_mem-cp-4mb","2326.29 (min 501.76, max 4150.81)"
    "bw_mem-fwr-4mb","2702.96 (min 1255.10, max 4150.81)"
    "bw_mem-frd-8mb","1123.23 (min 1009.97, max 1236.48)"
    "pipe_latency","28.06"
    "lat_sig-install","1.52"
    "lat_unix","55.43"
    "lat_proc-proccall","0.01"
    "bw_mem-bcopy-8mb","972.29"
    "lat_mem_rd-stride128-sz31k","3.80"
    "tcp_latency_using_localhost","0.77"
    "lat_mem_rd-stride128-sz1000k","41.51"
    "bw_mem-rd-16mb","1214.24"
    "bw_mem-rdwr-2mb","838.29 (min 506.52, max 1170.05)"
    "lat_pagefault","3.74"
    "bw_mem-wr-2mb","1192.19 (min 1170.05, max 1214.33)"
    "bw_file_rd-o2c-1mb","636.54"
    "af_unix_socket_stream_bandwidth","1089.45"
    "lat_ops-float-mul","5.05"
    "lat_fs-1k","71.00"
    "bw_mem-frd-16mb","1246.98"
    "signal_handler_overhead","11.00"
    "bw_mem-fwr-1mb","3021.62 (min 1542.95, max 4500.28)"
    "lat_fs-4k","72.00"
    "bw_mem-wr-4mb","1049.11 (min 1022.36, max 1075.85)"
    "lat_ctx-2-128k","9.61"
    "bw_mem-bcopy-16mb","972.05"
    "lat_mem_rd-stride128-sz125k","9.49"
    "bw_mem-rd-2mb","1272.28 (min 1214.33, max 1330.23)"
    "lat_mem_rd-stride128-sz500k","10.59"
    "lat_ops-double-add","0.92"
    "bw_mem-fcp-2mb","2649.77 (min 1014.37, max 4285.16)"
    "bw_mem-wr-16mb","1042.96"
    "lat_ops-int64-add","1.26"
    "bw_mem-bzero-4mb","2604.38 (min 973.71, max 4235.04)"
    "bw_mem-frd-2mb","1172.41 (min 1014.37, max 1330.45)"
    "lat_proc-fork","1330.25"
    "lat_sig-prot","0.72"
    "lat_ops-int-mod","7.97"
    "bw_mem-cp-8mb","2337.68 (min 498.54, max 4176.82)"
    "lat_ops-int64-mod","9.26"
    "lat_mem_rd-stride128-sz250k","10.14"
    "bw_mem-wr-1mb","1260.37 (min 1224.20, max 1296.54)"
    "lat_ops-int-div","7.58"
    "lat_mmap-1m","34.00"
    "bw_mem-bcopy-2mb","1002.84"


Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

.. csv-table::
    :header: "Benchmarks","am654x-idk: perf"

    "cpu_clock","400.00"
    "dhrystone_per_second","4166666.80"
    "dhrystone_per_mhz","5.90"


Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am654x-idk: perf"

    "whetstone","2500.00"


Table:  **Whetstone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
sloving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am654x-idk: perf"

    "linpack","331579.00"


Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am654x-idk: perf"

    "assignment","8.41"
    "idea","1953.30"
    "string_sort","94.71"
    "numeric_sort","449.97"
    "fp_emulation","62.36"
    "fourier","6806.50"
    "huffman","636.71"
    "lu_decomposition","320.18"
    "neural_net","4.31"


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
    :header: "Benchmarks","am654x-idk: perf"

    "triad","1618.90"
    "add","1754.90"
    "scale","2217.50"
    "copy","2132.60"


Table:  **Stream**

Maximum Latency under different use cases
------------------------------------------

Shield (dedicated core) Case
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
| The following tests measure worst-case latency under different
  scenarios or use cases.
| Cyclictest application was used to measured latency. Each test ran for
  4 hours.
| Two cgroups were used using shield\_shell procedure shown below.
| The application running the use case and cyclictest ran on a dedicated
  cpu (rt) while the rest of threads ran on nonrt cpu.

::

    shield_shell()
    {
    create_cgroup nonrt 0
    create_cgroup rt 1
    for pid in $(cat /sys/fs/cgroup/tasks); do /bin/echo $pid > /sys/fs/cgroup/nonrt/tasks; done
    /bin/echo $$ > /sys/fs/cgroup/rt/tasks
    }

|

.. csv-table::
    :header: "Use Case","am654x-idk: Latency"

    "L_PERF_SHIELD_SMP_USB","92.00"
    "L_PERF_SHIELD_SMP_HACKBENCH","58.00"
    "L_PERF_SHIELD_SMP_UART","78.00"
    "L_PERF_SHIELD_SMP_NO_LOAD","25.00"
    "L_PERF_SHIELD_SMP_MEM","56.00"
    "L_PERF_SHIELD_SMP_USB_NET","102.00"
    "L_PERF_SHIELD_SMP_NET","45.00"
    "L_PERF_SHIELD_SMP_STRESS_LOAD","78.00"


|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am574x-idk: boot time (sec)","am654x-idk: boot time (sec)"

    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","7.02 (min 6.98, max 7.08)","5.96 (min 5.63, max 6.70)"
    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","28.58 (min 28.25, max 29.34)","16.66 (min 16.31, max 17.40)"

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


Table:  **Audio Capture**

|

.. csv-table::
    :header: "Sampling Rate (Hz)","am574x-idk: Throughput (bits/sec)","am574x-idk: CPU Load (%)"

    "11025","1024418.00","0.15"
    "24000","1024418.00","0.05"
    "8000","1024418.00","0.06"
    "16000","1024418.00","0.04"
    "44100","1411776.00","1.62"
    "22050","1024418.00","0.04"
    "88200","2823548.00","3.29"
    "48000","1536626.00","0.08"
    "96000","3073247.00","0.00"
    "32000","1024418.00","0.06"

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


.. csv-table::
    :header: "Mode","am574x-idk: Fps"

    "1920x1200\@60","60.00 (min 59.90, max 60.12)"


Table:  **Display performance (LCD)**

|

|

Table:  **Display performance (DVI)**

|


.. csv-table::
    :header: "Mode","am574x-idk: Fps"

    "640x480\@60","60.00 (min 59.94, max 60.08)"
    "1680x1050\@75","74.89 (min 74.71, max 75.07)"
    "1400x1050\@60","59.98 (min 59.91, max 60.09)"
    "1600x1200\@65","65.00 (min 64.90, max 65.18)"
    "1152x864\@75","75.00 (min 74.91, max 75.10)"
    "1280x768\@60","59.87 (min 59.79, max 59.98)"
    "800x600\@56","56.25 (min 56.21, max 56.29)"
    "1280x1024\@75","75.02 (min 74.60, max 75.49)"
    "1280x720\@60","60.00 (min 59.93, max 60.09)"
    "1680x945\@60","60.02 (min 59.97, max 60.09)"
    "800x600\@72","72.19 (min 72.02, max 72.34)"
    "800x600\@75","75.00 (min 74.87, max 75.10)"
    "2048x1152\@60","60.00 (min 59.83, max 60.14)"
    "1280x960\@60","60.00 (min 59.95, max 60.09)"
    "848x480\@60","60.00 (min 59.94, max 60.09)"
    "1024x768\@75","75.03 (min 74.86, max 75.20)"
    "1280x800\@75","74.93 (min 74.83, max 75.05)"
    "1024x768\@70","70.07 (min 69.88, max 70.23)"
    "1920x1080\@60","60.00 (min 59.87, max 60.11)"
    "1440x900\@75","74.98 (min 74.86, max 75.21)"
    "1024x576\@60","59.97 (min 59.91, max 60.04)"
    "1600x1200\@60","60.00 (min 59.88, max 60.13)"
    "640x480\@73","72.81 (min 72.69, max 72.95)"
    "1680x1050\@60","59.95 (min 59.85, max 60.09)"
    "640x480\@75","75.00 (min 74.83, max 75.12)"
    "1600x900\@60","60.00 (min 59.95, max 60.06)"
    "1400x1050\@75","74.87 (min 74.74, max 75.07)"
    "1360x768\@60","59.95 (min 59.82, max 60.10)"
    "1280x768\@75","74.89 (min 74.73, max 75.10)"
    "1600x1200\@70","70.00 (min 69.86, max 70.14)"
    "1280x1024\@60","60.02 (min 59.71, max 60.35)"
    "720x400\@70","70.08 (min 70.00, max 70.17)"
    "800x600\@60","60.32 (min 60.24, max 60.38)"
    "1024x768\@60","60.00 (min 59.93, max 60.10)"
    "1280x800\@60","59.81 (min 59.70, max 59.92)"
    "832x624\@75","74.53 (min 73.27, max 74.71)"
    "1440x900\@60","59.89 (min 59.82, max 59.98)"


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
    :header: "Benchmark","am574x-idk: Test Number","am574x-idk: Fps"

    "GLB25_EgyptTestC24Z24MS4 test","2500003.00","35.71 (min 17.01, max 60.02)"
    "GLB25_EgyptTestC24Z16_PVRTC4 test","2501101.00","39.53 (min 17.92, max 60.25)"
    "GLB25_EgyptTestC24Z16_ETC1to565 test","2501401.00","39.79 (min 18.23, max 60.01)"
    "GLB25_EgyptTestC24Z16_ETC1 test","2501001.00","39.80 (min 18.29, max 60.08)"
    "GLB25_EgyptTestC24Z16FixedTime test","2500005.00","32.74 (min 18.40, max 55.16)"
    "GLB25_EgyptTestStandard_inherited test","2000000.00","59.98 (min 58.33, max 60.33)"


Table:  **GLBenchmark 2.5 Performance**

Vertex Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmark","am574x-idk: Test Number","am574x-idk: Rate (triangles/sec)"

    "GLB25_TriangleTexTestC24Z16 test","2500301.00","89539992.00"
    "GLB25_TriangleTexVertexLitTestC24Z16 test","2500411.00","23976830.00"
    "GLB25_TriangleTexFragmentLitTestC24Z16 test","2500511.00","20109784.00"


Table:  **GLBenchmark 2.5 Vertex Throughput**

Pixel Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmark","am574x-idk: Test Number","am574x-idk: Rate (texel/sec)","am574x-idk: Fps"

    "GLB25_FillTestC24Z16 test","2500101.00","1126236416.00","45.79 (min 41.31, max 47.00)"


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
    :header: "Resolution","am574x-idk: Fps","am574x-idk: IVA Freq (MHz)","am574x-idk: IPU Freq (MHz)"

    "720p","59940.00","",""
    "1080p","60.00","",""
    "CIF","90000.00","",""

Table:  **Gstreamer H264 in AVI Container Decode Performance**

|

MPEG4
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Resolution","am574x-idk: Fps","am574x-idk: IVA Freq (MHz)","am574x-idk: IPU Freq (MHz)"

    "QVGA","30.00","",""
    "CIF","30.00","",""


Table:  **GStreamer MPEG4 in 3GP Container Decode Performance**

|

MPEG2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Resolution","am574x-idk: Fps","am574x-idk: IVA Freq (MHz)","am574x-idk: IPU Freq (MHz)"

    "720p","29.97","",""


Table:  **GStreamer MPEG2 in MP4 Container Decode Performance**

|

|
Ethernet Driver
-------------------------

TCP Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "TCP Window Size (KBytes)","am574x-idk: Throughput (Mbits/sec)","am574x-idk: CPU Load ","am654x-idk: Throughput (Mbits/sec)","am654x-idk: CPU Load "

    "16","139.60","55.74 (min 53.81, max 58.70)","407.20","67.28 (min 65.21, max 71.13)"
    "32","352.80","91.28 (min 86.89, max 94.97)","487.20","69.84 (min 66.06, max 72.03)"
    "64","584.80","89.06 (min 84.92, max 94.09)","608.80","50.06 (min 39.40, max 69.79)"
    "128","668.80","92.15 (min 87.27, max 95.00)","641.60","41.38 (min 41.16, max 41.56)"
    "8","254.40","84.25 (min 82.94, max 85.74)","367.20","66.65 (min 65.63, max 67.49)"
    "256","171.20","68.34 (min 66.45, max 71.26)","650.40","41.37 (min 40.44, max 42.01)"

Table: **TCP Throughput No Interrupt Pacing**


.. csv-table::
    :header: "TCP Window Size (KBytes)","am574x-idk: Throughput (Mbits/sec)","am574x-idk: CPU Load "

    "16","388.80","93.60 (min 90.38, max 95.02)"
    "32","472.00","91.34 (min 90.71, max 92.62)"
    "64","577.60","86.15 (min 82.38, max 94.97)"
    "128","631.20","90.24 (min 88.57, max 94.68)"
    "8","273.60","83.64 (min 81.98, max 84.39)"
    "256","647.20","92.60 (min 89.11, max 95.01)"

Table: **TCP Throughput Interrupt Pacing**


UDP Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "UDP Packet Size(bytes)","am574x-idk: Throughput (Mbits/sec)","am574x-idk: CPU Load ","am574x-idk: Packets Per Second (kpps) ","am654x-idk: Throughput (Mbits/sec)","am654x-idk: CPU Load ","am654x-idk: Packets Per Second (kpps) "

    "1024","178.30","75.60","21.00","426.00","64.30","52.00"
    "1500","79.60","30.50","6.00","344.00","53.60","28.00"
    "1470","85.60","27.70","7.00","547.00","59.40","46.00"
    "64","13.40","84.70","25.00"
    "128","26.80","81.60","25.00"
    "512","115.70","82.00","28.00"
    "256","58.10","84.50","28.00"

Table: **UDP Throughput Egress**


.. csv-table::
    :header: "UDP Packet Size(bytes)","am574x-idk: Throughput (Mbits/sec)","am574x-idk: CPU Load ","am574x-idk: Packets Per Second (kpps) ","am654x-idk: Throughput (Mbits/sec)","am654x-idk: CPU Load ","am654x-idk: Packets Per Second (kpps) "

    "1024","622.00","99.20","75.00","434.00","36.10","52.00"
    "256","149.50","99.30","72.00"
    "1500","92.10","40.80","7.00"
    "1470","95.30","31.50","8.00"
    "64","38.20","99.10","74.00","25.60","43.70","48.00"
    "128","78.80","99.30","76.00"
    "512","331.00","99.90","80.00","207.00","46.50","50.00"
    "8000","95.60","25.30","1.00"

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
    :header: "TCP Window Size(Kbytes)","am654x-idk: Bandwidth (Mbits/sec)"

    "128","0.00"

Table: **PCI Ethernet**

NAND Driver
-------------------------










QSPI Flash Driver
-------------------------



AM574x-IDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am574x-idk: Write UBIFS Throughput (Mbytes/sec)","am574x-idk: Write UBIFS CPU Load (%)","am574x-idk: Read UBIFS Throughput (Mbytes/sec)","am574x-idk: Read UBIFS CPU Load (%)"

    "262144","0.27 (min 0.25, max 0.29)","73.44 (min 71.65, max 75.55)","15.44","17.39"
    "102400","0.32 (min 0.27, max 0.50)","74.41 (min 73.07, max 75.27)","15.49","13.64"
    "1048576","0.27 (min 0.24, max 0.30)","73.35 (min 72.00, max 75.22)","14.94","31.03"
    "524288","0.27 (min 0.25, max 0.29)","73.16 (min 70.14, max 75.19)","15.32","29.63"






AM654X-IDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write UBIFS Throughput (Mbytes/sec)","am654x-idk: Write UBIFS CPU Load (%)","am654x-idk: Read UBIFS Throughput (Mbytes/sec)","am654x-idk: Read UBIFS CPU Load (%)"

    "262144","0.45 (min 0.36, max 0.51)","25.06 (min 25.05, max 25.10)","43.53","27.27"
    "102400","0.77 (min 0.47, max 1.29)","25.05 (min 24.92, max 25.10)","43.47","28.57"
    "1048576","0.49 (min 0.35, max 0.73)","25.09 (min 25.02, max 25.15)","43.14","28.57"
    "524288","0.45 (min 0.36, max 0.51)","25.08 (min 24.96, max 25.23)","43.37","28.57"

















SPI Flash Driver
-------------------------




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















AM574x-IDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^


|





.. csv-table::
    :header: "Buffer size (bytes)","am574x-idk: Write EXT4 Throughput (Mbytes/sec)","am574x-idk: Write EXT4 CPU Load (%)","am574x-idk: Read EXT4 Throughput (Mbytes/sec)","am574x-idk: Read EXT4 CPU Load (%)"

    "262144","28.89 (min 27.09, max 31.43)","15.78 (min 12.59, max 24.83)","67.37","25.24"
    "102400","29.41 (min 27.35, max 30.74)","15.92 (min 13.37, max 24.51)","58.69","23.96"
    "1048576","26.51 (min 17.29, max 29.93)","15.00 (min 8.96, max 25.98)","77.44","25.56"
    "524288","28.98 (min 28.37, max 29.90)","16.25 (min 13.13, max 25.24)","74.51","26.67"
    "5242880","28.17 (min 27.85, max 28.60)","15.65 (min 12.57, max 23.93)","76.97","25.47"

|










AM654x-IDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write VFAT Throughput (Mbytes/sec)","am654x-idk: Write VFAT CPU Load (%)","am654x-idk: Read VFAT Throughput (Mbytes/sec)","am654x-idk: Read VFAT CPU Load (%)"

    "262144","35.94 (min 29.64, max 37.63)","6.31 (min 3.15, max 8.56)","138.54","18.77"
    "102400","35.45 (min 28.77, max 37.27)","5.69 (min 3.79, max 9.42)","130.89","12.69"
    "1048576","35.73 (min 29.44, max 37.39)","4.14 (min 3.02, max 7.94)","160.74","11.63"
    "524288","36.16 (min 29.94, max 37.80)","6.05 (min 3.34, max 9.99)","153.07","22.83"
    "5242880","35.90 (min 29.76, max 37.67)","4.36 (min 3.12, max 7.68)","159.89","11.58"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write EXT2 Throughput (Mbytes/sec)","am654x-idk: Write EXT2 CPU Load (%)","am654x-idk: Read EXT2 Throughput (Mbytes/sec)","am654x-idk: Read EXT2 CPU Load (%)"

    "262144","36.70 (min 34.59, max 37.36)","2.26 (min 1.68, max 3.72)","144.94","10.42"
    "102400","36.80 (min 34.99, max 37.35)","3.40 (min 1.88, max 4.50)","136.02","9.60"
    "1048576","36.84 (min 34.65, max 37.58)","2.16 (min 1.71, max 3.48)","171.26","10.33"
    "524288","36.58 (min 33.94, max 37.30)","2.51 (min 1.95, max 4.19)","162.05","11.20"
    "5242880","36.84 (min 34.39, max 37.59)","2.36 (min 1.70, max 3.61)","170.98","10.61"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write EXT4 Throughput (Mbytes/sec)","am654x-idk: Write EXT4 CPU Load (%)","am654x-idk: Read EXT4 Throughput (Mbytes/sec)","am654x-idk: Read EXT4 CPU Load (%)"

    "262144","37.53 (min 33.24, max 38.78)","3.97 (min 2.30, max 8.04)","147.44","10.28"
    "102400","36.92 (min 34.97, max 38.13)","4.31 (min 2.40, max 7.45)","120.36","9.54"
    "1048576","38.46 (min 36.64, max 38.93)","5.19 (min 2.14, max 10.62)","178.16","15.45"
    "524288","38.21 (min 36.49, max 38.84)","3.41 (min 2.13, max 5.00)","167.38","8.57"
    "5242880","38.49 (min 36.56, max 38.99)","9.69 (min 2.60, max 30.62)","178.55","11.54"

|



































SATA Driver
-------------------------

























|

|

|

-  Filesize used is : 1G
-  SATA II Harddisk used is: Seagate ST3500514NS 500G


mSATA Driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^







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






























AM654x-IDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write VFAT Throughput (Mbytes/sec)","am654x-idk: Write VFAT CPU Load (%)","am654x-idk: Read VFAT Throughput (Mbytes/sec)","am654x-idk: Read VFAT CPU Load (%)"

    "262144","16.63 (min 14.91, max 17.21)","2.74 (min 1.58, max 4.61)","22.40","2.04"
    "102400","16.48 (min 14.55, max 17.11)","2.12 (min 1.50, max 4.41)","22.20","2.90"
    "1048576","16.65 (min 15.03, max 17.23)","2.59 (min 1.54, max 5.16)","23.05","1.98"
    "524288","16.56 (min 14.81, max 17.05)","2.32 (min 1.46, max 4.14)","22.85","1.86"
    "5242880","16.64 (min 14.99, max 17.21)","1.99 (min 1.30, max 4.43)","23.04","2.74"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write EXT2 Throughput (Mbytes/sec)","am654x-idk: Write EXT2 CPU Load (%)","am654x-idk: Read EXT2 Throughput (Mbytes/sec)","am654x-idk: Read EXT2 CPU Load (%)"

    "262144","17.13 (min 16.62, max 17.33)","4.62 (min 0.87, max 15.49)","22.90","2.71"
    "102400","17.18 (min 16.60, max 17.45)","2.26 (min 0.95, max 3.61)","22.57","2.31"
    "1048576","17.18 (min 16.62, max 17.37)","1.38 (min 0.87, max 2.24)","23.61","3.27"
    "524288","17.09 (min 16.58, max 17.31)","1.30 (min 0.94, max 2.21)","23.43","1.84"
    "5242880","17.15 (min 16.51, max 17.45)","3.09 (min 0.99, max 6.05)","23.60","1.63"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write EXT4 Throughput (Mbytes/sec)","am654x-idk: Write EXT4 CPU Load (%)","am654x-idk: Read EXT4 Throughput (Mbytes/sec)","am654x-idk: Read EXT4 CPU Load (%)"

    "262144","19.08 (min 18.53, max 19.24)","1.32 (min 1.01, max 1.95)","23.03","1.81"
    "102400","18.29 (min 17.29, max 19.18)","2.97 (min 1.46, max 5.31)","22.69","2.73"
    "1048576","18.95 (min 18.50, max 19.09)","1.48 (min 1.00, max 3.06)","23.77","1.36"
    "524288","18.99 (min 18.53, max 19.15)","1.64 (min 1.18, max 1.95)","23.58","1.46"
    "5242880","18.96 (min 18.47, max 19.14)","1.90 (min 1.05, max 3.29)","23.76","1.48"

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








CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. csv-table::
    :header: "Algorithm","Buffer Size","am574x-idk: throughput","am654x-idk: throughput"

    "sha1","1024","5891.75","174402.45"
    "des-cbc","16","135.17","36068.94"
    "aes-192-cbc","8192","21176.32","22650880.00"
    "aes-256-cbc","8192","22713.69","7373346.13"
    "sha1","8192","32339.29","1739639.47"
    "aes-256-cbc","64","5276.44","54412.80"
    "sha1","64","1574.63","10252.62"
    "sha1","16","399.53","2643.84"
    "aes-128-cbc","8192","23344.47","11402035.20"
    "md5","256","1747.54","46231.89"
    "aes-192-cbc","64","5479.04","53781.76"
    "aes-192-cbc","16","1563.93","16837.20"
    "aes-256-cbc","1024","6902.44","2038374.40"
    "des3","64","499.29","58685.44"
    "des3","1024","5640.19","1077657.60"
    "des-cbc","64","374.66","135207.60"
    "md5","64","1635.99","11506.61"
    "sha1","256","1725.35","45819.59"
    "aes-192-cbc","256","1547.78","266054.40"
    "md5","16","415.72","2758.67"
    "des-cbc","256","1499.82","451977.60"
    "des-cbc","1024","4491.26","2174976.00"
    "aes-128-cbc","256","1949.95","376891.73"
    "aes-256-cbc","16","1512.92","11312.53"
    "md5","8192","32808.96","1374566.40"
    "aes-128-cbc","1024","5945.34","663364.27"
    "aes-192-cbc","1024","5293.40","1353489.07"
    "aes-128-cbc","16","1644.83","23654.40"
    "des-cbc","8192","13118.12",""
    "des3","8192","12872.36","8924364.80"
    "des3","256","1909.08","300019.20"
    "aes-256-cbc","256","2258.18","213432.32"
    "des3","16","123.81","25531.20"
    "aes-128-cbc","64","5872.00","67308.80"
    "md5","1024","6014.98","182339.54"


|
|

.. csv-table::
    :header: "Algorithm","am574x-idk: CPU Load","am654x-idk: CPU Load"

    "des3","17.00","44.00"
    "sha1","72.00","99.00"
    "aes-256-cbc","51.00","53.00"
    "md5","71.00","99.00"
    "des-cbc","20.00","99.00"
    "aes-192-cbc","54.00","52.00"
    "aes-128-cbc","52.00","52.00"



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
    :header: "Algorithm","am654x-idk: Throughput","am654x-idk: Packets/Sec","am654x-idk: CPU Load"

    "aes128","176.80","15.00","60.80"





DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.


Power Management
-----------------

Power Measurements
^^^^^^^^^^^^^^^^^^^

.. warning::

  Active power is slightly higher on this release
  because PRUSS is enabled by default. Customers not using PRUSS are
  advised to disable it to reduce power consumption.
    

