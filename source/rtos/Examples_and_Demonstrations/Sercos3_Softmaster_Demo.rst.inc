.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Sercos3_Softmaster_Demo

Overview
========

Sercos III is a third-generation industrial control interface that merges a hard real-time communications protocol with Ethernet by introducing a synchronized cyclic communication over Ethernet. To achieve true hard real time characteristics, Sercos III uses a form of synchronization that depends upon a synchronization “mark” issued by the master control at exact equidistant time intervals.
As shown in the figure below, the Real-Time (RT) packets are merged with Non Real-Time (NRT) Ethernet traffic, and the real-time packets are sent in a cyclic manner which can be achieved by Time Triggered Send (TTS). The first MDT packet (MDT0) contains the synchronization “mark” issued from the master.
    • MDT (Master Data Telegram): contains information provided by the master to slaves
    • AT (Acknowledge Telegram): issued by the master but populated by the individual slave with their response data.

.. Image:: ../images/Sercos3_cyclicPkts.png
   :align: center

Architecture Overview
=====================

Bosch Rexroth Sercos III SoftMaster software has been developed to provide an interface that is 100% compatible with previous generation of hardware-implemented Sercos III master interfaces. This enables the existing library of CoSeMa (Common Sercos Master) driver software to be used without modification. The PRU-ICSS Softmaster implements SercosIII Softmaster stack on TI Sitara Embedded Processors and enables real-time communication via PRU-ICSS EMAC firmware and LLD.

The following block diagram shows software architecture blocks of TI’s Sitara implementation of Sercos III Softmaster.

.. Image:: ../images/Softmaster_software_Arch.png
   :align: center

MDT/AT Telegrams - TX queue distribution
========================================

MDT0 packets are mapped to the highest priority TX Queue (Queue1). MDT1 to MDT3 go to Queue 2. AT0 to AT3 packets go to Queue3 and non-real time packets to Queue4.

Directory Structure
===================

Sercos III Softmaster demo is located in the Processor SDK RTOS
release under the directory path

::

    [SDK Install Path]/processor_sdk_rtos_[soc]_[version]/demos/sercos3-softmaster

Detailed description of the directory structure is given below:

-  sercos3-softmaster - is the main directory and contains makefile.
-  bin - directory contains output executables.
-  Module - directory contains Softmaster stack modules.
-  Module/RTTI - directory contains mayority of TI modifications to Softmaster stack. 

Components Used
===============

RTOS Components:

-  SYSBIOS
-  XDC
-  PDK

Processor SDK RTOS Drivers:

-  EMAC
-  UART
-  Board
-  OSAL
-  CSL

Building the Demo
=================
    .. note::

        If building in windows use gmake instead of make.

The demo application is built using makefile. 

You must first set up your development environment. Refer to
the `Processor SDK RTOS Building <index_overview.html#building-the-sdk>`__ page for
information on setting up your build environment.

The following are steps to clean the demo:

::

     cd [SDK Install Path]/processor_sdk_rtos_[soc]_[version]/demos/sercos3-softmaster
     make clean
::

     cd [SDK Install Path]/processor_sdk_rtos_[soc]_[version]/demos/sercos3-softmaster
     make all

Enabling Time Triggered Send (TTS)
==================================

The EMAC Time Triggered Send (TTS) is used to expand classical Ethernet to meet deterministic, time-critical or safety-relevant conditions. TTS reduces helps to reduce transmission jitter from 10us range to 40ns. Refer to http://processors.wiki.ti.com/index.php/ICSS_EMAC_LLD_developers_guide#Time_Triggered_Send for more details.

-  In RTTI_GLOB.h define RTTI_PRU_TTS_NIC_TIMED macro.
-  In RTTI_S3SM_USER.h for TTS define RTOS_USE_NIC_TIMED_TX and commented out RTOS_TIMING_REL_NANOSLEEP.
-  In SICE_USER.h define SICE_USE_NIC_TIMED_TX. 

Enabling Redundancy
==================================

    .. note::

        Redundancy only works if TTS is enabled.

-  In RTTI_GLOB.h define or undefined RTTI_REDUNDANCY macro.
-  In SICE_USER.h define SICE_REDUNDANCY macro.

Running the Demo
================

You will need the following:

+-----------------------+
| EVM's supported       |
|                       |
+=======================+
|  AM335x ICEv2         | 
+-----------------------+

Additional Hardware
-------------------
#. A Sercos III slave for connecting/testing PRU-ICSS Sercos III Softmaster.
#. Ethernet LAN Cable.
#. USB to micro USB cable for JTAG and serial terminal.

SD Card Creation
----------------
-  Windows instructions: http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/index_overview.html#windows-sd-card-creation-guide.
-  Linux instrunctions: http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/index_overview.html#tools-create-sd-card-linux-label.
-  Copy binary /bin/am335x/a8/debug into SD card as "app"
-  Copy SD card SBL (MLO) into SD card. Prebuilt MLO location: [SDK Install Path]/processor_sdk_rtos_[soc]_[version]\prebuilt-sdcards\evmAM335x\sd_card_files

Set up
------

#. Connect AM335x ICEv2 Eth0 to Sercos III slave with a LAN cable. 
#. Connect USB cable between a Host PC, and AM335x's ICEv2 micro USB port. 
#. Configure and run teraterm.
    - Speed : 115200
    - Data : 8
    - Parity / Flow control : none
    - Stop bits : 1 bit
#. After SercosIII Softmaster initialize, Enter “m” for menu (optional step).
#. Then enter “f”, to Go to CP4 with automatic slave configuration.
#. After CP4 is reached, enable output with “y”.

Supported features
----------------------------
-  Standard timing.
-  NIC timing via Time Triggered Send.
-  Redundancy.
-  Minimum cycle time 1ms.

Unsupported features
----------------------------
-  Different cycle time for different Communication Phase (CP). 
-  Hot-plugging (not tested).
-  NRT communication (no tested).
-  Communication method 2. 

Fixed issues
------------
#. PRU-ICSS EMAC TX queuing performance issue. PRSDK-4965.

Known issues & limitations
--------------------------
#. PRU-ICSS EMAC + TTS : Corrupted Rx packet at host from Firmware. PRSDK-4548.
#. Redundancy can be stablished if system starts as line topology and in CP4, second port is connected in ring topology, but sometimes it fails if systems starts in ring topology.


