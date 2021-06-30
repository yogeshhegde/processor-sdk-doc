
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
| AM437x-gpevm   | AM437x-gpevm Evaluation Module rev 1.5A with ARM running at 1000MHz, DDR3-400 (400MHz/800 MT/S), TMDSEVM437X   |
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
http://community.ti.com/ or http://support.ti.com/

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

**Bandwidth**: bw_mem_bcopy-N, where N is is equal to or smaller than the cache size at
a given level measures the achievable memory bandwidth from software doing
a memcpy() type operation. Typical use is for external memory bandwidth
calculation. The bandwidth is calculated as byte read and written counts
as 1 which should be roughly half of STREAM copy result.

.. csv-table::
    :header: "Benchmarks","am43xx-gpevm: perf"

    "af_unix_sock_stream_latency (microsec)","31.31"
    "af_unix_socket_stream_bandwidth (MBs)","181.76"
    "bw_file_rd-io-1mb (MB/s)","194.29"
    "bw_file_rd-o2c-1mb (MB/s)","163.32"
    "bw_mem-bcopy-16mb (MB/s)","194.01"
    "bw_mem-bcopy-1mb (MB/s)","199.52"
    "bw_mem-bcopy-2mb (MB/s)","198.12"
    "bw_mem-bcopy-4mb (MB/s)","195.76"
    "bw_mem-bcopy-8mb (MB/s)","198.54"
    "bw_mem-bzero-16mb (MB/s)","672.81"
    "bw_mem-bzero-1mb (MB/s)","437.26 (min 199.52, max 674.99)"
    "bw_mem-bzero-2mb (MB/s)","435.99 (min 198.12, max 673.85)"
    "bw_mem-bzero-4mb (MB/s)","434.75 (min 195.76, max 673.74)"
    "bw_mem-bzero-8mb (MB/s)","436.06 (min 198.54, max 673.57)"
    "bw_mem-cp-16mb (MB/s)","196.02"
    "bw_mem-cp-1mb (MB/s)","438.01 (min 201.13, max 674.88)"
    "bw_mem-cp-2mb (MB/s)","437.50 (min 200.92, max 674.08)"
    "bw_mem-cp-4mb (MB/s)","436.56 (min 199.38, max 673.74)"
    "bw_mem-cp-8mb (MB/s)","437.57 (min 201.79, max 673.34)"
    "bw_mem-fcp-16mb (MB/s)","148.80"
    "bw_mem-fcp-1mb (MB/s)","413.05 (min 151.10, max 674.99)"
    "bw_mem-fcp-2mb (MB/s)","411.22 (min 148.59, max 673.85)"
    "bw_mem-fcp-4mb (MB/s)","411.08 (min 148.42, max 673.74)"
    "bw_mem-fcp-8mb (MB/s)","411.17 (min 148.77, max 673.57)"
    "bw_mem-frd-16mb (MB/s)","204.72"
    "bw_mem-frd-1mb (MB/s)","193.57 (min 151.10, max 236.04)"
    "bw_mem-frd-2mb (MB/s)","177.17 (min 148.59, max 205.74)"
    "bw_mem-frd-4mb (MB/s)","176.51 (min 148.42, max 204.59)"
    "bw_mem-frd-8mb (MB/s)","177.21 (min 148.77, max 205.64)"
    "bw_mem-fwr-16mb (MB/s)","673.34"
    "bw_mem-fwr-1mb (MB/s)","455.46 (min 236.04, max 674.88)"
    "bw_mem-fwr-2mb (MB/s)","439.91 (min 205.74, max 674.08)"
    "bw_mem-fwr-4mb (MB/s)","439.17 (min 204.59, max 673.74)"
    "bw_mem-fwr-8mb (MB/s)","439.49 (min 205.64, max 673.34)"
    "bw_mem-rd-16mb (MB/s)","423.68"
    "bw_mem-rd-1mb (MB/s)","345.92 (min 273.49, max 418.35)"
    "bw_mem-rd-2mb (MB/s)","339.53 (min 269.98, max 409.08)"
    "bw_mem-rd-4mb (MB/s)","347.36 (min 271.70, max 423.01)"
    "bw_mem-rd-8mb (MB/s)","345.77 (min 271.76, max 419.77)"
    "bw_mem-rdwr-16mb (MB/s)","296.01"
    "bw_mem-rdwr-1mb (MB/s)","249.53 (min 201.13, max 297.93)"
    "bw_mem-rdwr-2mb (MB/s)","248.28 (min 200.92, max 295.64)"
    "bw_mem-rdwr-4mb (MB/s)","247.01 (min 199.38, max 294.64)"
    "bw_mem-rdwr-8mb (MB/s)","248.57 (min 201.79, max 295.34)"
    "bw_mem-wr-16mb (MB/s)","271.26"
    "bw_mem-wr-1mb (MB/s)","285.71 (min 273.49, max 297.93)"
    "bw_mem-wr-2mb (MB/s)","282.81 (min 269.98, max 295.64)"
    "bw_mem-wr-4mb (MB/s)","283.17 (min 271.70, max 294.64)"
    "bw_mem-wr-8mb (MB/s)","283.55 (min 271.76, max 295.34)"
    "bw_mmap_rd-mo-1mb (MB/s)","190.62"
    "bw_mmap_rd-o2c-1mb (MB/s)","146.43"
    "bw_pipe (MB/s)","365.84"
    "bw_unix (MB/s)","181.76"
    "lat_connect (us)","68.92"
    "lat_ctx-2-128k (us)","12.54"
    "lat_ctx-2-256k (us)","5.40"
    "lat_ctx-4-128k (us)","0.00"
    "lat_ctx-4-256k (us)","0.00"
    "lat_fs-0k (num_files)","267.00"
    "lat_fs-10k (num_files)","87.00"
    "lat_fs-1k (num_files)","128.00"
    "lat_fs-4k (num_files)","125.00"
    "lat_mem_rd-stride128-sz1000k (ns)","95.75"
    "lat_mem_rd-stride128-sz125k (ns)","16.03"
    "lat_mem_rd-stride128-sz250k (ns)","33.23"
    "lat_mem_rd-stride128-sz31k (ns)","9.24"
    "lat_mem_rd-stride128-sz50 (ns)","4.00"
    "lat_mem_rd-stride128-sz500k (ns)","88.93"
    "lat_mem_rd-stride128-sz62k (ns)","16.39"
    "lat_mmap-1m (us)","55.00"
    "lat_ops-double-add (ns)","1.00"
    "lat_ops-double-mul (ns)","7.03"
    "lat_ops-float-add (ns)","0.91"
    "lat_ops-float-mul (ns)","6.01"
    "lat_ops-int-add (ns)","1.03"
    "lat_ops-int-bit (ns)","0.76"
    "lat_ops-int-div (ns)","157.62"
    "lat_ops-int-mod (ns)","24.75"
    "lat_ops-int-mul (ns)","4.03"
    "lat_ops-int64-add (ns)","1.16"
    "lat_ops-int64-bit (ns)","1.02"
    "lat_ops-int64-div (ns)","186.64"
    "lat_ops-int64-mod (ns)","46.81"
    "lat_pagefault (us)","1.52"
    "lat_pipe (us)","24.81"
    "lat_proc-exec (us)","1468.25"
    "lat_proc-fork (us)","1261.50"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","34.57"
    "lat_sem (us)","6.10"
    "lat_sig-catch (us)","4.37"
    "lat_sig-install (us)","0.91"
    "lat_sig-prot (us)","0.18"
    "lat_syscall-fstat (us)","1.51"
    "lat_syscall-null (us)","0.38"
    "lat_syscall-open (us)","290.00"
    "lat_syscall-read (us)","0.88"
    "lat_syscall-stat (us)","4.38"
    "lat_syscall-write (us)","0.58"
    "lat_tcp (us)","0.80"
    "lat_unix (us)","31.31"
    "latency_for_0.50_mb_block_size (nanosec)","88.93"
    "latency_for_1.00_mb_block_size (nanosec)","47.88 (min 0.00, max 95.75)"
    "pipe_bandwidth (MBs)","365.84"
    "pipe_latency (microsec)","24.81"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","34.57"
    "semaphore_latency (microsec)","6.10"
    "signal_handler_latency (microsec)","0.91"
    "signal_handler_overhead (microsec)","4.37"
    "tcp_ip_connection_cost_to_localhost (microsec)","68.92"
    "tcp_latency_using_localhost (microsec)","0.80"


Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

.. csv-table::
    :header: "Benchmarks","am43xx-gpevm: perf"

    "cpu_clock (MHz)","1000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.50"
    "dhrystone_per_second (DhrystoneP)","4444444.50"


Table:  **Dhrystone Benchmark**

Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am43xx-gpevm: perf"

    "whetstone (MIPS)","3333.30"


Table:  **Whetstone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am43xx-gpevm: perf"

    "linpack (Kflops)","179427.00"


Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html


.. csv-table::
    :header: "Benchmarks","am43xx-gpevm: perf"

    "assignment (Iterations)","7.75"
    "fourier (Iterations)","13312.00"
    "fp_emulation (Iterations)","84.87"
    "huffman (Iterations)","853.13"
    "idea (Iterations)","1372.60"
    "lu_decomposition (Iterations)","341.81"
    "neural_net (Iterations)","9.16"
    "numeric_sort (Iterations)","429.57"
    "string_sort (Iterations)","52.72"


Table:  **NBench Benchmarks**

ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64

.. csv-table::
    :header: "Sampling Rate (Hz)","am43xx-gpevm: Throughput (bits/sec)","am43xx-gpevm: CPU Load (%)"

    "8000","255998.00","0.71"
    "11025","352798.00","0.77"
    "16000","511997.00","0.24"
    "22050","705596.00","1.65"
    "24000","705595.00","1.50"
    "32000","1023993.00","5.30"
    "44100","1411190.00","3.02"
    "48000","1535989.00","0.21"
    "88200","2822376.00","5.85"
    "96000","3071973.00","0.19"

Table:  **Audio Capture**

|

.. csv-table::
    :header: "Sampling Rate (Hz)","am43xx-gpevm: Throughput (bits/sec)","am43xx-gpevm: CPU Load (%)"

    "8000","256103.00","0.21"
    "11025","352942.00","0.75"
    "16000","512206.00","0.23"
    "22050","705883.00","1.54"
    "24000","705883.00","1.46"
    "32000","1024411.00","0.15"
    "44100","1411766.00","2.91"
    "48000","1536616.00","0.04"
    "88200","2823528.00","5.68"
    "96000","3073227.00","0.31"

Table:  **Audio Playback**

|

Graphics SGX/RGX Driver
-------------------------

GLBenchmark
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run GLBenchmark and capture performance reported Display rate (Fps),
Fill rate, Vertex Throughput, etc. All display outputs (HDMI, Displayport and/or LCD)
are connected when running these tests

Performance (Fps)
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Benchmark","am43xx-gpevm: Test Number","am43xx-gpevm: Fps"

    "GLB25_EgyptTestC24Z16FixedTime test","2500005.00","4.49 (min 2.15, max 11.71)"
    "GLB25_EgyptTestC24Z16_ETC1 test","2501001.00","5.34 (min 2.20, max 11.90)"
    "GLB25_EgyptTestC24Z16_ETC1to565 test","2501401.00","5.34 (min 2.20, max 11.90)"
    "GLB25_EgyptTestC24Z16_PVRTC4 test","2501101.00","5.20 (min 2.15, max 11.71)"
    "GLB25_EgyptTestC24Z24MS4 test","2500003.00","4.28 (min 1.19, max 9.60)"
    "GLB25_EgyptTestStandard_inherited test","2000000.00","16.02 (min 10.91, max 22.08)"




Table:  **GLBenchmark 2.5 Performance**

Vertex Throughput
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Benchmark","am43xx-gpevm: Test Number","am43xx-gpevm: Rate (triangles/sec)"

    "GLB25_TriangleTexFragmentLitTestC24Z16 test","2500511.00","2297500.25"
    "GLB25_TriangleTexTestC24Z16 test","2500301.00","11208974.00"
    "GLB25_TriangleTexVertexLitTestC24Z16 test","2500411.00","4232234.00"


Table:  **GLBenchmark 2.5 Vertex Throughput**

Pixel Throughput
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Benchmark","am43xx-gpevm: Test Number","am43xx-gpevm: Rate (texel/sec)","am43xx-gpevm: Fps"

    "GLB25_FillTestC24Z16 test","2500101.00","97853872.00","3.98 (min 3.97, max 4.02)"


Table:  **GLBenchmark 2.5 Pixel Throughput**

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

CPSW Ethernet Driver
^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput
   :name: tcp-bidirectional-throughput

.. csv-table::
    :header: "TCP Window Size","am43xx-gpevm: Throughput (Mbits/sec)","am43xx-gpevm: CPU Load %"

    "Default","416.31","100.00"

Table: **CPSW TCP Bidirectional Throughput**

.. rubric::  UDP Throughput (0% loss)
   :name: udp-throughput-0-loss

.. csv-table::
    :header: "Frame Size(bytes)","am43xx-gpevm: UDP Datagram Size(bytes)","am43xx-gpevm: Throughput (Mbits/sec)","am43xx-gpevm: CPU Load %"

    "64","18.00","6.68","100.00"
    "128","82.00","30.11","100.00"
    "256","210.00","74.29","100.00"
    "1024","978.00","284.06","100.00"

Table: **CPSW UDP Egress Throughput (0% loss)**

.. csv-table::
    :header: "Frame Size(bytes)","am43xx-gpevm: UDP Datagram Size(bytes)","am43xx-gpevm: Throughput (Mbits/sec)","am43xx-gpevm: CPU Load %"

    "64","18.00","1.05","49.58"
    "128","82.00","4.59","49.08"
    "256","210.00","9.58","0.50"
    "1024","978.00","14.08","0.20"
    "1518","1472.00","41.22","0.41"

Table: **CPSW UDP Ingress Throughput (0% loss)**

.. rubric::  UDP Throughput (possible loss)
   :name: udp-throughput-possible-loss

.. csv-table::
    :header: "Frame Size(bytes)","am43xx-gpevm: UDP Datagram Size(bytes)","am43xx-gpevm: Throughput (Mbits/sec)","am43xx-gpevm: CPU Load %","am43xx-gpevm: Packet Loss %"

    "64","18.00","6.68","100.00","0.00"
    "128","82.00","30.11","100.00","0.00"
    "256","210.00","74.29","100.00","0.00"
    "1024","978.00","284.06","100.00","0.00"

Table: **CPSW UDP Egress Throughput (possible loss)**

.. csv-table::
    :header: "Frame Size(bytes)","am43xx-gpevm: UDP Datagram Size(bytes)","am43xx-gpevm: Throughput (Mbits/sec)","am43xx-gpevm: CPU Load %","am43xx-gpevm: Packet Loss %"

    "64","18.00","4.22","100.00","88.35"
    "128","82.00","18.46","100.02","89.13"
    "256","210.00","39.26","100.12","73.19"
    "1024","978.00","17.19","100.08","97.41"
    "1518","1472.00","69.14","98.23","92.17"

Table: **CPSW UDP Ingress Throughput (possible loss)**

|

NAND Driver
-------------------------





AM43XX-GPEVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am43xx-gpevm: Write UBIFS Throughput (Mbytes/sec)","am43xx-gpevm: Write UBIFS CPU Load (%)","am43xx-gpevm: Read UBIFS Throughput (Mbytes/sec)","am43xx-gpevm: Read UBIFS CPU Load (%)"

    "102400","6.59 (min 6.45, max 6.90)","69.10 (min 67.82, max 69.69)","10.31","38.59"
    "262144","6.50 (min 6.43, max 6.54)","69.60 (min 69.35, max 69.84)","10.28","40.45"
    "524288","6.51 (min 6.47, max 6.55)","69.61 (min 69.29, max 69.86)","10.35","40.65"
    "1048576","6.51 (min 6.46, max 6.54)","69.59 (min 69.26, max 69.91)","10.35","38.95"
    "5242880","6.50 (min 6.47, max 6.53)","69.48 (min 68.57, max 70.24)","10.29","40.12"



CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^


::

    time -v openssl speed -elapsed -evp aes-128-cbc


IPSec Hardware Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Note: queue\_len is set to 300 and software fallback threshold set to 9
to enable software support for optimal performance

.. csv-table::
    :header: "Algorithm","am43xx-gpevm: Throughput (Mbps)","am43xx-gpevm: Packets/Sec","am43xx-gpevm: CPU Load"

    "aes128","0.10","0.00","99.32"
    "aes192","0.00","0.00","100.94"


IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am43xx-gpevm: Throughput (Mbps)","am43xx-gpevm: Packets/Sec","am43xx-gpevm: CPU Load"

    "3des","36.00","3.00","98.39"
    "aes128","1.40","0.00","99.90"
    "aes192","1.40","0.00","99.95"
    "aes256","1.40","0.00","100.00"


DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.
