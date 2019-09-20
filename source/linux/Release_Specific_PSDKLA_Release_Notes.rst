************************************
Release Notes
************************************

Overview
========

The **Processor Software Development Kit (Processor-SDK) for Linux Automotive**
provides a fundamental software platform for development, deployment and
execution of Linux based applications and includes the following:

-  Bootloaders, Linux Kernel & Filesystem
-  SDK installer
-  Setup scripts
-  Demo applications
-  Documentation

.. Note::
    For building some of the RTOS based demos, you should also download
    Processor SDK RTOS Automotive (PSDKRA) installer. For more information,
    refer to <PSDKRA install path>/index.html


Licensing
=========

Please refer to the software manifest, which outlines the licensing
status for all packages included in this release. The manifest can be found on the SDK
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


Supported Platforms
=====================================
See `here <Release_Specific_Supported_Platforms_and_Versions.html>`__ for a list of supported platforms and links to more information.


Release 06.00.01.00
===================

Released september 2019


What's New
----------
N/A: First SDK release


Release features
----------------

- R5 SPL:

  - Early booting of MCU R5F and MainSS R5F's
  - Bootstrapping 2nd stage boot loader (u-boot) on A72
  - Hyperflash support, UART boot, OSPI boot support.


- A72 U-boot:

  - Early booting of remote cores (C7x, C66x, Main subsystem R5F's) with configurable order of boot-strapping
  - Support for booting both compressed and uncompressed kernel image
  - Basic HYP mode support - boots up uboot in EL2 privileged mode
  - Hyperflash support, OSPI support, MMCSD support
  - SD card boot, hyperflash boot support


- Kernel:

   Kernel image includes support for the following drivers

  - MMC support
  - I2C support
  - CPSW2G Ethernet driver
  - UART driver, UART console support
  - USB driver with support for device/host mode of operation
  - PCIe Root Complex  and Endpoint drivers


- Graphics:

  - Support for OpenGL |reg| ES 1.x, OpenGL |reg| ES 2.0 and OpenGL |reg| ES 3.2 APIs
  - Weston window composition with GPU acceleration support
  - DRM-based display backend
  - Offscreen rendering mode support
  - DMABUF buffer import support


- IPC:

  - IPC support between

    - A72 to C7x
    - A72 to each C66x core
    - A72 to each MainSS R5F core
    - A72 to each MCU island R5F core

  - Support for IPC in both IPC-only mode (core loaded by u-boot) and remoteproc mode (core loaded by Linux Kernel)
  - Mailbox and H/W spinlock support


- Multimedia:

  - Gstreamer-based video decode plugin for H.264 & H.265/HEVC formats
  - Support for decode resolutions up to 4K\@60fps
  - Support for decoding NV12/NV16 pixel formats
  - Support for 8-bit and 10-bit pixel depths
  - Support for decoding streams with 'B' Frames


- Display:

  - DSS support for cropping, scaling, gamma correction, per-pixel blending and global alpha blending
  - DSS support for Color Space Conversion (CSC) and Color Phase Rotation (CPR)
  - DRM API support
  - Support for NV12, UYVY, and XRGB888 data
  - Static partitioning of DSS resources and using video pipelines on shared videoport
  - Display sharing support - shared same display output from Linux(A72) and RTOS(R5) with isolation support


- Audio:

  - Audio playback and Audio record support at 48 KHz, 24 bits per sample
  - Stereo and Multichannel support
  - Multicodec support
  - McASP: Master and slave mode support


- Virtualisation:

  - Jailhouse hypervisor support
  - Static system paritioning: VM config illustration with IVI and Cluster VMs for cockpit Use case
  - IO isolation between VMs
  - PVU and SMMU backed IO isolation support
  - SMMU emulation in Jailhouse hypervisor


- Demos:

  - Integrated cockpit with jailhouse hypervisor

    - IVI VM with Multimedia playback and GPU accelerated windowing system, graphics application
    - Cluster VM with 2D cluster application with CAN data from R5(RTOS)
    - Tell-tales from R5(RTOS)
    - Safety isolation for tell-tales: IVI VM, Cluster VM crash does not impact R5 tell-tale application
    - VM isolation: IVI VM crash does not impact the Cluster application(Cluster VM, Tell-tale from R5)


Component versions
------------------
.. csv-table::
   :header: "component", "version"
   :widths: 40,40

   Linux Kernel, 4.19.59
   U-boot, 2019.01+
   Wayland, 1.16.0
   Weston, 5.0 
   Gstreamer, 1.0_1.14.4
   Jailhouse, 0.10


Issues Tracker
===============

Issues fixed in this release
----------------------------
.. csv-table::
   :header: "Record ID", "Summary"
   :widths: 20, 80

   LCPD-14623,Graphics demo - triangle fails with pvSrc invalid in PVRSRVDeviceMemCopy() error
   LCPD-16122,DP: HPD interrupt doesn't happen every time
   LCPD-16349,OSPI mtd node could not be attached to ubi
   LCPD-16351,U-boot: eMMC boot fails with some boards
   LCPD-16352,U-boot: eMMC UDA boot finds images in boot0 partition
   LCPD-16420,J7: Fix the trng interrupt number
   LCPD-16489,[um]: Fix freeing of the string literal error
   LCPD-16511,J7ES: Environment can't be accessed in U-boot
   LCPD-16528,u-boot: virtID setting for DSS is not reflected correctly
   LCPD-16529,Jailhouse: Display shows blank screen from inmate cell
   LCPD-16537,K3: Fix gic-its unit-node addresses for 2019 LTS
   LCPD-16549,DP: DP connector power is not enabled
   LCPD-16563,Jailhouse: Hypervisor memory not isolated from DMA accesses
   LCPD-16564,Jailhouse: Display continues to access memory even after cell destroy
   LCPD-16574,"J7ES: USB: client: mass storage breaks when port is ""otg"""
   LCPD-16581,J7ES: USB: host: type-C device plugged before board powered is not detected
   LCPD-16586,DP: HDP IRQ handling has a race and is overly complex
   LCPD-16607,KS3: CPSW2G: kernel crashes during netif down
   LCPD-16608,K3: CPSW2G: hw stuck on netif down under high ingress traffic pressure
   LCPD-16629,PCIe EP: MSI interrupt tests fail and dut hangs for pci_endpoint_test.0 when 6PF are configured
   LCPD-16654,GBenchmark is not able to run on j721e libgbm.so.2 is missing
   PSDKLA-4906,Processor SDK Linux Getting Started Guide clean up
   PSDKLA-4965,Tell tale doesn't update with IVI VM crash

Errata workarounds
------------------
None


Open Defects
------------
.. csv-table::
   :header: "Record ID", "Summary"
   :widths: 20, 80

   LCPD-15855,Kernel Oops seen with debug options enabled
   LCPD-15870,CPU Hot plug - cannot offline cpu1
   LCPD-15902,DSS7: Kernel oops seen when an invalid pixel clock (=0) is returned
   LCPD-16024,DSS7: Driver does not check for unsupported pixel clock as per HW limit 
   LCPD-16120,"DP: Link fails right after link training, unless voltage swing is 2 or 3"
   LCPD-16121,DP: Videomodes that exceed the link bandwidth need to be rejected
   LCPD-16130,Exception triggered by drm_dev_unregister during poweroff
   LCPD-16192,/usr/share/jailhouse/linux-demo.sh does not work out-of-the-box
   LCPD-16208,FIFO Underflows during video playback on 4k panel
   LCPD-16366,PVR crashes while running some KICKSYNC_SYNCCONTEXTLOOP tests
   LCPD-16376,Uboot: fatwrite see Error: allocating new dir entry
   LCPD-16377,Uboot eMMC read/write failed on big size (512M)
   LCPD-16384,Seldom memory translation fault 
   LCPD-16401,J721e USB Device does not enumerate after switching to host role
   LCPD-16451,"DP: if cable is not connected, DPCD transactions mess up the driver"
   LCPD-16454,DSS underflows with 1080p/2.5k display on inmate cell
   LCPD-16505,"Wrong clock rate is reported for 157:400, 157:401 (HSDIVIDER after PLL4 and 15)"
   LCPD-16520,J721e: (if otg) USB device mode does not work when behind a USB HUB
   LCPD-16531,video decode: warnings at end of bbb hevc playback to kmssink
   LCPD-16535,remoteproc/k3-dsp: PDK IPC echo test binaries fails to do IPC in remoteproc mode on second run
   LCPD-16545,remoteproc/k3-r5f: PDK IPC echo_test image fails to boot up in remoteproc mode on second run
   LCPD-16546,Some MMCSD cards could not be enumerated with error -110
   LCPD-16573,SA2UL not handling partial update tests
   LCPD-16575,J7ES: USB: client: doesn't work in one plug orientation when dr_mode=otg
   LCPD-16580,J7 DP: error handling in probe is broken
   LCPD-16582,J7ES: USB: client: mass storage disconnects during super-speed transfers
   LCPD-16591,PCIe wifi ping stress test failed
   LCPD-16599,WIZ driver memleak 
   LCPD-16602,eMMC stress tests failed on J7
   LCPD-16605,MMC: MMC1/2 Speed Issue
   LCPD-16609,Hyperflash boot sometimes do not work
   LCPD-16610,"DP driver reports ""No supported color_format found"""
   LCPD-16628,Could not enumerate PLEXTRO pcie SSD
   LCPD-16641,tidss: need to ensure the output width is divisible by 2
   LCPD-16836,DP: GeChic display EDID read failures
   LCPD-16840,DP error handling is broken
   LCPD-16841,DP: Link training problem
   LCPD-16854,Could not bind pci_epf_test to EP controller when DMA is disabled
   LCPD-16909,"Linux performance guide:  CPU load is not captured, incorrect throughput numbers for ethernet "
   LCPD-16911,Linux performance guide: Crypto benchmark numbers: fix unit and accompanying description
   PSDKLA-4953,[PSDKLA release Document] Document bugs & enhancements been reported from field

Known issues & limitations
--------------------------
.. csv-table::
   :header: "Record ID", "Summary" , "Workaround"
   :widths: 20, 80, 60

   LCPD-16396, J721E: RC: Unsupported request in configuration completion packets results in an abort, Workaround for Multifunction: Configure all the physical functions supported by the endpoint.

|


.. rubric:: Installation and Usage
   :name: installation-and-usage

The `Software Developer's Guide <index.html>`__ provides instructions on how to setup up your Linux development
environment, install the SDK and start your development.  It also includes User's Guides for various Example Applications and Code
Composer Studio.

| 

.. rubric:: Host Support
   :name: host-support

For the specific supported hosts for current SDK, see `Supported Platforms <Release_Specific_Supported_Platforms_and_Versions.html>`__


.. note::
   Processor SDK Installer is 64-bit, and installs only on 64-bit host
   machine. Support for 32-bit host is dropped as Linaro toolchain is
   available only for 64-bit machines


.. |reg| unicode:: U+00AE .. REGISTERED SIGN
