.. _pm_sw_arch:

##############
S/W Architecture of System Suspend
##############

Overview
========

The user can deliberately force the system to a low power state. There are
various levels: Suspend to memory (RAM), Suspend to disk, etc. In Upcoming
releases we will support even more modes like MCU Only mode, Partial I/O
mode, etc.

First, let's try to understand what we mean by deep sleep. In AM62, Deep
Sleep is the state of the SoC in which it is consuming very low power
overall yet it is not completely shut off. During Deep Sleep, Certain IPs
(depending on power domain to which then belong) will lose register context on suspend.
SW should save and restore the context as required across state transitions. DDR is in self-
refresh. This mode is primarily used for Suspend to RAM for battery lifetime or backup
operation.

Here, we will try to cover the overall high level Software Flow of how the
system suspends when a user issues a deep sleep.

System diagram and components
=============================

.. Image:: /images/AM62x_Deep_Sleep_Flow.png


Above diagram has software sequence for how deep sleep (ie. Suspend to RAM) works on
SK-AM62 ( Read more on the Starter Kit `here <https://www.ti.com/tool/SK-AM62>`__ ).

#. The user first instructs the System to Suspend. This triggers a suspend
   sequence from linux side (which runs on the A53 cluster of the SoC).

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

#. The DM (Device Manager) who is the final entity in this entire deep sleep sequence. The procedure followed is:

   a. now starts to save it's own context to DDR
   b. Disable Security IP LPSCs, such as LPSC_SAUL.
   c. Disable non-critical"IP-less" LPSCs, such as LPSC_main_test.
   d. Save MAIN PADCONF MMRs
   e. Save GTC counter and Disable it.
   f. Finally, Suspend OS.

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

Learning Resources
==================

#. `AM62x Technical Reference Manual <https://www.ti.com/lit/pdf/spruiv7>`__
#. `Technical White Paper on Enabling Low Power on AM62x <https://www.ti.com/lit/wp/sprad41/sprad41.pdf>`__
#. `How To Enable and Use Low Power Mode on AM62x Guide <../../../../How_to_Guides/Target/How_to_suspend_to_ram_on_AM62x.html>`__

