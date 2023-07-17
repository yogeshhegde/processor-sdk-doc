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

    The recommended Linux distribution is Ubuntu 22.04.

The following build host packages are required for Ubuntu. The following
command will install the required tools on the Ubuntu Linux
distribution.

.. ifconfig:: CONFIG_sdk in ('PLSDK', 'PSDKL')

    For Ubuntu 22.04, please run the following:

::

    $ sudo apt-get update
    $ # Install packages required for builds
    $ sudo apt-get -f -y install \
        git build-essential diffstat texinfo gawk chrpath socat doxygen \
        dos2unix python3 bison flex libssl-dev u-boot-tools mono-devel \
        mono-complete curl python3-distutils repo pseudo python3-sphinx \
        g++-multilib libc6-dev-i386 jq git-lfs pigz zstd liblz4-tool \
        cpio file zstd lz4

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

        $ wget https://developer.arm.com/-/media/Files/downloads/gnu/11.3.rel1/binrel/arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-linux-gnueabihf.tar.xz
        $ tar -Jxvf arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-linux-gnueabihf.tar.xz -C $HOME
        $ wget https://developer.arm.com/-/media/Files/downloads/gnu/11.3.rel1/binrel/arm-gnu-toolchain-11.3.rel1-x86_64-aarch64-none-linux-gnu.tar.xz
        $ tar -Jxvf arm-gnu-toolchain-11.3.rel1-x86_64-aarch64-none-linux-gnu.tar.xz -C $HOME

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
The MACHINE can be set to |__SDK_BUILD_MACHINE__|, for example.

.. ifconfig:: CONFIG_part_family not in ('General_family', 'AM335X_family', 'AM437X_family')
    
 .. ifconfig:: CONFIG_sdk in ('PLSDK')

   .. ifconfig:: CONFIG_part_variant in ('AM62AX')

       The final command below will build the **tisdk-edgeai-image**, which is the
       Processor SDK image with arago + edge ai filesystem.  See `Build Options`_ for a list of
       additional targets.

       ::

           $ git clone https://git.ti.com/git/arago-project/oe-layersetup.git tisdk
           $ cd tisdk
           $ ./oe-layertool-setup.sh -f configs/processor-sdk/processor-sdk-08.06.00-config.txt
           $ cd build
           $ . conf/setenv
           $ export TOOLCHAIN_PATH_ARMV7=$HOME/gcc-arm-9.2-2019.12-x86_64-arm-none-linux-gnueabihf
           $ export TOOLCHAIN_PATH_ARMV8=$HOME/gcc-arm-9.2-2019.12-x86_64-aarch64-none-linux-gnu
           $ git clone https://git.ti.com/git/security-development-tools/core-secdev-k3.git -b master
           $ export TI_SECURE_DEV_PKG_K3=`pwd`/core-secdev-k3
           $ MACHINE=am62axx-evm bitbake -k tisdk-edgeai-image

       Your tisdk-edgeai-image wic image will be generated in arago-tmp-[toolchain]/deploy directory. Use `Processor\_SDK\_Linux\_create\_SD\_card <Overview/Processor_SDK_Linux_create_SD_card.html>`__ to flash this image on the SD-Card.
      
      
   .. ifconfig:: CONFIG_part_variant not in ('AM62AX')

       The final command below will build the **tisdk-default-image**, which is the
       Processor SDK image with arago filesystem.  See `Build Options`_ for a list of
       additional targets.

       ::

           $ git clone https://git.ti.com/git/arago-project/oe-layersetup.git tisdk
           $ cd tisdk
           $ ./oe-layertool-setup.sh -f configs/processor-sdk/processor-sdk-09.00.00-config.txt
           $ cd build
           $ . conf/setenv
           $ export TOOLCHAIN_PATH_ARMV7=$HOME/arm-gnu-toolchain-11.3.rel1-x86_64-arm-none-linux-gnueabihf
           $ export TOOLCHAIN_PATH_ARMV8=$HOME/arm-gnu-toolchain-11.3.rel1-x86_64-aarch64-none-linux-gnu
           $ MACHINE=<machine> bitbake -k tisdk-default-image

       Your tisdk-default-image wic image will be generated in arago-tmp-[toolchain]/deploy directory. Use `Processor\_SDK\_Linux\_create\_SD\_card <Overview/Processor_SDK_Linux_create_SD_card.html>`__ to flash this image on the SD-Card.    
     
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

    .. ifconfig:: CONFIG_part_variant in ('AM62AX')

        +------------------------------+---------------------------------------------------------------+----------------------------+
        | Target                       | Build Output                                                  | Description                |
        +==============================+===============================================================+============================+
        | tisdk-core-bundle            | images/<machine>/processor-sdk-linux-bundle-<machine>.tar.xz  | Full SDK                   |
        +------------------------------+---------------------------------------------------------------+----------------------------+
        | tisdk-edgeai-image           | images/<machine>/tisdk-edgeai-image-<machine>.tar.xz          | Target Edge AI Filesystem  |
        +------------------------------+---------------------------------------------------------------+----------------------------+
        | tisdk-default-image          | images/<machine>/tisdk-default-image-<machine>.tar.xz         | Target Filesystem          |
        +------------------------------+---------------------------------------------------------------+----------------------------+
        | tisdk-base-image             | images/<machine>/tisdk-base-image-<machine>.tar.xz            | Minimal Target Filesytem   |
        +------------------------------+---------------------------------------------------------------+----------------------------+
        | meta-toolchain-arago-tisdk   | sdk/arago-<arago-version>-<architecture>.sh                   | Devkit                     |
        +------------------------------+---------------------------------------------------------------+----------------------------+

    .. ifconfig:: CONFIG_part_variant not in ('AM62AX')

        +------------------------------+---------------------------------------------------------------+----------------------------+
        | Target                       | Build Output                                                  | Description                |
        +==============================+===============================================================+============================+
        | tisdk-core-bundle            | images/<machine>/processor-sdk-linux-bundle-<machine>.tar.xz  | Full SDK                   |
        +------------------------------+---------------------------------------------------------------+----------------------------+
        | tisdk-default-image          | images/<machine>/tisdk-default-image-<machine>.tar.xz         | Target Filesystem          |
        +------------------------------+---------------------------------------------------------------+----------------------------+
        | tisdk-base-image             | images/<machine>/tisdk-base-image-<machine>.tar.xz            | Minimal Target Filesytem   |
        +------------------------------+---------------------------------------------------------------+----------------------------+
        | tisdk-thinlinux-image        | images/<machine>/tisdk-thinlinux-image-<machine>.tar.xz       | Minimal Target Filesytem   |
        |                              |                                                               | with docker enabled        |
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

        +---------------+-----------------------------------------------+
        | **MACHINE**   | **Supported EVMs**                            |
        +---------------+-----------------------------------------------+
        | am64xx-evm    | AM64x EVM - HS-FS, HS-SE                      |
        +---------------+-----------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('AM62X')

        +------------------+--------------------------------------------+
        | **MACHINE**      | **Supported EVMs**                         |
        +------------------+--------------------------------------------+
        | am62xx-evm       | AM62x Starter Kit (SK) - GP, HS-FS, HS-SE  |
        +------------------+--------------------------------------------+
        | am62xx-lp-evm    | AM62x LP Starter Kit (SK) - HS-FS, HS-SE   |
        +------------------+--------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('AM62AX')

        +---------------+---------------------------------------------------------------------------------------+
        | **MACHINE**   | **Supported EVMs**                                                                    |
        +---------------+---------------------------------------------------------------------------------------+
        | am62axx-evm   | AM62A Starter Kit (SK)                                                                |
        +---------------+---------------------------------------------------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('AM65X')

        +---------------+-----------------------------------------------------------------------------------------+
        | **MACHINE**   | **Supported EVMs**                                                                      |
        +---------------+-----------------------------------------------------------------------------------------+
        | am65xx-evm    | AM65x Evaluation Module, AM65x Industrial Development Kit, DRA80xM Evaluation Module    |
        +---------------+-----------------------------------------------------------------------------------------+
        | am65xx-hs-evm | AM65x HS Evaluation Module, AM65x Industrial Development Kit, DRA80xM Evaluation Module |
        +---------------+-----------------------------------------------------------------------------------------+

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

        +---------------+-----------------------------------------------+
        | **MACHINE**   | **Supported EVMs**                            |
        +---------------+-----------------------------------------------+
        | am64xx-evm    | AM64x EVM - HS-FS, HS-SE                      |
        +---------------+-----------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('AM62X')

        +------------------+--------------------------------------------+
        | **MACHINE**      | **Supported EVMs**                         |
        +------------------+--------------------------------------------+
        | am62xx-evm       | AM62x Starter Kit (SK) - GP, HS-FS, HS-SE  |
        +------------------+--------------------------------------------+
        | am62xx-lp-evm    | AM62x LP Starter Kit (SK) - HS-FS, HS-SE   |
        +------------------+--------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('AM65X')

        +---------------+-----------------------------------------------------------------------------------------+
        | **MACHINE**   | **Supported EVMs**                                                                      |
        +---------------+-----------------------------------------------------------------------------------------+
        | am65xx-evm    | AM65x Evaluation Module, AM65x Industrial Development Kit, DRA80xM Evaluation Module    |
        +---------------+-----------------------------------------------------------------------------------------+
        | am65xx-hs-evm | AM65x HS Evaluation Module, AM65x Industrial Development Kit, DRA80xM Evaluation Module |
        +---------------+-----------------------------------------------------------------------------------------+

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

or

``MACHINE=<machine> bitbake <target> -c cleanall``

The cleansstate task will clean recipe's work directory and remove the
recipe's output from the dependency tree used by other recipe's during
compilation.

See also
========

General information on Yocto, OpenEmbedded and Arago projects can be found at:

-  `Yocto Project <http://yoctoproject.org/>`__
-  `OpenEmbedded <http://openembedded.org/>`__
-  `Arago Project <https://git.yoctoproject.org/meta-arago>`__

