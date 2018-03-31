.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Image_Processing_Demo 

.. rubric:: Introduction
   :name: introduction

This page describes the image processing demo provided in the
Processor-SDK for RTOS. This demo illustrates the integration of key
components in the SDK and provides a framework for application
development.

The use case implemented is the transfer of image data from/to DDR and
internal memory. Typically, images are large and need to be stored in
external memory. Key functions include

-  Operates on different segments of the same image in different cores
-  Operates across multiple cores executing different algorithms on the
   same image data
-  Transfers input/output image to a medium (SD card or external system)
-  Utilize IPC to communicate between cores to perform an image
   processing task parallel

This demo utilizes many SDK features/components:

-  **Multi-core** application utilizing ARM-A15 and DSP-C66x cores
-  **IMGLIB** for optimized C66x image processing
-  **IPC** for interprocessor communication
-  **NDK** application utilizing NDK for internet access
-  **UIA** for instrumentation logging

This demo is not available for all devices. Currently, the following
devices and EVM are supported:

-  AM57x, on the AM572x GP EVM
-  C665x, on the C665x EVM
-  C667x, on the C667x EVM
-  K2H, on the K2H EVM

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
Before running image demo for AM572x and K2H platforms on arm and c66x
core , we need to increase stack size in netctrl.c file from 2048 to
4096 and rebuild the NDK library and driver, otherwise the demo fails

.. raw:: html

   </div>

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
This demo has been only verified with the Microsoft Internet Explorer

.. raw:: html

   </div>

.. rubric:: Requirements
   :name: requirements

The following materials are required to run this demonstration:

Hardware

-  TI EVM (see list above)
-  Local Area Network with DHCP support
-  JTAG Emulator (on board or external)

Software

-  Processor-SDK RTOS
-  Code Composer Studio

| 

.. rubric:: Software Design
   :name: software-design

.. rubric:: More about processing algorithms
   :name: more-about-processing-algorithms

The application will use IMGLIB APIs for its core image processing
needs. The following steps are performed for edge detection:

-  Split input image into multiple overlapping slices
-  If it is a RGB image, separate out the Luma component (Y) for
   processing (See `YCbCr <http://en.wikipedia.org/wiki/Ycbcr>`__ for
   further details)
-  Run `Sobel operator <http://en.wikipedia.org/wiki/Sobel_operator>`__
   (IMG_sobel_3x3_8) to get the gradient image of each slices
-  Run the thresholding operation ( IMG_thr_le2min_8) on the slices to
   get the edges
-  Combine the slices to get the final output

.. rubric:: Framework for multicore
   :name: framework-for-multicore

The current framework for multicore is IPC (Message Queue). The
following are the overall steps (the master and threads will be run on
one or more cores):

-  The master thread will preprocess the input image to make a gray
   scale or luma image
-  The master thread signal each slave thread to start processing and
   wait for processing complete signal from all slave threads
-  The slave threads run edge detection function to generate output edge
   image of the slice
-  Then the slave threads signal master thread indicating the processing
   completed
-  Once master thread receives completion signal from all threads it
   proceeds with further user interface processing

| 

.. rubric:: How to Build the Demo
   :name: how-to-build-the-demo

.. rubric:: AM572x GP EVM
   :name: am572x-gp-evm

**For Linux:**

-  Under ~/ti/processor_sdk_rtos_am57xx_3_01_xx_xx directory, run the
   following commands:

::

      source ./setupenv.sh
      make demo_clean
      make demo
      the OUT files for A15, DSP1 and DSP2 will be built at 
         ~/ti/processor_sdk_rtos_am57xx_3_01_xx_xx/demos/image_processing/ipc/evmam572x/host/build,
         ~/ti/processor_sdk_rtos_am57xx_3_01_xx_xx/demos/image_processing/ipc/evmam572x/dsp1/build, and
         ~/ti/processor_sdk_rtos_am57xx_3_01_xx_xx/demos/image_processing/ipc/evmam572x/dsp2/build respectively

**For Windows:**

-  Under C:\ti\processor_sdk_rtos_am57xx_3_01_xx_xx directory, run the
   following commands:

::

      setupenv.bat
      gmake demo_clean
      gmake demo
      the OUT files for A15, DSP1 and DSP2 will be built at 
         C:\ti\processor_sdk_rtos_am57xx_3_01_xx_xx\demos\image_processing\ipc\evmam572x\host\build,
         C:\ti\processor_sdk_rtos_am57xx_3_01_xx_xx\demos\image_processing\ipc\evmam572x\dsp1\build, and
         C:\ti\processor_sdk_rtos_am57xx_3_01_xx_xx\demos\image_processing\ipc\evmam572x\dsp2\build respectively

.. rubric:: C6657 EVM
   :name: c6657-evm

**For Linux:**

-  Under ~/ti/processor_sdk_rtos_c665x_3_01_xx_xx directory, run the
   following commands:

::

      source ./setupenv.sh
      make demo_clean
      make demo
      the OUT files for DSPs will be built at 
         ~/ti/processor_sdk_rtos_c665x_3_01_xx_xx/demos/image_processing/ipc/evmc6657l/master/build,
         ~/ti/processor_sdk_rtos_c665x_3_01_xx_xx/demos/image_processing/ipc/evmc6657l/slave/build respectively

**For Windows:**

-  Under C:\ti\processor_sdk_rtos_c665x_3_01_xx_xx directory, run the
   following commands:

::

      setupenv.bat
      gmake demo_clean
      gmake demo
      the OUT files for DSPs will be built at 
         C:\ti\processor_sdk_rtos_c665x_3_01_xx_xx\demos\image_processing\ipc\evmc6657l\master\build,
         C:\ti\processor_sdk_rtos_c665x_3_01_xx_xx\demos\image_processing\ipc\evmc6657l\slave\build respectively

.. rubric:: C6678 EVM
   :name: c6678-evm

**For Linux:**

-  Under ~/ti/processor_sdk_rtos_c667x_3_01_xx_xx directory, run the
   following commands:

::

      source ./setupenv.sh
      make demo_clean
      make demo
      the OUT files for DSPs will be built at 
         ~/ti/processor_sdk_rtos_c667x_3_01_xx_xx/demos/image_processing/ipc/evmc6678l/master/build,
         ~/ti/processor_sdk_rtos_c667x_3_01_xx_xx/demos/image_processing/ipc/evmc6678l/slave/build respectively

**For Windows:**

-  Under C:\ti\processor_sdk_rtos_c667x_3_01_xx_xx directory, run the
   following commands:

::

      setupenv.bat
      gmake demo_clean
      gmake demo
      the OUT files for DSPs will be built at 
         C:\ti\processor_sdk_rtos_c667x_3_01_xx_xx\demos\image_processing\ipc\evmc6678l\master\build,
         C:\ti\processor_sdk_rtos_c667x_3_01_xx_xx\demos\image_processing\ipc\evmc6678l\slave\build respectively

.. rubric:: K2H EVM
   :name: k2h-evm

**For Linux:**

-  Under ~/ti/processor_sdk_rtos_k2hk_3_01_xx_xx directory, run the
   following commands:

::

      source ./setupenv.sh
      make demo_clean
      make demo
      the OUT files for A15, DSPs will be built at 
         ~/ti/processor_sdk_rtos_k2hk_3_01_xx_xx/demos/image_processing/ipc/evmk2hk/master/build,
         ~/ti/processor_sdk_rtos_k2hk_3_01_xx_xx/demos/image_processing/ipc/evmk2hk/slave/build respectively

**For Windows:**

-  Under C:\ti\processor_sdk_rtos_k2hk_3_01_xx_xx directory, run the
   following commands:

::

      setupenv.bat
      gmake demo_clean
      gmake demo
      the OUT files for A15, DSPs will be built at 
         C:\ti\processor_sdk_rtos_k2hk_3_01_xx_xx\demos\image_processing\ipc\evmk2hk\master\build,
         C:\ti\processor_sdk_rtos_k2hk_3_01_xx_xx\demos\image_processing\ipc\evmk2hk\slave\build respectively

| 

.. rubric:: How to Run the Demo
   :name: how-to-run-the-demo

.. rubric:: AM572x GP EVM (Using CCS)
   :name: am572x-gp-evm-using-ccs

The CCS is used to load the program and run on ARM-A15 (HOST), C66x Core
1 (DSP1) and C66x Core 2 (DSP2) by following the steps below:

-  Launch CCS and connect to AM572 GP EVM using proper target
   configuration
-  Connect to CortexA15_0 (Host) [Push "Power" button right before
   connect to CortexA15_0]

.. Image:: ../images/Am572x_connect_a15.jpg

-  Connect to C66xx_DSP1

.. Image:: ../images/Am572x_connect_dsp1.jpg

-  Connect to C66xx_DSP2

.. Image:: ../images/Am572x_connect_dsp2.jpg

-  Load image_processing_evmam572x_dsp1.out to C66xx_DSP1 using JTAG

.. Image:: ../images/Am572x_load_dsp1.jpg

-  Run image_processing_evmam572x_dsp1.out on C66xx_DSP1
-  Load image_processing_evmam572x_dsp2.out to C66xx_DSP2 using JTAG

.. Image:: ../images/Am572x_load_dsp2.jpg

-  Run image_processing_evmam572x_dsp2.out on C66xx_DSP2
-  Loaded image_processing_evmam572x_host.out to CortexA15_0

.. Image:: ../images/Am572x_load_host.jpg

-  Run image_processing_evmc6678l_master.out on CortexA15_0
-  The HOST will display the IP address on CCS CIO

.. Image:: ../images/Am572x_cio.jpg

-  Users can use internet browser to access this IP address
-  The Image Processing Demo page will be displayed
-  Provide values for the "Number of Cores" and "Select Image to
   Process" fields

.. Image:: ../images/Am572x_web_1.jpg

The HOST will read the image via NDK, partition it according to the
number of cores, send the messages to DSP cores (Slaves) via IPC
MessageQ. The DSP cores will start processing the partitioned images
concurrently. The resulting output image will be stored in DDR and the
HOST will be notified by DSP cores via IPC MessageQ. Subsequently, the
HOST will write the input and output images to the Image Processing Demo
page using NDK.

.. Image:: ../images/Am572x_web_2.jpg

| 

.. rubric:: AM572x GP EVM (Using SBL)
   :name: am572x-gp-evm-using-sbl

The SBL is used to load the program from SD card and run on ARM-A15
(HOST), C66x Core 1 (DSP1) and C66x Core 2 (DSP2) by following the steps
below:

-  Copy "app" and "MLO" from
   processor_sdk_rtos_am57xx_3_0x_00_0x\prebuilt-sdcards\evmAM572x\sd_card_files
   on Windows or
   processor_sdk_rtos_am57xx_3_0x_00_0x/prebuilt-sdcards/evmAM572x/sd_card_files
   on Linux to the root directory of a formatted micro SD card
-  Plug in the micro SD card into uSD slot on AM572x GP EVM
-  Connect "Serial Debug" on AM572x GP EVM to a PC USB port via a
   "Serial to USB" cable
-  Launch a terminal emulator like Tera Term and open the local COM port
   corresponding to the "Serial Debug" (Set it to 115200 bps, 8 bit,
   none parity, one bit stop, no flow control)
-  Plug power adapter (12V) into the AM572x GP EVM (DC-In) and power on
   the EVM
-  There the IP address will be displayed on the "Serial Debug"
-  Users can use internet browser to access this IP address
-  The Image Processing Demo page will be displayed
-  Provide values for the "Number of Cores" and "Select Image to
   Process" fields

.. Image:: ../images/Am572x_web_1.jpg

The HOST will read the image via NDK, partition it according to the
number of cores, send the messages to DSP cores (Slaves) via IPC
MessageQ. The DSP cores will start processing the partitioned images
concurrently. The resulting output image will be stored in DDR and the
HOST will be notified by DSP cores via IPC MessageQ. Subsequently, the
HOST will write the input and output images to the Image Processing Demo
page using NDK.

.. Image:: ../images/Am572x_web_2.jpg

.. rubric:: C6678 EVM or C6657 EVM
   :name: c6678-evm-or-c6657-evm

CCS is used to load the program and Core 0 will be configured as the
host. The following steps show C667x but a similar process applies for
C665x.

-  Launch CCS and connect to C6678 EVM using proper target configuration
-  Connect to C66x Core 0 (Host)

.. Image:: ../images/C6678_connect_core0.jpg

-  Loaded image_processing_evmc6678l_master.out to C66x Core 0

.. Image:: ../images/C6678_load_master.jpg

-  Run image_processing_evmc6678l_master.out on C66xx_0
-  Group C66x Core 1-N into a group (Group 1, Slave)
-  Connect to Group 1

.. Image:: ../images/C6678_connect_group1.jpg

-  Load image_processing_evmc6678l_slave.out to Group 1 using JTAG

.. Image:: ../images/C6678_load_slave.jpg

-  Run image_processing_evmc6678l_slave.out on Group 1
-  The HOST will display the IP address on CCS CIO

.. Image:: ../images/C6678_cio.jpg

-  Users can use internet browser to access this IP address
-  The Image Processing Demo page will be displayed
-  Provide values for the "Number of Cores" and "Select Image to
   Process" fields

.. Image:: ../images/Demo_web_page_1.jpg

The HOST will read the image via NDK, partition it according to the
number of cores, send the messages to DSP cores (Slaves) via IPC
MessageQ. The DSP cores will start processing the partitioned images
concurrently. The resulting output image will be stored in DDR and the
HOST will be notified by DSP cores via IPC MessageQ. Subsequently, the
HOST will write the input and output images to the Image Processing Demo
page using NDK.

.. Image:: ../images/Demo_web_page_2.jpg

.. rubric:: K2H EVM
   :name: k2h-evm-1

CCS is used to load the program and arm_A15_0 will be configured as the
master and C66xx_0 - C66xx_7 will be configured as slaves.

-  Launch CCS and connect to K2H EVM using proper target configuration
-  Connect to arm_A15_0 (Host)

.. Image:: ../images/K2h_connect_a15.jpg

-  Group C66xx_0 to C66xx_7 into a group (Group 1, Slaves)

.. Image:: ../images/K2h_from_group1.jpg

-  Connect to Group 1

.. Image:: ../images/K2h_connect_group1.jpg

-  Load image_processing_evmk2hk_slave.out to Group 1 using JTAG

.. Image:: ../images/K2h_load_group1.jpg

-  Run image_processing_evmk2hk_slave.out on Group 1

.. Image:: ../images/K2h_run_group1.jpg

-  Loaded image_processing_evmk2hk_master_arm.out to arm_A15_0

.. Image:: ../images/K2h_load_a15.jpg

-  Run image_processing_evmk2hk_master_arm.out on arm_A15_0

.. Image:: ../images/K2h_run_a15.jpg

-  The HOST will display the IP address on CCS CIO

.. Image:: ../images/K2h_cio.jpg

-  Users can use internet browser to access this IP address
-  The Image Processing Demo page will be displayed
-  Provide values for the "Number of Cores" and "Select Image to
   Process" fields

.. Image:: ../images/K2h_web_1.jpg

The HOST will read the image via NDK, partition it according to the
number of cores, send the messages to DSP cores (Slaves) via IPC
MessageQ. The DSP cores will start processing the partitioned images
concurrently. The resulting output image will be stored in DDR and the
HOST will be notified by DSP cores via IPC MessageQ. Subsequently, the
HOST will write the input and output images to the Image Processing Demo
page using NDK.

.. Image:: ../images/K2h_web_2.jpg

.. raw:: html

