.. _pm_sw_arch:

##################################
S/W Architecture of System Suspend
##################################

********
Overview
********

In AM62, Deep Sleep is the state of the SoC in which it consumes very low power
overall yet it is not completely shut off. During Deep Sleep, Certain IPs
(depending on the power domain to which then belong) will lose context on suspend.
S/W should save and restore the context as required across state transitions. DDR is in self-
refresh to allow context saving.

This document explains the overall high level Software Flow of deep sleep in AM62x.

*****************************
System diagram and components
*****************************

.. Image:: /images/AM62x_Deep_Sleep_Flow.png


Above diagram has software sequence for how deep sleep (ie. Suspend to RAM) works on
SK-AM62 ( Read more on the Starter Kit `here <https://www.ti.com/tool/SK-AM62>`__ ).

Deep Sleep Entry:
=================

#. The user first instructs the System to Suspend. This triggers a suspend
   sequence from linux side (which runs on the A53 cluster of the SoC).

#. As part of the TI_SCI driver's suspend hook, I/O isolation is invoked which
   isolates all the pads from their respective pinmuxed controllers. Refer to
   :ref:`Wakeup sources Documentation<pm_wakeup_sources>` to understand more on this.

#. Linux then suspends all the drivers in the order that they are probed.
   After ensuring that there were no faults in suspending the drivers, linux
   then issues core system suspend which ultimately is a PSCI system
   suspend call. Read more about PSCI `here <https://developer.arm.com/Architectures/Power%20State%20Coordination%20Interface>`__

#. At this point only ATF is running on A53 cores and it does the job of
   sending a TISCI Message to the TIFS Core telling it to enter deep sleep
   and then it puts A53 into standby.

#. The TIFS Core then encrypts and writes the contents of it's own SRAM to DDR.

#. Further it stops tick timer, disables interrupts that are not needed, and suspends local drivers.
   After the above steps it sends TISCI To DM for Suspend Finish and enters WFI.

#. The DM (Device Manager) is the final entity in this entire deep sleep sequence. It does the following:

   a. Saves own context to DDR
   b. Disables Security IP LPSCs, such as LPSC_SAUL.
   c. Disables non-critical "IP-less" LPSCs, such as LPSC_main_test.
   d. Saves MAIN PADCONF MMRs
   e. Saves GTC counter and Disable it.
   f. Finally, Suspends OS.

   The OS in this case is the Free RTOS based Device Manager firmware itself. After this step it starts performing final
   Steps toward completion of Suspend to RAM.

#. These steps include the following:

   a. Place DDR into Self Refresh
   b. Place USB into reset isolation
   c. Disable all LPSCs in MAIN except Debug, Always ON
   d. Disable all HSDIVs in MAIN_PLL.
   e. Bypass all MAIN PLLs.
   f. Configure selected wake sources, Enable MAIN IO Isolation.
   g. Disable MCU Core LPSCs, PDs
   h. Bypass MCU PLL

#. Finally, DM R5 Enters WFI with all the other power domains turned OFF except WKUP Always ON.
   DM in WFI will basically wait for the configured wakeup source to trigger
   an interrupt that will act as the wakeup signal.

Deep Sleep Exit:
================

#. External async wakeup from wake source triggers the DM to resume.
#. The DM brings MAIN Domain out of reset.
#. Secure (TIFS) ROM begins to boot.
#. A small piece of code called the FS Stub is required to restore the remaining context and resume the
   TIFS firmware.

   The TIFS Stub is loaded into the ATCM (Tightly Coupled Memory A of the DM R5) during device boot.
   The R5 SPL loads the TIFS Stub (which is a part of tispl.bin) onto DDR at address 0x9dc00000. The DM Firmware
   pulls in this TIFS Stub from DDR RAM to it's ATCM where it then resides as long as the
   device is not shutdown.
#. Then, the rest of the resume sequence is a mirror image of the deep sleep entry sequence.
#. As the A53 core resumes, and subsequently the linux TI_SCI driver's resume hook is called,
   I/O isolation is disabled. This allows the pads to be re-connected to their respective controllers
   and allow the device to function normally post resume.

******************
Learning Resources
******************

#. `AM62x Technical Reference Manual <https://www.ti.com/lit/pdf/spruiv7>`__
#. `Technical White Paper on Enabling Low Power on AM62x <https://www.ti.com/lit/wp/sprad41/sprad41.pdf>`__
#. :ref:`Low Power Modes Documentation<lpm_modes>`

