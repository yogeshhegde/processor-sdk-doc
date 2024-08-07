.. http://processors.wiki.ti.com/index.php/Linux_Core_Watchdog_User%27s_Guide

.. include:: /_replacevars.rst

Watchdog
---------------------------------

Introduction
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric:: Watchdog Driver Overview

- This guide covers K3 RTI-Windowed Watchdog Timer (WWDT) driver.
  It supports watchdogs found on TI's |__PART_FAMILY_NAME__| SoCs.

- The digital windowed watchdog opens a configurable time window
  in which the watchdog must be serviced. Any attempt to service the
  watchdog outside this time window, or a failure to service the
  watchdog in this time window, will cause the watchdog to generate
  an interrupt to the MCU ESM module. The MCU ESM module recieves these
  watchdog interrupts and triggers the reset logic to reset the device.

Driver Features
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. rubric:: Driver Configuration

- Driver source location: drivers/watchdog/rti_wdt.c

- Watchdog module timeout parameter name: heartbeat

- Watchdog module timeout parameter value, in seconds: from 1 to 1000 (default 60)

How to change timeout as kernel module parameter
================================================

The default timeout value can be changed the following way as kernel module parameter:

.. code-block:: console

   root@<machine>:~# lsmod | grep rti
   rti_wdt                12288  0
   root@<machine>:~# rmmod rti_wdt
   root@<machine>:~# modprobe rti_wdt heartbeat=30

The above command changes the timeout from 60s to 30s

How to change timeout using DT property
=======================================

Watchdog timeout can only be changed modprobe or insmod
commands as shown above, this is the default in rti_wdt.c
driver, to change using DT parameter timeout-sec, apply the
diff below for am62x:

.. code-block:: diff

   diff --git a/arch/arm64/boot/dts/ti/k3-am62-main.dtsi b/arch/arm64/boot/dts/ti/k3-am62-main.dtsi
   index 066a82d2d4b8..ab7a5cb0571e 100644
   --- a/arch/arm64/boot/dts/ti/k3-am62-main.dtsi
   +++ b/arch/arm64/boot/dts/ti/k3-am62-main.dtsi
   @@ -952,6 +952,7 @@ main_rti0: watchdog@e000000 {
                   power-domains = <&k3_pds 125 TI_SCI_PD_EXCLUSIVE>;
                   assigned-clocks = <&k3_clks 125 0>;
                   assigned-clock-parents = <&k3_clks 125 2>;
   +               timeout-sec = <30>;
           };

           main_rti1: watchdog@e010000 {
   diff --git a/drivers/watchdog/rti_wdt.c b/drivers/watchdog/rti_wdt.c
   index 79e573bc7e4d..359db4f47b81 100644
   --- a/drivers/watchdog/rti_wdt.c
   +++ b/drivers/watchdog/rti_wdt.c
   @@ -353,7 +353,8 @@ static int rti_wdt_probe(struct platform_device *pdev)
                memunmap(vaddr);
           }

   -       watchdog_init_timeout(wdd, heartbeat, dev);
   +       wdd->timeout = heartbeat;
   +       watchdog_init_timeout(wdd, 0, dev);

           ret = watchdog_register_device(wdd);
        if (ret) {

In the above example, timeout is set to 30s using timeout-sec DT property.

The DTS fixup is for am62x, but the same line could be
applied to any watchdog node using the rti_wdt.c driver.
The method to tell if a watchdog is using this driver is
by looking at the compatible string:

.. code-block:: dts

	compatible = "ti,j7-rti-wdt";

The driver diff can be applied directly for all platforms.

|

********************
Kernel Configuration
********************

Configs to be enabled in kernel:

.. code-block:: text

    CONFIG_WATCHDOG (watchdog support)
    CONFIG_K3_RTI_WATCHDOG (K3 RTI watchdog support)

::

   Device Drivers --->
      <*> Watchdog Timer Support --->
         <*> Texas Instruments K3 RTI watchdog

.. rubric:: Device tree configuration example

.. ifconfig:: CONFIG_part_variant in ('AM62X')

   From k3-am62-main.dtsi:

.. ifconfig:: CONFIG_part_variant in ('AM64X')

   From k3-am64-main.dtsi:

.. code-block:: text

   main_rti0: watchdog@e000000 {
            compatible = "ti,j7-rti-wdt";
            reg = <0x00 0x0e000000 0x00 0x100>;
            clocks = <&k3_clks 125 0>;
            power-domains = <&k3_pds 125 TI_SCI_PD_EXCLUSIVE>;
            assigned-clocks = <&k3_clks 125 0>;
            assigned-clock-parents = <&k3_clks 125 2>;
   };

.. rubric:: Driver Usage

Once the driver is probed, each of watchdogs are exposed as a
character device file by the kernel to be used by userspace:

.. code-block:: text

    /dev/watchdogX        X - watchdog number (zero indexed)

An example of how to use them from a userspace application can be
found in Linux Kernel at: samples/watchdog/watchdog-simple.c.
