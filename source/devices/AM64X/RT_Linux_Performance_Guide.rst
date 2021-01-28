**************************
RT-Linux Performance Guide
**************************

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

    "af_unix_sock_stream_latency (microsec)","42.48"
    "af_unix_socket_stream_bandwidth (MBs)","637.80"
    "bw_file_rd-io-1mb (MB/s)","828.16"
    "bw_file_rd-o2c-1mb (MB/s)","487.09"
    "bw_mem-bcopy-16mb (MB/s)","848.58"
    "bw_mem-bcopy-1mb (MB/s)","903.18"
    "bw_mem-bcopy-2mb (MB/s)","895.52"
    "bw_mem-bcopy-4mb (MB/s)","881.06"
    "bw_mem-bcopy-8mb (MB/s)","910.95"
    "bw_mem-bzero-16mb (MB/s)","2118.64"
    "bw_mem-bzero-1mb (MB/s)","1505.15 (min 903.18, max 2107.11)"
    "bw_mem-bzero-2mb (MB/s)","1505.96 (min 895.52, max 2116.40)"
    "bw_mem-bzero-4mb (MB/s)","1499.11 (min 881.06, max 2117.15)"
    "bw_mem-bzero-8mb (MB/s)","1514.66 (min 910.95, max 2118.36)"
    "bw_mem-cp-16mb (MB/s)","519.46"
    "bw_mem-cp-1mb (MB/s)","1414.33 (min 545.55, max 2283.11)"
    "bw_mem-cp-2mb (MB/s)","1366.91 (min 540.83, max 2192.98)"
    "bw_mem-cp-4mb (MB/s)","1345.48 (min 534.62, max 2156.33)"
    "bw_mem-cp-8mb (MB/s)","1374.27 (min 606.34, max 2142.19)"
    "bw_mem-fcp-16mb (MB/s)","812.02"
    "bw_mem-fcp-1mb (MB/s)","1451.77 (min 796.43, max 2107.11)"
    "bw_mem-fcp-2mb (MB/s)","1495.97 (min 875.53, max 2116.40)"
    "bw_mem-fcp-4mb (MB/s)","1437.94 (min 758.73, max 2117.15)"
    "bw_mem-fcp-8mb (MB/s)","1509.53 (min 900.70, max 2118.36)"
    "bw_mem-frd-16mb (MB/s)","1372.21"
    "bw_mem-frd-1mb (MB/s)","1047.09 (min 796.43, max 1297.74)"
    "bw_mem-frd-2mb (MB/s)","1084.91 (min 875.53, max 1294.29)"
    "bw_mem-frd-4mb (MB/s)","1070.45 (min 758.73, max 1382.17)"
    "bw_mem-frd-8mb (MB/s)","1131.44 (min 900.70, max 1362.17)"
    "bw_mem-fwr-16mb (MB/s)","2127.94"
    "bw_mem-fwr-1mb (MB/s)","1790.43 (min 1297.74, max 2283.11)"
    "bw_mem-fwr-2mb (MB/s)","1743.64 (min 1294.29, max 2192.98)"
    "bw_mem-fwr-4mb (MB/s)","1769.25 (min 1382.17, max 2156.33)"
    "bw_mem-fwr-8mb (MB/s)","1752.18 (min 1362.17, max 2142.19)"
    "bw_mem-rd-16mb (MB/s)","1359.50"
    "bw_mem-rd-1mb (MB/s)","1143.76 (min 913.41, max 1374.10)"
    "bw_mem-rd-2mb (MB/s)","1111.64 (min 834.38, max 1388.89)"
    "bw_mem-rd-4mb (MB/s)","1101.35 (min 839.37, max 1363.33)"
    "bw_mem-rd-8mb (MB/s)","1142.78 (min 892.56, max 1393.00)"
    "bw_mem-rdwr-16mb (MB/s)","916.59"
    "bw_mem-rdwr-1mb (MB/s)","716.91 (min 545.55, max 888.26)"
    "bw_mem-rdwr-2mb (MB/s)","649.01 (min 540.83, max 757.19)"
    "bw_mem-rdwr-4mb (MB/s)","680.71 (min 534.62, max 826.79)"
    "bw_mem-rdwr-8mb (MB/s)","746.19 (min 606.34, max 886.03)"
    "bw_mem-wr-16mb (MB/s)","928.88"
    "bw_mem-wr-1mb (MB/s)","900.84 (min 888.26, max 913.41)"
    "bw_mem-wr-2mb (MB/s)","795.79 (min 757.19, max 834.38)"
    "bw_mem-wr-4mb (MB/s)","833.08 (min 826.79, max 839.37)"
    "bw_mem-wr-8mb (MB/s)","889.30 (min 886.03, max 892.56)"
    "bw_mmap_rd-mo-1mb (MB/s)","1278.98"
    "bw_mmap_rd-o2c-1mb (MB/s)","503.27"
    "bw_pipe (MB/s)","285.86"
    "bw_unix (MB/s)","637.80"
    "lat_connect (us)","81.06"
    "lat_ctx-2-128k (us)","4.45"
    "lat_ctx-2-256k (us)","16.11"
    "lat_ctx-4-128k (us)","5.57"
    "lat_ctx-4-256k (us)","3.02"
    "lat_fs-0k (num_files)","208.00"
    "lat_fs-10k (num_files)","83.00"
    "lat_fs-1k (num_files)","140.00"
    "lat_fs-4k (num_files)","132.00"
    "lat_mem_rd-stride128-sz1000k (ns)","47.18"
    "lat_mem_rd-stride128-sz125k (ns)","7.93"
    "lat_mem_rd-stride128-sz250k (ns)","14.59"
    "lat_mem_rd-stride128-sz31k (ns)","3.04"
    "lat_mem_rd-stride128-sz50 (ns)","3.01"
    "lat_mem_rd-stride128-sz500k (ns)","42.96"
    "lat_mem_rd-stride128-sz62k (ns)","7.34"
    "lat_mmap-1m (us)","63.00"
    "lat_ops-double-add (ns)","0.73"
    "lat_ops-double-mul (ns)","4.02"
    "lat_ops-float-add (ns)","0.73"
    "lat_ops-float-mul (ns)","4.02"
    "lat_ops-int-add (ns)","1.01"
    "lat_ops-int-bit (ns)","0.67"
    "lat_ops-int-div (ns)","6.04"
    "lat_ops-int-mod (ns)","6.38"
    "lat_ops-int-mul (ns)","3.05"
    "lat_ops-int64-add (ns)","1.01"
    "lat_ops-int64-bit (ns)","0.67"
    "lat_ops-int64-div (ns)","9.55"
    "lat_ops-int64-mod (ns)","7.40"
    "lat_pagefault (us)","1.70"
    "lat_pipe (us)","20.64"
    "lat_proc-exec (us)","1494.25"
    "lat_proc-fork (us)","1332.00"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","44.32"
    "lat_sem (us)","2.39"
    "lat_sig-catch (us)","8.20"
    "lat_sig-install (us)","0.81"
    "lat_sig-prot (us)","0.36"
    "lat_syscall-fstat (us)","2.00"
    "lat_syscall-null (us)","0.38"
    "lat_syscall-open (us)","379.40"
    "lat_syscall-read (us)","0.94"
    "lat_syscall-stat (us)","5.88"
    "lat_syscall-write (us)","0.61"
    "lat_tcp (us)","0.65"
    "lat_unix (us)","42.48"
    "latency_for_0.50_mb_block_size (nanosec)","42.96"
    "latency_for_1.00_mb_block_size (nanosec)","23.59 (min 0.00, max 47.18)"
    "pipe_bandwidth (MBs)","285.86"
    "pipe_latency (microsec)","20.64"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","44.32"
    "semaphore_latency (microsec)","2.39"
    "signal_handler_latency (microsec)","0.81"
    "signal_handler_overhead (microsec)","8.20"
    "tcp_ip_connection_cost_to_localhost (microsec)","81.06"
    "tcp_latency_using_localhost (microsec)","0.65"

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

    "whetstone (MIPS)","2500.00"

Table:  **Whetstone Benchmark**

Linpack
^^^^^^^

Linpack measures peak double precision (64 bit) floating point performance in
sloving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "linpack (Kflops)","363527.00"

Table:  **Linpack Benchmark**

NBench
^^^^^^
.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "assignment (Iterations)","9.71"
    "fourier (Iterations)","16215.00"
    "fp_emulation (Iterations)","76.44"
    "huffman (Iterations)","837.28"
    "idea (Iterations)","2450.20"
    "lu_decomposition (Iterations)","387.20"
    "neural_net (Iterations)","5.60"
    "numeric_sort (Iterations)","329.90"
    "string_sort (Iterations)","115.65"

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

    "add (MB/s)","1664.60"
    "copy (MB/s)","2291.60"
    "scale (MB/s)","2326.20"
    "triad (MB/s)","1659.20"

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

    "cjpeg-rose7-preset (workloads/)","29.76"
    "core (workloads/)","0.21"
    "coremark-pro ()","588.29"
    "linear_alg-mid-100x100-sp (workloads/)","10.44"
    "loops-all-mid-10k-sp (workloads/)","0.48"
    "nnet_test (workloads/)","0.78"
    "parser-125k (workloads/)","5.65"
    "radix2-big-64k (workloads/)","19.18"
    "sha-test (workloads/)","57.80"
    "zip-test (workloads/)","15.63"

Table:  **CoreMarkPro**

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "cjpeg-rose7-preset (workloads/)","41.49"
    "core (workloads/)","0.42"
    "coremark-pro ()","975.19"
    "linear_alg-mid-100x100-sp (workloads/)","20.62"
    "loops-all-mid-10k-sp (workloads/)","0.88"
    "nnet_test (workloads/)","1.55"
    "parser-125k (workloads/)","5.31"
    "radix2-big-64k (workloads/)","31.29"
    "sha-test (workloads/)","97.09"
    "zip-test (workloads/)","28.57"

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

    "4m-check (workloads/)","328.86"
    "4m-check-reassembly (workloads/)","61.65"
    "4m-check-reassembly-tcp (workloads/)","37.76"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","2.29"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","0.76"
    "4m-cmykw2 (workloads/)","88.30"
    "4m-cmykw2-rotatew2 (workloads/)","18.30"
    "4m-reassembly (workloads/)","51.20"
    "4m-rotatew2 (workloads/)","4.24"
    "4m-tcp-mixed (workloads/)","11.98"
    "4m-x264w2 (workloads/)","0.10"
    "empty-wld (workloads/)","1.00"
    "idct-4m (workloads/)","13.67"
    "idct-4mw1 (workloads/)","3.93"
    "ippktcheck-4m (workloads/)","330.30"
    "ippktcheck-4mw1 (workloads/)","84.51"
    "ipres-4m (workloads/)","17.40"
    "ipres-4mw1 (workloads/)","68.49"
    "md5-4m (workloads/)","19.67"
    "md5-4mw1 (workloads/)","3.52"
    "rgbcmyk-4m (workloads/)","44.25"
    "rgbcmyk-4mw1 (workloads/)","44.18"
    "rotate-4ms1 (workloads/)","16.93"
    "rotate-4ms1w1 (workloads/)","4.41"
    "rotate-4ms64 (workloads/)","17.09"
    "rotate-4ms64w1 (workloads/)","17.15"
    "x264-4mq (workloads/)","0.21"
    "x264-4mqw1 (workloads/)","0.41"

Table:  **Multibench**

|

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

    "Default","1138.84","97.54"

Table: **CPSW TCP Bidirectional Throughput**

.. rubric::  UDP Throughput (0% loss) 
   
.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes)","am64xx-evm: Throughput (Mbits/sec)","am64xx-evm: CPU Load %"

    "64","18.00","7.62","83.18"
    "128","82.00","39.94","85.67"
    "256","210.00","114.18","89.27"
    "1024","978.00","377.41","81.34"
    "1518","1472.00","558.31","80.77"

Table: **CPSW UDP Egress Throughput (0% loss)**
   
.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes)","am64xx-evm: Throughput (Mbits/sec)","am64xx-evm: CPU Load %"

    "64","18.00","1.22","5.53"
    "128","82.00","6.89","15.68"
    "256","210.00","12.10","4.93"
    "1024","978.00","83.71","5.37"
    "1518","1472.00","122.47","17.93"

Table: **CPSW UDP Ingress Throughput (0% loss)**

.. rubric::  UDP Throughput (possible loss) 

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes)","am64xx-evm: Throughput (Mbits/sec)","am64xx-evm: CPU Load %","am64xx-evm: Packet Loss %"

    "64","18.00","7.62","83.18","0.00"
    "128","82.00","41.97","87.16","0.01"
    "256","210.00","114.18","89.27","0.00"
    "1024","978.00","377.41","81.34","0.00"
    "1518","1472.00","558.31","80.77","0.00"

Table: **CPSW UDP Egress Throughput (possible loss)**

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes)","am64xx-evm: Throughput (Mbits/sec)","am64xx-evm: CPU Load %","am64xx-evm: Packet Loss %"

    "64","18.00","19.62","78.63","19.94"
    "128","82.00","73.42","73.47","59.63"
    "256","210.00","221.92","81.67","52.54"
    "1024","978.00","932.24","86.76","0.47"
    "1518","1472.00","933.00","77.62","2.51"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|

PCIe Driver
-----------

PCIe-NVMe-SSD
^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","364.00","19.28","398.00","16.07"
    "4m","360.00","17.75","398.00","14.64"
    "4k","68.90","52.36","92.00","56.25"
    "256k","362.00","21.93","397.00","17.10"

- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_based 
- Platform: Speed 8GT/s, Width x1
- SSD being used: Lite-On Technology Corporation M8Pe Series NVMe SSD [14a4:22f1] (rev 01)

|

OSPI Flash Driver
-----------------

UBIFS
^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write UBIFS Throughput (Mbytes/sec)","am64xx-evm: Write UBIFS CPU Load (%)","am64xx-evm: Read UBIFS Throughput (Mbytes/sec)","am64xx-evm: Read UBIFS CPU Load (%)"

    "102400","0.18 (min 0.12, max 0.30)","56.26 (min 55.95, max 56.65)","51.24","42.86"
    "262144","0.14 (min 0.11, max 0.19)","57.00 (min 56.75, max 57.19)","48.99","55.56"
    "524288","0.16 (min 0.11, max 0.19)","56.39 (min 55.94, max 56.86)","48.95","42.86"
    "1048576","0.15 (min 0.11, max 0.19)","56.27 (min 55.20, max 56.87)","47.26","55.56"

|

RAW
^^^

.. csv-table::
    :header: "File size (Mbytes)","am64xx-evm: Raw Read Throughput (Mbytes/sec)"

    "50","34.72"

|

EMMC Driver
-----------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.


.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","58.30","4.81","312.00","13.89"
    "4m","58.40","3.50","312.00","12.26"
    "4k","49.80","59.24","54.90","65.89"
    "256k","58.40","6.89","311.00","17.36"

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

    "1m","13.30","1.90","92.10","5.52"
    "4m","15.60","1.75","91.60","4.45"
    "4k","5.04","11.82","15.60","22.99"
    "256k","12.00","2.52","88.00","7.80"

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

**Setup** : SAMSUNG 850 PRO 2.5" 128GB SATA III Internal Solid State Drive (SSD) used with Inateck ASM1153E enclosure is
connected to usb port under test. File read/write performance data is captured.

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","37.60","7.79","37.80","7.60"
    "4m","37.70","7.33","37.60","6.75"
    "4k","17.20","38.01","17.20","31.91"
    "256k","36.50","9.18","36.50","8.59"

