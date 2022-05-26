
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

    "af_unix_sock_stream_latency (microsec)","34.57"
    "af_unix_socket_stream_bandwidth (MBs)","175.48"
    "bw_file_rd-io-1mb (MB/s)","197.67"
    "bw_file_rd-o2c-1mb (MB/s)","165.07"
    "bw_mem-bcopy-16mb (MB/s)","193.85"
    "bw_mem-bcopy-1mb (MB/s)","200.04"
    "bw_mem-bcopy-2mb (MB/s)","197.75"
    "bw_mem-bcopy-4mb (MB/s)","196.36"
    "bw_mem-bcopy-8mb (MB/s)","198.93"
    "bw_mem-bzero-16mb (MB/s)","673.15"
    "bw_mem-bzero-1mb (MB/s)","438.32 (min 200.04, max 676.59)"
    "bw_mem-bzero-2mb (MB/s)","436.15 (min 197.75, max 674.54)"
    "bw_mem-bzero-4mb (MB/s)","435.22 (min 196.36, max 674.08)"
    "bw_mem-bzero-8mb (MB/s)","436.25 (min 198.93, max 673.57)"
    "bw_mem-cp-16mb (MB/s)","195.84"
    "bw_mem-cp-1mb (MB/s)","438.99 (min 201.27, max 676.70)"
    "bw_mem-cp-2mb (MB/s)","437.11 (min 199.56, max 674.65)"
    "bw_mem-cp-4mb (MB/s)","436.95 (min 199.70, max 674.20)"
    "bw_mem-cp-8mb (MB/s)","437.74 (min 201.73, max 673.74)"
    "bw_mem-fcp-16mb (MB/s)","148.60"
    "bw_mem-fcp-1mb (MB/s)","413.64 (min 150.69, max 676.59)"
    "bw_mem-fcp-2mb (MB/s)","411.45 (min 148.35, max 674.54)"
    "bw_mem-fcp-4mb (MB/s)","411.04 (min 148.00, max 674.08)"
    "bw_mem-fcp-8mb (MB/s)","411.12 (min 148.67, max 673.57)"
    "bw_mem-frd-16mb (MB/s)","207.99"
    "bw_mem-frd-1mb (MB/s)","197.12 (min 150.69, max 243.55)"
    "bw_mem-frd-2mb (MB/s)","180.52 (min 148.35, max 212.68)"
    "bw_mem-frd-4mb (MB/s)","177.30 (min 148.00, max 206.59)"
    "bw_mem-frd-8mb (MB/s)","178.53 (min 148.67, max 208.38)"
    "bw_mem-fwr-16mb (MB/s)","673.12"
    "bw_mem-fwr-1mb (MB/s)","460.13 (min 243.55, max 676.70)"
    "bw_mem-fwr-2mb (MB/s)","443.67 (min 212.68, max 674.65)"
    "bw_mem-fwr-4mb (MB/s)","440.40 (min 206.59, max 674.20)"
    "bw_mem-fwr-8mb (MB/s)","441.06 (min 208.38, max 673.74)"
    "bw_mem-rd-16mb (MB/s)","426.84"
    "bw_mem-rd-1mb (MB/s)","344.32 (min 273.30, max 415.34)"
    "bw_mem-rd-2mb (MB/s)","344.55 (min 271.00, max 418.10)"
    "bw_mem-rd-4mb (MB/s)","347.36 (min 271.35, max 423.37)"
    "bw_mem-rd-8mb (MB/s)","350.97 (min 271.37, max 430.57)"
    "bw_mem-rdwr-16mb (MB/s)","296.45"
    "bw_mem-rdwr-1mb (MB/s)","249.23 (min 201.27, max 297.18)"
    "bw_mem-rdwr-2mb (MB/s)","247.56 (min 199.56, max 295.55)"
    "bw_mem-rdwr-4mb (MB/s)","247.65 (min 199.70, max 295.60)"
    "bw_mem-rdwr-8mb (MB/s)","248.81 (min 201.73, max 295.89)"
    "bw_mem-wr-16mb (MB/s)","271.49"
    "bw_mem-wr-1mb (MB/s)","285.24 (min 273.30, max 297.18)"
    "bw_mem-wr-2mb (MB/s)","283.28 (min 271.00, max 295.55)"
    "bw_mem-wr-4mb (MB/s)","283.48 (min 271.35, max 295.60)"
    "bw_mem-wr-8mb (MB/s)","283.63 (min 271.37, max 295.89)"
    "bw_mmap_rd-mo-1mb (MB/s)","189.72"
    "bw_mmap_rd-o2c-1mb (MB/s)","145.82"
    "bw_pipe (MB/s)","360.92"
    "bw_unix (MB/s)","175.48"
    "lat_connect (us)","71.47"
    "lat_ctx-2-128k (us)","2.00"
    "lat_ctx-2-256k (us)","39.10"
    "lat_ctx-4-128k (us)","0.00"
    "lat_ctx-4-256k (us)","0.00"
    "lat_fs-0k (num_files)","248.00"
    "lat_fs-10k (num_files)","77.00"
    "lat_fs-1k (num_files)","119.00"
    "lat_fs-4k (num_files)","122.00"
    "lat_mem_rd-stride128-sz1000k (ns)","97.67"
    "lat_mem_rd-stride128-sz125k (ns)","16.07"
    "lat_mem_rd-stride128-sz250k (ns)","22.69"
    "lat_mem_rd-stride128-sz31k (ns)","9.24"
    "lat_mem_rd-stride128-sz50 (ns)","4.01"
    "lat_mem_rd-stride128-sz500k (ns)","90.16"
    "lat_mem_rd-stride128-sz62k (ns)","16.41"
    "lat_mmap-1m (us)","57.00"
    "lat_ops-double-add (ns)","1.00"
    "lat_ops-double-mul (ns)","7.02"
    "lat_ops-float-add (ns)","0.91"
    "lat_ops-float-mul (ns)","6.01"
    "lat_ops-int-add (ns)","1.03"
    "lat_ops-int-bit (ns)","0.76"
    "lat_ops-int-div (ns)","96.02"
    "lat_ops-int-mod (ns)","23.95"
    "lat_ops-int-mul (ns)","4.04"
    "lat_ops-int64-add (ns)","1.16"
    "lat_ops-int64-bit (ns)","1.01"
    "lat_ops-int64-div (ns)","186.62"
    "lat_ops-int64-mod (ns)","46.88"
    "lat_pagefault (us)","1.59"
    "lat_pipe (us)","25.77"
    "lat_proc-exec (us)","1682.50"
    "lat_proc-fork (us)","1328.50"
    "lat_proc-proccall (us)","0.01"
    "lat_select (us)","31.77"
    "lat_sem (us)","5.06"
    "lat_sig-catch (us)","4.54"
    "lat_sig-install (us)","0.91"
    "lat_sig-prot (us)","0.05"
    "lat_syscall-fstat (us)","1.47"
    "lat_syscall-null (us)","0.39"
    "lat_syscall-open (us)","301.68"
    "lat_syscall-read (us)","0.68"
    "lat_syscall-stat (us)","4.29"
    "lat_syscall-write (us)","0.54"
    "lat_tcp (us)","0.80"
    "lat_unix (us)","34.57"
    "latency_for_0.50_mb_block_size (nanosec)","90.16"
    "latency_for_1.00_mb_block_size (nanosec)","48.84 (min 0.00, max 97.67)"
    "pipe_bandwidth (MBs)","360.92"
    "pipe_latency (microsec)","25.77"
    "procedure_call (microsec)","0.01"
    "select_on_200_tcp_fds (microsec)","31.77"
    "semaphore_latency (microsec)","5.06"
    "signal_handler_latency (microsec)","0.91"
    "signal_handler_overhead (microsec)","4.54"
    "tcp_ip_connection_cost_to_localhost (microsec)","71.47"
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
    "dhrystone_per_second (DhrystoneP)","4347826.00"


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

    "linpack (Kflops)","179939.00"


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

    "assignment (Iterations)","7.70"
    "fourier (Iterations)","13312.00"
    "fp_emulation (Iterations)","84.95"
    "huffman (Iterations)","854.95"
    "idea (Iterations)","1372.90"
    "lu_decomposition (Iterations)","342.21"
    "neural_net (Iterations)","9.19"
    "numeric_sort (Iterations)","425.56"
    "string_sort (Iterations)","52.72"


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
    :header: "Benchmarks","am43xx-gpevm: perf"

    "add (MB/s)","386.60"
    "copy (MB/s)","399.50"
    "scale (MB/s)","654.80"
    "triad (MB/s)","590.80"


Table:  **Stream**

Boot-time Measurement
-------------------------

Boot media: MMCSD
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Boot Configuration","am43xx-gpevm: boot time (sec)"

    "Kernel boot time test when bootloader, kernel and sdk-rootfs are in mmc-sd","51.70 (min 51.44, max 51.89)"
    "Kernel boot time test when init is /bin/sh and bootloader, kernel and sdk-rootfs are in mmc-sd","9.88 (min 9.83, max 9.93)"

Table:  **Boot time MMC/SD**

ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64


.. csv-table::
    :header: "Sampling Rate (Hz)","am43xx-gpevm: Throughput (bits/sec)","am43xx-gpevm: CPU Load (%)"

    "8000","255998.00","0.73"
    "11025","352797.00","0.77"
    "16000","511996.00","1.68"
    "22050","705594.00","1.75"
    "24000","705594.00","1.60"
    "32000","1023991.00","0.31"
    "44100","1411187.00","3.12"
    "48000","1535986.00","0.34"
    "88200","2822370.00","6.07"
    "96000","3071966.00","0.50"

Table:  **Audio Capture**

|

.. csv-table::
    :header: "Sampling Rate (Hz)","am43xx-gpevm: Throughput (bits/sec)","am43xx-gpevm: CPU Load (%)"

    "8000","256102.00","0.16"
    "11025","352941.00","0.76"
    "16000","512205.00","0.20"
    "22050","705882.00","1.60"
    "24000","705882.00","1.52"
    "32000","1024409.00","0.37"
    "44100","1411763.00","2.96"
    "48000","1536613.00","12.22"
    "88200","2823522.00","5.77"
    "96000","3073221.00","0.15"

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

    "GLB25_EgyptTestC24Z16FixedTime test","2500005.00","4.50 (min 2.20, max 11.90)"
    "GLB25_EgyptTestC24Z16_ETC1 test","2501001.00","5.34 (min 2.20, max 11.90)"
    "GLB25_EgyptTestC24Z16_ETC1to565 test","2501401.00","5.32 (min 2.20, max 11.90)"
    "GLB25_EgyptTestC24Z16_PVRTC4 test","2501101.00","5.22 (min 2.13, max 11.90)"
    "GLB25_EgyptTestC24Z24MS4 test","2500003.00","4.33 (min 1.19, max 9.92)"
    "GLB25_EgyptTestStandard_inherited test","2000000.00","15.99 (min 10.56, max 22.08)"


.. csv-table::
    :header: "Benchmark","am43xx-gpevm: Test Number","am43xx-gpevm: Fps"

    "GLB25_EgyptTestC24Z16_ETC1_Offscreen test","2501011.00","3.00"
    "GLB25_EgyptTestStandardOffscreen_inherited test","2000010.00","6.00"


Table:  **GLBenchmark 2.5 Performance**
 


Vertex Throughput
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Benchmark","am43xx-gpevm: Test Number","am43xx-gpevm: Rate (triangles/sec)"

    "GLB25_TriangleTexFragmentLitTestC24Z16 test","2500511.00","2292102.25"
    "GLB25_TriangleTexTestC24Z16 test","2500301.00","11141643.00"
    "GLB25_TriangleTexVertexLitTestC24Z16 test","2500411.00","4255123.00"


Table:  **GLBenchmark 2.5 Vertex Throughput**



Pixel Throughput
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Benchmark","am43xx-gpevm: Test Number","am43xx-gpevm: Rate (texel/sec)","am43xx-gpevm: Fps"

    "GLB25_FillTestC24Z16 test","2500101.00","97853872.00","3.98 (min 3.97, max 4.02)"


Table:  **GLBenchmark 2.5 Pixel Throughput**

Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am43xx-gpevm: Score"

    "Glmark2-DRM","40.00"
    "Glmark2-Wayland","44.00"


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

CPSW Ethernet Driver
^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput
   :name: tcp-bidirectional-throughput

.. csv-table::
    :header: "TCP Window Size","am43xx-gpevm: Throughput (Mbits/sec)","am43xx-gpevm: CPU Load %"

    "Default","333.32","100.00"

Table: **CPSW TCP Bidirectional Throughput**

|

NAND Driver
-------------------------

AM43XX-GPEVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am43xx-gpevm: Write UBIFS Throughput (Mbytes/sec)","am43xx-gpevm: Write UBIFS CPU Load (%)","am43xx-gpevm: Read UBIFS Throughput (Mbytes/sec)","am43xx-gpevm: Read UBIFS CPU Load (%)"

    "102400","6.37 (min 6.18, max 6.81)","68.59 (min 66.02, max 69.57)","10.22","38.99"
    "262144","6.24 (min 6.16, max 6.31)","69.82 (min 69.03, max 70.29)","10.26","38.14"
    "524288","6.26 (min 6.22, max 6.31)","69.53 (min 69.19, max 70.04)","10.24","39.11"
    "1048576","6.26 (min 6.22, max 6.30)","69.47 (min 69.18, max 69.98)","10.21","39.66"
    "5242880","6.24 (min 6.21, max 6.30)","69.63 (min 68.99, max 70.35)","10.26","39.78"


MMC/SD Driver
-------------------------

.. warning::

  **IMPORTANT**: The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

| 

AM43XX-GPEVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^
|

.. csv-table::
    :header: "Buffer size (bytes)","am43xx-gpevm: Write EXT4 Throughput (Mbytes/sec)","am43xx-gpevm: Write EXT4 CPU Load (%)","am43xx-gpevm: Read EXT4 Throughput (Mbytes/sec)","am43xx-gpevm: Read EXT4 CPU Load (%)"

    "1m","9.54","3.22","36.30","9.91"
    "4m","9.66","3.08","36.50","9.52"
    "4k","3.00","16.74","8.52","37.21"
    "256k","9.44","3.95","35.90","10.69"

|

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

|

UBoot MMC/SD Driver
-------------------------
| 

AM43XX-GPEVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "File size (bytes in hex)","am43xx-gpevm: Write Throughput (Kbytes/sec)","am43xx-gpevm: Read Throughput (Kbytes/sec)"

    "400000","13128.21","19051.16"
    "800000","14271.78","19320.75"
    "1000000","11932.99","19504.76"

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card

|

USB Driver
-------------------------

USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Number of Blocks","am43xx-gpevm: Throughput (MB/sec)"

    "150","27.90"

Table: **USBDEVICE HIGHSPEED SLAVE READ THROUGHPUT**

|

.. csv-table::
    :header: "Number of Blocks","am43xx-gpevm: Throughput (MB/sec)"

    "150","28.90"

Table: **USBDEVICE HIGHSPEED SLAVE WRITE THROUGHPUT**

|

CRYPTO Driver
-------------------------

IPSec Hardware Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Note: queue\_len is set to 300 and software fallback threshold set to 9
to enable software support for optimal performance

.. csv-table::
    :header: "Algorithm","am43xx-gpevm: Throughput (Mbps)","am43xx-gpevm: Packets/Sec","am43xx-gpevm: CPU Load"

    "aes128","0.00","0.00","99.39"

IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am43xx-gpevm: Throughput (Mbps)","am43xx-gpevm: Packets/Sec","am43xx-gpevm: CPU Load"

    "aes128","1.40","0.00","100.00"
    "aes192","1.40","0.00","100.00"
    "aes256","1.40","0.00","100.01"


DCAN Driver
-------------------------

Performance and Benchmarks not available in this release.
