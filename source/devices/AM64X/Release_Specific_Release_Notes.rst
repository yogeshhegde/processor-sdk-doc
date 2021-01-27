.. _Release-note-label:

************************************
Release Notes
************************************

Overview
========

The **Processor Software Development Kit (Processor SDK)** is a unified software platform for TI embedded processors 
providing easy setup and fast out-of-the-box access to benchmarks and demos.  All releases of Processor SDK are 
consistent across TI’s broad portfolio, allowing developers to seamlessly reuse and develop software across devices. 
Developing a scalable platform solutions has never been easier than with the Processor SDK and TI’s embedded processor 
solutions.

To simplify the end user experience, Processor SDK AM64x installer provides, everything needed to create the embedded 
system from “scratch”, with...

-  Reference Examples - Servo Drive, TimeSync, R5 benchmarks
-  Protocol stacks - TI EtherCAT, ProfiNET, EthernetIP Adapter
-  Industrial Drives - EnDAT, HDSL
-  Platform/board-support software and configuration files for Linux, RTOS and Bare-metal
-  U-Boot and Kernel sources and configuration files
-  An ARM cross-compiling toolchain as well as other host binaries and components
-  A Yocto/OE compliant filesystem and sources for example applications
-  A variety of scripts and Makefiles to automate certain tasks
-  Other components needed to build an embedded system that don’t fit neatly into one of the above buckets


Licensing
=========

Please refer to the software manifests, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page or in the installed directory as indicated below. 

-  Linux Manifest:  "/linux/docs/software_manifest.htm"
-  RTOS/BM Manifest:  "/Processor_SDK_SITARA_manifest.html"


Release 07.02.00
================

Released on January 2021

.. rubric:: What's New
   :name: whats-new

Processor SDK AM64x Release has following new features:

This release integrates complete servo drive, timesync and benchmark examples built on top of RTOS, Baremetal and Linux platform software and Industrial communication protocols. Refer to highlights per subsystem for more detailed information.

**Servo Drive Demo:**

-  3-axes CiA402 motor control demo functional on AM64x EVM w/ TwinCAT as EtherCAT master on PC
-  EtherCAT 3-axes CiA402 Slave stack and TimeSync on R5F1-0/TIRTOS
-  Position Speed loop controller and FSI interface w/ C2K Motor on R5F2-0/BM
-  Low latency MBX IPC between R5F1-0 & R5F2-0

**Benchmark Demo:**

-  Benchmark_demo with GUI (A53/Linux) working for all 4 R5F/BM cores with u-boot based SD card boot
-  4-ch IPC RPMsg_char functional between R5F/BM and A53/Linux
-  Benchmarking R5F apps such as CFFT, FIR, FOC, PID, and ADC/PWM with profile/cycle counts 

**Reset Isolation**

-  ICSSG and M4 reset isolation with servo dive demo
-  Standalone reset isolation validated with on board heartbeat LEDs

**Sample Examples**

-  R5F Hello world Application
-  TimeSync Example
-  CCS based Sample Applications

**Platform SW/board-support**

-  Integrated with latest tools and Platform SW releases (Linux/RTOS/BM)


**Dependent component Release notes**

Refer below component release notes for complete feature-set and further details

-  For Linux Kernel, u-boot & DTB     `[Use Link] <Linux_Release_Notes.html>`__
-  For Platform Development Kit (PDK) `[Use Link] <../../rtos/pdk_am64x/docs/userguide/am64x/family_cfg/am64x/index_release_notes_am64x.html>`__
-  For EtherCAT Slave                 `[Use Link] <../../rtos/pru_icss_docs/indsw/EtherCAT_Slave/EtherCAT_Slave.html>`__
-  For ProfiNetSlave                  `[Use Link] <../../rtos/pru_icss_docs/indsw/profinet_slave/profinet_slave.html>`__
-  For Ethernet_ip_adapter            `[Use Link] <../../rtos/pru_icss_docs/indsw/ethernetIP_adapter/ethernetIP_adapter.html>`__
-  For Industrial Drives (EnDAT,HDSL) `[Use Link] <../../rtos/pru_icss_docs/indsw/Industrial_Drives/Industrial_Drives.html>`__


.. rubric:: Known Issues
   :name: Known Issue
   
-  For windows installer, install always in C:/ti. Do not install in any deeper directory structure as build might fail due to the 260 character path length limit exist in Windows operating system 

-  SITSW-373 - Servo Drive Demo: TwinCAT stuck in INIT mode with OPSI boot

-  SITSW-372 - Continuous mode does not work for EnDAT.



.. rubric:: Issues Fixed
   :name: Issues Fixed

-  This is the first release of Processor SDK AM64X.
