.. include:: /replacevars.rst.inc

.. _top-level-makefile:

Top-Level Makefile
======================================

.. http://processors.wiki.ti.com/index.php/Processor_Linux_SDK_Top-Level_Makefile
.. rubric:: Overview
   :name: top-level-makefile-overview

Inside of the |__SDK_FULL_NAME__| package, there is a top-level Makefile that can
be used to build some of the sub-components found within the SDK. This
Makefile uses the Rules.make file and gives an example of how the
various components can be built and the parameters to use.

**NOTE:** You should not call this makefile with the
`environment-setup
script <GCC_ToolChain.html#environment-setup-script>`__
sourced. The sub-component Makefiles will handle sourcing this script
where appropriate, but some make targets such as the Linux kernel make
target do not work properly when this script is already sourced.

.. rubric:: Rules.make
   :name: rules.make

The following sections cover the Rules.make file found in the top-level
of the |__SDK_FULL_NAME__| package.

.. rubric:: Purpose
   :name: top-level-makefile-purpose

The **Rules.make** file in the top-level of the |__SDK_FULL_NAME__| package is
used not only by the top-level Makefile, but also by many of the
sub-component Makefiles to gain access to common shared variables and
settings. The next section covers the main variables defined in the
Rules.make file.

.. rubric:: Variables Defined
   :name: variables-defined

-  **PLATFORM** - This represents the machine name of the device
   supported by the SDK. This machine name has a direct correlation to
   the machine definition in the `Arago
   project <http://arago-project.org>`__ build system. The PLATFORM
   variable can be used by component Makefiles to make decisions on a
   per-machine basis.
-  **ARCH** - This represents the architecture family of the machine.
   This can be used by component Makefiles to change settings such as
   mtune values in CFLAGS based on the architecture of the PLATFORM.
-  **UBOOT\_MACHINE** - This us used when building u-boot to configure
   the u-boot sources for the correct device.
-  **TI\_SDK\_PATH** - This points to the top-level of the SDK. This is
   the same directory where the Rules.make file itself is located.
-  **DESTDIR** - This points to the base installation directory that
   applications/drivers should be installed to. This is usually the root
   of a target file system but can be changed to point anywhere.
-  **LINUX\_DEVKIT\_PATH** - This points to the linux-devkit directory.
   This directory is the base directory containing the cross-compiler
   and cross-libraries as well as the
   `environment-setup <GCC_ToolChain.html#environment-setup-script>`__
   script used by many component Makefiles to source additional variable
   settings.
-  **CROSS\_COMPILE** - This setting represents the CROSS\_COMPILE
   prefix to be used when invoking the cross-compiler. Many components
   such as the Linux kernel use the variable CROSS\_COMPILE to prepend
   the proper prefix to commands such as *gcc* to invoke the ARM
   cross-compiler.
-  **ENV\_SETUP** - This points to the
   `environment-setup <GCC_ToolChain.html#environment-setup-script>`__
   script in the linux-devkit directory used by many components to
   configure for a cross-compilation build.
-  **LINUXKERNEL\_INSTALL\_DIR** - This points to the location of the
   Linux kernel sources, which is used by components such as out-of-tree
   kernel drivers to find the Linux kernel Makefiles and headers.

| 

.. rubric:: Makefile
   :name: makefile

The following sections cover the Makefile found in the top-level of the
|__SDK_FULL_NAME__| package.

.. rubric:: Required Host Packages
   :name: makefile-required-packages

Please run the following command to install all packages required to by the
makefile targets.

::

    host# sudo apt-get install build-essential autoconf automake bison flex libssl-dev bc u-boot-tools swig


.. ifconfig:: CONFIG_sdk in ('PSDKL')

    .. rubric:: Compiler toolchain
       :name: compiler-toolchain

    On the download page, you will find links to the recommended compiler toolchains.
    Download and extract them into your home directory. Note that you have to download
    both the toolchains for ARMv8 and ARMv7. Make sure to update your PATH to
    include the path to toolchain.

    ::

        GCC92PATH=$HOME/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu/bin:$HOME/gcc-arm-9.2-2019.12-x86_64-arm-none-linux-gnueabihf/bin
        export PATH=$GCC92PATH:$PATH

.. rubric:: Target Types
   :name: target-types

For each of the targets discussed below the following target type are
defined

-  **<target>** - This is the build target which will compile the
   release version of the component.
-  **<target>\_install** - This target will install the component to the
   location pointed to by DESTDIR.
-  **<target>\_clean** - This target will clean the component.

.. rubric:: Top-Level Targets
   :name: top-level-targets

The |__SDK_FULL_NAME__| package provides the following targets by default, which
will invoke the corresponding component targets:

-  **all** - This will call the build target for each component defined
   in the Makefile.
-  **install** - This will call the install target for each component
   defined in the Makefile.
-  **clean** - This will call the clean target for each component
   defined in the Makefile.

.. rubric:: Common Targets
   :name: common-targets

The following targets are common to all platforms in |__SDK_FULL_NAME__|
package:

-  **linux** - Compiles the Linux kernel using the default
   tisdk\_<PLATFORM>\_defconfig configuration.
-  **linux-dtbs** - Compiles and creates the device tree blobs.
-  **am-benchmarks** - Builds the ARM Benchmarks for the ARCH defined in
   Rules.make.
-  **am-sysinfo** - Build the helper applications used by the system
   settings demos in Matrix.

| 

.. rubric:: Additional Targets
   :name: additional-targets

Depending on the capabilities and software available for a given device
additional targets may also be defined. You can find the list of all the
targets by looking at the **all** target as described in the
`**Top-Level Targets** <#top-level-targets>`__ section above. Some
devices will have following additional targets:

.. ifconfig:: CONFIG_sdk in ('PSDKL')

  -  **sysfw-image** - Builds the system firmware itb file, which is a single
     binary for the system firmware release along with the different board
     configs.
  -  **jailhouse** - Builds the required kernel module, hypervisor firmware,
     jailhouse tools and cell configs. Applicable for only platforms with
     Hypervisor support enabled.

.. ifconfig:: CONFIG_sdk not in ('PSDKL')

  -  **u-boot** - This target will build both u-boot and the u-boot
     SPL (MLO) binaries used in newer versions of u-boot. This actually
     provides a u-boot and u-boot-spl target in the Makefile.
  -  **u-boot-legacy** - This target will build the u-boot binary for
     older versions of u-boot which do not support the SPL build.
  -  **wireless** - A wireless top-level build target that can be used to
     rebuild the wireless drivers against the kernel sources in the
     board-support directory.
  -  **matrix-gui** - Builds the matrix-gui sources.
  -  **matrix-gui-browser** - Builds the matrix GUI browser Qt project.
  -  **refresh-screen** - Builds the refresh screen Qt project.
  -  **sysfw-image** - Builds the system firmware itb file, which is a single
     binary for the system firmware release along with the different board
     configs.
  -  **linux-fitimage** - Sign and pack linux kernel and dtbs into FIT image
     required for booting HS devices.
  -  **jailhouse** - Builds the required kernel module, hypervisor firmware,
     jailhouse tools and cell configs. Applicable for only platforms with
     Hypervisor support enabled.

Along with these targets, there might be additional targets for different
external kernel modules. This list is different for each platform.

| 



.. rubric:: Usage Examples
   :name: usage-examples

The following examples demonstrate how to use the top-level Makefile for
some common tasks. All of the examples below assume that you are calling
the Makefile from the top-level of the SDK.

-  Build Everything

::

    host# make

-  Clean Everything

::

    host# make clean

-  Install Everything

::

    host# make install

-  Build the Linux kernel

::

    host# make linux

.. ifconfig:: CONFIG_part_variant in ('AM62X')

::

    Build GPU Kernel Modules
    host# make ti-img-rogue-driver_am62

-  Install the Linux kernel modules

::

    host# make linux_install

    To install in SD card directly:
    host# sudo DESTDIR=/media/$USER/rootfs make linux_install

.. ifconfig:: CONFIG_part_variant in ('AM62X')

::

    Install GPU Kernel Modules
    host# make ti-img-rogue-driver_am62_install

    To install in SD card directly:
    host# sudo DESTDIR=/media/$USER/rootfs make ti-img-rogue-driver_am62_install

-  Build the ARM Benchmarks

::

    host# make am-benchmarks

-  Clean the ARM Benchmarks

::

    host# make am-benchmarks_clean

-  Install the ARM Benchmarks

::

    host# make am-benchmarks_install


.. ifconfig:: CONFIG_sdk in ('PSDKL')

  .. ifconfig:: CONFIG_part_variant in ('AM65X')

    -  By default, this builds the sysfw for AM65xx PG1.0.  To build sysfw for AM65xx PG2.0,
       modify the SYSFW_SOC_am65xx-evm variable in the Makefile to equal am65x_sr2 and build.

  -  Build the sysfw.

  .. ifconfig:: CONFIG_part_variant in ('AM65X')

    -  By default, this builds the sysfw for AM65xx PG1.0.  To build sysfw for AM65xx PG2.0,
       modify the SYSFW_SOC_am65xx-evm variable in the Makefile to equal am65x_sr2 and build.

  ::

      host# make sysfw-image

  -  Clean the sysfw

  ::

      host# make sysfw-image_clean

  -  Install the sysfw

  ::

      host# make sysfw-image_install

-  Build u-boot

::

    host# make u-boot-spl

-  Clean u-boot

::

    host# make u-boot-spl_clean

.. ifconfig:: CONFIG_part_variant in ('AM64X', 'AM62X')

  -  Build the combined boot image -  This requires first building the R5 boot image.
     This will generate the u-boot-spl.bin. Then build sysfw-image to generate combined
     boot image at <TI_SDK_PATH>/board-support/k3-image-gen*/tiboot3.bin

::

    host# make u-boot
    host# make sysfw-image

If TI_SECURE_DEV_PKG environment variable is not defined, tiboot3.bin can still be built for GP devices. The following errors will occur in K3-Image-Gen build logs when building for HS-FS or HS-SE devices without the TI_SECURE_DEV_PKG environment variable defined and K3-Image-Gen build may fail:

::

    TI_SECURE_DEV_PKG must be set for HS, defaults will not work.  Stop.

To fix the above issue, do the following and rebuild the `sysfw-image`.

::

    host# git clone https://git.ti.com/git/security-development-tools/core-secdev-k3.git -b master
    host# export TI_SECURE_DEV_PKG=`pwd`/core-secdev-k3

.. ifconfig:: CONFIG_part_variant in ('AM64X')

  .. note:: To build `tiboot3.bin` for AM64x GP, update `PLATFORM_TYPE_am64xx-evm` and `SYSFW_SOC_am64xx-evm` in the top level Makefile as below:

    ::

        PLATFORM_TYPE_am64xx-evm = gp
        SYSFW_SOC_am64xx-evm = am64x

.. ifconfig:: CONFIG_sdk in ('PSDKL')

  .. ifconfig:: CONFIG_part_variant in ('J7200')

      -  Build the combined boot image.  This requires first building the R5 boot image.
         This will generate the u-boot-spl.bin.  This file must be copied to the k3-image-gen* folder.
         The tiboot3.bin can then be built from the k3-image-gen* folder.

    ::

        host# make u-boot-r5
        host# cp board-support/u-boot_build/r5/spl/u-boot-spl.bin board-support/k3-image-gen*/.
        host# cd board-support/k3-image-gen*/
        host# make SOC=j7200 ROM_COMBINED_IMAGE=1 SBL=u-boot-spl.bin

.. rubric:: Installing to SD card rootfs
   :name: installing-to-sd-card

All the install targets copy the files in the rootfs pointed by the DESTDIR variable.
By default, Rules.make points the DESTDIR to the NFS path for filesystem.
If you want to install the files to the SD card, you should be able to specify
different path to DESTDIR on commandline. e.g. run following for installing
everything in the SD card rootfs.

::

    host# sudo DESTDIR=/media/$USER/rootfs make install
    #Replace the path to SD card rootfs partition as appropriate

.. rubric:: Installing boot binaries
   :name: installing-boot-binaries

All the install targets copy the files in the rootfs pointed by the DESTDIR variable.
*make install* command only copies the files in rootfs. If you have built either of
system firmware or u-boot, you should copy these binaries in the boot partition of
the SD card. e.g. run following to copy boot binaries in SD card boot partition.


.. ifconfig:: CONFIG_part_variant in ('AM65X')

    ::

        host# sudo cp board-support/u-boot_build/a53/u-boot.img board-support/u-boot_build/a53/tispl.bin board-support/u-boot_build/r5/tiboot3.bin /media/$USER/boot
        #Replace the path to SD card boot partition as appropriate

        # For AM65xx-EVM PG1.0, copy the following sysfw file
        host# cp board-support/k3-image-gen*/sysfw-am65x-evm.itb /media/$USER/boot/sysfw.itb
        #Replace the path to SD card boot partition as appropriate

        # For AM65xx-EVM PG2.0, copy the following sysfw file
        host# cp board-support/k3-image-gen*/sysfw-am65x_sr2-evm.itb /media/$USER/boot/sysfw.itb
        #Replace the path to SD card boot partition as appropriate

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    ::

        host# sudo cp board-support/u-boot_build/a53/u-boot.img board-support/u-boot_build/a53/tispl.bin board-support/u-boot_build/r5/tiboot3.bin /media/$USER/boot

.. ifconfig:: CONFIG_part_variant not in ('AM65X','AM64X', 'AM62X')

    ::

        host# sudo cp board-support/u-boot_build/a72/u-boot.img board-support/u-boot_build/a72/tispl.bin board-support/u-boot_build/r5/tiboot3.bin /media/$USER/boot

.. ifconfig:: CONFIG_part_variant in ('AM64X')

    ::

        #Replace the path to SD card boot partition as appropriate
        host# sudo cp board-support/u-boot_build/a53/u-boot.img /media/$USER/boot/u-boot.img
        host# sudo cp board-support/u-boot_build/a53/tispl.bin /media/$USER/boot/tispl.bin
        host# sudo cp board-support/k3-image-gen-2022.01/tiboot3.bin /media/$USER/boot/tiboot3.bin

        NOTE: For AM64x HS EVM, please follow below steps instead:
        #Replace the path to SD card boot partition as appropriate
        host# sudo cp board-support/u-boot_build/a53/u-boot.img_HS /media/$USER/boot/u-boot.img
        host# sudo cp board-support/u-boot_build/a53/tispl.bin_HS /media/$USER/boot/tispl.bin
        host# sudo cp board-support/k3-image-gen-2022.01/tiboot3.bin /media/$USER/boot/tiboot3.bin

.. rubric:: A Note about Out-of-tree Kernel Modules
   :name: a-note-about-out-of-tree-kernel-modules

Some drivers like the GPU drivers are delivered as modules outside of
the kernel tree. If you rebuild the kernel and install it using the
"make linux\_install" target you will also need to rebuild the out of
tree modules and install them as well. The modules\_install command used
by the linux\_install target will remove any existing drivers before
installing the new ones. This means those drivers are no longer
available until they have been rebuilt against the kernel and
re-installed.

.. rubric:: A Note about the Linux Kernel Version
   :name: a-note-about-the-linux-kernel-version

To simplify and accelerate rebuilding and installing the linux kernel,
the file *.scmversion* is included in the kernel source tree to pin down
the version of the kernel provided in the SDK. If upgrading the kernel
sources or adding new commits, this file should be removed so that the
appropriate version is built into the kernel image.

