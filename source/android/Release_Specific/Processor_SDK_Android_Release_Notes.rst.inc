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

Release 05.00.00
=====================

Released July 2018

.. rubric:: What's New
   :name: whats-new

This is an "O-Pastry" based release of Processor SDK Android
for AM57x.

|

.. rubric:: Release Features
   :name: release-features

Following new features are enabled/tested in this release:

-  **Support AM574x IDK**
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
-  **Video:** 1080p30 MP4/H264/MP2
-  **Audio:** MP3/AAC playback, ARM<->DSP Audio Routing
-  **Display:** SGX accelerated UI and touch, DRM/KMS, DSS WB, SGX and
   DSS simultaneous composition.

| 

.. rubric:: SDK Components and Versions
   :name: sdk-components-and-versions

+----------------+------------------------------------------------+
| Component      | Version                                        |
+================+================================================+
| Linux Kernel   | 4.14.40                                        |
+----------------+------------------------------------------------+
| U-boot         | 2018.01                                        |
+----------------+------------------------------------------------+
| Android        | Android O-Pastry 8.1                           |
+----------------+------------------------------------------------+
| Toolchain      | Linaro GCC 7.2-2017.11                         |
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

   PANDSDK-112,am572x-evm,u-boot version being used is showing MMC fail messages
   PANDSDK-127,"am571x-idk, am572x-idk",AM57xx-IDK: Screen is hard to use at default resolution
   PANDSDK-128,am572x-idk,AM572x-IDK: LCD & HDMI screens intermittently lockup while playing videos
   PANDSDK-129,"am571x-idk, am572x-idk",AM57xx-IDK: Video played on LCD has long pauses when Android is booted without HDMI connected
   PANDSDK-132,"am572x-evm, am571x-idk, am572x-idk",Audio breaks up some when MP3 clip is played and Internet is browsed
   PANDSDK-142,"am572x-evm, am571x-idk, am572x-idk","When running setup.sh script seeing error pop up: ""Unable to find the requested file. Please check the spelling and try again"""
   PSDKAA-1950,"am572x-evm, am571x-idk, am572x-idk","Random sgx crash on J6 with HDMI connected, one time issue."
   PSDKAA-1948,"am572x-evm, am571x-idk, am572x-idk","After leaving SGX idle, UI was observed to freeze with SGX crash. One time issue"
   PSDKAA-1937,"am572x-evm, am571x-idk, am572x-idk",Crashes seen while running gfxbench


| 

Known Issues
----------------

.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 10, 20, 70, 50

    LCPD-11852,am57xx-evm,U-Boot: AM57x: doesn't detect super-speed thumb drive,
    LCPD-12491,am57xx-evm,Android: Selinux warnings during bootup,
    LCPD-12513,am57xx-evm,Android O: Board takes longer to boot compared to MM,
    LCPD-12776,am57xx-evm,Android: Graphics Error with Vellamo3 Benchmark,
    LCPD-12934,am57xx-evm,Android: Robustness test: monkey fails, "Appy patch available `here <http://git.ti.com/cgit/cgit.cgi/android/device-ti-am57xevm.git/commit/?h=d-oreo-mr1-core-release&id=3474bd4ce8d6179eb7aa8a974553a4c63ab91dff>`__"
    LCPD-12935,"am571x-idk, am572x-idk, am574x-idk",PVR Dmabuf error observed,"Apply `kernel patch <http://git.ti.com/cgit/cgit.cgi/ti-linux-kernel/ti-linux-kernel.git/commit/ti_config_fragments/android.cfg?h=ti-android-linux-4.14.y&id=539a5985e9637391ed6b5eea0725da4818bab35f>`__ and `patches for vendor-ti-dra7xx <http://git.ti.com/cgit/cgit.cgi/android/vendor-ti-dra7xx.git/log/?h=d-oreo-mr1-core-release>`__"
    LCPD-13011,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm", Web pages take a very long time to load >30 seconds,
    PANDSDK-154, "am571x-idk, am572x-idk, am574x-idk", 1080p decoding does not work for AM57xx IDKs with LCD connected, "For LCD only without HDMI connected, reduce the resolution by running *wm size 1280x720*. No workaround when both LCD and HDMI are used. This limitation comes from insufficient TILER memory when the screen resolution is larger than 720p. When LCD is connected, the screen resolution is detected and selected as 1920x1200."

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

The Processor SDK is developed, built and verified on Ubuntu 14.04.

.. note::
   Processor SDK Installer is 64-bit, and installs only on 64-bit host
   machine. Support for 32-bit host is dropped as Linaro toolchain is
   available only for 64-bit machines

