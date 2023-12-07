********************************************
Building the SDK
********************************************

Build PC setup
==============

Please refer to the following pages from Android documentation to setup your environment for Android build:

-  `Android's Build
   requirements <https://source.android.com/setup/build/requirements>`__.
-  `Android's Establishing a Build
   Environment <https://source.android.com/setup/build/initializing>`__
   guide.


**Getting the repo tool**

You will need the ``repo`` tool to retrieve repositories.
To install it, please refer to this webpage : https://source.android.com/setup/develop#installing-repo

**Getting toolchain for u-boot builds**

Links to download toolchains for building u-boot are mentioned in the SDK download page.

**Install OPTEE-OS build dependencies**

.. ifconfig:: CONFIG_part_variant in ('AM62X')

  Check OPTEE-OS docs to know list of dependencies needed to be installed :
  https://optee.readthedocs.io/en/latest/building/prerequisites.html

Downloading sources
===================

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    Create a folder for downloading all sources

    ::

        mkdir ~/09_01_00 && cd $_
        export YOUR_PATH=$PWD

Bootloader components
---------------------

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    ::

        mkdir ${YOUR_PATH}/ti-bootloader-aosp/ && cd $_
        git clone -b 09.01.00.008 git://git.ti.com/atf/arm-trusted-firmware.git
        git clone -b 3.22.0-rc1 https://github.com/OP-TEE/optee_os.git
        git clone -b 09.01.00.008 git://git.ti.com/ti-u-boot/ti-u-boot.git
        git clone -b 09.01.00.008 git://git.ti.com/processor-firmware/ti-linux-firmware.git

Kernel
------

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    Fetch the code using ``repo``::

        mkdir ${YOUR_PATH}/ti-kernel-aosp/ && cd $_
        repo init -u git://git.ti.com/android/manifest.git -b android14-release -m releases/RLS_09_01_Kernel.xml
        repo sync

    .. note::

        To save some disk space, pass the ``--depth=1`` option to ``repo init``::

            repo init -u git://git.ti.com/android/manifest.git -b android14-release -m releases/RLS_09_01_Kernel.xml --depth=1


Android file system
-------------------

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    Fetch the code using ``repo``::

        mkdir ${YOUR_PATH}/ti-aosp-14 && cd $_
        repo init -u git://git.ti.com/android/manifest.git -b android14-release -m releases/RLS_09_01.xml
        repo sync


Build Instructions
==================

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    .. note::

        The bootloader and kernel builds below are optional if they are used as-is from TI release.
        Prebuilt copies of these binaries are already part of Android file system sources
        in ``device/ti/am62x-kernel`` and ``vendor/ti/am62x/bootloader`` folder.


Bootloader components
---------------------

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    1. Build ATF::

        cd ${YOUR_PATH}/ti-bootloader-aosp/arm-trusted-firmware
        make E=0 CROSS_COMPILE=aarch64-none-linux-gnu- ARCH=aarch64 PLAT=k3 TARGET_BOARD=lite SPD=opteed CFLAGS+="-DK3_PM_SYSTEM_SUSPEND=1"

    2. Build OPTEE-OS::

        cd ${YOUR_PATH}/ti-bootloader-aosp/ti-optee-os
        make PLATFORM=k3 CFG_ARM64_core=y CROSS_COMPILE=arm-none-linux-gnueabihf- CROSS_COMPILE64=aarch64-none-linux-gnu-

    3. Build ``tiboot3.bin``::

        cd ${YOUR_PATH}/ti-bootloader-aosp/ti-u-boot/
        make ARCH=arm am62x_evm_r5_defconfig
        make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- \
             BINMAN_INDIRS=${YOUR_PATH}/ti-bootloader-aosp/ti-linux-firmware

    4. Build ``tispl.bin`` and ``u-boot.img``::

        cd ${YOUR_PATH}/ti-bootloader-aosp/ti-u-boot/
        make ARCH=arm am62x_evm_a53_defconfig
        make ARCH=arm am62x_android_a53.config
        make ARCH=arm CROSS_COMPILE=aarch64-none-linux-gnu- \
            BL31=${YOUR_PATH}/ti-bootloader-aosp/arm-trusted-firmware/build/k3/lite/release/bl31.bin \
            TEE=${YOUR_PATH}/ti-bootloader-aosp/optee_os/out/arm-plat-k3/core/tee-pager_v2.bin \
            BINMAN_INDIRS=${YOUR_PATH}/ti-bootloader-aosp/ti-linux-firmware

    5. Copy the ``tiboot3.bin``, ``tispl.bin`` and ``u-boot.img`` generated in steps 3 and 4
       to ``${YOUR_PATH}/ti-aosp-14/vendor/ti/am62x/bootloader``.
       If not copied, the prebuilt bootloader binaries already present in ``vendor/ti/am62x/bootloader``
       will get used by ``flashall.sh`` flashing script.

    .. note ::
        To build bootloaders for AM62x LP board please do same step with this defconfig:

            - For step 3 use ``am62x_lpsk_r5_defconfig``
            - For step 4 use ``am62x_lpsk_a53_defconfig`` with same fragment

Kernel
------

Building everything from scratch
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    ::

        cd ${YOUR_PATH}/ti-kernel-aosp/
        export DIST_DIR=${YOUR_PATH}/ti-aosp-14/device/ti/am62x-kernel/kernel/6.1
        tools/bazel run //common:ti_dist -- --dist_dir=$DIST_DIR

    .. note::

        Android move on Kleaf bazel build system, AOSP documentation can be read `here <https://source.android.com/docs/setup/build/building-kernels?hl=fr>`__ and Kleaf documentation `here  <https://android.googlesource.com/kernel/build/+/refs/heads/main/kleaf/README.md>`__

Rebuilding faster
~~~~~~~~~~~~~~~~~

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    ::

        cd ${YOUR_PATH}/ti-kernel-aosp/
        export DIST_DIR=${YOUR_PATH}/ti-aosp-14/device/ti/am62x-kernel/kernel/6.1
        tools/bazel run --config=fast //common:ti_dist -- --dist_dir=$DIST_DIR


Defconfig/menuconfig changes
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The usual (``make menuconfig`` ) is done via ``bazel`` command :

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    ::

        cd ${YOUR_PATH}/ti-kernel-aosp/
        tools/bazel run //common:ti_config -- menuconfig

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    .. note::

           Users must have built the android kernel image prior to building the Android file system.
           Otherwise pre-built kernel images present in ``device/ti/am62x-kernel``
           will be used to create ``boot.img``


Android File System
-------------------

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    ::

        cd ${YOUR_PATH}/ti-aosp-14
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
============================= ============================

.. note::
    Default BUILD_TARGET to use is ``am62x-userdebug``

.. note::
    By default with user images AVB feature is enabled.
    For userdebug images, if you want to enable AVB feature you need to build
    with ``TARGET_AVB_ENABLE=true`` build args::

        cd ${YOUR_PATH}/ti-aosp-14
        lunch <BUILD_TARGET>
        m TARGET_AVB_ENABLE=true

**After building all components, refer to instruction in next section for flashing the images to EVM**
