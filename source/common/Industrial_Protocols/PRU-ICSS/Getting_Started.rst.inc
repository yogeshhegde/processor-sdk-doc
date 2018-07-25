.. http://processors.wiki.ti.com/index.php/PRU-ICSS_Getting_Started_Guide
.. rubric:: Overview
   :name: overview

The PRU Software Support Package provides support for the PRU-ICSS
Subsystem in AM335x, AM437x, AM57xx, and K2G devices. This package
contains:

-  Support for ARM<->PRU interaction via remoteproc and rpmsg Linux
   drivers

   -  Remoteproc supports basic control functions such as firmware load,
      start/halt, simple debug, and interrupt managing
   -  Rpmsg supports message passing

-  Basic firmware examples showing simple functionality
-  Register header files for easy register programming
-  Library/API for controlling vrings (used for rpmsg)

.. rubric:: Things to Obtain
   :name: things-to-obtain

-  `CCSv7 <http://processors.wiki.ti.com/index.php/Download_CCS#Code_Composer_Studio_Version_7_Downloads>`__
-  `PRU Code Generation
   Tools <http://software-dl.ti.com/codegen/non-esd/downloads/download.htm#PRU>`__
   (you can also get these tools through the CCS App Center)
-  ARM running Linux

   -  `Linux Processor SDK for
      AM335x <http://software-dl.ti.com/processor-sw/esd/PROCESSOR-SDK-LINUX-AM335X/latest/index_FDS.html>`__,
      `Linux Processor SDK for
      AM437x <http://software-dl.ti.com/processor-sw/esd/PROCESSOR-SDK-LINUX-AM437X/latest/index_FDS.html>`__,
      `Linux Processor SDK for
      AM57xx <http://software-dl.ti.com/processor-sw/esd/PROCESSOR-SDK-LINUX-AM57X/latest/index_FDS.html>`__,
      or `Linux Processor SDK for
      K2G <http://software-dl.ti.com/processor-sdk-linux/esd/K2G/latest/index_FDS.html>`__
   -  The PRU Software Support Package is built into the Linux Processor
      SDK in the '<%SDK\_INSTALL\_DIR%>/example-applications/' folder

-  ARM running RTOS

   -  `RTOS Processor SDK for
      AM335x <http://software-dl.ti.com/processor-sw/esd/PROCESSOR-SDK-RTOS-AM335X/latest/index_FDS.html>`__,
      `RTOS Processor SDK for
      AM437x <http://software-dl.ti.com/processor-sw/esd/PROCESSOR-SDK-RTOS-AM437X/latest/index_FDS.html>`__,
      `RTOS Processor SDK for
      AM57xx <http://software-dl.ti.com/processor-sw/esd/PROCESSOR-SDK-RTOS-AM57X/latest/index_FDS.html>`__,
      or `RTOS Processor SDK for
      K2G <http://software-dl.ti.com/processor-sdk-rtos/esd/K2G/latest/index_FDS.html>`__
   -  `PRU Software Support
      Package <https://git.ti.com/pru-software-support-package/pru-software-support-package/trees/master>`__
      - Contains header files and register mappings

| 

.. rubric:: Installation of Tools
   :name: installation-of-tools

Tools installation paths are generally fairly arbitrary, but we do have
a few requirements once you have installed to your preferred directory.

.. rubric:: Linux
   :name: linux

#. Install Processor SDK to the directory of your choosing
   Follow the installation instructions found
   `here <Overview.html#download-and-install-the-sdk>`__.
   Location does not matter, but the default installation directory is
   strongly suggested and makes using the SDK's scripts much easier.
#. Install the PRU Software Support Package into the SDK you chose above
   Starting with Linux Processor SDK v2.0.1.7 the support package is
   built into the SDK at the 'examples-applications/pru-icss-x.y.z/'
   folder
#. (**Optional**) Install CCS to the directory of your choosing
   CCS installation instruction for Linux can be found
   `here <http://processors.wiki.ti.com/index.php/Linux_Host_Support_CCSv7#Installation_Instructions>`__.
   Makefiles are provided (in addition to CCS projects for most
   projects) in order to build all examples in the PRU Software Support
   Package. The ability to build the PRU projects using the Makefiles
   makes CCS completely optional in a Linux environment.

| 

.. rubric:: Windows
   :name: windows

#. There is no longer a standalone installer for the PRU Software
   Support Package
   You must now download the files from the public Git repository
   `here <https://git.ti.com/pru-software-support-package/pru-software-support-package/trees/master>`__.
#. Install CCS to the directory of your choosing
   Installers can be found
   `here <http://processors.wiki.ti.com/index.php/Download_CCS#Code_Composer_Studio_Version_7_Downloads>`__.

| 

.. rubric:: How to Enable PRU Support in Kernel
   :name: how-to-enable-pru-support-in-kernel

| This step is used to enable the remoteproc driver in the Linux kernel.
  Windows users that are loading the PRU through CCS can safely skip
  this step during the development phase.
| Beginning with Linux Processor SDK v2.0.2.11 the remoteproc and rpmsg
  modules are enabled by default and included out of the box in the
  Linux Processor SDK. Therefore, you do not need to make any menuconfig
  changes in order to load firmwares in the PRU cores. If you are using
  an older Linux Processor SDK please see the archive links at the
  bottom of this page.

.. rubric:: How to Begin Programming
   :name: how-to-begin-programming

Programming the PRU core is not terribly different from programming any
other core. Because we now have a C compiler we are able to write
regular C code and have it perform tasks on the PRU cores. A great place
to start development is to take a look at the `Hands-on
Labs <http://processors.wiki.ti.com/index.php/PRU_Training:_Hands-on_Labs>`__ that are provided in
the PRU Software Support Package.

.. rubric:: Register Header Files
   :name: register-header-files

Several register header files were created to help facilitate quick and
easy configuration. In Linux, these are located in the
<SDK\_install\_dir>/example-applications/pru-icss-x.y.z/include
directory by default. In the Git repository these are located in the
include folder. See the `header
files <Industrial_Protocols_PRU-ICSS.html#header-files>`__ page for more information.

| 

.. rubric:: Special Considerations
   :name: special-considerations

There are a couple of special CPU registers available with different
functionality.

-  Writes to R30 control the General Purpose Output pins, and reads
   allow the user to determine the current state of those pins
-  R31 is used to read General Purpose Input pins as well as the status
   of the two PRU host interrupts (bits 30 and 31)

   -  Writes to R31 are used to generate interrupts - see the
      device-specific TRM for more information on how these work.

.. rubric:: What Next?
   :name: what-next

For support please post questions on the TI E2E forum for `Sitara
devices <http://e2e.ti.com/support/arm/sitara_arm/default.aspx>`__.

