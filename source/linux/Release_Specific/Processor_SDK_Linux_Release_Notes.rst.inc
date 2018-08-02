************************************
Processor SDK Linux Release Notes
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
-  Code Composer Studio v7

Licensing
=========

Please refer to the software manifest, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page. The manifest can be found on the SDK
download page or in the installed directory as indicated below. In
addition, see :ref:`PLSDK-GPLv3-Disclaimer-label`

Documentation
===============
-  :ref:`processor-sdk-linux-software-developers-guide`: Provides information on features, functions, delivery package and,
   compile tools for the Processor SDK Linux release. This also provides
   detailed information regarding software elements and software
   infrastructure to allow developers to start creating applications.
-  :ref:`processor-sdk-linux-getting-started-guide`: Provides information on getting the software and running
   examples/demonstrations bundled in the SDK.
-  **Software Manifest**: Provides license information on software
   included in the SDK release. This document is in the release at
   ``[INSTALL-DIR]/docs``.
-  **EVM Quick Start Guide**: Provides information on hardware setup and
   running the demonstration application that is loaded on flash. This
   document is provided as part of the EVM kit.

Release 05.00.00 Highlights
============================

Released Jul 2018

.. rubric:: What's New
   :name: whats-new

- 2018 LTS Update: First release in 2018 LTS (Kernel 4.14, U-boot: 2018.01, gcc: 7.2-2017.11, Yocto 2.4 (rocko). For more details, see the `migration guide <Release_Specific.html#processor-sdk-05-00>`__
- AM57x: Enable Deep Learning at the edge using TI-DL that leverages TI’s proprietary, highly optimized CNN/DNN implementation on the EVE and C66x DSP compute engines. Please see `here <Foundational_Components_TIDL.html>`__ for more details
- AM57x: PTP: Support Ordinary Clock (OC) Master/Slave with HSR redundancy on PRU-ICSS
- AM57x: PTP: Support Hybrid Clock (HC), i.e. Transparent Clock (TC) + Ordinary Clock (OC) in HSR mode
- AM57x: HSR/PRP: Add `Broadcast Storm Prevention <Industrial_Protocols_HSR_PRP.html#broadcast-storm-prevention>`__
- AM57x: HSR/PRP: Improve throughput at smaller packet sizes, details `here <Industrial_Protocols_HSR_PRP.html#receive-interrupt-pacing>`__
- AM437x, AM57x: Implement Simple Open Real-Time Ethernet (SORTE) with Linux. Please see `here <Industrial_Protocols_SORTE.html>`__ for more details

.. rubric:: SDK Components & Versions
   :name: sdk-components-versions

+--------------------------+----------------------------+
| Component                | Version                    |
+==========================+============================+
| Linux Kernel             | 4.14.40+ (2018 LTS)        |
+--------------------------+----------------------------+
| U-Boot                   | 2018.01                    |
+--------------------------+----------------------------+
| Yocto Project            | 2.4 (rocko)                |
+--------------------------+----------------------------+
| Linaro Toolchain (gcc)   | 7.2-2017.11 hard-float     |
+--------------------------+----------------------------+
| Qt                       | 5.9.6                      |
+--------------------------+----------------------------+
| OpenCL                   | 1.1.15                     |
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
See :ref:`SDK-Supported-Platforms` for a list of supported platforms and links to more information.

|


Build Information
=====================================

U-Boot
-------------------------

| Head Commit: 131dc8283021742f03e843e216ed301862e2db38 configs: dra7xx_evm/dra7xx_hs_evm: Enable AHCI and PIPE3 
| Date: Wed Jun 13 12:48:25 CDT 2018
| uBoot Version: 2018.01
| uBoot Description: v2018.01-227-g131dc82
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2018.01
| uBoot Tag: ti2018.01

|

Kernel
-------------------------

.. rubric:: Linux Kernel
   :name: linux-kernel

| The kernel git repository, branch and commit id can be found below:
| Based on Version: 4.14.40
| URL: git://git.ti.com/processor-sdk/processor-sdk-linux.git
| Branch: processor-sdk-linux-4.14.y
| Commit ID: 4796173fc58688055a99a1cef19a839174067220

|

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| The RT kernel git repository, branch and commit id can be found below:
| Based on:
| Kernel Version: 4.14.40
| RT Kernel Version: 4.9.40-rt29

| URL: git://git.ti.com/processor-sdk/processor-sdk-linux.git
| Branch: processor-sdk-linux-4.14.y
| Commit ID: d5443cbd3b5a79c7b4f817896e12014f2b30e34b

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

    LCPD-7519,am335x-evm,dfu_get_buf return error when use dfu to update mmc card
    LCPD-9436,"am571x-idk, am572x-idk, am57xx-evm",DRM: plane zorders must be unique
    LCPD-12131,,Perl in linux-devkit isn't relocatable
    LCPD-12186,"am335x-evm, am335x-sk, beaglebone, beaglebone-black","MMC/SD0 (SD card) pins are not muxed correctly for AM335x EVM, SK and Bone"
    LCPD-12212,,ti-sgx-ddk-km: implicit fallthrough error in gcc7
    LCPD-12279,am335x-evm,Uboot: usb ethernet doesn't work in U-boot
    LCPD-12283,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15",ti-cpufreq: backport couple of upstream fixes
    LCPD-12311,"am571x-idk, am572x-idk",Board could not boot to kernel when one Inateck pci-usb card is in
    LCPD-12347,,edma: Fix Klocwork reported issue
    LCPD-12353,,Two files with the same name MLO appear in the SD card
    LCPD-12377,am335x-ice,am335x-ice - Builds should be updated with dtb for prueth support
    LCPD-12378,am574x-idk,VIP is not being enumerated as a v4l2 device
    LCPD-12381,,WLAN disabled to allow suspend/standby to work
    PLSDK-881,"am335x-evm, am437x-evm, am572x-evm, k2g-evm, k2h-evm, k2e-evm, k2l-evm","Linux: Toplevel make gets warnings from dhry_1,linpack and loopback for AM and K2 (rt and non rt) platforms"
    PLSDK-1842,,CMEM misses some multi-thread protection
    PLSDK-1815,"am335x-evm, am437x-evm, am572x-evm",DNS should be operational using binaries
    PLSDK-1891,am335x-evm,QT Wayland compositor with SGX on AM335x Processor SDK
    PLSDK-1939,am571x-idk,A-B forwarding with wrong/no FCS in HSR mode
    PLSDK-1940,am571x-idk,Unexpected offset jump in PTP
    PLSDK-1941,am571x-idk,PTP: Overshoot state reported
    PLSDK-1944,,GPIO Test fails on AM572/4-idk
    PLSDK-1957,"am571x-idk, am572x-idk",PPS offset of CPTS is big and jumping
    PLSDK-1960,am438x-epos-evm,Top level make failed on am438 epos
    PLSDK-1975,,"Download page has incorrect ""Back to Software Product Overview"" link"
    PLSDK-2070,,HSR/PRP: Maintain a MTU of 1500 for all cases (with or without VLAN)
    PLSDK-2080,,GPIO control of the CPTS reference PPS signal is low-active
    PLSDK-2083,,CPTS 1PPS reference signal should be optional
    PLSDK-2097,am572x-evm,"High level build of big-data-ipc-demo & ti-ipc-linux failed in PSDK 4.3 release, but works in 4.2"
    PLSDK-2101,"am335x-ice, am437x-idk",icss-emac unit test icev2AM335x/idkAM437x: test hangs after transmitting one packet
    PLSDK-2149,,ARM multimedia tests and 3D demos failed on AM3 HS evms
    PLSDK-2150,"am438x-epos-evm, am437x-hsevm",ARM multimedia tests failed on AM4 HS and EPOS evms
    PLSDK-2168,"am571x-idk, am572x-idk, am572x-evm, am572x-hsevm",Matrix-GUI needs 2-3 minutes to come up after boot

|


Issued found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 20, 70

    LCPD-12422,am571x-idk,davinci_mdio 48485000.mdio: timed out waiting for idle? seen in bootlog
    LCPD-12435,am43xx-gpevm,V3_3D domain consumes ~4mw higher during suspend & standby states
    LCPD-12456,,Analyze / fix klocwork warnings for DWC3 / UDC
    LCPD-12461,,Analyze / fix klocwork warnings for GPMC
    LCPD-12465,,Analyze / fix klocwork warnings for PRUETH
    LCPD-12474,am43xx-gpevm,am437x-gp-evm: Remove duplicate uart0 and uart0_pins_default nodes
    LCPD-12535,omapl138-lcdk,Top level Make fails on Omapl138 due to fatal error
    LCPD-12633,am57xx-evm,PCIe sata could not be enumerated
    LCPD-12634,am57xx-evm,PCIe wifi: no network interface being created even it is detected
    LCPD-12665,k2g-evm,CAN interface is missing in k2g
    LCPD-12690,am335x-evm,Newer releases of SDK u-boot load kernel slower
    LCPD-12693,k2g-evm,PCIe support is not in so all pcie tests failed on k2g-evm
    LCPD-12733,,ethtool -k eth0 gives an error message

| 

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
   :header: "Record ID",  "Title"
   :widths: 15, 80

    LCPD-876,OMAP5: Errata i810: DPLL Controller Sticks when left clock requests are removed
    LCPD-975,J6/J6eco: 32clk is psuedo (erratum i856) - realtime counter
    LCPD-976,J6/J6eco: 32clk is psuedo (erratum i856) - clock source
    LCPD-1022,J6: Errata: i694: System I2C hang due to miss of Bus Clear support @ OMAP level
    LCPD-1087,J6: MMC: Errata: i802: OMAP5430 MMCHS: DCRC errors during tuning procedure
    LCPD-1108,J6: Wrong Access In 1D Burst For YUV4:2:0-NV12 Format (Errata i631)
    LCPD-1146,DMM hang: Errata VAYU-BUG02976 (i878) (register part)
    LCPD-1776,"[J6 SATA Adaptation] J6 - Errata i783, SATA Lockup After SATA DPLL Unlock/Relock"
    LCPD-4184,Implement workaround for errata i814 - Bandgap Temperature read Dtemp can be corrupted
    LCPD-4217,Implement Workaround for Errata i814 - Bandgap Temperature read Dtemp can be corrupted
    LCPD-4218,Implement Workaround for Errata i813 - Spurious Thermal Alert Generation When Temperature Remains in Expected Range
    LCPD-4647,[rpmsg 2015 LTS] Implement errata i879 - DSP MStandby requires CD_EMU in SW_WKUP
    LCPD-4648,[rpmsg 2014 LTS] Implement errata i879 - DSP MStandby requires CD_EMU in SW_WKUP
    LCPD-4910,J6/OMAP5: errata i810 implementation
    LCPD-4975,DSS AM5/DRA7: implement WA for errata i886
    LCPD-5052,Upstream: Post the dmtimer errata fix for i874
    LCPD-5309,LCPD: i896: USB Port disable doesnt work
    LCPD-5310,"i900: CTRL_CORE_MMR_LOCK_5 region after locking results in ctrl module inaccessible, recoverable only post a reset"
    LCPD-5311,i893: DCAN ram init issues in HW AUTO and when traffic hitting CAN bus (open investigation)
    LCPD-5460,Implement WA for Vayu errata i829 (Reusing Pipe Connected To Writeback Pipeline On The Fly To An Active Panel)
    LCPD-5836,CAL: Errata: i913: CSI2 LDO needs to be disabled when module is powered on
    LCPD-5924,ALL: CONNECTIVITY: CPSW: errata i877 workarround for cpsw
    LCPD-6907,Workaround errata i880 for RGMII2 is missing
    LCPD-7642,MMC/SD: i832: return DLL to default reset state with CLK gated if not in SDR104/HS200 mode.
    LCPD-8277,u-boot: j6: SATA is not shutdown correctly as per errata i818
    LCPD-8294,37 pins + VOUT pins need slow slew enabled for timing and reliability respectively
    LCPD-9084,i887: Software workaround to limit mmc3 speed to 64MHz
    LCPD-9173,i897: USB Stop Endpoint doesnt work in certain circumstances

| 

SDK Known Issues
-----------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 25, 30, 50, 60

   LCPD-5578,,Exception triggered by graphics driver during boot if board does not have SGX (BBB A4),"Build Processor SDK without SGX following instructions `here <Overview.html#rebuilding-without-sgx>`__"
   LCPD-7025,am43xx-gpevm,System takes more than 10 seconds to go from login prompt to system prompt,Automated tests need to account for this boot delay
   LCPD-8345,"am335x-evm, am437x-idk, k2e-evm, k2e-hsevm, k2hk-evm, k2l-evm","Board fails to start login console after waiting 3.5 minutes ( hard to reproduce, ~4/1000)",Restart the EVM
   LCPD-8352,"am43xx-gpevm, am57xx-evm",weston: stress testing with 75 concurrent instances of simple-egl leads to unresponsive HMI due to running out of memory,1. Restart Wayland application. 2. Restart board if Weston is killed by oom-killer
   LCPD-9006,am57xx-evm,Some GLBenchmark tests fail to run,"This is a limitation with Imagination DDK, and no workaround"
   LCPD-9616,am57xx-evm,QtCreator GDB (remote) debugging stops working since QT5.7.1,use GDB from Processor SDK 3.2
   LCPD-11010,am574x-idk,AM574x-idk graphics performance is lower than am572x-idk,"Performance issue, no workaround"
   LCPD-11549,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm","Error message with multiple egl, not shared context","Limitation with Imagination DDK, no workaround"
   LCPD-12679,am574x-idk,PVR_K: dmabuf error during video playback,
   LCPD-12778,am335x-evm,Board hangs in standby & suspend state when wl12x card is attached,
   LCPD-12784,omapl138-lcdk,Board can't resume from suspend state sometimes, None
   PLSDK-832,AM57,OpenCL matmpy intermittent DSP1 crash due to EdmaMgr issues w/ suspend/resume,"Disabling suspend/resume on the DSPs prevents this intermittent failure: *echo on > /sys/bus/platform/devices/40800000.dsp/power/control; echo on > /sys/bus/platform/devices/41000000.dsp/power/control*"
   PLSDK-885,AM57,OpenCV Video test failure w/ GStreamer errors,Use the workaround from    PLSDK-832
   PLSDK-1266,am572x-idk,PRP: stale IGMP packets (IPv6) seems directly sent to eth2/eth3 of a HRP node,None
   PLSDK-1308,am572x-idk,PRP: PRP node is shown as SAN at times in the node table dump when not offloaded,"No problem with offload, which is default"
   PLSDK-1398,"k2g-hsevm, k2hk-hsevm, k2e-evm, k2e-hsevm",Document workaround for IPC demo hangs if run after OpenCL demos,Run IPC demo w/o running OpenCL first
   PLSDK-1419,k2l-evm,Intermittent-IP address display issue on LCD for K2L RT,"Use ifconfig once Linux boots, to acquire IP address"
   PLSDK-1556,"k2hk-evm, k2hk-hsevm, k2e-evm, k2l-evm",SA LLD: saBasicExample test shows warning as 'Alignment trap' on K2x platforms.,Just a warning message. No impact to test output
   PLSDK-1602,am437x-evm,"Simple people tracking demo: Bulk transfer failed, observed inconsistent behavior of the application",None
   PLSDK-1693,am572x-evm,"It takes long time to use ""kill pid"" to close matrix-browser","Start and stop Matrix GUI using /etc/init.d/matrix start, and /etc/init.d/matrix stop, respectively"
   PLSDK-1707,"am571x-idk, am572x-idk",prueth: debugfs_create_dir() fails during boot and error message shown,"Only impact the debug stats display. No other functionality affected. Once user login to root, user may do ifconfig or ifup to bring up the interface"
   PLSDK-1720,am437x-evm,Simple people tracking demo: Tracking Incorrect Number of People,None
   PLSDK-1814,am572x-evm,Camera support is not available from the default dtbs ,"Use am57xx-evm*-cam-mt9t111.dtb for mt9t111 camera, and am57xx-evm*-cam-ov10635.dtb for ov10635 camera"
   PLSDK-1817,,"HSR/PRP: Outstanding Net-Jury tests failures: 92/105 passed, 7 blocked and 6 failed",None
   PLSDK-1828,"am571x-idk, am572x-idk","HSR: In a ring topology, seeing small performance degradation with concurrent traffic",None
   PLSDK-1909,am572x-evm,DLP SDK demo: Assertion `ctx->pollfds_cnt >= internal_nfds' failed,None
   PLSDK-1922,"k2hk-hsevm, k2e-evm, k2e-hsevm, k2l-evm",K2: PA and NWAL are not supported in PLSDK 5.0,None
   PLSDK-1924,"am335x-ice, am335x-sk, beagleboneblack",AM3: Observed unwanted failure message in boot log.,None
   PLSDK-1945,am572x-evm,qApp->quit() does not work with the enhanced eglfs_kms QPA,None
   PLSDK-1953,"am571x-idk, am572x-idk",Linux PRP: lreTransparentReception - passRCT doesn't work as expected,None
   PLSDK-1963,k2e-evm,K2E:Observed unwanted failure messages in boot log,"No functionality affected except the log message. If not needed, do not connect anything to the PCIe slot."
   PLSDK-2067,am571x-idk,Transparent Clock crashes after a couple of days due to memory leak,
   PLSDK-2095,"am571x-idk, am572x-idk","kernel: EXPORT symbol ""__hyp_stub_vectors seen during kernel build",
   PLSDK-2107,k2g-ice,sorte for K2G: master is not working,None
   PLSDK-2109,"am437x-evm, am572x-evm",QtWebengine demobrowser shows problems at LTS2018 on EGLFS QPA,None
   PLSDK-2113,"am571x-idk, am572x-idk",PTP BC overshoot caused by cable unplug and plug back in,
   PLSDK-2128,"am335x-evm, am437x-evm, am438x-epos-evm, am572x-evm",Weston 2.0: overlay window display issue,"None. For Wayland demo, you may use qwindow-compositor instead of Weston."
   PLSDK-2171,"am571x-idk, am572x-idk",PRU HSR firmware: small degradation in performance seen for MTU sized frames,None
   PLSDK-2174,"am335x-evm, am335x-hsevm, am335x-ice, am335x-sk, beagleboneblack, am437x-idk, am437x-sk, am437x-evm, am438x-epos-evm, am437x-hsevm, am570x-evm, am571x-idk, am572x-idk, am572x-evm, am572x-hsevm, am574x-idk, am574x-hsidk","boot stuck on ""please wait"" display screen when no input device is connected","Connect an input device (e.g., mouse, keyboard) when booting the EVM"
   PLSDK-2178,am335x-ice,ICSS EMAC intermittent error in received acyclic packet content,None
   PLSDK-2181,k2g-ice,k2g-ice Eth0 IP address not displayed,
   PLSDK-2186,am572x-evm,video-analytic-demo should run on top of Weston instead of qwindow-compistor,"Run the deom on top of qwindow-compositor, as available from Matrix GUI"
   PLSDK-2188,"am335x-evm, am572x-evm",Failure to load ftdi_sio kernel module,None
   PLSDK-2190,am571x-idk,Matrix Launcher: Independent_Video_with_QT_widgets_to_Different_Displays failing on am571-idk-rt platform,Intermittent issue
   PLSDK-2192,am572x-evm,Using OpenVX image causing kernel crash or hang during boot up,Switch back to OpenCL firmware after completing the OpenVX testing: reload-dsp-fw.sh opencl
   PLSDK-2194,"am437x-evm, am572x-evm",QtWebengine demobrowser crashes during window resize operations at LTS2018,None
   PLSDK-2198,"k2g-ice, k2g-evm",Multimedia: ERROR: from element /GstPipeline:pipeline0/GSTQTMux: qtmux0: Could not multiplex stream,None
   PLSDK-2220,k2e-evm,UBI Image for K2E exceeds the available size limit,None
   PLSDK-2228,am572x-evm,AM572x GP EVM: Unable to boot with jailhouse dtb,Apply patch here
   PLSDK-2229,am572x-idk,Jailhouse ethercat slave failed to reach Operational state with SOEM master on am572-idk rt,
   PLSDK-2234,am571x-idk,3BC Jitter exceeds specification,None

| 

U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID", "Priority", "Title", "Platform", "Workaround"
   :widths: 15, 10, 70, 30, 5

    LCPD-12244,P3-Medium,AM43xx u-boot needs to support PHY_INVERT_CLKOUT=1,"am437x-idk, am437x-sk, am43xx-epos, am43xx-gpevm",
    LCPD-12176,P3-Medium,U-boot: Fix IOdelay error path issue,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm",
    LCPD-11586,P3-Medium,dhcp failed to get IP address after reboot for K2G-ICE non-RT linux,k2g-ice,
    LCPD-10805,P3-Medium,U-Boot: Fix uart boot on am335x-evm,am335x-evm,
    LCPD-10726,P3-Medium,Update DDR3 emif regs structure for EMIF2 for the beagle_x15 board in U-Boot board file,"am572x-idk, am57xx-evm",
    LCPD-9369,P3-Medium,AM437x GP EVM older PG version Uboot UART boot fails intermittently,,
    LCPD-8701,P3-Medium,Soft reboot broken,k2g-ice,
    LCPD-5416,P3-Medium,"U-BOOT: K2G: ""reset"" fails for certain SD cards",K2G,
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
   :header: "Record ID", "Priority", "Title", "Component", "Subcomponent", "Platform", "Workaround"
   :widths: 5, 10, 70, 10, 5, 20, 35

    LCPD--12784,P2-High,Board can't resume from suspend state sometimes,Power & Thermal,,omapl138-lcdk,
    LCPD--9877,P2-High,rtc alarm does not wakeup board from poweroff state,Power & Thermal,,omapl138-lcdk,
    LCPD--12734,P2-High,K2G: Ethernet performance is low,Connectivity,,k2g-evm,
    LCPD--9972,P2-High,Soft reboot failed on k2g-evm with class 10 SD cards,Connectivity,,k2g-evm,
    LCPD--12513,P2-High,Android O: Board takes longer to boot compared to MM,Baseport,,am57xx-evm,
    LCPD--11577,P3-Medium,IPC: Protocol and MessageQ Recovery tests failed,"IPC, System Test",,am57xx-evm,
    LCPD--12781,P3-Medium,ipu opencl-monitor causes suspend failures,"IPC, System Integration",,am57xx-evm,
    LCPD--12933,P3-Medium,Board fails to resume from standby/suspend state via UART sometimes,Power & Thermal,,,
    LCPD--9527,P3-Medium,Potential deadlock reported by pm_suspend on am335x,Power & Thermal,,"am335x-evm, am335x-sk, beaglebone, beaglebone-black",
    LCPD--7670,P3-Medium,AM43xx: pm debug counters are wrong,Power & Thermal,,"am437x-idk, am437x-sk",
    LCPD--7314,P3-Medium,Active power is slighly higher than on 2015 LTS release (Linux 4.1),Power & Thermal,,am335x-evm,
    LCPD--7256,P3-Medium,Board sometimes hangs after suspend/resume cycle,Power & Thermal,,am57xx-evm,
    LCPD--6427,P3-Medium,vpe fails to suspend sometimes,Power & Thermal,,"am571x-idk, am572x-idk, am57xx-evm",
    LCPD--1245,P3-Medium,AM335x: Power: Reverse current leakage on poweroff,Power & Thermal,,am335x-evm,
    LCPD--1204,P3-Medium,AM335x - Some voltage rails remain active during poweroff,Power & Thermal,,,
    LCPD--965,P3-Medium,AM335x: Power: Poweroff is not shutting down voltage domains,Power & Thermal,,,
    LCPD--10987,P3-Medium,OpenCL tests failed due to missing CMEM carveouts in dts,"IPC, System Integration",OpenCL,am574x-idk,
    LCPD--12673,P3-Medium,Board refuses to suspend on setup with SATA device,Connectivity,,omapl138-lcdk,
    LCPD--12664,P3-Medium,Some of SATA tests failed with Internel oops error,Connectivity,,am57xx-evm,
    LCPD--12566,P3-Medium,CAN user guide references canconfig which is not supported any more,Connectivity,,,
    LCPD--11952,P3-Medium,AM57x: disabling USB super-speed phy in DT causes kernel crash,Connectivity,USB,am571x-idk,
    LCPD--11564,P3-Medium,AM57xx-evm: eth1 1G connection failure to netgear switch,Connectivity,"CPSW, ETHERNET, PHYIF",am57xx-evm,
    LCPD--10974,P3-Medium,am43xx-gpevm - usb camera gadget shows halting frames,Connectivity,USB,,
    LCPD--10781,P3-Medium,NetCP module removal results in backtrace and kernel panic,Connectivity,NETCP,k2g-evm,
    LCPD--10777,P3-Medium,mtd_stresstest failed on omapl138,Connectivity,NAND,omapl138-lcdk,
    LCPD--10551,P3-Medium,"K2E eth0 does down when running udp traffic, eth1 stops working",Connectivity,NETCP,k2e-evm,
    LCPD--10221,P3-Medium,Longer resume times observed on setup with usb device cable,Connectivity,USB,am335x-evm,
    LCPD--9974,P3-Medium,PCIe x2 width is not at expected width on am571x-idk,Connectivity,PCIe,am571x-idk,
    LCPD--9905,P3-Medium,AM437x: UART: Implement workaround for Advisory 27? Spurious UART interrupts when using EDMA,Connectivity,UART,am43xx-gpevm,
    LCPD--9816,P3-Medium,USBdevice omapl138 - Flood ping from server to dut usbdevice at 65500 bytes has packet loss,Connectivity,USB,omapl138-lcdk,
    LCPD--9815,P3-Medium,Failed to start Login Service when using debug systest build on omapl138,Connectivity,,omapl138-lcdk,
    LCPD--9804,P3-Medium,SATA performance decreased by ~34% for read and ~54% for write compared to v2.6.33 kernel,Connectivity,SATA,omapl138-lcdk,
    LCPD--9658,P3-Medium,OMAP-L138 LCDK: MUSB does not enumerate mouse connected to Keyboard hub,Connectivity,USB,omapl138-lcdk,
    LCPD--9591,P3-Medium,CONNECTIVITY: USB NCM gadget ping with packet sizes > 10000 fails,Connectivity,,,
    LCPD--9469,P3-Medium,Fix race condition when adding VLAN entries,Connectivity,NETCP,"k2e-evm, k2g-evm, k2g-ice, k2hk-evm, k2l-evm",
    LCPD--9466,P3-Medium,SATA PMP causes suspend failures,Connectivity,SATA,am57xx-evm,
    LCPD--9455,P3-Medium,Kernel Warning reported for a USB audio device when listing with pulseaudio,Connectivity,USB,am335x-evm,
    LCPD--9428,P3-Medium,Ethernet performace UDP: iperf command fails with two threads for lower buffer length,Connectivity,NETCP,"k2e-evm, k2hk-evm, k2l-evm",
    LCPD--9372,P3-Medium,Nand stress tests failed on am335x-evm,Connectivity,NAND,am335x-evm,
    LCPD--9366,P3-Medium,PCIe USB drive sometimes could not be enumerated,Connectivity,PCIe,k2g-evm,
    LCPD--9011,P3-Medium,K2G-evm: usb devices do not enumerate behind a TUSB8041 usb3.0 hub,Connectivity,USB,,
    LCPD--8984,P3-Medium,Kernel boot to initramfs with PA enabled results in no DHCP IP address assigned to network interfaces,Connectivity,NETCP,"k2e-evm, k2l-evm",
    LCPD--8637,P3-Medium,K2HK: Long-term ping test fails due to ethernet link going down,Connectivity,,,
    LCPD--8636,P3-Medium,Serial corruption being seen in kernel,Connectivity,UART,am335x-evm,
    LCPD--8354,P3-Medium,K2G EVM: Need to use PMT data,"Audio & Display, Baseport, Connectivity",PINMUX,k2g-evm,
    LCPD--8353,P3-Medium,K2G ICE: Need to use PMT data,"Audio & Display, Baseport, Connectivity",PINMUX,k2g-ice,
    LCPD--8133,P3-Medium,"USB: ""cannot reset"" errors observed sometimes",Connectivity,USB,am335x-evm,
    LCPD--8100,P3-Medium,CONNECTIVITY: K2G ethernet performance numbers are low,Connectivity,NETCP,k2g-evm,
    LCPD--8078,P3-Medium,AM3 SK: Touchscreen isn't responsive,"Audio & Display, Connectivity",,am335x-sk,
    LCPD--8033,P3-Medium,AM3 SK: Unexpected USB2-1 Messages on UART,Connectivity,USB,,
    LCPD--7955,P3-Medium,Uncorrectable Bitflip errors seen after switch to SystemD,Connectivity,GPMC,"am335x-evm, am43xx-gpevm, k2e-evm, k2g-evm, k2g-ice, k2hk-evm, k2hk-hsevm, k2l-evm",Workaround to erase the NAND flash completely if flashed with an incompatible flash writer. SystemD tries to mount all partitions and that is the reason this is being seen now.
    LCPD--7829,P3-Medium,uboot: UHS card did not work on the expected speed in uboot,Connectivity,,am57xx-evm,
    LCPD--7744,P3-Medium,UHS SDR104 card works on different speed after soft reboot,Connectivity,,am57xx-evm,
    LCPD--7623,P3-Medium,Seeing SPI transfer failed error sometimes on k2hk when using rt kernel,Connectivity,SPI,k2hk-evm,
    LCPD--7559,P3-Medium,K2E/K2HK does not enumerate usb3 devices through usb3.0 hub,Connectivity,USB,"k2e-evm, k2hk-evm",
    LCPD--7265,P3-Medium,Uboot eMMC does not use HS200 on am57xx-gpevm,Connectivity,,am57xx-evm,
    LCPD--6334,P3-Medium,k2g-evm: NAND is untestable due to data corruption issues,Connectivity,,k2g-evm,
    LCPD--6300,P3-Medium,am57xx-evm: A few UHS cards could not be numerated in kernel and mmc as rootfs failed.,Connectivity,,am57xx-evm,
    LCPD--6144,P3-Medium,am572x-idk: eMMC failed to enumerate,Connectivity,MMCSD,am572x-idk,
    LCPD--5699,P3-Medium,pci: am572x-idk: pci broadcom card doesn't enumerate,Connectivity,,"AM571x, AM572x",
    LCPD--5677,P3-Medium,K2E-evm: Marvel SATA controller could not be detected sometimes when Power On Reset is involved,Connectivity,,K2E,
    LCPD--5522,P3-Medium,pcie-usb sometimes the usb drive/stick could not be enumerated,Connectivity,,"am571x-idk, am572x-idk, am57xx-evm",
    LCPD--5362,P3-Medium,MUSB: Isoch IN only utilises 50% bandwidth,Connectivity,USB,AM335x,
    LCPD--5308,P3-Medium,i897: USB Stop Endpoint doesnt work in certain circumstances,Connectivity,USB,"AM437x, AM571x, AM572x",
    LCPD--4849,P3-Medium,K2hk: Connectivity: UART data corruption observed sometimes in loopback mode,Connectivity,,,
    LCPD--4503,P3-Medium,ALL: 8250 UART driver not enabeld as wake source by default,Connectivity,UART,,
    LCPD--1239,P3-Medium,J6: Connectivity: J6 could not resume when PCI-SATA card is in,Connectivity,PCIe,"am572x-idk, am57xx-evm",
    LCPD--1198,P3-Medium,"am43xx-gpevm:Connectivity: when kmemleak debug is enabled and mmc stress test is run, OOM killer is seen to kick in. Does not happen without kernel debug.",Connectivity,,,
    LCPD--1144,P3-Medium,Logitech USB-PS/2 Optical Mouse cannot be detected every other time the system is suspended/resumed (AM335x-EVM),Connectivity,,,
    LCPD--1106,P3-Medium,Connectivity:PCIe-SATA ext2 1G write performance is poor due to ata failed command,Connectivity,PCIe,am57xx-evm,
    LCPD--932,P3-Medium,AM33X: CONNECTIVITY: MUSB MSC read numbers are lower in 3.14 compared to 3.12,Connectivity,USB,,
    LCPD--869,P3-Medium,AM335x: Connectivity: USB data transfer fails if board is suspended/resumed,Connectivity,,,
    LCPD--662,P3-Medium,CONNECTIVITY: AM335X: distortion in USB audio when msc connect/disconnect happens in parallel,Connectivity,,,
    LCPD--12512,P3-Medium,Board is not able to boot from emmc after flashing,Baseport,,am57xx-evm,
    LCPD--11546,P3-Medium,Rare kernel crash triggered by task_blocks_on_rt_mutex,Baseport,,"am574x-idk, k2e-evm",
    LCPD--10533,P3-Medium,Cryptos: SHA1_Hash demo test fails on AM3/4/5 platforms,Baseport,,"am335x-evm, am335x-ice, am43xx-gpevm, am571x-idk, am572x-idk, am574x-idk, am57xx-evm",
    LCPD--10451,P3-Medium,Context switch delay increased based on LMBench numbers,Baseport,,"am335x-evm, am43xx-gpevm, am571x-idk, am572x-idk, am574x-idk, am57xx-evm",
    LCPD--9981,P3-Medium,Some LTP's memory management tests fail due to low amount of free memory,Baseport,,omapl138-lcdk,
    LCPD--9980,P3-Medium,LTP's math tests float_exp_log and float_trigo fail due to OOM,Baseport,,omapl138-lcdk,
    LCPD--9756,P3-Medium,"pm_runtime does not kicks in for some IPs (serial, gpio and wdt)",Baseport,,omapl138-lcdk,
    LCPD--8640,P3-Medium,Crypto performance for AES drops 3-10% in 2016.05,Baseport,,,
    LCPD--8550,P3-Medium,CPSW memory allocation errors seen during boot,"Audio & Display, Baseport",,am335x-sk,
    LCPD--8406,P3-Medium,K2G: PADCONFIG_202 register cannot be re-programmed,Baseport,,"k2g-evm, k2g-ice",This has proven to be a silicon issue related to locking RSTMUX. It is currently being discussed if it will be fixed in a newer silicon revision. Currently to avoid this issue the affected pins pinmux are not changed in the kernel. This is because U-boot locks RSTMUX which causes problems if the kernel tries to change the pinmuxing for the pins.
    LCPD--8350,P3-Medium,UART boot does not work on am57xx-evm,Baseport,,am57xx-evm,
    LCPD--8347,P3-Medium,BUG: sleeping function called from invalid context triggered by keystone_pcie_fault,Baseport,,"k2e-evm, k2g-evm",
    LCPD--8336,P3-Medium,Soft reboot does not work on am43xx-hsevm rev1.5b,Baseport,,am43xx-hsevm,
    LCPD--8257,P3-Medium,Boot failed 1 of 1000 times on k2g,Baseport,,k2g-evm,
    LCPD--7717,P3-Medium,LTP Timer test fails for clock_settime02 for dra71-evm,"Baseport, System Test",,,
    LCPD--7486,P3-Medium,uboot debug with ccs is failing for K2,Baseport,,k2hk-evm,
    LCPD--7222,P3-Medium,Asynchronous abort seen during soft reboot from kernel,Baseport,,k2g-evm,
    LCPD--6998,P3-Medium,K2G sometimes boot failed with kernel oops error,Baseport,,k2g-evm,
    LCPD--6663,P3-Medium,[RT] Kmemleak is buggy and boot is crashed randomly,Baseport,,,
    LCPD--5537,P3-Medium,kmemleak: Could not scan kmemleak due to object search tree errors,Baseport,,"AM571x, AM572x",
    LCPD--12790,P3-Medium,DSS: work-around for DRA7 errata i932,Audio & Display,Display,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm",
    LCPD--12680,P3-Medium,Seeing i2c timeout error and board failed to boot,Audio & Display,,k2g-evm,
    LCPD--12511,P3-Medium,Audio record is not working,Audio & Display,,am57xx-evm,
    LCPD--11138,P3-Medium,VIP driver multi-channel capture issue with TVP5158,Audio & Display,"Capture, VIP","am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm",
    LCPD--10954,P3-Medium,DSS sync-losts and underflows seen with bad config,Audio & Display,Display,am437x-sk,
    LCPD--7735,P3-Medium,Powerdomain (vpe_pwrdm) didn't enter target state 0,"Audio & Display, Power & Thermal",,am57xx-evm,
    LCPD--7696,P3-Medium,DRA7xx: VPE: File2File checksum changes across multiple runs,Audio & Display,,"am571x-idk, am572x-idk, am57xx-evm","There is no workaround for this issue yet. No visual artifacts, but checksum on initial frame differs as couple of bytes are incorrect"
    LCPD--7693,P3-Medium,VIP: OV1063x: Video artifacts in LVDS cameras,Audio & Display,Capture,,
    LCPD--6377,P3-Medium,OMAP_BO_CACHED feature not functional,"Audio & Display, Multimedia",Display,"am437x-idk, am437x-sk, am43xx-gpevm, am571x-idk, am572x-idk, am57xx-evm, k2g-evm",
    LCPD--5380,P3-Medium,omapdss error: HDMI I2C Master Error,Audio & Display,,AM572x,Occurs only with this monitor -http://www.amazon.com/gp/product/B00PFLZV2G
    LCPD--4858,P4-Low,Power: pm_debug state counters are not increased during suspend,Power & Thermal,,"AM335x, AM437x",
    LCPD--4779,P4-Low,"coreaon, wkupaon and rtc power domains OFF counters are increasing during SUSPEND",Power & Thermal,,"AM571x, AM572x",
    LCPD--1191,P4-Low,AM335x: Power: System resumes due to wakeup source USB1_PHY without any external trigger,Power & Thermal,,,Use GPIO interrupt instead of USB PHY for wakeup source.
    LCPD--1013,P4-Low,AM335x: Power: Seldom short-duration power increase (~38mw) in VDDSHV4 domain,Power & Thermal,,,
    LCPD--10455,P4-Low,remoteproc/keystone: Hang observed while running RPMSG_PROTO example app,IPC,DSP_remoteproc,"k2g-evm, k2g-ice, k2hk-evm, k2l-evm",
    LCPD--9801,P4-Low,remoteproc/davinci: DSP boot is broken after a suspend/resume cycle,IPC,DSP_remoteproc,omapl138-lcdk,
    LCPD--9481,P4-Low,Sometime the system hangs while loading the rpmsg rpc modules,IPC,RPMSG-RPC,"am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm",
    LCPD--7495,P4-Low,Sometimes a Kernel Warning + Oops is seen when removing keystone_remoteproc module,IPC,,k2hk-evm,
    LCPD--4855,P4-Low,[rpmsg 2015 LTS] J6Eco: IPC: Board hangs when an MMU fault occurs in the first message,IPC,,am572x-idk,
    LCPD--4699,P4-Low,rpmsg-rpc: kernel crash during error recovery with dynamic debug traces enabled,IPC,,"am571x-idk, am572x-idk, am57xx-evm",
    LCPD--12783,P4-Low,Missing instruction for pcie-ep config on k2g-evm for 4.14 kernel,Connectivity,,k2g-evm,
    LCPD--11570,P4-Low,Base ubi filesystem could not be mounted as ubifs on k2g-evm,Connectivity,,k2g-evm,
    LCPD--9589,P4-Low,I2C: Sometimes i2c read write failed on farm01 and farm02,Connectivity,,am335x-evm,
    LCPD--9222,P4-Low,PRUSS Ethernet does not work on AM572x ES1.1,Connectivity,PRUSS-Ethernet,am572x-idk,
    LCPD--8477,P4-Low,K2: serdes nodes doesn't have a functional clock,Connectivity,SERDES,"k2e-evm, k2e-hsevm, k2g-evm, k2g-ice, k2hk-evm, k2hk-hsevm, k2l-evm, k2l-hsevm",
    LCPD--8270,P4-Low,K2: SerDes driver need to enable PD of the peripheral before access the SerDes h/w,Connectivity,SERDES,k2g-evm,
    LCPD--7998,P4-Low,Realtime OSADL Test results degraded slightly for am572x-idk,Connectivity,,am572x-idk,
    LCPD--7903,P4-Low,Uboot phy startup failed and dhcp failed occasionally on k2 board,Connectivity,,"k2g-evm, k2hk-evm",
    LCPD--7480,P4-Low,K2L/E EVMs doesn't boot to Linux when both 1G Ethernet interfaces are connected,Connectivity,,"k2e-evm, k2l-evm",
    LCPD--7188,P4-Low,PCIe-SATA test failed,Connectivity,,am57xx-evm,TI custom board would help with signal integrity issues being seen with the EVM.
    LCPD--1207,P4-Low,AM43XX/AM57XX: CONNECTIVITY: dwc3_omap on am43xx and xhci_plat_hcd on dra7 - removal results in segmentation fault,Connectivity,USB,,
    LCPD--998,P4-Low,MUSB does not free urbs causing usb audio playback to fail,Connectivity,,AM335x,
    LCPD--671,P4-Low,AM33XX: CONNECTIVITY: MUSB in PIO mode - video issues,Connectivity,,,
    LCPD--525,P4-Low,AM438x: Connectivity: I2C operates 9% beyond desired frequency,Connectivity,,,
    LCPD--10223,P4-Low,Keystone-2 Linking RAM region 0 size register REGION0_SIZE programming,Baseport,,k2hk-evm,
    LCPD--6075,P4-Low,BUG: using smp_processor_id() in preemptible [00000000] code during remoteproc suspend/resume,"Baseport, IPC",,"am572x-idk, am57xx-evm",
    LCPD--9098,P4-Low,Writeback: error prints seen when doing wb capture,Audio & Display,"Capture, Display, Writeback","am571x-idk, am572x-idk, am57xx-evm",
    LCPD--8884,P4-Low,VIP does not work after incorrectly configuring captured YUYV frame as NV12,Audio & Display,"Capture, VIP",,
    LCPD--5059,P4-Low,omapdrm: moving plane from one enabled display to another causes errors,Audio & Display,Display,,
    LCPD--4681,P4-Low,omapdrm: an error when enabling a display is not handled correctly,Audio & Display,Display,,
    LCPD--1171,P4-Low,DMM errata i878 (framebuffer part),Audio & Display,"Display, TILER","am571x-idk, am572x-idk, am57xx-evm",

|

RT Linux Kernel Known Issues
-----------------------------

.. csv-table::
   :header: "Record ID", "Priority", "Title", "Component", "Subcomponent", "Platform", "Workaround"
   :widths: 5, 10, 70, 10, 5, 20, 15

   LCPD-6663 ,P3-Medium ,[RT] Kmemleak is buggy and boot is crashed randomly ,Baseport ,  ,  , 
   LCPD-7623 ,P3-Medium ,Seeing SPI transfer failed error sometimes on k2hk when using rt kernel ,Connectivity ,SPI ,k2hk-evm , 
   LCPD-11546 ,P3-Medium ,Rare kernel crash triggered by task_blocks_on_rt_mutex ,Baseport ,  ,"am574x-idk, k2e-evm ", 
   LCPD-11568 ,P3-Medium ,dhcp failed to get IP address after reboot for K2G-ICE non-RT linux ,Baseport ,u-boot  ,"k2g-ice ",
|

.. rubric:: Installation and Usage
   :name: installation-and-usage

The `Software Developer's
Guide <Overview.html#processor-sdk-linux-software-developer-s-guide>`__
provides instructions on how to setup up your Linux development
environment, install the SDK and start your development.  It also
includes User's Guides for various Example Applications and Code
Composer Studio.

| 

.. rubric:: Host Support
   :name: host-support

The Processor SDK is developed, built and verified on Ubuntu 14.04 and
16.04.   Details on how to create a virtual machine to load Ubuntu 14.04
are described in `this
page <Processor_Linux_SDK_How_To_Guides.html#how-to-build-a-ubuntu-linux-host-under-vmware>`__.


.. note::
   Processor SDK Installer is 64-bit, and installs only on 64-bit host
   machine. Support for 32-bit host is dropped as Linaro toolchain is
   available only for 64-bit machines

| 

