.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_AUDK2G_AddOn 

.. rubric:: Introduction
   :name: introduction

This page describes the unit test for the Audio Daughter Card for K2G
(AUDK2G) AddOn provided in the Processor-SDK for RTOS. This unit test
implemented the audio loopback between the ADC_IN1-4 to DAC_OUT1-4 on
AUDK2G.

The key functions in this unit test include:

-  Use board library to initialize the K2G EVM
-  Setup the PinMux for K2G EVM and the AUDK2G
-  Allocate the data buffers needed
-  Initialize the McASP and EDMA
-  Start the infinite loop for continious loopback

This unit test utilizes other Processor SDK features/components:

-  **Board Library** for K2G platform initialization
-  **AUDK2G Library** for PinMux, McASP/EDMA setups

Currently, the following device and EVM are supported:

-  K2G, on the K2G EVM with AUDK2G

| 

.. rubric:: Requirements
   :name: requirements

The following materials are required to run this unit test:

Hardware

-  K2G EVM
-  Audio Daughter Card (AUDK2G)

Software

-  Processor-SDK RTOS (3.2 or greater)
-  Code Composer Studio 6.1.3

| 

.. rubric:: How to Build the Unit Test
   :name: how-to-build-the-unit-test

.. rubric:: K2G EVM
   :name: k2g-evm

**For Linux:**

-  Under pdk_k2g_<version>/packages directory, run the following
   commands:

::

      source pdksetupenv.sh
      cd pdk_k2g_<version>/packages/ti/addon/aud/
      make clean
      make all

-  The OUT file (audioAnalogLoopbackTest.out) for DSP will be built at
   pdk_k2g_<version>/packages/ti/addon/aud/test/analog/loopback/build/make

**For Windows:**

-  Under pdk_k2g_<version>\\packages directory, run the following
   commands:

::

      pdksetupenv.bat
      cd pdk_k2g_<version>\packages\ti\addon\aud\
      gmake clean
      gmake all

-  The OUT file (audioAnalogLoopbackTest.out) for DSP will be built at
   pdk_k2g_<version>\\packages\\ti\\addon\\aud\\test\\analog\\loopback\\build\\make

.. rubric:: How to Run the Unit Test
   :name: how-to-run-the-unit-test

The unit test works on the K2G EVM with an AUDK2G connected.

The following section provide detailed steps for K2G EVM

-  Follow this link `Processor SDK RTOS Setup CCS <index_how_to_guides.html#setup-ccs-for-evm-and-processor-sdk-rtos>`__
   to get target configuration setup correctly
-  Connect to the on board emulator (J1 on K2G EVM) to your PC USB
-  Plug power adaptor(12V) into the K2G EVM and power on the EVM
-  Launch the target configuration file using "Launch Selected
   Configuration" from CCS 6.1.3
-  Then "Connect to C66xx_DSP"
-  Load the audioAnalogLoopbackTest.out from
   pdk_k2g_<version>/packages/ti/addon/aud/test/analog/loopback/build/make
-  Run the program (loaded previously) by pressing F8
-  The program will print out the instructions on how to verify the
   loopback physically

::

      [C66xx] 
      ******************************************
            Audio DC Analog Loopback Test       
      ******************************************
      
      Test Verifies ADC and DAC Channels 0 to 3
      Test Runs in Audio Loopback Mode
      Confirm that ADC Input Audio is Played at DAC Channels 0 to 3
      
      Audio Connection Details
      **************************************
      ADC_IN 0 ==> DAC_OUT 0
      ADC_IN 1 ==> DAC_OUT 1
      ADC_IN 2 ==> DAC_OUT 2
      ADC_IN 3 ==> DAC_OUT 3
      **************************************

.. raw:: html

