.. http://processors.wiki.ti.com/index.php/CoreSDK_Linux_Kernel_Performance_Guide

======================================
 Linux 07.00.00 Performance Guide
======================================

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
    :header: "Benchmarks","j721e-idk-gw: perf"

    "af_unix_sock_stream_latency (microsec)","16.16"
    "af_unix_socket_stream_bandwidth (MBs)","2512.89"
    "bw_file_rd-io-1mb (MB/s)","4927.91"
    "bw_file_rd-o2c-1mb (MB/s)","2649.01"
    "bw_mem-bcopy-16mb (MB/s)","3142.80"
    "bw_mem-bcopy-1mb (MB/s)","6977.99"
    "bw_mem-bcopy-2mb (MB/s)","3825.42"
    "bw_mem-bcopy-4mb (MB/s)","3313.45"
    "bw_mem-bcopy-8mb (MB/s)","3155.40"
    "bw_mem-bzero-16mb (MB/s)","8926.08"
    "bw_mem-bzero-1mb (MB/s)","9273.52 (min 6977.99, max 11569.05)"
    "bw_mem-bzero-2mb (MB/s)","7628.12 (min 3825.42, max 11430.82)"
    "bw_mem-bzero-4mb (MB/s)","6833.95 (min 3313.45, max 10354.44)"
    "bw_mem-bzero-8mb (MB/s)","6170.88 (min 3155.40, max 9186.35)"
    "bw_mem-cp-16mb (MB/s)","1135.64"
    "bw_mem-cp-1mb (MB/s)","6844.27 (min 2163.23, max 11525.30)"
    "bw_mem-cp-2mb (MB/s)","7020.75 (min 2612.92, max 11428.57)"
    "bw_mem-cp-4mb (MB/s)","5786.25 (min 1263.22, max 10309.28)"
    "bw_mem-cp-8mb (MB/s)","5157.82 (min 1144.33, max 9171.31)"
    "bw_mem-fcp-16mb (MB/s)","3182.81"
    "bw_mem-fcp-1mb (MB/s)","9112.16 (min 6655.26, max 11569.05)"
    "bw_mem-fcp-2mb (MB/s)","7541.14 (min 3651.45, max 11430.82)"
    "bw_mem-fcp-4mb (MB/s)","6817.10 (min 3279.76, max 10354.44)"
    "bw_mem-fcp-8mb (MB/s)","6186.80 (min 3187.25, max 9186.35)"
    "bw_mem-frd-16mb (MB/s)","6681.51"
    "bw_mem-frd-1mb (MB/s)","6515.93 (min 6376.59, max 6655.26)"
    "bw_mem-frd-2mb (MB/s)","4849.16 (min 3651.45, max 6046.86)"
    "bw_mem-frd-4mb (MB/s)","5100.76 (min 3279.76, max 6921.75)"
    "bw_mem-frd-8mb (MB/s)","4946.52 (min 3187.25, max 6705.78)"
    "bw_mem-fwr-16mb (MB/s)","8909.93"
    "bw_mem-fwr-1mb (MB/s)","8950.95 (min 6376.59, max 11525.30)"
    "bw_mem-fwr-2mb (MB/s)","8737.72 (min 6046.86, max 11428.57)"
    "bw_mem-fwr-4mb (MB/s)","8615.52 (min 6921.75, max 10309.28)"
    "bw_mem-fwr-8mb (MB/s)","7938.55 (min 6705.78, max 9171.31)"
    "bw_mem-rd-16mb (MB/s)","6891.60"
    "bw_mem-rd-1mb (MB/s)","12209.09 (min 10514.24, max 13903.94)"
    "bw_mem-rd-2mb (MB/s)","5868.59 (min 5518.76, max 6218.42)"
    "bw_mem-rd-4mb (MB/s)","5076.22 (min 2835.37, max 7317.07)"
    "bw_mem-rd-8mb (MB/s)","4153.18 (min 1614.04, max 6692.32)"
    "bw_mem-rdwr-16mb (MB/s)","1533.15"
    "bw_mem-rdwr-1mb (MB/s)","4980.94 (min 2163.23, max 7798.65)"
    "bw_mem-rdwr-2mb (MB/s)","3197.47 (min 2612.92, max 3782.02)"
    "bw_mem-rdwr-4mb (MB/s)","1974.80 (min 1263.22, max 2686.37)"
    "bw_mem-rdwr-8mb (MB/s)","1432.11 (min 1144.33, max 1719.88)"
    "bw_mem-wr-16mb (MB/s)","1443.39"
    "bw_mem-wr-1mb (MB/s)","10851.30 (min 7798.65, max 13903.94)"
    "bw_mem-wr-2mb (MB/s)","4650.39 (min 3782.02, max 5518.76)"
    "bw_mem-wr-4mb (MB/s)","2760.87 (min 2686.37, max 2835.37)"
    "bw_mem-wr-8mb (MB/s)","1666.96 (min 1614.04, max 1719.88)"
    "bw_mmap_rd-mo-1mb (MB/s)","12490.82"
    "bw_mmap_rd-o2c-1mb (MB/s)","3477.94"
    "bw_pipe (MB/s)","3878.38"
    "bw_unix (MB/s)","2512.89"
    "lat_connect (us)","23.94"
    "lat_ctx-2-128k (us)","2.95"
    "lat_ctx-2-256k (us)","3.28"
    "lat_ctx-4-128k (us)","4.01"
    "lat_ctx-4-256k (us)","4.23"
    "lat_fs-0k (num_files)","792.00"
    "lat_fs-10k (num_files)","211.00"
    "lat_fs-1k (num_files)","203.00"
    "lat_fs-4k (num_files)","193.00"
    "lat_mem_rd-stride128-sz1000k (ns)","7.58"
    "lat_mem_rd-stride128-sz125k (ns)","5.15"
    "lat_mem_rd-stride128-sz250k (ns)","5.15"
    "lat_mem_rd-stride128-sz31k (ns)","2.00"
    "lat_mem_rd-stride128-sz50 (ns)","2.00"
    "lat_mem_rd-stride128-sz500k (ns)","5.16"
    "lat_mem_rd-stride128-sz62k (ns)","5.15"
    "lat_mmap-1m (us)","8.14"
    "lat_ops-double-add (ns)","0.32"
    "lat_ops-double-mul (ns)","2.00"
    "lat_ops-float-add (ns)","0.32"
    "lat_ops-float-mul (ns)","2.00"
    "lat_ops-int-add (ns)","0.50"
    "lat_ops-int-bit (ns)","0.33"
    "lat_ops-int-div (ns)","4.00"
    "lat_ops-int-mod (ns)","4.67"
    "lat_ops-int-mul (ns)","1.52"
    "lat_ops-int64-add (ns)","0.50"
    "lat_ops-int64-bit (ns)","0.33"
    "lat_ops-int64-div (ns)","3.00"
    "lat_ops-int64-mod (ns)","5.67"
    "lat_pagefault (us)","1.12"
    "lat_pipe (us)","8.50"
    "lat_proc-exec (us)","511.33"
    "lat_proc-fork (us)","480.64"
    "lat_proc-proccall (us)","0.00"
    "lat_select (us)","11.54"
    "lat_sem (us)","1.10"
    "lat_sig-catch (us)","2.15"
    "lat_sig-install (us)","0.40"
    "lat_sig-prot (us)","0.35"
    "lat_syscall-fstat (us)","0.56"
    "lat_syscall-null (us)","0.25"
    "lat_syscall-open (us)","124.60"
    "lat_syscall-read (us)","0.41"
    "lat_syscall-stat (us)","1.38"
    "lat_syscall-write (us)","0.32"
    "lat_tcp (us)","0.50"
    "lat_unix (us)","16.16"
    "latency_for_0.50_mb_block_size (nanosec)","5.16"
    "latency_for_1.00_mb_block_size (nanosec)","3.79 (min 0.00, max 7.58)"
    "pipe_bandwidth (MBs)","3878.38"
    "pipe_latency (microsec)","8.50"
    "procedure_call (microsec)","0.00"
    "select_on_200_tcp_fds (microsec)","11.54"
    "semaphore_latency (microsec)","1.10"
    "signal_handler_latency (microsec)","0.40"
    "signal_handler_overhead (microsec)","2.15"
    "tcp_ip_connection_cost_to_localhost (microsec)","23.94"
    "tcp_latency_using_localhost (microsec)","0.50"


Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.
  
.. csv-table::
    :header: "Benchmarks","j721e-idk-gw: perf"

    "cpu_clock (MHz)","400.00"
    "dhrystone_per_mhz (DMIPS/MHz)","28.50"
    "dhrystone_per_second (DhrystoneP)","20000000.00"


Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","j721e-idk-gw: perf"

    "whetstone (MIPS)","10000.00"


Table:  **Whetstone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
sloving a dense linear system.

.. csv-table::
    :header: "Benchmarks","j721e-idk-gw: perf"

    "linpack (Kflops)","2651223.00"


Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","j721e-idk-gw: perf"

    "assignment (Iterations)","29.69"
    "fourier (Iterations)","48965.00"
    "fp_emulation (Iterations)","250.04"
    "huffman (Iterations)","2424.50"
    "idea (Iterations)","7997.20"
    "lu_decomposition (Iterations)","1431.30"
    "neural_net (Iterations)","27.34"
    "numeric_sort (Iterations)","879.57"
    "string_sort (Iterations)","431.63"


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
    :header: "Benchmarks","j721e-idk-gw: perf"

    "add (MB/s)","6641.00"
    "copy (MB/s)","6481.40"
    "scale (MB/s)","6410.50"
    "triad (MB/s)","6635.20"


Table:  **Stream**

CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.

.. csv-table::
    :header: "Benchmarks","j721e-idk-gw: perf"

    "cjpeg-rose7-preset (workloads/)","83.33"
    "core (workloads/)","0.78"
    "coremark-pro ()","2571.70"
    "linear_alg-mid-100x100-sp (workloads/)","82.51"
    "loops-all-mid-10k-sp (workloads/)","2.50"
    "nnet_test (workloads/)","3.67"
    "parser-125k (workloads/)","12.05"
    "radix2-big-64k (workloads/)","281.29"
    "sha-test (workloads/)","158.73"
    "zip-test (workloads/)","52.63"


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
    :header: "Boot Configuration","j721e-idk-gw: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","16.25 (min 16.16, max 16.38)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","7.68 (min 7.67, max 7.72)"

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
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "11025","352800.00","0.05"
    "16000","512000.00","0.07"
    "22050","705600.00","0.24"
    "24000","705600.00","0.25"
    "32000","1024000.00","0.10"
    "44100","1411199.00","0.16"
    "48000","1535999.00","0.19"
    "88200","2822396.00","0.89"
    "96000","3071996.00","0.33"

Table:  **Audio Capture**

|

.. csv-table::
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "11025","352945.00","0.05"
    "16000","512211.00","0.06"
    "22050","705891.00","0.09"
    "24000","705891.00","0.24"
    "32000","1024422.00","0.13"
    "44100","1411781.00","0.46"
    "48000","1536633.00","0.19"
    "88200","2823561.00","0.91"
    "96000","3073264.00","0.29"

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


.. csv-table::
    :header: "Mode","j721e-idk-gw: Fps"

    "1024x576\@60","59.96 (min 58.98, max 60.02)"
    "1024x768\@60","59.97 (min 58.98, max 60.02)"
    "1024x768\@75","75.01 (min 73.82, max 75.11)"
    "1152x864\@75","74.98 (min 73.80, max 75.04)"
    "1280x1024\@75","75.12 (min 73.92, max 75.20)"
    "1280x720\@60","59.98 (min 58.99, max 60.02)"
    "1280x800\@60","59.82 (min 58.84, max 60.19)"
    "1360x768\@20","20.38 (min 20.38, max 20.39)"
    "1360x768\@60","59.93 (min 58.95, max 59.97)"
    "1440x480\@60","60.00 (min 59.03, max 60.05)"
    "1600x1200\@60","60.00 (min 59.98, max 60.02)"
    "1600x900\@60","60.00 (min 59.97, max 60.03)"
    "1680x1050\@60","59.93 (min 58.96, max 60.22)"
    "1920x1080\@53","52.69 (min 52.66, max 52.72)"
    "2048x1536\@17","17.19"
    "2560x1440\@15","14.85 (min 14.85, max 14.86)"
    "2560x1600\@13","13.41"
    "2880x1800\@11","10.70"
    "3840x2160\@15","14.62 (min 14.62, max 14.63)"
    "4088x2304\@10","10.18 (min 10.17, max 10.18)"
    "640x480\@60","59.95 (min 58.90, max 60.51)"
    "640x480\@75","74.93 (min 73.73, max 75.07)"
    "720x400\@70","70.07 (min 68.93, max 70.56)"
    "800x600\@60","60.31 (min 59.33, max 60.50)"
    "800x600\@75","74.95 (min 73.73, max 75.19)"
    "832x624\@75","74.48 (min 73.29, max 74.57)"

Table:  **Display performance (HDMI)**


|


.. csv-table::
    :header: "Mode","j721e-idk-gw: Fps"

    "1024x768\@60","59.98 (min 59.01, max 60.02)"
    "1024x768\@70","70.06 (min 68.91, max 70.18)"
    "1024x768\@75","75.03 (min 73.78, max 75.40)"
    "1280x1024\@60","60.00 (min 59.04, max 60.05)"
    "1280x1024\@75","75.12 (min 73.62, max 75.90)"
    "1280x720\@50","49.99 (min 49.98, max 50.01)"
    "1280x720\@60","59.98 (min 59.01, max 60.01)"
    "1280x960\@60","60.00 (min 59.97, max 60.03)"
    "1440x900\@60","59.86 (min 58.89, max 59.89)"
    "1680x1050\@60","59.94 (min 59.91, max 59.98)"
    "1920x1080\@50","49.99 (min 49.98, max 50.00)"
    "1920x1080\@60","59.98 (min 59.00, max 60.03)"
    "1920x2160\@60","60.00 (min 59.02, max 60.03)"
    "2560x1440\@60","59.98 (min 59.95, max 60.16)"
    "3840x2160\@30","30.01 (min 30.00, max 30.02)"
    "3840x2160\@60","59.93 (min 58.96, max 59.96)"
    "640x480\@60","60.00 (min 59.72, max 60.27)"
    "640x480\@67","66.63 (min 65.57, max 66.86)"
    "640x480\@73","72.80 (min 71.39, max 73.01)"
    "640x480\@75","74.98 (min 73.78, max 75.51)"
    "720x400\@70","70.07 (min 68.94, max 70.11)"
    "720x480\@60","59.99 (min 59.02, max 60.04)"
    "720x576\@50","50.00 (min 49.87, max 50.13)"
    "800x600\@56","56.25 (min 56.23, max 56.27)"
    "800x600\@60","60.29 (min 59.31, max 60.36)"
    "800x600\@72","72.17 (min 71.00, max 72.21)"
    "800x600\@75","74.94 (min 73.73, max 75.03)"
    "832x624\@75","74.50 (min 73.27, max 74.55)"

Table:  **Display performance (HDMI)**


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
    :header: "Benchmark","j721e-idk-gw: Test Number","j721e-idk-gw: Fps"

    "GLB25_EgyptTestC24Z16_ETC1_Offscreen test","2501011.00","57.00"
    "GLB25_EgyptTestStandardOffscreen_inherited test","2000010.00","142.00"


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

.. csv-table::
    :header: "Benchmark","j721e-idk-gw: Score","j721e-idk-gw: Fps"

    " GFXBench 3.x gl_manhattan_off","1064.25","17.17"
    " GFXBench 3.x gl_trex_off","1828.30","32.65"
    " GFXBench 4.x gl_4_off","346.34","5.86"
    " GFXBench 5.x gl_5_high_off","167.57","2.61"


Table:  **GFXBench**

Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","j721e-idk-gw: Score"

    "Glmark2-Wayland","952.00"


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
    :header: "Resolution","j721e-idk-gw: Fps","j721e-idk-gw: IVA Freq (MHz)","j721e-idk-gw: IPU Freq (MHz)"

    "1080i","30300.00","",""
    "1080p","60.00","",""
    "720p","59940.00","",""
    "720x480","24.17","",""
    "800x480","30.00","",""

Table:  **Gstreamer H264 in AVI Container Decode Performance**

|

MPEG4
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Resolution","j721e-idk-gw: Fps","j721e-idk-gw: IVA Freq (MHz)","j721e-idk-gw: IPU Freq (MHz)"

    "CIF","30.00","",""


Table:  **GStreamer MPEG4 in 3GP Container Decode Performance**

|

MPEG2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Resolution","j721e-idk-gw: Fps","j721e-idk-gw: IVA Freq (MHz)","j721e-idk-gw: IPU Freq (MHz)"

    "720p","29.97","",""


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
    :header: "TCP Window Size","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %"

    "Default","1764.11","24.58"

Table: **CPSW2g TCP Bidirectional Throughput**

.. rubric::  UDP Throughput (0% loss) 
   :name: udp-throughput-0-loss
   
.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes)","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %","j721e-idk-gw: Packets Per Second (KPPS)"

    "64","18.00","20.09","49.47","140.00"
    "128","82.00","224.33","62.59","342.00"
    "256","210.00","563.25","63.24","335.00"
    "1024","978.00","935.71","47.39","120.00"
    "1518","1472.00","956.56","22.91","81.00"

Table: **CPSW2g UDP Egress Throughput (0% loss)**
   
.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes)","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %","j721e-idk-gw: Packets Per Second (KPPS)"

    "64","18.00","11.16","19.49","78.00"
    "128","82.00","56.55","22.47","86.00"
    "256","210.00","170.18","27.04","101.00"
    "1024","978.00","936.76","79.77","120.00"
    "1518","1472.00","957.08","54.51","81.00"

Table: **CPSW2g UDP Ingress Throughput (0% loss)**

.. rubric::  UDP Throughput (possible loss) 
:name: udp-throughput-possible-loss

.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes)","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %","j721e-idk-gw: Packets Per Second (KPPS)","j721e-idk-gw: Packet Loss %"

    "64","18.00","37.00","96.85","257.00","0.01"
    "128","82.00","224.33","62.59","342.00","0.00"
    "256","210.00","563.25","63.24","335.00","0.00"
    "1024","978.00","935.71","47.39","120.00","0.00"
    "1518","1472.00","956.56","22.91","81.00","0.00"

Table: **CPSW2g UDP Egress Throughput (possible loss)**

.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes)","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %","j721e-idk-gw: Packets Per Second (KPPS)","j721e-idk-gw: Packet Loss %"

    "64","18.00","42.22","82.71","293.00","46.47"
    "128","82.00","192.65","83.61","294.00","34.28"
    "256","210.00","500.40","84.09","298.00","21.69"
    "1024","978.00","936.76","79.77","120.00","0.00"
    "1518","1472.00","957.08","54.51","81.00","0.00"

Table: **CPSW2g UDP Ingress Throughput (possible loss)**

|

CPSW9g Virtual Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput 
   :name: tcp-bidirectional-throughput

.. csv-table::
    :header: "TCP Window Size","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %"

    "Default","1845.31","75.75"

Table: **CPSW9g TCP Bidirectional Throughput**

.. rubric::  UDP Throughput (0% loss) 
   :name: udp-throughput-0-loss
   
.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes)","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %","j721e-idk-gw: Packets Per Second (KPPS)"

    "64","18.00","43.05","85.32","299.00"
    "128","82.00","135.33","58.92","206.00"
    "256","210.00","278.71","45.79","166.00"
    "1024","978.00","936.65","46.49","120.00"
    "1518","1472.00","956.99","33.11","81.00"

Table: **CPSW9g UDP Egress Throughput (0% loss)**
   
.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes)","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %","j721e-idk-gw: Packets Per Second (KPPS)"

    "64","18.00","4.02","7.53","28.00"
    "128","82.00","29.91","11.11","46.00"
    "256","210.00","90.04","12.97","54.00"
    "1024","978.00","929.25","62.48","119.00"
    "1518","1472.00","949.91","42.96","81.00"

Table: **CPSW9g UDP Ingress Throughput (0% loss)**

.. rubric::  UDP Throughput (possible loss) 
:name: udp-throughput-possible-loss

.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes)","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %","j721e-idk-gw: Packets Per Second (KPPS)","j721e-idk-gw: Packet Loss %"

    "64","18.00","46.00","95.80","319.00","0.09"
    "128","82.00","215.83","95.71","329.00","0.24"
    "256","210.00","540.57","96.19","322.00","0.30"
    "1024","978.00","936.65","46.90","120.00","0.00"
    "1518","1472.00","956.99","32.46","81.00","0.00"

Table: **CPSW9g UDP Egress Throughput (possible loss)**

.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes)","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %","j721e-idk-gw: Packets Per Second (KPPS)","j721e-idk-gw: Packet Loss %"

    "64","18.00","43.59","82.01","303.00","59.47"
    "128","82.00","194.51","82.21","297.00","61.57"
    "256","210.00","494.50","82.76","294.00","33.29"
    "1024","978.00","929.24","62.55","119.00","0.00"
    "1518","1472.00","949.90","41.74","81.00","0.00"

Table: **CPSW9g UDP Ingress Throughput (possible loss)**

|

PCIe Driver
-------------------------

PCIe-ETH
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "TCP Window Size(Kbytes)","j721e-idk-gw: Bandwidth (Mbits/sec)"

    "128","1319.20"
    "256","1424.00"

Table: **PCI Ethernet**

PCIe-EP
^^^^^^^^^^^^^^^^^^^^^^^^^^^














PCIe-NVMe-SSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^









J721E-IDK-GW
"""""""""""""""""""""""""""





    .. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","460.00","4.97","1214.00","3.39"
    "4m","461.00","7.85","1243.00","2.59"
    "4k","233.00","47.83","168.00","36.31"
    "256k","452.00","3.61","1226.00","6.56"




- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY


NAND Driver
-------------------------










QSPI Flash Driver
-------------------------




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
UBIFS
"""""""""""""""""""""""""""
.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write UBIFS Throughput (Mbytes/sec)","j721e-idk-gw: Write UBIFS CPU Load (%)","j721e-idk-gw: Read UBIFS Throughput (Mbytes/sec)","j721e-idk-gw: Read UBIFS CPU Load (%)"

    "102400","0.57 (min 0.46, max 0.97)","22.78 (min 20.02, max 26.14)","69.84","33.33"
    "262144","0.42 (min 0.31, max 0.48)","22.62 (min 21.62, max 23.84)","70.25","50.00"
    "524288","0.41 (min 0.29, max 0.50)","22.21 (min 21.14, max 23.41)","69.27","42.86"
    "1048576","0.44 (min 0.33, max 0.49)","23.53 (min 21.11, max 25.67)","68.96","33.33"




RAW
"""""""""""""""""""""""""""
.. csv-table::
    :header: "File size (Mbytes)","j721e-idk-gw: Raw Read Throughput (Mbytes/sec)"

    "50","277.78"






















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




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|



.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","95.90","2.13","1068.00","17.42"
    "4m","95.10","2.78","938.00","19.72"
    "4k","143.00","42.07","342.00","67.70"
    "256k","97.50","1.22","1224.00","10.49"

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



J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|



.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","57.80","0.84","313.00","0.87"
    "4m","57.00","1.07","312.00","0.74"
    "4k","53.50","20.51","56.30","20.00"
    "256k","58.50","0.70","312.00","2.14"

|




Jailhouse Hypervisor Performance (Inmate Cell)
""""""""""""""""""""""""""""""""""""""""""""""""
|



.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write VFAT Throughput (Mbytes/sec)","j721e-idk-gw: Write VFAT CPU Load (%)","j721e-idk-gw: Read VFAT Throughput (Mbytes/sec)","j721e-idk-gw: Read VFAT CPU Load (%)"

    "102400","57.37 (min 53.02, max 58.69)","6.57 (min 5.03, max 11.68)","270.75","13.51"
    "262144","57.42 (min 53.14, max 58.65)","6.49 (min 4.52, max 11.28)","276.31","13.89"
    "524288","57.96 (min 53.75, max 59.11)","6.66 (min 4.55, max 11.86)","282.01","18.42"
    "1048576","58.02 (min 54.18, max 59.32)","6.81 (min 4.49, max 13.78)","286.81","16.67"
    "5242880","57.72 (min 53.81, max 58.80)","6.65 (min 5.06, max 10.88)","289.27","18.92"

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




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|



.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","8.24","0.54","74.70","1.11"
    "4m","8.19","0.58","74.10","1.54"
    "4k","1.32","1.09","4.98","2.35"
    "256k","7.92","0.50","72.00","0.92"

|




Jailhouse Hypervisor Performance (Root Cell)
""""""""""""""""""""""""""""""""""""""""""""""""
|



.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write VFAT Throughput (Mbytes/sec)","j721e-idk-gw: Write VFAT CPU Load (%)","j721e-idk-gw: Read VFAT Throughput (Mbytes/sec)","j721e-idk-gw: Read VFAT CPU Load (%)"

    "102400","26.35 (min 13.94, max 35.38)","4.12 (min 3.53, max 4.65)","41.31","4.74"
    "262144","31.61 (min 20.19, max 37.21)","5.25 (min 2.89, max 9.00)","42.10","3.67"
    "524288","31.17 (min 20.06, max 37.36)","5.21 (min 2.69, max 9.51)","43.70","4.58"
    "1048576","31.53 (min 19.48, max 37.79)","5.02 (min 2.79, max 8.73)","44.17","5.42"
    "5242880","32.53 (min 20.35, max 37.56)","5.17 (min 2.72, max 8.57)","44.14","5.04"

|





.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "102400","29.67 (min 25.41, max 37.10)","3.03 (min 1.70, max 5.30)","41.00","3.89"
    "262144","28.66 (min 26.94, max 32.00)","3.07 (min 1.79, max 4.16)","43.89","3.32"
    "524288","32.66 (min 31.01, max 38.11)","3.51 (min 2.66, max 4.74)","45.33","1.74"
    "1048576","31.94 (min 29.34, max 37.71)","3.42 (min 2.67, max 4.33)","45.74","2.61"
    "5242880","36.06 (min 31.14, max 37.99)","3.59 (min 2.99, max 4.15)","45.88","2.62"

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






























J721E-IDK-GW
"""""""""""""""""""""""""""""""
|



.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","416.00","5.22","412.00","1.76"
    "4m","417.00","7.33","413.00","1.51"
    "4k","61.60","28.10","61.60","26.38"
    "256k","411.00","4.33","410.00","3.20"

|






|

USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^


|
|

|
|

Table: **USBDEVICE SUPERSPEED CDC IPERF TCP THROUGHPUT**
.. csv-table::
    :header: "Window Size (kbytes)","j721e-idk-gw: TX Throughput (Mbits/sec)","j721e-idk-gw: RX Throughput (Mbits/sec)"

    "8","542.70","490.00"
    "16","563.20","577.00"
    "32","571.00","610.00"
    "64","589.00","619.00"
    "128","618.00","636.00"


|
|

|
|

Table: **USBDEVICE HIGHSPEED SLAVE READ THROUGHPUT**
.. csv-table::
    :header: "Number of Blocks","j721e-idk-gw: Throughput (MB/sec)"

    "150","44.20"


|
|

Table: **USBDEVICE HIGHSPEED SLAVE WRITE THROUGHPUT**
.. csv-table::
    :header: "Number of Blocks","j721e-idk-gw: Throughput (MB/sec)"

    "150","42.00"


|
|

Table: **USBDEVICE HIGHSPEED CDC IPERF TCP THROUGHPUT**
.. csv-table::
    :header: "Window Size (kbytes)","j721e-idk-gw: TX Throughput (Mbits/sec)","j721e-idk-gw: RX Throughput (Mbits/sec)"

    "8","199.30","278.00"
    "16","214.10","285.00"
    "32","242.30","310.00"
    "64","271.00","311.00"
    "128","313.00","317.00"


|
|

|
|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","j721e-idk-gw: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","53220.35"
    "aes-128-cbc","16","1024.11"
    "aes-128-cbc","16384","215613.44"
    "aes-128-cbc","256","79410.18"
    "aes-128-cbc","64","3918.42"
    "aes-128-cbc","8192","182280.19"
    "aes-192-cbc","1024","52644.18"
    "aes-192-cbc","16","1094.76"
    "aes-192-cbc","16384","195253.59"
    "aes-192-cbc","256","79408.47"
    "aes-192-cbc","64","3970.35"
    "aes-192-cbc","8192","163086.34"
    "aes-256-cbc","1024","51403.43"
    "aes-256-cbc","16","993.77"
    "aes-256-cbc","16384","184887.98"
    "aes-256-cbc","256","77505.54"
    "aes-256-cbc","64","4276.65"
    "aes-256-cbc","8192","160497.66"
    "des-cbc","1024","47439.19"
    "des-cbc","16384","50003.97"
    "des-cbc","256","40982.10"
    "des-cbc","8192","49771.86"
    "des3","1024","45158.40"
    "des3","16","1073.82"
    "des3","16384","101482.50"
    "des3","256","17880.83"
    "des3","64","3862.55"
    "des3","8192","93792.94"
    "md5","1024","89134.08"
    "md5","16","1980.24"
    "md5","16384","267468.80"
    "md5","256","28703.15"
    "md5","64","7646.14"
    "md5","8192","236265.47"
    "sha1","1024","27285.85"
    "sha1","16","497.56"
    "sha1","16384","134179.50"
    "sha1","256","13508.18"
    "sha1","64","1972.97"
    "sha224","16384","641171.46"
    "sha224","256","28860.16"
    "sha256","16384","147483.31"
    "sha384","1024","69970.94"
    "sha384","16","1807.14"
    "sha384","16384","161639.08"
    "sha384","256","25015.13"
    "sha384","64","7288.90"
    "sha384","8192","148692.99"
    "sha512","16384","178552.83"
    "sha512","8192","133581.48"


|
|

.. csv-table::
    :header: "Algorithm","j721e-idk-gw: CPU Load"

    "sha224","98.00"
    "sha384","98.00"



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




DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.

Power Management
-------------------------















