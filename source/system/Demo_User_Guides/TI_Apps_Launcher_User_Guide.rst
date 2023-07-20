.. include:: /_replacevars.rst

.. _TI-Apps-Launcher-User-Guide-label:

TI Apps Launcher - User Guide
=======================================

Overview
--------

TI Apps Launcher is a QT Based Application launcher for TI Platforms. Currently, TI Apps Launcher incorporates following applications across all supported platforms,

- Industrial HMI

- Live Camera

- Benchmarks

- GPU Performance

- Seva Store

- Firefox

- Settings

.. ifconfig:: CONFIG_part_variant in ('AM62X')

   Additionally, The below demos are also available on the |__PART_FAMILY_DEVICE_NAMES__| platform specifically:

   - ARM Analytics

   - 3D Demo

All of the necessary equipment requirement and instructions are provided here.

.. note::

   Not all of the above set of applications are supported by each platform. So there will be differences between each.

Hardware Prerequisites
----------------------

.. ifconfig:: CONFIG_part_variant in ('AM62X')

   -  TI AM62x SK / TI AM62x-LP SK / TI AM62xSIP SK

.. ifconfig:: CONFIG_part_variant in ('J721S2','J784S4')

   -  TI |__PART_FAMILY_DEVICE_NAMES__| SK

-  PC (Windows or Linux, to use serial terminal console)

-  HDMI Monitor (to view the Demo on Display)

-  Ethernet Cable (to connect |__PART_FAMILY_DEVICE_NAMES__| SK to internet)

-  USB Camera or OV5640 camera sensor module (for Live Camera)

-  Keyboard & Mouse (to control the TI Apps Launcher)

-  SD card (minimum 16GB)

Launching and Using the TI Apps Launcher
----------------------------------------

The TI Apps Launcher launches on Linux startup. Follow the below instructions to use it.

1. Flash an SD card with the **tisdk-default-image**. User can download the tisdk-default-image-|__SDK_BUILD_MACHINE__|.wic.xz image from the SDK downloads page. Please follow the instructions from here to `Flash an SD card <../../linux/Overview/Processor_SDK_Linux_create_SD_card.html>`__.

.. note::

   Images may vary between each platform based on the number of supported applications.

2. Insert the flashed SD card to the board, connect the display, mouse, ethernet cable, keyboard and power on the TI |__PART_FAMILY_DEVICE_NAMES__| SK. The TI Apps Launcher will launch automatically when the device is fully booted.

.. ifconfig:: CONFIG_sdk in ('PLSDK')

   .. Image:: /images/ti-apps-launcher.png
      :width: 950
      :height: 900

.. ifconfig:: CONFIG_sdk in ('j7_foundational')

   .. Image:: /images/ti-apps-launcher-j7.png
      :width: 950
      :height: 900

Launching the Industrial HMI
____________________________

.. ifconfig:: CONFIG_part_variant in ('AM62X')

   .. note::

      Industrial HMI on AM62xSIP SK varies from the one documented here. This is only valid for AM62x SK and AM62x-LP SK.

1. To launch the Industrial HMI demo, click on the `Industrial HMI` button on the left panel.

.. ifconfig:: CONFIG_sdk in ('PLSDK')

   .. Image:: /images/industrial-hmi-button.jpg
      :width: 407
      :height: 400
   |
.. note:: It takes around 3-5 seconds for Industrial HMI to start.

2. By default, the Industrial HMI demo starts in **Auto** mode as shown below.

.. ifconfig:: CONFIG_sdk in ('PLSDK')

   .. Image:: /images/industrial-hmi.png
      :width: 950
      :height: 900

.. ifconfig:: CONFIG_sdk in ('j7_foundational')

   .. Image:: /images/hmi-demo-j7.png
      :width: 950
      :height: 900

3. You can click on the Auto-Manual slider button to switch modes.

.. ifconfig:: CONFIG_sdk in ('PLSDK')

   .. Image:: /images/industrial-hmi-auto-manual.jpg
      :width: 950
      :height: 900

4. In Manual mode, you can use the **^** and **v** buttons of each motor to control the RPM.

Launching the Live Camera
_________________________

1. Ensure you have enabled the camera sensors which you have connected to TI |__PART_FAMILY_DEVICE_NAMES__| SK. Refer `this <../../linux/Foundational_Components/Kernel/Kernel_Drivers/Camera/CSI2RX.html#enabling-camera-sensors>`__ to know the list of camera modules supported and how to enable the sensor overlays for them.

2. To launch the Live Camera demo, click on the `Live Camera` button on the left panel.

.. ifconfig:: CONFIG_sdk in ('PLSDK')

   .. Image:: /images/live-camera-button.jpg
      :width: 407
      :height: 400

.. note:: It takes around 3-5 seconds for Live Camera to start.

3. The Live Camera demo starts streaming the output of the camera connected in the centre window of TI Apps Launcher. The image below is captured using USB Camera.

.. ifconfig:: CONFIG_sdk in ('PLSDK')

   .. Image:: /images/live-camera.png
      :width: 950
      :height: 900

.. ifconfig:: CONFIG_sdk in ('j7_foundational')

   .. Image:: /images/live-camera-j7.png
      :width: 950
      :height: 900

.. ifconfig:: CONFIG_part_variant in ('AM62X')

   Launching the ARM Analytics Demo
   ________________________________

   .. note::

      ARM Analytics Demo is only supported on AM62x SK and AM62x-LP SK. AM62xSIP doesn't support it.

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

.. ifconfig:: CONFIG_part_variant in ('AM62X')

   .. note::

      Benchmarks Demo is not supported on AM62xSIP because it depends on weston-terminal. AM62xSIP uses EGLFS to run the ti-apps-launcher.

1. The Benchmarks Demo includes various System Benchmarks like dhrystone, linpack, nbench, etc. and GPU benchmarks like glmark2.

2. Click on the `Benchmarks` button on the left panel.

.. ifconfig:: CONFIG_sdk in ('PLSDK')

   .. Image:: /images/benchmark-icon.jpg
      :width: 407
      :height: 400

.. ifconfig:: CONFIG_sdk in ('PLSDK')

   3. User will now see the list of Benchmarks available to test on TI |__PART_FAMILY_DEVICE_NAMES__|. Click on the `play button` infront of the benchmark you like to test. The image below is captured while running the `glmark2`.

   .. Image:: /images/benchmark-glmark2.png
      :width: 950
      :height: 400

   4. You will see the updated values of FPS & Score metrices getting populated.

   .. Image:: /images/benchmark-glmark2-updated.png
      :width: 950
      :height: 400

.. ifconfig:: CONFIG_sdk in ('j7_foundational')

   3. User will now see the list of Benchmarks available to test on TI |__PART_FAMILY_DEVICE_NAMES__|. Click on the `play button` infront of the benchmark you like to test. The image below is captured while running the `dhrystone`.

   .. Image:: /images/benchmarks-system.png
      :width: 950
      :height: 400


Launching the GPU Performance Demo
__________________________________

.. ifconfig:: CONFIG_part_variant in ('AM62X')

   .. note::

      GPU Performance Demo is not supported on AM62xSIP because it depends on weston or requires the ownership of EGLFS context.

1. The GPU Performance demo allows users to vary the GPU loads using glmark2. Click on the `GPU Performance` button on the left panel.

.. ifconfig:: CONFIG_sdk in ('PLSDK')

   .. Image:: /images/gpu-performance-icon.jpg
      :width: 407
      :height: 400

2. Now you can vary the GPU Loads by clicking on the various numbers you see on `GPU Load Levels Bar`.

.. ifconfig:: CONFIG_sdk in ('PLSDK')

   .. Image:: /images/gpu-performance-home.png
      :width: 950
      :height: 900

.. ifconfig:: CONFIG_sdk in ('PLSDK')

   3. The image below is captured while running the `glmark2` with **GPU Load Level as 1**.

   .. Image:: /images/gpu-performance-demo.png
      :width: 950
      :height: 900

.. ifconfig:: CONFIG_sdk in ('j7_foundational')

   3. The image below is captured while running the `glmark2` with **GPU Load Level as 3**.

   .. Image:: /images/gpu-benchmarks-textures.png
      :width: 950
      :height: 900

4. You will see the updated values of FPS & Score metrices getting populated.

Launching the Seva Store
________________________

.. ifconfig:: CONFIG_part_variant in ('AM62X')

   .. note::

      Seva Store is not supported on AM62xSIP due to it's memory constraints.

1. |__PART_FAMILY_DEVICE_NAMES__| SDK now supports Seva Store. Seva Store is TI developed Demo Gallery Tool which allows users to Download and Install demos on the go. Developers can host their Demos as Docker Images on any public Docker Registry and link them to Seva Design Gallery. Refer `Seva Store - User Guide <Seva_Store.html>`__ to know more about Seva Store.

.. ifconfig:: CONFIG_sdk in ('PLSDK')

   .. Image:: /images/seva-store-icon.jpg
      :width: 407
      :height: 400

.. ifconfig:: CONFIG_sdk in ('j7_foundational')

   .. Image:: /images/seva-store.png
      :width: 950
      :height: 900

Launching the Firefox Browser
_____________________________

.. ifconfig:: CONFIG_part_variant in ('AM62X')

   .. note::

      Firefox Browser is not supported on AM62xSIP due to it's memory constraints.

1. |__PART_FAMILY_DEVICE_NAMES__| SDK now supports Firefox ESR Browser. Click on the `Firefox` button on the left panel.

.. ifconfig:: CONFIG_sdk in ('PLSDK')

   .. Image:: /images/firefox-icon.jpg
      :width: 407
      :height: 400

2. Click `Launch` button to launch the Firefox Browser. The Browser launches with `TI Arm-based processors page <https://www.ti.com/microcontrollers-mcus-processors/arm-based-processors/overview.html>`__ as the first tab by default.

.. Image:: /images/firefox-tab.png
   :width: 950
   :height: 900

.. note:: It takes approximately 10-12 seconds for Firefox ESR browser to launch.

3. Click `x` to close the Firefox Browser.

.. ifconfig:: CONFIG_part_variant in ('AM62X')

   Launching the 3D Demo
   _____________________

   .. note::

      3D Demo requires weston to be running or EGLFS context to run. ti-apps-launcher is run on EGLFS so it is not supported on AM62xSIP.

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

1. The Settings button on the left panel can be used to set docker's systemd-proxy and system proxy if your TI |__PART_FAMILY_DEVICE_NAMES__| SK is connected to a VPN.

.. ifconfig:: CONFIG_sdk in ('PLSDK')

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

The TI Apps Launcher is enabled by default in yocto for |__PART_FAMILY_DEVICE_NAMES__| Linux and RT-Linux.

The source code is available at `TI Apps Launcher <https://github.com/TexasInstruments/ti-apps-launcher/>`__ and can be re-compiled with the following steps

1. To setup the environment, from the root of the SDK installation directory, source `environment-setup` script.
   ::

        $ source linux-devkit/environment-setup

2. Go to the root of TI Apps Launcher repository and run the following command to build the application.

   .. ifconfig:: CONFIG_part_variant in ('AM62X')

      ::

         $ qmake "SOURCES += configs/am62xx-evm.cpp" "DEFINES += SOC_AM62"; make # For AM62x SK
         $ qmake "SOURCES += configs/am62xx-lp-evm.cpp" "DEFINES += SOC_AM62_LP"; make # For AM62x LP SK
         $ qmake "SOURCES += configs/am62xxsip-evm.cpp" "DEFINES += SOC_AM62_LP"; make # For AM62xSIP SK

      |

   .. ifconfig:: CONFIG_part_variant in ('J721S2')

      ::

         $ qmake "SOURCES += configs/am68-sk.cpp" "DEFINES += SOC_J721S2"; make

      |

   .. ifconfig:: CONFIG_part_variant in ('J784S4')

      ::

         $ qmake "SOURCES += configs/am69-sk.cpp" "DEFINES += SOC_J784S4"; make

      |

3. Copy the compiled binary to /usr/bin directory of the device
   ::

        $ scp ti-apps-launcher root@<ip-addr-of-device>:/usr/bin/

4. If you have modified the scripts under the ti-apps-launcher scripts directory then copy the same to the device
   ::

        $ scp -r scripts/ root@<ip-addr-of-device>:/opt/ti-apps-launcher/
