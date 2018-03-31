.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_EMAC 

.. rubric::  Introduction
   :name: introduction

| EMAC driver provides a well defined API layer which allows
  applications to use the EMAC peripheral to control the flow of packet
  data from the processor to the PHY and the MDIO module to control PHY
  configuration and status monitoring.

.. rubric::  Driver Configuration
   :name: driver-configuration

.. rubric::  **Board Specific Configuration**
   :name: board-specific-configuration

All the board specific configurations eg:enabling and pin-mux of
RGMII/MDIO pins should be performed before calling any driver APIs.By
default Board_Init() API supports all initialization sequence for TI
supported EVMs.Refer `Processor SDK RTOS Board
Support </index.php/Processor_SDK_RTOS_Board_Support>`__ for additional
details.

Once the board specific configuration is complete driver API emac_open()
can be called to initialize driver

.. rubric::  **EMAC Configuration Structure**
   :name: emac-configuration-structure

The EMAC_soc.c file binds driver with hardware attributes on the board
through EMAC_Cfg structure. This structure must be provided to EMAC
driver. It must be initialized before the emac_open() function is
called. Prior to calling emac_open, the address of the descriptor region
base to be inserted into the QMSS memory region MUST be provided by the
user application and updated into the EMAC_HwAttrs_V1 structure which is
part of the EMAC_Cfg. EMAC_socGetInitCfg() can be invoked to get the
EMAC initial configuration and EMAC_socSetInitCfg to update the
configuration as illustrated below.

::

       EMAC_socGetInitCfg(0, &emac_cfg);
       /* Need to update the descriptor base address */
       emac_cfg.p_desc_base = &gHostDesc;
       /* Now set the config after updating desc base address */
       EMAC_socSetInitCfg(0, &emac_cfg);

For details about individual fields of this structure, see the Doxygen
help by opening
PDK_INSTALL_DIR\packages\ti\drv\uart\docs\doxygen\html\index.html.

.. rubric::  **APIs**
   :name: apis

API reference for application:

::

    #include <ti/drv/emac/emac_drv.h>

.. rubric::  EMAC Open
   :name: emac-open

API to allow the calling application to supply a valid port number and
open configuration data. Note that providing a descriptor base address
is the code snippet below is only required for Keystone devices (at this
time only EVMK2G is supported) which is required to set up the Host
descriptor memory region in the QMSS sub-system.

::

    ...
    Board_init(boardCfg);
    EMAC_socGetInitCfg(0, &emac_cfg);
    /* Need to update the descriptor base address */
    emac_cfg.p_desc_base = &gHostDesc;
    /* Now set the config after updating desc base address */
    EMAC_socSetInitCfg(0, &emac_cfg);
    port_num = 0;
    /* Need to populate open_cfg structure with application specific configuration */
    openReturn = emac_open([port_num, &open_cfg))

| 

.. rubric::  EMAC Config
   :name: emac-config

API to allow the calling application to provide RX filter configuration.
This API is currently only supported for C6657 & OMAPL13x SOCs.

::

    /* fill in cfg_info structure */
    configReturn = emac_config(port_num, &cfg_info);

At this point EMAC driver is ready to send and receive packets.

| 

.. rubric::  EMAC Close
   :name: emac-close

API to allow user application to close an opened EMAC port. This API
will release all resources allocated during the call to emac_open().

.. rubric::  EMAC Get Statistics
   :name: emac-get-statistics

API to allow user application to retrieve statistics for specified port

::

    emac_get_statistics(port_num, * p_stats)

| 

.. rubric::  EMAC Receive Packet Poll
   :name: emac-receive-packet-poll

API (emac_pkt_poll) to provide a while(1) loop to receive packets. This
API must be called within a task context as it is blocking API.
Internally, this API will PEND on a semaphore until it it POSTED by the
Hwi Interrupt Handler. The Hwi interrupt handling is setup during the
call to the emac_open API at which time the user application, as part of
the open, configures a receive packet callback. Once there is a received
packet, the emac_pkt_poll function will invoke this callback to provide
the packet to the user application and resume PENDING on a semaphore
until there is another packet to receive. This API will not return to
the user application.

| 

.. rubric::  EMAC Send
   :name: emac-send

API to allow user application to send packet on opened EMAC port.

::

    retVal = emac_send(port_num, pkt_desc);

| 

.. rubric::  EMAC Poll
   :name: emac-poll

API to allow user application to poll the status of opened EMAC port.
Status info will be returned in the link_info structure.

::

    emac_poll(port_number, &link_info);

| 

.. rubric::  Example
   :name: example

+-----------------------+-----------------------+-----------------------+
| Name                  | Description           | Expected Results      |
+=======================+=======================+=======================+
| EMAC_BasicExample_evm | | EMAC Loopback test  | | Unit Test will      |
| K2G                   |   at CPSW switch      |   print "All tests    |
|                       |   interface.          |   have passed" via    |
|                       |   Reference example   |   UART console.       |
|                       |   for developers      |                       |
|                       |                       |                       |
|                       | Example demonstrates  |                       |
|                       | loopback capability   |                       |
|                       | by sending dummy      |                       |
|                       | broadcast packet to   |                       |
|                       | CPSW switch. Unit     |                       |
|                       | test registers        |                       |
|                       | receive packet        |                       |
|                       | callback routine with |                       |
|                       | LLD to be called for  |                       |
|                       | RX packet. Call back  |                       |
|                       | routine will extract  |                       |
|                       | packet received,      |                       |
|                       | perform simple memory |                       |
|                       | comparison against    |                       |
|                       | packet sent for       |                       |
|                       | integrity check. Unit |                       |
|                       | test will iterate     |                       |
|                       | over configured       |                       |
|                       | packet count for      |                       |
|                       | packet transmission   |                       |
|                       | and reception check.  |                       |
+-----------------------+-----------------------+-----------------------+
| EMACLoopback_testProj | | EMAC Loopback test  | | Unit Test will      |
| ect                   |   at CPSW switch      |   print "Loopback     |
| (for DRA7xx, C6657,   |   interface.          |   Test completed      |
| OMAPL137 & OMAPL138)  |   Reference example   |   successfully on     |
|                       |   for developers      |   core 0" via CCS     |
|                       |                       |   console for C6657   |
|                       | Example demonstrates  |   and on UART serial  |
|                       | loopback capability   |   console for         |
|                       | by sending dummy      |   OMAPL13x.           |
|                       | broadcast packet to   |                       |
|                       | CPSW switch. Unit     |                       |
|                       | test registers        |                       |
|                       | receive packet        |                       |
|                       | callback routine with |                       |
|                       | LLD to be called for  |                       |
|                       | RX packet. Call back  |                       |
|                       | routine will extract  |                       |
|                       | packet received,      |                       |
|                       | perform simple memory |                       |
|                       | comparison against    |                       |
|                       | packet sent for       |                       |
|                       | integrity check. Unit |                       |
|                       | test will iterate     |                       |
|                       | over configured       |                       |
|                       | packet count for      |                       |
|                       | packet transmission   |                       |
|                       | and reception check.  |                       |
|                       |                       |                       |
|                       | This example needs to |                       |
|                       | be run on the         |                       |
|                       | OMAPL137 and OMAPL138 |                       |
|                       | platforms using       |                       |
|                       | external loopback     |                       |
|                       | cable. OMAPL137 EVM   |                       |
|                       | is having two         |                       |
|                       | Ethernet ports.       |                       |
|                       | Connect the loopback  |                       |
|                       | cable to the port 1   |                       |
|                       | (ENET-P1) while       |                       |
|                       | running the loopback  |                       |
|                       | example.              |                       |
+-----------------------+-----------------------+-----------------------+
| EMAC_PktInspectionExa | This demonstrates how | Pass criteria:        |
| mple                  | to write an           |                       |
| (for all DRA7xx       | application to filter | -  The total packet   |
| devices)              | Ethernet packets      |    sent for each      |
|                       | based on IP address   |    stream is shown at |
|                       |                       |    the bottom of the  |
|                       | Prerequisites:        |    packETH widow. The |
|                       |                       |    packet stream      |
|                       | -  Install the        |    statistics must    |
|                       |    packETH utility (v |    match the packet   |
|                       |    1.8.1) on a Linux  |    statistics printed |
|                       |    PC. The packETH    |    by the DUT via     |
|                       |    tool is available  |    serial port        |
|                       |    for Windows as     | -  The packet         |
|                       |    well, but not all  |    inspection utility |
|                       |    features are       |    periodically       |
|                       |    supported          |    prints the EMAC    |
|                       | -  Download the test  |    statistics, which  |
|                       |    PCAP               |    include DMA        |
|                       |    `files </index.php |    overruns,          |
.. Image:: ../images/Pcap.zip
|                       |    and update the     |    other error. No    |
|                       |    source and dest    |    errors should be   |
|                       |    MAC address of the |    seen during the    |
|                       |    PC and EVM to be   |    transfer.          |
|                       |    used in the test.  |                       |
|                       |    The tcprewrite     | Fail criteria:        |
|                       |    utility can be     |                       |
|                       |    used to set the    | -  Packet count       |
|                       |    new MAC addresses  |    mismatch between   |
|                       |    (i.e. tcprewrite   |    packETH utility    |
|                       |    --enet-smac=<PC-MA |    and counters from  |
|                       | C-address>            |    the IPU1           |
|                       |    --enet-dmac=<EVM-M |    application        |
|                       | AC-address>           | -  Any EMAC errors    |
|                       |    -i ./ip1_test.pcap |    reported by the    |
|                       |    -o                 |    IPU1 application   |
|                       |    ./ip1_test.pcap)   |                       |
|                       |                       |                       |
|                       | Steps:                |                       |
|                       |                       |                       |
|                       | -  Launch the packETH |                       |
|                       |    utility on the     |                       |
|                       |    Linux PC with root |                       |
|                       |    permissions        |                       |
|                       | -  Go to the "Gen-S"  |                       |
|                       |    tab of the packETH |                       |
|                       |    utility and select |                       |
|                       |    the PCAP files to  |                       |
|                       |    be used            |                       |
|                       | -  Set the transfer   |                       |
|                       |    rate for each PCAP |                       |
|                       |    file (i.e. 200     |                       |
|                       |    Mbit/s and 150     |                       |
|                       |    Mbit/s)            |                       |
|                       | -  Set the total      |                       |
|                       |    packets to         |                       |
|                       |    transfer to 500000 |                       |
|                       | -  Load and run the   |                       |
|                       |    EMAC packet        |                       |
|                       |    inspection         |                       |
|                       |    application to the |                       |
|                       |    IPU1 core          |                       |
|                       | -  Hit the "Send"     |                       |
|                       |    button on the      |                       |
|                       |    packETH utility to |                       |
|                       |    start streaming    |                       |
|                       | -  The packet         |                       |
|                       |    streaming should   |                       |
|                       |    last for few       |                       |
|                       |    seconds            |                       |
|                       |                       |                       |
|                       | Additional changes    |                       |
|                       | can be made to the    |                       |
|                       | driver and            |                       |
|                       | application in order  |                       |
|                       | to reduce the CPU     |                       |
|                       | load and also         |                       |
|                       | increase the max      |                       |
|                       | traffic rate that can |                       |
|                       | be inspected. The     |                       |
|                       | changes are aimed to  |                       |
|                       | reduce the impact of  |                       |
|                       | cache management in   |                       |
|                       | the following areas   |                       |
|                       | of the receive data   |                       |
|                       | path:                 |                       |
|                       |                       |                       |
|                       | -  Skipping unneeded  |                       |
|                       |    cache invalidation |                       |
|                       |    for read only      |                       |
|                       |    buffers. After the |                       |
|                       |    application has    |                       |
|                       |    consumed a RX      |                       |
|                       |    packet, the        |                       |
|                       |    associated data    |                       |
|                       |    buffer has to be   |                       |
|                       |    cache invalidated  |                       |
|                       |    to ensure that the |                       |
|                       |    buffer doesn't     |                       |
|                       |    have any dirty     |                       |
|                       |    lines that could   |                       |
|                       |    cause problem      |                       |
|                       |    after giving it to |                       |
|                       |    the hardware. This |                       |
|                       |    example doesn't    |                       |
|                       |    change the content |                       |
|                       |    of the packet      |                       |
|                       |    buffer. It only    |                       |
|                       |    inspects the IPv6  |                       |
|                       |    header of each     |                       |
|                       |    packet. So this    |                       |
|                       |    cache invalidate   |                       |
|                       |    call can be safely |                       |
|                       |    skipped.           |                       |
|                       | -  Invalidating only  |                       |
|                       |    the region of      |                       |
|                       |    interest for       |                       |
|                       |    packet inspection. |                       |
|                       |    Allowing cache     |                       |
|                       |    management to be   |                       |
|                       |    done by the        |                       |
|                       |    application helps  |                       |
|                       |    narrowing the      |                       |
|                       |    invalidate area to |                       |
|                       |    what's actually    |                       |
|                       |    needed by the app, |                       |
|                       |    as opposed to      |                       |
|                       |    having the driver  |                       |
|                       |    invalidate the     |                       |
|                       |    entire packet      |                       |
|                       |    buffer. This       |                       |
|                       |    example inspects   |                       |
|                       |    the IPv6 header    |                       |
|                       |    area in order to   |                       |
|                       |    classify the       |                       |
|                       |    packets, so the    |                       |
|                       |    cache invalidate   |                       |
|                       |    size can be        |                       |
|                       |    reduced to the     |                       |
|                       |    first 56 bytes of  |                       |
|                       |    the packet buffer. |                       |
|                       |                       |                       |
|                       | Download and apply    |                       |
|                       | `this </index.php/Fil |                       |
|                       | e:PacketInspectionImp |                       |
|                       | rovements.zip>`__     |                       |
|                       | patch to the EMAC     |                       |
|                       | driver. The table     |                       |
|                       | below shows the       |                       |
|                       | expected M4 CPU load  |                       |
|                       | with and without the  |                       |
|                       | improvements          |                       |
|                       | described in the      |                       |
|                       | previous paragraph.   |                       |
|                       |                       |                       |
|                       | .. table::  M4 CPU    |                       |
|                       | Load (%)              |                       |
|                       |                       |                       |
|                       |    +---+---+---+---+  |                       |
|                       |    | T | B | R | R |  |                       |
|                       |    | r | a | / | / |  |                       |
|                       |    | a | s | O | O |  |                       |
|                       |    | f | e | B | B |  |                       |
|                       |    | f | l | u | u |  |                       |
|                       |    | i | i | f | f |  |                       |
|                       |    | c | n | f | f |  |                       |
|                       |    | ( | e | e | e |  |                       |
|                       |    | M | ( | r | r |  |                       |
|                       |    | b | R | s | s |  |                       |
|                       |    | p | T |   | + |  |                       |
|                       |    | s | O |   | I |  |                       |
|                       |    | ) | S |   | P |  |                       |
|                       |    |   | A |   | v |  |                       |
|                       |    |   | u |   | 6 |  |                       |
|                       |    |   | t |   | H |  |                       |
|                       |    |   | o |   | d |  |                       |
|                       |    |   | 4 |   | r |  |                       |
|                       |    |   | . |   | C |  |                       |
|                       |    |   | 3 |   | a |  |                       |
|                       |    |   | ) |   | c |  |                       |
|                       |    |   |   |   | h |  |                       |
|                       |    |   |   |   | e |  |                       |
|                       |    |   |   |   | I |  |                       |
|                       |    |   |   |   | n |  |                       |
|                       |    |   |   |   | v |  |                       |
|                       |    +===+===+===+===+  |                       |
|                       |    | 1 | 3 | 2 | 1 |  |                       |
|                       |    | 0 | 1 | 0 | 2 |  |                       |
|                       |    | 0 |   |   |   |  |                       |
|                       |    +---+---+---+---+  |                       |
|                       |    | 2 | 5 | 3 | 1 |  |                       |
|                       |    | 0 | 9 | 6 | 7 |  |                       |
|                       |    | 0 |   |   |   |  |                       |
|                       |    +---+---+---+---+  |                       |
|                       |    | 3 | 8 | 5 | 2 |  |                       |
|                       |    | 0 | 8 | 2 | 5 |  |                       |
|                       |    | 0 |   |   |   |  |                       |
|                       |    +---+---+---+---+  |                       |
|                       |    | 4 |   | 7 | 3 |  |                       |
|                       |    | 0 |   | 0 | 4 |  |                       |
|                       |    | 0 |   |   |   |  |                       |
|                       |    +---+---+---+---+  |                       |
|                       |    | 5 |   | 8 | 4 |  |                       |
|                       |    | 0 |   | 9 | 0 |  |                       |
|                       |    | 0 |   |   |   |  |                       |
|                       |    +---+---+---+---+  |                       |
|                       |    | 6 |   |   | 4 |  |                       |
|                       |    | 0 |   |   | 6 |  |                       |
|                       |    | 0 |   |   |   |  |                       |
|                       |    +---+---+---+---+  |                       |
|                       |    | 7 |   |   | 5 |  |                       |
|                       |    | 0 |   |   | 4 |  |                       |
|                       |    | 0 |   |   |   |  |                       |
|                       |    +---+---+---+---+  |                       |
+-----------------------+-----------------------+-----------------------+

.. rubric::  Additional References
   :name: additional-references

+-----------------------------------+-----------------------------------+
| **Document**                      | **Location**                      |
+-----------------------------------+-----------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\emac\docs\doxygen\html\index |
|                                   | .html                             |
+-----------------------------------+-----------------------------------+
| Release Notes                     | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\emac\docs\ReleaseNotes_EMAC_ |
|                                   | LLD.pdf                           |
+-----------------------------------+-----------------------------------+

.. raw:: html

