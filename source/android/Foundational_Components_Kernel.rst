##############
Android Kernel
##############

.. _android-download-kernel:

*******************
Downloading sources
*******************

.. ifconfig:: CONFIG_part_variant in ('AM62X' 'AM62PX')

    Fetch the code using ``repo``:

    .. code-block:: console

       $ mkdir ${YOUR_PATH}/ti-kernel-aosp/ && cd $_
       $ repo init -u git://git.ti.com/android/manifest.git -b android14-release -m releases/RLS_10_00_Kernel.xml
       $ repo sync

    .. tip::

       To save some disk space, pass the ``--depth=1`` option to ``repo init``:

       .. code-block:: console

          $ repo init -u git://git.ti.com/android/manifest.git -b android14-release -m releases/RLS_10_00_Kernel.xml --depth=1

    A preview for the ``android15-6.6`` kernel is also available for testing via a dedicated manifest:

    .. code-block:: console

       $ repo init -u git://git.ti.com/android/manifest.git -b android14-release -m releases/RLS_10_00_Kernel-6.6.xml

.. _android-build-kernel:

******************
Build Instructions
******************

Building everything from scratch
================================

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
=================

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

   .. code-block:: console

      $ cd ${YOUR_PATH}/ti-kernel-aosp/
      $ export TARGET_KERNEL_USE="6.1" # or "6.6" for experimental kernel
      $ export DIST_DIR=${YOUR_PATH}/ti-aosp-14/device/ti/am62x-kernel/kernel/${TARGET_KERNEL_USE}
      $ tools/bazel run --config=fast //common:ti_dist -- --dist_dir=$DIST_DIR


Defconfig/menuconfig changes
============================

The usual (``make menuconfig``) is done via ``bazel`` command :

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

   .. code-block:: console

      $ cd ${YOUR_PATH}/ti-kernel-aosp/
      $ tools/bazel run //common:ti_config -- menuconfig

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

   .. note::

      Users must have built the android kernel image prior to building the Android file system.
      Otherwise pre-built kernel images present in :file:`device/ti/am62x-kernel`
      will be used to create :file:`boot.img`

Rebuild Android images
======================

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

   We should re-generate the Android images to include the newly build kernel.
   Follow the Android :ref:`android-build-aosp` to do so.

*********************
Flashing instructions
*********************

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62PX')

   In order to flash a new kernel, several images should be flashed:

   .. code-block:: console

      $ adb reboot fastboot
      < Wait for fastbootd reboot >

      $ cd <PATH/TO/IMAGES>
      $ fastboot flash boot boot.img
      $ fastboot flash vendor_boot vendor_boot.img
      $ fastboot flash vendor_dlkm vendor_dlkm.img
      $ fastboot reboot

   The board should boot with the new kernel.
