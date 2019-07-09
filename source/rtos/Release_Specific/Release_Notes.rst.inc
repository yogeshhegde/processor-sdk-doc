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

Processor SDK v06.00.00
========================

.. warning::
   Big-endian support for C66x and C674x platforms shall be deprecated in Processor SDK RTOS from the Release 6.1 (3Q-2019)

Released July 2019

.. rubric::  What's New
   :name: whats-new

.. rubric::  New Features
   :name: new-features

- General
    - SMP mode support for PDK Drivers along with examples on A15/A53 cores
    - Support for parallel make (-j) for AM3/4/5/6 and OMAPL13x devices
- AM65x
    - `Serdes Diagnostic application <index_device_drv.html#serdes-diag>`_   
    - `PCIE QoS example <index_device_drv.html#id14>`_
    -  EMAC LLD: ICSS-G SWITCH enhancements below
		-  Support configuring the FW with base address PORT queues in MSMC/internal memory
		-  Support Polling Mode for RX packets
		-  Support processing the polled mode to retrieve timing events such as TX timestamp
		-  Support programming of VLAN table (4096 entries by 16 bits) into ICSS-G DataMemory
		-  Support Forwarding database entry management
		-  Support setting port state
		-  Support data plane meta data for directed packet on egress
		-  Support data plane meta data for requesting TX timestamp
		-  Support data plane meta data for receiving RX timestamp
		-  Support setting packet streaming interface(PSI) base flow for receive packets
    
- AM57xx
    - GPMC + FPGA SW example on CSL-FL

.. note::
   | C64P big endian targets are no longer supported since this release. 

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
|  DSPLIB     | 3.4.0.4    |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
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
|  MATHLIB    | 3.1.2.4    |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  MPM        | 3.0.4.0    |      |      |      |      |   X   |  X   |  X   |  X   |      |      |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  NDK        | 3.60.0     |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  NS         | 2.60.0     |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  OPENCL     | 1.1.18.0   |      |      |  X   |      |       |      |      |      |      |      |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  OPENMP     | 2.6.3.0    |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  PDK        |            |1.0.15|1.0.15|1.0.15| 1.0.5| 4.0.14|4.0.14|4.0.14|1.0.14|2.0.14|2.0.14|  1.0.9  |  1.0.9  |
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
|TI ARM CGT      | 18.12.1 |      |      |  M4  |  R5  |       |     |A15(SBL)|        |     | ARM9|   ARM9  |         |
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
|   CCS     | 9.0.1    |   X  |  X   |  X   |  X   |   X   |  X  |  X  |  X  |  X  |  X  |    X    |    X    |
+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+
|   EMU Pack|Sitara    |   X  |  X   |  X   |  X   |       |     |     |     |     |     |         |         |
|           |Device    |      |      |      |      |       |     |     |     |     |     |         |         |
|           |1.4.5     |      |      |      |      |       |     |     |     |     |     |         |         |
+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+
|    TI     |8.1.0.7   |   X  |  X   |  X   |  X   |   X   |  X  |  X  |  X  |  X  |  X  |     X   |     X   |
| Emulators |          |      |      |      |      |       |     |     |     |     |     |         |         |
+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+

If you need to install CCS, see the `CCS installation section <Overview.html#code-composer-studio>`__
in the *Getting Started Guide* for options to select for Processor-SDK.



Fixed Issues 
==============

.. csv-table::
   :header: "Record ID","Board/s", "Component/s", "Summary"
   :widths: 15, 20,20,30

	PRSDK-1760,am437x-idk,Board Support,Support for Sector erase function in QSPI library for AM437x in Starterware
	PRSDK-5691,"am654x-evm, am654x-hsevm, am654x-idk",Networking,am65xx: interface locks up on bi-directional tcp iperf test
	PRSDK-4121,am654x-evm,Boot,make all fails for Windows due to missing openSSL package
	PRSDK-5645,am654x-evm,Emupack,GEL file not working properly for AM654x-EVM platform causing DDR not to be configured properly
	PRSDK-5247,am654x-evm,PDK,RTOS builds are very slow on Windows machines
	PRSDK-4654,am654x-idk,System Integration,CCS fails to see symbols from *.out
	PRSDK-5986,,PDK,Autopadding of Frames <60 byte did not work correctly (Etherleak)
	PRSDK-5635,"am572x-evm, am572x-idk, am574x-idk, c6657-evm, c6678-evm, c6748-lcdk, k2e-evm, k2g-evm, k2g-hsevm, k2g-ice, k2h-evm, k2k-evm, k2l-evm, omapl137-evm, omapl138-lcdk",Optimized Libraries,DSPLIB and MATHLIB had kernel failures with C6000 8.3.x code gen tools
	PRSDK-5258,"am335x-evm, am335x-ice, am335x-sk, am437x-evm, am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk",Control Drivers,AM3/4/5 add UART test case to support more than 1 instances using EDMA
	PRSDK-5801,"am654x-evm, am654x-hsevm, am654x-idk",UNIFLASH,Uniflash tool - stability and OOB issues
	PRSDK-5665,am654x-idk,PDK,EMAC should configure context for Host Egress Queues
	PRSDK-5473,"am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk",Networking,NDK TCP packet re-transmission timeout when running ARM at a lower speed
	PRSDK-4321,"am654x-evm, am654x-idk",PRUSS,PRUICSS_pinMuxConfig function crashes for PRUICSS3 in AM654x
	PRSDK-5850,am654x-idk,Networking,NIMU_FtpCpsw_am65xx_idk_mcu1_0ExampleApp fails with SBL boot
	PRSDK-5539,"c6748-lcdk, omapl138-lcdk",Control Drivers,SPI loopback example not working in interrupt mode on OMAPL138
	PRSDK-5470,"am654x-evm, am654x-idk",Boot,R5 cannot boot an app if entry point is in DDR
	PRSDK-5272,k2g-hsevm,Networking,EMAC_BasicExample: error #10099-D: program will not fit into available memory
	PRSDK-5246,"am572x-idk, am574x-idk, am654x-evm",OSAL,OSAL cache APIs for AM57x incompatible with SMP aware Cache rtos module
	PRSDK-5684,"am335x-evm, am335x-ice, am335x-sk, am437x-evm, am437x-hsevm, am437x-idk, am437x-sk, am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk, amic110-ice",High-Speed Drivers,Incorrect buffer reset code in MMCSD V1 driver
	PRSDK-5874,am654x-idk,High-Speed Drivers,Second pcie lane not properly enabled on IDK
	PRSDK-5267,"am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk, k2e-evm, k2g-evm, k2g-hsevm, k2g-ice, k2h-evm, k2k-evm, k2l-evm",DMA,AM57x A15 EDMA library doesn't support SMP mode
	PRSDK-5812,"k2g-evm, k2g-hsevm, k2g-ice",Networking,NDK NIMU ping failure when packet receive buffer put into DDR on K2G C66x
	PRSDK-5332,"am335x-evm, am335x-ice, am335x-sk",Control Drivers,AM335x NAND ECC issue in Starterware library
	PRSDK-5692,"am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk",High-Speed Drivers,Incorrect AM57x MMCSD clock setting for SDR 104 mode
	PRSDK-5592,"am335x-evm, am335x-ice, am335x-sk",DMA,Missing parenthesis in AM335x Starterware EDMA marco

Known Issues 
==============

This section contains the list of known issues at the time of making the
release and any known workaround.

.. csv-table::
   :header: "Record ID","Board/s", "Component/s", "Summary","Workaround"
   :widths: 15, 20,20,30,70
   
	PRSDK-5080,"am654x-evm, am654x-idk",Board Support,"AM65xx diag failures on R5 core (USB, PCIE, MCASP and UART)",Can run failing test from A53 cores
	PRSDK-4214,k2g-hsevm,System,create-sdcard script does not boot OOB,Default generated App image is not signed follow the steps mentioned in User Guide of the Processor SDK Secdev Build and Install Guide to sign the app
	PRSDK-1975,am572x-evm,Diagnostics,timer_DiagExample_evmAM572x_arm7.out doesn't work on ARM1 core,Example can run on ARM Core 0
	PRSDK-3344,"am572x-idk, am574x-idk",Diagnostics,"Diagnostics icssEmac_TEST idkAM57{2/4}x : LINK IS DOWN, pluggin loopback cable",ICSS-EMAC LLD TI-RTOS example can be used for similar test.
	PRSDK-5178,"am571x-idk, am572x-idk, am574x-idk",Board Support,"Uniflash: Host tool fails to load Flash Programmer, when Flash device is programmed","Workaround for this issue is to insert SD card without any valid boot image( to prevent booting from SD card), and power on the board. SD boot has boot sequence priority over Flash device. This will hold the board booting out of flash device."
	PRSDK-5403,am437x-idk,Control Drivers,iolink: channel 7 has ISDN read/write response error,Increase the cycle time will reduce the read/write response error
	PRSDK-3383,am574x-idk,Diagnostics,Diagnostics: lcdTouchscreen_TEST hangs," Issue expected to be specific to TI EVM. For TI EVM, test need to be bypassed from the diagnostic menu."
	PRSDK-4667,am572x-evm,"Demonstrations,Networking",Image Processing Demo lock up on AM572x GP EVM,Issue seen using 1Gig router on ETH0. Replace with 100Mbps
	PRSDK-5626,am654x-hsevm,"Boot, DMA",OSPI Read using UDMA fails on AM65x HS devices.,Non-DMA mode could be used for the read operation
	PRSDK-335,"AM4X, k2g-evm",High-Speed Drivers,USB host MSC fails to re-enumerate,Re-enumeration support for the case of device unplugged and plugged back currently fails for the example. Workaround is to avoid disconnecting drive while running example.
	PRSDK-2892,"am571x-idk, am572x-evm, am572x-idk",PDK,Incorrect A15 MMU configurations in default config file,"Set MMU attribute to not executable for device memory ,attrs0.noExecute = true; // Not executable"
	PRSDK-2166,am572x-idk,High-Speed Drivers,USB3.0 host problem with Sandisk Extreme USB3.0 stick,"Start the example without the USB plugged in. Once the example is up and waiting for USB stick, plug the USB stick in and it will enumerate properly."
	PRSDK-4706,"am654x-evm, am654x-idk",Boot,SBL: MCU0 Boot in R5 Split Mode not supported in SBL,"The SBL currently cannot reset the MCU1 subsystem to restart the cores in split mode. To workaround this, the MPU needs to reset the MCU1 sub-system. To configure the MCU1 susb-system in split mode, do the following. a) Create a multi-core image with a MCU1_0 image, a MCU1_1 image and an MPU image. b) The MPU1 image must contain code to reset the MCU sub-system. Refer the function sblTestResetMcu in sbl/example/k3MulticoreApp/sbl_amp_multicore.c for example code on how to reset the MCU subsystem c) Before resetting the MCU, the MPU must wait for the SBL to boot MCU1_0"
	PRSDK-2336,"am335x-evm, am437x-evm",Power,AM3 & AM4 PM Examples experience I2C bus lockup when communicating with PMIC,"The debug versions of the PM apps are still functional. To build them: From the top-level makefile in pdk.../packages folder run ""make BUILD_PROFILE=debug pm"" This will build the debug versions of the PM RTOS and measurement apps"
	PRSDK-5638,am654x-evm,Diagnostics,AM65xx diag self test hangs during memory test on R5 core,The similar test can be run from A53 instead
	PRSDK-5642,am335x-evm,Board Support,USB_DevBulk_ExampleProject: Failed to load/run app,Use JTAG to load and run the example
	PRSDK-5667,"am654x-evm, am654x-idk",Board Support,AM65xx diagnostic tests hang on R5 core,Use the diagnostic tests built for A53 core.
	PRSDK-6056,"am654x-evm, am654x-hsevm, am654x-idk, am75x-evm, am64x-evm",Board Support,make clean board fails when run from <pdk>packages,"While doing a clean build of board from the top level PDK make file, use the following sequence. 1) make clean   2) make udma sciclient fatfs 3) make board"
	PRSDK-4548,am335x-ice,PRUSS-Firmware,PRU-ICSS EMAC + TTS : Corrupted Rx packet at host from Firmware,n/a
	PRSDK-5851,"am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk",Optimized Libraries,Fail to run RTOS examples on non-primary A15 core
	PRSDK-5770,"am335x-ice, am437x-idk, beagleboneblack",PRUSS-Firmware,PUT_IORD_SHORT not working after issuing PUT_IOWR_SHORT
	PRSDK-5789,"am335x-evm, am335x-ice, am335x-sk, am437x-evm, am437x-hsevm, am437x-idk, am437x-sk, am570x-evm, am571x-idk,am572x-evm, am572x-idk, am574x-idk",System Integration,Top level make windows fails intermittently with: fork: can't reserve memory for stack
	PRSDK-5074,am654x-evm,PDK,McASP driver hangs with small buffer size
	PRSDK-5307,c6748-lcdk,Control Drivers,SPI_transferCancel function not implemented in SPI v0 driver
	PRSDK-4886,"am654x-evm, am654x-hsevm, am654x-idk",High-Speed Drivers,UDMA-P Real-time Remote Peer Registers not Functional Across UDMA-P Domains
	PRSDK-5947,am654x-idk,PDK,EMAC fails to remove CRC from Locally received frame in TSN Switch
	PRSDK-5612,am437x-idk,OSAL,Missing interrupt enable/disable option in OSAL HwiP_Params
	PRSDK-5799,"c6748-lcdk, omapl138-lcdk",High-Speed Drivers,Cannot set RMIISPEED bit in EMAC HwAttrs structure
	PRSDK-5683,am335x-ice,Boot,OOB MLO from PSDK doesn't work with PRU-ICSS Ethernet/IP
	PRSDK-5727,k2g-hsevm,Boot,K2G HS SBL fails out of the box in SBL_initSK
	PRSDK-5981,"c6748-lcdk, omapl137-evm, omapl138-lcdk",High-Speed Drivers,MMCSD DMA test projects hangs on OMAPL138/137
	PRSDK-6027,c6678-evm,Demonstrations,Image processing demo doesn't work on C6678
	PRSDK-5611,"am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk",Networking,NDK HTTP server memory leak
	PRSDK-5303,"am335x-evm, am335x-ice, am335x-sk, amic110-ice",Networking,APP image for NIMU CCLINK examples on AM335x/AMIC110 is >SPI flash size
	PRSDK-5992,omapl138-lcdk,Chip Support,CSLR header file incorrect for OMAPL138
	PRSDK-5916,"am335x-evm, am335x-ice, am335x-sk, am437x-evm, am437x-hsevm, am437x-idk, am437x-sk, am570x-evm,am571x-idk,am572x-evm,am572x-idk,am574x-idk",High-Speed Drivers,Sitara EMMC driver does not support data bus width other than 8 bit
	PRSDK-5730,"am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk",High-Speed Drivers,Need to implementing AM57x errata i926 in PCIE RX PHY setting sample code
	PRSDK-5966,"am654x-evm, am654x-hsevm, am654x-idk",Boot,Optimized PLL settings for Maxwell
	PRSDK-5766,"c6657-evm, c6678-evm",Boot,PRSDK integration issue: IBL external GIT and release source don`t match
	PRSDK-6040,"am654x-evm, am654x-idk",Boot,Uniflash 5.0.0 hangs at 99% while flashing sbl_baremetal_boot_{xip/smp} appimage
	PRSDK-6052,"am654x-evm, am654x-hsevm","Control Drivers, DMA,High-Speed Drivers,Networking",AM654x: many of the unit-tests are failing when run using SBL.
	PRSDK-5811,k2k-evm,System Integration,K2K: top level parallel make fails due to package interdependency
	PRSDK-3862,am437x-hsevm,High-Speed Drivers,MMCSD_EMMC_{DMA}_Testproject ARM LE: hangs on AM437x-HSEVM
	PRSDK-5397,am574x-idk,Unknown,"CSL ECC EMIF test hangs at ""OCMC FULL ECC Mode"" on ARM"
	PRSDK-5879,am654x-evm,Board Support,Board: Board library needs to cover entire DDR region connected to EMIF1
	PRSDK-5751,am654x-idk,High-Speed Drivers,AM65xx IDK PCIe diagnostic test failure
	PRSDK-5919,"am572x-evm, k2g-evm",System Integration,"Make cplusplus: error: identifier ""EMAC_DRV_ERR_E"" is undefined"
	PRSDK-5887,am572x-evm,Boot,Application hangs on non zero core using Uart apploader
	PRSDK-5989,am654x-idk,Control Drivers,USB Host MSC test hangs in SMP mode on AM65xx IDK board
	PRSDK-5987,am572x-evm,Control Drivers,UART Rx/TX trigger level test fails in SMP mode for AM572x EVM (DMA)
	PRSDK-5988,am654x-idk,Control Drivers,OSPI SMP unit test fails in 133MHz speed for AM65xx IDK
	PRSDK-6059,"am654x-evm, am654x-idk",PDK,reserved area for DMSC in top level linker command file in PDK is incorrect
	PRSDK-6054,,High-Speed Drivers,Bare-metal USB application performance degradation on Am65xx R5 core as compared to SYSBIOS benchmark
	PRSDK-5920,"c6748-lcdk, k2g-evm, k2g-ice, k2h-evm",OSAL,OSAL DSP test hangs after 'HWI tests have passed'
	PRSDK-6043,,Unknown,Missing Resource Explorer Classic option from the CCSv9.0
	PRSDK-5933,amic110-ice,Networking,NIMU_ICSS iceAMIC110: ping failed at J7 port
	PRSDK-5942,k2g-hsevm,Control Drivers,UART DMA TX/RX FIFO trigger level test failure (UT12) failed
	PRSDK-3553,omapl137-evm,Unknown,EMAC Loopback: Should work with loopback cable connected on all ports
	PRSDK-3371,omapl137-evm,Boot,Slave boot is failing on evmOMAPL137
	PRSDK-3564,am437x-hsevm,System,"AM437x-HSEVM: I2C unit tests get ""Some tests have failed."" when run"
	PRSDK-3565,am437x-hsevm,Security,AM437x-HSEVM: GPMC unit-tests fail
	PRSDK-5064,"am654x-evm, am654x-idk","Audio, Video, & Display",RTOS: Maxwell MCASP Device Loopback Regression test 7 and 9 fail
	PRSDK-5388,"k2e-evm, k2h-evm",Unknown,mmap_TestProject DSP LE/BE: error #3188: Object size is greater than maximum supported size
	PRSDK-5493,am572x-idk,Demonstrations,Gravit Graphics demo: Error: File io init failed!!
	PRSDK-5535,"am654x-evm, am654x-idk",KeyStone Drivers,SA UnitTest MPU failure: Did not find SA reply in rx ring 305 from SYSFW
	PRSDK-5662,"am654x-evm, am654x-idk",Control Drivers,Baremetal & OSPI RTOS flash unit tests hang when running INDAC mode on R5
	PRSDK-5755,"am654x-evm, am654x-hsevm, am654x-idk",Networking,ICSS-G-FW: Firmware should not configure ICSSG clock mux
	PRSDK-2299,k2g-evm,Security,Ram_secure_kernel needs to be able to build using latest code_gen_tool
	PRSDK-4331,"am654x-evm, am654x-idk",Diagnostics,Incorrect Counter Values in DCC Operation
	PRSDK-5878,am654x-evm,Chip Support,CSL Timer : API inconsistencies noticed and potential stuck loop identified
	PRSDK-2989,omapl137-evm,High-Speed Drivers,Enable 1024 byte block size support for MMCSD LLD
	PRSDK-5253,am654x-evm,OSAL,[osal] R5 OsalArch_HwiPCreate calls system enable
	PRSDK-3541,am335x-evm,High-Speed Drivers,"USB MSC device mode doesn't handle ""safely remove"" command well."
	PRSDK-4583,am437x-idk,PRUSS-Firmware,PRUSS-I2C-FW: Does not support 1Mhz mode. Incorrect STOP condition generated for HS mode
	PRSDK-5340,am654x-idk,"Example, Networking",mis-matched number of channels and allocated memory arrays with EmacLoopbackTest
	PRSDK-5229,am654x-idk,Board Support,PCIe diagnostic test should validate both the ports on PCIe 2-lane card
	PRSDK-4493,"am654x-evm, am654x-idk",PDK,Missing interrupt number for peripherals (R5F/MCU in AM65x)
	PRSDK-769,"AM335X, AM437x, AM572x, C66X, K2",Demonstrations,Posix-SMP Demo DMIPS are wrong
	PRSDK-5654,"am654x-evm, am654x-hsevm, am654x-idk",High-Speed Drivers,"UART_config mismatch when removing ""--diag_supress=2300"" linker flag"
	PRSDK-4927,"am654x-evm, am654x-idk",SCIClient,sciclient: APIs seems to always use self host id to be core 0
	PRSDK-4744,"am654x-evm, am654x-idk",Networking,nimu_free_pkt() wrongly frees p_pkt_desc
	PRSDK-5259,"am654x-evm, am654x-idk",Board Support,Set TISCI_DEV_MCU_FSS0_BUS_OSPI0_RCLK_CLK and TISCI_DEV_MCU_FSS0_BUS_OSPI1_RCLK_CLK to 160Mhz
	PRSDK-4843,am654x-idk,Board Support,Pinmux support for AM654x IDK ICSS MII pin is missing
	PRSDK-3876,am572x-evm,Chip Support,CM_EMU_CLKSTCTRL=0x2 needed for reliable low power exit if EMU[1:0] pins are used as GPIOs
	PRSDK-4680,"am654x-evm, omapl137-evm",PDK,Processor SDK RTOS Post Installer script fails in case cygwin/mingw is overriding Windows default find utility
	PRSDK-2515,am654x-evm,Chip Support,CSL-RL for PSC not in sync with latest spec
	PRSDK-5022,am654x-idk,Networking,am65xx: Running emac unit test on R5 core from ddrless SBL at times does not complete execution
	PRSDK-5903,k2g-hsevm,Networking,EMAC_BasicExample DSP LE: Exception at 0xc00fde4
	PRSDK-5701,am75x-evm,PDK,NIMU: NIMU should not call Udma_init
	PRSDK-5793,beagleboneblack,"PDK, PRUSS-Firmware",pdkAppImageCreate script creates large binaries for PRU FW projects
	PRSDK-5847,am654x-idk,PDK,am64xx: switch: Unable to send packets after emac_close followed by emac_open.
	PRSDK-5690,"am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk",High-Speed Drivers,Improper test of MMCSD driver with power switch from 3.3V to 1.8V
	PRSDK-5814,"am654x-evm, am654x-idk",PDK,"Control drivers such as uart, i2c, gpio etc driver device dependent and independent libs issue"
	PRSDK-5852,,System Integration,vps-lld: recipe exists in meta-ti and internal layer
	PRSDK-5871,am570x-evm,PDK,"EMAC_BasicExample MPU LE test fails at ""Clock synthesizer: Write: Failed"""
	PRSDK-5936,am437x-idk,PDK,IO-Link master example does not work with Balluff inductive coupler
	PRSDK-5856,"am654x-evm, am654x-hsevm, am654x-idk, am75x-evm",Chip Support,CSL: Arasan source files for mmcsd support - license needs to be fixed
	PRSDK-5732,"am654x-evm, am654x-hsevm, am654x-idk","Board Support, Boot",SBL need to properly set CBIASSEL to use Bandgap references for LDOs
	PRSDK-5952,"am654x-evm, am654x-hsevm, am654x-idk",Networking,am65xx: icssg: fw: shutdown command doesn't work
	PRSDK-5466,am654x-evm,Boot,AM65xx/OSPI/XIP: subsequent driver open() fails.
	PRSDK-5544,"am654x-evm, am654x-idk",Networking,Maxwell EMAC LLD example doesn't work at 100Mbps
	PRSDK-5669,"am654x-evm, am654x-idk",Diagnostics,Maxwell DIAG: OSPI stress test hangs
	PRSDK-3412,"omapl137-evm, omapl138-evm",High-Speed Drivers,USB audio class example noise issue on OMAPL13x
	PRSDK-5938,"am437x-idk, am571x-idk, am572x-idk",PDK,MCSPI/I2C Master Slave Example: SPI TX/RX FIFO trigger level test failure (UT1)
	PRSDK-5448,"am654x-evm, am654x-idk",Boot,SBL boot from MMCSD fails intermittently
	PRSDK-5655,am654x-hsevm,Boot,Allow windows users to selectively enable JTAG for AM65x HS
	PRSDK-5624,"am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk, c6678-evm, k2h-evm","Collateral, Optimized Libraries",FFTLIB documentation for AM57xx and K2H devices is missing
	PRSDK-5915,"k2e-evm, k2g-evm, k2g-hsevm, k2g-ice, k2h-evm, k2k-evm, k2l-evm",Chip Support,Incorrect Keystone II Serdes Rx valid signal for PCIE interface using CSL
	PRSDK-5959,"k2g-evm, k2g-hsevm, k2g-ice",Diagnostics,Incorrect GPMC register access on K2G NAND diagnostics
	PRSDK-4043,"omapl137-evm, omapl138-lcdk",Unknown,OMAPL13x: USB Baremetal project binaries not built via top level make
	PRSDK-3727,"c6748-evm, c6748-lcdk",PDK,C6748 is missing from SOC description list in pdkProjectCreate
	PRSDK-5000,am654x-evm,Chip Support,Incorrect DMSC IRAM size in CSL-RL
	PRSDK-4847,"am335x-ice, am437x-idk, am571x-idk, am572x-idk, am574x-idk, k2g-ice",PDK,ICSS-EMAC LLD: Default Config sizes entire OCMC
	PRSDK-5186,"am335x-evm, am335x-ice, am335x-sk, am437x-evm, am437x-hsevm, am437x-idk, am437x-sk, am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk",Board Support,Libgcc code placement for IO delay configuration
	PRSDK-3864,"am571x-idk, am572x-idk, am574x-idk",High-Speed Drivers,Missing USB disconnect event on USB device mode on AM5xx
	PRSDK-6158,"am335x-evm,	am335x-ice,	am335x-sk,am437x-evm,am437x-hsevm,am437x-idk,amic110-ice,beagleboneblack",Control Drivers,"UART_BasicExample_TestProject: task creation fails","Use the default task stack size. In the test/src/main_uart_test.c, comment out the lines which increases the task stack size. i.e comment out the following line in the test code - taskParams.stackSize = 0x20000; This will restore the task stack size to default and workarounds the issue"
	PRSDK-6152,"am654x-evm,	am654x-idk",Control Drivers,"UART BasicExample_DMA: ti.sysbios.heaps.HeapMem: line 221: out of memory: handle=0x7003190c, size=8192","Increase the sysbios heapSize to 64K in the ti/drv/uart/test/am65xx/uartUnitTest_r5.cfg. Please refer to the fix which is available in http://git.ti.com/keystone-rtos/uart-lld/commit/8976c817fee427acc72447028ae47c3c7c3dca93"
	PRSDK-6109,"am654x-evm,	am654x-hsevm,am654x-idk",Boot,"ROM load time of SBL increased on GP devices","Use ROM degenrate key on GP devices for signing the SBL. To do this, overwrite ti/build/k3_dev_mpk.pem with ti/build/rom_degenerateKey.pem before building the SBL"

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
   5.3.0 <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/05_03_00_07/rtos/Release_Specific.html#processor-sdk-rtos-release-notes>`__
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
