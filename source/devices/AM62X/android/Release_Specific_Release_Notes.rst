.. _release-specific-release-notes:

************************************
Release Notes
************************************

Introduction
============

The Processor Software Development Kit for Android provides a fundamental software platform for development, deployment and execution of Android-based application and includes the following:

   * Bootloader components
   * Linux Kernel and
   * Android file system


Licensing
=========

Please refer to the software manifest, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page.


Release 08.04.00
================

Released on September 2022

What's new
----------

* This is a Android 12 based release of Processor SDK Android


Release Features
----------------

Following features are enabled/tested in this release for AM62x Android:

* **Boot:** eMMC boot, fastboot based flashing, A/B partition
* **Platform:** SELinux Permissive mode, ADB over USB
* **Connectivity:** Ethernet and Wi-Fi (WiLink) support, USB touch
* **Graphics:** GPU accelerated UI with Hwcomposer
* **Audio:** Audio out

SDK Components and Versions
---------------------------

+------------------------------------+-------------------------------------------------------------------------------+
| **Component**                      |  **Version**                                                                  |
+====================================+===============================================================================+
| **Android**                        | Android 12                                                                    |
+------------------------------------+-------------------------------------------------------------------------------+
| **Linux Kernel**                   | Linux 5.10.140                                                                |
+------------------------------------+-------------------------------------------------------------------------------+
| **Linux Kernel Toolchain**         | clang-r450784e                                                                |
+------------------------------------+-------------------------------------------------------------------------------+
| **U-boot**                         | 2021.01                                                                       |
+------------------------------------+-------------------------------------------------------------------------------+
| **GCC Toolchain**                  | GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)           |
+------------------------------------+-------------------------------------------------------------------------------+
| **Base Linux SDK**                 | PROCESSOR-SDK-LINUX-AM62X 08.04.01                                            |
+------------------------------------+-------------------------------------------------------------------------------+
| **Hardware Supported**             | AM62X-SK                                                                      |
+------------------------------------+-------------------------------------------------------------------------------+


Documentation
=============

- `Getting Started Guide`_ page provides information on getting started with pre-built binaries and booting the Android images on EVM.
- `Building the SDK`_ page provides information on downloading and building the Android images from sources.

.. _Getting Started Guide: Overview_Getting_Started_Guide.html
.. _Building the SDK: Overview_Building_the_SDK.html

Host Support
============

The Processor SDK is developed, built and verified on Ubuntu 18.04. For all other
versions of Host support refer to Android documentation.


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

