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

Release 05.01.00
=====================

Released October 2018

.. rubric:: What's New
   :name: whats-new

This is an "O-Pastry" based release of Processor SDK Android
for AM57x.

|

.. rubric:: Release Features
   :name: release-features

Following new features are enabled/tested in this release:

-  **Boot:** fastboot, emmc boot, GP with FIT model
-  **Platform:** LPAE support, SELinux Permissive mode
-  **Connectivity:** USB2.0/USB3.0 Host, Gadget,
   Ethernet, SD card detect, eMMC
-  **Power:** AVS0, MPU DVFS, ABB
-  **Thermal:** Governors implemented for MPU (On Die), Monitoring
   implemented for all on chip sensors
-  **Video:** 720p30 MP4/H264/MP2
-  **Audio:** MP3/AAC playback
-  **Display:** SGX accelerated UI and touch, DRM/KMS

| 

.. rubric:: SDK Components and Versions
   :name: sdk-components-and-versions

+----------------+------------------------------------------------+
| Component      | Version                                        |
+================+================================================+
| Linux Kernel   | 4.14.67                                        |
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

    LCPD-12486,am57xx-evm,Android: libdrm-modetest not found in builds
    LCPD-12487,"am574x-idk, am57xx-evm",Android: eth port issue
    LCPD-12488,am57xx-evm,Android: GFX warning seen on console
    LCPD-12512,am57xx-evm,Board is not able to boot from emmc after flashing
    LCPD-12659,am57xx-evm,Artifact observed during video decode operations
    LCPD-12679,"am574x-idk, am57xx-evm, am57xx-beagle-x15",PVR_K: dmabuf error during video playback
    LCPD-12776,am57xx-evm,Android: Graphics Error with Vellamo3 Benchmark
    LCPD-12782,"am571x-idk, am572x-idk",Android: AM571/572 IDK Board is not able to boot
    LCPD-12796,"am571x-idk, am572x-idk, am574x-idk, am57xx-beagle-x15",Board requires USB input device to boot
    LCPD-12919,am57xx-evm,PVR error observed during long term decode operations
    LCPD-12934,am57xx-evm,Android: Robustness test: monkey fails
    LCPD-12935,"am571x-idk, am572x-idk, am574x-idk",PVR Dmabuf error observed
    LCPD-12938,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm",GFXBench is not able to run no space left on device
    LCPD-13003,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm",Need LCD detection logic for the IDK boards in the fastboot.sh script
    LCPD-13005,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm",Component Test: POWERMGR_S_FUNC_CPUFREQ_BASIC Failed
    LCPD-13006,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm",Seeing gadget disconnect/reconnect over and over ~5 minutes after booting
    LCPD-13009,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15",AM57xx-IDK: Video played on LCD has long pauses when Android is booted without HDMI connected
    LCPD-13016,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm",u-boot version being used is showing MMC fail messages
    LCPD-13467,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm",Services problems reported after reboot

| 

Issues found and closed on this release that may be applicable to prior releases
-------------------------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 10, 20, 70

    LCPD-13147,"am57xx-evm, am57xx-beagle-x15",Regression to boot to UI with DB 178
    LCPD-13568,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15",Android Boot failure due to binder errors
    LCPD-13601,"am571x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15",Android: Treble: Gatekeeper service crash
    LCPD-13668,am57xx-evm,Android: AM57x with LCD: Android System Internal error reported at boot_complete

|

Known Issues
----------------

.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 10, 20, 70, 50

    LCPD-12491,am57xx-evm,Android: Selinux warnings during bootup,
    LCPD-12511,am57xx-evm,Audio record is not working,
    LCPD-12513,am57xx-evm,Android O: Board takes longer to boot compared to MM,
    LCPD-12928,am57xx-evm,Periodic frame freezes observed while decoding H264 video,
    LCPD-13409,"am571x-idk, am572x-idk, am574x-idk",Android: IDK: Bootloader images fail to boot from eMMC,
    LCPD-13602,"am571x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15",Android: Treble: Selinux warnings and enforcing mode errors,
    LCPD-13723,,[android] allmodconfig fails to build on kernel build redirect,
    LCPD-13795,"am571x-idk, am57xx-evm, am57xx-beagle-x15","Android: Graphics service failure with ""stop"" and ""start"" command",
    LCPD-13796,am57xx-evm,Android: monkey test causes system crash after 10 mins of execution,
    LCPD-13797,am57xx-evm,Android:CTS Failures,

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

