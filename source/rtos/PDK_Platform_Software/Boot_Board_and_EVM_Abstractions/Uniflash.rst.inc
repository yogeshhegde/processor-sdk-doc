
Overview
^^^^^^^^

Uniflash is a standalone tool used to download application image over UART/JTAG serial interface
and flash it on to the flash device on the target platform.
This section explains on how to use Uniflash CLI tool to flash images to the TI's MPU platform.

Supported Platforms
^^^^^^^^^^^^^^^^^^^

+----------------+------------------+---------------+------+--------------+
|      SOC       |      PLATFORM    | FLASH DEVICE         |    MODES     |
|                |                  +-------+-------+------+------+-------+
|                |                  | SPI   | QSPI  | OSPI | UART | JTAG  |
+================+==================+=======+=======+======+======+=======+
| AM335x         | AM335x GP EVM    |   X   |       |      |   X  |   X   |
|                +------------------+-------+-------+------+------+-------+
|                | AM335x ICEv2     |   X   |       |      |      |   X   |
|                +------------------+-------+-------+------+------+-------+
|                | AMIC110 ICE      |   X   |       |      |   X  |   X   |
+----------------+------------------+-------+-------+------+------+-------+
| AM437x         | AM437x IDK       |       |   X   |      |      |   X   |
+----------------+------------------+-------+-------+------+------+-------+
| AM571x         | AM571x IDK       |       |   X   |      |      |   X   |
+----------------+------------------+-------+-------+------+------+-------+
| AM572x         | AM572x IDK       |       |   X   |      |      |   X   |
+----------------+------------------+-------+-------+------+------+-------+
| AM574x         | AM574x IDK       |       |   X   |      |      |   X   |
+----------------+------------------+-------+-------+------+------+-------+
| K2G            | K2G GP EVM       |       |   X   |      |      |   X   |
|                +------------------+-------+-------+------+------+-------+
|                | K2G ICE          |       |   X   |      |      |   X   |
+----------------+------------------+-------+-------+------+------+-------+
| AM65XX         | AM65xx EVM       |       |       |   X  |      |   X   |
|                +------------------+-------+-------+------+------+-------+
|                | AM65xx IDK       |       |       |   X  |      |   X   |
+----------------+------------------+-------+-------+------+------+-------+

where,

X - supported

Pre-Requisites
^^^^^^^^^^^^^^

1. Download and install the desktop version of `Uniflash tool <http://processors.wiki.ti.com/index.php/Category:CCS_UniFlash#UniFlash_v4>`__

2. Download and install the Processor-SDK RTOS package. See
the software product page for your device to get the latest version of
this software:

-  `Processor SDK for
   AM335x <http://www.ti.com/tool/processor-sdk-am335x>`__
-  `Processor SDK for
   AM437x <http://www.ti.com/tool/processor-sdk-am437x>`__
-  `Processor SDK for
   AM57xx <http://www.ti.com/tool/processor-sdk-am57x>`__
-  `Processor SDK for
   AM65xx <http://www.ti.com/tool/processor-sdk-am65x>`__
-  `Processor SDK for
   AMIC110 <http://www.ti.com/tool/PROCESSOR-SDK-AMIC110>`__
-  `Processor SDK RTOS for
   K2G <http://www.ti.com/tool/PROCESSOR-SDK-K2G>`__

From the appropriate software product page, go to the download page by
clicking "Get Software" for the RTOS package.


Binaries
^^^^^^^^
**Host**

The dslite script file in Uniflash tool provides an option(- -mode) to execute
the Uniflash CLI tool for TI's MPU platforms.

The *processors* mode shall execute the Uniflash CLI binary to flash images
to the TI's MPU platforms. This mode will execute the Uniflash CLI binary <path_to_the_uniflash>/processors/ProcessorSDKSerialFlash.exe

**Target**

Get the Flash Writer binaries from <pdk_install_path>/packages/ti/board/utils/uniflash/bin/<board_name>/

.. note::   Flash Writer Binaries needs to be rebuilt for AM335x and AM65xx platforms.
            Refer :ref:`rebuild-board_utils` section to rebuild FlashWriter.

Display Help
^^^^^^^^^^^^

Use the following command to display Help

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

        Executing the following command:
        > C:\ti\uniflash_[Version Num]\processors\ProcessorSDKSerialFlash.exe -h

        For more details and examples, please visit http://processors.wiki.ti.com/index.
        php/UniFlash_[Version Num]_Quick_Guide#Command_Line_Interface


        ----------------------------------------------------------------------------
        ProcessorSDKSerialFlash CLI Tool
        Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com/
        Version 0.2
        ----------------------------------------------------------------------------
        Displaying Help..

        Usage:
        ProcessorSDKSerialFlash.exe -c <COM_Port> -f <Path_to_the_file_to_be_transfered>
         -d <Device_Type> -i <Image_Type> -e <erase_length -o <Offset>

        Device_Type:
        0 - NAND
        1 - SPI
        2 - QSPI
        3 - OSPI
        4 - eMMC

        Image_Type:
        0 - Flash
        1 - MLO
        2 - Uboot
        3 - UImage
        4 - Custom Inteface


        erase_length:Length in Bytes


        Note: File Path should not be specified in case of Flash Erase

        Program Example:
        ProcessorSDKSerialFlash.exe -c COM7 -f C:/Users/Documents/test.bin -d 0 -i 0 -o
        20000

        Erase Example:ProcessorSDKSerialFlash.exe -c COM7 -d 2 -e 1000 -o 20000
    

.. note::  Currently Image_Type(option -i) is not supported.

           Offset option(option -o) receives hexadecimal value by default.
           The offset value(hexadecimal) can be preceded with or without "0x"


.. _program-flashwriter:

Programming FlashWriter
^^^^^^^^^^^^^^^^^^^^^^^^
Flash Writer binary is the target software, used to program the binaries on to the flash devices
of the target platform.

There are two ways of loading and executing the Flash Writer on to the target platform:

1. Loading Flash Writer via ROM boot (over UART interface), for the target platforms that support UART Boot mode
2. Loading Flash Writer over JTAG interface, for the target platforms that do not support UART Boot mode

.. note:: This Section does not apply for AM65xx platform.
          Refer Section :ref:`program-flashwriter-am65xx` to load FlashWriter on AM65xx platform


Loading Flash Writer via ROM boot
+++++++++++++++++++++++++++++++++

For the target platforms that support UART Boot mode, use the following
procedure to transfer flash writer

**Steps**

1. Set the sysboot pins in UART boot mode.
2. Make sure the Serial connections between the Host PC and the target platform are established.
3. Power cycle the board
4. Issue the following commands on the Host PC

For Windows
::

        # cd <path_to_the_uniflash>
        # dslite.bat --mode processors -c <COM_Port> -f <Path_to_the_flash_writer_to_be_transfered>
        Example:
        # dslite.bat --mode processors -c COM1 -f C:\ti\pdk\ti\board\utils\uniflash\bin\uart_iceAMIC110_flash_programmer.bin
        


For Linux

::

        # cd <path_to_the_uniflash>
        # sudo ./dslite.sh --mode processors -c <COM_Port> -f <Path_to_the_flash_writer_to_be_transfered>
        Example:
        # sudo ./dslite.sh --mode processors -c /dev/ttyUSB1 -f /home/user/pdk/ti/board/utils/uniflash/bin/uart_iceAMIC110_flash_programmer.bin
        


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
        Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com/
        Version 0.2
        ----------------------------------------------------------------------------
        Flashing Flash Writer to RBL..

        Transferring File of size 56776 bytes
        File Transfer complete!



Upon successful transfer, Flash Writer will be loaded and executed on the target platform.
The Flash Writer starts sending character 'C'(xmodem protocol).
This can be verified on the serial console utility.

.. note::   Any Serial Console utility that supports xmodem protocol can be used.
            Verified utilities are Teraterm (in Windows) and Minicom (in Linux)

Loading Flash Writer over JTAG interface
++++++++++++++++++++++++++++++++++++++++

For the target platforms that does not support UART Boot mode, use the following
procedure to load and execute flash writer over JTAG interface.

**Steps**

1. Make sure the Serial and JTAG connections between the Host PC and the target platform are established.
2. Power cycle the board
3. Issue the following commands on the Host PC

For Windows

::

        # cd <path_to_the_uniflash>
        # dslite.bat --mode load --config=<Path_to_ccxml_file>
        -f <Path_to_the_flash_writer_to_be_transfered> -n <core_to_be_connected_on_the_target_platform>
        Example:
        # dslite.bat --mode load --config=C:\Users\username\ti\CCSTargetConfigurations\iceAMIC110.ccxml -f C:\ti\pdk\packages\ti\board\utils\uniflash\bin\iceAMIC110\uart_iceAMIC110_flash_programmer.out -n 1
        


For Linux

::

        # cd <path_to_the_uniflash>
        # sudo ./dslite.sh --mode load --config=<Path_to_ccxml_file> -f <Path_to_the_flash_writer_to_be_transfered> -n <core_to_be_connected_on_the_target_platform>
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


The Flash Writer will be loaded and executed. The Flash Writer starts sending character 'C'(xmodem protocol).
This can be verified on the serial console utility.

.. _program-flashwriter-am65xx:

Programming FlashWriter on AM65xx Platform
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
- Follow the instructions mentioned in `Basic CCS Setup <http://software-dl.ti.com/processor-sdk-rtos/esd
  /docs/latest/rtos/How_to_Guides.html#ccs-host-setup>`__ to connect to M3_0 and A53_0_0 and configure DDR.
- Once DDR is configured, load the Flash Writer program (<uniflash_install_path>/processors/FlashWriter/AM65XX/
  uart_am65xx_evm_flash_programmer.out) on to the A53_0_0 core.
- Run the FlashWriter program. The Flash Writer starts sending character 'C'(xmodem protocol) on the `SoC Main Uart0
  <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/How_to_Guides.html#uart-connection>`__
- Refer Section :ref:`erasing_target` for erasing the flash device on the target platform.
- To program SBL and app image on the AM65xx EVM
    - Program the SBL image (sbl_ospi_img_mcu1_0_release.tiimage) at offset 0.
    - Program the SBL app (sbl_ospi_img_mcu1_0_release.tiimage) at offset 0x80000.

::

    For Linux:
    cd <path_to_the_uniflash>
    sudo ./dslite.sh --mode processors -c <COM_Port> -f <Path_to_the_binary_to_be_flashed> -d  <device_type> -o <offset>

    Example:
    sudo ./dslite.sh --mode processors -c /dev/ttyUSB1 -f <PDK>/packages/ti/boot/sbl/binary/ospi/am65xx_evm/sbl_ospi_img_mcu1_0_release.tiimage -d 3 -o 000
    sudo ./dslite.sh --mode processors -c /dev/ttyUSB1 -f <PDK>/packages/ti/boot/sbl/example/ampMulticoreApp/binary/am65xx_evm/ sbl_baremetal_boot_test_am65xx_evm_all_coresTestApp_release.appimage -d 3 -o 80000

::

    For Windows:
    cd <path_to_the_uniflash>
    .\dslite.bat --mode processors -c <COM_Port> -f <Path_to_the_binary_to_be_flashed> -d  <device_type> -o <offset>

    Example:
    .\dslite.bat --mode processors -c COM9 -f <PDK>\packages\ti\boot\sbl\binary\ospi\am65xx_evm\sbl_ospi_img_mcu1_0_release.tiimage -d 3 -o 000
    .\dslite.bat --mode processors -c COM9 -f <PDK>\packages\ti\boot\sbl\example\ampMulticoreApp\binary\am65xx_evm\sbl_baremetal_boot_test_am65xx_evm_all_coresTestApp_release.appimage -d 3 -o 80000

.. note:: When using the dslite scripts for the AM65xx EVMs:

            - Specify the <device_type> as 3 (for OSPI flash)
            - <COM_Port> must refer to the `SoC Main Uart0  <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/How_to_Guides.html#uart-connection>`__

.. warning::   If you open the SoC Main Uart0 on a terminal application like minicom or hyperterm to see if the
               'CCCC' is being output, make sure to close the application before executing dslite. Disconnect
               and re-connect the Serial cable to reset the connection. If a terminal program like minicom or
               hyperterminal is run first, the dslite script might not run successfully.

.. _program_target:

Programming binaries to Flash Device
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Follow the procedure explained in Section :ref:`program-flashwriter` to load Flash Writer binary to the target platform.
Once the Flash Writer is loaded and executed, use the following commands to program binaries on to the Flash Device.

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
        Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com/
        Version 0.2
        ----------------------------------------------------------------------------
        Flashing Image to Flash Writer..

        Transferring Header information..
        Header Transfer complete!

        Transferring File of size 55680 bytes
        File Transfer complete!
        Programming Flash Device..

        Flash Programming Success!


.. note::  Make sure the Profile Selection switch in AM335x GP EVM is set to Profile#2
           to support SPI flash programming

.. _erasing_target:

Erasing Flash Device on the Target Platform
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Follow the procedure explained in Section :ref:`program-flashwriter` to load Flash Writer binary to the target platform.
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
        Copyright (C) 2017-2018 Texas Instruments Incorporated - http://www.ti.com/
        Version 0.2
        ----------------------------------------------------------------------------
        Erasing Flash....

        Transferring Header information..
        Header Transfer Complete!!
        Flash Erase Success!

.. _rebuild-board_utils:

Rebuilding Board-utils
^^^^^^^^^^^^^^^^^^^^^^
- Use the following commands to rebuild Flash Writer/Apploader

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

.. raw:: html