.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_SRIO 

Overview
--------

Introduction
^^^^^^^^^^^^

Driver enables the high-bandwidth system level interconnects. It is
intended to offer Gigabyte per second performance levels for
chip-to-chip and board-to-board communication.

.. rubric:: Modes of Operation
   :name: modes-of-operation

Following modes of operations are supported

**Direct I/O**: The SRIO packet contains the specific address where the
data should be stored or read in the destination device. This means that
the source device must have detailed knowledge of the available memory
space within the destination device.

**Type 9**: A destination address is not specified. Instead the Stream
ID is used to map the request to a specific memory region by the local
(destination) device. TI IP additionally uses Class of Service (COS) as
well to further classify the mapping of a request to a memory region.

**Type 11**: A destination address is not specified, instead, a
mailbox identifier is used within the SRIO packet. The mailbox is
controlled and mapped to memory by the local (destination) device.

User Interface
--------------

Driver Configuration
^^^^^^^^^^^^^^^^^^^^^

.. rubric:: **Board Specific Configuration**
   :name: board-specific-configuration

All board specific configurations eg:enabling and configuring the SRIO
SERDES registers and SRIO lane configurations (communication rates,
device IDs, etc) are required before calling any driver APIs. Template
functions for configuring the SRIO IP and SERDES registers are provided
in PDK_INSTALL_DIR\\packages\\ti\\drv\\srio\\device\\<device>\\src\\. A template
function is provided for each soc that supports SRIO.

APIs
^^^^^

API reference for application:

::

    #include <ti/drv/srio/srio_drv.h>

OSAL API reference for application:

::

    #include <ti/drv/srio/srio_osal.h>

.. rubric:: Init SRIO
   :name: init-srio

::

    Initialize QMSS and CPPI modules...

::

    ...
    SrioDevice_init();
    Srio_init ();
    ...
    /* Start the application Managed SRIO Driver. Refer example/test for appCfg fields */
    hAppManagedSrioDrv = Srio_start (&appCfg); 

At this point SRIO driver is ready for data transfer on specific
instance identified by handle.

.. rubric:: Send/Receive APIs
   :name: sendreceive-apis

**Direct IO**:

::

    Srio_sockSend_DIO(Srio_SockHandle srioSock, Srio_DrvBuffer hBuffer, uint32_t size, Srio_SockAddrInfo* to);

**Type 9**:

::

    Srio_sockSend_TYPE9   (Srio_SockHandle srioSock, Srio_DrvBuffer hBuffer, uint32_t size, Srio_SockAddrInfo* to);

**Type 11**:

::

    Srio_sockSend_TYPE11  (Srio_SockHandle srioSock, Srio_DrvBuffer hBuffer, uint32_t size, Srio_SockAddrInfo* to);

**Receive**:

::

    Srio_sockRecv         (Srio_SockHandle srioSock, Srio_DrvBuffer* hDrvBuffer,Srio_SockAddrInfo* from);

Application
------------

Examples
^^^^^^^^

+-----------------------+-----------------------+----------------------------+
| Name                  || Description          | Expected Results           |
+=======================+=======================+============================+
| Loopback DIO ISR      ||  The example is a    | The application            |
| Example Project       | demonstration of the  | will run through a         |
|                       | SRIO driver running   | set of DIO tests.          |
|                       | the SRIO IP Block in  | Upon successful            |
|                       | loopback mode. The    | completion the             |
|                       | example showcases the | following string           |
|                       | use of SRIO DIO       | will be printed            |
|                       | sockets using LSU     | "DIO with                  |
|                       | interrupts to         | Interrupts example         |
|                       | indicate the          | completed                  |
|                       | completion of packet  | successfully."             |
|                       | transfer.             |                            |
|                       |                       |                            |
|                       || It is shown how      |                            |
|                       | multiple sockets      |                            |
|                       | with different        |                            |
|                       | Source IDs can post   |                            |
|                       | transactions and      |                            |
|                       | process the pending   |                            |
|                       | interrupt raised by   |                            |
|                       | SRIO device.          |                            |
+-----------------------+-----------------------+----------------------------+
| Multicore Loopback    || The example is a     | The application            |
| Example Project       | demonstration of the  | will run through a         |
|                       | SRIO driver while     | set of tests               |
|                       | operating in a        | sending and                |
|                       | Multicore environment | receiving data             |
|                       | by running the SRIO   | between two cores          |
|                       | IP Block in loopback  | over SRIO. Upon            |
|                       | mode. The test case   | successful                 |
|                       | here showcases the    | completion the             |
|                       | SRIO Driver API being | following string           |
|                       | multicore safe and    | will be printed            |
|                       | using the SRIO IP     | "Multicore Test            |
|                       | peripheral to         | Passed" from each          |
|                       | exchange messages     | DSP core.                  |
|                       | between different     |                            |
|                       | cores running on the  |                            |
|                       | same device.          |                            |
|                       |                       |                            |
|                       || In this test case    |                            |
|                       | each core performs    |                            |
|                       | the role of a         |                            |
|                       | producer and          |                            |
|                       | consumer. The test    |                            |
|                       | starts with Core 1    |                            |
|                       | sending data to       |                            |
|                       | Core 2. Core 2        |                            |
|                       | receives and          |                            |
|                       | validates the data    |                            |
|                       | and sends another     |                            |
|                       | data message to       |                            |
|                       | Core3; which          |                            |
|                       | receives and          |                            |
|                       | validates the data    |                            |
|                       | and sends another     |                            |
|                       | different data        |                            |
|                       | message to Core 0.    |                            |
|                       | Core 0 then sends a   |                            |
|                       | message to Core 1     |                            |
|                       | which is received     |                            |
|                       | and validated.        |                            |
+-----------------------+-----------------------+----------------------------+
| Loopback Test         || Unit Test            | The application            |
|                       | application to test   | will run through a         |
|                       | all APIs              | set of tests to            |
|                       |                       | verify all SRIO LLD        |
|                       |                       | APIS. Upon                 |
|                       |                       | successful                 |
|                       |                       | completion the             |
|                       |                       | following string           |
|                       |                       | will be printed            |
|                       |                       | "Unit Testing              |
|                       |                       | completed                  |
|                       |                       | successfully." from        |
|                       |                       | each DSP core.             |
+-----------------------+-----------------------+----------------------------+
| SRIO Benchmarking     || The SRIO benchmarking| Review the SRIO            |
| Test                  | example code is       | Benchmarking Example       |
|                       | created to allow      | documentation located      |
|                       | customers to run      | in                         |
|                       | benchmarks on their   | PDK_INSTALL_DIR\\packa     |
|                       | own TI EVMs with code | ges\\ti\\drv\\srio\\test\\ |
|                       | that utilizes the     | tput_benchmarking\\doc     |
|                       | SRIO LLD APIs. The    | s\\SRIO_Benchmarking_E     |
|                       | benchmarking example  | xample_Code_Guide.doc      |
|                       | code allows the user  | for more information       |
|                       | to run core to core   | on the tests               |
|                       | in loopback mode      | pass/fail criteria.        |
|                       | (internal or          |                            |
|                       | external) on a single |                            |
|                       | EVM, or board to      |                            |
|                       | board using the       |                            |
|                       | external interface    |                            |
|                       | between two EVMs.     |                            |
|                       | This document’s       |                            |
|                       | purpose is to explain |                            |
|                       | how measurements are  |                            |
|                       | obtained and how to   |                            |
|                       | configure the example |                            |
|                       | code for different    |                            |
|                       | test scenarios. SRIO  |                            |
|                       | physical connectivity |                            |
|                       | or external SRIO      |                            |
|                       | switch configuration  |                            |
|                       | is beyond the scope   |                            |
|                       | of this document.     |                            |
+-----------------------+-----------------------+----------------------------+
                                                                             
|                                                                            
                                                                             
Additional References                                                        
---------------------                                                        
                                                                             
+-----------------------------------+----------------------------------------+
| **Document**                      | **Location**                           |
+-----------------------------------+----------------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)\\packages\\ti    |
|                                   | \\drv\\srio\\docs\\doxygen\\html\\index|
|                                   | .html                                  |
+-----------------------------------+----------------------------------------+
| Release Notes                     | $(TI_PDK_INSTALL_DIR)\\packages\\ti    |
|                                   | \\drv\\srio\\docs\\ReleaseNotes_SRIOD  |
|                                   | river.pdf                              |
+-----------------------------------+----------------------------------------+

| 

