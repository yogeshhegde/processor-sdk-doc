==================
Android on SD Card
==================

This applications Notes contains step to use SD Card instead of EMMC.


Build U-Boot with this changes
====================================

Download sources
----------------

Follow this link to `download Bootloader sources`_.

Apply this patch in U-boot source code:

    ::

        diff --git a/configs/am62x_android_a53.config b/configs/am62x_android_a53.config
        index fc949f65d7fe..d50952557192 100644
        --- a/configs/am62x_android_a53.config
        +++ b/configs/am62x_android_a53.config
        @@ -5,7 +5,7 @@ CONFIG_USB_FUNCTION_FASTBOOT=y
        CONFIG_FASTBOOT_BUF_ADDR=0xC0000000
        CONFIG_FASTBOOT_BUF_SIZE=0x2F000000
        CONFIG_FASTBOOT_FLASH=y
        -CONFIG_FASTBOOT_FLASH_MMC_DEV=0
        +CONFIG_FASTBOOT_FLASH_MMC_DEV=1
        CONFIG_FASTBOOT_CMD_OEM_FORMAT=y
        # Enable Android boot flow
        CONFIG_SYS_MALLOC_LEN=0x08000000


Build U-Boot
------------

Follow this link to `build U-Boot`_.

Rebuild U-boot then copy ``u-boot.img`` in Android build system environment : ``vendor/ti/am62x/bootloader/am62-sk``

Build Android
-------------

Follow this link to `build Android image`_.
Go in your Android environment then rebuild with ``TARGET_SDCARD_BOOT=true`` build args:

    ::

        cd ${YOUR_PATH}/ti-aosp-14
        lunch <BUILD_TARGET>
        m TARGET_SDCARD_BOOT=true



.. _download Bootloader sources: ../../../android/Overview_Building_the_SDK.html#bootloader-components
.. _build U-Boot: ../../../android/Overview_Building_the_SDK.html#id1
.. _build Android image: ../../../android/Overview_Building_the_SDK.html#id5


Flashing SD Card
----------------

.. warning::
    Minimal size for SD card is 16GB

- Change the Boot Mode DIP switches to SD card boot mode.

    ::

        Boot mode DIP Switch:
        SW1: 11000010 SW2: 01000000

- Go in out dir in android environment and launch this command:

    ::

        # If you are using binaries built locally
        cd out/target/product/am62x
        sudo ./flashall.sh --board="am62x-sk" --sdcard="/dev/sdX"

**flashall.sh script print in your console instruction to do**

.. note::
    Replace X in ``/dev/sdX/`` by letter corresponding to your SDCard

