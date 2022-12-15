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


Release 08.05.00
================

Released on December 2022

What's new
----------

* This is a Android 12 based release of Processor SDK Android


Release Features
----------------

Following features are enabled/tested in this release for AM62x Android:

* **Boot:** eMMC boot, fastboot based flashing, A/B partition
* **Platform:** SELinux Enforced mode with User build, ADB over USB
* **Connectivity:** Ethernet and Wi-Fi (WiLink) support, USB touch
* **Graphics:** GPU accelerated UI with Hwcomposer
* **Audio:** HDMI and Jack Audio out
* **Multimedia:** SW Video Decode/Encode, USB Camera Supported

SDK Components and Versions
---------------------------

+------------------------------------+-------------------------------------------------------------------------------+
| **Component**                      |  **Version**                                                                  |
+====================================+===============================================================================+
| **Android**                        | Android 12 / Android 12 Car                                                   |
+------------------------------------+-------------------------------------------------------------------------------+
| **Linux Kernel**                   | Linux 5.10.153                                                                |
+------------------------------------+-------------------------------------------------------------------------------+
| **Linux Kernel Toolchain**         | clang-r450784e                                                                |
+------------------------------------+-------------------------------------------------------------------------------+
| **U-boot**                         | 2021.01                                                                       |
+------------------------------------+-------------------------------------------------------------------------------+
| **GCC Toolchain**                  | GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)           |
+------------------------------------+-------------------------------------------------------------------------------+
| **Base Linux SDK**                 | PROCESSOR-SDK-LINUX-AM62X 08.05.00                                            |
+------------------------------------+-------------------------------------------------------------------------------+
| **Hardware Supported**             | AM62X-SK / AM62X-LP                                                           |
+------------------------------------+-------------------------------------------------------------------------------+


Documentation
=============

- `Getting Started Guide`_ page provides information on getting started with pre-built binaries and booting the Android images on EVM.
- `Building the SDK`_ page provides information on downloading and building the Android images from sources.
- `Application Notes`_ page provides Some Application Notes.

.. _Getting Started Guide:  ../../../android/Overview_Getting_Started_Guide.html
.. _Building the SDK: ../../../android/Overview_Building_the_SDK.html
.. _Application Notes: Application_Notes.html

Host Support
============

The Processor SDK is developed, built and verified on Ubuntu 18.04, 20.04 and 22.04. For all other
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
