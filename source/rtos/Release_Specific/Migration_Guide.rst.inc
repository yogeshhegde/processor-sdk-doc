****************
Migration Guide
****************

.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Migration_Guide

.. rubric::  Overview
   :name: overview

This page covers migration information for applications built on top of
the last Processor SDK for RTOS release.

| 

.. rubric::  Processor SDK RTOS 05.00.00
   :name: processor-sdk-rtos-05.00.00

.. rubric::  Build
   :name: Build

**Migration:** Applicable for applications migrating from SOCs supporting EDMA LLD to AM65x  with updated DMA infrastructure. Additional UDMA driver support is available in package to support enhanced DMA infrastrcuture for AM65x
Drivers for AM65x SOC is extended to support UDMA LLD abstracting changes needed by application. Limited change will be required for application using drivers included in Processor SDK. 
| 
**Additional Details**: Modifications needed at application will be limited to initialization of UDMA driver using Udma_init() API in addition to linking  UDMA driver library. Driver Test code could be used as reference
Additional migration details for all cases are covered in  \ti\drv\udma\docs folder inside PDK package

**Migration:** For all drivers using DMA mode EDMA driver is updated to UDMA driver

**Additional Details**: Application will need to initialize UDMA driver using 
Udma_init() API. Test code could be used as reference


| 

.. rubric::  Archived
   :name: archived
-  `Processor-SDK RTOS
   4.3.0 <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/04_03_00_05/rtos/Release_Specific.html#migration-guide>`__
-  `Processor-SDK RTOS
   4.2.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=232582>`__
-  `Processor-SDK RTOS
   4.1.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=232581>`__
-  `Processor-SDK RTOS
   4.0.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=228993>`__
-  `Processor-SDK RTOS
   3.3.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=223822>`__
-  `Processor-SDK RTOS
   3.2.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=223822>`__
-  `Processor-SDK RTOS
   3.1.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=221853>`__
-  `Processor-SDK RTOS
   3.0.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=219677>`__
-  `Processor-SDK RTOS
   2.0.2 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=219677>`__
-  `Processor-SDK RTOS
   2.0.1 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=219677>`__
-  `Processor-SDK RTOS
   2.0.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=219677>`__

| 

.. raw:: html

