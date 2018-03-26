.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Release_Notes

************************************
Release Notes
************************************

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

Release 04.03.00
================

Released Mar 2018

.. rubric:: What's New
   :name: whats-new

-  New Demos
    -  Qt5-based Thermostat demo on AM335x/AM437x/AM57x
    -  Demonstrate 4K Video Encode with IVAHD on AM57x
    -  Khronos OpenVX based demo example with C66x offload via OpenCL
    -  ROS Turtlebot based demo using AM335x/AM437x/AM57x and Processor Linux SDK

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

.. rubric:: Kernel and U-boot Details
   :name: kernel-and-u-boot-details

Kernel Details:

-  `Kernel Release
   Notes <http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Kernel_Release_Notes>`__
-  `Real Time (RT) Kernel Release
   Notes <http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_RT_Kernel_Release_Notes>`__
-  `Kernel Performance
   Guide <http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Kernel_Performance_Guide>`__
-  `Real Time (RT) Kernel Performance
   Guide <http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_RT_Kernel_Performance_Guide>`__

| 
| U-boot Details:

-  `U-boot Release
   Notes <http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_U-Boot_Release_Notes>`__

| 

.. rubric:: Supported Platforms
   :name: supported-platforms

See :ref:`SDK-Supported-Platforms` for a list of supported platforms and links to more information.

.. rubric:: Issues Tracker
   :name: issues-tracker

.. rubric:: Issues opened in previous releases that were closed on this
   release
   :name: issues-opened-in-previous-releases-that-were-closed-on-this-release

+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| **Record ID**   | **Platform**                                                                                                                                                                                                                 | **Title**                                                                               |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| LCPD-10702      | am571x-idk                                                                                                                                                                                                                   | AM571x IDK: pruss1\_eth is not initialized and the corresponding eth ports are not up   |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| LCPD-9752       | am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm                                                                                                                                                                             | VIP test cases fail, log shows error setting crop                                       |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| LCPD-10784      | am571x-idk                                                                                                                                                                                                                   | am571x-idk: Board can be booted in invalid configuration                                |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| LCPD-9876       | am43xx-gpevm                                                                                                                                                                                                                 | Try\_fmt does not work as expected                                                      |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| LCPD-8823       | am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm, k2e-evm, k2g-evm, k2g-ice, k2hk-evm, k2l-evm, omapl138-lcdk                                                                                                                | rpmsg: Don't Announce to Remote Core when Binding                                       |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| LCPD-9617       | am571x-idk, am572x-idk                                                                                                                                                                                                       | Failures with PCIe Wireless Cards with 4 DMA Queues                                     |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| LCPD-6374       | am335x-evm, am335x-ice, am335x-sk, am437x-idk, am437x-sk, am43xx-gpevm, am43xx-hsevm, am571x-idk, am572x-idk, am57xx-evm, beaglebone, beaglebone-black, beaglebone-black-ice, k2e-evm, k2g-evm, k2g-ice, k2hk-evm, k2l-evm   | realtime kernel LTP Priority Ordered Wakeup test hangs                                  |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| LCPD-10346      | am43xx-gpevm                                                                                                                                                                                                                 | CoreSDK u-boot image for am437x is corrupted                                            |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| LCPD-10413      | am571x-idk, am572x-idk, am57xx-evm                                                                                                                                                                                           | Cache misaligned messages seen during non HS boot                                       |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| LCPD-4592       | AM572x                                                                                                                                                                                                                       | omap\_hwmod\_addr\_space cleanup: remove omap\_hwmod\_addr\_space usage for hdq         |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| PLSDK-1231      | am572x-evm                                                                                                                                                                                                                   | Matrix demo doesn't display on HDMI                                                     |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| PLSDK-1418      | k2h-evm, k2e-evm, k2l-evm                                                                                                                                                                                                    | IPSEC Inflow mode not supported on 2017 LTS                                             |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| PLSDK-1512      | am571x-idk                                                                                                                                                                                                                   | ICSS-EMAC\_unittest test fails on AM571 IDK platform due to PRU1 ETH0/1 link down       |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| PLSDK-1597      | AM335x, AM437X, AM57x                                                                                                                                                                                                        | Yocto build for parts with no SGX fails                                                 |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| PLSDK-1599      | AM57x                                                                                                                                                                                                                        | Net-SNMP IEC-62439-3-MIB::lreManufacturerName.0 has spurious characters                 |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| PLSDK-1600      | am571x-idk, am572x-idk                                                                                                                                                                                                       | prueth: VLAN support is broken                                                          |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| PLSDK-1617      | am572x-idk                                                                                                                                                                                                                   | prueth: when system is loaded, prueth driver transmit function times out                |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| PLSDK-1619      | k2e-evm                                                                                                                                                                                                                      | KS2 XGE kernel crashes with inbound traffic at MTU greater than 1500                    |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| PLSDK-1629      | am571x-idk, am572x-idk                                                                                                                                                                                                       | HSR: NetJuryL ARP response showed incorrect LSDU size                                   |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| PLSDK-1647      | am571x-idk, am572x-idk                                                                                                                                                                                                       | HSR/PRP: Fix duplicate detect entry forget timer in the driver                          |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| PLSDK-1673      | K2, AM57x                                                                                                                                                                                                                    | Fix virtual address space leak in OpenCL runtime                                        |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| PLSDK-1681      | am571x-idk, am572x-idk                                                                                                                                                                                                       | PRP: Supervision frame should contain TLV type 21 when Duplicate Accept is enabled      |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| PLSDK-1685      | am571x-idk, am572x-idk                                                                                                                                                                                                       | NetSNMP: hsr/prp: fix set command for PRP duplicate discard mode                        |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| PLSDK-1704      | am571x-idk, am572x-idk                                                                                                                                                                                                       | PRP: RCT is not stripped by DAN when sending frames to SAN                              |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| PINDSW-2160     | am571x-idk, am572x-idk                                                                                                                                                                                                       | HSR/PRP: Supervision frame has incorrect start\_offset, but tag is present              |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| PINDSW-2137     | am571x-idk, am572x-idk                                                                                                                                                                                                       | HSRPRP: Ethernet frames with self MAC address is dropped, but stats not updated         |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+
| PINDSW-1841     | am571x-idk, am572x-idk                                                                                                                                                                                                       | Incorrect statistics handling for Supervision frames looping back to source DUT         |
+-----------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+-----------------------------------------------------------------------------------------+

| 

.. rubric:: Issued found and closed on this release that may be
   applicable to prior releases
   :name: issued-found-and-closed-on-this-release-that-may-be-applicable-to-prior-releases

+-----------------+----------------------------------------------------+----------------------------------------------------------------+
| **Record ID**   | **Platform**                                       | **Title**                                                      |
+-----------------+----------------------------------------------------+----------------------------------------------------------------+
| LCPD-10915      | k2g-evm                                            | Failed to probe qspi on k2g-evm RevD                           |
+-----------------+----------------------------------------------------+----------------------------------------------------------------+
| LCPD-10852      | am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm   | RGB24 capture output is not correct                            |
+-----------------+----------------------------------------------------+----------------------------------------------------------------+
| LCPD-10894      | am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm   | omapdrm: Fix a missing dma\_mapping\_error                     |
+-----------------+----------------------------------------------------+----------------------------------------------------------------+
| LCPD-10895      | am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm   | rpmsg: rpc: suspicious RCU usage on fcheck                     |
+-----------------+----------------------------------------------------+----------------------------------------------------------------+
| LCPD-10864      | am57xx-evm                                         | There is some warning messages from get\_part\_size in uboot   |
+-----------------+----------------------------------------------------+----------------------------------------------------------------+

| 

.. rubric:: Errata Workarounds Available in this Release
   :name: errata-workarounds-available-in-this-release

+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| **Record ID**   | **Title**                                                                                                                |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-7642       | MMC/SD: i832: return DLL to default reset state with CLK gated if not in SDR104/HS200 mode.                              |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-9084       | i887: Software workaround to limit mmc3 speed to 64MHz                                                                   |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-5311       | i893: DCAN ram init issues in HW AUTO and when traffic hitting CAN bus (open investigation)                              |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-5309       | LCPD: i896: USB Port disable doesnt work                                                                                 |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-5310       | i900: CTRL\_CORE\_MMR\_LOCK\_5 region after locking results in ctrl module inaccessible, recoverable only post a reset   |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-4184       | Implement workaround for errata i814 - Bandgap Temperature read Dtemp can be corrupted                                   |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-4218       | Implement Workaround for Errata i813 - Spurious Thermal Alert Generation When Temperature Remains in Expected Range      |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-4217       | Implement Workaround for Errata i814 - Bandgap Temperature read Dtemp can be corrupted                                   |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-8294       | 37 pins + VOUT pins need slow slew enabled for timing and reliability respectively                                       |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-9173       | i897: USB Stop Endpoint doesnt work in certain circumstances                                                             |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-5924       | ALL: CONNECTIVITY: CPSW: errata i877 workarround for cpsw                                                                |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-5052       | Upstream: Post the dmtimer errata fix for i874                                                                           |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-4975       | DSS AM5: implement WA for errata i886                                                                                    |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-4647       | [rpmsg 2015 LTS] Implement errata i879 - DSP MStandby requires CD\_EMU in SW\_WKUP                                       |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-4648       | [rpmsg 2014 LTS] Implement errata i879 - DSP MStandby requires CD\_EMU in SW\_WKUP                                       |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-1146       | DMM hang: Errata VAYU-BUG02976 (i878) (register part)                                                                    |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+
| LCPD-6907       | Workaround errata i880 for RGMII2 is missing                                                                             |
+-----------------+--------------------------------------------------------------------------------------------------------------------------+

| 

.. rubric:: Known Issues
   :name: known-issues

+--------------------+--------------------+--------------------+--------------------+
| **Record ID**      | **Platform**       | **Title**          | **Workaround**     |
+--------------------+--------------------+--------------------+--------------------+
| LCPD-5578          | beaglebone-black   | Exception          | Build Processor    |
|                    |                    | triggered by       | SDK without SGX    |
|                    |                    | graphics driver    | following          |
|                    |                    | during boot if     | instructions       |
|                    |                    | board does not     | `here <http://proc |
|                    |                    | have SGX (BBB A4)  | essors.wiki.ti.com |
|                    |                    |                    | /index.php/Process |
|                    |                    |                    | or_SDK_Building_Th |
|                    |                    |                    | e_SDK#Rebuilding_w |
|                    |                    |                    | ithout_SGX>`__     |
+--------------------+--------------------+--------------------+--------------------+
| LCPD-7025          | am43xx-gpevm       | System takes more  | Automated tests    |
|                    |                    | than 10 seconds to | need to account    |
|                    |                    | go from login      | for this boot      |
|                    |                    | prompt to system   | delay              |
|                    |                    | prompt             |                    |
+--------------------+--------------------+--------------------+--------------------+
| LCPD-7255          | All                | Telnet login takes | Booting with       |
|                    |                    | too long (~40      | rootfs mounted     |
|                    |                    | seconds)           | over NFS might     |
|                    |                    |                    | cause ~40 seconds  |
|                    |                    |                    | delay on Telnet    |
|                    |                    |                    | login because DNS  |
|                    |                    |                    | entries might not  |
|                    |                    |                    | be properly        |
|                    |                    |                    | populated. To work |
|                    |                    |                    | around this issue, |
|                    |                    |                    | enter appropriate  |
|                    |                    |                    | DNS server IP in   |
|                    |                    |                    | resolv.conf. For   |
|                    |                    |                    | example: echo      |
|                    |                    |                    | 'nameserver        |
|                    |                    |                    | 192.0.2.2' >       |
|                    |                    |                    | /etc/resolv.conf;  |
+--------------------+--------------------+--------------------+--------------------+
| LCPD-8210          | am57xx-evm,        | QT Touchscreen     | None               |
|                    | am571x-idk,        | interaction (Bear  |                    |
|                    | am572x-idk         | Whack) crash       |                    |
+--------------------+--------------------+--------------------+--------------------+
| LCPD-8345          | am335x-evm,        | Board fails to     | Restart the EVM    |
|                    | am437x-idk,        | start login        |                    |
|                    | k2e-evm,           | console after      |                    |
|                    | k2e-hsevm,         | waiting 3.5        |                    |
|                    | k2hk-evm, k2l-evm  | minutes ( hard to  |                    |
|                    |                    | reproduce,         |                    |
|                    |                    | ~4/1000)           |                    |
+--------------------+--------------------+--------------------+--------------------+
| LCPD-8352          | am43xx-gpevm,      | weston: stress     | 1. Restart Wayland |
|                    | am57xx-evm         | testing with 75    | application. 2.    |
|                    |                    | concurrent         | Restart board if   |
|                    |                    | instances of       | Weston is killed   |
|                    |                    | simple-egl leads   | by oom-killer      |
|                    |                    | to unresponsive    |                    |
|                    |                    | HMI due to running |                    |
|                    |                    | out of memory      |                    |
+--------------------+--------------------+--------------------+--------------------+
| LCPD-9616          | am57xx-evm         | QtCreator GDB      | use GDB from       |
|                    |                    | (remote) debugging | Processor SDK 3.2  |
|                    |                    | stops working      |                    |
|                    |                    | since QT5.7.1      |                    |
+--------------------+--------------------+--------------------+--------------------+
| LCPD-10976         | am57xx-evm         | Weston memory leak |                    |
|                    |                    | related to HDMI    |                    |
|                    |                    | hotplug            |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-780          | AM5X               | Failing to create  | Upper limit on #   |
|                    |                    | more then 10 gst   | of simultaneous    |
|                    |                    | pipeline using     | video channels is  |
|                    |                    | ductai codec       | 10.                |
|                    |                    | plugins            |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-832          | AM57               | OpenCL matmpy      | Disable DSP        |
|                    |                    | intermittent DSP1  | suspend/resume     |
|                    |                    | crash due to       | echo "on" >        |
|                    |                    | EdmaMgr issues w/  | /sys/bus/platform/ |
|                    |                    | suspend/resume     | devices/40800000.d |
|                    |                    |                    | sp/power/control   |
|                    |                    |                    | echo "on" >        |
|                    |                    |                    | /sys/bus/platform/ |
|                    |                    |                    | devices/41000000.d |
|                    |                    |                    | sp/power/control   |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-885          | AM57               | OpenCV Video test  | Use the workaround |
|                    |                    | failure w/         | from PLSDK-832     |
|                    |                    | GStreamer errors   |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1312         | k2h-evm, k2e-evm,  | QoS test fails due | None               |
|                    | k2l-evm            | to missing         |                    |
|                    |                    | qos-inputs-0 on K2 |                    |
|                    |                    | platforms          |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1398         | k2e-evm, k2e-hsevm | Matrix IPC demo    | Run IPC demo w/o   |
|                    |                    | seems hangs, if    | running OpenCL     |
|                    |                    | run after OpenCL   | first              |
|                    |                    | demos, on K2E      |                    |
|                    |                    | platform           |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1419         | k2l-evm            | Intermittent-IP    | Use ifconfig once  |
|                    |                    | address display    | Linux boots, to    |
|                    |                    | issue on LCD for   | acquire ip address |
|                    |                    | K2L RT             |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1421         | k2hk-evm           | SRIO is not        | None               |
|                    |                    | functional on 2017 |                    |
|                    |                    | LTS                |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1432         | k2hk-evm           | 10G UBoot support  | None               |
|                    |                    | broken on K2, in   |                    |
|                    |                    | 2017LTS            |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1524         | am572x-idk         | OPC UA demo failed |                    |
|                    |                    | on AM572-IDK       |                    |
|                    |                    | platform           |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1540         | am335x-evm,        | AM3 and AM4 Build  |                    |
|                    | am437x-evm         | WPANTUND: Unable   |                    |
|                    |                    | to find a usable   |                    |
|                    |                    | implementation of  |                    |
|                    |                    | boost::signals2    |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1556         | k2hk-evm,          | PDK:               | Just a warning     |
|                    | k2hk-hsevm,        | saBasicExample     | message. No impact |
|                    | k2e-evm, k2l-evm   | test shows warning | to test output     |
|                    |                    | as 'Alignment      |                    |
|                    |                    | trap' on K2x       |                    |
|                    |                    | platforms.         |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1602         | am437x-evm         | Simple people      |                    |
|                    |                    | tracking demo:     |                    |
|                    |                    | Bulk transfer      |                    |
|                    |                    | failed, observed   |                    |
|                    |                    | inconsistent       |                    |
|                    |                    | behavior of the    |                    |
|                    |                    | application        |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1603         | am571x-idk,        | Received bad addr  |                    |
|                    | am572x-idk,        | len cause the      |                    |
|                    | am572x-evm         | OpenAMP test       |                    |
|                    |                    | failure when DSP   |                    |
|                    |                    | is redownloaded on |                    |
|                    |                    | AM57xx platforms   |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1612         | am335x-sk          | Matrix GUI only    |                    |
|                    |                    | displays on first  |                    |
|                    |                    | boot on AM335x     |                    |
|                    |                    | Starter Kit        |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1625         | am571x-idk,        | prueth: netdev     | A workaround is    |
|                    | am572x-idk,        | watchdog fires     | already            |
|                    | am574x-idk         | under heavy load   | implemented in     |
|                    |                    |                    | software for this  |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1631         | k2e-hsevm          | PDK: paMCExample   |                    |
|                    |                    | test case          |                    |
|                    |                    | execution expires  |                    |
|                    |                    | due to             |                    |
|                    |                    | unsuccessful       |                    |
|                    |                    | packet transfer.   |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1675         | am572x-evm         | Matrix Demo:       |                    |
|                    |                    | Observed unwanted  |                    |
|                    |                    | failure message in |                    |
|                    |                    | QT touch and       |                    |
|                    |                    | Browser related    |                    |
|                    |                    | test               |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1687         | am570x-evm,        | ERROR: Invalid GPT |                    |
|                    | am571x-idk,        | observed in Boot   |                    |
|                    | am572x-idk,        | log on AM5         |                    |
|                    | am572x-evm,        | platforms          |                    |
|                    | am572x-hsevm,      |                    |                    |
|                    | am574x-idk         |                    |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1693         | am572x-evm         | Incorrect          |                    |
|                    |                    | behaviour observed |                    |
|                    |                    | for HDMI matrix on |                    |
|                    |                    | AM572x-GP EVM      |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1707         | am571x-idk,        | prueth:            | Only impact the    |
|                    | am572x-idk         | debugfs\_create\_d | debug stats        |
|                    |                    | ir()               | display. No other  |
|                    |                    | fails during boot  | functionality      |
|                    |                    | and error message  | affected           |
|                    |                    | shown              |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1711         | am438x-epos-evm    | AM438x-EPOS:       |                    |
|                    |                    | Observed unwanted  |                    |
|                    |                    | message in boot    |                    |
|                    |                    | log                |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1712         | am572x-idk,        | openvx test hangs  |                    |
|                    | am572x-evm         | on AM572x-GP and   |                    |
|                    |                    | AM572x-IDK         |                    |
|                    |                    | platform           |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1713         | omapl138-lcdk      | OMAP-L138          |                    |
|                    |                    | bin/setup-uboot-en |                    |
|                    |                    | v.sh               |                    |
|                    |                    | set env bootcmd    |                    |
|                    |                    | wrongly            |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1719         | k2e-evm            | K2E ethernet port  |                    |
|                    |                    | (eth2) link down   |                    |
|                    |                    | if SGMII           |                    |
|                    |                    | configured as      |                    |
|                    |                    | MAC\_MAC\_FORCED   |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1720         | am437x-evm         | Simple people      |                    |
|                    |                    | tracking demo:     |                    |
|                    |                    | Tracking Incorrect |                    |
|                    |                    | Number of People   |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1266         | am572x-idk         | PRP: stale IGMP    |                    |
|                    |                    | packets (IPv6)     |                    |
|                    |                    | seems directly     |                    |
|                    |                    | sent to eth2/eth3  |                    |
|                    |                    | of a HRP node      |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1283         | am572x-idk         | PRP: unexpected    | Seen only with non |
|                    |                    | MAC address seen   | offloaded case.    |
|                    |                    | in the node\_tabe  | With offload case, |
|                    |                    | dump               | this is not seen.  |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1308         | am572x-idk         | PRP: PRP node is   | No problem with    |
|                    |                    | shown as SAN at    | offload, which is  |
|                    |                    | times in the node  | default            |
|                    |                    | table dump when    |                    |
|                    |                    | not offloaded      |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1596         | am571x-idk,        | Static offset      |                    |
|                    | am572x-idk         | between input and  |                    |
|                    |                    | output 1 PPS       |                    |
|                    |                    | signals on GMAC    |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1641         | am57x              | HSR/PRP: NetJury   |                    |
|                    |                    | Test               |                    |
|                    |                    | TC\_HSR\_5\_2\_1   |                    |
|                    |                    | fails              |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1732         | am572x-idk         | Prueth: Observed   | Packet re-ordering |
|                    |                    | packet re-ordering | is expected to be  |
|                    |                    | in VLAN\_over\_HSR | taken care by      |
|                    |                    | and                | network stack for  |
|                    |                    | VLAN\_over\_PRP    | TCP and            |
|                    |                    | test on AM572x-IDK | application for    |
|                    |                    | platform           | UDP. So this is    |
|                    |                    |                    | not a serious      |
|                    |                    |                    | issue              |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1745         | am571x-idk         | PRUETH: Eth5 fails |                    |
|                    |                    | on AM571x ICSS1    |                    |
|                    |                    | with PRP firmware  |                    |
|                    |                    | used as SAN        |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1770         | am571x-idk,        | Crash happens when |                    |
|                    | am572x-idk         | ifconfig up/down   |                    |
|                    |                    | in prueth PRP-SAN  |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1771         | am571x-idk,        | Crash is observed  |                    |
|                    | am572x-idk         | when PRUETH IEP is |                    |
|                    |                    | PTP master clock   |                    |
+--------------------+--------------------+--------------------+--------------------+
| PLSDK-1773         | am571x-idk,        | HSR/PRP: snmpwalk  | Node table entries |
|                    | am572x-idk         | and debugfs        | can be seen by     |
|                    |                    | doesn’t show Node  | displaying the     |
|                    |                    | Table entries      | following debugs   |
|                    |                    |                    | file               |
|                    |                    |                    | cat                |
|                    |                    |                    | /sys/kernel/debug/ |
|                    |                    |                    | prueth-prp/new\_nt |
|                    |                    |                    | \_bins             |
+--------------------+--------------------+--------------------+--------------------+

| 

.. rubric:: Installation and Usage
   :name: installation-and-usage

The `Software Developer's
Guide </index.php/Processor_SDK_Linux_Software_Developer%E2%80%99s_Guide>`__
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
page </index.php/How_to_Build_a_Ubuntu_Linux_host_under_VMware>`__.

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

.. rubric:: Technical Support and Product Updates
   :name: technical-support-and-product-updates

For further information or to report any problems, see
`Processor\_SDK\_Technical\_Support <http://processors.wiki.ti.com/index.php/Processor_SDK_Technical_Support>`__

| 

