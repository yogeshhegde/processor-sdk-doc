.. include:: /replacevars.rst.inc

.. http://processors.wiki.ti.com/index.php/Flash_via_Ethernet

Flash via Ethernet
==================

Ethernet is used for peripheral boot and then to flash the files to on-chip memory 
using DHCP server and TFTP.

Important files
---------------

Environment variable text files are located at

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    ::

        <TI_SDK_PATH>/bin/Ethernet_flash/am62xx-evm/

.. ifconfig:: CONFIG_part_variant in ('AM64X')

    ::

        <TI_SDK_PATH>/bin/Ethernet_flash/am64xx-evm/

Requirements on host PC
-----------------------

Set up Ethernet boot. For details of Ethernet boot refer :ref:`booting-over-ethernet`.

Building bootloader binaries for flashing and Ethernet Boot
-----------------------------------------------------------

First you need to override the bootcmd command to send the environment variable 
text file.

::

    CONFIG_BOOTCOMMAND="dhcp <name of your uEnv.txt file>; env import -t ${loadaddr} $filesize; run user_commands;"

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    Add above line to am62x_evm_a53_defconfig file

.. ifconfig:: CONFIG_part_variant in ('AM64X')

    Update CONFIG_BOOTCOMMAND in am64x_evm_a53_defconfig file as above

    It will enable sending uEnv.txt after Ethernet boot, import the environment 
    variable and run *user_commands* after Ethernet boot.

    Next build the bootloader binaries for Ethernet boot. For details refer :ref:`booting-over-ethernet`.

Getting ready to flash
----------------------

Make sure that the bootloader binaries for flashing and Ethernet boot is built for 
the EVM and place them in the TFTP directory.

Place the files to be flashed to TFTP directory.

Make sure to set up Ethernet boot.

For connection refer :ref:`booting-over-ethernet`.

Environment variable text file for flashing
-------------------------------------------

It will be used to set environment variables in U-Boot for flashing. Create a new 
uEnv.txt file by using existing uEnv files as reference

It assigns U-Boot commands to run the list of commands specified by user to variable 
*user_commands*. Ex. for transfer to eMMC following commands are assigned to variable 
user_commands.

::

    user_commands=echo Flashing_on_emmc; run command_list;

To add new U-Boot commands, assign them to a variable in text file. For example

::

    example_command1=echo Flash
    example_command2=mmc list

Now add the variables to *command_list* to run them. By this way you can add or remove 
commands as per your choice.

::

    command_list=run example_command1; run example_command2;

Also make sure to replace file names in text files with the actual names of files
to be flashed. Ex. to transfer tiboot3.bin over TFTP to EVM

::

	#Enter your filename in place of tiboot3.bin
	cmd_3=dhcp tiboot3.bin

**Flash to eMMC**

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    Use uEnv_ethernet_emmc_am62xx-evm.txt file as reference.

.. ifconfig:: CONFIG_part_variant in ('AM64X')

	Use uEnv_ethernet_emmc_am64xx-evm.txt file as reference.

.. ifconfig:: CONFIG_part_variant in ('AM64X','AM62X')

**Flash to OSPI NOR**

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    Use uEnv_ethernet_ospi-nor_am62xx-evm.txt file as reference.

.. ifconfig:: CONFIG_part_variant in ('AM64X')

    Use uEnv_ethernet_ospi-nor_am64xx-evm.txt file as reference.

    **Flash to GPMC NAND**

    Use uEnv_ethernet_gpmc-nand_am64xx-evm.txt file as reference.
