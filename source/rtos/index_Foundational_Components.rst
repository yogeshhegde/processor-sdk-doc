.. _foundational-components-ti-rtos-kernel:

***************
TI-RTOS Kernel
***************
- `SYSBIOS <https://www.ti.com/tool/SYSBIOS>`__


.. _foundational-components-xdais:

*******
XDAIS
*******
- `XDAIS <http://processors.wiki.ti.com/index.php?title=Category:XDAIS>`__


.. _foundational-components-fc:

****
FC
****
- `Framework Components <http://processors.wiki.ti.com/index.php?title=Category:Framework_Components>`__

.. _foundational-components-ipc:

*******
IPC
*******

.. note:: This section mainly provides details of the software distributed part of the IPC 3.x package (installed under ipc_<version>). The IPC package provides the IPC APIs with higher level software abstraction. In addition,starting from  Processor SDK 6.1 release, a lower level IPC driver (IPC LLD) using rpmsg based transport is included specifically for AM6x/J7 platforms. See the following link for additional details `IPC 3.x vs IPC LLD`_

.. note:: Starting with releases after the 6.3 release, IPC3.x will be deprecated on the AM65x device and IPC LLD is the only IPC stack supported. Please stop new development on top of IPC3.x for AM65x, and migrate to IPC LLD stack. Please see `IPC LLD for AM65x/J721E <index_device_drv.html#ipclld>`_ for information on IPC LLD.

IPC User's Guide
================
.. include:: /rtos/PDK_Platform_Software/IPC/_IPC_Users_Guide.rst

Use Cases for IPC
=============================
.. include:: /rtos/PDK_Platform_Software/IPC/_Use_Cases_for_IPC.rst



IPC Examples
=============

.. include:: /rtos/PDK_Platform_Software/IPC/_IPC_examples.rst

IPC Training
=============

.. include:: /common/IPC/_IPC_Training.rst

TI SDO IPC Package
====================
.. include:: /rtos/PDK_Platform_Software/IPC/_The_ti.sdo.ipc_Package.rst

IPC Module
------------
.. include:: /rtos/PDK_Platform_Software/IPC/_IPC_Module.rst

MessageQ Module
-----------------
.. include:: /rtos/PDK_Platform_Software/IPC/_MessageQ_Module.rst

ListMP Module
-----------------
.. include:: /rtos/PDK_Platform_Software/IPC/_ListMP_Module.rst

HeapMP Module
-----------------
.. include:: /rtos/PDK_Platform_Software/IPC/_HeapMP_Modules.rst

GateMP Module
-----------------
.. include:: /rtos/PDK_Platform_Software/IPC/_GateMP_Module.rst

GateMP Support for UIO and Misc Driver
---------------------------------------
.. include:: /rtos/PDK_Platform_Software/IPC/_IPC_GateMP_Support_for_UIO_and_Misc_Driver.rst

Notify Module
-----------------
.. include:: /rtos/PDK_Platform_Software/IPC/_Notify_Module.rst

Shared Region Module
----------------------
.. include:: /rtos/PDK_Platform_Software/IPC/_SharedRegion_Module.rst



TI SDO Utils Package
=====================
.. include:: /rtos/PDK_Platform_Software/IPC/_The_ti.sdo.utils_Package.rst

List Module
--------------
.. include:: /rtos/PDK_Platform_Software/IPC/_List_Module.rst

MultiProc Module
-------------------
.. include:: /rtos/PDK_Platform_Software/IPC/_MultiProc_Module.rst

NameServer Module
-------------------
.. include:: /rtos/PDK_Platform_Software/IPC/NameServer_Module.inc


Optimizing IPC Applications
=============================
.. include:: /rtos/PDK_Platform_Software/IPC/_Optimizing_IPC_Applications.rst

Rebuilding IPC
================
.. include:: /rtos/PDK_Platform_Software/IPC/_Rebuilding_IPC.rst


|

IPC Transports
===============
.. include:: /common/IPC/_IPC_Transports.rst

IPC Benchmarking
==================
.. include:: /rtos/PDK_Platform_Software/IPC/_IPC_BenchMarking.rst

IPC 3.x
========
.. include:: /rtos/PDK_Platform_Software/IPC/_IPC_3.x.rst

Resource Custom Table
----------------------
.. include:: /rtos/PDK_Platform_Software/IPC/_IPC_Resource_customTable.rst

Resource Usage
---------------
.. include:: /rtos/PDK_Platform_Software/IPC/_IPC_Resource_Usage.rst

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
.. include:: /rtos/PDK_Platform_Software/IPC/_IPC_3.x_FAQ.rst

FAQ For Keystone Devices
-------------------------
.. include:: /rtos/PDK_Platform_Software/IPC/_IPC_FAQ_for_Keystone_Devices.rst

IPC Install Guides
====================
The IPC package now comes bundled with Processor SDK RTOS and can be built using the top-level makefile located in the Processor SDK RTOS folder. These install guides have been kept here for those using older, legacy versions of IPC.

BIOS Install Guide
-------------------
.. include:: /rtos/PDK_Platform_Software/IPC/_IPC_Install_Guide_BIOS.rst

Linux Install Guide
-------------------
.. include:: /rtos/PDK_Platform_Software/IPC/_IPC_Install_Guide_Linux.rst

QNX Install Guide
-------------------
.. include:: /rtos/PDK_Platform_Software/IPC/_IPC_Install_Guide_QNX.rst


.. _foundational-components-opencl:

***************
OpenCL
***************
`OpenCL <http://downloads.ti.com/mctools/esd/docs/opencl/index.html>`__


.. _foundational-components-boot:

***************
Boot
***************
.. _FC-Boot-label:
.. include:: /rtos/_Boot.rst


.. _foundational-components-mpm:

*****
MPM
*****
.. include:: /rtos/_MPM.rst


.. _foundational-components-openmp:

*******
OpenMP
*******
.. include:: /rtos/Compute/_OpenMP.rst


.. _foundational-components-pktlib:

***************
PKTLIB
***************
.. include:: /rtos/PDK_Platform_Software/Device_Drivers/_PKTLIB.rst

.. _foundational-components-network:

***************
Network
***************
CCLink
=======
.. include:: /rtos/PDK_Platform_Software/Network_and_Transport/_CCLink.rst

.. _foundational-components-ndk:

NDK
=======
.. include:: /rtos/PDK_Platform_Software/Network_and_Transport/_NDK.rst

.. _foundational-components-nwal:

NWAL
***************
.. include:: /rtos/PDK_Platform_Software/Device_Drivers/_NWAL.rst

.. _foundational-components-transport:

***************
Transport
***************
TimeSync (PTP)
==============
.. include:: /rtos/PDK_Platform_Software/Network_and_Transport/_TimeSync.rst

.. _foundational-components-tools:

***************
Tools
***************
- `Processor SDK RTOS Tools <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Tools>`__


+--------------------------------+--------------------------------------------------------------------------------------------------+
| .. Image:: /images/E2e.jpg     | For technical support please post your questions at `http://e2e.ti.com <http://e2e.ti.com/>`__.  |
+--------------------------------+--------------------------------------------------------------------------------------------------+
