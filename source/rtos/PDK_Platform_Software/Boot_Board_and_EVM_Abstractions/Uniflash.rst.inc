
Introduction
^^^^^^^^^^^^^^
Uniflash is an Unified Flashing tool which provides utilities for flashing the application software 
images to non-removable flash devices on TI hardware platforms. 

Uniflash for TI processors platform includes two components

 - Flash Programmer
 - Host utility

Flash porgrammer runs on target platform which takes care of receiving the images from Uniflash host
utility and programming them onto flash devices. Flash programmer communicates with Uniflash host utility
over the UART interface.

Default flash programmer which is part of the Uniflash release can be found at - "<Uniflash Root>\processors\FlashWriter\<Board Name>"

Host utility runs on host machine which provides Command-line Interface (CLI) to communicate with flash programmer.
Windows and Linux are supported OS platforms for running Uniflash host utility. Host utility uses UART or JTAG
interface to download the flash programmer to the target platform. All data transfers between
Uniflash host utility and Flash programmer happens over UART interface.

Refer to `Uniflash Documentation <http://processors.wiki.ti.com/index.php/Category:CCS_UniFlash>`__ 
for more details on Uniflash tool.


Supported Platforms
^^^^^^^^^^^^^^^^^^^^
Below table shows the platforms supported by Uniflash and flash devices supported on each platform.
Download mode indicates the mode of communication for downloading flash programmer to target platform.

+----------------+----------------+------------------+---------------+------+------+--------------+
|      SOC       |    SOC Core    |    PLATFORM      |    FLASH DEVICE             |DOWNLOAD MODE |
|                |                |                  +-------+-------+------+------+------+-------+
|                |                |                  | SPI   | QSPI  | OSPI | EMMC | UART | JTAG  |
+================+================+==================+=======+=======+======+======+======+=======+
| AM335x         | Cortex-A8      | AM335x GP EVM    |   X   |       |      |      |   X  |   X   |
|                |                +------------------+-------+-------+------+------+------+-------+
|                |                | AM335x ICEv2     |   X   |       |      |      |      |   X   |
|                |                +------------------+-------+-------+------+------+------+-------+
|                |                | AMIC110 ICE      |   X   |       |      |      |   X  |   X   |
+----------------+----------------+------------------+-------+-------+------+------+------+-------+
| AM437x         | Cortex-A9      | AM437x IDK       |       |   X   |      |      |      |   X   |
+----------------+----------------+------------------+-------+-------+------+------+------+-------+
| AM571x         | Cortex-A15     | AM571x IDK       |       |   X   |      |      |      |   X   |
+----------------+----------------+------------------+-------+-------+------+------+------+-------+
| AM572x         | Cortex-A15     | AM572x IDK       |       |   X   |      |      |      |   X   |
+----------------+----------------+------------------+-------+-------+------+------+------+-------+
| AM574x         | Cortex-A15     | AM574x IDK       |       |   X   |      |      |      |   X   |
+----------------+----------------+------------------+-------+-------+------+------+------+-------+
| K2G            | Cortex-A15     | K2G GP EVM       |       |   X   |      |      |      |   X   |
|                |                +------------------+-------+-------+------+------+------+-------+
|                |                | K2G ICE          |       |   X   |      |      |      |   X   |
+----------------+----------------+------------------+-------+-------+------+------+------+-------+
| AM65XX         | Cortex-R5      | AM65xx EVM       |       |       |   X  |   X  |   X  |       |
|                |                +------------------+-------+-------+------+------+------+-------+
|                |                | AM65xx IDK       |       |       |   X  |   X  |   X  |       |
+----------------+----------------+------------------+-------+-------+------+------+------+-------+


where,

X  - Supported
XX - Manual JTAG mode


Getting Started with Uniflash
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Downloads
"""""""""""
Latest version of Uniflash can be downloaded `here <http://processors.wiki.ti.com/index.php/Category:CCS_UniFlash#UniFlash_v4>`__


Command Options
""""""""""""""""
Uniflash CLI supports set of commands and configuration flags which are provided through dslite script. 
Run the help command as described below to see all the options supported by Uniflash. 

For Windows
::

        # cd <path_to_the_uniflash>
        # dslite.bat --mode processors -h



For Linux

::

        # cd <path_to_the_uniflash>
        # sudo ./dslite.sh --mode processors -h
        


This will display help menu.
Following is the sample output on Windows.
::
   
    For more details and examples, please refer to the UniFlash Quick Start guide.
    
    
        ----------------------------------------------------------------------------
        ProcessorSDKSerialFlash CLI Tool
        Copyright (C) 2017-2019 Texas Instruments Incorporated - http://www.ti.com/
        Version 1.2.0.0
        ----------------------------------------------------------------------------
    
        Displaying Help..
     
        Usage:
        dslite.bat --mode processors -c <COM_Port> -f <Path_to_the_file_to_be_transfered> -d <Device_Type> -i <Image_Type> -e <erase_length> -o <Offset>                                                                    
    
        Device_Type:
        0 - NAND
        1 - SPI
        2 - QSPI
        3 - OSPI
        4 - eMMC
        5 - HyperFlash
        6 - UFS

        Image_Type:
        0 - Flash
        1 - MLO
        2 - Uboot
        3 - UImage
        4 - Firmware
        5 - Custom Image
    
        erase_length:Length in Bytes
    
        Note: File Path should not be specified for Flash Erase command
     

.. note::

           Offset option(-o) expects hexadecimal value by default.
           The offset value can be provided with or without "0x"


Uniflash Execution Steps
"""""""""""""""""""""""""
Uniflash provides two modes of communication for downloading the flash programmer - UART and/or JTAG.
In JTAG mode Uniflash commnad-line interface is supported for most of the platforms.
Manual loading of the flash programmer through CCS is required for few cases.
Below diagram shows the execution steps for flashing the application images based on the Uniflash
supported mode for downloading the flash programmer.

.. Image:: ../images/Uniflash_Execution_Steps.png

Check the `Supported Platforms <index_board.html#supported-platforms>`__ for details of the mode of communication supported for
downloading the flash programmer on each platform.


Flashing Binaries with Uniflash
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Downloading Flash Programmer
""""""""""""""""""""""""""""""
UART Load
'''''''''''
Follow below steps for downloading the flash programer over UART

 - Confgure boot mode of the target platform to UART boot.
 - Connect UART serial port of the target platform to host PC
 - Power cycle the target platform
 - Run below commands on the Host PC from Uniflash root folder


For Windows
::

        # cd <Path to Uniflash Root Folder>
        # dslite.bat --mode processors -c <COM Port> -f <Flash Programmer Binary with Full Path> -i 0
        Example:
        # dslite.bat --mode processors -c COM1 -f <Uniflash Root>\processors\FlashWriter\am65xx_evm\uart_am65xx_evm_flash_programmer.tiimage -i 0


For Linux

::

        # cd <Path to Uniflash Root Folder>
        # sudo ./dslite.sh --mode processors -c <COM Port> -f <Flash Programmer Binary with Full Path>
        Example:
        # sudo ./dslite.sh --mode processors -c /dev/ttyUSB1 -f <Uniflash Root>/processors/FlashWriter/am65xx_evm/uart_am65xx_evm_flash_programmer.tiimage


The application will output the progress of file transfer on the Host PC.
Following is the sample output on Windows.

::

        Executing the following command:
        > C:\ti\uniflash_[Version Num]\processors\ProcessorSDKSerialFlash.exe -c COM1 -f 
        C:\ti\pdk\ti\board\utils\uniflash\bin\uart_iceAMIC110_flash_programmer.bin

        For more details and examples, please visit http://processors.wiki.ti.com/index.
        php/UniFlash_[Version Num]_Quick_Guide#Command_Line_Interface


        ----------------------------------------------------------------------------
        ProcessorSDKSerialFlash CLI Tool
        Copyright (C) 2017-2019 Texas Instruments Incorporated - http://www.ti.com/
        Version 1.0.0.6
        ----------------------------------------------------------------------------
        Flashing Flash Writer to RBL..

        Transferring File of size 56776 bytes
        File Transfer complete!



Upon successful transfer, Flash Writer will be loaded and executed on the target platform.
The Flash Writer starts sending character 'C'(xmodem protocol).
This can be verified on the serial console utility.

.. note::   Any Serial Console utility that supports xmodem protocol can be used.
            Verified utilities are Teraterm (in Windows) and Minicom (in Linux)


JTAG Load
'''''''''''

Uniflash CLI JTAG Load
~~~~~~~~~~~~~~~~~~~~~~~
Follow below steps for downloading the flash programer over JTAG using Uniflash CLI

 - Confgure boot mode of the target platform to 'No Boot' or 'JTAG mode'
 - Connect UART serial port of the target platform to host PC
 - Power cycle the target platform
 - Run below commands on the Host PC from Uniflash root folder
 

For Windows

::

        # cd <Path to Uniflash Root Folder>
        # dslite.bat --mode load --config=<CCS Target Config file (ccxml) with Full Path>
        -f <Flash Programmer Binary with Full Path> -n <Core ID to be Connected to JTAG on the Target Platform>
        Example:
        # dslite.bat --mode load --config=C:\Users\username\ti\CCSTargetConfigurations\iceAMIC110.ccxml -f C:\ti\pdk\packages\ti\board\utils\uniflash\bin\iceAMIC110\uart_iceAMIC110_flash_programmer.out -n 1
        


For Linux

::

        # cd <Path to Uniflash Root Folder>
        # sudo ./dslite.sh --mode load --config=<CCS Target Config file (ccxml) with Full Path>
        -f <Flash Programmer Binary with Full Path> -n <Core ID to be Connected to JTAG on the Target Platform>
        Example:
        # sudo ./dslite.sh --mode load --config=/home/ti/CCSTargetConfigurations/iceAMIC110.ccxml -f /home/user/pdk/ti/board/utils/uniflash/bin/uart_iceAMIC110_flash_programmer.out -n 1



The application will output the progress of file transfer on the Host PC
Following is the sample output on Windows.

::
        
        Executing the following command:
        > "C:\ti\uniflash_[Version Num]\deskdb\content\TICloudAgent\win\ccs_base\DebugServer\bin\DSLite" load --config=C:\Users\username\ti\CCSTargetConfigurations\iceAMIC110.ccxml -f C:\ti\pdk\packages\ti\board\utils\uniflash\bin\iceAMIC110\uart_iceAMIC110_flash_programmer.out -n 1

        For more details and examples, please visit http://processors.wiki.ti.com/index.php/UniFlash_[Version Num]_Quick_Guide#Command_Line_Interface

        DSLite version [Version Num]
        Configuring Debugger (may take a few minutes on first launch)...
                Initializing Register Database...
                Initializing: IcePick_D_0
                Executing Startup Scripts: IcePick_D_0
                Initializing: CS_DAP_M3
                Executing Startup Scripts: CS_DAP_M3
                Initializing: M3_wakeupSS_0
                Executing Startup Scripts: M3_wakeupSS_0
                Initializing: CS_DAP_DebugSS
                Executing Startup Scripts: CS_DAP_DebugSS
                Initializing: CortxA8
                Executing Startup Scripts: CortxA8
                Initializing: CSSTM_0
                Executing Startup Scripts: CSSTM_0
                Initializing: CSETB_0
                Executing Startup Scripts: CSETB_0
                Initializing: PRU_0
                Executing Startup Scripts: PRU_0
                Initializing: PRU_1
                Executing Startup Scripts: PRU_1
        Connecting...
        GEL: CortxA8: Output: ****  AM3359_ICE & BoosterPack Initialization is in progress ..........
        GEL: CortxA8: Output: ****  AM335x & Booster Pack ALL PLL Config for OPP == OPP100 is in progress .........
        GEL: CortxA8: Output: Input Clock Read from SYSBOOT[15:14]:  25MHz
        GEL: CortxA8: Output: ****  Going to Bypass...
        GEL: CortxA8: Output: ****  Bypassed, changing values...
        GEL: CortxA8: Output: ****  Locking ARM PLL
        GEL: CortxA8: Output: ****  Core Bypassed
        GEL: CortxA8: Output: ****  Now locking Core...
        GEL: CortxA8: Output: ****  Core locked
        GEL: CortxA8: Output: ****  DDR DPLL Bypassed
        GEL: CortxA8: Output: ****  DDR DPLL Locked
        GEL: CortxA8: Output: ****  PER DPLL Bypassed
        GEL: CortxA8: Output: ****  PER DPLL Locked
        GEL: CortxA8: Output: ****  DISP PLL Config is in progress ..........
        GEL: CortxA8: Output: ****  DISP PLL Config is DONE ..........
        GEL: CortxA8: Output: ****  AM335x BoosterPack ALL ADPLL Config for 25 MHz OPP == OPP100 25MHz is Done .........
        GEL: CortxA8: Output: ****  AM335x DDR3 EMIF and PHY configuration is in progress...
        GEL: CortxA8: Output: EMIF PRCM is in progress .......
        GEL: CortxA8: Output: EMIF PRCM Done
        GEL: CortxA8: Output: DDR PHY Configuration in progress
        GEL: CortxA8: Output: Waiting for VTP Ready .......
        GEL: CortxA8: Output: VTP is Ready!
        GEL: CortxA8: Output: DDR PHY CMD0 Register configuration is in progress .......
        GEL: CortxA8: Output: DDR PHY CMD1 Register configuration is in progress .......
        GEL: CortxA8: Output: DDR PHY CMD2 Register configuration is in progress .......
        GEL: CortxA8: Output: DDR PHY DATA0 Register configuration is in progress .......
        GEL: CortxA8: Output: DDR PHY DATA1 Register configuration is in progress .......
        GEL: CortxA8: Output: Setting IO control registers.......
        GEL: CortxA8: Output: EMIF Timing register configuration is in progress .......
        GEL: CortxA8: Output: EMIF Timing register configuration is done .......
        GEL: CortxA8: Output: PHY is READY!!
        GEL: CortxA8: Output: DDR PHY Configuration done
        GEL: CortxA8: GEL Output: Turning on EDMA...
        GEL: CortxA8: GEL Output: EDMA is turned on...
        GEL: CortxA8: Output: ****  AM3359_ICE Initialization is Done ******************


        Loading Program: C:\ti\pdk\packages\ti\board\utils\uniflash\bin\iceAMIC110\uart_iceAMIC110_flash_programmer.out
                Preparing ...
                .text: 0 of 57716 at 0x402f0054
        warning: CortxA8: Loader: One or more sections of your program falls into a memory region that is not writable.  These regions will not actually be written to the target.  Check your linker configuration and/or memory map.
                .text: 32752 of 57716 at 0x402f0054: 49%
                Finished: 49%
                Setting PC to entry point.: 49%
        Running...
        Success


The Flash Programmer will be loaded and executed. The Flash Programmer starts sending character 'C'(xmodem protocol).
This can be verified on the serial console utility.



Manual JTAG Load
~~~~~~~~~~~~~~~~~
This section to be updated


Programming Binaries to the Flash Device
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Follow the procedure explained in Section :ref:`program-flashwriter` to load Flash Programmer binary to the target platform.
Once the Flash Programmer is loaded and executed, use the following commands to program binaries on to the Flash Device.

For Windows
::

        # cd <path_to_the_uniflash>
        # dslite.bat --mode processors -c <COM_Port> -f <Path_to_the_binary_to_be_flashed> -d  <device_type> -o <offset>
        Example:
        # dslite.bat --mode processors -c COM7 -f C:\ti\pdk\packages\ti\starterware\binary\bootloader\bin\am335x-evm\gcc\bootloader_boot_mcspi_a8host_debug_ti.bin -d 1 -o 0



For Linux
::

        # cd <path_to_the_uniflash>
        # sudo ./dslite.sh --mode processors -c <COM_Port> -f <Path_to_the_binary_to_be_flashed> -d  <device_type> -o <offset>
        Example:
        # sudo ./dslite.sh --mode processors -c /dev/ttyUSB1 -f /home/user/pdk/packages/ti/starterware/binary/bootloader/bin/am335x-evm/gcc/bootloader_boot_mcspi_a8host_debug_ti.bin -d 1 -o 0



where device type is,

0. NAND Flash
1. SPI Flash
2. QSPI Flash
3. OSPI Flash
4. eMMC

The application will output the progress of file transfer to the console on the Host PC.
Following is the sample output on Windows.

::

        Executing the following command:
        > C:\ti\uniflash_[Version Num]\processors\ProcessorSDKSerialFlash.exe -c COM7 -f
        C:\ti\pdk\packages\ti\starterware\binary\bootloader\bin\am335x-evm\gcc\bootloader_boot_mcspi_a8host_debug_ti.bin -d 1 -o 0

        For more details and examples, please visit http://processors.wiki.ti.com/index.
        php/UniFlash_[Version Num]_Quick_Guide#Command_Line_Interface


        ----------------------------------------------------------------------------
        ProcessorSDKSerialFlash CLI Tool
        Copyright (C) 2017-2019 Texas Instruments Incorporated - http://www.ti.com/
        Version 1.0.0.6
        ----------------------------------------------------------------------------
        Flashing Image to Flash Writer..

        Transferring Header information..
        Header Transfer complete!

        Transferring File of size 55680 bytes
        File Transfer complete!
        Programming Flash Device..

        Flash Programming Success!



Erasing the Flash Device
^^^^^^^^^^^^^^^^^^^^^^^^^

Follow the procedure explained in Section :ref:`program-flashwriter` (:ref:`program-flashwriter-am65xx` in case of AM65xx platform)
to load Flash Programmer binary to the target platform.
Once the Flash Writer is loaded and executed, use the following commands to erase the Flash Device on the target platform

For Windows

::

        # cd <path_to_the_uniflash>
        # dslite.bat --mode processors -c <COM_Port> -e <Erase_Length_in_bytes> -d <device_type> -o <Erase_Offset>
        Example:
        # dslite.bat --mode processors -c COM7 -e 10000 -d 1 -o 20000


For Linux

::

        # cd <path_to_the_uniflash>
        # sudo ./dslite.sh --mode processors -c <COM_Port> -e <Erase_Length_in_bytes> -d <device_type> -o <Erase_Offset>
        Example:
        # sudo ./dslite.sh  --mode processors -c /dev/ttyUSB1 -e 10000 -d 1 -o 20000


The application will output the status to the console on the Host PC.
Following is the sample output on Windows.

::

        Executing the following command:
        > C:\ti\uniflash_[Version Num]\processors\ProcessorSDKSerialFlash.exe -c COM7 -e 10000 -
        d 1 -o 20000

        For more details and examples, please visit http://processors.wiki.ti.com/index.
        php/UniFlash_[Version Num]_Quick_Guide#Command_Line_Interface


        ----------------------------------------------------------------------------
        ProcessorSDKSerialFlash CLI Tool
        Copyright (C) 2017-2019 Texas Instruments Incorporated - http://www.ti.com/
        Version 1.0.0.6
        ----------------------------------------------------------------------------
        Erasing Flash....

        Transferring Header information..
        Header Transfer Complete!!
        Flash Erase Success!


Platform Specific Information
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
AM335x
""""""""
 - Make sure the Profile Selection switch in AM335x GP EVM is set to Profile#2 while programming SPI flash

AM65xx
"""""""
 - To be updated


.. _rebuild-board_utils:

Rebuilding Board-utils
^^^^^^^^^^^^^^^^^^^^^^
- Use the following commands to rebuild Uniflash and Apploader supported as part of board utils

- For Windows
::

        # cd <pdk_install_path>/packages
        # pdksetupenv.bat
        # cd ti\board\utils
        # gmake clean
        # gmake
        
- For Linux
::

        # cd <pdk_install_path>/packages
        # ./pdksetupenv.sh
        # cd ti/board/utils
        # make clean
        # make
        
- Uniflash binaries will be created under the folder <pdk_install_path>/packages/ti/board/utils/uniflash/bin/<board_name>/
- Apploader binaries will be created under the folder <pdk_install_path>/packages/ti/board/utils/uartAppLoader/bin/<board_name>/



Porting Uniflash to Custom Platforms
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Uniflash is validated and delivered for TI EVM but it can be ported to custom boards provided SoC device support is available in the Uniflash.
This section provides step by step guidelines for porting the Uniflash to custom boards.
| 
<To be updated>


Uniflash FAQ
^^^^^^^^^^^^^
1. How do I confirm my HW setup is proper for image download over UART?

2. How do I verify which COM number to be used for Uniflash image download?

3. I am running Uniflash on Windows and Uniflash CLI is not able to open COM port. What could be the reason?

4. Should the flash device need to be erased using Uniflash erase command before flashing the images?

5. . . .

.. raw:: html
