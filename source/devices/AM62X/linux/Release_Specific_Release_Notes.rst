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

-  Linux Manifest:  :file:`<PSDK_PATH>/docs/software_manifest.html`

Release 10.00.07.04
===================

Released on August 2024

What's new
----------

**Processor SDK Linux AM62X Release has following new features:**

  - LTS Refresh with Stable Kernel update to 6.6.32
  - Important Bug Fixes on top of Processor SDK 09.02.01.10 Release
  - `CC33XX M.2 Module <https://www.ti.com/tool/M2-CC3351>`__ Wi-Fi support on `SK-AM62B-P1 <https://www.ti.com/tool/SK-AM62B-P1>`__ & `SK-AM62B <https://www.ti.com/tool/SK-AM62B>`__ - :ref:`How to Enable M.2-CC33x1 in Linux <enable_m2cc3301>`
  - Kernel: MMC Highspeed tuning and Performance Improvements
  - RT Kernel : Significant Improvements to Real-Time Linux Interrupt Latency - :ref:`RT Interrupt Latencies <RT-linux-performance>`
  - Power Management: DeepSleep, MCU-Only and Partial IO mode - :ref:`Power Management Overview <Power-Management>`
  - OOB: GPU Accelerated Chromium Browser Support - :ref:`Chromium Browser <Chromium_Browser-label>`
  - TIFS, DM, R5 SPL: PLL Configuration sequence updated to latest recommendation


**Component version:**

  - Kernel 6.6.32
  - RT Kernel 6.6.32-rt32
  - U-Boot 2024.04
  - Toolchain GCC 13.3
  - ATF 2.10+
  - OPTEE 4.2.0
  - Graphics DDK 24.1
  - TIFS Firmware v10.00.08
  - DM Firmware 10.00.00.08
  - Yocto scarthgap


Build Information
=================

.. _u-boot-release-notes:

U-Boot
------

.. rubric:: u-boot
   :name: u-boot

| Head Commit: fda88f8bcea30590528930ff9441c6e958da86f5 clk: ti: clk-k3-pll: Add additional robustness steps to the PLL sequence
| Date: 2024-07-28 10:37:17 -0500
| uBoot Version: 2024.04
| uBoot Description: RC Release 10.00.07
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2024.04
| uBoot Tag: 10.00.07
|

.. _tf-a-release-notes:

TF-A
----
| Head Commit: 00f1ec6b8740ccd403e641131e294aabacf2a48b Merge changes from topic "revert-ti-dm-workaround" into integration
| Repo: https://git.trustedfirmware.org/TF-A/trusted-firmware-a.git
| Branch: master
| Tag: 2.10+
|

.. _optee-release-notes:

OP-TEE
------
| Head Commit: 12d7c4ee4642d2d761e39fbcf21a06fb77141dea Update CHANGELOG for 4.2.0
| Repo: https://github.com/OP-TEE/optee_os/
| Branch: master
| Tag: 4.2.0
|

.. _ti-linux-fw-release-notes:

ti-linux-firmware
-----------------
| Head Commit: 1e01062a34b88427c2fca1ce7c5a5c308961e0c7 ti-eth: update firmware to 10.00.00.02 for j721e, j7200 and j784s4
| Date: 2024-07-28 10:37:11 -0500
| Clone: https://git.ti.com/cgit/processor-firmware/ti-linux-firmware
| Branch: ti-linux-firmware
| Tag: 10.00.07
|

Kernel
------
.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 6de6e418c80edfbe08f4a5f851c721bd60c0123b net: ti: icssg_prueth: Enable 10M Link issue quirk for AM64x
| Date: 2024-07-28 10:37:02 -0500
| Kernel Version: 6.6.32
| Kernel Description: RC Release 10.00.07

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-6.6.y
| Tag: 10.00.07
| use-kernel-config=defconfig
| config-fragment=kernel/configs/ti_arm64_prune.config
|


.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 04a9ad081f0f255a046f398abf6faf1d4374267f Merge branch 'ti-linux-6.6.y-cicd' into ti-rt-linux-6.6.y-cicd
| Date: 2024-07-28 10:37:05 -0500
| Kernel Version: 6.6.32-rt32
| Kernel Description: RC Release 10.00.07-rt

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-6.6.y
| Tag: 10.00.07-rt
| use-kernel-config=defconfig
| config-fragment=config-fragment=kernel/configs/ti_arm64_prune.config kernel/configs/ti_rt.config
|


Yocto
-----
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 138077349667614f83637c98798c06249615a23e CI/CD Auto-Merger: cicd.scarthgap.202407271443
| Date: 2024-07-28 10:37:17 -0500

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: scarthgap
| Release Tag: 10.00.07
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: 82833bae8835e06301c23c8833642ae4c02d303a packagegroup-arago-tisdk-multimedia: Add ffmpeg package
| Date: 2024-07-28 10:36:40 -0500

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: scarthgap
| Release Tag: 10.00.07
|

.. rubric:: meta-tisdk
   :name: meta-tisdk

| Head Commit: af81e0d81c5efd005bfc0ef749f690f9748c70f6 recipes-demos: ti-apps-launcher: Bump up SRCREV
| Date: 2024-08-05 01:53:23 -0500

| Clone: https://github.com/TexasInstruments/meta-tisdk.git
| Branch: scarthgap
| Release Tag: 10.00.07.04
|

.. rubric:: meta-edgeai
   :name: meta-edgeai

| Head Commit: 836b1a3aa89d087474495ab4f77fc7a06ffcef0f edgeai-test-data.bb: edgeai-tidl-models.bb: Updated EDGEAI_SDK_VERSION
| Date: 2024-07-30 05:58:20 -0500

| Clone: https://git.ti.com/git/edgeai/meta-edgeai.git
| Branch: scarthgap
| Release Tag: 10.00.00.04
|

.. important::

    meta-edgeai layer is not applicable in case of SK-AM62-SIP (i.e. am62xxsip-evm)

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
   "LCPD-37418","am62xxsip_sk-se","Intermittent board hang during UART boot after successfully loading tispl.bin",""
   "LCPD-37417","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am68_sk-fs,am69_sk-fs,j721e-idk-gw,j721s2-evm,j784s4-evm,j722s_evm-fs","RGX_S_FUNC_APM test is failing",""
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

   "LCPD-38002","HSR Error: 8021q: VLANs not supported on device.","am62xx_sk-fs"
   "LCPD-37965","BCDMA: RX Channel can lockup in certain scenarios","am62axx_sk-fs, am62axx_sk-se, am62pxx_sk-fs, am62pxx_sk-se, am62xx_lp_sk-fs, am62xx_lp_sk-se, am62xx_p0_sk-fs, am62xx_sk-fs, am62xx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se"
   "LCPD-37443","McASP - Improve audio loopback latency","am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs"
   "LCPD-37389","Building Kernel from sources doesn't cover list of dependencies","am64xx-evm,am64xx-hssk,am62xx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs,am64xx_sk-fs,am64xx_sk-se"
   "LCPD-37388","Building U-Boot from sources doesn't cover list of dependencies","am64xx-hssk,am62xx_sk-fs,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am64xx_sk-fs,am64xx_evm-se"
   "LCPD-36615","Linux SDK Docs for most K3 devices contain an outdated device list in the Kernel/SPI Section","am62axx_sk-fs, am62axx_sk-se, am62pxx_sk-fs, am62pxx_sk-se, am62xx_lp_sk-fs, am62xx_lp_sk-se, am62xx_p0_sk-fs, am62xx_sk-fs, am62xx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se, am64xx-hsevm, am64xx-hssk, am64xx_evm-se, am64xx_sk-fs, am64xx_sk-se"
   "LCPD-37795","RAM size not updated, when ECC is enabled","am62axx_sk-fs, am62pxx_sk-fs, am62xx_lp_sk-fs, am62xx_lp_sk-se, am64xx_sk-fs"
   "LCPD-37805","Doc: AM62x: Known Issues table is missing in release notes","am62xx_sk-fs, am62xx_sk-se "
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
   "SYSFW-7183","Warm reset after system LPM entry/exit results in u-boot/DM hang","am62x,am62px"

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
   "SYSFW-7040","JTAG unlock issue on MCU-M4 on AM62x HS-SE","am62x"
   "SYSFW-7251","Enabling DM UART traces in boardcfg causes abort in DeepSleep resume path","am62x,am62a,am62px"
   "SYSFW-7315","Extra bypass step in boot time pll init routine","am62x,am62a,am62px"
   "SYSFW-7327","DM self reset goes to abort with logs enabled in SBL flow","am62x,am62a,am62px"
   "SYSFW-7370","pm init functions are missing proper return values","am64x,am62x,am62a,am62px"
   "SYSFW-7375","Firewall Exception during devices_init function in DM","am62x,am62a,am62px"
   "SITSW-4243","Enabling DM firmware log causing the DM to go to abort","am62x,am62a,am62px"

|


