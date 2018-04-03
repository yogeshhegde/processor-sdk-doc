********************************************
Processor SDK Android Directory Structure
********************************************

| The Processor SDK for Android contains the following top-level
  directories and files

.. Image:: ../images/Directory_structure_android.PNG

These directories contain the code and tools used to develop for
Processor SDK Android devices.

-  **android-devkit** - Contains the cross-compile toolchain and
   libraries to speed development for the target device.
-  **bin** - Contains the helper scripts for flashing the eMMC on the
   development device as well as the Android Debug Bridge (adb) tool.
-  **board-support** - Contains the SDK components that need to be
   modified when porting to a custom platform. This includes the kernel,
   boot loader, Android Open Source Project filesystem, as well as any
   out of tree drivers.
-  **docs** - Contains various SDK documentation such as the software
   manifest and additional user's guide. This is also the location where
   you can find the *training* directory with the device training
   materials.
-  **filesystem** -
-  **Makefile** - Provides build targets for many of the SDK components
   from the top-level of the SDK.
-  **Rules.make** - Sets default values used by the top-level Makefile
   as well as sub-component Makefiles.
-  **setup.sh** - Runs the fastboot.sh script (found in bin/) to flash
   the eMMC of the connected device using the files in the
   board-support/prebuilt-images/ directory.

