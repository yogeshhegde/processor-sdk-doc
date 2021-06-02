
======================================
 Linux 07.03.00 Performance Guide
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
    :header: "Benchmarks","am335x-evm: perf"

    "af_unix_sock_stream_latency (microsec)","40.80"
    "af_unix_socket_stream_bandwidth (MBs)","167.96"
    "bw_file_rd-io-1mb (MB/s)","176.34"
    "bw_file_rd-o2c-1mb (MB/s)","152.21"
    "bw_mem-bcopy-16mb (MB/s)","207.64"
    "bw_mem-bcopy-1mb (MB/s)","202.41"
    "bw_mem-bcopy-2mb (MB/s)","197.63"
    "bw_mem-bcopy-4mb (MB/s)","200.15"
    "bw_mem-bcopy-8mb (MB/s)","201.51"
    "bw_mem-bzero-16mb (MB/s)","994.96"
    "bw_mem-bzero-1mb (MB/s)","592.69 (min 202.41, max 982.96)"
    "bw_mem-bzero-2mb (MB/s)","590.86 (min 197.63, max 984.09)"
    "bw_mem-bzero-4mb (MB/s)","595.13 (min 200.15, max 990.10)"
    "bw_mem-bzero-8mb (MB/s)","592.70 (min 201.51, max 983.89)"
    "bw_mem-cp-16mb (MB/s)","192.30"
    "bw_mem-cp-1mb (MB/s)","586.01 (min 190.66, max 981.35)"
    "bw_mem-cp-2mb (MB/s)","590.47 (min 189.36, max 991.57)"
    "bw_mem-cp-4mb (MB/s)","595.45 (min 183.71, max 1007.18)"
    "bw_mem-cp-8mb (MB/s)","587.30 (min 191.31, max 983.28)"
    "bw_mem-fcp-16mb (MB/s)","296.71"
    "bw_mem-fcp-1mb (MB/s)","640.16 (min 297.35, max 982.96)"
    "bw_mem-fcp-2mb (MB/s)","638.37 (min 292.65, max 984.09)"
    "bw_mem-fcp-4mb (MB/s)","641.58 (min 293.06, max 990.10)"
    "bw_mem-fcp-8mb (MB/s)","638.09 (min 292.28, max 983.89)"
    "bw_mem-frd-16mb (MB/s)","247.95"
    "bw_mem-frd-1mb (MB/s)","282.65 (min 267.95, max 297.35)"
    "bw_mem-frd-2mb (MB/s)","273.39 (min 254.13, max 292.65)"
    "bw_mem-frd-4mb (MB/s)","270.28 (min 247.49, max 293.06)"
    "bw_mem-frd-8mb (MB/s)","269.94 (min 247.60, max 292.28)"
    "bw_mem-fwr-16mb (MB/s)","993.97"
    "bw_mem-fwr-1mb (MB/s)","624.65 (min 267.95, max 981.35)"
    "bw_mem-fwr-2mb (MB/s)","622.85 (min 254.13, max 991.57)"
    "bw_mem-fwr-4mb (MB/s)","627.34 (min 247.49, max 1007.18)"
    "bw_mem-fwr-8mb (MB/s)","615.44 (min 247.60, max 983.28)"
    "bw_mem-rd-16mb (MB/s)","250.65"
    "bw_mem-rd-1mb (MB/s)","626.27 (min 270.05, max 982.48)"
    "bw_mem-rd-2mb (MB/s)","618.13 (min 252.65, max 983.61)"
    "bw_mem-rd-4mb (MB/s)","617.29 (min 250.44, max 984.13)"
    "bw_mem-rd-8mb (MB/s)","626.23 (min 250.19, max 1002.26)"
    "bw_mem-rdwr-16mb (MB/s)","202.26"
    "bw_mem-rdwr-1mb (MB/s)","198.80 (min 190.66, max 206.93)"
    "bw_mem-rdwr-2mb (MB/s)","195.93 (min 189.36, max 202.49)"
    "bw_mem-rdwr-4mb (MB/s)","193.65 (min 183.71, max 203.59)"
    "bw_mem-rdwr-8mb (MB/s)","196.71 (min 191.31, max 202.10)"
    "bw_mem-wr-16mb (MB/s)","995.89"
    "bw_mem-wr-1mb (MB/s)","594.71 (min 206.93, max 982.48)"
    "bw_mem-wr-2mb (MB/s)","593.05 (min 202.49, max 983.61)"
    "bw_mem-wr-4mb (MB/s)","593.86 (min 203.59, max 984.13)"
    "bw_mem-wr-8mb (MB/s)","602.18 (min 202.10, max 1002.26)"
    "bw_mmap_rd-mo-1mb (MB/s)","258.70"
    "bw_mmap_rd-o2c-1mb (MB/s)","165.15"
    "bw_pipe (MB/s)","320.03"
    "bw_unix (MB/s)","167.96"
    "lat_connect (us)","80.19"
    "lat_ctx-2-128k (us)","31.29"
    "lat_ctx-2-256k (us)","4.00"
    "lat_ctx-4-128k (us)","4.39"
    "lat_ctx-4-256k (us)","0.00"
    "lat_fs-0k (num_files)","207.00"
    "lat_fs-10k (num_files)","80.00"
    "lat_fs-1k (num_files)","114.00"
    "lat_fs-4k (num_files)","118.00"
    "lat_mem_rd-stride128-sz1000k (ns)","214.76"
    "lat_mem_rd-stride128-sz125k (ns)","11.75"
    "lat_mem_rd-stride128-sz250k (ns)","65.41"
    "lat_mem_rd-stride128-sz31k (ns)","3.02"
    "lat_mem_rd-stride128-sz50 (ns)","3.01"
    "lat_mem_rd-stride128-sz500k (ns)","179.46"
    "lat_mem_rd-stride128-sz62k (ns)","8.74"
    "lat_mmap-1m (us)","68.00"
    "lat_ops-double-add (ns)","2.37"
    "lat_ops-double-mul (ns)","11.06"
    "lat_ops-float-add (ns)","2.28"
    "lat_ops-float-mul (ns)","10.05"
    "lat_ops-int-add (ns)","1.01"
    "lat_ops-int-bit (ns)","0.67"
    "lat_ops-int-div (ns)","72.90"
    "lat_ops-int-mod (ns)","24.49"
    "lat_ops-int-mul (ns)","6.07"
    "lat_ops-int64-add (ns)","1.21"
    "lat_ops-int64-bit (ns)","1.06"
    "lat_ops-int64-div (ns)","191.43"
    "lat_ops-int64-mod (ns)","52.27"
    "lat_pagefault (us)","1.98"
    "lat_pipe (us)","36.41"
    "lat_proc-exec (us)","1580.50"
    "lat_proc-fork (us)","1356.00"
    "lat_proc-proccall (us)","0.02"
    "lat_select (us)","41.73"
    "lat_sem (us)","5.87"
    "lat_sig-catch (us)","5.78"
    "lat_sig-install (us)","1.48"
    "lat_sig-prot (us)","0.40"
    "lat_syscall-fstat (us)","2.01"
    "lat_syscall-null (us)","0.53"
    "lat_syscall-open (us)","419.63"
    "lat_syscall-read (us)","1.17"
    "lat_syscall-stat (us)","5.48"
    "lat_syscall-write (us)","0.74"
    "lat_tcp (us)","1.10"
    "lat_unix (us)","40.80"
    "latency_for_0.50_mb_block_size (nanosec)","179.46"
    "latency_for_1.00_mb_block_size (nanosec)","107.38 (min 0.00, max 214.76)"
    "pipe_bandwidth (MBs)","320.03"
    "pipe_latency (microsec)","36.41"
    "procedure_call (microsec)","0.02"
    "select_on_200_tcp_fds (microsec)","41.73"
    "semaphore_latency (microsec)","5.87"
    "signal_handler_latency (microsec)","1.48"
    "signal_handler_overhead (microsec)","5.78"
    "tcp_ip_connection_cost_to_localhost (microsec)","80.19"
    "tcp_latency_using_localhost (microsec)","1.10"


Table:  **LM Bench Metrics**

Dhrystone
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Dhrystone is a core only benchmark that runs from warm L1 caches in all
modern processors. It scales linearly with clock speed. For standard ARM
cores the DMIPS/MHz score will be identical with the same compiler and flags.
  
.. csv-table::
    :header: "Benchmarks","am335x-evm: perf"

    "cpu_clock (MHz)","1000.00"
    "dhrystone_per_mhz (DMIPS/MHz)","2.00"
    "dhrystone_per_second (DhrystoneP)","3508772.00"


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
sloving a dense linear system.

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf"

    "linpack (Kflops)","51660.00"


Table:  **Linpack Benchmark**

NBench
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf"

    "assignment (Iterations)","7.47"
    "fourier (Iterations)","2846.60"
    "fp_emulation (Iterations)","78.71"
    "huffman (Iterations)","708.36"
    "idea (Iterations)","1278.10"
    "lu_decomposition (Iterations)","74.24"
    "neural_net (Iterations)","2.13"
    "numeric_sort (Iterations)","456.74"
    "string_sort (Iterations)","60.51"


Table:  **NBench Benchmarks**

Stream
^^^^^^^^^^^^^^^^^^^^^^^^^^^
STREAM is a microbenchmarks for measuring data memory system performance without
any data reuse. It is designed to miss on caches and exercise data prefetcher and
apeculative accesseses. it uses double precision floating point (64bit) but in
most modern processors the memory access will be the bottleck. The four individual
scores are copy, scale as in multiply by constant, add two numbers, and triad for
multiply accumulate. For bandwidth a byte read counts as one and a byte written
counts as one resulting in a score that is double the bandwidth LMBench will show.

.. csv-table::
    :header: "Benchmarks","am335x-evm: perf"

    "add (MB/s)","376.60"
    "copy (MB/s)","440.10"
    "scale (MB/s)","624.90"
    "triad (MB/s)","443.70"


Table:  **Stream**


ALSA SoC Audio Driver
-------------------------

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64


Table:  **Audio Capture**

|

.. csv-table::
    :header: "Sampling Rate (Hz)","am335x-evm: Throughput (bits/sec)","am335x-evm: CPU Load (%)"

    "8000","256102.00","11.82"
    "11025","352941.00","9.62"
    "16000","512204.00","5.07"
    "22050","705882.00","12.56"
    "24000","705881.00","12.43"
    "32000","1024407.00","35.25"
    "44100","1411753.00","18.66"
    "48000","1536607.00","34.27"
    "88200","2823503.00","29.88"
    "96000","3073198.00","26.64"

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

    "GLB25_EgyptTestC24Z16FixedTime test","2500005.00","4.29 (min 2.09, max 10.81)"
    "GLB25_EgyptTestC24Z16_ETC1 test","2501001.00","5.02 (min 2.13, max 11.09)"
    "GLB25_EgyptTestC24Z16_ETC1to565 test","2501401.00","4.99 (min 2.13, max 11.08)"
    "GLB25_EgyptTestC24Z16_PVRTC4 test","2501101.00","4.85 (min 2.11, max 10.16)"
    "GLB25_EgyptTestC24Z24MS4 test","2500003.00","4.04 (min 1.15, max 8.84)"
    "GLB25_EgyptTestStandard_inherited test","2000000.00","13.83 (min 5.99, max 19.65)"




Table:  **GLBenchmark 2.5 Performance**

Vertex Throughput
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Rate (triangles/sec)"

    "GLB25_TriangleTexFragmentLitTestC24Z16 test","2500511.00","2131015.25"
    "GLB25_TriangleTexTestC24Z16 test","2500301.00","10194548.00"
    "GLB25_TriangleTexVertexLitTestC24Z16 test","2500411.00","2865361.50"


Table:  **GLBenchmark 2.5 Vertex Throughput**

Pixel Throughput
"""""""""""""""""""""""""""

.. csv-table::
    :header: "Benchmark","am335x-evm: Test Number","am335x-evm: Rate (texel/sec)","am335x-evm: Fps"

    "GLB25_FillTestC24Z16 test","2500101.00","94916224.00","3.86 (min 3.81, max 3.87)"


Table:  **GLBenchmark 2.5 Pixel Throughput**

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

    "Default","389.39","100.00"

Table: **CPSW TCP Bidirectional Throughput**

|

NAND Driver
-------------------------



AM335X-EVM
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. csv-table::
    :header: "Buffer size (bytes)","am335x-evm: Write UBIFS Throughput (Mbytes/sec)","am335x-evm: Write UBIFS CPU Load (%)","am335x-evm: Read UBIFS Throughput (Mbytes/sec)","am335x-evm: Read UBIFS CPU Load (%)"

    "102400","3.93","62.69","5.31","34.90"
    "262144","3.95","61.69","5.47","32.55"
    "524288","3.95","62.09","5.47","33.52"
    "1048576","3.94","61.43","5.50","32.66"
    "5242880","3.95","62.02","5.45","34.59"

|

CRYPTO Driver
-------------------------

OpenSSL Performance
^^^^^^^^^^^^^^^^^^^^^^^^^^^


.. csv-table::
    :header: "Algorithm","Buffer Size (in bytes)","am335x-evm: throughput (KBytes/Sec)"

    "aes-128-cbc","1024","12317.35"
    "aes-128-cbc","16","2246.18"
    "aes-128-cbc","16384","17661.95"
    "aes-128-cbc","256","4242.09"
    "aes-128-cbc","64","7571.61"
    "aes-128-cbc","8192","19693.57"
    "aes-192-cbc","1024","12099.24"
    "aes-192-cbc","16","2248.15"
    "aes-192-cbc","16384","17651.03"
    "aes-192-cbc","256","4319.83"
    "aes-192-cbc","64","7338.99"
    "aes-192-cbc","8192","19649.88"
    "aes-256-cbc","1024","11865.43"
    "aes-256-cbc","16","2243.64"
    "aes-256-cbc","16384","17017.51"
    "aes-256-cbc","256","4181.93"
    "aes-256-cbc","64","7101.59"
    "aes-256-cbc","8192","19417.77"
    "des-cbc","1024","13986.47"
    "des-cbc","16","2226.02"
    "des-cbc","16384","16635.22"
    "des-cbc","256","11553.71"
    "des-cbc","64","6371.31"
    "des-cbc","8192","8323.07"
    "des3","1024","6449.83"
    "des3","16","1954.89"
    "des3","16384","6651.90"
    "des3","256","5799.25"
    "des3","64","4034.71"
    "des3","8192","6417.07"
    "md5","1024","9953.28"
    "md5","16","504.11"
    "md5","16384","45689.51"
    "md5","256","3623.25"
    "md5","64","1946.03"
    "md5","8192","37746.01"
    "sha1","1024","9679.19"
    "sha1","16","451.93"
    "sha1","16384","44176.73"
    "sha1","256","3546.03"
    "sha1","64","1697.19"
    "sha1","8192","37852.50"
    "sha224","1024","9557.33"
    "sha224","16","437.55"
    "sha224","16384","44881.24"
    "sha224","256","3380.74"
    "sha224","64","1711.68"
    "sha224","8192","37691.39"
    "sha256","1024","9341.27"
    "sha256","16","436.18"
    "sha256","16384","46049.96"
    "sha256","256","3493.80"
    "sha256","64","1709.10"
    "sha256","8192","37612.20"
    "sha384","1024","17053.01"
    "sha384","16","448.68"
    "sha384","16384","39195.99"
    "sha384","256","6182.57"
    "sha384","64","1844.99"
    "sha384","8192","34892.46"
    "sha512","1024","17272.49"
    "sha512","16","456.90"
    "sha512","16384","39168.68"
    "sha512","256","6137.69"
    "sha512","64","1773.57"
    "sha512","8192","34971.65"


|
|

.. csv-table::
    :header: "Algorithm","am335x-evm: CPU Load"

    "aes-128-cbc","42.00"
    "aes-192-cbc","43.00"
    "aes-256-cbc","43.00"
    "des-cbc","87.00"
    "des3","97.00"
    "md5","69.00"
    "sha1","69.00"
    "sha224","69.00"
    "sha256","69.00"
    "sha384","97.00"
    "sha512","97.00"



-

|
| Listed for each algorithm are the code snippets used to run each
  benchmark test.

|

::

    time -v openssl speed -elapsed -evp aes-128-cbc

-

