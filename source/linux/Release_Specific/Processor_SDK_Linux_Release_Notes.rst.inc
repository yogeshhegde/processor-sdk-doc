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

Release 05.02.00
==================

Released December 2018

.. rubric:: What's New
   :name: whats-new

- AM654x
    - DDR @ 1666 MT/s
    - IPC: Support IPC between A53 running Linux with R5F running in split mode
    - Driver and API to access AM654x internal temp sensors
    - Add ARMNN and ARM Compute Library
    - Early Access: DisplayPort driver for TC358867 DPI-DP bridge
    - IPSec sideband support 
    - Kernel: OSPI Performance Improvement w/ DMA mode
    - MCAN Support
    - Rotary Encoder support
    - Support SPI Flash as mtd device
    - PCIe Gen3 RC and EP mode support
- `Support Docker containerization <Foundational_Components_Virtualization.html#docker-linux-container-runtime>`__
- Integrate OPCUA open source stack (Open65241)
- Add Tiny Filesystem to PLSDK to support on board flashing of eMMC and QSPI from an initramfs
- HSR/PRP/EMAC/PTP
    - `EMAC: Multicast, VLAN and Storm prevention feature <Industrial_Protocols_HSR_PRP.html#linux-software>`__
    - `EMAC: PTP Support for SAN mode <Industrial_Protocols_PTP.html>`__
    - HSR: Add support of PTP 1-step to 2-step conversion on ingress
    - HSR: PTP OC Master or Slave (with redundancy)
    - PRP: PTP OC Master or Slave (with redundancy)
- Deep Learning
   - `Port ARM NN inference engine to AM65x <Foundational_Components_ArmNN.html>`__
   - `Add Arm NN MobileNet demo <Foundational_Components_ArmNN.html#arm-nn-mobilenet-demo>`__
   - Publish TIDL import tool source files
- Add IWR6843 (60GHz) support to the `TI design TIDEP-01006 <http://www.ti.com/tool/TIDEP-01006>`__

.. rubric:: SDK Components & Versions
   :name: sdk-components-versions

+--------------------------+----------------------------+
| Component                | Version                    |
+==========================+============================+
| Linux Kernel             | 4.14.79+ (2018 LTS)        |
+--------------------------+----------------------------+
| U-Boot                   | 2018.01                    |
+--------------------------+----------------------------+
| Yocto Project            | 2.4 (rocko)                |
+--------------------------+----------------------------+
| Linaro Toolchain (gcc)   | 7.2-2017.11 hard-float     |
+--------------------------+----------------------------+
| Qt                       | 5.9.7                      |
+--------------------------+----------------------------+
| OpenCL                   | 1.1.17                     |
+--------------------------+----------------------------+
| OpenCV                   | 3.1                        |
+--------------------------+----------------------------+
| Wayland                  | 1.13                       |
+--------------------------+----------------------------+
| GStreamer                | 1.12.2                     |
+--------------------------+----------------------------+
| Chromium                 | v53                        |
+--------------------------+----------------------------+
| TI PRU Compiler          | 2.2.1                      |
+--------------------------+----------------------------+
| TI C66x CGT Compiler     | 8.2.2                      |
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
| Based on verson: 2018.01
| URL: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2018.01
| Commit ID: 313dcd69c2b32648266f91bcf223f9e539bc4201

|

Kernel
-------------------------

.. rubric:: Linux Kernel
   :name: linux-kernel

| The kernel git repository, branch and commit id can be found below:
| Based on Version: 4.14.79
| URL: git://git.ti.com/processor-sdk/processor-sdk-linux.git
| Branch: processor-sdk-linux-4.14.y
| Commit ID: bde58ab01e3651529680af3eeea7e4d37cb94d40

|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| The RT kernel git repository, branch and commit id can be found below:
| Based on:
| Kernel Version: 4.14.79
| RT Kernel Version: 4.14.79-rt47

| URL: git://git.ti.com/processor-sdk/processor-sdk-linux.git
| Branch: processor-sdk-linux-rt-4.14.y
| Commit ID: 28d73230daa45803af5fed792bf635fe40ee3dbd

|

.. rubric:: Generic Kernel Release Notes
   :name: generic-kernel-release-notes

| Generic kernel release notes from kernelnewbies.org can be found at:
  http://kernelnewbies.org/Linux_4.14
| Archived versions can be found at:
  http://kernelnewbies.org/LinuxVersions

|

Issues Tracker
=====================================

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 20, 70

   LCPD-13895,"am654x-evm, am654x-idk",Kernel Paging request during ipsec association with sa2ul module removed
   LCPD-13899,"am335x-evm, am335x-ice, am335x-sk, am437x-idk, am437x-sk, am43xx-gpevm, am571x-idk, am572x-idk, am574x-idk, am57xx-evm, am654x-evm, am654x-idk, beaglebone, beaglebone-black,k2e-evm, k2g-evm, k2g-ice, k2hk-evm, k2l-evm, omapl138-lcdk",rpmsg: probe of rpmsg drivers broken on 4.14 integration kernel
   LCPD-13870,"am654x-evm, am654x-idk",remoteproc/k3-r5f: IPC does not work with SYSFW 2018.08a or 2018.08b releases
   LCPD-13767,am654x-idk,am654x: RT mmc probe errors
   LCPD-13725,"am654x-evm, am654x-idk",AM6 Board: Board intermittently hangs before getting to u-boot
   LCPD-13632,"am654x-evm, am654x-idk",AM65: icssg-prueth: Port 2 doesn't work if Port 1 is not first brought up
   LCPD-14173,am654x-idk,AM65x PRU ethtool missing functionality
   LCPD-14142,"am654x-evm, am654x-idk",AM65x: Uboot can't load environment in eMMC boot
   LCPD-13896,,IPSec performance with sa2ul is one-fourth that in 2018.03 without sa2ul
   LCPD-6144,am572x-idk,am572x-idk: eMMC failed to enumerate
   LCPD-10533,"am335x-evm, am335x-ice, am43xx-epos, am43xx-gpevm, am571x-idk, am572x-idk, am574x-idk, am57xx-evm",Crypto: SHA1_Hash demo test fails on AM3/4/5 platforms
   LCPD-5308,"AM437x, AM571x, AM572x, K2E, K2G, K2HK, K2L",i897: USB Stop Endpoint doesnt work in certain circumstances
   LCPD-13892,"am57xx-evm",DMM: Kernel crash on module removal due to interrupt after the resources have been released
   LCPD-13882,"am571x-idk, am572x-idk, am574x-idk",am57xx-idk: cpufreq fails to probe
   LCPD-13542,"am654x-evm, am654x-idk",U-boot: HS400 fails to enumerate on some boards
   LCPD-13499,am654x-evm,SGX KM Memory allocation failure
   LCPD-13502,am654x-evm,Maxwell: Matrix GUI does not work
   LCPD-13687,"am335x-evm, am43xx-gpevm, am57xx-evm, am654x-evm",QtWebengine demobrowser crashes during window resize operations at LTS2018
   LCPD-13411,"am654x-evm, am654x-idk",u-boot reset command does not reset the board
   LCPD-13832,,usb: missing CONFIG_USB_ANNOUNCE_NEW_DEVICES option
   LCPD-13819,"am335x-ice, am437x-idk, am571x-idk, am574x-idk, am654x-evm, am654x-idk, k2g-ice",Kernel warning is sometimes observed when stopping a remoteproc
   LCPD-13739,"am654x-evm, am654x-idk",K3M: CPSW: default P0 rx fifo mode is Fixed priority
   LCPD-13724,"am654x-evm, am654x-idk",AM6 Board: Getting continuously scrolling mmc error when trying to boot
   LCPD-13813,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm","In 2018 LTS, CCS can't connect to DSP if ARM is running Linux"
   LCPD-13666,am654x-evm,Seeing mmc0 timeout errors on some boards
   LCPD-13667,am654x-evm,mmc 0 timeout and env could not be saved to eMMC on one board (farm26)
   LCPD-14181,"am654x-evm, am654x-idk",Thermal driver is disabled
   LCPD-13304,am335x-evm,am335x-evm.dts lists wrong number of PHY's
   LCPD-12566,,CAN user guide references canconfig which is not supported any more
   LCPD-11417,,Latest GLmark2 fails against our GLES
   LCPD-13428,,Init/exit sequence in GBM leads to error
   LCPD-13800,,Seeing UBIFS assert failed error in OSPI stress test
   LCPD-13716,am654x-evm,KS3M: eMMC boot: document board switch settings in users guide
   LCPD-13356,am654x-evm,icssg-prueth pruss2_eth: slice 0: cmd 4 failed: -5 when pru eth interface is brought up
   LCPD-13453,"k2e-evm, k2g-evm, k2g-ice, k2hk-evm, k2l-evm",MPM service daemon does not start. Error allocating CMEM buffer
   LCPD-10954,am437x-sk,DSS sync-losts and underflows seen with bad config
   LCPD-14166,"am654x-evm, am654x-idk",Hang observed with stop->unload->load module sequence
   LCPD-14161,"am654x-evm, am654x-idk",Repeated CPU hotplug may fail in ATF
   PLSDK-1828,"am571x-idk, am572x-idk","HSR: In a ring topology, seeing small performance degradation with concurrent traffic"
   PLSDK-2067,am571x-idk,Transparent Clock crashes after a couple of days due to memory leak
   PLSDK-2253,am571x-idk,Accidental loop (no STP enabled) crashed Linux
   PLSDK-2323,am571x-idk,PRUETH: hsr/prp on PRUSS1/PRUSS2 can't co-exists with Dual EMAC
   PLSDK-2330,am654x-evm,"Simple People Tracking Demo doesn't restart Matrix GUI intermittently, when there is no ToF EVM connected"
   PLSDK-2331,am654x-evm,"Matrix-GUI EVSE demo Text overflows the button, and gets truncated"
   PLSDK-2339,"am335x-evm, am335x-ice, am335x-sk, am437x-evm, am437x-idk, am437x-sk, am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk, beagleboneblack",Matrix GUI takes 2 min to launch when not connected to ethernet
   PLSDK-2352,"am335x-evm, am437x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk, am654x-evm, am654x-idk",Graphics Demo: Video_Scaling_Overlaying_Positioning test failing on am platforms
   PLSDK-2384,"am335x-ice, k2g-ice",PRUETH Probe resource error
   PLSDK-2385,am654x-evm,weston failure warning stays even when multimedia demo is running successfully
   PLSDK-2389,am654x-evm,AM65XX: Linux Top level make file does not build IPC targets
   PLSDK-2394,am335x-ice,OOB UIO PRU-ICSS EMAC demo - Segmentation fault
   PLSDK-2404,"am335x-evm, am335x-ice, am335x-sk, am437x-evm, am437x-idk, am437x-sk, am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk, am654x-evm, am654x-idk, beagleboneblack","weston.ini script needs to change ""panel-location"" setting to ""panel-position"""
   PLSDK-2412,"am571x-idk, am572x-idk, am574x-idk","Error message ""msg 0 finds ts queue occupied"" is observed when running ptp in heavy network traffic"
   PLSDK-2413,"am571x-idk, am572x-idk, am574x-idk","Error message such as 'SYNC cut-thru ts ERROR: ct=1537669620.548208499, rx=1537669621.548189123"" observed when running linuxptp in heavy traffic"
   PLSDK-2417,"am572x-evm, am574x-idk",TIDL camera demo output freezes after 10min to 1hour
   PLSDK-2423,"am571x-idk, am572x-idk, am574x-idk",Cable unplug and plug-back on a 3-port BC leads to BC internal clocks out of sync
   PLSDK-2433,"am572x-evm, am572x-idk, am574x-idk, am654x-evm, am654x-idk",TIDL softmax based probability and confidence estimates do not look correct
   PLSDK-2443,,Use sv_dei instead of sv_cfi for VLAN tag information in ip link command
   PLSDK-2446,"am571x-idk, am574x-idk",PTP BC: Need to disable the decoder while updating the GPIO pins
   PLSDK-2447,"am335x-evm, am335x-ice, am335x-sk, am437x-evm, am437x-idk, am437x-sk, am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk, am654x-evm, am654x-idk, beagleboneblack, k2e-evm, k2g-evm, k2g-ice, k2hk-evm, k2l-evm, omapl138-lcdk",Install Banner has Incorrect Host Information for 18.04
   PLSDK-2449,"am654x-evm, am654x-idk",Updating Building Processor SDK for AM65x
   PLSDK-2451,"am335x-ice, am437x-idk, am571x-idk, am572x-idk, am574x-idk, k2g-ice",am3/4 workaround for node table update causes CPU load increase for PRP
   PLSDK-2464,am571x-idk,BC internal sync fails when eth1 cable is unplug
   PLSDK-2478,am574x-idk,TIDL recipes:tidl and tidl-ref (for ARMv7) platform fail
   PLSDK-2495,"am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk",Error in make linux_install
   PLSDK-2504,,drm/tidss: dispc7: Map vidl1 hw plane to plane number 0

|


Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 20, 70

   LCPD-14228,,remove unnecessary config fragments
   LCPD-14251,"am654x-evm, am654x-idk",Setting clock frequency fails after enable/disable clock sequence
   LCPD-14396,"am654x-evm, am654x-idk","AM654: UDMA: Descriptors for memcpy are not aligned, causing random channel lockup"
   LCPD-14275,"am654x-evm, am654x-idk",am654x: RT: cleanup and optimize configs for latency improvement
   LCPD-14305,,Latest master OE builds with meta-ti are failing
   LCPD-14304,,"New XDC, BIOS and CGT fail to download"
   LCPD-14229,"am654x-evm, am654x-idk",SDCard boot broken on AM65x after Android patches
   LCPD-14258,"am654x-evm, am654x-idk",AM65: USB: Software based role switching broken
   LCPD-14223,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm",WB: M2M: Add cropping support
   LCPD-14224,"am654x-evm, am654x-idk",CONFIG_CRYPTO_TEST needs to be enabled
   LCPD-14241,"am654x-evm, am654x-idk",remoteproc/k3-r5f: fix a use-after-free error with fixed memory support
   LCPD-14264,"am654x-evm, am654x-idk",remoteproc/k3-r5f: memory leak issue when module is installed and removed
   PLSDK-2380,"am571x-idk, am572x-idk, am574x-idk",missing timestamp error debug prints observed in HSR ptp test
   PLSDK-2381,"am571x-idk, am572x-idk, am574x-idk",Linux kernel crash in HSR PTP test with 100M network traffic
   PLSDK-2445,"am335x-ice, am437x-idk, am571x-idk, am572x-idk, am574x-idk, k2g-ice",PRUETH Ethtype Boot Param not working
   PLSDK-2494,"am571x-idk, am572x-evm",video-graphics-test: kernel crash observed
   PLSDK-2502,"am571x-idk, am572x-evm, am572x-idk",TIDL_Without_EVE: TIOCL FATAL: Internal Error
   PLSDK-2506,"am335x-ice, am437x-idk, am571x-idk, am572x-idk, am574x-idk, k2g-ice",HSR/PRP VLAN enable not functional
   PLSDK-2508,"am654x-evm, am654x-idk",create-sdcard script does not copy sysfw image to sd card
   PLSDK-2528,"am654x-evm, am654x-idk",mpeg-4 and h264 decode do not use full screen
   PLSDK-2532,am572x-evm,Boot fails when using SD card created on Windows
   PLSDK-2535,,PTP BC enhancements cause compiling error for non-BC devices
   PLSDK-2536,,TIDL single layers group classification example started from Matrix-GUI reports "no detection" error

|

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
   :header: "Record ID",  "Title"
   :widths: 15, 80

   LCPD-1188,J6: Baseport: Errata i877: RGMII clocks must be enabled to avoid IO timing degradation due to Assymetric Aging
   LCPD-1022,J6: Errata: i694: System I2C hang due to miss of Bus Clear support @ OMAP level
   LCPD-976,J6/J6eco: 32clk is psuedo (erratum i856) - clock source
   LCPD-975,J6/J6eco: 32clk is psuedo (erratum i856) - realtime counter
   LCPD-4225,J6: Errata: i834: Investigate possibility of software workaround
   LCPD-4195,J6: SATA: Investigate applicability of i807
   LCPD-5310,"i900: CTRL_CORE_MMR_LOCK_5 region after locking results in ctrl module inaccessible, recoverable only post a reset"
   LCPD-5311,i893: DCAN ram init issues in HW AUTO and when traffic hitting CAN bus (open investigation)
   LCPD-5309,LCPD: i896: USB Port disable doesnt work
   LCPD-9084,i887: Software workaround to limit mmc3 speed to 64MHz
   LCPD-7642,MMC/SD: i832: return DLL to default reset state with CLK gated if not in SDR104/HS200 mode.
   LCPD-6907,Workaround errata i880 for RGMII2 is missing
   LCPD-5931,DRA7xx: AM57xx: mmc: upstream errata workaround for i834
   LCPD-5924,ALL: CONNECTIVITY: CPSW: errata i877 workarround for cpsw
   LCPD-5836,CAL: Errata: i913: CSI2 LDO needs to be disabled when module is powered on
   LCPD-4648,[rpmsg 2014 LTS] Implement errata i879 - DSP MStandby requires CD_EMU in SW_WKUP
   LCPD-4647,[rpmsg 2015 LTS] Implement errata i879 - DSP MStandby requires CD_EMU in SW_WKUP
   LCPD-1146,DMM hang: Errata VAYU-BUG02976 (i878) (register part)
   LCPD-1108,J6: Wrong Access In 1D Burst For YUV4:2:0-NV12 Format (Errata i631)
   LCPD-1087,J6: MMC: Errata: i802: OMAP5430 MMCHS: DCRC errors during tuning procedure
   LCPD-876,OMAP5: Errata i810: DPLL Controller Sticks when left clock requests are removed
   LCPD-4218,Implement Workaround for Errata i813 - Spurious Thermal Alert Generation When Temperature Remains in Expected Range
   LCPD-4217,Implement Workaround for Errata i814 - Bandgap Temperature read Dtemp can be corrupted
   LCPD-4184,Implement workaround for errata i814 - Bandgap Temperature read Dtemp can be corrupted
   LCPD-5052,Upstream: Post the dmtimer errata fix for i874
   LCPD-4975,DSS AM5/DRA7: implement WA for errata i886
   LCPD-4912,DRA7: USB: Implement ErrataID_i896_PED_issue
   LCPD-4910,J6/OMAP5: errata i810 implementation
   LCPD-4911,DRA7: USB: Investigate applicability of Errata i897: StopEndpoint_issue
   LCPD-5460,Implement WA for Vayu errata i829 (Reusing Pipe Connected To Writeback Pipeline On The Fly To An Active Panel)
   LCPD-5308,i897: USB Stop Endpoint doesnt work in certain circumstances
   LCPD-13887,DDR Controller ECC Scrubbing feature can cause DRAM data corruption
   LCPD-13884,CPTracer Bus Probes MAIN_CAL0_0 and MCU_SRAM_SLV_1 are not able to distinguish between secure and non-secure transactions
   LCPD-14185,MSMC: Non-coherent memory access to coherent memory can cause invalidation of snoop filter
   LCPD-14159,The assertion of warm reset coinciding with a debug configuration access targeting the STM Subsystem may result in a hang of said debug configuration access
   LCPD-9173,i897: USB Stop Endpoint doesnt work in certain circumstances
   LCPD-8294,37 pins + VOUT pins need slow slew enabled for timing and reliability respectively
   LCPD-8277,u-boot: j6: SATA is not shutdown correctly as per errata i818
   LCPD-1776,"[J6 SATA Adaptation] J6 - Errata i783, SATA Lockup After SATA DPLL Unlock/Relock"
   LCPD-941,"OMAP4,5: DSS: implement workaround for errata i740"
   LCPD-14186,UDMA-P Host Packet Descriptor?s ?0x3FFFFF? Packet Length Mode not Functional


|

SDK Known Issues
-----------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 25, 30, 50, 60

   LCPD-8345,"am335x-evm, am437x-idk, k2e-evm, k2hk-evm, k2l-evm","Board fails to start login console after waiting 3.5 minutes ( hard to reproduce, ~4/1000)",Restart the EVM
   LCPD-8352,"am43xx-gpevm, am57xx-evm",weston: stress testing with 75 concurrent instances of simple-egl leads to unresponsive HMI due to running out of memory,1. Restart Wayland application. 2. Restart board if Weston is killed by oom-killer
   LCPD-9006,"am57xx-evm",Some GLBenchmark tests fail to run,
   LCPD-9616,am57xx-evm,QtCreator GDB (remote) debugging stops working since QT5.7.1,use GDB from Processor SDK 3.2
   LCPD-11010,am574x-idk,AM574x-idk graphics performance is lower than am572x-idk,"Performance issue, no workaround"
   LCPD-13470,am335x-evm,klogd and syslog are not needed when using systemd,
   PLSDK-832,AM57,OpenCL matmpy intermittent DSP1 crash due to EdmaMgr issues w/ suspend/resume,"Disabling suspend/resume on the DSPs prevents this intermittent failure: *echo on > /sys/bus/platform/devices/40800000.dsp/power/control; echo on > /sys/bus/platform/devices/41000000.dsp/power/control*"
   PLSDK-1398,"k2g-hsevm, k2hk-hsevm, k2e-evm, k2e-hsevm",Document workaround for IPC demo hangs if run after OpenCL demos,Run IPC demo w/o running OpenCL first
   PLSDK-1419,k2l-evm,Intermittent-IP address display issue on LCD for K2L RT,"Use ifconfig once Linux boots, to acquire IP address"
   PLSDK-1720,am437x-evm,Simple people tracking demo: Tracking Incorrect Number of People,None
   PLSDK-1909,am572x-evm,DLP SDK demo: Assertion `ctx->pollfds_cnt >= internal_nfds' failed,None
   PLSDK-1924,"am335x-ice, am335x-sk, beagleboneblack",AM3: Observed unwanted failure message in boot log.,No functionality affected except the log message
   PLSDK-1953,"am571x-idk, am572x-idk",Linux PRP: lreTransparentReception - passRCT doesn't work as expected,None
   PLSDK-2095,"am571x-idk, am572x-idk","kernel: EXPORT symbol ""__hyp_stub_vectors seen during kernel build", "it is just a warning message, and can be ignored"
   PLSDK-2107,k2g-ice,sorte for K2G: master is not working,None
   PLSDK-2109,"am437x-evm, am572x-evm",QtWebengine demobrowser shows problems at LTS2018 on EGLFS QPA,None
   PLSDK-2128,"am335x-evm, am437x-evm, am438x-epos-evm, am572x-evm",Weston 2.0: overlay window display issue,"None. For Wayland demo, you may use qwindow-compositor instead of Weston."
   PLSDK-2178,"am335x-ice, am437x-idk",ICSS EMAC intermittent error in received acyclic packet content,None
   PLSDK-2181,k2g-ice,k2g-ice Eth0 IP address not displayed,
   PLSDK-2186,am572x-evm,video-analytic-demo should run on top of Weston instead of qwindow-compistor,"Run the demo on top of qwindow-compositor, as available from Matrix GUI"
   PLSDK-2220,k2e-evm,UBI Image for K2E exceeds the available size limit,None
   PLSDK-2312,"am335x-evm, am437x-evm, am572x-evm",Some Qt3d examples either crash or works with errors,
   PLSDK-2319,am654x-evm,QT5 Touch Screen demo: characters are corrupted, "Set environment variable QML_USE_GLYPHCACHE_WORKAROUND to 1: export QML_USE_GLYPHCACHE_WORKAROUD=1"
   PLSDK-2355,"am572x-idk, am572x-evm",Openvx: openvx_tiovx_application hangs on am572x evm,
   PLSDK-2456,"am335x-ice, am437x-idk, am571x-idk, am572x-idk, k2g-ice",hsr: Node is not removed from node table after forget time.,"Node table can be manually cleared with: echo 1 > /proc/<hsr/prp-if_name>/clear-nt or will be cleared when device is rebooted."
   PLSDK-2465,"am571x-idk, am572x-idk, am574x-idk",Isolated BC stopped internal sync after about 9 hours,None
   PLSDK-2466,"am335x-ice, am437x-idk, am571x-idk, am572x-idk, k2g-ice",Fix Race condition in updating NSP credit value,None
   PLSDK-2472,am335x-ice,PRP Link Doesn't Re-establish Corrctly,None
   PLSDK-2473,"am335x-ice, am437x-idk, am571x-idk, am572x-idk, am574x-idk, k2g-ice","DualEMAC PTP ""invalid timestamp"" warning messages when starting ptp4l",None
   PLSDK-2474,am572x-evm,soc-performance-monitor table display problem (missing texts),None
   PLSDK-2514,"k2e-evm, k2l-evm",K2L:Observed failure messages in boot log,
   PLSDK-2515,"am571x-idk, am572x-evm, am572x-idk, am574x-idk","TIDL import tool should link with OpenCV to allow use of JPG, PNG",None
   PLSDK-2530,"am335x-ice, am437x-idk",AM3/4 PTP PPS fails intermittently,No complete workaround. Restarting the ethernet interface should reset PPS and likely resolve the issue temporarily.
   PLSDK-2545,"am574x-hsidk, am574x-idk",Caffe-Jacinto trained SSD model hangs when running the inference using TIDL on AM5749,None
   PLSDK-2564,am654x-idk,Maxwell IDK Multimedia Test Failures,None
   PLSDK-2565,am572x-evm,ROS navigation demo with IWR6843: intermittently the global path is not updated in time,None
   PLSDK-2566,"k2e-evm, k2e-hsevm, k2hk-evm, k2hk-hsevm, k2l-evm, k2l-hsevm",transportIpcQmssMultiProcess failed due to missing .out file on k2 platform,


|

U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID", "Priority", "Title", "Platform", "Workaround"
   :widths: 15, 10, 70, 30, 5

   LCPD-14325,P2-High,U-boot fails to read tispl.bin during android boot on some boards,,
   LCPD-13711,P3-Medium,U-Boot: EEPROM-based board detection support not available,"am654x-evm, am654x-idk",
   LCPD-12244,P3-Medium,AM43xx u-boot needs to support PHY_INVERT_CLKOUT=1,"am437x-idk, am437x-sk, am43xx-gpevm",
   LCPD-12176,P3-Medium,U-boot: Fix IOdelay error path issue,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm",
   LCPD-11586,P3-Medium,dhcp failed to get IP address after reboot for K2G-ICE non-RT linux,k2g-ice,
   LCPD-10805,P3-Medium,U-Boot: Fix uart boot on am335x-evm,am335x-evm,
   LCPD-10726,P3-Medium,Update DDR3 emif regs structure for EMIF2 for the beagle_x15 board in U-Boot board file,"am572x-idk, am57xx-evm",
   LCPD-9369,P3-Medium,AM437x GP EVM older PG version Uboot UART boot fails intermittently,,
   LCPD-8701,P3-Medium,Soft reboot broken,k2g-ice,
   LCPD-5416,P3-Medium,"U-BOOT: K2G: ""reset"" fails for certain SD cards",K2G,
   LCPD-13875,P3-Medium,U-boot: SD card times out in SPL when it is not the bootmode,"am654x-evm, am654x-idk",
   LCPD-13714,P3-Medium,OSPI boot settings for AM65x EVM must be documented in U-Boot users guide,am654x-evm,
   LCPD-10668,P3-Medium,Ethernet boot: Sometimes the board could not boot uboot from Ethernet on k2g-evm,k2g-evm,
   LCPD-9539,P3-Medium,dhcp does not work after soft reboot,k2g-evm,
   LCPD-7864,P3-Medium,U-Boot: Ethernet boot fails on AM335x and AM437x,"am335x-evm, am335x-ice, am335x-sk, am437x-idk, am437x-sk, am43xx-gpevm",
   LCPD-7547,P3-Medium,uboot nand write hangs for big size on k2g,k2g-evm,
   LCPD-7366,P3-Medium,uboot McSPI driver drives multiple chip selects simultaneously,am335x-evm,
   LCPD-5517,P3-Medium,Board fails to load bootloader sometimes when eSATA is connected,AM572x,
   LCPD-5116,P3-Medium,BBB: U-Boot: Board fails to acquire dhcp address sometimes,AM335x,
   LCPD-4817,P4-Low,am57xx-evm: uboot: usb failed to detect Kingston DataTraveler usb msc device,AM572x,

|


Linux Kernel Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Priority", "Title", "Component", "Subcomponent", "Platform", "Workaround", "Impact"
   :widths: 5, 10, 70, 10, 5, 20, 35, 20

   LCPD-9877,P2-High,rtc alarm does not wakeup board from poweroff state,Power & Thermal,,omapl138-lcdk,,
   LCPD-14188,P2-High,ICSSG PRUEth Extremely Slow,Connectivity,"ICSSG, PRUETH",am654x-evm,,
   LCPD-13766,P2-High,am654x: RT latency numbers are 60 us versus ~25 in am574x,Connectivity,,am654x-idk,Disable 64K pages in the config file to use default 4K pages (e.g. CONFIG_ARM64_64K_PAGES=n). OSADL Max latency is below 50usecs with 4K pages.,
   LCPD-9972,P2-High,Soft reboot failed on k2g-evm with class 10 SD cards,Connectivity,,k2g-evm,,
   LCPD-13653,P2-High,am65x-evm could not boot from MMC/SD when MMC/SD is backup boot mode,Baseport,,"am654x-evm, am654x-idk",,
   LCPD-12513,P2-High,Android O: Board takes longer to boot compared to MM,Baseport,,am57xx-evm,,
   LCPD-13412,P2-High,VIP camera sensor (mt9t11) is not initialized properly,Audio & Display,,am57xx-evm,,
   LCPD-12784,P3-Medium,Board can't resume from suspend state sometimes,Power & Thermal,,omapl138-lcdk,,
   LCPD-9527,P3-Medium,Potential deadlock reported by pm_suspend on am335x,Power & Thermal,,"am335x-evm, am335x-sk, beaglebone, beaglebone-black",,
   LCPD-7314,P3-Medium,Active power is slighly higher than on 2015 LTS release (Linux 4.1),Power & Thermal,,am335x-evm,,
   LCPD-7256,P3-Medium,Board sometimes hangs after suspend/resume cycle,Power & Thermal,,"am335x-evm, am57xx-evm",,
   LCPD-6427,P3-Medium,vpe fails to suspend sometimes,Power & Thermal,,"am571x-idk, am572x-idk, am57xx-evm",,
   LCPD-1245,P3-Medium,AM335x: Power: Reverse current leakage on poweroff,Power & Thermal,,am335x-evm,,
   LCPD-1204,P3-Medium,AM335x - Some voltage rails remain active during poweroff,Power & Thermal,,,,
   LCPD-965,P3-Medium,AM335x: Power: Poweroff is not shutting down voltage domains,Power & Thermal,,,,
   LCPD-14265,P3-Medium,PRUSS INTC driver doesn't support setting irq affinity,IPC,,"am571x-idk, am572x-idk, am574x-idk",,
   LCPD-14451,P3-Medium,Am65x: MMC: reasserting PDB at every stage loses calibration,Connectivity,MMCSD,"am654x-evm, am654x-idk",,
   LCPD-14450,P3-Medium,CPSW speed change with ethtool - unable to set to 100Mbps with ethtool,Connectivity,,"am654x-evm, am654x-idk",,
   LCPD-14448,P3-Medium,UART: 8250: transmit losses the first byte sometimes,Connectivity,UART,"am335x-evm, am335x-ice, am335x-sk",,
   LCPD-14447,P3-Medium,dmaengine: cppi41: kernel dumps from cppi41_run_queue(),Connectivity,USB,"am335x-evm, am335x-sk",,
   LCPD-14446,P3-Medium,8250_omap: kernel dump happens when using multiple uart ports,Connectivity,UART,,,
   LCPD-14445,P3-Medium,am335x: musb: the otg port stays in host mode if only the micro-A cable adapter is connected then removed,Connectivity,USB,am335x-evm,,
   LCPD-14230,P3-Medium,Ethernet Performance Limited by CPU / ksoftirqd,Connectivity,,"am654x-evm, am654x-idk",,
   LCPD-14208,P3-Medium,ADC: significant errors seen in measurements when performing single-ended conversions,Connectivity,ADC,,,
   LCPD-14189,P3-Medium,ICSSG Ethernet Kernel Panic,Connectivity,"ICSSG, PRUETH","am654x-evm, am654x-idk",,
   LCPD-14184,P3-Medium,USB: SuperSpeed USB Non-Functional,Connectivity,,am654x-evm,,
   LCPD-14183,P3-Medium,am654x-idk failed to login to kernel a few times (7/1000),"Connectivity, IPC",,am654x-idk,,
   LCPD-14171,P3-Medium,Failed to read uboot from SD card 1/1000 times,Connectivity,,"am57xx-evm",,
   LCPD-14136,P3-Medium,PCIe x2 usb tests failed on am654x-idk,Connectivity,,am654x-idk,,
   LCPD-13968,P3-Medium,fatwrite mmc failed on one idk board,Connectivity,,am654x-idk,,
   LCPD-13940,P3-Medium,mkfs.ext2 hangs when trying to format PCIe NVMe SSD device (Samsung PM961),Connectivity,,am654x-evm,,
   LCPD-13938,P3-Medium,PCIe EP read/write/copy test failed with larger sizes,Connectivity,,"am654x-evm, k2g-evm",,
   LCPD-13936,P3-Medium,Uboot dhcp timeout 1 of 100 times,Connectivity,,am654x-evm,,
   LCPD-13818,P3-Medium,MMC could not be built to module for am65xx,Connectivity,,am654x-evm,,
   LCPD-13775,P3-Medium,pcie performance test with pcie-eth card failed,Connectivity,,am654x-evm,,
   LCPD-13720,P3-Medium,SPI DMA TX Mode Halts During Continuous 16/32/64 bit Transfers,Connectivity,,beaglebone-black,,
   LCPD-13718,P3-Medium,musb: unbind musb-hdrc driver on one usb port breaks the other port,Connectivity,USB,am335x-evm,,
   LCPD-13717,P3-Medium,AM572x PG1.1ÿ: emmc: does not work. error -84 transferring data,Connectivity,eMMC,"am57xx-evm",,
   LCPD-13710,P3-Medium,KS3M: ICSSG: 100M link doesn't work,Connectivity,"ICSSG, ICSS_EMAC","am654x-evm, am654x-idk",,
   LCPD-13709,P3-Medium,USB camera gadget does not work on am6,Connectivity,,am654x-evm,,
   LCPD-13679,P3-Medium,There is no i2c command in uboot on am65x,Connectivity,,"am654x-evm, am654x-idk",,
   LCPD-13657,P3-Medium,ti-4.14 (2018.02) BBB Enet phy problem,Connectivity,,beaglebone-black,,
   LCPD-13603,P3-Medium,One board could not boot rootfs from more than one SDHC card,Connectivity,,am654x-evm,,
   LCPD-13587,P3-Medium,dwc3: g_audio can only record once,Connectivity,USB,am57xx-evm,,
   LCPD-13561,P3-Medium,AM64: icssg-prueth: prueth can fail occassionally with RX tdown timeout,Connectivity,UDMA,"am654x-evm, am654x-idk",,
   LCPD-13527,P3-Medium,A few pcie eth cards could not be enumerated on am654x-evm,Connectivity,,am654x-evm,,
   LCPD-13525,P3-Medium,Update PCIe EP user guide for am654x,Connectivity,,"am654x-evm, am654x-idk",,
   LCPD-13452,P3-Medium,USB Gadget Camera Capture - guvcview causes kernel oops,Connectivity,,k2g-evm,,
   LCPD-13445,P3-Medium,Seldom kernel oops triggered by prueth_netdev_init,Connectivity,,am654x-evm,,
   LCPD-13354,P3-Medium,PRU Ethernet ping fails with packet size > 4096 bytes,Connectivity,,"am654x-evm, am654x-idk",,
   LCPD-13330,P3-Medium,Uboot: usb storage device could not be found at second usb reset,Connectivity,,k2g-evm,,
   LCPD-12673,P3-Medium,Board refuses to suspend on setup with SATA device,Connectivity,,omapl138-lcdk,,
   LCPD-12470,P3-Medium,Analyze / fix klocwork warnings for TSCADC,Connectivity,ADC,,,
   LCPD-12469,P3-Medium,Analyze / fix klocwork warnings for QSPI,Connectivity,QSPI,,,
   LCPD-12467,P3-Medium,Analyze / fix klocwork warnings for SPI,Connectivity,SPI,,,
   LCPD-12466,P3-Medium,Analyze / fix klocwork warnings for UART,Connectivity,UART,,,
   LCPD-12463,P3-Medium,Analyze / fix klocwork warnings for PHY core,Connectivity,,,,
   LCPD-12462,P3-Medium,Analyze / fix klocwork warnings for PCIe,Connectivity,PCIE,,,
   LCPD-12392,P3-Medium,USBhost video: higher resolution tests fail with some cameras,Connectivity,,,,
   LCPD-12226,P3-Medium,mmcsd first write perf decreased on some platforms,Connectivity,,"am43xx-gpevm, am574x-idk, am57xx-evm, omapl138-lcdk",,
   LCPD-11564,P3-Medium,AM57xx-evm: eth1 1G connection failure to netgear switch,Connectivity,"CPSW, ETHERNET, PHYIF",am57xx-evm,,
   LCPD-10974,P3-Medium,am43xx-gpevm - usb camera gadget shows halting frames,Connectivity,USB,,,
   LCPD-10781,P3-Medium,NetCP module removal results in backtrace and kernel panic,Connectivity,NETCP,k2g-evm,,
   LCPD-10777,P3-Medium,mtd_stresstest failed on omapl138,Connectivity,NAND,omapl138-lcdk,,
   LCPD-10551,P3-Medium,"K2E eth0 does down when running udp traffic, eth1 stops working",Connectivity,NETCP,k2e-evm,,
   LCPD-10221,P3-Medium,Longer resume times observed on setup with usb device cable,Connectivity,USB,am335x-evm,,
   LCPD-9974,P3-Medium,PCIe x2 width is not at expected width on am571x-idk,Connectivity,PCIe,am571x-idk,,
   LCPD-9905,P3-Medium,AM437x: UART: Implement workaround for Advisory 27ÿ? Spurious UART interrupts when using EDMA,Connectivity,UART,am43xx-gpevm,,
   LCPD-9816,P3-Medium,USBdevice omapl138 - Flood ping from server to dut usbdevice at 65500 bytes has packet loss,Connectivity,USB,omapl138-lcdk,,
   LCPD-9815,P3-Medium,Failed to start Login Service when using debug systest build on omapl138,Connectivity,,omapl138-lcdk,,
   LCPD-9804,P3-Medium,SATA performance decreased by ~34% for read and ~54% for write compared to v2.6.33 kernel,Connectivity,SATA,omapl138-lcdk,,
   LCPD-9658,P3-Medium,OMAP-L138 LCDK: MUSB does not enumerate mouse connected to Keyboard hub,Connectivity,USB,omapl138-lcdk,,
   LCPD-9591,P3-Medium,CONNECTIVITY: USB NCM gadget ping with packet sizes > 10000 fails,Connectivity,,,,
   LCPD-9466,P3-Medium,SATA PMP causes suspend failures,Connectivity,SATA,"am57xx-evm",,
   LCPD-9455,P3-Medium,Kernel Warning reported for a USB audio device when listing with pulseaudio,Connectivity,USB,am335x-evm,,
   LCPD-9428,P3-Medium,Ethernet performace UDP: iperf command fails with two threads for lower buffer length,Connectivity,NETCP,"k2e-evm, k2hk-evm, k2l-evm",,
   LCPD-9372,P3-Medium,Nand stress tests failed on am335x-evm,Connectivity,NAND,am335x-evm,,
   LCPD-9366,P3-Medium,PCIe USB drive sometimes could not be enumerated,Connectivity,PCIe,k2g-evm,,
   LCPD-9011,P3-Medium,K2G-evm: usb devices do not enumerate behind a TUSB8041 usb3.0 hub,Connectivity,USB,,,
   LCPD-8984,P3-Medium,Kernel boot to initramfs with PA enabled results in no DHCP IP address assigned to network interfaces,Connectivity,NETCP,"k2e-evm, k2l-evm",,
   LCPD-8637,P3-Medium,K2HK: Long-term ping test fails due to ethernet link going down,Connectivity,,,,
   LCPD-8133,P3-Medium,"USB: ""cannot reset"" errors observed sometimes",Connectivity,USB,am335x-evm,,
   LCPD-8100,P3-Medium,CONNECTIVITY: K2G ethernet performance numbers are low,Connectivity,NETCP,k2g-evm,,
   LCPD-8078,P3-Medium,AM3 SK: Touchscreen isn't responsive,"Audio & Display, Connectivity",,am335x-sk,,
   LCPD-8033,P3-Medium,AM3 SK: Unexpected USB2-1 Messages on UART,Connectivity,USB,,,
   LCPD-7955,P3-Medium,Uncorrectable Bitflip errors seen after switch to SystemD,Connectivity,GPMC,"am335x-evm, am43xx-gpevm, k2e-evm, k2g-evm, k2g-ice, k2hk-evm, k2l-evm",Workaround to erase the NAND flash completely if flashed with an incompatible flash writer. SystemD tries to mount all partitions and that is the reason this is being seen now.,
   LCPD-7829,P3-Medium,uboot: UHS card did not work on the expected speed in uboot,Connectivity,,am57xx-evm,,
   LCPD-7744,P3-Medium,UHS SDR104 card works on different speed after soft reboot,Connectivity,,am57xx-evm,,
   LCPD-7623,P3-Medium,Seeing SPI transfer failed error sometimes on k2hk when using rt kernel,Connectivity,SPI,k2hk-evm,,
   LCPD-7559,P3-Medium,K2E/K2HK does not enumerate usb3 devices through usb3.0 hub,Connectivity,USB,"k2e-evm, k2hk-evm",,
   LCPD-7265,P3-Medium,Uboot eMMC does not use HS200 on am57xx-gpevm,Connectivity,,am57xx-evm,,
   LCPD-6334,P3-Medium,k2g-evm: NAND is untestable due to data corruption issues,Connectivity,,k2g-evm,,
   LCPD-6300,P3-Medium,am57xx-evm: A few UHS cards could not be numerated in kernel and mmc as rootfs failed.,Connectivity,,am57xx-evm,,
   LCPD-5699,P3-Medium,pci: am572x-idk: pci broadcom card doesn't enumerate,Connectivity,,"AM571x, AM572x",,
   LCPD-5677,P3-Medium,K2E-evm: Marvel SATA controller could not be detected sometimes when Power On Reset is involved,Connectivity,,K2E,,
   LCPD-5522,P3-Medium,pcie-usb sometimes the usb drive/stick could not be enumerated,Connectivity,,"am571x-idk, am572x-idk, am57xx-evm",,
   LCPD-5362,P3-Medium,MUSB: Isoch IN only utilises 50% bandwidth,Connectivity,USB,AM335x,,
   LCPD-4849,P3-Medium,K2hk: Connectivity: UART data corruption observed sometimes in loopback mode,Connectivity,,,,
   LCPD-4503,P3-Medium,ALL: 8250 UART driver not enabeld as wake source by default,Connectivity,UART,,,
   LCPD-1239,P3-Medium,J6: Connectivity: J6 could not resume when PCI-SATA card is in,Connectivity,PCIe,"am572x-idk, am57xx-evm",,
   LCPD-1198,P3-Medium,"am43xx-gpevm:Connectivity: when kmemleak debug is enabled and mmc stress test is run, OOM killer is seen to kick in. Does not happen without kernel debug.",Connectivity,,,,
   LCPD-1144,P3-Medium,Logitech USB-PS/2 Optical Mouse cannot be detected every other time the system is suspended/resumed (AM335x-EVM),Connectivity,,,,
   LCPD-1106,P3-Medium,Connectivity:PCIe-SATA ext2 1G write performance is poor due to ata failed command,Connectivity,PCIe,"am57xx-evm",,
   LCPD-932,P3-Medium,AM33X: CONNECTIVITY: MUSB MSC read numbers are lower in 3.14 compared to 3.12,Connectivity,USB,,,
   LCPD-869,P3-Medium,AM335x: Connectivity: USB data transfer fails if board is suspended/resumed,Connectivity,,,,
   LCPD-816,P3-Medium,J6/J6eco:Connectivity:PCIe-PCI eth bridge doesn't work on J6/J6eco,Connectivity,PCIe,,,
   LCPD-662,P3-Medium,CONNECTIVITY: AM335X: distortion in USB audio when msc connect/disconnect happens in parallel,Connectivity,,,,
   LCPD-14460,P3-Medium,am654x-idk failed to boot to kernel prompt occasionally,Baseport,,am654x-idk,,
   LCPD-14455,P3-Medium,UDMA glue layer: Double of_node_put can generate callback dump,"Audio & Display, Baseport",UDMA,"am654x-evm, am654x-idk",,
   LCPD-14191,P3-Medium,IPSec hardware-based throughput is 30% lower than 2018.03,Baseport,,"am335x-evm, am57xx-evm",,
   LCPD-13726,P3-Medium,"Error: ""NOHZ: local_softirq_pending""",Baseport,,"am335x-evm, am335x-ice, am335x-sk, am437x-idk, am437x-sk, am43xx-epos, am43xx-gpevm, am571x-idk, am572x-idk, am574x-idk, am57xx-evm, beaglebone, beaglebone-black",,
   LCPD-13410,P3-Medium,Reboot command is not operational,Baseport,,"am654x-evm, am654x-idk",,
   LCPD-11546,P3-Medium,Rare kernel crash triggered by task_blocks_on_rt_mutex,Baseport,,"am574x-idk, k2e-evm",,
   LCPD-9981,P3-Medium,Some LTP's memory management tests fail due to low amount of free memory,Baseport,,"omapl138-lcdk",,
   LCPD-9980,P3-Medium,LTP's math tests float_exp_log and float_trigo fail due to OOM,Baseport,,omapl138-lcdk,,
   LCPD-9756,P3-Medium,"pm_runtime does not kicks in for some IPs (serial, gpio and wdt)",Baseport,,omapl138-lcdk,,
   LCPD-8640,P3-Medium,Crypto performance for AES drops 3-10% in 2016.05,Baseport,,,,
   LCPD-8550,P3-Medium,CPSW memory allocation errors seen during boot,"Audio & Display, Baseport",,am335x-sk,,
   LCPD-8406,P3-Medium,K2G: PADCONFIG_202 register cannot be re-programmed,Baseport,,"k2g-evm, k2g-ice",This has proven to be a silicon issue related to locking RSTMUX. It is currently being discussed if it will be fixed in a newer silicon revision. Currently to avoid this issue the affected pins pinmux are not changed in the kernel. This is because U-boot locks RSTMUX which causes problems if the kernel tries to change the pinmuxing for the pins.,
   LCPD-8350,P3-Medium,UART boot does not work on am57xx-evm,Baseport,,am57xx-evm,,
   LCPD-8347,P3-Medium,BUG: sleeping function called from invalid context triggered by keystone_pcie_fault,Baseport,,"k2e-evm, k2g-evm",,
   LCPD-8257,P3-Medium,Boot failed 1 of 1000 times on k2g,Baseport,,k2g-evm,,
   LCPD-7486,P3-Medium,uboot debug with ccs is failing for K2,Baseport,,k2hk-evm,,
   LCPD-6998,P3-Medium,K2G sometimes boot failed with kernel oops error,Baseport,,k2g-evm,,
   LCPD-6663,P3-Medium,[RT] Kmemleak is buggy and boot is crashed randomly,Baseport,,,,
   LCPD-14449,P3-Medium,am574x-idk: Observed unwanted failure message in test log,Audio & Display,,am574x-idk,,
   LCPD-13956,P3-Medium,Graphics stack crash after HDMI hot un-plug,Audio & Display,,"am571x-idk, am574x-idk, am57xx-evm",,
   LCPD-12680,P3-Medium,Seeing i2c timeout error and board failed to boot,Audio & Display,,k2g-evm,,
   LCPD-12511,P3-Medium,Audio record is not working,Audio & Display,Audio,am57xx-evm,,
   LCPD-11138,P3-Medium,VIP driver multi-channel capture issue with TVP5158,Audio & Display,"Capture, VIP","am571x-idk, am572x-idk, am574x-idk, am57xx-evm",,
   LCPD-7735,P3-Medium,Powerdomain (vpe_pwrdm) didn't enter target state 0,"Audio & Display, Power & Thermal",,"am57xx-evm",,
   LCPD-7696,P3-Medium,VPE: File2File checksum changes across multiple runs,Audio & Display,,"am571x-idk, am572x-idk, am57xx-evm",There is no workaround for this issue yet,"No visual artifacts, but checksum on initial frame differs as couple of bytes are incorrect"
   LCPD-7693,P3-Medium,VIP: OV1063x: Video artifacts in LVDS cameras,Audio & Display,Capture,,,
   LCPD-5380,P3-Medium,omapdss error: HDMI I2C Master Error,Audio & Display,,AM572x,Occurs only with this monitor -ÿhttp://www.amazon.com/gp/product/B00PFLZV2G,
   LCPD-1191,P4-Low,AM335x: Power: System resumes due to wakeup source USB1_PHY without any external trigger,Power & Thermal,,,Use GPIO interrupt instead of USB PHY for wakeup source.,
   LCPD-1013,P4-Low,AM335x: Power: Seldom short-duration power increase (~38mw) in VDDSHV4 domain,Power & Thermal,,,,
   LCPD-10455,P4-Low,remoteproc/keystone: Hang observed while running RPMSG_PROTO example app,IPC,DSP_remoteproc,"k2g-evm, k2g-ice, k2hk-evm, k2l-evm",,
   LCPD-9801,P4-Low,remoteproc/davinci: DSP boot is broken after a suspend/resume cycle,IPC,DSP_remoteproc,omapl138-lcdk,,
   LCPD-9481,P4-Low,Sometime the system hangs while loading the rpmsg rpc modules,IPC,RPMSG-RPC,"am571x-idk, am572x-idk, am57xx-evm",,
   LCPD-7495,P4-Low,Sometimes a Kernel Warning + Oops is seen when removing keystone_remoteproc module,IPC,,k2hk-evm,,
   LCPD-4855,P4-Low,[rpmsg 2015 LTS] J6Eco: IPC: Board hangs when an MMU fault occurs in the first message,IPC,,"am572x-idk",,
   LCPD-4699,P4-Low,rpmsg-rpc: kernel crash during error recovery with dynamic debug traces enabled,IPC,,"am571x-idk, am572x-idk, am57xx-evm",,
   LCPD-13794,P4-Low,Usb stick could not be detected in Uboot at the second time on k2g-evm,Connectivity,,k2g-evm,,
   LCPD-12783,P4-Low,Missing instruction for pcie-ep config on k2g-evm for 4.14 kernel,Connectivity,,k2g-evm,,
   LCPD-11570,P4-Low,Base ubi filesystem could not be mounted as ubifs on k2g-evm,Connectivity,,k2g-evm,,
   LCPD-9589,P4-Low,I2C: Sometimes i2c read write failed on farm01 and farm02,Connectivity,,am335x-evm,,
   LCPD-9222,P4-Low,PRUSS Ethernet does not work on AM572x ES1.1,Connectivity,PRUSS-Ethernet,am572x-idk,,
   LCPD-8636,P4-Low,Serial corruption being seen in kernel,Connectivity,UART,"am335x-evm",,
   LCPD-8477,P4-Low,K2: serdes nodes doesn't have a functional clock,Connectivity,SERDES,"k2e-evm, k2g-evm, k2g-ice, k2hk-evm, k2l-evm",,
   LCPD-8270,P4-Low,K2: SerDes driver need to enable PD of the peripheral before access the SerDes h/w,Connectivity,SERDES,k2g-evm,,
   LCPD-7998,P4-Low,Realtime OSADL Test results degraded slightly for am572x-idk,Connectivity,,am572x-idk,,
   LCPD-7903,P4-Low,Uboot phy startup failed and dhcp failed occasionally on k2 board,Connectivity,,"k2g-evm, k2hk-evm",,
   LCPD-7480,P4-Low,K2L/E EVMs doesn't boot to Linux when both 1G Ethernet interfaces are connected,Connectivity,,"k2e-evm, k2l-evm",,
   LCPD-7188,P4-Low,PCIe-SATA test failed,Connectivity,,"am57xx-evm",TI custom board would help with signal integrity issues being seen with the EVM.,
   LCPD-1207,P4-Low,AM43XX/AM57XX: CONNECTIVITY: dwc3_omap on am43xx and xhci_plat_hcd on dra7 - removal results in segmentation fault,Connectivity,USB,,,
   LCPD-998,P4-Low,MUSB does not free urbs causing usb audio playback to fail,Connectivity,,AM335x,,
   LCPD-727,P4-Low,J6:Connectivity:SATA readwrite tests sometimes fail and dut hangs with cpuidle enabled,Connectivity,,,,
   LCPD-671,P4-Low,AM33XX: CONNECTIVITY: MUSB in PIO mode - video issues,Connectivity,,,,
   LCPD-525,P4-Low,AM438x: Connectivity: I2C operates 9% beyond desired frequency,Connectivity,,,,
   LCPD-10223,P4-Low,Keystone-2 Linking RAM region 0 size register REGION0_SIZE programming,Baseport,,k2hk-evm,,
   LCPD-6075,P4-Low,BUG: using smp_processor_id() in preemptible [00000000] code during remoteproc suspend/resume,"Baseport, IPC",,"am572x-idk, am57xx-evm",,
   LCPD-14311,P4-Low,tidss missing from libdrm's list of drm modules,Audio & Display,Display,"am654x-evm, am654x-idk",,
   LCPD-9098,P4-Low,Writeback: error prints seen when doing wb capture,Audio & Display,"Capture, Display, Writeback","am571x-idk, am572x-idk, am57xx-evm",,
   LCPD-8884,P4-Low,VIP does not work after incorrectly configuring captured YUYV frame as NV12,Audio & Display,"Capture, VIP",,,
   LCPD-6377,P4-Low,OMAP_BO_CACHED feature not functional,"Audio & Display, Multimedia",Display,"am437x-idk, am437x-sk, am43xx-gpevm, am571x-idk, am572x-idk, am57xx-evm, k2g-evm",,
   LCPD-5059,P4-Low,omapdrm: moving plane from one enabled display to another causes errors,Audio & Display,Display,,,
   LCPD-4681,P4-Low,omapdrm: an error when enabling a display is not handled correctly,Audio & Display,Display,,,
   LCPD-1171,P4-Low,DRA7: DMM errata i878 (framebuffer part),Audio & Display,"Display, TILER","am571x-idk, am572x-idk, am57xx-evm",,

|

RT Linux Kernel Known Issues
-----------------------------

.. csv-table::
   :header: "Record ID", "Priority", "Title", "Component", "Platform", "Workaround"
   :widths: 5, 10, 70, 10, 20, 15

   LCPD-6663 ,P3-Medium ,[RT] Kmemleak is buggy and boot is crashed randomly ,Baseport ,  ,
   LCPD-7623 ,P3-Medium ,Seeing SPI transfer failed error sometimes on k2hk when using rt kernel ,Connectivity ,k2hk-evm ,
   LCPD-11546 ,P3-Medium ,Rare kernel crash triggered by task_blocks_on_rt_mutex ,Baseport ,"am574x-idk, k2e-evm ",
   LCPD-11568 ,P3-Medium ,dhcp failed to get IP address after reboot for K2G-ICE non-RT linux ,Baseport  ,"k2g-ice ",
   LCPD-13766 ,P2-High ,am654x: RT latency numbers are 60 us versus ~25 in am574x ,Connectivity	,am654x-idk ,
     
|


.. rubric:: Installation and Usage
   :name: installation-and-usage

The `Software Developer's Guide <index.html>`__ provides instructions on how to setup up your Linux development
environment, install the SDK and start your development.  It also includes User's Guides for various Example Applications and Code
Composer Studio.

| 

.. rubric:: Host Support
   :name: host-support

The Processor SDK is developed, built and verified on Ubuntu 14.04, 16.04 and 18.04. Details on how to create a virtual machine to load Ubuntu 14.04
are described in `this page <How_to_Guides_Host.html#how-to-build-a-ubuntu-linux-host-under-vmware>`__.


.. note::
   Processor SDK Installer is 64-bit, and installs only on 64-bit host
   machine. Support for 32-bit host is dropped as Linaro toolchain is
   available only for 64-bit machines

| 

