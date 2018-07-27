.. http://processors.wiki.ti.com/index.php/Processor_SDK_LINUX_PTP
   
Overview
===========

The Precision Time Protocol (PTP), defined in IEEE 1588, is a protocol
used to synchronize clocks throughout a network. Many applications in
Industrial automation, Grid Infrastructure, Motion Control, AVB, and
Telecom markets require nano-second accuracy/precision, varied update
rates, rapid reconfiguration after network changes, fault tolerance.
TI's Sitara hardware platforms have dedicated hardware/firmware that
help us meet these stringent requirements for synchronizing the
distributed real-time clocks, in conjunction with LinuxPTP Application
Stack. This page is specific to the PTP implementation in Linux, and the
following sections provide details about the Software Architecture,
Supported platforms, test setup and details about the support for
Ordinary Clock (OC), Boundary Clock (BC) And Transparent Clock (TC)

Software Overview
=================

The picture below shows the Linux software stack of HSR/PRP/PTP in
Processor SDK.

.. Image:: ../images/Software-arch-v1.jpg

Software Components
--------------------

-  PRUETH driver – Kernel driver abstracts PRU hardware/firmware
-  PRUPTP driver – Kernel driver abstracts PRU-ICSS based PTP support
-  CPTS driver - Kernel driver abstracts CPSW/CPTS based PTP support
-  BC driver – Responsible for port state changes, IO Pad configuration
-  HSR/PRP driver – Upstream HSR driver, with PRP support and additional
   bug fixes
-  iproute2 - a collection of userspace utilities for controlling and
   monitoring various aspects of networking in the Linux kernel,
   including routing, network interfaces, tunnels, traffic control, and
   network-related device drivers
-  net-snmp - a suite of software for using and deploying the SNMP
   protocol
-  linuxptp (ptp4l, phc2sys)
-  Filesystem (/dev/ppsX, /dev/ptpX)

linuxptp Overview
-----------------

The Linux PTP Project is a software implementation of the PTP according
to the IEEE 1588 Standard. This software is licensed under GNU GPL
License, as described in the Processor SDK Software Manifest. For more
details on Linux PTP framework and implementation refer:
http://linuxptp.sourceforge.net/

LinuxPTP provides the four user applications - ptp4l, phc2sys,
hwstamp\_ctl and pmc. The definition and usage of these applications is
as follows:

-  ptp4l: It is the main program that implements the Precision Time
   Protocol (PTP) according to IEEE standard 1588 for Linux, as a
   Boundary Clock (BC) and Ordinary Clock (OC). The 'slave' and 'master'
   roles are determined for each port automatically using the BMC
-  phc2sys: It is a utility program to synchronize the normal Linux
   system time to a PTP Hardware Clock - which itself is synchronized by
   the ptp4l program/application. For phc2sys, the terms 'slave' and
   'master' are not about the PTP, but rather about two local clocks.
   Usually, the Linux system time is the slave, and the PHC is the
   master.
-  pmc: This is a utility program for sending PTP management queries.
   The program reads from the standard input actions specified by name
   and management ID, sends them over the selected transport and prints
   any received replies.
-  hwstamp\_ctl: It is just a test program for the SIOCSHWTSTAMP ioctl,
   used for debugging. The ptp4l program does not need this program to
   function

TI has forked LinuxPTP to add support for Sitara family of devices, and
the repo is hosted here: http://git.ti.com/processor-sdk/linuxptp

Hardware Overview
=================

TI’s Sitara devices have support for GMAC and PRU-ICSS ports, as shown
in the table below.

+--------------------------+--------------------------+--------------------------+
| SoC                      | # of GMAC ports          | # of PRU-ICSS ports      |
+==========================+==========================+==========================+
| AM571x                   | 1                        | 2(at 100Mbps)            |
+--------------------------+--------------------------+--------------------------+
| AM572x                   | 1                        | 1(at 100Mbps)            |
+--------------------------+--------------------------+--------------------------+
| AM574x                   | 1                        | 2(at 100Mbps)            |
+--------------------------+--------------------------+--------------------------+

GMAC
-----

GMAC interface can be configured to run at either 100 Mbps or 1 Gbps.
CPTS hardware block helps with timestamping of packets. Refer to :ref:`PLSDK_CPTS_Module-label`
for details.

PRU-ICSS
---------

The processing load is shared between firmware (PRU) and Host (ARM) with
the firmware doing most of the time critical activities. The IEP
hardware block in the PRU-ICSS sub-system is responsible for
timestamping of packets. Memory map for the firmware interface can be
found in :ref:`HSR_PRP_Firmware_Memory_Map_label`.  

.. _PLSDK_PTP_HW_Mods-label:

Hardware Modifications
----------------------
-   Hardware modifications are required on the AM57xx IDK platforms to provide 
    access points to 1 PPS sync and latch signals for CPSW/CPTS and PRU-ICSS modules
-   For Boundary Clock, since PPS generated by one internal clock needs to be latched 
    into another internal clock, hardware, mainly blue wire, modifications are needed 
    in order to achieive the latching of the PPS generated by one internal clock into 
    another internal clock.

Please refer to AM571x-IDK modifications and AM572x-IDK modifications documents and
make the recommended changes to verify OC and BC, and to get access to 1 PPS signals

Generating 1 PPS
================

The PPS (Pulse Per Second) or 1PPS signal is an electrical signal that
has a width of less than one second and a sharply rising or abruptly
falling edge at the second boundary. The PPS signal can be used to
measure the offset and jitters of the system time between the master and
slave clock. This signal can also be used to synchronize the slave clock
to its master within a BC.

PRU-ICSS
---------

IEP has an additional hardware to generate a programmable sync output
which is tied to the IEP counter. This is called the SYNC unit. For this
signal generation CMP1 is programmed to a value of 1 second. A HIT event
is generated by PRU0. Linux PRUETH IEP driver checks this event in and
re-programs CMP1 after every hit to ensure that accurate sync pulses are
generated. This sync is equivalent to the 1PPS output and should not be
confused with PTP Sync frame.

To enable/disable 1PPS signal on PRU-ICSS port, enter the following
commands respectively

::

    echo 1 > /sys/devices/platform/pruss2_eth/ptp/ptp1/pps_enable
    echo 0 > /sys/devices/platform/pruss2_eth/ptp/ptp1/pps_enable
    or
    echo 1 > /sys/devices/platform/pruss2_eth/ptp/ptp2/pps_enable
    echo 0 > /sys/devices/platform/pruss2_eth/ptp/ptp2/pps_enable

::

    echo 1 > /sys/devices/platform/pruss1_eth/ptp/ptp2/pps_enable
    echo 0 > /sys/devices/platform/pruss1_eth/ptp/ptp2/pps_enable
    or
    echo 1 > /sys/devices/platform/pruss1_eth/ptp/ptp1/pps_enable
    echo 0 > /sys/devices/platform/pruss1_eth/ptp/ptp1/pps_enable

Please note that both ptp1/2 may be assigned to pruss1(2)\_eth based on
the order of operations. Use the following command to find out the
assigned PTP ports.

::

    ls /sys/devices/platform/pruss1_eth/ptp
    ls /sys/devices/platform/pruss2_eth/ptp

GMAC
------

The GMAC/CPTS does not support a programmable sync output. Instead, the
GP Timer16 can be programmed to generate an output pulse every 100ms or
second and then this signal is passed to CPTS/HW\_TS\_PUSH4 to trigger
the HW\_TS\_PUSH event. Linux CPSW/CPTS driver checks this event in and
run through a simple algorithm to adjust the GP Timer reload value after
every hit to ensure that output sync pulse is aligned at the second
boundary of the PTP system time. In order to satisfy the +/-50ns jitter
requirement by reducing the accumulation error, the current 1PPS
implementation will generate a output pulse every 100ms and 9 out of 10
pulses will be filtered out except the one at the second boundary
through the pad-config or GPIO-based output control.

To enable/disable 1PPS signal on GMAC/CPTS, enter the following command
respectively:

::

    echo 1 > /sys/devices/platform/44000000.ocp/48484000.ethernet/ptp/ptp0/pps_enable
    echo 0 > /sys/devices/platform/44000000.ocp/48484000.ethernet/ptp/ptp0/pps_enable

PPS Output Latency Configuration
---------------------------------

It should be possible to configure the latency of the 1PPS output of
GMAC, PRU_ICSS to compensate for local propagation delay or for testing
purpose. A new PTP interface has been defined and implemented to allow
the PPS output latency to be adjusted in unit of ns.

The PPS output latency adjustment called PPS Offset can be set through
the command interface or as the port configuration parameter of linuxptp.

To set PPS offset to -10ns on PRU-ICSS port, enter the following command:

::

    echo -10 > /sys/devices/platform/pruss2_eth/ptp/ptp1/pps_offset


To set PPS offset to 10ns on GMAC/CPTS port, enter the following command:

::

    echo 10 > /sys/devices/platform/44000000.ocp/48484000.ethernet/ptp/ptp0/pps_offset

To configure the PPS offset of eth2 to 20ns, add the following line to
the OC/BC configuration file

::

    [eth2]
    ppsOffset 20


.. _PLSDK_PTP_OC-label:

PTP Ordinary Clock
==================

PTP ordinary clock (OC) is supported on both the CPSW GMAC ports and the
PRU-ICSS ports.

The **IEEE-1588-2009** standard defines **ordinary clock** as "A clock
that has a single Precision Time Protocol (PTP) port in a domain and
maintains the timescale used in the domain. It may serve as a source of
time, i.e., be a master clock, or may synchronize to another clock,
i.e., be a slave clock."

At the heart of the ordinary clock support is the capability of being
able to timestamp the PTP event messages that passes through the
different Ethernet ports. It is the CPTS module that does the
timestamping for the CPSW GMAC ports. For PRU-ICSS ports, it is the IEP
module together with the PRU firmware that does the timestamping.

.. rubric:: PHY Delay Compensation
   :name: phy-delay-compensation

The IEEE1588 timestamp should be measured at the Ethernet wire and
therefore the ideal place to measure the egress/ingress timestamp of the
Ethernet packets is at the Ethernet PHY. Unfortunately it is usually not
the case. The delay between the actual timestamp location and the ideal
location at the Ethernet wire will add to the path delay and create
error of the path delay and offset of the system timestamp if the egress
and ingress delay is not symmetric.

The Linux PTP software stack is designed to handle those delays with
environment variable egressLatency and ingressLatency. Both delay number
should be calculated or measured and used at the PTP configuration file.
In the case that those two number are not available, use the following
formulas to adjust those two variables as long as the measured path
delay by Linux PTP is positive.

::

    To reduce the 1PPS offset by x, increase the asymmetry delay compensation by 2x
    To reduce the end-to-end delay by y, increase both ingressLatency and egressLatency by y.

PTP Ordinary Clock on PRU-ICSS
------------------------------

Timestamping of PTP event messages at the PRU-ICSS ports is provided by
the PRU-ICSS IEP module together with the PRU firmware. More precisely,
the PRU-PRP firmware is used and is configured in SAN (Single Attached
Node) mode.

In this Linux PRU-ICSS OC implementation, the PRU firmware stores
timestamps (IEP counter values) of PTP event messages in specific shared
memory locations. The PRU IEP driver retrieves the timestamps and
converts them into PTP time values (in nanoseconds) before they are
passed to upper layer for further processing. The current PRU-ICSS PTP
clock frequency and time scale are kept in the IEP driver.

Since the PRU IEP drivers implements the Linux PTP hardware clock
subsystem APIs, the PRU-ICSS PTP clock can therefore be adjusted by
using those standard APIs. See `PTP hardware clock infrastructure for
Linux <https://www.kernel.org/doc/Documentation/ptp/ptp.txt#>`__ for
more details.

The PTP OC protocol is provided by the linuxptp application.

Follow the steps at :ref:`PLSDK_PRP_EMAC_Mode-label`
to boot up the AM57xx IDK and configure the PRU-PRP firmware to run in
**PRP\_EMAC** mode. Once the AM57xx IDK is boot into Linux kernel prompt
and the PRU-ICSS Ethernet ports are properly configured, to run linuxptp
over the PRU-ICSS Ethernet ports, do

::

    ptp4l -2 -P -f oc.cfg

oc.cfg is a ptp4l configuration file.

Example oc.cfg for OC,

::

    [global]
    tx_timestamp_timeout 10
    logMinPdelayReqInterval -3
    logSyncInterval -3
    twoStepFlag 1
    summary_interval 0
    [eth2]
    egressLatency 726
    ingressLatency 186

where **eth2** is the intended PRU-ICSS Ethernet port over which the OC
functionality is provided.

See `The Linux PTP Project <http://linuxptp.sourceforge.net#>`__ for
more details about linuxptp in general and `ptp4l(8) - Linux man
page <https://man.cx/ptp4l>`__ about ptp4l configurations in particular.

Here is a sample screen display of ptp4l for PRU-ICSS Ethernet port as
PTP/OC in slave mode:

::

    ptp4l -2 -P -f oc_eth2.txt -s -m &
    [1] 1153
    root@am57xx-evm:~# ptp4l[3777.676]: selected /dev/ptp1 as PTP clock
    ptp4l[3777.740]: port 1: INITIALIZING to LISTENING on INIT_COMPLETE
    ptp4l[3777.743]: port 0: INITIALIZING to LISTENING on INIT_COMPLETE
    ptp4l[3777.744]: port 1: received PDELAY_REQ without timestamp
    ptp4l[3778.727]: port 1: new foreign master 8ca5a1.fffe.0000c2-1
    ptp4l[3782.727]: selected best master clock 8ca5a1.fffe.0000c2
    ptp4l[3782.727]: port 1: LISTENING to UNCALIBRATED on RS_SLAVE
    ptp4l[3783.028]: port 1: UNCALIBRATED to SLAVE on MASTER_CLOCK_SELECTED
    ptp4l[3783.653]: rms 756344481817248256 max 1512688963634496512 ( -31, 1512688963634496512) freq  +2319 +/- 877 delay    12 +/-   0
    ptp4l[3784.653]: rms   28 max   32 ( -32,  -22) freq  +2612 +/-   9 delay    12 +/-   0
    ptp4l[3785.778]: rms   16 max   24 ( -24,  -11) freq  +2604 +/-   3 delay    12 +/-   0
    ptp4l[3786.778]: rms    6 max    9 (  -9,   -1) freq  +2607 +/-   3 delay    12 +/-   1
    ptp4l[3787.904]: rms    3 max    6 (  -6,    4) freq  +2612 +/-   5 delay    12 +/-   0
    ptp4l[3788.904]: rms    6 max   11 (   4,   11) freq  +2624 +/-   2 delay    12 +/-   0
    ptp4l[3789.904]: rms    4 max    7 (  -2,    7) freq  +2621 +/-   5 delay    12 +/-   0
    ptp4l[3790.904]: rms    5 max   10 ( -10,    2) freq  +2613 +/-   5 delay    11 +/-   0
    ptp4l[3791.904]: rms    6 max   10 ( -10,    0) freq  +2606 +/-   4 delay    12 +/-   1
    ptp4l[3792.904]: rms    3 max    6 (  -4,    6) freq  +2610 +/-   4 delay    11 +/-   1
    ptp4l[3793.904]: rms    6 max   11 (   0,   11) freq  +2618 +/-   6 delay    12 +/-   0
    ptp4l[3794.904]: rms    4 max    8 (  -5,    8) freq  +2618 +/-   5 delay    11 +/-   1
    ptp4l[3796.029]: rms    3 max    6 (  -6,    4) freq  +2614 +/-   4 delay    12 +/-   1
    ptp4l[3797.029]: rms    3 max    5 (  -5,    5) freq  +2614 +/-   4 delay    12 +/-   1
    ptp4l[3798.030]: rms    2 max    4 (  -4,    3) freq  +2614 +/-   3 delay    12 +/-   0
    ptp4l[3799.030]: rms    3 max    6 (  -4,    6) freq  +2616 +/-   4 delay    12 +/-   0
    ptp4l[3800.030]: rms    3 max    5 (  -5,    5) freq  +2615 +/-   4 delay    10 +/-   0
    ptp4l[3801.030]: rms    4 max    8 (  -8,    2) freq  +2609 +/-   5 delay    10 +/-   1
    ptp4l[3802.030]: rms    7 max   12 ( -12,    3) freq  +2603 +/-   7 delay    11 +/-   0
    ptp4l[3803.030]: rms    4 max    7 (  -7,    3) freq  +2601 +/-   4 delay    12 +/-   0
    ptp4l[3804.030]: rms    4 max    7 (  -7,    4) freq  +2599 +/-   5 delay    13 +/-   1
    ptp4l[3805.030]: rms    6 max    9 (  -8,    9) freq  +2600 +/-   8 delay    12 +/-   0
    ptp4l[3806.030]: rms    5 max   10 (   0,   10) freq  +2609 +/-   4 delay    12 +/-   0
    ptp4l[3807.030]: rms    5 max   10 ( -10,    6) freq  +2604 +/-   7 delay    12 +/-   0
    ptp4l[3808.030]: rms    6 max    8 (  -8,   -1) freq  +2594 +/-   3 delay    11 +/-   0
    ptp4l[3809.031]: rms    7 max   10 ( -10,   -2) freq  +2587 +/-   4 delay    12 +/-   1
    ptp4l[3810.156]: rms    4 max    8 (  -8,    0) freq  +2587 +/-   4 delay    12 +/-   0
    ptp4l[3811.156]: rms    2 max    4 (  -1,    4) freq  +2591 +/-   3 delay    12 +/-   1
    ptp4l[3812.156]: rms    4 max    7 (  -2,    7) freq  +2596 +/-   4 delay    11 +/-   0
    ptp4l[3813.406]: rms    3 max    6 (  -6,    1) freq  +2588 +/-   3 delay    12 +/-   0
    ptp4l[3814.406]: rms    6 max    7 (  -7,    1) freq  +2582 +/-   5 delay    12 +/-   0
    ptp4l[3815.406]: rms    4 max    7 (  -4,    7) freq  +2588 +/-   5 delay    11 +/-   0
    ptp4l[3816.406]: rms    3 max    4 (  -4,    4) freq  +2587 +/-   4 delay    12 +/-   1
    ptp4l[3817.531]: rms    4 max    6 (  -6,    6) freq  +2590 +/-   5 delay    12 +/-   1
    ptp4l[3818.531]: rms    3 max    5 (  -5,    5) freq  +2587 +/-   4 delay    11 +/-   0
    ptp4l[3819.532]: rms    4 max    5 (  -5,    4) freq  +2584 +/-   4 delay    12 +/-   0
    ptp4l[3820.657]: rms    4 max    7 (  -1,    7) freq  +2592 +/-   3 delay    11 +/-   0
    ptp4l[3821.782]: rms    4 max    9 (  -2,    9) freq  +2594 +/-   5 delay    11 +/-   0
    ptp4l[3822.782]: rms    3 max    5 (  -5,    2) freq  +2589 +/-   4 delay    11 +/-   0
    ...

| 

Some useful commands
^^^^^^^^^^^^^^^^^^^^

To see the availability of ICSS-PRU1 and ICSS-PRU2 on SoC:

::

    root@am57xx-evm:~# ls /sys/devices/platform/

and look for **pruss1\_eth** and/or **pruss2\_eth**.

To see which interface is configured under, for example, ICSS-PRU2:

::

    root@am57xx-evm:~# ls /sys/devices/platform/pruss2_eth/net
    eth2/ eth3/

To see what is available under an ICSS-PRU ptp support:

::

    root@am57xx-evm:~# ls /sys/devices/platform/pruss2_eth/ptp
    ptp1/

::

    root@am57xx-evm:~# ls /sys/devices/platform/pruss2_eth/ptp/ptp1
    clock_name             fifo                   n_periodic_outputs     pps_available
    dev                    max_adjustment         n_programmable_pins    pps_enable
    device@                n_alarms               period                 subsystem@
    extts_enable           n_external_timestamps  power/                 uevent

::

    root@am57xx-evm:~# cat /sys/devices/platform/pruss1_eth/ptp/ptp2/clock_name
    PRUSS1 timer

::

    root@am57xx-evm:~# cat /sys/devices/platform/pruss2_eth/ptp/ptp1/pps_available
    1

If ptp4l is started in the background and without the "-m" option to
print any message to standard output, the system log file
/var/log/messages can be used to get a glimpse of the progress of ptp4l.
For example,

::

    root@am57xx-evm:~# ptp4l -2 -P -f oc.cfg &
    root@am57xx-evm:~# 
    root@am57xx-evm:~# tail -n 30 /var/log/messages
    Dec  5 20:45:14 am57xx-evm daemon.info thttpd[946]:   fdwatch - 729 polls (0.2025/sec)
    Dec  5 20:45:14 am57xx-evm daemon.info thttpd[946]:   timers - 3 allocated, 3 active, 0 free
    Dec  5 20:58:06 am57xx-evm user.notice ptp4l: [83598.805] selected best master clock 70ff76.fffe.1c0f99
    Dec  5 20:58:06 am57xx-evm user.notice ptp4l: [83598.805] port 2: MASTER to UNCALIBRATED on RS_SLAVE
    Dec  5 20:58:06 am57xx-evm user.notice ptp4l: [83599.177] port 2: UNCALIBRATED to SLAVE on MASTER_CLOCK_SELECTED
    Dec  5 20:58:06 am57xx-evm user.info ptp4l: [83599.427] rms 36120 max 72251 (-72251,    8) freq  -7075 +/-  88 delay     8 +/-  0
    Dec  5 20:58:08 am57xx-evm user.info ptp4l: [83600.552] rms   15 max   19 (  11,   19) freq  -7141 +/-   8 delay     8 +/-   0
    Dec  5 20:58:09 am57xx-evm user.info ptp4l: [83601.553] rms    8 max   13 (   1,   13) freq  -7139 +/-   5 delay     8 +/-   0
    Dec  5 20:58:10 am57xx-evm user.info ptp4l: [83602.553] rms    3 max    4 (  -4,    4) freq  -7144 +/-   4 delay     7 +/-   0
    Dec  5 20:58:11 am57xx-evm user.info ptp4l: [83603.553] rms    7 max   11 ( -11,   -4) freq  -7157 +/-   5 delay     8 +/-   0
    Dec  5 20:58:12 am57xx-evm user.info ptp4l: [83604.554] rms    5 max   10 ( -10,    3) freq  -7159 +/-   5 delay     7 +/-   0
    Dec  5 20:58:13 am57xx-evm user.info ptp4l: [83605.554] rms    2 max    4 (  -4,    2) freq  -7156 +/-   3 delay     7 +/-   0
    Dec  5 20:58:14 am57xx-evm user.info ptp4l: [83606.680] rms    3 max    7 (  -7,    1) freq  -7160 +/-   3 delay     8 +/-   0
    Dec  5 20:58:15 am57xx-evm user.info ptp4l: [83607.680] rms    5 max    9 (  -4,    9) freq  -7154 +/-   6 delay     8 +/-   0
    Dec  5 20:58:16 am57xx-evm user.info ptp4l: [83608.680] rms    5 max    9 (   0,    9) freq  -7148 +/-   5 delay     7 +/-   0
    Dec  5 20:58:17 am57xx-evm user.info ptp4l: [83609.681] rms    4 max    6 (  -4,    6) freq  -7149 +/-   5 delay     7 +/-   0
    Dec  5 20:58:18 am57xx-evm user.info ptp4l: [83610.681] rms    2 max    4 (  -2,    4) freq  -7149 +/-   3 delay     7 +/-   0
    Dec  5 20:58:19 am57xx-evm user.info ptp4l: [83611.806] rms    3 max    7 (  -7,    2) freq  -7151 +/-   4 delay     7 +/-   0
    Dec  5 20:58:20 am57xx-evm user.info ptp4l: [83612.807] rms    2 max    4 (  -4,    4) freq  -7150 +/-   3 delay     8 +/-   0
    Dec  5 20:58:21 am57xx-evm user.info ptp4l: [83613.807] rms    3 max    6 (  -2,    6) freq  -7148 +/-   4 delay     8 +/-   0
    Dec  5 20:58:22 am57xx-evm user.info ptp4l: [83614.807] rms    5 max    9 (  -1,    9) freq  -7141 +/-   5 delay     8 +/-   0
    Dec  5 20:58:23 am57xx-evm user.info ptp4l: [83615.808] rms    3 max    6 (  -4,    6) freq  -7143 +/-   4 delay     8 +/-   0
    Dec  5 20:58:24 am57xx-evm user.info ptp4l: [83616.808] rms    2 max    5 (  -5,    1) freq  -7147 +/-   2 delay     7 +/-   0
    Dec  5 20:58:25 am57xx-evm user.info ptp4l: [83617.934] rms    5 max    8 (  -8,    5) freq  -7150 +/-   7 delay     8 +/-   0
    Dec  5 20:58:26 am57xx-evm user.info ptp4l: [83618.934] rms    3 max    5 (  -5,    3) freq  -7153 +/-   3 delay     8 +/-   0
    Dec  5 20:58:27 am57xx-evm user.info ptp4l: [83619.934] rms    5 max    8 (  -1,    8) freq  -7145 +/-   5 delay     7 +/-   1
    Dec  5 20:58:28 am57xx-evm user.info ptp4l: [83620.935] rms    6 max   10 (   2,   10) freq  -7136 +/-   2 delay     6 +/-   0
    Dec  5 20:58:29 am57xx-evm user.info ptp4l: [83621.935] rms    4 max    7 (  -1,    7) freq  -7135 +/-   3 delay     8 +/-   1
    Dec  5 20:58:30 am57xx-evm user.info ptp4l: [83622.935] rms    2 max    3 (  -1,    3) freq  -7136 +/-   2 delay     9 +/-   0
    Dec  5 20:58:31 am57xx-evm user.info ptp4l: [83624.061] rms    4 max    6 (   0,    6) freq  -7131 +/-   3 delay     8 +/-   0
    root@am57xx-evm:~#

PHY Delay Compensation for AM57xx IDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The accuracy of PTP time provided by an OC depends in part on the
accountability of the latencies introduced by the Ethernet of PHY and
the timestamping point at which a PTP event message is timestamped.

IEEE-1588-2009 specifies that timestamp should be taken right after the
SOF (start of frame). For Ethernet this is right after the SFD (start
frame delimiter) or right before the destination MAC address. In the
case of PRU-PRP firmware, only SOF timestampping is available for a TX
PTP event message. And because in a 100 mbps line speed, 1 bit time is
equivalent to 10ns, hence 640 ns ( (7 bytes preamble + 1 byte SFD) \* 8
bits \* 10ns) needs to be compensated in the TX direction.

Furthermore, the PRU-ICSS PHY TLK110 on AM57xx IDK introduces a latency
of 86 ns in the TX and 186 ns in the RX direction.

Thus a total of 640 + 86 = 726 ns in the TX direction and 186 ns in the
RX direction need to be accounted for.

When linuxptp's ptp4l is used as the PTP protocol application, the
following should be used for IngressLatency and EgressLatency
configuration respectively.

+--------------------------+--------------------------+--------------------------+
| Speed                    | Egress Latency (ns)      | Ingress Latency (ns)     |
+==========================+==========================+==========================+
| 100Mb                    | 726                      | 186                      |
+--------------------------+--------------------------+--------------------------+

This also explains the two lines that corresponds to egressLatency and
ingressLatency in the sample ptp4l configuration file oc.cfg in the
ptp4l example above.

Limitations
^^^^^^^^^^^^^

Although there are two Ethernet ports available on each ICSS-PRU
present, ICSS-PRU PTP OC can only be supported on at most **ONE** such
port. It cannot provide PTP OC functionality on both Ethernet ports on
the same ICSS-PRU simultaneously.

PTP Ordinary Clock on GMAC
---------------------------
Refer to :ref:`PLSDK_CPTS_Module-label` for more details about the CPTS driver 
and how to run **linuxptp** over the CPSW GMAC port for providing the PTP OC functionality.

For example, once the AM57xx IDK is boot into Linux kernel prompt and
the CPSW GMAC ports are properly configured, to run linuxptp over the
GMAC port, do

::

    ptp4l -2 -P -f oc_eth1.cfg -s -m

oc\_eth1.cfg is a ptp4l configuration file.

Example oc\_eth1.cfg for OC,

::

    [global]
    tx_timestamp_timeout 10
    logMinPdelayReqInterval -3
    logSyncInterval -3
    twoStepFlag 1
    summary_interval 0
    [et1]
    egressLatency 146
    ingressLatency 246

where **eth1** is the intended GMAC port over which the OC functionality
is provided.

Here is a sample screen display of ptp4l for GMAC port as PTP/OC in
slave mode:

::

    root@am57xx-evm:~# ptp4l -2 -P -f oc_eth1.txt -s -m &
    [1] 1201
    root@am57xx-evm:~# ptp4l[235215.373]: selected /dev/ptp0 as PTP clock
    ptp4l[235215.461]: port 1: INITIALIZING to LISTENING on INITIALIZE
    ptp4l[235215.462]: port 0: INITIALIZING to LISTENING on INITIALIZE
    ptp4l[235215.463]: port 1: link up
    ptp4l[235216.399]: port 1: new foreign master 8ca5a1.fffe.0000c2-1
    ptp4l[235220.400]: selected best master clock 8ca5a1.fffe.0000c2
    ptp4l[235220.400]: port 1: LISTENING to UNCALIBRATED on RS_SLAVE
    ptp4l[235220.701]: port 1: UNCALIBRATED to SLAVE on MASTER_CLOCK_SELECTED
    ptp4l[235221.451]: rms 3003 max 3986 (-3986, -1007) freq   -883 +/- 2090 delay    55 +/-   1
    ptp4l[235222.451]: rms  562 max  873 (-612,  873) freq   +943 +/- 756 delay    54 +/-   1
    ptp4l[235223.451]: rms  935 max  980 ( 838,  980) freq  +2627 +/- 243 delay    54 +/-   0
    ptp4l[235224.451]: rms  593 max  787 ( 366,  787) freq  +2958 +/-  24 delay    54 +/-   0
    ptp4l[235225.451]: rms  192 max  318 (  54,  318) freq  +2777 +/-  69 delay    54 +/-   0
    ptp4l[235226.451]: rms   39 max   62 ( -62,   28) freq  +2572 +/-  50 delay    55 +/-   1
    ptp4l[235227.451]: rms   60 max   68 ( -68,  -52) freq  +2468 +/-  13 delay    55 +/-   0
    ptp4l[235228.452]: rms   36 max   46 ( -46,  -24) freq  +2451 +/-   4 delay    54 +/-   1
    ptp4l[235229.452]: rms   11 max   17 ( -17,    4) freq  +2466 +/-   8 delay    53 +/-   0
    ptp4l[235230.452]: rms    6 max   11 (   2,   11) freq  +2485 +/-   5 delay    54 +/-   0
    ptp4l[235231.452]: rms   11 max   17 (   3,   17) freq  +2501 +/-   4 delay    54 +/-   0
    ptp4l[235232.452]: rms    6 max    8 (  -6,    8) freq  +2496 +/-   7 delay    55 +/-   1
    ptp4l[235233.452]: rms    3 max    4 (  -4,    4) freq  +2492 +/-   4 delay    56 +/-   0
    ptp4l[235234.452]: rms    5 max    9 (  -7,    9) freq  +2492 +/-   7 delay    55 +/-   1
    ptp4l[235235.452]: rms    7 max   10 ( -10,    1) freq  +2481 +/-   4 delay    55 +/-   1
    ptp4l[235236.452]: rms    3 max    6 (  -6,    2) freq  +2482 +/-   4 delay    53 +/-   0
    ptp4l[235237.452]: rms    5 max    8 (  -8,    3) freq  +2478 +/-   5 delay    54 +/-   0
    ptp4l[235238.452]: rms    4 max    7 (  -7,    7) freq  +2482 +/-   6 delay    54 +/-   0
    ptp4l[235239.453]: rms    5 max    9 (  -6,    9) freq  +2486 +/-   6 delay    54 +/-   0
    ptp4l[235240.453]: rms    5 max    9 (  -9,    4) freq  +2480 +/-   6 delay    55 +/-   0
    ptp4l[235241.453]: rms    5 max   10 ( -10,    4) freq  +2475 +/-   5 delay    56 +/-   0
    ptp4l[235242.453]: rms    3 max    5 (  -1,    5) freq  +2483 +/-   3 delay    56 +/-   0
    ptp4l[235243.453]: rms    2 max    4 (  -1,    4) freq  +2483 +/-   2 delay    56 +/-   0
    ptp4l[235244.453]: rms    5 max   10 ( -10,   -1) freq  +2473 +/-   3 delay    55 +/-   0
    ptp4l[235245.453]: rms    4 max    7 (  -6,    7) freq  +2479 +/-   5 delay    55 +/-   0
    ptp4l[235246.453]: rms    5 max    9 (  -1,    9) freq  +2486 +/-   4 delay    54 +/-   1
    ptp4l[235247.453]: rms    3 max    7 (  -7,    4) freq  +2483 +/-   5 delay    55 +/-   0
    ptp4l[235248.453]: rms    6 max    9 (   2,    9) freq  +2492 +/-   4 delay    55 +/-   0
    ptp4l[235249.453]: rms    4 max    7 (  -3,    7) freq  +2493 +/-   4 delay    57 +/-   0
    ptp4l[235250.454]: rms    3 max    5 (  -5,    1) freq  +2486 +/-   3 delay    55 +/-   1
    ptp4l[235251.454]: rms    8 max   16 ( -16,   -2) freq  +2476 +/-   7 delay    54 +/-   1
    ...

| 

PHY Delay Compensation for AM57xx IDK
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The theoretical values to use for GMAC PHY, which is KSZ9031RN, on
AM57xx IDKs, are not yet available. The following experimental values
are recommended for now.

+--------------------------+--------------------------+--------------------------+
| Speed                    | Egress Latency (ns)      | Ingress Latency (ns)     |
+==========================+==========================+==========================+
| 100Mb                    | 546                      | 646                      |
+--------------------------+--------------------------+--------------------------+
| 1000Mb                   | 146                      | 346                      |
+--------------------------+--------------------------+--------------------------+

Test Setup
----------

.. rubric:: Supported Platforms
   :name: supported-platforms

-   AM571x IDK (GMAC/CPTS: eth0-eth1, PRU-ICSS2:eth2-eth3,PRU-ICSS1:eth4-eth5)
-   AM572x IDK (GMAC/CPTS: eth0-eth1, PRU-ICSS2:eth2-eth3)

.. rubric:: Hardware Modifications
   :name: hardware-modifications

Refer to the :ref:`PLSDK_PTP_HW_Mods-label`

.. rubric:: Using 1 PPS to measure synchronization accuracy/offset
   :name: using-1-pps-to-measure-synchronization-accuracyoffset

Some PTP test equipment and PTP-enabled Network adaptors provide 1PPS
signal be used to measure the offset and jitters of the system time
between the master and slave clock.

.. rubric:: Test with Oregano Syn1588 Network Adaptor
   :name: test-with-oregano-syn1588-network-adaptor

The Oregano Syn1588 network adaptor
`[2] <http://www.oreganosystems.at/?page_id=19>`__\ is configured to be
the PTP master clock with the Linux PTP/Ethernet utilities.

.. rubric:: Oregano Network Adaptor Configurations
   :name: oregano-network-adaptor-configurations

Enter the regular ifconfig command to configure the desired IP address

::

    #ifconfig enp4s0 192.168.3.20

Specify the network speed only if it is required, auto negotiation
should be enabled for all other use cases

::

    //Specify the Link Speed
    #ethtool -s np4s0 speed 100 duplex half autoneg off
    //enable auto negotiation
    #ethtool -s nep4s0 autoneg on

To configure the Oregano Network Adaptor as a PTP/OC master clock, enter
the following command

::

    #./ptp -i enp4s0 -L -CM_EXT -s-3 -DP

.. rubric:: PRU-ICSS Port Configurations
   :name: pru-icss-port-configurations

Follow the steps at :ref:`PLSDK_PRP_EMAC_Mode-label`
to boot up the AM57xx IDK and configure the PRU-PRP firmware to run in
PRP\_EMAC mode.

Use the fconfig command to configure the desired IP address, for example

::

    #ifconfig eth2 192.168.3.30

Verify the Ethernet connection by pinging the IP address of the master
port

::

    #ping 192.168.3.20

| 
| To configure the PRU-ICSS port as a PTP/OC slave clock and enable 1PPS
  signal, enter the following commands

::

    #ptp4l -2 -P -f oc_eth2.txt -s -m &
    #echo 1 > /sys/devices/platform/pruss2_eth/ptp/ptp1/pps_enable

.. rubric:: GMAC Port Configurations
   :name: gmac-port-configurations

Use the fconfig command to configure the desired IP address, for example

::

    #ifconfig eth1 192.168.3.40

| 
| Verify the Ethernet connection by pinging the IP address of the master
  port

::

    #ping 192.168.3.20

| 
| To configure the GMAC port as a PTP/OC slave clock and enable 1PPS
  signal, enter the following commands

::

    #ptp4l -2 -P -f oc_eth1.txt -s -m &
    #echo 1 > /sys/devices/platform/44000000.ocp/48484000.ethernet/ptp/ptp0/pps_enable

Test Results
-------------

The following scope captures show the offset and jitters of the PPS
signal between master and slave OC clock.

.. Image:: ../images/Pic_1pps_pruicss.png

::

               Figure 1: PPS: Oregano Master vs. PRU-ICSS Slave Port

| 

.. Image:: ../images/Pic_1pps_cpts.png

::

               Figure 2: PPS: Oregano Master vs. GMAC Slave Port

PTP Boundary Clock
==================

PTP boundary clock (BC) is supported on AM571x and AM572x IDKs. In the
case of AM571x IDK, BC with two or three ports is supported. These two
or three ports can be any combination of the three ports, i.e., GMAC
port, one ICSS1 PRU port and one ICSS2 PRU port. In the case of AM572x
IDK, BC with two ports, i.e., GMAC port and one ICSS2 PRU port, is
supported.

Software Overview
---------------------

There are four main components to the software together to provide the
boundary clock functionality. These are, from low to high level, the
ICSS PRU firmware, the related kernel ethernet drivers, the linuxptp
ptp4l application and the linuxptp phc2sys application.

.. rubric:: ICSS PRU Firmware
   :name: icss-pru-firmware

The ICSS PRU firmware used in BC is the PRP firmware (with PTP
timestamping capability enabled) configured to run in Single Attached
Node (SAN) mode.

.. rubric:: CPSW/CPTS Ethernet Driver
   :name: cpswcpts-ethernet-driver

This is the same CPSW/CPTS Ethernet driver implemented for GMAC PTP OC.

.. rubric:: ICSS-PRU/IEP Ethernet Driver
   :name: icss-pruiep-ethernet-driver

This is the same ICSS PRU Ethernet driver implemented for PTP OC.

.. rubric:: BC Internal Clock Sync Monitoring Driver
   :name: bc-internal-clock-sync-monitoring-driver

A thin PTP BC driver layer is added on top of the ICSS-PRU/IEP and
CPSW/CPTS Ethernet drivers in order to support the BC internal clock
synchronization. This thin layer of driver is responsible for keeping
track of which internal clock has its PPS enabled and giving permission
to the requests by the internal clocks to generate PPS. Keeping track of
PPS enablement is necessary because, at any instance of time, at most
one clock can enable its PPS. For otherwise the SoC may be permanently
damaged.

.. rubric:: Application linuxptp ptp4l
   :name: application-linuxptp-ptp4l

This is the application provides the BC PTP functionality. In the AM57xx
BC, the linuxptp ptp4l program is configured to run in jbod (just a
bunch of device) mode, i.e., the BC PTP clock is modelled on more than
one internal clocks instead of one single clock.

.. rubric:: Application linuxptp phc2sys
   :name: application-linuxptp-phc2sys

The linuxptp phc2sys is used to perform synchronization of the internal
clocks of a BC in jbod mode. For AM57xx BC, the phc2sys is enhanced to
support the synchronization of the BC internal clocks by reading the
timestamps of the PPS generated by the internal master clock and
captured by the internal slave clocks. phc2sys then feeds the timestamps
into linuxptp's servo algorithm. The algorithm then produces the needed
clock adjustment, usually in ppb of the nominal clock frequency, which
is then passed to the kernel driver for clock adjustment by calling
Linux PTP subsystem's standard API.

.. rubric:: Internal Clock Synchronization
   :name: internal-clock-synchronization

Although the PTP clock time in the PTP network of the BC appears coming
from one clock source, the PTP clock time available on the AM57xx
ethernet ports are actually generated by different clocks internally. In
particular, the PTP clock time on the CPSW GMAC port is generated by the
CPTS module, and the PTP clock time on the ICSS PRU ports is generated
by the corresponding IEP module on the respective ICSS. Since these
clocks are running on their own separately, thus some internal
synchronization mechanism is needed in order to make the AM57xx BC
internal clocks appear as one clock source in the PTP network.

The internal clock synchronization can be considered in two parts. The
first part is the alignment of the clock time up to within one second.
This can easily be done by just reading one internal clock's time and
write it to the other internal clock by application software alone under
the assumption that the whole read and write operation takes less than
one second. The other part of synchronization is to align the two
clocks' time to the second boundary.

In this AM57xx BC implementation, the alignment of two internal clocks'
time to the second boundary is done by using the PPS generated by one
internal (master) clock latched into another internal (slave) clock.
This means that the PPS received by an internal clock is timestamped.
This timestamp is then consumed by a servo application in the
calculation of the adjustment needed in order to align the internal
slave clock's second boundary to that of the internal master clock.

Here the internal master clock of the BC is the internal clock that is
synchronized to a PTP master clock over the PTP network, i.e., the
corresponding ethernet port is in PTP slave port state.

Hardware Overview
-----------------

For AM57xx IDK BC, since PPC generated by one internal clock needs to be
latched into another internal clock, hardware, mainly blue wire,
modifications are needed in order to achieive the latching of the PPS
generated by one internal clock into another internal clock.

Refer to the :ref:`PLSDK_PTP_HW_Mods-label`

Test Setup/Procedure
--------------------

.. rubric:: A Sample BC Setup
   :name: a-sample-bc-setup

A sample set up for testing purpose is shown below.

.. Image:: ../images/Bc_connect.jpg


In this scenario, the BC ICSS2 PRU port (interface eth2) is in PTP
slave state (ICSS2-IEP is the BC internal master clock). The other two
ports, BC ICSS1 (interface eth4) and BC CPSW/CPTS (interface eth1) are
in PTP master state (ICSS1-IEP and CPTS are the BC internal slave
clocks).


.. rubric:: Getting a PTP master clock ready
   :name: getting-a-ptp-master-clock-ready

Start a reference PTP master clock that is connected in the PTP network
as shown in the `sample setup <#a-sample-bc-setup>`__.

If the PTP master clock is an AM572x OC running linuxptp ptp4l, and for
testing purpose, a line such as

::

    clockClass 6

in the [global] section of the OC's linuxptp configuration file can be
helpful to make sure that the OC will be a master clock. Refer to 
:ref:`PLSDK_PTP_OC-label` for starting an AM57xx OC.

| 

.. rubric:: Preparation on the AM57xx BC IDK
   :name: preparation-on-the-am57xx-bc-idk

This section assumes that an AM571x is used. It should be similar for
AM572x (or AM574x IDK) except that information about ICSS1 PRU (PRUSS1), eth4 and eth5
are not applicable.

.. rubric:: Hardware
   :name: hardware

.. rubric:: AM571x IDK
   :name: am571x-1 idk

Connect the following 4 pins together. See the `AM571x Mod
List <http://processors.wiki.ti.com/images/6/66/Am571x_idk_bc_ModList.pdf>`__
for more details.

+--------------------------------------+--------------------------------------+
| Wire on AM571x IDK                   | Signal                               |
+======================================+======================================+
| lower yellow wire                    | .. raw:: html                        |
|                                      |                                      |
|                                      |    <div style="text-align: center;"> |
|                                      |                                      |
|                                      | timer15                              |
|                                      |                                      |
|                                      | .. raw:: html                        |
|                                      |                                      |
|                                      |    </div>                            |
+--------------------------------------+--------------------------------------+
| J21-18 right blue wire               | .. raw:: html                        |
|                                      |                                      |
|                                      |    <div style="text-align: center;"> |
|                                      |                                      |
|                                      | pr2\_edc\_latch0\_out                |
|                                      |                                      |
|                                      | .. raw:: html                        |
|                                      |                                      |
|                                      |    </div>                            |
+--------------------------------------+--------------------------------------+
| J21-20 purple wire                   | .. raw:: html                        |
|                                      |                                      |
|                                      |    <div style="text-align: center;"> |
|                                      |                                      |
|                                      | pr1\_edc\_latch0\_out                |
|                                      |                                      |
|                                      | .. raw:: html                        |
|                                      |                                      |
|                                      |    </div>                            |
+--------------------------------------+--------------------------------------+
| J21-54 left blue wire                | .. raw:: html                        |
|                                      |                                      |
|                                      |    <div style="text-align: center;"> |
|                                      |                                      |
|                                      | pr1\_edc\_sync0\_out                 |
|                                      |                                      |
|                                      | .. raw:: html                        |
|                                      |                                      |
|                                      |    </div>                            |
+--------------------------------------+--------------------------------------+

Example: See below pictures (J21 is the connector along the top right edge)

.. Image:: ../images/Am571x_whole_small2.png

and this more J21 focused of the same picture above

.. Image:: ../images/Am571x_j21.png

.. rubric:: AM572x and AM574x IDK
   :name: am572x-1

Connect the following 3 pins together. See the `AM572x Mod
List <http://processors.wiki.ti.com/images/c/c3/Am572x_idk_bc_ModList.pdf>`__
for more details.


+--------------------------------------+--------------------------------------+
| Wire on AM574x IDK                   | Signal                               |
+======================================+======================================+
| Center left black wire               | .. raw:: html                        |
|                                      |                                      |
|                                      |    <div style="text-align: center;"> |
|                                      |                                      |
|                                      | timer15                              |
|                                      |                                      |
|                                      | .. raw:: html                        |
|                                      |                                      |
|                                      |    </div>                            |
+--------------------------------------+--------------------------------------+
| J21-13 black wire                    | .. raw:: html                        |
|                                      |                                      |
|                                      |    <div style="text-align: center;"> |
|                                      |                                      |
|                                      | pr2\_edc\_latch0\_out                |
|                                      |                                      |
|                                      | .. raw:: html                        |
|                                      |                                      |
|                                      |    </div>                            |
+--------------------------------------+--------------------------------------+
| J21-17 white wire                    | .. raw:: html                        |
|                                      |                                      |
|                                      |    <div style="text-align: center;"> |
|                                      |                                      |
|                                      | pr1\_edc\_sync0\_out                 |
|                                      |                                      |
|                                      | .. raw:: html                        |
|                                      |                                      |
|                                      |    </div>                            |
+--------------------------------------+--------------------------------------+

Example: See below pictures (J21 is the connector along the top right edge)

.. Image:: ../images/Am574x_whole_small2.png

and this more J21 focused of the same picture above

.. Image:: ../images/Am574x_j21.png

.. rubric:: Software
   :name: software-1

See a complete sample log for AM571x BC log
`here <http://processors.wiki.ti.com/images/2/20/Bc_20180112.pdf>`__. As
is shown in the log, right after the root login, the content of some
shell scripts are displayed. Some of the scrits are for retrieving
system information while others are for performing configurations. These
sample scripts are for informational purpose only.

Since BC and OC are supported by using the PRP firmware configured to
run in SAN mode, make sure to boot up the kernel with the parameters

-  ti\_prueth.pruss1\_ethtype=2
-  ti\_prueth.pruss2\_ethtype=2

in the bootargs. The firmware

-  am57xx-pru0-pruprp-fw.elf
-  am57xx-pru1-pruprp-fw.elf

will be loaded.

Make sure the following two lines appear in the start up log:

::

    prueth pruss2_eth: TI PRU ethernet (type 2) driver initialized
    prueth pruss1_eth: TI PRU ethernet (type 2) driver initialized

Once the AM57xx IDK is boot into kernel prompt, use command, for
example,

::

    $ ls /sys/devices/platform/pruss1_eth/net
      eth4/  eth5/

to see which interface is available on which ICSS. For GMAC port, use
the command

::

    $ ls /sys/devices/platform/44000000.ocp/48484000.ethernet/net
      eth0/ eth1/

Then enable SAN mode on each of the ICSS PRU interfaces (assuming eth2
and eth3 are on ICSS2, eth4 and eth5 are on ICSS1):

::

    $ echo 1 > /sys/kernel/debug/prueth-eth2/prp_emac_mode
    $ echo 1 > /sys/kernel/debug/prueth-eth3/prp_emac_mode
    $ echo 1 > /sys/kernel/debug/prueth-eth4/prp_emac_mode
    $ echo 1 > /sys/kernel/debug/prueth-eth5/prp_emac_mode

Next, configure each BC interface with a proper IP address. For example,

::

    $ ifconfig eth1 192.168.1.1

::

    $ ifconfig eth2 192.168.2.1

::

    $ ifconfig eth4 192.168.4.1

.. rubric:: Starting the BC applications
   :name: starting-the-bc-applications

Make sure the linuxptp BC configuration file bc.cfg (included in zip
file)

::

    [global]
    tx_timestamp_timeout 10
    logMinPdelayReqInterval -3
    logSyncInterval -3
    twoStepFlag 1
    summary_interval 0
    [eth1]
    boundary_clock_jbod 1
    egressLatency 146
    ingressLatency 346
    [eth2]
    boundary_clock_jbod 1
    egressLatency 726
    ingressLatency 186
    [eth4]
    boundary_clock_jbod 1
    egressLatency 726
    ingressLatency 186

is available in the filesystem. Start ptp4l in the background and with
display log to stdout enabled:

::

    $ ptp4l -2 -P -f bc.cfg -m &

Wait to see the PTP slave port clock is sync and stabilized, for
example, seeing similar lines:

::

    ptp4l[304.713]: rms    7 max   12 ( -12,    1) freq  -8253 +/-   4 delay     7 +/-   1
    ptp4l[305.714]: rms    2 max    4 (  -4,    2) freq  -8248 +/-   3 delay     8 +/-   0
    ptp4l[306.714]: rms    2 max    3 (  -3,    3) freq  -8248 +/-   3 delay     8 +/-   0

then start phc2sys to perform the BC internal clock sync in the
background

::

    $ phc2sys -a -X -g eth1 -m &

where the new options added in this implementation are

::

    -X: use extts (pps) to perform BC internal clock synchronization.
    -g: specify which interface is the GMAC port interface

Lines similar to the following should be displayed after a few seconds
(mixed with the "ptp4l[304.713]: rms ..." lines from ptp4l) :

::

    phc2sys[373.480]: eth4 phc offset       -14 s2 freq   -8311
    phc2sys[373.500]: eth1 phc offset       -18 s2 freq   -8315

Start an AM57xx OC in slave only mode connected to a BC's master port,
for example, the AM572x OC-3 in the `sample
setup <#a-sample-bc-setup>`__. To make sure the OC is started in slave
only mode, the ptp4l command

::

    $ ptp4l -2 -P -f oc.cfg -s -m

can be used. The slave OC's PPS can then be measured against the
reference PTP master clock's PPS.

.. rubric:: Forcing BC Port State Change (for Testing Purpose)
   :name: forcing-bc-port-state-change-for-testing-purpose

To force a port state change on the BC ports for testing purpose, one
can bring down the current reference PTP master clock and bring up
another reference PTP master clock connected to, for example, the BC's
eth1 interface in the `sample setup <#a-sample-bc-setup>`__. Or simply
rearrange the cable connections in the `sample
setup <#a-sample-bc-setup>`__ as shown below.

.. Image:: ../images/Bc_reconnect.jpg

See
`here <http://processors.wiki.ti.com/images/8/83/Bc_reconnect_20180112.pdf>`__
for a sample log when the BC's cables are reconnected. The sample log
starts right before when the cable is disconnected from eth2 on BC's
ICSS2 in the `sample setup <#a-sample-bc-setup>`__.

Test Results
-------------

.. rubric:: BC (GMAC ICSS2)
   :name: bc-gmac-icss2

| Oregano <==> BC-GMAC-eth1 <==> BC-ICSS2-eth2 <==> OC-ICSS2-eth2

.. Image:: ../images/Pic_ptp_bc_eth1_eth2.png

| 

.. rubric:: BC (GMAC ICSS1)
   :name: bc-gmac-icss1

| Oregano <==> BC-GMAC-eth1 <==> BC-ICSS1-eth4 <==> OC-ICSS2-eth2

.. Image:: ../images/Pic_ptp_bc_eth1_eth4.png

.. rubric:: BC (ICSS2 GMAC)
   :name: bc-icss2-gmac

| Oregano <==> BC-ICSS2-eth2 <==> BC-GMAC-eth1 <==> OC-GMAC-eth1

.. Image:: ../images/Pic_ptp_bc_eth2_eth1.png

.. rubric:: BC (ICSS1 GMAC)
   :name: bc-icss1-gmac

| Oregano <==> BC-ICSS1-eth4 <==> BC-GMAC-eth1 <==> OC-GMAC-eth1

.. Image:: ../images/Pic_ptp_bc_eth4_eth1.png

.. rubric:: BC (ICSS2 ICSS1)
   :name: bc-icss2-icss1

| Oregano <==> BC-ICSS2-eth2 <==> BC-ICSS1-eth4 <==> OC-ICSS2-eth2

.. Image:: ../images/Pic_ptp_bc_eth2_eth4.png

.. rubric:: BC (ICSS1 ICSS2)
   :name: bc-icss1-icss2

| Oregano <==> BC-ICSS1-eth4 <==> BC-ICSS2-eth2 <==> OC-ICSS2-eth2

.. Image:: ../images/Pic_ptp_bc_eth4_eth2.png

Limitations
-----------

-  At most one port from each of the three modules, CPSW, ICSS1 and
   ICSS2, can be as a BC interface.

-  In the current implementation, when running more than one OC, for
   example, ICSS1 OC and ICSS2 OC, only one pps can be enabled through
   command line. In this example, if ptp1 is the device for ICSS2 OC and
   ptp2 is the device for ICSS1 OC, then only one of the following will
   be allowed:

::

    echo 1 > /sys/devices/platform/pruss2_eth/ptp/ptp1/pps_enable

or

::

    echo 1 > /sys/devices/platform/pruss1_eth/ptp/ptp2/pps_enable

The same is true for other combinations. The intention is to avoid
having more than one PPS enabled when the IDK has the HW mod mentioned
in `Hardware Modifications for AM57xx IDK
BC <#hardware-modifications-for-am57xx-idk-bc>`__ and the pins are tied
together.

PTP Roadmap
===========
The following features are not yet supported as of Processor SDK 4.2
release, but will be added in future

.. rubric:: Redundancy (HSR/PRP) Support in OC/BC
   :name: redundancy-hsrprp-support-in-ocbc

.. rubric:: Transparent Clock
   :name: transparent-clock

