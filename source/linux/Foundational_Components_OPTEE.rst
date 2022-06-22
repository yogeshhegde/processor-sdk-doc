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

Official OPTEE documentation `here <https://optee.readthedocs.io/en/latest/>`__.

.. rubric:: Getting the OP-TEE Source Code

::

    $ git clone https://github.com/OP-TEE/optee_os.git

.. rubric:: Getting Security Dev Tool
    
::
    
    $ git clone git://git.ti.com/security-development-tools/core-secdev-k3.git -b master
    $ export TI_SECURE_DEV_PKG=`pwd`/core-secdev-k3
    
.. rubric:: Building OP-TEE

.. ifconfig:: CONFIG_part_variant in ('AM65X')

    On GP
    ::

        $ make CROSS_COMPILE64=aarch64-none-linux-gnu- PLATFORM=k3-am65x CFG_ARM64_core=y

    With debug parameters
    ::

        $ make CROSS_COMPILE64=aarch64-none-linux-gnu- PLATFORM=k3-am65x CFG_ARM64_core=y CFG_TEE_CORE_LOG_LEVEL=2 CFG_TEE_CORE_DEBUG=y

    Sign image for HS
    ::

        $ {TI_SECURE_DEV_PKG}/scripts/secure-binary-image.sh ./out/arm-plat-k3/core/tee-pager_v2.bin ./out/arm-plat-k3/core/tee-pager_v2.bin.signed

.. ifconfig:: CONFIG_part_variant in ('AM64X')

    On GP
    ::

        $ make CROSS_COMPILE64=aarch64-none-linux-gnu- PLATFORM=k3-am64x CFG_ARM64_core=y

    With debug parameters
    ::

        $ make CROSS_COMPILE64=aarch64-none-linux-gnu- PLATFORM=k3-am64x CFG_ARM64_core=y CFG_TEE_CORE_LOG_LEVEL=2 CFG_TEE_CORE_DEBUG=y

    Sign image for HS
    ::

        $ {TI_SECURE_DEV_PKG}/scripts/secure-binary-image.sh ./out/arm-plat-k3/core/tee-pager_v2.bin ./out/arm-plat-k3/core/tee-pager_v2.bin.signed

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    On GP
    ::

        $ make CROSS_COMPILE64=aarch64-none-linux-gnu- PLATFORM=k3-am62x CFG_ARM64_core=y

    With debug parameters
    ::

        $ make CROSS_COMPILE64=aarch64-none-linux-gnu- PLATFORM=k3-am62x CFG_ARM64_core=y CFG_TEE_CORE_LOG_LEVEL=2 CFG_TEE_CORE_DEBUG=y

    Sign image for HS
    ::

        $ {TI_SECURE_DEV_PKG}/scripts/secure-binary-image.sh ./out/arm-plat-k3/core/tee-pager_v2.bin ./out/arm-plat-k3/core/tee-pager_v2.bin.signed

.. ifconfig:: CONFIG_part_variant in ('J721E', 'J7200')

    On GP
    ::

        $ make CROSS_COMPILE64=aarch64-none-linux-gnu- PLATFORM=k3-j721e CFG_ARM64_core=y

    Sign image for HS
    ::

        $ {TI_SECURE_DEV_PKG}/scripts/secure-binary-image.sh ./out/arm-plat-k3/core/tee-pager_v2.bin ./out/arm-plat-k3/core/tee-pager_v2.bin.signed

.. ifconfig:: CONFIG_part_variant in ('J721S2')

    On GP
    ::

        $ make CROSS_COMPILE64=aarch64-none-linux-gnu- PLATFORM=k3-j721s2 CFG_ARM64_core=y CFG_CONSOLE_UART=0x8

    Sign image for HS
    ::

        $ {TI_SECURE_DEV_PKG}/scripts/secure-binary-image.sh ./out/arm-plat-k3/core/tee-pager_v2.bin ./out/arm-plat-k3/core/tee-pager_v2.bin.signed

.. ifconfig:: CONFIG_part_variant in ('AM62X', 'AM64X')
    
    .. note::
        
        If building for an HS device, tee-pager_v2.bin must be signed before it is packaged in tispl.bin. To sign the binary, the script secure-binary-image.sh is called as shown above with the path to the newly built binary: tee-pager_v2.bin (the first argument) and with the expected output binary path and name: tee-pager_v2.bin.signed (the second argument). Once the binary is signed, continue with the HS boot instructions found here: :ref:`Build-U-Boot-label`.

    Exptected binary output

        - Generated binary: tee-pager_v2.bin
        - Binary saved saved in: <path-to-optee>/out/arm-plat-k3/core

    Integrate binary output into U-boot

        - Go to u-boot folder <path-to-u-boot>
        - Re-build U-boot with A53 instructions found under: :ref:`Build-U-Boot-label`, but with the TEE parameter pointing to the newly built tee-pager_v2.bin. i.e. TEE=<path-to-optee>/out/arm-plat-k3/core/tee-pager_v2.bin

    .. note::

        tee-pager_v2.bin may be called bl32.bin in other documentation.