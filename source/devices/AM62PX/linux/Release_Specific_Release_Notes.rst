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

To simplify the end user experience, Processor SDK Linux AM62Px installer provides everything needed as discussed below
to create the embedded system from “scratch” :

-  Platform/board-support software and configuration files for Linux
-  U-Boot and Kernel sources and configuration files
-  An ARM cross-compiling toolchain as well as other host binaries and components
-  A Yocto/OE compliant filesystem and sources for example applications
-  A variety of scripts and Makefiles to automate certain tasks
-  Other components needed to build an embedded system that don’t fit neatly into one of the above buckets
-  Reference Examples, benchmarks

This release supports High Security - Field Securable (HS-FS) devices. For migration guide and other info, refer :ref:`HS-Migration-Guide`

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
------------------

Processor SDK Linux AM62Px Release has following new features:

- New improved OOB experience
- Kirkstone filesystem on Yocto based distribution
- Binman Migration across all K3 platforms for Uboot builds
- HS-FS Default Boot Experience for AM62Px

Major Refresh of component version:

- Kernel 6.1
- U-Boot 2023.04
- Toolchain GCC 11.4
- ATF 2.9+
- OPTEE 4.0
- Graphics DDK 23.2

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
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 6ad91a192fa1ab33775a22894a413aefd0b67106 CI/CD Auto-Merger: cicd.kirkstone.202312061239
| Date: 2023-12-06 19:02:01 -0600

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: kirkstone
| Release Tag: 09.01.00.008
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: 190e2b58fb6c1e3c658fe2f7afc40a2863007bbc CI/CD Auto-Merger: cicd.kirkstone.202312061239
| Date: 2023-12-06 19:01:43 -0600

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: kirkstone
| Release Tag: 09.01.00.008
|

Issues Tracker
==============

Errata Workarounds Available in this Release
--------------------------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 15, 30, 60, 35

|

U-Boot Known Issues
-------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 15, 30, 60, 35


|

Linux Kernel Known Issues
-------------------------
.. csv-table::
    :header: "Record ID", "Platform", "Title", "Workaround"
    :widths: 15, 30, 60, 35

|

Linux SDK Known Issues
----------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 15, 30, 60, 35



|
