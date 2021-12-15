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

Release 08.01.00
==================

Released December 2021

.. rubric:: What's New
   :name: whats-new

Processor SDK 8.1 Release has following new features:

- Second release on 2021 LTS 5.10 kernel, 2021.01 U-Boot
- J721E: Video encoder/decoder support 
- J721e: CAN driver
- J7200, AM64: High security board support
- AM64: Kernel NAND driver
- AM64: non-offload :hsr/prp with mtu,snmp,pps for performance, icssg, cpsw virtual net driver
- Support for AM3, AM4 and AM5 platforms

Build Information
=====================================

U-Boot
-------------------------

| Head Commit: 15769936a559b1840f50b83f94ee0c636b245001 configs: am64x: Add FIT ARGS for HS images
| Date: Tue Dec 14 08:15:08 CST 2021
| uBoot Version: 2021.01
| uBoot Description: 08.01.00.006
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: 08.01.00.006
| uBoot Tag: 08.01.00.006

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))

Kernel
-------------------------
.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: dcc6bedb2c2bdb509709e4ae08303206e95ce6c2 Merged TI feature connectivity into ti-linux-5.10.y
| Date: Wed Dec 15 08:06:10 CST 2021
| Kernel Version: 5.10.65
| Kernel Description: 08.01.00.006

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.10.y
| Tag: 08.01.00.006
| Kernel defconfig: ti_sdk_arm64_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 541ec9a6995c3dd881d6f0b63cc714a08ded457d Merged TI feature ti_linux_base_rt into ti-rt-linux-5.10.y
| Date: Tue Dec 14 09:43:46 CST 2021
| Kernel Version: 5.10.65
| RT Kernel Version: 5.10.65-rt53
| Kernel Description: 08.01.00.006-rt

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.10.y
| Tag: 08.01.00.006-rt
| Kernel defconfig: ti_sdk_arm64_rt_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))

Yocto
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 15613c951051c450fc8726b2576c23c105b79d53 linux-ti-staging: block sa2ul for am64x hs and j7200 hs device
| Date: 2021-12-10
| Version: dunfell-3.1

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: 08.01.00.006

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: e13e698213f5c4e2617ace97dca2d0ccf84ab0af Update the ltp-ddt to latest
| Date: 2021-12-03
| Version: 2021.09

| Clone: git://git.yoctoproject.org/git/meta-arago.git
| Branch: dunfell
| Release Tag: 08.01.00.006
|

Issues Tracker
=====================================

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 100

   "LCPD-23009"," CAL capture test- No capture device of type cal found","am654x-evm"
   "LCPD-23003","IPC: when pdk-ipc fw loaded from u-boot it breaks j721e boot and ethfw","j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw"
   "LCPD-22979","firmware links are missing in /lib/firmware directory for K3","am64xx-evm,am64xx-sk,am654x-evm,j721e-idk-gw,j7200-evm"
   "LCPD-22973","GFX_XS_FUNC_GPU_MEM2MEM test fails due to a change in the expected output","j721e-idk-gw"
   "LCPD-22967","U-Boot: PLL PostDiv1 and PostDiv2 divider clock rates are computed incorrectly","j721e-evm,j721e-evm-ivi,j721e-idk-gw,j7200-evm"
   "LCPD-22966","Upstream: U-Boot: PLL PostDiv1 and PostDiv2 divider clock rates are computed incorrectly","j721e-evm,j721e-evm-ivi,j721e-idk-gw,j7200-evm"
   "LCPD-22965","Upstream: U-Boot: PLL POSTDIV1 and POSTDIV2 clock parenting is reversed","j721e-evm,j721e-evm-ivi,j721e-idk-gw,j7200-evm"
   "LCPD-22951","Alsa test fails - no soundcards found","am654x-evm"
   "LCPD-22950","AM654x ALSA tests fail due to soundcard issues ","am654x-evm"
   "LCPD-22949","Audio interactive test fails","am654x-evm"
   "LCPD-22941","ptp clock register breaks 5.14-rc1 kernel bootup","am64xx-evm,am654x-evm,j721e-evm,j7200-evm"
   "LCPD-22920","AM64x Linux IPC documentation is insufficient / out-of-date","am64xx-evm"
   "LCPD-22913","USBDEV ACM NCM enumeration fails on the device side ","am64xx-evm,am654x-idk,j721e-idk-gw,j7200-evm"
   "LCPD-22907","j7200: EthFw not getting Q/SGMII linked","j7200-evm"
   "LCPD-22887","HSR/PRP: Root cause NetJury issues with PRP","am571x-idk,am572x-idk"
   "LCPD-22852","AM64x: ICSSG ping with 16384 size shows high packet loss","am64xx-evm"
   "LCPD-22823","Convert eeprom-93xx46.txt:    ""microchip,93lc46b"" to yaml","am335x-evm,am437x-idk,am572x-idk,am64xx-evm"
   "LCPD-22822","Convert inside-secure,safexcel-eip76 (omap_rng.txt) to yaml","am335x-evm,am437x-idk,am572x-idk"
   "LCPD-22789","cdns-usb3: g_mass_storage and g_ether fails on some boards","am64xx-evm"
   "LCPD-22549","v4l2h264dec : application hangs when setting the pipeline to null","j721e-idk-gw"
   "LCPD-22514","Broken USB MSC boot on AM642-EVM","am64xx-evm"
   "LCPD-22362","ALSA sampling format capture/loopback test - arecord failure","am335x-evm,j721e-idk-gw"
   "LCPD-22349","Displayport playback test fails: cannot find tidss device","j721e-idk-gw"
   "LCPD-22345","U-Boot: Main R5F clusters are incorrectly in LockStep mode","j721e-evm,j721e-evm-ivi,j721e-idk-gw"
   "LCPD-22344","crypto: sa2ul: crypto self-tests fail to allocate des3 algos","am654x-evm,am654x-idk,j721e-evm,j721e-evm-ivi,j721e-idk-gw"
   "LCPD-22338","ipc_echo_test test on am64xx-evm fails due to a firmware file name change","am64xx-evm"
   "LCPD-22318","CRYPTO_S_PERF testcases are missing CONFIG_CRYPTO_DEV_SA2UL arg in 2021.00","am654x-evm,am654x-idk,j721e-evm-ivi,j721e-idk-gw,j7200-evm"
   "LCPD-22317","J7200 incorrect eMMC speedmode in u-boot","j7200-evm"
   "LCPD-22300","/dev/hwrng missing on K3 platforms","am654x-evm,am654x-idk,j721e-evm,j721e-evm-ivi,j721e-idk-gw,j7200-evm"
   "LCPD-22285","HS200 MMC speeds aren't being achieved in kernel","j721e-idk-gw"
   "LCPD-22278","PCI-E USB devices fail to enumerate after power cycling","j721e-idk-gw,j7200-evm"
   "LCPD-22246","j721e Uboot DFU tests are failing","j721e-idk-gw"
   "LCPD-22188","j721e and am65 hs fails to build on 2021.01 uboot","am654x-hsevm,j721e-hsevm"
   "LCPD-22095","omap-spi.txt  convert to yaml","am64xx-hsevm,am64xx-sk,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm,k2g-evm,k2g-hsevm,j721e-eaik"
   "LCPD-22091","ti,phy-am654-serdes.txt convert to yaml","am64xx-hsevm,am64xx-sk,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm,k2g-evm,k2g-hsevm,j721e-eaik"
   "LCPD-21962","U-Boot documentation discrepancies","am64xx-evm"
   "LCPD-21538","am64xx-evm PCI-EP MSI tests are failing","am64xx-evm"
   "LCPD-21525","k3-am654-base-board-sr1.dtb is missing for upstream","am654x-evm"
   "LCPD-21350","j7200 PCIE-EP tests failing","j7200-evm"
   "LCPD-21347","k3: cpswxg: switchdev: crash in am65_cpsw_port_offload_fwd_mark_update() when there is a disabled port","am64xx-evm,am64xx-sk"
   "LCPD-20320","CPSW5g high packet loss","j7200-evm"
   "LCPD-20291","am335x: gpio wakeup event is ignored","am335x-evm"
   "LCPD-20131","Uboot fails to enumerate devices attached to a usb hub on the first 'usb reset' call ","am64xx-evm,j721e-idk-gw,j7200-evm"
   "LCPD-19819","KMS ALPHABLEND tests fail due to no attribute 'get_default_mode'","j721e-idk-gw"
   "LCPD-19723","RTI watchdog test fails on J7VCL E5 SOM","j7200-evm"
   "LCPD-19636","J7: HS: OSPI Boot broken","j721e-hsevm"
   "LCPD-19460","J7200: USB3 devices fail to enumerate at 2.0/3.0 when SERDES multi-link (PCIe + USB3)","j7200-evm,j7200-hsevm"
   "LCPD-18673","IPSEC fails to establish connection when using HW crypto","j721e-idk-gw"
   "LCPD-16114","RTC Init Script Needs to Wait for Module Load","am335x-evm,am335x-ice,am335x-sk"

|


Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-24625","am64 - Boot modes: eMMC alternative boot mode","am64xx-evm"
   "LCPD-24624","am64 Boot modes: OSPI","am64xx-evm"
   "LCPD-24623","am64 DFU boot failure","am64xx-evm"
   "LCPD-24600","Interrupt count wrong due to missing channel for crypto test","am64xx-evm,j7200-evm"
   "LCPD-24594","j721e-idk-gw USBHOST_S_FUNC_ETH_PING Fails ","j721e-idk-gw"
   "LCPD-24591","j721e-idk-gw PCIE EP 4BAR, 16 MSI_INT, 4 PF, 4 VF each Fails boot with exception","j721e-idk-gw"
   "LCPD-24540","am654x-evm PCIE-EP tests must be updated to expect GEN2 ","am654x-evm"
   "LCPD-24536","video codec: sdk: standalone tests missing","j721e-idk-gw"
   "LCPD-24527","j721e-idk-gw: Failed to get DMA channel with PCIe EP","j721e-idk-gw"
   "LCPD-24523","am654x alsa tests failing 75% of the time","am654x-evm"
   "LCPD-24522","j721e-idk-gw TIENC TIDEC tests fail with modprobe ","j721e-idk-gw"
   "LCPD-24514","AM65: PCIE-EP: swiotlb buffer is full","am654x-evm"
   "LCPD-24501","Flashing Linux wic image to SD card does not boots Linux","am64xx-evm,am64xx-sk,am654x-idk,am654x-hsevm,j721e-evm,j721e-hsevm,j721e-idk-gw,j7200-evm,j7200-hsevm"
   "LCPD-24493","j7200-evm PCI_L_PERF_USBHOST_VFAT performance outside 10 stdev ","j7200-evm"
   "LCPD-24492","am64xx-evm Multiple NAND device failures","am64xx-evm"
   "LCPD-24483","j721e-idk-gw boot stess test TIMOUT at rproc ","j721e-idk-gw,j7200-evm"
   "LCPD-24480","am654x-hsevm fails to boot ti linux","am654x-hsevm"
   "LCPD-24471","USBDEV_highspeed_multi_enumerate","am64xx-evm"
   "LCPD-24469","AM65_SR10: ICSSG is broken","am654x-evm"
   "LCPD-24468","j721e and j7200 hang when booting fw image j7-main-r5f0_1-fw","j721e-evm-ivi,j721e-idk-gw,j7200-evm"
   "LCPD-24454","j721e-idk-gw  ALSA capture performance outside expected range ","j721e-idk-gw"
   "LCPD-24449","j721e-idk-gw Verify IPC spl broken ","j721e-idk-gw"
   "LCPD-24435","ETH-CPSW2G_XS_FUNC_SPEED_1000Mbps_ALL","am64xx-evm"
   "LCPD-24434","PCIe Wifi ping tests","am64xx-evm,j7200-evm"
   "LCPD-24431","DFU: SPL-DFU boot support","am64xx-evm"
   "LCPD-24430","j721e-idk-gw j7200-evm Dhrystone performance outside range ","j721e-idk-gw,j7200-evm"
   "LCPD-24428","j721e-idk-gw USB ping, iperf, zlp tests time out on USB link ready ","j721e-idk-gw"
   "LCPD-24424","j721e-idk-gw PCIE-EP Segmentation Fault ","j721e-idk-gw"
   "LCPD-24326","am654x-evm: CAL capture test fails","am654x-evm"
   "LCPD-24294","TSN CPSW EST feature, counter not synchronized to ptp clock","am64xx-evm,am64xx-sk"
   "LCPD-24293","ICSS based Ethernet performance vs CPSW (AM64x)","am64xx-evm"
   "LCPD-24270","J7200/J7VCL: DFU documentation is missing on the U-Boot section","j7200-evm"
   "LCPD-24229","AM654x PCIE EP Tests Cannot Find Images","am654x-evm"
   "LCPD-24219","AM64: ICSSG: No RX packets after link down<and>up","am64xx-evm"
   "LCPD-24212","Update the locations of various elements in SRAM","am64xx-evm"
   "LCPD-24140","J721e-idk-gw UFS FUNC RW tests fail ","j721e-idk-gw"
   "LCPD-24126","AM654x KMS_XS_FUNC tests fail ","am654x-evm"
   "LCPD-24124","AM654x Audio play + record test fails unexpectedly","am654x-evm"
   "LCPD-24122","AM654x DRM Tests all fail ","am654x-evm"
   "LCPD-24117","U-Boot user's guide does not have documentation on how to boot from USB mass storage","am64xx-evm"
   "LCPD-24114","AM64x: MCAN documentation is missing","am64xx-evm"
   "LCPD-24098","v4l2h264enc : application hangs when setting the pipeline to null","j721e-idk-gw"
   "LCPD-23095","AM64: Add U-Boot,dm-spl tag in MMC1 pinmux dt node","am64xx-evm"
   "LCPD-23055","AM654x: DFU Boot fails","am654x-evm"
   "LCPD-23041","Doc: Update J7200 eMMC documentation","j7200-evm"
   "LCPD-23024","PSDK-DOC: UBoot: USB host boot info is out of date","am64xx-evm"
   "LCPD-23023","j7200 eMMC, Hyperflash and OSPI boot mode tests failing","j7200-evm"
   "LCPD-23012","DRM universal planes - Could not get DRM master permission","am654x-evm"

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

   "LCPD-24619","j721e-idk-gw","Bitbake fails in different timezone",""
   "LCPD-24586","am654x-evm","am65 uboot usbhost custom builds are missing in 8.1",""
   "LCPD-24484","j721e-idk-gw","j721e-idk-gw GFXBench tests fail, DRM authenticate failed ",""
   "LCPD-24482","j721e-idk-gw","j721e-idk-gw RGX_S_FUNC_GLES tests fail ",""
   "LCPD-24475","j721e-idk-gw","Performance of H.265 decoder is poor",""
   "LCPD-24455","am335x-evm,am43xx-gpevm,am57xx-evm"," SGXInitialise failed -SGX is failing to start",""
   "LCPD-24436","am335x-evm,am43xx-gpevm,am57xx-evm","glmark2 benchmark for Graphics-Glmark2-DRM",""
   "LCPD-24290","j721e-idk-gw","Decoder + kmssink elements generates pink and green frames blinking",""
   "LCPD-24232","am335x-evm,am43xx-gpevm","Test issue Run Wayland 3D ChameleonMan demo",""
   "LCPD-23006","am654x-evm","PVR driver fails to detect SGX core on AM65x SR1.0",""
   "LCPD-22972","j721e-idk-gw","j721e-idk-gw GLBenchmark GLB25_EgyptTestStandardOffscreen_inherited test ",""
   "LCPD-22921","j721e-idk-gw","j721e PVR profiling with PVRPerfServer test is failing",""
   "LCPD-22542","j721e-idk-gw","v4l2h264dec is giving high latency compared to SW decoder",""
   "LCPD-22361","am57xx-evm","SGX Lockup with gstreamer + weston",""
   "LCPD-21298","j721e-evm,j721e-evm-ivi,j721e-idk-gw","Frame Buffer Decompression does not show expected improvement",""
   "LCPD-20620","j721e-idk-gw","J721e: Gstreamer warning seen with video decoder mjpeg test",""
   "LCPD-20038","am64xx-evm","OPTEE test applications are missing from rootfs",""
   "LCPD-19948","am57xx-evm,am654x-evm,j721e-evm","Yocto: stream recipe is incorrect",""
   "LCPD-19894","j721e-idk-gw","UYVY texture test fails due to internal data stream error",""
   "LCPD-19858","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am64xx-evm,am64xx-vlab,am64xx-zebu,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm,k2l-hsevm","OE: OPTEE label used in SDK is old and wrong",""
   "LCPD-19835","am574x-hsidk","AM57-HS : E/TC:0 ti_sip_handler boot warning ",""
   "LCPD-19743","j7200-evm,j7200-hsevm","Packages.gz is missing",""
   "LCPD-19716","j721e-idk-gw","GFX_XS_FUNC_UYVY_TEXTURE test fails",""
   "LCPD-18908","am654x-evm","GLMark2 fails for am65x",""
   "LCPD-18270","am335x-evm,am43xx-gpevm,am571x-idk,am572x-idk,am574x-idk,am57xx-evm,am57xx-beagle-x15,am654x-evm,am654x-idk,dra71x-evm,dra72x-evm,dra76x-evm,dra7xx-evm,j721e-evm,j721e-evm-ivi,j721e-idk-gw","Ivi shell test fails. Lib ivi-controller.so and other components are missing from the file system",""
   "LCPD-18214","dra7xx-evm","SGX-HW recovery seen with NV12 buffer usage with wayland-drm applications",""
   "LCPD-17817","am335x-hsevm,am43xx-epos,am43xx-hsevm,k2e-hsevm,k2g-hsevm,k2hk-hsevm,k2l-hsevm","Images created with Proc-SECDEV grow with number of times SECDEV has been used",""
   "LCPD-17659","am437x-idk","Disable GPU on AM437x IDK",""
   "LCPD-17449","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm","libasan_preinit.o is missing in devkit",""
   "LCPD-17413","am335x-evm,am43xx-gpevm,am57xx-evm,am654x-evm","QT Webengine-based browser: the mouse does not work within the web page with QPA EGLFS",""
   "LCPD-17412","am654x-evm","QT5 Webengine-based browser crashing with any resize operation",""
   "LCPD-17387","j721e-evm-ivi,j721e-idk-gw","Underflow and CRTC SYNC LOST observed while running GLMark2 (1x1080p + 1x4k)",""
   "LCPD-17304","j721e-evm,j721e-evm-ivi,j721e-idk-gw","Error Recovery Test for VDEC_ERROR_SR_ERROR does not trigger error",""
   "LCPD-17283","j721e-evm,j721e-evm-ivi,j721e-idk-gw","Running Gstreamer's gst-discoverer causes a crash",""
   "LCPD-16664","am654x-evm,am654x-idk","MMU Alloc errors and Kernel Oops with RT build",""
   "LCPD-16366","j721e-evm,j721e-evm-ivi,j721e-idk-gw","RGX kick test fails when 32 sync dependencies are set for each command",""
   "LCPD-16207","am574x-hsidk","Board does not boot sometimes due to crypto crash when debug options are enabled","None"
   "LCPD-16130","j721e-evm,j721e-evm-ivi,j721e-idk-gw","Exception triggered by drm_dev_unregister during poweroff",""
   "LCPD-15918","am43xx-gpevm,dra7xx-evm,k2g-evm,k2l-hsevm","ti-ipc-rtos gets stuck in xdctools",""
   "LCPD-15864","am57xx-evm","SoC Performance Monitoring tool is still not enabled",""
   "LCPD-15794","am57xx-evm,dra71x-evm,dra72x-evm,dra76x-evm,dra7xx-evm","Allow non-root user access to graphics resources to enable graphics use case",""
   "LCPD-15410","dra7xx-evm","vdd_shv_power is ~200mw higher than on previous lts",""
   "LCPD-15367","am335x-evm,am574x-idk","Boot time increased about 15s ",""
   "LCPD-14254","am654x-evm,am654x-idk","meta-ti: Need a recipe update to pick up the new AM65x PRU Ethernet firmwares",""
   "LCPD-13947","am335x-evm","nativesdk-opkg is broken in the devkit",""
   "LCPD-13817","am654x-evm","Qt5 Webengine-based broswer does not work on AM654x with pagesize = 64k",""
   "LCPD-13816","am654x-evm","Chromium-wayland broswer does not work on AM654x with page size = 64k",""
   "LCPD-13443","am57xx-hsevm","Camera is not detected on AM572x-HSEVM",""
   "LCPD-12709","am43xx-hsevm","Boards resets when standby state is attempted ",""
   "LCPD-12405","am335x-evm,am335x-ice,am43xx-epos,am43xx-gpevm,am57xx-evm,dra71x-evm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2l-evm","Openssl certgen fails due to coredump in openssl_gen_cert.sh",""
   "LCPD-12270","dra72x-evm","VDD_SHV5 power consumption is ~ 200mw higher than on previous releases",""
   "LCPD-9923","am335x-evm,am43xx-gpevm,am57xx-evm,k2e-evm,k2g-evm,k2hk-evm,k2l-evm","Error message in boot log for K2 and AM platforms",""
   "LCPD-9616","am57xx-evm","QtCreator GDB (remote) debugging stops working since QT5.7.1","use GDB from Processor SDK 3.2"
   "LCPD-9364","am57xx-hsevm","There are SCM FW warnings during the am57xx-hsevm boot",""
   "LCPD-9254","am43xx-hsevm","Kernel warnings in boot for am437x-hsevm",""
   "LCPD-9006","am57xx-evm,dra72x-evm,dra7xx-evm","Some GLBenchmark tests fail to run",""
   "LCPD-8398","dra7xx-evm,dra7xx-hsevm","gsttestplayer: Reverse playback stops after next seek",""
   "LCPD-8352","am43xx-gpevm,am57xx-evm,dra7xx-evm","weston: stress testing with 75 concurrent instances of simple-egl leads to unresponsive HMI due to running out of memory","1. Restart Wayland application. 2. Restart board if Weston is killed by oom-killer"
   "LCPD-8345","am335x-evm,am437x-idk,dra7xx-evm,dra7xx-hsevm,k2e-evm,k2e-hsevm,k2hk-evm,k2l-evm","Board fails to start login console after waiting 3.5 minutes ( hard to reproduce, ~4/1000)","Restart the EVM"
   "LCPD-8210","am571x-idk,am572x-idk,am57xx-evm","QT Touchscreen interaction (Bear Whack) crash",""
   "LCPD-7255","am335x-evm,am335x-ice,am335x-sk,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am57xx-evm,beaglebone,beaglebone-black,beaglebone-black-ice,dra72x-evm,dra72x-hsevm,dra7xx-evm,dra7xx-hsevm,k2e-evm,k2g-evm,k2g-ice,k2hk-evm,k2l-evm","Telnet login takes too long (~40 seconds)","""Booting with rootfs mounted over NFS might cause ~40 seconds delay on telnet login because DNS entries might not be properly populated. To work around this issue, enter appropriate DNS server IP in resolv.conf. For example:   echo 'nameserver 192.0.2.2' > /etc/resolv.conf;"""
   "LCPD-7130","dra7xx-evm","KMSCube with video does not work",""
   "LCPD-7025","am43xx-gpevm","System takes more than 10 seconds to go from login prompt to system prompt","Automated tests need to account for this boot delay"

|


U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-24633","j721e-idk-gw","u-boot: j721e-sk: Update MAIN R5FSS cluster mode to Split-mode",""
   "LCPD-24628","am654x-evm,am654x-idk","am654x-idk DFU boot is failing",""
   "LCPD-24507","am64xx-evm,am64xx-hsevm,am64xx-sk","U-Boot command ""saveenv"" doesn't save env ",""
   "LCPD-24307","am335x-evm","U Boot: Kernel failed to boot 1 times out of one",""
   "LCPD-24115","j721e-idk-gw","j721e-idk-gw default mtdparts value in U-BOOT is wrong",""
   "LCPD-24108","j721e-evm,j721e-evm-ivi,j721e-idk-gw","U-Boot: TISCI config ring fail traces seen in OSPI boot mode on J721E",""
   "LCPD-23026","am64xx-evm","USB MSC Boot: USB controller not visible from u-boot",""
   "LCPD-23020","am64xx-evm","am64xx-evm: U-Boot PHY autonegotiation failed 2 out of 100 times",""
   "LCPD-22975","am654x-evm,am654x-idk","AM654x: 1Ghz & beyond caused boot hang on SR2.0",""
   "LCPD-22964","j721e-evm,j721e-evm-ivi,j721e-idk-gw,j7200-evm","U-Boot: PLL POSTDIV1 and POSTDIV2 clock parenting is reversed",""
   "LCPD-22904","j721e-idk-gw,j7200-evm","U-boot: Update EMIFtool for i2244:DDR: Valid stop value must be defined for write DQ VREF training",""
   "LCPD-22841","am64xx-evm,j721e-idk-gw,j7200-evm","Watchdog Timer test is failing ",""
   "LCPD-22512","j721e-evm,j7200-evm","Update dfu_alt_info_ospi to include flashing of PHY tuning data",""
   "LCPD-21986","j721e-idk-gw","j721e U-Boot DDR50 mode cannot be tested using the default image",""
   "LCPD-19871","j721e-idk-gw,j7200-evm","U-boot: Documentation: Combined Boot flow and SPL Rearch",""
   "LCPD-19776","j721e-idk-gw","j7: uboot: some socketed evms fail to boot",""
   "LCPD-19133","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk","Netconsole output corrupted when CONFIG_NETCONSOLE_BUFFER_SIZE >= 281",""
   "LCPD-18643","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk","U-Boot: AM335x/AM473x: Both SPI CS signals get asserted",""
   "LCPD-17789","j721e-idk-gw","UBOOT J7:  Could not see UFS device by scsi scan",""
   "LCPD-17770","am654x-evm,am654x-idk,am654x-hsevm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw","U-Boot: Fix order of MCU R5 shutdown depending on cluster mode",""
   "LCPD-17523","j721e-evm,j721e-idk-gw,j7200-evm","A72-SPL - Support to dump EEPROM to shared memory",""
   "LCPD-16696","am654x-evm,am654x-idk","U-Boot does not recognize SD-Card after re-insert/change",""
   "LCPD-16524","am654x-evm,am654x-idk,am654x-hsevm","Need to adjust RMW bit when using enabling ECC","None"
   "LCPD-15873","am654x-evm","There is no dtbo in u-boot for PCIe x1 + usb3 daughter card","None"
   "LCPD-15054","am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm","[u-boot] AM57xx phy_ctrl structures must be board-specific","None"
   "LCPD-14843","am654x-evm,am654x-idk","U-boot should support  default settings for netboot ","None"
   "LCPD-12348","dra71x-evm,dra72x-evm,dra76x-evm,dra7xx-evm","U-boot: MMC/SD: MMC erase fails with timeout",""
   "LCPD-11197","dra72x-evm","Uboot: Writing GPT partitions to emmc causing CACHE: Misaligned messages",""
   "LCPD-10726","am572x-idk,am57xx-evm","Update DDR3 emif regs structure for EMIF2 for the beagle_x15 board in U-Boot board file","None"
   "LCPD-8295","dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra7xx-evm,dra7xx-hsevm","vout1 pins missing manual i/o configuration",""
   "LCPD-7864","am335x-evm,am335x-ice,am335x-sk,am43xx-gpevm,am437x-idk,am437x-sk","U-Boot: Ethernet boot fails on AM335x and AM437x",""
   "LCPD-7776","dra7xx-evm,dra7xx-hsevm","U-boot: DRA7XX: secure boot fails on Rev-G J6 EVM",""
   "LCPD-7366","am335x-evm","uboot McSPI driver drives multiple chip selects simultaneously","None"

|


Linux Kernel Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround" 
   :widths: 5, 10, 70, 35

   "LCPD-24677","j721e-idk-gw","j721e-idk-gw PCI WIFI Tests Fail ",""
   "LCPD-24650","am43xx-gpevm","VPFE sensor capture fails",""
   "LCPD-24646","am335x-evm,am43xx-gpevm","POWERMGR_S_FUNC_RUNTIME is not enabled for ETH",""
   "LCPD-24645","am43xx-gpevm","power measurement, power performance data collected failing",""
   "LCPD-24644","am335x-evm,am43xx-gpevm,am654x-evm","weston service takes a long time to terminate",""
   "LCPD-24631","j721e-idk-gw,j721e-eaik","J721e-idk-gw H264 Decoder Support Test Gap",""
   "LCPD-24627","am64xx-evm","icssg_prueth: NULL pointer deference during remove",""
   "LCPD-24622","am64xx-evm","TCP Bidir",""
   "LCPD-24620","am64xx-evm","ETH-USB-LCD-ALSA-NAND-MMC-0001 Suspend/Resume with RTC Wakeup",""
   "LCPD-24615","j721e-hsevm","j721e-hsevm V1.1 fails to boot",""
   "LCPD-24605","am654x-evm,am654x-idk,am654x-hsevm","ICSSG: Not all TX timestamps are received",""
   "LCPD-24596","j721e-idk-gw","j721e-idk-gw MMC MOD tests fail ",""
   "LCPD-24595","j721e-idk-gw","j721e-idk-gw USB Suspend/Resume with RTC Wakeup fail ",""
   "LCPD-24593","am64xx-evm","am64xx-evm CAN_S_FUNC_MODULAR test failures",""
   "LCPD-24589","am57xx-evm","Performance on EVM as storage and ether port",""
   "LCPD-24541","am654x-evm","am65xx OSPI boot does not work",""
   "LCPD-24539","am654x-evm","am654x-evm CAL test fails on PG2.0 boards",""
   "LCPD-24538","am335x-evm","am335x-evm: intermittent boot failure on unhandled fault",""
   "LCPD-24521","am57xx-evm","DRM - switching different video modes",""
   "LCPD-24502","j721e-evm-ivi,j721e-idk-gw","j721e-evm-ivi Universal Planes fails ",""
   "LCPD-24491","j721e-evm,j721e-evm-ivi,j721e-idk-gw,j7200-evm","Docs: MMC/SD supported modes not documented properly for J721E/J7200",""
   "LCPD-24473","am64xx-evm","IPSEC_software_crypto_UDP_aes128_sha1_performance",""
   "LCPD-24467","am64xx-sk","am64xx-sk stress boot test files",""
   "LCPD-24463","am571x-idk,am572x-idk","HSR/PRP: Root cause NetJury issues with HSR/PRP with RBX and VDAN node",""
   "LCPD-24456","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j7am-evm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-vlab,j7200-evm,j7200-hsevm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm,k2l-hsevm,omapl138-lcdk,j721s2-evm,j721s2-hsevm,j7amp-evm,j7ae-evm,j7am-vlab,j7am-zebu,j7ae-zebu,j7aep-zebu,j7amp-vlab,j7amp-zebu,j721e-eaik,am62xx-evm,am62xx-sk,am62xx-hsevm,am62xx-vlab,am62xx-zebu,am62a-evm","Move IPC validation source from github to git.ti.com",""
   "LCPD-24451","am64xx-evm","CRYPTO_S_PERF_MD5",""
   "LCPD-24450","am654x-evm,am654x-idk,j721e-idk-gw,j7200-evm","j721e-idk-gw, j7200-evm UART tests fail ",""
   "LCPD-24433","am64xx-evm","ETH-USB-LCD-ALSA-NAND-MMC-0001 Suspend/Resume with RTC Wakeup",""
   "LCPD-24319","am654x-evm","am654x-evm DRM tests fail due to frequency mismatch ",""
   "LCPD-24301","am57xx-evm","Audio stereo S16_LE Channel swap",""
   "LCPD-24299","am335x-evm","DRM: Performance Test for xr24. Get fps for each format and connector",""
   "LCPD-24289","am64xx-evm,am64xx-sk,am654x-evm,am654x-idk","ICSSG Ethernet Docs Broken link to ICSS Eth docs",""
   "LCPD-24287","am335x-evm,am43xx-gpevm,am43xx-hsevm,am57xx-evm","POWERMGR_S_FUNC_RUNTIME_SERIAL pm_runtime is not suspending",""
   "LCPD-24285","am43xx-gpevm","Assertion for HDMI with Audio playback tests are failing",""
   "LCPD-24284","am654x-evm","DRM tests fail due to crash in panel_simple_probe",""
   "LCPD-24252","am57xx-evm","VPE M2M operation failed",""
   "LCPD-24239","am335x-evm,am43xx-gpevm,am574x-idk,am57xx-evm","IPC performance  test",""
   "LCPD-24199","am654x-evm","AM654x UART HWFLOW FUNC, PERF, STRESS tests fail ",""
   "LCPD-24192","j721e-idk-gw","J721E: Fix Video decoder documentation",""
   "LCPD-24182","am335x-evm,am57xx-evm,beaglebone-black","Powermgr_xs_func_simple_suspend/standby resume tests",""
   "LCPD-24171","am654x-evm","Display driver for parallel port: CTRLMMR_DSS_CLKSEL register write enablement",""
   "LCPD-24168","am64xx-sk","MCU GPIO Pins not working on AM64x SK",""
   "LCPD-24142","j721e-hsevm,j721e-idk-gw","J721e: Issue with OSPI probe in kernel when booting from OSPI boot mode",""
   "LCPD-24134","am654x-evm","AM654x CAL DMABUF tests fail ",""
   "LCPD-24125","j721e-idk-gw","j721e-idk-gw all LE play + record tests fail ",""
   "LCPD-24121","am64xx-evm,am64xx-sk","IPC SDK docs: link to example source code",""
   "LCPD-24104","am335x-evm","nandtest util crashes NAND ubifs filesystem",""
   "LCPD-23102","am64xx-sk","AM64-SK: DMA is not stable",""
   "LCPD-23096","am335x-ice","PTP broken with PRU-ETH on AM335x ICEv2",""
   "LCPD-23066","am64xx-sk","am64x-sk :gpio: direction test fail",""
   "LCPD-23061","am572x-idk","AM572 : Kernel hangs when trying to access PRU Debug register space",""
   "LCPD-23010","j721e-idk-gw","j721e-idk-gw stress boot test files",""
   "LCPD-23008","am654x-evm","AM65xx - display port scenario not enabled",""
   "LCPD-23007","am654x-evm","k3-am654-evm-hdmi.dtbo file is missing in CoreSDK for am654x",""
   "LCPD-22959","am654x-evm","UART Read/Write tests at baud rate 115200 fails",""
   "LCPD-22954","am654x-evm","DRM Stress Test fails",""
   "LCPD-22953","am654x-evm","v4l2 cal compliance test fails",""
   "LCPD-22947","am654x-evm","Alsa performance test fails",""
   "LCPD-22931","am64xx-evm,am64xx-sk,am654x-evm,am654x-idk,dra72x-evm","RemoteProc documentation missing",""
   "LCPD-22916","am654x-evm,am654x-idk","CSI: Interface Setup/Hold Timing Does Not Meet MIPI DPHY Spec above 600MHz",""
   "LCPD-22912","am64xx-evm","am64xx-evm SMP dual core test fails sporadically",""
   "LCPD-22910","am571x-idk,am572x-idk","Boundary Clock jitter exceeds 800us when SV traffic is added to setup",""
   "LCPD-22892","am64xx-evm,am654x-evm,am654x-idk","icssg: due to FW bug both interfaces has to be loaded always",""
   "LCPD-22861","j721e-hsevm","Missing documentation for HS devices",""
   "LCPD-22834","am64xx-evm","am64xx-evm stress boot test fails",""
   "LCPD-22748","am437x-idk","Kernel Panic after shutdown of kernel",""
   "LCPD-22715","j721e-idk-gw,j7200-evm,j721s2-evm,am62xx-evm","i2232: DDR: Controller postpones more than allowed refreshes after frequency change","Workaround 1:
   Disable dynamic frequency change by programing DFS_ENABLE = 0


      DFS_ENABLE = 0


   Workaround 2:
   If switching frequency, program the register field values as follows::

      if (old_freq/new_freq >= 7) {
         if (PBR_EN==1) {  // Per-bank refresh is enabled
               AREF_HIGH_THRESHOLD = 19
               AREF_NORM_THRESHOLD = 18
               AREF_PBR_CONT_EN_THRESHOLD = 1
               AREF_CMD_MAX_PER_TREF = 8
         }
         else {  // Per-bank refresh is disabled
               AREF_HIGH_THRESHOLD = 18
               AREF_NORM_THRESHOLD = 17
               AREF_CMD_MAX_PER_TREF = 8
         }
      } else {
         AREF_HIGH_THRESHOLD = 21
         AREF_CMD_MAX_PER_TREF = 8
      }
   "
   "LCPD-22541","am335x-ice,am437x-idk","Kernel crash while running docker example",""
   "LCPD-22538","am335x-evm","Remove transparency color keying and alpha blending feature from documentation",""
   "LCPD-22513","j721e-evm,j7200-evm","Update SDK doc to include OSPI flashing instruction using dfu-util",""
   "LCPD-22417","am335x-evm","No throughput on ipsec aes128 hardware test",""
   "LCPD-22413","j7200-evm","Hyperflash tests fail ~50% of the time on j7200",""
   "LCPD-22339","j721e-idk-gw,j7200-evm","PCI-E USBCARD, ETHCARD don't indicate 2-lane support with lspci",""
   "LCPD-22319","am64xx-evm,j7200-evm","OpenSSL performance test data out of bounds",""
   "LCPD-22215","am64xx-evm","PCIE NVM card stops enumerating on am64xx after some time",""
   "LCPD-21963","am571x-idk,am572x-idk,am574x-idk","AM5726 hangs during PRU initialization",""
   "LCPD-20705","am64xx-evm","USB stick attached to PCIe USB card is not enumerated",""
   "LCPD-20691","am654x-evm","AM65xx - lcd backlight scenario not enabled ",""
   "LCPD-20683","am654x-evm","am65xx fails emmc boot",""
   "LCPD-20653","am335x-evm,am43xx-gpevm,am654x-idk,j721e-idk-gw","ltp: kernel syscall tests fail",""
   "LCPD-20558","am64xx-sk","OSPI UBIFS tests failing on am64xx-sk",""
   "LCPD-20290","j721e-idk-gw","CPSW Performance regression on j721e-idk-gw",""
   "LCPD-20240","j721e-idk-gw","MMC Modular testcase regression",""
   "LCPD-20105","am64xx-evm","AM64x: Kernel: ADC: RX DMA channel request fails",""
   "LCPD-20061","am64xx-evm","Occasional PHY error during during TSN Time-Aware Shaper execution",""
   "LCPD-20014","am654x-evm,am654x-idk,am654x-hsevm","remoteproc: TX_PRU: IRQ vring, IRQ kick not found error message on console",""
   "LCPD-20006","am64xx-evm","AM64x: remoteproc may be stuck in the start phase after a few times of stop/start",""
   "LCPD-19929","am654x-evm","Industrial protocols documentation",""
   "LCPD-19923","am654x-evm,am654x-idk","[AM65x] Linux reboot command fails","https://e2e.ti.com/support/processors-group/processors/f/processors-forum/1011070/am6548-linux-reboot-command-fails"
   "LCPD-19861","am654x-evm","ICSSG: Unregistered multicast MAC packets are still visible in non-promiscuous mode",""
   "LCPD-19859","am654x-evm","ETH ICSSG netperf benchmark returns lower performance than expected",""
   "LCPD-19792","j721e-idk-gw","j721e boot fails sometimes due to EL1 exception",""
   "LCPD-19757","am335x-evm","OpenSSL DES performance numbers are lower in 07.01",""
   "LCPD-19660","am335x-ice,am437x-idk,am571x-idk,am572x-idk,am574x-idk","Remove unused definitions and related code for SV frame MAC address",""
   "LCPD-19659","j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm","Doc: PCIe: Update documentation to indicate how to move to compliance mode",""
   "LCPD-19580","am654x-evm","am654- unable to select a mode (sdhci?)",""
   "LCPD-19499","j7200-evm,j7200-hsevm","Kernel: OSPI write throughput is less than 1MB/s",""
   "LCPD-19497","j7200-evm","J7200: CPSW2g: interface goes up and down sporadically","Seen only on very few EVMs. No workaround. "
   "LCPD-19260","am571x-idk","PRUETH: Single EMAC doesn't ping with ICSS-1 Port 2 (MII-1)",""
   "LCPD-19084","j721e-idk-gw","Few SD cards not enumerating in Kernel with Alpha EVM",""
   "LCPD-19068","j721e-evm,j721e-evm-ivi,j721e-idk-gw","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame",""
   "LCPD-19043","am571x-idk,am572x-idk,am574x-idk,am57xx-evm,am57xx-beagle-x15,dra71x-evm,dra72x-evm,dra76x-evm,dra7xx-evm","kernel: dtbs_check command cannot be run with dtb-merge changes","Please see the suggestion in
   https://jira.itg.ti.com/browse/LCPD-19043?focusedCommentId=1696111&page=com.atlassian.jira.plugin.system.issuetabpanels:comment-tabpanel#comment-1696111"
   "LCPD-18860","am654x-evm,am654x-idk,j721e-idk-gw","isolcpus in the command line is not honored",""
   "LCPD-18854","am64xx-evm,dra71x-evm,dra76x-evm","ov5640 sensor capture fails for raw format capture",""
   "LCPD-18790","j721e-idk-gw","eMMC tests failed on J7 rev E2 EVM",""
   "LCPD-18684","am57xx-evm,am654x-evm,j721e-idk-gw","syscalls sync failures: fdatasync03, fsync04, sync03, syncfs01, sync_file_range02",""
   "LCPD-18665","am654x-evm,am654x-idk","Am65x Pg2: Board cannot do soft reboot when booting from SD card",""
   "LCPD-18353","dra7xx-evm","falcon boot does not work",""
   "LCPD-18297","am654x-evm","AM6: OV5640: 176x144 does not work",""
   "LCPD-18289","am654x-evm,k2g-evm","pcie-usb tests sometimes fail",""
   "LCPD-18258","am654x-evm,j721e-idk-gw","IPSEC perfomance failures",""
   "LCPD-18228","am654x-evm","PCI PM runtime suspend is not increasing",""
   "LCPD-18227","am57xx-evm,dra7xx-evm","cam and  vpe could not suspend",""
   "LCPD-18109","am571x-idk,am572x-idk,am574x-idk","am5xx-idk: pruss: ""l4per-clkctrl:0040:0: failed to disable"" on prueth removal",""
   "LCPD-18020","dra72x-evm","fatwrite failed to write ipu firmware to boot partition on dra72",""
   "LCPD-17908","am654x-evm,am654x-idk","ICSSG: dual-emac: udp packets ocassionally sent out of order on egress",""
   "LCPD-17814","j721e-idk-gw","Kingston 16G card could not boot to uboot prompt",""
   "LCPD-17800","am654x-evm,am654x-idk","CPSW: Master/Slave resolution failed message seen at console",""
   "LCPD-17798","am654x-evm,am654x-idk,j7am-evm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-vlab,j7200-evm,j7200-hsevm","2020 LTS: INTA/INTR smp_affinity failure and IRQ allocation issues.",""
   "LCPD-17794","j721e-idk-gw","ext4write failed to write firmware to SD card",""
   "LCPD-17790","am335x-evm","AM335x: USB Device: 15% performance drop",""
   "LCPD-17777","am654x-evm","AES HW is not exercised",""
   "LCPD-17673","am335x-evm,am43xx-gpevm,am571x-idk,am572x-idk,am574x-idk,am57xx-evm,am654x-evm,beaglebone-black,dra71x-evm,dra72x-evm,dra7xx-evm,j721e-evm","No software documentation for the Timer module",""
   "LCPD-17543","j721e-evm,j721e-evm-ivi,j721e-idk-gw","Some cpuhotplug tests failed",""
   "LCPD-17471","am654x-evm,am654x-idk","device hang when restarting crashed R5F",""
   "LCPD-17421","j721e-idk-gw","CPSW9G: Can't bring up interface over NFS",""
   "LCPD-17387","j721e-evm-ivi,j721e-idk-gw","Underflow and CRTC SYNC LOST observed while running GLMark2 (1x1080p + 1x4k)",""
   "LCPD-17373","dra71x-hsevm,dra72x-hsevm,dra76x-hsevm,dra7xx-hsevm","ARM Exception from PPA Signature Verification Call on HS Device","""In our SDK solution OP-TEE replaces the Secure ROM. OP-TEE does not use the Crypto HWA so we let the kernel manage and disable/enable them as needed. If one would like to continue using the Secure ROM then, as you have figured out in the description, you need to add the Crypto HWAs to the list of non-hwmod controlled devices (like we do for TRNG and GPTIMER12 that OP-TEE does use). We cant do this by default as our default configuration is to let the kernel crypto driver use these devices."""
   "LCPD-17284","j721e-evm,j721e-evm-ivi,j721e-idk-gw","remoteproc/k3-r5: Cores are started out-of-order when core 0 file size >> core 1 file size",""
   "LCPD-17172","j721e-idk-gw","Uboot USBhost: Sandisk Extreme USB 3.0 msc stick could not be detected at second time",""
   "LCPD-17171","j721e-idk-gw","Uboot dhcp occasionally failed",""
   "LCPD-17113","j721e-idk-gw","[Cpsw9g][VirtualDriver][VirtualMAC] rpmsg_kdrv_switch is not autoloaded",""
   "LCPD-17017","j721e-evm-ivi,j721e-idk-gw","J7: DSS underflows seen on various use cases",""
   "LCPD-16845","am654x-evm,am654x-idk","OPP freq update in DT impacts only cluster0",""
   "LCPD-16836","j721e-idk-gw","DP: GeChic display EDID read failures with custom DP cable",""
   "LCPD-16642","am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm","omapdrm: in some cases, DPI output width does not need to be divisible by 8",""
   "LCPD-16640","j721e-idk-gw","PCIe RC: GIC ITS misbehaves when more than 4 devices use it simultaneously",""
   "LCPD-16628","j721e-idk-gw","Could not enumerate PLEXTOR pcie SSD",""
   "LCPD-16594","dra7xx-evm","Seeing kernel traces during pcie wifi tests",""
   "LCPD-16591","j721e-idk-gw","PCIe wifi ping stress test failed",""
   "LCPD-16545","j721e-evm,j721e-evm-ivi,j721e-idk-gw","remoteproc/k3-r5f: PDK IPC echo_test image fails to boot up in remoteproc mode on second run",""
   "LCPD-16535","j721e-evm,j721e-evm-ivi,j721e-idk-gw","remoteproc/k3-dsp: PDK IPC echo test binaries fails to do IPC in remoteproc mode on second run",""
   "LCPD-16534","am654x-evm,am654x-idk","remoteproc/k3-r5f: PDK IPC echo_test image fails to do IPC in remoteproc mode on second run","None"
   "LCPD-16437","am335x-evm","Nand with prefetch dma: read perf drop ~20% comparing to 2018",""
   "LCPD-16396","j721e-evm,j721e-evm-ivi,j721e-idk-gw","J721E: RC: Unsupported request in configuration completion packets results in an abort","Workaround for Multifunction: Configure all the physical functions supported by the endpoint. For configuring all the 6 functions of PCIe  controller instance '1' in J721E, the following can be used::
   
      mount -t configfs none /sys/kernel/config; 
      cd /sys/kernel/config/pci_ep/; 
      mkdir functions/pci_epf_test/func1; 
      echo 0x104c > functions/pci_epf_test/func1/vendorid; 
      echo 0xb00d > functions/pci_epf_test/func1/deviceid; 
      echo 1 > functions/pci_epf_test/func1/msi_interrupts; 
      echo 16 > functions/pci_epf_test/func1/msix_interrupts; 
      ln -s functions/pci_epf_test/func1 controllers/d800000.pcie-ep/; 
      mkdir functions/pci_epf_test/func2; 
      echo 0x104c > functions/pci_epf_test/func2/vendorid; 
      echo 0xb00d > functions/pci_epf_test/func2/deviceid; 
      echo 1 > functions/pci_epf_test/func2/msi_interrupts; 
      echo 16 > functions/pci_epf_test/func2/msix_interrupts; 
      ln -s functions/pci_epf_test/func2 controllers/d800000.pcie-ep/; 
      mkdir functions/pci_epf_test/func3; 
      echo 0x104c > functions/pci_epf_test/func3/vendorid; 
      echo 0xb00d > functions/pci_epf_test/func3/deviceid; 
      echo 1 > functions/pci_epf_test/func3/msi_interrupts; 
      echo 16 > functions/pci_epf_test/func3/msix_interrupts; 
      ln -s functions/pci_epf_test/func3 controllers/d800000.pcie-ep/; 
      mkdir functions/pci_epf_test/func4; 
      echo 0x104c > functions/pci_epf_test/func4/vendorid; 
      echo 0xb00d > functions/pci_epf_test/func4/deviceid; 
      echo 1 > functions/pci_epf_test/func4/msi_interrupts; 
      echo 16 > functions/pci_epf_test/func4/msix_interrupts; 
      ln -s functions/pci_epf_test/func4 controllers/d800000.pcie-ep/; 
      mkdir functions/pci_epf_test/func5; 
      echo 0x104c > functions/pci_epf_test/func5/vendorid; 
      echo 0xb00d > functions/pci_epf_test/func5/deviceid; 
      echo 1 > functions/pci_epf_test/func5/msi_interrupts; 
      echo 16 > functions/pci_epf_test/func5/msix_interrupts; 
      ln -s functions/pci_epf_test/func5 controllers/d800000.pcie-ep/; 
      mkdir functions/pci_epf_test/func6; 
      echo 0x104c > functions/pci_epf_test/func6/vendorid; 
      echo 0xb00d > functions/pci_epf_test/func6/deviceid; 
      echo 1 > functions/pci_epf_test/func6/msi_interrupts; 
      echo 16 > functions/pci_epf_test/func6/msix_interrupts; 
      ln -s functions/pci_epf_test/func6 controllers/d800000.pcie-ep/; 
      echo 1 > controllers/d800000.pcie-ep/start; 
      echo 1 > /sys/bus/pci/devices/0000:00:00.0/remove; 
      echo 1 > /sys/bus/pci/rescan; 
      
   Workaround for switch card: No workarounds available."
   "LCPD-16048","am654x-evm,am654x-idk","UDP iperf with smaller packet sizes < 512 bytes does not complete consistently",""
   "LCPD-15819","am654x-evm","tidss: the driver should reject dual-display setup, as it is not supported",""
   "LCPD-15787","am335x-evm","Power suspend fails due to USB (scsi_bus_suspend) failure when HDD is in use",""
   "LCPD-15649","am57xx-evm","Uboot: sata could not be detected ",""
   "LCPD-15648","am335x-evm","Uboot mmc write performance decreased",""
   "LCPD-15635","dra71x-evm","mmc hotplug causes one board reboot",""
   "LCPD-15540","am57xx-evm,am654x-evm,dra71x-evm,dra7xx-evm","uvc-gadget results in segmentation fault",""
   "LCPD-15461","dra7xx-evm","pcie usb failed to enumerate sometimes on dra7xx",""
   "LCPD-15402","am571x-idk,am572x-idk,am574x-idk,am57xx-evm,am57xx-beagle-x15,dra71x-evm,dra72x-evm,dra76x-evm,dra7xx-evm","rpmsg-rpc: test application does not bail out gracefully upon error recovery",""
   "LCPD-15400","am571x-idk,am572x-idk,am574x-idk,am57xx-evm,am57xx-beagle-x15,dra71x-evm,dra72x-evm,dra76x-evm,dra7xx-evm","remoteproc/omap: System suspend fails for IPU1 domain without any remoteprocs loaded",""
   "LCPD-14855","am335x-evm,am335x-ice,am335x-sk","omap_i2c_prepare_recovery() function can Lock System",""
   "LCPD-14171","am57xx-evm,dra7xx-evm","Failed to read uboot from SD card 1/1000 times",""
   "LCPD-13938","am654x-evm,dra71x-evm,dra7xx-evm,k2g-evm","PCIe EP read/write/copy test failed with larger sizes ",""
   "LCPD-13936","am654x-evm","Uboot dhcp timeout 1 of 100 times",""
   "LCPD-13720","beaglebone-black","SPI DMA TX Mode Halts During Continuous 16/32/64 bit Transfers ",""
   "LCPD-13653","am654x-evm,am654x-idk","am65x-evm could not boot from MMC/SD when MMC/SD is backup boot mode","No workaround"
   "LCPD-13603","am654x-evm","One board could not boot rootfs from more than one SDHC card",""
   "LCPD-13478","dra76x-evm","kexec fails on some setups",""
   "LCPD-13458","dra76x-evm","MCAN FIFO errors seen in receive CANFD tests",""
   "LCPD-13445","am654x-evm","Seldom kernel oops triggered by prueth_netdev_init",""
   "LCPD-13412","am57xx-evm","VIP camera sensor (mt9t11) is not initialized properly",""
   "LCPD-13410","am654x-evm,am654x-idk","Reboot command is not operational",""
   "LCPD-12777","dra72x-evm","PCIe link is not up for Inateck pcie-usb card",""
   "LCPD-12718","dra7xx-evm","8250: serialcheck external loop back testing failure",""
   "LCPD-12423","dra72x-evm","PCIe fails to reach suspend target state sometimes ",""
   "LCPD-12392","am335x-evm","USBhost video: higher resolution tests fail with some cameras",""
   "LCPD-12273","dra7xx-evm","i2c controller timed out during DVFS",""
   "LCPD-12226","am43xx-gpevm,am574x-idk,am57xx-evm,omapl138-lcdk","mmcsd first write perf decreased on some platforms",""
   "LCPD-11952","am571x-idk,dra72x-evm","AM57x: disabling USB super-speed phy in DT causes kernel crash",""
   "LCPD-11564","am57xx-evm","AM57xx-evm: eth1 1G connection failure to netgear switch",""
   "LCPD-11138","am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,dra7,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm","VIP driver multi-channel capture issue with TVP5158",""
   "LCPD-10997","dra76x-evm","ABB voltage did not increase for 1800 MHz",""
   "LCPD-10974","am43xx-gpevm","am43xx-gpevm - usb camera gadget shows halting frames","None"
   "LCPD-10707","dra76x-evm,dra7xx-evm","Few PCIe cards could not enumerated on dra7xx and dra76x",""
   "LCPD-10221","am335x-evm","Longer resume times observed on setup with usb device cable",""
   "LCPD-9974","am571x-idk","PCIe x2 width is not at expected width on am571x-idk",""
   "LCPD-9589","am335x-evm","I2C: Sometimes i2c read write failed on farm01 and farm02",""
   "LCPD-9527","am335x-evm,am335x-sk,beaglebone,beaglebone-black","Potential deadlock reported by pm_suspend on am335x",""
   "LCPD-9481","am571x-idk,am572x-idk,am57xx-evm,am57xx-hsevm","Sometime the system hangs while loading the rpmsg rpc modules",""
   "LCPD-9466","am57xx-evm,dra7xx-evm","SATA PMP causes suspend failures",""
   "LCPD-9455","am335x-evm","Kernel Warning reported for a USB audio device when listing with pulseaudio",""
   "LCPD-9402","dra72x-evm","DRA72x: HDMI display EDID read fails on Rev B EVM","Add the required HDMI modes into the kernel binary as per instructions in http://lxr.free-electrons.com/source/Documentation/EDID/"
   "LCPD-9372","am335x-evm","Nand stress tests failed on a particular am335x-evm board",""
   "LCPD-9284","dra7xx-evm","DRA7xx: HDMI starting with non-preferred mode on boot",""
   "LCPD-9222","am572x-idk","PRUSS Ethernet does not work on AM572x ES1.1",""
   "LCPD-9027","dra71x-evm,dra72x-evm,dra7xx-evm","There is some warning regarding spi_flash_read when do ubimkvol",""
   "LCPD-8822","dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra7xx-evm,dra7xx-hsevm","rpmsg: fix memory leak in case of announce failure in device probe",""
   "LCPD-8636","am335x-evm,dra72x-evm,dra7xx-evm","Serial corruption being seen in kernel",""
   "LCPD-8550","am335x-sk","CPSW memory allocation errors seen during boot",""
   "LCPD-8350","am57xx-evm","UART boot does not work on am57xx-evm",""
   "LCPD-8336","am43xx-hsevm","Soft reboot does not work on am43xx-hsevm rev1.5b",""
   "LCPD-8133","am335x-evm","USB: ""cannot reset"" errors observed sometimes",""
   "LCPD-8078","am335x-sk","AM3 SK: Touchscreen isn't responsive",""
   "LCPD-8000","dra7xx-evm,dra7xx-hsevm","VIP: RGB: RGB capture error due to wrong data path setting",""
   "LCPD-7998","am572x-idk","Realtime OSADL Test results degraded slightly for am572x-idk",""
   "LCPD-7955","am335x-evm,am43xx-gpevm,k2e-evm,k2g-evm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm","Uncorrectable Bitflip errors seen after switch to SystemD","Workaround to erase the NAND flash completely if flashed with an incompatible flash writer. SystemD tries to mount all partitions and that is the reason this is being seen now."
   "LCPD-7829","am57xx-evm","uboot: UHS card did not work on the expected speed in uboot",""
   "LCPD-7744","am57xx-evm","UHS SDR104 card works on different speed after soft reboot",""
   "LCPD-7735","am57xx-evm,dra71x-evm,dra71x-hsevm,dra72x-evm,dra7xx-evm","Powerdomain (vpe_pwrdm) didn't enter target state 0",""
   "LCPD-7705","dra7xx-evm,dra7xx-hsevm","DRA7X: SATA: specific Port multiplier (JMicron) connected to dra7x enumerates at 1.5Gbps","None"
   "LCPD-7697","dra7xx-evm,dra7xx-hsevm","OV1063x configuration breaks if kernel is compiled with CONFIG_DEBUG_GPIO=n","Enable the CONFIG_DEBUG_GPIO"
   "LCPD-7696","am571x-idk,am572x-idk,am57xx-evm,am57xx-hsevm,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra7xx-evm,dra7xx-hsevm","DRA7xx: VPE: File2File checksum changes across multiple runs","There is no workaround for this issue yet"
   "LCPD-7695","dra7xx-evm","DRA7xx: building Ov1603x as a module causes a green tint in captured image","The workround is to use the camera driver as builtin. Also, a delay of 1s can stop this issue from occuring"
   "LCPD-7575","dra72x-evm","PCIe-USB card sometime could not be detected",""
   "LCPD-7374","dra72x-evm,dra7xx-evm","DRA7x: Transcend 16G UHS card enumerated as SDR104 but there are errors showing up",""
   "LCPD-7323","dra72x-evm","Inconsistent resuts in power measurement during suspended mode",""
   "LCPD-7314","am335x-evm","Active power is slighly higher than on 2015 LTS release (Linux 4.1)",""
   "LCPD-7293","dra7xx-evm","[rpmsg 2016 LTS] ALL: iommu/remoteproc: _wait_target_disable failed trace",""
   "LCPD-7265","am57xx-evm","Uboot eMMC does not use HS200 on am57xx-gpevm",""
   "LCPD-7256","am335x-evm,am335x-hsevm,am57xx-evm,dra72x-evm,dra7xx-evm","Board sometimes hangs after suspend/resume cycle",""
   "LCPD-7188","am57xx-evm,dra72x-evm,dra7xx-evm","PCIe-SATA test failed","TI custom board would help with signal integrity issues being seen with the EVM."
   "LCPD-7147","dra72x-evm,dra7xx-evm","Intel LAN Card D33745 could not enumerated on J6",""
   "LCPD-7065","dra72x-evm,dra7xx-evm","PCIe-sata: Samsung SSD 120G harddisk could not enumerated",""
   "LCPD-6301","dra72x-evm,dra7xx-evm","J6: A few SDR104 cards only enumerated as high speed card when use them as rootfs",""
   "LCPD-6300","am57xx-evm","am57xx-evm: A few UHS cards could not be numerated in kernel and mmc as rootfs failed.",""
   "LCPD-6120","dra7xx-evm","Ethernet Link not stable at 1G on Rev G DRA74x EVMs",""
   "LCPD-6075","am572x-idk,am57xx-evm,dra7xx-evm","BUG: using smp_processor_id() in preemptible [00000000] code during remoteproc suspend/resume",""
   "LCPD-5522","am571x-idk,am572x-idk,am57xx-evm,am57xx-hsevm,dra72x-evm,dra72x-hsevm,dra7xx-evm,dra7xx-hsevm","pcie-usb sometimes the usb drive/stick could not be enumerated",""
   "LCPD-5521","dra7xx-evm","Sporadic boot failure using debug image (~ 1/50)",""
   "LCPD-5362","am335x-evm","MUSB: Isoch IN only utilises 50% bandwidth",""
   "LCPD-4503","dra7xx-evm","ALL: 8250 UART driver not enabeld as wake source by default",""
   "LCPD-1245","am335x-evm","AM335x: Power: Reverse current leakage on poweroff",""
   "LCPD-1239","am572x-idk,am57xx-evm,dra72x-evm,dra7xx-evm","Connectivity: DUT could not resume when PCI-SATA card is in",""
   "LCPD-1207","am43xx-gpevm,am57xx-evm,dra7xx-evm","AM43XX/AM57XX/DRA7: CONNECTIVITY: dwc3_omap on am43xx and xhci_plat_hcd on dra7 - removal results in segmentation fault",""
   "LCPD-1191","am335x-evm","AM335x: Power: System resumes due to wakeup source USB1_PHY without any external trigger","Use GPIO interrupt instead of USB PHY for wakeup source."
   "LCPD-1106","am57xx-evm,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra7xx-evm,dra7xx-hsevm","Connectivity:PCIe-SATA ext2 1G write performance is poor due to ata failed command","None"
   "LCPD-1067","dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra7xx-evm,dra7xx-hsevm","J6: PCIe: Broadcom Ethernet cards cause kernel to hang after suspend/resume cycle",""
   "LCPD-885","dra7xx-evm","J6/J6eco: suspend-to-ram: l3init: USB clocks are active",""
   "LCPD-816","dra72x-evm,dra7xx-evm","J6/J6eco:Connectivity:PCIe-PCI eth bridge doesn't work on J6/J6eco",""
   "LCPD-799","dra7xx-evm","J6 and J6ECO: CONNECTIVITY: Backtrace during disconnect of usb camera during iso transaction",""

|


Linux RT Kernel Known Issues
----------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround" 
   :widths: 5, 10, 70, 35

   "LCPD-24288","am64xx-evm,am654x-idk","am64xx-evm NCM/ACM network performance test crashes with RT images",""
