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

Processor SDK v06.01.00
========================

Released Oct 2019

.. rubric::  What's New
   :name: whats-new

.. rubric::  New Features
   :name: new-features

- AM65x
    - `IPC Low level driver support <index_device_drv.html#ipclld>`_
    
- AM335x
    - `Sercos-III Softmaster Demo on AM335x ICEv2 <index_examples_demos.html#sercos-iii-softmaster>`_

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
|  IPC        | 3.50.4     |      |      |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |         |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  LIBARCH    | 1.0.0.0    |      |      |      |      |   X   |      |      |      |      |  X   |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  LINALG     | 1.2.0.0    |      |      |      |      |   X   |      |      |      |      |  X   |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  MATHLIB    | 3.1.2.4    |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  MPM        | 3.0.4.0    |      |      |      |      |   X   |  X   |  X   |  X   |      |      |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  NDK        | 3.61.1     |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  NS         | 2.60.1     |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  OPENCL     | 1.1.19.2   |      |      |  X   |      |       |      |      |      |      |      |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  OPENMP     | 2.6.3.0    |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  PDK        |            |1.0.16|1.0.16|1.0.16| 1.0.6| 4.0.15|4.0.15|4.0.15|1.0.15|2.0.15|2.0.15|  1.0.10 |  1.0.10 |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  SYS/BIOS   | 6.76.2     |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  UIA        | 2.30.1.2   |      |      |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  XDAIS      | 7.24.0.4   |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  XDCTOOLS   | 3.55.02    |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
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
|TI C6000 CGT    | 8.3.2   |      |      | C66x |      | C66x  |C66x | C66x   |  C66x  |C66x |C66x |   C674x |   C674x |
+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+
|TI PRU CGT      | 2.3.2   | PRU  | PRU  | PRU  |  PRU |       |     |  PRU   |        |     |     |         |         |
+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+

The SDK uses Code Composer Studio (CCS) as the integrated development
environment (IDE) for all devices and EVMs:

+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+
| Component | Version  |AM335x|AM437x|AM57x |AM65x |K2H/K2K| K2E | K2L | K2G |C665x|C667x|OMAP-L137|OMAP-L138|
+===========+==========+======+======+======+======+=======+=====+=====+=====+=====+=====+=========+=========+
|   CCS     | 9.1.0    |   X  |  X   |  X   |  X   |   X   |  X  |  X  |  X  |  X  |  X  |    X    |    X    |
+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+
|   EMU Pack|Sitara    |   X  |  X   |  X   |  X   |       |     |     |     |     |     |         |         |
|           |Device    |      |      |      |      |       |     |     |     |     |     |         |         |
|           |1.4.5     |      |      |      |      |       |     |     |     |     |     |         |         |
+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+
|    TI     |8.3.0.0   |   X  |  X   |  X   |  X   |   X   |  X  |  X  |  X  |  X  |  X  |     X   |     X   |
| Emulators |          |      |      |      |      |       |     |     |     |     |     |         |         |
+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+

If you need to install CCS, see the `CCS installation section <Overview.html#code-composer-studio>`__
in the *Getting Started Guide* for options to select for Processor-SDK.



Fixed Issues 
==============

.. csv-table::
   :header: "Record ID","Board/s", "Component/s", "Summary"
   :widths: 15, 20,20,30

	PRSDK-5916,"*Multiple platforms",High-Speed Drivers,Sitara EMMC driver does not support data bus width other than 8 bit
	PRSDK-4764,"*Multiple platforms",PDK,icss_dual emac firmware: PTP frames are all put under queue 0 for both ports
	PRSDK-5789,"*Multiple platforms",System Integration,Top level make windows fails intermittently with: fork: can't reserve memory for stack
	PRSDK-5624,"*Multiple platforms","Collateral, Optimized Libraries",FFTLIB documentation for AM57xx and K2H devices is missing
	PRSDK-5303,"am335x-evm, am335x-ice, am335x-sk, amic110-ice",Networking,APP image for NIMU CCLINK examples on AM335x/AMIC110 exceeds the SPI flash size
	PRSDK-5683,am335x-ice,Boot,OOB MLO from PSDK doesn't work with PRU-ICSS Ethernet/IP
	PRSDK-5770,"am335x-ice, am437x-idk, beagleboneblack",PRUSS-Firmware,PUT_IORD_SHORT not working after issuing PUT_IOWR_SHORT
	PRSDK-5403,am437x-idk,Control Drivers,iolink: channel 7 has ISDN read/write response error
	PRSDK-5612,am437x-idk,OSAL,Missing interrupt enable/disable option in OSAL HwiP_Params
	PRSDK-5690,"am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk",High-Speed Drivers,Improper test of MMCSD driver with power switch from 3.3V to 1.8V
	PRSDK-5730,"am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk",High-Speed Drivers,Need to implement AM57x errata i926 in PCIE RX PHY setting sample code
	PRSDK-6055,"am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk",High-Speed Drivers,FATFS example crash when insert/remove MMCSD cards
	PRSDK-5611,"am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk",Networking,NDK HTTP server memory leak
	PRSDK-5851,"am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk",Optimized Libraries,Fail to run RTOS examples on non-primary A15 core
	PRSDK-4850,"am571x-idk, am572x-evm, am572x-idk","Audio, Video, & Display","RTOS: VPS test fails using MMCSD/UARTApploader on am571x-idk, am572x-evm and am572x-idk platforms"
	PRSDK-5466,am654x-evm,Boot,AM65xx/OSPI/XIP: OSPI driver re-open() fails on XIP mode
	PRSDK-5000,am654x-evm,Chip Support,Incorrect DMSC IRAM size in CSL-RL
	PRSDK-5638,am654x-evm,Diagnostics,AM65xx diag self test hangs during memory test on R5 core
	PRSDK-5253,am654x-evm,OSAL,[osal] R5 OsalArch_HwiPCreate calls system enable() unconditionally
	PRSDK-6056,"am654x-evm, am654x-hsevm, am654x-idk",Board Support,make clean board fails when run from <pdk>packages
	PRSDK-5952,"am654x-evm, am654x-hsevm, am654x-idk",Networking,am65xx: icssg: fw: shutdown command doesn't work
	PRSDK-6259,"am654x-evm, am654x-idk",Board Support,AM65xx Board lib build failure with PMT output files
	PRSDK-4706,"am654x-evm, am654x-idk",Boot,SBL: MCU0 Boot in R5 Split Mode not supported in SBL
	PRSDK-6040,"am654x-evm, am654x-idk",Boot,Uniflash 5.0.0 hangs at 99% while flashing sbl_baremetal_boot_{xip/smp} appimage
	PRSDK-5669,"am654x-evm, am654x-idk",Diagnostics,Maxwell DIAG: OSPI stress test hangs
	PRSDK-5535,"am654x-evm, am654x-idk",KeyStone Drivers,SA UnitTest MPU failure: Did not find SA reply in rx ring 305 from SYSFW
	PRSDK-4744,"am654x-evm, am654x-idk",Networking,nimu_free_pkt() wrongly frees p_pkt_desc
	PRSDK-6059,"am654x-evm, am654x-idk",PDK,reserved area for DMSC in top level linker command file in PDK is incorrect
	PRSDK-4739,"am654x-evm, am654x-idk",SCIClient,ccsLoadDmsc fails if 2 or more boards configured
	PRSDK-4927,"am654x-evm, am654x-idk",SCIClient,sciclient: APIs seems to always use self host id to be core 0
	PRSDK-6047,am654x-idk,Board Support,CPSWHSDIV_CLKOUT2 should be initialized to 250MHz
	PRSDK-6445,am654x-idk,Example,"Invalid ""project_detected"" variable in pdkProjectCreate.bat"
	PRSDK-5340,am654x-idk,"Example, Networking",mis-matched number of channels and allocated memory arrays with EmacLoopbackTest
	PRSDK-5947,am654x-idk,PDK,EMAC fails to remove CRC from Locally received frame in TSN Switch
	PRSDK-6254,am654x-idk,PDK,emac_poll function takes ~1ms time during link change
	PRSDK-5793,beagleboneblack,"PDK, PRUSS-Firmware",pdkAppImageCreate script creates large binaries for PRU FW projects
	PRSDK-5675,c6657-evm,Boot,To bring back bootloader utilities into Processor SDK RTOS
	PRSDK-5766,"c6657-evm, c6678-evm",Boot,IBL external GIT and release source don`t match
	PRSDK-6027,c6678-evm,Demonstrations,Image processing demo doesn't work on C6678
	PRSDK-6301,c6678-evm,Networking,NDK NIMU driver memory double free error
	PRSDK-5307,c6748-lcdk,Control Drivers,SPI_transferCancel function not implemented in SPI v0 driver
	PRSDK-5920,"c6748-lcdk, k2g-evm, k2g-ice, k2h-evm, omapl137-evm, omapl138-lcdk",OSAL,OSAL DSP test hangs after 'HWI tests have passed'
	PRSDK-5981,"c6748-lcdk, omapl137-evm, omapl138-lcdk",High-Speed Drivers,MMCSD DMA test projects hangs on OMAPL138/137
	PRSDK-5799,"c6748-lcdk, omapl138-lcdk",High-Speed Drivers,Setting RMIISPEED bit in EMAC HwAttrs structure has no effect
	PRSDK-5701,j721e-evm,PDK,NIMU: NIMU should not call Udma_init
	PRSDK-5915,"k2e-evm, k2g-evm, k2g-hsevm, k2g-ice, k2h-evm, k2k-evm, k2l-evm",Chip Support,Incorrect Keystone II Serdes Rx valid signal for PCIE interface using CSL
	PRSDK-5388,"k2e-evm, k2h-evm, k2k-evm",PDK,mmap_TestProject DSP LE/BE: error #3188: Object size is greater than maximum supported size
	PRSDK-5959,"k2g-evm, k2g-hsevm, k2g-ice",Diagnostics,Incorrect GPMC register access on K2G NAND diagnostics
	PRSDK-5727,k2g-hsevm,Boot,K2G HS SBL fails out of the box in SBL_initSK
	PRSDK-4214,k2g-hsevm,System,create-sdcard script does not boot OOB
	PRSDK-5811,k2k-evm,System Integration,K2K: top level parallel make fails due to package interdependency
	PRSDK-5992,omapl138-lcdk,Chip Support,Incorrect definitions in CSLR header for OMAPL138
	PRSDK-6204,omapl138-lcdk,Chip Support,Corrections needed to EPWM CSL header for OMAP-L138

Known Issues 
==============

This section contains the list of known issues at the time of making the
release and any known workaround.

.. csv-table::
   :header: "Record ID","Board/s","Component/s","Summary","Workaround"
   :widths: 15,100,20,30,70

	PRSDK-5186,"*Multiple platforms",Board Support,PDK Driver examples wrongly puts libgcc in to DDR invalidating IO delay configuration,"The user application could explicitly place the libgcc.a in to OCMC RAM along with BOARD_IO_DELAY_DATA/CODE sections so that there is no DDR access while calling IO Delay functions "
	PRSDK-6043,"*Multiple platforms",CCS,TI-RTOS Kernel Example does not work with Resource Explorer in CCS 9.x,
	PRSDK-769,"*Multiple platforms",Demonstrations,Posix-SMP Demo DMIPS are wrong,
	PRSDK-5821,"*Multiple platforms",High-Speed Drivers,Failure to support file system with unicode string,ASCII string file names should be used instead of Unicode strings
	PRSDK-6184,"*Multiple platforms",System Integration,BIOS 6.75 newlib-nano and header incompatibility with GCCv7.3.1 toolchain in SDK,
	PRSDK-5642,am335x-evm,Board Support,USB_DevBulk_ExampleProject: Failed to load/run app,Use JTAG to load and run the example
	PRSDK-3541,am335x-evm,High-Speed Drivers,"USB MSC device mode doesn't handle ""safely remove"" command well.",
	PRSDK-6639,am335x-evm,OSAL,AM335x Osal baremetal test fails when loaded through SBL,Please load/run the test via JTAG instead of SBL
	PRSDK-6653,"am335x-evm, am437x-evm",Diagnostics,"Diagnostics accelerometer, adc, temperature and ambient_light_sensor hangs on evmAM335x/AM437x",
	PRSDK-2336,"am335x-evm, am437x-evm",Power,AM3 & AM4 PM Examples experience I2C bus lockup when communicating with PMIC,"The debug versions of the PM apps are still functional. To build them: From the top-level makefile in pdk.../packages folder run ""make BUILD_PROFILE=debug pm"" This will build the debug versions of the PM RTOS and measurement apps."
	PRSDK-5164,"am335x-evm, omapl137-evm, omapl138-lcdk",High-Speed Drivers,AM3/OMAP USB driver sends NYET response to BULK OUT transfer request causing unnecessary USB traffic,
	PRSDK-4548,am335x-ice,PRUSS-Firmware,PRU-ICSS EMAC + TTS : Corrupted Rx packet at host from Firmware,"Rebuild the firmware using the following changes to prioritize Rx packets over Tx packets during non realtime packet reception. Please make the following changes to firmware/icss_dualemac/src/emac_tts.h scheduler. In the M_TTS_XMT_SCHEDULER macro, add the following instruction after the label NOT_Queue1?: at line 149.      'QBBS TASK_EXECUTION_FINISHED, R23, Rcv_active'     .With the above changes, clean and rebuild the icss-emac firmware using the steps mentioned in http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/index_pru_icss_fw.html#firmware-build-instruction.Please note that there will be significant reduction in throughput due to the above change."
	PRSDK-6652,"am335x-ice, am437x-evm",Diagnostics,"Diagnostics LED test hangs at ""Jumping to user application""",
	PRSDK-7120,"am335x-ice, am571x-idk",PDK,SPI master slave test fails in non-dma callback mode,
	PRSDK-3565,am437x-hsevm,Security,AM437x-HSEVM: GPMC unit-tests fail,
	PRSDK-3564,am437x-hsevm,System,"I2C unit tests on AM437x-HSEVM fail with the message ""Some tests have failed.""",
	PRSDK-6161,am437x-idk,Networking,ICSS_EMAC_BasicExample fails on AM437x IDK with errors in received acyclic pkt content,
	PRSDK-5936,am437x-idk,PDK,IO-Link master example does not work with Balluff inductive coupler,
	PRSDK-4583,am437x-idk,PRUSS-Firmware,PRUSS-I2C-FW: Does not support 1Mhz mode. Incorrect STOP condition generated for HS mode,
	PRSDK-7085,"am437x-idk, am437x-sk",Diagnostics,Diagnostics: 'mem test' hangs on AM4 boards,
	PRSDK-5938,"am437x-idk, am571x-idk, am572x-idk",PDK,MCSPI/I2C Master Slave Example: SPI TX/RX FIFO trigger level test failure (UT1),
	PRSDK-335,"am437x-idk, k2g-evm",High-Speed Drivers,USB host MSC fails to re-enumerate,Re-enumeration support for the case of device unplugged and plugged back currently fails for the example. Workaround is to avoid disconnecting drive while running example.
	PRSDK-5871,am570x-evm,PDK,"EMAC_BasicExample MPU LE test fails at ""Clock synthesizer: Write: Failed""",
	PRSDK-6766,"am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk",High-Speed Drivers,USB driver TRB data buffer placement caused the bulk test failure,
	PRSDK-2892,"am571x-idk, am572x-evm, am572x-idk",PDK,Incorrect A15 MMU configurations in default config file,"Set MMU attribute to not executable for device memory attrs0.noExecute = true; // Not executable"
	PRSDK-5178,"am571x-idk, am572x-idk, am574x-idk",Board Support,"Uniflash: Host tool fails to load Flash Programmer, when Flash device is programmed","In case of AM5 platform, if flash device is programmed with a valid boot image, the board boots from flash as soon as powered on. After this, attempting to connect the board over JTAG will fail. | Workaround for this issue is to insert SD card without any valid boot image( to prevent booting from SD card), and power on the board. SD boot has boot sequence priority over Flash device. This will hold the board booting out of flash device."
	PRSDK-3864,"am571x-idk, am572x-idk, am574x-idk",High-Speed Drivers,Missing USB disconnect event on USB device mode on AM5xx,
	PRSDK-5087,"am571x-idk, am572x-idk, am574x-idk",Networking,ICSS_EMAC_BasicExample fails on AM57xx-IDK with Packet cyclic timestamp error,
	PRSDK-3876,am572x-evm,Chip Support,CM_EMU_CLKSTCTRL=0x2 needed for reliable low power exit if EMU[1:0] pins are used as GPIOs,
	PRSDK-5987,am572x-evm,Control Drivers,UART Rx/TX trigger level test fails in SMP mode for AM572x EVM (DMA),
	PRSDK-4667,am572x-evm,"Demonstrations, Networking",Image Processing Demo lock up on AM572x GP EVM,Issue seen using 1Gig router on ETH0. Replace with 100Mbps
	PRSDK-1975,am572x-evm,Diagnostics,timer_DiagExample_evmAM572x_arm7.out doesn't work on ARM1 core,Example can run on ARM Core 0
	PRSDK-6958,am572x-evm,Power,pm_rtos_testapp DSP/M4: shutdown test failed,
	PRSDK-3656,am572x-evm,Unknown,PM: shutdown test failed on DSP core for am572x-evm,
	PRSDK-3408,am572x-evm,PDK,AM572x GP EVM - camera sysbios loopback example fails for M4,
	PRSDK-6361,am572x-idk,Chip Support,Cycle-intensive interrupt handler breaks timer function,
	PRSDK-5493,am572x-idk,Demonstrations,Gravit Graphics demo: Error: File io init failed!!,
	PRSDK-7174,am572x-idk,PDK,Double interrupt with GPIO level triggering,
	PRSDK-3344,"am572x-idk, am574x-idk",Diagnostics,Diagnostics: icssEmac_TEST on idkAM57{2/4}x fails due to link status being down,ICSS-EMAC LLD TI-RTOS example can be used for similar test.
	PRSDK-5397,am574x-idk,Chip Support,"CSL ECC EMIF test hangs at ""OCMC FULL ECC Mode"" on ARM",
	PRSDK-3383,am574x-idk,Diagnostics,Diagnostics: lcdTouchscreen_TEST hangs,"Issue expected to be specific to TI EVM. For TI EVM, test need to be bypassed from the diagnostic menu."
	PRSDK-5879,am654x-evm,Board Support,Board: Board library needs to cover entire DDR region connected to EMIF1,
	PRSDK-6382,am654x-evm,Boot,SBL: R5F: Core 1 boot is not working with unsigned binary with ipc images,
	PRSDK-6341,am654x-evm,Control Drivers,UART SMP test application hangs in SMP mode on AM65xx board,
	PRSDK-6342,am654x-evm,Debug & Instrumentation,Interrupt latency benchmark hangs in SMP mode on AM65xx board,
	PRSDK-5638,am654x-evm,Diagnostics,AM65xx diag self test hangs during memory test on R5 core,
	PRSDK-6109,"am654x-evm, am654x-hsevm, am654x-idk",Boot,ROM load time of SBL increased on GP devices,"Use ROM degenrate key on GP devices for signing the SBL. To do this, overwrite ti/build/k3_dev_mpk.pem with ti/build/rom_degenerateKey.pem before building the SBL "
	PRSDK-5966,"am654x-evm, am654x-hsevm, am654x-idk",Boot,PLL settings for Maxwell are not optimal,
	PRSDK-4661,"am654x-evm, am654x-hsevm, am654x-idk",Diagnostics,Maxwell: Board diagnostics LCD touchscreen test reports incorrect number of touch events,
	PRSDK-6364,"am654x-evm, am654x-hsevm, am654x-idk",Demonstrations,CAN-GATEWAY-DEMO not present on am65xx installer,
	PRSDK-6054,"am654x-evm, am654x-hsevm, am654x-idk",High-Speed Drivers,Bare-metal USB application performance degradation on Am65xx R5 core as compared to SYSBIOS benchmark,
	PRSDK-4886,"am654x-evm, am654x-hsevm, am654x-idk",High-Speed Drivers,UDMA-P Real-time Remote Peer Registers not Functional Across UDMA-P Domains,
	PRSDK-5755,"am654x-evm, am654x-hsevm, am654x-idk",Networking,ICSS-G-FW: Firmware should not configure ICSSG clock mux,
	PRSDK-5064,"am654x-evm, am654x-idk","Audio, Video, & Display",RTOS: Maxwell MCASP Device Loopback Regression test 7 and 9 fail,
	PRSDK-2951,"am654x-evm, am654x-idk","Board Support, Diagnostics",Maxwell_M4_Diag: LCD Display Diagnostic Stress Test,
	PRSDK-5448,"am654x-evm, am654x-idk",Boot,SBL boot from MMCSD fails intermittently,
	PRSDK-5648,"am654x-evm, am654x-idk",Diagnostics,Maxwell DIAG: UART stress test only runs over JTAG,
	PRSDK-7118,"am654x-evm, am654x-idk",Diagnostics,Diagnostics ICSSG EMAC STRESS: Port 4 Send to Port 5 Receive Test Failed for 10240 packets,
	PRSDK-5097,"am654x-evm, am654x-idk",High-Speed Drivers,USB Dev MSC performance is not on par with Linux driver,
	PRSDK-5544,"am654x-evm, am654x-idk",Networking,Maxwell EMAC LLD example doesn't work at 100Mbps,
	PRSDK-5074,"am654x-evm, j721e-evm",PDK,McASP driver hangs with small buffer size,Use packet size 32 samples or greater
	PRSDK-4680,"am654x-evm, omapl137-evm",PDK,Processor SDK RTOS Post Installer script fails in case cygwin/mingw is overriding Windows default find utility,
	PRSDK-5626,am654x-hsevm,"Boot, DMA",OSPI Read using UDMA fails on AM65x HS devices.,Non-DMA mode could be used for the read operation
	PRSDK-5229,am654x-idk,Board Support,PCIe diagnostic test validates only one port on PCIe 2-lane card,
	PRSDK-4843,am654x-idk,Board Support,Pinmux support for AM654x IDK ICSS MII pin is missing,
	PRSDK-5988,am654x-idk,Control Drivers,OSPI SMP unit test fails in 133MHz speed for AM65xx IDK,
	PRSDK-5989,am654x-idk,Control Drivers,USB Host MSC test hangs in SMP mode on AM65xx IDK board,
	PRSDK-5751,am654x-idk,Diagnostics,AM65xx IDK PCIe diagnostic test failure,
	PRSDK-5022,am654x-idk,Networking,am65xx: Running emac unit test on R5 core from ddrless SBL at times does not complete execution,
	PRSDK-7121,am654x-idk,PDK,OSPI flash test slave in DAC mode at 166MHz RCLK have failed,
	PRSDK-5933,amic110-ice,Networking,NIMU_ICSS iceAMIC110: ping failed at J7 port,
	PRSDK-3727,"c6748-evm, c6748-lcdk",PDK,C6748 is missing from SOC description list in pdkProjectCreate,
	PRSDK-6399,"j721e-evm, k2g-evm",Control Drivers,SPI Master Slave example fails at the UT0,
	PRSDK-7177,"k2e-evm, k2h-evm, k2k-evm",PDK,mmap_TestProject DSP LE: keystone_mmap_init() returned error,
	PRSDK-3114,"k2g-evm, k2g-hsevm, k2g-ice",Diagnostics,K2G: RTOS ECC support broken on ARM core,
	PRSDK-5903,k2g-hsevm,Networking,EMAC_BasicExample DSP LE: Exception at 0xc00fde4,
	PRSDK-3371,omapl137-evm,Boot,Slave boot is failing on evmOMAPL137,
	PRSDK-2989,omapl137-evm,High-Speed Drivers,MMCSD LLD fails on OMAPl137 with 1024 byte block size,
	PRSDK-3412,"omapl137-evm, omapl138-evm",High-Speed Drivers,USB audio class example noise issue on OMAPL13x,
	PRSDK-4043,"omapl137-evm, omapl138-lcdk",High-Speed Drivers,OMAPL13x: USB Baremetal project binaries not built via top level make,

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

+------------------+--------------------------------+---------------+-----------+-----------+-----------+----------+
|     Feature      |    Platform/SOC                |  AM335x EVM   |AM437x EVM | AM57x EVM | AM65x EVM |J721E EVM |
+==================+=======+======+=====+=====+=====+===+===+===+===+===+===+===+=====+=====+=====+=====+==========+
|                  |AM335x |AM437x|AM57x|AM65x|J721E|GP |ICE|SK |BBB|GP |IDK|SK | GP  | IDK | GP  | IDK |  GP      | 
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| CSL              |   X   |   X  |  X  |  X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| EMAC             |   X   |   X  |  X  |  X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| EDMA3            |   X   |   X  |  X  |     |     | X |   |   |   | X |   |   |  X  |     |     |     |          |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| GPIO             |   X   |   X  |  X  |  X  |  X  |   | X |   | X | X |   | X |  X  |  X  |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| GPMC             |   X   |   X  |     |     |     |   | X |   |   | X |   |   |     |     |     |     |          |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| I2C              |   X   |   X  |  X  |  X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| PRUSS-I2C f/w    |   X   |   X  |  X  |     |     |   | X |   |   |   | X |   |     |  X  |     |     |          |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| PRUSS-eSPI f/w   |   X   |   X  |     |     |     |   |   |   |   |   |   |   |     |     |     |     |          |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| ICSS-EMAC        |   X   |   X  |  X  |  X  |     |   | X |   |   |   | X |   |     |  X  |     |     |          |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| McASP            |   X   |   X  |  X  |  X  |  X  | X |   |   |   | X |   |   |  X  |     |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| McSPI            |   X   |   X  |  X  |  X  |  X  |   | X |   |   |   | X |   |     |  X  |   X |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| MMC-SD           |   X   |   X  |  X  |  X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| PCIe             |       |      |  X  |  X  |     |   |   |   |   |   |   |   |     |  X  |  X  |     |          |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| PM               |   X   |      |  X  |  X  |  X  | X |   |   |   |   |   |   |  X  |     |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| PRUSS            |   X   |   X  |  X  |  X  |  X  |   | X |   |   |   | X |   |     |  X  |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| QSPI             |       |   X  |  X  |  X  |  X  |   |   |   |   |   | X | X |     |  X  |     |     |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| OSPI             |       |      |     |  X  |  X  |   |   |   |   |   |   |   |     |     |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| UART             |   X   |   X  |  X  |  X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| USB              |   X   |   X  |  X  |  X  |  X  | X |   |   |   | X |   |   |  X  |  X  |  X  |   X |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| USB Device Audio |   X   |      |     |     |     | X |   |   |   |   |   |   |     |     |     |     |          |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| USB Device Bulk  |   X   |   X  |  X  |  X  |  X  | X |   |   |   | X |   |   |  X  |  X  |  X  |   X |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| VPS              |       |      |  X  |     |     |   |   |   |   |   |   |   |  X  |  X  |     |     |          |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| UDMA             |       |      |     |  X  |  X  |   |   |   |   |   |   |   |     |     |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| SCICLIENT        |       |      |     |  X  |  X  |   |   |   |   |   |   |   |     |     |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| SA               |       |      |     |  X  |  X  |   |   |   |   |   |   |   |     |     |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| CAL              |       |      |     |  X  |  X  |   |   |   |   |   |   |   |     |     |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| DSS              |       |      |     |  X  |  X  |   |   |   |   |   |   |   |     |     |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| FVID2            |       |      |     |  X  |  X  |   |   |   |   |   |   |   |     |     |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+

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

+----------------------------+--------------------------------+---------------+-----------+-----------+-----------+ -----------+
|          Feature           |    Platform/SOC                |   AM335x EVM  |AM437x EVM | AM57x EVM | AM65x EVM |  J721E EVM |
+============================+=======+======+=====+=====+=====+===+===+===+===+===+===+===+=====+=====+=====+=====+============+
|                            |AM335x |AM437x|AM57x|AM65x|J721E|GP |ICE|SK |BBB|GP |IDK|SK | GP  | IDK | GP  | IDK |  GP        |
+----------------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+ -----------+
| Board Support              |   X   |  X   |  X  |  X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |   X        |
+----------------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+ -----------+
| Boot (SBL)                 |   X   |  X   |  X  |  X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |   X        |
+----------------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+ -----------+
| Diagnostics                |   X   |  X   |  X  |  X  |  X  | X |   |   |   | X |   |   |  X  |  X  |  X  |  X  |   X        |
+----------------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+ -----------+
| FATFS                      |   X   |  X   |  X  |  X  |  X  | X | X |   |   | X | X |   |  X  |  X  |  X  |  X  |   X        |
+----------------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+ -----------+
| NDK-NIMU(CPSW)             |   X   |  X   |  X  |  X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |   X        |
+----------------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+ -----------+
| NDK-NIMU(ICSS)             |   X   |  X   |  X  |  X  |  X  |   | X |   |   |   | X |   |     |  X  |  X  |  X  |   X        |
+----------------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+ -----------+
|CC-LINK IE Field Basic(CPSW)|   X   |  X   |  X  |     |     | X | X | X | X | X | X | X |  X  |  X  |     |     |            |
+----------------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+ -----------+
|CC-Link IE Field Basic(ICSS)|   X   |  X   |  X  |     |     |   | X |   |   |   | X |   |     |  X  |     |     |            |
+----------------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+ -----------+

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

Technical Support and Product Updates 
=======================================

For further information or to report any problems, contact:
-  `TI E2E Processor Support <https://e2e.ti.com/support/processors/>`__ for all supported platforms


| 

Archived 
==========
-  `Processor-SDK RTOS
   6.0.0 <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/06_00_00_07/rtos/Release_Specific.html#processor-sdk-rtos-release-notes>`__
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

**Note:** Release Notes prior to 4.3 are not archived. Please see the
:ref:`Migration Guide <RTOS-SDK-Migration-Guide-label>` for information on
migration from these releases.

| 

.. raw:: html
