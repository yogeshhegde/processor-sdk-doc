..  http://processors.wiki.ti.com/index.php/CoreSDK_Linux_RT_Kernel_Performance_Guide

======================================
 RT-linux 07.03.00 Performance Guide
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
| AM64x EVM      | AM64x Evaluation Module rev E1 with ARM running at 1GHz, DDRdata rate 1600 MT/S                                     |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| AM65x EVM      | AM65x Evaluation Module rev 1.0 with ARM running at 800MHz, DDR4-2400 (1600 MT/S), TMDX654GPEVM                     |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| J721e EVM      | J721e Evaluation Module rev E2 with ARM running at 2GHz, DDR data rate 4266 MT/S, L3 Cache size 3MB                 |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| J7200 EVM      | J7200 Evaluation Module rev E2 with ARM running at 2GHz, DDR data rate 2666 MT/S, L3 Cache size 3MB                 |
+----------------+---------------------------------------------------------------------------------------------------------------------+


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
    :header: "Benchmarks","am64xx-evm: perf"

    "af_unix_sock_stream_latency (microsec)","41.81"
    "af_unix_socket_stream_bandwidth (MBs)","655.38"
    "bw_file_rd-io-1mb (MB/s)","813.54"
    "bw_file_rd-o2c-1mb (MB/s)","473.48"
    "bw_mem-bcopy-16mb (MB/s)","860.59"
    "bw_mem-bcopy-1mb (MB/s)","918.61"
    "bw_mem-bcopy-2mb (MB/s)","895.66"
    "bw_mem-bcopy-4mb (MB/s)","890.37"
    "bw_mem-bcopy-8mb (MB/s)","909.19"
    "bw_mem-bzero-16mb (MB/s)","2118.92"
    "bw_mem-bzero-1mb (MB/s)","1514.90 (min 918.61, max 2111.19)"
    "bw_mem-bzero-2mb (MB/s)","1505.85 (min 895.66, max 2116.03)"
    "bw_mem-bzero-4mb (MB/s)","1503.76 (min 890.37, max 2117.15)"
    "bw_mem-bzero-8mb (MB/s)","1489.39 (min 909.19, max 2069.59)"
    "bw_mem-cp-16mb (MB/s)","522.35"
    "bw_mem-cp-1mb (MB/s)","1398.83 (min 526.22, max 2271.44)"
    "bw_mem-cp-2mb (MB/s)","1354.70 (min 529.17, max 2180.23)"
    "bw_mem-cp-4mb (MB/s)","1343.43 (min 528.96, max 2157.89)"
    "bw_mem-cp-8mb (MB/s)","1375.33 (min 605.60, max 2145.06)"
    "bw_mem-fcp-16mb (MB/s)","772.61"
    "bw_mem-fcp-1mb (MB/s)","1456.11 (min 801.03, max 2111.19)"
    "bw_mem-fcp-2mb (MB/s)","1473.70 (min 831.37, max 2116.03)"
    "bw_mem-fcp-4mb (MB/s)","1492.37 (min 867.58, max 2117.15)"
    "bw_mem-fcp-8mb (MB/s)","1492.57 (min 915.54, max 2069.59)"
    "bw_mem-frd-16mb (MB/s)","1368.69"
    "bw_mem-frd-1mb (MB/s)","1060.77 (min 801.03, max 1320.51)"
    "bw_mem-frd-2mb (MB/s)","1087.05 (min 831.37, max 1342.73)"
    "bw_mem-frd-4mb (MB/s)","1114.53 (min 867.58, max 1361.47)"
    "bw_mem-frd-8mb (MB/s)","1148.86 (min 915.54, max 1382.17)"
    "bw_mem-fwr-16mb (MB/s)","2120.33"
    "bw_mem-fwr-1mb (MB/s)","1795.98 (min 1320.51, max 2271.44)"
    "bw_mem-fwr-2mb (MB/s)","1761.48 (min 1342.73, max 2180.23)"
    "bw_mem-fwr-4mb (MB/s)","1759.68 (min 1361.47, max 2157.89)"
    "bw_mem-fwr-8mb (MB/s)","1763.62 (min 1382.17, max 2145.06)"
    "bw_mem-rd-16mb (MB/s)","1381.33"
    "bw_mem-rd-1mb (MB/s)","713.86 (min 661.55, max 766.17)"
    "bw_mem-rd-2mb (MB/s)","774.72 (min 723.33, max 826.10)"
    "bw_mem-rd-4mb (MB/s)","1092.66 (min 817.33, max 1367.99)"
    "bw_mem-rd-8mb (MB/s)","1126.60 (min 880.28, max 1372.92)"
    "bw_mem-rdwr-16mb (MB/s)","860.17"
    "bw_mem-rdwr-1mb (MB/s)","677.64 (min 526.22, max 829.05)"
    "bw_mem-rdwr-2mb (MB/s)","655.67 (min 529.17, max 782.17)"
    "bw_mem-rdwr-4mb (MB/s)","651.25 (min 528.96, max 773.54)"
    "bw_mem-rdwr-8mb (MB/s)","736.55 (min 605.60, max 867.49)"
    "bw_mem-wr-16mb (MB/s)","912.30"
    "bw_mem-wr-1mb (MB/s)","797.61 (min 766.17, max 829.05)"
    "bw_mem-wr-2mb (MB/s)","804.14 (min 782.17, max 826.10)"
    "bw_mem-wr-4mb (MB/s)","795.44 (min 773.54, max 817.33)"
    "bw_mem-wr-8mb (MB/s)","873.89 (min 867.49, max 880.28)"
    "bw_mmap_rd-mo-1mb (MB/s)","1274.81"
    "bw_mmap_rd-o2c-1mb (MB/s)","482.16"
    "bw_pipe (MB/s)","288.15"
    "bw_unix (MB/s)","655.38"
    "lat_connect (us)","78.52"
    "lat_ctx-2-128k (us)","5.91"
    "lat_ctx-2-256k (us)","4.78"
    "lat_ctx-4-128k (us)","8.77"
    "lat_ctx-4-256k (us)","1.70"
    "lat_fs-0k (num_files)","203.00"
    "lat_fs-10k (num_files)","83.00"
    "lat_fs-1k (num_files)","128.00"
    "lat_fs-4k (num_files)","144.00"
    "lat_mem_rd-stride128-sz1000k (ns)","47.13"
    "lat_mem_rd-stride128-sz125k (ns)","7.83"
    "lat_mem_rd-stride128-sz250k (ns)","12.73"
    "lat_mem_rd-stride128-sz31k (ns)","5.12"
    "lat_mem_rd-stride128-sz50 (ns)","3.01"
    "lat_mem_rd-stride128-sz500k (ns)","43.70"
    "lat_mem_rd-stride128-sz62k (ns)","7.38"
    "lat_mmap-1m (us)","76.00"
    "lat_ops-double-add (ns)","0.73"
    "lat_ops-double-mul (ns)","4.02"
    "lat_ops-float-add (ns)","0.73"
    "lat_ops-float-mul (ns)","4.02"
    "lat_ops-int-add (ns)","1.01"
    "lat_ops-int-bit (ns)","0.67"
    "lat_ops-int-div (ns)","6.04"
    "lat_ops-int-mod (ns)","6.40"
    "lat_ops-int-mul (ns)","3.05"
    "lat_ops-int64-add (ns)","1.01"
    "lat_ops-int64-bit (ns)","0.67"
    "lat_ops-int64-div (ns)","9.56"
    "lat_ops-int64-mod (ns)","7.40"
    "lat_pagefault (us)","2.20"
    "lat_pipe (us)","20.85"
    "lat_proc-exec (us)","1506.50"
    "lat_proc-fork (us)","1345.25"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","43.79"
    "lat_sem (us)","2.48"
    "lat_sig-catch (us)","7.94"
    "lat_sig-install (us)","0.84"
    "lat_sig-prot (us)","0.55"
    "lat_syscall-fstat (us)","2.10"
    "lat_syscall-null (us)","0.36"
    "lat_syscall-open (us)","395.79"
    "lat_syscall-read (us)","0.93"
    "lat_syscall-stat (us)","5.53"
    "lat_syscall-write (us)","0.61"
    "lat_tcp (us)","0.70"
    "lat_unix (us)","41.81"
    "latency_for_0.50_mb_block_size (nanosec)","43.70"
    "latency_for_1.00_mb_block_size (nanosec)","23.57 (min 0.00, max 47.13)"
    "pipe_bandwidth (MBs)","288.15"
    "pipe_latency (microsec)","20.85"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","43.79"
    "semaphore_latency (microsec)","2.48"
    "signal_handler_latency (microsec)","0.84"
    "signal_handler_overhead (microsec)","7.94"
    "tcp_ip_connection_cost_to_localhost (microsec)","78.52"
    "tcp_latency_using_localhost (microsec)","0.70"


Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "cpu_clock (MHz)","1000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.99"
    "dhrystone_per_second (DhrystoneP)","5263158.00"


Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "whetstone (MIPS)","1000.00"


Table:  **Whetstone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
sloving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "linpack (Kflops)","391598.00"


Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "assignment (Iterations)","9.76"
    "fourier (Iterations)","16312.00"
    "fp_emulation (Iterations)","76.43"
    "huffman (Iterations)","837.28"
    "idea (Iterations)","2450.30"
    "lu_decomposition (Iterations)","391.56"
    "neural_net (Iterations)","5.60"
    "numeric_sort (Iterations)","359.48"
    "string_sort (Iterations)","118.26"


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
    :header: "Benchmarks","am64xx-evm: perf"

    "add (MB/s)","466.80"
    "copy (MB/s)","519.30"
    "scale (MB/s)","569.50"
    "triad (MB/s)","440.90"


Table:  **Stream**

CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "cjpeg-rose7-preset (workloads/)","6.31"
    "core (workloads/)","0.09"
    "coremark-pro ()","332.14"
    "linear_alg-mid-100x100-sp (workloads/)","10.46"
    "loops-all-mid-10k-sp (workloads/)","0.49"
    "nnet_test (workloads/)","0.78"
    "parser-125k (workloads/)","5.59"
    "radix2-big-64k (workloads/)","5.41"
    "sha-test (workloads/)","13.19"
    "zip-test (workloads/)","15.38"


Table:  **CoreMarkPro**

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "cjpeg-rose7-preset (workloads/)","49.02"
    "core (workloads/)","0.43"
    "coremark-pro ()","1011.02"
    "linear_alg-mid-100x100-sp (workloads/)","20.06"
    "loops-all-mid-10k-sp (workloads/)","0.88"
    "nnet_test (workloads/)","1.54"
    "parser-125k (workloads/)","6.45"
    "radix2-big-64k (workloads/)","31.21"
    "sha-test (workloads/)","93.46"
    "zip-test (workloads/)","28.99"


Table:  **CoreMarkPro for Two Cores**

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
    :header: "Benchmarks","am64xx-evm: perf"

    "4m-check (workloads/)","330.78"
    "4m-check-reassembly (workloads/)","61.65"
    "4m-check-reassembly-tcp (workloads/)","37.65"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","15.29"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","0.76"
    "4m-cmykw2 (workloads/)","87.07"
    "4m-cmykw2-rotatew2 (workloads/)","18.15"
    "4m-reassembly (workloads/)","50.45"
    "4m-rotatew2 (workloads/)","21.32"
    "4m-tcp-mixed (workloads/)","86.02"
    "4m-x264w2 (workloads/)","0.24"
    "empty-wld (workloads/)","1.00"
    "idct-4m (workloads/)","13.66"
    "idct-4mw1 (workloads/)","3.85"
    "ippktcheck-4m (workloads/)","329.90"
    "ippktcheck-4mw1 (workloads/)","89.47"
    "ipres-4m (workloads/)","68.52"
    "ipres-4mw1 (workloads/)","68.59"
    "md5-4m (workloads/)","19.95"
    "md5-4mw1 (workloads/)","4.07"
    "rgbcmyk-4m (workloads/)","44.16"
    "rgbcmyk-4mw1 (workloads/)","44.21"
    "rotate-4ms1 (workloads/)","16.91"
    "rotate-4ms1w1 (workloads/)","16.95"
    "rotate-4ms64 (workloads/)","17.20"
    "rotate-4ms64w1 (workloads/)","17.21"
    "x264-4mq (workloads/)","0.41"
    "x264-4mqw1 (workloads/)","0.41"


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

CPSW Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^

- AM65x, J7200, J721e: CPSW2g
- AM64x: CPSW3g

.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table::
    :header: "TCP Window Size","am64xx-evm: Throughput (Mbits/sec)","am64xx-evm: CPU Load %"

    "Default","1070.56","97.56"

Table: **CPSW TCP Bidirectional Throughput**

.. rubric::  UDP Throughput (0% loss) 
   :name: CPSW2g-udp-throughput-0-loss
   
.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes)","am64xx-evm: Throughput (Mbits/sec)","am64xx-evm: CPU Load %"

    "64","18.00","9.82","89.72"
    "128","82.00","37.75","86.08"
    "256","210.00","117.21","88.69"
    "512","466.00","87.53","34.47"
    "1024","978.00","517.58","91.11"
    "1280","1234.00","614.84","90.96"
    "1518","1472.00","561.33","81.58"

Table: **CPSW UDP Egress Throughput (0% loss)**
   
.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes)","am64xx-evm: Throughput (Mbits/sec)","am64xx-evm: CPU Load %"

    "64","18.00","1.15","11.26"
    "128","82.00","6.56","17.32"
    "256","210.00","16.46","8.26"
    "512","466.00","37.65","8.46"
    "1024","978.00","81.37","10.00"
    "1280","1234.00","103.65","17.13"
    "1518","1472.00","123.64","17.91"

Table: **CPSW UDP Ingress Throughput (0% loss)**

.. rubric::  UDP Throughput (possible loss) 
   :name: CPSW2g-udp-throughput-possible-loss

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes)","am64xx-evm: Throughput (Mbits/sec)","am64xx-evm: CPU Load %","am64xx-evm: Packet Loss %"

    "64","18.00","9.82","89.72","0.00"
    "128","82.00","37.75","86.08","0.00"
    "256","210.00","117.21","88.69","0.00"
    "512","466.00","87.53","34.47","0.00"
    "1024","978.00","517.58","91.11","0.00"
    "1280","1234.00","614.84","90.96","0.00"
    "1518","1472.00","561.33","81.58","0.00"

Table: **CPSW UDP Egress Throughput (possible loss)**

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes)","am64xx-evm: Throughput (Mbits/sec)","am64xx-evm: CPU Load %","am64xx-evm: Packet Loss %"

    "64","18.00","18.41","76.61","55.38"
    "128","82.00","83.98","78.33","54.91"
    "256","210.00","210.20","80.36","52.82"
    "512","466.00","460.51","81.91","47.42"
    "1024","978.00","922.94","84.20","1.21"
    "1280","1234.00","943.04","84.71","0.64"
    "1518","1472.00","942.31","83.96","1.54"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|

ICSSG Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput 
   :name: tcp-bidirectional-throughput


Table: **ICSSG TCP Bidirectional Throughput**

.. rubric::  UDP Throughput (0% loss) 
   :name: udp-throughput-0-loss
   

Table: **ICSSG UDP Egress Throughput (0% loss)**
   

Table: **ICSSG UDP Ingress Throughput (0% loss)**

.. rubric::  UDP Throughput (possible loss) 
   :name: udp-throughput-possible-loss


Table: **ICSSG UDP Egress Throughput (possible loss)**


Table: **ICSSG UDP Ingress Throughput (possible loss)**

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

AM64xx-EVM
"""""""""""""""""""""""""""




.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","352.00","91.40","390.00","86.89"
    "4m","353.00","95.64","397.00","89.48"
    "4k","31.80","98.21","39.00","96.47"
    "256k","276.00","95.33","339.00","84.80"



- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x1
- SSD being used: Lite-On Technology Corporation M8Pe Series NVMe SSD [14a4:22f1] (rev 01)



NAND Driver
-------------------------










OSPI Flash Driver
-------------------------



AM64XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^






RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","am64xx-evm: Raw Read Throughput (Mbytes/sec)"

    "50","33.11"






















QSPI Flash Driver
-------------------------


















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





















AM64XX-EVM
"""""""""""""""""""""""""""""""
|



.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","37.90","7.83","38.60","7.16"
    "4m","38.10","6.44","38.90","6.43"
    "4k","17.60","34.65","17.70","28.36"
    "256k","36.40","9.30","37.10","8.96"

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

