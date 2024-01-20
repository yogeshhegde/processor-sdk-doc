*************
Target
*************

Run IPC Examples on AM572x
==============================================
.. include:: How_to_Guides/Target/_Run_IPC_Examples_on_AM572x.rst

Taking the C66x Out Of Reset with Linux Running on the ARM A15
===============================================================
.. include:: How_to_Guides/Target/_C66x_Reset_from_A15_Running_Linux.rst

RTOS Customization: using an external input to trigger an interrupt on AM57x
=======================================================================================================
.. include:: How_to_Guides/Target/_External_Input_Trigger_Interrupt_AM57x.rst

*************
Host
*************


Setup
======

.. Setup CCS for EVM and Processor-SDK RTOS
.. ------------------------------------------
.. _Processor-SDK-RTOS-Setup-CCS-label:
.. include:: How_to_Guides/Host/Setup/_Setup_CCS_for_EVM_and_PSDK_RTOS.rst


.. Update environment when installing to a custom path
.. -----------------------------------------------------
.. _Processor-SDK-RTOS-Install-In-Custom-Path-label:
.. include:: How_to_Guides/Host/Setup/_Update_ENV_for_a_Custom_Path.rst


Prevent BeagleBone board reset on JTAG Connect
-----------------------------------------------
`<https://elinux.org/Beagleboard:BeagleBone#Board_Reset_on_JTAG_Connect.28A3.2CA4.2CA5.29>`__


Rebuild drivers from PDK directory
------------------------------------
Refer `Rebuilding the PDK <Overview.html#rebuild-pdk>`__ for details on rebuilding the PDK components.

TI RTOS Basics
===============
.. include:: How_to_Guides/Host/Setup/_TI_RTOS_Tips_and_Tricks.rst


Flashing and Boot
==================

Flash bootable images (C66x, K2H/K2E/K2L only)
-----------------------------------------------
.. include:: How_to_Guides/Host/Flashing_and_Boot/_Flash_bootable_images.rst


Porting
==================

Adding Custom Board_Library Target to Processor SDK RTOS makefiles
-------------------------------------------------------------------
.. include:: How_to_Guides/Host/Porting/_Adding_Custom_Board_Library_Target_to_PSDK_RTOS_makefiles.rst


Processor SDK RTOS Porting Guide for AM571x/AM570x Speed Grades
----------------------------------------------------------------
.. include:: How_to_Guides/Host/Porting/_PSDK_RTOS_Porting_Guide_for_AM57xx_Speed_Grades.rst


System Integration
===================

Create DSP and IPU firmware using PDK drivers and IPC to load from ARM Linux on AM57xx devices
------------------------------------------------------------------------------------------------
.. include:: How_to_Guides/Host/System_Integration/_Create_DSP_and_IPU_FW_using_PDK_and_IPC_to_load_from_ARM_AM57xx.rst


Customizing Memory map for creating Multicore Applications on AM57xx using IPC
-------------------------------------------------------------------------------
`<http://www.ti.com/lit/an/sprac60/sprac60.pdf>`__

IPC Debugging Tools and Techniques on AM57xx
--------------------------------------------
.. include:: How_to_Guides/Host/System_Integration/_IPC_Debugging_Tools_and_Techniques_on_AM57xx.rst

*******************
EVM Hardware Setup
*******************

.. AM65x EVM
.. ====================================================
.. include:: ../common/EVM_Hardware_Setup/_TMDX654_EVM_Hardware_Setup.rst

.. AM572x GP EVM Hardware Setup
.. ====================================================
.. include:: ../common/EVM_Hardware_Setup/_AM572x_GP_EVM_Hardware_Setup.rst

.. TMDXIDK5728 Hardware Setup
.. ====================================================
.. include:: ../common/EVM_Hardware_Setup/_TMDXIDK5728_Hardware_Setup.rst

.. 66AK2G02 GP EVM Hardware Setup
.. ====================================================
.. include:: ../common/EVM_Hardware_Setup/_66AK2G02_GP_EVM_Hardware_Setup.rst

.. 66AK2G02 ICE EVM Hardware Setup
.. ====================================================
.. include:: ../common/EVM_Hardware_Setup/_66AK2G02_ICE_EVM_Hardware_setup.rst

.. EVMK2E Hardware Setup
.. ====================================================
.. include:: ../common/EVM_Hardware_Setup/_EVMK2E_Hardware_Setup.rst

.. EVMK2H Hardware Setup
.. ====================================================
.. include:: ../common/EVM_Hardware_Setup/_EVMK2H_Hardware_Setup.rst

.. TMDSEVM6657L EVM Hardware Setup
.. ====================================================
.. include:: ../common/EVM_Hardware_Setup/_TMDSEVM6657L_EVM_Hardware_Setup.rst

.. TMDXEVM6670L EVM Hardware Setup
.. ====================================================
.. include:: ../common/EVM_Hardware_Setup/_TMDXEVM6670L_EVM_Hardware_Setup.rst

.. TMDXEVM6678L EVM Hardware Setup
.. ====================================================
.. include:: ../common/EVM_Hardware_Setup/_TMDXEVM6678L_EVM_Hardware_Setup.rst

.. OMAP-L138/C6748 LCDK Hardware Setup
.. ====================================================
.. include:: ../common/EVM_Hardware_Setup/_OMAPL138-C6748_LCDK_Hardware_Setup.rst

.. OMAP-L137 EVM Hardware Setup
.. ====================================================
.. include:: ../common/EVM_Hardware_Setup/_OMAPL137_EVM_Hardware_Setup.rst

.. AM335x ICE EVM Hardware Setup
.. ====================================================
.. include:: ../common/EVM_Hardware_Setup/_ICE_AM335x_Hardware_Setup.rst

.. AMIC110 ICE EVM Hardware Setup
.. ====================================================
.. include:: ../common/EVM_Hardware_Setup/_ICE_AMIC110_EVM_Hardware_Setup.rst


66AK2G Audio DC AddOn
====================================================

Please refer to `K2G Audio DC AddOn
<index_examples_demos.html#k2g-audio-dc-addon>`__


+--------------------------------+--------------------------------------------------------------------------------------------------+
| .. Image:: ../../images/E2e.jpg   | For technical support please post your questions at `http://e2e.ti.com <http://e2e.ti.com/>`__.  |
+--------------------------------+--------------------------------------------------------------------------------------------------+
