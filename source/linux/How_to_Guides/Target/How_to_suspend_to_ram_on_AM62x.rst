How to Suspend to RAM (Deep Sleep) on AM62x
============================================

AM62x has limited support for Low Power Mode (LPM) in current SDK release.
Since not all peripheral drivers are updated to work across suspend/resume cycle,
a cut-down version of DT file is provided with limited peripherals and cores enabled
to demonstrate Suspend to RAM (S2R) capability.

.. note::
    The Documentation for Low Power Mode has now moved to Power Management section under `Linux Foundational Components </linux/Foundational_Components/Kernel/Kernel_Drivers/Power_Management/pm_low_power_modes.html>`__

Supported Low power mode:

#. **Suspend to RAM (S2R):** All power domains are off except for Wakeup Domain that has Wakeup Co-processor (DM R5) running. DDR is in Self Refresh.

.. _switching-to-lpm-demo-dts:
Switching to LPM demo dts
-------------------------

LPM demo is only possible with cut-down dtb: k3-am625-sk-lpmdemo.dtb.
U-Boot needs to be configured to switch to this dtb during kernel Image load and execute

**Steps to switch to LPM DT:**

#. Stop boot at U-Boot prompt
#. Run following cmd

    ::

        => run envboot; setenv name_fdt k3-am625-sk-lpmdemo.dtb; run init_mmc; run get_kern_mmc;run get_fdt_mmc;run get_overlay_mmc; booti ${loadaddr} ${rdaddr}:${filesize} ${fdtaddr}

    Alternately, update uEnv.txt to following

    ::

        uenvcmd=run check_for_board; setenv name_fdt k3-am625-sk-lpmdemo.dtb

#. At Linux prompt, using RTC as wakeup source, test S2R using following cmd

    ::

        root@am62xx-evm:~# rtcwake -s 10 -m mem
        rtcwake: wakeup from "mem" using /dev/rtc0 at Fri Feb 24 04:52:49 2023
        [   87.521442] PM: suspend entry (deep)
        [   87.525113] Filesystems sync: 0.000 seconds
        [   87.537560] Freezing user space processes ... (elapsed 0.001 seconds) done.
        [   87.546590] OOM killer disabled.
        [   87.549857] Freezing remaining freezable tasks ... (elapsed 0.001 seconds) done.
        [   87.559075] printk: Suspending console(s) (use no_console_suspend to debug)
        [   87.572006] wlcore: down
        [   87.572670] wlcore: down
        [   87.710673] am65-cpsw-nuss 8000000.ethernet eth0: Link is Down
        [   87.740005] Disabling non-boot CPUs ...
        [   87.744131] CPU1: shutdown
        [   87.744171] psci: CPU1 killed (polled 0 ms)
        [   87.754492] CPU2: shutdown
        [   87.754535] psci: CPU2 killed (polled 0 ms)
        [   87.763646] IRQ 255: no longer affine to CPU3
        [   87.764256] CPU3: shutdown
        [   87.765349] psci: CPU3 killed (polled 4 ms)
        [   87.771071] Enabling non-boot CPUs ...
        [   87.771835] Detected VIPT I-cache on CPU1
        [   87.771952] GICv3: CPU1: found redistributor 1 region 0:0x00000000018a0000
        [   87.772127] CPU1: Booted secondary processor 0x0000000001 [0x410fd034]
        [   87.776179] CPU1 is up
        [   87.776880] Detected VIPT I-cache on CPU2
        [   87.776985] GICv3: CPU2: found redistributor 2 region 0:0x00000000018c0000
        [   87.777137] CPU2: Booted secondary processor 0x0000000002 [0x410fd034]
        [   87.780827] CPU2 is up
        [   87.781440] Detected VIPT I-cache on CPU3
        [   87.781545] GICv3: CPU3: found redistributor 3 region 0:0x00000000018e0000
        [   87.781705] CPU3: Booted secondary processor 0x0000000003 [0x410fd034]
        [   87.785655] CPU3 is up
        [   87.814975] am65-cpsw-nuss 8000000.ethernet: set new flow-id-base 19
        [   87.835671] am65-cpsw-nuss 8000000.ethernet eth0: PHY [8000f00.mdio:00] driver [TI DP83867] (irq=POLL)
        [   87.835736] am65-cpsw-nuss 8000000.ethernet eth0: configuring for phy/rgmii-rxid link mode
        [   87.850935] am65-cpsw-nuss 8000000.ethernet eth1: PHY [8000f00.mdio:01] driver [TI DP83867] (irq=POLL)
        [   87.850983] am65-cpsw-nuss 8000000.ethernet eth1: configuring for phy/rgmii-rxid link mode
        [   88.240106] wlcore: using inverted interrupt logic: 2
        [   88.311185] wlcore: PHY firmware version: Rev 8.2.0.0.245
        [   88.475402] wlcore: firmware booted (Rev 8.9.0.0.86)
        [   88.677895] OOM killer enabled.
        [   88.681034] Restarting tasks ... done.
        [   88.687455] PM: suspend exit
        root@am62xx-evm:~#

This puts system to sleep for 10s and then wakes it up via RTC interrupt

Limitations
-----------

* Following IPs are enabled in k3-am625-sk-lpmdemo.dts and functional across system suspend and resume:
  UART, I2C, RTC, MMC/SD, MMC/eMMC, INTR, GPIO, CPSW, DMA,
  INTA, OSPI, USB, MCAN, DM Timer, ECAP, ehrPWM, DMA, INTA,
  McASP, McSPI, DSS, OLDI, HDMI, CSI.

* Unsupported IPs are disabled in k3-am625-sk-lpmdemo.dts, mainly crypto and IPC with R5 and M4 MCU are unsupported at the moment.

* To reenable DFS during the same session, scaling_min_freq will need to be reset:

    ::

        root@am62xx-evm:~# echo 200000 > /sys/devices/system/cpu/cpufreq/policy0/scaling_min_freq

Upcoming releases will add support for additional peripherals and cores.

Supported Peripherals
---------------------

GPIO
____

The Deep Sleep support for the AM62x GPIOs is provided by two standalone drivers in Linux.

System suspend and resume of the GPIO IP block is fully supported in the `gpio-davinci.c` driver. The information about the requested GPIOs and their state is saved on suspend and restored on resume from deep sleep.

The GPIO interrupts require an additional setup of the IRQ routing in the Interrupt Router (INTR) with the help of TISCI_MSG_RM_IRQ_SET message over TISCI. This interrupt configuration is currently not stored by the System Firmware when entering Suspend-to-RAM. The `irq-ti-sci-intr.c` (INTR) driver provides support for restoring the IRQ routing setup after resuming from Deep Sleep from internally cached state.

Validating the system suspend and resume support for GPIO on AM62x requires verifying the above two components. Any requested GPIO must preserve state after resuming from Deep Sleep and the requested GPIO interrupt handlers must trigger on the specified GPIO state change. The current version of the LPM demo for AM625-SK has a couple of GPIO consumers we can use for validation and testing.

.. rubric:: GPIO state preservation

`GPIO1_49` is used by the leds-gpio driver as heartbeat indicator. When the system is suspended to RAM the LD1 LED on the board will be off. After resuming LD1 must continue to indicate the system heartbeat. We can also switch the trigger to `default-on` and verify if the `brightness` sysfs attribute of the LED device is set to max. value (255).

    ::

        root@am62xx-evm:~# echo default-on > /sys/class/leds/am62-sk\:green\:heartbeat/trigger
        root@am62xx-evm:~# rtcwake -s 1 -m mem
        rtcwake: assuming RTC uses UTC ...
        ...
        root@am62xx-evm:~# cat /sys/class/leds/am62-sk\:green\:heartbeat/brightness
        255

.. rubric:: Interrupt routing state preservation

On AM625-SK, `GPIO1_23` is configured as interrupt for a GPIO IO expander which it's also wired to the SW4 button. We can use the button to generate an interrupt as if it originates from the IO expander. All we need to know is the kernel registering the interrupt.

    ::

        root@am62xx-evm:~# grep davinci_gpio /proc/interrupts
        278:          0      GPIO  23 Edge    -davinci_gpio  0-0022
        root@am62xx-evm:~# rtcwake -s 1 -m mem
        rtcwake: assuming RTC uses UTC ...
        ...
        root@am62xx-evm:~# grep davinci_gpio /proc/interrupts
        278:          0      GPIO  23 Edge    -davinci_gpio  0-0022
        # Press the SW4 button
        root@am62xx-evm:~# grep davinci_gpio /proc/interrupts
        278:          1      GPIO  23 Edge    -davinci_gpio  0-0022

GPU
___

Support for OS Active Power Management (APM) and suspend/resume functionality
is built into the pvrsrvkm out-of-tree module. No additional setup is required.
The device should automatically power down when not in use, which thanks to
Wayland's refresh scheduling should be quite often unless things are actively
being rendered.

Manual testing of the OS suspend/resume functionality with this component is conducted through the following process after :ref:`switching-to-lpm-demo-dts`:

#. Initiate a load to wake up the GPU using rgx_compute_test:

::

    target # rgx_compute_test -f 100 &

#. Trigger a suspend event with a scheduled wakeup:

::

    target # rtcwake -s 3 -m mem

#. Wait for the scheduled wakeup.

The above sequence should result in the background compute task being paused
for the suspend action and then resumed after the scheduled wakeup 3 seconds 
later.
