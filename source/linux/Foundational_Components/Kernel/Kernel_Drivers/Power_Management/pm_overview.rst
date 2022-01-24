.. http://processors.wiki.ti.com/index.php/Linux_Core_Power_Management_User%27s_Guide

Power Management Overview
---------------------------------

.. rubric:: Power Management Overview
   :name: Power Management Overview

Power management is a wide reaching topic and reducing the power a
system uses is handled by a number of drivers and techniques. Power
Management can broadly be classified into two categories: Dynamic/Active
Power management and Idle Power Management. This page covers power
topics for the v4.4 Linux kernel. This the most recent version. A full
history of this guide can be found at `Linux Core Power Management
User's Guide
History <http://processors.wiki.ti.com/index.php/Linux_Core_Power_Management_User%27s_Guide_History>`__.


.. ifconfig:: CONFIG_part_family in ('J7_family', 'General_family')

	.. rubric:: Power Management on DRA7 platform
	   :name: power-management-on-dra7-platform

	The power management features enabled on DRA7 platforms (DRA7x/ J6/
	AM57x) are as follows:

	-  Suspend/Resume
	-  MPU DVFS
	-  SmartReflex

.. ifconfig:: CONFIG_part_family in ('AM335X_family', 'AM437X_family')

	.. rubric:: Dynamic Power Management Techniques
	   :name: dynamic-power-management-techniques

	Dynamic or active Power management techniques reduce the active power
	consumption by an SoC when the system is active and performing tasks.

	#. DVFS
	#. CPUIdle
	#. Smartreflex


