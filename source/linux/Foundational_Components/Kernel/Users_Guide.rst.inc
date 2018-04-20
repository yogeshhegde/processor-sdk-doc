.. http://processors.wiki.ti.com/index.php/Linux_Kernel_Users_Guide
.. rubric:: Overview
   :name: overview-linux-kernel-ug

This wiki will cover the basic steps for building the Linux kernel.

.. rubric:: Getting the Kernel Source Code
   :name: getting-the-kernel-source-code

| The easiest way to get access to the kernel source code is by
  downloading and installing the Processor SDK Linux. Once installed,
  the kernel source code is included in the SDK's board-support
  directory. For your convenience the sources also includes the kernel's
  git repository including commit history.
| Alternatively, Kernel sources can directly be fetched from GIT. You
  can find the details about the git repository, branch and commit id in
  the
  `Processor\_SDK\_Linux\_Release\_Notes <Release_Specific.html#kernel>`__

| 

| 

.. rubric:: Preparing to Build
   :name: preparing-to-build

It is important that when using the GCC toolchain provided with the SDK
or stand alone from TI that you do **NOT** source the
*environment-setup* file included with the toolchain when building the
kernel. Doing so will cause the compilation of host side components
within the kernel tree to fail.

The following commands are intended to be run from the root of the
kernel tree unless otherwise specified. The root of the kernel tree is
the top-level directory and can be identified by looking for the
"MAINTAINERS" file.

.. rubric:: Compiler
   :name: compiler

Before compiling the kernel or kernel modules the SDK's toolchain needs
to be added to the PATH environment variable

``export PATH=<sdk path>/linux-devkit/sysroots/x86_64-arago-linux/usr/bin:$PATH``

The current compiler supported for this release along with download
location can be found in the release notes for the kernel release.

.. rubric:: Cleaning the Kernel Sources
   :name: cleaning-the-kernel-sources

Prior to compiling the Linux kernel it is often a good idea to make sure
that the kernel sources are clean and that there are no remnants left
over from a previous build.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
The next step will delete any saved .config file in the kernel tree as
well as the generated object files. If you have done a previous
configuration and do not wish to lose your configuration file you should
save a copy of the configuration file (.config) before proceeding.

.. raw:: html

   </div>

The command to clean the kernel is:

::

    make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- distclean

.. rubric:: Configuring the Kernel
   :name: configuring-the-kernel

Before compiling the Linux kernel it needs to be configured to select
what components will become part of the kernel image, which components
will be build as dynamic modules, and which components will be left out
all together. This is done using the Linux kernel configuration system.

.. rubric:: Using Default Configurations
   :name: using-default-configurations

It is often easiest to start with a base default configuration and then
customize it for you use case if needed. In the Linux kernel a command
of the form:

::

    make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- <defconfig>

.. rubric:: SDK Kernel Configuration
   :name: sdk-kernel-configuration

For this sdk the singlecore-omap2plus\_defconfig was used and is the one
we recommend all users to use or at least use as a starting point.
example:

::

    make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- tisdk_amNNNx-evm_defconfig

After the configuration step has run the full configuration file is
saved to the root of the kernel tree as .config. Any further
configuration changes are based on this file until it is cleanup up by
doing a kernel clean as mentioned above.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
Previous SDKs recommended users use omap2plus\_defconfig as their
<defconfig>. For this release tisdk\_[platformName]\_defconfig should be
used instead, which has included the platform name (e,g., am335x-evm for
AM335x, am437x-evm for AM437x, am57xx-evm for AM57xx, k2hk-evm for
K2H/K2K, k2e-evm for K2E, k2l-evm for K2L, k2g-evm for K2G, and
omapl138-lcdk for OMAP-L138). If the kernel was downloaded directly from
the git repository, the defconfig will need to be built with scripts.
Please see ti\_config\_fragments/README within the kernel sources for
more information. Otherwise a user will notice a significant amount of
features not working.

.. raw:: html

   </div>

Below is the procedure to build the defconfig from the kernel git
repository.

::

    $ ti_config_fragments/defconfig_builder.sh -t ti_sdk_[device]_release
    $ export ARCH=arm 
    $ make ti_sdk_[device]_release_defconfig
    $ mv .config arch/arm/configs/tisdk_[platformName]-evm_defconfig

The list of defconfig map file (i.e., ti\_sdk\_[device]\_release used
above) supported can be found from
ti\_config\_fragments/defconfig\_map.txt file.

.. rubric:: Customizing the Configuration
   :name: customizing-the-configuration

When you want to customize the kernel configuration the easiest way is
to use the built in kernel configuration systems. Two of the most
popular configuration systems are:

menuconfig: an ncurses based configuration utility

**NOTE:** on some systems in order to use xconfig you may need to
install the libqt3-mt-dev package. For example on Ubuntu 10.04 this can
be done using the command *sudo apt-get install libqt3-mt-dev*

To invoke the kernel configuration you simply use a command like:

::

    make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- <config type>

i.e. for menuconfig the command would look like

::

    make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- menuconfig

Once the configuration window is open you can then select which kernel
components should be included in the build. Exiting the configuration
will save your selections to a file in the root of the kernel tree
called .config.

| 

| 

.. rubric:: Compiling the Sources
   :name: compiling-the-sources

.. rubric:: Compiling the Kernel
   :name: compiling-the-kernel

Once the kernel has been configured it must be compiled to generate the
bootable kernel image as well as any dynamic kernel modules that were
selected.

By default U-boot expects zImage to be the type of kernel image used.

To just build the zImage use this command

::

    make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- zImage

This will result in a kernel image file being created in the
arch/arm/boot/ directory called zImage.

.. rubric:: Compiling the Device Tree Binaries
   :name: compiling-the-device-tree-binaries

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

Table:  Device Tree File Name Per Board

To build an individual device tree file find the name of the dts file
for the board you are using and replace the .dts extension with .dtb.
Then run the following command:

::

    make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- <dt filename>.dtb

The compiled device tree file with be located in arch/arm/boot/dts.

For example, the Beaglebone Black device tree file is named
am335x-boneblack.dts. To build the device tree binary you would run:

::

    make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- am335x-boneblack.dtb

| 

| 

.. rubric:: Compiling the Kernel Modules
   :name: compiling-the-kernel-modules

By default the majority of the Linux drivers used in the sdk are not
integrated into the kernel image (ex zImage). These drivers are built as
dynamic modules. The command to build these modules is:

::

    make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- modules

This will result in .ko (kernel object) files being placed in the kernel
tree. These .ko files are the dynamic kernel modules.

When ever you make a change to the kernel its generally recommended that
you rebuild your kernel modules and reinstall the kernel modules.
Otherwise the kernel modules may not load or run. The next section will
cover how to install these modules.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
Any time you make a change to the kernel which requires you to recompile
it you should also insure that you recompile the kernel modules and
reinstall them. Otherwise all your kernel modules may refuse to load
which will result in a significant loss of functionality.

.. raw:: html

   </div>

.. rubric:: Installing the Kernel
   :name: installing-the-kernel

Once the Linux kernel, dtb files and modules have been compiled they
must be installed. In the case of the kernel image this can be installed
by copying the zImage file to the location where it is going to be read
from. The device tree binaries should also be copied to the same
directory that the kernel image was copied to.

.. rubric:: Installing the Kernel Image and Device Tree Binaries
   :name: installing-the-kernel-image-and-device-tree-binaries

| `` cd <kernel sources dir> sudo cp arch/arm/boot/zImage <rootfs path>/boot sudo cp arch/arm/boot/dts/<dt file>.dtb <rootfs path>/boot``
| For example, if you wanted to copy the kernel image and BeagleBone
  Black device tree file to the rootfs partition of a SD card you would
  enter the below commands:
  ``  cd <kernel sources dir> sudo cp arch/arm/boot/zImage arch/arm/boot/dts/am335x-boneblack.dtb /media/rootfs/boot``
| Starting with U-boot 2013.10, the kernel and device tree binaries by
  default are no longer being read from the /boot/ partition on the MMC
  but from the root file system's boot directory when booting from
  MMC/EMMC. This would mean you would copy the kernel image and device
  tree binaries to /media/rootfs/boot instead of /media/boot.

.. rubric:: Installing the Kernel Modules
   :name: installing-the-kernel-modules

To install the kernel modules you use another make command similar to
the others, but with an additional parameter which give the base
location where the modules should be installed. This command will create
a directory tree from that location like lib/modules/<kernel version>
which will contain the dynamic modules corresponding to this version of
the kernel. The base location should usually be the root of your target
file system. The general format of the command is:

::

    sudo make ARCH=arm  INSTALL_MOD_PATH=<path to root of file system> modules_install

For example if you are installing the modules on the rootfs partition of
the SD card you would do:

::

    sudo make ARCH=arm INSTALL_MOD_PATH=/media/rootfs modules_install

.. note::

  Append **INSTALL\_MOD\_STRIP=1** to the make modules\_install command to
  reduce the size of the resulting installation
