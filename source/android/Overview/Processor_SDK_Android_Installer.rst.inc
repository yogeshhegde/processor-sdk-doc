Install the Android SDK
======================================

.. rubric:: Overview
   :name: install-the-android-sdk-overview

The Processor SDK Installer
(ti-processor-sdk-android-am57xx-evm-xx.xx.xx.xx-Linux-x86-Install.bin)
will install the necessary components to start your development on the
TI microprocessor. The SDK consists of source for the universal
bootloader (u-boot), the Linux kernel, toolchain and board support
package, ease of use scripts and documentation. The Android file
system sources can also be cloned to the SDK using the provided repo
tool and manifest file.
The Processor SDK was built and tested against a specific Linux
Distribution name and version, Ubuntu 14.04. Note this **does not**
prevent the user from installing the SDK on other Linux distributions.

| 

.. rubric:: How to Get the SDK Installer
   :name: how-to-get-the-sdk-installer

Download from the `Android SDK download
page <http://software-dl.ti.com/processor-sdk-android/esd/AM57X/latest/index_FDS.html>`__.
This will always host the latest version of SDK.

| 

.. rubric:: How to Run the SDK Installer
   :name: how-to-run-the-sdk-installer

Make sure that the execute permissions are set. Bring up a terminal
window and change directories to the where the installer is located
(probably the Downloads directory if downloaded) and run the following
commands:

.. code-block:: bash
   
   chmod +x
   ./ti-processor-sdk-android-am57xx-evm-xx.xx.xx.xx-Linux-x86-Install.bin**

Alternatively, you can give execute permissions and run the SDK
Installer by double clicking on it within your Linux host PC.

.. note::
   If nothing seems to happen, you are probably running a 32-bit version of
   Linux. The installer is 64-bit, and will not execute properly.

| 

.. rubric:: Additional Installer Options
   :name: additional-installer-options

Invoking the installer with argument --help will list available options
for the installer (e.g. text installer, etc.):

.. code-block:: bash
   
   ./ti-processor-sdk-linux-[platformName]-evm-xx.xx.xx.xx-Linux-x86-Install.bin --help


.. rubric:: SDK Installer Execution Steps
   :name: sdk-installer-execution-steps

#. **Environment Support Message**
   User is to acknowledge the host operating system recommendations.
#. **GPLv3 Components Notice**
   User is to acknowledge the use of GPLv3 components in the SDK.
#. **Directory Install Location**
   The user will be prompted for a location on where to put the
   Processor SDK. An example is given below.
#. **Review and Confirm**
   User is to confirm if loading the Processor SDK is ok. This is
   important to note if the user is trying to over-install on an
   existing directory and has made changes to the directory.
#. **Installation of software**
   The software is installed.

.. rubric:: Where to install the Processor SDK package
   :name: where-to-install-the-processor-sdk-package

The default selection of where to install is the user's home directory.
In this particular example the name of the user is 'sitara'.

.. Image:: ../images/Processor_sdk_android_select_directory.png


