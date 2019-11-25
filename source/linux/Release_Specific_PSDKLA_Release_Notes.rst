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
    For building some of the RTOS-based demonstrations, you should also download
    Processor SDK RTOS Automotive (PSDKRA) installer. For more information,
    refer to <PSDKRA install path>/index.html.


Licensing
=========

Please refer to the software manifest, which outlines the licensing
status for all packages included in this release. The manifest can be found on the SDK
download page or in the installed directory as indicated below. In
addition, see `Processor SDK Linux GPLv3 Disclaimer <Overview_GPLv3_Disclaimer.html>`__.


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


Release 06.01.00.05
===================
Released October 2019


What's New
----------

-  R5 SPL:

   -  eMMC HS400 mode support
   -  eMMC boot support
-  A72 U-boot:

   -  USB Host and mass storage support
   -  Support for DFU download to SD card, eMMC, OSPI
   -  UFS support
   -  eMMC boot support
-  Kernel:

   -  CPSW9G Virtual driver
   -  USB gadget driver support

      -  Composite device
      -  Multifunction composite device
   -  USB DRD dual role support
   -  Support for dual voltage SD cards (UHS mode)
   -  PCIe backplane support
   -  PCIe Gen3 2xlane support
   -  eMMC HS400 speed mode support
   -  UART DMA mode support
   -  UFS support
   -  ADC basic functionality
   -  Crypto acceleration support for AES, 3-DES, and RNG
-  Graphics:

   -  Support for GPU virtualization (GPU to be used by multiple VMs)
   -  Support for YUV texture formats
   -  Support for GPU profiling tools (PVRTrace and PVRTune)
-  Multimedia:

   -  Decoder:

      -  Support for multi channel decoding in driver and gstreamer
      -  Support for MJPEG and JPEG Image decoder
      -  Gstreamer plugin support for wayland sink
      -  Support for video decoder error recovery
      -  Support for interlaced video decode
   -  Encoder:

      -  Driver support for H.264 video encoder with NV12, 8 bit content
      -  Driver support for multi channel encoding
-  Audio:

   -  Multi-codec support with separate serializer per codec
-  Demos:

   -  Integrated cockpit with jailhouse hypervisor

      -  GPU usage by cluster VM for dials and needles rendering

Release features
----------------

-  R5 SPL:

   -  Early booting of MCU R5F and MainSS R5F's
   -  Bootstrapping 2nd stage boot loader (u-boot) on A72
   -  Hyperflash support, UART boot, OSPI boot support.
-  A72 U-boot:

   -  Early booting of remote cores (C7x, C66x, Main subsystem R5F's) with configurable order of boot-strapping
   -  Support for booting both compressed and uncompressed kernel image
   -  Basic HYP mode support - boots up uboot in EL2 privileged mode
   -  Hyperflash support, OSPI support, MMCSD support
   -  SD card boot, hyperflash boot support
-  Kernel: Kernel image includes support for the following drivers

   -  MMC support
   -  I2C support
   -  CPSW2G Ethernet driver
   -  UART driver, UART console support
   -  USB driver with support for device/host mode of operation
   -  PCIe Root Complex  and Endpoint drivers
-  Graphics:

   -  Support for OpenGL |reg| ES 1.x, OpenGL |reg| ES 2.0 and OpenGL |reg| ES 3.2 APIs
   -  Weston window composition with GPU acceleration support
   -  DRM-based display backend
   -  Offscreen rendering mode support
   -  DMABUF buffer import support
-  IPC:

   -  IPC support between

      -  A72 to C7x
      -  A72 to each C66x core
      -  A72 to each MainSS R5F core
      -  A72 to each MCU island R5F core
   -  Support for IPC in both IPC-only mode (core loaded by u-boot) and remoteproc mode (core loaded by Linux Kernel)
   -  Mailbox and H/W spinlock support
-  Multimedia:

   -  Gstreamer-based video decode plugin for H.264 & H.265/HEVC formats
   -  Support for decode resolutions up to 4K\@60fps
   -  Support for decoding NV12/NV16 pixel formats
   -  Support for 8-bit and 10-bit pixel depths
   -  Support for decoding streams with 'B' Frames
-  Display:

   -  DSS support for cropping, scaling, gamma correction, per-pixel blending and global alpha blending
   -  DSS support for Color Space Conversion (CSC) and Color Phase Rotation (CPR)
   -  DRM API support
   -  Support for NV12, UYVY, and XRGB888 data
   -  Static partitioning of DSS resources and using video pipelines on shared videoport
   -  Display sharing support - shared same display output from Linux (A72) and RTOS (R5) with isolation support
-  Audio:

   -  Audio playback and Audio record support at 48 KHz, 24 bits per sample
   -  Stereo and Multichannel support
   -  Multi-codec support
   -  McASP: Master and slave mode support
-  Virtualisation:

   -  Jailhouse hypervisor support
   -  Static system partitioning: VM config illustration with IVI and Cluster VMs for cockpit Use case
   -  IO isolation between VMs
   -  PVU and SMMU backed IO isolation support
   -  SMMU emulation in Jailhouse hypervisor
-  Demos:

   -  Integrated cockpit with jailhouse hypervisor

      -  IVI VM with Multimedia playback and GPU accelerated windowing system, graphics application
      -  Cluster VM with 2D cluster application with CAN data from R5 (RTOS)
      -  Tell-tales from R5 (RTOS)
      -  Safety isolation for tell-tales: IVI VM, Cluster VM crash does not impact R5 tell-tale application
      -  VM isolation: IVI VM crash does not impact the Cluster application (Cluster VM, Tell-tale from R5)

Component versions
------------------

.. csv-table::
   :header: "component", "source", "branch", "version"
   :widths: 20,40,20,30

   arm-trusted-firmware,git://git.ti.com/atf/arm-trusted-firmware.git,ti-atf,ce3f1512bfc3f346900178c5ef870fbef3ab205e
   optee-os,git://git.ti.com/optee/ti-optee-os.git,ti-optee-os,e5a8779a6ffa2aa7ad01aed43608bcb9321817c6
   U-boot,git://git.ti.com/ti-u-boot/ti-u-boot.git,ti-u-boot-2019.01,66126341c8f50129c6be051ef368cf12643eaccc
   Linux Kernel,git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git,ti-linux-4.19.y,0cabba2b47949524cacbb68678767307a4f0a23e
   Jailhouse,git://git.ti.com/jailhouse/ti-jailhouse.git,ti-jailhouse-0.10,b3a68ac89d7ed955546eae91954b184ec1583ce3


Issues Tracker
===============

Issues fixed in this release
----------------------------
.. csv-table::
   :header: "Record ID", "Summary"
   :widths: 20, 80

   LCPD-15991,remoteproc/k3-r5: remoteproc elf download crashes at memset for MSMC address 0x70020000
   LCPD-16180,J7: PCIe: Sparse warning from 0-day builder
   LCPD-16192,/usr/share/jailhouse/linux-demo.sh does not work out-of-the-box
   LCPD-16352,U-boot: eMMC UDA boot finds images in boot0 partition
   LCPD-16358,Gstreamer video displayed with extra lines at bottom
   LCPD-16376,Uboot: fatwrite see Error: allocating new dir entry
   LCPD-16384,Seldom memory translation fault 
   LCPD-16401,J721e USB Device does not enumerate after switching to host role
   LCPD-16520,J721e: (if otg) USB device mode does not work when behind a USB HUB
   LCPD-16521,USB gadget: Controller/Linux locks up on bulk stall
   LCPD-16526,J7ES: USB: client: limiting the controller to full-speed in DT doesn't work
   LCPD-16546,Some MMCSD cards could not be enumerated with error -110
   LCPD-16547,DP: EDID reading fails
   LCPD-16575,J7ES: USB: client: doesn't work in one plug orientation when dr_mode=otg
   LCPD-16602,eMMC stress tests failed on J7
   LCPD-16605,MMC: MMC1/2 Speed Issue
   LCPD-16606,"J7ES: DMA: ring reset is missed when !ti,dma-ring-reset-quirk"
   LCPD-16609,Hyperflash boot sometimes do not work
   LCPD-16648,Weston is not starting
   LCPD-16657,Removing sa2ul module on j721e causes omap-rng driver crash or failures printed
   LCPD-16658,"U-Boot: J7ES: DMA: ring reset is missed when !ti,dma-ring-reset-quirk"
   LCPD-16922,rogue: DMA-API warning from rgx_blit_test
   LCPD-16923,rgx: nulldrmws missing libglslcompiler.so symlink 
   LCPD-16931,K3 wic disk-images missing essential files in boot partition
   LCPD-16933,[Cpsw9g][VirtualDriver][VirtualMAC] integrated tree merge of the connectivity tree had a build error
   LCPD-16940,Android: Fastboot bootloader read/write from UDA failure
   LCPD-16979,Crash with H.264 4k test stream using standalone test
   LCPD-17003,[ti:ti-linux-4.19.y 8109/8113] drivers/gpu//drm/tidss/tidss_wb_m2m.c:256:1: warning: the frame size of 1280 bytes is larger than 1024 bytes
   LCPD-17004,[ti:ti-rt-linux-4.19.y 8609/8615] drivers/gpu/drm/tidss/tidss_wb.h:77:6: error: nested redefinition of 'enum wb_state'
   LCPD-17009,pcm3168a codec produces noise when playing back (unsupported) S32_LE in RIGHT_J mode
   LCPD-17024,v4l2 decoder driver memory leaks
   LCPD-17026,"ERROR: ""sha512_zero_message_hash"" [drivers/crypto/sa2ul.ko] undefined!"
   LCPD-17027,McASP: Occasional error interrupt when stopping (playback) stream
   LCPD-17050,j721e: Audio: Unsupported sampling rates are advertised and can be request (which will fail)
   LCPD-17078,J721e: Nightly builds missing dtb for Alpha boards
   LCPD-17105,UDMA: rchan's rflowid_cnt and rflowid_start needs to be reset when extra flow are not used
   LCPD-17109,J7ES: USB: super-speed doesn't work on alpha EVM
   LCPD-17111,vxe_enc_probe warning observed while booting with debug options enabled
   LCPD-17112,remoteproc/k3-r5: Kernel oops seen sometimes while loading remote proc
   LCPD-17135,U-boot: J7: scsi write fails for greater than 32 MB
   LCPD-17143,DSS7: j721e-dss has wrong scaling limitiations (copied from am6-dss)
   LCPD-17158,Jailhouse: Cannot boot with jailhouse DTBO on J721E alphaEVM
   LCPD-17161,k3: cpsw2g: Network core TX watchdog will be triggered periodically when link in manual mode
   LCPD-17165,remoteproc/k3-r5f: loading into TCM at 0x41010000 fails
   LCPD-17170,remoteproc/k3-dsp: memset causes a kernel panic when zeroing out C66 DSP internal RAMs
   LCPD-17184,PDK-IPC firmware images missing from 2019.04-rc3
   LCPD-17211,OSPI boot is broken in 2019.04-rc3
   LCPD-17220,U-Boot Hyperbus: Hyperflash reads limited to 125MHz max. frequency
   LCPD-17281,Hyperflash tests in kernel failed with display-sharing firmware
   PSDKLA-4990,CCB Stalls are seen in guest VM when running heavy graphics apps
   PSDKLA-4999,Update rc.pvr to load the VM version of the pvrsrvkm module

Errata workarounds
------------------
None


Open Defects
------------
.. csv-table::
   :header: "Record ID", "Summary", "Workaround"
   :widths: 20, 80, 60

   LCPD-16120,"DP: Link fails right after link training, unless voltage swing is 2 or 3",
   LCPD-16130,Exception triggered by drm_dev_unregister during poweroff,
   LCPD-16208,FIFO Underflows during video playback on 4k panel,
   LCPD-16366,RGX kick test fails when 32 sync dependencies are set for each command,
   LCPD-16377,Uboot eMMC read/write failed on big size (512M),
   LCPD-16505,"Wrong clock rate is reported for 157:400, 157:401 (HSDIVIDER after PLL4 and 15)",
   LCPD-16531,video decode: vxd_dec warnings displayed at end of gstreamer hevc playback to kmssink for certain video,
   LCPD-16535,remoteproc/k3-dsp: PDK IPC echo test binaries fails to do IPC in remoteproc mode on second run,
   LCPD-16545,remoteproc/k3-r5f: PDK IPC echo_test image fails to boot up in remoteproc mode on second run,
   LCPD-16591,PCIe wifi ping stress test failed,
   LCPD-16599,WIZ driver memleak on module unload,
   LCPD-16616,Jailhouse: Failure in mhdp probe while restarting the Linux VM,
   LCPD-16628,Could not enumerate PLEXTRO pcie SSD,
   LCPD-16640,PCIe RC: GIC ITS misbehaves when more than 4 devices use it simultaneously,
   LCPD-16836,DP: GeChic display EDID read failures,
   LCPD-16840,DP driver error handling is missing proper cleanups,
   LCPD-16909,"Linux performance guide:  CPU load is not captured, incorrect throughput numbers for ethernet ",
   LCPD-16921,GPU driver doesn't unregister genpd name on unload,
   LCPD-17006,4k DP Display Shows Blank Screen sometimes when booting,
   LCPD-17010,J7ES: USB: gadget mode breaks with PC host with USB3.0 LPM,
   LCPD-17084,tidss: page-flip race issue with very heavy use cases,
   LCPD-17171,Uboot dhcp occasionally failed,
   LCPD-17229,vxd_dec: kernel crash if rootfs has no pvdec_full_bin.fw firmware file,
   LCPD-17236,PDK-IPC build from sources is not creating stripped images and links,
   LCPD-17253,g_multi seems hanging when usbdev is full-speed/high-speed,
   LCPD-17284,remoteproc/k3-r5: Cores are started out-of-order when core 0 file size >> core 1 file size,
   LCPD-17286,PCIe EP stress test failed with large number of EP functions,
   LCPD-17291,PTP with CPSW failing to synchronize on J7,
   LCPD-17292,CDC ACM has problem after multiple modprobe,
   LCPD-17300,J7: possible memleak in DP PHY driver,
   LCPD-17316,U-boot: J7es: gpios above 32 don't work with the da8xx_gpio.c driver,
   PSDKLA-4991,PVRTune doesn't run on guest VM,
   PSDKLA-5002,Video playback crashes on continuous playback with VM,
   PSDKLA-5005,Multimedia decode application causes kernel crash after first run with VM,

Known issues & limitations
--------------------------
.. csv-table::
   :header: "Record ID", "Summary" , "Workaround"
   :widths: 20, 80, 60

   LCPD-16396, J721E: RC: Unsupported request in configuration completion packets results in an abort, Workaround for Multifunction: Configure all the physical functions supported by the endpoint.

|


.. rubric:: Installation and Usage
   :name: installation-and-usage

The `Software Developer's Guide <index.html>`__ provides instructions on how to setup your Linux development environment, install the SDK and start your development. It also includes User's Guides for various Example Applications.

|

.. rubric:: Host Support
   :name: host-support

For the specific supported hosts for current SDK, see `Supported Platforms <Release_Specific_Supported_Platforms_and_Versions.html>`__.


.. note::
   Processor SDK Installer is 64-bit, and installs only on 64-bit host
   machine. Support for 32-bit host is dropped as Linaro toolchain is
   available only for 64-bit machines.


.. |reg| unicode:: U+00AE .. REGISTERED SIGN
