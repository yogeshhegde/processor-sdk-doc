************************************
Release Notes
************************************
.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Release_Notes

Overview
========

The **Processor-CoreSDK for Linux**
provides a fundamental software platform for development, deployment and
execution of Linux based applications and includes the following:

  * Bootloaders & Filesystems.
  * Prebuilt Binaries.
  * Detailed Release Notes.

Licensing
=========

Please refer to the software manifest, which outlines the licensing
status for all packages included in the prebuilt binaries location.

Release 09.00.00 Refresh 2
==========================
Released October 2023

.. rubric:: What's New
   :name: whats-new

**Processor SDK 9.0 Sitara Release supports the following platforms**
  * AM335x (GP, HS), AM437x (GP, HS)

**Processor SDK 9.0 Sitara Release has following Major Updates**

  * LTS Refresh with Stable Kernel 6.1, U-boot 2023.04, Yocto Dunfell 4.0


Release 09.00.00 Refresh 1
==========================

Released October 2023

.. rubric:: What's New
   :name: whats-new

**Processor SDK 9.0 Sitara Release supports the following platforms**

  * AM62SIP 2.0 (HS-FS, HS-SE)

**Processor SDK 9.0 Sitara Release has following Major Updates**

  * LTS Refresh with Stable Kernel 6.1, U-boot 2023.04, Yocto Dunfell 4.0
  * Binman Migration
  * HS-FS Default Boot Experience
  * Graphics: Weston 10 and DDK 23.1 Upgrade
  * Multimedia: Gstreamer v1.20.5 Upgrade


Release 09.00.00
==================

Released July 2023

.. rubric:: What's New
   :name: whats-new

**Processor SDK 9.0 Sitara Release supports the following platforms**

  * AM64x 2.0 (HS-FS)
  * AM62x (GP, HS-FS, HS-SE)
  * AM62x LP (HS-FS, HS-SE)
  * AM62A (HS-FS, HS-SE)

**Processor SDK 9.0 Sitara Release has following Major Updates**

  * LTS Refresh with Stable Kernel 6.1, U-boot 2023.04, Yocto Dunfell 4.0
  * Binman Migration
  * HS-FS Default Boot Experience for AM64, AM62, AM62A, AM62 LP
  * Graphics: Weston 10 and DDK 23.1 Upgrade
  * Multimedia: Gstreamer v1.20.5 Upgrade

**AM62A**

  * U-Boot: Remoteproc boot with C7x
  * Kernel: E5010 JPEG Encoder
  * Low Power: DFS and CPUIdle on HS FS
  * Camera: V4L2 multi-stream controls

**AM62**

  * Uboot: A53 Early splash screen and bmp display
  * Low Power: Deep Sleep mode: HS FS Support, Main IO Daisychain support, Remoteproc with M4 and R5 Cores
  * Low Power: Wakeup Sources: MCU GPIO, Main I/O Daisy wakeup, MCU M4 IPC Wakeup
  * Low Power: DFS and CPUIdle on HS FS
  * Low Power: MCU Only mode
  * Kernel: Multi MCAN
  * IPC: A53 --> DM R5
  * Camera: Libcamera support
  * Audio: Recording bug-fixes

**AM64**

  * Bug Fixes and Stability Improvements
  * PRU-ICSSG: HSR Port-to-Port offload , Switch Mode, Multicast filtering in EMAC mode, Tx/Rx coalescing and Dump IET Statistic via ethtool

**AM65**

  * PRU-ICSSG: Multicast filtering in EMAC mode, Tx/Rx coalescing and Dump IET Statistic via ethtool


Build Information
=====================================

U-Boot
-------------------------
| Head Commit: 9390b636e8e292a85f236b4f1c70feb0ad8299cc arm: dts: k3-am64-main: Add ITAP delay values in Device Tree"
| Date: 2023-10-07 06:39:59 -0500
| uBoot Version: 2023.04
| uBoot Description: 09.01.00.001
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2023.04
| uBoot Tag: 09.01.00.001
|


Kernel
-------------------------
.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 1d4b5da681ea4d617c01a72ad18b228d7438db7a arm64: dts: ti: k3-am625-sk: Remove regulator always on for wlan lt
| Date: 2023-10-20 08:11:38 -0500
| Kernel Version: 6.1.46
| Kernel Description: 09.01.00.001

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-6.1.y
| Tag: 09.01.00.001
| use-kernel-config=multi_v7_defconfig
| config-fragment=kernel/configs/ti_multi_v7_prune.config kernel/configs/no_smp.config
|


.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: ccf548983bd6630d4a1a5b60d94d25d6387b73d2 Merge branch 'ti-linux-6.1.y-cicd' of git://git.ti.com/ti-linux-kernel/ti-linux-kernel into ti-rt-linux-6.1.y-cicd
| Date: 2023-10-20 08:11:41 -0500
| Kernel Version: 6.1.46-rt13
| Kernel Description: 09.01.00.001-rt

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-6.1.y
| Tag: 09.01.00.001-rt
| use-kernel-config=multi_v7_defconfig
| config-fragment=kernel/configs/ti_multi_v7_prune.config kernel/configs/no_smp.config kernel/configs/ti_rt.config
|



Yocto
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 59edb4e886df468edeb683355c36f06004b29925 linux-ti-staging_6.1: CI/CD Auto-Merger: cicd.kirkstone.202310191725
| Date: 2023-10-20 08:11:47 -0500

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: kirkstone
| Release Tag: 09.01.00.001
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: a9dcc0583f44bd7a7d8780759c2091b85d280ec2 ltp-ddt: CI/CD Auto-Merger: cicd.kirkstone.202310191725
| Date: 2023-10-20 08:11:26 -0500

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: kirkstone
| Release Tag: 09.01.00.001
|

Issues Tracker
=====================================


U-Boot Known Issues
------------------------
.. csv-table::
  :header: "Record ID", "Platform", "Title", "Workaround"
  :widths: 15, 30, 70, 30


|

Linux Known Issues
---------------------------
.. csv-table::
  :header: "Record ID", "Platform", "Title", "Workaround"
  :widths: 5, 10, 70, 35


|


