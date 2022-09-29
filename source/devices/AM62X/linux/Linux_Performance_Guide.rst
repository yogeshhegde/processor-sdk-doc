***********************
Linux Performance Guide
***********************


.. rubric::  **Read This First**

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| AM62x EVM      | AM62x Evaluation Module rev E2 with ARM running at 1.4GHz, DDR data rate 1600 MT/S                           |
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
    :header: "Benchmarks","am62xx-sk: perf"

    "af_unix_sock_stream_latency (microsec)","31.29"
    "af_unix_socket_stream_bandwidth (MBs)","1218.39"
    "bw_file_rd-io-1mb (MB/s)","827.13"
    "bw_file_rd-o2c-1mb (MB/s)","459.70"
    "bw_mem-bcopy-16mb (MB/s)","756.29"
    "bw_mem-bcopy-1mb (MB/s)","828.23"
    "bw_mem-bcopy-2mb (MB/s)","772.05"
    "bw_mem-bcopy-4mb (MB/s)","788.80"
    "bw_mem-bcopy-8mb (MB/s)","795.86"
    "bw_mem-bzero-16mb (MB/s)","1760.18"
    "bw_mem-bzero-1mb (MB/s)","1282.32 (min 828.23, max 1736.41)"
    "bw_mem-bzero-2mb (MB/s)","1252.88 (min 772.05, max 1733.70)"
    "bw_mem-bzero-4mb (MB/s)","1262.58 (min 788.80, max 1736.36)"
    "bw_mem-bzero-8mb (MB/s)","1279.38 (min 795.86, max 1762.89)"
    "bw_mem-cp-16mb (MB/s)","457.38"
    "bw_mem-cp-1mb (MB/s)","1166.63 (min 451.94, max 1881.31)"
    "bw_mem-cp-2mb (MB/s)","1077.25 (min 463.02, max 1691.47)"
    "bw_mem-cp-4mb (MB/s)","1128.72 (min 468.00, max 1789.44)"
    "bw_mem-cp-8mb (MB/s)","1126.50 (min 469.48, max 1783.52)"
    "bw_mem-fcp-16mb (MB/s)","676.39"
    "bw_mem-fcp-1mb (MB/s)","1281.84 (min 827.27, max 1736.41)"
    "bw_mem-fcp-2mb (MB/s)","1245.21 (min 756.72, max 1733.70)"
    "bw_mem-fcp-4mb (MB/s)","1257.59 (min 778.82, max 1736.36)"
    "bw_mem-fcp-8mb (MB/s)","1255.17 (min 747.45, max 1762.89)"
    "bw_mem-frd-16mb (MB/s)","1127.32"
    "bw_mem-frd-1mb (MB/s)","1052.79 (min 827.27, max 1278.31)"
    "bw_mem-frd-2mb (MB/s)","898.92 (min 756.72, max 1041.12)"
    "bw_mem-frd-4mb (MB/s)","934.37 (min 778.82, max 1089.92)"
    "bw_mem-frd-8mb (MB/s)","941.91 (min 747.45, max 1136.36)"
    "bw_mem-fwr-16mb (MB/s)","1767.37"
    "bw_mem-fwr-1mb (MB/s)","1579.81 (min 1278.31, max 1881.31)"
    "bw_mem-fwr-2mb (MB/s)","1366.30 (min 1041.12, max 1691.47)"
    "bw_mem-fwr-4mb (MB/s)","1439.68 (min 1089.92, max 1789.44)"
    "bw_mem-fwr-8mb (MB/s)","1459.94 (min 1136.36, max 1783.52)"
    "bw_mem-rd-16mb (MB/s)","1128.19"
    "bw_mem-rd-1mb (MB/s)","985.84 (min 693.60, max 1278.07)"
    "bw_mem-rd-2mb (MB/s)","881.30 (min 632.01, max 1130.58)"
    "bw_mem-rd-4mb (MB/s)","897.26 (min 657.03, max 1137.49)"
    "bw_mem-rd-8mb (MB/s)","973.69 (min 816.16, max 1131.22)"
    "bw_mem-rdwr-16mb (MB/s)","803.21"
    "bw_mem-rdwr-1mb (MB/s)","564.21 (min 451.94, max 676.48)"
    "bw_mem-rdwr-2mb (MB/s)","532.94 (min 463.02, max 602.86)"
    "bw_mem-rdwr-4mb (MB/s)","560.85 (min 468.00, max 653.70)"
    "bw_mem-rdwr-8mb (MB/s)","631.88 (min 469.48, max 794.28)"
    "bw_mem-wr-16mb (MB/s)","838.14"
    "bw_mem-wr-1mb (MB/s)","685.04 (min 676.48, max 693.60)"
    "bw_mem-wr-2mb (MB/s)","617.44 (min 602.86, max 632.01)"
    "bw_mem-wr-4mb (MB/s)","655.37 (min 653.70, max 657.03)"
    "bw_mem-wr-8mb (MB/s)","805.22 (min 794.28, max 816.16)"
    "bw_mmap_rd-mo-1mb (MB/s)","1274.81"
    "bw_mmap_rd-o2c-1mb (MB/s)","449.57"
    "bw_pipe (MB/s)","498.34"
    "bw_unix (MB/s)","1218.39"
    "lat_connect (us)","67.27"
    "lat_ctx-2-128k (us)","4.67"
    "lat_ctx-2-256k (us)","5.40"
    "lat_ctx-4-128k (us)","3.69"
    "lat_ctx-4-256k (us)","2.29"
    "lat_fs-0k (num_files)","271.00"
    "lat_fs-10k (num_files)","124.00"
    "lat_fs-1k (num_files)","170.00"
    "lat_fs-4k (num_files)","173.00"
    "lat_mem_rd-stride128-sz1000k (ns)","52.52"
    "lat_mem_rd-stride128-sz125k (ns)","5.56"
    "lat_mem_rd-stride128-sz250k (ns)","5.85"
    "lat_mem_rd-stride128-sz31k (ns)","3.65"
    "lat_mem_rd-stride128-sz50 (ns)","2.15"
    "lat_mem_rd-stride128-sz500k (ns)","15.96"
    "lat_mem_rd-stride128-sz62k (ns)","5.21"
    "lat_mmap-1m (us)","38.00"
    "lat_ops-double-add (ns)","0.52"
    "lat_ops-double-mul (ns)","2.86"
    "lat_ops-float-add (ns)","0.52"
    "lat_ops-float-mul (ns)","2.86"
    "lat_ops-int-add (ns)","0.72"
    "lat_ops-int-bit (ns)","0.48"
    "lat_ops-int-div (ns)","4.30"
    "lat_ops-int-mod (ns)","4.53"
    "lat_ops-int-mul (ns)","2.17"
    "lat_ops-int64-add (ns)","0.72"
    "lat_ops-int64-bit (ns)","0.48"
    "lat_ops-int64-div (ns)","6.79"
    "lat_ops-int64-mod (ns)","5.25"
    "lat_pagefault (us)","1.24"
    "lat_pipe (us)","18.15"
    "lat_proc-exec (us)","1175.80"
    "lat_proc-fork (us)","940.33"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","34.74"
    "lat_sem (us)","1.62"
    "lat_sig-catch (us)","5.07"
    "lat_sig-install (us)","0.48"
    "lat_sig-prot (us)","0.34"
    "lat_syscall-fstat (us)","1.19"
    "lat_syscall-null (us)","0.29"
    "lat_syscall-open (us)","183.90"
    "lat_syscall-read (us)","0.55"
    "lat_syscall-stat (us)","3.17"
    "lat_syscall-write (us)","0.47"
    "lat_tcp (us)","0.60"
    "lat_unix (us)","31.29"
    "latency_for_0.50_mb_block_size (nanosec)","15.96"
    "latency_for_1.00_mb_block_size (nanosec)","26.26 (min 0.00, max 52.52)"
    "pipe_bandwidth (MBs)","498.34"
    "pipe_latency (microsec)","18.15"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","34.74"
    "semaphore_latency (microsec)","1.62"
    "signal_handler_latency (microsec)","0.48"
    "signal_handler_overhead (microsec)","5.07"
    "tcp_ip_connection_cost_to_localhost (microsec)","67.27"
    "tcp_latency_using_localhost (microsec)","0.60"


Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.
  
.. csv-table::
    :header: "Benchmarks","am62xx-evm: perf"

    "cpu_clock (MHz)","1400.00"
    "dhrystone_per_mhz (DMIPS/MHz)","3.00"
    "dhrystone_per_second (DhrystoneP)","7407407.50"


Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am62xx-evm: perf"

    "whetstone (MIPS)","5000.00"

Table:  **Whetstone Benchmark**

Linpack
^^^^^^^

Linpack measures peak double precision (64 bit) floating point performance in
sloving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am62xx-evm: perf"

    "linpack (Kflops)","583950.00"

Table:  **Linpack Benchmark**

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
    :header: "Benchmarks","am62xx-evm: perf"

    "add (MB/s)","1449.20"
    "copy (MB/s)","1674.20"
    "scale (MB/s)","1824.70"
    "triad (MB/s)","1451.10"


Table:  **Stream**

CoreMarkPro
^^^^^^^^^^^

CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.

.. csv-table::
    :header: "Benchmarks","am62xx-evm: perf"

    "cjpeg-rose7-preset (workloads/)","41.84"
    "core (workloads/)","0.30"
    "coremark-pro ()","885.94"
    "linear_alg-mid-100x100-sp (workloads/)","14.69"
    "loops-all-mid-10k-sp (workloads/)","0.66"
    "nnet_test (workloads/)","1.09"
    "parser-125k (workloads/)","8.40"
    "radix2-big-64k (workloads/)","49.79"
    "sha-test (workloads/)","80.65"
    "zip-test (workloads/)","21.28"

Table:  **CoreMarkPro**

.. csv-table::
    :header: "Benchmarks","am62xx-evm: perf"

    "cjpeg-rose7-preset (workloads/)","81.97"
    "core (workloads/)","0.60"
    "coremark-pro ()","1491.23"
    "linear_alg-mid-100x100-sp (workloads/)","29.34"
    "loops-all-mid-10k-sp (workloads/)","1.15"
    "nnet_test (workloads/)","2.19"
    "parser-125k (workloads/)","12.12"
    "radix2-big-64k (workloads/)","36.34"
    "sha-test (workloads/)","161.29"
    "zip-test (workloads/)","40.00"

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
    :header: "Benchmarks","am62xx-evm: perf"

    "4m-check (workloads/)","357.86"
    "4m-check-reassembly (workloads/)","66.84"
    "4m-check-reassembly-tcp (workloads/)","43.86"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","24.66"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.80"
    "4m-cmykw2 (workloads/)","199.40"
    "4m-cmykw2-rotatew2 (workloads/)","39.32"
    "4m-reassembly (workloads/)","51.98"
    "4m-rotatew2 (workloads/)","44.50"
    "4m-tcp-mixed (workloads/)","108.11"
    "4m-x264w2 (workloads/)","1.89"
    "idct-4m (workloads/)","18.58"
    "idct-4mw1 (workloads/)","18.59"
    "ippktcheck-4m (workloads/)","358.32"
    "ippktcheck-4mw1 (workloads/)","359.25"
    "ipres-4m (workloads/)","60.36"
    "ipres-4mw1 (workloads/)","60.10"
    "md5-4m (workloads/)","28.17"
    "md5-4mw1 (workloads/)","28.15"
    "rgbcmyk-4m (workloads/)","63.45"
    "rgbcmyk-4mw1 (workloads/)","63.59"
    "rotate-4ms1 (workloads/)","18.45"
    "rotate-4ms1w1 (workloads/)","18.46"
    "rotate-4ms64 (workloads/)","18.44"
    "rotate-4ms64w1 (workloads/)","18.59"
    "x264-4mq (workloads/)","0.56"
    "x264-4mqw1 (workloads/)","0.56"

Table:  **Multibench**

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am62xx-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","18.06 (min 17.69, max 18.30)"

Table:  **Boot time MMC/SD**

Graphics SGX/RGX Driver
-------------------------

GFXBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Run GFXBench and capture performance reported (Score and Display rate in fps). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am62xx-evm: Score","am62xx-evm: Fps"

    " GFXBench 3.x gl_manhattan_off","87.02","1.40"
    " GFXBench 3.x gl_trex_off","148.73","2.66"
    " GFXBench 5.x gl_5_high_off","11.37","0.18"


Table:  **GFXBench**

Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am62xx-evm: Score"

    "Glmark2-Wayland","189.00"

Table:  **Glmark2**

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
    :header: "Command Used","am62xx-evm: THROUGHPUT (Mbits/sec)","am62xx-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1458.42","44.33"

Table: **CPSW TCP Bidirectional Throughput**

|

.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am62xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx-evm: THROUGHPUT (Mbits/sec)","am62xx-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","13.12","33.31"
    "128","82.00","79.74","44.20"
    "256","210.00","193.69","44.51"
    "1024","978.00","871.77","46.46"
    "1518","1472.00","937.30","42.62"

Table: **CPSW UDP Egress Throughput**

|



.. csv-table::
    :header: "Frame Size(bytes)","am62xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx-evm: THROUGHPUT (Mbits/sec)","am62xx-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.31","3.68"
    "128","82.00","15.88","5.85"
    "256","210.00","25.03","4.10"
    "1024","978.00","111.88","8.14"
    "1518","1472.00","445.11","18.75"

Table: **CPSW UDP Ingress Throughput (0% loss)**

|

.. csv-table::
    :header: "Frame Size(bytes)","am62xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xx-evm: THROUGHPUT (Mbits/sec)","am62xx-evm: CPU Load % (LOCAL_CPU_UTIL)","am62xx-evm: Packet Loss %"

    "64","18.00","25.87","39.82","64.91"
    "128","82.00","118.04","42.27","55.18"
    "256","210.00","274.91","42.15","62.73"
    "1024","978.00","934.70","43.23","0.22"
    "1518","1472.00","955.35","42.99","0.18"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|

OSPI Flash Driver
-------------------------

AM62XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

UBIFS
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Buffer size (bytes)","am62xx-sk: Write UBIFS Throughput (Mbytes/sec)","am62xx-sk: Write UBIFS CPU Load (%)","am62xx-sk: Read UBIFS Throughput (Mbytes/sec)","am62xx-sk: Read UBIFS CPU Load (%)"

    "102400","0.18 (min 0.13, max 0.28)","23.39 (min 23.22, max 23.70)","28.01","6.67"
    "262144","0.14 (min 0.11, max 0.18)","23.44 (min 23.28, max 23.68)","27.84","12.50"
    "524288","0.15 (min 0.12, max 0.18)","23.34 (min 23.21, max 23.40)","27.40","6.67"
    "1048576","0.14 (min 0.11, max 0.19)","23.43 (min 23.31, max 23.65)","27.21","6.45"


RAW
""""""""""""""""""""""""""" 

.. csv-table::
    :header: "File size (Mbytes)","am62xx-sk: Raw Read Throughput (Mbytes/sec)"

    "50","35.97"
|

EMMC Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

AM62XX-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am62xx-evm: Write EXT4 Throughput (Mbytes/sec)","am62xx-evm: Write EXT4 CPU Load (%)","am62xx-evm: Read EXT4 Throughput (Mbytes/sec)","am62xx-evm: Read EXT4 CPU Load (%)"

    "1m","59.30","1.70","174.00","2.17"
    "4m","59.10","1.36","174.00","2.00"
    "4k","50.10","17.97","55.70","17.05"
    "256k","59.90","2.18","173.00","2.73"

|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am62xx-evm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","242568.87"
    "aes-128-cbc","16","5310.18"
    "aes-128-cbc","16384","660701.18"
    "aes-128-cbc","256","76988.59"
    "aes-128-cbc","64","20742.06"
    "aes-128-cbc","8192","588485.97"
    "aes-192-cbc","1024","230238.21"
    "aes-192-cbc","16","5319.15"
    "aes-192-cbc","16384","575406.08"
    "aes-192-cbc","256","75718.31"
    "aes-192-cbc","64","20553.96"
    "aes-192-cbc","8192","519899.82"
    "aes-256-cbc","1024","219307.35"
    "aes-256-cbc","16","5241.28"
    "aes-256-cbc","16384","519159.81"
    "aes-256-cbc","256","73902.68"
    "aes-256-cbc","64","20214.61"
    "aes-256-cbc","8192","475160.58"
    "des-cbc","1024","26249.90"
    "des-cbc","16","5555.70"
    "des-cbc","16384","27683.50"
    "des-cbc","256","22295.30"
    "des-cbc","64","13934.42"
    "des-cbc","8192","27582.46"
    "des3","1024","10878.63"
    "des3","16","4261.01"
    "des3","16384","11250.35"
    "des3","256","9635.07"
    "des3","64","7990.55"
    "des3","8192","11231.23"
    "md5","1024","52667.05"
    "md5","16","1167.63"
    "md5","16384","154211.67"
    "md5","256","16811.01"
    "md5","64","4505.92"
    "md5","8192","136522.41"
    "sha1","1024","62764.37"
    "sha1","16","1095.58"
    "sha1","16384","362845.53"
    "sha1","256","17057.11"
    "sha1","64","4360.00"
    "sha1","8192","274153.47"
    "sha224","1024","61901.48"
    "sha224","16","1076.50"
    "sha224","16384","371212.29"
    "sha224","256","16716.63"
    "sha224","64","4254.83"
    "sha224","8192","276739.41"
    "sha256","1024","62156.80"
    "sha256","16","1080.17"
    "sha256","16384","371829.42"
    "sha256","256","16805.63"
    "sha256","64","4284.84"
    "sha256","8192","277796.18"
    "sha384","1024","36630.19"
    "sha384","16","1049.38"
    "sha384","16384","74148.52"
    "sha384","256","13913.26"
    "sha384","64","4198.98"
    "sha384","8192","69301.59"
    "sha512","1024","36676.27"
    "sha512","16","1046.99"
    "sha512","16384","74295.98"
    "sha512","256","13886.29"
    "sha512","64","4191.04"
    "sha512","8192","69438.12"
|
|

.. csv-table::
    :header: "Algorithm","am62xx-evm: CPU Load"

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

|

::

    time -v openssl speed -elapsed -evp aes-128-cbc


IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am62xx-evm: Throughput (Mbps)","am62xx-evm: Packets/Sec","am62xx-evm: CPU Load"

    "3des","73.20","6.00","26.59"
    "aes128","424.80","37.00","29.53"
    "aes192","419.20","37.00","29.48"
    "aes256","420.10","37.00","29.55"

