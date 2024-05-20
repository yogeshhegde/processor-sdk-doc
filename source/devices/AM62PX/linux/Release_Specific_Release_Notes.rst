.. _Release-note-label:

#############
Release Notes
#############

Overview
========

The **Processor Software Development Kit (Processor SDK)** is a unified software platform for TI embedded processors
providing easy setup and fast out-of-the-box access to benchmarks and demos.  All releases of Processor SDK are
consistent across TI’s broad portfolio, allowing developers to seamlessly reuse and develop software across devices.
Developing a scalable platform solutions has never been easier than with the Processor SDK and TI’s embedded processor
solutions.

To simplify the end user experience, Processor SDK Linux AM62Px installer provides everything needed as discussed below
to create the embedded system from “scratch” :

-  Platform/board-support software and configuration files for Linux
-  U-Boot and Kernel sources and configuration files
-  An ARM cross-compiling toolchain as well as other host binaries and components
-  A Yocto/OE compliant filesystem and sources for example applications
-  A variety of scripts and Makefiles to automate certain tasks
-  Other components needed to build an embedded system that don’t fit neatly into one of the above buckets
-  Reference Examples, benchmarks

This release supports High Security - Field Securable (HS-FS) devices.

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
----------

**Processor SDK Linux AM62Px Release has following new features:**

  - U-Boot: A53 SPL Splash Screen support :ref:`A53 SPL Splash Overview <Uboot-splash-label>`
  - Kernel: DSI Support, MMC Highspeed tuning and Performance Improvements
  - RT Kernel : Significant Improvements to Real-Time Linux Interrupt Latency, :ref:`RT Interrupt Latencies <RT-linux-performance>`
  - DDR: Stable Config Update, Single and multi-bit DDR ECC Support
  - Power Management: DeepSleep, MCU-Only and Partial IO mode :ref:`Power Management Overview <Power-Management>`
  - OOB: GPU Accelerated Chromium Browser Support :ref:`Chromium Browser <Chromium_Browser-label>`
  - Bug Fixes and Stability Improvements
  - PM: MCU Only mode and Partial I/O mode
  - DM Firmware: PLL Configuration sequence updated to latest recommendation
  - TIFS: HSM infrastructure updates


**Component version:**

  - Kernel 6.1.80
  - RT Kernel 6.1.80-rt26
  - U-Boot 2023.04
  - Toolchain GCC 11.4
  - ATF 2.10
  - OPTEE 4.1
  - Graphics DDK 23.3
  - TIFS Firmware v09.02.07
  - DM Firmware 09.02.00.24

Build Information
=================

.. _u-boot-release-notes:

U-Boot
------

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
----
| Head Commit: 00f1ec6b8740ccd403e641131e294aabacf2a48b Merge changes from topic "revert-ti-dm-workaround" into integration
| Repo: https://git.trustedfirmware.org/TF-A/trusted-firmware-a.git
| Branch: master
| Tag: 2.10
|

.. _optee-release-notes:

OP-TEE
------
| Head Commit: 012cdca49db398693903e05c42a254a3a0c0d8f2 plat-k3: drivers: sec_proxy: increment while reading trail bytes
| Repo: https://github.com/OP-TEE/optee_os/
| Branch: master
| Tag: 4.1.0
|

.. _ti-linux-fw-release-notes:

ti-linux-firmware
-----------------
| Head Commit: 553da6850e271b579b569725ce9c58a1a6d7c849 ti-dm: Update firmware for j784s4
| Date: 2024-03-21 08:39:13 -0500
| Clone: https://git.ti.com/cgit/processor-firmware/ti-linux-firmware
| Branch: ti-linux-firmware
| Tag: 09.02.00.009
|

Kernel
------

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
-----
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

| Head Commit: e2d81f687261309de3441917c53c5a282a4f3e1b jailhouse: Update SRCREV
| Date: 2024-03-22 07:49:05 -0500

| Clone: git://git.ti.com/ti-sdk-linux/meta-tisdk.git
| Branch: kirkstone
| Release Tag: 09.02.01.09
|

.. rubric:: meta-edgeai
   :name: meta-edgeai

| Head Commit: 80b2a8ea999c39f4ee7a951a67b218c3e0a1d6c4 ti-edgeai-firmware: Update SRCREV to get updated j722s FWs 9.2 RC3 tag
| Date: 2024-03-21 13:12:49 -0500

| Clone: https://git.ti.com/git/edgeai/meta-edgeai.git
| Branch: kirkstone
| Release Tag: 09.02.00.03
|

Issues Tracker
==============

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 30, 150

   "LCPD-37081","SNPS: USB2 PHY locks up due to short suspend","am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"

|

Known Issues
------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35

   "LCPD-37750","am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se","SDK Documentation: Formatting: Spacing between Lines seems broken",""
   "LCPD-37714","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se","CAN suspend and loopback tests are failing",""
   "LCPD-37467","am62pxx_sk-fs","AM62P low performance memory benchmark",""
   "LCPD-37342","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62pxx_sk-fs","cpufreq: schedutil: constant switch between CPU OPPs",""
   "LCPD-37226","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se,am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm","Update Ubuntu Host version in Linux documentation",""
   "LCPD-37141","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62pxx_sk-fs","AM62x: Sync up USB R5 defconfigs with main R5 defconfig",""
   "LCPD-36993","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se,am62pxx-zebu,am62lxx-vlab,am62lxx-zebu,am62xx_p0_sk-fs,am64xx_sk-fs,am64xx_evm-se,am64xx_sk-se,am68_sk-fs,am69_sk-fs,beaglebone,bbai,bbai64-gp,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j721s2_evm-se,j7200-evm,j7200-hsevm,j784s4-evm,j784s4-hsevm,j722s_evm-fs,J784S4_BASESIM","U-Boot: lpddr4.c: Error handling missing failure cases",""
   "LCPD-36950","am62xx_sk-fs,am62axx_sk-fs,am62pxx_sk-fs","crypto openssl performance test fail",""
   "SYSFW-5992","am62x,am62ax,am62px","Unable to set exact pixel clock for OLDI LCD display / HDMI Pixel clock",""
   "SYSFW-6432","am62x,am62ax,am62px,am64x,am65x","Set device API doesn't return Error when PD is in transition state",""
   "SYSFW-6426","am62x,am62ax,am62px,am64x,am65x","Ownership of a firewall region can be transferred to an invalid host",""
   "SYSFW-6369","am62x,am62ax,am62px","DM unable to enter deep sleep mode when booting in SBL flow",""
   "SYSFW-7183","am62x,am62px","Warm reset after system LPM entry/exit results in u-boot/DM hang",""
   "SITSW-4288","am62xx-sk, am62xx-sk-lp, am62x-sip-sk, am62p-sk","Debian: Dual-display does not work out-of-box",""
   "SITSW-4287","am62xx-sk-lp, am62x-sip-sk, am62p-sk","Debian: LPM not working on AM62P, AM62LP and AM62SIP",""
   "SITSW-4240","am62xx-sk, am62xx-sk-lp, am62x-sip-sk, am62p-sk","ti-apps-launcher : DeepSleep icon in RT Linux doesn't work & should be removed",""
   "SITSW-4236","am62xx-sk, am62xx-sk-lp, am62p-sk","Seva Store doesn't launch post EdgeAI studio Launch","After closing EdgeAI studio, reboot the board once before launching Seva Store"
   "SITSW-3922","am64xx-evm, am64xx-sk, am62xx-sk, am62xx-sk-lp, am62x-sip-sk, am62p-sk","Flash writer: Benchmark script fails for emmc logs",""
   "SITSW-3959","am62p-sk","AM62P: Display Cluster Image: Weston tries to launch and fails",""

|

Issues opened in previous releases that were closed on this release
-------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-37965","BCDMA: RX Channel can lockup in certain scenarios","am62axx_sk-fs, am62axx_sk-se, am62pxx_sk-fs, am62pxx_sk-se, am62xx_lp_sk-fs, am62xx_lp_sk-se, am62xx_p0_sk-fs, am62xx_sk-fs, am62xx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se "
   "LCPD-37853","Doc: CPSW3g doc missing from 62p","am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-37795","RAM size not updated, when ECC is enabled","am62axx_sk-fs,am62pxx_sk-fs,am64xx_sk-fs"
   "LCPD-37443","McASP - Improve audio loopback latency","am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs"
   "LCPD-37389","Building Kernel from sources doesn't cover list of dependencies","am64xx-evm,am64xx-hssk,am62xx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs,am64xx_sk-fs,am64xx_sk-se"
   "LCPD-37388","Building U-Boot from sources doesn't cover list of dependencies","am64xx-hssk,am62xx_sk-fs,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am64xx_sk-fs,am64xx_evm-se"
   "LCPD-36615","Linux SDK Docs for most K3 devices contain an outdated device list in the Kernel/SPI Section","am62axx_sk-fs, am62axx_sk-se, am62pxx_sk-fs, am62pxx_sk-se, am62xx_lp_sk-fs, am62xx_lp_sk-se, am62xx_p0_sk-fs, am62xx_sk-fs, am62xx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se, am64xx-hsevm, am64xx-hssk, am64xx_evm-se, am64xx_sk-fs, am64xx_sk-se"
   "LCPD-37723","am62p: missing wakeup sources lpm overlay","am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-37673","AM62P: Boot failures on Display Cluster Image","am62pxx_sk-fs"
   "LCPD-37625","Linux CPSW Proxy Client: Fix complier warnings","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62pxx_sk-fs,j721e-hsevm,j721e-idk-gw,j7200-evm,j7200-hsevm,j784s4-evm,j784s4-hsevm"
   "LCPD-37562","am62p, am62a boards fail to power on from automation interface after running PM tests  ","am62axx_sk-fs,am62axx_sk-se,am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-37524","ti-rpmsg-char: remove references to ti.ipc4.ping-pong ","am654x-evm,am654x-idk,am64xx-evm,am62xx_sk-fs,am62axx_sk-fs,am62pxx_sk-fs"
   "LCPD-37519","SDK: Enable GPIO1 bank GPIOs for RPI header","am62axx_sk-fs,am62axx_sk-se,am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-37492","U-Boot Failures for AM62P Display Cluster Image","am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-37476","Fatal kernel crash after camera pipeline long run","am62pxx_sk-fs"
   "LCPD-37465","DeepSleep regression because of GPU","am62xx_sk-fs,am62pxx_sk-fs"
   "LCPD-37341","Wave5 Encoder Memory Leak","am62axx_sk-fs,am62pxx_sk-fs,am68_sk-fs,am69_sk-fs,j721s2-evm,j784s4-evm"
   "LCPD-37327","eMMC: Doc and testcase update needed to enable RST_FUNCTION for warm reboot","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se"
   "LCPD-37270","Debian: LPM not working on AM62P","am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-37224","McASP - Audio receive buffer overflow/Transmit buffer underflow","am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs"
   "LCPD-37207","Docker is disabled in RT Linux","am64xx-hssk,am62xx_lp_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"
   "LCPD-37194","AM62P: DSI Color shift","am62pxx_sk-fs,am62pxx_sk-se,am62pxx-zebu"
   "LCPD-37161","Boot: Add Crypto performance tests to 9.1 testsplan","am62pxx_sk-fs"
   "LCPD-37158","Boot: Add MMCSD performance tests to 9.1 testsplan","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"
   "LCPD-37157","Add ARM performance benchmarks to 9.1 testplans","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"
   "LCPD-37151","am62: am64: i2c set/get tests are failing","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62xx-sk"
   "LCPD-37150","am62: i2c bus speed test is failing","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62xx-sk"
   "SYSFW-6763","TISCI_MSG_SET_DEVICE_RESETS message returns success for invalid device reset range","am62x,am62ax,am62px"
   "SYSFW-7056","Implement New PLL sequence Proposed by HW team","am62x,am62ax,am62px,am64x"
   "SYSFW-6941","TISCI_MSG_SYS_RESET fails for negative testcase","am62x,am62ax,am62px"
   "SYSFW-6892","TISCI Clock api returns success for invalid Clock ID","am62x,am62ax,am62px,am64x,am65x"
   "SYSFW-5266","LPM: USB must not remove reset isolation until LPSC has been reenabled","am62x,am62ax,am62px"
   "SYSFW-6805","TISCI_MSG_QUERY_FW_CAPS is giving NACK when send over secure queue","am62x,am62ax,am62px"
   "SYSFW-6879","clock_stop API in baremetal disables all configurable interrupts","am62x,am62ax,am62px"
   "SITSW-3600","FwdStatus is set as SCISERVER_FORWARD_MSG for secure messages from DM R5 core","am62x,am62ax,am62px"
   "SITSW-3610","clock mux changes are lost after deepsleep entry/exit","am62x,am62ax,am62px"

|

Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-37097","SDK: U-boot: Sync MMC otap/itap between kernel and u-boot","am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-37096","SDK: Linux: Add ITAP/OTAP for SDR104 speed mode","am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-37095","SDK: Linux: Add DD52 speed mode for MMC0","am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-37094","SDK: Linux: Enable HS400 speed mode for MMC0","am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-37081","SNPS: USB2 PHY locks up due to short suspend","am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"
   "LCPD-37049","microtips panel: touch doesn't work on AM62P with 09.01.00.005 Kernel","am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-37029","AM62: Suspend / Resume Test Failure: 29000000.mailbox failed to suspend","am62xx_sk-fs,am62xx_sk-se,am62axx_sk-fs,am62pxx_sk-fs"
   "LCPD-36992","U-Boot: k3-ddrss.c: Missing 'const' on k3_ddrss_ops","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se,am62pxx-zebu,am62lxx-vlab,am62lxx-zebu,am62xx_p0_sk-fs,am64xx_sk-fs,am64xx_evm-se,am64xx_sk-se,am68_sk-fs,am69_sk-fs,beaglebone,bbai,bbai64-gp,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j721s2_evm-se,j7200-evm,j7200-hsevm,j784s4-evm,j784s4-hsevm,j722s_evm-fs,J784S4_BASESIM"
   "LCPD-36989","AM62P: eMMC HS400 fails","am62pxx_sk-fs"
   "LCPD-36984","AM62: USB driver does not configure USB0_PHY_CTRL_CORE _VOLTAGE","am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se"
   "LCPD-36944","AM62P: OSPI tests fails ","am62pxx_sk-fs"
   "LCPD-36943","AM62P: eMMC boot fails","am62pxx_sk-fs"
   "LCPD-36942","AM62P: CPUFreq unit test fail","am62pxx_sk-fs"
   "LCPD-36891","AM62: Suspend / Resume Test Failure","am62xx_lp_sk-se,am62pxx_sk-fs"
   "LCPD-36847","doc: ltp-ddt documentation is not upto date","am64xx-hsevm,am62xx_sk-fs,am62axx_sk-fs,am62pxx_sk-fs,am68_sk-fs,am69_sk-fs,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-36801","USB-DFU boot test fail incorrect configuration","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-36588","eMMC boot fails after flashing via USB DFU","am62pxx_sk-fs"
   "LCPD-35096","OPTEE xtest failures","am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am68_sk-fs"
   "LCPD-35065","DMA buf import buffer activation error","am62axx_sk-fs,am62axx_sk-se,am62pxx_sk-fs,am62pxx_sk-se,j721s2-evm,j721s2-hsevm,j784s4-evm,j784s4-hsevm"
   "LCPD-29445","AM62ax: MCAN CAN_S_FUNC_MODULAR test is failing","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se"

|

