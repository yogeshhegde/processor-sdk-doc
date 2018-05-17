.. http://ap-fpdsp-swapps.dal.design.ti.com/index.php/Processor_SDK_RTOS_I2C_FIRMWARE 

.. rubric::  Introduction
   :name: introduction

| PRU-ICSS-I2C serves as an example for firmware based I2C peripheral
  support. Feature allows additional I2C instances for SOCs. Processor
  SDK package includes source release for Firmware.

| 

.. rubric:: FIRMWARE FEATURES
   :name: firmware-features

PRU-ICSS-I2C firmware supports standard two pin I2C interface through
three GPIO pins from PRU-ICSS peripheral. I2C SCL pin for firmware is
implemented with single GPIO configured in GPI mode. While I2C SDA pin
is implemented with two GPIO pins, one pin configured in GPI mode for
taking input sample and second pin configured in GPO mode for driving
the line. Depending on Baud rate, firmware can emulate multiple instance
of I2C interface from a single PRU core. Following are high level
features:

+-----------------------------------+-----------------------------------+
| **Features**                      | **Remarks**                       |
+-----------------------------------+-----------------------------------+
| No. of instances                  | 4(Standard mode)                  |
|                                   | 1(Fast mode)                      |
|                                   |                                   |
|                                   | 1 (HS mode at 1 MHz)              |
+-----------------------------------+-----------------------------------+
| SMbus Support                     | Supported                         |
+-----------------------------------+-----------------------------------+
| Addressing modes                  | 7/10-bit                          |
+-----------------------------------+-----------------------------------+
| Master Mode                       | Supported                         |
+-----------------------------------+-----------------------------------+
| I2C data transfer rate of from    | 100KHz/400KHz/1MHz                |
| 100 Kbps up to 1 Mbps             |                                   |
+-----------------------------------+-----------------------------------+
| Bit format transfer               | 8 bit                             |
+-----------------------------------+-----------------------------------+
| Number of host interrupts         | 1                                 |
+-----------------------------------+-----------------------------------+
| Peripheral enable/disable         | Supported                         |
| capability                        |                                   |
+-----------------------------------+-----------------------------------+
| Start/Restart/Stop                | Supported                         |
+-----------------------------------+-----------------------------------+
| Built-in configurable FIFOs (8,   | 8/16/32/64/128/256                |
| 16, 32, 64 bytes) for buffered    |                                   |
| read/ write                       |                                   |
+-----------------------------------+-----------------------------------+
| 8-bit-wide data access            | Supported                         |
+-----------------------------------+-----------------------------------+
| Slave reset feature               | Supported                         |
+-----------------------------------+-----------------------------------+
| Internal loopback feature         | Supported                         |
+-----------------------------------+-----------------------------------+
| Slave Mode                        | Not Supported                     |
+-----------------------------------+-----------------------------------+
| Combined Master-Slave             | Not Supported                     |
| Mode/transaction                  |                                   |
+-----------------------------------+-----------------------------------+
| DMA Support                       | Not Supported                     |
+-----------------------------------+-----------------------------------+
| Programmable clock generation     | Not Supported                     |
+-----------------------------------+-----------------------------------+
| Implement Auto Idle mechanism     | Not Supported                     |
| (SOC Specific feature)            |                                   |
+-----------------------------------+-----------------------------------+
| Implement Idle Request/Idle       | Not Supported                     |
| Acknowledge handshake mechanism   |                                   |
| (SOC Specific feature)            |                                   |
+-----------------------------------+-----------------------------------+
| Support for asynchronous wakeup   | Not Supported                     |
| mechanism                         |                                   |
+-----------------------------------+-----------------------------------+

.. rubric::  Code Organization
   :name: code-organization

+-------------------------+--------------------------------------------------+
| **I2C FW Organization** | **Directory**                                    |
+-------------------------+--------------------------------------------------+
| Source Code             | <PDK>/packages/ti/drv/i2c/firmware/icss_i2c/src  |
+-------------------------+--------------------------------------------------+
| Design Guide            | <PDK>/packages/ti/drv/i2c/firmware/icss_i2c/docs |
+-------------------------+--------------------------------------------------+
| Firmware binaries       | <PDK>/packages/ti/drv/i2c/firmware/icss_i2c/bin  |
+-------------------------+--------------------------------------------------+

| 

.. rubric::  Firmware Build Instruction
   :name: firmware-build-instruction

.. rubric::  Build instruction from Processor SDK Release package
   :name: build-instruction-from-processor-sdk-release-package

.. rubric::  Pre-requisites to Building
   :name: pre-requisites-to-building

::

    Refer to the Processor SDK RTOS Building page for information on setting up build environment. 

.. rubric::  Compiling I2C FIRMWARE
   :name: compiling-i2c-firmware

-  cd <PDK>/packages/ti/drv/i2c
-  make firm

Firmware binaries at the end of the build will be located at:

-  <PDK>/packages/ti/drv/i2c/firmware/<FIRMWARE_TYPE>/bin/<SOC>/<HOST_CORE>/<REVISION>

-  <FIRMWARE_TYPE> indicates the firmware type i.e. icss_i2c

-  <SOC> indicates the SOC type.

-  <HOST_CORE> indicates the Host core type on which the built binary
   can be loaded.

-  <REVISION> indicates the revision of the firmware binary based on
   core. (There are 2 revision of PRU-ICSS core)

| 

.. rubric::  Build instruction for GIT
   :name: build-instruction-for-git

Following are the steps for building firmware from any external
environment outside Processor SDK RTOS package.

-  Creation of directories

   -  Create a working directory e.g. <WORK_DIR>
   -  Create a new directory named ti inside working directory. i.e.
      <WORK_DIR/ti>
   -  Create a new directory called drv inside ti. i.e.
      <WORK_DIR/ti/drv>

-  Clone of Repos

   -  Git clone pdk build repo into ti directory. i.e.
      <WORK_DIR/ti/build>
   -  Git clone i2c repo into ti/drv directory. i.e.
      <WORK_DIR/ti/drv/i2c>

-  Setting Environment Variables

   -  Export CLPRU install path. i.e. export CL_PRU_INSTALL_PATH=clpru
      toolchain directory
   -  Export pdk install path. i.e. export PDK_INSTALL_PATH=<WORK_DIR>
   -  Export LIMIT_SOCS Variable i.e. LIMIT_SOCS=<SOC> [Optional for
      limiting to some SOCs]

-  Build command

   -  Run make firm_clean/firm to clean/build firmware from i2c
      directory i.e. <WORK_DIR/ti/drv/i2c>

-  Generated binaries

   -  the firmware binaries which will be located in
      <WORK_DIR/ti/drv/i2c/firmware/<FIRMWARE_TYPE>/bin/<SOC>/<HOST_CORE>/<REVISION>>

| 

.. rubric::  Supported EVMs
   :name: supported-evms

Following are list supported EVMs along with the pin configurations:

+-------------+---------------------+----------------------------------+
| EVM Name    | PRU-ICSS Instance   | Supported PRU ICSS core revision |
+-------------+---------------------+----------------------------------+
| icev2AM335x | PRU-ICSS instance 1 | REV1                             |
+-------------+---------------------+----------------------------------+
| idkAM437x   | PRU-ICSS instance 2 | REV1                             |
+-------------+---------------------+----------------------------------+
| idkAM574x   | PRU-ICSS instance 2 | REV2                             |
+-------------+---------------------+----------------------------------+
| idkAM572x   | PRU-ICSS instance 2 | REV2                             |
+-------------+---------------------+----------------------------------+

| 

.. rubric::  icev2AM335x
   :name: icev2am335x

+---------+-------+----------+--------------+---------------------+--------+-------+
| ICSS    | PRU   | Instance |Functional Pin|PRU GPIO Pins        |EVM Port|EVM pin|
+---------+-------+----------+--------------+---------------------+--------+-------+
|         |       |          | SCL          |pr1_pru0_pru_r30_1   | J3     | 14    |
|         |       |          +--------------+---------------------+--------+-------+
| ICSS1   | PRU0  | I2C0     |              |pr1_edio_data_out7   | J4     | 21    |
|         |       |          | SDA          +---------------------+--------+-------+
|         |       |          |              |pr1_pru0_pru_r31_0   | J3     | 12    |
+---------+-------+----------+--------------+---------------------+--------+-------+

.. rubric::  idkAM572x/idkAM574x
   :name: idkAM572x-idkAM574x

+---------+-------+----------+--------------+---------------------+--------+-------+
| ICSS    | PRU   | Instance |Functional Pin|PRU GPIO Pins        |EVM Port|EVM pin|
+---------+-------+----------+--------------+---------------------+--------+-------+
|         |       |          | SCL          |pr1_pru1_gpo1        | J21    | 5     |
|         |       |          +--------------+---------------------+--------+-------+
| ICSS1   | PRU0  | I2C0     |              |pr1_edio_data_out1   | J46    | 4     |
|         |       |          | SDA          +---------------------+--------+-------+
|         |       |          |              |pr1_pru1_gpi0        | J21    | 3     |
+---------+-------+----------+--------------+---------------------+--------+-------+


.. rubric::  idkAM437x
   :name: idkAM437x

+---------+-------+----------+--------------+---------------------+--------+-------+
| ICSS    | PRU   | Instance |Functional Pin|PRU GPIO Pins        |EVM Port|EVM pin|
+---------+-------+----------+--------------+---------------------+--------+-------+
|         |       |          | SCL          |pr1_pru0_pru_r30_8   | J3     | 6     |
|         |       |          +--------------+---------------------+--------+-------+
|         |       | I2C0     |              |pr1_edio_data_out0   | J3     | 5     |
|         |       |          | SDA          +---------------------+--------+-------+
|         |       |          |              |pr1_pru0_pru_r31_9   | J3     | 8     |
| ICSS1   | PRU0  +----------+--------------+---------------------+--------+-------+
|         |       |          | SCL          |pr1_pru0_pru_r30_10  | J16    | 46    |
|         |       |          +--------------+---------------------+--------+-------+
|         |       | I2C1     |              |pr1_edio_data_out1   | J3     | 7     |
|         |       |          | SDA          +---------------------+--------+-------+
|         |       |          |              |pr1_pru0_pru_r31_11  | J16    | 48    |
+---------+-------+----------+--------------+---------------------+--------+-------+

| 

.. rubric::  I2C FIRMWARE Example
   :name: i2c-firmware-example

 Sample code for initiating I2C FW transaction:

::

    ...
    Board_init(boardCfg);
    ...
    /* Initialize the I2C fw configuration */
    I2C_socInitFwCfg();

    /* Get the default I2C init configurations */
    I2C_socGetFwCfg(I2C_TEST_INSTANCE1, &i2c_cfg);

    /* Modify the default I2C configurations if necessary */

    /* Set the default I2C init configurations */
    I2C_socSetFwCfg(I2C_TEST_INSTANCE1, &i2c_cfg);

    I2C_init();

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

 For SMBUS  transaction:

::

    ...
    testCmd.transferCmd = SMBUS_WRITE_BYTE_CMD;
    testCmd.cmdCode = WRITE_SMBUS_COMMAND_CODE;
    controlStatus = I2C_control(handle, I2C_CMD_SMBUS_TYPE, ((void*)&testCmd));
    I2C_transactionInit(&i2cTransaction);
    ...
    transferOK = I2C_transfer(i2c, &i2cTransaction);
    if (transferOK != I2C_STS_SUCCESS) {
    /* I2C transaction failed */
    } 

| 
.. rubric::  Examples List 
   :name: examples-list

| Refer Release Note for I2C support across different EVMs

+-----------------------+-----------------------+-----------------------+
| Name                  | Description           | Expected Results      |
+=======================+=======================+=======================+
| I2C_FwExampleApplicat | | Driver Firmware     | Following prints will |
| ion                   |   Example application | come on console based |
|                       |   for additional I2C  | on pass/fail          |
|                       |   Instances           | criteria:             |
|                       |                       |                       |
|                       |                       | **Pass criteria:**    |
|                       |                       |                       |
|                       |                       | I2C Test: Instance :  |
|                       |                       | Baud Rate 100KHz:     |
|                       |                       |                       |
|                       |                       | All tests have        |
|                       |                       | passed.               |
+-----------------------+-----------------------+-----------------------+

| 
.. rubric::  Firmware Design Guide 
   :name: firmware-design-guide

+-----------------------------------+-----------------------------------+
| **Document**                      | **Location**                      |
+-----------------------------------+-----------------------------------+
| I2C FIRMWARE Design Guide         | <PDK>/packages/ti/drv/i2c/firmwar |
|                                   | e/icss_i2c/docs/I2C_FW_DESIGN_GUI |
|                                   | DE.pdf                            |
+-----------------------------------+-----------------------------------+

**NOTE: For normal use case, there is no need to refer this document.
Unless you wish to go through the internal working for firmware and/or
wanted to modify it.**

| 

.. raw:: html

