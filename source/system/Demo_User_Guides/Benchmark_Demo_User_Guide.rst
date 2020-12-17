
.. _Benchmark-Demo-User-Guide-label:

Benchmark Demo - User Guide
================================

Overview
--------

The default application loaded on the AM64x is the Benchmark Demo. It's
purpose is to showcase the capabilities of the four R5F cores as well as
the A53 core right out of the box. Several different applications and
options are available for loading onto the onboard cores in order to
test the AM64x and view it's performance. All of the necessary equipment
and instructions are provided below in order to get started with the
demo.

Hardware Prerequisites
----------------------

-  TI AM64x EVM

-  PC (Windows or Linux)

-  Ethernet cables

-  Ethernet switch or ethernet router with DHCP service

-  SD card (minimum 8GB) 

Get Started
-----------

1.  Install the AM64x Processor SDK on a Linux or a Windows machine at
    <PSDK\_PATH>

2.  The prebuilt SD card image (WIC file) is available
    at <PSDK\_PATH>/linux/filesystem/sitara-rootfs-image-am64x-evm.wic.xz

3.  unzip the sitara-rootfs-image-am64x-evm.wic.xz to
    sitara-rootfs-image-am64x-evm.wic

4.  Flash the WIC to SD card

    - For Windows, using Win32DiskImager

    - For Linux,

::

    sudo dd bs=4M if=./sitara-rootfs-image-am64x-evm.wic of=/dev/sdx status=progress && sync

5.  Insert the SD card into the AM64x EVM

6.  Set the Boot mode to "Boot from SD card"

7.  Connect an ethernet cable from your ethernet switch or router to the
    AM64x EVM

8.  Connect your PC to the same ethernet switch or router

9.  Connect the UART (via USB cable) to the PC's USB port.

10. Open the the main UART0 port using the TeraTerm or other UART
    emulator program. Set the port to 112Kbps, 8 bit, no parity, no flow
    control

11. Power on the AM64x

12. After the Linux boot completes, type in "ifconfig" in Linux prompt
    to find out the IP address for the AM64x EVM

13. On the PC, open a Internet Browser and enter in the
    following: \ http://IP_ADDRESS_OF_AM64x_EVM:8081, for example, http://192.168.1.100:8081

14. The following web page will pop up:

.. Image:: /images/OOB_GUI_root.png

15. Click on the "Benchmark Demo": 

.. Image:: /images/OOB_GUI_stats.png

16. User can change the "Application" and "Options" for each core, then
    click "LOAD" to refresh the statistics 

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

-  **AM64x Display:** When the AM64x is connected to the network, the
   onboard display will show the designated web address to access the
   Benchmark Demo. If an error occurs on the AM64x while running the
   demo, it will be displayed here.

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

   -  CMSIS PID benchmark for R5: Speed/position loop benchmark
      application using CMSIS DSP library for R5

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
AM64x is requested by the GUI every second, whereas the application and
option selection data is pushed from the GUI to the AM64x when the
"Load" button is clicked. The HTTP requests are handled with jQuery, and
the body of each HTTP request is a JSON string containing the
input/output benchmark data.

JSON
~~~~

A JSON file has been used to exchange structured information between the
web server and the A53 Linux application (a user space application
program). It will read the user input such as the input application and
parameters used to run on the desired R5F core. On the other hand, the
A53 Linux application will also get the benchmark data from the R5 cores
and then update the JSON file accordingly. The updated JSON file
will then be displayed on the GUI every second.     

Build Demos and Update SD card
------------------------------

1. Install the Sitara SDK on a Linux or a Windows machine at
   <PSDK\_PATH>

2. Change directory

::

   cd <PSDK_PATH>

3. Build the demo

::

   make all (for Linux) or gmake all (for Windows)

4. The R5 apps will be in
   <PSDK\_PATH>/apps/benchmark\_demo/out/AM64X/R5F/NO\_OS/release

5. The A53 app will be in
   <PSDK\_PATH>/apps/benchmark\_demo/webserver\_app/linux\_app/rpmsg\_json

6. Update the SD card with above newly built R5 apps and A53 app

   - Copy the R5 apps from
      <PSDK\_PATH>/apps/benchmark\_demo/out/AM64X/R5F/NO\_OS/release/\*.out
      to /lib/firmware/sitara-apps/sitara-benchmark-demo/ of rootfs
      partition on SD card

   - Copy the A53 app
      from <PSDK\_PATH>/apps/benchmark\_demo/webserver\_app/linux\_app/rpmsg\_json
      to /usr/bin/rpmsg\_json of rootfs partition of SD card

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

R5 Benchmarks
~~~~~~~~~~~~~

+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| Application                                                | Cycle Count Per Loop   | CPU Usage %   | RAM Usage %   | Interrupt   Latency ns   |
+============================================================+========================+===============+===============+==========================+
| CFFT (SP, 128pt) @ 1Khz                                    |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| CFFT (SP, 256pt) @ 1Khz                                    |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| CFFT (SP, 512pt) @ 1Khz                                    |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| CFFT (SP, 1024pt) @ 1Khz                                   |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| FIR Filtering (SP, 320pt, 29   taps) @ 1Khz                |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| FIR Filtering (SP, 320pt, 29   taps) @ 2Khz                |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| FIR Filtering (SP, 320pt, 29   taps) @ 4Khz                |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| FIR Filtering (SP, 320pt, 29   taps) @ 8Khz                |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| FOC Control Loop using CMSIS   funcs @ 8Khz                |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| FOC Control Loop using CMSIS funcs @ 16Khz                 |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| FOC Control Loop using CMSIS   funcs @ 32Khz               |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| FOC Control Loop using CMSIS   funcs @ 50Khz               |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| Speed/Position Control Loop   using CMSIS funcs @ 8Khz     |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| Speed/Position Control Loop using CMSIS funcs @ 16Khz      |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| Speed/Position Control Loop   using CMSIS funcs @ 32Khz    |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| Speed/Position Control Loop   using CMSIS funcs @ 50Khz    |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| ADC Sampling and Conversion   and ePWM Write @ 8Khz        |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| ADC Sampling and Conversion   and ePWM Write @ 16Khz       |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| ADC Sampling and Conversion   and ePWM Write @ 32Khz       |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+
| ADC Sampling   and Conversion and ePWM Write @ 50Khz       |                        |               |               |                          |
+------------------------------------------------------------+------------------------+---------------+---------------+--------------------------+

