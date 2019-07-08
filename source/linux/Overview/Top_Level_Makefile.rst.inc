Top-Level Makefile
======================================

.. http://processors.wiki.ti.com/index.php/Processor_Linux_SDK_Top-Level_Makefile
.. rubric:: Overview
   :name: overview

Inside of the Processor Linux SDK there is a top-level Makefile that can
be used to build some of the sub-components found within the SDK. This
Makefile uses the Rules.make file and gives an example of how the
various components can be built and the parameters to use.

**NOTE:** You should not call this makefile with the
`environment-setup
script <Overview_Getting_Started_Guide.html#environment-setup-script>`__
sourced. The sub-component Makefiles will handle sourcing this script
where appropriate, but some make targets such as the Linux kernel make
target do not work properly when this script is already sourced.

.. rubric:: Rules.make
   :name: rules.make

The following sections cover the Rules.make file found in the top-level
of the Processor Linux SDK.

.. rubric:: Purpose
   :name: purpose

The **Rules.make** file in the top-level of the Processor Linux SDK is
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
   of a target file system but can be changed to point anywhere. By
   default the initial value is a unique key value of \_\_DESTDIR\_\_
   which is replaced with the location of the target NFS file system
   when the
   `setup.sh <Overview_Getting_Started_Guide.html#run-setup-scripts>`__ script
   is run.
-  **LINUX\_DEVKIT\_PATH** - This points to the linux-devkit directory.
   This directory is the base directory containing the cross-compiler
   and cross-libraries as well as the
   `environment-setup <Overview_Getting_Started_Guide.html#gcc-toolchain>`__
   script used by many component Makefiles to source additional variable
   settings.
-  **CROSS\_COMPILE** - This setting represents the CROSS\_COMPILE
   prefix to be used when invoking the cross-compiler. Many components
   such as the Linux kernel use the variable CROSS\_COMPILE to prepend
   the proper prefix to commands such as *gcc* to invoke the ARM
   cross-compiler.
-  **ENV\_SETUP** - This points to the
   `environment-setup <Overview_Getting_Started_Guide.html#gcc-toolchain>`__
   script in the linux-devkit directory used by many components to
   configure for a cross-compilation build.
-  **LINUXKERNEL\_INSTALL\_DIR** - This points to the location of the
   Linux kernel sources, which is used by components such as out-of-tree
   kernel drivers to find the Linux kernel Makefiles and headers.

| 

.. rubric:: Makefile
   :name: makefile

The following sections cover the Makefile found in the top-level of the
Processor Linux SDK

.. rubric:: Required Host Packages
   :name: makefile-required-packages

Please run the following command to install all packages required to by the
makefile targets.

::

    host# sudo apt-get install build-essential autoconf automake bison flex libssl-dev bc


.. rubric:: Target Types
   :name: target-types

For each of the targets discussed below the following target type are
defined

-  **<target>** - This is the build target which will compile the
   release version of the component
-  **<target>\_install** - This target will install the component to the
   location pointed to by DESTDIR
-  **<target>\_clean** - This target will clean the component

.. rubric:: Top-Level Targets
   :name: top-level-targets

The Processor Linux SDK provides the following targets by default which
will invoke the corresponding component targets:

-  **all** - This will call the build target for each component defined
   in the Makefile
-  **install** - This will call the install target for each component
   defined in the Makefile
-  **clean** - This will call the clean target for each component
   defined in the Makefile

.. rubric:: Common Targets
   :name: common-targets

The following targets are common to all platforms in Processor Linux
SDK:

-  **linux** - Compiles the Linux kernel using the default
   tisdk\_<PLATFORM>\_defconfig configuration
-  **matrix-gui** - Builds the matrix-gui sources
-  **am-benchmarks** - Builds the ARM Benchmarks for the ARCH defined in
   Rules.make
-  **am-sysinfo** - Build the helper applications used by the system
   settings demos in Matrix
-  **matrix-gui-browser** - Builds the matrix GUI browser Qt project
-  **refresh-screen** - Builds the refresh screen Qt project

| 

.. rubric:: Additional Targets
   :name: additional-targets

Depending on the capabilities and software available for a given device
additional targets may also be defined. You can find the list of all the
targets by looking at the **all** target as described in the
`**Top-Level Targets** <#top-level-targets>`__ section above. Add
devices will have one or the other of the following targets depending on
the u-boot version used:

-  **u-boot-spl** - This target will build both u-boot and the u-boot
   SPL (MLO) binaries used in newer versions of u-boot. This actually
   provides a u-boot and u-boot-spl target in the Makefile.
-  **u-boot-legacy** - This target will build the u-boot binary for
   older versions of u-boot which do not support the SPL build.
-  **wireless** - A wireless top-level build target that can be used to
   rebuild the wireless drivers against the kernel sources in the
   board-support directory.

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

-  Install the Linux kernel modules

::

    host# make linux_install

-  Build the ARM Benchmarks

::

    host# make am-benchmarks

-  Clean the ARM Benchmarks

::

    host# make am-benchmarks_clean

-  Install the ARM Benchmarks

::

    host# make am-benchmarks_install

.. rubric:: A Note about Out-of-tree Kernel Modules
   :name: a-note-about-out-of-tree-kernel-modules

Some drivers like the SGX drivers are delivered as modules outside of
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

