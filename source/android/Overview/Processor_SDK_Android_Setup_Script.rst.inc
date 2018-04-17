Run Setup Scripts
======================================

.. rubric:: Overview
   :name: overview

After installation of the SDK on the Linux host, the setup script can
be run to flash the prebuilt images to the onboard eMMC. Some of the
tasks require administrator privileges. The script will prompt you
when these administrator privileges are required. The setup script
does the following things:

-  Minicom setup (to create a serial connection to the board)
-  u-boot setup (to configure the environment variables for the fastboot
   process)
-  Flashes the prebuilt images to the onboard eMMC (to allow you to boot
   the board from the eMMC)

.. rubric:: Prerequisites
   :name: prerequisites

To run the SDK's setup script the following steps should be taken first:

#. Install Minicom on your Linux host machine and add the current user
   to the dialout group. A Minicom script is used to configure the
   u-boot environment variables as well as put the device into fastboot
   mode.
   
   .. code-block:: bash
      sudo apt-get install minicom
      sudo usermod -a -G dialout $username

#. Run the **create-sdcard.sh** script provided in the SDK's **bin/**
   directory
   This will create an SD card using the prebuilt images, including a
   fastboot enabled u-boot.
#. Put the newly created SD card into your EVM
#. Connect a serial cable from your Linux host machine (the one from
   which you will run the setup.sh script) to your EVMs serial port.
   The AM572x GP EVM will require a 6-pin USB-to-serial cable. The 6-pin
   connection is on the underside of the board. `FTDI Serial
   cable <http://circuitco.com/support/index.php?title=BeagleBone_Black_Accessories#Serial_Debug_Cables>`__
   The AM57xx IDK boards have an onboard USB to serial IC so only a
   micro USB cable is required. The silkscreen next to the correct micro
   USB port will say 'USB JTAG' (both JTAG and serial connection are on
   the same port) and will be on the corner of the board that is
   opposite from the RJ-45 connectors.
#. Connect a micro USB cable (used for fastboot and ADB connections)
   from your Linux host machine to your EVMs (other) micro USB port.
   The AM572x GP EVM only has one micro USB port and it is located next
   to the SD card slot
   The AM57xx IDK has two micro USB ports. The second port is located
   underneath the RJ-45 jacks.
#. Connect the provided power cable to the barrel jack.
#. Power up your board and use **ls /dev/ \| grep ttyUSB** on your Linux
   host machine to find your serial port connection to your board
   The AM572x GP EVM will show up as a single connection (e.g.
   /dev/ttyUSB0)
   The AM57xx IDK boards will have two connections, one for serial
   communication and one for JTAG (e.g. /dev/ttyUSB0 and /dev/ttyUSB1).
   The higher numbered port is the serial connection that we are looking
   for.
#. Note down the serial connection device path, for instance
   /dev/ttyUSB1

.. rubric:: How to run the setup script
   :name: how-to-run-the-setup-script

The Setup Script is located in the Processor SDK Android installation
directory. By default, this directory has a name that has the form
ti-processor-sdk-android-am57xx;-<Version>. Navigate to that
ti-processor-sdk-android install directory. Then run the script:

.. code-block:: bash

   ./setup.sh

.. rubric:: Detailed description of what the script is doing
   :name: detailed-description-of-what-the-script-is-doing

.. rubric:: Minicom Setup
   :name: minicom-setup

This step let's the rest of the process now which serial port the board
connection is on. You should respond to the following question with the
device found in step #7 above.

::

    Which serial port do you want to use with minicom?
    [ /dev/ttyUSB0 ]

-  A minicom configuration will be saved for you at
   /home/user/.minirc.dfl
-  The old configuration if there was one will be saved at
   /home/user/.minirc.dfl.old

.. rubric:: uboot Setup
   :name: uboot-setup

This section will create a Minicom script to generate the necessary
u-boot environment variables and commands to put your board into
fastboot mode.

::

    Would you like to create a minicom script to configure the board (y/n)?
    [ y ]

If you answer 'n' to this question the script will exit.

.. rubric:: Run the Setup Script
   :name: run-the-setup-script

This section will run the remainder of the setup script and will create
a series of action between the board and your Linux host that will
configure the u-boot environment variables, put the EVM into fastboot
mode, and then flash the prebuilt images to the eMMC on the device. You
must select 'y' at the following question and then power cycle or reboot
your board to start the process.

::

    Would you like to run the setup script now (y/n)?
    [ y ]

If you answer 'n' to this question the script will exit.

.. rubric:: Boot Android
   :name: boot-android

At the completion of the this process you will have a board that can
boot Android from either the SD card that is plugged in or through the
newly flashed eMMC device. The recommended method is to power the device
off, remove the SD card, and then power the device back on to boot
Android from the eMMC.

