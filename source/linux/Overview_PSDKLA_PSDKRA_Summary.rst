.. include:: /replacevars.rst.inc

Processor SDK RTOS Automotive
=============================

Processor SDK RTOS Automotive (PSDKRA) is a companion SDK to PSDKLA on
the |__PART_FAMILY_NAME__| family of devices.  In order to use some SoC
features from the core running Linux, one needs to download and install the PSDKRA package.
After downloading this PSDKRA package, refer to the PSDKRA top level user
guide, ${PSDKRA_PATH}/index.html, for more details.

.. ifconfig:: CONFIG_part_family in ('J7_family')

    Features provided by PSDKRA that can be accessed from Linux A72 core on
    Jacinto 7 family of devices are listed below:

    -   TIDL on C7x
    -   Vision pre/post processing functions on C6x
    -   Vision HW accelerators (VPAC/DMPAC) on R5F
    -   CSI2RX on R5F
    -   Remote display on R5F
    -   Ethernet switch on R5F
    -   MCU/AutoSAR MCAL on R5F
    -   OpenVX on Linux A72 and RTOS C6x, C7x, R5F
    -   Deep learning demos on Linux A72
    -   Surround view demos on Linux A72

.. important::
    This package is NOT included in PSDKLA installer and needs to be downloaded separately.

.. ifconfig:: CONFIG_part_family in ('J7_family')

    +---------------+---------------------------+
    | Version       | 07_00_00_XX               |
    +---------------+---------------------------+
    | Release Notes | ${PSDKRA_PATH}/index.html |
    +---------------+---------------------------+
    | User Guide    | ${PSDKRA_PATH}/index.html |
    +---------------+---------------------------+

