
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
|  Examples and Demonstrations                                           | `RTOS Software Stack`_                                                        |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| `Directory Structure Overview`_                                        | `Building the SDK`_                                                           |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| `Training <https://training.ti.com/processor-sdk-training-series>`__   | `Migration Guide`_                                                            |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| `Technical Support`_                                                   | How To Guides                                                                 |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| `Related Software`_                                                    | `Frequently Asked Questions (FAQ)`__                                          |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| `Supported Platforms and Versions`_                                                                                                                    |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+


.. _Getting Started Guide: Overview.html#getting-started-guide
.. _Release Notes: Release_Specific.html#release-notes
.. _RTOS Software Stack: Overview.html#software-stack
.. _Directory Structure Overview: Overview.html#directory-structure-overview
.. _Building the SDK: Release_Specific.html#building-the-sdk
.. _Migration Guide: Release_Specific.html#migration-guide
.. _Technical Support: Overview.html#technical-support
.. _Related Software: Overview.html#related-software
.. _Frequently Asked Questions (FAQ): FAQ.html#frequently-asked-questions
.. _Supported Platforms and Versions: Release_Specific.html#supported-platforms-and-versions


