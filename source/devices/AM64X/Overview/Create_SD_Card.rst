
.. _am64x-create-sd-card:

Create SD Card
==============

.. contents::

.. note::
  You will need an SD Card and an SD Card Reader.

.. _am64x-create-sd-card-with-default-images:

Create SD Card with Default Images
----------------------------------

1.  Install the AM64x Processor SDK on a Linux or a Windows machine at <PSDK\_PATH>

|

2.  The default bootable SD card image (WIC file) is available
    at <PSDK\_PATH>/linux/filesystem/tisdk-default-image-am64xx-evm.wic.xz

|

3.  Decompress the tisdk-default-image-am64xx-evm.wic.xz to tisdk-default-image-am64xx-evm.wic

    - For Linux:

    ::

        cd <PSDK_PATH>/linux/filesystem
        unxz tisdk-default-image-am64xx-evm.wic.xz

    - For Windows, decompress the WIC image with a file archiver like 7-zip or
      winzip.

|

4.  Flash the WIC image to SD card


    - For Linux:
        a) First, make sure that the SD card is unmounted. You can use lsblk to
           inspect whether the SD card partitions have a MOUNTPOINT. If the SD
           card is mounted, use umount to unmount the partitions.

           For example, if lsblk returned this:

           ::

               $ lsblk
               NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINT
               :
               :
               sdc      8:32   1    15G  0 disk 
               ├─sdc1   8:33   1 131.8M  0 part /media/localUser/boot
               └─sdc2   8:34   1 765.9M  0 part /media/localUser/root

           Then we would want to unmount sdc1 and sdc2:

           ::

               $ sudo umount /media/localUser/boot
               $ sudo umount /media/localUser/root
               $ lsblk
               NAME   MAJ:MIN RM   SIZE RO TYPE MOUNTPOINT
               :
               :
               sdc      8:32   1    15G  0 disk 
               ├─sdc1   8:33   1 131.8M  0 part 
               └─sdc2   8:34   1 765.9M  0 part 

        b) Next, write the WIC image to the SD card with the following command:

           ::

               sudo dd bs=4M if=./tisdk-default-image-am64xx-evm.wic of=/dev/sdx status=progress && sync

           In the above example, the SD card is at /dev/sdc. In that case, the
           image write command would look like this:

           ::

               sudo dd bs=4M if=./tisdk-default-image-am64xx-evm.wic of=/dev/sdc status=progress && sync

    - For Windows, write the WIC image to the SD card with Win32DiskImager.exe
      (https://sourceforge.net/projects/win32diskimager/files/latest/download)

|

.. _am64x-create-sd-card-with-custom-images:

Create SD Card with Custom Images
---------------------------------

.. note::
  The TI script used to generate custom SD card images should be run on a Linux
  computer.

For a Linux+baremetal application to boot from a SD card, two partitions need to
be created on the SD card:

   - boot partition
   - rootfs partition

create-sdcard-image.sh was created to simplify this card creation process. Here
are the steps on how to use the script to create a custom WIC image to place on
an SD card.

1.  Install the AM64x Processor SDK on a Linux machine at <PSDK\_PATH> .

|

2.  Create a rootfs folder. create-sdcard-image.sh will use the rootfs folder
    to populate the rootfs partition on the WIC image.

    Let's use the prebuilt rootfs as an example. It is located at
    <PSDK\_PATH>/linux/filesystem/tisdk-default-image-am64xx-evm.tar.xz

    ::

        cd <PSDK\_PATH>/linux/filesystem
        mkdir rootfs

    Un-tar the tisdk-default-image-am64xx-evm.tar.xz to
    <PSDK\_PATH>/linux/filesystem/rootfs

    ::

        tar -xvf tisdk-default-image-am64xx-evm.tar.xz -C rootfs

|

3.  Create a boot folder. create-sdcard-image.sh will use the boot folder to
    populate the boot partition on the WIC image.

    Let's use the prebuilt images as an example. They are located at
    <PSDK\_PATH>/linux/board-support/prebuilt-images

    ::

        mkdir boot
        cp ../board-support/prebuilt-images/tispl.bin boot
        cp ../board-support/prebuilt-images/tiboot3.bin boot
        cp ../board-support/prebuilt-images/u-boot-am64xx-evm.img boot/u-boot.img
        cp ../board-support/prebuilt-images/uEnv.txt boot

|

4.  Use create-sdcard-image.sh to generate a custom WIC file.

    You can give the WIC image any name. In this example, we will name it
    custom-image.wic.

    ::  

        ../bin/scripts/create-sdcard-image.sh boot rootfs custom-image.wic

|

5.  If you want make changes to the custom WIC image, simply make changes to the
    boot and/or rootfs folders. Then use step 4 to re-create the WIC image.

|

6.  See section :ref:`am64x-create-sd-card-with-default-images` for steps to
    write your custom WIC image to an SD card.

|

Create SD Card for RTOS or Baremetal Only Applications
------------------------------------------------------

For an RTOS or baremetal only application to boot from a SD card, the boot
partition is the only partition needed. However, you can still use an SD card
with multiple partitions. For example, the prebuilt WIC file
<PSDK\_PATH>/linux/filesystem/tisdk-default-image-am64xx-evm.wic.xz has both a
boot partition and a rootfs partition, but it can still be used for RTOS or
baremetal only applications. Just make your modifications to the boot partition
and ignore the rootfs partition.


1.  Create an SD card.

    For example, use steps in section
    :ref:`am64x-create-sd-card-with-default-images` to
    create an SD card with the prebuilt WIC image.

|

2.  Build the RTOS or baremetal applications you want to run.

    We will use the benchmark_demo as an example. Refer to
    :ref:`Benchmark-Demo-User-Guide-label` for more details.

    ::

        make common_libs benchmark_demo BUILD_LINUX_APPS=0 RTOS_ONLY_BUILD=1   (for Linux) 
        gmake common_libs benchmark_demo BUILD_LINUX_APPS=0 RTOS_ONLY_BUILD=1  (for Windows)

|

3.  Place the bootable files you generated into the SD card boot partition.

    In our example, you can find the 3 baremetal SD card bootable files in
    <PSDK\_PATH>/apps/benchmark\_demo/out/AM64X/SDCardImage

    a.  Delete all files from the SD card boot partition
    b.  Copy the 3 baremetal SD card bootable files from
        <PSDK\_PATH>/apps/benchmark\_demo/out/AM64X/SDCardImage
        to the boot partition of the SD card

|

4.  The modified SD card is now ready to be used on AM64x EVM
