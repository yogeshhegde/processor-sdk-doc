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


Release 08.06.00
================

Released on February 2023

What's new
----------

Processor SDK Linux AM62A Release has following new features:

- AM62A: Initial Platform Support (GP, HS-FS, HS-SE with default Boot Experience on HS-FS)
- U-Boot: OSPI NAND with UBIFS, C7x and R5 Early boot, DFU Flashing, QoS Optimization for DSS and CSI load
- ATF: v2.8+
- Kernel: SD/eMMC, SDIO, GPIO, OSPI NAND, USB host and device mode, CSI Support with OV5640, IMX219, IMX390 and OV2312 Sensors, RTC, ePWM, CPSW 3G, IPC R5, IPC C7x, Mailbox, HWspinlock, VPU, SA3UL, Display( HDMI), Wave521 Video Encode and Decode, McASP audio output and capture, MCRC

Build Information
=================

.. _u-boot-release-notes:

U-Boot
------------------

.. rubric:: u-boot
   :name: u-boot

| Head Commit: 2ee8efd6543648c6b8a14d93d52a6038854035c8 Revert "configs: am57xx_evm: Enable Android commands"
| Date: Mon Feb 27 19:49:10 CST 2023
| uBoot Version: 2021.01
| uBoot Description: 08.06.00.007
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2021.01
| uBoot Tag: 08.06.00.007

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

.. _tf-a-release-notes:

TF-A
------------------
| Head Commit: 2fcd408bb3a6756767a43c073c597cef06e7f2d5 feat(ti): do not handle EAs in EL3
| Repo: https://git.trustedfirmware.org/TF-A/trusted-firmware-a.git
| Branch: master
| Tag: 2.8+
|

.. _optee-release-notes:

OP-TEE
------------------
| Head Commit: 8e74d47616a20eaa23ca692f4bbbf917a236ed94 Update CHANGELOG for 3.20.0
| Repo: https://github.com/OP-TEE/optee_os/
| Branch: master
| Tag: 3.20.0
|

.. _ti-linux-fw-release-notes:

Ti-linux-firmware
------------------
| Head Commit: 6572c6e7cad584f9bb891076ab6ba06aa062edbb ti-dm: Update firmware to 09.00.06a for J7200
| Date: 2023-07-04 09:03:52 -0500
| Clone: https://git.ti.com/cgit/processor-firmware/ti-linux-firmware
| Branch: ti-linux-firmware
| Tag: 09.00.00.006
|

Kernel
------------------

.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 2c23e6c538c879e380401ae4b236f54020618eaa Merged TI feature connectivity into ti-linux-5.10.y-cicd
| Date: Mon Feb 27 19:47:47 CST 2023
| Kernel Version: 5.10.168
| Kernel Description: 08.06.00.007

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.10.y
| Tag: 08.06.00.007
| Kernel defconfig: ti_sdk_arm64_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: c1a12919117a6978f40e723d6e0c67c744e026b9 Merge branch 'ti-rt-linux-5.10.y-cicd' into ti-rt-linux-5.10.y
| Date: Mon Feb 27 20:29:47 CST 2023
| Kernel Version: 5.10.168
| Kernel Description: 08.06.00.007-rt

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.10.y
| Tag: 08.06.00.007-rt
| Kernel defconfig: ti_sdk_arm64_rt_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

Yocto
------------------
.. rubric:: meta-processor-sdk
   :name: meta-processor-sdk

| Head Commit: 399b3bd65ef3bce99e15af7bfd76068e7fa9bb3f edgeai-components: Add tags for EDGEAI_APP_STACK_08_06_00_02
| Date: 2023-02-27
| Clone: git://git.ti.com/processor-sdk/meta-processor-sdk.git
| Branch: dunfell
| Release Tag: 08.06.00
|

.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 45bdaf7da0bc79fa73f1e01bb30b5c3b2eb34545 linux-ti-staging-rt: RC Auto-Merger: 08.06.00.007
| Date: 2023-02-23
| Clone: git://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: 08.06.00.007
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: e4fcc247b2fadc457efaff8edabdf12a6b4fa4d1 ltp-ddt: CI/CD Auto-Merger: cicd.dunfell.202302211800
| Date: 2023-02-23

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: dunfell
| Release Tag: 08.06.00.007
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

