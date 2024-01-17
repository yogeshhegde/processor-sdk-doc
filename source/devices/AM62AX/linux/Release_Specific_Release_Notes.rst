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


Release 09.01.00
================

Released on December 2023

What's new
----------

Processor SDK Linux AM62A Release has following new features:

- Kernel: MCAN, eQEP
- IPC: Mailbox, Shared buffer example (C7x, DM R5, MCU R5)
- UB954 Fusion board support
- Power Management: DeepSleep, MCU-Only and Partial IO mode
- Significant Improvements to Real-Time Linux Interrupt Latency, :ref:`RT Interrupt Latencies <RT-linux-performance>`
- Bug Fixes and Stability Improvements
- OPTEE v4.0, ATF v2.9+ Upgrade

Build Information
=================

.. _u-boot-release-notes:

U-Boot
------------------

.. rubric:: u-boot
   :name: u-boot

| Head Commit: b0d717b732ee28e446baf94522b3491e590f7fbb configs: am62*_r5_usbmsc_defconfig: Set SPL_STACK_R_MALLOC_SIMPLE_LEN to 2M
| Date: 2023-12-06 19:02:00 -0600
| uBoot Version: 2023.04
| uBoot Description: 09.01.00.008
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2023.04
| uBoot Tag: 09.01.00.008
|

.. _tf-a-release-notes:

TF-A
------------------
| Head Commit: d7a7135d32a8c7da004c0c19b75bd4e2813f9759 fix(ti): fix TISCI API changes during refactor
| Repo: https://git.trustedfirmware.org/TF-A/trusted-firmware-a.git
| Branch: master
| Tag: 2.9+
|

.. _optee-release-notes:

OP-TEE
------------------
| Head Commit: 2a5b1d1232f582056184367fb58a425ac7478ec6 Update CHANGELOG for 4.0.0
| Repo: https://github.com/OP-TEE/optee_os/
| Branch: master
| Tag: 4.0.0
|

.. _ti-linux-fw-release-notes:

Ti-linux-firmware
------------------
| Head Commit: 9ee2fedb1fb4815f54310dd872d34faf9948c7c1 ti-dm: Update display sharing firmware for am62px
| Date: 2023-12-06 19:01:59 -0600
| Clone: https://git.ti.com/cgit/processor-firmware/ti-linux-firmware
| Branch: ti-linux-firmware
| Tag: 09.01.00.008
|

Kernel
------------------

.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 247b2535b24894d5ac7f3d8cfc3b48edb7214cc0 configs: ti_rt.config: disable CPU hotplug
| Date: 2023-12-06 19:01:53 -0600
| Kernel Version: 6.1.46
| Kernel Description: 09.01.00.008

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-6.1.y
| Tag: 09.01.00.008
| use-kernel-config=defconfig
| config-fragment=kernel/configs/ti_arm64_prune.config
|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 833521d9b354beb95bac8b37bfc211495d73d36c Merge branch 'ti-linux-6.1.y-cicd' into ti-rt-linux-6.1.y-cicd
| Date: 2023-12-06 19:01:56 -0600
| Kernel Version: 6.1.46-rt13
| Kernel Description: 09.01.00.008-rt

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-6.1.y
| Tag: 09.01.00.008-rt
| use-kernel-config=defconfig
| config-fragment=kernel/configs/ti_arm64_prune.config kernel/configs/ti_rt.config
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

