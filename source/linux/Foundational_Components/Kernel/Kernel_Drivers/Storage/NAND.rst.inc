.. http://processors.wiki.ti.com/index.php/Linux_Core_NAND_User%27s_Guide
.. rubric:: **Introduction**
   :name: introduction-linux-core-nand

.. rubric::  **TI infrastructure for NAND Flash devices**
   :name: ti-infrastructure-for-nand-flash-devices

TI's SoC interface with NAND Flash devices via on-chip GPMC (General
Purpose Memory Controller) interface or via AEMIF depending on the SoC.

For devices that include GPMC: The ECC algorithms required by NAND
devices to protect their data, are managed by two independent hardware
engines:

-  GPMC ECC engine: used for calculating ECC checksum while writing and
   reading the NAND device.
-  ELM ECC engine: used for locating and decoding ECC errors while
   reading the NAND device.

| Important NAND related drivers can be further split into the following
  sub-components.
| For all devices:

-  NAND subsystem: protocol driver in MTD sub-system for interfacing
   with NAND flash devices.

For K2L and K2E:

-  AEMIF driver: controller driver for AEMIF engine

For all other SoCs:

-  GPMC driver: controller driver for GPMC engine
-  ELM driver (for applicable SoC) : controller driver for ELM engine.

.. rubric:: **Supported Features**
   :name: supported-features

| GPMC NAND driver supports:

-  NAND devices having:

   -  bus-width = x8 \| x16
   -  page-size = 2048 \| 4096
   -  block-size = 128k \| 256k

-  1-bit Hamming, BCH4, BCH8 and BCH16 ECC schemes.
-  Various transfer modes for different use-cases and applications (like
   Polled, Polled Prefetch, IRQ and DMA).
-  NAND boot support for custom non-ONFI compatible NAND devices using
   NAND-I2C boot-mode (Refer Chapter on *Initialization* in processor's
   TRM).
-  Sub-page write

| 

.. rubric:: Accessing NAND partitions
   :name: accessing-nand-partitions

.. rubric:: Linux
   :name: linux

Within the kernel NAND partitions are accessed via mtd devices. Instead
are referring to a partition by its name or its offset a user simply
needs to specify the NAND partition in question in the form of its mtd
device path. Usually in the format of /dev/mtdX where X is the mtd
device number.

.. rubric:: Determine NAND Partition MTD Identifier
   :name: determine-nand-partition-mtd-identifier

Within the kernel figuring out the mtd device number that is for a
particular NAND partition is simple. A user simply needs to view the
list of mtd devices along with its name. Below command will provide this
information:

::

    cat /proc/mtd

An example of this output performed on the DRA71x EVM can be seen below.

::

    dev:    size   erasesize  name                                                                                                                                                
    mtd0: 00010000 00010000 "QSPI.SPL"                                                                                                                                            
    mtd1: 00010000 00010000 "QSPI.SPL.backup1"                                                                                                                                    
    mtd2: 00010000 00010000 "QSPI.SPL.backup2"                                                                                                                                    
    mtd3: 00010000 00010000 "QSPI.SPL.backup3"                                                                                                                                    
    mtd4: 00100000 00010000 "QSPI.u-boot"                                                                                                                                         
    mtd5: 00080000 00010000 "QSPI.u-boot-spl-os"                                                                                                                                  
    mtd6: 00010000 00010000 "QSPI.u-boot-env"                                                                                                                                     
    mtd7: 00010000 00010000 "QSPI.u-boot-env.backup1"                                                                                                                             
    mtd8: 00800000 00010000 "QSPI.kernel"                                                                                                                                         
    mtd9: 01620000 00010000 "QSPI.file-system"                                                                                                                                    
    mtd10: 00020000 00020000 "NAND.SPL"                                                                                                                                           
    mtd11: 00020000 00020000 "NAND.SPL.backup1"                                                                                                                                   
    mtd12: 00020000 00020000 "NAND.SPL.backup2"                                                                                                                                   
    mtd13: 00020000 00020000 "NAND.SPL.backup3"                                                                                                                                   
    mtd14: 00040000 00020000 "NAND.u-boot-spl-os"                                                                                                                                 
    mtd15: 00100000 00020000 "NAND.u-boot"                                                                                                                                        
    mtd16: 00020000 00020000 "NAND.u-boot-env"                                                                                                                                    
    mtd17: 00020000 00020000 "NAND.u-boot-env.backup1"                                                                                                                            
    mtd18: 00800000 00020000 "NAND.kernel"                                                                                                                                        
    mtd19: 0f600000 00020000 "NAND.file-system"   

As you can see above the list of mtd devices may not only include NAND
partitions but list other peripherals that create mtd devices also. From
the above you can see that if the user wants to access the file-system
partition within the NAND then they use /dev/mtd19 to reference the
partition. The names of these partitions, their sizes (in hex) and
offsets (in hex) are determined within the specific board's device tree
file.

.. rubric:: Erasing, Reading and Writing
   :name: erasing-reading-and-writing

For the below sections it is important to remember to replaced **mtdX**
with the mtd device that is associated with the particular NAND
partition as described in the above section.

| **Erasing**
| Erasing a NAND partition can be performed by using the below command:

::

    flash_erase /dev/mtdX 0 0

| **Writing**
| Writing a NAND partition is usually a two step process. Writing to
  NAND at a bit level is only able to change a bit from 1 to 0. This is
  problematic since frequently when writing new data you will need to
  change many bits from 1 to 0 along with changing some bits from 0 to
  1. The only way to get around this is erasing the NAND partition
  before writing. This is because erasing sets all the bits in a
  partition to 1. Thus when performing raw NAND writes insure you
  erasing the partition first otherwise you will experience numerous
  NAND ECC errors during the write or read operation.

The command to write to a NAND partition is below:

::

    nandwrite -p /dev/mtdX <filename>

| The symbol **<filename>** should be replaced with the file path to the
  file you will like to write.
| **Reading**
| Reading NAND can be done by running the below command:

::

    nanddump /dev/mtdX -f <filename>

The symbol **<filename>** should be replaced with the name of a file you
want to be created that contains with contents of the NAND partition.
Note that the above command by default with save to a file the complete
contents of the NAND partition. If your interested in only a certain
amount of data being dumped additional parameters can be passed to the
utility.

.. rubric:: Command Line Partitioning
   :name: command-line-partitioning

In some situations, partitions defined in device-tree may not be
sufficient or correct. Note that once partitions are defined in
device-tree and present in a mainline kernel release, they cannot be
changed because this breaks users who have existing data on NAND flash
and upgrade to new kernel and device-tree. If you are not affected by
this issue, you may choose to override partition information passed from
device-tree using command line.

In TI kernel releases, MTD command line partitioning support is built as
module. To use it, add something like following to the kernel command
line (passed using ``bootargs`` U-Boot variable)

::

    setenv bootargs ${bootargs} cmdlinepart.mtdparts=davinci-nand.0:1m(image)ro,-(free-space)

Note that MTD command line parses breaks if there is space in partition
name. So use "free-space" not "free space". Change ``davinci-nand.0`` to
the correct device name. You can usually find the name to use from
``dmesg``\ output

::

    Creating 2 MTD partitions on "davinci-nand.0":

You can also setup new partitions after kernel has booted with old
partitions. You will need to re-probe the NAND driver if it has already
probed. Something like:

::

    $ modprobe -r davinci_nand
    $ modprobe cmdlinepart mtdparts="davinci-nand.0:2m(image)ro,-(free space)"
    $ modprobe davinci_nand

``davinci_nand`` module name here may have to be changed based on the
SoC you are using.

.. rubric:: U-boot
   :name: u-boot

| Information regarding NAND booting and booting the kernel and file
  system from NAND can be found in the U-boot User Guide NAND
  section.

.. rubric:: **NAND Based File system**
   :name: nand-based-file-system

.. rubric:: Required Software
   :name: required-software

Building a UBI file system depends on two applications. Ubinize and
mkfs.ubifs which are both provided by Ubuntu's mtd-utils package
(apt-get install mtd-utils). The below instructions are based on version
1.5.0 of mtd-utils although newer version are likely to work.

.. rubric:: Building UBI File system
   :name: building-ubi-file-system

When building a UBI file system you need to have a directory that
contains the exact files and directories layout that you plan to use for
your file system. This is similar to the files and directories layout
you will use to copy a file system onto a SD card for booting purposes.
It is important that your file system size is smaller than the file
system partition in the NAND.

| Next you need a file named ubinize.cfg. Below contains the exact
  contents of ubinize.cfg you should use. However, replace **<name>**
  with a name of your choosing
| ubinize.cfg contents:

::

    [ubifs]
     mode=ubi
     image=<name>.ubifs
     vol_id=0
     vol_type=dynamic
     vol_name=rootfs
     vol_flags=autoresize

| To build a ubi files system only requires the below two commands. The
  symbol below **<directory path>** should be replaced with the path to
  your directory that you want to convert into a ubifs. The symbol
  <name> should be replaced with the same value you used in creating
  ubinize.cfg. Make sure you use the same value of <name> across the two
  commands and ubinize.cfg. The symbols **<MKUBIFS ARGS>** and
  **<UBINIZE ARGS>** are board specific. Replace these values with the
  values seen in the below table based on the TI EVM you are using.
| Commands to execute:

::

    mkfs.ubifs -r <directory path> -o <name>.ubifs <MKUBIFS ARGS>
    ubinize -o <name>.ubi <UBINIZE ARGS> ubinize.cfg

Once these commands are executed <name>.ubi can then be programmed into
the NAND's designated file-system partition.

+-----------------+--------------------------------+-------------------------------------+
| Board Name      | MKUBIFS Args                   | UBINIZE Args                        |
+=================+================================+=====================================+
| AM335X GP EVM   | -F -m 2048 -e 126976 -c 5600   | -m 2048 -p 128KiB -s 512 -O 2048    |
+-----------------+--------------------------------+-------------------------------------+
| AM437x GP EVM   | -F -m 4096 -e 253952 -c 2650   | -m 4096 -p 256KiB -s 4096 -O 4096   |
+-----------------+--------------------------------+-------------------------------------+
| K2E EVM         | -F -m 2048 -e 126976 -c 3856   | -m 2048 -p 128KiB -s 2048 -O 2048   |
+-----------------+--------------------------------+-------------------------------------+
| K2L EVM         | -F -m 4096 -e 253952 -c 1926   | -m 4096 -p 256KiB -s 4096 -O 4096   |
+-----------------+--------------------------------+-------------------------------------+
| K2G EVM         | -F -m 4096 -e 253952 -c 1926   | -m 4096 -p 256KiB -s 4096 -O 4096   |
+-----------------+--------------------------------+-------------------------------------+
| DRA71x EVM      | -F -m 2048 -e 126976 -c 8192   | -m 2048 -p 128KiB -s 512 -O 2048    |
+-----------------+--------------------------------+-------------------------------------+

Table:  Table of Parameters to use for Building UBI filesystem image

| 

.. rubric:: **Board specific configurations**
   :name: board-specific-configurations

| Following table gives details about NAND devices present on various
  EVM boards

+----------+----------+----------+----------+----------+----------+----------+----------+----------+
| EVM      | NAND     | Size     | Bus-Widt | Block-Si | Page-Siz | OOB-Size | ECC      | Hardware |
|          | Part #   |          | h        | ze       | e        | (bytes)  | Scheme   |          |
|          |          |          |          | (KB)     | (KB)     |          |          |          |
+==========+==========+==========+==========+==========+==========+==========+==========+==========+
| AM335x   | MT29F2G0 | 256 MB   | 8        | 128      | 2        | 64       | BCH 8    | GPMC     |
| GP       | 8AB      |          |          |          |          |          |          |          |
+----------+----------+----------+----------+----------+----------+----------+----------+----------+
| AM437x   | MT29F4G0 | 512 MB   | 8        | 256      | 4        | 224      | BCH 16   | GPMC     |
| GP       | 8AB      |          |          |          |          |          |          |          |
+----------+----------+----------+----------+----------+----------+----------+----------+----------+
| AM437x   | MT29F4G0 | 512 MB   | 8        | 256      | 4        | 224      | BCH 16   | GPMC     |
| EPOS     | 8AB      |          |          |          |          |          |          |          |
+----------+----------+----------+----------+----------+----------+----------+----------+----------+
| DRA71x   | MT29F2G1 | 256 MB   | 16       | 128      | 2        | 64       | BCH 8    | GPMC     |
|          | 6AADWP:D |          |          |          |          |          |          |          |
+----------+----------+----------+----------+----------+----------+----------+----------+----------+
| K2G      | MT29F2G1 | 512 MB   | 16       | 128      | 2        | 64       | BCH 16   | GPMC     |
|          | 6ABAFAWP |          |          |          |          |          |          |          |
|          | :F       |          |          |          |          |          |          |          |
+----------+----------+----------+----------+----------+----------+----------+----------+----------+
| K2E      | MT29F4G0 | 1 GB     | 8        | 128      | 2        | 64       | TBD      | AEMIF    |
|          | 8ABBDAH4 |          |          |          |          |          |          |          |
|          | D        |          |          |          |          |          |          |          |
+----------+----------+----------+----------+----------+----------+----------+----------+----------+
| K2L      | MT29F16G | 512 MB   | 8        | 256      | 4        | 224      | TBD      | AEMIF    |
|          | 08ADBCAH |          |          |          |          |          |          | |        |
|          | 4:C      |          |          |          |          |          |          |          |
+----------+----------+----------+----------+----------+----------+----------+----------+----------+

Table:  NAND Flash Specification Summary

.. rubric:: AM43xx GP EVM
   :name: am43xx-gp-evm

On this board, NAND Flash data lines are muxed with eMMC, so either eMMC
or NAND can be used enabled at a time. By default NAND is enabled.

.. rubric:: AM43xx EPOS EVM
   :name: am43xx-epos-evm

On this board, NAND Flash control lines are muxed with QSPI, Thus either
NAND or QSPI-NOR can be used at a time. By default NAND is enabled.

.. rubric:: DRA71x EVM
   :name: dra74x-evm

On the board, NAND Flash signals are muxed between NAND, NOR and Video
Out signals. Therefore, to have the signals properly muxed for NAND to
work Pin 1 (first pin on the left) must be turned on and Pin 2 must be
turned off. Pin 1 and 2 must never be switched on at the same time.
Doing so may cause damage to the board or SoC.

.. note::

	Aside from setting the correct bootmode (SYSBOOT[5:0]) for
	NAND boot, make sure that The Bus width (SYSBOOT[13]) and
	Muxed-device (SYSBOOT[12:11]) are set as given in the TRM.

.. rubric:: Configurations (GPMC Specific)
   :name: configurations-gpmc-specific

.. rubric:: **How to enable OMAP NAND driver in Linux Kernel ?**
   :name: how-to-enable-omap-nand-driver-in-linux-kernel

OMAP NAND driver can be enable/disable via *Linux Kernel
Configuration* tool. Enable below Configs to enable MTD Support along
with MTD nand driver support

::

    Device Drivers  --->
      <*> Memory Technology Device (MTD) support  --->
                [*]   Command line partition table parsing
                <*>   Direct char device access to MTD devices
                <*>   Caching block device access to MTD devices
                <*>   NAND Device Support  --->
                            <*>    NAND Flash device on OMAP2 and OMAP3
                <*>   Enable UBI - Unsorted block images  --->

.. rubric:: Transfer Modes
   :name: transfer-modes

.. rubric:: **Choose correct bus transfer mode**
   :name: choose-correct-bus-transfer-mode

| TI's NAND driver support following different modes of transfers data
  to external NAND device.

-  "prefetch-polled" Prefetch polled mode (default)
-  "polled" Polled mode, without prefetch
-  "prefetch-dma" Prefetch enabled DMA mode
-  "prefetch-irq" Prefetch enabled IRQ mode

Transfer mode can be configured in linux-kernel via DT binding
**<ti,nand-xfer-type>**
Refer: Linux kernel\_docs @
$LINUX/Documentation/devicetree/bindings/mtd/gpmc-nand.txt

.. rubric:: **DMA vs Non DMA Mode (PIO Mode)**
   :name: dma-vs-non-dma-mode-pio-mode

| The NAND interface is a low speed interface when compared to the main
  CPU. This means for most CPU frequencies
| if the CPU is reading the NAND buffers via polling then its fully
  capable of reading the NAND at its maximum speed.
| Of course the trade off being that the CPU while polling the NAND is
  not capable of doing anything else thus significantly
| increasing the overall CPU load.

| DMA performs best when it can read large amount of data at a time.
  This is necessary since the overhead in setting up, executing and
  returning from a DMA request is not insignificant so to compensate its
  best for the DMA to read/write as much data as possible. This provides
  a dual purpose of significant reduction in CPU load for an operation
  and also high performance.

The current NAND subsystem within Linux currently deals with reading a
single page from the NAND at a time. Unfortunately, the page size is
small enough that the overhead for using the DMA (including Linux DMA
software stack) negatively impacts the performance. Based on nand
performance tests done in early 2016 using the DMA reduced NAND read and
write performance by 10-20% depending on SOC. However, cpu load when
using polling via the same NAND test were around 99%. When using DMA
mode the CPU load for reading was around 35%-54% and for writing was
around 15%-30% depending on SOC.

.. rubric:: **Performance optimizations on NAND**
   :name: performance-optimizations-on-nand

.. rubric:: **Tweak NAND device signal timings**
   :name: tweak-nand-device-signal-timings

Much of the NAND throughput can be improved by matching GPMC signal
timings with NAND device present on the board. Although GPMC signal
timing configurations are not same as those given in NAND device
datasheets, but they can be easily derived based on details given in
GPMC Controller functional specification.

-  Details of GPMC Signal Timing configurations and how to use them can
   be found in TI's Processor TRM

Chapter *General Purpose Memory Controller*
Section *Signal Control*

-  In Linux, GPMC signal timing configurations are specified via DTB.

Refer kernel\_docs
$LINUX/Documentation/devicetree/bindings/bus/ti-gpmc.txt
Some timing configurations like <gpmc,rd-cycle-ns>, <gpmc,wr-cycle-ns>
have larger impact on NAND throughput than others.

-  In U-boot, GPMC signal timing configurations are specified during
   GPMC initialization in arch/arm/cpu/armv7/../... mem.c or
   mem\_common.c

*gpmc\_init()* :: *struct gpmc\_cfg*

.. rubric:: **Tweaking UBIFS**
   :name: tweaking-ubifs

-  Specify **-o bulk\_read** while mounting UBIFS `(read
   ahead) <http://www.linux-mtd.infradead.org/doc/ubifs.html#L_readahead>`__
-  Tweak Linux VM `(kernel knobs for
   VM) <http://www.linux-mtd.infradead.org/doc/ubifs.html#L_wb_knobs>`__

.. rubric:: Additional Resources
   :name: additional-resources

| Following links should help you better understand NAND Flash as
  technology.
| http://www.linux-mtd.infradead.org/doc/nand.html
| https://wiki.linaro.org/Flash%20memory

https://lwn.net/Articles/428584/

