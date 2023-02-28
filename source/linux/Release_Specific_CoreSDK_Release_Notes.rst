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


Release 08.06.00
==================

Released February 2023

.. rubric:: What's New
   :name: whats-new

**Processor SDK 8.6 Sitara Release supports the following platforms**

  * AM65x 2.0 (GP, HS-SE)
  * AM64x 2.0 (HS-FS)
  * AM62x (GP, HS-FS, HS-SE)
  * AM62x LP (HS-FS, HS-SE)
  * AM62A (HS-FS, HS-SE)

**Processor SDK 8.6 Sitara Release has following Major Updates**

  * AM62A First Public Release
  * Upgrade ATF v2.8+, OPTEE 3.20
  * HS-FS Default Boot Experience for AM64, AM62, AM62A, AM62 LP
  * IRQ Affinity for AM64, AM62, AM62A

**AM62A**
  
  * Uboot: OSPI NAND with UBIFS, C7x and R5 Early boot, DFU Flashing
  * Uboot: QoS Optimization for DSS and CSI load
  * Kernel: Wave521 Video Encode and Decode
  * Kernel: CSI Support with OV5640, IMX219, IMX390 and OV2312 Sensors
  * SA3UL with OPTEE TRNG
  * K3conf debug tool

**AM62**

  * Uboot: M4 Early boot, GPMC NAND (on SK LP)
  * Kernel: Low Power Deep Sleep mode, CPUIdle on GP
  * Kernel: RS485, mCRC, Dual Display
  * IPC: A53 --> DM R5
  * SA2UL with OPTEE TRNG
  * TSN Network configuration support using netconf / YANG

**AM64**

  * Kernel: RS485, RT Stress-ng validation
  * Bug Fixes and Stability Improvements
  * TSN Network configuration support using netconf / YANG

**AM65**

  * Major Refresh release 8.2 --> 8.6
  * Includes Bug Fixes and Stability Improvements

Build Information
=====================================

U-Boot
-------------------------
| Head Commit: 2ee8efd6543648c6b8a14d93d52a6038854035c8 Revert "configs: am57xx_evm: Enable Android commands"
| Date: Mon Feb 27 19:49:10 CST 2023
| uBoot Version: 2021.01
| uBoot Description: 08.06.00.007
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2021.01
| uBoot Tag: 08.06.00.007

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

Kernel
-------------------------
.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 2c23e6c538c879e380401ae4b236f54020618eaa Merged TI feature connectivity into ti-linux-5.10.y-cicd
| Date: Mon Feb 27 19:47:47 CST 2023
| Kernel Version: 5.10.168
| Kernel Description: 08.06.00.007

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.10.y
| Tag: 08.06.00.007
| Kernel defconfig: ti_sdk_arm64_release_defconfig

| Compiler Information:  arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025
|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: c1a12919117a6978f40e723d6e0c67c744e026b9 Merge branch 'ti-rt-linux-5.10.y-cicd' into ti-rt-linux-5.10.y
| Date: Mon Feb 27 20:29:47 CST 2023
| Kernel Version: 5.10.168
| Kernel Description: 08.06.00.007-rt

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.10.y
| Tag: 08.06.00.007-rt
| Kernel defconfig: ti_sdk_arm64_rt_release_defconfig

| Compiler Information:  arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025
|


Yocto
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 45bdaf7da0bc79fa73f1e01bb30b5c3b2eb34545 linux-ti-staging-rt: RC Auto-Merger: 08.06.00.007
| Date: 2023-02-23

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: 08.06.00.007
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: e4fcc247b2fadc457efaff8edabdf12a6b4fa4d1 ltp-ddt: CI/CD Auto-Merger: cicd.dunfell.202302211800
| Date: 2023-02-23

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: dunfell
| Release Tag: 08.06.00.007
|

Issues Tracker
=====================================

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------
.. csv-table::
  :header: "Record ID", "Title", "Platform"
  :widths: 15, 70, 20

  "LCPD-29860","CI/CD : Update Heading to AM62/64x Linux Processor SDK Stable Release","am62xx-sk,am64xx-evm"
  "LCPD-32777","Update LPM demo documentation","am62xx-sk,am62xx_sk-fs,am62xx_sk-se"
  "LCPD-32731","Default booting behavior of HS-FS devices should be explicitly documented","am62axx_sk-fs,am62xx-sk,am64xx-evm,am64xx-sk"
  "LCPD-29855","am62: Microtips OLDI Panels Distortion issue","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk"
  "LCPD-32773","Rx stall seen when there is network traffic during startup","am64xx-evm,am654x-idk"
  "LCPD-32331","Unavailability of unsigned images for ATF, OPTEE and A53 SPL","am62xx-lp-sk,am62xx_lp_sk-fs"
  "LCPD-29900","k3: allmod config fails to build due to ti sci kconfig ","am62xx-sk,am64xx-evm,am64xx-sk,j721e-idk-gw"
  "LCPD-32467","tidss: Incorrect pixel format definitions","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,j721e-idk-gw,j721s2-evm,j721s2-hsevm,j784s4-evm,j784s4-hsevm"
  "LCPD-29863","AM62x: OSPI boot mode fails","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs"

|

Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
  :header: "Record ID", "Title", "Platform"
  :widths: 15, 70, 20

  "LCPD-29287","AM62A: OV2312: Frequent IR frames in RGB channel","am62axx_sk-fs"
  "LCPD-29850","Ethernet link up down crashes the system","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm"
  "LCPD-29388","PREEMPT_RT interrupt latency with background memory load","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk"
  "LCPD-29734","AM64x PRUETH Performance Guide numbers are wrong","am64xx-evm"
  "LCPD-29306","PRU_ICSSG: How much SRAM is needed?","am64xx-evm,am654x-idk"
  "LCPD-29808","am62x: SK-lp fails to boot on HS platform","am62xx-lp-sk,am62xx_lp_sk-fs"
  "LCPD-29698","Am62x LP SK: Fix boot issues due to HS support","am62xx-lp-sk,am62xx_lp_sk-fs"
  "LCPD-29433","AM64/AM62: IRQBalance does not migrate IRQs ","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-sk"
  "LCPD-29517","AM64x: UDP test fail: failed T_cpu_util out of expected range","am64xx-evm,am64xx-hsevm,am64xx-sk"
  "LCPD-29347","AM62a: ethernet-related warning about one hour after bootup","am62axx_sk-fs"
  "LCPD-25636","main uart0 pinmux not defined in k3-am642-sk.dts","am64xx-sk"
  "LCPD-25112","Ethernet driver not gating its clock when interface is down","am64xx-evm,j721e-idk-gw"
  "LCPD-20061","Occasional PHY error during during TSN Time-Aware Shaper execution","am64xx-evm"
  "LCPD-29806","AM62: Doc: Add boot mode switch settings","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se"
  "LCPD-29694","gpio-line-names is limited to 100. it should be ti,ngpios","am62axx_sk-fs,am62xx-sk,am64xx-sk,am654x-idk,dra71x-evm,dra7xx-evm,j784s4-evm"
  "LCPD-29621","MCAN user's guide is missing","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se"
  "LCPD-29528","k3: integration: sdk: missing tag info for optee and atf projects","am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk,am64xx-hssk,j721e-idk-gw,j721s2-evm,j721s2-hsevm,j7200-evm,j7200-hsevm,j784s4-evm"
  "LCPD-29518","AM64x: Dhrystone performance test fail","am64xx-evm,am64xx-hsevm,am64xx-sk"
  "LCPD-29308","AM62 LP SK OSPI NAND write fails in U-Boot","am62xx-lp-sk,am62xx_lp_sk-fs"
  "LCPD-28111","wic image flashed sdcard should resize to full image","am62xx-sk,am64xx-evm"
  "LCPD-27886","USART: Erroneous clear/trigger of timeout interrupt","am62axx_sk-fs,am62xx-sk,am64xx-evm,j721e-idk-gw,j7200-evm,j784s4-evm,j784s4-hsevm"
  "LCPD-25409","Doc: Support read of On-die temperature sensor in Linux","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-hsevm,am64xx-sk"
  "LCPD-18860","isolcpus in the command line is not honored","am654x-evm,am654x-idk,j721e-idk-gw,j7200-evm"
  "LCPD-29447","Docs Processor SDK Linux Software Developer’s Guide incorrect camera and LCD inteface","am62xx-sk,am62xx_sk-fs"
  "LCPD-29341","AM64x EVM: Clarify CPSW / PRU Ethernet selection steps","am64xx-evm"

|

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
  :header: "Record ID", "Title", "Platform"
  :widths: 15, 30, 150

  "LCPD-18979","MCAN: Message Transmitted with Wrong Arbitration and Control Fields (Early Start of Frame)","am654x-idk"
  "LCPD-19965","OSPI PHY Controller Bug Affecting Read Transactions","am64xx-evm,am654x-idk,j721e-idk-gw,j7200-evm"
  "LCPD-17788","PCI-Express: GEN3 (8GT/s) Operation Not Supported.","am654x-evm,am654x-idk"
  "LCPD-17783","USB: USB2PHY Charger Detect is enabled by default without VBUS presence","am654x-evm,am654x-idk"
  "LCPD-14184","USB:  SuperSpeed USB Non-Functional","am654x-evm"
  "LCPD-27887","i2327: RTC: Hardware wakeup event limitation","am62xx-sk,am62xx_sk-fs"
  "LCPD-27886","USART: Erroneous clear/trigger of timeout interrupt","am62axx_sk-fs,am62xx-sk,am64xx-evm,j721e-idk-gw,j7200-evm,j784s4-evm,j784s4-hsevm"
  "LCPD-25264","BCDMA: Blockcopy Gets Corrupted if TR Read Responses Interleave with Source Data Fetch","am64xx-evm,am64xx-hsevm,am64xx-sk"
  "LCPD-19447","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame","am654x-evm,am654x-idk"
  "LCPD-14579","DSS : DSS Does Not Support YUV Pixel Data Formats","am654x-evm,am654x-idk"

|

U-Boot Known Issues
------------------------
.. csv-table::
  :header: "Record ID", "Title", "Platform", "Workaround"
  :widths: 15, 30, 70, 30

  "LCPD-28286","ICSSG: AM65 SR2.0: U-Boot: Avoid hardcoding DMA channel","am654x-idk",""
  "LCPD-25540","u-boot: usb host boot failed on AM64x SK","am64xx-hsevm,am64xx-sk",""
  "LCPD-24628","am654x-idk DFU boot is failing","am654x-evm,am654x-idk",""
  "LCPD-29739","AM64: NAND device not detected in U-boot","am64xx-hsevm",""
  "LCPD-28287","ICSSG: AM65 SR2.0: U-Boot: RX is not working","am654x-idk",""
  "LCPD-25558","AM64x: 'nand' tool doesn't seem to be working","am64xx-evm,am64xx-hsevm,am64xx-sk",""
  "LCPD-24726","Uboot qspi read write performance test  failed ","am64xx-sk",""
  "LCPD-24717","am654: PCI-E ethernet interface shows link down in U-Boot","am654x-evm,am654x-idk",""
  "LCPD-24130","AM654x: USB MSC boot mode fails","am654x-evm",""
  "LCPD-23020","am64xx-evm: U-Boot PHY autonegotiation failed 2 out of 100 times","am64xx-evm",""
  "LCPD-16696","U-Boot does not recognize SD-Card after re-insert/change","am654x-evm,am654x-idk",""
  "LCPD-15873","There is no dtbo in u-boot for PCIe x1 + usb3 daughter card","am654x-evm","None"
  "LCPD-29300","U-Boot: OSPI-NOR: sf probe shows 0 randomly","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-28660","AM64x: tiboot3.bin generated by U-Boot build is confusing users","am64xx-evm,am64xx-hsevm,am64xx-sk",""
  "LCPD-28503","Need to sync up DTS files between u-boot and kernel for at least AM62x & AM64x, possibly other boards too","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk",""
  "LCPD-17770","U-Boot: Fix order of MCU R5 shutdown depending on cluster mode","am654x-evm,am654x-idk,am654x-hsevm",""
  "LCPD-16524","Need to adjust RMW bit when using enabling ECC","am654x-evm,am654x-idk,am654x-hsevm","None"
  "LCPD-14843","U-boot should support  default settings for netboot ","am654x-evm,am654x-idk","None"

|

Linux Known Issues
---------------------------
.. csv-table::
  :header: "Record ID", "Title", "Platform", "Workaround" 
  :widths: 5, 10, 70, 35

  "LCPD-18979","MCAN: Message Transmitted with Wrong Arbitration and Control Fields (Early Start of Frame)","am654x-idk",""
  "LCPD-17449","libasan_preinit.o is missing in devkit","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm",""
  "LCPD-29423","AM62A: OV2312: Occassional IR frames in RGB channel","am62axx_sk-fs","PR with a workaround has been opened, Contacted sensor manufacturer for root-cause and proper fix."
  "LCPD-28950","CSI2 Multi-capture channel 0 not working","am62axx_sk-fs",""
  "LCPD-17471","device hang when restarting crashed R5F","am654x-evm,am654x-idk",""
  "LCPD-29589","AM62x CPSW: PPS example not enabled by default","am62axx_sk-fs,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-29397","AM65x Linux SDK lists unsupported industrial protocols","am654x-evm,am654x-idk",""
  "LCPD-25314","ICSSG: Timestamp for back-to-back with IPG < 100us not received","am654x-evm,am654x-idk,am654x-hsevm",""
  "LCPD-23102","AM64-SK: DMA is not stable","am64xx-sk",""
  "LCPD-20558","OSPI UBIFS tests failing on am64xx-sk","am64xx-sk",""
  "LCPD-32480","Image authentication failure at A53 SPL in OSPI NOR boot mode","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-32459","am62a Intermittent Boot Failure on RT-Linux","am62axx_sk-fs",""
  "LCPD-29949","[PROD STOP]I2c operations at 100KHz is broken","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,j721e-idk-gw",""
  "LCPD-29515","AM64x: Cannot boot with USB-MSC","am64xx-evm,am64xx-hsevm,am64xx-sk",""
  "LCPD-29446","Linux SDK docs should explicitly state what peripherals are supported","am335x-evm,am335x-ice,am335x-sk,am43xx-gpevm,am437x-idk,am437x-sk,am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk,am654x-evm,am654x-idk",""
  "LCPD-29441","am62x: kingston emmc fails on AM62x","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-29339","Processor SDK 8.3 AM62x lacks RT Linux performance numbers","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-24448","Verify IPC kernel: main-r5f0(s)/main-r5f1(s)","am64xx-evm",""
  "LCPD-13653","am65x-evm could not boot from MMC/SD when MMC/SD is backup boot mode","am654x-evm,am654x-idk","No workaround"
  "LCPD-32481","AM64x: Environment variables for DFU to NAND","am64xx-evm,am64xx-hsevm",""
  "LCPD-29851","CI/CD Snapshot page doesn't have default images.","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-19948","Yocto: stream recipe is incorrect","am57xx-evm,am654x-evm,j721e-evm",""
  "LCPD-14254","meta-ti: Need a recipe update to pick up the new AM65x PRU Ethernet firmwares","am654x-evm,am654x-idk",""
  "LCPD-29651","AM64: NAND Flash device not detected","am64xx-hsevm",""
  "LCPD-20038","OPTEE test applications are missing from rootfs","am64xx-evm",""
  "LCPD-29332","LPM Demo not Working on Linux RT","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-13817","Qt5 Webengine-based broswer does not work on AM654x with pagesize = 64k","am654x-evm",""
  "LCPD-13816","Chromium-wayland broswer does not work on AM654x with page size = 64k","am654x-evm",""
  "LCPD-29353","Automate Test: AM62x Linux to M4 IPC: simple shared memory example","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-28614","RPMsg client driver sample does not work with AM62x","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-24456","Move IPC validation source from github to git.ti.com","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am62axx_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am62xx-vlab,am62xx-zebu,am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j7ae-evm,j7ae-zebu,j7aep-zebu,j7am-evm,j7am-vlab,j7am-zebu,j7amp-vlab,j7amp-zebu,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721e-vlab,j721s2-evm,j721s2-hsevm,j7200-evm,j7200-hsevm,j7amp-evm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm,k2l-hsevm,omapl138-lcdk",""
  "LCPD-22931","RemoteProc documentation missing","am64xx-evm,am64xx-sk,am654x-evm,am654x-idk",""
  "LCPD-20006","AM64x: remoteproc may be stuck in the start phase after a few times of stop/start","am64xx-evm",""
  "LCPD-16534","remoteproc/k3-r5f: PDK IPC echo_test image fails to do IPC in remoteproc mode on second run","am654x-evm,am654x-idk","None"
  "LCPD-29815","AM62 - Pixel format tests","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-25662","Remove SGX PVR tools from KS3 devices","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,j721e-evm,j7200-evm",""
  "LCPD-18908","GLMark2 fails for am65x","am654x-evm",""
  "LCPD-17413","QT Webengine-based browser: the mouse does not work within the web page with QPA EGLFS","am335x-evm,am43xx-gpevm,am57xx-evm,am654x-evm",""
  "LCPD-17412","QT5 Webengine-based browser crashing with any resize operation","am654x-evm",""
  "LCPD-32356","AM62x: tcrypt doesn't use sa2ul for SHA256/512 or any other alg","am62axx_sk-fs,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-26692","Hardware + Software IPSec Performance Test Failures","am335x-evm,am43xx-gpevm,am57xx-evm,am64xx-evm,j721e-idk-gw",""
  "LCPD-24127","AM654x IPSEC Software Crypto tests fail (Impact 4)","am654x-evm,j721e-idk-gw",""
  "LCPD-32640","Kernel HSR does not work on base image (same command works on default)","am64xx-evm",""
  "LCPD-29854","MCU UART TX baud rate is doubled","am64xx-evm,am64xx-hsevm,am64xx-sk,am64xx-hssk",""
  "LCPD-29588","CPSW documentation: Time Sync Router no longer firewalled","am62axx_sk-fs,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk,am654x-evm,am654x-idk",""
  "LCPD-29533","dropbear fails to start automatically","am335x-evm,am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-29500","AM64x: ETH CPSW2g TAS: tests fail with undefined method error","am64xx-evm,am64xx-hsevm,am64xx-sk",""
  "LCPD-29499","AM64x: ETH CPSW2g TAS: tests fail with queue 0 did not increase","am64xx-evm,am64xx-hsevm,am64xx-sk",""
  "LCPD-29498","AM64x: ETH CPSW2g TAS: Invalid traffic schedule","am64xx-evm,am64xx-hsevm,am64xx-sk",""
  "LCPD-28672","CPSW: Add more details about driver config","am62axx_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk",""
  "LCPD-28492","AM65: ICSSG: phc_ctl: Seeing clock jumps in get","am654x-evm",""
  "LCPD-28436","AM65x Uboot PRUETH is broken","am654x-idk",""
  "LCPD-28415","AM62: emmc: Had to disable higherspeeds","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-28105","Automated test failure - CPSW failure doing runtime pm","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-28104","Automated test failure - CPSW test is passing invalid parameters to switch-config","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-27924","AM65xx: Link does not come up after changing link settings while the interface is up with both endpoints on same board","am64xx-evm",""
  "LCPD-27871","GPMC NAND driver misleading error","am64xx-evm",""
  "LCPD-25563","Test: AM62: Linux: Add support for MCAN","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-25494","AM64 EVM TSN IET tests is failing","am64xx-evm",""
  "LCPD-24872","Am64x-sk :LCPD-16811 CPSW  failed while throughput metrics comparison ","am64xx-sk",""
  "LCPD-24696","CPSW Promiscuous mode test failing on am64xx-sk","am64xx-sk",""
  "LCPD-24690","Kernel: SDK: Set HIGH_SPEED_EN for MMC1 instance","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk,j721s2-evm,j7200-evm",""
  "LCPD-24537","am654x-idk nslookup times out when all netwokring interfaces are active","am64xx-evm,am64xx-hsevm,am654x-evm",""
  "LCPD-24288","am64xx-evm NCM/ACM network performance test crashes with RT images","am64xx-evm,am654x-idk",""
  "LCPD-24128","Performance issues with CPSW/ICSSG Linux Driver","am654x-idk",""
  "LCPD-23066","am64x-sk :gpio: direction test fail","am64xx-sk",""
  "LCPD-22905","UDMA: TR15 hangs if ICNT0 is less than 64 bytes","am654x-evm,j721e-idk-gw",""
  "LCPD-22892","icssg: due to FW bug both interfaces has to be loaded always","am64xx-evm,am654x-evm,am654x-idk",""
  "LCPD-22772","PRU_ICSSG: 100Mbit/s MII is not supported when the PRU_ICSSG is operating at frequencies < 250MHz","am654x-idk",""
  "LCPD-22324","ICSSG port does not drop packets with SA matching interface MAC","am654x-idk",""
  "LCPD-20105","AM64x: Kernel: ADC: RX DMA channel request fails","am64xx-evm",""
  "LCPD-19923","[AM65x] Linux reboot command fails","am654x-evm,am654x-idk","https://e2e.ti.com/support/processors-group/processors/f/processors-forum/1011070/am6548-linux-reboot-command-fails"
  "LCPD-19861","ICSSG: Unregistered multicast MAC packets are still visible in non-promiscuous mode","am654x-evm",""
  "LCPD-19859","ETH ICSSG netperf benchmark returns lower performance than expected","am654x-evm",""
  "LCPD-19580","am654- unable to select a mode (sdhci?)","am654x-evm",""
  "LCPD-18788","Uboot: Could not bring up PCIe interface","am654x-idk",""
  "LCPD-18756","ICSSG: eth5 and eth6 unknown interfaces ","am654x-idk",""
  "LCPD-18665","Am65x Pg2: Board cannot do soft reboot when booting from SD card","am654x-evm,am654x-idk",""
  "LCPD-18289","pcie-usb tests sometimes fail","am654x-evm,k2g-evm",""
  "LCPD-18228","PCI PM runtime suspend is not increasing","am654x-evm",""
  "LCPD-17800","CPSW: Master/Slave resolution failed message seen at console","am654x-evm,am654x-idk",""
  "LCPD-16406","Seeing "e1000#0: ERROR: Hardware Initialization Failed" sometimes when do dhcp via pcie-eth","am654x-idk",""
  "LCPD-15540","uvc-gadget results in segmentation fault","am57xx-evm,am654x-evm,dra71x-evm,dra7xx-evm",""
  "LCPD-14183","am654x-idk failed to login to kernel a few times (7/1000)","am654x-idk",""
  "LCPD-13938","PCIe EP read/write/copy test failed with larger sizes ","am654x-evm,dra71x-evm,dra7xx-evm,k2g-evm",""
  "LCPD-13936","Uboot dhcp timeout 1 of 100 times","am654x-evm",""
  "LCPD-13603","One board could not boot rootfs from more than one SDHC card","am654x-evm",""
  "LCPD-13445","Seldom kernel oops triggered by prueth_netdev_init","am654x-evm",""
  "LCPD-32790","AM62A: VPU: Module load/unload in loop fails after bootup","am62axx_sk-fs",""
  "LCPD-32728","AM62x, AM62a: Doc: Update HS FS Migration Guide","am62axx_sk-fs,am62axx_sk-se,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-32706","Display: DRM tests fail inconsistently","am62xx-sk,am62xx_sk-fs",""
  "LCPD-32353","SBL remote core images does not fit the partition table defined by LINUX for serial NAND ","am62axx_sk-fs,am62xx-lp-sk,am62xx_lp_sk-fs",""
  "LCPD-32351","MMCSD: HS200 and SDR104 Command Timeout Window Too Small","am62xx-sk,am62xx_sk-fs,am62xx_sk-se","If the command requires a timeout longer than 700ms, then the MMC host controller command timeout can be disabled (MMCSD_CON[6] MIT=0x1) and a software implementation may be used in its place. Detailed steps as follows (in Linux):"
  "LCPD-29876","am62x: crypto RNG functional and performance tests failures","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-29875","am62x: crypto SHA performance tests failures","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-29874","am62x: robustness: fails to boot 100 reboot test consistently","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-29792","am62x: mcspi not functional","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-29654","AM62x: OSPI read Performance test fail ","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-29597","AM64x: dts: main_rti nodes are defined twice","am64xx-evm",""
  "LCPD-29508","AM64x: EMMC speed test fails: MMC not running on HS400 mode","am64xx-evm,am64xx-hsevm,am64xx-sk",""
  "LCPD-29489","M4F Core should be able to load data to OC_SRAM","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk",""
  "LCPD-29445","am62xx-sk: MCAN loop-back test is failing","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-29442","Docs: AM62x-SK: Kernel User Guide uses tisdk_am64xx defconfigs","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-29409","DMIPS number should reflect all 4 cores","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-29362","AM64x EVM Devicetree should disable unused MCU peripherals","am64xx-evm,am64xx-sk",""
  "LCPD-29305","AM64x Uboot SRAM addresses are outdated","am64xx-evm,am64xx-sk",""
  "LCPD-29113","Test gap: Linux support for CSI2 virtual channel/multiple camera support","am62axx_sk-fs",""
  "LCPD-28764","AM62x: Cannot resume from low power mode","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-28742","AM62x: Make "Debugging SPL" doc specific to AM62x","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-28688","AM62x Kernel User Guide: Document AM62x default kernel config","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-28514","AM62x: MMC Card detect does not work","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-28491","WiLink not functional with fw_devlink option set to `on` ","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-28448","Wall time does not account for sleep time","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-28414","AM62x EVM Devicetree should disable unused MCU peripherals","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-28156","Mcasp: Buffer underflow warnings","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-25410","Test: Support read of On-die temperature sensor in Linux","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se,am64xx-evm,am64xx-sk",""
  "LCPD-24467","am64xx-sk stress boot test fails","am64xx-sk",""
  "LCPD-22912","am64xx-evm SMP dual core test fails sporadically","am64xx-evm",""
  "LCPD-22834","am64xx-evm stress boot test fails","am64xx-evm",""
  "LCPD-22715","i2232: DDR: Controller postpones more than allowed refreshes after frequency change","am62xx-sk,am62xx_sk-fs,am62xx_sk-se,j721e-idk-gw,j721s2-evm,j7200-evm","Disable dynamic frequency change by programing DFS_ENABLE"
  "LCPD-20653","ltp: kernel syscall tests fail","am335x-evm,am43xx-gpevm,am654x-idk,j721e-idk-gw",""
  "LCPD-19929","Industrial protocols documentation","am654x-evm",""
  "LCPD-18258","IPSEC perfomance failures","am654x-evm,j721e-idk-gw",""
  "LCPD-17777","AES HW is not exercised","am654x-evm",""
  "LCPD-17673","No software documentation for the Timer module","am335x-evm,am43xx-gpevm,am571x-idk,am572x-idk,am574x-idk,am57xx-evm,am654x-evm,beaglebone-black,dra71x-evm,dra72x-evm,dra7xx-evm,j721e-evm",""
  "LCPD-17115","BUG: sleeping function called from invalid context at kernel/locking/rtmutex.c:967","am654x-evm",""
  "LCPD-16845","OPP freq update in DT impacts only cluster0","am654x-evm,am654x-idk",""
  "LCPD-13410","Reboot command is not operational","am654x-evm,am654x-idk",""
  "LCPD-32793","Continous noise heard while playing audio file on am62a SK board","am62axx_sk-fs",""
  "LCPD-32344","AM62: McASP recording causes CPU freezes","am62axx_sk-fs,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-25652","am62: sk: reset-gpio property for sil9022a","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-24134","AM654x CAL DMABUF tests fail (Impact 4.0)","am654x-evm",""
  "LCPD-22947","Alsa performance test fails","am654x-evm",""
  "LCPD-19447","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame","am654x-evm,am654x-idk",""
  "LCPD-18297","AM6: OV5640: 176x144 does not work","am654x-evm",""
  "LCPD-14443","CTS failures detected","am654x-evm",""
  "LCPD-14442","Ethernert port does not obtain ip address","am654x-evm",""
  "LCPD-29861","AM64x: IPC tests fail","am64xx-evm,am64xx-hsevm,am64xx-sk,am64xx-hssk",""
  "LCPD-20014","remoteproc: TX_PRU: IRQ vring, IRQ kick not found error message on console","am654x-evm,am654x-idk,am654x-hsevm",""
  "LCPD-29879","AM62x: MMC Modular NEG RMMOD when mount test fail","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-29873"," AM62x: host does not detect USB gadget","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-29871","AM62xx-lp-sk: UHS104 card FAT write results are out of expected range","am62xx-lp-sk,am62xx_lp_sk-fs",""
  "LCPD-29864","AM62x: USB DFU test fails","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-29862","AM62x: Uboot qspi read write performance tests fail","am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-29580","ICSSG IET Statistics are not getting counted","am64xx-evm,am654x-evm,am654x-idk",""
  "LCPD-29943","AM64x: Upstream: Add boot mode switch settings","am62axx_sk-fs,am62axx_sk-se,am62xx-lp-sk,am62xx_lp_sk-fs,am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-29933","Linux SDK docs: GPIO Guide feels insufficient","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-29880","CAN_S_FUNC_MODULAR test fail","am64xx-evm,j7200-evm,j784s4-evm",""
  "LCPD-29805","AM64: Doc: Add boot mode switch settings","am64xx-evm,am64xx-hsevm,am64xx-sk,am64xx-hssk",""
  "LCPD-29649","inta_ack results in NULL pointer exception","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-24718","am654x hwspinlock test failing","am654x-evm,am654x-idk",""
  "LCPD-19739","AM65 shutdown error","am654x-idk,j7200-evm",""
  "LCPD-29872","PTP Time Synchronization needs to be restarted after link downs","am654x-evm,am654x-idk",""
  "LCPD-22959","UART Read/Write tests at baud rate 115200 fails","am654x-evm",""
  "LCPD-22215","PCIE NVM card stops enumerating on am64xx after some time","am64xx-evm",""
  "LCPD-20705","USB stick attached to PCIe USB card is not enumerated","am64xx-evm",""
  "LCPD-20243","AM65x Transition Kernel: pru-icssg support for100M half duplex mode is broken","am654x-idk",""
  "LCPD-24319","am654x-evm DRM tests fail due to frequency mismatch (Impact 7)","am654x-evm",""
  "LCPD-23008","AM65xx - display port scenario not enabled","am654x-evm",""
  "LCPD-23007","k3-am654-evm-hdmi.dtbo file is missing in CoreSDK for am654x","am654x-evm",""

|

Linux RT Kernel Known Issues
----------------------------
.. csv-table::
  :header: "Record ID", "Title", "Platform"
  :widths: 15, 70, 20

  "LCPD-29339","Processor SDK 8.3 AM62x lacks RT Linux performance numbers","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-29332","LPM Demo not Working on Linux RT","am62xx-sk,am62xx_sk-fs,am62xx_sk-se",""
  "LCPD-24288","am64xx-evm NCM/ACM network performance test crashes with RT images","am64xx-evm,am654x-idk",""

|

