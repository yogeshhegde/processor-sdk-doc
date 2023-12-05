
********************************************
Flashing Instruction
********************************************

DFU Recovery
============

It's possible to put the AM62x SK EVM in USB DFU mode, which allows
loading bootloaders over DFU. This is done via the ``snagboot`` tool.

This is useful for initial flashing or recovering boards which have broken
bootloaders.

Installation and setup
----------------------

Install snagboot following the `official instructions <https://github.com/bootlin/snagboot>`_

.. note::

    Snagboot requires at least Python 3.8, meaning that it can't run on Ubuntu 18.04 releases.
    If Snagboot cannot be installed, it's possible boot the initial bootloaders from an SD card.

    Follow `Initial Flashing on SD card`_ if you encounter issues with Snagboot.

.. _Initial Flashing on SD card: ../devices/AM62X/android/Application_Notes_Android_Bootloader_SD_Card.html


eMMC flashing
==============

Flashing instructions
---------------------

Once the build is complete, follow the steps below to flash the images to eMMC.

    .. Image:: ../images/am62x_sk_evm_setup.jpg

1. Change the Boot Mode DIP switches to DFU mode::

        Boot mode DIP Switch:
        SW1: 11001010 SW2: 00000000

2. Ensure the device is plugged in with USB Host and Debug UART/Serial Debug

3. Open a terminal debugger to view console output from the device::

        sudo picocom -b 115200 -r -l /dev/ttyUSB0

4. run ``snagrecover`` for host::

        snagrecover -s am625 -f ./am62x-sk-evm.yaml


    In the serial console, you will see::

        SYSFW ABI: 3.1 (firmware rev 0x0009 '9.0.5--v09.00.05 (Kool Koala)')
        SPL initial stack usage: 1856 bytes
        Trying to boot from DFU


.. note::

    For AM62x LP variant, or HS-FS boards, edit ``am62x-sk-evm.yaml`` :

        .. code:: yaml

            tiboot3:
                # for LP boards, use:
                path: tiboot3-am62x-lp-sk-dfu.bin
                # for LP with HS-FS:
                # path: tiboot3-am62x-lp-sk-dfu-hsfs.bin
                # for HS-FS:
                # path: tiboot3-am62x-sk-dfu-hsfs.bin
            tispl:
                # For LP boards, use:
                path: tispl-am62x-lp-sk-dfu.bin
            u-boot:
                # For LP boards, use:
                path: u-boot-am62x-lp-sk-dfu.img


5. Setup default U-Boot environment

.. _step_5_flashing_instructions:

    Type ``Ctrl-C`` in the serial console to continue to U-Boot.
    From there, we can run fastboot to recover with::

        =>  env default -f -a; saveenv;

.. note::
    If you build with `TARGET_AVB_ENABLE=true` or flash User Images you need to do this command in uboot console::

        => setenv force_avb "1"; saveenv;

.. note::

    By default No Device-Tree Overlays was selected. Please follow this link to set a `Device Tree Overlays`_

.. _Device Tree Overlays: ../devices/AM62X/android/Application_Notes_dtbo_support.html

6. Enable fastboot mode on the device through the terminal debugger by executing below command. Before running this command make sure USB-C cable is connected from the host PC to the EVM::

        => fastboot 0

7. From the host PC run the ``flashall.sh`` script to start flashing the binaries to eMMC::

        # If you are using binaries built locally
        cd out/target/product/am62x
        sudo ./flashall.sh --board am62x-sk

        (OR)

        # If you are using pre-built binaries from SDK download page
        cd AM62x_09.01.00_emmc
        sudo ./flashall.sh --board am62x-sk

.. note::
    To flash AM62X-LP board you should do::

        sudo ./flashall.sh --board am62x-lp-sk

.. note::

    To Flash HS-FS board use flash script with ``--hsfs`` arg.
    For example::

        sudo ./flashall.sh --board am62x-sk --hsfs

8. Once the flashing is complete, power off the board

9. Change Boot mode DIP switches to boot from eMMC user partitions and power cycle the board::

        Boot mode DIP Switch:
        SW1: 11000010 SW2: 00000000

10. Board should boot the Android images now.

Flashing the kernel
===================

In order to flash a new kernel, the new boot image should be flashed::

        adb reboot bootloader
        < Wait for bootloader reboot >

        cd <PATH/TO/BOOT/IMAGE>
        fastboot flash boot boot.img
        fastboot reboot

The board should boot with the new kernel build.
