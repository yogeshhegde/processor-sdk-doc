********************************************
Flashing Instruction
********************************************

.. include:: /devices/AM62X/android/Overview/Processor_SDK_Android_create_SD_card_script.rst.inc

eMMC flashing
==============

Flashing instructions
~~~~~~~~~~~~~~~~~~~~~

Once the build is complete, follow the steps below to flash the images to eMMC.
Use the SD card created in previous step to get started.

Procedure is same whether the pre-built images from SDK download page is used or
the images are built from source.

.. Image:: ../../../images/am62x_sk_evm_setup.jpg

1. Change the Boot Mode DIP switches to SD card boot mode.

::

    Boot mode DIP Switch:
    SW1: 11000010 SW2: 01000000

2. Ensure the device is plugged in with USB Host and Debug UART/Serial Debug

3. Boot the board with tiboot3.bin, u-boot.img, tispl.bin files in
boot partition of SD card.

4. Open a terminal debugger to view console output from the device:

::

    sudo picocom -b 115200 -r -l /dev/ttyUSB0

5. Stop at u-boot console (interrupt the autoboot countdown) and do below commands to setup Android
partition table

::

    env default -f -a
    run set_android_boot

6. Power cycle the board one more time and stop at u-boot console again.

7. Enable fastboot mode on the device through the terminal debugger by executing below command. Before running this command make sure USB-C
cable is connected from the host PC to the EVM.

::

    => fastboot 0

8. From the host PC run the ``flashall.sh`` script to start flashing the bianries to eMMC

::

    # If you are using binaries built locally
    cd out/target/product/am62x
    sudo ./flashall.sh

    (OR)

    # If you are using pre-built binaries from SDK download page
    cd AM62x_08.03.00_emmc
    sudo ./flashall.sh

9. Once the flashing is complete, power off the board and remove the SD card.

10. Change Boot mode DIP switches to boot from eMMC user partitions and power cycle the board:

::

    Boot mode DIP Switch:
    SW1: 11000010 SW2: 00000000

11. Board should boot the Android images now.

.. note::

    **For successful Android boot, HDMI display and an input device needs to be connected to the board before powering on the board.**

    Input device can be a mouse or HDMI display that has a USB touch. Input USB device connects to Type-A connector on the board.

|
