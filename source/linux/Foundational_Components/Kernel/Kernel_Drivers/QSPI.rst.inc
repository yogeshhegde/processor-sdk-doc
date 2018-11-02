.. http://processors.wiki.ti.com/index.php/Linux_Core_QSPI_User%27s_Guide
.. rubric:: Introduction
   :name: introduction-linux-qspi-ug

Quad Serial Peripheral Interface(QSPI) is a SPI module that allows
single, dual and quad read access to external SPI devices. This module
has a memory mapped register interface, which provides a direct
interface for accessing data from external SPI devices and thus
simplifying software requirements. The QSPI works as a master only.
The one QSPI in the device is primarily intended for fast booting from
quad-SPI flash memories.

This user guide applies to kernel v4.9 and higher.

Top level kernel user's guide can be found at:
  http://processors.wiki.ti.com/index.php/Linux_Kernel_Users_Guide

.. rubric:: Supported Devices
   :name: supported-devices

-  AM437x SK and AM437x IDK
-  DRA74x/DRA72x/DRA71x EVM
-  AM57x IDK

.. rubric:: Hardware features
   :name: hardware-features

The QSPI supports the following features:

::

      • General SPI features:
         – Programmable clock divider
         – Six pin interface
         – Programmable length (from 1 to 128 bits) of the words transferred
         – Programmable number (from 1 to 4096) of the words transferred
         – 4 external chip-select signals
         – Support for 3-, 4-, or 6-pin SPI interface
         – Optional interrupt generation on word or frame (number of words) completion
         – Programmable delay between chip select activation and output data from 0 to 3 QSPI clock cycles
         – Programmable signal polarities
         – Programmable active clock edge
         – Software-controllable interface allowing for any type of SPI transfer
         – Control through L3_MAIN configuration port
       • Serial flash interface (SFI) features:
         – Serial flash read/write interface
         – Additional registers for defining read and write commands to the external serial flash device
         – 1 to 4 address bytes
         – Fast read support, where fast read requires dummy bytes after address bytes; 0 to 3 dummy bytes
           can be configured.
         – Dual read support
         – Quad read support
         – Little-endian support only
         – Linear increment addressing mode only

.. rubric:: Driver Features
   :name: driver-features

.. rubric:: Supported Features
   :name: supported-features

Following features are supported by QSPI driver:

.. rubric:: Memory mapped read support
   :name: memory-mapped-read-support

TI QSPI controller provides memory map port to read data from SPI
flashes. Memory map port is enabled in QSPI\_SPI\_SWITCH\_REG register.
Control module register may also need to be accessed for DRA7xx. The
QSPI\_SPI\_SETUP\_REGx needs to be populated with flash specific
information like read opcode, read mode(quad, dual, normal), address
width and dummy bytes. Once, controller is in memory map mode, the whole
flash memory is available as a memory region at SoC specific address.
This region can be accessed using normal memcpy() (or mem-to-mem dma
copy). The ti-qspi controller hardware will internally communicate with
SPI flash over SPI bus and get the requested data.

.. rubric:: Supported bus widths
   :name: supported-bus-widths

-  Single bit write mode
-  Single bit read mode
-  Dual bit read mode
-  Quad bit read mode

.. rubric:: Supported SPI modes
   :name: supported-spi-modes

QSPI supportes all clock and polarity modes defined in table SPI Clock
Modes Definition of particular SoC's TRM. But make sure that the
selected mode is supported by the clocking requirements of the device as
per the device's datasheet.

.. rubric:: DMA support
   :name: dma-support

Driver uses mem-to-mem DMA copy on top QSPI memory mapped port during
read from flash for maximum throughput and reduced CPU load.

.. rubric:: Hardware Architecture
   :name: hardware-architecture

The QSPI is composed of two blocks. The first one is the SFI
memory-mapped interface (SFI\_MM\_IF) and the second one is the SPI
core (SPI\_CORE). The SFI\_MM\_IF block is associated only with SPI
flash memories and is used for specifying typical for the SPI flash
memories settings (read or write command, number of address and dummy
bytes, and so on) unlike the SPI\_CORE block, which is associated with
the SPI interface itself and is used to configure typical SPI settings
(chip-select polarity, serial clock inactive state, SPI clock mode,
length of the words transferred, and so on).

The SFI\_MM\_IF comprises the following two subblocks:

-  SFI register control
-  SFI translator

The SPI\_CORE comprises the following four subblocks:

-  SPI control interface (SPI\_CNTIF)
-  SPI clock generator (SPI\_CLKGEN)
-  SPI control state machine (SPI\_MACHINE)
-  SPI data shifter (SPI\_SHIFTER)

In addition, an interface bridge connects the two ports (configuration
port and memory-mapped port) of the SFI\_MM\_IF block to the L3\_MAIN
interconnect. There are no software controls associated with this
interface bridge. The QSPI supports long transfers through a frame-style
sequence. In its generic SPI use mode, a word can be defined up to 128
bits and multiple words can be transferred during a single access. For
each word, a device initiator must read or write the new data and then
tell the QSPI to continue the current operation. Using this sequence, a
maximum of 4096 128-bit words can be transferred in a single SPI read or
write operation. This allows great flexibility when connecting the QSPI
to various types of devices.

As opposed to the generic SPI use mode, the communication with serial
flash-type devices requires sending a byte command, followed by sending
bytes of data. Commands can be sent through the SPI\_CORE block to
communicate with a serial flash device; however, it is easier to do this
using the SFI\_MM\_IF block because it is intended to ease the
communication with serial flash devices. If the SPI\_CORE is used to
communicate with a serial flash device, software must load the command
into the SPI data transfer register with additional configuration
fields, perform the byte transfer, then place the data to be sent (or
configure for receive) along with additional configuration fields, and
perform that transfer. Reads and writes to serial flash devices are more
specific. First, the read or write command byte is sent, followed by 1
to 4 bytes of address (corresponding to the address to read/write), then
followed by the data write/receive phase. Data is always sent byte
oriented. When the address is loaded, data can be continuously read or
written, and the address will automatically increment to each byte
address internally to the serial flash device. See memory mapped read
for more info

| 

.. figure:: ../images/QSPI_block_diagram.png

    QSPI Block Diagram

|

.. rubric:: Driver Architecture
   :name: driver-architecture

Following diagram shows the QSPI driver stack:

.. figure:: ../images/QSPI_architecture.png

    QSPI software stack

|

QSPI driver can be use both to access SPI flash devices via mtd
subsystem or access generic SPI devices (like SPI touchscreen) via SPI
framework.

.. rubric:: Driver Configuration
   :name: driver-configuration

.. rubric:: Source Location
   :name: source-location

The source file for QSPI driver can be found at:
drivers/spi/spi-ti-qspi.c under Linux kernel source tree.

.. rubric:: Kernel Configuration Options
   :name: kernel-configuration-options

The driver can be built into the kernel or can be compiled as module and
loaded into the kernel dynamically.

.. rubric:: Enabling QSPI Driver Configurations
   :name: enabling-qspi-driver-configurations

Following needs to be enabled to access QSPI flash: TI QSPI controller
driver, SPI NOR framework and MTD M25P80 generic serial flash driver in
the kernel via menuconfig.

start Linux Kernel Configuration tool.

::

        $ make menuconfig  ARCH=arm

To enable QSPI controller driver:

::

              Device Drivers  --->
               [*] SPI support  --->
                 <*>   DRA7xxx QSPI controller support

To enable SPI NOR framework:

::

              Device Drivers  --->
                <*> Memory Technology Device (MTD) support  --->
                  <*>   SPI-NOR device support  --->  

To enable M25P80 generic SPI flash driver:

::

              Device Drivers  --->
                <*> Memory Technology Device (MTD) support  --->
                  Self-contained MTD device drivers  ---> 
                    <*> Support most SPI Flash chips (AT26DF, M25P, W25X, ...)

To enable them as module make <\*> as <M>

Enabling UBIFS filesystem support:

::

              File systems  --->
                [*] Miscellaneous filesystems  --->
                  <*>   UBIFS file system support

.. rubric:: DT Configuration
   :name: dt-configuration

Refer to Documentation/devicetree/bindings/spi/ti\_qspi.txt under
kernel source tree for QSPI controller driver's DT bindings and their
usage.

For generic SPI bus related DT bindings refer to:
Documentation/devicetree/bindings/spi/ti\_qspi.txt

To configure QSPI flash partitions and flash related DT bindings refer
to: Documentation/devicetree/bindings/mtd/jedec,spi-nor.txt and
Documentation/devicetree/bindings/mtd/partition.txt

.. rubric:: Driver Usage
   :name: driver-usage-qspi

Load QSPI module using modprobe (this will take care of dependencies and
load those modules as well)

::

       $modprobe spi-ti-qspi

This should create /dev/mtdX entries for every partitions defined in DT
or via command line arguments. To see all MTD partitions in the system
run:

::

       $cat /proc/mtd
        dev:    size   erasesize  name
        mtd0: 00080000 00010000 "QSPI.U_BOOT"
        mtd1: 00080000 00010000 "QSPI.U_BOOT.backup"
        mtd2: 00010000 00010000 "QSPI.U-BOOT-SPL_OS"
        mtd3: 00010000 00010000 "QSPI.U_BOOT_ENV"
        mtd4: 00010000 00010000 "QSPI.U-BOOT-ENV.backup"
        mtd5: 00800000 00010000 "QSPI.KERNEL"
        mtd6: 036d0000 00010000 "QSPI.FILESYSTEM"

.. rubric:: Testing
   :name: testing

.. rubric:: Using mtd-utils
   :name: using-mtd-utils

::

         $ cat /proc/mtd       /* Should list QSPI partitions */
         $ flash_erase  /dev/mtd6 0 0  /* Erase entire /dev/mtd6 */
         $ dd if=/dev/random of=tmp_write.txt bs=1 count=num  /* num = bytes to write to flash */
         $ mtd_debug write /dev/mtd6 0 num tmp_write.txt  /* write to num bytes to flash */
         $ mtd_debug read /dev/mtd6 0 num tmp_read.txt /* /* read to num bytes to flash */
         $ diff tmp_read.txt tmp_write.txt /* should be NULL */

.. rubric:: Using dd command
   :name: using-dd-command

::

         $ cat /proc/mtd       /* Should list QSPI partitions */
         $ flash_erase  /dev/mtd6 0 0  /* Erase entire /dev/mtd6 */
         $ dd if=/dev/random of=tmp_write.txt bs=1 count=num  /* num = bytes to write to flash */
         $ dd if=tmp_write.txt of=/dev/mtd6 bs=num count=1 /* write to num bytes to flash */
         $ dd if=/dev/mtd6 of=tmp_read.txt bs=num count=1  /* read to num bytes to flash */
         $ diff tmp_read.txt tmp_write.txt /* should be NULL */

.. rubric:: Using UBIFS on flash
   :name: using-ubifs-on-flash

Make sure UBIFS filesystem is enabled in the kernel refer to `this
section <#enabling-qspi-driver-configurations>`__.

::

         root~# ubiformat /dev/mtd9
         ubiformat: mtd9 (nor), size 23199744 bytes (22.1 MiB), 354 eraseblocks of 65536 bytes (64.0 KiB), min. I/O size 1 bytes
         libscan: scanning eraseblock 353 -- 100 % complete 
         ubiformat: 354 eraseblocks are supposedly empty
         ubiformat: formatting eraseblock 353 -- 100 % complete 
         root:~# ubiattach -p /dev/mtd9
         [  270.874428] ubi0: attaching mtd9
         [  270.914131] ubi0: scanning is finished
         [  270.921788] ubi0: attached mtd9 (name "QSPI.file-system", size 22 MiB)
         [  270.928405] ubi0: PEB size: 65536 bytes (64 KiB), LEB size: 65408 bytes
         [  270.935210] ubi0: min./max. I/O unit sizes: 1/256, sub-page size 1
         [  270.941491] ubi0: VID header offset: 64 (aligned 64), data offset: 128
         [  270.948102] ubi0: good PEBs: 354, bad PEBs: 0, corrupted PEBs: 0
         [  270.954215] ubi0: user volume: 0, internal volumes: 1, max. volumes count: 128
         [  270.961602] ubi0: max/mean erase counter: 0/0, WL threshold: 4096, image sequence number: 2077421476
         [  270.970887] ubi0: available PEBs: 350, total reserved PEBs: 4, PEBs reserved for bad PEB handling: 0
         [  270.980204] ubi0: background thread "ubi_bgt0d" started, PID 863
         UBI device number 0, total 354 LEBs (23154432 bytes, 22.1 MiB), available 350 LEBs (22892800 bytes, 21.8 MiB), LEB size 65408 bytes (63.9 KiB)
         root:~# ubimkvol /dev/ubi0 -N flash_fs -s 20MiB
         Volume ID 0, size 321 LEBs (20995968 bytes, 20.0 MiB), LEB size 65408 bytes (63.9 KiB), dynamic, name "flash_fs", alignment 1
         root:~# mkdir /mnt/flash
         root:~# mount -t ubifs ubi0:flash_fs /mnt/flash/   
         [  326.002602] UBIFS (ubi0:0): default file-system created
         [  326.008309] UBIFS (ubi0:0): background thread "ubifs_bgt0_0" started, PID 866
         [  326.027530] UBIFS (ubi0:0): UBIFS: mounted UBI device 0, volume 0, name "flash_fs"
         [  326.035157] UBIFS (ubi0:0): LEB size: 65408 bytes (63 KiB), min./max. I/O unit sizes: 8 bytes/256 bytes
         [  326.044615] UBIFS (ubi0:0): FS size: 20341888 bytes (19 MiB, 311 LEBs), journal size 1046528 bytes (0 MiB, 16 LEBs)
         [  326.055123] UBIFS (ubi0:0): reserved for root: 960797 bytes (938 KiB)
         [  326.061610] UBIFS (ubi0:0): media format: w4/r0 (latest is w4/r0), UUID 828AA98E-3A51-4B35-AD50-9E90144AD4C7, small LPT model
         root:~#

Now you can access filesystem at /mnt/flash/

.. rubric:: Limitations
   :name: limitations

-  The QSPI supports only dual and quad reads. Dual or quad writes are
   not supported. In addition, there is no "pass through" mode supported
   where the data present on the QSPI input is sent to its output
-  QSPI IP is designed in such a way that after 4096 word transfer, chip
   select automatically gets de asserted. As a result of which, the
   entire flash cannot be read in a single chip select using
   (Single/Dual/Quad) bit read mode feature. While the serial flash
   linux framework and flash specification expects the entire read to
   happen with a single read command in a single chip select. This
   limitation is not applicable when QSPI is used in memory mapped mode
   for reads. The QSPI driver by default uses memory mapped reads.
-  For writes QSPI uses normal SPI interface instead of memory mapped
   mode, this is because there is an explicit write enable command that
   needs to be sent to flash for every page write (256 bytes) which is
   not handled by SPI\_MM\_IF.

