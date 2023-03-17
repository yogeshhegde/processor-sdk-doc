..  http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_RT_Kernel_Performance_Guide

..  http://lcpdresults.itg.ti.com/LCPD/RT-linux/performance/publish/data/08.02.00/am654x-evm/rst/

.. rubric::  **Read This First**
   :name: read-this-first-rt-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+---------------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                         |
+================+=====================================================================================================================+
| AM65x EVM      | AM65x Evaluation Module rev 1.0 with ARM running at 800MHz, DDR4-2400 (1600 MT/S), TMDX654GPEVM                     |
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
http://e2e.ti.com/ or http://support.ti.com/


System Benchmarks
-------------------------

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

**Bandwidth**: bw_mem_bcopy-N, where N is is equal to or smaller than the cache size at
a given level measures the achievable memory bandwidth from software doing
a memcpy() type operation. Typical use is for external memory bandwidth
calculation. The bandwidth is calculated as byte read and written counts
as 1 which should be roughly half of STREAM copy result.

.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "af_unix_sock_stream_latency (microsec)","62.08"
    "af_unix_socket_stream_bandwidth (MBs)","1105.78"
    "bw_file_rd-io-1mb (MB/s)","1001.67"
    "bw_file_rd-o2c-1mb (MB/s)","559.81"
    "bw_mem-bcopy-16mb (MB/s)","880.91"
    "bw_mem-bcopy-1mb (MB/s)","1054.48"
    "bw_mem-bcopy-2mb (MB/s)","883.00"
    "bw_mem-bcopy-4mb (MB/s)","878.16"
    "bw_mem-bcopy-8mb (MB/s)","884.76"
    "bw_mem-bzero-16mb (MB/s)","1645.08"
    "bw_mem-bzero-1mb (MB/s)","2764.18 (min 1054.48, max 4473.87)"
    "bw_mem-bzero-2mb (MB/s)","1603.91 (min 883.00, max 2324.81)"
    "bw_mem-bzero-4mb (MB/s)","1290.75 (min 878.16, max 1703.34)"
    "bw_mem-bzero-8mb (MB/s)","1267.04 (min 884.76, max 1649.31)"
    "bw_mem-cp-16mb (MB/s)","584.99"
    "bw_mem-cp-1mb (MB/s)","2584.51 (min 672.95, max 4496.07)"
    "bw_mem-cp-2mb (MB/s)","1457.14 (min 570.78, max 2343.49)"
    "bw_mem-cp-4mb (MB/s)","1146.70 (min 587.63, max 1705.76)"
    "bw_mem-cp-8mb (MB/s)","1126.56 (min 599.03, max 1654.09)"
    "bw_mem-fcp-16mb (MB/s)","822.58"
    "bw_mem-fcp-1mb (MB/s)","2730.36 (min 986.84, max 4473.87)"
    "bw_mem-fcp-2mb (MB/s)","1576.71 (min 828.61, max 2324.81)"
    "bw_mem-fcp-4mb (MB/s)","1257.56 (min 811.77, max 1703.34)"
    "bw_mem-fcp-8mb (MB/s)","1236.99 (min 824.66, max 1649.31)"
    "bw_mem-frd-16mb (MB/s)","1278.47"
    "bw_mem-frd-1mb (MB/s)","1273.30 (min 986.84, max 1559.76)"
    "bw_mem-frd-2mb (MB/s)","1112.14 (min 828.61, max 1395.67)"
    "bw_mem-frd-4mb (MB/s)","1042.32 (min 811.77, max 1272.87)"
    "bw_mem-frd-8mb (MB/s)","1042.15 (min 824.66, max 1259.64)"
    "bw_mem-fwr-16mb (MB/s)","1655.63"
    "bw_mem-fwr-1mb (MB/s)","3027.92 (min 1559.76, max 4496.07)"
    "bw_mem-fwr-2mb (MB/s)","1869.58 (min 1395.67, max 2343.49)"
    "bw_mem-fwr-4mb (MB/s)","1489.32 (min 1272.87, max 1705.76)"
    "bw_mem-fwr-8mb (MB/s)","1456.87 (min 1259.64, max 1654.09)"
    "bw_mem-rd-16mb (MB/s)","1301.24"
    "bw_mem-rd-1mb (MB/s)","3298.78 (min 3141.75, max 3455.80)"
    "bw_mem-rd-2mb (MB/s)","1164.23 (min 912.27, max 1416.18)"
    "bw_mem-rd-4mb (MB/s)","1033.02 (min 750.89, max 1315.14)"
    "bw_mem-rd-8mb (MB/s)","1022.41 (min 742.74, max 1302.08)"
    "bw_mem-rdwr-16mb (MB/s)","731.19"
    "bw_mem-rdwr-1mb (MB/s)","1768.05 (min 672.95, max 2863.14)"
    "bw_mem-rdwr-2mb (MB/s)","720.81 (min 570.78, max 870.83)"
    "bw_mem-rdwr-4mb (MB/s)","663.98 (min 587.63, max 740.33)"
    "bw_mem-rdwr-8mb (MB/s)","666.96 (min 599.03, max 734.89)"
    "bw_mem-wr-16mb (MB/s)","742.22"
    "bw_mem-wr-1mb (MB/s)","3002.45 (min 2863.14, max 3141.75)"
    "bw_mem-wr-2mb (MB/s)","891.55 (min 870.83, max 912.27)"
    "bw_mem-wr-4mb (MB/s)","745.61 (min 740.33, max 750.89)"
    "bw_mem-wr-8mb (MB/s)","738.82 (min 734.89, max 742.74)"
    "bw_mmap_rd-mo-1mb (MB/s)","2857.65"
    "bw_mmap_rd-o2c-1mb (MB/s)","567.86"
    "bw_pipe (MB/s)","298.19"
    "bw_unix (MB/s)","1105.78"
    "lat_connect (us)","105.25"
    "lat_ctx-2-128k (us)","8.20"
    "lat_ctx-2-256k (us)","6.49"
    "lat_ctx-4-128k (us)","8.36"
    "lat_ctx-4-256k (us)","3.72"
    "lat_fs-0k (num_files)","129.00"
    "lat_fs-10k (num_files)","73.00"
    "lat_fs-1k (num_files)","89.00"
    "lat_fs-4k (num_files)","101.00"
    "lat_mem_rd-stride128-sz1000k (ns)","26.78"
    "lat_mem_rd-stride128-sz125k (ns)","9.72"
    "lat_mem_rd-stride128-sz250k (ns)","10.23"
    "lat_mem_rd-stride128-sz31k (ns)","3.80"
    "lat_mem_rd-stride128-sz50 (ns)","3.76"
    "lat_mem_rd-stride128-sz500k (ns)","11.52"
    "lat_mem_rd-stride128-sz62k (ns)","7.95"
    "lat_mmap-1m (us)","78.00"
    "lat_ops-double-add (ns)","0.91"
    "lat_ops-double-mul (ns)","5.03"
    "lat_ops-float-add (ns)","0.92"
    "lat_ops-float-mul (ns)","5.03"
    "lat_ops-int-add (ns)","1.26"
    "lat_ops-int-bit (ns)","0.83"
    "lat_ops-int-div (ns)","7.53"
    "lat_ops-int-mod (ns)","7.96"
    "lat_ops-int-mul (ns)","3.81"
    "lat_ops-int64-add (ns)","1.26"
    "lat_ops-int64-bit (ns)","0.84"
    "lat_ops-int64-div (ns)","11.98"
    "lat_ops-int64-mod (ns)","9.21"
    "lat_pagefault (us)","1.91"
    "lat_pipe (us)","33.59"
    "lat_proc-exec (us)","1733.25"
    "lat_proc-fork (us)","1484.25"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","52.71"
    "lat_sem (us)","8.20"
    "lat_sig-catch (us)","9.89"
    "lat_sig-install (us)","1.02"
    "lat_sig-prot (us)","0.41"
    "lat_syscall-fstat (us)","2.47"
    "lat_syscall-null (us)","0.53"
    "lat_syscall-open (us)","218.84"
    "lat_syscall-read (us)","0.96"
    "lat_syscall-stat (us)","6.53"
    "lat_syscall-write (us)","0.81"
    "lat_tcp (us)","1.00"
    "lat_unix (us)","62.08"
    "latency_for_0.50_mb_block_size (nanosec)","11.52"
    "latency_for_1.00_mb_block_size (nanosec)","13.39 (min 0.00, max 26.78)"
    "pipe_bandwidth (MBs)","298.19"
    "pipe_latency (microsec)","33.59"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","52.71"
    "semaphore_latency (microsec)","8.20"
    "signal_handler_latency (microsec)","1.02"
    "signal_handler_overhead (microsec)","9.89"
    "tcp_ip_connection_cost_to_localhost (microsec)","105.25"
    "tcp_latency_using_localhost (microsec)","1.00"


Table:  **LM Bench Metrics**



Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "cpu_clock (MHz)","800.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.96"
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
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "linpack (Kflops)","331179.00"


Table:  **Linpack Benchmark**



NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks 
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html


.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "assignment (Iterations)","7.80"
    "fourier (Iterations)","13066.00"
    "fp_emulation (Iterations)","61.24"
    "huffman (Iterations)","670.69"
    "idea (Iterations)","1962.80"
    "lu_decomposition (Iterations)","313.08"
    "neural_net (Iterations)","4.48"
    "numeric_sort (Iterations)","288.25"
    "string_sort (Iterations)","94.74"


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

.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "add (MB/s)","1602.90"
    "copy (MB/s)","1747.10"
    "scale (MB/s)","1756.80"
    "triad (MB/s)","1507.20"


Table:  **Stream**


 



 
 

 


Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am654x-evm: boot time (sec)"

    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","5.85 (min 5.78, max 6.13)"

Table:  **Boot time MMC/SD**


 
 


ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64


.. csv-table::
    :header: "Sampling Rate (Hz)","am654x-evm: Throughput (bits/sec)","am654x-evm: CPU Load (%)"

    "8000","255999.00","0.53"
    "11025","352798.00","0.44"
    "16000","511997.00","0.32"
    "22050","705596.00","0.66"
    "24000","705596.00","0.62"
    "32000","1023993.00","0.43"
    "44100","1411190.00","1.12"
    "48000","1535989.00","0.55"
    "88200","2822375.00","1.90"
    "96000","3071973.00","5.93"

Table:  **Audio Capture**

|


 
 


Sensor Capture
-------------------------

Capture video frames (MMAP buffers) with v4l2c-ctl and record the
reported fps

.. csv-table::
    :header: "Resolution","Format","am654x-evm: Fps","am654x-evm: Sensor"

    "176x144","uyvy","30.02","ov5640"
    "1920x1080","uyvy","30.00","ov5640"

Table:  **Sensor Capture**

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


 

 

 

 



 


AM654x-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write EXT4 Throughput (Mbytes/sec)","am654x-evm: Write EXT4 CPU Load (%)","am654x-evm: Read EXT4 Throughput (Mbytes/sec)","am654x-evm: Read EXT4 CPU Load (%)"

    "1m","30.90","1.06","85.80","1.56"
    "4m","29.40","0.91","85.50","1.28"
    "4k","3.22","3.51","12.50","9.60"
    "256k","27.90","1.27","84.00","2.02"

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

  


CRYPTO Driver
-------------------------

 




IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am654x-evm: Throughput (Mbps)","am654x-evm: Packets/Sec","am654x-evm: CPU Load"

    "aes256","6.80","0.00","32.53"

 
 

 

DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.

    
