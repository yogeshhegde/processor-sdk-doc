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


.. rubric::  PDK
   :name: PDK
   
**Migration:** AM65xx PDK component dependency on sciclient module.

**Impact Scope:** Applications will need to link to sciclient module library. 
No migration impact if application is already linking the library.

**Additional Details**: 
All application using PDK components on AM65xx platform will need to link sciclient library 
as components internally will be using sciclient API for PLL and interrupt configuration. 
In this release, requirement for application will be more mandated as more components
are using common infrastructure.

DMSC firmware should be loaded onto Cortex-M4 core using SBL or 
`CCS GEL script <index_how_to_guides.html#advanced-am65x-debug-setup-with-dmsc-firmware-load>`_
before calling the Board Init API with 'BOARD_INIT_PLL' flag.


.. rubric::  Board
   :name: Board

**Migration:** New APIs for EEPROM Board ID Information

**Impact Scope:** Applications using Board ID info APIs on AM65xx platform. 
No migration impact for existing applications and boards using version 1 API.

**Additional Details**: 
TI Board ID information format has been updated to new version on AM65xx.
New board library APIs 'Board_getIDInfo_v2' and 'Board_writeIDInfo_v2' are added
to support new Board ID information format. Old Board ID info APIs are still avaialble
to retain the backward build compatibility but returns error when used on AM65xx platform.


  
.. rubric::  FATFS
   :name: FATFS

**Migration:** FATFS module in this release includes multipartition support and capability of 
detecting single vs multiple partitions run time.

**Impact Scope:** Limited to the case if user had used MS-DOS Floppy disk format for formatting the SD/eMMC memory. No impact if the SD/eMMC is formatted using the steps provided by `Windows SD Card Creation Guide <index_overview.html#windows-sd-card-creation-guide>`_/
`Linux SD Card Creation Guide <index_overview.html#tools-create-sd-card-linux-label>`_

**Additional Details**:
Partition entry information may be wrongly detected for the storage media formated to 
MS-DOS Floppy disk format. FATFS APIs fail to access the disk in this case.

**Workaround**:
Format the storage media using the steps provided by `Windows SD Card Creation Guide <index_overview.html#windows-sd-card-creation-guide>`_/
`Linux SD Card Creation Guide <index_overview.html#tools-create-sd-card-linux-label>`_
in case this issue is observed.

.. raw:: html

