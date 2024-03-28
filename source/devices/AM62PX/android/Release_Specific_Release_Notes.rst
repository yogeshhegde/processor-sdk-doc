.. _release-specific-release-notes:

************************************
Release Notes
************************************

Introduction
============

The Processor Software Development Kit for Android provides a fundamental software platform for development, deployment and execution of Android-based application and includes the following:

   * Bootloader components
   * Linux kernel and
   * Android file system


Licensing
=========

Please refer to the software manifest, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page.


Release 09.02.00
================

Released on March 2024

What's new
----------

* This is a Android 14 based release of Processor SDK Android


Release Features
----------------

Following features are enabled/tested in this release for AM62Px Android:

* **Boot:** eMMC boot, fastboot based flashing, A/B partition
* **Security:** Keymint and gatekeeper implementation with OP-TEE
* **Platform:** SELinux enforced mode with user build, ADB over USB
* **Connectivity:** Ethernet, USB touch
* **Graphics:** GPU accelerated UI with drm_hwcomposer
* **Audio:** HDMI output and jack audio output/input
* **Multimedia:** SW video encode, :ref:`HW video decode (h264, hevc) <Android Multimedia Wave5>`, USB camera, CSI camera
* **Android Baseport:** Support of Generic System Image
* **Display:** Support for LVDS panel and dual display (mirroring and extended)

SDK Components and Versions
---------------------------

+------------------------------------+-------------------------------------------------------------------------------+
| **Component**                      |  **Version**                                                                  |
+====================================+===============================================================================+
| **Android**                        | Android 14 / Android 14 Car                                                   |
+------------------------------------+-------------------------------------------------------------------------------+
| **Linux Kernel**                   | Linux 6.1.68                                                                  |
+------------------------------------+-------------------------------------------------------------------------------+
| **Linux Kernel Toolchain**         | clang-r487747c                                                                |
+------------------------------------+-------------------------------------------------------------------------------+
| **U-boot**                         | 2023.04                                                                       |
+------------------------------------+-------------------------------------------------------------------------------+
| **GCC Toolchain**                  | GNU Toolchain for the A-profile Architecture 11.3 (rel2)                      |
+------------------------------------+-------------------------------------------------------------------------------+
| **Base Linux SDK**                 | PROCESSOR-SDK-LINUX-AM62PX 09.02.09                                           |
+------------------------------------+-------------------------------------------------------------------------------+
| **Hardware Supported**             | AM62PX-SK                                                                     |
+------------------------------------+-------------------------------------------------------------------------------+

Documentation
=============

- `Getting Started Guide`_ page provides information on getting started with pre-built binaries and booting the Android images on EVM.
- `Building the SDK`_ page provides information on downloading and building the Android images from sources.
- `Application Notes`_ page provides Application Notes.

.. _Getting Started Guide:  ../../../android/Overview_Getting_Started_Guide.html
.. _Building the SDK: ../../../android/Overview_Building_the_SDK.html
.. _Application Notes: Application_Notes.html

Host Support
============

The Processor SDK is developed, built and verified on Ubuntu 20.04 and 22.04. For all other
versions of host support refer to Android documentation.


Known Issues
============

+----------------+-----------------------------------------------------------------------+---------------------------------------------------------------------------------------------------------------------------+---------------+
| **Issues**     | **Description**                                                       | **Post Release Fix**                                                                                                      | **Component** |
+----------------+-----------------------------------------------------------------------+---------------------------------------------------------------------------------------------------------------------------+---------------+
| **SITSW-4289** | OTA via SystemUpdaterSample fails                                     | N/A                                                                                                                       | N/A           |
+----------------+-----------------------------------------------------------------------+---------------------------------------------------------------------------------------------------------------------------+---------------+
| **SITSW-4268** | Android: Seek operation not functional                                | N/A                                                                                                                       | N/A           |
+----------------+-----------------------------------------------------------------------+---------------------------------------------------------------------------------------------------------------------------+---------------+
| **SITSW-4272** | Codec2 HAL encode is not functional                                   | N/A                                                                                                                       | N/A           |
+----------------+-----------------------------------------------------------------------+---------------------------------------------------------------------------------------------------------------------------+---------------+
| **SITSW-1387** | Mcasp: Buffer underflow console messages seen                         | N/A                                                                                                                       | N/A           |
+----------------+-----------------------------------------------------------------------+---------------------------------------------------------------------------------------------------------------------------+---------------+
| **SITSW-1386** | Some commands don.t work from native console, but works via adb shell | N/A                                                                                                                       | N/A           |
+----------------+-----------------------------------------------------------------------+---------------------------------------------------------------------------------------------------------------------------+---------------+
