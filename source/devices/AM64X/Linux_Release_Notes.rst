*******************
Linux Release Notes
*******************

Overview
========

The **Processor SDK for Linux**
provides a fundamental software platform for development, deployment and
execution of Linux based applications and includes the following:

-  Bootloaders & Filesystems
-  Prebuilt Binaries
-  Detailed Release Notes

Licensing
=========

Please refer to the software manifest, which outlines the licensing
status for all packages included in the prebuilt binaries location.

Release 07.03.01
==================

Released May 2021

.. rubric:: What's New

Processor SDK 7.3.1 Release has following new features:

- Final release on 2020 LTS 5.4 kernel
- AM64 U-Boot support single SPL image for both EVM and SK.
- AM64 filesystem support to enable wifi access point on startup.

Build Information
=================

.. _release-specific-build-information-u-boot:

U-Boot
------

| Head Commit: e995ed0ec11baf3912470f8b7c8d33dd65f2d6da  configs: am64x_sk: Drop unused defconfigs
| Date: Wed May 12 15:48:40 2021 +0530
| uBoot Version: 2020.01
| uBoot Description: 07.03.01.006

| Clone: https://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2020.01

| Compiler Information:  arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025

|

.. _release-specific-build-information-kernel:

Kernel
------

.. rubric:: Linux Kernel

| Head Commit: 023faefa70274929bff92dc41167b007f7523792 Merged TI feature connectivity into ti-linux-5.4.y
| Date: Wed Apr 7 14:38:29 CDT 2021
| Kernel Version: 5.4.106
| Kernel Description: 07.03.00.005
| Repo: https://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.4.y
| Tag: 07.03.00.005

| Compiler Information: arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025

|

.. rubric:: Real Time (RT) Linux Kernel

| Head Commit: 519667b0d81d74a6e55105dcd6072ae550352599 Merged TI feature ti_linux_base_rt into ti-rt-linux-5.4.y
| Date: Wed Apr 7 21:12:27 CDT 2021
| Kernel Version: 5.4.106
| RT Kernel Version: 5.4.106-rt54
| Kernel Description: 07.03.00.005-rt

| Repo: https://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.4.y
| Tag: 07.03.00.005-rt

| Compiler Information:  arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025

|

Yocto
-----

.. rubric:: meta-ti

| Head Commit: 52ffccb09385ef3a369770b2fa45bc09418a5050
| ti-rtos: Update metadata and versions for RTOS firmware
| Date: 2021-4-05
| Version: dunfell-3.1

| Clone: https://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: 07.03.00.005

.. rubric:: meta-arago

| Head Commit: ee6ff44d90945429051c8d9573c8b60705104149
| omapconf: Bump to v1.75 release
| Date: 2021-4-01
| Version: 2020.05

| Clone: https://arago-project.org/git/meta-arago.git
| Branch: dunfell
| Release Tag: 07.03.00.005
|

Issues Tracker
==============

Issues opened in previous releases that were closed on this release
-------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Title"
   :widths: 15, 100

   "LCPD-20163","am64xx fails to boot when using the mmcmode custom build"
   "LCPD-20130","am64xx PCIe-EP test failing due to a NULL pointer exception"
   "LCPD-20122","Add external power supply to PCIe USB card on am64xx and j7200"
   "LCPD-20120","U-Boot user's guide does not mention AM64x"
   "LCPD-20119","Kernel user's guide does not mention ARM64 or AM64x"
   "LCPD-20111","TSN IET (Frame Preemption) iperf3 network is unreachable with VLAN"
   "LCPD-20107","USBDEVICE Bi-directional iperf test fails on am64xx when running from dut to server"
   "LCPD-20023","AM64x DDR4 startup instability seen due to driver clock configuration"
   "LCPD-20004","AM64: g_ether module failing to bringup link on host side"

|


Issues found and closed on this release that may be applicable to prior releases
--------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title"
   :widths: 15, 100

   "LCPD-22282","U-Boot: reset to default env fails in 2021 LTS"
   "LCPD-22281","U-Boot hangs with 'LPDDR4_StartTest: FAIL' error when starting on am64xx-evm"
   "LCPD-22048","U-Boot: J7/AM64: DDR driver size is bloated up"
   "LCPD-21510","USB devices attached to am64xx-evm are not enumerated"
   "LCPD-21348","K3: CPSWxG: can't disable rate limit for TX CPPI channels on Host P0"
   "LCPD-21346","k3: cpswxg: switchdev: crash in am65_cpsw_port_offload_fwd_mark_update() when there is a disabled port"
   "LCPD-21341","am64: cut-thru auto speed detection not working properly"
   "LCPD-20626","am64x-sk: mmc list command does not return anything"
   "LCPD-20618","k3: cpswxg: bindings not updated"
   "LCPD-20553","PCI: EP: PCIe EP Not Testable - Add device ID for AM64 in pci_endpoint_test"
   "LCPD-20323","AM64x: USB option_cv not being programmed"
   "LCPD-20306","Occasional AM64x EVM u-boot hangs seen after new CONFIG options enabled"
   "LCPD-20242","U-Boot: reset command fails on AM64x EVM"

|

Linux Kernel Known Issues
-------------------------
.. csv-table::
   :header: "Record ID", "Title", "Workaround"
   :widths: 15, 80, 15

   "LCPD-22338","ipc_echo_test test on am64xx-evm fails due to a firmware file name change",""
   "LCPD-22095","omap-spi.txt  convert to yaml",""
   "LCPD-22094","omap_serial.txt  convert to yaml",""
   "LCPD-22093","pwm-tiehrpwm.txt convert to yaml",""
   "LCPD-22092","pwm-tiecap.txt convert to yaml",""
   "LCPD-22091","ti,phy-am654-serdes.txt convert to yaml",""
   "LCPD-22090","pci-keystone.txt convert to yaml",""
   "LCPD-22089","ti,am654-hbmc.txt convert to yaml",""
   "LCPD-22087","ti-tsc-adc.txt convert to yaml",""
   "LCPD-22086","i2c-omap.txt convert to yaml",""
   "LCPD-21538","am64xx-evm PCI-EP MSI tests are failing",""
   "LCPD-21507","am64xx and j7200 PCIe USB card must use an external power supply to enumerate the attached USB stick",""
   "LCPD-21347","k3: cpswxg: switchdev: crash in am65_cpsw_port_offload_fwd_mark_update() when there is a disabled port",""
   "LCPD-21334","Convert ti,j721e-gpio to yaml",""
   "LCPD-20721","AM64-sk: Memtester failures",""
   "LCPD-20716","video capture on am64xx-sk not working with a USB3 camera",""
   "LCPD-20558","OSPI UBIFS tests failing on am64xx-sk",""
   "LCPD-20385","AM64: Upstream: Set USB PHY core voltage to 0.85",""
   "LCPD-20162","Degraded performance when running IET tests over eth1",""
   "LCPD-20131","Uboot fails to enumerate devices attached to a usb hub on the first 'usb reset' call ","Re-run usb reset command "
   "LCPD-20105","AM64x: Kernel: ADC: RX DMA channel request fails",""
   "LCPD-20061","Occasional PHY error during during TSN Time-Aware Shaper execution",""
   "LCPD-20055","Assign am64xx GPIO test pins in ltp-ddt",""
   "LCPD-20038","OPTEE test applications are missing from rootfs",""
   "LCPD-20006","AM64x: remoteproc may be stuck in the start phase after a few times of stop/start",""
   "LCPD-19858","OE: OPTEE label used in SDK is old and wrong",""
   "LCPD-19838","Cryptodev not building against 5.10 kernel",""
