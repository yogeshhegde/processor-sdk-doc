========================
Building Debian Packages
========================

Debian-Repos is a set of scripts to build TI's Debian packages with a single command.

The generation of a Debian package from a binary or source involves many steps such as, obtaining the source code in tar (compressed) format, generating template files, modifying template file. The host build system and host build  environment variables should also be configured. 

The `run.sh` script handles these steps, thus the building of a deb package for TI's packages is as simple as running `run.sh` with the desired package's name.

This repository is useful to the following audience:

1. Potential package contributors who want to fix bugs or add enhancements to TI packages.
2. Users who want to create a new package with the latest changes or customizations.
3. Anyone who wants to study Debian packaging.

Structure:
==========

The `run.sh` file is the "main" script that should be run. It takes as argument the name of the package to be built.

Each TI package has a corresponding directory, named after its source package. Within this directory exists the `suite/<distro-variant>/debian/` path. All Debian related files (`control`, `rules`, man pages etc) for the package are located here.

There also exists a `<package-name>/version.sh` file. This file is sourced by `run.sh`. It exports a bunch of variables for `run.sh` to use. It also contains a `run_prep` function, which `run.sh` calls. `run_prep` carries out all package-specific operations needed to build the deb files.

HowTo Use
=========

To build a package, the syntax is:

.. code-block::

    ./run.sh <package-name>

This command carries all the necessary steps to build the package. The package and all related files are then stored in `build/<package-name>`. Note that certain packages may require root privileges.

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

    cp /path/to/debian/* <proj-name>/suite/<distro-variant>/debian/
    cp /path/to/debian/* -r  <proj-name>/suite/<distro-variant>/debian/

3. In ``<proj-name>/``, create the ``version.sh`` file. The file must export the following variables:

.. code-block::

    git_repo # link from which to clone
    package_name # name of the package
    package_version # version of the package
    package_full # "${package-name}-${package-verion}"
    custom_build # set it to true if entire build process must be in version.sh
    require_root # set it to true if root privileges required for this package
    last_tested_commit # the last commit which has been tested and works

If ``custom_build`` is true, then the entire build process is run by ``run_custom_build`` function defined in the ``version.sh`` file. Look at ``ti-linux-kernel`` package for an example of this.
