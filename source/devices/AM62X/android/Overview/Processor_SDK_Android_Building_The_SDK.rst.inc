********************************************
Building the SDK
********************************************

.. note::

    The bootloader as well as the kernel builds are optional if you haven't modified anything in them.
    

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

Building Android File System
=================================

| 

U-Boot, Linux Kernel, and Android Filesystem Sources
------------------------------------------------------

Setup
~~~~~

Please refer to the following pages to setup your environment for AOSP build:

-  `Android's Build
   requirements <https://source.android.com/setup/build/requirements>`__.
-  `Android's Establishing a Build
   Environment <https://source.android.com/setup/build/initializing>`__
   guide.

**Getting the Repo tool**

You will need the Repo tool to retrieve repositories.
To install it, please refer to this webpage : https://source.android.com/setup/develop#installing-repo

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

Build
~~~~~

::

    cd ~/src/ti-aosp-12
    source build/envsetup.sh
    lunch am62x-userdebug
    m


.. rubric:: TI Hardware Accelerated Graphics Binaries
   :name: ti-hardware-accelerated-graphics-binaries

Accelerated graphics binaries are part of Android file system build.

|


