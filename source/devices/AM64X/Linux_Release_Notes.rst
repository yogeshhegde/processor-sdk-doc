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

U-Boot
------

| Head Commit: 84b608fd3489c8dd93d8eb20e7f005d967b88402 arm: | dts: k3-am65: Add tag to disable UHS modes in SR 1.0
| Date: Thu Jan 21 08:28:10 CST 2021
| uBoot Version: 2020.01
| uBoot Description: 07.02.00.004

| Clone: ssh://git@bitbucket.itg.ti.com/lcpdpub/ti-u-boot.git
| Branch: 07.02.00.004
| uBoot Tag: 07.02.00.004

|

Kernel
------

.. rubric:: Linux Kernel

| Head Commit: 60de748aca87c99a32f726a6abf1b6472f297ae3 Merged TI feature connectivity into ti-linux-5.4.y
| Date: Thu Jan 21 08:37:49 CST 2021
| Kernel Version: 5.4.87
| Kernel Description: 07.02.00.004

| Repo: ssh://git@bitbucket.itg.ti.com/lcpdpub/ti-linux-kernel.git
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

| Repo: ssh://git@bitbucket.itg.ti.com/lcpdpub/ti-linux-kernel.git
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

.. note::
   The following sections will be updated later when finalized in Core SDK.

Errata Workarounds Available in this Release
--------------------------------------------

SDK Known Issues
-----------------

U-Boot Known Issues
------------------------

Linux Kernel Known Issues
---------------------------

