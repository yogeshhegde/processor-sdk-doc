.. http://processors.wiki.ti.com/index.php/Sitara_Linux_AM335x_Flash_Programming_Linux_Development
.. rubric:: Introduction
   :name: introduction-linux-am335x-flash-programming

This document describes how to develop a flash imager for the Sitara
AM335x/AM437x SoCs and how to prepare an image to be flashed. This
information is focused on the Linux developer that is creating these
images. The images, once created and tested, can be used to program
Flash memory (NAND, NOR, SPI, QSPI or eMMC) attached to an AM335x/AM437x
SoC on a target board. The flasher application and image to be flashed
are transferred to what is expected to be a blank board (the flash has
not been programmed before) via Ethernet or USB (using the Remote NDIS
networking protocol). The flasher application and image can be hosted on
either Linux or Windows. For Linux, we use standard tools that most
developers are already familiar with for development, and this setup is
further documented
`here </index.php/Ubuntu_12.04_Set_Up_to_Network_Boot_an_AM335x_Based_Platform>`__.
For Windows, we use `CCS UniFlash </index.php/Category:CCS_UniFlash>`__.
For more information on using CCS UniFlash with Sitara Devices, please
see the `Sitara Uniflash Quick Start
Guide </index.php/Sitara_Uniflash_Quick_Start_Guide>`__.

The overall process of programming the flash is broken into two parts:

#. Developing the images to both be programmed and do the programming
   from the AM335x/AM437x SoC. This is usually done by the Linux
   developer responsible for creating the images. This process varies
   somewhat depending on the desires of the Linux developer. There are 2
   options defined below:

   #. Using U-Boot as the primary source of the flasher image. This
      works well for NAND, NOR, and (Q)SPI. It is the simplest process
      to use. Learn more about it
      `here </index.php/Sitara_Uniflash_Flash_Programming_with_U-Boot>`__
   #. Using a Linux kernel and minimal filesystem. This is recommended
      for eMMC, but may have advantages in other situations as it makes
      the full power of Linux available to the flasher program. This is
      a bit more complex and may require a bit more porting. This
      process is documented
      `here </index.php/Sitara_Uniflash_Flash_Programming_with_Linux>`__.

#. Actually programming the images using Uniflash v3. This tool runs on
   a Windows PC and serves the images to the target board that is being
   programmed. This process is detailed in the `Sitara Uniflash Quick
   Start Guide </index.php/Sitara_Uniflash_Quick_Start_Guide>`__.

