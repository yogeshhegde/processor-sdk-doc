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

Release 08.03.00
==================

Released May 2022

.. rubric:: What's New
   :name: whats-new

Processor SDK 8.3 Release has following new features:

- AM62: Initial Platform Support
- U-Boot: OSPI NOR, SD/eMMC (HS200), UART, Ethernet (CPSW) support,
  USB host (mass storage) and USB device (DFU)
- ATF: Upgrade to v2.6
- Kernel: SD/eMMC, SDIO, GPIO, OSPI NOR, USB host and device mode, RTC, ePWM,
  CPSW 3G, IPC M4, IPC PRUSS, Mailbox, HWspinlock, SA3UL,
  Display( DPI, HDMI), Graphics DDK 1.15, McASP audio out

Build Information
=====================================

U-Boot
-------------------------

| Head Commit: 74fc69c8897f67628ee9517744c720a3dc201f53 fastboot: add missing include
| Date: Wed May 25 17:00:29 CDT 2022
| uBoot Version: 2021.01
| uBoot Description: 08.03.00.005
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2021.01
| uBoot Tag: 08.03.00.005

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))

Kernel
-------------------------
.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 9e58028f945f077b3e0d7423c6af8938ec46a80a Merged TI feature platform_base into ti-linux-5.10.y
| Date: Wed May 25 17:24:07 CDT 2022
| Kernel Version: 5.10.109
| Kernel Description: 08.03.00.005

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.10.y
| Tag: 08.03.00.005
| Kernel defconfig: ti_sdk_arm64_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: d9ee8a25c2eea0d2aff22f36ced2513538fbd1a2 Merged TI feature ti_linux_base_rt into ti-rt-linux-5.10.y
| Date: Wed May 25 18:51:56 CDT 2022
| Kernel Version: 5.10.109
| RT Kernel Version: 5.10.109-rt65
| Kernel Description: 08.03.00.005-rt

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.10.y
| Tag: 08.03.00.005-rt
| Kernel defconfig: ti_sdk_arm64_rt_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))

Yocto
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: e99d9aa3fc41fa3a91d68ad9e654d40bfb6e0967 ti-linux-fw: Bump to 08.03.00.005 release
| Date: 2022-05-20
| Version: dunfell-3.1

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: 08.03.00.005

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: aa5fd0df1e0392703f7929c407ee1caf0f40b5aa ti-tisdk-setup: Bump to 08.03.00.005 release
| Date: 2022-05-20
| Version: 2021.09

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: dunfell
| Release Tag: 08.03.00.005
|

Issues Tracker
=====================================

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 100

   "LCPD-25536","DM should be relocated on AM62 to be inline with TF-A and OPTEE locations","am62xx-evm,am62xx-sk"
   "LCPD-25492","Occasionally Matrix-Gui does not auto launch","j721e-idk-gw,j721s2-evm,am62xx-sk"
   "LCPD-25293","CSI-2 driver not probing IMX219 image sensor","am62xx-sk"

|


Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-28101","EMMC boot fails","am62xx-sk"
   "LCPD-28036","AM62x: U-Boot: xSPI boot is broken","am62xx-sk"
   "LCPD-27815","uboot cannot warm reset the am62","am62xx-sk"
   "LCPD-25569","AM64:  Timer issues","am64xx-evm,am64xx-sk,am62xx-sk"
   "LCPD-25567","AM62x; WKUP UART pinmux not setup","am62xx-sk"

|

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title"
   :widths: 15, 180

   "LCPD-22890","PCIe: Link up failure when unused lanes are not assigned to PCIe Controller"
   "LCPD-22576","UART: Possible underflow condition when using EDMA with UART1, UART2, UART3"
   "LCPD-22573","DPHY: Reset sequence issue can lead to undefined module behavior"
   "LCPD-22544","DDR: LPDDR4 should be configured to 2666 MT/S"
   "LCPD-22543","CPSW: ALE IET Express Packet Drops"
   "LCPD-22424","PCIe: SERDES output reference clock cannot be used"
   "LCPD-22293","UFS: Auto-Hibernate can cause false entry/exit errors"
   "LCPD-22249","UDMA: Force teardown bitfield readback is masked in realtime TX/RX registers"
   "LCPD-20123","MPU COUNTER_REALTIME saturates after several hundred days"
   "LCPD-19987","UDMAP: Spurious ECC errors due to MAIN/MCU NAVSS rofifo_wr_byten issue"
   "LCPD-19986","UDMAP: TX Channel SA2UL teardown issue"
   "LCPD-19966","I3C: SDAPULLEN drives low instead of Hi-Z"
   "LCPD-19965","OSPI PHY Controller Bug Affecting Read Transactions"
   "LCPD-19874","PSIL: Clock stop operation can result in undefined behavior"
   "LCPD-19811","CPSW: ALE incorrectly routes packets with CRC errors"
   "LCPD-19586","USB: 2.0 PHY hangs if received signal amplitude crosses squelch threshold multiple times within the same packet"
   "LCPD-19561","R5FSS: Lock-step mode of operation is not functional"
   "LCPD-19447","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame"
   "LCPD-19068","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame"
   "LCPD-19056","USB: DMA hangs if USB reset is received during DMA transfer in device mode"
   "LCPD-19048","USB: Invalid termination of DMA transfer for endpoint following Isochronous endpoint in Superspeed device mode"
   "LCPD-19047","USB: Race condition while reading TRB from system memory in device mode"
   "LCPD-19041","PCIe: End of Interrupt (EOI) not enabled for PCIe legacy interrupts"
   "LCPD-19032","CPSW: CPSW Does Not Support Intersperced Express Traffic (IET -- P802.3br/D2.0) In 10/100Mbps Mode"
   "LCPD-19031","[CPTS] GENF (and ESTF)  Reconfiguration Issue"
   "LCPD-19030","USB: USB2PHY Charger Detect is enabled by default without VBUS presence"
   "LCPD-19029","PCI-Express (PCIe) May Corrupt Inbound Data"
   "LCPD-19028","DSS : DSS DPI Interface does not support BT.656 and BT.1120 output modes"
   "LCPD-19027","CPSW does not support CPPI receive checksum (Host to Ethernet) offload feature"
   "LCPD-19026","MMCSD: Negative Current from UHS-I PHY May Create an Over-Voltage Condition on VDDS6 and VDDS7 which exposes the Device to a Significant Reliability Risk"
   "LCPD-19025","IO, MMCSD: Incorrect IO Power Supply Connectivity Prevent Dynamic Voltage Change on VDDSHV6 and VDDSHV7"
   "LCPD-19024","RINGACC and UDMA ring state interoperability issue after channel teardown"
   "LCPD-19022","UDMA-P Real-time Remote Peer Registers not Functional Across UDMA-P Domains"
   "LCPD-18999","PCIe: Endpoint destination select attribute (ASEL) based routing issue"
   "LCPD-18996","Hyperflash: Hyperflash is not functional"
   "LCPD-18995","OSPI: OSPI Boot doesn't support some xSPI modes or xSPI devices"
   "LCPD-18981","UDMAP: Packet mode descriptor Address Space Select Field Restrictions"
   "LCPD-18980","PCIe: Gen2 capable endpoint devices always enumerate as Gen1"
   "LCPD-18979","MCAN: Message Transmitted with Wrong Arbitration and Control Fields (Early Start of Frame)"
   "LCPD-18952","DSS : DSS Does Not Support YUV Pixel Data Formats"
   "LCPD-17806","Cortex-R5F: Deadlock might occur  when one or more MPU regions is configured for write allocate mode"
   "LCPD-17788","PCI-Express: GEN3 (8GT/s) Operation Not Supported."
   "LCPD-17786","UART: Spurious UART Interrupts When Using DMA"
   "LCPD-17784","CPSW: CPSW Does Not Support Intersperced Express Traffic (IET -- P802.3br/D2.0) In 10/100Mbps Mode"
   "LCPD-17783","USB: USB2PHY Charger Detect is enabled by default without VBUS presence"
   "LCPD-17333","[CPTS] GENF (and ESTF)  Reconfiguration Issue"
   "LCPD-17220","U-Boot Hyperbus: Hyperflash reads limited to 125MHz max. frequency"
   "LCPD-16904","PCIe: Unsupported request (UR) or Configuration Request Retry Status (CRS) in configuration completion response packets results in external abort"
   "LCPD-16643","Hyperbus: Hyperflash reads limited to 125MHz max. frequency"
   "LCPD-16605","MMC: MMC1/2 Speed Issue"
   "LCPD-16538","PCI-Express (PCIe) May Corrupt Inbound Data"
   "LCPD-14941","RINGACC and UDMA ring state interoperability issue after channel teardown"
   "LCPD-14579","DSS : DSS Does Not Support YUV Pixel Data Formats"
   "LCPD-14577","CPSW does not support CPPI receive checksum (Host to Ethernet) offload feature"
   "LCPD-14187","UDMA-P Real-time Remote Peer Registers not Functional Across UDMA-P Domains"
   "LCPD-14185","MSMC: Non-coherent memory access to coherent memory can cause invalidation of snoop filter"
   "LCPD-14184","USB:  SuperSpeed USB Non-Functional"
   "LCPD-9084","i887: Software workaround to limit mmc3 speed to 64MHz"
   "LCPD-8294","37 pins + VOUT pins need slow slew enabled for timing and reliability respectively"
   "LCPD-8277","u-boot: j6: SATA is not shutdown correctly as per errata i818"
   "LCPD-7642","MMC/SD: i832: return DLL to default reset state with CLK gated if not in SDR104/HS200 mode."
   "LCPD-6907","Workaround errata i880 for RGMII2 is missing"
   "LCPD-5931","DRA7xx: AM57xx: mmc: upstream errata workaround for i834"
   "LCPD-5924","ALL: CONNECTIVITY: CPSW: errata i877 workarround for cpsw"
   "LCPD-5836","CAL: Errata: i913: CSI2 LDO needs to be disabled when module is powered on"
   "LCPD-5309","LCPD:  i896: USB Port disable doesnt work"
   "LCPD-5308","i897: USB Stop Endpoint doesnt work in certain circumstances"
   "LCPD-5052","Upstream: Post the dmtimer errata fix for i874"
   "LCPD-4975","DSS AM5/DRA7: implement WA for errata i886"
   "LCPD-4912","DRA7: USB: Implement ErrataID_i896_PED_issue"
   "LCPD-4910","J6/OMAP5: errata i810 implementation"
   "LCPD-4648","[rpmsg 2014 LTS] Implement errata i879 - DSP MStandby requires CD_EMU in SW_WKUP"
   "LCPD-4647","[rpmsg 2015 LTS] Implement errata i879 - DSP MStandby requires CD_EMU in SW_WKUP"
   "LCPD-4225","J6: Errata: i834: Investigate possibility of software workaround"
   "LCPD-4218","Implement Workaround for Errata i813 - Spurious Thermal Alert Generation When Temperature Remains in Expected Range"
   "LCPD-4217","Implement Workaround for Errata i814 - Bandgap Temperature read Dtemp can be corrupted"
   "LCPD-4195","J6: SATA: Investigate applicability of i807"
   "LCPD-4184","Implement workaround for errata i814 - Bandgap Temperature read Dtemp can be corrupted"
   "LCPD-1776","[J6 SATA Adaptation] J6 - Errata i783, SATA Lockup After SATA DPLL Unlock/Relock"
   "LCPD-1188","J6: Baseport: Errata i877: RGMII clocks must be enabled to avoid IO timing degradation due to Assymetric Aging"
   "LCPD-1146","DMM hang: Errata VAYU-BUG02976 (i878) (register part)"
   "LCPD-1108","J6: Wrong Access In 1D Burst For YUV4:2:0-NV12 Format (Errata i631)"
   "LCPD-1087","J6: MMC: Errata: i802: OMAP5430 MMCHS: DCRC errors during tuning procedure"
   "LCPD-976","J6/J6eco: 32clk is psuedo (erratum i856) - clock source"
   "LCPD-975","J6/J6eco: 32clk is psuedo (erratum i856) - realtime counter"
   "LCPD-876","OMAP5: Errata i810: DPLL Controller Sticks when left clock requests are removed"

|

SDK Known Issues
-----------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-28102","am62xx-sk","Automated test failure - GPU Mem2Mem test failed due to missing test program",""
   "LCPD-25663","j721e-evm,j721s2-evm,am62xx-sk","Remove old IMG demo binaries  ",""
   "LCPD-25662","j721e-evm,j7200-evm,am62xx-sk","Remove SGX PVR tools from KS3 devices",""

|


U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-28100","am62xx-sk","OSPI boot fails",""
   "LCPD-27828","am62xx-sk","AM62: Fix the USB MSC environment setting",""

|


Linux Kernel Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround" 
   :widths: 5, 10, 70, 35

   "LCPD-28131","am62xx-sk","am62x: wlan interface up - down - up results in kernel crash",""
   "LCPD-28111","am64xx-evm,am62xx-sk","wic image flashed sdcard should resize to full image",""
   "LCPD-28110","am62xx-sk","uboot and linux cannot boot in UHS speed modes on certain U1 class SD-cards",""
   "LCPD-28105","am62xx-sk","Automated test failure - CPSW failure doing runtime pm",""
   "LCPD-28104","am62xx-sk","Automated test failure - CPSW test is passing invalid parameters to switch-config",""
   "LCPD-28103","am62xx-sk","Automated test failure - CPSW test fails to find an active interface implemented by CPSW",""
   "LCPD-26721","am62xx-sk","AM62x: Cannot resume with more than one A53 enabled ",""
   "LCPD-25580","am62xx-sk","AM62: Move BSS below DM config data",""
   "LCPD-25563","am62xx-sk","Test: AM62: Linux: Add support for MCAN",""
   "LCPD-24456","am62xx-sk","Move IPC validation source from github to git.ti.com",""
   "LCPD-28149","am62xx-sk",CMA warning while running GPU tests",""

|


Linux RT Kernel Known Issues
----------------------------

There are no known issues in this release in the Linux RT Kernel.
