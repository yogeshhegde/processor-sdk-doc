.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Release_Notes 

.. rubric:: Overview
   :name: overview

The **Processor Software Development Kit (Processor-SDK)** provides the
core foundation and building blocks that facilitate application software
development on TI's embedded processors. This *Release Notes* focuses on
the Real-time operating system (RTOS).

| 

.. rubric:: Licensing
   :name: licensing

Please refer to the software manifest, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page or in the installed directory as
indicated below.

| 

.. rubric:: Documentation
   :name: documentation

-  `**Getting Started
   Guide** </index.php/Processor_SDK_RTOS_Getting_Started_Guide>`__:
   Provides information on getting the software and running basic
   examples/demonstrations bundled in the SDK.
-  `**Migration
   Guide** </index.php/Processor_SDK_RTOS_Migration_Guide>`__: Provides
   migration information for applications built on top of the Processor
   SDK for RTOS.
-  `**Software Developer
   Guide** </index.php/Processor_SDK_RTOS_Software_Developer_Guide>`__:
   Provides information on features, functions, delivery package and,
   compile tools for the Processor SDK RTOS release. This also provides
   detailed information regarding software elements and software
   infrastructure to allow developers to start creating applications.
-  **Software Manifest**: Provides license information on software
   included in the SDK release. This document is in the release at
   ``[INSTALL-DIR]/processor_sdk_rtos_<SOC>_<version>/docs`` and
   available to view from the software download page.
-  **EVM Quick Start Guide**: Provides information on hardware setup and
   running the demonstration application that is loaded on flash. This
   document is provided as part of the EVM kit.

| 

.. rubric:: Release 04.02.00
   :name: release-04.02.00

Released December 2017.

.. rubric:: What's New
   :name: whats-new

.. rubric:: New Features
   :name: new-features

-  AM574x: Platform Support with ECC feature demonstrated through CSL
   example
-  AM335x, OMAP-L13x, C674x

   -  USB: Device Mode Audio Class Support

-  AM572x, AM335x

   -  `**Processor SDK RTOS Template
      App** </index.php/Processor_SDK_RTOS_Template_App>`__:Single point
      reference to accelerate end application development

-  AM572x

   -  CSL: DCAN RTOS example support
   -  VPS: support for camera with OV10635 sensor

-  K2G

   -  Support for 1Ghz FC SOC

.. rubric:: Component Version
   :name: component-version

The following software components and host tools are bundled with the
SDK installer. See the `Software Developer
Guide </index.php/Processor_SDK_RTOS_Software_Developer_Guide>`__ for
more information on each item.

Component
Version
AM335x
AM437x
AM57x
K2H/K2K
K2E
K2L
K2G
C665x
C667x
OMAP-L137
OMAP-L138
CG\_XML
2.41.0
X
X
X
X
X
X
X
X
X
X
X
CTOOLSLIB
2.2.0.0
X
X
X
X
X
X
X
DSPLIB
3.4.0.0
X
X
X
X
X
X
X
X
X
EDMA3 LLD
2.12.5.30
X
X
X
X
X
X
X
X
X
X
X
FC
3.40.2.7
X
X
X
X
X
X
X
FFTLIB
3.1.0.0
X
IMGLIB
3.1.1.0
X
X
X
X
X
X
X
IPC
3.47.0.0
X
X
X
X
X
X
X
X
LIBARCH
1.0.0.0
X
LINALG
1.2.0.0
X
MATHLIB
3.1.1.0
X
X
X
X
X
X
X
X
X
MPM
3.0.4.0
X
X
X
X
NDK
2.26.0.0
X
X
X
X
X
X
X
X
X
X
X
OPENCL
1.1.14.1
X
OPENMP
2.6.2.0
X
X
X
X
X
X
X
PDK
Per platform
1.0.9
1.0.9
1.0.9
4.0.8
4.0.8
4.0.8
1.0.8
2.0.8
2.0.8
1.0.3
1.0.3
SYS/BIOS
6.52.0.12
X
X
X
X
X
X
X
X
X
X
X
UIA
2.21.2.07
X
X
X
X
X
X
X
X
X
XDAIS
7.24.0.4
X
X
X
X
X
X
X
X
X
XDCTOOLS
3.50.03.33
X
X
X
X
X
X
X
X
X
X
X
The following compilers are bundled with the SDK installer:

Compiler
Version
AM335x
AM437x
AM57x
K2H/K2K
K2E
K2L
K2G
C665x
C667x
OMAP-L137
OMAP-L138
GNU ARM Embedded
6-2017-q1
A8
A9
A15
A15
A15
A15
A15
TI ARM CGT
16.9.3
M4
A15 (SBL)
ARM9
ARM9
TI C6000 CGT
8.2.2
C66x
C66x
C66x
C66x
C66x
C66x
C66x
C674x
C674x
TI PRU CGT
2.1.5
PRU
PRU
PRU
PRU
The SDK uses Code Composer Studio (CCS) as the integrated development
environment (IDE) for all devices and EVMs:

Component
Version
AM335x
AM437x
AM57x
K2H/K2K
K2E
K2L
K2G
C665x
C667x
OMAP-L137
OMAP-L138
CCS
7.3.0.19
X
X
X
X
X
X
X
X
X
X
X
If you need to install CCS, see the `CCS installation
section </index.php/Processor_SDK_RTOS_Getting_Started_Guide#Code_Composer_Studio>`__
in the *Getting Started Guide* for options to select for Processor-SDK.

**Change log**

Updated

-  EDMA3 LLD 2.12.5.30
-  IPC 3.47.0
-  NDK 2.26.0.0
-  TI-RTOS/SysBIOS 6.52.0.12
-  UIA 2.21.2.7
-  XDCTOOLS 3.50.3.33
-  GNU ARM Embedded 6-2017-q1
-  TI C6000 CGT 8.2.2
-  CCS 7.3.0.19
-  PDK for all platforms

.. rubric:: Fixed Issues
   :name: fixed-issues

+--------------+-----------------------------------------+------------------------------------------------------------------------------------------------------------------------------------+
| Record ID    | Platform                                | Summary                                                                                                                            |
+==============+=========================================+====================================================================================================================================+
| PRSDK-3134   | am572x-evm                              | AM572x CSL:DSP booted through remoteproc stalls during unlocking/locking MMR\_LOCK\_2                                              |
+--------------+-----------------------------------------+------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3088   | c6748-evm                               | C6748 LCDK: Board\_Init Incorrectly enabling AINTC clock                                                                           |
+--------------+-----------------------------------------+------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3002   | k2g-ice                                 | Board Diagnostics- icssEmac\_TEST hangs while Sending first packet                                                                 |
+--------------+-----------------------------------------+------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3051   | k2g-ice                                 | SBL MMCSD Boot - MLO unable to load/run app for A15 and C66                                                                        |
+--------------+-----------------------------------------+------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3087   | \*                                      | UART\_Read: Possible loss of last byte when IP receives data before API is called and if returnMode is set to UART\_RETURN\_FULL   |
+--------------+-----------------------------------------+------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3037   | \*                                      | UART\_stdio: API files should include definition of return values expected from API functions                                      |
+--------------+-----------------------------------------+------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3258   | am437x/am57x/am335x                     | EMAC LLD: Incorrect link status returned from emac\_poll API                                                                       |
+--------------+-----------------------------------------+------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3208   | am437x/am57x/am335x                     | EMAC LLD: Missing C++ support in internal header files                                                                             |
+--------------+-----------------------------------------+------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3065   | c6748-evm, omapl137-evm, omapl138-evm   | EMAC LLD doesn\`t provide default SOC configuration for OMAPL devices.                                                             |
+--------------+-----------------------------------------+------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-2982   | \*                                      | EMAC LLD: API emac\_close does not free or release EMAC\_GLOBAL\_RX\_SEM\_HANDLE                                                   |
+--------------+-----------------------------------------+------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-2609   | k2h-evm                                 | Serdes diag documentation update for PCIE                                                                                          |
+--------------+-----------------------------------------+------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3007   | k2g-evm                                 | Posix-SMP Demo: c66 APP failed to run for evmK2G                                                                                   |
+--------------+-----------------------------------------+------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-2387   | am335x-evm, am572x-evm                  | Posix SMP Demo: SBL Boot No response on UART Only function through JTAG                                                            |
+--------------+-----------------------------------------+------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-1932   | AM3X, AM4X                              | SORTE firmware: Slave devices report RX\_CRC packet errors during Parameterization state                                           |
+--------------+-----------------------------------------+------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-1755   | K2G                                     | EDMA LLD example project fails to build because CCS project is not updated with components from SDK                                |
+--------------+-----------------------------------------+------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-2614   | AM437x                                  | Adding GPIO1 instance entry causes other GPIOs to not work                                                                         |
+--------------+-----------------------------------------+------------------------------------------------------------------------------------------------------------------------------------+

.. rubric:: Supported Platforms
   :name: supported-platforms

.. rubric:: Devices
   :name: devices

The following table lists all supported devices for a given installer.

Installer
Platform/SOC
Supported Devices
`RTOS-AM335X <http://software-dl.ti.com/processor-sdk-rtos/esd/AM335X/latest/index_FDS.html>`__
`AM335x <http://www.ti.com/am335x>`__
`AM3351 <http://www.ti.com/product/am3351>`__,
`AM3352 <http://www.ti.com/product/am3352>`__,
`AM3354 <http://www.ti.com/product/am3354>`__,
`AM3356 <http://www.ti.com/product/am3356>`__,
`AM3357 <http://www.ti.com/product/am3357>`__,
`AM3358 <http://www.ti.com/product/am3358>`__,
`AM3359 <http://www.ti.com/product/am3359>`__
`AMIC11x <http://www.ti.com/lsds/ti/processors/sitara/industrial-ethernet/amic11x/amic11x-overview.page>`__
`AMIC110 <http://www.ti.com/product/amic110>`__
`RTOS-AM437X <http://software-dl.ti.com/processor-sdk-rtos/esd/AM437X/latest/index_FDS.html>`__
`AM437x <http://www.ti.com/am437x>`__
`AM4376 <http://www.ti.com/product/am4376>`__,
`AM4377 <http://www.ti.com/product/am4377>`__,
`AM4378 <http://www.ti.com/product/am4378>`__,
`AM4379 <http://www.ti.com/product/am4379>`__
`RTOS-AM57X <http://software-dl.ti.com/processor-sdk-rtos/esd/AM57X/latest/index_FDS.html>`__
`AM57x <http://www.ti.com/am57x>`__
`AM5706 <http://www.ti.com/product/am5706>`__,
`AM5708 <http://www.ti.com/product/am5708>`__,
`AM5716 <http://www.ti.com/product/am5716>`__,
`AM5718 <http://www.ti.com/product/am5718>`__,
`AM5726 <http://www.ti.com/product/am5726>`__,
`AM5728 <http://www.ti.com/product/am5728>`__,AM5746, AM5748
`RTOS-C665X <http://software-dl.ti.com/processor-sdk-rtos/esd/C665x/latest/index_FDS.html>`__
`C665x <http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp/c66x/overview.page>`__
`C6652 <http://www.ti.com/product/tms320c6652>`__,
`C6654 <http://www.ti.com/product/tms320c6654>`__,
`C6655 <http://www.ti.com/product/tms320c6655>`__,
`C6657 <http://www.ti.com/product/tms320c6657>`__
`RTOS-C667X <http://software-dl.ti.com/processor-sdk-rtos/esd/C667x/latest/index_FDS.html>`__
`C667x <http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp/c66x/overview.page>`__
`C6671 <http://www.ti.com/product/tms320c6671>`__,
`C6672 <http://www.ti.com/product/tms320c6672>`__,
`C6674 <http://www.ti.com/product/tms320c6674>`__,
`C6678 <http://www.ti.com/product/tms320c6678>`__
`RTOS-K2E <http://software-dl.ti.com/processor-sdk-rtos/esd/K2E/latest/index_FDS.html>`__
`K2E <http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp-arm/66ak2x/overview.page>`__
`66AK2E02 <http://www.ti.com/product/66ak2e02>`__,
`66AK2E05 <http://www.ti.com/product/66ak2e05>`__,
`AM5K2E02 <http://www.ti.com/product/am5k2e02>`__,
`AM5K2E04 <http://www.ti.com/product/am5k2e04>`__
`RTOS-K2G <http://software-dl.ti.com/processor-sdk-rtos/esd/K2G/latest/index_FDS.html>`__
`K2G <http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp-arm/66ak2x/overview.page>`__
`66AK2G02 <http://www.ti.com/product/66ak2g02>`__
`RTOS-K2HK <http://software-dl.ti.com/processor-sdk-rtos/esd/K2HK/latest/index_FDS.html>`__
`K2H <http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp-arm/66ak2x/overview.page>`__
`66AK2H06 <http://www.ti.com/product/66ak2h06>`__,
`66AK2H12 <http://www.ti.com/product/66ak2h12>`__,
`66AK2H14 <http://www.ti.com/product/66ak2h14>`__
K2K
`TCI6638K2K <http://www.ti.com/product/tci6638k2k>`__
`RTOS-K2L <http://software-dl.ti.com/processor-sdk-rtos/esd/K2L/latest/index_FDS.html>`__
`K2L <http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp-arm/66ak2x/overview.page>`__
`66AK2L06 <http://www.ti.com/product/66ak2l06>`__
`RTOS-OMAPL137 <http://www.ti.com/tool/processor-sdk-omapl137>`__
`OMAP-L1x <http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp-arm/omap-l1x/overview.page>`__
`OMAP-L137 <http://www.ti.com/product/OMAP-L137>`__,
`C6743 <http://www.ti.com/product/tms320c6743>`__,
`C6745 <http://www.ti.com/product/tms320c6745>`__,
`C6747 <http://www.ti.com/product/tms320c6747>`__
`RTOS-OMAPL138 <http://www.ti.com/tool/processor-sdk-omapl138>`__
`OMAP-L1x <http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp-arm/omap-l1x/overview.page>`__
`OMAP-L138 <http://www.ti.com/product/OMAP-L138>`__,
`C6742 <http://www.ti.com/product/tms320c6742>`__,
`C6746 <http://www.ti.com/product/tms320c6746>`__,
`C6748 <http://www.ti.com/product/tms320c6748>`__
.. rubric:: Evaluation Modules
   :name: evaluation-modules

See `Processor SDK Supported
Platforms </index.php/Processor_SDK_Supported_Platforms_and_Versions>`__
page for a list of supported EVMs per platform and links to more
information.

.. rubric:: Demonstrations
   :name: demonstrations

See `Examples and
Demonstrations </index.php/Processor_SDK_RTOS_Examples_and_Demonstrations>`__
page for a list of demonstrations per platform and EVM.

.. rubric:: Drivers
   :name: drivers

The following tables show RTOS driver availability per platform and EVM.
A shaded box implies that the feature is not applicable for that
platform/EVM.

**Sitara devices**

Driver
Platform/SOC
AM335x EVM
AM437x EVM
AM57x EVM
AM335x
AM437x
AM57x
GP
ICE
SK
BBB
GP
IDK
SK
GP
IDK
CSL
X
X
X
X
X
X
X
X
X
X
X
X
EMAC
X
X
X
X
X
X
X
X
X
X
X
X
EDMA3
X
X
X
X
X
X
GPIO
X
X
X
X
X
X
X
X
X
GPMC
X
X
X
X
I2C
X
X
X
X
X
X
X
X
X
X
X
X
ICSS-EMAC
X
X
X
X
X
X
McASP
X
X
X
X
X
X
McSPI
X
X
X
X
X
X
MMC-SD
X
X
X
X
X
X
X
X
X
X
X
X
PCIe
X
X
PM
X
X
X
X
PRUSS
X
X
X
X
QSPI
X
X
X
X
X
UART
X
X
X
X
X
X
X
X
X
X
X
X
USB
X
X
X
X
X
X
X
USB Device Audio
X
X
VPS
X
X
X
**DSP devices - K2x, C66x**

Driver
Platform/SOC
K2 EVM
C66x EVM
K2H/K2K
K2E
K2L
K2G
C665x
C667x
K2H
K2E
K2L
K2G
K2G-ICE
C665x
C667x
CSL
X
X
X
X
X
X
X
X
X
X
X
X
X
AIF2
X
X
BCP
X
X
X
X
CPPI
X
X
X
X
X
X
X
X
X
X
X
X
X
DFE
X
X
EDMA3
X
X
X
X
X
X
X
X
X
X
X
X
X
EMAC
X
X
X
X
X
FFTC
X
X
X
X
GPIO
X
X
X
X
X
X
X
X
X
X
X
X
X
HYPLNK
X
X
X
X
X
X
X
X
ICSS-EMAC
X
X
I2C
X
X
X
X
X
X
X
X
X
X
X
X
X
IQN2
X
X
McASP
X
X
McBSP
X
X
X
X
MMAP
X
X
X
X
MMC-SD
X
X
X
NWAL
X
X
X
X
X
X
X
X
PA
X
X
X
X
X
X
X
X
PCIe
X
X
X
X
X
X
X
X
X
X
X
X
QMSS
X
X
X
X
X
X
X
X
X
X
X
X
X
RM
X
X
X
X
X
X
X
X
X
X
X
X
X
SA
X
X
X
X
X
X
X
X
X
X
SPI
X
X
X
X
X
X
X
X
X
X
X
X
X
SRIO
X
X
X
X
X
X
TCP3D
X
X
X
X
X
X
TSIP
X
X
X
X
UART
X
X
X
X
X
X
X
X
X
X
X
X
X
USB
X
X
USB Device Audio
**DSP devices - OMAP-L13x, C674x**

Driver
Platform/SOC
OMAP-L137 EVM
OMAP-L138 EVM
OMAP-L137
OMAP-L138
137/6747 SK
LCDK138
LCDK6748
CSL
X
X
X
X
X
EDMA3
X
X
X
X
X
EMAC
X
X
X
X
X
GPIO
X
X
X
X
X
I2C
X
X
X
X
X
McASP
X
X
X
X
X
MMC-SD
X
X
X
X
X
SPI
X
X
X
X
X
UART
X
X
X
X
X
USB
X
X
X
X
X
USB Device Audio
X
X
.. rubric:: Other Features
   :name: other-features

The following table shows other feature availability per platform and
EVM:

**Sitara devices**

Feature
Platform/SOC
AM335x EVM
AM437x EVM
AM57x EVM
AM335x
AM437x
AM57x
GP
ICE
SK
BBB
GP
IDK
SK
GP
IDK
Board Support
X
X
X
X
X
X
X
X
X
X
X
X
Boot (SBL)
X
X
X
X
X
X
X
X
X
X
X
X
Diagnostics
X
X
X
X
X
X
X
FATFS
X
X
X
X
X
X
X
X
X
NDK-NIMU(CPSW)
X
X
X
X
X
X
X
X
X
X
X
X
NDK-NIMU(ICSS)
X
X
X
X
X
X
CC-LINK IE Field Basic (CPSW)
X
X
X
X
X
X
X
X
X
X
X
X
CC-LINK IE Field Basic (ICSS)
X
X
X
X
X
X
**DSP devices - K2x, C66x**

Feature
Platform/SOC
K2 EVM
C66x EVM
K2H/K2K
K2E
K2L
K2G
C665x
C667x
K2H
K2E
K2L
K2G
K2G-ICE
C665x
C667x
Board Support
X
X
X
X
X
X
X
X
X
X
X
X
X
Boot (IBL/SBL)
X
X
X
X
X
X
X
X
X
X
X
X
X
Diagnostics
X
X
X
FATFS
X
X
X
Fault Management
X
X
X
X
X
X
IPC Transport (QMSS)
X
X
X
X
X
X
X
X
X
X
IPC Transport (SRIO)
X
X
X
X
X
X
MAD-UTIL
X
X
X
X
Network (CPSW)
X
X
X
X
X
X
X
X
X
X
X
X
X
Network (ICSS)
X
X
CC-Link IE Field Basic(ICSS)
X
X
Platform Library (obsolete)
X
X
X
X
X
X
X
X
X
X
PKTLIB
X
X
X
X
X
X
X
X
POST
X
X
X
X
X
X
X
X
X
X
SERDES Diagnostics
X
X
X
X
X
X
Trace Framework
X
X
X
X
X
X
**DSP devices - OMAP-L13x, C674x**

Feature
Platform/SOC
OMAP-L137 EVM
OMAP-L138 EVM
OMAP-L137
OMAP-L138
137/6747 SK
LCDK138
LCDK6748
Board Support
X
X
X
X
X
Boot (SBL)
X
X
X
X
X
Diagnostics
X
X
FATFS
X
X
X
X
X
Network (CPSW)
X
X
X
X
X
.. rubric:: Known Issues
   :name: known-issues

This section contains the list of known issues at the time of making the
release and any known workaround.

+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| Record ID    | Platform               | Area                      | Summary                                                                                                                                 | Workaround                                                                                                                                                                                                                   |
+==============+========================+===========================+=========================================================================================================================================+==============================================================================================================================================================================================================================+
| PRSDK-415    | AM3X                   | DMA                       | EDMA3 LLD RM code reserves first 64 parameters which are not available to user app using EDMA3\_DRV\_requestChannel                     | Application needs to make sure that they to not provision these resources.                                                                                                                                                   |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-335    | AM4X                   | High-Speed Drivers        | USB host MSC fails to re-enumerate                                                                                                      | Re-enumeration support for the case of device unplugged and plugged back currently fails for the example. Workaround is to avoid disconnecting drive while running example.                                                  |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-1995   | C6678                  | Optimized Libraries       | FFTLIB: 3D FFT CCS project example fails to build with Processor-SDK tools (CCS, OpenMP)                                                | Use older versions of tools (CCSv5, OpenMP).                                                                                                                                                                                 |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-1491   | K2G, K2H, K2L, K2K     | Board Support             | ARM PLL initialization sequence for K2 SOCs needs to be updated to avoid intermittent hang issue due to glitch observed on PLL clocks   | Enable the glitch-less bypass clock mux (ARM\_PLL\_EN bit in CHIP\_MISC\_CTL1, set it to 0) before enabling ARM PLL bypass. And then turn the glitch-less clock mux to PLL after releasing bypass (set ARM\_PLL\_EN to 1).   |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-316    | K2H                    | KeyStone Drivers          | SRIO LLD board to board throughput test fails for Type 11                                                                               | None                                                                                                                                                                                                                         |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-330    | AM4X                   | High-Speed Drivers        | USB device MSC re-enumeration fails while disconnecting and reconnecting on a Windows host                                              | Problem not observed with Linux USB Host.                                                                                                                                                                                    |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-1682   | AM5X                   | Diagnostics               | Board diagnostics LCD Touchscreen test does not work with new version of LCD TSC                                                        | For LCD/Display checkout example under VPS component could be used                                                                                                                                                           |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-2196   | AM5X                   | Diagnostics               | DCAN Diag test failed on AM57x IDK Platforms                                                                                            | None                                                                                                                                                                                                                         |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-2166   | AM5X                   | High-Speed Drivers        | USB3.0 host problem with Sandisk Extreme USB3.0 stick                                                                                   | Start the example without the USB plugged in. Once the example is up and waiting for USB stick, plug the USB stick in and it will enumerate properly.                                                                        |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-2263   | \*                     | DSPLIB                    | CCS test projects don\`t have optimized compiler settings.                                                                              | Modify compiler setting:remove -g,Add -O3.Add --mem\_model:data=far --symdebug:none                                                                                                                                          |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-2423   | \*                     | Mathlib                   | Linker Error while linking MATHLIB RTS override library in the application .                                                            | link both mathlib library and mathlib\_rts library                                                                                                                                                                           |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-2575   | \*                     | DSPLIB                    | DSPLIB header files prevents function declarations from being included                                                                  | None                                                                                                                                                                                                                         |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-2941   | AM335x                 | Board                     | PLL Settings need to be updated for additional optimal values                                                                           | None                                                                                                                                                                                                                         |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-2819   | AM335x                 | Board                     | Networking API header files are not compatible with C++                                                                                 | extern "C" can be added to the missing API header file in use by application                                                                                                                                                 |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-1975   | \*                     | Board Diagnostics         | Timer Diagnostic example does not run on ARM 1 core                                                                                     | None                                                                                                                                                                                                                         |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3142   | C667x,k2h,k2e          | IPC                       | IPC listMP corruption                                                                                                                   | Fix available in External GIT                                                                                                                                                                                                |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-2972   | c674x                  | DSPLIB                    | DSPLIB for C674x doesn\`t provide fixed point 16 bit FFT function like C66x version                                                     | None                                                                                                                                                                                                                         |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3382   | am335x,am437x,am57x    | UART                      | UART: API UART\_read() reads additional byte from what requested by application and drops in case FIFO has extra bytes                  | Fix will be update in UART\_v1\_readData() function to check for size !=0 before next read UARTCharGetNonBlocking()                                                                                                          |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3381   | am335x                 | UART                      | To support CPSW port-2 only in NDK/NIMU transport                                                                                       | Issue not observed when both ports are used and configured. Limited to board with only port 2 active                                                                                                                         |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3391   | k2g                    | EDMA-LLD                  | EDMA-LLD Sample library: Run time interrupt handling incorrect for EventCombiner APIs. Applicable for C66x/C67x cores                   | Application can override rm\\sample\\src\\sample\_cs.c source file with changes.                                                                                                                                             |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3267   | k2g                    | NIMU                      | NIMU\_ICSS\_CCLinkSlave\_idkAM437x\_wSoCLib\_armExampleProject hangs during build on linux                                              | Use CCS 7.3 on Windows                                                                                                                                                                                                       |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3383   | am574x-idk             | Board Diagnostic          | Diagnostic lcdTouchscreen\_TEST hangs on AM574x IDK                                                                                     | None                                                                                                                                                                                                                         |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3383   | c6657-evm              | EMAC-LLD                  | EMAC\_evmc6657\_C66Loopback\_testProject fails on C665x platform                                                                        | SOC configuration update needed for interrupt config. Fix available in external GIT                                                                                                                                          |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3236   | k2e,k2l                | SA-LLD                    | PDK: SA\_BasicExample hangs on K2E, K2L platforms in nightly                                                                            | Issue observed in CCS-Windows. Can use CCS - Linux host environment as workaround                                                                                                                                            |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3344   | am572x-id,am574x-idk   | Board Diagnostics         | Diagnostics icssEmac\_TEST idkAM57{2/4}x : LINK IS DOWN, pluggin loopback cable                                                         | None                                                                                                                                                                                                                         |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3369   | am574x-idk             | PCIE-LLD                  | PCIE board to board ARM test examples hangs on idkAM574x platform                                                                       | None                                                                                                                                                                                                                         |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-642    | \*                     | Processor SDK Installer   | RTOS: SDK components should be signed to avoid Eclipse/CCS warning when importing                                                       | Ignore the Eclipse/CCS warning                                                                                                                                                                                               |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+
| PRSDK-3318   | K2G 1Ghz               | EMAC                      | EMAC\_CpswRateLimit\_evmK2G\_c66xExampleProject failure on 1GHz Flip Chip                                                               | None                                                                                                                                                                                                                         |
+--------------+------------------------+---------------------------+-----------------------------------------------------------------------------------------------------------------------------------------+------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------+

.. rubric:: Installation and Usage
   :name: installation-and-usage

The `Getting Started
Guide </index.php/Processor_SDK_RTOS_Getting_Started_Guide>`__ provides
instructions on how to setup up your development environment, install
the SDK and start your development.

To uninstall the SDK, remove the individual component directories from
the installed path. This is safe to do even in Windows since these
components do not modify the Windows registry.

| 

.. rubric:: Host Support
   :name: host-support

The recommended development host is

-  **Windows**: Windows 10 on 64-bit machine
-  **Linux**: Ubuntu 16.04 on 64-bit machine

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
The Windows installer is a 32-bit binary, but is compatibility with
64-bit machine.

.. raw:: html

   </div>

| 

.. rubric:: Technical Support and Product Updates
   :name: technical-support-and-product-updates

For further information or to report any problems, contact TI E2E:

-  `Sitara Processor <http://e2e.ti.com/support/arm/sitara_arm/f/791>`__
   for AM335x, AM437x, and AM57x
-  `C6000 Multicore
   DSP <http://e2e.ti.com/support/dsp/c6000_multi-core_dsps/f/639>`__
   for C665x, C667x, K2E, K2G, K2H, and K2L
-  `OMAP
   Processor <http://e2e.ti.com/support/dsp/omap_applications_processors/f/42>`__
   for OMAP-L13x, C674x

| 

