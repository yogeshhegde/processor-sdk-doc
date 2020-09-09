.. _foundational-components-optee:

OP-TEE
========================================
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

.. rubric:: Building OP-TEE

::

    $ make CROSS_COMPILE64=aarch64-linux-gnu- PLATFORM=k3 CFG_ARM64_core=y all
