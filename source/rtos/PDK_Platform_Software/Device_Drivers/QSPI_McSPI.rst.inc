Introduction
=============

SPI driver enables communication for general SPI, MCSPI (Multichannel
SPI) and QSPI (Quad SPI) based peripherals on board through common API
to application.
MCSPI is a generic full-duplex interface supporting transmit and
receive of data over SPI bus. QSPI a variant of SPI supports four
receive data lanes. Driver supports configuration for either single,
dual or quad data lanes

Modes of Operation
===================

Following modes of operations are supported:

**SPI_MODE_BLOCKING**
*SPI_transfer()* API blocks code execution until transaction has
completed. By default, SPI driver operates in blocking mode. This
ensures only one SPI transaction operates at a given time. This mode
is supported in both interrupt or non-interrupt configurations.

**SPI_MODE_CALLBACK**
*SPI_transfer()* API returns without waiting for completion of
transaction in this case. Callback function registered by application
is invoked once transaction is complete.This mode is supported only in
interrupt configuration.

Driver Configuration
======================

Board Specific Configuration
-----------------------------

All board specific configurations eg:enabling clock and pin-mux for SPI
pins are required before calling any driver APIs.By default Board_Init()
API supports all initialization sequence for TI supported EVMs. In
addition it initializes UART instance for Console/STDIO.Refer `Processor
SDK RTOS Board Support <Board_EVM_Abstration.html#board-support>`__
for additional details.Once board specific configuration is
complete \ *SPI_init()* API should be called to initialize driver.

SoC Specific Configuration
---------------------------

All SoC specific configurations (eg: SPI module registers base address,
interrupt configurations, etc.) can be set using SPI_socSetInitCfg() SoC
driver API before calling any SPI driver APIs. The default SoC specific
configurations can be retrieved using SPI_socGetInitCfg() SoC driver
API. 

SPI Configuration Structure
-----------------------------

The *SPI_soc.c* file binds driver with hardware attributes on the board
through *SPI_config[]* structure. This structure must be provided to the
SPI driver. It must be initialized before the *SPI_init()* function is
called and cannot be changed afterwards. For details about individual
fields of this structure, see Doxygen help by opening
*PDK_INSTALL_DIR\packages\ti\drv\spi\docs\doxygen\html\index.html.*

Driver  requires common *SPI_config[]*  to configure hardware attributes
of MCSPI and QSPI peripherals on SOC and board. First all MCSPI related
hardware attributes is defined  followed by QSPI hardware attributes.
Application will need to include appropriate offset to instance while
invoking *SPI_open()* API..

APIs
=====

API Reference for application:

::

    #include <ti/drv/spi/SPI.h>

SPI IP V1 driver also supports multi-channel API's:

::

    #include <ti/drv/spi/MCSPI.h> 

.. rubric:: 
   :name: section

Open SPI
---------

::

    ...
    Board_init(boardCfg);
    ...
    SPI_socGetInitCfg(peripheralNum, &spi_cfg);
    ...
    SPI_socSetInitCfg(peripheralNum, &spi_cfg);
    SPI_Params_init(&spiParams);
    spiParams.transferMode = SPI_MODE_BLOCKING;
    spiParams.transferCallbackFxn = NULL;
    handle = SPI_open(peripheralNum, &spiParams);

SPI IP V1 driver also supports multi-channel open API's:

::

    ...
    Board_init(boardCfg);
    ...
    MCSPI_Params_init(&spiParams);
    spiParams.transferMode = SPI_MODE_BLOCKING;
    spiParams.transferCallbackFxn = NULL;
    handle = MCSPI_open(peripheralNum, channel, &spiParams);

| 
At this point SPI driver is ready for data transfer in blocking mode
on specific instance identified by handle. Pseudo/Sample code for
SPI read/write transaction is included below. Refer example for
additional details

::

    ...
    spiTransaction.count = n;    /* Transfer Length */
    spiTransaction. txBuf = transmitBuffer; /* Buffer to be written */
    spiTransaction.rxBuf = NULL;  /* Buffer holding the received data */
    transferOK = SPI_transfer(spi, &spiTransaction); /* Perform SPI transfer */
    if (!transferOK) {
    /* SPI transaction failed */
    }

SPI IP V1 driver also supports multi-channel transfer API's:

::

    ...
    spiTransaction.count = n;    /* Transfer Length */
    spiTransaction. txBuf = transmitBuffer; /* Buffer to be written */
    spiTransaction.rxBuf = NULL;  /* Buffer holding the received data */
    transferOK = MCSPI_transfer(spi, &spiTransaction); /* Perform SPI transfer */
    if (!transferOK) {
    /* SPI transaction failed */
    }

.. note::

  SPI_open API supports configuration of data word length in the
  SPI_Params. Currently IP V1 driver (for AM3/4/5 devices) supports
  8/16/32-bit word length, IP V0 driver (for Keystone devices) supports
  8/16-bit word length.

Examples
===========

SPI
----

+-----------------------+-----------------------+-----------------------+
| Name                  | Description           | Expected Results      |
+=======================+=======================+=======================+
| SPI_FlashReadWrite    | Sample application    | Following prints on   |
|                       | demonstrating read    | console expected:     |
| Example application   | and write of data     | **Pass criteria:**    |
|                       | to a NOR flash        |                       |
|                       | device connected      | All tests have        |
|                       | over SPI interface.   | passed.               |
|                       | By default, write     |                       |
|                       | test is disabled,     |                       |
|                       | user can enable       |                       |
|                       | write test by         |                       |
|                       | defining              |                       |
|                       | TEST_SPI_NOR_WRITE    |                       |
|                       | in                    |                       |
|                       | test/src/SPI_board.h  |                       |
|                       |                       |                       |
|                       | If write test is      |                       |
|                       | enabled, write        |                       |
|                       | transaction is        |                       |
|                       | verified              |                       |
|                       | for correctness by    |                       |
|                       | reading contents      |                       |
|                       | back.                 |                       |
+-----------------------+-----------------------+-----------------------+
| SPI_TestApplication   |                       | Following prints on   |
|                       | Driver unit test      | console expected:     |
|                       | application to        | **Pass criteria:**    |
|                       | validate features     | All tests have        |
|                       | and interfaces for    | passed.               |
|                       | SPI driver            |                       |
+-----------------------+-----------------------+-----------------------+
| spiLoopback example   |                       | Following prints on   |
|                       | Example application   | console expected:     |
|                       | to validate           | **Pass criteria:**    |
|                       | features and          | All tests have        |
|                       | interfaces for SPI    | passed.               |
|                       | driver in loopback    |                       |
|                       | mode. Configures      |                       |
|                       | the SPI in loopback   |                       |
|                       | mode, transmits a     |                       |
|                       | test pattern and      |                       |
|                       | receives it back      |                       |
|                       | from SPI.             |                       |
|                       |                       |                       |
|                       |                       |                       |
|                       | Note: This example    |                       |
|                       | is intended to        |                       |
|                       | demonstrate the SPI   |                       |
|                       | LLD API usage on      |                       |
|                       | the HW platforms      |                       |
|                       | where SPI memory is   |                       |
|                       | not available.        |                       |
|                       | Currently this        |                       |
|                       | example is            |                       |
|                       | supported on          |                       |
|                       | OMAPL138/C6748        |                       |
|                       | platforms.            |                       |
+-----------------------+-----------------------+-----------------------+

| 
QSPI
-----

+-----------------------+-----------------------+-----------------------+
| Name                  | Description           | Expected Results      |
+=======================+=======================+=======================+
| QSPI_FlashReadWrite   | Sample application    | Following prints on   |
|                       | demonstrating read    | console expected:     |
| Example application   | and write of data     | **Pass criteria:**    |
|                       | to a flash device     |                       |
|                       | connected over QSPI   | All tests have        |
|                       | interface. Write      | passed.               |
|                       | transaction is        |                       |
|                       | verified  for         |                       |
|                       | correctness by        |                       |
|                       | reading contents      |                       |
|                       | back.                 |                       |
+-----------------------+-----------------------+-----------------------+
| QSPI_TestApplication  |                       | Following prints on   |
|                       | Driver unit test      | console expected:     |
|                       | application to        | **Pass criteria:**    |
|                       | validate features     | All tests have        |
|                       | and interfaces for    | passed.               |
|                       | QSPI driver           |                       |
+-----------------------+-----------------------+-----------------------+

| 

MCSPI
------

+-----------------+-----------------+----------------------------------------+-----------------+
| Name            | Description     | Additional EVM                         | Expected        |
|                 |                 | Configuration                          | Results         |
+=================+=================+========================================+=================+
| MCSPI_Serialize | Sample          | **AM57x IDK EVM:**                     | |               |
| r               | Application     |                                        | | ** **         |
| Example         | demonstrating   |                                        |                 |
| application     | reading data    | Short pins 1  and 2 on header          | Following       |
|                 | generated from  | J37(Industrial I/O)                    | prints  on      |
|                 | industrial      |                                        | console         |
|                 | input module.   | **AM335x ICE v2:**                     | expected:       |
|                 | Application     | Short pins 1 and 2 on header           |                 |
|                 | uses GPIO pins  | J14(Industrial I/O)                    | **Pass          |
|                 | to assert load  |                                        | criteria:**     |
|                 | signal in order | **AM437x IDK EVM:**                    |                 |
|                 | to generate     | Short pins 1 and 2 on                  | All tests have  |
|                 | date from       | header J1(Industrial I/O)              | passed.         |
|                 | industrial      |                                        |                 |
|                 | input module.   |                                        |                 |
+-----------------+-----------------+----------------------------------------+-----------------+
| MCSPI_Dma_Seria | Sample          | **AM57x IDK EVM:**                     | |               |
| lizer           | Application     | Short pins 1 and 2 on header           | | ** **         |
| Example         | demonstrating   | J37(Industrial I/O)                    |                 |
| application     | reading data    | |                                      | Following       |
|                 | generated from  | **AM437x IDK EVM:**                    | prints  on      |
|                 | industrial      | Short pins 1 and 2 on header           | console         |
|                 | input module    | J1(Industrial I/O)                     | expected:       |
|                 | through EDMA.   |                                        |                 |
|                 | Application     |                                        | **Pass          |
|                 | uses GPIO pins  |                                        | criteria:**     |
|                 | to assert load  |                                        |                 |
|                 | signal in order |                                        | All tests have  |
|                 | to generate     |                                        | passed.         |
|                 | date from       |                                        |                 |
|                 | industrial      |                                        |                 |
|                 | input module.   |                                        |                 |
+-----------------+-----------------+----------------------------------------+-----------------+
| MCSPI_SerialFla | Sample          | **AM335x GP EVM:**                     | |               |
| sh              | Application     | Set the EVM in profile 2               | | ** **         |
|                 | demonstrating   | (SW8[1] = OFF,                         |                 |
|                 | writing and     |  SW8[2] = ON,                          | Following       |
|                 | reading data    |  SW8[3:4] = OFF)                       | prints  on      |
|                 | from the serial |                                        | console         |
|                 | flash through   |                                        | expected:       |
|                 | MCSPI EDMA      |                                        |                 |
|                 | interface.      |                                        | **Pass          |
|                 |                 |                                        | criteria:**     |
|                 |                 |                                        |                 |
|                 |                 |                                        | All tests have  |
|                 |                 |                                        | passed.         |
+-----------------+-----------------+----------------------------------------+-----------------+
| MCSPI_slavemode | Application     | **Pin Connections:**                   | | **On          |
| example         | demonstrates    |                                        |   slave EVM     |
| application     | slave recieve   |                                        |   console:      |
|                 | and transmit    | | **IDK AM571x,**                      |   **\ SPI       |
|                 | features of     | | **IDK AM572x or IDK AM574x:**        |   initialized   |
|                 | McSPI.          | | EVM1(master) ==== EVM2(slave)        | | Slave: PASS:  |
|                 | Application use | | J21-Pin24(CLK)---J21-Pin24(CLK)      |   Txd from      |
|                 | case requires   | | J21-Pin26(MISO)---J21-Pin28(MISO)    |   master SPI    |
|                 | two EVMs. One   | | J21-Pin28(MOSI)---J21-Pin26(MOSI)    |                 |
|                 | acts as Master  | | J21-Pin30(CS)------J21-Pin30(CS)     | |               |
|                 | and Another as  | | J21-Pin22(DGND)--J21-Pin22(DGND)     | | **On Master   |
|                 | slave. McSPI    | |                                      |   EVM console:  |
|                 | connections     | | **IDK AM437x:**                      |                 |
|                 | information and | | EVM1(master) ==== EVM2(slave)        |   initialized   |
|                 | addtional       | | J16-Pin24(CLK)-----J16-Pin24(CLK)    | | Master: PASS: |
|                 | details are as  | | J16-Pin26(MISO)---J16-Pin28(MISO)    |   Txd from      |
|                 | follows.        | | J16-Pin28(MOSI)---J16-Pin26(MOSI)    |   slave SPI     |
|                 |                 | | J16-Pin30(CS)------J16-Pin30(CS)     | | Done          |
|                 | **No of Boards  | | J16-Pin22(DGND)--J16-Pin22(DGND)     |                 |
|                 | Required**:     | |                                      |                 |
|                 |                 | | **ICEv2AM335x:**                     |                 |
|                 | 2               | | EVM1(master) ========= EVM2(slave)   |                 |
|                 |                 | | J3-Pin12(CLK)---------J3-Pin12(CLK)  |                 |
|                 | **Connection    | | J3-Pin14(MIS0)-------J3-Pin16(MISO)  |                 |
|                 | requirements:** | | J3-Pin16(MOSI)-------J3-Pin14(MOSI)  |                 |
|                 |                 | | J3-Pin18(CS)-----------J3-Pin18(CS)  |                 |
|                 | | Consider EVM1 | | J3-Pin2(DGND)--------J3-Pin2(DGND)   |                 |
|                 |   as Master and | |                                      |                 |
|                 |   EVM2 as       | | **BBB AM335x:**                      |                 |
|                 |   slave.        | | EVM1(master) ===== EVM2(slave)       |                 |
|                 | | MasterSPI_CLK | | P9-Pin31(CLK)-------P9-Pin31(CLK)    |                 |
|                 |   -------SlaveS | | P9-Pin29(MISO)------P9-Pin30(MISO)   |                 |
|                 | PI_CLK          | | P9-Pin30(MOSI)------P9-Pin29(MOSI)   |                 |
|                 | | MasterSPI_D0- | | P9-Pin28(CS)---------P9-Pin28(CS)    |                 |
|                 | ---------SlaveS | | P9-Pin1(DGND)-------P9-Pin1(DGND)    |                 |
|                 | PI_D1           | |                                      |                 |
|                 | | MasterSPI_D1- | | **K2G EVM:**                         |                 |
|                 | ---------Slave  | | EVM1(master) ======= EVM2(slave)     |                 |
|                 |   SPI_D0        | | J12-Pin9(MISO)-------J12-Pin9(MISO)  |                 |
|                 | | MasterSPI_CS0 | | J12-Pin11(MOSI)----J12-Pin11(MOSI)   |                 |
|                 | --------SlaveSP | | J12-Pin13(CLK)------J12-Pin13(CLK)   |                 |
|                 | I_CS0           | | J12-Pin15(CS0)------J12-Pin15(CS0)   |                 |
|                 | | DGND--------- | | J12-Pin49(DGND)--J12-Pin49(DGND)     |                 |
|                 | -------------DG | |                                      |                 |
|                 | ND              |                                        |                 |
|                 |                 | | **icev2AMIC110 EVM:**                |                 |
|                 | **Additional    | | EVM1(master) ======= EVM2(slave)     |                 |
|                 | Requirements:** | | J5-Pin12(MISO)-------J5-Pin14(MISO)  |                 |
|                 |                 | | J5-Pin14(MOSI)------J5-Pin12(MOSI)   |                 |
|                 | Run             | | J4-Pin13(CLK)------J4-Pin13(CLK)     |                 |
|                 | "MCSPI_SlaveMod | | J5-Pin4(CS)---------J5-Pin4(CS)      |                 |
|                 | e_SlaveExample_ | | J5-Pin2(DGND)-------J5-Pin2(DGND)    |                 |
|                 | <BoardType><arm |                                        |                 |
|                 | /c66x/m4>Exampl |                                        |                 |
|                 | eProject"       |                                        |                 |
|                 | first on Slave  |                                        |                 |
|                 | EVM and then    |                                        |                 |
|                 | "MCSPI_SlaveMode|                                        |                 |
|                 | _MasterExample  |                                        |                 |
|                 | <BoardType>_<ar |                                        |                 |
|                 | m/c66x/m4>Examp |                                        |                 |
|                 | leProject"      |                                        |                 |
|                 | on Master EVM.  |                                        |                 |
|                 |                 |                                        |                 |
|                 | |               |                                        |                 |
|                 | | **Note:**     |                                        |                 |
|                 |                 |                                        |                 |
|                 | A DGND          |                                        |                 |
|                 | connection may  |                                        |                 |
|                 | be required     |                                        |                 |
|                 | from expansion  |                                        |                 |
|                 | connector on    |                                        |                 |
|                 | each board to   |                                        |                 |
|                 | make sure the   |                                        |                 |
|                 | data transfer   |                                        |                 |
|                 | is proper.      |                                        |                 |
|                 |                 |                                        |                 |
|                 |                 |                                        |                 |
+-----------------+-----------------+----------------------------------------+-----------------+

Additional References
======================
+-----------------------------------+-----------------------------------+
| **Document**                      | **Location**                      |
+-----------------------------------+-----------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\spi\docs\doxygen\html\index. |
|                                   | html                              |
+-----------------------------------+-----------------------------------+
| Release Notes                     | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\spi\docs\ReleaseNotes_SPI_LL |
|                                   | D.pdf                             |
+-----------------------------------+-----------------------------------+

| 

.. raw:: html
