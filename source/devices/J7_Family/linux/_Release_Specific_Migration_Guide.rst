.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Migration_Guide

************************************
Processor SDK Linux Migration Guide
************************************

.. rubric:: Overview

This page covers migration information for applications built on top
of the Processor SDK for Linux.

Processor SDK 09.xx Releases
================================

Processor SDK Jacinto 09.02
-------------------------------
- This is the Third release based upon LTS stream 6.1 kernel, 2023.04 U-Boot and Yocto Kirkstone/4.0
- ATF Upgraded to 2.10
- OPTEE Upgarded to 4.1.0-51
- Yocto Kirkstone/4.0
- Platforms Supported : J721E, J7200, J721S2, J784S4, AM68, AM69, J722S

Processor SDK Jacinto 09.01
-------------------------------
- This is the Second release in the 2023 LTS stream 6.1 kernel, 2023.04 U-Boot and Yocto Kirkstone/4.0
- ATF 2.9
- OPTEE 4.0.0
- Yocto Kirkstone/4.0
- Platforms Supported : J721E, J7200, J721S2, J784S4, AM68, AM69

Processor SDK Jacinto 09.00
-------------------------------
- This is the first release in the 2023 LTS stream 6.1 kernel, 2023.04 U-Boot and Yocto Kirkstone/4.0
- ATF 2.8+
- OPTEE 3.20
- Yocto Kirkstone/4.0
- Platforms Supported : J721E, J7200, J721S2, J784S4, AM68, AM69

.. note::

    - For U-Boot builds, k3-image-gen and core-secdev-k3 are no longer needed
      as **binman** is used instead. Please refer to :ref:`U-Boot build
      instructions<Build-U-Boot-label>` for the updated steps.

    - For Linux builds, generic ``defconfig`` is used instead of custom
      fragments. Please refer to `linux users guide
      <../../../linux/Foundational_Components_Kernel_Users_Guide.html#preparing-to-build>`__
      for build instructions.
