***********************
Linux Performance Guide
***********************


.. rubric::  **Read This First**

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| AM62x EVM      | AM62x Starter Kit rev E2 and E3 with ARM running at 1400 MHz, DDR4 data rate 1600 MT/S                         |
+----------------+----------------------------------------------------------------------------------------------------------------+

Table:  Evaluation Modules

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

    "af_unix_sock_stream_latency (microsec)","32.39"
    "af_unix_socket_stream_bandwidth (MBs)","1199.02"
    "bw_file_rd-io-1mb (MB/s)","804.76"
    "bw_file_rd-o2c-1mb (MB/s)","480.31"
    "bw_mem-bcopy-16mb (MB/s)","768.38"
    "bw_mem-bcopy-1mb (MB/s)","839.77"
    "bw_mem-bcopy-2mb (MB/s)","759.30"
    "bw_mem-bcopy-4mb (MB/s)","786.32"
    "bw_mem-bcopy-8mb (MB/s)","816.16"
    "bw_mem-bzero-16mb (MB/s)","1736.49"
    "bw_mem-bzero-1mb (MB/s)","1287.94 (min 839.77, max 1736.11)"
    "bw_mem-bzero-2mb (MB/s)","1246.96 (min 759.30, max 1734.61)"
    "bw_mem-bzero-4mb (MB/s)","1260.97 (min 786.32, max 1735.61)"
    "bw_mem-bzero-8mb (MB/s)","1275.86 (min 816.16, max 1735.55)"
    "bw_mem-cp-16mb (MB/s)","441.34"
    "bw_mem-cp-1mb (MB/s)","1172.98 (min 475.74, max 1870.21)"
    "bw_mem-cp-2mb (MB/s)","1074.07 (min 439.90, max 1708.23)"
    "bw_mem-cp-4mb (MB/s)","1130.11 (min 469.70, max 1790.51)"
    "bw_mem-cp-8mb (MB/s)","1122.44 (min 470.45, max 1774.43)"
    "bw_mem-fcp-16mb (MB/s)","687.85"
    "bw_mem-fcp-1mb (MB/s)","1291.64 (min 847.17, max 1736.11)"
    "bw_mem-fcp-2mb (MB/s)","1247.03 (min 759.45, max 1734.61)"
    "bw_mem-fcp-4mb (MB/s)","1240.46 (min 745.30, max 1735.61)"
    "bw_mem-fcp-8mb (MB/s)","1241.43 (min 747.31, max 1735.55)"
    "bw_mem-frd-16mb (MB/s)","1138.22"
    "bw_mem-frd-1mb (MB/s)","1045.48 (min 847.17, max 1243.78)"
    "bw_mem-frd-2mb (MB/s)","934.56 (min 759.45, max 1109.67)"
    "bw_mem-frd-4mb (MB/s)","936.03 (min 745.30, max 1126.76)"
    "bw_mem-frd-8mb (MB/s)","937.51 (min 747.31, max 1127.71)"
    "bw_mem-fwr-16mb (MB/s)","1757.28"
    "bw_mem-fwr-1mb (MB/s)","1557.00 (min 1243.78, max 1870.21)"
    "bw_mem-fwr-2mb (MB/s)","1408.95 (min 1109.67, max 1708.23)"
    "bw_mem-fwr-4mb (MB/s)","1458.64 (min 1126.76, max 1790.51)"
    "bw_mem-fwr-8mb (MB/s)","1451.07 (min 1127.71, max 1774.43)"
    "bw_mem-rd-16mb (MB/s)","1152.24"
    "bw_mem-rd-1mb (MB/s)","993.19 (min 697.47, max 1288.90)"
    "bw_mem-rd-2mb (MB/s)","871.06 (min 619.58, max 1122.54)"
    "bw_mem-rd-4mb (MB/s)","898.79 (min 691.68, max 1105.89)"
    "bw_mem-rd-8mb (MB/s)","960.42 (min 791.37, max 1129.46)"
    "bw_mem-rdwr-16mb (MB/s)","853.65"
    "bw_mem-rdwr-1mb (MB/s)","580.16 (min 475.74, max 684.58)"
    "bw_mem-rdwr-2mb (MB/s)","524.74 (min 439.90, max 609.57)"
    "bw_mem-rdwr-4mb (MB/s)","587.65 (min 469.70, max 705.59)"
    "bw_mem-rdwr-8mb (MB/s)","626.77 (min 470.45, max 783.09)"
    "bw_mem-wr-16mb (MB/s)","815.79"
    "bw_mem-wr-1mb (MB/s)","691.03 (min 684.58, max 697.47)"
    "bw_mem-wr-2mb (MB/s)","614.58 (min 609.57, max 619.58)"
    "bw_mem-wr-4mb (MB/s)","698.64 (min 691.68, max 705.59)"
    "bw_mem-wr-8mb (MB/s)","787.23 (min 783.09, max 791.37)"
    "bw_mmap_rd-mo-1mb (MB/s)","1277.37"
    "bw_mmap_rd-o2c-1mb (MB/s)","504.03"
    "bw_pipe (MB/s)","499.88"
    "bw_unix (MB/s)","1199.02"
    "lat_connect (us)","70.08"
    "lat_ctx-2-128k (us)","4.54"
    "lat_ctx-2-256k (us)","4.16"
    "lat_ctx-4-128k (us)","4.28"
    "lat_ctx-4-256k (us)","3.35"
    "lat_fs-0k (num_files)","276.00"
    "lat_fs-10k (num_files)","114.00"
    "lat_fs-1k (num_files)","194.00"
    "lat_fs-4k (num_files)","198.00"
    "lat_mem_rd-stride128-sz1000k (ns)","52.11"
    "lat_mem_rd-stride128-sz125k (ns)","5.53"
    "lat_mem_rd-stride128-sz250k (ns)","5.83"
    "lat_mem_rd-stride128-sz31k (ns)","3.65"
    "lat_mem_rd-stride128-sz50 (ns)","2.15"
    "lat_mem_rd-stride128-sz500k (ns)","13.10"
    "lat_mem_rd-stride128-sz62k (ns)","5.24"
    "lat_mmap-1m (us)","47.00"
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
    "lat_ops-int64-div (ns)","6.80"
    "lat_ops-int64-mod (ns)","5.24"
    "lat_pagefault (us)","1.24"
    "lat_pipe (us)","17.74"
    "lat_proc-exec (us)","1167.60"
    "lat_proc-fork (us)","923.00"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","35.68"
    "lat_sem (us)","1.56"
    "lat_sig-catch (us)","4.45"
    "lat_sig-install (us)","0.47"
    "lat_sig-prot (us)","0.54"
    "lat_syscall-fstat (us)","1.15"
    "lat_syscall-null (us)","0.29"
    "lat_syscall-open (us)","161.65"
    "lat_syscall-read (us)","0.57"
    "lat_syscall-stat (us)","3.16"
    "lat_syscall-write (us)","0.48"
    "lat_tcp (us)","0.59"
    "lat_unix (us)","32.39"
    "latency_for_0.50_mb_block_size (nanosec)","13.10"
    "latency_for_1.00_mb_block_size (nanosec)","26.06 (min 0.00, max 52.11)"
    "pipe_bandwidth (MBs)","499.88"
    "pipe_latency (microsec)","17.74"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","35.68"
    "semaphore_latency (microsec)","1.56"
    "signal_handler_latency (microsec)","0.47"
    "signal_handler_overhead (microsec)","4.45"
    "tcp_ip_connection_cost_to_localhost (microsec)","70.08"
    "tcp_latency_using_localhost (microsec)","0.59"


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
    "dhrystone_per_mhz (DMIPS/MHz)","3.00"
    "dhrystone_per_second (DhrystoneP)","7407407.50"


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

    "linpack (Kflops)","581773.00"


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

    "assignment (Iterations)","13.63"
    "fourier (Iterations)","22879.00"
    "fp_emulation (Iterations)","107.20"
    "huffman (Iterations)","1174.50"
    "idea (Iterations)","3436.40"
    "lu_decomposition (Iterations)","542.73"
    "neural_net (Iterations)","7.85"
    "numeric_sort (Iterations)","505.15"
    "string_sort (Iterations)","165.88"


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

Execute the benchmark with the following:

::

    stream_c

.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf"

    "add (MB/s)","1446.10"
    "copy (MB/s)","1640.40"
    "scale (MB/s)","1810.50"
    "triad (MB/s)","1487.90"


Table:  **Stream**



CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.


.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf"

    "cjpeg-rose7-preset (workloads/)","41.67"
    "core (workloads/)","0.30"
    "coremark-pro ()","904.65"
    "linear_alg-mid-100x100-sp (workloads/)","14.66"
    "loops-all-mid-10k-sp (workloads/)","0.66"
    "nnet_test (workloads/)","1.09"
    "parser-125k (workloads/)","8.47"
    "radix2-big-64k (workloads/)","59.17"
    "sha-test (workloads/)","80.00"
    "zip-test (workloads/)","21.74"


Table:  **CoreMarkPro**



.. csv-table::
    :header: "Benchmarks","am62xx-sk: perf"

    "cjpeg-rose7-preset (workloads/)","83.33"
    "core (workloads/)","0.60"
    "coremark-pro ()","1518.99"
    "linear_alg-mid-100x100-sp (workloads/)","29.33"
    "loops-all-mid-10k-sp (workloads/)","1.14"
    "nnet_test (workloads/)","2.18"
    "parser-125k (workloads/)","12.42"
    "radix2-big-64k (workloads/)","42.58"
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

    "4m-check (workloads/)","361.38"
    "4m-check-reassembly (workloads/)","58.00"
    "4m-check-reassembly-tcp (workloads/)","44.56"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","24.70"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.73"
    "4m-cmykw2 (workloads/)","200.20"
    "4m-cmykw2-rotatew2 (workloads/)","39.84"
    "4m-reassembly (workloads/)","53.91"
    "4m-rotatew2 (workloads/)","45.91"
    "4m-tcp-mixed (workloads/)","108.84"
    "4m-x264w2 (workloads/)","1.87"
    "empty-wld (workloads/)","1.00"
    "idct-4m (workloads/)","18.59"
    "idct-4mw1 (workloads/)","18.58"
    "ippktcheck-4m (workloads/)","364.01"
    "ippktcheck-4mw1 (workloads/)","360.33"
    "ipres-4m (workloads/)","60.85"
    "ipres-4mw1 (workloads/)","61.10"
    "md5-4m (workloads/)","28.42"
    "md5-4mw1 (workloads/)","28.21"
    "rgbcmyk-4m (workloads/)","63.49"
    "rgbcmyk-4mw1 (workloads/)","63.71"
    "rotate-4ms1 (workloads/)","18.44"
    "rotate-4ms1w1 (workloads/)","18.48"
    "rotate-4ms64 (workloads/)","18.56"
    "rotate-4ms64w1 (workloads/)","18.59"
    "x264-4mq (workloads/)","0.56"
    "x264-4mqw1 (workloads/)","0.51"


Table:  **Multibench**


 
 

 

 



 


Graphics SGX/RGX Driver
-------------------------
 


GFXBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Run GFXBench and capture performance reported (Score and Display rate in fps). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am62xx-sk: Score","am62xx-sk: Fps"

    " GFXBench 5.x gl_5_high_off","11.48","0.18"


Table:  **GFXBench**



Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am62xx-sk: Score"

    "Glmark2-Wayland","186.00"


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


.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","am62xx-sk: THROUGHPUT (Mbits/sec)","am62xx-sk: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1719.54","46.31"

Table: **CPSW TCP Bidirectional Throughput**

|


.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am62xx-sk: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx-sk: THROUGHPUT (Mbits/sec)","am62xx-sk: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","13.77","37.27"
    "128","82.00","61.93","37.11"
    "256","210.00","157.63","37.11"
    "1024","978.00","882.49","42.39"
    "1518","1472.00","135.42","3.10"

Table: **CPSW UDP Egress Throughput**

|



.. csv-table::
    :header: "Frame Size(bytes)","am62xx-sk: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx-sk: THROUGHPUT (Mbits/sec)","am62xx-sk: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","8.55","17.12"
    "128","82.00","11.15","3.70"
    "256","210.00","109.53","16.04"
    "1024","978.00","212.03","12.93"
    "1518","1472.00","957.04","39.57"


Table: **CPSW UDP Ingress Throughput (0% loss)**


|



.. csv-table::
    :header: "Frame Size(bytes)","am62xx-sk: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx-sk: THROUGHPUT (Mbits/sec)","am62xx-sk: CPU Load % (LOCAL_CPU_UTIL)","am62xx-sk: Packet Loss %"

    "64","18.00","25.42","39.69","36.21"
    "128","82.00","115.68","41.30","53.69"
    "256","210.00","281.24","44.48","53.92"
    "1024","978.00","935.93","39.21","0.06"
    "1518","1472.00","956.59","39.46","0.04"

Table: **CPSW UDP Ingress Throughput (possible loss)**

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

 





 


AM62XX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","am62xx-sk: Write EXT4 Throughput (Mbytes/sec)","am62xx-sk: Write EXT4 CPU Load (%)","am62xx-sk: Read EXT4 Throughput (Mbytes/sec)","am62xx-sk: Read EXT4 CPU Load (%)"

    "1m","18.00","0.87","87.60","1.41"
    "4m","18.30","0.75","80.60","1.30"
    "4k","5.35","2.84","16.80","6.02"
    "256k","19.00","1.17","85.30","1.72"



 
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

    "aes-128-cbc","1024","231939.41"
    "aes-128-cbc","16","4927.82"
    "aes-128-cbc","16384","654098.43"
    "aes-128-cbc","256","72672.43"
    "aes-128-cbc","64","19475.09"
    "aes-128-cbc","8192","579556.69"
    "aes-192-cbc","1024","219130.20"
    "aes-192-cbc","16","4923.08"
    "aes-192-cbc","16384","565848.75"
    "aes-192-cbc","256","70948.35"
    "aes-192-cbc","64","19254.91"
    "aes-192-cbc","8192","512087.38"
    "aes-256-cbc","1024","211012.61"
    "aes-256-cbc","16","4903.49"
    "aes-256-cbc","16384","515320.49"
    "aes-256-cbc","256","70183.34"
    "aes-256-cbc","64","19079.66"
    "aes-256-cbc","8192","469909.50"
    "des-cbc","1024","26105.17"
    "des-cbc","16","5203.38"
    "des-cbc","16384","27667.11"
    "des-cbc","256","21917.10"
    "des-cbc","64","13308.95"
    "des-cbc","8192","27552.43"
    "des3","1024","10566.66"
    "des3","16","4052.52"
    "des3","16384","11239.42"
    "des3","256","8542.98"
    "des3","64","7796.95"
    "des3","8192","11231.23"
    "md5","1024","51471.70"
    "md5","16","1120.82"
    "md5","16384","153938.60"
    "md5","256","16328.79"
    "md5","64","4373.87"
    "md5","8192","135965.35"
    "sha1","1024","62358.53"
    "sha1","16","1086.12"
    "sha1","16384","363550.04"
    "sha1","256","16986.45"
    "sha1","64","4329.37"
    "sha1","8192","273566.38"
    "sha224","1024","60982.27"
    "sha224","16","1063.24"
    "sha224","16384","371081.22"
    "sha224","256","16469.42"
    "sha224","64","4200.04"
    "sha224","8192","275884.71"
    "sha256","1024","61202.09"
    "sha256","16","1061.38"
    "sha256","16384","370130.94"
    "sha256","256","16495.10"
    "sha256","64","4202.71"
    "sha256","8192","274909.87"
    "sha384","1024","36339.37"
    "sha384","16","1037.43"
    "sha384","16384","74257.75"
    "sha384","256","13717.85"
    "sha384","64","4153.30"
    "sha384","8192","69307.05"
    "sha512","1024","36271.79"
    "sha512","16","1031.84"
    "sha512","16384","74290.52"
    "sha512","256","13665.19"
    "sha512","64","4131.11"
    "sha512","8192","69296.13"


|



.. csv-table::
    :header: "Algorithm","am62xx-sk: CPU Load"

    "aes-128-cbc","98.00"
    "aes-192-cbc","98.00"
    "aes-256-cbc","98.00"
    "des-cbc","98.00"
    "des3","96.00"
    "md5","98.00"
    "sha1","98.00"
    "sha224","98.00"
    "sha256","98.00"
    "sha384","98.00"
    "sha512","98.00"

 

Listed for each algorithm are the code snippets used to run each benchmark test.

::
    
    time -v openssl speed -elapsed -evp aes-128-cbc

 




IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am62xx-sk: Throughput (Mbps)","am62xx-sk: Packets/Sec","am62xx-sk: CPU Load"

    "3des","69.00","6.00","25.06"
    "aes128","238.00","21.00","25.50"
    "aes192","237.90","21.00","25.46"
    "aes256","239.30","21.00","25.51"
