.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_MCBSP 

.. rubric:: Introduction
   :name: introduction

The multichannel buffered serial port (MCBSP) peripheral allows direct
interface to other TI DSPs, codecs, and other devices in a system. The
primary use for the MCBSP is for audio interface purposes. The following
sub sections explain the hardware (MCBSP peripheral) and software
context of the MCBSP LLD.

The device driver exposes a set of well-defined APIs which are used by
the application layer to send and receive data via the MCBSP peripheral.
The driver also exposes a set of well-defined OS abstraction APIs which
are used to ensure that the driver is OS independent and portable. The
MCBSP driver uses the CSL MCBSP register layer for all MCBSP MMR access.
The MCBSP driver also interfaces with the EDMA3 library to be able to
transfer data to and from MCBSP peripheral and data memory.

.. rubric:: Driver Configuration
   :name: driver-configuration

The MCBSP Driver initialization API needs to be called only once and it
initializes the internal driver data structures like device objects.
Application developers need to ensure that they call the MCBSP Driver
Init API before they call the MCBSP Device Initialization. Following API
is used to initialize the MCBSP Driver

::

    int32_t mcbspInit (void)

MCBSP Peripheral Configuration
The MCBSP driver provides a sample implementation sequence which
initializes the MCBSP IP block. The MCBSP Device initialization API is
implemented as a sample prototype:

::

    void McbspDevice_init (void)

For details about individual fields of this structure, see the Doxygen
help by opening
PDK_INSTALL_DIR\Packages\ti\drv\MCBSP\docs\doxygen\html\index.html.

.. rubric:: **APIs**
   :name: apis

API reference for application:

::

    #include <ti/drv/MCBSP/mcbsp_drv.h>

.. rubric:: Example
   :name: example

+-----------------------+-----------------------+
| Name                  | Description           |
+=======================+=======================+
| MCBSP_Example         | | Example             |
| application           |   demonstrating       |
|                       |   *sample MCBSP       |
|                       |   loopback* test.     |
|                       |   Reference example   |
|                       |   for developers      |
+-----------------------+-----------------------+

.. rubric:: Additional References
   :name: additional-references

+-----------------------------------+-----------------------------------+
| **Document**                      | **Location**                      |
+-----------------------------------+-----------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\MCBSP\docs\doxygen\html\inde |
|                                   | x.html                            |
+-----------------------------------+-----------------------------------+
| Release Notes                     | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\MCBSP\docs\ReleaseNotes_MCBS |
|                                   | P.pdf                             |
+-----------------------------------+-----------------------------------+

.. raw:: html

