************************************
Release Notes
************************************

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


Release 09.02.01
==================

Released May 2024

.. rubric:: What's New
   :name: whats-new

**Processor SDK 9.2.1 Sitara Release supports the following platforms**
  * tag: 09.02.00.010
       * AM62Px (HS-FS)
       * AM62x ( GP, HS-FS, HS-SE)
       * AM62x LP (HS-FS, HS-SE)
       * AM62SIP ( HS-FS, HS-SE)
       * AM64x 2.0 (HS-FS)
       * AM62A (HS-FS, HS-SE)

**Processor SDK 9.2.1 Sitara Release has following Major Updates**
  * LTS Refresh with Stable Kernel update from 6.1.80 to 6.1.83
  * Important Bug fixes on top of 9.2 Release
  ** Review Issue Tracker Section for the new fixes.


Build Information
=====================================

U-Boot
-------------------------
| Head Commit: 	83660642085462346fbeb410f83bc99448ec7042 arm: dts: k3-am62p-main: Add mac-address efuse
| Date: 2024-05-16 08:21:02 -0500
| uBoot Version: 2023.04
| uBoot Description: RC Release 09.02.00.010
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2023.04
| uBoot Tag: 09.02.00.010
|


Kernel
-------------------------
.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: c1c2f1971fbf6ddad93a8c94314fe8221e7aa6be Revert "HACK: drm/bridge: tc358762: Implement early_enable and late_disable"
| Date: 2024-05-16 08:20:49 -0500
| Kernel Version: 6.1.83
| Kernel Description: RC Release 09.02.00.010

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-6.1.y
| Tag: 09.02.00.010
| use-kernel-config=defconfig
| config-fragment=kernel/configs/ti_arm64_prune.config
|


.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 96b0ebd82722d16e9ab646cd3a73080e6f790747 Merge branch 'ti-linux-6.1.y-cicd' into ti-rt-linux-6.1.y-cicd
| Date: 2024-05-16 08:20:53 -0500
| Kernel Version: 6.1.83-rt26
| Kernel Description: RC Release 09.02.00.010-rt

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-6.1.y
| Tag: 09.02.00.010-rt
| use-kernel-config=defconfig
| config-fragment=config-fragment=kernel/configs/ti_arm64_prune.config kernel/configs/ti_rt.config
|



Yocto
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: c57b63147d2ac0dde16e43f7407d0ff50e62efdb CI/CD Auto-Merger: cicd.kirkstone.202405141220
| Date: 2024-05-16 08:21:03 -0500

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: kirkstone
| Release Tag: 09.02.00.010
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: 3bc9220ea41ee74eea8e48505abbd94f2eee3625 meta-arago-test: cpuloadgen: Update SRCREV to latest
| Date: 2024-05-16 08:20:18 -0500

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: kirkstone
| Release Tag: 09.02.00.010
|

Issues Tracker
=====================================

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 30, 150

   "LCPD-32825","PCIe: ls -al /dev/disk/by-id shows no nvme device","am64xx-hsevm"
   "LCPD-27887","i2327: RTC: Hardware wakeup event limitation","am62xx_sk-fs,am62xxsip_sk-fs,am62xxsip_sk-se,am62xx-sk"
   "LCPD-27886","USART: Erroneous clear/trigger of timeout interrupt","am64xx-evm,am62axx_sk-fs,am62xxsip_sk-fs,am62xxsip_sk-se,am62xx-sk,j721e-idk-gw,j7200-evm,j784s4-evm,j784s4-hsevm"
   "LCPD-25264","BCDMA: Blockcopy Gets Corrupted if TR Read Responses Interleave with Source Data Fetch","am64xx-evm,am64xx-hsevm,am64xx_sk-fs"
   "LCPD-22905","UDMA: TR15 hangs if ICNT0 is less than 64 bytes","am654x-evm,j721e-idk-gw"
   "LCPD-19965","OSPI PHY Controller Bug Affecting Read Transactions","am654x-idk,am64xx-evm,j721e-idk-gw,j7200-evm"
   "LCPD-19447","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame","am654x-evm,am654x-idk"
   "LCPD-18979","MCAN: Message Transmitted with Wrong Arbitration and Control Fields (Early Start of Frame)","am654x-idk"
   "LCPD-17788","PCI-Express: GEN3 (8GT/s) Operation Not Supported.","am654x-evm,am654x-idk"
   "LCPD-17783","USB: USB2PHY Charger Detect is enabled by default without VBUS presence","am654x-evm,am654x-idk"
   "LCPD-14579","DSS : DSS Does Not Support YUV Pixel Data Formats","am654x-evm,am654x-idk"
   "LCPD-14184","USB:  SuperSpeed USB Non-Functional","am654x-evm"


|


U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-37149","am62axx_sk-fs,am62axx_sk-se","Enabling RTC on am62ax is breaking TIDL",""
   "LCPD-36846","am62xx_sk-fs","u-boot usb reset comamnd fails",""
   "LCPD-36618","am62xxsip_sk-fs,am62xxsip_sk-se","AM62SIP:  reserving fdt memory region failed error seen at bootup",""
   "LCPD-34951","am62xx-sk","Board not booting up",""
   "LCPD-28503","am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62xx-sk,am64xx_sk-fs","Need to sync up DTS files between u-boot and kernel for at least AM62x, possibly other boards too",""
   "LCPD-28436","am654x-idk","AM65x Uboot PRUETH is broken",""
   "LCPD-25540","am64xx-hsevm,am64xx_sk-fs","AM64: u-boot: usb host boot failed",""
   "LCPD-24717","am654x-evm,am654x-idk","am654: PCI-E ethernet interface shows link down in U-Boot",""
   "LCPD-24628","am654x-evm,am654x-idk","am654x-idk DFU boot is failing",""
   "LCPD-17770","am654x-evm,am654x-idk,am654x-hsevm","U-Boot: Fix order of MCU R5 shutdown depending on cluster mode",""
   "LCPD-16696","am654x-evm,am654x-idk","U-Boot does not recognize SD-Card after re-insert/change",""
   "LCPD-16524","am654x-evm,am654x-idk,am654x-hsevm","Need to adjust RMW bit when using enabling ECC","None"
   "LCPD-14843","am654x-evm,am654x-idk","U-boot should support  default settings for netboot ","None"



|

Linux Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35

   "LCPD-37197","am64xx-evm,am64xx-hsevm","AM64x: ENET ICSSG: Firmware is not updating the Host Port statistics",""
   "LCPD-37194","am62pxx_sk-fs,am62pxx_sk-se,am62pxx-zebu","AM62P: DSI Color shift",""
   "LCPD-37187","am62axx_sk-fs,am62axx_sk-se","Enable remaining GPIO SOC pins on am62a for RPi Header Expansion",""
   "LCPD-37152","am654x-idk","ICSSG: IET FPE mac verify fails",""
   "LCPD-37150","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62xx-sk","am62: i2c bus speed test is failing",""
   "LCPD-37142","am62axx_sk-fs,am62axx_sk-se","AM62A: Suspend-resume: 29010000.mailbox: fifo 1 has unexpected unread messages",""
   "LCPD-37141","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62pxx_sk-fs","AM62x: Sync up USB R5 defconfigs with main R5 defconfig",""
   "LCPD-37076","am62xx_sk-fs,am62xx_sk-se","OP-TEE: RNG handling during suspend/resume",""
   "LCPD-36978","am62xxsip_sk-fs,am62xxsip_sk-se","AM62xSiP: DeepSleep: Suspend-Resume not working",""
   "LCPD-36975","am64xx-evm","HSR Error: 8021q: VLANs not supported on device.",""
   "LCPD-36950","am62xx_sk-fs,am62axx_sk-fs,am62pxx_sk-fs","crypto openssl performance test fail",""
   "LCPD-36925","am62xx_lp_sk-fs,am62xx_lp_sk-se","am62xx-lp-sk: power down from automation interface behaves differently between U-Boot and kernel",""
   "LCPD-36876","am64xx-hsevm","running linuxptp (ptp4l, phc_ctl or ts2phc, setting clock) it will cause PPS incoherence",""
   "LCPD-36848","am62xx_sk-fs,j721e-idk-gw","J721E: Occasional SPI-NOR write timeout under high load",""
   "LCPD-36812","am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se","RTC: tests fail",""
   "LCPD-36811","am62xx_sk-fs,am68_sk-fs,am69_sk-fs","MM: Weston should assign 0 zpos to primary plane",""
   "LCPD-36805","am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se","ETHERNET boot test fail incorrect configuration",""
   "LCPD-36804","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am64xx_sk-fs,am64xx_evm-se,am64xx_sk-se","IPC performance test fail - modprobe fails",""
   "LCPD-36803","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se","USBDEV:  test case fail - USB devices not enumerated",""
   "LCPD-36801","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se","USB-DFU boot test fail incorrect configuration",""
   "LCPD-36631","am62xx_sk-fs","AM625 SK EVM duplicate mbox node",""
   "LCPD-36622","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm","Errata i2028: USB3.0 Host and Device Non-Functional",""
   "LCPD-36575","am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se","AM62Q: AM62A: OSPI:  tuning fails at certain PVTs",""
   "LCPD-36524","am62xx_sk-fs","AM62x: sa2ul doesn't work after deepsleep",""
   "LCPD-36361","am64xx-hsevm,am62xxsip_sk-se","Boot failure over UART",""
   "LCPD-36282","am62xx-sk","OV5640 capture not working at two highest resolutions",""
   "LCPD-35352","am64xx-evm,am64xx_sk-fs","AM64x dts file calls SYNC2_OUT the wrong name",""
   "LCPD-35042","am62xx_sk-fs,am62xx_sk-se,am62xx-sk,am62xx_sk-hs4,am62xx_sk-hs5","Linux: AM62x: OSPI NOR Flash read speed is low (~2.5MBPS)",""
   "LCPD-35022","am64xx-hsevm","AM64x: Benchmark OOB doesn't show any load on A53 and R5 (core 0) with latest ti-rpmsg-char v6.1",""
   "LCPD-34912","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62axx_sk-hs4,am62axx_sk-hs5,am62xx-lp-sk,am62xx-sk,am62xx_sk-hs4,am62xx_sk-hs5","AM62/AM62Ax: DM does not set correct pixel clock",""
   "LCPD-34906","am62xx-sk","R5 SPL OSPI NOR with PHY calibration not working",""
   "LCPD-34901","am62xx_sk-fs,am62xx-sk","AM62: Reset button fails to reset AM625-SK-EVM after wakeup from deep sleep",""
   "LCPD-34898","am62xx_sk-fs,am62xx-sk","AM62x: MCU Only mode: Linux console lockup after ~100 suspend resume cycles",""
   "LCPD-34835","am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs","am62/am62a: Add CTRL MMR support for DPI signals on negative edge",""
   "LCPD-34813","am62xx_sk-fs,am62xx_sk-se,am62xx-sk,am62xx_sk-hs4,am62xx_sk-hs5","SK-AM62B: Flood of tps6598x_interrupt failed to read events",""
   "LCPD-34343","am62xx-sk","SDK: Am62x: Openssl commands for openssl_perf.sh gives wrong results",""
   "LCPD-34242","am62xx_sk-fs,am62xxsip_sk-fs,am62xxsip_sk-se,am62xx-sk,am68_sk-fs,am69_sk-fs,j721s2-evm,j7200-evm,j784s4-evm","GPIO_S_FUNC_DIR_IN_ALL_BANK unit test fails",""
   "LCPD-34105","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62axx_sk-hs4,am62axx_sk-hs5,am62xx-lp-sk,am62xx-sk,am62xx_sk-hs4,am62xx_sk-hs5","convert uboot's MDIO driver over to use the driver model",""
   "LCPD-32868","am654x-idk,am64xx-evm","Kernel crash from PRU auto-forwarding packet",""
   "LCPD-32706","am62xx_sk-fs,am62xx-sk","Display: DRM tests fail inconsistently",""
   "LCPD-29332","am62xx_sk-fs,am62xx_sk-se,am62xx-sk","LPM Demo not Working on Linux RT",""
   "LCPD-28448","am62xx_sk-fs,am62xx_sk-se,am62xx-sk","Wall time does not account for sleep time",""
   "LCPD-28104","am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62xx-sk","Automated test failure - CPSW test is passing invalid parameters to switch-config",""
   "LCPD-27871","am64xx-evm","GPMC NAND driver misleading error",""
   "LCPD-25494","am64xx-evm","AM64 EVM TSN IET tests is failing",""
   "LCPD-24823","am64xx-evm,am64xx_sk-fs","Clarify Single-Core usage in ti,k3-r5f-rproc.yaml",""
   "LCPD-24718","am654x-evm,am654x-idk","am654x hwspinlock test failing",""
   "LCPD-24595","am64xx-evm,am64xx_sk-fs,j721e-idk-gw,j721e-sk,j7200-evm","j721e-idk-gw USB Suspend/Resume with RTC Wakeup fail (Impact 1)",""
   "LCPD-24541","am654x-evm","am65xx OSPI boot does not work",""
   "LCPD-24537","am654x-evm,am64xx-evm,am64xx-hsevm","am654x-idk nslookup times out when all netwokring interfaces are active",""
   "LCPD-24456","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am62xx-sk,am64xx_sk-fs,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j721e-hsevm,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j7200-evm,j7200-hsevm,omapl138-lcdk","Move IPC validation source from github to git.ti.com",""
   "LCPD-24319","am654x-evm","am654x-evm DRM tests fail due to frequency mismatch (Impact 7)",""
   "LCPD-24288","am64xx-evm,am64xx-hsevm","am64xx-evm NCM/ACM network performance test crashes with RT images",""
   "LCPD-24134","am654x-evm","AM654x CAL DMABUF tests fail (Impact 4.0)",""
   "LCPD-24130","am654x-evm","AM654x: USB MSC boot mode fails",""
   "LCPD-24128","am654x-idk","Performance issues with CPSW/ICSSG Linux Driver",""
   "LCPD-23008","am654x-evm","AM65xx - display port scenario not enabled",""
   "LCPD-23007","am654x-evm","k3-am654-evm-hdmi.dtbo file is missing in CoreSDK for am654x",""
   "LCPD-22959","am654x-evm","UART Read/Write tests at baud rate 115200 fails",""
   "LCPD-22947","am654x-evm","Alsa performance test fails [waiting for TF]",""
   "LCPD-22912","am64xx-evm","am64xx-evm SMP dual core test fails sporadically",""
   "LCPD-22892","am654x-evm,am654x-idk,am64xx-evm","icssg: due to FW bug both interfaces has to be loaded always",""
   "LCPD-22834","am64xx-evm","am64xx-evm stress boot test fails",""
   "LCPD-22715","am62xx_sk-fs,am62xx_sk-se,am62xx-sk,j721e-idk-gw,j721s2-evm,j721s2_evm-fs,j7200-evm","i2232: DDR: Controller postpones more than allowed refreshes after frequency change","Workaround 1:Disable dynamic frequency change by programing DFS_ENABLE = 0"
   "LCPD-22215","am64xx-evm","PCIE NVM card stops enumerating on am64xx after some time",""
   "LCPD-20705","am64xx-evm","USB stick attached to PCIe USB card is not enumerated",""
   "LCPD-20105","am64xx-evm","AM64x: Kernel: ADC: RX DMA channel request fails",""
   "LCPD-20006","am64xx-evm","AM64x: remoteproc may be stuck in the start phase after a few times of stop/start",""
   "LCPD-19580","am654x-evm","am654- unable to select a mode (sdhci?)",""
   "LCPD-18854","am64xx-evm,dra71x-evm,dra76x-evm","ov5640 sensor capture fails for raw format capture",""
   "LCPD-18665","am654x-evm,am654x-idk","Am65x Pg2: Board cannot do soft reboot when booting from SD card",""
   "LCPD-18297","am654x-evm","AM6: OV5640: 176x144 does not work",""
   "LCPD-17673","am654x-evm,am335x-evm,am43xx-gpevm,am571x-idk,am572x-idk,am574x-idk,am57xx-evm,beaglebone-black,dra71x-evm,dra72x-evm,dra7xx-evm,j721e-evm","No software documentation for the Timer module",""
   "LCPD-17449","am654x-evm,am654x-idk,am654x-hsevm,am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,beaglebone,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm","libasan_preinit.o is missing in devkit",""
   "LCPD-16534","am654x-evm,am654x-idk","remoteproc/k3-r5f: PDK IPC echo_test image fails to do IPC in remoteproc mode on second run","None"



|

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20


   "LCPD-34952","Crypto: ti-udma 485c0000.dma-controller: PSI-L pairing fails during boot up","am62xx-sk"
   "LCPD-34943","AM62a: Wrong TARGET_BOARD in the build command of ATF source code","am62axx_sk-fs,am62axx_sk-se"
   "LCPD-34940","Kernel crash when encoder and decoder are pipelined simultaneously","am62axx_sk-se"
   "LCPD-34929","Remoteproc load of C7x from U-boot fails on 9.0 RC3","am62axx_sk-fs"
   "LCPD-34915","AM62x: op-tee with HW TRNG crashes after Deep Sleep","am62xx_sk-fs,am62xx-sk"
   "LCPD-34911","Boot failure when CONFIG_SPL_NET is enabled","am62xx-sk"
   "LCPD-34905","AM62X Uboot source links are broken","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-34897","AM62x-LP: USB failures ","am62xx_lp_sk-fs"
   "LCPD-34852","Few times payload is packed at size boundary by binman ","am654x-evm,am64xx-evm,am62xx_sk-se,j721e-idk-gw,j721s2-evm,j7200-evm"
   "LCPD-34840","AM64: Networking failures including ICSSG","am64xx-hsevm"
   "LCPD-34833","AM62: Wi-Fi not functional after 6.1/kirkstone migration","am62xx_sk-fs,am62xx-sk"
   "LCPD-34755","am62a: HDMI related crashes","am62axx_sk-fs"
   "LCPD-34697","am64x: dtsi: mcu_gpio0 compatible property typo","am64xx-evm,am64xx_sk-fs"
   "LCPD-34693","am62: CPSW TCP bidir tests fail","am62xx_sk-fs,am62axx_sk-fs,am62xx-sk"
   "LCPD-34687","MMC itapdly sel values are not specified in kernel DTS","am64xx-evm,am64xx_sk-fs"
   "LCPD-34686","MMC itapdly sel values are not specified in uboot DTS","am64xx-evm,am62axx_sk-fs"
   "LCPD-34650","AM62A SDK 8.6 docs missing CPSW link","am62axx_sk-fs"
   "LCPD-34637","AM62x: CPSW2G unit tests failing inconsistently","am62xx-sk"
   "LCPD-34626","AM62: Random Boot Failures and system is unstable","am62xx_sk-fs,am62xx-sk"
   "LCPD-34583","AM64x: some sdcards boot fail in u-boot","am64xx-evm,am64xx_sk-fs"
   "LCPD-34568","Documentation for doing remoteproc from U-Boot.","am62axx_sk-fs"
   "LCPD-34548","k3-image-gen generate error messages","am64xx-evm"
   "LCPD-34545","Am62 components present in OPTEE document","am62axx_sk-fs"
   "LCPD-34531","AM62a: eMMC LTP tests failure","am654x-evm,am62axx_sk-fs"
   "LCPD-34520","AM65: USB and PCIE DT overlays doesnt exist","am654x-evm,am654x-idk"
   "LCPD-34519","IPC: IPC_S_FUNC_RPMSG_SAMPLE_CLIENT test failures","am62axx_sk-fs,am62xx-sk,am68_sk-fs,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-34516","USBHOST Audio ltp unit test fails","am62xx_sk-fs,am62xx-sk,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-34414","AM65: Missing k3-am654-pcie-usb3 from kirkstone build","am654x-evm"
   "LCPD-34413","RT Linux: Interrupt latency issue with >200us outliers","am654x-evm,am654x-hsevm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-sk,am64xx_sk-fs,j721e-sk,j721s2-evm,j721s2_evm-fs,j7200-evm,j784s4-evm"
   "LCPD-34398","Uboot: AM62a boot reporting wrong SOC name","am62axx_sk-fs"
   "LCPD-34379","OP-TEE xtest fails","am62xx-sk"
   "LCPD-34378","U-Boot: AM62x document SRAM layout","am62xx_lp_sk-fs"
   "LCPD-34376","FPDLink: DS90UB960: Support CSI-1 port","am62axx_sk-fs,am62axx_sk-se"
   "LCPD-34362","U-Boot: SDK v8.6 throws ""Unidentified board claims AM62B-SKEVM in eeprom header"" into Boot Log","am62xx-sk"
   "LCPD-34361","U-Boot: AM62A R5 SPL Insufficient Stack Allocation causes very hard to debug Boot Failures","am62xx_lp_sk-fs"
   "LCPD-34342","Issues with OP-TEE documentation","am62xx-sk"
   "LCPD-34316","AM65x : ICSSG : Switching between Dual EMAC and Switch mode fails","am654x-idk"
   "LCPD-34293","Doc: AM62/AM62A: Missing u-boot remoteproc support","am62axx_sk-fs,am62xx-lp-sk,am62xx-sk"
   "LCPD-34258","Upstream: kernel: Bug: ""ti,j721e-esm"" should be described  bindings and devicetree update","am654x-evm,am654x-idk,am64xx-evm,am64xx_sk-fs,am68_sk-fs,am69_sk-fs,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2_evm-fs,j7200-evm,j784s4-evm"
   "LCPD-34229","am65x: UART boot inconsistent failures due to timeout errors ","am654x-hsevm"
   "LCPD-34144","CSI2-RX driver failure when Linux boots from OSPI NAND","am62axx_sk-fs,am62axx_sk-se"
   "LCPD-34131","AM62: Boot inconsistencies on HS FS","am62xx_sk-fs"
   "LCPD-34125","AM65x Linux SDK : Missing ICSSG Performance numbers","am654x-evm,am654x-idk"
   "LCPD-34104"," ICSSG interface statistics rx_total_bytes don't match tx_total_bytes (eth1 -> eth3)","am654x-evm,am654x-idk"
   "LCPD-32960","Documentation: default config to be used for each platform is not clear","am62axx_sk-fs,am62axx_sk-se"
   "LCPD-32958","AM6xx/J7: Issue with MCSPI clocking in Linux driver","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xx-lp-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-32946","RT Linux: PRU Ethernet link down causes kernel crash","am654x-evm,am654x-idk,am64xx-evm"
   "LCPD-32826","Uboot: AM62x/AM62a: R5 SPL loading A53 “tispl.bin” dependency on BOOTMOOD[7] from eMMC boot","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xx-lp-sk,am62xx-sk"
   "LCPD-32825","PCIe: ls -al /dev/disk/by-id shows no nvme device","am64xx-hsevm"
   "LCPD-32823","ICSS firmware does not process Rx packets once Min error frame is received","am654x-idk,am64xx-evm"
   "LCPD-32815","Packet get truncated on Transmit side when high traffic is applied","am654x-idk,am64xx-evm"
   "LCPD-32809","AM62x: RProc: R5 fails with low power mode enabled","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-32790","AM62A: VPU: Module load/unload in loop fails after bootup","am62axx_sk-fs"
   "LCPD-32728","AM62x, AM62a: Doc: Update HS FS Migration Guide","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xx-lp-sk,am62xx-sk"
   "LCPD-32698","Update GPIO numbers for AM62X in the DTSI file ","am62xx-lp-sk,am62xx-sk"
   "LCPD-32480","Image authentication failure at A53 SPL in OSPI NOR boot mode","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-32356","AM62x: tcrypt doesn't use sa2ul for SHA256/512 or any other alg","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-lp-sk,am62xx-sk"
   "LCPD-30075","AM62ax: Enable distro bootcommand","am62axx_sk-fs,am62axx_sk-se"
   "LCPD-29942","AM62x: Upstream: Add boot mode switch settings","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62axx_sk-fs,am62axx_sk-se,am62xx-lp-sk,am62xx-sk"
   "LCPD-29880","CAN_S_FUNC_MODULAR test fail","am64xx-evm,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-29874","am62x: robustness: fails to boot 100 reboot test consistently","am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62xx-sk"
   "LCPD-29854","MCU UART TX baud rate is doubled","am64xx-evm,am64xx-hsevm,am64xx-hssk,am64xx_sk-fs"
   "LCPD-29739","AM64: NAND device not detected in U-boot","am64xx-hsevm"
   "LCPD-29651","AM64: NAND Flash device not detected","am64xx-hsevm"
   "LCPD-29635","PCIe: x2 lane configuration is non functional","am654x-idk"
   "LCPD-29597","AM64x: dts: main_rti nodes are defined twice","am64xx-evm"
   "LCPD-29589","AM62x CPSW: PPS example not enabled by default","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-lp-sk,am62xx-sk"
   "LCPD-29588","CPSW documentation: Time Sync Router no longer firewalled","am654x-evm,am654x-idk,am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-lp-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-29508","AM64x: EMMC speed test fails: MMC not running on HS400 mode","am64xx-evm,am64xx-hsevm,am64xx_sk-fs"
   "LCPD-29500","AM64x: ETH CPSW2g TAS: tests fail with undefined method error","am64xx-evm,am64xx-hsevm,am64xx_sk-fs"
   "LCPD-29499","AM64x: ETH CPSW2g TAS: tests fail with queue 0 did not increase","am64xx-evm,am64xx-hsevm,am64xx_sk-fs"
   "LCPD-29498","AM64x: ETH CPSW2g TAS: Invalid traffic schedule","am64xx-evm,am64xx-hsevm,am64xx_sk-fs"
   "LCPD-29446","Linux SDK docs should explicitly state what peripherals are supported","am654x-evm,am654x-idk,am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am335x-evm,am335x-ice,am335x-sk,am43xx-gpevm,am437x-idk,am437x-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-29442","Docs: AM62x-SK: Kernel User Guide uses tisdk_am64xx defconfigs","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-29397","AM65x Linux SDK lists unsupported industrial protocols","am654x-evm,am654x-idk"
   "LCPD-29362","AM64x EVM Devicetree should disable unused MCU peripherals","am64xx-evm,am64xx_sk-fs"
   "LCPD-29339","Processor SDK 8.3 AM62x lacks RT Linux performance numbers","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-29305","AM64x Uboot SRAM addresses are outdated","am64xx-evm,am64xx_sk-fs"
   "LCPD-29300","U-Boot: OSPI-NOR: sf probe shows 0 randomly","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-28950","CSI2 Multi-capture channel 0 not working","am62axx_sk-fs"
   "LCPD-28764","AM62x: Cannot resume from low power mode","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-28688","AM62x Kernel User Guide: Document AM62x default kernel config","am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-lp-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-28672","CPSW: Add more details about driver config","am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62axx_sk-fs,am62xx-sk,am64xx_sk-fs"
   "LCPD-28660","AM64x: tiboot3.bin generated by U-Boot build is confusing users","am64xx-evm,am64xx-hsevm,am64xx_sk-fs"
   "LCPD-28614","AM62x: RPMsg client driver sample does not work","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-28414","AM62x EVM Devicetree should disable unused MCU peripherals","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-28156","Mcasp: Buffer underflow warnings","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-28105","Automated test failure - CPSW failure doing runtime pm","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-26692","Hardware + Software IPSec Performance Test Failures","am64xx-evm,am335x-evm,am43xx-gpevm,am57xx-evm,j721e-idk-gw"
   "LCPD-25652","am62: sk: reset-gpio property for sil9022a","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-25526","rproc_get() failure on certain race conditions","am654x-idk"
   "LCPD-25314","ICSSG: Timestamp for back-to-back with IPG < 100us not received","am654x-evm,am654x-idk,am654x-hsevm"
   "LCPD-24649","dma-heaps-test fails to build with 5.16-rc3 kernel+","am64xx-evm,am335x-evm,dra71x-evm,j721e-idk-gw"
   "LCPD-24199","AM654x UART HWFLOW FUNC, PERF, STRESS tests fail (Impact 2)","am654x-evm"
   "LCPD-23020","am64xx-evm: U-Boot PHY autonegotiation failed 2 out of 100 times","am64xx-evm"
   "LCPD-23011","Missing u-boot README file for AM64x","am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62xx-sk,am64xx_sk-fs"
   "LCPD-22931","RemoteProc documentation missing","am654x-evm,am654x-idk,am64xx-evm,am64xx_sk-fs"
   "LCPD-22324","ICSSG port does not drop packets with SA matching interface MAC","am654x-idk"
   "LCPD-22319","OpenSSL performance test data out of bounds","am64xx-evm,am62axx_sk-fs,am62xx-sk,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-20686","am65xx mainline build with dunfell is missing rproc test images","am654x-evm"
   "LCPD-20038","OPTEE test applications are missing from rootfs","am64xx-hsevm"
   "LCPD-20014","remoteproc: TX_PRU: IRQ vring, IRQ kick not found error message on console","am654x-evm,am654x-idk,am654x-hsevm"
   "LCPD-18788","Uboot: Could not bring up PCIe interface","am654x-idk"
   "LCPD-18627","uboot does not read the reserve-memory from the fdt ","am654x-idk"
   "LCPD-16406","Seeing ""e1000#0: ERROR: Hardware Initialization Failed"" sometimes when do dhcp via pcie-eth","am654x-idk"
   "LCPD-15873","There is no dtbo in u-boot for PCIe x1 + usb3 daughter card","am654x-evm"
   "LCPD-14843","U-boot should support  default settings for netboot ","am654x-evm,am654x-idk"



|


Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-37162","Boot: Add CPSW2 Ingress/Egress performance tests to 9.1 testsplan","am62axx_sk-fs"
   "LCPD-37161","Boot: Add Crypto performance tests to 9.1 testsplan","am62pxx_sk-fs"
   "LCPD-37160","Add SoC Audio performance benchmarks to 9.1 testplans","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs"
   "LCPD-37158","Boot: Add MMCSD performance tests to 9.1 testsplan","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"
   "LCPD-37157","Add ARM performance benchmarks to 9.1 testplans","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"
   "LCPD-37151","am62: am64: i2c set/get tests are failing","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62xx-sk"
   "LCPD-37095","SDK: Linux: Add DD52 speed mode for MMC0","am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-37094","SDK: Linux: Enable HS400 speed mode for MMC0","am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-37091","Upstream boot breakage: Am62x, AM62Ax","am62xx_sk-fs,am62axx_sk-fs"
   "LCPD-37057","AM62x: Power management suspend/resume fail","am62xx_sk-fs"
   "LCPD-37046","SDK: Fix DMA drain buffer size","am62xx_sk-fs,beagleplay-gp,am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"
   "LCPD-37029","AM62: Suspend / Resume Test Failure: 29000000.mailbox failed to suspend","am62xx_sk-fs,am62xx_sk-se,am62axx_sk-fs,am62pxx_sk-fs"
   "LCPD-36989","AM62P: eMMC HS400 fails","am62pxx_sk-fs"
   "LCPD-36984","AM62: USB driver does not configure USB0_PHY_CTRL_CORE _VOLTAGE","am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se"
   "LCPD-36968","am65x/debug: Display breaks with sysfw","am654x-evm,am654x-idk,am654x-hsevm"
   "LCPD-36947","AM65: eMMC/MMC tests fail","am654x-evm,am654x-idk"
   "LCPD-36944","AM62P: OSPI tests fails ","am62pxx_sk-fs"
   "LCPD-36943","AM62P: eMMC boot fails","am62pxx_sk-fs"
   "LCPD-36942","AM62P: CPUFreq unit test fail","am62pxx_sk-fs"
   "LCPD-36914","am654: ICSSG Performance degradation","am654x-idk"
   "LCPD-36850","HSR switching offload firmware needs to be loaded twice","am64xx-hsevm"
   "LCPD-36847","doc: ltp-ddt documentation is not upto date","am64xx-hsevm,am62xx_sk-fs,am62axx_sk-fs,am62pxx_sk-fs,am68_sk-fs,am69_sk-fs,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-36843","am62xxsip_sk-se Boot Failure","am62xxsip_sk-se"
   "LCPD-36813","SoC Detection test fails","am62xxsip_sk-fs,am62xxsip_sk-se"
   "LCPD-36808","LPM: SK-AM62: DeepSleep broken with 09.00+ onwards","am62xx_sk-fs"
   "LCPD-36786","am62sip: soc detect failure warning seen","am62xxsip_sk-fs"
   "LCPD-36764","CSI: Wrong pixelformat in saved frames for YUYV","am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-36754","AM62 LP SK: Uart boot broken","am62xx_lp_sk-fs,am62xx_lp_sk-se"
   "LCPD-36744","Linux SDK: CPSW: Bridge interface cannot ping in Switch Mode","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am64xx_sk-fs,am64xx_evm-se,am64xx_sk-se,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm,j784s4-evm,j784s4-hsevm"
   "LCPD-36654","USB PHY pllrefsel is configured after USB LPSC enabled","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se"
   "LCPD-36653","modprobe -r dwc3-am62 fails","am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se"
   "LCPD-36645","AM64X: Linux HSR - Multicast filtering support","am64xx-evm"
   "LCPD-36621","K3: OPENSSL: Fix testcases and make it platform specific","am62xx_sk-se,am62axx_sk-fs,am64xx_sk-fs,am68_sk-fs,am69_sk-fs,j721e-idk-gw,j721e-sk,j721s2-evm,j7200-hsevm,j784s4-evm"
   "LCPD-36612","TMDX654IDKEVM: Clock jump of PTP device for ICSSG #2","am654x-idk"
   "LCPD-36588","eMMC boot fails after flashing via USB DFU","am62pxx_sk-fs"
   "LCPD-36587","U-Boot: CPSW: Phy-Mode not configured correctly for ports","am64xx-evm,am64xx-hsevm,am62xx_sk-fs,am62xx_sk-se,am64xx_sk-fs,am64xx_sk-se"
   "LCPD-36578","AM65: USB hub on the daughter card does not work OOB ","am654x-evm,am654x-idk"
   "LCPD-36573","doc: am62ax: build instructions for ATF are incorrect","am62axx_sk-fs,am62axx_sk-se"
   "LCPD-36549","ICSSG: Ping to bridge not working in switch mode","am654x-idk,am64xx-hsevm"
   "LCPD-36517","TCP Performance Failure","am654x-idk"
   "LCPD-36510","BitBake Network Connectivity Check","am654x-hsevm"
   "LCPD-36494","Migrate to OPTEE 4.0.0 to address PSIRT","am62xx_sk-fs,am62axx_sk-fs,am64xx_sk-fs,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-36473","ICSSG UDP Performance Failure","am64xx-hsevm"
   "LCPD-36403","Rx Stall during Uboot in presence of Broadcast Traffic","am654x-evm,am654x-idk"
   "LCPD-36397","Thermal devices not enumerated on SDK 9.0","am62xx_sk-fs"
   "LCPD-36367","ETH_CPSW2g_Unicast Test nping Install Error ","am62xx-sk"
   "LCPD-36339","AM62A RT Linux SDK does not document cyclictest performance","am62axx_sk-fs"
   "LCPD-36325","MMC Error Getting Device Node","am654x-idk,j784s4-evm"
   "LCPD-36287","Doc: Update Toolchain documentation to 11.2+","am62xx_sk-fs,am64xx_sk-fs,j721e-idk-gw"
   "LCPD-35396","AM62X Update MCAN doc for 3x MCAN","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-35395","IMX390 Multicapture does not work with gstreamer","am62axx_sk-fs,am62axx_sk-se,am62axx_sk-hs4,am62axx_sk-hs5,am68_sk-fs,am69_sk-fs,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j721s2_evm-se,j784s4-evm,j784s4-hsevm"
   "LCPD-35382","Linux crashing when unloading/loading camera modules","am62xx_sk-fs"
   "LCPD-35361","Camera capture hanging on AM62x SK","am62xx_sk-fs"
   "LCPD-35309","kmssink and tidss odd plane behavior on 9.0","am62xx_sk-fs"
   "LCPD-35308","v4l2src wrong pool size is set, bug introduced in v4l2h264dec dmabuf_import patch","am62axx_sk-fs,am68_sk-fs,j721s2-evm"
   "LCPD-35300","Doc Bugs - Link/Add TISCI chapters and remove MSMC chapter ","am64xx-hsevm,am62xx_sk-fs"
   "LCPD-35109","AM62x SK: OSPI NOR DFU fails ","am62xx_sk-fs"
   "LCPD-35108","AM64x: eMMC boot fails using flashed using DFU ","am64xx-evm"
   "LCPD-35083","AM62: PRU rpmsg samples echo sample FW are not getting installed","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se"
   "LCPD-35054","AM62x LP fitImage boot issue with Yocto images","am62xx_lp_sk-fs,am62xx_lp_sk-se"
   "LCPD-35043","Doc: VPU performance and capabilities shown incorrectly for AM62Ax","am62axx_sk-fs"
   "LCPD-35039","Doc: Improve audio documentation","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xx-lp-sk"
   "LCPD-35033","AM64: ICSSG VLAN testcase is failing in 9.0-rc6","am64xx-hsevm"
   "LCPD-35009","doc: ubi format should be ubiformat","am62xx-sk"
   "LCPD-34994","AM64x: fitImage not booting","am64xx-hsevm"
   "LCPD-34993","AM64x: sf probe fails on hs-fs","am64xx-hsevm"
   "LCPD-34992","AM64x DFU Boot fails with signed images","am64xx-hsevm"
   "LCPD-34980","Serial Nand flash is not discovered from uboot and kernel","am62axx_sk-fs"
   "LCPD-34978","AM62x: High tiny-image cpio file size","am62xx_sk-fs,am62xx-sk"
   "LCPD-34976","AM62a: HS-SE : Fails to boot : Firewall Exception","am62axx_sk-se"
   "LCPD-34967","AM62a: SD Boot fails with warning ""alloc space exhausted""","am62axx_sk-fs"
   "LCPD-34966","rpmsg_ctrl device mapping errors see with 6.1 kernel","am64xx-evm,am62xx_sk-fs,am62axx_sk-fs,am62xx-lp-sk,am62xx-sk,am64xx_sk-fs,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721s2-evm,j784s4-evm"



|

