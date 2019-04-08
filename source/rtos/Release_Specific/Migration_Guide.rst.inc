****************
Migration Guide
****************

.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Migration_Guide

Overview
========

This page covers migration information from last Processor SDK RTOS release (Processor SDK RTOS 05.02.00) to the present release (Processor SDK RTOS 05.03.00)


EMAC
====

**Migration-1:** ICSS-G EMAC firmware binary directory location update for future extension 

**Impact Scope:** Applicable for all applications using EMAC driver with ICSS-G dual EMAC firmware 
 
**Additional Details**:
Applications will need to update the include path to location of firmware header files for ICSSG use case
    prevous location: ti/drv/emac/firmeare/icss_eth/src/dm
    
    new location:     ti/drv/emac/firmware/icss_dualmac/bin

**Migration-2:** Release introduces support for additional firmware specific configuration files. Added for future extension to support multiple firmwares using same EMAC driver 

**Impact Scope:** Applicable for all applications using EMAC driver with ICSS-G dual EMAC firmware 

**Additional Details**:
Firmware configuration has been moved to firmware specific configuration files, emac_fw_config_dual_mac.h and emac_fw_config_dual_mac.c. Previously the firmware configuration was specified in the test application 
It is not expected that applicatons will need to modify these files as the are closely tied to the firmware. 
   
   Previous location: firmware specific configuration was specified in the text application (ti/drv/emac/test/EmacLoopbackTest/test_utils_k3.c)
   
   New location:      'ti/drv/emac/firmware/icss_dualmac/config/'
Applications will need to update their makefiles to include c source file emac_fw_config_dual_mac.c 
At time of emac_open API call, applications need to udpate configuruation parameters to pass get firmware configuration pointer :
  
   EMAC_HwAttrs_V5 emac_cfg;
   
   EMAC_socGetInitCfg(0, &emac_cfg);
   
   emac_cfg.portCfg[port_num].getFwCfg = &emacGetDualMacFwConfig;
   
   EMAC_socSetInitCfg(0, &emac_cfg);


CSL
===

**Migration:** API changes on CSL-FL of AM65xx on ecc aggregator, vim, esm modules

**Impact Scope**: Limited to the case if application is using the CSL-FL APIs

**Additional Details**: The CSL-FL for ECC aggregator, ESM and VIM are modified to
return API functionality success/failures and additional arguments are added as and
when needed (especially during the cases where the return was the value instead of API success/failure).
Applications that use these CSL-FL calls are impacted and are needed to align to new calling conventions.
If applicable application modification required to align to updated APIs, refer doxygen API documentation for API details.


DSP- TI CGT Compiler
===================

**Migration:** In DSP TI CGT compiler version 8.3.2 the rts library boot object file name is changed 
from boot.obj to boot.c.obj.

**Impact Scope:** Limited only to DSP applications that explicitly uses rts library object files in linker
command file.

**Additional Details**: The DSP application which is using linker command file of CSL module should change
boot object name from boot.obj file to boot.c.obj. If the user is using cpp version of boot object file
then it should be mentioned as boot.cpp.obj. In general it can be also be used as boot.*.obj
This can be referred from the following linker command file in the PDK package
<PDK>/packages/ti/csl/example/lnk_dsp.cmd

.. raw:: html

