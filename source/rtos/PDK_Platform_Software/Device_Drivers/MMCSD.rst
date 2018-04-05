.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_MMCSD 

.. rubric:: Introduction
   :name: introduction

MMCSD module provides an interface between CPU and any
MMCSD-bus-compatible device that connects via MMCSD serial bus. External
components attached to MMCSD bus can serially transmit/receive data
to/from the CPU device through two-wire interface

.. rubric:: Key Features
   :name: key-features

| Type of transfers

   -   Read
   -   Write
   -   Write followed by read

| Operating modes

   -   Blocking(interrupt or Non interrupt)
   -   Callback mode(interrupt)

| Supports only master mode. Slave mode is not supported

| 

.. rubric:: Driver Configuration
   :name: driver-configuration

.. rubric:: **Board Specific Configuration**
   :name: board-specific-configuration

All board specific configurations eg:enabling clock and pin-mux for
UART pins are required before calling any driver APIs.By default
Board_Init() API supports all initialization sequence for TI supported
EVMs. In addition it initializes UART instance for Console/STDIO.Refer
`Processor SDK RTOS Board
Support <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Board_Support>`__ for
additional details.Once board specific configuration is complete 
MMCSD_init() API can be called to initialize driver.

.. rubric:: **MMCSD Configuration Structure**
   :name: mmcsd-configuration-structure

The MMCSD_soc.c file binds driver with hardware attributes on the
board through MMCSD_config structure. This structure must be 
initialized before the MMCSD_init() function is called and cannot be
changed afterwards. For details about the individual fields of this
structure, see the Doxygen help by opening
\\docs\\doxygen\\html\\index.html

.. rubric:: **APIs**
   :name: apis

Reference for API header file with documentation

::

    #include <ti/drv/mmcsd/MMCSD.h>

.. rubric:: API Call Flow
   :name: api-call-flow

The below sequence indicates the calling sequence of MMCSD driver APIs
for a use case of write transaction in blocking mode:

::

     MMCSD_Handle MMCSD;
     UInt peripheralNum = 0; /* Such as MMCSD0 */
     MMCSD_Params MMCSDParams;
     ...
     MMCSD_Params_init(&MMCSDParams); 
     MMCSD = MMCSD_open(peripheralNum, &MMCSDParams);<br>if (MMCSD == NULL) {<br> /* Error opening MMCSD */
     ...
     readOK = MMCSD_read(MMCSD, rxBuffer , startBlock, numBlock); /* Perform MMCSD read */
     if (!transferOK) { /* MMCSD transaction failed */} 

     writeOK = MMCSD_write(MMCSD, TxBuffer , startBlock, numBlock); /* Perform MMCSD write */
     if (!writeOK) { /* MMCSD transaction failed */} 


.. rubric:: eMMC Usage
   :name: emmc-usage

MMCSD driver supports eMMC device. Application need to configure the
eMMC device for an instance of peripheral. It is also recommended to
configure the operating bus width of eMMC device.

::

    mmcsdInitCfg[MMCSD_INSTANCE].cardType = MMCSD_CARD_EMMC;
    mmcsdInitCfg[MMCSD_INSTANCE].supportedBusWidth = MMCSD_BUS_WIDTH_8BIT;
    MMCSD_init();

.. rubric:: EDMA Usage
   :name: edma-usage

MMCSD driver supports EDMA operations to transfer data between memory
and MMCSD peripheral.

Driver uses separate source files for these operations.Refer source
MMCSD_soc.c for DMA MMCSD SOC configuration. Application need to create
EDMA handle and update the configuration before MMCSD_init() API.

::

    mmcsdInitCfg[MMCSD_INSTANCE].edmaHandle = MMCSDApp_edmaInit();/* Refer Example/Test */
    MMCSD_init();

Refer “MMCSD_[Usecase]_[Board/SoC]_DMA_[cpu][Example/Test]project” for
additional reference. Refer SDK Release Note for supported EVMs.

.. rubric:: UHS Mode Usage
   :name: uhs-mode-usage

The MMCSD driver supports UHS-I cards. Feature is available for AM57x
SOC and is dependent on board or platform support for run-time switching
from 3.0V to 1.8V. Feature is validated on AM572x GP EVM 3.0

.. rubric:: Examples
   :name: examples

+-----------------------+-----------------------+-----------------------+
| Name                  | | Description         | Expected Results      |
+=======================+=======================+=======================+
| MMCSD FATFS Example   | | Example initializes | When a card is        |
| application           |   the card and checks | detected with valid   |
|                       |   for valid FAT       | FAT partition a       |
|                       |   partition. When a   | console interface     |
|                       |   valid FAT partition | apperas like "0:> "   |
|                       |   is detected console |                       |
|                       |   interface for       |                       |
|                       |   command execution   |                       |
|                       |   is provided.        |                       |
|                       |   Console commands    |                       |
|                       |   supported are ls    |                       |
|                       |   (to list files of   |                       |
|                       |   directory), cd      |                       |
|                       |   (change directory), |                       |
|                       |   pwd (present        |                       |
|                       |   working directory)  |                       |
|                       |   and cat (text file  |                       |
|                       |   read operation).    |                       |
+-----------------------+-----------------------+-----------------------+
| MMCSD Test            | |                     | Prints results on     |
| Application           | | Unit Test           | console               |
|                       |   application         | **Pass criteria:**    |
|                       |   demonstrating write | All tests have        |
|                       |   and read a fixed    | passed.               |
|                       |   number of bytes     |                       |
|                       |   into MMCSD card.    |                       |
|                       |   Verifies written    |                       |
|                       |   data pattern to     |                       |
|                       |   conclude PASS/FAIL. |                       |
+-----------------------+-----------------------+-----------------------+
| eMMC Test Application | |                     | Prints results on     |
|                       | | Unit Test           | console               |
|                       |   application         | **Pass criteria:**    |
|                       |   demonstrating write | All tests have        |
|                       |   and read a fixed    | passed.               |
|                       |   number of bytes     |                       |
|                       |   into eMMC device.   |                       |
|                       |   Verifies written    |                       |
|                       |   data pattern to     |                       |
|                       |   conclude PASS/FAIL. |                       |
|                       |                       |                       |
|                       | |                     |                       |
+-----------------------+-----------------------+-----------------------+
| MMC Test Application  | |                     | Prints results on     |
|                       | | Unit Test           | console               |
|                       |   application         | **Pass criteria:**    |
|                       |   demonstrating write | All tests have        |
|                       |   and read a fixed    | passed.               |
|                       |   number of bytes     |                       |
|                       |   into MMC device.    |                       |
|                       |   Verifies written    |                       |
|                       |   data pattern to     |                       |
|                       |   conclude PASS/FAIL. |                       |
|                       |   Supported only on   |                       |
|                       |   OMAPL137 platform.  |                       |
|                       |                       |                       |
|                       | | There is no on-board|                       |
|                       |  eMMC chip on OMAPL137|                       |
|                       |  platform. Need to use|                       |
|                       |  external MMC card    |                       |
|                       |  inserted into MMCSD  |                       |
|                       |  slot of the board.   |                       |
|                       |  Currently the driver |                       |
|                       |  supports standard MMC|                       |
|                       |  card and other cards |                       |
|                       |  like MMCplus may not |                       |
|                       |  work. The example    |                       |
|                       |  requires the card    |                       |
|                       |  size to be at least  |                       |
|                       |  2GB.                 |                       |
|                       |                       |                       |
|                       | |                     |                       |
+-----------------------+-----------------------+-----------------------+


.. rubric:: Additional References
   :name: additional-references

+-----------------------------------+-----------------------------------+
| **Document**                      | **Location**                      |
+-----------------------------------+-----------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)/packages/ti |
|                                   | /drv/mmcsd/docs/doxygen/html/inde |
|                                   | x.html                            |
+-----------------------------------+-----------------------------------+
| Release Notes                     | $(TI_PDK_INSTALL_DIR)/packages/ti |
|                                   | /drv/mmcsd/docs/ReleaseNotes_MMCS |
|                                   | D_LLD.pdf                         |
+-----------------------------------+-----------------------------------+

| 

.. raw:: html

