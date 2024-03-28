
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
| AM62Ax SK      | AM62Ax Starter Kit with ARM running at 1.2GHz, DDR data rate 3733 MT/S                                         |
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
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "af_unix_sock_stream_latency (microsec)","24.82"
    "af_unix_socket_stream_bandwidth (MBs)","1044.50"
    "bw_file_rd-io-1mb (MB/s)","1195.36"
    "bw_file_rd-o2c-1mb (MB/s)","661.59"
    "bw_mem-bcopy-16mb (MB/s)","1746.53"
    "bw_mem-bcopy-1mb (MB/s)","1808.32"
    "bw_mem-bcopy-2mb (MB/s)","1691.76"
    "bw_mem-bcopy-4mb (MB/s)","1691.81"
    "bw_mem-bcopy-8mb (MB/s)","1736.30"
    "bw_mem-bzero-16mb (MB/s)","7143.92"
    "bw_mem-bzero-1mb (MB/s)","4446.49 (min 1808.32, max 7084.66)"
    "bw_mem-bzero-2mb (MB/s)","4391.35 (min 1691.76, max 7090.94)"
    "bw_mem-bzero-4mb (MB/s)","4421.17 (min 1691.81, max 7150.52)"
    "bw_mem-bzero-8mb (MB/s)","4451.74 (min 1736.30, max 7167.17)"
    "bw_mem-cp-16mb (MB/s)","892.51"
    "bw_mem-cp-1mb (MB/s)","1167.12 (min 854.12, max 1480.11)"
    "bw_mem-cp-2mb (MB/s)","1096.19 (min 846.26, max 1346.12)"
    "bw_mem-cp-4mb (MB/s)","1131.61 (min 905.90, max 1357.31)"
    "bw_mem-cp-8mb (MB/s)","1148.38 (min 934.58, max 1362.17)"
    "bw_mem-fcp-16mb (MB/s)","1598.08"
    "bw_mem-fcp-1mb (MB/s)","4330.98 (min 1577.29, max 7084.66)"
    "bw_mem-fcp-2mb (MB/s)","4322.78 (min 1554.61, max 7090.94)"
    "bw_mem-fcp-4mb (MB/s)","4400.35 (min 1650.17, max 7150.52)"
    "bw_mem-fcp-8mb (MB/s)","4411.74 (min 1656.31, max 7167.17)"
    "bw_mem-frd-16mb (MB/s)","1811.18"
    "bw_mem-frd-1mb (MB/s)","1713.72 (min 1577.29, max 1850.14)"
    "bw_mem-frd-2mb (MB/s)","1593.30 (min 1554.61, max 1631.99)"
    "bw_mem-frd-4mb (MB/s)","1723.43 (min 1650.17, max 1796.68)"
    "bw_mem-frd-8mb (MB/s)","1734.78 (min 1656.31, max 1813.24)"
    "bw_mem-fwr-16mb (MB/s)","1366.70"
    "bw_mem-fwr-1mb (MB/s)","1665.13 (min 1480.11, max 1850.14)"
    "bw_mem-fwr-2mb (MB/s)","1489.06 (min 1346.12, max 1631.99)"
    "bw_mem-fwr-4mb (MB/s)","1577.00 (min 1357.31, max 1796.68)"
    "bw_mem-fwr-8mb (MB/s)","1587.71 (min 1362.17, max 1813.24)"
    "bw_mem-rd-16mb (MB/s)","1877.71"
    "bw_mem-rd-1mb (MB/s)","1866.21 (min 1699.52, max 2032.90)"
    "bw_mem-rd-2mb (MB/s)","1704.10 (min 1543.69, max 1864.51)"
    "bw_mem-rd-4mb (MB/s)","1743.74 (min 1611.60, max 1875.88)"
    "bw_mem-rd-8mb (MB/s)","1719.58 (min 1563.42, max 1875.73)"
    "bw_mem-rdwr-16mb (MB/s)","1569.40"
    "bw_mem-rdwr-1mb (MB/s)","1247.93 (min 854.12, max 1641.74)"
    "bw_mem-rdwr-2mb (MB/s)","1151.86 (min 846.26, max 1457.46)"
    "bw_mem-rdwr-4mb (MB/s)","1203.42 (min 905.90, max 1500.94)"
    "bw_mem-rdwr-8mb (MB/s)","1278.08 (min 934.58, max 1621.57)"
    "bw_mem-wr-16mb (MB/s)","1579.93"
    "bw_mem-wr-1mb (MB/s)","1670.63 (min 1641.74, max 1699.52)"
    "bw_mem-wr-2mb (MB/s)","1500.58 (min 1457.46, max 1543.69)"
    "bw_mem-wr-4mb (MB/s)","1556.27 (min 1500.94, max 1611.60)"
    "bw_mem-wr-8mb (MB/s)","1592.50 (min 1563.42, max 1621.57)"
    "bw_mmap_rd-mo-1mb (MB/s)","1984.48"
    "bw_mmap_rd-o2c-1mb (MB/s)","599.70"
    "bw_pipe (MB/s)","657.20"
    "bw_unix (MB/s)","1044.50"
    "lat_connect (us)","58.23"
    "lat_ctx-2-128k (us)","5.58"
    "lat_ctx-2-256k (us)","6.53"
    "lat_ctx-4-128k (us)","5.69"
    "lat_ctx-4-256k (us)","6.12"
    "lat_fs-0k (num_files)","274.00"
    "lat_fs-10k (num_files)","130.00"
    "lat_fs-1k (num_files)","185.00"
    "lat_fs-4k (num_files)","186.00"
    "lat_mem_rd-stride128-sz1000k (ns)","32.08"
    "lat_mem_rd-stride128-sz125k (ns)","6.29"
    "lat_mem_rd-stride128-sz250k (ns)","6.83"
    "lat_mem_rd-stride128-sz31k (ns)","4.10"
    "lat_mem_rd-stride128-sz50 (ns)","2.41"
    "lat_mem_rd-stride128-sz500k (ns)","14.27"
    "lat_mem_rd-stride128-sz62k (ns)","5.90"
    "lat_mmap-1m (us)","55.00"
    "lat_ops-double-add (ns)","3.21"
    "lat_ops-double-div (ns)","17.68"
    "lat_ops-double-mul (ns)","3.21"
    "lat_ops-float-add (ns)","3.22"
    "lat_ops-float-div (ns)","10.44"
    "lat_ops-float-mul (ns)","3.21"
    "lat_ops-int-add (ns)","0.80"
    "lat_ops-int-bit (ns)","0.54"
    "lat_ops-int-div (ns)","4.82"
    "lat_ops-int-mod (ns)","5.09"
    "lat_ops-int-mul (ns)","3.45"
    "lat_ops-int64-add (ns)","0.80"
    "lat_ops-int64-bit (ns)","0.54"
    "lat_ops-int64-div (ns)","7.63"
    "lat_ops-int64-mod (ns)","5.89"
    "lat_ops-int64-mul (ns)","3.99"
    "lat_pagefault (us)","1.62"
    "lat_pipe (us)","21.99"
    "lat_proc-exec (us)","979.60"
    "lat_proc-fork (us)","772.71"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","37.52"
    "lat_sem (us)","2.87"
    "lat_sig-catch (us)","6.03"
    "lat_sig-install (us)","0.74"
    "lat_sig-prot (us)","0.60"
    "lat_syscall-fstat (us)","3.08"
    "lat_syscall-null (us)","0.52"
    "lat_syscall-open (us)","296.21"
    "lat_syscall-read (us)","0.86"
    "lat_syscall-stat (us)","4.37"
    "lat_syscall-write (us)","0.73"
    "lat_tcp (us)","1.04"
    "lat_unix (us)","24.82"
    "latency_for_0.50_mb_block_size (nanosec)","14.27"
    "latency_for_1.00_mb_block_size (nanosec)","16.04 (min 0.00, max 32.08)"
    "pipe_bandwidth (MBs)","657.20"
    "pipe_latency (microsec)","21.99"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","37.52"
    "semaphore_latency (microsec)","2.87"
    "signal_handler_latency (microsec)","0.74"
    "signal_handler_overhead (microsec)","6.03"
    "tcp_ip_connection_cost_to_localhost (microsec)","58.23"
    "tcp_latency_using_localhost (microsec)","1.04"

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

Execute the benchmark with the following:

::

    runDhrystone

.. csv-table:: Dhrystone Benchmarks
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "cpu_clock (MHz)","1250.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.90"
    "dhrystone_per_second (DhrystoneP)","6451613.00"

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Whetstone is a benchmark primarily measuring floating-point arithmetic performance.

Execute the benchmark with the following:

::

    runWhetstone

.. csv-table:: Whetstone Benchmarks
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "whetstone (MIPS)","5000.00"

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table:: Linpack Benchmarks
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "linpack (Kflops)","517380.00"

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
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "add (MB/s)","2488.60"
    "copy (MB/s)","3595.60"
    "scale (MB/s)","3221.10"
    "triad (MB/s)","2270.00"

CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.

.. csv-table:: CoreMarkPro Benchmarks
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "cjpeg-rose7-preset (workloads/)","36.63"
    "core (workloads/)","0.27"
    "coremark-pro ()","782.38"
    "linear_alg-mid-100x100-sp (workloads/)","13.03"
    "loops-all-mid-10k-sp (workloads/)","0.61"
    "nnet_test (workloads/)","0.97"
    "parser-125k (workloads/)","7.35"
    "radix2-big-64k (workloads/)","39.06"
    "sha-test (workloads/)","72.46"
    "zip-test (workloads/)","19.61"

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
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "4m-check (workloads/)","362.06"
    "4m-check-reassembly (workloads/)","106.16"
    "4m-check-reassembly-tcp (workloads/)","54.35"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","24.17"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.48"
    "4m-cmykw2 (workloads/)","167.65"
    "4m-cmykw2-rotatew2 (workloads/)","36.70"
    "4m-reassembly (workloads/)","82.37"
    "4m-rotatew2 (workloads/)","42.96"
    "4m-tcp-mixed (workloads/)","107.38"
    "4m-x264w2 (workloads/)","1.49"
    "empty-wld (workloads/)","1.00"
    "idct-4m (workloads/)","17.12"
    "idct-4mw1 (workloads/)","17.12"
    "ippktcheck-4m (workloads/)","361.27"
    "ippktcheck-4mw1 (workloads/)","362.00"
    "ipres-4m (workloads/)","106.23"
    "ipres-4mw1 (workloads/)","104.75"
    "md5-4m (workloads/)","25.07"
    "md5-4mw1 (workloads/)","25.11"
    "rgbcmyk-4m (workloads/)","58.70"
    "rgbcmyk-4mw1 (workloads/)","58.77"
    "rotate-4ms1 (workloads/)","21.45"
    "rotate-4ms1w1 (workloads/)","21.41"
    "rotate-4ms64 (workloads/)","21.86"
    "rotate-4ms64w1 (workloads/)","21.65"
    "x264-4mq (workloads/)","0.51"
    "x264-4mqw1 (workloads/)","0.51"

|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: Boot time MMCSD
    :header: "Boot Configuration","am62axx_sk-fs: boot time (sec)"

    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","3.93 (min 3.91, max 3.96)"

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

- CPSW3g: AM64x, AM62x, AM62ax, AM62px


.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table:: CPSW2g TCP Bidirectional Throughput
    :header: "Command Used","am62axx_sk-fs: THROUGHPUT (Mbits/sec)","am62axx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1861.15","83.19"

|

EMMC Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

AM62AXX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: EMMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","am62axx_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62axx_sk-fs: Write EXT4 CPU Load (%)","am62axx_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62axx_sk-fs: Read EXT4 CPU Load (%)"

    "1m","57.70","26.54","175.00","28.29"
    "4m","57.90","26.22","175.00","27.17"
    "4k","51.80","46.96","55.90","46.09"
    "256k","57.70","27.76","174.00","30.04"

|

MMC/SD Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

AM62AXX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: MMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","am62axx_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62axx_sk-fs: Write EXT4 CPU Load (%)","am62axx_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62axx_sk-fs: Read EXT4 CPU Load (%)"

    "1m","28.00","26.14","87.00","27.10"
    "4m","28.60","25.92","86.40","26.45"
    "4k","5.22","28.51","19.30","32.94"
    "256k","27.40","26.62","70.80","27.29"

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|

UBoot MMC/SD Driver
-------------------------

AM62AXX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT MMCSD FAT
    :header: "File size (bytes in hex)","am62axx_sk-fs: Write Throughput (Kbytes/sec)","am62axx_sk-fs: Read Throughput (Kbytes/sec)"

    "400000","18703.20","20177.34"
    "800000","21501.31","21614.78"
    "1000000","21700.66","22413.13"

|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: OpenSSL Performance
    :header: "Algorithm","Buffer Size (in bytes)","am62axx_sk-fs: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","24477.35"
    "aes-128-cbc","16","504.20"
    "aes-128-cbc","16384","85901.31"
    "aes-128-cbc","256","7538.43"
    "aes-128-cbc","64","1985.69"
    "aes-128-cbc","8192","73108.14"
    "aes-128-ecb","1024","25245.01"
    "aes-128-ecb","16","511.58"
    "aes-128-ecb","16384","87676.25"
    "aes-128-ecb","256","7629.06"
    "aes-128-ecb","64","2032.60"
    "aes-128-ecb","8192","75535.70"
    "aes-192-cbc","1024","24161.62"
    "aes-192-cbc","16","495.23"
    "aes-192-cbc","16384","77824.00"
    "aes-192-cbc","256","7382.27"
    "aes-192-cbc","64","1962.43"
    "aes-192-cbc","8192","67409.24"
    "aes-192-ecb","1024","24555.18"
    "aes-192-ecb","16","512.04"
    "aes-192-ecb","16384","80134.14"
    "aes-192-ecb","256","7553.28"
    "aes-192-ecb","64","2028.27"
    "aes-192-ecb","8192","67878.91"
    "aes-256-cbc","1024","23857.15"
    "aes-256-cbc","16","502.20"
    "aes-256-cbc","16384","70986.41"
    "aes-256-cbc","256","7413.42"
    "aes-256-cbc","64","1989.67"
    "aes-256-cbc","8192","61868.71"
    "aes-256-ecb","1024","24198.83"
    "aes-256-ecb","16","512.53"
    "aes-256-ecb","16384","72340.82"
    "aes-256-ecb","256","7553.02"
    "aes-256-ecb","64","2016.30"
    "aes-256-ecb","8192","63919.45"
    "sha256","1024","32903.17"
    "sha256","16","553.96"
    "sha256","16384","253635.24"
    "sha256","256","8617.90"
    "sha256","64","2182.81"
    "sha256","8192","174650.71"
    "sha512","1024","23121.24"
    "sha512","16","541.85"
    "sha512","16384","61183.32"
    "sha512","256","7675.22"
    "sha512","64","2167.55"
    "sha512","8192","55050.24"

.. csv-table:: OpenSSL CPU Load
    :header: "Algorithm","am62axx_sk-fs: CPU Load"

    "aes-128-cbc","33.00"
    "aes-128-ecb","34.00"
    "aes-192-cbc","33.00"
    "aes-192-ecb","33.00"
    "aes-256-cbc","32.00"
    "aes-256-ecb","33.00"
    "sha256","97.00"
    "sha512","97.00"

Listed for each algorithm are the code snippets used to run each
  benchmark test.

::

    time -v openssl speed -elapsed -evp aes-128-cbc

IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: IPSec Software Performance
    :header: "Algorithm","am62axx_sk-fs: Throughput (Mbps)","am62axx_sk-fs: Packets/Sec","am62axx_sk-fs: CPU Load"

    "aes128","345.80","30.00","74.23"
