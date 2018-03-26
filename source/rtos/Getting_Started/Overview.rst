.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Software_Developer_Guide 

.. rubric:: Introduction
   :name: introduction

The Texas Instruments **Processor Software Development Kit
(Processor-SDK)** is a single scalable software platform that offers
streamlined development across different `TI Sitara/DSP
Processors <http://www.ti.com/lsds/ti/processors/overview.page>`__. The
Processor-SDK for RTOS provides fundamental platform software and tools
for development, deployment and execution of RTOS-based applications. It
includes the following, though not all features are applicable across
all supported platforms:

-  TI-RTOS kernel, a light-weight real-time embedded operating system
   for TI devices
-  Chip support libraries, drivers, and basic board-support utilities
-  Interprocessor communication for communication across cores and
   devices
-  Basic networking stack and protocols
-  Optimized C66x algorithm libraries
-  Debug and instrumentation utilities
-  Bootloaders and boot utilities
-  Demonstrations and examples

Combined with TI Code Composer Studio integrated development environment
(IDE), the Processor-SDK provides the core foundational building blocks
that facilitate application software development on TI's embedded
processors.

.. rubric:: Scope
   :name: scope

The purpose of this guide is to quickly provide the information you need
most while evaluating and developing applications on a TI embedded
processor, specifically running embedded real-time operating system. It
is not intended to be a thorough design document. As such, the focus is
on application programming interfaces (API), build information, and
examples to use as a template to start development.

.. rubric:: Guides
   :name: guides

**Processor SDK RTOS**

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

`**Getting Started
Guide** </index.php/Processor_SDK_RTOS_Getting_Started_Guide>`__ ←
**Start Here**

`**Release Notes** </index.php/Processor_SDK_RTOS_Release_Notes>`__

`Examples and
Demonstrations </index.php/Processor_SDK_RTOS_Examples_and_Demonstrations>`__

`RTOS Software Stack </index.php/Processor_SDK_RTOS_Software_Stack>`__

`Directory Structure
Overview </index.php/Processor_SDK_RTOS_Directory_Structure>`__

`Building the SDK </index.php/Processor_SDK_RTOS_Building_The_SDK>`__

`Training <https://training.ti.com/processor-sdk-training-series>`__

`Migration Guide </index.php/Processor_SDK_RTOS_Migration_Guide>`__

`Technical Support </index.php/Processor_SDK_Technical_Support>`__

`How To Guides </index.php/Processor_SDK_RTOS_How_To_Guides>`__

`Related Software </index.php/Processor_SDK_RTOS_Related_Software>`__

`Frequently Asked Questions (FAQ) </index.php/Processor_SDK_RTOS_FAQ>`__

`Supported Platforms and
Versions </index.php/Processor_SDK_Supported_Platforms_and_Versions>`__

**Board/EVM Abstration**

`Diagnostics </index.php/Processor_SDK_RTOS_DIAG>`__

`Board Support </index.php/Processor_SDK_RTOS_Board_Support>`__

`Power-On Self Test </index.php/Processor_SDK_RTOS_POST>`__

**Foundational Components**

`TI-RTOS
Kernel <http://processors.wiki.ti.com/index.php?title=Category:SYSBIOS>`__

`Boot </index.php/Processor_SDK_RTOS_Boot>`__

`IPC </index.php/IPC_Users_Guide>`__

`MPM </index.php/MultiprocMgr>`__

`OpenMP </index.php/OpenMP_on_C6000>`__

`FC <http://processors.wiki.ti.com/index.php?title=Category:Framework_Components>`__

`OpenCL <http://downloads.ti.com/mctools/esd/docs/opencl/index.html>`__

`Network </index.php/Processor_SDK_RTOS_NDK>`__

`XDAIS <http://processors.wiki.ti.com/index.php?title=Category:XDAIS>`__

`PKTLIB </index.php/Processor_SDK_RTOS_PKTLIB>`__

`NWAL </index.php/Processor_SDK_RTOS_NWAL>`__

`Tools </index.php/Processor_SDK_RTOS_Tools>`__

**DSP Optimized Libraries**

`MATHLIB </index.php/Processor_SDK_Libraries>`__

`IMGLIB </index.php/Processor_SDK_Libraries>`__

`DSPLIB </index.php/Processor_SDK_Libraries>`__

`FFTLIB </index.php/Processor_SDK_Libraries>`__

`LINALG </index.php/Processor_SDK_Libraries>`__

**DSP Debug and Trace**

`CToolsLib </index.php/CToolsLib>`__

`UIA </index.php/Multicore_System_Analyzer#Unified_Instrumentation_Architecture_.28UIA.29>`__

`Trace </index.php/Processor_SDK_RTOS_TF>`__

`Fault Mgt </index.php/Processor_SDK_RTOS_FM>`__

`WDT </index.php/Processor_SDK_RTOS_WDT>`__

****

.. raw:: html

   <div id="Device_Drivers">

Device Drivers

.. raw:: html

   </div>

`CSL </index.php/Processor_SDK_RTOS_CSL>`__

`UART </index.php/Processor_SDK_RTOS_UART>`__

`USB </index.php/Processor_SDK_RTOS_USB>`__

`PCIe </index.php/Processor_SDK_RTOS_PCIe>`__

`GPIO </index.php/Processor_SDK_RTOS_GPIO>`__

`I2C </index.php/Processor_SDK_RTOS_I2C>`__

`QSPI-McSPI </index.php/Processor_SDK_RTOS_QSPI-McSPI>`__

`EDMA3 </index.php/Processor_SDK_RTOS_EDMA3>`__

`ICSS-EMAC(DRIVER,FIRMWARE) </index.php/Processor_SDK_RTOS_ICSS-EMAC(DRIVER,FIRMWARE)>`__

`PRUSS </index.php/Processor_SDK_RTOS_PRUSS>`__

`FATFS </index.php/Processor_SDK_RTOS_FATFS>`__

`MMCSD </index.php/Processor_SDK_RTOS_MMCSD>`__

`QMSS </index.php/Processor_SDK_RTOS_QMSS>`__

`CPPI </index.php/Processor_SDK_RTOS_CPPI>`__

`PA </index.php/Processor_SDK_RTOS_PA>`__

`SA </index.php/Processor_SDK_RTOS_SA>`__

`SRIO </index.php/Processor_SDK_RTOS_SRIO>`__

`HYPLNK </index.php/Processor_SDK_RTOS_HYPLNK>`__

`TSIP </index.php/Processor_SDK_RTOS_TSIP>`__

`MCBSP </index.php/Processor_SDK_RTOS_MCBSP>`__

`EMAC </index.php/Processor_SDK_RTOS_EMAC>`__

`MCASP </index.php/Processor_SDK_RTOS_MCASP>`__

`PM </index.php/Processor_SDK_RTOS_PM>`__

`RM </index.php/Processor_SDK_RTOS_RM>`__

`GPMC </index.php/Processor_SDK_RTOS_GPMC>`__

`VPS Drivers </index.php/Processor_SDK_RTOS_VPS_DRIVERS>`__

****

.. raw:: html

   <div id="Device_Driver_Utilities">

Device Driver Utilities

.. raw:: html

   </div>

`OSAL </index.php/Processor_SDK_RTOS_OSAL>`__

`Profiling </index.php/Processor_SDK_RTOS_PROFILING>`__

****

.. raw:: html

   <div id="Compilers">

Compilers

.. raw:: html

   </div>

`TI C6000 <http://www.ti.com/lit/pdf/sprui04>`__

`TI ARM <http://www.ti.com/lit/pdf/spnu151>`__

`TI PRU <http://www.ti.com/lit/pdf/spruhv>`__

`Linaro GCC ARM <https://launchpad.net/gcc-arm-embedded>`__

.. raw:: html

   <div class="block-note">

**Note:** To get to this page, you can also use the shortcut:
http://www.ti.com/processor_sdk_rtos

.. raw:: html

   </div>

| 

.. raw:: html

