************************************
Release Notes
************************************
.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Release_Notes

Overview
========

The **Processor-CoreSDK for Linux**
provides a fundamental software platform for development, deployment and
execution of Linux based applications and includes the following:

  * Bootloaders & Filesystems.
  * Prebuilt Binaries.
  * Detailed Release Notes.

Licensing
=========

Please refer to the software manifest, which outlines the licensing
status for all packages included in the prebuilt binaries location.


Release 09.01.00
================

Released October 2023

.. rubric:: What's New
   :name: whats-new

**Processor SDK 9.0 Sitara Release supports the following platforms**

  * AM62SIP 2.0 (HS-FS, HS-SE)

**Processor SDK 9.0 Sitara Release has following Major Updates**

  * LTS Refresh with Stable Kernel 6.1, U-boot 2023.04, Yocto Dunfell 4.0
  * Binman Migration
  * HS-FS Default Boot Experience
  * Graphics: Weston 10 and DDK 23.1 Upgrade
  * Multimedia: Gstreamer v1.20.5 Upgrade


Release 09.00.00
==================

Released July 2023

.. rubric:: What's New
   :name: whats-new

**Processor SDK 9.0 Sitara Release supports the following platforms**

  * AM64x 2.0 (HS-FS)
  * AM62x (GP, HS-FS, HS-SE)
  * AM62x LP (HS-FS, HS-SE)
  * AM62A (HS-FS, HS-SE)

**Processor SDK 9.0 Sitara Release has following Major Updates**

  * LTS Refresh with Stable Kernel 6.1, U-boot 2023.04, Yocto Dunfell 4.0
  * Binman Migration
  * HS-FS Default Boot Experience for AM64, AM62, AM62A, AM62 LP
  * Graphics: Weston 10 and DDK 23.1 Upgrade
  * Multimedia: Gstreamer v1.20.5 Upgrade

**AM62A**

  * U-Boot: Remoteproc boot with C7x
  * Kernel: E5010 JPEG Encoder
  * Low Power: DFS and CPUIdle on HS FS
  * Camera: V4L2 multi-stream controls

**AM62**

  * Uboot: A53 Early splash screen and bmp display
  * Low Power: Deep Sleep mode: HS FS Support, Main IO Daisychain support, Remoteproc with M4 and R5 Cores
  * Low Power: Wakeup Sources: MCU GPIO, Main I/O Daisy wakeup, MCU M4 IPC Wakeup
  * Low Power: DFS and CPUIdle on HS FS
  * Low Power: MCU Only mode
  * Kernel: Multi MCAN
  * IPC: A53 --> DM R5
  * Camera: Libcamera support
  * Audio: Recording bug-fixes

**AM64**

  * Bug Fixes and Stability Improvements
  * PRU-ICSSG: HSR Port-to-Port offload , Switch Mode, Multicast filtering in EMAC mode, Tx/Rx coalescing and Dump IET Statistic via ethtool

**AM65**

  * PRU-ICSSG: Multicast filtering in EMAC mode, Tx/Rx coalescing and Dump IET Statistic via ethtool


Build Information
=====================================

U-Boot
-------------------------
| Head Commit: 9390b636e8e292a85f236b4f1c70feb0ad8299cc arm: dts: k3-am64-main: Add ITAP delay values in Device Tree"
| Date: 2023-10-07 06:39:59 -0500
| uBoot Version: 2023.04
| uBoot Description: 09.00.00.011
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2023.04
| uBoot Tag: 09.00.00.011
|


Kernel
-------------------------
.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 	3ec3755134e2a6c107b43e335fa32c958a2fe5f6 Revert "HACK: arm64: dts: ti: k3-j721s2-common-proc-board: Disable DSI"
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

| Head Commit: 	4a3a5f9a7567d507b37b51980516ce26b34b353e Merge branch 'ti-linux-6.1.y-cicd' of git://git.ti.com/ti-linux-kernel/ti-linux-kernel into ti-rt-linux-6.1.y-cicd
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
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 	5fd6a816470feefc9c58c5d3ae1b2fb93bead787 linux-ti-staging_6.1: CI/CD Auto-Merger: cicd.kirkstone.202310061657
| Date: 2023-10-07 06:40:00 -0500

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: kirkstone
| Release Tag: 09.00.00.011
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: 	08c9b5656f2d514f27ba580afdc2cd937ce059e4 arago-gpl-notice: Update script to look for updated GPL-3.0 identifier
| Date: 2023-10-07 06:39:40 -0500

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: kirkstone
| Release Tag: 09.00.00.011
|

Issues Tracker
=====================================

Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
  :header: "Record ID", "Platform", "Title"
  :widths: 15, 70, 20

  "LCPD-35033","am64xx-hsevm","AM64: ICSSG VLAN testcase is failing in 9.0-rc6",""
  "LCPD-34994","am64xx-hsevm","AM64x: fitImage not booting",""
  "LCPD-34992","am64xx-hsevm","AM64x DFU Boot fails with signed images",""
  "LCPD-34980","am62axx_sk-fs","Serial Nand flash is not discovered from uboot and kernel",""
  "LCPD-34976","am62axx_sk-se","AM62a: HS-SE : Fails to boot : Firewall Exception",""
  "LCPD-34967","am62axx_sk-fs","AM62a: SD Boot fails with warning ""alloc space exhausted""",""
  "LCPD-34966","am62axx_sk-fs,am62xx-lp-sk,am62xx-sk,am62xx_sk-fs,am64xx-evm,am64xx-sk,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721s2-evm,j784s4-evm","rpmsg_ctrl device mapping errors see with 6.1 kernel",""
  "LCPD-34896","am62xx_lp_sk-fs","AM62x-LP: RT Kernel fails to boot due to PRU",""
  "LCPD-34852","am62xx_sk-se,am64xx-evm,am654x-evm,j721e-idk-gw,j721s2-evm,j7200-evm","Few times payload is packed at size boundary by binman ",""
  "LCPD-34836","am62xx_lp_sk-fs","AM62-lp-sk: USB Audio device missing in test farm",""
  "LCPD-34686","am62axx_sk-fs,am64xx-evm","MMC itapdly sel values are not specified in uboot DTS",""
  "LCPD-34593","am62axx_sk-fs,am62xx-sk,am62xx_sk-fs,am64xx-evm,am64xx-hsevm,am654x-evm,am654x-idk,am654x-hsevm,beagleplay-gp","DISTRO BOOT: Not enabled on all Sitara Platforms",""
  "LCPD-34519","am62axx_sk-fs,am62xx-sk,am68_sk-fs,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm","IPC: IPC_S_FUNC_RPMSG_SAMPLE_CLIENT test failures",""
  "LCPD-34414","am654x-evm","AM65: Missing k3-am654-pcie-usb3 from kirkstone build",""
  "LCPD-34378","am62xx_lp_sk-fs","U-Boot: AM62x document SRAM layout",""
  "LCPD-34354","am62xx-sk,am62xx_sk-fs","Doc: Power Management Arch: Board name misspelled",""
  "LCPD-34316","am654x-idk","AM65x : ICSSG : Switching between Dual EMAC and Switch mode fails",""
  "LCPD-34301","am62axx_sk-fs,am62xx-lp-sk,am62xx-sk","Enabling clock output on AUDIO_EXT_REFCLK1 pin",""
  "LCPD-34131","am62xx_sk-fs","AM62: Boot inconsistencies on HS FS",""
  "LCPD-34125","am654x-evm,am654x-idk","AM65x Linux SDK : Missing ICSSG Performance numbers",""
  "LCPD-32946","am64xx-evm,am654x-evm,am654x-idk","RT Linux: PRU Ethernet link down causes kernel crash",""
  "LCPD-32945","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs","AM62x USB-DFU Boot is broken in R5 SPL",""
  "LCPD-32823","am64xx-evm,am654x-idk","ICSS firmware does not process Rx packets once Min error frame is received",""

|

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------
.. csv-table::
  :header: "Record ID", "Platform", "Title"
  :widths: 15, 70, 20

  "LCPD-32790","am62axx_sk-fs","AM62A: VPU: Module load/unload in loop fails after bootup",""
  "LCPD-30075","am62axx_sk-fs,am62axx_sk-se","AM62ax: Enable distro bootcommand",""
  "LCPD-29949","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,j721e-idk-gw","[PROD STOP]I2c operations at 100KHz is broken",""
  "LCPD-29792","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","am62x: mcspi not functional",""
  "LCPD-29589","am62axx_sk-fs,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se","AM62x CPSW: PPS example not enabled by default",""
  "LCPD-29441","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","am62x: kingston emmc fails on AM62x",""
  "LCPD-29397","am654x-evm,am654x-idk","AM65x Linux SDK lists unsupported industrial protocols",""
  "LCPD-29339","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","Processor SDK 8.3 AM62x lacks RT Linux performance numbers",""
  "LCPD-29300","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","U-Boot: OSPI-NOR: sf probe shows 0 randomly",""
  "LCPD-28950","am62axx_sk-fs","CSI2 Multi-capture channel 0 not working",""
  "LCPD-28764","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","AM62x: Cannot resume from low power mode",""
  "LCPD-28688","am62axx_sk-fs,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk","AM62x Kernel User Guide: Document AM62x default kernel config",""
  "LCPD-28614","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","AM62x: RPMsg client driver sample does not work",""
  "LCPD-28492","am64xx-evm,am654x-evm","AM65: ICSSG: phc_ctl: Seeing clock jumps in get",""
  "LCPD-28415","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","AM62: emmc: Had to disable higherspeeds",""
  "LCPD-28414","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","AM62x EVM Devicetree should disable unused MCU peripherals",""
  "LCPD-25662","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,j721e-evm,j7200-evm","Remove SGX PVR tools from KS3 devices",""
  "LCPD-25526","am654x-idk","rproc_get() failure on certain race conditions",""
  "LCPD-24691","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,j721s2-evm,j721s2_evm-fs,j7200-evm","Kernel: Upstream: Set HIGH_SPEED_EN for MMC1 instance",""
  "LCPD-24690","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk,j721s2-evm,j721s2_evm-fs,j7200-evm","Kernel: SDK: Set HIGH_SPEED_EN for MMC1 instance",""
  "LCPD-24127","am654x-evm,j721e-idk-gw","AM654x IPSEC Software Crypto tests fail (Impact 4)",""
  "LCPD-19859","am654x-evm","ETH ICSSG netperf benchmark returns lower performance than expected",""
  "LCPD-18258","am654x-evm,j721e-idk-gw","IPSEC perfomance failures",""


|

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
  :header: "Record ID", "Platform", "Title"
  :widths: 15, 30, 150

  "LCPD-27887","am62xx-sk,am62xx_sk-fs","i2327: RTC: Hardware wakeup event limitation","None"
  "LCPD-27886","am62axx_sk-fs,am62xx-sk,am64xx-evm,j721e-idk-gw,j7200-evm,j784s4-evm,j784s4-hsevm","USART: Erroneous clear/trigger of timeout interrupt",""
  "LCPD-25264","am64xx-evm,am64xx-hsevm,am64xx-sk","BCDMA: Blockcopy Gets Corrupted if TR Read Responses Interleave with Source Data Fetch",""
  "LCPD-22905","am654x-evm,j721e-idk-gw","UDMA: TR15 hangs if ICNT0 is less than 64 bytes",""
  "LCPD-19965","am64xx-evm,am654x-idk,j721e-idk-gw,j7200-evm","OSPI PHY Controller Bug Affecting Read Transactions",""
  "LCPD-19447","am654x-evm,am654x-idk","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame",""
  "LCPD-18979","am654x-idk","MCAN: Message Transmitted with Wrong Arbitration and Control Fields (Early Start of Frame)",""
  "LCPD-17788","am654x-evm,am654x-idk","PCI-Express: GEN3 (8GT/s) Operation Not Supported.",""
  "LCPD-17783","am654x-evm,am654x-idk","USB: USB2PHY Charger Detect is enabled by default without VBUS presence",""
  "LCPD-14579","am654x-evm,am654x-idk","DSS : DSS Does Not Support YUV Pixel Data Formats",""
  "LCPD-14184","am654x-evm","USB:  SuperSpeed USB Non-Functional",""


|

U-Boot Known Issues
------------------------
.. csv-table::
  :header: "Record ID", "Platform", "Title", "Workaround"
  :widths: 15, 30, 70, 30

  "LCPD-34929","am62axx_sk-fs","Remoteproc load of C7x from U-boot fails on 9.0 RC3",""
  "LCPD-34398","am62axx_sk-fs","Uboot: AM62a boot reporting wrong SOC name",""
  "LCPD-28660","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: tiboot3.bin generated by U-Boot build is confusing users",""
  "LCPD-28503","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk","Need to sync up DTS files between u-boot and kernel for at least AM62x, possibly other boards too",""
  "LCPD-28287","am654x-idk","ICSSG: AM65 SR2.0: U-Boot: RX is not working",""
  "LCPD-28286","am654x-idk","ICSSG: AM65 SR2.0: U-Boot: Avoid hardcoding DMA channel",""
  "LCPD-25540","am64xx-hsevm,am64xx-sk","AM64: u-boot: usb host boot failed",""
  "LCPD-24717","am654x-evm,am654x-idk","am654: PCI-E ethernet interface shows link down in U-Boot",""
  "LCPD-24628","am654x-evm,am654x-idk","am654x-idk DFU boot is failing",""
  "LCPD-24130","am654x-evm","AM654x: USB MSC boot mode fails",""
  "LCPD-18627","am654x-idk","uboot does not read the reserve-memory from the fdt ",""
  "LCPD-17770","am654x-evm,am654x-idk,am654x-hsevm","U-Boot: Fix order of MCU R5 shutdown depending on cluster mode",""
  "LCPD-16696","am654x-evm,am654x-idk","U-Boot does not recognize SD-Card after re-insert/change",""
  "LCPD-16524","am654x-evm,am654x-idk,am654x-hsevm","Need to adjust RMW bit when using enabling ECC","None"
  "LCPD-15873","am654x-evm","There is no dtbo in u-boot for PCIe x1 + usb3 daughter card","None"
  "LCPD-14843","am654x-evm,am654x-idk","U-boot should support  default settings for netboot ","None"


|

Linux Known Issues
---------------------------
.. csv-table::
  :header: "Record ID", "Platform", "Title", "Workaround"
  :widths: 5, 10, 70, 35

  "LCPD-35056","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","'Error: ""main_cpsw0_qsgmii_phyinit"" not defined' on AM62x",""
  "LCPD-35055","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62xx-sk,am62xx_sk-fs,am62xx_sk-se","ERROR: reserving fdt memory region failed on AM62x",""
  "LCPD-35054","am62xx_lp_sk-fs,am62xx_lp_sk-se","AM62x LP fitImage boot issue with Yocto images"," On fs : boot non fit image and this is set as default in u-boot"
  "LCPD-35043","am62axx_sk-fs","Doc: VPU performance and capabilities shown incorrectly for AM62Ax",""
  "LCPD-35042","am62xx-sk,am62xx_sk-fs,am62xx_sk-hs4,am62xx_sk-hs5,am62xx_sk-se","Linux: AM62x: OSPI NOR Flash read speed is low (~2.5MBPS)",""
  "LCPD-35025","am62xx_sk-fs","Test gap: Implement automated test for Driver suspend resume",""
  "LCPD-35022","am64xx-evm,am64xx-hsevm","AM64x: Benchmark OOB doesn't show any load on A53 and R5 (core 0) with latest ti-rpmsg-char v6.1",""
  "LCPD-35007","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","AM62x: ip adress not assigned by default on AM62x",""
  "LCPD-34993","am64xx-hsevm","AM64x: sf probe fails on hs-fs",""
  "LCPD-34991","am62axx_sk-fs","systemd failure with vmalloc overflow error when using fitimage",""
  "LCPD-34978","am62xx-sk,am62xx_sk-fs","AM62x: High tiny-image cpio file size",""
  "LCPD-34916","am62xx-sk,am62xx_sk-fs","AM62x: op-tee with LOG_LEVEL=2 crashes after Deep Sleep",""
  "LCPD-34915","am62xx-sk,am62xx_sk-fs","AM62x: op-tee with HW TRNG crashes after Deep Sleep",""
  "LCPD-34912","am62axx_sk-fs,am62axx_sk-hs4,am62axx_sk-hs5,am62axx_sk-se,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62xx-sk,am62xx_sk-fs,am62xx_sk-hs4,am62xx_sk-hs5,am62xx_sk-se","AM62/AM62Ax: DM does not set correct pixel clock",""
  "LCPD-34901","am62xx-sk,am62xx_sk-fs","AM62: Reset button fails to reset AM625-SK-EVM after wakeup from deep sleep",""
  "LCPD-34898","am62xx-sk,am62xx_sk-fs","AM62x: MCU Only mode: Linux console lockup after ~100 suspend resume cycles",""
  "LCPD-34840","am64xx-hsevm","AM64: Networking failures including ICSSG",""
  "LCPD-34837","am64xx-evm,am64xx-hsevm,am654x-evm,am654x-idk","TEST: Create automated test for LCPD-32336 (ICSSG driver XDP native mode support)",""
  "LCPD-34835","am62axx_sk-fs,am62xx-lp-sk,am62xx-sk,beagleplay-gp","am62/am62a: Add CTRL MMR support for DPI signals on negative edge",""
  "LCPD-34833","am62xx-sk,am62xx_sk-fs","AM62: Wi-Fi not functional after 6.1/kirkstone migration",""
  "LCPD-34816","am62xx-sk,am62xx_sk-fs","rtcwake fails after resuming from Deep Sleep",""
  "LCPD-34813","am62xx-sk,am62xx_sk-fs,am62xx_sk-hs4,am62xx_sk-hs5,am62xx_sk-se","SK-AM62B: Flood of tps6598x_interrupt failed to read events",""
  "LCPD-34755","am62axx_sk-fs","am62a: HDMI related crashes",""
  "LCPD-34693","am62axx_sk-fs,am62xx-sk,am62xx_sk-fs","am62: CPSW TCP bidir tests fail",""
  "LCPD-34531","am62axx_sk-fs,am654x-evm","AM62a: eMMC LTP tests failure",""
  "LCPD-34520","am654x-evm,am654x-idk","AM65: USB and PCIE DT overlays doesnt exist",""
  "LCPD-34397","am62xx-sk","usb xhci locks up after multiple Linux reboot",""
  "LCPD-34360","am62axx_sk-fs","Display distorted above certain resolution",""
  "LCPD-34242","am62xx-sk,am62xx_sk-fs,am68_sk-fs,j721s2-evm,j7200-evm,j784s4-evm","GPIO_S_FUNC_DIR_IN_ALL_BANK unit test fails",""
  "LCPD-34105","am62axx_sk-fs,am62axx_sk-hs4,am62axx_sk-hs5,am62axx_sk-se,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62xx-sk,am62xx_sk-fs,am62xx_sk-hs4,am62xx_sk-hs5,am62xx_sk-se","convert uboot's MDIO driver over to use the driver model",""
  "LCPD-32868","am64xx-evm,am654x-idk","Kernel crash from PRU auto-forwarding packet",""
  "LCPD-32706","am62xx-sk,am62xx_sk-fs","Display: DRM tests fail inconsistently",""
  "LCPD-32351","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","MMCSD: HS200 and SDR104 Command Timeout Window Too Small","If the command requires a timeout longer than 700ms, then the MMC host controller command timeout can be disabled (MMCSD_CON[6] MIT=0x1) and a software implementation may be used in its place."
  "LCPD-29861","am64xx-evm,am64xx-hsevm,am64xx-sk,am64xx-hssk","AM64x: IPC tests fail",""
  "LCPD-29515","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: Cannot boot with USB-MSC",""
  "LCPD-28742","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","AM62x: Make ""Debugging SPL"" doc specific to AM62x",""
  "LCPD-28491","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","WiLink not functional with fw_devlink option set to `on` ",""
  "LCPD-28448","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","Wall time does not account for sleep time",""
  "LCPD-28436","am654x-idk","AM65x Uboot PRUETH is broken",""
  "LCPD-28105","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","Automated test failure - CPSW failure doing runtime pm",""
  "LCPD-28104","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","Automated test failure - CPSW test is passing invalid parameters to switch-config",""
  "LCPD-25563","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","Test: AM62: Linux: Add support for MCAN",""
  "LCPD-25314","am654x-evm,am654x-idk,am654x-hsevm","ICSSG: Timestamp for back-to-back with IPG < 100us not received",""
  "LCPD-24718","am654x-evm,am654x-idk","am654x hwspinlock test failing",""
  "LCPD-24541","am654x-evm","am65xx OSPI boot does not work",""
  "LCPD-24537","am64xx-evm,am64xx-hsevm,am654x-evm","am654x-idk nslookup times out when all netwokring interfaces are active",""
  "LCPD-24456","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am62axx_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am62xx-vlab,am62xx-zebu,am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j7ae-evm,j7ae-zebu,j7aep-zebu,j7am-evm,j7am-vlab,j7am-zebu,j7amp-vlab,j7amp-zebu,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721e-vlab,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j7200-evm,j7200-hsevm,j7amp-evm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm,k2l-hsevm,omapl138-lcdk","Move IPC validation source from github to git.ti.com",""
  "LCPD-24319","am654x-evm","am654x-evm DRM tests fail due to frequency mismatch (Impact 7)",""
  "LCPD-24134","am654x-evm","AM654x CAL DMABUF tests fail (Impact 4.0)",""
  "LCPD-23008","am654x-evm","AM65xx - display port scenario not enabled",""
  "LCPD-23007","am654x-evm","k3-am654-evm-hdmi.dtbo file is missing in CoreSDK for am654x",""
  "LCPD-22947","am654x-evm","Alsa performance test fails [waiting for TF]",""
  "LCPD-22931","am64xx-evm,am64xx-sk,am654x-evm,am654x-idk","RemoteProc documentation missing",""
  "LCPD-22892","am64xx-evm,am654x-evm,am654x-idk","icssg: due to FW bug both interfaces has to be loaded always",""
  "LCPD-22772","am654x-idk","PRU_ICSSG: 100Mbit/s MII is not supported when the PRU_ICSSG is operating at frequencies < 250MHz",""
  "LCPD-22715","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,j721e-idk-gw,j721s2-evm,j721s2_evm-fs,j7200-evm","i2232: DDR: Controller postpones more than allowed refreshes after frequency change","Workaround 1: Disable dynamic frequency change by programing DFS_ENABLE"
  "LCPD-22324","am654x-idk","ICSSG port does not drop packets with SA matching interface MAC",""
  "LCPD-22319","am62axx_sk-fs,am62xx-sk,am64xx-evm,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm","OpenSSL performance test data out of bounds",""
  "LCPD-20683","am654x-evm","am65xx fails emmc boot",""
  "LCPD-20653","am335x-evm,am43xx-gpevm,am654x-idk,j721e-idk-gw","ltp: kernel syscall tests fail",""
  "LCPD-20014","am654x-evm,am654x-idk,am654x-hsevm","remoteproc: TX_PRU: IRQ vring, IRQ kick not found error message on console",""
  "LCPD-19948","am57xx-evm,am654x-evm,j721e-evm","Yocto: stream recipe is incorrect",""
  "LCPD-19929","am654x-evm","Industrial protocols documentation",""
  "LCPD-19923","am654x-evm,am654x-idk","[AM65x] Linux reboot command fails","https://e2e.ti.com/support/processors-group/processors/f/processors-forum/1011070/am6548-linux-reboot-command-fails"
  "LCPD-19580","am654x-evm","am654- unable to select a mode (sdhci?)",""
  "LCPD-18788","am654x-idk","Uboot: Could not bring up PCIe interface",""
  "LCPD-18228","am654x-evm","PCI PM runtime suspend is not increasing",""
  "LCPD-17800","am654x-evm,am654x-idk","CPSW: Master/Slave resolution failed message seen at console",""
  "LCPD-17673","am335x-evm,am43xx-gpevm,am571x-idk,am572x-idk,am574x-idk,am57xx-evm,am654x-evm,beaglebone-black,dra71x-evm,dra72x-evm,dra7xx-evm,j721e-evm","No software documentation for the Timer module",""
  "LCPD-17449","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm","libasan_preinit.o is missing in devkit",""
  "LCPD-17413","am335x-evm,am43xx-gpevm,am57xx-evm,am654x-evm","QT Webengine-based browser: the mouse does not work within the web page with QPA EGLFS",""
  "LCPD-16534","am654x-evm,am654x-idk","remoteproc/k3-r5f: PDK IPC echo_test image fails to do IPC in remoteproc mode on second run","None"
  "LCPD-16406","am654x-idk","Seeing ""e1000#0: ERROR: Hardware Initialization Failed"" sometimes when do dhcp via pcie-eth",""


|

Linux RT Kernel Known Issues
----------------------------
.. csv-table::
  :header: "Record ID", "Platform", "Title", "Workaround"
  :widths: 15, 70, 20, 35

  "LCPD-35056","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","'Error: ""main_cpsw0_qsgmii_phyinit"" not defined' on AM62x",""
  "LCPD-35055","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62xx-sk,am62xx_sk-fs,am62xx_sk-se","ERROR: reserving fdt memory region failed on AM62x",""
  "LCPD-35054","am62xx_lp_sk-fs,am62xx_lp_sk-se","AM62x LP fitImage boot issue with Yocto images"," On fs : boot non fit image and this is set as default in u-boot "
  "LCPD-35043","am62axx_sk-fs","Doc: VPU performance and capabilities shown incorrectly for AM62Ax",""
  "LCPD-35042","am62xx-sk,am62xx_sk-fs,am62xx_sk-hs4,am62xx_sk-hs5,am62xx_sk-se","Linux: AM62x: OSPI NOR Flash read speed is low (~2.5MBPS)",""
  "LCPD-35025","am62xx_sk-fs","Test gap: Implement automated test for Driver suspend resume",""
  "LCPD-35022","am64xx-evm,am64xx-hsevm","AM64x: Benchmark OOB doesn't show any load on A53 and R5 (core 0) with latest ti-rpmsg-char v6.1",""
  "LCPD-34993","am64xx-hsevm","AM64x: sf probe fails on hs-fs",""
  "LCPD-34991","am62axx_sk-fs","systemd failure with vmalloc overflow error when using fitimage",""
  "LCPD-34978","am62xx-sk,am62xx_sk-fs","AM62x: High tiny-image cpio file size",""
  "LCPD-34916","am62xx-sk,am62xx_sk-fs","AM62x: op-tee with LOG_LEVEL=2 crashes after Deep Sleep",""
  "LCPD-34915","am62xx-sk,am62xx_sk-fs","AM62x: op-tee with HW TRNG crashes after Deep Sleep",""
  "LCPD-34912","am62axx_sk-fs,am62axx_sk-hs4,am62axx_sk-hs5,am62axx_sk-se,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62xx-sk,am62xx_sk-fs,am62xx_sk-hs4,am62xx_sk-hs5,am62xx_sk-se","AM62/AM62Ax: DM does not set correct pixel clock",""
  "LCPD-34901","am62xx-sk,am62xx_sk-fs","AM62: Reset button fails to reset AM625-SK-EVM after wakeup from deep sleep",""
  "LCPD-34898","am62xx-sk,am62xx_sk-fs","AM62x: MCU Only mode: Linux console lockup after ~100 suspend resume cycles",""
  "LCPD-34897","am62xx_lp_sk-fs","AM62x-LP: USB failures ",""
  "LCPD-34840","am64xx-hsevm","AM64: Networking failures including ICSSG",""
  "LCPD-34837","am64xx-evm,am64xx-hsevm,am654x-evm,am654x-idk","TEST: Create automated test for LCPD-32336 (ICSSG driver XDP native mode support)",""
  "LCPD-34835","am62axx_sk-fs,am62xx-lp-sk,am62xx-sk,beagleplay-gp","am62/am62a: Add CTRL MMR support for DPI signals on negative edge",""
  "LCPD-34833","am62xx-sk,am62xx_sk-fs","AM62: Wi-Fi not functional after 6.1/kirkstone migration",""
  "LCPD-34816","am62xx-sk,am62xx_sk-fs","rtcwake fails after resuming from Deep Sleep",""
  "LCPD-34813","am62xx-sk,am62xx_sk-fs,am62xx_sk-hs4,am62xx_sk-hs5,am62xx_sk-se","SK-AM62B: Flood of tps6598x_interrupt failed to read events",""
  "LCPD-34755","am62axx_sk-fs","am62a: HDMI related crashes",""
  "LCPD-34693","am62axx_sk-fs,am62xx-sk,am62xx_sk-fs","am62: CPSW TCP bidir tests fail",""
  "LCPD-34531","am62axx_sk-fs,am654x-evm","AM62a: eMMC LTP tests failure",""
  "LCPD-34520","am654x-evm,am654x-idk","AM65: USB and PCIE DT overlays doesnt exist",""
  "LCPD-34516","am62xx-sk,am62xx_sk-fs,j721s2-evm,j7200-evm,j784s4-evm","USBHOST Audio ltp unit test fails",""
  "LCPD-34360","am62axx_sk-fs","Display distorted above certain resolution",""
  "LCPD-34242","am62xx-sk,am62xx_sk-fs,am68_sk-fs,j721s2-evm,j7200-evm,j784s4-evm","GPIO_S_FUNC_DIR_IN_ALL_BANK unit test fails",""
  "LCPD-34105","am62axx_sk-fs,am62axx_sk-hs4,am62axx_sk-hs5,am62axx_sk-se,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62xx-sk,am62xx_sk-fs,am62xx_sk-hs4,am62xx_sk-hs5,am62xx_sk-se","convert uboot's MDIO driver over to use the driver model",""
  "LCPD-32868","am64xx-evm,am654x-idk","Kernel crash from PRU auto-forwarding packet",""
  "LCPD-32706","am62xx-sk,am62xx_sk-fs","Display: DRM tests fail inconsistently",""
  "LCPD-32351","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","MMCSD: HS200 and SDR104 Command Timeout Window Too Small","If the command requires a timeout longer than 700ms, then the MMC host controller command timeout can be disabled (MMCSD_CON[6] MIT=0x1) and a software implementation may be used in its place"
  "LCPD-29861","am64xx-evm,am64xx-hsevm,am64xx-sk,am64xx-hssk","AM64x: IPC tests fail",""
  "LCPD-29515","am64xx-evm,am64xx-hsevm,am64xx-sk","AM64x: Cannot boot with USB-MSC",""
  "LCPD-29332","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","LPM Demo not Working on Linux RT",""
  "LCPD-28742","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","AM62x: Make ""Debugging SPL"" doc specific to AM62x",""
  "LCPD-28491","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","WiLink not functional with fw_devlink option set to `on` ",""
  "LCPD-28448","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","Wall time does not account for sleep time",""
  "LCPD-28436","am654x-idk","AM65x Uboot PRUETH is broken",""
  "LCPD-28105","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","Automated test failure - CPSW failure doing runtime pm",""
  "LCPD-28104","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","Automated test failure - CPSW test is passing invalid parameters to switch-config",""
  "LCPD-25563","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","Test: AM62: Linux: Add support for MCAN",""
  "LCPD-25314","am654x-evm,am654x-idk,am654x-hsevm","ICSSG: Timestamp for back-to-back with IPG < 100us not received",""
  "LCPD-24718","am654x-evm,am654x-idk","am654x hwspinlock test failing",""
  "LCPD-24537","am64xx-evm,am64xx-hsevm,am654x-evm","am654x-idk nslookup times out when all netwokring interfaces are active",""
  "LCPD-24456","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am62axx_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am62xx-vlab,am62xx-zebu,am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j7ae-evm,j7ae-zebu,j7aep-zebu,j7am-evm,j7am-vlab,j7am-zebu,j7amp-vlab,j7amp-zebu,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721e-vlab,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j7200-evm,j7200-hsevm,j7amp-evm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm,k2l-hsevm,omapl138-lcdk","Move IPC validation source from github to git.ti.com",""
  "LCPD-24319","am654x-evm","am654x-evm DRM tests fail due to frequency mismatch (Impact 7)",""
  "LCPD-24288","am64xx-evm,am654x-idk","am64xx-evm NCM/ACM network performance test crashes with RT images",""
  "LCPD-24134","am654x-evm","AM654x CAL DMABUF tests fail (Impact 4.0)",""
  "LCPD-23008","am654x-evm","AM65xx - display port scenario not enabled",""
  "LCPD-23007","am654x-evm","k3-am654-evm-hdmi.dtbo file is missing in CoreSDK for am654x",""
  "LCPD-22947","am654x-evm","Alsa performance test fails [waiting for TF]",""
  "LCPD-22931","am64xx-evm,am64xx-sk,am654x-evm,am654x-idk","RemoteProc documentation missing",""
  "LCPD-22892","am64xx-evm,am654x-evm,am654x-idk","icssg: due to FW bug both interfaces has to be loaded always",""
  "LCPD-22715","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,j721e-idk-gw,j721s2-evm,j721s2_evm-fs,j7200-evm","i2232: DDR: Controller postpones more than allowed refreshes after frequency change","Workaround 1: Disable dynamic frequency change by programing DFS_ENABLE = 0"
  "LCPD-22324","am654x-idk","ICSSG port does not drop packets with SA matching interface MAC",""
  "LCPD-22319","am62axx_sk-fs,am62xx-sk,am64xx-evm,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm","OpenSSL performance test data out of bounds",""
  "LCPD-20014","am654x-evm,am654x-idk,am654x-hsevm","remoteproc: TX_PRU: IRQ vring, IRQ kick not found error message on console",""
  "LCPD-19948","am57xx-evm,am654x-evm,j721e-evm","Yocto: stream recipe is incorrect",""
  "LCPD-19929","am654x-evm","Industrial protocols documentation",""
  "LCPD-19923","am654x-evm,am654x-idk","[AM65x] Linux reboot command fails","https://e2e.ti.com/support/processors-group/processors/f/processors-forum/1011070/am6548-linux-reboot-command-fails"
  "LCPD-19580","am654x-evm","am654- unable to select a mode (sdhci?)",""
  "LCPD-18908","am654x-evm","GLMark2 fails for am65x",""
  "LCPD-18788","am654x-idk","Uboot: Could not bring up PCIe interface",""
  "LCPD-18228","am654x-evm","PCI PM runtime suspend is not increasing",""
  "LCPD-17800","am654x-evm,am654x-idk","CPSW: Master/Slave resolution failed message seen at console",""
  "LCPD-17673","am335x-evm,am43xx-gpevm,am571x-idk,am572x-idk,am574x-idk,am57xx-evm,am654x-evm,beaglebone-black,dra71x-evm,dra72x-evm,dra7xx-evm,j721e-evm","No software documentation for the Timer module",""
  "LCPD-17449","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm","libasan_preinit.o is missing in devkit",""
  "LCPD-17413","am335x-evm,am43xx-gpevm,am57xx-evm,am654x-evm","QT Webengine-based browser: the mouse does not work within the web page with QPA EGLFS",""
  "LCPD-16534","am654x-evm,am654x-idk","remoteproc/k3-r5f: PDK IPC echo_test image fails to do IPC in remoteproc mode on second run","None"
  "LCPD-16406","am654x-idk","Seeing ""e1000#0: ERROR: Hardware Initialization Failed"" sometimes when do dhcp via pcie-eth",""


|




Linux SDK Known Issues
----------------------
.. csv-table::
  :header: "Record ID", "Platform", "Title", "Workaround"
  :widths: 15, 70, 20, 35


  "LCPD-34978","am62xx-sk,am62xx_sk-fs","AM62x: High tiny-image cpio file size",""
  "LCPD-19948","am57xx-evm,am654x-evm,j721e-evm","Yocto: stream recipe is incorrect",""
  "LCPD-17449","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm","libasan_preinit.o is missing in devkit",""
  "LCPD-14254","am654x-evm,am654x-idk","meta-ti: Need a recipe update to pick up the new AM65x PRU Ethernet firmwares",""
  "LCPD-35083","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se","AM62: PRU rpmsg samples echo sample FW are not getting installed","MACHINE=am62xx-evm bitbake pru-icss; install the ipk on the targetfs; opkg install pru-icss-rpmsg-echo_6.2.0-r1.0_am62xx_evm.ipk"


|

