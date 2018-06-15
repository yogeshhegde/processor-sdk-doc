.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_BOOT_AM65x 

.. rubric:: Overview
   :name: overview-1

The Secondary Bootloader (SBL) for AM65xx device initializes the execution environment for multi-core application and this can be used to demonstrate a real world product experience.The section covers additional details including execution sequence, tools and additional flashing instructions.

.. rubric:: Bootloader Execution Sequence
   :name: bootloader-execution-sequence

-  **Power On Reset**
-  **ROM Bootloader (RBL)**

   -  Software pre-programmed in AM65xx ROM memory starts executing
   -  The RBL performs platform configuration and initialization.
   -  It then checks sysboot pins and chooses booting device
   -  The RBL then configures DPLL and clock settings for MPU, and boot media like eMMC, SD/MMC, OSPI, UART, PCIe, Ethernet etc for reliable boot.
   -  If no valid bootloader found on booting device, the RBL checks for next booting device, based on sysboot pins
   -  The gets image size and load address by checking the X.509 certificate that is part of the bootloader image.
   -  The RBL then verifies, optionally decrypts and loads the binary to internal memory at the Load address fetched from X.509 certificate.
   -  Finally it passes control to Secondary Bootloader(SBL) running on the R5.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
: Detailed description of ROM bootloader is provided in Initialization Chapter in AM65xx Technical Reference Manual.

.. raw:: html

   </div>

-  **Secondary bootloader(SBL)**

   -  User level secondary bootloader(SBL) begins execution from internal memory by running basic initialization routines like  setting up Stack, BSS and then jumps to main() to begin Board Initialization.
   -  Board Initialization is done by a call to **Board_init()** API.For additional details refer `Processor SDK Board Support <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Board_Support>`__.
   -  It includes setting up PLLs, loading the system firmware,enabling clocks to all interfaces and modules, performing pinmux and setting up UART console.
   -  Parses application image(s) for each of the core(s) from boot media and loads it to memory.
   -  Once the application is loaded, the SBL communicates with the system firmware to setup the clocks for the core and release it from reset.
   -  The core then starts executing from application entry point.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**

-  RBL requires boot loader to be in a special format with a X.509 certificate appended to the binary image. The certificate contains the load address, size and SHA of the bootloader image.
-  For more information on the image format expcted by the RBL refer AM65xx Technical Reference Manual.

.. raw:: html

   </div>

.. rubric:: Directory structure
   :name: directory-structure

**Makefiles:**

-  **PDK_INSTALL_PATH/ti/boot/sbl/build/sbl_lib.mk**: Makefile for bootloader that builds the sbl library that other apps can link into.
-  **PDK_INSTALL_PATH/ti/boot/sbl/build/sbl_img.mk**: Makefile for bootloader that builds the sbl image.
-  **PDK_INSTALL_PATH/ti/boot/sbl/build/sbl_boot_test.mk**: Makefile for application images for individual corea to test the SBL
-  **PDK_INSTALL_PATH/ti/boot/sbl/build/sbl_multicore_amp.mk**: Makefile for combining tests to generate create a single image that boots different cores in AM65xx.

**Source Files:**

-  **PDK_INSTALL_PATH/ti/boot/sbl\board/am65xx_evm**: Sources for SBL main function that consolidates all features
-  **PDK_INSTALL_PATH/ti/boot/sbl/soc/am65xx**: Sources for SOC specific initialization used in the SBL.
-  **PDK_INSTALL_PATH/ti/boot/sbl/src**: Source for boot media specific initialization used in the SBL. Also contains sources for boot image processing that is common across all SOCs.

.. rubric:: Tools and Binary Formats
   :name: tools-and-binary-formats

This section lists out the various tools and scripts used by SBL for different boot modes and those required to create a bootable application image.

**SBL image format:**

To generate the a bootable image, SBL uses x509CertificateGen script to sign the sbl binary with so that the RBL can parse it. The image format has been described in detail in the Image Format Section of the AM65xx Technical Reference manual.

|

**Application image format:**

A bootable application image can be created by using out2rprc and multicoreImageGen to convert the application elf image(s) into an image loadable by the SBL. Graphical view of the multicore application image is provided below:

.. Image:: ../images/Multicore_app_image.png

The script creates the bootable image in 2 steps

**Step 1: Conversion to RPRC format conversion**

-  Firstly, application executable is converted from ELF/COFF format (\*.out) to custom TI Rprc binary image using out2rprc tool. This tool strips out the initialized sections from the executable file (i.e.
   \*.out) and places them in a compact format that the SBL can understand. The output (\*.rprc) file is typically much smaller than the original executable (out) file.
-  The rprc files are intermediate files in a format that is consumed by MulticoreImageGen tool that generates the final binary (\*.appimage).

**RPRC File Header Format**

+------------+----------------------------+
| Offset     | Binary value               |
+============+============================+
| 0x00000000 | **Magic Word(43525052)**   |
+------------+----------------------------+
| 0x00000004 | **Entry Point (Location)** |
+------------+----------------------------+
| 0x00000008 | **Reserved Addr**          |
+------------+----------------------------+
| 0x0000000C | **Section Count**          |
+------------+----------------------------+
| 0x00000010 | **Version**                |
+------------+----------------------------+

**RPRC Section Header Format**

+------------+---------------------------+
| Offset     | Binary value              |
+============+===========================+
| 0x00000000 | **Section start Address** |
+------------+---------------------------+
| 0x00000004 | **Reserved Addr**         |
+------------+---------------------------+
| 0x00000008 | **Size**                  |
+------------+---------------------------+
| 0x0000000C | **Reserved CRC**          |
+------------+---------------------------+
| 0x00000010 | **Reserved**              |
+------------+---------------------------+

| 
| **Step 2: Multicore Image file generation**

-  RPRC files for each cores is combined into a single multicore bootable application image.

**Multicore boot image format**

**Meta Header Start**

+------------+-------------------------------+
| Offset     | Binary value                  |
+============+===============================+
| 0x00000000 | **Magic String (0x5254534D)** |
+------------+-------------------------------+
| 0x00000004 | **Number of Files**           |
+------------+-------------------------------+
| 0x00000008 | **Device ID**                 |
+------------+-------------------------------+
| 0x0000000C | **Reserved**                  |
+------------+-------------------------------+

**Meta Header per Core**

+------------+------------------+
| Offset     | Binary value     |
+============+==================+
| 0x00000000 | **Core ID**      |
+------------+------------------+
| 0x00000004 | **Image Offset** |
+------------+------------------+

Core ID and Device ID for specific devices can be located in the file sbl_slave_core_boot.h in the boot/sbl/soc/am65xx folder

| 

.. rubric:: Building the SBL
   :name: building-the-sbl

**Pre-requisites to Building**

-  Set your environment using pdksetupenv.bat or pdksetupenv.sh. Referto the Processor SDK RTOS Building page for information on setting up your build environment

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
: Refer to the makefile for the board you are using for the latest driver dependency. These libraries should come pre-built with any fresh installation of the Processor SDK RTOS but may be removed if a gmake
clean is invoked.

.. raw:: html

   </div>

| 

**Compiling the SBL Components**

To build the SBL components:


::


    cd <PDK>/packages/ti/boot/sbl/build
    make BOOTMODE=<BOOTMEDIA> clean all
    BOOTMEDIA : mmcsd, ospi, uart, eth, pcie

-  SBL image files will be located in: **<PDK>/packages/ti/boot/sbl/img/**
-  SBL examples will be located in **<PDK>/packages/ti/boot/sbl/examples/**
-  SBL lib will be located in **<PDK>/packages/ti/boot/sbl/lib/**

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
: Refer **<PDK>/packages/ti/boot/sbl/buid/sbl_am65xx.sh** for more build options

.. raw:: html

   </div>

| 

.. rubric:: Boot Modes
   :name: boot-modes

The SBL supports MMCSD, OSPI, UART, Ethernet and PCIe Boot modes. The different boot modes supported for all the am65xx boards is tabulated below.

+-----------------------+--------+------+------+------+------+
|                       | MMCSD  | OSPI | UART | PCIe | ETH  |
+-----------------------+--------+------+------+------+------+
| AM65xx EVM            |  YES   | YES  | YES  | YES  | YES  |
+-----------------------+--------+------+------+------+------+


| 

.. rubric:: Booting Via SD Card
   :name: booting-via-sd-card

#. Preparing the SD card.
#. Booting the target.

.. rubric:: Preparing the SD card 
   :name: preparing-the-sd-card

#. To boot the target the SD card should be bootable. Follow the steps
   at `Creating bootable SD card in
   windows <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Creating_a_SD_Card_with_Windows>`__
   or `Creating bootable SD card in
   Linux <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_create_SD_card_script>`__.
#. Delete the "MLO" and "app" in the bootable SD card which are created
   in the process of making the SD bootable.
#. Copy the sbl image (sbl_mmcsd_img_mcu1_0_release.tiimage) to the SD card. Rename it to **tiboot3.bin**
#. Copy the Application image(\*.appimage) generated to the SD card. Rename it to **app**

.. rubric:: Booting the target
   :name: booting-the-target

#. Insert SD card into the SD card slot of the board.
#. Refer EVM documentation to setup ROM to boot from MMCSD.
#. Open a serial communication terminal like TeraTerm, MiniCom on host
   PC and connect to the UART console port
#. Do a power reset of the board to boot the appliation from the SD
   card.

| 

.. rubric:: Test Application
   :name: test-application

SBL provides a test application to demonstrate booting of multicore application image on A53 and R5 cores.The multicore sample application prints a message on the UART for each core. It is used to validate the multi-core boot-up use case..

| 

.. rubric:: Application Image Creation
   :name: application-image-creation

Application Image creation involves three steps.

|

#. Generating the .outs of applications for individual cores
#. Converting the .outs into .rprc images
#. Combining the .rprc images of individual cores to create a bootable multicore image

|

To covert any .out into a bootable image that can be loaded by sbl, execute the following commands

|

**For Linux**

::

    mono <PDK>/packages/ti/boot/sbl/tools/out2rprc/bin/out2rprc.exe input.out output.rprc
    <PDK>/packages/ti/boot/sbl/tools/multicoreImageGen/bin/MulticoreImageGen LE 55 output.appimage  <core_id> output.rprc

|

**For Windows**

::

    <PDK>/packages/ti/boot/sbl/tools/out2rprc/bin/out2rprc.exe input.out output.rprc
    <PDK>/packages/ti/boot/sbl/tools/multicoreImageGen/bin/MulticoreImageGen.exe LE 55 output.appimage  <core_id> output.rprc

|

To stitch multiple .rprc images into a multicore image, execute the following command

|

**For Linux**

::

    <PDK>/packages/ti/boot/sbl/tools/multicoreImageGen/bin/MulticoreImageGen LE 55 output.appimage  <core_id_1> core_1.rprc <core_id_2> core_2.rprc

|

**For Windows**

::

    <PDK>/packages/ti/boot/sbl/tools/multicoreImageGen/bin/MulticoreImageGen.exe LE 55 output.appimage  <core_id_1> core_1.rprc <core_id_2> core_2.rprc

|

To add an image that must be loaded, but not executed, convert the .out into an .rprc as mentioned above. Then use the following comand



**For Linux**

::

    <PDK>/packages/ti/boot/sbl/tools/multicoreImageGen/bin/MulticoreImageGen LE 55 output.appimage  <core_id_1> to_execute.rprc <ONLY_LOAD_ID> only_load.rprc 

|

**For Windows**

::

    <PDK>/packages/ti/boot/sbl/tools/multicoreImageGen/bin/MulticoreImageGen.exe LE 55 output.appimage  <core_id_1> to_execute.rprc <ONLY_LOAD_ID> only_load.rprc

To get the value of ONLY_LOAD_ID refer **sbl_slave_core_boot.h** in the **<PDK>/packages/ti/boot/sbl/soc/am65xx**

|

The steps to create the bootable examples in Linux and Windows environment are listed below.

.. rubric:: Linux Environment:
   :name: linux-environment

Command to build the test application.

::

    cd (TI_PDK_INSTALL_DIR)\packages/ti/boot/sbl/build
    make example



#. Copy the Bootlaoder image(sbl_mmcsd_img_mcu1_0_release.tiimage) and application(sbl_boot_test_all_cores_release.appimage) in the SD card.
#. Rename sbl_mmcsd_img_mcu1_0_release.tiimage to **tiboot3.bin** and sbl_boot_test_all_cores_release.appimage to **app**.
#. Setup the EVM to boot from MMCSD and power cycle the board.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**

-  The make depends on tools like mono to execute the out2rprc.exe.
-  The linux host environment needs to have this tool installed to execute this script.
-  Refer this link to download the `mono <http://www.mono-project.com>`__ tool

.. raw:: html

   </div>

.. rubric:: Windows environment:
   :name: windows-environment

Command to build the test application.

::

    cd (TI_PDK_INSTALL_DIR)\packages\ti\boot\sbl\build
    gmake example


#. Copy the Bootlaoder image(sbl_mmcsd_img_mcu1_0_release.tiimage) and application(sbl_boot_test_all_cores_release.appimage) in the SD card. 
#. Rename sbl_mmcsd_img_mcu1_0_release.tiimage to **tiboot3.bin** and sbl_boot_test_all_cores_release.appimage to **app**.
#. Setup the EVM to boot from MMCSD and power cycle the board.

| 

.. rubric:: Setup Requirements
   :name: setup-requirements

For information on board specific requirements like power supply, UART console port connections refer the Hardware User guide of the respective boards.

The configurations needed to setup UART console through a serial terminal application on host PC are listed in the next section.

.. rubric:: UART Console Setup
   :name: uart-console-setup

PDK SBL prints messages on the UART Serial Console running on the host. Hence, a serial terminal application (like Tera Term/HyperTerminal/minicom) should be running on the host. 

-  The host serial port must be configured at 115200 baud, no parity, 1  stop bit and no flow control.
-  Please ensure that the local echo setting for the terminal is turned  off.

|

|

