************************************
Release Notes
************************************

.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Release_Notes

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

Processor SDK v06.03.02
========================

Released July 2021

.. note::
   | This release is specific to AM57x platform. No other platforms supported by RTOS processor SDK are validated in this release.

.. rubric::  What's New
   :name: whats-new

.. rubric::  New Features
   :name: new-features

- AM57x
    - USB driver
       - Added Full Speed support for USB Bulk Device
       - Support for Set and Clear STALL feature functions
       - Added close API
       - Bug fixes
    - MMCSD driver
       - Added support for different timeout errors
       - Bug fixes 
    - PRU Firmware
       - Added version details
       - Dual EMAC firmware memory map update
    
.. _release-notes-component-version:

.. rubric::  Component Version
   :name: component-version

The following software components and host tools are bundled with the
SDK installer. See the :ref:`Software Developer Guide <Index-Processor-SDK-RTOS-label>` for
more information on each item.

.. note::
   | This release has been tested with the following component and tool versions. It is recommended to use the versions listed here to avoid compatibility issues. 

+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  Component  |   Version  |AM335x|AM437x|AM57x |AM65x |K2H/K2K| K2E  | K2L  | K2G  |C665x |C667x |OMAP-L137|OMAP-L138|
+=============+============+======+======+======+======+=======+======+======+======+======+======+=========+=========+
|  CG_XML     | 2.61.0     |   X  |  X   |  X   |  X   |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  CTOOLSLIB  | 2.2.0.0    |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  DSPLIB     | 3.4.0.4    |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  EDMA3 LLD  | 2.12.5.30  |   X  |  X   |  X   |      |       |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  FC         | 3.40.2.7   |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  FFTLIB     | 3.1.0.0    |      |      |      |      |       |      |      |      |      |  X   |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  IMGLIB     | 3.1.1.0    |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  IPC        | 3.50.4     |      |      |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |         |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  LIBARCH    | 1.0.0.0    |      |      |      |      |   X   |      |      |      |      |  X   |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  LINALG     | 1.2.0.0    |      |      |      |      |   X   |      |      |      |      |  X   |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  MATHLIB    | 3.1.2.4    |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  MPM        | 3.0.4.0    |      |      |      |      |   X   |  X   |  X   |  X   |      |      |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  NDK        | 3.61.1     |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  NS         | 2.60.1     |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  OPENCL     | 1.2.0.2    |      |      |  X   |      |       |      |      |      |      |      |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  OPENMP     | 2.6.3.0    |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |         |         |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  PDK        |            |1.0.17|1.0.17|1.0.18| 1.0.7| 4.0.16|4.0.16|4.0.16|1.0.16|2.0.16|2.0.16|  1.0.11 |  1.0.11 |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  SYS/BIOS   | 6.76.3.1   |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  UIA        | 2.30.1.2   |      |      |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  XDAIS      | 7.24.0.4   |      |      |  X   |      |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  XDCTOOLS   | 3.55.02    |   X  |  X   |  X   |   X  |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+------------+------+------+------+------+-------+------+------+------+------+------+---------+---------+


The following compilers are bundled with the SDK installer:

+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+
|    Compiler    | Version |AM335x|AM437x|AM57x |AM65x |K2H/K2K| K2E | K2L    |  K2G   |C665x|C667x|OMAP-L137|OMAP-L138|
+================+=========+======+======+======+======+=======+=====+========+========+=====+=====+=========+=========+
|GNU ARM Embedded|7-2018-q2|   A8 |  A9  |  A15 |      |  A15  | A15 | A15    |  A15   |     |     |         |         |
+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+
|GNU Linaro GCC  | 7.2.1   |      |      |      | A53  |       |     |        |        |     |     |         |         |
+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+
|TI ARM CGT      | 18.12.5 |      |      |  M4  |  R5  |       |     |A15(SBL)|        |     | ARM9|   ARM9  |         |
+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+
|TI C6000 CGT    | 8.3.2   |      |      | C66x |      | C66x  |C66x | C66x   |  C66x  |C66x |C66x |   C674x |   C674x |
+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+
|TI PRU CGT      | 2.3.2   | PRU  | PRU  | PRU  |  PRU |       |     |  PRU   |        |     |     |         |         |
+----------------+---------+------+------+------+------+-------+-----+--------+--------+-----+-----+---------+---------+

The SDK uses Code Composer Studio (CCS) as the integrated development
environment (IDE) for all devices and EVMs:

+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+
| Component | Version  |AM335x|AM437x|AM57x |AM65x |K2H/K2K| K2E | K2L | K2G |C665x|C667x|OMAP-L137|OMAP-L138|
+===========+==========+======+======+======+======+=======+=====+=====+=====+=====+=====+=========+=========+
|   CCS     | 9.3.0    |   X  |  X   |  X   |  X   |   X   |  X  |  X  |  X  |  X  |  X  |    X    |    X    |
+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+
|   EMU Pack|Sitara    |   X  |  X   |  X   |  X   |       |     |     |     |     |     |         |         |
|           |Device    |      |      |      |      |       |     |     |     |     |     |         |         |
|           |1.4.5     |      |      |      |      |       |     |     |     |     |     |         |         |
+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+
|    TI     |8.3.0.0   |   X  |  X   |  X   |  X   |   X   |  X  |  X  |  X  |  X  |  X  |     X   |     X   |
| Emulators |          |      |      |      |      |       |     |     |     |     |     |         |         |
+-----------+----------+------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+

If you need to install CCS, see the `CCS installation section <index_overview.html#code-composer-studio>`__
in the *Getting Started Guide* for options to select for Processor-SDK.



Fixed Issues 
==============


    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | ID                                                             | Head Line                                                                                                             | Module            | Affected Versions    | Affected Platforms                                |
    +================================================================+=======================================================================================================================+===================+======================+===================================================+
    | PRSDK-8827                                                     | USB clearFeature and close function failures when device is operated in BULK mode                                     | USB               | 6.03.00              | am57xx-evm, am571x-idk, am572x-idk, am574x-idk    |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PRSDK-8826                                                     | TRB Memory corruption when the next event occurred before processing TRB completion event at EP0                      | USB               | 6.03.00              | am571x-idk, am57xx-evm, am572x-idk, am574x-idk    |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PRSDK-8832                                                     | USB host driver crashes when multiple EP0 requests are initiated                                                      | USB               | 6.03.00              | am57xx-evm, am571x-idk, am572x-idk, am574x-idk    |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PRSDK-8795                                                     | PC couldn’t connect to the USB device after connecting and disconnecting it several times.                            | USB               | 6.03.00              | am574x-idk                                        |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PRSDK-8805                                                     | MMCSD driver is not detecting the SD cards supporting SD spec revision below 2.0                                      | MMCSD             | 6.03.00              | am574x-idk                                        |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PRSDK-8810                                                     | Transfer failure if TCC channel was changed during enabling DMA.                                                      | MMCSD             | 6.03.00              | am574x-idk                                        |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PDK-10281                                                      | NIMU ICSS CCLink test failure on M4 core                                                                              | NIMU ICSS         | 6.03.00              | am571x-idk, am572x-idk, am574x-idk                |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+
    | PDK-10277                                                      | NIMU CCLink test failure on M4 core                                                                                   | NIMU              | 6.03.00              | am571x-idk, am572x-idk, am574x-idk                |
    +----------------------------------------------------------------+-----------------------------------------------------------------------------------------------------------------------+-------------------+----------------------+---------------------------------------------------+

Known Issues 
==============

This section contains the list of known issues at the time of making the
release and any known workaround.


+----------------------------------------------------------------+---------------------------------------------------------------------------------------------------+-------------------+-----------------------+------------------------------------------------------+----------------------------------------------------------------+-------------------------------------------------------+
| ID                                                             | Head Line                                                                                         | Module            | Reported in Release   | Affected Platforms                                   | Impact                                                         | Workaround in this release                            |
+================================================================+===================================================================================================+===================+=======================+======================================================+================================================================+=======================================================+
| PRSDK-8819                                                     | UART LLD data structure UART_Params mismatching between LLD and application                       | UART              | 6.03.02               |  am571x-idk, am572x-evm, am572x-idk, am574x-idk      | UART_Params_init() can overwrite application's data memory     | None                                                  |
+----------------------------------------------------------------+---------------------------------------------------------------------------------------------------+-------------------+-----------------------+------------------------------------------------------+----------------------------------------------------------------+-------------------------------------------------------+
| `PDK-9869 <https://sir.ext.ti.com/jira/browse/EXT_EP-10436>`_  | McSPI master slave example failures with some HW setups                                           | McASPI            | 6.03.02               |  am571x-idk, am572x-idk, am574x-idk                  | Inconsistent results while running the test                    | Use shorter cables with single wire for connections   |
+----------------------------------------------------------------+---------------------------------------------------------------------------------------------------+-------------------+-----------------------+------------------------------------------------------+----------------------------------------------------------------+-------------------------------------------------------+
| `PDK-10276 <https://sir.ext.ti.com/jira/browse/EXT_EP-10434>`_ | False test fail condition reported by diagnostic test framework                                   | Diagnostics       | 6.03.02               |  am571x-idk, am572x-idk, am574x-idk                  | Diagnostic framework menu shows test status as fail            | Use logs displayed by the test to confirm test result |
+----------------------------------------------------------------+---------------------------------------------------------------------------------------------------+-------------------+-----------------------+------------------------------------------------------+----------------------------------------------------------------+-------------------------------------------------------+
| `PDK-10275 <https://sir.ext.ti.com/jira/browse/EXTSYNC-2973>`_ | ICSS STP switch test failure while executing the loopback test                                    | ICSS EMAC         | 6.03.02               |  am574x-idk                                          | ICSS STP switch test hang                                      | None                                                  |
+----------------------------------------------------------------+---------------------------------------------------------------------------------------------------+-------------------+-----------------------+------------------------------------------------------+----------------------------------------------------------------+-------------------------------------------------------+
| `PDK-10285 <https://sir.ext.ti.com/jira/browse/EXTSYNC-2975>`_ | ICSS EMAC diagnostic test hang after link detection                                               | Diagnostics       | 6.03.02               |  am574x-idk                                          | ICSS EMAC diagnostic test hang                                 | None                                                  |
+----------------------------------------------------------------+---------------------------------------------------------------------------------------------------+-------------------+-----------------------+------------------------------------------------------+----------------------------------------------------------------+-------------------------------------------------------+
| `PDK-10282 <https://sir.ext.ti.com/jira/browse/EXTSYNC-2972>`_ | CSL timer example hang on DSP core while configuring timer instance 32                            | CSL examples      | 6.03.02               |  am571x-idk, am572x-evm, am572x-idk, am574x-idk      | CSL timer test hang                                            | None                                                  |
+----------------------------------------------------------------+---------------------------------------------------------------------------------------------------+-------------------+-----------------------+------------------------------------------------------+----------------------------------------------------------------+-------------------------------------------------------+
| PDK-10302                                                      | Prebuilt SD images are not included in AM57x processor SDK demos package                          | Demos             | 6.03.02               |  am571x-idk, am572x-evm, am572x-idk, am574x-idk      | No prebuilt images                                             | Generate the diagnostic test binaries by following    |
|                                                                |                                                                                                   |                   |                       |                                                      |                                                                | `Diag-Build`_ steps                                   |
+----------------------------------------------------------------+---------------------------------------------------------------------------------------------------+-------------------+-----------------------+------------------------------------------------------+----------------------------------------------------------------+-------------------------------------------------------+
| PDK-10313                                                      | System fails to recover using clearFeature when USB bulk application is made to                   | USB               | 6.03.02               |  am574x-idk                                          | Aborting pending transactions with clearFeature fails          | None                                                  |
|                                                                | sleep in different sequences                                                                      |                   |                       |                                                      |                                                                |                                                       |
+----------------------------------------------------------------+---------------------------------------------------------------------------------------------------+-------------------+-----------------------+------------------------------------------------------+----------------------------------------------------------------+-------------------------------------------------------+
| PDK-10328                                                      | Build warnings from hexpru tool while generating PRU firmware loader files                        | ICSS EMAC         | 6.03.02               |  am571x-idk, am572x-idk, am574x-idk                  | Warnings during ICSS EMAC LLD build                            | None                                                  |
+----------------------------------------------------------------+---------------------------------------------------------------------------------------------------+-------------------+-----------------------+------------------------------------------------------+----------------------------------------------------------------+-------------------------------------------------------+

.. _Diag-Build: https://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/index_board.html#building-the-examples

.. _RN-Supported-Platforms-label:

Supported Platforms 
=====================

Devices 
---------

The following table lists all supported devices for a given installer.

+----------------+------------+-------------------------------------------------------------------------------+
|   Installer    |Platform/SOC|                                 Supported Devices                             |
+================+======+=====+===============================================================================+
|                |`AM335x`_   | `AM3351`_, `AM3352`_, `AM3354`_, `AM3356`_, `AM3357`_, `AM3358`_, `AM3359`_   |
|`RTOS-AM335X`_  +------------+-------------------------------------------------------------------------------+
|                |`AMIC11x`_  | `AMIC110`_                                                                    |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-AM437X`_  |`AM437x`_   | `AM4376`_, `AM4377`_, `AM4378`_, `AM4379`_                                    |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-AM57X`_   |`AM57x`_    |`AM5706`_, `AM5708`_, `AM5716`_, `AM5718`_, `AM5726`_, `AM5728`_,              |
|                |            |`AM5746`_, `AM5748`_                                                           |
+----------------+------------+-------------------------------------------------------------------------------+
| `RTOS-AM65X`_  | `AM65x`_   |`AM6526`_, `AM6527`_, `AM6528`_, `AM6546`_, `AM6548`_, DRA80xM                 |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-C665X`_   |`C665x`_    | `C6652`_, `C6654`_, `C6655`_, `C6657`_                                        |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-C667X`_   |`C667x`_    | `C6671`_, `C6672`_, `C6674`_, `C6678`_                                        |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-K2E`_     |`K2E`_      | `66AK2E02`_, `66AK2E05`_, `AM5K2E02`_, `AM5K2E04`_                            |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-K2G`_     |`K2G`_      | `66AK2G02`_, `66AK2G12`_                                                      |
+----------------+------------+-------------------------------------------------------------------------------+
|                |`K2H`_      | `66AK2H06`_, `66AK2H12`_, `66AK2H14`_                                         |
| `RTOS-K2HK`_   +------------+-------------------------------------------------------------------------------+
|                |`K2K`_      | `TCI6638K2K`_                                                                 |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-K2L`_     |`K2L`_      | `66AK2L06`_                                                                   |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-OMAPL137`_|`OMAP-L1x`_ | `OMAP-L137`_, `C6743`_, `C6745`_, `C6747`_                                    |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-OMAPL138`_|`OMAP-L1x`_ | `OMAP-L138`_, `C6742`_, `C6746`_, `C6748`_                                    |
+----------------+------------+-------------------------------------------------------------------------------+


.. _RTOS-AM335X: http://software-dl.ti.com/processor-sdk-rtos/esd/AM335X/latest/index_FDS.html
.. _AM335x: http://www.ti.com/am335x
.. _AM3351: http://www.ti.com/product/am3351
.. _AM3352: http://www.ti.com/product/am3352
.. _AM3354: http://www.ti.com/product/am3354
.. _AM3356: http://www.ti.com/product/am3356
.. _AM3357: http://www.ti.com/product/am3357
.. _AM3358: http://www.ti.com/product/am3358
.. _AM3359: http://www.ti.com/product/am3359

.. _AMIC11x: http://www.ti.com/lsds/ti/processors/sitara/industrial-ethernet/amic11x/amic11x-overview.page>`__
.. _AMIC110: http://www.ti.com/product/amic110

.. _RTOS-AM437X: http://software-dl.ti.com/processor-sdk-rtos/esd/AM437X/latest/index_FDS.html
.. _AM437x: http://www.ti.com/am437x
.. _AM4376: http://www.ti.com/product/am4376
.. _AM4377: http://www.ti.com/product/am4377
.. _AM4378: http://www.ti.com/product/am4378
.. _AM4379: http://www.ti.com/product/am4379

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

.. _RTOS-AM65X: http://software-dl.ti.com/processor-sdk-rtos/esd/AM65X/latest/index_FDS.html
.. _AM65x: http://www.ti.com/am65x
.. _AM6526: http://www.ti.com/product/am6526
.. _AM6527: http://www.ti.com/product/am6527
.. _AM6528: http://www.ti.com/product/am6528
.. _AM6546: http://www.ti.com/product/am6546
.. _AM6548: http://www.ti.com/product/am6548

.. _RTOS-C665X: http://software-dl.ti.com/processor-sdk-rtos/esd/C665x/latest/index_FDS.html
.. _C665x: http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp/c66x/overview.page
.. _C6652: http://www.ti.com/product/tms320c6652
.. _C6654: http://www.ti.com/product/tms320c6654
.. _C6655: http://www.ti.com/product/tms320c6655
.. _C6657: http://www.ti.com/product/tms320c6657

.. _RTOS-C667X: http://software-dl.ti.com/processor-sdk-rtos/esd/C667x/latest/index_FDS.html
.. _C667x: http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp/c66x/overview.page
.. _C6671: http://www.ti.com/product/tms320c6671
.. _C6672: http://www.ti.com/product/tms320c6672
.. _C6674: http://www.ti.com/product/tms320c6674
.. _C6678: http://www.ti.com/product/tms320c6678

.. _RTOS-K2E: http://software-dl.ti.com/processor-sdk-rtos/esd/K2E/latest/index_FDS.html
.. _K2E: http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp-arm/66ak2x/overview.page
.. _66AK2E02: http://www.ti.com/product/66ak2e02
.. _66AK2E05: http://www.ti.com/product/66ak2e05
.. _AM5K2E02: http://www.ti.com/product/am5k2e02
.. _AM5K2E04: http://www.ti.com/product/am5k2e04

.. _RTOS-K2G: http://software-dl.ti.com/processor-sdk-rtos/esd/K2G/latest/index_FDS.html
.. _K2G: http://www.ti.com/processors/dsp/c6000-dsp-arm/66ak2x/overview.html
.. _66AK2G02: http://www.ti.com/product/66ak2g02
.. _66AK2G12: http://www.ti.com/product/66ak2g12

.. _RTOS-K2HK: http://software-dl.ti.com/processor-sdk-rtos/esd/K2HK/latest/index_FDS.html
.. _K2H: http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp-arm/66ak2x/overview.page
.. _66AK2H06: http://www.ti.com/product/66ak2h06
.. _66AK2H12: http://www.ti.com/product/66ak2h12
.. _66AK2H14: http://www.ti.com/product/66ak2h14

.. _K2K: http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp-arm/66ak2x/overview.page
.. _TCI6638K2K: http://www.ti.com/product/tci6638k2k

.. _RTOS-K2L: http://software-dl.ti.com/processor-sdk-rtos/esd/K2L/latest/index_FDS.html
.. _K2L: http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp-arm/66ak2x/overview.page
.. _66AK2L06: http://www.ti.com/product/66ak2l06

.. _RTOS-OMAPL137: http://www.ti.com/tool/processor-sdk-omapl137
.. _OMAP-L1x: http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp-arm/omap-l1x/overview.page
.. _OMAP-L137: http://www.ti.com/product/OMAP-L137
.. _C6743: http://www.ti.com/product/tms320c6743
.. _C6745: http://www.ti.com/product/tms320c6745
.. _C6747: http://www.ti.com/product/tms320c6747

.. _RTOS-OMAPL138: http://www.ti.com/tool/processor-sdk-omapl138
.. _OMAP-L1x: http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp-arm/omap-l1x/overview.page
.. _OMAP-L138: http://www.ti.com/product/OMAP-L138
.. _C6742: http://www.ti.com/product/tms320c6742
.. _C6746: http://www.ti.com/product/tms320c6746
.. _C6748: http://www.ti.com/product/tms320c6748

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

+------------------+--------------------------------+---------------+-----------+-----------+-----------+----------+
|     Feature      |    Platform/SOC                |  AM335x EVM   |AM437x EVM | AM57x EVM | AM65x EVM |J721E EVM |
+==================+=======+======+=====+=====+=====+===+===+===+===+===+===+===+=====+=====+=====+=====+==========+
|                  |AM335x |AM437x|AM57x|AM65x|J721E|GP |ICE|SK |BBB|GP |IDK|SK | GP  | IDK | GP  | IDK |  GP      | 
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| CSL              |   X   |   X  |  X  |  X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| EMAC             |   X   |   X  |  X  |  X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| EDMA3            |   X   |   X  |  X  |     |     | X |   |   |   | X |   |   |  X  |     |     |     |          |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| GPIO             |   X   |   X  |  X  |  X  |  X  |   | X |   | X | X |   | X |  X  |  X  |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| GPMC             |   X   |   X  |     |     |     |   | X |   |   | X |   |   |     |     |     |     |          |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| I2C              |   X   |   X  |  X  |  X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| PRUSS-I2C f/w    |   X   |   X  |  X  |     |     |   | X |   |   |   | X |   |     |  X  |     |     |          |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| PRUSS-eSPI f/w   |   X   |   X  |     |     |     |   |   |   |   |   |   |   |     |     |     |     |          |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| ICSS-EMAC        |   X   |   X  |  X  |  X  |     |   | X |   |   |   | X |   |     |  X  |     |     |          |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| McASP            |   X   |   X  |  X  |  X  |  X  | X |   |   |   | X |   |   |  X  |     |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| McSPI            |   X   |   X  |  X  |  X  |  X  |   | X |   |   |   | X |   |     |  X  |   X |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| MMC-SD           |   X   |   X  |  X  |  X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| PCIe             |       |      |  X  |  X  |     |   |   |   |   |   |   |   |     |  X  |  X  |     |          |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| PM               |   X   |      |  X  |  X  |  X  | X |   |   |   |   |   |   |  X  |     |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| PRUSS            |   X   |   X  |  X  |  X  |  X  |   | X |   |   |   | X |   |     |  X  |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| QSPI             |       |   X  |  X  |  X  |  X  |   |   |   |   |   | X | X |     |  X  |     |     |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| OSPI             |       |      |     |  X  |  X  |   |   |   |   |   |   |   |     |     |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| UART             |   X   |   X  |  X  |  X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| USB              |   X   |   X  |  X  |  X  |  X  | X |   |   |   | X |   |   |  X  |  X  |  X  |   X |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| USB Device Audio |   X   |      |     |     |     | X |   |   |   |   |   |   |     |     |     |     |          |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| USB Device Bulk  |   X   |   X  |  X  |  X  |  X  | X |   |   |   | X |   |   |  X  |  X  |  X  |   X |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| VPS              |       |      |  X  |     |     |   |   |   |   |   |   |   |  X  |  X  |     |     |          |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| UDMA             |       |      |     |  X  |  X  |   |   |   |   |   |   |   |     |     |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| SCICLIENT        |       |      |     |  X  |  X  |   |   |   |   |   |   |   |     |     |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| SA               |       |      |     |  X  |  X  |   |   |   |   |   |   |   |     |     |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| CAL              |       |      |     |  X  |  X  |   |   |   |   |   |   |   |     |     |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| DSS              |       |      |     |  X  |  X  |   |   |   |   |   |   |   |     |     |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+
| FVID2            |       |      |     |  X  |  X  |   |   |   |   |   |   |   |     |     |  X  |  X  |  X       |
+------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+----------+

**DSP devices - K2x, C66x**

+------------------+-------------------------------+-----------------------+-----------+
|     Feature      |         Platform/SOC          |        K2 EVM         | C66x EVM  |
+==================+=======+===+===+===+=====+=====+===+===+===+===+=======+=====+=====+
|                  |K2H/K2K|K2E|K2L|K2G|C665x|C667x|K2H|K2E|K2L|K2G|K2G-ICE|C665x|C667x|
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| CSL              |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| AIF2             |   X   |   |   |   |     |     | X |   |   |   |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| BCP              |   X   |   | X |   |     |     | X |   | X |   |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| CPPI             |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| DFE              |       |   | X |   |     |     |   |   | X |   |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| EDMA3            |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| EMAC             |       |   |   | X |  X  |     |   |   |   | X |   X   |  X  |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| FFTC             |   X   |   | X |   |     |     | X |   | X |   |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| GPIO             |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| HYPLNK           |   X   | X |   |   |  X  |  X  | X | X |   |   |       |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| ICSS-EMAC        |       |   |   | X |     |     |   |   |   |   |   X   |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| I2C              |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| IQN2             |       |   | X |   |     |     |   |   | X |   |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| McASP            |       |   |   | X |     |     |   |   |   | X |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| McBSP            |       |   |   | X |  X  |     |   |   |   | X |       |  X  |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| MMAP             |   X   | X |   |   |     |     | X | X |   |   |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| MMC-SD           |       |   |   | X |     |     |   |   |   | X |   X   |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| NWAL             |   X   | X | X |   |     |  X  | X | X | X |   |       |     |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| PA               |   X   | X | X |   |     |  X  | X | X | X |   |       |     |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| PCIe             |   X   | X | X | X |  X  |  X  | X | X | X | X |       |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| QMSS             |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| RM               |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| SA               |   X   | X | X | X |     |  X  | X | X | X | X |       |     |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| SPI              |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| SRIO             |   X   |   |   |   |  X  |  X  | X |   |   |   |       |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| TCP3D            |   X   |   | X |   |  X  |     | X |   | X |   |       |  X  |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| TSIP             |       | X |   |   |     |  X  |   | X |   |   |       |     |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| UART             |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| USB              |       |   |   | X |     |     |   |   |   | X |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| USB Device Audio |       |   |   |   |     |     |   |   |   |   |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| USB Device Bulk  |       |   |   | X |     |     |   |   |   | X |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+


**DSP devices - OMAP-L13x, C674x**

+----------------+-------------------+-------------+----------------+
|    Feature     |   Platform/SOC    |OMAP-L137 EVM| OMAP-L138 EVM  |
+================+=========+=========+=============+=======+========+
|                |OMAP-L137|OMAP-L138| L137/6747 SK|LCDK138|LCDK6748|
+----------------+---------+---------+-------------+-------+--------+
|CSL             |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|EDMA3           |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|EMAC            |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|GPIO            |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|I2C             |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|McASP           |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|MMC-SD          |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|SPI             |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|UART            |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|USB             |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|USB Device Audio|    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+
|USB Device Bulk |    X    |    X    |      X      |   X   |   X    |
+----------------+---------+---------+-------------+-------+--------+

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
|USB             |  K2G    |    C66x |
+----------------+---------+---------+
|McBSP           |  K2G    |    A15  |
+----------------+---------+---------+
|McBSP           |OMAP-L13x|    ARM9 |
+----------------+---------+---------+
|All Drivers     | K2E/L/K |    A15  |
+----------------+---------+---------+

Other Features 
----------------

The following table shows other feature availability per platform and
EVM:

**Sitara devices**

+----------------------------+--------------------------------+---------------+-----------+-----------+-----------+-----------+
|          Feature           |    Platform/SOC                |   AM335x EVM  |AM437x EVM | AM57x EVM | AM65x EVM | J721E EVM |
+============================+=======+======+=====+=====+=====+===+===+===+===+===+===+===+=====+=====+=====+=====+===========+
|                            |AM335x |AM437x|AM57x|AM65x|J721E|GP |ICE|SK |BBB|GP |IDK|SK | GP  | IDK | GP  | IDK | GP        |
+----------------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+-----------+
| Board Support              |   X   |  X   |  X  |  X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |  X        |
+----------------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+-----------+
| Boot (SBL)                 |   X   |  X   |  X  |  X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |  X        |
+----------------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+-----------+
| Diagnostics                |   X   |  X   |  X  |  X  |  X  | X |   |   |   | X |   |   |  X  |  X  |  X  |  X  |  X        |
+----------------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+-----------+
| FATFS                      |   X   |  X   |  X  |  X  |  X  | X | X |   |   | X | X |   |  X  |  X  |  X  |  X  |  X        |
+----------------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+-----------+
| NDK-NIMU(CPSW)             |   X   |  X   |  X  |  X  |  X  | X | X | X | X | X | X | X |  X  |  X  |  X  |  X  |  X        |
+----------------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+-----------+
| NDK-NIMU(ICSS)             |   X   |  X   |  X  |  X  |  X  |   | X |   |   |   | X |   |     |  X  |  X  |  X  |  X        |
+----------------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+-----------+
|CC-LINK IE Field Basic(CPSW)|   X   |  X   |  X  |     |     | X | X | X | X | X | X | X |  X  |  X  |     |     |           |
+----------------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+-----------+
|CC-Link IE Field Basic(ICSS)|   X   |  X   |  X  |     |     |   | X |   |   |   | X |   |     |  X  |     |     |           |
+----------------------------+-------+------+-----+-----+-----+---+---+---+---+---+---+---+-----+-----+-----+-----+-----------+

**DSP devices - K2x, C66x**

+----------------------------+-------------------------------+-----------------------+-----------+
|          Feature           |         Platform/SOC          |        K2 EVM         | C66x EVM  |
+============================+=======+===+===+===+=====+=====+===+===+===+===+=======+=====+=====+
|                            |K2H/K2K|K2E|K2L|K2G|C665x|C667x|K2H|K2E|K2L|K2G|K2G-ICE|C665x|C667x|
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| Board Support              |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| Boot (IBL/SBL)             |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| Diagnostics                |       |   |   | X |     |     |   |   |   | X |   X   |     |     |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| FATFS                      |       |   |   | X |     |     |   |   |   | X |   X   |     |     |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| Fault Management           |   X   | X | X |   |     |     | X | X | X |   |       |     |     |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| IPC Transport (QMSS)       |   X   | X | X |   |  X  |  X  | X | X | X |   |       |  X  |  X  |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| IPC Transport (SRIO)       |   X   |   |   |   |  X  |  X  | X |   |   |   |       |  X  |  X  |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| MAD-UTIL                   |       |   |   |   |  X  |  X  |   |   |   |   |       |  X  |  X  |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| Network (CPSW)             |   X   | X | X | X |  X  |  X  | X | X | X | X |   X   |  X  |  X  |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| Network (ICSS)             |       |   |   | X |     |     |   |   |   | X |       |     |     |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
|CC-Link IE Field Basic(ICSS)|       |   |   | X |     |     |   |   |   | X |       |     |     |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
|Platform Library (obsolete) |   X   | X | X |   |  X  |  X  | X | X | X |   |       |  X  |  X  |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| PKTLIB                     |   X   | X | X |   |     |  X  | X | X | X |   |       |     |  X  |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| POST                       |   X   | X | X |   |  X  |  X  | X | X | X |   |       |  X  |  X  |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| SERDES Diagnostics         |   X   | X | X |   |     |     | X | X | X |   |       |     |     |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+
| Trace Framework            |   X   | X | X |   |     |     | X | X | X |   |       |     |     |
+----------------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+


**DSP devices - OMAP-L13x, C674x**

+--------------+-------------------+-------------+----------------+
|   Feature    |   Platform/SOC    |OMAP-L137 EVM| OMAP-L138 EVM  |
+==============+=========+=========+=============+=======+========+
|              |OMAP-L137|OMAP-L138| 137/6747 SK |LCDK138|LCDK6748|
+--------------+---------+---------+-------------+-------+--------+
|Board Support |    X    |    X    |      X      |   X   |   X    |
+--------------+---------+---------+-------------+-------+--------+
|Boot (SBL)    |    X    |    X    |      X      |   X   |   X    |
+--------------+---------+---------+-------------+-------+--------+
|Diagnostics   |    X    |         |      X      |       |        |
+--------------+---------+---------+-------------+-------+--------+
|FATFS         |    X    |    X    |      X      |   X   |   X    |
+--------------+---------+---------+-------------+-------+--------+
|Network (CPSW)|    X    |    X    |      X      |   X   |   X    |
+--------------+---------+---------+-------------+-------+--------+

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

.. raw:: html
