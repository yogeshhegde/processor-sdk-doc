********************************************
Building the SDK
********************************************

Building Bootloader
===================

Fetching the source code
~~~~~~~~~~~~~~~~~~~~~~~~

::

    mkdir ~/src/ti-bootloader-aosp/ && cd $_
    git clone -b 08.03.00.005 git://git.ti.com/k3-image-gen/k3-image-gen.git
    git clone -b 08.03.00.005 https://git.ti.com/git/atf/arm-trusted-firmware.git
    git clone -b 08.03.00.005 https://git.ti.com/git/optee/ti-optee-os.git
    git clone -b 08.03.00.005 https://git.ti.com/git/ti-u-boot/ti-u-boot.git
    git clone -b 08.03.00.005 git://git.ti.com/processor-firmware/ti-linux-firmware.git

Build
~~~~~

The build is done in two stages:

1. build tiboot3.bin

::

    cd ~/src/ti-bootloader-aosp/ti-u-boot/
    make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- am62x_evm_r5_defconfig O=/tmp/r5
    make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- O=/tmp/r5
    cd ~/src/ti-bootloader-aosp/k3-image-gen
    make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- SOC=am62x SBL=/tmp/r5/spl/u-boot-spl.bin SYSFW_PATH=~/src/ti-bootloader-aosp/ti-linux-firmware/ti-sysfw/ti-fs-firmware-am62x-gp.bin

Use the tiboot3.bin generated from last command in ~/src/ti-bootloader-aosp/k3-image-gen

2. build tispl.bin and u-boot.img

In order to build tispl.bin and u-boot.img, OPTEE and ATF (arm trusted firmware) need to be built.

::

    cd ~/src/ti-bootloader-aosp/arm-trusted-firmware
    make CROSS_COMPILE=aarch64-none-linux-gnu- ARCH=aarch64 PLAT=k3 TARGET_BOARD=lite SPD=opteed
    cd ~/src/ti-bootloader-aosp/ti-optee-os
    make PLATFORM=k3 CFG_ARM64_core=y CROSS_COMPILE=arm-none-linux-gnueabihf- CROSS_COMPILE64=aarch64-none-linux-gnu-

It is now possible to generate tispl.bin and u-boot.img.

::

    cd ~/src/ti-bootloader-aosp/ti-u-boot/
    make ARCH=arm CROSS_COMPILE=aarch64-none-linux-gnu- am62x_evm_a53_defconfig O=/tmp/a53
    make ARCH=arm CROSS_COMPILE=aarch64-none-linux-gnu- ATF=~/src/ti-bootloader-aosp/arm-trusted-firmware/build/k3/lite/release/bl31.bin TEE=~/src/ti-bootloader-aosp/ti-optee-os/out/arm-plat-k3/core/tee-pager_v2.bin DM=~/src/ti-bootloader-aosp/ti-linux-firmware/ti-dm/am62xx/ipc_echo_testb_mcu1_0_release_strip.xer5f O=/tmp/a53

Use tispl.bin and u-boot.img located in /tmp/a53

Building Kernel
=====================

Fetching the kernel code
~~~~~~~~~~~~~~~~~~~~~~~~

Fetch the code using ``repo``:

::

    mkdir ~/src/ti-kernel-aosp/ && cd $_
    repo init -u https://git.ti.com/git/android/manifest.git -m kernel.xml -b android12-core-release
    repo sync

Build
~~~~~

In this section, we will assume that we already have an Android source tree which has been fully build and is located in:

::

    ~/src/ti-aosp-12

Building everything from scratch
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

::

    cd ~/src/ti-kernel-aosp/
    export DIST_DIR=~/src/ti-aosp/device/ti/am62x-prebuilts/kernel/5.10
    export BUILD_CONFIG=./imgtech-module/build.config.imgtech
    build/build.sh

Rebuilding incrementally
~~~~~~~~~~~~~~~~~~~~~~~~

Add the ``SKIP_MRPROPER=1`` flag:

::

    $ cd ~/src/ti-kernel-aosp/
    $ export DIST_DIR=~/src/ti-aosp/device/ti/am62x-prebuilts/kernel/5.10
    $ export BUILD_CONFIG=./imgtech-module/build.config.imgtech
    $ export SKIP_MRPROPER=1
    $ build/build.sh

Defconfig/menuconfig changes
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The usual (``make menuconfig`` ) is done via ``config.sh``:

::

    cd ~/src/ti-kernel-aosp/
    export BUILD_CONFIG=./imgtech-module/build.config.imgtech
    build/config.sh

.. note::

   Users must have built the
   android kernel image prior to building the Android file system.

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

Building Android
----------------

Fetching the code
~~~~~~~~~~~~~~~~~

Fetch the code using ``repo``:

::

    mkdir ~/src/ti-aosp-12 && cd $_
    repo init -u https://git.ti.com/git/android/manifest.git -b android12-core-release
    repo sync

For more information about ``repo``, visit `Android's official
documentation <https://source.android.com/setup/build/downloading>`__

Setup
~~~~~

Refer to:

-  `Android's Build
   requirements <https://source.android.com/setup/build/requirements>`__.
-  `Android's Establishing a Build
   Environment <https://source.android.com/setup/build/initializing>`__
   guide.

Build
~~~~~

::

    cd ~/src/ti-aosp-12
    source build/envsetup.sh
    lunch am62x-userdebug
    m

We also support the following build flags to enable optional features:

-  ``TARGET_AVB_ENABLE=true`` : Enable
   `AVB <https://source.android.com/security/verifiedboot/avb>`__
-  ``TARGET_VKMS_ENABLED=true`` : Enable Virtual Display

Flashing instructions
~~~~~~~~~~~~~~~~~~~~~

Once build is complete, prepare your eMMc binairies and images:

1. Change Boot mode DIP switches for SD card boot.

::

   Revision E1:
    Boot mode DIP Switch:
    SW1: 01000011 SW2: 00010010

   Revision E2:
    Boot mode DIP Switch:
    SW1: 11000010 SW2: 01000000

2. Ensure the device is plugged in with USB Host and Debug UART/Serial Debug


3. Boot the board with tiboot3.bin, u-boot.img, tispl.bin files in
boot partition of SD card.


4. Open a terminal debugger to view console output from the device:

::

    sudo picocom -b 115200 -r -l /dev/ttyUSB0

5. Setup Android partition table:(Need to be removed after hardcoding it on the uboot source code)

::

    env default -f -a
    run set_android_boot

6. Enable fastboot on the device through the terminal debugger:

::

    => fastboot 0

7. In a different terminal, change directory to ``out/target/product/am62x`` and run the ``flashall.sh`` script:

::

    cd out/target/product/am62x
    sudo ./flashall.sh;

8.Power off the board and remove the SD card.


9. Change Boot mode DIP switches to boot from eMMC user partitions and power cycle the board:

::

   Revision E1:
    Boot mode DIP Switch:
    SW1: 01000011 SW2: 0000000

   Revision E2:
    Boot mode DIP Switch:
    SW1: 11000010 SW2: 00000000
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

|


