***********************
Linux Performance Guide
***********************


.. rubric::  **Read This First**

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+-------------------------------------------------------------------------------------------+
| Name           | Description                                                                               |
+================+===========================================================================================+
| AM62x EVM      | AM62x Starter Kit rev E2 and E3 with ARM running at 1400 MHz, DDR4 data rate 1600 MT/S    |
+----------------+-------------------------------------------------------------------------------------------+
| AM62x SK LP    | AM62x LP Starter Kit rev E1 with ARM running at 1250 MHz, LPDDR4 data rate 1600 MT/S      |
+----------------+-------------------------------------------------------------------------------------------+
| AM62SIP SK     | AM62SIP Starter Kit rev E1 with ARM running at 1400 MHz, 512MB LPDDR4 data rate 1600 MT/S |
+----------------+-------------------------------------------------------------------------------------------+

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
    :header: "Benchmarks","am62xxsip_sk-fs: perf"

    "af_unix_sock_stream_latency (microsec)","25.60"
    "af_unix_socket_stream_bandwidth (MBs)","738.75"
    "bw_file_rd-io-1mb (MB/s)","854.85"
    "bw_file_rd-o2c-1mb (MB/s)","511.42"
    "bw_mem-bcopy-16mb (MB/s)","749.38"
    "bw_mem-bcopy-1mb (MB/s)","763.21"
    "bw_mem-bcopy-2mb (MB/s)","728.73"
    "bw_mem-bcopy-4mb (MB/s)","715.18"
    "bw_mem-bcopy-8mb (MB/s)","744.53"
    "bw_mem-bzero-16mb (MB/s)","1735.55"
    "bw_mem-bzero-1mb (MB/s)","1245.17 (min 763.21, max 1727.12)"
    "bw_mem-bzero-2mb (MB/s)","1227.03 (min 728.73, max 1725.33)"
    "bw_mem-bzero-4mb (MB/s)","1220.65 (min 715.18, max 1726.12)"
    "bw_mem-bzero-8mb (MB/s)","1246.68 (min 744.53, max 1748.83)"
    "bw_mem-cp-16mb (MB/s)","429.81"
    "bw_mem-cp-1mb (MB/s)","542.54 (min 421.17, max 663.90)"
    "bw_mem-cp-2mb (MB/s)","512.29 (min 432.43, max 592.15)"
    "bw_mem-cp-4mb (MB/s)","515.79 (min 397.46, max 634.12)"
    "bw_mem-cp-8mb (MB/s)","525.37 (min 414.14, max 636.59)"
    "bw_mem-fcp-16mb (MB/s)","796.85"
    "bw_mem-fcp-1mb (MB/s)","1274.54 (min 821.96, max 1727.12)"
    "bw_mem-fcp-2mb (MB/s)","1243.33 (min 761.32, max 1725.33)"
    "bw_mem-fcp-4mb (MB/s)","1237.59 (min 749.06, max 1726.12)"
    "bw_mem-fcp-8mb (MB/s)","1278.34 (min 807.84, max 1748.83)"
    "bw_mem-frd-16mb (MB/s)","1109.95"
    "bw_mem-frd-1mb (MB/s)","1037.21 (min 821.96, max 1252.46)"
    "bw_mem-frd-2mb (MB/s)","928.11 (min 761.32, max 1094.89)"
    "bw_mem-frd-4mb (MB/s)","926.03 (min 749.06, max 1102.99)"
    "bw_mem-frd-8mb (MB/s)","956.94 (min 807.84, max 1106.04)"
    "bw_mem-fwr-16mb (MB/s)","641.57"
    "bw_mem-fwr-1mb (MB/s)","958.18 (min 663.90, max 1252.46)"
    "bw_mem-fwr-2mb (MB/s)","843.52 (min 592.15, max 1094.89)"
    "bw_mem-fwr-4mb (MB/s)","868.56 (min 634.12, max 1102.99)"
    "bw_mem-fwr-8mb (MB/s)","871.32 (min 636.59, max 1106.04)"
    "bw_mem-rd-16mb (MB/s)","1119.35"
    "bw_mem-rd-1mb (MB/s)","951.36 (min 614.53, max 1288.19)"
    "bw_mem-rd-2mb (MB/s)","842.72 (min 557.72, max 1127.71)"
    "bw_mem-rd-4mb (MB/s)","836.64 (min 561.09, max 1112.19)"
    "bw_mem-rd-8mb (MB/s)","844.63 (min 580.76, max 1108.49)"
    "bw_mem-rdwr-16mb (MB/s)","593.98"
    "bw_mem-rdwr-1mb (MB/s)","513.21 (min 421.17, max 605.24)"
    "bw_mem-rdwr-2mb (MB/s)","486.45 (min 432.43, max 540.47)"
    "bw_mem-rdwr-4mb (MB/s)","481.42 (min 397.46, max 565.37)"
    "bw_mem-rdwr-8mb (MB/s)","499.75 (min 414.14, max 585.35)"
    "bw_mem-wr-16mb (MB/s)","591.69"
    "bw_mem-wr-1mb (MB/s)","609.89 (min 605.24, max 614.53)"
    "bw_mem-wr-2mb (MB/s)","549.10 (min 540.47, max 557.72)"
    "bw_mem-wr-4mb (MB/s)","563.23 (min 561.09, max 565.37)"
    "bw_mem-wr-8mb (MB/s)","583.06 (min 580.76, max 585.35)"
    "bw_mmap_rd-mo-1mb (MB/s)","1277.14"
    "bw_mmap_rd-o2c-1mb (MB/s)","470.15"
    "bw_pipe (MB/s)","536.36"
    "bw_unix (MB/s)","738.75"
    "lat_connect (us)","55.44"
    "lat_ctx-2-128k (us)","5.04"
    "lat_ctx-2-256k (us)","4.65"
    "lat_ctx-4-128k (us)","4.87"
    "lat_ctx-4-256k (us)","5.54"
    "lat_fs-0k (num_files)","283.00"
    "lat_fs-10k (num_files)","113.00"
    "lat_fs-1k (num_files)","142.00"
    "lat_fs-4k (num_files)","152.00"
    "lat_mem_rd-stride128-sz1000k (ns)","52.82"
    "lat_mem_rd-stride128-sz125k (ns)","5.54"
    "lat_mem_rd-stride128-sz250k (ns)","5.84"
    "lat_mem_rd-stride128-sz31k (ns)","3.65"
    "lat_mem_rd-stride128-sz50 (ns)","2.15"
    "lat_mem_rd-stride128-sz500k (ns)","14.16"
    "lat_mem_rd-stride128-sz62k (ns)","5.23"
    "lat_mmap-1m (us)","64.00"
    "lat_ops-double-add (ns)","2.86"
    "lat_ops-double-div (ns)","15.74"
    "lat_ops-double-mul (ns)","2.86"
    "lat_ops-float-add (ns)","2.86"
    "lat_ops-float-div (ns)","9.30"
    "lat_ops-float-mul (ns)","2.86"
    "lat_ops-int-add (ns)","0.72"
    "lat_ops-int-bit (ns)","0.48"
    "lat_ops-int-div (ns)","4.29"
    "lat_ops-int-mod (ns)","4.53"
    "lat_ops-int-mul (ns)","3.07"
    "lat_ops-int64-add (ns)","0.72"
    "lat_ops-int64-bit (ns)","0.48"
    "lat_ops-int64-div (ns)","6.80"
    "lat_ops-int64-mod (ns)","5.25"
    "lat_ops-int64-mul (ns)","3.60"
    "lat_pagefault (us)","1.53"
    "lat_pipe (us)","19.69"
    "lat_proc-exec (us)","1033.83"
    "lat_proc-fork (us)","751.14"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","32.92"
    "lat_sem (us)","2.43"
    "lat_sig-catch (us)","5.45"
    "lat_sig-install (us)","0.64"
    "lat_sig-prot (us)","0.53"
    "lat_syscall-fstat (us)","2.46"
    "lat_syscall-null (us)","0.47"
    "lat_syscall-open (us)","166.64"
    "lat_syscall-read (us)","0.81"
    "lat_syscall-stat (us)","3.48"
    "lat_syscall-write (us)","0.65"
    "lat_tcp (us)","0.92"
    "lat_unix (us)","25.60"
    "latency_for_0.50_mb_block_size (nanosec)","14.16"
    "latency_for_1.00_mb_block_size (nanosec)","26.41 (min 0.00, max 52.82)"
    "pipe_bandwidth (MBs)","536.36"
    "pipe_latency (microsec)","19.69"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","32.92"
    "semaphore_latency (microsec)","2.43"
    "signal_handler_latency (microsec)","0.64"
    "signal_handler_overhead (microsec)","5.45"
    "tcp_ip_connection_cost_to_localhost (microsec)","55.44"
    "tcp_latency_using_localhost (microsec)","0.92"

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
    :header: "Benchmarks","am62xxsip_sk-fs: perf"

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
    :header: "Benchmarks","am62xxsip_sk-fs: perf"

    "whetstone (MIPS)","5000.00"


Table:  **Whetstone Benchmark**



Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am62xxsip_sk-fs: perf"

    "linpack (Kflops)","577808.00"


Table:  **Linpack Benchmark**


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
    :header: "Benchmarks","am62xxsip_sk-fs: perf"

    "add (MB/s)","1372.50"
    "copy (MB/s)","1517.20"
    "scale (MB/s)","1579.70"
    "triad (MB/s)","1358.90"


Table:  **Stream**



CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.


.. csv-table::
    :header: "Benchmarks","am62xxsip_sk-fs: perf"

    "cjpeg-rose7-preset (workloads/)","42.02"
    "core (workloads/)","0.30"
    "coremark-pro ()","844.24"
    "linear_alg-mid-100x100-sp (workloads/)","14.68"
    "loops-all-mid-10k-sp (workloads/)","0.67"
    "nnet_test (workloads/)","1.09"
    "parser-125k (workloads/)","8.20"
    "radix2-big-64k (workloads/)","33.14"
    "sha-test (workloads/)","80.65"
    "zip-test (workloads/)","20.83"


Table:  **CoreMarkPro**



.. csv-table::
    :header: "Benchmarks","am62xxsip_sk-fs: perf"

    "cjpeg-rose7-preset (workloads/)","82.64"
    "core (workloads/)","0.60"
    "coremark-pro ()","1485.93"
    "linear_alg-mid-100x100-sp (workloads/)","29.36"
    "loops-all-mid-10k-sp (workloads/)","1.15"
    "nnet_test (workloads/)","2.18"
    "parser-125k (workloads/)","12.05"
    "radix2-big-64k (workloads/)","36.66"
    "sha-test (workloads/)","161.29"
    "zip-test (workloads/)","38.46"

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
    :header: "Benchmarks","am62xxsip_sk-fs: perf"

    "4m-check (workloads/)","300.95"
    "4m-check-reassembly (workloads/)","64.52"
    "4m-check-reassembly-tcp (workloads/)","42.23"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","24.30"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.80"
    "4m-cmykw2 (workloads/)","199.40"
    "4m-cmykw2-rotatew2 (workloads/)","38.99"
    "4m-reassembly (workloads/)","51.23"
    "4m-rotatew2 (workloads/)","46.00"
    "4m-tcp-mixed (workloads/)","103.90"
    "4m-x264w2 (workloads/)","1.86"
    "idct-4m (workloads/)","18.60"
    "idct-4mw1 (workloads/)","18.59"
    "ippktcheck-4m (workloads/)","302.37"
    "ippktcheck-4mw1 (workloads/)","302.44"
    "ipres-4m (workloads/)","62.89"
    "ipres-4mw1 (workloads/)","63.03"
    "md5-4m (workloads/)","26.32"
    "md5-4mw1 (workloads/)","26.16"
    "rgbcmyk-4m (workloads/)","63.57"
    "rgbcmyk-4mw1 (workloads/)","63.59"
    "rotate-4ms1 (workloads/)","18.44"
    "rotate-4ms1w1 (workloads/)","18.38"
    "rotate-4ms64 (workloads/)","18.45"
    "rotate-4ms64w1 (workloads/)","18.55"
    "x264-4mq (workloads/)","0.56"
    "x264-4mqw1 (workloads/)","0.56"

Table:  **Multibench**

Graphics SGX/RGX Driver
-------------------------





Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am62xxsip_sk-fs: Score"

    "Glmark2-DRM","38.00"
    "Glmark2-Wayland","230.00"


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
    :header: "Command Used","am62xxsip_sk-fs: THROUGHPUT (Mbits/sec)","am62xxsip_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1794.39","65.04"

Table: **CPSW TCP Bidirectional Throughput**

|


.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am62xxsip_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xxsip_sk-fs: THROUGHPUT (Mbits/sec)","am62xxsip_sk-fs: Packets Per Second (kPPS)","am62xxsip_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","18.91","131.00","41.22"
    "128","82.00","83.07","127.00","40.68"
    "256","210.00","209.96","125.00","40.57"
    "1024","978.00","936.49","120.00","46.34"
    "1518","1472.00","956.21","81.00","33.74"

Table: **CPSW UDP Egress Throughput**

|



.. csv-table::
    :header: "Frame Size(bytes)","am62xxsip_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xxsip_sk-fs: THROUGHPUT (Mbits/sec)","am62xxsip_sk-fs: Packets Per Second (kPPS)","am62xxsip_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","8.55","59.00","32.30"
    "128","82.00","40.87","62.00","29.43"
    "256","210.00","18.14","11.00","13.50"
    "1024","978.00","936.81","120.00","41.79"
    "1518","1472.00","957.14","81.00","39.41"

Table: **CPSW UDP Ingress Throughput (0% loss)**


|



.. csv-table::
    :header: "Frame Size(bytes)","am62xxsip_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62xxsip_sk-fs: THROUGHPUT (Mbits/sec)","am62xxsip_sk-fs: Packets Per Second (kPPS)","am62xxsip_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62xxsip_sk-fs: Packet Loss %"

    "64","18.00","27.36","190.00","37.49","66.96"
    "128","82.00","124.60","190.00","39.44","63.76"
    "256","210.00","310.14","185.00","40.51","57.70"
    "1024","978.00","936.76","120.00","41.89","0.01"
    "1518","1472.00","957.14","81.00","39.41","0.00"

Table: **CPSW UDP Ingress Throughput (possible loss)**


CRYPTO Driver
-------------------------


OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am62xxsip_sk-fs: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","24668.50"
    "aes-128-cbc","16","471.19"
    "aes-128-cbc","16384","130078.04"
    "aes-128-cbc","256","7159.13"
    "aes-128-cbc","64","1865.47"
    "aes-128-cbc","8192","98467.84"
    "aes-128-ecb","1024","24683.52"
    "aes-128-ecb","16","486.99"
    "aes-128-ecb","16384","131284.99"
    "aes-128-ecb","256","7433.05"
    "aes-128-ecb","64","1946.86"
    "aes-128-ecb","8192","98686.29"
    "aes-192-cbc","1024","24667.14"
    "aes-192-cbc","16","469.14"
    "aes-192-cbc","16384","120640.85"
    "aes-192-cbc","256","7081.13"
    "aes-192-cbc","64","1862.02"
    "aes-192-cbc","8192","97673.22"
    "aes-192-ecb","1024","24701.61"
    "aes-192-ecb","16","488.36"
    "aes-192-ecb","16384","127309.14"
    "aes-192-ecb","256","7367.85"
    "aes-192-ecb","64","1936.38"
    "aes-192-ecb","8192","98418.69"
    "aes-256-cbc","1024","24620.37"
    "aes-256-cbc","16","469.25"
    "aes-256-cbc","16384","111842.65"
    "aes-256-cbc","256","6967.55"
    "aes-256-cbc","64","1852.03"
    "aes-256-cbc","8192","90614.44"
    "aes-256-ecb","1024","24692.05"
    "aes-256-ecb","16","490.10"
    "aes-256-ecb","16384","118024.87"
    "aes-256-ecb","256","7289.51"
    "aes-256-ecb","64","1932.80"
    "aes-256-ecb","8192","98058.24"
    "des3","1024","9054.21"
    "des3","16","8366.59"
    "des3","16384","9060.35"
    "des3","256","9018.37"
    "des3","64","8873.77"
    "des3","8192","9063.08"
    "md5","1024","140703.40"
    "md5","16","8000.85"
    "md5","16384","189754.03"
    "md5","256","76994.39"
    "md5","64","27382.12"
    "md5","8192","185516.03"
    "sha1","1024","302073.17"
    "sha1","16","8696.27"
    "sha1","16384","608234.15"
    "sha1","256","115893.33"
    "sha1","64","33391.32"
    "sha1","8192","572470.61"
    "sha224","1024","302984.53"
    "sha224","16","9231.09"
    "sha224","16384","580752.73"
    "sha224","256","119728.30"
    "sha224","64","35194.18"
    "sha224","8192","548604.59"
    "sha256","1024","32763.22"
    "sha256","16","561.18"
    "sha256","16384","271226.20"
    "sha256","256","8509.87"
    "sha256","64","2183.10"
    "sha256","8192","190207.32"
    "sha384","1024","105389.40"
    "sha384","16","6124.09"
    "sha384","16384","141208.23"
    "sha384","256","58098.26"
    "sha384","64","24396.03"
    "sha384","8192","138283.69"
    "sha512","1024","24550.06"
    "sha512","16","543.16"
    "sha512","16384","68168.36"
    "sha512","256","7660.97"
    "sha512","64","2190.04"
    "sha512","8192","60582.57"


|
|

.. csv-table::
    :header: "Algorithm","am62xxsip_sk-fs: CPU Load"

    "aes-128-cbc","37.00"
    "aes-128-ecb","39.00"
    "aes-192-cbc","37.00"
    "aes-192-ecb","37.00"
    "aes-256-cbc","36.00"
    "aes-256-ecb","36.00"
    "des3","98.00"
    "md5","98.00"
    "sha1","98.00"
    "sha224","98.00"
    "sha256","98.00"
    "sha384","98.00"
    "sha512","98.00"

|

Listed for each algorithm are the code snippets used to run each benchmark test.

::

    time -v openssl speed -elapsed -evp aes-128-cbc


IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am62xxsip_sk-fs: Throughput (Mbps)","am62xxsip_sk-fs: Packets/Sec","am62xxsip_sk-fs: CPU Load"

    "3des","70.50","6.00","25.14"
    "aes128","279.10","24.00","47.18"
    "aes192","282.70","25.00","47.37"
    "aes256","281.90","25.00","47.42"

