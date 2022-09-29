************************************
Release Notes
************************************
.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Release_Notes

Overview
========

The **Processor-CoreSDK for Linux**
provides a fundamental software platform for development, deployment and
execution of Linux based applications and includes the following:

-  Bootloaders & Filesystems
-  Prebuilt Binaries
-  Detailed Release Notes

Licensing
=========

Please refer to the software manifest, which outlines the licensing
status for all packages included in the prebuilt binaries location. 


Release 08.04.01
==================

Released September 2022

.. rubric:: What's New
   :name: whats-new

Processor SDK 8.4 Sitara Release supports the following platforms:

- AM62x
  * 1.4 Ghz Support and DFS (Dynaminc Frequency Scaling)
  * DDR ECC Single bit mode
  * VTM, WDT
  * AM62 LP Starter Kit Initial Platform Support
  ** OSPI SPI NAND Support

- AM64x
  * SR2.0 HS-FS (High Security - Field Securable) Support
  * DDR ECC Single bit mode
  * VTM


Build Information
=====================================

U-Boot
-------------------------
| Head Commit: 2dd2e1d366acf7f41bbd8f2d1dbe6cf5e1bcbad6 dma: ti: k3-udma: Fix 'SZ_64K' undeclared error
| Date: Wed Sep 28 16:41:34 CDT 2022
| uBoot Version: 2021.01
| uBoot Description: 08.04.01.005
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2021.01
| uBoot Tag: 08.04.01.005
| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))

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

| Compiler Information:  arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 3a997318d8caa8caa100ecc69472e528ecfc2ebb Merge branch 'ti-rt-linux-5.10.y-cicd' into ti-rt-linux-5.10.y
| Date: 24 Sep 2022 01:23 PM
| Kernel Version: 5.10.140
| Kernel Description: 08.04.01.005-rt

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.10.y
| Tag: 08.04.01.005-rt
| Kernel defconfig: ti_sdk_arm64_rt_release_defconfig

| Compiler Information:  arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025

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

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-25536","DM should be relocated on AM62 to be inline with TF-A and OPTEE locations","am62xx-sk"
   "LCPD-25535","UBoot: customized ${optargs} doesn't take affect on K3 devices","am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm,j721e-evm,j721e-hsevm,j721s2-evm,j721s2-hsevm,j7200-evm,j7200-hsevm"
   "LCPD-25522","AM64: Ethernet broken at u-Boot prompt","am64xx-evm,am64xx-sk"
   "LCPD-25503","ATF/A53 does not come out of WFI if TIFS/DM signals a suspend abort","am62xx-sk"
   "LCPD-25492","Occasionally Matrix-Gui does not auto launch","am62xx-sk,j721e-idk-gw,j721s2-evm"
   "LCPD-25320","Docs: AM64x: IPC chapter should be under Foundational Components","am64xx-evm,am64xx-sk"
   "LCPD-25293","CSI-2 driver not probing IMX219 image sensor","am62xx-sk"
   "LCPD-25252","Docs: OPTEE SDK documentation is very minimal ","am62xx-hsevm,am62xx-sk,am64xx-evm,am64xx-hsevm"
   "LCPD-25074","AM64 HS Boot broken ","am64xx-hsevm"
   "LCPD-25070","am64xx-sk uboot build failed to boot due to ","am64xx-sk"
   "LCPD-24511","ARM: A72/53 L1 data cache and L2 cache set counts wrong","am64xx-evm,am64xx-hsevm,am64xx-sk,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm"
   "LCPD-24507","U-Boot command ""saveenv"" doesn't save env ","am64xx-evm,am64xx-hsevm,am64xx-sk,j721e-idk-gw"
   "LCPD-24498","AM64x DDR configuration needs update for EVM and SK","am64xx-evm,am64xx-sk"
   "LCPD-24470","QSPI Uboot Perf Test Failing","am64xx-evm"
   "LCPD-22812","Upstream: reserved-memory.txt  convert to yaml","am64xx-hsevm,am64xx-sk,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j7200-evm,j7200-hsevm,k2g-evm,k2g-hsevm"
   "LCPD-20310","Upstream: Timeout behavior inconsistency seen in upstream R5 SPL","am64xx-evm,j721e-evm,j7200-evm"
   "LCPD-19858","OE: OPTEE label used in SDK is old and wrong","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am64xx-evm,am64xx-vlab,am64xx-zebu,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm,k2l-hsevm"

|


Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-29284","Fix ti,sci-inta, ti,sci-intr and mmc dtbs_check","am62xx-sk,am64xx-evm,j721e-idk-gw,j721s2-evm"
   "LCPD-28921","AM62Q: validated samples crash on bootup","am62xx-lp-sk"
   "LCPD-28867","am62x: ti_sci: fix polled mode during suspend/resume","am62xx-sk"
   "LCPD-28827","u-boot: add support for AM64B SK","am64xx-sk"
   "LCPD-28740","AM62x SK: R5 SPL - default boot frequency should be 1.25 GHz","am62xx-sk"
   "LCPD-28664","am62x_evm_r5_ethboot_defconfig ""spl/u-boot-spl.bin exceeds file size limit” Build Failure","am62xx-sk"
   "LCPD-28658","doc: build instructions for ATF are unclear and might be incorrect","am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk"
   "LCPD-28449","Reboot does not work after suspend to ram","am62xx-sk"
   "LCPD-28442","am62x : Incorrect register size used for pktdma and bcdma nodes in device tree","am62xx-sk"
   "LCPD-28435","devtool finish fails","am64xx-evm"
   "LCPD-28419","Linux: All: AM65 CPSW driver fails to build w/o PHYLINK=y","am62xx-sk,j721e-idk-gw"
   "LCPD-28416","Stop using git:// in meta-ti , meta-arago","am62xx-sk"
   "LCPD-28413","Clarify PRU Ethernet not supported features","am64xx-evm,am654x-evm"
   "LCPD-28357","HSR/PRP Steps do not work","am64xx-evm"
   "LCPD-28331","OSPI layout offsets need to be updated in SDK 8.3 u-boot user guide","am62xx-sk"
   "LCPD-28327","u-boot ddr dtsi has a register double entries leading to data corruption","am62xx-hsevm,am62xx-sk"
   "LCPD-28325","kernel crashes if CONFIG_DEBUG_FS is not set","am62xx-hsevm,am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm,j7am-evm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721s2-evm,j721s2-hsevm,j7200-evm,j7200-hsevm"
   "LCPD-28179","Fix DFU Env variable for flashing combined bootloader images","am64xx-evm,j7200-evm"
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
   "LCPD-25765","AM64x U-boot is broken for mmc boot","am64xx-evm,am64xx-sk"
   "LCPD-25665","am62 having trouble responding to voltage select","am62xx-sk"
   "LCPD-25580","AM62: Move BSS below DM config data","am62xx-sk"
   "LCPD-25569","AM64:  Timer issues","am62xx-sk,am64xx-evm,am64xx-sk"
   "LCPD-25567","AM62x; WKUP UART pinmux not setup","am62xx-sk"
   "LCPD-25565","am62: sk: i2c controller time out","am62xx-sk"
   "LCPD-25564","J721s2-evm: CPSW2g: interface goes up and down sporadically","am62xx-sk,j721s2-evm"

|

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 150

   "LCPD-27887","i2327: RTC: Hardware wakeup event limitation"
   "LCPD-19965","OSPI PHY Controller Bug Affecting Read Transactions"

|

SDK Known Issues
-----------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-29285","am62xx-lp-sk,am62xx-sk","AM62x: U-Boot default defconfig does not generate unsigned image",""
   "LCPD-28773","am62xx-sk","Incorrect macro definition for DST_TAG bit field in CSI-2 RX driver",""
   "LCPD-28149","am62xx-sk","CMA warning while running GPU tests",""
   "LCPD-28102","am62xx-sk","Automated test failure - GPU Mem2Mem test failed due to missing test program",""
   "LCPD-25663","am62xx-sk,j721e-evm,j721s2-evm,j784s4-evm","Remove old IMG demo binaries  ",""
   "LCPD-25662","am62xx-sk,j721e-evm,j7200-evm","Remove SGX PVR tools from KS3 devices",""
   "LCPD-20038","am64xx-evm","OPTEE test applications are missing from rootfs",""

|


U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-29300","am62xx-sk","U-Boot: OSPI-NOR: sf probe shows 0 randomly",""
   "LCPD-29285","am62xx-lp-sk,am62xx-sk","AM62x: U-Boot default defconfig does not generate unsigned image",""
   "LCPD-28660","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: tiboot3.bin generated by U-Boot build is confusing users",""
   "LCPD-28503","am62xx-sk,am64xx-evm,am64xx-sk","Need to sync up DTS files between u-boot and kernel for at least AM62x, possibly other boards too",""
   "LCPD-27828","am62xx-sk","AM62: Fix the USB MSC environment setting",""
   "LCPD-25558","am64xx-evm","the 'nand' tool doesn't seem to be working",""
   "LCPD-25540","am64xx-sk","u-boot: usb host boot failed on AM64x SK",""
   "LCPD-24726","am64xx-sk","Uboot qspi read write performance test  failed ",""
   "LCPD-23026","am64xx-evm,am64xx-sk","USB MSC Boot: USB controller not visible from u-boot",""
   "LCPD-23020","am64xx-evm","am64xx-evm: U-Boot PHY autonegotiation failed 2 out of 100 times",""

|


Linux Kernel Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround" 
   :widths: 5, 10, 70, 35

   "LCPD-29353","am62xx-sk","Automate Test: AM62x Linux to M4 IPC: simple shared memory example",""
   "LCPD-29352","am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk","SDK: AM62x Linux to M4 IPC: simple shared memory example",""
   "LCPD-29344","am62xx-lp-sk","A53 SPL crashing while booting HSM using SBL OSPI NAND",""
   "LCPD-29341","am64xx-evm","AM64x EVM: Clarify CPSW / PRU Ethernet selection steps",""
   "LCPD-29339","am62xx-sk","Processor SDK 8.3 AM62x lacks RT Linux performance numbers",""
   "LCPD-29306","am64xx-evm,am654x-idk","PRU_ICSSG: How much SRAM is needed?",""
   "LCPD-29305","am64xx-evm,am64xx-sk","AM64x Uboot SRAM addresses are outdated",""
   "LCPD-28826","am62xx-sk","linux - enable CONFIG_DEBUG_INFO",""
   "LCPD-28774","am64xx-evm","plsdk-doc: PCIe doc content is incomplete for AM64x",""
   "LCPD-28764","am62xx-sk","AM62x: Cannot resume from low power mode",""
   "LCPD-28757","am64xx-evm","NAND Extension board causes UBoot Failure on am64xx-evm",""
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
   "LCPD-28307","am64xx-evm","Linux WDT SDK docs are missing",""
   "LCPD-28156","am62xx-sk","Mcasp: Buffer underflow warnings",""
   "LCPD-28111","am62xx-sk,am64xx-evm","wic image flashed sdcard should resize to full image",""
   "LCPD-28110","am62xx-sk","uboot and linux cannot boot in UHS speed modes on certain U1 class SD-cards",""
   "LCPD-28105","am62xx-sk","Automated test failure - CPSW failure doing runtime pm",""
   "LCPD-28104","am62xx-sk","Automated test failure - CPSW test is passing invalid parameters to switch-config",""
   "LCPD-27871","am64xx-evm","GPMC NAND driver misleading error",""
   "LCPD-26731","am64xx-evm,am64xx-hsevm","OpenSSL benchmarks for AM64x are empty",""
   "LCPD-25764","am64xx-evm,am64xx-sk","Upstream: AM64x DDR configuration needs update for EVM and SK",""
   "LCPD-25652","am62xx-sk","am62: sk: reset-gpio property for sil9022a",""
   "LCPD-25636","am64xx-sk","main uart0 pinmux not defined in k3-am642-sk.dts",""
   "LCPD-25563","am62xx-sk","Test: AM62: Linux: Add support for MCAN",""
   "LCPD-25494","am64xx-evm","AM64 EVM TSN IET tests is failing",""
   "LCPD-25410","am62xx-lp-sk,am62xx-sk,am64xx-evm,am64xx-sk","Test: Support read of On-die temperature sensor in Linux",""
   "LCPD-25409","am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk","Doc: Support read of On-die temperature sensor in Linux",""
   "LCPD-25112","am64xx-evm,j721e-idk-gw","Ethernet driver not gating its clock when interface is down",""
   "LCPD-24872","am64xx-sk","Am64x-sk :LCPD-16811 CPSW  failed while throughput metrics comparison ",""
   "LCPD-24823","am64xx-evm,am64xx-sk","Clarify Single-Core usage in ti,k3-r5f-rproc.yaml",""
   "LCPD-24696","am64xx-sk","CPSW Promiscuous mode test failing on am64xx-sk",""
   "LCPD-24690","am62xx-sk,am64xx-evm,am64xx-sk,j721s2-evm,j7200-evm","Kernel: SDK: Set HIGH_SPEED_EN for MMC1 instance",""
   "LCPD-24677","am62xx-sk,j721e-idk-gw","j721e-idk-gw PCI WIFI Tests Fail due to iperf issues(Impact 1)",""
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
   "LCPD-22715","am62xx-sk,j721e-idk-gw,j721s2-evm,j7200-evm","i2232: DDR: Controller postpones more than allowed refreshes after frequency change","Workaround 1:"
   "LCPD-22319","am64xx-evm,j7200-evm","OpenSSL performance test data out of bounds",""
   "LCPD-22215","am64xx-evm","PCIE NVM card stops enumerating on am64xx after some time",""
   "LCPD-21662","am62xx-sk","Doc: Linux watchdog support",""
   "LCPD-20705","am64xx-evm","USB stick attached to PCIe USB card is not enumerated",""
   "LCPD-20558","am64xx-sk","OSPI UBIFS tests failing on am64xx-sk",""
   "LCPD-20105","am64xx-evm","AM64x: Kernel: ADC: RX DMA channel request fails",""
   "LCPD-20061","am64xx-evm","Occasional PHY error during during TSN Time-Aware Shaper execution",""
   "LCPD-20006","am64xx-evm","AM64x: remoteproc may be stuck in the start phase after a few times of stop/start",""
   "LCPD-18854","am64xx-evm,dra71x-evm,dra76x-evm","ov5640 sensor capture fails for raw format capture",""

|


Linux RT Kernel Known Issues
----------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35

   "LCPD-29339","am62xx-sk","Processor SDK 8.3 AM62x lacks RT Linux performance numbers",""
   "LCPD-29332","am62xx-sk","LPM Demo not Working on Linux RT",""
   "LCPD-24288","am64xx-evm,am654x-idk","am64xx-evm NCM/ACM network performance test crashes with RT images",""

|
