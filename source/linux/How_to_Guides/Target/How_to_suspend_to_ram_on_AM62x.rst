How to Suspend to RAM (Deep Sleep) on AM62x
============================================

AM62x has limited support for Low Power Mode (LPM) in current SDK release. Since not all peripherals drivers are updated to work across suspend/resume cycle,a cut-down version of DT file is provided with limited peripherals and Cores enabled to demonstrate Suspend to RAM (S2R) capability.

Supported Low power mode:

#. **Suspend to RAM (S2R):** All power domains are off except for Wakeup Domain that has Wakeup Co-processor (DM R5) running. DDR is in Self Refresh.

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
* Following IPs are enabled in k3-am625-sk-lpmdemo.dts and function across system suspend and resume: UART, I2C, RTC, MMC/SD, MMC/eMMC.

Upcoming releases will add support for additional peripherals and cores.
