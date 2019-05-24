************************************
Supported Platforms and Versions
************************************
.. http://processors.wiki.ti.com/index.php/Processor_SDK_Supported_Platforms_and_Versions

.. rubric:: Supported Host Operating Systems
   :name: supported-host-operating-systems

The following operating systems have been validated to work with our
SDK.

-  **Linux SDK**

+---------------------------+-------------------------+
| **Operating System**      | | **Version**           |
+---------------------------+-------------------------+
| Ubuntu                    | | 14.04 (64-bit)        |
|                           | | 16.04 (64-bit)        |
|                           | | 18.04 (64-bit)        |
+---------------------------+-------------------------+

-  **RTOS SDK**

+---------------------------+-------------------------+
| **Operating System**      | | **Version**           |
+---------------------------+-------------------------+
| Windows                   | | 7 (64-bit)            |
+---------------------------+-------------------------+
| Ubuntu                    | | 14.04 (64-bit)        |
|                           | | 16.04 (64-bit)        |
+---------------------------+-------------------------+

-  **Android SDK**

+---------------------------+-------------------------+
| **Operating System**      | | **Version**           |
+---------------------------+-------------------------+
| Ubuntu                    | | 14.04 (64-bit)        |
+---------------------------+-------------------------+

| 

.. rubric:: Supported Platforms and EVMs
   :name: supported-platforms-and-evms

The following platforms and EVMs are supported with Processor SDK 

+--------------------------------------+--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|**Platform**                          |**EVM**                               |**Tested  |**Document**                                |**Processor SDK |**Processor SDK |**Processor SDK |**Processor SDK |
|                                      |                                      |Version** |                                            |Linux**         |RT Linux**      |RTOS**          |Android**       |
+--------------------------------------+--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|`AM65x/DRA80xM <http://www.ti.com/    |`AM65x/DRA80xM EVM                    | Beta     |Hardware User's Guide                       | X              | X              | X              | X              |
|AM65x>`__                             |<http://www.ti.com/tool/              |          |`Hardware Setup with CCS <http://software-d |                |                |                |                |
|                                      |tmdx654gpevm>`__                      |          |l.ti.com/processor-sdk-rtos/esd/docs/       |                |                |                |                |
|                                      |                                      |          |latest/rtos/How_to_Guides.html#am65x-evm>`__|                |                |                |                |
|                                      +--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|                                      |`AM65x/DRA80xM IDK                    | Beta     |Hardware User's Guide                       | X              | X              | X              | X              |
|                                      |<http://www.ti.com/tool/              |          |`Hardware Setup with CCS <http://software-d |                |                |                |                |
|                                      |tmdx654idkevm>`__                     |          |l.ti.com/processor-sdk-rtos/esd/docs/       |                |                |                |                |
|                                      |                                      |          |latest/rtos/How_to_Guides.html#am65x-evm>`__|                |                |                |                | 
+--------------------------------------+--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|`AM57x <http://www.ti.com/lsds/ti/    |`AM572x EVM                           | A3       |`Hardware User's Guide <http://             | X              | X              | X              | X              |
|processors/sitara/arm_cortex-a15/     |<http://www.ti.com/tool/              |          |www.ti.com/lit/pdf/spruig1>`__              |                |                |                |                |
|am57x/overview.page>`__               |TMDSEVM572X>`__                       |          |                                            |                |                |                |                |
|                                      +--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|                                      |`AM572x IDK                           | 1.3A     |`Hardware User's Guide <http://             | X              | X              | X              | X              |
|                                      |<http://www.ti.com/tool/              |          |www.ti.com/lit/pdf/sprui64>`__              |                |                |                |                |
|                                      |TMDXIDK5728>`__                       |          |`Hardware Setup with CCS <http://processors |                |                |                |                |
|                                      |                                      |          |.wiki.ti.com/index.php/TMDXIDK5728_         |                |                |                |                |
|                                      |                                      |          |Hardware_Setup>`__                          |                |                |                |                |
|                                      +--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|                                      |`AM571x IDK                           | 1.3A     |`Hardware User's Guide <http://             | X              | X              | X              | X              |
|                                      |<http://www.ti.com/tool/              |          |www.ti.com/lit/pdf/sprui97>`__              |                |                |                |                |
|                                      |tmdxidk5718>`__                       |          |`Hardware Setup with CCS <http://processors |                |                |                |                |
|                                      |                                      |          |.wiki.ti.com/index.php/TMDXIDK5728_         |                |                |                |                |
|                                      |                                      |          |Hardware_Setup>`__                          |                |                |                |                |
|                                      +--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|                                      |`AM574x IDK                           | 1.0A     |`Hardware User's Guide <http://             | X              | X              | X              | X              |
|                                      |<http://www.ti.com/tool/              |          |www.ti.com/lit/pdf/spruij9>`__              |                |                |                |                |
|                                      |TMDSIDK574>`__                        |          |`Hardware Setup with CCS <http://processors |                |                |                |                |
|                                      |                                      |          |.wiki.ti.com/index.php/TMDXIDK5728_         |                |                |                |                |
|                                      |                                      |          |Hardware_Setup>`__                          |                |                |                |                |
+--------------------------------------+--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|`AM437x <http://www.ti.com/lsds/ti/   |`AM437x EVM                           | 1.5B     |`Hardware User's Guide <http://             | X              | X              | X              |                |
|processors/sitara/arm_cortex-a9/      |<http://www.ti.com/tool/              |          |processors.wiki.ti.com/index.php/AM437x_    |                |                |                |                |
|am437x/overview.page>`__              |TMDXEVM437X>`__                       |          |General_Purpose_EVM_HW_User_Guide>`__       |                |                |                |                |
|                                      +--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|                                      |`AM437x SK                            | 1.1A     |`Hardware User's Guide <http://             | X              |                | X              |                |
|                                      |<http://www.ti.com/tool/              |          |www.ti.com/lit/pdf/spruhw8>`__              |                |                |                |                |
|                                      |TMDXSK437X>`__                        |          |                                            |                |                |                |                |
|                                      +--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|                                      |`AM437x IDK                           | 1.4A     |`Hardware User's Guide <http://             |                | X              | X              |                |
|                                      |<http://www.ti.com/tool/              |          |www.ti.com/lit/pdf/sprw259>`__              |                |                |                |                |
|                                      |tmdsidk437x>`__                       |          |                                            |                |                |                |                |
+--------------------------------------+--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|`AM335x <http://www.ti.com/lsds/ti/   |`AM335x EVM                           | 1.6A     |`Hardware User's Guide <http://             | X              | X              | X              |                |
|processors/sitara/arm_cortex-a8/      |<http://www.ti.com/tool/              |          |processors.wiki.ti.com/index.php/AM335x_    |                |                |                |                |
|am335x/overview.page>`__              |tmdxevm3358>`__                       |          |General_Purpose_EVM_HW_User_Guide>`__       |                |                |                |                |
|                                      +--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|                                      |`AM335x SK                            | 1.2      |`Hardware User's Guide <http://             | X              |                | X              |                |
|                                      |<http://www.ti.com/tool/              |          |processors.wiki.ti.com/index.php/           |                |                |                |                |
|                                      |tmdssk3358>`__                        |          |AM335xStarterKitHardwareUsersGuide>`__      |                |                |                |                |
|                                      +--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|                                      |`BeagleBone Black                     | B6       |`Hardware User's Guide <https://github.com/ | X              |                | X              |                |
|                                      |<http://beagleboard.org/Products/     |          |CircuitCo/BeagleBone-Black/blob/            |                |                |                |                |
|                                      |BeagleBone%20Black>`__                |          |master/BBB_SRM.pdf?raw=true>`__             |                |                |                |                |
|                                      +--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|                                      |`AM335x ICE                           | 2.1A     |`Hardware User's Guide <http://processors.  |                | X              | X              |                |
|                                      |<http://www.ti.com/tool/              |          |wiki.ti.com/index.php/AM335x_Industrial_    |                |                |                |                |
|                                      |TMDSICE3359>`__                       |          |Communication_Engine_%28ICE%29_EVM_HW_      |                |                |                |                |
|                                      |                                      |          |User_Guide>`__                              |                |                |                |                |
|                                      |                                      |          |`Hardware Setup with CCS <http://processors |                |                |                |                |
|                                      |                                      |          |.wiki.ti.com/index.php/ICE_AM335x_          |                |                |                |                |
|                                      |                                      |          |Hardware_Setup>`__                          |                |                |                |                |
+--------------------------------------+--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|`K2H/K2K <http://www.ti.com/lsds/ti/  |`66AK2Hx EVM                          | 4.0      |`Hardware User's Guide <http://             | X              | X              | X              |                |
|processors/dsp/c6000_dsp-arm/66ak2x/  |<http://www.ti.com/tool               |          |software-dl.ti.com/processor-sdk-linux      |                |                |                |                |
|overview.page>`__                     |/evmk2h>`__                           |          |/esd/docs/latest/linux/How_to_Guides_       |                |                |                |                |
|                                      |                                      |          |Hardware_Setup_with_CCS.html#evmk2h-        |                |                |                |                |
|                                      |                                      |          |hardware-setup-guide>`__                    |                |                |                |                |
|                                      +--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|                                      |`TCI6638K2K EVM                       | 4.0      |`Hardware User's Guide <http://             | X              | X              | X              |                |
|                                      |<http://www.ti.com/tool/              |          |software-dl.ti.com/processor-sdk-linux      |                |                |                |                |
|                                      |tci6638k2k>`__                        |          |/esd/docs/latest/linux/How_to_Guides_       |                |                |                |                |
|                                      |                                      |          |Hardware_Setup_with_CCS.html#evmk2h-        |                |                |                |                |
|                                      |                                      |          |hardware-setup-guide>`__                    |                |                |                |                |
+--------------------------------------+--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|`K2E <http://www.ti.com/lsds/ti/      |`66AK2Ex EVM                          | 1.0.3.0  |`Hardware User's Guide <http://             | X              | X              | X              |                |
|processors/dsp/c6000_dsp-arm/66ak2x/  |<http://www.ti.com/tool               |          |software-dl.ti.com/processor-sdk-linux      |                |                |                |                |
|overview.page>`__                     |/evmk2ex>`__                          |          |/esd/docs/latest/linux/How_to_Guides_       |                |                |                |                |
|                                      |                                      |          |Hardware_Setup_with_CCS.html#evmk2e-        |                |                |                |                |
|                                      |                                      |          |hardware-setup-guide>`__                    |                |                |                |                |
+--------------------------------------+--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|`K2L <http://www.ti.com/lsds/ti/      |`66AK2L06 EVM                         | 1.0.3.0  |`Hardware User's Guide <http://             | X              | X              | X              |                |
|processors/dsp/c6000_dsp-arm/66ak2x/  |<http://www.ti.com/tool               |          |processors.wiki.ti.com/index.php/           |                |                |                |                |
|overview.page>`__                     |/xevmk2lx>`__                         |          |TCIEVMK2L_Hardware_Setup>`__                |                |                |                |                |
+--------------------------------------+--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|`K2G <http://www.ti.com/processors/   |`K2G EVM                              | 1.3D     |`Hardware User's Guide <http://             | X              | X              | X              |                |
|dsp/c6000-dsp-arm/66ak2x/             |<http://www.ti.com/tool/              |          |www.ti.com/lit/pdf/sprui65a>`__             |                |                |                |                |
|overview.html>`__                     |EVMK2G>`__                            |          |                                            |                |                |                |                |
|                                      +--------------------------------------+----------+                                            +----------------+----------------+----------------+----------------+
|                                      |`K2G 1G EVM                           | 1.5D     |`Hardware User's Guide <http://             | X              | X              | X              |                |
|                                      |<http://www.ti.com/tool/              |          |www.ti.com/lit/pdf/sprui65a>`__             |                |                |                |                |
|                                      |EVMK2GX>`__                           |          |                                            |                |                |                |                |
|                                      +--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|                                      |`K2G Audio Daughtercard               | D        |`Software Support <http://                  |                |                | X              |                |
|                                      |<http://www.ti.com/tool/              |          |software-dl.ti.com/processor-sdk-rtos       |                |                |                |                |
|                                      |audk2g>`__                            |          |/esd/docs/latest/rtos/index_how_to_         |                |                |                |                |
|                                      |                                      |          |guides.html#ak2g-audio-dc-addon>`__         |                |                |                |                |
|                                      +--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|                                      |`K2G ICE EVM                          |1.0C Beta |`Hardware User's Guide <http://             | X              | X              | X              |                |
|                                      |<http://www.ti.com/tool/              |          |www.ti.com/lit/pdf/spruie0>`__              |                |                |                |                |
|                                      |k2gice>`__                            |          |`Hardware Setup with CCS <http://processors |                |                |                |                |
|                                      |                                      |          |.wiki.ti.com/index.php/66AK2G02_ICE_EVM_    |                |                |                |                |
|                                      |                                      |          |Hardware_Setup>`__                          |                |                |                |                |
+--------------------------------------+--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|`C665x <http://www.ti.com/lsds/ti/    |`C665x EVM                            | 1.1-44   |`Hardware User's Guide <http://             | N/A            | N/A            | X              |                |
|processors/dsp/c6000_dsp/c66x/        |<http://www.ti.com/tool               |          |software-dl.ti.com/processor-sdk-rtos       |                |                |                |                |
|overview.page>`__                     |/tmdsevm6657>`__                      |          |/esd/docs/latest/rtos/index_how_to_         |                |                |                |                |
|                                      |                                      |          |guides.html#tmdsevm6657l-evm-hardware-      |                |                |                |                |
|                                      |                                      |          |setup-guide>`__                             |                |                |                |                |
+--------------------------------------+--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|`C667x <http://www.ti.com/lsds/ti/    |`C667x EVM                            | 3B       |`Hardware User's Guide <http://             | N/A            | N/A            | X              |                |
|processors/dsp/c6000_dsp/c66x/        |<http://www.ti.com/tool               |          |software-dl.ti.com/processor-sdk-rtos       |                |                |                |                |
|overview.page>`__                     |/tmdsevm6678>`__                      |          |/esd/docs/latest/rtos/index_how_to_         |                |                |                |                |
|                                      |                                      |          |guides.html#tmdxevm6678l-                   |                |                |                |                |
|                                      |                                      |          |evm-hardware-setup-guide>`__                |                |                |                |                |
+--------------------------------------+--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|`OMAPL137/C6747 <http://www.ti.com/   |`OMAP-L137/C6747 Starter kit EVM      | J        |`Hardware User's Guide <http://             | N/A            | N/A            | X              |                |
|lsds/ti/processors/dsp/c6000_dsp-arm/ |<http://www.ti.com/tool               |          |support.spectrumdigital.com/boards/         |                |                |                |                |
|omap-l1x/overview.page>`__            |/tmdsoskl137>`__                      |          |evmomapl137/revd/>`__                       |                |                |                |                |
|                                      |                                      |          |`Hardware Setup with CCS <http://processors |                |                |                |                |
|                                      |                                      |          |.wiki.ti.com/index.php/OMAP-L137_EVM_       |                |                |                |                |
|                                      |                                      |          |Hardware_Setup#Connecting_to_CCS>`__        |                |                |                |                |
+--------------------------------------+--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|`OMAPL138/C6748 <http://www.ti.com/   |`OMAP-L138/C6748 LCDK                 | A7A      |`Hardware User's Guide <http://             | X              | N/A            | X              |                |
|lsds/ti/processors/dsp/c6000_dsp-arm/ |<http://www.ti.com/tool               |          |processors.wiki.ti.com/index.php/L138/      |                |                |                |                |
|omap-l1x/overview.page>`__            |/tmdslcdk138>`__                      |          |C6748_Development_Kit_%28LCDK%29>`__        |                |                |                |                |
+--------------------------------------+--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+
|`AMIC110 <http://www.ti.com/          |`AMIC110 ICE                          | 1.1      |`Hardware User's Guide <http://             |                |                | X              |                |
|product/AMIC110>`__                   |<http://www.ti.com/tool               |          |www.ti.com/lit/pdf/spruie6>`__              |                |                |                |                |
|                                      |/tmdxice110>`__                       |          |`Hardware Setup with CCS <http://processors |                |                |                |                |
|                                      |                                      |          |.wiki.ti.com/index.php/ICE_AMIC110_         |                |                |                |                |
|                                      |                                      |          |Hardware_Setup>`__                          |                |                |                |                |
+--------------------------------------+--------------------------------------+----------+--------------------------------------------+----------------+----------------+----------------+----------------+

