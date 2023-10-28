.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Migration_Guide

************************************
CoreSDK Linux Migration Guide
************************************

.. rubric:: Overview

This page covers migration information for applications built on top
of the Processor SDK for Linux.

Processor CoreSDK 09.xx Releases
================================

Processor CoreSDK Sitara 09.00
------------------------------
- This is the first release in the 2023 LTS stream, with new versions of Kernel, U-boot, toolchain and Yocto branch.
- Kernel 6.1
- U-Boot 2023.04
- Toolchain GCC 11.2
- ATF 2.8+
- OPTEE 3.20
- Yocto Kirkstone/4.0
- Graphics DDK 23.1
- Platforms Supported : AM64x 2.0 (HS-FS), AM62x ( GP, HS-FS, HS-SE), AM62x LP (HS-FS, HS-SE), AM62A (HS-FS, HS-SE)
- Tag Info: 09.00.00.006

Processor CoreSDK Sitara 09.00 Refresh
--------------------------------------
- This is the second release in the 2023 LTS stream, with new versions of Kernel, U-boot, toolchain and Yocto branch.
- Kernel 6.1
- U-Boot 2023.04
- Toolchain GCC 11.4
- ATF 2.9+
- OPTEE 3.20
- Yocto Kirkstone/4.0
- Graphics DDK 23.1
- Platforms Supported : AM62SIP ( HS-FS, HS-SE)
- Tag Info: 09.00.00.011

Processor CoreSDK Sitara 09.00 Refresh
--------------------------------------
- This is the third release in the 2023 LTS stream, with new versions of Kernel, U-boot, toolchain and Yocto branch.
- Kernel 6.1
- U-Boot 2023.04
- Toolchain GCC 11.4
- Yocto Kirkstone/4.0
- Graphics DDK 1.17
- Platforms Supported : AM335x(GP, HS), AM437x (GP, HS)
- Tag Info: 09.01.00.001


.. note::

    - For U-Boot builds, k3-image-gen and core-secdev-k3 are no longer needed
      as **binman** is used instead. Please refer to :ref:`U-Boot build
      instructions<Build-U-Boot-label>` for the updated steps.

    - For Linux builds, generic ``defconfig`` is used instead of custom
      fragments. Please refer to `linux users guide
      <../../../linux/Foundational_Components_Kernel_Users_Guide.html#preparing-to-build>`__
      for build instructions.

Processor CoreSDK Jacinto 09.00
-------------------------------
- This is the first release in the 2023 LTS stream, with new versions of Kernel, U-boot, toolchain and Yocto branch.
- Kernel 6.1
- U-Boot 2023.04
- Toolchain GCC 11.2
- ATF 2.8+
- OPTEE 3.20
- Yocto Kirkstone/4.0
- Graphics DDK 23.1
- Platforms Supported : J721E, J7200, J721S2, J784S4, AM68, AM69

.. note::

    - For U-Boot builds, k3-image-gen and core-secdev-k3 are no longer needed
      as **binman** is used instead. Please refer to :ref:`U-Boot build
      instructions<Build-U-Boot-label>` for the updated steps.

    - For Linux builds, generic ``defconfig`` is used instead of custom
      fragments. Please refer to `linux users guide
      <../../../linux/Foundational_Components_Kernel_Users_Guide.html#preparing-to-build>`__
      for build instructions.
