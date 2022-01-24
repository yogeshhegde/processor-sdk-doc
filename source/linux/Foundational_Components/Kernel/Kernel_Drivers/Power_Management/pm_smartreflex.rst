.. http://processors.wiki.ti.com/index.php/Linux_Core_Power_Management_User%27s_Guide

Smart Reflex
---------------------------------

.. ifconfig:: CONFIG_part_family in ('J7_family', 'General_family')

	.. rubric:: Power Management on DRA7 platform
	   :name: power-management-on-dra7-platform
	The power management features enabled on DRA7 platforms (DRA7x/ J6/
	AM57x) are as follows:

	-  Suspend/Resume
	-  MPU DVFS
	-  **SmartReflex**

	.. rubric:: SmartReflex
	   :name: smartreflex-2

	DRA7 platforms use Class 0 SmartReflex. It is a very simple class of
	AVS. The SR compensated voltages for different OPPs of various Voltage
	domains are burnt in the EFUSE registers. So whenever a new OPP is set
	the SR compensate voltage value for that particular OPP is read from the
	EFUSE registers and set.

	On entering an OPP, the voltage value to be selected is no longer the
	traditional nominal voltage, but the voltage meant from the efuse offset
	encoded in millivolts. Each device will have it's own unique voltage for
	given OPP. Therefore, it is not possible to encode a range of voltage
	representing an OPP voltage.

	DRA processors may be powered using various PMICs - I2C based ones such
	as TPS659039 or SPI / GPIO controlled ones as well.

	::

		   cpufreq/devfreq driver which controls voltage and frequency pairs 
		   traditionally used:
		   cpufreq/devfreq --> PMIC regulator
		                   \-> clock framework
		   This opens up a few issues:
		   a) PMIC regulator is designed for platforms that may not use SmartReflex
		      based SoCs, encoding the efuse offsets into every possible PMIC 
		      regulator driver is practically in-efficient.
		   b) Voltage values are not known a-priori to be encoded into DTB as they
		      device specific.

	::

		   To simplify this, we introduce:
		   cpufreq/devfreq --> SmartReflex Class 0 regulator --> PMIC regulator
		                   \-> clock framework

	::

		   Class 0 Regulator has information of translating the "nominal voltage" i
		   voltage value stored in efuse offset.
		   Example encoding:
		   uVolts      mVolt   --> stored as 16 bit hex value of mV
		   975000      975     --> 0x03CF
		   1075000     1075    --> 0x0433
		   1200000     1200    --> 0x04B0

	::

		   [1] http://www.ti.com/lit/ds/sprt659/sprt659.pdf
		   [2] http://www.ti.com/lit/wp/swpy015a/swpy015a.pdf


.. ifconfig:: CONFIG_part_family in ('AM335X_family', 'AM437x_family')

	.. rubric:: Smart Reflex
	   :name: Smart Reflex

	Power management is a wide reaching topic and reducing the power a
	system uses is handled by a number of drivers and techniques. Power
	Management can broadly be classified into two categories: Dynamic/Active
	Power management and Idle Power Management. This page covers power
	topics for the v4.4 Linux kernel. This the most recent version. A full
	history of this guide can be found at `Linux Core Power Management
	User's Guide
	History <http://processors.wiki.ti.com/index.php/Linux_Core_Power_Management_User%27s_Guide_History>`__.

	.. rubric:: Dynamic Power Management Techniques
	   :name: dynamic-power-management-techniques

	Dynamic or active Power management techniques reduce the active power
	consumption by an SoC when the system is active and performing tasks.

	#. DVFS
	#. CPUIdle
	#. **Smartreflex**

	.. rubric:: Smartreflex

	Adaptive Voltage Scaling(AVS) is an active PM Technique and is based on
	the silicon type. SmartReflex is currently only supported on DRA7 and
	AM57 platforms, so more detail can be found under the section specific
	to those SoCs here: `DRA7 and AM57 SmartReflex <#smartreflex-2>`__.

	.. rubric:: Idle Power Management Techniques
	   :name: idle-power-management-techniques

	This ensures the system is drawing minimum power when in idle state i.e
	no use-case is running. This is accomplished by turning off as many
	peripherals as that are not in use.

.. rubric:: Source Location
   :name: source-location-2

::

       drivers/cpufreq/ti-cpufreq.c



