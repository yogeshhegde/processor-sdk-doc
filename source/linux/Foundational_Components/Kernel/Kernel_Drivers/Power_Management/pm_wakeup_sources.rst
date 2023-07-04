.. _pm_wakeup_sources:

##############
Wakeup Sources
##############

This section talks about the numerous ways in which we can wakeup the AM625 from Low Power modes like MCU only or S2RAM.
The AM625 SOC supports various wakeup sources like GP Timers, RTC Timer, UART, I2C, WKUP GPIO, and I/O Daisy Chain.

RTC Real-Time Clock
==================

It's possible to use the internal SOC RTC to wakeup the system using the command rtcwake:

::

    rtcwake

    - Show whether an alarm is set or not:
        rtcwake -m show -v

    - Suspend to RAM and wakeup after 10 seconds:
        rtcwake -m mem -s {{10}}

    - Suspend to disk (higher power saving) and wakeup 15 minutes later:
        rtcwake -m disk --date +{{15}}min

    - Freeze the system (more efficient than suspend-to-RAM but version 3.9 or newer of the Linux kernel is required) and wakeup at a given date and time:
        rtcwake -m freeze --date {{YYYYMMDDhhmm}}

    - Disable a previously set alarm:
        rtcwake -m disable

    - Perform a dry run to wakeup the computer at a given time. (Press Ctrl + C to abort):
        rtcwake -m on --date {{hh:ss}}



For example, if you wish to wakeup from deep sleep in 10 seconds, use the command like this:

::

    root@am62xx-evm:~# rtcwake -s 10 -m mem
    rtcwake: wakeup from "mem" using /dev/rtc0 at Thu Apr 28 18:05:07 2022
    [  217.136973] PM: suspend entry (deep)
    [  217.140747] Filesystems sync: 0.000 seconds
    [  217.147762] Freezing user space processes
    [  217.153867] Freezing user space processes completed (elapsed 0.002 seconds)
    [  217.160915] OOM killer disabled.
    [  217.164149] Freezing remaining freezable tasks
    [  217.170101] Freezing remaining freezable tasks completed (elapsed 0.001 seconds)
    [  217.177507] printk: Suspending console(s) (use no_console_suspend to debug)
    [  217.430054] Disabling non-boot CPUs ...
    [  217.432261] psci: CPU1 killed (polled 0 ms)
    [  217.435103] psci: CPU2 killed (polled 0 ms)
    [  217.437754] psci: CPU3 killed (polled 0 ms)
    [  217.438625] Enabling non-boot CPUs ...
    [  217.439024] Detected VIPT I-cache on CPU1
    [  217.439117] GICv3: CPU1: found redistributor 1 region 0:0x00000000018a0000
    [  217.439182] CPU1: Booted secondary processor 0x0000000001 [0x410fd034]
    [  217.440126] CPU1 is up
    [  217.440374] Detected VIPT I-cache on CPU2
    [  217.440419] GICv3: CPU2: found redistributor 2 region 0:0x00000000018c0000
    [  217.440461] CPU2: Booted secondary processor 0x0000000002 [0x410fd034]
    [  217.441134] CPU2 is up
    [  217.441392] Detected VIPT I-cache on CPU3
    [  217.441442] GICv3: CPU3: found redistributor 3 region 0:0x00000000018e0000
    [  217.441486] CPU3: Booted secondary processor 0x0000000003 [0x410fd034]
    [  217.442257] CPU3 is up
    [  217.442874] ti-sci 44043000.system-controller: ti_sci_resume: wakeup source: 0x50
    [  217.454117] am65-cpsw-nuss 8000000.ethernet: set new flow-id-base 19
    [  217.463141] am65-cpsw-nuss 8000000.ethernet eth0: PHY [8000f00.mdio:00] driver [TI DP83867] (irq=POLL)
    [  217.463172] am65-cpsw-nuss 8000000.ethernet eth0: configuring for phy/rgmii-rxid link mode
    [  217.469924] am65-cpsw-nuss 8000000.ethernet eth1: PHY [8000f00.mdio:01] driver [TI DP83867] (irq=POLL)
    [  217.469938] am65-cpsw-nuss 8000000.ethernet eth1: configuring for phy/rgmii-rxid link mode
    [  217.728474] OOM killer enabled.
    [  217.731625] Restarting tasks ... done.
    [  217.737936] random: crng reseeded on system resumption
    [  217.743270] k3-m4-rproc 5000000.m4fss: received echo reply from 5000000.m4fss
    [  217.751165] PM: suspend exit
    root@am62xx-evm:~#

MCU GPIO
========

One of the most common ways to wakeup a system is by using some I/O activity. MCU GPIOs allow us to do this
by configuring the MCU GPIO controller as a wakeup source.
In ideal scenarios, The firmware running on MCU M4 is responsible to configure MCU GPIO's as wakeup sources.
However if the application design doesn't rely too much on the firmware running on the MCU M4 then
linux can be used to configure the MCU GPIOs as a wakeup source. You can refer to
`MCU GPIO overlay <https://git.ti.com/cgit/ti-linux-kernel/ti-linux-kernel/tree/arch/arm64/boot/dts/ti/k3-am625-sk-mcu-gpio-wakeup.dtso?h=ti-linux-6.1.y-cicd>`__
and use it as a template to cofigure the MCU GPIO of your choice as a wakeup capable GPIO.

A brief guide to configuring an MCU GPIO as wakeup:

First, we add gpio-keys as a compatible string, refer to `gpio_keys kernel documentation <https://www.kernel.org/doc/Documentation/devicetree/bindings/input/gpio-keys.txt>`__
for details.

::

    compatible = "gpio-keys";


Set the desired pinctrl,

::

    pinctrl-names = "default";
    pinctrl-0 = <&wake_mcugpio1_pins_default>;

Setup the interrupt parent and interrupt as MCU_GPIO0,

::

    interrupt-parent = <&mcu_gpio0>;
    interrupts = <16 IRQ_TYPE_EDGE_RISING>;

Now, under the switch node we add the following:

::

    switch {
                label = "MCUGPIO";
                linux,code = <143>;
                gpios = <&mcu_gpio0 16 GPIO_ACTIVE_LOW>;
                wakeup-source;
    };

#. The label is the descriptive name of the key. The string will reflect under /proc/interrupts as:

    ::

        root@am62xx-evm:~# cat /proc/interrupts | grep "MCUGPIO"
        262:          0          0          0          0      GPIO  16 Edge    -davinci_gpio  MCUGPIO

#. linux,code: Keycode to emit.
#. gpios: the gpio required to be used as the gpio-key.
#. The `wakeup-source <https://www.kernel.org/doc/Documentation/devicetree/bindings/power/wakeup-source.txt>`__ property describes
   devices which have wakeup capability.

This indicates that gpio_keys can wake-up the system from deep sleep.

The reason we can easily use MCU GPIOs to wakeup the system from deep sleep is because
MCU GPIO's are in a power domain that is never really shut down. This means that this domain
stays ON even when the SOC is in deep sleep. Hence, the GPIO controller is able to act as a wakeup
source and send a wakeup interrupt to the Device Manager. To understand the role of Device Manager
please refer to :ref:`S/W Architecture of System Suspend<pm_sw_arch>`

Main UART (I/O Daisy Chain)
=============================

The main domain is essentially shut down when the SOC enters low power mode. This includes controllers like
Main UART, GPIO, I2C, etc. The question then arises how to wakeup the SOC from peripherals connected
to for example main UART? Here's where the role of I/O daisychaining comes in.
At the hardware level, all the pads in an SOC have to be pinmuxed to dedicated controllers like UART or GPIO.

For example, If a key press on main UART (which is used for linux console logs)
were to wakeup the system from deep sleep then simply configuring the Main UART controller as a
wakeup source wouldn't suffice. This is because the UART controller is powered off and wouldn't be able to
register any key press as such. However, at the "pad" level we are still connected, and the pads have
a specific way to be configured as wakeup sources.

For detailed information and sequence please refer to
I/O Power Management and Daisy Chaining section in the TRM. To briefly explain,
Setting the 29th Bit in the desired padconfig register, allows the pad to act as a wakeup source by
triggering a wake irq to the DM R5 in deep sleep states.

.. note::
    AM62x supports the ability to wakeup using pad based wake event ONLY in Deep Sleep or MCU Only Mode.
    During active system usage, even if the wake_enable bit is set the system will be unresponsive to any wakeup
    activity on that pad.


To demonstrate I/O daisychain wakeup as part of TI AM62x SDK offering, main_uart0 is used where
a key press on the linux console can wakeup the system from deep sleep. The way to configure UART
as an I/O daisychain wakeup, refer to the
main_uart0 node in `k3-am62x-sk-common.dtsi <https://git.ti.com/cgit/ti-linux-kernel/ti-linux-kernel/tree/arch/arm64/boot/dts/ti/k3-am62x-sk-common.dtsi?h=ti-linux-6.1.y-cicd#n329>`_

::

    interrupts-extended = <&gic500 GIC_SPI 178 IRQ_TYPE_LEVEL_HIGH>,
                <&main_pmx0 0x1c8>; /* (D14) UART0_RXD PADCONFIG114 */
    interrupt-names = "irq", "wakeup";

Here, we chain the IRQ to the pinctrl driver using the second interrupts-extended entry.
The wake IRQ framework in linux works in such a way that the second entry gets marked as a
wakeup source, and then the pinctrl driver is informed that the pad 0x1c8 in this case is to
be configured as a wakeup pad when system enters deep sleep.

To use main_uart0 as a wakeup source, ensure serial is a wake-irq in /proc/interrupts:

::

    root@am62xx-evm:~# grep wakeup /proc/interrupts
    231:          0          0          0          0   pinctrl 456 Edge 2800000.serial:wakeup

Then, run this script:

::

    #!/bin/bash -xe

    # Detach kernel serial console
    consoles=$(find /sys/bus/platform/devices/*.serial/ -name console)
    for console in ${consoles}; do
            echo -n N > ${console}
    done

    # Configure PM runtime autosuspend
    uarts=$(find /sys/bus/platform/devices/*.serial/power/ -type d)
    for uart in $uarts; do
            echo -n 3000 > $uart/autosuspend_delay_ms
            echo -n enabled > $uart/wakeup
            echo -n auto > $uart/control
    done

    # Configure wake-up from suspend
    uarts=$(find /sys/class/tty/tty[SO]*/power/ -type d 2>/dev/null)
    for uart in $uarts; do
            echo -n enabled > $uart/wakeup
    done


This will configure UART to act as deep sleep wakeup source, and
then a *key press* on same terminal should trigger a wakeup from deep sleep.

Any other pad can be chosen as per application requirements depending on which pad is required
to wakeup the system.

MCU M4 IPC based WAKEUP
======================

It's possible to use IPC based wakeup events from the MCU M4. For details on how to implement this
from the firmware side, please refer to the `MCU+ SDK Documentation <https://software-dl.ti.com/mcu-plus-sdk/esd/AM62X/08_06_00_18/exports/docs/api_guide_am62x/index.html>`__.

.. note::
    The Linux SDK 09.00 release image MCU Firmware expects that if device enters MCU Only mode then it will wakeup
    **only** from MCU UART key press. It expects that no other wakeup sources wake the system. This doesn't block wakeup
    from other sources, but the MCU M4 may enter an unclean state as it waits for a wakeup event and recieves none.

    To accomodate other wakeup sources, please build and use the latest firmware from MCU+SDK.