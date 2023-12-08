..  http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_RT_Kernel_Performance_Guide

..  http://lcpdresults.itg.ti.com/LCPD/RT-linux/performance/publish/data/08.02.00/am654x-evm/rst/

.. rubric::  **Read This First**
   :name: read-this-first-rt-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+---------------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                         |
+================+=====================================================================================================================+
| AM65x EVM      | AM65x Evaluation Module rev 1.0 with ARM running at 800MHz, DDR4-2400 (1600 MT/S), TMDX654GPEVM                     |
+----------------+---------------------------------------------------------------------------------------------------------------------+


Table:  Evaluation Modules

|

.. rubric::  About This Manual
   :name: about-this-manual-rt-kernel-perf-guide

This document provides performance data for each of the device drivers
which are part of the Process SDK Linux package. This document should be
used in conjunction with release notes and user guides provided with the
Process SDK Linux package for information on specific issues present
with drivers included in a particular release.

.. rubric::  If You Need Assistance
   :name: if-you-need-assistance-rt-kernel-perf-guide

For further information or to report any problems, contact
http://e2e.ti.com/ or http://support.ti.com/


System Benchmarks
-------------------------

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

**Bandwidth**: bw_mem_bcopy-N, where N is is equal to or smaller than the cache size at
a given level measures the achievable memory bandwidth from software doing
a memcpy() type operation. Typical use is for external memory bandwidth
calculation. The bandwidth is calculated as byte read and written counts
as 1 which should be roughly half of STREAM copy result.

.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "af_unix_sock_stream_latency (microsec)",60.48
    "af_unix_socket_stream_bandwidth (MBs)",1107.59
    "bw_file_rd-io-1mb (MB/s)",975.61
    "bw_file_rd-o2c-1mb (MB/s)",502.34
    "bw_mem-bcopy-16mb (MB/s)",878.4
    "bw_mem-bcopy-1mb (MB/s)",1051.89
    "bw_mem-bcopy-2mb (MB/s)",880.67
    "bw_mem-bcopy-4mb (MB/s)",874.41
    "bw_mem-bcopy-8mb (MB/s)",865.99
    "bw_mem-bzero-16mb (MB/s)",1648.8
    "bw_mem-bzero-1mb (MB/s)","2734.88 (min 1051.89, max 4417.86)"
    "bw_mem-bzero-2mb (MB/s)","1605.06 (min 880.67, max 2329.45)"
    "bw_mem-bzero-4mb (MB/s)","1286.46 (min 874.41, max 1698.51)"
    "bw_mem-bzero-8mb (MB/s)","1254.52 (min 865.99, max 1643.05)"
    "bw_mem-cp-16mb (MB/s)",590.17
    "bw_mem-cp-1mb (MB/s)","2522.16 (min 675.11, max 4369.20)"
    "bw_mem-cp-2mb (MB/s)","1460.09 (min 591.89, max 2328.29)"
    "bw_mem-cp-4mb (MB/s)","1143.89 (min 586.85, max 1700.92)"
    "bw_mem-cp-8mb (MB/s)","1117.19 (min 578.91, max 1655.46)"
    "bw_mem-fcp-16mb (MB/s)",822.24
    "bw_mem-fcp-1mb (MB/s)","2690.44 (min 963.02, max 4417.86)"
    "bw_mem-fcp-2mb (MB/s)","1578.75 (min 828.04, max 2329.45)"
    "bw_mem-fcp-4mb (MB/s)","1258.84 (min 819.17, max 1698.51)"
    "bw_mem-fcp-8mb (MB/s)","1232.33 (min 821.61, max 1643.05)"
    "bw_mem-frd-16mb (MB/s)",1275.51
    "bw_mem-frd-1mb (MB/s)","1271.68 (min 963.02, max 1580.33)"
    "bw_mem-frd-2mb (MB/s)","1120.11 (min 828.04, max 1412.18)"
    "bw_mem-frd-4mb (MB/s)","1054.96 (min 819.17, max 1290.74)"
    "bw_mem-frd-8mb (MB/s)","1049.58 (min 821.61, max 1277.55)"
    "bw_mem-fwr-16mb (MB/s)",1646.6
    "bw_mem-fwr-1mb (MB/s)","2974.77 (min 1580.33, max 4369.20)"
    "bw_mem-fwr-2mb (MB/s)","1870.24 (min 1412.18, max 2328.29)"
    "bw_mem-fwr-4mb (MB/s)","1495.83 (min 1290.74, max 1700.92)"
    "bw_mem-fwr-8mb (MB/s)","1466.51 (min 1277.55, max 1655.46)"
    "bw_mem-rd-16mb (MB/s)",1297.54
    "bw_mem-rd-1mb (MB/s)","3319.10 (min 3250.27, max 3387.92)"
    "bw_mem-rd-2mb (MB/s)","1174.07 (min 910.33, max 1437.81)"
    "bw_mem-rd-4mb (MB/s)","1032.56 (min 753.86, max 1311.26)"
    "bw_mem-rd-8mb (MB/s)","1021.93 (min 741.77, max 1302.08)"
    "bw_mem-rdwr-16mb (MB/s)",730.43
    "bw_mem-rdwr-1mb (MB/s)","1861.95 (min 675.11, max 3048.78)"
    "bw_mem-rdwr-2mb (MB/s)","740.19 (min 591.89, max 888.49)"
    "bw_mem-rdwr-4mb (MB/s)","661.28 (min 586.85, max 735.70)"
    "bw_mem-rdwr-8mb (MB/s)","653.29 (min 578.91, max 727.67)"
    "bw_mem-wr-16mb (MB/s)",742.94
    "bw_mem-wr-1mb (MB/s)","3149.53 (min 3048.78, max 3250.27)"
    "bw_mem-wr-2mb (MB/s)","899.41 (min 888.49, max 910.33)"
    "bw_mem-wr-4mb (MB/s)","744.78 (min 735.70, max 753.86)"
    "bw_mem-wr-8mb (MB/s)","734.72 (min 727.67, max 741.77)"
    "bw_mmap_rd-mo-1mb (MB/s)",2662.3
    "bw_mmap_rd-o2c-1mb (MB/s)",529.94
    "bw_pipe (MB/s)",318.65
    "bw_unix (MB/s)",1107.59
    "lat_connect (us)",143.08
    "lat_ctx-2-128k (us)",8.38
    "lat_ctx-2-256k (us)",6.13
    "lat_ctx-4-128k (us)",7.94
    "lat_ctx-4-256k (us)",3.82
    "lat_fs-0k (num_files)",136
    "lat_fs-10k (num_files)",61
    "lat_fs-1k (num_files)",109
    "lat_fs-4k (num_files)",107
    "lat_mem_rd-stride128-sz1000k (ns)",24.99
    "lat_mem_rd-stride128-sz125k (ns)",9.88
    "lat_mem_rd-stride128-sz250k (ns)",10.21
    "lat_mem_rd-stride128-sz31k (ns)",6.39
    "lat_mem_rd-stride128-sz50 (ns)",3.76
    "lat_mem_rd-stride128-sz500k (ns)",11.82
    "lat_mem_rd-stride128-sz62k (ns)",9.16
    "lat_mmap-1m (us)",81
    "lat_ops-double-add (ns)",0.91
    "lat_ops-double-mul (ns)",5.04
    "lat_ops-float-add (ns)",0.91
    "lat_ops-float-mul (ns)",5.03
    "lat_ops-int-add (ns)",1.26
    "lat_ops-int-bit (ns)",0.84
    "lat_ops-int-div (ns)",7.52
    "lat_ops-int-mod (ns)",7.98
    "lat_ops-int-mul (ns)",3.81
    "lat_ops-int64-add (ns)",1.27
    "lat_ops-int64-bit (ns)",0.84
    "lat_ops-int64-div (ns)",11.96
    "lat_ops-int64-mod (ns)",9.23
    "lat_pagefault (us)",1.93
    "lat_pipe (us)",33.24
    "lat_proc-exec (us)",1703.25
    "lat_proc-fork (us)",1468.25
    "lat_proc-proccall (us)",0.01
    "lat_select (us)",55.76
    "lat_sem (us)",8.18
    "lat_sig-catch (us)",9.92
    "lat_sig-install (us)",1.02
    "lat_sig-prot (us)",0.69
    "lat_syscall-fstat (us)",2.44
    "lat_syscall-null (us)",0.5
    "lat_syscall-open (us)",317.94
    "lat_syscall-read (us)",0.98
    "lat_syscall-stat (us)",6.83
    "lat_syscall-write (us)",0.85
    "lat_tcp (us)",1.05
    "lat_unix (us)",60.48
    "latency_for_0.50_mb_block_size (nanosec)",11.82
    "latency_for_1.00_mb_block_size (nanosec)","12.49 (min 0.00, max 24.99)"
    "pipe_bandwidth (MBs)",318.65
    "pipe_latency (microsec)",33.24
    "procedure_call (microsec)",0.01
    "select_on_200_tcp_fds (microsec)",55.76
    "semaphore_latency (microsec)",8.18
    "signal_handler_latency (microsec)",1.02
    "signal_handler_overhead (microsec)",9.92
    "tcp_ip_connection_cost_to_localhost (microsec)",143.08
    "tcp_latency_using_localhost (microsec)",1.05

Table:  **LM Bench Metrics**



Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "cpu_clock (MHz)","800.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.96"
    "dhrystone_per_second (DhrystoneP)","4166666.80"


Table:  **Dhrystone Benchmark**



Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "whetstone (MIPS)","3333.30"


Table:  **Whetstone Benchmark**



Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "linpack (Kflops)","326564.00"


Table:  **Linpack Benchmark**



NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html


.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "assignment (Iterations)","7.82"
    "fourier (Iterations)","12991.00"
    "fp_emulation (Iterations)","61.24"
    "huffman (Iterations)","670.09"
    "idea (Iterations)","1962.70"
    "lu_decomposition (Iterations)","313.09"
    "neural_net (Iterations)","4.48"
    "numeric_sort (Iterations)","283.49"
    "string_sort (Iterations)","94.73"


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

.. csv-table::
    :header: "Benchmarks","am654x-evm: perf"

    "add (MB/s)","2506.20","1625.80"
    "copy (MB/s)","3755.90","1783.80"
    "scale (MB/s)","3313.10","1782.20"
    "triad (MB/s)","2283.10","1521.80"


Table:  **Stream**

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
    :header: "Benchmarks","am654x-evm: perf"

    "4m-check (workloads/)",356.68
    "4m-check-reassembly (workloads/)",69.2
    "4m-check-reassembly-tcp (workloads/)",35.77
    "4m-check-reassembly-tcp-cmykw2-rotatew2 (workloads/)",9.53
    "4m-check-reassembly-tcp-x264w2 (workloads/)",1.13
    "4m-cmykw2 (workloads/)",138.03
    "4m-cmykw2-rotatew2 (workloads/)",9.69
    "4m-reassembly (workloads/)",48.08
    "4m-rotatew2 (workloads/)",13.07
    "4m-tcp-mixed (workloads/)",70.48
    "4m-x264w2 (workloads/)",1.16
    "empty-wld (workloads/)",1
    "idct-4m (workloads/)",10.97
    "idct-4mw1 (workloads/)",10.99
    "ippktcheck-4m (workloads/)",356.63
    "ippktcheck-4mw1 (workloads/)",355.82
    "ipres-4m (workloads/)",62.89
    "ipres-4mw1 (workloads/)",62.47
    "md5-4m (workloads/)",15.04
    "md5-4mw1 (workloads/)",15.07
    "rgbcmyk-4m (workloads/)",36.54
    "rgbcmyk-4mw1 (workloads/)",36.42
    "rotate-4ms1 (workloads/)",14.51
    "rotate-4ms1w1 (workloads/)",14.32
    "rotate-4ms64 (workloads/)",14.52
    "rotate-4ms64w1 (workloads/)",14.53
    "x264-4mq (workloads/)",0.33
    "x264-4mqw1 (workloads/)",0.33

Table:  **MultiBench**


Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am654x-evm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","31.58 (min 31.14, max 32.10)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","5.88"

Table:  **Boot time MMC/SD**


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


ICSSG Ethernet Driver
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput
   :name: tcp-bidirectional-throughput

.. csv-table::
    :header: "Command Used","am65xx-evm: THROUGHPUT (Mbits/sec)","am65xx-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "netperf -H 192.168.4.1 -j -c -C -l 60 -t TCP_STREAM; netperf -H 192.168.3.1 -j -c -C -l 60 -t TCP_MAERTS","1501","40.89"

Table: **ICSSG TCP Bidirectional Throughput**

|



.. rubric::  UDP Throughput
   :name: udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am65xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am65xx-evm: THROUGHPUT (Mbits/sec)","am65xx-evm: CPU Load % (LOCAL_CPU_UTIL)"

    "64","18.00","10.68","43.68"
    "128","82.00","49.11","43.97"
    "256","210.00","125.77","43.90"
    "1024","978.00","638.75","39.42"
    "1518","1472.00","801.59","41.90"

Table: **ICSSG UDP Egress Throughput**

|



.. csv-table::
    :header: "Frame Size(bytes)","am65xx-evm: UDP Datagram Size(bytes) (LOCAL_SEND_SIZE)","am65xx-evm: THROUGHPUT (Mbits/sec)","am65xx-evm: CPU Load %"

    "64","18.00","16.5","45"
    "128","82.00","80.76","46"
    "256","210.00","202","47"
    "1024","978.00","703","45"
    "1518","1472.00","739","42"

Table: **ICSSG UDP Ingress Throughput (0% loss)**



ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64


.. csv-table::
    :header: "Sampling Rate (Hz)","am654x-evm: Throughput (bits/sec)","am654x-evm: CPU Load (%)"

    "8000","255999.00","0.45"
    "11025","352798.00","0.61"
    "16000","511997.00","0.49"
    "22050","705596.00","0.86"
    "24000","705596.00","0.80"
    "32000","1023993.00","0.62"
    "44100","1411190.00","1.18"
    "48000","1535989.00","0.73"
    "88200","2822376.00","1.91"
    "96000","3071973.00","6.12"

Table:  **Audio Capture**

|


Graphics SGX/RGX Driver
-------------------------

Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am654x-evm: Score"

    "Glmark2-Wayland","192.00"


Table:  **Glmark2**

|

Sensor Capture
-------------------------

Performance and Benchmarks not available in this release.

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















AM654x-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","am654x-evm: Write EXT4 Throughput (Mbytes/sec)","am654x-evm: Write EXT4 CPU Load (%)","am654x-evm: Read EXT4 Throughput (Mbytes/sec)","am654x-evm: Read EXT4 CPU Load (%)"

    "1m","28.60","1.37","85.40","1.84"
    "4m","28.60","1.18","85.40","1.66"
    "4k","3.22","3.81","12.40","9.55"
    "256k","24.90","1.57","83.70","2.51"

|





The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|



UART Driver
-------------------------

Performance and Benchmarks not available in this release.

|

I2C Driver
-------------------------

Performance and Benchmarks not available in this release.

|

EDMA Driver
-------------------------

Performance and Benchmarks not available in this release.

|

Touchscreen Driver
-------------------------

Performance and Benchmarks not available in this release.

|




CRYPTO Driver
-------------------------

Performance and Benchmarks not available in this release.




IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am654x-evm: Throughput (Mbps)","am654x-evm: Packets/Sec","am654x-evm: CPU Load"

    "3des","52.40","4.00","59.49"
    "aes256","91.30","8.00","36.35"





DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.


