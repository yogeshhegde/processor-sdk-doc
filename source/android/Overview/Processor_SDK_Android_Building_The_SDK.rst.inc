********************************************
Building the SDK
********************************************

Using the Prebuilt Release Images
==================================

The prebuilt release image can be found in the
'board-support/prebuilt-images/' directory of the Processor SDK Android
installation.

Follow the `create-sdcard.sh
script <Overview_Getting_Started_Guide.html#sd-card-creation>`__
(found in the 'bin/' directory of the SDK) to create a bootable SD
card. Then, use the top-level `setup.sh
script <Overview_Getting_Started_Guide.html#run-setup-scripts>`__ to flash the
prebuilt release images to the eMMC of your EVM or IDK.

.. note::

   Booting Android solely from the SD card is not
   supported starting from the Processor SDK Android v4.2 release. The SD card
   is used to run U-Boot in order to flash the onboard eMMC.

.. note::

   For AM572x EVM, the flashing procedure will put u-boot into the eMMC for
   subsequent boots, and therefore, SD card is required for the first boot only.
   For AM57xx IDK, u-boot is not flashed, and the SD card (with the boot
   files) is required always.

| 

Rebuilding Android from Sources
=================================

Follow the steps below to rebuild Android from sources when there is a need to do so,
e.g., after modifications are made for the sources.

Build PC setup
----------------

You need a 64-bit Ubuntu machine (`Version Supported <Release_Specific_Supported_Platforms_and_Versions.html>`__) for building the Android file
system.

**Install Pre-requisite packages for building the Android File System**

Follow instructions from official Android page
`here <https://source.android.com/source/initializing.html#setting-up-a-linux-build-environment>`__
for setting up the packages required for building Android.

Use the following command to install the same packages that were used
during the SDK development process:

::

    sudo apt-get install git-core gnupg flex bison gperf build-essential zip curl zlib1g-dev gcc-multilib g++-multilib libc6-dev-i386 lib32ncurses5-dev x11proto-core-dev libx11-dev lib32z-dev ccache libgl1-mesa-dev libxml2-utils xsltproc unzip lzop bc u-boot-tools libssl-dev

**Proxy/Firewall**

If you are behind proxy/firewall, workaround it using the instructions
in `Host PC Setup <http://omapedia.org/wiki/Host_PC_Setup>`__. For installing repo
make sure you also export https\_proxy environment variable.

**repo Tool**

Google's repo tool is used to clone all of the git repositories that you
need to rebuild the full Android filesystem from source. A copy of the
repo tool is provided in the Processor SDK Android in the
**board-support/aosp-<ver>/.repo/repo/** directory. Instructions to
use the repo tool are provided below in this guide.

**Tool Chain for building Kernel and Drivers**

The Kernel and Driver sources are built using the Android linux-x86
toolchain for ARM GNU/Linux version . This tool chain is provided in the
**android-devkit** directory of the SDK.

| 

U-Boot, Linux Kernel, and Android Filesystem Sources
------------------------------------------------------

.. rubric:: Android Filesystem Sources
   :name: android-filesystem-sources

You can get the Android filesystem sources for this release by using the
repo tool along with the provided manifest file.

::

    cd ~/ti-processor-sdk-android-<platform>-<ver>/board-support/aosp-<ver>/
    ./repo sync

This command may take several hours as it is cloning hundreds of
repositories and checking them out to a specific commit. This will also
take up considerable space on your development machine's hard drive
(~70GB).

.. note::

   The repo tool has already been initialized with the manifest file
   found in **board-support/aosp-<ver>/.repo/manifest.xml**.
   That is why only the 'repo sync' command is required above.

| 

.. rubric:: TI Hardware Accelerated Graphics Binaries
   :name: ti-hardware-accelerated-graphics-binaries

Accelerated graphics binaries are part of Android file system build.

.. rubric:: U-Boot Sources
   :name: u-boot-sources

The U-Boot sources are included in the Processor Android SDK in the
**board-support/u-boot-<ver>/** directory.

.. rubric:: Kernel & Driver Sources
   :name: kernel-driver-sources

The Linux kernel sources are included in the Processor Android SDK in
the **board-support/linux-<ver>/** directory.

Build Instructions
--------------------

Setting up build environment
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

::

    export CROSS_COMPILE=${HOME}/ti-processor-sdk-android-<platform>-<ver>/android-devkit/arm-linux-gnueabihf-<ver>/bin/arm-linux-gnueabihf-

Building U-boot sources
^^^^^^^^^^^^^^^^^^^^^^^^

The `top-level
Makefile <Overview_Directory_Structure.html#top-level-makefile>`__ can be
used to build MLO and U-Boot

::

    cd ~/ti-processor-sdk-android-<platform>-<ver>/
    make u-boot

Building Kernel
^^^^^^^^^^^^^^^^^^

The `top-level
Makefile <Overview_Directory_Structure.html#top-level-makefile>`__ can
also be used to build the Linux kernel

::

    cd ~/ti-processor-sdk-android-<platform>-<ver>/
    make linux
    make linux-dtbs

| 

Building Android Filesystem (AFS)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. note::

   Users must have built the
   android kernel image prior to building the Android file system.

**Instructions for building Android file system for AM5:**

::

    cd ~/ti-processor-sdk-android-am57xx-evm-<ver>/board-support/aosp-<ver>/
    export KERNELDIR=~/ti-processor-sdk-android-am57xx-evm-<ver>/board-support/linux-<ver>/
    make -j8 clean
    . build/envsetup.sh
    lunch am57xevm_full-userdebug
    make -j8


**Instructions for building Android file system for AM6:**

::

    cd ~/ti-processor-sdk-android-am65xx-evm-<ver>/board-support/aosp-<ver>/
    export KERNELDIR=~/ti-processor-sdk-android-am65xx-evm-<ver>/board-support/linux-<ver>/
    make -j8 clean
    . build/envsetup.sh
    lunch am65xevm_full-userdebug
    make -j8


See `Android Build
Tricks <http://elinux.org/Android_Build_System#Build_tricks>`__ for
tricks on building Android. Adjust -jX to match your build machine,
where X is the number of jobs.

|

Preparing Android Image
------------------------

This step is to rebuild Android Filesystem (AFS) to include kernel,
making your kernel to be part of boot.img

**Copy Kernel Image:**

::

    cd ~/ti-processor-sdk-android-<platform>-<ver>/board-support/aosp-<ver>
    cp -v ../linux-<ver>/arch/arm/boot/zImage device/ti/<platform>/kernel

**Rebuild AFS to generate update images for AM5:**

::

    cd ~/ti-processor-sdk-android-am57xx-evm-<ver>/board-support/aosp-<ver>/
    . build/envsetup.sh
    lunch am57xevm_full-userdebug
    rm out/target/product/am57xevm/*.img
    rm out/target/product/am57xevm/obj/PACKAGING/systemimage_intermediates/system.img
    make -j2

**Rebuild AFS to generate update images for AM6:**

::

    cd ~/ti-processor-sdk-android-am65xx-evm-<ver>/board-support/aosp-<ver>/
    . build/envsetup.sh
    lunch am65xevm_full-userdebug
    rm out/target/product/am65xevm/*.img
    rm out/target/product/am65xevm/obj/PACKAGING/systemimage_intermediates/system.img
    make -j2

Flashing eMMC images
=======================

Preparing eMMC binaries/images
-------------------------------

Make a copy of the prebuilt-images directory, and then copy over the rebuilt files to the prebuilt-images directory.

**AM5:**

::

    cd ~/ti-processor-sdk-android-am57xx-evm-<ver>/board-support/
    cp -r prebuilt-images prebuilt-images-psdk
    cp -v ./aosp-<ver>/out/target/product/am57xevm/*img prebuilt-images
    cp -v ./aosp-<ver>/device/ti/am57xevm/fastboot.sh prebuilt-images
    cp -v ./aosp-<ver>/out/host/linux-x86/bin/{simg2img,make_ext4fs,mkbootimg,fastboot,adb} prebuilt-images
    cp -v ./aosp-<ver>/out/host/linux-x86/lib64/{libc++.so,libcutils.so,liblog.so,libselinux.so} prebuilt-images
    cp -v ./linux-<ver>/arch/arm/boot/zImage prebuilt-images/zImage-am57xx-evm.bin
    cp -v ./linux-<ver>/arch/arm/boot/dts/am57*.dtb prebuilt-images
    cp -v ./u-boot-<ver>/MLO prebuilt-images
    cp -v ./u-boot-<ver>/u-boot.img prebuilt-images

**AM6:**

::

    cd ~/ti-processor-sdk-android-am65xx-evm-<ver>/board-support/
    cp -r prebuilt-images prebuilt-images-psdk
    cp -v ./aosp-<ver>/out/target/product/am65xevm/*img prebuilt-images
    cp -v ./aosp-<ver>/device/ti/am65xevm/fastboot.sh prebuilt-images
    cp -v ./aosp-<ver>/out/host/linux-x86/bin/{simg2img,mkbootimg,fastboot,adb} prebuilt-images
    cp -v ./aosp-<ver>/out/host/linux-x86/lib64/{libc++.so,libcutils.so,liblog.so,libselinux.so,libpcre2.so} prebuilt-images
    cp -v ./u-boot_build/a53/u-boot.img prebuilt-images
    cp -v ./u-boot_build/a53/tispl.bin prebuilt-images
    cp -v ./u-boot_build/r5/tiboot3.bin prebuilt-images

Flashing procedure
----------------------

-  Create an SD card containing MLO and u-boot.img using the
   `create-sdcard.sh
   script <Overview_Getting_Started_Guide.html#sd-card-creation>`__
   provided in the SDK and then boot the target board from this external
   SD card.

-  Follow `Run Setup Scripts <Overview_Getting_Started_Guide.html#run-setup-scripts>`__
   to flash the rebuilt images (which have been copied to the prebuilt-images directory in the step above)
   to the onboard eMMC.
