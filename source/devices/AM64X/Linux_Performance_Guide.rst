***********************
Linux Performance Guide
***********************


.. rubric::  **Read This First**

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| AM64x EVM      | AM64x Evaluation Module rev E1 with ARM running at 1GHz, DDRdata rate 1600 MT/S                                |
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
-----------------

LMBench
^^^^^^^

LMBench is a collection of microbenchmarks of which the memory bandwidth 
and latency related ones are typically used to estimate processor 
memory system performance.
  
**Latency**: lat_mem_rd-stride128-szN, where N is equal to or smaller than the cache
size at given level measures the cache miss penalty. N that is at least
double the size of last level cache is the latency to external memory.

**Bandwidth**: bw_mem_bcopy-N, where N is is equal to or smaller than the cache size at
a given level measures the achivable memory bandwidth from software doing
a memcpy() type operation. Typical use is for external memory bandwidth
calculation. The bandwidth is calculated as byte read and written counts
as 1 which should be roughly half of STREAM copy result.

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "af_unix_sock_stream_latency (microsec)","38.38"
    "af_unix_socket_stream_bandwidth (MBs)","622.28"
    "bw_file_rd-io-1mb (MB/s)","1046.76"
    "bw_file_rd-o2c-1mb (MB/s)","593.30"
    "bw_mem-bcopy-16mb (MB/s)","900.34"
    "bw_mem-bcopy-1mb (MB/s)","851.79"
    "bw_mem-bcopy-2mb (MB/s)","898.74"
    "bw_mem-bcopy-4mb (MB/s)","887.31"
    "bw_mem-bcopy-8mb (MB/s)","906.10"
    "bw_mem-bzero-16mb (MB/s)","2125.96"
    "bw_mem-bzero-1mb (MB/s)","1489.54 (min 851.79, max 2127.28)"
    "bw_mem-bzero-2mb (MB/s)","1513.20 (min 898.74, max 2127.66)"
    "bw_mem-bzero-4mb (MB/s)","1507.30 (min 887.31, max 2127.28)"
    "bw_mem-bzero-8mb (MB/s)","1516.03 (min 906.10, max 2125.96)"
    "bw_mem-cp-16mb (MB/s)","601.57"
    "bw_mem-cp-1mb (MB/s)","1428.61 (min 593.91, max 2263.30)"
    "bw_mem-cp-2mb (MB/s)","1395.34 (min 594.88, max 2195.79)"
    "bw_mem-cp-4mb (MB/s)","1378.87 (min 594.80, max 2162.94)"
    "bw_mem-cp-8mb (MB/s)","1375.59 (min 599.48, max 2151.69)"
    "bw_mem-fcp-16mb (MB/s)","856.81"
    "bw_mem-fcp-1mb (MB/s)","1484.80 (min 842.32, max 2127.28)"
    "bw_mem-fcp-2mb (MB/s)","1487.02 (min 846.38, max 2127.66)"
    "bw_mem-fcp-4mb (MB/s)","1493.33 (min 859.38, max 2127.28)"
    "bw_mem-fcp-8mb (MB/s)","1493.37 (min 860.77, max 2125.96)"
    "bw_mem-frd-16mb (MB/s)","1509.15"
    "bw_mem-frd-1mb (MB/s)","1157.40 (min 842.32, max 1472.48)"
    "bw_mem-frd-2mb (MB/s)","1142.88 (min 846.38, max 1439.37)"
    "bw_mem-frd-4mb (MB/s)","1145.34 (min 859.38, max 1431.30)"
    "bw_mem-frd-8mb (MB/s)","1188.97 (min 860.77, max 1517.16)"
    "bw_mem-fwr-16mb (MB/s)","2140.18"
    "bw_mem-fwr-1mb (MB/s)","1867.89 (min 1472.48, max 2263.30)"
    "bw_mem-fwr-2mb (MB/s)","1817.58 (min 1439.37, max 2195.79)"
    "bw_mem-fwr-4mb (MB/s)","1797.12 (min 1431.30, max 2162.94)"
    "bw_mem-fwr-8mb (MB/s)","1834.43 (min 1517.16, max 2151.69)"
    "bw_mem-rd-16mb (MB/s)","1514.29"
    "bw_mem-rd-1mb (MB/s)","1184.56 (min 934.14, max 1434.98)"
    "bw_mem-rd-2mb (MB/s)","1265.13 (min 1045.48, max 1484.78)"
    "bw_mem-rd-4mb (MB/s)","1304.61 (min 1100.72, max 1508.49)"
    "bw_mem-rd-8mb (MB/s)","1328.42 (min 1141.39, max 1515.44)"
    "bw_mem-rdwr-16mb (MB/s)","1113.74"
    "bw_mem-rdwr-1mb (MB/s)","748.55 (min 593.91, max 903.18)"
    "bw_mem-rdwr-2mb (MB/s)","785.41 (min 594.88, max 975.93)"
    "bw_mem-rdwr-4mb (MB/s)","829.67 (min 594.80, max 1064.54)"
    "bw_mem-rdwr-8mb (MB/s)","851.92 (min 599.48, max 1104.36)"
    "bw_mem-wr-16mb (MB/s)","1188.80"
    "bw_mem-wr-1mb (MB/s)","918.66 (min 903.18, max 934.14)"
    "bw_mem-wr-2mb (MB/s)","1010.71 (min 975.93, max 1045.48)"
    "bw_mem-wr-4mb (MB/s)","1082.63 (min 1064.54, max 1100.72)"
    "bw_mem-wr-8mb (MB/s)","1122.88 (min 1104.36, max 1141.39)"
    "bw_mmap_rd-mo-1mb (MB/s)","1457.99"
    "bw_mmap_rd-o2c-1mb (MB/s)","670.80"
    "bw_pipe (MB/s)","768.74"
    "bw_unix (MB/s)","622.28"
    "lat_connect (us)","57.03"
    "lat_ctx-2-128k (us)","22.25"
    "lat_ctx-2-256k (us)","73.25"
    "lat_ctx-4-128k (us)","45.83"
    "lat_ctx-4-256k (us)","55.13"
    "lat_fs-0k (num_files)","321.00"
    "lat_fs-10k (num_files)","89.00"
    "lat_fs-1k (num_files)","95.00"
    "lat_fs-4k (num_files)","95.00"
    "lat_mem_rd-stride128-sz1000k (ns)","41.86"
    "lat_mem_rd-stride128-sz125k (ns)","7.55"
    "lat_mem_rd-stride128-sz250k (ns)","8.16"
    "lat_mem_rd-stride128-sz31k (ns)","3.02"
    "lat_mem_rd-stride128-sz50 (ns)","3.01"
    "lat_mem_rd-stride128-sz500k (ns)","36.71"
    "lat_mem_rd-stride128-sz62k (ns)","6.40"
    "lat_mmap-1m (us)","21.00"
    "lat_ops-double-add (ns)","0.73"
    "lat_ops-double-mul (ns)","4.01"
    "lat_ops-float-add (ns)","0.73"
    "lat_ops-float-mul (ns)","4.01"
    "lat_ops-int-add (ns)","1.00"
    "lat_ops-int-bit (ns)","0.67"
    "lat_ops-int-div (ns)","6.02"
    "lat_ops-int-mod (ns)","6.35"
    "lat_ops-int-mul (ns)","3.04"
    "lat_ops-int64-add (ns)","1.00"
    "lat_ops-int64-bit (ns)","0.67"
    "lat_ops-int64-div (ns)","9.53"
    "lat_ops-int64-mod (ns)","7.35"
    "lat_pagefault (us)","2.51"
    "lat_pipe (us)","19.45"
    "lat_proc-exec (us)","1651.25"
    "lat_proc-fork (us)","1475.00"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","47.74"
    "lat_sem (us)","2.29"
    "lat_sig-catch (us)","6.83"
    "lat_sig-install (us)","0.59"
    "lat_sig-prot (us)","0.45"
    "lat_syscall-fstat (us)","1.58"
    "lat_syscall-null (us)","0.35"
    "lat_syscall-open (us)","218.91"
    "lat_syscall-read (us)","0.94"
    "lat_syscall-stat (us)","4.32"
    "lat_syscall-write (us)","0.62"
    "lat_tcp (us)","0.69"
    "lat_unix (us)","38.38"
    "latency_for_0.50_mb_block_size (nanosec)","36.71"
    "latency_for_1.00_mb_block_size (nanosec)","20.93 (min 0.00, max 41.86)"
    "pipe_bandwidth (MBs)","768.74"
    "pipe_latency (microsec)","19.45"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","47.74"
    "semaphore_latency (microsec)","2.29"
    "signal_handler_latency (microsec)","0.59"
    "signal_handler_overhead (microsec)","6.83"
    "tcp_ip_connection_cost_to_localhost (microsec)","57.03"
    "tcp_latency_using_localhost (microsec)","0.69"

Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.
  
.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "cpu_clock (MHz)","1000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","3.0"
    "dhrystone_per_second (DhrystoneP)","5263158.00"


Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "whetstone (MIPS)","3333.30"

Table:  **Whetstone Benchmark**

Linpack
^^^^^^^

Linpack measures peak double precision (64 bit) floating point performance in
sloving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "linpack (Kflops)","422512.00"

Table:  **Linpack Benchmark**

NBench
^^^^^^

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "assignment (Iterations)","9.76"
    "fourier (Iterations)","16339.00"
    "fp_emulation (Iterations)","76.58"
    "huffman (Iterations)","838.74"
    "idea (Iterations)","2454.20"
    "lu_decomposition (Iterations)","403.61"
    "neural_net (Iterations)","5.61"
    "numeric_sort (Iterations)","361.08"
    "string_sort (Iterations)","118.47"

Table:  **NBench Benchmarks**

Stream
^^^^^^

STREAM is a microbenchmarks for measuring data memory system performance without
any data reuse. It is designed to miss on caches and exercise data prefetcher and
apeculative accesseses. it uses double precision floating point (64bit) but in
most modern processors the memory access will be the bottleck. The four individual
scores are copy, scale as in multiply by constant, add two numbers, and triad for
multiply accumulate. For bandwidth a byte read counts as one and a byte written
counts as one resulting in a score that is double the bandwidth LMBench will show.

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "add (MB/s)","1895.70"
    "copy (MB/s)","1975.60"
    "scale (MB/s)","2456.60"
    "triad (MB/s)","1929.70"


Table:  **Stream**

CoreMarkPro
^^^^^^^^^^^

CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "cjpeg-rose7-preset (workloads/)","30.03"
    "core (workloads/)","0.21"
    "coremark-pro ()","603.95"
    "linear_alg-mid-100x100-sp (workloads/)","10.49"
    "loops-all-mid-10k-sp (workloads/)","0.49"
    "nnet_test (workloads/)","0.78"
    "parser-125k (workloads/)","6.29"
    "radix2-big-64k (workloads/)","19.86"
    "sha-test (workloads/)","58.48"
    "zip-test (workloads/)","16.39"

Table:  **CoreMarkPro**

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "cjpeg-rose7-preset (workloads/)","59.52"
    "core (workloads/)","0.43"
    "coremark-pro ()","1063.01"
    "linear_alg-mid-100x100-sp (workloads/)","20.98"
    "loops-all-mid-10k-sp (workloads/)","0.89"
    "nnet_test (workloads/)","1.55"
    "parser-125k (workloads/)","7.19"
    "radix2-big-64k (workloads/)","31.30"
    "sha-test (workloads/)","116.28"
    "zip-test (workloads/)","25.32"

Table:  **CoreMarkPro for Two Cores**

MultiBench
^^^^^^^^^^

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
    :header: "Benchmarks","am64xx-evm: perf"

    "4m-check (workloads/)","350.44"
    "4m-check-reassembly (workloads/)","83.61"
    "4m-check-reassembly-tcp (workloads/)","45.54"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","16.52"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","0.78"
    "4m-cmykw2 (workloads/)","91.70"
    "4m-cmykw2-rotatew2 (workloads/)","23.06"
    "4m-reassembly (workloads/)","81.57"
    "4m-rotatew2 (workloads/)","31.52"
    "4m-tcp-mixed (workloads/)","86.02"
    "4m-x264w2 (workloads/)","0.80"
    "empty-wld (workloads/)","1.00"
    "idct-4m (workloads/)","13.75"
    "idct-4mw1 (workloads/)","13.76"
    "ippktcheck-4m (workloads/)","350.24"
    "ippktcheck-4mw1 (workloads/)","349.55"
    "ipres-4m (workloads/)","73.60"
    "ipres-4mw1 (workloads/)","74.55"
    "md5-4m (workloads/)","20.57"
    "md5-4mw1 (workloads/)","20.87"
    "rgbcmyk-4m (workloads/)","45.86"
    "rgbcmyk-4mw1 (workloads/)","45.71"
    "rotate-4ms1 (workloads/)","19.65"
    "rotate-4ms1w1 (workloads/)","19.61"
    "rotate-4ms64 (workloads/)","19.72"
    "rotate_-4ms64w1 (workloads/)","19.72"
    "x264-4mq (workloads/)","0.41"
    "x264-4mqw1 (workloads/)","0.41"

Table:  **Multibench**

Ethernet
--------
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

CPSW Ethernet Driver 
^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput 

.. csv-table::
    :header: "TCP Window Size","am64xx-evm: Throughput (Mbits/sec)","am64xx-evm: CPU Load %"

    "Default","1161.60","65.67"

Table: **CPSW TCP Bidirectional Throughput**

.. rubric::  UDP Throughput (0% loss) 
   
.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes)","am64xx-evm: Throughput (Mbits/sec)","am64xx-evm: CPU Load %"

    "64","18.00","13.67","85.26"
    "128","82.00","60.36","84.80"
    "256","210.00","147.81","82.68"
    "1024","978.00","633.46","80.48"
    "1518","1472.00","947.57","86.25"

Table: **CPSW UDP Egress Throughput (0% loss)**
   
.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes)","am64xx-evm: Throughput (Mbits/sec)","am64xx-evm: CPU Load %"

    "64","18.00","2.10","15.28"
    "128","82.00","7.22","13.73"
    "256","210.00","23.69","9.08"
    "1024","978.00","80.59","4.26"
    "1518","1472.00","157.79","16.80"

Table: **CPSW UDP Ingress Throughput (0% loss)**

.. rubric::  UDP Throughput (possible loss) 

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes)","am64xx-evm: Throughput (Mbits/sec)","am64xx-evm: CPU Load %","am64xx-evm: Packet Loss %"

    "64","18.00","13.67","85.26","0.00"
    "128","82.00","60.36","84.80","0.00"
    "256","210.00","147.81","82.68","0.00"
    "1024","978.00","633.46","80.48","0.00"
    "1518","1472.00","947.57","86.25","0.00"

Table: **CPSW UDP Egress Throughput (possible loss)**

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes)","am64xx-evm: Throughput (Mbits/sec)","am64xx-evm: CPU Load %","am64xx-evm: Packet Loss %"

    "64","18.00","16.83","66.02","31.40"
    "128","82.00","77.23","69.00","55.17"
    "256","210.00","194.28","69.62","56.83"
    "1024","978.00","890.71","73.10","4.91"
    "1518","1472.00","953.41","74.29","0.37"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|

PCIe Driver
-----------

PCIe-NVMe-SSD
^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","363.00","12.07","398.00","7.80"
    "4m","361.00","11.55","398.00","7.72"
    "4k","104.00","51.18","107.00","48.22"
    "256k","364.00","13.77","397.00","9.53"

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based
- Platform: Speed 8GT/s, Width x1
- SSD being used: Lite-On Technology Corporation M8Pe Series NVMe SSD [14a4:22f1] (rev 01)

|

MMC/SD Driver
-------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","13.20","1.40","94.60","3.57"
    "4m","15.20","1.24","94.70","2.82"
    "4k","5.15","7.60","15.40","14.86"
    "256k","13.20","2.00","91.00","4.23"

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|

USB Driver
----------

USB Host Controller
^^^^^^^^^^^^^^^^^^^

.. warning::

  **IMPORTANT**: For Mass-storage applications, the performance numbers can be severely
  affected if the media is mounted in sync mode. Hot plug scripts in the
  filesystem mount removable media in sync mode to ensure data
  integrity. For performance sensitive applications, umount the
  auto-mounted filesystem and re-mount in async mode.

**Setup** : Inateck ASM1153E USB hard disk is
connected to usb0 port. File read/write performance data on usb0 port is
captured.

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","37.00","5.40","38.10","4.92"
    "4m","38.40","5.19","38.20","4.70"
    "4k","18.40","25.75","18.60","21.51"
    "256k","37.30","7.57","37.20","6.35"
