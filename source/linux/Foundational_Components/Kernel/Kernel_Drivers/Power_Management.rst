.. http://processors.wiki.ti.com/index.php/Linux_Core_Power_Management_User%27s_Guide

Power Management
---------------------------------

.. rubric:: Power Management Introduction
   :name: power-management-introduction

Power management is a wide reaching topic and reducing the power a
system uses is handled by a number of drivers and techniques. Power
Management can broadly be classified into two categories: Dynamic/Active
Power management and Idle Power Management. This page covers power
topics for the v4.4 Linux kernel. This the most recent version. A full
history of this guide can be found at `Linux Core Power Management
User's Guide
History <http://processors.wiki.ti.com/index.php/Linux_Core_Power_Management_User%27s_Guide_History>`__.

.. rubric:: Dynamic Power Management Techniques
   :name: dynamic-power-management-techniques

Dynamic or active Power management techniques reduce the active power
consumption by an SoC when the system is active and performing tasks.

#. DVFS
#. CPUIdle
#. Smartreflex

.. rubric:: Dynamic Voltage and Frequency Scaling(MPU aka CPUFREQ)
   :name: dynamic-voltage-and-frequency-scalingmpu-aka-cpufreq

Dynamic voltage and frequency scaling, or DVFS as it is commonly known,
is the ability of a part to modify both the voltage and frequency it
operates at based on need, user preference, or other factors. MPU DVFS
is supported in the kernel by the cpufreq driver. All supported SoCs use
the generic cpufreq-cpu0 driver.

Design: OPP is a pair of voltage frequency value. When scaling from High
OPP to Low OPP Frequency is reduced first and then the voltage. When
scaling from a lower OPP to Higher OPP we scale the voltage first and
then the frequency.

.. rubric:: Release applicable
   :name: release-applicable

Latest release this documentation applies to is Kernel v4.4

.. rubric:: Supported Devices
   :name: supported-devices-kernel-pm

-  DRA7xx
-  J6
-  AM57x
-  AM437x
-  AM335x

| 

.. rubric:: Driver Features
   :name: driver-features-kernel-pm

Dynamic voltage and frequency scaling, or DVFS as it is commonly known,
is the ability of a part to modify both the voltage and frequency it
operates at based on need, user preference, or other factors. MPU DVFS
is supported in the kernel by the cpufreq driver. All supported SoCs use
the generic cpufreq-cpu0 driver. The frequency at which the MPU operates
is selected by a driver called a governor. Each governor has a different
strategy for selecting the most appropriate frequency. The following
governors are available within the kernel:

-  **ondemand**: This governor samples the load of the cpu and scales it
   up aggressively in order to provide the proper amount of processing
   power.
-  **conservative**: This governor is similar to ondemand but uses a
   less aggressive method of increasing the the OPP of the MPU.
-  **performance**: This governor statically sets the OPP of the MPU to
   the highest possible frequency.
-  **powersave**: This governor statically sets the OPP of the MPU to
   the lowest possible frequency.
-  **userspace**: This governor allows the user to set the desired OPP
   using any value found within scaling\_available\_frequencies by
   echoing it into scaling\_setspeed.

More in depth documentation about each governor can be found in the
linux kernel documentation here:
https://www.kernel.org/doc/Documentation/cpu-freq/governors.txt

By default, cpufreq, the cpufreq-cpu0 driver, and all of the standard
governors are enabled with the ondemand governor selected as the default
governor. To make changes, follow the instructions below.

.. rubric:: Source Location
   :name: source-location-pm

drivers/cpufreq/ti-cpufreq.c drivers/cpufreq/cpufreq-dt.c

TI cpufreq driver uses efuse information to scale the OPP data based on
silicon characteristics. The OPP data itself is used by the cpufreq DT
driver to scale voltages based on frequency changes for the CPU.

.. rubric:: Kernel Configuration Options
   :name: kconfig-options-pm

The driver can be built into the kernel as a static module, dynamic
module, or both.

$ make menuconfig

Select CPU Power Management from the main menu.

::

       ...
       ...
       Boot options --->
       CPU Power Management --->
       Floating point emulation --->
       ...

Select CPU Frequency Scaling as shown here:

::

       ...
       ...
           CPU Frequency Scaling --->
       [*] CPU idle PM support
       ...

All relevant options are listed below:

::

        [*] CPU Frequency scaling                                 
        <*>   CPU frequency translation statistics                
        [*]     CPU frequency translation statistics details      
              Default CPUFreq governor (userspace)  --->          
        <*>   'performance' governor                              
        <*>   'powersave' governor                                
        -*-   'userspace' governor for userspace frequency scaling
        <*>   'ondemand' cpufreq policy governor                  
        <*>   'conservative' cpufreq governor                     
              *** CPU frequency scaling drivers ***               
        <M>   Generic DT based cpufreq driver                     
        <M>   Generic DT based cpufreq driver using clk notifiers 
        <*>    Texas Instruments CPUFreq support
       ...

.. rubric:: DT Configuration
   :name: dt-configuration

The clock information and the operating-points table need to be added as
given in the example below. The voltage source needs to be hooked to the
cpu0 node. As given below cpu0-supply needs to be mapped to the right
regulator node by looking at the schematics.

::

    /* From arch/arm/boot/dts/am4372.dtsi */ 

    cpus {
            #address-cells = <1>;
            #size-cells = <0>;
            cpu: cpu@0 {
                    compatible = "arm,cortex-a9";
                    enable-method = "ti,am4372";
                    device_type = "cpu";
                    reg = <0>;

                    clocks = <&dpll_mpu_ck>;
                    clock-names = "cpu";

                    operating-points-v2 = <&cpu0_opp_table>;
                    ti,syscon-efuse = <&scm_conf 0x610 0x3f 0>;
                    ti,syscon-rev = <&scm_conf 0x600>;

                    clock-latency = <300000>; /* From omap-cpufreq driver */
            };
    };

    /* From arch/arm/boot/dts/am437x-gp-evm.dts */ 

    &cpu {
            cpu0-supply = <&dcdc2>;
    };

The ``operating-points`` table has been introduced instead of
arch/arm/mach-omap2/oppXXXX\_data.c files for each platform that define
OPPs for each silicon revision. More information can be found in the
`Operating Points <#operating-points>`__ section.

.. rubric:: Driver Usage
   :name: driver-usage-pm

All of the standard governors are built-in to the kernel, and by default
the ondemand governor is selected.

To view available governors,

::

    $ cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_available_governors
    conservative userspace powersave ondemand performance

To view current governor,

::

    $ cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor
    ondemand

To set a governor,

::

    $ echo userspace > /sys/devices/system/cpu/cpu0/cpufreq/scaling_governor

To view current OPP (frequency in kHz)

::

    $ cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_cur_freq
    720000

To view supported OPP's (frequency in kHz),

::

    $ cat /sys/devices/system/cpu/cpu0/cpufreq/scaling_available_frequencies
    275000 500000 600000 720000

To change OPP (can be done only for userspace governor. If governors
like ondemand is used, OPP change happens automatically based on the
system load)

::

    $ echo 275000 > /sys/devices/system/cpu/cpu0/cpufreq/scaling_setspeed

| 

.. rubric:: Operating Points
   :name: operating-points

The OPP platform data defined in arch/arm/mach-omap2/oppXXXX\_data.c has
been replaced by the TI cpufreq driver OPP modification code and the OPP
tables in the DT files. These files allow defining of a different set of
OPPs for each different SoC, and also selective, automatic enabling
based on what is detected to be supported by the specific SoC in use.

::

    /* From arch/arm/boot/dts/am4372.dtsi */

    cpu0_opp_table: opp_table0 {
            compatible = "operating-points-v2";

            opp50@300000000 {
                    opp-hz = /bits/ 64 <300000000>;
                    opp-microvolt = <950000 931000 969000>;
                    opp-supported-hw = <0xFF 0x01>;
                    opp-suspend;
            };

            opp100@600000000 {
                    opp-hz = /bits/ 64 <600000000>;
                    opp-microvolt = <1100000 1078000 1122000>;
                    opp-supported-hw = <0xFF 0x04>;
            };

            opp120@720000000 {
                    opp-hz = /bits/ 64 <720000000>;
                    opp-microvolt = <1200000 1176000 1224000>;
                    opp-supported-hw = <0xFF 0x08>;
            };

            oppturbo@800000000 {
                    opp-hz = /bits/ 64 <800000000>;
                    opp-microvolt = <1260000 1234800 1285200>;
                    opp-supported-hw = <0xFF 0x10>;
            };

            oppnitro@1000000000 {
                    opp-hz = /bits/ 64 <1000000000>;
                    opp-microvolt = <1325000 1298500 1351500>;
                    opp-supported-hw = <0xFF 0x20>;
            };
    };

To implement Dynamic Frequency Scaling (DFS), the voltages in the table
can be changed to the same fixed value to avoid any voltage scaling from
taking place if the system has been designed to use a single voltage.

.. rubric:: CPUIdle
   :name: cpuidle

The cpuidle framework consists of two key components:

A governor that decides the target C-state of the system. A driver that
implements the functions to transition to target C-state. The idle loop
is executed when the Linux scheduler has no thread to run. When the idle
loop is executed, current 'governor' is called to decide the target
C-state. Governor decides whether to continue in current state/
transition to a different state. Current 'driver' is called to
transition to the selected state.

.. rubric:: Release applicable
   :name: release-applicable-1

Latest release this documentation applies to is Kernel v4.4

| 

.. rubric:: Supported Devices
   :name: supported-devices-1

-  AM335x
-  AM437x

.. rubric:: Driver Features
   :name: driver-features-1

AM335x supports two different C-states

-  MPU WFI
-  MPU WFI + Clockdomain gating

AM437x supports two different C-states

-  MPU WFI
-  MPU WFI + Clockdomain gating

| 

.. rubric:: Source Location
   :name: source-location-1

::

    arch/arm/mach-omap2/pm33xx-core.c
    drivers/soc/ti/pm33xx.c
    drivers/cpuidle/cpuidle-arm.c

.. rubric:: Kernel Configuration Options
   :name: kernel-configuration-options-1

The driver can be built into the kernel as a static module.

$ make menuconfig

Select CPU Power Management from the main menu.

::

       ...
       ...
       Boot options --->
       CPU Power Management --->
       Floating point emulation --->
       ...

Select CPU Idle as shown here:

::

       ...
       ...
           CPU Frequency Scaling --->
           CPU Idle --->
       ...

All relevant options are listed below:

::

           [*] CPU idle PM support
           [ ]   Support multiple cpuidle drivers
           [*]   Ladder governor (for periodic timer tick)
           -*-   Menu governor (for tickless system)
                 ARM CPU Idle Drivers  ----

| 

.. rubric:: DT Configuration
   :name: dt-configuration-1

::

    cpus {
            cpu: cpu0 {
                    compatible = "arm,cortex-a9";
                    enable-method = "ti,am4372";
                    device-type = "cpu";
                    reg = <0>;

                    cpu-idle-states = <&mpu_gate>;
            };

            idle-states {
                    compatible = "arm,idle-state";
                    entry-latency-us = <40>;
                    exit-latency-us = <100>;
                    min-residency-us = <300>;
                    local-timer-stop;
            };
    };

.. rubric:: Driver Usage
   :name: driver-usage-1

CPUIdle requires no intervention by the user for it to work, it just
works transparently in the background. By default the ladder governor is
selected.

It is possible to get statistics about the different C-states during
runtime, such as how long each state is occupied.

::

    # ls -l /sys/devices/system/cpu/cpu0/cpuidle/state0/
    -r--r--r--    1 root     root         4096 Jan  1 00:02 desc
    -r--r--r--    1 root     root         4096 Jan  1 00:02 latency
    -r--r--r--    1 root     root         4096 Jan  1 00:02 name
    -r--r--r--    1 root     root         4096 Jan  1 00:02 power
    -r--r--r--    1 root     root         4096 Jan  1 00:02 time
    -r--r--r--    1 root     root         4096 Jan  1 00:02 usage
    # ls -l /sys/devices/system/cpu/cpu0/cpuidle/state1/
    -r--r--r--    1 root     root         4096 Jan  1 00:05 desc
    -r--r--r--    1 root     root         4096 Jan  1 00:05 latency
    -r--r--r--    1 root     root         4096 Jan  1 00:03 name
    -r--r--r--    1 root     root         4096 Jan  1 00:05 power
    -r--r--r--    1 root     root         4096 Jan  1 00:05 time
    -r--r--r--    1 root     root         4096 Jan  1 00:02 usage

.. rubric:: Smartreflex

Adaptive Voltage Scaling(AVS) is an active PM Technique and is based on
the silicon type. SmartReflex is currently only supported on DRA7 and
AM57 platforms, so more detail can be found under the section specific
to those SoCs here: `DRA7 and AM57 SmartReflex <#smartreflex-2>`__.

.. rubric:: Source Location
   :name: source-location-2

::

       drivers/cpufreq/ti-cpufreq.c

.. rubric:: Idle Power Management Techniques
   :name: idle-power-management-techniques

This ensures the system is drawing minimum power when in idle state i.e
no use-case is running. This is accomplished by turning off as many
peripherals as that are not in use.

.. rubric:: Suspend/Resume Support
   :name: suspendresume-support

The user can deliberately force the system to low power state. There are
various levels: Suspend to memory(RAM), Suspend to disk, etc. Certains
parts support different levels of idle, such as DeepSleep0 or standby,
which allow additional wake-up sources to be used with less wake latency
at the expense of less power savings.

.. rubric:: Release applicable
   :name: release-applicable-2

Latest release this documentation applies to is Kernel v4.4.

.. rubric:: Supported Devices
   :name: supported-devices-2

-  DRA7xx
-  J6
-  AM57x
-  AM437x
-  AM335x

.. rubric:: Driver Features
   :name: driver-features-2

This is dependent on which device is in use. More information can be
found in the device specific usage sections below.

.. rubric:: Source Location
   :name: source-location-3

The files that provide suspend/resume differ from part to part however
they generally reside in arch/arm/mach-omap2/pm\*\*\*\*.c for the
higher-level code and arch/arm/mach-omap2/sleep\*\*\*\*.S for the
lower-level code.

.. rubric:: Kernel Configuration Options
   :name: kernel-configuration-options-2

Suspend/resume can be enable or disabled within the kernel using the
same method for all parts. To configure suspend/resume, enter the kernel
configuration tool using:

::

        $ make menuconfig

Select *Power management options* from the main menu.

::

        ...
        ...
        Kernel Features  --->
        Boot options  --->
        CPU Power Management  --->
        Floating point emulation  --->
        Userspace binary formats  --->
        Power management options  --->
        [*] Networking support  --->
        Device Drivers  --->
        ...
        ...

Select *Suspend to RAM and standby* to toggle the power management
support.

::

        [*] Suspend to RAM and standby
        -*- Run-time PM core functionality
        ...
        < > Advanced Power Management Emulation

And then build the kernel as usual.

| 

.. rubric:: Power Management Usage
   :name: power-management-usage

Although the techniques and concepts involved with power management are
common across many platforms, the actual implementation and usage of
each differ from part to part. The following sections cover the
specifics of using the aforementioned power management techniques for
each part that is supported by this release.

.. rubric:: Common Power Management
   :name: common-power-management

.. rubric:: IO Pad Configuration
   :name: io-pad-configuration

In order to optimize power on the I/O supply rails, each pin can be
given a "sleep" configuration in addition to it's run-time
configuration. This can be handled with the pinctrl states defined in
the board device tree for each peripheral. These values are used to
configure the PAD\_CONF registers found in the control module of the
device which allow for selection of the MUXMODE of the pin and the
operation of the internal pull resistor. Typically a device defines it's
pinctrl state for normal operation:

::

    davinci_mdio_default: davinci_mdio_default {
            pinctrl-single,pins = <
                    /* MDIO */
                    0x148 (PIN_INPUT_PULLUP | SLEWCTRL_FAST | MUX_MODE0)    /* mdio_data.mdio_data */
                    0x14c (PIN_OUTPUT_PULLUP | MUX_MODE0)                   /* mdio_clk.mdio_clk */
            >;
    };

In order to define a sleep state for the same device, another pinctrl
state can be defined:

::

    davinci_mdio_sleep: davinci_mdio_sleep {
            pinctrl-single,pins = <
                    /* MDIO reset value */
                    0x148 (PIN_INPUT_PULLDOWN | MUX_MODE7)
                    0x14c (PIN_INPUT_PULLDOWN | MUX_MODE7)
            >;
    };

The driver then defines the sleep state in addition to the default
state:

::

    &davinci_mdio {
            pinctrl-names = "default", "sleep";
            pinctrl-0 = <&davinci_mdio_default>;
            pinctrl-1 = <&davinci_mdio_sleep>;
            ...

Although the driver core handles selection of the default state during
the initial probe of the driver, some extra work may be needed within
the driver to make sure the sleep state is selected during suspend and
the default state is re-selected at resume time. This is accomplished by
placing calls to ``pinctrl_pm_select_sleep_state`` at the end of the
suspend handler of the driver and ``pinctrl_pm_select_default_state`` at
the start of the resume handler. These functions will not cause failure
if the driver cannot find a sleep state so even with them added the
sleep state is still default. Some drivers rely on the default
configuration of the pins without any need for a default pinctrl entry
to be set but if a sleep state is added a default state must be added as
well in order for the resume path to be able to properly reconfigure the
pins. Most TI drivers included with the 3.12 release already have this
done.

The required pinctrl states will differ from board to board;
configuration of each pin is dependent on the specific use of the pin
and what it is connected to. Generally the most desirable configuration
is to have an internal pull-down and GPIO mode set which gives minimal
leakage. However, in a case where there are external pull-ups connected
to the line (like for I2C lines) it makes more sense to disable the pull
on the pin. The pins are supplied by several different rails which are
described in the data manual for the part in use. By measuring current
draw on each of these rails during suspend it may be possible to fine
tune the pin configuration for maximum power savings. The AM335x EVM has
pinctrl sleep states defined for its peripheral and serves as a good
example.

Even pins that are not in use and not connected to anything can still
leak some power so it is important to consider these pins as well when
implementing the pad configuration. This can be accomplished by defining
a pinctrl state for unused pins and then assigning it directly the the
pinctrl node itself in the board device tree so the state is configured
during boot even though there is no specific driver for these pins:

::

    &am43xx_pinmux {
             pinctrl-names = "default";
             pinctrl-0 = <&unused_wireless>;
             ...
             unused_pins: unused_pins {
                     pinctrl-single,pins = <
                            0x80    (PIN_INPUT_PULLDOWN | MUX_MODE7) /* gpmc_csn1.mmc1_clk */
                            ...

.. rubric:: Power Management on AM335 and AM437
   :name: power-management-on-am335-and-am437

Because of the high level of overlap of power management techniques
between the two parts, AM335 and AM437 are covered in the same section.
The power management features enabled on AM335x are as follows:

-  Suspend/Resume

   -  DeepSleep0 is supported with mem power state
   -  Standby is supported with standby power state

-  MPU DVFS
-  CPU-Idle

.. rubric:: CM3 Firmware
   :name: cm3-firmware

A small ARM Cortex-M3 co-processor is present on these parts that helps
the SoC to get to the lowest power mode. This processor requires
firmware to be loaded from the kernel at run-time for all low-power
features of the SoC to be enabled. The name of the binary file
containing this firmware is am335x-pm-firmware.elf for both SoCs. The
git repository containing the source and pre-compiled binaries of this
file can be found here:
https://git.ti.com/processor-firmware/ti-amx3-cm3-pm-firmware/commits/ti-v4.1.y
.

There are two options for loading the CM3 firmware. If using the
CoreSDK, the firmware will be included in /lib/firmware and the root
filesystem should handle loading it automatically. Placing any version
of ``am335x-pm-firmware.elf`` at this location will cause it to load
automatically during boot. However, due to changes in the upstream
kernel it is now required that
CONFIG\_FW\_LOADER\_USER\_HELPER\_FALLBACK be enabled if the
CONFIG\_WKUP\_M3\_IPC is being built-in to the kernel so that the
firmware can be loaded once userspace and the root filesystem becomes
avaiable. It is also possible to manually load the firmware by following
the instructions below:

The final option is to build the binary directly into the kernel. Note
that if the firmware binary is built into the kernel it cannot be loaded
using the methods above and will be automatically loaded during boot. To
accomplish this, first make sure you have placed
``am335x-pm-firmware.elf`` under ``<KERNEL SOURCE>/firmware``. Then
enter the kernel configuration by typing:

::

    $ make menuconfig

Select *Device Drivers* from the main menu.

::

    ...
    ...
    Kernel Features  --->
    Boot options  --->
    CPU Power Management  --->
    Floating point emulation  --->
    Userspace binary formats  --->
    Power management options  --->
    [*] Networking support  --->
    Device Drivers  --->
    ...
    ...

Select Generic Driver Options

::

    Generic Driver Options
    CBUS support
    ...
    ...

Configure the name of the PM firmware and the location as shown below

::

    ...
    -*- Userspace firmware loading support
    [*] Include in-kernel firmware blobs in the kernel binary
    (am335x-pm-firmware.elf) External firmware blobs to build into the kernel binary
    (firmware) Firmware blobs root directory

The CM3 firmware is needed for all idle low power modes on am335x and
am437x and for cpuidle on am335x. During boot, if the CM3 firmware has
been properly loaded, the following message will be displayed:

::

        PM: CM3 Firmware Version = 0x191

.. rubric:: CM3 Firmware Linux Kernel Interface
   :name: cm3-firmware-linux-kernel-interface

The kernel interface to the CM3 firmware is through the wkup\_m3\_rproc
driver, which is used to load and boot the CM3 firmware, and the
wkup\_m3\_ipc driver, which exposes an API to be used by the PM code to
communicate with the CM3 firmware.

.. rubric:: wkup\_m3\_rproc Driver
   :name: wkup_m3_rproc-driver

.. rubric:: Driver Features
   :name: driver-features-3

This driver is responsible for loading and booting the CM3 firmware on
the wkup\_m3 inside the SoC using the remoteproc framework.

.. rubric:: Source Location
   :name: source-location-4

`` drivers/remoteproc/wkup_m3_rproc.c ``

.. rubric:: wkup\_m3\_ipc Driver
   :name: wkup_m3_ipc-driver

.. rubric:: Driver Features
   :name: driver-features-4

This driver exposes an API to be used by the PM code to provide board
and SoC specific data from the kernel to the CM3 firmware, request
certain power state transitions, and query the status of any previous
power state transitions performed by the CM3 firmware.

.. rubric:: Source Location
   :name: source-location-5

`` drivers/soc/ti/wkup_m3_ipc.c `` - provides the wkup\_m3\_ipc driver
responsible for communicating with the CM3 firmware.

.. rubric:: Suspend/Resume

Suspend on am335x and am437x depends on interaction between the Linux
kernel and the wkup\_m3, so there are several requirements when building
the Linux kernel to ensure this will work. The following config options
are required when building a kernel to support suspend:

::

    # Firmware Loading from rootfs
    CONFIG_FW_LOADER_USER_HELPER=y
    CONFIG_FW_LOADER_USER_HELPER_FALLBACK=y

    # AMx3 Power Config Options
    CONFIG_MAILBOX=y
    CONFIG_OMAP2PLUS_MBOX=y
    CONFIG_WKUP_M3_RPROC=y
    CONFIG_SOC_TI=y
    CONFIG_WKUP_M3_IPC=y
    CONFIG_TI_EMIF_SRAM=y
    CONFIG_AMX3_PM=y

    CONFIG_RTC_DRV_OMAP=y

Note that it is also possible to build all of the options under
`` AMx3 Power Config Options `` as modules if desired. Finally, do not
forget the steps mentioned in the `CM3 Firmware <#cm3-firmware>`__
section of the guide to make sure the proper firmware binary is
available.

The LCPD release supports mem sleep and standby sleep. On both AM335 and
AM437 mem sleep corresponds to DeepSleep0. The following wake sources
are supported from DeepSleep0

-  UART
-  GPIO0
-  Touchscreen (AM335x only)

To enter DeepSleep0 enter the following at the command line:

::

        $ echo mem > /sys/power/state

From here, the system will enter DeepSleep0. At any point, triggering
one of the aforementioned wake-up sources will cause the kernel to
resume and the board to exit DeepSleep0. A successful suspend/resume
cycle should look like this:

::

        $ echo mem > /sys/power/state
        $ PM: Syncing filesystems ... done.
        $ Freezing user space processes ... (elapsed 0.007 seconds) done.
        $ Freezing remaining freezable tasks ... (elapsed 0.006 seconds) done.
        $ Suspending console(s) (use no_console_suspend to debug)
        $ PM: suspend of devices complete after 194.787 msecs
        $ PM: late suspend of devices complete after 14.477 msecs
        $ PM: noirq suspend of devices complete after 17.849 msecs
        $ Disabling non-boot CPUs ...
        $ PM: Successfully put all powerdomains to target state
        $ PM: Wakeup source UART
        $ PM: noirq resume of devices complete after 39.113 msecs
        $ PM: early resume of devices complete after 10.180 msecs
        $ net eth0: initializing cpsw version 1.12 (0)
        $ net eth0: phy found : id is : 0x4dd074
        $ PM: resume of devices complete after 368.844 msecs
        $ Restarting tasks ... done
        $

It is also possible to enter standby sleep with the possibility to use
additional wake sources and have a faster resume time while using
slightly more power. To enter standby sleep, enter the following at the
command line:

::

        $ echo standby > /sys/power/state

A successful cycle through standby sleep should look the same as
DeepSleep0.

In the event that a cycle fails, the following message will be present
in the log:

::

        $ PM: Could not transition all powerdomains to target state

This is usually due to clocks that have not properly been shut off
within the PER powerdomain. Make sure that all clocks within CM\_PER are
properly shut off and try again.

.. rubric:: Debugging Techniques
   :name: debugging-techniques

Debugging suspend and resume issues can be inherently difficult because
by nature portions of the processor may be clock gated or powered down,
making traditional methods difficult or impossible.

To aid your debugging efforts, the following resources are available:

-  `Debugging AM335x Suspend Resume
   Issues <http://processors.wiki.ti.com/index.php/Debugging_AM335x_Suspend-Resume_Issues>`__
   (wiki article)
-  `AM335x Low Power Design
   Guide <http://www.ti.com/lit/an/sprac74a/sprac74a.pdf>`__
-  `E2E support forums <http://e2e.ti.com>`__

| 

.. rubric:: RTC-Only and RTC+DDR Mode
   :name: rtc-only-and-rtcddr-mode

The LCPD release also supports two RTC modes depending on what the
specific hardware in use supports. RTC+DDR Mode is similar to the
Suspend/Resume above but only supports wake by the Power Button present
on the board or from an RTC ALARM2 Event. RTC-Only mode supports the
same wake sources, however DDR context is not maintained so a wake event
causes a cold boot.

RTC-Only mode is supported on:

-  AM437x GP EVM
-  AM437x SK EVM

RTC+DDR mode is supported on:

-  AM437x GP EVM

.. rubric:: RTC+DDR Mode
   :name: rtcddr-mode

The first step in using RTC+DDR mode is to enable off mode by typing the
following at the command line:

::

        $ echo 1 > /sys/kernel/debug/pm_debug/enable_off_mode

With off-mode enabled, a command to enter DeepSleep0 will now enter
RTC-Only mode:

::

        $ echo mem > /sys/power/state

this method of entry only supports Power button as the wake source.

To use the rtc as a wake source, after enabling off mode use the
following command:

::

        $ rtcwake -s <NUMBER OF SECONDS TO SLEEP> -d /dev/rtc0 -m mem

Whether or not your board enters RTC-Only mode or RTC+DDR mode depends
on the regulator configuration and whether or not the regulator that
supplies the DDR is configured to remain on during suspend. This is
supported by the TPS65218 in use of the AM437x boards but not the
TPS65217 or TPS65910 present on AM335x boards.

::

    tps65218: tps65218@24 {
            reg = <0x24>;
            compatible = "ti,tps65218";
            interrupts = <GIC_SPI 7 IRQ_TYPE_NONE>; /* NMIn */
            interrupt-parent = <&gic>;
            interrupt-controller;
            #interrupt-cells = <2>;

            ...

            dcdc3: regulator-dcdc3 {
                    compatible = "ti,tps65218-dcdc3";
                    regulator-name = "vdcdc3";
                    regulator-suspend-enable;
                    regulator-min-microvolt = <1500000>;
                    regulator-max-microvolt = <1500000>;
                    regulator-boot-on;
                    regulator-always-on;
            };

            ...

    };

Another important thing to make sure of is that you are using the proper
u-boot. A certain u-boot is required in order to support RTC+DDR mode
otherwise the following message appears during boot of the kernel:

``PM: bootloader does not support rtc-only!``

When building u-boot, rather than using ``am43xx_evm_config`` you must
use ``am43xx_evm_rtconly_config`` to support either RTC mode.

.. rubric:: RTC-Only Mode
   :name: rtc-only-mode

RTC-Only mode does not maintain DDR context so placing a board into
RTC-only mode allows for very low power consumption after which a
supported wake source will cause a cold boot. RTC-Only mode is entered
via the poweroff command.

To wakeup from RTC-Only mode via an RTC alarm, a separate tool must be
used to program an RTC alarm prior to entering poweroff.

.. rubric:: DDR3 VTT Regulator Toggling
   :name: ddr3-vtt-regulator-toggling

Some boards using DDR3 have a VTT Regulator that must be shut off during
suspend to further conserve power. There are two methods that can be
used to toggle DDR3 VTT regulators (or any GPIO for that matter) during
suspend on am335x and am437x, through the use of GPIO0 (AM335x and
AM437x) or IO Isolation (AM437x only).

.. rubric:: GPIO0 Toggling
   :name: gpio0-toggling

An example of a board with this regulator is the AM335X EVM SK. On
AM335x and AM437x, GPIO0 remains powered during DS0 so it is possible to
use this to toggle a pin to control the VTT regulator. This is handled
by the wakeup M3 processor and gets defined inside the device node
within the board device tree file.

::

    &wkup_m3_ipc {
            ti,needs-vtt-toggle;
            ti,vtt-gpio-pin = <7>;
    };

``ti,needs-vtt-toggle`` is used to indicate that the vtt regulator must
be toggled and ``ti,vtt-gpio-pin`` indicates which pin within GPIO0 is
connected to the VTT regulator to control it.

.. rubric:: IO Isolation Control
   :name: io-isolation-control

Many of the pins on AM437x have the ability to configure both normal and
sleep states. Because of this it is possible to use any pin with a
corresponding CTRL\_CONF\_\* register in the control module and the
DS\_PAD\_CONFIG bits to toggle the VTT regulator enable pin. The DS
state of the pin must be configured such that the pin disables the VTT
regulator. The normal state of the pin must be configured such that the
VTT regulator is enabled by the state alone. This is because the VTT
regulator must be enabled before context is restored to the controlling
GPIO.

Example:

On the AM437x GP EVM, the VTT enable line must be held low to disable
VTT regulator and held high to enable, so the following pinctrl entry is
used. The DS pull is enabled which uses a pull down by default and DS
off mode is used which outputs a low by default. For the normal state, a
pull up is specified so that the VTT enable line gets pulled high
immediately after the DS states are removed upon exit from DeepSleep0.

The ``ti,set-io-isolation`` flag below in the ``wkup_m3_ipc`` node tells
the CM3 firmware to place the IO's in isolation and actually trigger the
value provided in the ``ddr3_vtt_toggle_default`` pinctrl entry.

::

            &am43xx_pinmux {
                    pinctrl-names = "default";
                    pinctrl-0 = <&ddr3_vtt_toggle_default>;

                    ddr3_vtt_toggle_default: ddr_vtt_toggle_default {
                    pinctrl-single,pins = <
                            0x25C (DS0_PULL_UP_DOWN_EN | PIN_OUTPUT_PULLUP |
                                   DS0_FORCE_OFF_MODE | MUX_MODE7)>;
                    };
                    ...
            };

            wkup_m3_ipc: wkup_m3_ipc@1324 {
                    compatible = "ti,am4372-wkup-m3-ipc";
                    ...
                    ...
                    '''ti,set-io-isolation;'''
                    ...
            };

.. rubric:: Deep Sleep Voltage Scaling
   :name: deep-sleep-voltage-scaling

It is possible to scale the voltages on both the MPU and CORE supply
rails down to 0.95V while we are in DeepSleep once powerdomains are shut
off. The i2c sequences needed to scale voltage vary from board to board
and are dependent on which PMIC is in use, so we use board specific
binaries that are passed to the CM3 firmware to define the sequences
needed during the sleep and wake paths. The CM3 firmware is then able to
write these sequences out at the proper location in the Deep Sleep path
on i2c0.

The CM3 firmware at
https://git.ti.com/processor-firmware/ti-amx3-cm3-pm-firmware/ti-v4.1.y/bin
contains scale data binaries for these platforms:

**am335x-evm-scale-data.bin**

-  AM335x EVM
-  AM335x Starter kit

**am335x-bone-scale-data.bin**

-  AM335x Beaglebone
-  AM335x Beaglebone Black

**am43x-evm-scale-data.bin**

-  AM437x GP EVM
-  AM437x EPOS EVM
-  AM437x SK EVM

The name of the binary to use is specified in the wkup\_m3\_ipc node
with the ``ti,scale-data-fw`` property of a board file like so:

::

    /* From arch/arm/boot/dts/am437x-gp-evm.dts */
    &wkup_m3_ipc {
            ...
            ti,scale-data-fw = "am43x-evm-scale-data.bin";
    };

The wkup\_m3\_ipc driver at\ ``drivers/soc/ti/wkup_m3_ipc.c`` handles
loading this binary to the proper data region of the CM3 and then
passing the offsets to the wake and sleep sequences through IPC register
5 to the firmware. As long as the format of the binary is proper the
driver will handle this automatically.

.. rubric:: Binary Data Format
   :name: binary-data-format

Each binary file contains a small header with a magic number and offsets
to the sleep wand wake sections and then the sleep and wake sections
themsevles which consist of two bytes to specify the i2c bus speed for
the operation and then blocks of bytes that specify the message. The
header is 4 bytes long and is shown here:

+----------------+-------------------------+
| Size (bytes)   | Field                   |
+================+=========================+
| 2              | Magic Number (0x0c57)   |
+----------------+-------------------------+
| 1              | Offset to sleep data    |
+----------------+-------------------------+
| 1              | Offset to wake data     |
+----------------+-------------------------+

Table:  Scale data binary header

The offsets to the sleep and wake are counted from the first byte after
the header starting at zero and point to the first of the two bytes in
little-endian order that specify the bus speed in kHz. In all scale data
provided by TI the i2c bus speed is specified as 0x6400, which
corresponds to 100kHz. After these two bytes are the message blocks
which can have a variable length. A standard message block is defined
as:

+----------------+---------------------------------------------------------------------------+
| Size (bytes)   | Field                                                                     |
+================+===========================================================================+
| 1              | Message size, counting from first byte \*after\* I2C Bus address below.   |
+----------------+---------------------------------------------------------------------------+
| 1              | I2C Bus Address                                                           |
+----------------+---------------------------------------------------------------------------+
| 1              | First byte of message (typically I2C register address)                    |
+----------------+---------------------------------------------------------------------------+
| 1              | Second byte of message (typically value to write to register)             |
+----------------+---------------------------------------------------------------------------+
| 1              | Nth byte of message                                                       |
+----------------+---------------------------------------------------------------------------+
| ...            | ...                                                                       |
+----------------+---------------------------------------------------------------------------+

Table:  Scale data message block

Each block is a single I2C transaction, and multiple blocks can be
placed one after the other to send multiple messages, as is needed in
the case of PMICs which have GO bits to actually apply the programmed
voltage to the rail.

| 

.. rubric:: Simple Example
   :name: simple-example

Single message for both sleep and wake sequence (from
bin/am335x-evm-scale-data.bin).

Raw binary data using xxd:

::

    a0274052local@uda0274052:~/git-repos/amx3-cm3$ xxd bin/am335x-evm-scale-data.bin 
    0000000: 0c57 0006 0034 022d 251f 0034 022d 252b  .W...4.-%..4.-%+

Explanation of values:

::

    0c57        # Magic number
    00      # Offset from first byte after header to sleep section
    06      # Offset from first byte after header to wake section

    0034        # Sleep sequence section, starts with two bytes to describe i2c bus in khz (100)
    02 2d 25 1f # Length of message, evm i2c bus addr, then message (i2c reg 0x25, write value 0x1f)

    0034        # Wake sequence section, starts with two bytes to describe i2c bus in khz (100)
    02 2d 25 2b # Length of message, evm i2c bus addr, then message (i2c reg 0x25, write value 0x2b) 

.. rubric:: Advanced Example
   :name: advanced-example

Multiple messages on sleep and wake sequence (from
bin/am43x-evm-scale-data.bin).

Raw binary data using xxd:

::

    amx3-cm3$ xxd bin/am43x-evm-scale-data.bin 
    0000000: 0c57 0012 0034 0224 106b 0224 168a 0224  .W...4.$.k.$...$
    0000010: 1067 0224 1a86 0034 0224 106b 0224 1699  .g.$...4.$.k.$..
    0000020: 0224 1067 0224 1a86                      .$.g.$..

Explanation of values:

::

    0C 57           # Magic number 0x0C57
    00          # Offset, starting after header, to sleep sequence
    12          # Offset, starting after header, to wake sequence

    0034            # Sleep sequence section, starts with two bytes to describe i2c bus in khz (100) 
    02 24 10 6b     # msg length 0x02, to i2c addr 0x24, message is (i2c reg 0x10, write 0x6b) 
    02 24 16 8a     # msg length 0x02, to i2c addr 0x24, message is (i2c reg 0x16, write 0x8a)
    02 24 10 67     # msg length 0x02, to i2c addr 0x24, message is (i2c reg 0x10, write 0x67)
    02 24 1a 86     # msg length 0x02, to i2c addr 0x24, message is (i2c reg 0x1a, write 0x86)

    0034            # Wake sequence section, starts with two bytes to describe i2c bus in khz (100)
    02 24 10 6b     # msg length 0x02, to i2c addr 0x24, message is (i2c reg 0x10, write 0x6b) 
    02 24 16 99     # msg length 0x02, to i2c addr 0x24, message is (i2c reg 0x16, write 0x99) 
    02 24 10 67     # msg length 0x02, to i2c addr 0x24, message is (i2c reg 0x10, write 0x67) 
    02 24 1a 86     # msg length 0x02, to i2c addr 0x24, message is (i2c reg 0x1a, write 0x86)         

| 

.. rubric:: Power Management on DRA7 platform
   :name: power-management-on-dra7-platform

The power management features enabled on DRA7 platforms (DRA7x/ J6/
AM57x) are as follows:

-  Suspend/Resume
-  MPU DVFS
-  SmartReflex

.. rubric:: DVFS
   :name: dvfs

On-Demand is a load based DVFS governor, enabled by deafult. The
governor will scale voltage and frequency based on load between
available OPPs.

-  VDD\_MPU supports only 2 OPPs for now (OPP\_NOM, OPP\_OD). OPP\_HIGH
   is not yet enabled. Future versions of Kernel may support OPP\_HIGH.
-  VDD\_CORE has only one OPP which removes the possibility of DVFS on
   VDD\_CORE.
-  GPU DVFS is TBD.

Supported OPPs:

::

          /* kHz    uV */
          1000000 1090000   /* OPP_NOM */
          1176000 1210000   /* OPP_OD */

.. rubric:: SmartReflex
   :name: smartreflex-2

DRA7 platforms use Class 0 SmartReflex. It is a very simple class of
AVS. The SR compensated voltages for different OPPs of various Voltage
domains are burnt in the EFUSE registers. So whenever a new OPP is set
the SR compensate voltage value for that particular OPP is read from the
EFUSE registers and set.

On entering an OPP, the voltage value to be selected is no longer the
traditional nominal voltage, but the voltage meant from the efuse offset
encoded in millivolts. Each device will have it's own unique voltage for
given OPP. Therefore, it is not possible to encode a range of voltage
representing an OPP voltage.

DRA processors may be powered using various PMICs - I2C based ones such
as TPS659039 or SPI / GPIO controlled ones as well.

::

           cpufreq/devfreq driver which controls voltage and frequency pairs 
           traditionally used:
           cpufreq/devfreq --> PMIC regulator
                           \-> clock framework
           This opens up a few issues:
           a) PMIC regulator is designed for platforms that may not use SmartReflex
              based SoCs, encoding the efuse offsets into every possible PMIC 
              regulator driver is practically in-efficient.
           b) Voltage values are not known a-priori to be encoded into DTB as they
              device specific.

::

           To simplify this, we introduce:
           cpufreq/devfreq --> SmartReflex Class 0 regulator --> PMIC regulator
                           \-> clock framework

::

           Class 0 Regulator has information of translating the "nominal voltage" i
           voltage value stored in efuse offset.
           Example encoding:
           uVolts      mVolt   --> stored as 16 bit hex value of mV
           975000      975     --> 0x03CF
           1075000     1075    --> 0x0433
           1200000     1200    --> 0x04B0

::

           [1] http://www.ti.com/lit/ds/sprt659/sprt659.pdf
           [2] http://www.ti.com/lit/wp/swpy015a/swpy015a.pdf

.. rubric:: Idle Power Management
   :name: idle-power-management

DRA7 platform only supports Suspend to RAM as of now. USB has issues in
waking up when is suspended hence suspend/resume feature only suspends
the MPU subsystem alone and does not transition the Core Domain. Core
domain will idle only when USB idles which will mean USB will not be
able to wake up. Hence only MPU is suspended and resumed currently.

Steps to Suspend:

To use UART as wake up source from suspend please sure that
no\_console\_suspend is given in bootargs. This is because UART module
wake up is broken and IO-Daisy wake up is not yet supported.

UART resume needs multiple things:

::

     a) no_console_suspend in bootargs
     b) enable UART wakeup capability.
           echo enabled > /sys/devices/platform/44000000.ocp/48020000.serial/tty/ttyS2/power/wakeup
     c) echo mem > /sys/power/state

