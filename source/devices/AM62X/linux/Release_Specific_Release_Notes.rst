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


Release 08.05.00
================

Released on December 2022

What's new
----------

Processor SDK Linux AM62x Release has following new features:

- TPS65219 PMIC driver enablement
- GPMC NAND Flash support
- DDR at 1600MT/s Peak rate
- CPSW TCP Performance measure

Build Information
=================

U-Boot
------

.. rubric:: u-boot
   :name: u-boot

| Head Commit: 3983bffabc137c885ab557ac3d1923e29d252fac mach-k3: am62a7_init: Avoid HSM SRAM access from A53 SPL/U-Boot
| Date: Thu Dec 8 22:38:07 CST 2022
| uBoot Version: 2021.01
| uBoot Description: 08.05.00.007
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2021.01
| uBoot Tag: 08.05.00.007

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

Kernel
------

.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 3eee621d164a02048ba26ca1342cba9c8d913d46 Merged TI feature connectivity into ti-linux-5.10.y-cicd
| Date: Thu Dec 8 22:59:10 CST 2022
| Kernel Version: 5.10.153
| Kernel Description: 08.05.00.007

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.10.y
| Tag: 08.05.00.007
| Kernel defconfig: ti_sdk_arm64_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 29dbc132ebfcdca4022663d80dbc6e7162c53ce5 Merge branch 'ti-rt-linux-5.10.y-cicd' into ti-rt-linux-5.10.y
| Date: Thu Dec 8 23:10:45 CST 2022
| Kernel Version: 5.10.153-rt76
| Kernel Description: 08.05.00.007-rt

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.10.y
| Tag: 08.05.00.007-rt
| Kernel defconfig: ti_sdk_arm64_rt_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

Yocto
-----
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 6763a269b0398aa70ddfa9bece73e17a92849a9e linux-ti-staging-rt: RC Auto-Merger: 08.05.00.007
| Date: 2022-12-02
| Clone: git://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: 08.05.00.007
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: dc749e9898eb1594c1289406e908ca62b3b7b077 ltp-ddt: CI/CD Auto-Merger: cicd.2022.12.02.14:23:50
| Date: 2022-12-02
| Version: 2021.09

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: dunfell
| Release Tag: 08.05.00.007
|

Issues Tracker
==============

Issues opened in previous releases that were closed in this release
--------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 100

   "LCPD-28416","Stop using git:// in meta-ti , meta-arago","am62xx-sk"
   "LCPD-28774","plsdk-doc: PCIe doc content is incomplete for AM64x","am64xx-evm"
   "LCPD-25613","Am64x-evm: DP83869 TX /RX delay values are wrong ( affects CPSW PORT2 / ICSSG PORT1/2)","am64xx-evm,am64xx-hsevm"
   "LCPD-28745","am62x: mmc: fix autosuspend delay for runtime_pm","am62xx-sk"
   "LCPD-28131","am62x: wlan interface up - down - up results in kernel crash","am62xx-sk"
   "LCPD-28110","uboot and linux cannot boot in UHS speed modes on certain U1 class SD-cards -1","am62xx-sk"
   "LCPD-26721","AM62x: Cannot resume with more than one A53 enabled ","am62xx-sk"
   "LCPD-25503","ATF/A53 does not come out of WFI if TIFS/DM signals a suspend abort","am62xx-sk"
   "LCPD-28435","devtool finish fails","am64xx-evm"
   "LCPD-25634","Update ADC SDK docs for AM64x","am64xx-evm,am64xx-hsevm,am64xx-sk"
   "LCPD-25633","Add AM64x to ADC Bindings Doc","am64xx-evm,am64xx-hsevm"
   "LCPD-28773","Incorrect macro definition for DST_TAG bit field in CSI-2 RX driver","am62xx-sk"
   "LCPD-28762","GLMark2 visual errors around fragmentation shader tests","am62xx-hsevm,am62xx-sk,j721e-evm,j721e-hsevm,j721s2-evm,j721s2-hsevm,j784s4-evm,j784s4-hsevm"
   "LCPD-28403","SDK: Crypto node cleanup across TI SOCs","am64xx-evm,am654x-evm,j721e-evm,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-28413","Clarify PRU Ethernet not supported features","am64xx-evm,am654x-evm"
   "LCPD-27828","AM62: Fix the USB MSC environment setting","am62xx-sk"
   "LCPD-24677","j721e-idk-gw PCI WIFI Tests Fail due to iperf issues(Impact 1)","am62xx-sk,j721e-idk-gw"
   "LCPD-24470","QSPI Uboot Perf Test Failing","am64xx-evm"
   "LCPD-29285","AM62x: U-Boot default defconfig does not generate unsigned image","am62xx-lp-sk,am62xx-sk"
   "LCPD-29284","Fix ti,sci-inta, ti,sci-intr and mmc dtbs_check","am62xx-sk,am64xx-evm,j721e-idk-gw,j721s2-evm"
   "LCPD-28826","linux - enable CONFIG_DEBUG_INFO","am62xx-sk"
   "LCPD-28664","am62x_evm_r5_ethboot_defconfig ""spl/u-boot-spl.bin exceeds file size limit” Build Failure","am62xx-sk"
   "LCPD-28307","Linux WDT SDK docs are missing","am64xx-evm"
   "LCPD-28035","camera overlay packaged as dtb instead of dtbo","am62xx-sk"
   "LCPD-26731","AM64x: OpenSSL benchmarks data is not seen","am64xx-evm,am64xx-hsevm"
   "LCPD-25264","BCDMA: Blockcopy Gets Corrupted if TR Read Responses Interleave with Source Data Fetch","am64xx-evm,am64xx-hsevm,am64xx-sk"
   "LCPD-21662","Doc: Linux watchdog support","am62xx-sk"
   "LCPD-25320","Docs: AM64x: IPC chapter should be under Foundational Components","am64xx-evm,am64xx-sk"
   "LCPD-29509","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: CAN tests fail:  kvaser tool connection fail",""
   
Issues found and closed in this release that may also be applicable to prior releases
-------------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-29807","am62x is unable to boot (missing rootfs)","am62xx-sk"
   "LCPD-29860","CI/CD : Update Heading to AM62/64x Linux Processor SDK Stable Release","am62xx-sk,am64xx-evm"
   "LCPD-29488","AM64x: IPC RPMSG Client: test case has Invalid argument","am64xx-evm,am64xx-hsevm,am64xx-sk"
   "LCPD-29438","DM memory map change has broken upstream linux","am62xx-sk"
   "LCPD-29511","AM64x: USBHOST Func Audio Loopback: No USB Audio Loopback Device found","am64xx-evm,am64xx-hsevm,am64xx-sk"
   "LCPD-29352","SDK: AM62x Linux to M4 IPC: simple shared memory example","am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk"
   "LCPD-29477","j721e-idk-gw PCI WIFI Tests Fail due to iperf issues(Impact 1)","am62xx-sk,j721e-idk-gw"
   "LCPD-29419","J721s2-evm: u-boot: CPSW2g: interface goes up and down sporadically","am62xx-sk,j721s2-evm"
   "LCPD-29534","kernels in arago-dunfell RT directory are not an RT-Kernels","am62xx-hsevm,am62xx-lp-sk,am62xx-sk,am64xx-sk,j721e-evm,j721e-hsevm,j721s2-evm,j721s2-hsevm,j7200-evm,j7200-hsevm,j784s4-evm,j784s4-hsevm"
  "LCPD-29528","k3: integration: sdk: missing tag info for optee and atf projects","am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk,am64xx-hssk,j721e-idk-gw,j721s2-evm,j721s2-hsevm,j7200-evm,j7200-hsevm,j784s4-evm"
   "LCPD-29527","AM64x: mcu_pmx node is missing in kernel device tree","am64xx-evm"
   "LCPD-29520","Inline ECC documentation is missing (AM64x has old K2 DDR ECC, AM62x has nothing)","am62xx-sk,am64xx-evm,am64xx-hsevm"
   "LCPD-29519","OSPI flash read corruption issue in DAC mode using cadence_qspi_apd_direct_read_execute","am62xx-sk"
   "LCPD-29504","AM64x: dfu-util failed to load u-boot","am64xx-evm,am64xx-hsevm,am64xx-sk"
   "LCPD-29495","AM64x: NAND test cases fail getting device node, mtd parition number, mtd part range","am64xx-evm,am64xx-hsevm,am64xx-sk"
   "LCPD-29458","AM64x: Remove SRAM references from Benchmark demo GUI","am64xx-evm"
   "LCPD-29733","Debugging code left in OV5640 DTS overlay file","am62xx-sk"
   "LCPD-29447","Docs Processor SDK Linux Software Developer’s Guide incorrect camera and LCD inteface","am62xx-hsevm,am62xx-sk"
   "LCPD-29718","Doc: Combine AM62x and AM64x GP and HS defconfigs","am62xx-hsevm,am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk,am64xx-hssk"
   "LCPD-29516","AM64x: NAND Modular test cases fail finding mtd part range","am64xx-evm,am64xx-hsevm,am64xx-sk"

Errata Workarounds Available in this Release
--------------------------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 150

   "LCPD-27887","am62xx-hsevm,am62xx-sk","i2327: RTC: Hardware wakeup event limitation"
   "LCPD-25264","am64xx-evm,am64xx-hsevm,am64xx-sk","BCDMA: Blockcopy Gets Corrupted if TR Read Responses Interleave with Source Data Fetch"

|

U-Boot Known Issues
-------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-25540","am64xx-hsevm,am64xx-sk","u-boot: usb host boot failed on AM64x SK",""
   "LCPD-29402","am64xx-evm,j7200-evm","tftp download in U-Boot fails on am64xx-evm1@eptf124 ",""
   "LCPD-29739","am64xx-hsevm","AM64: NAND device not detected in U-boot",""
   "LCPD-25558","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: 'nand' tool doesn't seem to be working",""
   "LCPD-23026","am64xx-evm,am64xx-sk","USB MSC Boot: USB controller not visible from u-boot",""
   "LCPD-23020","am64xx-evm","am64xx-evm: U-Boot PHY autonegotiation failed 2 out of 100 times",""
   "LCPD-29300","am62xx-sk","U-Boot: OSPI-NOR: sf probe shows 0 randomly",""
   "LCPD-28660","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: tiboot3.bin generated by U-Boot build is confusing users",""
   "LCPD-28503","am62xx-sk,am64xx-evm,am64xx-sk","Need to sync up DTS files between u-boot and kernel for at least AM62x, possibly other boards too",""

|

Linux Kernel Known Issues
-------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35

   "LCPD-29850","am62xx-sk,am64xx-evm","Ethernet link up down crashes the system",""
   "LCPD-29640","am62xx-sk","AM62x : Reboot halts due to irqbalance daemon",""
   "LCPD-28142","am62xx-sk,j784s4-evm","Automated performance testing - spec2k6 benchmark test broken",""
   "LCPD-29851","am62xx-sk","CI/CD Snapshot page doesn't have default images.",""
   "LCPD-29388","am62xx-sk,am64xx-evm,am64xx-sk","PREEMPT_RT interrupt latency with background memory load",""
   "LCPD-29306","am64xx-evm,am654x-idk","PRU_ICSSG: How much SRAM is needed?",""
   "LCPD-29515","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: Cannot boot with USB-MSC",""
   "LCPD-29514","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: Cannot boot with NAND",""
   "LCPD-29446","am335x-evm,am335x-ice,am335x-sk,am43xx-gpevm,am437x-idk,am437x-sk,am62xx-sk,am64xx-evm,am64xx-sk,am654x-evm,am654x-idk","Linux SDK docs should explicitly state what peripherals are supported",""
   "LCPD-29441","am62xx-sk","am62x: kingston emmc fails on AM62x",""
   "LCPD-29433","am62xx-sk,am64xx-sk","AM64/AM62: IRQBalance does not migrate IRQs ",""
   "LCPD-29339","am62xx-sk","Processor SDK 8.3 AM62x lacks RT Linux performance numbers",""
   "LCPD-24448","am64xx-evm","Verify IPC kernel: main-r5f0(s)/main-r5f1(s)",""
   "LCPD-29855","am62xx-lp-sk,am62xx-sk","am62: Microtips OLDI Panels Distortion issue",""
   "LCPD-29510","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: USB Host tests fail: No USB Camera found",""
   "LCPD-28138","am62xx-sk","AM62x: RTC tests fail in automated testing",""
   "LCPD-28130","am62xx-hsevm,am62xx-sk","uboot's 'bootcmd_recovery' env setting is too long",""
   "LCPD-28099","am62xx-sk","System test - Linux ADD suport for can",""
   "LCPD-24648","am335x-evm,am572x-idk,am64xx-evm,dra71x-evm,j721e-evm,j7200-evm","Move dma-heaps-test and ion-tests to TI repositories",""
   "LCPD-21577","am64xx-evm","USBHOST_S_FUNC_SERIAL_0001 test passes even when the serial device is not enumerated",""
   "LCPD-20331","am64xx-evm,am64xx-sk,j7200-evm","Farm: j7200-evm/k3-am642-evm/k3-am642-sk DT blob has to be passed manually",""
   "LCPD-29651","am64xx-hsevm","AM64: NAND Flash device not detected",""
   "LCPD-25386","am62xx-sk","SD card not being properly detected on AM62x SK ",""
   "LCPD-20038","am64xx-evm","OPTEE test applications are missing from rootfs",""
   "LCPD-29332","am62xx-sk","LPM Demo not Working on Linux RT",""
   "LCPD-29353","am62xx-sk","Automate Test: AM62x Linux to M4 IPC: simple shared memory example",""
   "LCPD-28614","am62xx-sk","RPMsg client driver sample does not work with AM62x",""
   "LCPD-24823","am64xx-evm,am64xx-sk","Clarify Single-Core usage in ti,k3-r5f-rproc.yaml",""
   "LCPD-24456","am62xx-hsevm,am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm","Move IPC validation source from github to git.ti.com",""
   "LCPD-22931","am64xx-evm,am64xx-sk,am654x-evm,am654x-idk,dra72x-evm","RemoteProc documentation missing",""
   "LCPD-20006","am64xx-evm","AM64x: remoteproc may be stuck in the start phase after a few times of stop/start",""
   "LCPD-29815","am62xx-sk","AM62 - Pixel format tests",""
   "LCPD-25662","am62xx-sk,j721e-evm,j7200-evm","Remove SGX PVR tools from KS3 devices",""
   "LCPD-29500","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: ETH CPSW2g TAS: tests fail with undefined method error",""
   "LCPD-29499","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: ETH CPSW2g TAS: tests fail with queue 0 did not increase",""
   "LCPD-29498","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: ETH CPSW2g TAS: Invalid traffic schedule",""
   "LCPD-28672","am62axx-sk,am62xx-sk,am64xx-evm,am64xx-sk","CPSW: Add more details about driver config",""
   "LCPD-28415","am62xx-sk","AM62: emmc: Had to disable higherspeeds",""
   "LCPD-28105","am62xx-sk","Automated test failure - CPSW failure doing runtime pm",""
   "LCPD-28104","am62xx-sk","Automated test failure - CPSW test is passing invalid parameters to switch-config",""
   "LCPD-27924","am64xx-evm","AM65xx: Link does not come up after changing link settings while the interface is up with both endpoints on same board",""
   "LCPD-27871","am64xx-evm","GPMC NAND driver misleading error",""
   "LCPD-25563","am62xx-sk","Test: AM62: Linux: Add support for MCAN",""
   "LCPD-25494","am64xx-evm","AM64 EVM TSN IET tests is failing",""
   "LCPD-25112","am64xx-evm,j721e-idk-gw","Ethernet driver not gating its clock when interface is down",""
   "LCPD-24690","am62xx-sk,am64xx-evm,am64xx-sk,j721s2-evm,j7200-evm","Kernel: SDK: Set HIGH_SPEED_EN for MMC1 instance",""
   "LCPD-24595","am64xx-evm,am64xx-sk,j721e-idk-gw,j721e-sk,j7200-evm","j721e-idk-gw USB Suspend/Resume with RTC Wakeup fail (Impact 1)",""
   "LCPD-24593","am64xx-evm","am64xx-evm CAN_S_FUNC_MODULAR test failures",""
   "LCPD-24537","am64xx-evm,am64xx-hsevm,am654x-evm","am654x-idk nslookup times out when all netwokring interfaces are active",""
   "LCPD-24288","am64xx-evm,am654x-idk","am64xx-evm NCM/ACM network performance test crashes with RT images",""
   "LCPD-22892","am64xx-evm,am654x-evm,am654x-idk","icssg: due to FW bug both interfaces has to be loaded always",""
   "LCPD-20105","am64xx-evm","AM64x: Kernel: ADC: RX DMA channel request fails",""
   "LCPD-20061","am64xx-evm","Occasional PHY error during during TSN Time-Aware Shaper execution",""
   "LCPD-29792","am62xx-sk","am62x: mcspi not functional",""
   "LCPD-29654","am62xx-sk","AM62x: OSPI read Performance test fail ",""
   "LCPD-29646","am62xx-sk,j721e-idk-gw","Failure logs during boot:  Failed to get MSI domain",""
   "LCPD-29621","am62xx-lp-sk,am62xx-sk","MCAN user's guide is missing",""
   "LCPD-29597","am64xx-evm","AM64x: dts: main_rti nodes are defined twice",""
   "LCPD-29518","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: Dhrystone performance test fail",""
   "LCPD-29508","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: EMMC speed test fails: MMC not running on HS400 mode",""
   "LCPD-29489","am62xx-lp-sk,am62xx-sk,am64xx-evm,am64xx-sk","M4F Core should be able to load data to OC_SRAM",""
   "LCPD-29480","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: PCIe tests fail to start EP controller",""
   "LCPD-29445","am62xx-sk","am62xx-sk: MCAN loop-back test is failing",""
   "LCPD-29442","am62xx-sk","Docs: AM62x-SK: Kernel User Guide uses tisdk_am64xx defconfigs",""
   "LCPD-29409","am62xx-sk","DMIPS number should reflect all 4 cores",""
   "LCPD-29362","am64xx-evm,am64xx-sk","AM64x EVM Devicetree should disable unused MCU peripherals",""
   "LCPD-29305","am64xx-evm,am64xx-sk","AM64x Uboot SRAM addresses are outdated",""
   "LCPD-28764","am62xx-sk","AM62x: Cannot resume from low power mode",""
   "LCPD-28742","am62xx-sk","AM62x: Make ""Debugging SPL"" doc specific to AM62x",""
   "LCPD-28688","am62xx-sk","AM62x Kernel User Guide: Document AM62x default kernel config",""
   "LCPD-28514","am62xx-sk","AM62x: MMC Card detect does not work",""
   "LCPD-28491","am62xx-sk","WiLink not functional with fw_devlink option set to `on` ",""
   "LCPD-28448","am62xx-sk","Wall time does not account for sleep time",""
   "LCPD-28414","am62xx-sk","AM62x EVM Devicetree should disable unused MCU peripherals",""
   "LCPD-28156","am62xx-sk","Mcasp: Buffer underflow warnings",""
   "LCPD-28111","am62xx-sk,am64xx-evm","wic image flashed sdcard should resize to full image",""
   "LCPD-25410","am62xx-lp-sk,am62xx-sk,am64xx-evm,am64xx-sk","Test: Support read of On-die temperature sensor in Linux",""
   "LCPD-25409","am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk","Doc: Support read of On-die temperature sensor in Linux",""
   "LCPD-22912","am64xx-evm","am64xx-evm SMP dual core test fails sporadically",""
   "LCPD-22834","am64xx-evm","am64xx-evm stress boot test fails",""
   "LCPD-22715","am62xx-sk,j721e-idk-gw,j721s2-evm,j7200-evm","i2232: DDR: Controller postpones more than allowed refreshes after frequency change",""
   "LCPD-22319","am64xx-evm,j7200-evm","OpenSSL performance test data out of bounds",""
   "LCPD-29530","am62xx-sk","HDMI with Audio playback failure",""
   "LCPD-25652","am62xx-sk","am62: sk: reset-gpio property for sil9022a",""
   "LCPD-29861","am64xx-evm,am64xx-hsevm,am64xx-sk,am64xx-hssk","AM64x: IPC tests fail",""
   "LCPD-28139","am62xx-hsevm,am62xx-sk","AM62x: performance benchmarks degradation between RC4 and RC5 releases",""
   "LCPD-25663","am62xx-sk,j721e-evm,j721s2-evm,j784s4-evm","Remove old IMG demo binaries  ",""
   "LCPD-29580","am64xx-evm,am654x-evm,am654x-idk","ICSSG IET Statistics are not getting counted",""
   "LCPD-29341","am64xx-evm","AM64x EVM: Clarify CPSW / PRU Ethernet selection steps",""
   "LCPD-29649","am62xx-sk","inta_ack results in NULL pointer exception",""
   "LCPD-18854","am64xx-evm,dra71x-evm,dra76x-evm","ov5640 sensor capture fails for raw format capture",""
   "LCPD-28149","am62xx-sk","CMA warning while running GPU tests",""
   "LCPD-26692","am335x-evm,am43xx-gpevm,am57xx-evm,am64xx-evm,j721e-idk-gw","Hardware + Software IPSec Performance Test Failures",""
   "LCPD-29854","am64xx-evm,am64xx-hsevm,am64xx-sk,am64xx-hssk","MCU UART TX baud rate is doubled",""
   "LCPD-29734","am64xx-evm","AM64x PRUETH Performance Guide numbers are wrong",""
   "LCPD-29589","am62axx-sk,am62xx-lp-sk,am62xx-sk","AM62x CPSW: PPS example not enabled by default",""
   "LCPD-29588","am62axx-sk,am62xx-lp-sk,am62xx-sk,am64xx-evm,am64xx-sk,am654x-evm,am654x-idk","CPSW documentation: Time Sync Router no longer firewalled",""
   "LCPD-29533","am335x-evm,am62xx-sk","dropbear fails to start automatically",""
   "LCPD-29517","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: UDP test fail: failed T_cpu_util out of expected range",""
   "LCPD-22215","am64xx-evm","PCIE NVM card stops enumerating on am64xx after some time",""
   "LCPD-20705","am64xx-evm","USB stick attached to PCIe USB card is not enumerated",""
   "LCPD-29877","am62xx-sk","am62x: openssl crypto performance tests fail",""
   "LCPD-29876","am62xx-sk","am62x: crypto RNG functional and performance tests failures",""
   "LCPD-29875","am62xx-sk","am62x: crypto SHA performance tests failures",""
   "LCPD-29874","am62xx-sk","am62x: robustness: fails to boot 100 reboot test consistently",""

|

Linux RT Kernel Known Issues
----------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35

   "LCPD-29388","am62xx-sk,am64xx-evm,am64xx-sk","PREEMPT_RT interrupt latency with background memory load",""
   "LCPD-29339","am62xx-sk","Processor SDK 8.3 AM62x lacks RT Linux performance numbers",""
   "LCPD-29332","am62xx-sk","LPM Demo not Working on Linux RT",""
   "LCPD-24288","am64xx-evm,am654x-idk","am64xx-evm NCM/ACM network performance test crashes with RT images",""
|
