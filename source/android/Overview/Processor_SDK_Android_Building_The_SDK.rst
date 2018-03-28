**********************
Building The SDK
**********************

.. rubric:: Using the Prebuilt Release Images
   :name: using-the-prebuilt-release-images

.. rubric:: SD Card
   :name: sd-card

.. raw:: html

   <div class="block-note">

|Note|\ **Note:** Booting Android solely from the SD card is not
supported in the Processor SDK Android v4.2 release. The SD card should
only be used to run U-Boot in order to flash the onboard eMMC.

.. raw:: html

   </div>

The prebuilt release image can be found in the
'board-support/prebuilt-images/' directory of the Processor SDK Android
installation. The `create-sdcard.sh
script </index.php/Processor_SDK_Android_create_SD_card_script>`__
(found in the 'bin/' directory of the SDK) will create a bootable SD
card using the prebuilt images that you can use to boot your AM572x GP
EVM, AM571x IDK, or AM572x IDK.

.. raw:: html

   <div class="block-note">

|Note|\ **Note:** While the SD card boot method can be useful during
development, the recommended setup is to flash the kernel and Android
filesystem to the eMMC as described in the next step.

.. raw:: html

   </div>

.. raw:: html

   <div class="block-note">

|Note|\ **Note:** SD card boot is not supported on Android for
production environments.

.. raw:: html

   </div>

| 

.. rubric:: Flashing to onboard eMMC
   :name: flashing-to-onboard-emmc

| You can also use the top-level `setup.sh
  script </index.php/Processor_SDK_Android_Setup_Script>`__ to flash the
  prebuilt release images to the eMMC of your EVM or IDK.

.. raw:: html

   <div class="block-note">

|Note|\ **Note:** You will still need to use the `create-sdcard.sh
script </index.php/Processor_SDK_Android_create_SD_card_script>`__ the
first time that you flash your board. This will allow you to run u-boot
off of the SD card for your first boot and then the flashing procedure
will put u-boot into the eMMC (or QSPI on the IDKs) for subsequent
boots.

.. raw:: html

   </div>

| 

.. rubric:: Rebuilding Android from Sources
   :name: rebuilding-android-from-sources

.. rubric:: Build PC setup
   :name: build-pc-setup

You need a 64 bit Ubuntu 14.04 machine for building the Android file
system.

Install Pre-requisite packages for building the Android File System
Follow instructions from official Android page
`here <https://source.android.com/source/initializing.html#setting-up-a-linux-build-environment>`__
for setting up the packages required for building Android.

Use the following command to install the same packages that were used
during the SDK development process:

::

    sudo apt-get install git-core gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib libc6-dev-i386 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip openjdk-7-jdk lzop bc u-boot-tools

Proxy/Firewall
If you are behind proxy/firewall, workaround it using the instructions
in `[1] <http://omapedia.org/wiki/Host_PC_Setup>`__. For installing repo
make sure you also export https\_proxy environment variable.

repo tool
Google's repo tool is used to clone all of the git repositories that you
need to rebuild the full Android filesystem from source. A copy of the
repo tool is provided in the Processor SDK Android in the
**board-support/aosp-6AM.1.3/.repo/repo/** directory. Instructions to
use the repo tool are provided below in this guide.

Tool Chain for building Kernel and Drivers
The Kernel and Driver sources are built using the Android linux-x86
toolchain for ARM GNU/Linux version . This tool chain is provided in the
**android-devkit** directory of the SDK.

A note on Host binaries of Marshmallow
Host binaries like simg2img, make\_exr4fs etc.. that are built in
Android M needs shared libraries now. You might see errors like below
when trying to use those binaries

::

    simg2img: error while loading shared libraries: libc++.so: cannot open shared object file: No such file or directory

To resolve it, export your LD\_LIBRARY\_PATH to include the libraries.
Point it to either the daily build or the folder from your build system

::

    export LD_LIBRARY_PATH=~/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/board-support/aosp-6AM1.3/out/host/linux-x86/lib64/

| 

.. rubric:: U-Boot, Linux Kernel, and Android Filesystem Sources
   :name: u-boot-linux-kernel-and-android-filesystem-sources

.. rubric:: Android Filesystem Sources
   :name: android-filesystem-sources

You can get the Android filesystem sources for this release by using the
repo tool along with the provided manifest file.

::

    cd ~/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/board-support/aosp-6AM.1.3/
    ./repo sync

This command may take several hours as it is cloning hundreds of
repositories and checking them out to a specific commit. This will also
take up considerable space on your development machine's hard drive
(~70GB).

Note: The repo tool has already been initialized with the manifest file
found in
**board-support/aosp-6AM.1.3/.repo/manifests/aosp-6AM.1.3\_manifest.xml**.
That is why only the 'repo sync' command is required above.

| 

.. rubric:: TI Hardware Accelerated Graphics and MultiMedia Binaries
   :name: ti-hardware-accelerated-graphics-and-multimedia-binaries

Multimedia (DCE) and accelerated graphics binaries are part of Android
file system build

.. rubric:: U-Boot Sources
   :name: u-boot-sources

The U-Boot sources are included in the Processor Android SDK in the
**board-support/u-boot-20xx-yy.zz/** directory.

.. rubric:: Kernel & Driver Sources
   :name: kernel-driver-sources

The Linux kernel sources are included in the Processor Android SDK in
the **board-support/linux-x.y.zz/** directory.

.. rubric:: Build Instructions
   :name: build-instructions

.. rubric:: Setting up build environment
   :name: setting-up-build-environment

::

    export CROSS_COMPILE=${HOME}/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/android-devkit/arm-linux-androideabi-4.9.x-google/bin/arm-linux-androideabi-

{{note\|The lzop tool needs to be installed on Linux PC when building
Kernel using Android 4.9 toolchain. lzop should have been installed
while following the steps in `this
section </index.php/Processor_SDK_Android_Building_The_SDK#Build_PC_setup>`__
of this guide.

.. rubric:: Building U-boot sources
   :name: building-u-boot-sources

The `top-level
Makefile </index.php/Processor_SDK_Android_Top-Level_Makefile>`__ can be
used to build MLO and U-Boot

::

    cd ~/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/
    make u-boot

.. rubric:: Building Kernel
   :name: building-kernel

The `top-level
Makefile </index.php/Processor_SDK_Android_Top-Level_Makefile>`__ can
also be used to build the Linux kernel

::

    cd ~/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/
    make linux
    make linux-dtbs

.. raw:: html

   <div class="block-note">

|Note|\ **Note:** If you are making changes to kernel defconfig and need
to rebuild SGX kernel module, refer
`here </index.php/Processor_SDK_Android_Building_The_SDK#Building_SGX_Kernel_Module>`__

.. raw:: html

   </div>

| 

.. rubric:: Building Android Filesystem (AFS)
   :name: building-android-filesystem-afs

Instructions for building Android file system (Processor SDK 4.0, 4.1).

::

    cd ~/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/board-support/aosp-.../
    . build/envsetup.sh
    lunch full_am57xevm-userdebug
    make -j8 clean
    make -j8

See `Android Build
Tricks <http://elinux.org/Android_Build_System#Build_tricks>`__ for
tricks on building Android. Adjust -jX to match your build machine,
where X is the number of jobs.

| 

Instructions for building Android file system (Processor SDK 4.2 +)

.. raw:: html

   <div class="block-note">

|Note|\ **Note:** Starting with Processor SDK 4.2, users must build the
android kernel image prior to building the Android file system.

.. raw:: html

   </div>

::

    cd ~/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/board-support/aosp-.../
    export KERNELDIR=~/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/board-support/linux-.../
    . build/envsetup.sh
    lunch full_am57xevm-userdebug
    make -j8 clean
    make -j8

| 

.. rubric:: Building SGX Kernel Module
   :name: building-sgx-kernel-module

Instructions for rebuilding the SGX kernel module.

::

    cd ~/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/board-support/aosp-6AM.1.3/device/ti/proprietary-open/jacinto6/sgx_src/eurasia_km/eurasiacon/build/linux2/omap_android
    export KERNELDIR=${HOME}/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/board-support/linux-4.4.x...
    export CROSS_COMPILE=${HOME}/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/android-devkit/arm-linux-androideabi-4.9.x-google/bin/arm-linux-androideabi-
    export KERNEL_CROSS_COMPILE=${HOME}/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/android-devkit/arm-linux-androideabi-4.9.x-google/bin/arm-linux-androideabi-
    export ARCH=arm
    make TARGET_PRODUCT="am57xevm" BUILD=release

SGX module will be generated at:

::

    ~/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/board-support/aosp-6AM.1.3/device/ti/proprietary-open/jacinto6/sgx_src/eurasia_km/eurasiacon/binary2_omap_android_release/target/pvrsrvkm.ko

Use ADB to push pvrsrvkm.ko file to the **/system/lib/modules/**
location on the AM57xx target and reboot the board.

.. raw:: html

   <div class="block-note">

|Note|\ **Note:** If you get an error about the kernel configuration
then you may need to go through the steps mentioned above to build the
kernel before completing these steps.

.. raw:: html

   </div>

| 

.. rubric:: Preparing Android Image
   :name: preparing-android-image

.. rubric:: Rebuild Android Filesystem (AFS) to include kernel
   :name: rebuild-android-filesystem-afs-to-include-kernel

Copy Kernel Image (This step is for making your kernel to be part of
boot.img)

::

    cd ~/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/board-support/aosp-6AM.1.3
    cp -v ../linux-4.4.x.../arch/arm/boot/zImage device/ti/am57xevm/kernel

| 
| Rebuild AFS to generate update images

::

    cd ~/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/board-support/aosp-6AM.1.3/
    . build/envsetup.sh
    lunch full_am57xevm-userdebug
    rm out/target/product/am57xevm/*.img
    rm out/target/product/am57xevm/obj/PACKAGING/systemimage_intermediates/system.img
    make -j2

.. rubric:: Preparing eMMC binaries/images
   :name: preparing-emmc-binariesimages

::


    cd ~/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/board-support/
    mkdir emmc_files
    cp -v ./aosp-6AM.1.3/out/target/product/am57xevm/*img emmc_files
    cp -v ./aosp-6AM.1.3/device/ti/am57xevm/fastboot.sh emmc_files
    cp -v ./aosp-6AM.1.3/out/host/linux-x86/bin/{simg2img,make_ext4fs,mkbootimg,fastboot,adb} emmc_files
    cp -v ./aosp-6AM.1.3/out/host/linux-x86/lib64/{libc++.so,libcutils.so,liblog.so,libselinux.so} emmc_files
    cp -v ./linux-4.4.x.../arch/arm/boot/zImage emmc_files/kernel
    cp -v ./linux-4.4.x.../arch/arm/boot/dts/am57*.dtb emmc_files
    cp -v ./u-boot.20xx.yy.../MLO emmc_files/GP_MLO
    cp -v ./u-boot.20xx.yy.../MLO emmc_files/
    cp -v ./u-boot.20xx.yy.../u-boot.img emmc_files

.. rubric:: Flashing eMMC images
   :name: flashing-emmc-images

The default setup is to flash MLO and u-boot.img ,kernel, dtb file and
AFS to emmc.

-  Instructions are same for AM57x GP EVM and the AM57x IDK boards

.. rubric:: Flashing procedure
   :name: flashing-procedure

-  Create an SD card containing MLO and u-boot.img using the
   `create-sdcard.sh
   script </index.php/Processor_SDK_Android_create_SD_card_script>`__
   provided in the SDK and then boot the target board from this external
   SD card.
-  Connect a USB cable from the Linux PC to the micro USB port on the
   EVM

   -  There is only one micro USB port on the AM57x GP EVM
   -  On the AM57xx IDK boards you need to connect the micro USB cable
      to the micro USB port on the opposite side of the (4) RJ-45
      connectors (The other micro USB port on the IDK boards is used for
      serial communication and JTAG).

-  Power on the board and stop the board at u-boot prompt by
   interrupting with key press

::

    Hit any key to stop autoboot:  3

-  Set the right environment variables for Android SDK and save (This
   step is needed only for fresh flash, for incremental flashing this is
   optional)

::

     => env default -f -a
     => setenv partitions $partitions_android
     => env save

-  Reboot the board and stop it at the u-boot prompt again and put the
   board into fastboot mode

::

     => fastboot 1

on the host machine

::

     => cd ~/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/board-support/emmc_files
     => sudo ./fastboot oem format
     => sudo ./fastboot reboot (reboot and stop the device again in u-boot)

.. raw:: html

   <div class="block-note">

|Note|\ **Note:** If the emmc\_files directory does not exist, you need
to following the instructions in the above `Preparing eMMC
binaries/images </index.php/Processor_SDK_Android_Building_The_SDK#Preparing_eMMC_binaries.2Fimages>`__
section first.

.. raw:: html

   </div>

-  Put the board in fastboot mode by typing in below command

::

     => fastboot 1

-  On the Linux PC which has the emmc images run the fastboot.sh script
   to flash the binaries

::

     cd ~/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/board-support/emmc_files
     sudo ./fastboot.sh

-  **NOTE:** After the flashing is done, remove the external SD card and
   reboot the board.

| 

.. rubric:: Technical support
   :name: technical-support

We strongly recommend using the TI E2E forum for all queries.

E2E Support Forums for all Sitara platforms - `Click
Here <http://e2e.ti.com/support/arm/sitara_arm/f/791.aspx>`__

There could be a few cases where your query has confidential information
and cannot be posted publicly. In such cases, please contact your FAE or
CPM.

.. raw:: html

