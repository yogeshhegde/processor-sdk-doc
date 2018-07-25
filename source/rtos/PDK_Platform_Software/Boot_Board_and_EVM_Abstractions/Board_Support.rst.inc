.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Board_Support

.. rubric::  Introduction
   :name: introduction

| Board library contains a set of general initialization and setup
  functions that are board-specific. This component includes libraries
  for boards supported in the Processor SDK release. Refer to the
  package content for the list of supported boards.Board component also
  includes diagnostic software. Refer to `Processor SDK RTOS
  DIAG <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_DIAG>`__ for additional details on
  available diagnostic examples.

.. rubric::  APIs
   :name: apis

The Board_init() API supports initialization of PLL, peripheral clocks,
external DDR memory, pinmux and IO Delay configurations. API Reference
for application:

::

   #. include <ti/board/board.h>

| 

Example API pseudo code for Board_init() is as follows:

::

   /* Setting up for pinmux and uart */
   Board_STATUS ret;
   Board_initCfg boardCfg;

   boardCfg = BOARD_INIT_MODULE_CLOCK \| BOARD_INIT_PINMUX_CONFIG \|
   BOARD_INIT_UART_STDIO;

   ret = Board_init(boardCfg);

| 

.. rubric::  LLD Dependencies
   :name: lld-dependencies

.. rubric::  I2C
   :name: i2c

Application need to configure **BOARD_INIT_MODULE_CLOCK** option to have
I2C operational. I2C is used to read EEPROM data. An I2C handle will be
opened in polling mode, and closed after the board ID data is retrieved
from EEPROM using Board_getIDInfo() API.

For DRA7xx EVMs, I2C is also used to configure various I/O expanders and
board muxes to enable PDK examples to function properly on the EVM. The
I2C handles are opened in polling mode and closed after the board mux
initialization has completed.

.. rubric::  UART
   :name: uart

Application need to configure Board_init() with the
**BOARD_INIT_UART_STDIO** option to use the UART stdio API.

After Board_init() completes, application can invoke UART stdio
functions such as UART_printf, UART_scanFmt, and etc.

.. rubric::  Application Integration for AM5x/DRA7xx
   :name: application-integration-for-am5xdra7xx

When configuring pinmux with IO Delay settings for **AM5x** and
**DRA7xx** boards, there is a hard restriction: the code/data/stack
during the IO Delay setup must be within local internal memory. Refer to
SOC TRM for additional information.

The board library specifies two sections for users to define for the
sole purpose of meeting this requirement. They are:
**BOARD_IO_DELAY_CODE** and **BOARD_IO_DELAY_DATA**. Below are examples
of how to specify these section into the local memory, OCMC_RAM1:

In baremetal case with a linker cmd file: 

::

   BOARD_IO_DELAY_CODE : {

      . = ALIGN(4);
      *(BOARD_IO_DELAY_CODE*)

   } > OCMC_RAM1

   BOARD_IO_DELAY_DATA : {

      . = ALIGN(4);
      *(BOARD_IO_DELAY_DATA*)

   } > OCMC_RAM1

| 

In a CCS RTSC project with .cfg file: 

::

   Program.sectMap["BOARD_IO_DELAY_DATA"] = "OCMC_RAM1";
   Program.sectMap["BOARD_IO_DELAY_CODE"] = "OCMC_RAM1";

| 

.. rubric::  Considerations for DRA7xx devices
   :name: considerations-for-dra7xx-devices

When integrating the board library in applcations on DRA7xx, these
code/data sections will likely overlap and conflict with the code/data
sections used by the Secondary Boot Loader (SBL) as both modules will
assume full access to OCMC_RAM1. Also, as the SBL performs identical
configuration using the common pad config data structures, the pinmux
request made by an application will be redundant. Therefore, it is
advised that the pinmux API be used only when loading the application
via CCS. When loading via SBL, there are three options available for
handling this conflict:

#. Place the BOARD_IO_DELAY_DATA/BOARD_IO_DELAY_CODE sections to another
   internal memory location. The Board library will check to see if the
   board code/data/stack are located in internal memory before executing
   the sequence. If another internal memory section is available for
   placement (e.g. L2SRAM, OCMC_RAM2), then it is acceptable to place
   the sections in these locations. The Board init sequence will proceed
   as expected.
#. Place the BOARD_IO_DELAY_DATA/BOARD_IO_DELAY_CODE sections into
   external memory. The pinmux subroutine in the Board library checks
   for code/data/stack placement and will fail if it detects that they
   reside in DDR and return before performing the configuration. The
   failure will not affect any other Board init requests as other flags
   are treated orthogonally.
#. Remove the BOARD_IO_DELAY_DATA/BOARD_IO_DELAY_CODE sections. This is
   the preferred solution as it removes redundant code from executing
   and will optimize code/data size and load speed. In order to remove
   these sections, two modifications are required:

   -  Place BOARD_IO_DELAY_DATA/BOARD_IO_DELAY_CODE input sections into
      an output Dummy Section (DSECT). DSECTs are a `Special Linker
      Section
      Type <http://processors.wiki.ti.com/index.php/Linker_Special_Section_Types#DSECT_Sections>`__
      which are relocated for linker resolution but otherwise do not
      allocate space to a memory map, place sections in the output file,
      or ever get loaded to the target. In order to place these sections
      into DSECTS, modify the placement as follows:

Replace:
::

   Program.sectMap["BOARD_IO_DELAY_DATA"] =
   "OCMC_RAM1"; Program.sectMap["BOARD_IO_DELAY_CODE"] = "OCMC_RAM1";
| 

With:

:: 

   Program.sectMap["BOARD_IO_DELAY_DATA"] = new
   Program.SectionSpec(); Program.sectMap["BOARD_IO_DELAY_CODE"] = new
   Program.SectionSpec(); Program.sectMap["BOARD_IO_DELAY_DATA"].type =
   "DSECT"; Program.sectMap["BOARD_IO_DELAY_CODE"].type = "DSECT";

| 

-  Remove the BOARD_INIT_PINMUX_CONFIG flag from the call to Board_init.
   Since the BOARD_IO_DELAY_DATA/BOARD_IO_DELAY_CODE sections no longer
   actually exist, we must instruct the application that it is no longer
   safe to call the routines and access the data. Otherwise, the CPU
   will branch to and access undefined memory and cause various
   exceptions

.. rubric::  Custom Board Addition
   :name: custom-board-addition

| Creating a custom board library has its merits whether you are
  creating it for custom silicon or for debugging/enhancements without
  losing your default board code. Below section include details needed
  for creation of additional board support.

.. rubric::  Pinmux and IO Delay
   :name: pinmux-and-io-delay

| When the **BOARD_INIT_PINMUX_CONFIG** option is specified, the
  Board_init() API configures the pinmux for the board. If applicable,
  it will also configure IO delay values for those device pads, which
  ensures correct IO timings are met along with the pinmux settings.
  Refer SOC TRM for additional details.

| The pinmux data to be configured is generated by the TI pinmux tool.
  Refer to `TI PinMux
  Tool <http://processors.wiki.ti.com/index.php/TI_PinMux_Tool>`__ for
  more information.
| For DRA7xx device, pinmux data is generated by the TI Pad Config Tool
  (PCT). Please contact TI for more assistance in obtaining this tool.
  Otherwise, values can be found through the device Data Manual (DM).

.. raw:: html

   <div
   style="margin: 5px 25px; padding: 2px 10px; background-color: #ecffff; border-top: 1px solid #3399ff; border-bottom: 1px solid #3399ff;">

**NOTE**

Pinmux is needed for AM3/AM4/AM5/DRA7/K2G devices. Pinmux is not needed
for C66x or K2H/K2E/K2L devices, and the BOARD_INIT_PINMUX_CONFIG option
is ignored when called in a C66x or K2H/K2E/K2L board library.

.. raw:: html

   </div>

.. rubric::  Custom Board Library
   :name: custom-board-library

#. Set up your build environment according to the `Building the RTOS
   SDK <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Building_The_SDK>`__ page.
#. Create your own folder under the src directory. The name of this
   folder will be your board name (will be referred to as $BOARD). Put
   your source files in this src/$BOARD folder. Updated sources can also
   include initialization sequence for additional devices specific to board.
#. Pinmux Update (see above note for applicable devices):

   -  Use the `TI PinMux
      Tool <http://processors.wiki.ti.com/index.php/TI_PinMux_Tool>`__
      to generate the new pinmux files. Refer the PinMux tool
      documentation on how to select pinmux for all the device pads and
      generate the pinmux data files.
   -  The four generated files are:

      -  boardPadDelay.h: Includes the prototypes of all structures and
         functions used by pinmux functions
      -  boardPadDelayInit.c: Includes the pinmux pad config data for
         all device pads along with values used to compute
         Manual/Virtual mode values.This data is used to configure
         pinmux during board initialization.
      -  boardPadDelayTune.h: This file includes the compile time macros
         used to select the Timing modes to be configured for modules
         during board Initialization.
      -  boardPadDelayDevice.c: This file includes the pinmuxdata for
         runtime pinmux configuration of the MMC module.
     
   - Some platforms not requiring IO delay configurations will have two files
     <Platform Name>pinmux.h and <Platform Name>_pinmux_data.c files generated 
     by the pinmux tool

   -  Copy the pinmux tool generated files to your custom board library
      implementation folder.
   -  **Note:** It is recommended to use the latest available PinMux Tool. 
      For PinMux Tool prior to version v4.0.1482, you will have to edit 
      **boardPadDelayTune.h** to select appropriate IO timing modes by 
      uncommenting the build macros.
      
#. SOC Clock Settings Update:
   The core clocks and module clocks used on the custom board library may 
   vary based on the power requirements and external components used on the 
   boards. TI provides `Clock Tree Tools <http://www.ti.com/tool/CLOCKTREETOOL>`__ 
   to simulate the device clocks. GEL file can be used to verify the settings
   in CCS before modifying the source in the board library.

#. SOC DDR Configuration Update:
   The board library has the correct DDR initialization sequence to initialize 
   the DDR memory on your board. You may need to make changes to the AC timings, 
   hardware leveling, and DDR PHY configuration, some or all of which may be 
   different than the TI supported platforms. GEL file can be used to verify 
   the settings in CCS before modifying the source in the board library.

#. IO Instance and Configuration update to Match Use Case:
   If your custom board uses an IO instance different from the TI-supported
   board, the instance needs to be modified in the Pin Mux setup as well
   as in the board_cfg.h file in
   pdk_xx_Xx_xx_xx/packages/ti/board/src/<customBoardName>/

#. Updating the Files Corresponding to External Board Components:
   The custom board may have external components (flash devices, Ethernet
   PHY, etc.) that are different from the components populated on the
   TI-supported EVM. These components and their support files need to be
   added to the
   pdk_xx_Xx_xx_xx/packages/ti/board/src/<customBoardName>/device path
   and linked as part of the board library build.

#. PLL Settings Update:
   The SOC board library in the PDK configures the SOC PLL and module clock
   settings to the nominal settings required to be used with the TI
   evaluation platform. If you want to use different clock settings due to
   power consideration, or if you are using a variant of the device that
   needs to be clocked differently, you can enter the PLL and clock
   settings in the board library. All of the PLL and module clock settings
   are consolidated in the following files:

   -  <Board>.c: Contains calls related to all board-level initialization.
      <Board> refers to the evaluation platform (For example, evmam335x)
   -  <EVM>_pll.c: Defines the Board_PLLInit() function that configures the
      dividers and multipliers for the clock tree.
   -  <EVM>_clock.c: Defines clock dividers, scalars, and multipliers for
      individual board modules initialized using the board library.

#. Create build makefile infrastructure for new board under
   <ti/board/build>. Please refer existing board makefiles for
   reference.
#. Update top level makefile <ti/board/makefile> for additional support
   of new boards.

Adding custom board to the PDK directory structure and build setup is
described in the article
`Adding_Custom_Board_Library_Target_to_Processor_SDK_RTOS_makefiles <http://processors.wiki.ti.com/index.php/Adding_Custom_Board_Library_Target_to_Processor_SDK_RTOS_makefiles>`__

.. note::
   TI evaluation platforms for Sitara Processors usually have board
   information stored in an EEPROM which checks for revision number and
   board name which is used to configure the board. When creating a custom
   platform if you don`t intend to use an EEPROM then we recommend removing
   code corresponding to Board_getIDInfo in your board library
| 

.. raw:: html

