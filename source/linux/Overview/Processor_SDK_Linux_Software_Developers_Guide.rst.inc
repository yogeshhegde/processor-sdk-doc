**********************************************
Processor SDK Linux Software Developer's Guide
**********************************************

.. rubric:: Welcome to the Processor SDK Linux Software Developer's Guide
   :name: welcome-to-the-processor-sdk-linux-software-developers-guide

.. note::
   | Processor SDK documentation is now created from reStructuredText sources using
     Sphinx, and hosted on ti.com instead of processors wiki - starting
     4.3 release.
   |
   | We intend to retain the look and feel of the content
     to make this transition seamless, and yet provide the users with the benefits of
     consuming the content generated with emergent documentation tools.
   |
   | Wiki content will be left for reference during this migration process to find any missing old content. Feel free to drop us a note using the
     forums listed at `Technical Support`_, and we would love to hear from you.
   |
   | Old Wiki Documentation links from previous releases:
   |    - `Wiki Software Developer's Guide <http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Software_Developer%E2%80%99s_Guide>`__.
   |    - `Wiki Getting Started Guide <http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Getting_Started_Guide>`__.
   |
  
Thank you for choosing to evaluate one of our TI Processors `ARM
microprocessors <http://www.ti.com/lsds/ti/dsp/arm.page>`__. Please
**bookmark** this page and refer back to it as needed. It is designed to
quickly provide the information you need most while evaluating a TI
microprocessor, specifically running one of the Software Architectures
available, embedded Linux. We are always striving to improve this
product. Please let us know if you have :ref:`ideas or
suggestions <Feedback>`.


.. rubric:: Version
   :name: version

This information covers Processor SDK 4.3 and above, unless otherwise noted.

+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| **Processor SDK Linux**                                                                                                                                |
+========================================================================+===============================================================================+
| `Getting Started Guide`_  <-- **Start Here**                           | `How To Guides`_                                                              | 
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| `Supported Platforms and Versions`_                                    | `Linux Software Stack`_                                                       |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| `Directory Structure Overview`_                                        | `Building the SDK`_                                                           |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| `Release Notes`_                                                       | `Migration Guide`_                                                            |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| `GPLv3 Disclaimer`_                                                    | `MCSDK to Processor SDK Migration Guide`_                                     |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+
| `Technical Support`_                                                   | `Training <https://training.ti.com/processor-sdk-training-series>`__          |
+------------------------------------------------------------------------+-------------------------------------------------------------------------------+

.. _Getting Started Guide: Overview.html#processor-sdk-linux-getting-started-guide
.. _Supported Platforms and Versions: Release_Specific.html#supported-platforms-and-versions
.. _Hardware platform: Release_Specific.html#supported-platforms-and-evms
.. _Release Notes: Release_Specific.html#processor-sdk-linux-release-notes
.. _Technical Support: Overview.html#processor-sdk-linux-technical-support
.. _Directory Structure Overview: Overview.html#processor-sdk-linux-directory-structure
.. _Linux Software Stack: Overview.html#processor-sdk-linux-software-stack
.. _Embedded Linux System: Overview.html#processor-sdk-linux-software-stack
.. _Building the SDK: Overview.html#processor-sdk-linux-building-the-sdk
.. _Migration Guide: Release_Specific.html#processor-sdk-linux-migration-guide
.. _MCSDK to Processor SDK Migration Guide: Release_Specific.html#mcsdk-to-processor-sdk-migration-guide
.. _GPLv3 Disclaimer: Overview.html#plsdk-gplv3-disclaimer-label
.. _How To Guides: Processor_Linux_SDK_How_To_Guides.html
.. _Processor SDK Linux How-To Guides: Processor_Linux_SDK_How_To_Guides.html
.. _Linux SDK Software Developer's Guide: Overview.html#processor-sdk-linux-software-developers-guide
.. _Processor SDK Linux Software Developer's Guide: Overview.html#processor-sdk-linux-software-developers-guide
.. _Developing with the Linux SDK: Overview.html#start-your-linux-development
.. _Creating a SD Card with Windows: Overview.html#windows-sd-card-creation-guide
.. _Install the Linux SDK: Overview.html#download-and-install-the-sdk
.. _SDK Create SD Card Script: Overview.html#linux-sd-card-creation-guide
.. _Program EVM User Guide: Overview.html#processor-sdk-linux-program-evm
.. _Run the Setup.sh Script: Overview.html#processor-sdk-linux-setup-script-overview
.. _top-level Makefile: Overview.html#processor-sdk-linux-top-level-makefile
.. _SD Card using default images: Overview.html#processor-sdk-linux-sd-card-using-default-images
.. _SD Card using custom images: Overview.html#processor-sdk-linux-sd-card-using-custom-images
.. _SD Card using parition tarballs: Overview.html#processor-sdk-linux-sd-card-using-partition-tarballs
.. _Installing SD Card Content: :Overview.html#processor-sdk-linux-installing-sd-card-content
.. _SD Card common steps: Overview.html#processor-sdk-linux-sd-card-common-steps
 
+---------------+--------------------------+------------------+-----------------------------------+
| **Foundational Components** (more information on each piece of the distribution)                |
+===============+==========================+==================+===================================+
| `U-Boot`_     | `Boot Monitor`_          | `Kernel`_        | `Filesystem`_                     |
+---------------+--------------------------+------------------+-----------------------------------+
| `Tools`_      | `OpenCL`_                | `OpenCV`_        | `Graphics & Display`_             |
+---------------+--------------------------+------------------+-----------------------------------+
| `Multimedia`_ | `Examples, Demos`_       | `PRU-ICSS`_      | `Virtualization`_                 |
+---------------+--------------------------+------------------+-----------------------------------+
| `IPC`_        | `OpenVX`_                | `CMEM`_          | `TIDL`_                           |
+---------------+--------------------------+------------------+-----------------------------------+

.. _U-Boot: Foundational_Components_U-Boot.html
.. _Processor SDK Linux U-Boot: Foundational_Components_U-Boot.html
.. _Boot Monitor: Foundational_Components_Boot_Monitor.html
.. _Kernel: Foundational_Components_Kernel.html
.. _Processor SDK Linux Kernel: Foundational_Components_Kernel.html
.. _Filesystem: Foundational_Components_Filesystem.html
.. _Processor SDK Linux Filesystem: Foundational_Components_Filesystem.html
.. _Tools: Foundational_Components_Tools.html
.. _Processor SDK Linux Tools: Foundational_Components_Tools.html
.. _OpenCL: http://downloads.ti.com/mctools/esd/docs/opencl/index.html
.. _OpenCV: Foundational_Components_OpenCV.html
.. _Graphics & Display: Foundational_Components_Graphics.html
.. _Multimedia: Foundational_Components_Multimedia.html
.. _Examples, Demos: Examples_and_Demos.html
.. _PRU-ICSS: Industrial_Protocols.html
.. _Virtualization: Foundational_Components_Virtualization.html
.. _IPC: Foundational_Components_IPC.html
.. _OpenVX: Foundational_Components_OpenVX.html
.. _CMEM: Foundational_Components_CMEM.html
.. _TIDL: Foundational_Components_TIDL.html

+----------------+-------------------------+------------------+-----------------------------------+
| **PRU-ICSS Protocols** (more information on each piece of the distribution)                     | 
+================+=========================+==================+===================================+
| `DUAL_EMAC`_   | `HSR\_PRP`_             | `PTP`_           | `RSTP`_                           |
+----------------+-------------------------+------------------+-----------------------------------+
| `CCLINK`_      | `SORTE`_                |                  |                                   |
+----------------+-------------------------+------------------+-----------------------------------+

.. _DUAL_EMAC: Industrial_Protocols_PRU-ICSS.html
.. _HSR\_PRP: Industrial_Protocols_HSR_PRP.html
.. _RSTP: Industrial_Protocols_RSTP.html
.. _PTP: Industrial_Protocols_PTP.html
.. _CCLINK: Industrial_Protocols_CCLINK.html
.. _SORTE: Industrial_Protocols_SORTE.html

.. rubric:: Feedback
   :name: feedback

If you have feedback, suggestions, or ideas on how to improve the SDK,
it is very appreciated. Please post your ideas to the Linux
forum listed at `Technical Support`_. 
