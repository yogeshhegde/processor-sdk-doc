.. include:: /replacevars.rst.inc

************************************
Building the SDK
************************************

Introduction
============
This page provides the steps to build the Processor SDK and individual
components from source. The Processor SDK build is based on the `Arago
Project <https://git.yoctoproject.org/meta-arago>`__ which
provides a set of layers for `OpenEmbedded <http://openembedded.org/>`__
and the `Yocto Project <http://yoctoproject.org/>`__ targeting TI
platforms.

This page will provide the basic steps required to recreate the Processor
SDK along with a reference of Processor SDK specific configurations,
build targets, and target devices. Also, tips and suggestions are
provided along with links for more in-depth information.

Quick Start
===========

Prerequisites (One-time setup)
------------------------------

.. rubric:: Host Setup - Ubuntu (Recommended)
   :name: Host Setup - ubuntu (Recommended)

.. ifconfig:: CONFIG_sdk in ('PLSDK', 'PSDKL')

    The recommended Linux distribution is Ubuntu 18.04.

The following build host packages are required for Ubuntu. The following
command will install the required tools on the Ubuntu Linux
distribution.

.. ifconfig:: CONFIG_sdk in ('PLSDK', 'PSDKL')

    For Ubuntu 18.04, please run the following:

::

    $ sudo apt-get install build-essential autoconf \
          automake bison \ 
          flex libssl-dev bc u-boot-tools \
          python diffstat \
          texinfo gawk chrpath dos2unix \
          wget unzip socat doxygen libc6:i386 \
          libncurses5:i386 libstdc++6:i386 \
          libz1:i386 g++-multilib \
          git python3-distutils python3-apt 

By default Ubuntu uses "dash" as the default shell for /bin/sh. You must
reconfigure to use bash by running the following command:

::

    sudo dpkg-reconfigure dash

Be sure to select "No" when you are asked to use dash as the default
system shell.

.. rubric:: Large Swap File

Building large packages, especially several at a time, requires a lot of 
working memory for a computer. For computers with 32 GB or RAM or more, this 
should not be a problem. For computers with less RAM, a swap file of ~16GB may 
be needed to build large packages. Creating a large swap file, or resizing a 
small swap file to be larger will help avoid build errors for large packages.

.. rubric:: Proxy Setup
   :name: Proxy Setup

If working behind a proxy, please see `Working Behind a Network
Proxy <https://wiki.yoctoproject.org/wiki/Working_Behind_a_Network_Proxy>`__.

.. rubric:: Cross-Compile Toolchain
   :name: Cross-Compile Toolchain

.. ifconfig:: CONFIG_sdk in ('PLSDK')

    .. ifconfig:: CONFIG_part_variant in ('AM62X')

        Run the following commands to install the ARM Toolchains. 64-bit products like AM62x need both. 32-bit products
        like AM335x and AM437x only need the 32-bit toolchain (arm-none-linux-).
    
    .. ifconfig:: CONFIG_part_variant in ('AM64X')
    
        Run the following commands to install the ARM Toolchains. 64-bit products like AM64x need both. 32-bit products
        like AM335x and AM437x only need the 32-bit toolchain (arm-none-linux-).

    ::

        $ wget https://developer.arm.com/-/media/Files/downloads/gnu-a/9.2-2019.12/binrel/gcc-arm-9.2-2019.12-x86_64-arm-none-linux-gnueabihf.tar.xz
        $ tar -Jxvf gcc-arm-9.2-2019.12-x86_64-arm-none-linux-gnueabihf.tar.xz -C $HOME
        $ wget https://developer.arm.com/-/media/Files/downloads/gnu-a/9.2-2019.12/binrel/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu.tar.xz
        $ tar -Jxvf gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu.tar.xz -C $HOME

.. ifconfig:: CONFIG_sdk in ('PSDKL')

    Download the toolchain compilers from the links provided in the SDK release page.
    Keep the extracted toolchains in the $HOME directory of host Linux machine.
    Use $HOME directory as the PATH_TO_TOOLCHAIN in following command.

    .. Note::
        For building all SDK components, you need two compilers.
        ARMv8 for software running on A72
        ARMv7 for software running on R5F
        Make sure to download both of these toolchains before starting yocto build.

Build Steps
-----------

Please refer to :ref:`here <yocto-layer-configuration>` for the
layer configuration for a particular release of Processor SDK Linux.
See `Build Options`_ for a list of additional targets.  The MACHINE can be set to
|__SDK_BUILD_MACHINE__|, for example.

.. ifconfig:: CONFIG_sdk in ('PLSDK')

    The final command below will build the **tisdk-base-image**, which is the
    minimal Processor SDK filesystem.  See `Build Options`_ for a list of
    additional targets.

    ::

        $ git clone https://git.ti.com/git/arago-project/oe-layersetup.git tisdk
        $ cd tisdk
        $ ./oe-layertool-setup.sh -f configs/processor-sdk/processor-sdk-<version>-config.txt
        $ cd build
        $ . conf/setenv
        $ export TOOLCHAIN_PATH_ARMV7=$HOME/gcc-arm-9.2-2019.12-x86_64-arm-none-linux-gnueabihf
        $ export TOOLCHAIN_PATH_ARMV8=$HOME/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu
        $ MACHINE=<machine> bitbake -k tisdk-base-image

.. ifconfig:: CONFIG_sdk in ('PSDKL')

    ::

        cd yocto-build
        ./oe-layertool-setup.sh -f configs/processor-sdk-linux/processor-sdk-linux-<version>.txt
        cd build
        echo "INHERIT += \"own-mirrors\"" >> conf/local.conf
        echo "SOURCE_MIRROR_URL = \"http://software-dl.ti.com/processor-sdk-mirror/sources/\"" >> conf/local.conf
        echo "ARAGO_BRAND  = \"psdkla\"" >> conf/local.conf
        echo "DISTRO_FEATURES_append = \" virtualization\"" >> conf/local.conf
        echo "IMAGE_INSTALL_append = \" docker\"">> conf/local.conf
        . conf/setenv
        TOOLCHAIN_BASE=<PATH_TO_TOOLCHAIN> MACHINE=<machine> bitbake -k tisdk-default-image

.. ifconfig:: CONFIG_part_family not in ('General_family', 'AM335X_family', 'AM437X_family')

    .. rubric:: Building for a HS platform

    To build for an HS platform, bitbake needs to know the location of the secdev utilities.
    Obtain it with the following:

      ::

        $ git clone https://git.ti.com/git/security-development-tools/core-secdev-k3.git -b master
        $ export TI_SECURE_DEV_PKG=`pwd`/core-secdev-k3

    Then let bitbake know the location by adding TI_SECURE_DEV_PKG_K3=$TI_SECURE_DEV_PKG to the
    list of environment variables before the bitbake command.

Processor SDK Build Reference
=============================

The following sections provide information for configuration, build
options, and supported platforms of the Processor SDK.

Layer Configuration
-------------------
Please refer to :ref:`here <yocto-layer-configuration>` for the layer configuration for a particular release of Processor SDK Linux.

Build Options
-------------

.. rubric:: Images
   :name: Images

In addition to individual components packages, the following table
provides a list of build targets supported. These are the <target> used
in the command:

``MACHINE=<machine> bitbake <target>``

The "Build Output" is given relative to the
**arago-tmp-[toolchain]/deploy** directory.


.. ifconfig:: CONFIG_sdk in ('PLSDK')

    +------------------------------+---------------------------------------------------------------+----------------------------+
    | Target                       | Build Output                                                  | Description                |
    +==============================+===============================================================+============================+
    | tisdk-core-bundle            | images/<machine>/processor-sdk-linux-bundle-<machine>.tar.xz  | Full SDK                   |
    +------------------------------+---------------------------------------------------------------+----------------------------+
    | tisdk-default-image          | images/<machine>/tisdk-default-image-<machine>.tar.xz         | Target Filesystem          |
    +------------------------------+---------------------------------------------------------------+----------------------------+
    | tisdk-base-image             | images/<machine>/tisdk-base-image-<machine>.tar.xz            | Minimal Target Filesytem   |
    +------------------------------+---------------------------------------------------------------+----------------------------+
    | meta-toolchain-arago-tisdk   | sdk/arago-<arago-version>-<architecture>.sh                   | Devkit                     |
    +------------------------------+---------------------------------------------------------------+----------------------------+

.. ifconfig:: CONFIG_sdk in ('PSDKL')

    +------------------------------+---------------------------------------------------------------+----------------------------+
    | Target                       | Build Output                                                  | Description                |
    +==============================+===============================================================+============================+
    | arago-core-psdkla-bundle     | images/<machine>/processor-sdk-linux-image-<machine>.tar.xz   | Full SDK                   |
    +------------------------------+---------------------------------------------------------------+----------------------------+
    | tisdk-default-image          | images/<machine>/tisdk-default-image-<machine>.tar.xz         | Target Filesystem          |
    +------------------------------+---------------------------------------------------------------+----------------------------+

|

.. ifconfig:: CONFIG_sdk in ('PLSDK')

    .. rubric:: Platforms
       :name: Platforms

    The following platforms are supported in Processor SDK. These are the
    <machine> in the command:

    ``MACHINE=<machine> bitbake <target>``

    .. ifconfig:: CONFIG_part_variant in ('AM335X')

        +---------------+---------------------------------------------------------------------------------------+
        | **MACHINE**   | **Supported EVMs**                                                                    |
        +---------------+---------------------------------------------------------------------------------------+
        | am335x-evm    | AM335x EVM, AM335x Starter Kit, Beaglebone Black                                      |
        +---------------+---------------------------------------------------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('AM437X')

        +---------------+---------------------------------------------------------------------------------------+
        | **MACHINE**   | **Supported EVMs**                                                                    |
        +---------------+---------------------------------------------------------------------------------------+
        | am437x-evm    | AM437x GP EVM, AM437x Starter Kit                                                     |
        +---------------+---------------------------------------------------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('AM57X')

        +---------------+---------------------------------------------------------------------------------------+
        | **MACHINE**   | **Supported EVMs**                                                                    |
        +---------------+---------------------------------------------------------------------------------------+
        | am57xx-evm    | AM572x GP EVM, AM572x Industrial Development Kit, AM571x Industrial Development Kit   |
        +---------------+---------------------------------------------------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('AM64X')

        +---------------+---------------------------------------------------------------------------------------+
        | **MACHINE**   | **Supported EVMs**                                                                    |
        +---------------+---------------------------------------------------------------------------------------+
        | am64xx-evm    | AM64x GP EVM, AM64x Starter Kit (SK)                                                  |
        +---------------+---------------------------------------------------------------------------------------+
        | am64xx-hs-evm | AM64x HS EVM                                                                          |
        +---------------+---------------------------------------------------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('AM62X')

        +---------------+---------------------------------------------------------------------------------------+
        | **MACHINE**   | **Supported EVMs**                                                                    |
        +---------------+---------------------------------------------------------------------------------------+
        | am62xx-evm    | AM62x Starter Kit (SK)                                                                |
        +---------------+---------------------------------------------------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('AM65X')

        +---------------+---------------------------------------------------------------------------------------+
        | **MACHINE**   | **Supported EVMs**                                                                    |
        +---------------+---------------------------------------------------------------------------------------+
        | am65xx-evm    | AM65x Evaluation Module, AM65x Industrial Development Kit, DRA80xM Evaluation Module  |
        +---------------+---------------------------------------------------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('Gen')

        +---------------+---------------------------------------------------------------------------------------+
        | **MACHINE**   | **Supported EVMs**                                                                    |
        +---------------+---------------------------------------------------------------------------------------+
        | k2hk-evm      | 66AK2Hx EVM , K2K EVM                                                                 |
        +---------------+---------------------------------------------------------------------------------------+
        | k2e-evm       | K2Ex EVM                                                                              |
        +---------------+---------------------------------------------------------------------------------------+
        | k2l-evm       | 66AK2L06 EVM                                                                          |
        +---------------+---------------------------------------------------------------------------------------+
        | k2g-evm       | K2G EVM                                                                               |
        +---------------+---------------------------------------------------------------------------------------+
        | omapl138-lcdk | OMAP-L138 LCDK                                                                        |
        +---------------+---------------------------------------------------------------------------------------+

    .. rubric:: RT Support
       :name: RT Support

    Processor SDK Linux supports RT Linux Kernel for the following
    machines/EVMs. Use the command below to make the RT builds:

    ``MACHINE=<machine> ARAGO_RT_ENABLE=1 bitbake <target>``

    .. ifconfig:: CONFIG_part_variant in ('AM335X')

        +--------------+---------------------------------------------------------------------------------------+
        | **MACHINE**  | **Supported EVMs**                                                                    |
        +--------------+---------------------------------------------------------------------------------------+
        | am335x-evm   | AM335x EVM, AM335x Industrial Communications Engine                                   |
        +--------------+---------------------------------------------------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('AM437X')

        +---------------+--------------------------------------------------------------------------------------+
        | **MACHINE**   | **Supported EVMs**                                                                   |
        +---------------+--------------------------------------------------------------------------------------+
        | am437x-evm   | AM437x GP EVM, AM437x Industrial Development Kit                                      |
        +--------------+---------------------------------------------------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('AM57X')

        +---------------+--------------------------------------------------------------------------------------+
        | **MACHINE**   | **Supported EVMs**                                                                   |
        +---------------+--------------------------------------------------------------------------------------+
        | am57xx-evm   | AM572x GP EVM, AM574x Industrial Development Kit,                                     |
        |              | AM572x Industrial Development Kit, AM571x Industrial Development Kit                  |
        +--------------+---------------------------------------------------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('AM64X')

        +---------------+--------------------------------------------------------------------------------------+
        | **MACHINE**   | **Supported EVMs**                                                                   |
        +---------------+--------------------------------------------------------------------------------------+
        | am64xx-evm   | AM64x GP EVM, AM64x Starter Kit (SK)                                                  |
        +--------------+---------------------------------------------------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('AM62X')

        +---------------+--------------------------------------------------------------------------------------+
        | **MACHINE**   | **Supported EVMs**                                                                   |
        +---------------+--------------------------------------------------------------------------------------+
        | am62xx-evm    | AM62x Starter Kit (SK)                                                               |
        +---------------+--------------------------------------------------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('AM65X')

        +---------------+--------------------------------------------------------------------------------------+
        | **MACHINE**   | **Supported EVMs**                                                                   |
        +---------------+--------------------------------------------------------------------------------------+
        | am65xx-evm   | AM65x Evaluation Module, AM65x Industrial Development Kit, DRA80xM Evaluation Module  |
        +--------------+---------------------------------------------------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('Gen')

        +---------------+--------------------------------------------------------------------------------------+
        | **MACHINE**   | **Supported EVMs**                                                                   |
        +---------------+--------------------------------------------------------------------------------------+
        | k2hk-evm     | 66AK2Hx EVM , K2K EVM                                                                 |
        +--------------+---------------------------------------------------------------------------------------+
        | k2e-evm      | K2Ex EVM                                                                              |
        +--------------+---------------------------------------------------------------------------------------+
        | k2l-evm      | 66AK2L06 EVM                                                                          |
        +--------------+---------------------------------------------------------------------------------------+
        | k2g-evm      | K2G EVM                                                                               |
        +--------------+---------------------------------------------------------------------------------------+

.. _building-the-sdk-recipes:

Recipes
-------


.. rubric:: Recipe Basics
   :name: Recipe Basics

One or more recipes can be specified for the <target> for greater
granularity of recipe development and debug. Specifying a recipe name,
minus the version (if the version is appended to the name), will build
the recipe and all its dependencies.

.. ifconfig:: CONFIG_sdk in ('PLSDK')

    For example, the command below builds only the opencl recipe and all the
    dependencies it defines.

    ``MACHINE=<machine> bitbake opencl``

    After the bitbake command above is successfully done,
    **arago-tmp-[toolchain]/work/<machine>-linux-gnueabi/opencl** directory
    will be available including the original source code under the git
    folder, independent shared objects (.so files) under packages-split
    folder, and IPKs under deploy-ipks folder.

.. ifconfig:: CONFIG_sdk in ('PSDKL')

    For example, the command below builds only the jailhouse recipe and all the
    dependencies it defines.

    ``MACHINE=<machine> bitbake jailhouse``

    After the bitbake command above is successfully done,
    **arago-tmp-[toolchain]/work/<machine>-linux/jailhouse** directory
    will be available including the original source code under the git
    folder, independent shared objects (.so files) under packages-split
    folder, and IPKs under deploy-ipks folder.

.. note:: Please note that the output of a recipe can be in another folder under "arago-tmp-[toolchain]/work" directory, depending on the defines of the recipe.


.. rubric:: Forced Re-compilation
   :name: Forced Re-compilation

.. ifconfig:: CONFIG_sdk in ('PLSDK')

    When needed, source code under the work directory (e.g.,
    **arago-tmp-[toolchain]/work/<machine>-linux-gnueabi/opencl**/git) can
    be modified. After the modification is done, run the following commands
    to force recompilation with the new code and rebuilding of the recipe,
    e.g.,
    ``MACHINE=<machine> bitbake opencl --force -c compile``

    ``MACHINE=<machine> bitbake opencl``

.. ifconfig:: CONFIG_sdk in ('PSDKL')

    When needed, source code under the work directory (e.g.,
    **arago-tmp-[toolchain]/work/<machine>-linux/jailhouse**/git) can
    be modified. After the modification is done, run the following commands
    to force recompilation with the new code and rebuilding of the recipe,
    e.g.,

    ``MACHINE=<machine> bitbake jailhouse --force -c compile``

    ``MACHINE=<machine> bitbake jailhouse``

.. rubric:: Installing Package
   :name: installing-package

.. ifconfig:: CONFIG_sdk in ('PLSDK')

    To install a modified and rebuilt package, copy the new IPKs from the
    deploy-ipks folder (e.g.,
    **arago-tmp-[toolchain]/work/<machine>-linux-gnueabi/opencl/[version]/deploy-ipks**)
    to the target system and then run the following command to install the
    IPKs:

    ``opkg install [package_ipk].ipk``

.. ifconfig:: CONFIG_sdk in ('PSDKL')

    To install a modified and rebuilt package, copy the new IPKs from the
    deploy-ipks folder (e.g.,
    **arago-tmp-[toolchain]/work/<machine>-linux/jailhouse/[version]/deploy-ipks**)
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

Common Variations 
=================

.. ifconfig:: CONFIG_sdk in ('PLSDK')

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

.. ifconfig:: CONFIG_sdk in ('PSDKL')

    N/A

See also
========

General information on Yocto, OpenEmbedded and Arago projects can be found at:

-  `Yocto Project <http://yoctoproject.org/>`__
-  `OpenEmbedded <http://openembedded.org/>`__
-  `Arago Project <https://git.yoctoproject.org/meta-arago>`__

