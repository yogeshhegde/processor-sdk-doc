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


Release 08.06.00
================

Released on February 2023

What's new
----------

Processor SDK Linux AM62x Release has following new features:

- Support for GP, HS-FS, HS-SE with default Boot Experience on HS-FS
- Uboot: M4 Early boot, GPMC NAND (on SK LP)
- Kernel: Low Power Deep Sleep mode, CPUIdle on GP
- Kernel: RS485, mCRC, Dual Display
- IPC: A53 --> DM R5
- SA2UL with OPTEE TRNG
- TSN Network configuration support using netconf / YANG

Build Information
=================

U-Boot
------

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

Kernel
------

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
-----
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

Issues opened in previous releases that were closed in this release
--------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 100

   "LCPD-29860","CI/CD : Update Heading to AM62/64x Linux Processor SDK Stable Release","am62xx-sk,am64xx-evm"
   "LCPD-32777","Update LPM demo documentation","am62xx-sk,am62xx_sk-fs,am62xx_sk-se"
   "LCPD-32731","Default booting behavior of HS-FS devices should be explicitly documented","am62axx_sk-fs,am62xx-sk,am64xx-evm,am64xx-sk"
   "LCPD-29855","am62: Microtips OLDI Panels Distortion issue","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk"
   "LCPD-32331","Unavailability of unsigned images for ATF, OPTEE and A53 SPL","am62xx-lp-sk,am62xx_lp_sk-fs"
   "LCPD-29900","k3: allmod config fails to build due to ti sci kconfig ","am62xx-sk,am64xx-evm,am64xx-sk,j721e-idk-gw"
   "LCPD-32467","tidss: Incorrect pixel format definitions","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,j721e-idk-gw,j721s2-evm,j721s2-hsevm,j784s4-evm,j784s4-hsevm"
   "LCPD-29863","AM62x: OSPI boot mode fails","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs"
   
Issues found and closed in this release that may also be applicable to prior releases
-------------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-29850","Ethernet link up down crashes the system","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm"
   "LCPD-29388","PREEMPT_RT interrupt latency with background memory load","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk"
   "LCPD-29808","am62x: SK-lp fails to boot on HS platform","am62xx-lp-sk,am62xx_lp_sk-fs"
   "LCPD-29698","Am62x LP SK: Fix boot issues due to HS support","am62xx-lp-sk,am62xx_lp_sk-fs"
   "LCPD-29433","AM64/AM62: IRQBalance does not migrate IRQs ","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-sk"
   "LCPD-29806","AM62: Doc: Add boot mode switch settings","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se"
   "LCPD-29694","gpio-line-names is limited to 100. it should be ti,ngpios","am62axx_sk-fs,am62xx-sk,am64xx-sk,am654x-idk,dra71x-evm,dra7xx-evm,j784s4-evm"
   "LCPD-29621","MCAN user's guide is missing","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se"
   "LCPD-29528","k3: integration: sdk: missing tag info for optee and atf projects","am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk,am64xx-hssk,j721e-idk-gw,j721s2-evm,j721s2-hsevm,j7200-evm,j7200-hsevm,j784s4-evm"
   "LCPD-29308","AM62 LP SK OSPI NAND write fails in U-Boot","am62xx-lp-sk,am62xx_lp_sk-fs"
   "LCPD-28111","wic image flashed sdcard should resize to full image","am62xx-sk,am64xx-evm"
   "LCPD-27886","USART: Erroneous clear/trigger of timeout interrupt","am62axx_sk-fs,am62xx-sk,am64xx-evm,j721e-idk-gw,j7200-evm,j784s4-evm,j784s4-hsevm"
   "LCPD-25409","Doc: Support read of On-die temperature sensor in Linux","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-hsevm,am64xx-sk"
   "LCPD-29447","Docs Processor SDK Linux Software Developer’s Guide incorrect camera and LCD inteface","am62xx-sk,am62xx_sk-fs"
     
Errata Workarounds Available in this Release
--------------------------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 150

   "LCPD-27887","i2327: RTC: Hardware wakeup event limitation","am62xx-sk,am62xx_sk-fs"
   "LCPD-27886","USART: Erroneous clear/trigger of timeout interrupt","am62axx_sk-fs,am62xx-sk,am64xx-evm,j721e-idk-gw,j7200-evm,j784s4-evm,j784s4-hsevm"

|

U-Boot Known Issues
-------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-29300","U-Boot: OSPI-NOR: sf probe shows 0 randomly","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-28503","Need to sync up DTS files between u-boot and kernel for at least AM62x & AM64x, possibly other boards too","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk",""

|

Linux Kernel Known Issues
-------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35

   "LCPD-29589","AM62x CPSW: PPS example not enabled by default","am62axx_sk-fs,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-32480","Image authentication failure at A53 SPL in OSPI NOR boot mode","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29949","[PROD STOP]I2c operations at 100KHz is broken","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,j721e-idk-gw",""
   "LCPD-29446","Linux SDK docs should explicitly state what peripherals are supported","am335x-evm,am335x-ice,am335x-sk,am43xx-gpevm,am437x-idk,am437x-sk,am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk,am654x-evm,am654x-idk",""
   "LCPD-29441","am62x: kingston emmc fails on AM62x","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29339","Processor SDK 8.3 AM62x lacks RT Linux performance numbers","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29851","CI/CD Snapshot page doesn't have default images.","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29332","LPM Demo not Working on Linux RT","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29353","Automate Test: AM62x Linux to M4 IPC: simple shared memory example","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-28614","RPMsg client driver sample does not work with AM62x","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-24456","Move IPC validation source from github to git.ti.com","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am62axx_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am62xx-vlab,am62xx-zebu,am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j7ae-evm,j7ae-zebu,j7aep-zebu,j7am-evm,j7am-vlab,j7am-zebu,j7amp-vlab,j7amp-zebu,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721e-vlab,j721s2-evm,j721s2-hsevm,j7200-evm,j7200-hsevm,j7amp-evm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm,k2l-hsevm,omapl138-lcdk",""
   "LCPD-29815","AM62 - Pixel format tests","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-25662","Remove SGX PVR tools from KS3 devices","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,j721e-evm,j7200-evm",""
   "LCPD-32356","AM62x: tcrypt doesn't use sa2ul for SHA256/512 or any other alg","am62axx_sk-fs,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29588","CPSW documentation: Time Sync Router no longer firewalled","am62axx_sk-fs,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk,am654x-evm,am654x-idk",""
   "LCPD-29533","dropbear fails to start automatically","am335x-evm,am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-28672","CPSW: Add more details about driver config","am62axx_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk",""
   "LCPD-28415","AM62: emmc: Had to disable higherspeeds","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-28105","Automated test failure - CPSW failure doing runtime pm","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-28104","Automated test failure - CPSW test is passing invalid parameters to switch-config","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-25563","Test: AM62: Linux: Add support for MCAN","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-24690","Kernel: SDK: Set HIGH_SPEED_EN for MMC1 instance","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk,j721s2-evm,j7200-evm",""
   "LCPD-32728","AM62x, AM62a: Doc: Update HS FS Migration Guide","am62axx_sk-fs,am62axx_sk-se,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-32706","Display: DRM tests fail inconsistently","am62xx-sk,am62xx_sk-fs",""
   "LCPD-32353","SBL remote core images does not fit the partition table defined by LINUX for serial NAND ","am62axx_sk-fs,am62xx-lp-sk,am62xx_lp_sk-fs",""
   "LCPD-32351","MMCSD: HS200 and SDR104 Command Timeout Window Too Small","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","If the command requires a timeout longer than 700ms, then the MMC host controller command timeout can be disabled (MMCSD_CON[6] MIT=0x1) and a software implementation may be used in its place. Detailed steps as follows (in Linux):"
   "LCPD-29876","am62x: crypto RNG functional and performance tests failures","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29875","am62x: crypto SHA performance tests failures","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29874","am62x: robustness: fails to boot 100 reboot test consistently","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29792","am62x: mcspi not functional","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29654","AM62x: OSPI read Performance test fail ","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29489","M4F Core should be able to load data to OC_SRAM","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk",""
   "LCPD-29445","am62xx-sk: MCAN loop-back test is failing","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29442","Docs: AM62x-SK: Kernel User Guide uses tisdk_am64xx defconfigs","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29409","DMIPS number should reflect all 4 cores","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-28764","AM62x: Cannot resume from low power mode","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-28742","AM62x: Make "Debugging SPL" doc specific to AM62x","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-28688","AM62x Kernel User Guide: Document AM62x default kernel config","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-28514","AM62x: MMC Card detect does not work","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-28491","WiLink not functional with fw_devlink option set to `on` ","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-28448","Wall time does not account for sleep time","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-28414","AM62x EVM Devicetree should disable unused MCU peripherals","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-28156","Mcasp: Buffer underflow warnings","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-25410","Test: Support read of On-die temperature sensor in Linux","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk",""
   "LCPD-22715","i2232: DDR: Controller postpones more than allowed refreshes after frequency change","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,j721e-idk-gw,j721s2-evm,j7200-evm","Disable dynamic frequency change by programing DFS_ENABLE"
   "LCPD-32344","AM62: McASP recording causes CPU freezes","am62axx_sk-fs,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-25652","am62: sk: reset-gpio property for sil9022a","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29879","AM62x: MMC Modular NEG RMMOD when mount test fail","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29873"," AM62x: host does not detect USB gadget","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29871","AM62xx-lp-sk: UHS104 card FAT write results are out of expected range","am62xx-lp-sk,am62xx_lp_sk-fs",""
   "LCPD-29864","AM62x: USB DFU test fails","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29862","AM62x: Uboot qspi read write performance tests fail","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29943","AM64x: Upstream: Add boot mode switch settings","am62axx_sk-fs,am62axx_sk-se,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29933","Linux SDK docs: GPIO Guide feels insufficient","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29649","inta_ack results in NULL pointer exception","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""

|

Linux RT Kernel Known Issues
----------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35

   "LCPD-29339","Processor SDK 8.3 AM62x lacks RT Linux performance numbers","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29332","LPM Demo not Working on Linux RT","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
|
