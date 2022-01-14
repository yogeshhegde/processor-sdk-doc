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

Release 07.03.00
==================

Released June 2021

.. rubric:: What's New
   :name: whats-new

Processor SDK 7.3 Release has following new features:

- 2020 LTS Update (Kernel 5.4, U-boot: 2020.01, gcc: 9.2 2019.12 hf, Yocto 3.1 (dunfell))
- ICSS-EMAC support has been descoped
- SORTE support has been descoped

.. _release-specific-sdk-components-versions:

.. rubric:: SDK Components & Versions
   :name: sdk-components-versions

+--------------------------+----------------------------+
| Component                | Version                    |
+==========================+============================+
| Linux Kernel             | 5.4.106 (2020 LTS)         |
+--------------------------+----------------------------+
| U-Boot                   | 2020.01                    |
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
| Based on verson: 2020.01
| URL: git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2020.01
| Commit ID: 2781231a33c3d779e32445f4fe55164c45d6d7c1

|

.. _release-specific-build-information-kernel:

Kernel
-------------------------

.. _release-specific-build-information-linux-kernel:

.. rubric:: Linux Kernel
   :name: linux-kernel

| The kernel git repository, branch and commit id can be found below:
| Based on Version: 5.4.106
| URL: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.4.y
| Commit ID: 023faefa70274929bff92dc41167b007f7523792

|

.. _release-specific-build-information-rt-linux-kernel:

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| The RT kernel git repository, branch and commit id can be found below:
| Based on:
| Kernel Version: 5.4.106
| RT Kernel Version: 5.4.106-rt54

| URL: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.4.y
| Commit ID: 519667b0d81d74a6e55105dcd6072ae550352599

|


.. _release-specific-generic-kernel-release-notes:

.. rubric:: Generic Kernel Release Notes
   :name: generic-kernel-release-notes

| Generic kernel release notes from kernelnewbies.org can be found at:
  http://kernelnewbies.org/Linux_5.4
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

   LCPD-19704,"am335x-evm,am43xx-gpevm", rtcwake failure on am335x-evm: 20201002
   LCPD-19274,"am43xx-gpevm", Kernel crash during resume from suspend state
   LCPD-19253,"am43xx-gpevm", am4 could not boot up using cumtom built images for eMMC
   LCPD-19083,"am335x-evm,am43xx-gpevm", Some powerdomains don't transition into suspend state

|


Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 20, 70

   LCPD-22282,"am335x-evm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am57xx-evm,am57xx-beagle-x15,am64xx-evm,am64xx-sk,am654x-evm,am654x-idk,beaglebone,bbai,beaglebone-black,dra71x-evm,dra72x-evm,dra76x-evm,dra7xx-evm,j721e-evm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,k2e-evm,k2g-evm,k2g-ice,k2hk-evm,k2l-evm,omapl138-lcdk,am62xx-evm", U-Boot: reset to default env fails in 2021 LTS

|

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
   :header: "Record ID",  "Title"
   :widths: 15, 80

   LCPD-5309, LCPD:  i896: USB Port disable doesnt work
   LCPD-5308, i897: USB Stop Endpoint doesnt work in certain circumstances


|

SDK Known Issues
-----------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 25, 30, 50, 600

   SITSW-428,"am335x-evm,am335x-sk,am437x-sk,am43xx-gpevm","Matrix demo is not running by default","Restart the Matrix demo manually after boot"
   LCPD-20673,"am43xx-gpevm","packaging: ipsec: command not found",""
   LCPD-19858,"am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am64xx-evm,am64xx-vlab,am64xx-zebu,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm,k2l-hsevm","OE: OPTEE label used in SDK is old and wrong",""
   LCPD-19279,"am335x-evm,am43xx-gpevm","openssl_perf.sh functionality to be included in rootfs (decouple from matrixgui)",""
   LCPD-18270,"am335x-evm,am43xx-gpevm,am571x-idk,am572x-idk,am574x-idk,am57xx-evm,am57xx-beagle-x15,am654x-evm,am654x-idk,dra71x-evm,dra72x-evm,dra76x-evm,dra7xx-evm,j721e-evm,j721e-evm-ivi,j721e-idk-gw","Ivi shell test fails. Lib ivi-controller.so and other components are missing from the file system",""
   LCPD-17659,"am437x-idk","Disable GPU on AM437x IDK",""
   LCPD-17449,"am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm","libasan_preinit.o is missing in devkit",""
   LCPD-17413,"am335x-evm,am43xx-gpevm,am57xx-evm,am654x-evm","QT Webengine-based browser: the mouse does not work within the web page with QPA EGLFS",""
   LCPD-15918,"am43xx-gpevm,dra7xx-evm,k2g-evm,k2l-hsevm","ti-ipc-rtos gets stuck in xdctools",""
   LCPD-12405,"am335x-evm,am335x-ice,am43xx-epos,am43xx-gpevm,am57xx-evm,dra71x-evm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2l-evm","Openssl certgen fails due to coredump in openssl_gen_cert.sh",""
   LCPD-9923,"am335x-evm,am43xx-gpevm,am57xx-evm,k2e-evm,k2g-evm,k2hk-evm,k2l-evm","Error message in boot log for K2 and AM platforms",""
   LCPD-8352,"am43xx-gpevm,am57xx-evm,dra7xx-evm","weston: stress testing with 75 concurrent instances of simple-egl leads to unresponsive HMI due to running out of memory","1. Restart Wayland application. 2. Restart board if Weston is killed by oom-killer"
   LCPD-8345,"am335x-evm,am437x-idk,dra7xx-evm,dra7xx-hsevm,k2e-evm,k2e-hsevm,k2hk-evm,k2l-evm","Board fails to start login console after waiting 3.5 minutes ( hard to reproduce, ~4/1000)","Restart the EVM"
   LCPD-7255,"am335x-evm,am335x-ice,am335x-sk,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am57xx-evm,beaglebone,beaglebone-black,beaglebone-black-ice,dra72x-evm,dra72x-hsevm,dra7xx-evm,dra7xx-hsevm,k2e-evm,k2g-evm,k2g-ice,k2hk-evm,k2l-evm","Telnet login takes too long (~40 seconds)","Booting with rootfs mounted over NFS might cause ~40 seconds delay on telnet login because DNS entries might not be properly populated. To work around this issue, enter appropriate DNS server IP in resolv.conf. For example:   echo 'nameserver 192.0.2.2' > /etc/resolv.conf;"
   LCPD-7025,"am43xx-gpevm","System takes more than 10 seconds to go from login prompt to system prompt","Automated tests need to account for this boot delay"

|

.. _release-specific-u-boot-known-issues:

U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-18643","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk","U-Boot: AM335x/AM473x: Both SPI CS signals get asserted",""
   "LCPD-7864","am335x-evm,am335x-ice,am335x-sk,am43xx-gpevm,am437x-idk,am437x-sk","U-Boot: Ethernet boot fails on AM335x and AM437x",""


|

.. _release-specific-linux-kernel-known-issues:

Linux Kernel Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Priority", "Title", "Component", "Subcomponent", "Platform", "Workaround", "Impact"
   :widths: 5, 10, 70, 10, 5, 20, 35, 20

   LCPD-9098,P4-Low,Writeback: error prints seen when doing wb capture,Audio & Display,"Capture, Display, Writeback","am571x-idk, am572x-idk, am57xx-evm, dra71x-evm, dra71x-hsevm, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm",,
   LCPD-22748,"P5-Not Prioritized","Kernel Panic after shutdown of kernel","Baseport","","am437x-idk","",""
   LCPD-22541,"P5-Not Prioritized","Kernel crash while running docker example","Connectivity","","am335x-ice,am437x-idk","",""
   LCPD-21524,"P5-Not Prioritized","Resume taking longer time","Baseport","","am43xx-gpevm","",""
   LCPD-21523,"P5-Not Prioritized","alpha blending test failure","Audio & Display","","am43xx-gpevm","",""
   LCPD-20680,"P5-Not Prioritized","VPFE capture fails","Audio & Display","","am43xx-gpevm","",""
   LCPD-20677,"P5-Not Prioritized","nbench: Numeric_Sort out of expected range: 431.72 < 529.7634209650582 - 46.19151441991239, String_Sort out of expected range: 52.731 < 60.232635274542424 - 3.325711027279963","Baseport","","am43xx-gpevm","",""
   LCPD-20676,"P5-Not Prioritized","test setup: display tests depend on weston","Audio & Display","","am43xx-gpevm","",""
   LCPD-20675,"P5-Not Prioritized","stream: measured value=591.3, historical mean=368.81875, std=0.6843183956822658","Baseport","","am43xx-gpevm","",""
   LCPD-20674,"P5-Not Prioritized"," pm_runtime is not enabled for ETH ","Connectivity","","am43xx-gpevm","",""
   LCPD-20653,"P5-Not Prioritized","ltp: kernel syscall tests fail","Baseport","","am335x-evm,am43xx-gpevm","",""
   LCPD-20301,"P3-Medium","5.11-rc3 - crypto device not found ","Baseport","","am43xx-gpevm","",""
   LCPD-19838,"P3-Medium","Cryptodev not building against 5.10 kernel","Baseport","","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am64xx-evm,am64xx-vlab,am64xx-zebu,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,dra8xx-qt,dra8xx-zebu,j7am-evm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-vlab,j7200-evm,j7200-hsevm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm,k2l-hsevm,omapl138-lcdk,j721s2-evm,j7amp-evm,j7ae-evm,j7am-vlab,j7am-zebu,j7ae-vlab,j7ae-zebu,j7aep-vlab,j7aep-zebu,j7amp-vlab,j7amp-zebu","",""
   LCPD-19702,"P3-Medium","crypto algapi failure on am335x-evm: 20201002","Baseport","","am335x-evm,am437x-sk","",""
   LCPD-19660,"P4-Low","Remove unused definitions and related code for SV frame MAC address","Connectivity","","am335x-ice,am437x-idk,am571x-idk,am572x-idk,am574x-idk","",""
   LCPD-17673,"P3-Medium","No software documentation for the Timer module","Baseport","Timers","am335x-evm,am43xx-gpevm,am571x-idk,am572x-idk,am574x-idk,am57xx-evm,am654x-evm,beaglebone-black,dra71x-evm,dra72x-evm,dra7xx-evm,j721e-evm","",""
   LCPD-12226,"P3-Medium","mmcsd first write perf decreased on some platforms","Connectivity","","am43xx-gpevm,am574x-idk,am57xx-evm,omapl138-lcdk","",""
   LCPD-10974,"P3-Medium","am43xx-gpevm - usb camera gadget shows halting frames","Connectivity","USB","am43xx-gpevm","None",""
   LCPD-7955,"P3-Medium","Uncorrectable Bitflip errors seen after switch to SystemD","Connectivity","GPMC","am335x-evm,am43xx-gpevm,k2e-evm,k2g-evm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm","Workaround to erase the NAND flash completely if flashed with an incompatible flash writer. SystemD tries to mount all partitions and that is the reason this is being seen now.",""
   LCPD-1207,"P4-Low","AM43XX/AM57XX/DRA7: CONNECTIVITY: dwc3_omap on am43xx and xhci_plat_hcd on dra7 - removal results in segmentation fault","Connectivity","USB","am43xx-gpevm,am57xx-evm,dra7xx-evm","",""


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
