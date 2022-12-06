**********************************
Secure Boot
**********************************

Authenticated Boot
--------------------

Each device contains customer programmable keys used to authenticate, and optionally decrypt, code/data to be used on the device. A job for
the Public Boot ROM of both General Purpose (GP) and High Security (HS) devices is to load the next stage of the boot process into memory. On
High Security devices, Public ROM also checks the initial boot image for an attached header containing details about the image, including
a signature used to verify the authorship of the image, and optionally encryption information. This header must be attached and the image must
pass authentication for Public Boot ROM to continue boot. It is then the responsibility of the authors to maintain a Chain-of-Trust by ensuring
each next stage is itself authenticated. One weak link and all lower trust levels could be compromised.

.. Note::
    Example: Forgetting to disable u-boot console or environment loading means a non-secured linux can be loaded. The U-Boot console (or command
    line interface (CLI)) and environment are powerful features that make it great for creating a customized boot process. However,
    leaving either or them enabled in a production system allows non-secured software to be loaded and the Chain-of-Trust to be broken.

The following is an example list where Chain-of-Trust should be maintained.

- Remove U-Boot uEnv.txt loading support.
- Disable environment loading (the default built-in environment must be compiled to be the one you want).
- Environment must not fallback to other boot modes.
- Place firewalls in board-config to match the location of loaded artifacts (ATF/OP-TEE).
- Update debug sections of initial image cert.
- Enable DM-verity/DM-crypt.
- Set root password or disable root account.
- Read the OP-TEE porting guide and turn off developer options
- Disable kernel debug options
- Disable/remove userspace debug tools, devmem disable, etc..

We provide methods for U-Boot's SPL loader to securely verify/decrypt the U-Boot proper, and this U-Boot proper to securely verify/decrypt the
Kernel/DTB/initfamfs. This is accomplished by calling into TIFS via TI-SCI (Texas Instruments System controller Interface). This allows us to use
the same signing/encrypting tools used to authenticate the first-stage image. For more infomation using TI_SCI methods refer to the
`TISCI User Guide <https://software-dl.ti.com/tisci/esd/22_01_02/index.html>`__.

.. Image:: /images/K3_KF.JPG
        :scale: 70%

Secure boot is like an onion, it has layers. Some layers are trusted more than others. Secure ROM has the highest trust and REE (Run-time Execution
Environment) non-trustzone user-space applications have the least. If any higher trust code is to be loaded by a lower trust entity, it must be verified
by an even higher trust entity and not allowed to be accessed by the lower trust entity after that point. Some such trust inversions are listed below:

- R5 U-Boot loading ATF/OP-TEE
- R5 Public Boot ROM loading TIFS
- Linux loading Trusted applications(TA)

These are called out in the sequence as shown in the following image and their method of ensuring trust is explained.

Secure Boot Flow
--------------------

.. Image:: /images/K3_BF.jpg
        :scale: 70%

.. rubric:: ROM

On device startup, execution begins with the ROM bootloader (Secure ROM) running on the DSMC/TIFS core. After initial device security
setup the Secure ROM starts the Public ROM running on the R5 core. The Public Boot ROM handles loading the first stage image `tiboot3.bin` from a
peripheral as selected by the BOOTMODE pins. This image is placed into on chip SRAM as external memory interfaces such as DDR are not yet enabled.
The exact location is device dependent. More details can be found in the device "Technical Reference Manual".

.. ifconfig:: CONFIG_part_variant in ('AM64x')

    - `AM64x TRM <https://www.ti.com/lit/pdf/spruim2>`_

    The contents of this first stage image are authenticated and decrypted by the Secure ROM. Contents include:

    * DMSC firmware: `Texas Instruments Foundational Security (TIFS)` + Device/Power Manager: After authentication/decryption, DMSC firmware replaces the Secure ROM as the authenticator entity executing on the DMSC core.
    * R5 SPL: The R5 SPL bootloader is executed on the R5 core.

.. ifconfig:: CONFIG_part_variant in ('AM62x')

    - `AM62x TRM <https://www.ti.com/lit/pdf/spruiv7>`_

    The contents of this first stage image are authenticated and decrypted by the Secure ROM. Contents include:

    * `Texas Instruments Foundational Security (TIFS)` firmware: After authentication/decryption, TIFS firmware replaces the Secure ROM as the authenticator entity executing on the TIFS core.
    * R5 SPL`: The R5 SPL bootloader is executed on the R5 core.

.. rubric:: R5 SPL

R5 SPL loads the second boot stage FIT image `tispl.bin` from the peripheral as selected by the BOOTMODE pins. From this FIT image, TF-A, OPTEE, A53 SPL,
and SPL DTB are extracted and authenticated and/or decrypted by TIFS. If authentication passed, the R5 SPL starts the ARM64 core. TF-A, OPTEE, and A53 SPL
will begin execution on the ARM64 core. R5 SPL also configures DDR and the console so the user can see the first prints as seen below:

R5 SPL's output will be similar to this:
Notice the "Authentication passed" lines as TF-A, OPTEE, A53 SPL, and SPL DTB are authenticated.
::
    U-Boot SPL 2021.01-dirty (May 13 2022 - 15:05:11 -0500)
    SYSFW ABI: 3.1 (firmware rev 0x0008 '8.4.0-3-gd5cb1+ (Jolly Jellyfis')
    SPL initial stack usage: 13392 bytes
    Trying to boot from MMC2
    Authentication passed
    Authentication passed
    Authentication passed
    Authentication passed
    Starting ATF on ARM64 core...

.. ifconfig:: CONFIG_part_variant in ('AM62x')

    After R5 SPL, the device/power manager firmware continues running on the R5 core.

.. rubric:: A53 SPL

A53 SPL then loads the U-Boot proper FIT image `U-boot.img` from the peripheral as selected by the BOOTMODE pins. From this FIT image, the U-boot bootloader
and DTB are extracted before passing execution to u-boot proper.

A53 SPL's output will be similar to this: (notice the "Authentication passed" lines as U-Boot and the DTB are authenticated).
::
    U-Boot SPL 2021.01-g2de57d278b (May 16 2022 - 14:28:40 +0000)
    SYSFW ABI: 3.1 (firmware rev 0x0008 '8.4.0-3-gd5cb1+ (Jolly Jellyfis')
    Trying to boot from MMC2
    Authentication passed
    Authentication passed

.. rubric:: U-Boot

The boot flow continues as it does on a non-secure device, until loading the next FIT image `fitImage`. This FIT image includes the Linux kernel, DTB, and
other required boot artifacts. Each component is extracted and authenticated from this FIT image. Once all components are authenticated, U-boot starts Linux.

U-boot's output will be similar to this: (notice the "Authentication passed" lines as we authenticate the Linux kernel and DTB).
::
    U-Boot 2021.01-g2de57d278b (May 16 2022 - 14:28:40 +0000)

    SoC:   AM64X SR1.0
    Model: Texas Instruments AM642 EVM
    Board: AM64-GPEVM rev A
    DRAM:  2 GiB
    NAND:  0 MiB
    MMC:   mmc@fa10000: 0, mmc@fa00000: 1
    Loading Environment from FAT... *** Warning - bad CRC, using default environment

    In:    serial@2800000
    Out:   serial@2800000
    Err:   serial@2800000
    Net:   eth0: ethernet@8000000port@1
    Hit any key to stop autoboot:  0
    switch to partitions #0, OK
    mmc1 is current device
    SD/MMC found on device 1
    Failed to load 'boot.scr'
    1011 bytes read in 2 ms (493.2 KiB/s)
    Loaded env from uEnv.txt
    Importing environment from mmc1 ...
    Running uenvcmd ...
    7862647 bytes read in 328 ms (22.9 MiB/s)
    ## Loading kernel from FIT Image at 90000000 ...
    Using 'k3-am642-evm.dtb' configuration
    Trying 'kernel@1' kernel subimage
        Description:  Linux kernel
        Type:         Kernel Image
        Compression:  gzip compressed
        Data Start:   0x900000f8
        Data Size:    7743643 Bytes = 7.4 MiB
        Architecture: AArch64
        OS:           Linux
        Load Address: 0x80080000
        Entry Point:  0x80080000
    Verifying Hash Integrity ... OK
    Authentication passed
    ## Loading fdt from FIT Image at 90000000 ...
    Using 'k3-am642-evm.dtb' configuration
    Trying 'k3-am642-evm.dtb' fdt subimage
        Description:  Flattened Device Tree blob
        Type:         Flat Device Tree
        Compression:  uncompressed
        Data Start:   0x90762a54
        Data Size:    56436 Bytes = 55.1 KiB
        Architecture: AArch64
        Load Address: 0x83000000
    Verifying Hash Integrity ... OK
    Authentication passed
    Loading fdt from 0x90762a54 to 0x83000000
    Booting using the fdt blob at 0x83000000
    Uncompressing Kernel Image
    Loading Device Tree to 000000008ffef000, end 000000008ffff602 ... OK

.. rubric:: Linux

If initramfs is included, we can trust our initial modules and tasks, but we cannot trust anything beyond this as the root file-system may have been
modified. To allow trusted use of files outside of our initramfs we use dm-verity. With this we can authenticate a block device as we read from it. As
any changes to this block-device will cause the authentication to fail, we cannot put any user-modifiable configurations or user installed programs
here. Only important, read-only, files should be placed on this partition, such as static kernel and operating system files and configurations. All
other files must be placed in a non-verifiable read-write user partition.

HS Boot Flow Tools
-------------------

TI_SECURE_DEV_PKG:

    The TI_SECURE_DEV_PKG package is a TI security project that is used to sign binaries in the HS boot flow. This software package is used when signing bl31.bin
    as shown in :ref:`foundational-components-atf`, bl32.bin as shown in :ref:`foundational-components-optee`, and other componenents such as the Linux
    kernel as shown in :ref:`fitImage-for-HS-with-SDK`. As shown in the diagram in the `Authenticated Boot` section above, all components involved in the
    HS boot flow must be signed except DMSC/TIFS firmware which is signed with TI keys. For most binaries, there will be instructions in the Processor SDK
    documentation for signing the images with the TI_SECURE_DEV_PKG package. In other cases, once the TI_SECURE_DEV_PKG environmental variable is exported, sources like u-boot
    and K3-Image-Gen will be able to find the package and sign the tiboot3.bin, tispl.bin, and U-boot.img images. To sign each of the binaries with customer
    keys, the dummy key in <path-to-TI_SECURE_DEV_PKG>/core-secdev-k3/keys/custMpk.pem must be replaced with a customer key.

    ::

        $ git clone https://git.ti.com/git/security-development-tools/core-secdev-k3.git -b master
        $ export TI_SECURE_DEV_PKG=`pwd`/core-secdev-k3

        Example use:
        $ $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh input-file-name output-file-name

K3-image-gen:

    The K3-Image-Gen source is a TI project used to package the `tiboot3.bin` image. Before packaging it, there needs to be an existing R5
    SPL (u-boot-spl.bin) which is built by U-Boot source. The K3-Image-Gen project will take the R5 SPL and DMSC firmware (for AM64x devices) as arguments
    in the build instruction. If the TI_SECURE_DEV_PKG environment variable exists, K3-Image-Gen will use the TI_SECURE_DEV_PKG package to sign the tiboot3.bin image with the
    key stored in TI_SECURE_DEV_PKG. If the TI_SECURE_DEV_PKG environment variable does not exist, K3-Image-Gen will still package tiboot3.bin for GP devices but not for HS-FS
    or HS-SE devices.

    ::

        $ git clone https://git.ti.com/git/k3-image-gen/k3-image-gen.git

        Example use:
        $ make CROSS_COMPILE=arm-none-linux-gnueabihf- SOC=am64x_sr2 SOC_TYPE=hs SBL=u-boot-spl.bin SYSFW_DIR=$SYSFW_DIR

U-boot:

    The ti-u-boot source is a TI project used to build R5 SPL, A53 SPL, and U-boot proper. To build  R5 SPL for AM64x family devices, u-boot builds an image named
    u-boot-spl.bin and the K3-Image-Gen project will copy this image as well as DMSC firmware and package it into a `tiboot3.bin` image. To build A53 SPL, u-boot takes
    the ATF and OPTEE images and packages them in `tispl.bin`. If the TI_SECURE_DEV_PKG environment variable exists, U-boot will use the TI_SECURE_DEV_PKG package to sign the images with
    the key stored in the secdev package.

    ::

        $ git clone https://git.ti.com/git/ti-u-boot/ti-u-boot.git

        Example use:
        $ make ARCH=arm CROSS_COMPILE=aarch64-none-linux-gnu- am64x_evm_a53_defconfig
        $ make CROSS_COMPILE=aarch64-none-linux-gnu- ATF=bl31.bin TEE=tee-pager_v2.bin

Linux:

    The ti-linux source is a TI project used to build Linux kernel, DTB, and other boot artifacts. Some of these components could be included in a verifiable image
    `fitImage`. For HS devices, only the fitImage will be allowed to boot once `fitImage` has been authenticated.

    ::

        $ git clone https://git.ti.com/git/ti-linux-kernel/ti-linux-kernel.git

        Example use:
        $ make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- <config type>
        $ make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- menuconfig
        $ make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- <target>

ATF:

    The ATF source (now called TF-A) is used to build `bl31.bin` that gets packaged into `tispl.bin`. For HS devices, this binary needs to be signed.

    ::

        $ git clone https://git.trustedfirmware.org/TF-A/trusted-firmware-a.git

        Example use:
        $ make ARCH=aarch64 CROSS_COMPILE=aarch64-none-linux-gnu- PLAT=k3 TARGET_BOARD=lite SPD=opteed

OPTEE:

   The OPTEE source is used to build `bl32.bin/tee-pager_v2.bin` that gets packaged into `tispl.bin`. For HS devices, this binary needs to be signed.

    ::

        $ git clone https://github.com/OP-TEE/optee_os.git

        Example use:
        $ make CROSS_COMPILE64=aarch64-linux-gnu- PLATFORM=k3-<soc> CFG_ARM64_core=y

Ti-linux-firmware:

    The ti-linux-firmware is a TI repository where all firmware releases are stored. Firmwares for a device family can also be found in the pre-built SDK
    under <path-to-tisdk>/board-support/prebuilt-images. The firmware binary locations need to be specified in K3-Image-Gen build instructions for AM64x
    family devices and K3-Image-Gen and U-boot build instructions for AM62x family devices.

    ::

        $ <https://git.ti.com/git/processor-firmware/ti-linux-firmware.git
        Branch: ti-linux-firmware.