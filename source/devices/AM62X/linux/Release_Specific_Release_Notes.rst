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

To simplify the end user experience, Processor SDK Linux AM62x installer provides everything needed as discussed below
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


Release 09.00.00
================

Released on October 2023

What's new
------------------

Processor SDK Linux AM62xSIP Release has following new features:

- New improved OOB experience
- Kirkstone filesystem on Yocto based distribution
- Binman Migration across all K3 platforms for Uboot builds
- HS-FS Default Boot Experience for AM62xSIP
- A53 Early Splash-Screen
- Low Power: Deep Sleep on HS-FS, MCU Only mode and more wakeup sources

Major Refresh of component version:

- Kernel 6.1
- U-Boot 2023.04
- Toolchain GCC 11.2
- ATF 2.8+
- OPTEE 3.20
- Graphics DDK 23.1

Build Information
=================

.. _u-boot-release-notes:

U-Boot
------------------

.. rubric:: u-boot
   :name: u-boot

| Head Commit: 9390b636e8e292a85f236b4f1c70feb0ad8299cc arm: dts: k3-am64-main: Add ITAP delay values in Device Tree"
| Date: 2023-10-07 06:39:59 -0500
| uBoot Version: 2023.04
| uBoot Description: 09.00.00.011
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2023.04
| uBoot Tag: 09.00.00.011
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
| Head Commit: 8e74d47616a20eaa23ca692f4bbbf917a236ed94 Update CHANGELOG for 3.20.0
| Repo: https://github.com/OP-TEE/optee_os/
| Branch: master
| Tag: 3.20.0
|

.. _ti-linux-fw-release-notes:

Ti-linux-firmware
------------------
| Head Commit: f903ca69b36c5a991728867153bf2e10cac35f6c Merge branch 'main' of git://git.kernel.org/pub/scm/linux/kernel/git/firmware/linux-firmware into ti-linux-firmware
| Date: 2023-07-04 09:03:52 -0500
| Clone: https://git.ti.com/cgit/processor-firmware/ti-linux-firmware
| Branch: ti-linux-firmware
| Tag: 09.00.00.011
|

Kernel
------------------

.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit:  3ec3755134e2a6c107b43e335fa32c958a2fe5f6 Revert "HACK: arm64: dts: ti: k3-j721s2-common-proc-board: Disable DSI"
| Date: 2023-10-07 06:39:48 -0500
| Kernel Version: 6.1.46
| Kernel Description: 09.00.00.011

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-6.1.y
| Tag: 09.00.00.011
| use-kernel-config=defconfig
| config-fragment=kernel/configs/ti_arm64_prune.config
|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit:  4a3a5f9a7567d507b37b51980516ce26b34b353e Merge branch 'ti-linux-6.1.y-cicd' of git://git.ti.com/ti-linux-kernel/ti-linux-kernel into ti-rt-linux-6.1.y-cicd
| Date: 2023-10-07 06:39:51 -0500
| Kernel Version: 6.1.46-rt13
| Kernel Description: 09.00.00.011-rt

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-6.1.y
| Tag: 09.00.00.011-rt
| use-kernel-config=defconfig
| config-fragment=kernel/configs/ti_arm64_prune.config kernel/configs/ti_rt.config
|

Yocto
------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit:  5fd6a816470feefc9c58c5d3ae1b2fb93bead787 linux-ti-staging_6.1: CI/CD Auto-Merger: cicd.kirkstone.202310061657
| Date: 2023-10-07 06:40:00 -0500

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: kirkstone
| Release Tag: 09.00.00.011
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit:  08c9b5656f2d514f27ba580afdc2cd937ce059e4 arago-gpl-notice: Update script to look for updated GPL-3.0 identifier
| Date: 2023-10-07 06:39:40 -0500

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: kirkstone
| Release Tag: 09.00.00.011
|

Issues Tracker
==============

Errata Workarounds Available in this Release
--------------------------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 15, 30, 60, 35

   "LCPD-27887","am62xxsip_sk-fs,am62xxsip_sk-se,am62xx-sk,am62xx_sk-fs","i2327: RTC: Hardware wakeup event limitation","None"
   "LCPD-27886","am62xxsip_sk-fs,am62xxsip_sk-se,am62xx-sk","USART: Erroneous clear/trigger of timeout interrupt",""

|

U-Boot Known Issues
-------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 15, 30, 60, 35

   "LCPD-36618","am62xxsip_sk-fs, am62xxsip_sk-se","AM62SIP: reserving fdt memory region failed error seen at bootup",""
   "LCPD-29874","am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se","am62x: robustness: fails to boot 100 reboot test consistently",""
   "LCPD-36820","am62xxsip_sk-fs, am62xxsip_sk-se","USB DFU: OSPI boot failure",""
   "LCPD-36819","am62xxsip_sk-fs, am62xxsip_sk-se","Flashing filesystem to eMMC fails if size is >50MB",""

|

Linux Kernel Known Issues
-------------------------
.. csv-table::
    :header: "Record ID", "Platform", "Title", "Workaround"
    :widths: 15, 30, 60, 35

    "LCPD-36812","am62xx_sk-fs, am62xx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se","RTC: tests fail",""
    "LCPD-36805","am62xx_sk-fs, am62xx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se","ETHERNET boot test fail incorrect configuration",""
    "LCPD-36804","am62xx_sk-fs, am62xx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se","IPC performance test fail - modprobe fails",""
    "LCPD-36803","am62xx_sk-fs, am62xx_sk-se, am62xx_lp_sk-fs, am62xx_lp_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se","USBDEV: test case fail - USB devices not enumerated",""
    "LCPD-36801","am62xx_sk-fs, am62xx_sk-se, am62xx_lp_sk-fs, am62xx_lp_sk-se, am62axx_sk-fs, am62axx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se, am62pxx_sk-fs, am62pxx_sk-se","USB-DFU boot test fail incorrect configuration",""
    "LCPD-36653","am62xx_sk-fs, am62xx_sk-se, beagleplay-gp, am62xx_lp_sk-fs, am62xx_lp_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se",modprobe -r dwc3-am62 fails",""
    "LCPD-34242","am62xx_sk-fs, am62xxsip_sk-fs, am62xxsip_sk-se, am62xx-sk","GPIO_S_FUNC_DIR_IN_ALL_BANK unit test fails",""
    "LCPD-29876","am62xx_sk-fs, am62xx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se, am62xx-sk","am62x: crypto RNG functional and performance tests failures",""
    "LCPD-29874","am62xx_sk-fs, am62xx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se, am62xx-sk",am62x: robustness: fails to boot 100 reboot test consistently",""
    "LCPD-29445","am62xx_sk-fs, am62xx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se, am62xx-sk",am62xx-sk: MCAN loop-back test is failing",""
    "LCPD-28104","am62xx_sk-fs, am62xx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se, am62xx-sk",Automated test failure - CPSW test is passing invalid parameters to switch-config",""
    "LCPD-34397","am62xxsip_sk-fs, am62xxsip_sk-se, am62xx-sk","usb xhci locks up after multiple Linux reboot",""

|

Linux SDK Known Issues
----------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 15, 30, 60, 35


   "LCPD-35083","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se","AM62: PRU rpmsg samples echo sample FW are not getting installed","MACHINE=am62xx-evm bitbake pru-icss; install the ipk on the targetfs; opkg install pru-icss-rpmsg-echo_6.2.0-r1.0_am62xx_evm.ipk"


|
