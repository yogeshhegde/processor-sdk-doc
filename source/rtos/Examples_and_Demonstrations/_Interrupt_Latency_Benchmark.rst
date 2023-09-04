.. http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/index_examples_demos.html#interrupt-latency-benchmark

Introduction
============

This page describes the interrupt latency benchmark provided in the 
Processor-SDK for RTOS. This benchmark gives several options for 
different types of load configurations.

This benchmark runs on:

-  AM572x (A15)

The sections below provide details of the application as well as build
and run instructions.

Requirements
============

The following materials are required to run this demonstration:

Hardware

-  TI EVM (see list above)
-  Micro USB cable (provided in EVM kit)

Software

-  Processor-SDK RTOS
-  Code Composer Studio

Software Design
===============

The purpose of this benchmark is to measure the worst case interrupt 
latency under load. This load is achieved by simultaneously running 
a modified version of the Dhrystone benchmark.

Dhrystone
---------

The Dhrystone code is modified to run continuously. Instead of testing 
the host system for DMIPS, Dhrystone threads are created repeatedly 
until the benchmark completes. Essentially, once a Dhrystone thread 
finishes, it is created again. Additionally, the user can specify the 
number of Dhrystone threads to be created.

Interrupt Latency Benchmark
---------------------------

Several design choices were made when creating the interrupt latency 
benchmark.

-  The benchmark task is set to core 0
    * Core 0 is the A15_0 core,
      and is the primary core for the benchmark. The benchmark is forced to
      operate only on this core, no matter the load. This is achieved by setting
      the affinity of the task parameter to 0
-  The benchmark task needs to have a higher priority than the Dhrystone threads
    * If the Dhrystone threads have a priority level that is greater
      than or equal to the benchmark task priority, then the scheduler will schedule
      the two to execute one after another. Thus, the benchmark task will not run
      while the Dhrystone thread is running, but the timer will continue to fire.
      As a result, the benchmark task is stalled and returns invalid data when it
      resumes
-  Results are printed to the UART
    * A UART-based menu has been implemented on the main UART

How to Build the Demo
=====================

Processor-SDK RTOS
------------------

To build the project, navigate to the benchmark’s directory and 
run "gmake clean" and then "gmake all" on windows, or "make
clean" and "make all" on Linux. 

::

     <PROC_SDK_INSTALL_PATH>/benchmarks/interrupt_latency




How to Run the Demo
===================

After building the benchmark, locate the binary under the relevant 
device directory in the interrupt latency benchmark's bin/ directory. 
Additionally, power on the board, connect the micro-USB cable to the 
UART port, and begin a UART console.

::

    <PROC_SDK_INSTALL_PATH>/benchmarks/interrupt_latency/bin/<soc>/
    

CCS
---

To run the benchmark on AM572xx using CCS, use the following steps.

#. Using CCS, launch the target configuration for the EVM CCS-Target
   Configurations (http://software-dl.ti.com/ccs/esd/documents/ccs_custom_target_config.html)
#. In the CCS debug view, create a sync group (http://software-dl.ti.com/ccs/esd/documents/ccs_smp-debug.html)
   with the A15 cores
#. For each core, connect to it and load the binary. The A15_0 
   core should halt at main while the SMP linked cores will begin 
   auto-running upon load
#. Once all cores have been loaded, run them all
#. The output will be sent to the UART console in real time
#. You must manually halt the cores to end the benchmark

.. note::
   -  If running in non-SMP mode, do not create a sync group. Only 
      load and run the binary on the A15_0 core

Secondary Bootloader (SBL)
--------------------------

To run the benchmark on a micro-SD card, follow the 
corresponding steps for AM57x (http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/index_Foundational_Components.html#am57x)

.. note::
   -  The binary is the same format as a .out file

Known Issues and Limitations
============================

When running the benchmark, keep in mind the following
issues which are still being fixed.

#. The cause for several outliers in the data is being 
   investigated

Results
=======

   +----------------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
   |           AM572x           | SMP Disabled          | SMP Disabled          | SMP Disabled          | SMP Enabled           | SMP Enabled           | SMP Enabled           |
   |                            | Dhrystone Disabled    | Dhrystone Enabled     | Dhrystone Enabled     | Dhrystone Disabled    | Dhrystone Enabled     | Dhrystone Enabled     |
   |                            |                       | One Dhry Thread       | Two Dhry Threads      |                       | One Dhry Thread       | Two Dhry Threads      |
   +============================+=======================+=======================+=======================+=======================+=======================+=======================+
   | **HW Interrupt Latency**   |                       |                       |                       |                       |                       |                       |
   +----------------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
   | **Average Max**            |        0.602 us       |        0.576 us       |        0.579 us       |        1.159 us       |        1.150 us       |        1.063 us       |
   +----------------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
   | **Average Min**            |        0.572 us       |        0.572 us       |        0.572 us       |        1.121 us       |        1.102 us       |        1.040 us       |
   +----------------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
   | **Absolute Max**           |        1.510 us       |        1.354 us       |        1.354 us       |        2.916 us       |        2.916 us       |        3.385 us       |
   +----------------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
   | **Absolute Min**           |        0.572 us       |        0.572 us       |        0.572 us       |        1.041 us       |        0.885 us       |        0.885 us       |
   +----------------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
   | **Semaphore Wake Latency** |                       |                       |                       |                       |                       |                       |
   +----------------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
   | **Average Max**            |        1.281 us       |        1.329 us       |        1.281 us       |        2.645 us       |        2.665 us       |        2.812 us       |
   +----------------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
   | **Average Min**            |        1.249 us       |        1.250 us       |        1.250 us       |        2.581 us       |        2.551 us       |        2.657 us       |
   +----------------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
   | **Absolute Max**           |        2.968 us       |        2.812 us       |        2.812 us       |        5.625 us       |        5.468 us       |        7.500 us       |
   +----------------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
   | **Absolute Min**           |        1.093 us       |        1.250 us       |        1.250 us       |        2.343 us       |        2.343 us       |        2.343 us       |
   +----------------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+-----------------------+
 



.. raw:: html
