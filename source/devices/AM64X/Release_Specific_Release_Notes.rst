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

To simplify the end user experience, Processor SDK Linux AM64x installer provides, everything needed to create the embedded 
system from “scratch”, with...

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


Release 08.01.00
================

Released on January 2022

.. rubric:: What's New
   :name: whats-new

What's new
----------
Processor SDK Linux AM64x Release has following new features:

- Second release on 2021 LTS 5.10 kernel, 2021.01 U-Boot
- Linux kernel driver support for NAND
- Linux remoteproc driver support for loading M4F core
- Support PRU IPC with Linux
- Support for booting HS-FS devices
- Authentication of boot binaries like SPL, Uboot and kernel
- Add support for ICSSG Ethernet MII mode in Linux driver
- Service to Print IP address of the board on AM64 EVM


Build Information
=====================================

U-Boot
-------------------------
.. rubric:: u-boot
   :name: u-boot

| Head Commit: 15769936a559b1840f50b83f94ee0c636b245001 configs: am64x: Add FIT ARGS for HS images
| Date: Tue Dec 14 08:15:08 CST 2021
| uBoot Version: 2021.01
| uBoot Description: 08.01.00.006
| Clone: https://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: 08.01.00.006
| uBoot Tag: 08.01.00.006

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))

Kernel
-------------------------
.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: dcc6bedb2c2bdb509709e4ae08303206e95ce6c2 Merged TI feature connectivity into ti-linux-5.10.y
| Date: Wed Dec 15 08:06:10 CST 2021
| Kernel Version: 5.10.65
| Kernel Description: 08.01.00.006

| Clone: https://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.10.y
| Tag: 08.01.00.006
| Kernel defconfig: ti_sdk_arm64_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 541ec9a6995c3dd881d6f0b63cc714a08ded457d Merged TI feature ti_linux_base_rt into ti-rt-linux-5.10.y
| Date: Tue Dec 14 09:43:46 CST 2021
| Kernel Version: 5.10.65
| RT Kernel Version: 5.10.65-rt53
| Kernel Description: 08.01.00.006-rt

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.10.y
| Tag: 08.01.00.006-rt
| Kernel defconfig: ti_sdk_arm64_rt_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))

Yocto
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 15613c951051c450fc8726b2576c23c105b79d53 linux-ti-staging: block sa2ul for am64x hs and j7200 hs device
| Date: 2021-12-10
| Version: dunfell-3.1

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: 08.01.00.006

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: e13e698213f5c4e2617ace97dca2d0ccf84ab0af Update the ltp-ddt to latest
| Date: 2021-12-03
| Version: 2021.09

| Clone: git://git.yoctoproject.org/git/meta-arago.git
| Branch: dunfell
| Release Tag: 08.01.00.006
|


Issues Tracker
=====================================

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 100

   "LCPD-22979","firmware links are missing in /lib/firmware directory for K3","am64xx-evm,am64xx-sk,am654x-evm,j721e-idk-gw,j7200-evm"
   "LCPD-22941","ptp clock register breaks 5.14-rc1 kernel bootup","am64xx-evm,am654x-evm,j721e-evm,j7200-evm"
   "LCPD-22920","AM64x Linux IPC documentation is insufficient / out-of-date","am64xx-evm"
   "LCPD-22913","USBDEV ACM NCM enumeration fails on the device side ","am64xx-evm,am654x-idk,j721e-idk-gw,j7200-evm"
   "LCPD-22852","AM64x: ICSSG ping with 16384 size shows high packet loss","am64xx-evm"
   "LCPD-22823","Convert eeprom-93xx46.txt:    ""microchip,93lc46b"" to yaml","am335x-evm,am437x-idk,am572x-idk,am64xx-evm"
   "LCPD-22822","Convert inside-secure,safexcel-eip76 (omap_rng.txt) to yaml","am335x-evm,am437x-idk,am572x-idk"
   "LCPD-22789","cdns-usb3: g_mass_storage and g_ether fails on some boards","am64xx-evm"
   "LCPD-22514","Broken USB MSC boot on AM642-EVM","am64xx-evm"
   "LCPD-22338","ipc_echo_test test on am64xx-evm fails due to a firmware file name change","am64xx-evm"
   "LCPD-21962","U-Boot documentation discrepancies","am64xx-evm"
   "LCPD-21538","am64xx-evm PCI-EP MSI tests are failing","am64xx-evm"
   "LCPD-21347","k3: cpswxg: switchdev: crash in am65_cpsw_port_offload_fwd_mark_update() when there is a disabled port","am64xx-evm,am64xx-sk"
   "LCPD-20131","Uboot fails to enumerate devices attached to a usb hub on the first 'usb reset' call ","am64xx-evm,j721e-idk-gw,j7200-evm"

|

Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-24625","am64 - Boot modes: eMMC alternative boot mode","am64xx-evm"
   "LCPD-24624","am64 Boot modes: OSPI","am64xx-evm"
   "LCPD-24623","am64 DFU boot failure","am64xx-evm"
   "LCPD-24600","Interrupt count wrong due to missing channel for crypto test","am64xx-evm,j7200-evm"
   "LCPD-24501","Flashing Linux wic image to SD card does not boots Linux","am64xx-evm,am64xx-sk,am654x-idk,am654x-hsevm,j721e-evm,j721e-hsevm,j721e-idk-gw,j7200-evm,j7200-hsevm"
   "LCPD-24493","j7200-evm PCI_L_PERF_USBHOST_VFAT performance outside 10 stdev ","j7200-evm"
   "LCPD-24492","am64xx-evm Multiple NAND device failures","am64xx-evm"
   "LCPD-24471","USBDEV_highspeed_multi_enumerate","am64xx-evm"
   "LCPD-24435","ETH-CPSW2G_XS_FUNC_SPEED_1000Mbps_ALL","am64xx-evm"
   "LCPD-24434","PCIe Wifi ping tests","am64xx-evm,j7200-evm"
   "LCPD-24431","DFU: SPL-DFU boot support","am64xx-evm"
   "LCPD-24294","TSN CPSW EST feature, counter not synchronized to ptp clock","am64xx-evm,am64xx-sk"
   "LCPD-24293","ICSS based Ethernet performance vs CPSW (AM64x)","am64xx-evm"
   "LCPD-24219","AM64: ICSSG: No RX packets after link down<and>up","am64xx-evm"
   "LCPD-24212","Update the locations of various elements in SRAM","am64xx-evm"
   "LCPD-24117","U-Boot user's guide does not have documentation on how to boot from USB mass storage","am64xx-evm"
   "LCPD-24114","AM64x: MCAN documentation is missing","am64xx-evm"
   "LCPD-23095","AM64: Add U-Boot,dm-spl tag in MMC1 pinmux dt node","am64xx-evm"
   "LCPD-23024","PSDK-DOC: UBoot: USB host boot info is out of date","am64xx-evm"

|

Known Issues
------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround" 
   :widths: 5, 10, 70, 35

   "LCPD-20038","am64xx-evm","OPTEE test applications are missing from rootfs",""
   "LCPD-24507","am64xx-evm,am64xx-hsevm,am64xx-sk","U-Boot command ""saveenv"" doesn't save env ",""
   "LCPD-23026","am64xx-evm","USB MSC Boot: USB controller not visible from u-boot",""
   "LCPD-23020","am64xx-evm","am64xx-evm: U-Boot PHY autonegotiation failed 2 out of 100 times",""
   "LCPD-22841","am64xx-evm,j721e-idk-gw,j7200-evm","Watchdog Timer test is failing ",""
   "LCPD-24627","am64xx-evm","icssg_prueth: NULL pointer deference during remove",""
   "LCPD-24622","am64xx-evm","TCP Bidir",""
   "LCPD-24620","am64xx-evm","ETH-USB-LCD-ALSA-NAND-MMC-0001 Suspend/Resume with RTC Wakeup",""
   "LCPD-24593","am64xx-evm","am64xx-evm CAN_S_FUNC_MODULAR test failures",""
   "LCPD-24473","am64xx-evm","IPSEC_software_crypto_UDP_aes128_sha1_performance",""
   "LCPD-24451","am64xx-evm","CRYPTO_S_PERF_MD5",""
   "LCPD-24433","am64xx-evm","ETH-USB-LCD-ALSA-NAND-MMC-0001 Suspend/Resume with RTC Wakeup",""
   "LCPD-24289","am64xx-evm,am64xx-sk,am654x-evm,am654x-idk","ICSSG Ethernet Docs Broken link to ICSS Eth docs",""
   "LCPD-24121","am64xx-evm,am64xx-sk","IPC SDK docs: link to example source code",""
   "LCPD-22931","am64xx-evm,am64xx-sk,am654x-evm,am654x-idk,dra72x-evm","RemoteProc documentation missing",""
   "LCPD-22912","am64xx-evm","am64xx-evm SMP dual core test fails sporadically",""
   "LCPD-22892","am64xx-evm,am654x-evm,am654x-idk","icssg: due to FW bug both interfaces has to be loaded always",""
   "LCPD-22834","am64xx-evm","am64xx-evm stress boot test fails",""
   "LCPD-22319","am64xx-evm,j7200-evm","OpenSSL performance test data out of bounds",""
   "LCPD-22215","am64xx-evm","PCIE NVM card stops enumerating on am64xx after some time",""
   "LCPD-20705","am64xx-evm","USB stick attached to PCIe USB card is not enumerated",""
   "LCPD-20105","am64xx-evm","AM64x: Kernel: ADC: RX DMA channel request fails",""
   "LCPD-20061","am64xx-evm","Occasional PHY error during during TSN Time-Aware Shaper execution",""
   "LCPD-20006","am64xx-evm","AM64x: remoteproc may be stuck in the start phase after a few times of stop/start",""
   "LCPD-18854","am64xx-evm,dra71x-evm,dra76x-evm","ov5640 sensor capture fails for raw format capture",""
   "LCPD-24288","am64xx-evm,am654x-idk","am64xx-evm NCM/ACM network performance test crashes with RT images",""

|
