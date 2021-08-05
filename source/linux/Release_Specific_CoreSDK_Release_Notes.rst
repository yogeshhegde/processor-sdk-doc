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

Release 08.00.00
==================

Released July 2021

.. rubric:: What's New
   :name: whats-new

Processor SDK 8.0 Release has following new features:

- First release on 2021 LTS 5.10 kernel, 2021.01 U-Boot
- AM64: SPL DFU boot, ICSS-G Dual EMAC/PRUETH, ECAP, MCAN, ePWM, SA2UL, WDT
- AM65: ICSS-G PRUETH
- J7200, J721E: HSM bootloader re-arch
- J721E HS Boot
- AM64, J7200, J721E: Unified DDR driver
- ATF 2.5, OPTEE 3.12



Build Information
=====================================

U-Boot
-------------------------

| Head Commit: 53e79d0e89f975eeb874366dd9a92f68b3a599d1 defconfigs: am65x_hs_evm: Sync HS and non-HS defconfigs
| Date: Sat Jul 31 10:26:46 CDT 2021
| uBoot Version: 2021.01
| uBoot Description: 08.00.00.004

| Clone: ssh://git@bitbucket.itg.ti.com/lcpdpub/ti-u-boot.git
| Branch: 08.00.00.004
| uBoot Tag: 08.00.00.004

| Compiler Information:  arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025

Kernel
-------------------------
.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 4c2eade9f722838b0e457650368cba1c6c7483c2 Merged TI feature rpmsg into ti-linux-5.10.y
| Date: Fri Jul 30 11:37:10 CDT 2021
| Kernel Version: 5.10.41
| Kernel Description: 08.00.00.004

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.10.y
| Tag: 08.00.00.004
| Kernel defconfig: ti_sdk_arm64_release_defconfig

| Compiler Information:  arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 0701a5b58c943909a38be9df38a3b4bdd8234340 Merged TI feature ti_linux_base_rt into ti-rt-linux-5.10.y
| Date: Fri Jul 30 16:42:25 CDT 2021
| Kernel Version: 5.10.41
| RT Kernel Version: 5.10.41-rt39<br>
| Kernel Description: 08.00.00.004-rt

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.10.y
| Tag: 08.00.00.004-rt
| Kernel defconfig: ti_sdk_arm64_rt_release_defconfig

| Compiler Information:  arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025

Yocto
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 15f3d4a3c3773294f1cdb66a88744930941a892e
| ti-rtos-firmware: Add soft link to the rtos firmware binaries
| Date: 2021-07-23
| Version: dunfell-3.1

| Clone: https://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: 08.00.00.004

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: ae47bd7fbea2776a4f8792f20c493d7959ee2f54
| iproute2: upgrade to 5.10
| Date: 2021-07-21
| Version: 2020.05

| Clone: https://arago-project.org/git/meta-arago.git
| Branch: dunfell
| Release Tag: 08.00.00.004
|

Issues Tracker
=====================================

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 100

   "LCPD-21538","am64xx-evm PCI-EP MSI tests are failing","am64xx-evm"
   "LCPD-21536","AM654x - Display port tests fail due to tidss not found","am654x-evm"
   "LCPD-21516","WIC file generated does not include tiboot3.bin","am64xx-evm"
   "LCPD-21510","USB devices attached to am64xx-evm are not enumerated","am64xx-evm"
   "LCPD-21509","AM64x Core Benchmarks degrades on some runs","am64xx-evm"
   "LCPD-21350","j7200 PCIE-EP tests failing","j7200-evm"
   "LCPD-21334","Convert ti,j721e-gpio to yaml","am64xx-evm,am64xx-sk,am654x-evm,am654x-idk,j721e-evm,j7200-evm"
   "LCPD-21297","Upstream: remoteproc/pru: Fix multiple issues in firmware event mapping","am335x-evm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am57xx-evm,am57xx-beagle-x15,am654x-evm,am654x-idk,beaglebone,bbai,beaglebone-black,j721e-evm,j721e-evm-ivi,j721e-idk-gw,k2g-evm,k2g-ice"
   "LCPD-20837","J7200: UART Boot hangs at R5 SPL with MCU_UART0 as console","j7200-evm"
   "LCPD-20741","j721e PCIe backplane test fails to load the dtb overlay","j721e-idk-gw"
   "LCPD-20721","AM64-sk: Memtester failures","am64xx-sk"
   "LCPD-20701","PCIe: Observe external abort during bootup","j7200-evm"
   "LCPD-20626","am64x-sk: mmc list command does not return anything","am64xx-sk"
   "LCPD-20623","AM654x UART boot failing to boot","am654x-evm,am654x-idk"
   "LCPD-20553","PCI: EP: PCIe EP Not Testable - Add device ID for AM64 in pci_endpoint_test","am64xx-evm"
   "LCPD-20385","AM64: Upstream: Set USB PHY core voltage to 0.85","am64xx-evm,am64xx-sk"
   "LCPD-20229","U-Boot : HS Boot post Rearch for J721E","j721e-hsevm"
   "LCPD-20163","am64xx fails to boot when using the mmcmode custom build","am64xx-evm"
   "LCPD-20162","Degraded performance when running IET tests over eth1","am64xx-evm"
   "LCPD-20130","am64xx PCIe-EP test failing due to a NULL pointer exception","am64xx-evm"
   "LCPD-20106","USBDEVICE ping from DUT to host fails when packet_count=470","am64xx-evm,j7200-evm"
   "LCPD-20055","Assign am64xx GPIO test pins in ltp-ddt","am64xx-evm"
   "LCPD-19873","Pings not received by DUT over Ethernet VLAN","am654x-evm"
   "LCPD-19822","ARM benchmark testcases returning lower than expected performance","j721e-idk-gw"
   "LCPD-18935","IPC tests failed on j721e in 07.00 rc5","j721e-idk-gw"
   "LCPD-18673","IPSEC fails to establish connection when using HW crypto","j721e-idk-gw"

|


Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-23003","IPC: when pdk-ipc fw loaded from u-boot it breaks j721e boot and ethfw","j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw"
   "LCPD-22979","firmware links are missing in /lib/firmware directory for K3","am64xx-evm,am64xx-sk,am654x-evm,j721e-idk-gw,j7200-evm"
   "LCPD-22945","udhcpc -i does does not exit when ran on virtual MAC interface","j7200-evm"
   "LCPD-22914","HS EVMs fail to boot","am654x-hsevm,j721e-hsevm"
   "LCPD-22907","j7200: EthFw not getting Q/SGMII linked","j7200-evm"
   "LCPD-22889","U-Boot: k3-ddrss driver generates a build warning","j721e-evm,j721e-evm-ivi,j721e-idk-gw,j7200-evm"
   "LCPD-22859","j721e PCE-EP tests fail","j721e-idk-gw"
   "LCPD-22854","am64xx crypto tests fail due to tcrypt","am64xx-evm,am64xx-sk"
   "LCPD-22851","j7200 SDHC performance write degraded","j7200-evm"
   "LCPD-22843","j7200 USBHOST Ethernet ping tests are failing","j7200-evm"
   "LCPD-22842","am64xx ethernet CPSW3g tests faile due to queue 0 not increasing","am64xx-evm"
   "LCPD-22816","Update documentation to mention that CPSW 2G PPS support is disabled","j721e-evm,j7200-evm"
   "LCPD-22792","EFI is disabled","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am574x-idk,am574x-hsidk,am57xx-evm,am64xx-evm,am64xx-sk,am654x-evm,am654x-idk,j721e-idk-gw,j7200-evm"
   "LCPD-22784","am654x-evm fails to load boot images over UART","am654x-evm"
   "LCPD-22747","AM64x: fails to boot since commit ffcfac2e4164","am64xx-evm"
   "LCPD-22514","Broken USB MSC boot on AM642-EVM","am64xx-evm"
   "LCPD-22488","AM64 inconsistent promiscuous mode visibility","am64xx-evm,j721e-idk-gw,j7200-evm"
   "LCPD-22358","U-Boot: am642/am654/j72xx: ethernet address fixup is broken","am64xx-evm,am654x-evm,j721e-evm,j7200-evm"
   "LCPD-22349","Displayport playback test fails: cannot find tidss device","j721e-idk-gw"
   "LCPD-22345","U-Boot: Main R5F clusters are incorrectly in LockStep mode","j721e-evm,j721e-evm-ivi,j721e-idk-gw"
   "LCPD-22344","crypto: sa2ul: crypto self-tests fail to allocate des3 algos","am654x-evm,am654x-idk,j721e-evm,j721e-evm-ivi,j721e-idk-gw"
   "LCPD-22342","crypto: sa2ul: Fix a number of leaks in failure paths in probe","am64xx-evm,am64xx-sk,am654x-evm,am654x-idk,j721e-evm,j721e-evm-ivi,j721e-idk-gw,j7200-evm"
   "LCPD-22338","ipc_echo_test test on am64xx-evm fails due to a firmware file name change","am64xx-evm"
   "LCPD-22335","Linux: OSPI read fails ","j7200-evm"
   "LCPD-22334","Hyperflash tests fail on j7200 - 2021.00","j7200-evm"
   "LCPD-22318","CRYPTO_S_PERF testcases are missing CONFIG_CRYPTO_DEV_SA2UL arg in 2021.00","am654x-evm,am654x-idk,j721e-evm-ivi,j721e-idk-gw,j7200-evm"
   "LCPD-22317","J7200 incorrect eMMC speedmode in u-boot","j7200-evm"
   "LCPD-22306","GFX: Fix RT kernel build failure for SGX","am57xx-evm,am654x-evm,dra7xx-evm"
   "LCPD-22304","am654x boot fails with latest baseboard dtb's","am654x-evm,am654x-idk"
   "LCPD-22300","/dev/hwrng missing on K3 platforms","am654x-evm,am654x-idk,j721e-evm,j721e-evm-ivi,j721e-idk-gw,j7200-evm"
   "LCPD-22282","U-Boot: reset to default env fails in 2021 LTS","am335x-evm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am57xx-evm,am57xx-beagle-x15,am64xx-evm,am64xx-sk,am654x-evm,am654x-idk,beaglebone,bbai,beaglebone-black,dra71x-evm,dra72x-evm,dra76x-evm,dra7xx-evm,j721e-evm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,k2e-evm,k2g-evm,k2g-ice,k2hk-evm,k2l-evm,omapl138-lcdk,am62xx-evm"
   "LCPD-22281","U-Boot hangs with 'LPDDR4_StartTest: FAIL' error when starting on am64xx-evm","am64xx-evm"
   "LCPD-22270","Kernel: J7200: main navss missing dma-coherent","j7200-evm,j7200-hsevm"
   "LCPD-22242","Kernel: UBIFS test failing on J721E","j721e-idk-gw"
   "LCPD-22240","2021.00 uboot on am64xx-evm - dhcp does not work","am64xx-evm"
   "LCPD-22239","2021.00 idk and pcie dtbs are missing for am654","am654x-evm"
   "LCPD-22237","2021 uboot - dhcp does not work with j7200","j7200-evm"
   "LCPD-22209","J7ES: OSPI boot: TISCI config ring fail error with SDK7.3","j721e-evm,j7200-evm"
   "LCPD-22208","J7ES: Linux not using the latest RM Boardcfg from the sysconfig tool leading to inconsistency with PDK","j721e-evm,j7200-evm"
   "LCPD-22207","SDK: j7\*-\*evm fails to build after 5.10 kernel migration","j721e-idk-gw"
   "LCPD-22048","U-Boot: J7/AM64: DDR driver size is bloated up","am64xx-evm,j721e-idk-gw"

|

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title"
   :widths: 15, 180

   "LCPD-20123","MPU COUNTER_REALTIME saturates after several hundred days"
   "LCPD-19987","UDMAP: Spurious ECC errors due to MAIN/MCU NAVSS rofifo_wr_byten issue"
   "LCPD-19986","UDMAP: TX Channel SA2UL teardown issue"
   "LCPD-19966","I3C: SDAPULLEN drives low instead of Hi-Z"
   "LCPD-19965","OSPI PHY Controller Bug Affecting Read Transactions"
   "LCPD-19874","PSIL: Clock stop operation can result in undefined behavior"
   "LCPD-19811","CPSW: ALE incorrectly routes packets with CRC errors"
   "LCPD-19586","USB: 2.0 PHY hangs if received signal amplitude crosses squelch threshold multiple times within the same packet"
   "LCPD-19447","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame"
   "LCPD-19068","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame"
   "LCPD-19056","USB: DMA hangs if USB reset is received during DMA transfer in device mode"
   "LCPD-19048","USB: Invalid termination of DMA transfer for endpoint following Isochronous endpoint in Superspeed device mode"
   "LCPD-19047","USB: Race condition while reading TRB from system memory in device mode"
   "LCPD-19041","PCIe: End of Interrupt (EOI) not enabled for PCIe legacy interrupts"
   "LCPD-19032","CPSW: CPSW Does Not Support Intersperced Express Traffic (IET – P802.3br/D2.0) In 10/100Mbps Mode"
   "LCPD-19031","[CPTS] GENF (and ESTF)  Reconfiguration Issue"
   "LCPD-19030","USB: USB2PHY Charger Detect is enabled by default without VBUS presence"
   "LCPD-19029","PCI-Express (PCIe) May Corrupt Inbound Data"
   "LCPD-19028","DSS : DSS DPI Interface does not support BT.656 and BT.1120 output modes"
   "LCPD-19027","CPSW does not support CPPI receive checksum (Host to Ethernet) offload feature"
   "LCPD-19026","MMCSD: Negative Current from UHS-I PHY May Create an Over-Voltage Condition on VDDS6 and VDDS7 which exposes the Device to a Significant Reliability Risk"
   "LCPD-19025","IO, MMCSD: Incorrect IO Power Supply Connectivity Prevent Dynamic Voltage Change on VDDSHV6 and VDDSHV7"
   "LCPD-19024","RINGACC and UDMA ring state interoperability issue after channel teardown"
   "LCPD-19022","UDMA-P Real-time Remote Peer Registers not Functional Across UDMA-P Domains"
   "LCPD-18999","PCIe: Endpoint destination select attribute (ASEL) based routing issue"
   "LCPD-18996","Hyperflash: Hyperflash is not functional"
   "LCPD-18995","OSPI: OSPI Boot doesn't support some xSPI modes or xSPI devices"
   "LCPD-18981","UDMAP: Packet mode descriptor Address Space Select Field Restrictions"
   "LCPD-18979","MCAN: Message Transmitted with Wrong Arbitration and Control Fields (Early Start of Frame)"
   "LCPD-18952","DSS : DSS Does Not Support YUV Pixel Data Formats"
   "LCPD-17806","Cortex-R5F: Deadlock might occur  when one or more MPU regions is configured for write allocate mode"
   "LCPD-17788","PCI-Express: GEN3 (8GT/s) Operation Not Supported."
   "LCPD-17786","UART: Spurious UART Interrupts When Using DMA"
   "LCPD-17784","CPSW: CPSW Does Not Support Intersperced Express Traffic (IET – P802.3br/D2.0) In 10/100Mbps Mode"
   "LCPD-17783","USB: USB2PHY Charger Detect is enabled by default without VBUS presence"
   "LCPD-17333","[CPTS] GENF (and ESTF)  Reconfiguration Issue"
   "LCPD-17220","U-Boot Hyperbus: Hyperflash reads limited to 125MHz max. frequency"
   "LCPD-16904","PCIe: Unsupported request (UR) or Configuration Request Retry Status (CRS) in configuration completion response packets results in external abort"
   "LCPD-16643","Hyperbus: Hyperflash reads limited to 125MHz max. frequency"
   "LCPD-16605","MMC: MMC1/2 Speed Issue"
   "LCPD-16538","PCI-Express (PCIe) May Corrupt Inbound Data"
   "LCPD-14941","RINGACC and UDMA ring state interoperability issue after channel teardown"
   "LCPD-14579","DSS : DSS Does Not Support YUV Pixel Data Formats"
   "LCPD-14577","CPSW does not support CPPI receive checksum (Host to Ethernet) offload feature"
   "LCPD-14187","UDMA-P Real-time Remote Peer Registers not Functional Across UDMA-P Domains"
   "LCPD-14185","MSMC: Non-coherent memory access to coherent memory can cause invalidation of snoop filter"
   "LCPD-14184","USB:  SuperSpeed USB Non-Functional"
   "LCPD-9084","i887: Software workaround to limit mmc3 speed to 64MHz"
   "LCPD-8294","37 pins + VOUT pins need slow slew enabled for timing and reliability respectively"
   "LCPD-8277","u-boot: j6: SATA is not shutdown correctly as per errata i818"
   "LCPD-7642","MMC/SD: i832: return DLL to default reset state with CLK gated if not in SDR104/HS200 mode."
   "LCPD-6907","Workaround errata i880 for RGMII2 is missing"
   "LCPD-5931","DRA7xx: AM57xx: mmc: upstream errata workaround for i834"
   "LCPD-5924","ALL: CONNECTIVITY: CPSW: errata i877 workarround for cpsw"
   "LCPD-5836","CAL: Errata: i913: CSI2 LDO needs to be disabled when module is powered on"
   "LCPD-5309","LCPD:  i896: USB Port disable doesnt work"
   "LCPD-5308","i897: USB Stop Endpoint doesnt work in certain circumstances"
   "LCPD-5052","Upstream: Post the dmtimer errata fix for i874"
   "LCPD-4975","DSS AM5/DRA7: implement WA for errata i886"
   "LCPD-4912","DRA7: USB: Implement ErrataID_i896_PED_issue"
   "LCPD-4910","J6/OMAP5: errata i810 implementation"
   "LCPD-4648","[rpmsg 2014 LTS] Implement errata i879 - DSP MStandby requires CD_EMU in SW_WKUP"
   "LCPD-4647","[rpmsg 2015 LTS] Implement errata i879 - DSP MStandby requires CD_EMU in SW_WKUP"
   "LCPD-4225","J6: Errata: i834: Investigate possibility of software workaround"
   "LCPD-4218","Implement Workaround for Errata i813 - Spurious Thermal Alert Generation When Temperature Remains in Expected Range"
   "LCPD-4217","Implement Workaround for Errata i814 - Bandgap Temperature read Dtemp can be corrupted"
   "LCPD-4195","J6: SATA: Investigate applicability of i807"
   "LCPD-4184","Implement workaround for errata i814 - Bandgap Temperature read Dtemp can be corrupted"
   "LCPD-1776","[J6 SATA Adaptation] J6 - Errata i783, SATA Lockup After SATA DPLL Unlock/Relock"
   "LCPD-1188","J6: Baseport: Errata i877: RGMII clocks must be enabled to avoid IO timing degradation due to Assymetric Aging"
   "LCPD-1146","DMM hang: Errata VAYU-BUG02976 (i878) (register part)"
   "LCPD-1108","J6: Wrong Access In 1D Burst For YUV4:2:0-NV12 Format (Errata i631)"
   "LCPD-1087","J6: MMC: Errata: i802: OMAP5430 MMCHS: DCRC errors during tuning procedure"
   "LCPD-976","J6/J6eco: 32clk is psuedo (erratum i856) - clock source"
   "LCPD-975","J6/J6eco: 32clk is psuedo (erratum i856) - realtime counter"
   "LCPD-876","OMAP5: Errata i810: DPLL Controller Sticks when left clock requests are removed"

|

SDK Known Issues
-----------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-23006","am654x-evm","PVR driver fails to detect SGX core on AM65x SR1.0",""
   "LCPD-22973","j721e-idk-gw","GFX_XS_FUNC_GPU_MEM2MEM test fails due to a change in the expected output",""
   "LCPD-22972","j721e-idk-gw","j721e-idk-gw GLBenchmark GLB25_EgyptTestStandardOffscreen_inherited test ",""
   "LCPD-22921","j721e-idk-gw","j721e PVR profiling with PVRPerfServer test is failing",""
   "LCPD-22549","j721e-idk-gw","v4l2h264dec : application hangs when setting the pipeline to null",""
   "LCPD-22542","j721e-idk-gw","v4l2h264dec is giving high latency compared to SW decoder",""
   "LCPD-21298","j721e-evm,j721e-evm-ivi,j721e-idk-gw","Frame Buffer Decompression does not show expected improvement",""
   "LCPD-20620","j721e-idk-gw","J721e: Gstreamer warning seen with video decoder mjpeg test",""
   "LCPD-20038","am64xx-evm","OPTEE test applications are missing from rootfs",""
   "LCPD-19948","am57xx-evm,am654x-evm,j721e-evm","Yocto: stream recipe is incorrect",""
   "LCPD-19894","j721e-idk-gw","UYVY texture test fails due to internal data stream error",""
   "LCPD-19858","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am64xx-evm,am64xx-vlab,am64xx-zebu,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm,k2e-evm,k2e-hsevm,k2g-evm,k2g-hsevm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm,k2l-hsevm","OE: OPTEE label used in SDK is old and wrong",""
   "LCPD-19819","j721e-idk-gw","KMS ALPHABLEND tests fail due to no attribute 'get_default_mode'",""
   "LCPD-19743","j7200-evm,j7200-hsevm","Packages.gz is missing",""
   "LCPD-19716","j721e-idk-gw","GFX_XS_FUNC_UYVY_TEXTURE test fails",""
   "LCPD-18908","am654x-evm","GLMark2 fails for am65x",""
   "LCPD-18270","am335x-evm,am43xx-gpevm,am571x-idk,am572x-idk,am574x-idk,am57xx-evm,am57xx-beagle-x15,am654x-evm,am654x-idk,dra71x-evm,dra72x-evm,dra76x-evm,dra7xx-evm,j721e-evm,j721e-evm-ivi,j721e-idk-gw","Ivi shell test fails. Lib ivi-controller.so and other components are missing from the file system",""
   "LCPD-17449","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am654x-evm,am654x-idk,am654x-hsevm,beaglebone,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm","libasan_preinit.o is missing in devkit",""
   "LCPD-17413","am335x-evm,am43xx-gpevm,am57xx-evm,am654x-evm","QT Webengine-based browser: the mouse does not work within the web page with QPA EGLFS",""
   "LCPD-17412","am654x-evm","QT5 Webengine-based browser crashing with any resize operation",""
   "LCPD-17387","j721e-evm-ivi,j721e-idk-gw","Underflow and CRTC SYNC LOST observed while running GLMark2 (1x1080p + 1x4k)",""
   "LCPD-17304","j721e-evm,j721e-evm-ivi,j721e-idk-gw","Error Recovery Test for VDEC_ERROR_SR_ERROR does not trigger error",""
   "LCPD-17283","j721e-evm,j721e-evm-ivi,j721e-idk-gw","Running Gstreamer's gst-discoverer causes a crash",""
   "LCPD-16664","am654x-evm,am654x-idk","MMU Alloc errors and Kernel Oops with RT build",""
   "LCPD-16366","j721e-evm,j721e-evm-ivi,j721e-idk-gw","RGX kick test fails when 32 sync dependencies are set for each command",""
   "LCPD-16130","j721e-evm,j721e-evm-ivi,j721e-idk-gw","Exception triggered by drm_dev_unregister during poweroff",""
   "LCPD-14254","am654x-evm,am654x-idk","meta-ti: Need a recipe update to pick up the new AM65x PRU Ethernet firmwares",""
   "LCPD-13817","am654x-evm","Qt5 Webengine-based broswer does not work on AM654x with pagesize = 64k",""
   "LCPD-13816","am654x-evm","Chromium-wayland broswer does not work on AM654x with page size = 64k",""

|


U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-23026","am64xx-evm","USB MSC Boot: USB controller not visible from u-boot",""
   "LCPD-23024","am64xx-evm","PSDK-DOC: UBoot: USB host boot info is out of date",""
   "LCPD-23023","j7200-evm","j7200 eMMC, Hyperflash and OSPI boot mode tests failing",""
   "LCPD-23020","am64xx-evm","am64xx-evm: U-Boot PHY autonegotiation failed 2 out of 100 times",""
   "LCPD-22975","am654x-evm,am654x-idk","AM654x: 1Ghz & beyond caused boot hang on SR2.0",""
   "LCPD-22967","j721e-evm,j721e-evm-ivi,j721e-idk-gw,j7200-evm","U-Boot: PLL PostDiv1 and PostDiv2 divider clock rates are computed incorrectly",""
   "LCPD-22964","j721e-evm,j721e-evm-ivi,j721e-idk-gw,j7200-evm","U-Boot: PLL POSTDIV1 and POSTDIV2 clock parenting is reversed",""
   "LCPD-22904","j721e-idk-gw,j7200-evm","U-boot: Update EMIFtool for i2244:DDR: Valid stop value must be defined for write DQ VREF training",""
   "LCPD-22841","am64xx-evm,j721e-idk-gw,j7200-evm","j7200 Watchdog Timer test is failing",""
   "LCPD-22512","j721e-evm,j7200-evm","Update dfu_alt_info_ospi to include flashing of PHY tuning data",""
   "LCPD-22246","j721e-idk-gw","j721e Uboot DFU tests are failing",""
   "LCPD-22188","am654x-hsevm,j721e-hsevm","j721e and am65 hs fails to build on 2021.01 uboot",""
   "LCPD-21986","j721e-idk-gw","j721e U-Boot DDR50 mode cannot be tested using the default image",""
   "LCPD-21962","am64xx-evm","U-Boot documentation discrepancies",""
   "LCPD-20131","am64xx-evm,j721e-idk-gw,j7200-evm","Uboot fails to enumerate devices attached to a usb hub on the first 'usb reset' call ","Re-run usb reset command "
   "LCPD-19871","j721e-idk-gw,j7200-evm","U-boot: Documentation: Combined Boot flow and SPL Rearch",""
   "LCPD-19776","j721e-idk-gw","j7: uboot: some socketed evms fail to boot",""
   "LCPD-19636","j721e-hsevm","J7: HS: OSPI Boot broken",""
   "LCPD-17789","j721e-idk-gw","UBOOT J7:  Could not see UFS device by scsi scan",""
   "LCPD-17770","am654x-evm,am654x-idk,am654x-hsevm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw","U-Boot: Fix order of MCU R5 shutdown depending on cluster mode",""
   "LCPD-17523","j721e-evm,j721e-idk-gw,j7200-evm","A72-SPL - Support to dump EEPROM to shared memory",""
   "LCPD-16696","am654x-evm,am654x-idk","U-Boot does not recognize SD-Card after re-insert/change",""
   "LCPD-16524","am654x-evm,am654x-idk,am654x-hsevm","Need to adjust RMW bit when using enabling ECC","None"
   "LCPD-15873","am654x-evm","There is no dtbo in u-boot for PCIe x1 + usb3 daughter card","None"
   "LCPD-14843","am654x-evm,am654x-idk","U-boot should support  default settings for netboot ","None"

|


Linux Kernel Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround" 
   :widths: 5, 10, 70, 35

   "LCPD-23041","j7200-evm","Doc: Update J7200 eMMc documentation",""
   "LCPD-23018","j721e-idk-gw","j721e-idk-gw IPC tests fail on some EVMs",""
   "LCPD-23012","am654x-evm","DRM universal planes - Could not get DRM master permission",""
   "LCPD-23010","j721e-idk-gw","j721e-idk-gw stress boot test files",""
   "LCPD-23009","am654x-evm"," CAL capture test- No capture device of type cal found",""
   "LCPD-23008","am654x-evm","AM65xx - display port scenario not enabled",""
   "LCPD-23007","am654x-evm","k3-am654-evm-hdmi.dtbo file is missing in CoreSDK for am654x",""
   "LCPD-22976","am64xx-hsevm,am64xx-sk,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm,k2g-evm,k2g-hsevm,j721e-eaik","omap-spi.txt  convert to yaml",""
   "LCPD-22963","am654x-evm","IPC_S_PERF_RPMSG_PROTO_BENCH_228BYTES - lad did not start",""
   "LCPD-22962","am654x-evm","IPC performance- IPC_S_FUNC_PRU_ECHO test failing",""
   "LCPD-22959","am654x-evm","UART Read/Write tests at baud rate 115200 fails",""
   "LCPD-22955","am654x-evm","DSS scaling and cropping tests fails- kms_props not supported",""
   "LCPD-22954","am654x-evm","DRM Stress Test fails",""
   "LCPD-22953","am654x-evm","v4l2 cal compliance test fails",""
   "LCPD-22952","am654x-evm","alsa_amixer_volumesetting fails",""
   "LCPD-22951","am654x-evm","Alsa test fails - no soundcards found",""
   "LCPD-22950","am654x-evm","Alsa speaker test fails",""
   "LCPD-22949","am654x-evm","Audio interactive test fails",""
   "LCPD-22947","am654x-evm","Alsa performance test fails",""
   "LCPD-22931","am64xx-evm,am64xx-sk,am654x-evm,am654x-idk,dra72x-evm","RemoteProc documentation missing",""
   "LCPD-22920","am64xx-evm","AM64x Linux IPC documentation is insufficient / out-of-date",""
   "LCPD-22917","j7200-evm","j7200 SPL: eMMC alternative boot mode support is failing",""
   "LCPD-22915","j7200-evm","j7200-evm SPL OSPI boot test is failing",""
   "LCPD-22913","am64xx-evm,j721e-idk-gw,j7200-evm","USBDEV ACM NCM enumeration fails on the device side",""
   "LCPD-22912","am64xx-evm","am64xx-evm SMP dual core test fails sporadically",""
   "LCPD-22892","am64xx-evm,am654x-evm,am654x-idk","icssg: due to FW bug both interfaces has to be loaded always",""
   "LCPD-22861","j721e-hsevm","Missing documentation for HS devices",""
   "LCPD-22852","am64xx-evm","AM64x: ICSSG ping with 16384 size shows high packet loss",""
   "LCPD-22834","am64xx-evm","am64xx-evm stress boot test files",""
   "LCPD-22789","am64xx-evm","cdns-usb3: g_mass_storage and g_ether fails on some boards",""
   "LCPD-22715","j721e-idk-gw,j7200-evm,j721s2-evm,am62xx-evm","i2232: DDR: Controller postpones more than allowed refreshes after frequency change","Workaround 1:
   Disable dynamic frequency change by programing::

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
   "LCPD-22534","am64xx-evm,am654x-evm,j721e-idk-gw,j7200-evm","Ipsec aes128 TCP test failure",""
   "LCPD-22513","j721e-evm,j7200-evm","Update SDK doc to include OSPI flashing instruction using dfu-util",""
   "LCPD-22413","j7200-evm","Hyperflash tests fail ~50% of the time on j7200",""
   "LCPD-22362","j721e-idk-gw","ALSA sampling format capture/loopback test - arecord failure",""
   "LCPD-22339","j721e-idk-gw,j7200-evm","PCI-E USBCARD, ETHCARD don't indicate 2-lane support with lspci",""
   "LCPD-22319","am64xx-evm,j7200-evm","OpenSSL performance test data out of bounds",""
   "LCPD-22285","j721e-idk-gw","HS200 MMC speeds aren't being achieved in kernel",""
   "LCPD-22278","j721e-idk-gw","PCI-E USB devices fail to enumerate after power cycling",""
   "LCPD-22215","am64xx-evm","PCIE NVM card stops enumerating on am64xx after some time",""
   "LCPD-21508","j7200-evm","USB stick attached to a PCIe USB card on j7200 not enumerated after reboot",""
   "LCPD-20705","am64xx-evm","USB stick attached to PCIe USB card is not enumerated",""
   "LCPD-20653","am335x-evm,am43xx-gpevm,am654x-idk,j721e-idk-gw","ltp: kernel syscall tests fail",""
   "LCPD-20558","am64xx-sk","OSPI UBIFS tests failing on am64xx-sk",""
   "LCPD-20320","j7200-evm","CPSW5g high packet loss",""
   "LCPD-20290","j721e-idk-gw","CPSW Performance regression on j721e-idk-gw",""
   "LCPD-20240","j721e-idk-gw","MMC Modular testcase regression",""
   "LCPD-20105","am64xx-evm","AM64x: Kernel: ADC: RX DMA channel request fails",""
   "LCPD-20061","am64xx-evm","Occasional PHY error during during TSN Time-Aware Shaper execution",""
   "LCPD-20014","am654x-evm,am654x-idk,am654x-hsevm","remoteproc: TX_PRU: IRQ vring, IRQ kick not found error message on console",""
   "LCPD-20006","am64xx-evm","AM64x: remoteproc may be stuck in the start phase after a few times of stop/start",""
   "LCPD-19929","am654x-evm","Industrial protocols documentation",""
   "LCPD-19924","am654x-evm,am654x-idk","[AM65xx]  ICSS-G TCP receive throughput degraded",""
   "LCPD-19923","am654x-evm,am654x-idk","[AM65x] Linux reboot command fails","https://e2e.ti.com/support/processors-group/processors/f/processors-forum/1011070/am6548-linux-reboot-command-fails"
   "LCPD-19861","am654x-evm","ICSSG: Unregistered multicast MAC packets are still visible in non-promiscuous mode",""
   "LCPD-19859","am654x-evm","ETH ICSSG netperf benchmark returns lower performance than expected",""
   "LCPD-19792","j721e-idk-gw","j721e boot fails sometimes due to EL1 exception",""
   "LCPD-19723","j7200-evm","RTI watchdog test fails on J7VCL E5 SOM",""
   "LCPD-19659","j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j7200-evm,j7200-hsevm","Doc: PCIe: Update documentation to indicate how to move to compliance mode",""
   "LCPD-19580","am654x-evm","am654- unable to select a mode (sdhci?)",""
   "LCPD-19499","j7200-evm,j7200-hsevm","Kernel: OSPI write throughput is less than 1MB/s",""
   "LCPD-19497","j7200-evm","J7200: CPSW2g: interface goes up and down sporadically","Seen only on very few EVMs. No workaround. "
   "LCPD-19460","j7200-evm,j7200-hsevm","J7200: USB3 devices fail to enumerate at 2.0/3.0 when SERDES multi-link (PCIe + USB3)","No workaround for USB 3.0 devices exists. USB 2.0 devices enumerate fine."
   "LCPD-19084","j721e-idk-gw","Few SD cards not enumerating in Kernel with Alpha EVM",""
   "LCPD-19068","j721e-evm,j721e-evm-ivi,j721e-idk-gw","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame",""
   "LCPD-18860","am654x-evm,am654x-idk,j721e-idk-gw","isolcpus in the command line is not honored",""
   "LCPD-18854","am64xx-evm,dra71x-evm,dra76x-evm","ov5640 sensor capture fails for raw format capture",""
   "LCPD-18790","j721e-idk-gw","eMMC tests failed on J7 rev E2 EVM",""
   "LCPD-18684","am57xx-evm,am654x-evm,j721e-idk-gw","syscalls sync failures: fdatasync03, fsync04, sync03, syncfs01, sync_file_range02",""
   "LCPD-18665","am654x-evm,am654x-idk","Am65x Pg2: Board cannot do soft reboot when booting from SD card",""
   "LCPD-18297","am654x-evm","AM6: OV5640: 176x144 does not work",""
   "LCPD-18289","am654x-evm,k2g-evm","pcie-usb tests sometimes fail",""
   "LCPD-18258","am654x-evm,j721e-idk-gw","IPSEC perfomance failures",""
   "LCPD-18228","am654x-evm","PCI PM runtime suspend is not increasing",""
   "LCPD-17908","am654x-evm,am654x-idk","ICSSG: dual-emac: udp packets ocassionally sent out of order on egress",""
   "LCPD-17814","j721e-idk-gw","Kingston 16G card could not boot to uboot prompt",""
   "LCPD-17800","am654x-evm,am654x-idk","CPSW: Master/Slave resolution failed message seen at console",""
   "LCPD-17798","am654x-evm,am654x-idk,j7am-evm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-vlab,j7200-evm,j7200-hsevm","2020 LTS: INTA/INTR smp_affinity failure and IRQ allocation issues.",""
   "LCPD-17794","j721e-idk-gw","ext4write failed to write firmware to SD card",""
   "LCPD-17777","am654x-evm","AES HW is not exercised",""
   "LCPD-17673","am335x-evm,am43xx-gpevm,am571x-idk,am572x-idk,am574x-idk,am57xx-evm,am654x-evm,beaglebone-black,dra71x-evm,dra72x-evm,dra7xx-evm,j721e-evm","No software documentation for the Timer module",""
   "LCPD-17543","j721e-evm,j721e-evm-ivi,j721e-idk-gw","Some cpuhotplug tests failed",""
   "LCPD-17471","am654x-evm,am654x-idk","device hang when restarting crashed R5F",""
   "LCPD-17421","j721e-idk-gw","CPSW9G: Can't bring up interface over NFS",""
   "LCPD-17387","j721e-evm-ivi,j721e-idk-gw","Underflow and CRTC SYNC LOST observed while running GLMark2 (1x1080p + 1x4k)",""
   "LCPD-17284","j721e-evm,j721e-evm-ivi,j721e-idk-gw","remoteproc/k3-r5: Cores are started out-of-order when core 0 file size >> core 1 file size",""
   "LCPD-17172","j721e-idk-gw","Uboot USBhost: Sandisk Extreme USB 3.0 msc stick could not be detected at second time",""
   "LCPD-17171","j721e-idk-gw","Uboot dhcp occasionally failed",""
   "LCPD-17113","j721e-idk-gw","[Cpsw9g][VirtualDriver][VirtualMAC] rpmsg_kdrv_switch is not autoloaded",""
   "LCPD-17017","j721e-evm-ivi,j721e-idk-gw","J7: DSS underflows seen on various use cases",""
   "LCPD-16845","am654x-evm,am654x-idk","OPP freq update in DT impacts only cluster0",""
   "LCPD-16836","j721e-idk-gw","DP: GeChic display EDID read failures with custom DP cable",""
   "LCPD-16640","j721e-idk-gw","PCIe RC: GIC ITS misbehaves when more than 4 devices use it simultaneously",""
   "LCPD-16628","j721e-idk-gw","Could not enumerate PLEXTOR pcie SSD",""
   "LCPD-16616","j721e-evm,j721e-evm-ivi,j721e-idk-gw","Jailhouse: Failure in mhdp probe while restarting the Linux VM",""
   "LCPD-16591","j721e-idk-gw","PCIe wifi ping stress test failed",""
   "LCPD-16545","j721e-evm,j721e-evm-ivi,j721e-idk-gw","remoteproc/k3-r5f: PDK IPC echo_test image fails to boot up in remoteproc mode on second run",""
   "LCPD-16535","j721e-evm,j721e-evm-ivi,j721e-idk-gw","remoteproc/k3-dsp: PDK IPC echo test binaries fails to do IPC in remoteproc mode on second run",""
   "LCPD-16534","am654x-evm,am654x-idk","remoteproc/k3-r5f: PDK IPC echo_test image fails to do IPC in remoteproc mode on second run","None"
   "LCPD-16396","j721e-evm,j721e-evm-ivi,j721e-idk-gw","J721E: RC: Unsupported request in configuration completion packets results in an abort","Workaround for Multifunction: Configure all the physical functions supported by the endpoint. For configuring all the 6 functions of PCIe  controller instance '1' in J721E, the following can be used::
   
      mount -t configfs none /sys/kernel/config; 
      cd /sys/kernel/config/pci_ep/; 
      mkdir functions/pci_epf_test/func1; 
      echo 0x104c > functions/pci_epf_test/func1/vendorid; 
      echo 0xb00d > functions/pci_epf_test/func1/deviceid; 
      echo 1 > functions/pci_epf_test/func1/msi_interrupts; 
      echo 16 > functions/pci_epf_test/func1/msix_interrupts; 
      ln -s functions/pci_epf_test/func1 controllers/d800000.pcie-ep/; 
      mkdir functions/pci_epf_test/func2; 
      echo 0x104c > functions/pci_epf_test/func2/vendorid; 
      echo 0xb00d > functions/pci_epf_test/func2/deviceid; 
      echo 1 > functions/pci_epf_test/func2/msi_interrupts; 
      echo 16 > functions/pci_epf_test/func2/msix_interrupts; 
      ln -s functions/pci_epf_test/func2 controllers/d800000.pcie-ep/; 
      mkdir functions/pci_epf_test/func3; 
      echo 0x104c > functions/pci_epf_test/func3/vendorid; 
      echo 0xb00d > functions/pci_epf_test/func3/deviceid; 
      echo 1 > functions/pci_epf_test/func3/msi_interrupts; 
      echo 16 > functions/pci_epf_test/func3/msix_interrupts; 
      ln -s functions/pci_epf_test/func3 controllers/d800000.pcie-ep/; 
      mkdir functions/pci_epf_test/func4; 
      echo 0x104c > functions/pci_epf_test/func4/vendorid; 
      echo 0xb00d > functions/pci_epf_test/func4/deviceid; 
      echo 1 > functions/pci_epf_test/func4/msi_interrupts; 
      echo 16 > functions/pci_epf_test/func4/msix_interrupts; 
      ln -s functions/pci_epf_test/func4 controllers/d800000.pcie-ep/; 
      mkdir functions/pci_epf_test/func5; 
      echo 0x104c > functions/pci_epf_test/func5/vendorid; 
      echo 0xb00d > functions/pci_epf_test/func5/deviceid; 
      echo 1 > functions/pci_epf_test/func5/msi_interrupts; 
      echo 16 > functions/pci_epf_test/func5/msix_interrupts; 
      ln -s functions/pci_epf_test/func5 controllers/d800000.pcie-ep/; 
      mkdir functions/pci_epf_test/func6; 
      echo 0x104c > functions/pci_epf_test/func6/vendorid; 
      echo 0xb00d > functions/pci_epf_test/func6/deviceid; 
      echo 1 > functions/pci_epf_test/func6/msi_interrupts; 
      echo 16 > functions/pci_epf_test/func6/msix_interrupts; 
      ln -s functions/pci_epf_test/func6 controllers/d800000.pcie-ep/; 
      echo 1 > controllers/d800000.pcie-ep/start; 
      echo 1 > /sys/bus/pci/devices/0000:00:00.0/remove; 
      echo 1 > /sys/bus/pci/rescan; 
      
   Workaround for switch card: No workarounds available."
   "LCPD-16048","am654x-evm,am654x-idk","UDP iperf with smaller packet sizes < 512 bytes does not complete consistently",""
   "LCPD-15819","am654x-evm","tidss: the driver should reject dual-display setup, as it is not supported",""
   "LCPD-15540","am57xx-evm,am654x-evm,dra71x-evm,dra7xx-evm","uvc-gadget results in segmentation fault",""
   "LCPD-13938","am654x-evm,dra71x-evm,dra7xx-evm,k2g-evm","PCIe EP read/write/copy test failed with larger sizes ",""
   "LCPD-13936","am654x-evm","Uboot dhcp timeout 1 of 100 times",""
   "LCPD-13653","am654x-evm,am654x-idk","am65x-evm could not boot from MMC/SD when MMC/SD is backup boot mode","No workaround"
   "LCPD-13603","am654x-evm","One board could not boot rootfs from more than one SDHC card",""
   "LCPD-13445","am654x-evm","Seldom kernel oops triggered by prueth_netdev_init",""
   "LCPD-13410","am654x-evm,am654x-idk","Reboot command is not operational",""
