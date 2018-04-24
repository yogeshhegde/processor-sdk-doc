************************************
Directory Structure Overview
************************************

The Processor SDK for Linux contains the following top-level
directories and files

.. Image:: ../images/Processor-SDK-Linux-directory-structure.png

These directories contain the code and tools used to develop for
Processor SDK devices.

-  **bin** - Contains the helper scripts for configuring the host system
   and target device. Most of these scripts are used by the setup.sh
   script.
-  **board-support** - Contains the SDK components that need to be
   modified when porting to a custom platform. This includes the kernel
   and boot loaders as well as any out of tree drivers.
-  **docs** - Contains various SDK documentation such as the software
   manifest and additional user's guide. This is also the location where
   you can find the *training* directory with the device training
   materials.
-  **example-applications** - Contains the sources for the TI provided
   example applications seen during the out-of-box demonstration.
-  **filesystem** - Contains the reference file systems. These include
   the smaller base file system as well as the full-featured SDK file
   system.
-  **linux-devkit** - Contains the cross-compile toolchain and libraries
   to speed development for the target device.
-  **Makefile** - Provides build targets for many of the SDK components
   from the top-level of the SDK.
-  **Rules.make** - Sets default values used by the top-level Makefile
   as well as sub-component Makefiles
-  **setup.sh** - Configures the users host system as well as the target
   system for development

