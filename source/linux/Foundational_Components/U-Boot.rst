.. convert from page http://processors.wiki.ti.com/index.php/Linux_Core_U-Boot_User%27s_Guide#Using_USB_Device_Firmware_Upgrade_.28DFU.29

*******************************
U-Boot
*******************************

Overview
==================

This document covers the general use of Linux Core Release of U-Boot on
following platforms:

-  `AM335x GP EVM <http://www.ti.com/tool/tmdxevm3358>`__
-  `AM335x EVM-SK <http://www.ti.com/tool/tmdssk3358>`__
-  `AM335x ICE <http://www.ti.com/tool/tmdsice3359>`__
-  `BeagleBone White <http://beagleboard.org/bone>`__
-  `BeagleBone Black <https://beagleboard.org/black>`__
-  `DRA74x EVM <http://www.ti.com/tool/j6evm5777>`__
-  `DRA72x EVM <http://www.ti.com/tool/dra72xevm>`__
-  `DRA71x EVM <http://www.ti.com/product/DRA718>`__
-  `AM437x GP EVM <http://www.ti.com/tool/tmdsevm437x>`__
-  AM43xx ePOS EVM
-  `AM437x EVM-SK <http://www.ti.com/tool/tmdxsk437x>`__
-  `AM437x IDK <http://www.ti.com/tool/TMDSIDK437X>`__
-  `AM572x GP EVM <http://www.ti.com/tool/tmdsevm572x>`__
-  `AM572x IDK <http://www.ti.com/tool/TMDXIDK5728>`__
-  `AM571x IDK <http://www.ti.com/tool/tmdxidk5718>`__
-  `66AK2H EVM <http://www.ti.com/tool/EVMK2H>`__
-  K2K EVM
-  `K2Ex EVM <http://www.ti.com/tool/xevmk2ex>`__
-  `K2L EVM <http://www.ti.com/tool/xevmk2lx>`__
-  `K2G GP EVM <http://www.ti.com/tool/evmk2g>`__
-  `K2G ICE EVM <http://www.ti.com/tool/k2gice>`__
-  `OMAP-L138 LCDK </index.php/L138/C6748_Development_Kit_(LCDK)>`__

+--------------------------+------------------+-----------------------+-------+--------+----------------------+---------------------------+--------------+
| Board                    | Wired ethernet   | USB gadget ethernet   | DFU   | NAND   | SD/eMMC              | USB Host (mass storage)   | SPI flash    |
+==========================+==================+=======================+=======+========+======================+===========================+==============+
| AM335x EVM               | yes              | yes                   | yes   | yes    | yes                  | yes                       | yes          |
+--------------------------+------------------+-----------------------+-------+--------+----------------------+---------------------------+--------------+
| AM335x EVM-SK            | yes              | yes                   | yes   | N/A    | yes                  | yes                       | N/A          |
+--------------------------+------------------+-----------------------+-------+--------+----------------------+---------------------------+--------------+
| Beaglebone White/Black   | yes              | yes                   | yes   | N/A    | yes                  | yes                       | N/A          |
+--------------------------+------------------+-----------------------+-------+--------+----------------------+---------------------------+--------------+
| DRA7xx EVM               | yes              | no                    | yes   | yes    | yes (both)           | yes                       | yes (QSPI)   |
+--------------------------+------------------+-----------------------+-------+--------+----------------------+---------------------------+--------------+
| AM43xx GP EVM            | yes              | no                    | yes   | yes    | yes (both)           | yes                       | yes (QSPI)   |
+--------------------------+------------------+-----------------------+-------+--------+----------------------+---------------------------+--------------+
| AM43xx ePOS EVM          | yes              | no                    | yes   | N/A    | yes (both)           | yes                       | yes (QSPI)   |
+--------------------------+------------------+-----------------------+-------+--------+----------------------+---------------------------+--------------+
| AM43xx EVM-SK            | yes              | no                    | yes   | N/A    | yes (both)           | yes                       | yes (QSPI)   |
+--------------------------+------------------+-----------------------+-------+--------+----------------------+---------------------------+--------------+
| AM57xx GP EVM            | yes              | no                    | no    | N/A    | yes (both)           | yes                       | N/A          |
+--------------------------+------------------+-----------------------+-------+--------+----------------------+---------------------------+--------------+
| K2H/K/E/L EVM            | yes              | no                    | no    | yes    | no                   | no                        | yes          |
+--------------------------+------------------+-----------------------+-------+--------+----------------------+---------------------------+--------------+
| K2G EVM                  | yes              | no                    | no    | no     | yes (both)           | no                        | yes (QSPI)   |
+--------------------------+------------------+-----------------------+-------+--------+----------------------+---------------------------+--------------+
| OMAP-L138 LCDK           | yes              | no                    | no    | yes    | yes (SD card only)   | no                        | no           |
+--------------------------+------------------+-----------------------+-------+--------+----------------------+---------------------------+--------------+

We assume that a GCC-based toolchain has already been installed and the
serial port for the board has been configured. We also assume that a
Linux Kernel has already been built (or has been provided) as well as an
appropriate filesystem image. Installing and setting up DHCP or TFTP
servers is also outside of the scope of this document, but snippets of
information are provided to show how to use a specific feature, when
needed.

Finally, please note that not all boards have all of the interfaces
documented here.

| 

| 

| 

General Information
===================================

.. rubric:: Getting the U-Boot Source Code
   :name: getting-the-u-boot-source-code

| The easiest way to get access to the U-boot source code is by
  downloading and installing the Processor SDK Linux. Once installed,
  the U-Boot source code is included in the SDK's board-support
  directory. For your convenience the sources also includes the U-Boot's
  git repository including commit history.
| Alternatively, U-Boot sources can directly be fetched from GIT. The
  GIT repo URL, branch and commit id can be found in the
  `Processor\_SDK\_Linux\_U-Boot\_Release\_Notes </index.php/Processor_SDK_Linux_U-Boot_Release_Notes>`__

.. rubric:: Device Trees
   :name: device-trees

A note about device trees. With this LCPD release all boards are
required to use a device tree to boot. To facilitate this in Sitara
family devices, within U-Boot we have a command in the environment named
**findfdt** that will set the **fdtfile** variable to the name of the
device tree to use, as found with the kernel sources. In the Keystone-2
family devices (K2H/K/E/L/G), it is specified by **name\_fdt** variable
for each platform. The device tree is expected to be loaded from the
same media as the kernel, and from the same relative path.

.. rubric:: Building MLO and u-boot
   :name: building-mlo-and-u-boot

We strongly recommend the use of separate object directories when
building. This is done with O= parameter to make. We also recommend that
you use an output directory name that is identical to the configuration
target name. That way if you are working with multiple configuration
targets it is very easy to know which folder contains the u-boot
binaries that you are interested in.

.. rubric:: Setting the tool chain path
   :name: setting-the-tool-chain-path

We strongly recommend using the toolchain that came with the Linux Core
release that corresponds to this U-Boot release. For e.g:

::

    export PATH=$HOME/gcc-linaro-4.9-2015.05-x86_64_arm-linux-gnueabihf/bin:$PATH

.. rubric:: Cleaning the Sources
   :name: cleaning-the-sources

If you did not use a separate object directory:

::

    $ make CROSS_COMPILE=arm-linux-gnueabihf- distclean

If you used 'O=am335x\_evm' as your object directory:

::

    $ rm -rf ./am335x_evm

.. rubric:: Compiling MLO and u-boot
   :name: compiling-mlo-and-u-boot

Building of both u-boot and SPL is done at the same time. You must
however first configure the build for the board you are working with.
Use the following table to determine what defconfig to use to configure
with:

+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+
| Board                      | SD Boot                     | eMMC Boot                | NAND Boot                                  | UART Boot                | Ethernet Boot            | USB Ethernet Boot        | USB Host Boot                           | NOR Boot                          | SPI Boot                                 |
+============================+=============================+==========================+============================================+==========================+==========================+==========================+=========================================+===================================+==========================================+
| AM335x GP EVM              | am335x\_evm\_defconfig      |                          | am335x\_evm\_defconfig                     | am335x\_evm\_defconfig   | am335x\_evm\_defconfig   | am335x\_evm\_defconfig   |                                         | am335x\_evm\_norboot\_defconfig   | am335x\_evm\_spiboot\_defconfig          |
+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+
| AM335x EVM-SK              | am335x\_evm\_defconfig      |                          |                                            | am335x\_evm\_defconfig   |                          | am335x\_evm\_defconfig   |                                         |                                   |                                          |
+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+
| AM335x ICE                 | am335x\_evm\_defconfig      |                          |                                            | am335x\_evm\_defconfig   |                          |                          |                                         |                                   |                                          |
+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+
| BeagleBone Black           | am335x\_evm\_defconfig      | am335x\_evm\_defconfig   |                                            | am335x\_evm\_defconfig   |                          |                          |                                         |                                   |                                          |
+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+
| BeagleBone White           | am335x\_evm\_defconfig      |                          |                                            | am335x\_evm\_defconfig   |                          |                          |                                         |                                   |                                          |
+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+
| AM437x GP EVM              | am43xx\_evm\_defconfig      |                          | am43xx\_evm\_defconfig                     | am43xx\_evm\_defconfig   | am43xx\_evm\_defconfig   | am43xx\_evm\_defconfig   | am43xx\_evm\_usbhost\_boot\_defconfig   |                                   |                                          |
+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+
| AM437x EVM-Sk              | am43xx\_evm\_defconfig      |                          |                                            |                          |                          |                          | am43xx\_evm\_usbhost\_boot\_defconfig   |                                   |                                          |
+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+
| AM437x IDK                 | am43xx\_evm\_defconfig      |                          |                                            |                          |                          |                          |                                         |                                   | am43xx\_evm\_qspiboot\_defconfig (XIP)   |
+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+
| AM437x ePOS EVM            | am43xx\_evm\_defconfig      |                          | am43xx\_evm\_defconfig                     |                          |                          |                          | am43xx\_evm\_usbhost\_boot\_defconfig   |                                   |                                          |
+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+
| AM572x GP EVM              | am57xx\_evm\_defconfig      |                          |                                            | am57xx\_evm\_defconfig   |                          |                          |                                         |                                   |                                          |
+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+
| AM572x IDK                 | am57xx\_evm\_defconfig      |                          |                                            |                          |                          |                          |                                         |                                   |                                          |
+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+
| AM571x IDK                 | am57xx\_evm\_defconfig      |                          |                                            |                          |                          |                          |                                         |                                   |                                          |
+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+
| DRA74x/DRA72x/DRA71x EVM   | dra7xx\_evm\_defconfig      | dra7xx\_evm\_defconfig   | dra7xx\_evm\_defconfig (DRA71x EVM only)   |                          |                          |                          |                                         |                                   | dra7xx\_evm\_defconfig(QSPI)             |
+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+
| K2HK EVM                   |                             |                          | k2hk\_evm\_defconfig                       | k2hk\_evm\_defconfig     | k2hk\_evm\_defconfig     |                          |                                         |                                   | k2hk\_evm\_defconfig                     |
+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+
| K2L EVM                    |                             |                          | k2l\_evm\_defconfig                        | k2l\_evm\_defconfig      |                          |                          |                                         |                                   | k2l\_evm\_defconfig                      |
+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+
| K2E EVM                    |                             |                          | k2e\_evm\_defconfig                        | k2e\_evm\_defconfig      |                          |                          |                                         |                                   | k2e\_evm\_defconfig                      |
+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+
| K2G GP EVM                 | k2g\_evm\_defconfig         |                          |                                            | k2g\_evm\_defconfig      | k2g\_evm\_defconfig      |                          |                                         |                                   | k2g\_evm\_defconfig                      |
+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+
| K2G ICE                    | k2g\_evm\_defconfig         |                          |                                            |                          |                          |                          |                                         |                                   |                                          |
+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+
| OMAP-L138 LCDK             | omapl138\_lcdk\_defconfig   |                          | omapl138\_lcdk\_defconfig                  |                          |                          |                          |                                         |                                   |                                          |
+----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+-----------------------------------+------------------------------------------+

Then:

::

    # Use 'am335x_evm' and 'AM335x GP EVM' in this example
    $ make CROSS_COMPILE=arm-linux-gnueabihf- O=am335x_evm am335x_evm_defconfig
    $ make CROSS_COMPILE=arm-linux-gnueabihf- O=am335x_evm

Note that not all possible build targets for a given platform are listed
here as the community has additional build targets that are not
supported by TI. To find these read the 'boards.cfg' file and look for
the build target listed above. And please note that the main config file
will leverage other files under include/configs, as seen by #include
statements.

| 

| 

| 

.. rubric:: U-Boot Environment
   :name: u-boot-environment

Please note that on many boards we modify the environment during system
start for a variety of variables such as **board\_name** and if unset,
**ethaddr**. When we restore defaults some variables will become unset,
and this can lead to other things not working such as **findfdt** that
rely on these run-time set variables.

.. rubric:: Restoring defaults
   :name: restoring-defaults

It is possible to reset the set of U-Boot environment variables to their
defaults and if desired, save them to where the environment is stored,
if applicable. It is also required to restore the default setting when
u-boot version changes from an upgrade or downgrade. To do so, issue the
following commands:

::

    U-Boot # env default -f -a
    U-Boot # saveenv

| 

| 

| 

.. rubric:: Networking Environment
   :name: networking-environment

When using a USB-Ethernet dongle a valid MAC address must be set in the
environment. To create a valid address please read `**this
page** <http://www.denx.de/wiki/view/DULG/WhereCanIGetAValidMACAddress>`__.
Then issue the following command:

::

    U-Boot # setenv usbethaddr value:from:link:above

You can use the **printenv** command to see if **usbethaddr** is already
set.

Then start the USB subsystem:

::

    U-Boot # usb start

The default behavior of U-Boot is to utilize all information that a DHCP
server passes to us when the user issues the **dhcp** command. This will
include the dhcp parameter *next-server* which indicates where to fetch
files from via TFTP. There may be times however where the dhcp server on
your network provides incorrect information and you are unable to modify
the server. In this case the following steps can be helpful:

::

    U-Boot # setenv autoload no
    U-Boot # dhcp
    U-Boot # setenv serverip correct.server.ip
    U-Boot # tftp

Another alternative is to utilize the full syntax of the tftp command:

::

    U-Boot # setenv autoload no
    U-Boot # dhcp
    U-Boot # tftp ${loadaddr} server.ip:fileName

.. rubric:: Available RAM for image download
   :name: available-ram-for-image-download

To know the amount of RAM available for downloading images or for other
usage, use ``bdinfo`` command.

::

    => bdinfo
    arch_number = 0x00000000
    boot_params = 0x80000100
    DRAM bank   = 0x00000000
    -> start    = 0x80000000
    -> size     = 0x7F000000
    baudrate    = 115200 bps
    TLB addr    = 0xFEFF0000
    relocaddr   = 0xFEF30000
    reloc off   = 0x7E730000
    irq_sp      = 0xFCEF8880
    sp start    = 0xFCEF8870
    Early malloc usage: 890 / 2000

After booting, U-Boot relocates itself (along with its various reserved
RAM areas) and places itself at end of available RAM (starting at
``relocaddr`` in ``bdinfo`` output above). Only the stack is located
just before that area. The address of top of the stack is in
``sp start`` in ``bdinfo`` output and it grows downwards. Users should
reserve at least about 1MB for stack, so in the example output above,
RAM in the range of ``[0x80000000, 0xFCE00000]`` is safely available for
use.

| 

| 

| 

USB Device Firmware Upgrade
===================================

When working with USB Device Firmware Upgrade (DFU), regardless of the
medium to be written to and of the board being used, there are some
general things to keep in mind. First of all, you will need to get a
copy of the **dfu-util** program installed on your host. If your
distribution does not provide this package you will need to build it
from source. Second, the examples that follow assume a single board is
plugged into the host PC. If you have more than one device plugged in
you will need to use the options that **dfu-util** provides for
specifying a single device to work with. Finally, to program via DFU for
a given storage device see the section for the storage device you are
working with.

.. rubric:: USB Peripheral boot mode on DRA7x/AM57x (SPL-DFU support)
   :name: usb-peripheral-boot-mode-on-dra7xam57x-spl-dfu-support

The USB Peripheral boot mode is used to boot DRA7x EVM using USB
interface using SPL-DFU feature. Same steps could be used on an AM57x
SoC where board support USB peripheral boot mode.

#. Enable the SPL-DFU feature in u-boot and build MLO/u-boot binaries.
#. Load the MLO and u-boot.img using the dfu-util from host PC.
#. Once the u-boot is up, use DFU command from u-boot to flash the
   binary images from Host PC (using dfu-utils tool) to the eMMC, or
   QSPI to fresh/factory boards.

-  Example provided here is for dra7xx platform.

-  Use default "dra7xx\_evm\_defconfig" to build spl/u-boot-spl.bin,
   u-boot.img.

::

     host$ make dra7xx_evm_defconfig
     host$ make menuconfig

     select SPL/DFU support
     menuconfig->SPL/TPL--->
        ..
        [*] Support booting from RAM
        [*] Support USB Gadget drivers
        [ ]    Support USB Ethernet drivers
        [*]    Support DFU (Device Firmware Upgrade)
                  DFU device selection (RAM device) -->

::

     Unselect CONFIG_HUSH_PARSER
     menuconfig--->Command Line interface
        [*] Support U-boot commands
        [ ]   Use hush shell

-  Build spl/u-boot-spl.bin and u-boot.img

::

     host$ make

-  Set SYSBOOT SW2 switch to USB Peripheral boot mode

::

     SW2[7..0] = 00010000 (refer to TRM for various booting order)

-  Connect EVM Superspeed port (USB1 port) to PC (Ubuntu) through USB
   cable.
-  From Ubuntu (or the host) PC, fetch and build usbboot application.
   usbboot pre-built binaries for particular distributions may be
   available in `processor
   SDK </index.php/Processor_SDK_Linux_Software_Developer%E2%80%99s_Guide>`__
   already. Here are the steps to build usbboot application.

::

    host$ git clone git://git.omapzoom.org/repo/omapboot.git
    host$ cd omapboot
    host$ checkout 609ac271d9f89b51c133fd829dc77e8af4e7b67e
    host$ make -C host/tools 

This results in host side tool called ``usbboot-stand-alone``

For loading spl/u-boot-spl.bin to EVM, issue the command below and reset
the board.

::

    host$ sudo usbboot-stand-alone -S spl/u-boot-spl.bin

-  Load the u-boot.img to RAM.

::

    host$ sudo dfu-util -l

::

    Found DFU: [0451:d022] devnum=0, cfg=1, intf=0, alt=0, name="kernel"
    Found DFU: [0451:d022] devnum=0, cfg=1, intf=0, alt=1, name="fdt"
    Found DFU: [0451:d022] devnum=0, cfg=1, intf=0, alt=2, name="ramdisk"

::

    host$ sudo dfu-util c 1 -i 0 -a 0 -D "u-boot.img" -R

-  Now EVM will boot to u-boot prompt.

| 

| 

| 

Network
===================================

This section documents how to configure the network and use it to load
files and then boot the Linux Kernel using a root filesystem mounted
over NFS. At this time, no special builds of U-Boot are required to
perform these operations on the supported hardware.

.. rubric:: Booting U-Boot from the network
   :name: booting-u-boot-from-the-network

In some cases we support loading SPL and U-Boot over the network because
of ROM support. In some cases, a special build of U-Boot may be
required. In addition, the DHCP server is needed to reply to the target
with the file to fetch via tftp. In order to facilitate this, the
**vendor-class-identifier** DHCP field is filled out by the ROM and the
values are listed in the table below. Finally, you will need to use the
**spl/u-boot-spl.bin** and **u-boot.img** files to boot.

+-----------------------------------+---------------+--------------------------------------+------------------------------------------------------+-------------------------------------+
| Board                             | make target   | Supported interfaces                 | ROM vendor-class-identifier value                    | SPL vendor-class-identifier value   |
+===================================+===============+======================================+======================================================+=====================================+
| AM335x GP EVM                     | am335x\_evm   | CPSW ethernet                        | DM814x ROM (PG1.0) or AM335x ROM (PG2.0 and later)   | AM335x U-Boot SPL                   |
+-----------------------------------+---------------+--------------------------------------+------------------------------------------------------+-------------------------------------+
| AM335x GP EVM (PG2.0 and later)   | am335x\_evm   | SPL and U-Boot via USB RNDIS         | AM335x ROM                                           | AM335x U-Boot SPL                   |
+-----------------------------------+---------------+--------------------------------------+------------------------------------------------------+-------------------------------------+
| AM335x GP EVM (PG1.0)             | am335x\_evm   | SPL via UART, U-Boot via USB RNDIS   | N/A                                                  | AM335x U-Boot SPL                   |
+-----------------------------------+---------------+--------------------------------------+------------------------------------------------------+-------------------------------------+
| AM43xx EVM                        | am43xx\_evm   | CPSW ethernet                        | AM43xx ROM                                           | AM43xx U-Boot SPL                   |
+-----------------------------------+---------------+--------------------------------------+------------------------------------------------------+-------------------------------------+
| AM43xx EVM (PG1.2 and later)      | am43xx\_evm   | SPL and U-Boot via USB RNDIS         | AM43xx ROM                                           | AM43xx U-Boot SPL                   |
+-----------------------------------+---------------+--------------------------------------+------------------------------------------------------+-------------------------------------+

If using ISC dhcpd an example host entry would look like this:

::

    host am335x_evm {
      hardware ethernet de:ad:be:ee:ee:ef;
      # Check for PG1.0, typically CPSW
      if substring (option vendor-class-identifier, 0, 10) = "DM814x ROM" {
        filename "u-boot-spl.bin";
      # Check for PG2.0, CPSW or USB RNDIS
      } elsif substring (option vendor-class-identifier, 0, 10) = "AM335x ROM" {
        filename "u-boot-spl.bin";
      } elsif substring (option vendor-class-identifier, 0, 17) = "AM335x U-Boot SPL" {
        filename "u-boot.img";
      } else {
        filename "zImage-am335x-evm.bin";
      }
    }

Note that in a factory type setting, the substring tests can be done
inside of the subnet declaration to set the default filename value for
the subnet, and overriden (if needed) in a host entry.

If you have removed NetworkManager from your system (which is not the
default in most distributions) you need to configure your
/etc/network/interfaces file thusly:

::

    allow-hotplug usb0
    iface usb0 inet static
            address 192.168.1.1
            netmask 255.255.255.0
            post-up service isc-dhcp-server reload

If you are using NetworkManager you need to create two files. First, as
root create /etc/NetworkManager/system-connections/AM335x USB RNDIS (and
use \\ to escape the space) with the following content:

::


    [802-3-ethernet]
    duplex=full
    mac-address=AA:BB:CC:11:22:33

    [connection]
    id=AM335X USB RNDIS
    uuid=INSERT THE CONTENTS OF 'uuidgen' HERE
    type=802-3-ethernet

    [ipv6]
    method=ignore

    [ipv4]
    method=manual
    addresses1=192.168.1.1;16;

Seccond as root, and ensuring execute permissions, create
/etc/NetworkManager/dispatcher.d/99am335x-dhcp-server

::

    #!/bin/sh

    IF=$1
    STATUS=$2

    if [ "$IF" = "usb0" ] && [ "$STATUS" = "up" ]; then
        service isc-dhcp-server reload
    fi

A walk through of these steps can be seen at `Ubuntu 12.04 Set Up to
Network Boot an AM335x Based
Platform </index.php/Ubuntu_12.04_Set_Up_to_Network_Boot_an_AM335x_Based_Platform>`__.

| 

| 

| 

.. rubric:: Multiple Interfaces
   :name: multiple-interfaces

On some boards, for example when we have both a wired interface and USB
RNDIS gadget ethernet, it can be desirable to change from the default
U-Boot behavior of cycling over each interface it knows to telling
U-Boot to use a single interface. For example, on start you may see
lines like:

::

    Net:   cpsw, usb_ether

So to ensure that we use **usb\_ether** first issue the following
command:

::

    U-Boot # setenv ethact usb_ether

.. rubric:: Network configuration via DHCP
   :name: network-configuration-via-dhcp

To configure the network via DHCP, use the following commands:

::

    U-Boot # setenv autoload no
    U-Boot # dhcp

And ensure that a DHCP server is configured to serve addresses for the
network you are connected to.

.. rubric:: Manual network configuration
   :name: manual-network-configuration

To configure the network manually, the **ipaddr**, **serverip**,
**gatewayip** and **netmask**:

::

    U-Boot # setenv ipaddr 192.168.1.2
    U-Boot # setenv serverip 192.168.1.1
    U-Boot # setenv gatewayip 192.168.1.1
    U-Boot # setenv netmask 255.255.255.0

.. rubric:: Disabling Gigabit Phy Advertising
   :name: disabling-gigabit-phy-advertising

On some boards like DRA72x Rev B or earlier, there is an issue like
ethernet doesn't connect to 1Gbps switch. This issue is due to the use
of an old ti phy with history of bad behaviour, due to this several J6
EVMs have been marked 100M only. So here is the U-Boot command to
disable phy's 1Gbps support and connect as 100Mbps max capable.

::

    => mii modify 0x3 0x9 0x0 0x300      /* Disable Gigabit advertising */
    => mii modify 0x3 0x0 0x0 0x1000     /* Disable Auto Negotiation */
    => mii modify 0x3 0x0 0x1000 0x1000  /* Enable Auto Negotiation */

.. rubric:: Booting Linux from the network
   :name: booting-linux-from-the-network

Within the default environment for each board that supports networking
there is a boot command called **netboot** in AM EVMs and **boot=net**
in KS2 EVMs that will automatically load the kernel and boot. For the
exact details of each use **printenv** on the **netboot** variable and
then in turn **printenv** other sub-sections of the command. The most
important variables in AM57x/DRA7x are **rootpath** and **nfsopts**, and
**tftp\_root** and **nfs\_root** in K2H/K/E/L/G.

| 

| 

| 

| 

NAND
===================================

This section documents how to write files to the NAND device and use it
to load and then boot the Linux Kernel using a root filesystem also
found on NAND.

.. rubric:: Erasing, Reading and Writing to/from NAND partitions
   :name: erasing-reading-and-writing-tofrom-nand-partitions

.. rubric:: Listing NAND partitions
   :name: listing-nand-partitions

Below command is used to see the list of mtd devices enabled in U-boot

::

    mtdparts

Example output on DRA74x EVM:

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

| 

| 

.. rubric:: Writing to NAND via DFU
   :name: writing-to-nand-via-dfu

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

.. rubric:: NAND Boot
   :name: nand-boot

If you want to load and run U-Boot from NAND the first step is insuring
that the appropriate U-boot files are loaded in the correct partition.
For AM335x, AM437x, DRA7x devices this means writing the file MLO to the
NAND's SPL partition. For OMAP-L138 device, write the .ais image to the
NAND's partition. For all devices this requires writing u-boot.img to
the NAND's U-Boot partition.

`Note </index.php?title=Note&action=edit&redlink=1>`__: The NAND
partition of OMAP-L138 is different from other devices, please use the
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

| 

| 

.. rubric:: Booting Kernel and Filesystem from NAND
   :name: booting-kernel-and-filesystem-from-nand

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
`here </index.php/Linux_Core_NAND_User%27s_Guide#.23Building_UBI_File_system>`__.

| 

| 

| 

SD, eMMC or USB Storage
====================================

The commands for using SD cards, eMMC flash and USB mass storage devices
(hard drives, flash drives, card readers, etc) are all very similar. The
biggest difference is that on some hardware we may not be able to run
U-Boot out of ROM from the storage device as it is unsupported. Once
U-Boot is running however, any of these may be used for the kernel and
the root filesystem.

.. rubric:: Partitioning eMMC from U-Boot
   :name: partitioning-emmc-from-u-boot

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
    U-Boot # gpt write mmc 1 ${partitions}

A reset is required for the partition table to be visible.

.. rubric:: Updating an SD card from a host PC
   :name: updating-an-sd-card-from-a-host-pc

This section assume that you have created an SD card following the
instructions on `Sitara Linux SDK create SD card
script </index.php/Sitara_Linux_SDK_create_SD_card_script>`__ or have
made a compatible layout by hand. In this case, you will need to copy
the **MLO** and **u-boot.img** files to the *boot* partition. At this
point, the card is now bootable in the SD card slot. We default to using
**/boot/zImage** on the *rootfs* partition and the device tree file
loaded from **/boot** with the same name as in the kernel.

However, if you are using OMAP-L138 based board (like the LCDK), then
you need to write the generated ``u-boot.ais`` image to the SD card
using ``dd`` command.

::

     $ sudo dd if=u-boot.ais of=/dev/sd<N> seek=117 bs=512 conv=fsync

.. rubric:: Updating an SD card or eMMC using DFU
   :name: updating-an-sd-card-or-emmc-using-dfu

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

.. rubric:: Updating an SD card or eMMC with RAW writes
   :name: updating-an-sd-card-or-emmc-with-raw-writes

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

.. rubric:: Booting Linux from SD card or eMMC
   :name: booting-linux-from-sd-card-or-emmc

Within the default environment for each board that supports SD/MMC there
is a boot command called **mmcboot** that will set the boot arguments
correctly and start the kernel. In this case however, you must first run
**loaduimagefat** or **loaduimage** to first load the kernel into
memory. For the exact details of each use **printenv** on the
**mmcboot**, **loaduimagefat** and **loaduimage** variables and then in
turn **printenv** other sub-sections of the command. The most important
variables here are **mmcroot** and **mmcrootfstype**.

.. rubric:: Booting MLO and u-boot from eMMC boot partition
   :name: booting-mlo-and-u-boot-from-emmc-boot-partition

The DRA7xx and AM57xx processors support booting from the eMMC boot
partition. To do this, some u-boot files need to be modified. First swap
two values in u-boot//arch/arm/include/asm/arch-omap5/spl.h.

::

    From
    #define BOOT_DEVICE_MMC1        0x05
    #define BOOT_DEVICE_MMC2        0x06
    #define BOOT_DEVICE_MMC2_2      0x07
    To
    #define BOOT_DEVICE_MMC1        0x05
    #define BOOT_DEVICE_MMC2        0x07
    #define BOOT_DEVICE_MMC2_2      0x06

Next add the boot partition to the list of boot devices. Modify
u-boot/arch/arm/mach-omap2/omap5/boot.c and change.

::

    From
    static u32 boot_devices[] = {
    #if defined(CONFIG_DRA7XX)
            BOOT_DEVICE_MMC2,
            BOOT_DEVICE_NAND,
    To
    static u32 boot_devices[] = {
    #if defined(CONFIG_DRA7XX)
            BOOT_DEVICE_MMC2_2,
            BOOT_DEVICE_MMC2,
            BOOT_DEVICE_NAND,

Finally modify the board's defconfig and add.

::

    CONFIG_SYS_EXTRA_OPTIONS="EMMC_BOOT"

Then use the following commands to make the boot partition read-write
and write MLO and u-boot.img to the boot partition.

::

    echo 0 > /sys/block/mmcblk1boot0/force_ro
    dd if=/dev/zero of=/dev/mmcblk1boot0 bs=512
    dd if=MLO of=/dev/mmcblk1boot0 bs=512
    dd if=u-boot.img of=/dev/mmcblk1boot0 bs=512 seek=768

| 

| 

| 

.. rubric:: Booting Linux from USB storage
   :name: booting-linux-from-usb-storage

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

.. rubric:: Booting from SD/eMMC from SPL (Single stage or Falcon mode)
   :name: booting-from-sdemmc-from-spl-single-stage-or-falcon-mode

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

| 

| 

| 


SPI
====================================


This section documents how to write files to the SPI device and use it
to load and then boot the Linux Kernel using a root filesystem also
found on SPI. At this time, no special builds of U-Boot are required to
perform these operations on the supported hardware. The table below
however, lists builds that will also use the SPI flash for the
environment instead of the default, which typically is NAND in AM57x and
DRA7x EVMs, but in Keystone-2 EVMs, it is only NOR. Finally, for
simplicity we assume the files are being loaded from an SD card. Using
the network interface (if applicable) is documented above.

.. rubric:: Writing to SPI from U-Boot
   :name: writing-to-spi-from-u-boot

Note for AM57x and DRA7x platforms:

-  From the U-Boot build, the **MLO.byteswap** and **u-boot.img** files
   are the ones to be written.
-  We load all files from an SD card in this example but they can just
   as easily be loaded via network (documented above) or other interface
   that exists.
-  At this time the SPI mtd partition map has not yet been updated to
   include an example location for the device tree.

+--------------+--------------------------------+
| Board        | Config target                  |
+==============+================================+
| AM335x EVM   | am335x\_evm\_spiboot\_config   |
+--------------+--------------------------------+

::

    U-Boot # mmc rescan
    U-Boot # sf probe 0
    U-Boot # sf erase 0 +80000
    U-Boot # fatload mmc 0 ${loadaddr} MLO.byteswap
    U-Boot # sf write ${loadaddr} 0 ${filesize}
    U-Boot # fatload mmc 0 ${loadaddr} u-boot.img
    U-Boot # sf write ${loadaddr} 0x20000 ${filesize}
    U-Boot # sf erase 80000 +${spiimgsize}
    U-Boot # fatload mmc 0 ${loadaddr} zImage
    U-Boot # sf write ${loadaddr} ${spisrcaddr} ${filesize}

Note for Keystone-2 (K2H/K/E/L/G) platforms:

-  From the U-Boot build, the **u-boot-spi.gph** file is the one to be
   written.
-  We load the file from a tftp server via netowrk in this example.
-  The series commands burns the u-boot image to the SPI NOR flash

::

    U-Boot # env default -f -a
    U-Boot # setenv serverip <ip address of tftp server>
    U-Boot # setenv tftp_root <tftp root directory>
    U-Boot # setenv name_uboot u-boot-spi.gph
    U-Boot # run get_uboot_net
    U-Boot # run burn_uboot_spi

| 

| 

| 

.. rubric:: Booting from SPI
   :name: booting-from-spi

Within the default environment for each board that supports SPI there is
a boot command called **spiboot** that will automatically load the
kernel and boot. For the exact details of each use **printenv** on the
**spiboot** variable and then in turn **printenv** other sub-sections of
the command. The most important variables here are **spiroot** and
**spirootfstype**. For Keystone-2 platforms, it is configured to be
**ARM SPI** boot mode using SW1 dip switch setting. Please refer to the
Hardware Setup of each Keystone-2 EVM.

| 

| 

| 

QSPI
====================================

QSPI is a serial peripheral interface like SPI the major difference
being the support for Quad read, uses 4 data lines for read compared to
2 lines used by the traditional SPI. This section documents how to write
files to the QSPI device and use it to load and then boot the Linux
Kernel using a root filesystem also found on QSPI. At this time, no
special builds of U-Boot are required to perform these operations on the
supported hardware. For simplicity we assume the files are being loaded
from an SD card. Using the network interface (if applicable) is
documented above.

.. rubric:: DRA7xx support
   :name: dra7xx-support

Memory Layout of QSPI Flash

::

    +----------------+ 0x00000
    |      MLO       |
    |                |
    +----------------+ 0x040000
    |   u-boot.img   |
    |                |
    +----------------+ 0x140000
    |   DTB blob     |
    +----------------+ 0x1c0000
    |   u-boot env   |
    +----------------+ 0x1d0000
    |   u-boot env   |
    |    (backup)    |
    +----------------+ 0x1e0000
    |                |
    |     uImage     |
    |                |
    |                |
    +----------------+ 0x9e0000
    |                |
    |  other data    |
    |                |
    +----------------+

.. rubric:: Writing to QSPI from U-Boot
   :name: writing-to-qspi-from-u-boot

Note:

-  From the U-Boot build, the **MLO** and **u-boot.img** files are the
   ones to be written.
-  We load all files from an SD card in this example but they can just
   as easily be loaded via network (documented above) or other interface
   that exists.

Writing MLO and u-boot.img binaries.

For QSPI\_1 build U-Boot with ``dra7xx_evm_config``

::

    U-Boot # mmc rescan
    U-Boot # fatload mmc 0 ${loadaddr} MLO
    U-Boot # sf probe 0
    U-Boot # sf erase 0x00000 0x100000
    U-Boot # sf write ${loadaddr} 0x00000 ${filesize}
    U-Boot # fatload mmc 0 ${loadaddr} u-boot.img
    U-Boot # sf write ${loadaddr} 0x40000 ${filesize}

change SW2[5:0] = 110110 for qspi boot.

For QSPI\_4 build U-Boot with ``dra7xx_evm_qspiboot_config``

::

    U-Boot # mmc rescan
    U-Boot # fatload mmc 0 ${loadaddr} MLO
    U-Boot # sf probe 0
    U-Boot # sf erase 0x00000 0x100000
    U-Boot # sf write ${loadaddr} 0x00000 0x10000
    U-Boot # fatload mmc 0 ${loadaddr} u-boot.img
    U-Boot # sf write ${loadaddr} 0x40000 0x60000

change SW2[5:0] = 110111 for qspi boot.

| 

| 

| 

.. rubric:: Writing to QSPI using DFU
   :name: writing-to-qspi-using-dfu

Setup: Connect the usb0 port of EVM to ubuntu host PC. Make sure
dfu-util tool is installed.

::

     #sudo apt-get install dfu-util

From u-boot:

::

    U-Boot # env default -a
    U-Boot # setenv dfu_alt_info ${dfu_alt_info_qspi}; dfu 0 sf "0:0:64000000:0"

From ubuntu PC: Using dfu-util utilities to flash the binares to QSPI
flash.

::

    # sudo dfu-util -l
    (C) 2005-2008 by Weston Schmidt, Harald Welte and OpenMoko Inc.
    (C) 2010-2011 Tormod Volden (DfuSe support)
    This program is Free Software and has ABSOLUTELY NO WARRANTY
    dfu-util does currently only support DFU version 1.0
    Found DFU: [0451:d022] devnum=0, cfg=1, intf=0, alt=0, name="MLO"
    Found DFU: [0451:d022] devnum=0, cfg=1, intf=0, alt=1, name="u-boot.img"
    Found DFU: [0451:d022] devnum=0, cfg=1, intf=0, alt=2, name="u-boot-spl-os"
    Found DFU: [0451:d022] devnum=0, cfg=1, intf=0, alt=3, name="u-boot-env"
    Found DFU: [0451:d022] devnum=0, cfg=1, intf=0, alt=4, name="u-boot-env.backup"
    Found DFU: [0451:d022] devnum=0, cfg=1, intf=0, alt=5, name="kernel"

Flash the binaries to the respective regions using alternate interface
number (alt=<x>).

::

    # sudo dfu-util -c 1 -i 0 -a 0 -D MLO
    # sudo dfu-util -c 1 -i 0 -a 1 -D u-boot.img
    # sudo dfu-util -c 1 -i 0 -a 2 -D <DTB-file>
    # sudo dfu-util -c 1 -i 0 -a 5 -D uImage

.. rubric:: Booting from QSPI from u-boot
   :name: booting-from-qspi-from-u-boot

The default environment does not contain a QSPI boot command. The
following example uses the partition table found in the kernel.

::

    U-Boot # sf probe 0
    U-Boot # sf read ${loadaddr} 0x1e0000 0x800000
    U-Boot # sf read ${fdtaddr} 0x140000 0x80000
    U-Boot # setenv bootargs console=${console} root=/dev/mtdblock19 rootfstype=jffs2
    U-Boot # bootz ${loadaddr} - ${fdtaddr}

.. rubric:: Booting from QSPI from SPL (Single stage or Falcon mode)
   :name: booting-from-qspi-from-spl-single-stage-or-falcon-mode

In this boot mode SPL (first stage bootloader) directly boots the Linux
kernel. Optionally, in order to enter into U-Boot, reset the board while
keeping 'c' key on the serial terminal pressed. When falcon mode is
enabled in U-Boot build (usually enabled by default), MLO checks if
there is a valid uImage present at a defined offset. If uImage is
present, it is booted directly. If valid uImage is not found, MLO falls
back to booting u-boot.img.

For QSPI single stage or Falcon mode, the CONFIG\_QSPI\_BOOT shall
enabled.

::

    Menuconfig->Bood media
       [ ] Support for booting from NAND flash
       ..
       [*] Support for booting from QSPI flash
       [ ] Support for booting from SATA
       ...

MLO, u-boot.img (optional), DTB, uImage are stored in QSPI flash memory.
Refer the "Memory Layout" section for offset details. To flash binaries
to QSPI, you can use
`DFU </index.php/Linux_Core_U-Boot_User%27s_Guide#Writing_to_QSPI_using_DFU>`__,
for example.

The QSPI boot uses uImage. Build the kernel uImage. You will need to
keep the U-Boot tool ``mkimage`` in your ``$PATH``

::

    # make uImage modules dtbs LOADADDR=80008000

If kernel is not build with ``CONFIG_CMDLINE`` to set correct bootargs,
then add the needed bootargs in chosen node in DTB file, using fdtput
host utility. For example, for DRA74x EVM:

::

    # fdtput -v -t s arch/arm/boot/dts/dra7-evm.dtb "/chosen" bootargs "console=ttyO0,115200n8 root=<rootfs>"

Set the environment variable "boot\_os" to 1.

From u-boot prompt

::

    => setenv boot_os 1
    => saveenv

Set the `board boot from
QSPI </index.php/Linux_Core_U-Boot_User%27s_Guide#Writing_to_QSPI_from_U-Boot>`__
and reset the EVM. The SPL directly boots the kernel image from QSPI.

| 

| 

| 

.. rubric:: AM43xx support
   :name: am43xx-support

Using QSPI on AM43xx platforms is done as eXecute In Place and U-Boot is
directly booted.

.. rubric:: Writing to QSPI from U-Boot
   :name: writing-to-qspi-from-u-boot-1

Note:

-  From the U-Boot build the **u-boot.bin** file is the one to be
   written.
-  We load all files from an SD card in this example but they can just
   as easily be loaded via network (documented above) or other interface
   that exists.

::

    U-Boot # mmc rescan
    U-Boot # fatload mmc 0 ${loadaddr} u-boot.bin
    U-Boot # sf probe 0
    U-Boot # sf erase 0x0 0x100000
    U-Boot # sf write ${loadaddr} 0x0 ${filesize}

.. rubric:: Booting from QSPI
   :name: booting-from-qspi

The default environment does not contain a QSPI boot command. The
following example uses the partition table found in the kernel.

::

    U-Boot # sf probe 0
    U-Boot # sf read ${loadaddr} 0x1a0000 0x800000
    U-Boot # sf read ${fdtaddr} 0x100000 0x80000
    U-Boot # setenv bootargs console=${console} spi-ti-qspi.enable_qspi=1 root=/dev/mtdblock6 rootfstype=jffs2
    U-Boot # bootz ${loadaddr} - ${fdtaddr}

| 

| 

| 

NOR
====================================

This section documents how to write files to the NOR device and use it
to load and then boot the Linux Kernel using a root filesystem also
found on NOR. In order for NOR to be visible to U-Boot a special build
of U-Boot is required on the supported hardware. The table below lists
builds that see NOR and in some cases also use theit for the environment
instead of the default, which typically is NAND. Finally, for simplicity
we assume the files are being loaded from an SD card. Using the network
interface (if applicable) is documented above.

.. rubric:: Writing to NOR from U-Boot
   :name: writing-to-nor-from-u-boot

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

.. rubric:: Booting from NOR
   :name: booting-from-nor

Within the default environment there is not a shortcut for booting. One
needs to pass **root=/dev/mtdblockN** where N is the number of the
rootfs partition in **bootargs**.

UART
====================================


This section documents how to use the UART to load files to boot the
board into U-Boot. After that the user is expected to know how they want
to continue loading files.

.. rubric:: Booting U-Boot from the console UART
   :name: booting-u-boot-from-the-console-uart

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

SATA
====================================

SATA and eSATA devices show up as SCSI devices in U-boot.

.. rubric:: Viewing SATA Devices
   :name: viewing-sata-devices

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

.. rubric:: Viewing Partitions
   :name: viewing-partitions

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

.. rubric:: Identifying Partition Filesystem Type
   :name: identifying-partition-filesystem-type

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

| 

| 

.. rubric:: Viewing, Reading and Writing to Partition
   :name: viewing-reading-and-writing-to-partition

Depending on the filesystem type of the partition will depend on the
exact commands to use to read and write to the partition. The two most
common partitions are FAT32, EXT2 and EXT4. Luckily the commands to
view, read and write to the partition all look the same. Viewing
partition uses <prefix>ls, reading files is <prefix>load and writing
files is <prefix>write. Replace <prefix> with fat, ext2 and ext4
depending on the filesystem type.

.. rubric:: = View Partition Contents
   :name: view-partition-contents

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

.. rubric:: Adding a splash screen
   :name: adding-a-splash-screen

.. rubric:: AM335x
   :name: am335x

All the code below is based on Processor Linux SDK 03.02.00..05.

There is a frame buffer driver for am335x in the drivers/video directory
called am3355x-fb.c. It makes calls to routines in board.c to set up the
LCDC and frame buffer. To use it:

Either create a new defconfig in the configs directory or just add
SPLASH to CONFIG\_SYS\_EXTRA\_OPTIONS. In this example the
am335x\_evm\_defconfig is copied into a new one called
am335x\_evm\_splash\_defconfig.

::

    CONFIG_TARGET_AM335X_EVM=y
    CONFIG_SPL_STACK_R_ADDR=0x82000000
    CONFIG_DEFAULT_DEVICE_TREE="am335x-evm"
    CONFIG_SPL=y
    CONFIG_SPL_STACK_R=y
    CONFIG_SYS_EXTRA_OPTIONS="NAND,SPLASH"
    CONFIG_HUSH_PARSER=y
    CONFIG_AUTOBOOT_KEYED=y

In include/configs/am335x\_evm.h, add support for the splash screen,
LCDC, and gzipped bitmaps.

::

    /* Splash scrren support */
    #ifdef CONFIG_SPLASH
    #define CONFIG_AM335X_LCD
    #define CONFIG_LCD
    #define CONFIG_LCD_NOSTDOUT
    #define CONFIG_SYS_WHITE_ON_BLACK
    #define LCD_BPP LCD_COLOR16

    #define CONFIG_VIDEO_BMP_GZIP
    #define CONFIG_SYS_VIDEO_LOGO_MAX_SIZE  (1366*767*4)
    #define CONFIG_CMD_UNZIP
    #define CONFIG_CMD_BMP
    #define CONFIG_BMP_16BPP
    #endif

In arch/arm/cpu/armv7/am33xx/clock\_am33xx.c enable the LCDC clocks.

::

                    &cmrtc->rtcclkctrl,
                    &cmper->usb0clkctrl,
                    &cmper->emiffwclkctrl,
                    &cmper->emifclkctrl,
                    &cmper->lcdclkctrl,
                    &cmper->lcdcclkstctrl,
                    &cmper->epwmss2clkctrl,
                    0

In board.c add includes for mmc, fat, lcd, and the frame buffer.

::

    #include <libfdt.h>
    #include <fdt_support.h>
    #include <mmc.h>
    #include <fat.h>
    #include <lcd.h>
    #include <../../../drivers/video/am335x-fb.h>

This example code is based on the AM335x Starter Kit. A GPIO controls
the backlight so use GPIO\_TO\_PIN to define the GPIO.

::

    #define GPIO_ETH1_MODE          GPIO_TO_PIN(1, 26)

    /* GPIO that controls backlight on EVM-SK */
    #define GPIO_BACKLIGHT_EN       GPIO_TO_PIN(3, 17)

In board\_late\_init call the splash screen routine.

::

    #if !defined(CONFIG_SPL_BUILD)
            splash_screen();
            /* try reading mac address from efuse */
            mac_lo = readl(&cdev->macid0l);
            mac_hi = readl(&cdev->macid0h);

The following routines enable the backlight, load the LCD timings (this
example is based on Starter Kit), power on the LCD and enable it, then
finally the splash screen code that registers a fat file system on mmc0.
The gzipped bitmap is named splash.bmp.gz and is displayed with
bmp\_display.

::

    #if defined(CONFIG_LCD) && defined(CONFIG_AM335X_LCD) && \
                    !defined(CONFIG_SPL_BUILD)
    void lcdbacklight(int on)
    {
            gpio_request(GPIO_BACKLIGHT_EN, "backlight_en");
            if (on)
                    gpio_direction_output(GPIO_BACKLIGHT_EN, 0);
            else
                    gpio_direction_output(GPIO_BACKLIGHT_EN, 1);
    }

    int  load_lcdtiming(struct am335x_lcdpanel *panel)
    {
            struct am335x_lcdpanel pnltmp;

            pnltmp.hactive = 480;
            pnltmp.vactive = 272;
            pnltmp.bpp = 16;
            pnltmp.hfp = 8;
            pnltmp.hbp = 43;
            pnltmp.hsw = 4;
            pnltmp.vfp = 4;
            pnltmp.vbp = 12;
            pnltmp.vsw = 10;
            pnltmp.pxl_clk_div = 2;
            pnltmp.pol = 0;
            pnltmp.pup_delay = 1;
            pnltmp.pon_delay = 1;
            panel_info.vl_rot = 0;

            memcpy((void *)panel, (void *)&pnltmp, sizeof(struct am335x_lcdpanel));

            return 0;
    }

    void lcdpower(int on)
    {
            lcd_enable();
    }

    vidinfo_t       panel_info = {
                    .vl_col = 480,
                    .vl_row = 272,
                    .vl_bpix = 4,
                    .priv = 0
    };

    void lcd_ctrl_init(void *lcdbase)
    {
            struct am335x_lcdpanel lcd_panel;

            memset(&lcd_panel, 0, sizeof(struct am335x_lcdpanel));
            if (load_lcdtiming(&lcd_panel) != 0)
                    return;

            lcd_panel.panel_power_ctrl = &lcdpower;

            if (am335xfb_init(&lcd_panel) != 0)
                    printf("ERROR: failed to initialize video!");

            /* Modify panel into to real resolution */
            panel_info.vl_col = lcd_panel.hactive;
            panel_info.vl_row = lcd_panel.vactive;

    //      lcd_set_flush_dcache(1);
    }

    void lcd_enable(void)
    {
            lcdbacklight(1);
    }

    void splash_screen(void)
    {
            struct mmc      *mmc = NULL;
            int             err;

            mmc = find_mmc_device(0);
            if (!mmc)
                    printf("Error finding mmc device\n");

            mmc_init(mmc);

            err = fat_register_device(&mmc->block_dev,
                                            CONFIG_SYS_MMCSD_FS_BOOT_PARTITION);

            if (!err) {
                    err = file_fat_read("splash.bmp.gz", (void *)0x82000000, 0);
                    bmp_display(0x82000000, 0, 0);
            }
    }
    #endif

In mux.c define the LCDC pin mux.

::

    #ifdef CONFIG_AM335X_LCD
    static struct module_pin_mux lcd_pin_mux[] = {
            {OFFSET(lcd_data0), (MODE(0) | PULLUDDIS)},     /* LCD-Data(0) */
            {OFFSET(lcd_data1), (MODE(0) | PULLUDDIS)},     /* LCD-Data(1) */
            {OFFSET(lcd_data2), (MODE(0) | PULLUDDIS)},     /* LCD-Data(2) */
            {OFFSET(lcd_data3), (MODE(0) | PULLUDDIS)},     /* LCD-Data(3) */
            {OFFSET(lcd_data4), (MODE(0) | PULLUDDIS)},     /* LCD-Data(4) */
            {OFFSET(lcd_data5), (MODE(0) | PULLUDDIS)},     /* LCD-Data(5) */
            {OFFSET(lcd_data6), (MODE(0) | PULLUDDIS)},     /* LCD-Data(6) */
            {OFFSET(lcd_data7), (MODE(0) | PULLUDDIS)},     /* LCD-Data(7) */
            {OFFSET(lcd_data8), (MODE(0) | PULLUDDIS)},     /* LCD-Data(8) */
            {OFFSET(lcd_data9), (MODE(0) | PULLUDDIS)},     /* LCD-Data(9) */
            {OFFSET(lcd_data10), (MODE(0) | PULLUDDIS)},    /* LCD-Data(10) */
            {OFFSET(lcd_data11), (MODE(0) | PULLUDDIS)},    /* LCD-Data(11) */
            {OFFSET(lcd_data12), (MODE(0) | PULLUDDIS)},    /* LCD-Data(12) */
            {OFFSET(lcd_data13), (MODE(0) | PULLUDDIS)},    /* LCD-Data(13) */
            {OFFSET(lcd_data14), (MODE(0) | PULLUDDIS)},    /* LCD-Data(14) */
            {OFFSET(lcd_data15), (MODE(0) | PULLUDDIS)},    /* LCD-Data(15) */
            {OFFSET(gpmc_ad8), (MODE(1) | PULLUDDIS)},      /* LCD-Data(16) */
            {OFFSET(gpmc_ad9), (MODE(1) | PULLUDDIS)},      /* LCD-Data(17) */
            {OFFSET(gpmc_ad10), (MODE(1) | PULLUDDIS)},     /* LCD-Data(18) */
            {OFFSET(gpmc_ad11), (MODE(1) | PULLUDDIS)},     /* LCD-Data(19) */
            {OFFSET(gpmc_ad12), (MODE(1) | PULLUDDIS)},     /* LCD-Data(20) */
            {OFFSET(gpmc_ad13), (MODE(1) | PULLUDDIS)},     /* LCD-Data(21) */
            {OFFSET(gpmc_ad14), (MODE(1) | PULLUDDIS)},     /* LCD-Data(22) */
            {OFFSET(gpmc_ad15), (MODE(1) | PULLUDDIS)},     /* LCD-Data(23) */
            {OFFSET(lcd_vsync), (MODE(0) | PULLUDDIS)},     /* LCD-VSync */
            {OFFSET(lcd_hsync), (MODE(0) | PULLUDDIS)},     /* LCD-HSync */
            {OFFSET(lcd_ac_bias_en), (MODE(0) | PULLUDDIS)},/* LCD-DE */
            {OFFSET(lcd_pclk), (MODE(0) | PULLUDDIS)},      /* LCD-CLK */

            /* backlight */
            {OFFSET(mcasp0_ahclkr), (MODE(7) | PULLUDDIS)}, /* mcasp0_gpio */

            {-1},
    };
    #endif

And enable the LCD.

::

            } else if (board_is_evm_sk()) {
                    /* Starter Kit EVM */
                    configure_module_pin_mux(i2c1_pin_mux);
                    configure_module_pin_mux(gpio0_7_pin_mux);
                    configure_module_pin_mux(rgmii1_pin_mux);
                    configure_module_pin_mux(mmc0_pin_mux_sk_evm);
    #ifdef CONFIG_AM335X_LCD
                    configure_module_pin_mux(lcd_pin_mux);
    #endif
            } else if (board_is_bone_lt()) {

| 

| 

| 

