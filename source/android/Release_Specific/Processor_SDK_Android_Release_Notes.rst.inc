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

Release 05.02.00
=====================

Released December 2018

.. rubric:: What's New
   :name: whats-new


- This is an "O-Pastry" based release of Processor SDK Android for AM57x
- PRU-Ethernet support
- Android Treble support
- Full CTS/VTS execution

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

+----------------+------------------------------------------------+
| Component      | Version                                        |
+================+================================================+
| Linux Kernel   | 4.14.80                                        |
+----------------+------------------------------------------------+
| U-boot         | 2018.01                                        |
+----------------+------------------------------------------------+
| Android        | Android O-Pastry 8.1                           |
+----------------+------------------------------------------------+
| Toolchain      | Linaro GCC 7.2-2017.11                         |
+----------------+------------------------------------------------+

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

   LCPD-13602,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm",Android: Treble: Selinux warnings and enforcing mode errors
   LCPD-12491,am57xx-evm,Android: Selinux warnings during bootup

| 

Issues found and closed on this release that may be applicable to prior releases
-------------------------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 10, 20, 70

   LCPD-14172,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm",Android: am57xevm: ADB Broken
   LCPD-14267,"am57xx-evm",Android: Android System Internal error reported at boot_complete
   LCPD-14222,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm",Android: 4.14.77 PVR Mismatch: Boot failure
   LCPD-13894,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm",Android: 4.14.71 PVR Mismatch: Boot failure
   LCPD-14095,,[Android] allmodconfig warning on linux 4.14
|

Known Issues
----------------

.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 10, 20, 70, 50

   LCPD-14325,,U-boot fails to read tispl.bin during android boot on some boards,
   LCPD-12513,am57xx-evm,Android O: Board takes longer to boot compared to MM,
   LCPD-12928,am57xx-evm,Periodic frame freezes observed while decoding H264 video,
   LCPD-13956,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm",Graphics stack crash after HDMI hot un-plug,
   LCPD-12511,am57xx-evm,Audio record is not working,
   LCPD-14423,am57xx-evm,Some Am57xx EVMs board are not able to fully boot from emmc,
   LCPD-13797,am57xx-evm,Android:CTS Failures,
   LCPD-13796,"am57xx-evm",Android: monkey test causes system crash after 10 mins of execution,
   LCPD-13795,"am571x-idk, am572x-idk, am57xx-evm","Android: Graphics service failure with ""stop"" and ""start"" command",
   LCPD-13723,,[android] allmodconfig fails to build on kernel build redirect,
   LCPD-13409,"am571x-idk, am572x-idk, am574x-idk",Android: IDK: Bootloader images fail to boot from eMMC,

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

The Processor SDK is developed, built and verified on Ubuntu 14.04, 16.04, and 18.04.

.. note::
   Processor SDK Installer is 64-bit, and installs only on 64-bit host
   machine. Support for 32-bit host is dropped as Linaro toolchain is
   available only for 64-bit machines

