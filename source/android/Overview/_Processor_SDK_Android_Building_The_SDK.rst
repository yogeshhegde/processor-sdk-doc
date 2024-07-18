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

       $ mkdir ~/10_00_00 && cd $_
       $ export YOUR_PATH=$PWD

.. _android-download-aosp:

Android file system
-------------------

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

    Fetch the code using ``repo``:

    .. code-block:: console

       $ mkdir ${YOUR_PATH}/ti-aosp-14 && cd $_
       $ repo init -u git://git.ti.com/android/manifest.git -b android14-release -m releases/RLS_10_00.xml
       $ repo sync

Kernel
------

.. ifconfig:: CONFIG_part_variant in ('AM62X' 'AM62PX')

    Fetch the code using ``repo``:

    .. code-block:: console

       $ mkdir ${YOUR_PATH}/ti-kernel-aosp/ && cd $_
       $ repo init -u git://git.ti.com/android/manifest.git -b android14-release -m releases/RLS_10_00_Kernel.xml
       $ repo sync

    .. note::

       To save some disk space, pass the ``--depth=1`` option to ``repo init``:

       .. code-block:: console

          $ repo init -u git://git.ti.com/android/manifest.git -b android14-release -m releases/RLS_10_00_Kernel.xml --depth=1

    A preview for the ``android15-6.6`` kernel is also available for testing via a dedicated manifest:

    .. code-block:: console

       $ repo init -u git://git.ti.com/android/manifest.git -b android14-release -m releases/RLS_10_00_Kernel-6.6.xml


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


Build Instructions
==================

.. _android-build-aosp:

Android File System
-------------------

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

   .. code-block:: console

      $ cd ${YOUR_PATH}/ti-aosp-14
      $ source build/envsetup.sh
      $ lunch <BUILD_TARGET>
      $ m

Where ``<BUILD_TARGET>`` is listed in the table below :

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    ============================= ============================
    Android Build type            Build target
    ============================= ============================
    AM62X-SK Tablet userdebug       ``am62x-userdebug``
    AM62X-SK Tablet user            ``am62x-user``
    AM62X-SK Car userdebug          ``am62x_car-userdebug``
    AM62X-SK Car user               ``am62x_car-user``
    ============================= ============================

    The recommended ``<BUILD_TARGET>`` to use is ``am62x-userdebug``.

.. ifconfig:: CONFIG_part_variant in ('AM62PX')

    ============================= ============================
    Android Build type            Build target
    ============================= ============================
    AM62PX-SK Tablet userdebug       ``am62p-userdebug``
    AM62PX-SK Tablet user            ``am62p-user``
    AM62PX-SK Car userdebug          ``am62p_car-userdebug``
    AM62PX-SK Car user               ``am62p_car-user``
    ============================= ============================

    The recommended ``<BUILD_TARGET>`` to use is ``am62p-userdebug``.

It's possible to customize the standard build (``m``), by passing build flags.
For example, the following enables AVB on userdebug builds:

.. code-block:: console

  $ TARGET_AVB_ENABLE=true m

The following build flags are available. **Default** values are **highlighted**.

.. list-table::
   :header-rows: 1

   * - Flag
     - Possible values
     - Description
   * - ``TARGET_AVB_ENABLE``
     - **false**/true
     - Forces AVB feature on userdebug
   * - ``TARGET_ADB_USER_ENABLE``
     - **false**/true
     - Forces enable ADB on user builds (**NOT for production builds**)
   * - ``TARGET_SDCARD_BOOT``
     - **false**/true
     - Boot from SD card instead of eMMC
   * - ``TARGET_KERNEL_USE``
     - **6.1**/6.6
     - Pick kernel version. 6.6 is experimental

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

   After building is complete, the necessary images will be available in
   ``${YOUR_PATH}/ti-aosp-14/out/target/product/am62*/``.

   The bootloader and kernel builds below are optional if they are used as-is from TI release.
   Prebuilt copies of these binaries are already part of Android file system sources
   in ``device/ti/am62x-kernel`` and ``vendor/ti/am62x/bootloader`` folder.
   To proceed to flash Android, see :ref:`android-flashing`.


Kernel
------

Building everything from scratch
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    The kernel is compatible with all AM62x boards, such as the SK EVM and the Beagle Play.

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

   .. code-block:: console

      $ cd ${YOUR_PATH}/ti-kernel-aosp/
      $ export TARGET_KERNEL_USE="6.1" # or "6.6" for experimental kernel
      $ export DIST_DIR=${YOUR_PATH}/ti-aosp-14/device/ti/am62x-kernel/kernel/${TARGET_KERNEL_USE}
      $ tools/bazel run //common:ti_dist -- --dist_dir=$DIST_DIR

Android uses Kleaf, a Bazel-based build system to build the kernel.
AOSP documentation can be found `here <https://source.android.com/docs/setup/build/building-kernels?hl=fr>`__ and
Kleaf documentation `here  <https://android.googlesource.com/kernel/build/+/refs/heads/main/kleaf/README.md>`__

Rebuilding faster
~~~~~~~~~~~~~~~~~

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

   .. code-block:: console

      $ cd ${YOUR_PATH}/ti-kernel-aosp/
      $ export TARGET_KERNEL_USE="6.1" # or "6.6" for experimental kernel
      $ export DIST_DIR=${YOUR_PATH}/ti-aosp-14/device/ti/am62x-kernel/kernel/${TARGET_KERNEL_USE}
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

.. _android-build-bootloaders:

Bootloader components
---------------------

Building the bootloaders is similar to the upstream procedure.
For detailed information, see `k3 upstream documentation <https://docs.u-boot.org/en/latest/board/ti/k3.html#build-procedure>`__.

0. Start setting up the generic environment variables:

   .. code-block:: console

      $ export CC32=arm-none-linux-gnueabihf-
      $ export CC64=aarch64-none-linux-gnu-
      $ export LNX_FW_PATH=${YOUR_PATH}/ti-bootloaders-aosp/ti-linux-firmware
      $ export TFA_PATH=${YOUR_PATH}/ti-bootloader-aosp/arm-trusted-firmware
      $ export OPTEE_PATH=${YOUR_PATH}/ti-bootloader-aosp/ti-optee-os
      $ export UBOOT_PATH=${YOUR_PATH}/ti-bootloader-aosp/ti-u-boot

1. Then, configure the board specific environment variables

   .. ifconfig:: CONFIG_part_variant in ('AM62X')

      For AM62x SK EVM, use:

      .. code-block:: console

         $ export UBOOT_CFG_CORTEXR=am62x_evm_r5_defconfig
         $ export UBOOT_CFG_CORTEXA="am62x_evm_a53_defconfig am62x_android_a53.config"

      For AM62x LP SK EVM, use:

      .. code-block:: console

         $ export UBOOT_CFG_CORTEXR=am62x_lpsk_r5_defconfig
         $ export UBOOT_CFG_CORTEXA="am62x_lpsk_a53_defconfig am62x_android_a53.config"

      For Beagle Play, use:

      .. code-block:: console

         $ export UBOOT_CFG_CORTEXR="am62x_evm_r5_defconfig am625_beagleplay_r5.config am625_beagleplay_android_r5.config"
         $ export UBOOT_CFG_CORTEXA="am62x_evm_a53_defconfig am625_beagleplay_a53.config am62x_android_a53.config am625_beagleplay_android_a53.config"


   .. ifconfig:: CONFIG_part_variant in ('AM62PX')

      .. code-block:: console

         $ export UBOOT_CFG_CORTEXR=am62px_evm_r5_defconfig
         $ export UBOOT_CFG_CORTEXA="am62px_evm_a53_defconfig am62x_android_a53.config"

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

    2. Build ATF:

       .. code-block:: console

          $ cd ${TFA_PATH}
          $ make E=0 CROSS_COMPILE=$CC64 ARCH=aarch64 PLAT=k3 TARGET_BOARD=lite SPD=opteed CFLAGS+="-DK3_PM_SYSTEM_SUSPEND=1"

    3. Build OPTEE-OS:

       .. code-block:: console

          $ cd ${OPTEE_PATH}
          $ make PLATFORM=k3 CFG_ARM64_core=y CROSS_COMPILE=$CC32 CROSS_COMPILE64=$CC64


    4. Build ``tiboot3.bin``:

       .. code-block:: console

          $ cd ${UBOOT_PATH}
          $ make ARCH=arm $UBOOT_CFG_CORTEXR
          $ make ARCH=arm CROSS_COMPILE=$CC32 \
                  BINMAN_INDIRS=${LNX_FW_PATH}


    5. Build ``tispl.bin`` and ``u-boot.img``:

       .. code-block:: console

          $ cd ${UBOOT_PATH}
          $ make ARCH=arm $UBOOT_CFG_CORTEXA
          $ make ARCH=arm CROSS_COMPILE=$CC64 \
                 BL31=${TFA_PATH}/build/k3/lite/release/bl31.bin \
                 TEE=${OPTEE_PATH}/out/arm-plat-k3/core/tee-pager_v2.bin \
                 BINMAN_INDIRS=${LNX_FW_PATH}


    6. Copy the ``tiboot3.bin``, ``tispl.bin`` and ``u-boot.img`` generated in steps 4 and 5
       to ``${YOUR_PATH}/ti-aosp-14/vendor/ti/am62x/bootloader``.
       If not copied, the prebuilt bootloader binaries already present in ``vendor/ti/am62x/bootloader``
       will get used by ``flashall.sh`` flashing script.

       .. ifconfig:: CONFIG_part_variant in ('AM62X')

          For picking the correct filenames, refer to the `upstream documentation <https://docs.u-boot.org/en/latest/board/ti/am62x_sk.html#target-images>`__.

       .. ifconfig:: CONFIG_part_variant in ('AM62PX')

          For picking the correct filenames, refer to the `upstream documentation <https://docs.u-boot.org/en/latest/board/ti/am62px_sk.html#target-images>`__.


**After building all components, refer to instruction in next section for flashing the images to EVM**

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    The android images generated for the AM62X-SK EVM are compatible with the Beagle Play board.
    For flashing the Beagle Play, see the `dedicated application note`_.

    .. _dedicated application note: ../devices/AM62X/android/Application_Notes_BeaglePlay.html
