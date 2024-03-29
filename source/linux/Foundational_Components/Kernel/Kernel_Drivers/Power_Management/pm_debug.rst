.. _pm_debug:

#################
Debug Information
#################

***************
Low Power Modes
***************

As described in the :ref:`S/W Architecture section<pm_sw_arch>`,
implementing Low Power Modes like Deep Sleep requires a synchronization
between multiple software components. Debugging a LPM issue 
requires finding out which component (Linux, TF-A, TIFS or DM R5) might
be at fault.

The comprehensive way of debugging Deep Sleep starts by looking at all
the commands that have been executed by the DM R5. The steps for getting
this trace and interpreting the logs has been documented in the following FAQ:
`How can we debug Deep Sleep on AM62x/AM62A/AM62P using SYSFW Trace? 
<https://e2e.ti.com/support/processors-group/processors/f/processors-forum/1323581/faq-processor-sdk-am62x-a-p-how-can-we-debug-deep-sleep-on-am62x-am62a-am62p-using-sysfw-trace/5103851#5103851>`__
