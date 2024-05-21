
======================================
 Linux 09.02.00 Performance Guide
======================================

.. rubric::  **Read This First**
   :name: read-this-first-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| AM62Px SK      | AM62Px Starter Kit rev E1 with ARM running at 1.4GHz, DDR data rate 3200 MT/S                                  |
+----------------+----------------------------------------------------------------------------------------------------------------+

Table:  Evaluation Modules

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

.. csv-table:: LMBench Benchmarks
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "af_unix_sock_stream_latency (microsec)","22.33"
    "af_unix_socket_stream_bandwidth (MBs)","1206.42"
    "bw_file_rd-io-1mb (MB/s)","1353.64"
    "bw_file_rd-o2c-1mb (MB/s)","797.45"
    "bw_mem-bcopy-16mb (MB/s)","1988.07"
    "bw_mem-bcopy-1mb (MB/s)","2154.75"
    "bw_mem-bcopy-2mb (MB/s)","1784.12"
    "bw_mem-bcopy-4mb (MB/s)","1942.38"
    "bw_mem-bcopy-8mb (MB/s)","1937.98"
    "bw_mem-bzero-16mb (MB/s)","8116.33"
    "bw_mem-bzero-1mb (MB/s)","5130.70 (min 2154.75, max 8106.65)"
    "bw_mem-bzero-2mb (MB/s)","4951.36 (min 1784.12, max 8118.60)"
    "bw_mem-bzero-4mb (MB/s)","5027.99 (min 1942.38, max 8113.59)"
    "bw_mem-bzero-8mb (MB/s)","5026.47 (min 1937.98, max 8114.96)"
    "bw_mem-cp-16mb (MB/s)","984.25"
    "bw_mem-cp-1mb (MB/s)","1319.68 (min 972.13, max 1667.22)"
    "bw_mem-cp-2mb (MB/s)","1206.93 (min 955.87, max 1457.99)"
    "bw_mem-cp-4mb (MB/s)","1226.82 (min 939.63, max 1514.00)"
    "bw_mem-cp-8mb (MB/s)","1297.00 (min 971.94, max 1622.06)"
    "bw_mem-fcp-16mb (MB/s)","1747.87"
    "bw_mem-fcp-1mb (MB/s)","4946.03 (min 1785.40, max 8106.65)"
    "bw_mem-fcp-2mb (MB/s)","4906.90 (min 1695.20, max 8118.60)"
    "bw_mem-fcp-4mb (MB/s)","4958.38 (min 1803.16, max 8113.59)"
    "bw_mem-fcp-8mb (MB/s)","4971.35 (min 1827.74, max 8114.96)"
    "bw_mem-frd-16mb (MB/s)","2005.01"
    "bw_mem-frd-1mb (MB/s)","1944.73 (min 1785.40, max 2104.06)"
    "bw_mem-frd-2mb (MB/s)","1778.99 (min 1695.20, max 1862.78)"
    "bw_mem-frd-4mb (MB/s)","1896.77 (min 1803.16, max 1990.38)"
    "bw_mem-frd-8mb (MB/s)","1910.88 (min 1827.74, max 1994.02)"
    "bw_mem-fwr-16mb (MB/s)","1702.67"
    "bw_mem-fwr-1mb (MB/s)","1885.64 (min 1667.22, max 2104.06)"
    "bw_mem-fwr-2mb (MB/s)","1660.39 (min 1457.99, max 1862.78)"
    "bw_mem-fwr-4mb (MB/s)","1752.19 (min 1514.00, max 1990.38)"
    "bw_mem-fwr-8mb (MB/s)","1808.04 (min 1622.06, max 1994.02)"
    "bw_mem-rd-16mb (MB/s)","2076.03"
    "bw_mem-rd-1mb (MB/s)","2169.31 (min 2035.28, max 2303.33)"
    "bw_mem-rd-2mb (MB/s)","1938.33 (min 1837.22, max 2039.43)"
    "bw_mem-rd-4mb (MB/s)","1965.72 (min 1893.04, max 2038.39)"
    "bw_mem-rd-8mb (MB/s)","2009.38 (min 1950.51, max 2068.25)"
    "bw_mem-rdwr-16mb (MB/s)","1977.26"
    "bw_mem-rdwr-1mb (MB/s)","1441.18 (min 972.13, max 1910.22)"
    "bw_mem-rdwr-2mb (MB/s)","1332.20 (min 955.87, max 1708.53)"
    "bw_mem-rdwr-4mb (MB/s)","1427.82 (min 939.63, max 1916.01)"
    "bw_mem-rdwr-8mb (MB/s)","1476.07 (min 971.94, max 1980.20)"
    "bw_mem-wr-16mb (MB/s)","1956.47"
    "bw_mem-wr-1mb (MB/s)","1972.75 (min 1910.22, max 2035.28)"
    "bw_mem-wr-2mb (MB/s)","1772.88 (min 1708.53, max 1837.22)"
    "bw_mem-wr-4mb (MB/s)","1904.53 (min 1893.04, max 1916.01)"
    "bw_mem-wr-8mb (MB/s)","1965.36 (min 1950.51, max 1980.20)"
    "bw_mmap_rd-mo-1mb (MB/s)","2252.25"
    "bw_mmap_rd-o2c-1mb (MB/s)","682.36"
    "bw_pipe (MB/s)","725.97"
    "bw_unix (MB/s)","1206.42"
    "lat_connect (us)","51.62"
    "lat_ctx-2-128k (us)","4.95"
    "lat_ctx-2-256k (us)","4.10"
    "lat_ctx-4-128k (us)","4.23"
    "lat_ctx-4-256k (us)","2.60"
    "lat_fs-0k (num_files)","291.00"
    "lat_fs-10k (num_files)","124.00"
    "lat_fs-1k (num_files)","185.00"
    "lat_fs-4k (num_files)","181.00"
    "lat_mem_rd-stride128-sz1000k (ns)","29.50"
    "lat_mem_rd-stride128-sz125k (ns)","5.53"
    "lat_mem_rd-stride128-sz250k (ns)","5.83"
    "lat_mem_rd-stride128-sz31k (ns)","4.66"
    "lat_mem_rd-stride128-sz50 (ns)","2.15"
    "lat_mem_rd-stride128-sz500k (ns)","7.69"
    "lat_mem_rd-stride128-sz62k (ns)","5.25"
    "lat_mmap-1m (us)","49.00"
    "lat_ops-double-add (ns)","2.86"
    "lat_ops-double-div (ns)","15.73"
    "lat_ops-double-mul (ns)","2.86"
    "lat_ops-float-add (ns)","2.87"
    "lat_ops-float-div (ns)","9.30"
    "lat_ops-float-mul (ns)","2.86"
    "lat_ops-int-add (ns)","0.72"
    "lat_ops-int-bit (ns)","0.48"
    "lat_ops-int-div (ns)","4.29"
    "lat_ops-int-mod (ns)","4.53"
    "lat_ops-int-mul (ns)","3.07"
    "lat_ops-int64-add (ns)","0.72"
    "lat_ops-int64-bit (ns)","0.48"
    "lat_ops-int64-div (ns)","6.79"
    "lat_ops-int64-mod (ns)","5.25"
    "lat_ops-int64-mul (ns)","3.70"
    "lat_pagefault (us)","1.40"
    "lat_pipe (us)","19.56"
    "lat_proc-exec (us)","722.57"
    "lat_proc-fork (us)","596.00"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","33.73"
    "lat_sem (us)","1.37"
    "lat_sig-catch (us)","5.42"
    "lat_sig-install (us)","0.68"
    "lat_sig-prot (us)","1.59"
    "lat_syscall-fstat (us)","2.69"
    "lat_syscall-null (us)","0.46"
    "lat_syscall-open (us)","146.43"
    "lat_syscall-read (us)","0.75"
    "lat_syscall-stat (us)","3.82"
    "lat_syscall-write (us)","0.68"
    "lat_tcp (us)","0.91"
    "lat_unix (us)","22.33"
    "latency_for_0.50_mb_block_size (nanosec)","7.69"
    "latency_for_1.00_mb_block_size (nanosec)","14.75 (min 0.00, max 29.50)"
    "pipe_bandwidth (MBs)","725.97"
    "pipe_latency (microsec)","19.56"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","33.73"
    "semaphore_latency (microsec)","1.37"
    "signal_handler_latency (microsec)","0.68"
    "signal_handler_overhead (microsec)","5.42"
    "tcp_ip_connection_cost_to_localhost (microsec)","51.62"
    "tcp_latency_using_localhost (microsec)","0.91"




Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

Execute the benchmark with the following:

::

    runDhrystone

.. csv-table:: Dhrystone Benchmarks
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "cpu_clock (MHz)","1400.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.90"
    "dhrystone_per_second (DhrystoneP)","7142857.00"

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Whetstone is a benchmark primarily measuring floating-point arithmetic performance.

Execute the benchmark with the following:

::

    runWhetstone

.. csv-table:: Whetstone Benchmarks
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "whetstone (MIPS)","5000.00"

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table:: Linpack Benchmarks
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "linpack (Kflops)","577759.00"




NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html

.. csv-table:: NBench Benchmarks
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "assignment (Iterations)","13.91"
    "fourier (Iterations)","22639.00"
    "fp_emulation (Iterations)","92.34"
    "huffman (Iterations)","1169.50"
    "idea (Iterations)","3445.00"
    "lu_decomposition (Iterations)","534.81"
    "neural_net (Iterations)","8.77"
    "numeric_sort (Iterations)","598.72"
    "string_sort (Iterations)","155.34"




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

.. csv-table:: Stream Benchmarks
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "add (MB/s)","2898.60"
    "copy (MB/s)","4044.50"
    "scale (MB/s)","3720.40"
    "triad (MB/s)","2543.40"




CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.


.. csv-table:: CoreMarkPro Benchmarks
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "cjpeg-rose7-preset (workloads/)","42.02"
    "core (workloads/)","0.30"
    "coremark-pro ()","952.19"
    "linear_alg-mid-100x100-sp (workloads/)","14.69"
    "loops-all-mid-10k-sp (workloads/)","0.72"
    "nnet_test (workloads/)","1.09"
    "parser-125k (workloads/)","8.85"
    "radix2-big-64k (workloads/)","77.78"
    "sha-test (workloads/)","81.97"
    "zip-test (workloads/)","22.22"



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

.. csv-table:: Multibench Benchmarks
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "4m-check (workloads/)","429.70"
    "4m-check-reassembly (workloads/)","136.05"
    "4m-check-reassembly-tcp (workloads/)","62.81"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","34.29"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.92"
    "4m-cmykw2 (workloads/)","246.31"
    "4m-cmykw2-rotatew2 (workloads/)","51.11"
    "4m-reassembly (workloads/)","93.11"
    "4m-rotatew2 (workloads/)","54.67"
    "4m-tcp-mixed (workloads/)","120.30"
    "4m-x264w2 (workloads/)","2.00"
    "idct-4m (workloads/)","19.26"
    "idct-4mw1 (workloads/)","19.27"
    "ippktcheck-4m (workloads/)","431.26"
    "ippktcheck-4mw1 (workloads/)","429.48"
    "ipres-4m (workloads/)","117.19"
    "ipres-4mw1 (workloads/)","119.05"
    "md5-4m (workloads/)","29.29"
    "md5-4mw1 (workloads/)","29.65"
    "rgbcmyk-4m (workloads/)","63.03"
    "rgbcmyk-4mw1 (workloads/)","63.01"
    "rotate-4ms1 (workloads/)","24.32"
    "rotate-4ms1w1 (workloads/)","24.40"
    "rotate-4ms64 (workloads/)","24.56"
    "rotate-4ms64w1 (workloads/)","24.64"
    "x264-4mq (workloads/)","0.58"
    "x264-4mqw1 (workloads/)","0.58"

|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: Boot time MMCSD
    :header: "Boot Configuration","am62pxx_sk-fs: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","13.24 (min 13.20, max 13.26)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","3.73 (min 3.72, max 3.73)"



|

ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64


.. csv-table:: Audio Capture
    :header: "Sampling Rate (Hz)","am62pxx_sk-fs: Throughput (bits/sec)","am62pxx_sk-fs: CPU Load (%)"

    "8000","255996.00","0.11"
    "11025","352795.00","0.16"
    "16000","511994.00","0.29"
    "22050","705592.00","0.24"
    "24000","705590.00","0.24"
    "32000","1023981.00","0.15"
    "44100","1411176.00","0.36"
    "48000","1535976.00","0.59"
    "88200","2822355.00","0.72"
    "96000","3071952.00","1.09"



 
 



 



|

Graphics SGX/RGX Driver
-------------------------

Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table:: Glmark2 Performance
    :header: "Benchmark","am62pxx_sk-fs: Score"

    "Glmark2-DRM","57.00"
    "Glmark2-Wayland","917.00"



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

CPSW/CPSW2g/CPSW3g Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- CPSW3g: AM62px

.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table:: CPSW2g TCP Bidirectional Throughput
    :header: "Command Used","am62pxx_sk-fs: THROUGHPUT (Mbits/sec)","am62pxx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1852.52","60.29"




.. rubric::  TCP Bidirectional Throughput Interrupt Pacing
   :name: CPSW2g-tcp-bidirectional-throughput-interrupt-pacing

.. csv-table:: CPSW2g TCP Bidirectional Throughput Interrupt Pacing
    :header: "Command Used","am62pxx_sk-fs: THROUGHPUT (Mbits/sec)","am62pxx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1487.63","38.86"


.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table:: CPSW2g UDP Egress Throughput 0 loss
    :header: "Frame Size(bytes)","am62pxx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62pxx_sk-fs: THROUGHPUT (Mbits/sec)","am62pxx_sk-fs: Packets Per Second (kPPS)","am62pxx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","20.25","141.00","41.93"
    "128","82.00","92.32","141.00","42.04"
    "256","210.00","229.54","137.00","41.59"
    "512","466.00","508.28","136.00","41.42"
    "1024","978.00","936.35","120.00","43.33"
    "1280","1234.00","946.67","96.00","35.86"
    "1518","1472.00","955.83","81.00","33.81"




.. csv-table:: CPSW2g UDP Ingress Throughput 0 loss
    :header: "Frame Size(bytes)","am62pxx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62pxx_sk-fs: THROUGHPUT (Mbits/sec)","am62pxx_sk-fs: Packets Per Second (kPPS)","am62pxx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.86","13.00","15.71"
    "128","82.00","5.25","8.00","8.19"
    "256","210.00","88.87","53.00","31.21"
    "512","466.00","32.81","9.00","10.28"
    "1024","978.00","918.39","117.00","40.49"
    "1280","1234.00","932.89","94.00","39.83"
    "1518","1472.00","955.51","81.00","39.85"




.. csv-table:: CPSW2g UDP Ingress Throughput possible loss
    :header: "Frame Size(bytes)","am62pxx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62pxx_sk-fs: THROUGHPUT (Mbits/sec)","am62pxx_sk-fs: Packets Per Second (kPPS)","am62pxx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62pxx_sk-fs: Packet Loss %"

    "64","18.00","29.68","206.00","39.06","63.43"
    "128","82.00","134.29","205.00","40.34","58.98"
    "256","210.00","353.98","211.00","42.32","50.72"
    "512","466.00","732.27","196.00","41.95","15.60"
    "1024","978.00","918.39","117.00","40.49","0.00"
    "1280","1234.00","932.89","94.00","39.83","0.00"
    "1518","1472.00","955.51","81.00","39.85","0.00"

 
 

 

 
 

 

 



|

Linux OSPI Flash Driver
-------------------------

 



AM62PXX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^


UBIFS
"""""""""""""""""""""""""""

.. csv-table:: OSPI Flash Driver
    :header: "Buffer size (bytes)","am62pxx_sk-fs: Write UBIFS Throughput (Mbytes/sec)","am62pxx_sk-fs: Write UBIFS CPU Load (%)","am62pxx_sk-fs: Read UBIFS Throughput (Mbytes/sec)","am62pxx_sk-fs: Read UBIFS CPU Load (%)"

    "102400","0.18 (min 0.13, max 0.29)","12.67 (min 12.45, max 12.94)","29.03","3.57"
    "262144","0.16 (min 0.11, max 0.19)","11.71 (min 10.66, max 12.29)","29.12","0.00"
    "524288","0.16 (min 0.11, max 0.19)","12.43 (min 11.84, max 13.70)","29.05","0.00"
    "1048576","0.16 (min 0.11, max 0.19)","11.51 (min 10.90, max 12.34)","28.68","9.68"




RAW
"""""""""""""""""""""""""""

.. csv-table:: OSPI Raw Flash Driver
    :header: "File size (Mbytes)","am62pxx_sk-fs: Raw Read Throughput (Mbytes/sec)"

    "50","37.59"

 


|

EMMC Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

AM62PXX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: EMMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","am62pxx_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62pxx_sk-fs: Write EXT4 CPU Load (%)","am62pxx_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62pxx_sk-fs: Read EXT4 CPU Load (%)"

    "1m","90.10","1.23","278.00","2.07"
    "4m","95.80","0.97","286.00","1.74"
    "4k","79.80","27.02","92.60","25.19"
    "256k","90.00","1.42","286.00","3.21"

 



|

UBoot EMMC Driver
-------------------------

AM62PXX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT EMMC RAW
    :header: "File size (bytes in hex)","am62pxx_sk-fs: Write Throughput (Kbytes/sec)","am62pxx_sk-fs: Read Throughput (Kbytes/sec)"

    "2000000","96946.75","270809.92"
    "4000000","94842.26","281270.39"

 



|

MMC/SD Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

AM62PXX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: MMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","am62pxx_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62pxx_sk-fs: Write EXT4 CPU Load (%)","am62pxx_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62pxx_sk-fs: Read EXT4 CPU Load (%)"

    "1m","7.32","0.28","89.70","0.86"
    "4m","7.35","0.29","89.70","0.73"
    "4k","2.65","1.18","19.70","3.84"
    "256k","6.41","0.31","88.90","1.02"






 

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|

UBoot MMC/SD Driver
-------------------------

AM62PXX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT MMCSD FAT
    :header: "File size (bytes in hex)","am62pxx_sk-fs: Write Throughput (Kbytes/sec)","am62pxx_sk-fs: Read Throughput (Kbytes/sec)"

    "400000","38280.37","55351.35"
    "800000","14921.68","69423.73"
    "1000000","23339.03","79149.76"

 



|

USB Driver
-------------------------

USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. csv-table:: USBDEVICE HIGHSPEED SLAVE_READ_THROUGHPUT
    :header: "Number of Blocks","am62pxx_sk-fs: Throughput (MB/sec)"

    "150","44.10"




.. csv-table:: USBDEVICE HIGHSPEED SLAVE_WRITE_THROUGHPUT
    :header: "Number of Blocks","am62pxx_sk-fs: Throughput (MB/sec)"

    "150","38.20"




|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: OpenSSL Performance
    :header: "Algorithm","Buffer Size (in bytes)","am62pxx_sk-fs: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","27078.66"
    "aes-128-cbc","16","570.01"
    "aes-128-cbc","16384","88926.89"
    "aes-128-cbc","256","8248.06"
    "aes-128-cbc","64","2231.83"
    "aes-128-cbc","8192","76491.43"
    "aes-128-ecb","1024","27669.16"
    "aes-128-ecb","16","582.07"
    "aes-128-ecb","16384","90854.74"
    "aes-128-ecb","256","8541.95"
    "aes-128-ecb","64","2294.36"
    "aes-128-ecb","8192","78681.43"
    "aes-192-cbc","1024","26673.15"
    "aes-192-cbc","16","563.94"
    "aes-192-cbc","16384","80281.60"
    "aes-192-cbc","256","8215.21"
    "aes-192-cbc","64","2238.87"
    "aes-192-cbc","8192","70115.33"
    "aes-192-ecb","1024","27458.22"
    "aes-192-ecb","16","584.84"
    "aes-192-ecb","16384","81870.85"
    "aes-192-ecb","256","8444.42"
    "aes-192-ecb","64","2298.03"
    "aes-192-ecb","8192","71625.39"
    "aes-256-cbc","1024","25774.08"
    "aes-256-cbc","16","562.31"
    "aes-256-cbc","16384","72608.43"
    "aes-256-cbc","256","8191.91"
    "aes-256-cbc","64","2206.04"
    "aes-256-cbc","8192","64577.54"
    "aes-256-ecb","1024","26596.69"
    "aes-256-ecb","16","583.58"
    "aes-256-ecb","16384","73990.14"
    "aes-256-ecb","256","8369.58"
    "aes-256-ecb","64","2296.30"
    "aes-256-ecb","8192","66084.86"
    "sha256","1024","37207.38"
    "sha256","16","621.78"
    "sha256","16384","285911.72"
    "sha256","256","9724.84"
    "sha256","64","2458.24"
    "sha256","8192","196343.13"
    "sha512","1024","26140.33"
    "sha512","16","608.38"
    "sha512","16384","69091.33"
    "sha512","256","8649.90"
    "sha512","64","2432.64"
    "sha512","8192","62125.40"





.. csv-table:: OpenSSL CPU Load
    :header: "Algorithm","am62pxx_sk-fs: CPU Load"

    "aes-128-cbc","33.00"
    "aes-128-ecb","34.00"
    "aes-192-cbc","33.00"
    "aes-192-ecb","33.00"
    "aes-256-cbc","32.00"
    "aes-256-ecb","32.00"
    "sha256","98.00"
    "sha512","98.00"



Listed for each algorithm are the code snippets used to run each
  benchmark test.

::

    time -v openssl speed -elapsed -evp aes-128-cbc

Low Power Performance
-------------------------

Table:  **Deep sleep**

.. csv-table::
    :header: "Rail name","Rail voltage(V)","am62pxx_sk-fs"

    "vdd_core","0.85","14.08"
    "vddr_core","0.85","1.24"
    "soc_dvdd_3v3","3.30","5.36"
    "soc_dvdd_1v8","1.80","2.87"
    "vdda_1v8","1.80","9.26"
    "vdd_lpddr4/vdd_ddr4","1.10","5.20"
    "Total"," ","38.02"

Table:  **MCU only**

.. csv-table::
    :header: "Rail name","Rail voltage(V)","am62pxx_sk-fs"

    "vdd_core","0.85","202.22"
    "vddr_core","0.85","2.67"
    "soc_dvdd_3v3","3.30","5.28"
    "soc_dvdd_1v8","1.80","2.84"
    "vdda_1v8","1.80","17.62"
    "vdd_lpddr4/vdd_ddr4","1.10","3.36"
    "Total"," ","233.99"

Partial I/O Data
- All voltage rails were measured to be near 0V

Further optimizations are possible for these low power modes. Please refer to the AM62x Power Consumption App Note (https://www.ti.com/lit/pdf/spradg1)
