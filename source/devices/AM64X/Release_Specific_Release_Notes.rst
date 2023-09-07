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

To simplify the end user experience, Processor SDK Linux AM64x installer provides everything needed as discussed below
to create the embedded system from “scratch” :

-  Platform/board-support software and configuration files for Linux
-  U-Boot and Kernel sources and configuration files
-  An ARM cross-compiling toolchain as well as other host binaries and components
-  A Yocto/OE compliant filesystem and sources for example applications
-  A variety of scripts and Makefiles to automate certain tasks
-  Other components needed to build an embedded system that don’t fit neatly into one of the above buckets
-  Reference Examples, benchmarks

This release supports SR2.0 High Security - Field Securable (HS-FS) devices. For migration guide and other info, refer :ref:`HS-Migration-Guide`

Licensing
=========

Please refer to the software manifests, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page or in the installed directory as indicated below.

-  Linux Manifest:  "/docs/software_manifest.html"


Release 09.00.00
================

Released on July 2023

What's new
----------

**Processor SDK 9.0 Sitara Release supports the following platforms**

  * AM64x 2.0 (HS-FS)


**Processor SDK 9.0 Sitara Release has following Major Updates**

  * LTS Refresh with Stable Kernel 6.1, U-boot 2023.04, Yocto Kirkstone 4.0
  * Binman Migration
  * HS-FS Default Boot Experience for AM64
  * Bug Fixes and Stability Improvements
  * PRU-ICSSG: HSR Port-to-Port offload , Switch Mode, Multicast filtering in EMAC mode, Tx/Rx coalescing and Dump IET Statistic via ethtool

Build Information
=====================================

.. _u-boot-release-notes:

U-Boot
------------------

.. rubric:: u-boot
   :name: u-boot

| Head Commit: 24098ea90dbaac7b16958e2f7d9f7a412ef1522a configs: am64: Fix booting of fitImage on AM64x"
| Date: 2023-07-07 08:52:25 -0500
| uBoot Version: 2023.04
| uBoot Description: 09.00.00.006
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2023.04
| uBoot Tag: 09.00.00.006

| Compiler Information:
| - arm-gnu-toolchain-11.3.rel1-x86_64-aarch64-none-linux-gnu
| - arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-linux-gnueabihf
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

| Head Commit: 40c32565ca0e213fb653570cc618408ee8e9c6cf arm64: dts: ti: k3-am64-main: Add ITAP delay values in Device Tree
| Date: 2023-07-07 08:51:44 -0500
| Kernel Version: 6.1.33
| Kernel Description: 09.00.00.006

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-6.1.y
| Tag: 09.00.00.006
| use-kernel-config=defconfig
| config-fragment=kernel/configs/ti_arm64_prune.config

| Compiler Information:
| - arm-gnu-toolchain-11.3.rel1-x86_64-aarch64-none-linux-gnu
| - arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-linux-gnueabihf

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 685e77152461bd6b791500f717bec62d17c1b36d Merge branch 'ti-linux-6.1.y-cicd' of git://git.ti.com/ti-linux-kernel/ti-linux-kernel into ti-rt-linux-6.1.y-cicd
| Date: 2023-07-07 08:51:50 -0500
| Kernel Version: 6.1.33-rt11
| Kernel Description: 09.00.00.006-rt

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-6.1.y
| Tag: 09.00.00.006-rt
| use-kernel-config=defconfig
| config-fragment=kernel/configs/ti_arm64_prune.config kernel/configs/ti_rt.config

| Compiler Information:
| - arm-gnu-toolchain-11.3.rel1-x86_64-aarch64-none-linux-gnu
| - arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-linux-gnueabihf


Yocto
------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 2e3ffb73630f4ff78227822bdb4c23e75a720223 linux-ti-staging_6.1: CI/CD Auto-Merger: cicd.kirkstone.202307061739
| Date: 2023-07-07 08:52:30 -0500

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: kirkstone
| Release Tag: 09.00.00.006
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: e1d3561ec681fd05509affa063e0d6212f1571d1 ltp-ddt: CI/CD Auto-Merger: cicd.kirkstone.202307061739
| Date: 2023-07-07 08:51:10 -0500

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: kirkstone
| Release Tag: 09.00.00.006
|

.. rubric:: meta-processor-sdk
   :name: meta-processor-sdk

| Head Commit: 9dad5765d33783f940ba3c32f4fc431e2b308621 ti-tisdk-setup: Fix LIC_FILES_CHKSUM
| Date: 2023-07-13 11:07:46 -0500

| Clone: git://git.ti.com/processor-sdk/meta-processor-sdk.git
| Branch: kirkstone
|

Issues Tracker
==============

Issues opened in previous releases that were closed in this release
-------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 70, 20

   "LCPD-28688","am62axx_sk-fs,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk","AM62x Kernel User Guide: Document AM62x default kernel config"
   "LCPD-28492","am64xx-evm,am654x-evm","AM65: ICSSG: phc_ctl: Seeing clock jumps in get"
   "LCPD-24691","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,j721s2-evm,j721s2_evm-fs,j7200-evm","Kernel: Upstream: Set HIGH_SPEED_EN for MMC1 instance"
   "LCPD-24690","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk,j721s2-evm,j721s2_evm-fs,j7200-evm","Kernel: SDK: Set HIGH_SPEED_EN for MMC1 instance"

|
   
Issues found and closed in this release that may also be applicable to prior releases
-------------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 70, 20
    
   "LCPD-35033","am64xx-hsevm","AM64: ICSSG VLAN testcase is failing in 9.0-rc6"
   "LCPD-34994","am64xx-hsevm","AM64x: fitImage not booting"
   "LCPD-34992","am64xx-hsevm","AM64x DFU Boot fails with signed images"
   "LCPD-34966","am62axx_sk-fs,am62xx-lp-sk,am62xx-sk,am62xx_sk-fs,am64xx-evm,am64xx-sk,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721s2-evm,j784s4-evm","rpmsg_ctrl device mapping errors see with 6.1 kernel"
   "LCPD-34852","am62xx_sk-se,am64xx-evm,am654x-evm,j721e-idk-gw,j721s2-evm,j7200-evm","Few times payload is packed at size boundary by binman "
   "LCPD-34686","am62axx_sk-fs,am64xx-evm","MMC itapdly sel values are not specified in uboot DTS"
   "LCPD-34593","am62axx_sk-fs,am62xx-sk,am62xx_sk-fs,am64xx-evm,am64xx-hsevm,am654x-evm,am654x-idk,am654x-hsevm,beagleplay-gp","DISTRO BOOT: Not enabled on all Sitara Platforms"
   "LCPD-32946","am64xx-evm,am654x-evm,am654x-idk","RT Linux: PRU Ethernet link down causes kernel crash"
   "LCPD-32823","am64xx-evm,am654x-idk","ICSS firmware does not process Rx packets once Min error frame is received"

|

Errata Workarounds Available in this Release
--------------------------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 150

   "LCPD-27886","am62axx_sk-fs,am62xx-sk,am64xx-evm,j721e-idk-gw,j7200-evm,j784s4-evm,j784s4-hsevm","USART: Erroneous clear/trigger of timeout interrupt"
   "LCPD-25264","am64xx-evm,am64xx-hsevm,am64xx-sk","BCDMA: Blockcopy Gets Corrupted if TR Read Responses Interleave with Source Data Fetch"
   "LCPD-19965","am64xx-evm,am654x-idk,j721e-idk-gw,j7200-evm","OSPI PHY Controller Bug Affecting Read Transactions"

|

U-Boot Known Issues
-------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 15, 30, 70, 30
    
   "LCPD-28660","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: tiboot3.bin generated by U-Boot build is confusing users",""
   "LCPD-28503","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk","Need to sync up DTS files between u-boot and kernel for at least AM62x, possibly other boards too",""
   "LCPD-25540","am64xx-hsevm,am64xx-sk","AM64: u-boot: usb host boot failed",""

|

Linux Kernel Known Issues
-------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround" 
   :widths: 5, 10, 70, 35

   "LCPD-35022","am64xx-evm,am64xx-hsevm","AM64x: Benchmark OOB doesn't show any load on A53 and R5 (core 0) with latest ti-rpmsg-char v6.1",""
   "LCPD-34993","am64xx-hsevm","AM64x: sf probe fails on hs-fs",""
   "LCPD-34840","am64xx-hsevm","AM64: Networking failures including ICSSG",""
   "LCPD-34837","am64xx-evm,am64xx-hsevm,am654x-evm,am654x-idk","TEST: Create automated test for LCPD-32336 (ICSSG driver XDP native mode support)",""
   "LCPD-34834","am64xx-hsevm,am654x-evm,am654x-idk","Test: Create automated test for LCPD-34655 (IET Statistics for PRU Ethernet should be counted)",""
   "LCPD-32868","am64xx-evm,am654x-idk","Kernel crash from PRU auto-forwarding packet",""
   "LCPD-29861","am64xx-evm,am64xx-hsevm,am64xx-sk,am64xx-hssk","AM64x: IPC tests fail",""
   "LCPD-29515","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: Cannot boot with USB-MSC",""
   "LCPD-24537","am64xx-evm,am64xx-hsevm,am654x-evm","am654x-idk nslookup times out when all netwokring interfaces are active",""
   "LCPD-24456","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am62axx_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am62xx-vlab,am62xx-zebu,am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j7ae-evm,j7ae-zebu,j7aep-zebu,j7am-evm,j7am-vlab,j7am-zebu,j7amp-vlab,j7amp-zebu,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721e-vlab,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j7200-evm,j7200-hsevm,j7amp-evm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm,k2l-hsevm,omapl138-lcdk","Move IPC validation source from github to git.ti.com",""
   "LCPD-22931","am64xx-evm,am64xx-sk,am654x-evm,am654x-idk","RemoteProc documentation missing",""
   "LCPD-22892","am64xx-evm,am654x-evm,am654x-idk","icssg: due to FW bug both interfaces has to be loaded always",""
   "LCPD-22319","am62axx_sk-fs,am62xx-sk,am64xx-evm,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm","OpenSSL performance test data out of bounds",""

|

Linux RT Kernel Known Issues
----------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 15, 70, 20, 35
 
   "LCPD-35022","am64xx-evm,am64xx-hsevm","AM64x: Benchmark OOB doesn't show any load on A53 and R5 (core 0) with latest ti-rpmsg-char v6.1",""
   "LCPD-34993","am64xx-hsevm","AM64x: sf probe fails on hs-fs",""
   "LCPD-34840","am64xx-hsevm","AM64: Networking failures including ICSSG",""
   "LCPD-34837","am64xx-evm,am64xx-hsevm,am654x-evm,am654x-idk","TEST: Create automated test for LCPD-32336 (ICSSG driver XDP native mode support)",""
   "LCPD-34834","am64xx-hsevm,am654x-evm,am654x-idk","Test: Create automated test for LCPD-34655 (IET Statistics for PRU Ethernet should be counted)",""
   "LCPD-32868","am64xx-evm,am654x-idk","Kernel crash from PRU auto-forwarding packet",""
   "LCPD-29861","am64xx-evm,am64xx-hsevm,am64xx-sk,am64xx-hssk","AM64x: IPC tests fail",""
   "LCPD-29515","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: Cannot boot with USB-MSC",""
   "LCPD-24537","am64xx-evm,am64xx-hsevm,am654x-evm","am654x-idk nslookup times out when all netwokring interfaces are active",""
   "LCPD-24456","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am62axx_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am62xx-vlab,am62xx-zebu,am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j7ae-evm,j7ae-zebu,j7aep-zebu,j7am-evm,j7am-vlab,j7am-zebu,j7amp-vlab,j7amp-zebu,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721e-vlab,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j7200-evm,j7200-hsevm,j7amp-evm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm,k2l-hsevm,omapl138-lcdk","Move IPC validation source from github to git.ti.com",""
   "LCPD-24288","am64xx-evm,am654x-idk","am64xx-evm NCM/ACM network performance test crashes with RT images",""
   "LCPD-22931","am64xx-evm,am64xx-sk,am654x-evm,am654x-idk","RemoteProc documentation missing",""
   "LCPD-22892","am64xx-evm,am654x-evm,am654x-idk","icssg: due to FW bug both interfaces has to be loaded always",""
   "LCPD-22319","am62axx_sk-fs,am62xx-sk,am64xx-evm,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm","OpenSSL performance test data out of bounds",""

|
