.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Migration_Guide

************************************
CoreSDK Linux Migration Guide
************************************

.. rubric:: Overview

This page covers migration information for applications built on top
of the Processor SDK for Linux.

Processor CoreSDK 09.xx Releases
================================

Processor CoreSDK Sitara 09.01
------------------------------

- Tag Info: 09.01.00.008
- This is the fifth release in the 2023 LTS stream, with new versions of Kernel, U-boot, toolchain and Yocto branch.
- Platforms Supported : AM62Px (HS-FS, HS-SE), AM62x ( GP, HS-FS, HS-SE), AM62x LP (HS-FS, HS-SE), AM62SIP ( HS-FS, HS-SE), AM64x 2.0 (HS-FS), AM62A (HS-FS, HS-SE)
- Kernel 6.1.46
- U-Boot 2023.04
- ATF 2.9+
- OPTEE 4.0
- Toolchain GCC 11.4
- Yocto Kirkstone/4.0
- Graphics DDK 23.2


- Tag Info: 09.01.00.007
- This is the fourth release in the 2023 LTS stream, with new versions of Kernel, U-boot, toolchain and Yocto branch.
- Platforms Supported : AM65x(GP, HS-SE)
- Kernel 6.1.46
- U-Boot 2023.04
- ATF 2.9+
- OPTEE 4.0
- Toolchain GCC 11.4
- Yocto Kirkstone/4.0
- Graphics DDK 1.17


Processor CoreSDK Sitara 09.00
------------------------------

- Tag Info: 09.01.00.001
- This is the third release in the 2023 LTS stream, with new versions of Kernel, U-boot, toolchain and Yocto branch.
- Platforms Supported : AM335x(GP, HS), AM437x (GP, HS)
- Kernel 6.1
- U-Boot 2023.04
- Toolchain GCC 11.4
- Yocto Kirkstone/4.0
- Graphics DDK 1.17

- Tag Info: 09.00.00.011
- This is the second release in the 2023 LTS stream, with new versions of Kernel, U-boot, toolchain and Yocto branch.
- Platforms Supported : AM62SIP ( HS-FS, HS-SE)
- Kernel 6.1
- U-Boot 2023.04
- Toolchain GCC 11.4
- ATF 2.9+
- OPTEE 3.20
- Yocto Kirkstone/4.0
- Graphics DDK 23.1


- Tag Info: 09.00.00.006
- This is the first release in the 2023 LTS stream, with new versions of Kernel, U-boot, toolchain and Yocto branch.
- Platforms Supported : AM64x 2.0 (HS-FS), AM62x ( GP, HS-FS, HS-SE), AM62x LP (HS-FS, HS-SE), AM62A (HS-FS, HS-SE)
- Kernel 6.1
- U-Boot 2023.04
- Toolchain GCC 11.2
- ATF 2.8+
- OPTEE 3.20
- Yocto Kirkstone/4.0
- Graphics DDK 23.1


.. note::

    - For U-Boot builds, k3-image-gen and core-secdev-k3 are no longer needed
      as **binman** is used instead. Please refer to :ref:`U-Boot build
      instructions<Build-U-Boot-label>` for the updated steps.

    - For Linux builds, generic ``defconfig`` is used instead of custom
      fragments. Please refer to `linux users guide
      <../../../linux/Foundational_Components_Kernel_Users_Guide.html#preparing-to-build>`__
      for build instructions.

