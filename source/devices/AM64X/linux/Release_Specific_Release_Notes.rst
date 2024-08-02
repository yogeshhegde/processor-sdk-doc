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

To simplify the end user experience, Processor SDK Linux AM64x installer provides everything needed as discussed below
to create the embedded system from “scratch” :

-  Platform/board-support software and configuration files for Linux
-  U-Boot and Kernel sources and configuration files
-  An ARM cross-compiling toolchain as well as other host binaries and components
-  A Yocto/OE compliant filesystem and sources for example applications
-  A variety of scripts and Makefiles to automate certain tasks
-  Other components needed to build an embedded system that don’t fit neatly into one of the above buckets
-  Reference Examples, benchmarks

This release supports SR2.0 High Security - Field Securable (HS-FS) devices. For migration guide and other info, refer :ref:`HS-Migration-Guide`

Licensing
=========

Please refer to the software manifests, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page or in the installed directory as indicated below.

-  Linux Manifest:  "/docs/software_manifest.html"


Release 10.00.07.04
===================

Released on August 2024

What's new
----------

**Processor SDK Linux AM64X Release has following Major Updates**

  - LTS Refresh with Stable Kernel update to 6.6.32
  - Important Bug Fixes on top of Processor SDK 09.02.01.10 Release
  - Kernel: MMC Highspeed tuning and Performance Improvements
  - RT Kernel : Significant Improvements to Real-Time Linux Interrupt Latency, :ref:`RT Interrupt Latencies <RT-linux-performance>`
  - Bug Fixes and Stability Improvements
  - TIFS, DM, R5 SPL: PLL Configuration sequence updated to latest recommendation
  - DMSC Firmware: No longer re-initializing ICSSG clocks
  - HSR Tx Tag Insertion and Rx Tag Removal offload on ICSSG

**Component version:**

  - Kernel 6.6.32
  - RT Kernel 6.6.32-rt32
  - U-Boot 2024.04
  - Toolchain GCC 13.3
  - ATF 2.10+
  - OPTEE 4.2.0
  - TIFS Firmware v10.00.08
  - DM Firmware 10.00.00.08

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

| Head Commit: 03f2d14c2e4fefacb17aeab1540cbec694c3f217 recipes-kernel/recipes-bsp: Bump up SRCREV for jailhouse
| Date: 2024-05-17 01:52:07 -0500

| Clone: git://git.ti.com/ti-sdk-linux/meta-tisdk.git
| Branch: kirkstone
| Release Tag: 09.02.01.10
|

Issues Tracker
==============

Errata Workarounds Available in this Release
--------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 30, 150

   "LCPD-37352","CDNS: USB2 PHY locks up due to short suspend","am64xx-evm"
   "LCPD-32825","PCIe: ls -al /dev/disk/by-id shows no nvme device","am64xx-hsevm"
   "LCPD-27886","USART: Erroneous clear/trigger of timeout interrupt","am64xx-evm,am62axx_sk-fs,am62xxsip_sk-fs,am62xxsip_sk-se,am62xx-sk,j721e-idk-gw,j7200-evm,j784s4-evm,j784s4-hsevm"
   "LCPD-25264","BCDMA: Blockcopy Gets Corrupted if TR Read Responses Interleave with Source Data Fetch","am64xx-evm,am64xx-hsevm,am64xx_sk-fs"
   "LCPD-19965","OSPI PHY Controller Bug Affecting Read Transactions","am654x-idk,am64xx-evm,j721e-idk-gw,j7200-evm"

|

Known Issues
------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35

   "LCPD-37197","am64xx-evm, am64xx-hsevm","AM64x: ICSSG: Firmware is not updating the Host Port statistics",""
   "LCPD-36864","am64xx-evm","ICSSG1 is not working in Debian but working in Yocto",""
   "LCPD-37780","am64xx-evm","HSR offload doesn't work when PRU firmware is not loaded prior to HSR firmware",""
   "LCPD-37746","am64xx-evm,am64xx-hsevm","AM64x: u-boot UHS104 card speed check test fails",""
   "LCPD-37744","am64xx-evm,am64xx-hsevm,am64xx_sk-fs,am64xx_evm-se,am64xx_sk-se","AM64x: RNG S Func tests fail",""
   "LCPD-37743","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62axx_sk-fs,am62axx_sk-se","AM64x: K3conf SoC rev kernel crash test fails",""
   "LCPD-37730","am64xx-evm","PRU_ICSSG PPS Support Documentation and DTS discrepancy",""
   "LCPD-37724","am64xx-hsevm,am62xx_lp_sk-fs","CICD: ETH_CPSW2g_TAS_1A : TSN: TAS test failed, queue 0 did not increase",""
   "LCPD-37714","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se","CAN suspend and loopback tests are failing",""
   "LCPD-37463","am64xx-evm,am64xx-hsevm","We don't have SMMU kernel options related to VFIO should be NOIOMMU set",""
   "LCPD-37226","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se,am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm","Update Ubuntu Host version in Linux documentation",""
   "LCPD-37197","am64xx-evm,am64xx-hsevm","AM64x: ICSSG: Firmware is not updating the Host Port statistics",""
   "LCPD-37163","am64xx-evm,am64xx-hsevm","AM64x: Ping in Switch mode results in duplicate packets",""
   "LCPD-36993","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se,am62pxx-zebu,am62lxx-vlab,am62lxx-zebu,am62xx_p0_sk-fs,am64xx_sk-fs,am64xx_evm-se,am64xx_sk-se,am68_sk-fs,am69_sk-fs,beaglebone,bbai,bbai64-gp,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j721s2_evm-se,j7200-evm,j7200-hsevm,j784s4-evm,j784s4-hsevm,j722s_evm-fs,J784S4_BASESIM","U-Boot: lpddr4.c: Error handling missing failure cases",""
   "LCPD-36985","am64xx-hsevm","AM64 Yocto SDK UG: Invalid eMMC Programming Steps in U-Boot Section",""
   "LCPD-36981","am64xx-evm,am64xx-hsevm","AM64x missing DMTimer support",""
   "LCPD-36876","am64xx-hsevm","running linuxptp (ptp4l, phc_ctl or ts2phc, setting clock) it will cause PPS incoherence",""
   "LCPD-36804","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am64xx_sk-fs,am64xx_evm-se,am64xx_sk-se","IPC performance test fail - modprobe fails",""
   "LCPD-36431","am64xx-evm","ti-linux:am64x: eMMC: Fix iTAP values dumps issue.",""
   "LCPD-36430","am64xx_sk-fs","ti-linux: MMC: Fix MMC Tunning Algorithm",""
   "LCPD-36414","am64xx-evm,am62xx_sk-fs","Performance numbers for NOR, eMMC missing in doc",""
   "LCPD-36361","am64xx-hsevm,am62xxsip_sk-se","Boot failure over UART",""
   "LCPD-36358","am64xx-evm","am64x: eth2 link fails to come up for test_nway test",""
   "LCPD-35352","am64xx-evm,am64xx_sk-fs","AM64x dts file calls SYNC2_OUT the wrong name",""
   "LCPD-35022","am64xx-hsevm","AM64x: Benchmark OOB doesn't show any load on A53 and R5 (core 0) with latest ti-rpmsg-char v6.1",""
   "LCPD-29861","am64xx-evm,am64xx-hsevm,am64xx-hssk,am64xx_sk-fs","AM64x: IPC tests fail",""
   "LCPD-25540","am64xx-hsevm,am64xx_sk-fs","AM64: u-boot: usb host boot failed",""
   "LCPD-25494","am64xx-evm","AM64 EVM TSN IET tests is failing",""
   "LCPD-24872","am64xx_sk-fs","Am64x-sk :LCPD-16811 CPSW  failed while throughput metrics comparison ",""
   "LCPD-24823","am64xx-evm,am64xx_sk-fs","Clarify Single-Core usage in ti,k3-r5f-rproc.yaml",""
   "LCPD-24726","am64xx_sk-fs","Uboot qspi read write performance test  failed ",""
   "LCPD-24595","am64xx-evm,am64xx_sk-fs,j721e-idk-gw,j721e-sk,j7200-evm","j721e-idk-gw USB Suspend/Resume with RTC Wakeup fail (Impact 1)",""
   "LCPD-24537","am654x-evm,am64xx-evm,am64xx-hsevm","am654x-idk nslookup times out when all netwokring interfaces are active",""
   "LCPD-24467","am64xx_sk-fs","am64xx-sk stress boot test fails",""
   "LCPD-24456","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am62xx-sk,am64xx_sk-fs,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j721e-hsevm,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j7200-evm,j7200-hsevm,omapl138-lcdk","Move IPC validation source from github to git.ti.com",""
   "LCPD-24448","am64xx-evm,am64xx-hsevm","Verify IPC kernel: main-r5f0(s)/main-r5f1(s)",""
   "LCPD-23102","am64xx_sk-fs","AM64-SK: DMA is not stable",""
   "LCPD-23066","am64xx_sk-fs","am64x-sk :gpio: direction test fail",""
   "LCPD-22912","am64xx-evm","am64xx-evm SMP dual core test fails sporadically",""
   "LCPD-22892","am654x-evm,am654x-idk,am64xx-evm","icssg: due to FW bug both interfaces has to be loaded always",""
   "LCPD-22834","am64xx-evm","am64xx-evm stress boot test fails",""
   "LCPD-20105","am64xx-evm","AM64x: Kernel: ADC: RX DMA channel request fails",""
   "SYSFW-6432","am62x,am62ax,am62px,am64x,am65x","Set device API doesn't return Error when PD is in transition state",""
   "SYSFW-6426","am62x,am62ax,am62px,am64x,am65x","Ownership of a firewall region can be transferred to an invalid host",""
   "SITSW-3922","am64xx-evm, am64xx-sk, am62xx-sk, am62xx-sk-lp, am62x-sip-sk, am62p-sk","Flash writer: Benchmark script fails for emmc logs",""

|

Issues opened in previous releases that were closed on this release
-------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-37795","RAM size not updated, when ECC is enabled","am62axx_sk-fs, am62pxx_sk-fs, am64xx_sk-fs"
   "LCPD-37917","AM64: Wifi broken on SK-AM64B","am64xx-evm, am64xx-hsevm"
   "LCPD-37831","ICSSG as switch is broken","am64xx-evm, am64xx-hsevm"
   "LCPD-37389","Building Kernel from sources doesn't cover list of dependencies","am64xx-evm,am64xx-hssk,am62xx_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs,am64xx_sk-fs,am64xx_sk-se"
   "LCPD-37388","Building U-Boot from sources doesn't cover list of dependencies","am64xx-hssk,am62xx_sk-fs,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am64xx_sk-fs,am64xx_evm-se"
   "LCPD-36615","Linux SDK Docs for most K3 devices contain an outdated device list in the Kernel/SPI Section","am62axx_sk-fs, am62axx_sk-se, am62pxx_sk-fs, am62pxx_sk-se, am62xx_lp_sk-fs, am62xx_lp_sk-se, am62xx_p0_sk-fs, am62xx_sk-fs, am62xx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se, am64xx-hsevm, am64xx-hssk, am64xx_evm-se, am64xx_sk-fs, am64xx_sk-se"
   "LCPD-37829","SDK 9.2 Three-board HSR offload fails on middle board","am64xx-evm, am64xx-hsevm"
   "LCPD-37742","AM64x: uboot eMMC speed check test fails","am64xx-evm,am64xx-hsevm,am64xx-hssk"
   "LCPD-37721","ICSSG : RX Frame Drop during XDP ","am654x-idk,am64xx-evm,am64xx-hsevm"
   "LCPD-37524","ti-rpmsg-char: remove references to ti.ipc4.ping-pong ","am654x-evm,am654x-idk,am64xx-evm,am62xx_sk-fs,am62axx_sk-fs,am62pxx_sk-fs"
   "LCPD-37503","Multicast filtering with HSR non-offload does not work","am64xx-evm"
   "LCPD-37501","HSR two board setup requires running hsr setup script twice","am64xx-evm,am64xx-hsevm"
   "LCPD-37500","Multicast filtering with HSR does not work after running HSR hw offload setup twice","am64xx-evm"
   "LCPD-37352","CDNS: USB2 PHY locks up due to short suspend","am64xx-evm"
   "LCPD-37327","eMMC: Doc and testcase update needed to enable RST_FUNCTION for warm reboot","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se"
   "LCPD-37309","Search is broken, never completes in 9.1 Linux SDKs","am64xx-evm,am64xx-hsevm,am62xx_sk-fs,am64xx_sk-fs"
   "LCPD-37300","AM64x SDK v9.1 SDK Images don't boot on SK-AM64B due to U-Boot using incorrect DTS File from EVM","am64xx-hsevm,am64xx-hssk"
   "LCPD-37223","AM64x: ICSSG1 MII mode isn't working","am64xx-evm,am64xx-hsevm"
   "LCPD-37207","Docker is disabled in RT Linux","am64xx-hssk,am62xx_lp_sk-fs,am62xxsip_sk-fs,am62pxx_sk-fs"
   "LCPD-32640","Kernel HSR does not work on base image (same command works on default)","am64xx-evm"

|

Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-37084","AM64x : GPMC NAND Boot ","am64xx-evm,am64xx-hsevm,am64xx-hssk,am64xx_evm-se"
   "LCPD-36992","U-Boot: k3-ddrss.c: Missing 'const' on k3_ddrss_ops","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,beagleplay-gp,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62lxx_evm-fs,am62lxx_evm-se,am62pxx-zebu,am62lxx-vlab,am62lxx-zebu,am62xx_p0_sk-fs,am64xx_sk-fs,am64xx_evm-se,am64xx_sk-se,am68_sk-fs,am69_sk-fs,beaglebone,bbai,bbai64-gp,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j721s2_evm-se,j7200-evm,j7200-hsevm,j784s4-evm,j784s4-hsevm,j722s_evm-fs,J784S4_BASESIM"
   "LCPD-36868","AM64x MMC1 HS OTAPSEL value is incorrect in kernel device tree","am64xx-evm,am64xx-hsevm,am64xx-hssk"
   "LCPD-36850","HSR switching offload firmware needs to be loaded twice","am64xx-hsevm"
   "LCPD-36847","doc: ltp-ddt documentation is not upto date","am64xx-hsevm,am62xx_sk-fs,am62axx_sk-fs,am62pxx_sk-fs,am68_sk-fs,am69_sk-fs,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-36842","ETH_XS_FUNC_ICSSG_TESTS_SPEED Fails","am64xx-hsevm"
   "LCPD-36744","Linux SDK: CPSW: Bridge interface cannot ping in Switch Mode","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am64xx_sk-fs,am64xx_evm-se,am64xx_sk-se,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm,j784s4-evm,j784s4-hsevm"
   "LCPD-36645","AM64X: Linux HSR - Multicast filtering support","am64xx-evm"
   "LCPD-36395","MMC delaybuffer duration, DLL / delay chain select, and DLL Ref Frequency are not programmed to PHY_CTRL5 register","am64xx-evm,am64xx_sk-fs"
   "LCPD-35108","AM64x: eMMC boot fails using flashed using DFU ","am64xx-evm"
   "LCPD-35096","OPTEE xtest failures","am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am68_sk-fs"
   "LCPD-34800","eMMC itapdly sel is not programmed to PHY_CTRL4 register","am64xx-evm,am64xx_sk-fs"
   "LCPD-34780","DT property ti,driver-strength-ohm is only applicable to AM64x MMC0","am64xx-evm,am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-lp-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-32868","Kernel crash from PRU auto-forwarding packet","am654x-idk,am64xx-evm"
   "LCPD-32481","AM64x: Environment variables for DFU to NAND","am64xx-evm,am64xx-hsevm"
   "LCPD-29597","AM64x: dts: main_rti nodes are defined twice","am64xx-evm"
   "LCPD-29489","M4F Core should be able to load data to OC_SRAM","am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx-lp-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-29445","AM62ax: MCAN CAN_S_FUNC_MODULAR test is failing","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se"
   "LCPD-24288","am64xx-evm NCM/ACM network performance test crashes with RT images","am64xx-evm,am64xx-hsevm"
   "LCPD-23011","Missing u-boot README file for AM64x","am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62xx-sk,am64xx_sk-fs"
   "LCPD-20006","AM64x: remoteproc may be stuck in the start phase after a few times of stop/start","am64xx-evm"
   "SYSFW-7315","Extra bypass step in boot time pll init routine","am62x,am62a,am62px"
   "SYSFW-7370","pm init functions are missing proper return values","am64x,am62x,am62a,am62px"

|
