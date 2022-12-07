************************************
Release Notes
************************************
.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Release_Notes

Overview
========

The **Processor-CoreSDK for Linux**
provides a fundamental software platform for development, deployment and
execution of Linux based applications and includes the following:

-  Bootloaders & Filesystems
-  Prebuilt Binaries
-  Detailed Release Notes

Licensing
=========

Please refer to the software manifest, which outlines the licensing
status for all packages included in the prebuilt binaries location. 


Release 08.05.00
==================

Released November 2022

.. rubric:: What's New
   :name: whats-new

Processor SDK 8.5 Release supports the following platforms:

- J721E
- J7200
- J721S2
- J784S4

Processor SDK 8.5 Release has following new features:

- Adds support for the J784S4 device family
- JPEG Decode support on J721E
- Authentication of firmware
- Proper support for poweroff command
- McSPI slave support
- J7AEP stability progress (mostly Graphics)


Build Information
=====================================

U-Boot
-------------------------
| Head Commit: 7996ed51f1c979cfdcb4bf4178dc35cf5e1f9778 j721e: j7200: serdes: evm: Switch to using R5/A72 config to configure serdes
| Date: Thu Dec 1 20:58:54 CST 2022
| uBoot Version: 2021.01
| uBoot Description: 08.05.00.005
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: 08.05.00.005
| uBoot Tag: 08.05.00.005

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

Kernel
-------------------------
.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 90c3a58fd297079d5fe3ebbaed1d1ff56191c953 Merged TI feature connectivity into ti-linux-5.10.y-cicd
| Date: Tue Nov 29 17:55:39 CST 2022
| Kernel Version: 5.10.153
| Kernel Description: 08.05.00.005

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.10.y
| Tag: 08.05.00.005
| Kernel defconfig: ti_sdk_arm64_release_defconfig

| Compiler Information:  arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025
|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: f16ef0399346f5b34f5fbd2ca91a712ab844de57 Merge branch 'ti-rt-linux-5.10.y-cicd' into ti-rt-linux-5.10.y
| Date: Thu Dec 1 21:13:45 CST 2022
| Kernel Version: 5.10.153
| Kernel Description: 08.05.00.005-rt

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.10.y
| Tag: 08.05.00.005-rt
| Kernel defconfig: ti_sdk_arm64_rt_release_defconfig

| Compiler Information:  arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025
|

Yocto
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit:	f8ddf45aca3fe5dd8b39bca8610b1e54a035eb5d linux-ti-staging-rt: RC Auto-Merger: 08.05.00.005
| Date: 2022-11-22

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: 08.05.00.005
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: f798b7a60966528c8eec33b43546a744f545fc4e ltp-ddt: CI/CD Auto-Merger: cicd.2022.11.22.08:55:27
| Date: 2022-11-22

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: dunfell
| Release Tag: 08.05.00.005
|


Issues Tracker
=====================================

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-28510","VDEC: Decoder gives cmalloc errors","j721e-idk-gw"
   "LCPD-28625","J7AHP: Add the missing UART instances clock/dev data","j784s4-evm"
   "LCPD-28243","core-image-minimal build fails for j7200-evm with rm_work enabled","j7200-evm"
   "LCPD-28108","J7200: cadence-mhdp-fw recipe should be machine dependent on j721e-evm only","j7200-evm"
   "LCPD-28509","WAVE5: MultiStream Decode/Encode > 2 channel fails ","j721s2-evm,j784s4-evm"
   "LCPD-28256","Wave5: H264/265 Encoded file produces extra green garbage data on width","j721s2-evm"
   "LCPD-28255","Wave5: Decode fails for Dynamic resolution change in input stream	","j721s2-evm"
   "LCPD-28254","Wave5: Decode deosnot work for videotestsrc with pattern source","j721s2-evm"
   "LCPD-25332","J721e Failing Video test","j721e-idk-gw"
   "LCPD-28325","kernel crashes if CONFIG_DEBUG_FS is not set","am62xx-hsevm,am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm,j7am-evm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721s2-evm,j721s2-hsevm,j7200-evm,j7200-hsevm"
   "LCPD-24142","J721e: Issue with OSPI probe in kernel when booting from OSPI boot mode","j721e-evm,j721e-hsevm,j721e-idk-gw"
   "LCPD-28387","J721e/J7200/J721s2: Add the missing UART instances clock/dev data","j721e-evm,j721s2-evm,j7200-evm"
   "LCPD-28349","j721s2-evm: no support in k3conf","j721s2-evm"
   "LCPD-28246","J7200/J7VCL: Linux crash when we cat pinctrl debugfs node","j7200-evm"
   "LCPD-26728","J721e: Watchdog reset fails on newer SoMs","j721e-idk-gw,j721e-sk"
   "LCPD-25670","tisdk-tiny-image does not boot for J721S2/J784S4","j721s2-evm,j784s4-evm"
   "LCPD-25317","A72 SPL: A72 SPL memcpy sluggish with 8.0/8.1 SDK","j721e-idk-gw"
   "LCPD-25075","J721E: revE8 SoM board doesn't boot consistently","j721e-idk-gw"
   "LCPD-28502","MMC I/O latency is causing audio UNDERRUN issues","j721e-idk-gw"
   "LCPD-24125","j721e-idk-gw all LE play + record tests fail (Impact 7.0)","j721e-idk-gw"
   "LCPD-16911","Linux performance guide: Crypto benchmark numbers: fix unit and accompanying description","j721e-evm,j721e-idk-gw"
   "LCPD-28259","Wave5: V4l2 driver Multi stream support","j721s2-evm"
   "LCPD-28257","Wave5: Video looping does not work with H264/265 Decoder","j721s2-evm"
   "LCPD-28465","Automated test failure - KICKSYNC SYNCCONTEXTLOOP failed due to change in command line arguments","j721s2-evm,j721s2-hsevm"
   "LCPD-16366","RGX kick test fails when 32 sync dependencies are set for each command","j721e-evm,j721e-evm-ivi,j721e-idk-gw"
   "LCPD-28403","SDK: Crypto node cleanup across TI SOCs","am64xx-evm,am654x-evm,j721e-evm,j721s2-evm,j7200-evm,j784s4-evm"
   "LCPD-27948","TSN: PTP test fails with J7200 in switch mode (acting as a transparent clock)","j7200-evm"
   "LCPD-25564","J721s2-evm: CPSW2g: interface goes up and down sporadically","am62xx-sk,j721s2-evm"
   "LCPD-25469","j721e USB OTG HOST regressions on eptf126","j721e-idk-gw"
   "LCPD-24677","j721e-idk-gw PCI WIFI Tests Fail due to iperf issues(Impact 1)","am62xx-sk,j721e-idk-gw"
   "LCPD-28206","j721: sdhci0: Capabilities offered in U-Boot Vs Kernel dts are different","j721e-idk-gw"
   "LCPD-24511","ARM: A72/53 L1 data cache and L2 cache set counts wrong","am64xx-evm,am64xx-hsevm,am64xx-sk,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm"
   "LCPD-22861","Missing documentation for HS devices","j721e-hsevm"
   "LCPD-28258","Wave5: Kernel crash during encode usecase","j721s2-evm"


|


Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-29625","j721e hangs during boot after IPC tests reconfigures firmware","j721e-idk-gw"
   "LCPD-28795","J7AHP : xSPI boot enable DMA","j784s4-evm"
   "LCPD-28663","Pauses in video being displayed when input video is read from SD card","j721e-idk-gw"
   "LCPD-29696","SERDES driver not being probed in U-Boot","j721e-evm,j7200-evm"
   "LCPD-29302","J721S2: CSI2RX: stream broken with update in DPHY Common module reset logic","j721s2-evm"
   "LCPD-28927","J7200: MCSPI: Data mismatch between the master & slave(J7200) when cpu is heavily loaded","j7200-evm"
   "LCPD-28889","j721s2: GPIO Interrupts are broken","j721s2-evm"
   "LCPD-29639","DSS tests failing due to FPS mismatch","j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk"
   "LCPD-28762","GLMark2 visual errors around fragmentation shader tests","am62xx-hsevm,am62xx-sk,j721e-evm,j721e-hsevm,j721s2-evm,j721s2-hsevm,j784s4-evm,j784s4-hsevm"
   "LCPD-29732","SDK: MDIO: DaVinci driver probe incorrectly deferred","j784s4-evm,j784s4-hsevm"
   "LCPD-29477","j721e-idk-gw PCI WIFI Tests Fail due to iperf issues(Impact 1)","am62xx-sk,j721e-idk-gw"
   "LCPD-29419","J721s2-evm: u-boot: CPSW2g: interface goes up and down sporadically","am62xx-sk,j721s2-evm"
   "LCPD-28756","J7AHP - Enable ultra high speed mode for SDIO/MMC","j784s4-evm"
   "LCPD-29534","kernels in arago-dunfell RT directory are not an RT-Kernels","am62xx-hsevm,am62xx-lp-sk,am62xx-sk,am64xx-sk,j721e-evm,j721e-hsevm,j721s2-evm,j721s2-hsevm,j7200-evm,j7200-hsevm,j784s4-evm,j784s4-hsevm"
   "LCPD-29524","j721: sdhci0: Capabilities offered in U-Boot Vs Kernel dts are different","j721e-idk-gw"
   "LCPD-29284","Fix ti,sci-inta, ti,sci-intr and mmc dtbs_check","am62xx-sk,am64xx-evm,j721e-idk-gw,j721s2-evm"
   "LCPD-28765","J7200: U-boot R5 SPL build triggers warning due to duplicate config definitions","j7200-evm"


|

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 150

   "LCPD-19965","am64xx-evm,am654x-idk,j721e-idk-gw,j7200-evm","OSPI PHY Controller Bug Affecting Read Transactions"
   "LCPD-19047","j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw","USB: Race condition while reading TRB from system memory in device mode"
   "LCPD-17220","j721e-idk-gw","U-Boot Hyperbus: Hyperflash reads limited to 125MHz max. frequency"
   "LCPD-16605","j721e-evm,j721e-evm-ivi,j721e-idk-gw","MMC: MMC1/2 Speed Issue"
   "LCPD-22544","j7200-evm","DDR: LPDDR4 should be configured to 2666 MT/S"
   "LCPD-19068","j721e-evm,j721e-evm-ivi,j721e-idk-gw","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame"

|

U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-29402","am64xx-evm,j7200-evm","tftp download in U-Boot fails on am64xx-evm1@eptf124 ",""
   "LCPD-25263","j721s2-evm","j721s2-evm: U-Boot USBHOST: Superspeed test is failing",""
   "LCPD-22512","j721e-evm,j7200-evm","Update dfu_alt_info_ospi to include flashing of PHY tuning data",""
   "LCPD-17789","j721e-idk-gw","UBOOT J7:  Could not see UFS device by scsi scan",""
   "LCPD-24824","j7200-evm","J7200/VCL: u-boot SPL code configuring the SOC DDR PLL (PLL12) incorrectly. Desired boot frequency is 27.5 MHz",""
   "LCPD-22904","j721e-idk-gw,j7200-evm","U-boot: Update EMIFtool for i2244:DDR: Valid stop value must be defined for write DQ VREF training",""
   "LCPD-17523","j721e-evm,j721e-idk-gw,j7200-evm","A72-SPL - Support to dump EEPROM to shared memory",""
   "LCPD-29743","j721e-evm,j721s2-evm,j7200-evm","u-boot ums does not work stably",""
   "LCPD-24108","j721e-evm,j721e-evm-ivi,j721e-idk-gw","U-Boot: TISCI config ring fail traces seen in OSPI boot mode on J721E",""
   "LCPD-29852","j784s4-evm","j784s4-evm: SD card not recognized in U-Boot when booting over UART",""

|


Linux Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround" 
   :widths: 5, 10, 70, 35

   "LCPD-29636","j784s4-evm","TDA4VH: multi thread mutex usage causes kernel crash",""
   "LCPD-28142","am62xx-sk,j784s4-evm","Automated performance testing - spec2k6 benchmark test broken",""
   "LCPD-28317","j721e-evm,j721e-hsevm","GStreamer pipeline with decoder and fakesink causes kernel crash",""
   "LCPD-27522","j721e-idk-gw","Multi Stream decode fails",""
   "LCPD-25598","j721s2-evm","Wave5: Dynamic SRAM configuration in upstream driver",""
   "LCPD-29521","j721e-evm,j784s4-evm","R5 remote proc load does'nt guarentee CPU0 vs CPU1 sequencing",""
   "LCPD-28791","j784s4-evm,j784s4-hsevm","AHP GFX performance regression compaired to AEP",""
   "LCPD-28511","j721e-evm,j721e-hsevm,j721s2-evm,j721s2-hsevm,j784s4-evm,j784s4-hsevm","GPU cache coherency issues",""
   "LCPD-24589","am335x-evm,am57xx-evm,j721e-idk-gw","no new usb reported on host after g_multi ",""
   "LCPD-19497","j7200-evm","J7200: CPSW2g: interface goes up and down sporadically","Seen only on very few EVMs. No workaround. "
   "LCPD-17814","j721e-idk-gw","Kingston 16G card could not boot to uboot prompt",""
   "LCPD-29737","j7200-evm","J7200: Watchdog reset test fails",""
   "LCPD-29714","j721e-idk-gw","iperf hangs during crypto performance testing",""
   "LCPD-29705","j7200-evm","J7200: DT compile time warnings",""
   "LCPD-29554","j721e-idk-gw,j7200-evm","EEPROM Header Unidentified Board",""
   "LCPD-29525","j7200-evm,j7200-hsevm","Documentation for MCAN missing in the SDK",""
   "LCPD-28645","j721e-idk-gw","k3conf wrong frequencies",""
   "LCPD-29599","j721e-idk-gw,j721s2-evm,j7200-evm,j784s4-evm","Stream_1 benchmark executable missing",""
   "LCPD-24720","j721e-idk-gw","Order 4 SR1.1 j721e-idk-boards and replace SR1.0 boards in the farm",""
   "LCPD-24686","j721e-idk-gw","j721e-idk-gw: ETH-CPSW2G test fail due to wrong return code",""
   "LCPD-24648","am335x-evm,am572x-idk,am64xx-evm,dra71x-evm,j721e-evm,j7200-evm","Move dma-heaps-test and ion-tests to TI repositories",""
   "LCPD-24629","j721e-idk-gw","j721e-idk-gw Weston Keyboard Test Capability Gap NR (Impact 1)",""
   "LCPD-24597","j721e-idk-gw","j721e-idk-gw PCI_PERF tests report bad numbers (Impact 2)",""
   "LCPD-20331","am64xx-evm,am64xx-sk,j7200-evm","Farm: j7200-evm/k3-am642-evm/k3-am642-sk DT blob has to be passed manually",""
   "LCPD-17398","j721e-evm,j721e-evm-ivi,j721e-idk-gw","J7 Beta board hangs and cannot power cycle via automation interface",""
   "LCPD-16909","dra7xx-evm,j721e-evm,j721e-idk-gw","Linux performance guide:  CPU load is not captured, incorrect throughput numbers for ethernet ",""
   "LCPD-24619","j721e-idk-gw","Bitbake fails in different timezone",""
   "LCPD-29721","j721e-evm,j721e-idk-gw","SDK: Linux: Kernel crashes with Intel PCIe WiFi Card",""
   "LCPD-29680","j721e-evm,j721e-evm-ivi,j721e-idk-gw,j7200-evm","vxe_enc_probe warning observed while booting with debug options enabled",""
   "LCPD-29634","j721s2-evm","Need to include codec maximum capabilities in SDK documentation",""
   "LCPD-29320","j721e-idk-gw","The H.264 profile in the IMG video encoder driver is hardcoded to Base profile.",""
   "LCPD-25619","j721s2-evm","Wave5: Encoded output, mplayer warnings",""
   "LCPD-24475","j721e-idk-gw","Performance of H.265 decoder is poor",""
   "LCPD-17138","j721e-idk-gw","Kernel warning reported during h264 video encode operations",""
   "LCPD-28946","j721e-evm,j7200-evm","remoteproc hangs during booting sporadically",""
   "LCPD-25322","j7200-evm","Docs: J7200: Improve the IPC chapter for ti-rpmsg-char",""
   "LCPD-25321","j721e-evm,j721e-evm-ivi,j721e-idk-gw","Docs: J721E: Improve the IPC chapter for ti-rpmsg-char",""
   "LCPD-24456","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am62axx-sk,am62xx-hsevm,am62xx-sk,am62xx-vlab,am62xx-zebu,am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j7ae-evm,j7ae-zebu,j7aep-zebu,j7am-evm,j7am-vlab,j7am-zebu,j7amp-vlab,j7amp-zebu,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk,j721e-vlab,j721s2-evm,j721s2-hsevm,j7200-evm,j7200-hsevm,j7amp-evm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm,k2l-hsevm,omapl138-lcdk","Move IPC validation source from github to git.ti.com",""
   "LCPD-17284","j721e-evm,j721e-evm-ivi,j721e-idk-gw","remoteproc/k3-r5: Cores are started out-of-order when core 0 file size >> core 1 file size",""
   "LCPD-16545","j721e-evm,j721e-evm-ivi,j721e-idk-gw","remoteproc/k3-r5f: PDK IPC echo_test image fails to boot up in remoteproc mode on second run",""
   "LCPD-16535","j721e-evm,j721e-evm-ivi,j721e-idk-gw","remoteproc/k3-dsp: PDK IPC echo test binaries fails to do IPC in remoteproc mode on second run",""
   "LCPD-25662","am62xx-sk,j721e-evm,j7200-evm","Remove SGX PVR tools from KS3 devices",""
   "LCPD-25221","j721e-idk-gw"," j721e-idk-gw failing Glmark2-DRM Test (Impact 1)",""
   "LCPD-22972","j721e-idk-gw","j721e-idk-gw GLBenchmark GLB25_EgyptTestStandardOffscreen_inherited test ",""
   "LCPD-22921","j721e-idk-gw","j721e PVR profiling with PVRPerfServer test is failing",""
   "LCPD-19894","j721e-idk-gw,j721s2-evm,j784s4-evm","UYVY texture test fails due to internal data stream error",""
   "LCPD-19716","j721e-idk-gw","GFX_XS_FUNC_UYVY_TEXTURE test fails",""
   "LCPD-24127","am654x-evm,j721e-idk-gw","AM654x IPSEC Software Crypto tests fail (Impact 4)",""
   "LCPD-28485","j7200-evm","j7200: Segmentation fault during reload PCIe driver.",""
   "LCPD-28433","j721s2-evm","PCIe EP: DMA test fail",""
   "LCPD-28087","j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw","emmc: using RPMB panicks the TA on High speed mode",""
   "LCPD-25304","j721s2-evm","J7AEP: USB: USB 3.0 devices not getting enumerated in high speed",""
   "LCPD-25112","am64xx-evm,j721e-idk-gw","Ethernet driver not gating its clock when interface is down",""
   "LCPD-24798","am654x-evm,am654x-idk,j721e-idk-gw,j7200-evm","j721e-idk-gw, j7200-evm UART tests fail (Impact 3.0)",""
   "LCPD-24725","j721e-idk-gw","PCIE RC Link fails when linux prints are made quiet",""
   "LCPD-24690","am62xx-sk,am64xx-evm,am64xx-sk,j721s2-evm,j7200-evm","Kernel: SDK: Set HIGH_SPEED_EN for MMC1 instance",""
   "LCPD-24595","am64xx-evm,am64xx-sk,j721e-idk-gw,j721e-sk,j7200-evm","j721e-idk-gw USB Suspend/Resume with RTC Wakeup fail (Impact 1)",""
   "LCPD-24491","j721e-evm,j721e-evm-ivi,j721e-idk-gw,j7200-evm","Docs: MMC/SD supported modes not documented properly for J721E/J7200",""
   "LCPD-22905","am654x-evm,j721e-idk-gw","UDMA: TR15 hangs if ICNT0 is less than 64 bytes",""
   "LCPD-22413","j7200-evm","Hyperflash tests fail ~50% of the time on j7200",""
   "LCPD-20240","j721e-idk-gw,j721e-sk","MMC Modular testcase regression",""
   "LCPD-19659","j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm","Doc: PCIe: Update documentation to indicate how to move to compliance mode",""
   "LCPD-19499","j7200-evm,j7200-hsevm","Kernel: OSPI write throughput is less than 1MB/s",""
   "LCPD-19084","j721e-idk-gw","Few SD cards not enumerating in Kernel with Alpha EVM",""
   "LCPD-17794","j721e-idk-gw","ext4write failed to write firmware to SD card",""
   "LCPD-17421","j721e-idk-gw","CPSW9G: Can't bring up interface over NFS",""
   "LCPD-17172","j721e-idk-gw","Uboot USBhost: Sandisk Extreme USB 3.0 msc stick could not be detected at second time",""
   "LCPD-17171","j721e-idk-gw","Uboot dhcp occasionally failed",""
   "LCPD-17113","j721e-idk-gw","[Cpsw9g][VirtualDriver][VirtualMAC] rpmsg_kdrv_switch is not autoloaded",""
   "LCPD-16640","j721e-idk-gw","PCIe RC: GIC ITS misbehaves when more than 4 devices use it simultaneously",""
   "LCPD-16396","j721e-evm,j721e-evm-ivi,j721e-idk-gw","J721E: RC: Unsupported request in configuration completion packets results in an abort","Workaround for Multifunction: Configure all the physical functions supported by the endpoint. For configuring all the 6 functions of PCIe  controller instance '1' in J721E, the following can be used. mount -t configfs none /sys/kernel/config; cd /sys/kernel/config/pci_ep/; mkdir functions/pci_epf_test/func1; echo 0x104c > functions/pci_epf_test/func1/vendorid; echo 0xb00d > functions/pci_epf_test/func1/deviceid; echo 1 > functions/pci_epf_test/func1/msi_interrupts; echo 16 > functions/pci_epf_test/func1/msix_interrupts; ln -s functions/pci_epf_test/func1 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func2; echo 0x104c > functions/pci_epf_test/func2/vendorid; echo 0xb00d > functions/pci_epf_test/func2/deviceid; echo 1 > functions/pci_epf_test/func2/msi_interrupts; echo 16 > functions/pci_epf_test/func2/msix_interrupts; ln -s functions/pci_epf_test/func2 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func3; echo 0x104c > functions/pci_epf_test/func3/vendorid; echo 0xb00d > functions/pci_epf_test/func3/deviceid; echo 1 > functions/pci_epf_test/func3/msi_interrupts; echo 16 > functions/pci_epf_test/func3/msix_interrupts; ln -s functions/pci_epf_test/func3 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func4; echo 0x104c > functions/pci_epf_test/func4/vendorid; echo 0xb00d > functions/pci_epf_test/func4/deviceid; echo 1 > functions/pci_epf_test/func4/msi_interrupts; echo 16 > functions/pci_epf_test/func4/msix_interrupts; ln -s functions/pci_epf_test/func4 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func5; echo 0x104c > functions/pci_epf_test/func5/vendorid; echo 0xb00d > functions/pci_epf_test/func5/deviceid; echo 1 > functions/pci_epf_test/func5/msi_interrupts; echo 16 > functions/pci_epf_test/func5/msix_interrupts; ln -s functions/pci_epf_test/func5 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func6; echo 0x104c > functions/pci_epf_test/func6/vendorid; echo 0xb00d > functions/pci_epf_test/func6/deviceid; echo 1 > functions/pci_epf_test/func6/msi_interrupts; echo 16 > functions/pci_epf_test/func6/msix_interrupts; ln -s functions/pci_epf_test/func6 controllers/d800000.pcie-ep/; echo 1 > controllers/d800000.pcie-ep/start; echo 1 > /sys/bus/pci/devices/0000:00:00.0/remove; echo 1 > /sys/bus/pci/rescan; Workaround for switch card: No workarounds available."
   "LCPD-16031","j721e-evm,j721e-evm-ivi,j721e-idk-gw","J721e: PCIe: Legacy interrupts do not work",""
   "LCPD-29740","j721e-idk-gw","j721e-idk-gw:  EMMC_DD_RW_500M test fail",""
   "LCPD-29729","j721e-idk-gw,j7200-evm","j721e-idk-gw, j7200-evm  MMC_M_MODULAR_SDHC_MULTI tests fail",""
   "LCPD-29648","j7200-evm","Failure logs during boot: Failed unmounting /var/lib & /var/volatile ",""
   "LCPD-29647","j7200-evm","Non-fatal failure logs seen during system boot up",""
   "LCPD-29646","am62xx-sk,j721e-idk-gw","Failure logs during boot:  Failed to get MSI domain",""
   "LCPD-29645","j784s4-evm","MMC: SD Card doesn't go into SDR104 mode",""
   "LCPD-29644","j784s4-evm","MMC: SD Card doesn't go into DDR50 mode",""
   "LCPD-29528","am62xx-sk,am64xx-evm,am64xx-hsevm,am64xx-sk,am64xx-hssk,j721e-idk-gw,j721s2-evm,j721s2-hsevm,j7200-evm,j7200-hsevm,j784s4-evm","k3: integration: sdk: missing tag info for optee and atf projects",""
   "LCPD-28861","j721e-evm,j7200-evm","J721e/j7200: MCU/WKUP UART as console. The output gets garbled after sysfw/dm load ",""
   "LCPD-28250","j721s2-evm","J7AEP: QSPI Write corrupted when the first operation after powerup is erase",""
   "LCPD-25692","j721s2-evm,j721s2-hsevm","linux needs to identify J7ES PG1.1 correctly",""
   "LCPD-25686","j721s2-evm,j721s2-hsevm","k3conf needs to identify J7ES PG1.1 correctly",""
   "LCPD-25262","j721s2-evm","j721s2-evm : cpuhotplug06 fails  ",""
   "LCPD-25195","j721s2-evm","j721s2-evm: audio device is not found",""
   "LCPD-23010","j721e-idk-gw","j721e-idk-gw stress boot test files",""
   "LCPD-22715","j721e-idk-gw,j7200-evm,j721s2-evm,am62xx-evm","i2232: DDR: Controller postpones more than allowed refreshes after frequency change","Workaround 1:
   Disable dynamic frequency change by programing DFS_ENABLE = 0


      DFS_ENABLE = 0


   Workaround 2:
   If switching frequency, program the register field values as follows::

      if (old_freq/new_freq >= 7) {
         if (PBR_EN==1) {  // Per-bank refresh is enabled
               AREF_HIGH_THRESHOLD = 19
               AREF_NORM_THRESHOLD = 18
               AREF_PBR_CONT_EN_THRESHOLD = 1
               AREF_CMD_MAX_PER_TREF = 8
         }
         else {  // Per-bank refresh is disabled
               AREF_HIGH_THRESHOLD = 18
               AREF_NORM_THRESHOLD = 17
               AREF_CMD_MAX_PER_TREF = 8
         }
      } else {
         AREF_HIGH_THRESHOLD = 21
         AREF_CMD_MAX_PER_TREF = 8
      }
   "
   "LCPD-22319","am64xx-evm,j7200-evm","OpenSSL performance test data out of bounds",""
   "LCPD-20653","am335x-evm,am43xx-gpevm,am654x-idk,j721e-idk-gw","ltp: kernel syscall tests fail",""
   "LCPD-19792","j721e-idk-gw","j721e boot fails sometimes due to EL1 exception",""
   "LCPD-18860","am654x-evm,am654x-idk,j721e-idk-gw,j7200-evm","isolcpus in the command line is not honored",""
   "LCPD-18684","am57xx-evm,am654x-evm,j721e-idk-gw","syscalls sync failures: fdatasync03, fsync04, sync03, syncfs01, sync_file_range02",""
   "LCPD-18258","am654x-evm,j721e-idk-gw","IPSEC perfomance failures",""
   "LCPD-17798","am654x-evm,am654x-idk,j7am-evm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-vlab,j7200-evm,j7200-hsevm","2020 LTS: INTA/INTR smp_affinity failure and IRQ allocation issues.",""
   "LCPD-17543","j721e-evm,j721e-evm-ivi,j721e-idk-gw","Some cpuhotplug tests failed",""
   "LCPD-24502","j721e-evm-ivi,j721e-idk-gw","j721e-evm-ivi Universal Planes fails (Impact 1)",""
   "LCPD-19068","j721e-evm,j721e-evm-ivi,j721e-idk-gw","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame",""
   "LCPD-17017","j721e-evm-ivi,j721e-idk-gw","J7: DSS underflows seen on various use cases",""
   "LCPD-25583","j721e-idk-gw","H264 Encode followed by decode not working for all resolutions in Gstreamer",""
   "LCPD-16531","j721e-idk-gw","video decode: vxd_dec warnings displayed at end of gstreamer hevc playback to kmssink for certain video",""
   "LCPD-25663","am62xx-sk,j721e-evm,j721s2-evm,j784s4-evm","Remove old IMG demo binaries  ",""
   "LCPD-22513","j721e-evm,j7200-evm","Update SDK doc to include OSPI flashing instruction using dfu-util",""
   "LCPD-18790","j721e-idk-gw","eMMC tests failed on J7 rev E2 EVM",""
   "LCPD-29755","j721e-idk-gw","j721e-idk-gw : Can Transmission and Reception Tests Fail",""
   "LCPD-29596","j721e-idk-gw","J721E: USBHOST: All boot attempts failed",""
   "LCPD-19743","j7200-evm,j7200-hsevm","Packages.gz is missing",""
   "LCPD-19739","am654x-idk,j7200-evm","AM65 shutdown error",""
   "LCPD-29781","j721s2-evm","CPU is hitting 100% when using gst-launch for both encode and decode",""
   "LCPD-29620","j721e-idk-gw","IMG Decoder not passing ITU-T Streams",""
   "LCPD-26692","am335x-evm,am43xx-gpevm,am57xx-evm,am64xx-evm,j721e-idk-gw","Hardware + Software IPSec Performance Test Failures",""
   "LCPD-22339","j721e-idk-gw,j7200-evm","PCI-E USBCARD, ETHCARD don't indicate 2-lane support with lspci",""
   "LCPD-29699","j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-sk","J721E tidss fails to keep in sync with displays requesting resolutions > 2k",""

|


Linux RT Kernel Known Issues
----------------------------

There are no known issues in this release in the Linux RT Kernel.
