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

To simplify the end user experience, Processor SDK Linux AM64x installer provides, everything needed to create the embedded 
system from “scratch”, with...

-  Platform/board-support software and configuration files for Linux
-  U-Boot and Kernel sources and configuration files
-  An ARM cross-compiling toolchain as well as other host binaries and components
-  A Yocto/OE compliant filesystem and sources for example applications
-  A variety of scripts and Makefiles to automate certain tasks
-  Other components needed to build an embedded system that don’t fit neatly into one of the above buckets
-  Reference Examples, benchmarks


Licensing
=========

Please refer to the software manifests, which outlines the licensing
status for all packages included in this release. The manifest can be
found on the SDK download page or in the installed directory as indicated below. 

-  Linux Manifest:  "/docs/software_manifest.htm"
-  App/Demos Manifest:  "/sitara-apps/Processor_SDK_manifest.html"


Release 07.03.00
================

Released on March 2021

.. rubric:: What's New
   :name: whats-new

Processor SDK Linux AM64x Release has following new features:

This release integrates benchmark examples built on top of RTOS, Baremetal and Linux platform software. Refer to highlights per subsystem for more detailed information.


**Benchmark Demo:**

-  Benchmark_demo with GUI (A53/Linux) working for all 4 R5F/BM cores with u-boot based SD card boot
-  4-ch IPC RPMsg_char functional between R5F/BM and A53/Linux
-  Benchmarking R5F apps such as CFFT, FIR and FOC with profile/cycle counts 


**Platform SW/board-support**

-  Integrated with latest tools and Platform SW releases


**Dependent component Release notes**

Refer below component release notes for complete feature-set and further details

-  For Linux Kernel, u-boot & DTB     `[Use Link] <Linux_Release_Notes.html>`__
-  For RTOS/BM source (MCU+ SDK)      `[Use Link] <http://software-dl.ti.com/mcu-plus-sdk/esd/AM64X/latest/exports/docs/api_guide_am64x/RELEASE_NOTES_PAGE.html>`__
-  For Industrial Protocols (ECAT)    `[Use Link] <http://software-dl.ti.com/mcu-plus-sdk/esd/AM64X/latest/exports/docs/api_guide_am64x/INDUSTRIAL_PROTOCOLS.html>`__
-  For Industrial Drives (EnDAT,HDSL) `[Use Link] <http://software-dl.ti.com/mcu-plus-sdk/esd/AM64X/latest/exports/docs/api_guide_am64x/EXAMPLES_MOTORCONTROL.html>`__


.. rubric:: Known Issues
   :name: Known Issue
   
-  None



.. rubric:: Issues Fixed
   :name: Issues Fixed

-  This is the first release of Processor SDK Linux AM64X.
