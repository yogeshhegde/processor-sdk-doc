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

To simplify the end user experience, Processor SDK Linux AM62A installer provides everything needed as discussed below
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


Release 09.02.00
================

Released on March 2024

What's new
----------

**Processor SDK Linux AM62A Release has following new features:**

  - Mini Fusion board support
  - LI OX05B1S Sensor support
  - Kernel: MMC Highspeed tuning and Performance Improvements
  - RT Kernel : Significant Improvements to Real-Time Linux Interrupt Latency, :ref:`RT Interrupt Latencies <RT-linux-performance>`
  - DDR: Stable Config Update, Single and multi-bit DDR ECC Support
  - Bug Fixes and Stability Improvements
  - DM Firmware: PLL Configuration sequence updated to latest recommendation

**Component version:**

  - Kernel 6.1.80
  - RT Kernel 6.1.80-rt26
  - U-Boot 2023.04
  - Toolchain GCC 11.4
  - ATF 2.10
  - OPTEE 4.1
  - TIFS Firmware v09.02.07
  - DM Firmware 09.02.00.24

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
==============

Errata Workarounds Available in this Release
--------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 30, 150

   "LCPD-37081","SNPS: USB2 PHY locks up due to short suspend","am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"
   "LCPD-27886","USART: Erroneous clear/trigger of timeout interrupt","am64xx-evm,am62axx_sk-fs,am62xxsip_sk-fs,am62xxsip_sk-se,am62xx-sk,j721e-idk-gw,j7200-evm,j784s4-evm,j784s4-hsevm"

|

Known Issues
------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 15, 70, 10, 25

   "LCPD-37795","am62axx_sk-fs,am62pxx_sk-fs,am64xx_sk-fs","RAM size not updated, when ECC is enabled","https://git.ti.com/cgit/ti-u-boot/ti-u-boot/commit/?&id=26c81a4d5b31"
   "LCPD-37789","am62axx_sk-fs","Automate_Test: E0510 jpeg encoder should support system PM, runtime PM and active use-case suspend/resume",""
   "LCPD-37750","am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se","SDK Documentation: Formatting: Spacing between Lines seems broken",""
   "LCPD-37743","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62axx_sk-fs,am62axx_sk-se","AM64x: K3conf SoC rev kernel crash test fails",""
   "LCPD-37732","am62axx_sk-fs","Linux SDK 09.02: CPSW EST Switch mode does not work",""
   "LCPD-37714","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se","CAN suspend and loopback tests are failing",""
   "LCPD-37543","am62axx_sk-fs","AM62A Yocto SDK UG: OSPI U-Boot Section Incomplete (PHY Calibration, Programming, etc.)",""
   "LCPD-37443","am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs","McASP - Improve audio loopback latency",""
   "LCPD-37377","am62xx_lp_sk-fs,am62axx_sk-fs,am62axx_sk-se","Doc: U-Boot: No documentation for OSPI NAND",""
   "LCPD-37373","am62axx_sk-fs","wave5 VPU page-faults on poison memory address during long test",""
   "LCPD-37342","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62pxx_sk-fs","cpufreq: schedutil: constant switch between CPU OPPs",""
   "LCPD-37226","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se,am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm","Update Ubuntu Host version in Linux documentation",""
   "LCPD-37210","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se","MMC driver runtime_pm support",""
   "LCPD-37209","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se","USB driver runtime_pm support",""
   "LCPD-37208","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se","CPSW driver runtime_pm support",""
   "LCPD-37187","am62axx_sk-fs,am62axx_sk-se","Enable remaining GPIO SOC pins on am62a for RPi Header Expansion",""
   "LCPD-37141","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62pxx_sk-fs","AM62x: Sync up USB R5 defconfigs with main R5 defconfig",""
   "LCPD-36993","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se,am62pxx-zebu,am62lxx-vlab,am62lxx-zebu,am62xx_p0_sk-fs,am64xx_sk-fs,am64xx_evm-se,am64xx_sk-se,am68_sk-fs,am69_sk-fs,beaglebone,bbai,bbai64-gp,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j721s2_evm-se,j7200-evm,j7200-hsevm,j784s4-evm,j784s4-hsevm,j722s_evm-fs,J784S4_BASESIM","U-Boot: lpddr4.c: Error handling missing failure cases",""
   "LCPD-36950","am62xx_sk-fs,am62axx_sk-fs,am62pxx_sk-fs","crypto openssl performance test fail",""
   "LCPD-36630","am62axx_sk-fs","AM62A dts files missing RTI nodes",""
   "LCPD-36575","am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se","AM62Q: AM62A: OSPI:  tuning fails at certain PVTs",""
   "LCPD-35360","am62axx_sk-se","TIDEC_S_FUNC_GST_DECODE_AHP_MULTICHANNEL_FILE_AUD_MW_E test failure",""
   "LCPD-34991","am62axx_sk-fs","systemd failure with vmalloc overflow error when using fitimage",""
   "LCPD-34912","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62axx_sk-hs4,am62axx_sk-hs5,am62xx-lp-sk,am62xx-sk,am62xx_sk-hs4,am62xx_sk-hs5","AM62/AM62Ax: DM does not set correct pixel clock",""
   "LCPD-34835","am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs","am62/am62a: Add CTRL MMR support for DPI signals on negative edge",""
   "LCPD-34360","am62axx_sk-fs","Display distorted above certain resolution",""
   "LCPD-34105","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62axx_sk-hs4,am62axx_sk-hs5,am62xx-lp-sk,am62xx-sk,am62xx_sk-hs4,am62xx_sk-hs5","convert uboot's MDIO driver over to use the driver model",""
   "LCPD-24456","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am62xx-sk,am64xx_sk-fs,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j721e-hsevm,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j7200-evm,j7200-hsevm,omapl138-lcdk","Move IPC validation source from github to git.ti.com",""
   "SYSFW-5992","am62x,am62ax,am62px","Unable to set exact pixel clock for OLDI LCD display / HDMI Pixel clock",""
   "SYSFW-6432","am62x,am62ax,am62px,am64x,am65x","Set device API doesn't return Error when PD is in transition state",""
   "SYSFW-6426","am62x,am62ax,am62px,am64x,am65x","Ownership of a firewall region can be transferred to an invalid host",""
   "SYSFW-6369","am62x,am62ax,am62px","DM unable to enter deep sleep mode when booting in SBL flow",""
   "SITSW-4366","am62ax","C7x edge AI firmware is not supporting graceful shutdown",""

|

Issues opened in previous releases that were closed on this release
-------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-37670","AM62Ax Linux SDK v9.1 Documentation: Broken/Missung USB-DFU Instructions","am62axx_sk-fs"
   "LCPD-37669","AM62Ax Linux SDK v9.1 Documentation: Broken U-Boot Build Instructions","am62axx_sk-fs"
   "LCPD-37625","Linux CPSW Proxy Client: Fix complier warnings","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62pxx_sk-fs,j721e-hsevm,j721e-idk-gw,j7200-evm,j7200-hsevm,j784s4-evm,j784s4-hsevm"
   "LCPD-37562","am62p, am62a boards fail to power on from automation interface after running PM tests  ","am62axx_sk-fs,am62axx_sk-se,am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-37524","ti-rpmsg-char: remove references to ti.ipc4.ping-pong ","am654x-evm,am654x-idk,am64xx-evm,am62xx_sk-fs,am62axx_sk-fs,am62pxx_sk-fs"
   "LCPD-37519","SDK: Enable GPIO1 bank GPIOs for RPI header","am62axx_sk-fs,am62axx_sk-se,am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-37341","Wave5 Encoder Memory Leak","am62axx_sk-fs,am62pxx_sk-fs,am68_sk-fs,am69_sk-fs,j721s2-evm,j784s4-evm"
   "LCPD-37327","eMMC: Doc and testcase update needed to enable RST_FUNCTION for warm reboot","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se"
   "LCPD-37305","MCU_MCAN1 Wakeup for Partial IO PINCTRL Conflict","am62xx_lp_sk-fs,am62axx_sk-fs"
   "LCPD-37228","CSI: Fix handling of short-frames","am62axx_sk-fs"
   "LCPD-37224","McASP - Audio receive buffer overflow/Transmit buffer underflow","am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs"
   "LCPD-37162","Boot: Add CPSW2 Ingress/Egress performance tests to 9.1 testsplan","am62axx_sk-fs"
   "LCPD-37160","Add SoC Audio performance benchmarks to 9.1 testplans","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs"
   "LCPD-37158","Boot: Add MMCSD performance tests to 9.1 testsplan","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"
   "LCPD-37157","Add ARM performance benchmarks to 9.1 testplans","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"
   "LCPD-37151","am62: am64: i2c set/get tests are failing","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62xx-sk"
   "LCPD-37150","am62: i2c bus speed test is failing","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62xx-sk"
   "LCPD-37149","Enabling RTC on am62ax is breaking TIDL","am62axx_sk-fs,am62axx_sk-se"
   "LCPD-37142","AM62A: Suspend-resume: 29010000.mailbox: fifo 1 has unexpected unread messages","am62axx_sk-fs,am62axx_sk-se"
   "SYSFW-6763","TISCI_MSG_SET_DEVICE_RESETS message returns success for invalid device reset range","am62x,am62ax,am62px"
   "SYSFW-7056","Implement New PLL sequence Proposed by HW team","am62x,am62ax,am62px,am64x"
   "SYSFW-6941","TISCI_MSG_SYS_RESET fails for negative testcase","am62x,am62ax,am62px"
   "SYSFW-6892","TISCI Clock api returns success for invalid Clock ID","am62x,am62ax,am62px,am64x,am65x"
   "SYSFW-5266","LPM: USB must not remove reset isolation until LPSC has been reenabled","am62x,am62ax,am62px"
   "SYSFW-6805","TISCI_MSG_QUERY_FW_CAPS is giving NACK when send over secure queue","am62x,am62ax,am62px"
   "SYSFW-6879","clock_stop API in baremetal disables all configurable interrupts","am62x,am62ax,am62px"
   "SYSFW-6811","HSM core not allowed to access SA2UL context memory","am62x,am62ax"
   "SITSW-3600","FwdStatus is set as SCISERVER_FORWARD_MSG for secure messages from DM R5 core","am62x,am62ax,am62px"
   "SITSW-3610","clock mux changes are lost after deepsleep entry/exit","am62x,am62ax,am62px"

|

Issues found and closed on this release that may be applicable to prior releases
--------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-37091","Upstream boot breakage: Am62x, AM62Ax","am62xx_sk-fs,am62axx_sk-fs"
   "LCPD-37081","SNPS: USB2 PHY locks up due to short suspend","am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"
   "LCPD-37029","AM62: Suspend / Resume Test Failure: 29000000.mailbox failed to suspend","am62xx_sk-fs,am62xx_sk-se,am62axx_sk-fs,am62pxx_sk-fs"
   "LCPD-36992","U-Boot: k3-ddrss.c: Missing 'const' on k3_ddrss_ops","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se,am62pxx-zebu,am62lxx-vlab,am62lxx-zebu,am62xx_p0_sk-fs,am64xx_sk-fs,am64xx_evm-se,am64xx_sk-se,am68_sk-fs,am69_sk-fs,beaglebone,bbai,bbai64-gp,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j721s2_evm-se,j7200-evm,j7200-hsevm,j784s4-evm,j784s4-hsevm,j722s_evm-fs,J784S4_BASESIM"
   "LCPD-36984","AM62: USB driver does not configure USB0_PHY_CTRL_CORE _VOLTAGE","am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se"
   "LCPD-36976","AM62a: OP-TEE with HW TRNG causes instabilities after Deep Sleep cycle","am62axx_sk-fs"
   "LCPD-36847","doc: ltp-ddt documentation is not upto date","am64xx-hsevm,am62xx_sk-fs,am62axx_sk-fs,am62pxx_sk-fs,am68_sk-fs,am69_sk-fs,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-36801","USB-DFU boot test fail incorrect configuration","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-36653","modprobe -r dwc3-am62 fails","am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se"
   "LCPD-35096","OPTEE xtest failures","am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am68_sk-fs"
   "LCPD-35065","DMA buf import buffer activation error","am62axx_sk-fs,am62axx_sk-se,am62pxx_sk-fs,am62pxx_sk-se,j721s2-evm,j721s2-hsevm,j784s4-evm,j784s4-hsevm"
   "LCPD-34780","DT property ti,driver-strength-ohm is only applicable to AM64x MMC0","am64xx-evm,am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-lp-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-34122","AM62A: OSPI documentation not present","am62axx_sk-fs"
   "LCPD-34119","AM62A performance page gives 3DES performance numbers when IP does not exist","am62axx_sk-fs"
   "LCPD-32819","AM62A: USB Client: Tests: Host not detecting DUT in device mode ","am62axx_sk-fs,am62axx_sk-se"
   "LCPD-32356","AM62x: tcrypt doesn't use sa2ul for SHA256/512 or any other alg","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-lp-sk,am62xx-sk"
   "LCPD-29445","AM62ax: MCAN CAN_S_FUNC_MODULAR test is failing","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se"

|
