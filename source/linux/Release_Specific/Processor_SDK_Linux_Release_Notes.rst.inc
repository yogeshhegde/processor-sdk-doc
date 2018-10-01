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
-  Code Composer Studio

Licensing
=========

Please refer to the software manifest, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page. The manifest can be found on the SDK
download page or in the installed directory as indicated below. In
addition, see `PLSDK GPLv3 Disclaimer <Overview_GPLv3_Disclaimer.html>`__

Documentation
===============
-  `Processor SDK Linux Software Developer's Guide <index.html>`__: Provides information on features, functions, delivery package and,
   compile tools for the Processor SDK Linux release. This also provides
   detailed information regarding software elements and software
   infrastructure to allow developers to start creating applications.
-  `Processor SDK Linux Getting Started Guide <Overview_Getting_Started_Guide.html>`__: Provides information on getting the software and running
   examples/demonstrations bundled in the SDK.
-  **Software Manifest**: Provides license information on software
   included in the SDK release. This document is in the release at
   ``[INSTALL-DIR]/docs``.
-  **EVM Quick Start Guide**: Provides information on hardware setup and
   running the demonstration application that is loaded on flash. This
   document is provided as part of the EVM kit.

Release 05.01.00
==================

Released Sep 2018

.. rubric:: What's New
   :name: whats-new

- Processor SDK Linux now supports AM65x family of devices, in addition to AM335x, AM437x, AM57x, K2H, K2E, K2L, K2G.
- New platforms: AM65x Evaluation Module (`TMDX654GPEVM <http://www.ti.com/tool/TMDX654GPEVM>`__), AM65x Industrial Development Kit (`TMDX654IDKEVM <http://www.ti.com/tool/TMDX654IDKEVM>`__)
- AM65x
   - Features supported
        - Boot: please refer to `U-boot flow <http://git.ti.com/gitweb/?p=ti-u-boot/ti-u-boot.git;a=blob_plain;f=board/ti/am65x/README;hb=refs/heads/ti-u-boot-2018.01>`__
        - Baseport: Dual and Quad Core SMP support
        - Connectivity: OSPI, MMC, CPSW, CIFS, USB host and client driver, UART, I2C, USB device, PRU Ethernet, SD card
        - Audio: McASP, stereo, playback and record
        - Graphics: 3D SGX Acceleration with Qt, Wayland/Weston, Matrix GUI
        - Display: DSS, touchscreen, DRM, LCD backlight
        - IPC: Hardware spinlocks and mailbox
        - DDR @ 1333 MHz, and CPU @ 800 MHz configuration
   - Features not (yet) supported
        - PCIe, USB 3.0
- Deep Learning
   - TIDL performance optimizations: Concurrent processing on all 4 cores: 2xDSP + 2xEVE
   - Port ARM NN inference engine to AM335x, AM437x, AM57xx. For more information on ARMNN, see `here <https://developer.arm.com/products/processors/machine-learning/arm-nn>`__
- HSR/PRP
   - Dual Instance support on the two PRU-ICSS on AM571x
   - Support VLAN tag in supervision frames
   - Extend HSR/PRP support to AM335x, AM437x, K2G from AM57xx (Note: PTP SAN is supported only on AM57xx in this release)
- New TI Designs (available as part of Processor SDK Linux)
   - `Flexible Interface (PRU-ICSS) Reference Design for Simultaneous, Coherent DAQ Using Multiple ADCs into Processor SDK <http://www.ti.com/tool/TIDA-01555>`__
   - Robotics sense and avoid demonstration using TI mmWave sensors
- OpenCV Performance optimizatons: StereoBM with C66x offload
- `GTK+ 3.0 Support on AM335x, AM437x, AM57x <Foundational_Components_Graphics.html#gtk-graphics-framework>`__

.. rubric:: SDK Components & Versions
   :name: sdk-components-versions

+--------------------------+----------------------------+
| Component                | Version                    |
+==========================+============================+
| Linux Kernel             | 4.14.67+ (2018 LTS)        |
+--------------------------+----------------------------+
| U-Boot                   | 2018.01                    |
+--------------------------+----------------------------+
| Yocto Project            | 2.4 (rocko)                |
+--------------------------+----------------------------+
| Linaro Toolchain (gcc)   | 7.2-2017.11 hard-float     |
+--------------------------+----------------------------+
| Qt                       | 5.9.6                      |
+--------------------------+----------------------------+
| OpenCL                   | 1.1.16                     |
+--------------------------+----------------------------+
| OpenCV                   | 3.1                        |
+--------------------------+----------------------------+
| Wayland                  | 1.13                       |
+--------------------------+----------------------------+
| GStreamer                | 1.12.2                     |
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
See `here <Release_Specific_Supported_Platforms_and_Versions.html>`__ for a list of supported platforms and links to more information.

|


Build Information
=====================================

U-Boot
-------------------------

| Head Commit: 8b2f1df4b55bc0797399a21d42ac191d44f99227:
  HACK: armv7R: K3: am654: Shut down R5 core after ATF startup on A53
| Date: Fri Sep 7 14:11:17 CDT 2018
| uBoot Version: 2018.01
| uBoot Description: v2018.01-441-g8b2f1df
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti2018.03

|

Kernel
-------------------------

.. rubric:: Linux Kernel
   :name: linux-kernel

| The kernel git repository, branch and commit id can be found below:
| Based on Version: 4.14.67
| URL: git://git.ti.com/processor-sdk/processor-sdk-linux.git
| Branch: processor-sdk-linux-4.14.y
| Commit ID: 74866f59d3507397ce9e296998fa2fc74f633dd7

|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| The RT kernel git repository, branch and commit id can be found below:
| Based on:
| Kernel Version: 4.14.67
| RT Kernel Version: 4.9.40-rt40

| URL: git://git.ti.com/processor-sdk/processor-sdk-linux.git
| Branch: processor-sdk-linux-4.14.y
| Commit ID: 3011944cfe166a6fc1bc96f578183d0c1c8ad664

|

.. rubric:: Generic Kernel Release Notes
   :name: generic-kernel-release-notes

| Generic kernel release notes from kernelnewbies.org can be found at:
  http://kernelnewbies.org/Linux_4.14
| Archived versions can be found at:
  http://kernelnewbies.org/LinuxVersions

|


.. rubric:: Installation and Usage
   :name: installation-and-usage

The `Software Developer's Guide <index.html>`__ provides instructions on how to setup up your Linux development
environment, install the SDK and start your development.  It also includes User's Guides for various Example Applications and Code
Composer Studio.

| 

.. rubric:: Host Support
   :name: host-support

The Processor SDK is developed, built and verified on Ubuntu 14.04, 16.04 and 18.04. Details on how to create a virtual machine to load Ubuntu 14.04
are described in `this page <How_to_Guides_Host.html#how-to-build-a-ubuntu-linux-host-under-vmware>`__.


.. note::
   Processor SDK Installer is 64-bit, and installs only on 64-bit host
   machine. Support for 32-bit host is dropped as Linaro toolchain is
   available only for 64-bit machines

| 

