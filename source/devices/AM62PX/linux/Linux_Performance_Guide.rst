
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

.. csv-table::
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "af_unix_sock_stream_latency (microsec)","24.11"
    "af_unix_socket_stream_bandwidth (MBs)","1157.09"
    "bw_file_rd-io-1mb (MB/s)","1259.67"
    "bw_file_rd-o2c-1mb (MB/s)","700.16"
    "bw_mem-bcopy-16mb (MB/s)","1840.35"
    "bw_mem-bcopy-1mb (MB/s)","1998.40"
    "bw_mem-bcopy-2mb (MB/s)","1765.85"
    "bw_mem-bcopy-4mb (MB/s)","1814.33"
    "bw_mem-bcopy-8mb (MB/s)","1812.83"
    "bw_mem-bzero-16mb (MB/s)","7811.23"
    "bw_mem-bzero-1mb (MB/s)","4892.32 (min 1998.40, max 7786.23)"
    "bw_mem-bzero-2mb (MB/s)","4781.56 (min 1765.85, max 7797.27)"
    "bw_mem-bzero-4mb (MB/s)","4807.19 (min 1814.33, max 7800.04)"
    "bw_mem-bzero-8mb (MB/s)","4808.86 (min 1812.83, max 7804.88)"
    "bw_mem-cp-16mb (MB/s)","916.17"
    "bw_mem-cp-1mb (MB/s)","1241.66 (min 890.00, max 1593.31)"
    "bw_mem-cp-2mb (MB/s)","1132.75 (min 886.66, max 1378.83)"
    "bw_mem-cp-4mb (MB/s)","1168.97 (min 932.94, max 1404.99)"
    "bw_mem-cp-8mb (MB/s)","1247.39 (min 954.54, max 1540.24)"
    "bw_mem-fcp-16mb (MB/s)","1729.73"
    "bw_mem-fcp-1mb (MB/s)","4739.30 (min 1692.37, max 7786.23)"
    "bw_mem-fcp-2mb (MB/s)","4699.41 (min 1601.54, max 7797.27)"
    "bw_mem-fcp-4mb (MB/s)","4736.38 (min 1672.71, max 7800.04)"
    "bw_mem-fcp-8mb (MB/s)","4712.00 (min 1619.11, max 7804.88)"
    "bw_mem-frd-16mb (MB/s)","1871.13"
    "bw_mem-frd-1mb (MB/s)","1826.58 (min 1692.37, max 1960.78)"
    "bw_mem-frd-2mb (MB/s)","1673.53 (min 1601.54, max 1745.51)"
    "bw_mem-frd-4mb (MB/s)","1752.67 (min 1672.71, max 1832.62)"
    "bw_mem-frd-8mb (MB/s)","1714.64 (min 1619.11, max 1810.16)"
    "bw_mem-fwr-16mb (MB/s)","1548.59"
    "bw_mem-fwr-1mb (MB/s)","1777.05 (min 1593.31, max 1960.78)"
    "bw_mem-fwr-2mb (MB/s)","1562.17 (min 1378.83, max 1745.51)"
    "bw_mem-fwr-4mb (MB/s)","1618.81 (min 1404.99, max 1832.62)"
    "bw_mem-fwr-8mb (MB/s)","1675.20 (min 1540.24, max 1810.16)"
    "bw_mem-rd-16mb (MB/s)","16.00"
    "bw_mem-rd-1mb (MB/s)","2002.94 (min 1840.60, max 2165.28)"
    "bw_mem-rd-2mb (MB/s)","1791.11 (min 1654.81, max 1927.40)"
    "bw_mem-rd-4mb (MB/s)","1849.46 (min 1780.15, max 1918.77)"
    "bw_mem-rd-8mb (MB/s)","1869.24 (min 1822.53, max 1915.94)"
    "bw_mem-rdwr-16mb (MB/s)","1855.29"
    "bw_mem-rdwr-1mb (MB/s)","1285.97 (min 890.00, max 1681.93)"
    "bw_mem-rdwr-2mb (MB/s)","1262.00 (min 886.66, max 1637.33)"
    "bw_mem-rdwr-4mb (MB/s)","1297.38 (min 932.94, max 1661.82)"
    "bw_mem-rdwr-8mb (MB/s)","1347.41 (min 954.54, max 1740.27)"
    "bw_mem-wr-16mb (MB/s)","1831.08"
    "bw_mem-wr-1mb (MB/s)","1761.27 (min 1681.93, max 1840.60)"
    "bw_mem-wr-2mb (MB/s)","1646.07 (min 1637.33, max 1654.81)"
    "bw_mem-wr-4mb (MB/s)","1720.99 (min 1661.82, max 1780.15)"
    "bw_mem-wr-8mb (MB/s)","1781.40 (min 1740.27, max 1822.53)"
    "bw_mmap_rd-mo-1mb (MB/s)","2165.67"
    "bw_mmap_rd-o2c-1mb (MB/s)","646.73"
    "bw_pipe (MB/s)","717.53"
    "bw_unix (MB/s)","1157.09"
    "lat_connect (us)","52.27"
    "lat_ctx-2-128k (us)","4.79"
    "lat_ctx-2-256k (us)","3.86"
    "lat_ctx-4-128k (us)","4.51"
    "lat_ctx-4-256k (us)","3.49"
    "lat_fs-0k (num_files)","283.00"
    "lat_fs-10k (num_files)","124.00"
    "lat_fs-1k (num_files)","183.00"
    "lat_fs-4k (num_files)","165.00"
    "lat_mem_rd-stride128-sz1000k (ns)","31.26"
    "lat_mem_rd-stride128-sz125k (ns)","5.54"
    "lat_mem_rd-stride128-sz250k (ns)","5.83"
    "lat_mem_rd-stride128-sz31k (ns)","3.65"
    "lat_mem_rd-stride128-sz50 (ns)","2.15"
    "lat_mem_rd-stride128-sz500k (ns)","10.41"
    "lat_mem_rd-stride128-sz62k (ns)","5.19"
    "lat_mmap-1m (us)","56.00"
    "lat_ops-double-add (ns)","2.86"
    "lat_ops-double-div (ns)","15.73"
    "lat_ops-double-mul (ns)","2.86"
    "lat_ops-float-add (ns)","2.86"
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
    "lat_ops-int64-mul (ns)","3.55"
    "lat_pagefault (us)","1.39"
    "lat_pipe (us)","19.48"
    "lat_proc-exec (us)","782.00"
    "lat_proc-fork (us)","606.11"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","33.39"
    "lat_sem (us)","1.79"
    "lat_sig-catch (us)","5.28"
    "lat_sig-install (us)","0.66"
    "lat_sig-prot (us)","0.55"
    "lat_syscall-fstat (us)","2.73"
    "lat_syscall-null (us)","0.46"
    "lat_syscall-open (us)","149.03"
    "lat_syscall-read (us)","0.77"
    "lat_syscall-stat (us)","3.94"
    "lat_syscall-write (us)","0.64"
    "lat_tcp (us)","0.93"
    "lat_unix (us)","24.11"
    "latency_for_0.50_mb_block_size (nanosec)","10.41"
    "latency_for_1.00_mb_block_size (nanosec)","6.25 (min 0.00, max 31.26)"
    "pipe_bandwidth (MBs)","717.53"
    "pipe_latency (microsec)","19.48"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","33.39"
    "semaphore_latency (microsec)","1.79"
    "signal_handler_latency (microsec)","0.66"
    "signal_handler_overhead (microsec)","5.28"
    "tcp_ip_connection_cost_to_localhost (microsec)","52.27"
    "tcp_latency_using_localhost (microsec)","0.93"

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

Execute the benchmark with the following:

::

    runDhrystone

.. csv-table::
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

.. csv-table::
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "whetstone (MIPS)","5000.00"

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "linpack (Kflops)","580494.00"

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html

.. csv-table::
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "assignment (Iterations)","13.94"
    "fourier (Iterations)","22639.00"
    "fp_emulation (Iterations)","92.34"
    "huffman (Iterations)","1169.40"
    "idea (Iterations)","3444.90"
    "lu_decomposition (Iterations)","533.43"
    "neural_net (Iterations)","8.82"
    "numeric_sort (Iterations)","598.41"
    "string_sort (Iterations)","164.95"

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
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "add (MB/s)","2702.00"
    "copy (MB/s)","3765.90"
    "scale (MB/s)","3488.00"
    "triad (MB/s)","2402.50"

CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.

.. csv-table::
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "cjpeg-rose7-preset (workloads/)","41.84"
    "core (workloads/)","0.30"
    "coremark-pro ()","944.26"
    "linear_alg-mid-100x100-sp (workloads/)","14.70"
    "loops-all-mid-10k-sp (workloads/)","0.71"
    "nnet_test (workloads/)","1.09"
    "parser-125k (workloads/)","8.77"
    "radix2-big-64k (workloads/)","75.73"
    "sha-test (workloads/)","81.97"
    "zip-test (workloads/)","21.74"

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
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "4m-check (workloads/)","412.47"
    "4m-check-reassembly (workloads/)","128.37"
    "4m-check-reassembly-tcp (workloads/)","60.68"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","33.43"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.95"
    "4m-cmykw2 (workloads/)","251.26"
    "4m-cmykw2-rotatew2 (workloads/)","50.34"
    "4m-reassembly (workloads/)","88.42"
    "4m-rotatew2 (workloads/)","53.45"
    "4m-tcp-mixed (workloads/)","120.30"
    "4m-x264w2 (workloads/)","2.01"
    "idct-4m (workloads/)","19.22"
    "idct-4mw1 (workloads/)","19.23"
    "ippktcheck-4m (workloads/)","413.29"
    "ippktcheck-4mw1 (workloads/)","412.95"
    "ipres-4m (workloads/)","112.28"
    "ipres-4mw1 (workloads/)","111.69"
    "md5-4m (workloads/)","28.96"
    "md5-4mw1 (workloads/)","29.38"
    "rgbcmyk-4m (workloads/)","65.94"
    "rgbcmyk-4mw1 (workloads/)","65.94"
    "rotate-4ms1 (workloads/)","23.58"
    "rotate-4ms1w1 (workloads/)","23.54"
    "rotate-4ms64 (workloads/)","23.84"
    "rotate-4ms64w1 (workloads/)","23.79"
    "x264-4mq (workloads/)","0.58"
    "x264-4mqw1 (workloads/)","0.58"

|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am62pxx_sk-fs: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","105.28 (min 15.02, max 128.07)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","3.70 (min 3.67, max 3.77)"

|

Graphics SGX/RGX Driver
-------------------------

Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am62pxx_sk-fs: Score"

    "Glmark2-DRM","57.00"
    "Glmark2-Wayland","913.00"

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

.. csv-table::
    :header: "Command Used","am62pxx_sk-fs: THROUGHPUT (Mbits/sec)","am62pxx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1800.0","59.22"

- Interrupt pacing value is kept as 250 microseconds for tx and rx interrupts.

.. rubric::  TCP Bidirectional Throughput Interrupt Pacing
   :name: CPSW2g-tcp-bidirectional-throughput-interrupt-pacing

.. csv-table::
    :header: "Command Used","am62pxx_sk-fs: THROUGHPUT (Mbits/sec)","am62pxx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1344.61","37.04"

.. rubric:: CPSW UDP Egress Throughput
   :name: CPSW-udp-egress-throughput

.. csv-table::
    :header: "Frame Size(bytes)","am62pxx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62pxx_sk-fs: THROUGHPUT (Mbits/sec)","am62pxx_sk-fs: CPU Load %(LOCAL_CPU_UTIL)"

    "64","18.00","19.89","41.4"
    "128","82.00","90.14","41.57"
    "256","210.00","225.72","41.14"
    "512","466.00","498.49","41.15"
    "1024","978.00","936.62","42.7"
    "1280","1234.00","947.78","33.1"
    "1518","1472.00","955.52","33.21"

|

.. rubric:: CPSW UDP Ingress Throughput
   :name: CPSW-udp-Ingress-throughput

.. csv-table::
    :header: "Frame Size(bytes)","am62pxx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62pxx_sk-fs: THROUGHPUT (Mbits/sec)","am62pxx_sk-fs: CPU Load %(LOCAL_CPU_UTIL)","am62pxx_sk-fs: Packet loss %"

    "64","18.00","7.3","31.08","63.54"
    "128","82.00","34.9","30.41","58.7"
    "256","210.00","94.08","31.17","50.21"
    "512","466.00","201.31","32.04","13.06"
    "1024","978.00","916.22","40.04","0.02"
    "1280","1234.00","930.71","39.42","0.0"
    "1518","1472.00","916.74","38.17","0.0"

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

.. csv-table::
    :header: "Buffer size (bytes)","am62pxx_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62pxx_sk-fs: Write EXT4 CPU Load (%)","am62pxx_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62pxx_sk-fs: Read EXT4 CPU Load (%)"

    "1m","89.80","1.21","285.00","2.24"
    "4m","95.70","0.94","286.00","1.76"
    "4k","79.20","26.99","92.80","25.24"
    "256k","90.30","1.71","284.00","3.43"

|

UBoot EMMC Driver
-------------------------

AM62PXX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Table:  **UBOOT EMMC RAW**

.. csv-table::
    :header: "File size (bytes in hex)","am62pxx_sk-fs: Write Throughput (Kbytes/sec)","am62pxx_sk-fs: Read Throughput (Kbytes/sec)"

    "2000000","95533.53","268590.16"
    "4000000","98254.87","232397.16"

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

.. csv-table::
    :header: "Buffer size (bytes)","am62pxx_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62pxx_sk-fs: Write EXT4 CPU Load (%)","am62pxx_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62pxx_sk-fs: Read EXT4 CPU Load (%)"

    "1m","42.70","0.81","87.50","1.05"
    "4m","43.40","0.60","87.30","0.81"
    "4k","3.60","1.64","16.40","5.05"
    "256k","39.60","1.00","85.50","1.24"

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|

UBoot MMC/SD Driver
-------------------------

AM62PXX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Table:  **UBOOT MMCSD FAT**

.. csv-table::
    :header: "File size (bytes in hex)","am62pxx_sk-fs: Write Throughput (Kbytes/sec)","am62pxx_sk-fs: Read Throughput (Kbytes/sec)"

    "400000","37236.36","60235.29"
    "800000","40960.00","72495.58"
    "1000000","41583.76","81512.44"

|

USB Driver
-------------------------

USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Table:  **USBDEVICE HIGHSPEED SLAVE_READ_THROUGHPUT**

.. csv-table::
    :header: "Number of Blocks","am62pxx_sk-fs: Throughput (MB/sec)"

    "150","44.10"

Table:  **USBDEVICE HIGHSPEED SLAVE_WRITE_THROUGHPUT**

.. csv-table::
    :header: "Number of Blocks","am62pxx_sk-fs: Throughput (MB/sec)"

    "150","39.90"

|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Table:  **OpenSSL Performance**

.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am62pxx_sk-fs: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","27031.21"
    "aes-128-cbc","16","552.76"
    "aes-128-cbc","16384","88069.46"
    "aes-128-cbc","256","8216.49"
    "aes-128-cbc","64","2187.29"
    "aes-128-cbc","8192","76024.49"
    "aes-128-ecb","1024","27399.85"
    "aes-128-ecb","16","573.77"
    "aes-128-ecb","16384","91215.19"
    "aes-128-ecb","256","8339.88"
    "aes-128-ecb","64","2251.84"
    "aes-128-ecb","8192","78157.14"
    "aes-192-cbc","1024","26395.65"
    "aes-192-cbc","16","553.54"
    "aes-192-cbc","16384","79527.94"
    "aes-192-cbc","256","8087.89"
    "aes-192-cbc","64","2193.92"
    "aes-192-cbc","8192","69823.15"
    "aes-192-ecb","1024","27090.60"
    "aes-192-ecb","16","570.65"
    "aes-192-ecb","16384","82482.52"
    "aes-192-ecb","256","8261.63"
    "aes-192-ecb","64","2266.73"
    "aes-192-ecb","8192","71778.30"
    "aes-256-cbc","1024","25508.18"
    "aes-256-cbc","16","555.50"
    "aes-256-cbc","16384","72783.19"
    "aes-256-cbc","256","7644.93"
    "aes-256-cbc","64","2168.23"
    "aes-256-cbc","8192","64143.36"
    "aes-256-ecb","1024","26324.31"
    "aes-256-ecb","16","568.96"
    "aes-256-ecb","16384","74880.34"
    "aes-256-ecb","256","8201.64"
    "aes-256-ecb","64","2240.98"
    "aes-256-ecb","8192","66183.17"
    "sha256","1024","36728.83"
    "sha256","16","613.09"
    "sha256","16384","283989.33"
    "sha256","256","9599.83"
    "sha256","64","2425.77"
    "sha256","8192","195665.92"
    "sha512","1024","25829.72"
    "sha512","16","600.75"
    "sha512","16384","69058.56"
    "sha512","256","8569.77"
    "sha512","64","2403.75"
    "sha512","8192","61964.29"

Table:  **OpenSSL CPU Load**

.. csv-table::
    :header: "Algorithm","am62pxx_sk-fs: CPU Load"

    "aes-128-cbc","32.00"
    "aes-128-ecb","34.00"
    "aes-192-cbc","32.00"
    "aes-192-ecb","33.00"
    "aes-256-cbc","31.00"
    "aes-256-ecb","33.00"
    "sha256","98.00"
    "sha512","98.00"

Listed for each algorithm are the code snippets used to run each benchmark test.

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
