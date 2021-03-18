*******************
Linux Release Notes
*******************

Overview
========

The **Processor SDK Linux**
provides a fundamental software platform for development, deployment and
execution of Linux based applications and includes the following:

-  Bootloaders & Filesystems
-  Prebuilt Binaries
-  Detailed Release Notes

Build Information
=================

.. _release-specific-build-information-u-boot:

U-Boot
------

| Head Commit: 84b608fd3489c8dd93d8eb20e7f005d967b88402 arm: | dts: k3-am65: Add tag to disable UHS modes in SR 1.0
| Date: Thu Jan 21 08:28:10 CST 2021
| uBoot Version: 2020.01
| uBoot Description: 07.02.00.004

| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: 07.02.00.004
| uBoot Tag: 07.02.00.004

|

.. _release-specific-build-information-kernel:

Kernel
------

.. rubric:: Linux Kernel

| Head Commit: 60de748aca87c99a32f726a6abf1b6472f297ae3 Merged TI feature connectivity into ti-linux-5.4.y
| Date: Thu Jan 21 08:37:49 CST 2021
| Kernel Version: 5.4.87
| Kernel Description: 07.02.00.004

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.4.y
| Tag: 07.02.00.004
| Kernel defconfig: multi_v7_defconfig

| Compiler Information: arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025

|

.. rubric:: Real Time (RT) Linux Kernel

| Head Commit: e0c39cf61df45b3f69d7ad1afd919e104d39eba3 Merged TI feature | ti_linux_base_rt into ti-rt-linux-5.4.y
| Date: Thu Jan 21 09:07:27 CST 2021
| Kernel Version: 5.4.87
| RT Kernel Version: 5.4.87-rt48
| Kernel Description: 07.02.00.004-rt

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.4.y
| Tag: 07.02.00.004-rt
| Kernel defconfig: multi_v7_defconfig

| Compiler Information: arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025

|

Yocto
-----
.. rubric:: meta-ti

| Head Commit: 542456ca082de7133a61be21222d13974a87e41d 
| ti-sci-fw: Update image gen and sysfw to v2020.12a
| Date: 2021-1-21
| Version: dunfell-3.1

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: 07.02.00.004

|

.. rubric:: meta-arago

| Head Commit: 3d81e5add1f7173e34a4fbc189bf56872969fc98  
| branding: core-next: AUTOREV kernel and uboot
| Date: 2021-1-21
| Version: 2020.05

| Clone: git://arago-project.org/git/meta-arago.git
| Branch: dunfell
| Release Tag: 07.02.00.004
|
|

Issues Tracker
==============

U-Boot Known Issues
-------------------

.. csv-table::
   :header: "Record ID", "Title"
   :widths: 5, 70

   "LCPD-20131","am64xx uboot fails to enumerate devices attached to a usb hub on the first 'usb reset' call"

Linux Kernel Known Issues
-------------------------

.. csv-table::
   :header: "Record ID", "Title"
   :widths: 5, 70

   "LCPD-20171","AM64x: Occasional boot failure due to dmesg log about cdns-usb3 that blocks the prompt "
   "LCPD-20169","AM64x: CPSW3g link can take up to 45 seconds to come back up"
   "LCPD-20168","USB driver trace seen on boot"
   "LCPD-20165","TSN PTP binary testptp not present by default in am64 filesystem"
   "LCPD-20164","TSN IET (Frame Preemption) eth0 link sometimes does not come back up after configuring"
   "LCPD-20163","am64xx fails to boot when using the mmcmode custom build"
   "LCPD-20162","Degraded performance when running IET tests over eth1"
   "LCPD-20130","am64xx PCIe-EP test failing due to a NULL pointer exception"
   "LCPD-20122","am64xx not recognizing a USB stick attached to a PCIe USB card"
   "LCPD-20119","Kernel user's guide does not mention ARM64 or AM64x"
   "LCPD-20111","TSN IET (Frame Preemption) iperf3 network is unreachable with VLAN"
   "LCPD-20107","USBDEVICE Bi-directional iperf test fails on am64xx when running from dut to server"
   "LCPD-20106","USBDEVICE ping from DUT to host fails when packet_count=470"
   "LCPD-20105","AM64x: Kernel: ADC: RX DMA channel request fails"
   "LCPD-20061","Occasional PHY error during during TSN Time-Aware Shaper execution"
   "LCPD-20055","Assign am64xx GPIO test pins in ltp-ddt"
   "LCPD-20050","Ramfs does not support ti-test installation due to 2GB RAM on AM64"
   "LCPD-20006","AM64x: remoteproc may be stuck in the start phase after a few times of stop/start"
   "LCPD-20004","AM64: g_ether module failing to bringup link on host side"
