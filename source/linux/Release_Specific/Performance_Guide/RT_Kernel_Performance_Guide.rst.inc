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

    "af_unix_sock_stream_latency (microsec)","72.29"
    "af_unix_socket_stream_bandwidth (MBs)","868.00"
    "bw_file_rd-io-1mb (MB/s)","677.51"
    "bw_file_rd-o2c-1mb (MB/s)","524.75"
    "bw_mem-bcopy-16mb (MB/s)","1561.43"
    "bw_mem-bcopy-1mb (MB/s)","3548.75"
    "bw_mem-bcopy-2mb (MB/s)","2547.31"
    "bw_mem-bcopy-4mb (MB/s)","1691.57"
    "bw_mem-bcopy-8mb (MB/s)","1570.78"
    "bw_mem-bzero-16mb (MB/s)","3954.03"
    "bw_mem-bzero-1mb (MB/s)","3998.97 (min 3548.75, max 4449.19)"
    "bw_mem-bzero-2mb (MB/s)","3453.04 (min 2547.31, max 4358.76)"
    "bw_mem-bzero-4mb (MB/s)","2938.20 (min 1691.57, max 4184.83)"
    "bw_mem-bzero-8mb (MB/s)","2789.07 (min 1570.78, max 4007.35)"
    "bw_mem-cp-16mb (MB/s)","847.10"
    "bw_mem-cp-1mb (MB/s)","3681.64 (min 3043.63, max 4319.65)"
    "bw_mem-cp-2mb (MB/s)","2603.96 (min 944.29, max 4263.63)"
    "bw_mem-cp-4mb (MB/s)","2492.25 (min 858.65, max 4125.84)"
    "bw_mem-cp-8mb (MB/s)","2429.62 (min 851.88, max 4007.35)"
    "bw_mem-fcp-16mb (MB/s)","927.54"
    "bw_mem-fcp-1mb (MB/s)","3336.66 (min 2224.12, max 4449.19)"
    "bw_mem-fcp-2mb (MB/s)","2710.45 (min 1062.13, max 4358.76)"
    "bw_mem-fcp-4mb (MB/s)","2514.09 (min 843.35, max 4184.83)"
    "bw_mem-fcp-8mb (MB/s)","2468.79 (min 930.23, max 4007.35)"
    "bw_mem-frd-16mb (MB/s)","910.75"
    "bw_mem-frd-1mb (MB/s)","2137.80 (min 2051.47, max 2224.12)"
    "bw_mem-frd-2mb (MB/s)","1351.28 (min 1062.13, max 1640.42)"
    "bw_mem-frd-4mb (MB/s)","927.24 (min 843.35, max 1011.12)"
    "bw_mem-frd-8mb (MB/s)","925.47 (min 920.70, max 930.23)"
    "bw_mem-fwr-16mb (MB/s)","3953.06"
    "bw_mem-fwr-1mb (MB/s)","3185.56 (min 2051.47, max 4319.65)"
    "bw_mem-fwr-2mb (MB/s)","2952.03 (min 1640.42, max 4263.63)"
    "bw_mem-fwr-4mb (MB/s)","2568.48 (min 1011.12, max 4125.84)"
    "bw_mem-fwr-8mb (MB/s)","2464.03 (min 920.70, max 4007.35)"
    "bw_mem-rd-16mb (MB/s)","2641.57"
    "bw_mem-rd-1mb (MB/s)","8072.03 (min 7213.88, max 8930.17)"
    "bw_mem-rd-2mb (MB/s)","6510.48 (min 5636.98, max 7383.97)"
    "bw_mem-rd-4mb (MB/s)","2072.58 (min 1209.37, max 2935.78)"
    "bw_mem-rd-8mb (MB/s)","1808.11 (min 948.65, max 2667.56)"
    "bw_mem-rdwr-16mb (MB/s)","897.67"
    "bw_mem-rdwr-1mb (MB/s)","4024.71 (min 3043.63, max 5005.78)"
    "bw_mem-rdwr-2mb (MB/s)","2003.25 (min 944.29, max 3062.20)"
    "bw_mem-rdwr-4mb (MB/s)","966.96 (min 858.65, max 1075.27)"
    "bw_mem-rdwr-8mb (MB/s)","884.13 (min 851.88, max 916.38)"
    "bw_mem-wr-16mb (MB/s)","923.63"
    "bw_mem-wr-1mb (MB/s)","6967.98 (min 5005.78, max 8930.17)"
    "bw_mem-wr-2mb (MB/s)","5223.09 (min 3062.20, max 7383.97)"
    "bw_mem-wr-4mb (MB/s)","1142.32 (min 1075.27, max 1209.37)"
    "bw_mem-wr-8mb (MB/s)","932.52 (min 916.38, max 948.65)"
    "bw_mmap_rd-mo-1mb (MB/s)","2736.51"
    "bw_mmap_rd-o2c-1mb (MB/s)","790.89"
    "bw_pipe (MB/s)","213.41"
    "bw_unix (MB/s)","868.00"
    "lat_connect (us)","147.82"
    "lat_ctx-2-128k (us)","1.86"
    "lat_ctx-2-256k (us)","4.00"
    "lat_ctx-4-128k (us)","8.12"
    "lat_ctx-4-256k (us)","0.00"
    "lat_fs-0k (num_files)","100.00"
    "lat_fs-10k (num_files)","45.00"
    "lat_fs-1k (num_files)","65.00"
    "lat_fs-4k (num_files)","68.00"
    "lat_mem_rd-stride128-sz1000k (ns)","19.28"
    "lat_mem_rd-stride128-sz125k (ns)","19.06"
    "lat_mem_rd-stride128-sz250k (ns)","19.28"
    "lat_mem_rd-stride128-sz31k (ns)","9.74"
    "lat_mem_rd-stride128-sz50 (ns)","4.01"
    "lat_mem_rd-stride128-sz500k (ns)","19.28"
    "lat_mem_rd-stride128-sz62k (ns)","19.06"
    "lat_mmap-1m (us)","163.00"
    "lat_ops-double-add (ns)","1.10"
    "lat_ops-double-mul (ns)","5.05"
    "lat_ops-float-add (ns)","1.10"
    "lat_ops-float-mul (ns)","5.05"
    "lat_ops-int-add (ns)","1.01"
    "lat_ops-int-bit (ns)","0.67"
    "lat_ops-int-div (ns)","88.24"
    "lat_ops-int-mod (ns)","15.50"
    "lat_ops-int-mul (ns)","3.16"
    "lat_ops-int64-add (ns)","1.11"
    "lat_ops-int64-bit (ns)","1.04"
    "lat_ops-int64-div (ns)","183.98"
    "lat_ops-int64-mod (ns)","34.31"
    "lat_pagefault (us)","1.83"
    "lat_pipe (us)","43.74"
    "lat_proc-exec (us)","2050.00"
    "lat_proc-fork (us)","2002.67"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","41.47"
    "lat_sem (us)","3.95"
    "lat_sig-catch (us)","11.88"
    "lat_sig-install (us)","2.29"
    "lat_sig-prot (us)","0.45"
    "lat_syscall-fstat (us)","10.29"
    "lat_syscall-null (us)","0.46"
    "lat_syscall-open (us)","363.56"
    "lat_syscall-read (us)","0.69"
    "lat_syscall-stat (us)","17.84"
    "lat_syscall-write (us)","0.57"
    "lat_tcp (us)","0.87"
    "lat_unix (us)","72.29"
    "latency_for_0.50_mb_block_size (nanosec)","19.28"
    "latency_for_1.00_mb_block_size (nanosec)","9.64 (min 0.00, max 19.28)"
    "pipe_bandwidth (MBs)","213.41"
    "pipe_latency (microsec)","43.74"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","41.47"
    "semaphore_latency (microsec)","3.95"
    "signal_handler_latency (microsec)","2.29"
    "signal_handler_overhead (microsec)","11.88"
    "tcp_ip_connection_cost_to_localhost (microsec)","147.82"
    "tcp_latency_using_localhost (microsec)","0.87"


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

    "linpack (Kflops)","648472.00","330144.00"


Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am574x-idk: perf","am654x-idk: perf"

    "assignment (Iterations)","13.35","7.68"
    "fourier (Iterations)","12555.00","8196.30"
    "fp_emulation (Iterations)","61.65","61.36"
    "huffman (Iterations)","902.59","671.87"
    "idea (Iterations)","2861.70","1915.40"
    "lu_decomposition (Iterations)","550.55","311.81"
    "neural_net (Iterations)","15.32","4.21"
    "numeric_sort (Iterations)","511.63","298.26"
    "string_sort (Iterations)","93.90","94.43"


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

    "add (MB/s)","2937.40","1589.40"
    "copy (MB/s)","3126.80","1832.70"
    "scale (MB/s)","3118.00","1824.50"
    "triad (MB/s)","2900.20","1494.40"


Table:  **Stream**
CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.



Table:  **CoreMarkPro**

MultiBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
MultiBench is a suite of benchmarks that allows processor and system designers to
analyze, test, and improve multicore processors. It uses three forms of concurrency:
Data decomposition: multiple threads cooperating on achieving a unified goal and
demonstrating a processors support for fine grain parallelism.
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




Table:  **Spec2K6**


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

    "L_PERF_SHIELD_SMP_1080ENC","28.00"
    "L_PERF_SHIELD_SMP_GRAPHICS","29.00"
    "L_PERF_SHIELD_SMP_HACKBENCH","29.00"
    "L_PERF_SHIELD_SMP_MEM","29.00"
    "L_PERF_SHIELD_SMP_NET","30.00"
    "L_PERF_SHIELD_SMP_NO_LOAD","29.00"
    "L_PERF_SHIELD_SMP_STRESS_LOAD","37.00"
    "L_PERF_SHIELD_SMP_UART","31.00"
    "L_PERF_SHIELD_SMP_USB","31.00"


|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am574x-idk: boot time (sec)","am654x-idk: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","38.17 (min 37.82, max 38.73)","15.13 (min 14.82, max 15.47)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","8.03 (min 7.99, max 8.04)","5.80 (min 5.78, max 5.84)"

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

    "8000","1024418.00","0.10"
    "11025","1024418.00","0.04"
    "16000","1024418.00","0.09"
    "22050","1024418.00","0.07"
    "24000","1024418.00","0.06"
    "32000","1024418.00","0.09"
    "44100","1411775.00","1.66"
    "48000","1536626.00","0.13"
    "88200","2823548.00","3.10"
    "96000","3073247.00","0.04"

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

    "1024x576\@60","59.97 (min 59.88, max 60.09)"
    "1024x768\@60","60.00 (min 59.88, max 60.14)"
    "1024x768\@70","70.07 (min 69.84, max 70.23)"
    "1024x768\@75","75.03 (min 74.84, max 75.23)"
    "1152x864\@75","75.00 (min 74.81, max 75.22)"
    "1280x1024\@60","60.02 (min 59.89, max 60.15)"
    "1280x1024\@75","75.02 (min 74.86, max 75.25)"
    "1280x720\@60","60.00 (min 59.90, max 60.11)"
    "1280x768\@60","59.87 (min 59.70, max 60.07)"
    "1280x768\@75","74.89 (min 74.72, max 75.12)"
    "1280x800\@60","59.81 (min 59.71, max 59.99)"
    "1280x800\@75","74.93 (min 74.74, max 75.12)"
    "1280x960\@60","60.00 (min 59.85, max 60.12)"
    "1360x768\@60","59.95 (min 59.79, max 60.11)"
    "1400x1050\@60","59.98 (min 59.77, max 60.23)"
    "1400x1050\@75","74.85 (min 73.64, max 75.39)"
    "1440x900\@60","59.89 (min 59.52, max 60.22)"
    "1440x900\@75","74.98 (min 74.70, max 75.21)"
    "1600x1200\@60","60.00 (min 59.87, max 60.15)"
    "1600x1200\@65","65.00 (min 64.87, max 65.18)"
    "1600x1200\@70","70.00 (min 69.72, max 70.21)"
    "1600x900\@60","60.00 (min 59.66, max 60.38)"
    "1680x1050\@60","59.95 (min 59.82, max 60.09)"
    "1680x1050\@75","74.89 (min 74.69, max 75.14)"
    "1680x945\@60","60.02 (min 59.75, max 60.16)"
    "1920x1080\@60","60.00 (min 59.88, max 60.16)"
    "2048x1152\@60","60.00 (min 59.87, max 60.15)"
    "640x480\@60","59.98 (min 58.98, max 60.11)"
    "640x480\@73","72.81 (min 72.70, max 72.97)"
    "640x480\@75","75.00 (min 74.83, max 75.16)"
    "720x400\@70","70.08 (min 69.92, max 70.24)"
    "800x600\@56","56.25 (min 56.13, max 56.37)"
    "800x600\@60","60.32 (min 60.24, max 60.44)"
    "800x600\@72","72.19 (min 71.99, max 72.36)"
    "800x600\@75","75.00 (min 74.76, max 75.27)"
    "832x624\@75","74.55 (min 73.98, max 75.19)"
    "848x480\@60","60.00 (min 59.90, max 60.12)"


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

    "GLB25_EgyptTestC24Z16FixedTime test","2500005.00","30.16 (min 17.44, max 58.07)"
    "GLB25_EgyptTestC24Z16_ETC1 test","2501001.00","36.36 (min 16.59, max 60.06)"
    "GLB25_EgyptTestC24Z16_ETC1to565 test","2501401.00","36.39 (min 16.67, max 60.02)"
    "GLB25_EgyptTestC24Z16_PVRTC4 test","2501101.00","36.10 (min 16.57, max 60.05)"
    "GLB25_EgyptTestC24Z24MS4 test","2500003.00","32.43 (min 15.52, max 60.00)"


Table:  **GLBenchmark 2.5 Performance**

Vertex Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmark","am574x-idk: Test Number","am574x-idk: Rate (triangles/sec)"

    "GLB25_TriangleTexFragmentLitTestC24Z16 test","2500511.00","17604802.00"
    "GLB25_TriangleTexTestC24Z16 test","2500301.00","85685896.00"
    "GLB25_TriangleTexVertexLitTestC24Z16 test","2500411.00","20564996.00"


Table:  **GLBenchmark 2.5 Vertex Throughput**

Pixel Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmark","am574x-idk: Test Number","am574x-idk: Rate (texel/sec)","am574x-idk: Fps"

    "GLB25_FillTestC24Z16 test","2500101.00","1050842688.00","42.73 (min 40.33, max 44.00)"


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



Table:  **GStreamer MPEG2 in MP4 Container Decode Performance**

|

|
Ethernet Driver
-------------------------

TCP Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "TCP Window Size (KBytes)","am574x-idk: Throughput (Mbits/sec)","am574x-idk: CPU Load ","am654x-idk: Throughput (Mbits/sec)","am654x-idk: CPU Load "

    "8","537.36","","567.20",""
    "16","569.60","","782.40",""
    "32","514.40",""
    "64","700.00","","1249.60",""
    "128","571.20","","1268.80",""
    "256","433.60","","1311.20",""

Table: **TCP Throughput No Interrupt Pacing**


.. csv-table::
    :header: "TCP Window Size (KBytes)","am574x-idk: Throughput (Mbits/sec)","am574x-idk: CPU Load ","am654x-idk: Throughput (Mbits/sec)","am654x-idk: CPU Load "

    "8","528.64","","0.00",""
    "16","574.40","","0.00",""
    "32","692.00","","0.00",""
    "64","757.60","","0.00",""
    "128","549.60","","0.00",""
    "256","462.40","","0.00",""

Table: **TCP Throughput Interrupt Pacing**


UDP Throughput
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "UDP Packet Size(bytes)","am574x-idk: Throughput (Mbits/sec)","am574x-idk: CPU Load ","am574x-idk: Packets Per Second (kpps) ","am654x-idk: Throughput (Mbits/sec)","am654x-idk: CPU Load ","am654x-idk: Packets Per Second (kpps) "

    "64","15.40","86.70","29.00"
    "128","32.50","90.00","31.00"
    "256","66.00","87.90","32.00"
    "512","123.30","83.20","30.00"
    "1024","243.00","82.90","29.00","473.00","100.00","57.00"
    "1470","349.00","83.00","29.00","92.00","25.80","7.00"
    "1500","211.00","83.00","17.00","446.00","100.00","37.00"
    "8000","952.00","53.10","14.00"

Table: **UDP Throughput Egress**


.. csv-table::
    :header: "UDP Packet Size(bytes)","am574x-idk: Throughput (Mbits/sec)","am574x-idk: CPU Load ","am574x-idk: Packets Per Second (kpps) ","am654x-idk: Throughput (Mbits/sec)","am654x-idk: CPU Load ","am654x-idk: Packets Per Second (kpps) "

    "64","38.80","97.50","74.00","39.70","36.40","76.00"
    "128","80.10","98.20","78.00","76.10","47.40","74.00"
    "256","156.10","98.60","76.00","156.60","47.70","76.00"
    "512","328.00","98.90","80.00","326.00","47.70","79.00"
    "1024","646.00","98.80","78.00","618.00","48.20","75.00"
    "1470","898.00","98.70","76.00","459.00","40.80","39.00"
    "1500","295.00","84.40","24.00","240.00","35.30","20.00"
    "8000","752.00","76.00","11.00"

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

    "102400","0.30 (min 0.26, max 0.46)","66.75 (min 65.75, max 68.16)","15.17","31.03"
    "262144","0.26 (min 0.24, max 0.28)","66.00 (min 65.22, max 66.43)","15.72","20.83"
    "524288","0.26 (min 0.24, max 0.27)","65.14 (min 63.15, max 66.35)","15.57","29.63"
    "1048576","0.26 (min 0.24, max 0.28)","66.61 (min 64.84, max 67.53)","15.32","20.83"






AM654X-IDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write UBIFS Throughput (Mbytes/sec)","am654x-idk: Write UBIFS CPU Load (%)","am654x-idk: Read UBIFS Throughput (Mbytes/sec)","am654x-idk: Read UBIFS CPU Load (%)"

    "102400","0.61 (min 0.48, max 1.11)","25.11 (min 25.03, max 25.19)","33.73","26.92"
    "262144","0.43 (min 0.31, max 0.50)","25.12 (min 25.06, max 25.19)","33.38","20.00"
    "524288","0.43 (min 0.30, max 0.51)","25.14 (min 25.07, max 25.18)","29.39","24.14"
    "1048576","0.46 (min 0.34, max 0.52)","25.15 (min 25.10, max 25.17)","29.01","24.14"

















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
    :header: "Buffer size (bytes)","am574x-idk: Write EXT2 Throughput (Mbytes/sec)","am574x-idk: Write EXT2 CPU Load (%)","am574x-idk: Read EXT2 Throughput (Mbytes/sec)","am574x-idk: Read EXT2 CPU Load (%)"

    "102400","32.49 (min 27.56, max 33.99)","13.56 (min 9.56, max 26.42)","63.76","23.49"
    "262144","32.17 (min 27.12, max 33.83)","13.81 (min 10.25, max 26.76)","67.55","23.96"
    "524288","32.09 (min 26.92, max 33.50)","13.82 (min 10.34, max 26.17)","73.58","21.71"
    "1048576","32.20 (min 27.05, max 34.03)","13.79 (min 9.90, max 27.31)","75.53","22.18"
    "5242880","32.32 (min 27.07, max 34.00)","14.16 (min 10.63, max 26.61)","75.43","23.38"

|



.. csv-table::
    :header: "Buffer size (bytes)","am574x-idk: Write EXT4 Throughput (Mbytes/sec)","am574x-idk: Write EXT4 CPU Load (%)","am574x-idk: Read EXT4 Throughput (Mbytes/sec)","am574x-idk: Read EXT4 CPU Load (%)"

    "102400","32.13 (min 28.88, max 33.15)","15.32 (min 11.36, max 24.03)","64.78","21.38"
    "262144","32.21 (min 28.76, max 33.32)","16.30 (min 13.65, max 23.86)","68.75","22.19"
    "524288","32.26 (min 28.92, max 33.17)","15.59 (min 13.04, max 23.42)","75.13","22.94"
    "1048576","32.40 (min 28.79, max 33.57)","15.77 (min 13.00, max 23.89)","77.53","24.45"
    "5242880","32.34 (min 28.73, max 33.58)","16.12 (min 13.73, max 24.21)","77.66","24.16"

|










AM654x-IDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write VFAT Throughput (Mbytes/sec)","am654x-idk: Write VFAT CPU Load (%)","am654x-idk: Read VFAT Throughput (Mbytes/sec)","am654x-idk: Read VFAT CPU Load (%)"

    "102400","33.69 (min 25.57, max 35.78)","6.80 (min 5.48, max 11.15)","131.45","12.37"
    "262144","33.75 (min 25.67, max 35.82)","6.70 (min 5.31, max 11.14)","135.10","16.89"
    "524288","33.81 (min 25.61, max 35.95)","6.78 (min 5.58, max 11.28)","143.23","18.90"
    "1048576","33.77 (min 25.52, max 35.88)","6.81 (min 5.34, max 11.51)","160.20","17.13"
    "5242880","33.78 (min 25.74, max 35.86)","6.67 (min 5.25, max 11.45)","158.60","19.84"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write EXT2 Throughput (Mbytes/sec)","am654x-idk: Write EXT2 CPU Load (%)","am654x-idk: Read EXT2 Throughput (Mbytes/sec)","am654x-idk: Read EXT2 CPU Load (%)"

    "102400","34.55 (min 30.89, max 35.59)","4.89 (min 4.09, max 7.89)","135.55","16.12"
    "262144","34.51 (min 30.59, max 35.64)","4.87 (min 4.06, max 7.60)","144.03","15.90"
    "524288","34.47 (min 30.48, max 35.61)","4.84 (min 3.92, max 7.66)","157.64","16.54"
    "1048576","34.48 (min 30.62, max 35.57)","4.79 (min 3.93, max 7.33)","168.31","18.62"
    "5242880","34.59 (min 30.49, max 35.69)","4.81 (min 3.85, max 7.64)","166.93","17.62"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write EXT4 Throughput (Mbytes/sec)","am654x-idk: Write EXT4 CPU Load (%)","am654x-idk: Read EXT4 Throughput (Mbytes/sec)","am654x-idk: Read EXT4 CPU Load (%)"

    "102400","34.25 (min 29.59, max 35.45)","5.87 (min 4.58, max 8.79)","127.66","15.17"
    "262144","34.79 (min 29.83, max 36.10)","6.23 (min 5.36, max 8.86)","145.12","16.67"
    "524288","34.61 (min 29.75, max 35.97)","6.28 (min 5.42, max 8.84)","163.36","17.53"
    "1048576","34.56 (min 29.63, max 36.10)","6.06 (min 5.19, max 9.08)","177.20","18.45"
    "5242880","34.74 (min 29.87, max 36.17)","6.13 (min 5.43, max 8.80)","176.53","19.66"

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

    "102400","17.19 (min 16.54, max 17.43)","7.88 (min 5.88, max 13.64)","18.41","6.60"
    "262144","18.13 (min 16.88, max 18.89)","8.96 (min 7.16, max 13.82)","22.15","6.62"
    "524288","18.29 (min 17.38, max 18.94)","8.28 (min 6.37, max 13.63)","22.68","6.74"
    "1048576","18.36 (min 17.01, max 18.84)","9.44 (min 7.53, max 15.56)","22.80","7.17"
    "5242880","18.15 (min 17.45, max 18.91)","9.02 (min 7.00, max 14.52)","22.83","7.10"

|




AM654x-IDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write VFAT Throughput (Mbytes/sec)","am654x-idk: Write VFAT CPU Load (%)","am654x-idk: Read VFAT Throughput (Mbytes/sec)","am654x-idk: Read VFAT CPU Load (%)"

    "102400","15.47 (min 13.18, max 16.72)","3.34 (min 2.47, max 6.27)","22.15","3.29"
    "262144","15.88 (min 13.49, max 16.71)","3.30 (min 2.44, max 6.18)","22.16","3.44"
    "524288","14.98 (min 11.49, max 16.66)","3.10 (min 2.15, max 5.39)","22.61","3.19"
    "1048576","15.49 (min 13.54, max 16.63)","3.28 (min 2.26, max 6.47)","23.09","3.14"
    "5242880","15.36 (min 13.45, max 16.62)","3.27 (min 1.99, max 6.43)","23.03","3.20"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write EXT2 Throughput (Mbytes/sec)","am654x-idk: Write EXT2 CPU Load (%)","am654x-idk: Read EXT2 Throughput (Mbytes/sec)","am654x-idk: Read EXT2 CPU Load (%)"

    "102400","16.43 (min 15.17, max 17.07)","2.43 (min 1.96, max 3.77)","22.54","2.49"
    "262144","16.21 (min 15.01, max 17.08)","2.35 (min 1.76, max 3.99)","22.83","2.74"
    "524288","16.13 (min 14.02, max 17.11)","2.30 (min 1.64, max 3.84)","23.41","2.36"
    "1048576","16.09 (min 13.01, max 17.01)","2.30 (min 1.97, max 3.32)","23.56","2.54"
    "5242880","16.61 (min 15.61, max 17.12)","2.23 (min 1.75, max 3.58)","23.57","2.60"

|



.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write EXT4 Throughput (Mbytes/sec)","am654x-idk: Write EXT4 CPU Load (%)","am654x-idk: Read EXT4 Throughput (Mbytes/sec)","am654x-idk: Read EXT4 CPU Load (%)"

    "102400","17.27 (min 16.07, max 17.99)","2.98 (min 2.40, max 4.80)","22.67","2.71"
    "262144","17.44 (min 15.76, max 18.00)","3.17 (min 2.71, max 4.71)","23.01","2.81"
    "524288","17.51 (min 16.17, max 17.87)","3.25 (min 2.61, max 5.10)","23.51","2.42"
    "1048576","17.42 (min 16.26, max 17.97)","3.15 (min 2.62, max 4.90)","23.76","2.50"
    "5242880","16.94 (min 14.38, max 17.86)","3.05 (min 2.49, max 4.60)","23.69","2.33"

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
    :header: "Buffer size (bytes)","am654x-idk: Write VFAT Throughput (Mbytes/sec)","am654x-idk: Write VFAT CPU Load (%)","am654x-idk: Read VFAT Throughput (Mbytes/sec)","am654x-idk: Read VFAT CPU Load (%)"

    "102400","33.41 (min 25.18, max 35.71)","8.62 (min 6.95, max 12.45)","38.22","7.43"
    "262144","33.59 (min 25.37, max 36.11)","9.17 (min 6.68, max 12.75)","37.28","5.35"




Table: **USB Host EXT2**

.. csv-table::
    :header: "Buffer size (bytes)","am654x-idk: Write EXT2 Throughput (Mbytes/sec)","am654x-idk: Write EXT2 CPU Load (%)","am654x-idk: Read EXT2 Throughput (Mbytes/sec)","am654x-idk: Read EXT2 CPU Load (%)"

    "102400","35.81 (min 31.04, max 37.36)","6.69 (min 5.81, max 8.86)","37.55","7.89"
    "1048576","35.68 (min 31.06, max 37.19)","6.37 (min 5.40, max 9.21)","37.92","6.65"
    "5242880","35.67 (min 31.00, max 37.06)","6.98 (min 5.77, max 9.27)","37.46","5.90"




|
|

|
|

|
|

|
|
CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. csv-table::
    :header: "Algorithm","Buffer Size","am574x-idk: throughput","am654x-idk: throughput"

    "aes-128-cbc","1024","6656.68","12538.88"
    "aes-128-cbc","16","1548.14","261.21"
    "aes-128-cbc","256","1926.57","4059.05"
    "aes-128-cbc","64","5513.94","1074.71"
    "aes-128-cbc","8192","23016.79","66617.34"
    "aes-192-cbc","1024","7769.77","12994.22"
    "aes-192-cbc","16","1478.41","225.37"
    "aes-192-cbc","256","2297.77","3276.97"
    "aes-192-cbc","64","5196.07","818.94"
    "aes-192-cbc","8192","24526.85","77376.17"
    "aes-256-cbc","1024","7786.84","12377.09"
    "aes-256-cbc","16","1509.84","212.30"
    "aes-256-cbc","256","2307.93","3261.61"
    "aes-256-cbc","64","5339.97","818.01"
    "aes-256-cbc","8192","24578.73","63070.21"
    "des-cbc","1024","5108.39","14333.61"
    "des-cbc","16","115.01","2599.46"
    "des-cbc","256","1663.32","11803.39"
    "des-cbc","64","449.45","6904.58"
    "des-cbc","8192","13170.01","15198.89"
    "des3","1024","5677.06","15437.82"
    "des3","16","135.50","204.84"
    "des3","256","1930.33","4310.70"
    "des3","64","530.26","1058.03"
    "des3","8192","12907.86","56729.60"
    "md5","1024","6046.72","27976.02"
    "md5","16","414.81","599.95"
    "md5","256","1946.45","8748.54"
    "md5","64","1640.96","2329.37"
    "md5","8192","31932.42","73717.08"
    "sha1","1024","6013.95","26284.03"
    "sha1","16","403.90","581.86"
    "sha1","256","1954.56","8417.28"
    "sha1","64","1591.34","2262.38"
    "sha1","8192","31812.27","65533.27"


|
|

.. csv-table::
    :header: "Algorithm","am574x-idk: CPU Load","am654x-idk: CPU Load"

    "aes-128-cbc","52.00","47.00"
    "aes-192-cbc","50.00","47.00"
    "aes-256-cbc","50.00","48.00"
    "des-cbc","20.00","99.00"
    "des3","16.00","43.00"
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

.. csv-table::
    :header: "Algorithm","am654x-idk: Throughput","am654x-idk: Packets/Sec","am654x-idk: CPU Load"

    "aes128","88.40","7.00","27.20"


PRU Ethernet
^^^^^^^^^^^^


Table: ** PRU UDP Throughput Egress**


.. csv-table::
    :header: "UDP Packet Size(bytes)","am654x-idk: Throughput (Mbits/sec)","am654x-idk: CPU Load ","am654x-idk: Packets Per Second (kpps) "

    "64","28.20","44.30","54.00"
    "1024","89.70","16.30","10.00"
    "1470","93.70","12.20","7.00"

Table: **PRU UDP Throughput Ingress**


