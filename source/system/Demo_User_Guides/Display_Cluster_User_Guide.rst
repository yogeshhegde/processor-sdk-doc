.. include:: /_replacevars.rst

.. _display-cluster-user-guide:

Display Cluster - User Guide
============================

Overview
--------

AM62Px supports display sharing between A53 and MCU R5 cores. Refer `this page <../../linux/How_to_Guides/Target/How_to_enable_display_sharing_between_remotecore_and_Linux.html>`__ to know 'How to enable display sharing between remote core and Linux'.

The Display Cluster Demo helps evaluate the display sharing feature out of the box without any manual changes in the filesystem.

Hardware Prerequisites
----------------------

  - AM62Px SK EVM

  - Microtips LVDS Panel

  - SD card (minimum 16GB)

  - PC (Windows or Linux) to flash wic image onto a SD Card

  - tisdk-display-cluster wic image (Available at |__SDK_DOWNLOAD_URL__|)

Steps to validate Display Cluster Demo
--------------------------------------

#. Flash an SD card with the tisdk-display-cluster-|__SDK_BUILD_MACHINE__|.wic.xz image. Please follow the instructions provided at `Flash an SD card <../../linux/Overview/Processor_SDK_Linux_create_SD_card.html>`__.

#. Insert the flashed SD card to the board, connect the Microtips LVDS Panel and power on both the Display panel and TI |__PART_FAMILY_DEVICE_NAMES__| SK.

#. As soon as the device is powered on, MCU R5 will display the Texas Instruments logo which slowly fades away and then starts displaying the Tell Tales before the Linux boots.

#. Once after the Linux is fully booted, it will launch the ti-demo binary which mimics an Automotive Display Cluster.

#. The entire screen is controlled by the A53 displaying the Cluster except the region where MCU R5 is overlaying the Tell Tales.

    .. Image:: /images/AM62P-display-cluster.png
      :width: 950
      :height: 900

#. Now even if Kernel or the application crashes for some reason, the MCU will still be displaying the Tell Tales with it's own pipeline. To try crashing the Kernel, run

   ::

      echo c > /proc/sysrq-trigger

How to build Display Cluster Demo
---------------------------------

**Building Display Cluster wic image**

    #. To build the display cluster wic image, please refer `Yocto Build Instructions <../../linux/Overview_Building_the_SDK.html>`__.

**Building the Linux Demo binary from sources**

    #. The source code for Display Cluster demo is available as part of the `ti-apps-launcher <https://github.com/TexasInstruments/ti-apps-launcher>`__.

        ::

            git clone https://github.com/TexasInstruments/ti-apps-launcher

    #. Download and Install the Linux SDK from |__SDK_DOWNLOAD_URL__| following the steps mentioned at `Download and Install the SDK <../../devices/AM62PX/linux/Overview/Download_and_Install_the_SDK.html>`__.

    #. Prepare the environment for cross compilation.

        ::

            source <path-to-linux-installer>/linux-devkit/environment-setup

    #. Compile the sources

        ::

            cd <path-to-ti-apps-launcher-sources>
            qmake ../ti-demo.pro ; make

    #. Transfer the generated `ti-demo` binary to the target and run.

**Building the MCU Firmware from sources**

    #. Please refer to the `MCU+ SDK Documentation <https://software-dl.ti.com/mcu-plus-sdk/esd/AM62PX/09_02_00_38/exports/docs/api_guide_am62px/group__DRV__DSS__MODULE.html>`__


