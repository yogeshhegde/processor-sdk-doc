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


Release 07.00.00
================
Released June 2020


What's New
----------
- First Processor SDK release with 2020 LTS Stream Kernel (v5.4), U-Boot (v2020.01), toolchain and Yocto branch
- J721E-HS Support
- Docker Linux Container Runtime
- Neo-AI-DLR library


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
-  Virtualization:

   -  Jailhouse hypervisor support
   -  Static system partitioning: SD/eMMC, sproxy threads, UARTs, etc.
   -  IO isolation between VMs
   -  PVU and SMMU backed IO isolation support
   -  Inter VM shared memory based communication
-  Profiling

   -  A72 PMU support for Performance profiling

.. _release-specific-sdk-components-versions:

Component versions
------------------

.. csv-table::
   :header: "component", "source", "branch", "version"
   :widths: 20,40,20,30

   arm-trusted-firmware,git://git.ti.com/atf/arm-trusted-firmware.git,ti-atf,5b907a2813faf039d752cdeb6a7b94e95580c46b
   optee-os,git://git.ti.com/optee/ti-optee-os.git,ti-optee-os,199fca17b575d4c748c9c435e908a6ec9618c75a
   U-boot,git://git.ti.com/ti-u-boot/ti-u-boot.git,ti-u-boot-2020.01,f9b0d030d31ab79577f1dd1e48814a8f3119c481
   Linux Kernel,git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git,ti-linux-5.4.y,66cf445b7697a4963cfc796e06918fe5b147fe7d
   Jailhouse,git://git.ti.com/jailhouse/ti-jailhouse.git,ti-jailhouse-0.12,8fd88c37ae1a4f7130ef40899c0eadd737c64832


Issues Tracker
===============
..
   project in (LCPD, "ADAS Algorithms") AND issuetype = Bug AND Platform in (j721e-evm, j721e-evm-ivi, j721e-idk-gw, j721e-hsevm, J7-EVM) AND fixversion in (2020.00, 07.00.00, SDK_J7_07_00_00) AND OS = Linux and resolution = Done AND (labels != SKIP_REL_NOTES OR labels is EMPTY) ORDER BY key ASC

Issues fixed in this release
----------------------------
.. csv-table::
   :header: "Record ID", "Summary"
   :widths: 20, 80

   LCPD-17010,J7ES: USB: gadget mode breaks with PC host with USB3.0 LPM
   LCPD-17236,PDK-IPC build from sources is not creating stripped images and links
   LCPD-17286,PCIe EP stress test failed with large number of EP functions
   LCPD-17404,PAT: lockdep warning
   LCPD-17675,Flash-based boot takes an extra 4 sec if SD card is not present in the J721e EVM
   LCPD-17771,cryptomgr_test kmemleak
   LCPD-17772,systemd doesn't show ansi sequences correctly
   LCPD-17773,cryptomgr_test related DMA-API errors
   LCPD-18055,rpmsg_rpc: allmodconfig with ARM 9.2 compiler generates bunch of warnings
   LCPD-18084,irqchip/pruss-intc: Fix up couple of build related issues
   LCPD-18137,J7 could not to uboot prompt with NITRO Strontium 16g card
   LCPD-18157,Jailhouse 0.12 build fails
   LCPD-18158,Automation interface does not work for some SD cards.
   LCPD-18159,Uboot: MMC could not be detected and 'mmc list' does not work on Alpha boards
   LCPD-18163,j721e audio is broken on alpha SOMs
   LCPD-18166,Jailhouse: Missing Jailhouse dtbo in the filesystem
   LCPD-18187,Audio Alsa tests are failing due to pulseaudio missing or default changing to pulseaudio
   LCPD-18198,ASoC: Incorrect DMA caused delay reporting
   LCPD-18204,eMMC alternative boot does not work
   LCPD-18205,SPL DFU boot test failed
   LCPD-18206,Uboot USB superspeed msc detection failed on J7
   LCPD-18211,Uboot OSPI performance decreased for both read/write
   LCPD-18216,arm and aarch64 target-side c compilation fails
   LCPD-18222,"Crypto 3DES, SHA1, SHA256 failures due to interrupt count not increasing"
   LCPD-18231,CPSW9G interface does not come up
   LCPD-18238,Kernel Oops generated sometimes by sa2ul
   LCPD-18244,Jailhouse linux-demo inmate does not boot
   LCPD-18245,openssl: missing cryptodev module
   LCPD-18252,opkg missing package for coremarkpro
   LCPD-18253,Jailhouse: missing cells for uart demo and gic demo
   LCPD-18254,U-Boot: remoteproc/k3-r5: rproc_init is failing for Main R5FSS0 Core0
   LCPD-18257,Jailhouse: Unhandled data abort with USB0 address
   LCPD-18270,Ivi shell test fails. Lib ivi-controller.so and other components are missing from the file system
   LCPD-18271,Git is missing from the default packages installed for testing
   LCPD-18286,crypto: sa2ul: memory leak with fallback algos
   LCPD-18287,tcrypto: multiblock sha test provides bad data chunks to driver
   LCPD-18288,crypto: sa2ul: openssl does not use sha accelerator
   LCPD-18304,U-Boot: Fix couple of issues with K3 DSP remoteproc driver
   LCPD-18342,IPC tests failed on j721e
   LCPD-18375,Operation is not permitted when setup pcie backplane
   LCPD-18447,J721e: SD/MMC back up boot mode not functional when eMMC is primary boot mode
   LCPD-18455,Jailhouse: lspci fails when Jailhouse is enabled
   LCPD-18501,ICSSG/CPSW9G: wrong IRQ trigger type used
   LCPD-18522,rpmsg_kdrv: fix build warnings
   LCPD-18523,U-Boot: Fix stale env variable in FIT loading support
   LCPD-18543,J721e HS QoS MMR programming causes firewall exception
   LCPD-18593,CPSW2G: restore vlan cfg after ifconfig up/down
   LCPD-18594,CPSW2G: CPTS: sync PPS to adjusted PTP clock
   LCPD-18656,OSPI/SPI ubifs test failed due to cannot read 64 bytes from mtd6/mtd0
   LCPD-18659,Jailhouse: ivshmem: Failed to map regions
   LCPD-18661,Jailhouse: ivshmem: Root cell does not receive interrupts
   LCPD-18672,J721e HS package is missing fit image
   LCPD-18694,AM65x: cpsw2g: ale parameters init issue
   LCPD-18695,AM65x: cpsw2g: allmulti mode is broken
   LCPD-18787,SPL DFU boot test failed
   LCPD-18793,pcie ep tests failed with big size with DMA mode
   LCPD-18847,UDMA: atype is ignored even if it is correctly specified for non slave channels
   LCPD-18850,Watchdog test failed to reboot EVM
   LCPD-18858,DMA heaps are not cached in Core SDK Linux

..
   project = LCPD AND Platform in (j721e-evm, j721e-evm-ivi, j721e-idk-gw, j721e-hsevm) AND ErrataID is not EMPTY AND status = Closed ORDER BY priority DESC

Errata workarounds
------------------
.. csv-table::
   :header: "Record ID", "Summary", "Workaround", "ErrataID"
   :widths: 20, 80, 60, 20

   LCPD-16350,DSS: Frame Buffer Flip/Mirror Feature Using RGB24/BGR24 Packed Format can Result in Pixel Corruption,"If the RGB24 or BGR24 packed format is selected, then use the GPU to implement the flip/mirror operation.",i2039
   LCPD-16605,MMC: MMC1/2 Speed Issue,,i2090
   LCPD-17220,U-Boot Hyperbus: Hyperflash reads limited to 125MHz max. frequency,,i2088

..
   project in (LCPD, "ADAS Algorithms") AND issuetype = Bug AND Platform in (j721e-evm, j721e-evm-ivi, j721e-idk-gw, j721e-hsevm, J7-EVM) AND status not in ("In Build", Closed, Resolved) AND OS = Linux AND (labels != SKIP_REL_NOTES OR labels is EMPTY) AND component != "System Test" ORDER BY key ASC

Open Defects
------------
.. csv-table::
   :header: "Record ID", "Summary", "Workaround"
   :widths: 20, 80, 60

   LCPD-16120,"DP: Link fails right after link training, unless voltage swing is 2 or 3",
   LCPD-16130,Exception triggered by drm_dev_unregister during poweroff,
   LCPD-16208,FIFO Underflows during video playback on 4k panel,
   LCPD-16366,RGX kick test fails when 32 sync dependencies are set for each command,
   LCPD-16505,"Wrong clock rate is reported for 157:400, 157:401 (HSDIVIDER after PLL4 and 15)",
   LCPD-16531,video decode: vxd_dec warnings displayed at end of gstreamer hevc playback to kmssink for certain video,
   LCPD-16535,remoteproc/k3-dsp: PDK IPC echo test binaries fails to do IPC in remoteproc mode on second run,
   LCPD-16545,remoteproc/k3-r5f: PDK IPC echo_test image fails to boot up in remoteproc mode on second run,
   LCPD-16591,PCIe wifi ping stress test failed,
   LCPD-16616,Jailhouse: Failure in mhdp probe while restarting the Linux VM,
   LCPD-16628,Could not enumerate PLEXTOR pcie SSD,
   LCPD-16836,DP: GeChic display EDID read failures,
   LCPD-16921,GPU driver doesn't unregister genpd name on unload,
   LCPD-17006,4k DP Display Shows Blank Screen sometimes when booting,
   LCPD-17213,Weston sometimes fails to start when booting with nfs filesystem,
   LCPD-17284,remoteproc/k3-r5: Cores are started out-of-order when core 0 file size >> core 1 file size,
   LCPD-17381,J7 Beta board ti_sci_power_domain_on: get_device(91) failed (-19),
   LCPD-17387,Underflow and CRTC SYNC LOST observed while running GLMark2 (1x1080p + 1x4k),
   LCPD-17398,J7 Beta board hangs and cannot power cycle via automation interface,
   LCPD-17403,PAT: DMA-API warning,
   LCPD-17406,U-boot: Uboot has no knowledge of memory reserved for remote cores,
   LCPD-17418,J7 sometimes failed to boot,Flash firmware into mmc rootfs
   LCPD-17421,CPSW9G: Can't bring up interface over NFS,
   LCPD-17543,Some cpuhotplug tests failed,
   LCPD-17673,No software documentation for the Timer module,
   LCPD-17770,U-Boot: Fix order of MCU R5 shutdown depending on cluster mode,
   LCPD-17780,Mbox timedout in resp,
   LCPD-17794,ext4write failed to write firmware to SD card,
   LCPD-17798,2020 LTS: INTA/INTR smp_affinity failure and IRQ allocation issues.,
   LCPD-17814,Kingston 16G card could not boot to uboot prompt,
   LCPD-18056,PVR Errors observed while running deqp-gles,
   LCPD-18115,PVR Error observed while running glmark2,
   LCPD-18233,MMC irq affinity to core 1 is not working.,
   LCPD-18258,IPSEC perfomance failures,
   LCPD-18657,Seeing bunch of Timed out in wait_for_event messages before getting to uboot prompt,
   LCPD-18754,U-Boot: Upstream: DTB getting over-written when booting kernel,
   LCPD-18849,OpenSSL HW crypto perfomance out of expected range,
   LCPD-18851,UYVY texture test needs update,
   LCPD-18860,isolcpus in the command line is not honored,
   LCPD-18894,J7 failed to boot to kernel occasionally,
   LCPD-18909,Uboot: SPL: failed to boot from all boot devices,
   LCPD-18912,QSPI read performance decreased,
   LCPD-18936,Jailhouse: GPIO driver probe fails,

..
   project = LCPD AND issuetype = Bug AND Platform in (j721e-evm, j721e-evm-ivi, j721e-idk-gw, j721e-hsevm) AND status = Closed AND resolution in ("Known Issue : HW Limitation", "Known Issue : Other") AND OS = Linux ORDER BY key ASC

.. _release-specific-known-issues:

Known issues & limitations
--------------------------
.. csv-table::
   :header: "Record ID", "Summary" , "Workaround"
   :widths: 20, 80, 60

   LCPD-16396,J721E: RC: Unsupported request in configuration completion packets results in an abort,"Workaround for Multifunction: Configure all the physical functions supported by the endpoint. For configuring all the 6 functions of PCIe  controller instance '1' in J721E, the following can be used. mount -t configfs none /sys/kernel/config; cd /sys/kernel/config/pci_ep/; mkdir functions/pci_epf_test/func1; echo 0x104c > functions/pci_epf_test/func1/vendorid; echo 0xb00d > functions/pci_epf_test/func1/deviceid; echo 1 > functions/pci_epf_test/func1/msi_interrupts; echo 16 > functions/pci_epf_test/func1/msix_interrupts; ln -s functions/pci_epf_test/func1 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func2; echo 0x104c > functions/pci_epf_test/func2/vendorid; echo 0xb00d > functions/pci_epf_test/func2/deviceid; echo 1 > functions/pci_epf_test/func2/msi_interrupts; echo 16 > functions/pci_epf_test/func2/msix_interrupts; ln -s functions/pci_epf_test/func2 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func3; echo 0x104c > functions/pci_epf_test/func3/vendorid; echo 0xb00d > functions/pci_epf_test/func3/deviceid; echo 1 > functions/pci_epf_test/func3/msi_interrupts; echo 16 > functions/pci_epf_test/func3/msix_interrupts; ln -s functions/pci_epf_test/func3 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func4; echo 0x104c > functions/pci_epf_test/func4/vendorid; echo 0xb00d > functions/pci_epf_test/func4/deviceid; echo 1 > functions/pci_epf_test/func4/msi_interrupts; echo 16 > functions/pci_epf_test/func4/msix_interrupts; ln -s functions/pci_epf_test/func4 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func5; echo 0x104c > functions/pci_epf_test/func5/vendorid; echo 0xb00d > functions/pci_epf_test/func5/deviceid; echo 1 > functions/pci_epf_test/func5/msi_interrupts; echo 16 > functions/pci_epf_test/func5/msix_interrupts; ln -s functions/pci_epf_test/func5 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func6; echo 0x104c > functions/pci_epf_test/func6/vendorid; echo 0xb00d > functions/pci_epf_test/func6/deviceid; echo 1 > functions/pci_epf_test/func6/msi_interrupts; echo 16 > functions/pci_epf_test/func6/msix_interrupts; ln -s functions/pci_epf_test/func6 controllers/d800000.pcie-ep/; echo 1 > controllers/d800000.pcie-ep/start; echo 1 > /sys/bus/pci/devices/0000:00:00.0/remove; echo 1 > /sys/bus/pci/rescan; Workaround for switch card: No workarounds available."
   LCPD-16640,PCIe RC: GIC ITS misbehaves when more than 4 devices use it simultaneously,
   LCPD-17171,Uboot dhcp occasionally failed,
   LCPD-17172,Uboot USBhost: Sandisk Extreme USB 3.0 msc stick could not be detected at second time,
   LCPD-17789,UBOOT J7:  Could not see UFS device by scsi scan,
   LCPD-18790,eMMC tests failed on J7 rev E2 EVM,

|


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
