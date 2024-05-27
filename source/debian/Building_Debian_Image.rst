======================
Building Debian Images
======================

Introduction
============

Building a Debian Image requires:

    1. Generating a chroot environment for the target architecture (Arm), if the host environment is on x86.
    2. Installing all the necessary packages
    3. Customizing configuration scripts if needed
    4. Building Bootloader
    5. Flashing the generated RootFS and Boot binaries to SD Card

There are several opensource tools available for generating the RootFS in a chroot environment. Such as debootstrap (now deprecated), mmdebstrap (complex), bdebstrap (simple wrapper on top of mmdebstrap).

`ti-bdebstrap <https://github.com/TexasInstruments/ti-debpkgs>`__ is a set of scripts that builds upon the ``bdebstrap`` tool to create custom Debian images for TI platforms. This includes creating the ``bdebstrap`` chroot environment itself, installing essential and useful TI and non-TI packages, setting up the configuations, Building the U-Boot etc.

In other words, ``ti-bdebstrap`` offers users an easy way to create a full-fledged Debian image for supported TI platforms, using a single command. Once the image is built, the user can directly flash it onto a SD card.

TI currently supports building Debian Bookworm Images for AM62Px, AM62x and AM64x platforms.

Usage
=====

Get Scripts
-----------

The scripts are hosted at https://github.com/TexasInstruments/ti-bdebstrap

To clone the repository, run:

.. code-block::

    git clone https://github.com/TexasInstruments/ti-bdebstrap.git


Repository Structure
--------------------

.. code-block::

    ti-bdebstrap
    ├── build.sh
    ├── builds.toml
    ├── configs
    │   ├── bdebstrap_configs
    │   │   ├── am62-bookworm.yaml
    │   │   ├── am62p-bookworm.yaml
    │   │   ├── am64-bookworm.yaml
    │   ├── bsp_sources.toml
    │   └── machines.toml
    ├── LICENSE
    ├── README.md
    ├── scripts
    │   ├── build_bsp.sh
    │   ├── build_distro.sh
    │   ├── common.sh
    │   └── setup.sh
    ├── target
    │   └── files for target configs


``build.sh``: the "main" script that the user should run to generate Debian images.

``configs/``: contains details, configuration options and values for machines, bsp_sources and distro-variants (see below for details).

``scripts/``: contains helper scripts for ``build.sh``.

``target/``: contains files for target configs, like ``weston.service`` for the **weston** target.

``builds.toml``: contains list of all valid builds along with their definitions (see below for details).

Build Configurations
--------------------

A ``build config`` represents an image with certain values for the ``machine``, ``bsp_version`` and ``distro_variant`` parameters.

The ``builds.toml`` file contains a list of all valid builds in the ``builds[]`` list. Each ``build`` is then defined underneath.

Values of ``machine``, ``bsp_version`` and ``distro-variant`` must be defined in ``configs/machines.toml``, ``configs/bsp_sources.toml`` and ``configs/bdebstrap_configs/<distro-variant>.yaml`` files. If any of these is missing, the build will fail.

So long as you conform to the rule above, you may also define your own builds.

Building Images
---------------

All valid builds are listed in the ``builds.toml`` file. To build an image, one of these must be chosen and supplied to the ``build.sh`` command. ``build.sh`` commences the build process.
The images are finally stored in the ``build/`` directory. Each build also produces a log file inside ``log/``.

Building images using ``ti-bdebstrap`` involves the following steps:

    1. install the pre-requisite packages
    2. get the scripts using ``git clone``
    3. run the ``build.sh`` script and with required build config as argument.
    4. flashing the image into a SD card

Install Pre-requisite Packages
------------------------------

First, ensure that your repositories are up-to-date:

.. code-block::

    sudo apt update

Then, install packages as follows:

.. code-block::

    sudo apt install -y \
        pigz expect pv \
        binfmtc binfmt-support \
        qemu-user qemu-user-static qemu-system-arm \
        debian-archive-keyring bdebstrap \
        build-essential autoconf automake \
        bison flex libssl-dev \
        bc u-boot-tools swig python3-pyelftools


Ensure that all packages were correctly installed using:

.. code-block::

    sudo apt install --fix-broken

Finally, install ``toml-cli``:

.. code-block::

    pip3 install toml-cli

.. note::

   Since the build script is run as `root` user, toml-cli should also be installed with `sudo` for `root` user to be able to access it.

.. note::

   The scripts internally handle toolchain downloads based on Host architecture. So the same steps can be followed on both `arm` and `x86_64` hosts.

Building the Image
-------------------

.. note::

   If you are behind a proxy, since the build is run with sudo, make sure to set the proxy for root user (preferably in ``/etc/environment``).

To build an image, you need to run the ``build.sh`` script:

.. code-block::

    sudo ./build.sh <build-name>

The ``<build-name>`` must be one present inside ``builds.toml`` file.

After the build, the RootFS, Boot partition and bsp_sources are stored in ``build/<build-name>``. The logs will be stored in ``logs/<build-name>.log``.

Example: to build for ``am62-bookworm-09.02.01.010``, run:

.. code-block::

    sudo ./build.sh am62-bookworm-09.02.01.010

The RootFS, Boot partition and bsp_sources are then stored in ``build/am62-bookworm-09.02.01.010``. The build log is saved as ``logs/am62-bookworm-09.02.01.010.log``.

Generate an SD Card Image
-------------------------

This step can be skipped if you do not want to share the generated Image with anyone and want to proceed with testing with an SD card.

To generate an SD Card Image with the generated RootFS and Boot partition files, run:

.. code-block::

   ./create-wic.sh <build-name>

Example: to build for ``am62-bookworm-09.02.01.010``, run:

.. code-block::

   ./create-wic.sh am62-bookworm-09.02.01.010

The wic image is generated under ``build/am62-bookworm-09.02.010``. This can be used to flash an SD card using standard tools like balena-etcher.

Flash Image to SD Card using Script
-----------------------------------

To flash the SD card without generating a wic image, use the ``create-sdcard.sh`` script. Run it using the below command and follow with the prompts.

.. code-block::

    sudo ./create-sdcard.sh <build-name>

For example, if the image is am62-bookworm-09.02.01.010, type:

.. code-block::

    sudo ./create-sdcard.sh am62-bookworm-09.02.01.010

This script will partition the SD Card and copy the contents of RootFS and Boot partitions that are generated to the SD Card.

