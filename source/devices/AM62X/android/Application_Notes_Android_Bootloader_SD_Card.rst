=============================
Android Bootloader on SD Card
=============================

This application note contains steps to flash initial bootloaders
from SD Card instead of using snagboot.

SD Card Creation
=============================

In order to flash the AM62X board's eMMC the fist time, a SD card containing the required bootloaders will have to be used
to boot into U-Boot and use fastboot.

Partitioning the SD card
------------------------

The SD card has to be partitioned using fdisk and the layout should look like as follow::

    Disk /dev/sda: 30,2 GiB, 32227983360 bytes, 62945280 sectors
    Disk model: Storage Device
    Units: sectors of 1 * 512 = 512 bytes
    Sector size (logical/physical): 512 bytes / 512 bytes
    I/O size (minimum/optimal): 512 bytes / 512 bytes
    Disklabel type: dos
    Disk identifier: 0x36c2ba10

    Device     Boot  Start      End  Sectors   Size Id Type
    /dev/sda1  *      2048   272919   270872 132,3M  c W95 FAT32 (LBA)

Formatting the SD card partitions
---------------------------------

Once partitioned, the boot partition has to be formatted with a FAT filesystem.

Assuming the SD card is /dev/sda::

    mkfs.vfat /dev/sda1

Copying the required bootloaders
--------------------------------


Once the SD card has been partitioned and formatted, copy the required binaries onto the newly formatted SD partition, either the pre-built ones located in your Android source folder in ``vendor/ti/am62x/bootloader`` or the ones you generated following the build instructions step in the next section.

These binaries are also present in the pre-built binaries tarball on the SDK download page::

    tiboot3.bin  tispl.bin  u-boot.img

eMMC flashing
==============

Flashing instructions
---------------------

Once the build is complete, follow the steps below to flash the images to eMMC.
Use the SD card created in previous step to get started.

Procedure is same whether the pre-built images from SDK download page is used or
the images are built from source.

1. Change the Boot Mode DIP switches to SD card boot mode::

        Boot mode DIP Switch:
        SW1: 11000010 SW2: 01000000

2. Ensure the device is plugged in with USB host and debug UART/serial debug

3. Boot the board with ``tiboot3.bin``, ``u-boot.img``, ``tispl.bin`` files in
   boot partition of SD card.

4. Open a terminal debugger to view console output from the device::

    sudo picocom -b 115200 -r -l /dev/ttyUSB0

5. Stop at U-Boot console (interrupt the autoboot countdown) and do below commands to setup Android
   partition table::

    env default -f -a; saveenv

Then, continue following the default :ref:`flashing instructions from step 5<step_5_flashing_instructions>`.
