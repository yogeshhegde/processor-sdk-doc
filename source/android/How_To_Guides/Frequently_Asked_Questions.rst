**********************************************
Frequently Asked Questions
**********************************************

.. rubric:: Frequently Asked Questions
   :name: frequently-asked-questions

.. rubric:: How do I see recently added files in the Gallery or Music
   Player app?
   :name: how-do-i-see-recently-added-files-in-the-gallery-or-music-player-app

Gallery/Music Player is not aware of files pushed via ADB at run time.
After pushing the files reboot the board to have the gallery updated.
Alternatively, to avoid a reboot, you can use the following command:
**$am broadcast -a android.intent.action.MEDIA\_MOUNTED -d
  file:///mnt/shell/emulated/0**

.. rubric:: Why does my board hang during boot if I have an empty SD
   card connected but I've flashed the eMMC?
   :name: why-does-my-board-hang-during-boot-if-i-have-an-empty-sd-card-connected-but-ive-flashed-the-emmc

The boot order of the AM572x GP EVM and the AM57xx IDK boards defaults
to checking the SD card for a bootable partition before any other
media. This means that if your SD card contains a partition with the
bootable flag set to true, and it doesn't contain MLO and u-boot.img,
then your boot process will appear to hang because the ROM bootloader
cannot find what it needs to boot in the boot partition of the SD
card.
To remedy this problem you should re-partition your SD card and make
sure that there are no bootable paritions. Utilities such as fdisk,
sfdisk, or parted can all do this from your Linux host machine.

.. rubric:: Why is an app that comes pre-installed in the TI Android SDK
   Example not working?
   :name: why-is-an-app-that-comes-pre-installed-in-the-ti-android-sdk-example-not-working

Apps that are pre-installed may not have permissions enabled by default.
Check that the proper permissions are enabled in settings > Device >
Apps > desired app (flow from Processor SDK 4.00).

