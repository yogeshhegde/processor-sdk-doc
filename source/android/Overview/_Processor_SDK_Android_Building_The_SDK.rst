.. _android-building:

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

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

  Check OPTEE-OS docs to know list of dependencies needed to be installed :
  https://optee.readthedocs.io/en/latest/building/prerequisites.html

Downloading sources
===================

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

    Create a folder for downloading all sources

    .. code-block:: console

       $ mkdir ~/09_02_00 && cd $_
       $ export YOUR_PATH=$PWD

.. _android-download-bootloaders:

Bootloader components
---------------------

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

    .. code-block:: console

       $ mkdir ${YOUR_PATH}/ti-bootloader-aosp/ && cd $_
       $ git clone -b 09.02.00.009 git://git.ti.com/atf/arm-trusted-firmware.git
       $ git clone -b 09.02.00.009 git://git.ti.com/optee/ti-optee-os.git
       $ git clone -b 09.02.00.009 git://git.ti.com/ti-u-boot/ti-u-boot.git
       $ git clone -b 09.02.00.009 git://git.ti.com/processor-firmware/ti-linux-firmware.git

Kernel
------

.. ifconfig:: CONFIG_part_variant in ('AM62X' 'AM62PX')

    Fetch the code using ``repo``:

    .. code-block:: console

       $ mkdir ${YOUR_PATH}/ti-kernel-aosp/ && cd $_
       $ repo init -u git://git.ti.com/android/manifest.git -b android14-release -m releases/RLS_09_02_Kernel.xml
       $ repo sync

    .. note::

       To save some disk space, pass the ``--depth=1`` option to ``repo init``:

       .. code-block:: console

          $ repo init -u git://git.ti.com/android/manifest.git -b android14-release -m releases/RLS_09_02_Kernel.xml --depth=1

.. _android-download-aosp:

Android file system
-------------------

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

    Fetch the code using ``repo``:

    .. code-block:: console

       $ mkdir ${YOUR_PATH}/ti-aosp-14 && cd $_
       $ repo init -u git://git.ti.com/android/manifest.git -b android14-release -m releases/RLS_09_02.xml
       $ repo sync


Build Instructions
==================

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

    .. note::

        The bootloader and kernel builds below are optional if they are used as-is from TI release.
        Prebuilt copies of these binaries are already part of Android file system sources
        in ``device/ti/am62x-kernel`` and ``vendor/ti/am62x/bootloader`` folder.

.. _android-build-bootloaders:

Bootloader components
---------------------

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

    1. Build ATF:

       .. code-block:: console

          $ cd ${YOUR_PATH}/ti-bootloader-aosp/arm-trusted-firmware
          $ make E=0 CROSS_COMPILE=aarch64-none-linux-gnu- ARCH=aarch64 PLAT=k3 TARGET_BOARD=lite SPD=opteed CFLAGS+="-DK3_PM_SYSTEM_SUSPEND=1"

    2. Build OPTEE-OS:

       .. code-block:: console

          $ cd ${YOUR_PATH}/ti-bootloader-aosp/optee_os
          $ make PLATFORM=k3 CFG_ARM64_core=y CROSS_COMPILE=arm-none-linux-gnueabihf- CROSS_COMPILE64=aarch64-none-linux-gnu-


    3. Build ``tiboot3.bin``:

      .. ifconfig:: CONFIG_part_variant in ('AM62X')

         .. code-block:: console

            $ cd ${YOUR_PATH}/ti-bootloader-aosp/ti-u-boot/
            $ make ARCH=arm am62x_evm_r5_defconfig
            $ make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- \
                   BINMAN_INDIRS=${YOUR_PATH}/ti-bootloader-aosp/ti-linux-firmware

      .. ifconfig:: CONFIG_part_variant in ('AM62PX')

         .. code-block:: console

            $ cd ${YOUR_PATH}/ti-bootloader-aosp/ti-u-boot/
            $ make ARCH=arm am62px_evm_r5_defconfig
            $ make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- \
                   BINMAN_INDIRS=${YOUR_PATH}/ti-bootloader-aosp/ti-linux-firmware


    4. Build ``tispl.bin`` and ``u-boot.img``:

      .. ifconfig:: CONFIG_part_variant in ('AM62X')

         .. code-block:: console

            $ cd ${YOUR_PATH}/ti-bootloader-aosp/ti-u-boot/
            $ make ARCH=arm am62x_evm_a53_defconfig
            $ make ARCH=arm am62x_android_a53.config
            $ make ARCH=arm CROSS_COMPILE=aarch64-none-linux-gnu- \
                   BL31=${YOUR_PATH}/ti-bootloader-aosp/arm-trusted-firmware/build/k3/lite/release/bl31.bin \
                   TEE=${YOUR_PATH}/ti-bootloader-aosp/optee_os/out/arm-plat-k3/core/tee-pager_v2.bin \
                   BINMAN_INDIRS=${YOUR_PATH}/ti-bootloader-aosp/ti-linux-firmware


      .. ifconfig:: CONFIG_part_variant in ('AM62PX')

         .. code-block:: console

            $ cd ${YOUR_PATH}/ti-bootloader-aosp/ti-u-boot/
            $ make ARCH=arm am62px_evm_a53_defconfig
            $ make ARCH=arm am62x_android_a53.config
            $ make ARCH=arm CROSS_COMPILE=aarch64-none-linux-gnu- \
                   BL31=${YOUR_PATH}/ti-bootloader-aosp/arm-trusted-firmware/build/k3/lite/release/bl31.bin \
                   TEE=${YOUR_PATH}/ti-bootloader-aosp/optee_os/out/arm-plat-k3/core/tee-pager_v2.bin \
                   BINMAN_INDIRS=${YOUR_PATH}/ti-bootloader-aosp/ti-linux-firmware

    5. Copy the ``tiboot3.bin``, ``tispl.bin`` and ``u-boot.img`` generated in steps 3 and 4
       to ``${YOUR_PATH}/ti-aosp-14/vendor/ti/am62x/bootloader``.
       If not copied, the prebuilt bootloader binaries already present in ``vendor/ti/am62x/bootloader``
       will get used by ``flashall.sh`` flashing script.

    .. ifconfig:: CONFIG_part_variant in ('AM62X')

       .. note::

          To build bootloaders for AM62x LP board please do same step with this defconfig:

              - For step 3, use ``am62x_lpsk_r5_defconfig``
              - For step 4, use ``am62x_lpsk_a53_defconfig`` with same fragment

       .. note::

          To build bootloaders for the Beagle Play, follow same steps but change the defconfigs:

              - For step 3, use ``am62x_evm_r5_defconfig`` with ``am625_beagleplay_r5.config`` and ``am625_beagleplay_android_r5.config``
              - For step 4, use ``am62x_evm_a53_defconfig`` with ``am625_beagleplay_a53.config``, ``am62x_android_a53.config`` and ``am625_beagleplay_android_a53.config``

Kernel
------

Building everything from scratch
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    The kernel is compatible with all AM62x boards, such as the SK EVM and the Beagle Play.

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

   .. code-block:: console

      $ cd ${YOUR_PATH}/ti-kernel-aosp/
      $ export DIST_DIR=${YOUR_PATH}/ti-aosp-14/device/ti/am62x-kernel/kernel/6.1
      $ tools/bazel run //common:ti_dist -- --dist_dir=$DIST_DIR

   .. note::

      Android uses Kleaf, a Bazel-based build system to build the kernel.
      AOSP documentation can be found `here <https://source.android.com/docs/setup/build/building-kernels?hl=fr>`__ and
      Kleaf documentation `here  <https://android.googlesource.com/kernel/build/+/refs/heads/main/kleaf/README.md>`__

Rebuilding faster
~~~~~~~~~~~~~~~~~

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

   .. code-block:: console

      $ cd ${YOUR_PATH}/ti-kernel-aosp/
      $ export DIST_DIR=${YOUR_PATH}/ti-aosp-14/device/ti/am62x-kernel/kernel/6.1
      $ tools/bazel run --config=fast //common:ti_dist -- --dist_dir=$DIST_DIR


Defconfig/menuconfig changes
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The usual (``make menuconfig``) is done via ``bazel`` command :

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

   .. code-block:: console

      $ cd ${YOUR_PATH}/ti-kernel-aosp/
      $ tools/bazel run //common:ti_config -- menuconfig

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

   .. note::

      Users must have built the android kernel image prior to building the Android file system.
      Otherwise pre-built kernel images present in ``device/ti/am62x-kernel``
      will be used to create ``boot.img``

.. _android-build-aosp:

Android File System
-------------------

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

   .. code-block:: console

      $ cd ${YOUR_PATH}/ti-aosp-14
      $ source build/envsetup.sh
      $ lunch <BUILD_TARGET>
      $ m

Where ``BUILD_TARGET`` is listed in the table below :

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    ============================= ============================
    Android Build type            Build target
    ============================= ============================
    AM62X-SK Tablet userdebug       ``am62x-userdebug``
    AM62X-SK Tablet user            ``am62x-user``
    AM62X-SK Car userdebug          ``am62x_car-userdebug``
    AM62X-SK Car user               ``am62x_car-user``
    ============================= ============================

    The recommended ``BUILD_TARGET`` to use is ``am62x-userdebug``.

.. ifconfig:: CONFIG_part_variant in ('AM62PX')

    ============================= ============================
    Android Build type            Build target
    ============================= ============================
    AM62PX-SK Tablet userdebug       ``am62p-userdebug``
    AM62PX-SK Tablet user            ``am62p-user``
    AM62PX-SK Car userdebug          ``am62p_car-userdebug``
    AM62PX-SK Car user               ``am62p_car-user``
    ============================= ============================

    The recommended ``BUILD_TARGET`` to use is ``am62p-userdebug``.

.. note::
    By default with user images AVB feature is enabled.
    For userdebug images, if you want to enable AVB feature you need to build
    with ``TARGET_AVB_ENABLE=true`` build args:

       .. code-block::console

          $ cd ${YOUR_PATH}/ti-aosp-14
          $ source build/envsetup.sh
          $ lunch <BUILD_TARGET>
          $ m TARGET_AVB_ENABLE=true

**After building all components, refer to instruction in next section for flashing the images to EVM**

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    The android images generated for the AM62X-SK EVM are compatible with the Beagle Play board.
    For flashing the Beagle Play, see the `dedicated application note`_.

    .. _dedicated application note: ../devices/AM62X/android/Application_Notes_BeaglePlay.html
