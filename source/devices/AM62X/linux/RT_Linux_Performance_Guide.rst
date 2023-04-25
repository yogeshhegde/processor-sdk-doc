===========================
 RT-linux Performance Guide
===========================

.. rubric::  **Read This First**

**All performance numbers provided in this document are gathered using
following Evaluation Modules unless otherwise specified.**

+----------------+---------------------------------------------------------------------------------------------------------------------+
| Name           | Description                                                                                                         |
+================+=====================================================================================================================+
| AM62x EVM      | AM62x Evaluation Module rev E2 and E3 with ARM running at 1.4 GHz, DDR data rate 1600 MT/S                          |
+----------------+---------------------------------------------------------------------------------------------------------------------+

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

System Benchmarks
-------------------


Cyclictest
^^^^^^^^^^^^^^^^^^^^^^^^^^^

Cyclictest is most commonly used for benchmarking RT systems.
It is one of the most frequently used tools for evaluating the relative performance of real-time systems.
Some performance tests which use Cyclictest are System benchmarking, Latency debugging with tracing and
approximating application performance.

Test command: 
cyclictest -l10000000 -m -Sp90 -i400 -h400 -q

.. csv-table::
    :header: "Latencies","am62xx_sk:per-core"

    "Minimum (usec)","5,5,5,5"
    "Average (usec)","6,6,6,6"
    "Maximum (usec)","65,65,34,40"


Table:  **Cyclictest**
