.. _release-specific-release-notes:

************************************
Release Notes
************************************
.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Release_Notes

Overview
========

The **Processor Software Development Kit (Processor-SDK) for Linux**
provides a fundamental software platform for development, deployment and
execution of Linux based applications and includes the following:

-  Bootloaders, Linux Kernel & Filesystem
-  SDK installer & Prebuilt Binaries
-  Setup scripts
-  Demo applications
-  Documentation

.. ifconfig:: CONFIG_sdk in ('PSDKL')

   .. Note::
      For building some of the RTOS-based demonstrations, you should also download
      Processor SDK RTOS installer. For more information,
      refer to <PSDKRA install path>/index.html.


Licensing
=========

Please refer to the software manifest, which outlines the licensing
status for all packages included in this release. The manifest can be found on the SDK
download page or in the installed directory as indicated below. In
addition, see :ref:`Processor SDK Linux GPLv3 Disclaimer <overview-gplv3-disclaimer>`.


Documentation
=============
-  :ref:`Processor SDK Linux Software Developer's Guide <linux-index>`: Provides information on features, functions, delivery package and,
   compile tools for the Processor SDK Linux release. This also provides
   detailed information regarding software elements and software
   infrastructure to allow developers to start creating applications.
-  :ref:`Processor SDK Linux Getting Started Guide <overview-getting-started>`: Provides information on getting the software and running
   examples/demonstrations bundled in the SDK.
-  **Software Manifest**: Provides license information on software
   included in the SDK release. This document is in the release at
   ``[INSTALL-DIR]/manifest``.
-  **EVM Quick Start Guide**: Provides information on hardware setup and
   running the demonstration application that is loaded on flash. This
   document is provided as part of the EVM kit.


Supported Platforms
===================
See :ref:`here <release-specific-supported-platforms-and-versions>` for a list of supported platforms and links to more information.


Release 10.00.00
================

Released Aug 2024

.. rubric:: What's New
   :name: whats-new

Processor SDK 10.00 Release supports the following platforms:

  * J721E
  * J7200
  * J721S2
  * J784S4
  * AM68
  * AM69
  * J722S

Processor SDK 10.00 Release has following new features:

  * This is the First release on LTS stream 6.6 kernel, 2024.04 U-Boot and Yocto Scarthgap/5.0
  * ATF 2.10
  * OPTEE 4.2.0
  * Yocto Scarthgap/5.0
  * Audio support added for J784S4 and J722S
  * Inline ECC Support for AM68, AM69, J722S
  * OSPI NAND boot Support for J722S

Build Information
=================

.. _u-boot-release-notes:

U-Boot
------
| Head Commit: fda88f8bcea30590528930ff9441c6e958da86f5 clk: ti: clk-k3-pll: Add additional robustness steps to the PLL sequence
| Date: Fri Jul 26 15:00:55 2024 +0530
| uBoot Version: 2024.04
| uBoot Description: 10.00.07

| Repo: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2024.04
| uBoot Tag: 10.00.07

| Compiler Information: arm-oe-eabi-gcc (GCC) 13.3.0, aarch64-oe-linux-gcc (GCC) 13.3.0
|

.. note::

   meta-tisdk Yocto layer contains additional patches for U-Boot `here <https://git.ti.com/cgit/ti-sdk-linux/meta-tisdk/tree/recipes-bsp/u-boot?h=REL.J7.10.00.07>`__.


.. _kernel-release-notes:

Kernel
------
.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 6de6e418c80edfbe08f4a5f851c721bd60c0123b net: ti: icssg_prueth: Enable 10M Link issue quirk for AM64x
| Date: Fri Jul 26 11:54:25 2024 +0530
| Kernel Version: 6.6.32
| Kernel Description: 10.00.07

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-6.6.y
| Tag: 10.00.07
| Kernel defconfig: defconfig + ti_arm64_prune.config

| Compiler Information: aarch64-oe-linux-gcc (GCC) 13.3.0, GNU ld (GNU Binutils) 2.42.0
|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 04a9ad081f0f255a046f398abf6faf1d4374267f Merge branch ‘ti-linux-6.6.y-cicd’ into ti-rt-linux-6.6.y-cicd
| Date: Fri Jul 26 09:42:37 2024 -0500
| Kernel Version: 6.6.32
| Kernel Description: 10.00.07-rt

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-6.6.y
| Tag: 10.00.07-rt
| Kernel defconfig: defconfig + ti_rt.config + ti_arm64_prune.config

| Compiler Information: aarch64-oe-linux-gcc (GCC) 13.3.0, GNU ld (GNU Binutils) 2.42.0

.. note::

   meta-tisdk Yocto layer contains additional patches for Linux Kernel `here <https://git.ti.com/cgit/ti-sdk-linux/meta-tisdk/tree/recipes-kernel/linux?h=REL.J7.10.00.07>`__.

.. _tf-a-release-notes:

TF-A
----
| Head Commit: 00f1ec6b8740ccd403e641131e294aabacf2a48b Merge changes from topic “revert-ti-dm-workaround” into integration
| Date : Fri Feb 9 17:09:05 2024 +0100 
| Version: 2.10

| Repo: https://git.trustedfirmware.org/TF-A/trusted-firmware-a.git
| Branch: master
|

.. _optee-release-notes:

OP-TEE
------
| Head Commit: 12d7c4ee4642d2d761e39fbcf21a06fb77141dea Update CHANGELOG for 4.2.0
| Date : Mon Mar 25 08:04:39 2024 +0100
| Version: 4.2.0

| Repo: https://github.com/OP-TEE/optee_os/
| Branch: master
| Tag: 4.2.0
|

.. _ti-linux-fw-release-notes:

ti-linux-firmware
-----------------
| Head Commit: 1e01062a34b88427c2fca1ce7c5a5c308961e0c7 ti-eth: update firmware to 10.00.00.02 for j721e, j7200 and j784s4
| Date: Fri Jul 26 18:29:44 2024 +0530

| Repo: https://git.ti.com/cgit/processor-firmware/ti-linux-firmware
| Branch: ti-linux-firmware
| Tag: 10.00.07
|



Yocto
-----
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 138077349667614f83637c98798c06249615a23e CI/CD Auto-Merger: cicd.scarthgap.202407271443
| Date: Sat Jul 27 14:44:31 2024 -0500

| Repo: git://git.yoctoproject.org/meta-ti
| Branch: scarthgap
| Release Tag: 10.00.07
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: 82833bae8835e06301c23c8833642ae4c02d303a packagegroup-arago-tisdk-multimedia: Add ffmpeg package
| Date: 2024-07-23 15:49:48 -0500

| Repo: git://git.yoctoproject.org/meta-arago
| Branch: scarthgap
| Release Tag: 10.00.07
|

.. rubric:: meta-tisdk

| Head Commit: a1b65d18db3c83f2c9cdf25c0f4fa334cb2a1849 jailhouse: Update SRCREV for 10.00.07 tag
| Date: 2024-07-29 07:51:46 -0500

| Repo: git://git.ti.com/ti-sdk-linux/meta-tisdk.git
| Branch: scarthgap
| Release Tag: 
|

Issues Tracker
==============

Issues opened in previous releases that were closed on this release
-------------------------------------------------------------------
.. csv-table::
  :header: "Record ID", "Title", "Platform"
  :widths: 15, 70, 20

  "LCPD-37739","Kernel soft-booting failure on j784s4/AM69 ","am69_sk-fs,j784s4-evm"
  "LCPD-37701","J722S : UART test failing in SDK 9.2 and LTS 2024","j722s_evm-fs"
  "LCPD-37700","J722S : Audio support missing ","j722s_evm-fs"
  "LCPD-37696","ECC Support failure","am68_sk-fs,am69_sk-fs,j721s2-evm,j784s4-evm"
  "LCPD-37690","UFS test case failing on J784S4","j721e-idk-gw,j784s4-evm"
  "LCPD-37689","SPL/U-Boot: NOR flash boot mode support using OSPI controller","j722s_evm-fs"
  "LCPD-37662","Capability gap coming as failure","am68_sk-fs"
  "LCPD-37660","J721E: U-Boot does not support booting SR1.1 HS-FS and SR2.0 HS-TIDK SoCs","j721e-hsevm"
  "LCPD-37622","J721E EVM 9.0 SDK HDMI grabber not detected while using DP-to-HDMI adapter","j721e-evm-ivi"
  "LCPD-37611","IPC: LTP Test failure for j784s4-evm platform (Regression)","am69_sk-fs,j784s4-evm"
  "LCPD-37493","emmc boot is broken in Test farm ","am69_sk-fs,j7200-evm,j721e-idk-gw,j721s2-evm,j722s_evm-fs,j784s4-evm"
  "LCPD-37417","RGX_S_FUNC_APM test is failing","am62xx_lp_sk-fs,am62xx_lp_sk-se,am62xx_sk-fs,am62xx_sk-se,am68_sk-fs,am69_sk-fs,j721e-idk-gw,j721s2-evm,j722s_evm-fs,j784s4-evm"
  "LCPD-37410","CAN interface removed from 9.x SDK for SK-TDA4VM","j721e-sk"
  "LCPD-37334","OSPI NOR Broken in upstream","j7200-evm"
  "LCPD-37326","SDK performance guide calls out DCAN benchmarks","am69_sk-fs"
  "LCPD-37186","J7AEN R5 SPL: DMA fails in R5 SPL","j722s_evm-fs"
  "LCPD-36990","j7200: USB audio test fail inconsistently","j7200-evm"
  "LCPD-36472","USB Audio Device not Found","j7200-evm"
  "LCPD-36283","MMCO errors reported from ITXAI stream","j721e-idk-gw,j721e-sk"
  "LCPD-35340","Modify Uart Testcase","j721s2-evm,j784s4-evm"
  "LCPD-35092","Over all test infra/script update for CSI testing","am68_sk-fs,am69_sk-fs,j721e-idk-gw,j721s2-evm,j784s4-evm"
  "LCPD-35069","DFU boot fails on J784S4","j784s4-evm"
  "LCPD-35067","Dropped frames at end of H264/HEVC decoding","j721e-idk-gw"
  "LCPD-35029","IPC test case script update ","am68_sk-fs,am69_sk-fs,j7200-evm,j721e-evm-ivi,j721e-hsevm,j721e-idk-gw,j721e-sk,j784s4-evm,j784s4-hsevm"
  "LCPD-35027","J7 Power off is not working","j7200-evm,j721e-idk-gw,j721s2-evm"
  "LCPD-34590","AM69x: CICD next failures of unit tests across components","am69_sk-fs"
  "LCPD-34589","AM68x: CICD next failures of unit tests across components","am68_sk-fs"
  "LCPD-34556","Dhystrone DMIPS Reported in Release Notes Not Consistently Achieved","j721e-evm-ivi"
  "LCPD-34136","J721E-SK PMIC reset","j721e-sk"
  "LCPD-32827","j784s4  evm with 21A27-AM116 emmc (32 GB )variant emmc performance is not as per standards in HS400","am69_sk-fs,j784s4-evm"
  "LCPD-32723","remote proc booting of C7x in non-SMP mode (AHP) RC 6 SDK 8.6","am69_sk-fs,j784s4-evm"
  "LCPD-29705","J7200: DT compile time warnings","j7200-evm"
  "LCPD-28494","J721E: Upstream CPU hotplugging fails","am68_sk-fs,am69_sk-fs,j721e-idk-gw"
  "LCPD-28439","hbmc-mux: $nodename:0: 'hbmc-mux' does not match '^mux-controller(@.*|-[0-9a-f]+)?$'","j7200-evm"

|

Issues found and closed on this release that may be applicable to prior releases
--------------------------------------------------------------------------------
.. csv-table::
  :header: "Record ID", "Title", "Platform"
  :widths: 15, 70, 20

  "LCPD-38657","Nbench perf failures requires historical data reset (lp-2016)","j721e-idk-gw,j784s4-evm"
  "LCPD-38600","RPROC_DMABUF_ATTACH ioctl is not thread safe","am62axx_sk-fs,am62axx_sk-se,j721e-idk-gw,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j722s_evm-fs,j784s4-evm,j784s4-hsevm"
  "LCPD-38592","j721e DFU boot not working","j721e-idk-gw"
  "LCPD-38557","J721s2: Main mcan 3 and 5 fails","j721s2-evm"
  "LCPD-38554","MCAN: add am68, am69, j7-sk in mcan docs ","am68_sk-fs,am69_sk-fs,j721e-sk"
  "LCPD-38526","J7200: Main mcan 3 and main mcan 0 fails","j7200-evm"
  "LCPD-38372","FPDLink: RX Port skipping leads to corrupt VC","am62axx_sk-fs,am62axx_sk-se,am62pxx_sk-fs,am62pxx_sk-se,j7200-evm,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2_evm-fs,j722s_evm-fs,j784s4-evm"
  "LCPD-38368","Nbench perf failures requires historical data reset (lp-2016)","am68_sk-fs,am69_sk-fs,j7200-evm,j7200-hsevm,j721e-hsevm,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j722s_evm-fs,j784s4-evm,j784s4-hsevm"
  "LCPD-38350","DMABuf import not working with CnM codec in ti-linux-6.6","am62axx_sk-fs,j721s2-evm,j784s4-evm"
  "LCPD-38339","Boot time tests failing for j722s ","j722s_evm-fs"
  "LCPD-38328","Emmc : raw read write test fails","am68_sk-fs,am69_sk-fs,j7200-evm,j721e-idk-gw,j721s2-evm,j722s_evm-fs,j784s4-evm"
  "LCPD-38240","J784S4: fix can3 probe failure","j784s4-evm"
  "LCPD-38238","[J784s4] Documentation correction regarding k3-j784s4-fpdlink-fusion.dtbo missing in default filesystem of the device","j784s4-evm"
  "LCPD-38215","MMC perf tests failing","j721e-idk-gw,j721s2-evm"
  "LCPD-38198","U-Boot: UART boot Documentation is wrong","j722s_evm-fs"
  "LCPD-38165","UFS kernel driver docs contain incorrect instructions","j784s4-evm"
  "LCPD-38164","USBHOST_S_FUNC_DD_RW_10M Failing in CICD LTS-2024","j721e-idk-gw"
  "LCPD-38099","i2C failure in LTS 2024 (lp-7363)","am68_sk-fs,am68_sk-se,am69_sk-fs,j722s_evm-fs,j784s4-evm"
  "LCPD-38098","IPC failure in LTS 2024","am62axx_sk-fs,am62axx_sk-se,am62lxx-vlab,am62lxx-zebu,am62lxx_evm-fs,am62lxx_evm-se,am62pxx-zebu,am62pxx_sk-fs,am62pxx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62xx_p0_sk-fs,am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am64xx-evm,am64xx-hsevm,am64xx-hssk,am64xx_evm-se,am64xx_sk-fs,am64xx_sk-se,am654x-evm,am654x-hsevm,am654x-idk,am68_sk-fs,am68_sk-se,am69_sk-fs,j7200-evm,j7200-hsevm,j721e-evm-ivi,j721e-hsevm,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j721s2_evm-se,j722s_evm-fs,j784s4-evm,j784s4-hsevm"
  "LCPD-38049","upstream u-boot broken on J784S4","j784s4-evm"
  "LCPD-38038","6.6.30 : Build Regression on K3 platforms due to kselftest","am335x-evm,am437x-idk,am57xx-evm,am62axx_sk-fs,am62pxx_sk-fs,am62xx_sk-fs,am62xxsip_sk-fs,am64xx-hsevm,am654x-idk,am68_sk-fs,am69_sk-fs"
  "LCPD-38032","Documentation:""How to Configure MSMC memory"" has wrong msmc_cache_size details","j7200-evm,j721e-evm-ivi,j721s2-evm,j784s4-evm"
  "LCPD-38015","U-boot shows error message as ""## Error: ""main_cpsw0_qsgmii_phyinit"" not defined""","j721s2-evm"
  "LCPD-37996","J722S OSPI Boot is failing","j722s_evm-fs"
  "LCPD-37978","j722s: Main GPIO count is wrong","j722s_evm-fs"
  "LCPD-37899","PCIe EP/RC transfer speed performance slow","j721e-sk,j784s4-evm"
  "LCPD-37889","DD rw test fails for mmc and emmc","j7200-evm,j721e-idk-gw,j721s2-evm,j784s4-evm"
  "LCPD-37888","J7AEN: Emmc Support is not up streamed ","j722s_evm-fs"
  "LCPD-37857","DFU boot mode is not working on SK-TDA4VM","j721e-sk"
  "LCPD-37839","U-Boot sensor overlay uEnv.txt documentation uses old dtbo file names","j721e-idk-gw,j721e-sk"
  "LCPD-37816","MAC Address changing for j722s on every boot","j722s_evm-fs"

|

Errata Workarounds Available in this Release
--------------------------------------------
.. csv-table::
  :header: "Record ID", "Title", "Platform"
  :widths: 15, 30, 150

  "LCPD-27886","USART: Erroneous clear/trigger of timeout interrupt","am62axx_sk-fs,am62xx-sk,am64xx-evm,j721e-idk-gw,j7200-evm,j784s4-evm,j784s4-hsevm"
  "LCPD-22905","UDMA: TR15 hangs if ICNT0 is less than 64 bytes","am654x-evm,j721e-idk-gw"
  "LCPD-22544","DDR: LPDDR4 should be configured to 2666 MT/S","j7200-evm"
  "LCPD-19965","OSPI PHY Controller Bug Affecting Read Transactions","am64xx-evm,am654x-idk,j721e-idk-gw,j7200-evm"
  "LCPD-19068","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame","j721e-evm,j721e-evm-ivi, j721e-idk-gw"
  "LCPD-19047","USB: Race condition while reading TRB from system memory in device mode","j721e-evm, j721e-hsevm, j721e-evm-ivi, j721e-idk-gw"
  "LCPD-17220","U-Boot Hyperbus: Hyperflash reads limited to 125MHz max. frequency","j721e-idk-gw"
  "LCPD-16605","MMC: MMC1/2 Speed Issue","j721e-evm, j721e-evm-ivi, j721e-idk-gw"



|

U-Boot Known Issues
-------------------
.. csv-table::
  :header: "Record ID", "Title", "Platform", "Workaround"
  :widths: 15, 30, 70, 30

  "LCPD-38569","j722s: Unable to communicate with MCU R5 and Main R5 when FW loaded from U-Boot","j722s_evm-fs",""
  "LCPD-38500","Add J721E SR 2.0 Support (k3conf and u-boot)","j721e-idk-gw",""
  "LCPD-38036","Ethernet MAC Address change in every boot at u-boot.","j722s_evm-fs",""
  "LCPD-37995","Format of DRAM logs print is confusing","j7200-evm,j721s2-evm,j722s_evm-fs,j784s4-evm",""
  "LCPD-37623","Board intermittently fails to acquire DHCP address","am68_sk-fs",""
  "LCPD-36993","U-Boot: lpddr4.c: Error handling missing failure cases","am62axx_sk-fs,am62axx_sk-se,am62lxx-vlab,am62lxx-zebu,am62lxx_evm-fs,am62lxx_evm-se,am62pxx-zebu,am62pxx_sk-fs,am62pxx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62xx_p0_sk-fs,am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am64xx-evm,am64xx-hsevm,am64xx-hssk,am64xx_evm-se,am64xx_sk-fs,am64xx_sk-se,am654x-evm,am654x-hsevm,am654x-idk,am68_sk-fs,am69_sk-fs,bbai,bbai64-gp,beaglebone,beagleplay-gp,j7200-evm,j7200-hsevm,j721e-evm-ivi,j721e-hsevm,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j721s2_evm-se,j722s_evm-fs,j784s4-evm,j784s4-hsevm,J784S4_BASESIM",""
  "LCPD-34124","U-boot support for rootfs flashing using fastboot","j721s2-evm,j721s2_evm-fs",""
  "LCPD-34106","SPL: USB DFU Boot fails on J721S2 EVM on upstream U-Boot(also ti-u-boot-2023.04)","j721s2-evm,j721s2_evm-fs",""
  "LCPD-32697","Failed to get DHCP address in U-Boot","j784s4-evm",""
  "LCPD-32695","J784S4 : U-boot : Mass storage tests failure","j784s4-evm",""
  "LCPD-25535","UBoot: customized ${optargs} doesn't take affect on K3 devices","am64xx-evm,am64xx-hsevm,am64xx_sk-fs,am654x-evm,am654x-hsevm,am654x-idk,j7200-evm,j7200-hsevm,j721e-evm,j721e-hsevm,j721e-idk-gw,j721s2-evm,j721s2-hsevm,j721s2_evm-fs",""
  "LCPD-24108","U-Boot: TISCI config ring fail traces seen in OSPI boot mode on J721E","j721e-evm,j721e-evm-ivi,j721e-idk-gw",""
  "LCPD-22904","U-boot: Update EMIFtool for i2244:DDR: Valid stop value must be defined for write DQ VREF training","j7200-evm,j721e-idk-gw",""
  "LCPD-17789","UBOOT J7:  Could not see UFS device by scsi scan","j721e-idk-gw",""
  "LCPD-17523","A72-SPL - Support to dump EEPROM to shared memory","j7200-evm,j721e-evm,j721e-idk-gw",""


|

Linux Known Issues
------------------
.. csv-table::
  :header: "Record ID", "Title", "Platform", "Workaround"
  :widths: 5, 10, 70, 35


  "LCPD-38662","rcu_preempt self-detected stall on CPU","am62axx_sk-fs,am62pxx_sk-fs,am62xx_lp_sk-fs,am62xx_sk-fs,am62xxsip_sk-fs,j721e-idk-gw,j721s2-evm",""
  "LCPD-38659","Update test case for AM69/AM69 and J784S4 AVS","am68_sk-fs,am69_sk-fs",""
  "LCPD-38658","DSI to DP interface tests are failing on AM68","am68_sk-fs",""
  "LCPD-38654","Linux NAND test case failing on J784S4 and J721S2","j721s2-evm,j784s4-evm",""
  "LCPD-38653","Stress test failing in test Farm","j7200-evm",""
  "LCPD-38645","J7200 pinmux register maps are incorrect","j7200-evm,j7200-hsevm",""
  "LCPD-38644","v4l2 compliance failing with try_fmt","am62axx_sk-fs,am62pxx_sk-fs,am68_sk-fs,am69_sk-fs,j721s2-evm,j722s_evm-fs,j784s4-evm,j742s2_evm-fs",""
  "LCPD-38643","SDK 10.00 RC 7 OSPI DFU is broken, if NAND is selected on board ","j784s4-evm",""
  "LCPD-38622","J722S 4 Camera IMX219 GStreamer Pipeline Failure","j722s_evm-fs",""
  "LCPD-38601","Warning in enabling audio clock[J784s4]","j784s4-evm",""
  "LCPD-38558","Unable to gracefully shutdown both cores in R5 Cluster","j7200-evm,j721e-idk-gw,j721s2-evm,j784s4-evm",""
  "LCPD-38528","Documentation: IPC:  Update 6.1.y links to 6.6.y","am62pxx_sk-fs,am62xx_sk-fs,j722s_evm-fs",""
  "LCPD-38498","IPC test are failing ","am68_sk-fs,am69_sk-fs,j7200-evm,j721e-idk-gw,j721s2-evm,j784s4-evm",""
  "LCPD-38497","Graceful Shutdown test failing","am69_sk-fs,j7200-evm,j721e-idk-gw,j721s2-evm,j784s4-evm",""
  "LCPD-38369","J784S4-EVM: AUDIO: PLAYBACK: sample rates 44100 and 88200 are not working on playback","j784s4-evm",""
  "LCPD-38347","VATf: Can transmission reception Testcase failing ","j7200-evm,j721e-idk-gw",""
  "LCPD-38329","CAN tests failing in RCs","j721e-idk-gw,j721s2-evm,j722s_evm-fs,j784s4-evm",""
  "LCPD-38311","Power off test case failing","j7200-evm,j721e-idk-gw,j721s2-evm",""
  "LCPD-38310","optee secure storage test fails ","j722s_evm-fs",""
  "LCPD-38276","MMCSD: DDR50 test failing in  j7 devices ","j7200-evm,j721e-idk-gw,j721s2-evm,j722s_evm-fs,j784s4-evm",""
  "LCPD-38267","J722S: tiboot3.bin / R5 SPL within size limit fails to boot","j722s_evm-fs",""
  "LCPD-38107","USB2.0 Not enabled in SDK","j784s4-evm",""
  "LCPD-38075","Documentation bug - Display section mentions modetest utility app","j722s_evm-fs",""
  "LCPD-38070","Misbehavior of CPSW due to ALE entries overwritten by driver","j721e-hsevm",""
  "LCPD-38055","Remoteproc: Loading secondary R5F firmware from Linux user space fails","j784s4-evm",""
  "LCPD-38041","RCU Torture test results in a crash","j784s4-evm",""
  "LCPD-38021","Update documentation for enabling PCIe EP for Jacinto7 devices","j7200-evm,j721e-evm-ivi,j721s2-evm,j784s4-evm",""
  "LCPD-38001","Doc: Uboot build instructions need to document specific python dependencies for binman","am62axx_sk-fs,am62pxx_sk-fs,am62xx_lp_sk-fs,am62xx_sk-fs,am62xxsip_sk-fs,am64xx-hsevm,j7200-evm,j721e-idk-gw,j721s2-evm,j721s2_evm-fs,j722s_evm-fs,j784s4-evm",""
  "LCPD-37954","[DSS-DP]: REG_WAKEUP_TIME register value can go out of bound","am68_sk-fs,am68_sk-se,am69_sk-fs,j721e-evm-ivi,j721e-hsevm,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j721s2_evm-se,j722s_evm-fs,j784s4-evm,j784s4-hsevm,J784S4_BASESIM",""
  "LCPD-37812","Linux headers in targetfs is not same as in ti-linux-kenel","am62axx_sk-fs,am62axx_sk-se,j721e-evm-ivi,j721e-hsevm,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j721s2_evm-se,j722s_evm-fs,j784s4-evm,j784s4-hsevm",""
  "LCPD-37740","USB DFU mode in spl not working ","j784s4-evm",""
  "LCPD-37727","Testcase for graceful shutdown of remoteprocs","am69_sk-fs,j784s4-evm",""
  "LCPD-37725","SDK 10.00 RC 7 Display test failure","am68_sk-fs,am69_sk-fs,j722s_evm-fs,j784s4-evm",""
  "LCPD-37706","J722S : RTC test failure","j722s_evm-fs",""
  "LCPD-37705","J722S : crypto perf failure ","j722s_evm-fs",""
  "LCPD-37704","J722S : i2c test failing ","j722s_evm-fs",""
  "LCPD-37702","J722S : Crypto perf (ipsec) test failed ","j722s_evm-fs",""
  "LCPD-37699","J722S : SPI tests are not working due to overlay","j722s_evm-fs",""
  "LCPD-37663","SDK: CSI2RX IMX390 sensor test pattern generation is faulty","j721e-idk-gw,j721s2-evm,j722s_evm-fs,j784s4-evm",""
  "LCPD-37624","SK-AM68: Weston fails to start after reducing boot time by setting bootdelay=0 and adding quiet to args_mmc","am68_sk-fs",""
  "LCPD-37605","QSPI Test failing (Boot and detection in Linux)","j721e-idk-gw,j721s2-evm,j784s4-evm",""
  "LCPD-37584","CPSW native IP and MAC functional test failure ","j722s_evm-fs",""
  "LCPD-37528","Setup script fails with bad substitution error when attempting to connect using minicom ","j721e-sk",""
  "LCPD-37507","DSS causes a freeze of processes every 10 seconds for about 200ms","am68_sk-fs,j722s_evm-fs",""
  "LCPD-37464","No J784S4 performance numbers in SDK documentation for CPSW and PCIe","j784s4-evm",""
  "LCPD-37463","We don't have SMMU kernel options related to VFIO should be NOIOMMU set","am64xx-hsevm,j721e-idk-gw",""
  "LCPD-37452","J721e EVM - timeout occurs when connecting PCIe switch with 4 NVMe SSD + another device on different PCIe port","j721e-idk-gw",""
  "LCPD-37415","RGB Encode Color Format Incorrect","j721e-idk-gw",""
  "LCPD-37387","NFS failure leads to stress test failure.","am68_sk-fs,j721s2-evm",""
  "LCPD-37288","J784S4: USXGMII: Add automated test case","j784s4-evm,j784s4-hsevm",""
  "LCPD-37231","USBHOST_S_FUNC_VIDEO_320_240 failing on J7200 CICD","j7200-evm",""
  "LCPD-37199","TPS6594: Error IRQ trap reach ilim, overcurrent for","j721e-idk-gw,j721s2-evm",""
  "LCPD-37015","Add comments about necessity of HPD pin for J721S2 display port","j721s2-evm",""
  "LCPD-36983","[CSIRX] Abrupt stop of a context will cause hang when other contexts are started","j721e-evm-ivi",""
  "LCPD-36952","Add support for J721S2 PG 1.1 in uboot","j721s2-evm",""
  "LCPD-36930","Add tests uart dma","j7200-evm,j721e-idk-gw,j721s2-evm,j784s4-evm",""
  "LCPD-36878","CSIRX does not stream in a particular order","j721e-evm-ivi,j721s2-evm,j784s4-evm",""
  "LCPD-36872","MAC Address changing in AM68A linux boot","am68_sk-fs",""
  "LCPD-36870","PSDK Linux PCIe endpoint test works only if device ID is J721E","j721s2-evm",""
  "LCPD-36863","OPTEE/ATF are not protected by c7x","am68_sk-fs,j7200-hsevm,j721e-hsevm",""
  "LCPD-36841","TDA4VM/J721e: An indirect write completion error occurred in the linux OSPI driver","j721e-evm,j721e-idk-gw",""
  "LCPD-36760","Customer Issue: MHDP compatibility issue","am69_sk-fs,j784s4-evm",""
  "LCPD-36748","M4F clock reported incorrectly with k3conf","am68_sk-fs,am69_sk-fs",""
  "LCPD-36474","J721s2 incorrect autogen generated data","j721s2-evm",""
  "LCPD-36386","IPSEC connection failure on automated setup in testfarm","j721e-idk-gw",""
  "LCPD-35384","After repetative connect/Disconnect EVM is  not getting detected to HOST pc in device mode ","j721s2-evm",""
  "LCPD-35311","Perf data is not getting updated in SDK 9.0 for OSPI","j721s2-evm,j784s4-evm",""
  "LCPD-35087","OSPI Performance benchmark are not at par with SDK 8.6","j7200-evm,j721e-idk-gw,j784s4-evm",""
  "LCPD-35066","CMA Failure with 4K video Files","j721e-idk-gw",""
  "LCPD-35005","h265 file decode infinite loop","j721s2-evm",""
  "LCPD-34988","Weston on DP display on AM68 SKs","am68_sk-fs",""
  "LCPD-34926","Some LTP tests are failing due to missing configurations","am62axx_sk-fs,am62pxx_sk-fs,am62xx_sk-fs,am64xx-hsevm,j7200-evm",""
  "LCPD-34920","Kernel: UBIFS test failing on J721E","j721e-idk-gw",""
  "LCPD-34902","J721E EVM PCIe switch causes kernel panic","j721e-evm-ivi",""
  "LCPD-34895","GPU: PVRCarbon not supported with EGL_LINUX_DMA_BUF_EXT","j721e-evm-ivi,j721e-sk,j721s2-evm,j784s4-evm",""
  "LCPD-34855","PCIe delay time for PERST# signal too short","j721e-hsevm",""
  "LCPD-34826","Crash while running gstreamer app to record camera feed","j721e-sk",""
  "LCPD-34792","UBIFS fails in OSPI NAND boot","am62xx-lp-sk,j721s2-evm",""
  "LCPD-34698","AM69-SK: PCIe enumeration failure","am69_sk-fs",""
  "LCPD-34619","k3conf reports wrong error information while setting the clock frequency","j7200-evm",""
  "LCPD-34587","Functionality Issue - PCI EP with VF ","am68_sk-fs,am69_sk-fs",""
  "LCPD-34579","Functionality Issue - Authentication of firmware images in uboot/SPL","am68_sk-fs,am69_sk-fs",""
  "LCPD-34409","test case naming ""soft boot"" should be ""reboot""","am62axx_sk-fs,am62xx_sk-fs,j721e-idk-gw,j721s2-evm,j721s2_evm-fs",""
  "LCPD-34256","Compute Cluster: A72 Corepac unable to be powered down","j7200-evm",""
  "LCPD-34061","The RGMII MAC is still running after an interface down","j721e-sk",""
  "LCPD-34048","PCIe: AFS bit in PCIE_CORE_RP_I_PCIE_CAP_2 register is not set,","j7200-evm,j721s2-evm,j721s2_evm-fs",""
  "LCPD-32931","OSPI: Update PHY tuning algorithm for PHY Tuning limitations","am62axx_sk-fs,am62axx_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62xx-lp-sk,am62xx-sk,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-hsevm,am64xx-hssk,am64xx_sk-fs,am68_sk-fs,am69_sk-fs,j7200-evm,j7200-hsevm,j721e-hsevm,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j784s4-evm,j784s4-hsevm","Update the OSPI PHY Tuning procedure with the following constraints: | DDR Mode only (SDR to be investigated) | Master Mode only (Bypass mode to be investigated) | Forced Half-Cycle DLL Lock Mode 100MHz - 166MHz only (100MHz is a Master Mode DLL limitation) | Full tuning range of 0-127 should be the default for both RX and TX"
  "LCPD-32923","CICD failure (usb 1-1.1-port3: unable to enumerate USB device)","j7200-evm",""
  "LCPD-32906","OSPI: Read data mismatch(first 32 bytes) when using DMA memcpy","am62axx_sk-fs,am62axx_sk-hs4,am62axx_sk-hs5,am62axx_sk-se,am62xx-lp-sk,am62xx-sk,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62xx_sk-fs,am62xx_sk-hs4,am62xx_sk-hs5,am62xx_sk-se,am64xx-evm,am64xx-hsevm,am64xx-hssk,am64xx_sk-fs,am64xx_sk-hs4,am64xx_sk-hs5,am64xx_sk-se,am654x-evm,am654x-hsevm,am654x-idk,am68_sk-fs,am69_sk-fs,j7200-evm,j7200-hsevm,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j784s4-evm,j784s4-hsevm",""
  "LCPD-32702","J784S4 : USB Client : CDC ECM test failures","j784s4-evm",""
  "LCPD-32701","J7200 : USB Client : Mass storage performance tests failure","j7200-evm",""
  "LCPD-32565","Serror while pcie bus scan","j721e-idk-gw",""
  "LCPD-32564","Failed to set irq type to MSI","j7200-evm",""
  "LCPD-32563","PCIe write test failed","j7200-evm",""
  "LCPD-32544","J7200: OSPI Phy calibration fails intermittently","j7200-evm",""
  "LCPD-32542","Failed to set irq type to MSI-X","j7200-evm",""
  "LCPD-32468","CMA allocation in higher memory (32bit+) fails","j721e-idk-gw,j721s2-evm,j721s2_evm-fs,j784s4-evm",""
  "LCPD-29736","videotestsrc of pattern 0 fails bufferhandling with encoder","j721e-idk-gw",""
  "LCPD-29647","Non-fatal failure logs seen during system boot up","j7200-evm",""
  "LCPD-28861","J721e/j7200: MCU/WKUP UART as console. The output gets garbled after sysfw/dm load ","j7200-evm,j721e-evm",""
  "LCPD-28250","J721S2: QSPI Write corrupted when the first operation after powerup is erase","j721s2-evm,j721s2_evm-fs",""
  "LCPD-28118","RGBA Encode throws timeout error for 720x512 resolution","j721e-idk-gw",""
  "LCPD-25304","J721S2: USB: USB 3.0 devices not getting enumerated in high speed","j721s2-evm,j721s2_evm-fs",""
  "LCPD-25195","j721s2-evm: audio device is not found","j721s2-evm,j721s2_evm-fs",""
  "LCPD-24725","PCIE RC Link fails when linux prints are made quiet","j721e-idk-gw",""
  "LCPD-24686","j721e-idk-gw: Graphics tests fail due to wrong return code","j721e-idk-gw",""
  "LCPD-24648","Move dma-heaps-test and ion-tests to TI repositories","am335x-evm,am572x-idk,am64xx-evm,dra71x-evm,j7200-evm,j721e-evm",""
  "LCPD-24597","j721e-idk-gw PCI_PERF tests report bad numbers (Impact 2)","j721e-idk-gw",""
  "LCPD-24595","j721e-idk-gw USB Suspend/Resume with RTC Wakeup fail (Impact 1)","am64xx-evm,am64xx_sk-fs,j7200-evm,j721e-idk-gw,j721e-sk",""
  "LCPD-24589","no new usb reported on host after g_multi ","am57xx-evm,j721e-idk-gw",""
  "LCPD-24456","Move IPC validation source from github to git.ti.com","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am437x-idk,am437x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am571x-idk,am572x-idk,am574x-hsidk,am574x-idk,am57xx-beagle-x15,am57xx-evm,am57xx-hsevm,am62axx_sk-fs,am62xx-sk,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-hsevm,am64xx_sk-fs,am654x-evm,am654x-hsevm,am654x-idk,bbai,beaglebone,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j7200-evm,j7200-hsevm,j721e-hsevm,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,omapl138-lcdk",""
  "LCPD-22339","PCI-E USBCARD, ETHCARD don't indicate 2-lane support with lspci","j7200-evm,j721e-idk-gw",""
  "LCPD-20653","ltp: kernel syscall tests fail","am335x-evm,am43xx-gpevm,am654x-idk,j721e-idk-gw",""
  "LCPD-19739","AM65 shutdown error","am654x-idk,j7200-evm",""
  "LCPD-19659","Doc: PCIe: Update documentation to indicate how to move to compliance mode","j7200-evm,j7200-hsevm,j721e-evm,j721e-evm-ivi,j721e-hsevm,j721e-idk-gw",""
  "LCPD-19499","Kernel: OSPI write throughput is less than 1MB/s","j7200-evm,j7200-hsevm",""
  "LCPD-19497","J7200: CPSW2g: interface goes up and down sporadically","j7200-evm","Seen only on very few EVMs. No workaround. "
  "LCPD-19084","Few SD cards not enumerating in Kernel with Alpha EVM","j721e-idk-gw",""
  "LCPD-19068","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame","j721e-evm,j721e-evm-ivi,j721e-idk-gw",""
  "LCPD-16640","PCIe RC: GIC ITS misbehaves when more than 4 devices use it simultaneously","j721e-idk-gw",""
  "LCPD-16545","remoteproc/k3-r5f: PDK IPC echo_test image fails to boot up in remoteproc mode on second run","j721e-evm,j721e-evm-ivi,j721e-idk-gw",""
  "LCPD-16535","remoteproc/k3-dsp: PDK IPC echo test binaries fails to do IPC in remoteproc mode on second run","j721e-evm,j721e-evm-ivi,j721e-idk-gw",""
  "LCPD-16531","video decode: vxd_dec warnings displayed at end of gstreamer hevc playback to kmssink for certain video","j721e-idk-gw",""
  "LCPD-16505","Wrong clock rate is reported for 157:400, 157:401 (HSDIVIDER after PLL4 and 15)","j721e-idk-gw",""
  "LCPD-16396","J721E: RC: Unsupported request in configuration completion packets results in an abort","j721e-evm,j721e-evm-ivi,j721e-idk-gw","Workaround for Multifunction: Configure all the physical functions supported by the endpoint. For configuring all the 6 functions of PCIe  controller instance '1' in J721E, the following can be used. mount -t configfs none /sys/kernel/config; cd /sys/kernel/config/pci_ep/; mkdir functions/pci_epf_test/func1; echo 0x104c > functions/pci_epf_test/func1/vendorid; echo 0xb00d > functions/pci_epf_test/func1/deviceid; echo 1 > functions/pci_epf_test/func1/msi_interrupts; echo 16 > functions/pci_epf_test/func1/msix_interrupts; ln -s functions/pci_epf_test/func1 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func2; echo 0x104c > functions/pci_epf_test/func2/vendorid; echo 0xb00d > functions/pci_epf_test/func2/deviceid; echo 1 > functions/pci_epf_test/func2/msi_interrupts; echo 16 > functions/pci_epf_test/func2/msix_interrupts; ln -s functions/pci_epf_test/func2 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func3; echo 0x104c > functions/pci_epf_test/func3/vendorid; echo 0xb00d > functions/pci_epf_test/func3/deviceid; echo 1 > functions/pci_epf_test/func3/msi_interrupts; echo 16 > functions/pci_epf_test/func3/msix_interrupts; ln -s functions/pci_epf_test/func3 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func4; echo 0x104c > functions/pci_epf_test/func4/vendorid; echo 0xb00d > functions/pci_epf_test/func4/deviceid; echo 1 > functions/pci_epf_test/func4/msi_interrupts; echo 16 > functions/pci_epf_test/func4/msix_interrupts; ln -s functions/pci_epf_test/func4 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func5; echo 0x104c > functions/pci_epf_test/func5/vendorid; echo 0xb00d > functions/pci_epf_test/func5/deviceid; echo 1 > functions/pci_epf_test/func5/msi_interrupts; echo 16 > functions/pci_epf_test/func5/msix_interrupts; ln -s functions/pci_epf_test/func5 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func6; echo 0x104c > functions/pci_epf_test/func6/vendorid; echo 0xb00d > functions/pci_epf_test/func6/deviceid; echo 1 > functions/pci_epf_test/func6/msi_interrupts; echo 16 > functions/pci_epf_test/func6/msix_interrupts; ln -s functions/pci_epf_test/func6 controllers/d800000.pcie-ep/; echo 1 > controllers/d800000.pcie-ep/start; echo 1 > /sys/bus/pci/devices/0000:00:00.0/remove; echo 1 > /sys/bus/pci/rescan; Workaround for switch card: No workarounds available."
  "LCPD-9981","Some LTP's memory management tests fail due to low amount of free memory","j721e-vlab,omapl138-lcdk",""

|

Linux RT Kernel Known Issues
----------------------------

There are no known issues in this release in the Linux RT Kernel.

|

Issues closed in system firmware in this release
-------------------------------------------------

System firmware Known Issues
------------------------------

Change Requests
===============

SDK features descoped from 10.00 release
----------------------------------------
.. csv-table::
  :header: "ID", "Head Line", "Platform", "Original Fix Version", "New Fix Version"
  :widths: 20, 90, 90, 20, 20

  JACINTOREQ-7514 ,Linux SDK shall support MSMC: Security Firewall, "J784S4", 10.00.00 ,10.01.00
  JACINTOREQ-5042 ,Linux SDK shall support cpufreq [opp] DFS, "J784S4, J721E, J721S2, J7200, J722S", 10.00.00 ,Dropped
  JACINTOREQ-4121 ,Support to boot MCU R5 1_1 in split mode, "J784S4, J721E, J721S2, J7200", 10.00.00 ,10.01.00

SDK features descoped from 9.2 release
--------------------------------------
.. csv-table::
  :header: "ID", "Head Line", "Platform", "Original Fix Version", "New Fix Version"
  :widths: 20, 90, 90, 20, 20

  JACINTOREQ-3970 ,Linux SDK shall support MSMC: Security Firewall, "J784S4", 09.02.00 ,10.00.00
  JACINTOREQ-5042 ,AM69/J784S4 Linux SDK shall support cpufreq [opp], "AM69, J784S4", 09.02.00 ,10.00.00

SDK features scoped in 9.1 release
----------------------------------
.. csv-table::
  :header: "ID", "Head Line", "Platform", "Original Fix Version", "New Fix Version"
  :widths: 20, 90, 90, 20, 20

   JACINTOREQ-3761 ,Linux SDK shall support RTI: Watchdog support J721S2, "J721S2", 09.02.00 ,09.01.00
   JACINTOREQ-3981 ,Linux SDK shall support RTI: Watchdog support J784S4, "J784S4", 09.02.00 ,09.01.00

SDK features descoped from 9.1 release
--------------------------------------
.. csv-table::
  :header: "ID", "Head Line", "Platform", "Original Fix Version", "New Fix Version"
  :widths: 20, 90, 90, 20, 20

  JACINTOREQ-3970 ,Linux SDK shall support MSMC: Security Firewall, "J784S4", 09.01.00 ,09.02.00
  JACINTOREQ-3920 ,"Linux SDK shall support SA2UL: HMAC using MD5, SHA1, SHA2-224, SHA2-256 and SHA2-512", "J784S4", 09.01.00 ,09.02.00

SDK features descoped from 9.0 release
--------------------------------------
.. csv-table::
  :header: "ID", "Head Line", "Platform", "Original Fix Version", "New Fix Version"
  :widths: 20, 90, 90, 20, 20

   JACINTOREQ-3598 ,Jacinto Device firewalling support, "J7200, J721e, J721s2, J784s4", 09.00.00 ,09.01.00

SDK features descoped from 8.6 release
--------------------------------------
.. csv-table::
  :header: "ID", "Head Line", "Platform", "Original Fix Version", "New Fix Version"
  :widths: 20, 90, 90, 20, 20

   JACINTOREQ-5338 ,Jacinto PSDK 8.6 AEP/AHP industrial APL pull-in impact, "J721e, J7200, J721S2 , J784S4", 08.06.00 ,09.00.00


SDK features descoped from 8.5 release
--------------------------------------
.. csv-table::
  :header: "ID", "Head Line", "Platform", "Original Fix Version", "New Fix Version"
  :widths: 20, 90, 90, 20, 20

   JACINTOREQ-5060, Jacinto networking requirements - CR to 8.6, "J721S2, J784S4", 08.05.00, 08.06.00
   JACINTOREQ-4991, "Jacinto Baseport, Graphics, Multimedia CR to 8.6", "J721S2, J784S4", 08.05.00, 08.06.00
   JACINTOREQ-4934, CSI Capture Automated Testing for J7AEP, J721S2, 08.05.00, 08.06.00
   JACINTOREQ-4928, J7AEP Multimedia Scope Modify, J721S2, 08.05.00, 08.06.00
   JACINTOREQ-5001, Configurable Buffering Descope, J784S4, 08.05.00, None
   JACINTOREQ-4993, Descope GLBenchmark, J784S4, 08.05.00, None
   JACINTOREQ-4927, J7AHP Graphics Scope Modify, J784S4, 08.05.00, 08.06.00

SDK features scope change for 8.5 release
-----------------------------------------
.. csv-table::
   :header: "ID", "Head Line", "Platform"
   :widths: 40, 60, 60

   JACINTOREQ-4994 , Video Codec Memory Optimization Scope Change, J721e

SDK features descoped from 8.4 release
--------------------------------------
.. csv-table::
   :header: "ID", "Head Line", "Platform", "Original Fix Version", "New Fix Version"
   :widths: 20, 90, 90, 20, 20

   JACINTOREQ-4930 ,k3conf Doc and Test Modify, J721e, 08.04.00 ,08.05.00
   JACINTOREQ-4905 ,J7AEP Graphics Scope Modify, J721s2, 08.04.00 ,08.05.00/08.06.00
   JACINTOREQ-4898 ,SERDES: PCIe + USB schedule update, J721s2, 08.04.00 ,08.05.00
   JACINTOREQ-4864 ,4k Resolution Scope change, J721s2, 08.04.00 ,08.05.00
   JACINTOREQ-4854 ,McASP Scope Change, J721s2, 08.04.00 ,08.05.00
   JACINTOREQ-4930 ,k3conf Doc and Test Modify, J721s2, 08.04.00 ,08.05.00

SDK features descoped from 8.0 release
--------------------------------------
.. csv-table::
   :header: "ID", "Head Line", "Platform", "Original Fix Version", "New Fix Version"
   :widths: 20, 90, 90, 20, 20

    JACINTOREQ-1559 ,Linux H264 decoder support, J721e, 08.00.00 ,08.01.00
    JACINTOREQ-1485 ,Linux writeback pipeline support , J721e, 08.00.00 ,None
    JACINTOREQ-1444 ,Vision apps inclusion in yocto build  , J721e, 08.00.00 ,None


SDK features present in 7.0 that were descoped in 7.1
-----------------------------------------------------
.. csv-table::
   :header: "Feature", "Comments", "Platform"
   :widths: 40, 60, 60

    HS support,Restored in 7.3, J721e
    SPL/Uboot boot modes restricted to SD card boot mode,Restored in 7.3, J721e
    1s Linux boot, , "J721e"
    Descope for support of native H264 encode/decode,Use R5F based driver with OpenVX as interface.  H.264 decoder support restored in 7.3, J721e
    GPU compression, , J712e
    SA2UL driver optimization, , J721e
    Display Sharing,Display sharing demo available in SDK v6.1, J721e
    Virtualization (Jailhouse hypervisor/IPC virtualization/CPSW9G virtualization),Does not affect 3P virtualization solutions. Basic Jailhouse demo can be seen in SDK 7.0, J721e


Installation and Usage
======================

The :ref:`Software Developer's Guide <linux-index>` provides instructions on how to setup your Linux development environment, install the SDK and start your development. It also includes User's Guides for various Example Applications.

|

Host Support
============

For the specific supported hosts for current SDK, see :ref:`this page <how-to-build-a-ubuntu-linux-host-under-vmware>`.

.. note::
   Processor SDK Installer is 64-bit, and installs only on 64-bit host machine.

.. |reg| unicode:: U+00AE .. REGISTERED SIGN
