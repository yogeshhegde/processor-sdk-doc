************************************
Release Notes
************************************

.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Release_Notes

Overview
==========

The **Processor Software Development Kit (Processor-SDK)** provides the
core foundation and building blocks that facilitate application software
development on TI's embedded processors. This *Release Notes* focuses on
the Real-time operating system (RTOS).

| 

Licensing
===========

Please refer to the software manifest, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page or in the installed directory as
indicated below.

| 

Documentation
===============

-  :ref:`Getting Started Guide <Processor-SDK-RTOS-Getting-Started-Guide-label>`:
   Provides information on getting the software and running basic
   examples/demonstrations bundled in the SDK.
-  :ref:`Migration Guide <RTOS-SDK-Migration-Guide-label>` Provides
   migration information for applications built on top of the Processor
   SDK for RTOS.
-  :ref:`Software Developer Guide <Index-Processor-SDK-RTOS-label>`
   Provides information on features, functions, delivery package and,
   compile tools for the Processor SDK RTOS release. This also provides
   detailed information regarding software elements and software
   infrastructure to allow developers to start creating applications.
-  **Software Manifest**: Provides license information on software
   included in the SDK release. This document is in the release at
   ``/processor_sdk_rtos_<SOC>_<version>/docs`` and available to view
   from the software download page.
-  **EVM Quick Start Guide**: Provides information on hardware setup and
   running the demonstration application that is loaded on flash. This
   document is provided as part of the EVM kit.

| 
Processor SDK v05.01.00 
========================

Released Sept 30 2018

.. rubric::  What's New
   :name: whats-new

.. rubric::  New Features
   :name: new-features

-  Processor SDK software GA support extension for SOC: AM65x and EVMs:am65xx-evm and am65xx-idk
 
   All unit tests for drivers in the case of AM65x SOC is available through standard makefile infrastructure.Use make all or gmake all from top level pdk_am65xx_1_0_x\packages after setting the environment using pdksetupenv.bat|sh
   Updates from EA Release:
   SBL (Boot Loader Support) for MMCSD and OSPI interface
   Additional Drivers: PCIe, UDMA LLD, DSS, CAL
   Additional firmware: PRU-ICSS-G Dual EMAC support
   Refer Release Note for details of component supported
   
-  PRU-ICSS Dual EMAC Firmware : Multicast filtering and PTP Feature externsion
-  AM437x PRU-ICSS I2C Firmware 
   Additional support for ICSS-0 instance   
-  AM335x Connectivity extension to support Simplelink (3120 NWP) WiFi
.. rubric::  Component Version
   :name: component-version

The following software components and host tools are bundled with the
SDK installer. See the :ref:`Software Developer Guide <Index-Processor-SDK-RTOS-label>` for
more information on each item.

.. note::
   | This release has been tested with the following component and tool versions. It is recommended to use the versions listed here to avoid compatibility issues. 

+-------------+-------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  Component  |   Version   |AM335x|AM437x|AM57x |AM65x |K2H/K2K| K2E  | K2L  | K2G  |C665x |C667x |OMAP-L137|OMAP-L138|
+=============+=============+======+======+======+======+=======+======+======+======+======+======+=========+=========+
| CG_XML      | 2.41.0      |   X  |  X   |  X   |  X   |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+-------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
| CTOOLSLIB   | 2.2.0.0     |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |         |         |
+-------------+-------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  DSPLIB     | 3.4.0.0     |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+-------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  EDMA3 LLD  | 2.12.5.30   |   X  |  X   |  X   |      |       |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+-------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  FC         | 3.40.2.7    |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |         |         |
+-------------+-------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  FFTLIB     | 3.1.0.0     |      |      |      |      |       |      |      |      |      |  X   |         |         |
+-------------+-------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  IMGLIB     | 3.1.1.0     |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |         |         |
+-------------+-------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  IPC        | 3.50.1      |      |      |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |         |    X    |
+-------------+-------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  LIBARCH    | 1.0.0.0     |      |      |      |      |   X   |      |      |      |      |  X   |         |         |
+-------------+-------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
| LINALG      | 1.2.0.0     |      |      |      |      |   X   |      |      |      |      |  X   |         |         |
+-------------+-------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
| MATHLIB      | 3.1.1.0    |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+--------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
| MPM          | 3.0.4.0    |      |      |      |      |   X   |  X   |  X   |  X   |      |      |         |         |
+--------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
| NDK          | 3.40.1     |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+--------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
| NS           | 2.40.1     |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+--------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
| OPENCL       | 1.1.14.1   |      |      |  X   |      |       |      |      |      |      |      |         |         |
+--------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  OPENMP      |Per platform|      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |         |         |
+--------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  PDK         |            |1.0.11|1.0.11|1.0.11| 1.0.2| 4.0.10|4.0.10|4.0.10|1.0.10|2.0.10|2.0.10|  1.0.5  |  1.0.5  |
+--------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  SYS/BIOS    | 6.73.0.03  |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+--------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  UIA         | 2.21.2.07  |      |      |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+--------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  XDAIS       | 7.24.0.4   |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+--------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  XDCTOOLS    | 3.50.04.43 |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+--------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+


The following compilers are bundled with the SDK installer:

+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+
|    Compiler    | Version |AM335x|AM437x|AM57x |AM65x |K2H/K2K| K2E | K2L    |  K2G   |C665x|C667x|OMAP-L137|OMAP-L138|
+================+=========+======+======+======+======+=======+=====+========+========+=====+=====+=========+=========+
|GNU ARM Embedded|6-2017-q1|   A8 |  A9  |  A15 |      |  A15  | A15 | A15    |  A15   |     |     |         |         |
+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+
|GNU Linaro GCC  |7.2.1    |      |      |      | A53  |       |     |        |        |     |     |         |         |
+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+
|TI ARM CGT      | 16.9.4  |      |      |  M4  |  R5  |       |     |A15(SBL)|        |     | ARM9|   ARM9  |         |
+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+
|TI C6000 CGT    | 8.2.2   |      |      | C66x |      |C66x   |C66x | C66x   |  C66x  |C66x |C66x |   C74x  |   C74x  |
+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+
|TI PRU CGT      | 2.2.1   | PRU  | PRU  | PRU  |      |       |     |  PRU   |        |     |     |         |         |
+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+

The SDK uses Code Composer Studio (CCS) as the integrated development
environment (IDE) for all devices and EVMs:

+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+
| Component | Version  |AM335x|AM437x|AM57x |AM65x |K2H/K2K| K2E | K2L | K2G |C665x|C667x|OMAP-L137|OMAP-L138|
+===========+==========+======+======+======+======+=======+=====+=====+=====+=====+=====+=========+=========+
|   CCS     | 8.1.0.11 |   X  |  X   |  X   |  X   |   X   |  X  |  X  |  X  |  X  |  X  |    X    |    X    |
+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+
|   EMU Pack| 8.0.598.14      |      |      |  X   |       |     |     |     |     |     |         |         |
+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+

If you need to install CCS, see the `CCS installation section <Overview.html#code-composer-studio>`__
in the *Getting Started Guide* for options to select for Processor-SDK.

**Change log**

Updated

- Support for AM65x SOC


Fixed Issues 
==============

+-----------------------+-----------------------+-------------------------------------+
|      Record ID        |       Platform        |       Summary                       |
+=======================+=======================+=====================================+
| PRSDK-642             | \*                    |RTOS: SDK components should be       |
|                       |                       |signed to avoid Eclipse/CCS warning  |
|                       |                       |when importing                       |
+-----------------------+-----------------------+-------------------------------------+
| PRSDK-3318            | k2g                   |EMAC_CpswRateLimit_evmK2G_c66x       |
|                       |                       |ExampleProject failure on 1GHz       |
|                       |                       |Flip Chip                            |
+-----------------------+-----------------------+-------------------------------------+
| PRSDK-4016            | k2h                   |NDK stack task doesn't work after    |
|                       |                       |moving to any core other than core 0 |
+-----------------------+-----------------------+-------------------------------------+
| PRSDK-4546            | AM57x                 |SBL RPRC parser bug when checking    |
|                       |                       |section address for L1D range on DSP1|
+-----------------------+-----------------------+-------------------------------------+
| PRSDK-4460            | AM335x                |MDIOPhyRegRead incorrect execution   |
+-----------------------+-----------------------+-------------------------------------+
| PRSDK-4305            | omapl138              |BenchmarkProjectCreate.bat error     |
|                       |                       |: CGT_VERSION not set                |
+-----------------------+-----------------------+-------------------------------------+
| PRSDK-4197            | AM57x                 |UARTDivisorValCompute does not       |
|                       |                       |round up to nearest integer          |
|                       |                       |resulting in large baudrate errors   |
+-----------------------+-----------------------+-------------------------------------+
| PRSDK-4197            | AM57x                 |UART LLD input clock control         |
|                       |                       |required at LLD level.               |
+-----------------------+-----------------------+-------------------------------------+
| PRSDK-4197            | AM57x                 |UART open sets up incorrect          |
|                       |                       |baudrates for 921600 bps settings.   |
+-----------------------+-----------------------+-------------------------------------+


Known Issues 
==============

This section contains the list of known issues at the time of making the
release and any known workaround.

.. csv-table::
   :header: "Record ID","Board/s", "Component/s", "Summary","Workaround"
   :widths: 15, 20,20,30,70
   
	PRSDK-4706,"am654x-evm, am654x-idk",Boot,SBL: MCU0 Boot in R5 Split Mode not supported in SBL,SBL supports Dual R5 configuration boot
	PRSDK-4617,"am335x-evm, am335x-sk, am437x-sk, amic110-ice, beagleboneblack","Control Drivers, Networking",CortxA8: Semihostsupport warning in CCS,Warning can be ignored
	PRSDK-4662,"am654x-evm, am654x-idk",Diagnostics,Board diagnostics application intermittently hangs,Issue is seen due to PLL initialization in the led test. PLL initialization can be skipped in LED test or test could be bypassed
	PRSDK-4412,,System,Processor SDK RTOS Windows installer needs to be signed,Warning message if seen can be ignored
	PRSDK-4727,am437x-idk,Diagnostics,ledIndustrial_TEST of Diagnostics hangs,Delay value need to be tuned for the SOC. Add BoardDiag_AppDelay(0x1FFFF); after Board_i2cIoExpWritePort() for test to pass
	PRSDK-4743,am654x-evm,Networking,Moving host buffers to DDR results in icss-g dual mac performance degredation (FTP put/get),Buffer placement in on chip MSMC memory expected to improve throughput
	PRSDK-4121,am654x-evm,Boot,make all fails for Windows due to missing openSSL package,"openSSL package not available in installer. 
	Install`Strawberry Perl <http://strawberryperl.com/download/5.26.2.1/strawberry-perl-5.26.2.1-64bit.msi>`__ 
	Run gmake all on DOS prompt with admin privilege"
	PRSDK-4541,"am571x-idk, c6748-lcdk, k2g-evm, omapl138-lcdk",OSAL,OSAL_BasicExample DSP LE hangs on c6748-lcdk,
	PRSDK-4721,k2g-ice,Diagnostics,"Diagnostics EMAC iceK2G: test hangs after ""Received Packet: 10""",
	PRSDK-4462,am654x-evm,System,IPC A53 ROV log won't show correctly because of XDCtools bug,Need to recompile examples/test with new XDC tool to resolve issues.
	PRSDK-4184,am572x-evm,Example,Hello_World: Baremetal ARM Cortex-A15 test example failure,Problem observed with using GCC semihosting support. Can use UART driver for input and output
	PRSDK-3482,"am335x-evm, am335x-ice, am335x-sk, am437x-evm, am437x-idk, am437x-sk, am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk, amic110-ice, beagleboneblack, c6657-evm, c6678-evm, c6748-evm, c6748-lcdk, k2e-evm, k2g-evm, k2g-ice, k2h-evm, k2k-evm, k2l-evm, omapl137-evm, omapl138-lcdk",CCS,CCSV8.1: Intermittent issue not able to connect target while using DSS script,Retry for connection failure in DSS script.
	PRSDK-3116,am335x-evm,High-Speed Drivers,USB Dev MSC drive corruptions after unplugging and replugging the cable,
	PRSDK-4145,c6678-evm,Control Drivers,SPI v0 ISR hangs processor when RX data is not ready after TX data has sent,"Add a WHILE delay loop in after the 
	SPI_INT_TX_EMPTY is processed, until SPI_INT_RX_FULL is set."
	PRSDK-4108,omapl138-lcdk,High-Speed Drivers,USB Audio: Lag when trying to adjust volume,
	PRSDK-4456,omapl138-lcdk,Control Drivers,OMAPL138 SPI driver doesn't configure clock polarity and phase when in slave mode,
	PRSDK-4529,"am335x-evm, am335x-ice, am335x-sk, am437x-evm, am437x-idk, am437x-sk, am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk, amic110-ice, beagleboneblack, c6657-evm, c6678-evm, c6748-evm, c6748-lcdk, k2e-evm, k2g-evm, k2g-hsevm, k2g-ice, k2h-evm, k2k-evm, omapl137-evm, omapl138-evm, omapl138-lcdk",KeyStone Drivers,UART LLD can't read value 0xff byte over the UART as it is detected as -1 (error),
	PRSDK-4526,"am654x-evm, am654x-idk",Board Support,R5 Interrupts will not work when program is loaded using CCS,"If code is loaded using CCS, the reset vector must be at 0x41C00000"
	PRSDK-4180,,UNIFLASH,Sitara Uniflash CLI Plugin could not open COM ports with number higher than 9,Select COM ports in lower range
	PRSDK-4689,"c6657-evm, c6678-evm",Networking,NIMU example fails compilation for big endian projects. Feature being descoped,
	PRSDK-2892,"am571x-idk, am572x-evm, am572x-idk",PDK,Incorrect A15 MMU configurations in default config file,"Set MMU attribute to not executable for device memory 
	attrs0.noExecute = true; // Not executable"
	PRSDK-4725,"am335x-ice, am437x-idk",PDK,PTP: ICSS-M /EMAC LLD Master Mode config does not sync with slave,
	PRSDK-4667,am572x-evm,"Demonstrations, Networking",Image Processing Demo lock up on AM572x GP EVM,Issue seen using 1Gig router on ETH0. Replace with 100Mbps
	PRSDK-4304,"am335x-evm, am335x-ice, amic110-ice",Board Support,Flash Writer pre-built Binary does not work,Rebuilding the flash writer binaries shall fix this issue. Refer the Rebuilding the flash writer
	PRSDK-3369,am574x-idk,High-Speed Drivers,PCIE board to board ARM test examples hangs,
	PRSDK-3383,am574x-idk,Diagnostics,Diagnostics: lcdTouchscreen_TEST hangs,
	PRSDK-4214,k2g-hsevm,System,create-sdcard script does not boot OOB,Default generated App image is not signed follow the steps mentioned in User Guide of the Processor SDK Secdev Build and Install Guide to sign the app
	PRSDK-2336,"am335x-evm, am437x-evm",Power,PM LLD test failing using CCS/JTAG,"The debug versions of the PM apps are still functional. To build them: 
	From the top-level makefile in pdk.../packages folder run ""make BUILD_PROFILE=debug pm"" 
	This will build the debug versions of the PM RTOS and measurement apps."
	PRSDK-3344,"am572x-idk, am574x-idk",Diagnostics,"Diagnostics icssEmac_TEST idkAM57{2/4}x : LINK IS DOWN, pluggin loopback cable",ICSS-EMAC LLD TI-RTOS example can be used for similar test.
	PRSDK-1975,am572x-evm,Diagnostics,timer_DiagExample_evmAM572x_arm7.out doesn't work on ARM1 core,Example can run on ARM Core 0
	PRSDK-2166,am572x-idk,High-Speed Drivers,USB3.0 host problem with Sandisk Extreme USB3.0 stick,"Start the example without the USB plugged in. Once the example is up and waiting for USB stick, plug the USB stick in and it will enumerate properly."
	PRSDK-1682,"am571x-idk, am572x-idk",Diagnostics,Board diagnostics LCD Touchscreen test does not work with new version of LCD TSC,For LCD/Display checkout example under VPS component could be used
	PRSDK-330,AM4X,High-Speed Drivers,USB device MSC re-enumeration failed,Problem not observed with Linux USB Host.
	PRSDK-4639,"am654x-evm, am654x-idk",Chip Support,SBL examples currently does not program loaded from DDR for R5 core,
	PRSDK-4050,"am654x-evm, am654x-idk",Control Drivers,RTOS: K3: OSPI high speed mode is not supported,"OSPI driver not functional for Full rate 133, 166 MHz with PHY enabled. Workaround by default is enabled in driver with PHY disabled. No change required for application"
	PRSDK-4771,"am654x-evm, am654x-idk",High-Speed Drivers,MMCSD_EMMC_Regression_TestApp hangs during DDR part of test,
	PRSDK-4464,"am654x-evm, am654x-idk",Networking,ICSS-G-FW: Dual-emac: ping with 16K packet size fails,
	PRSDK-335,"AM4X, k2g-evm",High-Speed Drivers,USB host MSC fails to re-enumerate,Re-enumeration support for the case of device unplugged and plugged back currently fails for the example. Workaround is to avoid disconnecting drive while running example.
	PRSDK-4704,"am654x-evm, am654x-idk",PDK,R5F RTOS MPU attributes don`t support running out of ATCM memory,"Workaround 
	Current MPU settings set permission and sets ATCM region as 1KB size which needs to be changed to 32 KB Modify following from. 
	MPU.setRegionMeta(1, 0x00000000, MPU.RegionSize_1K, attrs); 
	To 
	MPU.setRegionMeta(1, 0x00000000, MPU.RegionSize_32K, attrs); 
	"
	PRSDK-4718,"am654x-evm, am654x-idk",Board Support,DDR Controller ECC Scrubbing feature can cause DRAM data corruption,
	PRSDK-4668,,Board Support,AM65xx Diag: ICSSG Ethernet Test hang while running second time,


.. RN_Supported-Platforms-label:
Supported Platforms 
=====================

Devices 
---------

The following table lists all supported devices for a given installer.

+----------------+------------+-------------------------------------------------------------------------------+
|   Installer    |Platform/SOC|                                 Supported Devices                             |
+================+======+=====+===============================================================================+
|                |`AM335x`_   | `AM3351`_, `AM3352`_, `AM3354`_, `AM3356`_, `AM3357`_, `AM3358`_, `AM3359`_   |
|`RTOS-AM335X`_  +------------+-------------------------------------------------------------------------------+
|                |`AMIC11x`_  | `AMIC110`_                                                                    |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-AM437X`_  |`AM437x`_   | `AM4376`_, `AM4377`_, `AM4378`_, `AM4379`_                                    |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-AM57X`_   |`AM57x`_    |`AM5706`_, `AM5708`_, `AM5716`_, `AM5718`_, `AM5726`_, `AM5728`_,              |
|                |            |`AM5746`_, `AM5748`_                                                           |
+----------------+------------+-------------------------------------------------------------------------------+
|RTOS-AM65X      |AM65x       |AM65xx Family of SOCs (AM6526,AM6528,AM6546,AM6548)  Available through mySecure |
+----------------+------------+-------------------------------------------------------------------------------+
|RTOS-AM65X      |AM65x       |AM65xx Family of SOCs(AM6526,AM6528,AM6546,AM6548)  Available through mySecure |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-C665X`_   |`C665x`_    | `C6652`_, `C6654`_, `C6655`_, `C6657`_                                        |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-C667X`_   |`C667x`_    | `C6671`_, `C6672`_, `C6674`_, `C6678`_                                        |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-K2E`_     |`K2E`_      | `66AK2E02`_, `66AK2E05`_, `AM5K2E02`_, `AM5K2E04`_                            |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-K2G`_     |`K2G`_      | `66AK2G02`_, `66AK2G12`_                                                      |
+----------------+------------+-------------------------------------------------------------------------------+
|                |`K2H`_      | `66AK2H06`_, `66AK2H12`_, `66AK2H14`_                                         |
| `RTOS-K2HK`_   +------------+-------------------------------------------------------------------------------+
|                |`K2K`_      | `TCI6638K2K`_                                                                 |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-K2L`_     |`K2L`_      | `66AK2L06`_                                                                   |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-OMAPL137`_|`OMAP-L1x`_ | `OMAP-L137`_, `C6743`_, `C6745`_, `C6747`_                                    |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-OMAPL138`_|`OMAP-L1x`_ | `OMAP-L138`_, `C6742`_, `C6746`_, `C6748`_                                    |
+----------------+------------+-------------------------------------------------------------------------------+


.. _RTOS-AM335X: http://software-dl.ti.com/processor-sdk-rtos/esd/AM335X/latest/index_FDS.html
.. _AM335x: http://www.ti.com/am335x
.. _AM3351: http://www.ti.com/product/am3351
.. _AM3352: http://www.ti.com/product/am3352
.. _AM3354: http://www.ti.com/product/am3354
.. _AM3356: http://www.ti.com/product/am3356
.. _AM3357: http://www.ti.com/product/am3357
.. _AM3358: http://www.ti.com/product/am3358
.. _AM3359: http://www.ti.com/product/am3359

.. _AMIC11x: http://www.ti.com/lsds/ti/processors/sitara/industrial-ethernet/amic11x/amic11x-overview.page>`__
.. _AMIC110: http://www.ti.com/product/amic110

.. _RTOS-AM437X: http://software-dl.ti.com/processor-sdk-rtos/esd/AM437X/latest/index_FDS.html
.. _AM437x: http://www.ti.com/am437x
.. _AM4376: http://www.ti.com/product/am4376
.. _AM4377: http://www.ti.com/product/am4377
.. _AM4378: http://www.ti.com/product/am4378
.. _AM4379: http://www.ti.com/product/am4379

.. _RTOS-AM57X: http://software-dl.ti.com/processor-sdk-rtos/esd/AM57X/latest/index_FDS.html
.. _AM57x: http://www.ti.com/am57x
.. _AM5706: http://www.ti.com/product/am5706
.. _AM5708: http://www.ti.com/product/am5708
.. _AM5716: http://www.ti.com/product/am5716
.. _AM5718: http://www.ti.com/product/am5718
.. _AM5726: http://www.ti.com/product/am5726
.. _AM5728: http://www.ti.com/product/am5728
.. _AM5746: http://www.ti.com/product/am5746
.. _AM5748: http://www.ti.com/product/am5748

.. _RTOS-C665X: http://software-dl.ti.com/processor-sdk-rtos/esd/C665x/latest/index_FDS.html
.. _C665x: http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp/c66x/overview.page
.. _C6652: http://www.ti.com/product/tms320c6652
.. _C6654: http://www.ti.com/product/tms320c6654
.. _C6655: http://www.ti.com/product/tms320c6655
.. _C6657: http://www.ti.com/product/tms320c6657

.. _RTOS-C667X: http://software-dl.ti.com/processor-sdk-rtos/esd/C667x/latest/index_FDS.html
.. _C667x: http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp/c66x/overview.page
.. _C6671: http://www.ti.com/product/tms320c6671
.. _C6672: http://www.ti.com/product/tms320c6672
.. _C6674: http://www.ti.com/product/tms320c6674
.. _C6678: http://www.ti.com/product/tms320c6678

.. _RTOS-K2E: http://software-dl.ti.com/processor-sdk-rtos/esd/K2E/latest/index_FDS.html
.. _K2E: http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp-arm/66ak2x/overview.page
.. _66AK2E02: http://www.ti.com/product/66ak2e02
.. _66AK2E05: http://www.ti.com/product/66ak2e05
.. _AM5K2E02: http://www.ti.com/product/am5k2e02
.. _AM5K2E04: http://www.ti.com/product/am5k2e04

.. _RTOS-K2G: http://software-dl.ti.com/processor-sdk-rtos/esd/K2G/latest/index_FDS.html
.. _K2G: http://www.ti.com/processors/dsp/c6000-dsp-arm/66ak2x/overview.html
.. _66AK2G02: http://www.ti.com/product/66ak2g02
.. _66AK2G12: http://www.ti.com/product/66ak2g12

.. _RTOS-K2HK: http://software-dl.ti.com/processor-sdk-rtos/esd/K2HK/latest/index_FDS.html
.. _K2H: http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp-arm/66ak2x/overview.page
.. _66AK2H06: http://www.ti.com/product/66ak2h06
.. _66AK2H12: http://www.ti.com/product/66ak2h12
.. _66AK2H14: http://www.ti.com/product/66ak2h14

.. _K2K: http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp-arm/66ak2x/overview.page
.. _TCI6638K2K: http://www.ti.com/product/tci6638k2k

.. _RTOS-K2L: http://software-dl.ti.com/processor-sdk-rtos/esd/K2L/latest/index_FDS.html
.. _K2L: http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp-arm/66ak2x/overview.page
.. _66AK2L06: http://www.ti.com/product/66ak2l06

.. _RTOS-OMAPL137: http://www.ti.com/tool/processor-sdk-omapl137
.. _OMAP-L1x: http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp-arm/omap-l1x/overview.page
.. _OMAP-L137: http://www.ti.com/product/OMAP-L137
.. _C6743: http://www.ti.com/product/tms320c6743
.. _C6745: http://www.ti.com/product/tms320c6745
.. _C6747: http://www.ti.com/product/tms320c6747

.. _RTOS-OMAPL138: http://www.ti.com/tool/processor-sdk-omapl138
.. _OMAP-L1x: http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp-arm/omap-l1x/overview.page
.. _OMAP-L138: http://www.ti.com/product/OMAP-L138
.. _C6742: http://www.ti.com/product/tms320c6742
.. _C6746: http://www.ti.com/product/tms320c6746
.. _C6748: http://www.ti.com/product/tms320c6748

Evaluation Modules 
--------------------

See `Processor SDK Supported Platforms <Release_Specific.html#supported-platforms-and-versions>`__
page for a list of supported EVMs per platform and links to more
information.

Demonstrations 
----------------

See `Examples and Demonstrations <Examples_and_Demonstrations.html>`__
page for a list of demonstrations per platform and EVM.

Drivers 
---------

The following tables show RTOS driver availability per platform and EVM.
A shaded box implies that the feature is not applicable for that
platform/EVM.

**Sitara devices**

+------------------+--------------------+---------------+-----------+-----------+-----------+
|     Feature      |    Platform/SOC    |  AM335x EVM   |AM437x EVM | AM57x EVM | AM65x EVM |
+==================+=======+======+=====+===+===+===+===+===+===+===+=====+=====+=====+=====+
|                  |AM335x |AM437x|AM57x|GP |ICE|SK |BBB|GP |IDK|SK | GP  | IDK | GP  | IDK |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| CSL              |   X   |   X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| EMAC             |   X   |   X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| EDMA3            |   X   |   X  |  X  | X |   |   |   | X |   |   |  X  |     |     |     |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| GPIO             |   X   |   X  |  X  |   | X |   | X | X |   | X |  X  |  X  |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| GPMC             |   X   |   X  |     |   | X |   |   | X |   |   |     |     |     |     |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| I2C              |   X   |   X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| PRUSS-I2C f/w    |   X   |   X  |  X  |   | X |   |   |   | X |   |     |  X  |     |     |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| ICSS-EMAC        |   X   |   X  |  X  |   | X |   |   |   | X |   |     |  X  |     |     |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| McASP            |   X   |   X  |  X  | X |   |   |   | X |   |   |  X  |     |  X  |     |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| McSPI            |   X   |   X  |  X  |   | X |   |   |   | X |   |     |  X  |   X |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| MMC-SD           |   X   |   X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| PCIe             |       |      |  X  |   |   |   |   |   |   |   |     |  X  |  X  |     |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| PM               |   X   |      |  X  | X |   |   |   |   |   |   |  X  |     |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| PRUSS            |   X   |   X  |  X  |   | X |   |   |   | X |   |     |  X  |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| QSPI             |       |   X  |  X  |   |   |   |   |   | X | X |     |  X  |     |     |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| OSPI             |       |      |     |   |   |   |   |   |   |   |     |     |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| UART             |   X   |   X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| USB              |   X   |   X  |  X  | X |   |   |   | X |   |   |  X  |  X  |  X  |   X |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| USB Device Audio |   X   |      |     | X |   |   |   |   |   |   |     |     |     |     |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| VPS              |       |      |  X  |   |   |   |   |   |   |   |  X  |  X  |     |     |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| UDMA             |       |      |     |   |   |   |   |   |   |   |     |     |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| OSPI             |       |      |     |   |   |   |   |   |   |   |     |     |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| SCICLIENT        |       |      |     |   |   |   |   |   |   |   |     |     |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| SA               |       |      |     |   |   |   |   |   |   |   |     |     |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| CAL              |       |      |     |   |   |   |   |   |   |   |     |     |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| DSS              |       |      |     |   |   |   |   |   |   |   |     |     |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+


**DSP devices - K2x, C66x**

+------------------+-------------------------------+-----------------------+-----------+
|     Feature      |         Platform/SOC          |        K2 EVM         | C66x EVM  |
+==================+=======+===+===+===+=====+=====+===+===+===+===+=======+=====+=====+
|                  |K2H/K2K|K2E|K2L|K2G|C665x|C667x|K2H|K2E|K2L|K2G|K2G-ICE|C665x|C667x|
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| CSL              |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| AIF2             |   X   |   |   |   |     |     | X |   |   |   |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| BCP              |   X   |   | X |   |     |     | X |   | X |   |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| CPPI             |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| DFE              |       |   | X |   |     |     |   |   | X |   |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| EDMA3            |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| EMAC             |       |   |   | X |  X  |     |   |   |   | X |   X   |  X  |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| FFTC             |   X   |   | X |   |     |     | X |   | X |   |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| GPIO             |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| HYPLNK           |   X   | X |   |   |  X  |  X  | X | X |   |   |       |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| ICSS-EMAC        |       |   |   | X |     |     |   |   |   |   |   X   |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| I2C              |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| IQN2             |       |   | X |   |     |     |   |   | X |   |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| McASP            |       |   |   | X |     |     |   |   |   | X |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| McBSP            |       |   |   | X |  X  |     |   |   |   | X |       |  X  |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| MMAP             |   X   | X |   |   |     |     | X | X |   |   |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| MMC-SD           |       |   |   | X |     |     |   |   |   | X |   X   |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| NWAL             |   X   | X | X |   |     |  X  | X | X | X |   |       |     |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| PA               |   X   | X | X |   |     |  X  | X | X | X |   |       |     |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| PCIe             |   X   | X | X | X |  X  |  X  | X | X | X | X |       |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| QMSS             |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| RM               |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| SA               |   X   | X | X | X |     |  X  | X | X | X | X |       |     |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| SPI              |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| SRIO             |   X   |   |   |   |  X  |  X  | X |   |   |   |       |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| TCP3D            |   X   |   | X |   |  X  |     | X |   | X |   |       |  X  |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| TSIP             |       | X |   |   |     |  X  |   | X |   |   |       |     |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| UART             |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| USB              |       |   |   | X |     |     |   |   |   | X |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| USB Device Audio |       |   |   |   |     |     |   |   |   |   |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| USB Device Bulk  |       |   |   | X |     |     |   |   |   |   |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+


**DSP devices - OMAP-L13x, C674x**

+----------------+-------------------+-------------+----------------+
|    Feature     |   Platform/SOC    |OMAP-L137 EVM| OMAP-L138 EVM  |
+================+=========+=========+=============+=======+========+
|                |OMAP-L137|OMAP-L138| 137/6747 SK |LCDK138|LCDK6748|
+----------------+---------+---------+-------------+-------+--------+
|CSL             |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|EDMA3           |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|EMAC            |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|GPIO            |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|I2C             |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|McASP           |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|MMC-SD          |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|SPI             |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|UART            |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|USB             |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|USB Device Audio|    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+

**Unsupported Features**

- In general driver support is available across all cores within an SOC
  with following exceptions
+----------------+-------------------+
|    Feature     | Not supported     |
+================+=========+=========+
|                |SOC      |CPU/Core |
+----------------+---------+---------+
|McASP           |  AM57x  |    M4   |
+----------------+---------+---------+
|USB             |  AM57x  |    C66x |
+----------------+---------+---------+
|USB             |  AM57x  |    M4   |
+----------------+---------+---------+
|McBSP           |  K2G    |    A15  |
+----------------+---------+---------+
|McBSP           |OMAP-L13x|    ARM9 |
+----------------+---------+---------+
|All Drivers     |  K2x    |    A15  |
+----------------+---------+---------+

Other Features 
----------------

The following table shows other feature availability per platform and
EVM:

**Sitara devices**

+----------------------------+--------------------+---------------+-----------+-----------+-----------+
|          Feature           |    Platform/SOC    |  AM335x EVM   |AM437x EVM | AM57x EVM | AM65x EVM |
+============================+=======+======+=====+===+===+===+===+===+===+===+=====+=====+=====+=====+
|                            |AM335x |AM437x|AM57x|GP |ICE|SK |BBB|GP |IDK|SK | GP  | IDK | GP  | IDK |
+----------------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| Board Support              |   X   |  X   |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |
+----------------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| Boot (SBL)                 |   X   |  X   |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |
+----------------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| Diagnostics                |   X   |  X   |  X  | X |   |   |   | X |   |   |  X  |  X  |  X  |  X  |
+----------------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| FATFS                      |   X   |  X   |  X  | X | X |   |   | X | X |   |  X  |  X  |  X  |  X  |
+----------------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| NDK-NIMU(CPSW)             |   X   |  X   |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |
+----------------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
| NDK-NIMU(ICSS)             |   X   |  X   |  X  |   | X |   |   |   | X |   |     |  X  |  X  |  X  |
+----------------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
|CC-LINK IE Field Basic(CPSW)|   X   |  X   |  X  | X | X | X | X | X | X | X |  X  |  X  |     |     |
+----------------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+
|CC-Link IE Field Basic(ICSS)|   X   |  X   |  X  |   | X |   |   |   | X |   |     |  X  |     |     |
+----------------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+

**DSP devices - K2x, C66x**

+----------------------------+-------------------------------+-----------------------+-----------+
|          Feature           |         Platform/SOC          |        K2 EVM         | C66x EVM  |
+============================+=======+===+===+===+=====+=====+===+===+===+===+=======+=====+=====+
|                            |K2H/K2K|K2E|K2L|K2G|C665x|C667x|K2H|K2E|K2L|K2G|K2G-ICE|C665x|C667x|
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| Board Support              |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| Boot (IBL/SBL)             |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| Diagnostics                |       |   |   | X |     |     |   |   |   | X |   X   |     |     |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| FATFS                      |       |   |   | X |     |     |   |   |   | X |   X   |     |     |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| Fault Management           |   X   | X | X |   |     |     | X | X | X |   |       |     |     |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| IPC Transport (QMSS)       |   X   | X | X |   |  X  |  X  | X | X | X |   |       |  X  |  X  |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| IPC Transport (SRIO)       |   X   |   |   |   |  X  |  X  | X |   |   |   |       |  X  |  X  |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| MAD-UTIL                   |       |   |   |   |  X  |  X  |   |   |   |   |       |  X  |  X  |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| Network (CPSW)             |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| Network (ICSS)             |       |   |   | X |     |     |   |   |   | X |       |     |     |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
|CC-Link IE Field Basic(ICSS)|       |   |   | X |     |     |   |   |   | X |       |     |     |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
|Platform Library (obsolete) |   X   | X | X |   |  X  |  X  | X | X | X |   |       |  X  |  X  |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| PKTLIB                     |   X   | X | X |   |     |  X  | X | X | X |   |       |     |  X  |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| POST                       |   X   | X | X |   |  X  |  X  | X | X | X |   |       |  X  |  X  |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| SERDES Diagnostics         |   X   | X | X |   |     |     | X | X | X |   |       |     |     |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| Trace Framework            |   X   | X | X |   |     |     | X | X | X |   |       |     |     |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+


**DSP devices - OMAP-L13x, C674x**

+--------------+-------------------+-------------+----------------+
|   Feature    |   Platform/SOC    |OMAP-L137 EVM| OMAP-L138 EVM  |
+==============+=========+=========+=============+=======+========+
|              |OMAP-L137|OMAP-L138| 137/6747 SK |LCDK138|LCDK6748|
+--------------+---------+---------+-------------+-------+--------+
|Board Support |    X    |    X    |      X      |   X   |   X    |
+--------------+---------+---------+-------------+-------+--------+
|Boot (SBL)    |    X    |    X    |      X      |   X   |   X    |
+--------------+---------+---------+-------------+-------+--------+
|Diagnostics   |    X    |         |      X      |       |        |
+--------------+---------+---------+-------------+-------+--------+
|FATFS         |    X    |    X    |      X      |   X   |   X    |
+--------------+---------+---------+-------------+-------+--------+
|Network (CPSW)|    X    |    X    |      X      |   X   |   X    |
+--------------+---------+---------+-------------+-------+--------+

Installation and Usage 
========================

The :ref:`Getting Started Guide <Processor-SDK-RTOS-Getting-Started-Guide-label>` provides
instructions on how to setup up your development environment, install
the SDK and start your development.

To uninstall the SDK, remove the individual component directories from
the installed path. This is safe to do even in Windows since these
components do not modify the Windows registry.

| 

Host Support 
==============

The recommended development host is

-  **Windows**: Windows 10 on 64-bit machine
-  **Linux**: Ubuntu 16.04 on 64-bit machine

.. raw:: html

   <div
   style="margin: 5px 25px; padding: 2px 10px; background-color: #ecffff; border-top: 1px solid #3399ff; border-bottom: 1px solid #3399ff;">

**NOTE**

The Windows installer is a 32-bit binary, but is compatibile with
64-bit machine.

.. raw:: html

   </div>

| 

Technical Support and Product Updates 
=======================================

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

Archived 
==========

-  `Processor-SDK RTOS
   5.0.0 <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/05_00_00_15/Release_Specific.html#processor-sdk-rtos-release-notes>`__
-  `Processor-SDK RTOS
   5.0.0 AM65x EA Release <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/05_00_00_09/Release_Specific.html#processor-sdk-rtos-release-notes>`__
-  `Processor-SDK RTOS
   4.3.0 <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/04_03_00_05/rtos/Release_Specific.html#processor-sdk-rtos-release-notes>`__
-  `Processor-SDK RTOS
   4.2.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=232579>`__
-  `Processor-SDK RTOS
   4.1.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=231132>`__
-  `Processor-SDK RTOS
   4.0.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=229408>`__
-  `Processor-SDK RTOS
   3.3.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=227097>`__
-  `Processor-SDK RTOS
   3.2.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=223820>`__
-  `Processor-SDK RTOS
   3.1.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=222796>`__
-  `Processor-SDK RTOS
   3.0.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=220543>`__
-  `Processor-SDK RTOS
   2.0.2 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=216065>`__
-  `Processor-SDK RTOS
   2.0.1 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=211983>`__
-  `Processor-SDK RTOS
   2.0.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=208435>`__

| 

.. raw:: html
