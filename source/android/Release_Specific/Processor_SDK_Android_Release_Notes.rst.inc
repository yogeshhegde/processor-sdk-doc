*******************************************
Release Notes
*******************************************

Overview
=======================

The **Processor Software Development Kit (Processor-SDK) for Android**
provides a fundamental software platform for development, deployment and
execution of Android based applications and includes the following:

-  Bootloaders & Filesystems
-  SDK Installer
-  Setup Scripts
-  Makefiles
-  eMMC Images
-  Android UI
-  Example Applications

| 

Licensing
=============================

Please refer to the software manifest, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page. The manifest can be found on the SDK
download page or in the installed directory as indicated below. In
addition, see `Processor SDK Android GPLv3
Disclaimer <Overview_GPLv3_Disclaimer.html>`__

|

Documentation
==================

-  `Software Developer
   Guide <index.html>`__:
   Provides information on features, functions, delivery package and,
   compile tools for the Processor SDK Android release. This also
   provides detailed information regarding software elements and
   software infrastructure to allow developers to start creating
   applications.
-  `Getting Started
   Guide <Overview_Getting_Started_Guide.html>`__:
   provides information on getting the software and running
   examples/demonstrations bundled in the SDK.
-  **Software Manifest**: Provides license information on software
   included in the SDK release. This document is in the release at
   ``[INSTALL-DIR]/docs``.
-  **EVM Quick Start Guide**: Provides information on hardware setup and
   running the demonstration application that is loaded on flash. This
   document is provided as part of the EVM kit.

| 

Release 06.00.00
=====================

Released July 2019

.. rubric:: What's New
   :name: whats-new


- This is a "P-Pastry" based release of Processor SDK Android

|

.. rubric:: Release Features
   :name: release-features

Following features are enabled/tested in this release for AM57x:

-  **Boot:** fastboot, emmc boot, GP with FIT model
-  **Platform:** LPAE support, SELinux Permissive mode
-  **Connectivity:** USB2.0/USB3.0 Host, Gadget,
   Ethernet, PRU Ethernet, SD card detect, eMMC
-  **Power:** AVS0, MPU DVFS, ABB
-  **Thermal:** Governors implemented for MPU (On Die), Monitoring
   implemented for all on chip sensors
-  **Video:** 720p30 MP4/H264/MP2
-  **Audio:** MP3/AAC playback
-  **Display:** SGX accelerated UI and touch, DRM/KMS
-  **Android Treble Support**

| 

.. rubric:: SDK Components and Versions
   :name: sdk-components-and-versions

+--------------------+------------------------------------------------+
| Component          | Version                                        |
+====================+================================================+
| Linux Kernel       | 4.19.44                                        |
+--------------------+------------------------------------------------+
| U-boot             | 2019.01                                        |
+--------------------+------------------------------------------------+
| Android            | Android Pie (9.0)                              |
+--------------------+------------------------------------------------+
| OPTEE              | 3.5.0                                          |
+--------------------+------------------------------------------------+
| ATF                | 2.1                                            |
+--------------------+------------------------------------------------+
| Android Toolchain  | clang-4691093 v6.0.2 (LLVM 6.0.2svn)           |
+--------------------+------------------------------------------------+
| Kernel Toolchain   | ang 8.0.8 (based on r349610)                   |
+--------------------+------------------------------------------------+
| GCC Toolchain      | 8.3-2019.03                                    |
+--------------------+------------------------------------------------+


| 

Supported Platforms
=========================

See
`Processor\_SDK\_Supported\_Platforms\_and\_Versions <Release_Specific_Supported_Platforms_and_Versions.html>`__
for a list of supported platforms and links to more information.

| 

Issue Tracker
=============================

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 10, 20, 70

   LCPD-15227,"am57xx-evm, am654x-evm",Android: Android System Internal error reported at boot_complete

| 

Issues found and closed on this release that may be applicable to prior releases
-------------------------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 10, 20, 70

   LCPD-15563,am57xx-evm,omapdrm: display ordering based on alias is broken
   LCPD-15593,"am571x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15, am654x-evm, am654x-idk",Android: Compliance tests fail to execute on all supported platforms
   LCPD-15560,"am571x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15",Android: GPEVM fails to boot with LCD configuration
   LCPD-15542,am654x-evm,Android: Core services continually restarted
   LCPD-15521,"am571x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15, am654x-evm, am654x-idk",Android: modetest missing from file system
   LCPD-15595,"am571x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15, am654x-evm, am654x-idk",Android: failure in loading firmware from vendor/firmware/
   LCPD-15468,"am571x-idk, am574x-idk",Android: IDK boards fails to boot
   LCPD-15395,am654x-evm,Android: AM6: Binder Errors due to continual audio services crashing

|

Known Issues
----------------

.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 10, 20, 70, 50

   LCPD-15886,am654x-evm,Exception observed when starting gallery,
   LCPD-15858,am654x-evm,Android: AM6: Screen cap shows graphics cache Issue,
   LCPD-15830,"am57xx-evm, am654x-evm",Android: CTS Execution Failure on Pie builds,
   LCPD-15829,"am57xx-evm, am654x-evm",Android: VTS Execution Failure on Pie builds,
   LCPD-15514,am57xx-evm,Android boot time is noticeable higher than previous releases,
   LCPD-13409,"am571x-idk, am574x-idk",Android: IDK: Bootloader images fail to boot from eMMC,
   LCPD-13797,am57xx-evm,Android:CTS Failures,
   LCPD-14443,am654x-evm,CTS failures detected,
   LCPD-14442,am654x-evm,Ethernert port does not obtain ip address,
   LCPD-15643,"am57xx-evm, am654x-evm",Android: Monkey test fails to run,
   LCPD-15642,am57xx-evm,Android: kernel errors observed while trying to run cts,
   LCPD-15644,"am57xx-evm, am57xx-beagle-x15",Android: Unable to set the HDMI mode via ro.hwc.hdmiedid,
   LCPD-16140,am571x-idk,Video is jerky when LCD and HDMI are connected,
   LCPD-12928,am57xx-evm,Periodic frame freezes observed while decoding H264 video,
   LCPD-15742,am654x-evm,Android: AM6: PVR: Build warnings in kernel driver build,
   PANDSDK-207,am574x-idk,Application icons not showing correctly is second boot,"AM57x:  http://git.ti.com/android/device-ti-beagle-x15/commit/aa11b36aaa11c300cbeccfa653f8efca17fe9714, http://git.ti.com/android/hardware-ti-am57x/commit/ef3412ac548a0afa97c68d00f1d494b137289a0e AM65x:  http://git.ti.com/android/vendor-ti-am65x/commit/690354778b8b70c68e5f22fbd1452402d6184285 , http://git.ti.com/android/hardware-ti-am65x/commit/8054f800d4d00897859e65f8911dd7f66bba1464"
   PANDSDK-208,"am571x-idk, am572x-idk",sudo ./adb root command crashes OS and reboots board, 

| 

Installation and Usage
========================

The `Software Developer's
Guide <index.html>`__
provides instructions on how to setup up your Android development
environment, install the SDK and start your development.

|

Host Support
==============

The Processor SDK is developed, built and verified on Ubuntu 16.04, and 18.04.

.. note::
   Processor SDK Installer is 64-bit, and installs only on 64-bit host
   machine. Support for 32-bit host is dropped as Linaro toolchain is
   available only for 64-bit machines

