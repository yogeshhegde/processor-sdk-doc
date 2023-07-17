
.. _TI-Apps-Launcher-User-Guide-label:

TI Apps Launcher - User Guide
=======================================

Overview
--------

TI Apps Launcher is a QT Based Application launcher for TI Platforms. Currently, TI Apps Launcher incorparates following applications,

- Industrial HMI

- Live Camera

- ARM Analytics 

- Benchmarks

- GPU Performance

- Seva Store

- Firefox

- 3D Demo

- Settings

All of the necessary equipment requirement and instructions are provided here.

Hardware Prerequisites
----------------------

-  TI AM62x SK

-  PC (Windows or Linux, to use serial terminal console)

-  HDMI Monitor (to view the Demo on Display)

-  Ethernet Cable (to connect AM62x SK to internet)

-  USB Camera or OV5640 camera sensor module (for Live Camera)

-  Keyboard & Mouse (to control the TI Apps Launcher)

-  SD card (minimum 16GB)

Launching and Using the TI Apps Launcher
----------------------------------------

The TI Apps Launcher launches on Linux startup. Follow the below instructions to use it.

1. Flash an SD card with **tisdk-default-image-am62xx-evm.wic.xz**. User can download the tisdk-default-image-am62xx-evm.wic.xz image from `here <https://www.ti.com/tool/download/PROCESSOR-SDK-LINUX-AM62X/>`__. Please follow the instructions from here to `Flash an SD card <../../linux/Overview/Processor_SDK_Linux_create_SD_card.html>`__.

2. Insert the flashed SD card to the board, connect the display, mouse, ethernet cable, keyboard and power on the TI AM62x SK. The TI Apps Launcher will launch automatically when the device is fully booted.

.. Image:: /images/ti-apps-launcher.png
   :width: 950
   :height: 900

Launching the Industrial HMI
____________________________

1. To launch the Industrial HMI demo, click on the `Industrial HMI` button on the left panel.

.. Image:: /images/industrial-hmi-button.jpg
   :width: 407
   :height: 400

.. note:: It takes around 3-5 seconds for Industrial HMI to start.

2. By default, the Industrial HMI demo starts in **Auto** mode as shown below.

.. Image:: /images/industrial-hmi.png
   :width: 950
   :height: 900

3. You can click on the Auto-Manual slider button to switch modes.

.. Image:: /images/industrial-hmi-auto-manual.jpg
   :width: 950
   :height: 900
   
4. In Manual mode, you can use the **^** and **v** buttons of each motor to control the RPM.
   
Launching the Live Camera
_________________________

1. Ensure you have enabled the camera sensors which you have connected to TI AM62x SK. Refer `this <../../linux/Foundational_Components/Kernel/Kernel_Drivers/Camera/CSI2RX.html#enabling-camera-sensors>`__ to know the list of camera modules supported and how to enable the sensor overlays for them.
 
2. To launch the Live Camera demo, click on the `Live Camera` button on the left panel.

.. Image:: /images/live-camera-button.jpg
   :width: 407
   :height: 400

.. note:: It takes around 3-5 seconds for Live Camera to start.

3. The Live Camera demo starts streaming the output of the camera connected in the centre window of TI Apps Launcher. The image below is captured using USB Camera. 

.. Image:: /images/live-camera.png
   :width: 950
   :height: 900

Launching the ARM Analytics Demo
________________________________

1. AM62x SDK now supports ARM Analytics with pre-existing demos showcasing Object Detection, Face Detection and Image Classification. 

2. To launch the ARM Analytics demo, click on the `ARM Analytics` button on the left panel.

.. Image:: /images/arm-analytics-icon.jpg
   :width: 407
   :height: 400

3. By default, the ARM Analytics demo shows the results of **Object Detection** Model on existing data.

.. Image:: /images/object-detection.png
   :width: 950
   :height: 900

4. Click on the `Face Detection` button to check the results of **Face Detection** Model on existing data.

.. Image:: /images/face-detection.png
   :width: 950
   :height: 900

5. Click on the `Image Classification` button to check the results of **Image Classification** Model on existing data.

.. Image:: /images/image-classification.png
   :width: 950
   :height: 900
   
Launching the Benchmarks Demo
_____________________________

1. The Benchmarks Demo includes various System Benchmarks like dhrystone, linpack, nbench, etc. and GPU benchmarks like glmark2.

2. Click on the `Benchmarks` button on the left panel.

.. Image:: /images/benchmark-icon.jpg
   :width: 407
   :height: 400

3. User will now see the list of Benchmarks available to test on TI AM62x. Click on the `play button` infront of the benchmark you like to test. The image below is captured while running the `glmark2`.

.. Image:: /images/benchmark-glmark2.png
   :width: 950
   :height: 400
   
4. You will see the updated values of FPS & Score metrices getting populated.

.. Image:: /images/benchmark-glmark2-updated.png
   :width: 950
   :height: 400
 
Launching the GPU Performance Demo
__________________________________

1. The GPU Performance demo allows users to vary the GPU loads using glmark2. Click on the `GPU Performance` button on the left panel.

.. Image:: /images/gpu-performance-icon.jpg
   :width: 407
   :height: 400

2. Now you can vary the GPU Loads by clicking on the various numbers you see on `GPU Load Levels Bar`.

.. Image:: /images/gpu-performance-home.png
   :width: 950
   :height: 900

3. The image below is captured while running the `glmark2` with **GPU Load Level as 1**.

.. Image:: /images/gpu-performance-demo.png
   :width: 950
   :height: 900

4. You will see the updated values of FPS & Score metrices getting populated.
    
Launching the Seva Store
________________________

1. AM62x SDK now supports Seva Store. Seva Store is TI developed Demo Gallery Tool which allows users to Download and Install demos on the go. Developers can host their Demos as Docker Images on any public Docker Registry and link them to Seva Design Gallery. Refer `Seva Store - User Guide <Seva_Store.html>`__ to know more about Seva Store.

.. Image:: /images/seva-store-icon.jpg
   :width: 407
   :height: 400

Launching the Firefox Browser
_____________________________

1. AM62x SDK now supports Firefox ESR Browser. Click on the `Firefox` button on the left panel. 

.. Image:: /images/firefox-icon.jpg
   :width: 407
   :height: 400

2. Click `Launch` button to launch the Firefox Browser. The Browser launches with `TI Arm-based processors page <https://www.ti.com/microcontrollers-mcus-processors/arm-based-processors/overview.html>`__ as the first tab by default. 

.. Image:: /images/firefox-tab.png
   :width: 950
   :height: 900

.. note:: It takes approximately 10-12 seconds for Firefox ESR browser to launch.

3. Click `x` to close the Firefox Browser.

Launching the 3D Demo
_____________________

1. Click on the `3D Demo` button on the left panel.

.. Image:: /images/3d-icon.jpg
   :width: 407
   :height: 400

2. Click `Launch` button to launch the 3D Demo by Imagination. By default, you would see the Skinning Model running on the screen.

.. Image:: /images/3d-demo.png
   :width: 950
   :height: 900
   
3. You can use mouse buttons or spacebar to pause the 3D Demo and press `ESC` to exit & go back to TI Apps Launcher.

Using the Settings Button
_________________________

1. The Settings button on the left panel can be used to set docker's systemd-proxy and system proxy if your TI AM62x SK is connected to a VPN.

.. Image:: /images/settings-icon.jpg
   :width: 407
   :height: 400

2. Once the user clicks on the Settings button, it will ask for a HTTPS Proxy and No proxy values.

.. Image:: /images/settings.png
   :width: 950
   :height: 900

3. Once you enter the necessary values for both HTTPS and No proxy, click on `Set Proxy` to set the proxy configuration.

Building the TI Apps Launcher
-----------------------------

The TI Apps Launcher is enabled by default in yocto for AM62x Linux and RT-Linux.

The source code is available at `TI Apps Launcher <https://github.com/TexasInstruments/ti-apps-launcher/>`__ and can be re-compiled with the following steps

1. To setup the environment, from the root of the SDK installation directory, source `environment-setup` script.
   ::

        $ source linux-devkit/environment-setup

2. Go to the root of TI Apps Launcher repository and run the following command to build the application.
   ::

        $ qmake "SOURCES += configs/am62xx-evm.cpp" "DEFINES += SOC_AM62"; make

3. Copy the compiled binary to /usr/bin directory of the device
   ::

        $ scp ti-apps-launcher root@<ip-addr-of-device>:/usr/bin/

4. If you have modified the scripts under the ti-apps-launcher scripts directory then copy the same to the device
   ::           
        
        $ scp -r scripts/ root@<ip-addr-of-device>:/opt/ti-apps-launcher/
