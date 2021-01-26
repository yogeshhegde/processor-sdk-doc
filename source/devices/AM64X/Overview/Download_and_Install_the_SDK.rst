.. include:: /replacevars.rst.inc

.. _download-and-install-sdk:

Download and Install the SDK
======================================

The Processor SDK Sitara AM64x Installer will install the necessary components
to start your development on the TI microprocessor.

**Processor SDK SITARA AM64x Release has installers for both Linux and Windows.**

+------------------------------------------+-----------------------------------------------------------------------+
| **Installer Details**                    |   **Installers Name**                                                 |
+------------------------------------------+-----------------------------------------------------------------------+
| Linux + RTOS Installer (Windows version) | processor_sdk_sitara_am64x_xx_yy_zz_nn-windows-x64-installer.exe      |
+------------------------------------------+-----------------------------------------------------------------------+
| Linux + RTOS Installer (Linux version)   | processor_sdk_sitara_am64x_xx_yy_zz_nn-linux-x64-installer.run        |
+------------------------------------------+-----------------------------------------------------------------------+
| Linux only Installer   (Linux version)   | processor_sdk_sitara_am64x_linux_xx_yy_zz_nn-linux-x64-installer.run  |
+------------------------------------------+-----------------------------------------------------------------------+

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
   For windows installer, always install the SDK in C:/ti. Do not install in any
   deeper directory structure, because the build might fail due to the 260
   character path length limit in Windows operating system.

.. note::
   As a part of the installation, the packaging will run a script to configure your
   environment and download the Linux devkit.  This will cause the installation to
   continue for roughly a minute even after it shows that it has reached 100%.

.. note::
   If nothing seems to happen, your computer may be running a 32-bit version of
   its operating system. The installer is 64-bit, and will not execute properly.

**Package Overview**

This AM64x Software development kit contains Linux, RTOS and Baremetal device
drivers, industrial protocols, industrial drives, sample examples and
application specific demos.  The SDK has the below folder structure


+---------------------+-----------------------------------------------------------------------+
| **Folder Name**     |   **Description**                                                     |
+---------------------+-----------------------------------------------------------------------+
| linux               | Linux board supported packages (Linux kernel and u-boot in source),   |
|                     | linux-devkit, prebuilt-images, file-system,                           |
|                     | resource-partitioning tool, set-up scripts,                           |
+---------------------+-----------------------------------------------------------------------+
| rtos                | RTOS/BM platform development kit, industrial protocols and drives,    |
|                     | RTOS build tools                                                      |
+---------------------+-----------------------------------------------------------------------+
| sitara-apps         | Sample examples and                                                   |
|                     | application specific demos (servo drive & benchmarking demos)         |
+---------------------+-----------------------------------------------------------------------+


Refer to the :ref:`Release Notes <Release-note-label>` for complete feature-set and further details


**Instructions to set-up CCS**

-  Refer /<INSTALL-DIR>/rtos/pdk_am64x_xx_xx_xx_xx/docs/userguide/am64x/ccs_setup_am64x.html - `[Use Link] <../../rtos/pdk_am64x/docs/userguide/am64x/ccs_setup_am64x.html>`__
