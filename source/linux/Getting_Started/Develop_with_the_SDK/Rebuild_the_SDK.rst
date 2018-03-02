.. http://processors.wiki.ti.com/index.php/Processor_SDK_Building_The_SDK

.. rubric:: Introduction
   :name: introduction

This page provides the steps to build the Processor SDK and individual
components from source. The Processor SDK build is based on the `Arago
Project <http://arago-project.org/wiki/index.php/Main_Page>`__ which
provides a set of layers for `OpenEmbedded <http://openembedded.org/>`__
and the `Yocto Project <http://yoctoproject.org/>`__ targeting TI
platforms.

This page will provide the basic steps require to recreate the Processor
SDK along with a reference of Processor SDK specific configurations,
build targets, and target devices. Also, tips and suggestions are
provided along with links for more in-depth information.

| 

.. rubric:: Quick Start
   :name: quick-start

.. rubric:: Prerequisites (One-time setup)
   :name: prerequisites-one-time-setup

.. rubric:: Host Setup - Ubuntu (Recommended)
   :name: host-setup-ubuntu

The recommended Linux distribution is Ubuntu 14.04 or Ubuntu 16.04.

The following build host packages are required for Ubuntu. The following
command will install the required tools on the Ubuntu Linux
distribution.

For Ubuntu 14.04 and 16.04, please run the following:

::

    $ sudo apt-get install git build-essential python diffstat texinfo gawk chrpath dos2unix wget unzip socat doxygen libc6:i386 libncurses5:i386 libstdc++6:i386 libz1:i386

By default Ubuntu uses "dash" as the default shell for /bin/sh. You must
reconfigure to use bash by running the following command:

::

    sudo dpkg-reconfigure dash

Be sure to select "No" when you are asked to use dash as the default
system shell.

.. rubric:: Host Setup - CentOS (when applicable)
   :name: host-setup-centos

The build also requires that ``bash`` is configured as the default
system shell. The following steps will configure Ubuntu to use ``bash``
instead of the default ``dash``.

::

    $ sudo dpkg-reconfigure dash

    (Select "no" when prompted)

The following host packages are required for CentOS. Install the
packages using the command below:

::

    $ yum install gawk make wget tar bzip2 gzip python unzip perl patch diffutils diffstat git cpp gcc gcc-c++ glibc-devel texinfo chrpath socat SDL-devel xterm doxygen glibc-devel.i686 glibc-devel libstdc++-devel.i686 libgcc.i686 libstdc++-devel dos2unix 

Perl’s Thread::Queue module needs to be installed also. Download and
install perl-Thread-Queue-3.02-2.el7.noarch.rpm from
https://www.rpmfind.net/linux/rpm2html/search.php?query=perl-Thread-Queue.

.. rubric:: Proxy Setup
   :name: proxy-setup

If working behind a proxy, please see `Working Behind a Network
Proxy <https://wiki.yoctoproject.org/wiki/Working_Behind_a_Network_Proxy>`__.


.. rubric:: Cross-compile Toolchain
   :name: cross-compile-toolchain

Run the following commands to install the Linaro Toolchain.

::

    $ wget https://releases.linaro.org/components/toolchain/binaries/6.2-2016.11/arm-linux-gnueabihf/gcc-linaro-6.2.1-2016.11-x86_64_arm-linux-gnueabihf.tar.xz
    $ tar -Jxvf gcc-linaro-6.2.1-2016.11-x86_64_arm-linux-gnueabihf.tar.xz -C $HOME


.. rubric:: Build Steps
   :name: build-steps

::

    $ git clone git://arago-project.org/git/projects/oe-layersetup.git tisdk
    $ cd tisdk
    $ ./oe-layertool-setup.sh -f configs/processor-sdk/processor-sdk-04.02.00.09-config.txt
    $ cd build
    $ . conf/setenv
    $ export PATH=$HOME/gcc-linaro-6.2.1-2016.11-x86_64_arm-linux-gnueabihf/bin:$PATH
    $ MACHINE=am57xx-evm bitbake arago-core-tisdk-image


.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
One common location for hosting packages, gforge.ti.com, has recently
been decommissioned. This will cause fetch failures for the current and
past releases. Please follow this augmented procedure to configure the
build to obtain these packages from the TI mirror.

.. raw:: html

   </div>

::

    $ git clone git://arago-project.org/git/projects/oe-layersetup.git tisdk
    $ cd tisdk
    $ ./oe-layertool-setup.sh -f configs/processor-sdk/processor-sdk-04.02.00.09-config.txt
    $ cd build
    $ cat >> ./conf/local.conf << 'EOF'

    TI_MIRROR = "http://software-dl.ti.com/processor-sdk-mirror/sources/"
    MIRRORS += " \
    bzr://.*/.*      ${TI_MIRROR} \n \
    cvs://.*/.*      ${TI_MIRROR} \n \
    git://.*/.*      ${TI_MIRROR} \n \
    gitsm://.*/.*    ${TI_MIRROR} \n \
    hg://.*/.*       ${TI_MIRROR} \n \
    osc://.*/.*      ${TI_MIRROR} \n \
    p4://.*/.*       ${TI_MIRROR} \n \
    npm://.*/.*      ${TI_MIRROR} \n \
    ftp://.*/.*      ${TI_MIRROR} \n \
    https?$://.*/.*  ${TI_MIRROR} \n \
    svn://.*/.*      ${TI_MIRROR} \n \
    "
    EOF
    $ . conf/setenv
    $ export PATH=$HOME/gcc-linaro-6.2.1-2016.11-x86_64_arm-linux-gnueabihf/bin:$PATH
    $ MACHINE=am57xx-evm bitbake arago-core-tisdk-image


.. rubric:: Processor SDK Build Reference
   :name: processor-sdk-build-reference

The following sections provide information for configuration, build
options, and supported platforms of the Processor SDK.

.. rubric:: Layer Configuration
   :name: layer-configuration

Processor SDK uses the following oe-layersetup configs to configure the
meta layers. These are the <config> used in the command:

``$ ./oe-layersetup.sh -f <config>``

 
The following config files are located in the *configs/processor-sdk*
directory of the oe-layersetup git repo.

+----------------------------------------+---------------------------------+------------------------------------------------------------------------------------------+
|**Config File**                         | **Description**                 | **Supported machines/platforms**                                                         |
+----------------------------------------+---------------------------------+------------------------------------------------------------------------------------------+
| processor-sdk-04.02.00.09-config.txt   | Processor SDK 4.2.0.9 Release   | am335x-evm, am437x-evm, am57xx-evm, k2hk-evm, k2e-evm, k2l-evm, k2g-evm, omapl138-lcdk   |
+----------------------------------------+---------------------------------+------------------------------------------------------------------------------------------+

.. rubric:: Build Options
   :name: build-options

.. rubric:: Images
   :name: images

In addition to individual components packages, the following table
provides a list of build targets supported. These are the <target> used
in the command:

``MACHINE=<machine> bitbake <target>``

The "Build Output" is given relative to the
*arago-tmp-[toolchain]/deploy* directory.

+------------------------------+---------------------------------------------------------------+---------------------+
| **Target**                   | **Build Output**                                              | **Description**     |
+------------------------------+---------------------------------------------------------------+---------------------+
| arago-core-tisdk-image       | images/<machine>/processor-sdk-linux-image-<machine>.tar.xz   | Full SDK            |
+------------------------------+---------------------------------------------------------------+---------------------+
| tisdk-rootfs-image           | images/<machine>/tisdk-rootfs-image-<machine>.tar.xz          | Target Filesystem   |
+------------------------------+---------------------------------------------------------------+---------------------+
| meta-toolchain-arago-tisdk   | sdk/arago-<arago-version>-<architecture>.sh                   | Devkit              |
+------------------------------+---------------------------------------------------------------+---------------------+

| 

.. rubric:: Platforms
   :name: platforms

The following platforms are supported in Processor SDK. These are the
<machine> in the command:

``MACHINE=<machine> bitbake <target>``

| 

+--------------+---------------------------------------------------------------------------------------+
| **MACHINE**  | **Supported EVMs**                                                                    |
+--------------+---------------------------------------------------------------------------------------+
| am335x-evm   | AM335x EVM, AM335x Starter Kit, Beaglebone Black                                      |
+--------------+---------------------------------------------------------------------------------------+
| am437x-evm   | AM437x GP EVM, AM437x Starter Kit                                                     |
+--------------+---------------------------------------------------------------------------------------+
| am57xx-evm   | AM572x GP EVM, AM572x Industrial Development Kit, AM571x Industrial Development Kit   |
+--------------+---------------------------------------------------------------------------------------+
| k2hk-evm     | 66AK2Hx EVM , K2K EVM                                                                 |
+--------------+---------------------------------------------------------------------------------------+
| k2e-evm      | K2Ex EVM                                                                              |
+--------------+---------------------------------------------------------------------------------------+
| k2l-evm      | 66AK2L06 EVM                                                                          |
+--------------+---------------------------------------------------------------------------------------+
| k2g-evm      | K2G EVM                                                                               |
+--------------+---------------------------------------------------------------------------------------+
| omapl138     | OMAP-L138 LCDK                                                                        |
+--------------+---------------------------------------------------------------------------------------+

.. rubric:: RT Support
   :name: rt-support

Processor SDK Linux supports RT Linux Kernel for the following
machines/EVMs. Use the command below to make the RT builds:

``MACHINE=<machine> ARAGO_RT_ENABLE=1 bitbake <target>``

+--------------+---------------------------------------------------------------------------------------+
| **MACHINE**  | **Supported EVMs**                                                                    |
+--------------+---------------------------------------------------------------------------------------+
| am335x-evm   | AM335x EVM, AM335x Industrial Communications Engine                                   |
+--------------+---------------------------------------------------------------------------------------+
| am437x-evm   | AM437x GP EVM, AM437x Industrial Development Kit                                      |
+--------------+---------------------------------------------------------------------------------------+
| am57xx-evm   | AM572x GP EVM, AM574x Industrial Development Kit,                                     |
|              | AM572x Industrial Development Kit, AM571x Industrial Development Kit                  |
+--------------+---------------------------------------------------------------------------------------+
| k2hk-evm     | 66AK2Hx EVM , K2K EVM                                                                 |
+--------------+---------------------------------------------------------------------------------------+
| k2e-evm      | K2Ex EVM                                                                              |
+--------------+---------------------------------------------------------------------------------------+
| k2l-evm      | 66AK2L06 EVM                                                                          |
+--------------+---------------------------------------------------------------------------------------+
| k2g-evm      | K2G EVM                                                                               |
+--------------+---------------------------------------------------------------------------------------+

| 

.. rubric:: Using the snapshot of the source packages in Processor SDK
   release
   :name: using-the-snapshot-of-the-source-packages-in-processor-sdk-release

Using the snapshot of the arago source packages can avoid fetch errors
during the build when external URLs become unavailable. To use the
snapshot of sources distributed with a given Processor SDK release, you
must download a script from the SDK download page and then execute it on
your host to fetch all the packages from TI servers. For example, see
am57xx-evm-linux-sdk-arago-src-04.02.00.09.tar.xz file in
`AM57xx-Linux-SDK-Download-page <http://software-dl.ti.com/processor-sdk-linux/esd/AM57X/04_02_00_09/index_FDS.html>`__.
Once this package is downloaded, there are just a few extra steps in the
build process to fetch all the corresponding packages. The extra steps
are shown in red below:

::

    $ git clone git://arago-project.org/git/projects/oe-layersetup.git tisdk
    $ cd tisdk
    $ ./oe-layertool-setup.sh -f configs/processor-sdk/processor-sdk-04.02.00.09-config.txt
    $ mkdir downloads
    $ cd downloads
    $ # Assuming src file downloaded to $HOME/Downloads
    $ tar xvf $HOME/Downloads/<target-board>-linux-sdk-arago-src-##.##.##.##.tar.xz
    $ <target-board>-linux-sdk-arago-src-##.##.##.##/get_build_sources.sh <target-board>-linux-sdk-arago-src-##.##.##.##/source_pkg_list.txt
    $ cd ..</span>
    $ cd build
    $ . conf/setenv
    $ export PATH=$HOME/gcc-linaro-6.2.1-2016.11-x86_64_arm-linux-gnueabihf/bin:$PATH
    $ MACHINE=<target-board> bitbake arago-core-tisdk-image


.. rubric:: Recipes
   :name: recipes

.. rubric:: Recipe Basics
   :name: recipe-basics

One or more recipes can be specified for the <target> for greater
granularity of recipe development and debug. Specifying a recipe name,
minus the version (if the version is appended to the name), will build
the recipe and all its dependencies.

For example, the command below builds only the opencl recipe and all the
dependencies it defines.

``MACHINE=am57xx-evm bitbake opencl``

After the bitbake command above is successfully done,
*arago-tmp-[toolchain]/work/am57xx\_evm-linux-gnueabi/opencl* directory
will be available including the original source code under the git
folder, independent shared objects (.so files) under packages-split
folder, and IPKs under deploy-ipks folder.

.. note:: Please note that the output of a recipe can be in another folder under "arago-tmp-[toolchain]/work" directory, depending on the defines of the recipe.


.. rubric:: Forced Re-compilation
   :name: forced-re-compilation

When needed, source code under the work directory (e.g.,
*arago-tmp-[toolchain]/work/am57xx\_evm-linux-gnueabi/opencl*/git) can
be modified. After the modification is done, run the following commands
to force recompilation with the new code and rebuilding of the recipe,
e.g.,

``MACHINE=am57xx-evm bitbake opencl --force -c compile``

``MACHINE=am57xx-evm bitbake opencl``

.. rubric:: Installing Package
   :name: installing-package

To install a modified and rebuilt package, copy the new IPKs from the
deploy-ipks folder (e.g.,
*arago-tmp-[toolchain]/work/am57xx\_evm-linux-gnueabi/opencl/[version]/deploy-ipks*)
to the target system and then run the following command to install the
IPKs:

``opkg install [package_ipk].ipk``

.. rubric:: Cleaning a Built Recipe
   :name: cleaning-a-built-recipe

A built recipe can be cleaned using:

``MACHINE=<machine> bitbake <target> -c cleansstate``

The cleansstate task will clean recipe's work directory and remove the
recipe's output from the dependency tree used by other recipe's during
compilation.


.. rubric:: Common Variations
   :name: common-variations

.. rubric:: Rebuilding without SGX
   :name: rebuilding-without-sgx

In Processor SDK delivered today the graphics hardware acceleration is
enabled by default for device families with SGX (e.g. AM335x, AM437x,
AM57xx). As a result, some of the applications with graphics
dependencies will not run properly on device variants in those families
that do not contain the SGX accelerator (e.g. AM3352, AM4372, etc.). The
Processor SDK has been enhanced to provide the same OOB experience with
software rendering provided by QT5/Weston. The non-SGX software
rendering build will be enabled by adding the following to the bottom of
conf/local.conf immediately before invoking bitbake.

``MACHINE_FEATURES_remove="sgx"``

``PACKAGECONFIG_remove="wayland-egl"``

.. rubric:: Rebuilding without Wayland
   :name: rebuilding-without-wayland

If a full Window system is not needed, i.e. if you simply want apps to
run full screen using EGLFS then you can remove Wayland by adding the
following to the bottom of conf/local.conf immediately before invoking
bitbake:

``DISTRO_FEATURES_remove = "wayland"``

.. rubric:: X11 Build instructions
   :name: x11-build-instructions

X11 has been validated as a build option, on top of Processor SDK 4.1 release. 
In order to build with X11 instead of
Wayland, please use the configuration
processor-sdk-04.01.00.06-x11-config.txt for oe-layer-setup. One of the
key differences between this configuration file and the
processor-sdk-04.01.00.06 config file is the branch from
meta-processor-sdk. For X11 build, morty-x11-experimental branch is
used, where the DISTRO\_CONFIG is set to X11 instead of wayland.

.. rubric:: X11 Filesystem
   :name: x11-filesystem

All the X11 related components are provided by the IMG DDK X11 package
and located under /usr/local/XSGX directory instead of /usr/include and
/usr/lib directories. The following applications and demos are built and
verified with X11:

-  SGX unitest programs: xgles1tests, xgles2test1, and etc.
-  PVR SDK 3D demo programs: ChameleonMan, ExampleUI, and etc.
-  QT5 Examples and demo programs over eglfs.x11 including
   matrix-gui-browser

In the X11 build, the xorg (Xserver) is running and owns the DSS
resources by default. To support switching between X11 applications and
non-X11 applications such as DRM modetest and gstreamer pipelines, the
following shell file is provided to stop and start the Xserver.

::

    /etc/init.d/xorg <start|stop>

.. rubric:: See also
   :name: see-also

General information for building TI SDKs using the Arago Project can be
found at `Arago Project: Setting Up The Build
Environment <http://arago-project.org/wiki/index.php/Setting_Up_Build_Environment>`__.
This page contains information on the build host prerequisites, such as
installing the toolchain, and required host packages and configuration,
and the basic steps required to create an SDK completely from source.
Once the Arago Project information is familiar, read the next section
for a reference of layer configurations, build targets, and platforms
supported by the Processor SDK.

-  `Yocto Project <http://yoctoproject.org/>`__
-  `OpenEmbedded <http://openembedded.org/>`__
-  `Arago Project <http://arago-project.org/wiki/index.php/Main_Page>`__

