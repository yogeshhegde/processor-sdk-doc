.. _foundational-components-atf:

ARM Trusted Firmware-A
========================================
.. rubric:: Overview

Trusted Firmware-A (TF-A) provides a reference implementation of secure world
software for Armv7-A and Armv8-A, including a Secure Monitor executing at
Exception Level 3 (EL3).

ATF is used as the initial start code on ARMv8-A cores for all K3 platforms.
After setting up the initial core state and applying any needed errata fixes
it sets up itself as the EL3 monitor handler. After this is installs the secure
world software (OP-TEE) and passes execution on to either the Linux kernel or U-Boot
in the non-secure world.

.. rubric:: Getting the ATF Source Code

::

    $ git clone https://git.trustedfirmware.org/TF-A/trusted-firmware-a.git

.. rubric:: Getting Security Dev Tool
    
::
    
    $ git clone git://git.ti.com/security-development-tools/core-secdev-k3.git -b master
    $ export TI_SECURE_DEV_PKG=`pwd`/core-secdev-k3

.. rubric:: Building ATF

.. ifconfig:: CONFIG_part_family in ('AM64X_family')

    ::

        on GP
        $ make ARCH=aarch64 CROSS_COMPILE=aarch64-none-linux-gnu- PLAT=k3 TARGET_BOARD=lite SPD=opteed

    ::

        on HS
        $ make ARCH=aarch64 CROSS_COMPILE=aarch64-none-linux-gnu- PLAT=k3 TARGET_BOARD=lite SPD=opteed
        $ {TI_SECURE_DEV_PKG}/scripts/secure-binary-image.sh ./build/k3/generic/lite/bl31.bin ./build/k3/lite/release/bl31.bin.signed

.. ifconfig:: CONFIG_part_family not in ('AM64X_family')

    ::
        
        on GP
        $ make CROSS_COMPILE=aarch64-linux-gnu- PLAT=k3 TARGET_BOARD=generic SPD=opteed

    ::

        on HS
        $ make CROSS_COMPILE=aarch64-linux-gnu- PLAT=k3 TARGET_BOARD=generic SPD=opteed
        ${TI_SECURE_DEV_PKG}/scripts/secure-binary-image.sh ./build/k3/generic/release/bl31.bin ./build/k3/generic/release/bl31.bin.signed

.. rubric:: Default load locations

.. ifconfig:: CONFIG_part_family in ('AM64X_family')

    +---------------------------+------------+
    | ATF image                 | 0x701c0000 |
    +---------------------------+------------+
    | OP-TEE image              | 0x9e800000 |
    +---------------------------+------------+
    | U-Boot/Linux kernel image | 0x80080000 |
    +---------------------------+------------+
    | DTB                       | 0x82000000 |
    +---------------------------+------------+

.. ifconfig:: CONFIG_part_family not in ('AM64X_family')

    +---------------------------+------------+
    | ATF image                 | 0x70000000 |
    +---------------------------+------------+
    | OP-TEE image              | 0x9e800000 |
    +---------------------------+------------+
    | U-Boot/Linux kernel image | 0x80080000 |
    +---------------------------+------------+
    | DTB                       | 0x82000000 |
    +---------------------------+------------+

These can be changed from the defaults if needed in:


.. ifconfig:: CONFIG_part_family in ('AM64X_family')

    ::

        plat/ti/k3/board/lite/board.mk

.. ifconfig:: CONFIG_part_family not in ('AM64X_family')

    ::

        plat/ti/k3/board/generic/board.mk
