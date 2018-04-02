************************************
Release Notes
************************************
.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Release_Notes

Overview
========

The **Processor Software Development Kit (Processor-SDK) for Linux**
provides a fundamental software platform for development, deployment and
execution of Linux based applications and includes the following:

-  Bootloaders & Filesystems
-  SDK Installer
-  Setup Scripts
-  Makefiles
-  Matrix Application Launcher
-  Example Applications
-  WLAN support (Wilink 8)
-  Code Composer Studio v7

Licensing
=========

  Please refer to the software manifest, which outlines the licensing
  status for all packages included in this release. The manifest can be
  found on the SDK download page. The manifest can be found on the SDK
  download page or in the installed directory as indicated below. In
  addition, see :ref:`PLSDK-GPLv3-Disclaimer-label`

.. rubric:: Documentation
   :name: documentation

-  :ref:`PLSDK-SDG-label`: Provides information on features, functions, delivery package and,
   compile tools for the Processor SDK Linux release. This also provides
   detailed information regarding software elements and software
   infrastructure to allow developers to start creating applications.
-  :ref:`PLSDK-GSG-label`: Provides information on getting the software and running
   examples/demonstrations bundled in the SDK.
-  **Software Manifest**: Provides license information on software
   included in the SDK release. This document is in the release at
   ``[INSTALL-DIR]/docs``.
-  **EVM Quick Start Guide**: Provides information on hardware setup and
   running the demonstration application that is loaded on flash. This
   document is provided as part of the EVM kit.

Release 04.03.00 Highlights
============================

Released Mar 2018

.. rubric:: What's New
   :name: whats-new

-  New Demos
    -  Qt5-based Thermostat demo on AM335x/AM437x/AM57x
    -  Demonstrate 4K Video Encode with IVAHD on AM57x
    -  Khronos OpenVX based demo example with C66x offload via OpenCL
    -  ROS Turtlebot demo using AM57x and IWR1443/IWR1642 mmWave radar

-  New Features
    -  PTP: Support Boundary Clock between 3 ports (1xCPSW and 2xICSS) on AM571x
    -  PTP: Configurable latency for 1 PPS Output, to compensate for the propagation delay of 1 PPS signal to the oscilloscope
    -  HSR/PRP on AM57x: Support Multicast Filtering
    -  HSR/PRP on AM57x: Support VLAN Filtering

.. rubric:: SDK Components & Versions
   :name: sdk-components-versions

+--------------------------+----------------------------+
| Component                | Version                    |
+==========================+============================+
| Linux Kernel             | 4.9.69+ (2017 LTS)         |
+--------------------------+----------------------------+
| U-Boot                   | 2017.01                    |
+--------------------------+----------------------------+
| Yocto Project            | 2.2 (morty)                |
+--------------------------+----------------------------+
| Linaro Toolchain (gcc)   | 6.2.1 2016.11 hard-float   |
+--------------------------+----------------------------+
| Qt                       | 5.7.1                      |
+--------------------------+----------------------------+
| OpenCL                   | 1.1.14                     |
+--------------------------+----------------------------+
| OpenCV                   | 3.1                        |
+--------------------------+----------------------------+
| Wayland                  | 1.11                       |
+--------------------------+----------------------------+
| GStreamer                | 1.8.3                      |
+--------------------------+----------------------------+
| Chromium                 | v53                        |
+--------------------------+----------------------------+
| TI PRU Compiler          | 2.2.1                      |
+--------------------------+----------------------------+
| TI C66x CGT Compiler     | 8.2.2                      |
+--------------------------+----------------------------+

|

Supported Platforms
=====================================
See :ref:`SDK-Supported-Platforms` for a list of supported platforms and links to more information.

|


Build Information
=====================================

U-Boot
-------------------------

| Head Commit: c68ed086bd00054e28c46e033385f79104c3f84c mmc:
  omap\_hsmmc: Handle command and data errors after response
| Date: Wed Dec 20 11:21:41 CST 2017
| uBoot Version: 2017.01
| uBoot Description: v2017.01-457-gc68ed08
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2017.01
| uBoot Tag: ti2017.06

|

Kernel
-------------------------

.. rubric:: Linux Kernel
   :name: linux-kernel

| The kernel git repository, branch and commit id can be found below:
| Based on Version: 4.9.69
| URL: git://git.ti.com/processor-sdk/processor-sdk-linux.git
| Branch: processor-sdk-linux-04.03.00
| Commit ID: bfe793963ed7b2af3e1c3dd32e7275f449e6259d 

|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| The RT kernel git repository, branch and commit id can be found below:
| Based on:
| Kernel Version: 4.9.65
| RT Kernel Version: 4.9.65-rt23

| URL: git://git.ti.com/processor-sdk/processor-sdk-linux.git
| Branch: processor-sdk-linux-rt-04.03.00
| Commit ID: 3986f9c45542f5ff4ce7f0c916c4aae8f868a042 

|

.. rubric:: Generic Kernel Release Notes
   :name: generic-kernel-release-notes

| Generic kernel release notes from kernelnewbies.org can be found at:
  http://kernelnewbies.org/Linux_4.9
| Archived versions can be found at:
  http://kernelnewbies.org/LinuxVersions

|


Issues Tracker
=====================================

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 20, 70

    LCPD-9496,"am437x-idk, am437x-sk, am43xx-epos, am43xx-gpevm, am43xx-hsevm",AM43XX DS0_PULL_UP_DOWN_EN wrong polarity
    LCPD-10976,am57xx-evm,Weston memory leak related to HDMI hotplug
    LCPD-10975,"am574x-idk, am574x-hsidk, k2e-evm, k2e-hsevm, k2g-evm, k2g-hsevm, k2g-ice, k2hk-evm, k2hk-hsevm, k2l-evm, k2l-hsevm",EDAC support is disabled
    LCPD-10910,am571x-idk,U-Boot: am571x-idk doesn't boot with ti2017.05-rc1
    LCPD-10862,am335x,Adding VLANs does not show correct tagging on ingress/egress
    LCPD-10859,am57xx-evm,AM5728 PCIe unstable: PCIe USB card stopped when doing ethernet bandwidth test using iperf3
    LCPD-10809,am43xx-gpevm,AM437x USB RNDIS Host Fails with AM437x Client/gadget
    LCPD-10411,k2g-evm,Pcie-ep: pcitest: Read/write/copy tests timeout with legacy IRQ
    LCPD-7903,"k2g-evm, k2hk-evm",Uboot phy startup failed and dhcp failed occasionally on k2 board
    LCPD-8871,"am43xx-epos, am43xx-gpevm",DSS underflows seen on K2G at boot time
    LCPD-10963,am335x-evm,Possible memory leaked observed during stress testing mode setting
    LCPD-10921,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-hsevm",Writeback capture with interlace does not work
    LCPD-10843,"am571x-idk, am572x-idk, am335x-ice, am437x-idk",prueth: fix probe crash when unable to allocate sram memory
    LCPD-10808,am574x-idk,PMT data including iodelay values for am574x-idk
    LCPD-10212,omapl138-lcdk,omapl138: Modprobe g_zero leads to a cppi trace - no seeming loss of functionality
    LCPD-10013,am572x-idk,dhcp failed in uboot sometimes
    LCPD-10534,am57xx-evm,v4l2src gstreamer plugin with capture using VIP driver is showing frame loss
    LCPD-4834,AM335x,CONNECTIVITY: AM33XX: descriptor warning upon suspend/resume with host and device
    LCPD-666,AM335x,AM33X: CONNECTIVITY: gstreamer usb video fails to complete 10000 frames
    LCPD-1244,AM335x,AM335x: CONNECTIVITY: Could not flush fifo errors when cable is disconnected during usb transaction
    LCPD-7824,"am335x-evm, am43xx-gpevm, am57xx-evm, k2hk-evm",LTP MM: system allowed 2 more memory map entries than /proc/sys/vm/max_map_count
    LCPD-7340,am571x-idk,No Pin Mux (PMT) Data available
    LCPD-10658,"am335x-evm, am335x-hsevm, am335x-ice, am335x-sk, am437x-idk, am437x-sk, am43xx-epos, am43xx-gpevm, am43xx-hsevm, am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm, beaglebone, beaglebone-black, k2e-evm, k2e-hsevm, k2g-evm, k2g-hsevm, k2g-ice, k2hk-evm, k2hk-hsevm, k2l-evm, k2l-hsevm, omapl138-lcdk",Remove CONFIG_ENV_AES and all code associated with this
    LCPD-10552,am43xx-epos,Board does not boot
    LCPD-7144,"am335x-evm, am335x-ice, am335x-sk, am437x-idk, am437x-sk, am43xx-gpevm, am571x-idk, am572x-idk, am57xx-evm, beaglebone, beaglebone-black, omapl138-lcdk",System refuse to freeze sometimes and suspend is aborted
    LCPD-5647,AM437x,"I2C error causes irq flood, freezing the board"
    LCPD-10211,omapl138-lcdk,omapl138-lcdk: USB Video capture does not provide warning for resolutions larger than 320x240 resolution
    LCPD-10927,am574x-idk,Thermal_zone reach critical temperature and shutting down on am574x-idk
    LCPD-10210,omapl138-lcdk,omapl138: USB ECM ethernet interface is missing - config option
    LCPD-937,am43xx-epos,am43xx-epos:Connectivity:QSPI big size and stress RW tests fail due to data mismatch
    LCPD-868,am437x,AM437x: USB dev node is not restored after resume from standby or suspend state
    LCPD-6882,"am335x-evm, am335x-ice, am335x-sk",musb: ASIX usb-ethernet dongle unable to rx udp packets when behind a hub
    PLSDK-1896,"am571x-idk, am572x-idk",cpts does not unregister from ptp_bc
    PLSDK-1877,"am335x-ice, am437x-idk",PRU ETH on AM335x ICEv2
    PLSDK-1861,"am571x-idk, am572x-idk",AM57xx-IDK: USB host doesn't detect any attached USB device
    PLSDK-1824,,CPTS 1PPS: cannot enable 1PPS/PEROUT if disabled twice
    PLSDK-1819,"am571x-idk, am572x-idk",SAN MAC address not seen in Node Table
    PLSDK-1781,"am571x-idk, am572x-idk",CPTS events got lost occasionally
    PLSDK-1776,"am571x-idk, am572x-idk",HSR/PRP: the lreNodes in LRE stats shows zero always
    PLSDK-1773,"am571x-idk, am572x-idk",HSR/PRP: snmpwalk and debugfs doesn?t show Node Table entries
    PLSDK-1771,"am571x-idk, am572x-idk",Intermittent Linux crash is observed on PRU ports in PTP tests
    PLSDK-1770,,Crash happens when ifconfig up/down in prueth PRP-SAN
    PLSDK-1765,"am571x-idk, am572x-idk",AM57xx boundary clock internal clock sync does not persist
    PLSDK-1764,"am571x-idk, am572x-idk",AM57xx boundary clock fails to sync after runtime port state changes
    PLSDK-1763,am571x-idk,AM571x boundary clock ICSS-x to ICSS-y internal clock sync with pps fails when BC includes CPTS and 2 ICSS's
    PLSDK-1752,"k2e-evm, k2l-evm",OpenCL: Floating_Point_Computation test failed due to TIOCL FATAL: Internal Error on K2L-RT and K2E-RT platforms
    PLSDK-1725,am572x-evm,X11: cannot run /etc/init.d/xorg
    PLSDK-1719,k2e-evm,K2E ethernet port (eth2) link down if SGMII configured as MAC_MAC_FORCED
    PLSDK-1713,omapl138-lcdk,OMAP-L138 bin/setup-uboot-env.sh set env bootcmd wrongly
    PLSDK-1712,"am572x-idk, am572x-evm",openvx test hangs on AM572x-GP and AM572x-IDK platform
    PLSDK-1596,"am571x-idk, am572x-idk",Static offset between input and output 1 PPS signals on GMAC
    PLSDK-1540,"am335x-evm, am437x-evm",AM3 and AM4 Build WPANTUND: Unable to find a usable implementation of boost::signals2

|


Issued found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 20, 70

   LCPD-11124 ,  ,Fix WPA security vulnerability in ECS components
   LCPD-11109 ,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm ",System can not DHCP while booting
   LCPD-11106 ,"am43xx-epos, am43xx-hsevm ",TEE header error prevents TEE core initialization
   LCPD-11018 ,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm ",Thermal: Sometimes Software initiated thermal shutdown doesn?t trigger before HW shutdown
   LCPD-11415 ,am43xx-hsevm ,OPTEE regression_1014 test failed (secure data path against SDP TAs and pTAs)
   LCPD-11126 ,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm ",EGLImage memory leak
   LCPD-11134 ,am57x ,AM57xx Rev A3 ETH1 does not get link at 1Gbps
   LCPD-11307 ,am335x ,wl18xx not loading with ti2017.02-rc4
   LCPD-11024 ,omapl138-lcdk ,musb: babble condition doesn?t recover on OMAP-L138
   LCPD-11136 ,"am335x-evm, am335x-hsevm, am335x-ice, am335x-sk, am437x-idk, am437x-sk, am43xx-epos, am43xx-gpevm, am43xx-hsevm, am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm, beaglebone, beaglebone-black, k2e-evm, k2e-hsevm, k2g-evm, k2g-hsevm, k2g-ice, k2hk-evm, k2hk-hsevm, k2l-evm, k2l-hsevm, omapl138-lcdk ",Four Common Vulnerabilities and Exposures (CVE) not implemented
   LCPD-11003 ,am335x-evm ,AM33xx DDR DPLL incorrect setting

| 

Errata Workarounds Available in this Release
------------------------------------------------

+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| **Record ID**   | **Title**                                                                                                                |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-9084       | i887: Software workaround to limit mmc3 speed to 64MHz                                                                   |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-7642       | MMC/SD: i832: return DLL to default reset state with CLK gated if not in SDR104/HS200 mode.                              |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-5310       | i900: CTRL\_CORE\_MMR\_LOCK\_5 region after locking results in ctrl module inaccessible, recoverable only post a reset   |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-5309       | LCPD: i896: USB Port disable doesnt work                                                                                 |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-5311       | i893: DCAN ram init issues in HW AUTO and when traffic hitting CAN bus (open investigation)                              |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-9173       | i897: USB Stop Endpoint doesnt work in certain circumstances                                                             |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-5924       | ALL: CONNECTIVITY: CPSW: errata i877 workarround for cpsw                                                                |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-4975       | DSS AM5: implement WA for errata i886                                                                                    |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-5052       | Upstream: Post the dmtimer errata fix for i874                                                                           |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-4647       | [rpmsg 2015 LTS] Implement errata i879 - DSP MStandby requires CD\_EMU in SW\_WKUP                                       |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-4648       | [rpmsg 2014 LTS] Implement errata i879 - DSP MStandby requires CD\_EMU in SW\_WKUP                                       |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-4218       | Implement Workaround for Errata i813 - Spurious Thermal Alert Generation When Temperature Remains in Expected Range      |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-4217       | Implement Workaround for Errata i814 - Bandgap Temperature read Dtemp can be corrupted                                   |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-4184       | Implement workaround for errata i814 - Bandgap Temperature read Dtemp can be corrupted                                   |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-1146       | DMM hang: Errata VAYU-BUG02976 (i878) (register part)                                                                    |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-6907       | Workaround errata i880 for RGMII2 is missing                                                                             |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-8294       | 37 pins + VOUT pins need slow slew enabled for timing and reliability respectively                                       |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-5836       | CAL: Errata: i913: CSI2 LDO needs to be disabled when module is powered on                                               |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-5460       | Implement WA for Vayu errata i829 (Reusing Pipe Connected To Writeback Pipeline On The Fly To An Active Panel)           |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+

| 

SDK Known Issues
-----------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 25, 30, 50, 60

   LCPD-5578 ,beaglebone-black ,Exception triggered by graphics driver during boot if board does not have SGX (BBB A4) ,Build Processor SDK without SGX following instructions here
   LCPD-7025 ,am43xx-gpevm ,System takes more than 10 seconds to go from login prompt to system prompt ,Automated tests need to account for this boot delay
   LCPD-7255 ,All ,Telnet login takes too long (~40 seconds) ,"Booting with rootfs mounted over NFS might cause ~40 seconds delay on Telnet login because DNS entries might not be properly populated. To work around this issue, enter appropriate DNS server IP in resolv.conf. For example: echo ?nameserver 192.0.2.2? > /etc/resolv.conf;"
   LCPD-8210 ,"am57xx-evm, am571x-idk, am572x-idk ",QT Touchscreen interaction (Bear Whack) crash ,None
   LCPD-8345 ,"am335x-evm, am437x-idk, k2e-evm, k2e-hsevm, k2hk-evm, k2l-evm ","Board fails to start login console after waiting 3.5 minutes ( hard to reproduce, ~4/1000) ",Restart the EVM
   LCPD-8352 ,"am43xx-gpevm, am57xx-evm ",weston: stress testing with 75 concurrent instances of simple-egl leads to unresponsive HMI due to running out of memory ,"1. Restart Wayland application. 2. Restart board if Weston is killed by oom-killer"
   LCPD-9006 ,am57xx-evm ,Some GLBenchmark tests fail to run ,"This is a limitation with Imagination DDK, and no workaround"
   LCPD-9616 ,am57xx-evm ,QtCreator GDB (remote) debugging stops working since QT5.7.1 ,use GDB from Processor SDK 3.2
   LCPD-11010 ,am574x-idk ,AM574x-idk graphics performance is lower than am572x-idk ,"Performance issue, no workaround"
   LCPD-11549 ,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm ",Error message with multiple egl contexts that are not shared ,"Limitation with Imagination DDK, no workaround"
   PLSDK-780 ,AM5X ,Failing to create more then 10 gst pipeline using ductai codec plugins ,Upper limit on # of simultaneous video channels is 10.
   PLSDK-832 ,AM57 ,OpenCL matmpy intermittent DSP1 crash due to EdmaMgr issues w/ suspend/resume ,Disable DSP suspend/resume echo ?on? > /sys/bus/platform/devices/40800000.dsp/power/control echo ?on? > /sys/bus/platform/devices/41000000.dsp/power/control
   PLSDK-885 ,AM57 ,OpenCV Video test failure w/ GStreamer errors ,Use the workaround from    PLSDK-832
   PLSDK-1266 ,am572x-idk ,PRP: stale IGMP packets (IPv6) seems directly sent to eth2/eth3 of a HRP node ,None
   PLSDK-1283 ,am572x-idk ,PRP: unexpected MAC address seen in the node_tabe dump ,"Seen only with non offloaded case. With offload case, this is not seen."
   PLSDK-1308 ,am572x-idk ,PRP: PRP node is shown as SAN at times in the node table dump when not offloaded ,"No problem with offload, which is default"
   PLSDK-1312 ,"k2h-evm, k2e-evm, k2l-evm ",QoS test fails due to missing qos-inputs-0 on K2 platforms ,None
   PLSDK-1398 ,"k2e-evm, k2e-hsevm ","Matrix IPC demo seems hangs, if run after OpenCL demos, on K2E platform ",Run IPC demo w/o running OpenCL first
   PLSDK-1419 ,k2l-evm ,Intermittent-IP address display issue on LCD for K2L RT ,"Use ifconfig once Linux boots, to acquire ip address"
   PLSDK-1421 ,k2hk-evm ,SRIO is not functional on 2017 LTS ,None
   PLSDK-1432 ,k2hk-evm ,"10G UBoot support broken on K2, in 2017LTS ",None
   PLSDK-1556 ,"k2hk-evm, k2hk-hsevm, k2e-evm, k2l-evm ",PDK: saBasicExample test shows warning as ?Alignment trap? on K2x platforms. ,Just a warning message. No impact to test output
   PLSDK-1602 ,am437x-evm ,"Simple people tracking demo: Bulk transfer failed, observed inconsistent behavior of the application ",None
   PLSDK-1603 ,"am571x-idk, am572x-idk, am572x-evm ",Received bad addr len cause the OpenAMP test failure when DSP is redownloaded on AM57xx platforms ,None
   PLSDK-1625 ,"am571x-idk, am572x-idk, am574x-idk ",prueth: netdev watchdog fires under heavy load ,A workaround is already implemented in software for this
   PLSDK-1641 ,  ,HSR/PRP: NetJury Test TC_HSR_5_2_1 fails , 
   PLSDK-1675 ,am572x-evm ,Matrix Demo: Observed unwanted failure message in QT touch and Browser related test ,None
   PLSDK-1693 ,am572x-evm ,Incorrect behaviour observed for HDMI matrix on AM572x-GP EVM ,None
   PLSDK-1707 ,"am571x-idk, am572x-idk ",prueth: debugfs_create_dir() fails during boot and error message shown ,Only impact the debug stats display. No other functionality affected
   PLSDK-1720 ,am437x-evm ,Simple people tracking demo: Tracking Incorrect Number of People ,None
   PLSDK-1732 ,am572x-idk ,Prueth: Observed packet re-ordering in VLAN_over_HSR and VLAN_over_PRP test on AM572x-IDK platform ,Packet re-ordering is expected to be taken care by network stack for TCP and application for UDP. So this is not a serious issue
   PLSDK-1767 ,"am571x-idk, am572x-idk ",FATAL: error getting device node for USB , 
   PLSDK-1814 ,am572x-evm ,Camera support is not available from the default dtbs ,"Use am57xx-evm*-cam-mt9t111.dtb for mt9t111 camera, and am57xx-evm*-cam-ov10635.dtb for ov10635 camera"
   PLSDK-1815 ,"am335x-evm, am437x-evm, am572x-evm ",DNS should be operational using binaries ,None
   PLSDK-1817 ,  ,HSR/PRP: Outstanding Net-Jury tests failures , 
   PLSDK-1828 ,"am571x-idk, am572x-idk ","HSR: In a ring topology, seeing small performance degradation with concurrent traffic ",None
   PLSDK-1836 ,"am335x-evm, am335x-hsevm, am335x-ice, am335x-sk, beagleboneblack, omapl138-lcdk ",Kernel source code package has two defconfigs ,None
   PLSDK-1842 ,"AM4, AM5, K2 ",CMEM misses some multi-thread protection ,None
   PLSDK-1891 ,am335x-evm ,QT Wayland compositor with SGX on AM335x Processor SDK , 
   PLSDK-1909 ,am572x-evm ,DLP SDK demo: Assertion `ctx->pollfds_cnt >= internal_nfds? failed ,None
   PLSDK-1924 ,"am335x-ice, am335x-sk, beagleboneblack ",AM3: Observed unwanted failure message in boot log. , 
   PLSDK-1938 ,am571x-idk ,Unexpected behaviour with fixed Seq-Nr. in HSR mode , 
   PLSDK-1939 ,am571x-idk ,A-B forwarding with wrong/no FCS in HSR mode , 
   PLSDK-1940 ,am571x-idk ,Unexpected offset jump in PTP , 
   PLSDK-1941 ,am571x-idk ,PTP: Overshoot state reported , 
   PLSDK-1944 ,"am572x-idk, am574x-idk ",GPIO Test fails , 
   PLSDK-1945 ,am572x-evm ,qApp->quick() does not work with the enhanced eglfs_kms QPA , 
   PLSDK-1950 ,k2e-evm ,IPSEC failure: Issue in IPSEC TCP on the K2E when running iperf over the tunnel , 
   PLSDK-1953 ,"am571x-idk, am572x-idk ",Linux PRP: lreTransparentReception - passRCT doesn?t work as expected , 
   PLSDK-1955 ,"am335x-evm, am335x-sk, am437x-sk, am437x-evm, am571x-idk, am572x-idk, am572x-evm ",Matrix Launcher Iterations_Demo:Unable to query physical screen size , 
   PLSDK-1963 ,k2e-evm ,K2E:Observed unwanted failure messages in boot log , 

| 

U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID", "Priority", "Title", "Component", "Subcomponent", "Platform", "Workaround"
   :widths: 15, 10, 70, 10, 10, 30, 5

   LCPD-10911 ,P3-Medium ,Boot device incorrect in u-boot file spl.h for am57xx ,Baseport ,u-boot ,am57xx-evm , 
   LCPD-10805 ,P3-Medium ,U-Boot: Fix uart boot on am335x-evm ,Baseport ,u-boot ,am335x-evm , 
   LCPD-10726 ,P3-Medium ,Update DDR3 emif regs structure for EMIF2 for the beagle_x15 board in U-Boot board file ,Baseport ,  ,"am572x-idk, am57xx-evm ", 
   LCPD-10668 ,P3-Medium ,Ethernet boot: Sometimes the board could not boot uboot from Ethernet on k2g-evm ,Connectivity ,UBOOT ,k2g-evm , 
   LCPD-9539 ,P3-Medium ,dhcp does not work after soft reboot ,Connectivity ,UBOOT ,k2g-evm , 
   LCPD-9369 ,P3-Medium ,AM437x GP EVM older PG version Uboot UART boot fails intermittently ,Baseport ,u-boot ,  , 
   LCPD-8701 ,P3-Medium ,Soft reboot broken ,Baseport ,UBOOT ,k2g-ice , 
   LCPD-8393 ,P3-Medium ,u-boot ramfs boot does not work ,Baseport ,u-boot ,k2g-evm , 
   LCPD-8123 ,P3-Medium ,K2G: MSMC: Memory seen by USB controller not cache-coherent ,Baseport ,UBOOT ,k2g-evm , 
   LCPD-7864 ,P3-Medium ,U-Boot: Ethernet boot fails on AM335x and AM437x ,Connectivity ,  ,"am335x-evm, am335x-ice, am335x-sk, am437x-idk, am437x-sk, am43xx-gpevm ", 
   LCPD-7772 ,P3-Medium ,K2L/K2E: U-Boot: net: dhcp not working when both slave ethernet are connected to ethernet switch ,Connectivity ,UBOOT ,"k2e-evm, k2l-evm ", 
   LCPD-7547 ,P3-Medium ,uboot nand write hangs for big size on k2g ,Connectivity ,UBOOT ,k2g-evm , 
   LCPD-7519 ,P3-Medium ,dfu_get_buf return error when use dfu to update mmc card ,"Baseport, Connectivity ",UBOOT ,am335x-evm , 
   LCPD-7366 ,P3-Medium ,uboot McSPI driver drives multiple chip selects simultaneously ,Connectivity ,UBOOT ,  , 
   LCPD-5612 ,P3-Medium ,k2g_evm: Strange ethernet behavior seen in u-boot after warm reset when using netcp ,Connectivity ,UBOOT ,K2G , 
   LCPD-5517 ,P3-Medium ,Board fails to load bootloader sometimes when eSATA is connected ,Connectivity ,UBOOT ,AM572x , 
   LCPD-5416 ,P3-Medium ,U-BOOT: K2G: ?reset? fails for certain SD cards ,Baseport ,UBOOT ,K2G , 
   LCPD-5320 ,P3-Medium ,Update K2G Pinmuxing in U-boot with buffer class settings ,Baseport ,  ,K2G , 
   LCPD-5116 ,P3-Medium ,BBB: U-Boot: Board fails to acquire dhcp address sometimes ,Connectivity ,UBOOT ,AM335x , 
   LCPD-4817 ,P4-Low ,am57xx-evm: uboot: usb failed to detect Kingston DataTraveler usb msc device ,Connectivity ,UBOOT ,AM572x ,

|


Linux Kernel Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Priority", "Title", "Component", "Subcomponent", "Platform", "Workaround"
   :widths: 5, 10, 70, 10, 5, 20, 35

   LCPD-9877 ,P2-High ,rtc alarm does not wakeup board from poweroff state ,Power & Thermal ,  ,omapl138-lcdk , 
   LCPD-9972 ,P2-High ,Soft reboot failed on k2g-evm with class 10 SD cards ,Connectivity ,  ,k2g-evm , 
   LCPD-10987 ,P3-Medium ,OpenCL tests failed due to missing CMEM carveouts in dts ,"IPC, System Integration ",OpenCL ,am574x-idk , 
   LCPD-9527 ,P3-Medium ,Potential deadlock reported by pm_suspend on am335x ,Power & Thermal ,  ,"am335x-evm, am335x-sk, beaglebone, beaglebone-black ", 
   LCPD-7670 ,P3-Medium ,AM43xx: pm debug counters are wrong ,Power & Thermal ,  ,"am437x-idk, am437x-sk ", 
   LCPD-7314 ,P3-Medium ,Active power is slighly higher than on 2015 LTS release (Linux 4.1) ,Power & Thermal ,  ,am335x-evm , 
   LCPD-7256 ,P3-Medium ,Board sometimes hangs after suspend/resume cycle ,Power & Thermal ,  ,am57xx-evm , 
   LCPD-7165 ,P3-Medium ,Board hangs on standby state sometimes ,Power & Thermal ,  ,"am335x-evm, am43xx-gpevm ", 
   LCPD-6427 ,P3-Medium ,vpe fails to suspend sometimes ,Power & Thermal ,  ,"am571x-idk, am572x-idk, am57xx-evm ", 
   LCPD-1245 ,P3-Medium ,AM335x: Power: Reverse current leakage on poweroff ,Power & Thermal ,  ,am335x-evm , 
   LCPD-1204 ,P3-Medium ,AM335x - Some voltage rails remain active during poweroff ,Power & Thermal ,  ,  , 
   LCPD-965 ,P3-Medium ,AM335x: Power: Poweroff is not shutting down voltage domains ,Power & Thermal ,  ,  , 
   LCPD-11570 ,P3-Medium ,Base ubi filesystem could not be mounted as ubifs on k2g-evm ,Connectivity ,  ,k2g-evm , 
   LCPD-11564 ,P3-Medium ,AM57xx-evm: eth1 1G connection failure to netgear switch ,Connectivity ,"CPSW, ETHERNET, PHYIF ",am57xx-evm , 
   LCPD-11556 ,P3-Medium ,ks3: navss: mem2mem not working ,Connectivity ,NAVSS ,  , 
   LCPD-11121 ,P3-Medium ,Android: ADB Broken ,"Android, Connectivity ",USB ,am57xx-evm , 
   LCPD-10974 ,P3-Medium ,am43xx-gpevm - usb camera gadget shows halting frames ,Connectivity ,USB ,  , 
   LCPD-10863 ,P3-Medium ,am574x-idk: MMC speed is lower than expected in Uboot ,Connectivity ,MMCSD ,am574x-idk , 
   LCPD-10794 ,P3-Medium ,prueth: iperf udp test shows packet loss at low traffic rate such as 50Mbps ,Connectivity ,PRUSS/ETH ,"am335x-ice, am437x-idk, am571x-idk, am572x-idk, k2g-ice ", 
   LCPD-10781 ,P3-Medium ,NetCP module removal results in backtrace and kernel panic ,Connectivity ,NETCP ,k2g-evm , 
   LCPD-10777 ,P3-Medium ,mtd_stresstest failed on omapl138 ,Connectivity ,NAND ,omapl138-lcdk , 
   LCPD-10551 ,P3-Medium ,"K2E eth0 does down when running udp traffic, eth1 stops working ",Connectivity ,NETCP ,k2e-evm , 
   LCPD-10221 ,P3-Medium ,Longer resume times observed on setup with usb device cable ,Connectivity ,USB ,am335x-evm , 
   LCPD-9974 ,P3-Medium ,PCIe x2 width is not at expected width on am571x-idk ,Connectivity ,PCIe ,am571x-idk , 
   LCPD-9905 ,P3-Medium ,AM437x: UART: Implement workaround for Advisory 27 ? Spurious UART interrupts when using EDMA ,Connectivity ,UART ,am43xx-gpevm , 
   LCPD-9816 ,P3-Medium ,USBdevice omapl138 - Flood ping from server to dut usbdevice at 65500 bytes has packet loss ,Connectivity ,USB ,omapl138-lcdk , 
   LCPD-9815 ,P3-Medium ,Failed to start Login Service when using debug systest build on omapl138 ,Connectivity ,  ,omapl138-lcdk , 
   LCPD-9804 ,P3-Medium ,SATA performance decreased by ~34% for read and ~54% for write compared to v2.6.33 kernel ,Connectivity ,SATA ,omapl138-lcdk , 
   LCPD-9658 ,P3-Medium ,OMAP-L138 LCDK: MUSB does not enumerate mouse connected to Keyboard hub ,Connectivity ,USB ,omapl138-lcdk , 
   LCPD-9591 ,P3-Medium ,CONNECTIVITY: USB NCM gadget ping with packet sizes > 10000 fails ,Connectivity ,  ,  , 
   LCPD-9469 ,P3-Medium ,Fix race condition when adding VLAN entries ,Connectivity ,NETCP ,"k2e-evm, k2g-evm, k2g-ice, k2hk-evm, k2l-evm ", 
   LCPD-9466 ,P3-Medium ,SATA PMP causes suspend failures ,Connectivity ,SATA ,am57xx-evm , 
   LCPD-9455 ,P3-Medium ,Kernel Warning reported for a USB audio device when listing with pulseaudio ,Connectivity ,USB ,am335x-evm , 
   LCPD-9428 ,P3-Medium ,Ethernet performace UDP: iperf command fails with two threads for lower buffer length ,Connectivity ,NETCP ,"k2e-evm, k2hk-evm, k2l-evm ", 
   LCPD-9372 ,P3-Medium ,Nand stress tests failed on am335x-evm ,Connectivity ,NAND ,am335x-evm , 
   LCPD-9366 ,P3-Medium ,PCIe USB drive sometimes could not be enumerated ,Connectivity ,PCIe ,k2g-evm , 
   LCPD-9011 ,P3-Medium ,K2G-evm: usb devices do not enumerate behind a TUSB8041 usb3.0 hub ,Connectivity ,USB ,  , 
   LCPD-8984 ,P3-Medium ,Kernel boot to initramfs with PA enabled results in no DHCP IP address assigned to network interfaces ,Connectivity ,NETCP ,"k2e-evm, k2l-evm ", 
   LCPD-8637 ,P3-Medium ,K2HK: Long-term ping test fails due to ethernet link going down ,Connectivity ,  ,  , 
   LCPD-8636 ,P3-Medium ,Serial corruption being seen in kernel ,Connectivity ,UART ,am335x-evm , 
   LCPD-8354 ,P3-Medium ,K2G EVM: Need to use PMT data ,"Audio & Display, Baseport, Connectivity ",PINMUX ,k2g-evm , 
   LCPD-8353 ,P3-Medium ,K2G ICE: Need to use PMT data ,"Audio & Display, Baseport, Connectivity ",PINMUX ,k2g-ice , 
   LCPD-8133 ,P3-Medium ,USB: ?cannot reset? errors observed sometimes ,Connectivity ,USB ,am335x-evm , 
   LCPD-8100 ,P3-Medium ,CONNECTIVITY: K2G ethernet performance numbers are low ,Connectivity ,NETCP ,k2g-evm , 
   LCPD-8078 ,P3-Medium ,AM3 SK: Touchscreen isn?t responsive ,"Audio & Display, Connectivity ",  ,am335x-sk , 
   LCPD-8033 ,P3-Medium ,AM3 SK: Unexpected USB2-1 Messages on UART ,Connectivity ,USB ,  , 
   LCPD-7955 ,P3-Medium ,Uncorrectable Bitflip errors seen after switch to SystemD ,Connectivity ,GPMC ,"am335x-evm, am43xx-gpevm, k2e-evm, k2g-evm, k2g-ice, k2hk-evm, k2hk-hsevm, k2l-evm ",Workaround to erase the NAND flash completely if flashed with an incompatible flash writer. SystemD tries to mount all partitions and that is the reason this is being seen now.
   LCPD-7829 ,P3-Medium ,uboot: UHS card did not work on the expected speed in uboot ,Connectivity ,  ,am57xx-evm , 
   LCPD-7744 ,P3-Medium ,UHS SDR104 card works on different speed after soft reboot ,Connectivity ,  ,am57xx-evm , 
   LCPD-7623 ,P3-Medium ,Seeing SPI transfer failed error sometimes on k2hk when using rt kernel ,Connectivity ,SPI ,k2hk-evm , 
   LCPD-7613 ,P3-Medium ,Ethernet on port eth1 unstable - possibly iodelay value issue ,"Connectivity, System Test ",CPSW ,am57xx-evm , 
   LCPD-7559 ,P3-Medium ,K2E/K2HK does not enumerate usb3 devices through usb3.0 hub ,Connectivity ,USB ,"k2e-evm, k2hk-evm ", 
   LCPD-7266 ,P3-Medium ,CONNECTIVITY: USB RNDIS performance issues in 4.4 kernel ,Connectivity ,USB ,  , 
   LCPD-7265 ,P3-Medium ,Uboot eMMC does not use HS200 on am57xx-gpevm ,Connectivity ,  ,am57xx-evm , 
   LCPD-7146 ,P3-Medium ,AM437x: USB causes higher suspend power after first iteration ,Connectivity ,USB ,am43xx-gpevm , 
   LCPD-6334 ,P3-Medium ,k2g-evm: NAND is untestable due to data corruption issues ,Connectivity ,  ,k2g-evm , 
   LCPD-6300 ,P3-Medium ,am57xx-evm: A few UHS cards could not be numerated in kernel and mmc as rootfs failed. ,Connectivity ,  ,am57xx-evm , 
   LCPD-6144 ,P3-Medium ,am572x-idk: eMMC failed to enumerate ,Connectivity ,MMCSD ,am572x-idk , 
   LCPD-5699 ,P3-Medium ,pci: am572x-idk: pci broadcom card doesn?t enumerate ,Connectivity ,  ,"AM571x, AM572x ", 
   LCPD-5677 ,P3-Medium ,K2E-evm: Marvel SATA controller could not be detected sometimes when Power On Reset is involved ,Connectivity ,  ,K2E , 
   LCPD-5522 ,P3-Medium ,pcie-usb sometimes the usb drive/stick could not be enumerated ,Connectivity ,  ,"am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm ", 
   LCPD-5362 ,P3-Medium ,MUSB: Isoch IN only utilises 50% bandwidth ,Connectivity ,USB ,AM335x , 
   LCPD-5308 ,P3-Medium ,i897: USB Stop Endpoint doesnt work in certain circumstances ,Connectivity ,USB ,"AM437x, AM571x, AM572x, K2E, K2G, K2HK, K2L ", 
   LCPD-4849 ,P3-Medium ,K2hk: Connectivity: UART data corruption observed sometimes in loopback mode ,Connectivity ,  ,  , 
   LCPD-4503 ,P3-Medium ,ALL: 8250 UART driver not enabeld as wake source by default ,Connectivity ,UART ,  , 
   LCPD-1239 ,P3-Medium ,Connectivity: could not resume when PCI-SATA card is in ,Connectivity ,PCIe ,"am572x-idk, am57xx-evm ", 
   LCPD-1198 ,P3-Medium ,"am43xx-gpevm:Connectivity: when kmemleak debug is enabled and mmc stress test is run, OOM killer is seen to kick in. Does not happen without kernel debug. ",Connectivity ,  ,  , 
   LCPD-1144 ,P3-Medium ,Logitech USB-PS/2 Optical Mouse cannot be detected every other time the system is suspended/resumed (AM335x-EVM) ,Connectivity ,  ,  , 
   LCPD-1106 ,P3-Medium ,Connectivity:PCIe-SATA ext2 1G write performance is poor due to ata failed command ,Connectivity ,PCIe ,am57xx-evm , 
   LCPD-932 ,P3-Medium ,AM33X: CONNECTIVITY: MUSB MSC read numbers are lower in 3.14 compared to 3.12 ,Connectivity ,USB ,  , 
   LCPD-869 ,P3-Medium ,AM335x: Connectivity: USB data transfer fails if board is suspended/resumed ,Connectivity ,  ,  , 
   LCPD-662 ,P3-Medium ,CONNECTIVITY: AM335X: distortion in USB audio when msc connect/disconnect happens in parallel ,Connectivity ,  ,  , 
   LCPD-553 ,P3-Medium ,AM33XX: CONNECTIVITY: RNDIS performance drops after revert of advisory revert ,Connectivity ,USB ,  , 
   LCPD-11546 ,P3-Medium ,Rare kernel crash triggered by task_blocks_on_rt_mutex ,Baseport ,  ,"am574x-idk, k2e-evm ", 
   LCPD-10533 ,P3-Medium ,Cryptos: SHA1_Hash demo test fails on AM3/4/5 platforms ,Baseport ,  ,"am335x-evm, am335x-ice, am43xx-gpevm, am571x-idk, am572x-idk, am574x-idk, am57xx-evm ", 
   LCPD-10451 ,P3-Medium ,Context switch delay increased based on LMBench numbers ,Baseport ,  ,"am335x-evm, am43xx-gpevm, am571x-idk, am572x-idk, am574x-idk, am57xx-evm ", 
   LCPD-9981 ,P3-Medium ,Some LTP?s memory management tests fail due to low amount of free memory ,Baseport ,  ,omapl138-lcdk , 
   LCPD-9980 ,P3-Medium ,LTP?s math tests float_exp_log and float_trigo fail due to OOM ,Baseport ,  ,omapl138-lcdk , 
   LCPD-9756 ,P3-Medium ,"pm_runtime does not kicks in for some IPs (serial, gpio and wdt) ",Baseport ,  ,omapl138-lcdk , 
   LCPD-8640 ,P3-Medium ,Crypto performance for AES drops 3-10% in 2016.05 ,Baseport ,  ,  , 
   LCPD-8550 ,P3-Medium ,CPSW memory allocation errors seen during boot ,"Audio & Display, Baseport ",  ,am335x-sk , 
   LCPD-8406 ,P3-Medium ,K2G: PADCONFIG_202 register cannot be re-programmed ,Baseport ,  ,"k2g-evm, k2g-ice ",This has proven to be a silicon issue related to locking RSTMUX. It is currently being discussed if it will be fixed in a newer silicon revision. Currently to avoid this issue the affected pins pinmux are not changed in the kernel. This is because U-boot locks RSTMUX which causes problems if the kernel tries to change the pinmuxing for the pins.
   LCPD-8350 ,P3-Medium ,UART boot does not work on am57xx-evm ,Baseport ,  ,am57xx-evm , 
   LCPD-8347 ,P3-Medium ,BUG: sleeping function called from invalid context triggered by keystone_pcie_fault ,Baseport ,  ,"k2e-evm, k2g-evm ", 
   LCPD-8257 ,P3-Medium ,Boot failed 1 of 1000 times on k2g ,Baseport ,  ,k2g-evm , 
   LCPD-7486 ,P3-Medium ,uboot debug with ccs is failing for K2 ,Baseport ,  ,k2hk-evm , 
   LCPD-7222 ,P3-Medium ,Asynchronous abort seen during soft reboot from kernel ,Baseport ,  ,k2g-evm , 
   LCPD-6998 ,P3-Medium ,K2G sometimes boot failed with kernel oops error ,Baseport ,  ,k2g-evm , 
   LCPD-6663 ,P3-Medium ,[RT] Kmemleak is buggy and boot is crashed randomly ,Baseport ,  ,  , 
   LCPD-5537 ,P3-Medium ,kmemleak: Could not scan kmemleak due to object search tree errors ,Baseport ,  ,"AM571x, AM572x ", 
   LCPD-615 ,P3-Medium ,ALL:BASEPORT: Opening several RTC nodes leads to failure ,Baseport ,  ,  , 
   LCPD-614 ,P3-Medium ,ALL:BASEPORT: RTC allows to be written to in RDONLY mode ,Baseport ,  ,  , 
   LCPD-11138 ,P3-Medium ,VIP driver multi-channel capture issue with TVP5158 ,Audio & Display ,"Capture, VIP ","am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm ", 
   LCPD-10954 ,P3-Medium ,DSS sync-losts and underflows seen with bad config ,Audio & Display ,Display ,am437x-sk , 
   LCPD-7735 ,P3-Medium ,Powerdomain (vpe_pwrdm) didn?t enter target state 0 ,"Audio & Display, Power & Thermal ",  ,am57xx-evm , 
   LCPD-7696 ,P3-Medium ,VPE: File2File checksum changes across multiple runs ,Audio & Display ,  ,"am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm ",There is no workaround for this issue yet
   LCPD-6377 ,P3-Medium ,OMAP_BO_CACHED feature not functional ,"Audio & Display, Multimedia ",Display ,"am437x-idk, am437x-sk, am43xx-gpevm, am43xx-hsevm, am571x-idk, am572x-idk, am57xx-evm, k2g-evm ", 
   LCPD-5380 ,P3-Medium ,omapdss error: HDMI I2C Master Error ,Audio & Display ,  ,AM572x ,Occurs only with this monitor - http://www.amazon.com/gp/product/B00PFLZV2G
   LCPD-4858 ,P4-Low ,Power: pm_debug state counters are not increased during suspend ,Power & Thermal ,  ,"AM335x, AM437x ", 
   LCPD-4779 ,P4-Low ,"coreaon, wkupaon and rtc power domains OFF counters are increasing during SUSPEND ",Power & Thermal ,  ,"AM571x, AM572x ", 
   LCPD-1191 ,P4-Low ,AM335x: Power: System resumes due to wakeup source USB1_PHY without any external trigger ,Power & Thermal ,  ,  ,Use GPIO interrupt instead of USB PHY for wakeup source.
   LCPD-1013 ,P4-Low ,AM335x: Power: Seldom short-duration power increase (~38mw) in VDDSHV4 domain ,Power & Thermal ,  ,  , 
   LCPD-747 ,P4-Low ,Power: cpuidle states shows bogus power in stats ,Power & Thermal ,  ,"am437x-idk, am437x-sk, am43xx-gpevm, am43xx-hsevm ", 
   LCPD-565 ,P4-Low ,AM43xx: Power & Thermal: Board hangs in suspend state if function_graph tracer is enabled ,Power & Thermal ,  ,  , 
   LCPD-287 ,P4-Low ,am335x: Power & Thermal: pm_debug stats might not be updated ,Power & Thermal ,  ,  , 
   LCPD-10455 ,P4-Low ,remoteproc/keystone: Hang observed while running RPMSG_PROTO example app ,IPC ,DSP_remoteproc ,"k2g-evm, k2g-ice, k2hk-evm, k2l-evm ", 
   LCPD-9801 ,P4-Low ,remoteproc/davinci: DSP boot is broken after a suspend/resume cycle ,IPC ,DSP_remoteproc ,omapl138-lcdk , 
   LCPD-9481 ,P4-Low ,Sometime the system hangs while loading the rpmsg rpc modules ,IPC ,RPMSG-RPC ,"am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm ", 
   LCPD-7495 ,P4-Low ,Sometimes a Kernel Warning + Oops is seen when removing keystone_remoteproc module ,IPC ,  ,k2hk-evm , 
   LCPD-4855 ,P4-Low ,[rpmsg 2015 LTS] IPC: Board hangs when an MMU fault occurs in the first message ,IPC ,  ,am572x-idk , 
   LCPD-4699 ,P4-Low ,rpmsg-rpc: kernel crash during error recovery with dynamic debug traces enabled ,IPC ,  ,"am571x-idk, am572x-idk, am57xx-evm ", 
   LCPD-9589 ,P4-Low ,I2C: Sometimes i2c read write failed on farm01 and farm02 ,Connectivity ,  ,am335x-evm , 
   LCPD-9222 ,P4-Low ,PRUSS Ethernet does not work on AM572x ES1.1 ,Connectivity ,PRUSS-Ethernet ,am572x-idk , 
   LCPD-8987 ,P4-Low ,There is timeout error occasionaly when do mkfs.ext2 on emmc ,Connectivity ,MMCSD ,am43xx-gpevm , 
   LCPD-8477 ,P4-Low ,K2: serdes nodes doesn?t have a functional clock ,Connectivity ,SERDES ,"k2e-evm, k2e-hsevm, k2g-evm, k2g-ice, k2hk-evm, k2hk-hsevm, k2l-evm, k2l-hsevm ", 
   LCPD-8270 ,P4-Low ,K2: SerDes driver need to enable PD of the peripheral before access the SerDes h/w ,Connectivity ,SERDES ,k2g-evm , 
   LCPD-7998 ,P4-Low ,Realtime OSADL Test results degraded slightly for am572x-idk ,Connectivity ,  ,am572x-idk , 
   LCPD-7480 ,P4-Low ,K2L/E EVMs doesn?t boot to Linux when both 1G Ethernet interfaces are connected ,Connectivity ,  ,"k2e-evm, k2l-evm ", 
   LCPD-7188 ,P4-Low ,PCIe-SATA test failed ,Connectivity ,  ,am57xx-evm ,TI custom board would help with signal integrity issues being seen with the EVM.
   LCPD-1207 ,P4-Low ,AM43XX/AM57XX: CONNECTIVITY: dwc3_omap on am43xx and xhci_plat_hcd on am57xx - removal results in segmentation fault ,Connectivity ,USB ,  , 
   LCPD-998 ,P4-Low ,MUSB does not free urbs causing usb audio playback to fail ,Connectivity ,  ,AM335x , 
   LCPD-983 ,P4-Low ,AM335x: USB: disconnect and reconnect of hub during camera test results in capture failure ,Connectivity ,USB ,  , 
   LCPD-671 ,P4-Low ,AM33XX: CONNECTIVITY: MUSB in PIO mode - video issues ,Connectivity ,  ,  , 
   LCPD-525 ,P4-Low ,AM438x: Connectivity: I2C operates 9% beyond desired frequency ,Connectivity ,  ,  , 
   LCPD-11011 ,P4-Low ,Change Compression: Improve Boot performance ,"Android, Baseport ",  ,  , 
   LCPD-10223 ,P4-Low ,Keystone-2 Linking RAM region 0 size register REGION0_SIZE programming ,Baseport ,  ,k2hk-evm , 
   LCPD-6075 ,P4-Low ,BUG: using smp_processor_id() in preemptible [00000000] code during remoteproc suspend/resume ,"Baseport, IPC ",  ,"am572x-idk, am57xx-evm ", 
   LCPD-9436 ,P4-Low ,DRM: plane zorders must be unique ,Audio & Display ,Display ,"am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm ", 
   LCPD-9098 ,P4-Low ,Writeback: error prints seen when doing wb capture ,Audio & Display ,"Capture, Display, Writeback ","am571x-idk, am572x-idk, am57xx-evm ", 
   LCPD-8884 ,P4-Low ,VIP does not work after incorrectly configuring captured YUYV frame as NV12 ,Audio & Display ,"Capture, VIP ",  , 
   LCPD-5059 ,P4-Low ,omapdrm: moving plane from one enabled display to another causes errors ,Audio & Display ,Display ,  , 
   LCPD-4681 ,P4-Low ,omapdrm: an error when enabling a display is not handled correctly ,Audio & Display ,Display ,  , 
   LCPD-1171 ,P4-Low ,DMM errata i878 (framebuffer part) ,Audio & Display ,"Display, TILER ","am571x-idk, am572x-idk, am57xx-evm ", 

|

RT Linux Kernel Known Issues
-----------------------------

.. csv-table::
   :header: "Record ID", "Priority", "Title", "Component", "Subcomponent", "Platform", "Workaround"
   :widths: 5, 10, 70, 10, 5, 20, 15

   LCPD-6663 ,P3-Medium ,[RT] Kmemleak is buggy and boot is crashed randomly ,Baseport ,  ,  , 
   LCPD-7623 ,P3-Medium ,Seeing SPI transfer failed error sometimes on k2hk when using rt kernel ,Connectivity ,SPI ,k2hk-evm , 
   LCPD-11546 ,P3-Medium ,Rare kernel crash triggered by task_blocks_on_rt_mutex ,Baseport ,  ,"am574x-idk, k2e-evm ", 

|

.. rubric:: Installation and Usage
   :name: installation-and-usage

The `Software Developer's
Guide <Overview.html#processor-sdk-linux-software-developer-s-guide>`__
provides instructions on how to setup up your Linux development
environment, install the SDK and start your development.  It also
includes User's Guides for various Example Applications and Code
Composer Studio.

| 

.. rubric:: Host Support
   :name: host-support

The Processor SDK is developed, built and verified on Ubuntu 14.04 and
16.04.   Details on how to create a virtual machine to load Ubuntu 14.04
are described in `this
page <Processor_Linux_SDK_How_To_Guides.html#how-to-build-a-ubuntu-linux-host-under-vmware>`__.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
Processor SDK Installer is 64-bit, and installs only on 64-bit host
machine. Support for 32-bit host is dropped as Linaro toolchain is
available only for 64-bit machines

.. raw:: html

   </div>

| 

