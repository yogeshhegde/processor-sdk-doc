.. _release-specific-release-notes:

************************************
Release Notes for AM437X
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
| Based on:
| Kernel Version: 5.10.100
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
   :widths: 15, 30, 100

   SITSW-428,"am437x-sk,am43xx-gpevm","Matrix demo is not running by default"
   SITSW-706,"am437x-idk,am437x-sk","Top level makefile broken in AM437x"
   LCPD-18270,"am43xx-gpevm","Ivi shell test fails. Lib ivi-controller.so and other components are missing from the file system",""

|


Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
 - None

|

Errata Workarounds Available in this Release
------------------------------------------------
 - None

|

SDK Known Issues
-----------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 25, 30, 50, 600

   SITSW-1357,"am437x-sk,am43xx-gpevm","Some of the Matrix QT5 demos (Touch, Thermostat, Browser) are failing",""
   SITSW-1358,"am43xx-gpevm","Matrix KMScube demo is failing",""
   SITSW-1376,"am437x-sk,am43xx-gpevm","Matrix demo does not start until XFRM netlink socket initialization is complete","Reload localhost URL after XFRM netlink socket initialization is completed"
   LCPD-24839,"am43xx-gpevm","USBHOST video capture failed at 320x240",""
   LCPD-20673,"am43xx-gpevm","packaging: ipsec: command not found",""
   LCPD-19858,"am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk","OE: OPTEE label used in SDK is old and wrong",""
   LCPD-19279,"am43xx-gpevm","openssl_perf.sh functionality to be included in rootfs (decouple from matrixgui)",""
   LCPD-17659,"am437x-idk","Disable GPU on AM437x IDK",""
   LCPD-17449,"am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk","libasan_preinit.o is missing in devkit",""
   LCPD-17413,"am43xx-gpevm","QT Webengine-based browser: the mouse does not work within the web page with QPA EGLFS",""
   LCPD-15918,"am43xx-gpevm","ti-ipc-rtos gets stuck in xdctools",""
   LCPD-12405,"am43xx-epos,am43xx-gpevm","Openssl certgen fails due to coredump in openssl_gen_cert.sh",""
   LCPD-9923,"am43xx-gpevm","Error message in boot log for K2 and AM platforms",""
   LCPD-8352,"am43xx-gpevm","weston: stress testing with 75 concurrent instances of simple-egl leads to unresponsive HMI due to running out of memory","1. Restart Wayland application. 2. Restart board if Weston is killed by oom-killer"
   LCPD-7255,"am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk","Telnet login takes too long (~40 seconds)","Booting with rootfs mounted over NFS might cause ~40 seconds delay on telnet login because DNS entries might not be properly populated. To work around this issue, enter appropriate DNS server IP in resolv.conf. For example:   echo 'nameserver 192.0.2.2' > /etc/resolv.conf;"
   LCPD-7025,"am43xx-gpevm","System takes more than 10 seconds to go from login prompt to system prompt","Automated tests need to account for this boot delay"

|

.. _release-specific-u-boot-known-issues:

U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-25271","am43xx-gpevm","UBoot NAND ECC 8/16 bit read test Fails",""
   "LCPD-18643","am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk","U-Boot: AM473x: Both SPI CS signals get asserted",""
   "LCPD-7864","am43xx-gpevm,am437x-idk,am437x-sk","U-Boot: Ethernet boot fails on AM437x",""


|

.. _release-specific-linux-kernel-known-issues:

Linux Kernel Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Priority", "Title", "Component", "Subcomponent", "Platform", "Workaround", "Impact"
   :widths: 5, 10, 70, 10, 5, 20, 35, 20

   LCPD-26694,"P1-Urgent","AM437x PRU Ethernet slowdown from kernel 4.19 -> 5.4/5.10","am437x-idk",""
   LCPD-24650,"P2-High","VPFE sensor capture fails","am43xx-gpevm",""
   LCPD-22355,"P5-Not Prioritized","Update PHY latency values in SDK documentation","Connectivity","","am437x-idk",""
   LCPD-22748,"P5-Not Prioritized","Kernel Panic after shutdown of kernel","Baseport","","am437x-idk","",""
   LCPD-22541,"P5-Not Prioritized","Kernel crash while running docker example","Connectivity","","am437x-idk","",""
   LCPD-21524,"P5-Not Prioritized","Resume taking longer time","Baseport","","am43xx-gpevm","",""
   LCPD-24505,"P3-Medium","KMS properties test failed","Audio & Display","","am43xx-gpevm","",""
   LCPD-20653,"P5-Not Prioritized","ltp: kernel syscall tests fail","Baseport","","am43xx-gpevm","",""
   LCPD-19660,"P4-Low","Remove unused definitions and related code for SV frame MAC address","Connectivity","","am437x-idk","",""
   LCPD-17673,"P3-Medium","No software documentation for the Timer module","Baseport","Timers","am43xx-gpevm","",""
   LCPD-12226,"P3-Medium","mmcsd first write perf decreased on some platforms","Connectivity","","am43xx-gpevm","",""
   LCPD-10974,"P3-Medium","am43xx-gpevm - usb camera gadget shows halting frames","Connectivity","USB","am43xx-gpevm","None",""
   LCPD-7955,"P3-Medium","Uncorrectable Bitflip errors seen after switch to SystemD","Connectivity","GPMC","am43xx-gpevm","Workaround to erase the NAND flash completely if flashed with an incompatible flash writer. SystemD tries to mount all partitions and that is the reason this is being seen now.",""
   LCPD-1207,"P4-Low","AM43XX: CONNECTIVITY: dwc3_omap on am43xx and xhci_plat_hcd on dra7 - removal results in segmentation fault","Connectivity","USB","am43xx-gpevm","",""


|

.. _release-specific-rt-linux-kernel-known-issues:

RT Linux Kernel Known Issues
-----------------------------
   - None

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
