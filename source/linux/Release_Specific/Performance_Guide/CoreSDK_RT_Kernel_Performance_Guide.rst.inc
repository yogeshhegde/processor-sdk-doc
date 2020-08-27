..  http://processors.wiki.ti.com/index.php/CoreSDK_Linux_RT_Kernel_Performance_Guide
======================================
 RT-linux 07.00.00 Performance Guide
======================================

.. rubric::  **Read This First**
   :name: read-this-first-rt-kernel-perf-guide

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
| AM65x EVM      | AM65x Evaluation Module rev 1.0 with ARM running at 800MHz, DDR4-2400 (1600 MT/S), TMDX654GPEVM                     |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| J721e EVM      | J721e Evaluation Module rev E2 with ARM running at 2GHz, DDR data rate 3733 MT/S, L3 Cache size 3MB            |
+----------------+----------------------------------------------------------------------------------------------------------------+


Table:  Evaluation Modules

|

.. rubric::  About This Manual
   :name: about-this-manual-rt-kernel-perf-guide

This document provides performance data for each of the device drivers
which are part of the Process SDK Linux package. This document should be
used in conjunction with release notes and user guides provided with the
Process SDK Linux package for information on specific issues present
with drivers included in a particular release.

.. rubric::  If You Need Assistance
   :name: if-you-need-assistance-rt-kernel-perf-guide

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
    :header: "Benchmarks","am654x-evm: perf"

    "af_unix_sock_stream_latency (microsec)","53.21"
    "af_unix_socket_stream_bandwidth (MBs)","1191.45"
    "bw_file_rd-io-1mb (MB/s)","961.17"
    "bw_file_rd-o2c-1mb (MB/s)","560.64"
    "bw_mem-bcopy-16mb (MB/s)","868.39"
    "bw_mem-bcopy-1mb (MB/s)","1031.81"
    "bw_mem-bcopy-2mb (MB/s)","875.02"
    "bw_mem-bcopy-4mb (MB/s)","871.46"
    "bw_mem-bcopy-8mb (MB/s)","872.79"
    "bw_mem-bzero-16mb (MB/s)","1638.50"
    "bw_mem-bzero-1mb (MB/s)","2741.84 (min 1031.81, max 4451.86)"
    "bw_mem-bzero-2mb (MB/s)","1585.62 (min 875.02, max 2296.21)"
    "bw_mem-bzero-4mb (MB/s)","1277.13 (min 871.46, max 1682.79)"
    "bw_mem-bzero-8mb (MB/s)","1256.49 (min 872.79, max 1640.18)"
    "bw_mem-cp-16mb (MB/s)","583.60"
    "bw_mem-cp-1mb (MB/s)","2532.36 (min 665.89, max 4398.83)"
    "bw_mem-cp-2mb (MB/s)","1435.20 (min 587.72, max 2282.67)"
    "bw_mem-cp-4mb (MB/s)","1130.08 (min 579.71, max 1680.44)"
    "bw_mem-cp-8mb (MB/s)","1117.10 (min 591.32, max 1642.88)"
    "bw_mem-fcp-16mb (MB/s)","814.29"
    "bw_mem-fcp-1mb (MB/s)","2705.17 (min 958.47, max 4451.86)"
    "bw_mem-fcp-2mb (MB/s)","1557.11 (min 818.00, max 2296.21)"
    "bw_mem-fcp-4mb (MB/s)","1227.42 (min 772.05, max 1682.79)"
    "bw_mem-fcp-8mb (MB/s)","1225.98 (min 811.77, max 1640.18)"
    "bw_mem-frd-16mb (MB/s)","1257.57"
    "bw_mem-frd-1mb (MB/s)","1254.97 (min 958.47, max 1551.46)"
    "bw_mem-frd-2mb (MB/s)","1106.23 (min 818.00, max 1394.46)"
    "bw_mem-frd-4mb (MB/s)","1022.06 (min 772.05, max 1272.06)"
    "bw_mem-frd-8mb (MB/s)","1035.31 (min 811.77, max 1258.85)"
    "bw_mem-fwr-16mb (MB/s)","1637.67"
    "bw_mem-fwr-1mb (MB/s)","2975.15 (min 1551.46, max 4398.83)"
    "bw_mem-fwr-2mb (MB/s)","1838.57 (min 1394.46, max 2282.67)"
    "bw_mem-fwr-4mb (MB/s)","1476.25 (min 1272.06, max 1680.44)"
    "bw_mem-fwr-8mb (MB/s)","1450.87 (min 1258.85, max 1642.88)"
    "bw_mem-rd-16mb (MB/s)","1290.74"
    "bw_mem-rd-1mb (MB/s)","3093.16 (min 2768.44, max 3417.88)"
    "bw_mem-rd-2mb (MB/s)","1147.56 (min 897.00, max 1398.11)"
    "bw_mem-rd-4mb (MB/s)","1022.52 (min 749.06, max 1295.97)"
    "bw_mem-rd-8mb (MB/s)","1013.22 (min 733.81, max 1292.62)"
    "bw_mem-rdwr-16mb (MB/s)","725.95"
    "bw_mem-rdwr-1mb (MB/s)","1510.48 (min 665.89, max 2355.07)"
    "bw_mem-rdwr-2mb (MB/s)","731.82 (min 587.72, max 875.91)"
    "bw_mem-rdwr-4mb (MB/s)","660.09 (min 579.71, max 740.47)"
    "bw_mem-rdwr-8mb (MB/s)","658.61 (min 591.32, max 725.89)"
    "bw_mem-wr-16mb (MB/s)","736.82"
    "bw_mem-wr-1mb (MB/s)","2886.48 (min 2355.07, max 3417.88)"
    "bw_mem-wr-2mb (MB/s)","886.46 (min 875.91, max 897.00)"
    "bw_mem-wr-4mb (MB/s)","744.77 (min 740.47, max 749.06)"
    "bw_mem-wr-8mb (MB/s)","729.85 (min 725.89, max 733.81)"
    "bw_mmap_rd-mo-1mb (MB/s)","2622.38"
    "bw_mmap_rd-o2c-1mb (MB/s)","585.22"
    "bw_pipe (MB/s)","345.00"
    "bw_unix (MB/s)","1191.45"
    "lat_connect (us)","96.19"
    "lat_ctx-2-128k (us)","4.35"
    "lat_ctx-2-256k (us)","1.50"
    "lat_ctx-4-128k (us)","4.11"
    "lat_ctx-4-256k (us)","0.00"
    "lat_fs-0k (num_files)","176.00"
    "lat_fs-10k (num_files)","72.00"
    "lat_fs-1k (num_files)","112.00"
    "lat_fs-4k (num_files)","110.00"
    "lat_mem_rd-stride128-sz1000k (ns)","24.62"
    "lat_mem_rd-stride128-sz125k (ns)","9.75"
    "lat_mem_rd-stride128-sz250k (ns)","10.24"
    "lat_mem_rd-stride128-sz31k (ns)","3.79"
    "lat_mem_rd-stride128-sz50 (ns)","3.77"
    "lat_mem_rd-stride128-sz500k (ns)","11.47"
    "lat_mem_rd-stride128-sz62k (ns)","9.18"
    "lat_mmap-1m (us)","81.00"
    "lat_ops-double-add (ns)","0.92"
    "lat_ops-double-mul (ns)","5.05"
    "lat_ops-float-add (ns)","0.92"
    "lat_ops-float-mul (ns)","5.05"
    "lat_ops-int-add (ns)","1.26"
    "lat_ops-int-bit (ns)","0.84"
    "lat_ops-int-div (ns)","7.55"
    "lat_ops-int-mod (ns)","7.97"
    "lat_ops-int-mul (ns)","3.84"
    "lat_ops-int64-add (ns)","1.26"
    "lat_ops-int64-bit (ns)","0.84"
    "lat_ops-int64-div (ns)","11.95"
    "lat_ops-int64-mod (ns)","9.23"
    "lat_pagefault (us)","1.75"
    "lat_pipe (us)","26.20"
    "lat_proc-exec (us)","1343.75"
    "lat_proc-fork (us)","1268.20"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","56.58"
    "lat_sem (us)","7.22"
    "lat_sig-catch (us)","9.94"
    "lat_sig-install (us)","1.06"
    "lat_sig-prot (us)","0.68"
    "lat_syscall-fstat (us)","2.56"
    "lat_syscall-null (us)","0.46"
    "lat_syscall-open (us)","217.79"
    "lat_syscall-read (us)","1.17"
    "lat_syscall-stat (us)","7.11"
    "lat_syscall-write (us)","0.75"
    "lat_tcp (us)","0.82"
    "lat_unix (us)","53.21"
    "latency_for_0.50_mb_block_size (nanosec)","11.47"
    "latency_for_1.00_mb_block_size (nanosec)","12.31 (min 0.00, max 24.62)"
    "pipe_bandwidth (MBs)","345.00"
    "pipe_latency (microsec)","26.20"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","56.58"
    "semaphore_latency (microsec)","7.22"
    "signal_handler_latency (microsec)","1.06"
    "signal_handler_overhead (microsec)","9.94"
    "tcp_ip_connection_cost_to_localhost (microsec)","96.19"
    "tcp_latency_using_localhost (microsec)","0.82"


Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "cpu_clock (MHz)","400.00"
    "dhrystone_per_mhz (DMIPS/MHz)","5.90"
    "dhrystone_per_second (DhrystoneP)","4166666.80"


Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "whetstone (MIPS)","3333.30"


Table:  **Whetstone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
sloving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "linpack (Kflops)","332140.00"


Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "assignment (Iterations)","7.79"
    "fourier (Iterations)","13045.00"
    "fp_emulation (Iterations)","61.13"
    "huffman (Iterations)","669.06"
    "idea (Iterations)","1959.60"
    "lu_decomposition (Iterations)","318.44"
    "neural_net (Iterations)","4.48"
    "numeric_sort (Iterations)","285.22"
    "string_sort (Iterations)","94.57"


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
    :header: "Benchmarks","am654x-evm: perf"

    "add (MB/s)","1609.10"
    "copy (MB/s)","1762.50"
    "scale (MB/s)","1792.30"
    "triad (MB/s)","1507.30"


Table:  **Stream**
CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.

.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "cjpeg-rose7-preset (workloads/)","23.92"
    "core (workloads/)","0.17"
    "coremark-pro ()","548.19"
    "linear_alg-mid-100x100-sp (workloads/)","8.36"
    "loops-all-mid-10k-sp (workloads/)","0.43"
    "nnet_test (workloads/)","0.62"
    "parser-125k (workloads/)","5.26"
    "radix2-big-64k (workloads/)","44.74"
    "sha-test (workloads/)","46.30"
    "zip-test (workloads/)","12.82"


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



|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am654x-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","28.82 (min 24.54, max 35.09)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","7.01 (min 7.00, max 7.01)"

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

.. csv-table::
    :header: "Sampling Rate (Hz)","am654x-evm: Throughput (bits/sec)","am654x-evm: CPU Load (%)"

    "8000","255996.00","0.41"
    "11025","352794.00","0.41"
    "16000","511992.00","0.30"
    "22050","705589.00","0.61"
    "24000","705589.00","0.66"
    "32000","1023983.00","0.43"
    "44100","1411176.00","1.25"
    "48000","1535974.00","1.55"
    "88200","2822348.00","1.99"
    "96000","3071941.00","2.91"

Table:  **Audio Capture**

|


Table:  **Audio Playback**

|

Sensor Capture
-------------------------

Capture video frames (MMAP buffers) with v4l2c-ctl and record the
reported fps

.. csv-table::
    :header: "Resolution","Format","am654x-evm: Fps","am654x-evm: Sensor"

    "176x144","uyvy","30.02","ov5640"
    "1920x1080","uyvy","30.14","ov5640"

Table:  **Sensor Capture**

|

Display Driver
-------------------------


.. csv-table::
    :header: "Mode","am654x-evm: Fps"

    "1280x800\@60","59.99 (min 59.98, max 60.01)"

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





Table:  **GLBenchmark 2.5 Performance**

Vertex Throughput
"""""""""""""""""""""""""""



Table:  **GLBenchmark 2.5 Vertex Throughput**

Pixel Throughput
"""""""""""""""""""""""""""



Table:  **GLBenchmark 2.5 Pixel Throughput**

GFXBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Run GFXBench and capture performance reported (Score and Display rate in fps). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests



Table:  **GFXBench**

Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests



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

.. csv-table::
    :header: "Resolution","am654x-evm: Fps","am654x-evm: IVA Freq (MHz)","am654x-evm: IPU Freq (MHz)"

    "1080i","","",""
    "1080p","","",""
    "720p","","",""
    "720x480","","",""
    "800x480","","",""

Table:  **Gstreamer H264 in AVI Container Decode Performance**

|

MPEG4
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Resolution","am654x-evm: Fps","am654x-evm: IVA Freq (MHz)","am654x-evm: IPU Freq (MHz)"

    "CIF","","",""


Table:  **GStreamer MPEG4 in 3GP Container Decode Performance**

|

MPEG2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Resolution","am654x-evm: Fps","am654x-evm: IVA Freq (MHz)","am654x-evm: IPU Freq (MHz)"

    "720p","","",""


Table:  **GStreamer MPEG2 in MP4 Container Decode Performance**

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
bidirectional TCP performance for 60 seconds and report CPU utilization. 

::

   #!/bin/bash
   for i in 1
   do
      netperf -H <tester ip> -c -l 60 -t TCP_STREAM &
      netperf -H <tester ip> -c -l 60 -t TCP_MAERTS &
   done

Running the following commands will trigger netperf clients to measure UDP burst performance for 
60 seconds at various burst/datagram sizes and report CPU utilization.

- For UDP egress tests, run netperf client from DUT and start netserver on tester. 
::

   netperf -H <tester ip> -c -l 60 -t UDP_STREAM -b <burst_size> -w <wait_time> -- -m <UDP datagram size>

- For UDP ingress tests, run netperf client from tester and start netserver on DUT. 

::

   netperf -H <DUT ip> -C -l 60 -t UDP_STREAM -b <burst_size> -w <wait_time> -- -m <UDP datagram size>

|

CPSW2g Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput 
   :name: tcp-bidirectional-throughput

.. csv-table::
    :header: "TCP Window Size","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load %"

    "Default","1199.79","77.16"

Table: **CPSW2g TCP Bidirectional Throughput**

.. rubric::  UDP Throughput (0% loss) 
   :name: udp-throughput-0-loss
   
.. csv-table::
    :header: "Frame Size(bytes)","am654x-evm: UDP Datagram Size(bytes)","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load %","am654x-evm: Packets Per Second (KPPS)"

    "64","18.00","8.46","67.45","59.00"
    "128","82.00","34.38","68.86","52.00"
    "256","210.00","127.58","39.59","76.00"
    "1024","978.00","417.25","73.31","53.00"
    "1518","1472.00","736.45","51.49","63.00"

Table: **CPSW2g UDP Egress Throughput (0% loss)**
   
.. csv-table::
    :header: "Frame Size(bytes)","am654x-evm: UDP Datagram Size(bytes)","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load %","am654x-evm: Packets Per Second (KPPS)"

    "64","18.00","7.30","27.30","51.00"
    "128","82.00","29.58","24.55","45.00"
    "256","210.00","105.00","33.42","63.00"
    "1024","978.00","582.87","43.45","74.00"
    "1518","1472.00","640.58","30.82","54.00"

Table: **CPSW2g UDP Ingress Throughput (0% loss)**

.. rubric::  UDP Throughput (possible loss) 
:name: udp-throughput-possible-loss

.. csv-table::
    :header: "Frame Size(bytes)","am654x-evm: UDP Datagram Size(bytes)","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load %","am654x-evm: Packets Per Second (KPPS)","am654x-evm: Packet Loss %"

    "64","18.00","8.46","67.45","59.00","0.00"
    "128","82.00","34.38","68.86","52.00","0.00"
    "256","210.00","127.58","39.59","76.00","0.00"
    "1024","978.00","417.25","73.31","53.00","0.00"
    "1518","1472.00","736.45","51.49","63.00","0.00"

Table: **CPSW2g UDP Egress Throughput (possible loss)**

.. csv-table::
    :header: "Frame Size(bytes)","am654x-evm: UDP Datagram Size(bytes)","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load %","am654x-evm: Packets Per Second (KPPS)","am654x-evm: Packet Loss %"

    "64","18.00","11.69","43.48","81.00","87.08"
    "128","82.00","52.67","43.57","80.00","85.98"
    "256","210.00","140.13","44.24","83.00","80.74"
    "1024","978.00","600.23","44.46","77.00","35.93"
    "1518","1472.00","950.85","45.40","81.00","0.65"

Table: **CPSW2g UDP Ingress Throughput (possible loss)**

|

ICSSG Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput 
   :name: tcp-bidirectional-throughput

.. csv-table::
    :header: "TCP Window Size","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load %"

    "Default","146.05","51.59"

Table: **ICSSG TCP Bidirectional Throughput**

.. rubric::  UDP Throughput (0% loss) 
   :name: udp-throughput-0-loss
   
.. csv-table::
    :header: "Frame Size(bytes)","am654x-evm: UDP Datagram Size(bytes)","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load %","am654x-evm: Packets Per Second (KPPS)"

    "64","18.00","6.35","68.65","44.00"
    "128","82.00","35.53","69.29","54.00"
    "256","210.00","42.00","25.56","25.00"
    "1024","978.00","39.12","1.71","5.00"
    "1518","1472.00","40.04","7.97","3.00"

Table: **ICSSG UDP Egress Throughput (0% loss)**
   
.. csv-table::
    :header: "Frame Size(bytes)","am654x-evm: UDP Datagram Size(bytes)","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load %","am654x-evm: Packets Per Second (KPPS)"

    "128","82.00","27.22","35.66","41.00"
    "256","210.00","25.37","17.59","15.00"
    "1024","978.00","90.21","46.92","12.00"
    "1518","1472.00","94.13","42.95","8.00"

Table: **ICSSG UDP Ingress Throughput (0% loss)**

.. rubric::  UDP Throughput (possible loss) 
:name: udp-throughput-possible-loss

.. csv-table::
    :header: "Frame Size(bytes)","am654x-evm: UDP Datagram Size(bytes)","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load %","am654x-evm: Packets Per Second (KPPS)","am654x-evm: Packet Loss %"

    "64","18.00","5.60","34.19","39.00","0.00"
    "128","82.00","25.60","40.53","39.00","0.00"
    "256","210.00","67.58","47.43","40.00","14.23"
    "1024","978.00","90.38","29.18","12.00","54.48"
    "1518","1472.00","91.75","48.66","8.00","82.83"

Table: **ICSSG UDP Egress Throughput (possible loss)**

.. csv-table::
    :header: "Frame Size(bytes)","am654x-evm: UDP Datagram Size(bytes)","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load %","am654x-evm: Packets Per Second (KPPS)","am654x-evm: Packet Loss %"

    "128","82.00","33.37","43.37","51.00","41.62"
    "256","210.00","73.87","42.00","44.00","0.00"
    "1024","978.00","90.16","20.02","12.00","0.00"
    "1518","1472.00","94.08","14.33","8.00","0.00"

Table: **ICSSG UDP Ingress Throughput (possible loss)**

|

PCIe Driver
-------------------------

PCIe-ETH
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "TCP Window Size(Kbytes)","am654x-evm: Bandwidth (Mbits/sec)"

    "128","0.00"

Table: **PCI Ethernet**

NAND Driver
-------------------------










QSPI Flash Driver
-------------------------






.. rubric::  AM654x-EVM
   :name: am654x-evm

.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write UBIFS Throughput (Mbytes/sec)","am654x-evm: Write UBIFS CPU Load (%)","am654x-evm: Read UBIFS Throughput (Mbytes/sec)","am654x-evm: Read UBIFS CPU Load (%)"

    "102400","0.52 (min 0.43, max 0.83)","19.65 (min 18.75, max 20.21)","26.36","16.67"
    "262144","0.42 (min 0.34, max 0.45)","19.85 (min 19.38, max 20.82)","26.26","24.24"
    "524288","0.42 (min 0.34, max 0.45)","20.43 (min 19.47, max 20.87)","25.66","19.35"
    "1048576","0.42 (min 0.34, max 0.45)","20.56 (min 19.94, max 20.83)","27.74","23.33"















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

USB Host Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. warning::

  **IMPORTANT**: For Mass-storage applications, the performance numbers can be severely
  affected if the media is mounted in sync mode. Hot plug scripts in the
  filesystem mount removable media in sync mode to ensure data
  integrity. For performance sensitive applications, umount the
  auto-mounted filesystem and re-mount in async mode.

|

**Setup** : SAMSUNG 850 PRO 2.5" 128GB SATA III Internal Solid State Drive (SSD) used with Inateck ASM1153E enclosure is
connected to usb port under test. File read/write performance data is captured.

|






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
CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am654x-evm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","15295.15"
    "aes-128-cbc","16","249.97"
    "aes-128-cbc","16384","123808.43"
    "aes-128-cbc","256","21706.15"
    "aes-128-cbc","64","1000.41"
    "aes-128-cbc","8192","89019.73"
    "aes-192-cbc","1024","13575.51"
    "aes-192-cbc","16","249.63"
    "aes-192-cbc","16384","108582.23"
    "aes-192-cbc","256","21361.49"
    "aes-192-cbc","64","992.51"
    "aes-192-cbc","8192","87187.46"
    "aes-256-cbc","1024","14388.22"
    "aes-256-cbc","16","252.83"
    "aes-256-cbc","16384","112678.23"
    "aes-256-cbc","256","20743.00"
    "aes-256-cbc","64","1004.86"
    "aes-256-cbc","8192","75609.43"
    "des-cbc","1024","14978.05"
    "des-cbc","16","2861.43"
    "des-cbc","16384","15908.86"
    "des-cbc","256","12483.75"
    "des-cbc","64","7489.26"
    "des-cbc","8192","15843.33"
    "des3","1024","15016.96"
    "des3","16","247.35"
    "des3","16384","72450.05"
    "des3","256","5697.79"
    "des3","64","995.09"
    "des3","8192","59342.85"
    "md5","1024","28144.64"
    "md5","16","607.21"
    "md5","16384","86862.51"
    "md5","256","8822.10"
    "md5","64","2357.59"
    "md5","8192","75912.53"
    "sha1","1024","8691.03"
    "sha1","16","143.57"
    "sha1","16384","76174.68"
    "sha1","256","4704.60"
    "sha1","64","577.00"
    "sha1","8192","49575.25"
    "sha224","1024","32469.33"
    "sha224","16","559.52"
    "sha224","16384","199502.51"
    "sha224","256","8729.43"
    "sha224","64","2230.76"
    "sha224","8192","147622.57"
    "sha256","1024","8647.34"
    "sha256","16","146.05"
    "sha256","16384","81920.00"
    "sha256","256","4594.35"
    "sha256","64","601.05"
    "sha256","8192","51680.60"
    "sha384","1024","20144.81"
    "sha384","16","560.54"
    "sha384","16384","41937.58"
    "sha384","256","7508.05"
    "sha384","64","2248.94"
    "sha384","8192","39067.65"
    "sha512","1024","8769.88"
    "sha512","16","132.89"
    "sha512","16384","94988.97"
    "sha512","256","4153.51"
    "sha512","64","531.46"
    "sha512","8192","55667.37"


|
|

.. csv-table::
    :header: "Algorithm","am654x-evm: CPU Load"

    "aes-128-cbc","55.00"
    "aes-192-cbc","53.00"
    "aes-256-cbc","53.00"
    "des-cbc","98.00"
    "des3","50.00"
    "md5","98.00"
    "sha1","69.00"
    "sha224","98.00"
    "sha256","69.00"
    "sha384","98.00"
    "sha512","69.00"



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
    :header: "Algorithm","am654x-evm: Throughput (Mbps)","am654x-evm: Packets/Sec","am654x-evm: CPU Load"

    "aes128","124.40","10.00","46.90"


PRU Ethernet
------------

.. csv-table::
    :header: "UDP Datagram Size(bytes)","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load ","am654x-evm: Packets Per Second (kpps) "

    "64","28.80","61.60","54.00"

Table: **PRU UDP Throughput Egress**


.. csv-table::
    :header: "UDP Datagram Size(bytes)","am654x-evm: Throughput (Mbits/sec)","am654x-evm: CPU Load ","am654x-evm: Packets Per Second (kpps) "

    "64","20.40","42.60","39.00"
    "1470","93.60","15.70","7.00"
    "1500","89.90","23.20","7.00"
    "8000","92.70","14.30","1.00"

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
    

