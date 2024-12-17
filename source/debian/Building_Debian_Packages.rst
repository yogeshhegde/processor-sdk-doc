========================
Building Debian Packages
========================

`Debian-Repos <https://github.com/TexasInstruments/debian-repos>`__ is a set of scripts to build TI's Debian packages with a single command.

The generation of a Debian package from a binary or source involves many steps such as, obtaining the source code in tar (compressed) format, generating template files, modifying template file. The host build system and host build environment variables should also be configured.

The `run.sh` script handles these steps, thus the building of a deb package for TI's packages is as simple as running `run.sh` with the desired package's name.

This repository is useful to the following audience:

1. Potential package contributors who want to fix bugs or add enhancements to TI packages.
2. Users who want to create a new package with the latest changes or customizations.
3. Anyone who wants to study Debian packaging.

Structure
=========

The `run.sh` file is the "main" script that should be run. It takes as argument the name of the package to be built.

Each TI package has a corresponding directory, named after its source package. Within this directory exists the `suite/<distro-variant>/debian/` path. All Debian related files (`control`, `rules`, man pages etc) for the package are located here.

There also exists a `<package-name>/version.sh` file. This file is sourced by `run.sh`.

Setting Up Host for the build
=============================

The `debian-repos` only support native compilation of packages. Hence, the build has to be done either on the ARM64 Target or ARM64 Docker Container or ARM64 Chroot Environment.

When running on native ARM64 target, no additional setup is required. Proceed with Building the Package.

To setup and run an ARM64 Docker, run the following commands:

.. code-block::

    # Setup Qemu multiarch support
    sudo apt-get install qemu binfmt-support qemu-user-static
    docker run --rm --privileged multiarch/qemu-user-static --reset -p yes

    # Run ARM64 Container
    docker pull ghcr.io/texasinstruments/debian-arm64:latest
    docker run --rm -it ghcr.io/texasinstruments/debian-arm64:latest

Building the Package
====================

Clone `debian-repos <https://github.com/TexasInstruments/debian-repos>`__

.. code-block::

   git clone https://github.com/TexasInstruments/debian-repos.git
   cd debian-repos

To build a package, the syntax is:

.. code-block::

    ./run.sh <package-name>

This command carries out all the necessary steps to build the package including installation of package-specific dependencies. The package and all related files are then stored in `build/<package-name>`.

For example: to build `ti-linux-kernel`, the command is:

.. code-block::

    ./run.sh ti-linux-kernel

The output is then found in `build/ti-linux-kernel/`.

Adding Packages
===============

To add a package, follow the following steps:

1. Create nested directories as follows:

.. code-block::

    mkdir -p <proj-name>/suite/<distro-variant>/debian/

2. Copy all ``debian/`` specific files that are relevant to building the package:

.. code-block::

    cp /path/to/debian/* -r  <proj-name>/suite/<distro-variant>/debian/

3. In ``<proj-name>/``, create the ``version.sh`` file. The file must export the following variables:

.. code-block::

    git_repo # link from which to clone

