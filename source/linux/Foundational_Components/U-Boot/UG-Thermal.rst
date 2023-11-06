Thermal shutdown Support
--------------------------------------
To avoid thermal burn out, in R5 SPL thermal threshold values are programmed with high of 123 degrees Celsius and low of 105 degrees Celsius .

These values are fixed in U-Boot, In case other values are needed, K3_VTM_ADC_COUNT_FOR_123C and K3_VTM_ADC_COUNT_FOR_105C defines can be
changed in k3_avs driver before rebuilding u-boot.

However, if OS driver supports VTM (Voltage and Thermal Manager) then above values will be reprogrammed as per driver settings.


**Supported Devices**

-  J721E EVM
-  J7200 EVM

Driver
^^^^^^
Refer to drivers/misc/k3_avs.c in U-Boot source tree for the AVS driver. 
