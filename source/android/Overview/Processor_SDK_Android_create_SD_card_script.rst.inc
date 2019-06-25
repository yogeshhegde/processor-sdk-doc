SD Card Creation
=============================

The Android SDK includes a script in the **<ANDROID SDK INSTALL
DIR>/bin** directory named **create-sdcard.sh**. The purpose of this
script is to create SD cards using the boot files from the
Processor SDK for Android.

The script will give you information about each step, but the following
sections will go over the details and walk you through how to use the script.

Invoking the Script
---------------------

The **create-sdcard.sh** script can be run from any location but must be
run with **root** permissions. This usually means using the **sudo**
command to start execution of the script. For example:

.. code-block:: bash

   sudo <ANDROID SDK INSTALL DIR>/bin/create-sdcard.sh

If you fail to execute the script without root permissions you will
receive a message that root permissions are required and the script will
exit.

Select the SD Card Device
----------------------------

The first step of the script will ask you to select the drive
representing the SD card that you want to format. In most cases your
host root file system drive has been masked off to prevent damage to the
host system. When prompted enter the device number corresponding to the
SD card. For example if the output looks like:

::

    Availible Drives to write images to: 
     
    #  major   minor    size   name 
    1:   8       16    7761920 sdb
     
    Enter Device Number: 

You would enter **1** to select the **sdb** device

.. note::
   For most common installations, this script works fine.
   However, if you are using more advanced disk slicing and volume
   management, the presented list of device nodes are off by one; in the
   best case (picking the last item) it will flag a range error, and in the
   worst case (anything in the middle) the wrong DASD can be destroyed. The
   problem originates when it attempts to determine the $ROOTDRIVE to
   "mask" the volume where "/" is mounted from the selection list using a
   "grep -v $ROOTDRIVE" For the naive partitioning case, its heuristic is
   fine, yielding something like "sda" --- but for LVM, it grabs some chunk
   of the device name, e.g. "mapp" (out of "/dev/mapper/kubuntu--vg-root on
   / type ...")


Re-Partitioning the SD Card
------------------------------

Any partitions of the device that are already mounted will be un-mounted
so that the device is ready for partitioning.

The SD card will be re-partitioned to create a single boot partition
with the boot files copied later. The message below will show and
you will be prompted whether you want to continue partitioning the
SD card:

::

   ################################################################################
   
   Partitioning will format the drive with boot partition
   
   ################################################################################
   
   
   ################################################################################
   
        ****WARNING**** continuing will erase all data on sdd
   
   ################################################################################
   
   Would you like to continue? [y/n] :

Select **y** to continue with the partitioning. Select **n** if re-partitioning is
not desired.


Installing SD Card Content
-----------------------------

After the SD card is partitioned, you will be prompted whether you want
to continue copying the boot files or safely exit the script.

-  Options:

   -  **y** - Selecting yes here will begin the process of installing
      the SD card contents. This operation **WILL ERASE** any existing
      data on the SD card.

   -  **n** - Selecting no here will allow you to have partitioned your
      card but will leave the partitions empty.

| 

If you have selected **y**, you should now see a prompt like:

::

    now installing:  ti-processor-sdk-android-am57xx-evm-06.00.00.05

    0. BOOTFILEPATH = ....00.00.05//board-support/prebuilt-images
    1. MLO          = GP_MLO
    2. BOOTIMG      = u-boot-am57xx-evm.img
    3. BOOTUENV     = uEnv.txt


    Would you like to continue? [y/n] :

You should choose option **y** to create an SD card using the pre-built
boot files from the SDK. If you choose **n** then the script will exit.

You should execute this script from within the SDK so the script can
determine the SDK path automatically. The script will start copying the
contents to the SD card. Once the files are copied the script will exit.
