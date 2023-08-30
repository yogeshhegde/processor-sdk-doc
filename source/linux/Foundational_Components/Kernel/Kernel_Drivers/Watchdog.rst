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

.. rubric:: Kernel configuration options

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
