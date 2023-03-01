********************************************
Building the SDK
********************************************

Build PC Setup
===============

Please refer to the following pages from Android documentatio to setup your environment for Android build:

-  `Android's Build
   requirements <https://source.android.com/setup/build/requirements>`__.
-  `Android's Establishing a Build
   Environment <https://source.android.com/setup/build/initializing>`__
   guide.


**Getting the Repo tool**

You will need the Repo tool to retrieve repositories.
To install it, please refer to this webpage : https://source.android.com/setup/develop#installing-repo

**Getting toolchain for u-boot builds**

Links to download toolchains for building u-boot is mentioned in the SDK download page.


Downloading Sources
===================

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    Create a folder for downloading all sources

    ::

        mkdir ~/08_06_00 && cd $_
        export YOUR_PATH=$PWD

Bootloader components
---------------------

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    ::

        mkdir ${YOUR_PATH}/ti-bootloader-aosp/ && cd $_
        git clone -b 08.06.00.007 git://git.ti.com/k3-image-gen/k3-image-gen.git
        git clone -b 08.06.00.007 git://git.ti.com/atf/arm-trusted-firmware.git
        git clone -b 08.06.00.007-android git://git.ti.com/optee/ti-optee-os.git
        git clone -b 08.06.00.007-android git://git.ti.com/ti-u-boot/ti-u-boot.git
        git clone -b 08.06.00.007 git://git.ti.com/processor-firmware/ti-linux-firmware.git
        git clone -b 08.06.00.007 git://git.ti.com/security-development-tools/core-secdev-k3.git

Kernel
------

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    Fetch the code using ``repo``:

    ::

        mkdir ${YOUR_PATH}/ti-kernel-aosp/ && cd $_
        repo init -u git://git.ti.com/android/manifest.git -b android12-core-release -m releases/RLS_08_06_Kernel.xml
        repo sync


Android File System
-------------------

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    Fetch the code using ``repo``:

    ::

        mkdir ${YOUR_PATH}/ti-aosp-12 && cd $_
        repo init -u git://git.ti.com/android/manifest.git -b android12-core-release -m releases/RLS_08_06.xml
        repo sync



Build Instructions
==================

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    .. note::

        The Bootloader and Kernel builds below are optional if they are used as is from TI relase. Prebuilt copies of these
        binaries are already part of Android file system sources in ``device/ti/am62x-kernel`` and
        ``vendor/ti/am62x/bootloader`` folder.


Bootloader components
---------------------

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    1. Build tiboot3.bin

    ::

        export TI_SECURE_DEV_PKG="${YOUR_PATH}/core-secdev-k3"
        cd ${YOUR_PATH}/ti-bootloader-aosp/ti-u-boot/
        make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- am62x_evm_r5_defconfig O=/tmp/r5
        make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- O=/tmp/r5
        cd ${YOUR_PATH}/ti-bootloader-aosp/k3-image-gen
        make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- SOC=am62x SOC_TYPE=gp CONFIG=evm SBL=/tmp/r5/spl/u-boot-spl.bin SYSFW_PATH=${YOUR_PATH}/ti-bootloader-aosp/ti-linux-firmware/ti-sysfw/ti-fs-firmware-am62x-gp.bin

    Use the tiboot3.bin generated from last command in ${YOUR_PATH}/ti-bootloader-aosp/k3-image-gen

    .. note::

        To build tiboot3 for HS-FS board change ``SOC_TYPE=gp`` by ``SOC_TYPE=hs-fs`` in make command

    2. Build tispl.bin and u-boot.img

    In order to build tispl.bin and u-boot.img, OPTEE and ATF (arm trusted firmware) need to be built.

    ::

        cd ${YOUR_PATH}/ti-bootloader-aosp/arm-trusted-firmware
        make CROSS_COMPILE=aarch64-none-linux-gnu- ARCH=aarch64 PLAT=k3 TARGET_BOARD=lite SPD=opteed CFLAGS+="-DK3_PM_SYSTEM_SUSPEND=1"
        cd ${YOUR_PATH}/ti-bootloader-aosp/ti-optee-os
        make PLATFORM=k3 CFG_ARM64_core=y CROSS_COMPILE=arm-none-linux-gnueabihf- CROSS_COMPILE64=aarch64-none-linux-gnu-

    It is now possible to generate tispl.bin and u-boot.img.

    ::

        cd ${YOUR_PATH}/ti-bootloader-aosp/ti-u-boot/
        make ARCH=arm CROSS_COMPILE=aarch64-none-linux-gnu- am62x_evm_a53_defconfig O=/tmp/a53
        make ARCH=arm CROSS_COMPILE=aarch64-none-linux-gnu- ATF=${YOUR_PATH}/ti-bootloader-aosp/arm-trusted-firmware/build/k3/lite/release/bl31.bin TEE=${YOUR_PATH}/ti-bootloader-aosp/ti-optee-os/out/arm-plat-k3/core/tee-pager_v2.bin DM=${YOUR_PATH}/ti-bootloader-aosp/ti-linux-firmware/ti-dm/am62xx/ipc_echo_testb_mcu1_0_release_strip.xer5f O=/tmp/a53

    Use tispl.bin and u-boot.img located in /tmp/a53

    3. Copy the tiboot3.bin, tispl.bin and u-boot.img generated in steps 1 and 2 to ``${YOUR_PATH}/ti-aosp-12/vendor/ti/am62x/bootloader``. If not copied, the prebuilt bootloader binaries already present in vendor/ti/am62x/bootloader will get use by flashall.sh flashing script.


Kernel
------

Building everything from scratch
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    ::

        cd ${YOUR_PATH}/ti-kernel-aosp/
        export DIST_DIR=${YOUR_PATH}/ti-aosp/device/ti/am62x-kernel/kernel/5.10
        export BUILD_CONFIG=./common/build.config.ti
        build/build.sh

Rebuilding incrementally
~~~~~~~~~~~~~~~~~~~~~~~~

Add the ``SKIP_MRPROPER=1`` flag:

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    ::

        $ cd ${YOUR_PATH}/ti-kernel-aosp/
        $ export DIST_DIR=${YOUR_PATH}/ti-aosp/device/ti/am62x-prebuilts/kernel/5.10
        $ export BUILD_CONFIG=./common/build.config.ti
        $ export SKIP_MRPROPER=1
        $ build/build.sh

Defconfig/menuconfig changes
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The usual (``make menuconfig`` ) is done via ``config.sh``:

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    ::

        cd ${YOUR_PATH}/ti-kernel-aosp/
        export BUILD_CONFIG=./common/build.config.ti
        build/config.sh

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    .. note::

           Users must have built the android kernel image prior to building the Android file system.
           Otherwise pre-built Kernel images present in ``device/ti/am62x-kernel`` will be used to create ``boot.img``

Building the kernel without Android project code
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Download and extract the prebuilt binaries following : :ref:`android-prebuilts` and start building the kernel by running the following commands.

    ::

        cd ${YOUR_PATH}/ti-kernel-aosp/
        export BUILD_CONFIG=./common/build.config.ti
        export PREBUILT_BOOTIMG=<PATH/TO/ANDROID/PREBUILT/BINARIES/boot.img>
        build/build.sh

The new boot image will be located in ``${YOUR_PATH}/ti-kernel-aosp/out/android13-5.10/``

Please refer to : :ref:`android-flash_boot_image` to flash the new kernel.

Android File System
-------------------

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    ::

        cd ${YOUR_PATH}/ti-aosp-12
        lunch <BUILD_TARGET>
        m

Where ``BUILD_TARGET`` is listed in the table below :

============================= ============================
Android Build type            Build target
============================= ============================
AM62X-SK Tablet userdebug       ``am62x-userdebug``
AM62X-SK Tablet user            ``am62x-user``
AM62X-SK Car userdebug          ``am62x_car-userdebug``
AM62X-SK Car user               ``am62x_car-user``
AM62X-LP-SK Tablet userdebug    ``am62x_lp-userdebug``
AM62X-LP-SK Tablet user         ``am62x_lp-user``
AM62X-LP-SK Car userdebug       ``am62x_lp_car-userdebug``
AM62X-LP-SK Car user            ``am62x_lp_car-user``
============================= ============================

.. note::
    Default BUILD_TARGET to use is ``am62x-userdebug``

.. note::
    By default with User images AVB feature was enabled.
    For userdebug images if you want to enable AVB feature you need to build with ``TARGET_AVB_ENABLE=true`` build args
    ::

        cd ${YOUR_PATH}/ti-aosp-12
        lunch <BUILD_TARGET>
        m TARGET_AVB_ENABLE=true

.. note::
   Follow this link if you want to build and test in `Android Generic Kernel Image mode`_.

.. _Android Generic Kernel Image mode: ../devices/AM62X/android/Application_Notes_GKI_support.html

**After building all components, refer to instruction in next section for flashing the images to EVM**
