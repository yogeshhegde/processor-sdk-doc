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

Release 05.00.00
==================

Released July 2018.

.. rubric::  What's New
   :name: whats-new

.. rubric::  New Features
   :name: new-features

-  AM335x,AM437x,AM57x,K2G
	- `Uniflash Flash programmer: <Board_EVM_Abstration.html#uniflash>`__ Available as Early Adopter feature in this release. Includes flashing support through JTAG and UART for following peripherals and EVMs
		- SPI:  AMIC110 ICE, AM335x EVM, AM335x ICE
		- QSPI: AM437x  IDK, AM571x IDK,AM572x IDK,AM574x IDK,K2G ICE,K2G EVM
-  K2G
	- `Performance Audio Demo Framework: <Examples_and_Demonstrations.html#performance-audio-demo>`__ Demo Audio Application illustrating integration of I/O, auto detection,decoding,audio stream processing and encoding
-  `UART AppLoader: <Foundational_Components.html#uart-apploader>`__ Two stage bootloader support through UART interface
-  Improved OOB experience for overall `Building SDK <How_to_Guides.html#building-pdk-using-gmake-in-windows-environment>`__ with introduction of RULES_MAKE based environment. All envrionment variable dependency for processor SDK updates handled during post installation step


.. rubric::  Component Version
   :name: component-version

The following software components and host tools are bundled with the
SDK installer. See the :ref:`Software Developer Guide <Index-Processor-SDK-RTOS-label>` for
more information on each item.

.. note::
   | This release has been tested with the following component and tool versions. It is recommended to use the versions listed here to avoid compatibility issues. 

+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
|  Component  |   Version   |AM335x|AM437x|AM57x |K2H/K2K| K2E  | K2L  | K2G  |C665x |C667x |OMAP-L137|OMAP-L138|
+=============+=============+======+======+======+=======+======+======+======+======+======+=========+=========+
| CG_XML      | 2.41.0      |   X  |  X   |  X   |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
| CTOOLSLIB   | 2.2.0.0     |      |      |  X   |   X   |  X   |  X   |  X   |  X   |  X   |         |         |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
| DSPLIB      | 3.4.0.0     |      |      |  X   |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
| EDMA3 LLD   | 2.12.5.30   |   X  |  X   |  X   |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
| FC          | 3.40.2.7    |      |      |  X   |   X   |  X   |  X   |  X   |  X   |  X   |         |         |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
| FFTLIB      | 3.1.0.0     |      |      |      |       |      |      |      |      |  X   |         |         |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
| IMGLIB      | 3.1.1.0     |      |      |  X   |   X   |  X   |  X   |  X   |  X   |  X   |         |         |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
| IPC         | 3.47.0.0    |      |      |  X   |   X   |  X   |  X   |  X   |  X   |  X   |         |    X    |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
| LIBARCH     | 1.0.0.0     |      |      |      |       |      |      |      |      |  X   |         |         |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
| LINALG      | 1.2.0.0     |      |      |      |       |      |      |      |      |  X   |         |         |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
| MATHLIB     | 3.1.1.0     |      |      |  X   |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
| MPM         | 3.0.4.0     |      |      |      |   X   |  X   |  X   |  X   |      |      |         |         |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
| NDK         | 2.26.0.0    |   X  |  X   |  X   |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
| OPENCL      | 1.1.14.1    |      |      |  X   |       |      |      |      |      |      |         |         |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
| OPENMP      | Per platform|      |      |  X   |   X   |  X   |  X   |  X   |  X   |  X   |         |         |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
| PDK         |             |1.0.11|1.0.11|1.0.11| 4.0.10|4.0.10|4.0.10|1.0.10|2.0.10|2.0.10|  1.0.5  |  1.0.5  |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
| SYS/BIOS    | 6.52.0.12   |   X  |  X   |  X   |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
| UIA         | 2.21.2.07   |      |      |  X   |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
| XDAIS       | 7.24.0.4    |      |      |  X   |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+
| XDCTOOLS    | 3.50.03.33  |   X  |  X   |  X   |   X   |  X   |  X   |  X   |  X   |  X   |    X    |    X    |
+-------------+-------------+------+------+------+-------+------+------+------+------+------+---------+---------+


The following compilers are bundled with the SDK installer:

+----------------+---------+------+------+------+-------+-----+-----+--------+-----+-----+---------+---------+
|    Compiler    | Version |AM335x|AM437x|AM57x |K2H/K2K| K2E | K2L |  K2G   |C665x|C667x|OMAP-L137|OMAP-L138|
+================+=========+======+======+======+=======+=====+=====+========+=====+=====+=========+=========+
|GNU ARM Embedded|6-2017-q1|   A8 |  A9  |  A15 |  A15  | A15 | A15 |  A15   |     |     |         |         |
+----------------+---------+------+------+------+-------+-----+-----+--------+-----+-----+---------+---------+
|TI ARM CGT      | 16.9.3  |      |      |  M4  |       |     |     |A15(SBL)|     |     |   ARM9  |   ARM9  |
+----------------+---------+------+------+------+-------+-----+-----+--------+-----+-----+---------+---------+
|TI C6000 CGT    | 8.2.2   |      |      | C66x | C66x  |C66x |C66x |  C66x  |C66x |C66x |   C74x  |   C74x  |
+----------------+---------+------+------+------+-------+-----+-----+--------+-----+-----+---------+---------+
|TI PRU CGT      | 2.2.1   | PRU  | PRU  | PRU  |       |     |     |  PRU   |     |     |         |         |
+----------------+---------+------+------+------+-------+-----+-----+--------+-----+-----+---------+---------+

The SDK uses Code Composer Studio (CCS) as the integrated development
environment (IDE) for all devices and EVMs:

+-----------+----------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+
| Component | Version  |AM335x|AM437x|AM57x |K2H/K2K| K2E | K2L | K2G |C665x|C667x|OMAP-L137|OMAP-L138|
+===========+==========+======+======+======+=======+=====+=====+=====+=====+=====+=========+=========+
|   CCS     | 8.0.0.16 |   X  |  X   |  X   |   X   |  X  |  X  |  X  |  X  |  X  |    X    |    X    |
+-----------+----------+------+------+------+-------+-----+-----+-----+-----+-----+---------+---------+


If you need to install CCS, see the `CCS installation section <Overview.html#code-composer-studio>`__
in the *Getting Started Guide* for options to select for Processor-SDK.

**Change log**

Updated

-  CCS 8.0.0.16
-  PDK for all platforms

Fixed Issues 
==============

+-----------------------+-----------------------+-----------------------+
|      Record ID        |       Platform        |       Summary         |
+=======================+=======================+=======================+
| PRSDK-642             | \*                    |RTOS: SDK components   |
|                       |                       |should be signed to    |
|                       |                       |avoid Eclipse/CCS      |
|                       |                       |warning when importing |
+-----------------------+-----------------------+-----------------------+
| PRSDK-3718            | AM57x                 | L3/L4 Interconnect    |
|                       |                       | CLKSEL configuration  |
|                       |                       | does not take to      |
|                       |                       | effect                |
+-----------------------+-----------------------+-----------------------+
| PRSDK-3030            | omap L13x             | SPI driver Interrupt  |
|                       |                       | mode is not functional|
|                       |                       |                       |
+-----------------------+-----------------------+-----------------------+
| PRSDK-3856            | AM335x AM437x         | StarterWare build from|
|                       |                       | the PDK starterware   |
|                       |                       | folder fails on       |
|                       |                       | Windows  OS           |
+-----------------------+-----------------------+-----------------------+
| IPC-217               | C667x,k2h,k2e         | IPC listMP corruption |
+-----------------------+-----------------------+-----------------------+
| PRSDK-3859            | am57xx,c665x,c667x    | Audio benchmark       |
|                       | omapl13x,keystone2    | starterkit demo fails |
|                       | c674x                 | to build in Windows   |
|                       |                       | with Rules.make       |
|                       |                       | environment  setup    |
+-----------------------+-----------------------+-----------------------+
| PRSDK-3865            | am57xx,c665x,c667x    | SPI driver doesn`t    |
|                       | omapl13x,keystone2    | support timeout       |
|                       | c674x                 |                       |
+-----------------------+-----------------------+-----------------------+
| PRSDK-4013            | k2h                   | Client Socket recv()  |
|                       |                       | returns -1 with large |
|                       |                       | stream of data        |
+-----------------------+-----------------------+-----------------------+
| PRSDK-3749            | K2G                   |USB Spurrious interrupt|
|                       |                       |in device mode config  |
+-----------------------+-----------------------+-----------------------+
| PRSDK-3932            | AMIC110               | DDR Less bootloader   |
|                       |                       | support               |
+-----------------------+-----------------------+-----------------------+
| PRSDK-4182            | AM57xx                | Global interrupt      |
|                       |                       | disabling in EMAC     |
|                       |                       | driver breaks real    |
|                       |                       | time task             |
+-----------------------+-----------------------+-----------------------+
| PRSDK-4012            | AM335x AM437x         | Update to use -Wl,    |
|                       |                       | --start-group -Wl,    |
|                       |                       | --end-group during    |
|                       |                       | linking with GCC      |
|                       |                       | compiler              |
+-----------------------+-----------------------+-----------------------+
| PRSDK-3866            | AM57xx                | DSP1 image of IPC     |
|                       |                       | ex02_messageq example |
|                       |                       | doesn't work          |
+-----------------------+-----------------------+-----------------------+
| PRSDK-3867            | c674x, omapl13x       | MMCSD examples do not |
|                       |                       | detect SD card        |
|                       |                       | insertion             |
+-----------------------+-----------------------+-----------------------+
| PRSDK-3933            | AM57x                 | AM57x Board library   |
|                       |                       | sets L3MAIN1 and      |
|                       |                       | L4CFG CLKSTCTRL       |
|                       |                       | to Reserved_2         |
+-----------------------+-----------------------+-----------------------+
| PRSDK-4000            | k2g,omapl13x          | Aud/CMB loopback test |
|                       |                       | and Audio             |
|                       |                       | pre-processing demos  |
|                       |                       | failure               |
+-----------------------+-----------------------+-----------------------+
| PRSDK-4048            | k2l                   | K2L boot loader       |
|                       |                       | failure in SPI boot   |
|                       |                       | mode                  |
+-----------------------+-----------------------+-----------------------+

.. RN_Supported-Platforms-label:
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
|`RTOS-C665X`_   |`C665x`_    | `C6652`_, `C6654`_, `C6655`_, `C6657`_                                        |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-C667X`_   |`C667x`_    | `C6671`_, `C6672`_, `C6674`_, `C6678`_                                        |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-K2E`_     |`K2E`_      | `66AK2E02`_, `66AK2E05`_, `AM5K2E02`_, `AM5K2E04`_                            |
+----------------+------------+-------------------------------------------------------------------------------+
|`RTOS-K2G`_     |`K2G`_      | `66AK2G02`_                                                                   |
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
.. _K2G: http://www.ti.com/lsds/ti/processors/dsp/c6000_dsp-arm/66ak2x/overview.page
.. _66AK2G02: http://www.ti.com/product/66ak2g02

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

See `Processor SDK Supported Platforms <Release_Specific.html#supported-platforms-and-versions>`__
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

+------------------+--------------------+---------------+-----------+-----------+
|     Feature      |    Platform/SOC    |  AM335x EVM   |AM437x EVM | AM57x EVM |
+==================+=======+======+=====+===+===+===+===+===+===+===+=====+=====+
|                  |AM335x |AM437x|AM57x|GP |ICE|SK |BBB|GP |IDK|SK | GP  | IDK |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| CSL              |   X   |   X  |  X  | X | X | X | X | X | X | X |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| EMAC             |   X   |   X  |  X  | X | X | X | X | X | X | X |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| EDMA3            |   X   |   X  |  X  | X |   |   |   | X |   |   |  X  |     |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| GPIO             |   X   |   X  |  X  |   | X |   | X | X |   | X |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| GPMC             |   X   |   X  |     |   | X |   |   | X |   |   |     |     |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| I2C              |   X   |   X  |  X  | X | X | X | X | X | X | X |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| PRUSS-I2C f/w    |   X   |   X  |  X  |   | X |   |   |   | X |   |     |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| ICSS-EMAC        |   X   |   X  |  X  |   | X |   |   |   | X |   |     |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| McASP            |   X   |   X  |  X  | X |   |   |   | X |   |   |  X  |     |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| McSPI            |   X   |   X  |  X  |   | X |   |   |   | X |   |     |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| MMC-SD           |   X   |   X  |  X  | X | X | X | X | X | X | X |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| PCIe             |       |      |  X  |   |   |   |   |   |   |   |     |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| PM               |   X   |      |  X  | X |   |   |   |   |   |   |  X  |     |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| PRUSS            |   X   |   X  |  X  |   | X |   |   |   | X |   |     |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| QSPI             |       |   X  |  X  |   |   |   |   |   | X | X |     |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| UART             |   X   |   X  |  X  | X | X | X | X | X | X | X |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| USB              |   X   |   X  |  X  | X |   |   |   | X |   |   |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| USB Device Audio |   X   |      |     | X |   |   |   |   |   |   |     |     |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| USB Device Bulk  |   X   |   X  |  X  | X |   |   |   | X |   |   |     |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| VPS              |       |      |  X  |   |   |   |   |   |   |   |  X  |  X  |
+------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+

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
| USB Device Bulk  |       |   |   | X |     |     |   |   |   |   |       |     |     |
+------------------+-------+---+---+---+-----+-----+---+---+---+---+-------+-----+-----+


**DSP devices - OMAP-L13x, C674x**

+----------------+-------------------+-------------+----------------+
|    Feature     |   Platform/SOC    |OMAP-L137 EVM| OMAP-L138 EVM  |
+================+=========+=========+=============+=======+========+
|                |OMAP-L137|OMAP-L138| 137/6747 SK |LCDK138|LCDK6748|
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
|McBSP           |  K2G    |    A15  |
+----------------+---------+---------+
|McBSP           |OMAP-L13x|    ARM9 |
+----------------+---------+---------+
|All Drivers     |  K2x    |    A15  |
+----------------+---------+---------+

Other Features 
----------------

The following table shows other feature availability per platform and
EVM:

**Sitara devices**

+----------------------------+--------------------+---------------+-----------+-----------+
|          Feature           |    Platform/SOC    |  AM335x EVM   |AM437x EVM | AM57x EVM |
+============================+=======+======+=====+===+===+===+===+===+===+===+=====+=====+
|                            |AM335x |AM437x|AM57x|GP |ICE|SK |BBB|GP |IDK|SK | GP  | IDK |
+----------------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| Board Support              |   X   |  X   |  X  | X | X | X | X | X | X | X |  X  |  X  |
+----------------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| Boot (SBL)                 |   X   |  X   |  X  | X | X | X | X | X | X | X |  X  |  X  |
+----------------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| Diagnostics                |   X   |  X   |  X  | X |   |   |   | X |   |   |  X  |  X  |
+----------------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| FATFS                      |   X   |  X   |  X  | X | X |   |   | X | X |   |  X  |  X  |
+----------------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| NDK-NIMU(CPSW)             |   X   |  X   |  X  | X | X | X | X | X | X | X |  X  |  X  |
+----------------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
| NDK-NIMU(ICSS)             |   X   |  X   |  X  |   | X |   |   |   | X |   |     |  X  |
+----------------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
|CC-LINK IE Field Basic(CPSW)|   X   |  X   |  X  | X | X | X | X | X | X | X |  X  |  X  |
+----------------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+
|CC-Link IE Field Basic(ICSS)|   X   |  X   |  X  |   | X |   |   |   | X |   |     |  X  |
+----------------------------+-------+------+-----+---+---+---+---+---+---+---+-----+-----+

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


Known Issues 
==============

This section contains the list of known issues at the time of making the
release and any known workaround.

+-------------+-------------+-------------+-------------+---------------------------------------------------------+
|  Record ID  |  Platform   |    Area     |   Summary   | Workaround                                              |
+=============+=============+=============+=============+=========================================================+
| PRSDK-642   | \*          | Processor   | RTOS: SDK   | Ignore the Eclipse/CCS warning                          |
|             |             | SDK         | components  |                                                         |
|             |             | Installer   | should be   |                                                         |
|             |             |             | signed to   |                                                         |
|             |             |             | avoid       |                                                         |
|             |             |             | Eclipse/CCS |                                                         |
|             |             |             | warning     |                                                         |
|             |             |             | when        |                                                         |
|             |             |             | importing   |                                                         |
+-------------+-------------+-------------+-------------+---------------------------------------------------------+
| PRSDK-335   | AM4X        | High-Speed  | USB host    | Re-enumeration support for the case of                  |
|             |             | Drivers     | MSC fails   | device unplugged                                        |
|             |             |             | to          | and plugged back currently fails for the                |
|             |             |             | re-enumerat | example.Workaround is to avoid                          |
|             |             |             | e           | disconnecting drive while running example.              |
+-------------+-------------+-------------+-------------+---------------------------------------------------------+
| PRSDK-330   | AM4X        | High-Speed  | USB device  | Problem not observed with Linux USB Host.               |
|             |             | Drivers     | MSC         |                                                         |
|             |             |             | re-enumerat |                                                         |
|             |             |             | ion         |                                                         |
|             |             |             | fails while |                                                         |
|             |             |             | disconnecti |                                                         |
|             |             |             | ng          |                                                         |
|             |             |             | and         |                                                         |
|             |             |             | reconnectin |                                                         |
|             |             |             | g           |                                                         |
|             |             |             | on a        |                                                         |
|             |             |             | Windows     |                                                         |
|             |             |             | host        |                                                         |
+-------------+-------------+-------------+-------------+---------------------------------------------------------+
| PRSDK-1682  | AM5X        | Diagnostics | Board       | For LCD/Display checkout example under VPS component    |
|             |             |             | diagnostics | could be used                                           |
|             |             |             | LCD         |                                                         |
|             |             |             | Touchscreen |                                                         |
|             |             |             | test does   |                                                         |
|             |             |             | not work    |                                                         |
|             |             |             | with new    |                                                         |
|             |             |             | version of  |                                                         |
|             |             |             | LCD TSC     |                                                         |
+-------------+-------------+-------------+-------------+---------------------------------------------------------+
| PRSDK-2166  | AM5X        | High-Speed  | USB3.0 host | Start the example without the USB plugged in. Once      |
|             |             | Drivers     | problem     | the example is up and waiting for USB stick,            |
|             |             |             | with        | plug the USB stick in and it will enumerateproperly.    |
|             |             |             | Sandisk     |                                                         |
|             |             |             | Extreme     |                                                         |
|             |             |             | USB3.0      |                                                         |
|             |             |             | stick       |                                                         |
+-------------+-------------+-------------+-------------+---------------------------------------------------------+
| PRSDK-1975  | \*          | Board       | Timer       | Example can run on ARM Core 0                           |
|             |             | Diagnostics | Diagnostic  |                                                         |
|             |             |             | example     |                                                         |
|             |             |             | does not    |                                                         |
|             |             |             | run on ARM  |                                                         |
|             |             |             | Core 1      |                                                         |
+-------------+-------------+-------------+-------------+---------------------------------------------------------+
| PRSDK-3344  | am572x-id,a | Board       | Diagnostics | ICSS-EMAC LLD TI-RTOS example can be used for           |
|             | m574x-idk   | Diagnostics | Baremetal   | similar test.                                           |
|             |             |             | icssEmac_TE |                                                         |
|             |             |             | ST          |                                                         |
|             |             |             | idkAM57{2/4 |                                                         |
|             |             |             | }x :        |                                                         |
|             |             |             | LINK IS     |                                                         |
|             |             |             | DOWN,       |                                                         |
|             |             |             | pluggin     |                                                         |
|             |             |             | loopback    |                                                         |
|             |             |             | cable       |                                                         |
+-------------+-------------+-------------+-------------+---------------------------------------------------------+
| PRSDK-3482  | \*          | CCS         | CCSV7.4:    | Retry for connection failure in DSS script.             |
|             |             |             | Intermitten |                                                         |
|             |             |             | t           |                                                         |
|             |             |             | issue not   |                                                         |
|             |             |             | able to     |                                                         |
|             |             |             | connect     |                                                         |
|             |             |             | target      |                                                         |
|             |             |             | while using |                                                         |
|             |             |             | DSS script  |                                                         |
+-------------+-------------+-------------+-------------+---------------------------------------------------------+
| PRSDK-2336  | am335x-evm, | PM          | PM Unit     | Use debug version of PM library for the test. To        |
|             | am437x-evm  |             | Test        | build from the top-level makefile in                    |
|             |             |             | failure     | pdk.../packages folder run "make BUILD_CONFIG=debug pm" |
|             |             |             |             |                                                         |
|             |             |             |             |                                                         |
|             |             |             |             |                                                         |
|             |             |             |             |                                                         |
|             |             |             |             |                                                         |
|             |             |             |             |                                                         |
|             |             |             |             |                                                         |
|             |             |             |             |                                                         |
|             |             |             |             |                                                         |
|             |             |             |             |                                                         |
|             |             |             |             |                                                         |
|             |             |             |             |                                                         |
|             |             |             |             |                                                         |
+-------------+-------------+-------------+-------------+---------------------------------------------------------+
| PRSDK-3318  | K2G 1Ghz    | EMAC        | EMAC_CpswRa | Incorrect Core clock config in test. Fix for            |
|             |             |             | teLimit_evm | to set the correct CPU clock                            |
|             |             |             | K2G_c66xExa |                                                         |
|             |             |             | mpleProject |                                                         |
|             |             |             | failure on  |                                                         |
|             |             |             | 1GHz Flip   |                                                         |
|             |             |             | Chip        |                                                         |
+-------------+-------------+-------------+-------------+---------------------------------------------------------+
| PRSDK-4184  | am57x,k2x   | Board       | Hello_World:| Problem observed with using GCC semihosting support     |
|             |             | Diagnostic  | Baremetal   | Use UART driver for input and output                    |
|             |             |             | ARM         |                                                         |
|             |             |             | Cortex-A15  |                                                         |
|             |             |             | test example|                                                         |
|             |             |             | failure     |                                                         |
+-------------+-------------+-------------+-------------+---------------------------------------------------------+
| PRSDK-4214  | k2g-hs      | Board       |create-sdcard| Default generated App image is not signed               |
|             |             | Diagnostic  |script does  | follow the steps mentioned in section 6.2.1.2           |
|             |             |             |not boot OOB | of the Processor SDK Secdev Build and Install           |
|             |             |             |             | Guide to sign the app                                   |
+-------------+-------------+-------------+-------------+---------------------------------------------------------+
| PRSDK-642   | \*          | Uniflash    | Uniflash    |Command line option can be used.                         |
|             |             |             | based       |Refer `User Guide <Board_EVM_Abstration.html#uniflash>`__|
|             |             |             | flashing is |                                                         |
|             |             |             | not         |                                                         |
|             |             |             | available   |                                                         |
|             |             |             | through GUI |                                                         |
+-------------+-------------+-------------+-------------+---------------------------------------------------------+
| PRSDK-4325  | \*          | USB Bulk    | USB Bulk    |Available from                                           |
|             |             |             | Mode Python |`External GIT location <https://git.ti.com/keystone-rtos/|
|             |             |             | test script |usb/trees/master/example/usb_dev/bulk>`__                |
|             |             |             | missing in  |                                                         |
|             |             |             | package     |                                                         |
+-------------+-------------+-------------+-------------+---------------------------------------------------------+
| PRSDK-4108  | omapl13x    | USB         | USB Audio:  | None                                                    |
|             |             |             | Lag when    |                                                         |
|             |             |             | trying to   |                                                         |
|             |             |             | adjust      |                                                         |
|             |             |             | volume      |                                                         |
+-------------+-------------+-------------+-------------+---------------------------------------------------------+
| PRSDK-3383  | am574x-idk  | Board       | Diagnostic  | None                                                    |
|             |             | Diagnostic  | lcdTouchscr |                                                         |
|             |             |             | een_TEST    |                                                         |
|             |             |             | hangs on    |                                                         |
|             |             |             | AM574x IDK  |                                                         |
+-------------+-------------+-------------+-------------+---------------------------------------------------------+
| PRSDK-3369  | am574x-idk  | PCIE-LLD    | PCIE board  | None                                                    |
|             |             |             | to board    |                                                         |
|             |             |             | ARM test    |                                                         |
|             |             |             | examples    |                                                         |
|             |             |             | hangs on    |                                                         |
|             |             |             | idkAM574x   |                                                         |
|             |             |             | platform    |                                                         |
+-------------+-------------+-------------+-------------+---------------------------------------------------------+
| PRSDK-4304  | am335x      | Uniflash    | Flash writer| Rebuilding the flash writer binaries shall fix this     |
|             |             | Flash       | prebuilt    | issue. Refer the `Rebuilding the flash writer           |
|             |             | Writer      | binaries    | <Board_EVM_Abstration.html#rebuilding-flashwriter>`__   |
|             |             |             | does not    |                                                         |
|             |             |             | work on     |                                                         |
|             |             |             | AM335x      |                                                         |
|             |             |             | platforms   |                                                         |
+-------------+-------------+-------------+-------------+---------------------------------------------------------+

Installation and Usage 
========================

The :ref:`Getting Started Guide <Processor-SDK-RTOS-Getting-Started-Guide-label>` provides
instructions on how to setup up your development environment, install
the SDK and start your development.

To uninstall the SDK, remove the individual component directories from
the installed path. This is safe to do even in Windows since these
components do not modify the Windows registry.

| 

Host Support 
==============

The recommended development host is

-  **Windows**: Windows 10 on 64-bit machine
-  **Linux**: Ubuntu 16.04 on 64-bit machine

.. raw:: html

   <div
   style="margin: 5px 25px; padding: 2px 10px; background-color: #ecffff; border-top: 1px solid #3399ff; border-bottom: 1px solid #3399ff;">

**NOTE**

The Windows installer is a 32-bit binary, but is compatibility with
64-bit machine.

.. raw:: html

   </div>

| 

Technical Support and Product Updates 
=======================================

For further information or to report any problems, contact TI E2E:

-  `Sitara Processor <http://e2e.ti.com/support/arm/sitara_arm/f/791>`__
   for AM335x, AM437x, and AM57x
-  `C6000 Multicore
   DSP <http://e2e.ti.com/support/dsp/c6000_multi-core_dsps/f/639>`__
   for C665x, C667x, K2E, K2G, K2H, and K2L
-  `OMAP
   Processor <http://e2e.ti.com/support/dsp/omap_applications_processors/f/42>`__
   for OMAP-L13x, C674x

| 

Archived 
==========
-  `Processor-SDK RTOS
   4.3.0 <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/04_03_00_05/rtos/Release_Specific.html#processor-sdk-rtos-release-notes>`__
-  `Processor-SDK RTOS
   4.2.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=232579>`__
-  `Processor-SDK RTOS
   4.1.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=231132>`__
-  `Processor-SDK RTOS
   4.0.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=229408>`__
-  `Processor-SDK RTOS
   3.3.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=227097>`__
-  `Processor-SDK RTOS
   3.2.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=223820>`__
-  `Processor-SDK RTOS
   3.1.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=222796>`__
-  `Processor-SDK RTOS
   3.0.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=220543>`__
-  `Processor-SDK RTOS
   2.0.2 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=216065>`__
-  `Processor-SDK RTOS
   2.0.1 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=211983>`__
-  `Processor-SDK RTOS
   2.0.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Release_Notes&oldid=208435>`__

| 

.. raw:: html
