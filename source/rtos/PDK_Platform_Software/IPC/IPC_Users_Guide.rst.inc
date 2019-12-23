.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide 
        
.. |ipcCfg_Img| Image::  ../images/Book_cfg.png
               :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img| Image::  ../images/Book_run.png
               :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/index.html


Inter-Processor Communication (IPC) provides a processor-agnostic API which can be used for communication between processors in a multi-processor environment (inter-core), communication to other threads on same processor (inter-process), and communication to peripherals (inter-device). 
The API supports message passing, streams, and linked lists.
IPC can be used to communicate with the following:

- Other threads on the same processor
- Threads on other processors running SYS/BIOS
- Threads on other processors running an HLOS (e.g., Linux, QNX, Android)

.. image:: ../images/IPC_comm_features.JPG

Overview
========
This user's guide contains the topics in the following list. It also
links to API reference documentation for static configuration (|ipcCfg_Img|)
and run-time C processing (|ipcRun_Img|) for each module.

**Getting Started**

-  `Use Cases for IPC <index_Foundational_Components.html#use-cases-for-ipc>`__ explains the various use cases for IPC.

-  `IPC Examples <index_Foundational_Components.html#ipc-examples>`__ explains how
   to build and generate the IPC examples.

-  `IPC Training <index_Foundational_Components.html#ipc-training>`__ lists available IPC training. 

-  `IPC 3.x <index_Foundational_Components.html#ipc-3-x>`__
   Provides details of IPC 3.x releases
   
-  `Run IPC Examples on AM572x <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/index_how_to_guides.html#run-ipc-examples-on-am572x>`__

-  `Run IPC Examples on AM65xx <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/index_how_to_guides.html#run-ipc-examples-on-am65xx>`__

**Application Development**

-  `Create DSP and IPU firmware using PDK drivers and IPC to load from ARM Linux on AM57xx devices <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/How_to_Guides.html#create-dsp-and-ipu-firmware-using-pdk-drivers-and-ipc-to-load-from-arm-linux-on-am57xx-devices>`__

-  `Customizing Memory map for creating Multicore Applications on AM57xx using IPC <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/How_to_Guides.html#customizing-memory-map-for-creating-multicore-applications-on-am57xx-using-ipc>`__

-  `Optimizing IPC
   Applications <index_Foundational_Components.html#optimizing-ipc-applications>`__
   provides hints for improving the runtime performance and shared
   memory usage of applications that use IPC.
   
-  `IPC
   Benchmarking <index_Foundational_Components.html#ipc-benchmarking>`__
   IPC Benchmarking with IPC 3.x
   
-  `IPC Custom
   ResourceTable <index_Foundational_Components.html#resource-custom-table>`__
   Provides details of customizing the resource table.
   
-  `IPC Debugging Tools and Techniques on AM57xx <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/How_to_Guides.html#ipc-debugging-tools-and-techniques-on-am57xx>`__

**IPC Internal/API & Other Useful Links**

-  `The TI SDO IPC Package <index_Foundational_Components.html#ti-sdo-ipc-package>`__
   section describes the modules in the ti.sdo.ipc package.

-  `The TI SDO Utils Package <index_Foundational_Components.html#ti-sdo-utils-package>`__
   section describes the modules in the ti.sdo.utils package.

-  `IPC 3.x Migration
   Guide <http://processors.wiki.ti.com/index.php/IPC_3.x_Migration_Guide>`__
   Provides details of migrating to IPC 3.x from previous releases
   
-  `IPC GateMP Support for UIO and Misc
   Driver <index_Foundational_Components.html#gatemp-support-for-uio-and-misc-driver>`__
   Provides details of IPC GateMP support with UIO driver 

-  `RTOS IPC
   Transports <index_Foundational_Components.html#ipc-transports>`__
   explains details of the additional RTOS IPC transports provided via
   the Processor SDK PDK component.
   
-  `Rebuilding IPC <index_Foundational_Components.html#rebuilding-ipc>`__
   explains how to rebuild the IPC libraries if you modify the source
   files.

**FAQ**

-  `IPC 3.x
   FAQ <index_Foundational_Components.html#ipc-faq>`__
   Frequently asked questions on IPC 3.x
   
| 

.. note::
   Please see the release notes in your IPC installation before starting to
   use IPC. The release notes contain important information about feature
   support, issues, and compatibility information for a particular release.

| 

