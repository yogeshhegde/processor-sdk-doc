.. http://processors.wiki.ti.com/index.php/MCSDK1.1_to_Processor_SDK_Migration_Guide_for_OMAPL13x/C674x_devices

MCSDK1.1 to Processor SDK Migration Guide for OMAPL13x/C674x devices
=======================================================================

**Processor SDK v4.0 release from Texas Instruments adds support for
OMAPL13x/C674x and aligns the platform software with newer ARM and DSP
based SOC's.**

All new development efforts should use Processor SDK instead of
previously supported Starterware, C6BIOS SDK and MCSDK software. This
the only software package that TI supports on these devices for new
development.

|

High level Processor SDK and MCSDK comparison
-----------------------------------------------

+--------------------------+--------------------------+--------------------------+
| SW CATEGORIES            | Processor SDK            | `MCSDK`_                 |
+==========================+==========================+==========================+
| Device Supported         | OMAPL138, C6748,         | OMAPL138, C6748          |
|                          | OMAPL137, C6747          |                          |
+--------------------------+--------------------------+--------------------------+
| H/W platform             | OMAPL138/C6748 LCDK,     | OMAPL138 LCDK, C6748     |
|                          | OMAPL137/C6747 EVM       | LCDK                     |
+--------------------------+--------------------------+--------------------------+
| HLOS                     | Linux v4.9               | Linux v3.3               |
+--------------------------+--------------------------+--------------------------+
| RTOS                     | SysBIOS 6.46             | SysBIOS 6.35             |
+--------------------------+--------------------------+--------------------------+
| IPC Stack                | IPC (RTOS),              | SYSLink                  |
|                          | RemoteProc/RpMsg (Linux) |                          |
+--------------------------+--------------------------+--------------------------+
| Optimized DSP Algorithm  | DSPLIB, IMGLIB, MATHLIB  | DSPLIB, IMGLIB, MATHLIB  |
| Libraries                |                          |                          |
+--------------------------+--------------------------+--------------------------+
| Network Stack            | None                     | None                     |
+--------------------------+--------------------------+--------------------------+
| LLD Driver Component     | PDK 1.0 (See comparison  | PDK 1.0.1 (See           |
|                          | below)                   | comparison below)        |
+--------------------------+--------------------------+--------------------------+

.. _MCSDK: http://processors.wiki.ti.com/index.php/MCSDK_User_Guide_for_OMAPL138

Processor SDK RTOS OMAPL13x Features
----------------------------------------

-  Processor SDK provides separate packages for Linux (Processor SDK
   Linux) and RTOS/bare-metal (Processsor SDK RTOS) software
   development.
-  Device Drivers will maintain common APIs that aligns with all
   supported SoCs in the Processor SDK baseline.
-  Processor SDK RTOS OMAPL13x is combined SDK that supports
   OMAPL138/OMAPL137/C6747/C6748 devices. MCSDK1.1 supported only
   OMAPL138/C6748 devices.
-  Processor SDK RTOS adds support for TI RTOS on ARM9 core. MCSDK
   supported only bare-metal or Linux on the ARM.
-  Processor SDK adds support for latest CCSv7 and latest TI RTOS kernel
   6.46
-  Processor SDK includes C6000 CG Tools 8.x and TI ARM compiler

.. rubric:: New components
   :name: new-components

-  `CCS
   Integration <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Getting_Started_Guide#Setting_up_CCS_for_EVM_and_Processor-SDK_RTOS>`__:
   Processor SDK RTOS doesn\`t provide generated CCS projects but
   requires users to setup the environment and run the script. This
   allows the SDK to adapt to the custom development and software
   install paths. Creation of example projects is described in the
   article [PDK\_Example\_and\_Test\_Project\_Creation Create Peripheral
   driver Examples in CCS]
-  `Board
   Library <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Board_Support>`__:
   SOC and platform initialization is unified in the board library.
   MCSDK relied on functional CSL and GEL files to setup the SOC
   initialization like clocks, pinmux, DDR and PSC conigurations. All of
   this is not consolidated in a board library that initializes the SOC
   and board specific external components.
-  `OS abstraction
   layer <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_OSAL>`__:
   The OS abstraction layer in Processor SDK is implemented to better
   integrate with no-OS and TI RTOS environment.
-  `FAT Filesystem
   support <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_FATFS>`__:
   FATFS support that was dropped in MCSDK is brought into the Processor
   SDK RTOS.
-  `Secondary
   Bootloader <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Boot>`__:
   Processor SDK RTOS introduces a secondary bootloader in addition
   which allows additional customization to the boot process and allows
   users to boot combined ARM +DSP images. Starterware users will be
   familiar with this offering and associated boot utilities.
-  `Diagnostics <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_DIAG>`__:Diagnostic
   package is designed to be a set of baremetal tests to run on a given
   board to provide data path continuity testing on peripherals

.. rubric:: Migrating from existing CSL and LLD code:
   :name: migrating-from-existing-csl-and-lld-code

-  CSL in Processor SDK RTOS is organized into SOC specific, core
   specific and IP specific directories.

   -  Core specific CSL defines:
      pdk\_omapl13x\_x\_x\_x\\packages\\ti\\csl\\arch\\C67x and
      pdk\_omapl13x\_x\_x\_x\\packages\\ti\\csl\\arch\\arm9
   -  IP Specific CSL defines:
      pdk\_omapl13x\_x\_x\_x\\packages\\ti\\csl\\src\\ip
   -  SOC specific CSL defines:
      pdk\_omapl13x\_x\_x\_x\\packages\\ti\\csl\\soc


.. note::

 Users are recommended to use CSL header files from top level
 directory with the correct SOC define as described below:

-  CSL requires users to define the correct SOC defines to pick the
   appropriate register and functional CSL APIs.

**SOC define for C6748 and OMAPL138 users:**

::

    #define SOC_OMAPL138

**SOC define for C6747 and OMAPL137 users:**

::

    #define SOC_OMAPL137

.. rubric:: Device driver comparison of Processor SDK RTOS and MCSDK
   :name: device-driver-comparison-of-processor-sdk-rtos-and-mcsdk

+--------------------+-------------------+----------------------------------+
| Module             | PDK               | PDK                              |
|                    | (Part of MCSDK)   | (Part of Processor SDK RTOS)     |
+====================+===================+==================================+
| Device Supported   | OMAPL138          | OMAPL138/C6748, OMAPL137/C6747   |
+--------------------+-------------------+----------------------------------+
| EDMA3              | LLD               | LLD                              |
+--------------------+-------------------+----------------------------------+
| McASP              | LLD               | LLD                              |
+--------------------+-------------------+----------------------------------+
| McBSP              | LLD               | x                                |
+--------------------+-------------------+----------------------------------+
| I2C                | x                 | LLD                              |
+--------------------+-------------------+----------------------------------+
| SPI                | x                 | LLD                              |
+--------------------+-------------------+----------------------------------+
| UART               | x                 | LLD                              |
+--------------------+-------------------+----------------------------------+
| MMCSD              | x                 | LLD                              |
+--------------------+-------------------+----------------------------------+
| GPIO               | x                 | LLD                              |
+--------------------+-------------------+----------------------------------+

.. rubric:: Inter-processor communication(IPC) migration
   :name: inter-processor-communicationipc-migration

MCSDK supported IPC mechanism using SYSLINK for OMAPL138 devices. This
components is no longer supported. Processor SDK RTOS integrates IPC 3.x
for RTOS users and pairs it with remoteproc and RPMsg supported
Processor SDK Linux to provide the IPC functionality.

To migrate to IPC 3.x supported in Processor SDK, please refer to `IPC
Migration
Guide <http://processors.wiki.ti.com/index.php/IPC_3.x_Migration_Guide>`__

| 

Processor SDK Linux Migration
--------------------------------

.. rubric:: Installation
   :name: installation

-  Processor SDK Linux is available as an installer on ti.com for
   download

.. rubric:: Target Machine
   :name: target-machine

-  The Processor SDK Linux installer is available only for 64-bit host
   machines running Linux. Support for 32-bit machines is dropped
   primarily due to the Linzro toolchain not supporting 32-bit anymore.
   Host support for the SDK is described in the `Release
   Notes <Release_Specific.html#host_support>`__

| 

.. rubric:: Tool Chain
   :name: tool-chain

-  Processor Linux SDK is using Linaro GCC 6.2-2016.11 cross compiler.

.. rubric:: Directory Structure
   :name: directory-structure

-  The images directory in MCSDK is renamed to prebuilt\_images and
   moved under board\_support directory.
-  In addition to the prebuilt\_images and filesystem, the Linux
   installer now contains a copy of the Linux Kernel and U-Boot GIT
   repositories.
-  A script create-sdcard.sh is provided in bin directory to create the
   SD card using prebuilt images in Processor SDK.
-  host-tools folder in MCSDK is not included in Processor SDK. Pinmux
   utility can be downloaded from ti.com. Aisgen utility is replaced by
   dd command to generate the u-boot ais image.
-  For an overview of the directory structure and a brief description of
   the contents of the folders, please refer to `Processor SDK Linux
   Directory
   Structure <Overview.html#processor-sdk-linux-directory-structure>`__

.. rubric:: U-Boot
   :name: u-boot

-  Bootz is enabled in u-boot. So use zImage instead of uImage
-  A copy of u-boot GIT repo is included in the board-support folder of
   the Processor SDK installation
-  Aisgen utility is not used in Processor SDK to generate the U-Boot
   ais image, but using dd command:

::

      $ sudo dd if=u-boot.ais of=/dev/sd<N> seek=117 bs=512 conv=fsync

-  For more details, refer to `Processor SDK U-Boot Release
   Notes <Foundational_Components.html#u-boot-release-notes>`__
   and `Processor SDK U-Boot User’s
   Guide <Foundational_Components.html#u-boot-user-s-guide>`__

.. rubric:: Linux Kernel
   :name: linux-kernel

-  The Linux kernel is upgraded to 4.9.
-  A copy of Kernel GIT repo is included in the board-support folder of
   the Processor SDK installation
-  Kernel is device tree (.dts) based, and not board platform based
   implementation.
-  For more details, refer to `Processor SDK Kernel Release
   Notes <Foundational_Components.html#kernel-release-notes>`__
   and `Processor SDK Kernel User’s
   Guide <Foundational_Components.html#users-guide>`__

.. rubric:: Building the Linux SDK
   :name: building-the-linux-sdk

-  The Processor SDK Linux can be fully assembled from sources, via
   Yocto.
-  The instructions on how to build the Processor SDK Linux are
   available in `Building the Linux
   SDK <Overview.html#processor-sdk-linux-building-the-sdk>`__

.. rubric:: Inter-Processor Communication (IPC)
   :name: inter-processor-communication-ipc

-  Processor SDK supports IPC 3.x. As described in Section 2.4, it is
   not Syslink based implementation.
-  To migrate to IPC 3.x, please refer to `IPC 3.x Migration
   Guide <http://processors.wiki.ti.com/index.php/IPC_3.x_Migration_Guide>`__

