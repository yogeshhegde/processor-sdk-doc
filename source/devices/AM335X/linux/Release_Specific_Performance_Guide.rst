************************************
Performance Guide for AM335X
************************************

.. rubric::  **Read This First**
   :name: read-this-first-kernel-perf-guide

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
| AM65x EVM      | AM65x Evaluation Module rev 1.0 with ARM running at 800MHz, DDR4-2400 (1600 MT/S), TMDX654GPEVM                |
+----------------+----------------------------------------------------------------------------------------------------------------+
| J721e EVM      | J721e Evaluation Module rev E2 with ARM running at 2GHz, DDR data rate 3733 MT/S, L3 Cache size 3MB            |
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
http://community.ti.com/ or http://support.ti.com/

System Benchmarks
-------------------

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
    :header: "Benchmarks","am335x-evm: perf"

    "af_unix_sock_stream_latency (microsec)","42.41"
    "af_unix_socket_stream_bandwidth (MBs)","161.41"
    "bw_file_rd-io-1mb (MB/s)","186.74"
    "bw_file_rd-o2c-1mb (MB/s)","149.54"
    "bw_mem-bcopy-16mb (MB/s)","202.82"
    "bw_mem-bcopy-1mb (MB/s)","203.89"
    "bw_mem-bcopy-2mb (MB/s)","198.77"
    "bw_mem-bcopy-4mb (MB/s)","194.56"
    "bw_mem-bcopy-8mb (MB/s)","209.46"
    "bw_mem-bzero-16mb (MB/s)","996.33"
    "bw_mem-bzero-1mb (MB/s)","594.07 (min 203.89, max 984.25)"
    "bw_mem-bzero-2mb (MB/s)","592.00 (min 198.77, max 985.22)"
    "bw_mem-bzero-4mb (MB/s)","589.29 (min 194.56, max 984.01)"
    "bw_mem-bzero-8mb (MB/s)","596.98 (min 209.46, max 984.49)"
    "bw_mem-cp-16mb (MB/s)","164.22"
    "bw_mem-cp-1mb (MB/s)","588.78 (min 195.24, max 982.32)"
    "bw_mem-cp-2mb (MB/s)","588.46 (min 192.66, max 984.25)"
    "bw_mem-cp-4mb (MB/s)","594.65 (min 196.73, max 992.56)"
    "bw_mem-cp-8mb (MB/s)","593.26 (min 202.38, max 984.13)"
    "bw_mem-fcp-16mb (MB/s)","296.58"
    "bw_mem-fcp-1mb (MB/s)","641.05 (min 297.84, max 984.25)"
    "bw_mem-fcp-2mb (MB/s)","640.87 (min 296.52, max 985.22)"
    "bw_mem-fcp-4mb (MB/s)","639.11 (min 294.20, max 984.01)"
    "bw_mem-fcp-8mb (MB/s)","638.96 (min 293.42, max 984.49)"
    "bw_mem-frd-16mb (MB/s)","249.79"
    "bw_mem-frd-1mb (MB/s)","282.88 (min 267.92, max 297.84)"
    "bw_mem-frd-2mb (MB/s)","274.89 (min 253.26, max 296.52)"
    "bw_mem-frd-4mb (MB/s)","272.02 (min 249.84, max 294.20)"
    "bw_mem-frd-8mb (MB/s)","271.40 (min 249.38, max 293.42)"
    "bw_mem-fwr-16mb (MB/s)","996.39"
    "bw_mem-fwr-1mb (MB/s)","625.12 (min 267.92, max 982.32)"
    "bw_mem-fwr-2mb (MB/s)","618.76 (min 253.26, max 984.25)"
    "bw_mem-fwr-4mb (MB/s)","621.20 (min 249.84, max 992.56)"
    "bw_mem-fwr-8mb (MB/s)","616.76 (min 249.38, max 984.13)"
    "bw_mem-rd-16mb (MB/s)","252.47"
    "bw_mem-rd-1mb (MB/s)","632.70 (min 270.38, max 995.02)"
    "bw_mem-rd-2mb (MB/s)","619.11 (min 254.13, max 984.09)"
    "bw_mem-rd-4mb (MB/s)","618.42 (min 252.35, max 984.49)"
    "bw_mem-rd-8mb (MB/s)","617.97 (min 251.56, max 984.37)"
    "bw_mem-rdwr-16mb (MB/s)","203.07"
    "bw_mem-rdwr-1mb (MB/s)","201.36 (min 195.24, max 207.47)"
    "bw_mem-rdwr-2mb (MB/s)","198.25 (min 192.66, max 203.83)"
    "bw_mem-rdwr-4mb (MB/s)","199.97 (min 196.73, max 203.21)"
    "bw_mem-rdwr-8mb (MB/s)","202.79 (min 202.38, max 203.20)"
    "bw_mem-wr-16mb (MB/s)","996.57"
    "bw_mem-wr-1mb (MB/s)","601.25 (min 207.47, max 995.02)"
    "bw_mem-wr-2mb (MB/s)","593.96 (min 203.83, max 984.09)"
    "bw_mem-wr-4mb (MB/s)","593.85 (min 203.21, max 984.49)"
    "bw_mem-wr-8mb (MB/s)","593.79 (min 203.20, max 984.37)"
    "bw_mmap_rd-mo-1mb (MB/s)","262.50"
    "bw_mmap_rd-o2c-1mb (MB/s)","173.10"
    "bw_pipe (MB/s)","318.42"
    "bw_unix (MB/s)","161.41"
    "lat_connect (us)","77.90"
    "lat_ctx-2-128k (us)","50.34"
    "lat_ctx-2-256k (us)","4.00"
    "lat_ctx-4-128k (us)","48.70"
    "lat_ctx-4-256k (us)","0.00"
    "lat_fs-0k (num_files)","203.00"
    "lat_fs-10k (num_files)","69.00"
    "lat_fs-1k (num_files)","108.00"
    "lat_fs-4k (num_files)","104.00"
    "lat_mem_rd-stride128-sz1000k (ns)","220.90"
    "lat_mem_rd-stride128-sz125k (ns)","11.68"
    "lat_mem_rd-stride128-sz250k (ns)","76.74"
    "lat_mem_rd-stride128-sz31k (ns)","3.02"
    "lat_mem_rd-stride128-sz50 (ns)","3.00"
    "lat_mem_rd-stride128-sz500k (ns)","187.13"
    "lat_mem_rd-stride128-sz62k (ns)","8.72"
    "lat_mmap-1m (us)","69.00"
    "lat_ops-double-add (ns)","2.37"
    "lat_ops-double-mul (ns)","11.02"
    "lat_ops-float-add (ns)","2.28"
    "lat_ops-float-mul (ns)","10.02"
    "lat_ops-int-add (ns)","1.00"
    "lat_ops-int-bit (ns)","0.67"
    "lat_ops-int-div (ns)","72.96"
    "lat_ops-int-mod (ns)","24.47"
    "lat_ops-int-mul (ns)","6.06"
    "lat_ops-int64-add (ns)","1.20"
    "lat_ops-int64-bit (ns)","1.06"
    "lat_ops-int64-div (ns)","191.50"
    "lat_ops-int64-mod (ns)","52.31"
    "lat_pagefault (us)","1.69"
    "lat_pipe (us)","34.68"
    "lat_proc-exec (us)","1657.00"
    "lat_proc-fork (us)","1411.75"
    "lat_proc-proccall (us)","0.02"
    "lat_select (us)","41.59"
    "lat_sem (us)","4.60"
    "lat_sig-catch (us)","6.00"
    "lat_sig-install (us)","1.50"
    "lat_sig-prot (us)","0.19"
    "lat_syscall-fstat (us)","2.10"
    "lat_syscall-null (us)","0.53"
    "lat_syscall-open (us)","290.15"
    "lat_syscall-read (us)","1.37"
    "lat_syscall-stat (us)","5.27"
    "lat_syscall-write (us)","0.74"
    "lat_tcp (us)","1.13"
    "lat_unix (us)","42.41"
    "latency_for_0.50_mb_block_size (nanosec)","187.13"
    "latency_for_1.00_mb_block_size (nanosec)","110.45 (min 0.00, max 220.90)"
    "pipe_bandwidth (MBs)","318.42"
    "pipe_latency (microsec)","34.68"
    "procedure_call (microsec)","0.02"
    "select_on_200_tcp_fds (microsec)","41.59"
    "semaphore_latency (microsec)","4.60"
    "signal_handler_latency (microsec)","1.50"
    "signal_handler_overhead (microsec)","6.00"
    "tcp_ip_connection_cost_to_localhost (microsec)","77.90"
    "tcp_latency_using_localhost (microsec)","1.13"


Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.
  
.. csv-table::
    :header: "Benchmarks","am335x-evm: perf"

    "cpu_clock (MHz)","1000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.10"
    "dhrystone_per_second (DhrystoneP)","3636363.80"


Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf"

    "whetstone (MIPS)","833.30"


Table:  **Whetstone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
sloving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf"

    "linpack (Kflops)","52701.00"


Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf"

    "assignment (Iterations)","7.65"
    "fourier (Iterations)","2890.10"
    "fp_emulation (Iterations)","80.61"
    "huffman (Iterations)","720.73"
    "idea (Iterations)","1296.40"
    "lu_decomposition (Iterations)","76.46"
    "neural_net (Iterations)","2.16"
    "numeric_sort (Iterations)","466.21"
    "string_sort (Iterations)","61.48"


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
    :header: "Benchmarks","am335x-evm: perf"

    "add (MB/s)","386.80"
    "copy (MB/s)","423.20"
    "scale (MB/s)","638.80"
    "triad (MB/s)","449.30"


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

Rate (Multiple Cores)


Table:  **Spec2K6**

Speed (Single Core)


Table:  **Spec2K6 Speed**


Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am335x-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","57.54 (min 56.48, max 58.70)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","5.81 (min 5.57, max 6.32)"

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
    :header: "Sampling Rate (Hz)","am335x-evm: Throughput (bits/sec)","am335x-evm: CPU Load (%)"

    "8000","255999.00","1.07"
    "11025","352799.00","3.98"
    "16000","511998.00","16.05"
    "22050","705597.00","7.86"
    "24000","705597.00","7.81"
    "32000","1023995.00","1.20"
    "44100","1411191.00","14.41"
    "48000","1535989.00","29.16"
    "88200","2822367.00","28.33"
    "96000","3071961.00","1.12"

Table:  **Audio Capture**

|

.. csv-table::
    :header: "Sampling Rate (Hz)","am335x-evm: Throughput (bits/sec)","am335x-evm: CPU Load (%)"

    "8000","256102.00","4.96"
    "11025","352941.00","3.75"
    "16000","512204.00","18.29"
    "22050","705881.00","7.76"
    "24000","705881.00","7.64"
    "32000","1024407.00","1.15"
    "44100","1411759.00","14.15"
    "48000","1536607.00","11.24"
    "88200","2823503.00","28.24"
    "96000","3073198.00","10.97"

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
    :header: "Mode","am335x-evm: Fps"

    "800x480\@62","61.88 (min 59.90, max 61.92)"

Table:  **Display performance (LCD)**


|



|



|



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
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Fps"

    "GLB25_EgyptTestC24Z16FixedTime test","2500005.00","5.10 (min 2.29, max 14.07)"
    "GLB25_EgyptTestC24Z16_ETC1 test","2501001.00","6.17 (min 2.29, max 14.07)"
    "GLB25_EgyptTestC24Z16_ETC1to565 test","2501401.00","6.17 (min 1.85, max 14.39)"
    "GLB25_EgyptTestC24Z16_PVRTC4 test","2501101.00","6.00 (min 1.82, max 13.97)"
    "GLB25_EgyptTestStandard_inherited test","2000000.00","22.74 (min 14.74, max 30.95)"




Table:  **GLBenchmark 2.5 Performance**

Vertex Throughput
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Rate (triangles/sec)"

    "GLB25_TriangleTexFragmentLitTestC24Z16 test","2500511.00","2132589.00"
    "GLB25_TriangleTexTestC24Z16 test","2500301.00","10920302.00"
    "GLB25_TriangleTexVertexLitTestC24Z16 test","2500411.00","2872222.75"


Table:  **GLBenchmark 2.5 Vertex Throughput**

Pixel Throughput
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Rate (texel/sec)","am335x-evm: Fps"

    "GLB25_FillTestC24Z16 test","2500101.00","101827712.00","4.27 (min 3.81, max 6.88)"


Table:  **GLBenchmark 2.5 Pixel Throughput**

GFXBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Run GFXBench and capture performance reported (Score and Display rate in fps). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests



Table:  **GFXBench**

Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am335x-evm: Score"

    "Glmark2-DRM","47.00"
    "Glmark2-Wayland","39.00"


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

H264
^^^^^^^^^^^^^^^^^^^^^^^^^^^


Table:  **Gstreamer H264 in AVI Container Decode Performance**

|

MPEG4
^^^^^^^^^^^^^^^^^^^^^^^^^^^



Table:  **GStreamer MPEG4 in 3GP Container Decode Performance**

|

MPEG2
^^^^^^^^^^^^^^^^^^^^^^^^^^^



Table:  **GStreamer MPEG2 in MP4 Container Decode Performance**

|

Machine Learning
-------------------------

TensorFlow Lite
^^^^^^^^^^^^^^^^^^^^^^^^^^^
TensorFlow Lite https://www.tensorflow.org/lite/ is open source deep
learning runtime for on-device inference. Processor SDK supports
TensorFlow Lite execution on Cortex A cores on all Sitara devices.

The table below lists TensorFlow Lite performance benchmarks when running
several well-known models on Sitara devices. The benchmarking data are
obtained with the benchmark_model binary, which is released in the
TensorFlow Lite source package and included in Processor SDK Linux filesystem.


Table:  **TensorFlow Lite Performance**

|

TI Deep Learning
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Accelerates deep learning inference on C66x DSP cores and on
Embedded Vision Engine (EVE) subsystems.


Table:  **TIDL Performance**

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

CPSW2g Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput 
   :name: tcp-bidirectional-throughput


Table: **CPSW2g TCP Bidirectional Throughput**

.. rubric::  UDP Throughput (0% loss) 
   :name: udp-throughput-0-loss
   

Table: **CPSW2g UDP Egress Throughput (0% loss)**
   

Table: **CPSW2g UDP Ingress Throughput (0% loss)**

.. rubric::  UDP Throughput (possible loss) 
:name: udp-throughput-possible-loss


Table: **CPSW2g UDP Egress Throughput (possible loss)**


Table: **CPSW2g UDP Ingress Throughput (possible loss)**

|

CPSW9g Virtual Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput 
   :name: tcp-bidirectional-throughput


Table: **CPSW9g Virtual Ethernet Driver - TCP Bidirectional Throughput**

.. rubric::  UDP Throughput (0% loss) 
   :name: udp-throughput-0-loss
   

Table: **CPSW9g Virtual Ethernet Driver - UDP Egress Throughput (0% loss)**
   

Table: **CPSW9g Virtual Ethernet Driver - UDP Ingress Throughput (0% loss)**

.. rubric::  UDP Throughput (possible loss) 
:name: udp-throughput-possible-loss


Table: **CPSW9g Virtual Ethernet Driver - UDP Egress Throughput (possible loss)**


Table: **CPSW9g Virtual Ethernet Driver - UDP Ingress Throughput (possible loss)**

|

PCIe Driver
-------------------------

PCIe-ETH
^^^^^^^^^^^^^^^^^^^^^^^^^^^


Table: **PCI Ethernet**

PCIe-EP
^^^^^^^^^^^^^^^^^^^^^^^^^^^














PCIe-NVMe-SSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^
















NAND Driver
-------------------------



AM335X-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write UBIFS Throughput (Mbytes/sec)","am335x-evm: Write UBIFS CPU Load (%)","am335x-evm: Read UBIFS Throughput (Mbytes/sec)","am335x-evm: Read UBIFS CPU Load (%)"

    "102400","3.94 (min 3.91, max 4.03)","62.89 (min 61.85, max 63.84)","5.27","35.80"
    "262144","3.91 (min 3.87, max 3.93)","63.05 (min 62.08, max 63.90)","5.27","34.48"
    "524288","3.90 (min 3.88, max 3.93)","63.80 (min 63.38, max 64.34)","5.30","34.73"
    "1048576","3.91 (min 3.89, max 3.94)","62.89 (min 60.97, max 63.73)","5.27","35.21"
    "5242880","3.93 (min 3.91, max 3.96)","64.10 (min 63.82, max 64.32)","5.27","35.08"










OSPI Flash Driver
-------------------------














QSPI Flash Driver
-------------------------


























UBoot QSPI/OSPI Driver
-------------------------























SPI Flash Driver
-------------------------







UFS Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

|







UBoot UFS Driver
-------------------------
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









































UBoot EMMC Driver
-------------------------
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














|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|





The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|






The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|





The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|







The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|





|

The performance numbers were captured using the following:

-  SanDisk 8GB SDHC UHS Memory Card
-  Partition was mounted with async option

|






The performance numbers were captured using the following:

-  SanDisk 8GB SDHC UHS Memory Card
-  Partition was mounted with async option

|









|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|









|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|









|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|









|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|






|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|




|


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|


UBoot MMC/SD Driver
-------------------------
| 










|





















|





|









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




































|

USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^


|
|

|
|

|
|

|
|

Table: **USBDEVICE HIGHSPEED SLAVE READ THROUGHPUT**
.. csv-table::
    :header: "Number of Blocks","am335x-evm: Throughput (MB/sec)"

    "150","21.90"


|
|

Table: **USBDEVICE HIGHSPEED SLAVE WRITE THROUGHPUT**
.. csv-table::
    :header: "Number of Blocks","am335x-evm: Throughput (MB/sec)"

    "150","8.90"


|
|

Table: **USBDEVICE HIGHSPEED CDC IPERF TCP THROUGHPUT**
.. csv-table::
    :header: "Window Size (kbytes)","am335x-evm: TX Throughput (Mbits/sec)","am335x-evm: RX Throughput (Mbits/sec)"

    "8","50.35","51.25"
    "16","50.90","49.62"
    "32","50.06","49.78"
    "64","50.56","49.88"
    "128","50.60","50.76"


|
|

|
|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am335x-evm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","12286.63"
    "aes-128-cbc","16","2322.63"
    "aes-128-cbc","16384","17640.11"
    "aes-128-cbc","256","4397.06"
    "aes-128-cbc","64","7876.33"
    "aes-128-cbc","8192","19480.58"
    "aes-192-cbc","1024","12303.70"
    "aes-192-cbc","16","2397.06"
    "aes-192-cbc","16384","16995.67"
    "aes-192-cbc","256","4313.86"
    "aes-192-cbc","64","7506.90"
    "aes-192-cbc","8192","19111.94"
    "aes-256-cbc","1024","12401.66"
    "aes-256-cbc","16","2364.89"
    "aes-256-cbc","16384","16973.82"
    "aes-256-cbc","256","4327.77"
    "aes-256-cbc","64","7275.07"
    "aes-256-cbc","8192","18653.18"
    "des-cbc","1024","15244.97"
    "des-cbc","16","2350.14"
    "des-cbc","16384","16274.77"
    "des-cbc","256","11869.61"
    "des-cbc","64","6623.36"
    "des-cbc","8192","16613.38"
    "des3","1024","6293.50"
    "des3","16","1926.53"
    "des3","16384","6662.83"
    "des3","256","5808.81"
    "des3","64","4139.95"
    "des3","8192","6649.17"
    "md5","1024","9915.73"
    "md5","16","500.34"
    "md5","16384","47557.29"
    "md5","256","3724.54"
    "md5","64","2028.63"
    "md5","8192","39215.10"
    "sha1","1024","9717.08"
    "sha1","16","454.21"
    "sha1","16384","47491.75"
    "sha1","256","3620.18"
    "sha1","64","1809.07"
    "sha1","8192","39018.50"
    "sha224","1024","10158.08"
    "sha224","16","460.14"
    "sha224","16384","45951.66"
    "sha224","256","3614.81"
    "sha224","64","1719.51"
    "sha224","8192","37317.29"
    "sha256","1024","10112.00"
    "sha256","16","456.91"
    "sha256","16384","46945.62"
    "sha256","256","3720.36"
    "sha256","64","1709.53"
    "sha256","8192","39556.44"
    "sha384","1024","17238.70"
    "sha384","16","467.55"
    "sha384","16384","38065.49"
    "sha384","256","6092.97"
    "sha384","64","1871.72"
    "sha384","8192","36077.57"
    "sha512","1024","17098.75"
    "sha512","16","469.96"
    "sha512","16384","39348.91"
    "sha512","256","6270.81"
    "sha512","64","1882.28"
    "sha512","8192","36225.02"


|
|

.. csv-table::
    :header: "Algorithm","am335x-evm: CPU Load"

    "aes-128-cbc","43.00"
    "aes-192-cbc","43.00"
    "aes-256-cbc","43.00"
    "des-cbc","97.00"
    "des3","98.00"
    "md5","68.00"
    "sha1","68.00"
    "sha224","69.00"
    "sha256","69.00"
    "sha384","97.00"
    "sha512","98.00"



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
    :header: "Algorithm","am335x-evm: Throughput (Mbps)","am335x-evm: Packets/Sec","am335x-evm: CPU Load"

    "3des","17.30","1.00","76.10"
    "aes128","10.40","0.00","56.20"
    "aes192","3.90","0.00","73.40"
    "aes256","29.20","2.00","71.20"



DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.

Power Management
-------------------------


