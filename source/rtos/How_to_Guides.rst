######################
How to Guides
######################

.. toctree::
   :maxdepth: 3

   index_how_to_guides


Taking the C66x Out Of Reset with Linux Running on the ARM A15
===============================================================
.. include:: How_to_Guides/Target/C66x_Reset_from_A15_Running_Linux.rst.inc



*************
Host
*************


Setup
======

.. Setup CCS for EVM and Processor-SDK RTOS
.. ------------------------------------------
.. _Processor-SDK-RTOS-Setup-CCS-label:
.. include:: How_to_Guides/Host/Setup/Setup_CCS_for_EVM_and_PSDK_RTOS.rst.inc


.. Update environment when installing to a custom path
.. -----------------------------------------------------
.. _Processor-SDK-RTOS-Install-In-Custom-Path-label:
.. include:: How_to_Guides/Host/Setup/Update_ENV_for_a_Custom_Path.rst.inc


Prevent BeagleBone board reset on JTAG Connect 
-----------------------------------------------
`<https://elinux.org/Beagleboard:BeagleBone#Board_Reset_on_JTAG_Connect.28A3.2CA4.2CA5.29>`__


Rebuild drivers from PDK directory
------------------------------------
Refer `Rebuilding the PDK <Overview.html#rebuild-pdk>`__ for details on rebuilding the PDK components.



Flashing and Boot
==================

Flash bootable images (C66x, K2H/K2E/K2L only)
-----------------------------------------------
.. include:: How_to_Guides/Host/Flashing_and_Boot/Flash_bootable_images.rst.inc


Porting
==================

Adding Custom Board_Library Target to Processor SDK RTOS makefiles
-------------------------------------------------------------------
Refer `Creating Board Library with Custom Name <Board_EVM_Abstration.html#creating-board-library-with-custom-name>`_


Processor SDK RTOS Porting Guide for AM571x/AM570x Speed Grades
----------------------------------------------------------------
.. include:: How_to_Guides/Host/Porting/PSDK_RTOS_Porting_Guide_for_AM57xx_Speed_Grades.rst.inc


System Integration
===================

Create DSP and IPU firmware using PDK drivers and IPC to load from ARM Linux on AM57xx devices
------------------------------------------------------------------------------------------------
.. include:: How_to_Guides/Host/System_Integration/Create_DSP_and_IPU_FW_using_PDK_and_IPC_to_load_from_ARM_AM57xx.rst.inc


Customizing Memory map for creating Multicore Applications on AM57xx using IPC 
-------------------------------------------------------------------------------
`<http://www.ti.com/lit/an/sprac60/sprac60.pdf>`__

IPC Debugging Tools and Techniques on AM57xx
--------------------------------------------
.. include:: How_to_Guides/Host/System_Integration/IPC_Debugging_Tools_and_Techniques_on_AM57xx.rst.inc



