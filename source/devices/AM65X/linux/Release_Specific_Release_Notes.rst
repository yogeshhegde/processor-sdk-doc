.. _release-specific-release-notes:

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
-  WLAN support (Wilink 8)
-  Code Composer Studio

Licensing
=========

Please refer to the software manifest, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page. The manifest can be found on the SDK
download page or in the installed directory as indicated below. In
addition, see :ref:`Processor SDK Linux GPLv3 Disclaimer <overview-gplv3-disclaimer>`.

Documentation
===============
-  :ref:`Processor SDK Linux Software Developer's Guide <linux-index>`: Provides information on features, functions, delivery package and,
   compile tools for the Processor SDK Linux release. This also provides
   detailed information regarding software elements and software
   infrastructure to allow developers to start creating applications.
-  :ref:`Processor SDK Linux Getting Started Guide <overview-getting-started>`: Provides information on getting the software and running
   examples/demonstrations bundled in the SDK.
-  **Software Manifest**: Provides license information on software
   included in the SDK release. This document is in the release at
   ``[INSTALL-DIR]/docs``.
-  **EVM Quick Start Guide**: Provides information on hardware setup and
   running the demonstration application that is loaded on flash. This
   document is provided as part of the EVM kit.

Release 07.03.00
==================

Released May 2021

.. rubric:: What's New
   :name: whats-new


.. _release-specific-sdk-components-versions:

.. rubric:: SDK Components & Versions
   :name: sdk-components-versions

+--------------------------+----------------------------+
| Component                | Version                    |
+==========================+============================+
| Linux Kernel             | 5.4.106                    |
+--------------------------+----------------------------+
| U-Boot                   | 2020.01                    |
+--------------------------+----------------------------+
| Yocto Project            | 3.1 (dunfell)              |
+--------------------------+----------------------------+
| ARM Toolchain (gcc)      | 9.2-2019.12 hard-float     |
+--------------------------+----------------------------+
| TI C66x CGT Compiler     | 8.3.2                      |
+--------------------------+----------------------------+

|

Supported Platforms
=====================================
See :ref:`here <release-specific-supported-platforms-and-versions>` for a list of supported platforms and links to more information.

|


Build Information
=====================================

.. _release-specific-build-information-u-boot:

U-Boot
-------------------------

| Head Commit: 2781231a33c3d779e32445f4fe55164c45d6d7c1 arm: mach-k3: j721e_init: probe clock node after sci node is probed
| Date: Wed Apr 7 21:12:38 CDT 2021
| uBoot Version: 2020.01
| uBoot Description: 07.03.00.005

| Clone: https://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: 07.03.00.005
| uBoot Tag: 07.03.00.005

| Compiler Information:  arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025

.. _release-specific-build-information-kernel:

Kernel
-------------------------

.. _release-specific-build-information-linux-kernel:

.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 023faefa70274929bff92dc41167b007f7523792 Merged TI feature connectivity into ti-linux-5.4.y
| Date: Wed Apr 7 14:38:29 CDT 2021
| Kernel Version: 5.4.106
| Kernel Description: 07.03.00.005
| Repo: https://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.4.y
| Tag: 07.03.00.005

| Compiler Information: arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025

.. _release-specific-build-information-rt-linux-kernel:

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 519667b0d81d74a6e55105dcd6072ae550352599 Merged TI feature ti_linux_base_rt into ti-rt-linux-5.4.y
| Date: Wed Apr 7 21:12:27 CDT 2021
| Kernel Version: 5.4.106
| RT Kernel Version: 5.4.106-rt54
| Kernel Description: 07.03.00.005-rt

| Repo: https://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.4.y
| Tag: 07.03.00.005-rt

| Compiler Information:  arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025

.. _release-specific-generic-kernel-release-notes:

.. rubric:: Generic Kernel Release Notes
   :name: generic-kernel-release-notes

| Generic kernel release notes from kernelnewbies.org can be found at:
  https://kernelnewbies.org/Linux_5.4
| Archived versions can be found at:
  http://kernelnewbies.org/LinuxVersions

|

Yocto
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 52ffccb09385ef3a369770b2fa45bc09418a5050
| ti-rtos: Update metadata and versions for RTOS firmware
| Date: 2021-4-05
| Version: dunfell-3.1

| Clone: https://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: 07.03.00.005

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: ee6ff44d90945429051c8d9573c8b60705104149
| omapconf: Bump to v1.75 release
| Date: 2021-4-01
| Version: 2020.05

| Clone: https://arago-project.org/git/meta-arago.git
| Branch: dunfell
| Release Tag: 07.03.00.005
|

Issues Tracker
=====================================
..
   project = LCPD AND issuetype = Bug AND status = Closed AND resolution = Done AND component in ("Audio & Display", Baseport, Connectivity, IPC, "Power & Thermal", Graphics, Multimedia, Wireless, "System Integration", Security) AND closedDate > 2020-11-18 AND createdDate <= 2020-11-17 AND (Labels not in (LCPD_K3.14_MAINT, MAINTENANCE, PLSDK_NOT_RN) OR labels is EMPTY) AND OS in (Linux, RT-linux) AND Platform in (am654x-evm, am654x-hsevm, am654x-idk) ORDER BY key DESC, priority DESC

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Summary"
   :widths: 20, 80

   LCPD-19785,Uboot: usbhost has problem with detection
   LCPD-19784,DFU MMC test fails
   LCPD-19781,OE: ti-rpmsg-char: Library header files and primary so file are missing in FS
   LCPD-19772,ATF/Uboot GTC frequency handover bug
   LCPD-19740,TLS1.2 hangs on handshake
   LCPD-19717,am654-gpevm: kernel image boot reports corruption
   LCPD-19695,am654-gpevm: kernel image boot reports corruption
   LCPD-19264,Uboot: No usb controllers found 
   LCPD-19249,"Kernel WARN observed in some cases, tisci timeout reported"
   LCPD-19180,AM65 PG1 fails to boot with MMC/SD
   LCPD-18620,AM65x PG2: U-Boot MMC/SD does not work at greater than 25MHz clock

..
   project = LCPD AND issuetype = Bug AND status = Closed AND resolution = Done AND component in ("Audio & Display", Baseport, Connectivity, IPC, "Power & Thermal", "System Integration", Wireless, Graphics, Multimedia, Security) AND closedDate > 2020-11-18 AND createdDate > 2020-11-18 AND (Labels not in (LCPD_K3.14_MAINT, MAINTENANCE, PLSDK_NOT_RN) OR labels is EMPTY) AND OS in (Linux, RT-linux) AND fixversion not in (Upstream) AND Platform in (am654x-evm, am654x-hsevm, am654x-idk) ORDER BY key DESC, priority DESC

Issues found and closed on this release that may be applicable to prior releases
--------------------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Summary"
   :widths: 20, 80

   LCPD-21348,K3: CPSWxG: can't disable rate limit for TX CPPI channels on Host P0
   LCPD-20623,AM654x UART boot failing to boot
   LCPD-20618,k3: cpswxg: bindings not updated
   LCPD-20170,am654x UART boot not working
   LCPD-20099,U-Boot: AM65: broken boot (Both PG1.0 and 2.0)
   LCPD-20026,AM654: PG1.0: MMC boot failure with SDK 7.1 on some boards
   LCPD-20024,OPTEE dunfell bleeding builds fail
   LCPD-19946,remoteproc/k3-r5f: Fix couple of warnings
   LCPD-19864,AM65xx: Support SD card modes not documented in the SDK documentation

..
   project = LCPD AND Platform in (am654x-evm, am654x-hsevm, am654x-idk) AND ErrataID is not EMPTY AND status = Closed AND (Labels not in (PLSDK_NOT_RN) OR labels is EMPTY) ORDER BY priority DESC

Errata workarounds
------------------

.. csv-table::
   :header: "Record ID", "Summary", "Workaround", "ErrataID"
   :widths: 20, 80, 60, 20

   LCPD-18979,MCAN: Message Transmitted with Wrong Arbitration and Control Fields (Early Start of Frame),,i939
   LCPD-14579,DSS : DSS Does Not Support YUV Pixel Data Formats,,i2000
   LCPD-17788,PCI-Express: GEN3 (8GT/s) Operation Not Supported.,,i2104
   LCPD-17783,USB: USB2PHY Charger Detect is enabled by default without VBUS presence,,i2075
   LCPD-19447,DSS: Disabling a layer connected to Overlay may result in synclost during the next frame,,i2097
   LCPD-19965,OSPI PHY Controller Bug Affecting Read Transactions,,i2189

..
   project = LCPD AND issuetype = Bug AND (status not in (Closed, "In Build") OR status = Closed AND resolution in ("Known Issue : HW Limitation", "Known Issue : Other")) AND component in ("System Integration", Graphics, Wireless, Security, Multimedia) AND (labels not in (LCPD_K3.14_MAINT, MAINTENANCE, DO_NOT_RELEASE_NOTE, PLSDK_NOT_RN, SKIP_REL_NOTES) OR labels is EMPTY) AND ((affectedVersion <= 07.03.00 AND affectedVersion >upstream ) OR affectedVersion is EMPTY OR affectedVersion not in (Upstream, upstream)) AND Platform in (am654x-evm, am654x-hsevm, am654x-idk) AND OS = "Linux" ORDER BY key DESC, priority DESC, component ASC

.. _release-specific-known-issues:

SDK Known Issues
----------------

.. csv-table::
   :header: "Record ID", "Summary", "Workaround"
   :widths: 20, 80, 60

   LCPD-21527,AM654x -GLMark2 Wayland benchmark test fails,
   LCPD-19948,Yocto: stream recipe is incorrect,
   LCPD-19858,OE: OPTEE label used in SDK is old and wrong,
   LCPD-18270,Ivi shell test fails. Lib ivi-controller.so and other components are missing from the file system,
   LCPD-17449,libasan_preinit.o is missing in devkit,
   LCPD-17413,QT Webengine-based browser: the mouse does not work within the web page with QPA EGLFS,
   LCPD-17412,QT5 Webengine-based browser crashing with any resize operation,
   LCPD-13817,Qt5 Webengine-based broswer does not work on AM654x with pagesize = 64k,
   LCPD-13816,Chromium-wayland broswer does not work on AM654x with page size = 64k,

..
   project = LCPD AND issuetype = Bug AND (status not in (Closed, "In Build") OR status = Closed AND resolution in ("Known Issue : HW Limitation", "Known Issue : Other")) AND component in ("Power & Thermal", Baseport, "Audio & Display", Connectivity, IPC) AND (labels not in (LCPD_K3.14_MAINT, upstream, MAINTENANCE, DO_NOT_RELEASE_NOTE, PLSDK_NOT_RN, SKIP_REL_NOTES) OR labels is EMPTY) AND (summary ~ u-boot OR Subcomponent in (u-boot, UBOOT, Uboot)) AND (affectedVersion <= 07.03.00 AND affectedVersion > upstream OR affectedVersion is EMPTY OR affectedVersion not in (Upstream, upstream)) AND Platform in (am654x-evm, am654x-hsevm, am654x-idk) ORDER BY key DESC, priority DESC, component ASC

U-Boot Known Issues
-------------------

.. csv-table::
   :header: "Record ID", "Summary", "Workaround"
   :widths: 20, 80, 60

   LCPD-22188,j721e and am65 hs fails to build on 2021.01 uboot,
   LCPD-18627,uboot does not read the reserve-memory from the fdt ,
   LCPD-17770,U-Boot: Fix order of MCU R5 shutdown depending on cluster mode,
   LCPD-16696,U-Boot does not recognize SD-Card after re-insert/change,
   LCPD-16524,Need to adjust RMW bit when using enabling ECC,None
   LCPD-15873,There is no dtbo in u-boot for PCIe x1 + usb3 daughter card,None
   LCPD-14843,U-boot should support  default settings for netboot ,None

..
   project = LCPD AND issuetype = Bug AND (status not in (Closed, "In Build") OR status = Closed AND resolution in ("Known Issue : HW Limitation", "Known Issue : Other")) AND component in ("Audio & Display", Baseport, Connectivity, IPC, "Power & Thermal") AND (affectedVersion <= 07.03.00 AND affectedVersion > upstream OR affectedVersion is EMPTY OR affectedVersion not in (Upstream, upstream)) AND (labels not in (LCPD_K3.14_MAINT, upstream, MAINTENANCE, DO_NOT_RELEASE_NOTE, PLSDK_NOT_RN, SKIP_REL_NOTES) OR labels is EMPTY) AND summary !~ u-boot AND (Subcomponent not in (u-boot, UBOOT, Uboot) OR Subcomponent is EMPTY) AND Platform in (am654x-evm, am654x-hsevm, am654x-idk) ORDER BY key DESC, priority DESC, component DESC

.. _release-specific-linux-kernel-known-issues:

Linux Kernel Known Issues
---------------------------

.. csv-table::
   :header: "Record ID", "Summary", "Workaround"
   :widths: 20, 80, 60

   LCPD-22239,2021.00 idk and pcie dtbs are missing for am654,
   LCPD-21536,AM654x - Display port tests fail due to tidss not found,
   LCPD-20243,AM65x Transition Kernel: pru-icssg support for100M half duplex mode is broken,
   LCPD-20014,"remoteproc: TX_PRU: IRQ vring, IRQ kick not found error message on console",
   LCPD-19929,Industrial protocols documentation,
   LCPD-19924,[AM65xx]  ICSS-G TCP receive throughput degraded,
   LCPD-19923,[AM65x] Linux reboot command fails,
   LCPD-19873,Pings not received by DUT over Ethernet VLAN,
   LCPD-19861,ICSSG: Unregistered multicast MAC packets are still visible in non-promiscuous mode,
   LCPD-19859,ETH ICSSG netperf benchmark returns lower performance than expected,
   LCPD-19580,am654- unable to select a mode (sdhci?),
   LCPD-19447,DSS: Disabling a layer connected to Overlay may result in synclost during the next frame,
   LCPD-18979,MCAN: Message Transmitted with Wrong Arbitration and Control Fields (Early Start of Frame),
   LCPD-18860,isolcpus in the command line is not honored,
   LCPD-18788,Uboot: Could not bring up PCIe interface,
   LCPD-18756,ICSSG: eth5 and eth6 unknown interfaces ,
   LCPD-18684,"syscalls sync failures: fdatasync03, fsync04, sync03, syncfs01, sync_file_range02",
   LCPD-18665,Am65x Pg2: Board cannot do soft reboot when booting from SD card,
   LCPD-18297,AM6: OV5640: 176x144 does not work,
   LCPD-18289,pcie-usb tests sometimes fail,
   LCPD-18258,IPSEC perfomance failures,
   LCPD-18233,MMC irq affinity to core 1 is not working.,
   LCPD-18228,PCI PM runtime suspend is not increasing,
   LCPD-18212,am6 failed to boot due to FDT creation failed! hanging 3 of 100 times,
   LCPD-17908,ICSSG: dual-emac: udp packets ocassionally sent out of order on egress,
   LCPD-17800,CPSW: Master/Slave resolution failed message seen at console,
   LCPD-17798,2020 LTS: INTA/INTR smp_affinity failure and IRQ allocation issues.,
   LCPD-17777,AES HW is not exercised,
   LCPD-17673,No software documentation for the Timer module,
   LCPD-17471,device hang when restarting crashed R5F,
   LCPD-17115,BUG: sleeping function called from invalid context at kernel/locking/rtmutex.c:967,
   LCPD-16845,OPP freq update in DT impacts only cluster0,
   LCPD-16534,remoteproc/k3-r5f: PDK IPC echo_test image fails to do IPC in remoteproc mode on second run,None
   LCPD-16406,"Seeing ""e1000#0: ERROR: Hardware Initialization Failed"" sometimes when do dhcp via pcie-eth",
   LCPD-15819,"tidss: the driver should reject dual-display setup, as it is not supported",
   LCPD-15540,uvc-gadget results in segmentation fault,
   LCPD-14183,am654x-idk failed to login to kernel a few times (7/1000),
   LCPD-13938,PCIe EP read/write/copy test failed with larger sizes ,
   LCPD-13936,Uboot dhcp timeout 1 of 100 times,
   LCPD-13653,am65x-evm could not boot from MMC/SD when MMC/SD is backup boot mode,No workaround
   LCPD-13603,One board could not boot rootfs from more than one SDHC card,
   LCPD-13445,Seldom kernel oops triggered by prueth_netdev_init,
   LCPD-13410,Reboot command is not operational,

..
   project = LCPD AND issuetype = Bug AND (status not in (Closed, "In Build") OR status = Closed AND resolution in ("Known Issue : HW Limitation", "Known Issue : Other")) AND component in ("Power & Thermal", Baseport, "Audio & Display", Connectivity, IPC) AND (labels not in (LCPD_K3.14_MAINT, upstream, MAINTENANCE, DO_NOT_RELEASE_NOTE, PLSDK_NOT_RN, SKIP_REL_NOTES) OR labels is EMPTY) AND summary ~ rt AND (affectedVersion <= 07.03.00 AND affectedVersion > upstream OR affectedVersion is EMPTY OR affectedVersion not in (Upstream, upstream))  AND (Platform in (am654x-evm, am654x-hsevm, am654x-idk) OR Platform is EMPTY ) ORDER BY priority DESC

.. _release-specific-rt-linux-kernel-known-issues:

RT Linux Kernel Known Issues
----------------------------

.. csv-table::
   :header: "Record ID", "Summary", "Workaround"
   :widths: 20, 80, 60

   LCPD-6663,[RT] Kmemleak is buggy and boot is crashed randomly,
   LCPD-22238,RT linux build sometimes fails to boot - might be related to remoteproc2,

|

Installation and Usage
======================

The :ref:`Software Developer's Guide <linux-index>` provides instructions on how to setup up your Linux development
environment, install the SDK and start your development.  It also includes User's Guides for various Example Applications and Code
Composer Studio.

| 

Host Support
============

The Processor SDK is developed, built and verified on Ubuntu 16.04 and 18.04. Details on how to create a virtual machine to load Ubuntu
are described in :ref:`this page <how-to-build-a-ubuntu-linux-host-under-vmware>`.


.. note::
   Processor SDK Installer is 64-bit, and installs only on 64-bit host
   machine. Support for 32-bit host is dropped as Linaro toolchain is
   available only for 64-bit machines

| 
