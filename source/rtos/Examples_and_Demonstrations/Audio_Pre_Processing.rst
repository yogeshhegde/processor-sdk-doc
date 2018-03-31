.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Audio_Pre-Processing 

.. rubric:: Introduction
   :name: introduction

This page describes the audio pre-processing for speech recognition
framework provided in the Processor-SDK for RTOS. This demo illustrates
the integration of Beamforming (BF), Adaptive Spectral Noise Reduction
(ASNR), Multiple Source Selection (MSS) and Dynamic Range Compression
(DRC) components and provides a framework for application development.

.. Image:: ../images/Aud_pre_processing_arch.png

The key functions in this use case include:

-  Read 7 canned audio input files from hard drive into buffers in DDR
   using GEL function
-  Generate 12 virtual mics using BF (Beamforming) (30° apart)
-  Apply ASNR (Adaptive Spectral Noise Reduction) on each virtual mic
-  Use MSS (Multiple Source Selection) to select the best virtual mic
   from the 12 virtual mics
-  Do DRC (Dynamic Range Compression) on the best virtual mic
-  Display performance data
-  Write one processed audio channel from buffer in DDR to hard drive
   using GEL function

This demo utilizes other Processor SDK features/components:

-  **SYS/BIOS** application utilizing TI-RTOS features for
   DSP-C66x/C674x core
-  **UIA** for instrumentation logging

The audio components are available in AER and VOLIB packages, which are
optimized for C66x cores, so this demo not available for all devices.
Currently, the following devices and EVMs are supported:

-  AM57x, on the AM572x GP EVM
-  K2G, on the K2G EVM. See TIDEP-0088
   (http://www.ti.com/tool/TIDEP-0088) for details
-  OMAP-L137, on the OMAP-L137 EVM. See TIDEP-0099
   (http://www.ti.com/tool/TIDEP-0099) for details

| 

.. rubric:: Requirements
   :name: requirements

The following materials are required to run this demonstration:

Hardware

-  TI EVMs (see list above)
-  CMB for K2G and OMAP-L137, if using circular microphone
-  Blackhawk USB560 JTAG Emulator (BH-USB-560m)

Software

-  Processor-SDK RTOS (4.0 or greater)
-  Code Composer Studio
-  AER 17.0.0.0 (C64P) (http://www.ti.com/tool/telecomlib)
-  VOLIB 2.1.0.1(C64P for OMAP-L137, C66 for K2G and AM572x)
   (http://www.ti.com/tool/telecomlib)

| 

.. rubric:: Software Design
   :name: software-design

.. rubric:: More about processing algorithms
   :name: more-about-processing-algorithms

The application will use AER & VOLIB APIs for its noise reduction
processing needs. The following steps are performed for noise reduction:

-  Use 7 canned audio inputs to generate 12 virtual mics using
   BF(Beamforming) (30° apart)
-  Apply ASNR(Adaptive Spectral Noise Reduction) on each virtual mic
-  Use MSS(Multiple Source Selection)to select the best virtual mic from
   the 12 virtual mics
-  Do VAD(Voice Activity Detection) on the best virtual mic
-  Write 1 processed audio channel into the buffer in DDR

.. rubric:: Framework for Audio Pre-processing
   :name: framework-for-audio-pre-processing

The current framework is based on SYS/BIOS. The following are the
overall steps:

-  The CLK object in SYS/BIOS will be configured to generate a Software
   Interrupt(SWI) every 10 ms
-  The SWI will prepare the audio frame buffer pointers for further
   processing
-  The SWI will also send a semaphore to wake up the main thread
-  When woke up, the main thread will perform the BF, ASNR, MSS and DRC
-  The main thread will also output the final processing audio frame to
   the DDR
-  After completed the audio frame processing, the main thread will wait
   on semaphore for next audio frames to come

| 

.. rubric:: File Based Demo
   :name: file-based-demo

.. rubric:: How to Build the Demo
   :name: how-to-build-the-demo

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
In order to make the following build procedure to work, AER and VOLIB
have to be installed at the same location as the Processor SDK RTOS
4.x.x

.. raw:: html

   </div>

.. rubric:: AM572x GP EVM
   :name: am572x-gp-evm

**For Linux:**

-  Under processor_sdk_rtos_am57xx_4_xx_xx_xx directory, run the
   following commands:

::

      source ./setupenv.sh
      cd demos/audio-preprocessing/file_demo_bios/am572x/build
      make clean
      make all
      the OUT files for DSP1 will be built at 
         processor_sdk_rtos_am57xx_4_xx_xx_xx/demos/audio-preprocessing/file_demo_bios/am572x/build

**For Windows:**

-  Under processor_sdk_rtos_am57xx_4_00_xx_xx directory, run the
   following commands:

::

      setupenv.bat
      cd demos\audio-preprocessing\file_demo_bios\am572x\build
      gmake clean
      gmake all
      the OUT files for DSP1 will be built at 
         processor_sdk_rtos_am57xx_4_xx_xx_xx\demos\audio-preprocessing\file_demo_bios\am572x\build

.. rubric:: K2G EVM
   :name: k2g-evm

**For Linux:**

-  Under processor_sdk_rtos_k2g_4_xx_xx_xx directory, run the following
   commands:

::

      source ./setupenv.sh
      cd demos/audio-preprocessing/file_demo_bios/k2g/build
      make clean
      make all
      the OUT files for DSP will be built at 
         processor_sdk_rtos_k2g_4_xx_xx_xx/demos/audio-preprocessing/file_demo_bios/k2g/build

**For Windows:**

-  Under processor_sdk_rtos_k2g_4_00_xx_xx directory, run the following
   commands:

::

      setupenv.bat
      cd demos\audio-preprocessing\file_demo_bios\k2g\build
      gmake clean
      gmake all
      the OUT files for DSP will be built at 
         processor_sdk_rtos_k2g_4_xx_xx_xx\demos\audio-preprocessing\file_demo_bios\k2g\build

.. rubric:: OMAP-L137 EVM
   :name: omap-l137-evm

**For Linux:**

-  Under processor_sdk_rtos_omapl137_4_xx_xx_xx directory, run the
   following commands:

::

      source ./setupenv.sh
      cd demos/audio-preprocessing/file_demo_bios/omapl137/build
      make clean
      make all
      the OUT files for DSP will be built at 
         processor_sdk_rtos_omapl137_4_xx_xx_xx/demos/audio-preprocessing/file_demo_bios/omapl137/build

**For Windows:**

-  Under processor_sdk_rtos_omapl137_4_xx_xx_xx directory, run the
   following commands:

::

      setupenv.bat
      cd demos\audio-preprocessing\file_demo_bios\omapl137\build
      gmake clean
      gmake all
      the OUT files for DSP will be built at 
         processor_sdk_rtos_omapl137_4_xx_xx_xx\demos\audio-preprocessing\file_demo_bios\omapl137\build

.. rubric:: How to Run the Demo
   :name: how-to-run-the-demo

The demo along with the audio input files will be loaded onto the target
using JTAG. After executing, the output file can be read from target.
Play both input and output audio files to compare effect of audio
pre-processing.

The following sections provide detailed steps for each EVM.

.. rubric:: AM572x GP EVM
   :name: am572x-gp-evm-1

-  Follow this link
   (http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Setup_CCS)
   to get target configuration setup correctly.
-  Then in CCS tools --> Gel file to load the modified gel file --
   audio-preprocessing/file_demo_bios/am572x/files_io_7.gel
-  Connect the Blackhawk USB 560M JTAG to P4 on AM572x GP EVM
-  Plug power adaptor(12V) into the AM572x GP EVM (Do not press the
   Power Button(S1) yet)
-  Launch the target configuration created in step 1 using "Launch
   Selected Configuration" from CCS 6.1.3
-  Press the Power Button(S1) and "Connect to CortexA15_0" immediately
   (Due to the EVM will be auto power off in 10 secs)
-  Then "Connect to C66xx_DSP1"
-  Load the AM572x_bf.out from
   audio-preprocessing\file_demo_bios\am572x\build
-  Execute GEL function Scripts-->Microphone Load
   Functions-->BFMicLoadAll to load all 7 microphone input files
   (audio-preprocessing\common\t8\y16L7g3m7090_x.pcm) into external
   memory buffers
-  Run the program (loaded previously) by pressing F8
-  The program will print out the statistics and “EOF reached” when the
   program completes processing
-  Execute GEL function Scripts-->Microphone Save
   Functions-->BFSaveOutput to save the processed audio output from
   external memory buffer to a file
   (audio-preprocessing\common\t8\fileOutput7.bin)

.. rubric:: K2G EVM
   :name: k2g-evm-1

-  Follow this link
   (http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Setup_CCS)
   to get target configuration setup correctly.
-  Then in CCS tools --> Gel file to load the modified gel file --
   audio-preprocessing/file_demo_bios/k2g/files_io_7.gel
-  Connect to the on board emulator (J1 on K2G EVM) to your PC USB
-  Plug power adaptor(12V) into the K2G EVM and power on the EVM
-  Launch the target configuration created in step 1 using "Launch
   Selected Configuration" from CCS 6.1.3
-  Then "Connect to C66xx_DSP"
-  Load the K2G_bf.out from audio-preprocessing\file_demo_bios\k2g\build
-  Execute GEL function Scripts-->Microphone Load
   Functions-->BFMicLoadAll to load all 7 microphone input files
   ((audio-preprocessing\common\t8\y16L7g3m7090_x.pcm)) into external
   memory buffers
-  Run the program (loaded previously) by pressing F8
-  The program will print out the statistics and “EOF reached” when the
   program completes processing
-  Execute GEL function Scripts-->Microphone Save
   Functions-->BFSaveOutput to save the processed audio output from
   external memory buffer to a file
   (audio-preprocessing\common\t8\fileOutput7.bin)

.. rubric:: OMAP-L137 EVM
   :name: omap-l137-evm-1

-  Follow this link
   (http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Setup_CCS)
   to get target configuration setup correctly.
-  Then in CCS tools --> Gel file to load the modified gel file --
   audio-preprocessing/file_demo_bios/k2g/files_io_7.gel
-  Connect to the on board emulator (J201 on OMAP-L137 EVM) to your PC
   USB
-  Plug power adaptor(5V) into the OMAP-L137 EVM and power on the EVM
-  Launch the target configuration created in step 1 using "Launch
   Selected Configuration" from CCS 6.1.3
-  Then "Connect to C674x_0"
-  Load the DA830_bf.out from
   audio-preprocessing\file_demo_bios\omapl137\build
-  Execute GEL function Scripts-->Microphone Load
   Functions-->BFMicLoadAll to load all 7 microphone input files
   ((audio-preprocessing\common\t8\y16L7g3m7090_x.pcm)) into external
   memory buffers
-  Run the program (loaded previously) by pressing F8
-  The program will print out the statistics and “EOF reached” when the
   program completes processing
-  Execute GEL function Scripts-->Microphone Save
   Functions-->BFSaveOutput to save the processed audio output from
   external memory buffer to a file
   (audio-preprocessing\common\t8\fileOutput7.bin)

| 

| 

.. rubric:: Circular Microphone Board Demo
   :name: circular-microphone-board-demo

.. rubric:: How to Build the Demo
   :name: how-to-build-the-demo-1

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
In order to make the following build procedure to work, AER and VOLIB
have to be installed at the same location as the Processor SDK RTOS
4.x.x

.. raw:: html

   </div>

.. rubric:: K2G EVM
   :name: k2g-evm-2

**For Linux:**

-  Under processor_sdk_rtos_k2g_4_xx_xx_xx directory, run the following
   commands:

::

      source ./setupenv.sh
      cd demos/audio-preprocessing/realtime_demo_bios/k2g/build
      make clean
      make all
      the OUT files for DSP will be built at 
         processor_sdk_rtos_k2g_4_xx_xx_xx/demos/audio-preprocessing/realtime_demo_bios/k2g/build

**For Windows:**

-  Under processor_sdk_rtos_k2g_4_00_xx_xx directory, run the following
   commands:

::

      setupenv.bat
      cd demos\audio-preprocessing\realtime_demo_bios\k2g\build
      gmake clean
      gmake all
      the OUT files for DSP will be built at 
         processor_sdk_rtos_k2g_4_xx_xx_xx\demos\audio-preprocessing\realtime_demo_bios\k2g\build

.. rubric:: OMAP-L137 EVM
   :name: omap-l137-evm-2

**For Linux:**

-  Under processor_sdk_rtos_omapl137_4_xx_xx_xx directory, run the
   following commands:

::

      source ./setupenv.sh
      cd demos/audio-preprocessing/realtime_demo_bios/omapl137/build
      make clean
      make all
      the OUT files for DSP will be built at 
         processor_sdk_rtos_omapl137_4_xx_xx_xx/demos/audio-preprocessing/realtime_demo_bios/omapl137/make

**For Windows:**

-  Under processor_sdk_rtos_omapl137_4_00_xx_xx directory, run the
   following commands:

::

      setupenv.bat
      cd demos\audio-preprocessing\realtime_demo_bios\omapl137\make
      gmake clean
      gmake all
      the OUT files for DSP will be built at 
         processor_sdk_rtos_omapl137_4_xx_xx_xx\demos\audio-preprocessing\realtime_demo_bios\omapl137\make

.. rubric:: How to Run the Demo
   :name: how-to-run-the-demo-1

The demo works with the real time audio input from CMB. After processing
is complete, the audio output will be sent to the line-out(left channel)
of the K2G EVM on-board audio codec. For the purpose of comparison, the
unprocessed center microphone (mic 8) will be sent out to the line-out
(right channel) of the K2G EVM on-board audio codec.

The following sections provide detailed steps for each EVM.

.. rubric:: K2G EVM (using CCS)
   :name: k2g-evm-using-ccs

-  Follow this link
   (http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Setup_CCS)
   to get target configuration setup correctly.
-  Connect to the on board emulator (J1 on K2G EVM) to your PC USB
-  Plug power adaptor(12V) into the K2G EVM and power on the EVM
-  Launch the target configuration created in step 1 using "Launch
   Selected Configuration" from CCS 6.1.3
-  Then "Connect to C66xx_DSP"
-  Load the K2G_bf_rt.out from
   audio-preprocessing\realtime_demo_bios\k2g\build
-  Run the program (loaded previously) by pressing F8
-  The program will run the real time demo forever, taking the input
   from CMB and output to the on-board line-out

.. rubric:: OMAP-L137 EVM (using CCS)
   :name: omap-l137-evm-using-ccs

-  Follow this link
   (http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Setup_CCS)
   to get target configuration setup correctly.
-  Connect to the on board emulator (J201 on OMAP-L137 EVM) to your PC
   USB
-  Plug power adaptor(5V) into the OMAP-L137 EVM and power on the EVM
-  Launch the target configuration created in step 1 using "Launch
   Selected Configuration" from CCS 6.1.3
-  Then "Connect to C674X_0"
-  Load the OMAPL137_bf_rt.out from
   audio-preprocessing\realtime_demo_bios\omapl137\make
-  Run the program (loaded previously) by pressing F8
-  The program will run the real time demo forever, taking the input
   from CMB and output to the on-board line-out

.. rubric:: K2G EVM (Boot from SD card)
   :name: k2g-evm-boot-from-sd-card

-  Copy "app" and "MLO" from
   audio-preprocessing\realtime_demo_bios\k2g\pre-built\mmcsd on Windows
   or audio-preprocessing/realtime_demo_bios/k2g/pre-built/mmcsd on
   Linux to the root directory of a formatted micro SD card
-  Plug in the micro SD card into uSD Card slot on K2G EVM
-  Connect "USB TO SOC UART0" on K2G EVM to a PC USB port via USB cable
-  Launch a terminal emulator like Tera Term and open the local COM port
   corresponding to the UART0 (Set it to 115200 bps, 8 bit, none parity,
   one bit stop, no flow control)
-  Plug power adapter (12V) into the K2G EVM and power on the EVM and
   Power on the K2G EVM
-  There will be some information displayed on the SOC UART0
-  The program will run the real time demo forever, taking the input
   from CMB and output to the on-board line-out

| 

.. rubric:: How to Read the Input/output Audio Files
   :name: how-to-read-the-inputoutput-audio-files

Both the input/output audio files are in raw PCM format (*.pcm or
\*.bin) 16 bit per sample, big endian, mono, at 16Khz. They can be
imported either by Adobe Audition or Audacity as the raw audio data.

.. rubric:: Import Raw Audio Data File using Adobe Audition
   :name: import-raw-audio-data-file-using-adobe-audition

-  Launch the Adobe Audition CS5.5
-  File --> Import --> Raw Data...
-  The following dialog will pop up

.. Image:: ../images/Aud_pre_processing_import.png

-  Select the raw audio file and input the correct parameters
-  Click OK

.. rubric:: Before and After Comparison
   :name: before-and-after-comparison

-  Before audio pre-processing (t8/y16L7g3m7090_1.pcm)

.. Image:: ../images/Aud_pre_processing_before.png

-  After audio pre-processing (t8/fileOutput.bin)

.. Image:: ../images/Aud_pre_processing_after.png

| 

.. raw:: html

