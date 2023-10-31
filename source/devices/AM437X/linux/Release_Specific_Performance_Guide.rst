======================================
 Linux 09.01.00 Performance Guide
======================================

.. rubric::  **Read This First**
   :name: read-this-first-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| AM437x-gpevm   | AM437x-gpevm Evaluation Module rev 1.5A with ARM running at 1000MHz, DDR3-400 (400MHz/800 MT/S), TMDSEVM437X   |
+----------------+----------------------------------------------------------------------------------------------------------------+

Table:  Evaluation Modules

|

.. rubric::  About This Manual
   :name: about-this-manual-kernel-perf-guide

This document provides performance data for each of the device drivers
which are part of the Processor SDK Linux package. This document should be
used in conjunction with release notes and user guides provided with the
Processor SDK Linux package for information on specific issues present
with drivers included in a particular release.

.. rubric::  If You Need Assistance
   :name: if-you-need-assistance-kernel-perf-guide

For further information or to report any problems, contact
http://e2e.ti.com/ or http://support.ti.com/


System Benchmarks
-------------------


LMBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
LMBench is a collection of microbenchmarks of which the memory bandwidth 
and latency related ones are typically used to estimate processor 
memory system performance. More information about lmbench at
http://lmbench.sourceforge.net/whatis_lmbench.html and
http://lmbench.sourceforge.net/man/lmbench.8.html

  
**Latency**: lat_mem_rd-stride128-szN, where N is equal to or smaller than the cache
size at given level measures the cache miss penalty. N that is at least
double the size of last level cache is the latency to external memory.

**Bandwidth**: bw_mem_bcopy-N, where N is equal to or smaller than the cache size at
a given level measures the achievable memory bandwidth from software doing
a memcpy() type operation. Typical use is for external memory bandwidth
calculation. The bandwidth is calculated as byte read and written counts
as 1 which should be roughly half of STREAM copy result.

Execute the LMBench with the following:

::

    cd /opt/ltp
    ./runltp -P j721e-idk-gw -f ddt/lmbench -s LMBENCH_L_PERF_0001

.. csv-table::
    :header: "Benchmarks","am43xx-gpevm: perf"

    "af_unix_sock_stream_latency (microsec)","31.75"
    "af_unix_socket_stream_bandwidth (MBs)","196.34"
    "bw_file_rd-io-1mb (MB/s)","199.78"
    "bw_file_rd-o2c-1mb (MB/s)","164.61"
    "bw_mem-bcopy-16mb (MB/s)","193.25"
    "bw_mem-bcopy-1mb (MB/s)","198.33"
    "bw_mem-bcopy-2mb (MB/s)","198.83"
    "bw_mem-bcopy-4mb (MB/s)","197.07"
    "bw_mem-bcopy-8mb (MB/s)","198.09"
    "bw_mem-bzero-16mb (MB/s)","672.58"
    "bw_mem-bzero-1mb (MB/s)","434.40 (min 198.33, max 670.47)"
    "bw_mem-bzero-2mb (MB/s)","436.23 (min 198.83, max 673.63)"
    "bw_mem-bzero-4mb (MB/s)","433.71 (min 197.07, max 670.35)"
    "bw_mem-bzero-8mb (MB/s)","435.78 (min 198.09, max 673.46)"
    "bw_mem-cp-16mb (MB/s)","194.28"
    "bw_mem-cp-1mb (MB/s)","437.96 (min 201.49, max 674.42)"
    "bw_mem-cp-2mb (MB/s)","436.93 (min 200.68, max 673.17)"
    "bw_mem-cp-4mb (MB/s)","437.07 (min 200.73, max 673.40)"
    "bw_mem-cp-8mb (MB/s)","437.09 (min 201.01, max 673.17)"
    "bw_mem-fcp-16mb (MB/s)","243.87"
    "bw_mem-fcp-1mb (MB/s)","458.69 (min 246.91, max 670.47)"
    "bw_mem-fcp-2mb (MB/s)","457.97 (min 242.31, max 673.63)"
    "bw_mem-fcp-4mb (MB/s)","455.64 (min 240.92, max 670.35)"
    "bw_mem-fcp-8mb (MB/s)","459.15 (min 244.84, max 673.46)"
    "bw_mem-frd-16mb (MB/s)","202.94"
    "bw_mem-frd-1mb (MB/s)","227.82 (min 208.72, max 246.91)"
    "bw_mem-frd-2mb (MB/s)","224.55 (min 206.78, max 242.31)"
    "bw_mem-frd-4mb (MB/s)","220.84 (min 200.75, max 240.92)"
    "bw_mem-frd-8mb (MB/s)","223.39 (min 201.93, max 244.84)"
    "bw_mem-fwr-16mb (MB/s)","672.13"
    "bw_mem-fwr-1mb (MB/s)","441.57 (min 208.72, max 674.42)"
    "bw_mem-fwr-2mb (MB/s)","439.98 (min 206.78, max 673.17)"
    "bw_mem-fwr-4mb (MB/s)","437.08 (min 200.75, max 673.40)"
    "bw_mem-fwr-8mb (MB/s)","437.55 (min 201.93, max 673.17)"
    "bw_mem-rd-16mb (MB/s)","314.02"
    "bw_mem-rd-1mb (MB/s)","294.78 (min 273.19, max 316.36)"
    "bw_mem-rd-2mb (MB/s)","291.84 (min 270.05, max 313.63)"
    "bw_mem-rd-4mb (MB/s)","292.39 (min 269.96, max 314.81)"
    "bw_mem-rd-8mb (MB/s)","292.56 (min 270.78, max 314.33)"
    "bw_mem-rdwr-16mb (MB/s)","245.76"
    "bw_mem-rdwr-1mb (MB/s)","225.89 (min 201.49, max 250.28)"
    "bw_mem-rdwr-2mb (MB/s)","223.19 (min 200.68, max 245.70)"
    "bw_mem-rdwr-4mb (MB/s)","223.16 (min 200.73, max 245.59)"
    "bw_mem-rdwr-8mb (MB/s)","223.75 (min 201.01, max 246.48)"
    "bw_mem-wr-16mb (MB/s)","270.81"
    "bw_mem-wr-1mb (MB/s)","261.74 (min 250.28, max 273.19)"
    "bw_mem-wr-2mb (MB/s)","257.88 (min 245.70, max 270.05)"
    "bw_mem-wr-4mb (MB/s)","257.78 (min 245.59, max 269.96)"
    "bw_mem-wr-8mb (MB/s)","258.63 (min 246.48, max 270.78)"
    "bw_mmap_rd-mo-1mb (MB/s)","210.39"
    "bw_mmap_rd-o2c-1mb (MB/s)","161.06"
    "bw_pipe (MB/s)","391.78"
    "bw_unix (MB/s)","196.34"
    "lat_connect (us)","76.04"
    "lat_ctx-2-128k (us)","0.00"
    "lat_ctx-2-256k (us)","0.00"
    "lat_ctx-4-128k (us)","0.00"
    "lat_ctx-4-256k (us)","0.00"
    "lat_fs-0k (num_files)","233.00"
    "lat_fs-10k (num_files)","75.00"
    "lat_fs-1k (num_files)","120.00"
    "lat_fs-4k (num_files)","123.00"
    "lat_mem_rd-stride128-sz1000k (ns)","98.27"
    "lat_mem_rd-stride128-sz125k (ns)","16.01"
    "lat_mem_rd-stride128-sz250k (ns)","42.07"
    "lat_mem_rd-stride128-sz31k (ns)","4.01"
    "lat_mem_rd-stride128-sz50 (ns)","4.01"
    "lat_mem_rd-stride128-sz500k (ns)","88.77"
    "lat_mem_rd-stride128-sz62k (ns)","16.91"
    "lat_mmap-1m (us)","76.00"
    "lat_ops-double-add (ns)","5.02"
    "lat_ops-double-div (ns)","25.09"
    "lat_ops-double-mul (ns)","7.02"
    "lat_ops-float-add (ns)","5.04"
    "lat_ops-float-div (ns)","15.05"
    "lat_ops-float-mul (ns)","6.02"
    "lat_ops-int-add (ns)","1.03"
    "lat_ops-int-bit (ns)","0.76"
    "lat_ops-int-div (ns)","96.06"
    "lat_ops-int-mod (ns)","23.91"
    "lat_ops-int-mul (ns)","4.14"
    "lat_ops-int64-add (ns)","1.12"
    "lat_ops-int64-bit (ns)","0.67"
    "lat_ops-int64-div (ns)","200.99"
    "lat_ops-int64-mod (ns)","42.62"
    "lat_ops-int64-mul (ns)","4.16"
    "lat_pagefault (us)","1.42"
    "lat_pipe (us)","29.91"
    "lat_proc-exec (us)","1353.25"
    "lat_proc-fork (us)","988.17"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","33.01"
    "lat_sem (us)","4.47"
    "lat_sig-catch (us)","5.81"
    "lat_sig-install (us)","0.88"
    "lat_sig-prot (us)","0.57"
    "lat_syscall-fstat (us)","3.43"
    "lat_syscall-null (us)","0.39"
    "lat_syscall-open (us)","263.14"
    "lat_syscall-read (us)","0.67"
    "lat_syscall-stat (us)","5.04"
    "lat_syscall-write (us)","0.55"
    "lat_tcp (us)","0.87"
    "lat_unix (us)","31.75"
    "latency_for_0.50_mb_block_size (nanosec)","88.77"
    "latency_for_1.00_mb_block_size (nanosec)","49.13 (min 0.00, max 98.27)"
    "pipe_bandwidth (MBs)","391.78"
    "pipe_latency (microsec)","29.91"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","33.01"
    "semaphore_latency (microsec)","4.47"
    "signal_handler_latency (microsec)","0.88"
    "signal_handler_overhead (microsec)","5.81"
    "tcp_ip_connection_cost_to_localhost (microsec)","76.04"
    "tcp_latency_using_localhost (microsec)","0.87"


Table:  **LM Bench Metrics**



Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

Execute the benchmark with the following:

::

    runDhrystone

.. csv-table::
    :header: "Benchmarks","am43xx-gpevm: perf"

    "cpu_clock (MHz)","1000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.50"
    "dhrystone_per_second (DhrystoneP)","4444444.50"


Table:  **Dhrystone Benchmark**



Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Whetstone is a benchmark primarily measuring floating-point arithmetic performance.

Execute the benchmark with the following:

::

    runWhetstone

.. csv-table::
    :header: "Benchmarks","am43xx-gpevm: perf"

    "whetstone (MIPS)","3333.30"


Table:  **Whetstone Benchmark**



Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am43xx-gpevm: perf"

    "linpack (Kflops)","192209.00"


Table:  **Linpack Benchmark**



NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html


.. csv-table::
    :header: "Benchmarks","am43xx-gpevm: perf"

    "assignment (Iterations)","7.20"
    "fourier (Iterations)","13053.00"
    "fp_emulation (Iterations)","75.00"
    "huffman (Iterations)","855.02"
    "idea (Iterations)","1830.40"
    "lu_decomposition (Iterations)","338.30"
    "neural_net (Iterations)","9.63"
    "numeric_sort (Iterations)","503.24"
    "string_sort (Iterations)","64.02"


Table:  **NBench Benchmarks**



Stream
^^^^^^^^^^^^^^^^^^^^^^^^^^^
STREAM is a microbenchmark for measuring data memory system performance without
any data reuse. It is designed to miss on caches and exercise data prefetcher
and speculative accesses.
It uses double precision floating point (64bit) but in
most modern processors the memory access will be the bottleneck.
The four individual scores are copy, scale as in multiply by constant,
add two numbers, and triad for multiply accumulate.
For bandwidth, a byte read counts as one and a byte written counts as one,
resulting in a score that is double the bandwidth LMBench will show.

Execute the benchmark with the following:

::

    stream_c

.. csv-table::
    :header: "Benchmarks","am43xx-gpevm: perf"

    "add (MB/s)","327.10"
    "copy (MB/s)","435.10"
    "scale (MB/s)","654.20"
    "triad (MB/s)","381.50"


Table:  **Stream**



Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am43xx-gpevm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","46.96 (min 46.73, max 47.46)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","8.90 (min 8.79, max 9.26)"

Table:  **Boot time MMC/SD**


 
 


ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64


.. csv-table::
    :header: "Sampling Rate (Hz)","am43xx-gpevm: Throughput (bits/sec)","am43xx-gpevm: CPU Load (%)"

    "8000","255997.00","0.54"
    "11025","352795.00","0.63"
    "16000","511993.00","0.75"
    "22050","705591.00","1.09"
    "24000","705588.00","0.87"
    "32000","1023983.00","0.36"
    "44100","1411177.00","1.43"
    "48000","1535975.00","1.66"
    "88200","2822352.00","2.86"
    "96000","3071948.00","0.65"

Table:  **Audio Capture**


|


.. csv-table::
    :header: "Sampling Rate (Hz)","am43xx-gpevm: Throughput (bits/sec)","am43xx-gpevm: CPU Load (%)"

    "8000","256102.00","0.70"
    "11025","352941.00","0.52"
    "16000","512204.00","1.67"
    "22050","705881.00","0.96"
    "24000","705880.00","0.78"
    "32000","1024406.00","0.16"
    "44100","1411758.00","1.27"
    "48000","1536609.00","2.42"
    "88200","2823517.00","2.55"
    "96000","3073215.00","0.57"

Table:  **Audio Playback**
 

|

 

NAND Driver
-------------------------






AM43XX-GPEVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am43xx-gpevm: Write UBIFS Throughput (Mbytes/sec)","am43xx-gpevm: Write UBIFS CPU Load (%)","am43xx-gpevm: Read UBIFS Throughput (Mbytes/sec)","am43xx-gpevm: Read UBIFS CPU Load (%)"

    "102400","5.17 (min 5.10, max 5.37)","77.66 (min 76.81, max 77.96)","10.67","39.02"
    "262144","5.11 (min 5.08, max 5.16)","77.82 (min 77.70, max 78.00)","10.66","39.98"
    "524288","5.12 (min 5.08, max 5.15)","77.62 (min 77.22, max 77.94)","10.66","40.94"
    "1048576","5.11 (min 5.09, max 5.14)","77.67 (min 77.47, max 78.14)","10.67","41.04"
    "5242880","5.12 (min 5.07, max 5.16)","77.81 (min 77.47, max 78.25)","10.66","40.25"

 


MMC/SD Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

| 

 




AM43XX-GPEVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","am43xx-gpevm: Write EXT4 Throughput (Mbytes/sec)","am43xx-gpevm: Write EXT4 CPU Load (%)","am43xx-gpevm: Read EXT4 Throughput (Mbytes/sec)","am43xx-gpevm: Read EXT4 CPU Load (%)"

    "1m","5.90","3.40","26.60","8.92"
    "4m","9.41","2.41","26.60","4.40"
    "4k","2.56","12.38","8.59","31.77"
    "256k","7.97","3.26","26.60","9.68"

|





 
|


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|



UBoot MMC/SD Driver
-------------------------
| 






AM43XX-GPEVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","am43xx-gpevm: Write Throughput (Kbytes/sec)","am43xx-gpevm: Read Throughput (Kbytes/sec)"

    "400000","10556.70","18618.18"
    "800000","9649.00","19095.57"
    "1000000","7713.75","19389.35"


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card



|



USB Driver
-------------------------
 


USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^










.. csv-table::
    :header: "Number of Blocks","am43xx-gpevm: Throughput (MB/sec)"

    "150","18.30"

Table: **USBDEVICE HIGHSPEED SLAVE READ THROUGHPUT**

|
|



.. csv-table::
    :header: "Number of Blocks","am43xx-gpevm: Throughput (MB/sec)"

    "150","21.90"

Table: **USBDEVICE HIGHSPEED SLAVE WRITE THROUGHPUT**

|
|
