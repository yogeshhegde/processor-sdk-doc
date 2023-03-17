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

Release 08.02.00
==================

Released March 2022

Supported Platforms
=====================================
See :ref:`here <release-specific-supported-platforms-and-versions>` for a list of supported platforms and links to more information.

|

.. _release-specific-sdk-components-versions:

Build Information
=====================================

U-Boot
-------------------------

| Head Commit: 44a87e3ab85c6d64044f0b5ad677008316baad70 ARM: dts: k3-j721s2: Correct timer frequency
| Date: Wed Mar 16 17:05:52 CDT 2022
| uBoot Version: 2021.01
| uBoot Description: 08.02.00.006
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: 08.02.00.006
| uBoot Tag: 08.02.00.006

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
| 

Kernel
-------------------------
.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 7a7a3af903da2b2d551d058f8262a66e6b42b6b1 Merged TI feature connectivity into ti-linux-5.10.y
| Date: Wed Mar 16 12:00:19 CDT 2022
| Kernel Version: 5.10.100
| Kernel Description: 08.02.00.006

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.10.y
| Tag: 08.02.00.006
| Kernel defconfig: ti_sdk_arm64_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
| 

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 204ec708dc86f4334f585f04835527570be1c4eb Merged TI feature ti_linux_base_rt into ti-rt-linux-5.10.y
| Date: Wed Mar 16 14:53:35 CDT 2022
| Kernel Version: 5.10.100
| RT Kernel Version: 5.10.100-rt62
| Kernel Description: 08.02.00.006-rt

| Clone: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.10.y
| Tag: 08.02.00.006-rt
| Kernel defconfig: ti_sdk_arm64_rt_release_defconfig

| Compiler Information:  aarch64-none-linux-gnu-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10))
|

Yocto
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: facd5397cdc5c35c69e7a8e8f908a98a5c23d270 u-boot-ti-staging: Bump to 08.02.00.006 release
| Date: 2022-03-08
| Version: dunfell-3.1

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: 08.02.00.006
| 

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: 382ca36beb21a524de726bfd1c57e3d26f10cf82 recipes-core: images: Add tisdk-thinlinux-image
| Date: 2022-03-08
| Version: 2021.09

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: dunfell
| Release Tag: 08.02.00.006
| 

.. rubric:: meta-psdkla

| Head Commit: 5560e99ab3ffe0b67e1e5298ff4694ab3860325f recipes-demo: wifi-oob: Disable Station mode by default
| Date: 2022-03-22

| Clone: git://git.ti.com/jacinto-linux/meta-psdkla.git
| Branch: master
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

    LCPD-24644,weston service takes a long time to terminate
    LCPD-24308,linux/Documentation/devicetree/bindings/sound/davinci-mcasp-audio.txt Convert to YAML
    LCPD-23019,OPTEE tests are failing (Impact 5)
    LCPD-24586,am65 uboot usbhost custom builds are missing in 8.1
    LCPD-24450,"j721e-idk-gw, j7200-evm UART tests fail (Impact 3.0)"
    LCPD-24417,AM654x UART Boot Mode failing
    LCPD-24284,DRM tests fail due to crash in panel_simple_probe
    LCPD-24289,ICSSG Ethernet Docs Broken link to ICSS Eth docs
    LCPD-22962,IPC performance- IPC_S_FUNC_PRU_ECHO test failing
    LCPD-22953,v4l2 cal compliance test fails
    LCPD-24526,"k3-am65-iot2050 have mcasp nodes with missing required properties "
    LCPD-24486,smatch reports potential dereference of ERR_PTR
    LCPD-20691,AM65xx - lcd backlight scenario not enabled (Impact 1)
    LCPD-18270,Ivi shell test fails. Lib ivi-controller.so and other components are missing from the file system
    LCPD-16664,MMU Alloc errors and Kernel Oops with RT build
    LCPD-24605,ICSSG: Not all TX timestamps are received

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

    LCPD-25014	, ramfs boot fails when using tisdk-base-image
    LCPD-24716	, am654: Module pruss_soc_bus is missing

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

    LCPD-19447,DSS: Disabling a layer connected to Overlay may result in synclost during the next frame,,i2097
    LCPD-17788,PCI-Express: GEN3 (8GT/s) Operation Not Supported.,,i2104
    LCPD-17783,USB: USB2PHY Charger Detect is enabled by default without VBUS presence,,i2075
    LCPD-14184,USB:  SuperSpeed USB Non-Functional,,i2028
    LCPD-14579,DSS : DSS Does Not Support YUV Pixel Data Formats,,i2000

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
    LCPD-19858,OE: OPTEE label used in SDK is old and wrong,
    LCPD-18908,GLMark2 fails for am65x,
    LCPD-17449,libasan_preinit.o is missing in devkit,
    LCPD-17413,QT Webengine-based browser: the mouse does not work within the web page with QPA EGLFS,
    LCPD-17412,QT5 Webengine-based browser crashing with any resize operation,
    LCPD-14254,meta-ti: Need a recipe update to pick up the new AM65x PRU Ethernet firmwares,
    LCPD-13817,Qt5 Webengine-based broswer does not work on AM654x with pagesize = 64k,
    LCPD-13816,Chromium-wayland broswer does not work on AM654x with page size = 64k,

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

    LCPD-22975,AM654x: 1Ghz & beyond caused boot hang on SR2.0,
    LCPD-24628,am654x-idk DFU boot is failing,
    LCPD-17770,U-Boot: Fix order of MCU R5 shutdown depending on cluster mode,
    LCPD-16524,Need to adjust RMW bit when using enabling ECC,None
    LCPD-14843,"U-boot should support  default settings for netboot ",None
    LCPD-24717,am654: PCI-E ethernet interface shows link down in U-Boot,
    LCPD-24130,AM654x: USB MSC boot mode fails,
    LCPD-16696,U-Boot does not recognize SD-Card after re-insert/change,
    LCPD-15873,There is no dtbo in u-boot for PCIe x1 + usb3 daughter card,None
    LCPD-25535,UBoot: customized ${optargs} doesn't take affect on K3 devices,

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

    LCPD-17471,device hang when restarting crashed R5F,
    LCPD-25314,ICSSG: Timestamp for back-to-back with IPG < 100us not received,
    LCPD-13653,am65x-evm could not boot from MMC/SD when MMC/SD is backup boot mode,No workaround
    LCPD-24539,am654x-evm CAL test fails on PG2.0 boards,
    LCPD-24456,Move IPC validation source from github to git.ti.com,
    LCPD-22931,RemoteProc documentation missing,
    LCPD-16534,remoteproc/k3-r5f: PDK IPC echo_test image fails to do IPC in remoteproc mode on second run,None
    LCPD-24798,"j721e-idk-gw, j7200-evm UART tests fail (Impact 3.0)",
    LCPD-24541,am65xx OSPI boot does not work,
    LCPD-24199,"AM654x UART HWFLOW FUNC, PERF, STRESS tests fail (Impact 2)",
    LCPD-22916,CSI: Interface Setup/Hold Timing Does Not Meet MIPI DPHY Spec above 600MHz,
    LCPD-22892,icssg: due to FW bug both interfaces has to be loaded always,
    LCPD-20683,am65xx fails emmc boot,
    LCPD-19923,[AM65x] Linux reboot command fails,https://e2e.ti.com/support/processors-group/processors/f/processors-forum/1011070/am6548-linux-reboot-command-fails
    LCPD-19861,ICSSG: Unregistered multicast MAC packets are still visible in non-promiscuous mode,
    LCPD-19859,ETH ICSSG netperf benchmark returns lower performance than expected,
    LCPD-19580,am654- unable to select a mode (sdhci?),
    LCPD-18665,Am65x Pg2: Board cannot do soft reboot when booting from SD card,
    LCPD-18289,pcie-usb tests sometimes fail,
    LCPD-18228,PCI PM runtime suspend is not increasing,
    LCPD-17908,ICSSG: dual-emac: udp packets ocassionally sent out of order on egress,
    LCPD-17800,CPSW: Master/Slave resolution failed message seen at console,
    LCPD-16048,UDP iperf with smaller packet sizes < 512 bytes does not complete consistently,
    LCPD-15540,uvc-gadget results in segmentation fault,
    LCPD-13938,"PCIe EP read/write/copy test failed with larger sizes ",
    LCPD-13936,Uboot dhcp timeout 1 of 100 times,
    LCPD-13603,One board could not boot rootfs from more than one SDHC card,
    LCPD-13445,Seldom kernel oops triggered by prueth_netdev_init,
    LCPD-19929,Industrial protocols documentation,
    LCPD-18860,isolcpus in the command line is not honored,
    LCPD-18684,"syscalls sync failures: fdatasync03, fsync04, sync03, syncfs01, sync_file_range02",
    LCPD-18258,IPSEC perfomance failures,
    LCPD-17798,2020 LTS: INTA/INTR smp_affinity failure and IRQ allocation issues.,
    LCPD-17777,AES HW is not exercised,
    LCPD-17673,No software documentation for the Timer module,
    LCPD-16845,OPP freq update in DT impacts only cluster0,
    LCPD-13410,Reboot command is not operational,
    LCPD-24134,AM654x CAL DMABUF tests fail (Impact 4.0),
    LCPD-22954,DRM Stress Test fails,
    LCPD-22947,Alsa performance test fails,
    LCPD-18297,AM6: OV5640: 176x144 does not work,
    LCPD-15819,"tidss: the driver should reject dual-display setup, as it is not supported",
    LCPD-20014,"remoteproc: TX_PRU: IRQ vring, IRQ kick not found error message on console",
    LCPD-25348,nslookup time out when EVM has multiple eth connections,
    LCPD-22959,UART Read/Write tests at baud rate 115200 fails,
    LCPD-25252,"Docs: OPTEE SDK documentation is very minimal ",
    LCPD-24718,am654x hwspinlock test failing,
    LCPD-24680,missing document how to boot to Linux prompt in USB MSC boot mode,
    LCPD-24319,am654x-evm DRM tests fail due to frequency mismatch (Impact 7),
    LCPD-23008,AM65xx - display port scenario not enabled,
    LCPD-23007,k3-am654-evm-hdmi.dtbo file is missing in CoreSDK for am654x,

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

No known issues

|

Change Requests
===============

.. csv-table::
   :header: "ID", "Head Line", "Original Fix Version", "New Fix Version"
   :widths: 20, 90, 20, 20

    JACINTOREQ-1431 ,Descope all non ETHERNET functionality inside PRU-ICSS subsystem, 08.00.00 ,None

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
