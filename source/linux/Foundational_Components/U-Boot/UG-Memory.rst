SD, eMMC and USB
----------------

The commands for using SD cards, eMMC flash and USB mass storage devices
(hard drives, flash drives, card readers, etc) are all very similar. The
biggest difference is that on some hardware we may not be able to run
U-Boot out of ROM from the storage device as it is unsupported. Once
U-Boot is running however, any of these may be used for the kernel and
the root filesystem.

Usually in all the platforms there will be two MMC instances of which one
would be SD and the other would be eMMC. The index of them can vary from
one class of platforms to the other. For a given platform, the device
number (device num) can be found in the following way,

::

     U-Boot# mmc list
     sdhci@fa10000: 0 (eMMC)
     sdhci@fa00000: 1 (SD)


Partitioning eMMC from U-Boot
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The eMMC device typically ships without any partition table. We make use
of the GPT support in U-Boot to write a GPT partition table to eMMC. In
this case we need to use the **uuidgen** program on the host to create
the UUIDs used for the disk and each partition.

::

    $ uuidgen
    ...first uuid...
    $ uuidgen
    ...second uuid...

::

    U-Boot # printenv partitions
    uuid_disk=${uuid_gpt_disk};name=rootfs,start=2MiB,size=-,uuid=${uuid_gpt_rootfs}
    U-Boot # setenv uuid_gpt_disk ...first uuid...
    U-Boot # setenv uuid_gpt_rootfs ...second uuid...
    U-Boot # gpt write mmc <device num> ${partitions} /* <device num> is device index obtained from mmc list for eMMC */

A reset is required for the partition table to be visible.

Updating an SD card from a host PC
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

This section assume that you have created an SD card following the
instructions on `Processor SDK Linux Create SD Card
Script <Overview/Processor_SDK_Linux_create_SD_card_script.html>`__ or have
made a compatible layout by hand. In this case, you will need to copy
the all the boot images (**MLO** and **u-boot.img** for 32-bit platforms,
**tiboot3.bin**, **sysfw.itb**, **tispl.bin**, **u-boot.img** for K3 based platforms,
except AM64x and J7200 in which **sysfw.itb** is already combined with **tiboot3.bin**)
files to the *boot* partition. At this point, the card is now bootable in the SD card slot.
We default to using **/boot/${bootfile}** on the *rootfs* partition and the device tree file
loaded from **/boot** with the same name as in the kernel.

.. ifconfig:: CONFIG_part_family in ('GEN')

    However, if you are using OMAP-L138 based board (like the LCDK), then
    you need to write the generated ``u-boot.ais`` image to the SD card
    using ``dd`` command.

    ::

        $ sudo dd if=u-boot.ais of=/dev/sd<N> seek=117 bs=512 conv=fsync

Updating an SD card or eMMC using DFU
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To see the list of available places to write to (in DFU terms,
altsettings) use the **mmc part** command to list the partitions on the
MMC device and **printenv dfu\_alt\_settings\_mmc** or
**dfu\_alt\_settings\_emmc** to see how they are mapped and exposed to
**dfu-util**.

::

    U-Boot# mmc part

    Partition Map for MMC device 0  --   Partition Type: DOS

    Partition     Start Sector     Num Sectors     Type
        1                   63          144522       c Boot
        2               160650         1847475      83
        3              2024190         1815345      83
    U-Boot# printenv dfu_alt_info_mmc
    dfu_alt_info=boot part 0 1;rootfs part 0 2;MLO fat 0 1;u-boot.img fat 0 1;uEnv.txt fat 0 1"

.. note::
	The above command mmc part lists the partitions in the current
	selected device. So, to list the partitions in eMMC or SD one needs to
	switch to the required device by using the command ``mmc dev <device
	num>``.

This means that you can tell dfu-util to write anything to any of:

-  boot
-  rootfs
-  MLO
-  u-boot.img
-  uEnv.txt

And that the **MLO**, **u-boot.img** and **uEnv.txt** files are to be
written to a FAT filesystem.

To start DFU on the target on the first MMC device:

::

    U-Boot # setenv dfu_alt_info ${dfu_alt_info_mmc}
    U-Boot # dfu 0 mmc 0

On boards like AM57x GP EVM or BeagleBoard x15, where the second USB
instance is used as USB client, the dfu command becomes:

::

    U-Boot # dfu 1 mmc 0

Then on the host PC to write **MLO** to an existing boot partition:

::

    $ sudo dfu-util -D MLO -a MLO

On the host PC to overwrite the current boot partition contents with a
new created on the host FAT filesystem image:

::

    $ sudo dfu-util -D fat.img -a boot

.. ifconfig:: CONFIG_part_family not in ('AM64X')

    Updating an SD card or eMMC with RAW writes
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    In some cases it is desirable to write **MLO** and **u-boot.img** as raw
    images to the MMC device rather than in a filesystem. eMMC requires
    this, for example. In that case, the following is how to program these
    files and not overwrite the partition table on the device. We assume
    that the files exist on a SD card. In addition you may wish to write a
    filesystem image to the device, so an example is also provided.

    ::

        U-Boot # mmc dev 0
        U-Boot # mmc rescan
        U-Boot # mmc dev 1
        U-Boot # fatload mmc 0 ${loadaddr} MLO
        U-Boot # mmc write ${loadaddr} 0x100 0x100
        U-Boot # mmc write ${loadaddr} 0x200 0x100
        U-Boot # fatload mmc 0 ${loadaddr} u-boot.img
        U-Boot # mmc write ${loadaddr} 0x300 0x400
        U-Boot # fatload mmc 0 ${loadaddr} rootfs.ext4
        U-Boot # mmc write ${loadaddr} 0x1000 ...rootfs.ext4 size in bytes divided by 512, in hex...

Booting Linux from SD card or eMMC
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Within the default environment for each board that supports SD/MMC there
is a boot command called **mmcboot** that will set the boot arguments
correctly and start the kernel. In this case however, you must first run
**loaduimagefat** or **loaduimage** to first load the kernel into
memory. For the exact details of each use **printenv** on the
**mmcboot**, **loaduimagefat** and **loaduimage** variables and then in
turn **printenv** other sub-sections of the command. The most important
variables here are **mmcroot** and **mmcrootfstype**.

.. ifconfig:: CONFIG_part_family in ('AM335X', 'AM437X', 'AM57X', 'GEN')

    Booting MLO and u-boot from eMMC boot partition (For non-K3 class of SoCs)
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    The dra7xx and am57xx processors support booting from the eMMC boot
    partition. The following commands load the boot images from network and
    write them into the boot0 partition.

    ::

        U-boot # setenv autoload no
        U-boot # dhcp
        U-boot # mmc dev 1 1
        U-boot # tftp ${loadaddr} dra7xx/MLO
        U-boot # mmc write ${loadaddr} 0x0 0x300
        U-boot # tftp ${loadaddr} dra7xx/u-boot.img
        U-boot # mmc write ${loadaddr} 0x300 0x400

    We also need to configure the eMMC using the bootbus and partconf commands.
    The bootbus command sets the eMMC into dual data rate mode with a bus width
    of 8 to match with the bus configuration supported by the Boot ROM. The
    partconf command gives access to the boot0 partition during boot operation.
    Note that these configurations are limited to boot operation and the eMMC
    can be set to its highest speed mode once boot operation is complete. All
    these are non-volatile configurations that need to be done **once per
    eMMC/board** .

    ::

        U-boot # mmc bootbus 1 2 0 2
        U-boot # mmc partconf 1 1 1 0
        U-boot # mmc rst-function 1 1

Booting tiboot3.bin, tispl.bin and u-boot.img from eMMC boot partition (For K3 class of SoCs)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The K3 based processors support booting from the eMMC boot partition.
The following commands can be used to download tiboot3.bin, tispl.bin and
u-boot.img from an SD card and write them to the eMMC boot0 partition at
respective addresses.

.. ifconfig:: CONFIG_part_family not in ('AM64X_family')

  .. code-block:: console

    => mmc dev 0 1
    => fatload mmc 1 ${loadaddr} tiboot3.bin
    => mmc write ${loadaddr} 0x0 0x400
    => fatload mmc 1 ${loadaddr} tispl.bin
    => mmc write ${loadaddr} 0x400 0x1000
    => fatload mmc 1 ${loadaddr} u-boot.img
    => mmc write ${loadaddr} 0x1400 0x2000
    => fatload mmc 1 ${loadaddr} sysfw.itb
    => mmc write ${loadaddr} 0x3600 0x800


.. ifconfig:: CONFIG_part_family in ('AM64X_family')

  .. code-block:: console

    => mmc dev 0 1
    => fatload mmc 1 ${loadaddr} tiboot3.bin
    => mmc write ${loadaddr} 0x0 0x400
    => fatload mmc 1 ${loadaddr} tispl.bin
    => mmc write ${loadaddr} 0x400 0x1000
    => fatload mmc 1 ${loadaddr} u-boot.img
    => mmc write ${loadaddr} 0x1400 0x2000


.. ifconfig:: CONFIG_part_family in ('J7_family')

  In J7200 the memory layout is different. Therefore, use the following commands

  .. code-block:: console

    => mmc dev 0 1
    => fatload mmc 1 ${loadaddr} tiboot3.bin
    => mmc write ${loadaddr} 0x0 0x800
    => fatload mmc 1 ${loadaddr} tispl.bin
    => mmc write ${loadaddr} 0x800 0x1000
    => fatload mmc 1 ${loadaddr} u-boot.img
    => mmc write ${loadaddr} 0x1800 0x2000



To give the ROM access to the boot partition, the following commands must be
used for the first time:

.. code-block:: console

  => mmc partconf 0 1 1 1
  => mmc bootbus 0 2 0 0

- eMMC layout:

.. ifconfig:: CONFIG_part_family not in ('AM64X_family')

  .. code-block:: console

               boot0 partition (8 MB)                        user partition
       0x0+----------------------------------+      0x0+-------------------------+
          |     tiboot3.bin (512 KB)         |         |                         |
     0x400+----------------------------------+         |                         |
          |       tispl.bin (2 MB)           |         |                         |
    0x1400+----------------------------------+         |        rootfs           |
          |       u-boot.img (4 MB)          |         |                         |
    0x3400+----------------------------------+         |                         |
          |      environment (128 KB)        |         |                         |
    0x3500+----------------------------------+         |                         |
          |   backup environment (128 KB)    |         |                         |
    0x3600+----------------------------------+         |                         |
          |          sysfw (1 MB)            |         |                         |
    0x3E00+----------------------------------+         +-------------------------+


.. ifconfig:: CONFIG_part_family in ('AM64X_family')

  .. code-block:: console

               boot0 partition (7 MB)                        user partition
       0x0+----------------------------------+      0x0+-------------------------+
          |     tiboot3.bin (512 KB)         |         |                         |
     0x400+----------------------------------+         |                         |
          |       tispl.bin (2 MB)           |         |                         |
    0x1400+----------------------------------+         |        rootfs           |
          |       u-boot.img (4 MB)          |         |                         |
    0x3400+----------------------------------+         |                         |
          |      environment (128 KB)        |         |                         |
    0x3500+----------------------------------+         |                         |
          |   backup environment (128 KB)    |         |                         |
    0x3600+----------------------------------+         +-------------------------+


.. ifconfig:: CONFIG_part_family in ('J7_family')

  - Shown below is the eMMC layout in J7200, which is different from other devices.

  .. code-block:: console

                boot0 partition (8 MB)                        user partition
       0x0+----------------------------------+      0x0+-------------------------+
          |     tiboot3.bin (1 MB)           |         |                         |
     0x800+----------------------------------+         |                         |
          |       tispl.bin (2 MB)           |         |                         |
    0x1800+----------------------------------+         |        rootfs           |
          |       u-boot.img (4 MB)          |         |                         |
    0x3800+----------------------------------+         |                         |
          |      environment (128 KB)        |         |                         |
    0x3900+----------------------------------+         |                         |
          |   backup environment (128 KB)    |         |                         |
    0x3A00+----------------------------------+         +-------------------------+


.. note::
	rootfs is written to the user partition. The user partition is
	first required to be formatted as a ext4 file system and then the rootfs
	has to be written. It is not possible to format a partition to ext4 in
	U-Boot. It is required to boot to kernel and write rootfs to user partition
	after formatting it to ext4. Kernel image and DT are expected to be present
	in the /boot folder of rootfs.

To boot kernel from eMMC, use the following commands after writing rootfs to user partition:

::

    => setenv mmcdev 0
    => setenv bootpart 0
    => boot

|

.. ifconfig:: CONFIG_part_family not in ('AM64X')

    Booting Linux from USB storage
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    To load the Linux Kernel and rootfs from USB rather than SD/MMC card on
    AMx/DRA7x EVMs, if we assume that the USB device is partitioned the same
    way as an SD/MMC card is, we can utilize the **mmcboot** command to
    boot. To do this, perform the following steps:

    ::

        U-Boot # usb start
        U-Boot # setenv mmcroot /dev/sda2 ro
        U-Boot # run mmcargs
        U-Boot # run bootcmd_usb

    On K2H/K/E/L EVMs, the USB drivers in Kernel needs to be built-in
    (default modules). The configuration changes are:

    ::

        CONFIG_USB=y
        CONFIG_USB_XHCI_HCD=y
        CONFIG_USB_XHCI_PCI=y
        CONFIG_USB_XHCI_PLATFORM=y
        CONFIG_USB_STORAGE=y
        CONFIG_USB_DWC3=y
        CONFIG_USB_DWC3_HOST=y
        CONFIG_USB_DWC3_KEYSTONE=y
        CONFIG_EXTCON=y
        CONFIG_EXTCON_USB_GPIO=y
        CONFIG_SCSI_MOD=y
        CONFIG_SCSI=y
        CONFIG_BLK_DEV_SD=y

    The USB should have boot partition of FAT32 format, and rootfs partition
    of EXT4 format. The boot partition must contain the following images:

    ::

        keystone-<platform>-evm.dtb
        skern-<platform>.bin
        k2-fw-initrd.cpio.gz
        zImage

        where <platform>=k2hk, k2e, k2l

    The rootfs partition contains the filesystem from ProcSDK release
    package.

    ::

        # mkdir /mnt/temp
        # mount -t ext4 /dev/sdb2 /mnt/temp
        # cd /mnt/temp
        # tar xvf <Linux_Proc_Sdk_Install_DIR>/filesyste/tisdk-server-rootfs-image-k2hk-evm.tar.xz
        # cd /mnt
        # umount temp

    Set up the following u-boot environment variables:

    ::

        setenv args_all 'setenv bootargs console=ttyS0,115200n8 rootwait'
        setenv args_usb 'setenv bootargs ${bootargs} rootdelay=3 rootfstype=ext4 root=/dev/sda2 rw'
        setenv get_fdt_usb 'fatload usb 0:1 ${fdtaddr} ${name_fdt}'
        setenv get_kern_usb 'fatload usb 0:1 ${loadaddr} ${name_kern}'
        setenv get_mon_usb 'fatload usb 0:1 ${addr_mon} ${name_mon}'
        setenv init_fw_rd_usb 'fatload usb 0:1 ${rdaddr} ${name_fw_rd}; setenv filesize <hex_len>; run set_rd_spec'
        setenv init_usb 'usb start; run args_all args_usb'
        setenv boot usb
        saveenv
        boot

    **Note:**: <hex\_len> must be at least the hex size of the k2-fw-initrd.cpio.gz file size.

    .. ifconfig:: CONFIG_part_family in ('J7_family')

        .. rubric:: Enabling USB 3.0 host port on J721e EVM
           :name: j721e-evm-usb-30-host

        .. note::
            J721e SoC does not support booting from USB mass storage devices. But can be used as storage device at U-Boot prompt.

        USB0 instance on J721e base board is connected to TypeC port that can be
        used both as host port and device port. By default, USB0 is port is
        configured to be in **peripheral mode**. Since U-Boot does not support
        dynamic switching of USB roles, below DT fragment needs to be
        applied and U-Boot image needs to be rebuilt to make USB0 port to be
        USB 3.0 host port.

        ::

            diff --git a/arch/arm/dts/k3-j721e-common-proc-board-u-boot.dtsi b/arch/arm/dts/k3-j721e-common-proc-board-u-boot.dtsi
            index 50effb4812b2..28986c4d2c2a 100644
            --- a/arch/arm/dts/k3-j721e-common-proc-board-u-boot.dtsi
            +++ b/arch/arm/dts/k3-j721e-common-proc-board-u-boot.dtsi
            @@ -184,11 +184,10 @@

             &usbss0 {
                    u-boot,dm-spl;
            -       ti,usb2-only;
             };

             &usb0 {
            -       dr_mode = "peripheral";
            +       dr_mode = "host";
                    u-boot,dm-spl;
             };

    Booting from SD/eMMC from SPL (Single stage or Falcon mode)
    ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

    .. note::
        Falcon mode is not supported on K3 family of devices.

    In this boot mode SPL (first stage bootloader) directly boots the Linux
    kernel. Optionally, in order to enter into U-Boot, reset the board while
    keeping 'c' key on the serial terminal pressed. When falcon mode is
    enabled in U-Boot build (usually enabled by default), ``MLO`` checks if
    there is a valid ``uImage`` present at a defined offset. If ``uImage``
    is present, it is booted directly. If valid ``uImage`` is not found,
    ``MLO`` falls back to checking if the ``uImage`` exists in a FAT
    partition. If it fails, it falls back to booting ``u-boot.img``.

    The falcon boot uses ``uImage``. To build the kernel ``uImage``, you
    will need to keep the U-Boot tool ``mkimage`` in your ``$PATH``

    ::

        # make uImage modules dtbs LOADADDR=80008000

    If kernel is not build with ``CONFIG_CMDLINE`` to set correct bootargs,
    then add the needed ``bootargs`` in ``chosen`` node in DTB file, using
    ``fdtput`` host utility. For example, for DRA74x EVM:

    ::

        # fdtput -v -t s arch/arm/boot/dts/dra7-evm.dtb "/chosen" bootargs "console=ttyO0,115200n8 root=<rootfs>"

    ``MLO``, ``u-boot.img`` (optional), DTB, ``uImage`` are all stored on
    the same medium, either the SD or the eMMC. There are two ways to store
    the binaries in the SD (resp. eMMC):

    ::

        * raw: binaries are stored at fixed offset in the medium
        * fat: binaries are stored as file in a FAT partition

    To flash binaries to SD or eMMC, you can use DFU. For SD boot, from
    u-boot prompt

    ::

        => env default -a; setenv dfu_alt_info ${dfu_alt_info_mmc}; dfu 0 mmc 0

    For eMMC boot, from u-boot prompt

    ::

        => env default -a; setenv dfu_alt_info ${dfu_alt_info_emmc}; dfu 0 mmc 1

    Note: On boards like AM57x GP EVM or BeagleBoard x15, where the second
    USB instance is used as USB client, replace "dfu 0 mmc X" with "dfu 1
    mmc X"

    On the host side: binaries in FAT:

    ::

        $ sudo dfu-util -D MLO -a MLO
        $ sudo dfu-util -D u-boot.img -a u-boot.img
        $ sudo dfu-util -D dra7-evm.dtb -a spl-os-args
        $ sudo dfu-util -D uImage -a spl-os-image

    raw binaries:

    ::

        $ sudo dfu-util -D MLO -a MLO.raw
        $ sudo dfu-util -D u-boot.img -a u-boot.img.raw
        $ sudo dfu-util -D dra7-evm.dtb -a spl-os-args.raw
        $ sudo dfu-util -D uImage -a spl-os-image.raw

    If the binaries are files in a fat partition, you need to specify their
    name if they differ from the default values ("uImage" and "args"). Note
    that DFU uses the names "spl-os-image" and "spl-os-args", so this step
    is required in the case of DFU. From u-boot prompt

    ::

        => setenv falcon_image_file spl-os-image
        => setenv falcon_args_file spl-os-args
        => saveenv

    Set the environment variable "boot\_os" to 1. From u-boot prompt

    ::

        => setenv boot_os 1
        => saveenv

    Set the board boot from SD (or eMMC respectively) and reset the EVM. The
    SPL directly boots the kernel image from SD (or eMMC).
