SD Card Creation
=============================

.. rubric:: Overview
   :name: overview

The Android SDK includes a script in the **<ANDROID SDK INSTALL
DIR>/bin** directory named **create-sdcard.sh**. The purpose of this
script is to create SD cards for the following high-level use case:

#. Create the `**SD card using default
   images** <#sd-card-using-default-images>`__ from the Processor SDK
   for Android

The script will give you information about each step, but the following
sections will go over the details for the use case above and walk you
through how to use the script as well.

.. rubric:: Common Steps
   :name: common-steps

.. rubric:: Invoking the Script
   :name: invoking-the-script

The **create-sdcard.sh** script can be run from any location but must be
run with **root** permissions. This usually means using the **sudo**
command to start execution of the script. For example:

**sudo <ANDROID SDK INSTALL DIR>/bin/create-sdcard.sh**
If you fail to execute the script without root permissions you will
receive a message that root permissions are required and the script will
exit.

.. rubric:: Select the SD Card Device
   :name: select-the-sd-card-device

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

You would enter **1** to select the *sdb* device

**NOTE**: For most common installations, this script works fine.
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

.. rubric:: Re-Partitioning the SD Card
   :name: re-partitioning-the-sd-card

Any partitions of the device that are already mounted will be un-mounted
so that the device is ready for partitioning.

If the SD Card already has partition you will see a prompt like the
following asking you if you would like to repartition the card. If the
card was not already partitioned then this step will be skipped and you
can move on to the next step.

::

    Would you like to re-partition the drive anyways [y/n] :

-  Options:

   -  **y** - This will allow you to change the partitioning of the SD
      card. For example if you have a 3 partition card and want to
      create a 2 partition card to give additional storage space to the
      root file system you would select **y** here.
      **NOTE:** This operation **WILL ERASE** the contents of your SD
      card
   -  **n** - If the SD card already has the desired number of
      partitions then this will leave the partitioning alone. If you
      select **n** here skip on to the `**Installing SD Card
      Content** <#installing-sd-card-content>`__ section.

.. rubric:: Installing SD Card Content
   :name: installing-sd-card-content

After the SD card is partitioned, you will be prompted whether you want
to continue installing the file system or safely exit the script.

-  Options:

   -  **y** - Selecting yes here will begin the process of installing
      the SD card contents. This operation **WILL ERASE** any existing
      data on the SD card. Refer to one of the following sections for
      additional instructions depending on which use case you are
      creating an SD card for

      -  Create the `**SD card using default
         images** <#sd-card-using-default-images>`__

   -  **n** - Selecting no here will allow you to have partitioned your
      card but will leave the partitions empty.

| 

.. rubric:: SD Card Using Default Images
   :name: sd-card-using-default-images

The purpose of this section is to cover how to use the
**create-sdcard.sh** script to populate an SD card that can be used to
boot the device using the default images that ship with the Processor
SDK for Android.

.. rubric:: Prerequisites
   :name: prerequisites

#. The Processor SDK for Android is installed on your host system
#. The SD card you wish to create is inserted into the host system and
   has a size sufficiently large to hold at least the bootloaders,
   kernel, and Android file system.
#. You have started running the script as detailed in the `**Common
   Steps** <#common-steps>`__ section above.

.. rubric:: Choose Install Pre-built Images
   :name: choose-install-pre-built-images

You should now see a prompt like:

::

    now installing:  ti-processor-sdk-android-am57xx-evm-04.00.00.01

    0. BOOTFILEPATH = ....00.00.01//board-support/prebuilt-images
    1. MLO          = GP_MLO
    2. BOOTIMG      = u-boot-am57xx-evm.img
    3. BOOTUENV     = uEnv.txt
    4. KERNELIMAGE  = zImage-am57xx-evm.bin
    5. DTBDIR       = ....00.00.01//board-support/prebuilt-images
        * am571x-idk-lcd-osd.dtb
        * am571x-idk-lcd-osd101t2587.dtb
        * am571x-idk.dtb
        * am572x-idk-lcd-osd.dtb
        * am572x-idk-lcd-osd101t2587.dtb
        * am572x-idk.dtb
        * am57xx-beagle-x15-revb1.dtb
        * am57xx-beagle-x15.dtb
        * am57xx-evm-reva3.dtb
        * am57xx-evm.dtb
    6. RAMDISKIMG   = ...oard-support/prebuilt-images/ramdisk.img
    7. SYSTEMIMG    = ...board-support/prebuilt-images/system.img
    8. USERDATAIMG  = ...ard-support/prebuilt-images/userdata.img


    Would you like to continue? [y/n] :

You should choose option **y** to create an SD card using the pre-built
images from the SDK. If you choose **n** then the script will exit.

You should execute this script from within the SDK so the script can
determine the SDK path automatically. The script will start copying the
contents to the SD card. Once the files are copied the script will exit.

| 

| 

