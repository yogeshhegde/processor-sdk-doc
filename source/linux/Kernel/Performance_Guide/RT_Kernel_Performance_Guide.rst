.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_RT_Kernel_Performance_Guide
.. rubric:: **Read This First**
   :name: read-this-first

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+----------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                    |
+================+================================================================================================================+
| AM335x         | AM335x Evaluation Module rev 1.5B with ARM running at 1000MHz, DDR3-400 (400MHz/800 MT/S), TMDXEVM3358         |
+----------------+----------------------------------------------------------------------------------------------------------------+
| AM437x-gpevm   | AM437x-gpevm Evaluation Module rev 1.5A with ARM running at 1000MHz, DDR3-400 (400MHz/800 MT/S), TMDSEVM437X   |
+----------------+----------------------------------------------------------------------------------------------------------------+
| AM572x IDK     | AM57xx Evaluation Module rev A2 with ARM running at 1500MHz, DDR3L-533 (533 MHz/1066 MT/S), TMDXIDK5278        |
+----------------+----------------------------------------------------------------------------------------------------------------+
| K2HK EVM       | K2 Hawkings Evaluation Module rev 40 with ARM running at 1200MHz, DDR3-1600 (800 MHz/1600 MT/S), EVMK2H        |
+----------------+----------------------------------------------------------------------------------------------------------------+
| K2G EVM        | K2 Galileo Evaluation Module rev C, DDR3-1333 (666 MHz/1333 MT/S), EVMK2G                                      |
+----------------+----------------------------------------------------------------------------------------------------------------+

Table:  Evaluation Modules

| 

.. rubric:: About This Manual
   :name: about-this-manual

This document provides performance data for each of the device drivers
which are part of the Processor SDK RT Linux package. This document
should be used in conjunction with release notes and user guides
provided with the Processor SDK RT Linux package for information on
specific issues present with drivers included in a particular release.

.. rubric:: If You Need Assistance
   :name: if-you-need-assistance

For further information or to report any problems, contact
http://community.ti.com/ or http://support.ti.com/

.. rubric:: **Linux Kernel**
   :name: linux-kernel

.. rubric:: **System Benchmarks**
   :name: system-benchmarks

.. rubric:: LMBench
   :name: lmbench

**LMBench**
LMBENCH / host LMBENCH\_L\_PERF\_HostSide
**2017.05**
am574x-idk
af\_unix\_sock\_stream\_latency (microsec)
58.53
af\_unix\_socket\_stream\_bandwidt (MBs)
1350.78
bw\_file\_rd-io-1mb (MB/s)
809.72
bw\_file\_rd-o2c-1mb (MB/s)
655.52
bw\_mem-bcopy-16mb (MB/s)
1557.18
bw\_mem-bcopy-1mb (MB/s)
3534.23
bw\_mem-bcopy-2mb (MB/s)
2561.76
bw\_mem-bcopy-4mb (MB/s)
1658.15
bw\_mem-bcopy-8mb (MB/s)
1563.42
bw\_mem-bzero-16mb (MB/s)
3955.01
bw\_mem-bzero-1mb (MB/s)
3916.5 (min 3534.23, max 4298.76)
bw\_mem-bzero-2mb (MB/s)
3397.66 (min 2561.76, max 4233.55)
bw\_mem-bzero-4mb (MB/s)
2903.41 (min 1658.15, max 4148.66)
bw\_mem-bzero-8mb (MB/s)
2782.71 (min 1563.42, max 4002.0)
bw\_mem-cp-16mb (MB/s)
851.83
bw\_mem-cp-1mb (MB/s)
3664.66 (min 2922.47, max 4406.84)
bw\_mem-cp-2mb (MB/s)
2639.43 (min 998.5, max 4280.36)
bw\_mem-cp-4mb (MB/s)
2504.17 (min 864.68, max 4143.65)
bw\_mem-cp-8mb (MB/s)
2438.5 (min 854.88, max 4022.12)
bw\_mem-fcp-16mb (MB/s)
784.35
bw\_mem-fcp-1mb (MB/s)
3165.45 (min 2032.14, max 4298.76)
bw\_mem-fcp-2mb (MB/s)
2566.62 (min 899.69, max 4233.55)
bw\_mem-fcp-4mb (MB/s)
2451.34 (min 754.01, max 4148.66)
bw\_mem-fcp-8mb (MB/s)
2392.7 (min 783.39, max 4002.0)
bw\_mem-frd-16mb (MB/s)
791.45
bw\_mem-frd-1mb (MB/s)
2039.71 (min 2032.14, max 2047.27)
bw\_mem-frd-2mb (MB/s)
1228.82 (min 899.69, max 1557.94)
bw\_mem-frd-4mb (MB/s)
829.45 (min 754.01, max 904.88)
bw\_mem-frd-8mb (MB/s)
789.83 (min 783.39, max 796.26)
bw\_mem-fwr-16mb (MB/s)
3901.96
bw\_mem-fwr-1mb (MB/s)
3227.06 (min 2047.27, max 4406.84)
bw\_mem-fwr-2mb (MB/s)
2919.15 (min 1557.94, max 4280.36)
bw\_mem-fwr-4mb (MB/s)
2524.27 (min 904.88, max 4143.65)
bw\_mem-fwr-8mb (MB/s)
2409.19 (min 796.26, max 4022.12)
bw\_mem-rd-16mb (MB/s)
2638.52
bw\_mem-rd-1mb (MB/s)
8139.86 (min 7196.9, max 9082.81)
bw\_mem-rd-2mb (MB/s)
6381.7 (min 5323.19, max 7440.21)
bw\_mem-rd-4mb (MB/s)
2059.64 (min 1191.01, max 2928.26)
bw\_mem-rd-8mb (MB/s)
1801.24 (min 934.91, max 2667.56)
bw\_mem-rdwr-16mb (MB/s)
693.99
bw\_mem-rdwr-1mb (MB/s)
3756.08 (min 2922.47, max 4589.68)
bw\_mem-rdwr-2mb (MB/s)
1982.93 (min 998.5, max 2967.36)
bw\_mem-rdwr-4mb (MB/s)
841.93 (min 819.17, max 864.68)
bw\_mem-rdwr-8mb (MB/s)
779.15 (min 703.42, max 854.88)
bw\_mem-wr-16mb (MB/s)
912.1
bw\_mem-wr-1mb (MB/s)
6836.25 (min 4589.68, max 9082.81)
bw\_mem-wr-2mb (MB/s)
5203.79 (min 2967.36, max 7440.21)
bw\_mem-wr-4mb (MB/s)
1005.09 (min 819.17, max 1191.01)
bw\_mem-wr-8mb (MB/s)
819.17 (min 703.42, max 934.91)
bw\_mmap\_rd-mo-1mb (MB/s)
2048.8
bw\_mmap\_rd-o2c-1mb (MB/s)
786.63
bw\_pipe (MB/s)
355.14
bw\_unix (MB/s)
1350.78
lat\_connect (us)
93.13
lat\_ctx-2-128k (us)
12.48
lat\_ctx-2-256k (us)
18.91
lat\_ctx-4-128k (us)
14.19
lat\_ctx-4-256k (us)
28.42
lat\_fs-0k (num\_files)
170.0
lat\_fs-10k (num\_files)
77.0
lat\_fs-1k (num\_files)
111.0
lat\_fs-4k (num\_files)
101.0
lat\_mem\_rd-stride128-sz1000k (ns)
19.31
lat\_mem\_rd-stride128-sz125k (ns)
19.06
lat\_mem\_rd-stride128-sz250k (ns)
19.27
lat\_mem\_rd-stride128-sz31k (ns)
9.71
lat\_mem\_rd-stride128-sz50 (ns)
4.01
lat\_mem\_rd-stride128-sz500k (ns)
19.28
lat\_mem\_rd-stride128-sz62k (ns)
19.05
lat\_mmap-1m (us)
91.0
lat\_ops-double-add (ns)
1.1
lat\_ops-double-mul (ns)
5.03
lat\_ops-float-add (ns)
1.1
lat\_ops-float-mul (ns)
5.03
lat\_ops-int-add (ns)
1.01
lat\_ops-int-bit (ns)
1.01
lat\_ops-int-div (ns)
90.47
lat\_ops-int-mod (ns)
13.1
lat\_ops-int-mul (ns)
3.12
lat\_ops-int64-add (ns)
1.11
lat\_ops-int64-bit (ns)
1.01
lat\_ops-int64-div (ns)
184.86
lat\_ops-int64-mod (ns)
31.23
lat\_pagefault (us)
1.86
lat\_pipe (us)
37.82
lat\_proc-exec (us)
1048.67
lat\_proc-fork (us)
944.33
lat\_proc-proccall (us)
0.01
lat\_select (us)
45.42
lat\_sem (us)
6.48
lat\_sig-catch (us)
5.69
lat\_sig-install (us)
0.99
lat\_sig-prot (us)
0.74
lat\_syscall-fstat (us)
2.69
lat\_syscall-null (us)
0.47
lat\_syscall-open (us)
225.04
lat\_syscall-read (us)
0.62
lat\_syscall-stat (us)
7.52
lat\_syscall-write (us)
0.51
lat\_tcp (us)
0.82
lat\_unix (us)
58.53
latency\_for\_0.50\_mb\_block\_size (nanosec)
19.28
latency\_for\_1.00\_mb\_block\_size (nanosec)
9.66 (min 0.0, max 19.31)
pipe\_bandwidth (MBs)
355.14
pipe\_latency (microsec)
37.82
procedure\_call (microsec)
0.01
select\_on\_200\_tcp\_fds (microsec)
45.42
semaphore\_latency (microsec)
6.48
signal\_handler\_latency (microsec)
0.99
signal\_handler\_overhead (microsec)
5.69
tcp\_ip\_connection\_cost\_to\_loca (microsec)
93.13
tcp\_latency\_using\_localhost (microsec)
0.82
.. rubric:: Dhrystone
   :name: dhrystone

**Dhrystone Benchmark**
ARM Benchmarks / host Dhrystone\_S\_PERF\_HostSide
**2017.05**
am574x-idk
cpu\_clock (MHz)
1000.0
dhrystone\_per\_mhz (DMIPS/MHz)
3.6
dhrystone\_per\_second (DhrystoneP)
6451613.0
.. rubric:: Whestone
   :name: whestone

**Whestone Benchmark**
ARM Benchmarks / host Whetstone\_S\_PERF\_HostSide
**2017.05**
am574x-idk
whetstone (MIPS)
2000.0
.. rubric:: Linpack
   :name: linpack

**Linpack Benchmark**
ARM Benchmarks / host Linpack\_S\_PERF\_HostSide
**2017.05**
am574x-idk
linpack (Kflops)
686667.0
.. rubric:: NBench
   :name: nbench

**NBench Benchmarks**
ARM Benchmarks / host NBench\_S\_PERF\_HostSide
**2017.05**
am574x-idk
assignment (Iterations)
11.34
fourier (Iterations)
8625.5
fp\_emulation (Iterations)
102.59
huffman (Iterations)
947.98
idea (Iterations)
2907.8
lu\_decomposition (Iterations)
550.59
neural\_net (Iterations)
14.66
numeric\_sort (Iterations)
514.35
string\_sort (Iterations)
91.15
.. rubric:: Stream
   :name: stream

**Stream Benchmarks**
ARM Benchmarks / host Stream\_1\_core\_S\_PERF\_Hostside
**2017.05**
am574x-idk
add (MB/s)
2832.2
copy (MB/s)
3024.2
scale (MB/s)
3195.4
triad (MB/s)
2834.9
.. rubric:: **Maximum Latency under different use cases**
   :name: maximum-latency-under-different-use-cases

.. rubric:: Shield (dedicated core) Case
   :name: shield-dedicated-core-case

| The following tests measure worst-case latency under different
  scenarios or use cases.
| Cyclictest application was used to measured latency. Each test ran for
  4 hours.
| Two cgroups were used using shield\_shell procedure shown below.
| The application running the use case and cyclictest ran on a dedicated
  cpu (rt) while the rest of threads ran on nonrt cpu.

::

    shield_shell()
    {
    create_cgroup nonrt 0
    create_cgroup rt 1
    for pid in $(cat /sys/fs/cgroup/tasks); do /bin/echo $pid > /sys/fs/cgroup/nonrt/tasks; done
    /bin/echo $$ > /sys/fs/cgroup/rt/tasks
    }

| 

**Max Latency for shielded use cases**
Use Case
**2017.05**
am574x-idk
**Latency**
L\_PERF\_SHIELD\_SMP\_1080ENC
48.0
L\_PERF\_SHIELD\_SMP\_1080ENCDEC
47.0
L\_PERF\_SHIELD\_SMP\_GRAPHICS
40.0
L\_PERF\_SHIELD\_SMP\_HACKBENCH
63.0
L\_PERF\_SHIELD\_SMP\_MEM
42.0
L\_PERF\_SHIELD\_SMP\_NET
26.0
L\_PERF\_SHIELD\_SMP\_NO\_LOAD
25.0
L\_PERF\_SHIELD\_SMP\_STRESS\_LOAD
51.0
L\_PERF\_SHIELD\_SMP\_UART
41.0
L\_PERF\_SHIELD\_SMP\_USB
58.0
L\_PERF\_SHIELD\_SMP\_USB\_NET
59.0
| 

| 

.. rubric:: **OSADL Test**
   :name: osadl-test

Latency test used by https://www.osadl.org/ Command: "cyclictest
-l100000000 -m -n -a0 -t1 -p99 -i200 -h400 -q"

.. rubric:: am574x-idk
   :name: am574x-idk

::

    # Total: 100000000
    # Min Latencies: 00007
    # Avg Latencies: 00010
    # Max Latencies: 00027
    # Histogram Overflows: 00000

    # Histogram
    000000 000000
    000001 000000
    000002 000000
    000003 000000
    000004 000000
    000005 000000
    000006 000000
    000007 058012
    000008 2493021
    000009 332386
    000010 39660088
    000011 53158895
    000012 1800803
    000013 137575
    000014 069172
    000015 268388
    000016 1577346
    000017 408421
    000018 021530
    000019 002724
    000020 000296
    000021 002329
    000022 007020
    000023 001387
    000024 000415
    000025 000133 
    000026 000056
    000027 000003
    000028 000000

| 

.. rubric:: **Boot-time Measurement**
   :name: boot-time-measurement

.. rubric:: Sensor Capture
   :name: sensor-capture

Capture video frames (MMAP buffers) with v4l2c-ctl and record the
reported fps

**Sensor Capture**
Resolution
Format
**2017.05**
am574x-idk
**Fps**
**Sensor**
1600x1200
ba81
ov2659
1600x1200
rgb4
ov2659
320x240
ba81
ov2659
320x240
rgb4
ov2659
.. rubric:: Display Driver
   :name: display-driver

Set different display modes using modetest's sync plus flip option
(modetest -v -s ...)

**Display performance (LCD)**
Mode
**2017.05**
am574x-idk
**Fps**
1920x1200@60
59.99 (min 59.01, max 60.11)
| 

**Display performance (HDMI)**
Mode
**2017.05**
am574x-idk
**Fps**
1024x576@60
59.97 (min 59.91, max 60.0)
1024x768@60
60.0 (min 59.94, max 60.11)
1024x768@70
70.07 (min 70.0, max 70.17)
1024x768@75
75.03 (min 74.6, max 75.37)
1152x864@75
75.0 (min 74.89, max 75.09)
1280x1024@60
60.02 (min 59.65, max 60.37)
1280x1024@75
75.02 (min 74.93, max 75.12)
1280x720@60
60.0 (min 59.95, max 60.06)
1280x768@60
59.87 (min 59.77, max 59.98)
1280x768@75
74.89 (min 74.79, max 75.02)
1280x800@60
59.81 (min 59.77, max 59.87)
1280x800@75
74.93 (min 74.74, max 75.07)
1280x960@60
60.0 (min 59.92, max 60.08)
1360x768@60
59.8 (min 59.42, max 60.15)
1400x1050@60
59.98 (min 59.92, max 60.05)
1400x1050@75
74.87 (min 74.43, max 75.21)
1440x900@60
59.89 (min 59.36, max 60.43)
1440x900@75
74.98 (min 74.92, max 75.11)
1600x1200@60
60.0 (min 59.93, max 60.06)
1600x1200@65
65.0 (min 64.95, max 65.1)
1600x900@60
60.0 (min 59.96, max 60.06)
1680x1050@60
59.95 (min 59.83, max 60.05)
1680x945@60
60.02 (min 59.8, max 60.25)
1920x1080@60
60.0 (min 59.88, max 60.11)
2048x1152@60
60.0 (min 59.94, max 60.08)
640x480@60
60.0 (min 59.95, max 60.07)
640x480@73
72.81 (min 72.68, max 72.9)
640x480@75
75.0 (min 74.73, max 75.26)
720x400@70
70.08 (min 69.93, max 70.18)
800x600@56
56.25 (min 56.19, max 56.35)
800x600@60
60.32 (min 60.27, max 60.37)
800x600@72
72.19 (min 72.1, max 72.29)
800x600@75
75.0 (min 74.15, max 75.86)
832x624@75
74.55 (min 74.18, max 74.84)
848x480@60
60.0 (min 59.93, max 60.05)
| 

.. rubric:: Graphics SGX Driver
   :name: graphics-sgx-driver

Run GLBenchmark and capture performance reported Display rate (Fps),
Fill rate, Vertex Throughput, etc. All display outputs (HDMI and LCD)
are connected when running these tests

.. rubric:: Performance (Fps)
   :name: performance-fps

**GLBenchmark 2.5 Performance**
Benchmark
**2017.05**
am574x-idk
**Test Number**
**Fps**
GLB25\_EgyptTestC24Z16FixedTime test
2500005.0
22.42 (min 11.76, max 47.22)
GLB25\_EgyptTestC24Z16\_ETC1 test
2501001.0
28.66 (min 11.99, max 60.01)
GLB25\_EgyptTestC24Z16\_ETC1to565 test
2501401.0
28.61 (min 11.99, max 60.01)
GLB25\_EgyptTestC24Z16\_PVRTC4 test
2501101.0
28.53 (min 11.76, max 60.01)
GLB25\_EgyptTestC24Z24MS4 test
2500003.0
25.85 (min 11.22, max 59.99)
GLB25\_EgyptTestStandard\_inherited test
2000000.0
59.99 (min 58.74, max 60.45)
.. rubric:: Vertex Throughput
   :name: vertex-throughput

**GLBenchmark 2.5 Vertex Throughput**
Benchmark
**2017.05**
am574x-idk
**Test Number**
**Rate (triangles/sec)**
GLB25\_TriangleTexFragmentLitTestC24Z16 test
2500511.0
12249212.0
GLB25\_TriangleTexTestC24Z16 test
2500301.0
46891760.0
GLB25\_TriangleTexVertexLitTestC24Z16 test
2500411.0
18568814.0
.. rubric:: Pixel Throughput
   :name: pixel-throughput

**GLBenchmark 2.5 Pixel Throughput**
Benchmark
**2017.05**
am574x-idk
**Test Number**
**Rate (texel/sec)**
**Fps**
GLB25\_FillTestC24Z16 test
2500101.0
755731648.0
30.71 (min 30.49, max 31.0)
| 

.. rubric:: Multimedia (Decode)
   :name: multimedia-decode

Run gstreamer pipeline "gst-launch-1.0 playbin uri=file://<Path to
stream> video-sink="kmssink sync=false connector=<connector id>"
audio-sink=fakesink" and calculate performance based on the execution
time reported. All display display outputs (HDMI and LCD) were connected
when running these tests, but playout was forced to LCD via the
connector=<connector id> option.

.. rubric:: H264
   :name: h264

**Gstreamer H264 in AVI Container Decode Performance**
Resolution
**2017.05**
am574x-idk
**Fps**
**IVA Freq (MHz)**
**IPU Freq (MHz)**
1080p
59.5
720p
59.94
720x480
60.0
800x480
60.0
| 

**Gstreamer H264 in MP4 Container Decode Performance**
Resolution
**2017.05**
am574x-idk
**Fps**
**IVA Freq (MHz)**
**IPU Freq (MHz)**
1080p
59.5
720p
59.94
720x480
60.0
800x480
60.0
CIF
60.0
| 

.. rubric:: MPEG4
   :name: mpeg4

**GStreamer MPEG4 in MP4 Container Decode Performance**
Resolution
**2017.05**
am574x-idk
**Fps**
**IVA Freq (MHz)**
**IPU Freq (MHz)**
720p
59.94
VGA
60.0
| 

**GStreamer MPEG4 in AVI Container Decode Performance**
Resolution
**2017.05**
am574x-idk
**Fps**
**IVA Freq (MHz)**
**IPU Freq (MHz)**
720x576
61.11
VGA
63.75
| 

**GStreamer MPEG4 in 3GP Container Decode Performance**
Resolution
**2017.05**
am574x-idk
**Fps**
**IVA Freq (MHz)**
**IPU Freq (MHz)**
CIF
60.0
QVGA
60.0
VGA
63.75
| 

.. rubric:: MPEG2
   :name: mpeg2

**GStreamer MPEG2 in MP4 Container Decode Performance**
Resolution
**2017.05**
am574x-idk
**Fps**
**IVA Freq (MHz)**
**IPU Freq (MHz)**
720p
59.94
| 

| 

.. rubric:: Ethernet Driver
   :name: ethernet-driver

.. rubric:: TCP Performance
   :name: tcp-performance

**Ethernet performance table**
TCP Window Size(Kbytes)
**2017.05-RT**
am574x-idk
**Bandwidth (without interrupt pacing, in Mbits/sec)**
**CPU Load (without interrupt pacing, in %)**
**Bandwidth (with interrupt pacing, in Mbits/sec)**
**CPU Load (with interrupt pacing, in %)**
8
293.6
296.8
16
248.8
437.6
32
36.96
138.16
64
311.2
17.52
128
38.56
44.72
256
172.0
172.0
.. rubric:: UDP Performance
   :name: udp-performance

'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_64B\_ingress
**2017.05-RT**
am574x-idk
packet\_size (bytes)
64.0
packets\_per\_second (kpps)
58.0
throughput (Mbits/s)
30.1
| 

'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_128B\_ingress
**2017.05-RT**
am574x-idk
packet\_size (bytes)
128.0
packets\_per\_second (kpps)
29.0
throughput (Mbits/s)
30.3
| 

'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_256B\_ingress
**2017.05-RT**
am574x-idk
packet\_size (bytes)
256.0
packets\_per\_second (kpps)
35.0
throughput (Mbits/s)
73.3
| 

'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_512B\_ingress
**2017.05-RT**
am574x-idk
packet\_size (bytes)
512.0
packets\_per\_second (kpps)
55.0
throughput (Mbits/s)
228.0
| 

'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_1024B\_ingress
**2017.05-RT**
am574x-idk
packet\_size (bytes)
1024.0
packets\_per\_second (kpps)
20.0
throughput (Mbits/s)
165.0
| 

'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_1470B\_ingress
**2017.05-RT**
am574x-idk
packet\_size (bytes)
1470.0
packets\_per\_second (kpps)
72.0
throughput (Mbits/s)
858.0
| 

'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_64B\_egress
**2017.05-RT**
am574x-idk
packet\_size (bytes)
64.0
packets\_per\_second (kpps)
25.0
throughput (Mbits/s)
13.4
| 

'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_128B\_egress
**2017.05-RT**
am574x-idk
packet\_size (bytes)
128.0
packets\_per\_second (kpps)
27.0
throughput (Mbits/s)
28.3
| 

'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_256B\_egress
**2017.05-RT**
am574x-idk
packet\_size (bytes)
256.0
packets\_per\_second (kpps)
28.0
throughput (Mbits/s)
58.7
| 

'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_1024B\_egress
**2017.05-RT**
am574x-idk
packet\_size (bytes)
1024.0
packets\_per\_second (kpps)
11.0
throughput (Mbits/s)
93.9
| 

The performance numbers were captured using the iperf tool. Usage
details are mentioned below:

-  iperf version 2.0.5
-  On PC Host invoke iperf in the server mode.

::

    iperf -s

-  On the DUT iperf is invoked in client mode   (bi-directional traffic
   for 60 seconds).

::

    iperf -c <server ip> -w <window size> -m -f M -d -t 60

-  Interrupt pacing feature enabled with pacing interval set to
   500usecs. For faster processors such as DRA7 and AM57, 100usecs was
   used.

::

    ethtool -C eth0 rx-usecs 500

-  DUT is connected to a gigabit network.

| 

.. rubric:: USB Driver
   :name: usb-driver

.. rubric:: XHCI Host controller
   :name: xhci-host-controller

.. raw:: html

   <div style="padding:5px; background: #eeeeee; color: #348017">

| **IMPORTANT**
| For Mass-storage applications, the performance numbers can be severely
  affected if the media is mounted in sync mode. Hot plug scripts in the
  filesystem mount removable media in sync mode to ensure data
  integrity. For performance sensitive applications, umount the
  auto-mounted filesystem and re-mount in async mode.

.. raw:: html

   </div>

| 

**Setup** : Western Digital 1TB (My Book Essential) USB hard disk is
connected to usb0 port. File read/write performance data on usb0 port is
captured. For detailed test setup refer to `USB MSC host test
setup </index.php/Sitara_PSP_Test_Setup#MUSB_Host_MSC>`__

.. rubric:: AM574X-IDK USB MSC Host mode EXT2 File System Performance
   :name: am574x-idk-usb-msc-host-mode-ext2-file-system-performance

+------------------------------+-------------------------------------+-----------------------+
| **Buffer Size (in Bytes)**   | **Transfer Rate (in MBytes/sec)**   | **CPU Load (in %)**   |
+==============================+=====================================+=======================+
| 102400                       | 87.33                               | 57.44                 |
+------------------------------+-------------------------------------+-----------------------+
| 1048576                      | 86.99                               | 56.65                 |
+------------------------------+-------------------------------------+-----------------------+
| 5242880                      | 87.31                               | 57.98                 |
+------------------------------+-------------------------------------+-----------------------+

Table:  **USB-MSC XHCI Host-Write Performance values**

| 

+------------------------------+-------------------------------------+-----------------------+
| **Buffer Size (in Bytes)**   | **Transfer Rate (in MBytes/sec)**   | **CPU Load (in %)**   |
+==============================+=====================================+=======================+
| 102400                       | 175.01                              | 45.87                 |
+------------------------------+-------------------------------------+-----------------------+
| 1048576                      | 177.89                              | 50.86                 |
+------------------------------+-------------------------------------+-----------------------+
| 5242880                      | 170.79                              | 48.72                 |
+------------------------------+-------------------------------------+-----------------------+

Table:  **USB-MSC XHCI Host-Read Performance values**

.. rubric:: AM574X-IDK USB MSC Host mode VFAT File System Performance
   :name: am574x-idk-usb-msc-host-mode-vfat-file-system-performance

+------------------------------+-------------------------------------+-----------------------+
| **Buffer Size (in Bytes)**   | **Transfer Rate (in MBytes/sec)**   | **CPU Load (in %)**   |
+==============================+=====================================+=======================+
| 102400                       | 87.38                               | 55.08                 |
+------------------------------+-------------------------------------+-----------------------+
| 262144                       | 87.81                               | 55.65                 |
+------------------------------+-------------------------------------+-----------------------+

Table:  **USB-MSC XHCI Host-Write Performance values**

| 

+------------------------------+-------------------------------------+-----------------------+
| **Buffer Size (in Bytes)**   | **Transfer Rate (in MBytes/sec)**   | **CPU Load (in %)**   |
+==============================+=====================================+=======================+
| 102400                       | 184.90                              | 53.33                 |
+------------------------------+-------------------------------------+-----------------------+
| 262144                       | 175.90                              | 54.78                 |
+------------------------------+-------------------------------------+-----------------------+

Table:  **USB-MSC XHCI Host-Read Performance values**

| 

.. rubric:: USB Mass Storage Class Slave Driver
   :name: usb-mass-storage-class-slave-driver

| The performance numbers are captured using a file inside /dev/shm as
  storage gadget media exposed as removable media to an Ubuntu 10.04
  host over USB. The storage media is formatted as vfat filesystem.
| Storage gadget media file is created using the command:

::

    # dd if=/dev/zero of=/dev/shm/50M bs=1M count=50"

Insert the USB mass storage gadget with ``/dev/shm/50M`` as the backing
storage:

::

    # insmod g_mass_storage.ko file=/dev/shm/50M 

For test setup details refer to `USB MSC device
setup </index.php/Sitara_PSP_Test_Setup#MUSB_Device_MSC>`__

.. rubric:: AM574X-IDK USB SLAVE DEVICE PERFORMANCE
   :name: am574x-idk-usb-slave-device-performance

+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+
| **Bytes Transferred (MB)"/dev/shm/50M" file as storage device**   | **Number of files transferred**   | **Total Bytes transferred (MB)**   | **Transfer Rate (MB/sec)**   |
+===================================================================+===================================+====================================+==============================+
| 50                                                                | 1                                 | 50                                 | 37.8                         |
+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+

Table:  **AM574X-IDK USB Slave Read Performance values**

+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+
| **Bytes Transferred (MB)"/dev/shm/50M" file as storage device**   | **Number of files transferred**   | **Total Bytes transferred (MB)**   | **Transfer Rate (MB/sec)**   |
+===================================================================+===================================+====================================+==============================+
| 50                                                                | 1                                 | 50                                 | 36.2                         |
+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+

Table:  **AM574X-IDK USB Slave Write Performance values**

| 

.. rubric:: USB CDC/RNDIS Slave Driver
   :name: usb-cdcrndis-slave-driver

Performance benchmarks were collected using the Iperf tool and default
options were used to collect the throughput numbers.

.. rubric:: AM574X-IDK USB CDC Performance
   :name: am574x-idk-usb-cdc-performance

+----------------------------------+-----------------------------+-----------------------------+
| **TCP Window Size(in KBytes)**   | **Interval (in Seconds)**   | **Bandwidth (Mbits/Sec)**   |
+==================================+=============================+=============================+
| 16                               | 60                          | 187.5                       |
+----------------------------------+-----------------------------+-----------------------------+
| 32                               | 60                          | 185.1                       |
+----------------------------------+-----------------------------+-----------------------------+
| 64                               | 60                          | 191.1                       |
+----------------------------------+-----------------------------+-----------------------------+
| 128                              | 60                          | 197.5                       |
+----------------------------------+-----------------------------+-----------------------------+

Table:  **AM574X-IDK USB CDC Performance values - Client**

| 

.. rubric:: AM574X-IDK USB RNDIS Performance
   :name: am574x-idk-usb-rndis-performance

+----------------------------------+-----------------------------+-----------------------------+
| **TCP Window Size(in KBytes)**   | **Interval (in Seconds)**   | **Bandwidth (Mbits/Sec)**   |
+==================================+=============================+=============================+
| 16                               | 60                          | 152.0                       |
+----------------------------------+-----------------------------+-----------------------------+
| 32                               | 60                          | 165.1                       |
+----------------------------------+-----------------------------+-----------------------------+
| 64                               | 60                          | 168.0                       |
+----------------------------------+-----------------------------+-----------------------------+
| 128                              | 60                          | 173.7                       |
+----------------------------------+-----------------------------+-----------------------------+

Table:  **AM574X-IDK USB RNDIS Performance values - Client**

| 

.. rubric:: CRYPTO Driver
   :name: crypto-driver

.. rubric:: OpenSSL Performance
   :name: openssl-performance

'
CRYPTO / host / openssl\_performance\_tests
Crypto\_M\_PERF\_openssl\_perf\_hardware\_acceleration
**2017.05-RT**
am574x-idk
aes-128-cbc\_cpu\_util (%)
52.0
aes-128-cbc\_system\_time (s)
7.8
aes-128-cbc\_user\_time (s)
0.35
aes-128-cbc\_throughput\_16\_byte (KBytes/s)
1393.78
aes-128-cbc\_throughput\_256\_byt (KBytes/s)
2578.09
aes-128-cbc\_throughput\_64\_byte (KBytes/s)
4929.3
aes-128-cbc\_throughput\_1024\_by (KBytes/s)
6304.43
aes-128-cbc\_throughput\_8192\_by (KBytes/s)
22241.28
aes-192-cbc\_cpu\_util (%)
53.0
aes-192-cbc\_system\_time (s)
7.7
aes-192-cbc\_user\_time (s)
0.35
aes-192-cbc\_throughput\_16\_byte (KBytes/s)
1354.58
aes-192-cbc\_throughput\_256\_byt (KBytes/s)
2013.7
aes-192-cbc\_throughput\_64\_byte (KBytes/s)
4690.65
aes-192-cbc\_throughput\_1024\_by (KBytes/s)
6783.32
aes-192-cbc\_throughput\_8192\_by (KBytes/s)
25529.0
aes-256-cbc\_cpu\_util (%)
53.0
aes-256-cbc\_system\_time (s)
7.9
aes-256-cbc\_user\_time (s)
0.2
aes-256-cbc\_throughput\_16\_byte (KBytes/s)
1344.7
aes-256-cbc\_throughput\_256\_byt (KBytes/s)
2304.85
aes-256-cbc\_throughput\_64\_byte (KBytes/s)
4615.08
aes-256-cbc\_throughput\_1024\_by (KBytes/s)
7605.25
aes-256-cbc\_throughput\_8192\_by (KBytes/s)
22033.75
des-cbc\_cpu\_util (%)
21.0
des-cbc\_system\_time (s)
3.15
des-cbc\_user\_time (s)
0.11
des-cbc\_throughput\_16\_bytes (KBytes/s)
147.81
des-cbc\_throughput\_256\_bytes (KBytes/s)
2165.42
des-cbc\_throughput\_64\_bytes (KBytes/s)
487.51
des-cbc\_throughput\_1024\_bytes (KBytes/s)
6049.45
des-cbc\_throughput\_8192\_bytes (KBytes/s)
13535.91
des3\_cpu\_util (%)
23.0
des3\_system\_time (s)
3.5
des3\_user\_time (s)
0.05
des3\_throughput\_16\_bytes (KBytes/s)
118.86
des3\_throughput\_64\_bytes (KBytes/s)
437.46
des3\_throughput\_256\_bytes (KBytes/s)
1911.04
des3\_throughput\_1024\_bytes (KBytes/s)
5157.21
des3\_throughput\_8192\_bytes (KBytes/s)
13068.97
md5\_cpu\_util (%)
70.0
md5\_system\_time (s)
8.9
md5\_user\_time (s)
1.67
md5\_throughput\_16\_bytes (KBytes/s)
492.34
md5\_throughput\_64\_bytes (KBytes/s)
1933.44
md5\_throughput\_256\_bytes (KBytes/s)
2060.03
md5\_throughput\_1024\_bytes (KBytes/s)
6845.44
md5\_throughput\_8192\_bytes (KBytes/s)
36484.44
sha1\_cpu\_util (%)
69.0
sha1\_system\_time (s)
8.87
sha1\_user\_time (s)
1.64
sha1\_throughput\_16\_bytes (KBytes/s)
449.41
sha1\_throughput\_64\_bytes (KBytes/s)
1741.4
sha1\_throughput\_256\_bytes (KBytes/s)
2066.18
sha1\_throughput\_1024\_bytes (KBytes/s)
6847.49
sha1\_throughput\_8192\_bytes (KBytes/s)
36230.49
| 

| Listed for each algorithm are the code snippets used to run each
  benchmark test.

| 

::

    time -v openssl speed -elapsed -evp aes-128-cbc

.. rubric:: IPSec Performance
   :name: ipsec-performance

'
Hardware Crypto-based IPSec Throughput
**2017.05-RT**
am574x-idk
udp\_aes128\_sha1 (Mbps)
141.3
udp\_aes192\_sha1 (Mbps)
141.3
udp\_aes256\_sha1 (Mbps)
148.7
| 

.. rubric:: NAND Driver
   :name: nand-driver

Please refer `MTD Test
Setup </index.php/Sitara_PSP_Test_Setup#Memory_Technology_Device_.28MTD_-_NAND.2C_NOR.2C_OneNAND_Flash.29>`__
before proceeding.

.. rubric:: QSPI Flash Driver
   :name: qspi-flash-driver

Test setup is available
`here </index.php/Sitara_PSP_Test_Setup#Memory_Technology_Device_.28MTD_-_NAND.2C_NOR.2C_OneNAND_Flash.29>`__.

.. rubric:: AM574x-IDK
   :name: am574x-idk-1

'
Buffer size (bytes)
**2017.05**
am574x-idk
**Write UBIFS Throughput (Mbytes/sec)**
**Write UBIFS CPU Load (%)**
**Read UBIFS Throughput (Mbytes/sec)**
**Read UBIFS CPU Load (%)**
102400
0.53
73.08
18.08
26.09
262144
0.53
75.31
17.59
21.74
524288
0.53
75.58
17.12
21.74
1048576
0.53
72.68
17.26
19.05
.. rubric:: SPI Flash Driver
   :name: spi-flash-driver

.. rubric:: K2HK-EVM
   :name: k2hk-evm

.. rubric:: EMMC Driver
   :name: emmc-driver

.. raw:: html

   <div style="padding:5px; background: #eeeeee; color: #348017">

| **IMPORTANT**
| The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

.. raw:: html

   </div>

Please refer `MMC/SD Test
Setup </index.php/Sitara_PSP_Test_Setup#MMC.2FSD>`__ before proceeding.

.. rubric:: AM574X-IDK
   :name: am574x-idk-2

'
Buffer size (bytes)
**2017.05**
am574x-idk
**Write EXT4 Throughput (Mbytes/sec)**
**Write EXT4 CPU Load (%)**
**Read EXT4 Throughput (Mbytes/sec)**
**Read EXT4 CPU Load (%)**
102400
49.47
21.85
56.94
10.99
262144
48.46
22.86
60.58
16.62
524288
49.07
21.9
58.24
12.11
1048576
49.82
22.86
60.65
13.17
5242880
48.31
22.14
54.95
13.3
| 

'
Buffer size (bytes)
**2017.05**
am574x-idk
**Write EXT2 Throughput (Mbytes/sec)**
**Write EXT2 CPU Load (%)**
**Read EXT2 Throughput (Mbytes/sec)**
**Read EXT2 CPU Load (%)**
102400
41.77 (min 31.62, max 47.38)
24.37 (min 18.2, max 28.54)
60.76 (min 60.44, max 61.35)
12.17 (min 11.24, max 13.33)
262144
41.18 (min 30.99, max 46.69)
24.1 (min 17.81, max 27.91)
60.24 (min 58.92, max 61.11)
12.2 (min 11.08, max 13.18)
524288
40.24 (min 28.6, max 46.3)
24.1 (min 18.77, max 26.87)
61.09 (min 60.69, max 61.43)
13.59 (min 12.61, max 14.2)
1048576
35.67 (min 29.83, max 46.94)
23.41 (min 21.5, max 27.19)
60.14 (min 57.88, max 61.38)
13.85 (min 13.35, max 14.16)
5242880
35.54 (min 29.95, max 46.33)
22.25 (min 18.7, max 26.68)
60.7 (min 59.9, max 61.62)
14.12 (min 13.82, max 14.37)
| 

'
Buffer size (bytes)
**2017.05**
am574x-idk
**Write VFAT Throughput (Mbytes/sec)**
**Write VFAT CPU Load (%)**
**Read VFAT Throughput (Mbytes/sec)**
**Read VFAT CPU Load (%)**
102400
42.82 (min 42.4, max 43.25)
25.79 (min 25.46, max 25.98)
61.31 (min 61.08, max 61.5)
13.0 (min 12.05, max 14.12)
262144
42.98 (min 42.87, max 43.06)
26.29 (min 25.52, max 27.74)
60.64 (min 60.1, max 61.5)
13.34 (min 12.28, max 13.95)
524288
42.87 (min 42.54, max 43.16)
25.88 (min 25.21, max 26.49)
61.09 (min 60.72, max 61.49)
13.71 (min 12.87, max 14.91)
1048576
42.66 (min 42.37, max 42.93)
25.33 (min 25.0, max 25.77)
61.31 (min 61.15, max 61.51)
14.68 (min 13.35, max 16.03)
5242880
42.71 (min 41.78, max 43.39)
25.96 (min 25.31, max 26.34)
60.54 (min 60.22, max 60.99)
14.62 (min 14.08, max 15.7)
.. rubric:: SATA Driver
   :name: sata-driver

.. rubric:: MMC/SD Driver
   :name: mmcsd-driver

.. raw:: html

   <div style="padding:5px; background: #eeeeee; color: #348017">

| **IMPORTANT**
| The performance numbers can be severely affected if the media is
  mounted in sync mode. Hot plug scripts in the filesystem mount
  removable media in sync mode to ensure data integrity. For performance
  sensitive applications, umount the auto-mounted filesystem and
  re-mount in async mode.

.. raw:: html

   </div>

Please refer `MMC/SD Test
Setup </index.php/Sitara_PSP_Test_Setup#MMC.2FSD>`__ before proceeding.

.. rubric:: AM574X-IDK
   :name: am574x-idk-3

'
Buffer size (bytes)
**2017.05**
am574x-idk
**Write EXT2 Throughput (Mbytes/sec)**
**Write EXT2 CPU Load (%)**
**Read EXT2 Throughput (Mbytes/sec)**
**Read EXT2 CPU Load (%)**
102400
30.55
18.2
70.89
15.12
262144
31.4
19.52
68.76
18.91
524288
30.64
18.24
71.84
16.9
1048576
30.34
19.27
68.89
16.33
5242880
29.66
19.55
70.67
17.29
| 

'
Buffer size (bytes)
**2017.05**
am574x-idk
**Write EXT4 Throughput (Mbytes/sec)**
**Write EXT4 CPU Load (%)**
**Read EXT4 Throughput (Mbytes/sec)**
**Read EXT4 CPU Load (%)**
102400
10.25
5.51
70.54
16.0
262144
10.84
6.84
70.57
15.77
524288
11.02
6.87
72.52
18.18
1048576
11.0
5.8
68.7
18.36
5242880
10.49
5.44
70.72
13.54
| 

'
Buffer size (bytes)
**2017.05**
am574x-idk
**Write VFAT Throughput (Mbytes/sec)**
**Write VFAT CPU Load (%)**
**Read VFAT Throughput (Mbytes/sec)**
**Read VFAT CPU Load (%)**
102400
22.24
13.42
68.37
13.31
262144
12.96
7.97
68.74
14.33
524288
13.21
8.16
69.74
13.29
1048576
14.53
9.27
69.83
15.36
5242880
13.68
9.06
67.45
17.53
| 

| 

| 

The performance numbers were captured using the following:

-  Sandisk Ultra Plus 16GB Micro SDHC UHS card
-  Partition was mounted with async option

.. rubric:: UART Driver
   :name: uart-driver

Performance and Benchmarks not available in this release.

| 

.. rubric:: I2C Driver
   :name: i2c-driver

Performance and Benchmarks not available in this release.

| 

.. rubric:: EDMA Driver
   :name: edma-driver

Performance and Benchmarks not available in this release.

| 

.. rubric:: Touchscreen Driver
   :name: touchscreen-driver

Performance and Benchmarks not available in this release.

| 

| 

.. rubric:: Power Management
   :name: power-management

.. rubric:: Power Measurements
   :name: power-measurements

N/A

| 

