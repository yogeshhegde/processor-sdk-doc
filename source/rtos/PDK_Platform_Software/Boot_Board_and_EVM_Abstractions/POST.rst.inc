.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_POST

.. rubric:: Overview
   :name: overview-1

The Power-On Self Test (POST) boot is designed to execute a series of
platform/EVM factory tests on reset and indicate a PASS/FAIL condition
using the LEDs and write test result to UART. A PASS result indicates
that the EVM can be booted. POST is supported on K2H/K2E/K2L/C66x
devices, this functionality is provided on other devices (e.g., AM57x)
by `Diagnostics <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_DIAG>`__.

POST will perform the following functional tests:

-  External memory read/write test
-  NAND read test
-  NOR read test
-  EEPROM read test
-  UART write test
-  LED test

Additionally, POST provides the following useful information:

-  FPGA version
-  Board serial number
-  EFUSE MAC ID
-  Indication of whether SA is available on SOC
-  PLL Reset Type status register

| 

.. rubric:: Compilation
   :name: compilation

The recommended rule-of-thumb to compiling projects in the Processor SDK
RTOS package is to use the makefiles provided. The makefiles are usable
after setting up your shell/terminal/command prompt environment with the
setupenv.bat or setupenv.sh script located in

::

     [SDK Install Path]/processor_sdk_rtos_<platform>_<version>

Refer to `Processor SDK RTOS Building the SDK <Overview.html#building-the-sdk>`__
guide on how to setup your environment for building within any of the
Processor SDK RTOS packages.

To compile the POST application:

::

     cd [SDK Install Path]/pdk_<platform>_<version>/packages/ti/boot/post/<platform>/build
     make all

This will create the .out executable that can be loaded via CCS

| 

.. rubric:: Flashing POST Image
   :name: flashing-post-image

To flash a bootable image of POST, please refer to the `SDK RTOS
Flashing Bootable Images <How_to_Guides.html#flash-bootable-images-c66x-k2h-k2e-k2l-only>`__ guide.

| 

.. rubric:: C66x LED Code
   :name: c66x-led-code

For C66x, the on-board LEDs can also provide diagnostic information on
POST routines. Refer to the following table:

+-----------------------------+-------+-------+-------+-------+
| Test Result                 | LED1  | LED2  | LED3  | LED4  |
+=============================+=======+=======+=======+=======+
| Test in progress            | on    | on    | on    | on    |
+-----------------------------+-------+-------+-------+-------+
| All tests passed            | off   | off   | off   | off   |
+-----------------------------+-------+-------+-------+-------+
| External memory test failed | blink | off   | off   | off   |
+-----------------------------+-------+-------+-------+-------+
| I2C EEPROM read failed      | off   | blink | off   | off   |
+-----------------------------+-------+-------+-------+-------+
| EMIF16 NAND read failed     | off   | off   | blink | off   |
+-----------------------------+-------+-------+-------+-------+
| SPI NOR read failed         | off   | off   | off   | blink |
+-----------------------------+-------+-------+-------+-------+
| UART write failed           | blink | blink | off   | off   |
+-----------------------------+-------+-------+-------+-------+
| PLL initialization failed   | off   | off   | blink | blink |
+-----------------------------+-------+-------+-------+-------+
| NAND initialization failed  | blink | blink | blink | off   |
+-----------------------------+-------+-------+-------+-------+
| NOR initialization failed   | off   | blink | blink | blink |
+-----------------------------+-------+-------+-------+-------+
| EMAC loopback failed        | on    | blink | blink | blink |
+-----------------------------+-------+-------+-------+-------+
| Other failures              | blink | blink | blink | blink |
+-----------------------------+-------+-------+-------+-------+

.. raw:: html
