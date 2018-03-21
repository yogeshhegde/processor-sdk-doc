.. http://processors.wiki.ti.com/index.php/How_to_Set_Display_for_AM572x_GP_EVM

How to Set Display for AM572x GP EVM
==================================================================

.. rubric:: Introduction
   :name: introduction

| AM572x GP EVM can have two active displays at the same time: LCD and
  HDMI. By default, LCD is the primary display. This wiki page describes
  the procedure/options of enabling/disabling the displays as well as
  changing the primary/secondary order of the displays.

.. rubric:: Set Displays for AM572x GP EVM
   :name: set-displays-for-am572x-gp-evm

With 0 for LCD and 1 for HDMI, the following options are available:

-  omapdrm.displays=0,1: represents the original order (LCD is the
   primary display, while HDMI is the secondary display)
-  omapdrm.displays=1,0: represents reverse order (HDMI is the primary
   display, while LCD is the secondary display)
-  omapdrm.displays=0: only the LCD is enabled
-  omapdrm.displays=1: only the HDMI is enabled
-  omapdrm.displays=-1: disable all displays

| 
| To set one of the options above, stop at u-boot, and setenv for
  optargs. Run saveenv to save the setting if needed. For example, the
  setenv below will use HDMI as the primary display.

::

    setenv optargs omapdrm.displays=1,0

.. raw:: html

