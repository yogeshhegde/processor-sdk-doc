.. _release-specific-release-notes:

************************************
Release Notes for AM335X
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
addition, see :ref:`PLSDK GPLv3 Disclaimer <overview-gplv3-disclaimer>`.

Documentation
===============
-  :ref:`Processor SDK Linux Software Developer's Guide <linux-index>`: Provides information on features, functions, delivery package and,
   compile tools for the Processor SDK Linux release. This also provides
   detailed information regarding software elements and software
   infrastructure to allow developers to start creating applications.
-  :ref:`Processor SDK Linux Getting Started Guide <overview-getting-started>`: Provides information on getting the software and running
   examples/demonstrations bundled in the SDK.
-  **Software Manifest**: Provides license information on software
   included in the SDK release. This document is in the release at
   ``[INSTALL-DIR]/docs``.
-  **EVM Quick Start Guide**: Provides information on hardware setup and
   running the demonstration application that is loaded on flash. This
   document is provided as part of the EVM kit.

Release 08.02.00
==================

Released May 2022

.. rubric:: What's New
   :name: whats-new

Processor SDK 8.2 Release has following new features:

 - 2021 LTS Update (Kernel 5.10, U-boot: 2021.01, gcc: 9.2 2019.12 hf, Yocto 3.1 (dunfell))

|

.. _release-specific-sdk-components-versions:

.. rubric:: SDK Components & Versions
   :name: sdk-components-versions

+--------------------------+----------------------------+
| Component                | Version                    |
+==========================+============================+
| Linux Kernel             | 5.10.100 (2021 LTS)        |
+--------------------------+----------------------------+
| U-Boot                   | 2021.01                    |
+--------------------------+----------------------------+
| Yocto Project            | 3.1 (dunfell)              |
+--------------------------+----------------------------+
| ARM Toolchain (gcc)      | 9.2 2019.12 hard-float     |
+--------------------------+----------------------------+
| Qt                       | 5.14.2                     |
+--------------------------+----------------------------+
| OpenCL                   | 1.2.00.02                  |
+--------------------------+----------------------------+
| OpenCV                   | 4.1.0                      |
+--------------------------+----------------------------+
| Wayland                  | 1.18                       |
+--------------------------+----------------------------+
| GStreamer                | 1.16.3                     |
+--------------------------+----------------------------+
| TI PRU Compiler          | 2.3.2                      |
+--------------------------+----------------------------+
| TI C66x CGT Compiler     | 8.3.2                      |
+--------------------------+----------------------------+

|

Supported Platforms
=====================================
See :ref:`here <release-specific-supported-platforms-and-versions>` for a list of supported platforms and links to more information.

|


Build Information
=====================================

.. _release-specific-build-information-u-boot:

U-Boot
-------------------------

| The U-Boot git repository, branch and commit id can be found below:
| Based on verson: 2021.01
| URL: git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2021.01
| uBoot Tag: 08.02.00.006
| Commit ID: 44a87e3ab85c6d64044f0b5ad677008316baad70

|

.. _release-specific-build-information-kernel:

Kernel
-------------------------

.. _release-specific-build-information-linux-kernel:

.. rubric:: Linux Kernel
   :name: linux-kernel

| The kernel git repository, branch and commit id can be found below:
| Based on Version: 5.10.100
| URL: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.10.y
| Tag: 08.02.00.006
| Commit ID: 7a7a3af903da2b2d551d058f8262a66e6b42b6b1

|

.. _release-specific-build-information-rt-linux-kernel:

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| The RT kernel git repository, branch and commit id can be found below:
| Based on:
| Kernel Version: 5.10.100
| RT Kernel Version: 5.10.100-rt62

| URL: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.10.y
| Tag: 08.02.00.006-rt
| Commit ID: 204ec708dc86f4334f585f04835527570be1c4eb

|


.. _release-specific-generic-kernel-release-notes:

.. rubric:: Generic Kernel Release Notes
   :name: generic-kernel-release-notes

| Generic kernel release notes from kernelnewbies.org can be found at:
  http://kernelnewbies.org/Linux_5.10
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

   SITSW-428,"am335x-evm,am335x-sk","Matrix demo is not running by default"
   SITSW-706,"am335x-evm,am335x-ice,am335x-sk","Top level makefile broken in AM335x"

|


Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
 - None

|

SDK Known Issues
-----------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 25, 30, 50, 600

   SITSW-1357,"am335x-evm,am335x-sk","Some of the Matrix QT5 demos (Touch, Thermostat, Browser) are failing",""
   SITSW-1358,"am335x-evm,am335x-sk","Matrix KMScube demo is failing",""
   SITSW-1376,"am335x-evm,am335x-sk","Matrix demo does not start until XFRM netlink socket initialization is complete","Reload localhost URL after XFRM netlink socket initialization is completed"
   LCPD-28033,"am335x-evm,am335x-ice,am335x-sk","Error while running docker hello world example",""
   LCPD-27524,"am335x-evm,am335x-sk","Yocto: SRCIPK Packaging Build Failures for Kernel/U-Boot",""
   LCPD-19858,"am335x-evm,am335x-hsevm,am335x-ice,am335x-sk","OE: OPTEE label used in SDK is old and wrong",""
   LCPD-17817,"am335x-hsevm","Images created with Proc-SECDEV grow with number of times SECDEV has been used",""
   LCPD-17449,"am335x-evm,am335x-hsevm,am335x-ice,am335x-sk","libasan_preinit.o is missing in devkit",""
   LCPD-15367,"am335x-evm","Boot time increased about 15s ",""
   LCPD-13947,"am335x-evm","nativesdk-opkg is broken in the devkit",""
   LCPD-12405,"am335x-evm,am335x-ice","Openssl certgen fails due to coredump in openssl_gen_cert.sh",""

|

.. _release-specific-u-boot-known-issues:

U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   LCPD-19133,"am335x-evm,am335x-hsevm,am335x-ice,am335x-sk","Netconsole output corrupted when CONFIG_NETCONSOLE_BUFFER_SIZE >= 281",""
   LCPD-18643,"am335x-evm,am335x-hsevm,am335x-ice,am335x-sk","U-Boot: AM335x/AM473x: Both SPI CS signals get asserted",""
   LCPD-7366,"am335x-evm","uboot McSPI driver drives multiple chip selects simultaneously","None"

|

.. _release-specific-linux-kernel-known-issues:

Linux Kernel Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Priority", "Title", "Component", "Subcomponent", "Platform", "Workaround"
   :widths: 5, 10, 70, 10, 5, 20, 35

   LCPD-26694,"P1-Urgent","AM335x PRU Ethernet slowdown from kernel 4.19 -> 5.4/5.10","am335x-ice",""
   LCPD-22355,"P5-Not Prioritized","Update PHY latency values in SDK documentation","Connectivity","","am335x-ice",""
   LCPD-19757,"P3-Medium","OpenSSL DES performance numbers are lower in 07.01","Baseport,System Test","","am335x-evm",""
   LCPD-19703,"P3-Medium","suspicious RCU usage wkup_m3_prepare_low_power on am335x-evm: 20201002","Baseport","","am335x-evm",""
   LCPD-19702,"P3-Medium","crypto algapi failure on am335x-evm: 20201002","Baseport","","am335x-evm",""
   LCPD-19660,"P4-Low","Remove unused definitions and related code for SV frame MAC address","Connectivity","","am335x-ice",""
   LCPD-19262,"P3-Medium","Uboot: usb ethernet boot does not work on am335x-evm","Connectivity","","am335x-evm",""
   LCPD-17673,"P3-Medium","No software documentation for the Timer module","Baseport","Timers","am335x-evm",""
   LCPD-16437,"P4-Low","Nand with prefetch dma: read perf drop ~20% comparing to 2018","Connectivity","","am335x-evm",""
   LCPD-15787,"P3-Medium","Power suspend fails due to USB (scsi_bus_suspend) failure when HDD is in use","Connectivity","","am335x-evm",""
   LCPD-15648,"P4-Low","Uboot mmc write performance decreased","Connectivity","","am335x-evm",""
   LCPD-14855,"P3-Medium","omap_i2c_prepare_recovery() function can Lock System","Connectivity","I2C","am335x-evm,am335x-ice,am335x-sk",""
   LCPD-13720,"P3-Medium","SPI DMA TX Mode Halts During Continuous 16/32/64 bit Transfers ","Connectivity","","beaglebone-black",""
   LCPD-12392,"P4-Low","USBhost video: higher resolution tests fail with some cameras","Connectivity","","am335x-evm",""
   LCPD-10221,"P3-Medium","Longer resume times observed on setup with usb device cable","Connectivity","USB","am335x-evm",""
   LCPD-1245,"P3-Medium","AM335x: Power: Reverse current leakage on poweroff","Power & Thermal","","am335x-evm",""
   LCPD-1191,"P4-Low","AM335x: Power: System resumes due to wakeup source USB1_PHY without any external trigger","Power & Thermal","","am335x-evm","Use GPIO interrupt instead of USB PHY for wakeup source."
   LCPD-998,"P4-Low","MUSB does not free urbs causing usb audio playback to fail","Connectivity","","AM335x",""

|

.. _release-specific-rt-linux-kernel-known-issues:

RT Linux Kernel Known Issues
-----------------------------

-  None


|


.. rubric:: Installation and Usage
   :name: installation-and-usage

The :ref:`Software Developer's Guide <linux-index>` provides instructions on how to setup up your Linux development
environment, install the SDK and start your development.  It also includes User's Guides for various Example Applications and Code
Composer Studio.

|

.. rubric:: Host Support
   :name: host-support

The Processor SDK is developed, built and verified on Ubuntu 16.04 and 18.04. Details on how to create a virtual machine to load Ubuntu
are described in :ref:`this page <how-to-build-a-ubuntu-linux-host-under-vmware>`.


.. note::
   Processor SDK Installer is 64-bit, and installs only on 64-bit host
   machine. Support for 32-bit host is dropped as Linaro toolchain is
   available only for 64-bit machines

|
