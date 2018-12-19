****************
Migration Guide
****************

.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Migration_Guide

.. rubric::  Overview
   :name: overview

This page covers migration information for applications built on top of
the last Processor SDK for RTOS release.
| 

.. rubric::  Processor SDK RTOS 05.02.00
   :name: processor-sdk-rtos-05.02.00


.. rubric::  SBL
   :name: SBL

**Migration:** Image integration and memory map changes

**Additional Details**: Release supports optimized boot times for booting MCU1_0 core
from OSPI flash. To reduce the size of the SBL,  the system firmware image, which was
earlier embedded in the SBL, is now a separate binary. The system firmware image can
be found at <PDK>/packages/ti/drv/sciclient/soc/V0/sysfw.bin

For MMC/SD boot, if the steps followed in `Creating bootable SD card in windows 
<http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Creating_a_SD_Card_with_Windows>`__ 
or `Creating bootable SD card in Linux <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_create_SD_card_script>`__
are used, no additional steps are need. If the SD card is being created manually, then the
"sysfw.bin" file also needs to be copied into the root directory of the MMC SD card, along with
"tiboot3.bin" and "app"

For OSPI boot, the flash offsets have changed. "sysfw.bin" needs to be programmed into OSPI flash at 
offset 0x40000 (new for this release), along with "sbl_ospi_img_mcu1_0_release.tiimage" at offset 0x0 
(no change from previous release) and the "app" at offset **0xA0000** (was 0x80000 previous release). 
For details please refer `Programming the OSPI flash <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/Board_EVM_Abstration.html#uniflash>`__

Applications that the SBL loads must co-exist with the SBL's memory usage.In the application's linker command file, 
care must be taken to not use the first 0x100 bytes of  MCU1_0's ATCM memory and SBL reserved memory from 0x41C00100 
to 0x41C28000. If the applications violate the SBL memory usage, then apps that were working with the last release 
might not work any more, as the memory constraints are tighter. For details, refer the `SBL Memory Utilization
<http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/Foundational_Components.html#am655x-sbl-memory-usage>`__

.. raw:: html

