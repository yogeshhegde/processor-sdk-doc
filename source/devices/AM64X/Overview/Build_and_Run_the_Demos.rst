Build and Run the Demos
======================================

**Build Instructions**

Processor SDK AM64x support GNU make based build system. Refer to
/<INSTALL-DIR>/sitara-apps/makerules folder for all supported demos and build targets

Below is a list of build targets supported by processor SDK AM64x:

+-----------------------+-----------------------------------------------------------------------+
| **Build Target**      |   **Description**                                                     |
+-----------------------+-----------------------------------------------------------------------+
| benchmark_demo_build  | Benchmarking demos                                                    |
+-----------------------+-----------------------------------------------------------------------+


**Benchmark demos**

-  Refer :ref:`[Benchmark Demo User Guide] <Benchmark-Demo-User-Guide-label>`



**How to build dependent components**

Set-up Linux build environment to rebuild kernel, u-boot & DTB

    ::

        $ cd /<INSTALL-DIR>/bin/scripts
        $ ./setup-ubuntu.sh

Refer the respective user guides to build Linux and other RTOS/BM packages

-  For Linux Kernel, u-boot & DTB     `[Use Link] <../index_Linux.html>`__
-  For RTOS/BM source (MCU+ SDK)      `[Use Link] <http://software-dl.ti.com/mcu-plus-sdk/esd/AM64X/latest/exports/docs/api_guide_am64x/index.html>`__
-  For Industrial Protocols (ECAT)    `[Use Link] <http://software-dl.ti.com/mcu-plus-sdk/esd/AM64X/latest/exports/docs/api_guide_am64x/INDUSTRIAL_PROTOCOLS.html>`__
-  For Industrial Drives (EnDAT,HDSL) `[Use Link] <http://software-dl.ti.com/mcu-plus-sdk/esd/AM64X/latest/exports/docs/api_guide_am64x/EXAMPLES_MOTORCONTROL.html>`__



