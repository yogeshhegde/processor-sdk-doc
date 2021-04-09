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

Release 07.03.00
==================

Released April 2021

.. rubric:: What's New

Processor SDK 7.3 Release has following new features:

- Final release on 2020 LTS 5.4 kernel
- AM64 Kernel Support for MMC SDR104 and DDR50 and eMMC HS200 speed modes
- AM64 TSN Switch Support

Build Information
=================

.. _release-specific-build-information-u-boot:

U-Boot
------

| Head Commit: 2781231a33c3d779e32445f4fe55164c45d6d7c1 arm: mach-k3: j721e_init: probe clock node after sci node is probed
| Date: Wed Apr 7 21:12:38 CDT 2021
| uBoot Version: 2020.01
| uBoot Description: 07.03.00.005

| Clone: https://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: 07.03.00.005
| uBoot Tag: 07.03.00.005

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

   "LCPD-20122","Add external power supply to PCIe USB card on am64xx and j7200"
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

   "LCPD-21346","k3: cpswxg: switchdev: crash in am65_cpsw_port_offload_fwd_mark_update() when there is a disabled port"
   "LCPD-21341","am64: cut-thru auto speed detection not working properly"
   "LCPD-20618","k3: cpswxg: bindings not updated"
   "LCPD-20323","AM64x: USB option_cv not being programmed"
   "LCPD-20306","Occasional AM64x EVM u-boot hangs seen after new CONFIG options enabled"
   "LCPD-20242","U-Boot: reset command fails on AM64x EVM"

|

Linux Kernel Known Issues
-------------------------
.. csv-table::
   :header: "Record ID", "Title", "Workaround"
   :widths: 15, 70, 15

   "LCPD-21538","am64xx-evm PCI-EP MSI tests are failing",""
   "LCPD-21511","ADC tests fail due to elements missing in /sys/bus path",""
   "LCPD-21510","USB devices attached to am64xx-evm are not enumerated",""
   "LCPD-21507","am64xx and j7200 PCIe USB card must use an external power supply to enumerate the attached USB stick",""
   "LCPD-20705","USB stick attached to PCIe USB card is not enumerated",""
   "LCPD-20164","TSN IET (Frame Preemption) eth0 link sometimes does not come back up after configuring",""
   "LCPD-20162","Degraded performance when running IET tests over eth1",""
   "LCPD-20106","USBDEVICE ping from DUT to host fails when packet_count=470",""
   "LCPD-20105","AM64x: Kernel: ADC: RX DMA channel request fails",""
   "LCPD-20061","Occasional PHY error during during TSN Time-Aware Shaper execution",""
   "LCPD-20055","Assign am64xx GPIO test pins in ltp-ddt",""
   "LCPD-20006","AM64x: remoteproc may be stuck in the start phase after a few times of stop/start",""
