****************
Migration Guide
****************

.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Migration_Guide

.. rubric::  Overview
   :name: overview

This page covers migration information for applications built on top of
the last Processor SDK for RTOS release.
| 

.. rubric::  Processor SDK RTOS 05.01.00
   :name: processor-sdk-rtos-05.01.00

.. rubric::  Build
   :name: Build

**Migration:** Applicable for applications migrating from SOCs supporting EDMA LLD to AM65x  with updated DMA infrastructure. Additional UDMA driver support is available in package to support enhanced DMA infrastrcuture for AM65x
Drivers for AM65x SOC is extended to support UDMA LLD abstracting changes needed by application. Limited change will be required for application using drivers included in Processor SDK. 
| 
**Additional Details**: Modifications needed at application will be limited to initialization of UDMA driver using Udma_init() API in addition to linking  UDMA driver library. Driver Test code could be used as reference
Additional migration details for all cases are covered in  \ti\drv\udma\docs folder inside PDK package

**Migration:** For all drivers using DMA mode EDMA driver is updated to UDMA driver

**Additional Details**: Application will need to initialize UDMA driver and SCIClient interface using 
Udma_init() and Sciclient_init() API. Test code could be used as reference
| 

.. rubric::  Networking
   :name: Networking

**Migration:** Applicable for applications using NDK and Posix port of SysBIOS

**Additional Details**: Release introduces NS (Network Services Component) as independent portable networking API abstracting different network stacks. Detailed migration details is available at
`NDK 2.x to 3.x Migration Guide <http://software-dl.ti.com/targetcontent/ndk/3_40_01_01/exports/ndk_3_40_01_01/docs/ndk/NDK_2_to_3_Migration_Guide.html>`__
| 



.. raw:: html

