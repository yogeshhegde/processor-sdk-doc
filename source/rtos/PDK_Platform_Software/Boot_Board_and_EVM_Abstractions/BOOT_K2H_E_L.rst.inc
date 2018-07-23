.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_BOOT_K2H/E/L 

.. rubric:: Overview
   :name: overview-1

K2H/K2E/K2L EVMs uses the Secondary Boot Loader (SBL) to configure
board-related settings and execute a user application. The user
application can be single core or multicore, and execute on either DSP
cores or ARM cores. The only restriction is that the load sections must
not overlap the memory space that SBL uses.

The K2H/K2E/K2L SBL supports ARM master boot using SPI NOR. Please refer
to the boot mode dip switch settings in the respective EVM hardware page
(`link <http://processors.wiki.ti.com/index.php/Processor_SDK_Supported_Platforms_and_Versions>`__)
to configure your EVM for NOR boot.

.. rubric:: Flashing the Bootloader
   :name: flashing-the-bootloader

SBL and user application needs to be flashed into SPI NOR.

Refer to `Program EVM Guide <http://processors.wiki.ti.com/index.php/Program_EVM_UG>`__ for
instructions on using the script, program_evm.js, to automatically flash
your device.

.. rubric:: Usage
   :name: usage

#. Flash the bootloader and user application. This can be done
   automatically with default files by using program_evm.js
#. Set the EVM to ARM SPI boot mode
#. Connect UART serial debug cable from EVM to your computer. Open a
   terminal such as HyperTerminal or TeraTerm to see console output
#. Power on the EVM

.. rubric:: Compilation
   :name: compilation

The recommended rule-of-thumb to compiling projects in the Processor SDK
RTOS package is to use the makefiles provided. The makefiles are usable
after setting up your shell/terminal/command prompt environment with the
setupenv.bat or setupenv.sh script located in

::

     [SDK Install Path]/processor_sdk_rtos_<platform>_<version>

Refer to `Building RTOS SDK <Overview.html#building-the-sdk>`__ page on how to
setup your environment for building within any of the Processor SDK RTOS
packages.

The SBL package can be found in:

::

     [SDK Install Path]/pdk_<platform>_<version>/packages/ti/boot/sbl

To build:

::

     cd [SDK Install Path]/pdk_<platform>_<version>/packages/ti/boot/sbl
     make all BOOTMODE=spi BOARD=<EVM> SOC=<platform>

*<EVM>* can be of values: **evmK2H**, **evmK2E**, **evmK2L**, or
**evmK2K**

*<platform>* can be of values: **K2H**, **K2E**, **K2L**, or **K2K**

The resulting output will be in [SDK Install
Path]/pdk_<platform>_<version>/packages/ti/boot/sbl/binary/<platform>/spi/bin
directory.

.. rubric:: Making Loadable User Application image (app)
   :name: making-loadable-user-application-image-app

For converting the compiled .out files to a format loadable by TI's
Secondary Boot Loader (SBL), you must follow these two steps:

#. **out2rprc.exe [.out file] [rprc output]**
#. **MulticoreImageGen.exe LE 55 [output name] 0 [rprc output]**

Out2rprc.exe and MulticoreImageGen.exe are tools supplied by TI and can
be located in the **<PDK_INSTALL_DIR>/packages/ti/boot/sbl/tools**
folder. "rprc output" can be any spare name of your choosing. "output
name" can also be any name of your choosing.

The '0' used in step 2 refers to the Core ID to boot. By default, '0' is
MPU (Cortex A15) core 0. You can input a different value to boot to
other cores. Valid values are:

.. list-table:: Title
   :widths: 25 25 50
   :header-rows: 2
   
    * - Heading row 1, column 1
      - Heading row 1, column 2
      - Heading row 1, column 3
    * - Row 1, column 1
      -
      - Row 1, column 3
    * - Row 2, column 1
      - Row 2, column 2
      - Row 2, column 3

+-----------------------+-----------------------+-----------------------+
|         K2H           |          K2E          |         K2L           |
+==========+============+===========+===========+==========+============+
| **Core** | **Value**  | **Core**  | **Value** | **Core** | **Value**  |
+----------+------------+-----------+-----------+----------+------------+
|MPU Core 0|     0      |MPU Core 0 |     0     |MPU Core 0|     0      |
+----------+------------+-----------+-----------+----------+------------+
|MPU Core 1|     1      |MPU Core 1 |     1     |MPU Core 1|     1      |
+----------+------------+-----------+-----------+----------+------------+
|MPU Core 2|     2      |MPU Core 2 |     2     |MPU SMP   |     4      |
+----------+------------+-----------+-----------+----------+------------+
|MPU Core 3|     3      |MPU Core 3 |     3     |DSP Core 0|     5      |
+----------+------------+-----------+-----------+----------+------------+
|MPU SMP   |     4      |MPU SMP    |     4     |DSP Core 1|     6      |
+----------+------------+-----------+-----------+----------+------------+
|DSP Core 0|     5      |DSP Core 0 |     5     |DSP Core 2|     7      |
+----------+------------+-----------+-----------+----------+------------+
|DSP Core 1|     6      |           |           |DSP Core 3|     8      |
+----------+------------+-----------+-----------+----------+------------+
|DSP Core 2|     7      |           |           |          |            |
+----------+------------+-----------+-----------+----------+------------+
|DSP Core 3|     8      |           |           |          |            |
+----------+------------+-----------+-----------+----------+------------+
|DSP Core 4|     9      |           |           |          |            |
+----------+------------+-----------+-----------+----------+------------+
|DSP Core 5|     10     |           |           |          |            |
+----------+------------+-----------+-----------+----------+------------+
|DSP Core 6|     11     |           |           |          |            |
+----------+------------+-----------+-----------+----------+------------+
|DSP Core 7|     12     |           |           |          |            |
+----------+------------+-----------+-----------+----------+------------+

If MPU SMP is chosen, the same boot image and entry will be used for all
MPU cores. SBL can also parse multiple boot images that are concatenated
together. Simply use MulticoreImageGen as such:

**MulticoreImageGen.exe LE 55 [output name] [Core ID a] [rprc output a]
[Core ID b] [rprc output b] [Core ID c] [rprc output c] ...**

.. rubric:: Flash Writers
   :name: flash_writers

.. rubric:: SPI Writer
   :name: spi_writer

The SPI flash writer, spi_flash_writer.out, is a part of the SBL package
and allows users to flash multiple images at different offsets into the
board's SPI NOR flash memory.

.. rubric:: Compilation
   :name: _compilation-1

::

     cd [SDK Install Path]/pdk_<platform>_<version>/packages/ti/boot/sbl/
     make spi_flashwriter BOARD=<EVM> SOC=<platform>

The binary output will be at:

::

     [SDK Install Path]/pdk_<platform>_<version>/packages/ti/boot/sbl/tools/flashWriter/spi/bin/<platform>


.. rubric:: Usage
   :name: _usage-1

#. Copy the binaries that you want to flash to: [SDK Install
   Path]/pdk_<platform>_<version>/packages/ti/boot/sbl/tools/flashWriter/spi/bin/<platform>
#. In that same directory, there is a file named **config**. Edit that
   file such that each line has 2 parameters: [name of binary to flash]
   [SPI NOR offset to flash to]
#. Set your EVM to NO BOOT. Power on, launch target configuration in
   CCS, and connect to DSP Core 0
#. Load and run [SDK Install
   Path]/pdk_<platform>_<version>/packages/ti/boot/sbl/tools/flashWriter/spi/bin/<platform>/spi_flash_writer.out
#. You should see the flash progress output on UART terminal

| 

.. rubric:: Boot Example
   :name: boot_example

Below is an example output of evmK2H booting after having images flashed
in by program_evm.js:

::

    **** PDK SBL ****
    Boot succesful!
    Begin parsing user application
    Jumping to user application...


    TMDXEVM6636K2H POST Version 01.00.00.08
    ------------------------------------------
    SOC Information

    BMC Version: 0000
    EFUSE MAC ID is: B4 99 4C B6 E2 5B
    SA is enabled on this board.
    PLL Reset Type Status Register: 0x00000001
    Platform init return code: 0x00000000

    Power On Self Test

    POST running in progress ...
    POST I2C EEPROM read test started!
    POST I2C EEPROM read test passed!
    POST SPI NOR read test started!
    POST SPI NOR read test passed!
    POST EMIF16 NAND read test started!
    POST EMIF16 NAND read test passed!
    POST external memory test started!
    POST external memory test passed!
    POST done successfully!

    POST result: PASS

.. raw:: html

