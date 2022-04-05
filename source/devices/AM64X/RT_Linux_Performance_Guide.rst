===========================
 RT-linux Performance Guide
===========================

.. rubric::  **Read This First**

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+---------------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                         |
+================+=====================================================================================================================+
| AM64x EVM      | AM64x Evaluation Module rev E1 with ARM running at 1GHz, DDRdata rate 1600 MT/S                                     |
+----------------+---------------------------------------------------------------------------------------------------------------------+

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

    "af_unix_sock_stream_latency (microsec)","48.84"
    "af_unix_socket_stream_bandwidth (MBs)","728.12"
    "bw_file_rd-io-1mb (MB/s)","806.19"
    "bw_file_rd-o2c-1mb (MB/s)","480.23"
    "bw_mem-bcopy-16mb (MB/s)","855.07"
    "bw_mem-bcopy-1mb (MB/s)","933.88"
    "bw_mem-bcopy-2mb (MB/s)","910.61"
    "bw_mem-bcopy-4mb (MB/s)","916.91"
    "bw_mem-bcopy-8mb (MB/s)","927.75"
    "bw_mem-bzero-16mb (MB/s)","2124.55"
    "bw_mem-bzero-1mb (MB/s)","1494.60 (min 933.88, max 2055.31)"
    "bw_mem-bzero-2mb (MB/s)","1518.76 (min 910.61, max 2126.91)"
    "bw_mem-bzero-4mb (MB/s)","1519.65 (min 916.91, max 2122.39)"
    "bw_mem-bzero-8mb (MB/s)","1526.29 (min 927.75, max 2124.83)"
    "bw_mem-cp-16mb (MB/s)","524.49"
    "bw_mem-cp-1mb (MB/s)","1535.18 (min 570.88, max 2499.48)"
    "bw_mem-cp-2mb (MB/s)","1377.74 (min 566.49, max 2188.98)"
    "bw_mem-cp-4mb (MB/s)","1385.62 (min 562.51, max 2208.72)"
    "bw_mem-cp-8mb (MB/s)","1375.83 (min 611.48, max 2140.18)"
    "bw_mem-fcp-16mb (MB/s)","799.80"
    "bw_mem-fcp-1mb (MB/s)","1437.76 (min 820.21, max 2055.31)"
    "bw_mem-fcp-2mb (MB/s)","1486.35 (min 845.79, max 2126.91)"
    "bw_mem-fcp-4mb (MB/s)","1480.84 (min 839.28, max 2122.39)"
    "bw_mem-fcp-8mb (MB/s)","1517.27 (min 909.71, max 2124.83)"
    "bw_mem-frd-16mb (MB/s)","1269.84"
    "bw_mem-frd-1mb (MB/s)","1087.50 (min 820.21, max 1354.78)"
    "bw_mem-frd-2mb (MB/s)","1090.34 (min 845.79, max 1334.89)"
    "bw_mem-frd-4mb (MB/s)","1093.50 (min 839.28, max 1347.71)"
    "bw_mem-frd-8mb (MB/s)","1147.14 (min 909.71, max 1384.56)"
    "bw_mem-fwr-16mb (MB/s)","2008.28"
    "bw_mem-fwr-1mb (MB/s)","1927.13 (min 1354.78, max 2499.48)"
    "bw_mem-fwr-2mb (MB/s)","1761.94 (min 1334.89, max 2188.98)"
    "bw_mem-fwr-4mb (MB/s)","1778.22 (min 1347.71, max 2208.72)"
    "bw_mem-fwr-8mb (MB/s)","1762.37 (min 1384.56, max 2140.18)"
    "bw_mem-rd-16mb (MB/s)","1394.58"
    "bw_mem-rd-1mb (MB/s)","1174.32 (min 947.33, max 1401.30)"
    "bw_mem-rd-2mb (MB/s)","1138.22 (min 870.45, max 1405.98)"
    "bw_mem-rd-4mb (MB/s)","1129.88 (min 878.06, max 1381.69)"
    "bw_mem-rd-8mb (MB/s)","1159.21 (min 912.93, max 1405.48)"
    "bw_mem-rdwr-16mb (MB/s)","904.57"
    "bw_mem-rdwr-1mb (MB/s)","689.97 (min 570.88, max 809.06)"
    "bw_mem-rdwr-2mb (MB/s)","705.07 (min 566.49, max 843.64)"
    "bw_mem-rdwr-4mb (MB/s)","729.19 (min 562.51, max 895.86)"
    "bw_mem-rdwr-8mb (MB/s)","741.76 (min 611.48, max 872.03)"
    "bw_mem-wr-16mb (MB/s)","948.88"
    "bw_mem-wr-1mb (MB/s)","878.20 (min 809.06, max 947.33)"
    "bw_mem-wr-2mb (MB/s)","857.05 (min 843.64, max 870.45)"
    "bw_mem-wr-4mb (MB/s)","886.96 (min 878.06, max 895.86)"
    "bw_mem-wr-8mb (MB/s)","892.48 (min 872.03, max 912.93)"
    "bw_mmap_rd-mo-1mb (MB/s)","1333.08"
    "bw_mmap_rd-o2c-1mb (MB/s)","476.80"
    "bw_pipe (MB/s)","263.01"
    "bw_unix (MB/s)","728.12"
    "lat_connect (us)","91.69"
    "lat_ctx-2-128k (us)","8.94"
    "lat_ctx-2-256k (us)","19.02"
    "lat_ctx-4-128k (us)","10.20"
    "lat_ctx-4-256k (us)","0.30"
    "lat_fs-0k (num_files)","189.00"
    "lat_fs-10k (num_files)","77.00"
    "lat_fs-1k (num_files)","101.00"
    "lat_fs-4k (num_files)","103.00"
    "lat_mem_rd-stride128-sz1000k (ns)","46.67"
    "lat_mem_rd-stride128-sz125k (ns)","7.80"
    "lat_mem_rd-stride128-sz250k (ns)","14.82"
    "lat_mem_rd-stride128-sz31k (ns)","5.87"
    "lat_mem_rd-stride128-sz50 (ns)","3.01"
    "lat_mem_rd-stride128-sz500k (ns)","43.11"
    "lat_mem_rd-stride128-sz62k (ns)","7.31"
    "lat_mmap-1m (us)","62.00"
    "lat_ops-double-add (ns)","0.73"
    "lat_ops-double-mul (ns)","4.02"
    "lat_ops-float-add (ns)","0.73"
    "lat_ops-float-mul (ns)","4.01"
    "lat_ops-int-add (ns)","1.01"
    "lat_ops-int-bit (ns)","0.67"
    "lat_ops-int-div (ns)","6.02"
    "lat_ops-int-mod (ns)","6.36"
    "lat_ops-int-mul (ns)","3.08"
    "lat_ops-int64-add (ns)","1.01"
    "lat_ops-int64-bit (ns)","0.67"
    "lat_ops-int64-div (ns)","9.54"
    "lat_ops-int64-mod (ns)","7.36"
    "lat_pagefault (us)","1.87"
    "lat_pipe (us)","27.33"
    "lat_proc-exec (us)","1934.67"
    "lat_proc-fork (us)","1579.25"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","42.42"
    "lat_sem (us)","4.00"
    "lat_sig-catch (us)","7.96"
    "lat_sig-install (us)","0.82"
    "lat_sig-prot (us)","0.09"
    "lat_syscall-fstat (us)","1.95"
    "lat_syscall-null (us)","0.40"
    "lat_syscall-open (us)","424.14"
    "lat_syscall-read (us)","0.78"
    "lat_syscall-stat (us)","5.22"
    "lat_syscall-write (us)","0.64"
    "lat_tcp (us)","0.81"
    "lat_unix (us)","48.84"
    "latency_for_0.50_mb_block_size (nanosec)","43.11"
    "latency_for_1.00_mb_block_size (nanosec)","23.33 (min 0.00, max 46.67)"
    "pipe_bandwidth (MBs)","263.01"
    "pipe_latency (microsec)","27.33"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","42.42"
    "semaphore_latency (microsec)","4.00"
    "signal_handler_latency (microsec)","0.82"
    "signal_handler_overhead (microsec)","7.96"
    "tcp_ip_connection_cost_to_localhost (microsec)","91.69"
    "tcp_latency_using_localhost (microsec)","0.81"



Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^

Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "cpu_clock (MHz)","1000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.78"
    "dhrystone_per_second (DhrystoneP)","4878049.00"

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

    "linpack (Kflops)","414804.00"

Table:  **Linpack Benchmark**

NBench
^^^^^^

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "assignment (Iterations)","9.74"
    "fourier (Iterations)","16325.00"
    "fp_emulation (Iterations)","76.50"
    "huffman (Iterations)","837.96"
    "idea (Iterations)","2452.40"
    "lu_decomposition (Iterations)","390.72"
    "neural_net (Iterations)","5.60"
    "numeric_sort (Iterations)","360.07"
    "string_sort (Iterations)","118.37"


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

    "add (MB/s)","1674.90"
    "copy (MB/s)","1961.50"
    "scale (MB/s)","2322.40"
    "triad (MB/s)","1683.70"


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

    "cjpeg-rose7-preset (workloads/)","29.59"
    "core (workloads/)","0.21"
    "coremark-pro ()","594.23"
    "linear_alg-mid-100x100-sp (workloads/)","10.47"
    "loops-all-mid-10k-sp (workloads/)","0.49"
    "nnet_test (workloads/)","0.78"
    "parser-125k (workloads/)","5.95"
    "radix2-big-64k (workloads/)","19.47"
    "sha-test (workloads/)","58.14"
    "zip-test (workloads/)","15.63"


Table:  **CoreMarkPro**

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "cjpeg-rose7-preset (workloads/)","56.18"
    "core (workloads/)","0.43"
    "coremark-pro ()","1044.46"
    "linear_alg-mid-100x100-sp (workloads/)","20.90"
    "loops-all-mid-10k-sp (workloads/)","0.89"
    "nnet_test (workloads/)","1.54"
    "parser-125k (workloads/)","5.88"
    "radix2-big-64k (workloads/)","31.35"
    "sha-test (workloads/)","114.94"
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

    "4m-check (workloads/)","321.09"
    "4m-check-reassembly (workloads/)","61.61"
    "4m-check-reassembly-tcp (workloads/)","37.71"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","14.98"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","0.77"
    "4m-cmykw2 (workloads/)","86.99"
    "4m-cmykw2-rotatew2 (workloads/)","18.35"
    "4m-reassembly (workloads/)","51.31"
    "4m-rotatew2 (workloads/)","22.49"
    "4m-tcp-mixed (workloads/)","86.02"
    "4m-x264w2 (workloads/)","0.76"
    "empty-wld (workloads/)","1.00"
    "idct-4m (workloads/)","13.69"
    "idct-4mw1 (workloads/)","13.70"
    "ippktcheck-4m (workloads/)","321.54"
    "ippktcheck-4mw1 (workloads/)","321.21"
    "ipres-4m (workloads/)","69.03"
    "ipres-4mw1 (workloads/)","70.06"
    "md5-4m (workloads/)","18.89"
    "md5-4mw1 (workloads/)","19.10"
    "rgbcmyk-4m (workloads/)","44.60"
    "rgbcmyk-4mw1 (workloads/)","44.51"
    "rotate-4ms1 (workloads/)","17.04"
    "rotate-4ms1w1 (workloads/)","17.06"
    "rotate-4ms64 (workloads/)","17.32"
    "rotate-4ms64w1 (workloads/)","17.28"
    "x264-4mq (workloads/)","0.41"
    "x264-4mqw1 (workloads/)","0.41"


Table:  **Multibench**

|

Spec2K6
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CPU2006 is a set of benchmarks designed to test the CPU performance of a modern server
computer system. It is split into two components, the first being CINT2006,
the other being CFP2006 (SPECfp), for floating point testing.

SPEC defines a base runtime for each of the 12 benchmark programs.
For SPECint2006, that number ranges from 1000 to 3000 seconds. The timed test is run on
the system, and the time of the test system is compared to the reference time, and a ratio
is computed. That ratio becomes the SPECint score for that test. (This differs from the rating
in SPECINT2000, which multiplies the ratio by 100.)

As an example for SPECint2006, consider a processor which can run 400.perlbench in 2000 seconds.
The time it takes the reference machine to run the benchmark is 9770 seconds. Thus the ratio is 4.885.
Each ratio is computed, and then the geometric mean of those ratios is computed to produce an overall value.

Rate (Multiple Cores)

Table:  **Spec2K6**

Speed (Single Core)

Table:  **Spec2K6 Speed**

Maximum Latency under different use cases
------------------------------------------

Shield (dedicated core) Case
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
| The following tests measure worst-case latency under different
 scenarios or use cases.
| Cyclictest application was used to measured latency. Each test ran for
 4 hours.
| Two cgroups were used using shield\_shell procedure shown below.
| The application running the use case and cyclictest ran on a dedicated
 cpu (rt) while the rest of threads ran on nonrt cpu.

::

   shield_shell()
   {
   create_cgroup nonrt 0
   create_cgroup rt 1
   for pid in $(cat /sys/fs/cgroup/tasks); do /bin/echo $pid > /sys/fs/cgroup/nonrt/tasks; done
   /bin/echo $$ > /sys/fs/cgroup/rt/tasks
   }

|


AM64XX-EVM
"""""""""""""""""""""""""""""""

.. csv-table::
    :header: "Benchmarks","Core #1 (nonrt)","Core#2 (rt)"

    "Min Latencies","6", "6"
    "Avg Latencies","8", "8"
    "Max Latencies","92", "71"

Table:  **Cyclic test for Two Cores**

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am64xx-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","28.74 (min 25.63, max 28.45)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","3.43 (min 4.26, max 4.36)"

Table:  **Boot time MMC/SD**

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
  :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table::
   :header: "Command Used","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)"

   "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1003.18","97.44"

Table: **CPSW TCP Bidirectional Throughput**

|

.. rubric::  UDP Throughput 
  :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
   :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","7.50","88.54"
    "128","82.00","33.61","88.19"
    "256","210.00","84.73","87.81"
    "512","466.00","182.98","86.81"
    "1024","978.00","372.33","85.16"
    "1518","1472.00","560.30","85.93"

Table: **CPSW UDP Egress Throughput**

|

.. csv-table::
   :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.22","15.10"
    "128","82.00","5.64","11.30"
    "256","210.00","15.79","16.78"
    "512","466.00","38.02","17.47"
    "1024","978.00","79.80","4.94"
    "1518","1472.00","122.46","17.74"

Table: **CPSW UDP Ingress Throughput (0% loss)**

|

.. csv-table::
   :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","am64xx-evm: Packet Loss %"

    "64","18.00","19.66","80.99","1.07"
    "128","82.00","90.46","82.42","62.72"
    "256","210.00","225.19","85.33","36.56"
    "512","466.00","485.34","86.95","35.07"
    "1024","978.00","930.98","90.21","0.60"
    "1518","1472.00","910.66","84.39","4.78"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|

PCIe Driver
-----------

PCIe-NVMe-SSD
^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","368.00","19.03","398.00","14.78"
    "4m","382.00","17.83","398.00","13.77"
    "4k","66.70","52.09","84.20","49.21"
    "256k","374.00","27.14","397.00","15.91"


- Filesize used is: 10G
- FIO command options: --ioengine=libaio --iodepth=4 --numjobs=1 --direct=1 --runtime=60 --time_base
- Platform: Speed 8GT/s, Width x1
- SSD being used: Lite-On Technology Corporation M8Pe Series NVMe SSD [14a4:22f1] (rev 01)

|

OSPI Flash Driver
-----------------

UBIFS
^^^^^^^^^^^^^^^^^

.. csv-table::
   :header: "Buffer size (bytes)","am64xx-evm: Write UBIFS Throughput (Mbytes/sec)","am64xx-evm: Write UBIFS CPU Load (%)","am64xx-evm: Read UBIFS Throughput (Mbytes/sec)","am64xx-evm: Read UBIFS CPU Load (%)"

    "102400","0.16 (min 0.11, max 0.26)","64.31 (min 62.59, max 66.37)","35.34","83.33"
    "262144","0.13 (min 0.12, max 0.15)","65.30 (min 63.01, max 68.79)","45.04","55.56"
    "524288","0.13 (min 0.12, max 0.16)","65.59 (min 62.82, max 68.48)","43.77","37.50"
    "1048576","0.13 (min 0.12, max 0.15)","66.47 (min 63.93, max 68.23)","43.11","50.00"

RAW
^^^^^^^^^^^^^^^^^^^

.. csv-table::
   :header: "File size (Mbytes)","am64xx-evm: Raw Read Throughput (Mbytes/sec)"

    "50","108.69"

|

EMMC Driver
-------------------------

.. warning::

 **IMPORTANT**: The performance numbers can be severely affected if the media is
 mounted in sync mode. Hot plug scripts in the filesystem mount
 removable media in sync mode to ensure data integrity. For performance
 sensitive applications, umount the auto-mounted filesystem and
 re-mount in async mode.

|

.. csv-table::
   :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","59.60","4.83","312.00","13.99"
    "4m","59.70","3.38","312.00","11.87"
    "4k","40.50","55.79","54.80","65.79"
    "256k","59.50","7.16","309.00","16.45"

|

MMC/SD Driver
-------------------------

.. warning::

 **IMPORTANT**: The performance numbers can be severely affected if the media is
 mounted in sync mode. Hot plug scripts in the filesystem mount
 removable media in sync mode to ensure data integrity. For performance
 sensitive applications, umount the auto-mounted filesystem and
 re-mount in async mode.

|

.. csv-table::
   :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","19.00","2.43","85.20","5.22"
    "4m","18.00","2.25","85.70","3.96"
    "4k","4.97","11.52","16.60","20.44"
    "256k","18.50","3.39","82.60","6.51"

|

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

    "1m","37.30","8.18","37.90","7.59"
    "4m","37.70","7.59","37.90","6.87"
    "4k","15.60","37.67","16.90","33.13"
    "256k","36.50","10.75","36.80","9.95"

|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

 Listed for each algorithm are the code snippets used to run each
 benchmark test.

|

::

   time -v openssl speed -elapsed -evp aes-128-cbc

IPSec Hardware Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Note: queue\_len is set to 300 and software fallback threshold set to 9
to enable software support for optimal performance

IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
   :header: "Algorithm","am64xx-evm: Throughput (Mbps)","am64xx-evm: Packets/Sec","am64xx-evm: CPU Load"

   "3des","52.30","4.00","50.30"

