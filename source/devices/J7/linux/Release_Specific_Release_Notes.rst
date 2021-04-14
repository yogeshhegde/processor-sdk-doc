.. _release-specific-release-notes:

************************************
Release Notes
************************************

Overview
========

The **Processor Software Development Kit (Processor-SDK) for Linux**
provides a fundamental software platform for development, deployment and
execution of Linux based applications and includes the following:

-  Bootloaders, Linux Kernel & Filesystem
-  SDK installer
-  Setup scripts
-  Demo applications
-  Documentation

.. Note::
    For building some of the RTOS-based demonstrations, you should also download
    Processor SDK RTOS installer. For more information,
    refer to <PSDKRA install path>/index.html.


Licensing
=========

Please refer to the software manifest, which outlines the licensing
status for all packages included in this release. The manifest can be found on the SDK
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


Supported Platforms
=====================================
See :ref:`here <release-specific-supported-platforms-and-versions>` for a list of supported platforms and links to more information.


Release 07.03.00
================
Released April 2021


What's New
----------
- Final release on 2020 LTS 5.4 kernel
- J721E HS ES 1.0 Support (does not support J721E HS ES 1.1)
- Support for H.264 video decoder

Release features
----------------

-  R5 SPL:

   -  Early booting of MCU R5F and Main R5FSS Core0
   -  Bootstrapping 2nd stage boot loader (u-boot) on A72
   -  UART boot, OSPI boot support.
   -  eMMC HS400 mode support
   -  eMMC boot support
-  A72 U-boot:

   -  Early booting of remote cores (C7x, C66x, Main subsystem R5F's) with configurable order of boot-strapping
   -  Support for booting both compressed and uncompressed kernel image
   -  Basic HYP mode support - boots up uboot in EL2 privileged mode
   -  OSPI support, MMCSD support
   -  SD card boot support
   -  USB Host and mass storage support
   -  Support for DFU download to SD card, eMMC, OSPI
   -  UFS support
   -  eMMC boot support
-  Kernel: Kernel image includes support for the following drivers

   -  MMC support
   -  I2C support
   -  CPSW2G Ethernet driver
   -  UART driver, UART console support
   -  USB driver with support for device/host mode of operation
   -  PCIe Root Complex  and Endpoint drivers
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

   -  Support for OpenGL |reg| ES 1.x, OpenGL |reg| ES 2.0 and OpenGL |reg| ES 3.2 APIs
   -  Weston window composition with GPU acceleration support
   -  DRM-based display backend
   -  Offscreen rendering mode support
   -  DMABUF buffer import support
   -  Support for YUV texture formats
   -  Support for GPU profiling tools (PVRTrace and PVRTune)
-  IPC:

   -  IPC support between

      -  A72 to C7x
      -  A72 to each C66x core
      -  A72 to each MainSS R5F core
      -  A72 to each MCU island R5F core
   -  Support for IPC in both IPC-only mode (core loaded by u-boot) and remoteproc mode (core loaded by Linux Kernel)
   -  Mailbox and H/W spinlock support
-  Display:

   -  DSS support for cropping, scaling, gamma correction, per-pixel blending and global alpha blending
   -  DSS support for Color Space Conversion (CSC) and Color Phase Rotation (CPR)
   -  DRM API support
   -  Support for NV12, UYVY, and XRGB888 data
   -  Static partitioning of DSS resources and using video pipelines on shared videoport
-  Audio:

   -  Audio playback and Audio record support at 48 KHz, 24 bits per sample
   -  Stereo and Multichannel support
   -  Multi-codec support
   -  McASP: Master and slave mode support
   -  Multi-codec support with separate serializer per codec
-  Profiling

   -  A72 PMU support for Performance profiling

.. _release-specific-sdk-components-versions:

Component versions
------------------

.. csv-table::
   :header: "component", "source", "branch", "version"
   :widths: 20,40,20,30

   arm-trusted-firmware,git://git.ti.com/atf/arm-trusted-firmware.git,ti-atf,65dd16b4ea5032752af62e94ca64cff41733a123
   optee-os,git://git.ti.com/optee/ti-optee-os.git,ti-optee-os,36905c9566936f7502e3741b48015c1f147b3bd3
   U-boot,git://git.ti.com/ti-u-boot/ti-u-boot.git,ti-u-boot-2020.01,2781231a33c3d779e32445f4fe55164c45d6d7c1
   Linux Kernel,git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git,ti-linux-5.4.y,023faefa70274929bff92dc41167b007f7523792


Issues Tracker
===============
..
   project = LCPD AND issuetype = Bug AND status = Closed AND resolution = Done AND component in ("Audio & Display", Baseport, Connectivity, IPC, "Power & Thermal", Graphics, Multimedia, Wireless, "System Integration", Security) AND closedDate > 2020-11-18 AND createdDate <= 2020-11-17 AND (Labels not in (LCPD_K3.14_MAINT, MAINTENANCE, PLSDK_NOT_RN) OR labels is EMPTY) AND OS in (Linux, RT-linux) AND Platform in (j721e-evm, j721e-evm-ivi, j721e-idk-gw, j721e-hsevm) ORDER BY key DESC, priority DESC

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Summary"
   :widths: 20, 80

   LCPD-19818,CPSW2G netperf egress performance lower
   LCPD-19781,OE: ti-rpmsg-char: Library header files and primary so file are missing in FS
   LCPD-19772,ATF/Uboot GTC frequency handover bug
   LCPD-19751,[ti:ti-linux-5.4.y 3067/10775] drivers/pci/endpoint/pci-epf-bus.c:36:34: warning: unused variable 'pci_epf_bus_id_table'
   LCPD-19740,TLS1.2 hangs on handshake
   LCPD-19669,PCI Backplane: Does not work for more than one function 

..
   project = LCPD AND issuetype = Bug AND status = Closed AND resolution = Done AND component in ("Audio & Display", Baseport, Connectivity, IPC, "Power & Thermal", "System Integration", Wireless, Graphics, Multimedia, Security) AND closedDate > 2020-11-18 AND createdDate > 2020-11-18 AND (Labels not in (LCPD_K3.14_MAINT, MAINTENANCE, PLSDK_NOT_RN) OR labels is EMPTY) AND OS in (Linux, RT-linux) AND fixversion not in (Upstream) AND Platform in (j721e-evm, j721e-evm-ivi, j721e-idk-gw, j721e-hsevm) ORDER BY key DESC, priority DESC

Issues found and closed on this release that may be applicable to prior releases
--------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Summary"
   :widths: 20, 80

   LCPD-21348,K3: CPSWxG: can't disable rate limit for TX CPPI channels on Host P0
   LCPD-21327,gstreamer: plugins-good build failure with DDK1.13 update
   LCPD-20642,j721e-idk-gw fails to boot when using the mmcmode custom build
   LCPD-20618,k3: cpswxg: bindings not updated
   LCPD-20524,doc: i2027 errata incorrectly documented as applicable for J721E/J7200.
   LCPD-20388,SPL clk-k3 driver can experience severe rounding error beyond just off-by-one error seen with 166MHz
   LCPD-20299,"Obsolete ti,sci-rm-range-girq usage in Wkup GPIO Interrupt Routers"
   LCPD-20065,Kernel: Scatter-gather DMA missing data at the end of the buffer
   LCPD-19947,remoteproc/k3-dsp: Fix erroneous error check on devm_ioremap_wc()
   LCPD-19946,remoteproc/k3-r5f: Fix couple of warnings

..
   project = LCPD AND Platform in (j721e-evm, j721e-evm-ivi, j721e-idk-gw, j721e-hsevm) AND ErrataID is not EMPTY AND status = Closed AND (Labels not in (PLSDK_NOT_RN) OR labels is EMPTY) ORDER BY priority DESC

Errata workarounds
------------------
.. csv-table::
   :header: "Record ID", "Summary", "Workaround", "ErrataID"
   :widths: 20, 80, 60, 20

   LCPD-19965,OSPI PHY Controller Bug Affecting Read Transactions,,i2189
   LCPD-19068,DSS: Disabling a layer connected to Overlay may result in synclost during the next frame,,i2097
   LCPD-19047,USB: Race condition while reading TRB from system memory in device mode,,i2067
   LCPD-17220,U-Boot Hyperbus: Hyperflash reads limited to 125MHz max. frequency,,i2088
   LCPD-16605,MMC: MMC1/2 Speed Issue,,i2090

..
   project = LCPD AND issuetype = Bug AND (status not in (Closed, "In Build") OR status = Closed AND resolution in ("Known Issue : HW Limitation", "Known Issue : Other")) AND component in ("System Integration", Graphics, Wireless, Security, Multimedia) AND (labels not in (LCPD_K3.14_MAINT, MAINTENANCE, DO_NOT_RELEASE_NOTE, PLSDK_NOT_RN, SKIP_REL_NOTES) OR labels is EMPTY) AND ((affectedVersion <= 07.03.00 AND affectedVersion >upstream ) OR affectedVersion is EMPTY OR affectedVersion not in (Upstream, upstream)) AND Platform in (j721e-evm, j721e-evm-ivi, j721e-idk-gw, j721e-hsevm) AND OS = "Linux" ORDER BY key DESC, priority DESC, component ASC

.. _release-specific-known-issues:

SDK Known Issues
----------------
.. csv-table::
   :header: "Record ID", "Summary", "Workaround"
   :widths: 20, 80, 60

   LCPD-22097,Kernel crash for video file based demo,
   LCPD-21298,Frame Buffer Decompression does not show expected improvement,
   LCPD-20620,J721e: Gstreamer warning seen with video decoder mjpeg test,
   LCPD-19948,Yocto: stream recipe is incorrect,
   LCPD-19894,UYVY texture test fails due to internal data stream error,
   LCPD-19893,RGX GLES3 test fails due to KCCB stall,
   LCPD-19858,OE: OPTEE label used in SDK is old and wrong,
   LCPD-19716,GFX_XS_FUNC_UYVY_TEXTURE test fails,
   LCPD-18851,UYVY texture test needs update,
   LCPD-18270,Ivi shell test fails. Lib ivi-controller.so and other components are missing from the file system,
   LCPD-18115,PVR Error observed while running glmark2,
   LCPD-17387,Underflow and CRTC SYNC LOST observed while running GLMark2 (1x1080p + 1x4k),
   LCPD-17213,Weston sometimes fails to start when booting with nfs filesystem,
   LCPD-16921,GPU driver doesn't unregister genpd name on unload,
   LCPD-16531,video decode: vxd_dec warnings displayed at end of gstreamer hevc playback to kmssink for certain video,
   LCPD-16366,RGX kick test fails when 32 sync dependencies are set for each command,
   LCPD-16130,Exception triggered by drm_dev_unregister during poweroff,

..
   project = LCPD AND issuetype = Bug AND (status not in (Closed, "In Build") OR status = Closed AND resolution in ("Known Issue : HW Limitation", "Known Issue : Other")) AND component in ("Power & Thermal", Baseport, "Audio & Display", Connectivity, IPC) AND (labels not in (LCPD_K3.14_MAINT, upstream, MAINTENANCE, DO_NOT_RELEASE_NOTE, PLSDK_NOT_RN, SKIP_REL_NOTES) OR labels is EMPTY) AND (summary ~ u-boot OR Subcomponent in (u-boot, UBOOT, Uboot)) AND (affectedVersion <= 07.03.00 AND affectedVersion > upstream OR affectedVersion is EMPTY OR affectedVersion not in (Upstream, upstream)) AND Platform in (j721e-evm, j721e-evm-ivi, j721e-idk-gw, j721e-hsevm) ORDER BY key DESC, priority DESC, component ASC

U-Boot Known Issues
-------------------
.. csv-table::
   :header: "Record ID", "Summary", "Workaround"
   :widths: 20, 80, 60

   LCPD-22048,U-Boot: J7/AM64: DDR driver size is bloated up,
   LCPD-21986,j721e U-Boot DDR50 mode cannot be tested using the default image,
   LCPD-20737,Documentation: u-boot documentation issues,
   LCPD-20700,Direction for MCU_RGMII1_TXC pin in for u-boot and Kernel DTB don't match Pinmux tool's output,
   LCPD-20229,U-Boot : HS Boot post Rearch for J721E,
   LCPD-20131,Uboot fails to enumerate devices attached to a usb hub on the first 'usb reset' call ,Re-run usb reset command 
   LCPD-19871,U-boot: Documentation: Combined Boot flow and SPL Rearch,
   LCPD-19776,j7: uboot: some socketed evms fail to boot,
   LCPD-19636,J7: HS: OSPI Boot broken,
   LCPD-17789,UBOOT J7:  Could not see UFS device by scsi scan,
   LCPD-17770,U-Boot: Fix order of MCU R5 shutdown depending on cluster mode,
   LCPD-17523,R5-SPL - Support to dump EEPROM to shared memory,
   LCPD-17406,U-boot: Uboot has no knowledge of memory reserved for remote cores,

..
   project = LCPD AND issuetype = Bug AND (status not in (Closed, "In Build") OR status = Closed AND resolution in ("Known Issue : HW Limitation", "Known Issue : Other")) AND component in ("Audio & Display", Baseport, Connectivity, IPC, "Power & Thermal") AND (affectedVersion <= 07.03.00 AND affectedVersion > upstream OR affectedVersion is EMPTY OR affectedVersion not in (Upstream, upstream)) AND (labels not in (LCPD_K3.14_MAINT, upstream, MAINTENANCE, DO_NOT_RELEASE_NOTE, PLSDK_NOT_RN, SKIP_REL_NOTES) OR labels is EMPTY) AND summary !~ u-boot AND (Subcomponent not in (u-boot, UBOOT, Uboot) OR Subcomponent is EMPTY) AND Platform in (j721e-evm, j721e-evm-ivi, j721e-idk-gw, j721e-hsevm) ORDER BY key DESC, priority DESC, component DESC

Linux Kernel Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Summary", "Workaround"
   :widths: 20, 80, 60

   LCPD-20622,J721e-ivi-evm DSS CRTC0 sync lost error,
   LCPD-20526,Kernel: UBIFS test failing on J721E,
   LCPD-20297,CPSW9G eventually fails to become enumerated,
   LCPD-20290,CPSW Performance regression on j721e-idk-gw,
   LCPD-20240,MMC Modular testcase regression,
   LCPD-19942,"UART tests at certain speeds fail on j7200, j721e",
   LCPD-19822,ARM benchmark testcases returning lower than expected performance,
   LCPD-19792,j721e boot fails sometimes due to EL1 exception,
   LCPD-19659,Doc: PCIe: Update documentation to indicate how to move to compliance mode,
   LCPD-19084,Few SD cards not enumerating in Kernel with Alpha EVM,
   LCPD-19068,DSS: Disabling a layer connected to Overlay may result in synclost during the next frame,
   LCPD-19046,Very low IPSEC throughput,
   LCPD-18980,PCIe: Gen2 capable endpoint devices always enumerate as Gen1,
   LCPD-18935,IPC tests failed on j721e in 07.00 rc5,
   LCPD-18894,J7 failed to boot to kernel occasionally,
   LCPD-18860,isolcpus in the command line is not honored,
   LCPD-18790,eMMC tests failed on J7 rev E2 EVM,
   LCPD-18684,"syscalls sync failures: fdatasync03, fsync04, sync03, syncfs01, sync_file_range02",
   LCPD-18258,IPSEC perfomance failures,
   LCPD-18233,MMC irq affinity to core 1 is not working.,
   LCPD-17814,Kingston 16G card could not boot to uboot prompt,
   LCPD-17798,2020 LTS: INTA/INTR smp_affinity failure and IRQ allocation issues.,
   LCPD-17794,ext4write failed to write firmware to SD card,
   LCPD-17673,No software documentation for the Timer module,
   LCPD-17543,Some cpuhotplug tests failed,
   LCPD-17421,CPSW9G: Can't bring up interface over NFS,
   LCPD-17418,J7 sometimes failed to boot,Flash firmware into mmc rootfs
   LCPD-17387,Underflow and CRTC SYNC LOST observed while running GLMark2 (1x1080p + 1x4k),
   LCPD-17284,remoteproc/k3-r5: Cores are started out-of-order when core 0 file size >> core 1 file size,
   LCPD-17172,Uboot USBhost: Sandisk Extreme USB 3.0 msc stick could not be detected at second time,
   LCPD-17171,Uboot dhcp occasionally failed,
   LCPD-17006,4k DP Display Shows Blank Screen sometimes when booting,
   LCPD-16836,DP: GeChic display EDID read failures with custom DP cable,
   LCPD-16640,PCIe RC: GIC ITS misbehaves when more than 4 devices use it simultaneously,
   LCPD-16628,Could not enumerate PLEXTOR pcie SSD,
   LCPD-16616,Jailhouse: Failure in mhdp probe while restarting the Linux VM,
   LCPD-16591,PCIe wifi ping stress test failed,
   LCPD-16545,remoteproc/k3-r5f: PDK IPC echo_test image fails to boot up in remoteproc mode on second run,
   LCPD-16535,remoteproc/k3-dsp: PDK IPC echo test binaries fails to do IPC in remoteproc mode on second run,
   LCPD-16505,"Wrong clock rate is reported for 157:400, 157:401 (HSDIVIDER after PLL4 and 15)",
   LCPD-16396,J721E: RC: Unsupported request in configuration completion packets results in an abort,"Workaround for Multifunction: Configure all the physical functions supported by the endpoint. For configuring all the 6 functions of PCIe  controller instance '1' in J721E, the following can be used. mount -t configfs none /sys/kernel/config; cd /sys/kernel/config/pci_ep/; mkdir functions/pci_epf_test/func1; echo 0x104c > functions/pci_epf_test/func1/vendorid; echo 0xb00d > functions/pci_epf_test/func1/deviceid; echo 1 > functions/pci_epf_test/func1/msi_interrupts; echo 16 > functions/pci_epf_test/func1/msix_interrupts; ln -s functions/pci_epf_test/func1 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func2; echo 0x104c > functions/pci_epf_test/func2/vendorid; echo 0xb00d > functions/pci_epf_test/func2/deviceid; echo 1 > functions/pci_epf_test/func2/msi_interrupts; echo 16 > functions/pci_epf_test/func2/msix_interrupts; ln -s functions/pci_epf_test/func2 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func3; echo 0x104c > functions/pci_epf_test/func3/vendorid; echo 0xb00d > functions/pci_epf_test/func3/deviceid; echo 1 > functions/pci_epf_test/func3/msi_interrupts; echo 16 > functions/pci_epf_test/func3/msix_interrupts; ln -s functions/pci_epf_test/func3 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func4; echo 0x104c > functions/pci_epf_test/func4/vendorid; echo 0xb00d > functions/pci_epf_test/func4/deviceid; echo 1 > functions/pci_epf_test/func4/msi_interrupts; echo 16 > functions/pci_epf_test/func4/msix_interrupts; ln -s functions/pci_epf_test/func4 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func5; echo 0x104c > functions/pci_epf_test/func5/vendorid; echo 0xb00d > functions/pci_epf_test/func5/deviceid; echo 1 > functions/pci_epf_test/func5/msi_interrupts; echo 16 > functions/pci_epf_test/func5/msix_interrupts; ln -s functions/pci_epf_test/func5 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func6; echo 0x104c > functions/pci_epf_test/func6/vendorid; echo 0xb00d > functions/pci_epf_test/func6/deviceid; echo 1 > functions/pci_epf_test/func6/msi_interrupts; echo 16 > functions/pci_epf_test/func6/msix_interrupts; ln -s functions/pci_epf_test/func6 controllers/d800000.pcie-ep/; echo 1 > controllers/d800000.pcie-ep/start; echo 1 > /sys/bus/pci/devices/0000:00:00.0/remove; echo 1 > /sys/bus/pci/rescan; Workaround for switch card: No workarounds available."
   LCPD-16208,FIFO Underflows during video playback on 4k panel,
   LCPD-16031,J721e: PCIe: Legacy interrupts do not work,

|

Past Release Descopes
=====================


SDK features present in 7.0 that were descoped in 7.1
-----------------------------------------------------
.. csv-table::
   :header: "Feature", "Comments"
   :widths: 40, 60

   HS support,Restored in 7.3
   SPL/Uboot boot modes restricted to SD card boot mode,Restored in 7.3
   1s Linux boot,
   Descope for support of native H264 encode/decode,Use R5F based driver with OpenVX as interface.  H.264 decoder support restored in 7.3
   GPU compression,
   SA2UL driver optimization,
   Display Sharing,Display sharing demo available in SDK v6.1
   Virtualization (Jailhouse hypervisor/IPC virtualization/CPSW9G virtualization),Does not affect 3P virtualization solutions. Basic Jailhouse demo can be seen in SDK 7.0


Installation and Usage
======================

The :ref:`Software Developer's Guide <linux-index>` provides instructions on how to setup your Linux development environment, install the SDK and start your development. It also includes User's Guides for various Example Applications.

|

Host Support
============

For the specific supported hosts for current SDK, see :ref:`this page <how-to-build-a-ubuntu-linux-host-under-vmware>`.

.. note::
   Processor SDK Installer is 64-bit, and installs only on 64-bit host machine. 

.. |reg| unicode:: U+00AE .. REGISTERED SIGN
