.. include:: /_replacevars.rst

********************************************
Flashing Instruction
********************************************

.. ifconfig:: CONFIG_part_variant in ('AM62X')

   These instructions are for the AM62x SK EVM.

   For flashing the Beagle Play, see the `dedicated application note`_.

   .. _dedicated application note: ../devices/AM62X/android/Application_Notes_BeaglePlay.html


DFU Recovery
============

It's possible to put the |__PART_FAMILY_NAME__| SK EVM in USB DFU mode, which allows
loading bootloaders over DFU. This is done via the ``snagboot`` tool.

This is useful for initial flashing or recovering boards which have broken
bootloaders.

Installation and setup
----------------------

Install snagboot following the `official instructions <https://github.com/bootlin/snagboot>`_

.. note::

    Snagboot requires at least Python 3.8, meaning that it can't run on Ubuntu 18.04 releases.
    If Snagboot cannot be installed, it's possible boot the initial bootloaders from an SD card.

    .. ifconfig:: CONFIG_part_variant in ('AM62X')

      Follow `AM62x Initial Flashing on SD card`_ if you encounter issues with Snagboot.

    .. ifconfig:: CONFIG_part_variant in ('AM62PX')

      Follow `AM62Px Initial Flashing on SD card`_ if you encounter issues with Snagboot.

.. _AM62x Initial Flashing on SD card: ../devices/AM62X/android/Application_Notes_Android_Bootloader_SD_Card.html
.. _AM62Px Initial Flashing on SD card: ../devices/AM62PX/android/Application_Notes_Android_Bootloader_SD_Card.html

eMMC flashing
==============

Flashing instructions
---------------------

Once the build is complete, follow the steps below to flash the images to eMMC.

    .. Image:: ../images/am62x_sk_evm_setup.jpg

1. Change the boot mode DIP switches to DFU mode::

        Boot mode DIP Switch:
        SW1: 11001010 SW2: 00000000

2. Ensure the device is plugged in with USB host and debug UART/serial debug

3. Open a terminal debugger to view console output from the device::

        sudo picocom -b 115200 -r -l /dev/ttyUSB0

4. run ``snagrecover`` for host

  .. ifconfig:: CONFIG_part_variant in ('AM62X')

        ::

          # If you are using binaries built locally
          cd out/target/product/am62x

          (OR)

          # If you are using pre-built binaries from SDK download page
          cd AM62x_09.01.00_emmc

          # for AM62x SK EVM (GP)
          snagrecover -s am625 -f ./am62x-sk-evm.yaml

          # for AM62x SK EVM (HS-FS)
          snagrecover -s am625 -f ./am62x-sk-evm-hsfs.yaml

          # for AM62x LP SK EVM (GP)
          snagrecover -s am625 -f ./am62x-lp-sk-evm.yaml

          # for AM62x LP SK EVM (HS-FS)
          snagrecover -s am625 -f ./am62x-lp-sk-evm-hsfs.yaml

  .. ifconfig:: CONFIG_part_variant in ('AM62PX')

        ::

          # If you are using binaries built locally
          cd out/target/product/am62p

          (OR)

          # If you are using pre-built binaries from SDK download page
          cd AM62Px_09.01.00_emmc

          snagrecover -s am625 -f ./am62px-sk-evm-hsfs.yaml


  In the serial console, you will see::

      SYSFW ABI: 3.1 (firmware rev 0x0009 '9.0.5--v09.00.05 (Kool Koala)')
      SPL initial stack usage: 1856 bytes
      Trying to boot from DFU


5. Setup default U-Boot environment

.. _step_5_flashing_instructions:

  Type ``Ctrl-C`` in the serial console to continue to U-Boot.
  From there, we should ensure the default U-Boot environment is configured with::

      =>  env default -f -a; saveenv;

  .. note::
      If you build with `TARGET_AVB_ENABLE=true` or flash user images you need to do this command in U-Boot console::

          => setenv force_avb "1"; saveenv;

  .. note::

      .. ifconfig:: CONFIG_part_variant in ('AM62X')

        By default, no Device-Tree Overlays are selected. Follow this link to set `AM62x Device Tree Overlays`_

      .. ifconfig:: CONFIG_part_variant in ('AM62PX')

        By default, no Device-Tree Overlays are selected. Follow this link to set `AM62Px Device Tree Overlays`_

.. _AM62x Device Tree Overlays: ../devices/AM62X/android/Application_Notes_dtbo_support.html
.. _AM62Px Device Tree Overlays: ../devices/AM62PX/android/Application_Notes_dtbo_support.html

6. Enable fastboot mode on the device through the terminal debugger by executing below command.
   Before running this command make sure USB-C cable is connected from the host PC to the EVM::

        => fastboot 0

7. From the host PC run the ``flashall.sh`` script to start flashing the binaries to eMMC:

  .. ifconfig:: CONFIG_part_variant in ('AM62X')

        ::

          # If you are using binaries built locally
          cd out/target/product/am62x

          (OR)

          # If you are using pre-built binaries from SDK download page
          cd AM62x_09.01.00_emmc

          # for AM62x SK EVM (GP)
          sudo ./flashall.sh --board am62x-sk

          # for AM62x SK EVM (HS-FS)
          sudo ./flashall.sh --board am62x-sk --hsfs

          # for AM62x LP SK EVM (GP)
          sudo ./flashall.sh --board am62x-lp-sk

          # for AM62x LP SK EVM (HS-FS)
          sudo ./flashall.sh --board am62x-lp-sk --hsfs

  .. ifconfig:: CONFIG_part_variant in ('AM62PX')

        ::

          # If you are using binaries built locally
          cd out/target/product/am62p

          (OR)

          # If you are using pre-built binaries from SDK download page
          cd AM62Px_09.01.00_emmc

          sudo ./flashall.sh --board am62px-sk

  .. note::

      If you get ``mcopy`` command not found error on Linux PC, install the ``mtools`` package::

        $ apt-get install mtools

8. Once the flashing is complete, power off the board

9. Change boot mode DIP switches to boot from eMMC user partitions and power cycle the board::

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
