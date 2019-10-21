***************
TI-RTOS Kernel
***************
- `SYSBIOS <http://processors.wiki.ti.com/index.php?title=Category:SYSBIOS>`__


*******
XDAIS
*******
- `XDAIS <http://processors.wiki.ti.com/index.php?title=Category:XDAIS>`__


****
FC
****
- `Framework Components <http://processors.wiki.ti.com/index.php?title=Category:Framework_Components>`__

*******
IPC
*******

.. note:: This section mainly provides details of the software distributed part of the IPC 3.x package (installed under ipc_<version>). The IPC package provides the IPC APIs with higher level software abstraction. In addition,starting from  Processor SDK 6.1 release, a lower level IPC driver (IPC LLD) using rpmsg based transport is included specifically for AM6x/J7 platforms. See the following link for additional details `IPC 3.x vs IPC LLD`_

Inter-Processor Communication (IPC) provides a processor-agnostic API which can be used for communication between processors in a multi-processor environment (inter-core), communication to other threads on same processor (inter-process), and communication to peripherals (inter-device). 
The API supports message passing, streams, and linked lists.
IPC can be used to communicate with the following:

- Other threads on the same processor
- Threads on other processors running SYS/BIOS
- Threads on other processors running an HLOS (e.g., Linux, QNX, Android)

.. image:: ../images/IPC_comm_features.JPG

IPC User's Guide
================
.. include:: PDK_Platform_Software/IPC/IPC_Users_Guide.rst.inc

IPC Install Guides
====================
BIOS Install Guide
-------------------
.. include:: PDK_Platform_Software/IPC/IPC_Install_Guide_BIOS.rst.inc
Linux Install Guide
-------------------
.. include:: PDK_Platform_Software/IPC/IPC_Install_Guide_Linux.rst.inc
QNX Install Guide
-------------------
.. include:: PDK_Platform_Software/IPC/IPC_Install_Guide_QNX.rst.inc

Porting IPC
================
.. include:: PDK_Platform_Software/IPC/Porting_IPC.rst.inc

Optimizing IPC Applications
=============================
.. include:: PDK_Platform_Software/IPC/Optimizing_IPC_Applications.rst.inc

Rebuilding IPC
================
.. include:: PDK_Platform_Software/IPC/Rebuilding_IPC.rst.inc

TI SDO IPC Package
====================
.. include:: PDK_Platform_Software/IPC/The_ti.sdo.ipc_Package.rst.inc

IPC Module
------------
.. include:: PDK_Platform_Software/IPC/IPC_Module.rst.inc

MessageQ Module
-----------------
.. include:: PDK_Platform_Software/IPC/MessageQ_Module.rst.inc

ListMP Module
-----------------
.. include:: PDK_Platform_Software/IPC/ListMP_Module.rst.inc

HeapMP Module
-----------------
.. include:: PDK_Platform_Software/IPC/HeapMP_Modules.rst.inc

GateMP Module
-----------------
.. include:: PDK_Platform_Software/IPC/GateMP_Module.rst.inc

GateMP Support for UIO and Misc Driver 
---------------------------------------
.. include:: PDK_Platform_Software/IPC/IPC_GateMP_Support_for_UIO_and_Misc_Driver.rst.inc

Notify Module
-----------------
.. include:: PDK_Platform_Software/IPC/Notify_Module.rst.inc

Shared Region Module
----------------------
.. include:: PDK_Platform_Software/IPC/SharedRegion_Module.rst.inc


TI SDO Utils Package
=====================
.. include:: PDK_Platform_Software/IPC/The_ti.sdo.utils_Package.rst.inc

List Module
--------------
.. include:: PDK_Platform_Software/IPC/List_Module.rst.inc

MultiProc Module
-------------------
.. include:: PDK_Platform_Software/IPC/MultiProc_Module.rst.inc

NameServer Module
-------------------
.. include:: PDK_Platform_Software/IPC/NameServer_Module.inc

Use Cases for IPC
=============================
.. include:: PDK_Platform_Software/IPC/Use_Cases_for_IPC.rst.inc

| 

IPC Examples
=============
.. include:: PDK_Platform_Software/IPC/IPC_examples.rst.inc

IPC Tests
=============
.. include:: PDK_Platform_Software/IPC/IPC_Tests.rst.inc

IPC Daemon
=============
.. include:: PDK_Platform_Software/IPC/IPC_Daemon.rst.inc

IPC Transports
===============
.. include:: PDK_Platform_Software/IPC/IPC_Transports.rst.inc

IPC Benchmarking
==================
.. include:: PDK_Platform_Software/IPC/IPC_BenchMarking.rst.inc

IPC 3.x
========
.. include:: PDK_Platform_Software/IPC/IPC_3.x.rst.inc

Resource Custom Table
----------------------
.. include:: PDK_Platform_Software/IPC/IPC_Resource_customTable.rst.inc

Resource Usage
---------------
.. include:: PDK_Platform_Software/IPC/IPC_Resource_Usage.rst.inc

IPC 3.x vs IPC LLD
==================

IPC 3.x APIs provide High level IPC APIs that scale across all TI platforms.

Instead of the IPC 3.x APIs, in certain cases customers can choose to use the IPC Low level Driver (IPC LLD).

In general, the IPC LLD can be used, if the customer application falls under the following categories.

a) Non-RTOS bare metal applications (Note: IPC 3.x is closely coupled with  SYSBIOS and XDC tools)
b) Applications does not need the high level API abstraction and all the features (like GateMP etc) and would like to call the low level driver to just establish basic communication between the cores.
c) Application needs the same RPMSG/Virtio transport mechanism to communicate with a core running linux and other cores running other operating systems.

Please refer to the following page for details on the IPC LLD: `IPC LLD for AM65x/J721E <index_device_drv.html#ipclld>`_

IPC FAQ
========
.. include:: PDK_Platform_Software/IPC/IPC_3.x_FAQ.rst.inc

FAQ For Keystone Devices
-------------------------
.. include:: PDK_Platform_Software/IPC/IPC_FAQ_for_Keystone_Devices.rst.inc

***************
OpenCL
***************
`OpenCL <http://downloads.ti.com/mctools/esd/docs/opencl/index.html>`__


***************
Boot
***************
.. _FC-Boot-label:
.. include:: Boot.rst.inc


*****
MPM
*****
.. include:: MPM.rst.inc


*******
OpenMP
*******
.. include:: Compute/OpenMP.rst.inc


***************
PKTLIB
***************
.. include:: PDK_Platform_Software/Device_Drivers/PKTLIB.rst.inc

***************
Network
***************
CCLink
=======
.. include:: PDK_Platform_Software/Network_and_Transport/CCLink.rst.inc
NDK
=======
.. include:: PDK_Platform_Software/Network_and_Transport/NDK.rst.inc

NWAL
***************
.. include:: PDK_Platform_Software/Device_Drivers/NWAL.rst.inc

***************
Transport
***************
TimeSync (PTP)
==============
.. include:: PDK_Platform_Software/Network_and_Transport/TimeSync.rst.inc

***************
Tools
***************
- `Processor SDK RTOS Tools <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Tools>`__


+--------------------------------+--------------------------------------------------------------------------------------------------+
| .. Image:: ../images/E2e.jpg   | For technical support please post your questions at `http://e2e.ti.com <http://e2e.ti.com/>`__.  |
+--------------------------------+--------------------------------------------------------------------------------------------------+
