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
    :header: "Benchmarks","am574x-idk: perf"

    "bw_mmap_rd-mo-1mb","2043.25"
    "lat_sig-catch","11.27"
    "lat_ops-int-bit","0.67"
    "bw_mem-bzero-8mb","2780.71 (min 1553.40, max 4008.02)"
    "latency_for_0.50_mb_block_size","19.29"
    "lat_ops-double-mul","5.11"
    "lat_ops-int64-bit","1.02"
    "lat_proc-exec","1323.60"
    "lat_fs-10k","45.00"
    "bw_mem-fwr-16mb","3957.46"
    "bw_mem-bzero-1mb","3905.27 (min 3526.35, max 4284.18)"
    "bw_mem-frd-1mb","2136.16 (min 2052.33, max 2219.98)"
    "bw_mem-bcopy-1mb","3526.35"
    "bw_mem-rdwr-8mb","778.46 (min 701.75, max 855.16)"
    "lat_syscall-write","0.53"
    "select_on_200_tcp_fds","41.38"
    "bw_mem-rd-8mb","1799.44 (min 937.54, max 2661.34)"
    "lat_ops-int-add","1.01"
    "bw_mem-rd-1mb","8158.02 (min 7231.60, max 9084.43)"
    "semaphore_latency","5.19"
    "lat_syscall-read","0.62"
    "bw_mem-fwr-2mb","2958.00 (min 1680.95, max 4235.04)"
    "bw_mem-rdwr-4mb","839.53 (min 817.91, max 861.14)"
    "bw_mem-fcp-8mb","2431.13 (min 854.24, max 4008.02)"
    "bw_mem-cp-2mb","2611.27 (min 987.49, max 4235.04)"
    "bw_mem-fcp-1mb","3252.08 (min 2219.98, max 4284.18)"
    "lat_syscall-null","0.47"
    "bw_mem-wr-8mb","819.65 (min 701.75, max 937.54)"
    "bw_mem-bzero-16mb","3906.25"
    "lat_ctx-2-256k","12.99"
    "bw_mem-rd-4mb","2064.31 (min 1189.06, max 2939.56)"
    "signal_handler_latency","2.33"
    "pipe_bandwidth","159.67"
    "latency_for_1.00_mb_block_size","9.64 (min 0.00, max 19.28)"
    "lat_ops-int64-div","186.71"
    "bw_file_rd-io-1mb","407.44"
    "procedure_call","0.01"
    "bw_mem-frd-4mb","877.66 (min 846.74, max 908.57)"
    "lat_pipe","63.44"
    "lat_syscall-stat","18.04"
    "bw_mem-bzero-2mb","3439.73 (min 2658.56, max 4220.89)"
    "bw_mem-bcopy-4mb","1700.92"
    "bw_mem-fwr-8mb","2659.62 (min 1312.55, max 4006.68)"
    "lat_fs-0k","103.00"
    "bw_mem-cp-1mb","3711.95 (min 3139.72, max 4284.18)"
    "lat_mem_rd-stride128-sz62k","17.20"
    "bw_mem-fcp-4mb","2515.79 (min 846.74, max 4184.83)"
    "lat_syscall-open","348.06"
    "tcp_ip_connection_cost_to_localhost","142.92"
    "lat_tcp","0.81"
    "lat_ctx-4-128k","14.87"
    "lat_sem","5.19"
    "lat_ops-int-mul","3.16"
    "bw_pipe","159.67"
    "bw_mmap_rd-o2c-1mb","711.62"
    "lat_connect","142.92"
    "lat_mem_rd-stride128-sz50","4.01"
    "bw_mem-rdwr-1mb","3865.97 (min 3139.72, max 4592.21)"
    "bw_mem-cp-16mb","850.07"
    "lat_select","41.38"
    "bw_mem-rdwr-16mb","691.74"
    "af_unix_sock_stream_latency","78.39"
    "lat_ctx-4-256k","24.38"
    "lat_syscall-fstat","10.51"
    "bw_mem-fcp-16mb","858.83"
    "bw_unix","885.51"
    "lat_ops-float-add","1.10"
    "bw_mem-cp-4mb","2486.07 (min 861.14, max 4111.00)"
    "bw_mem-fwr-4mb","2509.79 (min 908.57, max 4111.00)"
    "bw_mem-frd-8mb","1083.40 (min 854.24, max 1312.55)"
    "pipe_latency","63.44"
    "lat_sig-install","2.33"
    "lat_unix","78.39"
    "lat_proc-proccall","0.01"
    "bw_mem-bcopy-8mb","1553.40"
    "lat_mem_rd-stride128-sz31k","9.71"
    "tcp_latency_using_localhost","0.81"
    "lat_mem_rd-stride128-sz1000k","19.28"
    "bw_mem-rd-16mb","2634.61"
    "bw_mem-rdwr-2mb","1797.29 (min 987.49, max 2607.08)"
    "lat_pagefault","1.78"
    "bw_mem-wr-2mb","4938.58 (min 2607.08, max 7270.08)"
    "bw_file_rd-o2c-1mb","339.33"
    "af_unix_socket_stream_bandwidth","885.51"
    "lat_ops-float-mul","5.04"
    "lat_fs-1k","65.00"
    "bw_mem-frd-16mb","1518.75"
    "signal_handler_overhead","11.27"
    "bw_mem-fwr-1mb","3168.26 (min 2052.33, max 4284.18)"
    "lat_fs-4k","68.00"
    "bw_mem-wr-4mb","1003.49 (min 817.91, max 1189.06)"
    "lat_ctx-2-128k","13.42"
    "bw_mem-bcopy-16mb","1558.09"
    "lat_mem_rd-stride128-sz125k","19.07"
    "bw_mem-rd-2mb","6533.07 (min 5796.05, max 7270.08)"
    "lat_mem_rd-stride128-sz500k","19.29"
    "lat_ops-double-add","1.10"
    "bw_mem-fcp-2mb","2599.76 (min 978.63, max 4220.89)"
    "bw_mem-wr-16mb","913.03"
    "lat_ops-int64-add","1.11"
    "bw_mem-bzero-4mb","2942.88 (min 1700.92, max 4184.83)"
    "bw_mem-frd-2mb","1329.79 (min 978.63, max 1680.95)"
    "lat_proc-fork","1195.80"
    "lat_sig-prot","0.67"
    "lat_ops-int-mod","13.44"
    "bw_mem-cp-8mb","2430.92 (min 855.16, max 4006.68)"
    "lat_ops-int64-mod","33.28"
    "lat_mem_rd-stride128-sz250k","19.28"
    "bw_mem-wr-1mb","6838.32 (min 4592.21, max 9084.43)"
    "lat_ops-int-div","90.61"
    "lat_mmap-1m","159.00"
    "bw_mem-bcopy-2mb","2658.56"


Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

.. csv-table::
    :header: "Benchmarks","am574x-idk: perf"

    "cpu_clock","10.00"
    "dhrystone_per_second","6250000.00"
    "dhrystone_per_mhz","355.70"


Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am574x-idk: perf"

    "whetstone","2500.00"


Table:  **Whetstone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
sloving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am574x-idk: perf"

    "linpack","696346.00"


Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am574x-idk: perf"

    "assignment","11.23"
    "idea","3003.40"
    "string_sort","93.94"
    "numeric_sort","464.98"
    "fp_emulation","112.97"
    "fourier","8404.20"
    "huffman","933.83"
    "lu_decomposition","546.86"
    "neural_net","15.20"


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
    :header: "Benchmarks","am574x-idk: perf"

    "triad","2960.80"
    "add","2840.00"
    "scale","3172.00"
    "copy","3070.70"


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
    :header: "Use Case","am574x-idk: Latency"

    "L_PERF_SHIELD_SMP_1080ENC","71.00"
    "L_PERF_SHIELD_SMP_GRAPHICS","48.00"
    "L_PERF_SHIELD_SMP_UART","45.00"
    "L_PERF_SHIELD_SMP_NO_LOAD","23.00"
    "L_PERF_SHIELD_SMP_MEM","37.00"
    "L_PERF_SHIELD_SMP_NET","70.00"
    "L_PERF_SHIELD_SMP_STRESS_LOAD","48.00"
    "L_PERF_SHIELD_SMP_HACKBENCH","50.00"


|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am574x-idk: boot time (sec)"

    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","6.62 (min 6.59, max 6.69)"
    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","19.55 (min 19.16, max 20.01)"

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

    "11025","1024418.00","0.25"
    "24000","1024418.00","0.07"
    "8000","1024418.00","0.04"
    "16000","1024418.00","0.06"
    "44100","1411775.00","1.64"
    "22050","1024418.00","0.12"
    "88200","2823547.00","3.24"
    "48000","1536626.00","0.06"
    "96000","3073248.00","0.10"
    "32000","1024418.00","0.07"

Table:  **Audio Playback**

|

Sensor Capture
-------------------------

Capture video frames (MMAP buffers) with v4l2c-ctl and record the
reported fps

.. csv-table::
    :header: "Resolution","Format","am574x-idk: Fps","am574x-idk: Sensor"

    "1600x1200","rgb4","14.56 (min 14.56, max 14.57)","ov2659"
    "320x240","rgb4","43.78 (min 43.70, max 44.00)","ov2659"
    "320x240","ba81","43.78 (min 43.70, max 44.00)","ov2659"
    "1600x1200","ba81","14.56 (min 14.56, max 14.57)","ov2659"

Table:  **Sensor Capture**

|

Display Driver
-------------------------


.. csv-table::
    :header: "Mode","am574x-idk: Fps"

    "1920x1200\@60","60.00 (min 59.82, max 60.18)"


Table:  **Display performance (LCD)**

|

|

Table:  **Display performance (DVI)**

|


.. csv-table::
    :header: "Mode","am574x-idk: Fps"

    "640x480\@60","60.00 (min 59.91, max 60.06)"
    "1400x1050\@60","59.98 (min 59.88, max 60.09)"
    "1600x1200\@65","65.00 (min 64.86, max 65.13)"
    "1152x864\@75","75.00 (min 74.79, max 75.18)"
    "1280x768\@60","59.87 (min 59.75, max 59.98)"
    "800x600\@56","56.25 (min 56.08, max 56.40)"
    "1280x1024\@75","75.02 (min 74.89, max 75.20)"
    "1280x720\@60","60.00 (min 59.72, max 60.26)"
    "1680x945\@60","60.02 (min 59.93, max 60.13)"
    "800x600\@72","72.19 (min 72.05, max 72.34)"
    "800x600\@75","75.00 (min 74.91, max 75.13)"
    "2048x1152\@60","60.00 (min 59.85, max 60.18)"
    "1280x960\@60","60.00 (min 59.94, max 60.10)"
    "848x480\@60","60.00 (min 59.92, max 60.09)"
    "1024x768\@75","75.03 (min 74.76, max 75.33)"
    "1280x800\@75","74.93 (min 74.77, max 75.11)"
    "1024x768\@70","70.07 (min 69.88, max 70.31)"
    "1920x1080\@60","60.00 (min 59.44, max 60.59)"
    "1440x900\@75","74.98 (min 74.60, max 75.25)"
    "1024x576\@60","59.97 (min 59.88, max 60.06)"
    "1600x1200\@60","60.00 (min 59.92, max 60.12)"
    "640x480\@73","72.81 (min 72.71, max 72.96)"
    "1680x1050\@60","59.95 (min 59.74, max 60.13)"
    "640x480\@75","75.00 (min 74.50, max 75.55)"
    "1600x900\@60","60.00 (min 59.89, max 60.10)"
    "1400x1050\@75","74.87 (min 74.07, max 75.64)"
    "1360x768\@60","59.95 (min 59.88, max 60.05)"
    "1280x768\@75","74.89 (min 74.54, max 75.29)"
    "1280x1024\@60","60.00 (min 59.07, max 60.12)"
    "720x400\@70","70.08 (min 69.96, max 70.19)"
    "800x600\@60","60.32 (min 60.17, max 60.39)"
    "1024x768\@60","60.00 (min 59.89, max 60.10)"
    "1280x800\@60","59.81 (min 59.70, max 59.91)"
    "832x624\@75","74.55 (min 74.33, max 74.83)"
    "1440x900\@60","59.89 (min 59.77, max 59.98)"


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

    "GLB25_EgyptTestC24Z24MS4 test","2500003.00","35.68 (min 17.03, max 60.01)"
    "GLB25_EgyptTestC24Z16_PVRTC4 test","2501101.00","39.52 (min 17.96, max 60.21)"
    "GLB25_EgyptTestC24Z16_ETC1to565 test","2501401.00","39.77 (min 18.39, max 60.29)"
    "GLB25_EgyptTestC24Z16_ETC1 test","2501001.00","39.78 (min 18.05, max 60.13)"
    "GLB25_EgyptTestC24Z16FixedTime test","2500005.00","33.01 (min 18.74, max 57.35)"
    "GLB25_EgyptTestStandard_inherited test","2000000.00","59.99 (min 59.28, max 60.25)"


Table:  **GLBenchmark 2.5 Performance**

Vertex Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmark","am574x-idk: Test Number","am574x-idk: Rate (triangles/sec)"

    "GLB25_TriangleTexTestC24Z16 test","2500301.00","89544728.00"
    "GLB25_TriangleTexVertexLitTestC24Z16 test","2500411.00","23994292.00"
    "GLB25_TriangleTexFragmentLitTestC24Z16 test","2500511.00","20104896.00"


Table:  **GLBenchmark 2.5 Vertex Throughput**

Pixel Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmark","am574x-idk: Test Number","am574x-idk: Rate (texel/sec)","am574x-idk: Fps"

    "GLB25_FillTestC24Z16 test","2500101.00","1131143808.00","45.95 (min 43.28, max 47.21)"


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
    :header: "TCP Window Size (KBytes)","am574x-idk: Throughput (Mbits/sec)","am574x-idk: CPU Load "

    "16","347.20",""
    "32","440.80",""
    "64","566.40",""
    "128","631.20",""
    "8","137.76",""
    "256","783.52",""

Table: **TCP Throughput No Interrupt Pacing**

.. rubric::  TCP Throughput Interrupt Pacing
   :name: tcp-throughput-interrupt-pacing

.. csv-table::
    :header: "TCP Window Size (KBytes)","am574x-idk: Throughput (Mbits/sec)","am574x-idk: CPU Load "

    "8","272.80",""
    "32","467.20",""
    "64","443.20",""
    "256","605.60",""
    "16","337.60",""

Table: **TCP Throughput Interrupt Pacing**

UDP Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^


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


Table: **PCI Ethernet**

NAND Driver
-------------------------










QSPI Flash Driver
-------------------------



AM574x-IDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am574x-idk: Write UBIFS Throughput (Mbytes/sec)","am574x-idk: Write UBIFS CPU Load (%)","am574x-idk: Read UBIFS Throughput (Mbytes/sec)","am574x-idk: Read UBIFS CPU Load (%)"

    "262144","0.27 (min 0.24, max 0.29)","74.47 (min 73.55, max 75.75)","15.23","20.00"
    "102400","0.31 (min 0.26, max 0.49)","73.70 (min 72.03, max 75.26)","15.15","20.00"
    "1048576","0.27 (min 0.24, max 0.29)","73.90 (min 73.04, max 74.94)","14.94","20.00"
    "524288","0.27 (min 0.24, max 0.29)","73.50 (min 71.95, max 75.24)","15.00","12.50"



















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

    "262144","29.44 (min 26.72, max 30.92)","15.20 (min 13.08, max 21.19)","65.41","21.79"
    "102400","29.61 (min 26.64, max 30.77)","16.13 (min 13.49, max 21.87)","63.13","19.28"
    "1048576","29.21 (min 27.46, max 30.89)","15.87 (min 12.14, max 24.05)","76.15","25.91"
    "524288","29.30 (min 26.16, max 30.77)","15.48 (min 13.04, max 20.33)","76.96","25.19"
    "5242880","29.73 (min 27.40, max 30.92)","15.53 (min 12.28, max 23.38)","76.36","25.56"

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
























AM574x-IDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^


|



.. csv-table::
    :header: "Buffer size (bytes)","am574x-idk: Write EXT2 Throughput (Mbytes/sec)","am574x-idk: Write EXT2 CPU Load (%)","am574x-idk: Read EXT2 Throughput (Mbytes/sec)","am574x-idk: Read EXT2 CPU Load (%)"

    "262144","31.97 (min 19.47, max 37.01)","14.75 (min 11.20, max 19.57)","80.67","29.07"
    "102400","24.53 (min 12.69, max 34.23)","12.21 (min 4.88, max 15.31)","72.65","28.27"
    "1048576","29.87 (min 19.91, max 34.66)","15.04 (min 12.66, max 20.73)","82.95","29.69"
    "524288","28.07 (min 19.42, max 33.15)","13.95 (min 10.18, max 19.83)","83.26","29.53"
    "5242880","25.20 (min 19.40, max 30.25)","12.52 (min 8.98, max 19.12)","83.49","32.31"

|



.. csv-table::
    :header: "Buffer size (bytes)","am574x-idk: Write EXT4 Throughput (Mbytes/sec)","am574x-idk: Write EXT4 CPU Load (%)","am574x-idk: Read EXT4 Throughput (Mbytes/sec)","am574x-idk: Read EXT4 CPU Load (%)"

    "262144","25.93 (min 15.02, max 35.41)","14.34 (min 9.28, max 16.92)","81.23","28.63"
    "102400","12.86 (min 11.09, max 15.09)","7.02 (min 5.11, max 12.56)","72.10","29.79"
    "1048576","26.94 (min 14.82, max 34.71)","13.64 (min 7.03, max 15.98)","85.86","29.22"
    "524288","26.54 (min 14.37, max 34.92)","13.10 (min 7.57, max 15.23)","85.56","29.84"
    "5242880","25.46 (min 15.35, max 35.49)","13.02 (min 6.65, max 15.44)","85.81","28.87"

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
    :header: "Algorithm","Buffer Size","am574x-idk: throughput"

    "sha1","1024","5767.51"
    "des-cbc","16","91.17"
    "aes-192-cbc","8192","22413.31"
    "aes-256-cbc","8192","23098.71"
    "sha1","8192","31640.23"
    "aes-256-cbc","64","5323.73"
    "sha1","64","1543.34"
    "sha1","16","395.19"
    "aes-128-cbc","8192","22642.69"
    "md5","256","1755.90"
    "aes-192-cbc","64","5464.92"
    "aes-192-cbc","16","1518.29"
    "aes-256-cbc","1024","7472.13"
    "des3","64","493.70"
    "des3","1024","4396.37"
    "des-cbc","64","373.31"
    "md5","64","1608.96"
    "sha1","256","1733.38"
    "aes-192-cbc","256","2233.09"
    "md5","16","407.50"
    "des-cbc","256","1604.86"
    "des-cbc","1024","4607.32"
    "aes-128-cbc","256","2066.60"
    "aes-256-cbc","16","1498.72"
    "md5","8192","32074.41"
    "aes-128-cbc","1024","5846.36"
    "aes-192-cbc","1024","6672.38"
    "aes-128-cbc","16","1533.38"
    "des-cbc","8192","13085.35"
    "des3","8192","12815.02"
    "des3","256","1838.34"
    "aes-256-cbc","256","2214.83"
    "des3","16","91.16"
    "aes-128-cbc","64","5599.57"
    "md5","1024","5906.43"


|
|

.. csv-table::
    :header: "Algorithm","am574x-idk: CPU Load"

    "des3","20.00"
    "sha1","71.00"
    "aes-256-cbc","50.00"
    "md5","72.00"
    "des-cbc","22.00"
    "aes-192-cbc","51.00"
    "aes-128-cbc","52.00"



|
| Listed for each algorithm are the code snippets used to run each
  benchmark test.

|

::

    time -v openssl speed -elapsed -evp aes-128-cbc


IPSec Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Note: queue\_len is set to 300 and software fallback threshold set to 9
to enable software support for optimal performance






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
