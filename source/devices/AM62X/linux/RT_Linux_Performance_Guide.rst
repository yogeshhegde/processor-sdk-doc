===========================
 RT-linux Performance Guide
===========================

.. rubric::  **Read This First**

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+---------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                       |
+================+===================================================================================================+
| AM62x EVM      | AM62x Evaluation Module rev E2 and E3 with ARM running at 1.4 GHz, DDR data rate 1600 MT/S        |
+----------------+---------------------------------------------------------------------------------------------------+
| AM62x SK LP    | AM62x LP Starter Kit rev E1 with ARM running at 1250 MHz, LPDDR4 data rate 1600 MT/S              |
+----------------+---------------------------------------------------------------------------------------------------+

Table:  Evaluation Modules

|

.. rubric::  About This Manual

This document provides performance data for each of the device drivers
which are part of the Process SDK Linux package. This document should be
used in conjunction with release notes and user guides provided with the
Process SDK Linux package for information on specific issues present
with drivers included in a particular release.

.. rubric::  If You Need Assistance

For further information or to report any problems, contact
http://e2e.ti.com/ or http://support.ti.com/

Stress-ng and Cyclic Test
^^^^^^^^^^^^^^^^^^^^^^^^^^^

stress-ng (next-generation) will stress test a embedded platform in various selectable ways.
It was designed to exercise various physical subsystems as well as the various
operating system kernel interfaces. stress-ng can also measure test throughput rates;
this can be useful to observe performance changes across different operating system or types of hardware.

Cyclictest is most commonly used for benchmarking RT systems.
It is one of the most frequently used tools for evaluating the relative performance of real-time systems.
Some performance tests which use Cyclictest are System benchmarking, Latency debugging with tracing and
approximating application performance.

Test command for running stress-ng and cyclictest together

``stress-ng -c 4 --cpu-method all &``

``cyclictest -m -Sp80 -i400 -h400 -q -D1h``

.. csv-table::
    :header: "Latencies","am62xx_sk:per-core"

    "Minimum (usec)","6,6,6,6"
    "Average (usec)","8,9,8,8"
    "Maximum (usec)","67,62,63,74"

