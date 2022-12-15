====================================
Android Generic Kernel Image Support
====================================

Build Kernel in `Android GKI <https://source.android.com/docs/core/architecture/kernel/generic-kernel-image>`__ Mode
=====================================================================================================================================

Building everything from scratch
--------------------------------

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    ::

        cd ${YOUR_PATH}/ti-kernel-aosp/
        export DIST_DIR=${YOUR_PATH}/ti-aosp/device/ti/am62x-kernel/kernel/5.10-gki
        export BUILD_CONFIG=./common/build.config.gki.ti
        build/build.sh

Rebuilding incrementally
------------------------

Add the ``SKIP_MRPROPER=1`` flag:

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    ::

        $ cd ${YOUR_PATH}/ti-kernel-aosp/
        $ export DIST_DIR=${YOUR_PATH}/ti-aosp/device/ti/am62x-prebuilts/kernel/5.10-gki
        $ export BUILD_CONFIG=./common/build.config.gki.ti
        $ export SKIP_MRPROPER=1
        $ build/build.sh

    .. note::

           Users must have built the android kernel image prior to building the Android file system.
           Otherwise pre-built Kernel images present in ``device/ti/am62x-kernel`` will be used to create ``boot.img``


Build Android in `Android GKI <https://source.android.com/docs/core/architecture/kernel/generic-kernel-image>`__ Mode
=====================================================================================================================================

    ::

        cd ${YOUR_PATH}/ti-aosp-12
        lunch <BUILD_TARGET>
        m TARGET_KERNEL_USE=5.10-gki

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
    By default with User images AVB feature was enabled.
    For userdebug images if you want to enable AVB feature you need to build with ``TARGET_AVB_ENABLE=true`` build args
    ::

        cd ${YOUR_PATH}/ti-aosp-12
        lunch <BUILD_TARGET>
        m TARGET_KERNEL_USE=5.10-gki TARGET_AVB_ENABLE=true