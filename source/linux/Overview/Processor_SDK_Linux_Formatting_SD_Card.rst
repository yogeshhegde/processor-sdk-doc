Formatting SD card on Linux
===========================

Overview
--------

The Linux SDK includes a script in the **<SDK INSTALL DIR>/bin**
directory named **mksdboot.sh**. The purpose of this script is to
create bootable SD cards by partitioning and formatting them so that
target can boot using the boot images and filesystem.

   .. note::
      You will need a >8GB SD Card and a SD Card Reader

   .. note::
      If you are having trouble booting with the SD card, you may need
      to run the following commands to clear the default environment.
      You will then need to reboot the board for the commands to take
      effect.

      .. code-block:: text

         env default –a –f
         saveenv

Select the SD Card Device
-------------------------

The first step before running the script is to select the drive
representing the SD card that you want to format. In most cases your
host root file system drive has been masked off to prevent damage to the
host system. You can run `sudo fdisk -l` to find out the device name
for the SD card you want to format. Example output looks like this:

::

    Disk /dev/sda: 931.5 GiB, 1000204886016 bytes, 1953525168 sectors
    Units: sectors of 1 * 512 = 512 bytes
    Sector size (logical/physical): 512 bytes / 4096 bytes
    I/O size (minimum/optimal): 4096 bytes / 4096 bytes
    Disklabel type: dos
    Disk identifier: 0x2addf736
    
    Device     Boot      Start        End   Sectors   Size Id Type
    /dev/sda1             2048  614402047 614400000   293G 83 Linux
    /dev/sda2        614402048 1228802047 614400000   293G 83 Linux
    /dev/sda3       1228802048 1953523711 724721664 345.6G 83 Linux
    
    Disk /dev/sdd: 14.9 GiB, 15931539456 bytes, 31116288 sectors
    Units: sectors of 1 * 512 = 512 bytes
    Sector size (logical/physical): 512 bytes / 512 bytes
    I/O size (minimum/optimal): 512 bytes / 512 bytes
    Disklabel type: dos
    Disk identifier: 0xda7cb208
    
    Device     Boot   Start      End  Sectors  Size Id Type
    /dev/sdd1  *       2048   129023   126976   62M  c W95 FAT32 (LBA)
    /dev/sdd2        129024  8517631  8388608    4G 83 Linux
    /dev/sdd3       8517632 31116287 22598656 10.8G 83 Linux

You should choose the device where the partition sizes match with the
SD card you want to partition.

Partitioning SD card
--------------------

No matter which use case above that you are creating an SD card for the
following steps are the same.

The **mksdboot.sh** script can be run from any location but must be
run with **root** permissions. This usually means using the **sudo**
command to start execution of the script. For example:

::

    sudo <SDK INSTALL DIR>/bin/mksdboot.sh --device /dev/sdX --sdk <SDK INSTALL DIR>
    #Replace the /dev/sdX with appropriate device name

.. ifconfig:: CONFIG_part_variant in ('AM65X')

    By default, the mksdboot.sh copies the PG2.0 sysfw to the SD card. To
    use the PG1.0 sysfw, copy the board-support/prebuilt-images/sysfw-am65x-evm.itb
    file to /media/$USER/boot/sysfw.itb.

If you fail to execute the script without root permissions you will
receive a message that root permissions are required and the script will
exit.
