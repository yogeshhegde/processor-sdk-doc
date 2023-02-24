.. include:: /replacevars.rst.inc

.. contents:: Linux Kernel User's Guide

Overview
--------

This document will cover the basic steps for building the Linux kernel.

Getting the Kernel Source Code
------------------------------

The easiest way to get access to the kernel source code is by
downloading and installing the |__SDK_FULL_NAME__|. You can download the
latest |__SDK_FULL_NAME__| installer from |__SDK_DOWNLOAD_URL__|. Once
installed, the kernel source code is included in the SDK's board-support
directory. For your convenience the sources also includes the kernel's
git repository including commit history.
Alternatively, Kernel sources can directly be fetched from GIT.

.. ifconfig:: CONFIG_sdk in ('PLSDK')

    You can find the details about the git repository, branch and commit id in
    the :ref:`release-specific-build-information-kernel` section of the release notes.


Preparing to Build
------------------

It is important that when using the GCC toolchain provided with the SDK
or stand alone from TI that you do **NOT** source the
*environment-setup* file included with the toolchain when building the
kernel. Doing so will cause the compilation of host side components
within the kernel tree to fail.

.. note::
    The following commands are intended to be run from the root of the
    kernel tree unless otherwise specified. The root of the kernel tree is
    the top-level directory and can be identified by looking for the
    "MAINTAINERS" file.

Compiler
^^^^^^^^

Before compiling the kernel or kernel modules the SDK's toolchain needs
to be added to the PATH environment variable

.. only:: _comment

    [comment] The same path applies to both 32 bit and 64 bit processors

::

    export PATH=<sdk path>/linux-devkit/sysroots/x86_64-arago-linux/usr/bin:$PATH

The current compiler supported for this release along with download
location can be found in the release notes for the kernel release.


Cleaning the Kernel Sources
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Prior to compiling the Linux kernel it is often a good idea to make sure
that the kernel sources are clean and that there are no remnants left
over from a previous build.

.. note::
    The next step will delete any saved .config file in the kernel tree as
    well as the generated object files. If you have done a previous
    configuration and do not wish to lose your configuration file you should
    save a copy of the configuration file (.config) before proceeding.

The command to clean the kernel is:

..
  [comment] instructions for 32 bit processors
.. ifconfig:: CONFIG_part_family in ('General_family', 'AM335X_family', 'AM437X_family')

    ::

        make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- distclean

..
  [comment] instructions for 64 bit processors
.. ifconfig:: CONFIG_part_family not in ('General_family', 'AM335X_family', 'AM437X_family')

    ::

        make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- distclean

|

Configuring the Kernel
----------------------

Before compiling the Linux kernel it needs to be configured to select
what components will become part of the kernel image, which components
will be build as dynamic modules, and which components will be left out
all together. This is done using the Linux kernel configuration system.


It is often easiest to start with a base default configuration and then
customize it for your use case if needed. Apply Linux kernel configurations with
a command of the form:

..
  [comment] instructions for 32 bit processors
.. ifconfig:: CONFIG_part_family in ('General_family', 'AM335X_family', 'AM437X_family')

    ::

        make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- <defconfig>

..
  [comment] instructions for 64 bit processors
.. ifconfig:: CONFIG_part_family not in ('General_family', 'AM335X_family', 'AM437X_family')

    ::

        make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- <defconfig>

Using Default Configurations
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

For this sdk, tisdk\_[platformName]\_defconfig was used to create the prebuilt
files. We recommend users to use this kernel configuration (or at least use it
as a starting point).

..
  [comment] instructions for 32 bit processors
.. ifconfig:: CONFIG_part_family in ('General_family', 'AM335X_family', 'AM437X_family')

    platformName is am335x-evm for AM335x, am437x-evm for AM437x, am57xx-evm for
    AM57xx, k2hk-evm for K2H/K2K, k2e-evm for K2E, k2l-evm for K2L, k2g-evm for
    K2G, and omapl138-lcdk for OMAP-L138.

    For example, to apply the default AM335x kernel configuration, use:

    ::

        make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- tisdk_am335x-evm_defconfig

..
  [comment] instructions for 64 bit processors
.. ifconfig:: CONFIG_part_family not in ('General_family', 'AM335X_family', 'AM437X_family')


    platformName is am64xx-evm for AM64x, and am65xx-evm for AM65x.

    For example, to apply the default AM64x kernel configuration, use:

    ::

        am64xx-evm:
        make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- tisdk_am64xx-evm_defconfig

        am64xx-hs-evm:
        make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- tisdk_am64xx-hs-evm_defconfig


After the configuration step has run the full configuration file is
saved to the root of the kernel tree as .config. Any further
configuration changes are based on this file until it is cleaned up by
doing a kernel clean as mentioned above.

If the kernel was downloaded directly from
the git repository, the defconfig will need to be built with scripts.
Please see ti\_config\_fragments/README within the kernel sources for
more information. Otherwise a user will notice a significant amount of
features not working.

Below is the procedure to build the defconfig from the kernel git
repository.

..
  [comment] instructions for 32 bit processors
.. ifconfig:: CONFIG_part_family in ('General_family', 'AM335X_family', 'AM437X_family')

    ::

        ti_config_fragments/defconfig_builder.sh -t ti_sdk_[device]_release
        export ARCH=arm
        make ti_sdk_[device]_release_defconfig
        mv .config arch/arm/configs/tisdk_[platformName]-evm_defconfig

    The list of defconfig map file (i.e., ti\_sdk\_[device]\_release used
    above) supported can be found from
    ti\_config\_fragments/defconfig\_map.txt file.

..
  [comment] instructions for 64 bit processors
.. ifconfig:: CONFIG_part_family not in ('General_family', 'AM335X_family', 'AM437X_family')

    ::

        ti_config_fragments/defconfig_builder.sh -t ti_sdk_arm64_release
        export ARCH=arm64
        make ti_sdk_arm64_release_defconfig
        mv .config arch/arm64/configs/tisdk_[platformName]-evm_defconfig

    The list of defconfig map file (i.e., ti\_sdk\_[device]\_release used
    above) supported can be found from
    ti\_config\_fragments/v8\_defconfig\_map.txt file.


Customizing the Configuration
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

When you want to customize the kernel configuration the easiest way is
to use the built in kernel configuration systems. One popular configuration
system is menuconfig. menuconfig is an ncurses based configuration utility.

To invoke the kernel configuration you simply use a command like:

..
  [comment] instructions for 32 bit processors
.. ifconfig:: CONFIG_part_family in ('General_family', 'AM335X_family', 'AM437X_family')

    ::

        make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- <config type>

    i.e. for menuconfig the command would look like

    ::

        make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- menuconfig

..
  [comment] instructions for 64 bit processors
.. ifconfig:: CONFIG_part_family not in ('General_family', 'AM335X_family', 'AM437X_family')

    ::

        make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- <config type>

    i.e. for menuconfig the command would look like

    ::

        make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- menuconfig

Once the configuration window is open you can then select which kernel
components should be included in the build. Exiting the configuration
will save your selections to a file in the root of the kernel tree
called .config.

| 

Compiling the Sources
---------------------

Compiling the Kernel
^^^^^^^^^^^^^^^^^^^^

..
  [comment] instructions for 32 bit processors
.. ifconfig:: CONFIG_part_family in ('General_family', 'AM335X_family', 'AM437X_family')

    Once the kernel has been configured it must be compiled to generate the
    bootable kernel image as well as any dynamic kernel modules that were
    selected.

    By default U-boot expects zImage to be the type of kernel image used.

    To just build the zImage use this command

    ::

        make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- zImage

    This will result in a kernel image file being created in the
    arch/arm/boot/ directory called zImage.

..
  [comment] instructions for 64 bit processors
.. ifconfig:: CONFIG_part_family not in ('General_family', 'AM335X_family', 'AM437X_family')

    By default U-boot expects to boot kernel `Image`, DTB, and DTOs found in root/boot of the
    SD card if using SD/MMC boot. The exception is for HS-SE (High Security - Security Enforced)
    devices where the FIT image (Flattened Image Tree) named `fitImage` will boot by default.

    The FIT image includes the kernel `Image`, DTB, and DTOs. Booting with the FIT image could be
    enabled/disabled by setting/resetting u-boot environment variable `boot_fit`. If `boot_fit` is set
    to `1`, then u-boot will boot the FIT image found in root/boot of the SD card.

    Once the kernel has been configured it must be compiled to generate the bootable kernel `Image`
    as well as any dynamic kernel modules that were selected. To rebuild kernel `Image` to boot as
    is or for FIT image boot, use this command:

    ::

        make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- Image

    This will result in a kernel image file being created in the
    arch/arm64/boot/ directory called Image.

.. _kernel_users_guide_compiling_the_device_tree_binaries:

Compiling the Device Tree Binaries
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

..
  [comment] instructions for 32 bit processors
.. ifconfig:: CONFIG_part_family in ('General_family', 'AM335X_family', 'AM437X_family')

    Starting with the 3.8 kernel each TI evm has an unique device tree
    binary file required by the kernel. Therefore, you will need to build
    and install the correct dtb for the target device. All device tree files
    are located at arch/arm/boot/dts/. Below list various TI evms and the
    matching device tree file.

    +-------------------------------------------+--------------------------------------+
    | Boards                                    | Device Tree File                     |
    +===========================================+======================================+
    | Beaglebone Black                          | am335x-boneblack.dts                 |
    +-------------------------------------------+--------------------------------------+
    | AM335x General Purpose EVM                | am335x-evm.dts                       |
    +-------------------------------------------+--------------------------------------+
    | AM335x Starter Kit                        | am335x-evmsk.dts                     |
    +-------------------------------------------+--------------------------------------+
    | AM335x Industrial Communications Engine   | am335x-icev2.dts                     |
    +-------------------------------------------+--------------------------------------+
    | AM437x General Purpose EVM                | am437x-gp-evm.dts,                   |
    |                                           | am437x-gp-evm-hdmi.dts (HDMI)        |
    +-------------------------------------------+--------------------------------------+
    | AM437x Starter Kit                        | am437x-sk-evm.dts                    |
    +-------------------------------------------+--------------------------------------+
    | AM437x Industrial Development Kit         | am437x-idk-evm.dts                   |
    +-------------------------------------------+--------------------------------------+
    | AM57xx EVM                                | am57xx-evm.dts,                      |
    |                                           | am57xx-evm-reva3.dts (revA3 EVMs )   |
    +-------------------------------------------+--------------------------------------+
    | AM572x IDK                                | am572x-idk.dts                       |
    +-------------------------------------------+--------------------------------------+
    | AM571x IDK                                | am571x-idk.dts                       |
    +-------------------------------------------+--------------------------------------+
    | AM574x IDK                                | am574x-idk.dts                       |
    +-------------------------------------------+--------------------------------------+
    | K2H/K2K EVM                               | keystone-k2hk-evm.dts                |
    +-------------------------------------------+--------------------------------------+
    | K2E EVM                                   | keystone-k2e-evm.dts                 |
    +-------------------------------------------+--------------------------------------+
    | K2L EVM                                   | keystone-k2l-evm.dts                 |
    +-------------------------------------------+--------------------------------------+
    | K2G EVM                                   | keystone-k2g-evm.dts                 |
    +-------------------------------------------+--------------------------------------+
    | K2G ICE EVM                               | keystone-k2g-ice.dts                 |
    +-------------------------------------------+--------------------------------------+
    | OMAP-L138 LCDK                            | da850-lcdk.dts                       |
    +-------------------------------------------+--------------------------------------+

    To build an individual device tree file find the name of the dts file
    for the board you are using and replace the .dts extension with .dtb.
    Then run the following command:

    ::

        make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- <dt filename>.dtb

    The compiled device tree file with be located in arch/arm/boot/dts.

    For example, the Beaglebone Black device tree file is named
    am335x-boneblack.dts. To build the device tree binary you would run:

    ::

        make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- am335x-boneblack.dtb

    Alternatively, you can build every device tree binary with command

    ::

        make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- dtbs

..
  [comment] instructions for 64 bit processors
.. ifconfig:: CONFIG_part_family not in ('General_family', 'AM335X_family', 'AM437X_family')

    Each TI evm has an unique device tree
    binary file required by the kernel. Therefore, you will need to build
    and install the correct dtb for the target device. TI device tree files
    are located in arch/arm64/boot/dts/ti. Below list various TI evms and the
    matching device tree file.

    +-------------------------------------------+--------------------------------------+
    | Boards                                    | Device Tree File                     |
    +===========================================+======================================+
    | AM62x SK                                  | k3-am625-sk.dts                      |
    +-------------------------------------------+--------------------------------------+
    | AM64x EVM                                 | k3-am642-evm.dts                     |
    +-------------------------------------------+--------------------------------------+
    | AM64x SK                                  | k3-am642-sk.dts                      |
    +-------------------------------------------+--------------------------------------+
    | AM65x EVM / AM65x IDK                     | k3-am654-base-board.dts,             |
    |                                           | daughter cards use .dtso files       |
    +-------------------------------------------+--------------------------------------+
    | J721e EVM                                 | k3-j721e-common-proc-board.dts       |
    +-------------------------------------------+--------------------------------------+
    | J721e SK                                  | k3-j721e-sk.dts                      |
    +-------------------------------------------+--------------------------------------+
    | J7200 EVM                                 | k3-j7200-common-proc-board.dts       |
    +-------------------------------------------+--------------------------------------+

    To build an individual device tree file find the name of the dts file
    for the board you are using and replace the .dts extension with .dtb.
    Then run the following command:

    ::

        make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- ti/<dt filename>.dtb

    The compiled device tree file with be located in arch/arm64/boot/dts/ti.

    For example, the AM64x EVM device tree file is named
    k3-am642-evm.dts. To build the device tree binary you would run:

    ::

        make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- ti/k3-am642-evm.dtb

    Alternatively, you can build every device tree binary with command

    ::

        make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- dtbs

Compiling the Kernel Modules
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

..
  [comment] instructions for 32 bit processors
.. ifconfig:: CONFIG_part_family in ('General_family', 'AM335X_family', 'AM437X_family')

    By default the majority of the Linux drivers used in the sdk are not
    integrated into the kernel image file (zImage). These drivers are built as
    dynamic modules. The command to build these modules is:

    ::

        make ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabihf- modules

..
  [comment] instructions for 64 bit processors
.. ifconfig:: CONFIG_part_family not in ('General_family', 'AM335X_family', 'AM437X_family')

    By default the majority of the Linux drivers used in the sdk are not
    integrated into the kernel image file (Image). These drivers are built as
    dynamic modules. The command to build these modules is:

    ::

        make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- modules


This will result in .ko (kernel object) files being placed in the kernel
tree. These .ko files are the dynamic kernel modules.

.. note::
    If you make a change to the kernel which requires you to recompile
    the kernel, then you should also recompile the kernel modules and
    reinstall the kernel modules. Otherwise your kernel modules may refuse to
    load, which will result in a loss of functionality.

|

.. _fitImage-for-HS:

Creating the kernel fitImage for high security device (using SDK)
-----------------------------------------------------------------

Build kernel image and dtbs as per instructions given above.

Get the Security Dev Tool

  ::

    git clone https://git.ti.com/git/security-development-tools/core-secdev-k3.git -b master
    export TI_SECURE_DEV_PKG=`pwd`/core-secdev-k3

Sign kernel image and copy to <sdk path>/board_support/signed-images

  .. ifconfig:: CONFIG_part_variant not in ('AM64X')

    ::

      mkdir <sdk path>/board_support/signed-images
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh Image Image.sec
      cp -p Image.sec <sdk path>/board-support/signed-images

  .. ifconfig:: CONFIG_part_variant in ('AM64X')

    ::

      mkdir <sdk path>/board_support/signed-images
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh Image linux.bin.sec
      cp -p linux.bin.sec <sdk path>/board-support/linux-5.10*/

Sign devicetree binaries, and copy the signed binaries to <sdk path>/board_support/signed-images.
The binaries to be signed is listed in <sdk path>/board-support/prebuilt-images/fitImage-its.its

  .. ifconfig:: CONFIG_part_variant in ('AM64X')

    ::

      cd <sdk path>/board-support/linux-5.10*/arch/arm64/boot/dts/ti/
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-am642-evm.dtb k3-am642-evm.dtb.sec
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-am642-sk.dtb k3-am642-sk.dtb.sec
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-am642-evm-icssg1-dualemac.dtbo k3-am642-evm-icssg1-dualemac.dtbo.sec
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-am642-evm-icssg1-dualemac-mii.dtbo k3-am642-evm-icssg1-dualemac-mii.dtbo.sec
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-am642-evm-nand.dtbo k3-am642-evm-nand.dtbo.sec

  .. ifconfig:: CONFIG_part_variant in ('AM65X')

    ::

      cd <sdk path>/board-support/linux-5.10*/arch/arm64/boot/dts/ti/
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-am654-base-board.dtb k3-am654-base-board.dtb.sec
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-am654-base-board-sr1.dtbo k3-am654-base-board-sr1.dtbo.sec
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-am654-gp.dtbo k3-am654-gp.dtbo.sec
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-am654-idk.dtbo k3-am654-idk.dtbo.sec
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-am654-idk-sr1.dtbo k3-am654-idk-sr1.dtbo.sec
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-am654-sr1.dtbo k3-am654-sr1.dtbo.sec
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-am654-pcie-usb2.dtbo k3-am654-pcie-usb2.dtbo.sec
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-am654-pcie-usb3.dtbo k3-am654-pcie-usb3.dtbo.sec
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-am654-evm-tc358876.dtbo k3-am654-evm-tc358876.dtbo.sec
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-am654-evm-oldi-lcd1evm.dtbo k3-am654-evm-oldi-lcd1evm.dtbo.sec
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-am654-evm-ov5640.dtbo k3-am654-evm-ov5640.dtbo.sec
      cp -p *.sec <sdk path>/board-support/signed-images

  .. ifconfig:: CONFIG_part_variant in ('J721E')

    ::

      cd <sdk path>/board-support/linux-5.10*/arch/arm64/boot/dts/ti/
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-j721e-common-proc-board.dtb k3-j721e-common-proc-board.dtb.sec
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-j721e-proc-board-tps65917.dtb k3-j721e-proc-board-tps65917.dtb.sec
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-j721e-common-proc-board-infotainment.dtbo k3-j721e-common-proc-board-infotainment.dtbo.sec
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-j721e-sk.dtb k3-j721e-sk.dtb.sec
      cp -p *.sec <sdk path>/board-support/signed-images

  .. ifconfig:: CONFIG_part_variant in ('J7200')

    ::

      cd <sdk path>/board-support/linux-5.10*/arch/arm64/boot/dts/ti/
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-j7200-common-proc-board.dtb k3-j7200-common-proc-board.dtb.sec
      cp -p *.sec <sdk path>/board-support/signed-images

  .. ifconfig:: CONFIG_part_variant in ('J721S2')

    ::

      cd <sdk path>/board-support/linux-5.10*/arch/arm64/boot/dts/ti/
      $TI_SECURE_DEV_PKG/scripts/secure-binary-image.sh k3-j721s2-common-proc-board.dtb k3-j721s2-common-proc-board.dtb.sec
      cp -p *.sec <sdk path>/board-support/signed-images

Generate the FIT image

  .. ifconfig:: CONFIG_part_variant in ('AM64X')

    ::
  
      cp <sdk path>/board-support/prebuilt-images/fitImage-its.its <sdk path>/board-support/linux-5.10*/
      cd <sdk path>/board-support/linux-5.10*/
      mkimage -f fitImage-its.its -r fitImage
      cp -p fitImage <sdk path>/board-support/signed-images
      cd <sdk path>/board-support/signed-images

  .. ifconfig:: CONFIG_part_variant not in ('AM64X')

    ::

      cp <sdk path>/board-support/prebuilt-images/fitImage-its.its <sdk path>/board-support/linux
      cd <sdk path>/board-support/signed-images
      mkimage -f fitImage-its.its -r fitImage

Install the generated FIT image to "rootfs/boot" for MMC/SD card boot as an example

  ::
  
    sudo cp -p fitImage /media/$(USER)/rootfs/boot/fitImage

|

Creating the kernel fitImage for high security device (using Kernel source)
---------------------------------------------------------------------------

SDKs have pre-built FIT images that contain the default kernel and dtb files.
But developers may want to deploy and test new kernel and dtb without going
through the standard build system. Developers can generate the fitImage directly
in the "root/boot" partition of the SD card from the host system. For that, a Makefile
is needed.

Download the Makefile from :download:`here </files/Makefile-for-fitImage>`

Pre-requisites:

  ::

    Have u-boot 'mkimage' tool in your path. This can be done with the following command:
    $ sudo apt install u-boot-tools

    Get the Security Dev Tools as mentioned in the section above.
    $ export TI_SECURE_DEV_PKG=`pwd`/core-secdev-k3

    Add the Makefile to the "root/boot" directory in SD card.

Generating fitImage:

  ::

    Add the new images in the "root/boot" directory of SD card

    Modify the fitImage.its accordingly

    From the host system, go to the "root/boot" directory and run:
    $ make

|

Installing the Kernel
---------------------

Once the Linux kernel, dtb files and modules have been compiled they
must be installed. In the case of the kernel image this can be installed
by copying the kernel image file to the location where it is going to be read
from. The device tree binaries should also be copied to the same
directory that the kernel image was copied to.

Installing the Kernel Image and Device Tree Binaries
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

..
  [comment] instructions for 32 bit processors
.. ifconfig:: CONFIG_part_family in ('General_family', 'AM335X_family', 'AM437X_family')

    ::

        cd <kernel sources dir>
        sudo cp arch/arm/boot/zImage <rootfs path>/boot
        sudo cp arch/arm/boot/dts/<dt file>.dtb <rootfs path>/boot

    For example, if you wanted to copy the kernel image and BeagleBone
    Black device tree file to the rootfs partition of a SD card you would
    enter the below commands:

    ::

         cd <kernel sources dir>
         sudo cp arch/arm/boot/zImage /media/rootfs/boot
         arch/arm/boot/dts/am335x-boneblack.dtb /media/rootfs/boot

..
  [comment] instructions for 64 bit processors
.. ifconfig:: CONFIG_part_family not in ('General_family', 'AM335X_family', 'AM437X_family')

    ::

        cd <kernel sources dir>
        sudo cp arch/arm64/boot/Image <rootfs path>/boot
        sudo cp arch/arm64/boot/dts/ti/<dt file>.dtb <rootfs path>/boot

    For example, if you wanted to copy the kernel image and AM64x EVM
    device tree file to the rootfs partition of a SD card you would
    enter the below commands:

    ::

         cd <kernel sources dir>
         sudo cp arch/arm64/boot/Image /media/rootfs/boot
         sudo cp arch/arm64/boot/dts/ti/k3-am642-evm.dtb /media/rootfs/boot

Starting with U-boot 2013.10, the kernel and device tree binaries are read from
the root file system's boot directory when booting from MMC/EMMC. (NOT from the
/boot/ partition on the MMC). This would mean you copy the kernel image and device
tree binaries to /media/rootfs/boot instead of /media/boot.

Installing the Kernel Modules
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To install the kernel modules you use another make command similar to
the others, but with an additional parameter which give the base
location where the modules should be installed. This command will create
a directory tree from that location like lib/modules/<kernel version>
which will contain the dynamic modules corresponding to this version of
the kernel. The base location should usually be the root of your target
file system. The general format of the command is:

..
  [comment] instructions for 32 bit processors
.. ifconfig:: CONFIG_part_family in ('General_family', 'AM335X_family', 'AM437X_family')

    ::

        sudo make ARCH=arm  INSTALL_MOD_PATH=<path to root of file system> modules_install

    For example if you are installing the modules on the rootfs partition of
    the SD card you would do:

    ::

        sudo make ARCH=arm INSTALL_MOD_PATH=/media/rootfs modules_install

..
  [comment] instructions for 64 bit processors
.. ifconfig:: CONFIG_part_family not in ('General_family', 'AM335X_family', 'AM437X_family')

    ::

        sudo make ARCH=arm64  INSTALL_MOD_PATH=<path to root of file system> modules_install

    For example if you are installing the modules on the rootfs partition of
    the SD card you would do:

    ::

        sudo make ARCH=arm64 INSTALL_MOD_PATH=/media/rootfs modules_install

.. note::

  Append **INSTALL\_MOD\_STRIP=1** to the make modules\_install command to
  reduce the size of the resulting installation
