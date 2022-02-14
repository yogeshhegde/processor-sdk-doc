.. include:: /replacevars.rst.inc

Power Management Overview
-------------------------

.. rubric:: Power Management Overview

Power management is a wide reaching topic and reducing the power a
system uses is handled by a number of drivers and techniques. Power
Management can broadly be classified into two categories: Dynamic/Active
Power management and Idle Power Management.

.. rubric:: Dynamic Power Management Techniques

Dynamic or active Power management techniques reduce the active power
consumption by an SoC when the system is active and performing tasks.

The dynamic power management features enables on |__PART_FAMILY_DEVICE_NAMES__| are as follows:

.. ifconfig:: CONFIG_part_family in ('General_family')

	-  MPU DVFS
	-  SmartReflex

.. ifconfig:: CONFIG_part_family in ('AM335X_family', 'AM437X_family')

	#. DVFS
	#. CPUIdle
	#. Smartreflex

.. rubric:: Idle Power Management Techniques

This ensures the system is drawing minimum power when in idle state i.e
no use-case is running. This is accomplished by turning off as many
peripherals as that are not in use.
