
.. _HMI-and-3D-Demo-User-Guide-label:

HMI and 3D Out Of Box Demo - User Guide
=======================================

Overview
--------

The AM62x SK board has an Imagination Technologies GPU.
Using this, a QT based Human-Machine Interface (HMI) Out of Box Demo has been set up such that the board launches a Control Panel which user can control using the connected Mouse and Keyboard.
The HMI Demo also launches a 3D Demo and Matrix GUI.

All of the necessary equipment requirement and instructions are provided here.

Hardware Prerequisites
----------------------

-  TI AM62x SK

-  PC (Windows or Linux, to use serial terminal console)

-  HDMI Monitor (to view the Demo on Display)

-  Keyboard & Mouse (to control the HMI & 3D Demo)

-  SD card (minimum 16GB)

Launching and Using the HMI Demo
--------------------------------

The HMI Demo launches on Linux startup. Follow the below instructions to use it.

1. Connect the Display, mouse & keyboard and Power on the board. The HMI Demo will launch when the Device is fully booted.

.. Image:: /images/AM62x_HMI_Demo.PNG
   :width: 407
   :height: 400

2. Once started, Click on the ON/OFF button to start the Control Panel.

3. Now you can use the `+` and `-` buttons of each motor to control the RPM.

4. To go to the 3D Demo, click on the `3D` button on the left panel.

.. Image:: /images/AM62X_3D_DEMO.jpg
   :width: 407
   :height: 400

5. You can use `mouse buttons` or `spacebar` to pause the 3D Demo. And press `ESC` to go back to HMI Demo.

6. To Exit the HMI Demo and go to Matrix GUI, long press on ON/OFF Button. The HMI Demo closes after 3 seconds and launches Matrix-GUI.

7. To relaunch the HMI Demo, run
   ::

        systemctl start hmi_demo

Launching the 3D Demo
---------------------

1. To launch the 3D Demo without the HMI Demo, run
   ::

        /etc/init.d/start_3d_demo.sh

2. To change the 3D Demo that launches with the script, update the DEMO_3D_APP_NAME variable in the script.

3. You can find the list of available 3D demos under `/usr/bin/SGX/demos/Wayland/`
   ::

        OGLES2ChameleonMan
        OGLES2Coverflow
        OGLES2ExampleUI
        OGLES2FilmTV
        OGLES2MagicLantern
        OGLES2Navigation
        OpenGLESBinaryShaders
        OpenGLESSkinning

Launching the Matrix-GUI
------------------------

1. To launch the Matrix-GUI without the HMI Demo, run
   ::

        /etc/init.d/matrix-gui-2.0 start

2. To stop the Matrix-GUI, run
   ::
        /etc/init.d/matrix-gui-2.0 stop

Building the HMI Demo
---------------------

The HMI Demo is enabled by default in yocto for AM62x Linux and RT-Linux.

The source code is available at `HMI Demo <https://git.ti.com/cgit/apps/hmi-demo>`__ and can be recompiled with the following steps

1. To setup the environment, from the root of the SDK installation directory, source `environment-setup` script.
   ::

        $ source linux-devkit/environment-setup

2. Go to the root of HMI Demo repository and run the following command to build the application.
   ::

        $ qmake; make

3. Copy the compiled binary to /usr/bin directory of the device
   ::

        $ scp hmi_demo root@<ip-addr-of-device>:/usr/bin/


