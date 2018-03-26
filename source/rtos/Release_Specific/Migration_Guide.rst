.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Migration_Guide

.. rubric:: Overview
   :name: overview

This page covers migration information for applications built on top of
the last Processor SDK for RTOS release.

| 

.. rubric:: Processor SDK RTOS 04.02.00
   :name: processor-sdk-rtos-04.02.00

.. rubric:: General
   :name: general

.. rubric:: GCC Toolchain Migration to 6-2017-q1
   :name: gcc-toolchain-migration-to-6-2017-q1

**Migration:** Limited to TI-RTOS based application on ARM Cortex-A
cores ****

**Additional Details**: Processor SDK RTOS components includes updates
to be compatible with GCC tool chain. This includes updates to SysBIOS,
compiler and linker options. Following migration changes required for
applications

::

     o Compiler options: Add nano libs to Include path 
         Example: gcc-arm-none-eabi-6-2017-q1-update/arm-none-eabi/include/newlib-nano
     o Linker Options: Replace fpu lib paths with hard lib and enable nano specs
         Example:  "<SYS/BIOS Root>/packages/gnu/targets/arm/libs/install-native/arm-none-eabi/lib/fpu"   
         with "<SYS/BIOS Root>/packages/gnu/targets/arm/libs/install-native/arm-none-eabi/lib/hard --specs=nano.specs”

Additional references

::

     o PDK Project Creation Scipt: <pdk_soc_x_x_x/packages/pdkProjectCreate.[bat/sh]> 
     o SMP/BIOS SYS/BIOS user guide with GCC migration details 
      

-  **Note**: For baremetal applications, stack section needs to be
   aligned to 8 bytes. Updated GCC toolchain is more stringent on memory
   alignment requirement. Misalignment can result in unexpected run time
   failures.

.. rubric:: EMAC Library
   :name: emac-library

**Migration:** Limited to C6657, OMAPL137/C6747 and OMAPL138/C6748 SoCs

**Additional Details**: Interrupt setup and ISR functions are
implemented in the driver. Interrupt handling in applications need to be
removed to use the latest driver version. Use EMAC_socGetInitCfg and
EMAC_socSetInitCfg functions to change the default interrupt mapping in
HW attributes if required.

Example:

::

    EMAC_HwAttrs_V0             emac_hwattr;  /* Local instance for HW attributes */
    EMAC_OPEN_CONFIG_INFO_T     open_cfg;

    EMAC_socGetInitCfg(port_num, &emac_hwattr);  /* Get default SOC HW attributes */
    emac_hwattr.txIntrNum = <Int Num>  /* Change default interrupt mapping Optional: if needed */
    EMAC_socSetInitCfg(port_num, &emac_hwattr); /* Change the default HW attributes */
    open_cfg.hwAttrs = &emac_hwattr;  /* Assign HW attributes to configuration parameters */
    emac_open(port_num, &open_cfg);

.. rubric:: Archived
   :name: archived

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
-  `MCSDK to Processor SDK
   Migration <http://processors.wiki.ti.com/index.php?title=MCSDK_to_Processor_SDK_Migration>`__

| 

.. raw:: html