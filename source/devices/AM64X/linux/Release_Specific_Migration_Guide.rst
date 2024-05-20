************************************
Migration Guide
************************************

.. rubric:: Overview

This page covers migration information for applications built on top
of the Processor SDK Linux AM64X.

Processor SDK Linux AM64X 09.xx Releases
========================================

Processor SDK 09.02.01.10
-------------------------

- This is the fourth release based on the 2023 LTS stream 6.1 kernel, 2023.04 U-Boot and Yocto Kirkstone/4.0
- ATF 2.10
- OPTEE 4.1
- Yocto Kirkstone/4.0
- Platforms Supported : AM64x 2.0 (HS-FS) : `EVM <https://www.ti.com/tool/TMDS64EVM>`__ , `SK <https://www.ti.com/tool/SK-AM64B>`__

Processor SDK 09.02.01.09
-------------------------

- This is the third release based on the 2023 LTS stream 6.1 kernel, 2023.04 U-Boot and Yocto Kirkstone/4.0
- ATF 2.10
- OPTEE 4.1
- Yocto Kirkstone/4.0
- Platforms Supported : AM64x 2.0 (HS-FS) : `EVM <https://www.ti.com/tool/TMDS64EVM>`__ , `SK <https://www.ti.com/tool/SK-AM64B>`__

Processor SDK 09.01
-------------------
- This is the second release based on the 2023 LTS stream 6.1 kernel, 2023.04 U-Boot and Yocto Kirkstone/4.0
- ATF 2.9+
- OPTEE 4.0
- Yocto Kirkstone/4.0
- Platforms Supported : AM64x 2.0 (HS-FS)


Processor SDK 09.00
-------------------
- This is the first release on the 2023 LTS stream 6.1 kernel, 2023.04 U-Boot and Yocto Kirkstone/4.0
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

