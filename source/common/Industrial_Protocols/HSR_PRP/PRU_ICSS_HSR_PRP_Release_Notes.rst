.. http://processors.wiki.ti.com/index.php/PRU_ICSS_HSR_PRP_Release_Notes

Release Notes
================================

Overview
----------------

The **PRU-ICSS HSR PRP package** provides the foundation that facilitate
application software development for HSR PRP Adapter on TI Sitara
Embedded Processors with PRU-ICSS HW IP.

| 

Licensing
--------------------

Please refer to the software manifest, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page or in the installed directory as
indicated below.

| 

Documentation
---------------------------

-  `Software Developer
   Guide <http://processors.wiki.ti.com/index.php/Industrial_Protocol_Package_Software_Developer_Guide>`__:
   Provides information on features, functions, delivery package and,
   compile tools for the release. This also provides detailed
   information regarding software elements and software infrastructure
   to allow developers to start creating applications.
-  `Getting Started
   Guide <http://processors.wiki.ti.com/index.php/Industrial_Protocol_Package_Getting_Started_Guide>`__:
   provides information on getting the software and running basic
   examples/demonstrations bundled in the package.
-  `User Guide <http://processors.wiki.ti.com/index.php/PRU_ICSS_HSR_PRP>`__: Documentation of
   key API and interface changes from last release.
-  **HSR PRP Datasheet**: Data sheet contains information about the
   capabilities of the solution, certification information (if
   applicable), memory and pin mux information. It can be found in the
   'docs' folder in the installation directory. The directory structure
   is shown in the user guide `here <http://processors.wiki.ti.com/index.php/PRU_ICSS_HSR_PRP>`__
-  **Software Manifest**: Provides license information on software
   included in the package. The manifest can be found on the SDK
   download page or in the installed directory. The directory structure
   is shown in the user guide `here <http://processors.wiki.ti.com/index.php/PRU_ICSS_HSR_PRP>`__
-  **EVM Quick Start Guide**: Provides information on hardware setup and
   running the demonstration application that is loaded on flash. This
   document is provided as part of the EVM kit.

| 

System Requirements
---------------------------

1.0.3 release uses the PROCESSOR-SDK-RTOS 04\_02\_00\_09 which is
available at:

-  AM335x family :
   http://software-dl.ti.com/processor-sdk-rtos/esd/AM335X/04_02_00_09/index_FDS.html
-  AM437x family :
   http://software-dl.ti.com/processor-sdk-rtos/esd/AM437X/04_02_00_09/index_FDS.html
-  AM57x family:
   http://software-dl.ti.com/processor-sdk-rtos/esd/AM57X/04_02_00_09/index_FDS.html
-  K2G family :
   http://software-dl.ti.com/processor-sdk-rtos/esd/K2G/04_02_00_09/index_FDS.html

Alternatively one can follow "Previous SDK Link" from Processor SDK RTOS
release page (
http://software-dl.ti.com/processor-sdk-rtos/esd/<Soc>/latest/index_FDS.html
)

| 

Release 01.00.03
---------------------

Released February 2018

What's New
^^^^^^^^^^^^^^^^

-  PRU-ICSS HSR-PRP Software support for AMIC1x
-  256 entries Node Table support on AM57x and K2G
-  Multicast Filter Support
-  Bug Fixes

Platforms supported
^^^^^^^^^^^^^^^^^^^^^^^

-  AM335x
-  AM437x
-  AM57x
-  K2G
-  AMIC1x

Features supported
^^^^^^^^^^^^^^^^^^^^^^^^

-  **HSR/PRP**

   -  The implementation is as per IEC 62439-3 Ed 2.0
   -  Operates as a DAN (Dual Attached Node)

-  **HSR**

   -  Operates as a DANH
   -  As per clause 5 of the standard
   -  Support for modes – H, T, U and N as per standard
   -  Modes can be changed at run time

-  **PRP**

   -  Operates as a DANP
   -  As per clause 6 of the standard
   -  Two ports as per standard, Port A and Port B

-  **Support for Node Table**

   -  Total 128 entries on AMICx, AM335x, AM437x
   -  Total 256 entries on AM57xx & K2G
   -  Hash Table for faster lookup
   -  O(1) complexity
   -  Node Table statistics

-  **Support for Multicast Filtering**

   -  Supported on all SoCs
   -  Hash Table for faster lookup
   -  O(1) complexity

-  **Duplicate Discard Table**

   -  Duplicate discard on Port to Host path (HSR and PRP)
   -  Duplicate discard table on Port to Port path (HSR)
   -  Data integrity (CRC) check during port to port forwarding, except
      cut through (HSR)

-  **PHY Configuration**

   -  Duplex : Full/Auto
   -  Speed : 100/Auto
   -  10mbps and Half duplex modes are not supported

-  **QoS scheme** : 3-bit VLAN PCP

   -  No of levels supported : 8
   -  Number of host queues : 2 \| 4 QoS levels per host queue
   -  Number of port queues : 4 \| 2 QoS levels per port queue

-  **Statistics**

   -  Supports all MIB statistics as per standard
   -  Node Table statistics for debugging
   -  Self configuring

-  **PTP/1588**

   -  PTP Slave and Master mode
   -  Supports P2P clock.
   -  PTP over 802.3 (Annex F)
   -  Transparent Clock supported
   -  Ordinary Clock supported
   -  Single and Two step clock supported
   -  Peer delay Response is always sent as two-step

-  **Storm Prevention** : Yes. Configurable per port

| 

What is not supported
^^^^^^^^^^^^^^^^^^^^^^^^^^^

-  BMCA for PTP/1588

   -  See User Guide on how to switch between Slave and Master

-  Boundary clock
-  Multi domain support for SYNC

| 

PRU-ICSS Firmware Revision
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

+---------------------------+-----------+---------------------------------------+
| Platform                  | Build     | Firmware Header Location              |
+===========================+===========+=======================================+
| AM335x, AM437x, AMIC11x   | [2.A.E]   | protocols\\hsr\_prp\\firmware\\v1.0   |
+---------------------------+-----------+---------------------------------------+
| AM571x, AM572x, K2G       | [2.A.E]   | protocols\\hsr\_prp\\firmware\\v2.1   |
+---------------------------+-----------+---------------------------------------+

| 

Fixed Issues
^^^^^^^^^^^^^^^^^^^

+---------------+------------------------------------------------+-----------------------------------------------------------------------------------------------------------+
| Record ID     | Platform                                       | Details                                                                                                   |
+===============+================================================+===========================================================================================================+
| PINDSW-1046   | AM335x, AM437x, AMIC11x, AM571x, AM572x, K2G   | PRP nodetable fixes & counter fixes due to timing mismatch.                                               |
+---------------+------------------------------------------------+-----------------------------------------------------------------------------------------------------------+
| PINDSW-1047   | AM335x, AM437x, AMIC11x, AM571x, AM572x, K2G   | HSR nodetable fixes & counter fixes due to timing mismatch.                                               |
+---------------+------------------------------------------------+-----------------------------------------------------------------------------------------------------------+
| PINDSW-1494   | AM335x, AM437x, AMIC11x, AM571x, AM572x, K2G   | HSR: Packet loss seen at firmware when running iperf TCP/UDP test                                         |
+---------------+------------------------------------------------+-----------------------------------------------------------------------------------------------------------+
| PINDSW-1495   | AM335x, AM437x, AMIC11x, AM571x, AM572x, K2G   | HSR: firmware node\_table shows incorrect values & unexpected lreErrorsA/B                                |
+---------------+------------------------------------------------+-----------------------------------------------------------------------------------------------------------+
| PINDSW-1742   | K2G                                            | PTP sync disabled on K2G platform                                                                         |
+---------------+------------------------------------------------+-----------------------------------------------------------------------------------------------------------+
| PINDSW-1745   | K2G                                            | LinkISR doesnt update status properly when application starts with both ports up                          |
+---------------+------------------------------------------------+-----------------------------------------------------------------------------------------------------------+
| PINDSW-1755   | K2G                                            | K2G board flash memory access issues                                                                      |
+---------------+------------------------------------------------+-----------------------------------------------------------------------------------------------------------+
| PINDSW-1885   | AM335x, AM437x, AMIC11x, AM571x, AM572x, K2G   | HSR/PRP: add per receive port host queues in PRU firmware                                                 |
+---------------+------------------------------------------------+-----------------------------------------------------------------------------------------------------------+
| PINDSW-1953   | Sitara                                         | Bridge Delay correction not done correctly for 2-step Sync, will result in sync issues in a long chain.   |
+---------------+------------------------------------------------+-----------------------------------------------------------------------------------------------------------+
| PINDSW-1977   | AM335x, AM437x, AMIC11x, AM571x, AM572x, K2G   | Fixed stats PRU Level rxOctets, TX stat count & rxUcast counter                                           |
+---------------+------------------------------------------------+-----------------------------------------------------------------------------------------------------------+
| PINDSW-2004   | AM335x, AM437x, AMIC11x, AM571x, AM572x, K2G   | Enable transparent clock in HSR irrespective of PTP configuration                                         |
+---------------+------------------------------------------------+-----------------------------------------------------------------------------------------------------------+
| PINDSW-2030   | AM571x                                         | AM571x application crashes when PRU-ICSS 1 is enabled                                                     |
+---------------+------------------------------------------------+-----------------------------------------------------------------------------------------------------------+
| PINDSW-2119   | AM437x                                         | Exception in PRP startup and Tx/Rx test on am437x-idk IDK                                                 |
+---------------+------------------------------------------------+-----------------------------------------------------------------------------------------------------------+

| 

Known Issues
^^^^^^^^^^^^^^^^^^^^^

This section contains the list of known Issues at the time of making the
release.

+---------------+------------------------------------------------+--------------------------------------------------------------------------------------------------------+----------------------------------------------------------------------------------------------+
| Record ID     | Platform                                       | Details                                                                                                | Workaround                                                                                   |
+===============+================================================+========================================================================================================+==============================================================================================+
| PINDSW-913    | AM335x, AM437x, AMIC11x, AM571x, AM572x, K2G   | Check for numStepsRemoved field in BMCA for redundant clock not implemented as BMCA not implemented.   | None                                                                                         |
+---------------+------------------------------------------------+--------------------------------------------------------------------------------------------------------+----------------------------------------------------------------------------------------------+
| PINDSW-1746   | AM335x, AM437x, AMIC11x, AM571x, AM572x, K2G   | PTP driver is not multi-instance capable                                                               | None                                                                                         |
+---------------+------------------------------------------------+--------------------------------------------------------------------------------------------------------+----------------------------------------------------------------------------------------------+
| PINDSW-1968   | AM335x, AM437x, AMIC11x, AM571x, AM572x, K2G   | Sync0 output interval changes on resetting IEP counter and CMP1 register                               | None                                                                                         |
+---------------+------------------------------------------------+--------------------------------------------------------------------------------------------------------+----------------------------------------------------------------------------------------------+
| PINDSW-2154   | AM335x, AM437x, AMIC11x, AM571x, AM572x, K2G   | HSR : Duplicate ARP seems to be forwarded to other port                                                | None                                                                                         |
+---------------+------------------------------------------------+--------------------------------------------------------------------------------------------------------+----------------------------------------------------------------------------------------------+
| PINDSW-2294   | AM335x, AM437x, AMIC11x, AM571x, AM572x, K2G   | Higher jitter observed in forced 2-step mode                                                           | None                                                                                         |
+---------------+------------------------------------------------+--------------------------------------------------------------------------------------------------------+----------------------------------------------------------------------------------------------+
+---------------+------------------------------------------------+--------------------------------------------------------------------------------------------------------+----------------------------------------------------------------------------------------------+
| PRSDK-3086    | AM335x, AM437x, AMIC11x, AM571x, AM572x, K2G   | Interrupt modification due change to host queue remapping scheme.                                      | Patch and rebuild the ICSS EMAC LLD & NIMU ICSS LLD. Rebuild of driver libraries required.   |
+---------------+------------------------------------------------+--------------------------------------------------------------------------------------------------------+----------------------------------------------------------------------------------------------+
| PRSDK-3454    | AM335x, AM437x, AMIC11x, AM571x, AM572x, K2G   | Modification due to mismatch in finalPrioQueue variable.                                               | Patch and rebuild the ICSS EMAC LLD.                                                         |
+---------------+------------------------------------------------+--------------------------------------------------------------------------------------------------------+----------------------------------------------------------------------------------------------+

| 

| 

Key APIs & interface changes
--------------------------------

-  `This
   section <http://processors.wiki.ti.com/index.php/HSRPRP_Key_API_and_interface_changes>`__
   provides important information on the application porting to the
   current version of PRU-ICSS-HSR-PRP-DAN software
