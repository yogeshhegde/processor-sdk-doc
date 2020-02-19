Thank you for choosing to evaluate one of our TI Processors `ARM
microprocessors <http://www.ti.com/lsds/ti/dsp/arm.page>`__. It is
designed to quickly provide the information you need most while evaluating a TI
microprocessor, specifically running one of the Software Architectures
available, embedded Linux. We are always striving to improve this
product. Please let us know if you have :ref:`ideas or
suggestions <Feedback>`.


.. ifconfig:: CONFIG_sdk in ('PLSDK')

    +------------------------------------------------------------------------+-------------------------------------------------------------------------------+
    | **Processor SDK Linux**                                                                                                                                |
    +========================================================================+===============================================================================+
    | `Getting Started Guide`_  <-- **Start Here**                           | `How To Guides`_                                                              |
    +------------------------------------------------------------------------+-------------------------------------------------------------------------------+
    | `Supported Platforms and Versions`_                                    | `Linux Software Stack`_                                                       |
    +------------------------------------------------------------------------+-------------------------------------------------------------------------------+
    | `Directory Structure Overview`_                                        | `Building the SDK`_                                                           |
    +------------------------------------------------------------------------+-------------------------------------------------------------------------------+
    | `Release Notes <Release_Specific_PLSDK_Release_Notes.html>`_           | `Migration Guide`_                                                            |
    +------------------------------------------------------------------------+-------------------------------------------------------------------------------+
    | `GPLv3 Disclaimer`_                                                    | `Training <https://training.ti.com/processor-sdk-training-series>`__          |
    +------------------------------------------------------------------------+-------------------------------------------------------------------------------+
    | `Technical Support`_                                                   |                                                                               |
    +------------------------------------------------------------------------+-------------------------------------------------------------------------------+

.. ifconfig:: CONFIG_sdk in ('PSDKLA')

    +----------------------------------------------------------------+----------------------------------------------------------------------+
    |           **Processor SDK Linux**                              |                                                                      |
    +================================================================+======================================================================+
    | `Getting Started Guide`_  <-- **Start Here**                   | `Directory Structure Overview`_                                      |
    +----------------------------------------------------------------+----------------------------------------------------------------------+
    | `Release Notes <Release_Specific_PSDKLA_Release_Notes.html>`__ | `How To Guides`_                                                     |
    +----------------------------------------------------------------+----------------------------------------------------------------------+
    | `Examples and Demos`_                                          | `Building the SDK`_                                                  |
    +----------------------------------------------------------------+----------------------------------------------------------------------+
    | `Linux Software Stack`_                                        | `GPLv3 Disclaimer`_                                                  |
    +----------------------------------------------------------------+----------------------------------------------------------------------+
    | `Technical Support`_                                           | `Training <https://training.ti.com/processor-sdk-training-series>`__ |
    +----------------------------------------------------------------+----------------------------------------------------------------------+

.. _Getting Started Guide: Overview_Getting_Started_Guide.html
.. _Directory Structure Overview: Overview_Directory_Structure_Overview.html
.. _Building the SDK: Overview_Building_the_SDK.html
.. _GPLv3 Disclaimer: Overview_GPLv3_Disclaimer.html
.. _Technical Support: Overview_Technical_Support.html

.. _Supported Platforms and Versions: Release_Specific_Supported_Platforms_and_Versions.html
.. _Hardware platform: Release_Specific_Supported_Platforms_and_Versions.html#supported-platforms-and-evms
.. _Linux Software Stack: Overview_Software_Stack.html
.. _Embedded Linux System: Overview_Software_Stack.html
.. _Migration Guide: Release_Specific_Migration_Guide.html
.. _How To Guides: How_to_Guides.html
.. _Processor SDK Linux How-To Guides: How_to_Guides.html
.. _Linux SDK Software Developer's Guide: index.html
.. _Processor SDK Linux Software Developer's Guide: index.html
.. _SD Card using default images: Overview/Processor_SDK_Linux_create_SD_card_script.html#sd-card-using-default-images
.. _SD Card using custom images: Overview/Processor_SDK_Linux_create_SD_card_script.html#sd-card-using-custom-images
.. _SD Card using parition tarballs: Overview/Processor_SDK_Linux_create_SD_card_script.html#sd-card-using-partition-tarballs
.. _Examples and Demos: Examples_and_Demos.html


.. ifconfig:: CONFIG_part_family in ('General_family')

    +---------------+--------------------+-------------------------+----------------------------+
    | **Foundational Components** (more information on each piece of the distribution)          |
    +===============+====================+=========================+============================+
    | `U-Boot`_     | `Boot Monitor`_    | `Kernel`_               | `Filesystem`_              |
    +---------------+--------------------+-------------------------+----------------------------+
    | `Tools`_      | `OpenCL`_          | `OpenCV`_               | `Graphics & Display`_      |
    +---------------+--------------------+-------------------------+----------------------------+
    | `Multimedia`_ | `Examples, Demos`_ | `PRU-ICSS / PRU_ICSSG`_ | `Virtualization`_          |
    +---------------+--------------------+-------------------------+----------------------------+
    | `IPC`_        | `OpenVX`_          | `CMEM`_                 | `Machine Learning`_        |
    +---------------+--------------------+-------------------------+----------------------------+
    | `ATF`_        | `OPTEE`_           |                         |                            |
    +---------------+--------------------+-------------------------+----------------------------+

    .. _U-Boot: Foundational_Components_U-Boot.html
    .. _Processor SDK Linux U-Boot: Foundational_Components_U-Boot.html
    .. _Boot Monitor: Foundational_Components_Boot_Monitor.html
    .. _Kernel: Foundational_Components_Kernel.html
    .. _Processor SDK Linux Kernel: Foundational_Components_Kernel.html
    .. _Filesystem: Foundational_Components_Filesystem.html
    .. _Processor SDK Linux Filesystem: Foundational_Components_Filesystem.html
    .. _Tools: Foundational_Components_Tools.html
    .. _Processor SDK Linux Tools: Foundational_Components_Tools.html
    .. _OpenCL: http://downloads.ti.com/mctools/esd/docs/opencl/index.html
    .. _OpenCV: Foundational_Components_OpenCV.html
    .. _Graphics & Display: Foundational_Components_Graphics.html
    .. _Multimedia: Foundational_Components_Multimedia.html
    .. _Examples, Demos: Examples_and_Demos.html
    .. _PRU-ICSS / PRU_ICSSG: Foundational_Components_PRU-ICSS_PRU_ICSSG.html
    .. _Virtualization: Foundational_Components_Virtualization.html
    .. _IPC: Foundational_Components_IPC.html
    .. _OpenVX: Foundational_Components_OpenVX.html
    .. _CMEM: Foundational_Components_CMEM.html
    .. _Machine Learning: Foundational_Components_Machine_Learning.html
    .. _ATF: Foundational_Components_ATF.html
    .. _OPTEE: Foundational_Components_OPTEE.html


.. ifconfig:: CONFIG_part_family in ('AM335X_family', 'AM437X_family')

    +-----------------------+-----------------------+-------------------------+------------+
    | **Foundational Components** (more information on each piece of the distribution)     |
    +=======================+=======================+=========================+============+
    | `U-Boot`_             | `Kernel`_             | `Filesystem`_           | `Tools`_   |
    +-----------------------+-----------------------+-------------------------+------------+
    | `Graphics & Display`_ | `Examples, Demos`_    | `PRU-ICSS / PRU_ICSSG`_ |            |
    +-----------------------+-----------------------+-------------------------+------------+

    .. _U-Boot: Foundational_Components_U-Boot.html
    .. _Processor SDK Linux U-Boot: Foundational_Components_U-Boot.html
    .. _Kernel: Foundational_Components_Kernel.html
    .. _Processor SDK Linux Kernel: Foundational_Components_Kernel.html
    .. _Filesystem: Foundational_Components_Filesystem.html
    .. _Processor SDK Linux Filesystem: Foundational_Components_Filesystem.html
    .. _Tools: Foundational_Components_Tools.html
    .. _Processor SDK Linux Tools: Foundational_Components_Tools.html
    .. _Graphics & Display: Foundational_Components_Graphics.html
    .. _Examples, Demos: Examples_and_Demos.html
    .. _PRU-ICSS / PRU_ICSSG: Foundational_Components_PRU-ICSS_PRU_ICSSG.html


.. ifconfig:: CONFIG_sdk in ('PLSDK')

    +----------------+-------------------------+------------------+-----------------------------------+
    | **PRU-ICSS / PRU_ICSSG Protocols** (more information on each piece of the distribution)         |
    +================+=========================+==================+===================================+
    | `DUAL_EMAC`_   | `HSR\_PRP`_             | `PTP`_           | `RSTP`_                           |
    +----------------+-------------------------+------------------+-----------------------------------+
    | `CCLINK`_      | `SORTE`_                | `OPC/UA`_        |                                   |
    +----------------+-------------------------+------------------+-----------------------------------+

    .. _DUAL_EMAC: Industrial_Protocols_ICSS_Dual_EMAC.html
    .. _HSR\_PRP: Industrial_Protocols_HSR_PRP.html
    .. _RSTP: Industrial_Protocols_RSTP.html
    .. _PTP: Industrial_Protocols_PTP.html
    .. _CCLINK: Industrial_Protocols_CCLINK.html
    .. _SORTE: Industrial_Protocols_SORTE.html
    .. _OPC/UA: Industrial_Protocols_OPCUA.html
