.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_RM 

.. rubric:: Introduction
   :name: introduction

The Resource Manager (RM) is delivered as part of Processor-SDK as a
means for managing system resource contentions. RM has the ability to
allocate system resources within a software architecture based on sets
of allocation rules. Resources can be allocated to anything from a
device core, to an OS task or process, to a specific software module.
RM's resource management is defined by the RM configuration parameters
and how RM is integrated within a software framework. The RM source code
is device agnostic. The RM configuration parameters are device specific
allowing RM to function on any processor capable of compiling and
executing a C binary.

.. rubric:: RM Instance Types
   :name: rm-instance-types

Resource Manager is an instance-based architecture. Integrating RM into
a system consists of creating a set of RM instances, connecting these
instances via message-passing mechanisms, and then using the instances
to request resources for cores, processes, tasks, modules, etc. There
are no restrictions on where a RM instance can be created as long as the
means exist to connect the instance to other RM instances within the
system.

There are five instance types

#. **Server**: Manages all defined system resources. Services resource
   requests received from connected Client Delegates and Clients.
#. **Client Delegate (CD)**: Acts as a low-request-latency proxy for the
   RM Server, managing resources provided by the RM Server. Services
   resource requests received from connected Clients.
#. **Client**: Front-end for receiving/responding to resource requests
   from application. Forwards resource requests to Server, or CD, for
   servicing. Returns allocated resources to application once response
   is received from Server or CD.
#. **Shared Server**: Same as the standard Server except all resource
   data structures are stored in shared memory allowing direct access
   from Shared Client instances.
#. **Shared Client**: Same as Client except has direct access to the
   Server resource data structures via shared memory. Useful for low
   latency requests but not as robust from a software architecture
   perspective given shared memory MUST be available and used in order
   for Shared Server-Clients to function.

.. rubric:: Driver Configuration
   :name: driver-configuration

.. rubric:: **Resource Configuration**
   :name: resource-configuration

The RM Server instance must be provided a resource list and allocation
policy at initialization time. The resource list and allocation policy
are specified in the open source flattened device tree format. Device
specific resource list and allocation policy files are provided in
``[PDK_INSTALL_PATH]/packages/ti/drv/rm/device/[SoC]/``.

The Client Delegate and Client instances do not require a resource list
and allocation policy at initialization.

.. rubric:: **Transport Configuration**
   :name: transport-configuration

RM instances must be attached to one another using a message passing
mechanism. This mechanism can be shared memory, software/hardware
queues, sockets or any other method capable of sending and receiving
data packets between endpoints on the SoC.

An example transport implementation used by many PDK test applications
is available in
``[PDK_INSTALL_PATH]/packages/ti/drv/rm/test/rm_transport_setup.c``. The
implementation uses an IPC shared memory transport to connect an RM
Server to RM Clients on multiple DSP cores.

.. rubric:: **APIs**
   :name: apis

RM instance init/delete/status API reference for application:

::

    #include <ti/drv/rm/rm.h>

RM instance transport API reference for application:

::

    #include <ti/drv/rm/rm_transport.h>

RM instance service request/response API reference for application:

::

    #include <ti/drv/rm/rm_services.h>

RM Server interface API reference for application:

::

    #include <ti/drv/rm/rm_server_if.h>

.. rubric:: Tests
   :name: tests

+-----------------------+-----------------------+-----------------------+
| Name                  | Description           | Expected Results      |
+=======================+=======================+=======================+
| RM DSP BIOS Test      | | Unit Test           | | Application         |
| application           |   application         |   successfully        |
|                       |   exercising APIs and |   completes on two    |
|                       |   the different       |   DSP cores.          |
|                       |   service             |                       |
|                       |   request/response    |                       |
|                       |   mechanisms across   |                       |
|                       |   the Server, Client  |                       |
|                       |   Delegate, and       |                       |
|                       |   Client instances.   |                       |
+-----------------------+-----------------------+-----------------------+
| RM Memory DSP BIOS    | | Unit Test           | | Application         |
| Test application      |   application to test |   successfully        |
|                       |   for memory leaks    |   completes with no   |
|                       |   during resource     |   memory leaks on two |
|                       |   request/free        |   DSP cores.          |
|                       |   operations.         |                       |
+-----------------------+-----------------------+-----------------------+
| RM Shared DSP BIOS    | | Unit Test           | | Application         |
| Test application      |   application         |   successfully        |
|                       |   exercising Shared   |   completes with no   |
|                       |   Server/Client APIs  |   memory leaks on two |
|                       |   and resource        |   DSP cores.          |
|                       |   allocation in a     |                       |
|                       |   Shared              |                       |
|                       |   Server/Client       |                       |
|                       |   architecture.       |                       |
+-----------------------+-----------------------+-----------------------+
| RM DSP BIOS           | | Unit Test           | | Application         |
| Multi-Threaded Test   |   application         |   successfully        |
| application           |   verifying service   |   completes with no   |
|                       |   request/response    |   memory leaks on a   |
|                       |   mechanism in a      |   single DSP core.    |
|                       |   multi-threaded      |                       |
|                       |   architecture.       |                       |
+-----------------------+-----------------------+-----------------------+
| RM ARM Linux Test     | | Unit Test           | | Application         |
| application           |   application         |   successfully        |
|                       |   exercising APIs and |   completes when run  |
|                       |   the different       |   from Linux          |
|                       |   service             |   user-space.         |
|                       |   request/response    |                       |
|                       |   mechanisms across   |                       |
|                       |   the Server, Client  |                       |
|                       |   Delegate, and       |                       |
|                       |   Client instances.   |                       |
+-----------------------+-----------------------+-----------------------+
| RM ARM Linux          | | Unit Test           | | Application         |
| Multi-Threaded Test   |   application         |   successfully        |
| application           |   verifying service   |   completes when run  |
|                       |   request/response    |   from Linux          |
|                       |   mechanism in a      |   user-space.         |
|                       |   multi-threaded      |                       |
|                       |   architecture.       |                       |
+-----------------------+-----------------------+-----------------------+
| Combined DSP BIOS &   | | Unit Test           | | Application         |
| ARM Linux Test        |   application         |   successfully        |
| application           |   verifying service   |   completes with no   |
|                       |   request/response    |   memory leaks on two |
|                       |   mechanism over a    |   DSP cores.          |
|                       |   heterogeneous       |                       |
|                       |   processor boundary. |                       |
|                       |   RM Clients on two   |                       |
|                       |   DSP cores request   |                       |
|                       |   resources from an   |                       |
|                       |   RM Server running   |                       |
|                       |   in Linux            |                       |
|                       |   user-space.         |                       |
+-----------------------+-----------------------+-----------------------+

.. rubric:: Additional References
   :name: additional-references

+-----------------------------------+-----------------------------------+
| **Document**                      | **Location**                      |
+-----------------------------------+-----------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\rm\docs\doxygen\html\index.h |
|                                   | tml                               |
+-----------------------------------+-----------------------------------+
| Release Notes                     | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\rm\docs\ReleaseNotes_RM.pdf  |
+-----------------------------------+-----------------------------------+
| Resource Manager User Guide       | `Processor_SDK_Resource_Manager < |
|                                   | /index.php/Processor_SDK_Resource |
|                                   | _Manager>`__                      |
+-----------------------------------+-----------------------------------+

.. raw:: html

