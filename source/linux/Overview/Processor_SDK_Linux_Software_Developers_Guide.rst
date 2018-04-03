**********************************************
Processor SDK Linux Software Developer's Guide
**********************************************

.. rubric:: Welcome to the Processor SDK Linux Software Developer's Guide
   :name: welcome-to-the-processor-sdk-linux-software-developers-guide

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

This information covers Processor SDK 3.3 and above, unless otherwise noted.

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
.. _GPLv3 Disclaimer: Licenses.html#gplv3-disclaimer
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
| `IPC`_        | `OpenVX`_                | `CMEM`_          |                                   |
+---------------+--------------------------+------------------+-----------------------------------+

.. _U-Boot: Foundational_Components.html#processor-sdk-linux-u-boot 
.. _Processor SDK Linux U-Boot: Foundational_Components.html#_processor-sdk-linux-u-boot 
.. _Boot Monitor: Foundational_Components.html#processor-sdk-linux-boot-monitor
.. _Kernel: Foundational_Components.html#processor-sdk-linux-kernel
.. _Processor SDK Linux Kernel: Foundational_Components.html#processor-sdk-linux-kernel
.. _Filesystem: Foundational_Components.html#processor-sdk-linux-filesystem
.. _Processor SDK Linux Filesystem: Foundational_Components.html#processor-sdk-linux-filesystem
.. _Tools: Foundational_Components.html#processor-sdk-linux-tools
.. _Processor SDK Linux Tools: Foundational_Components.html#processor-sdk-linux-tools
.. _OpenCL: http://downloads.ti.com/mctools/esd/docs/opencl/index.html
.. _OpenCV: Foundational_Components.html#processor-sdk-linux-opencv
.. _Graphics & Display: Foundational_Components.html#processor-sdk-linux-graphics-and-display
.. _Multimedia: Foundational_Components.html#processor-sdk-linux-multimedia
.. _Examples, Demos: Examples_and_Demos.html
.. _PRU-ICSS: Industrial_Protocols.html
.. _Virtualization: Foundational_Components.html#processor-sdk-linux-virtualization
.. _IPC: Foundational_Components.html#processor-sdk-linux-ipc
.. _OpenVX: Foundational_Components.html#processor-sdk-linux-openvx
.. _CMEM: Foundational_Components.html#processor-sdk-linux-cmem

+----------------+-------------------------+------------------+-----------------------------------+
| **Industrial Protocols** (more information on each piece of the distribution)                   | 
+================+=========================+==================+===================================+
| `DUAL_EMAC`_   | `HSR\_PRP`_             | `PTP`_           | `RSTP`_                           |
+----------------+-------------------------+------------------+-----------------------------------+
| `CCLINK`_      |                         |                  |                                   |
+----------------+-------------------------+------------------+-----------------------------------+

.. _DUAL_EMAC: Industrial_Protocols.html#dual-emac
.. _HSR\_PRP: Industrial_Protocols.html#hsr-prp
.. _RSTP: Industrial_Protocols.html#rstp
.. _PTP: Industrial_Protocols.html#ptp
.. _CCLINK: Industrial_Protocols.html#cclink

.. rubric:: Feedback
   :name: feedback

If you have feedback, suggestions, or ideas on how to improve the SDK,
it is very appreciated. Please post your ideas to the Linux
forum listed at `Technical Support`_. 
