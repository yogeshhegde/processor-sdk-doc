.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_EDMA3 

| 

.. rubric:: Introduction
   :name: introduction

EDMA3 Low Level Driver is targeted to device drivers and applications
for submitting and synchronizing EDMA3-based DMA transfers.

EDMA3 is a peripheral that supports data transfers between two memory
mapped devices. It supports EDMA as well as QDMA channels for data
transfer.

The EDMA3 LLD consists of an EDMA3 Driver and EDMA3 Resource Manager.
The **EDMA3 Driver** provides functionality that allows device drivers
and applications for submitting and synchronizing with EDMA3 based DMA
transfers. In order to simplify the usage, this component internally
uses the services of the **EDMA3 Resource Manager** and provides one
consistent interface for applications or device drivers.

.. rubric:: Driver Configuration
   :name: driver-configuration

EDMA3 peripheral IP is re-used in different SoCs with only a few
configuration changes:

-  Number of DMA and QDMA channels supported
-  Number of PARAM sets available
-  Number of event queues and transfer controllers etc.

The EDMA3 peripheral is used by other peripherals for their DMA needs
thus the EDMA3 Driver needs to cater to the requirements of device
drivers of these peripherals as well as other application software that
may need to use DMA services. Resources for EDMA driver is managed
through RM sub module within driver.

.. rubric:: **APIs**
   :name: apis

API reference for EDMA3 driver

::

    #include <ti/sdo/edma3/drv/edma3_drv.h>

API reference for EDMA3 Resource Management layer

::

    #include <ti/sdo/edma3/rm/edma3_rm.h>

.. rubric:: Additional References
   :name: additional-references
   
+--------------------+-----------------------------------------------+
|                       EDMA3 Driver Summary                         |
+====================+===============================================+
| Component Type     |    Library                                    |
|                    |                                               |
+--------------------+-----------------------------------------------+
| Install Package    |    EDMA3 Low level drivers                    |
|                    |                                               |
+--------------------+-----------------------------------------------+
| Install Directory  |    <root_install_dir>/edma3_lld_xx_xx_xx_xx   |
|                    |                                               |
+--------------------+-----------------------------------------------+
| Project Type       |    N/A                                        |
|                    |                                               |
+--------------------+-----------------------------------------------+
| Endian Support     |    Little and Big                             |
|                    |                                               |
+--------------------+-----------------------------------------------+
| Library Name       |    edma3_lld_drv.ae66 (little endian),        |
|                    |    edma3_lld_drv.ae66e (big endian),          |
|                    |    edma3_lld_drv.aa15fg (A15),                |
|                    |    edma3_lld_drv.aem4 (M4)                    |
|                    |                                               |
+--------------------+-----------------------------------------------+
| Linker Path        |    <ti/sdo/edma3/drv/lib/[cpu]>               |
|                    |    <ti/sdo/edma3/rm/lib/[soc-evm]>            |
|                    |                                               |
+--------------------+-----------------------------------------------+
| Include Paths      |    <ti/sdo/edma3/drv>                         |
|                    |    <ti/sdo/edma3/rm>                          |
|                    |                                               |
+--------------------+-----------------------------------------------+
| Reference Guides   |    See docs under install directory           |
|                    |                                               |
+--------------------+-----------------------------------------------+
| Additional         |    Programming the EDMA3 using the            |
| Resources          |    Low-Level Driver (LLD)                     |
|                    |                                               |    
+--------------------+-----------------------------------------------+
| License            |    BSD                                        |
|                    |                                               |
+--------------------+-----------------------------------------------+

.. rubric:: EDMA3 sample libs
   :name: edma3_sample_libs
   
+--------------------+-----------------------------------------------+
|                    EDMA3 Driver Sample Summary                     |
+====================+===============================================+
| Component Type     |    Library                                    |
|                    |                                               |
+--------------------+-----------------------------------------------+
| Install Package    |    EDMA3 Low level drivers                    |
|                    |                                               |
+--------------------+-----------------------------------------------+
| Install Directory  |    <root_install_dir>/edma3_lld_xx_xx_xx_xx   |
|                    |                                               |
+--------------------+-----------------------------------------------+
| Project Type       |    N/A                                        |
|                    |                                               |
+--------------------+-----------------------------------------------+
| Endian Support     |    Little and Big                             |
|                    |                                               |
+--------------------+-----------------------------------------------+
| Library Name       |    edma3_lld_drv_sample.ae66 (little endian), |
|                    |    edma3_lld_drv_sample.ae66e (big endian),   |
|                    |    edma3_lld_drv_sample.aa15fg (A15),         |
|                    |    edma3_lld_drv_sample.aem4 (M4)             |
|                    |                                               |
|                    |    edma3_lld_rm_sample.ae66 (little endian),  |
|                    |    edma3_lld_rm_sample.ae66e (big endian),    |
|                    |    edma3_lld_rm_sample.aa15fg (A15),          |
|                    |    edma3_lld_rm_sample.aem4 (M4)              |
|                    |                                               |
+--------------------+-----------------------------------------------+
| Linker Path        |   <ti/sdo/edma3/drv/sample/lib/[soc-evm]/     |
|                    |    [cpu]>                                     |
|                    |   <ti/sdo/edma3/rm/sample/lib/[soc-evm]/[cpu]>|
|                    |                                               |
+--------------------+-----------------------------------------------+
| Include Paths      |    <ti/sdo/edma3/drv>                         |
|                    |    <ti/sdo/edma3/rm>                          |
|                    |                                               |
+--------------------+-----------------------------------------------+
| Reference Guides   |    See docs under install directory           |
|                    |                                               |
+--------------------+-----------------------------------------------+
| Additional         |    Programming the EDMA3 using the            |
| Resources          |    Low-Level Driver (LLD)                     |
|                    |                                               |    
+--------------------+-----------------------------------------------+
| License            |    BSD                                        |
|                    |                                               |
+--------------------+-----------------------------------------------+


.. raw:: html

