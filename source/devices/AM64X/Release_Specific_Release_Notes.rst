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


Release 08.04.01
================

Released on September 2022

What's new
----------
Processor SDK Linux AM64x Release has following new features:

- SR2.0 HS-FS (High Security - Field Securable) Support
- DDR ECC Single bit mode
- VTM

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

   "LCPD-25535","UBoot: customized ${optargs} doesn't take affect on K3 devices","am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm,j721e-evm,j721e-hsevm,j721s2-evm,j721s2-hsevm,j7200-evm,j7200-hsevm"
   "LCPD-25522","AM64: Ethernet broken at u-Boot prompt","am64xx-evm,am64xx-sk"
   "LCPD-25320","Docs: AM64x: IPC chapter should be under Foundational Components","am64xx-evm,am64xx-sk"
   "LCPD-25252","Docs: OPTEE SDK documentation is very minimal ","am62xx-hsevm,am62xx-sk,am64xx-evm,am64xx-hsevm"
   "LCPD-25074","AM64 HS Boot broken ","am64xx-hsevm"
   "LCPD-25070","am64xx-sk uboot build failed to boot due to ","am64xx-sk"
   "LCPD-24498","AM64x DDR configuration needs update for EVM and SK","am64xx-evm,am64xx-sk"
   "LCPD-24470","QSPI Uboot Perf Test Failing","am64xx-evm"
   "LCPD-22812","Upstream: reserved-memory.txt  convert to yaml","am64xx-hsevm,am64xx-sk,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j7200-evm,j7200-hsevm,k2g-evm,k2g-hsevm"
   "LCPD-20310","Upstream: Timeout behavior inconsistency seen in upstream R5 SPL","am64xx-evm,j721e-evm,j7200-evm"
   "LCPD-19858","OE: OPTEE label used in SDK is old and wrong","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am64xx-evm,am64xx-vlab,am64xx-zebu,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm,k2l-hsevm"
   "LCPD-24511","ARM: A72/53 L1 data cache and L2 cache set counts wrong","am64xx-evm,am64xx-hsevm,am64xx-sk,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm"
   "LCPD-24507","U-Boot command ""saveenv"" doesn't save env ","am64xx-evm,am64xx-hsevm,am64xx-sk,j721e-idk-gw" 	

Issues found and closed in this release that may also be applicable to prior releases
-------------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-29284","Fix ti,sci-inta, ti,sci-intr and mmc dtbs_check","am62xx-sk,am64xx-evm,j721e-idk-gw,j721s2-evm"
   "LCPD-28827","u-boot: add support for AM64B SK","am64xx-sk"
   "LCPD-28658","doc: build instructions for ATF are unclear and might be incorrect","am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk"
   "LCPD-28435","devtool finish fails","am64xx-evm"
   "LCPD-28413","Clarify PRU Ethernet not supported features","am64xx-evm,am654x-evm"
   "LCPD-28357","HSR/PRP Steps do not work","am64xx-evm"
   "LCPD-28325","kernel crashes if CONFIG_DEBUG_FS is not set","am62xx-hsevm,am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm,j7am-evm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721s2-evm,j721s2-hsevm,j7200-evm,j7200-hsevm"
   "LCPD-28179","Fix DFU Env variable for flashing combined bootloader images","am64xx-evm,j7200-evm"
   "LCPD-28178","wic images for K3 HS images are broken","am62xx-hsevm,am64xx-hsevm,am654x-hsevm,j721e-hsevm,j721s2-hsevm,j7200-hsevm"
   "LCPD-26641","K3: Move stack initialization address in arm64","am62xx-sk,am64xx-evm,am654x-evm,j721e-evm,j721s2-evm,j7200-evm"
   "LCPD-25765","AM64x U-boot is broken for mmc boot","am64xx-evm,am64xx-sk"
   "LCPD-25569","AM64:  Timer issues","am62xx-sk,am64xx-evm,am64xx-sk"
    
     	

U-Boot Known Issues
-------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-28660","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: tiboot3.bin generated by U-Boot build is confusing users",""
   "LCPD-28503","am62xx-sk,am64xx-evm,am64xx-sk","Need to sync up DTS files between u-boot and kernel for at least AM62x, possibly other boards too",""
   "LCPD-25558","am64xx-evm","the 'nand' tool doesn't seem to be working",""
   "LCPD-25540","am64xx-sk","u-boot: usb host boot failed on AM64x SK",""
   "LCPD-24726","am64xx-sk","Uboot qspi read write performance test  failed ",""
   "LCPD-23026","am64xx-evm,am64xx-sk","USB MSC Boot: USB controller not visible from u-boot",""
   "LCPD-23020","am64xx-evm","am64xx-evm: U-Boot PHY autonegotiation failed 2 out of 100 times","" 	    

Linux Kernel Known Issues
-------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35

   "LCPD-29341","am64xx-evm","AM64x EVM: Clarify CPSW / PRU Ethernet selection steps",""
   "LCPD-29306","am64xx-evm,am654x-idk","PRU_ICSSG: How much SRAM is needed?",""
   "LCPD-29305","am64xx-evm,am64xx-sk","AM64x Uboot SRAM addresses are outdated",""
   "LCPD-28774","am64xx-evm","plsdk-doc: PCIe doc content is incomplete for AM64x",""
   "LCPD-28757","am64xx-evm","NAND Extension board causes UBoot Failure on am64xx-evm",""
   "LCPD-28307","am64xx-evm","Linux WDT SDK docs are missing",""
   "LCPD-27871","am64xx-evm","GPMC NAND driver misleading error",""
   "LCPD-26731","am64xx-evm,am64xx-hsevm","OpenSSL benchmarks for AM64x are empty",""
   "LCPD-25764","am64xx-evm,am64xx-sk","Upstream: AM64x DDR configuration needs update for EVM and SK",""
   "LCPD-25636","am64xx-sk","main uart0 pinmux not defined in k3-am642-sk.dts",""
   "LCPD-25494","am64xx-evm","AM64 EVM TSN IET tests is failing",""
   "LCPD-25410","am62xx-lp-sk,am62xx-sk,am64xx-evm,am64xx-sk","Test: Support read of On-die temperature sensor in Linux",""
   "LCPD-25409","am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk","Doc: Support read of On-die temperature sensor in Linux",""
   "LCPD-25112","am64xx-evm,j721e-idk-gw","Ethernet driver not gating its clock when interface is down",""     
   "LCPD-24872","am64xx-sk","Am64x-sk :LCPD-16811 CPSW  failed while throughput metrics comparison ",""
   "LCPD-24823","am64xx-evm,am64xx-sk","Clarify Single-Core usage in ti,k3-r5f-rproc.yaml",""
   "LCPD-24696","am64xx-sk","CPSW Promiscuous mode test failing on am64xx-sk",""
   "LCPD-24690","am62xx-sk,am64xx-evm,am64xx-sk,j721s2-evm,j7200-evm","Kernel: SDK: Set HIGH_SPEED_EN for MMC1 instance",""
   "LCPD-24595","am64xx-evm,am64xx-sk,j721e-idk-gw,j721e-sk,j7200-evm","j721e-idk-gw USB Suspend/Resume with RTC Wakeup fail (Impact 1)",""
   "LCPD-24593","am64xx-evm","am64xx-evm CAN_S_FUNC_MODULAR test failures",""
   "LCPD-24537","am64xx-evm,am64xx-hsevm,am654x-evm","am654x-idk nslookup times out when all netwokring interfaces are active",""
   "LCPD-24467","am64xx-sk","am64xx-sk stress boot test fails",""
   "LCPD-24456","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am62axx-sk,am62xx-hsevm,am62xx-sk,am62xx-vlab,am62xx-zebu,am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j7ae-evm,j7ae-zebu,j7aep-zebu,j7am-evm,j7am-vlab,j7am-zebu,j7amp-vlab,j7amp-zebu,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721e-vlab,j721s2-evm,j721s2-hsevm,j7200-evm,j7200-hsevm,j7amp-evm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm,k2l-hsevm,omapl138-lcdk","Move IPC validation source from github to git.ti.com",""
   "LCPD-24448","am64xx-evm","Verify IPC kernel: main-r5f0(s)/main-r5f1(s)",""
   "LCPD-23102","am64xx-sk","AM64-SK: DMA is not stable",""
   "LCPD-23066","am64xx-sk","am64x-sk :gpio: direction test fail",""
   "LCPD-22931","am64xx-evm,am64xx-sk,am654x-evm,am654x-idk,dra72x-evm","RemoteProc documentation missing",""
   "LCPD-22912","am64xx-evm","am64xx-evm SMP dual core test fails sporadically",""
   "LCPD-22892","am64xx-evm,am654x-evm,am654x-idk","icssg: due to FW bug both interfaces has to be loaded always",""
   "LCPD-22834","am64xx-evm","am64xx-evm stress boot test fails",""
   "LCPD-22319","am64xx-evm,j7200-evm","OpenSSL performance test data out of bounds",""
   "LCPD-22215","am64xx-evm","PCIE NVM card stops enumerating on am64xx after some time",""
   "LCPD-20705","am64xx-evm","USB stick attached to PCIe USB card is not enumerated",""
   "LCPD-20558","am64xx-sk","OSPI UBIFS tests failing on am64xx-sk",""
   "LCPD-20105","am64xx-evm","AM64x: Kernel: ADC: RX DMA channel request fails",""
   "LCPD-20061","am64xx-evm","Occasional PHY error during during TSN Time-Aware Shaper execution",""
   "LCPD-20006","am64xx-evm","AM64x: remoteproc may be stuck in the start phase after a few times of stop/start",""
   "LCPD-18854","am64xx-evm,dra71x-evm,dra76x-evm","ov5640 sensor capture fails for raw format capture","" 
	
Linux RT Kernel Known Issues
----------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35

   "LCPD-24288","am64xx-evm,am654x-idk","am64xx-evm NCM/ACM network performance test crashes with RT images",""
