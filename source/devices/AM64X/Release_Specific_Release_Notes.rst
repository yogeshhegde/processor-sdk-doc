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


Release 08.06.00
================

Released on February 2023

What's new
----------
Processor SDK Linux AM64x Release has following new features:

- Kernel: RS485, RT Stress-ng validation
- Bug Fixes and Stability Improvements
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
| Tag:  08.06.00.007
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
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 100, 50

   "LCPD-29860","CI/CD : Update Heading to AM62/64x Linux Processor SDK Stable Release","am64xx-evm"
   "LCPD-32731","Default booting behavior of HS-FS devices should be explicitly documented","am64xx-evm,am64xx-sk"
   "LCPD-32773","Rx stall seen when there is network traffic during startup","am64xx-evm"
   "LCPD-29900","k3: allmod config fails to build due to ti sci kconfig ","am64xx-evm,am64xx-sk"

Issues found and closed in this release that may also be applicable to prior releases
-------------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 100, 50
    
   "LCPD-29850","Ethernet link up down crashes the system","am64xx-evm"
   "LCPD-29388","PREEMPT_RT interrupt latency with background memory load","am64xx-evm,am64xx-sk"
   "LCPD-29734","AM64x PRUETH Performance Guide numbers are wrong","am64xx-evm"
   "LCPD-29306","PRU_ICSSG: How much SRAM is needed?","am64xx-evm"
   "LCPD-29433","AM64/AM62: IRQBalance does not migrate IRQs ","am64xx-sk"
   "LCPD-29517","AM64x: UDP test fail: failed T_cpu_util out of expected range","am64xx-evm,am64xx-hsevm,am64xx-sk"
   "LCPD-25636","main uart0 pinmux not defined in k3-am642-sk.dts","am64xx-sk"
   "LCPD-25112","Ethernet driver not gating its clock when interface is down","am64xx-evm"
   "LCPD-20061","Occasional PHY error during during TSN Time-Aware Shaper execution","am64xx-evm"
   "LCPD-29694","gpio-line-names is limited to 100. it should be ti,ngpios","am64xx-sk"
   "LCPD-29528","k3: integration: sdk: missing tag info for optee and atf projects","am64xx-evm,am64xx-hsevm,am64xx-sk,am64xx-hssk"
   "LCPD-29518","AM64x: Dhrystone performance test fail","am64xx-evm,am64xx-hsevm,am64xx-sk"
   "LCPD-28111","wic image flashed sdcard should resize to full image","am64xx-evm"
   "LCPD-27886","USART: Erroneous clear/trigger of timeout interrupt","am64xx-evm"
   "LCPD-25409","Doc: Support read of On-die temperature sensor in Linux","am64xx-evm,am64xx-hsevm,am64xx-sk"
   "LCPD-29341","AM64x EVM: Clarify CPSW / PRU Ethernet selection steps","am64xx-evm"

Errata Workarounds Available in this Release
--------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 100, 50

   "LCPD-19965","OSPI PHY Controller Bug Affecting Read Transactions","am64xx-evm"
   "LCPD-27886","USART: Erroneous clear/trigger of timeout interrupt","am64xx-evm"

|

U-Boot Known Issues
-------------------
.. csv-table::
   :header: "Record ID","Title", "Platform","Workaround"
   :widths: 20, 100, 50, 5
    
   "LCPD-25540","u-boot: usb host boot failed on AM64x SK","am64xx-hsevm,am64xx-sk",""
   "LCPD-29739","AM64: NAND device not detected in U-boot","am64xx-hsevm",""
   "LCPD-25558","AM64x: 'nand' tool doesn't seem to be working","am64xx-evm,am64xx-hsevm,am64xx-sk",""
   "LCPD-24726","Uboot qspi read write performance test  failed ","am64xx-sk",""
   "LCPD-23020","am64xx-evm: U-Boot PHY autonegotiation failed 2 out of 100 times","am64xx-evm",""
   "LCPD-28660","AM64x: tiboot3.bin generated by U-Boot build is confusing users","am64xx-evm,am64xx-hsevm,am64xx-sk",""
   "LCPD-28503","Need to sync up DTS files between u-boot and kernel for at least AM62x & AM64x, possibly other boards too","am64xx-evm,am64xx-sk",""

|

Linux Kernel Known Issues
-------------------------

.. csv-table::
   :header: "Record ID", "Title", "Platform", "Workaround"
   :widths: 20, 100, 50, 5

   "LCPD-23102","AM64-SK: DMA is not stable","am64xx-sk",""
   "LCPD-20558","OSPI UBIFS tests failing on am64xx-sk","am64xx-sk",""
   "LCPD-29515","AM64x: Cannot boot with USB-MSC","am64xx-evm,am64xx-hsevm,am64xx-sk",""
   "LCPD-29446","Linux SDK docs should explicitly state what peripherals are supported","am64xx-evm,am64xx-sk",""
   "LCPD-24448","Verify IPC kernel: main-r5f0(s)/main-r5f1(s)","am64xx-evm",""
   "LCPD-32481","AM64x: Environment variables for DFU to NAND","am64xx-evm,am64xx-hsevm",""
   "LCPD-29651","AM64: NAND Flash device not detected","am64xx-hsevm",""
   "LCPD-20038","OPTEE test applications are missing from rootfs","am64xx-evm",""
   "LCPD-24456","Move IPC validation source from github to git.ti.com","am64xx-evm,am64xx-hsevm,am64xx-sk",""
   "LCPD-22931","RemoteProc documentation missing","am64xx-evm,am64xx-sk",""
   "LCPD-20006","AM64x: remoteproc may be stuck in the start phase after a few times of stop/start","am64xx-evm",""
   "LCPD-26692","Hardware + Software IPSec Performance Test Failures","am64xx-evm",""
   "LCPD-32640","Kernel HSR does not work on base image (same command works on default)","am64xx-evm",""
   "LCPD-29854","MCU UART TX baud rate is doubled","am64xx-evm,am64xx-hsevm,am64xx-sk,am64xx-hssk",""
   "LCPD-29588","CPSW documentation: Time Sync Router no longer firewalled","am64xx-evm,am64xx-sk",""
   "LCPD-29500","AM64x: ETH CPSW2g TAS: tests fail with undefined method error","am64xx-evm,am64xx-hsevm,am64xx-sk",""
   "LCPD-29499","AM64x: ETH CPSW2g TAS: tests fail with queue 0 did not increase","am64xx-evm,am64xx-hsevm,am64xx-sk",""
   "LCPD-29498","AM64x: ETH CPSW2g TAS: Invalid traffic schedule","am64xx-evm,am64xx-hsevm,am64xx-sk",""
   "LCPD-28672","CPSW: Add more details about driver config","am64xx-evm,am64xx-sk",""
   "LCPD-27924","AM65xx: Link does not come up after changing link settings while the interface is up with both endpoints on same board","am64xx-evm",""
   "LCPD-27871","GPMC NAND driver misleading error","am64xx-evm",""
   "LCPD-25494","AM64 EVM TSN IET tests is failing","am64xx-evm",""
   "LCPD-24872","Am64x-sk :LCPD-16811 CPSW  failed while throughput metrics comparison ","am64xx-sk",""
   "LCPD-24696","CPSW Promiscuous mode test failing on am64xx-sk","am64xx-sk",""
   "LCPD-24690","Kernel: SDK: Set HIGH_SPEED_EN for MMC1 instance","am64xx-evm,am64xx-sk",""
   "LCPD-24537","am654x-idk nslookup times out when all netwokring interfaces are active","am64xx-evm,am64xx-hsevm",""
   "LCPD-24288","am64xx-evm NCM/ACM network performance test crashes with RT images","am64xx-evm",""
   "LCPD-23066","am64x-sk :gpio: direction test fail","am64xx-sk",""
   "LCPD-22892","icssg: due to FW bug both interfaces has to be loaded always","am64xx-evm",""
   "LCPD-20105","AM64x: Kernel: ADC: RX DMA channel request fails","am64xx-evm",""
   "LCPD-29597","AM64x: dts: main_rti nodes are defined twice","am64xx-evm",""
   "LCPD-29508","AM64x: EMMC speed test fails: MMC not running on HS400 mode","am64xx-evm,am64xx-hsevm,am64xx-sk",""
   "LCPD-29489","M4F Core should be able to load data to OC_SRAM","am64xx-evm,am64xx-sk",""
   "LCPD-29362","AM64x EVM Devicetree should disable unused MCU peripherals","am64xx-evm,am64xx-sk",""
   "LCPD-29305","AM64x Uboot SRAM addresses are outdated","am64xx-evm,am64xx-sk",""
   "LCPD-25410","Test: Support read of On-die temperature sensor in Linux","am64xx-evm,am64xx-sk",""
   "LCPD-24467","am64xx-sk stress boot test fails","am64xx-sk",""
   "LCPD-22912","am64xx-evm SMP dual core test fails sporadically","am64xx-evm",""
   "LCPD-22834","am64xx-evm stress boot test fails","am64xx-evm",""
   "LCPD-29861","AM64x: IPC tests fail","am64xx-evm,am64xx-hsevm,am64xx-sk,am64xx-hssk",""
   "LCPD-29580","ICSSG IET Statistics are not getting counted","am64xx-evm",""
   "LCPD-29943","AM64x: Upstream: Add boot mode switch settings","am62axx_sk-fs,am62axx_sk-se,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
   "LCPD-29880","CAN_S_FUNC_MODULAR test fail","am64xx-evm",""
   "LCPD-29805","AM64: Doc: Add boot mode switch settings","am64xx-evm,am64xx-hsevm,am64xx-sk,am64xx-hssk",""
   "LCPD-18854","ov5640 sensor capture fails for raw format capture","am64xx-evm",""
   "LCPD-22215","PCIE NVM card stops enumerating on am64xx after some time","am64xx-evm",""
   "LCPD-20705","USB stick attached to PCIe USB card is not enumerated","am64xx-evm",""

|

Linux RT Kernel Known Issues
----------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform", "Workaround"
   :widths: 20, 100, 50, 5

   "LCPD-24288","am64xx-evm NCM/ACM network performance test crashes with RT images","am64xx-evm",""
|
