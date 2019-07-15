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
  
**Latency**: lat_mem_rd-stride128-szN, where N is equal to or smaller than the cache
size at given level measures the cache miss penalty. N that is at least
double the size of last level cache is the latency to external memory.

**Bandwidth**: bw_mem_bcopy-N, where N is is equal to or smaller than the cache size at
a given level measures the achivable memory bandwidth from software doing
a memcpy() type operation. Typical use is for external memory bandwidth
calculation. The bandwidth is calculated as byte read and written counts
as 1 which should be roughly half of STREAM copy result.

.. csv-table::
    :header: "Benchmarks","am574x-idk: perf"

    "af_unix_sock_stream_latency (microsec)","71.72"
    "af_unix_socket_stream_bandwidth (MBs)","853.60"
    "bw_file_rd-io-1mb (MB/s)","428.94"
    "bw_file_rd-o2c-1mb (MB/s)","352.67"
    "bw_mem-bcopy-16mb (MB/s)","1553.25"
    "bw_mem-bcopy-1mb (MB/s)","3499.56"
    "bw_mem-bcopy-2mb (MB/s)","2502.68"
    "bw_mem-bcopy-4mb (MB/s)","1683.27"
    "bw_mem-bcopy-8mb (MB/s)","1571.40"
    "bw_mem-bzero-16mb (MB/s)","3943.31"
    "bw_mem-bzero-1mb (MB/s)","3905.34 (min 3499.56, max 4311.12)"
    "bw_mem-bzero-2mb (MB/s)","3390.17 (min 2502.68, max 4277.66)"
    "bw_mem-bzero-4mb (MB/s)","2909.18 (min 1683.27, max 4135.08)"
    "bw_mem-bzero-8mb (MB/s)","2787.70 (min 1571.40, max 4004.00)"
    "bw_mem-cp-16mb (MB/s)","850.07"
    "bw_mem-cp-1mb (MB/s)","3817.39 (min 3241.80, max 4392.97)"
    "bw_mem-cp-2mb (MB/s)","2634.22 (min 1017.64, max 4250.80)"
    "bw_mem-cp-4mb (MB/s)","2449.30 (min 867.02, max 4031.58)"
    "bw_mem-cp-8mb (MB/s)","2402.11 (min 850.34, max 3953.87)"
    "bw_mem-fcp-16mb (MB/s)","899.18"
    "bw_mem-fcp-1mb (MB/s)","3338.46 (min 2365.79, max 4311.12)"
    "bw_mem-fcp-2mb (MB/s)","2634.45 (min 991.24, max 4277.66)"
    "bw_mem-fcp-4mb (MB/s)","2483.69 (min 832.29, max 4135.08)"
    "bw_mem-fcp-8mb (MB/s)","2452.30 (min 900.60, max 4004.00)"
    "bw_mem-frd-16mb (MB/s)","879.12"
    "bw_mem-frd-1mb (MB/s)","2209.42 (min 2053.04, max 2365.79)"
    "bw_mem-frd-2mb (MB/s)","1332.44 (min 991.24, max 1673.64)"
    "bw_mem-frd-4mb (MB/s)","921.77 (min 832.29, max 1011.25)"
    "bw_mem-frd-8mb (MB/s)","896.08 (min 891.56, max 900.60)"
    "bw_mem-fwr-16mb (MB/s)","3937.01"
    "bw_mem-fwr-1mb (MB/s)","3223.01 (min 2053.04, max 4392.97)"
    "bw_mem-fwr-2mb (MB/s)","2962.22 (min 1673.64, max 4250.80)"
    "bw_mem-fwr-4mb (MB/s)","2521.42 (min 1011.25, max 4031.58)"
    "bw_mem-fwr-8mb (MB/s)","2422.72 (min 891.56, max 3953.87)"
    "bw_mem-rd-16mb (MB/s)","2635.48"
    "bw_mem-rd-1mb (MB/s)","8082.24 (min 7257.45, max 8907.03)"
    "bw_mem-rd-2mb (MB/s)","6512.61 (min 5887.45, max 7137.76)"
    "bw_mem-rd-4mb (MB/s)","2067.24 (min 1201.38, max 2933.09)"
    "bw_mem-rd-8mb (MB/s)","1809.06 (min 949.67, max 2668.45)"
    "bw_mem-rdwr-16mb (MB/s)","897.41"
    "bw_mem-rdwr-1mb (MB/s)","4130.66 (min 3241.80, max 5019.52)"
    "bw_mem-rdwr-2mb (MB/s)","2146.97 (min 1017.64, max 3276.30)"
    "bw_mem-rdwr-4mb (MB/s)","971.29 (min 867.02, max 1075.56)"
    "bw_mem-rdwr-8mb (MB/s)","884.15 (min 850.34, max 917.96)"
    "bw_mem-wr-16mb (MB/s)","923.95"
    "bw_mem-wr-1mb (MB/s)","6963.28 (min 5019.52, max 8907.03)"
    "bw_mem-wr-2mb (MB/s)","5207.03 (min 3276.30, max 7137.76)"
    "bw_mem-wr-4mb (MB/s)","1138.47 (min 1075.56, max 1201.38)"
    "bw_mem-wr-8mb (MB/s)","933.82 (min 917.96, max 949.67)"
    "bw_mmap_rd-mo-1mb (MB/s)","2739.23"
    "bw_mmap_rd-o2c-1mb (MB/s)","787.25"
    "bw_pipe (MB/s)","154.29"
    "bw_unix (MB/s)","853.60"
    "lat_connect (us)","147.41"
    "lat_ctx-2-128k (us)","4.79"
    "lat_ctx-2-256k (us)","4.00"
    "lat_ctx-4-128k (us)","8.07"
    "lat_ctx-4-256k (us)","0.00"
    "lat_fs-0k (num_files)","108.00"
    "lat_fs-10k (num_files)","45.00"
    "lat_fs-1k (num_files)","58.00"
    "lat_fs-4k (num_files)","67.00"
    "lat_mem_rd-stride128-sz1000k (ns)","19.28"
    "lat_mem_rd-stride128-sz125k (ns)","19.06"
    "lat_mem_rd-stride128-sz250k (ns)","19.28"
    "lat_mem_rd-stride128-sz31k (ns)","11.60"
    "lat_mem_rd-stride128-sz50 (ns)","4.01"
    "lat_mem_rd-stride128-sz500k (ns)","19.28"
    "lat_mem_rd-stride128-sz62k (ns)","17.21"
    "lat_mmap-1m (us)","181.00"
    "lat_ops-double-add (ns)","1.10"
    "lat_ops-double-mul (ns)","5.05"
    "lat_ops-float-add (ns)","1.09"
    "lat_ops-float-mul (ns)","5.06"
    "lat_ops-int-add (ns)","1.01"
    "lat_ops-int-bit (ns)","0.67"
    "lat_ops-int-div (ns)","88.42"
    "lat_ops-int-mod (ns)","15.46"
    "lat_ops-int-mul (ns)","3.17"
    "lat_ops-int64-add (ns)","1.11"
    "lat_ops-int64-bit (ns)","1.03"
    "lat_ops-int64-div (ns)","189.42"
    "lat_ops-int64-mod (ns)","34.40"
    "lat_pagefault (us)","1.80"
    "lat_pipe (us)","58.43"
    "lat_proc-exec (us)","2135.00"
    "lat_proc-fork (us)","2061.67"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","42.01"
    "lat_sem (us)","4.30"
    "lat_sig-catch (us)","12.29"
    "lat_sig-install (us)","2.30"
    "lat_sig-prot (us)","0.39"
    "lat_syscall-fstat (us)","10.22"
    "lat_syscall-null (us)","0.46"
    "lat_syscall-open (us)","315.88"
    "lat_syscall-read (us)","0.72"
    "lat_syscall-stat (us)","18.28"
    "lat_syscall-write (us)","0.57"
    "lat_tcp (us)","0.88"
    "lat_unix (us)","71.72"
    "latency_for_0.50_mb_block_size (nanosec)","19.28"
    "latency_for_1.00_mb_block_size (nanosec)","9.64 (min 0.00, max 19.28)"
    "pipe_bandwidth (MBs)","154.29"
    "pipe_latency (microsec)","58.43"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","42.01"
    "semaphore_latency (microsec)","4.30"
    "signal_handler_latency (microsec)","2.30"
    "signal_handler_overhead (microsec)","12.29"
    "tcp_ip_connection_cost_to_localhost (microsec)","147.41"
    "tcp_latency_using_localhost (microsec)","0.88"


Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

.. csv-table::
    :header: "Benchmarks","am574x-idk: perf","am654x-idk: perf"

    "cpu_clock (MHz)","10.00","400.00"
    "dhrystone_per_mhz (DMIPS/MHz)","334.80","6.10"
    "dhrystone_per_second (DhrystoneP)","5882353.00","4255319.00"


Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am574x-idk: perf","am654x-idk: perf"

    "whetstone (MIPS)","3333.30","3333.30"


Table:  **Whetstone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
sloving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am574x-idk: perf","am654x-idk: perf"

    "linpack (Kflops)","652601.00","330033.00"


Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am574x-idk: perf","am654x-idk: perf"

    "assignment (Iterations)","13.36","7.71"
    "fourier (Iterations)","12524.00","8091.60"
    "fp_emulation (Iterations)","61.64","61.39"
    "huffman (Iterations)","902.98","672.13"
    "idea (Iterations)","2862.00","1915.70"
    "lu_decomposition (Iterations)","548.50","313.34"
    "neural_net (Iterations)","15.40","4.21"
    "numeric_sort (Iterations)","509.03","297.96"
    "string_sort (Iterations)","93.87","94.48"


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
    :header: "Benchmarks","am574x-idk: perf","am654x-idk: perf"

    "add (MB/s)","2932.50","1588.20"
    "copy (MB/s)","3127.10","1841.30"
    "scale (MB/s)","3118.80","1806.60"
    "triad (MB/s)","2900.20","1493.90"


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
    :header: "Use Case","am574x-idk: Latency","am654x-idk: Latency"

    "L_PERF_SHIELD_SMP_1080ENC","59.00"
    "L_PERF_SHIELD_SMP_GRAPHICS","46.00"
    "L_PERF_SHIELD_SMP_HACKBENCH","47.00","64.00"
    "L_PERF_SHIELD_SMP_MEM","56.00","64.00"
    "L_PERF_SHIELD_SMP_NET","29.00","90.00"
    "L_PERF_SHIELD_SMP_NO_LOAD","27.00","25.00"
    "L_PERF_SHIELD_SMP_STRESS_LOAD","46.00","92.00"
    "L_PERF_SHIELD_SMP_UART","71.00","45.00"
    "L_PERF_SHIELD_SMP_USB","72.00","80.00"


|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am574x-idk: boot time (sec)","am654x-idk: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","21.60 (min 21.56, max 21.66)","14.30 (min 13.89, max 15.05)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","7.64 (min 7.59, max 7.69)","5.02"

Table:  **Boot time MMC/SD**

Boot media: NAND
^^^^^^^^^^^^^^^^^^^^^^^^^^^


Table:  **Boot time NAND**


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

    "8000","1024418.00","0.04"
    "11025","1024418.00","0.04"
    "16000","1024417.00","37.89"
    "22050","1024418.00","0.01"
    "24000","1024418.00","0.03"
    "32000","1024418.00","0.02"
    "44100","1411775.00","1.62"
    "48000","1536626.00","0.06"
    "88200","2823548.00","3.63"
    "96000","3073248.00","0.02"

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


Table:  **Display performance (LCD)**

|

|

Table:  **Display performance (DVI)**

|


.. csv-table::
    :header: "Mode","am574x-idk: Fps"

    "1024x576\@60","59.97 (min 59.75, max 60.13)"
    "1024x768\@60","60.00 (min 59.86, max 60.13)"
    "1024x768\@70","70.07 (min 69.93, max 70.27)"
    "1024x768\@75","75.01 (min 73.88, max 75.51)"
    "1152x864\@75","74.98 (min 73.82, max 75.61)"
    "1280x1024\@60","60.02 (min 59.89, max 60.17)"
    "1280x1024\@75","75.01 (min 73.96, max 75.25)"
    "1280x720\@60","60.00 (min 59.85, max 60.11)"
    "1280x768\@60","59.87 (min 59.73, max 60.03)"
    "1280x768\@75","74.89 (min 74.37, max 75.28)"
    "1280x800\@60","59.81 (min 59.69, max 59.96)"
    "1280x800\@75","74.93 (min 74.69, max 75.16)"
    "1280x960\@60","60.00 (min 59.80, max 60.14)"
    "1360x768\@60","59.95 (min 59.82, max 60.08)"
    "1400x1050\@60","59.98 (min 59.77, max 60.24)"
    "1400x1050\@75","74.86 (min 74.64, max 75.08)"
    "1440x900\@60","59.89 (min 59.72, max 60.01)"
    "1440x900\@75","74.97 (min 73.62, max 75.20)"
    "1600x1200\@60","60.00 (min 59.58, max 60.38)"
    "1600x1200\@65","65.00 (min 64.82, max 65.24)"
    "1600x1200\@70","70.00 (min 69.77, max 70.20)"
    "1600x900\@60","60.00 (min 59.84, max 60.18)"
    "1680x1050\@60","59.95 (min 59.80, max 60.10)"
    "1680x1050\@75","74.89 (min 74.31, max 75.56)"
    "1680x945\@60","60.02 (min 59.89, max 60.16)"
    "1920x1080\@60","60.00 (min 59.85, max 60.19)"
    "2048x1152\@60","60.00 (min 59.91, max 60.11)"
    "640x480\@60","60.00 (min 59.90, max 60.11)"
    "640x480\@73","72.81 (min 72.68, max 72.99)"
    "640x480\@75","75.00 (min 74.81, max 75.19)"
    "720x400\@70","70.08 (min 69.91, max 70.24)"
    "800x600\@56","56.25 (min 56.15, max 56.36)"
    "800x600\@60","60.32 (min 60.23, max 60.43)"
    "800x600\@72","72.17 (min 70.91, max 72.37)"
    "800x600\@75","75.00 (min 74.75, max 75.20)"
    "832x624\@75","74.53 (min 73.20, max 74.76)"
    "848x480\@60","59.98 (min 58.95, max 60.10)"


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

    "GLB25_EgyptTestC24Z16FixedTime test","2500005.00","30.12 (min 17.40, max 57.91)"
    "GLB25_EgyptTestC24Z16_ETC1 test","2501001.00","36.35 (min 16.66, max 60.02)"
    "GLB25_EgyptTestC24Z16_ETC1to565 test","2501401.00","36.37 (min 16.58, max 60.03)"
    "GLB25_EgyptTestC24Z16_PVRTC4 test","2501101.00","36.06 (min 16.55, max 60.04)"
    "GLB25_EgyptTestC24Z24MS4 test","2500003.00","32.47 (min 15.48, max 60.01)"
    "GLB25_EgyptTestStandard_inherited test","2000000.00","59.98 (min 57.40, max 60.38)"


Table:  **GLBenchmark 2.5 Performance**

Vertex Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmark","am574x-idk: Test Number","am574x-idk: Rate (triangles/sec)"

    "GLB25_TriangleTexFragmentLitTestC24Z16 test","2500511.00","17594072.00"
    "GLB25_TriangleTexTestC24Z16 test","2500301.00","85689760.00"
    "GLB25_TriangleTexVertexLitTestC24Z16 test","2500411.00","20664184.00"


Table:  **GLBenchmark 2.5 Vertex Throughput**

Pixel Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmark","am574x-idk: Test Number","am574x-idk: Rate (texel/sec)","am574x-idk: Fps"

    "GLB25_FillTestC24Z16 test","2500101.00","1064894592.00","43.38 (min 42.29, max 44.00)"


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

    "1080p","59.00","",""
    "720p","59940.00","",""
    "CIF","90000.00","",""

Table:  **Gstreamer H264 in AVI Container Decode Performance**

|

MPEG4
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Resolution","am574x-idk: Fps","am574x-idk: IVA Freq (MHz)","am574x-idk: IPU Freq (MHz)"

    "CIF","30.00","",""
    "QVGA","30.00","",""


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

    "8","501.04","82.41 (min 81.87, max 82.80)","592.80",""
    "16","600.00","77.73 (min 76.09, max 78.87)","813.60",""
    "32","662.40","88.58 (min 84.97, max 89.31)"
    "64","785.60","94.93 (min 90.75, max 96.38)","1170.40",""
    "128","572.00","73.89 (min 61.80, max 87.49)","1056.00",""
    "256","492.80","70.34 (min 63.61, max 82.85)","1051.20",""

Table: **TCP Throughput No Interrupt Pacing**


.. csv-table::
    :header: "TCP Window Size (KBytes)","am574x-idk: Throughput (Mbits/sec)","am574x-idk: CPU Load ","am654x-idk: Throughput (Mbits/sec)","am654x-idk: CPU Load "

    "8","487.20","90.86 (min 86.44, max 92.48)","0.00",""
    "16","596.80","76.61 (min 73.43, max 77.58)","0.00",""
    "32","657.60","89.85 (min 87.50, max 91.39)","0.00",""
    "64","711.20","88.65 (min 65.47, max 98.46)","0.00",""
    "128","668.80","81.01 (min 70.36, max 93.39)","0.00",""
    "256","535.20","70.61 (min 67.96, max 75.32)","0.00",""

Table: **TCP Throughput Interrupt Pacing**


UDP Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "UDP Packet Size(bytes)","am574x-idk: Throughput (Mbits/sec)","am574x-idk: CPU Load ","am574x-idk: Packets Per Second (kpps) ","am654x-idk: Throughput (Mbits/sec)","am654x-idk: CPU Load ","am654x-idk: Packets Per Second (kpps) "

    "64","15.30","85.50","29.00"
    "128","31.10","87.90","30.00"
    "256","65.80","86.00","31.00"
    "1024","235.00","81.00","28.00","935.00","72.90","114.00"
    "1470","341.00","81.40","28.00"
    "1500","204.50","81.80","17.00"

Table: **UDP Throughput Egress**


.. csv-table::
    :header: "UDP Packet Size(bytes)","am574x-idk: Throughput (Mbits/sec)","am574x-idk: CPU Load ","am574x-idk: Packets Per Second (kpps) ","am654x-idk: Throughput (Mbits/sec)","am654x-idk: CPU Load ","am654x-idk: Packets Per Second (kpps) "

    "64","37.20","97.70","72.00","45.50","48.60","87.00"
    "128","78.10","98.80","76.00","91.00","49.40","88.00"
    "256","77.10","98.30","37.00","182.10","49.70","88.00"
    "512","306.00","98.00","74.00","344.00","49.00","83.00"
    "1024","311.00","97.00","37.00","744.00","50.60","90.00"
    "1470","856.00","99.40","72.00","956.00","48.30","81.00"
    "1500","296.00","84.30","24.00","250.00","35.60","20.00"

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
    "256","0.00"

Table: **PCI Ethernet**

NAND Driver
-------------------------










QSPI Flash Driver
-------------------------



AM574x-IDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am574x-idk: Write UBIFS Throughput (Mbytes/sec)","am574x-idk: Write UBIFS CPU Load (%)","am574x-idk: Read UBIFS Throughput (Mbytes/sec)","am574x-idk: Read UBIFS CPU Load (%)"

    "102400","0.29 (min 0.25, max 0.43)","58.87 (min 58.33, max 59.57)","15.51","26.92"
    "262144","0.25 (min 0.23, max 0.27)","59.64 (min 59.17, max 60.45)","14.74","13.04"
    "524288","0.25 (min 0.23, max 0.27)","59.34 (min 58.31, max 60.17)","15.33","24.00"
    "1048576","0.25 (min 0.23, max 0.27)","59.29 (min 58.46, max 60.30)","14.41","27.59"






AM654X-IDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write UBIFS Throughput (Mbytes/sec)","am654x-idk: Write UBIFS CPU Load (%)","am654x-idk: Read UBIFS Throughput (Mbytes/sec)","am654x-idk: Read UBIFS CPU Load (%)"

    "102400","0.65 (min 0.51, max 1.16)","25.13 (min 25.08, max 25.15)","42.82","11.11"
    "262144","0.49 (min 0.37, max 0.55)","25.17 (min 25.09, max 25.27)","36.12","25.00"
    "524288","0.49 (min 0.37, max 0.55)","25.17 (min 25.10, max 25.24)","41.38","15.79"
    "1048576","0.49 (min 0.37, max 0.55)","25.12 (min 25.08, max 25.17)","35.11","28.00"

















SPI Flash Driver
-------------------------




EMMC Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

|















AM574x-IDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^


|





.. csv-table::
    :header: "Buffer size (bytes)","am574x-idk: Write EXT4 Throughput (Mbytes/sec)","am574x-idk: Write EXT4 CPU Load (%)","am574x-idk: Read EXT4 Throughput (Mbytes/sec)","am574x-idk: Read EXT4 CPU Load (%)"

    "102400","32.03 (min 28.53, max 33.56)","16.23 (min 13.64, max 24.90)","64.80","17.47"
    "262144","32.02 (min 28.57, max 33.55)","16.69 (min 13.58, max 24.73)","65.52","24.29"
    "524288","31.54 (min 28.21, max 32.83)","15.75 (min 12.95, max 24.39)","68.67","23.26"
    "1048576","31.85 (min 28.54, max 32.87)","16.36 (min 13.85, max 24.69)","77.51","26.12"
    "5242880","31.94 (min 28.53, max 33.73)","16.25 (min 13.49, max 24.45)","77.72","26.77"

|










AM654x-IDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write VFAT Throughput (Mbytes/sec)","am654x-idk: Write VFAT CPU Load (%)","am654x-idk: Read VFAT Throughput (Mbytes/sec)","am654x-idk: Read VFAT CPU Load (%)"

    "102400","33.54 (min 25.53, max 35.66)","6.72 (min 5.54, max 11.07)","131.55","13.49"
    "262144","33.66 (min 25.55, max 35.72)","6.66 (min 5.22, max 11.09)","133.29","18.06"
    "524288","33.90 (min 25.62, max 36.10)","6.73 (min 5.41, max 11.38)","143.47","19.11"
    "1048576","33.88 (min 25.68, max 35.98)","6.93 (min 5.75, max 11.31)","159.20","19.62"
    "5242880","33.72 (min 25.64, max 35.81)","6.80 (min 5.38, max 11.51)","158.60","19.38"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write EXT2 Throughput (Mbytes/sec)","am654x-idk: Write EXT2 CPU Load (%)","am654x-idk: Read EXT2 Throughput (Mbytes/sec)","am654x-idk: Read EXT2 CPU Load (%)"

    "102400","34.06 (min 30.30, max 35.04)","4.75 (min 3.94, max 7.27)","136.62","15.18"
    "262144","34.09 (min 30.07, max 35.18)","4.63 (min 3.79, max 7.34)","142.90","18.09"
    "524288","34.05 (min 30.45, max 35.17)","4.84 (min 3.92, max 7.64)","157.72","16.92"
    "1048576","34.37 (min 29.95, max 37.00)","4.86 (min 3.99, max 7.24)","167.69","17.55"
    "5242880","34.03 (min 30.16, max 35.28)","4.77 (min 3.82, max 7.35)","166.98","17.89"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write EXT4 Throughput (Mbytes/sec)","am654x-idk: Write EXT4 CPU Load (%)","am654x-idk: Read EXT4 Throughput (Mbytes/sec)","am654x-idk: Read EXT4 CPU Load (%)"

    "102400","33.83 (min 29.30, max 35.03)","5.70 (min 4.61, max 8.65)","120.50","14.04"
    "262144","34.37 (min 29.63, max 35.65)","6.31 (min 5.38, max 9.28)","145.57","16.67"
    "524288","34.40 (min 29.64, max 35.71)","6.09 (min 5.15, max 8.52)","162.79","18.04"
    "1048576","34.57 (min 29.75, max 36.56)","5.96 (min 4.94, max 8.62)","177.33","19.15"
    "5242880","34.23 (min 29.67, max 35.74)","6.42 (min 5.31, max 8.68)","176.06","19.23"

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

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

| 
























AM574x-IDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^


|





.. csv-table::
    :header: "Buffer size (bytes)","am574x-idk: Write EXT4 Throughput (Mbytes/sec)","am574x-idk: Write EXT4 CPU Load (%)","am574x-idk: Read EXT4 Throughput (Mbytes/sec)","am574x-idk: Read EXT4 CPU Load (%)"

    "102400","17.24 (min 16.39, max 17.98)","8.79 (min 6.51, max 14.53)","19.20","6.60"
    "262144","17.52 (min 15.68, max 18.64)","8.39 (min 6.41, max 13.32)","22.19","8.98"
    "524288","18.41 (min 16.86, max 19.10)","9.73 (min 7.75, max 15.69)","22.64","7.61"
    "1048576","18.62 (min 17.45, max 19.09)","9.59 (min 7.07, max 15.18)","22.83","7.65"
    "5242880","18.20 (min 17.57, max 18.75)","9.80 (min 7.81, max 15.47)","22.80","8.05"

|




AM654x-IDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write VFAT Throughput (Mbytes/sec)","am654x-idk: Write VFAT CPU Load (%)","am654x-idk: Read VFAT Throughput (Mbytes/sec)","am654x-idk: Read VFAT CPU Load (%)"

    "102400","16.14 (min 13.70, max 17.15)","3.42 (min 2.54, max 6.46)","22.16","3.14"
    "262144","15.42 (min 12.71, max 16.92)","3.18 (min 2.26, max 5.99)","22.03","3.07"
    "524288","15.92 (min 13.58, max 16.99)","3.33 (min 2.36, max 6.37)","22.66","2.83"
    "1048576","14.70 (min 10.04, max 16.76)","2.97 (min 2.23, max 4.82)","23.15","3.16"
    "5242880","14.75 (min 11.62, max 16.67)","3.03 (min 2.08, max 5.59)","23.12","3.10"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write EXT2 Throughput (Mbytes/sec)","am654x-idk: Write EXT2 CPU Load (%)","am654x-idk: Read EXT2 Throughput (Mbytes/sec)","am654x-idk: Read EXT2 CPU Load (%)"

    "102400","16.47 (min 15.75, max 17.02)","2.43 (min 1.95, max 3.91)","22.54","2.65"
    "262144","16.18 (min 14.21, max 17.06)","2.36 (min 1.80, max 3.81)","22.83","2.74"
    "524288","16.31 (min 14.93, max 17.10)","2.28 (min 1.80, max 3.70)","23.42","2.52"
    "1048576","16.74 (min 15.79, max 17.02)","2.41 (min 1.99, max 3.77)","23.57","2.43"
    "5242880","16.67 (min 15.21, max 17.12)","2.30 (min 1.91, max 3.67)","23.55","2.65"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write EXT4 Throughput (Mbytes/sec)","am654x-idk: Write EXT4 CPU Load (%)","am654x-idk: Read EXT4 Throughput (Mbytes/sec)","am654x-idk: Read EXT4 CPU Load (%)"

    "102400","17.76 (min 16.95, max 18.73)","3.07 (min 2.44, max 5.07)","22.70","2.72"
    "262144","17.64 (min 16.28, max 18.01)","3.27 (min 2.71, max 5.06)","23.02","3.13"
    "524288","17.47 (min 16.13, max 17.84)","3.30 (min 2.69, max 5.13)","23.55","2.43"
    "1048576","17.67 (min 16.30, max 18.09)","3.26 (min 2.71, max 5.14)","23.76","2.50"
    "5242880","17.52 (min 16.19, max 17.88)","3.24 (min 2.73, max 4.99)","23.73","2.50"

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

**Setup** : Inateck ASM1153E USB hard disk is
connected to usb0 port. File read/write performance data on usb0 port is
captured.

|


Table: **USB Host VFAT**

.. csv-table::
    :header: "Buffer size (bytes)","am574x-idk: Write VFAT Throughput (Mbytes/sec)","am574x-idk: Write VFAT CPU Load (%)","am574x-idk: Read VFAT Throughput (Mbytes/sec)","am574x-idk: Read VFAT CPU Load (%)","am654x-idk: Write VFAT Throughput (Mbytes/sec)","am654x-idk: Write VFAT CPU Load (%)","am654x-idk: Read VFAT Throughput (Mbytes/sec)","am654x-idk: Read VFAT CPU Load (%)"

    "102400","149.17 (min 48.59, max 175.54)","62.97 (min 52.91, max 65.55)","153.52","57.58","33.55 (min 25.24, max 35.89)","7.89 (min 6.52, max 12.18)","37.40","6.97"
    "262144","148.26 (min 48.55, max 174.32)","64.45 (min 53.36, max 68.33)","145.23","49.65","33.71 (min 25.62, max 36.08)","7.50 (min 6.10, max 11.63)","38.32","6.80"




Table: **USB Host EXT2**

.. csv-table::
    :header: "Buffer size (bytes)","am574x-idk: Write EXT2 Throughput (Mbytes/sec)","am574x-idk: Write EXT2 CPU Load (%)","am574x-idk: Read EXT2 Throughput (Mbytes/sec)","am574x-idk: Read EXT2 CPU Load (%)","am654x-idk: Write EXT2 Throughput (Mbytes/sec)","am654x-idk: Write EXT2 CPU Load (%)","am654x-idk: Read EXT2 Throughput (Mbytes/sec)","am654x-idk: Read EXT2 CPU Load (%)"

    "102400","164.01 (min 57.10, max 192.05)","66.80 (min 55.07, max 71.43)","140.31","50.34","35.83 (min 30.97, max 37.07)","6.33 (min 5.53, max 8.87)","37.10","6.51"
    "1048576","164.76 (min 57.13, max 194.96)","67.22 (min 54.92, max 71.43)","172.09","54.62","35.78 (min 31.19, max 37.12)","6.42 (min 5.69, max 8.41)","38.43","7.18"
    "5242880","165.08 (min 56.84, max 195.60)","66.21 (min 53.53, max 70.09)","155.11","49.63","35.51 (min 30.97, max 36.66)","7.17 (min 6.47, max 9.45)","37.35","5.81"






CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. csv-table::
    :header: "Algorithm","Buffer Size","am574x-idk: throughput","am654x-idk: throughput"

    "aes-128-cbc","1024","6653.61","26869.42"
    "aes-128-cbc","16","1513.75","2592.11"
    "aes-128-cbc","256","1899.61","18538.15"
    "aes-128-cbc","64","5380.86","8279.02"
    "aes-128-cbc","8192","22929.41","30471.51"
    "aes-192-cbc","1024","6677.50","23590.91"
    "aes-192-cbc","16","1498.73","2655.23"
    "aes-192-cbc","256","1922.39","17146.37"
    "aes-192-cbc","64","5344.90","8186.52"
    "aes-192-cbc","8192","22978.56","26195.29"
    "aes-256-cbc","1024","7761.24","21001.90"
    "aes-256-cbc","16","1465.11","2551.90"
    "aes-256-cbc","256","2287.02","15567.02"
    "aes-256-cbc","64","5105.00","7723.75"
    "aes-256-cbc","8192","24524.12","23076.86"
    "des-cbc","1024","5114.88","14333.95"
    "des-cbc","16","115.02","2561.71"
    "des-cbc","256","1664.34","11749.80"
    "des-cbc","64","450.18","6837.25"
    "des-cbc","8192","13197.31","15196.16"
    "des3","1024","5665.79","5956.95"
    "des3","16","134.68","1999.38"
    "des3","256","1924.18","5445.29"
    "des3","64","526.44","4050.11"
    "des3","8192","12894.21","6111.23"
    "md5","1024","6002.35","28482.56"
    "md5","16","413.42","614.84"
    "md5","256","1920.00","8951.81"
    "md5","64","1640.30","2391.85"
    "md5","8192","31823.19","74282.33"
    "sha1","1024","5961.05","26507.95"
    "sha1","16","397.79","589.46"
    "sha1","256","1929.64","8511.06"
    "sha1","64","1556.76","2290.11"
    "sha1","8192","31629.31","65743.53"


|
|

.. csv-table::
    :header: "Algorithm","am574x-idk: CPU Load","am654x-idk: CPU Load"

    "aes-128-cbc","52.00","99.00"
    "aes-192-cbc","52.00","99.00"
    "aes-256-cbc","50.00","99.00"
    "des-cbc","20.00","99.00"
    "des3","16.00","99.00"
    "md5","72.00","99.00"
    "sha1","72.00","99.00"



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



PRU Ethernet
^^^^^^^^^^^^


Table: ** PRU UDP Throughput Egress**



Table: **PRU UDP Throughput Ingress**


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
    
   

