********************************************
Flashing Instruction
********************************************

.. include:: /devices/AM62X/android/Overview/Processor_SDK_Android_create_SD_card_script.rst.inc

eMMC flashing
===================

Flashing instructions
~~~~~~~~~~~~~~~~~~~~~

Once build is complete, prepare your eMMc binairies and images:

1. Change Boot mode DIP switches for SD card boot.

::

    Boot mode DIP Switch:
    SW1: 11000010 SW2: 01000000

2. Ensure the device is plugged in with USB Host and Debug UART/Serial Debug


3. Boot the board with tiboot3.bin, u-boot.img, tispl.bin files in
boot partition of SD card.


4. Open a terminal debugger to view console output from the device:

::

    sudo picocom -b 115200 -r -l /dev/ttyUSB0

5. Setup Android partition table:(Need to be removed after hardcoding it on the uboot source code)

::

    env default -f -a
    run set_android_boot

6.Power cycle the board and enter u-boot.


7. Enable fastboot on the device through the terminal debugger:

::

    => fastboot 0

8. In a different terminal, change directory to ``out/target/product/am62x`` and run the ``flashall.sh`` script:

::

    cd out/target/product/am62x
    sudo ./flashall.sh;

9.Power off the board and remove the SD card.


10. Change Boot mode DIP switches to boot from eMMC user partitions and power cycle the board:

::

    Boot mode DIP Switch:
    SW1: 11000010 SW2: 00000000
| 

