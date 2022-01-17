.. http://processors.wiki.ti.com/index.php/Linux_Core_Power_Management_User%27s_Guide

Smart Reflex
---------------------------------

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

.. rubric:: Source Location
   :name: source-location-2

::

       drivers/cpufreq/ti-cpufreq.c

.. rubric:: Idle Power Management Techniques
   :name: idle-power-management-techniques

This ensures the system is drawing minimum power when in idle state i.e
no use-case is running. This is accomplished by turning off as many
peripherals as that are not in use.


