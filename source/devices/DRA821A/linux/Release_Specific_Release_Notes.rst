.. _release-specific-release-notes:

************************************
Release Notes
************************************

Overview
========

The **Processor Software Development Kit (Processor-SDK) for Linux**
provides a fundamental software platform for development, deployment and
execution of Linux based applications and includes the following:

-  Bootloaders, Linux Kernel & Filesystem
-  SDK installer
-  Setup scripts
-  Documentation

.. Note::
    For building some of the RTOS-based demonstrations, you should also download
    Processor SDK RTOS installer. For more information,
    refer to <PSDKRA install path>/index.html.


Licensing
=========

Please refer to the software manifest, which outlines the licensing
status for all packages included in this release. The manifest can be found on the SDK
download page or in the installed directory as indicated below. In
addition, see :ref:`Processor SDK Linux GPLv3 Disclaimer <overview-gplv3-disclaimer>`.


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


Supported Platforms
=====================================
See :ref:`here <release-specific-supported-platforms-and-versions>` for a list of supported platforms and links to more information.


Release 07.01.01
================
Released November 2020

Release features
----------------

-  A72 U-boot:

   -  Support for booting both compressed and uncompressed kernel image
   -  Basic HYP mode support - boots up uboot in EL2 privileged mode
   -  MMCSD support
   -  SD card boot support
   -  USB Host and mass storage support
   -  Support for DFU download to SD card, eMMC
   -  UFS support
   -  eMMC boot support
-  Kernel: Kernel image includes support for the following drivers

   -  MMC support
   -  I2C support
   -  CPSW2G Ethernet driver
   -  UART driver, UART console support
   -  USB driver with support for device/host mode of operation
   -  PCIe Root Complex  and Endpoint drivers
   -  USB gadget driver support

      -  Composite device
      -  Multifunction composite device
   -  USB DRD dual role support
   -  Support for dual voltage SD cards (UHS mode)
   -  PCIe Gen3 2xlane support
   -  eMMC HS400 speed mode support
   -  UART DMA mode support
   -  UFS support
   -  ADC basic functionality
   -  Crypto acceleration support for AES, 3-DES, and RNG
-  Profiling

   -  A72 PMU support for Performance profiling



Component versions
------------------

.. csv-table::
   :header: "component", "source", "branch", "version"
   :widths: 20,40,20,30

   arm-trusted-firmware,git://git.ti.com/atf/arm-trusted-firmware.git,ti-atf,52c334fc361194e3896ea3b2529c10a06e586a5f
   optee-os,git://git.ti.com/optee/ti-optee-os.git,ti-optee-os,199fca17b575d4c748c9c435e908a6ec9618c75a
   U-boot,git://git.ti.com/ti-u-boot/ti-u-boot.git,ti-u-boot-2020.01,3c9ebdb87d65aacc4ec302be8bef3df15364bacd
   Linux Kernel,git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git,ti-linux-5.4.y,9574bba32a1898794895ca3816e815154c80226d
   Jailhouse,git://git.ti.com/jailhouse/ti-jailhouse.git,ti-jailhouse-0.12,0d059b6f2c3efeaa2466517300540498b34b7655


Issues Tracker
===============
..
   Issues fixed in this release: project in (LCPD, "ADAS Algorithms") AND issuetype = Bug AND project = LCPD AND platform=j7200-evm  AND ErrataID is not EMPTY AND status = Closed ORDER BY priority DESC) AND fixversion in (2020.00, 07.00.00, SDK_J7_07_00_00) AND OS = Linux and resolution = Done AND (Labels not in (LCPD_K3.14_MAINT, MAINTENANCE, PLSDK_NOT_RN) OR labels is EMPTY) ORDER BY key ASC

..
   Errata workarounds: project = LCPD AND platform=j7200-evm  AND ErrataID is not EMPTY AND status = Closed AND (Labels not in (PLSDK_NOT_RN) OR labels is EMPTY) ORDER BY priority DESC

..
   project in (LCPD, "ADAS Algorithms") AND issuetype = Bug AND platform=j7200-evm  AND status not in ("In Build", Closed, Resolved) AND OS = Linux AND (Labels not in (PLSDK_NOT_RN, SKIP_REL_NOTES) OR labels is EMPTY) AND component != "System Test" ORDER BY key ASC

Open Defects
------------
.. csv-table::
   :header: "Record ID", "Summary", "Workaround"
   :widths: 20, 80, 60

   LCPD-17798,2020 LTS: INTA/INTR smp_affinity failure and IRQ allocation issues.,
   LCPD-19460,J7200: USB3 devices fail to enumerate at 2.0 when SERDES multi-link (PCIe + USB3),No workaround for USB 3.0 devices exists. USB 2.0 devices enumerate fine.
   LCPD-19497,CPSW2g: interface goes up and down sporadically,Seen only on very few EVMs. No workaround. 
   LCPD-19499,Kernel: OSPI write throughput is less than 1MB/s,
   LCPD-19519,Kernel: RT Linux build error with SPI NOR hack to find the PHY pattern location,
   LCPD-19659,Doc: PCIe: Update documentation to indicate how to move to compliance mode,
   LCPD-19664,Upstream: kernel MMC dts properties need to avoid _ in property names,
   LCPD-19716,GFX_XS_FUNC_UYVY_TEXTURE test fails,
   LCPD-19723,RTI watchdog test fails on J7VCL E5 SOM,
   LCPD-19772,ATF/Uboot GTC frequency handover bug,
   LCPD-19800,tisci_sysreset_request blocks boot for several tests,
   LCPD-19838,Cryptodev not building against 5.10 kernel,
   LCPD-19858,OE: OPTEE label used in SDK is old and wrong,

..
   Known issues & limitations: project = LCPD AND issuetype = Bug AND platform=j7200-evm AND status = Closed AND resolution in ("Known Issue : HW Limitation", "Known Issue : Other") AND OS = Linux AND (Labels not in (PLSDK_NOT_RN) OR labels is EMPTY) ORDER BY key ASC


Known issues & limitations
--------------------------
.. csv-table::
   :header: "Record ID", "Summary" , "Workaround"
   :widths: 20, 80, 60

   LCPD-19636,J7: OSPI Boot broken,
   LCPD-19739,AM65 shutdown error,
   LCPD-19743,Packages.gz is missing,

|


Installation and Usage
======================

The :ref:`Software Developer's Guide <linux-index>` provides instructions on how to setup your Linux development environment, install the SDK and start your development. It also includes User's Guides for various Example Applications.

|

Host Support
============

For the specific supported hosts for current SDK, see :ref:`this page <how-to-build-a-ubuntu-linux-host-under-vmware>`.


.. note::
   Processor SDK Installer is 64-bit, and installs only on 64-bit host machine. 

.. |reg| unicode:: U+00AE .. REGISTERED SIGN
