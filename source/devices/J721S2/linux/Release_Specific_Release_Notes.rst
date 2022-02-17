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


Release 08.00.04
================



.. _release-specific-sdk-components-versions:

Build Information
=====================================

U-Boot
-------------------------

| Head Commit: bd58b61277a189ee49e0d6e9fd03d52996685d98 arm: dts: k3-j721s2-common-proc-board-u-boot: Add cdns,phy-mode tag
| Date: 2022-02-17 12:57:42 -0600
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2021.01
| uBoot Tag: 08.02.00.003

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))

Kernel
-------------------------
.. rubric:: Linux Kernel

| Head Commit: 4a12bec7d3f438ce9407e4ba9b2ec883729558a5 Merged TI feature connectivity into ti-linux-5.10.y
| Date: Thu Feb 17 08:21:39 2022 -0600
| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.10.y
| Tag: 08.02.00.003
| Kernel defconfig: ti_sdk_arm64_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))


Yocto
------------------------
.. rubric:: meta-ti

| Head Commit: a29c582f9e5213c46fbf0c82e7d8847079ae761e u-boot-ti-staging: Bump to 08.02.00.003 release
| Date: 2022-02-17

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: 08.02.00.003

.. rubric:: meta-arago

| Head Commit: a5999c8e10a78b0bd174d8f4463aa0f7f1dd1fd4 weston-init: Update initscript for weston-calibration
| Date: 2021-02-17

| Clone: git://git.yoctoproject.org/git/meta-arago.git
| Branch: dunfell
| Release Tag: 08.02.00.003
|

.. rubric:: meta-psdkla

| Head Commit: 403b52292d65b577556e326f8a9a68de12439acf u-boot-ti-staging: Removing u-boot patches that have been upstreamed
| Date: 2021-02-22

| Clone: git://git.ti.com/jacinto-linux/meta-psdkla.git
| Branch: j721s2
|

Wakeup status
===============

Completed features
------------------

.. csv-table::
   :header: Module,Feature,Wakeup Status
   :widths: 20,60,20

   ATF,Core 0 startup,COMPLETE
   ATF,Communication with TIFS - version message,COMPLETE
   ATF,Startup BL32 Secure OS (OPTEE),COMPLETE
   ATF,Startup A72 SPL,COMPLETE
   ATF,Startup UART,COMPLETE
   OPTEE,OP-TEE boot and return to ATF,COMPLETE
   U-Boot,JTAG connectivity (R5),COMPLETE
   U-Boot,SPL message USART,COMPLETE
   U-Boot,SPL: Base DM timer,COMPLETE
   U-Boot,SPL: version message to TIFS firmware,COMPLETE
   U-Boot,SPL configure DDR (dual instances with interleaving),COMPLETE
   U-Boot,SPL load tispl.bin(DM Firmware + ATF + OPTEE + A53 SPL),COMPLETE
   U-Boot,SPL hand off A72 boot via TIFS firmware,COMPLETE
   U-Boot,SPL jump to DM firmware,COMPLETE
   U-boot,SPL version response from DM,COMPLETE
   U-Boot,SPL startup and load u-boot.img,COMPLETE
   U-Boot,U-Boot to shell,COMPLETE
   U-Boot,Pinmux,COMPLETE
   Linux,Startup Linux kernel,COMPLETE
   Linux,Linux single-core startup,COMPLETE
   Linux,Linux kernel ramdisk shell,COMPLETE
   Linux,Pinmux bring up,COMPLETE
   Linux,Memtester,COMPLETE
   Linux,Linux earlyboot uart8250 (USART8),COMPLETE
   Linux,Linux uart8250 K3 driver,COMPLETE
   Linux/ATF/PSCI,Linux kernel dual core (Cluster 0).,COMPLETE
   Linux,"TISCI clk, PD, reset control active",COMPLETE
   Linux,TISCI RM api functionality,COMPLETE
   Linux,TISCI bringup initial version message,COMPLETE
   Linux,TISCI IRQCHIP support,COMPLETE
   Linux,Reboot functionality,COMPLETE
   Linux,DMA Engine bring up - memory to memory transfer,COMPLETE
   Linux,CPSW 2G (RGMIII) - NFS support,COMPLETE
   U-Boot,Reset,COMPLETE
   U-Boot,DMA driver,COMPLETE
   U-Boot,CPSW 2G (RGMII) - TFTP,COMPLETE
   INTEG,"Daily wakeup builds
   Automated test setup",COMPLETE
   Linux,I2C bring-up,COMPLETE
   Linux,OSPI bring-up,COMPLETE
   Linux,eMMC support,COMPLETE
   Linux,GPIO support,COMPLETE
   U-Boot,"eMMC at U-Boot prompt
   eMMC boot mode",COMPLETE
   U-Boot,UART boot mode,COMPLETE
   U-Boot,"I2C bring-up
   EEPROM",COMPLETE
   INTEG,"Daily wakeup builds (Buffer)
   Automated test setup  (Buffer)",COMPLETE
   Linux,R5F split-mode IPC only,COMPLETE
   Linux,R5F lockstep mode: remoteproc,COMPLETE
   Linux,C7x: IPC only mode,COMPLETE
   Linux,C7x: remoteproc mode,COMPLETE
   Linux,R5F lockstep mode IPC only,COMPLETE
   Linux,R5F split-mode: remoteproc mode,COMPLETE
   U-Boot,Start-up R5F core,COMPLETE
   U-Boot,Start-up C7x core.,COMPLETE
   U-Boot,USB Mass storage,COMPLETE
   Linux,CAN,COMPLETE
   Linux,PCIe EP,COMPLETE
   Linux,USB Host,COMPLETE
   Linux,USB device,COMPLETE
   U-Boot,"USB DFU support at U-Boot prompt
   DFU Boot mode",COMPLETE

Partially Complete features
---------------------------

.. csv-table::
   :header: Module,Feature,Wakeup Status
   :widths: 20,60,20

   U-Boot,SPL initialize MMC,WORKAROUND
   U-Boot,"OSPI at U-Boot prompt
   OSPI boot mode",PARITAL
   U-Boot,SD support,PARTIAL
   Linux,SD Card support,PARTIAL
   Linux,PCIe RC,PARTIAL

Pending/Failed features
-----------------------

.. csv-table::
   :header: Module,Feature,Wakeup Status
   :widths: 20,60,20

   Linux,OPTEE driver bringup,PENDING
   Linux,Mailbox functionality,PENDING
   Linux,HwSpinlock functionality,PENDING
   Linux,Display,PENDING
   Linux,Audio,PENDING
   Linux,Single Camera (CSI),PENDING
   Linux,Multi-Camera,PENDING
   Linux,Graphics,FAIL
   Linux,CnM: Video Codec,FAIL

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
