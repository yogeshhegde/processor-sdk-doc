.. include:: /replacevars.rst.inc

.. _HS-Migration-Guide:

**********************************
GP to HS-FS Migration Guide
**********************************

Overview
-----------

The Processor SDK now supports HS-FS (High Security - Field Securable) device types. This migration guide targets customers who have |__PART_FAMILY_NAME__| GP
devices and need to migrate to |__PART_FAMILY_NAME__| HS-FS devices. The Processor SDK will include source and build instruction updates for K3-Image-Gen, ti-u-boot,
and ti-linux sources.

.. ifconfig:: CONFIG_part_variant in ('AM64X')

    The Processor SDK will include support for AM64x SR2.0 HS-FS and HS-SE devices and no longer support AM64x SR1.0 HS-FS and HS-SE devices; changing the firmware
    that is distributed in the Processor SDK. More information on device specifications can be found below.

.. ifconfig:: CONFIG_part_variant not in ('AM64X')

    The Processor SDK will include support for HS-FS, HS-SE, and GP variants. The default device targeted in the Processor SDK is of HS-FS type.

    .. note::

        Images in the Processor SDK will by defualt boot HS-FS devices. To boot GP devices, use tiboot3-<family>-gp-evm.bin found in the Processor SDK. If using
        SD/MMC boot and having flashed a .wic image (WIC file) to an SD card, tiboot3-<family>-gp-evm.bin should be found in the `boot` partition of the SD card.
        Renaming/removing the pre-existing`tiboot3.bin` and renaming `tiboot3-<family>-gp-evm.bin` to `tiboot3.bin` is the only change needed to boot the HS-FS
        device.

Device types
---------------

+-------+-----------------------------------------------------------------------+
| GP    | General Purpose: This is a SoC/board state where there is no devie    |
|       | protection and authentication is not enabled for booting the device.  |
+-------+-----------------------------------------------------------------------+
| HS-FS | High Security - Field Securable: This is a SoC/board state before a   |
|       | customer has blown the keys in the device. i.e. the state at which HS |
|       | device leaves TI factory. In this state, the device protects the ROM  |
|       | code, TI keys and certain security peripherals. In this state, device |
|       | do not force authentication for booting, however DMSC is locked.      |
+-------+-----------------------------------------------------------------------+
| HS-SE | High Security - Security Enforced: This is a SoC/board state after a  |
|       | customer has successfully blown the keys and set “customer Keys       |
|       | enable”. In HS-SE device all security features enabled. All secrets   |
|       | within the device are fully protected and all of the security goals   |
|       | are fully enforced. The device also enforces secure booting.          |
+-------+-----------------------------------------------------------------------+

.. ifconfig:: CONFIG_part_variant in ('AM64X')

    +-------+--------------------------+
    | SR1.0 | SoC Silicon Revision 1.0 |
    +-------+--------------------------+
    | SR2.0 | Soc Silicon Revision 2.0 |
    +-------+--------------------------+

To identify a device type the following method could be used:

- Connect to UART terminal (main domain)
- Change boot pin settings to UART boot mode (Refer to TRM for boot mode switch settings)
- Turn on the device and watch the terminal for a string that looks like the one below:

.. parsed-literal::

    02000000011a0000616d3632780000000000000048534653010001000100010002a6000000000000d68ecb2c055dff11ade95bd927e837d2a53bc23b0a2800cebce4f106bcf309df2213912d77a157a8b7c2df40672a06a918034aa4c7d603e462481475225d49b8ad0bc40b0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000a2847bc4053c7aeb55ff49d6c1a5097be5608811c7f05ec71d5cf5eba99b47e

.. note::

    Do not copy the CCCC characters at the end of the string.

- Save the string into a <file-name>.txt file
- Download the uart-parser :download:`here </files/parse_uart_boot_socid.py>`
- Execute the uart-parser on PC as follows:

::

    $ python parse_uart_boot_socid.py <file-name.txt>

The string will print to log like the following output:

::

    -----------------------
    SoC ID Header Info:
    -----------------------
    NumBlocks            : [2]
    -----------------------
    SoC ID Public ROM Info:
    -----------------------
    SubBlockId           : 1
    SubBlockSize         : 26
    DeviceName           : am64x
    DeviceType           : HSFS
    DMSC ROM Version     : [0, 2, 0, 0]
    R5 ROM Version       : [0, 2, 0, 0]
    -----------------------
    SoC ID Secure ROM Info:
    -----------------------
    Sec SubBlockId       : 2
    Sec SubBlockSize     : 166
    Sec Prime            : 0
    Sec Key Revision     : 0
    Sec Key Count        : 0
    Sec TI MPK Hash      : b018658ad99dc903c8c9bfb27b12751099920a042ad1dfea7b7ba57369f15546de285edde6a7b39a8bdc40a27b237f8fb1e57f245e80b929c1e28b024aa2ecc6
    Sec Cust MPK Hash    : ad0bc40b000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
    Sec Unique ID        : a6bbeab017b04e54d30c26460c175bc03e734507db2b8a206af12f3e38de6e47

DeviceType will show whether an soc is GP, HS-FS, or HS-SE under `DeviceName`. ROM version will show whether an SOC is SR1.0 with [0,1,0,0] or SR2.0 with [0,2,0,0],

Processor SDK
---------------

The boot images necessary to boot |__PART_FAMILY_NAME__| family devices are described here: :ref:`target-images`. Of those, the initial boot
image that ROM loads is `tiboot3.bin`. The |__PART_FAMILY_NAME__| Processor SDK will include up to three versions of the `tiboot3.bin` initial boot
image. This is due to `tiboot3.bin` packaging TI firmware. TI firmware is different for every |__PART_FAMILY_NAME__| device type and one firmware
for one device type may not work on another |__PART_FAMILY_NAME__| device type. Use the `tiboot3.bin` version according to the target device type.

.. ifconfig:: CONFIG_part_variant in ('AM64X')

    +-------------------+-------------------------------------------+
    | Device Type       | Initial boot image name                   |
    +===================+===========================================+
    | AM64x HS-FS SR2.0 | tiboot3-am64x_sr2-hs-fs-evm.bin (default) |
    +-------------------+-------------------------------------------+
    | AM64x HS-SE SR2.0 | tiboot3-am64x_sr2-hs-evm.bin              |
    +-------------------+-------------------------------------------+
    | AM64x GP SR1.0    | tiboot3-am64x-gp-evm.bin                  |
    +-------------------+-------------------------------------------+

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62AX')

    +------------------------------+------------------------------------------+
    | Device Type                  | Initial boot image name                  |
    +==============================+==========================================+
    | |__PART_FAMILY_NAME__| HS-FS | tiboot3-<family>-hs-fs-evm.bin (default) |
    +------------------------------+------------------------------------------+
    | |__PART_FAMILY_NAME__| HS-SE | tiboot3-<family>-hs-evm.bin              |
    +------------------------------+------------------------------------------+
    | |__PART_FAMILY_NAME__| GP    | tiboot3-<family>-gp-evm.bin              |
    +------------------------------+------------------------------------------+

    Where <family> is |__PART_FAMILY_NAME__|

A common way to boot a board is with a bootable SD card, so it is assumed this is the method used. In the pre-built SDK, a bootable
SD card image (WIC file) can be found in <path-to-tisdk>/filesystem directory which can then be flashed onto an SD card. During boot,
ROM will load the initial boot binary (found in the SD card boot partition) named `tiboot3.bin`. By default this binary will be the
HS-FS version.

The bootable SD card image will also have `tiboot3-<famly>-gp-evm.bin` in the boot partition of the SD card image.
Renaming `tiboot3-<family>-gp-evm.bin` to `tiboot3.bin` and removing/renaming the pre-existing `tiboot3.bin` of HS-FS type is the only
change needed to run the HS-FS SDK on a GP board.

K3-image-gen
-------------

K3-Image-Gen is a tool to allow users to create an image comprising of a signed System Firmware image as well
as the binary configuration artifacts needed to bring up SYSFW as part of the U-Boot SPL startup. For more information go to:
https://git.ti.com/cgit/k3-image-gen/k3-image-gen/tree/README.md.

The following updates to K3-Image-Gen apply to the pre-built SDK, buildable SDK, and latest TI source for manual builds.
k3-image-gen will now include the SOC and SOC_TYPE Make flags for packaging `tiboot3.bin`.

.. ifconfig:: CONFIG_part_variant in ('AM64X')

    Below is a list with AM64x devices and the corresponding flags to be included in the K3-Image-Gen build instruction:

    +-------------------+---------------+----------------+
    | Device Type       | SOC flag      | SOC_TYPE flag  |
    +===================+===============+================+
    | AM64x HS-FS SR2.0 | SOC=am64x_sr2 | SOC_TYPE=hs-fs |
    +-------------------+---------------+----------------+
    | AM64x HS-FS SR1.0 | SOC=am64x     | SOC_TYPE=hs-fs |
    +-------------------+---------------+----------------+
    | AM64x HS-SE SR2.0 | SOC=am64x_sr2 | SOC_TYPE=hs    |
    +-------------------+---------------+----------------+
    | AM64x HS-SE SR1.0 | SOC=am64x     | SOC_TYPE=hs    |
    +-------------------+---------------+----------------+
    | AM64x GP SR1.0    | SOC=am64x     | SOC_TYPE=gp    |
    +-------------------+---------------+----------------+

    For example, to package the initial boot image for AM64x SR2.0 HS-FS device using the pre-built SDK, one could use the following:

    ::

        $ cd <path-to-tisdk>/board-support/k3-image-gen-<version>
        $ make CROSS_COMPILE=arm-none-linux-gnueabihf- SOC=am64x_sr2 SOC_TYPE=hs-fs SBL=./prebuilt-images/u-boot-spl.bin-<machine-name> SYSFW_DIR=./prebuilt-images

.. ifconfig:: CONFIG_part_variant not in ('AM64X')

    +------------------------------+---------------+----------------+
    | Device Type                  | SOC flag      | SOC_TYPE flag  |
    +==============================+===============+================+
    | |__PART_FAMILY_NAME__| HS-FS | SOC=<family>  | SOC_TYPE=hs-fs |
    +------------------------------+---------------+----------------+
    | |__PART_FAMILY_NAME__| GP    | SOC=<family>  | SOC_TYPE=gp    |
    +------------------------------+---------------+----------------+
    | |__PART_FAMILY_NAME__| HS-SE | SOC=<family>  | SOC_TYPE=hs    |
    +------------------------------+---------------+----------------+

    Where <family> is |__PART_FAMILY_NAME__|

    For example, to package the initial boot image for |__PART_FAMILY_NAME__| HS-FS device using the pre-built SDK, one could use the following:

    ::

    $ cd <path-to-tisdk>/board-support/k3-image-gen-<version>
    $ make CROSS_COMPILE=arm-none-linux-gnueabihf- SOC=<family> SOC_TYPE=hs-fs SBL=./prebuilt-images/u-boot-spl.bin-<machine-name> SYSFW_DIR=./prebuilt-images


K3-Image-Gen will name the target `tiboot3.bin` image in the following format: tiboot3-<soc_flag>-<soc_type>-evm.bin.

If TI_SECURE_DEV_PKG environment variable is not defined, `tiboot3.bin` can still be built for GP devices. The following errors will occur in K3-Image-Gen build logs when
building for HS-FS or HS-SE devices without the TI_SECURE_DEV_PKG environment variable defined and K3-Image-Gen build may fail:

.. parsed-literal::

    TI_SECURE_DEV_PKG must be set for HS, defaults will not work.  Stop.

To fix the above issue, do the following:

::

    $ git clone https://git.ti.com/git/security-development-tools/core-secdev-k3.git -b master
    $ export TI_SECURE_DEV_PKG=`pwd`/core-secdev-k3

.. ifconfig:: CONFIG_part_variant in ('AM64X')

    If a AM64x device SoC is SR1.0 or SR2.0, it does not impact U-boot source, or linux source, only K3-Image-Gen source since it packages firmware that is unique to
    specific SoC and its silicon revision number.

    .. note::

        AM64x HS-FS SR1.0 and AM64x HS-SE SR1.0 will not be supported in the 08.04 SDK. Therefore, the following firmware may not be found in the Processor SDK:
        ti-sci-firmware-am64x-hs.bin, ti-sci-firmware-am64x-hs-cert.bin, ti-sci-firmware-am64x-hs-fs.bin, and ti-sci-firmware-am64x-hs-fs-cert.bin.

U-Boot
---------

The following updates to ti-u-boot apply to the pre-built SDK, buildable SDK, and latest TI source for manual builds.
U-Boot will now use the same defconfig for both HS and non-HS device types. All devices are assumed to be secure and the
default `<family>_evm_{r5,a53}_defconfig` will build for HS-FS and HS-SE devices. This causes U-Boot to attempt to sign the
individual images (tispl.bin, tiboot3.bin, and u-boot.img) if `TI_SECURE_DEV_PKG` environment variable is defined and
pointing to a copy of the SECDEV package. If not, the binaries will remain unsigned. If TI_SECURE_DEV_PKG environment variable is
not defined all images can still be built for GP devices. The following warnings will occur in ti-u-boot build logs when
building for HS-FS or HS-SE devices without the TI_SECURE_DEV_PKG environment variable defined:

.. parsed-literal::

    WARNING: TI_SECURE_DEV_PKG environment variable must be defined for TI secure devices. spl/u-boot-spl-nodtb.bin was NOT secured!

After U-boot is built, the filenames of the generated images `tispl.bin` and `u-boot.img` are in the following format:

.. ifconfig:: CONFIG_part_variant in ('AM64X')

    - Signed: tispl.bin
    - Unsigned: tispl.bin_unsigned

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM62AX')

    - Signed: tispl.bin_HS
    - Unsigned: tispl.bin

Unsigned images will boot on GP and HS-FS devices but not on HS-SE devices.

On HS-SE device, unsigned images may cause no prints to be displayed on the console or we may see "Authentication failed" warnings and the
device will fail to boot as seen below:
::
    U-Boot SPL 2021.01 (Aug 18 2022 - 15:15:21 -0500)
    EEPROM not available at 80, trying to read at 81
    SYSFW ABI: 3.1 (firmware rev 0x0008 '8.4.4-v08.04.04 (Jolly Jellyfi')
    SPL initial stack usage: 13424 bytes
    Trying to boot from MMC2
    ti_sci system-controller@44043000: Message not acknowledgedAuthentication failed!
    ### ERROR ### Please RESET the board ###

On HS-FS device, unsigned images will boot but we will see a "Skipping authentication" warning in the console ouput as seen below:
::
    U-Boot SPL 2021.01 (Aug 18 2022 - 15:25:41 -0500)
    EEPROM not available at 80, trying to read at 81
    SYSFW ABI: 3.1 (firmware rev 0x0008 '8.4.4-v08.04.04 (Jolly Jellyfi')
    SPL initial stack usage: 13424 bytes
    Trying to boot from MMC2
    Warning: Did not detect image signing certificate. Skipping authentication to prevent boot failure. This will fail on Security Enforcing(HS-SE) devices

Signed images will boot on all devices including GP device as can be seen on the ouput below:
::
    U-Boot SPL 2021.01 (Aug 18 2022 - 15:29:01 -0500)
    EEPROM not available at 80, trying to read at 81
    SYSFW ABI: 3.1 (firmware rev 0x0008 '8.4.4--v08.04.04 (Jolly Jellyfi')
    SPL initial stack usage: 13424 bytes
    Trying to boot from MMC2
    Warning: Detected image signing certificate on GP device. Skipping certificate to prevent boot failure. This will fail if the image was also encrypted

Linux Kernel
---------------

The following updates to ti-linux-kernel apply to the pre-built SDK, buildable SDK, and latest TI source for manual builds.
No changes are needed when building the kernel.

By default U-boot expects to boot kernel `Image`, DTB, and DTOs found in root/boot of the SD card if using SD/MMC boot. The exception is
for HS-SE (High Security - Security Enforced) devices where the FIT image (Flattened Image Tree) named `fitImage` will boot by default. Booting
with FIT image implements higher security. Each individual component is signed and when packaged, the FIT image will be authenticated during boot.

Booting FIT image is not required for GP and HS-FS devices, but on HS-SE devices only the signed FIT image will be allowed to boot.

To build your own FIT image, the pre-built SDK provides scripts to take a re-built kernel and re-bundle it into a FIT image :ref:`fitImage-for-HS`.

To enable booting the FIT image, the u-boot environment variable `boot_fit` could be set to `1` in u-boot:
::
    setenv boot_fit 1
    savenv
    boot

or we could copy the following code line to the uEnv.txt file located in the `boot` partition of the SD card after flashing a working bootable image, then
boot AM64x via SD/MMC card boot:
::
    boot_fit=1
