Download and Install the SDK
======================================

.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Installer
.. rubric:: Overview
   :name: overview

The Processor SDK Installer
(ti-processor-sdk-linux-[platformName]-evm-xx.xx.xx.xx-Linux-x86-Install.bin)
will install the necessary components to start your development on the
TI microprocessor. The SDK consists of source for the Matrix App
launcher starting point application, a development filesystem, a
target filesystem, example applications, toolchain and board support
package, ease of use scripts and documentation.
The Processor SDK now includes the ARM GCC toolchain.  The
Processor SDK was built and tested against a specific Linux
Distribution name and version, Ubuntu 16.04 and 18.04. Note this
**does not** prevent the user from installing the SDK on other Linux
distributions.

| 

.. rubric:: How to Get the SDK Installer
   :name: how-to-get-the-sdk-installer

There are two ways you can get the installer:

1. From a file downloaded from the `SDK download
   page <http://www.ti.com/lsds/ti/tools-software/processor_sw.page>`_.
   This will always host the latest version of SDK.

   .. note::
      The second way below is not applicable to K2H/K2K, K2E, and K2L
      platforms, which are using SD card.

2. From the SD Card included with a TI EVM. This may not be the latest
   version of the SDK. We recommend checking the above site and using the
   latest version if at all possible. Before running the SDK Installer from 
   the SD card, the SD Card from the EVM box needs to be mounted to your 
   Linux Host PC (using a USB SD Card reader).  The SDK Installer is found 
   in the START\_HERE partition of the SD card.

| 

.. rubric:: How to Run the SDK Installer
   :name: how-to-run-the-sdk-installer

Make sure that the execute permissions are set. Bring up a terminal
window and change directories to the where the installer is located
(probably the Downloads directory if downloaded or the START\_HERE
partition mounted from the SD Card) and run the following commands:

**chmod +x
./ti-processor-sdk-linux-[platformName]-evm-xx.xx.xx.xx-Linux-x86-Install.bin**
**./ti-processor-sdk-linux-[platformName]-evm-xx.xx.xx.xx-Linux-x86-Install.bin**
| 

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

**./ti-processor-sdk-linux-[platformName]-evm-xx.xx.xx.xx-Linux-x86-Install.bin
--help**
| 

.. rubric:: SDK Installer Execution Steps
   :name: sdkinstaller-execution-steps

1. **Confirm**
   User is to confirm if loading the Processor SDK is ok. This is
   important to note if the user is trying to over-install on an existing
   directory and has made changes to the directory.
2. **Directory Install Location**
   The user will be prompted for a location on where to put the Processor
   SDK. An example is given below.
3. **Installation of software**
   The software is installed.

| 

.. rubric:: Where to install the Processor SDK package
   :name: where-to-install-the-processor-sdk-package

The default selection of where to install is the user's home directory.
In this particular example the name of the user is 'sitara'.

.. Image:: ../images/Processor_sdk_select_directory.png

| 

