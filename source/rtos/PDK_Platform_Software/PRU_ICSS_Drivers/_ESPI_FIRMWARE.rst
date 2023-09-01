.. http://ap-fpdsp-swapps.dal.design.ti.com/index.php/Processor_SDK_RTOS_ESPI_FIRMWARE

Introduction
============

| PRU-ICSS eSPI serves as an example for firmware-based eSPI peripheral
  support. The Processor SDK package includes full source code for eSPI FW.

|

Firmware Organization
=====================

+-------------------------+--------------------------------------------------+
| **FW Item**             | **Directory**                                    |
+=========================+==================================================+
| Source code             | <PDK>/packages/ti/drv/spi/firmware/icss_espi/src/|
+-------------------------+--------------------------------------------------+
| Design Guide            | <PDK>/packages/ti/drv/spi/docs/                  |
+-------------------------+--------------------------------------------------+

Firmware Build Instruction
==========================

Build instruction from Processor SDK Release package
----------------------------------------------------
.. rubric::  Pre-requisites to Building
   :name: espi-pre-requisites-to-building

Refer to the Processor SDK RTOS Building page for information on setting up the build environment.

.. rubric::  Compiling Driver/Firmware
   :name: espi-compiling-driver-firmware
   
1. ``make spi``

   
.. rubric::  Running CCS Application
   :name: espi-run-app

CCS applications will be build and run just like any other project with one exception. Before loading the binary, from the menu-bar run ``Scripts > PRU_ICSS > PRU_ICSS_Init``.

Supported EVMs
==============

Supported EVMs and pin configurations for these EVMs are listed below. See the design document in ``<PDK>/packages/ti/drv/spi/docs/`` for more information.

+-------------+---------------------+-------------------+
| EVM Name    | PRU-ICSS Instances  | PRU-ICSS Revision |
+=============+=====================+===================+
| bbbAM335x   | 1                   | REV1              |
+-------------+---------------------+-------------------+
| idkAM437x   | 2                   | REV1              |
+-------------+---------------------+-------------------+


.. rubric::  bbbAM335x
   :name: espi-bbbam335x

+---------+-------+----------------+----------------------+----------+---------+
| Core    | PRU   | Functional Pin | GPIO Pins            | EVM Port | EVM Pin |
+=========+=======+================+======================+==========+=========+
|         |       | OUT[0]         | pr1_pru0_pru_r30_4   | J3       | 41      |
|         |       +----------------+----------------------+----------+---------+ 
|         |       | OUT[1]         | pr1_pru0_pru_r30_5   | J3       | 42      |
|         |       +----------------+----------------------+----------+---------+ 
|         |       | OUT[2]         | pr1_pru0_pru_r30_6   | J3       | 39      |
|         |       +----------------+----------------------+----------+---------+ 
|         |       | OUT[3]         | pr1_pru0_pru_r30_7   | J3       | 40      |
|         |       +----------------+----------------------+----------+---------+ 
|         |       | Alert          | pr1_pru0_pru_r30_9   | J3       | 29      |
|         |       +----------------+----------------------+----------+---------+
| ICSS1   | PRU1  | EN             | pr1_pru0_pru_r30_10  | J3       | 28      |
|         |       +----------------+----------------------+----------+---------+
|         |       | IN[0]          | pr1_pru0_pru_r30_0   | J3       | 45      |
|         |       +----------------+----------------------+----------+---------+
|         |       | IN[1]          | pr1_pru0_pru_r30_1   | J3       | 46      |
|         |       +----------------+----------------------+----------+---------+ 
|         |       | IN[2]          | pr1_pru0_pru_r30_2   | J3       | 43      |
|         |       +----------------+----------------------+----------+---------+ 
|         |       | IN[3]          | pr1_pru0_pru_r30_3   | J3       | 44      |
|         |       +----------------+----------------------+----------+---------+ 
|         |       | SCL            | pr1_pru0_pru_r30_8   | J3       | 27      |
|         |       +----------------+----------------------+----------+---------+ 
|         |       | CS             | pr1_pru0_pru_r30_11  | J3       | 30      |
+---------+-------+----------------+----------------------+----------+---------+
| A8      | n/a   | Reset          | GPIO_3_19            | J9       | 26      |
+---------+-------+----------------+----------------------+----------+---------+

.. rubric::  idkAM437x
   :name: espi-idkAM437x

+---------+-------+----------------+----------------------+----------+---------+
| Core    | PRU   | Functional Pin | GPIO Pins            | EVM Port | EVM Pin |
+=========+=======+================+======================+==========+=========+
|         |       | OUT[0]         | pr1_pru0_pru_r30_6   | P16      | 49      |
|         |       +----------------+----------------------+----------+---------+ 
|         |       | Alert          | pr1_pru0_pru_r30_11  | P16      | 48      |
|         |       +----------------+----------------------+----------+---------+
| ICSS1   | PRU0  | EN             | pr1_pru0_pru_r30_8   | P16      | 6       |
|         |       +----------------+----------------------+----------+---------+
|         |       | IN[0]          | pr1_pru0_pru_r30_16  | P16      | 42      |
|         |       +----------------+----------------------+----------+---------+ 
|         |       | SCL            | pr1_pru0_pru_r30_10  | P16      | 46      |
|         |       +----------------+----------------------+----------+---------+ 
|         |       | CS             | pr1_pru0_pru_r30_9   | P16      | 8       |
+---------+-------+----------------+----------------------+----------+---------+
| A9      | n/a   | Reset          | GPIO_5_9             | P16      | 32      |
+---------+-------+----------------+----------------------+----------+---------+


eSPI Applications
=================

We have included a simple example test application which handles PUT_IORD_SHORT,
PUT_IOWR_SHORT, PUT_MEMRD32_SHORT, and PUT_MEMWR32_SHORT packets with expected
address/data values. This can be used as a starting point to build your own
applications, along with the following:

- eSPI uses the MCSPI API

   - Open as MCSPI instance 2

- HW interrupts must be enabled

   - i.e. HwiP_enableInterrupt(espi_cfg.intNum)

- MCSPI_transfer() is blocking and takes a SPI_Transaction parameter which is
  used as follows:

   - RX Transfer:

      - transaction.rxBuf = <some pre-allocated buffer>

      - transaction.txBuf = Null

      - transaction.count = max packet size

   - TX Transfer:

      - transaction.rxBuf = Null

      - transaction.txBuf = <some pre-allocated buffer>

      - transaction.count = <size of packet>

- The application must parse the full eSPI packet, and must respond with the
  full proper eSPI packet (the RSP code and CRC will be taken care of by the
  firmware)

.. rubric::  example-application
   :name: espi-example-application

.. code-block:: c

    /* Refer to eSPI FW Example for details */

    Board_init(boardCfg);

    ...
    
    /* Initialize the ESPI fw configuration */
    ESPI_socInitFwCfg();

    /* Get the default ESPI init configurations */
    ESPI_socGetFwCfg(ESPI_INSTANCE, &espi_cfg);

    /* Modify the default eSPI configurations if necessary */

    /* Set the default ESPI init configurations */
      ESPI_socSetFwCfg(ESPI_INSTANCE, &espi_cfg);

    /* Set GPIO pin configurations */
    GPIO_setConfig(ESPI_GPIO_PIN_RESET, GPIO_DEVICE_CONFIG(espi_cfg.resetPin.port,
    						    espi_cfg.resetPin.pinNum) |
    		 GPIO_CFG_IN_INT_RISING | GPIO_CFG_INPUT);

    /* Initialize GPIO */
    GPIO_init();

    /* Initialize the MCSPI paramters */
    MCSPI_Params_init(&mcspiParams);

    /* Init SPI driver */
    MCSPI_init();

    /* Enable interrupts (necessary for  */
    HwiP_enableInterrupt(espi_cfg.intNum);

    /* Grab ESPI handle from SoC config list */
    fwHandle = (MCSPI_Handle)MCSPI_open(ESPI_INSTANCE, 0, &mcspiParams);

    ...

    /* Read ESPI Packet */
    transaction.txBuf = NULL; /* indicates we want RX */
    transaction.rxBuf = (uint8_t*) rxBuf;
    transaction.count = ESPI_PACKET_MAX_SIZE;
    retVal = MCSPI_transfer(fwHandle, &transaction);  /* blocking */

    ...
    
    /* Prepare TX response */
    transaction.txBuf = (uint8_t*) txBuf;
    transaction.rxBuf = NULL; /* indicates we want TX */
    transaction.count = ESPI_PACKET_MAX_SIZE;

    ...

    /* Put response in TX queue */
    retVal = MCSPI_transfer(fwHandle, &transaction);

    ...

.. rubric::  Examples List 
   :name: examples-list

Refer to the Release Notes for details concerning eSPI support across different EVMs.

+-----------------------+-----------------------+---------------------------+
| Name                  | Description           | Expected Results          |
+=======================+=======================+===========================+
| ESPI_FwExample        | Driver Firmware       | A short write to 0xDEAD   |
|                       | example application   | or 0x0D0E0A0D will not    |
|                       | for ESPI FW instances | print or return anything. |
|                       |                       | A short read from 0xDEAD  |
|                       |                       | or 0x0D0E0A0D will return |
|                       |                       | the command opcode + the  |
|                       |                       | byte-number of the        |
|                       |                       | response. A read from any |
|                       |                       | other address will return |
|                       |                       | the opcode minus the      |
|                       |                       | byte-number of the        |
|                       |                       | response.                 |
+-----------------------+-----------------------+---------------------------+

| 

.. rubric::  Firmware Design Guide 
   :name: firmware-design-guide

+-----------------------------------+---------------------------------------------------------+
| **Document**                      | **Location**                                            |
+===================================+=========================================================+
| eSPI FIRMWARE Design Guide        | <PDK>/packages/ti/drv/spi/docs/ESPI_FW_DESIGN_GUIDE.doc |
+-----------------------------------+---------------------------------------------------------+

**NOTE: For normal use of eSPI FW, there is no need to refer to the design guide.
This document can be cosulted in case of interest in details of internal firmware 
operation, or a desire to modify the firmware.**

