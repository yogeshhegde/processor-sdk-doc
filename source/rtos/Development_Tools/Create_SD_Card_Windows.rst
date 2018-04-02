Creating a SD Card with Windows
================================

.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Creating_a_SD_Card_with_Windows 

.. rubric:: Overview
   :name: overview

This page details how to use an image file to create a bootable SD card
for the Processor SDK RTOS for AM3/AM4/AM5/K2G. This is only required
one time. After that, you can use Windows to delete the SD card contents
and replace it with whatever you would like to boot.

The contents of an bootable RTOS application will contain two files on
the SD card:

-  **app** - Application image
-  **MLO** - Boot loader image


**Useful Tip**
 If you have the SD card that came in the EVM kit, you can skip the
 following steps to *create* a bootable SD card and simply copy your
 SD card image files directly to the SD card.


| 

.. rubric:: What is Needed
   :name: what-is-needed

-  Access to a Windows PC
-  A valid Processor SDK RTOS for the appropriate processor installed
   (AM335x, AM437x, AM57xx, K2G)
-  Software to write an image file to a SD card
-  A SD card appropriate for the required hardware platform, must be 1GB
   or larger
-  A SD card reader/writer

| 

.. rubric:: Steps to Follow
   :name: steps-to-follow

Here is the process to follow to create the SD card.

.. rubric:: Create a bootable SD image file
   :name: create-a-bootable-sd-image-file

For example purposes, you can use the one that is bundled in the SDK.
The file is located in

::

     [SDK Install Path]\processor_sdk_rtos_<platform>_<version>\prebuilt-sdcards\<evm>\sd_card_img\

For example, the default location of the image file for the GP AM57x EVM
is
``C:\processor_sdk_rtos_am57xx_2_00_00_00\prebuilt-sdcards\evmAM572x\sd_card_img\sd_card.img.gz``.
To save installer space, this file is compressed. Once uncompressed, the
file name will be ``boot.img``.

.. rubric:: Download a disk imager program to write the image file to
   the SD card
   :name: download-a-disk-imager-program-to-write-the-image-file-to-the-sd-card

The open source `Win32 Disk
Imager <http://sourceforge.net/projects/win32diskimager>`__ is a good
option.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
This application needs to be installed with Administrative privilages.

.. raw:: html

   </div>

.. rubric:: Use the software for writing an image to disk to write the
   .img file to the SD card
   :name: use-the-software-for-writing-an-image-to-disk-to-write-the-.img-file-to-the-sd-card

-  Plug the SD card into the SD card reader/writer.
-  Insert the SD card reader/writer into the PC.
-  Launch the disk writer software. In the screenshots below, we are
   using *Win32 Disk Imager*.

.. Image:: ../images/Win32_Disk_Imager_open.png

-  Choose the image file for the SDK that you want to write.

.. Image:: ../images/Win32_disk_imager_select_a_disk_image.png

-  Choose the SD card as the "Device".
-  Write the image to the SD card by click "Write". You will likely get
   the below confirmation box. This command will overwrite whatever disk
   you point it to, please make sure and choose the correct disk.

.. Image:: ../images/Win32_disk_imager_Confirm_overwrite.png

-  You should see the following status bar as the image is being written
   to the disk

.. Image:: ../images/Win32_Disk_Imager_writing_to_disk.png

-  When the write is complete, you will get the following notification:

.. Image:: ../images/Win32_Disk_Imager_Complete.png

-  You can now close the image writing program by click "Exit".

.. rubric:: Safely eject the SD card from the computer
   :name: safely-eject-the-sd-card-from-the-computer

| Here's an example using Windows 7:

.. Image:: ../images/Win7_eject_disk.png

.. Image:: ../images/Win7_eject_disk_detail.png

.. Image:: ../images/Win7_device_can_be_safely_removed.png

| 

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
Once SD card is made bootable with Win32 disk imager, it contains sample
“MLO” and “app” which can be used on the target platform.

.. raw:: html

   </div>

| 

.. rubric:: Boot from SD Card
   :name: boot-from-sd-card

To boot from SD card, simply plug in the SD card to the EVM and power on
the board. If you used the examples provided in the Processor SDK RTOS
installer, you will see

-  AM335x/AM437x:

.. Image:: ../images/AM437x-SD-Card-Example.png

-  AM57x:

.. Image:: ../images/AM57x-SD-Card-Example.png

.. raw:: html

