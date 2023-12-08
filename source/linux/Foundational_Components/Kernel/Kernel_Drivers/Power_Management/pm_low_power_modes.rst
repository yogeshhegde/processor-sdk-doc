.. _lpm_modes:

##############
Low Power Modes
##############

Overview
========

The following sections describe a high-level description of the different low power modes of the
device. If your application requires inactive power management, you must determine which
low power mode described below satisfies your requirements. Each mode must be evaluated
based on power consumption and latency (the time it takes to wakeup to Active mode) requirements. Specific
values are detailed in the device-specific data sheet. As part of this SDK offering,
Texas Instruments has added support for the following low power modes:

#. Deep Sleep
#. MCU Only
#. Partial I/O


Deep Sleep
==========

Deep Sleep AKA Suspend-to-RAM is a low-power mode that allows an embedded device
to retain its state in RAM while the processor is turned off.
This can save a significant amount of power, especially in devices that are
battery-powered.

The benefits of using deep sleep in embedded devices:

#. Faster wake-up: devices can wake up from this low-power state much faster than
   a complete power cycle.
#. Better efficiency: deep sleep can help to improve the efficiency of embedded devices by
   reducing the amount of time that the processor is idle. This is because the processor can
   be kept in a low-power state when it is not needed.

In order to enter deep sleep, use the following command:

.. ifconfig:: CONFIG_part_variant in ('AM62X')

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

.. ifconfig:: CONFIG_part_variant in ('AM62AX')

   ::

      root@am62axx-evm:~# echo mem > /sys/power/state
      [   47.558246] PM: suspend entry (deep)
      [   47.562456] Filesystems sync: 0.000 seconds
      [   47.597364] remoteproc remoteproc1: stopped remote processor 79000000.r5f
      [   47.604640] Freezing user space processes
      [   47.614313] Freezing user space processes completed (elapsed 0.005 seconds)
      [   47.623448] OOM killer disabled.
      [   47.627420] Freezing remaining freezable tasks
      [   47.633363] Freezing remaining freezable tasks completed (elapsed 0.001 seconds)
      [   47.640783] printk: Suspending console(s) (use no_console_suspend to debug)
      [   47.662936] omap8250 2800000.serial: PM domain pd:146 will not be powered off
      [   47.669305] Disabling non-boot CPUs ...
      [   47.671283] psci: CPU1 killed (polled 0 ms)
      [   47.674127] psci: CPU2 killed (polled 4 ms)
      [   47.676794] psci: CPU3 killed (polled 0 ms)

This partially indicates that linux has finished it's deep sleep sequence.
For further confirmation, one can take a look at the TP25/PMIC_LPM_EN pin on the EVM
(after programming the PMCTRL_SYS register (0x43018080) to 0x15). Here, if the pin is 3.3V when active and
0V when in deep sleep.

Refer to the :ref:`Wakeup Sources<pm_wakeup_sources>` section for information on how to wakeup the device from
Deep Sleep mode using one of the supported wakeup sources.


MCU Only
========

.. _pm_mcu_only:

Similar to Deep Sleep, with the major distinction being that the MCU core is kept alive to run applications.
The benefits of using MCU Only mode:

#. Low power consumption: MCU Only mode can save a significant amount of power, especially in battery-powered
   devices. This is because The rest of the SoC status is the same as Deep Sleep and DDR is in self-refresh.
#. Run background tasks: This mode can be used to run background tasks that do not require the full power of the system.
   For example, you could use the firmware on the MCU core to run a watchdog timer, a sensor polling loop,
   or a network communication task.
#. Respond to interrupts: This allows the system to still respond to external events, while it is in a low-power state.

.. ifconfig:: CONFIG_part_variant in ('AM62X')

   To enter MCU Only mode, enable MCU M4 core as a wakeup source in linux:

   ::

      root@am62xx-evm:~# echo enabled > /sys/bus/platform/devices/5000000.m4fss/power/wakeup

.. ifconfig:: CONFIG_part_variant in ('AM62AX')

   To enter MCU Only mode, enable MCU R5 core as a wakeup source in linux:

   ::

      root@am62axx-evm:~# echo enabled > /sys/bus/platform/devices/79000000.r5f/power/wakeup

Now, the SoC can be suspended using the following command:

::

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

Once the SoC enters MCU Only mode, the following log should be printed
on the MCU UART (in most cases it will be /dev/ttyUSB3)

::

    [IPC RPMSG ECHO] Suspend request to MCU-only mode received
    [IPC RPMSG ECHO] Press any key on this terminal to resume the kernel from MCU only mode

Refer to the :ref:`Wakeup Sources<pm_wakeup_sources>` section for information on how to wakeup the device from
MCU Only mode using one of the supported wakeup sources.

Limitations
===========

HWRNG support on GP devices is incompatible with Deep Sleep and MCU Only
modes. To test LPM on GP devices, HWRNG has to be unloaded one-time
before running the Suspend-to-RAM command:

::

   root@evm:@~# modprobe -r optee_rng
