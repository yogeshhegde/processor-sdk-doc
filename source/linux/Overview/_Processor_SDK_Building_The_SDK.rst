.. include:: /_replacevars.rst

************************************
Building the SDK with Yocto
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

.. ifconfig:: CONFIG_sdk in ('PLSDK', 'PSDKL','j7_foundational')

    The recommended Linux distribution is Ubuntu 22.04.

The following build host packages are required for Ubuntu. The following
command will install the required tools on the Ubuntu Linux
distribution.

.. ifconfig:: CONFIG_sdk in ('PLSDK', 'PSDKL','j7_foundational')

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


Build Steps
-----------

Please refer to :ref:`here <yocto-layer-configuration>` for the
layer configuration (oeconfig-file) for a particular release of |__SDK_FULL_NAME__|.
The MACHINE can be set to |__SDK_BUILD_MACHINE__|, for example.

.. ifconfig:: CONFIG_part_family not in ('General_family')

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
           $ ./oe-layertool-setup.sh -f configs/processor-sdk/<oeconfig-file>
           $ cd build
           $ . conf/setenv
           $ MACHINE=<machine> bitbake -k tisdk-default-image

       Your tisdk-default-image wic image will be generated in deploy-ti directory. Use `Processor\_SDK\_Linux\_create\_SD\_card <Overview/Processor_SDK_Linux_create_SD_card.html>`__ to flash this image on the SD-Card.


.. note:: While building images via Yocto, if you are facing **locale.Error: unsupported locale setting** error it means your system is trying to use locale setting which was not there. Run the following commands which will setup the locale and try building your target image again.

    ::

        export LC_ALL="en_US.UTF-8"
        export LC_CTYPE="en_US.UTF-8"
        export LC_NUMERIC="en_US.UTF-8"
        export LANG=en_US.UTF-8
        export LANGUAGE=en_US.UTF-8
        ulimit -n 4096

.. ifconfig:: CONFIG_sdk in ('PSDKL','j7_foundational')

    |__SDK_FULL_NAME__| uses the 'oe-layersetup' tool to configure the meta layers. If you do not have the Linux SDK package installed:
    ::

        git clone https://git.ti.com/git/arago-project/oe-layersetup.git yocto-build
        cd yocto-build

    The Linux SDK package also has the above tool cloned at the top level. If you have it installed:
    ::

        cd <SDK INSTALL DIR>/yocto-build

    Then run following commands to setup a yocto build for a specific release version and build the 'tisdk-default-image' target.
    ::

        ./oe-layertool-setup.sh -f configs/processor-sdk-linux/processor-sdk-linux-<version>.txt
        cd build
        . conf/setenv
        MACHINE=<machine> bitbake -k tisdk-default-image

    .. Note::
        The build will ~250GB of hard disk space for building the tisdk-default-image.


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
**deploy-ti** directory.


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

.. ifconfig:: CONFIG_sdk in ('j7_foundational')

   +------------------------------+---------------------------------------------------------------+----------------------------+
   | Target                       | Build Output                                                  | Description                |
   +==============================+===============================================================+============================+
   | tisdk-core-bundle            | images/<machine>/tisdk-core-bundle-<machine>.tar.xz           | Full SDK                   |
   +------------------------------+---------------------------------------------------------------+----------------------------+
   | tisdk-default-image          | images/<machine>/tisdk-default-image-<machine>.tar.xz         | Target Filesystem          |
   +------------------------------+---------------------------------------------------------------+----------------------------+
   | tisdk-base-image             | images/<machine>/tisdk-base-image-<machine>.tar.xz            | Minimal Target Filesytem   |
   +------------------------------+---------------------------------------------------------------+----------------------------+
   | tisdk-thinlinux-image        | images/<machine>/tisdk-thinlinux-image-<machine>.tar.xz       | Minimal Target Filesytem   |
   |                              |                                                               | with docker enabled        |
   +------------------------------+---------------------------------------------------------------+----------------------------+
   | meta-toolchain-arago-tisdk   | sdk/arago-<arago-version>-<architecture>.sh                   | Linux glibc toolchain      |
   +------------------------------+---------------------------------------------------------------+----------------------------+
   | mc:k3r5:meta-toolchain-arago | sdk/arago-<arago-version>-<architecture>.sh                   | K3R5 baremetal toolchain   |
   +------------------------------+---------------------------------------------------------------+----------------------------+

.. ifconfig:: CONFIG_sdk in ('PSDKL')

   +------------------------------+---------------------------------------------------------------+----------------------------+
   | Target                       | Build Output                                                  | Description                |
   +==============================+===============================================================+============================+
   | tisdk-core-bundle            | images/<machine>/tisdk-core-bundle-<machine>.tar.xz           | Full SDK                   |
   +------------------------------+---------------------------------------------------------------+----------------------------+
   | tisdk-default-image          | images/<machine>/tisdk-default-image-<machine>.tar.xz         | Target Filesystem          |
   +------------------------------+---------------------------------------------------------------+----------------------------+
   | tisdk-base-image             | images/<machine>/tisdk-base-image-<machine>.tar.xz            | Minimal Target Filesytem   |
   +------------------------------+---------------------------------------------------------------+----------------------------+
   | tisdk-thinlinux-image        | images/<machine>/tisdk-thinlinux-image-<machine>.tar.xz       | Minimal Target Filesytem   |
   |                              |                                                               | with docker enabled        |
   +------------------------------+---------------------------------------------------------------+----------------------------+
   | meta-toolchain-arago-tisdk   | sdk/arago-<arago-version>-<architecture>.sh                   | Linux glibc toolchain      |
   +------------------------------+---------------------------------------------------------------+----------------------------+
   | mc:k3r5:meta-toolchain-arago | sdk/arago-<arago-version>-<architecture>.sh                   | K3R5 baremetal toolchain   |
   +------------------------------+---------------------------------------------------------------+----------------------------+

.. ifconfig:: CONFIG_sdk in ('PSDKL','j7_foundational')

    .. rubric:: Platforms

    Please refer to :ref:`here <yocto-layer-configuration>` for the yocto build platforms supported in |__SDK_FULL_NAME__|.
    These are the <machine> used in the command:

    ``MACHINE=<machine> bitbake <target>``

    .. ifconfig:: CONFIG_part_variant in ('J721E')

        +-------------------------------+-----------------------------------------------------------------------+
        | **MACHINE**                   | **Supported EVMs**                                                    |
        +-------------------------------+-----------------------------------------------------------------------+
        | |__SDK_BUILD_MACHINE__|       | J721E EVM, TDA4VM SK                                                  |
        +-------------------------------+-----------------------------------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('J721S2')

        +-------------------------------+-----------------------------------------------------------------------+
        | **MACHINE**                   | **Supported EVMs**                                                    |
        +-------------------------------+-----------------------------------------------------------------------+
        | |__SDK_BUILD_MACHINE__|       | J721S2 EVM, AM68 SK                                                   |
        +-------------------------------+-----------------------------------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('J784S4')

        +-------------------------------+-----------------------------------------------------------------------+
        | **MACHINE**                   | **Supported EVMs**                                                    |
        +-------------------------------+-----------------------------------------------------------------------+
        | |__SDK_BUILD_MACHINE__|       | J784S4 EVM, AM69 SK                                                   |
        +-------------------------------+-----------------------------------------------------------------------+

    .. ifconfig:: CONFIG_part_variant in ('J7200')

        +-------------------------------+-----------------------------------------------------------------------+
        | **MACHINE**                   | **Supported EVMs**                                                    |
        +-------------------------------+-----------------------------------------------------------------------+
        | |__SDK_BUILD_MACHINE__|       | J7200 EVM                                                             |
        +-------------------------------+-----------------------------------------------------------------------+

    .. ifconfig:: CONFIG_rt_linux_support in ('yes')

        .. rubric:: RT Support

        Run the command below, before the bitbake build command, to setup a yocto build with RT Linux Kernel:
        ::

            echo "ARAGO_RT_ENABLE = \"1\"" >> conf/local.conf

        This will tell the Arago yocto setup to pick up RT-Linux Kernel when building any images that depend on the Kernel.
        Alternatively, one can directly build the RT Kernel using below:

        ``MACHINE=<machine> bitbake linux-ti-staging-rt``

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
        | am62xxsip-evm    | AM62x-SIP Starter Kit (SK) - HS-FS, HS-SE  |
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
        | am62xxsip-evm    | AM62x-SIP Starter Kit (SK) - HS-FS, HS-SE  |
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

.. ifconfig:: CONFIG_sdk in ('PSDKL','j7_foundational')

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

.. ifconfig:: CONFIG_sdk in ('PSDKL','j7_foundational')

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

.. ifconfig:: CONFIG_sdk in ('PSDKL','j7_foundational')

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

