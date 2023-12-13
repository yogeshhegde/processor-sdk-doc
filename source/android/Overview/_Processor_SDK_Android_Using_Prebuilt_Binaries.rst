.. include:: /_replacevars.rst

.. _android-prebuilts:

Using Prebuilt binaries
=======================

.. note::

    Linux machine running Ubuntu is needed for building and flashing Android images to the EVM

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    The SDK download page provides pre-built Android binaries (``AM62x_XX.YY.ZZ_emmc.tgz``) which can be readily used to flash the |__PART_FAMILY_DEVICE_NAMES__| EVM and boot Android.

    Extract the contents of the pre-built images tarball and follow the procedure mentioned in `Flashing Instruction`_ page to flash these binaries to the EVM.

    ::

        tar -zxvf AM62x_XX.YY.ZZ_emmc.tgz


.. ifconfig:: CONFIG_part_variant in ('AM62PX')

    The SDK download page provides pre-built Android binaries (``AM62Px_XX.YY.ZZ_emmc.tgz``) which can be readily used to flash the |__PART_FAMILY_DEVICE_NAMES__| EVM and boot Android.

    Extract the contents of the pre-built images tarball and follow the procedure mentioned in `Flashing Instruction`_ page to flash these binaries to the EVM.

    ::

        tar -zxvf AM62Px_XX.YY.ZZ_emmc.tgz

.. _Flashing Instruction: Overview_Flashing.html

