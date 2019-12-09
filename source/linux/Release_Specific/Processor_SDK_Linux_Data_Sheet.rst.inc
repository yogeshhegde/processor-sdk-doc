.. rubric::  **Read This First**
   :name: read-this-first

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

**NOTE: All performance measurements provided in this document are PRELIMINARY and have
not necessarily been fully optimized yet.  They are provided here as-is for this release.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| J721E EVM      | J721E Evaluation Module, SOM rev E6 with ARM running at 2GHz, DDR data rate 3733 MT/S, L3 Cache size 3MB,      |
|                | J721EXG01EVM                                                                                                   |
+----------------+----------------------------------------------------------------------------------------------------------------+

Table:  Evaluation Modules


.. rubric::  About This Manual
   :name: about-this-manual

This document provides a roadmap for benchmarks to be provided in this release
and future releases, as well as specific performance data for benchmarks, kernel
drivers and use-case examples provided as part of this release of the Processor
SDK Linux Automotive package.  This document should be used in conjunction
with release notes and user guides provided with the Processor SDK Linux
Automotive package for information on specific issues present with drivers
and other software included in a particular release.

.. rubric::  If You Need Assistance
   :name: if-you-need-assistance

For further information or to report any problems, contact
http://community.ti.com/ or http://support.ti.com/


Benchmarking Roadmap
*********************

The current plan for availability of benchmark measurements on the J721E EVM is shown in the table below.

.. csv-table::
    :header: "Domain","Feature","Benchmark Application","Metric","Target SDK"

    "MPU/A72","MIPS","CoreMark","Score","SDK6.0"
    "","","Dhrystone","Score","SDK6.0"
    "","","Nbench","Score","SDK6.0"
    "","","Whetstone","Score","SDK6.0"
    "","","Linpack","Score","SDK6.0"
    "","Multi-tasking","CoreMarkPro","Single core Score","SDK6.0"
    "","","","Multicore scaling","SDK6.0"
    "","","SpecInt2K6","Single core Score","SDK6.0"
    "","","","Multicore scaling","SDK6.0"
    "","","Multibench","Single core Score","SDK6.0"
    "","","","Multicore scaling","SDK6.0"
    "MSMC","L3 Cache","CoreMark Pro","Single core Score","SDK6.0"
    "","","","Multicore scaling","SDK6.0"
    "","","LMBench","Memory access latency","SDK6.0"
    "","","SpecInt2K6","Single core Score","SDK6.0"
    "","","","Multicore scaling","SDK6.0"
    "","I/O Coherence","Ethernet throughput","CPU Load (%)","SDK6.1"
    "","","","I/O throughput (GBps)","SDK6.1"
    "DSS7 & PAT","On-the-fly composition","Multi-layer composition","Resolution","SDK6.0"
    "","","","FPS","SDK6.0"
    "","","","CPU Load (%)","SDK6.0"
    "","","","Memory bandwidth (GBps)","SDK6.0"
    "Multimedia","HEVC 4K@60fps decoding","HEVC 4K stream decoding","Latency","SDK6.1"
    "","","","CPU Load (%)","SDK6.1"
    "","","","Memory Bandwidth (GBps)","SDK6.1"
    "","4x 1080p@60fps decoding","4-channel decoding","Latency","SDK6.1"
    "","","","CPU Load (%)","SDK6.1"
    "","","","Memory Bandwidth (GBps)","SDK6.1"
    "","H264 1080p@60fps encoding","1080p encoding","Latency","SDK6.1"
    "","","","CPU Load ","TBD"
    "","","","Memory Bandwidth","TBD"
    "","4x 720p@30fps Encoding","4-channel Encoding","Latency","TBD"
    "","","","CPU Load (%)","TBD"
    "","","","Memory Bandwidth (GBps)","TBD"
    "3D Graphics","GPU off screen rendering performance","GFXBench 3.0 Manhattan 1080p offscreen (fps)","FPS","SDK6.0"
    "","","","CPU Load (%)","SDK6.1"
    "","","","Memory Bandwidth (GBps)","SDK6.1"
    "","","GFXBench 3.1 Manhattan 1080p offscreen (fps)","FPS","SDK6.0"
    "","","","CPU Load (%)","SDK6.1"
    "","","","Memory Bandwidth (GBps)","SDK6.1"
    "","","GFXBench 4.0 Car Chase 1080p offscreen (fps)","FPS","SDK6.0"
    "","","","CPU Load (%)","SDK6.1"
    "","","","Memory Bandwidth (GBps)","SDK6.1"
    "","","GFXBench Trex OffScreen","FPS","SDK6.0"
    "","","","CPU Load (%)","SDK6.1"
    "","","","Memory Bandwidth (GBps)","SDK6.1"
    "","","Texture Read/Write","FPS","SDK6.2"
    "","","","Memory Bandwidth (GBps)","SDK6.2"
    "DDR/Interconnect","Throughput","STREAM","GBps","SDK6.0"
    "","","LMBench","GBps","SDK6.0"
    "","","udma mem<->mem xfers","GBps","SDK6.2"
    "","","DRU xfers","GBps","SDK6.2"
    "","ECC overhead","Synthetic application with ECC memory region","GBps","SDK6.2"
    "","","","% loss in performance","SDK6.2"
    "Boot-time Measurement","Cold boot to Linux prompt","Time measurement","seconds","SDK6.1"
    "Peripheral Performance Results","Throughput","Unit Test","Mbits/sec","SDK6.0"

Table:  **Benchmarking Release Plan**


Benchmarks
*********************

LMBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
LMBench is a collection of microbenchmarks of which the memory bandwidth 
and latency-related ones are typically used to estimate processor 
memory system performance.
  
**Latency**: lat_mem_rd-stride128-szN, where N is equal to or smaller than the cache
size at a given level, measures the cache miss penalty. N that is at least
double the size of last level cache is the latency to external memory.

**Bandwidth**: bw_mem_bcopy-N, where N is is equal to or smaller than the cache size at
a given level, measures the achievable memory bandwidth from software doing
a memcpy() type operation. Typical use is for external memory bandwidth
calculation. The bandwidth is calculated as byte read and written counts
as 1 which should be roughly half of STREAM copy result.

.. csv-table::
    :header: "Benchmarks","j721e-evm: perf"

    "af_unix_sock_stream_latency (microsec)","11.29"
    "af_unix_socket_stream_bandwidth (MBs)","2849.56"
    "bw_file_rd-io-1mb (MB/s)","4959.59"
    "bw_file_rd-o2c-1mb (MB/s)","2914.39"
    "bw_mem-bcopy-16mb (MB/s)","3196.16"
    "bw_mem-bcopy-1mb (MB/s)","6046.59"
    "bw_mem-bcopy-2mb (MB/s)","4056.80"
    "bw_mem-bcopy-4mb (MB/s)","3386.39"
    "bw_mem-bcopy-8mb (MB/s)","3190.64"
    "bw_mem-bzero-16mb (MB/s)","8956.06"
    "bw_mem-bzero-1mb (MB/s)","8407.49 (min 6046.59, max 10768.39)"
    "bw_mem-bzero-2mb (MB/s)","7240.76 (min 4056.80, max 10424.71)"
    "bw_mem-bzero-4mb (MB/s)","6578.58 (min 3386.39, max 9770.76)"
    "bw_mem-bzero-8mb (MB/s)","6210.45 (min 3190.64, max 9230.26)"
    "bw_mem-cp-16mb (MB/s)","1134.75"
    "bw_mem-cp-1mb (MB/s)","6321.01 (min 1878.13, max 10763.89)"
    "bw_mem-cp-2mb (MB/s)","6392.84 (min 2338.79, max 10446.89)"
    "bw_mem-cp-4mb (MB/s)","5533.59 (min 1270.65, max 9796.53)"
    "bw_mem-cp-8mb (MB/s)","5193.39 (min 1144.33, max 9242.45)"
    "bw_mem-fcp-16mb (MB/s)","3255.34"
    "bw_mem-fcp-1mb (MB/s)","8891.47 (min 7014.54, max 10768.39)"
    "bw_mem-fcp-2mb (MB/s)","7180.86 (min 3937.01, max 10424.71)"
    "bw_mem-fcp-4mb (MB/s)","6565.77 (min 3360.78, max 9770.76)"
    "bw_mem-fcp-8mb (MB/s)","6245.12 (min 3259.98, max 9230.26)"
    "bw_mem-frd-16mb (MB/s)","6707.66"
    "bw_mem-frd-1mb (MB/s)","6642.07 (min 6269.59, max 7014.54)"
    "bw_mem-frd-2mb (MB/s)","4858.16 (min 3937.01, max 5779.30)"
    "bw_mem-frd-4mb (MB/s)","5166.74 (min 3360.78, max 6972.69)"
    "bw_mem-frd-8mb (MB/s)","4998.70 (min 3259.98, max 6737.41)"
    "bw_mem-fwr-16mb (MB/s)","8956.06"
    "bw_mem-fwr-1mb (MB/s)","8516.74 (min 6269.59, max 10763.89)"
    "bw_mem-fwr-2mb (MB/s)","8113.10 (min 5779.30, max 10446.89)"
    "bw_mem-fwr-4mb (MB/s)","8384.61 (min 6972.69, max 9796.53)"
    "bw_mem-fwr-8mb (MB/s)","7989.93 (min 6737.41, max 9242.45)"
    "bw_mem-rd-16mb (MB/s)","7151.37"
    "bw_mem-rd-1mb (MB/s)","12469.51 (min 11214.63, max 13724.38)"
    "bw_mem-rd-2mb (MB/s)","5398.97 (min 3764.35, max 7033.59)"
    "bw_mem-rd-4mb (MB/s)","6074.99 (min 3723.01, max 8426.97)"
    "bw_mem-rd-8mb (MB/s)","4472.57 (min 1612.42, max 7332.72)"
    "bw_mem-rdwr-16mb (MB/s)","1529.05"
    "bw_mem-rdwr-1mb (MB/s)","4502.86 (min 1878.13, max 7127.58)"
    "bw_mem-rdwr-2mb (MB/s)","2482.81 (min 2338.79, max 2626.83)"
    "bw_mem-rdwr-4mb (MB/s)","2454.50 (min 1270.65, max 3638.35)"
    "bw_mem-rdwr-8mb (MB/s)","1420.79 (min 1144.33, max 1697.25)"
    "bw_mem-wr-16mb (MB/s)","1434.21"
    "bw_mem-wr-1mb (MB/s)","10425.98 (min 7127.58, max 13724.38)"
    "bw_mem-wr-2mb (MB/s)","3195.59 (min 2626.83, max 3764.35)"
    "bw_mem-wr-4mb (MB/s)","3680.68 (min 3638.35, max 3723.01)"
    "bw_mem-wr-8mb (MB/s)","1654.84 (min 1612.42, max 1697.25)"
    "bw_mmap_rd-mo-1mb (MB/s)","12495.41"
    "bw_mmap_rd-o2c-1mb (MB/s)","3616.29"
    "bw_pipe (MB/s)","4463.63"
    "bw_unix (MB/s)","2849.56"
    "lat_connect (us)","22.63"
    "lat_ctx-2-128k (us)","2.99"
    "lat_ctx-2-256k (us)","3.19"
    "lat_ctx-4-128k (us)","4.02"
    "lat_ctx-4-256k (us)","4.34"
    "lat_fs-0k (num_files)","813.00"
    "lat_fs-10k (num_files)","209.00"
    "lat_fs-1k (num_files)","236.00"
    "lat_fs-4k (num_files)","218.00"
    "lat_mem_rd-stride128-sz1000k (ns)","8.43"
    "lat_mem_rd-stride128-sz125k (ns)","5.15"
    "lat_mem_rd-stride128-sz250k (ns)","5.15"
    "lat_mem_rd-stride128-sz31k (ns)","2.00"
    "lat_mem_rd-stride128-sz50 (ns)","2.00"
    "lat_mem_rd-stride128-sz500k (ns)","5.15"
    "lat_mem_rd-stride128-sz62k (ns)","5.15"
    "lat_mmap-1m (us)","6.72"
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
    "lat_pagefault (us)","1.10"
    "lat_pipe (us)","8.55"
    "lat_proc-exec (us)","512.91"
    "lat_proc-fork (us)","494.18"
    "lat_proc-proccall (us)","0.00"
    "lat_select (us)","9.61"
    "lat_sem (us)","1.13"
    "lat_sig-catch (us)","2.15"
    "lat_sig-install (us)","0.41"
    "lat_sig-prot (us)","0.16"
    "lat_syscall-fstat (us)","1.02"
    "lat_syscall-null (us)","0.25"
    "lat_syscall-open (us)","121.36"
    "lat_syscall-read (us)","0.38"
    "lat_syscall-stat (us)","1.85"
    "lat_syscall-write (us)","0.32"
    "lat_tcp (us)","0.53"
    "lat_unix (us)","11.29"
    "latency_for_0.50_mb_block_size (nanosec)","5.15"
    "latency_for_1.00_mb_block_size (nanosec)","4.22 (min 0.00, max 8.43)"
    "pipe_bandwidth (MBs)","4463.63"
    "pipe_latency (microsec)","8.55"
    "procedure_call (microsec)","0.00"
    "select_on_200_tcp_fds (microsec)","9.61"
    "semaphore_latency (microsec)","1.13"
    "signal_handler_latency (microsec)","0.41"
    "signal_handler_overhead (microsec)","2.15"
    "tcp_ip_connection_cost_to_localhost (microsec)","22.63"
    "tcp_latency_using_localhost (microsec)","0.53"

Table:  **LM Bench Metrics**


Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.
  
.. csv-table::
    :header: "Benchmarks","j721e-evm: perf"

    "cpu_clock (MHz)","2000.00"
    "dhrystone MIPS (dual-core)","23K DMIPS"
    "dhrystone_per_second (DhrystoneP) per core","20000000.00"

Table:  **Dhrystone Benchmark**


Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Whetstone is a benchmark that measures the speed and efficiency
at which a core performs floating-point operations.

.. csv-table::
    :header: "Benchmarks","j721e-evm: perf"

    "whetstone (MIPS)","10000.00"

Table:  **Whetstone Benchmark**


Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","j721e-evm: perf"

    "linpack (Kflops)","2634946.00"

Table:  **Linpack Benchmark**


NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench is a CPU benchmark designed to expose the capabilities of a system's CPU,
FPU, and memory system. NBench is a single-threaded benchmark and is not designed
to measure the performance gain on multi-core machines.

.. csv-table::
    :header: "Benchmarks","j721e-evm: perf"

    "assignment (Iterations)","29.88"
    "fourier (Iterations)","32335.00"
    "fp_emulation (Iterations)","257.81"
    "huffman (Iterations)","2466.30"
    "idea (Iterations)","7718.70"
    "lu_decomposition (Iterations)","1431.80"
    "neural_net (Iterations)","24.09"
    "numeric_sort (Iterations)","871.86"
    "string_sort (Iterations)","428.25"

Table:  **NBench Benchmarks**


Stream
^^^^^^^^^^^^^^^^^^^^^^^^^^^
STREAM is a microbenchmark for measuring data memory system performance without
any data reuse. It is designed to miss on caches and exercise data prefetcher and
speculative accesseses. It uses double precision floating point (64bit) but in
most modern processors, the memory access will be the bottleneck. The four individual
scores are copy, scale (as in multiply by constant), add two numbers, and triad for
multiply accumulate. For bandwidth, a byte read counts as one, and a byte written
counts as one, resulting in a score that is double the bandwidth LMBench will show.

.. csv-table::
    :header: "Benchmarks","j721e-evm: perf"

    "add (MB/s)","6789.60"
    "copy (MB/s)","6637.90"
    "scale (MB/s)","6565.70"
    "triad (MB/s)","6783.10"

Table:  **Stream**


CoreMark
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark® is a benchmark that measures the performance of CPUs in embedded systems.
Coremark contains implementations of the following algorithms: list processing (find and sort),
matrix manipulation (common matrix operations), state machine (determine if an input stream
contains valid numbers), and CRC (cyclic redundancy check). The result of the benchmark is a
single score for the CPU divided by the clock rate (CoreMark/MHz).

.. csv-table::
    :header: "Benchmarks","j721e-evm: Score/MHz"

    "CoreMark/MHz (dual-core)", "11.4"

Table:  **CoreMark**


CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.

.. csv-table::
    :header: "Benchmarks","j721e-evm: perf"

    "cjpeg-rose7-preset (workloads/)","83.33"
    "core (workloads/)","0.78"
    "coremark-pro ()","2561.66"
    "linear_alg-mid-100x100-sp (workloads/)","82.51"
    "loops-all-mid-10k-sp (workloads/)","2.50"
    "nnet_test (workloads/)","3.55"
    "parser-125k (workloads/)","12.20"
    "radix2-big-64k (workloads/)","281.69"
    "sha-test (workloads/)","156.25"
    "zip-test (workloads/)","52.63"

Table:  **CoreMarkPro**


MultiBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
MultiBench™ is a suite of benchmarks that allows processor and system designers to
analyze, test, and improve multicore processors. It uses three forms of concurrency:
 - Data decomposition: multiple threads cooperating on achieving a unified goal and demonstrating a processor’s support for fine grain parallelism.
 - Processing multiple data streams: uses common code running over multiple threads and demonstrating how well a processor scales over scalable data inputs.
 - Multiple workload processing: shows the scalability of general-purpose processing, demonstrating concurrency over both code and data.
MultiBench combines a wide variety of application-specific workloads with the EEMBC
Multi-Instance-Test Harness (MITH), compatible and portable with most any multicore
processors and operating systems. MITH uses a thread-based API (POSIX-compliant) to
establish a common programming model that communicates with the benchmark through an
abstraction layer and provides a flexible interface to allow a wide variety of
thread-enabled workloads to be tested.

.. csv-table::
    :header: "Benchmarks","j721e-evm: perf"

    "4m-check (workloads/)","1296.68"
    "4m-check-reassembly (workloads/)","239.81"
    "4m-check-reassembly-tcp (workloads/)","135.14"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","46.37"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","2.80"
    "4m-cmykw2 (workloads/)","324.15"
    "4m-cmykw2-rotatew2 (workloads/)","63.36"
    "4m-reassembly (workloads/)","247.53"
    "4m-rotatew2 (workloads/)","73.15"
    "4m-tcp-mixed (workloads/)","210.53"
    "4m-x264w2 (workloads/)","2.84"
    "idct-4m (workloads/)","35.10"
    "idct-4mw1 (workloads/)","35.10"
    "ippktcheck-4m (workloads/)","1200.19"
    "ippktcheck-4mw1 (workloads/)","1203.08"
    "ipres-4m (workloads/)","229.36"
    "ipres-4mw1 (workloads/)","227.96"
    "md5-4m (workloads/)","54.44"
    "md5-4mw1 (workloads/)","53.08"
    "rgbcmyk-4m (workloads/)","164.20"
    "rgbcmyk-4mw1 (workloads/)","164.07"
    "rotate-4ms1 (workloads/)","58.82"
    "rotate-4ms1w1 (workloads/)","58.89"
    "rotate-4ms64 (workloads/)","59.31"
    "rotate-4ms64w1 (workloads/)","59.31"
    "x264-4mq (workloads/)","1.46"
    "x264-4mqw1 (workloads/)","1.46"

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
The time it takes the reference machine to run the benchmark is 9770 seconds. Thus, the ratio is 4.885.
Each ratio is computed, and then the geometric mean of those ratios is computed to produce an overall value.


.. csv-table::
    :header: "Benchmarks","j721e-evm: perf"

    "Spec2K6_speed (PRELIM)","5.53 score/GHz"
    "Spec2K6_rate (PRELIM)","4.8 score/GHz/Core"

Table:  **Spec2K6**


Boot-time Measurement
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Boot media: MMCSD
-------------------------

.. csv-table::
    :header: "Boot Configuration","j721e-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","22.7"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","14.5"

Table:  **Boot time MMC/SD**


DSS Composition
^^^^^^^^^^^^^^^^^^^^^^^^^^^

A DSS unit test is used to perform on-the-fly composition with 4 distinct display layers all
going to the same display output. Frame-rate performance is measured, along with CPU load
and DDR memory bandwidth consumption.

.. csv-table::
    :header: "DSS Display Composition","Resolution","j721e-evm: FPS","CPU Load","Bandwidth: GB/sec"

    "4-layer composition","1080p","60","~0 %","2 GBps"

Table:  **DSS Composition**


3D Graphics Benchmarks
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run GFXBench and capture performance reported: output render rate (Fps) and Score.
All results here are "offscreen" only.

.. csv-table::
    :header: "Benchmarks","j721e-evm: FPS","Score","CPU Load","Bandwidth: GB/sec"

    "GFXBench 3.0 Manhattan 1080p offscreen","16.6","1029","39.4%","2.98"
    "GFXBench 3.1 Manhattan 1080p offscreen","10.2","632","21.2%","2.29"
    "GFXBench 4.0 Car Chase 1080p offscreen","5.56","328","20.3%","2.43"
    "GFXBench Trex offScreen","32.1","1798","33.5%","4.5"

Table:  **GFXBench Results**


Multimedia (Decode)
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run gstreamer pipeline "gst-launch-1.0 playbin uri=\ file://\ <Path to
stream> video-sink="kmssink sync=false connector=<connector id>"
audio-sink=fakesink" and calculate performance based on the execution
time reported.  CPU load of the V4L2 driver is also reported.

.. csv-table::
    :header: "HEVC Decode Performance (V4L2 driver level), Stream(s)","Resolution","j721e-evm: Decode latency (usec)","CPU Load"

    "Netflix_FoodMarket_4096x2160_60fps_IPP_51level_main_40mbps.265","4K @60fps (4096 x 2160)","10234","2 %"
    "Netflix_FoodMarket_4096x2160_30fps_IPP_51level_main_40mbps.265","4K @30fps (4096 x 2160)","10239","1 %"
    "crowd_run_2560x1440_350frame_75mbps_60fps.265","2.5K @60fps (2560 x 1440)","9936","1.4%"
    "CrowdRun_p1920x1080_nv12_60fps_500fr.yuv.265","1080p @60fps (1920 x 1080)","9898","2 %"
    "4x CrowdRun_p1920x1080_nv12_60fps_500fr.yuv.265","4 x 1080p @ 60fps (1920 x 1080)","9966","7.5%"
    "CrowdRun_p1920x1080_nv12_30fps_500fr.265","1080p @ 30fps (1920 x 1080)","9903","1 %"
    "4x CrowdRun_p1920x1080_nv12_30fps_500fr.265","4 x 1080p @ 30fps (1920 x 1080)","10043","3.5%"
    "sintotrees_p1280x720_60fps_nv12_480fr.yuv.265","720p @ 60fps (1280 x 720)","9789","1.5%"
    "4x sintotrees_p1280x720_60fps_nv12_480fr.yuv.265","4 x 720p @ 60fps (1280 x 720)","9850","6.4%"

Table:  **HEVC V4L2 Decode Performance**


.. csv-table::
    :header: "H.264 Decode Performance (V4L2 driver level), Stream(s)","Resolution","j721e-evm: Decode latency (usec)","CPU Load"

    "Netflix_FoodMarket_4096x2160_60fps_8bit_500frames.264","4K @60fps (4096 x 2160)","13176","4.2%"
    "Netflix_FoodMarket_4096x2160_30fps_8bit_500frames.264","4K @30fps (4096 x 2160)","13559","1.5%"
    "crowd_run_2560x1440_350frame_70mbps_60fps.264","2.5K @60fps (2560 x 1440)","9830","2.7%"
    "CrowdRun_p1920x1080_nv12_60fps_500fr.yuv.264","1080p @60fps (1920 x 1080)","9798","3.5%"
    "4x CrowdRun_p1920x1080_nv12_60fps_500fr.yuv.264","4 x 1080p @ 60fps (1920 x 1080)","9855","20%"
    "CrowdRun_p1920x1080_nv12_30fps_500fr.264","1080p @ 30fps (1920 x 1080)","9790","2 %"
    "4x CrowdRun_p1920x1080_nv12_30fps_500fr.264","4 x 1080p @ 30fps (1920 x 1080)","9859","11%"
    "sintotrees_p1280x720_60fps_nv12_480fr.yuv.264","720p @ 60fps (1280 x 720)","9741","3 %"
    "4x sintotrees_p1280x720_60fps_nv12_480fr.yuv.264","4 x 720p @ 60fps (1280 x 720)","9806","22%"
    "GA20_13_panning_720x480_185_420SP.264","720 x 480","9696","0.7 %"
    "container_640x480_420sp_300fr.h264","640 x 480","9690","0.6 %"
    "AUD_MW_E.264","176 x 144","9659","0.5 %"

Table:  **H.264 V4L2 Decode Performance**


Multimedia (Encode)
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run encode test command and calculate performance based on the execution time reported, as in the following example:
  tienc_encode -i pedestrain_1080p_nv12.yuv -w 1920 -h 1080 -o out19.264 -b 15000000 -g 1 -p 1 –j

.. csv-table::
    :header: "H.264 Encode Performance (V4L2 driver level), Stream (Encoder)","Resolution","j721e-evm: Encode latency (usec)"

    "pedestrain_1080p_nv12.yuv","1920 x 1080","12770"
    "oldtowncross_1280x720_nv12.yuv","1280 x 720","5746"
    "concert_640x480_nv12.yuv","640 x 480","2636"

Table:  **H.264 V4L2 Encode Performance**


Ethernet Driver (CPSW_2G)
^^^^^^^^^^^^^^^^^^^^^^^^^^^

TCP Throughput
--------------------------

.. csv-table::
    :header: "TCP Window Size (KBytes)","j721e-evm: Throughput (Mbits/sec)","j721e-evm: CPU Load "

    "8","734.40",""
    "16","958.40",""
    "32","1333.60",""
    "64","1712.00",""
    "128","1696.00",""
    "256","1408.80",""

Table: **TCP Throughput**


UDP Throughput
--------------------------

.. rubric::  UDP Throughput Egress
   :name: udp-throughput-egress

.. csv-table::
    :header: "UDP Packet Size(bytes)","j721e-evm: Throughput (Mbits/sec)","j721e-evm: CPU Load ","j721e-evm: Packets Per Second (kpps) "

    "1024","924.00","53.70","112.00"
    "1470","546.00","29.90","46.00"
    "1500","922.00","57.80","76.00"
    "4000","956.00","47.20","29.00"
    "8000","958.00","46.00","14.00"

Table: **UDP Throughput Egress**


.. rubric::  UDP Throughput Ingress
   :name: udp-throughput-ingress

.. csv-table::
    :header: "UDP Packet Size(bytes)","j721e-evm: Throughput (Mbits/sec)","j721e-evm: CPU Load ","j721e-evm: Packets Per Second (kpps) "

    "64","63.90","32.90","123.00"
    "128","29.80","24.40","28.00"
    "256","120.00","31.30","58.00"
    "512","241.00","37.20","58.00"
    "1024","815.00","54.00","99.00"
    "1470","956.00","55.50","81.00"
    "1500","861.00","59.80","71.00"
    "4000","946.00","55.20","29.00"
    "8000","958.00","46.60","14.00"

Table: **UDP Throughput Ingress**


PCIe Driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^

PCIe-ETH
-------------------------

.. csv-table::
    :header: "TCP Window Size(Kbytes)","j721e-evm: Bandwidth (Mbits/sec)"

    "128","1317.60"
    "256","1427.20"

Table: **PCI Ethernet**


UFS Driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^


UFS Throughput
-------------------------

.. important::

  The performance numbers can be severely affected if the media is
  mounted in sync mode. For performance sensitive applications, umount the
  auto-mounted filesystem and re-mount in async mode.

.. csv-table::
    :header: "Buffer size (bytes)","j721e-evm: Write VFAT Throughput (Mbytes/sec)","j721e-evm: Write VFAT CPU Load (%)","j721e-evm: Read VFAT Throughput (Mbytes/sec)","j721e-evm: Read VFAT CPU Load (%)"

    "102400","97.39 (min 96.05, max 98.28)","3.15 (min 2.33, max 3.72)","663.08","19.35"
    "262144","96.95 (min 95.39, max 97.66)","3.22 (min 2.79, max 3.64)","778.28","25.00"
    "524288","96.52 (min 95.48, max 97.27)","2.77 (min 2.33, max 3.65)","798.43","25.93"
    "1048576","97.34 (min 95.83, max 98.00)","3.15 (min 2.79, max 3.65)","798.91","23.08"
    "5242880","97.45 (min 96.10, max 98.22)","2.79 (min 2.35, max 3.23)","797.60","24.00"

Table: **UFS Throughput VFAT**


.. csv-table::
    :header: "Buffer size (bytes)","j721e-evm: Write EXT4 Throughput (Mbytes/sec)","j721e-evm: Write EXT4 CPU Load (%)","j721e-evm: Read EXT4 Throughput (Mbytes/sec)","j721e-evm: Read EXT4 CPU Load (%)"

    "102400","88.79 (min 86.78, max 90.73)","3.21 (min 2.60, max 4.56)","470.46","15.56"
    "262144","96.57 (min 95.18, max 97.60)","3.40 (min 2.82, max 4.07)","795.68","23.08"
    "524288","96.80 (min 96.00, max 97.65)","3.05 (min 2.33, max 4.13)","799.37","26.92"
    "1048576","96.48 (min 94.61, max 97.60)","3.39 (min 2.79, max 4.48)","757.11","24.14"
    "5242880","97.27 (min 95.57, max 98.13)","3.34 (min 2.35, max 4.11)","780.68","25.93"

Table: **UFS Throughput EXT4**


EMMC Driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^


EMMC Throughput
-------------------------

.. important::

  The performance numbers can be severely affected if the media is
  mounted in sync mode. For performance sensitive applications, umount the
  auto-mounted filesystem and re-mount in async mode.

.. csv-table::
    :header: "Buffer size (bytes)","j721e-evm: Write VFAT Throughput (Mbytes/sec)","j721e-evm: Write VFAT CPU Load (%)","j721e-evm: Read VFAT Throughput (Mbytes/sec)","j721e-evm: Read VFAT CPU Load (%)"

    "102400","59.52 (min 55.27, max 60.90)","3.51 (min 2.60, max 6.82)","287.13","12.99"
    "262144","59.91 (min 56.19, max 60.96)","3.12 (min 2.33, max 5.12)","293.21","7.14"
    "524288","60.00 (min 56.52, max 61.07)","3.22 (min 2.33, max 5.66)","298.61","7.25"
    "1048576","59.85 (min 56.45, max 60.79)","3.44 (min 2.61, max 5.66)","294.10","7.04"
    "5242880","60.15 (min 56.62, max 61.17)","3.41 (min 2.63, max 5.41)","293.04","8.45"

Table: **EMMC Throughput VFAT**


.. csv-table::
    :header: "Buffer size (bytes)","j721e-evm: Write EXT2 Throughput (Mbytes/sec)","j721e-evm: Write EXT2 CPU Load (%)","j721e-evm: Read EXT2 Throughput (Mbytes/sec)","j721e-evm: Read EXT2 CPU Load (%)"

    "102400","60.71 (min 59.92, max 61.01)","1.91 (min 1.46, max 2.85)","292.55","6.94"
    "262144","60.57 (min 59.43, max 60.99)","1.62 (min 1.17, max 2.56)","302.14","10.00"
    "524288","60.76 (min 59.53, max 61.28)","1.62 (min 1.17, max 2.56)","319.51","4.69"
    "1048576","60.79 (min 59.33, max 61.26)","1.67 (min 1.17, max 2.82)","320.64","6.15"
    "5242880","60.58 (min 59.37, max 61.09)","1.73 (min 1.45, max 2.83)","320.41","7.81"

Table: **EMMC Throughput EXT2**


.. csv-table::
    :header: "Buffer size (bytes)","j721e-evm: Write EXT4 Throughput (Mbytes/sec)","j721e-evm: Write EXT4 CPU Load (%)","j721e-evm: Read EXT4 Throughput (Mbytes/sec)","j721e-evm: Read EXT4 CPU Load (%)"

    "102400","60.53 (min 60.32, max 60.93)","1.90 (min 1.45, max 2.59)","306.33","10.00"
    "262144","61.74 (min 61.05, max 62.08)","1.71 (min 1.47, max 2.33)","317.46","9.09"
    "524288","61.69 (min 60.96, max 62.05)","1.82 (min 1.47, max 2.62)","334.83","6.56"
    "1048576","61.74 (min 60.81, max 62.26)","1.70 (min 1.48, max 2.03)","337.18","7.94"
    "5242880","61.80 (min 61.11, max 62.23)","1.88 (min 1.47, max 2.33)","337.15","6.67"

Table: **EMMC Throughput EXT4**


MMC/SD Driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^


MMC/SD Throughput
-------------------------

.. important::

  The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

.. csv-table::
    :header: "Buffer size (bytes)","j721e-evm: Write VFAT Throughput (Mbytes/sec)","j721e-evm: Write VFAT CPU Load (%)","j721e-evm: Read VFAT Throughput (Mbytes/sec)","j721e-evm: Read VFAT CPU Load (%)"

    "102400","10.32 (min 10.28, max 10.37)","0.98 (min 0.69, max 1.47)","40.64","2.14"
    "262144","10.18 (min 9.70, max 10.44)","0.93 (min 0.65, max 1.48)","41.47","2.57"
    "524288","10.15 (min 9.65, max 10.40)","0.92 (min 0.64, max 1.56)","42.09","2.61"
    "1048576","9.97 (min 9.40, max 10.39)","0.91 (min 0.58, max 1.52)","43.28","4.98"
    "5242880","10.17 (min 9.36, max 10.41)","0.95 (min 0.60, max 1.38)","42.55","6.25"

Table: **MMC/SD Throughput VFAT**


.. csv-table::
    :header: "Buffer size (bytes)","j721e-evm: Write EXT2 Throughput (Mbytes/sec)","j721e-evm: Write EXT2 CPU Load (%)","j721e-evm: Read EXT2 Throughput (Mbytes/sec)","j721e-evm: Read EXT2 CPU Load (%)"

    "102400","9.19 (min 3.84, max 11.08)","0.59 (min 0.42, max 0.69)","41.69","1.59"
    "262144","10.74 (min 10.25, max 11.05)","0.66 (min 0.45, max 0.99)","42.81","1.23"
    "524288","10.52 (min 10.15, max 11.10)","0.66 (min 0.45, max 0.87)","44.63","1.49"
    "1048576","10.30 (min 9.85, max 10.50)","0.64 (min 0.50, max 0.84)","44.77","1.07"
    "5242880","10.67 (min 10.27, max 11.15)","0.64 (min 0.48, max 0.89)","45.18","0.87"

Table: **MMC/SD Throughput EXT2**


.. csv-table::
    :header: "Buffer size (bytes)","j721e-evm: Write EXT4 Throughput (Mbytes/sec)","j721e-evm: Write EXT4 CPU Load (%)","j721e-evm: Read EXT4 Throughput (Mbytes/sec)","j721e-evm: Read EXT4 CPU Load (%)"

    "102400","10.87 (min 10.11, max 12.15)","0.62 (min 0.47, max 0.75)","42.14","1.41"
    "262144","10.91 (min 10.34, max 11.63)","0.61 (min 0.47, max 0.72)","42.53","2.43"
    "524288","10.97 (min 10.68, max 11.64)","0.62 (min 0.52, max 0.78)","45.04","1.29"
    "1048576","11.23 (min 10.92, max 11.68)","0.64 (min 0.50, max 0.83)","45.65","1.09"
    "5242880","11.25 (min 10.90, max 11.74)","0.64 (min 0.47, max 0.88)","45.60","1.73"

Table: **MMC/SD Throughput EXT4**

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option


USB Driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^

MUSB/XHCI Host controller
---------------------------

.. important::

  For Mass-storage applications, the performance numbers can be severely
  affected if the media is mounted in sync mode. Hot plug scripts in the
  filesystem mount removable media in sync mode to ensure data
  integrity. For performance sensitive applications, umount the
  auto-mounted filesystem and re-mount in async mode.

|

**Setup** : Inateck ASM1153E USB hard disk is
connected to usb0 port. File read/write performance data on usb0 port is
captured.

|

.. csv-table::
    :header: "Buffer size (bytes)","j721e-evm: Write VFAT Throughput (Mbytes/sec)","j721e-evm: Write VFAT CPU Load (%)","j721e-evm: Read VFAT Throughput (Mbytes/sec)","j721e-evm: Read VFAT CPU Load (%)"

    "102400","312.86 (min 236.02, max 332.26)","17.04 (min 14.52, max 24.42)","333.52","12.90"
    "262144","317.29 (min 247.76, max 335.04)","17.01 (min 14.52, max 21.69)","354.90","12.07"

Table: **USB Host VFAT**

.. csv-table::
    :header: "Buffer size (bytes)","j721e-evm: Write EXT2 Throughput (Mbytes/sec)","j721e-evm: Write EXT2 CPU Load (%)","j721e-evm: Read EXT2 Throughput (Mbytes/sec)","j721e-evm: Read EXT2 CPU Load (%)"

    "102400","349.94 (min 311.81, max 359.84)","11.25 (min 8.77, max 13.43)","320.95","12.50"
    "1048576","351.06 (min 312.71, max 360.91)","11.05 (min 7.14, max 13.64)","394.87","11.54"
    "5242880","353.43 (min 315.19, max 363.50)","10.77 (min 7.27, max 12.50)","405.38","10.00"

Table: **USB Host EXT2**

.. csv-table::
    :header: "Window Size (kbytes)","j721e-evm: TX Throughput (Mbits/sec)","j721e-evm: RX Throughput (Mbits/sec)"

    "8","263.50","44.50"
    "16","266.80","78.70"
    "32","337.30","230.90"
    "64","347.90","345.00"
    "128","351.60","351.00"

Table: **USBDEVICE NCM IPERF TCP THROUGHPUT**

  
CRYPTO Driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^

OpenSSL Performance
-------------------------

.. csv-table::
    :header: "Algorithm","Buffer Size","j721e-evm: throughput"

    "aes-128-cbc","1024","59030.53"
    "aes-128-cbc","16","1125.79"
    "aes-128-cbc","256","18987.78"
    "aes-128-cbc","64","4571.37"
    "aes-128-cbc","8192","174153.73"
    "aes-192-cbc","1024","53752.49"
    "aes-192-cbc","16","1176.94"
    "aes-192-cbc","256","18654.46"
    "aes-192-cbc","64","4529.56"
    "aes-192-cbc","8192","174410.41"
    "aes-256-cbc","1024","56535.38"
    "aes-256-cbc","16","1146.76"
    "aes-256-cbc","256","18744.58"
    "aes-256-cbc","64","4550.21"
    "aes-256-cbc","8192","157827.07"
    "des-cbc","1024","40360.62"
    "des-cbc","16","11463.94"
    "des-cbc","256","35921.66"
    "des-cbc","64","25251.09"
    "des-cbc","8192","41822.89"
    "des3","1024","46702.25"
    "des3","16","1176.65"
    "des3","256","15924.74"
    "des3","64","4926.95"
    "des3","8192","94093.31"
    "md5","1024","96581.63"
    "md5","16","2185.08"
    "md5","256","31671.89"
    "md5","64","8521.94"
    "md5","8192","242316.63"
    "sha1","1024","64368.30"
    "sha1","16","1077.21"
    "sha1","256","16950.44"
    "sha1","64","4295.45"
    "sha1","8192","353219.93"
    "sha224","1024","119689.56"
    "sha224","16","2122.24"
    "sha224","256","33028.01"
    "sha224","64","8506.86"
    "sha224","8192","511008.77"
    "sha256","1024","61989.21"
    "sha256","16","1038.27"
    "sha256","256","16261.12"
    "sha256","64","4130.03"
    "sha256","8192","342261.76"
    "sha384","1024","76010.84"
    "sha384","16","2083.06"
    "sha384","256","28211.63"
    "sha384","64","8395.31"
    "sha384","8192","151688.53"
    "sha512","1024","46941.87"
    "sha512","16","990.04"
    "sha512","256","14470.91"
    "sha512","64","3952.11"
    "sha512","8192","131323.22"

Table: **OpenSSL Algorithm Throughput**


.. csv-table::
    :header: "Algorithm","j721e-evm: CPU Load"

    "aes-128-cbc","35.00"
    "aes-192-cbc","36.00"
    "aes-256-cbc","34.00"
    "des-cbc","99.00"
    "des3","36.00"
    "md5","99.00"
    "sha1","99.00"
    "sha224","99.00"
    "sha256","99.00"
    "sha384","99.00"
    "sha512","99.00"

Table: **OpenSSL CPU Load During Throughput Testing**


Resources
************************

Linux Memory Map
^^^^^^^^^^^^^^^^^^^^^^^^

-  You can view the RAM allocations for the Kernel at run-time as follows:

.. code-block:: bash

  root@j7-evm:/proc# cat /proc/iomem
  [snip...]
  80000000-9e7fffff : System RAM
    80080000-80bdffff : Kernel code
    80be0000-80c6ffff : reserved
    80c70000-80e4ffff : Kernel data
  a9000000-a9ffffff : System RAM
  abc00000-ffffffff : System RAM
  [snip]

  [snip...]
  880000000-8ffffffff : System RAM
    8ff480000-8fff2ffff : reserved
    8fff30000-8fff4ffff : reserved
    8fff50000-8fffeffff : reserved
    8ffff0000-8ffffffff : reserved
  [snip]

**Memory Carveouts**

-  Both reserved & shared memory carveouts are defined in the following file for the J721E EVM:

linux/arch/arm64/boot/dts/ti/k3-j721e-som-p0.dtsi

-  The following table shows the memory carveouts designated in this release:

.. csv-table::
    :header: "Memory Carveout Purpose","Start Address","Carveout Size (MiB)","Carveout Type"

    "Secure DDR (OPTEE)","0x9e800000","24","reserved"
    "MCU_R5F0 Core0 IPC data","0xa0000000","1","shared DMA pool"
    "MCU_R5F0 Core0 Memory","0xa0100000","15","shared DMA pool"
    "MCU_R5F0 Core1 IPC data","0xa1000000","1","shared DMA pool"
    "MCU_R5F0 Core1 Memory","0xa1100000","15","shared DMA pool"
    "MAIN_R5F0 Core0 IPC data","0xa2000000","1","shared DMA pool"
    "MAIN_R5F0 Core0 Memory","0xa2100000","15","shared DMA pool"
    "MAIN_R5F0 Core1 IPC data","0xa3000000","1","shared DMA pool"
    "MAIN_R5F0 Core1 Memory","0xa3100000","15","shared DMA pool"
    "MAIN_R5F1 Core0 IPC data","0xa4000000","1","shared DMA pool"
    "MAIN_R5F1 Core0 Memory","0xa4100000","15","shared DMA pool"
    "MAIN_R5F1 Core1 IPC data","0xa5000000","1","shared DMA pool"
    "MAIN_R5F1 Core1 Memory","0xa5100000","15","shared DMA pool"
    "C66x_1 IPC data","0xa6000000","1","shared DMA pool"
    "C66x_0 Memory","0xa6100000","15","shared DMA pool"
    "C66x_0 IPC data","0xa7000000","1","shared DMA pool"
    "C66x_1 Memory","0xa7100000","15","shared DMA pool"
    "C71x_0 IPC data","0xa8000000","1","shared DMA pool"
    "C71x_0 Memory","0xa8100000","15","shared DMA pool"
    "IPC Memory (Remote Cores IPC VRING space)","0xaa000000","28","reserved"
    "Display Memory (dynamic allocation)","0xc0000000","512","CMA carveout"

Table: **Linux Memory Carveouts**

