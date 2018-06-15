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

**Migration:** This is applicable for AM65x SOC. There is an updated infrastructure for the SOC which requires new driver UDMA support. 
For all drivers using DMA mode update is being handled internally to limit changes required for applications

| 

**Additional Details**: Application will need to initialize UDMA driver using Udma_init() API. Additionally it will need to link the UDMA driver library. Driver Test code could be used as reference

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

