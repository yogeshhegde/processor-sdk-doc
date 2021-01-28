
.. _Benchmark-Demo-User-Guide-label:

Benchmark Demo - User Guide
===========================

Overview
--------

The default application loaded on the AM64x is the Benchmark Demo. It's
purpose is to showcase the capabilities of the four R5F cores as well as
the A53 core right out of the box. One of the four R5F benchmarks will run 
on one of the 4 R5F cores. There are 4 running options available for each 
benchmark. Users can switch using the drop-down to test the AM64x and view 
it's performance. 

All of the necessary equipment requirement and instructions are provided here.

Hardware Prerequisites
----------------------

-  TI AM64x EVM

-  PC (Windows or Linux)

-  Ethernet cables

-  Ethernet switch or ethernet router with DHCP service

-  SD card (minimum 2GB) 

Get Started
-----------

1.  Follow the instructions in section
    :ref:`am64x-create-sd-card-with-default-images` to create an SD card with
    the prebuilt WIC image.

2.  Insert the SD card into the AM64x EVM

3.  Set the AM64x EVM Boot mode to "Boot from SD card"

    - SW2(1:8) on, on, off, off, off, off, on, off
    - SW3(1:8) off, on, off, off, off, off, off, off

4.  Connect an ethernet cable from your ethernet switch or router to the
    AM64x EVM

5.  Connect your PC to the same ethernet switch or router

6.  Connect the UART (J26 via USB cable) to the PC's USB port.

7. Open the the main UART0 port using the TeraTerm or other UART emulator 
    program. Set the port to 115200bps, 8 bit, no parity, 1 stop bit, no flow control

8. Power on the AM64x

9. After the Linux boot completes, login as "root", then type in "ifconfig" in 
    Linux prompt to find out the IP address for the AM64x EVM

.. Image:: /images/OOB_Linux_ifconfig.png

10. On the PC, open a Internet Browser and enter in the
    following: \ http://IP_ADDRESS_OF_AM64x_EVM:8081, for example, http://192.168.86.198:8081

11. The following web page will pop up:

.. Image:: /images/OOB_GUI_root.png

12. Click on the "Benchmark Demo": 

.. Image:: /images/OOB_GUI_stats.png

13. With the current release, the R5F app for each R5F core are fixed. User can only 
    change the "Options" for each core, then click "LOAD" to refresh the statistics 

+-------------+------------------+----------------------+-----------------------------------------------------------+
| **R5 Core** | **App Name**     |   Default Option     | **Description**                                           |
+=============+==================+======================+===========================================================+
| 0_0         | ADC and PWM Loop |      8Khz            | ADC/PWM benchmark for R5 5 ADC sample read & 1 PWM write  |
+-------------+------------------+----------------------+-----------------------------------------------------------+
| 0_1         | CFFT             |      1Khz & 128pt    | CMSIS CFFT benchmark for R5                               |
+-------------+------------------+----------------------+-----------------------------------------------------------+
| 1_0         | FIR Filtering    |      1Khz            | CMSIS FIR filtering benchmark for R5 320pt & 29-tap       |
+-------------+------------------+----------------------+-----------------------------------------------------------+
| 1_1         | FOC Loop         |      16Khz           | CMSIS FOC benchmark for R5                                |
+-------------+------------------+----------------------+-----------------------------------------------------------+

.. note:: Sometimes, you see spikes in "CPU Usage". It happens sparsely, so the average numbers are not affected. This is a known issue and we are investigating right now.

Software Architecture
---------------------

.. Image:: /images/OOB_SW_arch.png

Building Blocks
---------------

-  **User Interface:** The GUI was built by using `GUI Composer <https://dev.ti.com/gc/designer/help/GC_UserGuide_v2/index.html>`__. The
   Benchmark Demo is the second page where inputs and outputs can be
   accessed.

-  **Web Server:** The benchmark data is sent between the GUI and the
   AM64x via HTTP communication. New data are pulled from the AM64x and
   sent to the GUI every second, while data sending from the GUI to the
   AM64x is transmitted every time "Load" is clicked. The data are
   transmitted and received in JSON format.

-  **R5 and A53 Applications:**

   -  IPC RPMsg\_char library for R5: it provides a API for R5
      application to receive/send a RPMsg\_char message from/to A53

   -  CMSIS DSP library 5.6.0 compiled with TI CGT for R5

   -  CMSIS CFFT benchmark for R5: CFFT benchmark application using
      CMSIS DSP library for R5 

   -  CMSIS FIR benchmark for R5: FIR benchmark application using CMSIS
      DSP library for R5 

   -  CMSIS FOC benchmark for R5: FOC benchmark application using CMSIS
      DSP library for R5 

   -  ADC/PWM benchmark for R5: ADC/PWM loop benchmark application for
      R5 

   -  Linux application code handles the IPC RPMsg\_char and the JSON
      file update for A53 

   -  Web server code is built on Node JS

Demo Internals
--------------

Programming Paradigm
~~~~~~~~~~~~~~~~~~~~

-  The user interface of the demo is built from GUI Composer and runs on
   a PC's browser

-  The web server is built on Node JS, transmits and receives data in
   JSON format, and runs on the Linux A53 core

-  The linux app is written in C and runs on the Linux A53 core

-  Each of the CMSIS applications run on any given baremetal R5F core

   -  Applications are chosen using the Imperative Programming Paradigm
      (Procedural Programming Paradigm)

Node JS
~~~~~~~

When the AM64x boots, an initialization script executes the web server
code by calling the Node JS code. Several node packages are used to edit
the JSON file, create the demo instance, and serve up the files to the
client.

HTTP
~~~~

All data communication is handled via HTTP. Benchmark data from the
AM64x is requested by the GUI every second, whereas the option selection 
data is pushed from the GUI to the AM64x when the "Load" button is clicked. 
The HTTP requests are handled with jQuery, and the body of each HTTP request 
is a JSON string containing the input/output benchmark data.

JSON
~~~~

A JSON file has been used to exchange structured information between the
web server and the A53 Linux application (a user space application
program). It will read the user input such as the input application and
parameters used to run on the desired R5F core. On the other hand, the
A53 Linux application will also get the benchmark data from the R5 cores
and then update the JSON file accordingly. The updated JSON file
will then be displayed on the GUI every second.     

Build Linux+Baremetal Demos and Update SD card
----------------------------------------------

1. Install the Sitara SDK on a Linux machine at
   <PSDK\_PATH>

2. Change directory

::

   cd <PSDK_PATH>/sitara-apps

3. Build the demo

::

   make common_libs benchmark_demo BUILD_LINUX_APPS=1 RTOS_ONLY_BUILD=0

4. The R5 apps will be in
   <PSDK\_PATH>/apps/benchmark\_demo/out/AM64X/R5F/NO\_OS/release

5. The A53 app will be in
   <PSDK\_PATH>/apps/benchmark\_demo/webserver\_app/linux\_app/rpmsg\_json

6. Update the SD card with above newly built R5 apps and A53 app

   - Copy the R5 apps from <PSDK\_PATH>/apps/benchmark\_demo/out/AM64X/R5F/NO\_OS/release/\*.out
     to /lib/firmware/sitara-apps/sitara-benchmark-demo/ of rootfs partition on SD card

   - Copy the A53 app from <PSDK\_PATH>/apps/benchmark\_demo/webserver\_app/linux\_app/rpmsg\_json
     to /usr/bin/rpmsg\_json of rootfs partition of SD card

Build Baremetal Demos and Update SD card
----------------------------------------

1. Install the Sitara SDK on a Linux or a Windows machine at
   <PSDK\_PATH>

2. Change directory

::

   cd <PSDK_PATH>/sitara-apps

3. Build the demo

::

   make common_libs benchmark_demo BUILD_LINUX_APPS=0 RTOS_ONLY_BUILD=1   (for Linux) 
   gmake common_libs benchmark_demo BUILD_LINUX_APPS=0 RTOS_ONLY_BUILD=1  (for Windows)

4. The 3 baremetal SD card bootable files will be in
   <PSDK\_PATH>/apps/benchmark\_demo/out/AM64X/SDCardImage

5. Update the SD card with above newly built Baremetal SD card bootable files

   - Delete all files from the SD card boot partition
   - Copy the 3 baremetal SD card bootable files from
     <PSDK\_PATH>/apps/benchmark\_demo/out/AM64X/SDCardImage
     to boot partition on SD card

6. Display the benchmark statistics for baremetal only SD card boot

   - Because the baremetal only demo will not be able to display anything on 
     webserver, in order to see the benchmark statstics, CCS has to be used
   - Create a target configuration (ccxml) file with no gel file attached to DSMC core
   - Put the AM64x EVM in SD card boot mode: 
      - SW2(1:8) on, on, off, off, off, off, on, off
      - SW3(1:8) off, on, off, off, off, off, off, off
   - Boot for a baremetal only SD card, wait until the Linux boot is completed
   - Launch the target configuration file without gel file on DSMC core
   - Connect to the R5F core of interest (R5_0_0, R5_0_1, R5_1_0, or R5_1_1)
   - To examine the statistics, you will need to add gCoreStat into your Expressions. 
      - gCoreStat.output.cload.cur: the current CPU loading in percentage
      - gCoreStat.output.cload.ave: the average CPU loading in percentage
      - gCoreStat.output.cload.max: the maximum CPU loading in percentage
      - gCoreStat.output.ilate.ave: the average interrupt latency in ns
      - gCoreStat.output.ilate.max: the maximum interrupt latency in ns
      - gCoreStat.output.ccploop.ave: the average cycle count per loop
      - gCoreStat.output.ccploop.max: the maximum cycle count per loop
      - gCoreStat.output.ave_count: the number of loops has been perfomed in this benchmark 


Directory Structure
-------------------


+------+--------------------------------------------------+----------------------------------------------------------------------------------------+
|      | **Directory Name**                               | **Description**                                                                        |
+======+==================================================+========================================================================================+
| 1    | apps/common/ipc\_rpmsg\_lib                      | IPC RPMsg\_char library for R5                                                         |
+------+--------------------------------------------------+----------------------------------------------------------------------------------------+
| 2    | apps/common/libs/cmsis                           | CMSIS DSP library 5.6.0 compiled with TI CGT                                           |
+------+--------------------------------------------------+----------------------------------------------------------------------------------------+
| 3    | apps/benchmark\_demo/cmsis\_cfft                 | CMSIS CFFT benchmark for R5                                                            |
+------+--------------------------------------------------+----------------------------------------------------------------------------------------+
| 4    | apps/benchmark\_demo/cmsis\_fir                  | CMSIS FIR filtering benchmark for R5                                                   |
+------+--------------------------------------------------+----------------------------------------------------------------------------------------+
| 5    | apps/benchmark\_demo/cmsis\_foc                  | CMSIS FOC benchmark for R5                                                             |
+------+--------------------------------------------------+----------------------------------------------------------------------------------------+
| 6    | apps/benchmark\_demo/cmsis\_pid                  | CMSIS speed/position control benchmark for R5                                          |
+------+--------------------------------------------------+----------------------------------------------------------------------------------------+
| 7    | apps/benchmark\_demo/adc\_pwm                    | ADC/PWM benchmark for R5                                                               |
+------+--------------------------------------------------+----------------------------------------------------------------------------------------+
| 8    | apps/benchmark\_demo/webserver\_app/app          | GUI code and component files                                                           |
+------+--------------------------------------------------+----------------------------------------------------------------------------------------+
| 9    | apps/benchmark\_demo/webserver\_app/linux\_app   | Linux application code handles the IPC RPMsg\_char and the JSON file update for A53    |
+------+--------------------------------------------------+----------------------------------------------------------------------------------------+
| 10   | apps/benchmark\_demo/webserver\_app/webserver    | Web server and node files                                                              |
+------+--------------------------------------------------+----------------------------------------------------------------------------------------+

Benchmark Results
-----------------

R5 Benchmarks (Average)
~~~~~~~~~~~~~~~~~~~~~~~

+--------------------------------------------------------+----------------------+-------------+-------------+----------------------+
| Application                                            | Cycle Count Per Loop | CPU Usage % | RAM Usage % | Interrupt Latency ns |
+========================================================+======================+=============+=============+======================+
| CFFT (SP, 128pt) @ 1Khz*                               |         9857         |      1      |      38     |          80          |
+--------------------------------------------------------+----------------------+-------------+-------------+----------------------+
| CFFT (SP, 256pt) @ 1Khz                                |        20770         |      2      |      38     |          80          |
+--------------------------------------------------------+----------------------+-------------+-------------+----------------------+
| CFFT (SP, 512pt) @ 1Khz                                |        45421         |      5      |      38     |          80          |
+--------------------------------------------------------+----------------------+-------------+-------------+----------------------+
| CFFT (SP, 1024pt) @ 1Khz                               |       107701         |     13      |      38     |          80          |
+--------------------------------------------------------+----------------------+-------------+-------------+----------------------+
| FIR Filtering (SP, 320pt, 29 taps) @ 1Khz*             |        20169         |      2      |      28     |          80          |
+--------------------------------------------------------+----------------------+-------------+-------------+----------------------+
| FIR Filtering (SP, 320pt, 29 taps) @ 2Khz              |        20154         |      5      |      28     |          80          |
+--------------------------------------------------------+----------------------+-------------+-------------+----------------------+
| FIR Filtering (SP, 320pt, 29 taps) @ 4Khz              |        20166         |     10      |      28     |          80          |
+--------------------------------------------------------+----------------------+-------------+-------------+----------------------+
| FIR Filtering (SP, 320pt, 29 taps) @ 8Khz              |        20169         |     20      |      28     |          80          |
+--------------------------------------------------------+----------------------+-------------+-------------+----------------------+
| FOC Control Loop using CMSIS funcs @ 16Khz*            |         326          |      0      |      27     |          80          |
+--------------------------------------------------------+----------------------+-------------+-------------+----------------------+
| FOC Control Loop using CMSIS funcs @ 32Khz             |         330          |      1      |      27     |          80          |
+--------------------------------------------------------+----------------------+-------------+-------------+----------------------+
| FOC Control Loop using CMSIS funcs @ 100Khz            |         328          |      4      |      27     |          80          |
+--------------------------------------------------------+----------------------+-------------+-------------+----------------------+
| FOC Control Loop using CMSIS funcs @ 250Khz            |         290          |      9      |      27     |          80          |
+--------------------------------------------------------+----------------------+-------------+-------------+----------------------+
| 5 ADC Sampling and Conversion and 1 ePWM Write @ 8Khz* |         604          |      0      |      27     |         N/A          |
+--------------------------------------------------------+----------------------+-------------+-------------+----------------------+
| 5 ADC Sampling and Conversion and 1 ePWM Write @ 16Khz |         604          |      1      |      27     |         N/A          |
+--------------------------------------------------------+----------------------+-------------+-------------+----------------------+
| 5 ADC Sampling and Conversion and 1 ePWM Write @ 32Khz |         606          |      2      |      27     |         N/A          |
+--------------------------------------------------------+----------------------+-------------+-------------+----------------------+
| 5 ADC Sampling and Conversion and 1 ePWM Write @ 50Khz |         743          |      4      |      27     |         N/A          |
+--------------------------------------------------------+----------------------+-------------+-------------+----------------------+

.. note:: "RAM Usage %" is computed based on 320KB (64KB TCM + 256KB MSMC) per R5F core
.. note:: "CPU Usage %" is computed based on R5F core running at 800Mhz
.. note:: "*" is the default running frequencywhen the benchmark demo starts

..
  [comment] commenting out the A53 Benchmarks until we have data to put here
  [comment] A53 Benchmarks (TBD)
  [comment] ~~~~~~~~~~~~~~~~~~~~
