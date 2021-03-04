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

Release 07.02.00
==================

Released January 2021

.. rubric:: What's New
   :name: whats-new

Processor SDK 7.2 Release has following new features:

- AM64XX Support


Build Information
=====================================

U-Boot
-------------------------

| Head Commit: 84b608fd3489c8dd93d8eb20e7f005d967b88402 arm: | dts: k3-am65: Add tag to disable UHS modes in SR 1.0
| Date: Thu Jan 21 08:28:10 CST 2021
| uBoot Version: 2020.01
| uBoot Description: 07.02.00.004

| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: 07.02.00.004
| uBoot Tag: 07.02.00.004

Kernel
-------------------------

.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 60de748aca87c99a32f726a6abf1b6472f297ae3 Merged TI feature connectivity into ti-linux-5.4.y
| Date: Thu Jan 21 08:37:49 CST 2021
| Kernel Version: 5.4.87
| Kernel Description: 07.02.00.004

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.4.y
| Tag: 07.02.00.004
| Kernel defconfig: multi_v7_defconfig

| Compiler Information: arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

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

Yocto
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 542456ca082de7133a61be21222d13974a87e41d 
| ti-sci-fw: Update image gen and sysfw to v2020.12a
| Date: 2021-1-21
| Version: dunfell-3.1

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: 07.02.00.004

.. rubric:: meta-arago
   :name: meta-arago

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
=====================================

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 100

   LCPD-19854,"j721e-evm, j721e-hsevm, j721e-evm-ivi, j721e-idk-gw",PCIe: EP: Low Throughput using DMA
   LCPD-19695,am654x-evm,am654-gpevm: kernel image boot reports corruption
   LCPD-19249,"am654x-evm, am654x-idk","Kernel WARN observed in some cases, tisci timeout reported"
   LCPD-19784,am654x-idk,DFU MMC test fails
   LCPD-19823,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm",ICSS PTP: Fix order of registering ICSS PTP
   LCPD-19573,,Internel Tree Build Failed with overlay repo (ti-upstream-tools)
   LCPD-19733,"j7200-evm, j7200-hsevm",[ti:ti-rt-linux-5.4.y 3364/11241] drivers/pci/endpoint/functions/pci-epf-ntb.c:860 epf_ntb_init_epc_bar_interface() warn: unsigned 'barno' is never less than zero.
   LCPD-19781,"am654x-evm, am654x-idk, j721e-evm, j721e-hsevm, j721e-evm-ivi, j7200-evm, j7200-hsevm",OE: ti-rpmsg-char: Library header files and primary so file are missing in FS
   LCPD-18620,"am654x-evm, am654x-idk",AM65x PG2: U-Boot MMC/SD does not work at greater than 25MHz clock
   LCPD-19891,j721e-evm,V5.10-rc: usb: cdns3 otg does not work on type-C port
   LCPD-19845,,ti: regression: cpts irq not working after a suspend/resume cycle
   LCPD-19870,j721e-evm,next-20201119: cdns3 null pointer derefrence issue
   LCPD-19751,j721e-idk-gw,[ti:ti-linux-5.4.y 3067/10775] drivers/pci/endpoint/pci-epf-bus.c:36:34: warning: unused variable 'pci_epf_bus_id_table'
   LCPD-19273,,UART custom builds are missing
   LCPD-19264,"am654x-evm, am654x-idk",Uboot: No usb controllers found
   LCPD-19857,,Uboot: Nodes with same name not distinguished while assigning sequence numbers
   LCPD-19818,j721e-idk-gw,CPSW2G netperf egress performance lower
   LCPD-19772,"am654x-evm, am654x-idk, am654x-hsevm, j721e-hsevm, j721e-evm-ivi, j721e-idk-gw, j7200-evm, j7200-hsevm",ATF/Uboot GTC frequency handover bug


|


Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   LCPD-19854,"j721e-evm, j721e-hsevm, j721e-evm-ivi, j721e-idk-gw",PCIe: EP: Low Throughput using DMA
   LCPD-20008,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm",ICSS PTP: Fix updating latch registers
   LCPD-20022,"am574x-idk, am574x-hsidk",AM574 IDK HS fails to boot
   LCPD-20099,am654x-evm,U-Boot: AM65: broken boot (Both PG1.0 and 2.0)
   LCPD-19823,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm",ICSS PTP: Fix order of registering ICSS PTP
   LCPD-19947,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",remoteproc/k3-dsp: Fix erroneous error check on devm_ioremap_wc()
   LCPD-19946,"am654x-evm, am654x-idk, j721e-evm, j721e-evm-ivi, j721e-idk-gw, j7200-evm",remoteproc/k3-r5f: Fix couple of warnings
   LCPD-19844,am335x-evm,ALL legacy: CPTS: PTPv1 is advertised by mistake
   LCPD-19845,"am335x-evm,am43xx-gpevm",ti: regression: cpts irq not working after a suspend/resume cycle
   LCPD-19837,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",k3conf: DSP frequencies are printed incorrectly as 0
   LCPD-20034,"am571x-idk, am572x-idk, am574x-idk",prueth: incorrect port renaming
   LCPD-20033,"am571x-idk, am572x-idk, am574x-idk",cpts: icss_iep: provides incorrect phc index through ethtool
   LCPD-20066,am64xx-evm,AM64x PDK IPC firmwares are missing from rootfs
   LCPD-19969,j7200-evm,Kernel: Random DMA timeouts on OSPI
   LCPD-20065,j721e-idk-gw,Kernel: Scatter-gather DMA missing data at the end of the buffer
   LCPD-20058,"am64xx-evm, j7200-evm",Kernel: Fix UBIFS errors on Cypress S28 flash
   LCPD-20103,am64xx-evm,AM64x: Kernel: BCDMA Split RX chan request fails

|

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
   :header: "Record ID",  "Title"
   :widths: 15, 180

   LCPD-19992,PRU-ICSSG: FDB table corruption during switch operation
   LCPD-19991,CPSW9g: Reset isolation not working correctly
   LCPD-19987,UDMAP: Spurious ECC errors due to MAIN/MCU NAVSS rofifo_wr_byten issue
   LCPD-19986,UDMAP: TX Channel SA2UL teardown issue
   LCPD-19978,CPSW: CPSW directed frames are not observed when classification overrides the destination port via the egress opcode feature
   LCPD-19972,OSPI Boot: OSPI Boot doesn't support some xSPI modes or xSPI devices
   LCPD-19966,I3C: SDAPULLEN drives low instead of Hi-Z
   LCPD-19919,CPTS: GENF and ESTF nudge value not  cleared by hardware
   LCPD-19874,PSIL: Clock stop operation can result in undefined behavior
   LCPD-19811,CPSW: ALE incorrectly routes packets with CRC errors
   LCPD-19586,USB: 2.0 PHY hangs if received signal amplitude crosses squelch threshold multiple times within the same packet
   LCPD-19517,R5FSS: The same interrupt cannot be nested back-2-back within another interrupt
   LCPD-19447,DSS: Disabling a layer connected to Overlay may result in synclost during the next frame
   LCPD-19068,DSS: Disabling a layer connected to Overlay may result in synclost during the next frame
   LCPD-19056,USB: DMA hangs if USB reset is received during DMA transfer in device mode
   LCPD-19048,USB: Invalid termination of DMA transfer for endpoint following Isochronous endpoint in Superspeed device mode
   LCPD-19047,USB: Race condition while reading TRB from system memory in device mode
   LCPD-19041,PCIe: End of Interrupt (EOI) not enabled for PCIe legacy interrupts
   LCPD-19032,CPSW: CPSW Does Not Support Intersperced Express Traffic (IET â€“ P802.3br/D2.0) In 10/100Mbps Mode
   LCPD-19031,[CPTS] GENF (and ESTF)  Reconfiguration Issue
   LCPD-19030,USB: USB2PHY Charger Detect is enabled by default without VBUS presence
   LCPD-19029,PCI-Express (PCIe) May Corrupt Inbound Data
   LCPD-19028,DSS : DSS DPI Interface does not support BT.656 and BT.1120 output modes
   LCPD-19027,CPSW does not support CPPI receive checksum (Host to Ethernet) offload feature
   LCPD-19026,MMCSD: Negative Current from UHS-I PHY May Create an Over-Voltage Condition on VDDS6 and VDDS7 which exposes the Device to a Significant Reliability Risk
   LCPD-19025,"IO, MMCSD: Incorrect IO Power Supply Connectivity Prevent Dynamic Voltage Change on VDDSHV6 and VDDSHV7"
   LCPD-19024,RINGACC and UDMA ring state interoperability issue after channel teardown
   LCPD-19022,UDMA-P Real-time Remote Peer Registers not Functional Across UDMA-P Domains
   LCPD-18999,PCIe: Endpoint destination select attribute (ASEL) based routing issue
   LCPD-18996,Hyperflash: Hyperflash is not functional
   LCPD-18995,OSPI: OSPI Boot doesn't support some xSPI modes or xSPI devices
   LCPD-18992,DSS: Frame Buffer Flip/Mirror Feature Using RGB24/BGR24 Packed Format can Result in Pixel Corruption
   LCPD-18981,UDMAP: Packet mode descriptor Address Space Select Field Restrictions
   LCPD-18979,MCAN: Message Transmitted with Wrong Arbitration and Control Fields (Early Start of Frame)
   LCPD-18955,DSS : DSS Does Not Support YUV Pixel Data Formats
   LCPD-18954,DSS : DSS Does Not Support YUV Pixel Data Formats
   LCPD-18953,DSS : DSS Does Not Support YUV Pixel Data Formats
   LCPD-18952,DSS : DSS Does Not Support YUV Pixel Data Formats
   LCPD-17806,Cortex-R5F: Deadlock might occur  when one or more MPU regions is configured for write allocate mode
   LCPD-17788,PCI-Express: GEN3 (8GT/s) Operation Not Supported.
   LCPD-17787,SA2UL: Auth/decrypt operations with 2nd input thread does not send the DMA packet out
   LCPD-17786,UART: Spurious UART Interrupts When Using DMA
   LCPD-17785,UART: Spurious UART Interrupts When Using DMA
   LCPD-17784,CPSW: CPSW Does Not Support Intersperced Express Traffic (IET â€“ P802.3br/D2.0) In 10/100Mbps Mode
   LCPD-17783,USB: USB2PHY Charger Detect is enabled by default without VBUS presence
   LCPD-17333,[CPTS] GENF (and ESTF)  Reconfiguration Issue
   LCPD-17220,U-Boot Hyperbus: Hyperflash reads limited to 125MHz max. frequency
   LCPD-16904,PCIe: Unsupported request (UR) or Configuration Request Retry Status (CRS) in configuration completion response packets results in external abort
   LCPD-16643,Hyperbus: Hyperflash reads limited to 125MHz max. frequency
   LCPD-16605,MMC: MMC1/2 Speed Issue
   LCPD-16538,PCI-Express (PCIe) May Corrupt Inbound Data
   LCPD-16364,MMCSD: Negative Current from UHS-I PHY May Create an Over-Voltage Condition on VDDS6 and VDDS7 which exposes the Device to a Significant Reliability Risk
   LCPD-16363,"IO, MMCSD: Incorrect IO Power Supply Connectivity Prevent Dynamic Voltage Change on VDDSHV6 and VDDSHV7"
   LCPD-16350,DSS: Frame Buffer Flip/Mirror Feature Using RGB24/BGR24 Packed Format can Result in Pixel Corruption
   LCPD-14941,RINGACC and UDMA ring state interoperability issue after channel teardown
   LCPD-14580,DSS : DSS Does Not Support YUV Pixel Data Formats
   LCPD-14579,DSS : DSS Does Not Support YUV Pixel Data Formats
   LCPD-14578,DSS : DSS DPI Interface does not support BT.656 and BT.1120 output modes
   LCPD-14577,CPSW does not support CPPI receive checksum (Host to Ethernet) offload feature
   LCPD-14187,UDMA-P Real-time Remote Peer Registers not Functional Across UDMA-P Domains
   LCPD-14186,UDMA-P Host Packet Descriptorâ€™s â€œ0x3FFFFFâ€ Packet Length Mode not Functional
   LCPD-14185,MSMC: Non-coherent memory access to coherent memory can cause invalidation of snoop filter
   LCPD-14184,USB:  SuperSpeed USB Non-Functional
   LCPD-14159,The assertion of warm reset coinciding with a debug configuration access targeting the STM Subsystem may result in a hang of said debug configuration access
   LCPD-13887,DDR Controller ECC Scrubbing feature can cause DRAM data corruption
   LCPD-13884,"CPTracer Bus Probes MAIN_CAL0_0 and MCU_SRAM_SLV_1 are not able to distinguish between secure and non-secure transactions"
   LCPD-9173,i897: USB Stop Endpoint doesnt work in certain circumstances
   LCPD-9084,i887: Software workaround to limit mmc3 speed to 64MHz
   LCPD-8294,37 pins + VOUT pins need slow slew enabled for timing and reliability respectively
   LCPD-8277,u-boot: j6: SATA is not shutdown correctly as per errata i818
   LCPD-7642,MMC/SD: i832: return DLL to default reset state with CLK gated if not in SDR104/HS200 mode.
   LCPD-6907,Workaround errata i880 for RGMII2 is missing
   LCPD-5931,DRA7xx: AM57xx: mmc: upstream errata workaround for i834
   LCPD-5924,ALL: CONNECTIVITY: CPSW: errata i877 workarround for cpsw
   LCPD-5836,CAL: Errata: i913: CSI2 LDO needs to be disabled when module is powered on
   LCPD-5460,Implement WA for Vayu errata i829 (Reusing Pipe Connected To Writeback Pipeline On The Fly To An Active Panel)
   LCPD-5311,i893: DCAN ram init issues in HW AUTO and when traffic hitting CAN bus (open investigation)
   LCPD-5310,"i900:  CTRL_CORE_MMR_LOCK_5 region after locking results in ctrl module inaccessible, recoverable only post a reset"
   LCPD-5309,"i896: USB Port disable doesnt work"
   LCPD-5308,i897: USB Stop Endpoint doesnt work in certain circumstances
   LCPD-5052,Upstream: Post the dmtimer errata fix for i874
   LCPD-4975,DSS AM5/DRA7: implement WA for errata i886
   LCPD-4912,DRA7: USB: Implement ErrataID_i896_PED_issue
   LCPD-4911,DRA7: USB: Investigate applicability of Errata i897: StopEndpoint_issue
   LCPD-4910,J6/OMAP5: errata i810 implementation
   LCPD-4648,[rpmsg 2014 LTS] Implement errata i879 - DSP MStandby requires CD_EMU in SW_WKUP
   LCPD-4647,[rpmsg 2015 LTS] Implement errata i879 - DSP MStandby requires CD_EMU in SW_WKUP
   LCPD-4225,J6: Errata: i834: Investigate possibility of software workaround
   LCPD-4218,Implement Workaround for Errata i813 - Spurious Thermal Alert Generation When Temperature Remains in Expected Range
   LCPD-4217,Implement Workaround for Errata i814 - Bandgap Temperature read Dtemp can be corrupted
   LCPD-4195,J6: SATA: Investigate applicability of i807
   LCPD-4184,Implement workaround for errata i814 - Bandgap Temperature read Dtemp can be corrupted
   LCPD-1776,"[J6 SATA Adaptation] J6 - Errata i783, SATA Lockup After SATA DPLL Unlock/Relock"
   LCPD-1188,J6: Baseport: Errata i877: RGMII clocks must be enabled to avoid IO timing degradation due to Assymetric Aging
   LCPD-1171,DRA7: DMM errata i878 (framebuffer part)
   LCPD-1146,DMM hang: Errata VAYU-BUG02976 (i878) (register part)
   LCPD-1108,J6: Wrong Access In 1D Burst For YUV4:2:0-NV12 Format (Errata i631)
   LCPD-1087,J6: MMC: Errata: i802: OMAP5430 MMCHS: DCRC errors during tuning procedure
   LCPD-1022,J6: Errata: i694: System I2C hang due to miss of Bus Clear support @ OMAP level
   LCPD-976,J6/J6eco: 32clk is psuedo (erratum i856) - clock source
   LCPD-975,J6/J6eco: 32clk is psuedo (erratum i856) - realtime counter
   LCPD-941,"OMAP4,5: DSS: implement workaround for errata i740"
   LCPD-876,OMAP5: "Errata i810: DPLL Controller Sticks when left clock requests are removed"

|

SDK Known Issues
-----------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   LCPD-14263,am43xx-epos,Hardware RNG module not getting probed in Linux for AM438x,
   LCPD-15029,j721e-vlab,tidec_decode app crashes the system when run several times,
   LCPD-17182,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",Android: j721e: unable to boot to UI with 2K display,
   LCPD-16454,j721e-evm,DSS underflows with 1080p/2.5k display on inmate cell,
   LCPD-17387,"j721e-evm-ivi, j721e-idk-gw",Underflow and CRTC SYNC LOST observed while running GLMark2 (1x1080p + 1x4k),
   LCPD-17164,"am335x-evm, am571x-idk, am574x-idk, am57xx-evm, dra71x-evm, dra7xx-evm",GLBenchmark is not able to run missing libgbm.so.2 error reported,create a symlink for linker file
   LCPD-17213,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",Weston sometimes fails to start when booting with nfs filesystem,
   LCPD-16921,j721e-evm,GPU driver doesn't unregister genpd name on unload,
   LCPD-17659,am437x-idk,Disable GPU on AM437x IDK,
   LCPD-16664,"am654x-evm, am654x-idk",MMU Alloc errors and Kernel Oops with RT build,
   LCPD-15864,am57xx-evm,SoC Performance Monitoring tool is still not enabled,
   LCPD-16366,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",RGX kick test fails when 32 sync dependencies are set for each command,
   LCPD-15794,"am57xx-evm, dra71x-evm, dra72x-evm, dra76x-evm, dra7xx-evm",Allow non-root user access to graphics resources to enable graphics use case,
   LCPD-16130,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",Exception triggered by drm_dev_unregister during poweroff,
   LCPD-12270,dra72x-evm,VDD_SHV5 power consumption is ~ 200mw higher than on previous releases,
   LCPD-13429,,Init/exit sequence in GBM leads to error,None
   LCPD-10964,dra76x-evm,Segmentation fault observed when trying to run GC320 test app,
   LCPD-17412,am654x-evm,QT5 Webengine-based browser crashing with any resize operation,
   LCPD-17413,"am335x-evm, am43xx-gpevm, am57xx-evm, am654x-evm",QT Webengine-based browser: the mouse does not work within the web page with QPA EGLFS,
   LCPD-17370,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",Android: Executing Andebenchpro benchmark app results in kernel crash,
   LCPD-15410,dra7xx-evm,vdd_shv_power is ~200mw higher than on previous lts,
   LCPD-18214,dra7xx-evm,SGX-HW recovery seen with NV12 buffer usage with wayland-drm applications,
   LCPD-18115,j721e-idk-gw,PVR Error observed while running glmark2,
   LCPD-9616,am57xx-evm,QtCreator GDB (remote) debugging stops working since QT5.7.1,use GDB from Processor SDK 3.2
   LCPD-9006,"am57xx-evm, dra72x-evm, dra7xx-evm",Some GLBenchmark tests fail to run,
   LCPD-9819,"am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm",drmextended app cannot enable plane,
   LCPD-7130,dra7xx-evm,KMSCube with video does not work,
   LCPD-8352,"am43xx-gpevm, am57xx-evm, dra7xx-evm",weston: stress testing with 75 concurrent instances of simple-egl leads to unresponsive HMI due to running out of memory,1. Restart Wayland application. 2. Restart board if Weston is killed by oom-killer
   LCPD-16877,k2hk-evm,ti-ipc-examples-linux intermittent build failure,
   LCPD-17283,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",Running Gstreamer's gst-discoverer causes a crash,
   LCPD-17138,,Kernel warning reported during h264 video encode operations,
   LCPD-15810,"am335x-evm, am43xx-gpevm, k2g-evm",Illegal instruction reported when trying to decode h264 stream with gstreamer,None
   LCPD-15795,"am57xx-evm, dra71x-evm, dra72x-evm, dra76x-evm, dra7xx-evm",Allow non-root user access to IPC resources to enable multimedia use case,
   LCPD-13817,am654x-evm,Qt5 Webengine-based broswer does not work on AM654x with pagesize = 64k,
   LCPD-13816,am654x-evm,Chromium-wayland broswer does not work on AM654x with page size = 64k,
   LCPD-13443,am57xx-hsevm,Camera is not detected on AM572x-HSEVM,
   LCPD-16531,j721e-evm,video decode: vxd_dec warnings displayed at end of gstreamer hevc playback to kmssink for certain video,
   LCPD-9754,"am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm, dra71x-evm, dra71x-hsevm, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm",GLSDK Sometimes capture + encode fails,
   LCPD-9753,"am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm",GLSDK gst test suite waylandsink and 1080i kmssink tests fail,
   LCPD-5654,AM335x,AM3 Beaglebone black: MPEG4+AAC Dec does not play out any audio for some HDMI monitors,
   LCPD-16207,am574x-hsidk,Board does not boot sometimes due to crypto crash when debug options are enabled,None
   LCPD-12709,am43xx-hsevm,Boards resets when standby state is attempted,
   LCPD-17817,"am335x-hsevm, am43xx-epos, am43xx-hsevm, k2e-hsevm, k2g-hsevm, k2hk-hsevm, k2l-hsevm",Images created with Proc-SECDEV grow with number of times SECDEV has been used,
   LCPD-17781,am43xx-epos,am43xx-epos boot instability,
   LCPD-9364,am57xx-hsevm,There are SCM FW warnings during the am57xx-hsevm boot,
   LCPD-9254,am43xx-hsevm,Kernel warnings in boot for am437x-hsevm,
   LCPD-9782,k2e-hsevm,CPU hotplug generates an exception and system crashes,
   LCPD-20038,am64xx-evm,OPTEE test applications are missing from rootfs,
   LCPD-16114,"am335x-evm, am335x-ice, am335x-sk",RTC Init Script Needs to Wait for Module Load,
   LCPD-15562,,OpenSSL1.1 does not have hooks for using hw crypto,Use openssl1.0 for crypto
   LCPD-14552,,Enable snmpd in coresdk,
   LCPD-14254,"am654x-evm, am654x-idk",meta-ti: Need a recipe update to pick up the new AM65x PRU Ethernet firmwares,
   LCPD-12443,omapl138-lcdk,SD boot time with coresdk rootfs increases ~30% on omapl138-lcdk,
   LCPD-12405,"am335x-evm, am335x-ice, am43xx-epos, am43xx-gpevm, am57xx-evm, dra71x-evm, k2e-evm, k2e-hsevm, k2g-evm, k2g-hsevm, k2l-evm",Openssl certgen fails due to coredump in openssl_gen_cert.sh,
   LCPD-12383,omapl138-lcdk,Umount failed if sata is mounted as vfat after boot without enough delay before umount,
   LCPD-16053,"k2e-evm, k2g-evm, k2hk-evm, k2l-evm",IP address is not getting displayed on EVM LCD for K2 EVMs,
   LCPD-15918,"am43xx-gpevm, dra7xx-evm, k2g-evm, k2l-hsevm",ti-ipc-rtos gets stuck in xdctools,
   LCPD-13947,am335x-evm,nativesdk-opkg is broken in the devkit,
   LCPD-9415,,File system is missing resource visualization tool,
   LCPD-9072,"k2e-evm, k2e-hsevm, k2hk-evm, k2hk-hsevm, k2l-evm, k2l-hsevm",netapi requires changes due to new libnl and xfrm,
   LCPD-9923,"am335x-evm, am43xx-gpevm, am57xx-evm, k2e-evm, k2g-evm, k2hk-evm, k2l-evm",Error message in boot log for K2 and AM platforms,
   LCPD-4952,"K2E, K2G, K2HK, K2L",tisdk-image.bbclass limitation on TARGET_IMAGES,
   LCPD-5091,AM335x,Installing AM335x CoreSDK 15.01 leads to dumped core,
   LCPD-5649,"K2E, K2HK, K2L",Integration: Release content for core-sdk should not be the content of SD card for k2 platform,
   LCPD-7255,"am335x-evm, am335x-ice, am335x-sk, am43xx-gpevm, am43xx-hsevm, am437x-idk, am437x-sk, am571x-idk, am572x-idk, am57xx-evm, beaglebone, beaglebone-black, beaglebone-black-ice, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm, k2e-evm, k2g-evm, k2g-ice, k2hk-evm, k2l-evm",Telnet login takes too long (~40 seconds),"Booting with rootfs mounted over NFS might cause ~40 seconds delay on telnet login because DNS entries might not be properly populated. To work around this issue, enter appropriate DNS server IP in resolv.conf. For example: echo 'nameserver 192.0.2.2' > /etc/resolv.conf;" 
   LCPD-8404,,Fix jira check script to only send one email per broken instance,
   LCPD-7025,am43xx-gpevm,System takes more than 10 seconds to go from login prompt to system prompt,Automated tests need to account for this boot delay
   LCPD-8345,"am335x-evm, am437x-idk, dra7xx-evm, dra7xx-hsevm, k2e-evm, k2e-hsevm, k2hk-evm, k2l-evm","Board fails to start login console after waiting 3.5 minutes ( hard to reproduce, ~4/1000)",Restart the EVM
   LCPD-4327,AM572x,remove temporary files from kernel package,
   LCPD-17449,"am335x-evm, am335x-hsevm, am335x-ice, am335x-sk, am43xx-epos, am43xx-gpevm, am43xx-hsevm, am437x-idk, am437x-sk, am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm, am654x-evm, am654x-idk, am654x-hsevm, beaglebone, beaglebone-black, dra71x-evm, dra71x-hsevm, dra72x-evm, dra72x-hsevm, dra76x-evm, dra76x-hsevm, dra7xx-evm, dra7xx-hsevm",libasan_preinit.o is missing in devkit,
   LCPD-4890,,ECS_TEAM: ap_test.sh demo script does not work as is and changes required are documented here,
   LCPD-8686,,ECS: DRA7 - wl18xx_multi module insert/remove leads to mm_fault errors,
   LCPD-17368,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",Format support - Mismatch with DDK - Android Allocator (NV12),
   LCPD-8210,"am571x-idk, am572x-idk, am57xx-evm",QT Touchscreen interaction (Bear Whack) crash,
   LCPD-17304,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",Error Recovery Test for VDEC_ERROR_SR_ERROR does not trigger error,
   LCPD-9423,,kmscube with video: viddec3test sometimes return error 139,None
   LCPD-8398,"dra7xx-evm, dra7xx-hsevm",gsttestplayer: Reverse playback stops after next seek,
   LCPD-8278,k2e-hsevm,Secure boot takes more than 10 minutes,
   LCPD-15367,"am335x-evm, am574x-idk",Boot time increased about 15s,
   LCPD-20148,am335x-evm,am335x-evm: Yocto recipe in meta-processor-sdk needs to be fixed for origin reference,

|


U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-20131","am64xx-evm","am64xx uboot fails to enumerate devices attached to a usb hub on the first 'usb reset' call ",""
   "LCPD-20120","am64xx-evm","U-Boot user's guide does not mention AM64x",""
   "LCPD-19133","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk","Netconsole output corrupted when CONFIG_NETCONSOLE_BUFFER_SIZE >= 281",""
   "LCPD-18643","am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk","U-Boot: AM335x/AM473x: Both SPI CS signals get asserted",""
   "LCPD-17789","j721e-idk-gw","UBOOT J7:  Could not see UFS device by scsi scan",""
   "LCPD-17770","am654x-evm,am654x-idk,am654x-hsevm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw","U-Boot: Fix order of MCU R5 shutdown depending on cluster mode",""
   "LCPD-17406","j721e-idk-gw","U-boot: Uboot has no knowledge of memory reserved for remote cores",""
   "LCPD-17210","am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm","AM57x EVM could not boot when using DEFAULT_DEVICE_TREE=""am57xx-beagle-x15""",""
   "LCPD-16696","am654x-evm,am654x-idk","U-Boot does not recognize SD-Card after re-insert/change",""
   "LCPD-16524","am654x-evm,am654x-idk,am654x-hsevm","Need to adjust RMW bit when using enabling ECC","None"
   "LCPD-15873","am654x-evm","There is no dtbo in u-boot for PCIe x1 + usb3 daughter card","None"
   "LCPD-15725","","[Klokworks uboot] Resolve or indicate false positives on arch/arm/mach-omap2/emif-common.c",""
   "LCPD-15720","","[Klokworks uboot] Resolve or indicate false positives on drivers/dfu/dfu_ram.c",""
   "LCPD-15719","","[Klokworks uboot] Resolve or indicate false positives on arch/arm/mach-omap2/hwinit-common.c",""
   "LCPD-15711","","[Klokworks uboot] Resolve or indicate false positives on arch/arm/mach-omap2/omap5/sdram.c",""
   "LCPD-15710","","[Klokworks uboot] Resolve or indicate false positives on board/ti/common/board_detect.c",""
   "LCPD-15054","am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm","[u-boot] AM57xx phy_ctrl structures must be board-specific","None"
   "LCPD-14843","am654x-evm,am654x-idk","U-boot should support  default settings for netboot ","None"
   "LCPD-14638","k2g-evm,k2g-ice","Invalid  DDR_PHY_MR2 setting in K2G board library","None"
   "LCPD-12348","dra71x-evm,dra72x-evm,dra76x-evm,dra7xx-evm","U-boot: MMC/SD: MMC erase fails with timeout",""
   "LCPD-11197","dra72x-evm","Uboot: Writing GPT partitions to emmc causing CACHE: Misaligned messages",""
   "LCPD-10726","am572x-idk,am57xx-evm","Update DDR3 emif regs structure for EMIF2 for the beagle_x15 board in U-Boot board file","None"
   "LCPD-10668","k2g-evm","Ethernet boot: Sometimes the board could not boot uboot from Ethernet on k2g-evm","None"
   "LCPD-9539","k2g-evm","dhcp does not work after soft reboot","None"
   "LCPD-9369","","AM437x GP EVM older PG version Uboot UART boot fails intermittently",""
   "LCPD-8701","k2g-ice","Soft reboot broken",""
   "LCPD-8295","dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra7xx-evm,dra7xx-hsevm","vout1 pins missing manual i/o configuration",""
   "LCPD-7864","am335x-evm,am335x-ice,am335x-sk,am43xx-gpevm,am437x-idk,am437x-sk","U-Boot: Ethernet boot fails on AM335x and AM437x",""
   "LCPD-7776","dra7xx-evm,dra7xx-hsevm","U-boot: DRA7XX: secure boot fails on Rev-G J6 EVM",""
   "LCPD-7547","k2g-evm","uboot nand write hangs for big size on k2g",""
   "LCPD-7366","am335x-evm","uboot McSPI driver drives multiple chip selects simultaneously","None"
   "LCPD-5517","AM572x","Board fails to load bootloader sometimes when eSATA is connected","None"
   "LCPD-5416","K2G","U-BOOT: K2G: ""reset"" fails for certain SD cards","None"
   "LCPD-5116","AM335x","BBB: U-Boot: Board fails to acquire dhcp address sometimes","None"
|


Linux Kernel Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround" 
   :widths: 5, 10, 70, 35

   "LCPD-20177","j7200-evm","J7200 UART boot not working",""
   "LCPD-20171","am64xx-evm","AM64x: Occasional boot failure due to dmesg log about cdns-usb3 that blocks the prompt ",""
   "LCPD-20170","am654x-evm,am654x-idk","am654x UART boot not working",""
   "LCPD-20169","am64xx-evm","AM64x: CPSW3g link can take up to 45 seconds to come back up",""
   "LCPD-20168","am64xx-evm","USB driver trace seen on boot",""
   "LCPD-20165","am64xx-evm","TSN PTP binary testptp not present by default in am64 filesystem",""
   "LCPD-20164","am64xx-evm","TSN IET (Frame Preemption) eth0 link sometimes does not come back up after configuring",""
   "LCPD-20163","am64xx-evm","am64xx fails to boot when using the mmcmode custom build",""
   "LCPD-20162","am64xx-evm","Degraded performance when running IET tests over eth1",""
   "LCPD-20130","am64xx-evm","am64xx PCIe-EP test failing due to a NULL pointer exception",""
   "LCPD-20122","am64xx-evm","am64xx not recognizing a USB stick attached to a PCIe USB card",""
   "LCPD-20119","am64xx-evm","Kernel user's guide does not mention ARM64 or AM64x",""
   "LCPD-20111","am64xx-evm","TSN IET (Frame Preemption) iperf3 network is unreachable with VLAN",""
   "LCPD-20107","am64xx-evm","USBDEVICE Bi-directional iperf test fails on am64xx when running from dut to server",""
   "LCPD-20106","am64xx-evm","USBDEVICE ping from DUT to host fails when packet_count=470",""
   "LCPD-20105","am64xx-evm","AM64x: Kernel: ADC: RX DMA channel request fails",""
   "LCPD-20074","","drivers/net/ethernet/ti/icssg_classifier.c:402:6: warning: no previous prototype for 'icssg_class_add_mcast'",""
   "LCPD-20061","am64xx-evm","Occasional PHY error during during TSN Time-Aware Shaper execution",""
   "LCPD-20055","am64xx-evm","Assign am64xx GPIO test pins in ltp-ddt",""
   "LCPD-20050","am64xx-evm","Ramfs does not support ti-test installation due to 2GB RAM on AM64",""
   "LCPD-20006","am64xx-evm","AM64x: remoteproc may be stuck in the start phase after a few times of stop/start",""
   "LCPD-20004","am64xx-evm","AM64: g_ether module failing to bringup link on host side",""
   "LCPD-19216","k2e-evm","K2E PCIe is not enumerated when EVM boots up cold",""
   "LCPD-19068","j721e-evm,j721e-evm-ivi,j721e-idk-gw","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame",""
   "LCPD-18044","omapl138-lcdk","Seeing kernel oops when bring up USB Ethernet interface",""
   "LCPD-18020","dra72x-evm","fatwrite failed to write ipu firmware to boot partition on dra72",""
   "LCPD-17995","omapl138-lcdk","Failed to insert 'g_multi' on omapl138",""
   "LCPD-17908","am654x-evm,am654x-idk","ICSSG: dual-emac: udp packets ocassionally sent out of order on egress",""
   "LCPD-17873","omapl138-lcdk","SATA delays resume time by 10+ seconds sometimes",""
   "LCPD-17814","j721e-idk-gw","Kingston 16G card could not boot to uboot prompt",""
   "LCPD-17800","am654x-evm,am654x-idk","CPSW: Master/Slave resolution failed message seen at console",""
   "LCPD-17794","j721e-idk-gw","ext4write failed to write firmware to SD card",""
   "LCPD-17790","am335x-evm","AM335x: USB Device: 15% performance drop",""
   "LCPD-17782","","INTRTR: Spurious interrupts generated when programming certain Interrupt Routers",""
   "LCPD-17780","am654x-evm,j721e-idk-gw","Mbox timedout in resp",""
   "LCPD-17777","am654x-evm","AES HW is not exercised",""
   "LCPD-17673","am335x-evm,am43xx-gpevm,am571x-idk,am572x-idk,am574x-idk,am57xx-evm,am654x-evm,beaglebone-black,dra71x-evm,dra72x-evm,dra7xx-evm,j721e-evm","No software documentation for the Timer module",""
   "LCPD-17543","j721e-evm,j721e-evm-ivi,j721e-idk-gw","Some cpuhotplug tests failed",""
   "LCPD-17471","am654x-evm,am654x-idk","device hang when restarting crashed R5F",""
   "LCPD-17421","j721e-idk-gw","CPSW9G: Can't bring up interface over NFS",""
   "LCPD-17418","j721e-idk-gw","J7 sometimes failed to boot","Flash firmware into mmc rootfs"
   "LCPD-17403","j721e-evm-ivi,j721e-idk-gw","PAT: DMA-API warning",""
   "LCPD-17387","j721e-evm-ivi,j721e-idk-gw","Underflow and CRTC SYNC LOST observed while running GLMark2 (1x1080p + 1x4k)",""
   "LCPD-17373","dra71x-hsevm,dra72x-hsevm,dra76x-hsevm,dra7xx-hsevm","ARM Exception from PPA Signature Verification Call on HS Device","In our SDK solution OP-TEE replaces the Secure ROM. OP-TEE does not use the Crypto HWA so we let the kernel manage and disable/enable them as needed. If one would like to continue using the Secure ROM then, as you have figured out in the description, you need to add the Crypto HWAs to the list of non-hwmod controlled devices (like we do for TRNG and GPTIMER12 that OP-TEE does use). We cant do this by default as our default configuration is to let the kernel crypto driver use these devices."
   "LCPD-17284","j721e-evm,j721e-evm-ivi,j721e-idk-gw","remoteproc/k3-r5: Cores are started out-of-order when core 0 file size >> core 1 file size",""
   "LCPD-17172","j721e-idk-gw","Uboot USBhost: Sandisk Extreme USB 3.0 msc stick could not be detected at second time",""
   "LCPD-17171","j721e-idk-gw","Uboot dhcp occasionally failed",""
   "LCPD-17113","j721e-idk-gw","[Cpsw9g][VirtualDriver][VirtualMAC] rpmsg_kdrv_switch is not autoloaded",""
   "LCPD-17017","j721e-evm-ivi,j721e-idk-gw","J7: DSS underflows seen on various use cases",""
   "LCPD-17006","j721e-evm","4k DP Display Shows Blank Screen sometimes when booting",""
   "LCPD-16877","k2hk-evm","ti-ipc-examples-linux intermittent build failure",""
   "LCPD-16845","am654x-evm,am654x-idk","OPP freq update in DT impacts only cluster0",""
   "LCPD-16836","j721e-idk-gw","DP: GeChic display EDID read failures with custom DP cable",""
   "LCPD-16642","am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm","omapdrm: in some cases, DPI output width does not need to be divisible by 8",""
   "LCPD-16640","j721e-idk-gw","PCIe RC: GIC ITS misbehaves when more than 4 devices use it simultaneously",""
   "LCPD-16628","j721e-idk-gw","Could not enumerate PLEXTOR pcie SSD",""
   "LCPD-16616","j721e-evm,j721e-evm-ivi,j721e-idk-gw","Jailhouse: Failure in mhdp probe while restarting the Linux VM",""
   "LCPD-16594","dra7xx-evm","Seeing kernel traces during pcie wifi tests",""
   "LCPD-16591","j721e-idk-gw","PCIe wifi ping stress test failed",""
   "LCPD-16560","omapl138-lcdk","OMAPL-138 Resume from UART ",""
   "LCPD-16545","j721e-evm,j721e-evm-ivi,j721e-idk-gw","remoteproc/k3-r5f: PDK IPC echo_test image fails to boot up in remoteproc mode on second run",""
   "LCPD-16535","j721e-evm,j721e-evm-ivi,j721e-idk-gw","remoteproc/k3-dsp: PDK IPC echo test binaries fails to do IPC in remoteproc mode on second run",""
   "LCPD-16534","am654x-evm,am654x-idk","remoteproc/k3-r5f: PDK IPC echo_test image fails to do IPC in remoteproc mode on second run","None"
   "LCPD-16505","j721e-evm","Wrong clock rate is reported for 157:400, 157:401 (HSDIVIDER after PLL4 and 15)",""
   "LCPD-16454","j721e-evm","DSS underflows with 1080p/2.5k display on inmate cell",""
   "LCPD-16451","j721e-evm","DP: if cable is not connected, DPCD transactions mess up the driver",""
   "LCPD-16437","am335x-evm","Nand with prefetch dma: read perf drop ~20% comparing to 2018",""
   "LCPD-16406","am654x-idk","Seeing ""e1000#0: ERROR: Hardware Initialization Failed"" sometimes when do dhcp via pcie-eth",""
   "LCPD-16396","j721e-evm,j721e-evm-ivi,j721e-idk-gw","J721E: RC: Unsupported request in configuration completion packets results in an abort","Workaround for Multifunction: Configure all the physical functions supported by the endpoint. For configuring all the 6 functions of PCIe  controller instance '1' in J721E, the following can be used. mount -t configfs none /sys/kernel/config; cd /sys/kernel/config/pci_ep/; mkdir functions/pci_epf_test/func1; echo 0x104c > functions/pci_epf_test/func1/vendorid; echo 0xb00d > functions/pci_epf_test/func1/deviceid; echo 1 > functions/pci_epf_test/func1/msi_interrupts; echo 16 > functions/pci_epf_test/func1/msix_interrupts; ln -s functions/pci_epf_test/func1 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func2; echo 0x104c > functions/pci_epf_test/func2/vendorid; echo 0xb00d > functions/pci_epf_test/func2/deviceid; echo 1 > functions/pci_epf_test/func2/msi_interrupts; echo 16 > functions/pci_epf_test/func2/msix_interrupts; ln -s functions/pci_epf_test/func2 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func3; echo 0x104c > functions/pci_epf_test/func3/vendorid; echo 0xb00d > functions/pci_epf_test/func3/deviceid; echo 1 > functions/pci_epf_test/func3/msi_interrupts; echo 16 > functions/pci_epf_test/func3/msix_interrupts; ln -s functions/pci_epf_test/func3 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func4; echo 0x104c > functions/pci_epf_test/func4/vendorid; echo 0xb00d > functions/pci_epf_test/func4/deviceid; echo 1 > functions/pci_epf_test/func4/msi_interrupts; echo 16 > functions/pci_epf_test/func4/msix_interrupts; ln -s functions/pci_epf_test/func4 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func5; echo 0x104c > functions/pci_epf_test/func5/vendorid; echo 0xb00d > functions/pci_epf_test/func5/deviceid; echo 1 > functions/pci_epf_test/func5/msi_interrupts; echo 16 > functions/pci_epf_test/func5/msix_interrupts; ln -s functions/pci_epf_test/func5 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func6; echo 0x104c > functions/pci_epf_test/func6/vendorid; echo 0xb00d > functions/pci_epf_test/func6/deviceid; echo 1 > functions/pci_epf_test/func6/msi_interrupts; echo 16 > functions/pci_epf_test/func6/msix_interrupts; ln -s functions/pci_epf_test/func6 controllers/d800000.pcie-ep/; echo 1 > controllers/d800000.pcie-ep/start; echo 1 > /sys/bus/pci/devices/0000:00:00.0/remove; echo 1 > /sys/bus/pci/rescan; Workaround for switch card: No workarounds available."
   "LCPD-16208","j721e-evm","FIFO Underflows during video playback on 4k panel",""
   "LCPD-16048","am654x-evm,am654x-idk","UDP iperf with smaller packet sizes < 512 bytes does not complete consistently",""
   "LCPD-15887","omapl138-lcdk","The boot time increase ~30s on omapl138-lcdk",""
   "LCPD-15885","k2hk-evm","Uboot usb start trigger the board resetting with one usb stick",""
   "LCPD-15857","","Kernel Panic with Multiple PRUETH Ports",""
   "LCPD-15819","am654x-evm","tidss: the driver should reject dual-display setup, as it is not supported",""
   "LCPD-15787","am335x-evm","Power suspend fails due to USB (scsi_bus_suspend) failure when HDD is in use",""
   "LCPD-15768","","RNDIS performance dropped in 2019 LTS",""
   "LCPD-15708","j721e-vlab","J721E: vlab: MMC1 not functional",""
   "LCPD-15695","","[Klokworks] Resolve or indicate false positives on drivers/clk/ti/clkctrl.c",""
   "LCPD-15660","k2g-evm","pcie sata or usb drive no device node being created",""
   "LCPD-15649","am57xx-evm","Uboot: sata could not be detected ",""
   "LCPD-15648","am335x-evm","Uboot mmc write performance decreased",""
   "LCPD-15635","dra71x-evm","mmc hotplug causes one board reboot",""
   "LCPD-15540","am57xx-evm,am654x-evm,dra71x-evm,dra7xx-evm","uvc-gadget results in segmentation fault",""
   "LCPD-15518","am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm","omapdrm: WB M2M: Headless mode is not working",""
   "LCPD-15461","dra7xx-evm","pcie usb failed to enumerate sometimes on dra7xx",""
   "LCPD-15402","am571x-idk,am572x-idk,am574x-idk,am57xx-evm,am57xx-beagle-x15,dra71x-evm,dra72x-evm,dra76x-evm,dra7xx-evm","rpmsg-rpc: test application does not bail out gracefully upon error recovery",""
   "LCPD-15400","am571x-idk,am572x-idk,am574x-idk,am57xx-evm,am57xx-beagle-x15,dra71x-evm,dra72x-evm,dra76x-evm,dra7xx-evm","remoteproc/omap: System suspend fails for IPU1 domain without any remoteprocs loaded",""
   "LCPD-14961","k2g-ice","k2g-ice: Ethernet port Eth0 doesn't get IP address when Jumper J3 is not mounted","None"
   "LCPD-14855","am335x-evm,am335x-ice,am335x-sk","omap_i2c_prepare_recovery() function can Lock System",""
   "LCPD-14249","j721e-vlab","PCI kernel oops seen between rc7 and rc8 of 4.19",""
   "LCPD-14191","am335x-evm,am57xx-evm","IPSec hardware-based throughput is 30% lower than 2018.03",""
   "LCPD-14183","am654x-idk","am654x-idk failed to login to kernel a few times (7/1000)",""
   "LCPD-14171","am57xx-evm,dra7xx-evm","Failed to read uboot from SD card 1/1000 times",""
   "LCPD-13938","am654x-evm,dra71x-evm,dra7xx-evm,k2g-evm","PCIe EP read/write/copy test failed with larger sizes ",""
   "LCPD-13936","am654x-evm","Uboot dhcp timeout 1 of 100 times",""
   "LCPD-13720","beaglebone-black","SPI DMA TX Mode Halts During Continuous 16/32/64 bit Transfers ",""
   "LCPD-13653","am654x-evm,am654x-idk","am65x-evm could not boot from MMC/SD when MMC/SD is backup boot mode","No workaround"
   "LCPD-13603","am654x-evm","One board could not boot rootfs from more than one SDHC card",""
   "LCPD-13478","dra76x-evm","kexec fails on some setups",""
   "LCPD-13458","dra76x-evm","MCAN FIFO errors seen in receive CANFD tests",""
   "LCPD-13452","k2g-evm","USB Gadget Camera Capture - guvcview causes kernel oops",""
   "LCPD-13445","am654x-evm","Seldom kernel oops triggered by prueth_netdev_init",""
   "LCPD-13412","am57xx-evm","VIP camera sensor (mt9t11) is not initialized properly",""
   "LCPD-13410","am654x-evm,am654x-idk","Reboot command is not operational",""
   "LCPD-12784","omapl138-lcdk","Board can't resume from suspend state sometimes",""
   "LCPD-12777","dra72x-evm","PCIe link is not up for Inateck pcie-usb card",""
   "LCPD-12718","dra7xx-evm","8250: serialcheck external loop back testing failure",""
   "LCPD-12680","k2g-evm","Seeing i2c timeout error and board failed to boot",""
   "LCPD-12673","omapl138-lcdk","Board refuses to suspend on setup with SATA device",""
   "LCPD-12423","dra72x-evm","PCIe fails to reach suspend target state sometimes ",""
   "LCPD-12392","am335x-evm","USBhost video: higher resolution tests fail with some cameras",""
   "LCPD-12273","dra7xx-evm","i2c controller timed out during DVFS",""
   "LCPD-12226","am43xx-gpevm,am574x-idk,am57xx-evm,omapl138-lcdk","mmcsd first write perf decreased on some platforms",""
   "LCPD-11952","am571x-idk,dra72x-evm","AM57x: disabling USB super-speed phy in DT causes kernel crash",""
   "LCPD-11570","k2g-evm","Base ubi filesystem could not be mounted as ubifs on k2g-evm",""
   "LCPD-11564","am57xx-evm","AM57xx-evm: eth1 1G connection failure to netgear switch",""
   "LCPD-11138","am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,dra7,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm","VIP driver multi-channel capture issue with TVP5158",""
   "LCPD-10997","dra76x-evm","ABB voltage did not increase for 1800 MHz",""
   "LCPD-10974","am43xx-gpevm","am43xx-gpevm - usb camera gadget shows halting frames","None"
   "LCPD-10781","k2g-evm","NetCP module removal results in backtrace and kernel panic",""
   "LCPD-10777","omapl138-lcdk","mtd_stresstest failed on omapl138",""
   "LCPD-10707","dra76x-evm,dra7xx-evm","Few PCIe cards could not enumerated on dra7xx and dra76x",""
   "LCPD-10551","k2e-evm","K2E eth0 does down when running udp traffic, eth1 stops working",""
   "LCPD-10455","k2g-evm,k2g-ice,k2hk-evm,k2l-evm","remoteproc/keystone: Hang observed while running RPMSG_PROTO example app",""
   "LCPD-10223","k2hk-evm","Keystone-2 Linking RAM region 0 size register REGION0_SIZE programming",""
   "LCPD-10221","am335x-evm","Longer resume times observed on setup with usb device cable",""
   "LCPD-10158","","Matrix power demos fails on DRA71x platform",""
   "LCPD-9981","j721e-vlab,omapl138-lcdk","Some LTP's memory management tests fail due to low amount of free memory",""
   "LCPD-9980","omapl138-lcdk","LTP's math tests float_exp_log and float_trigo fail due to OOM",""
   "LCPD-9974","am571x-idk","PCIe x2 width is not at expected width on am571x-idk",""
   "LCPD-9972","k2g-evm","Soft reboot failed on k2g-evm with class 10 SD cards","Do not use soft reboot"
   "LCPD-9877","omapl138-lcdk","rtc alarm does not wakeup board from poweroff state",""
   "LCPD-9816","omapl138-lcdk","USBdevice omapl138 -  Flood ping from server to dut usbdevice at 65500 bytes has packet loss",""
   "LCPD-9815","omapl138-lcdk","Failed to start Login Service when using debug systest build on omapl138",""
   "LCPD-9804","omapl138-lcdk","SATA performance decreased by ~34% for read and ~54% for write compared to v2.6.33 kernel",""
   "LCPD-9801","omapl138-lcdk","remoteproc/davinci: DSP boot is broken after a suspend/resume cycle",""
   "LCPD-9756","omapl138-lcdk","pm_runtime does not kicks in for some IPs (serial, gpio and wdt)",""
   "LCPD-9658","omapl138-lcdk","OMAP-L138 LCDK: MUSB does not enumerate mouse connected to Keyboard hub",""
   "LCPD-9591","","CONNECTIVITY: USB NCM gadget ping with packet sizes > 10000 fails",""
   "LCPD-9589","am335x-evm","I2C: Sometimes i2c read write failed on farm01 and farm02",""
   "LCPD-9527","am335x-evm,am335x-sk,beaglebone,beaglebone-black","Potential deadlock reported by pm_suspend on am335x",""
   "LCPD-9481","am571x-idk,am572x-idk,am57xx-evm,am57xx-hsevm","Sometime the system hangs while loading the rpmsg rpc modules",""
   "LCPD-9466","am57xx-evm,dra7xx-evm","SATA PMP causes suspend failures",""
   "LCPD-9455","am335x-evm","Kernel Warning reported for a USB audio device when listing with pulseaudio",""
   "LCPD-9428","k2e-evm,k2hk-evm,k2l-evm","Ethernet performace UDP: iperf command fails with two threads for lower buffer length",""
   "LCPD-9427","dra71x-evm","vip error logs during gst-capture-encode testcases",""
   "LCPD-9402","dra72x-evm","DRA72x: HDMI display EDID read fails on Rev B EVM","Add the required HDMI modes into the kernel binary as per instructions in http://lxr.free-electrons.com/source/Documentation/EDID/"
   "LCPD-9372","am335x-evm","Nand stress tests failed on a particular am335x-evm board",""
   "LCPD-9366","k2g-evm","PCIe USB drive sometimes could not be enumerated",""
   "LCPD-9284","dra7xx-evm","DRA7xx: HDMI starting with non-preferred mode on boot",""
   "LCPD-9222","am572x-idk","PRUSS Ethernet does not work on AM572x ES1.1",""
   "LCPD-9027","dra71x-evm,dra72x-evm,dra7xx-evm","There is some warning regarding spi_flash_read when do ubimkvol",""
   "LCPD-9011","k2g-evm","K2G-evm: usb devices do not enumerate behind a TUSB8041 usb3.0 hub","None"
   "LCPD-8984","k2e-evm,k2l-evm","Kernel boot to initramfs with PA enabled results in no DHCP IP address assigned to network interfaces",""
   "LCPD-8637","","K2HK: Long-term ping test fails due to ethernet link going down",""
   "LCPD-8636","am335x-evm,dra72x-evm,dra7xx-evm","Serial corruption being seen in kernel",""
   "LCPD-8550","am335x-sk","CPSW memory allocation errors seen during boot",""
   "LCPD-8477","k2e-evm,k2e-hsevm,k2g-evm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm,k2l-hsevm","K2: serdes nodes doesn't have a functional clock",""
   "LCPD-8406","k2g-evm,k2g-ice","K2G: PADCONFIG_202 register cannot be re-programmed","This has proven to be a silicon issue related to locking RSTMUX. It is currently being discussed if it will be fixed in a newer silicon revision. Currently to avoid this issue the affected pins pinmux are not changed in the kernel. This is because U-boot locks RSTMUX which causes problems if the kernel tries to change the pinmuxing for the pins."
   "LCPD-8350","am57xx-evm","UART boot does not work on am57xx-evm",""
   "LCPD-8347","k2e-evm,k2g-evm","BUG: sleeping function called from invalid context triggered by keystone_pcie_fault",""
   "LCPD-8336","am43xx-hsevm","Soft reboot does not work on am43xx-hsevm rev1.5b",""
   "LCPD-8270","k2g-evm","K2: SerDes driver need to enable PD of the peripheral before access the SerDes h/w",""
   "LCPD-8257","k2g-evm","Boot failed 1 of 1000 times on k2g",""
   "LCPD-8133","am335x-evm","USB: ""cannot reset"" errors observed sometimes",""
   "LCPD-8100","k2g-evm","CONNECTIVITY: K2G ethernet performance numbers are low",""
   "LCPD-8078","am335x-sk","AM3 SK: Touchscreen isn't responsive",""
   "LCPD-8033","","AM3 SK: Unexpected USB2-1 Messages on UART",""
   "LCPD-8000","dra7xx-evm,dra7xx-hsevm","VIP: RGB: RGB capture error due to wrong data path setting",""
   "LCPD-7998","am572x-idk","Realtime OSADL Test results degraded slightly for am572x-idk",""
   "LCPD-7955","am335x-evm,am43xx-gpevm,k2e-evm,k2g-evm,k2g-ice,k2hk-evm,k2hk-hsevm,k2l-evm","Uncorrectable Bitflip errors seen after switch to SystemD","Workaround to erase the NAND flash completely if flashed with an incompatible flash writer. SystemD tries to mount all partitions and that is the reason this is being seen now."
   "LCPD-7903","k2g-evm,k2hk-evm","Uboot phy startup failed and dhcp failed occasionally on k2 board",""
   "LCPD-7829","am57xx-evm","uboot: UHS card did not work on the expected speed in uboot",""
   "LCPD-7744","am57xx-evm","UHS SDR104 card works on different speed after soft reboot",""
   "LCPD-7735","am57xx-evm,dra71x-evm,dra71x-hsevm,dra72x-evm,dra7xx-evm","Powerdomain (vpe_pwrdm) didn't enter target state 0",""
   "LCPD-7705","dra7xx-evm,dra7xx-hsevm","DRA7X: SATA: specific Port multiplier (JMicron) connected to dra7x enumerates at 1.5Gbps","None"
   "LCPD-7697","dra7xx-evm,dra7xx-hsevm","OV1063x configuration breaks if kernel is compiled with CONFIG_DEBUG_GPIO=n","Enable the CONFIG_DEBUG_GPIO"
   "LCPD-7696","am571x-idk,am572x-idk,am57xx-evm,am57xx-hsevm,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra7xx-evm,dra7xx-hsevm","DRA7xx: VPE: File2File checksum changes across multiple runs","There is no workaround for this issue yet"
   "LCPD-7695","dra7xx-evm","DRA7xx: building Ov1603x as a module causes a green tint in captured image","The workround is to use the camera driver as builtin. Also, a delay of 1s can stop this issue from occuring"
   "LCPD-7623","k2hk-evm","Seeing SPI transfer failed error sometimes on k2hk when using rt kernel",""
   "LCPD-7575","dra72x-evm","PCIe-USB card sometime could not be detected",""
   "LCPD-7559","k2e-evm,k2hk-evm","K2E/K2HK does not enumerate usb3 devices through usb3.0 hub",""
   "LCPD-7495","k2hk-evm","Sometimes a Kernel Warning + Oops is seen when removing keystone_remoteproc module",""
   "LCPD-7480","k2e-evm,k2l-evm","K2L/E EVMs doesn't boot to Linux when both 1G Ethernet interfaces are connected",""
   "LCPD-7374","dra72x-evm,dra7xx-evm","DRA7x: Transcend 16G UHS card enumerated as SDR104 but there are errors showing up",""
   "LCPD-7323","dra72x-evm","Inconsistent resuts in power measurement during suspended mode",""
   "LCPD-7314","am335x-evm","Active power is slighly higher than on 2015 LTS release (Linux 4.1)",""
   "LCPD-7293","dra7xx-evm","[rpmsg 2016 LTS] ALL: iommu/remoteproc: _wait_target_disable failed trace",""
   "LCPD-7265","am57xx-evm","Uboot eMMC does not use HS200 on am57xx-gpevm",""
   "LCPD-7256","am335x-evm,am335x-hsevm,am57xx-evm,dra72x-evm,dra7xx-evm","Board sometimes hangs after suspend/resume cycle",""
   "LCPD-7188","am57xx-evm,dra72x-evm,dra7xx-evm","PCIe-SATA test failed","TI custom board would help with signal integrity issues being seen with the EVM."
   "LCPD-7147","dra72x-evm,dra7xx-evm","Intel LAN Card D33745 could not enumerated on J6",""
   "LCPD-7065","dra72x-evm,dra7xx-evm","PCIe-sata: Samsung SSD 120G harddisk could not enumerated",""
   "LCPD-6998","k2g-evm","K2G sometimes boot failed with kernel oops error","None"
   "LCPD-6663","","[RT] Kmemleak is buggy and boot is crashed randomly",""
   "LCPD-6334","k2g-evm","k2g-evm: NAND is untestable due to data corruption issues",""
   "LCPD-6301","dra72x-evm,dra7xx-evm","J6: A few SDR104 cards only enumerated as high speed card when use them as rootfs",""
   "LCPD-6300","am57xx-evm","am57xx-evm: A few UHS cards could not be numerated in kernel and mmc as rootfs failed.",""
   "LCPD-6120","dra7xx-evm","Ethernet Link not stable at 1G on Rev G DRA74x EVMs",""
   "LCPD-6075","am572x-idk,am57xx-evm,dra7xx-evm","BUG: using smp_processor_id() in preemptible [00000000] code during remoteproc suspend/resume",""
   "LCPD-5699","AM571x,AM572x","pci: am572x-idk: pci broadcom card doesn't enumerate",""
   "LCPD-5677","K2E","K2E-evm: Marvel SATA controller could not be detected sometimes when Power On Reset is involved",""
   "LCPD-5566","DRA72x,DRA74x","Suspend failed when running pcie-usb test",""
   "LCPD-5522","am571x-idk,am572x-idk,am57xx-evm,am57xx-hsevm,dra72x-evm,dra72x-hsevm,dra7xx-evm,dra7xx-hsevm","pcie-usb sometimes the usb drive/stick could not be enumerated",""
   "LCPD-5521","dra7xx-evm","Sporadic boot failure using debug image (~ 1/50)",""
   "LCPD-5380","AM572x","omapdss error: HDMI I2C Master Error","Occurs only with this monitor - http://www.amazon.com/gp/product/B00PFLZV2G"
   "LCPD-5362","am335x-evm","MUSB: Isoch IN only utilises 50% bandwidth",""
   "LCPD-4870","DRA74x","DRA74x EVM: suspend causes ""suspicious RCU usage""",""
   "LCPD-4855","am572x-idk,dra72x-evm","[rpmsg 2015 LTS] J6Eco: IPC: Board hangs when an MMU fault occurs in the first message",""
   "LCPD-4849","","K2hk: Connectivity: UART data corruption observed sometimes in loopback mode",""
   "LCPD-4699","am571x-idk,am572x-idk,am57xx-evm,dra72x-evm,dra7xx-evm","[rpmsg 2015 LTS] rpmsg-rpc: kernel crash during error recovery with dynamic debug traces enabled",""
   "LCPD-4503","dra7xx-evm","ALL: 8250 UART driver not enabeld as wake source by default",""
   "LCPD-1245","am335x-evm","AM335x: Power: Reverse current leakage on poweroff",""
   "LCPD-1239","am572x-idk,am57xx-evm,dra72x-evm,dra7xx-evm","Connectivity: DUT could not resume when PCI-SATA card is in",""
   "LCPD-1207","am43xx-gpevm,am57xx-evm,dra7xx-evm","AM43XX/AM57XX/DRA7: CONNECTIVITY: dwc3_omap on am43xx and xhci_plat_hcd on dra7 - removal results in segmentation fault",""
   "LCPD-1204","","AM335x - Some voltage rails remain active during poweroff",""
   "LCPD-1198","","am43xx-gpevm:Connectivity: when kmemleak debug is enabled and mmc stress test is run, OOM killer is seen to kick in. Does not happen without kernel debug.",""
   "LCPD-1191","am335x-evm","AM335x: Power: System resumes due to wakeup source USB1_PHY without any external trigger","Use GPIO interrupt instead of USB PHY for wakeup source."
   "LCPD-1144","","Logitech USB-PS/2 Optical Mouse cannot be detected every other time the system is suspended/resumed (AM335x-EVM)",""
   "LCPD-1106","am57xx-evm,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra7xx-evm,dra7xx-hsevm","Connectivity:PCIe-SATA ext2 1G write performance is poor due to ata failed command","None"
   "LCPD-1067","dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra7xx-evm,dra7xx-hsevm","J6: PCIe: Broadcom Ethernet cards cause kernel to hang after suspend/resume cycle",""
   "LCPD-1027","dra72x-evm","[rpmsg 2014 LTS] J6Eco: IPC: Board hangs when an MMU fault occurs in the first message",""
   "LCPD-1013","","AM335x: Power: Seldom short-duration power increase (~38mw) in VDDSHV4 domain",""
   "LCPD-998","AM335x","MUSB does not free urbs causing usb audio playback to fail",""
   "LCPD-965","","AM335x: Power: Poweroff is not shutting down voltage domains",""
   "LCPD-932","","AM33X: CONNECTIVITY: MUSB MSC read numbers are lower in 3.14 compared to 3.12",""
   "LCPD-885","dra7xx-evm","J6/J6eco: suspend-to-ram: l3init: USB clocks are active",""
   "LCPD-869","","AM335x: Connectivity: USB data transfer fails if board is suspended/resumed",""
   "LCPD-816","dra72x-evm,dra7xx-evm","J6/J6eco:Connectivity:PCIe-PCI eth bridge doesn't work on J6/J6eco",""
   "LCPD-799","dra7xx-evm","J6 and J6ECO: CONNECTIVITY: Backtrace during disconnect of usb camera during iso transaction",""
   "LCPD-727","","J6:Connectivity:SATA readwrite tests sometimes fail and dut hangs with cpuidle enabled",""
   "LCPD-671","","AM33XX: CONNECTIVITY: MUSB in PIO mode - video issues",""
   "LCPD-662","","CONNECTIVITY: AM335X: distortion in USB audio when msc connect/disconnect happens in parallel",""
   "LCPD-525","","AM438x: Connectivity: I2C operates 9% beyond desired frequency",""
