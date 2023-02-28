..  http://processors.wiki.ti.com/index.php/CoreSDK_Linux_RT_Kernel_Performance_Guide


======================================
 RT-linux 08.06.00 Performance Guide
======================================

.. rubric::  **Read This First**
   :name: read-this-first-rt-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+---------------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                         |
+================+=====================================================================================================================+
| AM64x EVM      | AM64x SR2.0 Evaluation Module rev C  with ARM running at 1GHz, DDR data rate 1600 MT/S                              |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| AM65x EVM      | AM65x SR2.0 Evaluation Module rev E4 with ARM running at 800MHz, DDR4-2400 (1600 MT/S)	                       |
+----------------+---------------------------------------------------------------------------------------------------------------------+
| AM62A SK       | AM62A Starter Kit rev E2 with ARM running at 1200MHz, LPDDR4 data rate 1866 MT/S				       |
+----------------+---------------------------------------------------------------------------------------------------------------------+


Table:  Evaluation Modules

|

.. rubric::  About This Manual
   :name: about-this-manual-rt-kernel-perf-guide

This document provides performance data for each of the device drivers
which are part of the Processor SDK Linux package. This document should be
used in conjunction with release notes and user guides provided with the
Processor SDK Linux package for information on specific issues present
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

**Bandwidth**: bw_mem_bcopy-N, where N is equal to or smaller than the cache size at
a given level measures the achievable memory bandwidth from software doing
a memcpy() type operation. Typical use is for external memory bandwidth
calculation. The bandwidth is calculated as byte read and written counts
as 1 which should be roughly half of STREAM copy result.

.. csv-table::
    :header: "Benchmarks","am62axx_sk-fs: perf","am654x-evm: perf"

    "af_unix_sock_stream_latency (microsec)","39.51","60.48"
    "af_unix_socket_stream_bandwidth (MBs)","1610.93","1107.59"
    "bw_file_rd-io-1mb (MB/s)","1168.81","975.61"
    "bw_file_rd-o2c-1mb (MB/s)","140.49","502.34"
    "bw_mem-bcopy-16mb (MB/s)","1830.66","878.40"
    "bw_mem-bcopy-1mb (MB/s)","2046.89","1051.89"
    "bw_mem-bcopy-2mb (MB/s)","1848.43","880.67"
    "bw_mem-bcopy-4mb (MB/s)","1814.06","874.41"
    "bw_mem-bcopy-8mb (MB/s)","1830.04","865.99"
    "bw_mem-bzero-16mb (MB/s)","7392.58","1648.80"
    "bw_mem-bzero-1mb (MB/s)","4721.81 (min 2046.89, max 7396.72)","2734.88 (min 1051.89, max 4417.86)"
    "bw_mem-bzero-2mb (MB/s)","4619.45 (min 1848.43, max 7390.46)","1605.06 (min 880.67, max 2329.45)"
    "bw_mem-bzero-4mb (MB/s)","4595.21 (min 1814.06, max 7376.36)","1286.46 (min 874.41, max 1698.51)"
    "bw_mem-bzero-8mb (MB/s)","4609.60 (min 1830.04, max 7389.16)","1254.52 (min 865.99, max 1643.05)"
    "bw_mem-cp-16mb (MB/s)","938.47","590.17"
    "bw_mem-cp-1mb (MB/s)","4281.81 (min 931.45, max 7632.17)","2522.16 (min 675.11, max 4369.20)"
    "bw_mem-cp-2mb (MB/s)","4214.92 (min 933.85, max 7495.98)","1460.09 (min 591.89, max 2328.29)"
    "bw_mem-cp-4mb (MB/s)","4184.49 (min 913.24, max 7455.73)","1143.89 (min 586.85, max 1700.92)"
    "bw_mem-cp-8mb (MB/s)","4207.62 (min 989.49, max 7425.74)","1117.19 (min 578.91, max 1655.46)"
    "bw_mem-fcp-16mb (MB/s)","1581.81","822.24"
    "bw_mem-fcp-1mb (MB/s)","4664.92 (min 1933.11, max 7396.72)","2690.44 (min 963.02, max 4417.86)"
    "bw_mem-fcp-2mb (MB/s)","4555.23 (min 1719.99, max 7390.46)","1578.75 (min 828.04, max 2329.45)"
    "bw_mem-fcp-4mb (MB/s)","4561.67 (min 1746.98, max 7376.36)","1258.84 (min 819.17, max 1698.51)"
    "bw_mem-fcp-8mb (MB/s)","4565.95 (min 1742.73, max 7389.16)","1232.33 (min 821.61, max 1643.05)"
    "bw_mem-frd-16mb (MB/s)","1865.67","1275.51"
    "bw_mem-frd-1mb (MB/s)","1900.99 (min 1868.87, max 1933.11)","1271.68 (min 963.02, max 1580.33)"
    "bw_mem-frd-2mb (MB/s)","1755.25 (min 1719.99, max 1790.51)","1120.11 (min 828.04, max 1412.18)"
    "bw_mem-frd-4mb (MB/s)","1738.17 (min 1729.36, max 1746.98)","1054.96 (min 819.17, max 1290.74)"
    "bw_mem-frd-8mb (MB/s)","1705.40 (min 1668.06, max 1742.73)","1049.58 (min 821.61, max 1277.55)"
    "bw_mem-fwr-16mb (MB/s)","7413.13","1646.60"
    "bw_mem-fwr-1mb (MB/s)","4750.52 (min 1868.87, max 7632.17)","2974.77 (min 1580.33, max 4369.20)"
    "bw_mem-fwr-2mb (MB/s)","4643.25 (min 1790.51, max 7495.98)","1870.24 (min 1412.18, max 2328.29)"
    "bw_mem-fwr-4mb (MB/s)","4592.55 (min 1729.36, max 7455.73)","1495.83 (min 1290.74, max 1700.92)"
    "bw_mem-fwr-8mb (MB/s)","4546.90 (min 1668.06, max 7425.74)","1466.51 (min 1277.55, max 1655.46)"
    "bw_mem-rd-16mb (MB/s)","1932.60","1297.54"
    "bw_mem-rd-1mb (MB/s)","2088.41 (min 1971.33, max 2205.48)","3319.10 (min 3250.27, max 3387.92)"
    "bw_mem-rd-2mb (MB/s)","1838.65 (min 1719.39, max 1957.91)","1174.07 (min 910.33, max 1437.81)"
    "bw_mem-rd-4mb (MB/s)","1844.61 (min 1739.89, max 1949.32)","1032.56 (min 753.86, max 1311.26)"
    "bw_mem-rd-8mb (MB/s)","1848.61 (min 1761.34, max 1935.87)","1021.93 (min 741.77, max 1302.08)"
    "bw_mem-rdwr-16mb (MB/s)","1796.54","730.43"
    "bw_mem-rdwr-1mb (MB/s)","1393.51 (min 931.45, max 1855.57)","1861.95 (min 675.11, max 3048.78)"
    "bw_mem-rdwr-2mb (MB/s)","1272.73 (min 933.85, max 1611.60)","740.19 (min 591.89, max 888.49)"
    "bw_mem-rdwr-4mb (MB/s)","1301.10 (min 913.24, max 1688.95)","661.28 (min 586.85, max 735.70)"
    "bw_mem-rdwr-8mb (MB/s)","1358.31 (min 989.49, max 1727.12)","653.29 (min 578.91, max 727.67)"
    "bw_mem-wr-16mb (MB/s)","1786.11","742.94"
    "bw_mem-wr-1mb (MB/s)","1913.45 (min 1855.57, max 1971.33)","3149.53 (min 3048.78, max 3250.27)"
    "bw_mem-wr-2mb (MB/s)","1665.50 (min 1611.60, max 1719.39)","899.41 (min 888.49, max 910.33)"
    "bw_mem-wr-4mb (MB/s)","1714.42 (min 1688.95, max 1739.89)","744.78 (min 735.70, max 753.86)"
    "bw_mem-wr-8mb (MB/s)","1744.23 (min 1727.12, max 1761.34)","734.72 (min 727.67, max 741.77)"
    "bw_mmap_rd-mo-1mb (MB/s)","2204.26","2662.30"
    "bw_mmap_rd-o2c-1mb (MB/s)","603.68","529.94"
    "bw_pipe (MB/s)","479.04","318.65"
    "bw_unix (MB/s)","1610.93","1107.59"
    "lat_connect (us)","95.80","143.08"
    "lat_ctx-2-128k (us)","5.17","8.38"
    "lat_ctx-2-256k (us)","4.64","6.13"
    "lat_ctx-4-128k (us)","4.43","7.94"
    "lat_ctx-4-256k (us)","0.09","3.82"
    "lat_fs-0k (num_files)","249.00","136.00"
    "lat_fs-10k (num_files)","117.00","61.00"
    "lat_fs-1k (num_files)","145.00","109.00"
    "lat_fs-4k (num_files)","158.00","107.00"
    "lat_mem_rd-stride128-sz1000k (ns)","30.68","24.99"
    "lat_mem_rd-stride128-sz125k (ns)","6.25","9.88"
    "lat_mem_rd-stride128-sz250k (ns)","6.53","10.21"
    "lat_mem_rd-stride128-sz31k (ns)","2.43","6.39"
    "lat_mem_rd-stride128-sz50 (ns)","2.40","3.76"
    "lat_mem_rd-stride128-sz500k (ns)","12.16","11.82"
    "lat_mem_rd-stride128-sz62k (ns)","5.89","9.16"
    "lat_mmap-1m (us)","61.00","81.00"
    "lat_ops-double-add (ns)","0.58","0.91"
    "lat_ops-double-mul (ns)","3.21","5.04"
    "lat_ops-float-add (ns)","0.58","0.91"
    "lat_ops-float-mul (ns)","3.21","5.03"
    "lat_ops-int-add (ns)","0.80","1.26"
    "lat_ops-int-bit (ns)","0.53","0.84"
    "lat_ops-int-div (ns)","4.84","7.52"
    "lat_ops-int-mod (ns)","5.08","7.98"
    "lat_ops-int-mul (ns)","2.43","3.81"
    "lat_ops-int64-add (ns)","0.80","1.27"
    "lat_ops-int64-bit (ns)","0.53","0.84"
    "lat_ops-int64-div (ns)","7.65","11.96"
    "lat_ops-int64-mod (ns)","5.88","9.23"
    "lat_pagefault (us)","1.32","1.93"
    "lat_pipe (us)","21.62","33.24"
    "lat_proc-exec (us)","1140.40","1703.25"
    "lat_proc-fork (us)","941.83","1468.25"
    "lat_proc-proccall (us)","0.01","0.01"
    "lat_select (us)","35.52","55.76"
    "lat_sem (us)","2.89","8.18"
    "lat_sig-catch (us)","6.48","9.92"
    "lat_sig-install (us)","0.77","1.02"
    "lat_sig-prot (us)","0.55","0.69"
    "lat_syscall-fstat (us)","1.72","2.44"
    "lat_syscall-null (us)","0.43","0.50"
    "lat_syscall-open (us)","6170.00","317.94"
    "lat_syscall-read (us)","0.74","0.98"
    "lat_syscall-stat (us)","4.59","6.83"
    "lat_syscall-write (us)","0.65","0.85"
    "lat_tcp (us)","0.92","1.05"
    "lat_unix (us)","39.51","60.48"
    "latency_for_0.50_mb_block_size (nanosec)","12.16","11.82"
    "latency_for_1.00_mb_block_size (nanosec)","15.34 (min 0.00, max 30.68)","12.49 (min 0.00, max 24.99)"
    "pipe_bandwidth (MBs)","479.04","318.65"
    "pipe_latency (microsec)","21.62","33.24"
    "procedure_call (microsec)","0.01","0.01"
    "select_on_200_tcp_fds (microsec)","35.52","55.76"
    "semaphore_latency (microsec)","2.89","8.18"
    "signal_handler_latency (microsec)","0.77","1.02"
    "signal_handler_overhead (microsec)","6.48","9.92"
    "tcp_ip_connection_cost_to_localhost (microsec)","95.80","143.08"
    "tcp_latency_using_localhost (microsec)","0.92","1.05"


Table:  **LM Bench Metrics**



Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

.. csv-table::
    :header: "Benchmarks","am62axx_sk-fs: perf","am64xx-hsevm: perf"

    "cpu_clock (MHz)","1250.00","1000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.90","2.90"
    "dhrystone_per_second (DhrystoneP)","6451613.00","5128205.00"


Table:  **Dhrystone Benchmark**



Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am62axx_sk-fs: perf","am64xx-hsevm: perf","am654x-evm: perf"

    "whetstone (MIPS)","5000.00","5000.00","3333.30"


Table:  **Whetstone Benchmark**



Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am62axx_sk-fs: perf","am654x-evm: perf"

    "linpack (Kflops)","518826.00","326564.00"


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

    "assignment (Iterations)","7.82"
    "fourier (Iterations)","12991.00"
    "fp_emulation (Iterations)","61.24"
    "huffman (Iterations)","670.09"
    "idea (Iterations)","1962.70"
    "lu_decomposition (Iterations)","313.09"
    "neural_net (Iterations)","4.48"
    "numeric_sort (Iterations)","283.49"
    "string_sort (Iterations)","94.73"


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
    :header: "Benchmarks","am62axx_sk-fs: perf","am654x-evm: perf"

    "add (MB/s)","2506.20","1625.80"
    "copy (MB/s)","3755.90","1783.80"
    "scale (MB/s)","3313.10","1782.20"
    "triad (MB/s)","2283.10","1521.80"


Table:  **Stream**



CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.


.. csv-table::
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "cjpeg-rose7-preset (workloads/)","37.45"
    "core (workloads/)","0.27"
    "coremark-pro ()","851.58"
    "linear_alg-mid-100x100-sp (workloads/)","13.11"
    "loops-all-mid-10k-sp (workloads/)","0.64"
    "nnet_test (workloads/)","0.98"
    "parser-125k (workloads/)","7.94"
    "radix2-big-64k (workloads/)","69.21"
    "sha-test (workloads/)","72.99"
    "zip-test (workloads/)","20.00"


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
    :header: "Benchmarks","am62axx_sk-fs: perf","am654x-evm: perf"

    "4m-check (workloads/)","474.65","356.68"
    "4m-check-reassembly (workloads/)","113.38","69.20"
    "4m-check-reassembly-tcp (workloads/)","56.05","35.77"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","31.93","9.53"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.73","1.13"
    "4m-cmykw2 (workloads/)","216.22","138.03"
    "4m-cmykw2-rotatew2 (workloads/)","43.73","9.69"
    "4m-reassembly (workloads/)","71.94","48.08"
    "4m-rotatew2 (workloads/)","48.78","13.07"
    "4m-tcp-mixed (workloads/)","112.68","70.48"
    "4m-x264w2 (workloads/)","1.73","1.16"
    "empty-wld (workloads/)","","1.00"
    "idct-4m (workloads/)","17.21","10.97"
    "idct-4mw1 (workloads/)","17.21","10.99"
    "ippktcheck-4m (workloads/)","472.50","356.63"
    "ippktcheck-4mw1 (workloads/)","473.22","355.82"
    "ipres-4m (workloads/)","102.81","62.89"
    "ipres-4mw1 (workloads/)","102.46","62.47"
    "md5-4m (workloads/)","26.12","15.04"
    "md5-4mw1 (workloads/)","26.10","15.07"
    "rgbcmyk-4m (workloads/)","58.81","36.54"
    "rgbcmyk-4mw1 (workloads/)","58.70","36.42"
    "rotate-4ms1 (workloads/)","22.15","14.51"
    "rotate-4ms1w1 (workloads/)","21.96","14.32"
    "rotate-4ms64 (workloads/)","22.35","14.52"
    "rotate-4ms64w1 (workloads/)","22.17","14.53"
    "x264-4mq (workloads/)","0.52","0.33"
    "x264-4mqw1 (workloads/)","0.52","0.33"


Table:  **Multibench**


 
 

 


Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am654x-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","31.58 (min 31.14, max 32.10)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","5.88"

Table:  **Boot time MMC/SD**


 
 


ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64


.. csv-table::
    :header: "Sampling Rate (Hz)","am654x-evm: Throughput (bits/sec)","am654x-evm: CPU Load (%)"

    "8000","255999.00","0.45"
    "11025","352798.00","0.61"
    "16000","511997.00","0.49"
    "22050","705596.00","0.86"
    "24000","705596.00","0.80"
    "32000","1023993.00","0.62"
    "44100","1411190.00","1.18"
    "48000","1535989.00","0.73"
    "88200","2822376.00","1.91"
    "96000","3071973.00","6.12"

Table:  **Audio Capture**

|


 
 



 


Graphics SGX/RGX Driver
-------------------------
 




Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am654x-evm: Score"

    "Glmark2-Wayland","192.00"


Table:  **Glmark2**
 
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


CPSW/CPSW2g/CPSW3g Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- CPSW2g: AM65x
- CPSW3g: AM64x


.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","am62axx_sk-fs: THROUGHPUT (Mbits/sec)","am62axx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1685.70","42.42"

Table: **CPSW TCP Bidirectional Throughput**

|



.. rubric::  UDP Throughput 
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am62axx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62axx_sk-fs: THROUGHPUT (Mbits/sec)","am62axx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","10.36","48.30"
    "128","82.00","46.42","47.88"
    "256","210.00","119.83","47.89"
    "1024","978.00","92.32","10.41"
    "1518","1472.00","170.75","10.59"

Table: **CPSW UDP Egress Throughput**

|



.. csv-table::
    :header: "Frame Size(bytes)","am62axx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62axx_sk-fs: THROUGHPUT (Mbits/sec)","am62axx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.27","8.38"
    "128","82.00","7.02","2.95"
    "256","210.00","17.64","4.02"
    "1024","978.00","91.54","9.09"
    "1518","1472.00","143.66","9.43"

Table: **CPSW UDP Ingress Throughput (0% loss)**

|



.. csv-table::
    :header: "Frame Size(bytes)","am62axx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62axx_sk-fs: THROUGHPUT (Mbits/sec)","am62axx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62axx_sk-fs: Packet Loss %"

    "64","18.00","20.15","40.52","70.89"
    "128","82.00","89.91","40.96","65.88"
    "256","210.00","226.14","42.17","64.29"
    "1024","978.00","936.01","42.44","0.08"
    "1518","1472.00","956.84","39.99","0.02"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|
 
 


ICSSG Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput 
   :name: tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_MAERTS","182.62","53.26"

Table: **ICSSG TCP Bidirectional Throughput**

|



.. rubric::  UDP Throughput 
   :name: udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-hsevm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","6.97","81.75"
    "128","82.00","31.48","81.28"
    "256","210.00","75.23","83.30"
    "1024","978.00","93.64","28.51"
    "1518","1472.00","12.95","1.14"

Table: **ICSSG UDP Egress Throughput**

|



.. csv-table::
    :header: "Frame Size(bytes)","am64xx-hsevm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: CPU Load %"

    "64","18.00","1.99","20.76"
    "128","82.00","8.13","14.28"
    "256","210.00","14.11","16.85"
    "1024","978.00","94.67","32.84"
    "1518","1472.00","121.29","27.85"

Table: **ICSSG UDP Ingress Throughput (0% loss)**

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

    "1m","28.60","1.37","85.40","1.84"
    "4m","28.60","1.18","85.40","1.66"
    "4k","3.22","3.81","12.40","9.55"
    "256k","24.90","1.57","83.70","2.51"

|

 

 

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|
 

  


CRYPTO Driver
-------------------------


OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am62axx_sk-fs: throughput (KBytes/Sec)","am64xx-hsevm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","21167.79","20062.21"
    "aes-128-cbc","16","411.44","332.70"
    "aes-128-cbc","16384","83367.25","132732.25"
    "aes-128-cbc","256","6201.94","5345.11"
    "aes-128-cbc","64","1621.76","1332.37"
    "aes-128-cbc","8192","69033.98","95373.99"
    "aes-192-cbc","1024","20931.58","19713.71"
    "aes-192-cbc","16","414.10","335.01"
    "aes-192-cbc","16384","75688.62","124764.16"
    "aes-192-cbc","256","6210.73","5042.69"
    "aes-192-cbc","64","1634.03","1343.32"
    "aes-192-cbc","8192","63892.14","91837.78"
    "aes-256-cbc","1024","20416.51","19805.87"
    "aes-256-cbc","16","412.90","336.49"
    "aes-256-cbc","16384","69277.01","119029.76"
    "aes-256-cbc","256","6145.88","5365.16"
    "aes-256-cbc","64","1610.69","1341.50"
    "aes-256-cbc","8192","59189.93","88342.53"
    "des-cbc","1024","23051.95","18436.44"
    "des-cbc","16","4122.59","3300.41"
    "des-cbc","16384","24663.38","19682.65"
    "des-cbc","256","18923.78","15145.05"
    "des-cbc","64","11011.56","8823.30"
    "des-cbc","8192","24545.96","19567.96"
    "des3","1024","9750.87","7789.57"
    "des3","16","3229.89","2598.29"
    "des3","16384","10032.47","8006.31"
    "des3","256","8893.61","7109.97"
    "des3","64","6573.42","5242.26"
    "des3","8192","10005.16","7951.70"
    "md5","1024","41871.02","33933.99"
    "md5","16","886.54","722.06"
    "md5","16384","133802.67","106255.70"
    "md5","256","12976.64","10574.51"
    "md5","64","3446.57","2822.44"
    "md5","8192","116471.13","93164.89"
    "sha1","1024","49449.30","40485.89"
    "sha1","16","846.15","699.75"
    "sha1","16384","304911.70","243750.23"
    "sha1","256","13363.88","10880.85"
    "sha1","64","3425.77","2779.93"
    "sha1","8192","225503.91","181403.65"
    "sha224","1024","49502.89","39455.74"
    "sha224","16","848.51","680.43"
    "sha224","16384","311083.01","248479.74"
    "sha224","256","13263.36","10603.09"
    "sha224","64","3375.25","2708.10"
    "sha224","8192","228018.86","182255.62"
    "sha256","1024","29983.40","24089.94"
    "sha256","16","496.45","400.79"
    "sha256","16384","248146.60","199360.51"
    "sha256","256","7828.39","6325.08"
    "sha256","64","1979.52","1599.49"
    "sha256","8192","166207.49","133584.21"
    "sha384","1024","30427.82","24240.81"
    "sha384","16","831.21","655.17"
    "sha384","16384","65465.00","52101.12"
    "sha384","256","11166.89","8866.56"
    "sha384","64","3314.47","2637.61"
    "sha384","8192","60708.18","48201.73"
    "sha512","1024","21775.70","17496.06"
    "sha512","16","489.23","395.08"
    "sha512","16384","62133.59","49479.68"
    "sha512","256","7042.13","5674.07"
    "sha512","64","1959.25","1576.41"
    "sha512","8192","55184.04","43895.47"


|
|



.. csv-table::
    :header: "Algorithm","am62axx_sk-fs: CPU Load","am64xx-hsevm: CPU Load"

    "aes-128-cbc","37.00","44.00"
    "aes-192-cbc","36.00","43.00"
    "aes-256-cbc","35.00","43.00"
    "des-cbc","97.00","97.00"
    "des3","97.00","97.00"
    "md5","98.00","97.00"
    "sha1","98.00","97.00"
    "sha224","98.00","97.00"
    "sha256","98.00","97.00"
    "sha384","88.00","97.00"
    "sha512","98.00","97.00"

 

|
| Listed for each algorithm are the code snippets used to run each
  benchmark test.

|

::
    time -v openssl speed -elapsed -evp aes-128-cbc

 




IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am62axx_sk-fs: Throughput (Mbps)","am62axx_sk-fs: Packets/Sec","am62axx_sk-fs: CPU Load","am64xx-hsevm: Throughput (Mbps)","am64xx-hsevm: Packets/Sec","am64xx-hsevm: CPU Load","am654x-evm: Throughput (Mbps)","am654x-evm: Packets/Sec","am654x-evm: CPU Load"

    "3des","63.80","5.00","24.89","52.40","4.00","59.49"
    "aes128","60.90","5.00","18.42"
    "aes192","56.00","5.00","17.21"
    "aes256","0.00","0.00","8.57","91.30","8.00","36.35"

 

