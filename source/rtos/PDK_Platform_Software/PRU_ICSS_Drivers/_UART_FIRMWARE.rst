.. http://ap-fpdsp-swapps.dal.design.ti.com/index.php/Processor_SDK_RTOS_UART_FIRMWARE

Introduction
============

| PRU-ICSS UART serves as an example for PRU firmware-based UART peripheral
  support. The UART firmware (UART FW) allows additional UART instances for SOCs
  beyond those supported by SOC hardware. The Processor SDK package includes
  full source code for UART FW.

|

FIRMWARE FEATURES
=================

The following UART specifications are supported by the PRU UART firmware:

- Up to 3 UARTs are supported per PRU with the following configuration options
    - Baud rate: common baud rates up to 115200
    - Bits per transfer: 5-9 bit characters
    - Number of stop bits: 1, 1.5, 2
    - Parity: even, odd, none
    - Flow control: HW, none (SW flow control currently unsupported)
    - Full-duplex communication

- Each UART can simultaneously support different configurations
    - UART0 can have a different baud rate, number of stop bits, etc. when
      compared to UART1 or UART2 in the same PRU

- The firmware is self-contained in a single PRU
    - The firmware does not use shared resources within an ICSS including IEP Timer and Scratchpad
    - In case 3 or less UART instances are required, only one PRU core is required for the UART firmware

The table below shows a comparison of the features supported by the UART
firmware with those available on hardware IP.

+------------------------------+-------------------------------+----------------------------+
| **UART Supported Feature**   | **Hardware IP**               | **Software IP (Firmware)** |
+------------------------------+-------------------------------+----------------------------+
| Number of hardware instances | SoC dependent                 | 3 (per PRU)                |
+------------------------------+-------------------------------+----------------------------+
| Baud rates                   | SoC dependent (up to 12 Mbps) | All common baud rates      |
|                              |                               | between 300-115200         |
+------------------------------+-------------------------------+----------------------------+
| Bits per character           | 5-8 bits                      | 5-9 bits                   |
+------------------------------+-------------------------------+----------------------------+
| Number of stop bits          | 1, 1.5, 2                     | 1, 1.5, 2                  |
+------------------------------+-------------------------------+----------------------------+
| Parity types                 | Even, Odd, Mark, Space, none  | Even, Odd, none            |
+------------------------------+-------------------------------+----------------------------+
| Flow control types           | HW, SW, none                  | HW, none                   |
+------------------------------+-------------------------------+----------------------------+

Firmware Organization
=====================

+-------------------------+---------------------------------------------------+
| **FW Item**             | **Directory**                                     |
+-------------------------+---------------------------------------------------+
| Source code             | <PDK>/packages/ti/drv/uart/firmware/icss_i2c/src  |
+-------------------------+---------------------------------------------------+
| Design Guide            | <PDK>/packages/ti/drv/uart/docs                   |
+-------------------------+---------------------------------------------------+

|

Firmware Build Instructions
===========================

Build instructions from Processor SDK Release package
-----------------------------------------------------

.. rubric::  Pre-requisites to Building
   :name: uart-pre-requisites-to-building

Refer to the Processor SDK RTOS Building page for information on setting up the build environment.

.. rubric::  Compiling UART Firmware
   :name: uart-compiling-firmware

-  cd <PDK>/packages/ti/drv/uart
-  make firm

.. rubric::  Compiling UART LLD
   :name: uart-compiling-driver

-  cd <PDK>/packages/ti/drv/uart
-  make lib

.. rubric::  Compiling UART Driver & Firmware
   :name: uart-compiling-driver-firmware

-  cd <PDK>/packages/
-  make uart


Firmware binaries at the end of the firmware build will be located at:

-  <PDK>/packages/ti/drv/uart/firmware/<FIRMWARE_TYPE>/bin/<SOC>/<HOST_CORE>/<REVISION>

-  <FIRMWARE_TYPE> indicates the firmware type i.e. icss_uart

-  <SOC> indicates the SOC type, e.g. am335x

-  <HOST_CORE> indicates the Host core type on which the built binary
   can be loaded, e.g. a8host

-  <REVISION> indicates the revision of the firmware binary based on
   core (there are 2 revision of PRU-ICSS core), e.g. REV1.

|

Supported EVMs
==============

Supported EVMs and pin configurations for these EVMs are listed below. See the design document in ``<PDK>/packages/ti/drv/uart/docs/`` for more information.

+-------------+---------------------+-------------------+
| EVM Name    | PRU-ICSS Instances  | PRU-ICSS Revision |
+=============+=====================+===================+
| bbbAM335x   | 6                   | REV1              |
+-------------+---------------------+-------------------+

|

.. rubric::  bbbAM335x
   :name: bbbAM335x

+---------+-------+----------+--------------+---------------------+--------+-------+
| ICSS    | PRU   | Instance |Functional Pin|PRU GPIO Pins        |EVM Port|EVM Pin|
+=========+=======+==========+==============+=====================+========+=======+
|         |       |          | TX           |pr1_pru0_pru_r30_0   | P9     | 31    |
|         |       |          +--------------+---------------------+--------+-------+
|         |       |          | RX           |pr1_pru0_pru_r31_1   | P9     | 29    |
| ICSS1   | PRU0  | UART0    +--------------+---------------------+--------+-------+
|         |       |          | CTS          |         \-          |  \-    |  \-   |
|         |       |          +--------------+---------------------+--------+-------+
|         |       |          | RTS          |         \-          |  \-    |  \-   |
+---------+-------+----------+--------------+---------------------+--------+-------+
|         |       |          | TX           |pr1_pru0_pru_r30_2   | P9     | 30    |
|         |       |          +--------------+---------------------+--------+-------+
|         |       |          | RX           |pr1_pru0_pru_r31_3   | P9     | 28    |
| ICSS1   | PRU0  | UART1    +--------------+---------------------+--------+-------+
|         |       |          | CTS          |         \-          |  \-    |  \-   |
|         |       |          +--------------+---------------------+--------+-------+
|         |       |          | RTS          |         \-          |  \-    |  \-   |
+---------+-------+----------+--------------+---------------------+--------+-------+
|         |       |          | TX           |pr1_pru0_pru_r30_5   | P9     | 27    |
|         |       |          +--------------+---------------------+--------+-------+
|         |       |          | RX           |pr1_pru0_pru_r31_7   | P9     | 25    |
| ICSS1   | PRU0  | UART2    +--------------+---------------------+--------+-------+
|         |       |          | CTS          |         \-          |  \-    |  \-   |
|         |       |          +--------------+---------------------+--------+-------+
|         |       |          | RTS          |         \-          |  \-    |  \-   |
+---------+-------+----------+--------------+---------------------+--------+-------+
|         |       |          | TX           |pr1_pru0_pru_r30_0   | P8     | 45    |
|         |       |          +--------------+---------------------+--------+-------+
|         |       |          | RX           |pr1_pru0_pru_r31_1   | P8     | 46    |
| ICSS1   | PRU1  | UART0    +--------------+---------------------+--------+-------+
|         |       |          | CTS          |pr1_pru1_pru_r31_2   | P8     | 43    |
|         |       |          +--------------+---------------------+--------+-------+
|         |       |          | RTS          |pr1_pru1_pru_r30_3   | P8     | 44    |
+---------+-------+----------+--------------+---------------------+--------+-------+
|         |       |          | TX           |pr1_pru0_pru_r30_4   | P8     | 41    |
|         |       |          +--------------+---------------------+--------+-------+
|         |       |          | RX           |pr1_pru0_pru_r31_5   | P8     | 42    |
| ICSS1   | PRU1  | UART1    +--------------+---------------------+--------+-------+
|         |       |          | CTS          |pr1_pru1_pru_r31_6   | P8     | 39    |
|         |       |          +--------------+---------------------+--------+-------+
|         |       |          | RTS          |pr1_pru1_pru_r30_7   | P8     | 40    |
+---------+-------+----------+--------------+---------------------+--------+-------+
|         |       |          | TX           |pr1_pru0_pru_r30_8   | P8     | 27    |
|         |       |          +--------------+---------------------+--------+-------+
|         |       |          | RX           |pr1_pru0_pru_r31_9   | P8     | 29    |
| ICSS1   | PRU1  | UART2    +--------------+---------------------+--------+-------+
|         |       |          | CTS          |pr1_pru1_pru_r31_10  | P8     | 28    |
|         |       |          +--------------+---------------------+--------+-------+
|         |       |          | RTS          |pr1_pru1_pru_r30_11  | P8     | 30    |
+---------+-------+----------+--------------+---------------------+--------+-------+

|

UART Firmware Example & Test
============================
Example are test applications are available in the package for reference purpose
and starting point.

The example application uses the UART stdio API to repeatedly read characters
transmitted from a PC UART. The acquired characters are then written (echoed)
back to the PC UART.

The test applications are more complex than the example application, and
perform many more types of UART transfers than the example application. The
test applications performs transfers using UART software IP (implemented
in PRU firmware) and hardware IPs with different combinations of UART
settings. Both the UART and UART stdio APIs are exercised (note the UART
software and hardware IPs use the same UART-LLD API). The test applications
are further described in the Firmware Design Guide.

|

Sample code for UART write & read:

::

    /* Refer to UART FW example & tests for details */
    ...

    /* Initialize the UART FW configuration */
    UART_socInitFwCfg();

    Board_init(boardCfg);
    ...

    UART_init();

    /* Get the default UART init configuration */
    UART_socGetFwCfg(uartInst, &uart_cfg);
    /* Modify the default UART configurations if necessary */
    /* Set the default UART init configurations */
    UART_socSetFwCfg(uartInst, &uart_cfg);
    ...

    UART_Params_init(&uartParams);
    uartParams.readCallback = UART_callback;
    uartParams.readMode = UART_MODE_CALLBACK;
    uartParams.writeCallback = UART_callback;
    uartParams.writeMode = UART_MODE_CALLBACK;
    uartParams.parityType = UART_PAR_NONE;
    handle = UART_open(uartInst, &uartParams);
    ...

    /* Initiate UART write */
    UART_transactionInit(&wrCbTransaction);
    wrCbTransaction.buf = (void *)wrBuff;
    wrCbTransaction.count = sizeof(wrBuffer)/2;
    if (UART_write2(handle, &wrCbTransaction) == UART_ERROR) {
        /* UART write failed */
    }
    ...

    /* Initiate UART read */
    UART_transactionInit(&rdCbTransaction);
    rdCbTransaction.buf = (void *)rdBuff;
    rdCbTransaction.count = sizeof(rdBuffer)/2;
    if (UART_read2(handle, &callbackTransaction) == UART_ERROR) {
        /* UART read failed */
    }
|

.. rubric::  List of Examples & Tests
   :name: examples-tests-list

Refer to the Release Notes for details concerning UART support across different EVMs.

+-----------------------+-------------------------+------------------------+
| Name                  | Description             | Expected Results       |
+=======================+=========================+========================+
| UART_FwExample        | Example application     | Status messages will   |
|                       | for PRU UART FW driver  | be displayed on        |
|                       |                         | console based based    |
|                       |                         | on pass/fail criteria: |
|                       |                         |                        |
|                       |                         | **Pass criteria:**     |
|                       |                         |                        |
|                       |                         | All Passed             |
+-----------------------+-------------------------+------------------------+
| UART_FwTest           | Simple test application | Status messages will   |
|                       | for PRU UART FW driver  | be displayed on        |
|                       |                         | console based on       |
|                       |                         | pass/fail criteria:    |
|                       |                         |                        |
|                       |                         | **Pass criteria:**     |
|                       |                         |                        |
|                       |                         | All tests have         |
|                       |                         | passed.                |
+-----------------------+-------------------------+------------------------+
| UART_FwTestExtLb      | More complex test       | Status messages will   |
|                       | test application        | be displayed on        |
|                       | for PRU UART FW driver, | console based on       |
|                       | superset of UART_FwTest | pass/fail criteria:    |
|                       |                         |                        |
|                       |                         | **Pass criteria:**     |
|                       |                         |                        |
|                       |                         | All tests have         |
|                       |                         | passed.                |
+-----------------------+-------------------------+------------------------+

|

.. rubric::  Firmware Design Guide
   :name: firmware-design-guide

+-----------------------------------+----------------------------------------------------------+
| **Document**                      | **Location**                                             |
+-----------------------------------+----------------------------------------------------------+
| UART Firmware Design Guide        | <PDK>/packages/ti/drv/uart/docs/UART_FW_DESIGN_GUIDE.pdf |
+-----------------------------------+----------------------------------------------------------+

**NOTE: Design document includes details for internal firmware implementation and
can be used in case of modification required for firmware.**


|

