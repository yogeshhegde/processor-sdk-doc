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

Released October 2018

.. rubric::  What's New
   :name: whats-new

.. rubric::  New Features
   :name: new-features

-  Processor SDK RTOS now includes additional support of AM65x family of devices.
- New platforms: AM65x Evaluation Module (`TMDX654GPEVM <http://www.ti.com/tool/TMDX654GPEVM>`__), AM65x Industrial Development Kit (`TMDX654IDKEVM <http://www.ti.com/tool/TMDX654IDKEVM>`__)
- AM65x
	- Features Supported
		- Boot :SBL (Boot Loader Support) for MMCSD and OSPI interface. Please refer to `SBL AM65x: <Foundational_Components.html#am65x>`__
		- Connectivity: UART, I2C,GPIO, McSPI,OSPI,MMC,CPSW,ICSS-G Dual EMAC/PRU Ethernet,USB host and device, MMCSD,eMMC
		- Audio: McASP
		- DMA Driver: UDMA LLD
		- Display and Camera: DSS,CAL
		- IPC: Hardware spinlocks and mailbox
		- Crypto Low level Driver: SA2 UL
		- DDR @ 1600 MTS, and CPU @ 800 MHz configuration
		- Additional source release for PRU-ICSS-G Dual EMAC firmware
	- Features not (yet) supported: USB 3.0,OSPI 133Mhz/166Mhz, MCU/R5 Split Mode, MPU TI-RTOS SMP Support,CTOOLSLIB
-  PRU-ICSS Dual EMAC Firmware Feature extension:
    - `Multicast filtering <PRU_ICSS.html>`__
    - `Timesync PTP <Foundational_Components.html#timesync-ptp>`__
-  `PRU-ICSS I2C Firmware <PRU_ICSS.html#pru-icss-i2c>`__
	- Additional support for `PRU-ICSS-0 instance of AM437x SOC <PRU_ICSS.html#pru-icss-i2c>`__
-  AM335x Connectivity extension to support `Simplelink 3120 NWP WiFi <Examples_and_Demonstrations.html#simplelink-wifi-demo>`__

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
|  IPC        | 3.50.2      |      |      |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |         |    X    |
+-------------+-------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  LIBARCH    | 1.0.0.0     |      |      |      |      |   X   |      |      |      |      |  X   |         |         |
+-------------+-------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  LINALG     | 1.2.0.0     |      |      |      |      |   X   |      |      |      |      |  X   |         |         |
+-------------+-------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  MATHLIB    | 3.1.1.0    |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  MPM        | 3.0.4.0    |      |      |      |      |   X   |  X   |  X   |  X   |      |      |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  NDK        | 3.40.1     |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  NS         | 2.40.1     |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  OPENCL     | 1.1.14.1   |      |      |  X   |      |       |      |      |      |      |      |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  OPENMP     |2.6.2.1     |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  PDK        |            |1.0.12|1.0.12|1.0.12| 1.0.2| 4.0.11|4.0.11|4.0.11|1.0.11|2.0.11|2.0.11|  1.0.6  |  1.0.6  |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  SYS/BIOS   | 6.73.0.03  |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  UIA        | 2.30.1.2   |      |      |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  XDAIS      | 7.24.0.4   |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  XDCTOOLS   | 3.50.07.20 |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+


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
|   EMU Pack|Sitara    |   X  |  X   |  X   |  X   |       |     |     |     |     |     |         |         |
|           |Device    |      |      |      |      |       |     |     |     |     |     |         |         |
|           |1.4.1     |      |      |      |      |       |     |     |     |     |     |         |         |
+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+
|    TI     |8.0.803.0 |   X  |  X   |  X   |  X   |   X   |  X  |  X  |  X  |  X  |  X  |     X   |     X   |
| Emulators |          |      |      |      |      |       |     |     |     |     |     |         |         |
+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+

If you need to install CCS, see the `CCS installation section <Overview.html#code-composer-studio>`__
in the *Getting Started Guide* for options to select for Processor-SDK.



Fixed Issues 
==============

.. csv-table::
   :header: "Record ID","Board/s", "Component/s", "Summary"
   :widths: 15, 20,20,30
   
	PRSDK-642,*,System Integration,RTOS: SDK components should be signed to avoid Eclipse/CCS warning when importing
	PRSDK-4460,am335x-evm,Chip Support,MDIOPhyRegRead() implementation in mdio.c contains erroneous semicolon
	PRSDK-4449,"am437x-evm, am437x-hsevm, am437x-idk, am437x-sk",Control Drivers,Processor SDK Starterware QSPI clock setup issue on AM437x
	PRSDK-4712,"am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk",Demonstrations,POSIX-SMP demo failed to work
	PRSDK-4187,"am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk",Control Drivers,UART LLD input clock control required at LLD level.
	PRSDK-4197,"am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk",Control Drivers,UARTDivisorValCompute does not round up to nearest integer resulting in large baudrate errors
	PRSDK-4546,"am570x-evm, am571x-idk, am572x-evm, am572x-idk, am574x-idk, k2g-evm, k2h-evm, k2k-evm",Boot,SBL RPRC parser bug when checking section address for L1D range on DSP1
	PRSDK-4105,"am571x-idk, am572-evm, am572x-evm, am572x-idk, am574x-idk",Control Drivers,UART open sets up incorrect baudrates for 921600 bps settings.
	PRSDK-3318,k2g-evm,Networking,EMAC_CpswRateLimit_evmK2G_c66xExampleProject failure on 1GHz Flip Chip
	PRSDK-4303,"k2g-evm, k2g-hsevm, k2g-ice",Chip Support,C++ build issue due to cslr_msmc.h missing closing brackets for extern C
	PRSDK-4016,k2h-evm,Networking,NDK stack task doesn't work after moving to any core other than core 0
	PRSDK-4305,omapl138-lcdk,Demonstrations,BenchmarkProjectCreate.bat error: CGT_VERSION not set


	
Known Issues 
==============

This section contains the list of known issues at the time of making the
release and any known workaround.

.. csv-table::
   :header: "Record ID","Board/s", "Component/s", "Summary","Workaround"
   :widths: 15, 20,20,30,70

	PRSDK-4529,*,KeyStone Drivers,UART LLD can't read value 0xff byte over the UART as it is detected as -1 (error),UART LLD when configured to read data in BINARY format reports error and hangs if the received data is 0xFF. Issue is because it conflicts with failure return code. Workaround will be either prevent above pattern if controlled use case or modify the driver to bypass the failure handling
	PRSDK-3482,*,CCS,CCSV8.1: Intermittent issue not able to connect target while using DSS script,Retry for connection failure in DSS script.
	PRSDK-4412,*,System,Processor SDK RTOS Windows installer needs to be signed,Warning message if seen can be ignored
	PRSDK-4180,*,UNIFLASH,Sitara Uniflash CLI Plugin could not open COM ports with number higher than 9,Select COM ports in lower range
	PRSDK-4304,"am335x-evm, am335x-ice, amic110-ice",Board Support,Flash Writer pre-built Binary does not work,Rebuilding the flash writer binaries shall fix this issue. Refer the Rebuilding the flash writer
	PRSDK-4617,"am335x-evm, am335x-sk, am437x-sk, amic110-ice, beagleboneblack","Control Drivers, Networking",Cortex-A8: Semi host support warning in CCS,Warning can be ignored
	PRSDK-2336,"am335x-evm, am437x-evm",Power,PM LLD test failing using CCS/JTAG,"The debug versions of the PM apps are still functional. To build them: 
	From the top-level makefile in pdk.../packages folder run ""make BUILD_PROFILE=debug pm"" 
	This will build the debug versions of the PM RTOS and measurement apps."
	PRSDK-4725,"am335x-ice, am437x-idk",PDK,PTP: ICSS-EMAC LLD Master Mode config does not sync with slave,
	PRSDK-4448,"am437x-evm, am437x-hsevm, am437x-idk, am437x-sk",High-Speed Drivers,SD card insert/remove doesn't work in MMCSD/FATFS,Modify PINMUX config for CTRL_CONF_SPI0_CS1 to 0x00060007 instead of 0x00060005
	PRSDK-4727,am437x-idk,Diagnostics,ledIndustrial_TEST of Diagnostics hangs,Delay value need to be tuned for the SOC. Add BoardDiag_AppDelay(0x1FFFF); after Board_i2cIoExpWritePort() for test to pass
	PRSDK-330,AM4X,High-Speed Drivers,USB device MSC re-enumeration failed,Problem not observed with Linux USB Host.
	PRSDK-335,"AM4X, k2g-evm",High-Speed Drivers,USB host MSC fails to re-enumerate,Re-enumeration support for the case of device unplugged and plugged back currently fails for the example. Workaround is to avoid disconnecting drive while running example.
	PRSDK-2892,"am571x-idk, am572x-evm, am572x-idk",PDK,Incorrect A15 MMU configurations in default config file,"Set MMU attribute to not executable for device memory 
	attrs0.noExecute = true; // Not executable"
	PRSDK-1682,"am571x-idk, am572x-idk",Diagnostics,Board diagnostics LCD Touchscreen test does not work with new version of LCD TSC,For LCD/Display checkout example under VPS component could be used
	PRSDK-4541,"am571x-idk, c6748-lcdk, k2g-evm, omapl138-lcdk",OSAL,OSAL_BasicExample DSP LE hangs after HWI tests have passed.,Issue narrowed to example causing incorrectly creating two duplicate task. Example could be modified for the fix
	PRSDK-4184,am572x-evm,Example,Hello_World: Baremetal ARM Cortex-A15 test example failure,Problem observed with using GCC semihosting support. Can use UART driver for input and output
	PRSDK-4667,am572x-evm,"Demonstrations, Networking",Image Processing Demo lock up on AM572x GP EVM,Issue seen using 1Gig router on ETH0. Replace with 100Mbps
	PRSDK-1975,am572x-evm,Diagnostics,timer_DiagExample_evmAM572x_arm7.out doesn't work on ARM1 core,Example can run on ARM Core 0
	PRSDK-2166,am572x-idk,High-Speed Drivers,USB3.0 host problem with Sandisk Extreme USB3.0 stick,"Start the example without the USB plugged in. Once the example is up and waiting for USB stick, plug the USB stick in and it will enumerate properly."
	PRSDK-4668,am572x-idk,Board Support,AM65xx Diag: ICSSG Ethernet Test hang while running second time,Diagnostic test still can be used for basic checkout of the board
	PRSDK-3344,"am572x-idk, am574x-idk",Diagnostics,"Diagnostics icssEmac_TEST idkAM57{2/4}x : LINK IS DOWN, pluggin loopback cable",ICSS-EMAC LLD TI-RTOS example can be used for similar test.
	PRSDK-3383,am574x-idk,Diagnostics,Diagnostics: lcdTouchscreen_TEST hangs,"Issue expected to be specific to TI EVM. For TI EVM, test need to be bypassed from the diagnostic menu."
	PRSDK-4743,am654x-evm,Networking,"Host buffers need to be in MSMC for high throughput icss-g dual mac performance (FTP put/get). Host buffers in DDR results in degradation, improvement pending",Update linker command file for Buffer placement to on chip MSMC memory
	PRSDK-4741,am654x-evm,Boot,SBL does not work if entry point specified is address 0x0,"For baremetal and BIOS applications, The SBL reserves the first 0x100 bytes of memory from address 0x0 and memory from 0x41C00200 to 0x41C60000 for its use. This memory is available only for run time use by applications. For MCU RTOS applications, the linker command file must specify the entry point as 
	--entry_point=ti_sysbios_family_arm_v7r_keystone3_Hwi_vectors 
	
	and add the following line to the BIOS application config file 
	Program.sectMap["".vecs""] = ""MCU0_R5F_TCMA""; 
	
	(Refer http://git.ti.com/keystone-rtos/processor-pdk-build/blobs/master/am65xx/linker_r5_sysbios.lds for an example)"
	PRSDK-4121,am654x-evm,Boot,make all fails for Windows due to missing openSSL package,"| 
	For Windows : Download and install `Strawberry Perl <http://strawberryperl.com/download/5.28.0.1/strawberry-perl-5.28.0.1-64bit.msi>`__. The Strawberry Perl installer automatically installs and sets up OpenSSL. 
	
	For Linux : Execute the command ""sudo apt-get install openssl"" at the linux command prompt. 
	
	Check if OpenSSL is installed by typing ""openssl version"" at the command prompt. 
	|"
	PRSDK-4462,am654x-evm,System,IPC A53 ROV log won't show correctly because of XDCtools bug,Need to recompile examples/test with new XDC tool to resolve issues.
	PRSDK-4706,"am654x-evm, am654x-idk",Boot,SBL: MCU0 Boot in R5 Split Mode not supported in SBL,Dual R5 configuration support in SBL could be used
	PRSDK-4478,"am654x-evm, am654x-idk",Chip Support,AM65x R5F Baremetal CSL Startup code is setting instruction cache to disabled,"""S"" bit in MPU attr need to be set to ""0"" in CSL startup code for enabling instruction cache"
	PRSDK-4464,"am654x-evm, am654x-idk",Networking,ICSS-G-FW: Dual-emac: ping with 16K packet size fails,
	PRSDK-4771,"am654x-evm, am654x-idk",High-Speed Drivers,MMCSD_EMMC_Regression_TestApp hangs during DDR part of test,Application can configure for higher supported speed mode HS200
	PRSDK-4630,"am654x-evm, am654x-idk",Demonstrations,Windows top level gmake clean followed by gmake all does not complete,"Issue due to dependency for PDK build before IPC example build. As a workaround following sequence will work 
	gmake clean 
	gmake pdk 
	gmake all 
	"
	PRSDK-4639,"am654x-evm, am654x-idk",Chip Support,SBL examples currently does not program loaded from DDR for R5 core,"If an MCU application uses DDR, it must setup the RAT before it accesses DDR. The best place to set it up is in the reset vector, before branching to c_init_00. For an eg, please refer the code for the sbl_mcu_ddr_entry test case http://git.ti.com/keystone-rtos/sbl/blobs/master/example/ampMulticoreApp/sbl_ddr_entry_r5.asm"
	PRSDK-4662,"am654x-evm, am654x-idk",Diagnostics,Board diagnostics application intermittently hangs,Issue is seen due to PLL initialization in the led test. PLL initialization can be skipped in LED test or test could be bypassed
	PRSDK-4526,"am654x-evm, am654x-idk",Board Support,R5 Interrupts will not work when program is loaded using CCS,"If code is loaded using CCS, the reset vector must be at 0x41C00000"
	PRSDK-4050,"am654x-evm, am654x-idk",Control Drivers,RTOS: K3: OSPI high speed mode is not supported,"OSPI driver not functional for Full rate 133, 166 MHz with PHY enabled. Workaround by default is enabled in driver with PHY disabled. No change required for application"
	PRSDK-4704,"am654x-evm, am654x-idk",PDK,R5F RTOS MPU attributes don`t support running out of ATCM memory,"Workaround 
	Current MPU settings set permission and sets ATCM region as 1KB size which needs to be changed to 32 KB Modify following from. 
	MPU.setRegionMeta(1, 0x00000000, MPU.RegionSize_1K, attrs); 
	To 
	MPU.setRegionMeta(1, 0x00000000, MPU.RegionSize_32K, attrs); 
	"
	PRSDK-4718,"am654x-evm, am654x-idk",Board Support,DDR Controller ECC Scrubbing feature can cause DRAM data corruption,The ECC scrubbing feature inside the DDR controller must be kept disabled at all times by setting DIS_SCRUB=1 in the DDR controller's ECC Configuraion 0 (DDRCTRL_ECCCFG0) register.
	PRSDK-4779,"am654x-evm, am654x-idk",Board Support,AM65xx: Test control does not return to menu after executing USB device test,Reboot the board after running the USB device test
	PRSDK-4778,"am654x-evm, am654x-idk",Board Support,SPI NOR flash diagnostic test is failing on AM65xx platform with IDK application card,Keep SPI0 CS1 (SOC_PADCONFIG_112) high during NOR flash test.
	PRSDK-4777,"am654x-evm, am654x-idk",Board Support,AM65xx EMAC diagnostic test failure,Ethernet functional test runs fine but extended tests cannot be run due to this failure. Test control returns to menu after failure and allows to run other tests normally.
	PRSDK-4689,"c6657-evm, c6678-evm",Networking,NIMU example fails compilation for big endian projects. Feature being descoped,BE mode has been descoped. Little Endian mode is supported.
	PRSDK-4145,c6678-evm,Control Drivers,SPI v0 ISR hangs processor when RX data is not ready after TX data has sent,"Add a WHILE delay loop in after the 
	SPI_INT_TX_EMPTY is processed, until SPI_INT_RX_FULL is set."
	PRSDK-4214,k2g-hsevm,System,create-sdcard script does not boot OOB,Default generated App image is not signed follow the steps mentioned in User Guide of the Processor SDK Secdev Build and Install Guide to sign the app
	PRSDK-4721,k2g-ice,Diagnostics,"Diagnostics EMAC iceK2G: test hangs after ""Received Packet: 10""",Diagnostic test can still be used for board checkout
	PRSDK-4758,k2h-evm,Boot,Images not booting on slave DSP cores,
	PRSDK-4456,omapl138-lcdk,Control Drivers,OMAPL138 SPI driver doesn't configure clock polarity and phase when in slave mode,SPIFMT Polarity & Phase bits can be updated inside the driver directly to reflect the required config
	PRSDK-4108,omapl138-lcdk,High-Speed Drivers,USB Audio: Lag when trying to adjust volume,



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
-  **Linux**: Ubuntu 14.04, 16.04 on 64-bit machine

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

For further information or to report any problems, contact:
-  TI E2E Processor Support <https://e2e.ti.com/support/processors/>`__
   for all supported platforms


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
