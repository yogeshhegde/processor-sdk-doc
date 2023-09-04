SD Card Creation
=============================

In order to flash the |__PART_FAMILY_NAME__| board's eMMC the fist time, a SD card containing the required bootloaders will have to be used
to boot into uboot and use fastboot.

Partitioning the SD card
------------------------

The SD card has to be partitioned using fdisk and the layout should look like as follow:

::

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

Assuming the SD card is /dev/sda:

::

    mkfs.vfat /dev/sda1

Copying the required bootloaders
--------------------------------

Once the SD card has been partitioned and formatted, copy the required binaries onto the newly formatted SD partition, either the pre-built ones located 
in your Android source folder in ``vendor/ti/am62x/bootloader`` or the ones you generated following the build instructions step in the next section.

These binaries are also present in the pre-built binaries tarball on the SDK download page.

::

    tiboot3.bin  tispl.bin  u-boot.img
