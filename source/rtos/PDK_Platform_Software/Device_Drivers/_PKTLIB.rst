.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_PKTLIB

.. rubric:: Introduction
   :name: introduction

The packet library (PKTLIB) provides higher layer of abstraction for
underlying CPPI hardware descriptors to application layer.
Functionalities include:

-  Zero copy operation for:

   -  Packet split/merge operations
   -  Cloning operations
   -  Headroom/Tail room addition through merge operation

-  Allocations of packet buffer and descriptors during startup time
-  Allows packet allocation by HW at Rx CPPI DMA
-  Efficient recycling of data buffers including the case of buffers
   being referenced by multiple CPPI descriptors

.. rubric:: Modes of Operation
   :name: modes-of-operation

A pktlib heap can be created in on of the following two modes:

-  Private: only visible on the core where the heap was created
-  Shared: visible across multiple cores

.. rubric:: Driver Configuration
   :name: driver-configuration-pktlib

Applications can use Pktlib_createHeap() API to create heap(s) in the
system and heap properties are specified by the Pktlib_HeapCfg
configuration structure. This configuration structure should be
populated by the application and passed to the PKTLIB module when a heap
is being created via the Pktlib_createHeap() API. Multiple heaps can
exist in the system where each heaps properties are specified by the
Pktlib_HeapCfg configuration structure.

For details about individual fields of this structure, see the Doxygen
help by opening
<PDK_INSTALL_DIR>/packages/ti/runtime/pktlib/docs/doxygen/html/index.html.

.. rubric:: **APIs**
   :name: apis

API reference for application can be found in below file:

::

    #include <ti/runtime/pktlib/pktlib.h>

.. rubric:: Example
   :name: example

+-----------------------+-----------------------+-----------------------+
| Name                  | Description           | Expected Results      |
+=======================+=======================+=======================+
| pktlibUnitTest        | | Unit Test           | | User observes the   |
| Application           |   application to test |   output printed over |
|                       |   all APIs            |   the CCS console     |
+-----------------------+-----------------------+-----------------------+

.. rubric:: Additional References
   :name: additional-references

+-----------------------------------+-----------------------------------+
| **Document**                      | **Location**                      |
+-----------------------------------+-----------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)/packages/ti |
|                                   | /runtime/pktlib/docs/doxygen/html |
|                                   | /index.html                       |
+-----------------------------------+-----------------------------------+
| Release Notes                     | $(TI_PDK_INSTALL_DIR)/packages/ti |
|                                   | /runtime/pktlib/docs/ReleaseNotes |
|                                   | _pktlib.pdf                       |
+-----------------------------------+-----------------------------------+

