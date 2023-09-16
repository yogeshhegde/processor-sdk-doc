.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_SA

Overview
--------

Introduction
^^^^^^^^^^^^

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

**Data Mode**: In this mode, user can implement a custom/proprietary
protocol mode with the help of APIs provided by SA LLD

User Interface
--------------

Driver Configuration
^^^^^^^^^^^^^^^^^^^^^

The driver configures the SASS subsystem using SA_config_t (system
configuration) and Channel Configuration (Sa_ChanConfig_t) structure.

For details about individual fields of this structure and other APIs,
see the Doxygen help by opening
PDK_INSTALL_DIR\\packages\\ti\\drv\\SA\\docs\\doxygen\\html\\index.html.

APIs
^^^^^

API reference for application:

::

    #include <ti/drv/SA/Salld.h>

Application
------------

Examples
^^^^^^^^

+-----------------------+-----------------------+-----------------------+----------------------------------+----------------------------------+
| Name                  | | Description         | | Expected Results    | | List of SOCs with              | | List of SOCs with              |
|                       |                       |                       | Application Build Support as CCS | Applications Build Support Make  |
+=======================+=======================+=======================+==================================+==================================+
| SA_Example            | | CCS Project Example | | User observes the   | | K2HK, K2L, K2E, C6678          |    None                          |
| application           |   demonstrating       |   output printed over |                                  |                                  |
|                       |   *simple IPSec* use  |   the CCS console     |                                  |                                  |
|                       |   case. Reference     |                       |                                  |                                  |
|                       |   example for         |                       |                                  |                                  |
|                       |   developers          |                       |                                  |                                  |
+-----------------------+-----------------------+-----------------------+----------------------------------+----------------------------------+
| SA_UnitTestApplication| | Unit Test           | | User observes the   | | K2HK, K2L, K2E, C6678, K2G     |    AM65XX                        |
|                       |   application to test |   output printed over |                                  |                                  |
|                       |   all APIs            |   the CCS console     |                                  |                                  |
+-----------------------+-----------------------+-----------------------+----------------------------------+----------------------------------+

**NOTE**
: SA Unit Test applications are makefile based for AM65XX. Note that the application built, can be loaded on to CCS.

Building SA Examples/Unit Test
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

- Setup the build environment `SetupBuildEnvironment <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/index_overview.html#setup-environment>`__
- Follow the steps `SDK example and test CCS Project Creation <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/index_overview.html#pdk-example-and-test-project-creation>`__  for creating the CCS based example and test projects creation
- Create make based test application executables following the link `Building the component and make based test application <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/index_overview.html#rebuilding-components>`__. Once the build environment is set, issue the following commands:
    -  cd <pdk>/packages/
    -  To build: make sa
    -  To clean: make sa_clean


Additional References
---------------------

+-----------------------------------+-----------------------------------------+
| **Document**                      | **Location**                            |
+-----------------------------------+-----------------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)\\packages\\ti     |
|                                   | \\drv\\sa\\docs\\doxygen\\html\\index.h |
|                                   | tml                                     |
+-----------------------------------+-----------------------------------------+
| Release Notes                     | $(TI_PDK_INSTALL_DIR)\\packages\\ti     |
|                                   | \\drv\\sa\\docs\\ReleaseNotes_SA_LLD.   |
|                                   | pdf                                     |
+-----------------------------------+-----------------------------------------+

.. note::

   Although SASS supports 3GPP specific Ciphering and
   Authentication algorithms such as Kasumi F8/F9 and Snow3G F8, those
   algorithms are locked out in this standard SA LLD distribution. In order
   to access 3GPP specific functionalities, one must obtain ETSI licensing
   as described at
   http://www.etsi.org/services/security-algorithms/cellular-algorithms and
   then download the SASS 3GPP Enabler package from TI from the link
   http://software-dl.ti.com/libs/sa_3gpp_enabler/latest/index_FDS.html


Due to export control restrictions, the SA 3GPP Enabler is a seperate
download from the rest of the PROCESSOR-SDK.

|

