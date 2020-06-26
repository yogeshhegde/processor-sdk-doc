Watchdog Demo on AM654x PG 1.0
==============================

Introduction
------------

The traditional watchdog with SoC/core reset capability on Linux is not supported on AM654x PG1.0 due to hardware limitation.
In stead, the following workaround is implemented to demostrate the tranditional watchdog functionality as described and shown below.

.. Image:: /images/watchdog_demo.png

* Standard Linux watchdog with MCU RTI0/1 in kernel
* Linux watchdog daemon configures watchdog timeout, strats and feeds the watchdog periodically
* The RTI expiry interrupt is fed into the Safety R5F where the demo firmware instructs DMSC to trigger SoC reset when RTI expiration interrupt is detected.

Running the Demo
----------------
In order for the users to run the watchdog demo, follow the following procedure on the AM654x PG1.0 platform:

1. Replace the IPC firmware with the wdt test firmware

::

    target # ln -sf /lib/firmware/rti_dwwdtest/am65xx_evm/csl_rti_dwwd_test_app_mcu1_0_release.xer5f /lib/firmware/am65x-mcu-r5f0_0-fw

2. Reboot and run the Watchdog demo by starting watchdog

::

    target # watchdog


3. Do normal operations

4. Stop watchdog daemon and observe the system reset occurs within 2-3 minmutes

::

    target # pkill watchdog


5. Restore the IPC firmware after SoC reboot
 
::

    target # ln -sf /lib/firmware/ipc/ti_platforms_cortexR_AM65X_R5F0/messageq_single.xer5f /lib/firmware/am65x-mcu-r5f0_0-fw


 
