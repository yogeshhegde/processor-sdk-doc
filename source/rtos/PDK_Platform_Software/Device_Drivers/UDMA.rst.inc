.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_UDMA

Overview
--------

Introduction
^^^^^^^^^^^^

The DMA architecture specifies the data structures used by standard communications
modules to facilitate direct memory access (DMA) and to provide a consistent application programming
interface (API) to the host software in multi-core devices. The data structures and the API used to
manipulate them will be jointly referred to as NAVSS.
For more information on NAVSS DMA architecture, refer to the device Technical Reference Manual

The UDMA driver provides API to program the DMA portion of the NAVSS subsystem
to setup and initiate transfers. Below are the high level features supported by the driver

-  Both Main and MCU NAVSS instances
-  Supports all DMA operations from both instances from all the cores in the SOC
-  UDMAP block copy using native NAVSS channels
-  DRU block copy using direct TR submission to DRU register
-  DRU block copy using indirect (PSIL) TR submission to UDMA external channels
-  PDMA module to initiate transfers to/from PDMA peripherals like UART, McASP, McSPI, ADC, MCAN
-  DMA transfer to/from from native PSIL peripherals like EMAC, CPSW, SA2UL
-  Event and interrupt management like DMA completion, channel chaining, interrupt sharing using IA
-  Resources management across instances and cores for UDMAP DMA channels,RX flow, External UTC channel (DRU), interrupt aggregators (IA), interrupt routers (IR),global events, ring accelerators (RA)
-  Interaction with DMSC RM module via SCICLIENT for all non-RealTime (NRT) configuration
-  Supports both TI-RTOS and baremetal

**Notes**

-  UDMA driver doesn't manage/allocate the descriptor and RA memory.The caller need to allocate and provide the required memory.
-  UDMA driver doesn't use any global variables. All the required object memory like channel, driver instance, event etc should be allocated by the caller

This document has detailed API description that user can use
to make use of the UDMA driver.


User Interface
--------------

Driver Configuration
^^^^^^^^^^^^^^^^^^^^^

.. rubric::  **UDMA Configuration Structure**
   :name: udma-configuration-structure

For details about individual fields of UDMA library structure, see the
Doxygen help by opening
PDK_INSTALL_DIR\\packages\\ti\\drv\\udma\\docs\\doxygen\\html\\index.html.

APIs
^^^^^

The UDMA driver API can be broadly divided into the following categories

-  UDMAP native channel API
-  DRU (External UTC) channel API
-  PDMA channel operations
-  Event and interrupt API
-  Ring API

In addition to above drivers the UDMA package also includes many sample
examples which show how to use the drivers in different ways. Many of
these sample examples use a common set of APIs which a user may find
useful to refer to for use in their final application.

API reference for application:

::

    #include <ti/drv/udma/udma.h>

Application
------------

Examples
^^^^^^^^

+-----------------------+-----------------------+-----------------------+
| Name                  | | Description         | | Expected Results    |
+=======================+=======================+=======================+
| UDMA ADC RX           | | This performs PDMA  | | The application     |
| application           |   RX data capture     |   checks the ADC      |
|                       |   from ADC. ADC is    |   channel ID and      |
|                       |   configured in       |   prints pass on      |
|                       |   single shot mode    |   successful          |
|                       |   and captures        |   completion          |
|                       |   APP_ADC_NUM_CH      |                       |
|                       |   channel of ADC      |                       |
|                       |   data. The FIFO is   |                       |
|                       |   configured to       |                       |
|                       |   generate a DMA      |                       |
|                       |   trigger after       |                       |
|                       |   all channel data    |                       |
|                       |   is captured         |                       |
+-----------------------+-----------------------+-----------------------+
| UDMA Chaining         | | UDMA chaining       | | The application     |
| application           |   sample application  |   checks the          |
|                       |   performing a chain  |   destination buffer  |
|                       |   of block copy using |   with source buffer  |
|                       |   channel global      |   and prints pass on  |
|                       |   trigger: CH0 -> CH1 |   successful          |
|                       |   -> ... -> CHx.      |   completion          |
|                       |   The first channel   |                       |
|                       |   doesn't user a      |                       |
|                       |   global trigger and  |                       |
|                       |   each channel        |                       |
|                       |   triggers the next   |                       |
|                       |   channel's global    |                       |
|                       |   trigger through     |                       |
|                       |   the channel's TR    |                       |
|                       |   event register.     |                       |
|                       |   A channel's source  |                       |
|                       |   buffer is previous  |                       |
|                       |   channel destination |                       |
|                       |   buffer. This        |                       |
|                       |   ensures that        |                       |
|                       |   chaining trigger    |                       |
|                       |   worked in a         |                       |
|                       |   synchronized manner |                       |
|                       |   when the memory     |                       |
|                       |   compare matches     |                       |
+-----------------------+-----------------------+-----------------------+
| UDMA CRC              | | This performs       | | The application     |
| application           |   UDMA CRC operation  |   checks the          |
|                       |                       |   calculated CRC      |
|                       |                       |   value with          |
|                       |                       |   pre-calculated CRC  |
|                       |                       |   value and prints    |
|                       |                       |   pass on successful  |
|                       |                       |   completion          |
|                       |                       |                       |
|                       |                       |                       |
|                       |                       |                       |
+-----------------------+-----------------------+-----------------------+
| UDMA Direct TR DRU    | | UDMA DRU memcpy     | | The application     |
| application           |   sample application  |   checks the          |
|                       |   performing block    |   destination buffer  |
|                       |   copy using direct   |   with source buffer  |
|                       |   TR submission via   |   and prints pass on  |
|                       |   DRU registers       |   successful          |
|                       |                       |   completion          |
+-----------------------+-----------------------+-----------------------+
| UDMA In-Direct TR DRU | | UDMA DRU memory     | | The application     |
| application           |   copy sample         |   checks the          |
|                       |   application         |   destination buffer  |
|                       |   performing block    |   with source buffer  |
|                       |   copy using Type 15  |   and prints pass on  |
|                       |   Transfer Record     |   successful          |
|                       |   (TR15) using        |   completion          |
|                       |   Transfer Record     |                       |
|                       |   Packet Descriptor   |                       |
|                       |   (TRPD)              |                       |
|                       |   for developers.     |                       |
+-----------------------+-----------------------+-----------------------+
| UDMA Blockcopy        | | UDMA memory copy    | | The application     |
| application           |   sample              |   checks the          |
|                       |   application         |   destination buffer  |
|                       |   performing block    |   with source buffer  |
|                       |   copy using Type 15  |   and prints pass on  |
|                       |   Transfer Record     |   successful          |
|                       |   (TR15) using        |   completion          |
|                       |   Transfer Record     |                       |
|                       |   Packet Descriptor   |                       |
|                       |   (TRPD)              |                       |
+-----------------------+-----------------------+-----------------------+






Additional References
---------------------

+-----------------------------------+------------------------------------------------------------+
| **Document**                      | **Location**                                               |
+-----------------------------------+------------------------------------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)\\packages\\ti                        |
|                                   | \\drv\\udma\\docs\\doxygen\\html\\                         |
|                                   | index.html                                                 |
+-----------------------------------+------------------------------------------------------------+
| Migration Guide: EDMA to UDMA     | $(TI_PDK_INSTALL_DIR)\\packages\\ti\\drv\\udma\\docs\\     |
|                                   | Migrating_Applications_from_EDMA_to_UDMA_using_TI-RTOS.pdf |
|                                   |                                                            |
+-----------------------------------+------------------------------------------------------------+

Building UDMA examples
----------------------

-  UDMA examples and dependent libraries are built from the top level udma
   makefile
-  cd <pdk>/packages/ti/drv/udma
-  To build: make -s PDK_INSTALL_PATH=<pdk>/packages
-  To clean: make -s clean PDK_INSTALL_PATH=<pdk>/packages

UDMA examples
-------------

.. rubric::  *Description*
   :name: description

UDMA examples demonstrates the key features of the driver.

|

.. rubric::  **Running the UDMA examples**
   :name: running-the-udma-examples

**CCS connection**:

-  Load the System firmware as specified in SCICLIENT documentation
-  Load the generated executable file in CCS
-  Run the application.
-  The application print will be displayed on the CCS and UART console. The UART console used depends on the core in which the application is run.
