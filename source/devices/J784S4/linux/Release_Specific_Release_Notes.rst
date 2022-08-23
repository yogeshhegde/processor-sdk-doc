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
-  Demo applications
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


Release 08.02.01
================

Released July 2022

.. rubric:: What's New
   :name: whats-new

Processor SDK 8.2.1 Release has following new features:
- Initial Platform Support


.. _release-specific-sdk-components-versions:

Build Information
=====================================

U-Boot
-------------------------

| Head Commit: 53e3a12a1d76913fcf20820eaa6cfb9bbead5550 arm: mach-k3: j784s4: Update clock and device data
| Date: 15 Jul 2022 12:00 AM
| uBoot Version: 2021.01
| Clone: git://git@bitbucket.itg.ti.com/lcpd-priv-sdk/ti-u-boot.git
| Branch: j784s4-wakeup

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

Kernel
-------------------------
.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 507e01cc16db513193008988f5606fefb915bf3b arm64: dts: ti: k3-j784s4-main: Update device id for main_gpio_intr
| Date: 14 Jul 2022 11:42 PM
| Kernel Version: 5.10.120

| Clone: ssh://git@bitbucket.itg.ti.com/lcpd-priv-sdk/ti-linux-kernel.git
| Branch: j784s4-wakeup
| Kernel defconfig: ti_sdk_arm64_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

.. rubric:: Note:

| meta-psdkla Yocto layer contains additional patches for Linux Kernel
  `here <https://bitbucket.itg.ti.com/projects/PSDKLA/repos/meta-psdkla-internal/browse/recipes-kernel/linux/linux-ti-staging/j784s4-evm?at=7a6b1f0632bc9fd514fb70ff9f37ba516b615fa0>`_.
|

Yocto
------------------------
.. rubric:: meta-ti

| Head Commit: c76841d3d791761d06e7bbd3a8b94979cc93eef0 cnm-wave-fw: Add support for j784s4-evm
| Date: 2022-07-20

| Clone: ssh://git@bitbucket.itg.ti.com/coresdk/meta-ti.git
| Branch: dunfell-j7ahp-wakeup
|

.. rubric:: meta-arago

| Head Commit: 9bf6189234c6618dc5a84b389a634621c8637bf4 ti-tisdk-makefile: adding uboot r5 config variable for j784s4
| Date: 2022-06-25

| Clone: ssh://git@bitbucket.itg.ti.com/coresdk/meta-arago.git
| Branch: dunfell-j7ahp-wakeup
|

.. rubric:: meta-psdkla

| Head Commit: 7a6b1f0632bc9fd514fb70ff9f37ba516b615fa0 Revert "recipes-bsp: Temporarily removing this deployment while it is not available"
| Date: 2022-07-06

| Clone: https://bitbucket.itg.ti.com/scm/psdkla/meta-psdkla-internal.git
| Branch: j784s4_nightly
|

Wakeup status
===============

Completed features
------------------

.. csv-table::
   :header: Module,Feature,Wakeup Status
   :widths: 20,60,20

   ATF,Communication with TIFS - version message,COMPLETE
   ATF,Core 0 startup,COMPLETE
   ATF,Startup A72 SPL,COMPLETE
   ATF,Startup BL32 Secure OS (OPTEE),COMPLETE
   ATF,Startup UART,COMPLETE
   INTEG,"Daily wakeup builds (Buffer)
   Automated test setup (Buffer)",COMPLETE
   Linux,C7x: IPC only mode,COMPLETE
   Linux,C7x: remoteproc mode,COMPLETE
   Linux,CAN,COMPLETE
   Linux,CnM: Video Codec,COMPLETE
   Linux,CPSW 2G (RGMIII) - NFS support,COMPLETE
   Linux,Display,COMPLETE
   Linux,DMA Engine bring up - memory to memory transfer,COMPLETE
   Linux,eMMC support,COMPLETE
   Linux,GPIO support,COMPLETE
   Linux,Graphics,COMPLETE
   Linux,I2C bring-up,COMPLETE
   Linux,Linux earlyboot uart8250 (USART8),COMPLETE
   Linux,Linux kernel ramdisk shell,COMPLETE
   Linux,Linux single-core startup,COMPLETE
   Linux,Linux uart8250 K3 driver,COMPLETE
   Linux,Mailbox functionality,COMPLETE
   Linux,Memtester,COMPLETE
   Linux,Multi-Camera (Risk),COMPLETE
   Linux,OPTEE driver bringup,COMPLETE
   Linux,OSPI bring-up,COMPLETE
   Linux,PCIe RC,COMPLETE
   Linux,Pinmux bring up,COMPLETE
   Linux,R5F lockstep mode: remoteproc,COMPLETE
   Linux,R5F split-mode IPC only,COMPLETE
   Linux,Reboot functionality,COMPLETE
   Linux,SD Card support,COMPLETE
   Linux,Startup Linux kernel,COMPLETE
   Linux,TISCI bringup initial version message,COMPLETE
   Linux,"TISCI clk, PD, reset control active",COMPLETE
   Linux,TISCI IRQCHIP support,COMPLETE
   Linux,TISCI RM api functionality,COMPLETE
   Linux,USB device,COMPLETE
   Linux,USB Host,COMPLETE
   Linux,R5F lockstep mode IPC only,COMPLETE
   Linux,R5F split-mode: remoteproc mode,COMPLETE
   Linux/ATF/PSCI,Linux kernel quad core (Cluster 0).,COMPLETE
   OPTEE,OP-TEE boot and return to ATF,COMPLETE
   U-Boot,CPSW 2G (RGMII) - TFTP,COMPLETE
   U-Boot,"DFU Boot mode",COMPLETE
   U-Boot,DMA driver,COMPLETE
   U-Boot,"eMMC at U-Boot prompt
   eMMC boot mode",COMPLETE
   U-Boot,"I2C bring-up
   EEPROM",COMPLETE
   U-Boot,JTAG connectivity (R5),COMPLETE
   U-Boot,Pinmux,COMPLETE
   U-Boot,Reset,COMPLETE
   U-Boot,SD support,COMPLETE
   U-Boot,SPL configure DDR (quad instances with interleaving),COMPLETE
   U-Boot,SPL hand off A72 boot via TIFS firmware,COMPLETE
   U-Boot,SPL initialize MMC,COMPLETE
   U-Boot,SPL jump to DM firmware,COMPLETE
   U-Boot,SPL load tispl.bin(DM Firmware + ATF + OPTEE + A72 SPL),COMPLETE
   U-Boot,SPL message USART,COMPLETE
   U-Boot,SPL startup and load u-boot.img,COMPLETE
   U-boot,SPL version response from DM,COMPLETE
   U-Boot,SPL: version message to TIFS firmware,COMPLETE
   U-Boot,Start-up C7x core.,COMPLETE
   U-Boot,Start-up R5F core,COMPLETE
   U-Boot,U-Boot to shell,COMPLETE
   U-Boot,UART boot mode,COMPLETE


Pending/Failed features
-----------------------

.. csv-table::
   :header: Module,Feature,Wakeup Status
   :widths: 20,60,20

   INTEG,"Daily wakeup builds
   Automated test setup",In progress
   Linux,PCIe EP,In progress
   U-Boot,"OSPI at U-Boot prompt
   OSPI boot mode",In progress
   U-Boot,"USB DFU support at U-Boot prompt",In progress
   Linux,Audio,
   Linux,HwSpinlock functionality,
   Linux,Main CPSW,
   Linux,Single Camera (CSI),
   U-Boot,SPL: Base DM timer,
   U-Boot,USB Mass storage,

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
