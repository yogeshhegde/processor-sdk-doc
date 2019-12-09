.. include:: replacevars.rst.inc

.. rubric:: Quick Start Guide
   :name: quick-start-guide

Thanks for your interest in |__SDK_FULL_NAME__|.
In this section, we describe the basic steps needed to start development using the SDK.
We will cover the following:

1. Steps for SDK installation
2. Setting up the host environment
3. Hardware setup
4. Running the Out of the box demo
5. Flashing release binaries
6. Illustration for simple kernel build and install to target

For more detailed documentation, refer to `Getting Started Guide <Overview_Getting_Started_Guide.html>`__

.. rubric:: Steps for SDK installation
   :name: qsg-steps-for-sdk-installation

Refer to section `Installing the SDK <Overview/Download_and_Install_the_SDK.html>`__
for instructions on running the SDK installer.

.. rubric:: Setting up host environment
   :name: qsg-setting-up-host-environment

Once the installer is run, you can setup your host environment with a few steps.
Run the following scripts to achieve this:

* *sdk-install.sh* to setup cross compiler environment.
* *setup.sh* to install all host packages needed for development.

Detailed steps are described at `Installing the SDK <Overview/Run_Setup_Scripts.html>`__

.. rubric:: Hardware EVM setup
   :name: qsg-hardware-evm-setup

.. ifconfig:: CONFIG_part_family in ('J7_family')

    J721E EVM comes with a SoM (System on Chip),  a common processor board and optionally
    few daughter cards.

Detailed instructions for EVM setup with image illustration can be found at
`J721E EVM Hardware Setup <How_to_Guides/Hardware_Setup_with_CCS/J721E_EVM_Hardware_Setup.html>`__.
Refer this to setup your EVM and boot with the default card.

The preferred way for starting SDK development is SD card boot. The section referenced above
describes pin settings to set the EVM in SD boot mode.

.. rubric:: Running out of the box demo
   :name: qsg-running-oob-demo

By default, the SD card comes with pre-built Linux SDK binaries flashed.
This will allow you to quickly verify the EVM functionality with just a Display Port monitor.

Insert the SD card with pre-built binaries and boot the EVM. After successful bootup,
you should see a welcome message on the display wallpaper.


.. rubric:: Flashing release binaries
   :name: qsg-flashing-release-binaries

The SDK Installer packages latest pre-built binaries and filesystem for the target.
For detailed steps on flashing these binaries on the SD card, refer to the section
format your SD card and flash all the pre-built binaries from the SDK release,
`Creating SD Card on Linux <Overview/PSDKLA_Formatting_SD_Card.html>`__.

You should be able to verify the same out of box demo after flashing the SD card.
This step should be used only when you want to completely overwrite the card with
release binaries.

.. rubric:: Illustration for simple kernel build and install to target
   :name: qsg-kernel-build-install-example

For most users, an important step in development is the ability to customize
baseport software components like bootloader, Linux kernel, hypervisor, etc.
This SDK allows you to build these components and install the built binaries
for target EVM. This step allows you to verify that your host environment
is configured correctly, and you can build and install these components.

For detailed instructions on building BSP components, refer to the section
`Building the baseport components <Overview/Top_Level_Makefile.html>`__.
You should run the following commands in the installer directory:

* Build all components using *make all*
* Follow the section *Installing to SD card rootfs*
* Follow the section *Installing boot binaries*

After you build and copy all the binaries to your SD card, you can boot the
EVM with binaries built on your host. Upon successful bootup, you should see
a different wallpaper on the display. This should confirm that your updates
are copied correctly in the SD card. Also, you can run the following command
on the target to verify that you are using the newly-built Linux kernel.

::

    $> cat /proc/version

The output should indicate the build date, host PC name, etc. This verifies
that your SDK has been setup correctly, enabling you to start development.
