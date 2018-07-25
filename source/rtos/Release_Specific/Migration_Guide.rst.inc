****************
Migration Guide
****************

.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Migration_Guide

.. rubric::  Overview
   :name: overview

This page covers migration information for applications built on top of
the last Processor SDK for RTOS release.

| 

.. rubric::  Processor SDK RTOS 05.00.00
   :name: processor-sdk-rtos-05.00.00

.. rubric::  Build
   :name: Build

**Migration:** TOOLS_INSTALL_PATH macro value changed to SDK_INSTALL_PATH

**Additional Details**: 
TOOLS_INSTALL_PATH macro value is set to SDK_INSTALL_PATH by default.
For accessing the tools from a different path, modify TOOLS_INSTALL_PATH in 
packages/ti/build/Rules.make file or can be overriden from the build console
as shown below.

Windows
::
       set TOOLS_INSTALL_PATH=<Path for the tools root folder>

Linux
::
       TOOLS_INSTALL_PATH=<Path for the tools root folder>


.. rubric::  Build Setup
   :name: build-setup

**Migration:** There is no migration needed for default components in processor SDK.
Custom software modules and/or mmodules outside processor SDK should include 
RULES_MAKE variable.

**Additional Details**:
Rules.make file is used instead of pdksetupenv to setup the build environment variables.
Components inside processor SDK are updated to align with this change. Any applications
making use of pdksetupenv from processor SDK to setup the build environment variables
should include below line in the application makefile.

  include $(RULES_MAKE)

| 

.. rubric::  Archived
   :name: archived

-  `Processor-SDK RTOS
   4.3.0 <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/04_03_00_05/rtos/Release_Specific.html#migration-guide>`__
-  `Processor-SDK RTOS
   4.2.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=232582>`__
-  `Processor-SDK RTOS
   4.1.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=232581>`__
-  `Processor-SDK RTOS
   4.0.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=228993>`__
-  `Processor-SDK RTOS
   3.3.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=223822>`__
-  `Processor-SDK RTOS
   3.2.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=223822>`__
-  `Processor-SDK RTOS
   3.1.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=221853>`__
-  `Processor-SDK RTOS
   3.0.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=219677>`__
-  `Processor-SDK RTOS
   2.0.2 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=219677>`__
-  `Processor-SDK RTOS
   2.0.1 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=219677>`__
-  `Processor-SDK RTOS
   2.0.0 <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_Migration_Guide&oldid=219677>`__

| 

.. raw:: html

