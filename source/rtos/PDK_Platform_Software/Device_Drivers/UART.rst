.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_UART 

| .. rubric:: **Overview**          | .. rubric:: **User Interface**    |
|    :name: overview                |    :name: user-interface          |
|                                   |                                   |
| -  `Introduction </index.php/Proc | -  `Driver                        |
| essor_SDK_RTOS_UART#Introduction> |    Configuration </index.php/Proc |
| `__                               | essor_SDK_RTOS_UART#Driver_Config |
| -  `Additional                    | uration>`__                       |
|    References </index.php/Process | -  `APIs </index.php/Processor_SD |
| or_SDK_RTOS_UART#Additional_Refer | K_RTOS_UART#APIs>`__              |
| ences>`__                         |                                   |
+-----------------------------------+-----------------------------------+
| .. rubric:: **Application**       | .. rubric:: **Debug**             |
|    :name: application             |    :name: debug                   |
|                                   |                                   |
| -  `Examples </index.php/Processo |                                   |
| r_SDK_RTOS_UART#Example>`__       |                                   |
+-----------------------------------+-----------------------------------+

| 

.. rubric:: Introduction
   :name: introduction

| Driver enables UART's available on SOC for reading and writing to any
  peripherals on board. Additionally it supports simple APIs for
  Console/STDIO operations.

.. rubric:: Modes of Operation
   :name: modes-of-operation

Following modes of operations are supported

**UART_MODE_BLOCKING**: In this mode, read and write APIs, blocks on
semaphore until required operation is complete. By default, UART driver
operates in blocking mode. In this mode, code execution of a task blocks
until UART transaction is complete. While transaction is in progress
additional tasks pending requests will remain in blocked state waiting
for semaphore.

| **UART_MODE_CALLBACK**: In this mode, read and write operation returns
  immediately. On trigger of hardware Interrupt (hwi) callback function
  gets triggered.

.. rubric:: Driver Configuration
   :name: driver-configuration

.. rubric:: **Board Specific Configuration**
   :name: board-specific-configuration

All board specific configurations eg:enabling clock and pin-mux for UART
pins are required before calling any driver APIs.By default Board_Init()
API supports all initialization sequence for TI supported EVMs. In
addition it initializes UART instance for Console/STDIO.Refer `Processor
SDK RTOS Board Support </index.php/Processor_SDK_RTOS_Board_Support>`__
for additional details.Once board specific configuration is complete 
UART_init() API can be called to initialize driver.

.. rubric:: **UART Configuration Structure**
   :name: uart-configuration-structure

The UART_soc.c file binds driver with hardware attributes on the board
through UART_config structure. This structure must be provided to UART
driver. It must be initialized before the UART_init() function is called
and cannot be changed afterwards. For details about individual fields of
this structure, see the Doxygen help by opening
PDK_INSTALL_DIR\packages\ti\drv\uart\docs\doxygen\html\index.html.

.. rubric:: **APIs**
   :name: apis

API reference for application:

::

    #include <ti/drv/uart/UART.h>

STDIO API reference for application:

::

    #include <ti/drv/uart/UART_stdio.h>

.. rubric:: Open UART
   :name: open-uart

There are three ways to open a UART instance:

1. UART_open()

::

    ...
    Board_init(boardCfg);
    ...
    UART_socGetInitCfg(UART_INSTANCE, &uart_cfg);
    ...
    UART_socSetInitCfg(UART_INSTANCE, &uart_cfg);
    ...
    UART_Params_init(&params);
    ...
    handle = UART_open(UART_INSTANCE, &params);

| At this point UART driver is ready for data transfer on specific
  instance identified by handle. Application can call UART_read/write
  API for read/write operation

2. UART_stdioInit() using the default UART parameters

::

    ...
    Board_init(boardCfg);
    ...
    UART_socGetInitCfg(UART_INSTANCE, &uart_cfg);
    ...
    UART_socSetInitCfg(UART_INSTANCE, &uart_cfg);
    ...
    UART_stdioInit(UART_INSTANCE);

| At this point UART driver is ready for data transfer on specific
  instance. Application can call UART_printf/scanFmt API for read/write
  operation

3. UART_stdioInit2() using Application specified UART parameters

::

    ...
    Board_init(boardCfg);
    ...
    UART_socGetInitCfg(UART_INSTANCE, &uart_cfg);
    ...
    UART_socSetInitCfg(UART_INSTANCE, &uart_cfg);
    ...
    UART_Params_init(&params);
    ...
    UART_stdioInit2(UART_INSTANCE, &params);

| At this point UART driver is ready for data transfer on specific
  instance. Application can call UART_printf/scanFmt API for read/write
  operation

.. rubric:: Read/Write APIs
   :name: readwrite-apis

**Interrupt**:

::

    UART_read(handle,scanPrompt, sizeof(scanPrompt));/* Read API */ 
    ... 
    UART_write(handle, bufferPrompt, sizeof(bufferPrompt));/* Write API */ 

    Or

    UART_transactionInit(&transaction);
    transaction.buf = (void *)scanPrompt;
    transaction.count = sizeof(scanPrompt);
    UART_read2(uart, &transaction);
    ...
    UART_transactionInit(&transaction);
    transaction.buf = (void *)bufferPrompt;
    transaction.count = sizeof(bufferPrompt);
    UART_write2(uart, &transaction);

**Polling**:

::

    UART_readPolling(handle,scanPrompt, sizeof(scanPrompt));/* Read Polling mode API */
    ... 
    UART_writePolling(handle, bufferPrompt, sizeof(bufferPrompt));/* Write Polling API */ 

.. rubric:: EDMA Usage :
   :name: edma-usage

UART driver supports EDMA operations to transfer data between

-  Memory and RX FIFO for read transfer
-  Memory and TX FIFO for write transfer.

Driver uses separate source files for these operations.Refer source
UART_soc_dma.c for DMA UART SOC configuration. Application need to
create EDMA handle and update the configuration before UART_init() API.

::

    uartInitCfg[UART_INSTANCE].edmaHandle = UartApp_edmaInit();/* Refer Example/Test */
    UART_init();

| Refer “UART_BasicExample_[SOC]_[cpu]DMATestproject” for additional
  reference. Refer SDK Release Note for supported EVMs.

.. rubric:: Example
   :name: example

+-----------------------+-----------------------+-----------------------+
| Name                  | Description           | Expected Results      |
+=======================+=======================+=======================+
| UART_Example          | | Example             | | Application prompts |
| application           |   demonstrating       |   user to enter input |
|                       |   *simple* UART use   |   data in console.    |
|                       |   case. Reference     |                       |
|                       |   example for         | | User can enter up   |
|                       |   developers          |   to 16 characters or |
|                       |                       |   terminate with      |
|                       |                       |   enter               |
|                       |                       |   key.Application     |
|                       |                       |   echoes back         |
|                       |                       |   characters.         |
+-----------------------+-----------------------+-----------------------+
| UART_TestApplication  | | Unit Test           | User can enter up to  |
|                       |   application to test | 16 characters using   |
|                       |   all APIs            | serial                |
|                       |                       | console.Application   |
|                       |                       | echoes back           |
+-----------------------+-----------------------+-----------------------+
| UART_DMATestApplicati | | Unit Test           | User can enter up to  |
| on                    |   application with    | 16 characters using   |
|                       |   DMA mode.           | serial                |
|                       |                       | console.Application   |
|                       |                       | echoes back           |
+-----------------------+-----------------------+-----------------------+

.. rubric:: Additional References
   :name: additional-references

+-----------------------------------+-----------------------------------+
| **Document**                      | **Location**                      |
+-----------------------------------+-----------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\uart\docs\doxygen\html\index |
|                                   | .html                             |
+-----------------------------------+-----------------------------------+
| Release Notes                     | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\uart\docs\ReleaseNotes_UART_ |
|                                   | LLD.pdf                           |
+-----------------------------------+-----------------------------------+

.. raw:: html

