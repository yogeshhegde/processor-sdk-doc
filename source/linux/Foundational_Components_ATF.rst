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

.. rubric:: Building ATF

.. ifconfig:: CONFIG_part_family in ('AM64X_family')

    ::

        $ make ARCH=aarch64 CROSS_COMPILE=aarch64-none-linux-gnu- PLAT=k3 TARGET_BOARD=lite SPD=opteed

.. ifconfig:: CONFIG_part_family not in ('AM64X_family')

    ::

        $ make CROSS_COMPILE=aarch64-linux-gnu- PLAT=k3 TARGET_BOARD=generic SPD=opteed

.. rubric:: Default load locations

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

::

    plat/ti/k3/board/generic/board.mk
