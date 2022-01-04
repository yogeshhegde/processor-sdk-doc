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

    "af_unix_sock_stream_latency (microsec)","40.80"
    "af_unix_socket_stream_bandwidth (MB/s)","565.54"
    "bw_file_rd-io-1mb (MB/s)","1036.45"
    "bw_file_rd-o2c-1mb (MB/s)","591.63"
    "bw_mem-bcopy-16mb (MB/s)","888.99"
    "bw_mem-bcopy-1mb (MB/s)","865.65"
    "bw_mem-bcopy-2mb (MB/s)","865.68"
    "bw_mem-bcopy-4mb (MB/s)","899.18"
    "bw_mem-bcopy-8mb (MB/s)","906.72"
    "bw_mem-bzero-16mb (MB/s)","2126.53"
    "bw_mem-bzero-1mb (MB/s)","1495.72 (min 865.65, max 2125.78)"
    "bw_mem-bzero-2mb (MB/s)","1495.54 (min 865.68, max 2125.40)"
    "bw_mem-bzero-4mb (MB/s)","1513.42 (min 899.18, max 2127.66)"
    "bw_mem-bzero-8mb (MB/s)","1516.77 (min 906.72, max 2126.81)"
    "bw_mem-cp-16mb (MB/s)","603.27"
    "bw_mem-cp-1mb (MB/s)","1420.68 (min 591.63, max 2249.72)"
    "bw_mem-cp-2mb (MB/s)","1400.45 (min 593.38, max 2207.51)"
    "bw_mem-cp-4mb (MB/s)","1382.04 (min 594.88, max 2169.20)"
    "bw_mem-cp-8mb (MB/s)","1374.81 (min 599.66, max 2149.96)"
    "bw_mem-fcp-16mb (MB/s)","858.78"
    "bw_mem-fcp-1mb (MB/s)","1489.37 (min 852.95, max 2125.78)"
    "bw_mem-fcp-2mb (MB/s)","1481.52 (min 837.64, max 2125.40)"
    "bw_mem-fcp-4mb (MB/s)","1484.53 (min 841.40, max 2127.66)"
    "bw_mem-fcp-8mb (MB/s)","1488.44 (min 850.07, max 2126.81)"
    "bw_mem-frd-16mb (MB/s)","1510.57"
    "bw_mem-frd-1mb (MB/s)","1148.63 (min 852.95, max 1444.30)"
    "bw_mem-frd-2mb (MB/s)","1149.42 (min 837.64, max 1461.19)"
    "bw_mem-frd-4mb (MB/s)","1175.04 (min 841.40, max 1508.67)"
    "bw_mem-frd-8mb (MB/s)","1179.47 (min 850.07, max 1508.86)"
    "bw_mem-fwr-16mb (MB/s)","2136.18"
    "bw_mem-fwr-1mb (MB/s)","1847.01 (min 1444.30, max 2249.72)"
    "bw_mem-fwr-2mb (MB/s)","1834.35 (min 1461.19, max 2207.51)"
    "bw_mem-fwr-4mb (MB/s)","1838.94 (min 1508.67, max 2169.20)"
    "bw_mem-fwr-8mb (MB/s)","1829.41 (min 1508.86, max 2149.96)"
    "bw_mem-rd-16mb (MB/s)","1510.86"
    "bw_mem-rd-1mb (MB/s)","1207.49 (min 943.04, max 1471.94)"
    "bw_mem-rd-2mb (MB/s)","1255.07 (min 1007.22, max 1502.91)"
    "bw_mem-rd-4mb (MB/s)","1298.34 (min 1095.74, max 1500.94)"
    "bw_mem-rd-8mb (MB/s)","1335.73 (min 1154.57, max 1516.88)"
    "bw_mem-rdwr-16mb (MB/s)","1257.37"
    "bw_mem-rdwr-1mb (MB/s)","772.19 (min 591.63, max 952.74)"
    "bw_mem-rdwr-2mb (MB/s)","777.69 (min 593.38, max 962.00)"
    "bw_mem-rdwr-4mb (MB/s)","793.35 (min 594.88, max 991.82)"
    "bw_mem-rdwr-8mb (MB/s)","826.91 (min 599.66, max 1054.16)"
    "bw_mem-wr-16mb (MB/s)","1166.27"
    "bw_mem-wr-1mb (MB/s)","947.89 (min 943.04, max 952.74)"
    "bw_mem-wr-2mb (MB/s)","984.61 (min 962.00, max 1007.22)"
    "bw_mem-wr-4mb (MB/s)","1043.78 (min 991.82, max 1095.74)"
    "bw_mem-wr-8mb (MB/s)","1104.37 (min 1054.16, max 1154.57)"
    "bw_mmap_rd-mo-1mb (MB/s)","1474.93"
    "bw_mmap_rd-o2c-1mb (MB/s)","659.20"
    "bw_pipe (MB/s)","307.12"
    "bw_unix (MB/s)","565.54"
    "lat_connect (us)","63.33"
    "lat_ctx-2-128k (us)","29.03"
    "lat_ctx-2-256k (us)","79.76"
    "lat_ctx-4-128k (us)","50.06"
    "lat_ctx-4-256k (us)","61.55"
    "lat_fs-0k (num_files)","219.00"
    "lat_fs-10k (num_files)","321.00"
    "lat_fs-1k (num_files)","83.00"
    "lat_fs-4k (num_files)","80.00"
    "lat_mem_rd-stride128-sz1000k (ns)","41.80"
    "lat_mem_rd-stride128-sz125k (ns)","7.57"
    "lat_mem_rd-stride128-sz250k (ns)","8.15"
    "lat_mem_rd-stride128-sz31k (ns)","3.03"
    "lat_mem_rd-stride128-sz50 (ns)","3.01"
    "lat_mem_rd-stride128-sz500k (ns)","36.61"
    "lat_mem_rd-stride128-sz62k (ns)","6.42"
    "lat_mmap-1m (us)","22.00"
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
    "lat_pagefault (us)","2.62"
    "lat_pipe (us)","25.23"
    "lat_proc-exec (us)","2075.33"
    "lat_proc-fork (us)","1701.25"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","46.27"
    "lat_sem (us)","2.75"
    "lat_sig-catch (us)","6.74"
    "lat_sig-install (us)","0.66"
    "lat_sig-prot (us)","0.68"
    "lat_syscall-fstat (us)","1.59"
    "lat_syscall-null (us)","0.40"
    "lat_syscall-open (us)","282.85"
    "lat_syscall-read (us)","0.78"
    "lat_syscall-stat (us)","4.36"
    "lat_syscall-write (us)","0.64"
    "lat_tcp (us)","0.84"
    "lat_unix (us)","40.80"
    "latency_for_0.50_mb_block_size (nanosec)","36.61"
    "latency_for_1.00_mb_block_size (nanosec)","20.90 (min 0.00, max 41.80)"
    "pipe_bandwidth (MBs)","1437.90"
    "pipe_latency (microsec)","25.23"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","46.27"
    "semaphore_latency (microsec)","2.75"
    "signal_handler_latency (microsec)","0.66"
    "signal_handler_overhead (microsec)","6.74"
    "tcp_ip_connection_cost_to_localhost (microsec)","63.33"
    "tcp_latency_using_localhost (microsec)","0.84"

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

    "whetstone (MIPS)","5000.00"

Table:  **Whetstone Benchmark**

Linpack
^^^^^^^

Linpack measures peak double precision (64 bit) floating point performance in
sloving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "linpack (Kflops)","422174.00"

Table:  **Linpack Benchmark**

NBench
^^^^^^

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "assignment (Iterations)","9.76"
    "fourier (Iterations)","16339.00"
    "fp_emulation (Iterations)","76.57"
    "huffman (Iterations)","838.76"
    "idea (Iterations)","2454.30"
    "lu_decomposition (Iterations)","403.49"
    "neural_net (Iterations)","5.61"
    "numeric_sort (Iterations)","360.92"
    "string_sort (Iterations)","118.41"

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

    "add (MB/s)","1897.10"
    "copy (MB/s)","1967.40"
    "scale (MB/s)","2454.20"
    "triad (MB/s)","1930.10"


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
    "coremark-pro ()","602.65"
    "linear_alg-mid-100x100-sp (workloads/)","10.51"
    "loops-all-mid-10k-sp (workloads/)","0.49"
    "nnet_test (workloads/)","0.78"
    "parser-125k (workloads/)","6.29"
    "radix2-big-64k (workloads/)","19.85"
    "sha-test (workloads/)","57.80"
    "zip-test (workloads/)","16.39"

Table:  **CoreMarkPro**

.. csv-table::
    :header: "Benchmarks","am64xx-evm: perf"

    "cjpeg-rose7-preset (workloads/)","58.82"
    "core (workloads/)","0.42"
    "coremark-pro ()","1081.76"
    "linear_alg-mid-100x100-sp (workloads/)","20.92"
    "loops-all-mid-10k-sp (workloads/)","0.90"
    "nnet_test (workloads/)","1.54"
    "parser-125k (workloads/)","7.30"
    "radix2-big-64k (workloads/)","31.18"
    "sha-test (workloads/)","116.28"
    "zip-test (workloads/)","30.30"

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

    "4m-check (workloads/)","344.40"
    "4m-check-reassembly (workloads/)","83.82"
    "4m-check-reassembly-tcp (workloads/)","45.37"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","16.99"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","0.78"
    "4m-cmykw2 (workloads/)","91.37"
    "4m-cmykw2-rotatew2 (workloads/)","22.63"
    "4m-reassembly (workloads/)","83.26"
    "4m-rotatew2 (workloads/)","27.29"
    "4m-tcp-mixed (workloads/)","93.57"
    "4m-x264w2 (workloads/)","0.79"
    "empty-wld (workloads/)","1.00"
    "idct-4m (workloads/)","13.72"
    "idct-4mw1 (workloads/)","13.78"
    "ippktcheck-4m (workloads/)","343.83"
    "ippktcheck-4mw1 (workloads/)","344.69"
    "ipres-4m (workloads/)","72.99"
    "ipres-4mw1 (workloads/)","74.15"
    "md5-4m (workloads/)","19.46"
    "md5-4mw1 (workloads/)","19.77"
    "rgbcmyk-4m (workloads/)","45.90"
    "rgbcmyk-4mw1 (workloads/)","45.74"
    "rotate-4ms1 (workloads/)","19.55"
    "rotate-4ms1w1 (workloads/)","19.52"
    "rotate-4ms64 (workloads/)","19.62"
    "rotate-4ms64w1 (workloads/)","19.69"
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

    "64","18.00","7.48","86.32"
    "128","82.00","33.82","85.90"
    "256","210.00","84.12","85.10"
    "512","466.00","392.68","50.13"
    "1024","978.00","377.79","84.10"
    "1518","1472.00","569.36","84.54"

Table: **CPSW UDP Egress Throughput**

|

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","5.44","24.23"
    "128","82.00","6.63","4.81"
    "256","210.00","16.80","4.76"
    "1024","978.00","81.37","18.16"
    "1518","1472.00","122.46","18.25"

Table: **CPSW UDP Ingress Throughput (0% loss)**

|

.. csv-table::
    :header: "Frame Size(bytes)","am64xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am64xx-evm: THROUGHPUT (Mbits/sec)","am64xx-evm: CPU Load % (LOCAL_CPU_UTIL)","am64xx-evm: Packet Loss %"

    "64","18.00","23.75","67.82","2.84"
    "128","82.00","68.64","58.39","72.41"
    "256","210.00","161.46","55.91","73.82"
    "1024","978.00","647.70","54.14","30.84"
    "1518","1472.00","860.42","69.12","10.09"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|

PCIe Driver
-----------

PCIe-NVMe-SSD
^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am64xx-evm: Write EXT4 Throughput (Mbytes/sec)","am64xx-evm: Write EXT4 CPU Load (%)","am64xx-evm: Read EXT4 Throughput (Mbytes/sec)","am64xx-evm: Read EXT4 CPU Load (%)"

    "1m","383.00","13.14","398.00","7.75"
    "4m","382.00","12.19","398.00","7.54"
    "4k","82.70","51.53","110.00","47.91"
    "256k","382.00","15.12","398.00","9.58"

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

    "102400","0.17 (min 0.12, max 0.29)","44.84 (min 43.21, max 48.48)","63.52","33.33"
    "262144","0.13 (min 0.10, max 0.18)","45.50 (min 43.80, max 46.81)","64.62","33.33"
    "524288","0.13 (min 0.10, max 0.18)","45.40 (min 44.10, max 46.52)","64.66","57.14"
    "1048576","0.13 (min 0.10, max 0.18)","45.92 (min 44.00, max 46.74)","64.57","20.00"

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

    "1m","59.50","3.07","281.00","2.06"
    "4m","59.60","2.37","296.00","0.47"
    "4k","46.40","45.10","54.80","47.75"
    "256k","59.90","4.39","173.00","5.91"

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

    "1m","18.80","1.90","86.80","3.27"
    "4m","19.20","1.48","86.00","2.73"
    "4k","5.01","8.82","16.60","16.96"
    "256k","18.50","2.50","84.20","4.28"

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

    "1m","36.80","5.51","37.30","5.20"
    "4m","36.00","5.03","37.80","4.98"
    "4k","17.40","28.36","17.90","27.47"
    "256k","35.40","7.98","36.40","6.54"

|
