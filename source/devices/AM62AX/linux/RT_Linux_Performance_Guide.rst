===========================
 RT-linux Performance Guide
===========================

.. rubric::  **Read This First**

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| AM62A SK       | AM62A Starter Kit rev E2 with ARM running at 1200MHz, LPDDR4 data rate 1866 MT/S                               |
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
    :header: "Benchmarks","am62axx_sk-fs: perf"
    "af_unix_sock_stream_latency (microsec)","39.51"
    "af_unix_socket_stream_bandwidth (MBs)","1610.93"
    "bw_file_rd-io-1mb (MB/s)","1168.81"
    "bw_file_rd-o2c-1mb (MB/s)","140.49"
    "bw_mem-bcopy-16mb (MB/s)","1830.66"
    "bw_mem-bcopy-1mb (MB/s)","2046.89"
    "bw_mem-bcopy-2mb (MB/s)","1848.43"
    "bw_mem-bcopy-4mb (MB/s)","1814.06"
    "bw_mem-bcopy-8mb (MB/s)","1830.04"
    "bw_mem-bzero-16mb (MB/s)","7392.58"
    "bw_mem-bzero-1mb (MB/s)","4721.81 (min 2046.89, max 7396.72)"
    "bw_mem-bzero-2mb (MB/s)","4619.45 (min 1848.43, max 7390.46)"
    "bw_mem-bzero-4mb (MB/s)","4595.21 (min 1814.06, max 7376.36)"
    "bw_mem-bzero-8mb (MB/s)","4609.60 (min 1830.04, max 7389.16)"
    "bw_mem-cp-16mb (MB/s)","938.47"
    "bw_mem-cp-1mb (MB/s)","4281.81 (min 931.45, max 7632.17)"
    "bw_mem-cp-2mb (MB/s)","4214.92 (min 933.85, max 7495.98)"
    "bw_mem-cp-4mb (MB/s)","4184.49 (min 913.24, max 7455.73)"
    "bw_mem-cp-8mb (MB/s)","4207.62 (min 989.49, max 7425.74)"
    "bw_mem-fcp-16mb (MB/s)","1581.81"
    "bw_mem-fcp-1mb (MB/s)","4664.92 (min 1933.11, max 7396.72)"
    "bw_mem-fcp-2mb (MB/s)","4555.23 (min 1719.99, max 7390.46)"
    "bw_mem-fcp-4mb (MB/s)","4561.67 (min 1746.98, max 7376.36)"
    "bw_mem-fcp-8mb (MB/s)","4565.95 (min 1742.73, max 7389.16)"
    "bw_mem-frd-16mb (MB/s)","1865.67"
    "bw_mem-frd-1mb (MB/s)","1900.99 (min 1868.87, max 1933.11)"
    "bw_mem-frd-2mb (MB/s)","1755.25 (min 1719.99, max 1790.51)"
    "bw_mem-frd-4mb (MB/s)","1738.17 (min 1729.36, max 1746.98)"
    "bw_mem-frd-8mb (MB/s)","1705.40 (min 1668.06, max 1742.73)"
    "bw_mem-fwr-16mb (MB/s)","7413.13"
    "bw_mem-fwr-1mb (MB/s)","4750.52 (min 1868.87, max 7632.17)"
    "bw_mem-fwr-2mb (MB/s)","4643.25 (min 1790.51, max 7495.98)"
    "bw_mem-fwr-4mb (MB/s)","4592.55 (min 1729.36, max 7455.73)"
    "bw_mem-fwr-8mb (MB/s)","4546.90 (min 1668.06, max 7425.74)"
    "bw_mem-rd-16mb (MB/s)","1932.60"
    "bw_mem-rd-1mb (MB/s)","2088.41 (min 1971.33, max 2205.48)"
    "bw_mem-rd-2mb (MB/s)","1838.65 (min 1719.39, max 1957.91)"
    "bw_mem-rd-4mb (MB/s)","1844.61 (min 1739.89, max 1949.32)"
    "bw_mem-rd-8mb (MB/s)","1848.61 (min 1761.34, max 1935.87)"
    "bw_mem-rdwr-16mb (MB/s)","1796.54"
    "bw_mem-rdwr-1mb (MB/s)","1393.51 (min 931.45, max 1855.57)"
    "bw_mem-rdwr-2mb (MB/s)","1272.73 (min 933.85, max 1611.60)"
    "bw_mem-rdwr-4mb (MB/s)","1301.10 (min 913.24, max 1688.95)"
    "bw_mem-rdwr-8mb (MB/s)","1358.31 (min 989.49, max 1727.12)"
    "bw_mem-wr-16mb (MB/s)","1786.11"
    "bw_mem-wr-1mb (MB/s)","1913.45 (min 1855.57, max 1971.33)"
    "bw_mem-wr-2mb (MB/s)","1665.50 (min 1611.60, max 1719.39)"
    "bw_mem-wr-4mb (MB/s)","1714.42 (min 1688.95, max 1739.89)"
    "bw_mem-wr-8mb (MB/s)","1744.23 (min 1727.12, max 1761.34)"
    "bw_mmap_rd-mo-1mb (MB/s)","2204.26"
    "bw_mmap_rd-o2c-1mb (MB/s)","603.68"
    "bw_pipe (MB/s)","479.04"
    "bw_unix (MB/s)","1610.93"
    "lat_connect (us)","95.80"
    "lat_ctx-2-128k (us)","5.17"
    "lat_ctx-2-256k (us)","4.64"
    "lat_ctx-4-128k (us)","4.43"
    "lat_ctx-4-256k (us)","0.09"
    "lat_fs-0k (num_files)","249.00"
    "lat_fs-10k (num_files)","117.00"
    "lat_fs-1k (num_files)","145.00"
    "lat_fs-4k (num_files)","158.00"
    "lat_mem_rd-stride128-sz1000k (ns)","30.68"
    "lat_mem_rd-stride128-sz125k (ns)","6.25"
    "lat_mem_rd-stride128-sz250k (ns)","6.53"
    "lat_mem_rd-stride128-sz31k (ns)","2.43"
    "lat_mem_rd-stride128-sz50 (ns)","2.40"
    "lat_mem_rd-stride128-sz500k (ns)","12.16"
    "lat_mem_rd-stride128-sz62k (ns)","5.89"
    "lat_mmap-1m (us)","61.00"
    "lat_ops-double-add (ns)","0.58"
    "lat_ops-double-mul (ns)","3.21"
    "lat_ops-float-add (ns)","0.58"
    "lat_ops-float-mul (ns)","3.21"
    "lat_ops-int-add (ns)","0.80"
    "lat_ops-int-bit (ns)","0.53"
    "lat_ops-int-div (ns)","4.84"
    "lat_ops-int-mod (ns)","5.08"
    "lat_ops-int-mul (ns)","2.43"
    "lat_ops-int64-add (ns)","0.80"
    "lat_ops-int64-bit (ns)","0.53"
    "lat_ops-int64-div (ns)","7.65"
    "lat_ops-int64-mod (ns)","5.88"
    "lat_pagefault (us)","1.32"
    "lat_pipe (us)","21.62"
    "lat_proc-exec (us)","1140.40"
    "lat_proc-fork (us)","941.83"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","35.52"
    "lat_sem (us)","2.89"
    "lat_sig-catch (us)","6.48"
    "lat_sig-install (us)","0.77"
    "lat_sig-prot (us)","0.55"
    "lat_syscall-fstat (us)","1.72"
    "lat_syscall-null (us)","0.43"
    "lat_syscall-open (us)","6170.00"
    "lat_syscall-read (us)","0.74"
    "lat_syscall-stat (us)","4.59"
    "lat_syscall-write (us)","0.65"
    "lat_tcp (us)","0.92"
    "lat_unix (us)","39.51"
    "latency_for_0.50_mb_block_size (nanosec)","12.16"
    "latency_for_1.00_mb_block_size (nanosec)","15.34 (min 0.00, max 30.68)"
    "pipe_bandwidth (MBs)","479.04"
    "pipe_latency (microsec)","21.62"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","35.52"
    "semaphore_latency (microsec)","2.89"
    "signal_handler_latency (microsec)","0.77"
    "signal_handler_overhead (microsec)","6.48"
    "tcp_ip_connection_cost_to_localhost (microsec)","95.80"
    "tcp_latency_using_localhost (microsec)","0.92"


Table:  **LM Bench Metrics**



Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

.. csv-table::
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "cpu_clock (MHz)","1250.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.90"
    "dhrystone_per_second (DhrystoneP)","6451613.00"


Table:  **Dhrystone Benchmark**



Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

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

    "linpack (Kflops)","518826.00"


Table:  **Linpack Benchmark**


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
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "add (MB/s)","2506.20"
    "copy (MB/s)","3755.90"
    "scale (MB/s)","3313.10"
    "triad (MB/s)","2283.10"


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
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "4m-check (workloads/)","474.65"
    "4m-check-reassembly (workloads/)","113.38"
    "4m-check-reassembly-tcp (workloads/)","56.05"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","31.93"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.73"
    "4m-cmykw2 (workloads/)","216.22"
    "4m-cmykw2-rotatew2 (workloads/)","43.73"
    "4m-reassembly (workloads/)","71.94"
    "4m-rotatew2 (workloads/)","48.78"
    "4m-tcp-mixed (workloads/)","112.68"
    "4m-x264w2 (workloads/)","1.73"
    "idct-4m (workloads/)","17.21"
    "idct-4mw1 (workloads/)","17.21"
    "ippktcheck-4m (workloads/)","472.50"
    "ippktcheck-4mw1 (workloads/)","473.22"
    "ipres-4m (workloads/)","102.81"
    "ipres-4mw1 (workloads/)","102.46"
    "md5-4m (workloads/)","26.12"
    "md5-4mw1 (workloads/)","26.10"
    "rgbcmyk-4m (workloads/)","58.81"
    "rgbcmyk-4mw1 (workloads/)","58.70"
    "rotate-4ms1 (workloads/)","22.15"
    "rotate-4ms1w1 (workloads/)","21.96"
    "rotate-4ms64 (workloads/)","22.35"
    "rotate-4ms64w1 (workloads/)","22.17"
    "x264-4mq (workloads/)","0.52"
    "x264-4mqw1 (workloads/)","0.52"


Table:  **Multibench**

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
 

 
CRYPTO Driver
-------------------------


OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am62axx_sk-fs: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","21167.79"
    "aes-128-cbc","16","411.44"
    "aes-128-cbc","16384","83367.25"
    "aes-128-cbc","256","6201.94"
    "aes-128-cbc","64","1621.76"
    "aes-128-cbc","8192","69033.98"
    "aes-192-cbc","1024","20931.58"
    "aes-192-cbc","16","414.10"
    "aes-192-cbc","16384","75688.62"
    "aes-192-cbc","256","6210.73"
    "aes-192-cbc","64","1634.03"
    "aes-192-cbc","8192","63892.14"
    "aes-256-cbc","1024","20416.51"
    "aes-256-cbc","16","412.90"
    "aes-256-cbc","16384","69277.01"
    "aes-256-cbc","256","6145.88"
    "aes-256-cbc","64","1610.69"
    "aes-256-cbc","8192","59189.93"
    "des-cbc","1024","23051.95"
    "des-cbc","16","4122.59"
    "des-cbc","16384","24663.38"
    "des-cbc","256","18923.78"
    "des-cbc","64","11011.56"
    "des-cbc","8192","24545.96"
    "des3","1024","9750.87"
    "des3","16","3229.89"
    "des3","16384","10032.47"
    "des3","256","8893.61"
    "des3","64","6573.42"
    "des3","8192","10005.16"
    "md5","1024","41871.02"
    "md5","16","886.54"
    "md5","16384","133802.67"
    "md5","256","12976.64"
    "md5","64","3446.57"
    "md5","8192","116471.13"
    "sha1","1024","49449.30"
    "sha1","16","846.15"
    "sha1","16384","304911.70"
    "sha1","256","13363.88"
    "sha1","64","3425.77"
    "sha1","8192","225503.91"
    "sha224","1024","49502.89"
    "sha224","16","848.51"
    "sha224","16384","311083.01"
    "sha224","256","13263.36"
    "sha224","64","3375.25"
    "sha224","8192","228018.86"
    "sha256","1024","29983.40"
    "sha256","16","496.45"
    "sha256","16384","248146.60"
    "sha256","256","7828.39"
    "sha256","64","1979.52"
    "sha256","8192","166207.49"
    "sha384","1024","30427.82"
    "sha384","16","831.21"
    "sha384","16384","65465.00"
    "sha384","256","11166.89"
    "sha384","64","3314.47"
    "sha384","8192","60708.18"
    "sha512","1024","21775.70"
    "sha512","16","489.23"
    "sha512","16384","62133.59"
    "sha512","256","7042.13"
    "sha512","64","1959.25"
    "sha512","8192","55184.04"


|



.. csv-table::
    :header: "Algorithm","am62axx_sk-fs: CPU Load"

    "aes-128-cbc","37.00"
    "aes-192-cbc","36.00"
    "aes-256-cbc","35.00"
    "des-cbc","97.00"
    "des3","97.00"
    "md5","98.00"
    "sha1","98.00"
    "sha224","98.00"
    "sha256","98.00"
    "sha384","88.00"
    "sha512","98.00"

 

|

Listed for each algorithm are the code snippets used to run each benchmark test.

|

::

    time -v openssl speed -elapsed -evp aes-128-cbc

 




IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am62axx_sk-fs: Throughput (Mbps)","am62axx_sk-fs: Packets/Sec","am62axx_sk-fs: CPU Load"

    "3des","63.80","5.00","24.89"
    "aes128","60.90","5.00","18.42"
    "aes192","56.00","5.00","17.21"
    "aes256","0.00","0.00","8.57"
