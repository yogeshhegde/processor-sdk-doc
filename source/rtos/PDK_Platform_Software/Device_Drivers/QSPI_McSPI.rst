.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_QSPI-McSPI 

.. rubric:: Introduction
   :name: introduction

SPI driver enables communication for general SPI, MCSPI (Multichannel
SPI) and QSPI (Quad SPI) based peripherals on board through common API
  to application.
MCSPI is a generic full-duplex interface supporting transmit and
receive of data over SPI bus. QSPI a variant of SPI supports four
receive data lanes. Driver supports configuration for either single,
dual or quad data lanes

.. rubric:: Modes of Operation
   :name: modes-of-operation

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

.. rubric:: Driver Configuration
   :name: driver-configuration

.. rubric:: **Board Specific Configuration**
   :name: board-specific-configuration

All board specific configurations eg:enabling clock and pin-mux for SPI
pins are required before calling any driver APIs.By default Board_Init()
API supports all initialization sequence for TI supported EVMs. In
addition it initializes UART instance for Console/STDIO.Refer `Processor
SDK RTOS Board Support <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Board_Support>`__
for additional details.Once board specific configuration is
complete \ *SPI_init()* API should be called to initialize driver.

.. rubric:: SoC Specific Configuration
   :name: soc-specific-configuration

All SoC specific configurations (eg: SPI module registers base address,
interrupt configurations, etc.) can be set using SPI_socSetInitCfg() SoC
driver API before calling any SPI driver APIs. The default SoC specific
configurations can be retrieved using SPI_socGetInitCfg() SoC driver
API. 

.. rubric:: **SPI Configuration Structure**
   :name: spi-configuration-structure

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

.. rubric:: **APIs**
   :name: apis

API Reference for application:

::

    #include <ti/drv/spi/SPI.h>

SPI IP V1 driver also supports multi-channel API's:

::

    #include <ti/drv/spi/MCSPI.h> 

.. rubric:: 
   :name: section

.. rubric:: **Open SPI**
   :name: open-spi

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
| At this point SPI driver is ready for data transfer in blocking mode
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

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
SPI_open API supports configuration of data word length in the
SPI_Params. Currently IP V1 driver (for AM3/4/5 devices) supports
8/16/32-bit word length, IP V0 driver (for Keystone devices) supports
8/16-bit word length.

.. raw:: html

   </div>

.. rubric:: Examples
   :name: examples

.. rubric:: **SPI**
   :name: spi

+-----------------------+-----------------------+-----------------------+
|         Name          |      Description      |    Expected Results   |
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
|                       | verified for          |                       |
|                       | correctness by        |                       |
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

| **QSPI**

+-----------------------+-----------------------+-----------------------+
|          Name         |      Description      |   Expected Results    |
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
| **MCSPI**

+-----------------+-----------------+-----------------+-----------------+
| Name            | Description     | Additional EVM  | Expected        |
|                 |                 | Configuration   | Results         |
+=================+=================+=================+=================+
| MCSPI_Serialize | Sample          | **AM57x IDK     |                 |
| r               | Application     | EVM : **        |                 |
| Example         | demonstrating   |                 |                 |
| application     | reading data    | Short pins 1    | Following       |
|                 | generated from  | and 2 on header | prints  on      |
|                 | industrial      | J37(Industrial  | console         |
|                 | input module.   | I/O)            | expected:       |
|                 | Application     |                 |                 |
|                 | uses GPIO pins  | **AM335x ICE    | **Pass          |
|                 | to assert load  | v2:**           | criteria:**     |
|                 | signal in order |                 |                 |
|                 | to generate     | Short pins 1    | All tests have  |
|                 | date from       | and 2 on        | passed.         |
|                 | industrial      | header          |                 |
|                 | input module.   | J14(Industrial  |                 |
|                 |                 | I/O)            |                 |
|                 |                 |                 |                 |
|                 |                 | **AM437x IDK    |                 |
|                 |                 | EVM:**          |                 |
|                 |                 | Short pins 1    |                 |
|                 |                 | and 2 on        |                 |
|                 |                 | header          |                 |
|                 |                 | J1(Industrial   |                 |
|                 |                 | I/O)            |                 |
+-----------------+-----------------+-----------------+-----------------+
| MCSPI_Dma_Seria | Sample          | **AM57x IDK     |                 |
| lizer           | Application     | EVM : **        |                 |
| Example         | demonstrating   |                 |                 |
| application     | reading data    | Short pins 1    | Following       |
|                 | generated from  | and 2 on header | prints  on      |
|                 | industrial      | J37(Industrial  | console         |
|                 | input module    | I/O)            | expected:       |
|                 | through EDMA.   |                 |                 |
|                 | Application     | **AM437x IDK    | **Pass          |
|                 | uses GPIO pins  | EVM:**          | criteria:**     |
|                 | to assert load  |                 |                 |
|                 | signal in order | Short pins 1    | All tests have  |
|                 | to generate     | and 2 on        | passed.         |
|                 | date from       | header          |                 |
|                 | industrial      | J1(Industrial   |                 |
|                 | input module.   | I/O)            |                 |
+-----------------+-----------------+-----------------+-----------------+
| MCSPI_SerialFla | Sample          | **AM335x        |                 |
| sh              | Application     | GP**\  **EVM**\ |                 |
|                 | demonstrating   |  **:**          |                 |
|                 | writing and     |                 | Following       |
|                 | reading data    | Set the EVM in  | prints  on      |
|                 | from the serial | profile 2       | console         |
|                 | flash through   | (SW8[1] = OFF,  | expected:       |
|                 | MCSPI EDMA      | SW8[2] = ON,    |                 |
|                 | interface.      | SW8[3:4] = OFF) | **Pass          |
|                 |                 |                 | criteria:**     |
|                 |                 |                 |                 |
|                 |                 |                 | All tests have  |
|                 |                 |                 | passed.         |
+-----------------+-----------------+-----------------+-----------------+
| MCSPI_slavemode | Application     | **Pin           | **On            |
| example         | demonstrates    | Connections:**  | slave EVM       |
| application     | slave recieve   |                 | console:        |
|                 | and transmit    | **IDK AM571x,   | **\ SPI         |
|                 | features of     | IDK AM572x or   | initialized     |
|                 | McSPI.          | IDK AM574x:     | Slave: PASS:    |
|                 | Application use | **\ EVM1(mast   | Txd from        |
|                 | case requires   | er)====         | master SPI      |
|                 | two EVMs. One   | EVM2(slave)     |                 |
|                 | acts as Master  | J21-Pin24(CLK)  |                 |
|                 | and Another as  |   -----         | **On Master     |
|                 | slave. McSPI    |   J21-Pin24(CLK | EVM console:    |
|                 | connections     | )               | **\ SPI         |
|                 | information and | J21-Pin26(MISO) | initialized     |
|                 | addtional       |                 | Master: PASS:   |
|                 | details are as  |   ---           | Txd from        |
|                 | follows.        | J21-Pin28(MISO) | slave SPI       |
|                 |                 |                 | Done            |
|                 | **No of Boards  | J21-Pin28(MOSI) |                 |
|                 | Required**:     |                 |                 |
|                 |                 | ---             |                 |
|                 | 2               | J21-Pin26(MOSI) |                 |
|                 |                 |                 |                 |
|                 | **Connection    | J21-Pin30(CS)   |                 |
|                 | requirements:** | ------          |                 |
|                 |                 | J21-Pin30(CS)   |                 |
|                 | Consider EVM1 | J21-Pin22(DGND) |                 |
|                 | as Master and |                 |                 |
|                 | EVM2 as       | --              |                 |
|                 | slave.        | J21-Pin22(DGND) |                 |
|                 | MasterSPI_CLK |                 |                 |
|                 | -------SlaveS |                 |                 |
|                 | PI_CLK          |                 |                 |
|                 | MasterSPI_D0- |                 |                 |
|                 | ---------SlaveS | **IDK AM437x**: |                 |
|                 | PI_D1           |                 |                 |
|                 | MasterSPI_D1- | EVM1(master)=   |                 |
|                 | ---------Slave  | ===EVM2(slave)  |                 |
|                 | SPI_D0        | J16-Pin24(CLK)  |                 |
|                 | MasterSPI_CS0 |                 |                 |
|                 | --------SlaveSP | -----           |                 |
|                 | I_CS0           | J16-Pin24(CLK)  |                 |
|                 | DGND--------- |                 |                 |
|                 | -------------DG | J16-Pin26(MISO) |                 |
|                 | ND              |                 |                 |
|                 |                 | ---             |                 |
|                 | **Additional    | J16-Pin28(MISO) |                 |
|                 | Requirements:** |                 |                 |
|                 |                 | J16-Pin28(MOSI) |                 |
|                 | Run             |                 |                 |
|                 | "MCSPI_SlaveMod | ---             |                 |
|                 | e_SlaveExample_ | J16-Pin26(MOSI) |                 |
|                 | <BoardType><arm |                 |                 |
|                 | /c66x/m4>Exampl | J16-Pin30(CS)   |                 |
|                 | eProject"       | ------          |                 |
|                 | first on Slave  | J16-Pin30(CS)   |                 |
|                 | EVM and then    | J16-Pin22(DGND) |                 |
|                 | "MCSPI_SlaveMod |                 |                 |
|                 | e_MasterExample | --              |                 |
|                 | <BoardType>_<ar | J16-Pin22(DGND) |                 |
|                 | m/c66x/m4>Examp |                 |                 |
|                 | leProject"      |                 |                 |
|                 | on Master EVM.  |                 |                 |
|                 |                 | **ICEv2         |                 |
|                 |               | AM335x:         |                 |
|                 | **Note:**     | **\ EVM1(master)|                 |
|                 |                 | ====            |                 |
|                 | A DGND          | EVM2(slave)     |                 |
|                 | connection may  | J3-Pin12(CLK)   |                 |
|                 | be required     | ---------       |                 |
|                 | from expansion  | J3-Pin12(CLK)   |                 |
|                 | connector on    | J3-Pin14(MIS0)  |                 |
|                 | each board to   | -------         |                 |
|                 | make sure the   | J3-Pin16(MISO)  |                 |
|                 | data transfer   |                 |                 |
|                 | is proper.      | J3-Pin16(MOSI)  |                 |
|                 |                 | -------         |                 |
|                 |               | J3-Pin14(MOSI)  |                 |
|                 |                 |                 |                 |
|                 |                 | J3-Pin18(CS)-   |                 |
|                 |                 | ----------      |                 |
|                 |                 | J3-Pin18(CS)    |                 |
|                 |                 | J3-Pin2(DGND)   |                 |
|                 |                 | --------        |                 |
|                 |                 | J3-Pin2(DGND)   |                 |
|                 |                 |                 |                 |
|                 |                 |                 |                 |
|                 |                 | **BBB AM335x:   |                 |
|                 |                 | **\             |                 |
|                 |                 | EVM1(master)    |                 |
|                 |                 | ====EVM2(slave) |                 |
|                 |                 | | P9-Pin31(CLK) |                 |
|                 |                 | -------         |                 |
|                 |                 | P9-Pin31(CLK)   |                 |
|                 |                 | P9-Pin29(MISO)  |                 |
|                 |                 | ------          |                 |
|                 |                 | P9-Pin30(MISO)  |                 |
|                 |                 | P9-Pin30(MOSI)  |                 |
|                 |                 | ------          |                 |
|                 |                 | P9-Pin29(MOSI)  |                 |
|                 |                 | P9-Pin28(CS)-   |                 |
|                 |                 | --------        |                 |
|                 |                 | P9-Pin28(CS)    |                 |
|                 |                 | P9-Pin1(DGND)   |                 |
|                 |                 | -------(        |                 |
|                 |                 | P9-Pin1DGND)    |                 |
|                 |                 |                 |                 |
|                 |                 |                 |                 |
|                 |                 | **K2G EVM:      |                 |
|                 |                 | **\ EVM1(master)|                 |
|                 |                 | ====EVM2(slave) |                 |
|                 |                 | J12-Pin9(MISO)  |                 |
|                 |                 | -------         |                 |
|                 |                 | J12-Pin9(MISO)  |                 |
|                 |                 | J12-Pin11(MOSI) |                 |
|                 |                 | ----            |                 |
|                 |                 | J12-Pin11(MOSI) |                 |
|                 |                 | J12-Pin13(CLK)  |                 |
|                 |                 | ------          |                 |
|                 |                 | J12-Pin13(CLK)  |                 |
|                 |                 | J12-Pin15(CS0)  |                 |
|                 |                 | ------          |                 |
|                 |                 | J12-Pin15(CS0)  |                 |
|                 |                 | J12-Pin49(DGND) |                 |
|                 |                 | ------          |                 |
|                 |                 | J12-Pin49(DGND) |                 |
|                 |                 |                 |                 |
|                 |                 | **icev2         |                 |
|                 |                 | AMIC110 EVM:    |                 |
|                 |                 | **\ EVM1(master)|                 |
|                 |                 | ====            |                 |
|                 |                 | EVM2(slave)     |                 |
|                 |                 | J5-Pin12(MISO)  |                 |
|                 |                 | -------         |                 |
|                 |                 | J5-Pin14(MISO)  |                 |
|                 |                 | J5-Pin14(MOSI)  |                 |
|                 |                 | ------          |                 |
|                 |                 | J5-Pin12(MOSI)  |                 |
|                 |                 | J4-Pin13(CLK)   |                 |
|                 |                 | ------          |                 |
|                 |                 | J4-Pin13(CLK)   |                 |
|                 |                 | J5-Pin4(CS)     |                 |
|                 |                 | ---------       |                 |
|                 |                 | J5-Pin4(CS)     |                 |
|                 |                 | J5-Pin2(DGND)   |                 |
|                 |                 | -------         |                 |
|                 |                 | J5-Pin2(DGND)   |                 |
|                 |                 |                 |                 |
+-----------------+-----------------+-----------------+-----------------+

.. rubric:: **Additional References**
   :name: additional-references

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

