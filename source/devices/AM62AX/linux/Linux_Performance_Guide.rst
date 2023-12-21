
======================================
 Linux Performance Guide
======================================

.. rubric::  **Read This First**
   :name: read-this-first-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| AM62Ax SK      | AM62Ax Starter Kit with ARM running at 1.2GHz, DDR data rate 3733 MT/S                                         |
+----------------+----------------------------------------------------------------------------------------------------------------+

Table:  Evaluation Modules

.. rubric::  About This Manual
   :name: about-this-manual-kernel-perf-guide

This document provides performance data for each of the device drivers
which are part of the Processor SDK Linux package. This document should be
used in conjunction with release notes and user guides provided with the
Processor SDK Linux package for information on specific issues present
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

Execute the LMBench with the following:

::

    cd /opt/ltp
    ./runltp -P j721e-idk-gw -f ddt/lmbench -s LMBENCH_L_PERF_0001

.. csv-table:: LMBench Benchmarks
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "af_unix_sock_stream_latency (microsec)","28.28"
    "af_unix_socket_stream_bandwidth (MBs)","1177.00"
    "bw_file_rd-io-1mb (MB/s)","1215.91"
    "bw_file_rd-o2c-1mb (MB/s)","706.46"
    "bw_mem-bcopy-16mb (MB/s)","1947.66"
    "bw_mem-bcopy-1mb (MB/s)","2024.29"
    "bw_mem-bcopy-2mb (MB/s)","1891.25"
    "bw_mem-bcopy-4mb (MB/s)","1907.18"
    "bw_mem-bcopy-8mb (MB/s)","1871.13"
    "bw_mem-bzero-16mb (MB/s)","7448.79"
    "bw_mem-bzero-1mb (MB/s)","4733.08 (min 2024.29, max 7441.86)"
    "bw_mem-bzero-2mb (MB/s)","4664.42 (min 1891.25, max 7437.58)"
    "bw_mem-bzero-4mb (MB/s)","4673.58 (min 1907.18, max 7439.97)"
    "bw_mem-bzero-8mb (MB/s)","4658.81 (min 1871.13, max 7446.48)"
    "bw_mem-cp-16mb (MB/s)","960.73"
    "bw_mem-cp-1mb (MB/s)","1266.00 (min 927.82, max 1604.17)"
    "bw_mem-cp-2mb (MB/s)","1147.56 (min 902.12, max 1393.00)"
    "bw_mem-cp-4mb (MB/s)","1205.81 (min 988.63, max 1422.98)"
    "bw_mem-cp-8mb (MB/s)","1242.56 (min 1010.74, max 1474.38)"
    "bw_mem-fcp-16mb (MB/s)","1779.36"
    "bw_mem-fcp-1mb (MB/s)","4584.49 (min 1727.12, max 7441.86)"
    "bw_mem-fcp-2mb (MB/s)","4507.68 (min 1577.78, max 7437.58)"
    "bw_mem-fcp-4mb (MB/s)","4593.48 (min 1746.98, max 7439.97)"
    "bw_mem-fcp-8mb (MB/s)","4601.11 (min 1755.73, max 7446.48)"
    "bw_mem-frd-16mb (MB/s)","1934.94"
    "bw_mem-frd-1mb (MB/s)","1854.55 (min 1727.12, max 1981.98)"
    "bw_mem-frd-2mb (MB/s)","1737.48 (min 1577.78, max 1897.17)"
    "bw_mem-frd-4mb (MB/s)","1804.88 (min 1746.98, max 1862.78)"
    "bw_mem-frd-8mb (MB/s)","1795.61 (min 1755.73, max 1835.49)"
    "bw_mem-fwr-16mb (MB/s)","1481.21"
    "bw_mem-fwr-1mb (MB/s)","1793.08 (min 1604.17, max 1981.98)"
    "bw_mem-fwr-2mb (MB/s)","1645.09 (min 1393.00, max 1897.17)"
    "bw_mem-fwr-4mb (MB/s)","1642.88 (min 1422.98, max 1862.78)"
    "bw_mem-fwr-8mb (MB/s)","1654.94 (min 1474.38, max 1835.49)"
    "bw_mem-rd-16mb (MB/s)","1999.25"
    "bw_mem-rd-1mb (MB/s)","2154.08 (min 2042.55, max 2265.60)"
    "bw_mem-rd-2mb (MB/s)","1891.98 (min 1808.65, max 1975.31)"
    "bw_mem-rd-4mb (MB/s)","1914.89 (min 1835.42, max 1994.35)"
    "bw_mem-rd-8mb (MB/s)","1953.29 (min 1897.53, max 2009.04)"
    "bw_mem-rdwr-16mb (MB/s)","1960.54"
    "bw_mem-rdwr-1mb (MB/s)","1454.72 (min 927.82, max 1981.62)"
    "bw_mem-rdwr-2mb (MB/s)","1300.25 (min 902.12, max 1698.37)"
    "bw_mem-rdwr-4mb (MB/s)","1360.74 (min 988.63, max 1732.85)"
    "bw_mem-rdwr-8mb (MB/s)","1460.25 (min 1010.74, max 1909.76)"
    "bw_mem-wr-16mb (MB/s)","1921.00"
    "bw_mem-wr-1mb (MB/s)","2012.09 (min 1981.62, max 2042.55)"
    "bw_mem-wr-2mb (MB/s)","1753.51 (min 1698.37, max 1808.65)"
    "bw_mem-wr-4mb (MB/s)","1784.14 (min 1732.85, max 1835.42)"
    "bw_mem-wr-8mb (MB/s)","1903.65 (min 1897.53, max 1909.76)"
    "bw_mmap_rd-mo-1mb (MB/s)","2265.43"
    "bw_mmap_rd-o2c-1mb (MB/s)","695.41"
    "bw_pipe (MB/s)","673.09"
    "bw_unix (MB/s)","1177.00"
    "lat_connect (us)","57.73"
    "lat_ctx-2-128k (us)","5.88"
    "lat_ctx-2-256k (us)","5.92"
    "lat_ctx-4-128k (us)","5.16"
    "lat_ctx-4-256k (us)","3.03"
    "lat_fs-0k (num_files)","302.00"
    "lat_fs-10k (num_files)","120.00"
    "lat_fs-1k (num_files)","171.00"
    "lat_fs-4k (num_files)","163.00"
    "lat_mem_rd-stride128-sz1000k (ns)","30.00"
    "lat_mem_rd-stride128-sz125k (ns)","6.24"
    "lat_mem_rd-stride128-sz250k (ns)","6.53"
    "lat_mem_rd-stride128-sz31k (ns)","4.69"
    "lat_mem_rd-stride128-sz50 (ns)","2.40"
    "lat_mem_rd-stride128-sz500k (ns)","10.54"
    "lat_mem_rd-stride128-sz62k (ns)","5.87"
    "lat_mmap-1m (us)","53.00"
    "lat_ops-double-add (ns)","3.20"
    "lat_ops-double-div (ns)","17.63"
    "lat_ops-double-mul (ns)","3.21"
    "lat_ops-float-add (ns)","3.21"
    "lat_ops-float-div (ns)","10.42"
    "lat_ops-float-mul (ns)","3.20"
    "lat_ops-int-add (ns)","0.80"
    "lat_ops-int-bit (ns)","0.53"
    "lat_ops-int-div (ns)","4.81"
    "lat_ops-int-mod (ns)","5.08"
    "lat_ops-int-mul (ns)","3.44"
    "lat_ops-int64-add (ns)","0.80"
    "lat_ops-int64-bit (ns)","0.53"
    "lat_ops-int64-div (ns)","7.61"
    "lat_ops-int64-mod (ns)","5.88"
    "lat_ops-int64-mul (ns)","4.05"
    "lat_pagefault (us)","1.42"
    "lat_pipe (us)","22.34"
    "lat_proc-exec (us)","762.14"
    "lat_proc-fork (us)","629.56"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","37.17"
    "lat_sem (us)","2.27"
    "lat_sig-catch (us)","6.05"
    "lat_sig-install (us)","0.72"
    "lat_sig-prot (us)","0.48"
    "lat_syscall-fstat (us)","2.73"
    "lat_syscall-null (us)","0.52"
    "lat_syscall-open (us)","257.84"
    "lat_syscall-read (us)","0.84"
    "lat_syscall-stat (us)","3.78"
    "lat_syscall-write (us)","0.72"
    "lat_tcp (us)","0.99"
    "lat_unix (us)","28.28"
    "latency_for_0.50_mb_block_size (nanosec)","10.54"
    "latency_for_1.00_mb_block_size (nanosec)","15.00 (min 0.00, max 30.00)"
    "pipe_bandwidth (MBs)","673.09"
    "pipe_latency (microsec)","22.34"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","37.17"
    "semaphore_latency (microsec)","2.27"
    "signal_handler_latency (microsec)","0.72"
    "signal_handler_overhead (microsec)","6.05"
    "tcp_ip_connection_cost_to_localhost (microsec)","57.73"
    "tcp_latency_using_localhost (microsec)","0.99"




Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

Execute the benchmark with the following:

::

    runDhrystone

.. csv-table:: Dhrystone Benchmarks
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "cpu_clock (MHz)","1250.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.90"
    "dhrystone_per_second (DhrystoneP)","6451613.00"




Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Whetstone is a benchmark primarily measuring floating-point arithmetic performance.

Execute the benchmark with the following:

::

    runWhetstone

.. csv-table:: Whetstone Benchmarks
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "whetstone (MIPS)","5000.00"




Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table:: Linpack Benchmarks
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "linpack (Kflops)","516913.00"




NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html

.. csv-table:: NBench Benchmarks
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "assignment (Iterations)","12.41"
    "fourier (Iterations)","20212.00"
    "fp_emulation (Iterations)","82.43"
    "huffman (Iterations)","1044.10"
    "idea (Iterations)","3075.80"
    "lu_decomposition (Iterations)","476.39"
    "neural_net (Iterations)","7.88"
    "numeric_sort (Iterations)","534.52"
    "string_sort (Iterations)","147.28"




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

.. csv-table:: Stream Benchmarks
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "add (MB/s)","2646.90"
    "copy (MB/s)","3943.30"
    "scale (MB/s)","3457.20"
    "triad (MB/s)","2362.50"




CoreMarkPro
^^^^^^^^^^^^^^^^^^^^^^^^^^^
CoreMark®-Pro is a comprehensive, advanced processor benchmark that works with
and enhances the market-proven industry-standard EEMBC CoreMark® benchmark.
While CoreMark stresses the CPU pipeline, CoreMark-Pro tests the entire processor,
adding comprehensive support for multicore technology, a combination of integer
and floating-point workloads, and data sets for utilizing larger memory subsystems.


.. csv-table:: CoreMarkPro Benchmarks
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "cjpeg-rose7-preset (workloads/)","37.59"
    "core (workloads/)","0.27"
    "coremark-pro ()","853.15"
    "linear_alg-mid-100x100-sp (workloads/)","13.10"
    "loops-all-mid-10k-sp (workloads/)","0.65"
    "nnet_test (workloads/)","0.97"
    "parser-125k (workloads/)","7.87"
    "radix2-big-64k (workloads/)","70.41"
    "sha-test (workloads/)","72.99"
    "zip-test (workloads/)","20.00"



 
 


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

.. csv-table:: Multibench Benchmarks
    :header: "Benchmarks","am62axx_sk-fs: perf"

    "4m-check (workloads/)","393.45"
    "4m-check-reassembly (workloads/)","126.10"
    "4m-check-reassembly-tcp (workloads/)","57.47"
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)","31.45"
    "4m-check-reassembly-tcp-x264w2 (workloads/)","1.75"
    "4m-cmykw2 (workloads/)","223.96"
    "4m-cmykw2-rotatew2 (workloads/)","46.30"
    "4m-reassembly (workloads/)","85.54"
    "4m-rotatew2 (workloads/)","49.73"
    "4m-tcp-mixed (workloads/)","108.11"
    "4m-x264w2 (workloads/)","1.82"
    "idct-4m (workloads/)","17.23"
    "idct-4mw1 (workloads/)","17.24"
    "ippktcheck-4m (workloads/)","394.45"
    "ippktcheck-4mw1 (workloads/)","394.95"
    "ipres-4m (workloads/)","111.36"
    "ipres-4mw1 (workloads/)","109.97"
    "md5-4m (workloads/)","26.45"
    "md5-4mw1 (workloads/)","26.20"
    "rgbcmyk-4m (workloads/)","59.03"
    "rgbcmyk-4mw1 (workloads/)","59.03"
    "rotate-4ms1 (workloads/)","22.08"
    "rotate-4ms1w1 (workloads/)","22.12"
    "rotate-4ms64 (workloads/)","22.29"
    "rotate-4ms64w1 (workloads/)","22.22"
    "x264-4mq (workloads/)","0.52"
    "x264-4mqw1 (workloads/)","0.52"



 
 



|

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: Boot time MMCSD
    :header: "Boot Configuration","am62axx_sk-fs: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","27.48 (min 26.22, max 31.25)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","4.09 (min 4.07, max 4.18)"



 
 



|

ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64


.. csv-table:: Audio Capture
    :header: "Sampling Rate (Hz)","am62axx_sk-fs: Throughput (bits/sec)","am62axx_sk-fs: CPU Load (%)"

    "8000","255998.00","0.13"
    "11025","352798.00","0.17"
    "16000","511996.00","0.13"
    "22050","705595.00","0.29"
    "24000","705595.00","0.27"
    "32000","1023992.00","0.20"
    "44100","1411189.00","0.44"
    "48000","1535988.00","1.17"
    "88200","2822375.00","0.84"
    "96000","3071971.00","2.27"



 

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

- CPSW3g: AM62ax


.. rubric::  TCP Bidirectional Throughput 
   :name: CPSW2g-tcp-bidirectional-throughput

.. csv-table:: CPSW2g TCP Bidirectional Throughput
    :header: "Command Used","am62axx_sk-fs: THROUGHPUT (Mbits/sec)","am62axx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.0.1 -j -c -C -l 60 -t TCP_MAERTS","1862.94","84.29"






.. rubric::  UDP Throughput
   :name: CPSW2g-udp-throughput-0-loss

.. csv-table:: CPSW2g UDP Egress Throughput 0 loss
    :header: "Frame Size(bytes)","am62axx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62axx_sk-fs: THROUGHPUT (Mbits/sec)","am62axx_sk-fs: Packets Per Second (kPPS)","am62axx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","18.05","125.00","68.35"
    "128","82.00","79.39","121.00","67.67"
    "256","210.00","75.25","45.00","41.44"
    "1024","978.00","706.46","90.00","59.08"
    "1518","1472.00","955.30","81.00","62.02"




.. csv-table:: CPSW2g UDP Ingress Throughput 0 loss
    :header: "Frame Size(bytes)","am62axx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62axx_sk-fs: THROUGHPUT (Mbits/sec)","am62axx_sk-fs: Packets Per Second (kPPS)","am62axx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","1.67","12.00","27.00"
    "128","82.00","13.38","20.00","31.92"
    "256","210.00","16.80","10.00","27.53"
    "1024","978.00","482.74","62.00","45.94"
    "1518","1472.00","493.41","42.00","46.77"




.. csv-table:: CPSW2g UDP Ingress Throughput possible loss
    :header: "Frame Size(bytes)","am62axx_sk-fs: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am62axx_sk-fs: THROUGHPUT (Mbits/sec)","am62axx_sk-fs: Packets Per Second (kPPS)","am62axx_sk-fs: CPU Load % (LOCAL_CPU_UTIL)","am62axx_sk-fs: Packet Loss %"

    "64","18.00","26.75","186.00","64.09","56.00"
    "128","82.00","122.03","186.00","66.82","57.86"
    "256","210.00","307.61","183.00","66.37","57.08"
    "1024","978.00","936.35","120.00","67.50","0.04"
    "1518","1472.00","956.64","81.00","66.79","0.04"

 



|

EMMC Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.





AM62AXX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: EMMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","am62axx_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62axx_sk-fs: Write EXT4 CPU Load (%)","am62axx_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62axx_sk-fs: Read EXT4 CPU Load (%)"

    "1m","61.10","1.09","175.00","1.63"
    "4m","60.90","0.80","175.00","1.46"
    "4k","52.70","20.25","56.80","19.42"
    "256k","60.90","1.50","174.00","2.23"





|

UBoot EMMC Driver
-------------------------

 


AM62AXX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT EMMC RAW
    :header: "File size (bytes in hex)","am62axx_sk-fs: Write Throughput (Kbytes/sec)","am62axx_sk-fs: Read Throughput (Kbytes/sec)"

    "2000000","60346.22","170666.67"
    "4000000","61077.35","173375.66"



|

MMC/SD Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

 

 



AM62AXX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: MMC EXT4 FIO 1G
    :header: "Buffer size (bytes)","am62axx_sk-fs: Write EXT4 Throughput (Mbytes/sec)","am62axx_sk-fs: Write EXT4 CPU Load (%)","am62axx_sk-fs: Read EXT4 Throughput (Mbytes/sec)","am62axx_sk-fs: Read EXT4 CPU Load (%)"

    "1m","28.00","0.59","69.70","1.02"
    "4m","28.10","0.54","64.80","0.67"
    "4k","5.39","2.46","19.60","6.68"
    "256k","27.70","0.77","76.20","1.25"


 

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option
 



|

UBoot MMC/SD Driver
-------------------------

  


AM62AXX-SK
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: UBOOT MMCSD FAT
    :header: "File size (bytes in hex)","am62axx_sk-fs: Write Throughput (Kbytes/sec)","am62axx_sk-fs: Read Throughput (Kbytes/sec)"

    "400000","18703.20","20078.43"
    "800000","21614.78","21557.89"
    "1000000","21758.30","22413.13"




|

CRYPTO Driver
-------------------------


OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: OpenSSL Performance
    :header: "Algorithm","Buffer Size (in bytes)","am62axx_sk-fs: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","24493.40"
    "aes-128-cbc","16","491.77"
    "aes-128-cbc","16384","85409.79"
    "aes-128-cbc","256","7348.05"
    "aes-128-cbc","64","1956.33"
    "aes-128-cbc","8192","72952.49"
    "aes-128-ecb","1024","25098.58"
    "aes-128-ecb","16","505.18"
    "aes-128-ecb","16384","87949.31"
    "aes-128-ecb","256","7592.11"
    "aes-128-ecb","64","2009.32"
    "aes-128-ecb","8192","75172.52"
    "aes-192-cbc","1024","23974.57"
    "aes-192-cbc","16","495.65"
    "aes-192-cbc","16384","77583.70"
    "aes-192-cbc","256","7340.03"
    "aes-192-cbc","64","1962.22"
    "aes-192-cbc","8192","66887.68"
    "aes-192-ecb","1024","24654.85"
    "aes-192-ecb","16","506.17"
    "aes-192-ecb","16384","79915.69"
    "aes-192-ecb","256","7461.72"
    "aes-192-ecb","64","2013.14"
    "aes-192-ecb","8192","69036.71"
    "aes-256-cbc","1024","23431.85"
    "aes-256-cbc","16","489.40"
    "aes-256-cbc","16384","70926.34"
    "aes-256-cbc","256","7307.61"
    "aes-256-cbc","64","1969.45"
    "aes-256-cbc","8192","61950.63"
    "aes-256-ecb","1024","24079.36"
    "aes-256-ecb","16","503.22"
    "aes-256-ecb","16384","72182.44"
    "aes-256-ecb","256","7440.73"
    "aes-256-ecb","64","2001.90"
    "aes-256-ecb","8192","63294.12"
    "sha256","1024","32196.61"
    "sha256","16","540.77"
    "sha256","16384","253640.70"
    "sha256","256","8438.53"
    "sha256","64","2135.04"
    "sha256","8192","173241.69"
    "sha512","1024","22995.63"
    "sha512","16","535.95"
    "sha512","16384","60861.10"
    "sha512","256","7622.23"
    "sha512","64","2144.87"
    "sha512","8192","54788.10"




.. csv-table:: OpenSSL CPU Load
    :header: "Algorithm","am62axx_sk-fs: CPU Load"

    "aes-128-cbc","33.00"
    "aes-128-ecb","34.00"
    "aes-192-cbc","33.00"
    "aes-192-ecb","33.00"
    "aes-256-cbc","32.00"
    "aes-256-ecb","33.00"
    "sha256","97.00"
    "sha512","97.00"



Listed for each algorithm are the code snippets used to run each
  benchmark test.

::

    time -v openssl speed -elapsed -evp aes-128-cbc

 




IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table:: IPSec Software Performance
    :header: "Algorithm","am62axx_sk-fs: Throughput (Mbps)","am62axx_sk-fs: Packets/Sec","am62axx_sk-fs: CPU Load"

    "3des","65.90","5.00","25.12"
    "aes128","366.40","32.00","48.93"
    "aes192","351.30","31.00","49.43"
    "aes256","0.00","0.00","43.01"

 
 

|


