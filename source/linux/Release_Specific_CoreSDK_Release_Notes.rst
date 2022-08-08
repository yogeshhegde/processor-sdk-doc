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

Release 08.04.00
==================

Released July 2022

.. rubric:: What's New
   :name: whats-new

Processor SDK 8.4 Release supports the following platforms:

- J721E
- J7200
- J721S2

Processor SDK 8.4 Release has following new features:

- Native Linux networking (CPSW)
- OSPI1 & Hyperflash boot
- J7AEP stability progress (mostly MM)
- J7VCL PG2.0

Build Information
=====================================

U-Boot
-------------------------
| Head Commit: a169f4261024397dd3ddb944decc1601a623df2a HACK: j721s2: QoS workaround for GPU cache incoherency
| Date: 25 Jul 2022 06:28 PM CDT
| uBoot Version: 2021.01
| uBoot Description: 08.04.00.005
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2021.01
| uBoot Tag: 08.04.00.005

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))

Kernel
-------------------------
.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 95b90aa828165df6c45d6bb0e1cce905e83a66a7 Merged TI feature connectivity into ti-linux-5.10.y
| Date: 22 Jul 2022 02:21 PM CDT
| Kernel Version: 5.10.120
| Kernel Description: 08.04.00.005

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.10.y
| Tag: 08.04.00.005
| Kernel defconfig: ti_sdk_arm64_release_defconfig

| Compiler Information:  arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: adb96c641cb03198db729962eb348ca1a16978e2 Merged TI feature ti_linux_base_rt into ti-rt-linux-5.10.y
| Date: 22 Jul 2022 02:57 PM CDT
| Kernel Version: 5.10.120
| Kernel Description: 08.04.00.005

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.10.y
| Tag: 08.04.00.005
| Kernel defconfig: ti_sdk_arm64_release_defconfig

| Compiler Information:  arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025

Yocto
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 762f4908189fcd5f62cb259767768534264d7702 linux-ti-staging-rt: Bump to 08.04.00.005 release
| Date: 2022-07-26
| Version: dunfell-3.1

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: 08.04.00.005

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: 28ab4e60678f0d54f552c3c7606ad76244dd0b5c ltp-ddt: Bump to 08.04.00.005 release
| Date: 2022-07-26
| Version: 2021.09

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: dunfell
| Release Tag: 08.04.00.005
|

Issues Tracker
=====================================

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-28108","J7200: cadence-mhdp-fw recipe should be machine dependent on j721e-evm only","j7200-evm"
   "LCPD-28094","SK-TDA4VM fails to boot with recent daily builds","j721e-sk"
   "LCPD-28034","J7ES/J721e: Issue in OSPI driver with Cypress flash","j721e-evm"
   "LCPD-27107","Upstream: Move ARM64 stack pointer for all K3 devices","am64xx-evm,am654x-evm,j721e-evm,j7200-evm,j721s2-evm"
   "LCPD-26695","Errors using DDK 1.15 with Linux kernel 5.10 for J7AEP","j721s2-evm"
   "LCPD-26641","K3: Move stack initialization address in arm64","am64xx-evm,am654x-evm,j721e-evm,j7200-evm,j721s2-evm,am62xx-sk"
   "LCPD-25661","GPU driver DDK 1.13 not supported on Linux kernel 5.10","j721e-evm"
   "LCPD-25597","Wave5: kmssink rendering has color space mismatch","j721s2-evm"
   "LCPD-25596","Wave5: CTRL-C results in rmmod/insmod being needed to reinitialize the driver","j721s2-evm"
   "LCPD-25595","Wave5: GStreamer End of File does not result in pipeline termination","j721s2-evm"
   "LCPD-25535","UBoot: customized ${optargs} doesn't take affect on K3 devices","am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm,j721e-evm,j721e-hsevm,j7200-evm,j7200-hsevm,j721s2-evm,j721s2-hsevm"
   "LCPD-25502","J721e/J7200/J7AEP: Add the missing UART instances clock/dev data","j721e-evm,j7200-evm,j721s2-evm"
   "LCPD-25491","j721e-idk-gw: CPSW2G Promisc failure","j721e-idk-gw"
   "LCPD-25317","A72 SPL: A72 SPL memcpy sluggish with 8.0/8.1 SDK","j721e-idk-gw"
   "LCPD-25305","J721e/J7200: Populate missing IDs in the j72xx_dst_ep_map","j721e-idk-gw,j7200-evm,j721s2-evm"
   "LCPD-25184","U-Boot: bootcmd is using invalid main_cpsw0_qsgmii_phyinit for J721S2","j721s2-evm"
   "LCPD-25075","J721E: revE8 SoM board doesn't boot consistently","j721e-idk-gw"
   "LCPD-24940","PSC driver to support up to 64 Power Domains","j721s2-evm"
   "LCPD-24871","J721E-SK: SPL: DFU boot test failed","j721e-sk"
   "LCPD-24722","clk_set_rate fails to set requested frequency in tidss driver","j721s2-evm"
   "LCPD-24511","ARM: A72/53 L1 data cache and L2 cache set counts wrong","am64xx-evm,am64xx-hsevm,am64xx-sk,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm"
   "LCPD-24507","U-Boot command ""saveenv"" doesn't save env ","am64xx-evm,am64xx-hsevm,am64xx-sk,j721e-idk-gw"
   "LCPD-24315"," ufs@4e84000:  fix warning","j721e-evm"
   "LCPD-24290","Decoder + kmssink elements generates pink and green frames blinking","j721e-idk-gw"
   "LCPD-24283","CSI2 10 bit raw capture does not work ","j721e-evm"
   "LCPD-24274","PCIe: Link up failure when unused lanes are not assigned to PCIe Controller","j721e-evm"
   "LCPD-24231","J721e: U-boot: QSPI: Read performance very low with 7.x & 8.0 SDK","j721e-evm"
   "LCPD-24115","j721e-idk-gw default mtdparts value in U-BOOT is wrong","j721e-idk-gw"
   "LCPD-23002","wic images for K3 HS images are broken","am654x-hsevm,j721e-hsevm"
   "LCPD-22964","U-Boot: PLL POSTDIV1 and POSTDIV2 clock parenting is reversed","j721e-evm,j721e-evm-ivi,j721e-idk-gw,j7200-evm"
   "LCPD-22861","Missing documentation for HS devices","j721e-hsevm"
   "LCPD-19858","OE: OPTEE label used in SDK is old and wrong","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am64xx-evm,am64xx-vlab,am64xx-zebu,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm,k2l-hsevm"
   "LCPD-16591","PCIe wifi ping stress test failed","j721e-idk-gw"

|


Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-28495","Incorrect clock assignment in main cpsw mdio node of j7200","j7200-evm,j7200-hsevm"
   "LCPD-28478","Display Connector port shows false active status","j721s2-evm"
   "LCPD-28419","Linux: All: AM65 CPSW driver fails to build w/o PHYLINK=y","j721e-idk-gw,am62xx-sk"
   "LCPD-28417","J7200 (rev < E7) fails to boot ","j7200-evm"
   "LCPD-28361","RMII mode not working with am65-cpsw driver","j721e-evm,j7200-evm"
   "LCPD-28349","j721s2-evm: no support in k3conf","j721s2-evm"
   "LCPD-28340","Yocto: viddec-test and videnc-test recipes are IMG encoder specific - disable for j721s2/am62a etc","j721e-evm,j721s2-evm"
   "LCPD-28325","kernel crashes if CONFIG_DEBUG_FS is not set","am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm,j7am-evm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm,j721s2-evm,j721s2-hsevm,am62xx-sk,am62xx-hsevm"
   "LCPD-28316","Documentation for tidec_decode should clearly limit the support to raw streams (no container formats)","j721e-evm,j721e-hsevm"
   "LCPD-28308","u-boot: build broken for j721e_hs_evm_a72_defconfig","j721e-hsevm"
   "LCPD-28294","j721s2-hs: fitImage not found at the uboot prompt","j721s2-hsevm"
   "LCPD-28260","j721s2-hs: OSPI Boot Mode hangs as system raises firewall exception","j721s2-hsevm"
   "LCPD-28227","v5.19-rc1: devm_spi_release_controller refcount issue","am654x-evm,j721e-evm"
   "LCPD-28179","Fix DFU Env variable for flashing combined bootloader images","am64xx-evm,j7200-evm"
   "LCPD-28178","wic images for K3 HS images are broken","am64xx-hsevm,am654x-hsevm,j721e-hsevm,j7200-hsevm,j721s2-hsevm,am62xx-hsevm"

|

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 150

   "LCPD-24274","j721e-evm","PCIe: Link up failure when unused lanes are not assigned to PCIe Controller"
   "LCPD-22544","j7200-evm","DDR: LPDDR4 should be configured to 2666 MT/S"
   "LCPD-19965","am64xx-evm,am654x-idk,j721e-idk-gw,j7200-evm","OSPI PHY Controller Bug Affecting Read Transactions"
   "LCPD-19068","j721e-evm,j721e-evm-ivi,j721e-idk-gw","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame"
   "LCPD-19047","j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw","USB: Race condition while reading TRB from system memory in device mode"
   "LCPD-18980","j721e-evm","PCIe: Gen2 capable endpoint devices always enumerate as Gen1"
   "LCPD-17220","j721e-idk-gw","U-Boot Hyperbus: Hyperflash reads limited to 125MHz max. frequency"
   "LCPD-16605","j721e-evm,j721e-evm-ivi,j721e-idk-gw","MMC: MMC1/2 Speed Issue"

|

SDK Known Issues
-----------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-28511","j721s2-evm","GPU cache coherency issues",""
   "LCPD-28509","j721s2-evm,j784s4-evm","WAVE5: MultiStream Decode/Encode > 2 channel fails ",""
   "LCPD-28474","j721e-sk","libthread_db and libpthread version mismatch does not allow GDB debug of multi-thread",""
   "LCPD-28465","j721s2-evm,j721s2-hsevm","Automated test failure - KICKSYNC SYNCCONTEXTLOOP failed due to change in command line arguments",""
   "LCPD-28412","j721s2-evm","UYVY texture format not supported",""
   "LCPD-28411","j721s2-evm","Active power management causes kernel panic",""
   "LCPD-28317","j721e-evm,j721e-hsevm","GStreamer pipeline with decoder and fakesink causes kernel crash",""
   "LCPD-28315","j721e-evm","tidec_decode causes a kernel crash when used with container fileformats",""
   "LCPD-28245","j721s2-evm","Decoder framerate drops below 30FPS for >2 channels for 1080p",""
   "LCPD-28243","j7200-evm","core-image-minimal build fails for j7200-evm with rm_work enabled",""
   "LCPD-28123","j721e-evm","Encoder framerate drops below 30FPS for 2 or more channels of 1920x1080",""
   "LCPD-28118","j721e-evm","RGBA Encode throws timeout error for 720x512 resolution",""
   "LCPD-28019","j721e-evm","TDA4VM: Kernel panic caused by H265 decoder crash",""
   "LCPD-27522","j721e-idk-gw","Multi Stream decode fails",""
   "LCPD-25670","j721s2-evm","tisdk-tiny-image does not boot for J721S2",""
   "LCPD-25663","j721e-evm,j721s2-evm,j784s4-evm,am62xx-sk","Remove old IMG demo binaries  ",""
   "LCPD-25662","j721e-evm,j7200-evm,am62xx-sk","Remove SGX PVR tools from KS3 devices",""
   "LCPD-25619","j721s2-evm","Wave5: Encoded output, mplayer warnings",""
   "LCPD-25598","j721s2-evm","Wave5: Dynamic SRAM configuration in upstream driver",""
   "LCPD-25583","j721e-idk-gw","H264 Encode followed by decode not working for all resolutions in Gstreamer",""
   "LCPD-25538","j721e-evm","Unable to extract header info with Decoder Standalone Test application",""
   "LCPD-25332","j721e-idk-gw","J721e Failing Video test",""
   "LCPD-25330","j721e-evm","Video seek feature breaks with buffer import patch",""
   "LCPD-25221","j721e-idk-gw"," j721e-idk-gw failing Glmark2-DRM Test (Impact 1)",""
   "LCPD-24733","j721e-sk","Gstreamer video decode test failing for H.264",""
   "LCPD-24619","j721e-idk-gw","Bitbake fails in different timezone",""
   "LCPD-24475","j721e-idk-gw","Performance of H.265 decoder is poor",""
   "LCPD-24099","j721e-evm","v4l2h264dec, v4l2h264enc, v4l2h265dec: Codec Allocates much more space than required in Linux",""
   "LCPD-22972","j721e-idk-gw","j721e-idk-gw GLBenchmark GLB25_EgyptTestStandardOffscreen_inherited test ",""
   "LCPD-22921","j721e-idk-gw","j721e PVR profiling with PVRPerfServer test is failing",""
   "LCPD-19948","am57xx-evm,am654x-evm,j721e-evm","Yocto: stream recipe is incorrect",""
   "LCPD-19894","j721e-idk-gw","UYVY texture test fails due to internal data stream error",""
   "LCPD-19743","j7200-evm,j7200-hsevm","Packages.gz is missing",""
   "LCPD-19716","j721e-idk-gw","GFX_XS_FUNC_UYVY_TEXTURE test fails",""
   "LCPD-16531","j721e-idk-gw","video decode: vxd_dec warnings displayed at end of gstreamer hevc playback to kmssink for certain video",""
   "LCPD-16454","j721e-evm","DSS underflows with 1080p/2.5k display on inmate cell",""
   "LCPD-16366","j721e-evm,j721e-evm-ivi,j721e-idk-gw","RGX kick test fails when 32 sync dependencies are set for each command",""

|


U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-28387","j721e-evm,j7200-evm,j721s2-evm","J721e/J7200/J721s2: Add the missing UART instances clock/dev data",""
   "LCPD-28206","j721e-idk-gw","j721: sdhci0: Capabilities offered in U-Boot Vs Kernel dts are different",""
   "LCPD-25263","j721s2-evm","j721s2-evm: U-Boot USBHOST: Superspeed test is failing",""
   "LCPD-24824","j7200-evm","J7200/VCL: u-boot SPL code configuring the SOC DDR PLL (PLL12) incorrectly. Desired boot frequency is 27.5 MHz",""
   "LCPD-24108","j721e-evm,j721e-evm-ivi,j721e-idk-gw","U-Boot: TISCI config ring fail traces seen in OSPI boot mode on J721E",""
   "LCPD-22904","j721e-idk-gw,j7200-evm","U-boot: Update EMIFtool for i2244:DDR: Valid stop value must be defined for write DQ VREF training",""
   "LCPD-22512","j721e-evm,j7200-evm","Update dfu_alt_info_ospi to include flashing of PHY tuning data",""
   "LCPD-22452","j721e-evm","u-boot README doesn't have eMMC specific documentation for J7ES",""
   "LCPD-22451","j721e-evm","Documentation on J7ES Boot flow refers to AM65xx Boot flow in the u-boot user guide",""
   "LCPD-19871","j721e-idk-gw,j7200-evm","U-boot: Documentation: Combined Boot flow and SPL Rearch",""
   "LCPD-19776","j721e-idk-gw","j7: uboot: some socketed evms fail to boot",""
   "LCPD-17789","j721e-idk-gw","UBOOT J7:  Could not see UFS device by scsi scan",""
   "LCPD-17523","j721e-evm,j721e-idk-gw,j7200-evm","A72-SPL - Support to dump EEPROM to shared memory",""

|


Linux Kernel Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround" 
   :widths: 5, 10, 70, 35

   "LCPD-28663","j721e-idk-gw","Pauses in video being displayed when input video is read from SD card",""
   "LCPD-28502","j721e-idk-gw","MMC I/O latency is causing audio UNDERRUN issues",""
   "LCPD-28485","j7200-evm","j7200: Segmentation fault during reload PCIe driver.",""
   "LCPD-28480","j721e-evm","J721E: USB super speed gadget mode: PC does not detect device",""
   "LCPD-28433","j721s2-evm","PCIe EP: DMA test fail",""
   "LCPD-28432","j7200-evm","DRA821: PCIe: Segmentation fault",""
   "LCPD-28385","j721e-evm","SPI Master RX Transfer Hangs in Full Duplex Mode with UDMA",""
   "LCPD-28314","j721e-evm","SDK: CPSW9G: GESI Card interface eth1: packet loss observed",""
   "LCPD-28250","j721s2-evm","J7AEP: QSPI Write corrupted when the first operation after powerup is erase",""
   "LCPD-28247","j721e-evm","J721e: Ethernet driver crash while running iperf3 after about 6+ hrs",""
   "LCPD-28246","j7200-evm","J7200/J7VCL: Linux crash when we cat pinctrl debugfs node",""
   "LCPD-28182","j721e-sk","Add support for simultaneous use of RPi camera and Rpi extension header",""
   "LCPD-28087","j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw","emmc: using RPMB panicks the TA on High speed mode",""
   "LCPD-27948","j7200-evm","TSN: PTP test fails with J7200 in switch mode (acting as a transparent clock)",""
   "LCPD-26728","j721e-idk-gw,j721e-sk","J721e: Watchdog reset fails on newer SoMs",""
   "LCPD-25692","j721s2-evm,j721s2-hsevm","linux needs to identify J7ES PG1.1 correctly",""
   "LCPD-25686","j721s2-evm,j721s2-hsevm","k3conf needs to identify J7ES PG1.1 correctly",""
   "LCPD-25670","j721s2-evm","tisdk-tiny-image does not boot for J721S2",""
   "LCPD-25629","j721e-evm","networking - dunfell systemd behaves differently than older SDK's",""
   "LCPD-25564","j721s2-evm,am62xx-sk","J721s2-evm: CPSW2g: interface goes up and down sporadically","Seen only on very few EVMs. No workaround. "
   "LCPD-25512","j721e-evm","TSN (EST) : Reduced Bandwidth observed on ports 5002, 5003 with increase in test bandwidth",""
   "LCPD-25469","j721e-idk-gw","j721e USB OTG HOST regressions on eptf126",""
   "LCPD-25322","j7200-evm","Docs: J7200: Improve the IPC chapter for ti-rpmsg-char",""
   "LCPD-25321","j721e-evm,j721e-evm-ivi,j721e-idk-gw","Docs: J721E: Improve the IPC chapter for ti-rpmsg-char",""
   "LCPD-25304","j721s2-evm","J7AEP: USB: USB 3.0 devices not getting enumerated in high speed",""
   "LCPD-25262","j721s2-evm","j721s2-evm : cpuhotplug06 fails  ",""
   "LCPD-25195","j721s2-evm","j721s2-evm: audio device is not found",""
   "LCPD-25187","j721e-idk-gw","ATF: Support PSCI call for system reset",""
   "LCPD-25112","am64xx-evm,j721e-idk-gw","Ethernet driver not gating its clock when interface is down",""
   "LCPD-24798","am654x-evm,am654x-idk,j721e-idk-gw,j7200-evm","j721e-idk-gw, j7200-evm UART tests fail (Impact 3.0)",""
   "LCPD-24725","j721e-idk-gw","PCIE RC Link fails when linux prints are made quiet",""
   "LCPD-24690","am64xx-evm,am64xx-sk,j7200-evm,j721s2-evm,am62xx-sk","Kernel: SDK: Set HIGH_SPEED_EN for MMC1 instance",""
   "LCPD-24677","j721e-idk-gw","j721e-idk-gw PCI WIFI Tests Fail due to iperf issues(Impact 1)",""
   "LCPD-24595","am64xx-evm,am64xx-sk,j721e-idk-gw,j7200-evm,j721e-sk","j721e-idk-gw USB Suspend/Resume with RTC Wakeup fail (Impact 1)",""
   "LCPD-24589","am335x-evm,am57xx-evm,j721e-idk-gw","no new usb reported on host after g_multi ",""
   "LCPD-24502","j721e-evm-ivi,j721e-idk-gw","j721e-evm-ivi Universal Planes fails (Impact 1)",""
   "LCPD-24491","j721e-evm,j721e-evm-ivi,j721e-idk-gw,j7200-evm","Docs: MMC/SD supported modes not documented properly for J721E/J7200",""
   "LCPD-24456","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am64xx-evm,am64xx-hsevm,am64xx-sk,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j7am-evm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-vlab,j7200-evm,j7200-hsevm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm,k2l-hsevm,omapl138-lcdk,j721s2-evm,j721s2-hsevm,j7amp-evm,j7ae-evm,j7am-vlab,j7am-zebu,j7ae-zebu,j7aep-zebu,j7amp-vlab,j7amp-zebu,j721e-sk,am62xx-sk,am62xx-hsevm,am62xx-vlab,am62xx-zebu,am62a-sk","Move IPC validation source from github to git.ti.com",""
   "LCPD-24198","j721e-sk","J721e-sk stress boot test fails",""
   "LCPD-24142","j721e-evm,j721e-hsevm,j721e-idk-gw","J721e: Issue with OSPI probe in kernel when booting from OSPI boot mode",""
   "LCPD-24125","j721e-idk-gw","j721e-idk-gw all LE play + record tests fail (Impact 7.0)",""
   "LCPD-23010","j721e-idk-gw","j721e-idk-gw stress boot test files",""
   "LCPD-22760","j721e-evm","k3conf: Register read leads to kernel crash",""
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
   "LCPD-22513","j721e-evm,j7200-evm","Update SDK doc to include OSPI flashing instruction using dfu-util",""
   "LCPD-22487","j721e-evm","USB: usb0 doesn't work properly in host only mode",""
   "LCPD-22413","j7200-evm","Hyperflash tests fail ~50% of the time on j7200",""
   "LCPD-22339","j721e-idk-gw,j7200-evm","PCI-E USBCARD, ETHCARD don't indicate 2-lane support with lspci",""
   "LCPD-22319","am64xx-evm,j7200-evm","OpenSSL performance test data out of bounds",""
   "LCPD-20653","am335x-evm,am43xx-gpevm,am654x-idk,j721e-idk-gw","ltp: kernel syscall tests fail",""
   "LCPD-20290","j721e-idk-gw","CPSW Performance regression on j721e-idk-gw",""
   "LCPD-20240","j721e-idk-gw,j721e-sk","MMC Modular testcase regression",""
   "LCPD-19792","j721e-idk-gw","j721e boot fails sometimes due to EL1 exception",""
   "LCPD-19659","j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm","Doc: PCIe: Update documentation to indicate how to move to compliance mode",""
   "LCPD-19499","j7200-evm,j7200-hsevm","Kernel: OSPI write throughput is less than 1MB/s",""
   "LCPD-19497","j7200-evm","J7200: CPSW2g: interface goes up and down sporadically","Seen only on very few EVMs. No workaround. "
   "LCPD-19084","j721e-idk-gw","Few SD cards not enumerating in Kernel with Alpha EVM",""
   "LCPD-19068","j721e-evm,j721e-evm-ivi,j721e-idk-gw","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame",""
   "LCPD-18860","am654x-evm,am654x-idk,j721e-idk-gw","isolcpus in the command line is not honored",""
   "LCPD-18790","j721e-idk-gw","eMMC tests failed on J7 rev E2 EVM",""
   "LCPD-18684","am57xx-evm,am654x-evm,j721e-idk-gw","syscalls sync failures: fdatasync03, fsync04, sync03, syncfs01, sync_file_range02",""
   "LCPD-18258","am654x-evm,j721e-idk-gw","IPSEC perfomance failures",""
   "LCPD-17814","j721e-idk-gw","Kingston 16G card could not boot to uboot prompt",""
   "LCPD-17798","am654x-evm,am654x-idk,j7am-evm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-vlab,j7200-evm,j7200-hsevm","2020 LTS: INTA/INTR smp_affinity failure and IRQ allocation issues.",""
   "LCPD-17794","j721e-idk-gw","ext4write failed to write firmware to SD card",""
   "LCPD-17673","am335x-evm,am43xx-gpevm,am571x-idk,am572x-idk,am574x-idk,am57xx-evm,am654x-evm,beaglebone-black,dra71x-evm,dra72x-evm,dra7xx-evm,j721e-evm","No software documentation for the Timer module",""
   "LCPD-17543","j721e-evm,j721e-evm-ivi,j721e-idk-gw","Some cpuhotplug tests failed",""
   "LCPD-17421","j721e-idk-gw","CPSW9G: Can't bring up interface over NFS",""
   "LCPD-17284","j721e-evm,j721e-evm-ivi,j721e-idk-gw","remoteproc/k3-r5: Cores are started out-of-order when core 0 file size >> core 1 file size",""
   "LCPD-17172","j721e-idk-gw","Uboot USBhost: Sandisk Extreme USB 3.0 msc stick could not be detected at second time",""
   "LCPD-17171","j721e-idk-gw","Uboot dhcp occasionally failed",""
   "LCPD-17113","j721e-idk-gw","[Cpsw9g][VirtualDriver][VirtualMAC] rpmsg_kdrv_switch is not autoloaded",""
   "LCPD-17017","j721e-evm-ivi,j721e-idk-gw","J7: DSS underflows seen on various use cases",""
   "LCPD-17006","j721e-evm","4k DP Display Shows Blank Screen sometimes when booting",""
   "LCPD-16640","j721e-idk-gw","PCIe RC: GIC ITS misbehaves when more than 4 devices use it simultaneously",""
   "LCPD-16545","j721e-evm,j721e-evm-ivi,j721e-idk-gw","remoteproc/k3-r5f: PDK IPC echo_test image fails to boot up in remoteproc mode on second run",""
   "LCPD-16535","j721e-evm,j721e-evm-ivi,j721e-idk-gw","remoteproc/k3-dsp: PDK IPC echo test binaries fails to do IPC in remoteproc mode on second run",""
   "LCPD-16505","j721e-evm","Wrong clock rate is reported for 157:400, 157:401 (HSDIVIDER after PLL4 and 15)",""
   "LCPD-16454","j721e-evm","DSS underflows with 1080p/2.5k display on inmate cell",""
   "LCPD-16396","j721e-evm,j721e-evm-ivi,j721e-idk-gw","J721E: RC: Unsupported request in configuration completion packets results in an abort","Workaround for Multifunction: Configure all the physical functions supported by the endpoint. For configuring all the 6 functions of PCIe  controller instance '1' in J721E, the following can be used. mount -t configfs none /sys/kernel/config; cd /sys/kernel/config/pci_ep/; mkdir functions/pci_epf_test/func1; echo 0x104c > functions/pci_epf_test/func1/vendorid; echo 0xb00d > functions/pci_epf_test/func1/deviceid; echo 1 > functions/pci_epf_test/func1/msi_interrupts; echo 16 > functions/pci_epf_test/func1/msix_interrupts; ln -s functions/pci_epf_test/func1 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func2; echo 0x104c > functions/pci_epf_test/func2/vendorid; echo 0xb00d > functions/pci_epf_test/func2/deviceid; echo 1 > functions/pci_epf_test/func2/msi_interrupts; echo 16 > functions/pci_epf_test/func2/msix_interrupts; ln -s functions/pci_epf_test/func2 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func3; echo 0x104c > functions/pci_epf_test/func3/vendorid; echo 0xb00d > functions/pci_epf_test/func3/deviceid; echo 1 > functions/pci_epf_test/func3/msi_interrupts; echo 16 > functions/pci_epf_test/func3/msix_interrupts; ln -s functions/pci_epf_test/func3 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func4; echo 0x104c > functions/pci_epf_test/func4/vendorid; echo 0xb00d > functions/pci_epf_test/func4/deviceid; echo 1 > functions/pci_epf_test/func4/msi_interrupts; echo 16 > functions/pci_epf_test/func4/msix_interrupts; ln -s functions/pci_epf_test/func4 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func5; echo 0x104c > functions/pci_epf_test/func5/vendorid; echo 0xb00d > functions/pci_epf_test/func5/deviceid; echo 1 > functions/pci_epf_test/func5/msi_interrupts; echo 16 > functions/pci_epf_test/func5/msix_interrupts; ln -s functions/pci_epf_test/func5 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func6; echo 0x104c > functions/pci_epf_test/func6/vendorid; echo 0xb00d > functions/pci_epf_test/func6/deviceid; echo 1 > functions/pci_epf_test/func6/msi_interrupts; echo 16 > functions/pci_epf_test/func6/msix_interrupts; ln -s functions/pci_epf_test/func6 controllers/d800000.pcie-ep/; echo 1 > controllers/d800000.pcie-ep/start; echo 1 > /sys/bus/pci/devices/0000:00:00.0/remove; echo 1 > /sys/bus/pci/rescan; Workaround for switch card: No workarounds available."
   "LCPD-16208","j721e-evm","FIFO Underflows during video playback on 4k panel",""

|


Linux RT Kernel Known Issues
----------------------------

There are no known issues in this release in the Linux RT Kernel.
