************************************
Migration Guide
************************************

.. rubric:: Overview

This page covers migration information for applications built on top
of the Processor SDK Linux AM64X.

Processor SDK Linux AM64X 09.xx Releases
========================================

Processor SDK 09.00
-------------------
- This is the first release in the 2023 LTS stream 6.1 kernel, 2023.04 U-Boot and Yocto Kirkstone/4.0
- ATF 2.8+
- OPTEE 3.20
- Yocto Kirkstone/4.0
- Platforms Supported : AM64x 2.0 (HS-FS)

.. note::

    - For U-Boot builds, k3-image-gen and core-secdev-k3 are no longer needed
      as **binman** is used instead. Please refer to :ref:`U-Boot build
      instructions<Build-U-Boot-label>` for the updated steps.

    - For Linux builds, generic ``defconfig`` is used instead of custom
      fragments. Please refer to `linux users guide
      <../../../linux/Foundational_Components_Kernel_Users_Guide.html#preparing-to-build>`__
      for build instructions.

Processor SDK Linux AM64X 08.xx Releases
========================================

Processor SDK 08.06
-------------------
- This is the sixth release on 2021 LTS 5.10 kernel, 2021.01 U-Boot
- ATF 2.8+
- OPTEE 3.20
- Yocto Dunfell/3.1
- Platforms Supported : AM64x SR2.0 (HS-FS, HS-SE) with default boot on HS-FS
  
Processor SDK 08.05
-----------------------
- This is the fifth release on 2021 LTS 5.10 kernel, 2021.01 U-Boot
- ATF 2.8+
- OPTEE 3.19+
- Yocto Dunfell/3.1
- Platforms Supported : AM64x ( Including HS-FS )

Processor SDK 08.04
-----------------------
- This is the fourth release on 2021 LTS 5.10 kernel, 2021.01 U-Boot
- ATF 2.7
- OPTEE 3.18
- Yocto Dunfell/3.1
- Platforms Supported : AM64x ( Including HS-FS )


Processor SDK 08.02
-----------------------
- This is the third release on 2021 LTS 5.10 kernel, 2021.01 U-Boot

- Third release on 5.10 kernel and 2021.01 U-boot
- ATF 2.5
- OPTEE 3.12
- Yocto Dunfell/3.1
- NAND boot, Ethernet boot, Secure Boot, ICSSG-Dual Emac

Processor SDK 08.01
-----------------------
- This is the second release on 2021 LTS 5.10 kernel, 2021.01 U-Boot

- Second release on 5.10 kernel and 2021.01 U-boot
- ATF 2.5
- OPTEE 3.12

Processor SDK 08.00
------------------------
- USB DFU boot mode support
- SRAM memory layout during R5 SPL boot stage, has been changed. Please refer :ref:`AM64-SRAM-Layout-label`.

Processor SDK Linux AM64X 07.03.xx Releases
===========================================

Processor SDK 07.03.01
----------------------
- AM64x EVM and SK uses same u-boot binaries for booting.
- Support to build u-boot SPL for both AM64x EVM and SK using same defconfig.

Processor SDK 07.03.00
----------------------
- This is the first release of Processor SDK Linux AM64X. 
