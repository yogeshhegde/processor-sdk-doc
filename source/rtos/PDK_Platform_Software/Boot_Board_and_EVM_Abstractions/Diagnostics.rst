.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_DIAG 

| .. rubric:: **Overview**          | .. rubric:: **User Interface**    |
|    :name: overview                |    :name: user-interface          |
|                                   |                                   |
| -  `Overview </index.php/Processo | -  `Running the Diagnostic        |
| r_SDK_RTOS_DIAG#Overview>`__      |    Examples </index.php/Processor |
| -  `Building the                  | _SDK_RTOS_DIAG#Running_the_Diagno |
|    Examples </index.php/Processor | stic_Examples>`__                 |
| _SDK_RTOS_DIAG#Building_the_Examp |                                   |
| les>`__                           | -  `Loading through SD Card       |
|                                   |    (Default                       |
| -  `Pre-requisites to             |    Method) </index.php/Processor_ |
|    Building </index.php/Processor | SDK_RTOS_DIAG#Loading_through_SD_ |
| _SDK_RTOS_DIAG#Pre-requisites_to_ | Card_.28Default_Method.29>`__     |
| Building>`__                      | -  `Running or debugging on       |
| -  `Compiling the Diagnostic      |    CCS </index.php/Processor_SDK_ |
|    Applications </index.php/Proce | RTOS_DIAG#Running_or_debugging_on |
| ssor_SDK_RTOS_DIAG#Compiling_the_ | _CCS>`__                          |
| Diagnostic_Applications>`__       |                                   |
| -  `Creating the SD Card Loadable |                                   |
|    Files </index.php/Processor_SD |                                   |
| K_RTOS_DIAG#Creating_the_SD_Card_ |                                   |
| Loadable_Files>`__                |                                   |
| -  `Make                          |                                   |
|    targets </index.php/Processor_ |                                   |
| SDK_RTOS_DIAG#Make_targets>`__    |                                   |
+-----------------------------------+-----------------------------------+
| .. rubric:: **Application**       | .. rubric:: **Debug**             |
|    :name: application             |    :name: debug                   |
|                                   |                                   |
| -  `Diagnostic                    | -  Tips                           |
|    Applications </index.php/Proce |                                   |
| ssor_SDK_RTOS_DIAG#Diagnostic_App |                                   |
| lications>`__                     |                                   |
|                                   |                                   |
| -  `Additional Jumper or Hardware |                                   |
|    Settings </index.php/Processor |                                   |
| _SDK_RTOS_DIAG#Additonal_Jumper_o |                                   |
| r_Hardware_Settings>`__           |                                   |
+-----------------------------------+-----------------------------------+

.. rubric:: Overview
   :name: overview-1

The Processor SDK RTOS Diagnostic package is designed to be a set of
baremetal tests to run on a given board to provide data path continuity
testing on peripherals. For K2H/K2E/K2L/C66x devices, this functionality
is provided by `POST </index.php/Processor_SDK_RTOS_POST>`__.

.. rubric:: Building the Examples
   :name: building-the-examples

.. rubric:: Pre-requisites to Building
   :name: pre-requisites-to-building

#. Set your environment using pdksetupenv.bat or pdksetupenv.sh. The
   diagnostic application uses the same environment variables as the
   board library build. Refer to the `Processor SDK RTOS
   Building </index.php/Processor_SDK_RTOS_Building_The_SDK>`__ page for
   information on setting up your build environment.
#. You will need the following libraries built:

-  Board
-  UART
-  GPIO
-  I2C
-  SPI
-  CSL
-  ICSS
-  PRUSS

(Note: not every library is used for every application, and these
libraries should come pre-built with any fresh installation of the
Processor SDK)

.. rubric:: Compiling the Diagnostic Applications
   :name: compiling-the-diagnostic-applications

To build the diagnostic examples:

#. **cd <PDK>/packages/ti/board/diag**
#. **make <BOARD>**

This will make the diagnostic applications for a specific $BOARD.
Alternatively, "make all" will make for all boards. Output files will be
located in: **<PDK>/packages/ti/board/bin/<BOARD>**

.. rubric:: Creating the SD Card Loadable Files
   :name: creating-the-sd-card-loadable-files

For converting the compiled .out files to a format loadable by TI's
Secondary Boot Loader (SBL), you must follow these two steps:

#. **out2rprc.exe [.out file] [rprc output]**
#. **MulticoreImageGen.exe LE 55 [output name] 0 [rprc output]**

Out2rprc.exe and MulticoreImageGen.exe are tools supplied by TI and can
be located in the **<PDK>/packages/ti/boot/sbl/tools** folder. "rprc
output" can be any spare name of your choosing. "output name" can also
be any name of your choosing. **For diagnostic applications, your final
output name must have the keyword "TEST" in it.** You will have to do
this process for every .out application you wish to be loadable on the
SD card.

Alternatively, there is also a make target to automate this process:

#. **cd <PDK>/packages/ti/board/diag**
#. **make <BOARD>_sd**

This will compile all the applications for a specific $BOARD, and also
create the SD card loadable files. The output files will be located in:
**<PDK>/packages/ti/board/bin/<BOARD>/sd**. Note that the framework
application is named "app" to allow it to be the default application to
be loaded by the SBL.

.. rubric:: Creating the SPI Flash Loadable Files
   :name: creating-the-spi-flash-loadable-files

SPI boot shall be the primary boot option for the platforms (Ex: AMIC110
ICE) which does not support SD card interface. All the diagnostic tests
are integrated into framework binary for the ease of use in the case of
SPI boot. Integrated diagnostic framework test binary can be loaded and
executed through UART port.

Use below command to build the diagnostic tests and create SPI flash
loadable files.

-  **make <BOARD>_spi**

| 

.. rubric:: Make targets
   :name: make-targets

The simplest invocation is to use "make <BOARD>" to compile all the
applications. Here is a list of make targets implemented for the
diagnostic makefile:

-  **make <BOARD>** - compile all diagnostic applications for one
   specific BOARD
-  **make clean** - clean and remove all applications for all supported
   BOARDs
-  **make <BOARD>_clean** - clean and remove all application for one
   specific BOARD
-  **make <BOARD>_sd** - compile all diagnostic applications for one
   specific BOARD and create the SD card loadable files with those
   compiled applications
-  **make <BOARD>_spi** - compile all diagnostic applications for one
   specific BOARD and create the SPI flash loadable files with those
   compiled applications

The <BOARD> supported depends on your Processor SDK RTOS variant. Refer
to following table for available <BOARD> for each Processor SDK RTOS
variant:

+-----------+-----------+-----------+-----------+-----------+-----------+
| make      | am335x    | am437x    | am57xx    | k2g       | omapl13x  |
| target /  |           |           |           |           |           |
| Variant   |           |           |           |           |           |
+===========+===========+===========+===========+===========+===========+
| <Board>   | evmAM335x | evmAM437x | idkAM572x | evmK2G    | evmOMAPL1 |
|           | skAM335x  | skAM437x  | idkAM571x | iceK2G    | 37        |
|           | bbbAM335x | idkAM437x | evmAM572x |           | (No Boot  |
|           | icev2AM33 |           | idkAM574x |           | support.  |
|           | 5x        |           |           |           |           |
|           | iceAMIC11 |           |           |           | Diagnosti |
|           | 0         |           |           |           | cs        |
|           |           |           |           |           | need to   |
|           |           |           |           |           | run from  |
|           |           |           |           |           | CCS)      |
+-----------+-----------+-----------+-----------+-----------+-----------+

**Note:** OMAPL137 EVM diagnostic tests does not support executing from
a boot device. Use the command **make evmOMAPL137** to build the
diagnostics. Diagnostics test binaries need to be executed from CCS.

.. rubric:: Running the Diagnostic Examples
   :name: running-the-diagnostic-examples

.. rubric:: Loading through SD Card (Default Method)
   :name: loading-through-sd-card-default-method

Your SD card must be set up to a bootable format. Refer to the
`Processor SDK RTOS Boot </index.php/Processor_SDK_RTOS_Boot>`__ page
for information on how the SD card is handled.

You will need to compile the diagnostic applications for your BOARD,
created their respective SD card loadable files, and copied them onto an
SD card. You will also need the SBL (renamed to "MLO") on the SD card.
To do so:

#. cd <PDK>/packages/ti/board/diag
#. make <BOARD>_sd
#. copy all the content under <PDK>/packages/ti/board/bin/<BOARD>/sd to
   your SD card
#. copy the MLO to your SD card (default location at
   <PDK>/packages/ti/boot/sbl/binary/<BOARD>/mmcsd
#. insert your SD card into your board and power on your board
#. open Terminal emulator program eg: Teraterm to connect to the board's
   UART console
#. press the "Hard Reset" button on your board. (This is to force
   re-booting, and not absolutely necessary. Because Terminal emulator
   program is opened after boot is powered on, you would've missed the
   initial printout messages. This step is for demonstration and
   confidence checking that the board has booted correctly)

You should see the following screen:

.. Image:: ../images/Diag-screen1.jpg

The framework diagnostic application should be loaded through SBL, and
gives you the options:

-  help - prints the command menu and descriptions of the commands
-  run - run a diagnostic application found on the SD card
-  status - current status of the framework run

Below is an example of running a diagnostic application:

.. Image:: ../images/Diag-screen2.jpg

Result of return from above run:

.. Image:: ../images/Diag-screen3.png

.. rubric:: Loading through SPI Flash
   :name: loading-through-spi-flash

This section describes creating the diagnostic test images for SPI flash
booting, programming and running them from SPI flash. Currently SPI boot
is supported only by iceAMIC110 platform.

You will need to compile the diagnostic applications for your BOARD,
create their respective SPI flash loadable files, and program them onto
SPI flash. To do so:

#. cd <PDK>/packages/ti/board/diag
#. make <BOARD>_spi
#. Start CCS and launch target configuration file for AMIC110 ICE board
#. Connect the target, load and run the SPI flash writer binary.
   Prebuilt SPI flash writer is available at **<AM335x
   PDK>\packages\ti\starterware\tools\flash_writer\spi_flash_writer_AM335X.out**
#. Choose option 1 to initiate image flashing
#. Enter the file name as SPI bootloader along with full path **(Ex:
   <AM335x
   PDK>\packages\ti\starterware\binary\bootloader\bin\am335x-evm\gcc\bootloader_boot_mcspi_a8host_release_ti.bin)**
#. Enter offset as 0
#. Wait until flashing completes successfully
#. Rerun the SPI flash writer binary and program diagnostic framework
   loader at offset 20000. Diagnostic framework loader binary will be
   available at **<AM335x
   PDK>\packages\ti\board\bin\iceAMIC110\spi\app**
#. Rerun the SPI flash writer binary and program diagnostic framework at
   offset 40000. Diagnostic framework binary will be available at
   **<AM335x PDK>\packages\ti\board\bin\iceAMIC110\spi\framework**

Sample CCS output of SPI flash writer is shown below:

.. Image:: ../images/Spi_flash_writer_output.jpg

| 

#. open Terminal emulator program eg: Teraterm to connect to the board's
   UART console
#. press the "Hard Reset" button on your board. (This is to force
   re-booting, and not absolutely necessary. Because Terminal emulator
   program is opened after boot is powered on, you would've missed the
   initial printout messages. This step is for demonstration and
   confidence checking that the board has booted correctly)

You should see the following screen:

.. Image:: ../images/Amic110_ice_spi_boot_diag1.jpg

| 
| The framework diagnostic application should be loaded through SBL, and
  gives you the options:

-  help - prints the command menu and descriptions of the commands
-  run - run a diagnostic application found on the SD card
-  status - current status of the framework run

Below is an example of running a diagnostic application:

.. Image:: ../images/Amic110_ice_spi_boot_diag2.jpg

| 
| Result of return from above run:

.. Image:: ../images/Amic110_ice_spi_boot_diag3.jpg

| 

.. rubric:: Running or debugging on CCS
   :name: running-or-debugging-on-ccs

To debug your application, CCS can give you access to the chip's memory
and register values. You can follow the below steps to load and run an
application in CCS. If you have a SD card loadable image, and is able to
load your application, you can connect to the A15 core in CCS and load
symbols without having to load and run the entire application. After
running "make all" or "make $BOARD", the output files should be
generated under <PDK>/packages/ti/board/bin/ directory. You will have to
navigate down to the $BOARD you're building (eg. idkAM572x, evmAM572x,
etc.) and the $TARGET core you're building for (eg. armv7).

**For the existing diagnostic applications, you may need to define
PDK_RAW_BOOT before compiling**. This is done by adding the line
"#define PDK_RAW_BOOT" to an individual application source file or to
<PDK>/packages/ti/board/src/<BOARD>/include/board_cfg.h to apply for all
applications. This is used because the default diagnostic loading method
is through SD card, and the pinmux is done already. Adding this option
only forces the diagnostic applications to do pinmuxing within the
application itself (and not depend it being done).

To run on CCS:

#. Connect USB cable to the board's JTAG
#. Connect the UART serial cable. For the IDK boards, the UART console
   is the same as the usb JTAG connector, so no additional cable is
   necessary.
#. Plug in power cord to your board
#. Press the power button on the board to turn the board on
#. Setup and run CCSv6.1 (or higher). Follow the `Processor SDK RTOS
   Getting Started
   Guide </index.php/Processor_SDK_RTOS_Getting_Started_Guide>`__ on how
   to setup your CCS to connect to the board
#. Launch target configuration for the board
#. Connect to the core that you built your application for. For example:
   for idkAM572x armv7 projects, click on the Cortex A-15 MPU0 core and
   press the connect button
#. Load the program by pressing the load button and navigate the
   explorer to the .out file that you want to load
#. Press the Run button to run the program
#. Check UART console to see if anything is printed out. \**If nothing
   is printed out, pause the core and see where the program counter is
   at. If it is at 0x3808c (or near it), try reloading the program and
   running again.

Note: On omapl13x platforms diagnostic tests can only be run from CCS as
SBL support is not available at this point. Diagnostics are built for
both DSP (C674x) and ARM (arm9) cores on omapl13x platform.

.. rubric:: Running on a different ARM core
   :name: running-on-a-different-arm-core

The diagnostic baremetal applications are typically targeted for Core 0
of an ARM corepac. It is possible to load and run it on one of the
subcores in CCS. To do so, please consider the following:

#. Enable Cache - setup typically only enables cache for the main ARM
   core. You may have to explicitly enable the data and instruction
   cache. See relevant cache functions under pdk/packages/ti/csl/arch.
#. [For AM57x boards] Set OPP to high - SBL would set OPP to high for
   Core 0, but may not do it for the subcores. You can do so by using
   the GEL file. After connecting to the core, run the function under
   Scripts -> AM572x PRCM CLOCK configuration ->
   AM572x_PRCM_Clock_Config_OPPHIGH (similarly named for AM571x).

.. rubric:: Diagnostic Applications
   :name: diagnostic-applications

+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| N | D | G | I | I | E | I | E | S | B | I | E | S | I | E | I |
| a | e | P | D | D | V | C | V | K | B | C | V | K | D | V | C |
| m | s | A | K | K | M | E | M | A | B | E | M | A | K | M | E |
| e | c | M | A | A | K | K | A | M | A | v | A | M | A | O | A |
|   | r | 5 | M | M | 2 | 2 | M | 3 | M | 2 | M | 4 | M | M | M |
|   | i | 7 | 5 | 5 | G | G | 3 | 3 | 3 | A | 4 | 3 | 4 | A | I |
|   | p | 2 | 7 | 7 |   |   | 3 | 5 | 3 | M | 3 | 7 | 3 | P | C |
|   | t | x | 2 | 1 |   |   | 5 | x | 5 | 3 | 7 | x | 7 | L | 1 |
|   | i |   | x | x |   |   | x |   | x | 3 | x |   | x | 1 | 1 |
|   | o |   | / |   |   |   |   |   |   | 5 |   |   |   | 3 | 0 |
|   | n |   | A |   |   |   |   |   |   | x |   |   |   | 7 |   |
|   |   |   | M |   |   |   |   |   |   |   |   |   |   |   |   |
|   |   |   | 5 |   |   |   |   |   |   |   |   |   |   |   |   |
|   |   |   | 7 |   |   |   |   |   |   |   |   |   |   |   |   |
|   |   |   | 4 |   |   |   |   |   |   |   |   |   |   |   |   |
|   |   |   | x |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| a | T |   |   |   |   |   | x | x |   |   | x | x |   |   |   |
| c | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| c | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | X |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | , |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | Y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | Z |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | x |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| a | T |   |   |   |   |   | x | x |   |   | x | x |   |   |   |
| d | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| c | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | A |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | q |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | O |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| a | T |   |   |   |   |   | x |   |   |   | x |   |   |   |   |
| m | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| b | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| n | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| h | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| s | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| n | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| s | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| b | W |   |   |   |   |   | x |   |   |   | x |   |   |   |   |
| u | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| z | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| z | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | G |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | O |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | z |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | z |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | R |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | q |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| c | P |   |   |   |   | x |   |   |   |   |   |   |   |   |   |
| l | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| c | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| k | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| n | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | 2 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| c | R |   |   |   |   | x |   |   |   |   |   |   |   |   |   |
| u | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| n | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| n | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | 2 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| d | D |   | x | x | x |   |   |   |   |   |   |   |   |   |   |
| c | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| n | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | A |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | N |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| e | R | x | x | x | x | x | x | x | x | x | x | x | x |   | x |
| e | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | E |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | E |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | R |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | O |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | M |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | ' |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | 2 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | E |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | E |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | R |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | O |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | M |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| e | S |   |   |   |   | x |   |   |   |   |   |   |   |   |   |
| m | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| c | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | H |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | Y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | M |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | A |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| e | W | x | x | x | x |   |   |   |   |   |   |   |   |   |   |
| m | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| c | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | M |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | M |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| f | T | x | x | x | x | x | x | x | x | x | x | x | x |   | x |
| r | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| w | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| k | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | T |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | S |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | B |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | L |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | S |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| g | S |   | x | x |   |   |   |   |   |   |   |   |   |   |   |
| m | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| c | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | , |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | x |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| h | W |   | x | x |   |   |   |   |   |   | x |   |   |   |   |
| a | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| c | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| s | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | G |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | O |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | ( |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | ) |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | R |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | q |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| h | T |   |   |   | x |   |   |   |   |   |   |   |   |   |   |
| d | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | H |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | M |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| i | C |   | x | x |   |   |   |   |   |   |   |   |   |   |   |
| c | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| s | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| s | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| c | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | S |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | S |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | E |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | M |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | A |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| i | T |   |   |   |   | x |   |   |   |   |   |   |   |   |   |
| o | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| G | G |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | O |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | O |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | x |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| i | T |   |   |   |   | x |   |   |   |   |   |   |   |   |   |
| o | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| I | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 2 | 2 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| c | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | O |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | x |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| i | C |   |   |   |   | x |   |   |   |   |   |   |   |   |   |
| o | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| L | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | L |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | E |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | O |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | x |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| l | T |   |   |   | x |   |   |   |   |   |   |   |   |   |   |
| c | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | L |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| l | P |   | x | x |   |   |   |   |   |   |   |   |   |   |   |
| c | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| T | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| c | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| h | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| s | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| c | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| n | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | L |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | R |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | q |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | 9 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| l | C | x | x | x | x | x | x | x | x | x | x | x | x |   | x |
| e | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | G |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | O |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | L |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | E |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | R |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | q |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | L |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | E |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| l | C |   | x | x |   | x |   |   |   |   |   |   |   |   |   |
| e | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| I | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| n | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| s | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | 2 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | L |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | E |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | R |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | q |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | L |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | E |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| m | A |   | x | x |   |   |   |   |   |   |   |   | x |   | x |
| c | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| s | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | M |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | S |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | R |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | q |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | x |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| m | W | x | x | x | x | x | x | x | x | x | x | x | x |   | x |
| e | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | x |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | ( |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | R |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | ) |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | V |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | / |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | T |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | , |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | ~ |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | ( |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | ) |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | , |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| m | W | x | x | x |   |   | x | x | x | x | x | x | x |   |   |
| m | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| c | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| s | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | M |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | M |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | S |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| n | T |   |   |   | x |   |   |   |   |   |   |   |   |   |   |
| a | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| n | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | N |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | A |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | N |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| n | T |   |   |   | x |   |   |   |   |   |   |   |   |   |   |
| o | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| f | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| s | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| h | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | N |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | O |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | R |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| o | L |   |   |   |   | x |   |   |   |   |   |   |   |   |   |
| l | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| s | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | O |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| y | L |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | E |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| p | W | x | x | x |   |   | x | x | x | x | x | x |   |   |   |
| m | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| c | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | M |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | T |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | 2 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | M |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | T |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| q | T |   | x | x | x | x |   |   |   |   | x |   |   |   |   |
| s | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | Q |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | S |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | T |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| r | T |   |   |   |   | x |   |   |   |   |   |   |   |   |   |
| o | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| y | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| s | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| w | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| c | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| h | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | 1 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | 0 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| r | T |   |   |   |   |   | x | x | x | x | x | x | x |   |   |
| t | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| c | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | R |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | T |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| t | T | x |   |   | x |   | x |   |   |   | x |   |   |   |   |
| e | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | 2 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | T |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | 2 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| u | T |   |   |   | x |   |   |   |   |   |   |   |   |   |   |
| a | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 2 | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| s | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| b | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| u | D | x | x | x | x | x | x | x | x | x | x | x | x |   |   |
| a | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | U |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| r | A |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | R |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| v | T |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| 7 | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | R |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | q |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | v |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| m | O |   |   |   | x |   |   |   |   |   |   |   |   | x |   |
| c | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | - |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| s | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| C | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | x |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | A |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | E |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | V |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | M |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | T |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | , |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | 3 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | 2 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | S |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | L |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | L |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | L |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | N |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| m | M |   |   |   |   |   |   |   |   |   |   |   |   | x |   |
| c | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| s | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | - |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| C | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| C | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | x |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | A |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | k |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | T |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | , |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | 3 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | S |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | L |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | L |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | L |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | D |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | N |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+
| p | D | x |   |   | x |   | x |   |   |   |   |   | x |   |   |
| w | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| d | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| i | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| g | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| x | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| a | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| m | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| p | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| l | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| e | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| B | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| A | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| D | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| _ | W |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| < | M |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| C | C |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| O | S |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| R | L |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| E | F |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| > | L |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| . | A |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| o | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| u | I |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
| t | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | b |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | P |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | W |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | M |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | m |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | g |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | p |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | s |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | o |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | 1 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | K |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | H |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | z |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | w |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | h |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | i |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | f |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | r |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | u |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | t |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | y |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | c |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | l |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | e |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | - |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | 2 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | 5 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | , |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | 5 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | 0 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | a |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | n |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | d |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | 7 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | 5 |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | % |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
|   | . |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+---+

| Some diagnostic applications expect additional jumpers or hardware
  settings to complete. Refer to below section.

.. rubric:: Additional Jumper or Hardware Settings
   :name: additional-jumper-or-hardware-settings

.. rubric:: Current Monitor
   :name: current-monitor

For iceK2G, this test expects J16 and J17 to be connected with jumper
shunts. This enables the current monitors to be used.

.. rubric:: GMAC
   :name: gmac

For idkAM572x, idkAM571x, idkAM574x and evmAM572x, this test expects
loopback plugs to be used on both Ethernet ports. These loopback plugs
will loopback the TX lines back to the RX lines. The Ethernet ports are
the RJ-45 connectors labeled "Ethernet" on the board.

.. rubric:: ICSS EMAC
   :name: icss-emac

For idkAM572x, idkAM574x and idkAM571x, this test expects loopback plug
to be used on J6. These loopback plugs will loopback the TX lines back
to the RX lines. For iceK2G, this test expects loopback plugs to be used
on all four ICSS EMAC ports.

.. rubric:: LCD Touchscreen
   :name: lcd-touchscreen

For idkAM572x, idkAM574x and idkAM571x, this test expects the LCD module
to be connected. This requires the two ribbon cables (one for display,
one for the capacitive-touch IC) to be connected.

.. rubric:: McSPI
   :name: mcspi

For idkAM572x, idkAM574x and idkAM571x, this test expects pins to be
connected to the Industrial I/O header. The Industrial I/O header, J37,
has two columns in parallel, one of which is the McSPI input and the
other being VDD. Thus, connecting any row with a jumper will yield a '1'
read on that McSPI input. By connecting the first, second, third, and
forth row with jumpers would yield 0x1, 0x2, 0x4, and 0x8 being read
respectively.

.. rubric:: PWM
   :name: pwm

PWM output generated while running the diagnostic test can be verified
at below pins.

evmK2G - J12 pin 33

evmAM572x - P17 pin 5

idkAM437x - J16 pin 14

evmAM335x - J5 pin 13

.. raw:: html

