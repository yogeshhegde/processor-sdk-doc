.. http://processors.wiki.ti.com/index.php/CoreSDK_Linux_Kernel_Performance_Guide


======================================
 Linux 08.05.00 Performance Guide
======================================

.. rubric::  **Read This First**
   :name: read-this-first-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| AM64x EVM      | AM64x Evaluation Module rev E1 with ARM running at 1GHz, DDR data rate 1600 MT/S                               |
+----------------+----------------------------------------------------------------------------------------------------------------+
| AM65x EVM      | AM65x Evaluation Module rev 1.0 with ARM running at 800MHz, DDR4-2400 (1600 MT/S), TMDX654GPEVM                |
+----------------+----------------------------------------------------------------------------------------------------------------+

Table:  Evaluation Modules

|

.. rubric::  About This Manual
   :name: about-this-manual-kernel-perf-guide

This document provides performance data for each of the device drivers
which are part of the Process SDK Linux package. This document should be
used in conjunction with release notes and user guides provided with the
Process SDK Linux package for information on specific issues present
with drivers included in a particular release.

.. rubric::  If You Need Assistance
   :name: if-you-need-assistance-kernel-perf-guide

For further information or to report any problems, contact
http://e2e.ti.com/ or http://support.ti.com/


System Benchmarks
-------------------


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
    :header: "Benchmarks","am62xx-sk: perf"

    "af_unix_sock_stream_latency (microsec)","29.90"
    "af_unix_socket_stream_bandwidth (MBs)","1162.37"
    "bw_file_rd-io-1mb (MB/s)","802.95"
    "bw_file_rd-o2c-1mb (MB/s)","469.41"
    "bw_mem-bcopy-16mb (MB/s)","764.12"
    "bw_mem-bcopy-1mb (MB/s)","791.77"
    "bw_mem-bcopy-2mb (MB/s)","756.72"
    "bw_mem-bcopy-4mb (MB/s)","792.31"
    "bw_mem-bcopy-8mb (MB/s)","810.37"
    "bw_mem-bzero-16mb (MB/s)","1762.50"
    "bw_mem-bzero-1mb (MB/s)","1263.94 (min 791.77, max 1736.11)"
    "bw_mem-bzero-2mb (MB/s)","1245.36 (min 756.72, max 1734.00)"
    "bw_mem-bzero-4mb (MB/s)","1262.96 (min 792.31, max 1733.60)"
    "bw_mem-bzero-8mb (MB/s)","1279.89 (min 810.37, max 1749.40)"
    "bw_mem-cp-16mb (MB/s)","448.87"
    "bw_mem-cp-1mb (MB/s)","1169.66 (min 464.90, max 1874.41)"
    "bw_mem-cp-2mb (MB/s)","1224.39 (min 426.08, max 2022.69)"
    "bw_mem-cp-4mb (MB/s)","1118.45 (min 467.51, max 1769.39)"
    "bw_mem-cp-8mb (MB/s)","1126.68 (min 475.37, max 1777.98)"
    "bw_mem-fcp-16mb (MB/s)","694.14"
    "bw_mem-fcp-1mb (MB/s)","1279.44 (min 822.77, max 1736.11)"
    "bw_mem-fcp-2mb (MB/s)","1229.85 (min 725.69, max 1734.00)"
    "bw_mem-fcp-4mb (MB/s)","1245.95 (min 758.29, max 1733.60)"
    "bw_mem-fcp-8mb (MB/s)","1268.95 (min 788.49, max 1749.40)"
    "bw_mem-frd-16mb (MB/s)","1137.74"
    "bw_mem-frd-1mb (MB/s)","1043.61 (min 822.77, max 1264.45)"
    "bw_mem-frd-2mb (MB/s)","928.78 (min 725.69, max 1131.86)"
    "bw_mem-frd-4mb (MB/s)","924.33 (min 758.29, max 1090.36)"
    "bw_mem-frd-8mb (MB/s)","956.76 (min 788.49, max 1125.02)"
    "bw_mem-fwr-16mb (MB/s)","1767.17"
    "bw_mem-fwr-1mb (MB/s)","1569.43 (min 1264.45, max 1874.41)"
    "bw_mem-fwr-2mb (MB/s)","1577.28 (min 1131.86, max 2022.69)"
    "bw_mem-fwr-4mb (MB/s)","1429.88 (min 1090.36, max 1769.39)"
    "bw_mem-fwr-8mb (MB/s)","1451.50 (min 1125.02, max 1777.98)"
    "bw_mem-rd-16mb (MB/s)","1147.94"
    "bw_mem-rd-1mb (MB/s)","999.08 (min 700.65, max 1297.50)"
    "bw_mem-rd-2mb (MB/s)","874.54 (min 627.16, max 1121.91)"
    "bw_mem-rd-4mb (MB/s)","922.92 (min 709.47, max 1136.36)"
    "bw_mem-rd-8mb (MB/s)","942.00 (min 744.39, max 1139.60)"
    "bw_mem-rdwr-16mb (MB/s)","791.22"
    "bw_mem-rdwr-1mb (MB/s)","570.92 (min 464.90, max 676.93)"
    "bw_mem-rdwr-2mb (MB/s)","513.39 (min 426.08, max 600.69)"
    "bw_mem-rdwr-4mb (MB/s)","575.35 (min 467.51, max 683.18)"
    "bw_mem-rdwr-8mb (MB/s)","630.11 (min 475.37, max 784.85)"
    "bw_mem-wr-16mb (MB/s)","857.36"
    "bw_mem-wr-1mb (MB/s)","688.79 (min 676.93, max 700.65)"
    "bw_mem-wr-2mb (MB/s)","613.93 (min 600.69, max 627.16)"
    "bw_mem-wr-4mb (MB/s)","696.33 (min 683.18, max 709.47)"
    "bw_mem-wr-8mb (MB/s)","764.62 (min 744.39, max 784.85)"
    "bw_mmap_rd-mo-1mb (MB/s)","1252.91"
    "bw_mmap_rd-o2c-1mb (MB/s)","479.54"
    "bw_pipe (MB/s)","494.80"
    "bw_unix (MB/s)","1162.37"
    "lat_connect (us)","67.54"
    "lat_ctx-2-128k (us)","4.56"
    "lat_ctx-2-256k (us)","4.84"
    "lat_ctx-4-128k (us)","4.26"
    "lat_ctx-4-256k (us)","3.35"
    "lat_fs-0k (num_files)","322.00"
    "lat_fs-10k (num_files)","115.00"
    "lat_fs-1k (num_files)","194.00"
    "lat_fs-4k (num_files)","207.00"
    "lat_mem_rd-stride128-sz1000k (ns)","52.08"
    "lat_mem_rd-stride128-sz125k (ns)","5.57"
    "lat_mem_rd-stride128-sz250k (ns)","5.84"
    "lat_mem_rd-stride128-sz31k (ns)","3.65"
    "lat_mem_rd-stride128-sz50 (ns)","2.15"
    "lat_mem_rd-stride128-sz500k (ns)","12.95"
    "lat_mem_rd-stride128-sz62k (ns)","5.26"
    "lat_mmap-1m (us)","48.00"
    "lat_ops-double-add (ns)","0.52"
    "lat_ops-double-mul (ns)","2.86"
    "lat_ops-float-add (ns)","0.52"
    "lat_ops-float-mul (ns)","2.86"
    "lat_ops-int-add (ns)","0.72"
    "lat_ops-int-bit (ns)","0.48"
    "lat_ops-int-div (ns)","4.29"
    "lat_ops-int-mod (ns)","4.53"
    "lat_ops-int-mul (ns)","2.17"
    "lat_ops-int64-add (ns)","0.72"
    "lat_ops-int64-bit (ns)","0.48"
    "lat_ops-int64-div (ns)","6.79"
    "lat_ops-int64-mod (ns)","5.25"
    "lat_pagefault (us)","1.24"
    "lat_pipe (us)","17.92"
    "lat_proc-exec (us)","1221.40"
    "lat_proc-fork (us)","929.67"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","34.84"
    "lat_sem (us)","1.61"
    "lat_sig-catch (us)","5.03"
    "lat_sig-install (us)","0.48"
    "lat_sig-prot (us)","0.45"
    "lat_syscall-fstat (us)","1.19"
    "lat_syscall-null (us)","0.29"
    "lat_syscall-open (us)","186.47"
    "lat_syscall-read (us)","0.56"
    "lat_syscall-stat (us)","3.20"
    "lat_syscall-write (us)","0.49"
    "lat_tcp (us)","0.60"
    "lat_unix (us)","29.90"
    "latency_for_0.50_mb_block_size (nanosec)","12.95"
    "latency_for_1.00_mb_block_size (nanosec)","26.04 (min 0.00, max 52.08)"
    "pipe_bandwidth (MBs)","494.80"
    "pipe_latency (microsec)","17.92"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","34.84"
    "semaphore_latency (microsec)","1.61"
    "signal_handler_latency (microsec)","0.48"
    "signal_handler_overhead (microsec)","5.03"
    "tcp_ip_connection_cost_to_localhost (microsec)","67.54"
    "tcp_latency_using_localhost (microsec)","0.60"


Table:  **LM Bench Metrics**



Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

Execute the benchmark with the following:

::

    runDhrystone

.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf"

    "cpu_clock (MHz)","1400.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.90"
    "dhrystone_per_second (DhrystoneP)","7142857.00"


Table:  **Dhrystone Benchmark**



Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Whetstone is a benchmark primarily measuring floating-point arithmetic performance.

Execute the benchmark with the following:

::

    runWhetstone

.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf"

    "whetstone (MIPS)","5000.00"


Table:  **Whetstone Benchmark**



Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf"

    "linpack (Kflops)","577516.00"


Table:  **Linpack Benchmark**



NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html


.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf"

    "assignment (Iterations)","13.66"
    "fourier (Iterations)","22878.00"
    "fp_emulation (Iterations)","107.20"
    "huffman (Iterations)","1174.50"
    "idea (Iterations)","3436.40"
    "lu_decomposition (Iterations)","547.83"
    "neural_net (Iterations)","7.85"
    "numeric_sort (Iterations)","504.74"
    "string_sort (Iterations)","165.87"


Table:  **NBench Benchmarks**





CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.


.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf"

    "cjpeg-rose7-preset (workloads/)","42.02"
    "core (workloads/)","0.30"
    "coremark-pro ()","883.66"
    "linear_alg-mid-100x100-sp (workloads/)","14.68"
    "loops-all-mid-10k-sp (workloads/)","0.67"
    "nnet_test (workloads/)","1.09"
    "parser-125k (workloads/)","8.40"
    "radix2-big-64k (workloads/)","47.75"
    "sha-test (workloads/)","80.65"
    "zip-test (workloads/)","21.28"


Table:  **CoreMarkPro**



.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf"

    "cjpeg-rose7-preset (workloads/)","81.30"
    "core (workloads/)","0.60"
    "coremark-pro ()","1495.39"
    "linear_alg-mid-100x100-sp (workloads/)","29.12"
    "loops-all-mid-10k-sp (workloads/)","1.15"
    "nnet_test (workloads/)","2.19"
    "parser-125k (workloads/)","11.90"
    "radix2-big-64k (workloads/)","39.32"
    "sha-test (workloads/)","161.29"
    "zip-test (workloads/)","39.22"


Table:  **CoreMarkPro for Two Cores**
 
 


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
    :header: "Benchmarks","am62xx-sk: perf"

    "4m-check (workloads/)","357.71"
    "4m-check-reassembly (workloads/)","67.39"
    "4m-check-reassembly-tcp (workloads/)","43.78"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","24.63"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.80"
    "4m-cmykw2 (workloads/)","198.02"
    "4m-cmykw2-rotatew2 (workloads/)","39.42"
    "4m-reassembly (workloads/)","52.41"
    "4m-rotatew2 (workloads/)","44.33"
    "4m-tcp-mixed (workloads/)","108.11"
    "4m-x264w2 (workloads/)","1.86"
    "idct-4m (workloads/)","18.54"
    "idct-4mw1 (workloads/)","18.58"
    "ippktcheck-4m (workloads/)","356.38"
    "ippktcheck-4mw1 (workloads/)","358.53"
    "ipres-4m (workloads/)","60.44"
    "ipres-4mw1 (workloads/)","60.19"
    "md5-4m (workloads/)","28.05"
    "md5-4mw1 (workloads/)","28.07"
    "rgbcmyk-4m (workloads/)","63.88"
    "rgbcmyk-4mw1 (workloads/)","63.37"
    "rotate-4ms1 (workloads/)","18.48"
    "rotate-4ms1w1 (workloads/)","18.44"
    "rotate-4ms64 (workloads/)","18.51"
    "rotate-4ms64w1 (workloads/)","18.59"
    "x264-4mq (workloads/)","0.56"
    "x264-4mqw1 (workloads/)","0.56"


Table:  **Multibench**


 
 

 

 



 


Graphics SGX/RGX Driver
-------------------------
 


GFXBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Run GFXBench and capture performance reported (Score and Display rate in fps). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am62xx-sk: Score","am62xx-sk: Fps"

    " GFXBench 5.x gl_5_high_off","10.40","0.16"


Table:  **GFXBench**



Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am62xx-sk: Score"

    "Glmark2-Wayland","188.00"


Table:  **Glmark2**
 
 
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

- CPSW2g: AM65x, J7200, J721e, J721S2, J784S4
- CPSW3g: AM64x


.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","am62xx-sk: THROUGHPUT (Mbits/sec)","am62xx-sk: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1503.50","43.77"

Table: **CPSW TCP Bidirectional Throughput**
|



.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am62xx-sk: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx-sk: THROUGHPUT (Mbits/sec)","am62xx-sk: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","17.77","43.17"
    "128","82.00","85.89","44.70"
    "256","210.00","202.53","43.03"
    "1024","978.00","905.84","47.50"
    "1518","1472.00","933.80","42.33"

Table: **CPSW UDP Egress Throughput**
|



.. csv-table::
    :header: "Frame Size(bytes)","am62xx-sk: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx-sk: THROUGHPUT (Mbits/sec)","am62xx-sk: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.28","2.14"
    "128","82.00","15.94","7.69"
    "256","210.00","23.18","4.41"
    "1024","978.00","84.50","3.70"
    "1518","1472.00","956.98","38.52"


Table: **CPSW UDP Ingress Throughput (0% loss)**

|



.. csv-table::
    :header: "Frame Size(bytes)","am62xx-sk: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx-sk: THROUGHPUT (Mbits/sec)","am62xx-sk: CPU Load % (LOCAL_CPU_UTIL)","am62xx-sk: Packet Loss %"

    "64","18.00","25.68","38.63","55.27"
    "128","82.00","108.72","39.36","57.51"
    "256","210.00","269.24","40.58","63.58"
    "1024","978.00","933.03","43.27","0.40"
    "1518","1472.00","955.32","42.37","0.12"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|
 
 

 

 
 

 

 


OSPI Flash Driver
-------------------------

 

 

 

 

 

 

 

 
 

 

 

 

 

 

 

 

 


MMC/SD Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

| 

 





 


AM62XX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","am62xx-sk: Write EXT4 Throughput (Mbytes/sec)","am62xx-sk: Write EXT4 CPU Load (%)","am62xx-sk: Read EXT4 Throughput (Mbytes/sec)","am62xx-sk: Read EXT4 CPU Load (%)"

    "1m","18.50","0.96","86.30","1.55"
    "4m","18.80","0.83","86.90","1.37"
    "4k","5.34","3.00","16.60","5.96"
    "256k","18.50","1.10","84.60","2.00"

|







 

 








 













 

 

 





 
|


The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|




 


CRYPTO Driver
-------------------------


OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am62xx-sk: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","251095.04"
    "aes-128-cbc","16","5531.99"
    "aes-128-cbc","16384","659046.40"
    "aes-128-cbc","256","80427.86"
    "aes-128-cbc","64","21707.99"
    "aes-128-cbc","8192","594542.59"
    "aes-192-cbc","1024","237904.90"
    "aes-192-cbc","16","5574.54"
    "aes-192-cbc","16384","575580.84"
    "aes-192-cbc","256","79091.37"
    "aes-192-cbc","64","21674.86"
    "aes-192-cbc","8192","524405.42"
    "aes-256-cbc","1024","224464.55"
    "aes-256-cbc","16","5420.19"
    "aes-256-cbc","16384","521546.41"
    "aes-256-cbc","256","76291.16"
    "aes-256-cbc","64","20973.85"
    "aes-256-cbc","8192","477227.69"
    "des-cbc","1024","26197.33"
    "des-cbc","16","5556.19"
    "des-cbc","16384","27639.81"
    "des-cbc","256","22286.76"
    "des-cbc","64","13877.42"
    "des-cbc","8192","27522.39"
    "des3","1024","10989.23"
    "des3","16","4196.93"
    "des3","16384","11244.89"
    "des3","256","10201.26"
    "des3","64","7930.11"
    "des3","8192","11223.04"
    "md5","1024","51033.77"
    "md5","16","1117.89"
    "md5","16384","153217.71"
    "md5","256","16171.52"
    "md5","64","4327.87"
    "md5","8192","135249.92"
    "sha1","1024","61794.30"
    "sha1","16","1076.51"
    "sha1","16384","361867.95"
    "sha1","256","16775.08"
    "sha1","64","4282.71"
    "sha1","8192","271594.84"
    "sha224","1024","60442.28"
    "sha224","16","1053.10"
    "sha224","16384","367667.88"
    "sha224","256","16337.07"
    "sha224","64","4179.75"
    "sha224","8192","274046.98"
    "sha256","1024","61745.15"
    "sha256","16","1077.31"
    "sha256","16384","371720.19"
    "sha256","256","16720.73"
    "sha256","64","4273.32"
    "sha256","8192","276657.49"
    "sha384","1024","36471.47"
    "sha384","16","1034.55"
    "sha384","16384","74208.60"
    "sha384","256","13771.09"
    "sha384","64","4140.50"
    "sha384","8192","69320.70"
    "sha512","1024","36587.52"
    "sha512","16","1046.51"
    "sha512","16384","74328.75"
    "sha512","256","13878.02"
    "sha512","64","4195.07"
    "sha512","8192","69410.82"


|
|



.. csv-table::
    :header: "Algorithm","am62xx-sk: CPU Load"

    "aes-128-cbc","98.00"
    "aes-192-cbc","98.00"
    "aes-256-cbc","98.00"
    "des-cbc","98.00"
    "des3","98.00"
    "md5","98.00"
    "sha1","98.00"
    "sha224","98.00"
    "sha256","98.00"
    "sha384","98.00"
    "sha512","98.00"

 

Listed for each algorithm are the code snippets used to run each
  benchmark test.

::
    time -v openssl speed -elapsed -evp aes-128-cbc

 




IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am62xx-sk: Throughput (Mbps)","am62xx-sk: Packets/Sec","am62xx-sk: CPU Load"

    "3des","73.30","6.00","26.37"
    "aes128","425.20","37.00","29.42"
    "aes192","426.70","38.00","29.30"
    "aes256","418.60","37.00","29.39"

 
 

DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.




