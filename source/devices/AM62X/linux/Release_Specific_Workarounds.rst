.. _workarounds:

Workarounds
===========

USB Device Firmware Upgrade (DFU) Boot Fix
------------------------------------------

In 08.06 release, USB Device Firmware Upgrade (DFU) boot failure was observed as required ENV variable definitions for USB DFU boot from U-Boot SPL were not available, leaving R5 U-Boot SPL unable to continue with the DFU boot process.

Following steps can be used to fix the issue:-

1. Cherry-pick this commit inside U-Boot directory in (<installer-path>/board-support/) included in SDK https://git.ti.com/cgit/ti-u-boot/ti-u-boot/commit/?h=ti-u-boot-2021.01-next&id=28c75c2713915a122e5d39311ae7416ca35c0532 

::

    git fetch
    git cherry-pick 28c75c2713

2. Build the bootloader images using default “am62x_evm_r5_usbdfu_defconfig” and “am62x_evm_a53_defconfig” configs files. Following steps can be followed to build bootloader images using top-level makefile in SDK.

- Following change is needed in Rules.make

::

    UBOOT_MACHINE_R5=am62x_evm_r5_usbdfu_defconfig

- Build the bootloader images using top-level makefile by running following commands in top level of SDK.

::

    make u-boot
    make sysfw-image

- To build bootloader binaries without using top-level makefile please refer to :ref:`Build-U-Boot-label`.

3. USB Device Firmware Upgrade (DFU) Boot now can be used. For steps refer to :ref:`usb-device-firmware-upgrade-label`.
