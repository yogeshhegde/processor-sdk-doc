.. _Release-note-label:

************************************
Release Notes
************************************

Overview
========

The **Processor Software Development Kit (Processor SDK)** is a unified software platform for TI embedded processors
providing easy setup and fast out-of-the-box access to benchmarks and demos.  All releases of Processor SDK are
consistent across TI’s broad portfolio, allowing developers to seamlessly reuse and develop software across devices.
Developing a scalable platform solutions has never been easier than with the Processor SDK and TI’s embedded processor
solutions.

To simplify the end user experience, Processor SDK Linux AM62A installer provides everything needed as discussed below
to create the embedded system from “scratch” :

-  Platform/board-support software and configuration files for Linux
-  U-Boot and Kernel sources and configuration files
-  An ARM cross-compiling toolchain as well as other host binaries and components
-  A Yocto/OE compliant filesystem and sources for example applications
-  A variety of scripts and Makefiles to automate certain tasks
-  Other components needed to build an embedded system that don’t fit neatly into one of the above buckets
-  Reference Examples, benchmarks


Licensing
=========

Please refer to the software manifests, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page or in the installed directory as indicated below.

-  Linux Manifest:  "/docs/software_manifest.html"


Release 09.02.00
================

Released on March 2024

What's new
----------

**Processor SDK Linux AM62A Release has following new features:**

  - Mini Fusion board support
  - LI OX05B1S Sensor support
  - Kernel: MMC Highspeed tuning and Performance Improvements
  - RT Kernel : Significant Improvements to Real-Time Linux Interrupt Latency, :ref:`RT Interrupt Latencies <RT-linux-performance>`
  - DDR: Stable Config Update, Single and multi-bit DDR ECC Support
  - Bug Fixes and Stability Improvements

**Component version:**

  - Kernel 6.1.80
  - RT Kernel 6.1.80-rt26
  - U-Boot 2023.04
  - Toolchain GCC 11.4
  - ATF 2.10
  - OPTEE 4.1

Build Information
=================

.. _u-boot-release-notes:

U-Boot
------------------

.. rubric:: u-boot
   :name: u-boot

| Head Commit: f9b966c674731a1a29a20a8e143c61d4e046f13c configs: am62x_android_a53.config: Disable splashscreen
| Date: 2024-03-21 08:39:16 -0500
| uBoot Version: 2023.04
| uBoot Description: RC Release 09.02.00.009
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2023.04
| uBoot Tag: 09.02.00.009
|

.. _tf-a-release-notes:

TF-A
------------------
| Head Commit: 00f1ec6b8740ccd403e641131e294aabacf2a48b Merge changes from topic "revert-ti-dm-workaround" into integration
| Repo: https://git.trustedfirmware.org/TF-A/trusted-firmware-a.git
| Branch: master
| Tag: 2.10
|

.. _optee-release-notes:

OP-TEE
------------------
| Head Commit: 012cdca49db398693903e05c42a254a3a0c0d8f2 plat-k3: drivers: sec_proxy: increment while reading trail bytes
| Repo: https://github.com/OP-TEE/optee_os/
| Branch: master
| Tag: 4.1.0
|

.. _ti-linux-fw-release-notes:

ti-linux-firmware
------------------
| Head Commit: 553da6850e271b579b569725ce9c58a1a6d7c849 ti-dm: Update firmware for j784s4
| Date: 2024-03-21 08:39:13 -0500
| Clone: https://git.ti.com/cgit/processor-firmware/ti-linux-firmware
| Branch: ti-linux-firmware
| Tag: 09.02.00.009
|

Kernel
------------------

.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 2e423244f8c09173a344e7069f0fe2bdf26cccee net: ethernet: ti: icssg-prueth: Fix RX frame drops in XDP
| Date: 2024-03-21 08:39:05 -0500
| Kernel Version: 6.1.80
| Kernel Description: RC Release 09.02.00.009

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-6.1.y
| Tag: 09.02.00.009
| use-kernel-config=defconfig
| config-fragment=kernel/configs/ti_arm64_prune.config
|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 3c08dbfd7bfd83c247ad1ee4ddb989260c150af1 Merge branch 'ti-linux-6.1.y-cicd' into ti-rt-linux-6.1.y-cicd
| Date: 2024-03-21 08:39:09 -0500
| Kernel Version: 6.1.80-rt26
| Kernel Description: RC Release 09.02.00.009-rt

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-6.1.y
| Tag: 09.02.00.009-rt
| use-kernel-config=defconfig
| config-fragment=config-fragment=kernel/configs/ti_arm64_prune.config kernel/configs/ti_rt.config
|

Yocto
------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 376a2143533c6497b4e79304eccca2a630784436 CI/CD Auto-Merger: cicd.kirkstone.202403201028
| Date: 2024-03-21 08:39:18 -0500

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: kirkstone
| Release Tag: 09.02.00.009
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: 98f178314931635c8641d1394dfd4341b86b6be2 CI/CD Auto-Merger: cicd.kirkstone.202403201028
| Date: 2024-03-21 08:38:40 -0500

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: kirkstone
| Release Tag: 09.02.00.009
|

.. rubric:: meta-tisdk
   :name: meta-tisdk

| Head Commit: 9131d1afc1b69d423786d100bc346949f4426b08 Fix 62x/62p build for jailhouse and RT build
| Date: 2023-12-13 04:19:26 -0600

| Clone: git://git.ti.com/ti-sdk-linux/meta-tisdk.git
| Branch: kirkstone
| Release Tag: 09.01.00.08
|

Issues Tracker
==============

Linux Known Issues
---------------------------
.. csv-table::
  :header: "Record ID", "Title", "Platform", "Workaround"
  :widths: 15, 70, 10, 25

  "LCPD-29423","AM62A: OV2312: Occassional IR frames in RGB channel","am62axx_sk-fs","PR with a workaround has been opened, Contacted sensor manufacturer for root-cause and proper fix."
  "LCPD-28950","CSI2 Multi-capture channel 0 not working","am62axx_sk-fs",""
  "LCPD-29589","AM62x CPSW: PPS example not enabled by default","am62axx_sk-fs",""
  "LCPD-32459","am62a Intermittent Boot Failure on RT-Linux","am62axx_sk-fs",""
  "LCPD-24456","Move IPC validation source from github to git.ti.com","am62axx_sk-fs",""
  "LCPD-32356","AM62x: tcrypt doesn't use sa2ul for SHA256/512 or any other alg","am62axx_sk-fs",""
  "LCPD-29588","CPSW documentation: Time Sync Router no longer firewalled","am62axx_sk-fs",""
  "LCPD-28672","CPSW: Add more details about driver config","am62axx_sk-fs",""
  "LCPD-32790","AM62A: VPU: Module load/unload in loop fails after bootup","am62axx_sk-fs",""
  "LCPD-32728","AM62x, AM62a: Doc: Update HS FS Migration Guide","am62axx_sk-fs,am62axx_sk-se",""
  "LCPD-32353","SBL remote core images does not fit the partition table defined by LINUX for serial NAND ","am62axx_sk-fs",""
  "LCPD-29113","Test gap: Linux support for CSI2 virtual channel/multiple camera support","am62axx_sk-fs",""
  "LCPD-32793","Continous noise heard while playing audio file on am62a SK board","am62axx_sk-fs",""
  "LCPD-32344","AM62: McASP recording causes CPU freezes","am62axx_sk-fs",""
  "LCPD-29943","AM64x: Upstream: Add boot mode switch settings","am62axx_sk-fs,am62axx_sk-se",""

|

