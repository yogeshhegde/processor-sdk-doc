.. http://processors.wiki.ti.com/index.php/CoreSDK_Linux_Kernel_Performance_Guide


======================================
 Linux 07.03.00 Performance Guide
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
| AM64x EVM      | AM64x Evaluation Module rev E1 with ARM running at 1GHz, DDRdata rate 1600 MT/S                                |
+----------------+----------------------------------------------------------------------------------------------------------------+
| AM65x EVM      | AM65x Evaluation Module rev 1.0 with ARM running at 800MHz, DDR4-2400 (1600 MT/S), TMDX654GPEVM                |
+----------------+----------------------------------------------------------------------------------------------------------------+
| J721e EVM      | J721e Evaluation Module rev E2 with ARM running at 2GHz, DDR data rate 4266 MT/S, L3 Cache size 3MB            |
+----------------+----------------------------------------------------------------------------------------------------------------+
| J7200 EVM      | J7200 Evaluation Module rev E1 with ARM running at 2GHz, DDR data rate 2666 MT/S, L3 Cache size 3MB            |
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
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf"

    "af_unix_sock_stream_latency (microsec)","15.82","15.46"
    "af_unix_socket_stream_bandwidth (MBs)","930.41","2719.65"
    "bw_file_rd-io-1mb (MB/s)","2483.15","3751.34"
    "bw_file_rd-o2c-1mb (MB/s)","1203.13","1915.38"
    "bw_mem-bcopy-16mb (MB/s)","1117.24","2565.34"
    "bw_mem-bcopy-1mb (MB/s)","1142.20","5051.42"
    "bw_mem-bcopy-2mb (MB/s)","1118.78","3279.88"
    "bw_mem-bcopy-4mb (MB/s)","1119.66","3154.08"
    "bw_mem-bcopy-8mb (MB/s)","1116.54","2773.44"
    "bw_mem-bzero-16mb (MB/s)","1140.41","10240.00"
    "bw_mem-bzero-1mb (MB/s)","1392.26 (min 1142.20, max 1642.31)","8829.75 (min 5051.42, max 12608.07)"
    "bw_mem-bzero-2mb (MB/s)","1147.89 (min 1118.78, max 1176.99)","7889.94 (min 3279.88, max 12500.00)"
    "bw_mem-bzero-4mb (MB/s)","1130.53 (min 1119.66, max 1141.39)","7808.71 (min 3154.08, max 12463.34)"
    "bw_mem-bzero-8mb (MB/s)","1130.85 (min 1116.54, max 1145.15)","7560.75 (min 2773.44, max 12348.06)"
    "bw_mem-cp-16mb (MB/s)","688.23","1081.59"
    "bw_mem-cp-1mb (MB/s)","1175.40 (min 704.85, max 1645.94)","6807.12 (min 976.88, max 12637.36)"
    "bw_mem-cp-2mb (MB/s)","934.16 (min 689.42, max 1178.90)","6765.69 (min 1015.74, max 12515.64)"
    "bw_mem-cp-4mb (MB/s)","915.90 (min 688.94, max 1142.86)","6842.26 (min 1243.97, max 12440.54)"
    "bw_mem-cp-8mb (MB/s)","915.90 (min 689.42, max 1142.37)","6728.56 (min 1099.51, max 12357.60)"
    "bw_mem-fcp-16mb (MB/s)","1199.49","2523.26"
    "bw_mem-fcp-1mb (MB/s)","1431.66 (min 1221.00, max 1642.31)","8857.75 (min 5107.43, max 12608.07)"
    "bw_mem-fcp-2mb (MB/s)","1189.46 (min 1176.99, max 1201.92)","7864.64 (min 3229.28, max 12500.00)"
    "bw_mem-fcp-4mb (MB/s)","1171.12 (min 1141.39, max 1200.84)","7846.66 (min 3229.97, max 12463.34)"
    "bw_mem-fcp-8mb (MB/s)","1172.01 (min 1145.15, max 1198.86)","7512.94 (min 2677.82, max 12348.06)"
    "bw_mem-frd-16mb (MB/s)","5587.57","4968.94"
    "bw_mem-frd-1mb (MB/s)","3891.58 (min 1221.00, max 6562.16)","5604.75 (min 5107.43, max 6102.07)"
    "bw_mem-frd-2mb (MB/s)","3417.86 (min 1201.92, max 5633.80)","4576.14 (min 3229.28, max 5923.00)"
    "bw_mem-frd-4mb (MB/s)","3393.23 (min 1200.84, max 5585.62)","4561.58 (min 3229.97, max 5893.19)"
    "bw_mem-frd-8mb (MB/s)","3392.73 (min 1198.86, max 5586.59)","4175.29 (min 2677.82, max 5672.75)"
    "bw_mem-fwr-16mb (MB/s)","1142.86","10233.45"
    "bw_mem-fwr-1mb (MB/s)","4104.05 (min 1645.94, max 6562.16)","9369.72 (min 6102.07, max 12637.36)"
    "bw_mem-fwr-2mb (MB/s)","3406.35 (min 1178.90, max 5633.80)","9219.32 (min 5923.00, max 12515.64)"
    "bw_mem-fwr-4mb (MB/s)","3364.24 (min 1142.86, max 5585.62)","9166.87 (min 5893.19, max 12440.54)"
    "bw_mem-fwr-8mb (MB/s)","3364.48 (min 1142.37, max 5586.59)","9015.18 (min 5672.75, max 12357.60)"
    "bw_mem-rd-16mb (MB/s)","5089.06","5486.97"
    "bw_mem-rd-1mb (MB/s)","3643.13 (min 977.68, max 6308.58)","11209.95 (min 10646.25, max 11773.64)"
    "bw_mem-rd-2mb (MB/s)","2982.64 (min 760.55, max 5204.72)","4116.79 (min 1500.83, max 6732.75)"
    "bw_mem-rd-4mb (MB/s)","2918.01 (min 744.19, max 5091.83)","4100.59 (min 1454.55, max 6746.63)"
    "bw_mem-rd-8mb (MB/s)","2914.42 (min 743.01, max 5085.82)","3935.07 (min 1360.78, max 6509.36)"
    "bw_mem-rdwr-16mb (MB/s)","745.23","1235.71"
    "bw_mem-rdwr-1mb (MB/s)","841.82 (min 704.85, max 978.79)","4049.06 (min 976.88, max 7121.24)"
    "bw_mem-rdwr-2mb (MB/s)","726.10 (min 689.42, max 762.78)","1340.65 (min 1015.74, max 1665.56)"
    "bw_mem-rdwr-4mb (MB/s)","718.44 (min 688.94, max 747.94)","1291.67 (min 1243.97, max 1339.36)"
    "bw_mem-rdwr-8mb (MB/s)","717.64 (min 689.42, max 745.85)","1211.90 (min 1099.51, max 1324.28)"
    "bw_mem-wr-16mb (MB/s)","742.53","1743.30"
    "bw_mem-wr-1mb (MB/s)","978.24 (min 977.68, max 978.79)","9447.44 (min 7121.24, max 11773.64)"
    "bw_mem-wr-2mb (MB/s)","761.67 (min 760.55, max 762.78)","1583.20 (min 1500.83, max 1665.56)"
    "bw_mem-wr-4mb (MB/s)","746.07 (min 744.19, max 747.94)","1396.96 (min 1339.36, max 1454.55)"
    "bw_mem-wr-8mb (MB/s)","744.43 (min 743.01, max 745.85)","1342.53 (min 1324.28, max 1360.78)"
    "bw_mmap_rd-mo-1mb (MB/s)","6350.47","9350.94"
    "bw_mmap_rd-o2c-1mb (MB/s)","1502.63","1907.67"
    "bw_pipe (MB/s)","1634.30","1985.21"
    "bw_unix (MB/s)","930.41","2719.65"
    "lat_connect (us)","26.17","24.39"
    "lat_ctx-2-128k (us)","5.69","2.56"
    "lat_ctx-2-256k (us)","17.80","2.86"
    "lat_ctx-4-128k (us)","16.53","3.79"
    "lat_ctx-4-256k (us)","22.55","4.71"
    "lat_fs-0k (num_files)","712.00","751.00"
    "lat_fs-10k (num_files)","77.00","229.00"
    "lat_fs-1k (num_files)","75.00","219.00"
    "lat_fs-4k (num_files)","77.00","210.00"
    "lat_mem_rd-stride128-sz1000k (ns)","18.65","8.79"
    "lat_mem_rd-stride128-sz125k (ns)","5.15","5.15"
    "lat_mem_rd-stride128-sz250k (ns)","5.15","5.15"
    "lat_mem_rd-stride128-sz31k (ns)","2.00","2.00"
    "lat_mem_rd-stride128-sz50 (ns)","2.00","2.00"
    "lat_mem_rd-stride128-sz500k (ns)","5.42","5.15"
    "lat_mem_rd-stride128-sz62k (ns)","5.15","5.15"
    "lat_mmap-1m (us)","7.75","7.72"
    "lat_ops-double-add (ns)","0.32","0.32"
    "lat_ops-double-mul (ns)","2.00","2.00"
    "lat_ops-float-add (ns)","0.32","0.32"
    "lat_ops-float-mul (ns)","2.00","2.00"
    "lat_ops-int-add (ns)","0.50","0.50"
    "lat_ops-int-bit (ns)","0.33","0.33"
    "lat_ops-int-div (ns)","4.00","4.00"
    "lat_ops-int-mod (ns)","4.67","4.67"
    "lat_ops-int-mul (ns)","1.52","1.52"
    "lat_ops-int64-add (ns)","0.50","0.50"
    "lat_ops-int64-bit (ns)","0.33","0.33"
    "lat_ops-int64-div (ns)","3.00","3.00"
    "lat_ops-int64-mod (ns)","5.67","5.67"
    "lat_pagefault (us)","1.13","1.20"
    "lat_pipe (us)","7.91","8.01"
    "lat_proc-exec (us)","1194.00","687.50"
    "lat_proc-fork (us)","1132.20","674.00"
    "lat_proc-proccall (us)","0.00","0.00"
    "lat_select (us)","9.45","9.45"
    "lat_sem (us)","0.98","1.09"
    "lat_sig-catch (us)","2.29","2.29"
    "lat_sig-install (us)","0.39","0.39"
    "lat_sig-prot (us)","0.33","0.34"
    "lat_syscall-fstat (us)","0.57","0.57"
    "lat_syscall-null (us)","0.26","0.26"
    "lat_syscall-open (us)","180.38","156.80"
    "lat_syscall-read (us)","0.40","0.41"
    "lat_syscall-stat (us)","1.43","1.41"
    "lat_syscall-write (us)","0.32","0.32"
    "lat_tcp (us)","0.53","0.52"
    "lat_unix (us)","15.82","15.46"
    "latency_for_0.50_mb_block_size (nanosec)","5.42","5.15"
    "latency_for_1.00_mb_block_size (nanosec)","9.32 (min 0.00, max 18.65)","4.39 (min 0.00, max 8.79)"
    "pipe_bandwidth (MBs)","1634.30","1985.21"
    "pipe_latency (microsec)","7.91","8.01"
    "procedure_call (microsec)","0.00","0.00"
    "select_on_200_tcp_fds (microsec)","9.45","9.45"
    "semaphore_latency (microsec)","0.98","1.09"
    "signal_handler_latency (microsec)","0.39","0.39"
    "signal_handler_overhead (microsec)","2.29","2.29"
    "tcp_ip_connection_cost_to_localhost (microsec)","26.17","24.39"
    "tcp_latency_using_localhost (microsec)","0.53","0.52"


Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

.. csv-table::
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf"

    "cpu_clock (MHz)","2000.00","2000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","5.7","5.17"
    "dhrystone_per_second (DhrystoneP)","20000000.00","18181818.00"


Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf"

    "whetstone (MIPS)","10000.00","10000.00"


Table:  **Whetstone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
sloving a dense linear system.

.. csv-table::
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf"

    "linpack (Kflops)","2637982.00","2655324.00"


Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf"

    "assignment (Iterations)","29.67","29.68"
    "fourier (Iterations)","59198.00","51977.00"
    "fp_emulation (Iterations)","250.02","250.06"
    "huffman (Iterations)","2433.80","2423.30"
    "idea (Iterations)","7997.10","7997.30"
    "lu_decomposition (Iterations)","1429.90","1431.40"
    "neural_net (Iterations)","27.34","27.31"
    "numeric_sort (Iterations)","878.98","879.45"
    "string_sort (Iterations)","416.97","418.94"


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
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf"

    "add (MB/s)","3864.40","5367.90"
    "copy (MB/s)","3087.30","5655.70"
    "scale (MB/s)","3115.40","5360.70"
    "triad (MB/s)","3872.30","5285.30"


Table:  **Stream**

CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.

.. csv-table::
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf"

    "cjpeg-rose7-preset (workloads/)","82.64","83.33"
    "core (workloads/)","0.78","0.78"
    "coremark-pro ()","2282.42","2571.86"
    "linear_alg-mid-100x100-sp (workloads/)","82.51","82.51"
    "loops-all-mid-10k-sp (workloads/)","2.22","2.48"
    "nnet_test (workloads/)","3.67","3.87"
    "parser-125k (workloads/)","11.49","12.20"
    "radix2-big-64k (workloads/)","126.49","265.75"
    "sha-test (workloads/)","158.73","158.73"
    "zip-test (workloads/)","47.62","52.63"


Table:  **CoreMarkPro**



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
    :header: "Benchmarks","j7200-evm: perf","j721e-idk-gw: perf"

    "4m-check (workloads/)","784.68","1075.27"
    "4m-check-reassembly (workloads/)","123.61","233.65"
    "4m-check-reassembly-tcp (workloads/)","89.61","124.38"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","33.30","42.89"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","2.59","2.77"
    "4m-cmykw2 (workloads/)","309.12","322.06"
    "4m-cmykw2-rotatew2 (workloads/)","53.29","63.36"
    "4m-reassembly (workloads/)","125.31","238.10"
    "4m-rotatew2 (workloads/)","63.73","71.63"
    "4m-tcp-mixed (workloads/)","222.22","235.29"
    "4m-x264w2 (workloads/)","2.60","2.83"
    "idct-4m (workloads/)","34.78","35.12"
    "idct-4mw1 (workloads/)","34.79","35.10"
    "ippktcheck-4m (workloads/)","796.94","1072.04"
    "ippktcheck-4mw1 (workloads/)","797.19","1093.61"
    "ipres-4m (workloads/)","147.06","208.04"
    "ipres-4mw1 (workloads/)","147.06","208.04"
    "md5-4m (workloads/)","37.92","52.80"
    "md5-4mw1 (workloads/)","36.54","52.49"
    "rgbcmyk-4m (workloads/)","163.27","164.20"
    "rgbcmyk-4mw1 (workloads/)","163.13","164.20"
    "rotate-4ms1 (workloads/)","52.36","57.14"
    "rotate-4ms1w1 (workloads/)","52.36","57.14"
    "rotate-4ms64 (workloads/)","52.74","57.67"
    "rotate-4ms64w1 (workloads/)","52.58","57.60"
    "x264-4mq (workloads/)","1.41","1.46"
    "x264-4mqw1 (workloads/)","1.40","1.45"


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
    :header: "Boot Configuration","j7200-evm: boot time (sec)","j721e-idk-gw: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","13.73 (min 13.62, max 14.02)","15.91 (min 15.82, max 15.97)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","4.46 (min 4.42, max 4.52)","7.35 (min 7.34, max 7.39)"

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

    "11025","352800.00","0.08"
    "16000","512000.00","0.09"
    "22050","705600.00","0.10"
    "24000","705600.00","0.11"
    "32000","1023999.00","0.12"
    "44100","1411199.00","0.48"
    "48000","1535999.00","0.20"
    "88200","2822396.00","0.92"
    "96000","3071995.00","0.31"

Table:  **Audio Capture**

|

.. csv-table::
    :header: "Sampling Rate (Hz)","j721e-idk-gw: Throughput (bits/sec)","j721e-idk-gw: CPU Load (%)"

    "11025","352945.00","0.15"
    "16000","512211.00","0.09"
    "22050","705891.00","0.26"
    "24000","705891.00","0.27"
    "32000","1024422.00","0.12"
    "44100","1411781.00","0.18"
    "48000","1536633.00","0.21"
    "88200","2823561.00","0.86"
    "96000","3073263.00","0.31"

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



.. csv-table::
    :header: "Benchmark","j721e-idk-gw: Test Number","j721e-idk-gw: Fps"

    "GLB25_EgyptTestC24Z16_ETC1_Offscreen test","2501011.00","46.00"


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

    " GFXBench 3.x gl_manhattan_off","1210.13","19.52"
    " GFXBench 3.x gl_trex_off","1430.81","25.55"
    " GFXBench 4.x gl_4_off","402.22","6.81"
    " GFXBench 5.x gl_5_high_off","177.98","2.77"


Table:  **GFXBench**

Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","j721e-idk-gw: Score"

    "Glmark2-Wayland","1139.00"


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

CPSW Ethernet Driver
^^^^^^^^^^^^^^^^^^^^^^^^^

- AM65x, J7200, J721e: CPSW2g
- AM64x: CPSW3g

.. rubric::  TCP Bidirectional Throughput
   :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table::
    :header: "TCP Window Size","j7200-evm: Throughput (Mbits/sec)","j7200-evm: CPU Load %","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %"

    "Default","1563.90","65.83","1849.65","70.33"

Table: **CPSW TCP Bidirectional Throughput**

.. rubric::  UDP Throughput (0% loss)
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes)","j7200-evm: Throughput (Mbits/sec)","j7200-evm: CPU Load %","j721e-idk-gw: UDP Datagram Size(bytes)","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %"

    "64","18.00","38.98","92.75","18.00","36.23","93.06"
    "128","82.00","84.23","45.48","82.00","166.51","95.69"
    "256","210.00","429.73","94.69","210.00","428.86","94.19"
    "1024","978.00","932.86","50.60","978.00","936.75","46.60"
    "1518","1472.00","955.55","47.74","1472.00","957.06","34.25"

Table: **CPSW UDP Egress Throughput (0% loss)**

.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes)","j7200-evm: Throughput (Mbits/sec)","j7200-evm: CPU Load %","j721e-idk-gw: UDP Datagram Size(bytes)","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %"

    "64","18.00","3.21","13.18","18.00","25.42","41.02"
    "128","82.00","7.61","7.43"
    "256","210.00","145.18","54.40","210.00","523.21","71.64"
    "1024","978.00","173.69","13.84","978.00","929.07","71.02"
    "1518","1472.00","9.42","0.50","1472.00","949.90","48.97"

Table: **CPSW UDP Ingress Throughput (0% loss)**

.. rubric::  UDP Throughput (possible loss)
   :name: CPSW2g-udp-throughput-possible-loss

.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes)","j7200-evm: Throughput (Mbits/sec)","j7200-evm: CPU Load %","j7200-evm: Packet Loss %","j721e-idk-gw: UDP Datagram Size(bytes)","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %","j721e-idk-gw: Packet Loss %"

    "64","18.00","38.98","92.75","0.00","18.00","36.23","93.06","0.00"
    "128","82.00","172.46","96.67","0.03","82.00","166.51","95.69","0.00"
    "256","210.00","429.73","94.69","0.00","210.00","428.86","94.19","0.00"
    "1024","978.00","932.86","50.60","0.00","978.00","936.75","46.60","0.00"
    "1518","1472.00","955.55","47.74","0.00","1472.00","957.06","34.25","0.00"

Table: **CPSW UDP Egress Throughput (possible loss)**

.. csv-table::
    :header: "Frame Size(bytes)","j7200-evm: UDP Datagram Size(bytes)","j7200-evm: Throughput (Mbits/sec)","j7200-evm: CPU Load %","j7200-evm: Packet Loss %","j721e-idk-gw: UDP Datagram Size(bytes)","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %","j721e-idk-gw: Packet Loss %"

    "64","18.00","25.88","66.24","0.14","18.00","45.23","66.75","0.01"
    "128","82.00","190.59","70.95","0.16"
    "256","210.00","145.18","54.40","0.00","210.00","523.21","71.64","0.00"
    "1024","978.00","935.84","69.98","0.10","978.00","929.07","71.02","0.00"
    "1518","1472.00","949.67","59.93","0.01","1472.00","949.90","48.97","0.00"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|

CPSW5g/9g Virtual Ethernet Driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- J7200: CPSW5g
- J721e: CPSW9g

.. rubric::  TCP Bidirectional Throughput
   :name: CPSW9g-tcp-bidirectional-throughput

.. csv-table::
    :header: "TCP Window Size","j7200-evm: Throughput (Mbits/sec)","j7200-evm: CPU Load %","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %"

    "Default","1792.31","72.93","1857.34","67.33"

Table: **CPSW9g Virtual Ethernet Driver - TCP Bidirectional Throughput**

.. rubric::  UDP Throughput (0% loss)
   :name: CPSW9g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes)","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %"

    "64","18.00","39.14","94.51"
    "128","82.00","187.05","96.81"
    "256","210.00","470.99","94.79"
    "1024","978.00","936.56","49.21"
    "1518","1472.00","956.95","31.56"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Egress Throughput (0% loss)**

.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes)","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %"

    "64","18.00","9.79","26.84"
    "128","82.00","47.76","28.63"
    "256","210.00","58.63","17.85"
    "1024","978.00","515.59","36.63"
    "1518","1472.00","957.09","47.23"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Ingress Throughput (0% loss)**

.. rubric::  UDP Throughput (possible loss)
   :name: CPSW9g-udp-throughput-possible-loss

.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes)","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %","j721e-idk-gw: Packet Loss %"

    "64","18.00","39.14","94.51","0.00"
    "128","82.00","187.05","96.81","0.00"
    "256","210.00","460.44","92.68","0.01"
    "1024","978.00","936.56","49.21","0.00"
    "1518","1472.00","956.95","31.56","0.00"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Egress Throughput (possible loss)**

.. csv-table::
    :header: "Frame Size(bytes)","j721e-idk-gw: UDP Datagram Size(bytes)","j721e-idk-gw: Throughput (Mbits/sec)","j721e-idk-gw: CPU Load %","j721e-idk-gw: Packet Loss %"

    "64","18.00","45.04","67.04","0.05"
    "128","82.00","188.57","69.02","0.04"
    "256","210.00","518.07","70.98","0.05"
    "1024","978.00","936.48","69.80","0.02"
    "1518","1472.00","957.09","47.23","0.00"

Table: **CPSW5g/9g Virtual Ethernet Driver - UDP Ingress Throughput (possible loss)**

|

CPSW Ethernet Driver
^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput
   :name: tcp-bidirectional-throughput


Table: **CPSW TCP Bidirectional Throughput**

.. rubric::  UDP Throughput (0% loss)
   :name: udp-throughput-0-loss


Table: **CPSW UDP Egress Throughput (0% loss)**


Table: **CPSW UDP Ingress Throughput (0% loss)**

.. rubric::  UDP Throughput (possible loss)
   :name: udp-throughput-possible-loss


Table: **CPSW UDP Egress Throughput (possible loss)**


Table: **CPSW UDP Ingress Throughput (possible loss)**

|

PCIe Driver
-------------------------

PCIe-ETH
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "TCP Window Size(Kbytes)","j721e-idk-gw: Bandwidth (Mbits/sec)"

    "128","0.00"
    "256","0.00"

Table: **PCI Ethernet**

PCIe-EP
^^^^^^^^^^^^^^^^^^^^^^^^^^^


















PCIe-NVMe-SSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^











J721E-IDK-GW
"""""""""""""""""""""""""""





.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","386.00","5.77","1500.00","4.30"
    "4m","816.00","12.33","720.00","1.66"
    "4k","230.00","46.84","167.00","36.11"
    "256k","772.00","10.40","711.00","3.32"




- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY



J7200-EVM
"""""""""""""""""""""""""""





.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","801.00","17.36","1522.00","5.94"
    "4m","800.00","16.68","1521.00","5.29"
    "4k","207.00","48.89","150.00","38.10"
    "256k","815.00","20.88","1519.00","10.80"




- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based
- Platform: Speed 8GT/s, Width x2
- SSD being used: PLEXTOR PX-128M8PeY


NAND Driver
-------------------------










OSPI Flash Driver
-------------------------









J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^




UBIFS
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write UBIFS Throughput (Mbytes/sec)","j721e-idk-gw: Write UBIFS CPU Load (%)","j721e-idk-gw: Read UBIFS Throughput (Mbytes/sec)","j721e-idk-gw: Read UBIFS CPU Load (%)"

    "102400","0.59 (min 0.46, max 1.06)","21.91 (min 21.48, max 22.85)","33.87","8.33"
    "262144","0.42 (min 0.30, max 0.49)","20.17 (min 17.33, max 21.37)","33.78","8.33"





RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","j721e-idk-gw: Raw Read Throughput (Mbytes/sec)"

    "50","39.06"






J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^




UBIFS
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write UBIFS Throughput (Mbytes/sec)","j7200-evm: Write UBIFS CPU Load (%)","j7200-evm: Read UBIFS Throughput (Mbytes/sec)","j7200-evm: Read UBIFS CPU Load (%)"

    "102400","0.19 (min 0.14, max 0.31)","41.26 (min 40.08, max 42.50)","82.16","40.00"
    "262144","0.16 (min 0.11, max 0.20)","41.00 (min 39.98, max 42.03)","82.18","33.33"
    "524288","0.16 (min 0.12, max 0.20)","41.10 (min 39.97, max 41.86)","78.96","33.33"
    "1048576","0.17 (min 0.12, max 0.20)","40.69 (min 39.80, max 41.61)","78.43","33.33"





RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","j7200-evm: Raw Read Throughput (Mbytes/sec)"

    "50","208.33"


















QSPI Flash Driver
-------------------------






























UBoot QSPI/OSPI Driver
-------------------------





J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","1614.51","37577.98"
    "800000","1617.37","39196.17"
    "1000000","1617.85","39863.75"
    "2000000","1624.75","40255.53"







J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","411.53","204800.00"
    "800000","413.22","248242.42"
    "1000000","416.76","277694.92"
    "2000000","422.13","300623.85"






















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




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|




.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","87148.94","372363.64"
    "800000","101135.80","455111.11"
    "1000000","104356.69","564965.52"

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



J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","57.20","1.52","314.00","1.77"
    "4m","56.90","1.32","313.00","1.21"
    "4k","59.70","32.44","55.00","28.17"
    "256k","57.30","2.37","314.00","3.43"

|




J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","61.30","1.01","174.00","0.60"
    "4m","61.50","1.00","174.00","0.52"
    "4k","51.70","20.11","56.30","20.70"
    "256k","61.30","1.25","173.00","1.28"

|

















































UBoot EMMC Driver
-------------------------
|



J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|



.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "2000000","59470.05","309132.08"
    "4000000","59686.70","318135.92"

|





J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|



.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "2000000","62534.35","174297.87"
    "4000000","62060.61","177604.34"

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



















































J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j7200-evm: Write EXT4 Throughput (Mbytes/sec)","j7200-evm: Write EXT4 CPU Load (%)","j7200-evm: Read EXT4 Throughput (Mbytes/sec)","j7200-evm: Read EXT4 CPU Load (%)"

    "1m","18.50","0.79","87.10","1.03"
    "4m","18.90","0.66","87.00","0.78"
    "4k","4.81","4.33","16.30","9.86"
    "256k","18.40","0.99","84.00","1.59"

|





J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","j721e-idk-gw: Write EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Write EXT4 CPU Load (%)","j721e-idk-gw: Read EXT4 Throughput (Mbytes/sec)","j721e-idk-gw: Read EXT4 CPU Load (%)"

    "1m","13.00","0.39","47.40","0.42"
    "4m","14.80","0.42","47.40","0.39"
    "4k","5.20","2.70","13.30","5.36"
    "256k","12.80","0.54","46.90","0.51"

|
















|
































































|


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|


UBoot MMC/SD Driver
-------------------------
|



J721E-IDK-GW
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j721e-idk-gw: Write Throughput (Kbytes/sec)","j721e-idk-gw: Read Throughput (Kbytes/sec)"

    "400000","16318.73","43115.79"
    "800000","19140.19","45010.99"
    "1000000","20029.34","46022.47"





J7200-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "File size (bytes in hex)","j7200-evm: Write Throughput (Kbytes/sec)","j7200-evm: Read Throughput (Kbytes/sec)"

    "400000","26425.81","78769.23"
    "800000","19692.31","86231.58"
    "1000000","21250.32","89043.48"

|
The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
|


|






|





















|





|









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
    :header: "Algorithm","Buffer Size (in bytes)","j7200-evm: throughput (KBytes/Sec)","j721e-idk-gw: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","44521.81","52761.26"
    "aes-128-cbc","16","938.44","1133.67"
    "aes-128-cbc","16384","214182.57","207672.66"
    "aes-128-cbc","256","13571.24","17465.51"
    "aes-128-cbc","64","3722.79","4562.69"
    "aes-128-cbc","8192","170003.11","178577.41"
    "aes-192-cbc","1024","44712.62","52353.37"
    "aes-192-cbc","16","947.01","1071.69"
    "aes-192-cbc","16384","212893.70","198240.94"
    "aes-192-cbc","256","13535.91","17482.84"
    "aes-192-cbc","64","3745.86","4561.47"
    "aes-192-cbc","8192","167736.66","169492.48"
    "aes-256-cbc","1024","45214.38","50931.71"
    "aes-256-cbc","16","935.81","1115.14"
    "aes-256-cbc","16384","198257.32","178804.05"
    "aes-256-cbc","256","13960.96","17335.81"
    "aes-256-cbc","64","3748.97","4417.00"
    "aes-256-cbc","8192","164069.38","155598.85"
    "des-cbc","1024","47597.57","47576.41"
    "des-cbc","16","11318.79","11180.66"
    "des-cbc","16384","50036.74","50053.12"
    "des-cbc","256","41261.31","41317.21"
    "des-cbc","64","26892.33","27204.59"
    "des-cbc","8192","49859.24","49872.90"
    "des3","1024","42792.62","46236.33"
    "des3","16","935.54","1044.65"
    "des3","16384","127942.66","102105.09"
    "des3","256","13204.99","16380.67"
    "des3","64","3776.51","4283.56"
    "des3","8192","110895.10","94262.61"
    "md5","1024","90435.24","96179.20"
    "md5","16","2038.52","2198.31"
    "md5","16384","266982.74","271324.50"
    "md5","256","29715.03","31678.29"
    "md5","64","7864.92","8561.90"
    "md5","8192","234141.01","241175.21"
    "sha1","1024","16286.04","23866.71"
    "sha1","16","281.41","420.67"
    "sha1","16384","124174.34","124316.33"
    "sha1","256","4363.18","6708.39"
    "sha1","64","1125.14","1691.14"
    "sha1","8192","84235.61","97288.19"
    "sha224","1024","115958.78","113622.02"
    "sha224","16","2049.58","2007.43"
    "sha224","16384","661793.45","661886.29"
    "sha224","256","31894.10","31087.53"
    "sha224","64","8244.97","8048.73"
    "sha224","8192","502601.05","497183.40"
    "sha256","1024","16263.85","23901.53"
    "sha256","16","281.70","419.46"
    "sha256","16384","141170.01","143234.39"
    "sha256","256","4480.34","6453.76"
    "sha256","64","1122.03","1667.52"
    "sha256","8192","93929.47","109464.23"
    "sha384","1024","70566.23","74619.90"
    "sha384","16","1820.29","2027.15"
    "sha384","16384","161420.63","163179.18"
    "sha384","256","25743.87","27471.10"
    "sha384","64","7463.08","8138.39"
    "sha384","8192","148226.05","150937.60"
    "sha512","1024","16421.55","23232.17"
    "sha512","16","277.16","421.79"
    "sha512","16384","150809.26","164014.76"
    "sha512","256","4405.33","6504.96"
    "sha512","64","1124.76","1752.55"
    "sha512","8192","96813.06","117325.82"


|
|

.. csv-table::
    :header: "Algorithm","j7200-evm: CPU Load","j721e-idk-gw: CPU Load"

    "aes-128-cbc","34.00","33.00"
    "aes-192-cbc","31.00","31.00"
    "aes-256-cbc","31.00","32.00"
    "des-cbc","99.00","99.00"
    "des3","28.00","27.00"
    "md5","99.00","99.00"
    "sha1","64.00","60.00"
    "sha224","99.00","99.00"
    "sha256","66.00","60.00"
    "sha384","98.00","99.00"
    "sha512","68.00","61.00"



-

|
| Listed for each algorithm are the code snippets used to run each
  benchmark test.

|

::

    time -v openssl speed -elapsed -evp aes-128-cbc

-

