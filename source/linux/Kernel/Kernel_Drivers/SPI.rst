.. http://processors.wiki.ti.com/index.php/Linux_Core_SPI_User%27s_Guide
.. rubric:: **Introduction**
   :name: introduction

-  Serial interface

-  Synchronous

-  Master-slave configuration (driver supports only master mode)

-  Data Exchange - DMA/PIO

| 

.. rubric:: SOC Specific Information
   :name: soc-specific-information

+--------------+-----------+
| SoC Family   | Driver    |
+==============+===========+
| AM335x       | McSPI     |
+--------------+-----------+
| AM437x       | McSPI     |
+--------------+-----------+
| DRA7x        | McSPI     |
+--------------+-----------+
| 66AK2Gx      | McSPI     |
+--------------+-----------+
| 66AK2Lx      | Davinci   |
+--------------+-----------+
| 66AK2Hx      | Davinci   |
+--------------+-----------+
| 66AK2E       | Davinci   |
+--------------+-----------+

.. rubric:: Features Not Supported
   :name: features-not-supported

| Below contains a list of features not supported by the Linux driver.
| Note this isn't meant to be an exhaustive list and only takes into
  account features the SPI peripheral in the SoC is capable of but is
  currently not supported in the Linux driver.

.. rubric:: SoCs using McSPI driver
   :name: socs-using-mcspi-driver

SPI slave mode isn't supported

.. rubric:: SoCs using Davinci Driver
   :name: socs-using-davinci-driver

SPI slave mode isn't supported

.. rubric:: Kernel Configuration
   :name: kernel-configuration

The specific peripheral driver to enable depends on the SoC being used.

.. rubric:: Enabling McSPI Driver
   :name: enabling-mcspi-driver

::

    Device Drivers  --->
       [*] SPI support
          [*] McSPI driver for OMAP

.. rubric:: Enabling DaVinci Driver
   :name: enabling-davinci-driver

::

    Device Drivers  --->
       [*] SPI support
          [*] Texas Instruments DaVinci/DA8x/OMAP-L/AM1x SoC SPI controller 

.. rubric:: SPI Driver Usecases
   :name: spi-driver-usecases

There are numerous drivers that can be used to interact with a variety
of hardware. From SPI based RTC to SPI based GPIO expander. A list of
drivers along with their documentation can be found within the kernel
sources. The below section attempts to provide information on SPI based
chips that are located on TI's evms.

.. rubric:: Flash Storage
   :name: flash-storage

.. rubric:: Boards with SPI Flash
   :name: boards-with-spi-flash

+------------------+--------------------+--------------+
| EVM              | Part #             | Flash Size   |
+==================+====================+==============+
| AM335x ICE EVM   | W25Q64             | 8 MB         |
+------------------+--------------------+--------------+
| K2E EVM          | N25Q128A11ESF40F   | 16 MB        |
+------------------+--------------------+--------------+
| K2HK EVM         | N25Q128A11ESF40F   | 16 MB        |
+------------------+--------------------+--------------+
| K2L EVM          | N25Q128A11ESF40F   | 16 MB        |
+------------------+--------------------+--------------+

.. rubric:: Kernel Configuration
   :name: kernel-configuration-1

::

    Device Drivers  --->
       <*> Memory Technology Device (MTD) support  ---> 
           Self-contained MTD device drivers  ---> 
             <*> Support most SPI Flash chips (AT26DF, M25P, W25X, ...)

.. rubric:: Reading/Writing to Flash
   :name: readingwriting-to-flash

.. rubric:: Determine SPI NOR Partition MTD Identifier
   :name: determine-spi-nor-partition-mtd-identifier

Within the kernel figuring out the mtd device number that is for a
particular SPI NOR partition is simple. A user simply needs to view the
list of mtd devices along with its name. Below command will provide this
information:

::

    cat /proc/mtd

An example of this output performed on the AM571x IDK EVM can be seen
below.

::

    dev:    size   erasesize  name
    mtd0: 00040000 00010000 "QSPI.SPL"
    mtd1: 00100000 00010000 "QSPI.u-boot"
    mtd2: 00080000 00010000 "QSPI.u-boot-spl-os"
    mtd3: 00010000 00010000 "QSPI.u-boot-env"
    mtd4: 00010000 00010000 "QSPI.u-boot-env.backup1"
    mtd5: 00800000 00010000 "QSPI.kernel"
    mtd6: 01620000 00010000 "QSPI.file-system"

Note the names of these partitions, their sizes (in hex) and offsets (in
hex) are determined within the specific board's device tree file.

| **Erasing**
| Erasing a NOR partition can be performed by using the below command:

::

    flash_erase /dev/mtdX 0 0

Where X is the partition number.

| **Reading/Writing**
| Use the MTD interface provided for SPI flash on the EVM to validate
  the SPI driver interface.
| The below step copies 8KiB from /dev/mtd2 partition (u-boot env) to
  /dev/mtd4 partition and reads
| the 8KiB image from /dev/mtd4 to a file and checks the md5sum. The
  md5sum of test.img and test1.img should be same.

::

    cd /tmp
    dd if=/dev/mtd2 of=test.img bs=8k count=1
    md5sum test.img
    flash_eraseall /dev/mtd4
    dd if=test.img of=/dev/mtd4 bs=8k count=1
    dd if=/dev/mtd4 of=test1.img bs=8k count=1
    md5sum test1.img

.. rubric:: Linux Userspace Interface
   :name: linux-userspace-interface

In situations where a premade SPI driver doesn't exist or a user wants a
simple means to send and receive SPI messages the spidev driver can be
used. Spidev provides a user space accessible means to communicate with
the SPI interface. Latest documentation regarding spidev driver can be
found
`here <https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/tree/Documentation/spi/spidev>`__.

Spidev allows users to interact with the spi interface in a variety of
programming languages that can communicate with kernel ioctls.

.. rubric:: Kernel Configuration
   :name: kernel-configuration-2

::

    Device Drivers  --->
       [*] SPI support
          <*> User mode SPI device driver support

.. rubric:: Device Tree
   :name: device-tree

Below is an example of the device tree settings a user would use to
enable the spidev driver. Like most drivers for a peripheral, the spidev
driver is listed as a subnode of the main SPI peripheral driver.

::

    &spi1 {
            status = "okay";
            pinctrl-names = "default";
            pinctrl-0 = <&spi1_pins_s0>;
            spidev@1 {
                    spi-max-frequency = <24000000>;
                    reg = <0>;
                    compatible = "rohm,dh2228fv";
            };
    };

-  Note that reg property for SPI subnodes are usually used to indicate
   the chip select to use when communicating with a particular driver.

.. rubric:: Test Application
   :name: test-application

In the kernel sources,
./tools/spi/\ `spidev\_test.c <https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/tree/tools/spi/spidev_test.c>`__
is a test application within the kernel that can be cross compiled to
show a C application interacting with the SPI peripheral.

.. raw:: html

