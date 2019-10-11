****************
Migration Guide
****************

.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Migration_Guide

Overview
========

This page covers migration information from last Processor SDK RTOS release (Processor SDK RTOS 06.00.00) to the present release (Processor SDK RTOS 06.01.00)


NIMU
====

**Migration-1:** Udma init sequence call has been moved from NIMU library to NIMU example for AM65xx andd J721E SOC's.

**Impact Scope:** Applicable for all NIMU applications using NIMU tranport library for AM65xx and J721E SOC's.
 
**Additional Details**:
Applications will need to implement the following function to provide UDMA drive handle which will be called by the NIMU driver at startup

 Udma_DrvHandle nimu_app_get_udma_handle(void)


