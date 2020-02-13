.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Board_Support

Introduction
-------------

Board library contains a set of general initialization and setup
functions that are board-specific. This component includes libraries
for boards supported in the Processor SDK release. Refer to the
package content for the list of supported boards.Board component also
includes diagnostic software. Refer to `Processor SDK RTOS
DIAG <index_board.html#diagnostics>`__ for additional details on
available diagnostic examples.

Board APIs
^^^^^^^^^^^

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

LLD Dependencies
^^^^^^^^^^^^^^^^^

I2C
""""

Application need to configure **BOARD_INIT_MODULE_CLOCK** option to have
I2C operational. I2C is used to read EEPROM data. An I2C handle will be
opened in polling mode, and closed after the board ID data is retrieved
from EEPROM using Board_getIDInfo() API.

For DRA7xx EVMs, I2C is also used to configure various I/O expanders and
board muxes to enable PDK examples to function properly on the EVM. The
I2C handles are opened in polling mode and closed after the board mux
initialization has completed.

UART
"""""

Application need to configure Board_init() with the
**BOARD_INIT_UART_STDIO** option to use the UART stdio API.

After Board_init() completes, application can invoke UART stdio
functions such as UART_printf, UART_scanFmt, and etc.

SCICLIENT
""""""""""

AM65xx/J7xx Board library uses sciclient APIs for configuring the PLL clocks.


Application Integration for AM5x/DRA7xx
----------------------------------------

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

Considerations for DRA7xx devices
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

When integrating the board library in applications on DRA7xx, these
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

Custom Board Addition
----------------------
This section provides the guidelines for creating a custom board library.

Below image shows the recommended sequence to be followed while porting processor SDK to custom board.

.. Image:: ../images/prsdk_rtos_custom_board_porting_steps.png

Board Configurations
^^^^^^^^^^^^^^^^^^^^^^
Board library supports different SoC and HW board specific configuration functions. 
Below table shows configurations supported by board library across different platforms.

+-------------------------------------+-------------------------+-------------------------------------+-----------+-----------+-----------+-----------+-----------+---------+---------------+
|         Board Configuration         |    Description          |            References               |   J721E   |  AM65xx   |  AM57xx   |  AM437x   |  AM335x   |   K2G   |  K2-E/H/K/L   |
|                                     |                         |                                     |           |           |           |           |           |         |               |
+=====================================+=========================+=====================================+===========+===========+===========+===========+===========+=========+===============+
|                                     | Configures pinmux for   |   `Pinmux Tool`_                    |           |           |           |           |           |         |               |
|    Pinmux                           | interfaces on the HW    |                                     |     x     |     x     |     x     |     x     |     x     |    x    |               |
|                                     | board.                  |                                     |           |           |           |           |           |         |               |
|                                     |                         |                                     |           |           |           |           |           |         |               |
+-------------------------------------+-------------------------+-------------------------------------+-----------+-----------+-----------+-----------+-----------+---------+---------------+
|                                     | Enables power domains   |                                     |           |           |           |           |           |         |               |     
|    SoC Clock Settings               | and clocks for SoC      |   `Clock Tree Tool`_                |     x     |     x     |     x     |     x     |     x     |    x    |       x       |
|                                     | peripherals             |                                     |           |           |           |           |           |         |               |
|                                     |                         |                                     |           |           |           |           |           |         |               |
+-------------------------------------+-------------------------+-------------------------------------+-----------+-----------+-----------+-----------+-----------+---------+---------------+
|                                     | Configures DDR/EMIF     |                                     |           |           |           |           |           |         |               |
|    DDR Configuration                | controller and DDR      |   `EMIF Tools Appnote`_             |     x     |     x     |     x     |           |           |    x    |       x       |
|                                     | timing parameters.      |                                     |           |           |           |           |           |         |               |
|                                     |                         |                                     |           |           |           |           |           |         |               |
+-------------------------------------+-------------------------+-------------------------------------+-----------+-----------+-----------+-----------+-----------+---------+---------------+
|                                     | Configures PLL modules  |                                     |           |           |           |           |           |         |               |
|    PLL Configuration                | to generate various     |    NA                               |     x     |     x     |     x     |           |           |    x    |       x       |
|                                     | clocks used by the SoC. |                                     |           |           |           |           |           |         |               |
|                                     |                         |                                     |           |           |           |           |           |         |               |
+-------------------------------------+-------------------------+-------------------------------------+-----------+-----------+-----------+-----------+-----------+---------+---------------+
|                                     | Configures Ethernet     |                                     |           |           |           |           |           |         |               |
|    Ethernet Configuration           | PHYs on the board.      |    NA                               |     x     |     x     |     x     |     x     |     x     |    x    |               |
|                                     |                         |                                     |           |           |           |           |           |         |               |
+-------------------------------------+-------------------------+-------------------------------------+-----------+-----------+-----------+-----------+-----------+---------+---------------+
|                                     | Defines IO instances    |                                     |           |           |           |           |           |         |               |
|    IO Instances                     | for HW interfaces.      |    NA                               |     x     |     x     |     x     |     x     |     x     |    x    |       x       |
|                                     |                         |                                     |           |           |           |           |           |         |               |
+-------------------------------------+-------------------------+-------------------------------------+-----------+-----------+-----------+-----------+-----------+---------+---------------+
|                                     | EEPROM board ID for     |                                     |           |           |           |           |           |         |               |
|    Board Detection                  | board detection.        |    NA                               |     x     |     x     |     x     |     x     |     x     |    x    |               |
|                                     |                         |                                     |           |           |           |           |           |         |               |
+-------------------------------------+-------------------------+-------------------------------------+-----------+-----------+-----------+-----------+-----------+---------+---------------+
|                                     | Provides Common APIs for|                                     |           |           |           |           |           |         |               |
|    Board Flash APIs                 | accessing flash devices.|    NA                               |     x     |     x     |           |     x     |     x     |    x    |       x       |
|                                     |                         |                                     |           |           |           |           |           |         |               |
+-------------------------------------+-------------------------+-------------------------------------+-----------+-----------+-----------+-----------+-----------+---------+---------------+
|                                     | Configures SerDes       |                                     |           |           |           |           |           |         |               |
|    SerDes Configuration             | interface internal      |    NA                               |     x     |     x     |           |           |           |         |               |
|                                     | muxing and basic setup. |                                     |           |           |           |           |           |         |               |
|                                     |                         |                                     |           |           |           |           |           |         |               |
+-------------------------------------+-------------------------+-------------------------------------+-----------+-----------+-----------+-----------+-----------+---------+---------------+

.. _Pinmux Tool: http://processors.wiki.ti.com/index.php/TI_PinMux_Tool
.. _Clock Tree Tool: http://www.ti.com/tool/CLOCKTREETOOL
.. _EMIF Tools Appnote: FAQ.html#useful-ddr-configuration-resources


Adding custom board library can follow two approaches as mentioned below

|  **Approach 1**: Update files in existing TI board library and modify for custom board.
|  This approach will be less time consuming since the board library setup is already existing
   in the processor SDK, but need to maintain TI board library separately for reference.
|
|  **Approach 2**: Add custom board to PDK build
|  This approach involves one time effort of setting up the custom board library but makes it easy
   to switch between custom board library and TI reference board library. In this approach during migration 
   to updated processor SDK, review and selective updates from existing TI board reference source will need to be considered.
|
|  
   Refer the section `Board Library Creation with Custom Name <index_board.html#creating-board-library-with-custom-name>`_ 
   for additional steps involved in creating board library with Approach 2.
|

Creating Board Configurations
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Before updating the board library with configurations for custom board, it is recommended to use
GEL file and CCS for validating the configurations. 
Follow the steps mentioned below

- Update the SoC clock configurations in the GEL file.
  TI provides `Clock Tree Tool <http://www.ti.com/tool/CLOCKTREETOOL>`_ to simulate the device clocks.
- Update the PLL clock configurations in GEL file if custom board uses a different input clock than the eval platform and/or needs different clock outputs.
- Update DDR PHY and timing configurations for custom board. 
  Refer the guidelines described in `Application Report on EMIF Tools <FAQ.html#useful-ddr-configuration-resources>`_
- After GEL file update is complete, connect to custom board using JTAG, run the GEL script to apply the modified configurations and verify the configured values.
  Load and run simple hello world example out of SoC internal memory and DDR memory.


Updating Board Configurations
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Steps for updating the board library configurations for a custom board is described in this section.
Updating some of the configurations may need additional steps based on the platform.
Refer `Platform Specific Configuration <index_board.html#platform-specific-configurations>`_ section for more details.

Pinmux 
"""""""
When the **BOARD_INIT_PINMUX_CONFIG** option is specified, the
Board_init() API configures the pinmux for the board. If applicable,
it will also configure IO delay values for those device pads, which
ensures correct IO timings are met along with the pinmux settings.
Refer SOC TRM for additional details.

The pinmux data to be configured is generated by the TI pinmux tool.
Refer to `TI PinMux
Tool <http://processors.wiki.ti.com/index.php/TI_PinMux_Tool>`__ for
more information.

Once the pinmux selection is done, Copy the pinmux tool generated files to your custom board library
implementation folder.

Refer `Platform Specific Configuration <index_board.html#platform-specific-configurations>`_ section for more details on the files generated
by pinmux tool for different platforms.

SoC Clock Settings
"""""""""""""""""""""
The core clocks and module clocks used on the custom board library may 
vary based on the power requirements and external components used on the 
boards.

<Board>_clock.c: Defines functions and structures for configuring the clock and power modules. 
Update this file based on the data from clock tree tool and GEL file validation.

DDR Configuration
"""""""""""""""""""""
The board library has the correct DDR initialization sequence to initialize 
the DDR memory on your board. You may need to make changes to the AC timings, 
hardware leveling, and DDR PHY configuration, some or all of which may be 
different than the TI supported platforms. GEL file can be used to verify 
the settings in CCS before modifying the source in the board library.

<Board>_ddr.c: Defines functions and structures for configuring the DDR module. 
Update this file based on the DDR timing parameters specific to custom board.
   
PLL Configuration
""""""""""""""""""""
The SOC board library in the PDK configures the SOC PLL and module clock
settings to the nominal settings required to be used with the TI
evaluation platform. If you want to use different clock settings due to
power consideration, or if you are using a variant of the device that
needs to be clocked differently, you can enter the PLL and clock
settings in the board library. All of the PLL and module clock settings
are consolidated in the following files:

- <Board>.c: Contains calls related to all board-level initialization.
  <Board> refers to the evaluation platform (For example, evmam335x)
- <Board>_pll.c: Defines the Board_PLLInit() function that configures the
  dividers and multipliers for the clock tree.

Ethernet Configuration
"""""""""""""""""""""""
The custom board may have external components (flash devices, Ethernet
PHY, etc.) that are different from the components populated on the
TI-supported EVM. These components and their support files need to be
added to the
pdk_xx_xx_xx_xx/packages/ti/board/src/<customBoardName>/device path
and linked as part of the board library build.

IO Instances
"""""""""""""
If your custom board uses an IO instance different from the TI-supported
board, the instance needs to be modified in the Pin Mux setup as well
as in the board_cfg.h file in
pdk_xx_xx_xx_xx/packages/ti/board/src/<customBoardName>/include

Board Detection
'''''''''''''''''
 - TI defined board detect mechanism using structure stored in I2C EEPROM
 - Board Lib APIs read and write Board ID to EEPROM on I2C address 0x50
 - Application boards, if available, will have their own EEPROM with board information
 - Structure typically defines:
 
::

    Board ID (IDK vs GP EVM vs custom)
    Revision number (board revision to address board level issues)
    Serial Number (internal tracking)
    MAC ID  (Custom MAC ID use)
| 
.. note::
   Board detection is TI defined mechanism to detect evaluation platform details. 
   This needs to be removed/replicated from board based on customer board implementation.
   In case board detect mechanism is not used in custom board, check for the Board_getIDInfo() API calls 
   and make necessary changes in the code to avoid dependencies on board detect mechanism.

Board Flash APIs
'''''''''''''''''
Board library includes a dedicated flash library to abstract the HW flash interface access
using a standard set of APIs. In case custom board uses flash devices that are different
from eval platform, update to board flash APIs is required. 
Check the board flash library available at <PDK_INSTALL_PATH>/packages/ti/board/src/flash and 
make changes required for custom board as needed.

   
Platform Specific Configurations
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

J721E
"""""""

Board File Names
'''''''''''''''''
Board library file names for J721E are different when compared with other platforms in processor SDK.
This is to facilitate the easy migration of board library to custom platforms.
Read the file name <Board>.c as board_init.c and <Board>_xxx.c/h as board_xxx.c/h in all the 
references in above sections.

Pinmux 
'''''''
Follow below steps to update pinmux configuration for custom board on J721E platform.
Pinmux project files provided under j721e_evm board folder can be used as reference for pinmux configuration.

* Download the pinmux files <Platform Name>_pinmux.h and <Platform Name>_pinmux_data.c generated by pinmux tool 
  and copy them to custom board folder.
* Open 'packages/ti/board/src/j721e_evm/<Platform Name>_pinmux.h' and make below modifications.

   * Change #include "pinmux.h" to #include <ti/board/src/j721e_evm/include/pinmux.h>
   * Change #include "csl_types.h" to #include <ti/csl/csl_types.h>
     * Modify 'j721e_evm' in above step if a different name is used for custom board.

.. tip::

    <Platform Name>_pinmux.h file contains the basic pin definition macros which will not change with every 
    pin configuration change. This file generation and above step is one time configuration
    for a given pinmux tool version.

* Modify the Board_pinmuxConfig() function in 'packages/ti/board/src/j721e_evm/board_pinmux.c' file to remove 
  pinmux configurations specific to EVM addon boards.
  Look for the comment "Pinmux for Application cards" in the function Board_pinmuxConfig().
  All the code after this comment till end of the function and 'i2cPinmux' variable can be removed.
  Board_pinmuxConfig function shall look as below after the update

::
    
    Board_STATUS Board_pinmuxConfig (void)
    {
        Board_STATUS status = BOARD_SOK;

        /* Pinmux for baseboard */
        Board_pinmuxUpdate(gJ721E_MainPinmuxData,
                           BOARD_SOC_DOMAIN_MAIN);
        Board_pinmuxUpdate(gJ721E_WkupPinmuxData,
                           BOARD_SOC_DOMAIN_WKUP);

        return status;
    }
|

* Rebuild the board library with new pinmux configurations

Follow additional steps (optional) below to clean-up the TI EVM addon board specific files.

* Remove below files from SRCS_COMMON build configuration in 'packages/ti/board/src/j721e_evm/src_files_j721e_evm.mk' 
  and remove the files from the board folder 'packages/ti/board/src/j721e_evm'

   * J721E_pinmux_data_gesi.c
   * J721E_pinmux_data_gesi_cpsw9g.c
   * J721E_pinmux_data_info.c

SerDes Configuration
'''''''''''''''''''''
J721E board library includes SerDes module which configures the SerDes interface internal pinmux
to route PCIe, USB and SGMII to different interfaces on the board. If custom board uses
similar design, SerDes configurations (board_serdes_cfg.c) can be reused.
Otherwise this configuration can be ignored.

AM65xx
"""""""

Pinmux 
'''''''
Follow below steps to update pinmux configuration for custom board on AM65xx platforms.

 - Download the pinmux files <Platform Name>_pinmux.h and <Platform Name>_pinmux_data.c generated by pinmux tool
 - Copy the files to custom board folder and rename them to match with board name if needed.
 - Rebuild the board library with new pinmux configurations

SerDes Configuration
'''''''''''''''''''''
AM65xx board library includes SerDes module which configures the SerDes interface internal pinmux
to route PCIe, USB and SGMII interfaces to different personality cards. If custom board uses
similar design, SerDes configurations can be reused. Otherwise this configuration can be ignored.


AM57xx
"""""""
Pinmux 
'''''''
Pinmux tool output for AM57xx platform includes IO delay information.
Below are the files generated by pinmux tool:
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

Copy the above listed files generated by pinmux tool to custom board folder and 
rebuild the board library with updated pinmux configurations.

AM335x/AM437x
"""""""""""""""
Pinmux 
'''''''
Follow below steps to update pinmux configuration for custom board on AM335x/AM437x platforms.

 - Download the pinmux files <Platform Name>pinmux.h and <Platform Name>_pinmux_data.c generated by pinmux tool
 - At the bottom of <Platform Name>pinmux.h change extern pinmuxBoardCfg_t g<Platform Name>PinmuxData[]; to extern pinmuxBoardCfg_t g<Custom Board Name>PinmuxData[];
 - Change <Platform Name>_pinmux_data.c to <Platform Name>_<Custom Board Name>pinmux_data.c
 - Change g<Platform Name>PinmuxData to g<Custom Board Name>PinmuxData at the end of the file in <Platform Name>_<Custom Board Name>pinmux_data.c 
 - The last step is to invoke the PinMuxModuleConfig in the file <BoardName>_pinmux.c that is found at <PDK_INSTALL_PATH>\packages\ti\board\src\<BoardName>. 
   For Example to add three instances of UART in the pinmux setup, users can add :

::

    /* UART */
     status = PINMUXModuleConfig(CHIPDB_MOD_ID_UART, 0U, NULL);
     status = PINMUXModuleConfig(CHIPDB_MOD_ID_UART, 1U, NULL);
     status = PINMUXModuleConfig(CHIPDB_MOD_ID_UART, 4U, NULL);
| 
 - Rebuild the board library with new pinmux configurations
|

K2G
""""
Pinmux 
'''''''
Follow below steps to update pinmux configuration for custom board on K2G platforms.
 - Download the pinmux files <Platform Name>pinmux.h and <Platform Name>_pinmux_data.c generated by pinmux tool
 - Copy the files to custom board folder and rename them to match with board name if needed.
 - Rebuild the board library with new pinmux configurations


Custom Board Validation
^^^^^^^^^^^^^^^^^^^^^^^^^^
Validate the basic functionality of custom board using hardware diagnostics before bringing-up 
RTOS applications or Linux. Hardware diagnostics help verify the functionality of on-board 
peripherals and external interfaces of each board. 

Refer `Board Diagnostics <index_board.html#diagnostics>`_ section for more details on the 
diagnostic tests supported as part of processor SDK.
 
Below are the recommended diagnostic tests which can be validated on custom board

 - External memory (DDR): DDR timing and leveling setting can be checked out using mem_test
 - Debug UART: Debug UART pin functionality
 - Boot Media: Validate functionality of SD/MMC, OSPIor any other boot interfaces
 - Board ID/EEPROM test: Recommend checking out/writing ID on personality EEPROM. 
   This also checkout I2C pin functionality
 - Ethernet PHY: Ethernet diagnostics tests read PHY configuration over MDIO and 
   check for Link up status. Good first step before bringing up any network stack


Creating Board Library with Custom Name
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Instructions to add custom Board to the PDK build
""""""""""""""""""""""""""""""""""""""""""""""""""
Follow below steps for creating board library with custom name. 
AM572x platform is used as reference in the examples wherever needed.

**Step 1: Creating new directory for custom board library**

In <PDK_INSTALL_PATH>/packages/ti/board/src, 
Create new directory myCustomBoard and copy files from existing board
library package which closely matches your custom board design.

**Step 2: Updating names and makefile inside the customBoard package**

In <PDK_INSTALL_PATH>/packages/ti/board/src/myCustomBoard, Rename file
src_files_<Board>.mk to src_files_myCustomBoard.mk. This file will
need a bit of work depending on what elements of board you need for your
platform.

**Step 3: Adding MACRO based inclusion of updated board_cfg.h
corresponding to custom Board**

In packages/ti/board/board_cfg.h, add the lines pointing to board_cfg.h
file in your customBoard package so that updated peripheral instances
and board specific defines can be picked up

::

    #if defined (myCustomBoard)
    #include <ti/board/src/myCustomBoard/include/board_cfg.h>
    #endif

**Step 4: Update top level board package makefile to include build for
customBoard Library** The makefile is used to include all relevant make
files for including Low level driver(LLD), source files relevant to
board and the common board.c file

-  In packages/ti/board/build/makefile.mk, add board.c to the
   customBoard build:

::

    ifeq ($(BOARD),$(filter $(BOARD),evmAM335x icev2AM335x skAM335x bbbAM335x evmAM437x idkAM437x skAM437x myCustomBoard evmAM572x idkAM571x idkAM572x evmK2H evmK2K evmK2E evmK2L evmK2G iceK2G evmC6678 evmC6657))
    # Common source files across all platforms and cores
    SRCS_COMMON += board.c
    endif

-  Add board library source files and LLD files to the customBoard build

In packages/ti/board/build/makefile.mk, change

::

    ifeq ($(BOARD),$(filter $(BOARD), evmAM572x idkAM571x idkAM572x))
    include $(PDK_BOARD_COMP_PATH)/src/$(BOARD)/src_files_$(BOARD).mk
    include $(PDK_BOARD_COMP_PATH)/src/src_files_lld.mk
    endif

to

::

    ifeq ($(BOARD),$(filter $(BOARD), myCustomBoard evmAM572x idkAM571x idkAM572x))
    include $(PDK_BOARD_COMP_PATH)/src/$(BOARD)/src_files_$(BOARD).mk
    include $(PDK_BOARD_COMP_PATH)/src/src_files_lld.mk
    endif

**Step 5: Update Global makerules**

build_config.mk defines the global CFLAGS used to compile different PDK
components. Add the following line in the BOARD Specific configurations.

::

    CFLAGS_GLOBAL_myCustomBoard  = -DSOC_AM572x -DmyCustomBoard=myCustomBoard

The SOC_AM572x macro ensures that the CSL applicable to this SOC will be
included in the build. Use the SoC name that corresponds to the platform of your custom board.


**Optional step to update RTSC platform definition** If you have a
custom RTSC platform definition for your custom board that updates the
memory and platform configuration using RTSC Tool then you need to
update the platform.mk file that associates the RTSC platform with the
corresponding board library

In packages/ti/build/makerules/platform.mk, add the following lines:


::

     ifeq ($(BOARD),$(filter $(BOARD), evmAM572x))
       PLATFORM_XDC = "ti.platforms.evmAM572X"
     endif

::

     ifeq ($(BOARD),$(filter $(BOARD), myCustomBoard))
       PLATFORM_XDC = "evmAM572XCustom"
     endif

.. note::
   The SYSBIOS platforms follow the convention to consolidate all
   platform definitions under SYSBIOS_INSTALL_PATH/packages/ti/platforms/\*
   hence the convention ti.platorms.<platformName> but for custom platform,
   users are not required to follow this convention.

**Step 6: Update source files corresponding to drivers used in board
library**. src_files_lld.mk file adds source files corresponding to LLD
drivers used in the board library. Usually most boards utilitize control
driver like I2C (for programming the PMIC or reading EEPROM), UART
drivers (for IO) and boot media drivers like (SPI/QSPI, MMC or NAND). In
the example below, we assume that the custom Board library has
dependency on I2C, SPI and UART LLD drivers. Since the LLD drivers will
be linked to the application along with board library, board library
only needs <driver>_soc.c corresponding to SOC used on the custom Board.

In packages/ti/board/src/src_files_lld.mk, add the following lines:


::

    ifeq ($(BOARD),$(filter $(BOARD), myCustomBoard))
    SRCDIR +=  $(PDK_INSTALL_PATH)/ti/drv/i2c/soc/am572x \
               $(PDK_INSTALL_PATH)/ti/drv/uart/soc/am572x \
               $(PDK_INSTALL_PATH)/ti/drv/spi/soc/am572x

::

    INCDIR +=  $(PDK_INSTALL_PATH)/ti/drv/i2c/soc/am572x \
               $(PDK_INSTALL_PATH)/ti/drv/uart/soc/am572x \
               $(PDK_INSTALL_PATH)/ti/drv/spi/soc/am572x

::

    # Common source files across all platforms and cores
    SRCS_COMMON += I2C_soc.c UART_soc.c SPI_soc.c
    endif


.. note::
   For all LLD drivers linked to the board library you need to include
   corresponding <drv>_soc.c file. For example if you include GPIO driver
   for setting board mux then GPIO_soc.c needs to be added to LLD source
   files.

**Step 7: Add custom Board to BOARDLIST and update CORELIST**

In packages/ti/board/board_component.mk, modify the build to add your
custom board and specify the cores for which you want to build the board
library. Example to build board library for only A15 and C66x cores,
limit the build by specify only a15_0 and C66x in the CORELIST

::

    board_lib_BOARDLIST       = myCustomBoard evmAM335x icev2AM335x skAM335x bbbAM335x evmAM437x idkAM437x skAM437x evmAM572x idkAM571x idkAM572x evmK2H evmK2K evmK2E evmK2L evmK2G iceK2G \

::

    #board_lib_am572x_CORELIST = c66x a15_0 ipu1_0
    board_lib_am572x_CORELIST = a15_0 c66x

**Step 8: Update .bld files for XDCTOOL based build steps.**

Make corresponding changes in packages/ti/board/config.bld, by adding
the following lines:

::

    var myCustomBoard = {
       name: "myCustomBoard",
       ccOpts: "-DmyCustomBoard -DSOC_AM572x",
       targets: [C66LE,A15LE ]
    }

::

    var boards = [ evmAM335x, icev2AM335x, skAM335x, bbbAM335x, evmAM437x, idkAM437x, skAM437x, myCustomBoard, evmAM572x, idkAM571x, idkAM572x, evmK2H, evmK2K, evmK2E, evmK2L, evmK2G, evmC6678, evmC6657 ];

Also, in packages/ti/board/package.bld, add the following line:

::

    Pkg.otherFiles[Pkg.otherFiles.length++] = "src/myCustomBoard/src_files_myCustomBoard.mk";


**Step 9: Setup Top level PDK build files to add the Custom board to
setup environment.**

Final setup involves updating the top level setup file for PDK package
to update to setup the build environment to include the custom Board in
setup. This can be done by commenting out the top line and adding in the
bottom line in <PDK_INSTALL_PATH>/packages/Rules.make:


::

    #export LIMIT_BOARDS ?= evmAM572x idkAM571x idkAM572x
    export LIMIT_BOARDS ?= myCustomBoard

**Alternative:** Invoke the build using command line options to limit
the build to specific board, specific SOC and specific CORE. For
example, if you want to build the A15 version of board library for
AM572x EVM, you can invoke the build using:

::

    gmake board_lib LIMIT_SOCS=am572x LIMIT_BOARDS=myCustomBoard LIMIT_CORES=a15_0 



**Step 10: Building the custom board with the updated settings**

To build package change directory to
<SDK_INSTALL_PATH>/<PDK_INSTALL_PATH>/packages, first run pdksetupenv.bat

To make just the board library: gmake board_lib


Additional steps for AM335x/AM437x users
"""""""""""""""""""""""""""""""""""""""""

.. note::
   Currently the AM335x and AM437x board libraries re-use the board support
   that was used in legacy starterware software. AM335x and AM437x users
   will need to additionally modify build files in starterware to build
   their custom board library.

.. raw:: html

