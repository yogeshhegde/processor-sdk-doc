
.. _Servo-Drive-Demo-User-Guide-label:

Servo Drive Demo - User Guide
==================================

Overview
--------

The Servo Drive Demo showcases the AM64x device's ability to support a
real-time servo control path by taking EtherCAT CiA402 input and
performing a position/speed loop calculation and sending torque and flux
reference values to a C2000 device over the FSI interface.

.. Image:: /images/Servo_Drive_Demo_1.png
   :width: 800px

HW Setup
--------

-  TI AM64x EVM

-  Windows PC with TwinCAT

   -  Ethernet cable between EVM and TwinCAT PC

-  Ethernet or crossover cable

-  8GB SD card, or JTAG connection to CCS, or OSPI flashed with binaries

-  3x F280049 Launchpad: `LAUNCHXL-F280049C <https://www.ti.com/tool/LAUNCHXL-F280049C>`_

-  3x Low voltage servo motor: `LVSERVOMTR <https://www.ti.com/tool/LVSERVOMTR>`_

-  GaNFET BoosterPack: `BOOSTXL-3PHGANINV <https://www.ti.com/tool/BOOSTXL-3PHGANINV>`_

-  4x FSI serial interface (FSI) adapter boards: `TMDSFSIADAPEVM <https://www.ti.com/tool/TMDSFSIADAPEVM>`_

   -  3x Ethernet cables connecting AM64x EVM in daisy-chain fashion
      between each FSI adapter board

   -  Daisy-chain shown in Overview image

-  5x Female-to-male jumper wires

-  3x 24 volt power supply(s)

   -  for the GaNFET BoosterPack power input

SW Architecture
---------------

The Servo Drive Demo was architected around a central real-time path
that is made up of:

-  ICSSG1 - EtherCAT Slave Controller firmware

-  R5F0_0 - EtherCAT Slave Stack application implementing CiA402 using
   TI RTOS

-  Mailbox IPC - Real-time, low-latency Interrupt based IPC between the
   two R5F cores

-  R5F1_0 - Position Speed Loop application taking speed reference
   values from the EtherCAT master and converting them to torque and
   flux reference value for the C2000 running the current loop

-  FSI - Low pin count, fast serial peripheral to send data to the C2000
   device

This real-time path demonstrates the components needed to make up a
bare-bones Servo Drive from receiving data from an EtherCAT master to
sending the data to the device running the current loop to spin the
motor. In addition to the real-time path the demo also aims to showcase
the available A53 and M4F cores located in the AM64x device:

-  A53 cores - Running RT Linux to host an HTTP web server for a GUI
   composer visualization application

-  M4F core - Runs in an isolated domain separate from the main domain
   cores (A53s and R5s). It monitors the device for ECC errors through
   the ESM (Error Signaling Module) and responds to errors by resetting
   the main domain. The M4F stays alive due to isolation from reset.

The Software Architecture diagram is shown below:

.. Image:: /images/Servo_Drive_Demo_2.png
   :width: 800px

The software stack up in the demo is shown below:

.. Image:: /images/Servo_Drive_Demo_3.png
   :width: 800px

Building Blocks
---------------

Memory Usage
~~~~~~~~~~~~

.. Image:: /images/Servo_Drive_Demo_4.png
   :width: 800px

On-chip SRAM bank partitioning

-  AM64x architecture allows contention-free access to each SRAM bank

-  Demo aims to show customers how to use static linker file
   partitioning to give each core/function its own SRAM space

-  Suggested demo split pictured above

OSPI boot

-  Fast boot option uses OSPI flash to store binaries

-  AM64x EVM has a 128Mb OSPI flash on-board that will hold the M4F,
   R5F, and A53 binaries (excluding Linux filesystem - will be in eMMC
   or SD)

DDR4

-  Expected to be used exclusively by A53/Linux in the Servo Drive Demo

SBL based Combined Boot Flow
~~~~~~~~~~~~~~~~~~~~~~~~~~~~

.. Image:: /images/Servo_Drive_Demo_5.png

-  Solution being demonstrated by the Motor Drive demo is a ‘Combined
   Boot Flow’ based on the RTOS Secondary Boot Loader (SBL) running on
   the R5F boot core that is capable of booting RT Linux on the A53 core

-  Interleaved SBL boot process allows fast booting of the real-time
   control path

   -  Configurable core boot order based on customer needs

   -  Once the R5-1 or M4 program is copied from external memory the
      core can be started immediately, no need to wait for the rest of
      the boot process to complete

-  Optimized Linux Kernel and filesystem can be loaded for fast Linux
   boot

   -  Goal is boot to Linux prompt in < 3 seconds

MCU Channel
~~~~~~~~~~~

.. Image:: /images/Servo_Drive_Demo_6.png
   :width: 800px

The M4 Application demo is broken into 3 main functions listed below:

-  Main Domain monitoring and reset isolation

   -  M4 domain is reset isolated from Main domain so M4 application stays
      alive while rest of SoC reboots.

   -  ICSSG1 is also reset isolated from Main domain so industrial
      ethernet protocols with daisy chain stay connected while SoC reboots.

   -  SoC SRAM and DDR ECC Errors are monitored by M4 through ESM and
      a reset to the Main domain can be triggered in response.

-  Montitor safe inputs and drive safe outputs

   -  The application demos a Safe Torque Off input using SW5 on the EVM. An
      external proximity detection device such as light curtain or mmWave radar
      can also be connected via MCU_GPIO0_6 on J1 (active-low input).

   -  M4 MCU_GPIO0_7 is the Safe Torque Off output which can be connected to
      GaNFET BoosterPack pin 13 (nEnable). This will disable the BoosterPack
      power stage and stop the motors.

-  Black Channel communication path using OC SRAM

   -  Provide an example on the method to safely pass notifications and data
      between the main domain to the M4 core using a combination of the
      mailbox module and dedicated OC SRAM.

   -  Mimics data path recommended for FSoE data coming from the R5F running
      EtherCAT or HDSL Safety data coming from ICSSG0

Inter-Processor Communication (IPC)
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The 3 methods of IPC needed in the demo are:

-  R5F RTOS <-> R5F Bare metal

   -  Needed to pass real-time control data between the R5F cores

   -  Ultra-low latency needed

-  R5F RTOS <-> M4F Bare metal

   -  Will act as an example for the TI approved ‘Black Channel’
      communication path that will be needed in future

   -  SOC architecture and Functional Safety concerns dictate the method
      of passing information

-  A53 Linux <-> R5F RTOS

   -  Needed to expose diagnostics and configuration data between the
      R5F core and the A53

   -  A53 running RT Linux will pass the data to a human consumable GUI

R5F RTOS <-> R5F Bare Metal IPC
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. Image:: /images/Servo_Drive_Demo_7.png

-  Interrupt-based Mailbox CSL communication between R5F cores

   -  Dedicated mailbox clusters 0 and 1 used for message passing
      between R5F Pulsars

   -  Interrupts used to simplify programming and reduce wasted cycles
      on R5F

   -  Theoretical latency for 4 bytes transferred is 304-432ns (measured
      average is 410ns)

   -  Using direct VIM/VIC ISR registration (no software lookup of ISR
      function for each interrupt)

R5F RTOS <-> M4 Bare Metal IPC
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. Image:: /images/Servo_Drive_Demo_8.png

Also uses Interrupt-based Mailbox CSL communication

1. Information from the R5F needs to be passed to the M4

2. Data (payload) placed into OC SRAM shared memory in dedicated SRAM
   bank

3. M4 is notified that data is ready when the R5F uses mailbox to create
   an interrupt to the M4 core

4. M4 retrieves the payload from OC SRAM

Does not violate Functional Safety use case since nothing from the Main
Domain is **pushed** into the MCU Channel except for the Mailbox
interrupt. M4 **pulls** the data from the Main Domain.

As long as a CRC accompanies the payload into the MCU channel before
being checked, the ‘black channel’ is extended.

This path (and its reverse) will be used in future Safety application
demonstrations such as Fail-safe over EtherCAT (FSoE) and HIPERFACE DSL
Safety.

A53 RT Linux <-> R5F RTOS IPC
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

2 distinct use cases for A53 Linux <-> R5F RTOS IPC

-  Passing data to the A53 running Linux to be exposed for human
   consumption

   -  HTTP/OPC UA server providing data to a PC based client application

   -  Human operator can peek at diagnostic information

   -  Human operator can poke in tuning values

   -  Existing rpmsg IPC could suffice, real-time requirement is relaxed
      since data is only for human consumption

   -  This is the Motor Drive Demo use case

-  Passing data to the A53 running Linux to be used in a real-time
   control loop

   -  Method needed for integrating the Motion Controller into the same
      device that is running the Motor Control application

   -  CODESYS Motion Control master runs on RT Linux on an A53

   -  8kHz Motion Control loops (125us) are not uncommon in this use
      case

   -  This places the communication between the A53 and R5F into a
      real-time path where rpmsg WILL NOT suffice

   -  A low-latency IPC between A53 and R5F needs to be developed
      (planned for a later demonstration)

Demo Syncronization Technique
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The EtherCAT slave stack using the CMP1 event of the ICSSG1 IEP
peripheral to create a SYNC0 signal as dictated by the EtherCAT master
in the system. In addition to this signal, the Servo Drive Demo shows an
example to use the CMP7 value aligned to the same IEP counter to
interrupt the position_speed_loop R5F in order to synchronize the
processing and FSI transmissions in the demo. This process is shown
below.

.. Image:: /images/Servo_Drive_Demo_9.png
   :width: 900px

Real-Time Path Timing Diagram
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

The timing diagram of the Servo Drive Demo is shown below and is made up
of:

1.  Position/Speed reference passed to AM64x from Motion Control PLC
    (also the EtherCAT master)

2.  R5F running the EtherCAT slave stack will pass the position/speed
    reference to the real-time control R5F using low-latency Mailbox CSL
    IPC

3.  Real-time control R5F will use the reference value to run its
    control loop to create a torque reference value

4.  Torque reference value passed to C2000 over FSI

5.  C2000 will run its current loop and actuate the motor

6.  Actual speed/position values will be passed from C2000 back to the
    real-time R5F over FSI

7.  Speed/position values are passed from the real-time R5F to the
    EtherCAT slave stack R5F

8.  EtherCAT slave stack passes the speed/position back to the Motion
    Control PLC master (*not shown in diagram*)

9.  EtherCAT master provides SYNC0 pulse every 125us

10. Demo Time Sync (previous slide) creates a pre-trigger using CMP3 and
    Compare Event Router to pre-trigger the real-time R5F

.. Image:: /images/Servo_Drive_Demo_10.png
   :width: 900px

Directory Contents
-------------------
+----+------------------------------------------------------+-------------------------------+
|    | **Directory Name**                                   | **Description**               |
+====+======================================================+===============================+
| 1  | apps/servo_drive_demo/c2000_slave/                   | Contains a README, C2000      |
|    |                                                      | binary for the F28004x        |
|    |                                                      | device, as well as modified   |
|    |                                                      | files to rebuild from source  |
+----+------------------------------------------------------+-------------------------------+
| 2  | apps/servo_drive_demo/common/config/                 | MEMORY section of the linker  |
|    |                                                      | command file for the          |
|    |                                                      | servo_drive_demo              |
+----+------------------------------------------------------+-------------------------------+
| 3  | apps/servo_drive_demo/include/                       | Common structures and         |
|    |                                                      | definitions shared between    |
|    |                                                      | the position_speed_loop and   |
|    |                                                      | ethercat_loop applications    |
+----+------------------------------------------------------+-------------------------------+
| 4  | apps/servo_drive_demo/libs/                          | Libraries provided for the    |
|    |                                                      | servo_drive_demo              |
|    |                                                      | applications:                 |
|    |                                                      |                               |
|    |                                                      | -  ipc_mbx_intr - Mailbox     |
|    |                                                      |    interrupt based IPC        |
|    |                                                      |    mechanism to share         |
|    |                                                      |    real-time data between R5F |
|    |                                                      |    cores                      |
|    |                                                      |                               |
|    |                                                      | -  logs - library to print    |
|    |                                                      |    debug information          |
|    |                                                      |                               |
|    |                                                      | -  r5f_mpu - application      |
|    |                                                      |    specific MPU settings      |
|    |                                                      |                               |
|    |                                                      | -  sciclient - helper         |
|    |                                                      |    functions to simplify      |
|    |                                                      |    common sciclient           |
|    |                                                      |    operations                 |
+----+------------------------------------------------------+-------------------------------+
| 5  | apps/servo_drive_demo/ethercat_loop/                 | TI RTOS based R5F EtherCAT    |
|    |                                                      | slave stack application       |
|    |                                                      | implementing the CiA402       |
|    |                                                      | interface and passing data to |
|    |                                                      | the other R5F over Mailbox    |
|    |                                                      | IPC                           |
+----+------------------------------------------------------+-------------------------------+
| 6  | apps/servo_drive_demo/out/                           | Directory storing the output  |
|    |                                                      | binaries after building the   |
|    |                                                      | applications                  |
+----+------------------------------------------------------+-------------------------------+
| 7  | apps/servo_drive_demo/ethercat_loop/emulation/       | Application written to        |
|    |                                                      | emulate the data generated by |
|    |                                                      | the EtherCAT slave stack.     |
|    |                                                      | Useful for testing the IPC    |
|    |                                                      | between cores without the     |
|    |                                                      | complication of the full      |
|    |                                                      | EtherCAT stack or EtherCAT    |
|    |                                                      | master.                       |
+----+------------------------------------------------------+-------------------------------+
| 8  | apps/servo_drive_demo/position_speed_loop/           | Baremetal based R5F           |
|    |                                                      | application performing the    |
|    |                                                      | position speed loop and       |
|    |                                                      | passing references values to  |
|    |                                                      | the C2000 over FSI            |
+----+------------------------------------------------------+-------------------------------+
| 9  | apps/servo_drive_demo/position_speed_loop/emulation/ | Application written to        |
|    |                                                      | emulate the data transfer     |
|    |                                                      | between the                   |
|    |                                                      | position_speed_loop R5F and   |
|    |                                                      | the ethercat_loop R5F. A      |
|    |                                                      | loopback is performed on the  |
|    |                                                      | data received.                |
+----+------------------------------------------------------+-------------------------------+
| 10 | apps/servo_drive_demo/safety_app/                    | Baremetal based M4F           |
|    |                                                      | application to showcase reset |
|    |                                                      | isolation and black channel   |
|    |                                                      | communication with the Main   |
|    |                                                      | Domain.                       |
+----+------------------------------------------------------+-------------------------------+
