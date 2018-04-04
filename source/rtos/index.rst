
.. _Index-Processor-SDK-RTOS-label:
Processor SDK RTOS
=================================================================

.. rubric:: Introduction
   :name: introduction

The Texas Instruments Processor Software Development Kit (Processor-SDK)
is a single scalable software platform that offers streamlined development 
across different TI `Sitara/DSP Processors <http://www.ti.com/lsds/ti/processors/overview.page>`__.
The Processor-SDK for RTOS provides fundamental platform software and tools 
for development, deployment and execution of RTOS-based applications. 
It includes the following, though not all features are applicable across 
all supported platforms:

-  TI-RTOS kernel, a light-weight real-time embedded operating system for TI devices
-  Chip support libraries, drivers, and basic board-support utilities
-  Interprocessor communication for communication across cores and devices
-  Basic networking stack and protocols
-  Optimized C66x algorithm libraries
-  Debug and instrumentation utilities
-  Bootloaders and boot utilities
-  Demonstrations and examples

Combined with TI Code Composer Studio integrated development environment (IDE), 
the Processor-SDK provides the core foundational building blocks that facilitate 
application software development on TI's embedded processors.

.. rubric:: Scope
   :name: scope

The purpose of this guide is to quickly provide the information you need most while 
evaluating and developing applications on a TI embedded processor, specifically 
running embedded real-time operating system. It is not intended to be a thorough 
design document. As such, the focus is on application programming interfaces (API), 
build information, and examples to use as a template to start development.

.. toctree::
   :maxdepth: 5
   :hidden:
   :numbered:

   Overview
   Release_Specific
   Board_EVM_Abstration
   Foundational_Components
   DSP_Software
   Device_Drivers
   PRU_ICSS
   Compilers
   Examples_and_Demonstrations
   How_to_Guides
   FAQ



.. rubric:: Guides
   :name: guides
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| **Processor SDK RTOS**                                                                                                                                 |
+========================================================================+===============================================================================+
| `Getting Started Guide`_  <-- **Start Here**                           | `Release Notes`_                                                              | 
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
|  `Examples and Demonstrations`_                                        | `RTOS Software Stack`_                                                        |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| `Directory Structure Overview`_                                        | `Building the SDK`_                                                           |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| `Training <https://training.ti.com/processor-sdk-training-series>`__   | `Migration Guide`_                                                            |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| `Technical Support`_                                                   | `How To Guides`_                                                              |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| `Related Software`_                                                    | `Frequently Asked Questions (FAQ)`_                                           |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| `Supported Platforms and Versions`_                                                                                                                    |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+


.. _Getting Started Guide: Overview.html#getting-started-guide
.. _Release Notes: Release_Specific.html#release-notes
.. _Examples and Demonstrations: Examples_and_Demonstrations.html
.. _RTOS Software Stack: Overview.html#rtos-software-stack
.. _Directory Structure Overview: Overview.html#directory-structure
.. _Building the SDK: Overview.html#building-the-sdk
.. _Migration Guide: Release_Specific.html#migration-guide
.. _Technical Support: Overview.html#technical-support
.. _How To Guides: How_to_Guides.html
.. _Related Software: Overview.html#related-software
.. _Frequently Asked Questions (FAQ): FAQ.html
.. _Supported Platforms and Versions: Release_Specific.html#supported-platforms-and-versions

+---------------------+-------------------+---------------------+-------------------+
| **Board/EVM Abstration**                                                          |
+=====================+===================+=====================+===================+
| `Diagnostics`_      | `Board Support`_  |`Power-On Self Test`_|                   |
+---------------------+-------------------+---------------------+-------------------+

.. _Diagnostics: Board_EVM_Abstration.html#diagnostics
.. _Board Support: Board_EVM_Abstration.html#board-support
.. _Power-On Self Test: Board_EVM_Abstration.html#power-on-self-test

+---------------------+-------------------+--------------------+--------------------+
| **Foundational Components**                                                       |
+=====================+===================+====================+====================+
| `TI-RTOS Kernel`_   | `Boot`_           | `IPC`_             | `MPM`_             |
+---------------------+-------------------+--------------------+--------------------+
| `OpenMP`_           | `FC`_             | `OpenCL`_          | `Network`_         |
+---------------------+-------------------+--------------------+--------------------+
| `XDAIS`_            | `PKTLIB`_         | `NWAL`_            | `Tools`_           |
+---------------------+-------------------+--------------------+--------------------+

.. _TI-RTOS Kernel: Foundational_Components.html#ti-rtos-kernel
.. _Boot: Foundational_Components.html#boot
.. _IPC: http://processors.wiki.ti.com/index.php/IPC_Users_Guide
.. _MPM: Foundational_Components.html#mpm
.. _OpenMP: Foundational_Components.html#openmp
.. _FC: Foundational_Components.html#fc
.. _OpenCL: Foundational_Components.html#opencl
.. _Network: http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_NDK
.. _XDAIS: Foundational_Components.html#xdais
.. _PKTLIB: Foundational_Components.html#pktlib
.. _NWAL: Foundational_Components.html#nwal
.. _Tools: Foundational_Components.html#tools


+---------------------+-------------------+--------------------+--------------------+
| **DSP Optimized Libraries**                                                       |
+=====================+===================+====================+====================+
| `MATHLIB`_          | `IMGLIB`_         | `DSPLIB`_          | `FFTLIB`_          |
+---------------------+-------------------+--------------------+--------------------+
| `LINALG`_           |                   |                    |                    |
+---------------------+-------------------+--------------------+--------------------+

.. _MATHLIB: DSP_Optimized_Libraries.html
.. _IMGLIB: DSP_Optimized_Libraries.html
.. _DSPLIB: DSP_Optimized_Libraries.html
.. _FFTLIB: DSP_Optimized_Libraries.html
.. _LINALG: DSP_Optimized_Libraries.html


+---------------------+-------------------+--------------------+--------------------+
| **DSP Debug and Trace**                                                           |
+=====================+===================+====================+====================+
| `CToolsLib`_        | `UIA`_            | `Trace`_           |                    |
+---------------------+-------------------+--------------------+--------------------+
| `Fault Mgt`_        | `WDT`_            |                    |                    |
+---------------------+-------------------+--------------------+--------------------+

.. _CToolsLib: DSP_Software.html#ctoolslib
.. _UIA: DSP_Software.html#uia
.. _Trace: DSP_Software.html#trace
.. _Fault Mgt: DSP_Software.html#fault-management
.. _WDT: DSP_Software.html#wdt

+-----------------------------+----------------------------+----------------------------+----------------------------+
| **Device Drivers**                                                                                                 |
+=============================+============================+============================+============================+
| `CSL`_                      | `UART`_                    | `USB`_                     | `PCIe`_                    |
+-----------------------------+----------------------------+----------------------------+----------------------------+
| `GPIO`_                     | `I2C`_                     | `QSPI-McSPI`_              | `EDMA3`_                   |
+-----------------------------+----------------------------+----------------------------+----------------------------+
|`ICSS-EMAC(DRIVER,FIRMWARE)`_| `PRUSS`_                   | `FATFS`_                   | `MMCSD`_                   |
+-----------------------------+----------------------------+----------------------------+----------------------------+
| `QMSS`_                     | `CPPI`_                    | `PA`_                      | `SA`_                      |
+-----------------------------+----------------------------+----------------------------+----------------------------+
| `SRIO`_                     | `HYPLNK`_                  | `TSIP`_                    | `MCBSP`_                   |
+-----------------------------+----------------------------+----------------------------+----------------------------+
| `EMAC`_                     | `MCASP`_                   | `PM`_                      | `RM`_                      |
+-----------------------------+----------------------------+----------------------------+----------------------------+
| `GPMC`_                     | `VPS Drivers`_             |                            |                            |
+-----------------------------+----------------------------+----------------------------+----------------------------+

.. _CSL: Device_Drivers.html#csl
.. _UART: Device_Drivers.html#uart
.. _USB: Device_Drivers.html#usb
.. _PCIe: Device_Drivers.html#pcie
.. _GPIO: Device_Drivers.html#gpio
.. _I2C: Device_Drivers.html#i2c
.. _QSPI-McSPI: http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_QSPI-McSPI
.. _EDMA3: Device_Drivers.html#edma3
.. _ICSS-EMAC(DRIVER,FIRMWARE): Device_Drivers.html#icss-emac-driver-firmware
.. _PRUSS: Device_Drivers.html#pruss
.. _FATFS: Device_Drivers.html#fatfs
.. _MMCSD: Device_Drivers.html#mmcsd
.. _QMSS: Device_Drivers.html#qmss
.. _CPPI: Device_Drivers.html#cppi
.. _PA: Device_Drivers.html#pa
.. _SA: Device_Drivers.html#sa
.. _SRIO: Device_Drivers.html#srio
.. _HYPLNK: Device_Drivers.html#hyplnk
.. _TSIP: Device_Drivers.html#tsip
.. _MCBSP: Device_Drivers.html#mcbsp
.. _EMAC: http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_EMAC
.. _MCASP: Device_Drivers.html#mcasp
.. _PM: Device_Drivers.html#pm
.. _RM: Device_Drivers.html#rm
.. _GPMC: Device_Drivers.html#gpmc
.. _VPS Drivers: Device_Drivers.html#vps-drivers


+-----------------------------+----------------------------+----------------------------+----------------------------+
| **Device Driver Utilities**                                                                                        |
+=============================+============================+============================+============================+
| `OSAL`_                     | `Profiling`_               |                            |                            |
+-----------------------------+----------------------------+----------------------------+----------------------------+

.. _OSAL: Device_Drivers.html#osal
.. _Profiling: Device_Drivers.html#profiling


+-----------------------------+----------------------------+----------------------------+----------------------------+
| **PRU-ICSS Firmware**                                                                                              |
+=============================+============================+============================+============================+
| `Dual EMAC and Switch`_     | `PRU-ICSS SORTE`_          | `PRU-ICSS I2C`_            |                            |
+-----------------------------+----------------------------+----------------------------+----------------------------+

.. _Dual EMAC and Switch: PRU_ICSS.html#dual-emac-and-switch
.. _PRU-ICSS SORTE: PRU_ICSS.html#pru-icss-sorte
.. _PRU-ICSS I2C: PRU_ICSS.html#pru-icss-i2c


+-----------------------------+----------------------------+----------------------------+----------------------------+
| **Compilers**                                                                                                      |
+=============================+============================+============================+============================+
| `TI C6000`_                 | `TI ARM`_                  | `TI PRU`_                  | `Linaro GCC ARM`_          |
+-----------------------------+----------------------------+----------------------------+----------------------------+

.. _TI C6000: Compilers.html#ti-c6000
.. _TI ARM: Compilers.html#ti-arm
.. _TI PRU: Compilers.html#ti-pru
.. _Linaro GCC ARM: Compilers.html#linaro-gcc-arm
