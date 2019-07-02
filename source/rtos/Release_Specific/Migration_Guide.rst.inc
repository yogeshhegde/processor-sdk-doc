****************
Migration Guide
****************

.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Migration_Guide

Overview
========

This page covers migration information from last Processor SDK RTOS release (Processor SDK RTOS 05.03.00) to the present release (Processor SDK RTOS 06.00.00)


PRUSS
=====

**Migration-1:** Calls that passed PRUICCSS_INSTANCE_MAX as a parameter to PRUSS driver API calls will now pass PRUICCSS_INSTANCE_THREE instead.

**Impact Scope:** Applicable for all AM65xx applications using PRUSS driver for ICSSG use case
 
**Additional Details**:
The following new enumeration, PRUICCSS_INSTANCE_THREE, for PRU-ICSS instance 3 has been added to PRUICSS_MaxInstances enumeration list as PRUICCSS_INSTANCE_MAX is not longer valid when making PRUSS driver API calls.


Board Library
==============

**Migration:** MMU configuration is needed to enable NBO CFG registers access on A53 core

**Impact Scope:** Applicable for all AM65xx RTOS applications calling Board_init with 'BOARD_INIT_ICSS_ETH_PHY' flag
 
**Additional Details**:
Board library is setting NAVSS THREADMAP register to give higher priority for MSMC access from ICSSG
which requires access to NBO CFG registers.

.. raw:: html

