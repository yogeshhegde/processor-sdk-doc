************************************
Migration Guide
************************************

.. rubric:: Overview

This page covers migration information for applications built on top
of the Processor SDK Linux AM62A.

Processor SDK Linux AM62A 09.xx Releases
========================================

Processor SDK 09.00
-------------------
- This is the first release in the 2023 LTS stream 6.1 kernel, 2023.04 U-Boot and Yocto Kirkstone/4.0
- ATF 2.8+
- OPTEE 3.20
- Yocto Kirkstone/4.0
- Platforms Supported : AM62A (HS-FS, HS-SE)

.. note::

    - For U-Boot builds, k3-image-gen and core-secdev-k3 are no longer needed
      as **binman** is used instead. Please refer to :ref:`U-Boot build
      instructions<Build-U-Boot-label>` for the updated steps.

    - For Linux builds, generic ``defconfig`` is used instead of custom
      fragments. Please refer to `linux users guide
      <../../../linux/Foundational_Components_Kernel_Users_Guide.html#preparing-to-build>`__
      for build instructions.

Processor SDK Linux AM62A 08.xx Releases
========================================

Processor SDK 08.06
-------------------
- This is the first release of Processor SDK Linux AM62A on 2021 LTS 5.10 kernel, 2021.01 U-Boot
- ATF 2.8+
- OPTEE 3.20
- Yocto Dunfell/3.1
- Platforms Supported : AM62A (HS-FS, HS-SE) with default boot on HS-FS
