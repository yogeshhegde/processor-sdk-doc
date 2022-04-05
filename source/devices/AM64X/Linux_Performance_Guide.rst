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

    "af_unix_sock_stream_latency (microsec)","41.18"
    "af_unix_socket_stream_bandwidth (MB/s)","567.49"
    "bw_file_rd-io-1mb (MB/s)","1038.96"
    "bw_file_rd-o2c-1mb (MB/s)","589.88"
    "bw_mem-bcopy-16mb (MB/s)","890.92"
    "bw_mem-bcopy-1mb (MB/s)","850.46"
    "bw_mem-bcopy-2mb (MB/s)","891.40"
    "bw_mem-bcopy-4mb (MB/s)","905.49"
    "bw_mem-bcopy-8mb (MB/s)","909.92"
    "bw_mem-bzero-16mb (MB/s)","2126.53"
    "bw_mem-bzero-1mb (MB/s)","1488.12 (min 865.65, max 2125.78)"
    "bw_mem-bzero-2mb (MB/s)","1511.04 (min 865.68, max 2125.40)"
    "bw_mem-bzero-4mb (MB/s)","1516.39 (min 899.18, max 2127.66)"
    "bw_mem-bzero-8mb (MB/s)","1518.37 (min 906.72, max 2126.81)"
    "bw_mem-cp-16mb (MB/s)","603.20"
    "bw_mem-cp-1mb (MB/s)","1442.93 (min 596.21, max 2289.64)"
    "bw_mem-cp-2mb (MB/s)","1396.60 (min 597.01, max 2196.19)"
    "bw_mem-cp-4mb (MB/s)","1382.78 (min 601.05, max 2164.50)"
    "bw_mem-cp-8mb (MB/s)","1374.86 (min 600.33, max 2149.38)"
    "bw_mem-fcp-16mb (MB/s)","865.19"
    "bw_mem-fcp-1mb (MB/s)","1473.20 (min 820.61, max 2125.78"
    "bw_mem-fcp-2mb (MB/s)","1490.33 (min 849.98, max 2130.68)"
    "bw_mem-fcp-4mb (MB/s)","1491.22 (min 855.16, max 2127.28)"
    "bw_mem-fcp-8mb (MB/s)","1481.86 (min 836.91, max 2126.81)"
    "bw_mem-frd-16mb (MB/s)","1506.45"
    "bw_mem-frd-1mb (MB/s)","1128.05 (min 820.61, max 1435.49)"
    "bw_mem-frd-2mb (MB/s)","1143.00 (min 849.98, max 1436.01)"
    "bw_mem-frd-4mb (MB/s)","1172.05 (min 855.16, max 1488.93)"
    "bw_mem-frd-8mb (MB/s)","1160.78 (min 836.91, max 1484.64"
    "bw_mem-fwr-16mb (MB/s)","2145.63"
    "bw_mem-fwr-1mb (MB/s)","1862.57 (min 1435.49, max 2289.64)"
    "bw_mem-fwr-2mb (MB/s)","1816.10 (min 1436.01, max 2196.19)"
    "bw_mem-fwr-4mb (MB/s)","1826.72 (min 1488.93, max 2164.50)"
    "bw_mem-fwr-8mb (MB/s)","1817.01 (min 1484.64, max 2149.38)"
    "bw_mem-rd-16mb (MB/s)","1506.73"
    "bw_mem-rd-1mb (MB/s)","1188.93 (min 918.27, max 1459.59)"
    "bw_mem-rd-2mb (MB/s)","1263.75 (min 1020.06, max 1507.44)"
    "bw_mem-rd-4mb (MB/s)","1280.77 (min 1063.12, max 1498.41)"
    "bw_mem-rd-8mb (MB/s)","1327.10 (min 1156.07, max 1498.13)"
    "bw_mem-rdwr-16mb (MB/s)","1103.22"
    "bw_mem-rdwr-1mb (MB/s)","762.71 (min 596.21, max 929.20)"
    "bw_mem-rdwr-2mb (MB/s)","807.07 (min 597.01, max 1017.12)"
    "bw_mem-rdwr-4mb (MB/s)","826.43 (min 601.05, max 1051.80)"
    "bw_mem-rdwr-8mb (MB/s)","843.20 (min 600.33, max 1086.07)"
    "bw_mem-wr-16mb (MB/s)","1169.33"
    "bw_mem-wr-1mb (MB/s)","923.74 (min 918.27, max 929.20)"
    "bw_mem-wr-2mb (MB/s)","1018.59 (min 1017.12, max 1020.06)"
    "bw_mem-wr-4mb (MB/s)","1057.46 (min 1051.80, max 1063.12)"
    "bw_mem-wr-8mb (MB/s)","1121.07 (min 1086.07, max 1156.07)"
    "bw_mmap_rd-mo-1mb (MB/s)","1347.03"
    "bw_mmap_rd-o2c-1mb (MB/s)","661.49"
    "bw_pipe (MB/s)","742.96"
    "bw_unix (MB/s)","567.49"
    "lat_connect (us)","62.94"
    "lat_ctx-2-128k (us)","28.43"
    "lat_ctx-2-256k (us)","73.96"
    "lat_ctx-4-128k (us)","53.04"
    "lat_ctx-4-256k (us)","61.31"
    "lat_fs-0k (num_files)","277.00"
    "lat_fs-10k (num_files)","77.00"
    "lat_fs-1k (num_files)","82.00"
    "lat_fs-4k (num_files)","85.00"
    "lat_mem_rd-stride128-sz1000k (ns)","41.93"
    "lat_mem_rd-stride128-sz125k (ns)","7.56"
    "lat_mem_rd-stride128-sz250k (ns)","8.15"
    "lat_mem_rd-stride128-sz31k (ns)","3.03"
    "lat_mem_rd-stride128-sz50 (ns)","3.01"
    "lat_mem_rd-stride128-sz500k (ns)","36.73"
    "lat_mem_rd-stride128-sz62k (ns)","6.41"
    "lat_mmap-1m (us)","22.00"
    "lat_ops-double-add (ns)","0.73"
    "lat_ops-double-mul (ns)","4.01"
    "lat_ops-float-add (ns)","0.73"
    "lat_ops-float-mul (ns)","4.01"
    "lat_ops-int-add (ns)","1.00"
    "lat_ops-int-bit (ns)","0.67"
    "lat_ops-int-div (ns)","6.01"
    "lat_ops-int-mod (ns)","6.35"
    "lat_ops-int-mul (ns)","3.04"
    "lat_ops-int64-add (ns)","1.00"
    "lat_ops-int64-bit (ns)","0.67"
    "lat_ops-int64-div (ns)","9.53"
    "lat_ops-int64-mod (ns)","7.35"
    "lat_pagefault (us)","2.69"
    "lat_pipe (us)","24.98"
    "lat_proc-exec (us)","2091.67"
    "lat_proc-fork (us)","1733.25"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","47.84"
    "lat_sem (us)","3.19"
    "lat_sig-catch (us)","6.87"
    "lat_sig-install (us)","0.66"
    "lat_sig-prot (us)","0.60"
    "lat_syscall-fstat (us)","1.62"
    "lat_syscall-null (us)","0.40"
    "lat_syscall-open (us)","321.78"
    "lat_syscall-read (us)","0.77"
    "lat_syscall-stat (us)","4.80"
    "lat_syscall-write (us)","0.66"
    "lat_tcp (us)","0.81"
    "lat_unix (us)","41.18"
    "latency_for_0.50_mb_block_size (nanosec)","36.73"
    "latency_for_1.00_mb_block_size (nanosec)","20.97 (min 0.00, max 41.80)"
    "pipe_bandwidth (MBs)","742.96"
    "pipe_latency (microsec)","24.98"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","47.84"
    "semaphore_latency (microsec)","3.19"
    "signal_handler_latency (microsec)","0.66"
    "signal_handler_overhead (microsec)","6.87"
    "tcp_ip_connection_cost_to_localhost (microsec)","62.94"
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
    "dhrystone_per_mhz (DMIPS/MHz)","2.92"
    "dhrystone_per_second (DhrystoneP)","5128205.00"


Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "whetstone (MIPS)","5000.00"

Table:  **Whetstone Benchmark**

Linpack
^^^^^^^

Linpack measures peak double precision (64 bit) floating point performance in
sloving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "linpack (Kflops)","421061.00"

Table:  **Linpack Benchmark**

NBench
^^^^^^

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "assignment (Iterations)","9.76"
    "fourier (Iterations)","16329.00"
    "fp_emulation (Iterations)","76.53"
    "huffman (Iterations)","838.18"
    "idea (Iterations)","2453.00"
    "lu_decomposition (Iterations)","403.14"
    "neural_net (Iterations)","5.60"
    "numeric_sort (Iterations)","361.19"
    "string_sort (Iterations)","118.49"

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

    "add (MB/s)","1898.30"
    "copy (MB/s)","2499.60"
    "scale (MB/s)","2462.60"
    "triad (MB/s)","1918.50"


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

    "cjpeg-rose7-preset (workloads/)","29.67"
    "core (workloads/)","0.21"
    "coremark-pro ()","602.74"
    "linear_alg-mid-100x100-sp (workloads/)","10.50"
    "loops-all-mid-10k-sp (workloads/)","0.49"
    "nnet_test (workloads/)","0.78"
    "parser-125k (workloads/)","6.29"
    "radix2-big-64k (workloads/)","19.84"
    "sha-test (workloads/)","58.14"
    "zip-test (workloads/)","16.39"

Table:  **CoreMarkPro**

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "cjpeg-rose7-preset (workloads/)","59.17"
    "core (workloads/)","0.43"
    "coremark-pro ()","1085.32"
    "linear_alg-mid-100x100-sp (workloads/)","20.95"
    "loops-all-mid-10k-sp (workloads/)","0.89"
    "nnet_test (workloads/)","1.55"
    "parser-125k (workloads/)","7.25"
    "radix2-big-64k (workloads/)","31.02"
    "sha-test (workloads/)","116.28"
    "zip-test (workloads/)","30.77"

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

    "4m-check (workloads/)","344.21"
    "4m-check-reassembly (workloads/)","82.30"
    "4m-check-reassembly-tcp (workloads/)","45.37"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","16.82"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","0.78"
    "4m-cmykw2 (workloads/)","90.87"
    "4m-cmykw2-rotatew2 (workloads/)","22.74"
    "4m-reassembly (workloads/)","80.45"
    "4m-rotatew2 (workloads/)","26.87"
    "4m-tcp-mixed (workloads/)","93.02"
    "4m-x264w2 (workloads/)","0.79"
    "empty-wld (workloads/)","1.00"
    "idct-4m (workloads/)","13.73"
    "idct-4mw1 (workloads/)","13.73"
    "ippktcheck-4m (workloads/)","344.12"
    "ippktcheck-4mw1 (workloads/)","344.26"
    "ipres-4m (workloads/)","73.96"
    "ipres-4mw1 (workloads/)","74.00"
    "md5-4m (workloads/)","19.74"
    "md5-4mw1 (workloads/)","19.62"
    "rgbcmyk-4m (workloads/)","45.71"
    "rgbcmyk-4mw1 (workloads/)","45.89"
    "rotate-4ms1 (workloads/)","19.55"
    "rotate-4ms1w1 (workloads/)","19.43"
    "rotate-4ms64 (workloads/)","19.68"
    "rotate-4ms64w1 (workloads/)","19.65"
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

.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","7.35","87.10"
    "128","82.00","33.57","87.29"
    "256","210.00","83.43","86.13"
    "512","466.00","439.18","50.03"
    "1024","978.00","373.56","85.62"
    "1518","1472.00","546.71","83.86"

Table: **CPSW UDP Egress Throughput**

|

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.20","15.34"
    "128","82.00","6.82","14.90"
    "256","210.00","317.75","41.76"
    "1024","978.00","79.02","5.98"
    "1518","1472.00","121.29","18.44"

Table: **CPSW UDP Ingress Throughput (0% loss)**

|

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","am64xx-evm: Packet Loss %"

    "64","18.00","19.17","79.10","60.18"
    "128","82.00","86.77","81.76","55.70"
    "256","210.00","634.69","78.76","13.63"
    "1024","978.00","806.82","79.29","0.67"
    "1518","1472.00","818.05","75.67","4.68"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|

PCIe Driver
-----------

PCIe-NVMe-SSD
^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","382.00","13.14","398.00","8.02"
    "4m","382.00","12.58","398.00","7.87"
    "4k","81.10","51.49","107.00","47.61"
    "256k","381.00","15.40","397.00","9.78"

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

    "102400","0.17 (min 0.12, max 0.28)","47.98 (min 46.88, max 48.81)","62.43","42.86"
    "262144","0.13 (min 0.10, max 0.17)","48.63 (min 48.25, max 49.06)","63.63","40.00"
    "524288","0.13 (min 0.10, max 0.18)","49.20 (min 48.31, max 49.96)","62.68","33.33"
    "1048576","0.13 (min 0.10, max 0.17)","49.36 (min 47.97, max 50.14)","63.22","50.00"

|

RAW
^^^

.. csv-table::
    :header: "File size (Mbytes)","am64xx-evm: Raw Read Throughput (Mbytes/sec)"

    "50","178.57"

|

EMMC Driver
-------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","58.00","3.40","313.00","6.65"
    "4m","58.80","2.46","312.00","5.83"
    "4k","55.90","50.73","55.70","48.26"
    "256k","58.10","4.73","313.00","9.47"

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

    "1m","19.80","1.97","86.10","3.10"
    "4m","19.70","1.43","85.90","2.54"
    "4k","5.21","9.36","16.40","15.89"
    "256k","19.00","2.57","83.30","4.34"

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

**Setup** : Inateck ASM1153E USB hard disk is
connected to usb0 port. File read/write performance data on usb0 port is
captured.

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","37.50","5.78","38.60","5.02"
    "4m","37.90","4.99","38.90","4.63"
    "4k","17.60","31.38","17.70","27.90"
    "256k","36.80","8.22","37.60","6.30"

|
