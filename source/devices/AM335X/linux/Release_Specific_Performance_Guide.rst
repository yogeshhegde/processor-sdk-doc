
======================================
 Linux 08.02.00 Performance Guide
======================================

.. rubric::  **Read This First**
   :name: read-this-first-kernel-perf-guide

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| AM335x         | AM335x Evaluation Module rev 1.5B with ARM running at 1000MHz, DDR3-400 (400MHz/800 MT/S), TMDXEVM3358         |
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
    :header: "Benchmarks","am335x-evm: perf"

    "af_unix_sock_stream_latency (microsec)","44.00"
    "af_unix_socket_stream_bandwidth (MBs)","156.59"
    "bw_file_rd-io-1mb (MB/s)","180.57"
    "bw_file_rd-o2c-1mb (MB/s)","144.15"
    "bw_mem-bcopy-16mb (MB/s)","218.37"
    "bw_mem-bcopy-1mb (MB/s)","204.08"
    "bw_mem-bcopy-2mb (MB/s)","207.62"
    "bw_mem-bcopy-4mb (MB/s)","208.47"
    "bw_mem-bcopy-8mb (MB/s)","168.47"
    "bw_mem-bzero-16mb (MB/s)","994.84"
    "bw_mem-bzero-1mb (MB/s)","595.46 (min 204.08, max 986.84)"
    "bw_mem-bzero-2mb (MB/s)","596.67 (min 207.62, max 985.71)"
    "bw_mem-bzero-4mb (MB/s)","596.18 (min 208.47, max 983.89)"
    "bw_mem-bzero-8mb (MB/s)","576.18 (min 168.47, max 983.89)"
    "bw_mem-cp-16mb (MB/s)","201.34"
    "bw_mem-cp-1mb (MB/s)","597.64 (min 201.73, max 993.54)"
    "bw_mem-cp-2mb (MB/s)","590.74 (min 194.95, max 986.52)"
    "bw_mem-cp-4mb (MB/s)","600.64 (min 198.51, max 1002.76)"
    "bw_mem-cp-8mb (MB/s)","574.90 (min 165.55, max 984.25)"
    "bw_mem-fcp-16mb (MB/s)","294.68"
    "bw_mem-fcp-1mb (MB/s)","642.88 (min 298.91, max 986.84)"
    "bw_mem-fcp-2mb (MB/s)","641.56 (min 297.40, max 985.71)"
    "bw_mem-fcp-4mb (MB/s)","641.86 (min 299.83, max 983.89)"
    "bw_mem-fcp-8mb (MB/s)","632.73 (min 281.56, max 983.89)"
    "bw_mem-frd-16mb (MB/s)","247.68"
    "bw_mem-frd-1mb (MB/s)","283.74 (min 268.56, max 298.91)"
    "bw_mem-frd-2mb (MB/s)","268.52 (min 239.64, max 297.40)"
    "bw_mem-frd-4mb (MB/s)","273.99 (min 248.15, max 299.83)"
    "bw_mem-frd-8mb (MB/s)","264.37 (min 247.18, max 281.56)"
    "bw_mem-fwr-16mb (MB/s)","996.45"
    "bw_mem-fwr-1mb (MB/s)","631.05 (min 268.56, max 993.54)"
    "bw_mem-fwr-2mb (MB/s)","613.08 (min 239.64, max 986.52)"
    "bw_mem-fwr-4mb (MB/s)","625.46 (min 248.15, max 1002.76)"
    "bw_mem-fwr-8mb (MB/s)","615.72 (min 247.18, max 984.25)"
    "bw_mem-rd-16mb (MB/s)","250.85"
    "bw_mem-rd-1mb (MB/s)","629.84 (min 273.49, max 986.19)"
    "bw_mem-rd-2mb (MB/s)","622.36 (min 259.50, max 985.22)"
    "bw_mem-rd-4mb (MB/s)","617.64 (min 250.78, max 984.49)"
    "bw_mem-rd-8mb (MB/s)","617.30 (min 249.98, max 984.62)"
    "bw_mem-rdwr-16mb (MB/s)","202.64"
    "bw_mem-rdwr-1mb (MB/s)","204.48 (min 201.73, max 207.23)"
    "bw_mem-rdwr-2mb (MB/s)","199.40 (min 194.95, max 203.85)"
    "bw_mem-rdwr-4mb (MB/s)","200.68 (min 198.51, max 202.84)"
    "bw_mem-rdwr-8mb (MB/s)","183.84 (min 165.55, max 202.12)"
    "bw_mem-wr-16mb (MB/s)","992.74"
    "bw_mem-wr-1mb (MB/s)","596.71 (min 207.23, max 986.19)"
    "bw_mem-wr-2mb (MB/s)","594.54 (min 203.85, max 985.22)"
    "bw_mem-wr-4mb (MB/s)","593.67 (min 202.84, max 984.49)"
    "bw_mem-wr-8mb (MB/s)","593.37 (min 202.12, max 984.62)"
    "bw_mmap_rd-mo-1mb (MB/s)","258.13"
    "bw_mmap_rd-o2c-1mb (MB/s)","171.09"
    "bw_pipe (MB/s)","322.20"
    "bw_unix (MB/s)","156.59"
    "lat_connect (us)","86.06"
    "lat_ctx-2-128k (us)","33.07"
    "lat_ctx-2-256k (us)","4.00"
    "lat_ctx-4-128k (us)","37.03"
    "lat_ctx-4-256k (us)","0.00"
    "lat_fs-0k (num_files)","217.00"
    "lat_fs-10k (num_files)","65.00"
    "lat_fs-1k (num_files)","96.00"
    "lat_fs-4k (num_files)","115.00"
    "lat_mem_rd-stride128-sz1000k (ns)","221.15"
    "lat_mem_rd-stride128-sz125k (ns)","11.70"
    "lat_mem_rd-stride128-sz250k (ns)","88.62"
    "lat_mem_rd-stride128-sz31k (ns)","3.03"
    "lat_mem_rd-stride128-sz50 (ns)","3.01"
    "lat_mem_rd-stride128-sz500k (ns)","188.12"
    "lat_mem_rd-stride128-sz62k (ns)","8.78"
    "lat_mmap-1m (us)","74.00"
    "lat_ops-double-add (ns)","2.37"
    "lat_ops-double-mul (ns)","11.06"
    "lat_ops-float-add (ns)","2.28"
    "lat_ops-float-mul (ns)","10.06"
    "lat_ops-int-add (ns)","1.01"
    "lat_ops-int-bit (ns)","0.67"
    "lat_ops-int-div (ns)","72.92"
    "lat_ops-int-mod (ns)","24.38"
    "lat_ops-int-mul (ns)","6.06"
    "lat_ops-int64-add (ns)","1.21"
    "lat_ops-int64-bit (ns)","1.06"
    "lat_ops-int64-div (ns)","192.20"
    "lat_ops-int64-mod (ns)","52.33"
    "lat_pagefault (us)","1.90"
    "lat_pipe (us)","36.90"
    "lat_proc-exec (us)","1869.00"
    "lat_proc-fork (us)","1490.50"
    "lat_proc-proccall (us)","0.02"
    "lat_select (us)","39.50"
    "lat_sem (us)","4.75"
    "lat_sig-catch (us)","6.00"
    "lat_sig-install (us)","1.39"
    "lat_sig-prot (us)","0.15"
    "lat_syscall-fstat (us)","1.93"
    "lat_syscall-null (us)","0.53"
    "lat_syscall-open (us)","303.00"
    "lat_syscall-read (us)","0.90"
    "lat_syscall-stat (us)","5.52"
    "lat_syscall-write (us)","0.70"
    "lat_tcp (us)","1.13"
    "lat_unix (us)","44.00"
    "latency_for_0.50_mb_block_size (nanosec)","188.12"
    "latency_for_1.00_mb_block_size (nanosec)","110.58 (min 0.00, max 221.15)"
    "pipe_bandwidth (MBs)","322.20"
    "pipe_latency (microsec)","36.90"
    "procedure_call (microsec)","0.02"
    "select_on_200_tcp_fds (microsec)","39.50"
    "semaphore_latency (microsec)","4.75"
    "signal_handler_latency (microsec)","1.39"
    "signal_handler_overhead (microsec)","6.00"
    "tcp_ip_connection_cost_to_localhost (microsec)","86.06"
    "tcp_latency_using_localhost (microsec)","1.13"


Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf"

    "cpu_clock (MHz)","1000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.10"
    "dhrystone_per_second (DhrystoneP)","3636363.80"


Table:  **Dhrystone Benchmark**


Whetstone
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf"

    "whetstone (MIPS)","833.30"


Table:  **Whetstone Benchmark**

Linpack
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Linpack measures peak double precision (64 bit) floating point performance in
solving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf"

    "linpack (Kflops)","51162.00"


Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^
NBench which stands for Native Benchmark is used to measure macro benchmarks
for commonly used operations such as sorting and analysis algorithms.
More information about NBench at
https://en.wikipedia.org/wiki/NBench and
https://nbench.io/articles/index.html


.. csv-table::
    :header: "Benchmarks","am335x-evm: perf"

    "assignment (Iterations)","7.52"
    "fourier (Iterations)","2851.00"
    "fp_emulation (Iterations)","78.77"
    "huffman (Iterations)","709.42"
    "idea (Iterations)","1280.00"
    "lu_decomposition (Iterations)","74.58"
    "neural_net (Iterations)","2.13"
    "numeric_sort (Iterations)","458.12"
    "string_sort (Iterations)","60.60"


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
    :header: "Benchmarks","am335x-evm: perf"

    "add (MB/s)","382.90"
    "copy (MB/s)","435.70"
    "scale (MB/s)","611.20"
    "triad (MB/s)","447.70"


Table:  **Stream**


ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64


.. csv-table::
    :header: "Sampling Rate (Hz)","am335x-evm: Throughput (bits/sec)","am335x-evm: CPU Load (%)"

    "8000","255999.00","7.02"
    "11025","352799.00","9.49"
    "16000","511997.00","18.97"
    "22050","705596.00","11.97"
    "24000","705596.00","12.02"
    "32000","1023993.00","11.78"
    "44100","1411188.00","15.28"
    "48000","1535987.00","14.98"
    "88200","2822344.00","29.67"
    "96000","3071955.00","9.38"

Table:  **Audio Capture**


|


.. csv-table::
    :header: "Sampling Rate (Hz)","am335x-evm: Throughput (bits/sec)","am335x-evm: CPU Load (%)"

    "8000","256103.00","9.16"
    "11025","352941.00","3.98"
    "16000","512205.00","23.81"
    "22050","705882.00","7.71"
    "24000","705882.00","7.75"
    "32000","1024408.00","1.22"
    "44100","1411760.00","14.14"
    "48000","1536608.00","19.33"
    "88200","2823504.00","27.90"
    "96000","3073224.00","54.47"

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
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Fps"

    "GLB25_EgyptTestC24Z16FixedTime test","2500005.00","4.27 (min 2.11, max 10.48)"
    "GLB25_EgyptTestC24Z16_ETC1 test","2501001.00","5.03 (min 2.13, max 11.25)"
    "GLB25_EgyptTestC24Z16_ETC1to565 test","2501401.00","5.06 (min 2.13, max 11.43)"
    "GLB25_EgyptTestC24Z16_PVRTC4 test","2501101.00","4.84 (min 2.06, max 10.32)"
    "GLB25_EgyptTestStandard_inherited test","2000000.00","14.21 (min 9.82, max 20.31)"


.. csv-table::
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Fps"

    "GLB25_EgyptTestC24Z16_ETC1_Offscreen test","2501011.00","2.00"
    "GLB25_EgyptTestStandardOffscreen_inherited test","2000010.00","6.00"


Table:  **GLBenchmark 2.5 Performance**

Vertex Throughput
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Rate (triangles/sec)"

    "GLB25_TriangleTexFragmentLitTestC24Z16 test","2500511.00","2129335.00"
    "GLB25_TriangleTexTestC24Z16 test","2500301.00","10194565.00"


Table:  **GLBenchmark 2.5 Vertex Throughput**

Pixel Throughput
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Rate (texel/sec)","am335x-evm: Fps"

    "GLB25_FillTestC24Z16 test","2500101.00","94916224.00","3.86 (min 3.81, max 3.87)"


Table:  **GLBenchmark 2.5 Pixel Throughput**

|

Glmark2
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Run Glmark2 and capture performance reported (Score). All display outputs (HDMI, Displayport and/or LCD) are connected when running these tests

.. csv-table::
    :header: "Benchmark","am335x-evm: Score"

    "Glmark2-DRM","39.00"
    "Glmark2-Wayland","39.00"


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

|

CPSW Ethernet Driver
^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric::  TCP Bidirectional Throughput
   :name: tcp-bidirectional-throughput

.. csv-table::
    :header: "TCP Window Size","am335x-evm: Throughput (Mbits/sec)","am335x-evm: CPU Load %"

    "Default","391.00","100.00"

Table: **CPSW TCP Bidirectional Throughput**

|


NAND Driver
-------------------------




AM335X-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write UBIFS Throughput (Mbytes/sec)","am335x-evm: Write UBIFS CPU Load (%)","am335x-evm: Read UBIFS Throughput (Mbytes/sec)","am335x-evm: Read UBIFS CPU Load (%)"

    "102400","3.96 (min 3.92, max 4.09)","64.09 (min 63.38, max 64.80)","5.28","36.06"
    "262144","3.58 (min 3.55, max 3.64)","63.73 (min 63.29, max 64.36)","5.50","36.96"
    "524288","3.90 (min 3.89, max 3.92)","64.43 (min 63.83, max 65.21)","5.30","35.69"
    "1048576","3.90 (min 3.89, max 3.92)","63.66 (min 63.06, max 65.01)","5.28","35.65"
    "5242880","3.91 (min 3.89, max 3.92)","64.20 (min 63.97, max 64.38)","5.29","35.70"

|

USB Driver
-------------------------



USB Device Controller
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Number of Blocks","am335x-evm: Throughput (MB/sec)"

    "150","18.40"

Table: **USBDEVICE HIGHSPEED SLAVE READ THROUGHPUT**

|
|


.. csv-table::
    :header: "Number of Blocks","am335x-evm: Throughput (MB/sec)"

    "150","7.30"

Table: **USBDEVICE HIGHSPEED SLAVE WRITE THROUGHPUT**

|


CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am335x-evm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","11951.45"
    "aes-128-cbc","16","2244.12"
    "aes-128-cbc","16384","19027.29"
    "aes-128-cbc","256","4342.36"
    "aes-128-cbc","64","7720.51"
    "aes-128-cbc","8192","16422.23"
    "aes-192-cbc","1024","12137.13"
    "aes-192-cbc","16","2314.85"
    "aes-192-cbc","16384","18568.53"
    "aes-192-cbc","256","4103.08"
    "aes-192-cbc","64","7259.07"
    "aes-192-cbc","8192","17238.70"
    "aes-256-cbc","1024","11621.38"
    "aes-256-cbc","16","2291.91"
    "aes-256-cbc","16384","18508.46"
    "aes-256-cbc","256","4151.98"
    "aes-256-cbc","64","7065.24"
    "aes-256-cbc","8192","16878.25"
    "des-cbc","1024","18736.81"
    "des-cbc","16","14756.21"
    "des-cbc","16384","18191.70"
    "des-cbc","256","17943.89"
    "des-cbc","64","17629.38"
    "des-cbc","8192","18841.60"
    "des3","1024","6455.64"
    "des3","16","6119.14"
    "des3","16384","6673.75"
    "des3","256","6648.58"
    "des3","64","6517.23"
    "des3","8192","6537.22"
    "md5","1024","8201.56"
    "md5","16","470.95"
    "md5","16384","36104.87"
    "md5","256","3028.99"
    "md5","64","1917.93"
    "md5","8192","33431.55"
    "sha1","1024","7756.12"
    "sha1","16","455.04"
    "sha1","16384","35722.58"
    "sha1","256","2911.32"
    "sha1","64","1827.95"
    "sha1","8192","33095.68"
    "sha224","1024","8175.96"
    "sha224","16","440.38"
    "sha224","16384","36459.86"
    "sha224","256","2873.86"
    "sha224","64","1626.35"
    "sha224","8192","32453.97"
    "sha256","1024","8065.71"
    "sha256","16","441.24"
    "sha256","16384","35170.99"
    "sha256","256","2830.76"
    "sha256","64","1674.62"
    "sha256","8192","32396.63"
    "sha384","1024","16733.87"
    "sha384","16","437.67"
    "sha384","16384","37453.82"
    "sha384","256","5769.73"
    "sha384","64","1787.31"
    "sha384","8192","34461.01"
    "sha512","1024","16081.92"
    "sha512","16","431.02"
    "sha512","16384","37218.99"
    "sha512","256","5985.71"
    "sha512","64","1792.66"
    "sha512","8192","33557.16"

|
|

.. csv-table::
    :header: "Algorithm","am335x-evm: CPU Load"

    "aes-128-cbc","42.00"
    "aes-192-cbc","42.00"
    "aes-256-cbc","41.00"
    "des-cbc","94.00"
    "des3","95.00"
    "md5","58.00"
    "sha1","58.00"
    "sha224","58.00"
    "sha256","58.00"
    "sha384","94.00"
    "sha512","93.00"



|
| Listed for each algorithm are the code snippets used to run each
  benchmark test.

|

::

    time -v openssl speed -elapsed -evp aes-128-cbc


IPSec Hardware Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Note: queue\_len is set to 300 and software fallback threshold set to 9
to enable software support for optimal performance

.. csv-table::
    :header: "Algorithm","am335x-evm: Throughput (Mbps)","am335x-evm: Packets/Sec","am335x-evm: CPU Load"

    "aes128","0.00","0.00","99.44"
    "aes192","0.10","0.00","100.46"
    "aes256","0.20","0.00","100.40"




IPSec Software Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Algorithm","am335x-evm: Throughput (Mbps)","am335x-evm: Packets/Sec","am335x-evm: CPU Load"

    "aes128","0.60","0.00","101.49"
    "aes192","1.10","0.00","100.65"
    "aes256","1.40","0.00","98.45"

|
