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

Release AM65x EA2 v05.00.00.09
===============================

Released June 30 2018

.. rubric:: Features Supported
   :name: features-supported

.. csv-table::
   :header: "Component(s)", "Record ID", "Title"
   :widths: 25, 20, 70

    Audio & Display,LCPD-8817,McASP pseudo mono support
    Audio & Display,LCPD-6779,Support DRM API (atomic and legacy)
    Audio & Display,LCPD-5457,KERNEL: enable support for CAL Driver
    Audio & Display,LCPD-6129,Render in stereo
    Audio & Display,LCPD-6131,"Render audio in configurable buffer size of 5 ms, 10 ms, 20 ms"
    Audio & Display,LCPD-6130,"Capture audio in configurable buffer size of 5 ms, 10 ms, 20 ms"
    Audio & Display,LCPD-6128,"Capture audio at the following frequencies: 8kHz, 16kHz, and 48kHz"
    Audio & Display,LCPD-6124,render 16-bit and 24-bit audio
    Audio & Display,LCPD-6127,Render audio at 8 kHz
    Audio & Display,LCPD-6125,record 16-bit and 24-bit audio
    Audio & Display,LCPD-6126,Configure HW digital and analog gains
    Audio & Display,LCPD-6123,"start, stop and resume audio playback"
    Audio & Display,LCPD-6122,"start, stop and resume audio record"
    Audio & Display,LCPD-5455,Display: Support for DMABuf import in DRM driver
    Audio & Display,LCPD-11489,"McASP driver shall support 16, 24, 24_3 and 32-bit data sizes"
    Audio & Display,LCPD-11492,McASP driver shall support master and slave modes
    Audio & Display,LCPD-11499,McASP driver shall support underflow/overflow error reporting and recovery
    Audio & Display,LCPD-11484,McASP driver shall support I2S mode
    Audio & Display,LCPD-11491,McASP driver shall support configurable BCLK and FSYNC clock polarities
    Audio & Display,LCPD-6842,Support for user space mmapping of DMABUF FD
    Audio & Display,LCPD-8663,OMAP DRM: Allow using unused primary planes as overlay planes
    Audio & Display,LCPD-11214,LCD backlight control (full support)
    Audio & Display,LCPD-11215,LCD backlight
    Audio & Display,LCPD-11223,DSS per pixel alpha blending (pre & non-pre-multiplied)
    Audio & Display,LCPD-12581,Support DMABuf fence in DRM driver
    Audio & Display,LCPD-11211,Support RGB pixel formats
    Audio & Display,LCPD-11217,DSS VP Gamma correction
    Audio & Display,LCPD-10615,MIPI DPI on LCD outputs
    Audio & Display,LCPD-11218,DSS Overlay Z ordering
    Audio & Display,LCPD-11220,DSS cropping
    Audio & Display,LCPD-11210,Support YUV422 pixel formats
    Audio & Display,LCPD-11208,Support YUV420 pixel formats
    Audio & Display,LCPD-11226,[am654x-evm] Touchscreen driver shall detect single-point touch events
    Audio & Display,LCPD-11225,[am654x-evm] Touchscreen driver shall detect multi-point touch events
    Audio & Display,LCPD-11503,UDMA driver shall support transfer position querying capability
    Baseport,LCPD-12350,Uboot/SPL: Uboot/SPL needs to support DDR SS init for platform/EVM supported DDR devices
    Baseport,LCPD-13312,U-Boot: Bootloader running on Cortex A53 should support booting Linux
    Baseport,LCPD-13309,SPL: Support boot-strapping second stage of U-boot on Cortex A53/A72
    Baseport,LCPD-10355,Basic HYP mode support in kernel
    Baseport,LCPD-10352,Support Symmetric multiprocessing (SMP)
    Baseport,LCPD-9741,Quad Core SMP support
    Baseport,LCPD-9551,Dual core SMP support
    Baseport,LCPD-7023,Device shall have boot success rate higher than 99.9%
    Baseport,LCPD-7022,Device shall boot to Linux prompt
    Baseport,LCPD-6870,Dhrystone performance is between 1 std dev of previous release
    Baseport,LCPD-6869,Whetstone performance is between 1 std dev of previous release
    Baseport,LCPD-6866,Support core kernel Memory Management functionality
    Baseport,LCPD-6867,Support core kernel scheduler functionality
    Baseport,LCPD-6868,Support kernel system calls
    Baseport,LCPD-6535,Bootloader shall support kernel image either as an uncompressed image file or as a ZImage compressed kernel file.
    Baseport,LCPD-6536,The PMU shall be configurable through kernel interfaces.
    Baseport,LCPD-6184,OS Kernel shall support preemptive scheduler configuration
    Baseport,LCPD-6173,Support for Hardware Timer
    Baseport,LCPD-6149,System shall detect correct SoC during boot
    Baseport,LCPD-10129,RT Functional Support
    Baseport,LCPD-10121,Add STREAM benchmark for Single-Core
    Connectivity,LCPD-12483,U-Boot: Support Octal SPI(OSPI) flash devices
    Connectivity,LCPD-12482,Kernel: Support Octal SPI (OSPI) flash devices
    Connectivity,LCPD-10586,[am654x-evm] ext4 file system shall be supported on MMC
    Connectivity,LCPD-9718,CPSW: Ethernet driver shall support placing the interface in promiscuous mode
    Connectivity,LCPD-9000,Enable CIFS support
    Connectivity,LCPD-10305,m4x-gpevm Support PCIe Root Complex
    Connectivity,LCPD-10304,am65xx: PCIe: PCIe EP mode support
    Connectivity,LCPD-7446,USB-DEVICE: ZLP Support in USB driver
    Connectivity,LCPD-6629,"USB host driver shall support High Speed, Full Speed, and Low-speed devices simultaneously (via Hubs)"
    Connectivity,LCPD-6630,USB host driver shall support selective suspend.
    Connectivity,LCPD-6628,USB host driver shall support enumeration of High speed devices
    Connectivity,LCPD-6623,USB host driver shall support HUB class client devices.
    Connectivity,LCPD-6624,USB host driver shall support WiFi client devices.
    Connectivity,LCPD-6627,USB host driver shall support enumeration of Full speed devices
    Connectivity,LCPD-6626,USB host driver shall support enumeration of Low speed devices
    Connectivity,LCPD-6622,USB host driver shall support CDC ECM class client devices.
    Connectivity,LCPD-6620,USB host driver shall support Audio class client devices.
    Connectivity,LCPD-6617,USB host driver shall support mass storage client devices.
    Connectivity,LCPD-6606,USB client gadget driver for CDC(Communication Device Class for Abstract Control Model) shall be supported.
    Connectivity,LCPD-6605,USB client gadget driver for CDC ECM (Communication Device Class for Ethernet Control Model) shall be supported.
    Connectivity,LCPD-6615,USB client driver shall support both High-speed and Full-speed mode for all supported client gadget drivers
    Connectivity,LCPD-6607,USB client driver shall support cable connect and disconnect feature.
    Connectivity,LCPD-6618,USB host driver shall support Human interface client devices.
    Connectivity,LCPD-6621,USB host driver shall support CDC ACM class client devices.
    Connectivity,LCPD-6619,USB host driver shall support Video class client devices.
    Connectivity,LCPD-6599,UART driver shall support baud rates from 2400 bps up to 3.6 Mbps.
    Connectivity,LCPD-6611,USB client gadget driver for MultiFunction Composite (CDC/RNDIS Ethernet + CDC Serial + Storage) device shall be supported.
    Connectivity,LCPD-6603,USB client gadget driver for Mass Storage shall be supported.
    Connectivity,LCPD-6600,"UART driver shall support settings of 115200 baud rate, 8 bit data, 1 stop bit, no parity, no flow control and no DMA usage for Debug Console functionality"
    Connectivity,LCPD-6598,UART driver shall support configuration of the baudrate.
    Connectivity,LCPD-6612,USB client gadget driver for MultiFunction Composite (CDC Ethernet + CDC Serial + Storage) device shall be supported.
    Connectivity,LCPD-6610,USB client gadget driver for composite device (CDC + MSC and CDC (ACM) + CDC (ECM)) shall be supported.
    Connectivity,LCPD-6595,UART driver shall support hardware flow control (auto-CTS).
    Connectivity,LCPD-6596,UART driver shall support hardware flow control (auto-RTS).
    Connectivity,LCPD-6575,MMC: Write throughput within 1 standard deviation from historical data
    Connectivity,LCPD-6568,MMC driver shall support 4-bit data transfers to the MMC/SD card
    Connectivity,LCPD-6574,MMC: Read throughput within 1 standard deviation from historical data
    Connectivity,LCPD-6573,ext4 file system shall be supported on MMC
    Connectivity,LCPD-6571,ext2 file system shall be supported on MMC
    Connectivity,LCPD-6572,ext3 file system shall be supported on MMC
    Connectivity,LCPD-6563,CPSW: Ethernet switch driver shall support ability to dump statistics of the switch
    Connectivity,LCPD-6561,CPSW: The Ethernet switch driver shall provide an interface to configure the speed and duplexity of the downstream ports (same options for both independent ports).
    Connectivity,LCPD-6564,I2C driver shall operate in master mode.
    Connectivity,LCPD-6565,I2C driver shall support interrupt mode for data transfers.
    Connectivity,LCPD-6559,CPSW: The Ethernet switch driver will support a configuration whereby the only unicast packets forwarded to the host are those that match the host's MAC address
    Connectivity,LCPD-6560,CPSW: The ethernet switch driver shall support multicast frame filtering based on entries programmed in the ALE
    Connectivity,LCPD-6556,CPSW: In switch mode the ethernet driver downstream ports (and the PHYs) shall be configured to support auto-negotiation
    Connectivity,LCPD-5964,MMC: Kernel: support ADMA for DMA transfer
    Connectivity,LCPD-6569,MMC driver shall support 8-bit data transfers to the MMC/eMMC card
    Connectivity,LCPD-7449,USB: DEVICE: Support for composite gadget (Running NCM and ACM function simultaneously)
    Connectivity,LCPD-7448,USB: DEVICE: Support for NCM gadget driver
    Connectivity,LCPD-9594,MMC/SD/SDIO: support building and insertion of driver as a kernel module
    Connectivity,LCPD-8959,USB webcam gadget support
    Connectivity,LCPD-10439,PRUETH driver must support a single PHY instead of requiring 2
    Connectivity,LCPD-10584,[am654x-evm] CPSW: The Ethernet driver will be a standard Linux network driver (implementing netdev interface).
    Connectivity,LCPD-10585,[am654x-evm] I2C driver shall operate in master mode.
    Connectivity,LCPD-10381,CPSW: Ethernet switch driver shall support ability to dump statistics of the switch
    Connectivity,LCPD-6567,I2C master driver shall support the highest speed supported by slowest speed slave on the bus subject to a maximum of 3.4Mbit/s
    Connectivity,LCPD-6557,CPSW: The ethernet switch driver shall provide for MAC address configuration through ifconfig command. The default value shall be read from EFUSEs/EEPROM as supported by the board/SoC.
    Connectivity,LCPD-6549,CPSW: Ethernet driver shall support modular builds
    Connectivity,LCPD-12646,Uboot: Support SD card boot
    Connectivity,LCPD-9697,EMAC driver for ICSS_G
    IPC,LCPD-10120,[m4x-gpevm] Support HW spinlocks
    IPC,LCPD-10119,[m4x-gpevm] Support mailbox
    System,LCPD-6871,Linpack performance is between 1 std dev of previous release
    System,LCPD-6872,NBench performance is between 1 std dev of previous release
    System,LCPD-6873,LMBench performance is between 1 std dev of previous release
    System Integration,LCPD-7475,Support ipsec based secure connections using software crypto and StrongSwan
    System Integration,LCPD-9258,Support core kernel IPC functionality
    System Integration,LCPD-9259,Support Math library
    System Integration,LCPD-9682,Support CPU Core Isolation


.. rubric:: Features Not Available
   :name: features-not-available

Below are the main features which are not available in this EA2 release:

-  PCIe
-  USB 3.0 (SS)
-  Graphics
-  Gstreamer


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

