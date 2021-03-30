.. include:: /replacevars.rst.inc

.. _download-and-install-sdk:

Download and Install the SDK
======================================

The Processor SDK Linux AM64x Installer will install the necessary components
to start Linux development on the TI microprocessor.

**Processor SDK Linux AM64x Release has installers for both Linux and Windows machines.**

+----------------------------------------------+------------------------------------------------------------------+
| **Installer Details**                        |   **Installers Name**                                            |
+----------------------------------------------+------------------------------------------------------------------+
| PSDK Linux AM64x Installer (Windows version) | processor_sdk_linux_am64x_xx_yy_zz_nn-windows-x64-installer.exe  |
+----------------------------------------------+------------------------------------------------------------------+
| PSDK Linux AM64x Installer (Linux version)   | processor_sdk_linux_am64x_xx_yy_zz_nn-linux-x64-installer.run    |
+----------------------------------------------+------------------------------------------------------------------+

Windows installer has only the prebuilt-image and filesystems, meant for out of the box demo experience.

Use Linux installer for complete source package, tools, prebuilt-image, filesystems etc. for product development.


The |__SDK_FULL_NAME__| includes the ARM GCC toolchain.
The |__SDK_FULL_NAME__| was built and tested against a specific Linux
Distribution name and version, Ubuntu |__LINUX_UBUNTU_VERSION_SHORT__|.
Note this **does not** prevent the user from installing the SDK on other Linux
distributions.

.. rubric:: Downloading the SDK installer
   :name: downloading-the-sdk-installer

You can download the latest |__SDK_FULL_NAME__| installer from the
|__SDK_DOWNLOAD_URL__|.

.. rubric:: How to Run the SDK Installer in Linux
   :name: how-to-run-the-sdk-installer-linux

Make sure that the execute permissions are set. Bring up a terminal
window and change directories to where the installer is located
(probably the Downloads directory) and run the following commands:

.. parsed-literal::

    chmod +x ./|__SDK_INSTALL_FILE__|
    ./|__SDK_INSTALL_FILE__|

Alternatively, you can give execute permissions and run the "|__SDK_INSTALL_FILE__|"
by double clicking on it within your Linux host PC.

.. rubric:: How to Run the SDK Installer in Windows
   :name: how-to-run-the-sdk-installer-windows

Double click on the installer to begin installation.

.. note::
   As a part of the installation, the packaging will run a script to configure your
   environment and download the Linux devkit.  This will cause the installation to
   continue for roughly a minute even after it shows that it has reached 100%.

.. note::
   If nothing seems to happen, your computer may be running a 32-bit version of
   its operating system. The installer is 64-bit, and will not execute properly.

**Package Overview**

This AM64x Software development kit contains Linux device drivers, sample examples and
application specific demos.  The SDK has the below folder structure


+---------------------+-----------------------------------------------------------------------+
| **Folder Name**     |   **Description**                                                     |
+---------------------+-----------------------------------------------------------------------+
| bin                 | set-up scripts, SD card image creation script                         |
|                     |                                                                       |
+---------------------+-----------------------------------------------------------------------+
| board-support       | Linux board supported packages (prebuilt-images, tools,               |
|                     | Linux kernel and u-boot in source)                                    |
+---------------------+-----------------------------------------------------------------------+
| docs                | Manifest and License                                                  |
|                     |                                                                       |
+---------------------+-----------------------------------------------------------------------+
| filesystem          | Prebuilt Filesystems (both tar and wic images)                        |
|                     |                                                                       |
+---------------------+-----------------------------------------------------------------------+
| linux-devkit        | Linux development kit (tools, compilers etc.)                         |
|                     |                                                                       |
+---------------------+-----------------------------------------------------------------------+
| sitara-apps         | Sample examples and application specific demos                        |
|                     | (GUI composer of benchmark demos)                                     |
+---------------------+-----------------------------------------------------------------------+


Refer :ref:`Release Notes <Release-note-label>` for complete feature-set and further details


**MCU-PLUS-SDK for RTOS/BM**

.. note::
   Processor SDK Linux AM64x contains only the Linux specific source and application intended   
   to runs on A53/Linux core. For R5F and RTOS/BM side source and applications, refer **MCU-PLUS-SDK** 
   package `[Use Link] <http://software-dl.ti.com/mcu-plus-sdk/esd/AM64X/latest/exports/docs/api_guide_am64x/index.html>`__.

**Instructions to set-up CCS**

-  Refer `[Use Link] <http://software-dl.ti.com/mcu-plus-sdk/esd/AM64X/latest/exports/docs/api_guide_am64x/CCS_SETUP_PAGE.html>`__
