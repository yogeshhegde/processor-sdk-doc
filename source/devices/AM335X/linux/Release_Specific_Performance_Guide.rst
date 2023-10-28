======================================
 Linux 09.00.00 Performance Guide
======================================

.. rubric::  **Read This First**
   :name: read-this-first-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| AM335x EVM     | AM335x Evaluation Module rev 1.5B with ARM running at 1000MHz, DDR3-400 (400MHz/800 MT/S), TMDXEVM3358         |
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
    :header: "Benchmarks","am335x-evm: perf"

    "af_unix_sock_stream_latency (microsec)","40.96"
    "af_unix_socket_stream_bandwidth (MBs)","186.32"
    "bw_file_rd-io-1mb (MB/s)","157.62"
    "bw_file_rd-o2c-1mb (MB/s)","147.34"
    "bw_mem-bcopy-16mb (MB/s)","203.35"
    "bw_mem-bcopy-1mb (MB/s)","205.80"
    "bw_mem-bcopy-2mb (MB/s)","206.70"
    "bw_mem-bcopy-4mb (MB/s)","200.71"
    "bw_mem-bcopy-8mb (MB/s)","193.36"
    "bw_mem-bzero-16mb (MB/s)","996.33"
    "bw_mem-bzero-1mb (MB/s)","595.43 (min 205.80, max 985.06)"
    "bw_mem-bzero-2mb (MB/s)","595.40 (min 206.70, max 984.09)"
    "bw_mem-bzero-4mb (MB/s)","592.30 (min 200.71, max 983.89)"
    "bw_mem-bzero-8mb (MB/s)","588.81 (min 193.36, max 984.25)"
    "bw_mem-cp-16mb (MB/s)","193.71"
    "bw_mem-cp-1mb (MB/s)","582.73 (min 182.98, max 982.48)"
    "bw_mem-cp-2mb (MB/s)","589.61 (min 195.12, max 984.09)"
    "bw_mem-cp-4mb (MB/s)","598.18 (min 192.08, max 1004.27)"
    "bw_mem-cp-8mb (MB/s)","587.30 (min 185.47, max 989.12)"
    "bw_mem-fcp-16mb (MB/s)","184.96"
    "bw_mem-fcp-1mb (MB/s)","588.96 (min 192.86, max 985.06)"
    "bw_mem-fcp-2mb (MB/s)","586.05 (min 188.01, max 984.09)"
    "bw_mem-fcp-4mb (MB/s)","584.21 (min 184.53, max 983.89)"
    "bw_mem-fcp-8mb (MB/s)","581.35 (min 178.44, max 984.25)"
    "bw_mem-frd-16mb (MB/s)","250.22"
    "bw_mem-frd-1mb (MB/s)","230.66 (min 192.86, max 268.46)"
    "bw_mem-frd-2mb (MB/s)","219.60 (min 188.01, max 251.19)"
    "bw_mem-frd-4mb (MB/s)","217.29 (min 184.53, max 250.05)"
    "bw_mem-frd-8mb (MB/s)","214.27 (min 178.44, max 250.09)"
    "bw_mem-fwr-16mb (MB/s)","996.02"
    "bw_mem-fwr-1mb (MB/s)","625.47 (min 268.46, max 982.48)"
    "bw_mem-fwr-2mb (MB/s)","617.64 (min 251.19, max 984.09)"
    "bw_mem-fwr-4mb (MB/s)","627.16 (min 250.05, max 1004.27)"
    "bw_mem-fwr-8mb (MB/s)","619.61 (min 250.09, max 989.12)"
    "bw_mem-rd-16mb (MB/s)","252.78"
    "bw_mem-rd-1mb (MB/s)","627.70 (min 270.82, max 984.57)"
    "bw_mem-rd-2mb (MB/s)","620.30 (min 255.04, max 985.55)"
    "bw_mem-rd-4mb (MB/s)","628.24 (min 252.84, max 1003.64)"
    "bw_mem-rd-8mb (MB/s)","628.84 (min 252.53, max 1005.15)"
    "bw_mem-rdwr-16mb (MB/s)","204.39"
    "bw_mem-rdwr-1mb (MB/s)","195.46 (min 182.98, max 207.94)"
    "bw_mem-rdwr-2mb (MB/s)","199.62 (min 195.12, max 204.12)"
    "bw_mem-rdwr-4mb (MB/s)","198.43 (min 192.08, max 204.77)"
    "bw_mem-rdwr-8mb (MB/s)","194.90 (min 185.47, max 204.32)"
    "bw_mem-wr-16mb (MB/s)","996.02"
    "bw_mem-wr-1mb (MB/s)","596.26 (min 207.94, max 984.57)"
    "bw_mem-wr-2mb (MB/s)","594.84 (min 204.12, max 985.55)"
    "bw_mem-wr-4mb (MB/s)","604.21 (min 204.77, max 1003.64)"
    "bw_mem-wr-8mb (MB/s)","604.74 (min 204.32, max 1005.15)"
    "bw_mmap_rd-mo-1mb (MB/s)","253.55"
    "bw_mmap_rd-o2c-1mb (MB/s)","167.36"
    "bw_pipe (MB/s)","322.54"
    "bw_unix (MB/s)","186.32"
    "lat_connect (us)","85.15"
    "lat_ctx-2-128k (us)","28.67"
    "lat_ctx-2-256k (us)","5.36"
    "lat_ctx-4-128k (us)","34.51"
    "lat_ctx-4-256k (us)","0.00"
    "lat_fs-0k (num_files)","198.00"
    "lat_fs-10k (num_files)","74.00"
    "lat_fs-1k (num_files)","111.00"
    "lat_fs-4k (num_files)","101.00"
    "lat_mem_rd-stride128-sz1000k (ns)","220.85"
    "lat_mem_rd-stride128-sz125k (ns)","11.74"
    "lat_mem_rd-stride128-sz250k (ns)","62.97"
    "lat_mem_rd-stride128-sz31k (ns)","3.03"
    "lat_mem_rd-stride128-sz50 (ns)","3.00"
    "lat_mem_rd-stride128-sz500k (ns)","183.34"
    "lat_mem_rd-stride128-sz62k (ns)","8.87"
    "lat_mmap-1m (us)","117.00"
    "lat_ops-double-add (ns)","8.97"
    "lat_ops-double-div (ns)","57.32"
    "lat_ops-double-mul (ns)","11.08"
    "lat_ops-float-add (ns)","8.97"
    "lat_ops-float-div (ns)","33.20"
    "lat_ops-float-mul (ns)","10.06"
    "lat_ops-int-add (ns)","1.01"
    "lat_ops-int-bit (ns)","0.67"
    "lat_ops-int-div (ns)","72.83"
    "lat_ops-int-mod (ns)","25.49"
    "lat_ops-int-mul (ns)","6.64"
    "lat_ops-int64-add (ns)","1.06"
    "lat_ops-int64-bit (ns)","0.68"
    "lat_ops-int64-div (ns)","188.60"
    "lat_ops-int64-mod (ns)","52.12"
    "lat_ops-int64-mul (ns)","6.07"
    "lat_pagefault (us)","1.62"
    "lat_pipe (us)","41.00"
    "lat_proc-exec (us)","1521.00"
    "lat_proc-fork (us)","1191.40"
    "lat_proc-proccall (us)","0.02"
    "lat_select (us)","41.44"
    "lat_sem (us)","6.11"
    "lat_sig-catch (us)","8.24"
    "lat_sig-install (us)","1.33"
    "lat_sig-prot (us)","0.74"
    "lat_syscall-fstat (us)","4.55"
    "lat_syscall-null (us)","0.49"
    "lat_syscall-open (us)","316.11"
    "lat_syscall-read (us)","0.86"
    "lat_syscall-stat (us)","6.38"
    "lat_syscall-write (us)","0.67"
    "lat_tcp (us)","1.05"
    "lat_unix (us)","40.96"
    "latency_for_0.50_mb_block_size (nanosec)","183.34"
    "latency_for_1.00_mb_block_size (nanosec)","110.42 (min 0.00, max 220.85)"
    "pipe_bandwidth (MBs)","322.54"
    "pipe_latency (microsec)","41.00"
    "procedure_call (microsec)","0.02"
    "select_on_200_tcp_fds (microsec)","41.44"
    "semaphore_latency (microsec)","6.11"
    "signal_handler_latency (microsec)","1.33"
    "signal_handler_overhead (microsec)","8.24"
    "tcp_ip_connection_cost_to_localhost (microsec)","85.15"
    "tcp_latency_using_localhost (microsec)","1.05"


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
    :header: "Benchmarks","am335x-evm: perf"

    "cpu_clock (MHz)","1000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.10"
    "dhrystone_per_second (DhrystoneP)","3773585.00"


Table:  **Dhrystone Benchmark**



Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Whetstone is a benchmark primarily measuring floating-point arithmetic performance.

Execute the benchmark with the following:

::

    runWhetstone

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf"

    "whetstone (MIPS)","833.30"


Table:  **Whetstone Benchmark**



Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf"

    "linpack (Kflops)","50419.00"


Table:  **Linpack Benchmark**



NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html


.. csv-table::
    :header: "Benchmarks","am335x-evm: perf"

    "assignment (Iterations)","7.77"
    "fourier (Iterations)","2891.70"
    "fp_emulation (Iterations)","70.38"
    "huffman (Iterations)","727.35"
    "idea (Iterations)","1706.30"
    "lu_decomposition (Iterations)","76.53"
    "neural_net (Iterations)","2.21"
    "numeric_sort (Iterations)","418.37"
    "string_sort (Iterations)","67.17"


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
    :header: "Benchmarks","am335x-evm: perf"

    "add (MB/s)","528.70"
    "copy (MB/s)","486.60"
    "scale (MB/s)","614.30"
    "triad (MB/s)","445.60"


Table:  **Stream**



ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64


.. csv-table::
    :header: "Sampling Rate (Hz)","am335x-evm: Throughput (bits/sec)","am335x-evm: CPU Load (%)"

    "8000","255998.00","2.27"
    "11025","352796.00","2.61"
    "16000","511995.00","3.75"
    "22050","705594.00","4.14"
    "24000","705592.00","3.44"
    "32000","1023988.00","7.47"
    "44100","1411183.00","5.03"
    "48000","1535983.00","2.48"
    "88200","2822364.00","7.95"
    "96000","3071961.00","12.37"

Table:  **Audio Capture**


|


.. csv-table::
    :header: "Sampling Rate (Hz)","am335x-evm: Throughput (bits/sec)","am335x-evm: CPU Load (%)"

    "8000","256101.00","0.85"
    "11025","352940.00","0.78"
    "16000","512203.00","0.17"
    "22050","705880.00","1.55"
    "24000","705878.00","1.29"
    "32000","1024404.00","0.29"
    "44100","1411756.00","2.13"
    "48000","1536606.00","4.54"
    "88200","2823510.00","4.36"
    "96000","3073208.00","0.77"

Table:  **Audio Playback**
 

|

 

NAND Driver
-------------------------




AM335X-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write UBIFS Throughput (Mbytes/sec)","am335x-evm: Write UBIFS CPU Load (%)","am335x-evm: Read UBIFS Throughput (Mbytes/sec)","am335x-evm: Read UBIFS CPU Load (%)"

    "102400","3.45 (min 3.41, max 3.56)","68.18 (min 67.31, max 68.65)","6.32","32.26"
    "262144","3.51 (min 3.47, max 3.58)","65.30 (min 64.51, max 65.89)","6.30","29.16"
    "524288","3.42 (min 3.39, max 3.44)","68.32 (min 67.94, max 69.29)","6.33","29.78"
    "1048576","3.41 (min 3.38, max 3.42)","68.15 (min 67.20, max 68.90)","6.34","29.78"
    "5242880","3.42 (min 3.39, max 3.44)","68.06 (min 66.88, max 69.18)","6.34","28.61"





USB Driver
-------------------------
 


USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. csv-table::
    :header: "Number of Blocks","am335x-evm: Throughput (MB/sec)"

    "150","18.00"

Table: **USBDEVICE HIGHSPEED SLAVE READ THROUGHPUT**

|
|



.. csv-table::
    :header: "Number of Blocks","am335x-evm: Throughput (MB/sec)"

    "150","7.60"

Table: **USBDEVICE HIGHSPEED SLAVE WRITE THROUGHPUT**

|
|

