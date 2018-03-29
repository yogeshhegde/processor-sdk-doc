.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_CMB_AddOn 

.. rubric:: Introduction
   :name: introduction

This page describes the Circular Microphone Board (CMB) Addon library
and the unit test provided in the Processor-SDK for RTOS.

The key functions in the CMB Addon library include:

-  Initialize the board connects to the CMB
-  Initialize/configure the McASP, EDMA, I2C and GPIO
-  Set up the CMB and on-board audio codec to the correct sample rate
   and format

The unit test demo utilizes other Processor SDK features/components:

-  **SYS/BIOS** application utilizing TI-RTOS features for DSP-C66x core
-  **UIA** for instrumentation logging

Currently, the following devices and EVMs are supported:

-  K2G, on the K2G EVM. See TIDEP-0088
   (http://www.ti.com/tool/TIDEP-0088) for details
-  OMAP-L137, on the OMAP-L137 EVM. See TIDEP-0099
   ((http://www.ti.com/tool/TIDEP-0099)) for details

.. rubric:: Requirements
   :name: requirements

The following materials are required to run this add-on unit test:

Hardware

-  TI EVMs (see list above)
-  Circular Microphone Array Board (CMB)
-  OMAP-L137 Prototype Board (for OMAP-L137 EVM only)

Software

-  Processor-SDK RTOS (4.0 or greater)
-  Code Composer Studio 6.1.3 and up

.. rubric:: Software Design
   :name: software-design

.. rubric:: Framework for Unit Test
   :name: framework-for-unit-test

The current framework is based on SYS/BIOS. The following are the
overall steps:

-  The McASP/EDMA will generate interrupt every 10ms (approximately)
-  The EDMA ISR will prepare the audio frame buffer pointers (McASP/EDMA
   RX buffer) for further processing
-  The EDMA ISR will also send a semaphore to wake up the main task
-  When woke up, the main thread will perform the audio de-interleaving
   to separate the channels
-  The main thread will also output two of eight channels to McASP/EDMA
   TX buffer
-  The McASP/EDMA will send the TX buffer to the on-board audio codec

.. rubric:: How to Build the CMB Library and Unit Test
   :name: how-to-build-the-cmb-library-and-unit-test

.. rubric:: K2G EVM
   :name: k2g-evm

**For Linux:**

-  Under pdk_k2g_1_x_x/packages directory, run the following commands:

::

      source ./pdksetupenv.sh
      make cmb_clean
      make cmb
      the libraries will be in 
         pdk_k2g_1_x_x/packages/ti/addon/cmb/lib/k2g/c66/release
      the OUT file (audioAnalogLoopbackTest.out) for DSP will be built at 
         pdk_k2g_1_x_x/packages/ti/addon/cmb/test/evmK2G/analog/loopback/build/make

**For Windows:**

-  Under pdk_k2g_1_x_x/packages directory, run the following commands:

::

      pdksetupenv.bat
      gmake cmb_clean
      gmake cmb
      the libraries will be in 
         pdk_k2g_1_x_x\packages\ti\addon\cmb\lib\k2g\c66\release
      the OUT file (audioAnalogLoopbackTest.out) for DSP will be built at 
         pdk_k2g_1_x_x\packages\ti\addon\cmb\test\evmK2G\analog\loopback\build\make

.. rubric:: OMAP-L137 EVM
   :name: omap-l137-evm

**For Linux:**

-  Under pdk_omapl137_1_x_x/packages directory, run the following
   commands:

::

      source ./pdksetupenv.sh
      make cmb_clean
      make cmb
      the libraries will be in 
         pdk_omapl137_1_x_x/packages/ti/addon/cmb/lib/omapl137/c674/release
      the OUT file (audioAnalogLoopbackTest.out) for DSP will be built at 
         pdk_omapl137_1_x_x/packages/ti/addon/cmb/test/evmOMAPL137/analog/loopback/build/make

**For Windows:**

-  Under pdk_omapl137_1_x_x\packages directory, run the following
   commands:

::

      pdksetupenv.bat
      gmake cmb_clean
      gmake cmb
      the libraries will be in 
         pdk_omapl137_1_x_x\packages\ti\addon\cmb\lib\omapl137\c674\release
      the OUT file (audioAnalogLoopbackTest.out) for DSP will be built at 
         pdk_omapl137_1_x_x\packages\ti\addon\cmb\test\evmOMAPL137\analog\loopback\build\make

.. rubric:: How to Run the Unit Test
   :name: how-to-run-the-unit-test

The unit test will be loaded onto the target using JTAG. After running
the unit test, the 2 out of 8 input audio channels from CMB will be
output to the line-out of the on-board audio codec.

The following sections provide detailed steps for each EVM.

.. rubric:: K2G EVM
   :name: k2g-evm-1

-  Follow this link
   (http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Setup_CCS)
   to get target configuration setup correctly.
-  Connect to the on board emulator (J1 on K2G EVM) to your PC USB
-  Plug power adaptor(12V) into the K2G EVM and power on the EVM
-  Launch the ccxml created above using "Launch Selected Configuration"
   from CCS 6.1.3
-  Then "Connect to C66xx_DSP"
-  Load the audioAnalogLoopbackTest.out from
   pdk_k2g_1_x_x/packages/ti/addon/cmb/test/evmK2G/analog/loopback/build/make
-  Run the program (loaded previously) by pressing F8
-  The program will run the unit test forever, taking the input from CMB
   and output to the on-board line-out

.. rubric:: OMAP-L137 EVM
   :name: omap-l137-evm-1

-  Follow this link
   (http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Setup_CCS)
   to get target configuration setup correctly.
-  Connect to the on board emulator (J201 on OMAP-L137 EVM) to your PC
   USB
-  Plug power adaptor(5V) into the OMAP-L137 EVM and power on the EVM
-  Launch the ccxml created above using "Launch Selected Configuration"
   from CCS 6.1.3
-  Then "Connect to C674X_0"
-  Load the audioAnalogLoopbackTest.out from
   pdk_omapl137_1_x_x/packages/ti/addon/cmb/test/evmOMAPL137/analog/loopback/build/make
-  Run the program (loaded previously) by pressing F8
-  The program will run the unit test forever, taking the input from CMB
   and output to the on-board line-out

| 

.. raw:: html

