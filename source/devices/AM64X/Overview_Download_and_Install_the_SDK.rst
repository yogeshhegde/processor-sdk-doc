Download and Install the SDK
======================================

**Processor SDK AM64x 0.9 (Early Adapter)** Release support both Linux and Windows versions of installers

-  processor_sdk_sitara_am64x_00_09_00_00-windows-installer.exe
-  processor_sdk_sitara_am64x_00_09_00_00-linux-x64-installer.run

For windows installer, install always in C:/ti. Do not install in any deeper directory structure as build might fail due to the 260 character path length limit exist in Windows operating system


Note: This early adapter release contain basic demos, Linux/RTOS drivers & industrial protocols, and intend to showcase that silicon is up and running.  This should not be used for any SW development or benchmarking.  This a bring-up package with minimal documentation and test coverage.

**Instructions to set-up CCS**

-  Refer /<INSTALL-DIR>/rtos/pdk_am64x_xx_xx_xx_xx/docs/userguide/am64x/ccs_setup_am64x.html


**Build Instructions**

Processor SDK AM64x support GNU make based build system. Refer /<INSTALL-DIR>/sitara-apps/makerules folder for all supported demos and build targets

For Winnows version use “gmake” from /<INSTALL-DIR>/rtos/xdctools_3_61_03_29_core to build SDK


**Sample Application: R5F Hello world App for AM64x**

Build R5F Hello World App

-  $ cd /<INSTALL-DIR>/sitara-apps

For Linux

-  $ make common_libs
-  $ make r5f_hello_world

For Windows

-  $ gmake common_libs
-  $ gmake r5f_hello_world

The built binary files will be in /<INSTALL-DIR>/sitara-apps/examples/r5f_hello_world/out/AM64X/R5F/NO_OS/release

Run R5F Hello World App using CCS with JTAG

-  Power up the AM64x EVM, Launch the CCS, Launch the AM64x_EVM.ccxml
-  Run load script - loadJSFile “/<INSTALL-DIR>/rtos/pdk_am64x_xx_xx_xx_xx/packages/ti/drv/sciclient/tools/ccsLoadDmsc/am64x launch.js”
-  By default, the MAIN_Cor_R5_0_0 will be halt at 0x00000000. Load the OUT files for mcu1_0 to MAIN_Cor_R5_0_0


**Benchmark demos**

-  Refer Demo User Guides -> Benchmark Demo - User Guide


**Servo drive demo**

-  Refer Demo User Guides -> Servo Drive Demo - User Guide

