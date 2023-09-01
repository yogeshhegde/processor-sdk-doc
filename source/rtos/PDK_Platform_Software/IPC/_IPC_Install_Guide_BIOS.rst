.. http://processors.wiki.ti.com/index.php/IPC_Install_Guide_BIOS

Introduction
^^^^^^^^^^^^^

Inter/Intra Processor Communication (IPC) is a product designed to
enable communication between processors in a multi-processor
environment. Features of IPC include message passing, multi-processor
gates, shared memory primitives, and more.

IPC is designed for use with processors running SYS/BIOS applications.
This is typically an ARM or DSP. IPC includes support for High Level
Operating Systems (HLOS) like Linux, as well as the SYS/BIOS RTOS. The
breadth of IPC features supported in an HLOS environment is reduced in
an effort to simplify the product.

Install
^^^^^^^^^

IPC is often distributed and installed within a larger SDK. In those
cases, no installation is required.

Outside of an SDK, `IPC can be downloaded
here <http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/index.html>`__,
and is released as a zip file. To install, simply extract the file.

::

    buildhost$ unzip ipc_<version>.zip

This will extract the IPC product in a directory with its product name
and version information (e.g. **c:/ti/ipc_<version>**)

.. note::
  -  This document assumes the IPC install path to be the user's home
     directory on a Linux host machine (**/home/<user>**) or the user's
     main drive on a Windows host machine (**C:\\**). The variable
     **IPC_INSTALL_DIR** will be used throughout the document. If IPC was
     installed at a different location, make appropriate changes to
     commands.
  -  Some customers find value in archiving the released sources in a
     configuration management system. This can help in identifying any
     changes made to the original sources - often useful when updating to
     newer releases.

Build
^^^^^^^

The IPC product often comes with prebuilt libraries, so rebuilding them
isn't necessary. The IPC product downloads contain prebuilt libraries,
and when provided with an SDK, IPC is typically rebuilt to contain only
libraries appropriate for the SDK.

However, if you want to rebuild its libraries, IPC provides GNU
makefile(s) at the base of the product. This section describes the steps
required to rebuild the IPC libraries.

.. note::
  GNU make version 3.81 or greater is required. The XDC tools (provided
  with most SDKs and CCS distributions) includes a pre-compiled version of
  GNU make 3.81 in $(XDC_INSTALL_DIR)/gmake.

products.mak
""""""""""""""

IPC contains a **products.mak** file at the root of the product that
specifies the necessary paths and options to build IPC for the various
OS support.

Edit **products.mak** and set the following variables:

.. note::
   Please make sure the complete path is specified. (e.g) Don't use ~ in the path specified.

-  **XDC_INSTALL_DIR** - Path to TI's XDCTools installation
-  **BIOS_INSTALL_DIR** - Path to TI's SYS/BIOS installation
-  **ti.targets.<device target and file format>** - Path to TI toolchain
   for the device.

   -  Set only the variables to the targets your device supports to
      minimize build time.

-  **gnu.targets.arm.<device target and file format>** - Path to GNU
   toolchain for the device.

   -  Set only the variables to the targets your device supports to
      minimize build time.

-  **PLATFORM** - (Optional) platform for which to build executables

   -  Introduced in IPC 3.10. Prior releases build executables for
      **all** platforms based on that targets/toolchains set above
   -  If not set, only libraries will be built (not executables)

.. note::
  The versions used during validation can be found in the IPC Release
  Notes provided in the product.

ipc-bios.mak
"""""""""""""

IPC is built with a GNU makefile. After editing **products.mak**, issue
the following command:

::

    <buildhost> make -f ipc-bios.mak all

Based on the number of targets you're building for, this may take some
time.

Examples
^^^^^^^^^^

The IPC product contains an examples/archive directory with
device-specific examples. Once identifying your device, the examples can
be unzipped anywhere on your build host. Typically once unzipped, the
user edits the example's individual **products.mak** file and simply
invokes **make**.

.. note::
  A common place to unzip the examples is into the
  **IPC_INSTALL_DIR/examples/** directory. Each example's **products.mak**
  file is smart enough to look up two directories (in this case, into
  **IPC_INSTALL_DIR**) for a master **products.mak** file, and if found it
  uses those variables. This technique enables users to set the dependency
  variables in one place, namely **IPC_INSTALL_DIR/products.mak**.

Each example contains a **readme.txt** with example-specific details.

See Also
^^^^^^^^^^

-  `IPC 3.x <index_Foundational_Components.html#ipc-3-x>`__
-  `IPC Users Guide <index_Foundational_Components.html#ipc-user-guide>`__
-  `IPC 3.x FAQ <index_Foundational_Components.html#ipc-faq>`__
-  `IPC Install Guide Linux <index_Foundational_Components.html#linux-install-guide>`__
-  `IPC Install Guide QNX <index_Foundational_Components.html#qnx-install-guide>`__


