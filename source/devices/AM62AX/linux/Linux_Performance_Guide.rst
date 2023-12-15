===========================
 Linux Performance Guide
===========================

.. rubric::  **Read This First**

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| AM62A SK       | AM62A Starter Kit                                                                                              |
+----------------+----------------------------------------------------------------------------------------------------------------+

Table:  Evaluation Modules

|

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
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "af_unix_sock_stream_latency (microsec)","28.62"
    "af_unix_socket_stream_bandwidth (MBs)","1020.58"
    "bw_file_rd-io-1mb (MB/s)","1199.25"
    "bw_file_rd-o2c-1mb (MB/s)","682.13"
    "bw_mem-bcopy-16mb (MB/s)","1719.69"
    "bw_mem-bcopy-1mb (MB/s)","1791.47"
    "bw_mem-bcopy-2mb (MB/s)","1635.06"
    "bw_mem-bcopy-4mb (MB/s)","1675.28"
    "bw_mem-bcopy-8mb (MB/s)","1688.12"
    "bw_mem-bzero-16mb (MB/s)","6933.41"
    "bw_mem-bzero-1mb (MB/s)","4383.43 (min 1791.47, max 6975.39)"
    "bw_mem-bzero-2mb (MB/s)","4308.54 (min 1635.06, max 6982.02)"
    "bw_mem-bzero-4mb (MB/s)","4312.88 (min 1675.28, max 6950.48)"
    "bw_mem-bzero-8mb (MB/s)","4326.56 (min 1688.12, max 6965.00)"
    "bw_mem-cp-16mb (MB/s)","863.56"
    "bw_mem-cp-1mb (MB/s)","1160.85 (min 866.10, max 1455.60)"
    "bw_mem-cp-2mb (MB/s)","1086.08 (min 845.90, max 1326.26)"
    "bw_mem-cp-4mb (MB/s)","1104.94 (min 886.03, max 1323.85)"
    "bw_mem-cp-8mb (MB/s)","1113.49 (min 903.34, max 1323.63)"
    "bw_mem-fcp-16mb (MB/s)","1616.16"
    "bw_mem-fcp-1mb (MB/s)","4297.34 (min 1619.29, max 6975.39)"
    "bw_mem-fcp-2mb (MB/s)","4238.28 (min 1494.54, max 6982.02)"
    "bw_mem-fcp-4mb (MB/s)","4271.00 (min 1591.51, max 6950.48)"
    "bw_mem-fcp-8mb (MB/s)","4302.93 (min 1640.86, max 6965.00)"
    "bw_mem-frd-16mb (MB/s)","1785.32"
    "bw_mem-frd-1mb (MB/s)","1696.33 (min 1619.29, max 1773.36)"
    "bw_mem-frd-2mb (MB/s)","1574.68 (min 1494.54, max 1654.81)"
    "bw_mem-frd-4mb (MB/s)","1656.10 (min 1591.51, max 1720.68)"
    "bw_mem-frd-8mb (MB/s)","1712.89 (min 1640.86, max 1784.92)"
    "bw_mem-fwr-16mb (MB/s)","1329.46"
    "bw_mem-fwr-1mb (MB/s)","1614.48 (min 1455.60, max 1773.36)"
    "bw_mem-fwr-2mb (MB/s)","1490.54 (min 1326.26, max 1654.81)"
    "bw_mem-fwr-4mb (MB/s)","1522.27 (min 1323.85, max 1720.68)"
    "bw_mem-fwr-8mb (MB/s)","1554.28 (min 1323.63, max 1784.92)"
    "bw_mem-rd-16mb (MB/s)","1830.24"
    "bw_mem-rd-1mb (MB/s)","1818.91 (min 1668.61, max 1969.21)"
    "bw_mem-rd-2mb (MB/s)","1683.40 (min 1544.64, max 1822.16)"
    "bw_mem-rd-4mb (MB/s)","1669.85 (min 1531.10, max 1808.59)"
    "bw_mem-rd-8mb (MB/s)","1663.26 (min 1506.88, max 1819.63)"
    "bw_mem-rdwr-16mb (MB/s)","1533.30"
    "bw_mem-rdwr-1mb (MB/s)","1238.21 (min 866.10, max 1610.31)"
    "bw_mem-rdwr-2mb (MB/s)","1153.41 (min 845.90, max 1460.92)"
    "bw_mem-rdwr-4mb (MB/s)","1171.88 (min 886.03, max 1457.73)"
    "bw_mem-rdwr-8mb (MB/s)","1214.45 (min 903.34, max 1525.55)"
    "bw_mem-wr-16mb (MB/s)","1518.46"
    "bw_mem-wr-1mb (MB/s)","1639.46 (min 1610.31, max 1668.61)"
    "bw_mem-wr-2mb (MB/s)","1502.78 (min 1460.92, max 1544.64)"
    "bw_mem-wr-4mb (MB/s)","1494.42 (min 1457.73, max 1531.10)"
    "bw_mem-wr-8mb (MB/s)","1516.22 (min 1506.88, max 1525.55)"
    "bw_mmap_rd-mo-1mb (MB/s)","1934.58"
    "bw_mmap_rd-o2c-1mb (MB/s)","633.91"
    "bw_pipe (MB/s)","614.18"
    "bw_unix (MB/s)","1020.58"
    "lat_connect (us)","59.20"
    "lat_ctx-2-128k (us)","5.60"
    "lat_ctx-2-256k (us)","5.14"
    "lat_ctx-4-128k (us)","5.79"
    "lat_ctx-4-256k (us)","6.12"
    "lat_fs-0k (num_files)","286.00"
    "lat_fs-10k (num_files)","119.00"
    "lat_fs-1k (num_files)","188.00"
    "lat_fs-4k (num_files)","187.00"
    "lat_mem_rd-stride128-sz1000k (ns)","33.56"
    "lat_mem_rd-stride128-sz125k (ns)","6.31"
    "lat_mem_rd-stride128-sz250k (ns)","6.63"
    "lat_mem_rd-stride128-sz31k (ns)","4.10"
    "lat_mem_rd-stride128-sz50 (ns)","2.41"
    "lat_mem_rd-stride128-sz500k (ns)","19.09"
    "lat_mem_rd-stride128-sz62k (ns)","5.94"
    "lat_mmap-1m (us)","55.00"
    "lat_ops-double-add (ns)","3.21"
    "lat_ops-double-div (ns)","17.68"
    "lat_ops-double-mul (ns)","3.22"
    "lat_ops-float-add (ns)","3.22"
    "lat_ops-float-div (ns)","10.47"
    "lat_ops-float-mul (ns)","3.21"
    "lat_ops-int-add (ns)","0.81"
    "lat_ops-int-bit (ns)","0.54"
    "lat_ops-int-div (ns)","4.83"
    "lat_ops-int-mod (ns)","5.09"
    "lat_ops-int-mul (ns)","3.45"
    "lat_ops-int64-add (ns)","0.80"
    "lat_ops-int64-bit (ns)","0.54"
    "lat_ops-int64-div (ns)","7.64"
    "lat_ops-int64-mod (ns)","5.90"
    "lat_ops-int64-mul (ns)","4.02"
    "lat_pagefault (us)","1.47"
    "lat_pipe (us)","22.55"
    "lat_proc-exec (us)","978.17"
    "lat_proc-fork (us)","757.57"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","36.85"
    "lat_sem (us)","3.49"
    "lat_sig-catch (us)","6.13"
    "lat_sig-install (us)","0.72"
    "lat_sig-prot (us)","0.63"
    "lat_syscall-fstat (us)","2.78"
    "lat_syscall-null (us)","0.52"
    "lat_syscall-open (us)","238.30"
    "lat_syscall-read (us)","0.84"
    "lat_syscall-stat (us)","3.85"
    "lat_syscall-write (us)","0.74"
    "lat_tcp (us)","1.03"
    "lat_unix (us)","28.62"
    "latency_for_0.50_mb_block_size (nanosec)","19.09"
    "latency_for_1.00_mb_block_size (nanosec)","16.78 (min 0.00, max 33.56)"
    "pipe_bandwidth (MBs)","614.18"
    "pipe_latency (microsec)","22.55"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","36.85"
    "semaphore_latency (microsec)","3.49"
    "signal_handler_latency (microsec)","0.72"
    "signal_handler_overhead (microsec)","6.13"
    "tcp_ip_connection_cost_to_localhost (microsec)","59.20"
    "tcp_latency_using_localhost (microsec)","1.03"

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
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "cpu_clock (MHz)","1250.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.90"
    "dhrystone_per_second (DhrystoneP)","6451613.00"

Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Whetstone is a benchmark primarily measuring floating-point arithmetic performance.

Execute the benchmark with the following:

::

    runWhetstone

.. csv-table::
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "whetstone (MIPS)","5000.00"


Table:  **Whetstone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "linpack (Kflops)","514666.00"

Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html

.. csv-table::
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "assignment (Iterations)","12.36"
    "fourier (Iterations)","20183.00"
    "fp_emulation (Iterations)","82.05"
    "huffman (Iterations)","1043.50"
    "idea (Iterations)","3074.10"
    "lu_decomposition (Iterations)","473.72"
    "neural_net (Iterations)","7.87"
    "numeric_sort (Iterations)","533.22"
    "string_sort (Iterations)","147.06"

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
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "add (MB/s)","2454.60"
    "copy (MB/s)","3517.40"
    "scale (MB/s)","3240.30"
    "triad (MB/s)","2241.60"

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

    "cjpeg-rose7-preset (workloads/)","36.76"
    "core (workloads/)","0.27"
    "coremark-pro ()","785.77"
    "linear_alg-mid-100x100-sp (workloads/)","13.04"
    "loops-all-mid-10k-sp (workloads/)","0.62"
    "nnet_test (workloads/)","0.97"
    "parser-125k (workloads/)","7.41"
    "radix2-big-64k (workloads/)","39.46"
    "sha-test (workloads/)","72.46"
    "zip-test (workloads/)","19.61"

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
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "4m-check (workloads/)","357.04"
    "4m-check-reassembly (workloads/)","111.36"
    "4m-check-reassembly-tcp (workloads/)","53.30"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","24.11"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.47"
    "4m-cmykw2 (workloads/)","156.99"
    "4m-cmykw2-rotatew2 (workloads/)","36.72"
    "4m-reassembly (workloads/)","81.23"
    "4m-rotatew2 (workloads/)","42.54"
    "4m-tcp-mixed (workloads/)","108.11"
    "4m-x264w2 (workloads/)","1.47"
    "idct-4m (workloads/)","17.14"
    "idct-4mw1 (workloads/)","17.10"
    "ippktcheck-4m (workloads/)","357.14"
    "ippktcheck-4mw1 (workloads/)","357.19"
    "ipres-4m (workloads/)","104.24"
    "ipres-4mw1 (workloads/)","103.45"
    "md5-4m (workloads/)","24.61"
    "md5-4mw1 (workloads/)","24.50"
    "rgbcmyk-4m (workloads/)","58.79"
    "rgbcmyk-4mw1 (workloads/)","58.89"
    "rotate-4ms1 (workloads/)","21.26"
    "rotate-4ms1w1 (workloads/)","21.57"
    "rotate-4ms64 (workloads/)","21.68"
    "rotate-4ms64w1 (workloads/)","21.71"
    "x264-4mq (workloads/)","0.51"
    "x264-4mqw1 (workloads/)","0.51"

Table:  **Multibench**

|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am62axx_sk-fs: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","27.48 (min 26.22, max 31.25)"

Table:  **Boot time MMC/SD**

|

ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64

.. csv-table::
    :header: "Sampling Rate (Hz)","am62axx_sk-fs: Throughput (bits/sec)","am62axx_sk-fs: CPU Load (%)"

    "8000","255998.00","25.14"
    "11025","352798.00","25.28"
    "16000","511997.00","26.23"
    "22050","705597.00","25.40"
    "24000","705592.00","25.39"
    "32000","1023983.00","25.26"
    "44100","1411180.00","25.60"
    "48000","1535981.00","25.97"
    "88200","2822366.00","25.95"
    "96000","3071963.00","25.60"

Table:  **Audio Capture**

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

- CPSW3g: AM64x, AM62x, AM62ax, AM62px


.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","am62axx_sk-fs: THROUGHPUT (Mbits/sec)","am62axx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1862.94","84.29"

Table: **CPSW TCP Bidirectional Throughput**

.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am62axx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62axx_sk-fs: THROUGHPUT (Mbits/sec)","am62axx_sk-fs: Packets Per Second (kPPS)","am62axx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","18.05","125.00","68.35"
    "128","82.00","79.39","121.00","67.67"
    "256","210.00","75.25","45.00","41.44"
    "1024","978.00","706.46","90.00","59.08"
    "1518","1472.00","955.30","81.00","62.02"

Table: **CPSW UDP Egress Throughput**

.. csv-table::
    :header: "Frame Size(bytes)","am62axx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62axx_sk-fs: THROUGHPUT (Mbits/sec)","am62axx_sk-fs: Packets Per Second (kPPS)","am62axx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.67","12.00","27.00"
    "128","82.00","13.38","20.00","31.92"
    "256","210.00","16.80","10.00","27.53"
    "1024","978.00","482.74","62.00","45.94"
    "1518","1472.00","493.41","42.00","46.77"

Table: **CPSW UDP Ingress Throughput (0% loss)**

.. csv-table::
    :header: "Frame Size(bytes)","am62axx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62axx_sk-fs: THROUGHPUT (Mbits/sec)","am62axx_sk-fs: Packets Per Second (kPPS)","am62axx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62axx_sk-fs: Packet Loss %"

    "64","18.00","26.75","186.00","64.09","56.00"
    "128","82.00","122.03","186.00","66.82","57.86"
    "256","210.00","307.61","183.00","66.37","57.08"
    "1024","978.00","936.35","120.00","67.50","0.04"
    "1518","1472.00","956.64","81.00","66.79","0.04"

Table: **CPSW UDP Ingress Throughput (possible loss)**

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

.. csv-table::
    :header: "Buffer size (bytes)","am62axx_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62axx_sk-fs: Write EXT4 CPU Load (%)","am62axx_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62axx_sk-fs: Read EXT4 CPU Load (%)"

    "1m","58.80","26.66","175.00","27.56"
    "4m","59.40","26.32","175.00","27.28"
    "4k","51.50","46.68","55.90","46.12"
    "256k","58.90","27.70","174.00","29.34"

|

UBoot EMMC Driver
-------------------------

AM62AXX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","am62axx_sk-fs: Write Throughput (Kbytes/sec)","am62axx_sk-fs: Read Throughput (Kbytes/sec)"

    "2000000","58514.29","170666.67"
    "4000000","60124.77","173835.54"

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

.. csv-table::
    :header: "Buffer size (bytes)","am62axx_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62axx_sk-fs: Write EXT4 CPU Load (%)","am62axx_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62axx_sk-fs: Read EXT4 CPU Load (%)"

    "1m","28.50","26.21","84.80","27.03"
    "4m","28.20","26.07","86.30","26.58"
    "4k","5.31","28.73","18.80","32.82"
    "256k","27.90","26.60","85.70","27.93"

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|

UBoot MMC/SD Driver
-------------------------

AM62AXX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","am62axx_sk-fs: Write Throughput (Kbytes/sec)","am62axx_sk-fs: Read Throughput (Kbytes/sec)"

    "400000","18962.96","20078.43"
    "800000","21167.96","21614.78"
    "1000000","19528.01","22413.13"

|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am62axx_sk-fs: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","24493.40"
    "aes-128-cbc","16","491.77"
    "aes-128-cbc","16384","85409.79"
    "aes-128-cbc","256","7348.05"
    "aes-128-cbc","64","1956.33"
    "aes-128-cbc","8192","72952.49"
    "aes-128-ecb","1024","25098.58"
    "aes-128-ecb","16","505.18"
    "aes-128-ecb","16384","87949.31"
    "aes-128-ecb","256","7592.11"
    "aes-128-ecb","64","2009.32"
    "aes-128-ecb","8192","75172.52"
    "aes-192-cbc","1024","23974.57"
    "aes-192-cbc","16","495.65"
    "aes-192-cbc","16384","77583.70"
    "aes-192-cbc","256","7340.03"
    "aes-192-cbc","64","1962.22"
    "aes-192-cbc","8192","66887.68"
    "aes-192-ecb","1024","24654.85"
    "aes-192-ecb","16","506.17"
    "aes-192-ecb","16384","79915.69"
    "aes-192-ecb","256","7461.72"
    "aes-192-ecb","64","2013.14"
    "aes-192-ecb","8192","69036.71"
    "aes-256-cbc","1024","23431.85"
    "aes-256-cbc","16","489.40"
    "aes-256-cbc","16384","70926.34"
    "aes-256-cbc","256","7307.61"
    "aes-256-cbc","64","1969.45"
    "aes-256-cbc","8192","61950.63"
    "aes-256-ecb","1024","24079.36"
    "aes-256-ecb","16","503.22"
    "aes-256-ecb","16384","72182.44"
    "aes-256-ecb","256","7440.73"
    "aes-256-ecb","64","2001.90"
    "aes-256-ecb","8192","63294.12"
    "sha256","1024","32196.61"
    "sha256","16","540.77"
    "sha256","16384","253640.70"
    "sha256","256","8438.53"
    "sha256","64","2135.04"
    "sha256","8192","173241.69"
    "sha512","1024","22995.63"
    "sha512","16","535.95"
    "sha512","16384","60861.10"
    "sha512","256","7622.23"
    "sha512","64","2144.87"
    "sha512","8192","54788.10"

.. csv-table::
    :header: "Algorithm","am62axx_sk-fs: CPU Load"

    "aes-128-cbc","33.00"
    "aes-128-ecb","34.00"
    "aes-192-cbc","33.00"
    "aes-192-ecb","33.00"
    "aes-256-cbc","32.00"
    "aes-256-ecb","33.00"
    "sha256","97.00"
    "sha512","97.00"

Listed for each algorithm are the code snippets used to run each benchmark test.

::

    time -v openssl speed -elapsed -evp aes-128-cbc

IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am62axx_sk-fs: Throughput (Mbps)","am62axx_sk-fs: Packets/Sec","am62axx_sk-fs: CPU Load"

    "3des","65.60","5.00","25.17"
    "aes128","362.80","32.00","75.52"
    "aes192","349.50","31.00","75.65"
    "aes256","0.00","0.00","76.38"
