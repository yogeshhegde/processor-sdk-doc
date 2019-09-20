.. rubric::  **Read This First**
   :name: read-this-first

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

**NOTE: All performance measurements provided in this document are PRELIMINARY and have
not necessarily been fully optimized yet.  They are provided here as-is for this release.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| J721E EVM      | J721E Evaluation Module rev E2 with ARM running at 2GHz, DDR data rate 4266 MT/S, L3 Cache size 3MB,           |
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
    "Multimedia","HEVC 4K@60fps decoding","HEVC 4K stream decoding","FPS","SDK6.0"
    "","","","CPU Load (%)","SDK6.0"
    "","","","Memory Bandwidth (GBps)","SDK6.1"
    "","4x 1080p@60fps decoding","4-channel decoding","FPS","SDK6.1"
    "","","","CPU Load (%)","SDK6.1"
    "","","","Memory Bandwidth (GBps)","SDK6.1"
    "","H264 1080p@60fps encoding","1080p encoding","FPS","TBD"
    "","","","CPU Load ","TBD"
    "","","","Memory Bandwidth","TBD"
    "","4x 720p@30fps Encoding","4-channel Encoding","FPS","TBD"
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
    "","","Texture Read/Write","FPS","SDK6.1"
    "","","","Memory Bandwidth (GBps)","SDK6.1"
    "DDR/Interconnect","Throughput","STREAM","GBps","SDK6.0"
    "","","LMBench","GBps","SDK6.0"
    "","","udma mem<->mem xfers","GBps","SDK6.1"
    "","","DRU xfers","GBps","SDK6.1"
    "","ECC overhead","Synthetic application with ECC memory region","GBps","SDK6.1"
    "","","","% loss in performance","SDK6.1"
    "Boot-time Measurement","Cold boot to Linux prompt","Time measurement","seconds","SDK6.0"
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

    "af_unix_sock_stream_latency (microsec)","14.80"
    "af_unix_socket_stream_bandwidth (MBs)","2866.58"
    "bw_file_rd-io-1mb (MB/s)","4942.34"
    "bw_file_rd-o2c-1mb (MB/s)","2673.29"
    "bw_mem-bcopy-16mb (MB/s)","3277.01"
    "bw_mem-bcopy-1mb (MB/s)","6476.19"
    "bw_mem-bcopy-2mb (MB/s)","4272.74"
    "bw_mem-bcopy-4mb (MB/s)","3509.39"
    "bw_mem-bcopy-8mb (MB/s)","3282.72"
    "bw_mem-bzero-16mb (MB/s)","9070.29"
    "bw_mem-bzero-1mb (MB/s)","9076.07 (min 6476.19, max 11675.95)"
    "bw_mem-bzero-2mb (MB/s)","7871.14 (min 4272.74, max 11469.53)"
    "bw_mem-bzero-4mb (MB/s)","6953.36 (min 3509.39, max 10397.33)"
    "bw_mem-bzero-8mb (MB/s)","6306.47 (min 3282.72, max 9330.22)"
    "bw_mem-cp-16mb (MB/s)","1200.30"
    "bw_mem-cp-1mb (MB/s)","6702.46 (min 1843.16, max 11561.75)"
    "bw_mem-cp-2mb (MB/s)","7101.75 (min 2768.17, max 11435.33)"
    "bw_mem-cp-4mb (MB/s)","5882.64 (min 1352.49, max 10412.79)"
    "bw_mem-cp-8mb (MB/s)","5267.66 (min 1206.64, max 9328.67)"
    "bw_mem-fcp-16mb (MB/s)","3364.53"
    "bw_mem-fcp-1mb (MB/s)","9172.58 (min 6669.21, max 11675.95)"
    "bw_mem-fcp-2mb (MB/s)","7811.25 (min 4152.97, max 11469.53)"
    "bw_mem-fcp-4mb (MB/s)","6944.17 (min 3491.01, max 10397.33)"
    "bw_mem-fcp-8mb (MB/s)","6350.74 (min 3371.26, max 9330.22)"
    "bw_mem-frd-16mb (MB/s)","6652.81"
    "bw_mem-frd-1mb (MB/s)","6439.03 (min 6208.84, max 6669.21)"
    "bw_mem-frd-2mb (MB/s)","4961.97 (min 4152.97, max 5770.96)"
    "bw_mem-frd-4mb (MB/s)","5210.38 (min 3491.01, max 6929.74)"
    "bw_mem-frd-8mb (MB/s)","5031.79 (min 3371.26, max 6692.32)"
    "bw_mem-fwr-16mb (MB/s)","9084.46"
    "bw_mem-fwr-1mb (MB/s)","8885.30 (min 6208.84, max 11561.75)"
    "bw_mem-fwr-2mb (MB/s)","8603.15 (min 5770.96, max 11435.33)"
    "bw_mem-fwr-4mb (MB/s)","8671.27 (min 6929.74, max 10412.79)"
    "bw_mem-fwr-8mb (MB/s)","8010.50 (min 6692.32, max 9328.67)"
    "bw_mem-rd-16mb (MB/s)","7114.27"
    "bw_mem-rd-1mb (MB/s)","12452.96 (min 11301.64, max 13604.27)"
    "bw_mem-rd-2mb (MB/s)","5140.15 (min 3261.46, max 7018.84)"
    "bw_mem-rd-4mb (MB/s)","6109.86 (min 3860.26, max 8359.46)"
    "bw_mem-rd-8mb (MB/s)","4503.02 (min 1720.06, max 7285.97)"
    "bw_mem-rdwr-16mb (MB/s)","1623.05"
    "bw_mem-rdwr-1mb (MB/s)","4649.53 (min 1843.16, max 7455.90)"
    "bw_mem-rdwr-2mb (MB/s)","2748.34 (min 2728.51, max 2768.17)"
    "bw_mem-rdwr-4mb (MB/s)","2587.08 (min 1352.49, max 3821.66)"
    "bw_mem-rdwr-8mb (MB/s)","1517.82 (min 1206.64, max 1828.99)"
    "bw_mem-wr-16mb (MB/s)","1549.94"
    "bw_mem-wr-1mb (MB/s)","10530.09 (min 7455.90, max 13604.27)"
    "bw_mem-wr-2mb (MB/s)","2994.99 (min 2728.51, max 3261.46)"
    "bw_mem-wr-4mb (MB/s)","3840.96 (min 3821.66, max 3860.26)"
    "bw_mem-wr-8mb (MB/s)","1774.53 (min 1720.06, max 1828.99)"
    "bw_mmap_rd-mo-1mb (MB/s)","12399.71"
    "bw_mmap_rd-o2c-1mb (MB/s)","3379.01"
    "bw_pipe (MB/s)","3884.62"
    "bw_unix (MB/s)","2866.58"
    "lat_connect (us)","22.23"
    "lat_ctx-2-128k (us)","2.83"
    "lat_ctx-2-256k (us)","3.01"
    "lat_ctx-4-128k (us)","3.91"
    "lat_ctx-4-256k (us)","4.23"
    "lat_fs-0k (num_files)","808.00"
    "lat_fs-10k (num_files)","228.00"
    "lat_fs-1k (num_files)","219.00"
    "lat_fs-4k (num_files)","222.00"
    "lat_mem_rd-stride128-sz1000k (ns)","7.93"
    "lat_mem_rd-stride128-sz125k (ns)","5.15"
    "lat_mem_rd-stride128-sz250k (ns)","5.15"
    "lat_mem_rd-stride128-sz31k (ns)","2.00"
    "lat_mem_rd-stride128-sz50 (ns)","2.00"
    "lat_mem_rd-stride128-sz500k (ns)","5.15"
    "lat_mem_rd-stride128-sz62k (ns)","5.15"
    "lat_mmap-1m (us)","6.68"
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
    "lat_pagefault (us)","1.06"
    "lat_pipe (us)","8.33"
    "lat_proc-exec (us)","499.00"
    "lat_proc-fork (us)","493.08"
    "lat_proc-proccall (us)","0.00"
    "lat_select (us)","9.56"
    "lat_sem (us)","1.24"
    "lat_sig-catch (us)","2.10"
    "lat_sig-install (us)","0.40"
    "lat_sig-prot (us)","0.34"
    "lat_syscall-fstat (us)","1.02"
    "lat_syscall-null (us)","0.26"
    "lat_syscall-open (us)","131.85"
    "lat_syscall-read (us)","0.41"
    "lat_syscall-stat (us)","1.82"
    "lat_syscall-write (us)","0.33"
    "lat_tcp (us)","0.53"
    "lat_unix (us)","14.80"
    "latency_for_0.50_mb_block_size (nanosec)","5.15"
    "latency_for_1.00_mb_block_size (nanosec)","3.97 (min 0.00, max 7.93)"
    "pipe_bandwidth (MBs)","3884.62"
    "pipe_latency (microsec)","8.33"
    "procedure_call (microsec)","0.00"
    "select_on_200_tcp_fds (microsec)","9.56"
    "semaphore_latency (microsec)","1.24"
    "signal_handler_latency (microsec)","0.40"
    "signal_handler_overhead (microsec)","2.10"
    "tcp_ip_connection_cost_to_localhost (microsec)","22.23"
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

    "linpack (Kflops)","2629900.00"

Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","j721e-evm: perf"

    "assignment (Iterations)","29.87"
    "fourier (Iterations)","32457.00"
    "fp_emulation (Iterations)","257.83"
    "huffman (Iterations)","2471.50"
    "idea (Iterations)","7718.70"
    "lu_decomposition (Iterations)","1432.70"
    "neural_net (Iterations)","24.86"
    "numeric_sort (Iterations)","871.82"
    "string_sort (Iterations)","429.64"

Table:  **NBench Benchmarks**

Stream
^^^^^^^^^^^^^^^^^^^^^^^^^^^
STREAM is a microbenchmark for measuring data memory system performance without
any data reuse. It is designed to miss on caches and exercise data prefetcher and
speculative accesseses. It uses double precision floating point (64bit) but in
most modern processors, the memory access will be the bottleck. The four individual
scores are copy, scale as in multiply by constant, add two numbers, and triad for
multiply accumulate. For bandwidth a byte read counts as one and a byte written
counts as one resulting in a score that is double the bandwidth LMBench will show.

.. csv-table::
    :header: "Benchmarks","j721e-evm: perf"

    "add (MB/s)","6879.60"
    "copy (MB/s)","6790.00"
    "scale (MB/s)","6688.90"
    "triad (MB/s)","6871.30"

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
    "coremark-pro ()","2559.34"
    "linear_alg-mid-100x100-sp (workloads/)","82.37"
    "loops-all-mid-10k-sp (workloads/)","2.47"
    "nnet_test (workloads/)","3.53"
    "parser-125k (workloads/)","12.20"
    "radix2-big-64k (workloads/)","280.43"
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

.. csv-table::
    :header: "Benchmarks","j721e-evm: perf"

    "4m-check (workloads/)","1281.39"
    "4m-check-reassembly (workloads/)","259.07"
    "4m-check-reassembly-tcp (workloads/)","130.89"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","46.62"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","2.80"
    "4m-cmykw2 (workloads/)","324.68"
    "4m-cmykw2-rotatew2 (workloads/)","64.66"
    "4m-reassembly (workloads/)","263.16"
    "4m-rotatew2 (workloads/)","72.89"
    "4m-tcp-mixed (workloads/)","216.22"
    "4m-x264w2 (workloads/)","2.85"
    "idct-4m (workloads/)","35.11"
    "idct-4mw1 (workloads/)","35.11"
    "ippktcheck-4m (workloads/)","1355.01"
    "ippktcheck-4mw1 (workloads/)","1328.37"
    "ipres-4m (workloads/)","237.72"
    "ipres-4mw1 (workloads/)","236.97"
    "md5-4m (workloads/)","53.53"
    "md5-4mw1 (workloads/)","53.25"
    "rgbcmyk-4m (workloads/)","164.20"
    "rgbcmyk-4mw1 (workloads/)","164.20"
    "rotate-4ms1 (workloads/)","59.03"
    "rotate-4ms1w1 (workloads/)","59.10"
    "rotate-4ms64 (workloads/)","59.81"
    "rotate_-4ms64w1 (workloads/)","59.67"
    "x264-4mq (workloads/)","1.46"
    "x264-4mqw1 (workloads/)","1.47"

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


.. csv-table::
    :header: "Benchmarks","j721e-evm: perf"

    "Spec2K6_speed (PRELIM)","6.0"
    "Spec2K6_rate (PRELIM)","4.94"

Table:  **Spec2K6**


Boot-time Measurement
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Boot media: MMCSD
-------------------------

.. csv-table::
    :header: "Boot Configuration","j721e-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","16.57 (min 16.36, max 17.01)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","7.63 (min 7.46, max 8.23)"

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
    :header: "Benchmarks","j721e-evm: FPS","Score"

    "GFXBench 3.0 Manhattan 1080p offscreen","17.95","1113"
    "GFXBench 3.1 Manhattan 1080p offscreen","11.07","686"
    "GFXBench 4.0 Car Chase 1080p offscreen","20.2","1214"
    "GFXBench Trex offScreen","33.7","1886"

Table:  **GFXBench Results**


Multimedia (Decode)
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run gstreamer pipeline "gst-launch-1.0 playbin uri=\ file://\ <Path to
stream> video-sink="kmssink sync=false connector=<connector id>"
audio-sink=fakesink" and calculate performance based on the execution
time reported.  CPU load of the V4L2 driver is also reported.

.. csv-table::
    :header: "H.264 & HEVC Decode Performance (V4L2 driver level)","j721e-evm: FPS","CPU Load"

    "4K resolution decode","60","~8% of Dual-core A72"
    "","","NOTE: V4L2 driver optimization is still in progress"

Table:  **V4L2 Decode Performance**


Ethernet Driver (CPSW_2G)
^^^^^^^^^^^^^^^^^^^^^^^^^^^

TCP Throughput
--------------------------

.. csv-table::
    :header: "TCP Window Size (KBytes)","j721e-evm: Throughput (Mbits/sec)","j721e-evm: CPU Load "

    "8","760.00",""
    "16","1051.20",""
    "32","1382.40",""
    "64","1313.60",""
    "128","1760.00",""
    "256","1768.00",""

Table: **TCP Throughput**

UDP Throughput
--------------------------

.. rubric::  UDP Throughput Egress
   :name: udp-throughput-egress

.. csv-table::
    :header: "UDP Packet Size(bytes)","j721e-evm: Throughput (Mbits/sec)","j721e-evm: CPU Load ","j721e-evm: Packets Per Second (kpps) "

    "1024","902.00","56.40","110.00"
    "1470","956.00","47.60","81.00"
    "1500","923.00","59.30","76.00"

Table: **UDP Throughput Egress**

.. rubric::  UDP Throughput Ingress
   :name: udp-throughput-ingress

.. csv-table::
    :header: "UDP Packet Size(bytes)","j721e-evm: Throughput (Mbits/sec)","j721e-evm: CPU Load ","j721e-evm: Packets Per Second (kpps) "

    "64","63.90","31.50","123.00"
    "128","136.40","32.80","132.00"
    "256","115.00","32.50","56.00"
    "512","228.00","35.40","55.00"
    "1024","828.00","54.50","101.00"
    "1470","956.00","55.60","81.00"
    "1500","614.00","58.80","51.00"

Table: **UDP Throughput Ingress**


PCIe Driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^

PCIe-ETH
-------------------------

.. csv-table::
    :header: "TCP Window Size(Kbytes)","j721e-evm: Bandwidth (Mbits/sec)"

    "128","1321.60"
    "256","1436.80"

Table: **PCI Ethernet**


USB Driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^

MUSB/XHCI Host controller
---------------------------

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

.. csv-table::
    :header: "Buffer size (bytes)","j721e-evm: Write VFAT Throughput (Mbytes/sec)","j721e-evm: Write VFAT CPU Load (%)","j721e-evm: Read VFAT Throughput (Mbytes/sec)","j721e-evm: Read VFAT CPU Load (%)"

    "102400","305.41 (min 234.87, max 323.63)","18.76 (min 16.92, max 25.84)","317.51","16.92"
    "262144","309.49 (min 245.13, max 326.43)","17.37 (min 14.52, max 22.62)","332.77","13.33"

Table: **USB Host VFAT**

.. csv-table::
    :header: "Buffer size (bytes)","j721e-evm: Write EXT2 Throughput (Mbytes/sec)","j721e-evm: Write EXT2 CPU Load (%)","j721e-evm: Read EXT2 Throughput (Mbytes/sec)","j721e-evm: Read EXT2 CPU Load (%)"

    "102400","336.96 (min 300.81, max 346.57)","13.23 (min 10.17, max 18.31)","308.84","18.84"
    "1048576","338.61 (min 304.10, max 347.83)","12.75 (min 8.77, max 17.39)","351.79","16.95"
    "5242880","338.03 (min 303.04, max 347.14)","13.67 (min 12.90, max 14.71)","346.81","20.97"

Table: **USB Host EXT2**

  
CRYPTO Driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^

OpenSSL Performance
-------------------------

.. csv-table::
    :header: "Algorithm","Buffer Size","j721e-evm: throughput"

    "aes-128-cbc","1024","57594.88"
    "aes-128-cbc","16","1182.89"
    "aes-128-cbc","256","17503.91"
    "aes-128-cbc","64","4735.13"
    "aes-128-cbc","8192","176305.49"
    "aes-192-cbc","1024","57849.86"
    "aes-192-cbc","16","1190.19"
    "aes-192-cbc","256","17624.41"
    "aes-192-cbc","64","4739.80"
    "aes-192-cbc","8192","170595.67"
    "aes-256-cbc","1024","55819.61"
    "aes-256-cbc","16","1181.58"
    "aes-256-cbc","256","17147.56"
    "aes-256-cbc","64","4692.93"
    "aes-256-cbc","8192","156423.51"
    "des-cbc","1024","42311.34"
    "des-cbc","16","10969.93"
    "des-cbc","256","37191.77"
    "des-cbc","64","25144.30"
    "des-cbc","8192","44094.81"
    "des3","1024","46171.82"
    "des3","16","1187.96"
    "des3","256","16302.76"
    "des3","64","4717.44"
    "des3","8192","93492.57"
    "md5","1024","93546.84"
    "md5","16","2108.06"
    "md5","256","30348.97"
    "md5","64","8185.49"
    "md5","8192","239514.97"
    "sha1","1024","115795.97"
    "sha1","16","1984.57"
    "sha1","256","31114.07"
    "sha1","64","7874.84"
    "sha1","8192","509941.08"

Table: **OpenSSL Algorithm Throughput**

.. csv-table::
    :header: "Algorithm","j721e-evm: CPU Load"

    "aes-128-cbc","48.00"
    "aes-192-cbc","48.00"
    "aes-256-cbc","47.00"
    "des-cbc","99.00"
    "des3","43.00"
    "md5","99.00"
    "sha1","99.00"

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
    80080000-80bbffff : Kernel code
    80bc0000-80c4ffff : reserved
    80c50000-80e2ffff : Kernel data
  a9000000-a9ffffff : System RAM
  abc00000-ffffffff : System RAM
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
    "Display Memory","0xc0000000","512","CMA carveout"

Table: **Linux Memory Carveouts**


Use Cases
************************

Integrated Cockpit
^^^^^^^^^^^^^^^^^^^^^^^^

Overview
------------------------
The integrated cockpit use-case example demonstrates the virtualization features of
the J721e SoC by integrating the Cluster and Infotainment (IVI) applications into a single
ECU solution using a Hypervisor.  The OS stack for each key application runs in complete isolation
from the other application's OS by running both as Virtual Machines (VMs) and using the virtualization
features of the J721e SoC to provide both isolation as well as protected resource sharing.
The following block diagram describes the high-level software stacks for this demo.

.. Image:: ../images/Integrated-Cockpit-Block-Diagram.png

Integrated Cockpit use-case features in this SDK6.0 release:

IVI VM:
   Multi-media playback, HMI acceleration with the GPU

   GPU rendering application – "OGLES skinning"

Cluster VM:
   2D-cluster with CPU blitting: 2 layers for dials and needles (upgraded to 3D-cluster app in next release)

Other Features:
   Safety telltales / Cluster display from Cortex-R5F

   Display sharing between VMs (Cortex-A72) and Cortex-R5F

Isolation:
   IVI VM crash does not impact the Cluster VM

