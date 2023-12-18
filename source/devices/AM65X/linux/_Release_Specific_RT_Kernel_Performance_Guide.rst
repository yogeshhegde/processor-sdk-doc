..  http://lcpdresults.itg.ti.com/LCPD/RT-linux/performance/publish/data/09.01.00/am654x-evm/rst/

======================================
 RT-linux 09.01.00 Performance Guide
======================================

.. rubric::  **Read This First**
   :name: read-this-first-rt-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+---------------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                         |
+================+=====================================================================================================================+
| AM65x EVM      | AM65x Evaluation Module rev 2.0 with ARM running at 800MHz, DDR4-2400 (1600 MT/S), TMDX654IDKEVM                    |
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

Execute the LMBench with the following:

::

    cd /opt/ltp
    ./runltp -P j721e-idk-gw -f ddt/lmbench -s LMBENCH_L_PERF_0001

.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "af_unix_sock_stream_latency (microsec)","68.44"
    "af_unix_socket_stream_bandwidth (MBs)","986.93"
    "bw_file_rd-io-1mb (MB/s)","1091.70"
    "bw_file_rd-o2c-1mb (MB/s)","638.37"
    "bw_mem-bcopy-16mb (MB/s)","905.54"
    "bw_mem-bcopy-1mb (MB/s)","1233.92"
    "bw_mem-bcopy-2mb (MB/s)","970.72"
    "bw_mem-bcopy-4mb (MB/s)","910.75"
    "bw_mem-bcopy-8mb (MB/s)","904.47"
    "bw_mem-bzero-16mb (MB/s)","2021.48"
    "bw_mem-bzero-1mb (MB/s)","2847.91 (min 1233.92, max 4461.90)"
    "bw_mem-bzero-2mb (MB/s)","2222.14 (min 970.72, max 3473.56)"
    "bw_mem-bzero-4mb (MB/s)","1608.12 (min 910.75, max 2305.48)"
    "bw_mem-bzero-8mb (MB/s)","1475.26 (min 904.47, max 2046.04)"
    "bw_mem-cp-16mb (MB/s)","582.98"
    "bw_mem-cp-1mb (MB/s)","1402.49 (min 775.34, max 2029.63)"
    "bw_mem-cp-2mb (MB/s)","849.54 (min 616.05, max 1083.03)"
    "bw_mem-cp-4mb (MB/s)","717.69 (min 587.46, max 847.91)"
    "bw_mem-cp-8mb (MB/s)","694.50 (min 593.60, max 795.39)"
    "bw_mem-fcp-16mb (MB/s)","892.26"
    "bw_mem-fcp-1mb (MB/s)","2806.55 (min 1151.19, max 4461.90)"
    "bw_mem-fcp-2mb (MB/s)","2219.80 (min 966.03, max 3473.56)"
    "bw_mem-fcp-4mb (MB/s)","1599.92 (min 894.35, max 2305.48)"
    "bw_mem-fcp-8mb (MB/s)","1477.26 (min 908.47, max 2046.04)"
    "bw_mem-frd-16mb (MB/s)","1168.65"
    "bw_mem-frd-1mb (MB/s)","1360.53 (min 1151.19, max 1569.86)"
    "bw_mem-frd-2mb (MB/s)","1175.78 (min 966.03, max 1385.52)"
    "bw_mem-frd-4mb (MB/s)","1058.05 (min 894.35, max 1221.75)"
    "bw_mem-frd-8mb (MB/s)","1057.46 (min 908.47, max 1206.45)"
    "bw_mem-fwr-16mb (MB/s)","791.88"
    "bw_mem-fwr-1mb (MB/s)","1799.75 (min 1569.86, max 2029.63)"
    "bw_mem-fwr-2mb (MB/s)","1234.28 (min 1083.03, max 1385.52)"
    "bw_mem-fwr-4mb (MB/s)","1034.83 (min 847.91, max 1221.75)"
    "bw_mem-fwr-8mb (MB/s)","1000.92 (min 795.39, max 1206.45)"
    "bw_mem-rd-16mb (MB/s)","1207.46"
    "bw_mem-rd-1mb (MB/s)","3248.89 (min 3232.76, max 3265.01)"
    "bw_mem-rd-2mb (MB/s)","1426.50 (min 1328.90, max 1524.10)"
    "bw_mem-rd-4mb (MB/s)","1121.45 (min 967.59, max 1275.31)"
    "bw_mem-rd-8mb (MB/s)","1059.94 (min 899.99, max 1219.88)"
    "bw_mem-rdwr-16mb (MB/s)","851.47"
    "bw_mem-rdwr-1mb (MB/s)","1660.58 (min 775.34, max 2545.82)"
    "bw_mem-rdwr-2mb (MB/s)","939.64 (min 616.05, max 1263.22)"
    "bw_mem-rdwr-4mb (MB/s)","758.85 (min 587.46, max 930.23)"
    "bw_mem-rdwr-8mb (MB/s)","729.61 (min 593.60, max 865.61)"
    "bw_mem-wr-16mb (MB/s)","892.16"
    "bw_mem-wr-1mb (MB/s)","2889.29 (min 2545.82, max 3232.76)"
    "bw_mem-wr-2mb (MB/s)","1296.06 (min 1263.22, max 1328.90)"
    "bw_mem-wr-4mb (MB/s)","948.91 (min 930.23, max 967.59)"
    "bw_mem-wr-8mb (MB/s)","882.80 (min 865.61, max 899.99)"
    "bw_mmap_rd-mo-1mb (MB/s)","2721.62"
    "bw_mmap_rd-o2c-1mb (MB/s)","696.99"
    "bw_pipe (MB/s)","477.71"
    "bw_unix (MB/s)","986.93"
    "lat_connect (us)","91.85"
    "lat_ctx-2-128k (us)","12.01"
    "lat_ctx-2-256k (us)","9.65"
    "lat_ctx-4-128k (us)","7.85"
    "lat_ctx-4-256k (us)","3.97"
    "lat_fs-0k (num_files)","204.00"
    "lat_fs-10k (num_files)","90.00"
    "lat_fs-1k (num_files)","135.00"
    "lat_fs-4k (num_files)","134.00"
    "lat_mem_rd-stride128-sz1000k (ns)","23.73"
    "lat_mem_rd-stride128-sz125k (ns)","9.79"
    "lat_mem_rd-stride128-sz250k (ns)","10.28"
    "lat_mem_rd-stride128-sz31k (ns)","6.43"
    "lat_mem_rd-stride128-sz50 (ns)","3.77"
    "lat_mem_rd-stride128-sz500k (ns)","11.38"
    "lat_mem_rd-stride128-sz62k (ns)","9.25"
    "lat_mmap-1m (us)","80.00"
    "lat_ops-double-add (ns)","5.03"
    "lat_ops-double-div (ns)","27.79"
    "lat_ops-double-mul (ns)","5.03"
    "lat_ops-float-add (ns)","5.04"
    "lat_ops-float-div (ns)","16.37"
    "lat_ops-float-mul (ns)","5.05"
    "lat_ops-int-add (ns)","1.26"
    "lat_ops-int-bit (ns)","0.84"
    "lat_ops-int-div (ns)","7.57"
    "lat_ops-int-mod (ns)","7.97"
    "lat_ops-int-mul (ns)","5.42"
    "lat_ops-int64-add (ns)","1.26"
    "lat_ops-int64-bit (ns)","0.84"
    "lat_ops-int64-div (ns)","11.96"
    "lat_ops-int64-mod (ns)","9.23"
    "lat_ops-int64-mul (ns)","6.25"
    "lat_pagefault (us)","1.30"
    "lat_pipe (us)","35.18"
    "lat_proc-exec (us)","909.67"
    "lat_proc-fork (us)","790.14"
    "lat_proc-proccall (us)","0.02"
    "lat_select (us)","54.96"
    "lat_sem (us)","5.89"
    "lat_sig-catch (us)","7.38"
    "lat_sig-install (us)","1.14"
    "lat_sig-prot (us)","0.84"
    "lat_syscall-fstat (us)","5.47"
    "lat_syscall-null (us)","0.71"
    "lat_syscall-open (us)","276.20"
    "lat_syscall-read (us)","1.21"
    "lat_syscall-stat (us)","6.96"
    "lat_syscall-write (us)","1.00"
    "lat_tcp (us)","1.41"
    "lat_unix (us)","68.44"
    "latency_for_0.50_mb_block_size (nanosec)","11.38"
    "latency_for_1.00_mb_block_size (nanosec)","11.87 (min 0.00, max 23.73)"
    "pipe_bandwidth (MBs)","477.71"
    "pipe_latency (microsec)","35.18"
    "procedure_call (microsec)","0.02"
    "select_on_200_tcp_fds (microsec)","54.96"
    "semaphore_latency (microsec)","5.89"
    "signal_handler_latency (microsec)","1.14"
    "signal_handler_overhead (microsec)","7.38"
    "tcp_ip_connection_cost_to_localhost (microsec)","91.85"
    "tcp_latency_using_localhost (microsec)","1.41"


Table:  **LM Bench Metrics**


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

    "linpack (Kflops)","326394.00"


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

    "assignment (Iterations)","7.89"
    "fourier (Iterations)","12853.00"
    "fp_emulation (Iterations)","52.43"
    "huffman (Iterations)","663.45"
    "idea (Iterations)","1956.50"
    "lu_decomposition (Iterations)","302.85"
    "neural_net (Iterations)","5.01"
    "numeric_sort (Iterations)","339.11"
    "string_sort (Iterations)","93.56"


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

    "add (MB/s)","1589.60"
    "copy (MB/s)","1838.30"
    "scale (MB/s)","1811.70"
    "triad (MB/s)","1495.20"


Table:  **Stream**


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
    :header: "Benchmarks","am654x-evm: perf"

    "4m-check (workloads/)","314.43"
    "4m-check-reassembly (workloads/)","79.05"
    "4m-check-reassembly-tcp (workloads/)","37.04"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","11.18"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.13"
    "4m-cmykw2 (workloads/)","139.28"
    "4m-cmykw2-rotatew2 (workloads/)","34.27"
    "4m-reassembly (workloads/)","58.04"
    "4m-rotatew2 (workloads/)","13.29"
    "4m-tcp-mixed (workloads/)","70.80"
    "4m-x264w2 (workloads/)","1.16"
    "empty-wld (workloads/)","1.00"
    "idct-4m (workloads/)","10.97"
    "idct-4mw1 (workloads/)","10.98"
    "ippktcheck-4m (workloads/)","314.74"
    "ippktcheck-4mw1 (workloads/)","315.30"
    "ipres-4m (workloads/)","67.78"
    "ipres-4mw1 (workloads/)","67.72"
    "md5-4m (workloads/)","17.05"
    "md5-4mw1 (workloads/)","17.00"
    "rgbcmyk-4m (workloads/)","36.43"
    "rgbcmyk-4mw1 (workloads/)","36.40"
    "rotate-4ms1 (workloads/)","14.25"
    "rotate-4ms1w1 (workloads/)","14.25"
    "rotate-4ms64 (workloads/)","14.39"
    "rotate-4ms64w1 (workloads/)","14.38"
    "x264-4mq (workloads/)","0.33"
    "x264-4mqw1 (workloads/)","0.33"


Table:  **Multibench**
 

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am654x-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","20.50 (min 17.91, max 24.61)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","4.45 (min 4.42, max 4.47)"

Table:  **Boot time MMC/SD**


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

.. rubric::  TCP Bidirectional Throughput Interrupt Pacing
   :name: CPSW2g-tcp-bidirectional-throughput-interrupt-pacing

.. csv-table::
    :header: "Command Used","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1463.47","34.26"

Table: **CPSW TCP Bidirectional Throughput Interrupt Pacing**

|



.. rubric::  UDP Throughput 
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am654x-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: Packets Per Second (kPPS)","am654x-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","10.34","72.00","45.70"
    "128","82.00","48.91","75.00","44.85"
    "256","210.00","120.14","72.00","45.76"
    "1024","978.00","517.07","66.00","46.38"
    "1518","1472.00","625.72","53.00","37.07"

Table: **CPSW UDP Egress Throughput**

|



.. csv-table::
    :header: "Frame Size(bytes)","am654x-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: Packets Per Second (kPPS)","am654x-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.86","13.00","4.86"
    "128","82.00","9.58","15.00","4.84"
    "256","210.00","56.45","34.00","16.67"
    "1518","1472.00","428.63","36.00","18.22"

Table: **CPSW UDP Ingress Throughput (0% loss)**

|



.. csv-table::
    :header: "Frame Size(bytes)","am654x-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: Packets Per Second (kPPS)","am654x-evm: CPU Load % (LOCAL_CPU_UTIL)","am654x-evm: Packet Loss %"

    "64","18.00","14.93","104.00","42.30","73.92"
    "128","82.00","68.49","104.00","42.84","74.73"
    "256","210.00","176.52","105.00","43.39","72.63"
    "1518","1472.00","924.97","79.00","40.51","1.74"

Table: **CPSW UDP Ingress Throughput (possible loss)**

