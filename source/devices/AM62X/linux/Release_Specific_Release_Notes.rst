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

Release 09.02.01.10
===================

Released on May 2024

What's new
----------

**Processor SDK Linux AM62X Release has following new features:**

  - LTS Refresh with Stable Kernel update from 6.1.80 to 6.1.83
  - Important Bug Fixes on top of Processor SDK 09.02.01.09 Release
  - Kernel: MMC Highspeed tuning and Performance Improvements
  - RT Kernel : Significant Improvements to Real-Time Linux Interrupt Latency, :ref:`RT Interrupt Latencies <RT-linux-performance>`
  - DDR: Stable Config Update, Single and multi-bit DDR ECC Support
  - Power Management: DeepSleep, MCU-Only and Partial IO mode :ref:`Power Management Overview <Power-Management>`
  - OOB: GPU Accelerated Chromium Browser Support :ref:`Chromium Browser <Chromium_Browser-label>`
  - DM Firmware: PLL Configuration sequence updated to latest recommendation


**Component version:**

  - Kernel 6.1.83
  - RT Kernel 6.1.83-rt28
  - U-Boot 2023.04
  - Toolchain GCC 11.4
  - ATF 2.10
  - OPTEE 4.1
  - Graphics DDK 23.3
  - TIFS Firmware v09.02.08
  - DM Firmware 09.02.01.01

Build Information
=================

.. _u-boot-release-notes:

U-Boot
------

.. rubric:: u-boot
   :name: u-boot

| Head Commit: 83660642085462346fbeb410f83bc99448ec7042 arm: dts: k3-am62p-main: Add mac-address efuse
| Date: 2024-05-16 08:21:02 -0500
| uBoot Version: 2023.04
| uBoot Description: RC Release 09.02.00.010
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2023.04
| uBoot Tag: 09.02.00.010
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
| Head Commit: 3987d170fc522565c5e4a9293aba1db75951b8c0 ti-ipc: Update IPC firmwares for am62x, am62ax and am62px
| Date: 2024-05-13 15:02:06 -0500
| Clone: https://git.ti.com/cgit/processor-firmware/ti-linux-firmware
| Branch: ti-linux-firmware
| Tag: 09.02.00.010
|

Kernel
------

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
-----
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

.. rubric:: meta-tisdk
   :name: meta-tisdk

| Head Commit: 03f2d14c2e4fefacb17aeab1540cbec694c3f217 recipes-kernel/recipes-bsp: Bump up SRCREV for jailhouse
| Date: 2024-05-17 01:52:07 -0500

| Clone: git://git.ti.com/ti-sdk-linux/meta-tisdk.git
| Branch: kirkstone
| Release Tag: 09.02.01.10
|

.. rubric:: meta-edgeai
   :name: meta-edgeai

| Head Commit: fdb683aa69d4d70aca17c2d53be3f900ae9d5e72 Revert "conf: layer: Add device tree appends for packaging v3link dtbos"
| Date: 2024-04-08 03:12:04 -0500

| Clone: https://git.ti.com/git/edgeai/meta-edgeai.git
| Branch: kirkstone
|

.. note::

    meta-edgeai layer is not applicable in case of AM62SIP (i.e. am62xxsip-evm)

Issues Tracker
==============

Errata Workarounds Available in this Release
--------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 30, 150

   "LCPD-37081","SNPS: USB2 PHY locks up due to short suspend","am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"
   "LCPD-27887","i2327: RTC: Hardware wakeup event limitation","am62xx_sk-fs,am62xxsip_sk-fs,am62xxsip_sk-se,am62xx-sk"

|


Known Issues
------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35

   "LCPD-37750","am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se","SDK Documentation: Formatting: Spacing between Lines seems broken",""
   "LCPD-37724","am64xx-hsevm,am62xx_lp_sk-fs","CICD: ETH_CPSW2g_TAS_1A : TSN: TAS test failed, queue 0 did not increase",""
   "LCPD-37714","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se","CAN suspend and loopback tests are failing",""
   "LCPD-37653","am62xx_sk-fs,am62xx_sk-se","AM62B/-P1 SK: i2c1/audio goes haywire when 2nd IO expander is added",""
   "LCPD-37554","am62xx_sk-fs","Update the AM625 DTS for AM62B-P1 board",""
   "LCPD-37453","am62xx_sk-fs","Outstanding mailbox messages prevent suspend",""
   "LCPD-37443","am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs","McASP - Improve audio loopback latency",""
   "LCPD-37418","am62xxsip_sk-se","Intermittent board hang during UART boot after successfully loading tispl.bin",""
   "LCPD-37417","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am68_sk-fs,am69_sk-fs,j721e-idk-gw,j721s2-evm,j784s4-evm,j722s_evm-fs","RGX_S_FUNC_APM test is failing",""
   "LCPD-37389","am64xx-evm,am64xx-hssk,am62xx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs,am64xx_sk-fs,am64xx_sk-se","Building Kernel from sources doesn't cover list of dependencies",""
   "LCPD-37388","am64xx-hssk,am62xx_sk-fs,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am64xx_sk-fs,am64xx_evm-se","Building U-Boot from sources doesn't cover list of dependencies",""
   "LCPD-37377","am62xx_lp_sk-fs,am62axx_sk-fs,am62axx_sk-se","Doc: U-Boot: No documentation for OSPI NAND",""
   "LCPD-37358","am62xx_lp_sk-fs","Eth: TCP bidir tests failing in CI ",""
   "LCPD-37355","am62xx_sk-fs","Watchdog timer cannot be pet",""
   "LCPD-37342","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62pxx_sk-fs","cpufreq: schedutil: constant switch between CPU OPPs",""
   "LCPD-37321","am62xx_lp_sk-fs","suspend-to-RAM wakeup by plugging in USB device is not reliable",""
   "LCPD-37226","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se,am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm","Update Ubuntu Host version in Linux documentation",""
   "LCPD-37210","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se","MMC driver runtime_pm support",""
   "LCPD-37209","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se","USB driver runtime_pm support",""
   "LCPD-37208","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se","CPSW driver runtime_pm support",""
   "LCPD-37141","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62pxx_sk-fs","AM62x: Sync up USB R5 defconfigs with main R5 defconfig",""
   "LCPD-37126","am62xx_sk-fs","AM62x HS-FS resume failing",""
   "LCPD-37064","am62xx_sk-fs","Linux kernel crash observed while booting from EMMC",""
   "LCPD-37053","am62xx_sk-fs,am62xx_sk-se","AM62x: Deep Sleep: tidss Timeout waiting for framedone on crtc 1",""
   "LCPD-36993","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se,am62pxx-zebu,am62lxx-vlab,am62lxx-zebu,am62xx_p0_sk-fs,am64xx_sk-fs,am64xx_evm-se,am64xx_sk-se,am68_sk-fs,am69_sk-fs,beaglebone,bbai,bbai64-gp,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j721s2_evm-se,j7200-evm,j7200-hsevm,j784s4-evm,j784s4-hsevm,j722s_evm-fs,J784S4_BASESIM","U-Boot: lpddr4.c: Error handling missing failure cases",""
   "LCPD-36978","am62xxsip_sk-fs,am62xxsip_sk-se","AM62xSiP: DeepSleep: Suspend-Resume not working",""
   "LCPD-36950","am62xx_sk-fs,am62axx_sk-fs,am62pxx_sk-fs","crypto openssl performance test fail",""
   "LCPD-36925","am62xx_lp_sk-fs,am62xx_lp_sk-se","am62xx-lp-sk: power down from automation interface behaves differently between U-Boot and kernel",""
   "LCPD-36918","am62xx_sk-fs,am62xx_lp_sk-fs,am62xxsip_sk-fs","meta-arago: Matrix GUI  change caused : runLmDDRBandwidth.sh failure",""
   "LCPD-36846","am62xx_sk-fs","u-boot usb reset command fails",""
   "LCPD-36820","am62xxsip_sk-fs","USB DFU: OSPI boot failure",""
   "LCPD-36812","am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se","RTC: tests fail",""
   "LCPD-36805","am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se","ETHERNET boot test fail incorrect configuration",""
   "LCPD-36804","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am64xx_sk-fs,am64xx_evm-se,am64xx_sk-se","IPC performance test fail - modprobe fails",""
   "LCPD-36803","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se","USBDEV:  test case fail - USB devices not enumerated",""
   "LCPD-36618","am62xxsip_sk-fs,am62xxsip_sk-se","AM62SIP:  reserving fdt memory region failed error seen at bootup",""
   "LCPD-36575","am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se","AM62Q: AM62A: OSPI:  tuning fails at certain PVTs",""
   "LCPD-36524","am62xx_sk-fs","AM62x: sa2ul doesn't work after deepsleep",""
   "LCPD-36462","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs","ti-u-boot:AM62x SK: Update ITAP/OTAP values in device tree ",""
   "LCPD-36457","am62xx_sk-fs","am62xx-sk: DHCP, tftp occasionally fail when bothe network interfaces are connected",""
   "LCPD-36436","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs","ti-linux:AM62x SK: Update ITAP/OTAP values in device tree ",""
   "LCPD-36423","am62xxsip_sk-se","am62sip: uboot: fdt memory region failed ",""
   "LCPD-36414","am64xx-evm,am62xx_sk-fs","Performance numbers for NOR, eMMC missing in doc",""
   "LCPD-36361","am64xx-hsevm,am62xxsip_sk-se","Boot failure over UART",""
   "LCPD-36320","am62xx_sk-fs,am62xx_sk-se,am62xx-sk","AM62x: DM FW sets wrong CPU core frequency",""
   "LCPD-36282","am62xx-sk","OV5640 capture not working at two highest resolutions",""
   "LCPD-35042","am62xx_sk-fs,am62xx_sk-se,am62xx-sk,am62xx_sk-hs4,am62xx_sk-hs5","Linux: AM62x: OSPI NOR Flash read speed is low (~2.5MBPS)",""
   "LCPD-34951","am62xx_sk-fs","AM62: Board not booting up with new auto-gen data",""
   "LCPD-34916","am62xx_sk-fs,am62xx-sk","AM62x: op-tee with LOG_LEVEL=2 crashes after Deep Sleep",""
   "LCPD-34912","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62axx_sk-hs4,am62axx_sk-hs5,am62xx-lp-sk,am62xx-sk,am62xx_sk-hs4,am62xx_sk-hs5","AM62/AM62Ax: DM does not set correct pixel clock",""
   "LCPD-34906","am62xx-sk","R5 SPL OSPI NOR with PHY calibration not working",""
   "LCPD-34901","am62xx_sk-fs,am62xx-sk","AM62: Reset button fails to reset AM625-SK-EVM after wakeup from deep sleep",""
   "LCPD-34835","am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs","am62/am62a: Add CTRL MMR support for DPI signals on negative edge",""
   "LCPD-34816","am62xx_sk-fs,am62xx-sk","rtcwake fails after resuming from Deep Sleep",""
   "LCPD-34343","am62xx-sk","SDK: Am62x: Openssl commands for openssl_perf.sh gives wrong results",""
   "LCPD-34105","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62axx_sk-hs4,am62axx_sk-hs5,am62xx-lp-sk,am62xx-sk,am62xx_sk-hs4,am62xx_sk-hs5","convert uboot's MDIO driver over to use the driver model",""
   "LCPD-32706","am62xx_sk-fs,am62xx-sk","Display: DRM tests fail inconsistently",""
   "LCPD-32351","am62xx_sk-fs,am62xx_sk-se,am62xx-sk","MMCSD: HS200 and SDR104 Command Timeout Window Too Small","If the command requires a timeout longer than 700ms, then the MMC host controller command timeout can be disabled (MMCSD_CON[6] MIT=0x1) and a software implementation may be used in its place."
   "LCPD-29332","am62xx_sk-fs,am62xx_sk-se,am62xx-sk","LPM Demo not Working on Linux RT",""
   "LCPD-28742","am62xx_sk-fs,am62xx_sk-se,am62xx-sk","AM62x: Make ""Debugging SPL"" doc specific to AM62x",""
   "LCPD-28491","am62xx_sk-fs,am62xx_sk-se,am62xx-sk","WiLink not functional with fw_devlink option set to `on` ",""
   "LCPD-28448","am62xx_sk-fs,am62xx_sk-se,am62xx-sk","Wall time does not account for sleep time",""
   "LCPD-28104","am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62xx-sk","Automated test failure - CPSW test is passing invalid parameters to switch-config",""
   "LCPD-24456","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am62xx-sk,am64xx_sk-fs,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j721e-hsevm,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j7200-evm,j7200-hsevm,omapl138-lcdk","Move IPC validation source from github to git.ti.com",""
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
   "SITSW-3811","am62xx-sk-lp","Jailhouse: Missing config file for ivshmem-demo",""

|

Issues opened in previous releases that were closed on this release
-------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-37625","Linux CPSW Proxy Client: Fix complier warnings","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62pxx_sk-fs,j721e-hsevm,j721e-idk-gw,j7200-evm,j7200-hsevm,j784s4-evm,j784s4-hsevm"
   "LCPD-37613","Documentation: Mention correct file name for LP board","am62xx_lp_sk-fs"
   "LCPD-37591","am62x-lp-fs : Power Suspend/Resume test failure  on automation platform over NFS","am62xx_lp_sk-fs"
   "LCPD-37563","link ""https://docs.imgtec.com/tools-manuals/pvrtune-manual/topics/introduction.html"" is broken","am62xx_sk-fs,am62xx_sk-se"
   "LCPD-37524","ti-rpmsg-char: remove references to ti.ipc4.ping-pong ","am654x-evm,am654x-idk,am64xx-evm,am62xx_sk-fs,am62axx_sk-fs,am62pxx_sk-fs"
   "LCPD-37478","AM62x: beagleplay: am65_cpsw_nuss_suspend issues in suspend resume","am62xx_sk-fs,am62xx_sk-se,beagleplay-gp"
   "LCPD-37465","DeepSleep regression because of GPU","am62xx_sk-fs,am62pxx_sk-fs"
   "LCPD-37459","Deep Sleep Error When Only One A53 Core is Active","am62xx_sk-fs"
   "LCPD-37438","Docs: Update CAN interface names","am654x-evm,am62xx_sk-fs,am335x-evm,dra7xx-evm,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-37402","LPM: GPIO interrupt stops generating events after resume from deepsleep","am62xx_sk-fs"
   "LCPD-37340","Qt DMA bug with CSI cameras","am62xx_sk-fs,j721e-idk-gw,j721s2-evm,j784s4-evm"
   "LCPD-37327","eMMC: Doc and testcase update needed to enable RST_FUNCTION for warm reboot","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se"
   "LCPD-37309","Search is broken, never completes in 9.1 Linux SDKs","am64xx-evm,am64xx-hsevm,am62xx_sk-fs,am64xx_sk-fs"
   "LCPD-37305","MCU_MCAN1 Wakeup for Partial IO PINCTRL Conflict","am62xx_lp_sk-fs,am62axx_sk-fs"
   "LCPD-37275","crc32 at address 0x8'8100'0000 is too slow","am62xx_sk-fs"
   "LCPD-37224","McASP - Audio receive buffer overflow/Transmit buffer underflow","am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs"
   "LCPD-37207","Docker is disabled in RT Linux","am64xx-hssk,am62xx_lp_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"
   "LCPD-37160","Add SoC Audio performance benchmarks to 9.1 testplans","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs"
   "LCPD-37158","Boot: Add MMCSD performance tests to 9.1 testsplan","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"
   "LCPD-37157","Add ARM performance benchmarks to 9.1 testplans","am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"
   "LCPD-37151","am62: am64: i2c set/get tests are failing","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62xx-sk"
   "LCPD-37150","am62: i2c bus speed test is failing","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62xx-sk"
   "SYSFW-6763","TISCI_MSG_SET_DEVICE_RESETS message returns success for invalid device reset range","am62x,am62ax,am62px"
   "SYSFW-7056","Implement New PLL sequence Proposed by HW team","am62x,am62ax,am62px,am64x"
   "SYSFW-6941","TISCI_MSG_SYS_RESET fails for negative testcase","am62x,am62ax,am62px"
   "SYSFW-6892","TISCI Clock api returns success for invalid Clock ID","am62x,am62ax,am62px,am64x,am65x"
   "SYSFW-5266","LPM: USB must not remove reset isolation until LPSC has been reenabled","am62x,am62ax,am62px"
   "SYSFW-6356","clock: DSS: clock needs to be set twice to take effect","am62x"
   "SYSFW-6805","TISCI_MSG_QUERY_FW_CAPS is giving NACK when send over secure queue","am62x,am62ax,am62px"
   "SYSFW-6879","clock_stop API in baremetal disables all configurable interrupts","am62x,am62ax,am62px"
   "SYSFW-6811","HSM core not allowed to access SA2UL context memory","am62x,am62ax,am62px"
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
   "LCPD-37057","AM62x: Power management suspend/resume fail","am62xx_sk-fs"
   "LCPD-37029","AM62: Suspend / Resume Test Failure: 29000000.mailbox failed to suspend","am62xx_sk-fs,am62xx_sk-se,am62axx_sk-fs,am62pxx_sk-fs"
   "LCPD-36996","Upstream: am62xx-sk-fs: kernel oops with 6.6.0-next-20231109 drm_do_probe_ddc_edid","am62xx_sk-fs"
   "LCPD-36992","U-Boot: k3-ddrss.c: Missing 'const' on k3_ddrss_ops","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se,am62pxx-zebu,am62lxx-vlab,am62lxx-zebu,am62xx_p0_sk-fs,am64xx_sk-fs,am64xx_evm-se,am64xx_sk-se,am68_sk-fs,am69_sk-fs,beaglebone,bbai,bbai64-gp,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j721s2_evm-se,j7200-evm,j7200-hsevm,j784s4-evm,j784s4-hsevm,j722s_evm-fs,J784S4_BASESIM"
   "LCPD-36984","AM62: USB driver does not configure USB0_PHY_CTRL_CORE _VOLTAGE","am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se"
   "LCPD-36891","AM62: Suspend / Resume Test Failure","am62xx_lp_sk-se,am62pxx_sk-fs"
   "LCPD-36879","AM62: CPU hotplug broken due to WDT enablement","am62xx_sk-fs"
   "LCPD-36875","AM6x CI/CD Snapshot points to incorrect/old toolchain","am62xx_sk-fs"
   "LCPD-36848","Occasional SPI-NOR write timeout under high load","am62xx_sk-fs,j721e-idk-gw"
   "LCPD-36847","doc: ltp-ddt documentation is not upto date","am64xx-hsevm,am62xx_sk-fs,am62axx_sk-fs,am62pxx_sk-fs,am68_sk-fs,am69_sk-fs,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-36844","Linux kernel crashes when DDR Inline ECC is enabled","am62xx_sk-fs"
   "LCPD-36811","MM: Weston should assign 0 zpos to primary plane","am62xx_sk-fs,am68_sk-fs,am69_sk-fs"
   "LCPD-36801","USB-DFU boot test fail incorrect configuration","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-36744","Linux SDK: CPSW: Bridge interface cannot ping in Switch Mode","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am64xx_sk-fs,am64xx_evm-se,am64xx_sk-se,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm,j784s4-evm,j784s4-hsevm"
   "LCPD-36654","USB PHY pllrefsel is configured after USB LPSC enabled","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se"
   "LCPD-36653","modprobe -r dwc3-am62 fails","am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se"
   "LCPD-36631","AM625 SK EVM duplicate mbox node","am62xx_sk-fs"
   "LCPD-35111","AM62x: CPU Frequency error","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-35109","AM62x SK: OSPI NOR DFU fails ","am62xx_sk-fs"
   "LCPD-35096","OPTEE xtest failures","am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am68_sk-fs"
   "LCPD-35056","'Error: ""main_cpsw0_qsgmii_phyinit"" not defined' on AM62x","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-35055","ERROR: reserving fdt memory region failed on AM62x","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62xx-lp-sk,am62xx-sk"
   "LCPD-34833","AM62: Wi-Fi not functional after 6.1/kirkstone migration","am62xx_sk-fs,am62xx-sk"
   "LCPD-34780","DT property ti,driver-strength-ohm is only applicable to AM64x MMC0","am64xx-evm,am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-lp-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-34242","GPIO_S_FUNC_DIR_IN_ALL_BANK unit test fails","am62xx_sk-fs,am62xxsip_sk-fs,am62xxsip_sk-se,am62xx-sk,am68_sk-fs,am69_sk-fs,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-32356","AM62x: tcrypt doesn't use sa2ul for SHA256/512 or any other alg","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-lp-sk,am62xx-sk"
   "LCPD-29654","AM62x: OSPI read Performance test fail ","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-29489","M4F Core should be able to load data to OC_SRAM","am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx-lp-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-29445","AM62ax: MCAN CAN_S_FUNC_MODULAR test is failing","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-23011","Missing u-boot README file for AM64x","am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62xx-sk,am64xx_sk-fs"

|


