************************************
Release Notes
************************************
.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Release_Notes

Overview
========

The **Processor Software Development Kit (Processor-SDK) for Linux**
provides a fundamental software platform for development, deployment and
execution of Linux based applications and includes the following:

-  Bootloaders & Filesystems
-  SDK Installer
-  Setup Scripts
-  Makefiles
-  Matrix Application Launcher
-  Example Applications
-  WLAN support (Wilink 8)
-  Code Composer Studio

Licensing
=========

Please refer to the software manifest, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page. The manifest can be found on the SDK
download page or in the installed directory as indicated below. In
addition, see `PLSDK GPLv3 Disclaimer <Overview_GPLv3_Disclaimer.html>`__

Documentation
===============
-  `Processor SDK Linux Software Developer's Guide <index.html>`__: Provides information on features, functions, delivery package and,
   compile tools for the Processor SDK Linux release. This also provides
   detailed information regarding software elements and software
   infrastructure to allow developers to start creating applications.
-  `Processor SDK Linux Getting Started Guide <Overview_Getting_Started_Guide.html>`__: Provides information on getting the software and running
   examples/demonstrations bundled in the SDK.
-  **Software Manifest**: Provides license information on software
   included in the SDK release. This document is in the release at
   ``[INSTALL-DIR]/docs``.
-  **EVM Quick Start Guide**: Provides information on hardware setup and
   running the demonstration application that is loaded on flash. This
   document is provided as part of the EVM kit.

Release 06.01.00
==================

Released October 2019

.. rubric:: What's New
   :name: whats-new

- Analytics: 
    - Add support for TFLite. For more details, see `here <Foundational_Components/Machine_Learning/tflite.html>`__ 
    - Upgraded ARMNN to 2019.08
    - TensorFlow Lite parser support in ARMNN
- Added avahi-daemon and avahi-tools towards enabling mDNS support on TI platforms
- AM57x: Feature parity in Dual EMAC firmware compared to PRP EMAC mode, for Single Attached Nodes (SAN)
- AM65x: 
    - Support Jailhouse Hypervisor
    - Uboot support to load non-lockstep MCU R5F Firmware.
    - Support AVS Class 0
    - Ethernet throughput enhancements
- BeagleboneBlack: Increase number of UART ports via Soft UART with PRU

.. rubric:: SDK Components & Versions
   :name: sdk-components-versions

+--------------------------+----------------------------+
| Component                | Version                    |
+==========================+============================+
| Linux Kernel             | 4.19.59+ (2019 LTS)        |
+--------------------------+----------------------------+
| U-Boot                   | 2019.01                    |
+--------------------------+----------------------------+
| Yocto Project            | 2.6 (thud)                 |
+--------------------------+----------------------------+
| ARM Toolchain (gcc)      | 8.3 2019.03 hard-float     |
+--------------------------+----------------------------+
| Qt                       | 5.11.3                     |
+--------------------------+----------------------------+
| OpenCL                   | 1.1.19                     |
+--------------------------+----------------------------+
| OpenCV                   | 3.1                        |
+--------------------------+----------------------------+
| Wayland                  | 1.16                       |
+--------------------------+----------------------------+
| GStreamer                | 1.14.4                     |
+--------------------------+----------------------------+
| TI PRU Compiler          | 2.2.1                      |
+--------------------------+----------------------------+
| TI C66x CGT Compiler     | 8.3.2                      |
+--------------------------+----------------------------+

|

Supported Platforms
=====================================
See `here <Release_Specific_Supported_Platforms_and_Versions.html>`__ for a list of supported platforms and links to more information.

|


Build Information
=====================================

U-Boot
-------------------------

| The U-Boot git repository, branch and commit id can be found below:
| Based on verson: 2019.01
| URL: git.ti.com/processor-sdk/processor-sdk-u-boot.git
| Branch: processor-sdk-u-boot-2019.01
| Commit ID: 029e4c009aaeaee2d06aa8271dbd3a9e73a28aa7

|

Kernel
-------------------------

.. rubric:: Linux Kernel
   :name: linux-kernel

| The kernel git repository, branch and commit id can be found below:
| Based on Version: 4.19.59
| URL: git://git.ti.com/processor-sdk/processor-sdk-linux.git
| Branch: processor-sdk-linux-4.19.y
| Commit ID: 5f8c1c6121da785bbe7ecc5896877a2537b5d6eb 

|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| The RT kernel git repository, branch and commit id can be found below:
| Based on:
| Kernel Version: 4.19.59
| RT Kernel Version: 4.19.59-rt21

| URL: git://git.ti.com/processor-sdk/processor-sdk-linux.git
| Branch: processor-sdk-linux-rt-4.19.y
| Commit ID: 4203cb8c96070a94158d7b2b8e77edf1709ef3f7 

|

.. rubric:: Generic Kernel Release Notes
   :name: generic-kernel-release-notes

| Generic kernel release notes from kernelnewbies.org can be found at:
  http://kernelnewbies.org/Linux_4.19
| Archived versions can be found at:
  http://kernelnewbies.org/LinuxVersions

|

Issues Tracker
=====================================

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 100

    LCPD-14188,am654x-evm,ICSSG PRUEth Extremely Slow when board to board tests are run
    LCPD-15792,"am654x-evm, am654x-idk",am65xx: icssg: tx_teardown_timeout at prueth interface down
    LCPD-10233,"am335x-evm, am335x-ice, am335x-sk, am43xx-gpevm, am437x-idk, am437x-sk, am571x-idk, am572x-idk, am57xx-evm, beaglebone, beaglebone-black, dra71x-evm, dra72x-evm, dra7xx-evm",U-boot: Using DM_I2C in SPL is broken
    LCPD-16194, "am654x-evm, am654x-idk, am654x-hsevm", AM65x PG1.0: certain USB hubs are failed in enumeration
    LCPD-16195,"am654x-evm, am654x-idk, am654x-hsevm",U-Boot: AM65x PG1.0: USB D+ is pulled high without VBUS presence
    LCPD-16096,"am57xx-evm, dra7xx-evm", Instability observed while trying to capture video with USB camera via Gstreamer
    LCPD-16100,"k2e-evm, k2e-hsevm, k2l-evm, k2l-hsevm",NAND failures on K2 evms
    LCPD-16132,am654x-evm, kernel dumps due to Bad of_node_put() when open/close mcu uart multiple times
    LCPD-15537,omapl138-lcdk,remoteproc/davinci: Fix IPC with upstream 5.1 kernel
    LCPD-15479,"am57xx-evm, dra71x-evm, dra7xx-evm",DSS-WB Inconsistent behavior observed when converting to NM12 format
    LCPD-13940,am654x-evm, mkfs.ext2 hangs when trying to format PCIe NVMe SSD device (Samsung PM961)
    LCPD-16176,"am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm, dra76x-evm, dra76x-hsevm, dra7xx-evm, dra7xx-hsevm","MMC3 does not have correct IODELAY values for DS, HS, SDR12, SDR25"
    LCPD-16181,"am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm, dra76x-evm, dra76x-hsevm, dra7xx-evm, dra7xx-hsevm","U-boot: MMC3 does not have correct IODELAY values for DS, HS, SDR12, SDR25"
    LCPD-16163,"am654x-evm, am654x-idk",IRQ not populated error message during boot
    PLSDK-2986,am574x-idk,"TIDL: Update mobilenetV1, inceptionNetV1, squeezeNetV1, models (.bin files) in target filesystem using more optimal import configuration"
    PLSDK-2909,"am57xx-evm,am574x-idk,dra7xx-evm",Upgrade TIDL-API converted models to the new file format
    PLSDK-2699,am574x-idk,TIDL: Accuracy problem using UNET3 topology with 160x120x1 input
    LCPD-14816,am654x-idk,iperf UDP tests shows packet loss as low as 20 Mbps tput


|


Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 20, 70

   LCPD-16607,"am654x-evm, am654x-idk, am654x-hsevm","KS3 CPSW2G - kernel crashes during netif down"
   LCPD-16608,"am654x-evm, am654x-idk, am654x-hsevm","K3 CPSW2G - hw stuck on netif down under high ingress traffic pressure"
   LCPD-16697,am654x-evm,AM65X RM config The R5F core 1 interrupt resource host type need correction
   LCPD-16593,"am571x-idk, am574x-idk, am57xx-evm, dra71x-evm, dra7xx-evm",Errors observed for IOCTLs with DMABuf import-export capture operation
   LCPD-16626,am57xx-evm,USB gadget Removing g_multi makes DUT hang
   LCPD-16550,am654x-hsevm,AM6 DT overlays not applied in u-boot when using FIT image
   PLSDK-3077,"am335x-evm,am437x-gpevm,am57xx-evm,am654x-evm","IVI-Shell Documentation  fix typo at the Weston core section"
   PLSDK-3073,k2e-evm,K2E: mpm tests failing due to missing executables
   PLSDK-3092,k2g-ice,icss_emacMainTest_k2g.out not included in FS

|

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
   :header: "Record ID",  "Title"
   :widths: 15, 80

   LCPD-9084,i887: Software workaround to limit mmc3 speed to 64MHz
   LCPD-7642,MMC/SD: i832: return DLL to default reset state with CLK gated if not in SDR104/HS200 mode.
   LCPD-1022,J6: Errata: i694: System I2C hang due to miss of Bus Clear support @ OMAP level
   LCPD-976,J6/J6eco: 32clk is psuedo (erratum i856) - clock source
   LCPD-975,J6/J6eco: 32clk is psuedo (erratum i856) - realtime counter
   LCPD-1188,J6: Baseport: Errata i877: RGMII clocks must be enabled to avoid IO timing degradation due to Assymetric Aging
   LCPD-5311,i893: DCAN ram init issues in HW AUTO and when traffic hitting CAN bus (open investigation)
   LCPD-5310,"i900: CTRL_CORE_MMR_LOCK_5 region after locking results in ctrl module inaccessible, recoverable only post a reset"
   LCPD-5309,LCPD: i896: USB Port disable doesnt work
   LCPD-4225,J6: Errata: i834: Investigate possibility of software workaround
   LCPD-4195,J6: SATA: Investigate applicability of i807
   LCPD-14580,DSS : DSS Does Not Support YUV Pixel Data Formats
   LCPD-14577,CPSW does not support CPPI receive checksum (Host to Ethernet) offload feature
   LCPD-14579,DSS : DSS Does Not Support YUV Pixel Data Formats
   LCPD-14578,DSS : DSS DPI Interface does not support BT.656 and BT.1120 output modes
   LCPD-9173,i897: USB Stop Endpoint doesnt work in certain circumstances
   LCPD-8294,37 pins + VOUT pins need slow slew enabled for timing and reliability respectively
   LCPD-13887,DDR Controller ECC Scrubbing feature can cause DRAM data corruption
   LCPD-13884,CPTracer Bus Probes MAIN_CAL0_0 and MCU_SRAM_SLV_1 are not able to distinguish between secure and non-secure transactions
   LCPD-14185,MSMC: Non-coherent memory access to coherent memory can cause invalidation of snoop filter
   LCPD-14187,UDMA-P Real-time Remote Peer Registers not Functional Across UDMA-P Domains
   LCPD-14159,The assertion of warm reset coinciding with a debug configuration access targeting the STM Subsystem may result in a hang of said debug configuration access
   LCPD-14941,RINGACC and UDMA ring state interoperability issue after channel teardown
   LCPD-8277,u-boot: j6: SATA is not shutdown correctly as per errata i818
   LCPD-5924,ALL: CONNECTIVITY: CPSW: errata i877 workarround for cpsw
   LCPD-5931,DRA7xx: AM57xx: mmc: upstream errata workaround for i834
   LCPD-6907,Workaround errata i880 for RGMII2 is missing
   LCPD-5836,CAL: Errata: i913: CSI2 LDO needs to be disabled when module is powered on
   LCPD-5052,Upstream: Post the dmtimer errata fix for i874
   LCPD-4975,DSS AM5/DRA7: implement WA for errata i886
   LCPD-4912,DRA7: USB: Implement ErrataID_i896_PED_issue
   LCPD-4910,J6/OMAP5: errata i810 implementation
   LCPD-4911,DRA7: USB: Investigate applicability of Errata i897: StopEndpoint_issue
   LCPD-876,OMAP5: Errata i810: DPLL Controller Sticks when left clock requests are removed
   LCPD-1146,DMM hang: Errata VAYU-BUG02976 (i878) (register part)
   LCPD-1108,J6: Wrong Access In 1D Burst For YUV4:2:0-NV12 Format (Errata i631)
   LCPD-1087,J6: MMC: Errata: i802: OMAP5430 MMCHS: DCRC errors during tuning procedure
   LCPD-5460,Implement WA for Vayu errata i829 (Reusing Pipe Connected To Writeback Pipeline On The Fly To An Active Panel)
   LCPD-5308,i897: USB Stop Endpoint doesnt work in certain circumstances
   LCPD-4218,Implement Workaround for Errata i813 - Spurious Thermal Alert Generation When Temperature Remains in Expected Range
   LCPD-4217,Implement Workaround for Errata i814 - Bandgap Temperature read Dtemp can be corrupted
   LCPD-4184,Implement workaround for errata i814 - Bandgap Temperature read Dtemp can be corrupted
   LCPD-4647,[rpmsg 2015 LTS] Implement errata i879 - DSP MStandby requires CD_EMU in SW_WKUP
   LCPD-4648,[rpmsg 2014 LTS] Implement errata i879 - DSP MStandby requires CD_EMU in SW_WKUP
   LCPD-14186,UDMA-P Host Packet Descriptors 0x3FFFFF Packet Length Mode not Functional
   LCPD-941,OMAP4 and OMAP5: DSS: implement workaround for errata i740
   LCPD-1776,"[J6 SATA Adaptation] J6 - Errata i783, SATA Lockup After SATA DPLL Unlock/Relock"


|

SDK Known Issues
-----------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 25, 30, 50, 600

   LCPD-15810,"am335x-evm, am43xx-gpevm, k2g-evm",Illegal instruction reported when trying to decode h264 stream with gstreamer,None
   LCPD-15587,"am335x-evm, am43xx-gpevm, am57xx-evm",QtWebengine-based browser does not work,Use QTWebkit-based browser instead.
   PLSDK-3039,"am571x-idk, am572x-idk, am574x-idk",OC PPS on GMAC port does not follow PTP sync in BC test,"Re-enable PPS with echo 0 > /sys/class/ptp/ptp0/pps_enable echo 1 > /sys/class/ptp/ptp0/pps_enable"
   PLSDK-2662,"am335x-ice, am437x-idk, am571x-idk, am572x-idk, am574x-idk, k2g-ice",HSR/PRP: Bringing down one slave port stops HSR/PRP interface,None
   PLSDK-2642,am654x-idk,PRU Ethernet links on IDK Application board are unstable,IDK Limitation and requires re-work
   LCPD-14450,"am654x-evm, am654x-idk",CPSW speed change with ethtool - delay when setting to 100Mbps,
   PLSDK-2900,"am335x-evm, am437x-evm, k2e-evm, k2g-evm, k2hk-evm, k2l-evm","crypto examples are skipped from toplevel SDK Makefile, due to OpenSSL dependency",No workaround
   PLSDK-2730,"am335x-evm, am335x-ice, am437x-evm, am572x-evm, am654x-evm",Chromium-Wayland browser doesn't work,Use qtWebkit browser
   PLSDK-1398,"k2e-evm, k2e-hsevm, k2g-hsevm, k2hk-hsevm",IPC demo hangs if run after OpenCL demos,Run IPC demo w/o running OpenCL first
   PLSDK-2913,am572x-idk,NetJury Test Failure: TC_PRP_4_3_4_____Reception_of_a_PRP_Supervision_frame_and_Nodes_Table - test_VLAN,No workaround
   PLSDK-3031,"am571x-idk, am572x-idk, am574x-idk",HSR: erroneous A-B forwarding of frames,
   PLSDK-3074,am572x-idk,NetJury Test Failure: TC_PRP_4_2_4_____IP_addresses,None
   PLSDK-2895,am571x-idk,AM571x-IDK: Icss Emac: TTS Port 1: Packet cyclic timestamp error.,None
   PLSDK-2178,"am335x-ice, am437x-idk, am574x-idk",ICSS EMAC intermittent error in received acyclic packet content,None
   LCPD-16525,"am654x-evm, am654x-idk, am654x-hsevm",Need to configure ACIOCR3 during DDR configuration,
   PLSDK-2530,"am335x-ice, am437x-idk",AM3/4 PTP PPS fails intermittently,No complete workaround. Restarting the ethernet interface should reset PPS and likely resolve the issue temporarily
   PLSDK-2896,"k2e-evm, k2e-hsevm, k2hk-evm",mpm_transport_hyperlink_loopback: transport arm-loopback-hyplnk-0 failed (error: -114) retval -1001,No workaround
   PLSDK-2861,"k2e-evm, k2g-evm, k2hk-evm, k2l-evm",Crypto is not functional on 2019 LTS,None
   LCPD-15874,am574x-idk,QSPI boot does not work on am574x-idk, Bring in modules used in Power Management  xdc.loadPackage('ti.pm') ; var Power = xdc.useModule('ti.sysbios.family.arm.ducati.smp.Power'
   LCPD-11846,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm",libdce2 omapdrm API call with bus-version style,
   PLSDK-2466,"am335x-ice, am437x-idk, am571x-idk, am572x-idk, k2g-ice",Fix Race condition in updating NSP credit value,None
   PLSDK-3095,"am571x-idk, am572x-idk","If nsp_credit is set to 0, storm prevention should be disabled",
   PLSDK-2936,am572x-evm,jailhouse: failed in destroy cell,None
   PLSDK-2937,am572x-evm,jailhouse: ti-app demo doesn't start,None
   PLSDK-2942,"am335x-evm, am572x-evm",ARMNNexample: Performance on AM335x (2.5x variation) and AM57 (1.5x variation) is not stable,None
   PLSDK-3094,k2hk-evm,"K2H booting kernel from NAND doesn't complete using Arago-base-tisdk-image.ubi from     PLSDK 6.0, but works with ubi file from     PLSDK 5.2",None
   LCPD-16641,"am654x-evm, am654x-idk, am654x-hsevm, , -ivi",tidss: need to ensure the output width is divisible by 2,
   PLSDK-2960,am571x-idk,HSR/PRP: Noticed 1 packet loss seen with UDP tests over 60 minute test,None
   LCPD-17118,"am57xx-evm, dra7xx-evm",Kernel MMC/SD user's guide incorrectly refers to OMAP-HSMMC,None
   PLSDK-3057,"am335x-evm, am437x-evm, am572x-evm, am654x-evm, am654x-idk",ARMNN with TFLite parser: performance/accuracy issue with quantized mobilenet models,Patch from arm compute library https://review.mlplatform.org/c/ml/ComputeLibrary/+/1620/.
   PLSDK-3065,"am335x-evm, am437x-evm, am572x-evm, am654x-evm, am654x-idk",Running "ArmnnExamples --help" returns error,None
   LCPD-14843,"am654x-evm, am654x-idk",U-boot should support default settings for netboot,"The net boot plus NFS do work with the following settings as example: setenv get_fdt_net 'tftp ${fdtaddr} ${bootdir}/${name_fdt}'... "
   LCPD-16534,"am654x-evm, am654x-idk",remoteproc/k3-r5f: PDK IPC echo_test image fails to do IPC in remoteproc mode on second run,None
   LCPD-16573,"am654x-evm, ",SA2UL not handling partial update tests,None
   PLSDK-3063,"am571x-idk, am572x-evm, am574x-idk",Switching over MCs with 2 BC in between intermittently causing phc2sys inactive for a long duration,None
   PLSDK-3086,"am571x-idk, am572x-idk",Unable to handle kernel NULL pointer dereference when disabling HSR,None
   PLSDK-3032,"am571x-idk, am572x-idk, am574x-idk","HSR: forwarding of untagged frames in default mode H not according to IEC 62439-3:2016, “5.3.3 DANH receiving from an HSR port”.",None
   PLSDK-3033,"am571x-idk, am572x-idk, am574x-idk","HSR mode, PRP frames not forwarded",None
   LCPD-16103,am654x-evm,AM6: MMC: Probe fail warning in bootloader,
   LCPD-16187,"am654x-evm, am654x-idk, am654x-hsevm",Linux warns that CPUs are started in inconsistent modes,
   LCPD-13429,,Init/exit sequence in GBM leads to error,None
   LCPD-16707,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm, dra71x-evm, dra71x-hsevm, dra72x-evm, dra72x-hsevm, dra76x-evm, dra76x-hsevm, dra7xx-evm, dra7xx-hsevm",DRA7x: Off-by-one error while selecting OTV in tuning algorithm,
   LCPD-16207,am574x-hsidk,Board does not boot sometimes due to crypto crash,None
   LCPD-1106,"am57xx-evm, dra71x-evm, dra71x-hsevm, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm",Connectivity:PCIe-SATA ext2 1G write performance is poor due to ata failed command,None
   LCPD-17005,"k2e-evm, k2g-evm, k2hk-evm, k2l-evm",Keysotne-2 PCIe memory space is set up incorrectly using OB_WIN_SIZE,Suggested change will be integrated into next release. diff --git a/drivers/pci/dwc/pci-keystone.c b/drivers/pci/dwc/pci-keystone.c. In static void ks_pcie_setup_mem_space(struct keystone_pcie *ks_pcie)  - start += OB_WIN_SIZE;  + start += (OB_WIN_SIZE << 20); 
   LCPD-15648,am335x-evm,Uboot mmc performance decreased,
   PLSDK-2873,k2g-ice,K2G-ICE kernel warnings when removing PRUETH module,None

|

U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   LCPD-17185,am57xx-evm,U-Boot does not have Extended Mode Register support for the TI DP83867 PHY driver,None
   LCPD-16937,"am43xx-epos, am43xx-gpevm, am43xx-hsevm, am437x-idk, am437x-sk",U-Boot: usbhost boot failed on AM437x,None
   LCPD-16592,"am654x-evm, am654x-idk",Unable to access MMC1 (SD Card) after UART-Based Boot,None
   LCPD-16524,"am654x-evm, am654x-idk, am654x-hsevm",Need to adjust RMW bit when using enabling ECC,None
   LCPD-16103,am654x-evm,AM6: MMC: Probe fail warning in bootloader,None
   LCPD-15889,"am654x-evm, am654x-idk",U-boot: MMC instances need to probe independently,None
   LCPD-15873,am654x-evm,There is no dtbo in u-boot for PCIe x1 + usb3 daughter card,None
   LCPD-15127,am654x-evm,u-boot: net: Stop called even without start leading to crash,None
   LCPD-15054,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm",[u-boot] AM57xx phy_ctrl structures must be board-specific,None
   LCPD-14843,"am654x-evm, am654x-idk",U-boot should support default settings for netboot,None
   LCPD-14638,"k2g-evm, k2g-ice",Invalid DDR_PHY_MR2 setting in K2G board library,None
   LCPD-12179,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm, dra71x-evm, dra71x-hsevm, dra72x-evm, dra72x-hsevm, dra76x-evm, dra76x-hsevm, dra7xx-evm, dra7xx-hsevm",U-boot: Fix IOdelay error path issue,None
   LCPD-11586,k2g-ice,dhcp failed to get IP address after reboot for K2G-ICE non-RT linux,None
   LCPD-10726,"am572x-idk, am57xx-evm",Update DDR3 emif regs structure for EMIF2 for the beagle_x15 board in U-Boot board file,None
   LCPD-10668,k2g-evm,Ethernet boot: Sometimes the board could not boot uboot from Ethernet on k2g-evm,None
   LCPD-9539,k2g-evm,dhcp does not work after soft reboot,None
   LCPD-7366,am335x-evm,uboot McSPI driver drives multiple chip selects simultaneously,None
   LCPD-5517,AM572x,Board fails to load bootloader sometimes when eSATA is connected,None
   LCPD-5416,K2G,"U-BOOT: K2G: ""reset"" fails for certain SD cards",None
   LCPD-5116,AM335x,BBB: U-Boot: Board fails to acquire dhcp address sometimes,None
   LCPD-4817,AM572x,am57xx-evm/dra7xx-evm: uboot: usb failed to detect Kingston DataTraveler usb msc device,None
|


Linux Kernel Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Priority", "Title", "Component", "Subcomponent", "Platform", "Workaround", "Impact"
   :widths: 5, 10, 70, 10, 5, 20, 35, 20

   LCPD-9972,P2-High,Soft reboot failed on k2g-evm with class 10 SD cards,Connectivity,,k2g-evm,Do not use soft reboot, Only hard reboot works
   LCPD-13653,P2-High,am65x-evm could not boot from MMC/SD when MMC/SD is backup boot mode,Baseport,,"am654x-evm, am654x-idk",No workaround, If UART boot times out mmc backup mode cannot work
   LCPD-13412,P2-High,VIP camera sensor (mt9t11) is not initialized properly,Audio & Display,,am57xx-evm, Hardware issue with sensor, capture does not work with this sensor
   LCPD-15894,P3-Medium,Standby hangs sometimes after many standby/resume transitions,Power & Thermal,,am335x-evm,,
   LCPD-15422,P3-Medium,cpuhotplug03 test failed (tasks get scheduled to a newly on-lined CPU?),Power & Thermal,,"am57xx-evm, am654x-evm, dra7xx-evm",,
   LCPD-12784,P3-Medium,Board can't resume from suspend state sometimes,Power & Thermal,,omapl138-lcdk,,
   LCPD-12273,P3-Medium,i2c controller timed out during DVFS,Power & Thermal,,dra7xx-evm,,
   LCPD-10997,P3-Medium,ABB voltage did not increase for 1800 MHz,"Power & Thermal, System Test",,dra76x-evm,,
   LCPD-9527,P3-Medium,Potential deadlock reported by pm_suspend on am335x,Power & Thermal,,"am335x-evm, am335x-sk, beaglebone, beaglebone-black",,
   LCPD-7256,P3-Medium,Board sometimes hangs after suspend/resume cycle,Power & Thermal,,"am335x-evm, am335x-hsevm, am57xx-evm, dra72x-evm, dra7xx-evm",,
   LCPD-6427,P3-Medium,vpe fails to suspend sometimes,Power & Thermal,,"am571x-idk, am572x-idk, am57xx-evm, dra72x-evm, dra7xx-evm",,
   LCPD-4870,P3-Medium,"DRA74x EVM: suspend causes ""suspicious RCU usage""",Power & Thermal,,DRA74x,,
   LCPD-1245,P3-Medium,AM335x: Power: Reverse current leakage on poweroff,Power & Thermal,,am335x-evm,,
   LCPD-1204,P3-Medium,AM335x - Some voltage rails remain active during poweroff,Power & Thermal,,,,
   LCPD-965,P3-Medium,AM335x: Power: Poweroff is not shutting down voltage domains,Power & Thermal,,,,
   LCPD-16125,P3-Medium,PRU RemoteProc INTC Initialization Wrong,IPC,PRUSS_remoteproc,"am335x-evm, am335x-ice, am335x-sk, am43xx-epos, am43xx-gpevm, am437x-idk, am437x-sk, am571x-idk, am572x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15, am654x-evm, am654x-idk, beaglebone, beaglebone-black, k2g-evm, k2g-ice",,
   LCPD-16100,P3-Medium,NAND failures on K2 evms,Connectivity,,"k2e-evm, k2e-hsevm, k2l-evm, k2l-hsevm",,
   LCPD-16096,P3-Medium,Instability observed while trying to capture video with USB camera via Gstreamer,"Audio & Display, Connectivity, Multimedia",,"am574x-idk, am57xx-evm, dra7xx-evm",,
   LCPD-16029,P3-Medium,AM65: icssg: PRU ethernet links might be unstable with new PHY package,Connectivity,PRUSS-Ethernet,"am654x-evm, am654x-idk, am654x-hsevm",,
   LCPD-15955,P3-Medium,QSPI boot does not work on am437x-sk,Connectivity,,"am437x-idk, am437x-sk",,
   LCPD-15952,P3-Medium,DCAN Documentation incorrect,Connectivity,,,,
   LCPD-15900,P3-Medium,Uboot eMMC mode is not at expected mode,Connectivity,,am574x-idk,,
   LCPD-15888,P3-Medium,Uboot mmc fatwrite sometimes hanging,Connectivity,,omapl138-lcdk,,
   LCPD-15887,P3-Medium,The boot time increase ~30s on omapl138-lcdk,Connectivity,,omapl138-lcdk,,
   LCPD-15885,P3-Medium,Uboot usb start trigger the board resetting with one usb stick,Connectivity,,k2hk-evm,,
   LCPD-15874,P3-Medium,QSPI boot does not work on am574x-idk,Connectivity,,,,
   LCPD-15855,P3-Medium,Kernel Oops seen with debug options enabled,Connectivity,,am654x-evm,,
   LCPD-15787,P3-Medium,Power suspend fails due to USB (scsi_bus_suspend) failure when HDD is in use,Connectivity,,am335x-evm,,
   LCPD-15768,P3-Medium,RNDIS performance dropped in 2019 LTS,Connectivity,,,,
   LCPD-15737,P3-Medium,AM65x: MMC OTAPDLY values must match values in the Data Manual,Connectivity,MMCSD,"am654x-evm, am654x-idk",,
   LCPD-15672,P3-Medium,eMMC boot failed on BBB,Connectivity,,beaglebone-black,,
   LCPD-15649,P3-Medium,Uboot: sata could not be detected,Connectivity,,am57xx-evm,,
   LCPD-15633,P3-Medium,Uboot: Could not write to USB msc device,Connectivity,,"am335x-evm, am43xx-gpevm",,
   LCPD-15540,P3-Medium,uvc-gadget results in segmentation fault,Connectivity,,"am57xx-evm, am654x-evm, dra71x-evm, dra7xx-evm",,
   LCPD-15538,P3-Medium,Nand cpuload 100% and it seems like not using DMA,Connectivity,,am335x-evm,,
   LCPD-15515,P3-Medium,PCI: Endpoint: MSIX interrupts do not work on AM654,Connectivity,PCIe,am654x-evm,,
   LCPD-15405,P3-Medium,DFU: could not update eMMC bootloaders when using dfu_alt_info_emmc set in uboot env,Connectivity,,"am57xx-evm, dra71x-evm, dra7xx-evm",,
   LCPD-15365,P3-Medium,warning dump in fs/nfs/inode.c seen sometimes,Connectivity,CPSW,am654x-evm,,
   LCPD-15244,P3-Medium,"When 'allmulti' and 'promisc' are disabled, PRUeth should not receive multicast packets",Connectivity,,,,
   LCPD-15241,P3-Medium,am437x-sk failed boot to uboot prompt from QSPI,Connectivity,,am437x-sk,,
   LCPD-14933,P3-Medium,10Mbps not working working with RGMII PHYs,Connectivity,,am335x-hsevm,,
   LCPD-14855,P3-Medium,omap_i2c_prepare_recovery() function can Lock System,Connectivity,I2C,"am335x-evm, am335x-ice, am335x-sk",,
   LCPD-14842,P3-Medium,musb: unplug usb-serial device cause console lockup,Connectivity,USB,"am335x-evm, am335x-sk, beaglebone-black",,
   LCPD-14511,P3-Medium,AM65x: Soft reset fails when booting from eMMC,Connectivity,MMCSD,"am654x-evm, am654x-idk",,
   LCPD-14497,P3-Medium,PCIe Gen3 problems on AM654x,Connectivity,,"am654x-evm, am654x-idk",,
   LCPD-14460,P3-Medium,am654x-idk failed to boot to kernel prompt occasionally,Connectivity,,am654x-idk,,
   LCPD-14450,P3-Medium,CPSW speed change with ethtool - delay when setting to 100Mbps,Connectivity,,"am654x-evm, am654x-idk",,
   LCPD-14184,P3-Medium,USB: SuperSpeed USB Non-Functional,Connectivity,,am654x-evm,,
   LCPD-14183,P3-Medium,am654x-idk failed to login to kernel a few times (7/1000),"Connectivity, IPC",,am654x-idk,,
   LCPD-14171,P3-Medium,Failed to read uboot from SD card 1/1000 times,Connectivity,,"am57xx-evm, dra7xx-evm",,
   LCPD-13940,P3-Medium,mkfs.ext2 hangs when trying to format PCIe NVMe SSD device (Samsung PM961),Connectivity,,am654x-evm,,
   LCPD-13938,P3-Medium,PCIe EP read/write/copy test failed with larger sizes,Connectivity,,"am654x-evm, dra71x-evm, dra7xx-evm, k2g-evm",,
   LCPD-13936,P3-Medium,Uboot dhcp timeout 1 of 100 times,Connectivity,,am654x-evm,,
   LCPD-13720,P3-Medium,SPI DMA TX Mode Halts During Continuous 16/32/64 bit Transfers,Connectivity,,beaglebone-black,,
   LCPD-13603,P3-Medium,One board could not boot rootfs from more than one SDHC card,Connectivity,,am654x-evm,,
   LCPD-13587,P3-Medium,dwc3: g_audio can only record once,Connectivity,USB,am57xx-evm,,
   LCPD-13452,P3-Medium,USB Gadget Camera Capture - guvcview causes kernel oops,Connectivity,,k2g-evm,,
   LCPD-13445,P3-Medium,Seldom kernel oops triggered by prueth_netdev_init,Connectivity,,am654x-evm,,
   LCPD-13330,P3-Medium,Uboot: usb storage device could not be found at second usb reset,Connectivity,,k2g-evm,,
   LCPD-12673,P3-Medium,Board refuses to suspend on setup with SATA device,Connectivity,,omapl138-lcdk,,
   LCPD-12226,P3-Medium,mmcsd first write perf decreased on some platforms,Connectivity,,"am43xx-gpevm, am574x-idk, am57xx-evm, omapl138-lcdk",,
   LCPD-11952,P3-Medium,AM57x: disabling USB super-speed phy in DT causes kernel crash,Connectivity,USB,"am571x-idk, dra72x-evm",,
   LCPD-11564,P3-Medium,AM57xx-evm: eth1 1G connection failure to netgear switch,Connectivity,"CPSW, ETHERNET, PHYIF",am57xx-evm,,
   LCPD-10974,P3-Medium,am43xx-gpevm - usb camera gadget shows halting frames,Connectivity,USB,,,
   LCPD-10781,P3-Medium,NetCP module removal results in backtrace and kernel panic,Connectivity,NETCP,k2g-evm,,
   LCPD-10777,P3-Medium,mtd_stresstest failed on omapl138,Connectivity,NAND,omapl138-lcdk,,
   LCPD-10551,P3-Medium,"K2E eth0 does down when running udp traffic, eth1 stops working",Connectivity,NETCP,k2e-evm,,
   LCPD-10221,P3-Medium,Longer resume times observed on setup with usb device cable,Connectivity,USB,am335x-evm,,
   LCPD-9974,P3-Medium,PCIe x2 width is not at expected width on am571x-idk,Connectivity,PCIe,am571x-idk,,
   LCPD-9905,P3-Medium,AM437x: UART: Implement workaround for Advisory 27 ? Spurious UART interrupts when using EDMA,Connectivity,UART,am43xx-gpevm,,
   LCPD-9816,P3-Medium,USBdevice omapl138 - Flood ping from server to dut usbdevice at 65500 bytes has packet loss,Connectivity,USB,omapl138-lcdk,,
   LCPD-9815,P3-Medium,Failed to start Login Service when using debug systest build on omapl138,Connectivity,,omapl138-lcdk,,
   LCPD-9804,P3-Medium,SATA performance decreased by ~34% for read and ~54% for write compared to v2.6.33 kernel,Connectivity,SATA,omapl138-lcdk,,
   LCPD-9658,P3-Medium,OMAP-L138 LCDK: MUSB does not enumerate mouse connected to Keyboard hub,Connectivity,USB,omapl138-lcdk,,
   LCPD-9591,P3-Medium,CONNECTIVITY: USB NCM gadget ping with packet sizes > 10000 fails,Connectivity,,,,
   LCPD-9466,P3-Medium,SATA PMP causes suspend failures,Connectivity,SATA,"am57xx-evm, dra7xx-evm",,
   LCPD-9455,P3-Medium,Kernel Warning reported for a USB audio device when listing with pulseaudio,Connectivity,USB,am335x-evm,,
   LCPD-9428,P3-Medium,Ethernet performace UDP: iperf command fails with two threads for lower buffer length,Connectivity,NETCP,"k2e-evm, k2hk-evm, k2l-evm",,
   LCPD-9372,P3-Medium,Nand stress tests failed on a particular am335x-evm board,Connectivity,NAND,am335x-evm,,
   LCPD-9366,P3-Medium,PCIe USB drive sometimes could not be enumerated,Connectivity,PCIe,k2g-evm,,
   LCPD-9011,P3-Medium,K2G-evm: usb devices do not enumerate behind a TUSB8041 usb3.0 hub,Connectivity,USB,,,
   LCPD-8984,P3-Medium,Kernel boot to initramfs with PA enabled results in no DHCP IP address assigned to network interfaces,Connectivity,NETCP,"k2e-evm, k2l-evm",,
   LCPD-8637,P3-Medium,K2HK: Long-term ping test fails due to ethernet link going down,Connectivity,,,,
   LCPD-8133,P3-Medium,"USB: ""cannot reset"" errors observed sometimes",Connectivity,USB,am335x-evm,,
   LCPD-8100,P3-Medium,CONNECTIVITY: K2G ethernet performance numbers are low,Connectivity,NETCP,k2g-evm,,
   LCPD-8078,P3-Medium,AM3 SK: Touchscreen isn't responsive,"Audio & Display, Connectivity",,am335x-sk,,
   LCPD-8033,P3-Medium,AM3 SK: Unexpected USB2-1 Messages on UART,Connectivity,USB,,,
   LCPD-7955,P3-Medium,Uncorrectable Bitflip errors seen after switch to SystemD,Connectivity,GPMC,"am335x-evm, am43xx-gpevm, k2e-evm, k2g-evm, k2g-ice, k2hk-evm, k2hk-hsevm, k2l-evm",Workaround to erase the NAND flash completely if flashed with an incompatible flash writer. SystemD tries to mount all partitions and that is the reason this is being seen now.,
   LCPD-7829,P3-Medium,uboot: UHS card did not work on the expected speed in uboot,Connectivity,,am57xx-evm,,
   LCPD-7744,P3-Medium,UHS SDR104 card works on different speed after soft reboot,Connectivity,,am57xx-evm,,
   LCPD-7623,P3-Medium,Seeing SPI transfer failed error sometimes on k2hk when using rt kernel,Connectivity,SPI,k2hk-evm,,
   LCPD-7559,P3-Medium,K2E/K2HK does not enumerate usb3 devices through usb3.0 hub,Connectivity,USB,"k2e-evm, k2hk-evm",,
   LCPD-7265,P3-Medium,Uboot eMMC does not use HS200 on am57xx-gpevm,Connectivity,,am57xx-evm,,
   LCPD-6334,P3-Medium,k2g-evm: NAND is untestable due to data corruption issues,Connectivity,,k2g-evm,,
   LCPD-6300,P3-Medium,am57xx-evm: A few UHS cards could not be numerated in kernel and mmc as rootfs failed.,Connectivity,,am57xx-evm,,
   LCPD-5699,P3-Medium,pci: am572x-idk: pci broadcom card doesn't enumerate,Connectivity,,"AM571x, AM572x",,
   LCPD-5677,P3-Medium,K2E-evm: Marvel SATA controller could not be detected sometimes when Power On Reset is involved,Connectivity,,K2E,,
   LCPD-5522,P3-Medium,pcie-usb sometimes the usb drive/stick could not be enumerated,Connectivity,,"am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm",,
   LCPD-5362,P3-Medium,MUSB: Isoch IN only utilises 50% bandwidth,Connectivity,USB,AM335x,,
   LCPD-4849,P3-Medium,K2hk: Connectivity: UART data corruption observed sometimes in loopback mode,Connectivity,,,,
   LCPD-4503,P3-Medium,ALL: 8250 UART driver not enabeld as wake source by default,Connectivity,UART,,,
   LCPD-1239,P3-Medium, Connectivity: DUT could not resume when PCI-SATA card is in,Connectivity,PCIe,"am572x-idk, am57xx-evm, dra72x-evm, dra7xx-evm",,
   LCPD-1198,P3-Medium,"am43xx-gpevm:Connectivity: when kmemleak debug is enabled and mmc stress test is run, OOM killer is seen to kick in. Does not happen without kernel debug.",Connectivity,,,,
   LCPD-1144,P3-Medium,Logitech USB-PS/2 Optical Mouse cannot be detected every other time the system is suspended/resumed (AM335x-EVM),Connectivity,,,,
   LCPD-869,P3-Medium,AM335x: Connectivity: USB data transfer fails if board is suspended/resumed,Connectivity,,,,
   LCPD-662,P3-Medium,CONNECTIVITY: AM335X: distortion in USB audio when msc connect/disconnect happens in parallel,Connectivity,,,,
   LCPD-16132,P3-Medium,kernel dumps due to Bad of_node_put() when open/close mcu uart multiple times,Baseport,,am654x-evm,,
   LCPD-14191,P3-Medium,IPSec hardware-based throughput is 30% lower than 2018.03,Baseport,,"am335x-evm, am57xx-evm",,
   LCPD-13410,P3-Medium,Reboot command is not operational,Baseport,,"am654x-evm, am654x-idk",,
   LCPD-9981,P3-Medium,Some LTP's memory management tests fail due to low amount of free memory,Baseport,,"omapl138-lcdk",,
   LCPD-9980,P3-Medium,LTP's math tests float_exp_log and float_trigo fail due to OOM,Baseport,,omapl138-lcdk,,
   LCPD-9756,P3-Medium,"pm_runtime does not kicks in for some IPs (serial, gpio and wdt)",Baseport,,omapl138-lcdk,,
   LCPD-8550,P3-Medium,CPSW memory allocation errors seen during boot,"Audio & Display, Baseport",,am335x-sk,,
   LCPD-8406,P3-Medium,K2G: PADCONFIG_202 register cannot be re-programmed,Baseport,,"k2g-evm, k2g-ice",This has proven to be a silicon issue related to locking RSTMUX. It is currently being discussed if it will be fixed in a newer silicon revision. Currently to avoid this issue the affected pins pinmux are not changed in the kernel. This is because U-boot locks RSTMUX which causes problems if the kernel tries to change the pinmuxing for the pins.,
   LCPD-8350,P3-Medium,UART boot does not work on am57xx-evm,Baseport,,am57xx-evm,,
   LCPD-8347,P3-Medium,BUG: sleeping function called from invalid context triggered by keystone_pcie_fault,Baseport,,"k2e-evm, k2g-evm",,
   LCPD-8336,P3-Medium,Soft reboot does not work on am43xx-hsevm rev1.5b,Baseport,,am43xx-hsevm,,
   LCPD-8257,P3-Medium,Boot failed 1 of 1000 times on k2g,Baseport,,k2g-evm,,
   LCPD-7486,P3-Medium,uboot debug with ccs is failing for K2,Baseport,,k2hk-evm,,
   LCPD-6998,P3-Medium,K2G sometimes boot failed with kernel oops error,Baseport,,k2g-evm,None,
   LCPD-6663,P3-Medium,[RT] Kmemleak is buggy and boot is crashed randomly,Baseport,,,,
   LCPD-15821,P3-Medium,AM6 tidss: 1680x1050 does not work with TC358767,Audio & Display,Display,am654x-evm,,
   LCPD-15819,P3-Medium,"tidss: the driver should reject dual-display setup, as it is not supported",Audio & Display,Display,am654x-evm,,
   LCPD-15659,P3-Medium,Audio record operation sometimes fail with arecord: pcm_read:2143: read error: Input/output error,Audio & Display,Audio,am57xx-evm,,
   LCPD-15646,P3-Medium,Fifo underflow reported for 1280x720@60 mode,Audio & Display,,k2g-evm,,
   LCPD-15518,P3-Medium,omapdrm: WB M2M: Headless mode is not working,Audio & Display,Writeback,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm, dra71x-evm, dra71x-hsevm, dra72x-evm, dra72x-hsevm, dra76x-evm, dra76x-hsevm, dra7xx-evm, dra7xx-hsevm",,
   LCPD-15455,P3-Medium,FIFO underflow reported during mode setting test,Audio & Display,Display,am654x-evm,,
   LCPD-12680,P3-Medium,Seeing i2c timeout error and board failed to boot,Audio & Display,,k2g-evm,,
   LCPD-11138,P3-Medium,VIP driver multi-channel capture issue with TVP5158,Audio & Display,"Capture, VIP","am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm, dra7, dra71x-evm, dra71x-hsevm, dra72x-evm, dra72x-hsevm, dra76x-evm, dra76x-hsevm, dra7xx-evm, dra7xx-hsevm",,
   LCPD-7735,P3-Medium,Powerdomain (vpe_pwrdm) didn't enter target state 0,"Audio & Display, Power & Thermal",,"am57xx-evm, dra71x-evm, dra71x-hsevm, dra72x-evm, dra7xx-evm",,
   LCPD-7696,P3-Medium,DRA7xx: VPE: File2File checksum changes across multiple runs,Audio & Display,,"am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm, dra71x-evm, dra71x-hsevm, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm",There is no workaround for this issue yet,"No visual artifacts, but checksum on initial frame differs as couple of bytes are incorrect"
   LCPD-7693,P3-Medium,VIP: OV1063x: Video artifacts in LVDS cameras,Audio & Display,Capture,,,
   LCPD-5380,P3-Medium,omapdss error: HDMI I2C Master Error,Audio & Display,,AM572x,Occurs only with this monitor - http://www.amazon.com/gp/product/B00PFLZV2G,
   LCPD-1191,P4-Low,AM335x: Power: System resumes due to wakeup source USB1_PHY without any external trigger,Power & Thermal,,,Use GPIO interrupt instead of USB PHY for wakeup source.,
   LCPD-1013,P4-Low,AM335x: Power: Seldom short-duration power increase (~38mw) in VDDSHV4 domain,Power & Thermal,,,,
   LCPD-15991,P4-Low,remoteproc elf download crashes at memset for MSMC address 0x70020000,IPC,,am654x-evm,,
   LCPD-15918,P4-Low,ti-ipc-rtos gets stuck in xdctools,IPC,,k2l-hsevm,,
   LCPD-15402,P4-Low,rpmsg-rpc: test application does not bail out gracefully upon error recovery,IPC,"DSP_remoteproc, IPU_remoteproc","am571x-idk, am572x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15, dra71x-evm, dra72x-evm, dra76x-evm, dra7xx-evm",,
   LCPD-15400,P4-Low,remoteproc/omap: System suspend fails for IPU1 domain without any remoteprocs loaded,IPC,IPU_remoteproc,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15, dra71x-evm, dra72x-evm, dra76x-evm, dra7xx-evm",,
   LCPD-10455,P4-Low,remoteproc/keystone: Hang observed while running RPMSG_PROTO example app,IPC,DSP_remoteproc,"k2g-evm, k2g-ice, k2hk-evm, k2l-evm",,
   LCPD-9801,P4-Low,remoteproc/davinci: DSP boot is broken after a suspend/resume cycle,IPC,DSP_remoteproc,omapl138-lcdk,,
   LCPD-9481,P4-Low,Sometime the system hangs while loading the rpmsg rpc modules,IPC,RPMSG-RPC,"am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm",,
   LCPD-7495,P4-Low,Sometimes a Kernel Warning + Oops is seen when removing keystone_remoteproc module,IPC,,k2hk-evm,,
   LCPD-15660,P4-Low,pcie sata or usb drive no device node being created,Connectivity,,k2g-evm,,
   LCPD-15648,P4-Low,Uboot mmc performance decreased,Connectivity,,am335x-evm,,
   LCPD-14169,P4-Low,K2E:Observed unwanted failure messages in boot log,Connectivity,,k2e-evm,"No functionality affected except the log message. If not needed, do not connect anything to the PCIe slot.",
   LCPD-13794,P4-Low,Usb stick could not be detected in Uboot at the second time on k2g-evm,Connectivity,,k2g-evm,,
   LCPD-12392,P4-Low,USBhost video: higher resolution tests fail with some cameras,Connectivity,,am335x-evm,,
   LCPD-11570,P4-Low,Base ubi filesystem could not be mounted as ubifs on k2g-evm,Connectivity,,k2g-evm,,
   LCPD-9589,P4-Low,I2C: Sometimes i2c read write failed on farm01 and farm02,Connectivity,,am335x-evm,,
   LCPD-9222,P4-Low,PRUSS Ethernet does not work on AM572x ES1.1,Connectivity,PRUSS-Ethernet,am572x-idk,,
   LCPD-8636,P4-Low,Serial corruption being seen in kernel,Connectivity,UART,"am335x-evm, dra72x-evm, dra7xx-evm",,
   LCPD-8477,P4-Low,K2: serdes nodes doesn't have a functional clock,Connectivity,SERDES,"k2e-evm, k2e-hsevm, k2g-evm, k2g-ice, k2hk-evm, k2hk-hsevm, k2l-evm, k2l-hsevm",,
   LCPD-8270,P4-Low,K2: SerDes driver need to enable PD of the peripheral before access the SerDes h/w,Connectivity,SERDES,k2g-evm,,
   LCPD-7998,P4-Low,Realtime OSADL Test results degraded slightly for am572x-idk,Connectivity,,am572x-idk,,
   LCPD-7903,P4-Low,Uboot phy startup failed and dhcp failed occasionally on k2 board,Connectivity,,"k2g-evm, k2hk-evm",,
   LCPD-7480,P4-Low,K2L/E EVMs doesn't boot to Linux when both 1G Ethernet interfaces are connected,Connectivity,,"k2e-evm, k2l-evm",,
   LCPD-7188,P4-Low,PCIe-SATA test failed,Connectivity,,"am57xx-evm, dra72x-evm, dra7xx-evm",TI custom board would help with signal integrity issues being seen with the EVM.,
   LCPD-1207,P4-Low,AM43XX/AM57XX/DRA7: CONNECTIVITY: dwc3_omap on am43xx and xhci_plat_hcd on dra7 - removal results in segmentation fault,Connectivity,USB,,,
   LCPD-998,P4-Low,MUSB does not free urbs causing usb audio playback to fail,Connectivity,,AM335x,,
   LCPD-671,P4-Low,AM33XX: CONNECTIVITY: MUSB in PIO mode - video issues,Connectivity,,,,
   LCPD-525,P4-Low,AM438x: Connectivity: I2C operates 9% beyond desired frequency,Connectivity,,,,
   LCPD-10223,P4-Low,Keystone-2 Linking RAM region 0 size register REGION0_SIZE programming,Baseport,,k2hk-evm,,
   LCPD-6075,P4-Low,BUG: using smp_processor_id() in preemptible [00000000] code during remoteproc suspend/resume,"Baseport, IPC",,"am572x-idk, am57xx-evm, dra7xx-evm",,
   LCPD-15896,P4-Low,Suspend sometimes fails due to touch screen error (edt_ft5x06),Audio & Display,Touchscreen,dra7xx-evm,,
   LCPD-14311,P4-Low,tidss missing from libdrm's list of drm modules,Audio & Display,Display,"am654x-evm, am654x-idk",,
   LCPD-9098,P4-Low,Writeback: error prints seen when doing wb capture,Audio & Display,"Capture, Display, Writeback","am571x-idk, am572x-idk, am57xx-evm, dra71x-evm, dra71x-hsevm, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm",,
   LCPD-8884,P4-Low,VIP does not work after incorrectly configuring captured YUYV frame as NV12,Audio & Display,"Capture, VIP",,,
   LCPD-8000,P4-Low,VIP: RGB: RGB capture error due to wrong data path setting,Audio & Display,Capture,"dra7xx-evm, dra7xx-hsevm",,
   LCPD-6377,P4-Low,OMAP_BO_CACHED feature not functional,"Audio & Display, Multimedia",Display,"am43xx-gpevm, am43xx-hsevm, am437x-idk, am437x-sk, am571x-idk, am572x-idk, am57xx-evm, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm, k2g-evm",,
   LCPD-5059,P4-Low,omapdrm: moving plane from one enabled display to another causes errors,Audio & Display,Display,,,
   LCPD-1171,P4-Low,: DMM errata i878 (framebuffer part),Audio & Display,"Display, TILER","am571x-idk, am572x-idk, am57xx-evm, dra72x-evm, dra72x-evm-hsevm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm",,


|

RT Linux Kernel Known Issues
-----------------------------

.. csv-table::
   :header: "Record ID", "Priority", "Title", "Component", "Platform", "Workaround"
   :widths: 5, 10, 70, 10, 20, 15

   LCPD-6663 ,P3-Medium ,[RT] Kmemleak is buggy and boot is crashed randomly ,Baseport ,  ,
   LCPD-7623 ,P3-Medium ,Seeing SPI transfer failed error sometimes on k2hk when using rt kernel ,Connectivity ,k2hk-evm ,
   LCPD-11586 ,P3-Medium ,dhcp failed to get IP address after reboot for K2G-ICE non-RT linux ,Baseport  ,"k2g-ice ",
     
|


.. rubric:: Installation and Usage
   :name: installation-and-usage

The `Software Developer's Guide <index.html>`__ provides instructions on how to setup up your Linux development
environment, install the SDK and start your development.  It also includes User's Guides for various Example Applications and Code
Composer Studio.

| 

.. rubric:: Host Support
   :name: host-support

The Processor SDK is developed, built and verified on Ubuntu 16.04 and 18.04. Details on how to create a virtual machine to load Ubuntu
are described in `this page <How_to_Guides_Host.html#how-to-build-a-ubuntu-linux-host-under-vmware>`__.


.. note::
   Processor SDK Installer is 64-bit, and installs only on 64-bit host
   machine. Support for 32-bit host is dropped as Linaro toolchain is
   available only for 64-bit machines

| 

