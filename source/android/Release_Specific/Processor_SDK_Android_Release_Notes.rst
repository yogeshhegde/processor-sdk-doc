*******************************************
Processor SDK Android Release Notes
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
Disclaimer <Licenses.html#gplv3-disclaimer>`__

|

.. rubric:: Documentation
   :name: documentation

-  `Software Developer
   Guide <index.html>`__:
   Provides information on features, functions, delivery package and,
   compile tools for the Processor SDK Android release. This also
   provides detailed information regarding software elements and
   software infrastructure to allow developers to start creating
   applications.
-  `Getting Started
   Guide <Overview.html#processor-sdk-android-getting-started-guide>`__:
   provides information on getting the software and running
   examples/demonstrations bundled in the SDK.
-  **Software Manifest**: Provides license information on software
   included in the SDK release. This document is in the release at
   ``[INSTALL-DIR]/docs``.
-  **EVM Quick Start Guide**: Provides information on hardware setup and
   running the demonstration application that is loaded on flash. This
   document is provided as part of the EVM kit.

| 

Release 04.03.00
=====================

| Released March 2018

.. rubric:: What's New
   :name: whats-new

This is an "O-Pastry" based release of Processor SDK Android
for AM57x.

|

.. rubric:: Release Features
   :name: release-features

Following new features are enabled/tested in this release:

-  **Boot:** fastboot, QSPI/NOR + emmc boot, Single stage bootloader,
   USB peripheral boot, HS Boot with FIT model, IPU Loading, Switch to
   recovery mode
-  **Platform:** LPAE support, SELinux enforce mode
-  **IPC:** MessageQ, MmRpc, Late attach support, error recovery : DEH
   And MMU faults
-  **Connectivity:** USB2.0/USB3.0 Host, Gadget and dual-role, Dual
   Ethernet, SD card detect, eMMC HS200 mode
-  **Power:** AVS0, MPU DVFS, ABB
-  **Thermal:** Governors implemented for MPU (On Die), Monitoring
   implemented for all on chip sensors
-  **Video:** 1080p60 MP4/H264/MP2, H264 Video Encode (F2F)
-  **Audio:** MP3/AAC playback, ARM<->DSP Audio Routing
-  **Display:** SGX accelerated UI and touch, DRM/KMS, DSS WB, SGX and
   DSS simultaneous composition.
-  **Camera:** VIP: YUYV/RGB888 format capture, NV12 capture, Interlaced
   capture, VPE: color conversion, V4L2 M2M, scalar, DEI

| 

.. rubric:: SDK Components and Versions
   :name: sdk-components-and-versions

+----------------+------------------------------------------------+
| Component      | Version                                        |
+================+================================================+
| Linux Kernel   | 4.4.117                                        |
+----------------+------------------------------------------------+
| U-boot         | 2016.05                                        |
+----------------+------------------------------------------------+
| Android        | Android O-Pastry 8.1                           |
+----------------+------------------------------------------------+
| Toolchain      | Andriod linux-x86 toolchain android-eabi-4.9   |
+----------------+------------------------------------------------+
| IPC            | 3.47.01.00                                     |
+----------------+------------------------------------------------+

| 

Supported Platforms
=========================

See
`Processor\_SDK\_Supported\_Platforms\_and\_Versions <Release_Specific.html#supported-platforms-and-versions>`__
for a list of supported platforms and links to more information.

| 

Issue Tracker
=============================

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 10, 20, 70

   PANDSDK-109,"am572x-evm, am571x-idk, am572x-idk",Get libpcre2.so "No such file or directory" error when running setup.sh
   PSDKAA-1949,"am572x-evm, am571x-idk, am572x-idk",Touchscreen errors when terminal disconnected. Issue with touchscreen with some PSUs
   PSDKAA-1943,"am572x-evm, am571x-idk, am572x-idk",Crash seen with MPEG2 robustness test
   PSDKAA-1942,"am572x-evm, am571x-idk, am572x-idk",H264 encode fails with main and high profiles
   PSDKAA-1938,"am572x-evm, am571x-idk, am572x-idk",Wallpaper is loaded a few seconds after UI comes up
   PSDKAA-1932,"am572x-evm, am571x-idk, am572x-idk",System crashes and reboots after adb remount
   PSDKAA-1797,"am572x-evm, am571x-idk, am572x-idk",OOM and Kernel crash with 10 minutes of monkey test
   PSDKAA-1718,"am572x-evm, am571x-idk, am572x-idk",Fence timeout issue - HWC timeout is not cleaned up correctly causing graphics failure

| 

Known Issues
----------------

.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 10, 20, 70, 50

   PANDSDK-112,am572x-evm,u-boot version being used is showing MMC fail messages,Does not affect functionality
   PANDSDK-126,am572x-evm,AM572x-EVM: No audio over HDMI when HDMI monitor connected,
   PANDSDK-127,"am571x-idk, am572x-idk",AM57xx-IDK: Screen is hard to use at default resolution,change resolution with "su; wm density 240"
   PANDSDK-128,am572x-idk,AM572x-IDK: LCD & HDMI screens intermittently lockup while playing videos,
   PANDSDK-129,"am571x-idk, am572x-idk",AM57xx-IDK: Video played on LCD has long pauses when Android is booted without HDMI connected,
   PANDSDK-131,"am572x-evm, am571x-idk, am572x-idk",Web pages take a very long time to load >30 seconds,
   PANDSDK-132,"am572x-evm, am571x-idk, am572x-idk",Audio breaks up some when MP3 clip is played and Internet is browsed,
   PANDSDK-142,"am572x-evm, am571x-idk, am572x-idk","When running setup.sh script seeing error pop up: ""Unable to find the requested file. Please check the spelling and try again""",
   PANDSDK-145,"am572x-evm, am571x-idk, am572x-idk",Camera application not able to connect to camera,
   PSDKAA-1950,"am572x-evm, am571x-idk, am572x-idk","Random sgx crash on J6 with HDMI connected, one time issue.",
   PSDKAA-1948,"am572x-evm, am571x-idk, am572x-idk","After leaving SGX idle, UI was observed to freeze with SGX crash. One time issue",
   PSDKAA-1937,"am572x-evm, am571x-idk, am572x-idk",Crashes seen while running gfxbench,


| 

.. rubric:: Installation and Usage
   :name: installation-and-usage

The `Software Developer's
Guide <index.html>`__
provides instructions on how to setup up your Android development
environment, install the SDK and start your development.

|

.. rubric:: Host Support
   :name: host-support

The Processor SDK is developed, built and verified on Ubuntu 14.04.

.. note::
   Processor SDK Installer is 64-bit, and installs only on 64-bit host
   machine. Support for 32-bit host is dropped as Linaro toolchain is
   available only for 64-bit machines

