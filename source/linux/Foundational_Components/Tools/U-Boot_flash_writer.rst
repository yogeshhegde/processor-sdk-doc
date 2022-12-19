.. include:: /replacevars.rst.inc

.. http://processors.wiki.ti.com/index.php/U-Boot_flash_writer

U-Boot Flash Writer
===================

U-Boot Flash Writer is a tool used to flash binaries to the on-chip flash memory. It is included in Processor SDK Linux AM62x package in <PSDK_PATH>/bin directory.  

Requirements on Host PC
-----------------------

1.  The tool is implemented using python and needs python version 3.x on Linux host.
2.  The tool uses additional python packages as listed below.Install this packages before running the script
        * pyserial
        * subprocess
        * regex

Flash Writer Support
---------------------

Flash writer currently supports flash via:

1. USB Device Firmware Upgrade (DFU) to eMMC storage
2. DFU to OSPI 
3. Ethernet to OSPI

How to Use
----------

Flash writer takes 3 arguments

1. Flash mode ( USBDFU, Ethernet )
2. Flash memory (eMMC, OSPI flash )
3. Serial port 

Run u-boot_flashwriter.sh to use the flash writer on Linux host with suitable arguments. All of the examples below assume that you are running commands from the top-level of the SDK. 

  ::

    $ sudo ./bin/u-boot_flashwriter.sh Flash_mode Flash_memory Serial_port

    Ex. if flash mode is USBDFU, memory eMMC and serial port used is /dev/ttyUSB0

    $ sudo ./bin/u-boot_flashwriter.sh usbdfu emmc /dev/ttyUSB0

  .. note::
        Flash writer uses UART to read the logs from the EVM. You need to connect board to host PC via UART irrespective of the flash mode/flash memory and close any program/process which is using the respective the serial port.

Flash via USB Device Firmware Upgrade (DFU)
-------------------------------------------

Flash writer will use DFU to boot the board and then flash the binaries to flash memory via DFU. First of all, you will need to get a copy of the dfu-util program installed on your host.For additional details refer :ref:`usb-device-firmware-upgrade-label`.

  .. rubric:: Steps for DFU boot
   :name: steps-for-dfu-boot

* For DFU boot you need to build the bootloader images using default “am62x_evm_r5_usbdfu_defconfig” and “am62x_evm_a53_defconfig” configs files. By default Flash writer(for DFU boot) takes bootloader binaries from: 

  ::

    <TI_SDK_PATH>/board-support/k3-image-gen*/tiboot3.bin
    <TI_SDK_PATH>/board-support/u-boot_build/a53/tispl.bin
    <TI_SDK_PATH>/board-support/u-boot_build/a53/u-boot.img

For building the bootloader images for DFU Boot, following change is needed in Rules.make file

  ::

    UBOOT_MACHINE_R5=am62x_evm_r5_usbdfu_defconfig
      
Now generate the bootloader images using top-level makefile by running following commands from the top-level of the SDK

  ::

    $ make u-boot
    $ make sysfw-image

To more information how to use top level makefile refer :ref:`top-level-makefile`.

* Set SYSBOOT switches to USB DFU boot mode (Refer to Initialization chapter of AM62 TRM for boot switch details)

* Connect USB Type C DRD Port (J13) on AM62x board to PC through USB cable

* Connect board to PC via UART

* Power on the board

For additional details refer :ref:`usb-device-firmware-upgrade-label`.

Flash to eMMC via DFU
~~~~~~~~~~~~~~~~~~~~~

 .. note::
        eMMC needs to be partitioned before running U-boot flash writer as a reset is required for the partition table to be visible. For steps refer :ref:`partitioning-eMMC-from-uboot`. 

To flash bootloader binaries and filesystem to eMMC storage via USB-DFU, run following command in linux host

  ::

    $ sudo ./bin/u-boot_flashwriter.sh usbdfu emmc Serial_port

    Ex. if serial port is /dev/ttyUSB0

    $ sudo ./bin/u-boot_flashwriter.sh usbdfu emmc /dev/ttyUSB0

For details on how to boot using eMMC refer :ref:`boot-linux-from-mmc`.

Flash to OSPI via DFU
~~~~~~~~~~~~~~~~~~~~~

To flash bootloader binaries to OSPI via USB-DFU, run following command in linux host

  ::

    $ sudo ./bin/u-boot_flashwriter.sh usbdfu ospi Serial_port
        
    Ex. if serial port is /dev/ttyUSB0

    $ sudo ./bin/u-boot_flashwriter.sh usbdfu ospi /dev/ttyUSB0

To boot via OPSI, change boot mode pins (Refer to Initialization chapter of AM62 TRM for boot switch details)        

Flash via Ethernet
------------------

Flash writer will use DFU to boot the board then flash the files to on-chip memory over TFTP. Flash writer invokes setup-tftp.sh in ``<Path to sdk>/bin`` to set up TFTP directory in ``/tftpboot`` in host pc and then copies the binaries to TFTP directory for flashing to EVM.

* Follow the same steps for DFU boot in `**Steps for DFU boot** <#steps-for-dfu-boot>`__ .

* In addition, connect Ethernet Cable to board. For details refer :ref:`booting-over-ethernet`.

Flash to OSPI via Ethernet
~~~~~~~~~~~~~~~~~~~~~~~~~~

To flash bootloader binaries to OSPI via ethernet, run following command in linux host

  ::

    $ sudo ./bin/u-boot_flashwriter.sh ethernet ospi Serial_port
        
    Ex. if serial port is /dev/ttyUSB0

    $ sudo ./bin/u-boot_flashwriter.sh ethernet ospi /dev/ttyUSB0

To boot via OPSI, change boot mode pins (Refer to Initialization chapter of AM62 TRM for boot switch details).
