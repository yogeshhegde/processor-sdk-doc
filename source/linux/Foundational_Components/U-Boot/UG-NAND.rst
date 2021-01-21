NAND
-----------------------------------

.. ifconfig:: CONFIG_part_family in ('J7_family')

    .. note::
        NAND is not supported on J721E platform.

This section documents how to write files to the NAND device and use it
to load and then boot the Linux Kernel using a root filesystem also
found on NAND.

Erasing, Reading and Writing to/from NAND partitions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric:: Listing NAND partitions
   :name: listing-nand-partitions

Below command is used to see the list of mtd devices enabled in U-boot

::

    mtdparts

Example output on DRA71x EVM:

::

    device nand0 <nand.0>, # parts = 10
     #: name                size            offset          mask_flags
     0: NAND.SPL            0x00020000      0x00000000      0
     1: NAND.SPL.backup1    0x00020000      0x00020000      0
     2: NAND.SPL.backup2    0x00020000      0x00040000      0
     3: NAND.SPL.backup3    0x00020000      0x00060000      0
     4: NAND.u-boot-spl-os  0x00040000      0x00080000      0
     5: NAND.u-boot         0x00100000      0x000c0000      0
     6: NAND.u-boot-env     0x00020000      0x001c0000      0
     7: NAND.u-boot-env.backup10x00020000   0x001e0000      0
     8: NAND.kernel         0x00800000      0x00200000      0
     9: NAND.file-system    0x0f600000      0x00a00000      0

Note: In later sections the <partition name> symbol should be replaced
with the partition name seen when executing the mtdparts command.

.. rubric:: Erasing Partition
   :name: erasing-partition

::

    nand erase.part <partition name>

.. rubric:: Writing to Partition
   :name: writing-to-partition

When writing to NAND partition the file to be written must have
previously been copied to memory.

::

    nand write <ddr address> <partition name> <file size>

The symbol <ddr address> refers to the location in memory that a file
was read into DDR memory. The symbol <file size> represents the amount
of bytes (in hex) of the file to write into the NAND partition. Note:
When reading a file into DDR, U-boot by default sets the value of
environment variable "filesize" to the number of bytes (in hex) that was
read via the last read/load command.

| 
| As an example below shows the process of writing a kernel (zImage)
  into the NAND's kernel partition. The zImage to be written is loaded
  from the SD card's rootfs (2nd) partition. Loading zImage from MMC to
  DDR memory

::

    U-Boot # mmc dev 0;
    U-Boot # setenv devnum 0
    U-Boot # setenv devtype mmc
    U-Boot # mmc rescan
    U-Boot # load ${devtype} 1:2 ${loadaddr} /boot/zImage

Now that zImage is loaded into memory time to write it into the NAND
partition

::

    U-Boot # nand erase.part NAND.kernel
    U-Boot # nand write ${loadaddr} NAND.kernel ${filesize}

.. rubric:: Reading from Partition
   :name: reading-from-partition

::

    nand read <ddr address> <partition name>

The symbol <ddr address> should be replaced with the location in DDR
that you want the contents of the NAND partition to be copied to. The
symbol <partition name> contains the NAND partition name you want to
read from.

| 

Writing to NAND via DFU
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Currently in boards that support using DFU, the default build supports
writing to NAND, so no custom build is required. To see the list of
available places to write to (in DFU terms, altsettings) use the
**mtdparts** command to list the known MTD partitions and **printenv
dfu\_alt\_settings** to see how they are mapped and exposed to
**dfu-util**.

::

    U-Boot # mtdparts

    device nand0 <nand0>, # parts = 8
     #: name                size            offset          mask_flags
     0: NAND.SPL            0x00020000      0x00000000      0
     1: NAND.SPL.backup1    0x00020000      0x00020000      0
     2: NAND.SPL.backup2    0x00020000      0x00040000      0
     3: NAND.SPL.backup3    0x00020000      0x00060000      0
     4: NAND.u-boot         0x001e0000      0x00080000      0
     5: NAND.u-boot-env     0x00020000      0x00260000      0
     6: NAND.kernel         0x00500000      0x00280000      0
     7: NAND.file-system    0x0f880000      0x00780000      0

    active partition: nand0,0 - (SPL) 0x00080000 @ 0x00000000
    U-Boot # printenv dfu_alt_info_nand
    dfu_alt_info=NAND.SPL part 0 1;NAND.SPL.backup1 part 0 2;NAND.SPL.backup2 part 0 3;NAND.SPL.backup3 part 0 4;NAND.u-boot part 0 5;NAND.kernel part 0 7;NAND.file-system part 0 8

This means that you can tell dfu-util to write anything to any of:

-  NAND.SPL
-  NAND.SPL.backup1
-  NAND.SPL.backup2
-  NAND.SPL.backup3
-  NAND.u-boot
-  NAND.kernel
-  NAND.file-system

Before writing you must erase at least the area to be written to. Then
to start DFU on the target on the first NAND device:

::

    U-Boot # nand erase.chip
    U-Boot # setenv dfu_alt_info ${dfu_alt_info_nand}
    U-Boot # dfu 0 nand 0

Then on the host PC to write **MLO** to the first SPL partition:

::

    $ sudo dfu-util -D MLO -a NAND.SPL

NAND Boot
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

If you want to load and run U-Boot from NAND the first step is insuring
that the appropriate U-boot files are loaded in the correct partition.
For AM335x, AM437x, DRA7x devices this means writing the file MLO to the
NAND's SPL partition. For OMAP-L138 device, write the .ais image to the
NAND's partition. For all devices this requires writing u-boot.img to
the NAND's U-Boot partition.

.. note:: 
  The NAND partition of OMAP-L138 is different from other devices, please use the
  following commands to program the NAND

::

      => setenv ipaddr <EVM_IPADDR>
      => setenv serverip <TFTP_SERVER_IPADDR> 
      => tftp ${loadaddr} ${serverip}:u-boot-omapl138-lcdk.ais
      => print filesize
      => nand erase 0x20000 <hex_len>
      => nand write ${loadaddr} 0x20000 <hex_len>
      * hex_len is next sector boundary of the filesize. The sector size is 0x10000.
      set dip switch to NAND boot and power cycle the EVM
      

Once the file(s) have been written to NAND the board should then be
powered off. Next evm's boot switches need to be configured for NAND
booting. To understand the appropriate boot switches settings please see
the evm's hardware setup guide.

| 

Booting Kernel and Filesystem from NAND
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

If a user wants to use NAND as their primary storage then the NAND flash
must have individual partitions for all the critical software needed to
boot the kernel. At a minimum this includes kernel, dtb, file system.
Some SoCs require additional files and firmware which also need to be
stored in different NAND partitions.

Similar to booting the kernel from any interface the user must insure
that all required files needed for booting are loaded in DDR memory. The
only exception is the filesystem which will be loaded by the kernel via
the bootargs parameters. Bootargs contains information passed to the
kernel including where and how to mount the file system.

The below contains example bootargs used by DRA7x evm for using a ubifs
filesystem

::

    setenv bootargs console=${console} ${optargs} root=ubi0:rootfs rw ubi.mtd=NAND.file-system,2048 rootfstype=ubifs rootwait=1

In the above example bootargs, "rootfs" stands for the value specified
by in the "vol\_name" parameter defined in the ubinize.cfg file. In
ubi.mtd "NAND.file-system" and "2048" represents the name of the
partition that contains the ubifs and page size. Rootfstype simply tells
the kernel what type of file system to use.

By default for our evms properly loading, setting bootargs and booting
the kernel is handled by running "run nandboot" in U-boot. Information
on creating a UBIFS can be found
`here <Foundational_Components/Kernel/Kernel_Drivers/Storage/NAND.html#building-ubi-file-system>`__.
