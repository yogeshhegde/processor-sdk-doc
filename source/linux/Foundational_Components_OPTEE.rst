.. _foundational-components-optee:

OP-TEE
======

.. rubric:: Overview

OP-TEE is a Trusted Execution Environment (TEE) designed as companion
to a non-secure Linux kernel running on Arm; Cortex-A cores using the
TrustZone technology. OP-TEE implements TEE Internal Core API v1.1.x
which is the API exposed to Trusted Applications and the TEE Client
API v1.0, which is the API describing how to communicate with a TEE.
Those APIs are defined in the GlobalPlatform API specifications.

.. rubric:: Getting the OP-TEE Source Code

::

    $ git clone https://github.com/OP-TEE/optee_os.git

.. rubric:: Getting Security Dev Tool
    
::
    
    $ git clone git://git.ti.com/security-development-tools/core-secdev-k3.git -b master
    $ export TI_SECURE_DEV_PKG=`pwd`/core-secdev-k3

    
.. rubric:: Building OP-TEE

.. ifconfig:: CONFIG_part_variant in ('AM65X', 'AM64X')

    ::

        on GP
        $ make CROSS_COMPILE64=aarch64-linux-gnu- PLATFORM=k3-am65x CFG_ARM64_core=y

    ::

        on HS
        $ make CROSS_COMPILE64=aarch64-linux-gnu- PLATFORM=k3-am65x CFG_ARM64_core=y
        $ {TI_SECURE_DEV_PKG}/scripts/secure-binary-image.sh ./out/arm-plat-k3/core/tee-pager_v2.bin ./out/arm-plat-k3/core/tee-pager_v2.bin.signed
        
.. ifconfig:: CONFIG_part_variant in ('J721E', 'J7200')

    ::

        on GP
        $ make CROSS_COMPILE64=aarch64-none-linux-gnu- PLATFORM=k3-j721e CFG_ARM64_core=y

    ::

        on HS
        $ make CROSS_COMPILE64=aarch64-linux-gnu- PLATFORM=k3-am65x CFG_ARM64_core=y
        $ {TI_SECURE_DEV_PKG}/scripts/secure-binary-image.sh ./out/arm-plat-k3/core/tee-pager_v2.bin ./out/arm-plat-k3/core/tee-pager_v2.bin.signed

.. ifconfig:: CONFIG_part_variant in ('J721S2')

    ::

        $ make CROSS_COMPILE64=aarch64-none-linux-gnu- PLATFORM=k3-j721e CFG_ARM64_core=y CFG_CONSOLE_UART=0x8
