.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_I2C

.. rubric::  Introduction
   :name: introduction

I2C module provides an interface to any I2C-bus-compatible device
accessible via I2C serial bus. External components attached to I2C bus
can serially transmit/receive data to/from the CPU through two-wire
interface. Driver supports three types of transfers in both I2C master
mode and slave mode

-  Read
-  Write
-  Write followed by read

In addition driver supports following modes of operation:

-  **I2C_MODE_BLOCKING:** By default, driver operates in blocking mode.
   In blocking mode, a Task’s code execution is blocked until
   transaction is complete. This ensures only one transaction operates
   at a given time. Driver supports both interrupt or non-interrupt
   based blocking modes.
-  **I2C_MODE_CALLBACK** In callback mode, an I2C transaction functions
   asynchronously, which means that it does not block a Task’s code
   execution. After an I2C transaction is complete, I2C driver calls a
   user-provided hook function. Only interrupt based callback is
   supported.

.. raw:: html

   <div
   style="margin: 5px 25px; padding: 2px 10px; background-color: #ecffff; border-top: 1px solid #3399ff; border-bottom: 1px solid #3399ff;">

**NOTE**

If I2C peripheral is in reset during a transfer, it can cause the I2C
bus to hang. I2C V0 IP (Keystone SoCs) does not have hardware support to
recover the I2C bus from hanging, user needs to power cycle the board as
a workaround. For I2C V1 IP (AM3/4/5 SoCs), the application can call
I2C_control() API and use I2C_CMD_RECOVER_BUS to recover the I2C bus.

.. raw:: html

   </div>

.. rubric::  Firmware
   :name: firmware

TI PRU-ICSS cores (Programmable Real-Time Unit Industrial Communication
Subsystem) is firmware programmable and can take on various
personalities. Processor SDK package includes I2C Firmware support.
Refer `I2C FW <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_I2C_FIRMWARE>`__ for
additional details.

| 

.. rubric::  Driver Configuration
   :name: driver-configuration

.. rubric::  **Board Specific Configuration**
   :name: board-specific-configuration

All the board specific configurations eg:enabling and pin-mux of I2C
pins should be performed before calling any driver APIs.By default
Board_Init() API supports all initialization sequence for TI supported
EVMs.Refer `Processor SDK RTOS Board
Support <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Board_Support>`__ for additional
details.

Once the board specific configuration is complete driver API I2C_init()
can be called to initialize driver

.. rubric::  **I2C Configuration Structure**\ 
   :name: i2c-configuration-structure

I2C_soc.c file binds driver with hardware attributes on the board
through I2C_config structure. This structure must be provided to I2C
driver. It must be initialized before the I2C_init() function is called
and cannot be changed afterwards. For details about the individual
fields of this structure, see the Doxygen help by opening
PDK_INSTALL_DIR\packages\ti\drv\i2c\docs\doxygen\html\index.html.

.. rubric::  **APIs**
   :name: apis

API reference for application:

::

    #include <ti/drv/i2c/I2C.h>

 Sample code for initiating I2C transaction:

::

    ...
    Board_init(boardCfg);
    ...
    I2C_socGetInitCfg(peripheralNum, &i2c_cfg);
    ...
    I2C_socSetInitCfg(peripheralNum, &i2c_cfg);
    ...
    i2c = I2C_open(peripheralNum, &i2cParams);
    ...
    ...

    /* Initiate I2C transfers. Refer Example for details
    */
    I2C_transactionInit(&i2cTransaction);
    transaction.masterMode   = true;
    ...
    ...
    transferOK = I2C_transfer(i2c, &i2cTransaction);
    if (transferOK != I2C_STS_SUCCESS) {
    /* I2C transaction failed */
    } 

.. rubric::  Examples
   :name: examples

| Refer Release Note for I2C support across different EVMs

+-----------------------+-----------------------+-----------------------+
| Name                  | Description           | Expected Results      |
+=======================+=======================+=======================+
| I2C_EepromRead        | Simple example to     | Following prints will |
| Example application   | read fixed number     | come on console based |
|                       | of bytes from         | on pass/fail          |
|                       | EEPROM on board and   | criteria:             |
|                       | compares it with      |                       |
|                       | expected data.        | **Pass criteria:**    |
|                       |                       |                       |
|                       |                       | EEPROM data matched   |
|                       |                       | All tests have        |
|                       |                       | passed.               |
+-----------------------+-----------------------+-----------------------+
| I2C_TestApplication   | Driver Unit Test      | Following prints will |
|                       | application for       | come on console based |
|                       | additional I2C        | on pass/fail          |
|                       | speed                 | criteria:             |
|                       |                       |                       |
|                       |                       | **Pass criteria:**    |
|                       |                       |                       |
|                       |                       | I2C Test: 400Kbps:    |
|                       |                       | PASS                  |
|                       |                       |                       |
|                       |                       | I2C Test: 100Kbps:    |
|                       |                       | PASS                  |
|                       |                       |                       |
|                       |                       | All tests have        |
|                       |                       | passed.               |
+-----------------------+-----------------------+-----------------------+
| I2C_TemperatureSensor | Example to get the    | Following prints will |
|                       | temperature value     | come on console based |
|                       | from the temperature  | on pass/fail          |
|                       | sensor and displays   | criteria:             |
|                       | on the serial         |                       |
|                       | console.              | **Pass criteria:**    |
|                       |                       |                       |
|                       |                       | Temperature =         |
|                       |                       | "value in             |
|                       |                       | centigrades" C        |
|                       |                       | All tests have        |
|                       |                       | passed.               |
+-----------------------+-----------------------+-----------------------+
| I2C_master/slave      | Application           | Following prints will |
|                       | demonstrates          | come on console based |
|                       | master/slave          | on pass/fail          |
|                       | transfer of I2C.      | criteria:             |
|                       | Application use       |                       |
|                       | case requires two     | **Pass criteria:**    |
|                       | EVMs. One acts as     |                       |
|                       | Master and the        | All tests have        |
|                       | other as slave. I2C   | passed.               |
|                       | connections           |                       |
|                       | information and       |                       |
|                       | addtional details     |                       |
|                       | are as follows:       |                       |
|                       |                       |                       |
|                       | AM57xx boards I2C bus |                       |
|                       | connection on J9      |                       |
|                       | (master board <-->    |                       |
|                       | slave board)          |                       |
|                       |                       |                       |
|                       | pin22 (SCL)<-->       |                       |
|                       | pin22 (SCL)           |                       |
|                       |                       |                       |
|                       | pin24 (SDA)<--> pin24 |                       |
|                       | (SDA)                 |                       |
|                       |                       |                       |
|                       | pin21 (GND)<--> pin21 |                       |
|                       | (GND)                 |                       |
|                       |                       |                       |
|                       | K2G boards I2C bus    |                       |
|                       | connection on J12     |                       |
|                       | (master board <-->    |                       |
|                       | slave board)          |                       |
|                       | pin28 (SCL)<-->       |                       |
|                       | pin28 (SCL)           |                       |
|                       | pin30 (SDA)<-->       |                       |
|                       | pin30 (SDA)           |                       |
|                       | pin50 (GND)<-->       |                       |
|                       | pin50 (GND)           |                       |
|                       |                       |                       |
|                       |                       |                       |
|                       | OMAPL138/C6748        |                       |
|                       | boards I2C bus        |                       |
|                       | connection on J15     |                       |
|                       | (master board <-->    |                       |
|                       | slave board)          |                       |
|                       | pin13 (SCL)<-->       |                       |
|                       | pin13 (SCL)           |                       |
|                       | pin15 (SDA)<-->       |                       |
|                       | pin15 (SDA)           |                       |
|                       | pin35 (GND)<-->       |                       |
|                       | pin35 (GND)           |                       |
|                       |                       |                       |
|                       | Run                   |                       |
|                       | "I2C_Slave_<BoardTy   |                       |
|                       | pe>_<arm/c66x/m4>Test |                       |
|                       | Project"              |                       |
|                       | first on Slave EVM    |                       |
|                       | and then              |                       |
|                       | "I2C_Master_<BoardT   |                       |
|                       | ype>_<arm/c66x/m4>Tes |                       |
|                       | tProject"             |                       |
|                       | on Master EVM.        |                       |
+-----------------------+-----------------------+-----------------------+

.. raw:: html

   <div
   style="margin: 5px 25px; padding: 2px 10px; background-color: #ecffff; border-top: 1px solid #3399ff; border-bottom: 1px solid #3399ff;">

**NOTE**

I2C_Test Application supports write test on Keystone II EVMs, by default
write test is disabled, user can enable the write test by defining
I2C_EEPROM_WRITE_ENABLE in test/eeprom_read/src/I2C_board.h.
I2C_TemperatureSensor Application is supported only on AM572x GP EVM.

.. raw:: html

   </div>

.. rubric::  Additional References
   :name: additional-references

+-----------------------------------+-----------------------------------+
| **Document**                      | **Location**                      |
+-----------------------------------+-----------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\i2c\docs\doxygen\html\index. |
|                                   | html                              |
+-----------------------------------+-----------------------------------+
| Release Notes                     | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\i2c\docs\ReleaseNotes_I2C_LL |
|                                   | D.pdf                             |
+-----------------------------------+-----------------------------------+

.. raw:: html