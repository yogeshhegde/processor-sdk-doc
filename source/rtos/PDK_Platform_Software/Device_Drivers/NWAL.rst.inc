.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_NWAL 

| 

.. rubric:: Introduction
   :name: introduction

| The NWAL (Network Adaptation Layer) driver provides a well-defined set
  of APIs which could be used for applications interfacing with NetCP
  (Network Coprocessor) module in Keystone family of SOCs (C66x, K2x).

.. rubric:: Driver Features
   :name: driver-features

-  Initialization of NetCP low level driver resources
-  Initialization of Packet DMA related resources associated with NetCP
-  Classification of incoming packets based on L2: MAC header fields
-  Classification of incoming packets based on L3: IPv4/IPv6 header
   fields
-  Routing of packets to host based on L4: UDP/TCP/GTP-U
-  Unidirectional IPSec SA creation and deletion
-  In band offload of IPSec encryption/decryption for the outgoing
   packets
-  Access to SA data mode acceleration for data plane applications.
-  Supports offload of the following features to NETCP Hardware during
   transmission of packets:

   -  IPv4 checksum/L4:TCP/UDP checksum/IPSec Encryption
   -  Redirection of packets through a specific MAC port
   -  Software Insertion of L2/L3/L4 header

-  Upon reception of packet, module provides additional meta data
   details including:

   -  Status of IP checksum/UDP/TCP checksum results
   -  Offset to L2/L3/L4 protocol offsets. Appropriate layer offset will
      be valid only if classification or routing is enabled at NETCP
   -  Ingress MAC port information

.. rubric:: Modes of Operation
   :name: modes-of-operation

Following modes of operations are supported by NWAL when sending control
configuration request to configure NetCP firmware. **BLOCKING Mode**: In
this mode, status of API request used to configure NetCP is returned
back in API call context.

**Non-BLOCKING Mode**: In this mode, application can invoke a separate
poll routine to retrieve status response result.

| 

.. rubric:: Driver Configuration
   :name: driver-configuration-nwal

The driver configures the NWAL subsystem using the nwalGlobCfg_t
structure.

This structure must be initialized before the nwal_create() function API
is called and cannot be changed afterwards. For details regarding
individual fields of this structure, see the Doxygen help by opening
PDK_INSTALL_DIR\packages\ti\drv\nwal\docs\doxygen\html\index.html.

.. rubric:: **APIs**
   :name: apis

API reference for application can be found in below file:

::

    #include <ti/drv/nwal/nwal.h>

.. rubric:: Example
   :name: example

+-----------------------+-----------------------+-----------------------+
| Name                  | Description           | Expected Results      |
+=======================+=======================+=======================+
| nwalUnitTest          | | Unit Test           | | User observes the   |
| Application           |   application to test |   output printed over |
|                       |   all APIs            |   the CCS console     |
+-----------------------+-----------------------+-----------------------+

.. rubric:: Additional References
   :name: additional-references

+-----------------------------------+-----------------------------------+
| **Document**                      | **Location**                      |
+-----------------------------------+-----------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\nwal\docs\doxygen\html\index |
|                                   | .html                             |
+-----------------------------------+-----------------------------------+
| Release Notes                     | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\nwal\docs\ReleaseNotes_NWAL_ |
|                                   | LLD.pdf                           |
+-----------------------------------+-----------------------------------+


