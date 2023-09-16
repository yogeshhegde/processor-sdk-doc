.. _lpm_modes:

##############
Low Power Modes
##############

Overview
========

The following sections describe a high-level description of the different low power modes of the
device. If your application requires power management, you must determine which
low power mode described below satisfies your requirements. Each mode must be evaluated
based on power consumption and latency (the time it takes to wakeup to Active mode) requirements. Specific
values are detailed in the device-specific data sheet. As part of it's SDK offering,
Texas Instruments has added support for Deep Sleep and MCU Only modes.

Suspend-to-RAM (Deep Sleep)
=========================

Deep Sleep AKA Suspend to RAM is a low-power mode that allows an embedded device
to retain its state in RAM while the processor is turned off.
This can save a significant amount of power, especially in devices that are
battery-powered.

The benefits of using deep sleep in embedded devices:

#. Faster wake-up: devices can wake up from this low-power state much faster than
   a complete power cycle.
#. Better efficiency: deep sleep can help to improve the efficiency of embedded devices by
   reducing the amount of time that the processor is idle. This is because the processor can
   be kept in a low-power state when it is not needed.

Inorder to enter deep sleep, use the following command:

::

    root@am62xx-evm:~# echo mem > /sys/power/state
    [   45.902923] PM: suspend entry (deep)
    [   45.906725] Filesystems sync: 0.000 seconds
    [   45.924512] remoteproc remoteproc0: stopped remote processor 5000000.m4fss
    [   45.931827] Freezing user space processes
    [   45.937861] Freezing user space processes completed (elapsed 0.001 seconds)
    [   45.944868] OOM killer disabled.
    [   45.948087] Freezing remaining freezable tasks
    [   45.953924] Freezing remaining freezable tasks completed (elapsed 0.001 seconds)
    [   45.961330] printk: Suspending console(s) (use no_console_suspend to debug)
    [   45.988085] Disabling non-boot CPUs ...
    [   45.990243] psci: CPU1 killed (polled 0 ms)
    [   45.992334] psci: CPU2 killed (polled 4 ms)
    [   45.994977] psci: CPU3 killed (polled 0 ms)

This partially indicates that linux has finished it's deep sleep sequence.
For further confirmation, one can take a look at the TP25/PMIC_LPM_EN pin on the EVM
(after programming the PMCTRL_SYS register (0x43018080) to 0x15). Here, if the pin is 3.3V when active and
0V when in deep sleep.
Refer to the :ref:`Wakeup Sources<pm_wakeup_sources>` section for information on how to wakeup the device from
Deep Sleep.


MCU Only Mode
=============

Similar to Deep Sleep, with the major distinction being that the MCU M4 core is kept alive.
The benefits of using MCU Only Mode:

#. Low power consumption: MCU Only mode can save a significant amount of power, especially in battery-powered
   devices. This is because The rest of the SoC status is the same as Deep Sleep and DDR is in self-refresh.
#. Run background tasks: This mode can be used to run background tasks that do not require the full power of the system.
   For example, you could use the firmware on the MCU M4 core to run a watchdog timer, a sensor polling loop,
   or a network communication task.
#. Respond to interrupts: This allows the system to still respond to external events, while it is in a low-power state.

To enter MCU Only mode, enable MCU M4 as a wakeup source in linux:

::

    root@am62xx-evm:~# echo enabled > /sys/bus/platform/devices/5000000.m4fss/power/wakeup
    root@am62xx-evm:~# echo mem > /sys/power/state
    [  175.651151] PM: suspend entry (deep)
    [  175.655444] Filesystems sync: 0.000 seconds
    [  175.667559] Freezing user space processes
    [  175.673951] Freezing user space processes completed (elapsed 0.002 seconds)
    [  175.681105] OOM killer disabled.
    [  175.684404] Freezing remaining freezable tasks
    [  175.690155] Freezing remaining freezable tasks completed (elapsed 0.001 seconds)
    [  175.697574] printk: Suspending console(s) (use no_console_suspend to debug)
    [  175.722262] omap8250 2800000.serial: PM domain pd:146 will not be powered off
    [  175.954174] Disabling non-boot CPUs ...
    [  175.956374] psci: CPU1 killed (polled 0 ms)
    [  175.959326] psci: CPU2 killed (polled 0 ms)
    [  175.962024] psci: CPU3 killed (polled 4 ms)


Now, on the MCU UART (in most cases it will be /dev/ttyUSB3)
These logs should be printed:

::

    [IPC RPMSG ECHO] Suspend request to MCU-only mode received
    [IPC RPMSG ECHO] Press any key on this terminal to resume the kernel from MCU only mode
    ## Press any key here and it will trigger a wakeup
    [IPC RPMSG ECHO] Main domain resumed due to MCU UART

On linux side, you'll see the device resumes after this:

::

    [  175.962955] Enabling non-boot CPUs ...
    [  175.963349] Detected VIPT I-cache on CPU1
    [  175.963445] GICv3: CPU1: found redistributor 1 region 0:0x00000000018a0000
    [  175.963511] CPU1: Booted secondary processor 0x0000000001 [0x410fd034]
    [  175.964446] CPU1 is up
    [  175.964691] Detected VIPT I-cache on CPU2
    [  175.964735] GICv3: CPU2: found redistributor 2 region 0:0x00000000018c0000
    [  175.964776] CPU2: Booted secondary processor 0x0000000002 [0x410fd034]
    [  175.965475] CPU2 is up
    [  175.965734] Detected VIPT I-cache on CPU3
    [  175.965782] GICv3: CPU3: found redistributor 3 region 0:0x00000000018e0000
    [  175.965830] CPU3: Booted secondary processor 0x0000000003 [0x410fd034]
    [  175.966775] CPU3 is up
    [  175.967452] ti-sci 44043000.system-controller: ti_sci_resume: wakeup source: 0x90
    [  175.978673] am65-cpsw-nuss 8000000.ethernet: set new flow-id-base 19
    [  175.987680] am65-cpsw-nuss 8000000.ethernet eth0: PHY [8000f00.mdio:00] driver [TI DP83867] (irq=POLL)
    [  175.987710] am65-cpsw-nuss 8000000.ethernet eth0: configuring for phy/rgmii-rxid link mode
    [  175.994440] am65-cpsw-nuss 8000000.ethernet eth1: PHY [8000f00.mdio:01] driver [TI DP83867] (irq=POLL)
    [  175.994453] am65-cpsw-nuss 8000000.ethernet eth1: configuring for phy/rgmii-rxid link mode
    [  176.258903] OOM killer enabled.
    [  176.262045] Restarting tasks ... done.
    [  176.273194] random: crng reseeded on system resumption
    [  176.278516] k3-m4-rproc 5000000.m4fss: received echo reply from 5000000.m4fss
    [  176.285808] PM: suspend exit

Limitations
===========

The Crypto Module fails to work after suspend resume and the issue will be addressed in a future release.
As a result of this, we get these error messages in the resume logs:

::

   ...
   [ 3768.463588] CPU3 is up
   [ 3768.464240] ti-sci 44043000.system-controller: ti_sci_resume: wakeup source: 0x50
   [ 3768.472102] ti-udma 485c0000.dma-controller: pktdma_alloc_chan_resources: chan0 invalid direction (0)
   [ 3768.472124] ti-udma 485c0000.dma-controller: PM: dpm_run_callback(): udma_pm_resume+0x0/0xb4 returns -22
   [ 3768.472149] ti-udma 485c0000.dma-controller: PM: failed to resume early: error -22
   [ 3768.475822] am65-cpsw-nuss 8000000.ethernet: set new flow-id-base 19
   ...
