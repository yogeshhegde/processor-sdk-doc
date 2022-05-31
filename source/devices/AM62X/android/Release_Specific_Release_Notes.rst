.. _release-specific-release-notes:

************************************
Release Notes
************************************

Introduction
========

The Processor Software Development Kit for Android provides a fundamental software platform for development, deployment and execution of Android-based application and includes the following:

   Bootloader components
   Linux Kernel and
   Android file system

These release notes provide instructions for both:

   Testing the release using pre-built binary image which can be loaded onto eMMC on the AM62x board
   Rebuilding the Android binary images from source code

This software release has been developed and verified in the following software and hardware development environment:

+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| **Component**                                                          |  **Version**                                                                  |
+========================================================================+===============================================================================+
| **Linux Kernel**                                                       | Linux 5.10                                                                    |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| **Android**                                                            | Android 12                                                                    |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| **Hardware Supported**                                                 | AM62x E2 board                                                                |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+

Release Features
=========

+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| **Domain**                                                             |  **Feature**                                                                  |
+========================================================================+===============================================================================+
| **Platform**                                                           | Boot from eMMC                                                                |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
|                                                                        | Fastboot USB flashing                                                         |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
|                                                                        | Support for USB ADB                                                           |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
|                                                                        | SELinux permissive                                                            |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
|                                                                        | Wifi                                                                          |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| **Graphics**                                                           | Imagination ROGUE-AXE                                                         |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+

Licensing
=========

Please refer to the software manifest, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page. The manifest can be found on the SDK
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


Release 08.03.00
==================

.. _release-specific-sdk-components-versions:


Build Information
=====================================

.. _release-specific-build-information-u-boot:

U-Boot
-------------------------

| Head Commit:
| Date:
| uBoot Version:
| uBoot Description:
| Clone: https://git.ti.com/git/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2021.01
| uBoot Tag:
| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))


Kernel
-------------------------

.. rubric:: Linux Kernel

| Head Commit:
| Date:
| Kernel Version:
| Kernel Description:
| Clone: https://git.ti.com/git/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-android-linux-5.10.y
| Tag:
| Compiler Information: aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))


AOSP
------------------------
.. rubric:: AOSP

| Head Commit:
| Date:
| Version:
| Clone: https://android.googlesource.com
| Branch: android12-release
| Release Tag:


Wakeup status
===============

Completed features
------------------

.. csv-table::
   :header: Module,Feature,Wakeup Status
   :widths: 20,60,20

Partially Complete features
---------------------------

.. csv-table::
   :header: Module,Feature,Wakeup Status
   :widths: 20,60,20

Pending/Failed features
-----------------------

.. csv-table::
   :header: Module,Feature,Wakeup Status
   :widths: 20,60,20

Installation and Usage
======================

The :ref:`Software Developer's Guide <linux-index>` provides instructions on how to setup up your Linux development
environment, install the SDK and start your development.  It also includes User's Guides for various Example Applications.

Host Support
============

For the specific supported hosts for current SDK, see :ref:`this page <how-to-build-a-ubuntu-linux-host-under-vmware>`.

Known Issues
============

+----------------+-------------------------------------------------------------------------------+
| **Issues**     |  **Description**                                                              |
+================+===============================================================================+
| **SITSW-1387** | Mcasp: Buffer underflow console messages seen                                 |
+----------------+-------------------------------------------------------------------------------+
| **SITSW-1386** | Some commands don't work from native console, but works via adb shell         |
+----------------+-------------------------------------------------------------------------------+
| **SITSW-1385** | Wi-Fi cannot be turned off and turned on second time                          |
+----------------+-------------------------------------------------------------------------------+

