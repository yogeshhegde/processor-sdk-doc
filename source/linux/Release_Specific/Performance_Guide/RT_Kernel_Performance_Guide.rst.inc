..  http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_RT_Kernel_Performance_Guide

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
| AM572x IDK     | AM57xx Evaluation Module rev A2 with ARM running at 1500MHz, DDR3L-533 (533 MHz/1066 MT/S), TMDXIDK5278        |
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
-------------------------

LMBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^

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

.. csv-table::
    :header: "Benchmarks","am574x-idk: perf"

    "cpu_clock","10.00"
    "dhrystone_per_second","6250000.00"
    "dhrystone_per_mhz","355.70"


Table:  **Dhrystone Benchmark**

Whestone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am574x-idk: perf"

    "whetstone","2500.00"


Table:  **Whestone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^

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

   :name: mpeg2
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

   :name: tcp-throughput

.. csv-table::
    :header: "TCP Window Size (KBytes)","am574x-idk: Throughput (Mbits/sec)","am574x-idk: CPU Load "

    "16","347.20",""
    "32","440.80",""
    "64","566.40",""
    "128","631.20",""
    "8","137.76",""
    "256","783.52",""

Table: **TCP Throughput**

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


UDP Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

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

AM574x-IDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am574x-idk: Write UBIFS Throughput (Mbytes/sec)","am574x-idk: Write UBIFS CPU Load (%)","am574x-idk: Read UBIFS Throughput (Mbytes/sec)","am574x-idk: Read UBIFS CPU Load (%)"

    "262144","0.27 (min 0.24, max 0.29)","74.47 (min 73.55, max 75.75)","15.23","20.00"
    "102400","0.31 (min 0.26, max 0.49)","73.70 (min 72.03, max 75.26)","15.15","20.00"
    "1048576","0.27 (min 0.24, max 0.29)","73.90 (min 73.04, max 74.94)","14.94","20.00"
    "524288","0.27 (min 0.24, max 0.29)","73.50 (min 71.95, max 75.24)","15.00","12.50"







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


