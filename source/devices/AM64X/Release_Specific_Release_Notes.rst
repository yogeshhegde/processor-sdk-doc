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

-  Linux Manifest:  "/docs/software_manifest.htm"


Release 08.00.00
================

Released on August 2021

.. rubric:: What's New
   :name: whats-new

Processor SDK Linux AM64x Release has following new features:

- First release on 2021 LTS 5.10 kernel, 2021.01 U-Boot
- Support for DFU boot in SPL bootloader
- Support for ICSS-G Dual EMAC/PRUETH
- Support for ECAP, MCAN, ePWM, SA2UL, WDT drivers
- Unified DDR driver for AM64
- ATF 2.5, OPTEE 3.12
- WiFi out of box demo for AM64x SK
- Matrix GUI LED demo for AM64 EVM and SK
- Yocto build support for all the demo components including benchmark demo
- Toplevel Makefile in the installer for building BSP components

Build Information
=====================================

U-Boot
-------------------------

| Head Commit: 53e79d0e89f975eeb874366dd9a92f68b3a599d1 defconfigs: am65x_hs_evm: Sync HS and non-HS defconfigs
| Repo: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: 08.00.00.004
|

Kernel
-------------------------
.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 4c2eade9f722838b0e457650368cba1c6c7483c2 Merged TI feature rpmsg into ti-linux-5.10.y
| Repo: https://git.ti.com/cgit/ti-u-boot/ti-u-boot/
| Branch: ti-linux-5.10.y
| Kernel defconfig: ti_sdk_arm64_release_defconfig
|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 0701a5b58c943909a38be9df38a3b4bdd8234340 Merged TI feature ti_linux_base_rt into ti-rt-linux-5.10.y
| Repo: https://git.ti.com/cgit/ti-linux-kernel/ti-linux-kernel/
| Branch: ti-rt-linux-5.10.y
| Kernel defconfig: ti_sdk_arm64_rt_release_defconfig
|

Yocto
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 15f3d4a3c3773294f1cdb66a88744930941a892e ti-rtos-firmware: Add soft link to the rtos firmware binaries
| Repo: https://git.ti.com/cgit/arago-project/meta-ti/
| Branch: dunfell
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: ae47bd7fbea2776a4f8792f20c493d7959ee2f54 iproute2: upgrade to 5.10
| Repo: https://git.ti.com/cgit/arago-project/meta-arago/
| Branch: dunfell
|

.. rubric:: meta-processor-sdk
   :name: meta-processor-sdk

| Head Commit: ea2e8505fdf9948c0e2881af9dacb07e801c9037 recipes-ti: ti-tisdk-makefile: Remove evse-hmi snippet
| Repo: https://git.ti.com/cgit/processor-sdk/meta-processor-sdk/
| Branch: dunfell
|


Issues Tracker
=====================================

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 100

   "LCPD-21538","am64xx-evm PCI-EP MSI tests are failing","am64xx-evm"
   "LCPD-21516","WIC file generated does not include tiboot3.bin","am64xx-evm"
   "LCPD-21510","USB devices attached to am64xx-evm are not enumerated","am64xx-evm"
   "LCPD-21509","AM64x Core Benchmarks degrades on some runs","am64xx-evm"
   "LCPD-20721","AM64-sk: Memtester failures","am64xx-sk"
   "LCPD-20626","am64x-sk: mmc list command does not return anything","am64xx-sk"
   "LCPD-20163","am64xx fails to boot when using the mmcmode custom build","am64xx-evm"
   "LCPD-20162","Degraded performance when running IET tests over eth1","am64xx-evm"
   "LCPD-20130","am64xx PCIe-EP test failing due to a NULL pointer exception","am64xx-evm"
   "LCPD-20106","USBDEVICE ping from DUT to host fails when packet_count=470","am64xx-evm,j7200-evm"

|


Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-22854","am64xx crypto tests fail due to tcrypt","am64xx-evm,am64xx-sk"
   "LCPD-22842","am64xx ethernet CPSW3g tests faile due to queue 0 not increasing","am64xx-evm"
   "LCPD-22514","Broken USB MSC boot on AM642-EVM","am64xx-evm"
   "LCPD-22488","AM64 inconsistent promiscuous mode visibility","am64xx-evm,j721e-idk-gw,j7200-evm"
   "LCPD-22358","U-Boot: am642/am654/j72xx: ethernet address fixup is broken","am64xx-evm,am654x-evm,j721e-evm,j7200-evm"
   "LCPD-22281","U-Boot hangs with 'LPDDR4_StartTest: FAIL' error when starting on am64xx-evm","am64xx-evm"
   "LCPD-22240","2021.00 uboot on am64xx-evm - dhcp does not work","am64xx-evm"
   "LCPD-22048","U-Boot: J7/AM64: DDR driver size is bloated up","am64xx-evm,j721e-idk-gw"

|


SDK Known Issues
-----------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-20038","am64xx-evm","OPTEE test applications are missing from rootfs",""

|


U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-23026","am64xx-evm","USB MSC Boot: USB controller not visible from u-boot",""
   "LCPD-23024","am64xx-evm","PSDK-DOC: UBoot: USB host boot info is out of date",""
   "LCPD-23020","am64xx-evm","am64xx-evm: U-Boot PHY autonegotiation failed 2 out of 100 times",""
   "LCPD-22841","am64xx-evm,j721e-idk-gw,j7200-evm","j7200 Watchdog Timer test is failing",""
   "LCPD-21962","am64xx-evm","U-Boot documentation discrepancies",""
   "LCPD-20131","am64xx-evm,j721e-idk-gw,j7200-evm","Uboot fails to enumerate devices attached to a usb hub on the first 'usb reset' call ","Re-run usb reset command "

|


Linux Kernel Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround" 
   :widths: 5, 10, 70, 35

   "LCPD-22931","am64xx-evm,am64xx-sk,am654x-evm,am654x-idk,dra72x-evm","RemoteProc documentation missing",""
   "LCPD-22920","am64xx-evm","AM64x Linux IPC documentation is insufficient / out-of-date",""
   "LCPD-22913","am64xx-evm,j721e-idk-gw,j7200-evm","USBDEV ACM NCM enumeration fails on the device side",""
   "LCPD-22912","am64xx-evm","am64xx-evm SMP dual core test fails sporadically",""
   "LCPD-22892","am64xx-evm,am654x-evm,am654x-idk","icssg: due to FW bug both interfaces has to be loaded always",""
   "LCPD-22852","am64xx-evm","AM64x: ICSSG ping with 16384 size shows high packet loss",""
   "LCPD-22834","am64xx-evm","am64xx-evm stress boot test files",""
   "LCPD-22789","am64xx-evm","cdns-usb3: g_mass_storage and g_ether fails on some boards",""
   "LCPD-22534","am64xx-evm,am654x-evm,j721e-idk-gw,j7200-evm","Ipsec aes128 TCP test failure",""
   "LCPD-22319","am64xx-evm,j7200-evm","OpenSSL performance test data out of bounds",""
   "LCPD-22215","am64xx-evm","PCIE NVM card stops enumerating on am64xx after some time",""
   "LCPD-20705","am64xx-evm","USB stick attached to PCIe USB card is not enumerated",""
   "LCPD-20558","am64xx-sk","OSPI UBIFS tests failing on am64xx-sk",""
   "LCPD-20105","am64xx-evm","AM64x: Kernel: ADC: RX DMA channel request fails",""
   "LCPD-20061","am64xx-evm","Occasional PHY error during during TSN Time-Aware Shaper execution",""
   "LCPD-20006","am64xx-evm","AM64x: remoteproc may be stuck in the start phase after a few times of stop/start",""
   "LCPD-18854","am64xx-evm,dra71x-evm,dra76x-evm","ov5640 sensor capture fails for raw format capture",""

|