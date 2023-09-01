************************************
Release Notes
************************************

Overview
==========

The **Processor Software Development Kit (Processor-SDK)** provides the
core foundation and building blocks that facilitate application software
development on TI's embedded processors. This *Release Notes* focuses on
the Real-time operating system (RTOS).

|

Licensing
===========

Please refer to the software manifest, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page or in the installed directory as
indicated below.

|

Documentation
===============

-  :ref:`Getting Started Guide <Processor-SDK-RTOS-Getting-Started-Guide-label>`:
   Provides information on getting the software and running basic
   examples/demonstrations bundled in the SDK.
-  :ref:`Migration Guide <RTOS-SDK-Migration-Guide-label>` Provides
   migration information for applications built on top of the Processor
   SDK for RTOS.
-  :ref:`Software Developer Guide <Index-Processor-SDK-RTOS-label>`
   Provides information on features, functions, delivery package and,
   compile tools for the Processor SDK RTOS release. This also provides
   detailed information regarding software elements and software
   infrastructure to allow developers to start creating applications.
-  **Software Manifest**: Provides license information on software
   included in the SDK release. This document is in the release at
   ``/processor_sdk_rtos_<SOC>_<version>/docs`` and available to view
   from the software download page.
-  **EVM Quick Start Guide**: Provides information on hardware setup and
   running the demonstration application that is loaded on flash. This
   document is provided as part of the EVM kit.

|

Processor SDK v08.01.00
========================

Released March 2022

.. note::
   | Limited testing is done on this release based on the components changed. Full testing of the SDK is not done.

.. rubric::  What's New
   :name: whats-new

.. rubric::  New Features
   :name: new-features

- SDK
   - Naming change for APIs, Macros and Data structures in some of the components. Please refer :ref:`Migration Guide <RTOS-SDK-Migration-Guide-label>` for more details. 
- Board Diagnostics
   - 4GB DDR support in memory diagnostic test
- USB driver
   - Added USB long run regression test
- PRU
   - Upgraded toolchain version to v2.3.3

.. rubric::  Other Updates

- Features/Components Removed
   - RS485 Diagnostic test support is removed
   - Big data IPC and Jailhouse demos
- Bug Fixes
   - Bug fixes for USB driver, SPI driver and diagnostic examples. Please refer `Fixed Issues <Release_Specific_Release_Notes.html#fixed-issues>`__ section for more details

.. _release-notes-component-version:

.. rubric::  Component Version
   :name: component-version

The following software components and host tools are bundled with the
SDK installer. See the :ref:`Software Developer Guide <Index-Processor-SDK-RTOS-label>` for
more information on each item.

.. note::
   | This release has been tested with the following component and tool versions. It is recommended to use the versions listed here to avoid compatibility issues.

+-------------+------------+
|  Component  |   Version  |
+=============+============+
|  CG_XML     | 2.61.0     |
+-------------+------------+
|  CTOOLSLIB  | 2.2.0.0    |
+-------------+------------+
|  DSPLIB     | 3.4.0.4    |
+-------------+------------+
|  EDMA3 LLD  | 2.12.5.30  |
+-------------+------------+
|  FC         | 3.40.2.7   |
+-------------+------------+
|  IMGLIB     | 3.1.1.0    |
+-------------+------------+
|  IPC        | 3.50.4     |
+-------------+------------+
|  MATHLIB    | 3.1.2.4    |
+-------------+------------+
|  NDK        | 3.61.1     |
+-------------+------------+
|  NS         | 2.60.1     |
+-------------+------------+
|  OPENCL     | 1.2.0.2    |
+-------------+------------+
|  OPENMP     | 2.6.3.0    |
+-------------+------------+
|  PDK        | 1.0.19     |
+-------------+------------+
|  SYS/BIOS   | 6.76.3.1   |
+-------------+------------+
|  UIA        | 2.30.1.2   |
+-------------+------------+
|  XDAIS      | 7.24.0.4   |
+-------------+------------+
|  XDCTOOLS   | 3.55.02    |
+-------------+------------+


The following compilers are bundled with the SDK installer:

+----------------+---------+
|    Compiler    | Version |
+================+=========+
|GNU ARM Embedded|7-2018-q2|
+----------------+---------+
|TI ARM CGT      | 18.12.5 |
+----------------+---------+
|TI C6000 CGT    | 8.3.2   |
+----------------+---------+
|TI PRU CGT      | 2.3.3   |
+----------------+---------+

The SDK uses Code Composer Studio (CCS) as the integrated development
environment (IDE) for all devices and EVMs:

+-----------+----------+
| Component | Version  |
+===========+==========+
|   CCS     | 9.3.0    |
+-----------+----------+
|   EMU Pack|Sitara    |
|           |Device    |
|           |1.4.5     |
+-----------+----------+
|    TI     |8.3.0.0   |
| Emulators |          |
+-----------+----------+

If you need to install CCS, see the `CCS installation section <index_overview.html#code-composer-studio>`__
in the *Getting Started Guide* for options to select for Processor-SDK.



Fixed Issues
==============

    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | ID                                                             | Head Line                                                                                                             | Module            | Affected Versions    | Affected Platforms                                |
    +================================================================+=======================================================================================================================+===================+======================+===================================================+
    | PDK-9869                                                       | McSPI controller peripheral example failures with some HW setups                                                      | McSPI             | 6.03.02              | am571x-idk, am572x-idk, am574x-idk                |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PDK-10870                                                      | MCSPI controller peripheral example does not transfer more than 32bytes                                               | McSPI             | 6.03.02              | am571x-idk, am572x-idk, am574x-idk                |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PDK-10276                                                      | False test fail condition reported by diagnostic test framework                                                       | Diagnostics       | 6.03.02              | am571x-idk, am572x-idk, am574x-idk                |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PDK-10285                                                      | ICSS EMAC diagnostic test hang after link detection                                                                   | Diagnostics       | 6.03.02              | am574x-idk                                        |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PDK-10282                                                      | CSL timer example hang on DSP core while configuring timer instance 32                                                | CSL examples      | 6.03.02              | am571x-idk, am572x-evm, am572x-idk, am574x-idk    |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PDK-10302                                                      | Prebuilt SD images are not included in AM57x processor SDK demos package                                              | Demos             | 6.03.02              | am572x-evm, am571x-idk, am572x-idk, am574x-idk    |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PDK-10313                                                      | System fails to recover using clearFeature when USB bulk application is made to sleep in different sequences          | USB               | 6.03.02              | am571x-idk, am572x-idk, am574x-idk                |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PDK-11043                                                      | ICSS EMAC Example in Poll Mode fails for incorrect overflow count                                                     | ICSS EMAC         | 6.03.02              | am574x-idk, am572x-idk                            |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PDK-10576                                                      | UART print hangs on A15_1 core after BIOS_start                                                                       | Demos             | 6.03.02              | am571x-idk, am572x-evm, am572x-idk, am574x-idk    |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PDK-10408                                                      | Audio EQ McASP example is not working when equalization is enabled                                                    | McASP             | 6.03.02              | am572x-evm                                        |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PDK-10406                                                      | QSPI flash block erase & DMA mode write issues                                                                        | QSPI              | 6.03.02              | am572x-idk                                        |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PDK-11121                                                      | Fix for USB bulk write function infinite loop                                                                         | USB               | 6.03.02              | am571x-idk, am572x-idk, am574x-idk                |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PDK-10525                                                      | PULLUP misspelled as PILLUP (TYPO ERROR)                                                                              | SPI, Board        | 6.03.02              | am571x-idk, am572x-evm, am572x-idk, am574x-idk    |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PDK-10521                                                      | RS485 support is wrongly documented for AM57x platform                                                                | Diagnostics       | 6.03.02              | am571x-idk, am572x-idk, am574x-idk                |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PDK-10398                                                      | Documentation improvements                                                                                            | Documentation     | 6.03.02              | am571x-idk, am572x-evm, am572x-idk, am574x-idk    |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PDK-10328                                                      | Build warnings from hexpru tool while generating PRU firmware loader files                                            | ICSS EMAC         | 8.01.00              |  am572x-idk, am574x-idk am571x-idk                |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+

Known Issues
==============

This section contains the list of known issues at the time of making the
release and any known workaround.

+----------------------------------------------------------------+---------------------------------------------------------------------------------------------------+-------------------+-----------------------+------------------------------------------------------+----------------------------------------------------------------+-------------------------------------------------------+
| ID                                                             | Head Line                                                                                         | Module            | Reported in Release   | Affected Platforms                                   | Impact                                                         | Workaround in this release                            |
+================================================================+===================================================================================================+===================+=======================+======================================================+================================================================+=======================================================+
| PDK-11137                                                      | Queue overflow count is not returning proper value in poll mode                                   | ICSS EMAC         | 8.01.00               |  am572x-idk, am574x-idk                              | Applications will not be able to determine the overflow count  | Use the error count to track over all errors          |
+----------------------------------------------------------------+---------------------------------------------------------------------------------------------------+-------------------+-----------------------+------------------------------------------------------+----------------------------------------------------------------+-------------------------------------------------------+

.. _RN-Supported-Platforms-label:

Supported Platforms
=====================

Devices
---------

The following table lists all supported devices by the release installer.

+----------------+------------+-------------------------------------------------------------------------------+
|   Installer    |Platform/SOC|                                 Supported Devices                             |
+================+======+=====+===============================================================================+
|`RTOS-AM57X`_   |`AM57x`_    |`AM5706`_, `AM5708`_, `AM5716`_, `AM5718`_, `AM5726`_, `AM5728`_,              |
|                |            |`AM5746`_, `AM5748`_                                                           |
+----------------+------------+-------------------------------------------------------------------------------+


.. _RTOS-AM57X: http://software-dl.ti.com/processor-sdk-rtos/esd/AM57X/latest/index_FDS.html
.. _AM57x: http://www.ti.com/am57x
.. _AM5706: http://www.ti.com/product/am5706
.. _AM5708: http://www.ti.com/product/am5708
.. _AM5716: http://www.ti.com/product/am5716
.. _AM5718: http://www.ti.com/product/am5718
.. _AM5726: http://www.ti.com/product/am5726
.. _AM5728: http://www.ti.com/product/am5728
.. _AM5746: http://www.ti.com/product/am5746
.. _AM5748: http://www.ti.com/product/am5748


Evaluation Modules
--------------------

See :ref:`Processor SDK Supported Platforms <RTOS-SDK-Supported-Platforms>`
page for a list of supported EVMs per platform and links to more
information.

Demonstrations
----------------

See `Examples and Demonstrations <Examples_and_Demonstrations.html>`__
page for a list of demonstrations per platform and EVM.

Drivers
---------

The following tables show RTOS driver availability per platform and EVM.
A shaded box implies that the feature is not applicable for that
platform/EVM.

**Sitara devices**

+------------------+-----+-----------+
|     Feature      | SoC | AM57x EVM |
+==================+=====+=====+=====+
|                  |AM57x| GP  | IDK |
+------------------+-----+-----+-----+
| CSL              |  X  |  X  |  X  |
+------------------+-----+-----+-----+
| EMAC             |  X  |  X  |  X  |
+------------------+-----+-----+-----+
| EDMA3            |  X  |  X  |     |
+------------------+-----+-----+-----+
| GPIO             |  X  |  X  |  X  |
+------------------+-----+-----+-----+
| I2C              |  X  |  X  |  X  |
+------------------+-----+-----+-----+
| PRUSS-I2C f/w    |  X  |     |  X  |
+------------------+-----+-----+-----+
| ICSS-EMAC        |  X  |     |  X  |
+------------------+-----+-----+-----+
| McASP            |  X  |  X  |     |
+------------------+-----+-----+-----+
| McSPI            |  X  |     |  X  |
+------------------+-----+-----+-----+
| MMC-SD           |  X  |  X  |  X  |
+------------------+-----+-----+-----+
| PCIe             |  X  |     |  X  |
+------------------+-----+-----+-----+
| PM               |  X  |  X  |     |
+------------------+-----+-----+-----+
| PRUSS            |  X  |     |  X  |
+------------------+-----+-----+-----+
| QSPI             |  X  |     |  X  |
+------------------+-----+-----+-----+
| UART             |  X  |  X  |  X  |
+------------------+-----+-----+-----+
| USB              |  X  |  X  |  X  |
+------------------+-----+-----+-----+
| USB Device Bulk  |  X  |  X  |  X  |
+------------------+-----+-----+-----+
| VPS              |  X  |  X  |  X  |
+------------------+-----+-----+-----+

**Unsupported Features**

- In general driver support is available across all cores within an SOC
  with following exceptions

+----------------+-------------------+
|    Feature     | Not supported     |
+================+=========+=========+
|                |SOC      |CPU/Core |
+----------------+---------+---------+
|McASP           |  AM57x  |    M4   |
+----------------+---------+---------+
|USB             |  AM57x  |    C66x |
+----------------+---------+---------+
|USB             |  AM57x  |    M4   |
+----------------+---------+---------+

Other Features
----------------

The following table shows other feature availability per platform and
EVM:

**Sitara devices**

+----------------------------+-----+-----------+
|          Feature           | SoC | AM57x EVM |
+============================+=====+=====+=====+
|                            |AM57x| GP  | IDK |
+----------------------------+-----+-----+-----+
| Board Support              |  X  |  X  |  X  |
+----------------------------+-----+-----+-----+
| Boot (SBL)                 |  X  |  X  |  X  |
+----------------------------+-----+-----+-----+
| Diagnostics                |  X  |  X  |  X  |
+----------------------------+-----+-----+-----+
| FATFS                      |  X  |  X  |  X  |
+----------------------------+-----+-----+-----+
| NDK-NIMU(CPSW)             |  X  |  X  |  X  |
+----------------------------+-----+-----+-----+
| NDK-NIMU(ICSS)             |  X  |     |  X  |
+----------------------------+-----+-----+-----+
|CC-LINK IE Field Basic(CPSW)|  X  |  X  |  X  |
+----------------------------+-----+-----+-----+
|CC-Link IE Field Basic(ICSS)|  X  |     |  X  |
+----------------------------+-----+-----+-----+

Installation and Usage
========================

The :ref:`Getting Started Guide <Processor-SDK-RTOS-Getting-Started-Guide-label>` provides
instructions on how to setup up your development environment, install
the SDK and start your development.

To uninstall the SDK, remove the individual component directories from
the installed path. This is safe to do even in Windows since these
components do not modify the Windows registry.

|

Technical Support and Product Updates
=======================================

For further information or to report any problems, contact:
-  `TI E2E Processor Support <https://e2e.ti.com/support/processors/>`__ for all supported platforms


|

Archived
==========
-  `Processor-SDK RTOS
   6.3.2 <https://software-dl.ti.com/processor-sdk-rtos/esd/AM57X/06_03_02_08/exports/docs/devices/AM57X/rtos/Release_Specific_Release_Notes.html#release-notes>`__
-  `Processor-SDK RTOS
   6.3.0 <https://software-dl.ti.com/processor-sdk-rtos/esd/docs/06_03_00_106/rtos/Release_Specific.html#processor-sdk-rtos-release-notes>`__
-  `Processor-SDK RTOS
   6.1.0 <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/06_01_00_08/rtos/Release_Specific.html#processor-sdk-rtos-release-notes>`__
-  `Processor-SDK RTOS
   6.0.0 <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/06_00_00_07/rtos/Release_Specific.html#processor-sdk-rtos-release-notes>`__
-  `Processor-SDK RTOS
   5.3.0 <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/05_03_00_07/rtos/Release_Specific.html#processor-sdk-rtos-release-notes>`__
-  `Processor-SDK RTOS
   5.2.0 <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/05_02_00_10/rtos/Release_Specific.html#processor-sdk-rtos-release-notes>`__
-  `Processor-SDK RTOS
   5.1.0 <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/05_01_00_11/rtos/Release_Specific.html#processor-sdk-rtos-release-notes>`__
-  `Processor-SDK RTOS
   5.0.0 <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/05_00_00_15/rtos/Release_Specific.html#processor-sdk-rtos-release-notes>`__
-  `Processor-SDK RTOS
   5.0.0 AM65x EA Release <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/05_00_00_09/rtos/Release_Specific.html#processor-sdk-rtos-release-notes>`__
-  `Processor-SDK RTOS
   4.3.0 <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/04_03_00_05/rtos/Release_Specific.html#processor-sdk-rtos-release-notes>`__

**Note:** Release Notes prior to 4.3 are not archived. Please see the
:ref:`Migration Guide <RTOS-SDK-Migration-Guide-label>` for information on
migration from these releases.

|

