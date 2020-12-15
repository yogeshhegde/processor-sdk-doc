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
system from “scratch”:

-  Reference Examples - Servo Drive, TimeSync, R5 benchmarks
-  Protocol stacks - TI EtherCAT
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


Release 00.09.00
==================

Released December 2020

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
-  All benchmarking R5F apps (CFFT, FIR, FOC, PID, ADC/PWM) are passing with expected cycle counts

**Rest Isolation**

-  Standalone reset isolation validated with on board heartbeat LEDs

**Combined boot flow**

-  NTR

**Platform SW/board-support**

-  Integrated with latest tools and Platform SW releases


.. rubric:: Known Issues
   :name: Known Issue
   
-  For windows installer, install always in C:/ti. Do not install in any deeper directory structure as build might fail due to the 260 character path length limit exist in Windows operating system 

   
.. rubric:: Issues Fixed
   :name: Issues Fixed

-  This is the first EA release of Processor SDK AM64X. 
