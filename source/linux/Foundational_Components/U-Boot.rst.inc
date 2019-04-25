.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_U-Boot

*******************************
U-Boot
*******************************
.. include:: Foundational_Components/U-Boot/Linux_Core_U-Boot_Users_Guide.rst.inc


U-Boot Release Notes
======================

Build Information
-------------------
Please refer to `U-Boot Build Information <Release_Specific_Release_Notes.html#u-boot>`__ for details.

Known Issues
--------------
Please refer to `U-Boot Known Issues <Release_Specific_Release_Notes.html#u-boot-known-issues>`__ for details.


.. include:: Foundational_Components/U-Boot/Processor_SDK_Linux_U-Boot_Splash_Screen.rst.inc


Troubleshooting
================

1. After U-boot upgrade, Kernel stops booting

Check if one of the cases below applies:

- Not resetting U-boot environment variables after upgrading/downgrading u-boot version

  From release to release, some of the u-boot environment variables may be changed.
  To guarantee the environment variables are correctly matching the version used,
  it is required to reset the u-boot environment variables When upgrading/downgrading u-boot version.
  When booting up a different version of u-boot, the u-boot boot process can be
  interruptted by hitting any key to get the u-boot prompt. Then, the following command needs
  to issue to reset the u-boot environment variables.
   
    |   # env default -f -a
    |   # saveenv

- Mix-matching U-boot and Linux kernel version

  There are times that users mix-match u-boot and kernel version from different SDK releases.
  It probably is fine in most cases, but TI recommends the u-boot and kernel are from the same SDK release.
  From release to release, the u-boot environemt variables may change, including load addresses,
  kernel image format, etc. Any of the incompatibility of these changes between u-boot and kernel
  will cause boot issues. Therefore, when u-boot is upgraded or downgreaded,
  a reset of the u-boot environment variables is requried.
  Please see how to reset u-boot environment variables in previous bullet.

2. Not able to boot U-boot with different boot mode

- Check if the instruction for supported u-boot boot modes is followed.

| For Sitara family devices (AM3/4/5), please follow instructions in `U-boot User's Guide 
    <Foundational_Components_U-Boot.html#u-boot-user-s-guide>`__ 
|
| Keystone-2 platforms support the following boot modes:

  - SPI NOR boot
  - EMIF NAND boot
  - UART boot
  - MMC boot (only on K2G)

| Different boot modes ues diferent image formats. They are:

  - u-boot-spi.gph
  - rootfs-image.ubi
  - u-boot.bin
  - MLO

  For Keystone-2 platforms, U-boot can also be brought up using CCS. The step-by-step instruction on booting up u-boot
  with one of the boot modes or using CCS are documented in <Processor_SDK_install_dir>/board-support/u-boot-<ver>/board/ti/ks2_evm/README file.
