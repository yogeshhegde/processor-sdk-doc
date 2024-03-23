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

Release 09.02.00
================

Released on March 2024

What's new
------------------

**Processor SDK Linux AM62X Release has following new features:**

  - Kernel: MMC Highspeed tuning and Performance Improvements
  - RT Kernel : Significant Improvements to Real-Time Linux Interrupt Latency, :ref:`RT Interrupt Latencies <RT-linux-performance>`
  - DDR: Stable Config Update, Single and multi-bit DDR ECC Support
  - Power Management: DeepSleep, MCU-Only and Partial IO mode :ref:`Power Management Overview <Power-Management>`
  - OOB: GPU Accelerated Chromium Browser Support
  - Bug Fixes and Stability Improvements


**Component version:**

  - Kernel 6.1.80
  - RT Kernel 6.1.80-rt26
  - U-Boot 2023.04
  - Toolchain GCC 11.4
  - ATF 2.10
  - OPTEE 4.1
  - Graphics DDK 23.3

Build Information
=================

.. _u-boot-release-notes:

U-Boot
------------------

.. rubric:: u-boot
   :name: u-boot

| Head Commit: f9b966c674731a1a29a20a8e143c61d4e046f13c configs: am62x_android_a53.config: Disable splashscreen
| Date: 2024-03-21 08:39:16 -0500
| uBoot Version: 2023.04
| uBoot Description: RC Release 09.02.00.009
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2023.04
| uBoot Tag: 09.02.00.009
|

.. _tf-a-release-notes:

TF-A
------------------
| Head Commit: 00f1ec6b8740ccd403e641131e294aabacf2a48b Merge changes from topic "revert-ti-dm-workaround" into integration
| Repo: https://git.trustedfirmware.org/TF-A/trusted-firmware-a.git
| Branch: master
| Tag: 2.10
|

.. _optee-release-notes:

OP-TEE
------------------
| Head Commit: 012cdca49db398693903e05c42a254a3a0c0d8f2 plat-k3: drivers: sec_proxy: increment while reading trail bytes
| Repo: https://github.com/OP-TEE/optee_os/
| Branch: master
| Tag: 4.1.0
|

.. _ti-linux-fw-release-notes:

ti-linux-firmware
------------------
| Head Commit: 553da6850e271b579b569725ce9c58a1a6d7c849 ti-dm: Update firmware for j784s4
| Date: 2024-03-21 08:39:13 -0500
| Clone: https://git.ti.com/cgit/processor-firmware/ti-linux-firmware
| Branch: ti-linux-firmware
| Tag: 09.02.00.009
|

Kernel
------------------

.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 2e423244f8c09173a344e7069f0fe2bdf26cccee net: ethernet: ti: icssg-prueth: Fix RX frame drops in XDP
| Date: 2024-03-21 08:39:05 -0500
| Kernel Version: 6.1.80
| Kernel Description: RC Release 09.02.00.009

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-6.1.y
| Tag: 09.02.00.009
| use-kernel-config=defconfig
| config-fragment=kernel/configs/ti_arm64_prune.config
|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 3c08dbfd7bfd83c247ad1ee4ddb989260c150af1 Merge branch 'ti-linux-6.1.y-cicd' into ti-rt-linux-6.1.y-cicd
| Date: 2024-03-21 08:39:09 -0500
| Kernel Version: 6.1.80-rt26
| Kernel Description: RC Release 09.02.00.009-rt

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-6.1.y
| Tag: 09.02.00.009-rt
| use-kernel-config=defconfig
| config-fragment=config-fragment=kernel/configs/ti_arm64_prune.config kernel/configs/ti_rt.config
|

Yocto
------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 376a2143533c6497b4e79304eccca2a630784436 CI/CD Auto-Merger: cicd.kirkstone.202403201028
| Date: 2024-03-21 08:39:18 -0500

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: kirkstone
| Release Tag: 09.02.00.009
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: 98f178314931635c8641d1394dfd4341b86b6be2 CI/CD Auto-Merger: cicd.kirkstone.202403201028
| Date: 2024-03-21 08:38:40 -0500

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: kirkstone
| Release Tag: 09.02.00.009
|

.. rubric:: meta-tisdk
   :name: meta-tisdk

| Head Commit: 9131d1afc1b69d423786d100bc346949f4426b08 Fix 62x/62p build for jailhouse and RT build
| Date: 2023-12-13 04:19:26 -0600

| Clone: git://git.ti.com/ti-sdk-linux/meta-tisdk.git
| Branch: kirkstone
| Release Tag: 09.01.00.08
|

Issues Tracker
=====================================

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 30, 150

   "LCPD-27887","i2327: RTC: Hardware wakeup event limitation","am62xx_sk-fs,am62xxsip_sk-fs,am62xxsip_sk-se,am62xx-sk"
   "LCPD-27886","USART: Erroneous clear/trigger of timeout interrupt","am64xx-evm,am62axx_sk-fs,am62xxsip_sk-fs,am62xxsip_sk-se,am62xx-sk,j721e-idk-gw,j7200-evm,j784s4-evm,j784s4-hsevm"

|

U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-36846","am62xx_sk-fs","u-boot usb reset comamnd fails",""
   "LCPD-36618","am62xxsip_sk-fs,am62xxsip_sk-se","AM62SIP:  reserving fdt memory region failed error seen at bootup",""
   "LCPD-34951","am62xx-sk","Board not booting up",""
   "LCPD-28503","am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62xx-sk,am64xx_sk-fs","Need to sync up DTS files between u-boot and kernel for at least AM62x, possibly other boards too",""

|

Linux Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35

   "LCPD-37150","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62xx-sk","am62: i2c bus speed test is failing",""
   "LCPD-37141","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62pxx_sk-fs","AM62x: Sync up USB R5 defconfigs with main R5 defconfig",""
   "LCPD-37076","am62xx_sk-fs,am62xx_sk-se","OP-TEE: RNG handling during suspend/resume",""
   "LCPD-36978","am62xxsip_sk-fs,am62xxsip_sk-se","AM62xSiP: DeepSleep: Suspend-Resume not working",""
   "LCPD-36950","am62xx_sk-fs,am62axx_sk-fs,am62pxx_sk-fs","crypto openssl performance test fail",""
   "LCPD-36925","am62xx_lp_sk-fs,am62xx_lp_sk-se","am62xx-lp-sk: power down from automation interface behaves differently between U-Boot and kernel",""
   "LCPD-36848","am62xx_sk-fs,j721e-idk-gw","J721E: Occasional SPI-NOR write timeout under high load",""
   "LCPD-36812","am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se","RTC: tests fail",""
   "LCPD-36811","am62xx_sk-fs,am68_sk-fs,am69_sk-fs","MM: Weston should assign 0 zpos to primary plane",""
   "LCPD-36805","am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se","ETHERNET boot test fail incorrect configuration",""
   "LCPD-36804","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am64xx_sk-fs,am64xx_evm-se,am64xx_sk-se","IPC performance test fail - modprobe fails",""
   "LCPD-36803","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se","USBDEV:  test case fail - USB devices not enumerated",""
   "LCPD-36801","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se","USB-DFU boot test fail incorrect configuration",""
   "LCPD-36631","am62xx_sk-fs","AM625 SK EVM duplicate mbox node",""
   "LCPD-36575","am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se","AM62Q: AM62A: OSPI:  tuning fails at certain PVTs",""
   "LCPD-36524","am62xx_sk-fs","AM62x: sa2ul doesn't work after deepsleep",""
   "LCPD-36361","am64xx-hsevm,am62xxsip_sk-se","Boot failure over UART",""
   "LCPD-36282","am62xx-sk","OV5640 capture not working at two highest resolutions",""
   "LCPD-35042","am62xx_sk-fs,am62xx_sk-se,am62xx-sk,am62xx_sk-hs4,am62xx_sk-hs5","Linux: AM62x: OSPI NOR Flash read speed is low (~2.5MBPS)",""
   "LCPD-34912","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62axx_sk-hs4,am62axx_sk-hs5,am62xx-lp-sk,am62xx-sk,am62xx_sk-hs4,am62xx_sk-hs5","AM62/AM62Ax: DM does not set correct pixel clock",""
   "LCPD-34906","am62xx-sk","R5 SPL OSPI NOR with PHY calibration not working",""
   "LCPD-34901","am62xx_sk-fs,am62xx-sk","AM62: Reset button fails to reset AM625-SK-EVM after wakeup from deep sleep",""
   "LCPD-34898","am62xx_sk-fs,am62xx-sk","AM62x: MCU Only mode: Linux console lockup after ~100 suspend resume cycles",""
   "LCPD-34835","am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs","am62/am62a: Add CTRL MMR support for DPI signals on negative edge",""
   "LCPD-34813","am62xx_sk-fs,am62xx_sk-se,am62xx-sk,am62xx_sk-hs4,am62xx_sk-hs5","SK-AM62B: Flood of tps6598x_interrupt failed to read events",""
   "LCPD-34343","am62xx-sk","SDK: Am62x: Openssl commands for openssl_perf.sh gives wrong results",""
   "LCPD-34242","am62xx_sk-fs,am62xxsip_sk-fs,am62xxsip_sk-se,am62xx-sk,am68_sk-fs,am69_sk-fs,j721s2-evm,j7200-evm,j784s4-evm","GPIO_S_FUNC_DIR_IN_ALL_BANK unit test fails",""
   "LCPD-34105","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62axx_sk-hs4,am62axx_sk-hs5,am62xx-lp-sk,am62xx-sk,am62xx_sk-hs4,am62xx_sk-hs5","convert uboot's MDIO driver over to use the driver model",""
   "LCPD-32706","am62xx_sk-fs,am62xx-sk","Display: DRM tests fail inconsistently",""
   "LCPD-29332","am62xx_sk-fs,am62xx_sk-se,am62xx-sk","LPM Demo not Working on Linux RT",""
   "LCPD-28448","am62xx_sk-fs,am62xx_sk-se,am62xx-sk","Wall time does not account for sleep time",""
   "LCPD-28104","am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62xx-sk","Automated test failure - CPSW test is passing invalid parameters to switch-config",""
   "LCPD-24456","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am62xx-sk,am64xx_sk-fs,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j721e-hsevm,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j7200-evm,j7200-hsevm,omapl138-lcdk","Move IPC validation source from github to git.ti.com",""
   "LCPD-22715","am62xx_sk-fs,am62xx_sk-se,am62xx-sk,j721e-idk-gw,j721s2-evm,j721s2_evm-fs,j7200-evm","i2232: DDR: Controller postpones more than allowed refreshes after frequency change","Workaround 1:Disable dynamic frequency change by programing DFS_ENABLE = 0"

|

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-34952","Crypto: ti-udma 485c0000.dma-controller: PSI-L pairing fails during boot up","am62xx-sk"
   "LCPD-34915","AM62x: op-tee with HW TRNG crashes after Deep Sleep","am62xx_sk-fs,am62xx-sk"
   "LCPD-34911","Boot failure when CONFIG_SPL_NET is enabled","am62xx-sk"
   "LCPD-34905","AM62X Uboot source links are broken","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-34897","AM62x-LP: USB failures ","am62xx_lp_sk-fs"
   "LCPD-34852","Few times payload is packed at size boundary by binman ","am654x-evm,am64xx-evm,am62xx_sk-se,j721e-idk-gw,j721s2-evm,j7200-evm"
   "LCPD-34833","AM62: Wi-Fi not functional after 6.1/kirkstone migration","am62xx_sk-fs,am62xx-sk"
   "LCPD-34693","am62: CPSW TCP bidir tests fail","am62xx_sk-fs,am62axx_sk-fs,am62xx-sk"
   "LCPD-34637","AM62x: CPSW2G unit tests failing inconsistently","am62xx-sk"
   "LCPD-34626","AM62: Random Boot Failures and system is unstable","am62xx_sk-fs,am62xx-sk"
   "LCPD-34519","IPC: IPC_S_FUNC_RPMSG_SAMPLE_CLIENT test failures","am62axx_sk-fs,am62xx-sk,am68_sk-fs,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-34516","USBHOST Audio ltp unit test fails","am62xx_sk-fs,am62xx-sk,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-34413","RT Linux: Interrupt latency issue with >200us outliers","am654x-evm,am654x-hsevm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-sk,am64xx_sk-fs,j721e-sk,j721s2-evm,j721s2_evm-fs,j7200-evm,j784s4-evm"
   "LCPD-34379","OP-TEE xtest fails","am62xx-sk"
   "LCPD-34378","U-Boot: AM62x document SRAM layout","am62xx_lp_sk-fs"
   "LCPD-34362","U-Boot: SDK v8.6 throws ""Unidentified board claims AM62B-SKEVM in eeprom header"" into Boot Log","am62xx-sk"
   "LCPD-34361","U-Boot: AM62A R5 SPL Insufficient Stack Allocation causes very hard to debug Boot Failures","am62xx_lp_sk-fs"
   "LCPD-34342","Issues with OP-TEE documentation","am62xx-sk"
   "LCPD-34293","Doc: AM62/AM62A: Missing u-boot remoteproc support","am62axx_sk-fs,am62xx-lp-sk,am62xx-sk"
   "LCPD-34131","AM62: Boot inconsistencies on HS FS","am62xx_sk-fs"
   "LCPD-32958","AM6xx/J7: Issue with MCSPI clocking in Linux driver","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xx-lp-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-32826","Uboot: AM62x/AM62a: R5 SPL loading A53 “tispl.bin” dependency on BOOTMOOD[7] from eMMC boot","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xx-lp-sk,am62xx-sk"
   "LCPD-32809","AM62x: RProc: R5 fails with low power mode enabled","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-32728","AM62x, AM62a: Doc: Update HS FS Migration Guide","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xx-lp-sk,am62xx-sk"
   "LCPD-32698","Update GPIO numbers for AM62X in the DTSI file ","am62xx-lp-sk,am62xx-sk"
   "LCPD-32480","Image authentication failure at A53 SPL in OSPI NOR boot mode","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-32356","AM62x: tcrypt doesn't use sa2ul for SHA256/512 or any other alg","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-lp-sk,am62xx-sk"
   "LCPD-29942","AM62x: Upstream: Add boot mode switch settings","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62axx_sk-fs,am62axx_sk-se,am62xx-lp-sk,am62xx-sk"
   "LCPD-29874","am62x: robustness: fails to boot 100 reboot test consistently","am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62xx-sk"
   "LCPD-29589","AM62x CPSW: PPS example not enabled by default","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-lp-sk,am62xx-sk"
   "LCPD-29588","CPSW documentation: Time Sync Router no longer firewalled","am654x-evm,am654x-idk,am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-lp-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-29446","Linux SDK docs should explicitly state what peripherals are supported","am654x-evm,am654x-idk,am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am335x-evm,am335x-ice,am335x-sk,am43xx-gpevm,am437x-idk,am437x-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-29442","Docs: AM62x-SK: Kernel User Guide uses tisdk_am64xx defconfigs","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-29339","Processor SDK 8.3 AM62x lacks RT Linux performance numbers","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-29300","U-Boot: OSPI-NOR: sf probe shows 0 randomly","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-28764","AM62x: Cannot resume from low power mode","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-28688","AM62x Kernel User Guide: Document AM62x default kernel config","am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-lp-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-28672","CPSW: Add more details about driver config","am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62axx_sk-fs,am62xx-sk,am64xx_sk-fs"
   "LCPD-28614","AM62x: RPMsg client driver sample does not work","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-28414","AM62x EVM Devicetree should disable unused MCU peripherals","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-28156","Mcasp: Buffer underflow warnings","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-28105","Automated test failure - CPSW failure doing runtime pm","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-26692","Hardware + Software IPSec Performance Test Failures","am64xx-evm,am335x-evm,am43xx-gpevm,am57xx-evm,j721e-idk-gw"
   "LCPD-25652","am62: sk: reset-gpio property for sil9022a","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-23011","Missing u-boot README file for AM64x","am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62xx-sk,am64xx_sk-fs"
   "LCPD-22319","OpenSSL performance test data out of bounds","am64xx-evm,am62axx_sk-fs,am62xx-sk,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"

|

Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-37160","Add SoC Audio performance benchmarks to 9.1 testplans","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs"
   "LCPD-37158","Boot: Add MMCSD performance tests to 9.1 testsplan","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"
   "LCPD-37157","Add ARM performance benchmarks to 9.1 testplans","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"
   "LCPD-37151","am62: am64: i2c set/get tests are failing","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62xx-sk"
   "LCPD-37091","Upstream boot breakage: Am62x, AM62Ax","am62xx_sk-fs,am62axx_sk-fs"
   "LCPD-37057","AM62x: Power management suspend/resume fail","am62xx_sk-fs"
   "LCPD-37046","SDK: Fix DMA drain buffer size","am62xx_sk-fs,beagleplay-gp,am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"
   "LCPD-37029","AM62: Suspend / Resume Test Failure: 29000000.mailbox failed to suspend","am62xx_sk-fs,am62xx_sk-se,am62axx_sk-fs,am62pxx_sk-fs"
   "LCPD-36984","AM62: USB driver does not configure USB0_PHY_CTRL_CORE _VOLTAGE","am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se"
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
   "LCPD-36621","K3: OPENSSL: Fix testcases and make it platform specific","am62xx_sk-se,am62axx_sk-fs,am64xx_sk-fs,am68_sk-fs,am69_sk-fs,j721e-idk-gw,j721e-sk,j721s2-evm,j7200-hsevm,j784s4-evm"
   "LCPD-36587","U-Boot: CPSW: Phy-Mode not configured correctly for ports","am64xx-evm,am64xx-hsevm,am62xx_sk-fs,am62xx_sk-se,am64xx_sk-fs,am64xx_sk-se"
   "LCPD-36494","Migrate to OPTEE 4.0.0 to address PSIRT","am62xx_sk-fs,am62axx_sk-fs,am64xx_sk-fs,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-36397","Thermal devices not enumerated on SDK 9.0","am62xx_sk-fs"
   "LCPD-36367","ETH_CPSW2g_Unicast Test nping Install Error ","am62xx-sk"
   "LCPD-36287","Doc: Update Toolchain documentation to 11.2+","am62xx_sk-fs,am64xx_sk-fs,j721e-idk-gw"
   "LCPD-35396","AM62X Update MCAN doc for 3x MCAN","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-35382","Linux crashing when unloading/loading camera modules","am62xx_sk-fs"
   "LCPD-35361","Camera capture hanging on AM62x SK","am62xx_sk-fs"
   "LCPD-35309","kmssink and tidss odd plane behavior on 9.0","am62xx_sk-fs"
   "LCPD-35300","Doc Bugs - Link/Add TISCI chapters and remove MSMC chapter ","am64xx-hsevm,am62xx_sk-fs"
   "LCPD-35109","AM62x SK: OSPI NOR DFU fails ","am62xx_sk-fs"
   "LCPD-35083","AM62: PRU rpmsg samples echo sample FW are not getting installed","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se"
   "LCPD-35054","AM62x LP fitImage boot issue with Yocto images","am62xx_lp_sk-fs,am62xx_lp_sk-se"
   "LCPD-35039","Doc: Improve audio documentation","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xx-lp-sk"
   "LCPD-35009","doc: ubi format should be ubiformat","am62xx-sk"
   "LCPD-34978","AM62x: High tiny-image cpio file size","am62xx_sk-fs,am62xx-sk"
   "LCPD-34966","rpmsg_ctrl device mapping errors see with 6.1 kernel","am64xx-evm,am62xx_sk-fs,am62axx_sk-fs,am62xx-lp-sk,am62xx-sk,am64xx_sk-fs,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721s2-evm,j784s4-evm"

|

Linux SDK known issues
----------------------
.. csv-table::
    :header: "Record ID", "Title", "Platform"
    :widths: 15, 70, 20

    "LCPD-37207","Docker is disabled in RT Linux","am64xx-hssk, am62xx_lp_sk-fs, am62xxsip_sk-fs, am62pxx_sk-fs"
    "SITSW-3461","Makefile : Make all fails for am62xx-lp-evm","am62xx-sk-lp"
    "SITSW-3462","Jailhouse: Ivshmem-net driver throws errors while loading jailhouse","am62xx-sk, am62p-sk"

|

