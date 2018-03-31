.. rubric:: Overview
   :name: overview-1

| This page provides an overview about the Secondary Bootloader support
  provided in Processor SDK RTOS.

| The Secondary Bootloader (SBL) sets-up the PLL clocks, powers on the
  I/O Peripherals, initializes the DDR, loads the application image into
  DDR & brings the slave cores for applicable SOCs out of reset.
  Additional details including execution boot flow is covered in more
  elaborate detail under individual SOC section.

.. rubric:: Boot Modes
   :name: boot-modes

.. rubric:: MMCSD
   :name: mmcsd

MMCSD bootloader is required to boot target using an SD card containing
bootloader and application images. When the board is powered ON the ROM
bootloader detects the MMCSD bootloader image and loads it to the
internal memory.The bootloader initializes the board, copies the
application image from SD card to the DDR memory and gives control to
the application.

.. rubric:: QSPI
   :name: qspi

A flash device interfaced with QSPI is flashed with QSPI bootloader and
application images. When the board is powered ON the ROM bootloader
detects the bootloader image from flash device and loads it to the
internal memory. The Bootloader initializes the board, copies the
application image from QSPI device to the DDR memory and gives control
to the application.

.. rubric:: UART
   :name: uart

A Serial connection is used for transferring the bootloader binary from
PC to target board through XMODEM protocol. The bootloader on execution
prompts for application image to transfer through XMODEM. On providing
the path, the application binary is transferred through serial
connection to DDR memory and the control is passed to application to
execute.

.. rubric:: MCSPI/SPI
   :name: mcspispi

A SPI flash device flashed with MCSPI/SPI bootloader and application
images is used for booting the board. When the board is powered ON the
ROM bootloader detects the bootloader image from flash device and loads
it to the internal memory. The Bootloader initializes the board, copies
the application image from flash to the DDR memory and gives control to
the application.

.. rubric:: NAND
   :name: nand

NAND flash with bootloader and and application images is used for
booting the board. When the board is powered ON the ROM bootloader
detects the bootloader image from flash device and loads it to the
internal memory. The bootloader initializes the board, copies the
application image from flash to the DDR memory and gives control to the
application.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
For information on boot mode setting, see the applicable `EVM Hardware
User
Guide </index.php/Processor_SDK_Supported_Platforms_and_Versions>`__.

.. raw:: html

   </div>

AM335x/AM437x
==============
.. include:: PDK_Platform_Software/Boot_Board_and_EVM_Abstractions/BOOT_AM335x_AM437x.rst


AM57x
==============
.. include:: PDK_Platform_Software/Boot_Board_and_EVM_Abstractions/BOOT_AM57x.rst


C66x
==============
.. include:: PDK_Platform_Software/Boot_Board_and_EVM_Abstractions/BOOT_C66x.rst


K2G
==============
.. include:: PDK_Platform_Software/Boot_Board_and_EVM_Abstractions/BOOT_K2G.rst


K2H/K2E/K2L
==============
.. include:: PDK_Platform_Software/Boot_Board_and_EVM_Abstractions/BOOT_K2H_E_L.rst


OMAPL137/OMAPL138/C6748
========================
.. include:: PDK_Platform_Software/Boot_Board_and_EVM_Abstractions/BOOT_OMAPL13x.rst


Bootloader Debugging
========================
.. include:: PDK_Platform_Software/Boot_Board_and_EVM_Abstractions/Boot_Debug.rst


.. raw:: html