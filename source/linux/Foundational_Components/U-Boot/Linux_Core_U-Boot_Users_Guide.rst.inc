.. convert from page http://processors.wiki.ti.com/index.php/Linux_Core_U-Boot_User%27s_Guide

U-Boot User's Guide
======================

Overview
-----------

This document covers the general use of Linux Core Release of U-Boot on
following platforms:

**32-bit platforms**

	-  `AM335x GP EVM <http://www.ti.com/tool/tmdxevm3358>`__
	-  `AM335x EVM-SK <http://www.ti.com/tool/tmdssk3358>`__
	-  `AM335x ICE <http://www.ti.com/tool/tmdsice3359>`__
	-  `BeagleBone White <http://beagleboard.org/bone>`__
	-  `BeagleBone Black <https://beagleboard.org/black>`__
	-  `DRA76x EVM <http://www.ti.com/tool/J6PEVM577P>`__
	-  `DRA74x EVM <http://www.ti.com/tool/j6evm5777>`__
	-  `DRA72x EVM <http://www.ti.com/tool/dra72xevm>`__
	-  `DRA71x EVM <http://www.ti.com/product/DRA718>`__
	-  `AM437x GP EVM <http://www.ti.com/tool/tmdsevm437x>`__
	-  AM43xx ePOS EVM
	-  `AM437x EVM-SK <http://www.ti.com/tool/tmdxsk437x>`__
	-  `AM437x IDK <http://www.ti.com/tool/TMDSIDK437X>`__
	-  `AM574x IDK <http://www.ti.com/tool/TMDSIDK574>`__
	-  `AM572x GP EVM <http://www.ti.com/tool/tmdsevm572x>`__
	-  `AM572x IDK <http://www.ti.com/tool/TMDXIDK5728>`__
	-  `AM571x IDK <http://www.ti.com/tool/tmdxidk5718>`__
	-  `66AK2H EVM <http://www.ti.com/tool/EVMK2H>`__
	-  K2K EVM
	-  `K2Ex EVM <http://www.ti.com/tool/xevmk2ex>`__
	-  `K2L EVM <http://www.ti.com/tool/xevmk2lx>`__
	-  `K2G GP EVM <http://www.ti.com/tool/evmk2g>`__
	-  `K2G ICE EVM <http://www.ti.com/tool/k2gice>`__
	-  `OMAP-L138 LCDK <http://www.ti.com/product/omap-l138>`__

**64-bit platforms**

	-  `AM65x EVM <http://www.ti.com/tool/TMDX654GPEVM>`__
	-  `AM65x IDK <http://www.ti.com/tool/TMDX654IDKEVM>`__
	-  `J721E EVM <http://www.ti.com/tool/J721EXSOMXEVM>`__
	-  `J7200 EVM <http://www.ti.com/tool/J7200XSOMXEVM>`__


+-------------------+
|K3 family of SoCs  |
+===================+
| AM65              |
+-------------------+
| J721E             |
+-------------------+
| J7200             |
+-------------------+
| AM64              |
+-------------------+


NOR
---------------------------------------

.. ifconfig:: CONFIG_part_family in ('J7_family')

    .. note::
        Parallel NOR is not supported on J721E platform.

This section documents how to write files to the NOR device and use it
to load and then boot the Linux Kernel using a root filesystem also
found on NOR. In order for NOR to be visible to U-Boot a special build
of U-Boot is required on the supported hardware. The table below lists
builds that see NOR and in some cases also use theit for the environment
instead of the default, which typically is NAND. Finally, for simplicity
we assume the files are being loaded from an SD card. Using the network
interface (if applicable) is documented above.

Writing to NOR from U-Boot
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Note:

-  From the U-Boot build, the **u-boot.bin** file is the one to be
   written.
-  We load all files from an SD card in this example but they can just
   as easily be loaded via network (documented above) or other interface
   that exists.
-  At this time the NOR mtd partition map has not yet been updated to
   include an example location for the device tree.

+--------------+-----------------------------------------------------------+
| Board        | Config target                                             |
+==============+===========================================================+
| AM335x EVM   | am335x\_evm\_nor\_config / am335x\_evm\_norboot\_config   |
+--------------+-----------------------------------------------------------+

::

    U-Boot # mmc rescan
    U-Boot # load mmc 0 ${loadaddr} u-boot.bin
    U-Boot # protect off 08000000 +4c0000
    U-Boot # erase 08000000 +4c0000
    U-Boot # cp.b ${loadaddr} 08000000 ${filesize}
    U-Boot # fatload mmc 0 ${loadaddr} zImage
    U-Boot # cp.b ${loadaddr} 080c0000 ${filesize}

Booting from NOR
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Within the default environment there is not a shortcut for booting. One
needs to pass **root=/dev/mtdblockN** where N is the number of the
rootfs partition in **bootargs**.

|

UART
------------------------------------


This section documents how to use the UART to load files to boot the
board into U-Boot. After that the user is expected to know how they want
to continue loading files.

Booting U-Boot from the console UART
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

In some cases we support loading SPL and U-Boot over the console UART.
You will need to use the **spl/u-boot-spl.bin** and **u-boot.img** files
to boot. As per the TRM, the file is to be loaded via the X-MODEM
protocol at 115200 baud 8 stop bits no parity (same as using it for
console). SPL in turn expects to be sent **u-boot.img** at the same rate
but via Y-MODEM. An example session from the host PC, assuming console
is on ttyUSB0 and already configured would be and the **lrzsz** package
is installed

::

    $ sx -kb /path/to/u-boot-spl.bin < /dev/ttyUSB0 > /dev/ttyUSB0
    $ sx -kb --ymodem /path/to/u-boot.img < /dev/ttyUSB0 > /dev/ttyUSB0

In K3 based platforms, ROM supports booting from MCU_UART0 via X-Modem protocol.
The entire UART-based boot process up to U-Boot (proper) prompt goes through
different stages and uses different UART peripherals as follows:

+---------------+---------------+-------------+------------+
|   WHO         | Loading WHAT  |  HW Module  |  Protocol  |
+===============+===============+=============+============+
| Boot ROM      |  tiboot3.bin  |  MCU_UART0  |  X-Modem   |
+---------------+---------------+-------------+------------+
| R5 SPL        |  sysfw.itb    |  MCU_UART0  |  Y-Modem   |
+---------------+---------------+-------------+------------+
| R5 SPL        |  tispl.bin    |  MAIN_UART0 |  Y-Modem   |
+---------------+---------------+-------------+------------+
| A53/A72 SPL   |  u-boot.img   |  MAIN_UART0 |  Y-Modem   |
+---------------+---------------+-------------+------------+

UART_BOOT_MAIN_UART and UART_BOOT_MCU_UART should be set to serial ports such as /dev/ttyUSBx.

::

    $ sb --xmodem $OUT_R5/tiboot3.bin > $UART_BOOT_MCU_UART < $UART_BOOT_MCU_UART
    $ sb --ymodem $SYSFW_ITB > $UART_BOOT_MCU_UART < $UART_BOOT_MCU_UART
    $ sb --ymodem $OUT_AXX/tispl.bin > $UART_BOOT_MAIN_UART < $UART_BOOT_MAIN_UART
    $ sb --xmodem $OUT_AXX/u-boot.img > $UART_BOOT_MAIN_UART < $UART_BOOT_MAIN_UART

SATA
------------------------------------

.. note::
    SATA is not supported on J721E platform.

SATA and eSATA devices show up as SCSI devices in U-boot.

Viewing SATA Devices
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
To view all SCSI devices that U-boot sees the command "scsi info" can be
used.

Output of this command when ran on AM57x General Purpose EVM can be seen
below.

::

    scsi part
    Device 0: (0:0) Vendor: ATA Prod.: PLEXTOR PX-64M6M Rev: 1.08
                Type: Hard Disk
                Capacity: 61057.3 MB = 59.6 GB (125045424 x 512)

Device 0 represents the instance of the scsi device. Therefore, in later
commands when a "<dev>" parameter is seen replace it with the
appropriate device number.

Viewing Partitions
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
To view all the partitions found on the SATA device the command "scsi
part <dev>" can be used.

Output of this command when ran on AM57x General Purpose EVM can be seen
below.

::

    Partition Map for SCSI device 0  --   Partition Type: DOS

    Part    Start Sector    Num Sectors     UUID            Type
      1     2048            161793          6cc50771-01     0c Boot
      2     165888          33552385        6cc50771-02     83
      3     33720320        91325104        6cc50771-03     83

All entries above represent different partitions that exist on the
particular scsi device. To reference a particular partition a user will
reference it the part number shown above. In commands shown below <part>
should be replaced with the appropriate partition number seen from this
table.

Identifying Partition Filesystem Type
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

As shown above the "scsi part <dev>" command can be used to view all the
partitions available on the particular scsi device. However, the proper
commands to use depend on the filesystem type each partition have been
formatted to.

In the "scsi part <dev>" command the partition type can be found under
the type column. The values under the Type column are referred to as
partition id. Depending on the partition id will dedicate which commands
to use to read and write partition. Partition id of "0c" refers to a
FAT32 partition. Partition id of "83" refers to a native Linux file
system which ext2,ext3 and ext4 fall under. Go
`here <https://en.wikipedia.org/wiki/Partition_type#List_of_partition_IDs>`__
to find a complete list of partition ids.

| 

Viewing, Reading and Writing to Partition
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Depending on the filesystem type of the partition will depend on the
exact commands to use to read and write to the partition. The two most
common partitions are FAT32, EXT2 and EXT4. Luckily the commands to
view, read and write to the partition all look the same. Viewing
partition uses <prefix>ls, reading files is <prefix>load and writing
files is <prefix>write. Replace <prefix> with fat, ext2 and ext4
depending on the filesystem type.

View Partition Contents
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To view the contents of a FAT32 partition the user would use "fatls scsi
<dev>:<partition>"

Below command list the contents of SCSI device 0 partition 1 on AM57x
General Purpose EVM:

::

    => fatls scsi 0:1
       110578   test
    1 file(s), 0 dir(s)

.. rubric:: Write File to Partition
   :name: write-file-to-partition

To write a file on a EXT4 partition the user must have first read the
file to be written into memory and then also know the size of the file.
Luckily U-boot automatically sets the environment variable "filesize" to
the filesize of a file that was loaded into memory via U-boot load
command.

To write to a ext4 partition the user would execute the below command:
ext4write scsi <dev>:<partition> <ddr address> <absolute filename path>
<filesize>

In the above command <ddr address> refers to the address in memory the
file has already been loaded into. Absolute filename path must start
with / to indicate the root. Filesize is the amount in bytes to be
written.

Below is an example of writing the file "tester" previously loaded into
memory onto a EXT4 partition

::

    => ext4write scsi 0:3 ${loadaddr} /tester ${filesize}
    File System is consistent
    update journal finished
    110578 bytes written in 2650 ms (40 KiB/s)

|

UFS
---------------------------

Universal Flash Subsystem (UFS) devices show up as scsi devices similar
to SATA in the `previous section <Foundational_Components_U-Boot.html#sata>`__.
One additional command to initialize all ufs devices is:

::
    => ufs init
    Device at ufs@4e84000 up at:[RX, TX]: gear=[3, 3], lane[2, 2], pwr[FAST MODE, FAST MODE], rate = 2

|

Then we can go ahead with 'scsi scan' to see the attached devices:

::

    => scsi scan
    scanning bus for devices...
  Device 0: (0:0) Vendor: TOSHIBA Prod.: THGAF8G8T23BAILB Rev: 0300
            Type: Hard Disk
            Capacity: 31.9 MB = 0.0 GB (8191 x 4096)
  Device 0: (0:1) Vendor: TOSHIBA Prod.: THGAF8G8T23BAILB Rev: 0300
            Type: Hard Disk
            Capacity: 30499.9 MB = 29.7 GB (7807999 x 4096)

|

All the remaining scsi commands detailed in the
`previous section <Foundational_Components_U-Boot.html#sata>`__ are
also applicable.

For more information about UFS see
`Kernel UFS Guide <Foundational_Components_Kernel_Drivers.html#ufs>`__.

DDR3 ECC
-------------

.. note::
    DDR3 ECC feature described below is enabled for Keystone-II devices.

DDR3 ECC in Keystone-II
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Some of the TI SoC devices have DDR ECC enabled. Keystone-II devices (K2H/K2E/K2G) enable the
DDR3 error detection and correction feature. The DDR3 controller supports ECC on the data
written or read from the SDRAM and is enabled by programming the ECC Control register.
8-bit ECC is calculated over 64-bit data quanta for K2H and K2E, but 4-bit ECC over 32-bit data for K2G.
The ECC is calculated for all accesses that are within the address ranges protected by ECC.
1-bit error is correctable by ECC and 2-bit error is not correctable and will be treated as
unrecoverable error by software and trigger the reset of the device.

DDR3 ECC Handling
"""""""""""""""""""

Keystone-II U-boot checks if the DDR3 controller supports ECC RMW or not.
If ECC RMW is not supported (in K2H PG1.x devices), U-boot will disable the ECC by default,
otherwise it always enables ECC (in K2H PG2.0, K2E, and K2G devices)

During the ECC initialization, U-boot fills the entire memory (up to 8GB) to zeros
using an EDMA channel after ECC is enabled. For K2H device, U-boot configures
the chip level interrupt controller to route the DDR3 ECC error interrupt to
ARM interrupt controller. For K2E and K2G devices, since DDR3 ECC error interrupt is directly
routed to ARM interrupt controller, there is no need to configure the chip level interrupt controller.

A DDR3 command is added to simulate the ECC error by generating bit errors in DDR data at certain address. The command format is:

::

   ddr ecc_err <addr in hex> <bit_err in hex>

The command will read a 32-bit data from <addr>, and write (data ^ bit_err) back to <addr>

::

   E.g.:
   ddr ecc_err 0x90000000 0x1 (this will genereate a 1-bit error on bit 0 of the data in ddr address 0x9000_0000)
   ddr ecc_err 0xa0000000 0x1001 (this will genereate 2-bit error on bit 0 & 3 of the data in ddr address 0xa000_0000)

A new environment variable "ecc_test" is also introduced to test ECC. By default, ecc_test = 0, and any detection of 2-bit error will reset the device. If ecc_test = 1, U-boot will bypass the error and continues to boot Linux kernel so that Linux kernel can handle the error in interrupt service.

.. note::
  **DDR3 ECC Handling in Keystone-II Linux kernel**

  Linux kernel requests an IRQ handler for DDR3 ECC error interrupt, the handler checks the DDR3 controller interrupt
  status register, if the error is 2-bit error, Linux kernel will reboot the device. User can also use a user mode
  command to read the DDR3 ECC registers (e.g. 1-bit error count register, etc.), the DDR3 controller register and
  interrupt mapping are defined in the sysctrl node of device tree binding:

::

  E.g. K2H SOC device tree:
  sysctrl {
        reg = <0x21010000 0x0200>; /* DDR3 controller reg */
        interrupts = <0 24 0xf01    /* L1L2 ECC error interrupt */
                      0 448 0xf01>; /* DDR3 ECC error interrupt */
  };

|

HyperBus and HyperFlash
-----------------------------------
HyperBus is Low Signal Count, High Performance Double Data Rate (DDR) Bus interface between a host system master and one or more slave interfaces. Its a 8-bit data bus (DQ[7:0]) with  Read-Write Data Strobe (RWDS) signal and either Single-ended clock(3.0V parts) or Differential clock (1.8V parts). It uses ChipSelect lines to select b/w multiple slaves. At bus level, it follows a separate protocol described in HyperBus specification.

HyperFlash is a NOR flash based device storage over HyperBus.  HyperFlash follows CFI AMD/Fujitsu Extended Command Set (0x0002) similar to that of existing parallel NORs. Since Hyperbus is x8 DDR bus, its equivalent to x16 parallel NOR flash wrt bits per clk. But Hyperbus operates at very high frequencies.

HyperFlash on TI's J721E EVM is connected to HyperBus Memory Controller that supports memory mapped IO access to flash. HyperFlash is supported under MTD framework and U-Boot's standard MTD commands can be used to access HyperFlash

**Supported Devices**
- J721E EVM

To list detected HyperFlash devices:

::

 => mtd list
 List of MTD devices:
 * nor0
  - type: NOR flash
  - block size: 0x40000 bytes /* Each erase sector size is of 256KB */
  - min I/O: 0x1 bytes
  - 0x000000000000-0x000004000000 : "nor0" /* Detected 64MB devices labeled as "nor0" */

.. note::

 On J721E EVM, SW3.1 should be set to ON position to select HyperFlash.

Below Example shows how to erase and write different boot images to HyperFlash from U-Boot prompt.
Erase has to be a multiple of erase sector size.
::

 => mtd erase nor0 0 0x40000 /* Erase from offset 0 to 256KB of HyperFlash labeled nor0 */
 Erasing 0x00000000 ... 0x0003ffff (1 eraseblock(s))
 => fatload mmc 1 0x82000000 tiboot3.bin /* Load an img from SD into DDR to flash into HyperFlash */
 180932 bytes read in 10 ms (17.3 MiB/s)
 => mtd write nor0  0x82000000 0x0 $filesize /* Write the loaded image into HyperFlash labeled nor0 */
 Writing 180932 byte(s) at offset 0x00000000
 =>

Below Example shows how to read back the data

::

 => mtd read nor0 0x82000000 0x0 0x40000 /* Read from offset 0 to 0x4000 to DDR address 0x82000000 from nor0 */
 Reading 262144 byte(s) at offset 0x00000000

**Flashing Images to HyperFlash**

Below commands can be used to download tiboot3.bin, tispl.bin and
u-boot.img over tftp and then flash it to HyperFlash at respective addresses.

.. code-block:: console

  => mtd erase nor0 0 0x800000
  => tftp ${loadaddr} tiboot3.bin
  => mtd write nor0 $loadaddr 0x0 $filesize
  => tftp ${loadaddr} tispl.bin
  => mtd write nor0 $loadaddr 0x80000 $filesize
  => tftp ${loadaddr} u-boot.img
  => mtd write nor0 $loadaddr 0x280000 $filesize
  => tftp ${loadaddr} sysfw.itb
  => mtd write nor0 $loadaddr 0x6C0000 $filesize

**Flash Layout for HyperFlash**
 Below is the layout for HyperFlash in order to boot from HyperFlash:

.. code-block:: console

         0x0 +----------------------------+
             |     hbmc.tiboot3(512K)     |
             |                            |
     0x80000 +----------------------------+
             |     hbmc.tispl(2M)         |
             |                            |
    0x280000 +----------------------------+
             |     hbmc.u-boot(4M)        |
             |                            |
    0x680000 +----------------------------+
             |     hbmc.env(128K)         |
             |                            |
    0x6C0000 +----------------------------+
             |      hbmc.sysfw(1M)        |
             |                            |
    0x7C0000 +----------------------------+
             |      padding (256k)        |
    0x800000 +----------------------------+
             |     hbmc.rootfs(UBIFS)     |
             |                            |
             +----------------------------+

**Bootmode Switch Settings for J721E EVM**

After writing the images, change the bootmode switches on the EVM to the
following in order to boot from HyperFlash at 83MHz:

+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
| Switch No. | 1   | 2   | 3   | 4   | 5   | 6   | 7   | 8   | 9   | 10  |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
| SW8        | OFF | OFF | OFF | OFF | OFF | OFF | OFF | OFF | OFF | OFF |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
| SW9        | OFF | OFF | OFF | OFF | OFF | OFF | OFF | OFF | OFF | OFF |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+
| SW3        | ON  | ON  | ON  | ON  | OFF | OFF | ON  | OFF | ON  | OFF |
+------------+-----+-----+-----+-----+-----+-----+-----+-----+-----+-----+

REMOTEPROC
------------

This section documents how to initialize, load, start and stop remote cores from U-Boot prompt.
Following remotecores support is available in U-boot:

-  Cortex-R5F in Lockstep more
-  Cortex-R5F in split mode
-  C66x DSP
-  C71x DSP

Initialization
^^^^^^^^^^^^^^^

U-Boot supports for initializing all the available remotecores in one go or
initialize individual core based on the DT alias id.

The below command will initialize all the available remote cores:

::

    => rproc init

The below command will initialize just the given remote core

::

   => rproc init <id>

The below command lists all the available/initialized remotecores in the system.

::

   => rproc list
   0 - Name:'r5f@41000000' type:'internal memory mapped' supports: load start stop reset
   1 - Name:'r5f@41400000' type:'internal memory mapped' supports: load start stop reset
   2 - Name:'r5f@5c00000' type:'internal memory mapped' supports: load start stop reset
   3 - Name:'r5f@5d00000' type:'internal memory mapped' supports: load start stop reset
   4 - Name:'r5f@5e00000' type:'internal memory mapped' supports: load start stop reset
   5 - Name:'r5f@5f00000' type:'internal memory mapped' supports: load start stop reset
   6 - Name:'dsp@4d80800000' type:'internal memory mapped' supports: load start stop reset
   7 - Name:'dsp@4d81800000' type:'internal memory mapped' supports: load start stop reset
   8 - Name:'dsp@64800000' type:'internal memory mapped' supports: load start stop reset


Loading
^^^^^^^^

Once Initialized, remotecores can be loaded with a relevant image. Make sure
image is loaded only after initializing the core.

::

    => load mmc 1:2 0x90000000 /lib/firmware/j7-main-r5f0_0-fw
    2536540 bytes read in 112 ms (21.6 MiB/s)
    => rproc load 2 0x90000000 0x${filesize}
    Load Remote Processor 2 with data@addr=0x90000000 2536540 bytes: Success!


Starting
^^^^^^^^^

Successfully loaded remotecore can be started using the following command.

::

    => rproc start 2

Stop
^^^^^

A running remotecore can be stopped using the following command.

::

    => rproc stop 2

Make sure all the commands are run in the above given sequence. Currently IPC
is not supported in U-boot.

|

Uboot SPL Debugging Tips
-----------------------------

The following section demonstrates how to connect a board to CCS and load the SPL symbols for debugging. For the experiment below, users are expected to boot their board from a SD card.

Step 1: Downloading CCS
^^^^^^^^^^^^^^^^^^^^^^^^^
#. Please download the CCS from the following link: http://software-dl.ti.com/ccs/esd/documents/ccs_downloads.html

**NOTE**: We will be building Uboot on a Linux machine and it is recommended to install CCS on the same operating system (OS). If CCS is not installed on the same OS, CCS will not be able to locate the code files. Please follow the Linux instructions on the following link: http://software-dl.ti.com/ccs/esd/documents/ccs_linux_host_support.html

Step 2: Creating a Target Configuration File
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#. The first step is to create a target configuration file in CCS. Navigate to "View"-> "Target Configurations":

	.. Image:: /images/Uboot_Image1.png
#. Right click on the "Target Configurations" window and select "New Target Configuration":

	.. Image:: /images/Uboot_Image2.png
#. Create a name for target configuration:

	.. Image:: /images/Uboot_Image3.png
#. Select the appropriate SoC and JTAG. **Note**: If we select the SoC name, the GEL files will not be loaded. However, if we select the board options, the GEL files will be loaded by default. In the below example, if GPEVM_AM65x or IDK_AM65x is selected, the GEL files are automatically enabled in the configuration. While debugging Uboot, it is recommended to avoid GEL files because Uboot is responsible for initializing the peripherals:

	.. Image:: /images/Uboot_Image4.png
#. Next, click save and test connection to ensure CCS is able to communicate with the debugger:

	.. Image:: /images/Uboot_Image5.png

Step 3: Loading Symbol files
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Before the symbols are loaded, a test code will be added to the SPL code. The test code will loop within itself and the only way to break the loop is to change the Program Counter via the CCS. For the current experiment, the AM65EVM is used but the same experiment could be performed on other boards. The following test code is added to the "board_init_f" function in the file <ti_sdk_dir>/board-support/<u-boot_version>/arch/arm/mach-k3/am6_init.c:

.. code-block:: c

	store_boot_index_from_rom();

	/* Make all control module registers accessible */
	ctrl_mmr_unlock();

	asm("test: nop");
	asm("       nop");
	asm("  b test ");
	asm(" nop");
	asm(" nop");

	setup_am654_navss_northbridge();

If a user is working with AM335x/AM437x/AM57xx, the test code could be added in the "early_system_init" function in the file <ti_sdk_dir>/board-support/<u-boot_version>/arch/arm/mach-omap2/hwinit-common.c. The location of the test code on all platforms will vary based on the section of the SPL we are trying to debug.

#. There are two methods of compiling Uboot: `method1 <Top_Level_Makefile.html>`__ and `method2 <Foundational_Components_U-Boot.html#build-and-boot-flow-on-32-bit-platforms>`__. Both methods will generate the necessary symbol file required for SPL debugging.

#. On AM335x/AM437x/AM57xx, the symbol file is located in the following directory "<ti_sdk_dir>/board-support/<u-boot_version>/spl/u-boot-spl". For AM654x, the symbol file is located in the following directory "<ti_sdk_dir>/board-support/u-boot_build/r5/spl/u-boot-spl".

#. After building Uboot, copy the relevant images on the SD card. For AM335x/AM437x/AM57xx, copy MLO and u-boot.img to the SD card. For AM65x, copy sysfw.itb, tiboot3.bin, tispl.bin and u-boot.img to the SD card.

#. Install the SD card and power on the board.

#. On CCS, launch the target configuration file created in Step2:

	.. Image:: /images/Uboot_Image6.png

#. After successful launch, connect to one of the ARM cores. On AM65x, the inital SPL code is executed on the R5 so the user would connect to the R5 core. For the AM335x/AM437/AM57xx, please connect to the A8/A9/A15 core.

	.. Image:: /images/Uboot_Image7.png

#. After connecting to the core, click on "Run"-> "Load"->"Load Symbols...":

	.. Image:: /images/Uboot_Image8.png
	.. Image:: /images/Uboot_Image9.png
	.. Image:: /images/Uboot_Image10.png

#. After loading the code, CCS should find the source code file and it should be stuck at the code previously added:

	.. Image:: /images/Uboot_Image11.png

#. To break out of the loop, change the program counter in the Register Window:

	.. Image:: /images/Uboot_Image12.png

At this point, the user has the ability to step through the SPL code and debug issues in the SPL.

**NOTE**: On K3 family of devices such as AM654x, a watchdog timer part of the DMSC is enabled by default by the ROM bootcode with a timeout of 3 minutes. The watchdog timer is serviced by System Firmware (SYSFW) during normal operation. If one is debugging SPL before the SYSFW is loaded, the watchdog timer will not get serviced automatically and the debug session will reset after 3 minutes. Therefore, it is recommended to start debugging SPL code only after the startup of SYSFW to avoid running into the watchdog timer reset. Similarly, the watchdog timer is also enabled on the AM335x/AM437x/AM57xx devices and please refer to the "Disable_Watchdog()" function in our gel files.



Loading Uboot through Code Composer Studio (CCS)
---------------------------------------------------

The below lab is going to walk you through the process of using CCS to load SPL/U-Boot images on the `AM437x EVM <http://www.ti.com/tool/TMDSEVM437X>`__. The same process applies to other boards as well.

Step 1: Software Downloads 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* A Linux host system configured in accordance with the `Processor SDK Linux Getting Started Guide <http://software-dl.ti.com/processor-sdk-linux/esd/docs/latest/linux/Overview_Getting_Started_Guide.html>`__, with the latest Processor Software Development Kit (PSDK) and Code Composer Studios (CCS) installed. Please refer to the release notes. This document was written using Ubuntu 18.04, Processor SDK Linux 06.03, and CCS 10.0.

Step 2: Testing Hardware Connection 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Remove the SD card from board and setup USB cable connection between the board and your Linux Host
 
* Power on the board

* Open a terminal and run the following command to find the USB serial adapters available on the system : "dmesg | grep tty"

::
 
		[    0.000000] console [tty0] enabled
		[    0.554632] 00:06: ttyS0 at I/O 0x3f8 (irq = 4, base_baud = 115200) is a 16550A
		[   29.566576] usb 2-1.6.1.1: pl2303 converter now attached to ttyUSB0


**NOTE:** The ttyUSB<x> will be different based on the host machine connections.
  
* Launch a serial terminal (the terminal displayed below is created with $minicom -w -s) and configure it as below:

	.. Image:: /images/Uboot_CCS1.png

* You should now see a minicom window with "ccccc" being printed. Go ahead and leave this console RUNNING in the background.
 
 	.. Image:: /images/Uboot_CCS2.jpg

Step 3: Building the SPL/Uboot images
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ 

* Open another console terminal and navigate to the latest PSDK that was installed

* Change directories to the Uboot source code and open the defconfig file associated with your board: **"<psdk_dir>/board-support/u-boot-xxx+yyyy/configs/am43xx_evm_defconfig"**

* Before we compile the Uboot, please add the following flag "CONFIG_OF_EMBED=y" in the am43xx_evm_defconfig file. If you refer to the <u-boot_dir>/README file, it mentions "If this variable is defined, U-Boot will embed a device tree binary in its image." Please keep in mind that this is suitable for debugging and development only and is not recommended for production.

* There are two methods of compiling Uboot: `method1 <Overview/Top_Level_Makefile.html#top-level-makefile>`__ and `method2 <Foundational_Components_U-Boot.html#build-and-boot-flow-on-32-bit-platforms>`__. Both methods will generate the necessary files required for Uboot debugging

* Upon successful compilation, there are a total of 3 images that we are interested:

+------------------------------------------------------------+----------------+------------------------------------------------------------------+
|                    Location                                | Image Name     |  Description                                                     |
+============================================================+================+==================================================================+
| <psdk_dir>/board-support/u-boot-u-boot-xxx+yyyy/spl        | u-boot-spl     | Full SPL image containing all debug symbols                      |
+------------------------------------------------------------+----------------+------------------------------------------------------------------+
| <psdk_dir>/board-support/u-boot-u-boot-xxx+yyyy/spl        | u-boot-spl.bin | Stripped binary SPL image that can fit into the internal memory  |
+------------------------------------------------------------+----------------+------------------------------------------------------------------+
| <psdk_dir>/board-support/u-boot-u-boot-xxx+yyyy            | u-boot         | ELF image that contains debug symbols and the device tree files  |
+------------------------------------------------------------+----------------+------------------------------------------------------------------+


Step 4: CCS Configuration
^^^^^^^^^^^^^^^^^^^^^^^^^^

* Launch CCS and select **File -> New -> Target Configuration File**

* In the **New Target Configuration** dialog box give the configuration a name. For this lab, we will use the name AM437x

	.. Image:: /images/Uboot_CCS3.png
	
* Click **Use shared location**, then Click **Finish**

* The *AM437x* configuration you created will now be opened for editing. Perform the following steps to finish the target configuration:

   #. In the **Connection** drop-down box select **Texas Instruments XDS100v2 USB Emulator**. If you are using a different emulator please select that one instead

   #. In the **Board or Device** selection list check the **AM4378** device. Please do not select any "IDK" or "EVM" option because it will load the GEL files and we do not want that
   
		.. Image:: /images/Uboot_CCS4.png

   #. Click the **Save** button at the right of the screen

* You can now test your target connection by pressing the **Test Connection** button at the right of the screen.
 
 	.. Image:: /images/Uboot_CCS5.png

* Close the *Test Connection* dialog box

Step 5: Change ARM mode 
^^^^^^^^^^^^^^^^^^^^^^^^^

* Launch the target configuration we created in the previous step

   #. Click **View -> Target Configurations**. This should open a tab on the right side of your screen called **Target Configurations**
   
   #. Expand the **User Defined** list
   
   #. Right-Click the **AM437x** configuration and select **Launch Selected Configuration**

* The view should have changed to a **Debug** tab (may take a few minutes to launch)

	.. Image:: /images/Uboot_CCS6.png

* Right-Click the **CortxA9** line item and select **Connect Target**

* To set the processor in ARM Mode (not THUMB mode) with CCS use the following steps:

   #. Select the **Registers** tab
   
		.. Image:: /images/Uboot_CCS7.png
		
   #. Expand the **Core Registers** and inside of **Core Registers** expand the **CPSR** list
		
		.. Image:: /images/Uboot_CCS8.png
		
   #. Scroll down in the CPSR register list and change the **T** register from **1** to **0**.
  
   #. You should see the CPSR value change to reflect the new value
		
		.. Image:: /images/Uboot_CCS9.png
		 
* The above steps need to be performed every time the board is powered completely off or reset

Step 6: Loading SPL 
^^^^^^^^^^^^^^^^^^^^^^^
* To load the SPL binary into the internal chip memory, please use the following steps:

   #. Click **Tools -> Load Memory**. The *Load Memory* tool is used here because we are loading the SPL binary and not and ELF image. The reason for this is that the binary is sized to be able to fit into the internal RAM of the SoC

   #. Click the **Browse** button and navigate to the u-boot-spl.bin file (Refer to Step3 for binary location)
    
		.. Image:: /images/Uboot_CCS10.png

   #. Select the **u-boot-spl.bin** file and click **OK**. For the file type, leave it as "TI Raw Data"

   #. **Start Address: 0x402F4000**. This is the start address of the SPL binary as defined in the u-boot sources. To confirm the start address, please navigate to the file "<psdk_dir>/board-support/u-boot-u-boot-xxx+yyyy/spl/u-boot-spl.map" and search for "__start"
    
		.. Image:: /images/Uboot_CCS11.png
			
   #. Click **Finish** and you should see a box pop up showing the memory load operation
    
    	.. Image:: /images/Uboot_CCS12.png

* To load the symbols for the binary to allow source level debugging
 
 	#. Click **Run -> Load -> Load Symbols...**
 	
 	#. In the dialog box, click the **Browse** button
 	 
 	#. Like before browse to the **spl** directory and change the filter to **All**
 	 
 	#. Select the **u-boot-spl** file which is the ELF executable that also contains the symbols and click **OK**
 	
 	#. Ensure the Code Offset and Data Offset are blank

* Now that the binary and symbols are loaded, we need to set the program counter to the beginning of the SPL code. Click on the **Registers** Tab and in the **Core Registers** list, change the PC value to the start address you entered before (**0x402F4000**)

	.. Image:: /images/Uboot_CCS13.png
	
* Open the Disassembly view by clicking **View -> Disassembly**, ensure that the PC equals *0x402F4000*

	.. Image:: /images/Uboot_CCS14.png 
	
* At this point, feel free to step through the SPL code

* Go ahead and click the green run button to let SPL finish running to completion

* After a second or two, press the yellow **pause** symbol to suspend execution

* You should either see output on the console window of **### ERROR ### Please RESET the board ###**

	.. Image:: /images/Uboot_CCS15.png

* This means that SPL has ran and tried to read the U-Boot image from the SD card, the default boot setting for the EVM. The processor now has the SPL context which means means the board is ready for U-Boot.

**IMPORTANT**: DO NOT RESET YOUR BOARD. If you reset your board at this point you will need to re-run these steps and re-load SPL to go on to the debugging U-Boot

Step 7: Loading Uboot Image 
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

* Assuming that you have executed SPL, please use the following steps to the load the U-Boot ELF image:

   #. Before loading the image, please make sure THUMB mode is not set in the CPSR Register
   
   #. Click **Run -> Load -> Load Program...**
   
   #. Click the **Browse** button and this time select the **u-boot** image (Refer to Step3 for binary location)
   
		.. Image:: /images/Uboot_CCS16.png

   #. Click **OK** to load the program

* Since an ELF image was loaded, the **PC** was automatically set. Also, make sure THUMB mode is set to 0

	.. Image:: /images/Uboot_CCS17.png
	
* Determine the U-Boot relocation offset. U-boot initially loads into low memory and later, relocates itself into high memory to make room for the Linux Kernel.

   #. Now that U-Boot is loaded, go ahead and run the executable by clicking the **green run arrow**. In the minicom window, you should see U-Boot start running and press enter on the Uboot prompt
      
   #. In your minicom terminal, use the command **bdinfo** to find the **relocaddr**. You should see output like the following which shows the relocation address to be **0xfff42000 - this value changes with different SDKs**
   
		.. Image:: /images/Uboot_CCS18.png

      **IMPORTANT**: You want to get the **relocaddr** value, NOT the 'reloc off **value.**

* Re-load U-Boot

   #. Before re-loading the image, please make sure THUMB mode is set to 0 in the CPSR Register
   
   #. Click **Run -> Load -> Reload Program** and allow the load to finish

* Now the U-Boot is loaded again, we need to reload the symbols based on the relocation offset we determined before.

   #. Click **Run -> Load -> Load Symbols...**

   #. Make sure that the **Program file** entry is still set to your **u-boot** file. If not, browse to the proper file.
   
   #. In the **Code offset** field enter the offset value you found before. i.e. **0xfff42000**
   
   #. In the **Data offset** field enter the offset value you found before. i.e. **0xfff42000**

			.. Image:: /images/Uboot_CCS19.png

* You can now do single step and step over operations in the same way you did for SPL
