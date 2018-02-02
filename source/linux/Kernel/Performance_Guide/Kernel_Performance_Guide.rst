.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Kernel_Performance_Guide
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
| AM572x EVM     | AM57xx Evaluation Module rev A2 with ARM running at 1500MHz, DDR3L-533 (533 MHz/1066 MT/S), TMDSEVM572x        |
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
which are part of the Process SDK Linux package. This document should be
used in conjunction with release notes and user guides provided with the
Process SDK Linux package for information on specific issues present
with drivers included in a particular release.

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

**LM Bench Metrics**
LMBENCH / host LMBENCH\_L\_PERF\_HostSide
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
af\_unix\_sock\_stream\_latency (microsec)
41.43
24.39
35.93
44.44
697.22
af\_unix\_socket\_stream\_bandwidt (MBs)
172.62
187.51
2062.12
699.86
28.44
bw\_file\_rd-io-1mb (MB/s)
189.47
205.68
1347.19
650.2
39.63
bw\_file\_rd-o2c-1mb (MB/s)
158.58
170.47
1036.45
500.33
35.84
bw\_mem-bcopy-16mb (MB/s)
154.95
193.43
1942.93
1087.18
82.67
bw\_mem-bcopy-1mb (MB/s)
194.63
198.97
4942.03
1157.41
89.32
bw\_mem-bcopy-2mb (MB/s)
204.54
196.95
3359.46
1084.6
89.91
bw\_mem-bcopy-4mb (MB/s)
210.38
197.27
2071.47
1079.62
90.41
bw\_mem-bcopy-8mb (MB/s)
215.63
197.68
1941.75
1081.23
92.99
bw\_mem-bzero-16mb (MB/s)
994.9
672.38
5003.13
2279.85
145.01
bw\_mem-bzero-1mb (MB/s)
589.28 (min 194.63, max 983.93)
436.7 (min 198.97, max 674.42)
5411.11 (min 4942.03, max 5880.19)
2410.56 (min 1157.41, max 3663.71)
116.55 (min 89.32, max 143.78)
bw\_mem-bzero-2mb (MB/s)
594.32 (min 204.54, max 984.09)
435.06 (min 196.95, max 673.17)
4485.27 (min 3359.46, max 5611.08)
1963.51 (min 1084.6, max 2842.42)
117.41 (min 89.91, max 144.91)
bw\_mem-bzero-4mb (MB/s)
607.14 (min 210.38, max 1003.89)
434.94 (min 197.27, max 672.61)
3699.74 (min 2071.47, max 5328.01)
1807.64 (min 1079.62, max 2535.66)
117.85 (min 90.41, max 145.29)
bw\_mem-bzero-8mb (MB/s)
599.76 (min 215.63, max 983.89)
435.37 (min 197.68, max 673.06)
3547.78 (min 1941.75, max 5153.81)
1711.24 (min 1081.23, max 2341.24)
119.08 (min 92.99, max 145.17)
bw\_mem-cp-16mb (MB/s)
173.81
195.33
1043.43
529.22
98.33
bw\_mem-cp-1mb (MB/s)
583.16 (min 182.55, max 983.77)
437.28 (min 201.27, max 673.29)
5261.64 (min 4711.43, max 5811.84)
2213.55 (min 538.21, max 3888.89)
121.43 (min 98.55, max 144.3)
bw\_mem-cp-2mb (MB/s)
589.53 (min 195.29, max 983.77)
436.24 (min 199.08, max 673.4)
3450.95 (min 1220.07, max 5681.82)
1650.29 (min 529.94, max 2770.63)
121.5 (min 97.65, max 145.35)
bw\_mem-cp-4mb (MB/s)
601.09 (min 196.9, max 1005.28)
436.34 (min 200.19, max 672.49)
3201.39 (min 1058.76, max 5344.02)
1515.5 (min 512.89, max 2518.1)
119.61 (min 94.38, max 144.84)
bw\_mem-cp-8mb (MB/s)
602.71 (min 201.77, max 1003.64)
437.24 (min 201.3, max 673.17)
3080.57 (min 1032.92, max 5128.21)
1442.13 (min 531.31, max 2352.94)
124.49 (min 103.97, max 145.01)
bw\_mem-fcp-16mb (MB/s)
280.47
159.48
985.22
534.99
60.92
bw\_mem-fcp-1mb (MB/s)
636.33 (min 288.73, max 983.93)
418.03 (min 161.63, max 674.42)
4424.05 (min 2967.91, max 5880.19)
2096.92 (min 530.13, max 3663.71)
104.35 (min 64.92, max 143.78)
bw\_mem-fcp-2mb (MB/s)
635.75 (min 287.4, max 984.09)
416.56 (min 159.94, max 673.17)
3377.08 (min 1143.07, max 5611.08)
1687.45 (min 532.48, max 2842.42)
105.07 (min 65.23, max 144.91)
bw\_mem-fcp-4mb (MB/s)
648.04 (min 292.18, max 1003.89)
416.07 (min 159.53, max 672.61)
3167.15 (min 1006.29, max 5328.01)
1524.37 (min 513.08, max 2535.66)
105.12 (min 64.94, max 145.29)
bw\_mem-fcp-8mb (MB/s)
629.47 (min 275.04, max 983.89)
416.38 (min 159.69, max 673.06)
3072.45 (min 991.08, max 5153.81)
1433.97 (min 526.7, max 2341.24)
106.08 (min 66.99, max 145.17)
bw\_mem-frd-16mb (MB/s)
248.6
240.51
918.59
671.39
126.02
bw\_mem-frd-1mb (MB/s)
278.58 (min 268.42, max 288.73)
203.5 (min 161.63, max 245.37)
3016.59 (min 2967.91, max 3065.27)
659.45 (min 530.13, max 788.77)
95.58 (min 64.92, max 126.23)
bw\_mem-frd-2mb (MB/s)
269.33 (min 251.26, max 287.4)
200.29 (min 159.94, max 240.64)
1636.66 (min 1143.07, max 2130.25)
609.59 (min 532.48, max 686.7)
95.32 (min 65.23, max 125.41)
bw\_mem-frd-4mb (MB/s)
270.16 (min 248.14, max 292.18)
200.33 (min 159.53, max 241.12)
1041.8 (min 1006.29, max 1077.3)
593.64 (min 513.08, max 674.2)
95.49 (min 64.94, max 126.04)
bw\_mem-frd-8mb (MB/s)
261.58 (min 248.11, max 275.04)
200.19 (min 159.69, max 240.68)
958.67 (min 926.25, max 991.08)
600.02 (min 526.7, max 673.34)
96.35 (min 66.99, max 125.71)
bw\_mem-fwr-16mb (MB/s)
994.41
671.96
4989.09
2288.0
144.9
bw\_mem-fwr-1mb (MB/s)
626.1 (min 268.42, max 983.77)
459.33 (min 245.37, max 673.29)
4438.56 (min 3065.27, max 5811.84)
2338.83 (min 788.77, max 3888.89)
135.27 (min 126.23, max 144.3)
bw\_mem-fwr-2mb (MB/s)
617.52 (min 251.26, max 983.77)
457.02 (min 240.64, max 673.4)
3906.04 (min 2130.25, max 5681.82)
1728.67 (min 686.7, max 2770.63)
135.38 (min 125.41, max 145.35)
bw\_mem-fwr-4mb (MB/s)
626.71 (min 248.14, max 1005.28)
456.81 (min 241.12, max 672.49)
3210.66 (min 1077.3, max 5344.02)
1596.15 (min 674.2, max 2518.1)
135.44 (min 126.04, max 144.84)
bw\_mem-fwr-8mb (MB/s)
625.88 (min 248.11, max 1003.64)
456.93 (min 240.68, max 673.17)
3027.23 (min 926.25, max 5128.21)
1513.14 (min 673.34, max 2352.94)
135.36 (min 125.71, max 145.01)
bw\_mem-rd-16mb (MB/s)
250.7
371.73
3042.4
2163.62
135.89
bw\_mem-rd-1mb (MB/s)
626.11 (min 268.28, max 983.93)
325.98 (min 277.85, max 374.11)
12295.66 (min 10902.83, max 13688.49)
1593.81 (min 776.64, max 2410.98)
345.53 (min 135.81, max 555.25)
bw\_mem-rd-2mb (MB/s)
619.45 (min 254.49, max 984.41)
320.61 (min 273.64, max 367.58)
8778.75 (min 8071.91, max 9485.59)
1400.94 (min 619.67, max 2182.21)
345.55 (min 135.92, max 555.17)
bw\_mem-rd-4mb (MB/s)
626.19 (min 250.99, max 1001.38)
320.63 (min 274.35, max 366.91)
2478.51 (min 1614.21, max 3342.8)
1396.52 (min 623.83, max 2169.2)
346.22 (min 135.72, max 556.72)
bw\_mem-rd-8mb (MB/s)
626.59 (min 250.67, max 1002.51)
321.06 (min 274.42, max 367.7)
2185.38 (min 1309.54, max 3061.22)
1388.65 (min 621.26, max 2156.04)
345.51 (min 135.38, max 555.63)
bw\_mem-rdwr-16mb (MB/s)
201.96
296.52
915.65
519.01
107.04
bw\_mem-rdwr-1mb (MB/s)
193.81 (min 182.55, max 205.07)
247.52 (min 201.27, max 293.77)
5826.6 (min 4711.43, max 6941.77)
568.82 (min 538.21, max 599.43)
102.26 (min 98.55, max 105.97)
bw\_mem-rdwr-2mb (MB/s)
198.58 (min 195.29, max 201.86)
246.75 (min 199.08, max 294.42)
2754.81 (min 1220.07, max 4289.54)
524.41 (min 518.87, max 529.94)
102.26 (min 97.65, max 106.87)
bw\_mem-rdwr-4mb (MB/s)
199.43 (min 196.9, max 201.95)
248.45 (min 200.19, max 296.71)
1077.4 (min 1058.76, max 1096.04)
515.38 (min 512.89, max 517.87)
100.58 (min 94.38, max 106.78)
bw\_mem-rdwr-8mb (MB/s)
201.83 (min 201.77, max 201.89)
249.37 (min 201.3, max 297.43)
981.74 (min 930.56, max 1032.92)
524.56 (min 517.8, max 531.31)
105.52 (min 103.97, max 107.07)
bw\_mem-wr-16mb (MB/s)
994.84
274.79
1279.18
620.01
558.87
bw\_mem-wr-1mb (MB/s)
594.5 (min 205.07, max 983.93)
285.81 (min 277.85, max 293.77)
10315.13 (min 6941.77, max 13688.49)
688.04 (min 599.43, max 776.64)
330.61 (min 105.97, max 555.25)
bw\_mem-wr-2mb (MB/s)
593.14 (min 201.86, max 984.41)
284.03 (min 273.64, max 294.42)
6887.57 (min 4289.54, max 9485.59)
569.27 (min 518.87, max 619.67)
331.02 (min 106.87, max 555.17)
bw\_mem-wr-4mb (MB/s)
601.67 (min 201.95, max 1001.38)
285.53 (min 274.35, max 296.71)
1355.13 (min 1096.04, max 1614.21)
570.85 (min 517.87, max 623.83)
331.75 (min 106.78, max 556.72)
bw\_mem-wr-8mb (MB/s)
602.2 (min 201.89, max 1002.51)
285.93 (min 274.42, max 297.43)
1120.05 (min 930.56, max 1309.54)
569.53 (min 517.8, max 621.26)
331.35 (min 107.07, max 555.63)
bw\_mmap\_rd-mo-1mb (MB/s)
267.49
250.28
3091.47
787.71
126.07
bw\_mmap\_rd-o2c-1mb (MB/s)
178.99
188.36
1198.84
419.58
79.58
bw\_pipe (MB/s)
289.47
361.09
696.81
459.14
26.67
bw\_unix (MB/s)
172.62
187.51
2062.12
699.86
28.44
lat\_connect (us)
68.41
59.89
50.18
78.3
998.0
lat\_ctx-2-128k (us)
494.8
228.54
9.61
4.0
15.0
lat\_ctx-2-256k (us)
2786.75
2330.31
13.06
4.0
15.0
lat\_ctx-4-128k (us)
1083.79
466.49
10.92
4.0
15.0
lat\_ctx-4-256k (us)
3308.21
1865.62
23.08
4.0
15.0
lat\_fs-0k (num\_files)
249.0
310.0
366.0
213.0
21.0
lat\_fs-10k (num\_files)
80.0
83.0
154.0
98.0
8.0
lat\_fs-1k (num\_files)
126.0
141.0
199.0
140.0
12.0
lat\_fs-4k (num\_files)
118.0
141.0
225.0
138.0
12.0
lat\_mem\_rd-stride128-sz1000k (ns)
225.06
98.93
12.83
135.76
244.85
lat\_mem\_rd-stride128-sz125k (ns)
12.27
16.09
12.68
20.08
233.7
lat\_mem\_rd-stride128-sz250k (ns)
76.58
35.19
12.83
20.22
235.9
lat\_mem\_rd-stride128-sz31k (ns)
3.01
12.8
11.45
16.09
190.93
lat\_mem\_rd-stride128-sz50 (ns)
3.02
4.01
2.67
4.01
5.13
lat\_mem\_rd-stride128-sz500k (ns)
187.35
90.98
12.83
51.05
245.23
lat\_mem\_rd-stride128-sz62k (ns)
9.15
16.4
10.21
18.08
236.01
lat\_mmap-1m (us)
62.0
43.0
47.0
81.0
625.0
lat\_ops-double-add (ns)
2.38
1.0
0.73
1.1
35.32
lat\_ops-double-mul (ns)
11.06
7.02
3.34
5.02
118.32
lat\_ops-float-add (ns)
2.28
0.91
0.73
1.09
21.61
lat\_ops-float-mul (ns)
10.06
6.02
3.34
5.02
67.05
lat\_ops-int-add (ns)
1.01
1.01
0.67
1.0
1.71
lat\_ops-int-bit (ns)
1.0
1.0
0.67
1.0
2.57
lat\_ops-int-div (ns)
72.77
96.12
60.14
90.26
192.45
lat\_ops-int-mod (ns)
23.15
21.68
8.69
13.13
92.27
lat\_ops-int-mul (ns)
6.03
4.02
2.07
3.11
6.85
lat\_ops-int64-add (ns)
1.21
1.38
0.74
1.11
5.31
lat\_ops-int64-bit (ns)
1.02
1.02
0.67
1.01
5.16
lat\_ops-int64-div (ns)
210.19
208.54
122.62
176.0
890.5
lat\_ops-int64-mod (ns)
54.87
41.17
20.71
31.11
282.32
lat\_pagefault (us)
1.83
1.44
1.15
1.98
8.96
lat\_pipe (us)
35.78
18.9
23.12
31.96
490.8
lat\_proc-exec (us)
1444.5
1178.4
575.9
975.33
7675.0
lat\_proc-fork (us)
1244.6
1164.0
536.9
836.0
7163.0
lat\_proc-proccall (us)
0.02
0.01
0.01
0.01
0.11
lat\_select (us)
42.19
39.4
28.59
47.95
180.0
lat\_sem (us)
4.97
2.94
2.39
4.78
77.56
lat\_sig-catch (us)
13.09
6.81
3.17
4.9
36.98
lat\_sig-install (us)
1.48
0.87
0.64
0.97
5.25
lat\_sig-prot (us)
0.56
0.48
0.36
0.73
lat\_syscall-fstat (us)
2.26
1.63
1.87
2.79
14.91
lat\_syscall-null (us)
0.55
0.4
0.31
0.49
1.35
lat\_syscall-open (us)
220.82
232.83
150.92
205.04
1633.25
lat\_syscall-read (us)
1.05
0.79
0.41
0.63
3.4
lat\_syscall-stat (us)
6.26
4.64
4.37
6.99
67.39
lat\_syscall-write (us)
0.7
0.55
0.34
0.5
3.34
lat\_tcp (us)
1.06
0.75
0.54
0.81
2.65
lat\_unix (us)
41.43
24.39
35.93
44.44
697.22
latency\_for\_0.50\_mb\_block\_size (nanosec)
187.35
90.98
12.83
51.05
245.23
latency\_for\_1.00\_mb\_block\_size (nanosec)
112.53 (min 0.0, max 225.06)
49.46 (min 0.0, max 98.93)
6.41 (min 0.0, max 12.83)
67.88 (min 0.0, max 135.76)
122.43 (min 0.0, max 244.85)
pipe\_bandwidth (MBs)
289.47
361.09
696.81
459.14
26.67
pipe\_latency (microsec)
35.78
18.9
23.12
31.96
490.8
procedure\_call (microsec)
0.02
0.01
0.01
0.01
0.11
select\_on\_200\_tcp\_fds (microsec)
42.19
39.4
28.59
47.95
180.0
semaphore\_latency (microsec)
4.97
2.94
2.39
4.78
77.56
signal\_handler\_latency (microsec)
1.48
0.87
0.64
0.97
5.25
signal\_handler\_overhead (microsec)
13.09
6.81
3.17
4.9
36.98
tcp\_ip\_connection\_cost\_to\_loca (microsec)
68.41
59.89
50.18
78.3
998.0
tcp\_latency\_using\_localhost (microsec)
1.06
0.75
0.54
0.81
2.65
.. rubric:: Dhrystone
   :name: dhrystone

**Dhrystone Benchmark**
ARM Benchmarks / host Dhrystone\_S\_PERF\_HostSide
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
dhrystone\_per\_mhz (DMIPS/MHz)
2.2
2.6
3.6
3.6
1.6
dhrystone\_per\_second (DhrystoneP)
3846153.8
4545454.5
9523810.0
6451613.0
645161.3
| 

.. rubric:: Whestone
   :name: whestone

**Whestone Benchmark**
ARM Benchmarks / host Whetstone\_S\_PERF\_HostSide
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
whetstone (MIPS)
555.6
2000.0
3333.3
2500.0
31.1
| 

.. rubric:: Linpack
   :name: linpack

**Linpack Benchmark**
ARM Benchmarks / host Linpack\_S\_PERF\_HostSide
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
linpack (Kflops)
57222.0
228889.0
686667.0
686667.0
7228.0
| 

.. rubric:: NBench
   :name: nbench

**NBench Benchmarks**
ARM Benchmarks / host NBench\_S\_PERF\_HostSide
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
assignment (Iterations)
7.89
7.89
16.81
11.24
0.92
fourier (Iterations)
1806.1
7366.1
12784.0
8612.4
124.61
fp\_emulation (Iterations)
68.34
67.79
154.09
102.65
16.37
huffman (Iterations)
789.13
907.25
1421.5
946.21
220.73
idea (Iterations)
1535.0
1702.3
4362.3
2912.4
459.63
lu\_decomposition (Iterations)
74.58
336.81
828.75
552.6
5.75
neural\_net (Iterations)
2.02
8.5
22.42
14.7
0.18
numeric\_sort (Iterations)
463.46
578.52
769.7
501.9
84.05
string\_sort (Iterations)
64.23
62.09
136.39
91.17
5.97
| 

.. rubric:: Stream
   :name: stream

**Stream**
ARM Benchmarks / host Stream\_1\_core\_S\_PERF\_Hostside
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
add (MB/s)
502.2
395.2
3593.8
2089.6
copy (MB/s)
436.3
429.1
3795.9
2146.6
scale (MB/s)
579.9
651.3
4341.6
2115.6
triad (MB/s)
479.6
352.0
3384.8
2028.5
.. rubric:: **Interrupt Latency Measurement**
   :name: interrupt-latency-measurement

The following table gives interrupt latency measurements taken across
1001 measurement samples.

+--------------------------------------------+------------------------------------------------------------------+----------------------------------------------------------------------------------------------------------------+
| **Interrupt Latency (in micro seconds)**   | **Number of samples (under 0% cpu load) (1001 total samples)**   | **Number of samples (under 100% cpu load using hackbench ``hackbench -P -l -1 -g 10``) (501 total samples)**   |
+============================================+==================================================================+================================================================================================================+
| 10                                         | 25                                                               | 0                                                                                                              |
+--------------------------------------------+------------------------------------------------------------------+----------------------------------------------------------------------------------------------------------------+
| 11                                         | 265                                                              | 25                                                                                                             |
+--------------------------------------------+------------------------------------------------------------------+----------------------------------------------------------------------------------------------------------------+
| 12                                         | 531                                                              | 249                                                                                                            |
+--------------------------------------------+------------------------------------------------------------------+----------------------------------------------------------------------------------------------------------------+
| 13                                         | 167                                                              | 203                                                                                                            |
+--------------------------------------------+------------------------------------------------------------------+----------------------------------------------------------------------------------------------------------------+
| 14                                         | 11                                                               | 24                                                                                                             |
+--------------------------------------------+------------------------------------------------------------------+----------------------------------------------------------------------------------------------------------------+
| 15                                         | 2                                                                | 0                                                                                                              |
+--------------------------------------------+------------------------------------------------------------------+----------------------------------------------------------------------------------------------------------------+

Table:  **Interrupt Latency Measurement**

| 

.. rubric:: **Boot-time Measurement**
   :name: boot-time-measurement

.. rubric:: Boot media: MMCSD
   :name: boot-media-mmcsd

'
Boot Configuration
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
**boot time (sec)**
**boot time (sec)**
**boot time (sec)**
**boot time (sec)**
**boot time (sec)**
Kernel boot time test when bootloader, kernel and sdk-rootfs are in
mmc-sd
25.27 (min 25.1, max 25.55)
23.98 (min 23.6, max 24.31)
15.49 (min 14.54, max 17.2)
23.35 (min 23.06, max 23.83)
69.96 (min 52.1, max 74.71)
Kernel boot time test when init is /bin/sh and bootloader, kernel and
sdk-rootfs are in mmc-sd
5.77
6.31 (min 6.28, max 6.32)
5.93 (min 5.67, max 6.1)
8.07 (min 8.02, max 8.09)
9.93 (min 9.92, max 9.98)
.. rubric:: ALSA SoC Audio Driver
   :name: alsa-soc-audio-driver

#. Access type - RW\_INTERLEAVED
#. Channels - 2
#. Format - S16\_LE
#. Period size - 64

| 

**Audio Capture**
Sampling Rate (Hz)
**2017.05**
am335x-evm
am437x-evm
am57xx-evm
k2g-evm
omapl138-lcdk
**Throughput (bits/sec)**
**CPU Load (%)**
**Throughput (bits/sec)**
**CPU Load (%)**
**Throughput (bits/sec)**
**CPU Load (%)**
**Throughput (bits/sec)**
**CPU Load (%)**
**Throughput (bits/sec)**
**CPU Load (%)**
8000
255998.0
3.66
255996.0
0.2
255981.0
0.12
256006.0
1.96
11025
352793.0
2.18
352789.0
0.44
352790.0
0.08
352797.0
0.38
352804.0
2.25
16000
511990.0
1.24
511981.0
0.15
511943.0
0.1
512012.0
2.55
22050
705595.0
3.18
705559.0
0.84
705579.0
0.17
705595.0
0.46
705601.0
3.9
24000
705578.0
3.28
705559.0
0.68
705579.0
0.13
705601.0
3.2
32000
1023961.0
1.23
1023923.0
0.23
1023811.0
0.24
1024040.0
4.83
44100
1411139.0
5.13
1411034.0
0.86
1411159.0
0.25
1411189.0
0.86
1411200.0
5.82
48000
1535909.0
1.75
1535827.0
1.11
1535605.0
0.28
1536083.0
6.2
88200
2821951.0
9.2
2821740.0
1.5
2822316.0
0.46
2822375.0
1.47
2822382.0
12.35
96000
3071609.0
2.13
3071311.0
0.15
3070535.0
0.66
3072305.0
11.56
| 

**Audio Playback**
Sampling Rate (Hz)
**2017.05**
am335x-evm
am437x-evm
am57xx-evm
k2g-evm
omapl138-lcdk
**Throughput (bits/sec)**
**CPU Load (%)**
**Throughput (bits/sec)**
**CPU Load (%)**
**Throughput (bits/sec)**
**CPU Load (%)**
**Throughput (bits/sec)**
**CPU Load (%)**
**Throughput (bits/sec)**
**CPU Load (%)**
8000
256103.0
1.18
256100.0
0.35
256087.0
0.07
256107.0
1.92
11025
352942.0
2.1
352935.0
0.43
352935.0
0.07
352942.0
0.22
352947.0
2.22
16000
512206.0
1.18
512195.0
0.24
512191.0
0.11
512213.0
3.04
22050
705883.0
3.05
705860.0
0.69
705870.0
0.17
705884.0
0.43
705898.0
3.82
24000
705883.0
2.94
705860.0
0.54
705870.0
0.13
705898.0
3.1
32000
1024409.0
3.55
1024374.0
0.2
1024255.0
0.15
1024442.0
5.12
44100
1411762.0
4.81
1411678.0
0.93
1411740.0
0.23
1411766.0
0.68
1411826.0
5.47
48000
1536611.0
1.29
1536537.0
0.19
1536287.0
0.3
1536687.0
5.31
88200
2823511.0
7.74
2823203.0
1.73
2823477.0
0.39
2823530.0
1.3
2731522.0
10.56
96000
3073207.0
2.4
3072923.0
4.73
3071999.0
0.44
3073497.0
11.92
| 

.. rubric:: Sensor Capture
   :name: sensor-capture

Capture video frames (MMAP buffers) with v4l2c-ctl and record the
reported fps

**Sensor Capture**
Resolution
Format
**2017.05**
am437x-evm
am57xx-evm
**Fps**
**Sensor**
**Fps**
**Sensor**
1280x800
nv12
1280x800
rgb4
1600x1200
ba81
14.56 (min 14.56, max 14.57)
ov2659
1600x1200
yuyv
14.57 (min 14.56, max 14.7)
ov2659
160x128
nv12
40.88 (min 40.79, max 41.0)
mt9t111
160x128
rgb4
40.88 (min 40.79, max 41.0)
mt9t111
2048x1536
nv12
6.63 (min 6.14, max 6.68)
mt9t111
2048x1536
rgb4
6.63 (min 6.14, max 6.68)
mt9t111
320x240
ba81
43.78 (min 43.7, max 44.0)
ov2659
320x240
nv12
320x240
rgb4
320x240
yuyv
43.78 (min 43.7, max 44.0)
ov2659
| 

.. rubric:: Display Driver
   :name: display-driver

**Display performance (LCD)**
Mode
**2017.05**
am335x-evm
am437x-evm
am57xx-evm
k2g-evm
**Fps**
**Fps**
**Fps**
**Fps**
1920x1200@60
480x272@60
59.94 (min 59.93, max 59.95)
800x480@60
59.52 (min 59.51, max 59.54)
59.52 (min 59.46, max 59.59)
800x480@62
61.81 (min 60.01, max 61.9)
| 

**Display performance (HDMI)**
Mode
**2017.05**
am335x-evm
am437x-evm
am57xx-evm
k2g-evm
**Fps**
**Fps**
**Fps**
**Fps**
1024x576@60
59.95 (min 58.98, max 60.0)
59.85 (min 58.98, max 59.98)
60.01 (min 60.0, max 60.01)
1024x768@60
60.0 (min 59.94, max 60.07)
1024x768@70
1024x768@75
75.03 (min 74.97, max 75.09)
1152x864@75
75.0 (min 74.98, max 75.02)
1280x1024@60
60.02 (min 60.0, max 60.04)
1280x1024@75
1280x720@60
59.95 (min 59.0, max 60.06)
60.0 (min 59.93, max 60.07)
60.0 (min 59.99, max 60.01)
60.0
1280x768@60
59.87 (min 59.86, max 59.88)
1280x768@75
1280x800@60
1280x800@75
74.93 (min 74.54, max 75.35)
1280x960@60
1360x768@60
59.8 (min 59.43, max 60.16)
1400x1050@60
50.67 (min 39.55, max 59.6)
1400x1050@75
74.87 (min 74.47, max 75.25)
1440x900@60
59.89 (min 59.52, max 60.24)
1440x900@75
1600x1200@60
1600x1200@65
65.0 (min 64.92, max 65.08)
1600x900@60
60.0 (min 59.78, max 60.22)
1680x1050@60
59.95 (min 59.94, max 59.97)
1680x945@60
1920x1080@60
2048x1152@60
60.0 (min 59.98, max 60.02)
640x480@60
59.95 (min 59.01, max 60.04)
60.0 (min 59.61, max 60.4)
640x480@73
72.73 (min 69.34, max 72.87)
68.89 (min 53.93, max 72.81)
640x480@75
74.88 (min 72.58, max 75.16)
75.0 (min 74.92, max 75.08)
75.0 (min 74.98, max 75.02)
720x400@70
69.98 (min 67.82, max 70.09)
800x600@56
56.2 (min 55.33, max 56.26)
56.25 (min 56.24, max 56.26)
56.25 (min 56.23, max 56.27)
800x600@60
60.28 (min 59.33, max 60.32)
57.16 (min 50.59, max 60.86)
800x600@72
72.12 (min 70.68, max 72.53)
72.19 (min 72.18, max 72.2)
72.19 (min 72.17, max 72.21)
72.19 (min 72.18, max 72.2)
800x600@75
74.85 (min 71.43, max 75.01)
70.44 (min 54.22, max 75.92)
75.0 (min 74.99, max 75.01)
832x624@75
74.48 (min 72.15, max 74.67)
74.55 (min 74.54, max 74.56)
74.55 (min 74.02, max 75.09)
74.57 (min 74.56, max 74.58)
848x480@60
59.98 (min 59.02, max 60.01)
57.28 (min 45.0, max 60.03)
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
am57xx-evm
**Test Number**
**Fps**
GLB25\_EgyptTestC24Z16FixedTime test
2500005.0
38.79 (min 21.56, max 59.61)
GLB25\_EgyptTestC24Z16\_ETC1 test
2501001.0
45.45 (min 20.99, max 60.09)
GLB25\_EgyptTestC24Z16\_ETC1to565 test
2501401.0
45.32 (min 20.43, max 60.03)
GLB25\_EgyptTestC24Z16\_PVRTC4 test
2501101.0
45.38 (min 21.07, max 60.14)
GLB25\_EgyptTestC24Z24MS4 test
2500003.0
44.07 (min 20.16, max 60.17)
GLB25\_EgyptTestStandard\_inherited test
2000000.0
59.53 (min 59.25, max 59.92)
.. rubric:: Vertex Throughput
   :name: vertex-throughput

**GLBenchmark 2.5 Vertex Throughput**
Benchmark
**2017.05**
am57xx-evm
**Test Number**
**Rate (triangles/sec)**
GLB25\_TriangleTexFragmentLitTestC24Z16 test
2500511.0
32952526.0
GLB25\_TriangleTexTestC24Z16 test
2500301.0
105561992.0
GLB25\_TriangleTexVertexLitTestC24Z16 test
2500411.0
39968508.0
.. rubric:: Pixel Throughput
   :name: pixel-throughput

**GLBenchmark 2.5 Pixel Throughput**
Benchmark
**2017.05**
am57xx-evm
**Test Number**
**Rate (texel/sec)**
**Fps**
GLB25\_FillTestC24Z16 test
2500101.0
1435972864.0
58.34 (min 51.59, max 59.53)
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
am57xx-evm
**Fps**
**IVA Freq (MHz)**
**IPU Freq (MHz)**
1080i
60.6
532.0
1080p
59.5
532.0
720p
59.94
532.0
720x480
60.0
532.0
800x480
60.0
532.0
| 

.. rubric:: MPEG4
   :name: mpeg4

**GStreamer MPEG4 in 3GP Container Decode Performance**
Resolution
**2017.05**
am57xx-evm
**Fps**
**IVA Freq (MHz)**
**IPU Freq (MHz)**
CIF
60.0
532.0
QVGA
60.0
532.0
VGA
63.75
532.0
| 

.. rubric:: MPEG2
   :name: mpeg2

**GStreamer MPEG2 in MP4 Container Decode Performance**
Resolution
**2017.05**
am57xx-evm
**Fps**
**IVA Freq (MHz)**
**IPU Freq (MHz)**
1080p
532.0
720p
59.94
532.0
| 

| 

.. rubric:: Ethernet Driver
   :name: ethernet-driver

.. rubric:: TCP Throughput
   :name: tcp-throughput

**Ethernet performance table**
TCP Window Size(Kbytes)
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
**Bandwidth (without interrupt pacing, in Mbits/sec)**
**CPU Load (without interrupt pacing, in %)**
**Bandwidth (with interrupt pacing, in Mbits/sec)**
**CPU Load (with interrupt pacing, in %)**
**Bandwidth (without interrupt pacing, in Mbits/sec)**
**CPU Load (without interrupt pacing, in %)**
**Bandwidth (with interrupt pacing, in Mbits/sec)**
**CPU Load (with interrupt pacing, in %)**
**Bandwidth (without interrupt pacing, in Mbits/sec)**
**CPU Load (without interrupt pacing, in %)**
**Bandwidth (with interrupt pacing, in Mbits/sec)**
**CPU Load (with interrupt pacing, in %)**
**Bandwidth (without interrupt pacing, in Mbits/sec)**
**CPU Load (without interrupt pacing, in %)**
**Bandwidth (with interrupt pacing, in Mbits/sec)**
**CPU Load (with interrupt pacing, in %)**
**Bandwidth (without interrupt pacing, in Mbits/sec)**
**CPU Load (without interrupt pacing, in %)**
**Bandwidth (with interrupt pacing, in Mbits/sec)**
**CPU Load (with interrupt pacing, in %)**
8
239.2
54.24
240.8
229.6
365.6
119.68
630.4
-
-
4.48
-
-
16
255.2
298.4
267.2
292.8
448.8
585.6
574.4
-
-
30.56
-
-
32
45.6
324.8
57.12
316.0
144.56
891.2
582.4
-
-
32.08
-
-
64
334.24
26.24
328.0
347.2
1076.0
48.0
582.4
-
2.08
-
-
128
54.88
378.56
61.44
367.12
151.68
1073.6
646.4
-
-
52.16
-
-
256
330.4
82.16
343.2
368.96
1108.8
164.08
627.2
-
-
9.92
-
-
.. rubric:: UDP Throughput
   :name: udp-throughput

'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_64B\_egress
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
packet\_size (bytes)
64.0
64.0
64.0
64.0
64.0
packets\_per\_second (kpps)
41.0
56.0
95.0
46.0
1.0
throughput (Mbits/s)
21.6
29.0
49.1
24.8
1.6
'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_128B\_egress
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
packet\_size (bytes)
128.0
128.0
128.0
128.0
128.0
packets\_per\_second (kpps)
41.0
55.0
91.0
47.0
2.0
throughput (Mbits/s)
42.1
57.6
94.1
49.1
3.3
'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_256B\_egress
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
packet\_size (bytes)
256.0
256.0
256.0
256.0
256.0
packets\_per\_second (kpps)
40.0
55.0
92.0
47.0
2.0
throughput (Mbits/s)
83.1
113.0
189.7
97.2
6.5
'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_512B\_egress
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
packet\_size (bytes)
512.0
512.0
512.0
512.0
512.0
packets\_per\_second (kpps)
42.0
51.0
90.0
45.0
2.0
throughput (Mbits/s)
175.2
210.0
372.0
186.6
12.8
'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_1024B\_egress
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
packet\_size (bytes)
1024.0
1024.0
1024.0
1024.0
1024.0
packets\_per\_second (kpps)
38.0
47.0
84.0
45.0
3.0
throughput (Mbits/s)
312.0
390.0
695.0
369.0
25.0
'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_1470B\_egress
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
packet\_size (bytes)
1470.0
1470.0
1470.0
1470.0
1470.0
packets\_per\_second (kpps)
40.0
44.0
76.0
26.0
2.0
throughput (Mbits/s)
476.0
525.0
904.0
312.0
34.5
'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_128B\_ingress
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
packet\_size (bytes)
128.0
128.0
128.0
128.0
128.0
packets\_per\_second (kpps)
25.0
37.0
87.0
79.0
0.0
throughput (Mbits/s)
26.9
38.0
90.8
81.9
0.5
| 

'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_256B\_ingress
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
packet\_size (bytes)
256.0
256.0
256.0
256.0
256.0
packets\_per\_second (kpps)
19.0
40.0
33.0
66.0
3.0
throughput (Mbits/s)
39.7
83.1
68.8
136.1
7.5
'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_512B\_ingress
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
packet\_size (bytes)
512.0
512.0
512.0
512.0
512.0
packets\_per\_second (kpps)
18.0
37.0
45.0
21.0
3.0
throughput (Mbits/s)
76.8
153.8
186.0
88.2
15.0
'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_1024B\_ingress
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
packet\_size (bytes)
1024.0
1024.0
1024.0
1024.0
1024.0
packets\_per\_second (kpps)
18.0
24.0
80.0
50.0
3.0
throughput (Mbits/s)
151.8
202.8
660.0
410.0
31.0
'
Ethernet\_\_eth0\_1G Ethernet\_performance\_UDP\_1470B\_ingress
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
packet\_size (bytes)
1470.0
1470.0
1470.0
1470.0
1470.0
packets\_per\_second (kpps)
17.0
19.0
62.0
39.0
3.0
throughput (Mbits/s)
204.0
231.6
740.0
467.0
42.4
| 

-  iperf version 2.0.5
-  For receive performance, on DUT, invoke iperf in server mode.

::

    iperf -s -u

-  For transmit performance, on DUT, invoke iperf in client mode.

::

    iperf -c <server ip> -b <bandwidth limit> -f M -t 60

| 

.. rubric:: PCIe Driver
   :name: pcie-driver

.. rubric:: PCIe-ETH
   :name: pcie-eth

'
TCP Window Size(Kbytes)
**2017.05**
k2g-evm
**Bandwidth (in Mbits/sec)**
8
572.08
16
719.2
32
956.0
64
1216.0
128
1318.4
256
1341.6
| 

| 

-  k2g: Measured with Broadcom Corporation NetXtreme BCM5721 Gigabit
   Ethernet PCI Express [14e4:1659] (rev 21)
-  LnkSta: Speed 2.5GT/s, Width x1

.. rubric:: NAND Driver
   :name: nand-driver

Please refer `MTD Test
Setup </index.php/Sitara_PSP_Test_Setup#Memory_Technology_Device_.28MTD_-_NAND.2C_NOR.2C_OneNAND_Flash.29>`__
before proceeding.

.. rubric:: AM335X-EVM
   :name: am335x-evm

'
Buffer size (bytes)
**2017.05**
am335x-evm
**Write UBIFS Throughput (Mbytes/sec)**
**Write UBIFS CPU Load (%)**
**Read UBIFS Throughput (Mbytes/sec)**
**Read UBIFS CPU Load (%)**
102400
4.31
100.0
7.33
100.0
262144
4.44
100.0
7.31
100.0
524288
4.47
100.0
7.41
100.0
1048576
4.51
100.0
7.41
100.0
5242880
4.53
100.0
7.46
100.0
.. rubric:: AM43XX-GPEVM
   :name: am43xx-gpevm

'
Buffer size (bytes)
**2017.05**
am43xx-gpevm
**Write UBIFS Throughput (Mbytes/sec)**
**Write UBIFS CPU Load (%)**
**Read UBIFS Throughput (Mbytes/sec)**
**Read UBIFS CPU Load (%)**
102400
7.95
100.0
12.64
100.0
262144
7.96
100.0
12.65
100.0
524288
7.98
100.0
12.69
100.0
1048576
7.96
100.0
12.68
100.0
5242880
7.96
100.0
12.67
100.0
.. rubric:: OMAPL138-LCDK
   :name: omapl138-lcdk

'
Buffer size (bytes)
**2017.05**
omapl138-lcdk
**Write UBIFS Throughput (Mbytes/sec)**
**Write UBIFS CPU Load (%)**
**Read UBIFS Throughput (Mbytes/sec)**
**Read UBIFS CPU Load (%)**
102400
1.37
100.0
1.91
100.0
262144
1.47
100.0
1.98
100.0
524288
1.48
100.0
1.98
100.0
1048576
1.49
100.0
1.98
100.0
5242880
1.48
100.0
1.96
100.0
.. rubric:: QSPI Flash Driver
   :name: qspi-flash-driver

Test setup is available
`here </index.php/Sitara_PSP_Test_Setup#Memory_Technology_Device_.28MTD_-_NAND.2C_NOR.2C_OneNAND_Flash.29>`__.

.. rubric:: K2G-EVM
   :name: k2g-evm

'
Buffer size (bytes)
**2017.05**
k2g-evm
**Write UBIFS Throughput (Mbytes/sec)**
**Write UBIFS CPU Load (%)**
**Read UBIFS Throughput (Mbytes/sec)**
**Read UBIFS CPU Load (%)**
102400
0.56
99.73
5.3
100.0
262144
0.57
99.73
5.24
100.0
524288
0.57
99.73
5.23
100.0
1048576
0.57
99.73
5.22
100.0
.. rubric:: SPI Flash Driver
   :name: spi-flash-driver

.. rubric:: K2G-EVM
   :name: k2g-evm-1

'
Buffer size (bytes)
**2017.05**
k2g-evm
**Write UBIFS Throughput (Mbytes/sec)**
**Write UBIFS CPU Load (%)**
**Read UBIFS Throughput (Mbytes/sec)**
**Read UBIFS CPU Load (%)**
102400
0.14
51.14
0.22
7.11
262144
0.14
53.34
0.22
7.5
524288
0.14
51.56
0.22
9.65
1048576
0.14
51.29
0.22
8.11
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

| 

.. rubric:: AM43XX-GPEVM
   :name: am43xx-gpevm-1

'
Buffer size (bytes)
**2017.05**
am43xx-gpevm
**Write VFAT Throughput (Mbytes/sec)**
**Write VFAT CPU Load (%)**
**Read VFAT Throughput (Mbytes/sec)**
**Read VFAT CPU Load (%)**
102400
5.85
8.09
22.99
21.02
262144
5.83
7.58
22.98
22.86
524288
5.83
7.78
23.0
20.76
1048576
6.16
8.24
23.58
22.7
5242880
6.17
8.64
23.55
22.22
| 

'
Buffer size (bytes)
**2017.05**
am43xx-gpevm
**Write EXT4 Throughput (Mbytes/sec)**
**Write EXT4 CPU Load (%)**
**Read EXT4 Throughput (Mbytes/sec)**
**Read EXT4 CPU Load (%)**
102400
6.1
5.96
26.26
22.67
262144
6.11
6.15
26.23
22.14
524288
6.1
5.84
26.21
25.86
1048576
5.97
6.0
26.24
24.82
5242880
6.14
6.0
26.21
22.88
| 

'
Buffer size (bytes)
**2017.05**
am43xx-gpevm
**Write EXT2 Throughput (Mbytes/sec)**
**Write EXT2 CPU Load (%)**
**Read EXT2 Throughput (Mbytes/sec)**
**Read EXT2 CPU Load (%)**
102400
5.57
6.31
25.42
22.0
262144
5.58
6.78
25.64
21.3
524288
5.6
6.49
25.62
24.63
1048576
5.58
6.53
25.64
23.28
5242880
5.46
6.08
25.63
24.88
.. rubric:: AM57XX-EVM
   :name: am57xx-evm

'
Buffer size (bytes)
**2017.05**
am57xx-evm
**Write VFAT Throughput (Mbytes/sec)**
**Write VFAT CPU Load (%)**
**Read VFAT Throughput (Mbytes/sec)**
**Read VFAT CPU Load (%)**
102400
11.76
4.61
63.58
12.24
262144
11.77
4.07
64.11
8.0
524288
11.75
4.34
63.77
7.14
1048576
11.75
3.74
63.14
7.95
5242880
11.73
4.11
63.05
7.93
| 

'
Buffer size (bytes)
**2017.05**
am57xx-evm
**Write EXT4 Throughput (Mbytes/sec)**
**Write EXT4 CPU Load (%)**
**Read EXT4 Throughput (Mbytes/sec)**
**Read EXT4 CPU Load (%)**
102400
11.89
2.74
61.52
5.92
262144
11.81
3.11
67.8
6.27
524288
12.03
3.57
61.51
5.99
1048576
11.87
2.91
61.49
6.53
5242880
11.78
3.28
67.69
8.14
| 

'
Buffer size (bytes)
**2017.05**
am57xx-evm
**Write EXT2 Throughput (Mbytes/sec)**
**Write EXT2 CPU Load (%)**
**Read EXT2 Throughput (Mbytes/sec)**
**Read EXT2 CPU Load (%)**
102400
12.18
4.21
67.47
7.19
262144
12.24
4.22
67.49
6.86
524288
12.13
4.52
67.63
8.74
1048576
12.12
3.8
67.28
7.74
5242880
12.15
4.19
66.98
8.95
.. rubric:: K2G-EVM
   :name: k2g-evm-2

'
Buffer size (bytes)
**2017.05**
k2g-evm
**Write VFAT Throughput (Mbytes/sec)**
**Write VFAT CPU Load (%)**
**Read VFAT Throughput (Mbytes/sec)**
**Read VFAT CPU Load (%)**
102400
20.2
24.71
38.53
16.97
262144
20.17
24.32
38.58
15.99
524288
20.3
23.93
38.6
15.04
1048576
20.3
23.78
38.56
15.04
5242880
20.34
24.42
38.53
15.41
| 

'
Buffer size (bytes)
**2017.05**
k2g-evm
**Write EXT4 Throughput (Mbytes/sec)**
**Write EXT4 CPU Load (%)**
**Read EXT4 Throughput (Mbytes/sec)**
**Read EXT4 CPU Load (%)**
102400
30.27
25.79
39.42
11.02
262144
30.39
25.65
38.78
13.69
524288
30.37
24.49
38.76
12.69
1048576
30.57
27.14
39.44
14.56
5242880
27.27
24.04
39.42
18.38
'
Buffer size (bytes)
**2017.05**
k2g-evm
**Write EXT2 Throughput (Mbytes/sec)**
**Write EXT2 CPU Load (%)**
**Read EXT2 Throughput (Mbytes/sec)**
**Read EXT2 CPU Load (%)**
102400
21.06
22.95
39.07
10.32
262144
21.03
22.95
39.19
8.23
524288
21.12
23.54
39.2
9.68
1048576
21.26
21.69
39.08
8.54
5242880
21.09
22.65
39.01
14.23
.. rubric:: SATA Driver
   :name: sata-driver

.. rubric:: AM57XX-EVM
   :name: am57xx-evm-1

.. rubric:: SATA
   :name: sata

'
Buffer size (bytes)
**2017.05**
am57xx-evm
**Write VFAT Throughput (Mbytes/sec)**
**Write VFAT CPU Load (%)**
**Read VFAT Throughput (Mbytes/sec)**
**Read VFAT CPU Load (%)**
102400
97.14
31.44
135.64
11.89
262144
96.86
28.66
135.9
12.12
524288
95.79
28.58
135.95
11.81
1048576
97.43
28.73
135.97
12.91
5242880
97.17
29.21
136.0
12.8
| 

'
Buffer size (bytes)
**2017.05**
am57xx-evm
**Write EXT2 Throughput (Mbytes/sec)**
**Write EXT2 CPU Load (%)**
**Read EXT2 Throughput (Mbytes/sec)**
**Read EXT2 CPU Load (%)**
102400
106.85
25.38
134.68
11.83
262144
106.36
25.67
134.39
11.96
524288
108.84
27.78
134.68
12.48
1048576
104.5
27.89
134.68
12.02
5242880
108.06
28.25
134.68
12.62
'
Buffer size (bytes)
**2017.05**
am57xx-evm
**Write EXT4 Throughput (Mbytes/sec)**
**Write EXT4 CPU Load (%)**
**Read EXT4 Throughput (Mbytes/sec)**
**Read EXT4 CPU Load (%)**
102400
118.67
19.82
134.6
11.52
262144
120.44
18.27
133.68
10.5
524288
113.84
11.26
128.24
10.94
1048576
117.62
12.72
128.06
11.11
5242880
113.29
11.91
126.68
12.22
| 

| 

| 

-  Filesize used is : 1G
-  SATA II Harddisk used is: Seagate ST3500514NS 500G

.. rubric:: mSATA
   :name: msata

'
Buffer size (bytes)
**2017.05**
am57xx-evm
**Write EXT4 Throughput (Mbytes/sec)**
**Write EXT4 CPU Load (%)**
**Read EXT4 Throughput (Mbytes/sec)**
**Read EXT4 CPU Load (%)**
102400
63.8
5.67
210.2
17.79
262144
63.52
5.24
213.06
17.23
524288
63.17
5.62
212.33
18.55
1048576
68.22
5.23
214.66
19.74
5242880
67.63
5.31
221.78
21.06
| 

'
Buffer size (bytes)
**2017.05**
am57xx-evm
**Write VFAT Throughput (Mbytes/sec)**
**Write VFAT CPU Load (%)**
**Read VFAT Throughput (Mbytes/sec)**
**Read VFAT CPU Load (%)**
102400
61.54
20.22
219.1
19.53
262144
60.29
19.71
219.14
19.8
524288
58.08
18.38
219.23
22.44
1048576
57.64
18.57
218.5
22.19
5242880
58.14
18.82
218.54
21.62
'
Buffer size (bytes)
**2017.05**
am57xx-evm
**Write EXT2 Throughput (Mbytes/sec)**
**Write EXT2 CPU Load (%)**
**Read EXT2 Throughput (Mbytes/sec)**
**Read EXT2 CPU Load (%)**
102400
63.32
9.24
224.26
19.21
262144
63.6
7.87
225.12
19.68
524288
71.51
8.36
224.65
19.11
1048576
64.32
8.65
226.41
21.21
5242880
63.76
8.85
226.23
20.58
| 

| 

-  Filesize used is : 1G
-  MSATA Harddisk used is: SMS200S3/30G Kingston mSATA SSD drive

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

.. rubric:: AM335X-EVM
   :name: am335x-evm-1

'
Buffer size (bytes)
**2017.05**
am335x-evm
**Write EXT4 Throughput (Mbytes/sec)**
**Write EXT4 CPU Load (%)**
**Read EXT4 Throughput (Mbytes/sec)**
**Read EXT4 CPU Load (%)**
102400
7.77
9.86
21.24
22.04
262144
8.37
10.3
21.25
21.67
524288
8.53
10.04
21.24
22.13
1048576
8.54
10.56
21.25
21.17
5242880
8.17
10.25
21.25
20.68
| 

'
Buffer size (bytes)
**2017.05**
am335x-evm
**Write VFAT Throughput (Mbytes/sec)**
**Write VFAT CPU Load (%)**
**Read VFAT Throughput (Mbytes/sec)**
**Read VFAT CPU Load (%)**
102400
8.93
16.51
20.52
22.38
262144
9.23
15.66
20.45
23.59
524288
8.62
15.23
20.48
24.4
1048576
8.94
14.88
20.51
23.9
5242880
8.97
14.46
20.47
24.85
| 

'
Buffer size (bytes)
**2017.05**
am335x-evm
**Write EXT2 Throughput (Mbytes/sec)**
**Write EXT2 CPU Load (%)**
**Read EXT2 Throughput (Mbytes/sec)**
**Read EXT2 CPU Load (%)**
102400
8.97
13.02
21.13
20.96
262144
8.48
12.75
21.12
21.9
524288
9.33
14.36
21.12
23.33
1048576
9.33
13.36
21.12
22.06
5242880
9.36
13.4
21.12
21.83
| 

| 

The performance numbers were captured using the following:

-  SanDisk 8GB MicroSDHC Class 10 Memory Card
-  Partition was mounted with async option

| 

.. rubric:: AM43XX-GPEVM
   :name: am43xx-gpevm-2

'
Buffer size (bytes)
**2017.05**
am43xx-gpevm
**Write EXT4 Throughput (Mbytes/sec)**
**Write EXT4 CPU Load (%)**
**Read EXT4 Throughput (Mbytes/sec)**
**Read EXT4 CPU Load (%)**
102400
6.68
7.08
21.79
19.83
262144
7.46
7.59
21.79
18.53
524288
7.77
7.82
21.78
22.18
1048576
7.68
8.06
21.79
17.06
5242880
7.67
8.05
21.79
16.88
| 

'
Buffer size (bytes)
**2017.05**
am43xx-gpevm
**Write EXT2 Throughput (Mbytes/sec)**
**Write EXT2 CPU Load (%)**
**Read EXT2 Throughput (Mbytes/sec)**
**Read EXT2 CPU Load (%)**
102400
9.91
12.03
21.71
18.66
262144
9.56
11.27
21.66
20.12
524288
9.57
10.95
21.69
20.53
1048576
8.57
10.47
21.32
41.1
5242880
9.65
10.77
21.7
19.67
'
Buffer size (bytes)
**2017.05**
am43xx-gpevm
**Write VFAT Throughput (Mbytes/sec)**
**Write VFAT CPU Load (%)**
**Read VFAT Throughput (Mbytes/sec)**
**Read VFAT CPU Load (%)**
102400
8.56
12.01
21.13
19.18
262144
8.22
11.01
21.12
19.22
524288
9.01
11.61
21.13
21.04
1048576
8.67
81.46
21.05
20.53
5242880
8.94
12.45
21.11
19.76
| 

| 

The performance numbers were captured using the following:

-  Sandisk Ultra 8GB Micro SDHC Flash Card Class10
-  Partition was mounted with async option

| 

.. rubric:: AM57XX-EVM
   :name: am57xx-evm-2

'
Buffer size (bytes)
**2017.05**
am57xx-evm
**Write EXT4 Throughput (Mbytes/sec)**
**Write EXT4 CPU Load (%)**
**Read EXT4 Throughput (Mbytes/sec)**
**Read EXT4 CPU Load (%)**
102400
9.06
2.17
39.46
3.81
262144
9.13
2.11
39.51
3.98
524288
10.33
3.52
39.3
3.25
1048576
10.45
3.05
39.31
3.98
5242880
10.08
3.15
39.52
4.02
| 

'
Buffer size (bytes)
**2017.05**
am57xx-evm
**Write EXT2 Throughput (Mbytes/sec)**
**Write EXT2 CPU Load (%)**
**Read EXT2 Throughput (Mbytes/sec)**
**Read EXT2 CPU Load (%)**
102400
12.87
4.33
38.92
5.19
262144
12.94
4.1
38.96
1.35
524288
13.01
3.88
38.97
1.92
1048576
12.95
4.77
38.97
2.68
5242880
12.95
4.53
39.18
2.13
| 

'
Buffer size (bytes)
**2017.05**
am57xx-evm
**Write VFAT Throughput (Mbytes/sec)**
**Write VFAT CPU Load (%)**
**Read VFAT Throughput (Mbytes/sec)**
**Read VFAT CPU Load (%)**
102400
8.41
2.9
38.7
6.61
262144
7.03
2.4
38.99
8.32
524288
7.23
2.81
38.56
3.93
1048576
8.48
2.97
38.26
6.36
5242880
8.47
2.89
39.1
7.37
| 

The performance numbers were captured using the following:

-  Sandisk Ultra 8GB Micro SDHC Flash Card Class10
-  Partition was mounted with async option

.. rubric:: K2G-EVM
   :name: k2g-evm-3

'
Buffer size (bytes)
**2017.05**
k2g-evm
**Write EXT4 Throughput (Mbytes/sec)**
**Write EXT4 CPU Load (%)**
**Read EXT4 Throughput (Mbytes/sec)**
**Read EXT4 CPU Load (%)**
102400
6.22
5.48
21.78
6.78
262144
5.65
5.38
21.79
9.17
524288
5.66
5.04
21.79
7.4
1048576
6.58
6.15
21.76
8.98
5242880
5.66
5.19
21.79
9.9
| 

'
Buffer size (bytes)
**2017.05**
k2g-evm
**Write EXT2 Throughput (Mbytes/sec)**
**Write EXT2 CPU Load (%)**
**Read EXT2 Throughput (Mbytes/sec)**
**Read EXT2 CPU Load (%)**
102400
9.53
10.28
21.72
8.32
262144
9.61
10.38
21.65
6.57
524288
9.58
10.09
21.72
11.13
1048576
9.54
10.05
21.72
7.19
5242880
11.15
12.82
21.72
7.98
| 

'
Buffer size (bytes)
**2017.05**
k2g-evm
**Write VFAT Throughput (Mbytes/sec)**
**Write VFAT CPU Load (%)**
**Read VFAT Throughput (Mbytes/sec)**
**Read VFAT CPU Load (%)**
102400
8.1
9.91
21.39
8.88
262144
8.07
10.51
21.37
8.94
524288
7.24
9.32
21.34
8.7
1048576
8.65
10.62
21.37
9.47
5242880
8.54
10.98
21.34
8.71
| 

| 

The performance numbers were captured using the following:

-  Sandisk Ultra 8GB Micro SDHC Flash Card Class10
-  Partition was mounted with async option

.. rubric:: OMAPL138-LCDK
   :name: omapl138-lcdk-1

'
Buffer size (bytes)
**2017.05**
omapl138-lcdk
**Write EXT4 Throughput (Mbytes/sec)**
**Write EXT4 CPU Load (%)**
**Read EXT4 Throughput (Mbytes/sec)**
**Read EXT4 CPU Load (%)**
102400
6.33
76.06
14.05
58.1
262144
6.48
62.26
13.54
56.1
524288
6.43
61.31
13.48
57.03
1048576
6.57
56.33
13.98
51.93
5242880
7.13
63.08
13.8
56.28
| 

'
Buffer size (bytes)
**2017.05**
omapl138-lcdk
**Write EXT2 Throughput (Mbytes/sec)**
**Write EXT2 CPU Load (%)**
**Read EXT2 Throughput (Mbytes/sec)**
**Read EXT2 CPU Load (%)**
102400
3.65
37.69
15.93
61.42
262144
3.21
22.26
16.07
63.48
524288
3.55
24.95
16.06
62.48
1048576
3.02
20.71
16.15
54.97
5242880
3.46
22.93
16.11
58.83
| 

'
Buffer size (bytes)
**2017.05**
omapl138-lcdk
**Write VFAT Throughput (Mbytes/sec)**
**Write VFAT CPU Load (%)**
**Read VFAT Throughput (Mbytes/sec)**
**Read VFAT CPU Load (%)**
102400
3.86
53.56
15.35
68.24
262144
4.63
48.7
14.92
70.67
524288
4.6
47.35
15.43
66.67
1048576
4.88
46.28
15.68
59.44
5242880
4.83
44.87
15.41
64.64
| 

| 

| 
| The performance numbers were captured using the following:

-  Sandisk Ultra 8GB Micro SDHC Flash Card Class10
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

.. rubric:: USB Driver
   :name: usb-driver

.. rubric:: MUSB/XHCI Host controller
   :name: musbxhci-host-controller

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
captured.

| 

| 

'
USBHOST / host USBHOST\_L\_PERF\_EXT2\_0002
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
copy\_102400\_throughput (MBytes/sec)
17.70
26.27
169.90
29.35
1.22
copy\_1048576\_throughput (MBytes/sec)
17.33
25.52
159.21
29.36
1.19
copy\_5242880\_throughput (MBytes/sec)
17.22
25.68
160.84
29.17
1.08
read\_102400\_cpuload (%)
47.48
45.92
31.76
25.45
100.00
read\_102400\_throughput (MBytes/sec)
13.88
25.68
211.94
36.97
7.18
read\_1048576\_cpuload (%)
49.18
40.40
33.73
23.9
100.00
read\_1048576\_throughput (MBytes/sec)
13.88
29.14
217.71
36.98
7.77
read\_5242880\_cpuload (%)
48.98
44.15
36.78
24.26
100.00
read\_5242880\_throughput (MBytes/sec)
13.85
29.77
211.26
36.92
7.68
write\_102400\_cpuload (%)
35.41
52.10
52.29
37.62
write\_102400\_throughput (MBytes/sec)
19.98
29.16
134.96
32.35
write\_1048576\_cpuload (%)
33.33
50.42
49.33
38.49
write\_1048576\_throughput (MBytes/sec)
20.48
29.00
134.24
32.54
write\_5242880\_cpuload (%)
32.58
51.40
48.7
38.29
write\_5242880\_throughput (MBytes/sec)
20.69
29.14
132.44
32.58
'
USBHOST / host USBHOST\_L\_PERF\_VFAT\_0002
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
k2g-evm
omapl138-lcdk
copy\_102400\_throughput (MBytes/sec)
17.16
26.00
150.63
28.70
copy\_262144\_throughput (MBytes/sec)
17.09
25.48
148.30
28.61
read\_102400\_cpuload (%)
37.50
49.65
34.83
22.59
read\_102400\_throughput (MBytes/sec)
13.85
29.89
211.56
37.09
read\_262144\_cpuload (%)
38.27
47.04
34.83
24.09
read\_262144\_throughput (MBytes/sec)
13.85
29.70
211.56
36.98
write\_102400\_cpuload (%)
33.88
50.01
51.01
38.01
write\_102400\_throughput (MBytes/sec)
20.64
29.51
136.48
32.18
write\_262144\_cpuload (%)
33.88
50.28
51.01
37.5
write\_262144\_throughput (MBytes/sec)
20.26
29.13
136.48
32.77
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

.. rubric:: AM335X USB SLAVE DEVICE PERFORMANCE
   :name: am335x-usb-slave-device-performance

+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+
| **Bytes Transferred (MB)"/dev/shm/50M" file as storage device**   | **Number of files transferred**   | **Total Bytes transferred (MB)**   | **Transfer Rate (MB/sec)**   |
+===================================================================+===================================+====================================+==============================+
| 50                                                                | 1                                 | 50                                 | 17.5                         |
+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+

Table:  **AM335X USB Slave Read Performance values**

+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+
| **Bytes Transferred (MB)"/dev/shm/50M" file as storage device**   | **Number of files transferred**   | **Total Bytes transferred (MB)**   | **Transfer Rate (MB/sec)**   |
+===================================================================+===================================+====================================+==============================+
| 50                                                                | 1                                 | 50                                 | 4.0                          |
+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+

Table:  **AM335X USB Slave Write Performance values**

| 

.. rubric:: AM43XX GPEVM USB SLAVE DEVICE PERFORMANCE
   :name: am43xx-gpevm-usb-slave-device-performance

+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+
| **Bytes Transferred (MB)"/dev/shm/50M" file as storage device**   | **Number of files transferred**   | **Total Bytes transferred (MB)**   | **Transfer Rate (MB/sec)**   |
+===================================================================+===================================+====================================+==============================+
| 50                                                                | 1                                 | 50                                 | 34.6                         |
+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+

Table:  **AM43XX USB Slave Read Performance values**

+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+
| **Bytes Transferred (MB)"/dev/shm/50M" file as storage device**   | **Number of files transferred**   | **Total Bytes transferred (MB)**   | **Transfer Rate (MB/sec)**   |
+===================================================================+===================================+====================================+==============================+
| 50                                                                | 1                                 | 50                                 | 20.3                         |
+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+

Table:  **AM43XX USB Slave WritePerformance values**

| 

.. rubric:: AM57XX GPEVM USB SLAVE DEVICE PERFORMANCE
   :name: am57xx-gpevm-usb-slave-device-performance

+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+
| **Bytes Transferred (MB)"/dev/shm/50M" file as storage device**   | **Number of files transferred**   | **Total Bytes transferred (MB)**   | **Transfer Rate (MB/sec)**   |
+===================================================================+===================================+====================================+==============================+
| 50                                                                | 1                                 | 50                                 | 30.6                         |
+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+

Table:  **AM57XX USB Slave Read Performance values**

+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+
| **Bytes Transferred (MB)"/dev/shm/50M" file as storage device**   | **Number of files transferred**   | **Total Bytes transferred (MB)**   | **Transfer Rate (MB/sec)**   |
+===================================================================+===================================+====================================+==============================+
| 50                                                                | 1                                 | 50                                 | 21.7                         |
+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+

Table:  **AM57XX USB Slave WritePerformance values**

| 

.. rubric:: OMAPL138-LCDK USB SLAVE DEVICE PERFORMANCE
   :name: omapl138-lcdk-usb-slave-device-performance

+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+
| **Bytes Transferred (MB)"/dev/shm/50M" file as storage device**   | **Number of files transferred**   | **Total Bytes transferred (MB)**   | **Transfer Rate (MB/sec)**   |
+===================================================================+===================================+====================================+==============================+
| 50                                                                | 1                                 | 50                                 | 10.1                         |
+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+

Table:  **OMAPL138-LCDK USB Slave Read Performance values**

+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+
| **Bytes Transferred (MB)"/dev/shm/50M" file as storage device**   | **Number of files transferred**   | **Total Bytes transferred (MB)**   | **Transfer Rate (MB/sec)**   |
+===================================================================+===================================+====================================+==============================+
| 50                                                                | 1                                 | 50                                 | 3.4                          |
+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+

Table:  **OMAPL138-LCDK USB Slave WritePerformance values**

| 

.. rubric:: K2G USB SLAVE DEVICE PERFORMANCE
   :name: k2g-usb-slave-device-performance

+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+
| **Bytes Transferred (MB)"/dev/shm/50M" file as storage device**   | **Number of files transferred**   | **Total Bytes transferred (MB)**   | **Transfer Rate (MB/sec)**   |
+===================================================================+===================================+====================================+==============================+
| 50                                                                | 1                                 | 50                                 | 30.2                         |
+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+

Table:  **K2G USB Slave Read Performance values**

+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+
| **Bytes Transferred (MB)"/dev/shm/50M" file as storage device**   | **Number of files transferred**   | **Total Bytes transferred (MB)**   | **Transfer Rate (MB/sec)**   |
+===================================================================+===================================+====================================+==============================+
| 50                                                                | 1                                 | 50                                 | 21.4                         |
+-------------------------------------------------------------------+-----------------------------------+------------------------------------+------------------------------+

Table:  **K2G USB Slave WritePerformance values**

| 

.. rubric:: USB CDC/RNDIS Slave Driver
   :name: usb-cdcrndis-slave-driver

Performance benchmarks were collected using the Iperf tool and default
options were used to collect the throughput numbers.

.. rubric:: AM335X USB CDC Performance
   :name: am335x-usb-cdc-performance

+----------------------------------+-----------------------------+-----------------------------+
| **TCP Window Size(in KBytes)**   | **Interval (in Seconds)**   | **Bandwidth (Mbits/Sec)**   |
+==================================+=============================+=============================+
| 16                               | 60                          | 55.4                        |
+----------------------------------+-----------------------------+-----------------------------+
| 32                               | 60                          | 52.0                        |
+----------------------------------+-----------------------------+-----------------------------+
| 64                               | 60                          | 50.0                        |
+----------------------------------+-----------------------------+-----------------------------+
| 128                              | 60                          | 49.6                        |
+----------------------------------+-----------------------------+-----------------------------+

Table:  **AM335X USB CDC Performance values - Client**

| 

.. rubric:: AM43XX GPEVM USB CDC Performance
   :name: am43xx-gpevm-usb-cdc-performance

+----------------------------------+-----------------------------+-----------------------------+
| **TCP Window Size(in KBytes)**   | **Interval (in Seconds)**   | **Bandwidth (Mbits/Sec)**   |
+==================================+=============================+=============================+
| 16                               | 60                          | 163.9                       |
+----------------------------------+-----------------------------+-----------------------------+
| 32                               | 60                          | 161.1                       |
+----------------------------------+-----------------------------+-----------------------------+
| 64                               | 60                          | 168.9                       |
+----------------------------------+-----------------------------+-----------------------------+
| 128                              | 60                          | 177.5                       |
+----------------------------------+-----------------------------+-----------------------------+

Table:  **AM43XX GPEVM USB CDC Performance values - Client**

| 

.. rubric:: AM57XX USB CDC Performance
   :name: am57xx-usb-cdc-performance

+----------------------------------+-----------------------------+-----------------------------+
| **TCP Window Size(in KBytes)**   | **Interval (in Seconds)**   | **Bandwidth (Mbits/Sec)**   |
+==================================+=============================+=============================+
| 16                               | 60                          | 245.9                       |
+----------------------------------+-----------------------------+-----------------------------+
| 32                               | 60                          | 253.0                       |
+----------------------------------+-----------------------------+-----------------------------+
| 64                               | 60                          | 254.0                       |
+----------------------------------+-----------------------------+-----------------------------+
| 128                              | 60                          | 257.0                       |
+----------------------------------+-----------------------------+-----------------------------+

Table:  **AM57XX USB CDC Performance values - Client**

| 

.. rubric:: K2G-EVM USB CDC Performance
   :name: k2g-evm-usb-cdc-performance

+----------------------------------+-----------------------------+-----------------------------+
| **TCP Window Size(in KBytes)**   | **Interval (in Seconds)**   | **Bandwidth (Mbits/Sec)**   |
+==================================+=============================+=============================+
| 16                               | 60                          | 181.0                       |
+----------------------------------+-----------------------------+-----------------------------+
| 32                               | 60                          | 177.8                       |
+----------------------------------+-----------------------------+-----------------------------+
| 64                               | 60                          | 183.1                       |
+----------------------------------+-----------------------------+-----------------------------+
| 128                              | 60                          | 195.8                       |
+----------------------------------+-----------------------------+-----------------------------+

Table:  **K2G-EVM USB CDC Performance values - Client**

.. rubric:: OMAPL138-LCDK USB CDC Performance
   :name: omapl138-lcdk-usb-cdc-performance

+----------------------------------+-----------------------------+-----------------------------+
| **TCP Window Size(in KBytes)**   | **Interval (in Seconds)**   | **Bandwidth (Mbits/Sec)**   |
+==================================+=============================+=============================+
| 16                               | 60                          | 14.8                        |
+----------------------------------+-----------------------------+-----------------------------+
| 32                               | 60                          | 15.3                        |
+----------------------------------+-----------------------------+-----------------------------+
| 64                               | 60                          | 21.4                        |
+----------------------------------+-----------------------------+-----------------------------+
| 128                              | 60                          | 25.5                        |
+----------------------------------+-----------------------------+-----------------------------+

Table:  **OMAPL138-LCDK USB CDC Performance values - Client**

| 

.. rubric:: AM335X USB RNDIS Performance
   :name: am335x-usb-rndis-performance

+----------------------------------+-----------------------------+-----------------------------+
| **TCP Window Size(in KBytes)**   | **Interval (in Seconds)**   | **Bandwidth (Mbits/Sec)**   |
+==================================+=============================+=============================+
| 16                               | 60                          | 57.7                        |
+----------------------------------+-----------------------------+-----------------------------+
| 32                               | 60                          | 56.4                        |
+----------------------------------+-----------------------------+-----------------------------+
| 64                               | 60                          | 56.2                        |
+----------------------------------+-----------------------------+-----------------------------+
| 128                              | 60                          | 48.8                        |
+----------------------------------+-----------------------------+-----------------------------+

Table:  **AM335XX USB RNDIS Performance values - Client**

| 

.. rubric:: AM43XX GPEVM USB RNDIS Performance
   :name: am43xx-gpevm-usb-rndis-performance

+----------------------------------+-----------------------------+-----------------------------+
| **TCP Window Size(in KBytes)**   | **Interval (in Seconds)**   | **Bandwidth (Mbits/Sec)**   |
+==================================+=============================+=============================+
| 16                               | 60                          | 130.2                       |
+----------------------------------+-----------------------------+-----------------------------+
| 32                               | 60                          | 123.3                       |
+----------------------------------+-----------------------------+-----------------------------+
| 64                               | 60                          | 126.3                       |
+----------------------------------+-----------------------------+-----------------------------+
| 128                              | 60                          | 129.9                       |
+----------------------------------+-----------------------------+-----------------------------+

Table:  **AM43XX GPEVM USB RNDIS Performance values - Client**

| 

| 

.. rubric:: AM57XX USB RNDIS Performance
   :name: am57xx-usb-rndis-performance

+----------------------------------+-----------------------------+-----------------------------+
| **TCP Window Size(in KBytes)**   | **Interval (in Seconds)**   | **Bandwidth (Mbits/Sec)**   |
+==================================+=============================+=============================+
| 16                               | 60                          | 186.7                       |
+----------------------------------+-----------------------------+-----------------------------+
| 32                               | 60                          | 162.4                       |
+----------------------------------+-----------------------------+-----------------------------+
| 64                               | 60                          | 182.2                       |
+----------------------------------+-----------------------------+-----------------------------+
| 128                              | 60                          | 199.5                       |
+----------------------------------+-----------------------------+-----------------------------+

Table:  **AM57XX USB RNDIS Performance values - Client**

| 

.. rubric:: K2G USB RNDIS Performance
   :name: k2g-usb-rndis-performance

+----------------------------------+-----------------------------+-----------------------------+
| **TCP Window Size(in KBytes)**   | **Interval (in Seconds)**   | **Bandwidth (Mbits/Sec)**   |
+==================================+=============================+=============================+
| 16                               | 60                          | 148.2                       |
+----------------------------------+-----------------------------+-----------------------------+
| 32                               | 60                          | 144.4                       |
+----------------------------------+-----------------------------+-----------------------------+
| 64                               | 60                          | 141.6                       |
+----------------------------------+-----------------------------+-----------------------------+
| 128                              | 60                          | 160.5                       |
+----------------------------------+-----------------------------+-----------------------------+

Table:  **K2G USB RNDIS Performance values - Client**

| 

.. rubric:: OMAPL138-LCDK GPEVM USB RNDIS Performance
   :name: omapl138-lcdk-gpevm-usb-rndis-performance

+----------------------------------+-----------------------------+-----------------------------+
| **TCP Window Size(in KBytes)**   | **Interval (in Seconds)**   | **Bandwidth (Mbits/Sec)**   |
+==================================+=============================+=============================+
| 16                               | 60                          | 16.2                        |
+----------------------------------+-----------------------------+-----------------------------+
| 32                               | 60                          | 13.2                        |
+----------------------------------+-----------------------------+-----------------------------+
| 64                               | 60                          | 12.4                        |
+----------------------------------+-----------------------------+-----------------------------+
| 128                              | 60                          | 14.1                        |
+----------------------------------+-----------------------------+-----------------------------+

Table:  **OMAPL138-LCDK USB RNDIS Performance values - Client**

| 

.. rubric:: CRYPTO Driver
   :name: crypto-driver

.. rubric:: OpenSSL Performance
   :name: openssl-performance

'
CRYPTO / host / openssl\_performance\_tests
Crypto\_M\_PERF\_openssl\_perf\_hardware\_acceleration
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
aes-128-cbc\_cpu\_util (%)
53.0
53.0
51.0
aes-128-cbc\_system\_time (s)
7.79
7.72
7.52
aes-128-cbc\_user\_time (s)
0.34
0.34
0.27
aes-128-cbc\_throughput\_16\_byte (KBytes/s)
1050.83
1314.04
2557.73
aes-128-cbc\_throughput\_64\_byte (KBytes/s)
3641.43
4502.1
8838.19
aes-128-cbc\_throughput\_256\_byt (KBytes/s)
4404.39
4625.66
5025.71
aes-128-cbc\_throughput\_1024\_by (KBytes/s)
11936.43
12942.34
14292.99
aes-128-cbc\_throughput\_8192\_by (KBytes/s)
19480.58
22487.04
30897.49
aes-192-cbc\_cpu\_util (%)
53.0
53.0
51.0
aes-192-cbc\_system\_time (s)
7.8
7.81
7.39
aes-192-cbc\_user\_time (s)
0.31
0.26
0.4
aes-192-cbc\_throughput\_16\_byte (KBytes/s)
1023.31
1298.06
2523.22
aes-192-cbc\_throughput\_64\_byte (KBytes/s)
3583.19
4364.22
8482.43
aes-192-cbc\_throughput\_256\_byt (KBytes/s)
4165.21
4645.97
4901.29
aes-192-cbc\_throughput\_1024\_by (KBytes/s)
11406.68
12781.23
14230.87
aes-192-cbc\_throughput\_8192\_by (KBytes/s)
19974.83
22462.46
30599.85
aes-256-cbc\_cpu\_util (%)
52.0
53.0
53.0
aes-256-cbc\_system\_time (s)
7.68
7.74
7.75
aes-256-cbc\_user\_time (s)
0.33
0.28
0.31
aes-256-cbc\_throughput\_16\_byte (KBytes/s)
1032.99
1293.14
2520.87
aes-256-cbc\_throughput\_64\_byte (KBytes/s)
3507.26
4253.46
8236.22
aes-256-cbc\_throughput\_256\_byt (KBytes/s)
3989.25
4566.27
4930.82
aes-256-cbc\_throughput\_1024\_by (KBytes/s)
11629.23
12761.43
14014.46
aes-256-cbc\_throughput\_8192\_by (KBytes/s)
18885.15
21891.75
30750.04
des-cbc\_cpu\_util (%)
98.0
35.0
20.0
des-cbc\_system\_time (s)
14.7
5.17
2.98
des-cbc\_user\_time (s)
0.16
0.17
0.14
des-cbc\_throughput\_16\_bytes (KBytes/s)
1077.8
391.35
311.35
des-cbc\_throughput\_64\_bytes (KBytes/s)
3507.69
1557.89
1175.13
des-cbc\_throughput\_256\_bytes (KBytes/s)
8271.96
4214.27
3937.62
des-cbc\_throughput\_1024\_bytes (KBytes/s)
12224.85
10097.66
9242.62
des-cbc\_throughput\_8192\_bytes (KBytes/s)
14125.74
16091.82
14974.98
des3\_cpu\_util (%)
97.0
35.0
19.0
des3\_system\_time (s)
14.46
5.17
2.84
des3\_user\_time (s)
0.29
0.18
0.16
des3\_throughput\_16\_bytes (KBytes/s)
949.86
394.9
312.38
des3\_throughput\_64\_bytes (KBytes/s)
2508.29
1561.98
1169.56
des3\_throughput\_256\_bytes (KBytes/s)
4487.59
4251.56
3952.47
des3\_throughput\_1024\_bytes (KBytes/s)
5503.66
10207.23
9125.89
des3\_throughput\_8192\_bytes (KBytes/s)
5679.97
16080.9
14518.95
md5\_cpu\_util (%)
77.0
76.0
77.0
md5\_system\_time (s)
9.01
9.18
9.87
md5\_user\_time (s)
2.78
2.34
1.75
md5\_throughput\_16\_bytes (KBytes/s)
449.44
581.06
858.3
md5\_throughput\_64\_bytes (KBytes/s)
1715.26
2286.72
3382.14
md5\_throughput\_256\_bytes (KBytes/s)
3338.58
4204.54
4649.9
md5\_throughput\_1024\_bytes (KBytes/s)
9514.33
11118.59
13220.18
md5\_throughput\_8192\_bytes (KBytes/s)
35749.89
42399.06
55610.03
sha1\_cpu\_util (%)
78.0
76.0
73.0
sha1\_system\_time (s)
9.24
9.3
9.16
sha1\_user\_time (s)
2.6
2.22
1.95
sha1\_throughput\_16\_bytes (KBytes/s)
406.96
540.39
755.81
sha1\_throughput\_64\_bytes (KBytes/s)
1575.45
2123.16
2995.93
sha1\_throughput\_256\_bytes (KBytes/s)
3245.14
3927.55
4038.57
sha1\_throughput\_1024\_bytes (KBytes/s)
8997.25
10797.25
13187.41
sha1\_throughput\_8192\_bytes (KBytes/s)
36031.15
41328.64
54771.71
| 
| -

| 
| Listed for each algorithm are the code snippets used to run each
  benchmark test.

| 

::

    time -v openssl speed -elapsed -evp aes-128-cbc

.. rubric:: IPSec Performance
   :name: ipsec-performance

Note: queue\_len is set to 300 and software fallback threshold set to 9
to enable software support for optimal performance

'
Hardware Crypto-based IPSec Throughput
**2017.05**
am335x-evm
am43xx-gpevm
am57xx-evm
udp\_aes128\_sha1 (Mbps)
48.4
62.4
147.5
udp\_aes192\_sha1 (Mbps)
55.2
60.9
141.9
udp\_aes256\_sha1 (Mbps)
54.2
61.1
146.2
.. rubric:: DCAN Driver
   :name: dcan-driver

Performance and Benchmarks not available in this release.

| 

.. rubric:: Power Management
   :name: power-management

.. rubric:: AM335x
   :name: am335x

Measurements were taken from Process SDK Linux 04.00.00.

|Warning| **Warning**: Active power is slightly higher on this release
because PRUSS is enabled by default. Customers not using PRUSS are
advised to disable it to reduce power consumption.

.. rubric:: Summary
   :name: summary

| The summary shows total SoC power consumption at all MPU frequencies.
| Please note, these test cases have not been optimized for low power!
| Data demonstrating power-optimized use cases and guidance to achieve
  lower power, please refer to the `AM335x Low Power Design
  Guide <http://www.ti.com/lit/an/sprac74a/sprac74a.pdf>`__.

.. rubric:: SoC-only power
   :name: soc-only-power

SoC-only power does not include power from DDR.

**Test Case**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
OS Idle
379.45
385.76
390.76
394.78
400.81
Dhrystone
488.95
682.90
821.01
924.80
1124.95
Network Load
379.78
387.36
389.56
395.16
399.96
Memory Tester
471.87
606.73
691.08
754.68
873.39
Video + Audio
460.12
681.63
787.60
859.14
1007.45
3D Graphics
555.10
579.75
600.80
621.36
644.74
Suspend
4.93
Standby
28.25
.. rubric:: OS Idle (Matrix GUI)
   :name: os-idle-matrix-gui

OS Idle is the case where no active userspace tasks are active. The
system is idle with the Matrix GUI application displayed on the LCD.
Note: having the LCD active will consume extra power.

| **Simplified View**

**Power Rail**
**Voltage**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
1.13
227.96
228.04
229.25
226.67
227.88
vdd\_mpu\_power
`DVFS <#DVFS_Rails>`__
7.44
13.21
15.45
17.58
29.56
1.8V I/O
1.8
60.39
62.05
62.72
37.73
65.38
3.3V I/O
3.3
100.33
100.26
100.39
94.8
100.29
**SoC Power without DDR3L**
396.12
403.56
407.81
376.78
423.11
DDR3L + I/O + VTT
1.5
236.67
236.5
236.18
235.81
235.65
**Total Power**
632.79
640.06
643.99
612.59
658.76
| **Detailed View**

**Power Rail**
**Voltage**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
1.13
227.96
228.04
229.25
226.67
227.88
vdd\_mpu\_power
`DVFS <#DVFS_Rails>`__
7.44
13.21
15.45
17.58
29.56
vdda\_1p8v\_usb0\_1\_power
1.8
32.96
32.92
32.98
7.26
33.02
vdda\_adc\_power
1.8
0.8
0.8
0.8
0.8
0.8
vdds\_a3p3v\_usb0\_1\_power
3.3
11.1
11.1
11.1
6.67
11.1
vdds\_osc\_power
1.8
1.23
1.23
1.23
1.23
1.23
vdds\_pll\_core\_lcd\_power
1.8
13.12
13.12
13.12
13.11
13.11
vdds\_pll\_ddr\_power
1.8
1.97
1.97
1.97
1.97
1.97
vdds\_pll\_mpu\_power
1.8
2.03
3.71
4.33
4.56
5.62
vdds\_power
1.8
2.4
2.4
2.4
2.39
2.4
vdds\_rtc\_power
1.8
0.66
0.66
0.66
0.66
0.66
vdds\_sram\_core\_bg\_power
1.8
2.69
2.7
2.7
2.68
2.7
vdds\_sram\_mpu\_bb\_power
1.8
2.53
2.54
2.53
3.07
3.87
vddshv1\_power
3.3
0.41
0.4
0.4
0.4
0.4
vddshv2\_power
3.3
2.58
2.58
2.58
2.58
2.58
vddshv3\_power
3.3
0.16
0.16
0.16
0.15
0.15
vddshv4\_power
3.3
0.09
0.09
0.09
0.09
0.09
vddshv5\_power
3.3
51.1
51.05
51.2
51.13
51.07
vddshv6\_power
3.3
34.89
34.88
34.86
33.78
34.9
**SoC Power without DDR3L**
396.12
403.56
407.81
376.78
423.11
vdds\_ddr\_power
1.5
142.27
142.31
142.46
143.44
143.44
vddsddrmem
1.5
94.4
94.19
93.72
92.37
92.21
**Total Power**
632.79
640.06
643.99
612.59
658.76
.. rubric:: Dhrystone
   :name: dhrystone-1

Dhrystone test case is typically be one of the most power-intensive
applications and used here to approximate worst-case power consumption
of the processor. Note: DDR3 is not exercised in this test case, however
test data has shown where DDR bandwidth is high, MPU utilization drops,
and total power consumption typically does not exceed Dhrystone.

**Simplified View**

**Power Rail**
**Voltage**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
1.13
229.24
230.15
230.76
231.06
245.75
vdd\_mpu\_power
`DVFS <#DVFS_Rails>`__
113.46
302.1
435.65
540.9
715.52
1.8V I/O
1.8
62.91
67.36
68.32
70.11
73.81
3.3V I/O
3.3
101.73
102.47
102.26
101.89
102.31
**SoC Power without DDR3L**
507.34
702.08
836.99
943.96
1137.39
DDR3L + I/O + VTT
1.5
262.82
262.88
263.01
262.67
263.77
**Total Power**
770.16
964.96
1100
1206.63
1401.16
**Detailed View**

**Power Rail**
**Voltage**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
1.13
229.24
230.15
230.76
231.06
245.75
vdd\_mpu\_power
`DVFS <#DVFS_Rails>`__
113.46
302.1
435.65
540.9
715.52
vdda\_1p8v\_usb0\_1\_power
1.8
33.04
33.26
33.03
33.06
32.97
vdda\_adc\_power
1.8
0.8
0.79
0.79
0.79
0.79
vdds\_a3p3v\_usb0\_1\_power
3.3
11.09
11.08
11.07
11.06
11.03
vdds\_osc\_power
1.8
1.23
1.23
1.23
1.23
1.22
vdds\_pll\_core\_lcd\_power
1.8
13.12
13.12
13.13
13.13
13.13
vdds\_pll\_ddr\_power
1.8
1.97
1.97
1.97
1.97
1.97
vdds\_pll\_mpu\_power
1.8
2.03
3.71
4.33
4.56
5.62
vdds\_power
1.8
2.53
2.55
2.54
2.53
2.53
vdds\_rtc\_power
1.8
0.66
0.66
0.66
0.66
0.67
vdds\_sram\_core\_bg\_power
1.8
2.75
2.8
2.88
2.93
3.06
vdds\_sram\_mpu\_bb\_power
1.8
4.78
7.27
7.76
9.25
11.85
vddshv1\_power
3.3
0.41
0.4
0.4
0.4
0.4
vddshv2\_power
3.3
8.98
8.97
9.15
8.95
9.06
vddshv3\_power
3.3
0.16
0.16
0.16
0.16
0.16
vddshv4\_power
3.3
0.09
0.09
0.09
0.09
0.09
vddshv5\_power
3.3
51.39
51.29
51.61
51.46
51.79
vddshv6\_power
3.3
29.61
30.48
29.78
29.77
29.78
**SoC Power without DDR3L**
507.34
702.08
836.99
943.96
1137.39
vdds\_ddr\_power
1.5
142.82
142.88
143.01
142.67
143.77
vddsddrmem
1.5
120
120
120
120
120
**Total Power**
770.16
964.96
1100
1206.63
1401.16
.. rubric:: Network Load
   :name: network-load

Network load is the test case where the data is being transmitted
through Ethernet.

| **Simplified View**

**Power Rail**
**Voltage**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
1.13
227.94
228.18
228.07
228.04
228
vdd\_mpu\_power
`DVFS <#DVFS_Rails>`__
7.35
12.3
15.85
19.18
33.53
1.8V I/O
1.8
60.38
62.13
62.63
63.69
65.45
3.3V I/O
3.3
100.32
100.3
100.34
100.17
100.2
**SoC Power without DDR3L**
395.99
402.91
406.89
411.08
427.18
DDR3L + I/O + VTT
1.5
237.01
237.22
237.01
236.24
235.8
**Total Power**
633
640.13
643.9
647.32
662.98
| **Detailed View**

**Power Rail**
**Voltage**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
1.13
227.94
228.18
228.07
228.04
228
vdd\_mpu\_power
`DVFS <#DVFS_Rails>`__
7.35
12.3
15.85
19.18
33.53
vdda\_1p8v\_usb0\_1\_power
1.8
32.95
32.92
32.89
32.97
32.97
vdda\_adc\_power
1.8
0.8
0.8
0.8
0.8
0.8
vdds\_a3p3v\_usb0\_1\_power
3.3
11.1
11.09
11.09
11.1
11.09
vdds\_osc\_power
1.8
1.23
1.23
1.23
1.23
1.23
vdds\_pll\_core\_lcd\_power
1.8
13.12
13.12
13.12
13.11
13.11
vdds\_pll\_ddr\_power
1.8
1.97
1.97
1.97
1.97
1.97
vdds\_pll\_mpu\_power
1.8
2.03
3.71
4.33
4.56
5.62
vdds\_power
1.8
2.39
2.39
2.39
2.39
2.39
vdds\_rtc\_power
1.8
0.66
0.66
0.66
0.66
0.66
vdds\_sram\_core\_bg\_power
1.8
2.69
2.72
2.7
2.7
2.71
vdds\_sram\_mpu\_bb\_power
1.8
2.54
2.61
2.54
3.3
3.99
vddshv1\_power
3.3
0.41
0.41
0.41
0.41
0.4
vddshv2\_power
3.3
2.58
2.58
2.58
2.58
2.58
vddshv3\_power
3.3
0.16
0.15
0.15
0.16
0.16
vddshv4\_power
3.3
0.09
0.08
0.09
0.09
0.09
vddshv5\_power
3.3
51.17
51.16
51.2
51.03
51.1
vddshv6\_power
3.3
34.81
34.83
34.82
34.8
34.78
**SoC Power without DDR3L**
395.99
402.91
406.89
411.08
427.18
vdds\_ddr\_power
1.5
142.54
142.25
142.6
144.06
143.38
vddsddrmem
1.5
94.47
94.97
94.41
92.18
92.42
**Total Power**
633
640.13
643.9
647.32
662.98
.. rubric:: Memory Tester
   :name: memory-tester

This test case executes the DDR memory data transactions.

Note: total power and DDR power is not logged here since DDR power
consumption can vary significantly based on memory test case.

| **Simplified View**

**Power Rail**
**Voltage**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
1.13
237.84
243.85
244.73
243.6
243.15
vdd\_mpu\_power
`DVFS <#DVFS_Rails>`__
90.44
217.16
299.46
367.42
489.18
1.8V I/O
1.8
62.14
64.83
65.79
66.78
67.79
3.3V I/O
3.3
101.91
101.71
101.83
101.7
101.86
**SoC Power without DDR3L**
492.33
627.55
711.81
779.5
901.98
DDR3L + I/O + VTT
1.5
**Total Power**
| **Detailed View**

**Power Rail**
**Voltage**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
1.13
237.84
243.85
244.73
243.6
243.15
vdd\_mpu\_power
`DVFS <#DVFS_Rails>`__
90.44
217.16
299.46
367.42
489.18
vdda\_1p8v\_usb0\_1\_power
1.8
32.99
33
33.03
32.99
32.94
vdda\_adc\_power
1.8
0.8
0.79
0.79
0.79
0.79
vdds\_a3p3v\_usb0\_1\_power
3.3
11.09
11.08
11.07
11.07
11.06
vdds\_osc\_power
1.8
1.23
1.23
1.23
1.23
1.23
vdds\_pll\_core\_lcd\_power
1.8
13.12
13.13
13.13
13.13
13.13
vdds\_pll\_ddr\_power
1.8
1.97
1.97
1.97
1.97
1.97
vdds\_pll\_mpu\_power
1.8
2.03
3.71
4.34
4.56
5.62
vdds\_power
1.8
2.53
2.53
2.53
2.53
2.53
vdds\_rtc\_power
1.8
0.66
0.66
0.66
0.66
0.66
vdds\_sram\_core\_bg\_power
1.8
2.75
2.83
2.85
2.86
2.93
vdds\_sram\_mpu\_bb\_power
1.8
4.06
4.98
5.26
6.06
5.99
vddshv1\_power
3.3
0.41
0.4
0.4
0.4
0.4
vddshv2\_power
3.3
9.05
8.96
8.97
8.86
9.07
vddshv3\_power
3.3
0.15
0.16
0.16
0.16
0.15
vddshv4\_power
3.3
0.09
0.09
0.09
0.09
0.09
vddshv5\_power
3.3
51.48
51.43
51.46
51.47
51.52
vddshv6\_power
3.3
29.64
29.59
29.68
29.65
29.57
**SoC Power without DDR3L**
492.33
627.55
711.81
779.5
901.98
vdds\_ddr\_power
1.5
147.36
149.24
149.7
147
152.73
vddsddrmem
1.5
**Total Power**
.. rubric:: Video + Audio
   :name: video-audio

Video and Audio decode test case decodes the MPEG4 video content and
displays it on the LCD and also decodes the audio content and output
through the audio jack.

| **Simplified View**

**Power Rail**
**Voltage**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
1.13
237.19
232.61
242.83
245.88
247.19
vdd\_mpu\_power
`DVFS <#DVFS_Rails>`__
90.58
103.83
323.36
405.32
535.69
1.8V I/O
1.8
61.81
37.91
66.28
66.88
69.37
3.3V I/O
3.3
104.25
116.94
101.56
98.16
101.84
**SoC Power without DDR3L**
493.83
491.29
734.03
816.24
954.09
DDR3L + I/O + VTT
1.5
265.68
276.07
285.45
287.4
295.78
**Total Power**
759.51
767.36
1019.48
1103.64
1249.87
| **Detailed View**

**Power Rail**
**Voltage**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
1.13
237.19
232.61
242.83
245.88
247.19
vdd\_mpu\_power
`DVFS <#DVFS_Rails>`__
90.58
103.83
323.36
405.32
535.69
vdda\_1p8v\_usb0\_1\_power
1.8
32.98
7.28
33.01
32.86
32.84
vdda\_adc\_power
1.8
0.79
0.8
0.79
0.79
0.79
vdds\_a3p3v\_usb0\_1\_power
3.3
11.09
6.66
11.07
11.06
11.04
vdds\_osc\_power
1.8
1.23
1.23
1.23
1.23
1.22
vdds\_pll\_core\_lcd\_power
1.8
13.12
13.12
13.12
13.12
13.13
vdds\_pll\_ddr\_power
1.8
1.97
1.97
1.97
1.97
1.97
vdds\_pll\_mpu\_power
1.8
2.03
3.71
4.33
4.56
5.62
vdds\_power
1.8
2.5
2.85
2.69
2.69
2.49
vdds\_rtc\_power
1.8
0.66
0.66
0.66
0.66
0.66
vdds\_sram\_core\_bg\_power
1.8
2.75
2.73
2.85
2.88
2.96
vdds\_sram\_mpu\_bb\_power
1.8
3.78
3.56
5.63
6.12
7.69
vddshv1\_power
3.3
0.41
0.41
0.41
0.4
0.4
vddshv2\_power
3.3
6.38
3.88
7.64
7.66
9.02
vddshv3\_power
3.3
0.16
0.16
0.16
0.16
0.16
vddshv4\_power
3.3
5.05
22.09
0.09
0.09
0.08
vddshv5\_power
3.3
51.11
51.14
51.59
51.45
51.54
vddshv6\_power
3.3
30.05
32.6
30.6
27.34
29.6
**SoC Power without DDR3L**
493.83
491.29
734.03
816.24
954.09
vdds\_ddr\_power
1.5
144.53
142.78
146.45
147.73
149.06
vddsddrmem
1.5
121.15
133.29
139
139.67
146.72
**Total Power**
759.51
767.36
1019.48
1103.64
1249.87
.. rubric:: 3D Graphics
   :name: d-graphics

3D graphics test case is the processor executes 3D graphics and display
the content in the LCD.

| **Simplified View**

**Power Rail**
**Voltage**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
1.13
272.02
269.44
270.13
271.33
271.57
vdd\_mpu\_power
`DVFS <#DVFS_Rails>`__
31.03
53.99
61.75
74.76
88.32
1.8V I/O
1.8
61.61
63.26
64.11
64.67
66.39
3.3V I/O
3.3
142.02
141.27
142.22
141.92
141.6
**SoC Power without DDR3L**
506.68
527.96
538.21
552.68
567.88
DDR3L + I/O + VTT
1.5
298.43
298.44
298.8
298.96
299.17
**Total Power**
805.11
826.4
837.01
851.64
867.05
| **Detailed View**

**Power Rail**
**Voltage**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
1.13
272.02
269.44
270.13
271.33
271.57
vdd\_mpu\_power
`DVFS <#DVFS_Rails>`__
31.03
53.99
61.75
74.76
88.32
vdda\_1p8v\_usb0\_1\_power
1.8
32.98
32.93
33.16
32.96
32.91
vdda\_adc\_power
1.8
0.79
0.79
0.79
0.79
0.79
vdds\_a3p3v\_usb0\_1\_power
3.3
11.09
11.09
11.08
11.08
11.08
vdds\_osc\_power
1.8
1.23
1.23
1.23
1.23
1.23
vdds\_pll\_core\_lcd\_power
1.8
13.12
13.12
13.12
13.12
13.12
vdds\_pll\_ddr\_power
1.8
1.97
1.97
1.97
1.97
1.97
vdds\_pll\_mpu\_power
1.8
2.03
3.71
4.34
4.56
5.63
vdds\_power
1.8
3.09
3.09
3.08
3.08
3.08
vdds\_rtc\_power
1.8
0.66
0.66
0.66
0.66
0.66
vdds\_sram\_core\_bg\_power
1.8
2.88
2.89
2.89
2.9
2.91
vdds\_sram\_mpu\_bb\_power
1.8
2.86
2.87
2.87
3.4
4.09
vddshv1\_power
3.3
0.4
0.4
0.4
0.4
0.4
vddshv2\_power
3.3
28.9
28.75
28.83
29.06
29.04
vddshv3\_power
3.3
0.16
0.16
0.16
0.16
0.16
vddshv4\_power
3.3
0.09
0.09
0.09
0.09
0.09
vddshv5\_power
3.3
51.13
51.03
51.21
51.08
51.06
vddshv6\_power
3.3
50.25
49.75
50.45
50.05
49.77
**SoC Power without DDR3L**
506.68
527.96
538.21
552.68
567.88
vdds\_ddr\_power
1.5
150.38
151.28
149.98
150.53
151.24
vddsddrmem
1.5
148.05
147.16
148.82
148.43
147.93
**Total Power**
805.11
826.4
837.01
851.64
867.05
.. rubric:: Low Power Modes - Standby and Suspend
   :name: low-power-modes---standby-and-suspend

Standby and Suspend modes both put the processor into a low-power state.
DDR is in self-refresh.

| **Simplified View**

**Power Rail**
**Voltage**
**Standby**
**Suspend**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
1.13
14.25
1.2
vdd\_mpu\_power
0.95
0.3
0.26
1.8V I/O
1.8
4.02
2.18
3.3V I/O
3.3
1.54
1.33
**SoC Power without DDR3L**
20.11
4.97
DDR3L + I/O + VTT
1.5
28.27
28.24
**Total Power**
48.38
33.21
| **Detailed View**

**Power Rail**
**Voltage**
**Standby**
**Suspend**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
1.13
14.25
1.2
vdd\_mpu\_power
0.95
0.3
0.26
vdda\_1p8v\_usb0\_1\_power
1.8
0
0
vdda\_adc\_power
1.8
0
0
vdds\_a3p3v\_usb0\_1\_power
3.3
0.08
0.07
vdds\_osc\_power
1.8
1.25
0
vdds\_pll\_core\_lcd\_power
1.8
0
0
vdds\_pll\_ddr\_power
1.8
0
0
vdds\_pll\_mpu\_power
1.8
0
0
vdds\_power
1.8
0.89
1.3
vdds\_rtc\_power
1.8
0.04
0.04
vdds\_sram\_core\_bg\_power
1.8
1.83
0.83
vdds\_sram\_mpu\_bb\_power
1.8
0.01
0.01
vddshv1\_power
3.3
0.44
0.29
vddshv2\_power
3.3
0.09
0.09
vddshv3\_power
3.3
0.16
0.12
vddshv4\_power
3.3
0.09
0.09
vddshv5\_power
3.3
0.12
0.12
vddshv6\_power
3.3
0.56
0.55
**SoC Power without DDR3L**
20.11
4.97
vdds\_ddr\_power
1.5
0.75
0.75
vddsddrmem
1.5
27.52
27.49
**Total Power**
48.38
33.21
| 

| 

.. rubric:: DVFS Rails
   :name: dvfs-rails

**Power Rail**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Voltage (V)**
**Voltage (V)**
**Voltage (V)**
**Voltage (V)**
**Voltage (V)**
vdd\_mpu\_power
0.95
1.1
1.2
1.26
1.325
| 

.. rubric:: AM437x
   :name: am437x

Measurements were taken from Process SDK Linux 04.00.00.

|Note|\ **Note:** Active power is slightly higher on this release
because PRUSS is enabled by default. Customers not using PRUSS are
advised to disable it to reduce power consumption.

.. rubric:: Summary
   :name: summary-1

| The summary shows total SoC power consumption at all MPU frequencies.
| Please note, these test cases have not been optimized for low power!

.. rubric:: SoC-only power
   :name: soc-only-power-1

SoC-only power does not include power from DDR.

**Power Rail**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
OS Idle
543.55
547.34
549.71
552.76
556.28
Dhrystone
666.93
876.05
1023.5
1134.28
1362.6
Network Load
543.7
547.48
550.44
553.51
557.6
Memory Tester
690.76
846.85
931.88
1005.35
1140.47
Video + Audio
666.93
565.06
958.1
1058.02
1237.29
3D Graphics
639.33
659.49
669.92
677.91
693.52
Standby
42.07
Suspend (Deep sleep)
12.84
Suspend (RTC+DDR)
<30uW :sup:`[1]`
RTC-only
<30uW :sup:`[1]`
Notes:

[1] Sense resistors installed on EVM do not provide sufficient dynamic
range to accurately measure the RTC domain of AM43XX.

| 

.. rubric:: OS Idle (Matrix GUI)
   :name: os-idle-matrix-gui-1

OS Idle is the case where no active userspace tasks are active. The
system is idle with the Matrix GUI application displayed on the LCD.
Note: having the LCD active will consume extra power.

**Detailed View**

**Power Rail**
**Voltage**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
v3\_3d\_am437x\_power
3.3
98.33
98.26
98.19
98.33
98.31
vdd\_core\_power
1.1
369.85
369.94
369.7
370.08
369.65
vdd\_mpu\_power
`DVFS <#DVFS_Rails_2>`__
3.04
5.25
7.06
8.8
11.26
**SoC Power without DDR3L**
543.55
547.34
549.71
552.76
556.28
vdds\_ddr\_mem\_power
1.5
176.15
179.04
175.22
176.79
177.88
vdds\_ddr\_power
1.5
159.5
157.69
160.27
159.61
158.4
**Total Power**
879.2
884.07
885.2
889.16
892.56
.. rubric:: Dhrystone
   :name: dhrystone-2

Dhrystone test case is typically be one of the most power-intensive
applications and used here to approximate worst-case power consumption
of the processor. Note: DDR3 is not exercised in this test case, however
test data has shown where DDR bandwidth is high, MPU utilization drops,
and total power consumption typically does not exceed Dhrystone.

**Detailed View**

**Power Rail**
**Voltage**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
v1\_8d\_am437x\_power
1.8
74.28
77.72
79.93
80.87
84.65
v3\_3d\_am437x\_power
3.3
98.4
98.29
98.32
98.23
98.26
vdd\_core\_power
1.1
371.51
372.87
374.87
375.01
377.4
vdd\_mpu\_power
`DVFS <#DVFS_Rails_2>`__
122.74
327.17
470.38
580.17
802.29
**SoC Power without DDR3L**
666.93
876.05
1023.5
1134.28
1362.6
vdds\_ddr\_mem\_power
1.5
178.9
176.2
175.07
179.18
176.31
vdds\_ddr\_power
1.5
158.21
158.95
159.56
157.58
158.8
**Total Power**
1004.04
1211.2
1358.13
1471.04
1697.71
.. rubric:: Network Load
   :name: network-load-1

Network load is the test case where the data is being transmitted
through Ethernet.

**Detailed View**

**Power Rail**
**Voltage**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
v1\_8d\_am437x\_power
1.8
72.39
73.97
74.78
75.62
77.27
v3\_3d\_am437x\_power
3.3
98.23
98.22
98.22
98.2
98.3
vdd\_core\_power
1.1
369.94
370.09
369.74
370.07
370.12
vdd\_mpu\_power
`DVFS <#DVFS_Rails_2>`__
3.14
5.2
7.7
9.62
11.91
**SoC Power without DDR3L**
543.7
547.48
550.44
553.51
557.6
vdds\_ddr\_mem\_power
1.5
179.06
176.54
177.86
177.74
179.51
vdds\_ddr\_power
1.5
157.76
159.07
158.35
158.31
157.66
**Total Power**
880.52
883.09
886.65
889.56
894.77
.. rubric:: Memory Tester
   :name: memory-tester-1

This test case executes the DDR memory data transactions.

**Detailed View**

**Power Rail**
**Voltage**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
v1\_8d\_am437x\_power
1.8
73.42
76.03
76.98
77.54
79.72
v3\_3d\_am437x\_power
3.3
98.28
98.31
98.31
98.21
98.31
vdd\_core\_power
1.1
403.65
414.59
411.76
417.63
415.1
vdd\_mpu\_power
`DVFS <#DVFS_Rails_2>`__
115.41
257.92
344.83
411.97
547.34
**SoC Power without DDR3L**
690.76
846.85
931.88
1005.35
1140.47
vdds\_ddr\_mem\_power
1.5
284.37
292.37
300.23
303.12
306.09
vdds\_ddr\_power
1.5
208.76
217.54
227.78
220.65
222.39
**Total Power**
1183.89
1356.76
1459.89
1529.12
1668.95
.. rubric:: Video + Audio
   :name: video-audio-1

Video and Audio decode test case decodes the MPEG4 video content and
displays it on the LCD and also decodes the audio content and output
through the audio jack.

Simplified View

**Detailed View**

**Power Rail**
**Voltage**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
v1\_8d\_am437x\_power
1.8
74.93
73.09
79.36
80.79
83.36
v3\_3d\_am437x\_power
3.3
109.65
97.64
107.44
111.17
111.32
vdd\_core\_power
1.1
385.14
378.08
397.11
399.3
403.06
vdd\_mpu\_power
`DVFS <#DVFS_Rails_2>`__
97.21
16.25
374.19
466.76
639.55
**SoC Power without DDR3L**
666.93
565.06
958.1
1058.02
1237.29
vdds\_ddr\_mem\_power
1.5
221.73
202.07
252.78
266.56
278.33
vdds\_ddr\_power
1.5
177.04
169.11
190.47
194.17
200.29
**Total Power**
1065.7
936.24
1401.35
1518.75
1715.91
.. rubric:: 3D Graphics
   :name: d-graphics-1

3D graphics test case is the processor executes 3D graphics and display
the content in the LCD.

Simplified View

**Detailed View**

**Power Rail**
**Voltage**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
v1\_8d\_am437x\_power
1.8
75.22
77.23
78.26
78.81
80.39
v3\_3d\_am437x\_power
3.3
110.22
109.87
109.88
110
110.33
vdd\_core\_power
1.1
430.68
430.66
434.19
433.55
433.27
vdd\_mpu\_power
`DVFS <#DVFS_Rails_2>`__
23.21
41.73
47.59
55.55
69.53
**SoC Power without DDR3L**
639.33
659.49
669.92
677.91
693.52
vdds\_ddr\_mem\_power
1.5
267.79
264.15
269.75
266.57
266.04
vdds\_ddr\_power
1.5
202.13
200.66
203.65
200.58
201.47
**Total Power**
1109.25
1124.3
1143.32
1145.06
1161.03
.. rubric:: Low Power Modes - Suspend and Standby
   :name: low-power-modes---suspend-and-standby

Standby and Suspend modes both put the processor into a low-power state.
DDR is in self-refresh.

**Detailed View**

**Power Rail**
**Voltage**
**Standby**
**Suspend**
**RTC+DDR**
**RTC Only**
**Power (mW)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
v1\_8d\_am437x\_power
1.8
12.97
9.89
0
0
v3\_3d\_am437x\_power
3.3
1.75
1.62
0
0
vdd\_core\_power
0.95
27.1
1.11
0
0
vdd\_mpu\_power
0.95
0.25
0.22
0
0
**Total Power**
42.07
12.84
0
0
vdds\_ddr\_mem\_power
1.5
54.82
54.9
55.12
15.02
vdds\_ddr\_power
1.5
0.99
0.99
0
0
**Total Power**
97.88
68.73
55.12
15.02
| 

.. rubric:: DVFS Rails
   :name: dvfs-rails-1

**Power Rail**
**MPU OPP50 (300MHz)**
**MPU OPP100 (600MHz)**
**MPU OPP120 (720MHz)**
**MPU OPP\_Turbo (800MHz)**
**MPU OPP\_Nitro (1000MHz)**
**Voltage (V)**
**Voltage (V)**
**Voltage (V)**
**Voltage (V)**
**Voltage (V)**
vdd\_mpu\_power
0.95
1.1
1.2
1.26
1.325
**Note:** vdd\_core\_power does not support DVFS, however
vdd\_core\_power voltage drops to 0.95V during CPU Idle.

| 

.. rubric:: v1\_8d\_am437x
   :name: v1_8d_am437x

The following AM437X voltage domains are connected to the v1\_8d\_AM437x
net on the AM437X GP EVM (production version).

| VDDS\_OSC
| VDDS\_CTM
| VDDS\_CLKOUT
| VDDA\_MC\_ADC
| VDDA\_TS\_ADC
| VDDS\_SRAM\_CORE\_BG
| VDDS\_SRAM\_MPU\_BB
| VDDS\_PLL\_DDR
| VDDS VDDS\_PLL\_MPU
| VDDS\_PLL\_CORE\_LCD
| VDDSHV9
| VDDSHV11
| VDDA1P8V\_USB0
| VDDA1P8V\_USB1

.. rubric:: v3\_3d\_am437x
   :name: v3_3d_am437x

The following AM437X voltage domains are connected to the v3\_3d\_AM437x
net on the AM437X GP EVM (production version).

| VDDSHV1
| VDDSHV2
| VDDSHV3
| VDDSHV5
| VDDSHV6
| VDDSHV7
| VDDSHV8
| VDDSHV10
| VDDA\_3P3V\_USB0
| VDDA\_3P3V\_USB1

| 

.. rubric:: AM571x
   :name: am571x

Power measurement data for AM571x was taken using an internal EVM
running a trimmed down version of `Processor
SDK <http://www.ti.com/tool/PROCESSOR-SDK-AM57X>`__. Data presented here
should be representative of power consumption of AM571x family of
devices. The internal EVM allows finer measurement granularity.

.. rubric:: Summary
   :name: summary-2

| The summary shows total SoC power consumption at all MPU frequencies.
| Please note, these test cases have not been optimized for low power!

.. rubric:: SoC-only power
   :name: soc-only-power-2

SoC-only power does not include power from DDR.

**Power Rail**
**2017.01**
**dra72x-evm**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
OS Idle
1599.61
1634.6
1734.58
Dhrystone
2259.44
2614.36
3436.66
Network Load
1574.61
1612.1
1688.33
Memory Tester
2349.42
2629.35
3547.87
Video + Audio
1779.56
1633.35
2720.58
3D Graphics
1804.56
1847.68
1978.28
Suspend-to-RAM
472.27
.. rubric:: OS Idle (Matrix GUI)
   :name: os-idle-matrix-gui-2

OS Idle is the case where no active userspace tasks are active. The
system is idle with the Matrix GUI application displayed on the LCD.
Note: having the LCD active will consume extra power.

**Simplified View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
AVS
674.84
674.84
672.34
vdd\_gpu\_iva\_dspeve\_power
AVS
162.46
162.46
162.46
vdd\_mpu\_power
DVFS
87.48
124.97
224.95
1.8V I/O
1.8
449.89
447.39
449.89
3.3V I/O
3.3
224.94
224.94
224.94
**SoC Power without DDR3L**
1599.61
1634.6
1734.58
evm\_vdd\_ddr\_power
1.35
287.43
284.93
281.18
j6\_vdd\_ddr\_power
1.35
303.68
307.42
306.18
**Total Power**
2190.72
2226.95
2321.94
**Detailed View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
AVS
674.84
674.84
672.34
vdd\_gpu\_iva\_dspeve\_power
AVS
162.46
162.46
162.46
vdd\_mpu\_power
DVFS
87.48
124.97
224.95
evm\_vdd\_1v8\_power
1.8
24.99
24.99
24.99
j6\_vdd\_1v8\_power
1.8
137.47
134.97
137.47
vdda\_1v8\_phy2\_power
1.8
137.47
137.47
137.47
vdda\_phy\_power
1.8
87.48
87.48
87.48
vdda\_pll\_power
1.8
62.48
62.48
62.48
vdd\_shv5\_power
3.3
199.95
199.95
199.95
vdd\_shv8\_power
3.3
0
0
0
vdda\_usb3v3\_power
3.3
24.99
24.99
24.99
**SoC Power without DDR3L**
1599.61
1634.6
1734.58
evm\_vdd\_ddr\_power
1.35
287.43
284.93
281.18
j6\_vdd\_ddr\_power
1.35
303.68
307.42
306.18
**Total Power**
2190.72
2226.95
2321.94
.. rubric:: Dhrystone
   :name: dhrystone-3

Dhrystone test case is typically be one of the most power-intensive
applications and used here to approximate worst-case power consumption
of the processor. Note: DDR3 is not exercised in this test case, however
test data has shown where DDR bandwidth is high, MPU utilization drops,
and total power consumption typically does not exceed Dhrystone.

**Simplified View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
AVS
647.34
674.84
672.34
vdd\_gpu\_iva\_dspeve\_power
AVS
162.46
162.46
162.46
vdd\_mpu\_power
DVFS
774.81
1102.23
1902.04
1.8V I/O
1.8
449.89
449.89
474.88
3.3V I/O
3.3
224.94
224.94
224.94
**SoC Power without DDR3L**
2259.44
2614.36
3436.66
evm\_vdd\_ddr\_power
1.35
287.43
287.43
287.43
j6\_vdd\_ddr\_power
1.35
302.43
302.43
304.93
**Total Power**
2849.3
3204.22
4029.02
**Detailed View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
AVS
647.34
674.84
672.34
vdd\_gpu\_iva\_dspeve\_power
AVS
162.46
162.46
162.46
vdd\_mpu\_power
DVFS
774.81
1102.23
1902.04
evm\_vdd\_1v8\_power
1.8
24.99
24.99
24.99
j6\_vdd\_1v8\_power
1.8
137.47
137.47
162.46
vdda\_1v8\_phy2\_power
1.8
137.47
137.47
137.47
vdda\_phy\_power
1.8
87.48
87.48
87.48
vdda\_pll\_power
1.8
62.48
62.48
62.48
vdd\_shv5\_power
3.3
199.95
199.95
199.95
vdd\_shv8\_power
3.3
0
0
0
vdda\_usb3v3\_power
3.3
24.99
24.99
24.99
**SoC Power without DDR3L**
2259.44
2614.36
3436.66
evm\_vdd\_ddr\_power
1.35
287.43
287.43
287.43
j6\_vdd\_ddr\_power
1.35
302.43
302.43
304.93
**Total Power**
2849.3
3204.22
4029.02
.. rubric:: Network Load
   :name: network-load-2

Network load is the test case where the data is being transmitted
through Ethernet.

**Simplified View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
AVS
649.84
649.84
651.09
vdd\_gpu\_iva\_dspeve\_power
AVS
162.46
162.46
162.46
vdd\_mpu\_power
DVFS
87.48
124.97
199.95
1.8V I/O
1.8
449.89
449.89
449.89
3.3V I/O
3.3
224.94
224.94
224.94
**SoC Power without DDR3L**
1574.61
1612.1
1688.33
evm\_vdd\_ddr\_power
1.35
287.43
282.43
287.43
j6\_vdd\_ddr\_power
1.35
307.42
303.68
299.93
**Total Power**
2169.46
2198.21
2275.69
**Detailed View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
AVS
649.84
649.84
651.09
vdd\_gpu\_iva\_dspeve\_power
AVS
162.46
162.46
162.46
vdd\_mpu\_power
DVFS
87.48
124.97
199.95
evm\_vdd\_1v8\_power
1.8
24.99
24.99
24.99
j6\_vdd\_1v8\_power
1.8
137.47
137.47
137.47
vdda\_1v8\_phy2\_power
1.8
137.47
137.47
137.47
vdda\_phy\_power
1.8
87.48
87.48
87.48
vdda\_pll\_power
1.8
62.48
62.48
62.48
vdd\_shv5\_power
3.3
199.95
199.95
199.95
vdd\_shv8\_power
3.3
0
0
0
vdda\_usb3v3\_power
3.3
24.99
24.99
24.99
**SoC Power without DDR3L**
1574.61
1612.1
1688.33
evm\_vdd\_ddr\_power
1.35
287.43
282.43
287.43
j6\_vdd\_ddr\_power
1.35
307.42
303.68
299.93
**Total Power**
2169.46
2198.21
2275.69
.. rubric:: Memory Tester
   :name: memory-tester-2

This test case executes the DDR memory data transactions.

**Simplified View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
AVS
709.83
716.08
711.08
vdd\_gpu\_iva\_dspeve\_power
AVS
162.46
187.45
187.45
vdd\_mpu\_power
DVFS
752.32
1001.01
1924.53
1.8V I/O
1.8
499.87
499.87
499.87
3.3V I/O
3.3
224.94
224.94
224.94
**SoC Power without DDR3L**
2349.42
2629.35
3547.87
evm\_vdd\_ddr\_power
1.35
674.84
667.34
574.86
j6\_vdd\_ddr\_power
1.35
422.4
428.65
474.88
**Total Power**
3446.66
3725.34
4597.61
**Detailed View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
AVS
709.83
716.08
711.08
vdd\_gpu\_iva\_dspeve\_power
AVS
162.46
187.45
187.45
vdd\_mpu\_power
DVFS
752.32
1001.01
1924.53
evm\_vdd\_1v8\_power
1.8
24.99
24.99
24.99
j6\_vdd\_1v8\_power
1.8
187.45
187.45
187.45
vdda\_1v8\_phy2\_power
1.8
137.47
137.47
137.47
vdda\_phy\_power
1.8
87.48
87.48
87.48
vdda\_pll\_power
1.8
62.48
62.48
62.48
vdd\_shv5\_power
3.3
199.95
199.95
199.95
vdd\_shv8\_power
3.3
0
0
0
vdda\_usb3v3\_power
3.3
24.99
24.99
24.99
**SoC Power without DDR3L**
2349.42
2629.35
3547.87
evm\_vdd\_ddr\_power
1.35
674.84
667.34
574.86
j6\_vdd\_ddr\_power
1.35
422.4
428.65
474.88
**Total Power**
3446.66
3725.34
4597.61
.. rubric:: Video + Audio
   :name: video-audio-2

Video and Audio decode test case decodes the MPEG4 video content and
displays it on the LCD and also decodes the audio content and output
through the audio jack.

**Simplified View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
AVS
662.34
671.09
668.59
vdd\_gpu\_iva\_dspeve\_power
AVS
162.46
162.46
162.46
vdd\_mpu\_power
DVFS
267.43
124.97
1192.21
1.8V I/O
1.8
447.39
449.89
472.38
3.3V I/O
3.3
239.94
224.94
224.94
**SoC Power without DDR3L**
1779.56
1633.35
2720.58
evm\_vdd\_ddr\_power
1.35
297.43
287.43
329.92
j6\_vdd\_ddr\_power
1.35
289.93
306.18
307.42
**Total Power**
2366.92
2226.96
3357.92
**Detailed View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
AVS
662.34
671.09
668.59
vdd\_gpu\_iva\_dspeve\_power
AVS
162.46
162.46
162.46
vdd\_mpu\_power
DVFS
267.43
124.97
1192.21
evm\_vdd\_1v8\_power
1.8
24.99
24.99
24.99
j6\_vdd\_1v8\_power
1.8
134.97
137.47
159.96
vdda\_1v8\_phy2\_power
1.8
137.47
137.47
137.47
vdda\_phy\_power
1.8
87.48
87.48
87.48
vdda\_pll\_power
1.8
62.48
62.48
62.48
vdd\_shv5\_power
3.3
199.95
199.95
199.95
vdd\_shv8\_power
3.3
15
0
0
vdda\_usb3v3\_power
3.3
24.99
24.99
24.99
**SoC Power without DDR3L**
1779.56
1633.35
2720.58
evm\_vdd\_ddr\_power
1.35
297.43
287.43
329.92
j6\_vdd\_ddr\_power
1.35
289.93
306.18
307.42
**Total Power**
2366.92
2226.96
3357.92
.. rubric:: 3D Graphics
   :name: d-graphics-2

3D graphics test case is the processor executes 3D graphics and display
the content in the LCD.

**Simplified View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
AVS
698.58
694.21
703.58
vdd\_gpu\_iva\_dspeve\_power
AVS
238.69
228.07
245.57
vdd\_mpu\_power
DVFS
128.72
188.08
283.06
1.8V I/O
1.8
477.39
475.51
481.76
3.3V I/O
3.3
261.18
261.81
264.31
**SoC Power without DDR3L**
1804.56
1847.68
1978.28
evm\_vdd\_ddr\_power
1.35
453.64
430.52
444.89
j6\_vdd\_ddr\_power
1.35
364.91
358.67
368.66
**Total Power**
2623.11
2636.87
2791.83
**Detailed View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
AVS
698.58
694.21
703.58
vdd\_gpu\_iva\_dspeve\_power
AVS
238.69
228.07
245.57
vdd\_mpu\_power
DVFS
128.72
188.08
283.06
evm\_vdd\_1v8\_power
1.8
24.99
24.99
24.99
j6\_vdd\_1v8\_power
1.8
152.47
150.59
156.84
vdda\_1v8\_phy2\_power
1.8
137.47
137.47
137.47
vdda\_phy\_power
1.8
87.48
87.48
87.48
vdda\_pll\_power
1.8
74.98
74.98
74.98
vdd\_shv5\_power
3.3
236.19
236.82
239.32
vdd\_shv8\_power
3.3
0
0
0
vdda\_usb3v3\_power
3.3
24.99
24.99
24.99
**SoC Power without DDR3L**
1804.56
1847.68
1978.28
evm\_vdd\_ddr\_power
1.35
453.64
430.52
444.89
j6\_vdd\_ddr\_power
1.35
364.91
358.67
368.66
**Total Power**
2623.11
2636.87
2791.83
.. rubric:: Low Power Modes - Suspend and Standby
   :name: low-power-modes---suspend-and-standby-1

Standby and Suspend modes both put the processor into a low-power state.
DDR is in self-refresh.

**Simplified View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**Suspend-to-RAM**
**Power (mW)**
vdd\_core\_power
AVS
184.84
vdd\_gpu\_iva\_dspeve\_power
AVS
0
vdd\_mpu\_power
DVFS
24.99
1.8V I/O
1.8
124.97
3.3V I/O
3.3
137.47
**SoC Power without DDR3L**
472.27
evm\_vdd\_ddr\_power
1.35
195.94
j6\_vdd\_ddr\_power
1.35
161.97
**Total Power**
830.18
**Detailed View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**Suspend-to-RAM**
**Power (mW)**
vdd\_core\_power
AVS
184.84
vdd\_gpu\_iva\_dspeve\_power
AVS
0
vdd\_mpu\_power
DVFS
24.99
evm\_vdd\_1v8\_power
1.8
0
j6\_vdd\_1v8\_power
1.8
87.48
vdda\_1v8\_phy2\_power
1.8
0
vdda\_phy\_power
1.8
0
vdda\_pll\_power
1.8
37.49
vdd\_shv5\_power
3.3
137.47
vdd\_shv8\_power
3.3
0
vdda\_usb3v3\_power
3.3
0
**SoC Power without DDR3L**
472.27
evm\_vdd\_ddr\_power
1.35
195.94
j6\_vdd\_ddr\_power
1.35
161.97
**Total Power**
830.18
| 

.. rubric:: AM572x
   :name: am572x

Power measurement data for AM572x was taken using an internal EVM
running a trimmed down version of `Processor SDK
V4.0 <http://www.ti.com/tool/PROCESSOR-SDK-AM57X>`__. Data presented
here should be representative of power consumption of AM572x family of
devices. The internal EVM allows finer measurement granularity.

.. rubric:: Summary
   :name: summary-3

| The summary shows total SoC power consumption at all MPU frequencies.
| Please note, these test cases have not been optimized for low power!

.. rubric:: SoC-only power
   :name: soc-only-power-3

SoC-only power does not include power from DDR.

**Power Rail**
**2017.01**
**dra7xx-evm**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
OS Idle
1617.08
1679.57
1919.51
Dhrystone
2349.4
2774.31
3786.56
Network Load
1579.59
1675.82
1915.76
Memory Tester
2541.87
3039.25
3971.52
Video + Audio
1779.56
1633.35
2720.58
3D Graphics
1890.79
2148.24
2084.48
Suspend-to-RAM
299.92
.. rubric:: OS Idle (Matrix GUI)
   :name: os-idle-matrix-gui-3

OS Idle is the case where no active userspace tasks are active. The
system is idle with the Matrix GUI application displayed on the LCD.
Note: having the LCD active will consume extra power.

**Simplified View**

**2017.01**
**dra7xx-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
core\_vdd\_power
AVS
609.85
611.1
612.35
vdd\_dspeve\_power
AVS
0
0
0
vdd\_gpu\_power
AVS
187.45
187.45
187.45
vdd\_iva\_power
AVS
24.99
24.99
24.99
vdd\_mpu\_power
DVFS
187.45
249.94
474.88
1.8V I/O
1.8
449.88
449.88
462.38
3.3V I/O
3.3
157.46
156.21
157.46
**SoC Power without DDR3L**
1617.08
1679.57
1919.51
evm\_vdd\_ddr\_power
1.35
346.17
341.17
337.42
j6\_vdd\_ddr\_power
1.35
523.62
529.87
529.87
**Total Power**
2486.87
2550.61
2786.8
**Detailed View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
core\_vdd\_power
AVS
609.85
611.1
612.35
vdd\_dspeve\_power
AVS
0
0
0
vdd\_gpu\_power
AVS
187.45
187.45
187.45
vdd\_iva\_power
AVS
24.99
24.99
24.99
vdd\_mpu\_power
DVFS
187.45
249.94
474.88
vdd\_shv\_power
3.3
132.47
131.22
132.47
vdda\_1v8\_phy\_power
1.8
199.95
199.95
199.95
vdda\_1v8\_pll\_power
1.8
62.48
62.48
62.48
vdds18v\_power
1.8
187.45
187.45
199.95
vusb\_3v3\_power
3.3
24.99
24.99
24.99
**SoC Power without DDR3L**
1617.08
1679.57
1919.51
evm\_vdd\_ddr\_power
1.35
346.17
341.17
337.42
j6\_vdd\_ddr\_power
1.35
523.62
529.87
529.87
**Total Power**
2486.87
2550.61
2786.8
.. rubric:: Dhrystone
   :name: dhrystone-4

Dhrystone test case is typically be one of the most power-intensive
applications and used here to approximate worst-case power consumption
of the processor. Note: DDR3 is not exercised in this test case, however
test data has shown where DDR bandwidth is high, MPU utilization drops,
and total power consumption typically does not exceed Dhrystone.

**Simplified View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
core\_vdd\_power
AVS
609.85
612.35
612.35
vdd\_dspeve\_power
AVS
0
0
0
vdd\_gpu\_power
AVS
187.45
187.45
187.45
vdd\_iva\_power
AVS
24.99
24.99
24.99
vdd\_mpu\_power
DVFS
924.77
1329.68
2336.93
1.8V I/O
1.8
449.88
462.38
469.88
3.3V I/O
3.3
152.46
157.46
154.96
**SoC Power without DDR3L**
2349.4
2774.31
3786.56
evm\_vdd\_ddr\_power
1.35
349.91
336.17
337.42
j6\_vdd\_ddr\_power
1.35
532.37
537.37
534.87
**Total Power**
3231.68
3647.85
4658.85
**Detailed View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
core\_vdd\_power
AVS
609.85
612.35
612.35
vdd\_dspeve\_power
AVS
0
0
0
vdd\_gpu\_power
AVS
187.45
187.45
187.45
vdd\_iva\_power
AVS
24.99
24.99
24.99
vdd\_mpu\_power
DVFS
924.77
1329.68
2336.93
vdd\_shv\_power
3.3
127.47
132.47
129.97
vdda\_1v8\_phy\_power
1.8
199.95
199.95
199.95
vdda\_1v8\_pll\_power
1.8
62.48
62.48
62.48
vdds18v\_power
1.8
187.45
199.95
207.45
vusb\_3v3\_power
3.3
24.99
24.99
24.99
**SoC Power without DDR3L**
2349.4
2774.31
3786.56
evm\_vdd\_ddr\_power
1.35
349.91
336.17
337.42
j6\_vdd\_ddr\_power
1.35
532.37
537.37
534.87
**Total Power**
3231.68
3647.85
4658.85
.. rubric:: Network Load
   :name: network-load-3

Network load is the test case where the data is being transmitted
through Ethernet.

**Simplified View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
core\_vdd\_power
AVS
609.85
612.35
612.35
vdd\_dspeve\_power
AVS
0
0
0
vdd\_gpu\_power
AVS
187.45
187.45
187.45
vdd\_iva\_power
AVS
24.99
24.99
24.99
vdd\_mpu\_power
DVFS
162.46
249.94
474.88
1.8V I/O
1.8
449.88
449.88
459.88
3.3V I/O
3.3
144.96
151.21
156.21
**SoC Power without DDR3L**
1579.59
1675.82
1915.76
evm\_vdd\_ddr\_power
1.35
339.92
342.42
334.92
j6\_vdd\_ddr\_power
1.35
522.37
532.37
537.37
**Total Power**
2441.88
2550.61
2788.05
**Detailed View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
core\_vdd\_power
AVS
609.85
612.35
612.35
vdd\_dspeve\_power
AVS
0
0
0
vdd\_gpu\_power
AVS
187.45
187.45
187.45
vdd\_iva\_power
AVS
24.99
24.99
24.99
vdd\_mpu\_power
DVFS
162.46
249.94
474.88
vdd\_shv\_power
3.3
119.97
126.22
131.22
vdda\_1v8\_phy\_power
1.8
199.95
199.95
199.95
vdda\_1v8\_pll\_power
1.8
62.48
62.48
62.48
vdds18v\_power
1.8
187.45
187.45
197.45
vusb\_3v3\_power
3.3
24.99
24.99
24.99
**SoC Power without DDR3L**
1579.59
1675.82
1915.76
evm\_vdd\_ddr\_power
1.35
339.92
342.42
334.92
j6\_vdd\_ddr\_power
1.35
522.37
532.37
537.37
**Total Power**
2441.88
2550.61
2788.05
.. rubric:: Memory Tester
   :name: memory-tester-3

This test case executes the DDR memory data transactions.

**Simplified View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
core\_vdd\_power
AVS
649.84
667.34
649.84
vdd\_dspeve\_power
AVS
0
0
24.99
vdd\_gpu\_power
AVS
187.45
187.45
199.95
vdd\_iva\_power
AVS
24.99
24.99
24.99
vdd\_mpu\_power
DVFS
997.26
1448.4
2391.92
1.8V I/O
1.8
524.87
544.86
522.37
3.3V I/O
3.3
157.46
166.21
157.46
**SoC Power without DDR3L**
2541.87
3039.25
3971.52
evm\_vdd\_ddr\_power
1.35
667.34
708.58
541.12
j6\_vdd\_ddr\_power
1.35
729.82
753.57
684.83
**Total Power**
3939.03
4501.4
5197.47
**Detailed View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
core\_vdd\_power
AVS
649.84
667.34
649.84
vdd\_dspeve\_power
AVS
0
0
24.99
vdd\_gpu\_power
AVS
187.45
187.45
199.95
vdd\_iva\_power
AVS
24.99
24.99
24.99
vdd\_mpu\_power
DVFS
997.26
1448.4
2391.92
vdd\_shv\_power
3.3
132.47
141.22
132.47
vdda\_1v8\_phy\_power
1.8
199.95
199.95
199.95
vdda\_1v8\_pll\_power
1.8
62.48
62.48
62.48
vdds18v\_power
1.8
262.44
282.43
259.94
vusb\_3v3\_power
3.3
24.99
24.99
24.99
**SoC Power without DDR3L**
2541.87
3039.25
3971.52
evm\_vdd\_ddr\_power
1.35
667.34
708.58
541.12
j6\_vdd\_ddr\_power
1.35
729.82
753.57
684.83
**Total Power**
3939.03
4501.4
5197.47
.. rubric:: Video + Audio
   :name: video-audio-3

Video and Audio decode test case decodes the MPEG4 video content and
displays it on the LCD and also decodes the audio content and output
through the audio jack.

**Simplified View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
AVS
662.34
671.09
668.59
vdd\_gpu\_iva\_dspeve\_power
AVS
162.46
162.46
162.46
vdd\_mpu\_power
DVFS
267.43
124.97
1192.21
1.8V I/O
1.8
447.39
449.89
472.38
3.3V I/O
3.3
239.94
224.94
224.94
**SoC Power without DDR3L**
1779.56
1633.35
2720.58
evm\_vdd\_ddr\_power
1.35
297.43
287.43
329.92
j6\_vdd\_ddr\_power
1.35
289.93
306.18
307.42
**Total Power**
2366.92
2226.96
3357.92
**Detailed View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
vdd\_core\_power
AVS
662.34
671.09
668.59
vdd\_gpu\_iva\_dspeve\_power
AVS
162.46
162.46
162.46
vdd\_mpu\_power
DVFS
267.43
124.97
1192.21
evm\_vdd\_1v8\_power
1.8
24.99
24.99
24.99
j6\_vdd\_1v8\_power
1.8
134.97
137.47
159.96
vdda\_1v8\_phy2\_power
1.8
137.47
137.47
137.47
vdda\_phy\_power
1.8
87.48
87.48
87.48
vdda\_pll\_power
1.8
62.48
62.48
62.48
vdd\_shv5\_power
3.3
199.95
199.95
199.95
vdd\_shv8\_power
3.3
15
0
0
vdda\_usb3v3\_power
3.3
24.99
24.99
24.99
**SoC Power without DDR3L**
1779.56
1633.35
2720.58
evm\_vdd\_ddr\_power
1.35
297.43
287.43
329.92
j6\_vdd\_ddr\_power
1.35
289.93
306.18
307.42
**Total Power**
2366.92
2226.96
3357.92
.. rubric:: 3D Graphics
   :name: d-graphics-3

3D graphics test case is the processor executes 3D graphics and display
the content in the LCD.

**Simplified View**

**2017.01**
**dra7xx-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
core\_vdd\_power
AVS
637.35
655.47
605.48
vdd\_dspeve\_power
AVS
0
0
0
vdd\_gpu\_power
AVS
386.16
491.76
295.55
vdd\_iva\_power
AVS
24.99
24.99
24.99
vdd\_mpu\_power
DVFS
179.96
311.18
524.25
1.8V I/O
1.8
474.88
481.76
462.38
3.3V I/O
3.3
187.45
183.08
171.83
**SoC Power without DDR3L**
1890.79
2148.24
2084.48
evm\_vdd\_ddr\_power
1.35
602.36
567.36
449.89
j6\_vdd\_ddr\_power
1.35
661.09
651.72
563.61
**Total Power**
3154.24
3367.32
3097.98
**Detailed View**

**2017.01**
**dra72x-evm**
**Power Rail**
**Voltage**
**MPU OPP\_NOM (1000MHz)**
**MPU OPP\_OD (1176MHz)**
**MPU OPP\_HIGH (1500MHz)**
**Power (mW)**
**Power (mW)**
**Power (mW)**
Suspend-to-RAM
**Power (mW)**
core\_vdd\_power
AVS
637.35
655.47
605.48
vdd\_dspeve\_power
AVS
0
0
0
vdd\_gpu\_power
AVS
386.16
491.76
295.55
vdd\_iva\_power
AVS
24.99
24.99
24.99
vdd\_mpu\_power
DVFS
179.96
311.18
524.25
vdd\_shv\_power
3.3
162.46
158.09
146.84
vdda\_1v8\_phy\_power
1.8
199.95
199.95
193.7
vdda\_1v8\_pll\_power
1.8
62.48
62.48
62.48
vdds18v\_power
1.8
212.45
219.33
206.2
vusb\_3v3\_power
3.3
24.99
24.99
24.99
**SoC Power without DDR3L**
1890.79
2148.24
2084.48
evm\_vdd\_ddr\_power
1.35
602.36
567.36
449.89
j6\_vdd\_ddr\_power
1.35
661.09
651.72
563.61
**Total Power**
3154.24
3367.32
3097.98
.. rubric:: Low Power Modes - Suspend and Standby
   :name: low-power-modes---suspend-and-standby-2

Standby and Suspend modes both put the processor into a low-power state.
DDR is in self-refresh.

**Simplified View**

**2017.01**
**dra7xx-evm**
**Power Rail**
**Voltage**
**Suspend-to-RAM**
**Power (mW)**
core\_vdd\_power
AVS
124.97
vdd\_dspeve\_power
AVS
0
vdd\_gpu\_power
AVS
0
vdd\_iva\_power
AVS
0
vdd\_mpu\_power
DVFS
24.99
1.8V I/O
1.8
112.47
3.3V I/O
3.3
37.49
**SoC Power without DDR3L**
299.92
evm\_vdd\_ddr\_power
1.35
87.48
j6\_vdd\_ddr\_power
1.35
389.91
**Total Power**
777.31
**Detailed View**

**2017.01**
**dra7xx-evm**
**Power Rail**
**Voltage**
**Suspend-to-RAM**
**Power (mW)**
core\_vdd\_power
AVS
124.97
vdd\_dspeve\_power
AVS
0
vdd\_gpu\_power
AVS
0
vdd\_iva\_power
AVS
0
vdd\_mpu\_power
DVFS
24.99
vdd\_shv\_power
3.3
37.49
vdda\_1v8\_phy\_power
1.8
0
vdda\_1v8\_pll\_power
1.8
24.99
vdds18v\_power
1.8
87.48
vusb\_3v3\_power
3.3
0
**SoC Power without DDR3L**
299.92
evm\_vdd\_ddr\_power
1.35
87.48
j6\_vdd\_ddr\_power
1.35
389.91
**Total Power**
777.31
| 

