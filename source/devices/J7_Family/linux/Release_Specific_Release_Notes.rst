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
===============
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
=====================================
See :ref:`here <release-specific-supported-platforms-and-versions>` for a list of supported platforms and links to more information.


Release 09.01.00
==================

Released Nov 2023

.. rubric:: What's New
   :name: whats-new

Processor SDK 9.1 Release supports the following platforms:

  * J721E
  * J7200
  * J721S2
  * J784S4
  * AM68
  * AM69

Processor SDK 9.1 Release has following new features:

  * This is the Second release in the 2023 LTS stream 6.1 kernel, 2023.04 U-Boot and Yocto Kirkstone/4.0
  * ATF 2.9
  * OPTEE 4.0.0
  * Yocto Kirkstone/4.0
  * Firewalling support added

Build Information
=====================================

.. _u-boot-release-notes:

U-Boot
-------------------------
| Head Commit: b0d868ee086eb5c96a3d32f72a7cb9670abf5b90 arm: dts: k3-am62p: sync with linux again
| Date: Fri Nov 3 04:46:23 2023 +0000
| uBoot Version: 2023.04
| uBoot Description: 09.01.00.003
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2023.04
| uBoot Tag: 09.01.00.003

| Compiler Information: arm-oe-eabi-gcc (GCC) 11.4.0, aarch64-oe-linux-gcc (GCC) 11.4.0
|

.. rubric:: Note:
| meta-tisdk Yocto layer contains additional patches for U-Boot `here <https://git.ti.com/cgit/ti-sdk-linux/meta-tisdk/tree/recipes-bsp/u-boot?h=09.01.00.05>`__.
|

Kernel
-------------------------
.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 7d494fe58c8e5d41a6bd886c9a628a7fff5763f9 arm64: dts: ti: k3-am62p-main: SRAM allocation for VPU
| Date: Mon Oct 30 12:33:39 2023 -0500
| Kernel Version: 6.1.46
| Kernel Description: 09.01.00.003

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-6.1.y
| Tag: 09.01.00.003
| Kernel defconfig: defconfig + ti_arm64_prune.config

| Compiler Information: aarch64-oe-linux-gcc (GCC) 11.4.0, GNU ld (GNU Binutils) 2.38.20220708
|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 	eda9974e8513cdd2c5cc20c3c6b851f9977acd4d Merge branch 'ti-linux-6.1.y-cicd' into ti-rt-linux-6.1.y-cicd
| Date: Thu Nov 02 18:16:06 2023 -0500
| Kernel Version: 6.1.46
| Kernel Description: 09.01.00.003-rt

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-6.1.y
| Tag: 09.01.00.003-rt
| Kernel defconfig: defconfig + ti_rt.config + ti_arm64_prune.config

| Compiler Information: aarch64-oe-linux-gcc (GCC) 11.4.0, GNU ld (GNU Binutils) 2.38.20220708

.. rubric:: Note:
| meta-tisdk Yocto layer contains additional patches for Linux Kernel `here <https://git.ti.com/cgit/ti-sdk-linux/meta-tisdk/tree/recipes-kernel/linux?h=09.01.00.05>`__.
|


Yocto
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 7e404bcf2235b1fcf192269c8d8a25ad02de54c1 linux-ti-staging_6.1: CI/CD Auto-Merger: cicd.kirkstone.202311022105
| Date: 2023-11-02

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: kirkstone
| Release Tag: 09.01.00.003
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: 5fe0223b22e91011d39452464d3a2c6f368789cc ltp-ddt: CI/CD Auto-Merger: cicd.kirkstone.202311022105
| Date: 2023-11-02

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: kirkstone
| Release Tag: 09.01.00.003
|

.. rubric:: meta-tisdk

| Head Commit: a799cbacc2760216bf889939d677f129370791ac ti-apps-launcher: Update SRCREV to pull in GUI updates
| Date: 2023-11-27

| Clone: git://git.ti.com/ti-sdk-linux/meta-tisdk.git
| Branch: kirkstone
| Release Tag: 09.01.00.05
|

Issues Tracker
=====================================

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------
.. csv-table::
  :header: "Record ID", "Title", "Platform"
  :widths: 15, 70, 20

  "LCPD-35085","Docs: Incorrect boot image formats in AHP SDK doc","j784s4-evm"
  "LCPD-35072","DSI is not working due to wrong clock","am68_sk-fs,j721s2-evm,j784s4-evm"
  "LCPD-34982","j721s2: Enable ospi nand 8D mode in uboot","j721s2-evm"
  "LCPD-34935","Reset Performance data for mmc","j721s2-evm,j784s4-evm"
  "LCPD-34933","BootApp fails to boot linux kernel","j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"
  "LCPD-34925","MCSPI: J784S4/J721S2/J7200 RC7 failures","j721e-hsevm,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"
  "LCPD-34907","J721S2/J784S4/AM68/AM69: Display: DSI always comes as connected even when the connector is not plugged","am68_sk-fs,am69_sk-fs,j721s2-evm,j784s4-evm"
  "LCPD-34904","Watchdog reset is not working in J721E and J7200","j721e-idk-gw,j7200-evm"
  "LCPD-34890","uboot mmc sd and emmc performance tests failing","am69_sk-fs,j784s4-evm"
  "LCPD-34884","J784s4/J721S2 OSPI_S_FUNC_ Failure CICD","j721s2-evm,j784s4-evm"
  "LCPD-34825","img_enc errors while running gstreamer app using encoder","j721e-sk"
  "LCPD-34756","HDMI_S_FUNC_PLAYBACK_1920x1080 failing om AM68","am68_sk-fs"
  "LCPD-34711","u-boot dhcp caused data abort failure","am69_sk-fs"
  "LCPD-34689","CICD failure 	Uboot emmc raw read write performance","j721s2-evm,j784s4-evm"
  "LCPD-34679","DRU registers are inaccessible on mcu2_0 after uboot boots up","j721e-idk-gw"
  "LCPD-34519","IPC: IPC_S_FUNC_RPMSG_SAMPLE_CLIENT test failures","am62axx_sk-fs,am62xx-sk,am68_sk-fs,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"
  "LCPD-34516","USBHOST Audio ltp unit test fails","am62xx_sk-fs,am62xx-sk,j721s2-evm,j7200-evm,j784s4-evm"
  "LCPD-34413","RT Linux: Interrupt latency issue with >200us outliers","am654x-evm,am654x-hsevm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-sk,am64xx_sk-fs,j721e-sk,j721s2-evm,j721s2_evm-fs,j7200-evm,j784s4-evm"
  "LCPD-34237","U-boot: j7200-sk: Get rid of pinmux and duplication from sk-r5.dts","j7200-evm"
  "LCPD-34236","U-boot: j721e-sk: Get rid of pinmux and duplication from sk-r5.dts","j721e-sk"
  "LCPD-34235","U-boot: j721e-evm: Get rid of pinmux and duplication from sk-r5.dts","j721e-idk-gw"
  "LCPD-34234","U-boot: j721s2-evm: Get rid of pinmux from sk-r5.dts","j721s2-evm,j721s2_evm-fs"
  "LCPD-34233","U-boot: AM68-SK: Get rid of pinmux from sk-r5.dts","am68_sk-fs"
  "LCPD-32935","J7: Issue with MCSPI clocking in Linux driver","j721e-idk-gw"
  "LCPD-32921","CICD failure [UART overrun causes test failure]","j7200-evm"
  "LCPD-32895","AM69-SK: Lower throughput in MMCSD performance testing","am69_sk-fs"
  "LCPD-32894","AM69-SK: USB enumeration fails in u-boot","am69_sk-fs"
  "LCPD-32817","while flashing emmc using dfu still it expecting sysfw.itb though it uses combined boot flow","j721s2-evm,j721s2_evm-fs"
  "LCPD-32756","Upstream:  Jacinto: Convert docs to RST in U-Boot","j721e-idk-gw,j721s2-evm,j721s2_evm-fs,j7200-evm,j784s4-evm"
  "LCPD-32656","AM69-SK: PCIe0 enumeration fails","am69_sk-fs,j784s4-evm,j784s4-hsevm"
  "LCPD-32539","J721S2: Linux crash when we cat pinctrl debugfs node","j721s2-evm,j721s2-hsevm,j721s2_evm-fs"
  "LCPD-29880","CAN_S_FUNC_MODULAR test fail","am64xx-evm,j721s2-evm,j7200-evm,j784s4-evm"
  "LCPD-29755","j721e-idk-gw : Can Transmission and Reception Tests Fail","j721e-idk-gw"
  "LCPD-29680","vxe_enc_probe warning observed while booting with debug options enabled","j721e-evm,j721e-evm-ivi,j721e-idk-gw,j7200-evm"
  "LCPD-28474","libthread_db and libpthread version mismatch does not allow GDB debug of multi-thread","j721e-sk"
  "LCPD-26692","Hardware + Software IPSec Performance Test Failures","am64xx-evm,am335x-evm,am43xx-gpevm,am57xx-evm,j721e-idk-gw"
  "LCPD-25692","linux needs to identify J7ES PG1.1 correctly","j721s2-evm,j721s2-hsevm,j721s2_evm-fs"
  "LCPD-25322","Docs: J7200: Improve the IPC chapter for ti-rpmsg-char","j7200-evm"
  "LCPD-25321","Docs: J721E: Improve the IPC chapter for ti-rpmsg-char","j721e-evm,j721e-evm-ivi,j721e-idk-gw"
  "LCPD-24649","dma-heaps-test fails to build with 5.16-rc3 kernel+","am64xx-evm,am335x-evm,dra71x-evm,j721e-idk-gw"
  "LCPD-22513","Update SDK doc to include OSPI flashing instruction using dfu-util","j721e-evm,j7200-evm"
  "LCPD-22512","Update dfu_alt_info_ospi to include flashing of PHY tuning data","j721e-evm,j7200-evm"
  "LCPD-22319","OpenSSL performance test data out of bounds","am64xx-evm,am62axx_sk-fs,am62xx-sk,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"
  "LCPD-19948","Yocto: stream recipe is incorrect","am57xx-evm,j721e-evm,j721e-idk-gw"
  "LCPD-19894","UYVY texture test fails due to internal data stream error","j721e-idk-gw,j721s2-evm,j721s2_evm-fs,j784s4-evm"
  "LCPD-17814","Kingston 16G card could not boot to uboot prompt","j721e-idk-gw"

|

Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
  :header: "Record ID", "Title", "Platform"
  :widths: 15, 70, 20

  "LCPD-35028","J7200 perf data is equal to 8.6 but test mark as pass due to old data","j7200-evm"
  "LCPD-34966","rpmsg_ctrl device mapping errors see with 6.1 kernel","am62axx_sk-fs,am62xx-lp-sk,am62xx-sk,am62xx_sk-fs,am64xx-evm,am64xx-sk,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721s2-evm,j784s4-evm"
  "LCPD-34963","RPi camera does not work with AM68A","am68_sk-fs"
  "LCPD-34928","LTP-DDT: DISPLAY: 09.00 test failing due to weston not being killed","j721e-idk-gw,j721s2-evm,j784s4-evm"
  "LCPD-34923","u-boot: ospi: j721e: OSPI boot failure including DFU","j721e-idk-gw"
  "LCPD-34919","OSPI Performance benchmark are not at par with SDK 8.6","j721e-idk-gw,j7200-evm"
  "LCPD-34909","USBHOST Audio ltp unit test fails","am69_sk-fs"
  "LCPD-34908","J721S2: 09.00.00.003: Display: all test cases are failing","j721s2-evm"
  "LCPD-34889","Test to update emmc using dfu fails","j784s4-evm"
  "LCPD-34852","Few times payload is packed at size boundary by binman ","am62xx_sk-se,am64xx-evm,am654x-evm,j721e-idk-gw,j721s2-evm,j7200-evm"
  "LCPD-34848","Rproc init fails on some boots","j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721s2-evm,j784s4-evm"
  "LCPD-34839","eMMC raw boot failure ","j7200-evm"
  "LCPD-34794","AM68-SK does not have mhdp but its node is there in dts","am68_sk-fs"
  "LCPD-34692","U-Boot Debug Tips: Section 3.1.2.1 broken link leading to U-boot User's Guide","j721e-idk-gw,j721e-sk,j721s2-evm,j784s4-evm"
  "LCPD-34678","GCC ToolChain: Typo in export path foot note ","j721e-idk-gw"
  "LCPD-34673","display: j784s4,j721s2,j721e: display tests are failing as pykms module is missing in kirkstone builds (python 3.10)","j721e-idk-gw,j721s2-evm,j784s4-evm"
  "LCPD-34669","J7200 [Regression reboot test failing TPS] ","j7200-evm"
  "LCPD-34668","CMA buffer size is fixed to 32MB in tiL6.1. Multimedia needs significantly more than that. Add DT node to increase the size.","j721e-idk-gw,j721e-sk,j721s2-evm,j784s4-evm"
  "LCPD-34667","J721E: Audio: 09.00.00.001: tests are failing due to missing configs","j721e-idk-gw"
  "LCPD-34661","j721e: R5Fs configured in lockstep mode instead of split mode ","j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721e-vlab"
  "LCPD-34660","CONFIG_DRM_TI_TFP410 Not enabled in ti-linux-6.1","j721e-sk"
  "LCPD-34649","Wave521CL encoder kernel panic issue","j721s2-evm"
  "LCPD-34646","TDA4VM: Status of standalone tests tienc_encode and tidec_decode","j721e-idk-gw"
  "LCPD-34645","TDA4VH: gstreamer rtp stream cannot be played","j721s2-evm"
  "LCPD-34592","DISTRO BOOT: Not enabled on all Jacinto Platforms","j721s2-evm,j721s2-hsevm,j7200-evm,j784s4-evm,j784s4-hsevm"
  "LCPD-34584","j721s2: hs boot test failure","j721s2-evm,j721s2_evm-fs"
  "LCPD-34544","J784s4: OPTEE: Missing documentation to set the UART instance","j784s4-evm"
  "LCPD-34534","j7200: OSPI_S_PERF_RAW_READ test fails","j7200-evm"
  "LCPD-34533","Random failure [j7200: ETH : CPSW2G : functional test failure of ETH_CPSW2g_Unicast]","j7200-evm"
  "LCPD-34527","j721e: CI/CD boot failure with PMIC node","j721e-idk-gw,j7200-evm"
  "LCPD-34519","IPC: IPC_S_FUNC_RPMSG_SAMPLE_CLIENT test failures","am62axx_sk-fs,am62xx-sk,am68_sk-fs,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"
  "LCPD-34368","SDK: J721S2: MAIN CPSW2G RGMII Clock Frequency is incorrect","j721s2-evm,j721s2-hsevm,j721s2_evm-fs"
  "LCPD-34302","TDA4VH: Memory leak in encoder driver/GStreamer","j784s4-evm"
  "LCPD-34300","J721E Multimedia documentation improvements","j721e-idk-gw,j721s2-evm,j721s2_evm-fs,j784s4-evm"
  "LCPD-34292","j784s4: OSPI failures with Rx DMA not available","j784s4-evm"
  "LCPD-34213","CI/CD failure (OSPI read performance fails sometimes) ","j7200-evm"
  "LCPD-34201","Wrong Mapping of tifs-sram@1f0000 in k3-j721s2-main.dtsi","j721s2-evm,j721s2_evm-fs,j784s4-evm"
  "LCPD-34190","The last CPSW port enumerated does not untag inner VLAN tag in header","j7200-evm,j784s4-evm"
  "LCPD-34127","Serdes4 Lane definitions are missing","j784s4-evm"
  "LCPD-34126","AHP stability test (Kernel boot 1000 times)","j784s4-evm"
  "LCPD-34092","Add developer notes section in Linux SDK documentation to point users to k3conf","j721e-hsevm"
  "LCPD-34091","U-Boot: Add missing documentation about Adaptive Voltage Scaling(AVS)","j721s2-evm,j721s2_evm-fs"
  "LCPD-32971","CICD failure ( j784s4-evm Application exited with non-zero value.)","j784s4-evm"
  "LCPD-32929","CI/CD failure (J721e,VENC warning while using DMA)","j721e-hsevm"
  "LCPD-32928","CICD failure (Could not find an active interface implemented by cpsw2g to run test, VCL)","j7200-evm"
  "LCPD-32927","CICD (Second UART timeout while boot, VCL)","j7200-evm"
  "LCPD-32925","CICD [Eth performance test on VCL)","j7200-evm"
  "LCPD-32922","CI/CD failure (Kernel panic in CPSW SW stack)","j784s4-evm"
  "LCPD-32919","CICD failure PCIe Serror on n/w and NVME // was remote proc failed due to nw is not available ","j7200-evm,j784s4-evm"
  "LCPD-32899","CI/CD failure report [eMMC performance out of bound]","j721s2-evm,j721s2_evm-fs,j7200-evm,j784s4-evm"
  "LCPD-32853","j721s2: xSPI/QSPI boot fails when trying to read 4 bytes data from NOR flash in SPL","j721s2-evm,j721s2_evm-fs"
  "LCPD-32835","./setup.sh fails due to missing PLATFORM=j7200-evm in Rules.make","j7200-evm"

|

Errata Workarounds Available in this Release
------------------------------------------------
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
------------------------
.. csv-table::
  :header: "Record ID", "Title", "Platform", "Workaround"
  :widths: 15, 30, 70, 30

  "LCPD-36745","u-boot: spl: spl_image_info has no member named fdt_addr","j721e-idk-gw,j7200-evm",""
  "LCPD-36491","ti-u-boot: J784S4: Update ITAP values in device tree","j784s4-evm,j784s4-hsevm",""
  "LCPD-36488","ti-u-boot: J721S2: Update ITAP values in device tree","j721e-hsevm,j721e-idk-gw,j721e-sk",""
  "LCPD-36483","ti-u-boot: J721E: Update TAP Delay values in device tree","j721e-hsevm,j721e-idk-gw,j721e-sk",""
  "LCPD-36478","ti-u-boot: J7200: Update ITAP values in device tree","j7200-evm,j7200-hsevm",""
  "LCPD-34106","SPL: USB DFU Boot fails on J721S2 EVM on upstream U-Boot(also ti-u-boot-2023.04)","j721s2-evm,j721s2_evm-fs",""
  "LCPD-24108","U-Boot: TISCI config ring fail traces seen in OSPI boot mode on J721E","j721e-evm,j721e-evm-ivi,j721e-idk-gw",""
  "LCPD-22904","U-boot: Update EMIFtool for i2244:DDR: Valid stop value must be defined for write DQ VREF training","j721e-idk-gw,j7200-evm",""
  "LCPD-17789","UBOOT J7:  Could not see UFS device by scsi scan","j721e-idk-gw",""
  "LCPD-17523","A72-SPL - Support to dump EEPROM to shared memory","j721e-evm,j721e-idk-gw,j7200-evm",""

|

Linux Known Issues
---------------------------
.. csv-table::
  :header: "Record ID", "Title", "Platform", "Workaround"
  :widths: 5, 10, 70, 35

  "LCPD-36952","Add support for J721S2 PG 1.1 in uboot","j721s2-evm",""
  "LCPD-36930","Add tests uart dma","j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm",""
  "LCPD-36885","j7200: TSN TAS Test Failure","j7200-evm",""
  "LCPD-36863","OPTEE/ATF are not protected by c7x","am68_sk-fs,j721e-hsevm,j7200-hsevm",""
  "LCPD-36848","J721E: Occasional SPI-NOR write timeout under high load","am62xx_sk-fs,j721e-idk-gw",""
  "LCPD-36847","doc: ltp-ddt documentation is not upto date","am64xx-hsevm,am62xx_sk-fs,am62axx_sk-fs,am62pxx_sk-fs,am68_sk-fs,am69_sk-fs,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm",""
  "LCPD-36841","TDA4VM/J721e: An indirect write completion error occurred in the linux OSPI driver","j721e-evm,j721e-idk-gw",""
  "LCPD-36794","j7200-evm: eth firmware floods network with dhcp packets  ","j7200-evm",""
  "LCPD-36760","Customer Issue: MHDP compatibility issue","am69_sk-fs,j784s4-evm",""
  "LCPD-36748","M4F clock reported incorrectly with k3conf","am68_sk-fs,am69_sk-fs",""
  "LCPD-36744","Linux SDK: CPSW: Bridge interface cannot ping in Switch Mode","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am64xx_sk-fs,am64xx_evm-se,am64xx_sk-se,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm,j784s4-evm,j784s4-hsevm",""
  "LCPD-36609","j7200: UART DMA fails immediately without Flow control enabled","j7200-evm",""
  "LCPD-36494","Migrate to OPTEE 4.0.0 to address PSIRT","am62xx_sk-fs,am62axx_sk-fs,am64xx_sk-fs,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm",""
  "LCPD-36489","ti-linux: J784S4: Update ITAP values in device tree","j784s4-evm,j784s4-hsevm",""
  "LCPD-36485","ti-linux: J721S2: Update ITAP values in device tree","j721s2-evm,j721s2-hsevm",""
  "LCPD-36476","ti-linux: j7200: Update ITAP values in device tree","j7200-evm,j7200-hsevm",""
  "LCPD-36474","J721s2 incorrect autogen generated data","j721s2-evm",""
  "LCPD-36472","USB Audio Device not Found","j7200-evm",""
  "LCPD-36386","IPSEC connection failure on automated setup in testfarm","j721e-idk-gw",""
  "LCPD-35400","wkup i2c0 is not enabled on j721e-sk","j721e-sk",""
  "LCPD-35353","ti-rpmsg-char instability observed when using SafeRTOS firmware with multiple endpoints","j721e-idk-gw",""
  "LCPD-35340","Modify Uart Testcase","j721s2-evm,j784s4-evm",""
  "LCPD-35311","Perf data is not getting updated in SDK 9.0 for OSPI","j721s2-evm,j784s4-evm",""
  "LCPD-35097","OSPI Boot failing on AM69","am69_sk-fs",""
  "LCPD-35096","OPTEE Runtime security Support : Secure Storage","am68_sk-fs",""
  "LCPD-35094","IPsec benchmark failing in SDK 9.0 RC7","j721e-idk-gw",""
  "LCPD-35093","Verify failing display mode in Rc7","am68_sk-fs,am69_sk-fs,j721e-idk-gw,j721s2-evm,j784s4-evm",""
  "LCPD-35092","Over all test infra/script update for CSI testing","am68_sk-fs,am69_sk-fs,j721e-idk-gw,j721s2-evm,j784s4-evm",""
  "LCPD-35087","OSPI Performance benchmark are not at par with SDK 8.6","j721e-idk-gw,j7200-evm",""
  "LCPD-35069","DFU boot fails on test farm but works locally ok","j721e-idk-gw,j784s4-evm",""
  "LCPD-35029","IPC test case script update ","am68_sk-fs,am69_sk-fs,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j7200-evm,j784s4-evm,j784s4-hsevm",""
  "LCPD-35027","J7 Power off is not working","j721e-idk-gw,j721s2-evm,j7200-evm",""
  "LCPD-35010","CICD test on AM68 and AM69 are running from SD card . ","am68_sk-fs,am69_sk-fs",""
  "LCPD-34988","Weston on DP display on AM68 SKs","am68_sk-fs",""
  "LCPD-34920","Kernel: UBIFS test failing on J721E","j721e-idk-gw",""
  "LCPD-34801","A72 SPL is not present in deploy directory","j721e-hsevm,j721e-idk-gw,j721s2-evm,j721s2-hsevm,j7200-evm,j7200-hsevm,j784s4-evm,j784s4-hsevm",""
  "LCPD-34792","UBIFS fails in OSPI NAND boot","am62xx-lp-sk,j721s2-evm",""
  "LCPD-34590","AM69x: CICD next failures of unit tests across components","am69_sk-fs",""
  "LCPD-34589","AM68x: CICD next failures of unit tests across components","am68_sk-fs",""
  "LCPD-34242","GPIO_S_FUNC_DIR_IN_ALL_BANK unit test fails","am62xx_sk-fs,am62xxsip_sk-fs,am62xxsip_sk-se,am62xx-sk,am68_sk-fs,am69_sk-fs,j721s2-evm,j7200-evm,j784s4-evm",""
  "LCPD-34048","PCIe: AFS bit in PCIE_CORE_RP_I_PCIE_CAP_2 register is not set,","j721s2-evm,j721s2_evm-fs,j7200-evm",""
  "LCPD-29521","R5 remote proc load does'nt guarentee CPU0 vs CPU1 sequencing","j721e-evm,j784s4-evm",""
  "LCPD-28861","J721e/j7200: MCU/WKUP UART as console. The output gets garbled after sysfw/dm load ","j721e-evm,j7200-evm",""
  "LCPD-28250","J7AEP: QSPI Write corrupted when the first operation after powerup is erase","j721s2-evm,j721s2_evm-fs",""
  "LCPD-25304","J7AEP: USB: USB 3.0 devices not getting enumerated in high speed","j721s2-evm,j721s2_evm-fs",""
  "LCPD-25262","j721s2-evm : cpuhotplug06 fails  ","j721s2-evm,j721s2_evm-fs",""
  "LCPD-25195","j721s2-evm: audio device is not found","j721s2-evm,j721s2_evm-fs",""
  "LCPD-24725","PCIE RC Link fails when linux prints are made quiet","j721e-idk-gw",""
  "LCPD-24595","j721e-idk-gw USB Suspend/Resume with RTC Wakeup fail (Impact 1)","am64xx-evm,am64xx_sk-fs,j721e-idk-gw,j721e-sk,j7200-evm",""
  "LCPD-24589","no new usb reported on host after g_multi ","am335x-evm,am57xx-evm,j721e-idk-gw",""
  "LCPD-24502","j721e-evm-ivi Universal Planes fails (Impact 1)","j721e-evm-ivi,j721e-idk-gw",""
  "LCPD-24456","Move IPC validation source from github to git.ti.com","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am62xx-sk,am64xx_sk-fs,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j721e-hsevm,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j7200-evm,j7200-hsevm,omapl138-lcdk",""
  "LCPD-24198","J721e-sk stress boot test fails","j721e-sk",""
  "LCPD-22715","i2232: DDR: Controller postpones more than allowed refreshes after frequency change","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,j721e-idk-gw,j721s2-evm,j721s2_evm-fs,j7200-evm","Workaround 1:
  Disable dynamic frequency change by programing DFS_ENABLE = 0


  Workaround 2:
    If switching frequency, program the register field values as follows:

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
  "LCPD-22339","PCI-E USBCARD, ETHCARD don't indicate 2-lane support with lspci","j721e-idk-gw,j7200-evm",""
  "LCPD-20653","ltp: kernel syscall tests fail","am654x-idk,am335x-evm,am43xx-gpevm,j721e-idk-gw",""
  "LCPD-19739","AM65 shutdown error","am654x-idk,j7200-evm",""
  "LCPD-19659","Doc: PCIe: Update documentation to indicate how to move to compliance mode","j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm",""
  "LCPD-19499","Kernel: OSPI write throughput is less than 1MB/s","j7200-evm,j7200-hsevm",""
  "LCPD-19497","J7200: CPSW2g: interface goes up and down sporadically","j7200-evm","Seen only on very few EVMs. No workaround. "
  "LCPD-19084","Few SD cards not enumerating in Kernel with Alpha EVM","j721e-idk-gw",""
  "LCPD-19068","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame","j721e-evm,j721e-evm-ivi,j721e-idk-gw",""
  "LCPD-18790","eMMC tests failed on J7 rev E2 EVM","j721e-idk-gw",""
  "LCPD-17543","Some cpuhotplug tests failed","j721e-evm,j721e-evm-ivi,j721e-idk-gw",""
  "LCPD-17421","CPSW9G: Can't bring up interface over NFS","j721e-idk-gw",""
  "LCPD-17284","remoteproc/k3-r5: Cores are started out-of-order when core 0 file size >> core 1 file size","j721e-evm,j721e-evm-ivi,j721e-idk-gw",""
  "LCPD-17172","Uboot USBhost: Sandisk Extreme USB 3.0 msc stick could not be detected at second time","j721e-idk-gw",""
  "LCPD-17171","Uboot dhcp occasionally failed","j721e-idk-gw",""
  "LCPD-17017","J7: DSS underflows seen on various use cases","j721e-evm-ivi,j721e-idk-gw",""
  "LCPD-16640","PCIe RC: GIC ITS misbehaves when more than 4 devices use it simultaneously","j721e-idk-gw",""
  "LCPD-16545","remoteproc/k3-r5f: PDK IPC echo_test image fails to boot up in remoteproc mode on second run","j721e-evm,j721e-evm-ivi,j721e-idk-gw",""
  "LCPD-16535","remoteproc/k3-dsp: PDK IPC echo test binaries fails to do IPC in remoteproc mode on second run","j721e-evm,j721e-evm-ivi,j721e-idk-gw",""
  "LCPD-16505","Wrong clock rate is reported for 157:400, 157:401 (HSDIVIDER after PLL4 and 15)","j721e-idk-gw",""
  "LCPD-16396","J721E: RC: Unsupported request in configuration completion packets results in an abort","j721e-evm,j721e-evm-ivi,j721e-idk-gw","Workaround for Multifunction: Configure all the physical functions supported by the endpoint. For configuring all the 6 functions of PCIe  controller instance '1' in J721E, the following can be used. mount -t configfs none /sys/kernel/config; cd /sys/kernel/config/pci_ep/; mkdir functions/pci_epf_test/func1; echo 0x104c > functions/pci_epf_test/func1/vendorid; echo 0xb00d > functions/pci_epf_test/func1/deviceid; echo 1 > functions/pci_epf_test/func1/msi_interrupts; echo 16 > functions/pci_epf_test/func1/msix_interrupts; ln -s functions/pci_epf_test/func1 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func2; echo 0x104c > functions/pci_epf_test/func2/vendorid; echo 0xb00d > functions/pci_epf_test/func2/deviceid; echo 1 > functions/pci_epf_test/func2/msi_interrupts; echo 16 > functions/pci_epf_test/func2/msix_interrupts; ln -s functions/pci_epf_test/func2 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func3; echo 0x104c > functions/pci_epf_test/func3/vendorid; echo 0xb00d > functions/pci_epf_test/func3/deviceid; echo 1 > functions/pci_epf_test/func3/msi_interrupts; echo 16 > functions/pci_epf_test/func3/msix_interrupts; ln -s functions/pci_epf_test/func3 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func4; echo 0x104c > functions/pci_epf_test/func4/vendorid; echo 0xb00d > functions/pci_epf_test/func4/deviceid; echo 1 > functions/pci_epf_test/func4/msi_interrupts; echo 16 > functions/pci_epf_test/func4/msix_interrupts; ln -s functions/pci_epf_test/func4 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func5; echo 0x104c > functions/pci_epf_test/func5/vendorid; echo 0xb00d > functions/pci_epf_test/func5/deviceid; echo 1 > functions/pci_epf_test/func5/msi_interrupts; echo 16 > functions/pci_epf_test/func5/msix_interrupts; ln -s functions/pci_epf_test/func5 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func6; echo 0x104c > functions/pci_epf_test/func6/vendorid; echo 0xb00d > functions/pci_epf_test/func6/deviceid; echo 1 > functions/pci_epf_test/func6/msi_interrupts; echo 16 > functions/pci_epf_test/func6/msix_interrupts; ln -s functions/pci_epf_test/func6 controllers/d800000.pcie-ep/; echo 1 > controllers/d800000.pcie-ep/start; echo 1 > /sys/bus/pci/devices/0000:00:00.0/remove; echo 1 > /sys/bus/pci/rescan; Workaround for switch card: No workarounds available."
  "LCPD-15708","J721E: vlab: MMC1 not functional","j721e-vlab",""
  "LCPD-14249","PCI kernel oops seen between rc7 and rc8 of 4.19","j721e-vlab",""
  "LCPD-9981","Some LTP's memory management tests fail due to low amount of free memory","j721e-vlab,omapl138-lcdk",""

|

Linux RT Kernel Known Issues
----------------------------

There are no known issues in this release in the Linux RT Kernel.

Change Requests
===============

SDK features scoped in 9.1 release
--------------------------------------
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
