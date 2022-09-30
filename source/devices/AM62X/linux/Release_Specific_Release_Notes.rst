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


Licensing
=========

Please refer to the software manifests, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page or in the installed directory as indicated below.

-  Linux Manifest:  "/docs/software_manifest.html"


Release 08.04.01
================

Released on September 2022

What's new
----------
Processor SDK Linux AM62x Release has following new features:

- 1.4 Ghz Support and DFS (Dynaminc Frequency Scaling)
- DDR ECC Single bit mode
- IPC: A53 - DM R5
- VTM, WDT
- AM62x LP Starter Kit Initial Platform Support
- OSPI SPI NAND Support


Build Information
=====================================

U-Boot
-------------------------

.. rubric:: u-boot
   :name: u-boot

| Head Commit: 2dd2e1d366acf7f41bbd8f2d1dbe6cf5e1bcbad6 dma: ti: k3-udma: Fix 'SZ_64K' undeclared error
| Date: Wed Sep 28 16:41:34 CDT 2022
| uBoot Version: 2021.01
| uBoot Description: 08.04.01.005
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2021.01
| uBoot Tag: 08.04.01.005

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

Kernel
-------------------------

.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 5e63ae91b2138efad3db617a0ecb5ff76c591131 Merged TI feature connectivity into ti-linux-5.10.y-cicd
| Date: 23 Sep 2022 09:11 AM
| Kernel Version: 5.10.140
| Kernel Description: 08.04.01.005

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.10.y
| Tag: 08.04.01.005
| Kernel defconfig: ti_sdk_arm64_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 3a997318d8caa8caa100ecc69472e528ecfc2ebb Merge branch 'ti-rt-linux-5.10.y-cicd' into ti-rt-linux-5.10.y
| Date: 24 Sep 2022 01:23 PM
| RT Kernel Version: 5.10.140-rt
| Kernel Description: 08.04.01.005-rt

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.10.y
| Tag: 08.04.01.005-rt
| Kernel defconfig: ti_sdk_arm64_rt_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

Yocto
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: e84c0aeaa84afe9784f8b1dbe31377b5f4283a49 linux-ti-staging-rt: RC Auto-Merger: 08.04.01.005
| Date: 2022-09-24
| Version: dunfell-3.1
| Clone: git://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: 08.04.01.005
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: 4061de845fc950ddaa983ba3bdfed60a7e602e92 ltp-ddt: CI/CD Auto-Merger: cicd.2022.09.16.17:39:59
| Date: 2022-09-16
| Version: 2021.09

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: dunfell
| Release Tag: 08.04.01.005
|

Issues Tracker
=====================================

Issues opened in previous releases that were closed in this release
--------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 100

   "LCPD-25536","DM should be relocated on AM62 to be inline with TF-A and OPTEE locations","am62xx-sk"
   "LCPD-25503","ATF/A53 does not come out of WFI if TIFS/DM signals a suspend abort","am62xx-sk"
   "LCPD-25492","Occasionally Matrix-Gui does not auto launch","am62xx-sk,j721e-idk-gw,j721s2-evm"
   "LCPD-25293","CSI-2 driver not probing IMX219 image sensor","am62xx-sk"
   "LCPD-25252","Docs: OPTEE SDK documentation is very minimal ","am62xx-hsevm,am62xx-sk,am64xx-evm,am64xx-hsevm"
   

Issues found and closed in this release that may also be applicable to prior releases
-------------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-29284","Fix ti,sci-inta, ti,sci-intr and mmc dtbs_check","am62xx-sk,am64xx-evm,j721e-idk-gw,j721s2-evm"
   "LCPD-28921","AM62Q: validated samples crash on bootup","am62xx-lp-sk"
   "LCPD-28867","am62x: ti_sci: fix polled mode during suspend/resume","am62xx-sk"
   "LCPD-28740","AM62x SK: R5 SPL - default boot frequency should be 1.25 GHz","am62xx-sk"
   "LCPD-28664","am62x_evm_r5_ethboot_defconfig ""spl/u-boot-spl.bin exceeds file size limit” Build Failure","am62xx-sk"
   "LCPD-28658","doc: build instructions for ATF are unclear and might be incorrect","am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk"
   "LCPD-28449","Reboot does not work after suspend to ram","am62xx-sk"
   "LCPD-28442","am62x : Incorrect register size used for pktdma and bcdma nodes in device tree","am62xx-sk"
   "LCPD-28419","Linux: All: AM65 CPSW driver fails to build w/o PHYLINK=y","am62xx-sk,j721e-idk-gw"
   "LCPD-28416","Stop using git:// in meta-ti , meta-arago","am62xx-sk"
   "LCPD-28331","OSPI layout offsets need to be updated in SDK 8.3 u-boot user guide","am62xx-sk"
   "LCPD-28327","u-boot ddr dtsi has a register double entries leading to data corruption","am62xx-hsevm,am62xx-sk"
   "LCPD-28325","kernel crashes if CONFIG_DEBUG_FS is not set","am62xx-hsevm,am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm,j7am-evm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721s2-evm,j721s2-hsevm,j7200-evm,j7200-hsevm"
   "LCPD-28178","wic images for K3 HS images are broken","am62xx-hsevm,am64xx-hsevm,am654x-hsevm,j721e-hsevm,j721s2-hsevm,j7200-hsevm"
   "LCPD-28131","am62x: wlan interface up - down - up results in kernel crash","am62xx-sk"
   "LCPD-28103","Automated test failure - CPSW test fails to find an active interface implemented by CPSW","am62xx-sk"
   "LCPD-28101","EMMC boot fails","am62xx-sk"
   "LCPD-28037","LPM firmware load fails during suspend with MMC enabled ","am62xx-sk"
   "LCPD-28036","AM62x: U-Boot: xSPI boot is broken","am62xx-sk"
   "LCPD-28035","camera overlay packaged as dtb instead of dtbo","am62xx-sk"
   "LCPD-27894","AM62: Fix the size check configs in R5 SPL","am62xx-sk"
   "LCPD-27891","ti_sdk_arm64_release_defconfig: Warnings","am62xx-sk"
   "LCPD-27887","i2327: RTC: Hardware wakeup event limitation","am62xx-hsevm,am62xx-sk"
   "LCPD-27815","uboot cannot warm reset the am62","am62xx-sk"
   "LCPD-26721","AM62x: Cannot resume with more than one A53 enabled ","am62xx-sk"
   "LCPD-26641","K3: Move stack initialization address in arm64","am62xx-sk,am64xx-evm,am654x-evm,j721e-evm,j721s2-evm,j7200-evm"
   "LCPD-26597","AM62: Disable UHS speed modes in U-Boot","am62xx-sk"
   "LCPD-25665","am62 having trouble responding to voltage select","am62xx-sk"
   "LCPD-25580","AM62: Move BSS below DM config data","am62xx-sk"
   "LCPD-25569","AM64:  Timer issues","am62xx-sk,am64xx-evm,am64xx-sk"
   "LCPD-25567","AM62x; WKUP UART pinmux not setup","am62xx-sk"
   "LCPD-25565","am62: sk: i2c controller time out","am62xx-sk"
   "LCPD-25564","J721s2-evm: CPSW2g: interface goes up and down sporadically","am62xx-sk,j721s2-evm"

U-Boot Known Issues
-------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-29300","am62xx-sk","U-Boot: OSPI-NOR: sf probe shows 0 randomly",""
   "LCPD-29285","am62xx-lp-sk,am62xx-sk","AM62x: U-Boot default defconfig does not generate unsigned image",""
   "LCPD-28503","am62xx-sk,am64xx-evm,am64xx-sk","Need to sync up DTS files between u-boot and kernel for at least AM62x, possibly other boards too",""
   "LCPD-27828","am62xx-sk","AM62: Fix the USB MSC environment setting",""
   

Linux Kernel Known Issues
-------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35

   "LCPD-29353","am62xx-sk","Automate Test: AM62x Linux to M4 IPC: simple shared memory example",""
   "LCPD-29352","am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk","SDK: AM62x Linux to M4 IPC: simple shared memory example",""
   "LCPD-29344","am62xx-lp-sk","A53 SPL crashing while booting HSM using SBL OSPI NAND",""
   "LCPD-29339","am62xx-sk","Processor SDK 8.3 AM62x lacks RT Linux performance numbers",""
   "LCPD-28826","am62xx-sk","linux - enable CONFIG_DEBUG_INFO",""
   "LCPD-28764","am62xx-sk","AM62x: Cannot resume from low power mode",""
   "LCPD-28745","am62xx-sk","am62x: mmc: fix autosuspend delay for runtime_pm",""
   "LCPD-28742","am62xx-sk","AM62x: Make ""Debugging SPL"" doc specific to AM62x",""
   "LCPD-28688","am62xx-sk","AM62x Kernel User Guide: Document AM62x default kernel config",""
   "LCPD-28672","am62axx-sk,am62xx-sk,am64xx-evm,am64xx-sk","CPSW: Add more details about driver config",""
   "LCPD-28614","am62xx-sk","RPMsg client driver sample does not work with AM62x",""
   "LCPD-28514","am62xx-sk","AM62x: MMC Card detect does not work",""
   "LCPD-28491","am62xx-sk","WiLink not functional with fw_devlink option set to `on` ",""
   "LCPD-28448","am62xx-sk","Wall time does not account for sleep time",""
   "LCPD-28415","am62xx-sk","AM62: emmc: Had to disable higherspeeds",""
   "LCPD-28414","am62xx-sk","AM62x EVM Devicetree should disable unused MCU peripherals",""
   "LCPD-28156","am62xx-sk","Mcasp: Buffer underflow warnings",""
   "LCPD-28111","am62xx-sk,am64xx-evm","wic image flashed sdcard should resize to full image",""
   "LCPD-28110","am62xx-sk","uboot and linux cannot boot in UHS speed modes on certain U1 class SD-cards",""
   "LCPD-28105","am62xx-sk","Automated test failure - CPSW failure doing runtime pm",""
   "LCPD-28104","am62xx-sk","Automated test failure - CPSW test is passing invalid parameters to switch-config",""
   "LCPD-25652","am62xx-sk","am62: sk: reset-gpio property for sil9022a",""
   "LCPD-25563","am62xx-sk","Test: AM62: Linux: Add support for MCAN",""
   "LCPD-25410","am62xx-lp-sk,am62xx-sk,am64xx-evm,am64xx-sk","Test: Support read of On-die temperature sensor in Linux",""
   "LCPD-25409","am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk","Doc: Support read of On-die temperature sensor in Linux",""
   "LCPD-24690","am62xx-sk,am64xx-evm,am64xx-sk,j721s2-evm,j7200-evm","Kernel: SDK: Set HIGH_SPEED_EN for MMC1 instance",""
   "LCPD-24677","am62xx-sk,j721e-idk-gw","j721e-idk-gw PCI WIFI Tests Fail due to iperf issues(Impact 1)",""
   "LCPD-22715","am62xx-sk,j721e-idk-gw,j721s2-evm,j7200-evm","i2232: DDR: Controller postpones more than allowed refreshes after frequency change","Workaround 1:"
   "LCPD-21662","am62xx-sk","Doc: Linux watchdog support",""
     

Linux RT Kernel Known Issues
----------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35
   
   "LCPD-29339","am62xx-sk","Processor SDK 8.3 AM62x lacks RT Linux performance numbers",""
   "LCPD-29332","am62xx-sk","LPM Demo not Working on Linux RT",""	
