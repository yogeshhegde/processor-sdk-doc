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

This release supports SR2.0 High Security - Field Securable (HS-FS) devices. For migration guide and other info, refer :ref:`HS-Migration-Guide`

Licensing
=========

Please refer to the software manifests, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page or in the installed directory as indicated below.

-  Linux Manifest:  "/docs/software_manifest.html"


Release 09.02.00
================

Released on March 2024

What's new
----------

**Processor SDK 9.2 Sitara Release has following Major Updates**

  - Kernel: MMC Highspeed tuning and Performance Improvements
  - RT Kernel : Significant Improvements to Real-Time Linux Interrupt Latency, :ref:`RT Interrupt Latencies <RT-linux-performance>`
  - Bug Fixes and Stability Improvements
  - DMSC Firmware: PLL Configuration sequence updated to latest recommendation
  - DMSC Firmware: No longer re-initializing ICSSG clocks

**Component version:**

  - Kernel 6.1.80
  - RT Kernel 6.1.80-rt26
  - U-Boot 2023.04
  - Toolchain GCC 11.4
  - ATF 2.10
  - OPTEE 4.1
  - DMSC Firmware v09.02.07

Build Information
=====================================

.. _u-boot-release-notes:

U-Boot
------------------

.. rubric:: u-boot
   :name: u-boot

| Head Commit: f9b966c674731a1a29a20a8e143c61d4e046f13c configs: am62x_android_a53.config: Disable splashscreen
| Date: 2024-03-21 08:39:16 -0500
| uBoot Version: 2023.04
| uBoot Description: RC Release 09.02.00.009
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2023.04
| uBoot Tag: 09.02.00.009
|

.. _tf-a-release-notes:

TF-A
------------------
| Head Commit: 00f1ec6b8740ccd403e641131e294aabacf2a48b Merge changes from topic "revert-ti-dm-workaround" into integration
| Repo: https://git.trustedfirmware.org/TF-A/trusted-firmware-a.git
| Branch: master
| Tag: 2.10
|

.. _optee-release-notes:

OP-TEE
------------------
| Head Commit: 012cdca49db398693903e05c42a254a3a0c0d8f2 plat-k3: drivers: sec_proxy: increment while reading trail bytes
| Repo: https://github.com/OP-TEE/optee_os/
| Branch: master
| Tag: 4.1.0
|

.. _ti-linux-fw-release-notes:

ti-linux-firmware
------------------
| Head Commit: 553da6850e271b579b569725ce9c58a1a6d7c849 ti-dm: Update firmware for j784s4
| Date: 2024-03-21 08:39:13 -0500
| Clone: https://git.ti.com/cgit/processor-firmware/ti-linux-firmware
| Branch: ti-linux-firmware
| Tag: 09.02.00.009
|

Kernel
------------------

.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 2e423244f8c09173a344e7069f0fe2bdf26cccee net: ethernet: ti: icssg-prueth: Fix RX frame drops in XDP
| Date: 2024-03-21 08:39:05 -0500
| Kernel Version: 6.1.80
| Kernel Description: RC Release 09.02.00.009

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-6.1.y
| Tag: 09.02.00.009
| use-kernel-config=defconfig
| config-fragment=kernel/configs/ti_arm64_prune.config
|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 3c08dbfd7bfd83c247ad1ee4ddb989260c150af1 Merge branch 'ti-linux-6.1.y-cicd' into ti-rt-linux-6.1.y-cicd
| Date: 2024-03-21 08:39:09 -0500
| Kernel Version: 6.1.80-rt26
| Kernel Description: RC Release 09.02.00.009-rt

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-6.1.y
| Tag: 09.02.00.009-rt
| use-kernel-config=defconfig
| config-fragment=config-fragment=kernel/configs/ti_arm64_prune.config kernel/configs/ti_rt.config
|

Yocto
------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 376a2143533c6497b4e79304eccca2a630784436 CI/CD Auto-Merger: cicd.kirkstone.202403201028
| Date: 2024-03-21 08:39:18 -0500

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: kirkstone
| Release Tag: 09.02.00.009
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: 98f178314931635c8641d1394dfd4341b86b6be2 CI/CD Auto-Merger: cicd.kirkstone.202403201028
| Date: 2024-03-21 08:38:40 -0500

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: kirkstone
| Release Tag: 09.02.00.009
|

.. rubric:: meta-tisdk
   :name: meta-tisdk

| Head Commit: 3d2589b3b9b0d102917a7e0b1cecaf62cd7eba79 conf: arago-source-ipk: Enable source-ipk's of all missing packages for ti33x, ti43x
| Date: 2023-12-27 11:07:27 -0600

| Clone: git://git.ti.com/ti-sdk-linux/meta-tisdk.git
| Branch: kirkstone
| Release Tag: 09.02.00.08
|


Issues Tracker
=====================================

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 30, 150

   "LCPD-32825","PCIe: ls -al /dev/disk/by-id shows no nvme device","am64xx-hsevm"
   "LCPD-27886","USART: Erroneous clear/trigger of timeout interrupt","am64xx-evm,am62axx_sk-fs,am62xxsip_sk-fs,am62xxsip_sk-se,am62xx-sk,j721e-idk-gw,j7200-evm,j784s4-evm,j784s4-hsevm"
   "LCPD-25264","BCDMA: Blockcopy Gets Corrupted if TR Read Responses Interleave with Source Data Fetch","am64xx-evm,am64xx-hsevm,am64xx_sk-fs"
   "LCPD-19965","OSPI PHY Controller Bug Affecting Read Transactions","am654x-idk,am64xx-evm,j721e-idk-gw,j7200-evm"

|

U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-28503","am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62xx-sk,am64xx_sk-fs","Need to sync up DTS files between u-boot and kernel for at least AM62x, possibly other boards too",""
   "LCPD-25540","am64xx-hsevm,am64xx_sk-fs","AM64: u-boot: usb host boot failed",""

|

Linux Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35

   "LCPD-37197","am64xx-evm,am64xx-hsevm","AM64x: ENET ICSSG: Firmware is not updating the Host Port statistics",""
   "LCPD-36975","am64xx-evm","HSR Error: 8021q: VLANs not supported on device.",""
   "LCPD-36876","am64xx-hsevm","running linuxptp (ptp4l, phc_ctl or ts2phc, setting clock) it will cause PPS incoherence",""
   "LCPD-36804","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am64xx_sk-fs,am64xx_evm-se,am64xx_sk-se","IPC performance test fail - modprobe fails",""
   "LCPD-36622","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm","Errata i2028: USB3.0 Host and Device Non-Functional",""
   "LCPD-36361","am64xx-hsevm,am62xxsip_sk-se","Boot failure over UART",""
   "LCPD-35352","am64xx-evm,am64xx_sk-fs","AM64x dts file calls SYNC2_OUT the wrong name",""
   "LCPD-35022","am64xx-hsevm","AM64x: Benchmark OOB doesn't show any load on A53 and R5 (core 0) with latest ti-rpmsg-char v6.1",""
   "LCPD-32868","am654x-idk,am64xx-evm","Kernel crash from PRU auto-forwarding packet",""
   "LCPD-27871","am64xx-evm","GPMC NAND driver misleading error",""
   "LCPD-25494","am64xx-evm","AM64 EVM TSN IET tests is failing",""
   "LCPD-24823","am64xx-evm,am64xx_sk-fs","Clarify Single-Core usage in ti,k3-r5f-rproc.yaml",""
   "LCPD-24595","am64xx-evm,am64xx_sk-fs,j721e-idk-gw,j721e-sk,j7200-evm","j721e-idk-gw USB Suspend/Resume with RTC Wakeup fail (Impact 1)",""
   "LCPD-24537","am654x-evm,am64xx-evm,am64xx-hsevm","am654x-idk nslookup times out when all netwokring interfaces are active",""
   "LCPD-24456","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am62xx-sk,am64xx_sk-fs,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j721e-hsevm,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j7200-evm,j7200-hsevm,omapl138-lcdk","Move IPC validation source from github to git.ti.com",""
   "LCPD-24288","am64xx-evm,am64xx-hsevm","am64xx-evm NCM/ACM network performance test crashes with RT images",""
   "LCPD-22912","am64xx-evm","am64xx-evm SMP dual core test fails sporadically",""
   "LCPD-22892","am654x-evm,am654x-idk,am64xx-evm","icssg: due to FW bug both interfaces has to be loaded always",""
   "LCPD-22834","am64xx-evm","am64xx-evm stress boot test fails",""
   "LCPD-22215","am64xx-evm","PCIE NVM card stops enumerating on am64xx after some time",""
   "LCPD-20705","am64xx-evm","USB stick attached to PCIe USB card is not enumerated",""
   "LCPD-20105","am64xx-evm","AM64x: Kernel: ADC: RX DMA channel request fails",""
   "LCPD-20006","am64xx-evm","AM64x: remoteproc may be stuck in the start phase after a few times of stop/start",""
   "LCPD-18854","am64xx-evm,dra71x-evm,dra76x-evm","ov5640 sensor capture fails for raw format capture",""

|

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-37300","AM64x SDK v9.1 SDK Images don't boot on SK-AM64B due to U-Boot using incorrect DTS File from EVM","am64xx-hsevm, am64xx-hssk"
   "LCPD-34852","Few times payload is packed at size boundary by binman ","am654x-evm,am64xx-evm,am62xx_sk-se,j721e-idk-gw,j721s2-evm,j7200-evm"
   "LCPD-34840","AM64: Networking failures including ICSSG","am64xx-hsevm"
   "LCPD-34697","am64x: dtsi: mcu_gpio0 compatible property typo","am64xx-evm,am64xx_sk-fs"
   "LCPD-34687","MMC itapdly sel values are not specified in kernel DTS","am64xx-evm,am64xx_sk-fs"
   "LCPD-34686","MMC itapdly sel values are not specified in uboot DTS","am64xx-evm,am62axx_sk-fs"
   "LCPD-34583","AM64x: some sdcards boot fail in u-boot","am64xx-evm,am64xx_sk-fs"
   "LCPD-34548","k3-image-gen generate error messages","am64xx-evm"
   "LCPD-34413","RT Linux: Interrupt latency issue with >200us outliers","am654x-evm,am654x-hsevm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-sk,am64xx_sk-fs,j721e-sk,j721s2-evm,j721s2_evm-fs,j7200-evm,j784s4-evm"
   "LCPD-34258","Upstream: kernel: Bug: ""ti,j721e-esm"" should be described  bindings and devicetree update","am654x-evm,am654x-idk,am64xx-evm,am64xx_sk-fs,am68_sk-fs,am69_sk-fs,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2_evm-fs,j7200-evm,j784s4-evm"
   "LCPD-32958","AM6xx/J7: Issue with MCSPI clocking in Linux driver","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xx-lp-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-32946","RT Linux: PRU Ethernet link down causes kernel crash","am654x-evm,am654x-idk,am64xx-evm"
   "LCPD-32825","PCIe: ls -al /dev/disk/by-id shows no nvme device","am64xx-hsevm"
   "LCPD-32823","ICSS firmware does not process Rx packets once Min error frame is received","am654x-idk,am64xx-evm"
   "LCPD-32815","Packet get truncated on Transmit side when high traffic is applied","am654x-idk,am64xx-evm"
   "LCPD-29880","CAN_S_FUNC_MODULAR test fail","am64xx-evm,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-29854","MCU UART TX baud rate is doubled","am64xx-evm,am64xx-hsevm,am64xx-hssk,am64xx_sk-fs"
   "LCPD-29739","AM64: NAND device not detected in U-boot","am64xx-hsevm"
   "LCPD-29651","AM64: NAND Flash device not detected","am64xx-hsevm"
   "LCPD-29597","AM64x: dts: main_rti nodes are defined twice","am64xx-evm"
   "LCPD-29588","CPSW documentation: Time Sync Router no longer firewalled","am654x-evm,am654x-idk,am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-lp-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-29508","AM64x: EMMC speed test fails: MMC not running on HS400 mode","am64xx-evm,am64xx-hsevm,am64xx_sk-fs"
   "LCPD-29500","AM64x: ETH CPSW2g TAS: tests fail with undefined method error","am64xx-evm,am64xx-hsevm,am64xx_sk-fs"
   "LCPD-29499","AM64x: ETH CPSW2g TAS: tests fail with queue 0 did not increase","am64xx-evm,am64xx-hsevm,am64xx_sk-fs"
   "LCPD-29498","AM64x: ETH CPSW2g TAS: Invalid traffic schedule","am64xx-evm,am64xx-hsevm,am64xx_sk-fs"
   "LCPD-29446","Linux SDK docs should explicitly state what peripherals are supported","am654x-evm,am654x-idk,am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am335x-evm,am335x-ice,am335x-sk,am43xx-gpevm,am437x-idk,am437x-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-29442","Docs: AM62x-SK: Kernel User Guide uses tisdk_am64xx defconfigs","am62xx_sk-fs,am62xx_sk-se,am62xx-sk"
   "LCPD-29362","AM64x EVM Devicetree should disable unused MCU peripherals","am64xx-evm,am64xx_sk-fs"
   "LCPD-29305","AM64x Uboot SRAM addresses are outdated","am64xx-evm,am64xx_sk-fs"
   "LCPD-28688","AM62x Kernel User Guide: Document AM62x default kernel config","am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-lp-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-28672","CPSW: Add more details about driver config","am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62axx_sk-fs,am62xx-sk,am64xx_sk-fs"
   "LCPD-28660","AM64x: tiboot3.bin generated by U-Boot build is confusing users","am64xx-evm,am64xx-hsevm,am64xx_sk-fs"
   "LCPD-26692","Hardware + Software IPSec Performance Test Failures","am64xx-evm,am335x-evm,am43xx-gpevm,am57xx-evm,j721e-idk-gw"
   "LCPD-24649","dma-heaps-test fails to build with 5.16-rc3 kernel+","am64xx-evm,am335x-evm,dra71x-evm,j721e-idk-gw"
   "LCPD-23020","am64xx-evm: U-Boot PHY autonegotiation failed 2 out of 100 times","am64xx-evm"
   "LCPD-23011","Missing u-boot README file for AM64x","am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62xx-sk,am64xx_sk-fs"
   "LCPD-22931","RemoteProc documentation missing","am654x-evm,am654x-idk,am64xx-evm,am64xx_sk-fs"
   "LCPD-22319","OpenSSL performance test data out of bounds","am64xx-evm,am62axx_sk-fs,am62xx-sk,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-20038","OPTEE test applications are missing from rootfs","am64xx-hsevm"

|

Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-37151","am62: am64: i2c set/get tests are failing","am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xxsip_sk-fs,am62xxsip_sk-se,am62pxx_sk-fs,am62pxx_sk-se,am62xx-sk"
   "LCPD-36850","HSR switching offload firmware needs to be loaded twice","am64xx-hsevm"
   "LCPD-36847","doc: ltp-ddt documentation is not upto date","am64xx-hsevm,am62xx_sk-fs,am62axx_sk-fs,am62pxx_sk-fs,am68_sk-fs,am69_sk-fs,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-36744","Linux SDK: CPSW: Bridge interface cannot ping in Switch Mode","am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am64xx_sk-fs,am64xx_evm-se,am64xx_sk-se,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm,j784s4-evm,j784s4-hsevm"
   "LCPD-36645","AM64X: Linux HSR - Multicast filtering support","am64xx-evm"
   "LCPD-36621","K3: OPENSSL: Fix testcases and make it platform specific","am62xx_sk-se,am62axx_sk-fs,am64xx_sk-fs,am68_sk-fs,am69_sk-fs,j721e-idk-gw,j721e-sk,j721s2-evm,j7200-hsevm,j784s4-evm"
   "LCPD-36587","U-Boot: CPSW: Phy-Mode not configured correctly for ports","am64xx-evm,am64xx-hsevm,am62xx_sk-fs,am62xx_sk-se,am64xx_sk-fs,am64xx_sk-se"
   "LCPD-36549","ICSSG: Ping to bridge not working in switch mode","am654x-idk,am64xx-hsevm"
   "LCPD-36494","Migrate to OPTEE 4.0.0 to address PSIRT","am62xx_sk-fs,am62axx_sk-fs,am64xx_sk-fs,j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-36473","ICSSG UDP Performance Failure","am64xx-hsevm"
   "LCPD-36287","Doc: Update Toolchain documentation to 11.2+","am62xx_sk-fs,am64xx_sk-fs,j721e-idk-gw"
   "LCPD-35300","Doc Bugs - Link/Add TISCI chapters and remove MSMC chapter ","am64xx-hsevm,am62xx_sk-fs"
   "LCPD-35108","AM64x: eMMC boot fails using flashed using DFU ","am64xx-evm"
   "LCPD-35033","AM64: ICSSG VLAN testcase is failing in 9.0-rc6","am64xx-hsevm"
   "LCPD-34994","AM64x: fitImage not booting","am64xx-hsevm"
   "LCPD-34993","AM64x: sf probe fails on hs-fs","am64xx-hsevm"
   "LCPD-34992","AM64x DFU Boot fails with signed images","am64xx-hsevm"
   "LCPD-34966","rpmsg_ctrl device mapping errors see with 6.1 kernel","am64xx-evm,am62xx_sk-fs,am62axx_sk-fs,am62xx-lp-sk,am62xx-sk,am64xx_sk-fs,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721s2-evm,j784s4-evm"

|

Linux SDK known issues
----------------------
.. csv-table::
    :header: "Record ID", "Title", "Platform"
    :widths: 15, 70, 20

    "LCPD-37207","Docker is disabled in RT Linux","am64xx-hssk, am62xx_lp_sk-fs, am62xxsip_sk-fs, am62pxx_sk-fs"

|

