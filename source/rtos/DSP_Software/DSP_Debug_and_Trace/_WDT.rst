.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_WDT

Introduction
------------

The Watchdog Timer Module provides configuration and use of the watchdog
timer mode for the DSP local timers. The watchdog mode is a 64-bit timer
mode for the local timers.

Modes of Operation
------------------

Following modes of operations are supported

-  **DEFAULT_NO_OUTPUT_EVENT**: Default on system reset, WD timeout
   causes no output event
-  **LOCAL_RESET_INPUT**: WD timeout causes local reset input to CorePac
-  **NMI_INPUT**: WD timeout causes NMI input to CorePac
-  **NMI_INPUT_PLUS_LOCAL_RESET_INPUT**: WD timeout causes an NMI input
   followed by a local reset input. The delay between the NMI and the
   local reset is configurable.
-  **DEVICE_RESET**: WD timeout event causes a device reset.

Resets can be configured as a hard or soft reset.

Driver Configuration
--------------------

Watchdog Timer Configuration Structure
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The watchdog timer configuration is passed at the time of the
WatchdogTimer_Init() function call and cannot be changed afterwards. For
details about individual fields of the configuration structure,
WatchdogTimer_InitCfg, see the Watchdog Timer XDC by opening
``[PDK_INSTALL_DIR]\packages\ti\instrumentation\wdtimer\WatchdogTimer.xdc``.

APIs
^^^^

API reference for application:

::

    #include <ti/instrumentation/wdtimer/WatchdogTimer.h>

Initialize a Watchdog Timer
^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. code:: c

     ...
     memset((void *)&wdCfg, 0, sizeof(WatchdogTimer_InitCfg));

     wdCfg.wdPeriodLo = ...;
     wdCfg.wdPeriodHi = ...;
     ...
     /* Initialize and start the timer */
     WatchdogTimer_Init(&wdCfg);

At this point the watchdog timer is enabled and running.

Service Watchdog Timer
^^^^^^^^^^^^^^^^^^^^^^

The watchdog timer must be serviced prior to the configured period in
order to avoid a timeout. The following API is used to service the
watchdog timer, resetting the count back to zero.

::

    WatchdogTimer_ResetTimer()

Tests
^^^^^

+-----------------------+-----------------------+-----------------------+
| Name                  | Description           | Expected Results      |
+=======================+=======================+=======================+
| Watchdog Timer Test   | | Tests configuration | | Watchdog timer      |
| Application           |   and expiration of   |   expires on all DSP  |
|                       |   DSP watchdog        |   cores.              |
|                       |   timers. Reference   |                       |
|                       |   test for            | | See                 |
|                       |   developers.         |   ti/instrumentation/ |
|                       |                       |   wdtimer/test/       |
|                       |                       |   README.t xt         |
|                       |                       |   for more details.   |
+-----------------------+-----------------------+-----------------------+

Additional References
---------------------

+-----------------------------------+-----------------------------------+
| **Document**                      | **Location**                      |
+-----------------------------------+-----------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)\\packages\\ |
|                                   | ti\\instrumentation\\wdtimer\\    |
|                                   | docs\\doxygen\\html\\index.html   |
+-----------------------------------+-----------------------------------+
| Release Notes                     | $(TI_PDK_INSTALL_DIR)\\packages\\ |
|                                   | ti\\instrumentation\\wdtimer\\do  |
|                                   | cs\\ReleaseNotes_WatchdogTimer.pdf|
+-----------------------------------+-----------------------------------+

