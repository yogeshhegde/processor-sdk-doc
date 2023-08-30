.. http://processors.wiki.ti.com/index.php/MCSDK1.1_to_Processor_SDK_Migration_Guide_for_OMAPL13x/C674x_devices

MCSDK1.1 to Processor SDK Linux Migration Guide for OMAPL13x devices
=======================================================================

**Processor SDK v4.0 release from Texas Instruments adds support for
OMAPL13x and aligns the platform software with newer ARM and DSP
based SOC's.**

All new development efforts should use Processor SDK. This is
the only software package that TI supports on these devices for new
development.

.. rubric:: Installation
   :name: installation-mcsdk-to-procsdk-omapl1

-  Processor SDK Linux is available as an installer on ti.com for
   download

.. rubric:: Target Machine
   :name: target-machine-mcsdk-to-procsdk-omapl1

-  The Processor SDK Linux installer is available only for 64-bit host
   machines running Linux. Support for 32-bit machines is dropped
   primarily due to the Linzro toolchain not supporting 32-bit anymore.

   .. ifconfig:: CONFIG_sdk in ('PLSDK')

       Host support for the SDK is described in the `Supported Host Operating Systems
       <Release_Specific_Supported_Platforms_and_Versions.html#supported-host-operating-systems>`__

.. rubric:: Tool Chain
   :name: tool-chain

-  Processor Linux SDK is using Linaro GCC 6.2-2016.11 cross compiler.

.. rubric:: Directory Structure
   :name: directory-structure-mcsdk-to-procsdk-omapl1

-  The images directory in MCSDK is renamed to prebuilt\_images and
   moved under board\_support directory.
-  In addition to the prebuilt\_images and filesystem, the Linux
   installer now contains a copy of the Linux Kernel and U-Boot GIT
   repositories.
-  A script create-sdcard.sh is provided in bin directory to create the
   SD card using prebuilt images in Processor SDK.
-  host-tools folder in MCSDK is not included in Processor SDK. Pinmux
   utility can be downloaded from ti.com. Aisgen utility is replaced by
   dd command to generate the u-boot ais image.
-  For an overview of the directory structure and a brief description of
   the contents of the folders, please refer to `Processor SDK Linux
   Directory
   Structure <Overview_Directory_Structure_Overview.html>`__

.. rubric:: U-Boot
   :name: u-boot-mcsdk-to-procsdk-omapl1

-  Bootz is enabled in u-boot. So use zImage instead of uImage
-  A copy of u-boot GIT repo is included in the board-support folder of
   the Processor SDK installation
-  Aisgen utility is not used in Processor SDK to generate the U-Boot
   ais image, but using dd command:

::

      $ sudo dd if=u-boot.ais of=/dev/sd<N> seek=117 bs=512 conv=fsync

-  For more details, refer to `Processor SDK U-Boot Release
   Notes <Foundational_Components_U-Boot.html#u-boot-release-notes>`__
   and `Processor SDK U-Boot User’s
   Guide <Foundational_Components_U-Boot.html#u-boot-user-s-guide>`__

.. rubric:: Linux Kernel
   :name: linux-kernel-mcsdk-to-procsdk-omapl1

-  The Linux kernel is upgraded to 4.9.
-  A copy of Kernel GIT repo is included in the board-support folder of
   the Processor SDK installation
-  Kernel is device tree (.dts) based, and not board platform based
   implementation.
-  For more details, refer to `Processor SDK Kernel Release
   Notes <Foundational_Components_Kernel_Release_Notes.html>`__
   and `Processor SDK Kernel User’s
   Guide <Foundational_Components_Kernel_Users_Guide.html>`__

.. rubric:: Building the Linux SDK
   :name: building-the-linux-sdk-mcsdk-to-procsdk-omapl1

-  The Processor SDK Linux can be fully assembled from sources, via
   Yocto.
-  The instructions on how to build the Processor SDK Linux are
   available in `Building the Linux
   SDK <Overview_Building_the_SDK.html>`__

.. rubric:: Inter-Processor Communication (IPC)
   :name: inter-processor-communication-ipc

-  Processor SDK supports IPC 3.x. It is
   not Syslink based implementation.
-  To migrate to IPC 3.x, please refer to `IPC 3.x Migration
   Guide <http://processors.wiki.ti.com/index.php/IPC_3.x_Migration_Guide>`__

