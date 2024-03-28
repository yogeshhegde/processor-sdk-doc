
======================================
 RT-linux 09.02.00 Performance Guide
======================================

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


|

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

.. csv-table:: LMBench Benchmarks
    :header: "Benchmarks","am654x-evm: perf"

    "af_unix_sock_stream_latency (microsec)","73.33"
    "af_unix_socket_stream_bandwidth (MBs)","1012.24"
    "bw_file_rd-io-1mb (MB/s)","1093.29"
    "bw_file_rd-o2c-1mb (MB/s)","649.25"
    "bw_mem-bcopy-16mb (MB/s)","902.68"
    "bw_mem-bcopy-1mb (MB/s)","1244.00"
    "bw_mem-bcopy-2mb (MB/s)","970.40"
    "bw_mem-bcopy-4mb (MB/s)","901.71"
    "bw_mem-bcopy-8mb (MB/s)","909.40"
    "bw_mem-bzero-16mb (MB/s)","2013.85"
    "bw_mem-bzero-1mb (MB/s)","2842.43 (min 1244.00, max 4440.86)"
    "bw_mem-bzero-2mb (MB/s)","2187.17 (min 970.40, max 3403.93)"
    "bw_mem-bzero-4mb (MB/s)","1605.43 (min 901.71, max 2309.14)"
    "bw_mem-bzero-8mb (MB/s)","1479.82 (min 909.40, max 2050.23)"
    "bw_mem-cp-16mb (MB/s)","583.41"
    "bw_mem-cp-1mb (MB/s)","1371.07 (min 764.67, max 1977.46)"
    "bw_mem-cp-2mb (MB/s)","853.00 (min 621.21, max 1084.79)"
    "bw_mem-cp-4mb (MB/s)","715.12 (min 582.24, max 848.00)"
    "bw_mem-cp-8mb (MB/s)","696.44 (min 595.02, max 797.85)"
    "bw_mem-fcp-16mb (MB/s)","891.91"
    "bw_mem-fcp-1mb (MB/s)","2801.15 (min 1161.44, max 4440.86)"
    "bw_mem-fcp-2mb (MB/s)","2186.31 (min 968.68, max 3403.93)"
    "bw_mem-fcp-4mb (MB/s)","1602.85 (min 896.56, max 2309.14)"
    "bw_mem-fcp-8mb (MB/s)","1476.02 (min 901.81, max 2050.23)"
    "bw_mem-frd-16mb (MB/s)","1150.42"
    "bw_mem-frd-1mb (MB/s)","1346.86 (min 1161.44, max 1532.27)"
    "bw_mem-frd-2mb (MB/s)","1166.24 (min 968.68, max 1363.79)"
    "bw_mem-frd-4mb (MB/s)","1056.56 (min 896.56, max 1216.55)"
    "bw_mem-frd-8mb (MB/s)","1055.14 (min 901.81, max 1208.46)"
    "bw_mem-fwr-16mb (MB/s)","791.45"
    "bw_mem-fwr-1mb (MB/s)","1754.87 (min 1532.27, max 1977.46)"
    "bw_mem-fwr-2mb (MB/s)","1224.29 (min 1084.79, max 1363.79)"
    "bw_mem-fwr-4mb (MB/s)","1032.28 (min 848.00, max 1216.55)"
    "bw_mem-fwr-8mb (MB/s)","1003.16 (min 797.85, max 1208.46)"
    "bw_mem-rd-16mb (MB/s)","1208.00"
    "bw_mem-rd-1mb (MB/s)","3308.61 (min 3272.73, max 3344.48)"
    "bw_mem-rd-2mb (MB/s)","1428.14 (min 1322.53, max 1533.74)"
    "bw_mem-rd-4mb (MB/s)","1126.77 (min 975.37, max 1278.16)"
    "bw_mem-rd-8mb (MB/s)","1056.99 (min 900.39, max 1213.59)"
    "bw_mem-rdwr-16mb (MB/s)","853.65"
    "bw_mem-rdwr-1mb (MB/s)","1835.83 (min 764.67, max 2906.98)"
    "bw_mem-rdwr-2mb (MB/s)","940.83 (min 621.21, max 1260.44)"
    "bw_mem-rdwr-4mb (MB/s)","757.43 (min 582.24, max 932.62)"
    "bw_mem-rdwr-8mb (MB/s)","729.57 (min 595.02, max 864.12)"
    "bw_mem-wr-16mb (MB/s)","893.56"
    "bw_mem-wr-1mb (MB/s)","3089.86 (min 2906.98, max 3272.73)"
    "bw_mem-wr-2mb (MB/s)","1291.49 (min 1260.44, max 1322.53)"
    "bw_mem-wr-4mb (MB/s)","954.00 (min 932.62, max 975.37)"
    "bw_mem-wr-8mb (MB/s)","882.26 (min 864.12, max 900.39)"
    "bw_mmap_rd-mo-1mb (MB/s)","2721.83"
    "bw_mmap_rd-o2c-1mb (MB/s)","709.47"
    "bw_pipe (MB/s)","480.79"
    "bw_unix (MB/s)","1012.24"
    "lat_connect (us)","91.28"
    "lat_ctx-2-128k (us)","11.95"
    "lat_ctx-2-256k (us)","9.22"
    "lat_ctx-4-128k (us)","7.82"
    "lat_ctx-4-256k (us)","5.75"
    "lat_fs-0k (num_files)","185.00"
    "lat_fs-10k (num_files)","88.00"
    "lat_fs-1k (num_files)","122.00"
    "lat_fs-4k (num_files)","122.00"
    "lat_mem_rd-stride128-sz1000k (ns)","23.29"
    "lat_mem_rd-stride128-sz125k (ns)","9.81"
    "lat_mem_rd-stride128-sz250k (ns)","10.28"
    "lat_mem_rd-stride128-sz31k (ns)","7.36"
    "lat_mem_rd-stride128-sz50 (ns)","3.77"
    "lat_mem_rd-stride128-sz500k (ns)","11.95"
    "lat_mem_rd-stride128-sz62k (ns)","9.19"
    "lat_mmap-1m (us)","80.00"
    "lat_ops-double-add (ns)","5.03"
    "lat_ops-double-div (ns)","27.69"
    "lat_ops-double-mul (ns)","5.03"
    "lat_ops-float-add (ns)","5.03"
    "lat_ops-float-div (ns)","16.36"
    "lat_ops-float-mul (ns)","5.03"
    "lat_ops-int-add (ns)","1.26"
    "lat_ops-int-bit (ns)","0.84"
    "lat_ops-int-div (ns)","7.55"
    "lat_ops-int-mod (ns)","7.97"
    "lat_ops-int-mul (ns)","5.42"
    "lat_ops-int64-add (ns)","1.26"
    "lat_ops-int64-bit (ns)","0.84"
    "lat_ops-int64-div (ns)","11.99"
    "lat_ops-int64-mod (ns)","9.25"
    "lat_ops-int64-mul (ns)","6.38"
    "lat_pagefault (us)","1.31"
    "lat_pipe (us)","37.56"
    "lat_proc-exec (us)","920.83"
    "lat_proc-fork (us)","774.86"
    "lat_proc-proccall (us)","0.02"
    "lat_select (us)","58.34"
    "lat_sem (us)","4.65"
    "lat_sig-catch (us)","7.40"
    "lat_sig-install (us)","1.14"
    "lat_sig-prot (us)","0.60"
    "lat_syscall-fstat (us)","5.39"
    "lat_syscall-null (us)","0.71"
    "lat_syscall-open (us)","253.50"
    "lat_syscall-read (us)","1.14"
    "lat_syscall-stat (us)","6.86"
    "lat_syscall-write (us)","0.97"
    "lat_tcp (us)","1.41"
    "lat_unix (us)","73.33"
    "latency_for_0.50_mb_block_size (nanosec)","11.95"
    "latency_for_1.00_mb_block_size (nanosec)","11.65 (min 0.00, max 23.29)"
    "pipe_bandwidth (MBs)","480.79"
    "pipe_latency (microsec)","37.56"
    "procedure_call (microsec)","0.02"
    "select_on_200_tcp_fds (microsec)","58.34"
    "semaphore_latency (microsec)","4.65"
    "signal_handler_latency (microsec)","1.14"
    "signal_handler_overhead (microsec)","7.40"
    "tcp_ip_connection_cost_to_localhost (microsec)","91.28"
    "tcp_latency_using_localhost (microsec)","1.41"

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: Whetstone Benchmarks
    :header: "Benchmarks","am654x-evm: perf"

    "whetstone (MIPS)","3333.30"

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table:: Linpack Benchmarks
    :header: "Benchmarks","am654x-evm: perf"

    "linpack (Kflops)","327968.00"

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks 
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html

.. csv-table:: NBench Benchmarks
    :header: "Benchmarks","am654x-evm: perf"

    "assignment (Iterations)","7.88"
    "fourier (Iterations)","12859.00"
    "fp_emulation (Iterations)","52.44"
    "huffman (Iterations)","663.85"
    "idea (Iterations)","1957.30"
    "lu_decomposition (Iterations)","303.07"
    "neural_net (Iterations)","5.01"
    "numeric_sort (Iterations)","339.27"
    "string_sort (Iterations)","93.80"

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

.. csv-table:: Stream Benchmarks
    :header: "Benchmarks","am654x-evm: perf"

    "add (MB/s)","1590.10"
    "copy (MB/s)","1839.90"
    "scale (MB/s)","1817.50"
    "triad (MB/s)","1497.10"

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
    :header: "Benchmarks","am654x-evm: perf"

    "4m-check (workloads/)","314.70"
    "4m-check-reassembly (workloads/)","78.80"
    "4m-check-reassembly-tcp (workloads/)","36.98"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","11.02"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.13"
    "4m-cmykw2 (workloads/)","139.76"
    "4m-cmykw2-rotatew2 (workloads/)","10.45"
    "4m-reassembly (workloads/)","57.74"
    "4m-rotatew2 (workloads/)","13.86"
    "4m-tcp-mixed (workloads/)","67.23"
    "4m-x264w2 (workloads/)","1.15"
    "empty-wld (workloads/)","1.00"
    "idct-4m (workloads/)","10.98"
    "idct-4mw1 (workloads/)","10.98"
    "ippktcheck-4m (workloads/)","314.66"
    "ippktcheck-4mw1 (workloads/)","315.10"
    "ipres-4m (workloads/)","68.00"
    "ipres-4mw1 (workloads/)","68.09"
    "md5-4m (workloads/)","16.98"
    "md5-4mw1 (workloads/)","16.97"
    "rgbcmyk-4m (workloads/)","36.44"
    "rgbcmyk-4mw1 (workloads/)","36.42"
    "rotate-4ms1 (workloads/)","14.24"
    "rotate-4ms1w1 (workloads/)","14.24"
    "rotate-4ms64 (workloads/)","14.38"
    "rotate-4ms64w1 (workloads/)","14.38"
    "x264-4mq (workloads/)","0.33"
    "x264-4mqw1 (workloads/)","0.33"

|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: Boot time MMCSD
    :header: "Boot Configuration","am654x-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","18.19 (min 17.30, max 19.42)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","4.41 (min 4.38, max 4.42)"

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

- CPSW2g: AM65x, J7200, J721e
- CPSW3g: AM64x

.. rubric::  TCP Bidirectional Throughput Interrupt Pacing
   :name: CPSW2g-tcp-bidirectional-throughput-interrupt-pacing

.. csv-table:: CPSW2g TCP Bidirectional Throughput Interrupt Pacing
    :header: "Command Used","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1385.92","33.09"

.. rubric::  UDP Throughput 
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table:: CPSW2g UDP Egress Throughput 0 loss
    :header: "Frame Size(bytes)","am654x-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: Packets Per Second (kPPS)","am654x-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","10.59","74.00","46.60"
    "128","82.00","47.45","72.00","46.85"
    "256","210.00","120.51","72.00","46.18"
    "1024","978.00","612.40","78.00","44.89"
    "1518","1472.00","788.20","67.00","47.67"

.. csv-table:: CPSW2g UDP Ingress Throughput 0 loss
    :header: "Frame Size(bytes)","am654x-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: Packets Per Second (kPPS)","am654x-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","3.61","25.00","12.00"
    "128","82.00","16.60","25.00","12.50"
    "256","210.00","44.01","26.00","13.19"
    "1518","1472.00","317.95","27.00","14.15"

.. csv-table:: CPSW2g UDP Ingress Throughput possible loss
    :header: "Frame Size(bytes)","am654x-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: Packets Per Second (kPPS)","am654x-evm: CPU Load % (LOCAL_CPU_UTIL)","am654x-evm: Packet Loss %"

    "64","18.00","14.53","101.00","41.73","51.72"
    "128","82.00","65.91","100.00","42.26","51.42"
    "256","210.00","166.18","99.00","44.19","50.23"
    "1518","1472.00","949.03","81.00","41.85","0.84"

ICSSG Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput 
   :name: tcp-bidirectional-throughput

.. csv-table:: ICSSG TCP Bidirectional Throughput
    :header: "Command Used","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_MAERTS","1071.12","48.59"

.. rubric::  TCP Bidirectional Throughput Interrupt Pacing
   :name: ICSSG-tcp-bidirectional-throughput-interrupt-pacing

.. csv-table:: ICSSG TCP Bidirectional Throughput Interrupt Pacing
    :header: "Command Used","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_MAERTS","1111.40","49.09"

.. csv-table:: ICSSG UDP Ingress Throughput 0 loss
    :header: "Frame Size(bytes)","am654x-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am654x-evm: THROUGHPUT (Mbits/sec)","am654x-evm: Packets Per Second (kPPS)","am654x-evm: CPU Load %"

    "256","210.00","32.59","19.00","10.54"

|

PCIe Driver
-------------------------

PCIe-ETH
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: PCIe Ethernet performance
    :header: "TCP Window Size(Kbytes)","am654x-evm: Bandwidth (Mbits/sec)"

    "128","0.00"
    "256","0.00"

|

CRYPTO Driver
-------------------------

IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: IPSec Software Performance
    :header: "Algorithm","am654x-evm: Throughput (Mbps)","am654x-evm: Packets/Sec","am654x-evm: CPU Load"

    "aes256","0.60","0.00","31.42"
