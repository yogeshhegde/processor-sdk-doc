.. include:: /_replacevars.rst

.. http://processors.wiki.ti.com/index.php/Flash_via_DFU

Flash via USB Device Firmware Upgrade (DFU)
===========================================

Flash writer script will use DFU to boot the board and then flash the binaries to 
flash memory. It also supports flashing to multiple devices one by one.

Important files
---------------

u-boot_flashwriter.sh script for flashing via DFU is located at

::

    <TI_SDK_PATH>/bin/DFU_flash/u-boot_flashwriter.sh

The text files for setting up environment variables in U-Boot for DFU flash are 
located at

.. ifconfig:: CONFIG_part_variant in ('AM62X')
    
    ::

        <TI_SDK_PATH>/bin/DFU_flash/am62xx-evm/

.. ifconfig:: CONFIG_part_variant in ('AM64X')

    ::
    
        <TI_SDK_PATH>/bin/DFU_flash/am64xx-evm/

.. ifconfig:: CONFIG_part_variant in ('AM62AX')

    ::

        <TI_SDK_PATH>/bin/DFU_flash/am62axx-evm/  

Requirements on host PC
-----------------------

dfu-util program needs to installed on your Linux host.

Building bootloader binaries for flashing and DFU boot
------------------------------------------------------

Override the bootcmd command to receive the environment variable text file after 
DFU boot. Following change needs to be done

::                                                                          

    CONFIG_BOOTCOMMAND="setenv dfu_alt_info_flashenv uEnv.txt ram 0x82000000 0x10000000; setenv dfu_alt_info ${dfu_alt_info_flashenv}; dfu 0 ram 0; env import -t ${loadaddr} $filesize; run user_commands;"

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    Add above line to am62x_evm_a53_defconfig file

.. ifconfig:: CONFIG_part_variant in ('AM64X')

    Update CONFIG_BOOTCOMMAND in am64x_evm_a53_defconfig file as above

.. ifconfig:: CONFIG_part_variant in ('AM62AX')

    Update CONFIG_BOOTCOMMAND in am62ax_evm_a53_defconfig file as above

It will enable script to send uEnv.txt file, import the environment variables and run *user_commands* after DFU boot.

Next build the bootloader binaries for DFU boot. For details refer :ref:`usb-device-firmware-upgrade-label`.

Export path to files
--------------------

Assign the path of bootloader binaries for flashing and DFU boot to variables as 
shown below and export them. Not defining these variables or providing wrong path 
will throw an error.

::

    export DFU_BOOT_TIBOOT=<path to tiboot3.bin for flashing & DFU boot>
    export DFU_BOOT_TISPL=<path to tispl.bin for flashing & DFU boot>
    export DFU_BOOT_UBOOT=<path to u-boot.img for flashing & DFU boot>

Assign the path of environment variable text file which contains to below variable 
and export. Not defining this variable or providing wrong path will throw an error. 

::

    export UENV_TXT=<path to environment variable txt file for setting environment for flashing>

Assign the path of the files you want to flash in the given variables and export 
them. Its not mandatory to assign all the below variables with a path. Script will 
skip flashing files for which corresponding variable is undefined.

::
    
    export FLASH_TIBOOT=<path to tiboot3.bin to be flashed>
    export FLASH_TISPL=<path to tispl.bin to be flashed>
    export FLASH_UBOOT=<path to u-boot.img to be flashed>
    export FLASH_ENV=<path to uenv.txt to be flashed>
    export FLASH_ROOTFS=<path to rootfs to be flashed>

Getting ready to flash
----------------------

Make sure dfu-util is installed in the host pc.

Make sure to build bootloader binaries for flashing and DFU boot and assign their 
path to the variables and export.

Make sure to export path to your environment variable txt file.

For connection refer :ref:`usb-device-firmware-upgrade-label`.

Environment variable text file for flashing
-------------------------------------------

It will be used to set environment variables in U-Boot for flashing.

It assigns a set of U-Boot commands to variable *user_commands*. Ex. for DFU 
transfer to eMMC following commands are assigned to variable user_commands.

::

    user_commands=echo Flashing_on_eMMC; setenv dfu_alt_info ${dfu_alt_info_emmc}; dfu 0 mmc 0;

The user_commands variable defined in the text file contains the commands to 
setup environment variables in U-Boot for DFU transfer.

Flashing the files                                                        
------------------

Script takes 2 arguments - Flash memory and Device
 
Run u-boot_flashwriter.sh to use the flash writer on Linux host with suitable 
arguments. All of the examples below assume that you are running commands from 
the top-level of the SDK.

::

    $ sudo ./bin/DFU_flash/u-boot_flashwriter.sh Flash_memory Device
 
**Flash to eMMC**

eMMC needs to be partitioned before running the script. For steps 
refer :ref:`partitioning-eMMC-from-uboot`.

Use uEnv_dfu_emmc.txt as environment variable file for flashing.

After exporting paths to binaries and files, run following command in linux host

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    ::

        $ sudo ./bin/DFU_flash/u-boot_flashwriter.sh emmc am62x

.. ifconfig:: CONFIG_part_variant in ('AM64X')

    ::

        $ sudo ./bin/DFU_flash/u-boot_flashwriter.sh emmc am64x

.. ifconfig:: CONFIG_part_variant in ('AM62AX')

    ::

        $ sudo ./bin/DFU_flash/u-boot_flashwriter.sh emmc am62ax

**Flash to SD card**

SD card needs to be partitioned before running U-boot flash writer.

Use uEnv_dfu_sdcard.txt as environment variable text file for flashing.

After exporting paths to binaries and files, run following command in linux host.

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    ::
        
        $ sudo ./bin/DFU_flash/u-boot_flashwriter.sh sdcard am62x

.. ifconfig:: CONFIG_part_variant in ('AM64X')                                  
                                                                                
    ::
    
        $ sudo ./bin/DFU_flash/u-boot_flashwriter.sh sdcard am64x

.. ifconfig:: CONFIG_part_variant in ('AM62AX')                                 
                                                                         
    ::
  
        $ sudo ./bin/DFU_flash/u-boot_flashwriter.sh sdcard am62ax

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    **Flash to OSPI NOR** 
    
    Use uEnv_dfu_ospi-nor.txt as environment variable file for flashing.

    After exporting paths to binaries and files, run following command in linux host
    
    ::

        $ sudo ./bin/DFU_flash/u-boot_flashwriter.sh ospi-nor am62x        
    
.. ifconfig:: CONFIG_part_variant in ('AM64X')

    **Flash to OSPI NOR**                                             

    Use uEnv_dfu_ospi-nor.txt as environment variable file for flashing.        
    
    After exporting paths to binaries and files, run following command in linux host

    ::
        
        $ sudo ./bin/DFU_flash/u-boot_flashwriter.sh ospi-nor am64x

.. ifconfig:: CONFIG_part_variant in ('AM62AX')

    **Flash to OSPI NAND**                    

    Use uEnv_dfu_ospi-nand.txt as environment variable file for flashing.

    After exporting paths to binaries and files, run following command in linux 
    host                       
    
    ::                                                                          
        
        $ sudo ./bin/DFU_flash/u-boot_flashwriter.sh ospi-nand am62ax 


Flashing multiple devices via USB Device Firmware Upgrade (DFU)
---------------------------------------------------------------

The script supports flashing multiple EVMs via DFU one by one. 
   
It will check for existing DFU device(s), flash the files, detach the existing 
device(s) and wait for new device(s). 

If a new device is connected to host pc for flashing, it will detect and flash 
to that device .Script can be exited by pressing Ctrl C.
