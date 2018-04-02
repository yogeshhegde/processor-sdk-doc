.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Migration_Guide

.. rubric::  Overview
   :name: overview

This page covers migration information for applications built on top of
the last Processor SDK for RTOS release.

| 

.. rubric::  Processor SDK RTOS 04.03.00
   :name: processor-sdk-rtos-04.03.00

.. rubric::  General
   :name: general

.. rubric::  OSAL
   :name: osal

**Migration:** No impact expected if Semaphore allocation and HwIP
registration from OSAL is not invoked by application.

**Additional Details**: OSAL module is fine tuned for optimized number
of semaphores required internally within drivers. Module provides
additional API to application for additional semaphore allocation if
required.Application can configure for either default internal static
allocation or it can select external memory block that can be provided
to create these objects. Note that this decision to go with external
memory block or internal memory block need to be done during init
configuration of application (near to main) just after Board_init() is
called. Below sample code sets SemaphoreP/HwiP to be used from external
memory block:

``...``

::

       ...
       /* Get the Hw Attrs */
       osal_ret = Osal_getHwAttrs(&hwAttrs);
       if (osal_ret != osal_OK)
       {
           return (false);
       }
       /* This API should set to use external memory block */
       hwAttrs.extSemaphorePBlock.base = (uintptr_t) &semPMemBlock[0];
       hwAttrs.extSemaphorePBlock.size = SEMP_BLOCK_SIZE;
       hwAttrs.extHwiPBlock.size       = HWIP_BLOCK_SIZE;
       hwAttrs.extHwiPBlock.base       = (uintptr_t) &hwiPMemBlock[0];
       osal_ret = Osal_setHwAttrs(ctrlBitMap, &hwAttrs);

.. rubric::  Board
   :name: board

**Migration:** Section details applicable only to applications based on
DRA7xx SoCs.

**Additional Details**: DRA7xx board libraries have refactored pad
configuration sequence by removing manual pinmux entries and replacing
them with a full IODELAY reconfiguration procedure. This was done in
order to simplify transition from a standalone application development
in CCS to booting the whole device via SBL, ensuring that pad
configuration is 100% consistent between the two application loading
methods.

The IODELAY and pin control data structures are maintained in each of
evmDRA72x and evmDRA75x board library source directories. These
structures are also included in the SBL compilation and used in the
SBL's IODELAY reconfiguration. Therefore, changes can be made in one
location but reused by both Board and SBL components just through
recompilation.

Note that DRA78x does not require IODELAY reconfiguration and pinmux
setup is always contained entirely in the application. Hence, there are
no corresponding changes to this library.

All of this is done in a transparent manner, so there is **no API
change** and will not affect existing applications. However, there are
considerations with respect to memory placement and potential conflicts
between the board library and SBL code. These restrictions have always
existed but are now more clearly defined and documented. Please refer to
`Board
Support <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Board_Support>`__
for more details.

.. rubric::  I2C
   :name: i2c

**Migration:** No migration required for existing user application.

**Additional Details**: PRUICSS based I2C Firmware have been introduced
in this release. This new features increases the number of I2C interface
available in the SOC. I2C LLD now depends on PRUSS LLD for compilation
of this new feature. All of this is done in a transparent manner, so
there is **no API change** and will not affect existing applications.
However, for using the I2C FW feature refer :ref:`I2C FW <PRU-ICSS-I2C-FIRMWARE-label>` for additional
details.

| 

.. rubric::  Archived
   :name: archived

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

