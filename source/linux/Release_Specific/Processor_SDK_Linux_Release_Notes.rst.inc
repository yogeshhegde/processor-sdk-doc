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

Release AM65x EA v05.00.00.09
===============================

Released June 30 2018

.. rubric:: Features Supported
   :name: features-supported

The following features are supported in this release:

- Boot: please refer to `U-boot flow <http://git.ti.com/gitweb/?p=ti-u-boot/ti-u-boot.git;a=blob_plain;f=board/ti/am65x/README;hb=refs/heads/ti-u-boot-2018.01>`__
- Baseport: Dual and Quad Core SMP support
- Connectivity: OSPI, MMC, CPSW, CIFS, USB host and client driver, UART, I2C, USB device, PRU Ethernet, SD card
- Audio: McASP, stereo, playback and record
- Display: DSS, touchscreen, DRM, LCD backlight
- IPC: Hardware spinlocks and mailbox


.. rubric:: Features Not Supported
   :name: features-not-supported

Below are the main features which are not supported in this release:

-  PCIe
-  USB 3.0 (SS)
-  Graphics


.. rubric:: Build U-Boot for AM65x
   :name: build-u-boot-for-am65x

.. code-block:: console

    $ <Install SDK>
    $ cd <sdk_install_dir>
    $ export TISDK_PATH="$PWD"

    $ cd linux-devkit
    $ curl -L https://releases.linaro.org/components/toolchain/binaries/7.2-2017.11/arm-linux-gnueabihf/gcc-linaro-7.2.1-2017.11-x86_64_arm-linux-gnueabihf.tar.xz | tar xJf -

    $ export CROSS_COMPILE_V7="$TISDK_PATH/linux-devkit/gcc-linaro-7.2.1-2017.11-x86_64_arm-linux-gnueabihf/bin/arm-linux-gnueabihf-"
    $ export CROSS_COMPILE_V8="$TISDK_PATH/linux-devkit/sysroots/x86_64-arago-linux/usr/bin/aarch64-linux-gnu-"
    $ export ATF_FILE="$TISDK_PATH/board-support/prebuilt-images/bl31.bin"
    $ export TEE_FILE="$TISDK_PATH/board-support/prebuilt-images/bl32.bin"
    $ export SYSFW_FILE="$TISDK_PATH/board-support/prebuilt-images/sysfw.bin"

    $ cd $TISDK_PATH/board-support/u-boot*
    $ # Build U-Boot for R5
    $ make ARCH=arm CROSS_COMPILE="$CROSS_COMPILE_V7" am65x_evm_r5_defconfig O=./build_r5
    $ make ARCH=arm CROSS_COMPILE="$CROSS_COMPILE_V7" SYSFW="$SYSFW_FILE" CONFIG_MKIMAGE_DTC_PATH=./scripts/dtc/dtc O=./build_r5

    $ # Build A53
    $ make ARCH=arm CROSS_COMPILE="$CROSS_COMPILE_V8" am65x_evm_a53_defconfig O=./build_a53
    $ make ARCH=arm CROSS_COMPILE="$CROSS_COMPILE_V8" ATF="$ATF_FILE" TEE="$TEE_FILE" CONFIG_MKIMAGE_DTC_PATH=./scripts/dtc/dtc O=./build_a53


.. rubric:: Build Kernel for AM65x
   :name: build-kernel-for-am65x

Please use top-level Makefile provided by Processor SDK Linux to build kernel and DTBs.


.. rubric:: SDK Components & Versions
   :name: sdk-components-versions

+--------------------------+----------------------------+
| Component                | Version                    |
+==========================+============================+
| Linux Kernel             | 4.14.52+ (2018 LTS)        |
+--------------------------+----------------------------+
| U-Boot                   | 2018.01                    |
+--------------------------+----------------------------+
| Yocto Project            | 2.4 (rocko)                |
+--------------------------+----------------------------+
| Linaro Toolchain (gcc)   | 7.2-2017.11 hard-float     |
+--------------------------+----------------------------+
| Qt                       | 5.9.6                      |
+--------------------------+----------------------------+
| OpenCL                   | 1.1.15                     |
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

| Head Commit: e1183b1ef6a3dc5d54603f904307bdbae51f22c3 configs:
  am65x\_evm: Add initial support for applying overlays
| Date: Wed Jun 27 21:22:27 2018 +0530
| uBoot Version: 2018.01
| uBoot Description: v2018.01-373-ge1183b1
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2018.01

|

Kernel
-------------------------

.. rubric:: Linux Kernel
   :name: linux-kernel

| The kernel git repository, branch and commit id can be found below:
| Based on Version: 4.14.40
| URL: git://git.ti.com/processor-sdk/processor-sdk-linux.git
| Branch: processor-sdk-linux-4.14.y
| Commit ID: 4796173fc58688055a99a1cef19a839174067220

|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| The RT kernel git repository, branch and commit id can be found below:
| Based on:
| Kernel Version: 4.14.40
| RT Kernel Version: 4.9.40-rt29

| URL: git://git.ti.com/processor-sdk/processor-sdk-linux.git
| Branch: processor-sdk-linux-4.14.y
| Commit ID: d5443cbd3b5a79c7b4f817896e12014f2b30e34b

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

The `Software Developer's
Guide <index.html>`__
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
page <How_to_Guides_Host.html#how-to-build-a-ubuntu-linux-host-under-vmware>`__.


.. note::
   Processor SDK Installer is 64-bit, and installs only on 64-bit host
   machine. Support for 32-bit host is dropped as Linaro toolchain is
   available only for 64-bit machines

| 

