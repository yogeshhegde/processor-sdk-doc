***********************
Linux Performance Guide
***********************


.. rubric::  **Read This First**

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+-------------------------------------------------------------------------------------------+
| Name           | Description                                                                               |
+================+===========================================================================================+
| AM62Px SK      | AM62Px Evaluation Module rev E1 with ARM running at 1.4GHz, DDR data rate 3200MT/s        |
+----------------+-------------------------------------------------------------------------------------------+

Table:  Evaluation Modules

.. rubric::  About This Manual

This document provides performance data for each of the device drivers
which are part of the Process SDK Linux package. This document should be
used in conjunction with release notes and user guides provided with the
Process SDK Linux package for information on specific issues present
with drivers included in a particular release.

.. rubric::  If You Need Assistance

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

    "af_unix_sock_stream_latency (microsec)","23.62"
    "af_unix_socket_stream_bandwidth (MBs)","1127.14"
    "bw_file_rd-io-1mb (MB/s)","1266.28"
    "bw_file_rd-o2c-1mb (MB/s)","767.02"
    "bw_mem-bcopy-16mb (MB/s)","1805.26"
    "bw_mem-bcopy-1mb (MB/s)","1959.04"
    "bw_mem-bcopy-2mb (MB/s)","1744.59"
    "bw_mem-bcopy-4mb (MB/s)","1779.62"
    "bw_mem-bcopy-8mb (MB/s)","1787.31"
    "bw_mem-bzero-16mb (MB/s)","7770.76"
    "bw_mem-bzero-1mb (MB/s)","4874.90 (min 1959.04, max 7790.76)"
    "bw_mem-bzero-2mb (MB/s)","4757.16 (min 1744.59, max 7769.73)"
    "bw_mem-bzero-4mb (MB/s)","4782.93 (min 1779.62, max 7786.23)"
    "bw_mem-bzero-8mb (MB/s)","4784.08 (min 1787.31, max 7780.84)"
    "bw_mem-cp-16mb (MB/s)","885.20"
    "bw_mem-cp-1mb (MB/s)","1201.26 (min 867.60, max 1534.92)"
    "bw_mem-cp-2mb (MB/s)","1122.32 (min 902.80, max 1341.83)"
    "bw_mem-cp-4mb (MB/s)","1146.19 (min 905.90, max 1386.48)"
    "bw_mem-cp-8mb (MB/s)","1213.68 (min 931.75, max 1495.61)"
    "bw_mem-fcp-16mb (MB/s)","1685.45"
    "bw_mem-fcp-1mb (MB/s)","4723.04 (min 1655.32, max 7790.76)"
    "bw_mem-fcp-2mb (MB/s)","4677.51 (min 1585.29, max 7769.73)"
    "bw_mem-fcp-4mb (MB/s)","4723.91 (min 1661.59, max 7786.23)"
    "bw_mem-fcp-8mb (MB/s)","4722.72 (min 1664.59, max 7780.84)"
    "bw_mem-frd-16mb (MB/s)","1815.91"
    "bw_mem-frd-1mb (MB/s)","1792.41 (min 1655.32, max 1929.49)"
    "bw_mem-frd-2mb (MB/s)","1682.33 (min 1585.29, max 1779.36)"
    "bw_mem-frd-4mb (MB/s)","1731.70 (min 1661.59, max 1801.80)"
    "bw_mem-frd-8mb (MB/s)","1737.79 (min 1664.59, max 1810.98)"
    "bw_mem-fwr-16mb (MB/s)","1583.69"
    "bw_mem-fwr-1mb (MB/s)","1732.21 (min 1534.92, max 1929.49)"
    "bw_mem-fwr-2mb (MB/s)","1560.60 (min 1341.83, max 1779.36)"
    "bw_mem-fwr-4mb (MB/s)","1594.14 (min 1386.48, max 1801.80)"
    "bw_mem-fwr-8mb (MB/s)","1653.30 (min 1495.61, max 1810.98)"
    "bw_mem-rd-16mb (MB/s)","1895.29"
    "bw_mem-rd-1mb (MB/s)","1925.26 (min 1738.79, max 2111.73)"
    "bw_mem-rd-2mb (MB/s)","1741.56 (min 1621.27, max 1861.85)"
    "bw_mem-rd-4mb (MB/s)","1799.96 (min 1708.67, max 1891.25)"
    "bw_mem-rd-8mb (MB/s)","1828.23 (min 1765.42, max 1891.03)"
    "bw_mem-rdwr-16mb (MB/s)","1817.98"
    "bw_mem-rdwr-1mb (MB/s)","1303.97 (min 867.60, max 1740.34)"
    "bw_mem-rdwr-2mb (MB/s)","1202.94 (min 902.80, max 1503.08)"
    "bw_mem-rdwr-4mb (MB/s)","1284.03 (min 905.90, max 1662.16)"
    "bw_mem-rdwr-8mb (MB/s)","1343.07 (min 931.75, max 1754.39)"
    "bw_mem-wr-16mb (MB/s)","1817.77"
    "bw_mem-wr-1mb (MB/s)","1739.57 (min 1738.79, max 1740.34)"
    "bw_mem-wr-2mb (MB/s)","1562.18 (min 1503.08, max 1621.27)"
    "bw_mem-wr-4mb (MB/s)","1685.42 (min 1662.16, max 1708.67)"
    "bw_mem-wr-8mb (MB/s)","1759.91 (min 1754.39, max 1765.42)"
    "bw_mmap_rd-mo-1mb (MB/s)","2053.00"
    "bw_mmap_rd-o2c-1mb (MB/s)","704.85"
    "bw_pipe (MB/s)","710.33"
    "bw_unix (MB/s)","1127.14"
    "lat_connect (us)","52.89"
    "lat_ctx-2-128k (us)","4.79"
    "lat_ctx-2-256k (us)","5.25"
    "lat_ctx-4-128k (us)","4.50"
    "lat_ctx-4-256k (us)","2.95"
    "lat_fs-0k (num_files)","305.00"
    "lat_fs-10k (num_files)","115.00"
    "lat_fs-1k (num_files)","176.00"
    "lat_fs-4k (num_files)","198.00"
    "lat_mem_rd-stride128-sz1000k (ns)","31.81"
    "lat_mem_rd-stride128-sz125k (ns)","5.57"
    "lat_mem_rd-stride128-sz250k (ns)","5.83"
    "lat_mem_rd-stride128-sz31k (ns)","2.16"
    "lat_mem_rd-stride128-sz50 (ns)","2.15"
    "lat_mem_rd-stride128-sz500k (ns)","12.35"
    "lat_mem_rd-stride128-sz62k (ns)","5.28"
    "lat_mmap-1m (us)","55.00"
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
    "lat_ops-int64-mod (ns)","5.24"
    "lat_ops-int64-mul (ns)","3.56"
    "lat_pagefault (us)","1.30"
    "lat_pipe (us)","19.91"
    "lat_proc-exec (us)","743.86"
    "lat_proc-fork (us)","582.60"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","32.67"
    "lat_sem (us)","1.57"
    "lat_sig-catch (us)","5.44"
    "lat_sig-install (us)","0.65"
    "lat_sig-prot (us)","0.56"
    "lat_syscall-fstat (us)","2.42"
    "lat_syscall-null (us)","0.46"
    "lat_syscall-open (us)","158.71"
    "lat_syscall-read (us)","0.74"
    "lat_syscall-stat (us)","3.41"
    "lat_syscall-write (us)","0.65"
    "lat_tcp (us)","0.91"
    "lat_unix (us)","23.62"
    "latency_for_0.50_mb_block_size (nanosec)","12.35"
    "latency_for_1.00_mb_block_size (nanosec)","15.90 (min 0.00, max 31.81)"
    "pipe_bandwidth (MBs)","710.33"
    "pipe_latency (microsec)","19.91"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","32.67"
    "semaphore_latency (microsec)","1.57"
    "signal_handler_latency (microsec)","0.65"
    "signal_handler_overhead (microsec)","5.44"
    "tcp_ip_connection_cost_to_localhost (microsec)","52.89"
    "tcp_latency_using_localhost (microsec)","0.91"

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
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "cpu_clock (MHz)","1400.00"
    "dhrystone_per_mhz (DMIPS/MHz)","3.00"
    "dhrystone_per_second (DhrystoneP)","7407407.50"

Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Whetstone is a benchmark primarily measuring floating-point arithmetic performance.

Execute the benchmark with the following:

::

    runWhetstone

.. csv-table::
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "whetstone (MIPS)","5000.00"

Table:  **Whetstone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "linpack (Kflops)","578928.00"

Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html

.. csv-table::
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "assignment (Iterations)","13.93"
    "fourier (Iterations)","22638.00"
    "fp_emulation (Iterations)","92.30"
    "huffman (Iterations)","1169.30"
    "idea (Iterations)","3444.90"
    "lu_decomposition (Iterations)","538.17"
    "neural_net (Iterations)","8.82"
    "numeric_sort (Iterations)","598.37"
    "string_sort (Iterations)","164.96"

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
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "add (MB/s)","2533.40"
    "copy (MB/s)","3668.10"
    "scale (MB/s)","3375.50"
    "triad (MB/s)","2330.40"


Table:  **Stream**

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
    "coremark-pro ()","942.75"
    "linear_alg-mid-100x100-sp (workloads/)","14.69"
    "loops-all-mid-10k-sp (workloads/)","0.71"
    "nnet_test (workloads/)","1.09"
    "parser-125k (workloads/)","8.77"
    "radix2-big-64k (workloads/)","75.31"
    "sha-test (workloads/)","81.30"
    "zip-test (workloads/)","21.74"


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
    :header: "Benchmarks","am62pxx_sk-fs: perf"

    "4m-check (workloads/)","411.25"
    "4m-check-reassembly (workloads/)","122.70"
    "4m-check-reassembly-tcp (workloads/)","59.95"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","32.88"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.96"
    "4m-cmykw2 (workloads/)","244.80"
    "4m-cmykw2-rotatew2 (workloads/)","49.79"
    "4m-reassembly (workloads/)","87.26"
    "4m-rotatew2 (workloads/)","53.28"
    "4m-tcp-mixed (workloads/)","119.40"
    "4m-x264w2 (workloads/)","1.99"
    "idct-4m (workloads/)","19.20"
    "idct-4mw1 (workloads/)","19.21"
    "ippktcheck-4m (workloads/)","408.90"
    "ippktcheck-4mw1 (workloads/)","409.50"
    "ipres-4m (workloads/)","109.97"
    "ipres-4mw1 (workloads/)","108.62"
    "md5-4m (workloads/)","28.82"
    "md5-4mw1 (workloads/)","29.20"
    "rgbcmyk-4m (workloads/)","65.85"
    "rgbcmyk-4mw1 (workloads/)","65.90"
    "rotate-4ms1 (workloads/)","23.39"
    "rotate-4ms1w1 (workloads/)","23.36"
    "rotate-4ms64 (workloads/)","23.56"
    "rotate-4ms64w1 (workloads/)","23.58"
    "x264-4mq (workloads/)","0.58"
    "x264-4mqw1 (workloads/)","0.58"

Table:  **Multibench**

|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am62pxx_sk-fs: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","27.62 (min 23.09, max 33.56)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","7.01 (min 6.96, max 7.21)"

Table:  **Boot time MMC/SD**

|

Graphics SGX/RGX Driver
-------------------------

Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am62pxx_sk-fs: Score"

    "Glmark2-DRM","57.00"
    "Glmark2-Wayland","860.00"

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

CPSW/CPSW2g/CPSW3g Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- CPSW3g: AM64x, AM62x, AM62ax, AM62px

.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","am62pxx_sk-fs: THROUGHPUT (Mbits/sec)","am62pxx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1854.95","61.02"

Table: **CPSW TCP Bidirectional Throughput**

.. rubric::  TCP Bidirectional Throughput Interrupt Pacing
   :name: CPSW2g-tcp-bidirectional-throughput-interrupt-pacing

.. csv-table::
    :header: "Command Used","am62pxx_sk-fs: THROUGHPUT (Mbits/sec)","am62pxx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1714.22","40.62"

Table: **CPSW TCP Bidirectional Throughput Interrupt Pacing**

|

OSPI Flash Driver
-------------------------

AM62PXX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

UBIFS
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Buffer size (bytes)","am62pxx_sk-fs: Write UBIFS Throughput (Mbytes/sec)","am62pxx_sk-fs: Write UBIFS CPU Load (%)","am62pxx_sk-fs: Read UBIFS Throughput (Mbytes/sec)","am62pxx_sk-fs: Read UBIFS CPU Load (%)"

    "102400","0.18 (min 0.13, max 0.28)","12.59 (min 12.42, max 12.78)","29.18","7.14"
    "262144","0.14 (min 0.11, max 0.18)","12.72 (min 11.06, max 14.17)","29.07","3.57"
    "524288","0.14 (min 0.11, max 0.18)","12.32 (min 11.51, max 13.28)","28.81","6.90"
    "1048576","0.14 (min 0.11, max 0.19)","12.37 (min 10.79, max 13.74)","28.56","10.00"

RAW
"""""""""""""""""""""""""""

.. csv-table::
    :header: "File size (Mbytes)","am62pxx_sk-fs: Raw Read Throughput (Mbytes/sec)"

    "50","37.88"

|

UBoot QSPI/OSPI Driver
-------------------------

AM62PXX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","am62pxx_sk-fs: Write Throughput (Kbytes/sec)","am62pxx_sk-fs: Read Throughput (Kbytes/sec)"

    "400000","386.27","37577.98"
    "800000","387.40","39009.52"
    "1000000","389.39","39574.88"
    "2000000","383.01","40009.77"

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

    "1m","90.10","1.33","285.00","2.16"
    "4m","96.00","1.05","285.00","2.18"
    "4k","79.30","27.44","92.90","25.35"
    "256k","90.30","1.72","285.00","3.11"

|

UBoot EMMC Driver
-------------------------

AM62PXX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","am62pxx_sk-fs: Write Throughput (Kbytes/sec)","am62pxx_sk-fs: Read Throughput (Kbytes/sec)"

    "2000000","98698.80","230760.56"
    "4000000","96518.41","278876.60"

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

    "1m","12.70","0.42","91.40","1.01"
    "4m","15.10","0.42","91.50","0.91"
    "4k","5.19","2.36","17.10","5.02"
    "256k","12.70","0.50","91.90","1.21"

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|

USB Driver
-------------------------

USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Number of Blocks","am62pxx_sk-fs: Throughput (MB/sec)"

    "150","44.00"

Table: **USBDEVICE HIGHSPEED SLAVE READ THROUGHPUT**

.. csv-table::
    :header: "Number of Blocks","am62pxx_sk-fs: Throughput (MB/sec)"

    "150","38.00"

Table: **USBDEVICE HIGHSPEED SLAVE WRITE THROUGHPUT**

|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am62pxx_sk-fs: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","26695.34"
    "aes-128-cbc","16","546.44"
    "aes-128-cbc","16384","88451.75"
    "aes-128-cbc","256","8090.11"
    "aes-128-cbc","64","2170.79"
    "aes-128-cbc","8192","76103.68"
    "aes-128-ecb","1024","27254.10"
    "aes-128-ecb","16","559.87"
    "aes-128-ecb","16384","91329.88"
    "aes-128-ecb","256","8285.61"
    "aes-128-ecb","64","2216.41"
    "aes-128-ecb","8192","78525.78"
    "aes-192-cbc","1024","25874.43"
    "aes-192-cbc","16","547.50"
    "aes-192-cbc","16384","79724.54"
    "aes-192-cbc","256","7955.80"
    "aes-192-cbc","64","2152.45"
    "aes-192-cbc","8192","69279.74"
    "aes-192-ecb","1024","26567.00"
    "aes-192-ecb","16","562.49"
    "aes-192-ecb","16384","81597.78"
    "aes-192-ecb","256","8201.05"
    "aes-192-ecb","64","2231.96"
    "aes-192-ecb","8192","70216.36"
    "aes-256-cbc","1024","25366.53"
    "aes-256-cbc","16","549.43"
    "aes-256-cbc","16384","72750.42"
    "aes-256-cbc","256","7966.04"
    "aes-256-cbc","64","2162.73"
    "aes-256-cbc","8192","64252.59"
    "aes-256-ecb","1024","25857.37"
    "aes-256-ecb","16","558.03"
    "aes-256-ecb","16384","74678.27"
    "aes-256-ecb","256","8092.33"
    "aes-256-ecb","64","2202.47"
    "aes-256-ecb","8192","65784.49"
    "sha256","1024","36742.14"
    "sha256","16","619.73"
    "sha256","16384","289609.05"
    "sha256","256","9681.32"
    "sha256","64","2450.20"
    "sha256","8192","197640.19"
    "sha512","1024","25773.74"
    "sha512","16","600.54"
    "sha512","16384","68965.72"
    "sha512","256","8536.58"
    "sha512","64","2398.78"
    "sha512","8192","61936.98"

.. csv-table::
    :header: "Algorithm","am62pxx_sk-fs: CPU Load"

    "aes-128-cbc","32.00"
    "aes-128-ecb","34.00"
    "aes-192-cbc","32.00"
    "aes-192-ecb","33.00"
    "aes-256-cbc","32.00"
    "aes-256-ecb","33.00"
    "sha256","98.00"
    "sha512","98.00"

Listed for each algorithm are the code snippets used to run each benchmark test.

::

    time -v openssl speed -elapsed -evp aes-128-cbc
