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

Release 07.00.00
==================

Released June 2020

.. rubric:: What's New
   :name: whats-new

Processor SDK 7.0 Release has following new features:

- AM654x GP PG2.0 Support
- J721E-HS Support

.. rubric:: SDK Components & Versions
   :name: sdk-components-versions

+--------------------------+----------------------------+
| Component                | Version                    |
+==========================+============================+
| Linux Kernel             | 5.4.40                     |
+--------------------------+----------------------------+
| U-Boot                   | 2020.01                    |
+--------------------------+----------------------------+
| Yocto Project            | 3.1 (dunfell)              |
+--------------------------+----------------------------+
| ARM Toolchain (gcc)      | 9.2-2019.12 hard-float     |
+--------------------------+----------------------------+

|

Build Information
=====================================

U-Boot
-------------------------

| Head Commit: f9b0d030d31ab79577f1dd1e48814a8f3119c481 
| uBoot Version: 2020.01
| uBoot Description: 07.00.00.005
| Clone: ssh://git@bitbucket.itg.ti.com/lcpdpub/ti-u-boot.git
| Branch: 07.00.00.005
| uBoot Tag: 07.00.00.005
|

Kernel
-------------------------

.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 66cf445b7697a4963cfc796e06918fe5b147fe7d 
| URL: http://git.ti.com/gitweb/?p=ti-linux-kernel/ti-linux-kernel.git;a=commit;h=66cf445b7697a4963cfc796e06918fe5b147fe7d
| Kernel Version: 5.4.40
| Kernel Description: 07.00.00.005
| Repo: ssh://git@bitbucket.itg.ti.com/lcpdpub/ti-linux-kernel.git
| Branch: ti-linux-5.4.y
| Kernel Tag: 07.00.00.005
| Kernel defconfig: multi\_v7\_defconfig
| Compiler Information: arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025
| Compiler Download Location: https://developer.arm.com/open-source/gnu-toolchain/gnu-a/downloads
| Information on how to download and build the kernel can be found here:  http://processors.wiki.ti.com/index.php/Linux_Kernel_Users_Guide
|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 17e2c5c658e9bcdf7566c9e7f70b1f0a8c9f7036
| URL: http://git.ti.com/gitweb/?p=ti-linux-kernel/ti-linux-kernel.git;a=commit;h=17e2c5c658e9bcdf7566c9e7f70b1f0a8c9f7036
| RT Kernel Version: 5.4.43-rt25
| Kernel Description: 07.00.00.005-rt
| Repo: ssh://git@bitbucket.itg.ti.com/lcpdpub/ti-linux-kernel.git
| Tag: 07.00.00.005-rt
| Kernel defconfig: multi\_v7\_defconfig
| Compiler Information: arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025
| Compiler Download Location: https://developer.arm.com/open-source/gnu-toolchain/gnu-a/downloads
| Information on how to download and build the kernel can be found here: http://processors.wiki.ti.com/index.php/Linux_Kernel_Users_Guide

|

.. rubric:: Generic Kernel Release Notes
   :name: generic-kernel-release-notes

| Generic kernel release notes from kernelnewbies.org can be found at:
  http://kernelnewbies.org/Linux_5.4
| Archived versions can be found at:
  http://kernelnewbies.org/LinuxVersions

|

Yocto
-------------------------

.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: f2b2b2095f1a9d3ef705f7518d9db1e3141da2fb
| Version: dunfell-3.1
| Repo: git://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Tag: 07.00.00.005
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: 41cfd83e13955178bffae84ebbe5a915b79181fd
| Version: 2020.05
| Repo: git://arago-project.org/git/meta-arago.git
| Branch: dunfell
| Tag: 07.00.00.005
|

Prebuilt Binary Information
=====================================

http://lcpd.gt.design.ti.com/releases/07.00.00.005/

|


Detailed Release Notes Information
=====================================

- Uboot  http://ap-fpdsp-swapps.dal.design.ti.com/index.php/Uboot_release_notes_07.00.00.005
- Kernel http://ap-fpdsp-swapps.dal.design.ti.com/index.php/Linux_kernel_release_07.00.00.005
- RT-Kernel http://ap-fpdsp-swapps.dal.design.ti.com/index.php/Linux_RT_kernel_release_07.00.00.005-rt
- Yocto http://ap-fpdsp-swapps.dal.design.ti.com/index.php/Core_SDK_release_notes_07.00.00.005

|

Issues Tracker
=====================================

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 100

   LCPD-17236,am654x-evm,PDK-IPC build from sources is not creating stripped images and links
   LCPD-11846,am571x-idk,libdce2 omapdrm API call with bus-version style
   LCPD-16013,j721e-evm,modprobe pvrsrvkm causes kernel crash when no gpu DT node is present
   LCPD-16654,j721e-evm,GBenchmark is not able to run on j721e libgbm.so.2 is missing
   LCPD-14623,j721e-evm,Graphics demo - triangle fails with pvSrc invalid in PVRSRVDeviceMemCopy() error
   LCPD-16922,j721e-evm,rogue: DMA-API warning from rgx_blit_test
   LCPD-16029,am654x-evm,AM65: icssg: PRU ethernet links might be unstable with new PHY package
   LCPD-17771,j721e-idk-gw,cryptomgr_test kmemleak
   LCPD-17773,j721e-idk-gw,cryptomgr_test related DMA-API errors
   LCPD-17529,am43xx-gpevm,Could not access usbhost when booting from SD card
   LCPD-17229,j721e-evm,vxd_dec: kernel crash if rootfs has no pvdec_full_bin.fw firmware file
   LCPD-17010,j721e-evm,J7ES: USB: gadget mode breaks with PC host with USB3.0 LPM
   LCPD-17783,am654x-evm,USB: USB2PHY Charger Detect is enabled by default without VBUS presence
   LCPD-17118,am57xx-evm,Kernel MMC/SD user's guide incorrectly refers to OMAP-HSMMC
   LCPD-15551,k2e-evm,Upstream: remoteproc/keystone: DSP remoteproc driver is broken with upstream 4.19+ kernels
   LCPD-16382,dra7xx-evm,pcie usb/sata read write tests failed
   LCPD-17772,j721e-idk-gw,systemd doesn't show ansi sequences correctly

|


Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   LCPD-18672,J721e HS package is missing fit image,j721e-hsevm
   LCPD-18690,AM65x SR1.0: MMC UHS mode enabled but not functional,am654x-evm
   LCPD-18694,AM65x: cpsw2g: ale parameters init issue,"am654x-evm,am654x-hsevm"
   LCPD-18656,OSPI/SPI ubifs test failed due to cannot read 64 bytes from mtd6/mtd0,j721e-idk-gw
   LCPD-18787,SPL DFU boot test failed,j721e-idk-gw
   LCPD-18799,ipumm-fw breaks with latest tools,"am57xx-evm,dra7xx-evm"
   LCPD-18848,Fit Image is missing default config (k3-am654-base-board-sr1.dtb),am654x-hsevm
   LCPD-18887,am654x-hsevm fails to boot,am654x-hsevm
   LCPD-18641,"u-boot: says ""cannot find image node 'k3-am654-idk-sr1.dtbo'"" on AM65 SR1.0","am654x-evm,am654x-hsevm"
   LCPD-18674,sysint: k3-am654-idk-sr1.dtbo missing from rootfs,am654x-idk
   LCPD-18850,Watchdog test failed to reboot EVM,j721e-idk-gw
   LCPD-18593,CPSW2G: restore vlan cfg after ifconfig up/down,"am654x-evm,am654x-hsevm"
   LCPD-18594,CPSW2G: CPTS: sync PPS to adjusted PTP clock,"am654x-evm,am654x-hsevm"
   LCPD-18695,AM65x: cpsw2g: allmulti mode is broken,"am654x-evm,am654x-hsevm"
   LCPD-18669,SA2UL causes boot failure if built-in to kernel,am654x-evm
   LCPD-18793,pcie ep tests failed with big size with DMA mode,j721e-idk-gw
   LCPD-18660,K2H MDIO signal integrity workaround doesn't work in kernel 4.19,
   LCPD-18753,AM65x: cpsw2g: iet changes bloks rrobin cfg is <2 TX queues,"am654x-evm,am654x-hsevm"
   LCPD-18847,UDMA: atype is ignored even if it is correctly specified for non slave channels,"am654x-evm,am654x-hsevm"

|

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
   :header: "Record ID",  "Title"
   :widths: 15, 80

   LCPD-5310,"i900: CTRL_CORE_MMR_LOCK_5 region after locking results in ctrl module inaccessible, recoverable only post a reset"
   LCPD-5311,i893: DCAN ram init issues in HW AUTO and when traffic hitting CAN bus (open investigation)
   LCPD-5309,   LCPD: i896: USB Port disable doesnt work
   LCPD-7642,MMC/SD: i832: return DLL to default reset state with CLK gated if not in SDR104/HS200 mode.
   LCPD-4195,J6: SATA: Investigate applicability of i807
   LCPD-4225,J6: Errata: i834: Investigate possibility of software workaround
   LCPD-976,J6/J6eco: 32clk is psuedo (erratum i856) - clock source
   LCPD-975,J6/J6eco: 32clk is psuedo (erratum i856) - realtime counter
   LCPD-1022,J6: Errata: i694: System I2C hang due to miss of Bus Clear support @ OMAP level
   LCPD-1188,J6: Baseport: Errata i877: RGMII clocks must be enabled to avoid IO timing degradation due to Assymetric Aging
   LCPD-9084,i887: Software workaround to limit mmc3 speed to 64MHz
   LCPD-16904,PCIe: Unsupported request (UR) or Configuration Request Retry Status (CRS) in configuration completion response packets results in external abort
   LCPD-5836,CAL: Errata: i913: CSI2 LDO needs to be disabled when module is powered on
   LCPD-5460,Implement WA for Vayu errata i829 (Reusing Pipe Connected To Writeback Pipeline On The Fly To An Active Panel)
   LCPD-5052,Upstream: Post the dmtimer errata fix for i874
   LCPD-4910,J6/OMAP5: errata i810 implementation
   LCPD-4911,DRA7: USB: Investigate applicability of Errata i897: StopEndpoint_issue
   LCPD-4912,DRA7: USB: Implement ErrataID_i896_PED_issue
   LCPD-16363,"IO, MMCSD: Incorrect IO Power Supply Connectivity Prevent Dynamic Voltage Change on VDDSHV6 and VDDSHV7"
   LCPD-16364,MMCSD: Negative Current from UHS-I PHY May Create an Over-Voltage Condition on VDDS6 and VDDS7 which exposes the Device to a Significant Reliability Risk
   LCPD-16538,PCI-Express (PCIe) May Corrupt Inbound Data
   LCPD-14184,USB: SuperSpeed USB Non-Functional
   LCPD-14187,UDMA-P Real-time Remote Peer Registers not Functional Across UDMA-P Domains
   LCPD-14185,MSMC: Non-coherent memory access to coherent memory can cause invalidation of snoop filter
   LCPD-14159,The assertion of warm reset coinciding with a debug configuration access targeting the STM Subsystem may result in a hang of said debug configuration access
   LCPD-13884,CPTracer Bus Probes MAIN_CAL0_0 and MCU_SRAM_SLV_1 are not able to distinguish between secure and non-secure transactions
   LCPD-13887,DDR Controller ECC Scrubbing feature can cause DRAM data corruption
   LCPD-4647,[rpmsg 2015 LTS] Implement errata i879 - DSP MStandby requires CD_EMU in SW_WKUP
   LCPD-4648,[rpmsg 2014 LTS] Implement errata i879 - DSP MStandby requires CD_EMU in SW_WKUP
   LCPD-4975,DSS AM5/DRA7: implement WA for errata i886
   LCPD-14941,RINGACC and UDMA ring state interoperability issue after channel teardown
   LCPD-14579,DSS : DSS Does Not Support YUV Pixel Data Formats
   LCPD-14580,DSS : DSS Does Not Support YUV Pixel Data Formats
   LCPD-14578,DSS : DSS DPI Interface does not support BT.656 and BT.1120 output modes
   LCPD-14577,CPSW does not support CPPI receive checksum (Host to Ethernet) offload feature
   LCPD-8277,u-boot: j6: SATA is not shutdown correctly as per errata i818
   LCPD-8294,37 pins + VOUT pins need slow slew enabled for timing and reliability respectively
   LCPD-5308,i897: USB Stop Endpoint doesnt work in certain circumstances
   LCPD-6907,Workaround errata i880 for RGMII2 is missing
   LCPD-5931,DRA7xx: AM57xx: mmc: upstream errata workaround for i834
   LCPD-5924,ALL: CONNECTIVITY: CPSW: errata i877 workarround for cpsw
   LCPD-4218,Implement Workaround for Errata i813 - Spurious Thermal Alert Generation When Temperature Remains in Expected Range
   LCPD-4217,Implement Workaround for Errata i814 - Bandgap Temperature read Dtemp can be corrupted
   LCPD-4184,Implement workaround for errata i814 - Bandgap Temperature read Dtemp can be corrupted
   LCPD-1146,DMM hang: Errata VAYU-BUG02976 (i878) (register part)
   LCPD-1087,J6: MMC: Errata: i802: OMAP5430 MMCHS: DCRC errors during tuning procedure
   LCPD-1108,J6: Wrong Access In 1D Burst For YUV4:2:0-NV12 Format (Errata i631)
   LCPD-876,OMAP5: Errata i810: DPLL Controller Sticks when left clock requests are removed
   LCPD-16605,MMC: MMC1/2 Speed Issue
   LCPD-17220,U-Boot Hyperbus: Hyperflash reads limited to 125MHz max. frequency
   LCPD-16643,Hyperbus: Hyperflash reads limited to 125MHz max. frequency
   LCPD-16350,DSS: Frame Buffer Flip/Mirror Feature Using RGB24/BGR24 Packed Format can Result in Pixel Corruption
   LCPD-9173,i897: USB Stop Endpoint doesnt work in certain circumstances
   LCPD-17333,[CPTS] GENF (and ESTF) Reconfiguration Issue
   LCPD-14186,UDMA-P Host Packet Descriptors 0x3FFFFF Packet Length Mode not Functional
   LCPD-1776,"[J6 SATA Adaptation] J6 - Errata i783, SATA Lockup After SATA DPLL Unlock/Relock"
   LCPD-941,"OMAP4,5: DSS: implement workaround for errata i740"
   LCPD-1171,DRA7: DMM errata i878 (framebuffer part)

|

SDK Known Issues
-----------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 25, 30, 50, 600

   LCPD-14263,am43xx-epos,Hardware RNG module not getting probed in Linux for AM438x ,
   LCPD-18888,am335x-evm,Qt application fails to launch with HDMI display,
   LCPD-15029,j721e-vlab,tidec_decode app crashes the system when run several times,
   LCPD-18852,k2g-hsevm,k2g-hs secure monitor image is not up to date,
   LCPD-16454,j721e-evm,DSS underflows with 1080p/2.5k display on inmate cell,
   LCPD-17387,j721e-evm-ivi,Underflow and CRTC SYNC LOST observed while running GLMark2 (1x1080p + 1x4k),
   LCPD-18056,j721e-evm-ivi,PVR Errors observed while running deqp-gles,
   LCPD-18115,j721e-idk-gw,PVR Error observed while running glmark2,
   LCPD-17659,am437x-idk,Disable GPU on AM437x IDK,
   LCPD-15864,am57xx-evm,SoC Performance Monitoring tool is still not enabled,
   LCPD-16130,j721e-evm,Exception triggered by drm_dev_unregister during poweroff,
   LCPD-16664,am654x-evm,MMU Alloc errors and Kernel Oops with RT build,
   LCPD-16366,j721e-evm,RGX kick test fails when 32 sync dependencies are set for each command,
   LCPD-15410,dra7xx-evm,vdd_shv_power is ~200mw higher than on previous lts,
   LCPD-17182,j721e-evm,Android: j721e: unable to boot to UI with 2K display,
   LCPD-17164,am335x-evm,GLBenchmark is not able to run missing libgbm.so.2 error reported,create a symlink for linker file
   LCPD-17413,am335x-evm,QT Webengine-based browser: the mouse does not work within the web page with QPA EGLFS,
   LCPD-17370,j721e-evm,Android: Executing Andebenchpro benchmark app results in kernel crash,
   LCPD-16921,j721e-evm,GPU driver doesn't unregister genpd name on unload,
   LCPD-10964,dra76x-evm,Segmentation fault observed when trying to run GC320 test app,
   LCPD-9819,am571x-idk,drmextended app cannot enable plane,
   LCPD-9006,am57xx-evm,Some GLBenchmark tests fail to run,
   LCPD-7130,dra7xx-evm,KMSCube with video does not work,
   LCPD-8352,am43xx-gpevm,weston: stress testing with 75 concurrent instances of simple-egl leads to unresponsive HMI due to running out of memory,1. Restart Wayland application. 2. Restart board if Weston is killed by oom-killer
   LCPD-13429,,Init/exit sequence in GBM leads to error,None
   LCPD-12270,dra72x-evm,VDD_SHV5 power consumption is ~ 200mw higher than on previous releases,
   LCPD-17213,j721e-evm,Weston sometimes fails to start when booting with nfs filesystem,
   LCPD-18431,am57xx-evm,Display artifacts on QT window,
   LCPD-18851,j721e-evm,UYVY texture test needs update,
   LCPD-18214,dra7xx-evm,SGX-HW recovery seen with NV12 buffer usage with wayland-drm applications,
   LCPD-17412,am654x-evm,QT5 Webengine-based browser crashing with any resize operation,
   LCPD-15794,am57xx-evm,Allow non-root user access to graphics resources to enable graphics use case,
   LCPD-18908,am654x-evm,GLMark2 fails for am65x,
   LCPD-15795,am57xx-evm,Allow non-root user access to IPC resources to enable multimedia use case,
   LCPD-5654,AM335x,AM3 Beaglebone black: MPEG4+AAC Dec does not play out any audio for some HDMI monitors,
   LCPD-9753,am571x-idk,GLSDK gst test suite waylandsink and 1080i kmssink tests fail,
   LCPD-17283,j721e-evm,Running Gstreamer's gst-discoverer causes a crash,
   LCPD-17138,,Kernel warning reported during h264 video encode operations,
   LCPD-9754,am571x-idk,GLSDK Sometimes capture + encode fails,
   LCPD-13443,am57xx-hsevm,Camera is not detected on AM572x-HSEVM,
   LCPD-16531,j721e-evm,video decode: vxd_dec warnings displayed at end of gstreamer hevc playback to kmssink for certain video,
   LCPD-15810,am335x-evm,Illegal instruction reported when trying to decode h264 stream with gstreamer,None
   LCPD-13816,am654x-evm,Chromium-wayland broswer does not work on AM654x with page size = 64k,
   LCPD-13817,am654x-evm,Qt5 Webengine-based broswer does not work on AM654x with pagesize = 64k,
   LCPD-17817,am335x-hsevm,Images created with Proc-SECDEV grow with number of times SECDEV has been used,
   LCPD-17781,am43xx-epos,am43xx-epos boot instability ,
   LCPD-16207,am574x-hsidk,Board does not boot sometimes due to crypto crash when debug options are enabled,None
   LCPD-9364,am57xx-hsevm,There are SCM FW warnings during the am57xx-hsevm boot,
   LCPD-9782,k2e-hsevm,CPU hotplug generates an exception and system crashes,
   LCPD-9254,am43xx-hsevm,Kernel warnings in boot for am437x-hsevm,
   LCPD-12709,am43xx-hsevm,Boards resets when standby state is attempted ,
   LCPD-14254,am654x-evm,meta-ti: Need a recipe update to pick up the new AM65x PRU Ethernet firmwares,
   LCPD-13947,am335x-evm,nativesdk-opkg is broken in the devkit,
   LCPD-16053,k2e-evm,IP address is not getting displayed on EVM LCD for K2 EVMs,
   LCPD-16114,am335x-evm,RTC Init Script Needs to Wait for Module Load,
   LCPD-4952,K2E,tisdk-image.bbclass limitation on TARGET_IMAGES,
   LCPD-5091,AM335x,Installing AM335x CoreSDK 15.01 leads to dumped core,
   LCPD-4327,AM572x,remove temporary files from kernel package,
   LCPD-5649,K2E,Integration: Release content for core-sdk should not be the content of SD card for k2 platform,
   LCPD-16877,k2hk-evm,ti-ipc-examples-linux intermittent build failure,
   LCPD-14552,,Enable snmpd in coresdk,
   LCPD-9616,am57xx-evm,QtCreator GDB (remote) debugging stops working since QT5.7.1,use GDB from Processor SDK 3.2
   LCPD-9415,,File system is  missing resource visualization tool,
   LCPD-9072,k2e-evm,netapi requires changes due to new libnl and xfrm,
   LCPD-17449,am335x-evm,libasan_preinit.o is missing in devkit,
   LCPD-9923,am335x-evm,Error message in boot log for K2 and AM platforms,
   LCPD-8404,,Fix jira check script to only send one email per broken instance,
   LCPD-7255,am335x-evm,Telnet login takes too long (~40 seconds),"Booting with rootfs mounted over NFS might cause ~40 seconds delay on telnet login because DNS entries might not be properly populated. To work around this issue, enter appropriate DNS server IP in resolv.conf. For example:   echo 'nameserver 192.0.2.2' > /etc/resolv.conf"
   LCPD-8345,am335x-evm,"Board fails to start login console after waiting 3.5 minutes ( hard to reproduce, ~4/1000)",Restart the EVM
   LCPD-7025,am43xx-gpevm,System takes more than 10 seconds to go from login prompt to system prompt,Automated tests need to account for this boot delay
   LCPD-12443,omapl138-lcdk,SD boot time with coresdk rootfs increases ~30% on omapl138-lcdk,
   LCPD-12405,am335x-evm,Openssl certgen fails due to coredump in openssl_gen_cert.sh,
   LCPD-12383,omapl138-lcdk,Umount failed if sata is mounted as vfat after boot without enough delay before umount,
   LCPD-15562,,OpenSSL1.1 does not have hooks for using hw crypto,Use openssl1.0 for crypto
   LCPD-18633,,ipc-lld-examples-rtos builds in single thread,
   LCPD-15918,am43xx-gpevm,ti-ipc-rtos gets stuck in xdctools,
   LCPD-4890,,ECS_TEAM: ap_test.sh demo script does not work as is and changes required are documented here,
   LCPD-8686,,ECS: DRA7 - wl18xx_multi module insert/remove leads to mm_fault errors,
   LCPD-17368,j721e-evm,Format support - Mismatch with DDK - Android Allocator (NV12),
   LCPD-8210,am571x-idk,QT Touchscreen interaction (Bear Whack) crash,
   LCPD-9423,,kmscube with video: viddec3test sometimes return error 139,None
   LCPD-8398,dra7xx-evm,gsttestplayer: Reverse playback stops after next seek,
   LCPD-17304,j721e-evm,Error Recovery Test for VDEC_ERROR_SR_ERROR does not trigger error,
   LCPD-8278,k2e-hsevm,Secure boot takes more than 10 minutes,
   LCPD-15367,am335x-evm,Boot time increased about 15s ,

|

U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   LCPD-18627,am654x-idk,uboot does not read the reserve-memory from the fdt ,
   LCPD-17770,am654x-evm,U-Boot: Fix order of MCU R5 shutdown depending on cluster mode,
   LCPD-17406,j721e-idk-gw,U-boot: Uboot has no knowledge of memory reserved for remote cores,
   LCPD-17210,am571x-idk,"AM57x EVM could not boot when using DEFAULT_DEVICE_TREE=""am57xx-beagle-x15""",
   LCPD-16524,am654x-evm,Need to adjust RMW bit when using enabling ECC,None
   LCPD-15725,,[Klokworks uboot] Resolve or indicate false positives on arch/arm/mach-omap2/emif-common.c,
   LCPD-15720,,[Klokworks uboot] Resolve or indicate false positives on drivers/dfu/dfu_ram.c,
   LCPD-15719,,[Klokworks uboot] Resolve or indicate false positives on arch/arm/mach-omap2/hwinit-common.c,
   LCPD-15711,,[Klokworks uboot] Resolve or indicate false positives on arch/arm/mach-omap2/omap5/sdram.c,
   LCPD-15710,,[Klokworks uboot] Resolve or indicate false positives on board/ti/common/board_detect.c,
   LCPD-15054,am571x-idk,[u-boot] AM57xx phy_ctrl structures must be board-specific,None
   LCPD-14843,am654x-evm,U-boot should support  default settings for netboot ,None
   LCPD-14638,k2g-evm,Invalid  DDR_PHY_MR2 setting in K2G board library,None
   LCPD-10726,am572x-idk,Update DDR3 emif regs structure for EMIF2 for the beagle_x15 board in U-Boot board file,None
   LCPD-9369,,AM437x GP EVM older PG version Uboot UART boot fails intermittently,
   LCPD-8701,k2g-ice,Soft reboot broken,
   LCPD-8295,dra71x-evm,vout1 pins missing manual i/o configuration,
   LCPD-7776,dra7xx-evm,U-boot: DRA7XX: secure boot fails on Rev-G J6 EVM,
   LCPD-18643,am335x-evm,U-Boot: AM335x/AM473x: Both SPI CS signals get asserted,
   LCPD-18620,am654x-evm,AM65x PG2: U-Boot MMC/SD does not work at greater than 25MHz clock,
   LCPD-17789,j721e-idk-gw,UBOOT J7:  Could not see UFS device by scsi scan,
   LCPD-16696,am654x-evm,U-Boot does not recognize SD-Card after re-insert/change,
   LCPD-15873,am654x-evm,There is no dtbo in u-boot for PCIe x1 + usb3 daughter card,None
   LCPD-12348,dra71x-evm,U-boot: MMC/SD: MMC erase fails with timeout,
   LCPD-11197,dra72x-evm,Uboot: Writing GPT partitions to emmc causing CACHE: Misaligned messages,
   LCPD-10668,k2g-evm,Ethernet boot: Sometimes the board could not boot uboot from Ethernet on k2g-evm,None
   LCPD-9539,k2g-evm,dhcp does not work after soft reboot,None
   LCPD-7864,am335x-evm,U-Boot: Ethernet boot fails on AM335x and AM437x,
   LCPD-7547,k2g-evm,uboot nand write hangs for big size on k2g,
   LCPD-7366,am335x-evm,uboot McSPI driver drives multiple chip selects simultaneously,None
   LCPD-5517,AM572x,Board fails to load bootloader sometimes when eSATA is connected,None
   LCPD-5416,K2G,"U-BOOT: K2G: ""reset"" fails for certain SD cards",None
   LCPD-5116,AM335x,BBB: U-Boot: Board fails to acquire dhcp address sometimes,None


|


Linux Kernel Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Priority", "Title", "Component", "Subcomponent", "Platform", "Workaround", "Impact"
   :widths: 5, 10, 70, 10, 5, 20, 35, 20

   LCPD-9877,P2-High,rtc alarm does not wakeup board from poweroff state,Power & Thermal,omapl138-lcdk,,,
   LCPD-17471,P2-High,device hang when restarting crashed R5F,IPC,am654x-evm,,,
   LCPD-18832,P2-High,NVMe SSD could not be detected reliably,Connectivity,am654x-idk,,,
   LCPD-15708,P2-High,J721E: vlab: MMC1 not functional,Connectivity,j721e-vlab,MMCSD,,
   LCPD-14249,P2-High,PCI kernel oops seen between rc7 and rc8 of 4.19,Connectivity,j721e-vlab,,,
   LCPD-9972,P2-High,Soft reboot failed on k2g-evm with class 10 SD cards,Connectivity,k2g-evm,,Do not use soft reboot,
   LCPD-18902,P2-High,Unhandled Exception from EL1 observed during boot,Baseport,am654x-hsevm,,,
   LCPD-18784,P2-High,SD boot and eMMC alternative boot do not work if tftp images instead of fatload,Baseport,am654x-idk,,,
   LCPD-13653,P2-High,am65x-evm could not boot from MMC/SD when MMC/SD is backup boot mode,Baseport,am654x-evm,,No workaround,
   LCPD-13412,P2-High,VIP camera sensor (mt9t11) is not initialized properly,Audio & Display,am57xx-evm,,,
   LCPD-10997,P3-Medium,ABB voltage did not increase for 1800 MHz,Power & Thermal,dra76x-evm,,,
   LCPD-18633,P3-Medium,ipc-lld-examples-rtos builds in single thread,IPC,,Firmware,,
   LCPD-16877,P3-Medium,ti-ipc-examples-linux intermittent build failure,IPC,k2hk-evm,,,
