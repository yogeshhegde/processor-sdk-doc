How to Suspend to RAM (Deep Sleep) on AM62x
============================================

AM62x has limited support for Low Power Mode (LPM) in current SDK release. Since not all peripherals drivers are updated to work across suspend/resume cycle,a cut-down version of DT file is provided with limited peripherals and Cores enabled to demonstrate Suspend to RAM (S2R) capability.

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

        #uenvcmd=run check_for_board; run findfdt
        uenvcmd=run check_for_board; setenv name_fdt k3-am625-sk-lpmdemo.dtb

#. At Linux prompt, using RTC as wakeup source, test S2R using following cmd

    ::

        root@am62xx-evm:~# rtcwake -s 10 -m mem
        rtcwake: wakeup from "mem" using /dev/rtc0 at Fri May 20 09:41:11 2022
        [   42.148655] PM: suspend entry (deep)
        [   42.152391] Filesystems sync: 0.000 seconds
        [   42.166102] Freezing user space processes ... (elapsed 0.001 seconds)    done.
        [   42.175081] OOM killer disabled.
        [   42.178325] Freezing remaining freezable tasks ... (elapsed 0.001 seconds) done.
        [   42.186951] printk: Suspending console(s) (use no_console_suspend to debug)
        [   42.428329] Disabling non-boot CPUs ...
        [   42.826185] OOM killer enabled.
        [   42.829327] Restarting tasks ... done.
        [   42.855525] PM: suspend exit
        root@am62xx-evm:~#

This puts system to sleep for 10s and then wakes it up via RTC interrupt

Limitations
-----------
* Only one A53 core is enabled. Multi-core support is not enabled.
* Following IPs are enabled in k3-am625-sk-lpmdemo.dts and function across system suspend and resume: UART, I2C, RTC, MMC/SD, MMC/eMMC, INTR, GPIO, CPSW, DMA,
  INTA, OSPI, USB, MCAN, DM Timer, ECAP.
* There is a known issue of performance drop after resuming from deep sleep. It can be worked around by temporarily disabling DFS and cycling through deep sleep:

    ::

        root@am62xx-evm:~# echo 1400000 > /sys/devices/system/cpu/cpufreq/policy0/scaling_min_freq
        root@am62xx-evm:~# rtcwake -s 1 -m mem

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
