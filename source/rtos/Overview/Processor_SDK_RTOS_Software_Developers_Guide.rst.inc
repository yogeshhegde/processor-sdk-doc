**********************************************
Processor SDK RTOS Software Developer's Guide
**********************************************

.. note::
   | Processor SDK documentation is now created from reStructuredText sources using
     Sphinx, and hosted on ti.com instead of processors wiki - starting
     4.3 release.
   |
   | We intend to retain the look and feel of the content
     to make this transition seamless, and yet provide the users with the benefits of
     consuming the content generated with emergent documentation tools.
   |
   | Wiki content will be left for reference during this migration process to find any missing old content. Feel free to drop us a note using the
     forums listed at `Technical Support`_, and we would love to hear from you.
   |
   | Old Wiki Documentation links from previous releases:
   |    - `Wiki Software Developer's Guide <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Software_Developer_Guide>`__.
   |    - `Wiki Getting Started Guide <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Getting_Started_Guide>`__.
   |

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


.. _Getting Started Guide: index_overview.html#getting-started-guide
.. _Release Notes: Release_Specific.html#release-notes
.. _Examples and Demonstrations: index_examples_demos.html
.. _RTOS Software Stack: index_overview.html#rtos-software-stack
.. _Directory Structure Overview: index_overview.html#directory-structure
.. _Building the SDK: index_overview.html#building-the-sdk
.. _Migration Guide: Release_Specific.html#migration-guide
.. _Technical Support: index_overview.html#technical-support
.. _How To Guides: index_how_to_guides.html
.. _Related Software: index_overview.html#related-software
.. _Frequently Asked Questions (FAQ): index_faq.html
.. _Supported Platforms and Versions: Release_Specific.html#supported-platforms-and-versions

+---------------------+-------------------+---------------------+-------------------+
| **Board/EVM Abstration**                                                          |
+=====================+===================+=====================+===================+
| `Diagnostics`_      | `Board Support`_  |`Power-On Self Test`_|                   |
+---------------------+-------------------+---------------------+-------------------+

.. _Diagnostics: index_board.html#diagnostics
.. _Board Support: index_board.html#board-support
.. _Power-On Self Test: index_board.html#power-on-self-test

+---------------------+-------------------+--------------------+--------------------+
| **Foundational Components**                                                       |
+=====================+===================+====================+====================+
| `TI-RTOS Kernel`_   | `Boot`_           | `IPC`_             | `MPM`_             |
+---------------------+-------------------+--------------------+--------------------+
| `OpenMP`_           | `FC`_             | `OpenCL`_          | `Network`_         |
+---------------------+-------------------+--------------------+--------------------+
| `XDAIS`_            | `PKTLIB`_         | `NWAL`_            | `Tools`_           |
+---------------------+-------------------+--------------------+--------------------+

.. _TI-RTOS Kernel: index_Foundational_Components.html#ti-rtos-kernel
.. _Boot: index_Foundational_Components.html#boot
.. _IPC: index_Foundational_Components.html#IPC
.. _MPM: index_Foundational_Components.html#mpm
.. _OpenMP: index_Foundational_Components.html#openmp
.. _FC: index_Foundational_Components.html#fc
.. _OpenCL: index_Foundational_Components.html#opencl
.. _Network: index_Foundational_Components.html#ndk
.. _XDAIS: index_Foundational_Components.html#xdais
.. _PKTLIB: index_Foundational_Components.html#pktlib
.. _NWAL: index_Foundational_Components.html#nwal
.. _Tools: index_Foundational_Components.html#tools


+---------------------+-------------------+--------------------+--------------------+
| **DSP Optimized Libraries**                                                       |
+=====================+===================+====================+====================+
| `MATHLIB`_          | `IMGLIB`_         | `DSPLIB`_          | `FFTLIB`_          |
+---------------------+-------------------+--------------------+--------------------+
| `LINALG`_           |                   |                    |                    |
+---------------------+-------------------+--------------------+--------------------+

.. _MATHLIB: index_dsp_sw.html#dsp-optimized-libraries 
.. _IMGLIB: index_dsp_sw.html#dsp-optimized-libraries
.. _DSPLIB: index_dsp_sw.html#dsp-optimized-libraries
.. _FFTLIB: index_dsp_sw.html#dsp-optimized-libraries
.. _LINALG: index_dsp_sw.html#dsp-optimized-libraries


+---------------------+-------------------+--------------------+--------------------+
| **DSP Debug and Trace**                                                           |
+=====================+===================+====================+====================+
| `CToolsLib`_        | `UIA`_            | `Trace`_           |                    |
+---------------------+-------------------+--------------------+--------------------+
| `Fault Mgt`_        | `WDT`_            |                    |                    |
+---------------------+-------------------+--------------------+--------------------+

.. _CToolsLib: index_dsp_sw.html#ctoolslib
.. _UIA: index_dsp_sw.html#uia
.. _Trace: index_dsp_sw.html#trace
.. _Fault Mgt: index_dsp_sw.html#fault-management
.. _WDT: index_dsp_sw.html#wdt

+-----------------------------+----------------------------+----------------------------+----------------------------+
| **Device Drivers**                                                                                                 |
+=============================+============================+============================+============================+
| `CSL`_                      | `UART`_                    | `USB`_                     | `PCIe`_                    |
+-----------------------------+----------------------------+----------------------------+----------------------------+
| `GPIO`_                     | `I2C`_                     | `McSPI-QSPI-OSPI`_         | `EDMA3`_                   |
+-----------------------------+----------------------------+----------------------------+----------------------------+
|`ICSS-EMAC(DRIVER,FIRMWARE)`_| `PRUSS`_                   | `FATFS`_                   | `MMCSD`_                   |
+-----------------------------+----------------------------+----------------------------+----------------------------+
| `QMSS`_                     | `CPPI`_                    | `PA`_                      | `SA`_                      |
+-----------------------------+----------------------------+----------------------------+----------------------------+
| `SRIO`_                     | `HYPLNK`_                  | `TSIP`_                    | `MCBSP`_                   |
+-----------------------------+----------------------------+----------------------------+----------------------------+
| `EMAC`_                     | `MCASP`_                   | `PM`_                      | `RM`_                      |
+-----------------------------+----------------------------+----------------------------+----------------------------+
| `GPMC`_                     | `VPS Drivers`_             | `DSS`_                     | `CAL`_                     |
+-----------------------------+----------------------------+----------------------------+----------------------------+
| `UDMA`_                     | `SCICLIENT`_               |                            |                            |
+-----------------------------+----------------------------+----------------------------+----------------------------+

.. _CSL: index_device_drv.html#csl
.. _UART: index_device_drv.html#uart
.. _USB: index_device_drv.html#usb
.. _PCIe: index_device_drv.html#pcie
.. _GPIO: index_device_drv.html#gpio
.. _I2C: index_device_drv.html#i2c
.. _McSPI-QSPI-OSPI: index_device_drv.html#McSPI-QSPI-OSPI
.. _EDMA3: index_device_drv.html#edma3
.. _ICSS-EMAC(DRIVER,FIRMWARE): index_device_drv.html#icss-emac-driver-firmware
.. _PRUSS: index_device_drv.html#pruss
.. _FATFS: index_device_drv.html#fatfs
.. _MMCSD: index_device_drv.html#mmcsd
.. _QMSS: index_device_drv.html#qmss
.. _CPPI: index_device_drv.html#cppi
.. _PA: index_device_drv.html#pa
.. _SA: index_device_drv.html#sa
.. _SRIO: index_device_drv.html#srio
.. _HYPLNK: index_device_drv.html#hyplnk
.. _TSIP: index_device_drv.html#tsip
.. _MCBSP: index_device_drv.html#mcbsp
.. _EMAC: index_device_drv.html#emac
.. _MCASP: index_device_drv.html#mcasp
.. _PM: index_device_drv.html#pm
.. _RM: index_device_drv.html#rm
.. _GPMC: index_device_drv.html#gpmc
.. _VPS Drivers: index_device_drv.html#vps-drivers
.. _DSS: index_device_drv.html#dss
.. _CAL: index_device_drv.html#cal
.. _UDMA: index_device_drv.html#udma
.. _SCICLIENT: index_device_drv.html#sciclient


+-----------------------------+----------------------------+----------------------------+----------------------------+
| **Device Driver Utilities**                                                                                        |
+=============================+============================+============================+============================+
| `OSAL`_                     | `Profiling`_               |                            |                            |
+-----------------------------+----------------------------+----------------------------+----------------------------+

.. _OSAL: index_device_drv.html#osal
.. _Profiling: index_device_drv.html#profiling


+-----------------------------+----------------------------+----------------------------+----------------------------+
| **PRU-ICSS Firmware**                                                                                              |
+=============================+============================+============================+============================+
| `Dual EMAC and Switch`_     | `PRU-ICSS SORTE`_          | `PRU-ICSS I2C`_            |                            |
+-----------------------------+----------------------------+----------------------------+----------------------------+

.. _Dual EMAC and Switch: index_pru_icss_fw.html#dual-emac-and-switch
.. _PRU-ICSS SORTE: index_pru_icss_fw.html#pru-icss-sorte
.. _PRU-ICSS I2C: index_pru_icss_fw.html#pru-icss-i2c


+-----------------------------+----------------------------+----------------------------+----------------------------+
| **Compilers**                                                                                                      |
+=============================+============================+============================+============================+
| `TI C6000`_                 | `TI ARM`_                  | `TI PRU`_                  | `Linaro GCC ARM`_          |
+-----------------------------+----------------------------+----------------------------+----------------------------+

.. _TI C6000: Compilers.html#ti-c6000
.. _TI ARM: Compilers.html#ti-arm
.. _TI PRU: Compilers.html#ti-pru
.. _Linaro GCC ARM: Compilers.html#linaro-gcc-arm
