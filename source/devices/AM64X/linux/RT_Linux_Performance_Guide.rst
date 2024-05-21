
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
| AM64x EVM      | AM64x Evaluation Module rev E1 with ARM running at 1GHz, DDR data rate 1600 MT/S                                    |
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

.. csv-table::
    :header: "Benchmarks","am64xx-hsevm: perf"

    "af_unix_sock_stream_latency (microsec)","38.71"
    "af_unix_socket_stream_bandwidth (MBs)","573.36"
    "bw_file_rd-io-1mb (MB/s)","855.58"
    "bw_file_rd-o2c-1mb (MB/s)","508.91"
    "bw_mem-bcopy-16mb (MB/s)","853.20"
    "bw_mem-bcopy-1mb (MB/s)","967.31"
    "bw_mem-bcopy-2mb (MB/s)","862.81"
    "bw_mem-bcopy-4mb (MB/s)","905.18"
    "bw_mem-bcopy-8mb (MB/s)","980.87"
    "bw_mem-bzero-16mb (MB/s)","2119.49"
    "bw_mem-bzero-1mb (MB/s)","1542.79 (min 967.31, max 2118.27)"
    "bw_mem-bzero-2mb (MB/s)","1490.17 (min 862.81, max 2117.52)"
    "bw_mem-bzero-4mb (MB/s)","1511.17 (min 905.18, max 2117.15)"
    "bw_mem-bzero-8mb (MB/s)","1550.18 (min 980.87, max 2119.49)"
    "bw_mem-cp-16mb (MB/s)","519.77"
    "bw_mem-cp-1mb (MB/s)","670.75 (min 534.66, max 806.84)"
    "bw_mem-cp-2mb (MB/s)","670.36 (min 519.35, max 821.36)"
    "bw_mem-cp-4mb (MB/s)","695.11 (min 565.05, max 825.17)"
    "bw_mem-cp-8mb (MB/s)","719.39 (min 600.47, max 838.31)"
    "bw_mem-fcp-16mb (MB/s)","892.56"
    "bw_mem-fcp-1mb (MB/s)","1600.36 (min 1082.45, max 2118.27)"
    "bw_mem-fcp-2mb (MB/s)","1590.49 (min 1063.45, max 2117.52)"
    "bw_mem-fcp-4mb (MB/s)","1611.52 (min 1105.89, max 2117.15)"
    "bw_mem-fcp-8mb (MB/s)","1610.48 (min 1101.47, max 2119.49)"
    "bw_mem-frd-16mb (MB/s)","1313.95"
    "bw_mem-frd-1mb (MB/s)","1182.84 (min 1082.45, max 1283.23)"
    "bw_mem-frd-2mb (MB/s)","1206.49 (min 1063.45, max 1349.53)"
    "bw_mem-frd-4mb (MB/s)","1190.91 (min 1105.89, max 1275.92)"
    "bw_mem-frd-8mb (MB/s)","1195.90 (min 1101.47, max 1290.32)"
    "bw_mem-fwr-16mb (MB/s)","846.56"
    "bw_mem-fwr-1mb (MB/s)","1045.04 (min 806.84, max 1283.23)"
    "bw_mem-fwr-2mb (MB/s)","1085.45 (min 821.36, max 1349.53)"
    "bw_mem-fwr-4mb (MB/s)","1050.55 (min 825.17, max 1275.92)"
    "bw_mem-fwr-8mb (MB/s)","1064.32 (min 838.31, max 1290.32)"
    "bw_mem-rd-16mb (MB/s)","1354.33"
    "bw_mem-rd-1mb (MB/s)","1105.50 (min 836.82, max 1374.17)"
    "bw_mem-rd-2mb (MB/s)","1091.19 (min 821.13, max 1361.24)"
    "bw_mem-rd-4mb (MB/s)","1097.00 (min 842.19, max 1351.81)"
    "bw_mem-rd-8mb (MB/s)","1123.36 (min 884.08, max 1362.63)"
    "bw_mem-rdwr-16mb (MB/s)","883.64"
    "bw_mem-rdwr-1mb (MB/s)","673.57 (min 534.66, max 812.48)"
    "bw_mem-rdwr-2mb (MB/s)","667.12 (min 519.35, max 814.89)"
    "bw_mem-rdwr-4mb (MB/s)","714.26 (min 565.05, max 863.46)"
    "bw_mem-rdwr-8mb (MB/s)","736.87 (min 600.47, max 873.27)"
    "bw_mem-wr-16mb (MB/s)","906.10"
    "bw_mem-wr-1mb (MB/s)","824.65 (min 812.48, max 836.82)"
    "bw_mem-wr-2mb (MB/s)","818.01 (min 814.89, max 821.13)"
    "bw_mem-wr-4mb (MB/s)","852.83 (min 842.19, max 863.46)"
    "bw_mem-wr-8mb (MB/s)","878.68 (min 873.27, max 884.08)"
    "bw_mmap_rd-mo-1mb (MB/s)","1321.00"
    "bw_mmap_rd-o2c-1mb (MB/s)","513.35"
    "bw_pipe (MB/s)","545.27"
    "bw_unix (MB/s)","573.36"
    "lat_connect (us)","77.30"
    "lat_ctx-2-128k (us)","5.80"
    "lat_ctx-2-256k (us)","20.91"
    "lat_ctx-4-128k (us)","8.07"
    "lat_ctx-4-256k (us)","9.81"
    "lat_fs-0k (num_files)","214.00"
    "lat_fs-10k (num_files)","119.00"
    "lat_fs-1k (num_files)","134.00"
    "lat_fs-4k (num_files)","131.00"
    "lat_mem_rd-stride128-sz1000k (ns)","47.93"
    "lat_mem_rd-stride128-sz125k (ns)","7.80"
    "lat_mem_rd-stride128-sz250k (ns)","14.08"
    "lat_mem_rd-stride128-sz31k (ns)","5.88"
    "lat_mem_rd-stride128-sz50 (ns)","3.01"
    "lat_mem_rd-stride128-sz500k (ns)","43.81"
    "lat_mem_rd-stride128-sz62k (ns)","7.36"
    "lat_mmap-1m (us)","76.00"
    "lat_ops-double-add (ns)","4.02"
    "lat_ops-double-div (ns)","22.10"
    "lat_ops-double-mul (ns)","4.02"
    "lat_ops-float-add (ns)","4.02"
    "lat_ops-float-div (ns)","13.06"
    "lat_ops-float-mul (ns)","4.02"
    "lat_ops-int-add (ns)","1.01"
    "lat_ops-int-bit (ns)","0.67"
    "lat_ops-int-div (ns)","6.03"
    "lat_ops-int-mod (ns)","6.37"
    "lat_ops-int-mul (ns)","4.32"
    "lat_ops-int64-add (ns)","1.01"
    "lat_ops-int64-bit (ns)","0.67"
    "lat_ops-int64-div (ns)","9.55"
    "lat_ops-int64-mod (ns)","7.37"
    "lat_ops-int64-mul (ns)","5.13"
    "lat_pagefault (us)","1.48"
    "lat_pipe (us)","20.79"
    "lat_proc-exec (us)","1197.20"
    "lat_proc-fork (us)","924.17"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","46.20"
    "lat_sem (us)","3.04"
    "lat_sig-catch (us)","5.92"
    "lat_sig-install (us)","0.91"
    "lat_sig-prot (us)","0.53"
    "lat_syscall-fstat (us)","4.31"
    "lat_syscall-null (us)","0.57"
    "lat_syscall-open (us)","284.45"
    "lat_syscall-read (us)","0.92"
    "lat_syscall-stat (us)","5.52"
    "lat_syscall-write (us)","0.78"
    "lat_tcp (us)","1.14"
    "lat_unix (us)","38.71"
    "latency_for_0.50_mb_block_size (nanosec)","43.81"
    "latency_for_1.00_mb_block_size (nanosec)","23.97 (min 0.00, max 47.93)"
    "pipe_bandwidth (MBs)","545.27"
    "pipe_latency (microsec)","20.79"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","46.20"
    "semaphore_latency (microsec)","3.04"
    "signal_handler_latency (microsec)","0.91"
    "signal_handler_overhead (microsec)","5.92"
    "tcp_ip_connection_cost_to_localhost (microsec)","77.30"
    "tcp_latency_using_localhost (microsec)","1.14"

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

.. csv-table::
    :header: "Benchmarks","am64xx-hsevm: perf"

    "cpu_clock (MHz)","1000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.90"
    "dhrystone_per_second (DhrystoneP)","5128205.00"

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am64xx-hsevm: perf"

    "whetstone (MIPS)","5000.00"

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am64xx-hsevm: perf"

    "linpack (Kflops)","408974.00"

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html

.. csv-table::
    :header: "Benchmarks","am64xx-hsevm: perf"

    "assignment (Iterations)","9.84"
    "fourier (Iterations)","16093.00"
    "fp_emulation (Iterations)","65.58"
    "huffman (Iterations)","830.57"
    "idea (Iterations)","2448.30"
    "lu_decomposition (Iterations)","379.43"
    "neural_net (Iterations)","6.27"
    "numeric_sort (Iterations)","424.72"
    "string_sort (Iterations)","117.24"

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
    :header: "Benchmarks","am64xx-hsevm: perf"

    "add (MB/s)","1628.80"
    "copy (MB/s)","2009.90"
    "scale (MB/s)","2252.90"
    "triad (MB/s)","1622.50"

CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.

.. csv-table::
    :header: "Benchmarks","am64xx-hsevm: perf"

    "cjpeg-rose7-preset (workloads/)","29.76"
    "core (workloads/)","0.21"
    "coremark-pro ()","590.26"
    "linear_alg-mid-100x100-sp (workloads/)","10.43"
    "loops-all-mid-10k-sp (workloads/)","0.48"
    "nnet_test (workloads/)","0.77"
    "parser-125k (workloads/)","5.75"
    "radix2-big-64k (workloads/)","19.27"
    "sha-test (workloads/)","58.14"
    "zip-test (workloads/)","15.87"

Stress-ng and Cyclic Test
^^^^^^^^^^^^^^^^^^^^^^^^^

.. _RT-linux-performance:

stress-ng (next-generation) will stress test a embedded platform in various selectable ways.
It was designed to exercise various physical subsystems as well as the various
operating system kernel interfaces. stress-ng can also measure test throughput rates;
this can be useful to observe performance changes across different operating system or types of hardware.

Cyclictest is most commonly used for benchmarking RT systems.
It is one of the most frequently used tools for evaluating the relative performance of real-time systems.
Some performance tests which use Cyclictest are System benchmarking, Latency debugging with tracing and
approximating application performance.

Test command for running stress-ng and cyclictest together

``stress-ng --cpu-method=all -c 4 &``

``cyclictest -m -Sp98 -D6h -h400 -i200 -q``

.. csv-table::
    :header: "Latencies", "am64xx-hsevm:per-core"

    "Minimum (usec)","5,5"
    "Average (usec)","7,8"
    "Maximum (usec)","60,50"

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

- CPSW3g: AM64x

.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","206.32","25.60"

.. rubric::  TCP Bidirectional Throughput Interrupt Pacing
   :name: CPSW2g-tcp-bidirectional-throughput-interrupt-pacing

.. csv-table::
    :header: "Command Used","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","195.02","25.61"

.. rubric::  UDP Throughput 
   :name: CPSW2g-udp-throughput-0-loss

Table:  **CPSW2g UDP Egress Throughput 0 loss**

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-hsevm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: Packets Per Second (kPPS)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","12.84","89.00","89.30"
    "128","82.00","58.93","90.00","88.11"
    "256","210.00","104.52","62.00","69.09"
    "1024","978.00","612.26","78.00","92.33"
    "1518","1472.00","484.25","41.00","51.18"

Table:  **CPSW2g UDP Ingress Throughput 0 loss**

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-hsevm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: Packets Per Second (kPPS)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.20","8.00","8.13"
    "128","82.00","5.31","8.00","0.60"
    "256","210.00","13.10","8.00","0.75"
    "1024","978.00","61.81","8.00","9.68"
    "1518","1472.00","94.21","8.00","8.98"

Table:  **CPSW2g UDP Ingress Throughput possible loss**

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-hsevm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: Packets Per Second (kPPS)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)","am64xx-hsevm: Packet Loss %"

    "64","18.00","19.22","133.00","76.55","77.05"
    "128","82.00","84.69","129.00","77.02","75.24"
    "256","210.00","212.57","127.00","81.08","71.43"
    "1024","978.00","785.24","100.00","82.53","16.18"
    "1518","1472.00","859.16","73.00","86.85","10.15"

ICSSG Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput 
   :name: tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_MAERTS","213.08","50.04"

.. rubric::  TCP Bidirectional Throughput Interrupt Pacing
   :name: ICSSG-tcp-bidirectional-throughput-interrupt-pacing

Table:  **ICSSG TCP Bidirectional Throughput Interrupt Pacing**

.. csv-table::
    :header: "Command Used","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_MAERTS","215.37","36.31"

Table:  **ICSSG UDP Ingress Throughput 0 loss**

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-hsevm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: Packets Per Second (kPPS)","am64xx-hsevm: CPU Load %"

    "64","18.00","2.28","16.00","11.19"
    "128","82.00","12.19","19.00","28.42"
    "1024","978.00","181.72","23.00","32.30"
    "1518","1472.00","122.21","10.00","16.20"

|

PCIe Driver
-------------------------

PCIe-ETH
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "TCP Window Size(Kbytes)","am64xx-hsevm: Bandwidth (Mbits/sec)"

    "8","0.00"
    "16","0.00"
    "32","333.60"
    "64","521.60"
    "128","635.20"
    "256","760.80"

PCIe-NVMe-SSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

AM64xx-EVM
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-hsevm: Write EXT4 Throughput (Mbytes/sec)","am64xx-hsevm: Write EXT4 CPU Load (%)","am64xx-hsevm: Read EXT4 Throughput (Mbytes/sec)","am64xx-hsevm: Read EXT4 CPU Load (%)"

    "1m","373.00","16.28","398.00","11.37"
    "4m","360.00","14.03","398.00","10.33"
    "4k","82.30","50.92","92.40","46.69"
    "256k","375.00","18.11","397.00","11.88"

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x1
- SSD being used: Lite-On Technology Corporation M8Pe Series NVMe SSD [14a4:22f1] (rev 01)

|

EMMC Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

AM64XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-hsevm: Write EXT4 Throughput (Mbytes/sec)","am64xx-hsevm: Write EXT4 CPU Load (%)","am64xx-hsevm: Read EXT4 Throughput (Mbytes/sec)","am64xx-hsevm: Read EXT4 CPU Load (%)"

    "1m","61.40","3.37","175.00","5.71"
    "4m","61.50","2.51","175.00","4.51"
    "4k","48.40","51.50","55.70","51.73"
    "256k","61.30","5.14","174.00","7.16"

|

MMC/SD Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

AM64XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-hsevm: Write EXT4 Throughput (Mbytes/sec)","am64xx-hsevm: Write EXT4 CPU Load (%)","am64xx-hsevm: Read EXT4 Throughput (Mbytes/sec)","am64xx-hsevm: Read EXT4 CPU Load (%)"

    "1m","18.80","1.51","85.30","3.54"
    "4m","19.00","1.29","85.30","2.68"
    "4k","4.99","9.28","16.40","17.36"
    "256k","18.40","2.31","82.70","4.73"

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Table:  **OpenSSL Performance**

.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am64xx-hsevm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","23718.91"
    "aes-128-cbc","16","406.46"
    "aes-128-cbc","16384","142409.73"
    "aes-128-cbc","256","6505.90"
    "aes-128-cbc","64","1629.44"
    "aes-128-cbc","8192","104510.81"
    "aes-128-ecb","1024","24387.24"
    "aes-128-ecb","16","374.23"
    "aes-128-ecb","16384","146904.41"
    "aes-128-ecb","256","6602.15"
    "aes-128-ecb","64","1505.32"
    "aes-128-ecb","8192","106848.26"
    "aes-192-cbc","1024","23673.17"
    "aes-192-cbc","16","403.41"
    "aes-192-cbc","16384","133917.35"
    "aes-192-cbc","256","6445.82"
    "aes-192-cbc","64","1631.10"
    "aes-192-cbc","8192","99775.83"
    "aes-192-ecb","1024","24245.25"
    "aes-192-ecb","16","414.90"
    "aes-192-ecb","16384","137418.07"
    "aes-192-ecb","256","6278.40"
    "aes-192-ecb","64","1635.48"
    "aes-192-ecb","8192","102318.08"
    "aes-256-cbc","1024","23561.22"
    "aes-256-cbc","16","393.10"
    "aes-256-cbc","16384","125370.37"
    "aes-256-cbc","256","6459.82"
    "aes-256-cbc","64","1635.09"
    "aes-256-cbc","8192","96578.22"
    "aes-256-ecb","1024","23083.35"
    "aes-256-ecb","16","416.11"
    "aes-256-ecb","16384","130334.72"
    "aes-256-ecb","256","6548.74"
    "aes-256-ecb","64","1647.25"
    "aes-256-ecb","8192","98497.88"
    "sha256","1024","24971.26"
    "sha256","16","418.82"
    "sha256","16384","195259.05"
    "sha256","256","6528.00"
    "sha256","64","1656.70"
    "sha256","8192","133245.61"
    "sha512","1024","17405.95"
    "sha512","16","403.24"
    "sha512","16384","46918.31"
    "sha512","256","5745.49"
    "sha512","64","1613.40"
    "sha512","8192","42068.65"

Table:  **OpenSSL CPU Load**

.. csv-table::
    :header: "Algorithm","am64xx-hsevm: CPU Load"

    "aes-128-cbc","45.00"
    "aes-128-ecb","46.00"
    "aes-192-cbc","45.00"
    "aes-192-ecb","46.00"
    "aes-256-cbc","44.00"
    "aes-256-ecb","45.00"
    "sha256","97.00"
    "sha512","97.00"

Listed for each algorithm are the code snippets used to run each benchmark test.

::

    time -v openssl speed -elapsed -evp aes-128-cbc

IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am64xx-hsevm: Throughput (Mbps)","am64xx-hsevm: Packets/Sec","am64xx-hsevm: CPU Load"

    "3des","52.10","4.00","51.72"
    "aes128","0.60","0.00","51.57"
