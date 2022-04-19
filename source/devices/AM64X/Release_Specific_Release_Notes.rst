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

To simplify the end user experience, Processor SDK Linux AM64x installer provides everything needed as discussed below
to create the embedded system from “scratch” :

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


Release 08.02.00
================

Released on April 2022

What's new
----------
Processor SDK Linux AM64x Release has following new features:

- Third release on 2021 LTS 5.10 kernel, 2021.01 U-Boot
- Yocto Dunfell/3.1
- NAND boot, Ethernet boot, Secure Boot, ICSSG-Dual Emac
- AM64 HS EVM support

Build Information
=====================================

U-Boot
-------------------------

.. rubric:: u-boot
   :name: u-boot

| Head Commit: 44a87e3ab85c6d64044f0b5ad677008316baad70 ARM: dts: k3-j721s2: Correct timer frequency
| Date: Wed Mar 16 17:05:52 CDT 2022
| uBoot Version: 2021.01
| uBoot Description: 08.02.00.006
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: 08.02.00.006
| uBoot Tag: 08.02.00.006

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

Kernel
-------------------------

.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 7a7a3af903da2b2d551d058f8262a66e6b42b6b1 Merged TI feature connectivity into ti-linux-5.10.y
| Date: Wed Mar 16 12:00:19 CDT 2022
| Kernel Version: 5.10.100
| Kernel Description: 08.02.00.006

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.10.y
| Tag: 08.02.00.006
| Kernel defconfig: ti_sdk_arm64_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 204ec708dc86f4334f585f04835527570be1c4eb Merged TI feature ti_linux_base_rt into ti-rt-linux-5.10.y
| Date: Wed Mar 16 14:53:35 CDT 2022
| Kernel Version: 5.10.100
| RT Kernel Version: 5.10.100-rt62
| Kernel Description: 08.02.00.006-rt

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.10.y
| Tag: 08.02.00.006-rt
| Kernel defconfig: ti_sdk_arm64_rt_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

Yocto
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: facd5397cdc5c35c69e7a8e8f908a98a5c23d270 u-boot-ti-staging: Bump to 08.02.00.006 release
| Date: 2022-03-08
| Version: dunfell-3.1
| Clone: git://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: 08.02.00.006
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: 382ca36beb21a524de726bfd1c57e3d26f10cf82 recipes-core: images: Add tisdk-thinlinux-image
| Date: 2022-03-08
| Version: 2021.09

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: dunfell
| Release Tag: 08.02.00.006
|

Issues Tracker
=====================================

Issues opened in previous releases that were closed in this release
--------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 100

   "LCPD-24627","icssg_prueth: NULL pointer deference during remove","am64xx-evm"
   "LCPD-24625","am64 - Boot modes: eMMC alternative boot mode","am64xx-evm"
   "LCPD-24624","am64 Boot modes: OSPI","am64xx-evm"
   "LCPD-24622","TCP Bidir","am64xx-evm"
   "LCPD-24612","am64xx-hsevm fails to boot","am64xx-hsevm"
   "LCPD-24510","ARM: A72/53 L1 data cache and L2 cache set counts wrong(upstream)","am64xx-evm,am64xx-hsevm,am64xx-sk,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm"
   "LCPD-24486","smatch reports potential dereference of ERR_PTR","am64xx-evm,am654x-evm,j721e-evm,j7200-evm,j721s2-evm"
   "LCPD-24121","IPC SDK docs: link to example source code","am64xx-evm,am64xx-sk"
   "LCPD-23019","OPTEE tests are failing (Impact 5)","am43xx-hsevm,am57xx-hsevm,am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,j721e-idk-gw,j7200-evm"
   "LCPD-22841","Watchdog Timer test is failing (Impact 5.0)","am64xx-evm,j721e-idk-gw,j7200-evm"
   "LCPD-22812","Upstream: reserved-memory.txt  convert to yaml","am64xx-hsevm,am64xx-sk,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm,k2g-evm,k2g-hsevm,j721e-sk"

Issues found and closed in this release that may also be applicable to prior releases
-------------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-25522","AM64: Ethernet broken at u-Boot prompt","am64xx-evm,am64xx-sk"
   "LCPD-25074","AM64 HS Boot broken ","am64xx-hsevm"
   "LCPD-25070","am64xx-sk uboot build failed to boot due to ","am64xx-sk"
   "LCPD-25014","ramfs boot fails when using tisdk-base-image","am64xx-evm,am654x-evm,j721e-idk-gw,j7200-evm,j721s2-evm"

U-Boot Known Issues
-------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

    "LCPD-25540","am64xx-sk","u-boot: usb host boot failed on AM64x SK",""
    "LCPD-25535","am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm","UBoot: customized ${optargs} doesn't take affect on K3 devices",""
    "LCPD-24726","am64xx-sk","Uboot qspi read write performance test  failed ",""
    "LCPD-24507","am64xx-evm,am64xx-hsevm,am64xx-sk,j721e-idk-gw","U-Boot command ""saveenv"" doesn't save env ",""
    "LCPD-23026","am64xx-evm,am64xx-sk","USB MSC Boot: USB controller not visible from u-boot",""
    "LCPD-23020","am64xx-evm","am64xx-evm: U-Boot PHY autonegotiation failed 2 out of 100 times",""

Linux Kernel Known Issues
-------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35

   "LCPD-25558","am64xx-evm","the 'nand' tool doesn't seem to be working",""
   "LCPD-25494","am64xx-evm","AM64 EVM TSN IET tests is failing",""
   "LCPD-25348","am64xx-evm,am654x-evm,am654x-idk","nslookup time out when EVM has multiple eth connections",""
   "LCPD-25320","am64xx-evm,am64xx-sk","Docs: AM64x: IPC chapter should be under Foundational Components",""
   "LCPD-25112","am64xx-evm,j721e-idk-gw","Ethernet driver not gating its clock when interface is down",""
   "LCPD-24872","am64xx-sk","Am64x-sk :LCPD-16811 CPSW  failed while throughput metrics comparison ",""
   "LCPD-24823","am64xx-evm,am64xx-sk","Clarify Single-Core usage in ti,k3-r5f-rproc.yaml",""
   "LCPD-24696","am64xx-sk","CPSW Promiscuous mode test failing on am64xx-sk",""
   "LCPD-24691","am64xx-evm,j7200-evm,j721s2-evm,am62xx-evm","Kernel: Upstream: Set HIGH_SPEED_EN for MMC1 instance",""
   "LCPD-24690","am64xx-evm,am64xx-sk,j7200-evm,j721s2-evm,am62xx-evm","Kernel: SDK: Set HIGH_SPEED_EN for MMC1 instance",""
   "LCPD-24680","am64xx-sk,am654x-evm,j721e-evm,j7200-evm","missing document how to boot to Linux prompt in USB MSC boot mode",""
   "LCPD-24595","am64xx-evm,am64xx-sk,j721e-idk-gw,j7200-evm,j721e-sk","j721e-idk-gw USB Suspend/Resume with RTC Wakeup fail (Impact 1)",""
   "LCPD-24593","am64xx-evm","am64xx-evm CAN_S_FUNC_MODULAR test failures",""
   "LCPD-24511","am64xx-evm,am64xx-hsevm,am64xx-sk,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm","ARM: A72/53 L1 data cache and L2 cache set counts wrong",""
   "LCPD-24473","am64xx-evm","IPSEC_software_crypto_UDP_aes128_sha1_performance",""
   "LCPD-24467","am64xx-sk","am64xx-sk stress boot test files",""
   "LCPD-24456","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j7am-evm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-vlab,j7200-evm,j7200-hsevm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm,k2l-hsevm,omapl138-lcdk,j721s2-evm,j721s2-hsevm,j7amp-evm,j7ae-evm,j7am-vlab,j7am-zebu,j7ae-zebu,j7aep-zebu,j7amp-vlab,j7amp-zebu,j721e-sk,am62xx-evm,am62xx-sk,am62xx-hsevm,am62xx-vlab,am62xx-zebu,am62a-evm","Move IPC validation source from github to git.ti.com",""
   "LCPD-24448","am64xx-evm","Verify IPC kernel: main-r5f0(s)/main-r5f1(s)",""
   "LCPD-23102","am64xx-sk","AM64-SK: DMA is not stable",""
   "LCPD-23066","am64xx-sk","am64x-sk :gpio: direction test fail",""
   "LCPD-22931","am64xx-evm,am64xx-sk,am654x-evm,am654x-idk,dra72x-evm","RemoteProc documentation missing",""
   "LCPD-22912","am64xx-evm","am64xx-evm SMP dual core test fails sporadically",""
   "LCPD-22892","am64xx-evm,am654x-evm,am654x-idk","icssg: due to FW bug both interfaces has to be loaded always",""
   "LCPD-22834","am64xx-evm","am64xx-evm stress boot test fails",""
   "LCPD-22319","am64xx-evm,j7200-evm","OpenSSL performance test data out of bounds",""
   "LCPD-22215","am64xx-evm","PCIE NVM card stops enumerating on am64xx after some time",""
   "LCPD-20705","am64xx-evm","USB stick attached to PCIe USB card is not enumerated",""
   "LCPD-20558","am64xx-sk","OSPI UBIFS tests failing on am64xx-sk",""
   "LCPD-20105","am64xx-evm","AM64x: Kernel: ADC: RX DMA channel request fails",""
   "LCPD-20061","am64xx-evm","Occasional PHY error during during TSN Time-Aware Shaper execution",""
   "LCPD-20006","am64xx-evm","AM64x: remoteproc may be stuck in the start phase after a few times of stop/start",""

Linux RT Kernel Known Issues
----------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35

   "LCPD-24288","am64xx-evm,am654x-idk","am64xx-evm NCM/ACM network performance test crashes with RT images",""
