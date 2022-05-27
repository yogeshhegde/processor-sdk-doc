.. _Release-note-label:

************************************
Release Notes
************************************

Overview
========

The **Processor Software Development Kit (Processor SDK)** is a unified software platform for TI embedded processors
providing easy setup and fast out-of-the-box access to benchmarks and demos.  All releases of Processor SDK are
consistent across TI’s broad portfolio, allowing developers to seamlessly reuse and develop software across devices.
Developing a scalable platform solutions has never been easier than with the Processor SDK and TI’s embedded processor
solutions.

To simplify the end user experience, Processor SDK Linux AM62x installer provides everything needed as discussed below
to create the embedded system from “scratch” :

-  Platform/board-support software and configuration files for Linux
-  U-Boot and Kernel sources and configuration files
-  An ARM cross-compiling toolchain as well as other host binaries and components
-  A Yocto/OE compliant filesystem and sources for example applications
-  A variety of scripts and Makefiles to automate certain tasks
-  Other components needed to build an embedded system that don’t fit neatly into one of the above buckets
-  Reference Examples, benchmarks


Licensing
=========

Please refer to the software manifests, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page or in the installed directory as indicated below.

-  Linux Manifest:  "/docs/software_manifest.html"


Release 08.03.00
================

Released on April 2022

What's new
----------
Processor SDK Linux AM62x Release has following new features:

- AM62X: Initial Platform Support
- U-Boot: OSPI NOR, SD/eMMC (HS200), UART, Ethernet (CPSW) support,
  USB host (mass storage) and USB device (DFU)
- ATF: Upgrade to v2.6
- Kernel: SD/eMMC, SDIO, GPIO, OSPI NOR, USB host and device mode, RTC, ePWM,
  CPSW 3G, IPC M4, IPC PRUSS, Mailbox, HWspinlock, SA3UL,
  Display( DPI, HDMI), Graphics DDK 1.15, McASP audio out

Build Information
=====================================

U-Boot
-------------------------

.. rubric:: u-boot
   :name: u-boot

| Head Commit: 74fc69c8897f67628ee9517744c720a3dc201f53 fastboot: add missing include
| Date: Wed May 25 17:00:29 CDT 2022
| uBoot Version: 2021.01
| uBoot Description: 08.03.00.005
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2021.01
| uBoot Tag: 08.03.00.005

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

Kernel
-------------------------

.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 9e58028f945f077b3e0d7423c6af8938ec46a80a Merged TI feature platform_base into ti-linux-5.10.y
| Date: Wed May 25 17:24:07 CDT 2022
| Kernel Version: 5.10.109
| Kernel Description: 08.03.00.005

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.10.y
| Tag: 08.03.00.005
| Kernel defconfig: ti_sdk_arm64_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: d9ee8a25c2eea0d2aff22f36ced2513538fbd1a2 Merged TI feature ti_linux_base_rt into ti-rt-linux-5.10.y
| Date: Wed May 25 18:51:56 CDT 2022
| Kernel Version: 5.10.109
| RT Kernel Version: 5.10.109-rt65
| Kernel Description: 08.03.00.005-rt

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.10.y
| Tag: 08.03.00.005-rt
| Kernel defconfig: ti_sdk_arm64_rt_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

Yocto
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: e99d9aa3fc41fa3a91d68ad9e654d40bfb6e0967 ti-linux-fw: Bump to 08.03.00.005 release
| Date: 2022-05-20
| Version: dunfell-3.1
| Clone: git://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: 08.03.00.005
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: aa5fd0df1e0392703f7929c407ee1caf0f40b5aa ti-tisdk-setup: Bump to 08.03.00.005 release
| Date: 2022-05-20
| Version: 2021.09

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: dunfell
| Release Tag: 08.03.00.005
|

Issues Tracker
=====================================

Issues opened in previous releases that were closed in this release
--------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 100

   "LCPD-25536","DM should be relocated on AM62 to be inline with TF-A and OPTEE locations","am62xx-evm,am62xx-sk"
   "LCPD-25492","Occasionally Matrix-Gui does not auto launch","j721e-idk-gw,j721s2-evm,am62xx-sk"
   "LCPD-25293","CSI-2 driver not probing IMX219 image sensor","am62xx-sk"

Issues found and closed in this release that may also be applicable to prior releases
-------------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-28101","EMMC boot fails","am62xx-sk"
   "LCPD-28036","AM62x: U-Boot: xSPI boot is broken","am62xx-sk"
   "LCPD-27815","uboot cannot warm reset the am62","am62xx-sk"
   "LCPD-25569","Timer issues","am62xx-sk"
   "LCPD-25567","AM62x; WKUP UART pinmux not setup","am62xx-sk"

U-Boot Known Issues
-------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-28100","am62xx-sk","OSPI boot fails",""
   "LCPD-27828","am62xx-sk","AM62: Fix the USB MSC environment setting",""

Linux Kernel Known Issues
-------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35

   "LCPD-28131","am62xx-sk","am62x: wlan interface up - down - up results in kernel crash",""
   "LCPD-28111","am62xx-sk","wic image flashed sdcard should resize to full image",""
   "LCPD-28149","am62xx-sk","CMA warning while running GPU tests",""
   "LCPD-28110","am62xx-sk","uboot and linux cannot boot in UHS speed modes on certain U1 class SD-cards",""
   "LCPD-28105","am62xx-sk","Automated test failure - CPSW failure doing runtime pm",""
   "LCPD-28104","am62xx-sk","Automated test failure - CPSW test is passing invalid parameters to switch-config",""
   "LCPD-28103","am62xx-sk","Automated test failure - CPSW test fails to find an active interface implemented by CPSW",""
   "LCPD-26721","am62xx-sk","AM62x: Cannot resume with more than one A53 enabled ",""
   "LCPD-25580","am62xx-sk","AM62: Move BSS below DM config data",""
   "LCPD-25563","am62xx-sk","Test: AM62: Linux: Add support for MCAN",""
   "LCPD-24456","am62xx-sk","Move IPC validation source from github to git.ti.com",""

Linux RT Kernel Known Issues
----------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35

There are no known issues in this release in the Linux RT Kernel.
