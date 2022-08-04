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

| Head Commit: 6cb42d71a32d8be3a23eea08770468c16ebd35d3 arch: arm: dts: k3-j784s4-mcu-wakeup: Fix interrupt parent and id for
  wkup_gpio0, wkup_gpio1 and wkup_i2c0
| Date: 29 Jun 2022 07:01 PM
| uBoot Version: 2021.01
| Clone: git://git@bitbucket.itg.ti.com/lcpd-priv-sdk/ti-u-boot.git
| Branch: j784s4-wakeup

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

Kernel
-------------------------
.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 6e9f968521af4bcd3394d1a8c1dddb031c858893 arm64: dts: ti: k3-j784s4-main: add 2nd wave5 codec
| Date: 04 Jul 2022 05:20 PM
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

| Head Commit: e40f89a013cdadc8d8fa6d9d12011d88f7ceef7b linux-ti-staging: J7HAP Wakeup Auto-Merger: wakeup.2022.07.05.03:18:03
| Date: 2022-07-05

| Clone: ssh://git@bitbucket.itg.ti.com/coresdk/meta-ti.git
| Branch: dunfell-j7ahp-wakeup
| Release Tag: J784S4_CORE_SDK_EEA_0.9
|

.. rubric:: meta-arago

| Head Commit: 9bf6189234c6618dc5a84b389a634621c8637bf4 ti-tisdk-makefile: adding uboot r5 config variable for j784s4
| Date: 2022-06-25

| Clone: ssh://git@bitbucket.itg.ti.com/coresdk/meta-arago.git
| Branch: dunfell-j7ahp-wakeup
| Release Tag: J784S4_CORE_SDK_EEA_0.9
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

   U-Boot,JTAG connectivity (R5),Completed
   ATF,Core 0 startup,Completed
   ATF,Communication with TIFS - version message,Completed
   ATF,Startup UART,Completed
   ATF,Startup BL32 Secure OS (OPTEE),Completed
   ATF,Startup A72 SPL,Completed
   Linux,Startup Linux kernel,Completed
   Linux,Linux earlyboot uart8250 (USART8),Completed
   Linux,Linux single-core startup,Completed
   Linux,Linux uart8250 K3 driver,Completed
   Linux,Linux kernel ramdisk shell,Completed
   Linux,Memtester,Completed
   Linux,"TISCI clk, PD, reset control active",Completed
   Linux,TISCI RM api functionality,Completed
   Linux,TISCI bringup initial version message,Completed
   Linux,TISCI IRQCHIP support,Completed
   Linux,OPTEE driver bringup,Completed
   Linux,DMA Engine bring up - memory to memory transfer,Completed
   Linux,CPSW 2G (RGMIII) - NFS support,Completed
   Linux,I2C bring-up,Completed
   Linux,OSPI bring-up,Completed
   Linux,SD Card support,Completed
   Linux,eMMC support,Completed
   Linux,GPIO support,Completed
   Linux,Mailbox functionality,Completed
   Linux,R5F split-mode IPC only,Completed
   Linux,R5F lockstep mode: remoteproc,Completed
   Linux,C7x: IPC only mode,Completed
   Linux,C7x: remoteproc mode,Completed
   Linux,PCIe RC,Completed
   Linux,Display,Completed
   Linux,Multi-Camera (Risk),Completed
   Linux,Graphics,Completed
   Linux,R5F lockstep mode IPC only,Completed
   Linux,R5F split-mode: remoteproc mode,Completed
   Linux/ATF/PSCI,Linux kernel quad core (Cluster 0).,Completed
   OPTEE,OP-TEE boot and return to ATF,Completed
   U-Boot,Pinmux,Completed
   U-Boot,SPL message USART,Completed
   U-Boot,SPL: version message to TIFS firmware,Completed
   U-Boot,SPL configure DDR (quad instances with interleaving),Completed
   U-Boot,SPL initialize MMC,Completed
   U-Boot,SPL load tispl.bin(DM Firmware + ATF + OPTEE + A72 SPL),Completed
   U-Boot,SPL hand off A72 boot via TIFS firmware,Completed
   U-Boot,SPL jump to DM firmware,Completed
   U-boot,SPL version response from DM,Completed
   U-Boot,SPL startup and load u-boot.img,Completed
   U-Boot,U-Boot to shell,Completed
   U-Boot,SD support,Completed
   U-Boot,DMA driver,Completed
   U-Boot,CPSW 2G (RGMII) - TFTP,Completed
   U-Boot,Reset,Completed
   U-Boot,eMMC at U-Boot prompt,Completed
   U-Boot,I2C bring-up,Completed
   U-Boot,Start-up R5F core,Completed
   U-Boot,Start-up C7x core.,Completed
   U-Boot,eMMC boot mode,Completed
   U-Boot,EEPROM,Completed
   U-Boot,DFU Boot mode,Completed

Partially Complete features
---------------------------

.. csv-table::
   :header: Module,Feature,Wakeup Status
   :widths: 20,60,20

   Linux,USB Host,Partially Completed
   Linux,USB device,Partially Completed

Pending/Failed features
-----------------------

.. csv-table::
   :header: Module,Feature,Wakeup Status
   :widths: 20,60,20

   INTEG,Daily wakeup builds,In progress
   INTEG,Automated test setup,In progress
   Linux,CAN,In progress
   Linux,PCIe EP,In progress
   Linux,CnM: Video Codec,In progress
   U-Boot,OSPI at U-Boot prompt,In progress
   U-Boot,USB DFU support at U-Boot prompt,In progress
   U-Boot,OSPI boot mode,In progress
   Linux,Pinmux bring up,
   Linux,Reboot functionality,
   Linux,HwSpinlock functionality,
   Linux,Main CPSW,
   Linux,Audio,
   Linux,Single Camera (CSI),
   U-Boot,SPL: Base DM timer,
   U-Boot,UART boot mode,
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
