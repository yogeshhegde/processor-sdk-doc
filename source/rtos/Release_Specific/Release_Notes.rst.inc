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

Processor SDK v05.03.00
========================

.. warning::
   Big-endian support for C66x and C674x platforms shall be deprecated in Processor SDK RTOS from the Release 6.0 (2Q-2019)

Released March 2019

.. rubric::  What's New
   :name: whats-new

.. rubric::  New Features
   :name: new-features

- AM65x
	- Additional Features
        - EA support for AM65x HS SOC
        - SBL Example app with XIP support
        - Additional SPI driver support for XIP mode
   		- `Uniflash <index_board.html#uniflash>`_ image load support over UART
        - PCIe driver update for Multiple interfaces, DMA and Interrupt Support
        - CAN to Ethernet Gateway Demo
	- Features not (yet) supported: USB 3.0, MPU TI-RTOS SMP Support,CTOOLSLIB
- OMAPL13x
    - DMA mode support for `SPI <index_device_drv.html#mcspi-qspi-ospi>`_ driver
- AM437x
    - IOLink driver and sample application support
- AM574x 
    - Support for C66x 1Ghz
- AM335x
    - PRU-ICSS Soft UART support
- Rx interrupt pacing support in EMAC firmware

.. rubric::  Component Version
   :name: component-version

The following software components and host tools are bundled with the
SDK installer. See the :ref:`Software Developer Guide <Index-Processor-SDK-RTOS-label>` for
more information on each item.

.. note::
   | This release has been tested with the following component and tool versions. It is recommended to use the versions listed here to avoid compatibility issues. 

+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  Component  |   Version  |AM335x|AM437x|AM57x |AM65x |K2H/K2K| K2E  | K2L  | K2G  |C665x |C667x |OMAP-L137|OMAP-L138|
+=============+============+======+======+======+======+=======+======+======+======+======+======+=========+=========+
| CG_XML      | 2.61.0     |   X  |  X   |  X   |  X   |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
| CTOOLSLIB   | 2.2.0.0    |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  DSPLIB     | 3.4.0.3    |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  EDMA3 LLD  | 2.12.5.30  |   X  |  X   |  X   |      |       |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  FC         | 3.40.2.7   |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  FFTLIB     | 3.1.0.0    |      |      |      |      |       |      |      |      |      |  X   |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  IMGLIB     | 3.1.1.0    |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  IPC        | 3.50.3     |      |      |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |         |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  LIBARCH    | 1.0.0.0    |      |      |      |      |   X   |      |      |      |      |  X   |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  LINALG     | 1.2.0.0    |      |      |      |      |   X   |      |      |      |      |  X   |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  MATHLIB    | 3.1.2.3    |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  MPM        | 3.0.4.0    |      |      |      |      |   X   |  X   |  X   |  X   |      |      |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  NDK        | 3.40.1     |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  NS         | 2.40.1     |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  OPENCL     | 1.1.18.0   |      |      |  X   |      |       |      |      |      |      |      |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  OPENMP     | 2.6.3.0    |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  PDK        |            |1.0.14|1.0.14|1.0.14| 1.0.4| 4.0.13|4.0.13|4.0.13|1.0.13|2.0.13|2.0.13|  1.0.8  |  1.0.8  |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  SYS/BIOS   | 6.75.2     |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  UIA        | 2.30.1.2   |      |      |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  XDAIS      | 7.24.0.4   |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  XDCTOOLS   | 3.51.01    |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+


The following compilers are bundled with the SDK installer:

+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+
|    Compiler    | Version |AM335x|AM437x|AM57x |AM65x |K2H/K2K| K2E | K2L    |  K2G   |C665x|C667x|OMAP-L137|OMAP-L138|
+================+=========+======+======+======+======+=======+=====+========+========+=====+=====+=========+=========+
|GNU ARM Embedded|7-2018-q2|   A8 |  A9  |  A15 |      |  A15  | A15 | A15    |  A15   |     |     |         |         |
+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+
|GNU Linaro GCC  | 7.2.1   |      |      |      | A53  |       |     |        |        |     |     |         |         |
+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+
|TI ARM CGT      | 18.1.5  |      |      |  M4  |  R5  |       |     |A15(SBL)|        |     | ARM9|   ARM9  |         |
+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+
|TI C6000 CGT    | 8.3.2   |      |      | C66x |      |C66x   |C66x | C66x   |  C66x  |C66x |C66x |   C74x  |   C74x  |
+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+
|TI PRU CGT      | 2.2.1   | PRU  | PRU  | PRU  |      |       |     |  PRU   |        |     |     |         |         |
+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+

The SDK uses Code Composer Studio (CCS) as the integrated development
environment (IDE) for all devices and EVMs:

+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+
| Component | Version  |AM335x|AM437x|AM57x |AM65x |K2H/K2K| K2E | K2L | K2G |C665x|C667x|OMAP-L137|OMAP-L138|
+===========+==========+======+======+======+======+=======+=====+=====+=====+=====+=====+=========+=========+
|   CCS     | 8.3.0    |   X  |  X   |  X   |  X   |   X   |  X  |  X  |  X  |  X  |  X  |    X    |    X    |
+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+
|   EMU Pack|Sitara    |   X  |  X   |  X   |  X   |       |     |     |     |     |     |         |         |
|           |Device    |      |      |      |      |       |     |     |     |     |     |         |         |
|           |1.4.4     |      |      |      |      |       |     |     |     |     |     |         |         |
+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+
|    TI     |8.0.903.2 |   X  |  X   |  X   |  X   |   X   |  X  |  X  |  X  |  X  |  X  |     X   |     X   |
| Emulators |          |      |      |      |      |       |     |     |     |     |     |         |         |
+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+

If you need to install CCS, see the `CCS installation section <Overview.html#code-composer-studio>`__
in the *Getting Started Guide* for options to select for Processor-SDK.



Fixed Issues 
==============

.. csv-table::
   :header: "Record ID","Board/s", "Component/s", "Summary"
   :widths: 15, 20,20,30
   
	PRSDK-3482,467700,am335x-evm,am335x-ice,am335x-sk,am437x-evm,am437x-idk,am437x-sk,am570x-evm,am571x-idk,am572x-evm,am572x-idk,am574x-idk,amic110-ice,beagleboneblack,c6657-evm,c6678-evm,c6748-evm,c6748-lcdk,k2e-evm,k2g-evm,k2g-ice,k2h-evm,k2k-evm,k2l-evm,omapl137-evm,omapl138-lcdk,CCS,,CCSV8.1: Intermittent issue not able to connect target while using DSS script
	PRSDK-5094,644902,am437x-idk,am571x-idk,am572x-idk,am574x-idk,,,,,,,,,,,,,,,,,,,,,,Control Drivers,,QSPI flash R/W performance issue in MMAP (DAC) mode
	PRSDK-4994,633303,am572x-evm,am572x-idk,am574x-idk,,,,,,,,,,,,,,,,,,,,,,,PDK,,CSL CPTS spec mismatch with TRM spec
	PRSDK-4108,544271,omapl138-lcdk,,,,,,,,,,,,,,,,,,,,,,,,,High-Speed Drivers,,USB Audio: Lag when trying to adjust volume
	PRSDK-4950,622093,am654x-evm,am654x-idk,,,,,,,,,,,,,,,,,,,,,,,,Networking,,am65xx: icssg-fw: TX lockup observed when trying to transmit and maintain 96ns IPG.
	PRSDK-4464,579179,am654x-evm,am654x-idk,,,,,,,,,,,,,,,,,,,,,,,,Networking,,ICSS-G-FW: Dual-emac: ping with 16K packet size fails
	PRSDK-5179,651897,am571x-idk,am572x-evm,am572x-idk,am574x-idk,,,,,,,,,,,,,,,,,,,,,,Control Drivers,,FATFS multi-partition fails to load file from windows formatted SD card with only Boot Record
	PRSDK-4725,600777,am335x-ice,am437x-idk,,,,,,,,,,,,,,,,,,,,,,,,PDK,,PTP: ICSS-EMAC LLD Master Mode config does not sync with slave
	PRSDK-4462,579103,am654x-evm,,,,,,,,,,,,,,,,,,,,,,,,,System,,IPC A53 ROV log won't show correctly because of XDCtools bug
	PRSDK-4965,623350,am335x-ice,,,,,,,,,,,,,,,,,,,,,,,,,Networking,,PRU-ICSS EMAC TX queuing performance issue
	PRSDK-5489,696280,am335x-evm,am335x-ice,am335x-sk,am437x-evm,am437x-hsevm,am437x-idk,am437x-sk,am570x-evm,am571x-idk,am572x-evm,am572x-idk,am574x-idk,am654x-evm,am654x-hsevm,am654x-idk,,,,,,,,,,,High-Speed Drivers,,USB bulk in wrong state when task preempted
	PRSDK-5533,704101,am335x-evm,am335x-ice,am335x-sk,,,,,,,,,,,,,,,,,,,,,,,High-Speed Drivers,,USB enumeration failure intermittently with unplug/plug test
	PRSDK-5248,666737,am654x-idk,,,,,,,,,,,,,,,,,,,,,,,,,Networking,PDK,packet loss with ICSSG emac driver
	PRSDK-5522,702613,,,,,,,,,,,,,,,,,,,,,,,,,,Chip Support,,Typo in hw_control_am437x.h file for PWM SS mask and shift 
	PRSDK-5021,637505,am654x-evm,am654x-idk,,,,,,,,,,,,,,,,,,,,,,,,Boot,,SBL Needs to set CTRLMMR_MCU_TIMER0_CLKSEL to 0x0 for timer to work in RTOS applications
	PRSDK-5461,692481,omapl138-lcdk,,,,,,,,,,,,,,,,,,,,,,,,,"Audio, Video, & Display",,McBSP driver does not account for TX data delay
	PRSDK-5559,707903,am572x-evm,am572x-idk,am574x-idk,,,,,,,,,,,,,,,,,,,,,,,Control Drivers,,QSPI clock doesn`t change when bitrate field in SPI driver Params is setup
	PRSDK-5029,639096,am437x-evm,am437x-idk,am571x-idk,am572x-evm,am572x-idk,am574x-idk,,,,,,,,,,,,,,,,,,,,Board Support,,Incorrect placement of dummy read cycles in SPI LLD test code 
	PRSDK-5234,664012,k2g-evm,k2g-ice,,,,,,,,,,,,,,,,,,,,,,,,Board Support,,Invalid  DDR_PHY_MR2 setting in K2G board library
	PRSDK-4972,624841,am572x-idk,k2g-evm,,,,,,,,,,,,,,,,,,,,,,,,Control Drivers,,Inconsistent TCC handling for UART Rx and Tx in DMA mode.
	PRSDK-5414,689174,am654x-evm,am654x-idk,,,,,,,,,,,,,,,,,,,,,,,,Board Support,,Board library VTT Enable for DDR config is missing RMW in GPIO setup
	PRSDK-4911,610532,am571x-idk,am572x-idk,,,,,,,,,,,,,,,,,,,,,,,,Networking,,Poll IEEE defined register for speed and duplexity instead of PHYSTS
	PRSDK-5126,506288,am335x-evm,,,,,,,,,,,,,,,,,,,,,,,,,OSAL,,Add error block in TaskP OSAL implementation 
	PRSDK-5288,674233,am437x-evm,am571x-idk,am572x-evm,am572x-idk,am574x-idk,,,,,,,,,,,,,,,,,,,,,Control Drivers,,Redundant OSAL_pendLock code in QSPI_transfer_v1 API that needs to be removed
	PRSDK-5207,655523,am335x-evm,,,,,,,,,,,,,,,,,,,,,,,,,"Audio, Video, & Display",,AM335x LCDC_RasterExample build failure
	PRSDK-5217,454231,am572x-idk,,,,,,,,,,,,,,,,,,,,,,,,,Chip Support,,Need add L1/L2 ECC functions into CSL
	PRSDK-5157,649023,am572x-evm,am572x-idk,,,,,,,,,,,,,,,,,,,,,,,,Control Drivers,,AM57x UART DMA test linked with wrong library
	
Known Issues 
==============

This section contains the list of known issues at the time of making the
release and any known workaround.

.. csv-table::
   :header: "Record ID","Board/s", "Component/s", "Summary","Workaround"
   :widths: 15, 20,20,30,70
	PRSDK-5635,716760,,,,,,,,,,,,,Optimized Libraries,,DSPLIB and MATHLIB performance degrades with C6000 8.3.x code gen tools,"To get better performance, can use the C6000 Codegen tools v7.4.2. Here are the details.

1. Download C6000 Code Generation Tools v7.4.2 http://software-dl.ti.com/codegen/non-esd/downloads/download.htm
2. Clone DSPLIB from https://git.ti.com/ep-processor-libraries/dsplib, and follow readme.txt in root folder to recompile DSPLIB.
3. Clone MATHLIB from https://git.ti.com/ep-processor-libraries/mathlib, and follow readme.txt in root folder to recompile MATHLIB.
"
	PRSDK-5645,717883,am654x-evm,,,,,,,,,,,,Emupack,,GEL file not working properly for AM654x-EVM platform causing DDR not to be configured properly,"Processor SDK RTOS v5.03 users will need to use Device support package 1.4.4. and TI emulation driver 8.0.903.2 
Customers are required to disable Automatic updates to prevent auto update to latest 1.4.5."
	PRSDK-4706,599378,am654x-evm,am654x-idk,,,,,,,,,,,Boot,,SBL: MCU0 Boot in R5 Split Mode not supported in SBL,"The SBL currently cannot reset the MCU1 subsystem to restart the cores in split mode. To workaround this, the MPU needs to reset the MCU1 sub-system. To configure the MCU1 susb-system in split mode, do the following. a) Create a multi-core image with a MCU1_0 image, a MCU1_1 image and an MPU image. 
b) The MPU1 image must contain code to reset the MCU sub-system. Refer the function sblTestResetMcu in sbl/example/k3MulticoreApp/sbl_amp_multicore.c for example code on how to reset the MCU subsystem 
 c) Before resetting the MCU, the MPU must wait for the SBL to boot MCU1_0"
	PRSDK-2892,387132,am571x-idk,am572x-evm,am572x-idk,,,,,,,,,,PDK,,Incorrect A15 MMU configurations in default config file,"Set MMU attribute to not executable for device memory
attrs0.noExecute = true;                   // Not executable"
	PRSDK-5612,712817,am437x-idk,,,,,,,,,,,,OSAL,PDK,Missing interrupt enable/disable option in OSAL HwiP_Params,
	PRSDK-5539,704361,c6748-lcdk,omapl138-lcdk,,,,,,,,,,,Control Drivers,,SPI loopback example not working in interrupt mode on OMAPL138,Polling mode can be used instead.
	PRSDK-5624,715182,am570x-evm,am571x-idk,am572x-evm,am572x-idk,am574x-idk,c6678-evm,k2h-evm,,,,,,Optimized Libraries,,FFTLIB documentation for AM57xx and K2H devices is missing,
	PRSDK-5485,696039,am570x-evm,am571x-idk,am572x-evm,am572x-idk,am574x-idk,,,,,,,,Networking,,Intermittent ping packet loss when running AM57x EMAC at 10 mbps,
	PRSDK-5473,695148,am570x-evm,am571x-idk,am572x-evm,am572x-idk,am574x-idk,,,,,,,,Networking,,NDK TCP packet re-transmission timeout when running ARM at a lower speed,
	PRSDK-5667,721358,am654x-evm,am654x-idk,,,,,,,,,,,Board Support,,AM65xx diagnostic test hang on R5 core,Use the diagnostic tests built for A53 core.
	PRSDK-5620,713797,am572x-idk,,,,,,,,,,,,PDK,,I2C_BasicExample_TestProject: I2C EEPROM test failure UT0 ,Same test passed on AM571x IDK and AM572x-EVM platforms but only failed on AM572x IDK platform.
	PRSDK-5272,670402,k2g-hsevm,,,,,,,,,,,,Networking,,EMAC_BasicExample: error #10099-D: program will not fit into available memory,"Move .stack and .cinit sections to L2SRAM to  MSMCSRAM in 
ti\drv\emac\test\EmacLoopbackTest\k2g\c66\bios\emac_example_k2g.cfg."
	PRSDK-5638,717143,am654x-evm,,,,,,,,,,,,Diagnostics,,AM65xx diag self test hangs during memory test on R5 core,The similar test can be run from A53 instead
	PRSDK-5655,718772,am654x-hsevm,,,,,,,,,,,,Boot,,Allow  windows users to selectively enable JTAG for AM65x HS,
	PRSDK-5448,690710,am654x-evm,am654x-idk,,,,,,,,,,,Boot,,SBL boot from MMCSD fails intermittently,
	PRSDK-5403,688693,am437x-idk,,,,,,,,,,,,Control Drivers,,iolink: channel 7 has ISDN read/write response error,Increase the cycle time will reduce the read/write response error
	PRSDK-5470,694344,am654x-hsevm,am654x-idk,,,,,,,,,,,Boot,,R5 cannot boot an app if entry point is in DDR,
	PRSDK-5626,715292,am654x-hsevm,,,,,,,,,,,,Boot,DMA,OSPI Read using UDMA fails on AM65x HS devices.,Non-DMA mode could be used for the read operation
	PRSDK-5080,644124,am654x-evm,am654x-idk,,,,,,,,,,,Board Support,,AM65xx diag failures on R5 core,Can run failing test from A53 cores
	PRSDK-3344,445171,am572x-idk,am574x-idk,,,,,,,,,,,Diagnostics,,"Diagnostics icssEmac_TEST idkAM57{2/4}x : LINK IS DOWN, pluggin loopback cable",ICSS-EMAC LLD TI-RTOS example can be used for similar test.
	PRSDK-3383,449034,am574x-idk,,,,,,,,,,,,Diagnostics,,Diagnostics: lcdTouchscreen_TEST hangs," Issue expected to be specific to TI EVM. For TI EVM, test need to be bypassed from the diagnostic menu."
	PRSDK-4667,596374,am572x-evm,,,,,,,,,,,,Demonstrations,Networking,Image Processing Demo lock up on AM572x GP EVM,Issue seen using 1Gig router on ETH0. Replace with 100Mbps
	PRSDK-335,107826,AM4X,k2g-evm,,,,,,,,,,,High-Speed Drivers,,USB host MSC fails to re-enumerate,Re-enumeration support for the case of device unplugged and plugged back currently fails for the example. Workaround is to avoid disconnecting drive while running example.
	PRSDK-5177,651854,am574x-idk,,,,,,,,,,,,Board Support,,Uniflash: Flash programmer hangs when qspi flash is programmed with DDRECC enabled MLO,"Issue will be seen while flashing with prebuilt MLO image. Workaround will be to rebuild MLO with DDRECC disabled and program the flash device. 
	| 
	 Commands to rebuild MLO with DDRECC disabled: 
	| 
	 cd $(PDK_INSTALL_PATH)\ti\boot\sbl 
	| 
	 gmake all BOARD=idkAM574x SOC=AM574x BOOTMODE=qspi "
	PRSDK-1975,280967,am572x-evm,,,,,,,,,,,,Diagnostics,,timer_DiagExample_evmAM572x_arm7.out doesn't work on ARM1 core,Example can run on ARM Core 0
	PRSDK-1682,253372,am571x-idk,am572x-idk,,,,,,,,,,,Diagnostics,,Board diagnostics LCD Touchscreen test does not work with new version of LCD TSC,For LCD/Display checkout example under VPS component could be used
	PRSDK-2336,310254,am335x-evm,am437x-evm,,,,,,,,,,,Power,,AM3 & AM4 PM Examples experience I2C bus lockup when communicating with PMIC,"The debug versions of the PM apps are still functional.  To build them:
From the top-level makefile in pdk.../packages folder run ""make BUILD_PROFILE=debug pm""
This will build the debug versions of the PM RTOS and measurement apps."
	PRSDK-2166,293452,am572x-idk,,,,,,,,,,,,High-Speed Drivers,,USB3.0 host problem with Sandisk Extreme USB3.0 stick,"Start the example without the USB plugged in. Once the example is up and waiting for USB stick, plug the USB stick in and it will enumerate properly."
	PRSDK-4214,561734,k2g-hsevm,,,,,,,,,,,,System,,create-sdcard script does not boot OOB,Default generated App image is not signed follow the steps mentioned in User Guide of the Processor SDK Secdev Build and Install Guide to sign the app
	PRSDK-4121,546574,am654x-evm,,,,,,,,,,,,Boot,,make all fails for Windows due to missing openSSL package,"|
  -  For Windows : Download and install `Strawberry Perl <http://strawberryperl.com/download/5.28.0.1/strawberry-perl-5.28.0.1-64bit.msi>`__. The Strawberry Perl installer automatically installs and sets up OpenSSL.
|
   -  For Linux : Execute the command ""sudo apt-get install openssl"" at the linux command prompt.
|
  -  Check if OpenSSL is installed by typing ""openssl version"" at the command prompt.
|"
	PRSDK-5267,669009,am570x-evm,am571x-idk,am572x-evm,am572x-idk,am574x-idk,k2e-evm,k2g-evm,k2g-hsevm,k2g-ice,k2h-evm,k2k-evm,k2l-evm,DMA,,AM57x A15 EDMA library doesn't support SMP mode,


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
| `RTOS-AM65X`_  | `AM65x`_   |`AM6526`_, `AM6527`_, `AM6528`_, `AM6546`_, `AM6548`_, DRA80xM                 |
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

.. _RTOS-AM65X: http://software-dl.ti.com/processor-sdk-rtos/esd/AM65X/latest/index_FDS.html
.. _AM65x: http://www.ti.com/am65x
.. _AM6526: http://www.ti.com/product/am6526
.. _AM6527: http://www.ti.com/product/am6527
.. _AM6528: http://www.ti.com/product/am6528
.. _AM6546: http://www.ti.com/product/am6546
.. _AM6548: http://www.ti.com/product/am6548

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
| PRUSS-eSPI f/w   |   X   |   X  |     |   |   |   |   |   |   |   |     |     |     |     |
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
| USB Device Bulk  |   X   |   X  |  X  | X |   |   |   | X |   |   |  X  |  X  |  X  |   X |
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
| USB Device Bulk  |       |   |   | X |     |     |   |   |   | X |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+


**DSP devices - OMAP-L13x, C674x**

+----------------+-------------------+-------------+----------------+
|    Feature     |   Platform/SOC    |OMAP-L137 EVM| OMAP-L138 EVM  |
+================+=========+=========+=============+=======+========+
|                |OMAP-L137|OMAP-L138| L137/6747 SK|LCDK138|LCDK6748|
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
|USB Device Bulk |    X    |    X    |      X      |   X   |   X    |
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
|USB             |  K2G    |    C66x |
+----------------+---------+---------+
|McBSP           |  K2G    |    A15  |
+----------------+---------+---------+
|McBSP           |OMAP-L13x|    ARM9 |
+----------------+---------+---------+
|All Drivers     | K2E/L/K |    A15  |
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
-  **Linux**: Ubuntu 14.04, 16.04 on 64-bit machine

.. note::
   The Windows installer is a 32-bit binary, but is compatibile with
   64-bit machine.

| 

Technical Support and Product Updates 
=======================================

For further information or to report any problems, contact:
-  `TI E2E Processor Support <https://e2e.ti.com/support/processors/>`__ for all supported platforms


| 

Archived 
==========
-  `Processor-SDK RTOS
   5.2.0 <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/05_02_00_10/rtos/Release_Specific.html#processor-sdk-rtos-release-notes>`__
-  `Processor-SDK RTOS
   5.1.0 <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/05_01_00_11/rtos/Release_Specific.html#processor-sdk-rtos-release-notes>`__
-  `Processor-SDK RTOS
   5.0.0 <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/05_00_00_15/rtos/Release_Specific.html#processor-sdk-rtos-release-notes>`__
-  `Processor-SDK RTOS
   5.0.0 AM65x EA Release <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/05_00_00_09/rtos/Release_Specific.html#processor-sdk-rtos-release-notes>`__
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
