.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_TIMESYNC(PTP)

Overview
--------

Terms and Abbreviations
^^^^^^^^^^^^^^^^^^^^^^^^

+-------------------------------+----------------------------------+
| Acronym                       | Description                      |
+===============================+==================================+
| PTP                           |  Precision Time Protocol         |
+-------------------------------+----------------------------------+
| P2P                           |  Peer to Peer                    |
+-------------------------------+----------------------------------+
| E2E                           |  End to End                      |
+-------------------------------+----------------------------------+
| TC                            |  Transparent Clock               |
+-------------------------------+----------------------------------+
| OC                            |  Ordinary Clock                  |
+-------------------------------+----------------------------------+
| BC                            |  Boundary Clock                  |
+-------------------------------+----------------------------------+
| Controller                    |  PTP controller                  |
+-------------------------------+----------------------------------+
| Device                        |  PTP Device                      |
+-------------------------------+----------------------------------+
| BMCA                          |  Best Controller Clock Algorithm |
+-------------------------------+----------------------------------+
| RCF                           |  Synchronization/(Frequency      |
|                               |  Compensation) Factor            |
+-------------------------------+----------------------------------+
| IEC 61558                     |  PTP profile for network control |
|                               |  systems                         |
+-------------------------------+----------------------------------+

Introduction
^^^^^^^^^^^^

This document details the user guide aspects of PTP/1588 v2 controller/device implementation on PRU-ICSS.

Dual EMAC firmware implementation supports P2P and the implementation is unique to Emac.
The controller capability added to the TimeSync driver is currently limitted to sending Sync and
Announce frames. The BMCA/Management part of PTP controller is not implemented.


TimeSync (PTP) driver does the task of

#. Running BMCA
#. Calculating RCF and Sync packet interval.
#. Performing clock synchronization
#. Calculating peer and line delay
#. Sending Delay Request and Delay Response frames (includes Pdelay Req and Pdelay Res)


.. rubric:: Driver Configuration
   :name: driver-configuration-timesync

.. rubric:: **Board Specific Configuration**
   :name: board-specific-configuration

All board specific configurations like enabling clock and pin-mux are
required before calling any driver APIs. By default Board_Init() API
available under board module supports all initialization sequence for TI
supported EVMs. In addition it initializes UART instance for
Console/STDIO. Refer `Processor SDK RTOS Board
Support <index_board.html#board-support>`__ for additional
details.

.. rubric:: **TimeSync Configuration Structure**
   :name: timesync-configuration-structure

The TimeSync driver needs to be initialized/configured with initial parameters during the driver initialization.

icss_timeSync_init.c binds driver with TimeSync parameters.

TimeSync_drvInit() API triggers all static configuration information available through parameters. Once initialization is complete the driver is ready for use.

Please refer to TimeSync_ParamsHandle structure defined under '<pdk>/packages/ti/transport/timeSync/include/icss_timeSyncApi.h'


APIs
^^^^^

API reference for Application:

::

    #include <ti/transport/timeSync/icss_timeSync.h>

Below sequence indicates API calling sequence for a simple use case of
timeSync controller operation

.. code-block:: c

    ...
    Board_init(boardCfg);
    timeSync_example_configureInterrupts(EMAC_PORT_NUM, &emacCfg);
    ICSS_EmacSocSetInitCfg(instance, emacBaseAddr);
    ICSS_EmacInit();
    /* Assumption: firmware is downloaded and ICSS_EMAC driver is initialized */
    TimeSync_drvInit(timeSyncHandle);
    TimeSync_drvEnable(timeSyncHandle);
    TimeSync_enableController();
    While(1)
    {
        Delay();
    }

Below sequence indicates API calling sequence for a simple use case of
timeSync device operation

.. code-block:: c

    ...
    Board_init(boardCfg);
    timeSync_example_configureInterrupts(EMAC_PORT_NUM, &emacCfg);
    ICSS_EmacSocSetInitCfg(instance, emacBaseAddr);
    ICSS_EmacInit();
    /* Assumption: firmware is downloaded and ICSS_EMAC driver is initialized */
    TimeSync_drvInit(timeSyncHandle);
    TimeSync_drvEnable(timeSyncHandle);
    TimeSync_disableController();
    While(1)
    {
        Delay();
    }

**NOTE**
: 

#. The TimeSync Tx callback interrupt is mapped to the ISR TimeSync_txTSIsr(), where the two PRU interrupts configured to ARM interrupt txIntNum are PRU_ARM_EVENT_6 and PRU_ARM_EVENT_7.
#. The PTP frames are received via the Real Time (RT) call back from ICSS_EMAC driver and hence RT call back needs to be implemented at the application for ICSS-EMAC driver.

Tasks Internally created from TimeSync_drvInit()
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Below tasks would be created after Application calls TimeSync_drvInit() function. The sample osal implementation is provided under <pdk>/packages/ti/transport/timeSync/example/src/common/timeSync_example_osal.c implementing these tasks.


+-------------------------------+----------------------------------+-----------------------------------------------------------------+
| Handle Name                   | | Function Name                  | | What it does                                                  |
+===============================+==================================+=================================================================+
| timeSync_pDelayReqSendTask    | TimeSync_PdelayReqSendTask()     | | Send Peer Delay Requests periodically on both ports.          |
|                               |                                  |   Delay is configurable. Only applicable for P2P configuration  |
+-------------------------------+----------------------------------+-----------------------+-----------------------------------------+
| timeSync_delayReqSendTask     | TimeSync_delayReqSendTask()      | | Send Delay requests to PTP Controller. This is currently done |
|                               |                                  |   for every Sync frame. Pends indefinitely on a semaphore.      |
+-------------------------------+----------------------------------+-----------------------------------------------------------------+
| timeSync_TxTSTaskP1           + TimeSync_TxTSTask_P1()           | | Process Tx timestamp for Port 1. Pends on an event posted by  |
|                               |                                  |   Tx ISR indefinitely.                                          |
+-------------------------------+----------------------------------+-----------------------------------------------------------------+
| timeSync_TxTSTaskP2           + TimeSync_TxTSTask_P2()           | | Process Tx timestamp for Port 2. Pends on an event posted by  |
|                               |                                  |   Tx ISR indefinitely.                                          |
+-------------------------------+----------------------------------+-----------------------------------------------------------------+
| timeSync_syncTxTask           + TimeSync_SyncTxTask()            | | Sends Sync frames on both ports in Controller mode.           |
|                               |                                  |   Pends indefinitely on a semaphore posted by the DM Timer ISR  |
+-------------------------------+----------------------------------+-----------------------------------------------------------------+
| timeSync_announceTxTask       | TimeSync_AnnounceTxTask()        | | Sends Announce frames on both ports periodically              |
+-------------------------------+----------------------------------+-----------------------------------------------------------------+
| timeSync_NRT_Task             | TimeSync_NRT_Task()              | | NRT stands for non real time. Processes Peer delay frames in  |
|                               |                                  |   the background and calculate peer delay.                      |
+-------------------------------+----------------------------------+-----------------------------------------------------------------+
| timeSync_backgroundTask       | TimeSync_BackgroundTask()        | | Checks for Sync timeout and performs offset stabilization.    |
+-------------------------------+----------------------------------+-----------------------------------------------------------------+


Building timeSync Examples/Unit Test
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- Setup the build environment `SetupBuildEnvironment <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/index_overview.html#setup-environment>`__
- Follow the steps as mentioned under `SDK example and test CCS Project Creation <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/index_overview.html#pdk-example-and-test-project-creation>`__  for creating the CCS based example and test projects creation


Sample Examples
^^^^^^^^^^^^^^^


+--------------------------+-----------------------+-----------------------+
|       Name               |      Description      || Expected Results     |
+==========================+=======================+=======================+
| timeSync_BasicExample    | Simple timeSync       || Clock Sync           |
|                          | example demonstrating |  results at Device    |
|                          | sync between          |                       |
|                          | Controller and Device |                       |
+--------------------------+-----------------------+-----------------------+

Additional References
---------------------

+----------------------------+---------------------------------------------+
| **Document**               | **Location**                                |
+----------------------------+---------------------------------------------+
| API Reference Manual       | $(TI_PDK_INSTALL_DIR)/packages/ti           |
|                            | /transport/timeSync/docs/doxygen/html/index |
|                            | .html                                       |
+----------------------------+---------------------------------------------+

















