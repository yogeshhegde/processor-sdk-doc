.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_SA 

.. rubric:: Introduction
   :name: introduction

The Security Accelerator (SA) also known as cp_ace (Adaptive
Cryptographic Engine) is designed to provide packet security as part of
IPSEC, SRTP, and 3GPP industry standards. The security accelerator low
level driver (referred to as the module) provides APIs for the
configuration and control of the security accelerator sub-system. The SA
low level driver provides an abstraction layer between the application
and the Security Accelerator Sub System (SASS). It provides both the
system level interface and the channel-level interface with a set of
APIs in the driver.

.. rubric:: Modes of Operation
   :name: modes-of-operation

Security accelerator library (ti.drv.sa) supports below modes

**Protocol Specific Mode**: In this mode, standards such as Ipv4/Ipv6
and 3gpp protocols are supported, where command labels are created based
on the protocols.

| **Data Mode**: In this mode, user can implement a custom/proprietary
  protocol mode with the help of APIs provided by SA LLD

.. rubric:: Driver Configuration
   :name: driver-configuration

The driver configures the SASS subsystem using SA_config_t (system
configuration) and Channel Configuration (Sa_ChanConfig_t) structure.

For details about individual fields of this structure and other APIs,
see the Doxygen help by opening
PDK_INSTALL_DIR\SAckages\ti\drv\SA\docs\doxygen\html\index.html.

.. rubric:: **APIs**
   :name: apis

API reference for application:

::

    #include <ti/drv/SA/Salld.h>

.. rubric:: Example
   :name: example

+-----------------------+-----------------------+-----------------------+
| Name                  | Description           | Expected Results      |
+=======================+=======================+=======================+
| SA_Example            | | Example             | | User observes the   |
| application           |   demonstrating       |   output printed over |
|                       |   *simple IPSec* use  |   the CCS console     |
|                       |   case. Reference     |                       |
|                       |   example for         |                       |
|                       |   developers          |                       |
+-----------------------+-----------------------+-----------------------+
| SA_UnitTestApplicatio | | Unit Test           | | User observes the   |
| n                     |   application to test |   output printed over |
|                       |   all APIs            |   the CCS console     |
+-----------------------+-----------------------+-----------------------+

.. rubric:: Additional References
   :name: additional-references

+-----------------------------------+-----------------------------------+
| **Document**                      | **Location**                      |
+-----------------------------------+-----------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\sa\docs\doxygen\html\index.h |
|                                   | tml                               |
+-----------------------------------+-----------------------------------+
| Release Notes                     | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\sa\docs\ReleaseNotes_SA_LLD. |
|                                   | pdf                               |
+-----------------------------------+-----------------------------------+

|Note|\ **Note:** Although SASS supports 3GPP specific Ciphering and
Authentication algorithms such as Kasumi F8/F9 and Snow3G F8, those
algorithms are locked out in this standard SA LLD distribution. In order
to access 3GPP specific functionalities, one must obtain ETSI licensing
as described at
http://www.etsi.org/services/security-algorithms/cellular-algorithms and
then download the SASS 3GPP Enabler package from TI from the link
http://software-dl.ti.com/libs/sa_3gpp_enabler/latest/index_FDS.html

| 
| Due to export control restrictions, the SA 3GPP Enabler is a seperate
  download from the rest of the PROCESSOR-SDK.

.. raw:: html

