
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

.. csv-table:: LMBench Benchmarks
    :header: "Benchmarks","am64xx-hsevm: perf"

    "af_unix_sock_stream_latency (microsec)","37.55"
    "af_unix_socket_stream_bandwidth (MBs)","592.55"
    "bw_file_rd-io-1mb (MB/s)","852.37"
    "bw_file_rd-o2c-1mb (MB/s)","492.85"
    "bw_mem-bcopy-16mb (MB/s)","839.45"
    "bw_mem-bcopy-1mb (MB/s)","951.02"
    "bw_mem-bcopy-2mb (MB/s)","930.38"
    "bw_mem-bcopy-4mb (MB/s)","990.96"
    "bw_mem-bcopy-8mb (MB/s)","1012.40"
    "bw_mem-bzero-16mb (MB/s)","2118.08"
    "bw_mem-bzero-1mb (MB/s)","1531.48 (min 951.02, max 2111.93)"
    "bw_mem-bzero-2mb (MB/s)","1522.09 (min 930.38, max 2113.79)"
    "bw_mem-bzero-4mb (MB/s)","1553.31 (min 990.96, max 2115.66)"
    "bw_mem-bzero-8mb (MB/s)","1565.10 (min 1012.40, max 2117.80)"
    "bw_mem-cp-16mb (MB/s)","515.38"
    "bw_mem-cp-1mb (MB/s)","690.36 (min 528.63, max 852.08)"
    "bw_mem-cp-2mb (MB/s)","683.10 (min 527.50, max 838.69)"
    "bw_mem-cp-4mb (MB/s)","676.28 (min 524.32, max 828.24)"
    "bw_mem-cp-8mb (MB/s)","713.71 (min 583.09, max 844.33)"
    "bw_mem-fcp-16mb (MB/s)","903.65"
    "bw_mem-fcp-1mb (MB/s)","1606.63 (min 1101.32, max 2111.93)"
    "bw_mem-fcp-2mb (MB/s)","1578.73 (min 1043.66, max 2113.79)"
    "bw_mem-fcp-4mb (MB/s)","1579.89 (min 1044.11, max 2115.66)"
    "bw_mem-fcp-8mb (MB/s)","1611.62 (min 1105.43, max 2117.80)"
    "bw_mem-frd-16mb (MB/s)","1298.60"
    "bw_mem-frd-1mb (MB/s)","1193.81 (min 1101.32, max 1286.29)"
    "bw_mem-frd-2mb (MB/s)","1171.61 (min 1043.66, max 1299.55)"
    "bw_mem-frd-4mb (MB/s)","1165.04 (min 1044.11, max 1285.97)"
    "bw_mem-frd-8mb (MB/s)","1195.49 (min 1105.43, max 1285.55)"
    "bw_mem-fwr-16mb (MB/s)","845.76"
    "bw_mem-fwr-1mb (MB/s)","1069.19 (min 852.08, max 1286.29)"
    "bw_mem-fwr-2mb (MB/s)","1069.12 (min 838.69, max 1299.55)"
    "bw_mem-fwr-4mb (MB/s)","1057.11 (min 828.24, max 1285.97)"
    "bw_mem-fwr-8mb (MB/s)","1064.94 (min 844.33, max 1285.55)"
    "bw_mem-rd-16mb (MB/s)","1337.01"
    "bw_mem-rd-1mb (MB/s)","1085.25 (min 825.63, max 1344.86)"
    "bw_mem-rd-2mb (MB/s)","1093.12 (min 815.44, max 1370.80)"
    "bw_mem-rd-4mb (MB/s)","1112.96 (min 868.15, max 1357.77)"
    "bw_mem-rd-8mb (MB/s)","1121.04 (min 888.89, max 1353.18)"
    "bw_mem-rdwr-16mb (MB/s)","869.05"
    "bw_mem-rdwr-1mb (MB/s)","680.20 (min 528.63, max 831.77)"
    "bw_mem-rdwr-2mb (MB/s)","671.97 (min 527.50, max 816.44)"
    "bw_mem-rdwr-4mb (MB/s)","683.61 (min 524.32, max 842.90)"
    "bw_mem-rdwr-8mb (MB/s)","719.22 (min 583.09, max 855.34)"
    "bw_mem-wr-16mb (MB/s)","903.50"
    "bw_mem-wr-1mb (MB/s)","828.70 (min 825.63, max 831.77)"
    "bw_mem-wr-2mb (MB/s)","815.94 (min 815.44, max 816.44)"
    "bw_mem-wr-4mb (MB/s)","855.53 (min 842.90, max 868.15)"
    "bw_mem-wr-8mb (MB/s)","872.12 (min 855.34, max 888.89)"
    "bw_mmap_rd-mo-1mb (MB/s)","1307.43"
    "bw_mmap_rd-o2c-1mb (MB/s)","496.52"
    "bw_pipe (MB/s)","524.94"
    "bw_unix (MB/s)","592.55"
    "lat_connect (us)","77.38"
    "lat_ctx-2-128k (us)","5.12"
    "lat_ctx-2-256k (us)","20.50"
    "lat_ctx-4-128k (us)","7.30"
    "lat_ctx-4-256k (us)","10.17"
    "lat_fs-0k (num_files)","205.00"
    "lat_fs-10k (num_files)","93.00"
    "lat_fs-1k (num_files)","149.00"
    "lat_fs-4k (num_files)","162.00"
    "lat_mem_rd-stride128-sz1000k (ns)","48.11"
    "lat_mem_rd-stride128-sz125k (ns)","7.81"
    "lat_mem_rd-stride128-sz250k (ns)","9.64"
    "lat_mem_rd-stride128-sz31k (ns)","5.89"
    "lat_mem_rd-stride128-sz50 (ns)","3.01"
    "lat_mem_rd-stride128-sz500k (ns)","43.32"
    "lat_mem_rd-stride128-sz62k (ns)","7.35"
    "lat_mmap-1m (us)","65.00"
    "lat_ops-double-add (ns)","4.02"
    "lat_ops-double-div (ns)","22.12"
    "lat_ops-double-mul (ns)","4.02"
    "lat_ops-float-add (ns)","4.02"
    "lat_ops-float-div (ns)","13.06"
    "lat_ops-float-mul (ns)","4.02"
    "lat_ops-int-add (ns)","1.01"
    "lat_ops-int-bit (ns)","0.67"
    "lat_ops-int-div (ns)","6.03"
    "lat_ops-int-mod (ns)","6.37"
    "lat_ops-int-mul (ns)","4.34"
    "lat_ops-int64-add (ns)","1.01"
    "lat_ops-int64-bit (ns)","0.67"
    "lat_ops-int64-div (ns)","9.55"
    "lat_ops-int64-mod (ns)","7.37"
    "lat_ops-int64-mul (ns)","4.99"
    "lat_pagefault (us)","1.43"
    "lat_pipe (us)","21.00"
    "lat_proc-exec (us)","1175.00"
    "lat_proc-fork (us)","937.83"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","43.12"
    "lat_sem (us)","2.50"
    "lat_sig-catch (us)","6.17"
    "lat_sig-install (us)","0.94"
    "lat_sig-prot (us)","0.31"
    "lat_syscall-fstat (us)","4.24"
    "lat_syscall-null (us)","0.58"
    "lat_syscall-open (us)","333.69"
    "lat_syscall-read (us)","0.92"
    "lat_syscall-stat (us)","5.79"
    "lat_syscall-write (us)","0.78"
    "lat_tcp (us)","1.14"
    "lat_unix (us)","37.55"
    "latency_for_0.50_mb_block_size (nanosec)","43.32"
    "latency_for_1.00_mb_block_size (nanosec)","24.06 (min 0.00, max 48.11)"
    "pipe_bandwidth (MBs)","524.94"
    "pipe_latency (microsec)","21.00"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","43.12"
    "semaphore_latency (microsec)","2.50"
    "signal_handler_latency (microsec)","0.94"
    "signal_handler_overhead (microsec)","6.17"
    "tcp_ip_connection_cost_to_localhost (microsec)","77.38"
    "tcp_latency_using_localhost (microsec)","1.14"

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

.. csv-table:: Dhrystone Benchmarks
    :header: "Benchmarks","am64xx-hsevm: perf"

    "cpu_clock (MHz)","1000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","3.00"
    "dhrystone_per_second (DhrystoneP)","5263158.00"




Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: Whetstone Benchmarks
    :header: "Benchmarks","am64xx-hsevm: perf"

    "whetstone (MIPS)","5000.00"

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table:: Linpack Benchmarks
    :header: "Benchmarks","am64xx-hsevm: perf"

    "linpack (Kflops)","409266.00"




NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks 
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html

.. csv-table:: NBench Benchmarks
    :header: "Benchmarks","am64xx-hsevm: perf"

    "assignment (Iterations)","9.86"
    "fourier (Iterations)","16087.00"
    "fp_emulation (Iterations)","65.58"
    "huffman (Iterations)","830.48"
    "idea (Iterations)","2448.30"
    "lu_decomposition (Iterations)","378.30"
    "neural_net (Iterations)","6.23"
    "numeric_sort (Iterations)","424.59"
    "string_sort (Iterations)","110.37"




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
    :header: "Benchmarks","am64xx-hsevm: perf"

    "add (MB/s)","1629.00"
    "copy (MB/s)","2097.80"
    "scale (MB/s)","2263.70"
    "triad (MB/s)","1619.20"




CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.


.. csv-table:: CoreMarkPro Benchmarks
    :header: "Benchmarks","am64xx-hsevm: perf"

    "cjpeg-rose7-preset (workloads/)","29.76"
    "core (workloads/)","0.21"
    "coremark-pro ()","587.75"
    "linear_alg-mid-100x100-sp (workloads/)","10.43"
    "loops-all-mid-10k-sp (workloads/)","0.48"
    "nnet_test (workloads/)","0.77"
    "parser-125k (workloads/)","5.71"
    "radix2-big-64k (workloads/)","19.27"
    "sha-test (workloads/)","58.14"
    "zip-test (workloads/)","15.38"

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

.. csv-table:: CPSW2g TCP Bidirectional Throughput
    :header: "Command Used","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","956.48","72.91"




.. rubric::  TCP Bidirectional Throughput Interrupt Pacing
   :name: CPSW2g-tcp-bidirectional-throughput-interrupt-pacing

.. csv-table:: CPSW2g TCP Bidirectional Throughput Interrupt Pacing
    :header: "Command Used","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","195.02","25.61"

.. rubric::  UDP Throughput 
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table:: CPSW2g UDP Egress Throughput 0 loss
    :header: "Frame Size(bytes)","am64xx-hsevm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: Packets Per Second (kPPS)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","12.84","89.00","89.30"
    "128","82.00","58.93","90.00","88.11"
    "256","210.00","104.52","62.00","69.09"
    "1024","978.00","612.26","78.00","92.33"
    "1518","1472.00","484.25","41.00","51.18"





.. csv-table:: CPSW2g UDP Ingress Throughput 0 loss
    :header: "Frame Size(bytes)","am64xx-hsevm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: Packets Per Second (kPPS)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.20","8.00","8.13"
    "128","82.00","5.18","8.00","6.35"
    "256","210.00","12.94","8.00","6.52"
    "1024","978.00","61.81","8.00","9.68"
    "1518","1472.00","94.21","8.00","8.98"





.. csv-table:: CPSW2g UDP Ingress Throughput possible loss
    :header: "Frame Size(bytes)","am64xx-hsevm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: Packets Per Second (kPPS)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)","am64xx-hsevm: Packet Loss %"

    "64","18.00","19.22","133.00","76.55","77.05"
    "128","82.00","83.04","127.00","79.34","75.89"
    "256","210.00","207.48","124.00","79.63","69.44"
    "1024","978.00","785.24","100.00","82.53","16.18"
    "1518","1472.00","859.16","73.00","86.85","10.15"

ICSSG Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput 
   :name: tcp-bidirectional-throughput

.. csv-table:: ICSSG TCP Bidirectional Throughput
    :header: "Command Used","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_MAERTS","141.59","33.17"




.. rubric::  TCP Bidirectional Throughput Interrupt Pacing
   :name: ICSSG-tcp-bidirectional-throughput-interrupt-pacing

.. csv-table:: ICSSG TCP Bidirectional Throughput Interrupt Pacing
    :header: "Command Used","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.2.1 -j -c -C -l 60 -t TCP_MAERTS","141.88","25.04"







.. csv-table:: ICSSG UDP Ingress Throughput 0 loss
    :header: "Frame Size(bytes)","am64xx-hsevm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-hsevm: THROUGHPUT (Mbits/sec)","am64xx-hsevm: Packets Per Second (kPPS)","am64xx-hsevm: CPU Load %"

    "64","18.00","3.31","23.00","17.84"
    "128","82.00","14.43","22.00","17.31"
    "1024","978.00","102.83","13.00","20.91"
    "1518","1472.00","203.40","17.00","30.48"

 
 
 



|

PCIe Driver
-------------------------

PCIe-ETH
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: PCIe Ethernet performance
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




.. csv-table:: PCIE SSD EXT4 FIO 10G
    :header: "Buffer size (bytes)","am64xx-hsevm: Write EXT4 Throughput (Mbytes/sec)","am64xx-hsevm: Write EXT4 CPU Load (%)","am64xx-hsevm: Read EXT4 Throughput (Mbytes/sec)","am64xx-hsevm: Read EXT4 CPU Load (%)"

    "1m","373.00","16.35","398.00","10.85"
    "4m","368.00","14.63","398.00","10.33"
    "4k","72.50","50.99","90.10","47.27"
    "256k","375.00","18.25","397.00","12.00"



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

.. csv-table:: EMMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","am64xx-hsevm: Write EXT4 Throughput (Mbytes/sec)","am64xx-hsevm: Write EXT4 CPU Load (%)","am64xx-hsevm: Read EXT4 Throughput (Mbytes/sec)","am64xx-hsevm: Read EXT4 CPU Load (%)"

    "1m","60.90","3.30","175.00","5.78"
    "4m","61.40","2.56","175.00","4.46"
    "4k","48.10","52.04","55.50","54.39"
    "256k","61.00","5.17","174.00","7.38"





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

.. csv-table:: MMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","am64xx-hsevm: Write EXT4 Throughput (Mbytes/sec)","am64xx-hsevm: Write EXT4 CPU Load (%)","am64xx-hsevm: Read EXT4 Throughput (Mbytes/sec)","am64xx-hsevm: Read EXT4 CPU Load (%)"

    "1m","18.70","1.44","86.80","3.48"
    "4m","19.00","1.25","86.70","2.67"
    "4k","4.97","8.93","16.20","17.12"
    "256k","18.20","2.12","84.10","5.15"


 

 

 

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Table:  **OpenSSL Performance**

.. csv-table:: OpenSSL Performance
    :header: "Algorithm","Buffer Size (in bytes)","am64xx-hsevm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","23724.03"
    "aes-128-cbc","16","413.09"
    "aes-128-cbc","16384","142710.10"
    "aes-128-cbc","256","6472.70"
    "aes-128-cbc","64","1647.77"
    "aes-128-cbc","8192","104966.83"
    "aes-128-ecb","1024","23443.46"
    "aes-128-ecb","16","414.90"
    "aes-128-ecb","16384","147707.22"
    "aes-128-ecb","256","6678.19"
    "aes-128-ecb","64","1662.38"
    "aes-128-ecb","8192","107252.39"
    "aes-192-cbc","1024","21836.12"
    "aes-192-cbc","16","410.06"
    "aes-192-cbc","16384","132928.85"
    "aes-192-cbc","256","6497.88"
    "aes-192-cbc","64","1639.40"
    "aes-192-cbc","8192","99292.50"
    "aes-192-ecb","1024","24174.25"
    "aes-192-ecb","16","411.21"
    "aes-192-ecb","16384","137887.74"
    "aes-192-ecb","256","6575.70"
    "aes-192-ecb","64","1629.18"
    "aes-192-ecb","8192","102342.66"
    "aes-256-cbc","1024","22263.81"
    "aes-256-cbc","16","377.12"
    "aes-256-cbc","16384","125719.89"
    "aes-256-cbc","256","6525.53"
    "aes-256-cbc","64","1503.64"
    "aes-256-cbc","8192","94806.02"
    "aes-256-ecb","1024","24240.47"
    "aes-256-ecb","16","404.67"
    "aes-256-ecb","16384","129957.89"
    "aes-256-ecb","256","6635.18"
    "aes-256-ecb","64","1656.53"
    "aes-256-ecb","8192","97949.01"
    "sha256","1024","24987.65"
    "sha256","16","419.15"
    "sha256","16384","196034.56"
    "sha256","256","6539.35"
    "sha256","64","1657.39"
    "sha256","8192","134018.39"
    "sha512","1024","17459.20"
    "sha512","16","406.13"
    "sha512","16384","46972.93"
    "sha512","256","5782.36"
    "sha512","64","1624.45"
    "sha512","8192","42142.38"





.. csv-table:: OpenSSL CPU Load
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

.. csv-table:: IPSec Software Performance
    :header: "Algorithm","am64xx-hsevm: Throughput (Mbps)","am64xx-hsevm: Packets/Sec","am64xx-hsevm: CPU Load"

    "3des","52.90","4.00","52.45"
    "aes128","0.40","0.00","95.16"

  

|



