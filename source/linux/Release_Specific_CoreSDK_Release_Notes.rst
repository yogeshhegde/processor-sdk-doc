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

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
  :header: "Record ID", "Platform", "Title"
  :widths: 15, 30, 150

  "LCPD-27887","am62xxsip_sk-fs, am62xxsip_sk-se,am62xx-sk,am62xx_sk-fs","i2327: RTC: Hardware wakeup event limitation"
  "LCPD-27886","am62xxsip_sk-fs, am62xxsip_sk-se,am62axx_sk-fs,am62xx-sk,am64xx-evm,j721e-idk-gw,j7200-evm,j784s4-evm,j784s4-hsevm","USART: Erroneous clear/trigger of timeout interrupt"


|

U-Boot Known Issues
------------------------
.. csv-table::
  :header: "Record ID", "Platform", "Title", "Workaround"
  :widths: 15, 30, 70, 30

  "LCPD-36618","am62xxsip_sk-fs, am62xxsip_sk-se","AM62SIP: reserving fdt memory region failed error seen at bootup",""
  "LCPD-29874","am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se","am62x: robustness: fails to boot 100 reboot test consistently",""

|

Linux Known Issues
---------------------------
.. csv-table::
  :header: "Record ID", "Platform", "Title", "Workaround"
  :widths: 5, 10, 70, 35

  "LCPD-36812","am62xx_sk-fs, am62xx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se","RTC: tests fail"
  "LCPD-36805","am62xx_sk-fs, am62xx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se","ETHERNET boot test fail incorrect configuration",""
  "LCPD-36804","am654x-evm, am654x-idk, am654x-hsevm, am64xx-evm, am64xx-hsevm, am64xx-hssk, am62xx_sk-fs, am62xx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se, am335x-evm, am335x-hsevm, am335x-ice, am335x-sk, am43xx-gpevm, am43xx-hsevm, am437x-idk, am437x-sk, am64xx_sk-fs, am64xx_evm-se, am64xx_sk-se","IPC performance test fail - modprobe fails",""
  "LCPD-36803","am62xx_sk-fs, am62xx_sk-se, am62xx_lp_sk-fs, am62xx_lp_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se","USBDEV: test case fail - USB devices not enumerated",""
  "LCPD-36801","am62xx_sk-fs, am62xx_sk-se, am62xx_lp_sk-fs, am62xx_lp_sk-se, am62axx_sk-fs, am62axx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se, am62pxx_sk-fs, am62pxx_sk-se","USB-DFU boot test fail incorrect configuration",""
  "LCPD-36653","am62xx_sk-fs, am62xx_sk-se, beagleplay-gp, am62xx_lp_sk-fs, am62xx_lp_sk-se, am62axx_sk-fs, am62axx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se",modprobe -r dwc3-am62 fails",""
  "LCPD-34242","am62xx_sk-fs, am62xxsip_sk-fs, am62xxsip_sk-se, am62xx-sk, am68_sk-fs, am69_sk-fs, j721s2-evm, j7200-evm, j784s4-evm","GPIO_S_FUNC_DIR_IN_ALL_BANK unit test fails",""
  "LCPD-29876","am62xx_sk-fs, am62xx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se, am62xx-sk","am62x: crypto RNG functional and performance tests failures",""
  "LCPD-29874","am62xx_sk-fs, am62xx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se, am62xx-sk",am62x: robustness: fails to boot 100 reboot test consistently",""
  "LCPD-29445","am62xx_sk-fs, am62xx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se, am62xx-sk",am62xx-sk: MCAN loop-back test is failing",""
  "LCPD-28104","am62xx_sk-fs, am62xx_sk-se, am62xxsip_sk-fs, am62xxsip_sk-se, am62xx-sk",Automated test failure - CPSW test is passing invalid parameters to switch-config",""
  "LCPD-34397","am62xxsip_sk-fs, am62xxsip_sk-se, am62xx-sk","usb xhci locks up after multiple Linux reboot",""


|


