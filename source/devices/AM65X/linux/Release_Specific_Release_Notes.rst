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

Release 08.06.00
==================

Released March 2023

Supported Platforms
=====================================
See :ref:`here <release-specific-supported-platforms-and-versions>` for a list of supported platforms and links to more information.

|

.. _release-specific-sdk-components-versions:

Build Information
=====================================

U-Boot
-------------------------

| Head Commit: dce39357567f6833db98ff9867eae97f4f7fc700 default.avbkey: fix 0 key size
| Date: Wed Mar 1 10:55:12 CDT 2023
| uBoot Version: 2021.01
| uBoot Description: cicd.dunfell.202303090400
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: cicd.dunfell.202303090400
| uBoot Tag: cicd.dunfell.202303090400

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
| 

Kernel
-------------------------
.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 2c23e6c538c879e380401ae4b236f54020618eaa Merged TI feature connectivity into ti-linux-5.10.y-cicd
| Date: Thu Feb 23 13:09:34 CDT 2023
| Kernel Version: 5.10.168
| Kernel Description: 08.06.00.007

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.10.y
| Tag: 08.06.00.007
| Kernel defconfig: ti_sdk_arm64_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
| 

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: c1a12919117a6978f40e723d6e0c67c744e026b9 Merge branch 'ti-rt-linux-5.10.y-cicd' into ti-rt-linux-5.10.y
| Date: Thu Feb 23 16:06:31 CDT 2023
| Kernel Version: 5.10.168
| RT Kernel Version: 5.10.168-rt62
| Kernel Description: 08.06.00.007-rt

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.10.y
| Tag: 08.06.00.007-rt
| Kernel defconfig: ti_sdk_arm64_rt_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

Yocto
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 27ff52dd415164ffce84a5c316c5475225860f46 ti-k3-secdev: CI/CD Auto-Merger: cicd.dunfell.202303021800
| Date: 2023-02-08
| Version: dunfell-3.1

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: cicd.dunfell.202303090400
| 

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: 07a4d8f3320f9574676e9a3055912fb69c7dce7a ltp-ddt: CI/CD Auto-Merger: cicd.dunfell.202303090400
| Date: 2023-03-09
| Version: dunfell-3.1

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: dunfell
| Release Tag: cicd.dunfell.202303090400
| 

.. rubric:: meta-processor-sdk

| Head Commit: 01876dc32daf5a31a643d26f7935d6cd35187d08 ti-tisdk-setup: Remove setup.sh TFTP Fix patch for AM65
| Date: 2023-03-25

| Clone: git://git.ti.com/processor-sdk/meta-processor-sdk.git
| Branch: dunfell
| 



Issues Tracker
=====================================
..
   project = LCPD AND platform in (am654x-evm, am654x-hsevm) AND
      issuetype = Bug AND
      status = Closed AND
      resolution = Done AND
      component in (
         "Audio & Display", 
         Baseport, 
         Connectivity, 
         IPC, 
         "Power & Thermal", 
         Graphics, 
         Multimedia, 
         Wireless, 
         "System Integration", 
         Security) AND
      closedDate > 2021-12-10 AND
      createdDate <= 2021-12-10 AND
      (Labels not in (LCPD_K3.14_MAINT, MAINTENANCE) OR labels is EMPTY) AND
      OS in (Linux, RT-linux) 
      ORDER BY priority DESC   

Issues opened in previous releases that were closed on this release
-------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Summary"
   :widths: 20, 80

   "LCPD-32773","Rx stall seen when there is network traffic during startup"
   "LCPD-28492","AM65: ICSSG: phc_ctl: Seeing clock jumps in get"

..
   project = LCPD AND platform in (am654x-evm, am654x-hsevm) AND
       issuetype = Bug AND
       status = Closed AND
       resolution = Done AND
       component in (
          "Audio & Display", 
          Baseport,
          Connectivity, 
          IPC, 
          "Power & Thermal",
          "System Integration",
          Wireless,
          Graphics,
          Multimedia,
          Security) AND
       closedDate > 2021-12-10 AND
       createdDate > 2021-12-10 AND
       (Labels not in (LCPD_K3.14_MAINT, MAINTENANCE) OR labels is EMPTY) AND
       OS in (Linux, RT-linux) AND
       fixversion not in (Upstream) 
       ORDER BY priority DESC  

Issues found and closed on this release that may be applicable to prior releases
--------------------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Summary"
   :widths: 20, 80

    "LCPD-29306","PRU_ICSSG: How much SRAM is needed?"
    "LCPD-29694","gpio-line-names is limited to 100. it should be ti,ngpios"
    "LCPD-18860","isolcpus in the command line is not honored"

..
    project = LCPD AND
       platform in (am654x-evm, am654x-hsevm) AND
       ErrataID is not EMPTY AND
       status = Closed AND
       resolution not in (Duplicate, Rejected) 
       ORDER BY priority DESC 


Errata workarounds
------------------

.. csv-table::
   :header: "Record ID", "Summary", "Workaround", "ErrataID"
   :widths: 20, 80, 60, 20

    "LCPD-18979","MCAN: Message Transmitted with Wrong Arbitration and Control Fields (Early Start of Frame)"
    "LCPD-19965","OSPI PHY Controller Bug Affecting Read Transactions"
    "LCPD-17788","PCI-Express: GEN3 (8GT/s) Operation Not Supported."
    "LCPD-17783","USB: USB2PHY Charger Detect is enabled by default without VBUS presence"
    "LCPD-14184","USB:  SuperSpeed USB Non-Functional"
    "LCPD-19447","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame"
    "LCPD-14579","DSS : DSS Does Not Support YUV Pixel Data Formats"

..
    project = LCPD AND
       platform in (am654x-evm, am654x-hsevm) AND
       issuetype = Bug AND
       (status not in (Closed, "In Build") OR status = Closed AND
       resolution in ("Known Issue : HW Limitation", "Known Issue : Other")) AND
       component in ("System Integration", Graphics, Wireless, Security, Multimedia) AND
       (labels not in (LCPD_K3.14_MAINT, MAINTENANCE, DO_NOT_RELEASE_NOTE) OR labels is EMPTY) AND
       (affectedVersion <= 08.02.00  AND
       affectedVersion > Upstream OR affectedVersion < Upstream OR affectedVersion is EMPTY) 
       ORDER BY key DESC, priority DESC, component ASC  

.. _release-specific-known-issues:

SDK Known Issues
----------------

.. csv-table::
   :header: "Record ID", "Summary", "Workaround"
   :widths: 20, 80, 60

    LCPD-19948,Yocto: stream recipe is incorrect,
    LCPD-18908,GLMark2 fails for am65x,
    LCPD-17449,libasan_preinit.o is missing in devkit,
    LCPD-17413,QT Webengine-based browser: the mouse does not work within the web page with QPA EGLFS,

..
    project = LCPD AND
       platform in (am654x-evm, am654x-hsevm) AND
       issuetype = Bug AND
       (status not in (Closed, "In Build") OR status = Closed AND
       resolution in ("Known Issue : HW Limitation", "Known Issue : Other")) AND
       component in ("Power & Thermal", Baseport, "Audio & Display", Connectivity, IPC) AND
       (labels not in (LCPD_K3.14_MAINT, upstream, MAINTENANCE) OR labels is EMPTY) AND
       (summary ~ u-boot OR Subcomponent in (u-boot, UBOOT, Uboot)) AND
       (affectedVersion <= 08.02.00 AND
       affectedVersion > Upstream OR affectedVersion < Upstream OR affectedVersion is EMPTY) 
       ORDER BY priority DESC, component ASC, key DESC 

U-Boot Known Issues
-------------------

.. csv-table::
   :header: "Record ID", "Summary", "Workaround"
   :widths: 20, 80, 60

    "LCPD-28286","ICSSG: AM65 SR2.0: U-Boot: Avoid hardcoding DMA channel"
    "LCPD-24628","am654x-idk DFU boot is failing"
    "LCPD-28287","ICSSG: AM65 SR2.0: U-Boot: RX is not working"
    "LCPD-24717","am654: PCI-E ethernet interface shows link down in U-Boot"
    "LCPD-24130","AM654x: USB MSC boot mode fails"
    "LCPD-16696","U-Boot does not recognize SD-Card after re-insert/change"
    "LCPD-15873","There is no dtbo in u-boot for PCIe x1 + usb3 daughter card"
    "LCPD-17770","U-Boot: Fix order of MCU R5 shutdown depending on cluster mode"
    "LCPD-16524","Need to adjust RMW bit when using enabling ECC"
    "LCPD-14843","U-boot should support  default settings for netboot "

..
   project = LCPD AND
       platform in (am654x-evm, am654x-hsevm) AND
       issuetype = Bug AND
       (status not in (Closed, "In Build") OR status = Closed AND
       resolution in ("Known Issue : HW Limitation", "Known Issue : Other")) AND
       component in ("Audio & Display", Baseport, Connectivity, IPC, "Power & Thermal") AND
       (affectedVersion <= 08.02.00  AND
       affectedVersion > Upstream OR affectedVersion < Upstream OR affectedVersion is EMPTY) AND
       (labels not in (LCPD_K3.14_MAINT, upstream, MAINTENANCE, DO_NOT_RELEASE_NOTE) OR labels is EMPTY) AND
       summary !~ u-boot AND
       (Subcomponent not in (u-boot, UBOOT, Uboot) OR Subcomponent is EMPTY) AND
       OS = Linux 
       ORDER BY priority DESC, component DESC, key DESC   

.. _release-specific-linux-kernel-known-issues:

Linux Kernel Known Issues
---------------------------

.. csv-table::
   :header: "Record ID", "Summary", "Workaround"
   :widths: 20, 80, 60

    LCPD-18979,MCAN: Message Transmitted with Wrong Arbitration and Control Fields (Early Start of Frame)
    LCPD-17449,libasan_preinit.o is missing in devkit
    LCPD-17471,device hang when restarting crashed R5F
    LCPD-29397,AM65x Linux SDK lists unsupported industrial protocols
    LCPD-25314,ICSSG: Timestamp for back-to-back with IPG < 100us not received
    LCPD-29446,Linux SDK docs should explicitly state what peripherals are supported
    LCPD-13653,am65x-evm could not boot from MMC/SD when MMC/SD is backup boot mode
    LCPD-19948,Yocto: stream recipe is incorrect
    LCPD-14254,meta-ti: Need a recipe update to pick up the new AM65x PRU Ethernet firmwares
    LCPD-13817,Qt5 Webengine-based broswer does not work on AM654x with pagesize = 64k
    LCPD-13816,Chromium-wayland broswer does not work on AM654x with page size = 64k
    LCPD-24456,Move IPC validation source from github to git.ti.com
    LCPD-22931,RemoteProc documentation missing
    LCPD-16534,remoteproc/k3-r5f: PDK IPC echo_test image fails to do IPC in remoteproc mode on second run
    LCPD-18908,GLMark2 fails for am65x
    LCPD-17413,QT Webengine-based browser: the mouse does not work within the web page with QPA EGLFS
    LCPD-17412,QT5 Webengine-based browser crashing with any resize operation
    LCPD-24127,AM654x IPSEC Software Crypto tests fail (Impact 4)
    LCPD-29588,CPSW documentation: Time Sync Router no longer firewalled
    LCPD-28436,AM65x Uboot PRUETH is broken
    LCPD-24537,am654x-idk nslookup times out when all netwokring interfaces are active
    LCPD-24288,am64xx-evm NCM/ACM network performance test crashes with RT images
    LCPD-22905,UDMA: TR15 hangs if ICNT0 is less than 64 bytes
    LCPD-22892,icssg: due to FW bug both interfaces has to be loaded always
    LCPD-22772,PRU_ICSSG: 100Mbit/s MII is not supported when the PRU_ICSSG is operating at frequencies < 250MHz
    LCPD-22324,ICSSG port does not drop packets with SA matching interface MAC
    LCPD-19923,[AM65x] Linux reboot command fails
    LCPD-19861,ICSSG: Unregistered multicast MAC packets are still visible in non-promiscuous mode
    LCPD-19580,am654- unable to select a mode (sdhci?)
    LCPD-18788,Uboot: Could not bring up PCIe interface
    LCPD-18665,Am65x Pg2: Board cannot do soft reboot when booting from SD card
    LCPD-18289,pcie-usb tests sometimes fail
    LCPD-18228,PCI PM runtime suspend is not increasing
    LCPD-17800,CPSW: Master/Slave resolution failed message seen at console
    LCPD-16406,Seeing "e1000#0: ERROR: Hardware Initialization Failed" sometimes when do dhcp via pcie-eth
    LCPD-15540,uvc-gadget results in segmentation fault
    LCPD-14183,am654x-idk failed to login to kernel a few times (7/1000)
    LCPD-13938,PCIe EP read/write/copy test failed with larger sizes 
    LCPD-13936,Uboot dhcp timeout 1 of 100 times
    LCPD-13603,One board could not boot rootfs from more than one SDHC card
    LCPD-13445,Seldom kernel oops triggered by prueth_netdev_init
    LCPD-20653,ltp: kernel syscall tests fail
    LCPD-19929,Industrial protocols documentation
    LCPD-18258,IPSEC perfomance failures
    LCPD-17777,AES HW is not exercised
    LCPD-17673,No software documentation for the Timer module
    LCPD-17115,BUG: sleeping function called from invalid context at kernel/locking/rtmutex.c:967
    LCPD-16845,OPP freq update in DT impacts only cluster0
    LCPD-13410,Reboot command is not operational
    LCPD-24134,AM654x CAL DMABUF tests fail (Impact 4.0)
    LCPD-22947,Alsa performance test fails
    LCPD-19447,DSS: Disabling a layer connected to Overlay may result in synclost during the next frame
    LCPD-18297,AM6: OV5640: 176x144 does not work
    LCPD-14443,CTS failures detected
    LCPD-20014,remoteproc: TX_PRU: IRQ vring, IRQ kick not found error message on console
    LCPD-29580,ICSSG IET Statistics are not getting counted
    LCPD-24718,am654x hwspinlock test failing
    LCPD-19739,AM65 shutdown error
    LCPD-29872,PTP Time Synchronization needs to be restarted after link downs
    LCPD-22959,UART Read/Write tests at baud rate 115200 fails
    LCPD-24319,am654x-evm DRM tests fail due to frequency mismatch (Impact 7)
    LCPD-23008,AM65xx - display port scenario not enabled
    LCPD-23007,k3-am654-evm-hdmi.dtbo file is missing in CoreSDK for am654x
    LCPD-32823,ICSS firmware does not process Rx packets once Min error frame is received
    LCPD-34104,ICSSG interface statistics rx_total_bytes don't match tx_total_bytes (eth1 -> eth3)

..
   project = LCPD AND
       platform in (am654x-evm, am654x-hsevm) AND
       issuetype = Bug AND
       (status not in (Closed, "In Build") OR status = Closed AND
       resolution in ("Known Issue : HW Limitation", "Known Issue : Other")) AND
       component in ("Power & Thermal", Baseport, "Audio & Display", Connectivity, IPC) AND
       (labels not in (LCPD_K3.14_MAINT, MAINTENANCE) OR labels is EMPTY) AND
       summary ~ rt AND
       (affectedVersion <= 08.02.00  AND
       affectedVersion > Upstream OR affectedVersion < Upstream OR affectedVersion is EMPTY) 
       ORDER BY  priority DESC

.. _release-specific-rt-linux-kernel-known-issues:

RT Linux Kernel Known Issues
----------------------------

.. csv-table::
   :header: "Record ID", "Summary", "Workaround"
   :widths: 20, 80, 60

    "LCPD-24288","am64xx-evm NCM/ACM network performance test crashes with RT images"

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
