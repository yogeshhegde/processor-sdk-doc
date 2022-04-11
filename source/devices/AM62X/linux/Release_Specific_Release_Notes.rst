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
-  SDK Installer
-  Setup Scripts
-  Demo applications
-  Documentation

.. Note::
    For building some of the RTOS-based demonstrations, you should also download
    Processor SDK RTOS installer. For more information,
    refer to <PSDKRA install path>/index.html.

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
| Clone: https://git.ti.com/ti-u-boot/ti-u-boot.git
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
| Clone: https://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.10.y
| Tag:
| Compiler Information: aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))


Yocto
------------------------
.. rubric:: meta-ti

| Head Commit:
| Date:
| Version:
| Clone: https://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag:

.. rubric:: meta-arago

| Head Commit:
| Date:
| Version:
| Clone: https://arago-project.org/git/meta-arago.git
| Branch: dunfell
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

.. note::
   The Processor SDK Installer is 64-bit, and installs only on 64-bit host
   machine. Support for 32-bit host is dropped as Linaro toolchain is
   available only for 64-bit machines.
