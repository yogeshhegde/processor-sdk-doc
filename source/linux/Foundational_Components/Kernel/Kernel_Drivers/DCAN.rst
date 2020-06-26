.. http://processors.wiki.ti.com/index.php/Linux_Core_DCAN_User%27s_Guide

DCAN
---------------------------------

.. rubric:: **Introduction**
   :name: introduction-linux-dcan

The Controller Area Network is a serial communications protocol which
efficiently supports distributed real-time control with a high level of
security. The DCAN module supports bitrates up to 1 Mbit/s and is
compliant to the CAN 2.0B protocol specification. The core IP within
DCAN is provided by Bosch.

This wiki page provides usage information of DCAN Linux driver.

.. rubric:: **Acronyms & definitions**
   :name: acronyms-definitions

+-----------+---------------------------+
| Acronym   | Definition                |
+===========+===========================+
| CAN       | Controller Area Network   |
+-----------+---------------------------+
| BTL       | Bit timing logic          |
+-----------+---------------------------+
| DLC       | Data Length Code          |
+-----------+---------------------------+
| MO        | Message Object            |
+-----------+---------------------------+
| LEC       | Last Error Code           |
+-----------+---------------------------+
| FSM       | Finite State Machine      |
+-----------+---------------------------+
| CRC       | Cyclic Redundancy Check   |
+-----------+---------------------------+

Table:  **DCAN Driver: Acronyms**

.. rubric:: **Setup Details**
   :name: setup-details

.. rubric:: **EVM List**
   :name: evm-list

+-----------+------------------------------+-----------------------+-------------------+----------------------+
| SoC       | EVM                          | Number of Instances   | Connection Type   | Enabled by default   |
+===========+==============================+=======================+===================+======================+
| AM335x    | General Purpose EVM          | 1                     | DB9               | No                   |
+-----------+------------------------------+-----------------------+-------------------+----------------------+
| AM437x    | General Purpose EVM          | 2                     | DB9               | Yes                  |
+-----------+------------------------------+-----------------------+-------------------+----------------------+
| 66AK2Gx   | General Purpose EVM          | 2                     | DB9               | Yes                  |
+-----------+------------------------------+-----------------------+-------------------+----------------------+
| AM571x    | Industrial Development Kit   | 1                     | Header            | Yes                  |
+-----------+------------------------------+-----------------------+-------------------+----------------------+
| DRA74x    | Evaluation Module            | 1                     | Header            | Yes                  |
+-----------+------------------------------+-----------------------+-------------------+----------------------+
| DRA72x    | Evaluation Module            | 1                     | Header            | Yes                  |
+-----------+------------------------------+-----------------------+-------------------+----------------------+

Table:  EVMs DCAN Driver is Validated on

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
On AM335x GP EVM CAN does not work by default. The evm must have its
"Profile Switch" set to 1 to enable CAN support.

.. raw:: html

   </div>

.. rubric:: **Hardware/Software Changes to Enable CAN Support**
   :name: hardwaresoftware-changes-to-enable-can-support

.. rubric:: **AM335x General Purpose EVM**
   :name: am335x-general-purpose-evm

Most TI boards by default will allow the user to use CAN without any
changes. The boards that do require modifications to be enabled for CAN
to work will be listed below.

+-------------------------------------------------------------+---------------------------------------------+
| .. raw:: html                                               | .. raw:: html                               |
|                                                             |                                             |
|    <div class="center">                                     |    <div class="center">                     |
|                                                             |                                             |
| .. raw:: html                                               | .. raw:: html                               |
|                                                             |                                             |
|    <div class="thumb tnone">                                |    <div class="thumb tnone">                |
|                                                             |                                             |
| .. raw:: html                                               | .. raw:: html                               |
|                                                             |                                             |
|    <div class="thumbinner"                                  |    <div class="thumbinner"                  |
|    style="width:302px;">                                    |    style="width:598px;">                    |
|                                                             |                                             |
| .. Image:: /images/Am335x-profile-selection.png             | .. Image:: /images/Dcan_node.png            |
|                                                             |                                             |
| .. raw:: html                                               | .. raw:: html                               |
|                                                             |                                             |
|    <div class="thumbcaption">                               |    <div class="thumbcaption">               |
|                                                             |                                             |
| .. raw:: html                                               | .. raw:: html                               |
|                                                             |                                             |
|    <div class="magnify">                                    |    <div class="magnify">                    |
+-------------------------------------------------------------+---------------------------------------------+
| enable)                                                     | disabled to okay                            |
+-------------------------------------------------------------+---------------------------------------------+

Table:  AM335x Hardware and Software modifications


By default the CAN signals on the AM335x GP EVM isn't routed to the CAN
connector. To do so you must configure the EVM to profile 1 instead of
profile 0 which is the default. The profile switch can be found in front
of the LCD screen next to the brown ribbon cable. Pictures of the EVM
using profile 1 is shown above.

Since CAN from a hardware perspective isn't enabled on the EVM by
default it is kept disabled by default. Luckily to re-enable it is
relatively simple. The user must edit the am335x-evm.dts (device tree
file used for this specific evm). Edit the dcan1 node by changing the
node's status from "disabled" to "okay". Example of this change can be
seen above.

.. rubric:: **Connection Configuration**
   :name: connection-configuration

+----------------------------------------+-----------------------------------------------+------------------------------------------------------+
| .. raw:: html                          | .. raw:: html                                 | .. raw:: html                                        |
|                                        |                                               |                                                      |
|    <div class="center">                |    <div class="center">                       |    <div class="center">                              |
|                                        |                                               |                                                      |
| .. raw:: html                          | .. raw:: html                                 | .. raw:: html                                        |
|                                        |                                               |                                                      |
|    <div                                |    <div                                       |    <div                                              |
|    class="thumb tnone">                |    class="thumb tnone">                       |    class="thumb tnone">                              |
|                                        |                                               |                                                      |
| .. raw:: html                          | .. raw:: html                                 | .. raw:: html                                        |
|                                        |                                               |                                                      |
|    <div                                |    <div                                       |    <div                                              |
|    class="thumbinner"                  |    class="thumbinner"                         |    class="thumbinner"                                |
|    style="width:302px;">               |    style="width:302px;">                      |    style="width:302px;">                             |
|                                        |                                               |                                                      |
| .. Image:: /images/Dcan.png            | .. Image:: /images/Dcan-header.png            | .. Image:: /images/Dcan_header_to_db9.png            |
|                                        |                                               |                                                      |
| .. raw:: html                          | .. raw:: html                                 | .. raw:: html                                        |
|                                        |                                               |                                                      |
|    <div                                |    <div                                       |    <div                                              |
|    class="thumbcaption">               |    class="thumbcaption">                      |    class="thumbcaption">                             |
|                                        |                                               |                                                      |
| .. raw:: html                          | .. raw:: html                                 | .. raw:: html                                        |
|                                        |                                               |                                                      |
|    <div class="magnify">               |    <div class="magnify">                      |    <div class="magnify">                             |
|                                        |                                               |                                                      |
+----------------------------------------+-----------------------------------------------+------------------------------------------------------+
| DB9 to DB9                             | Header to Header                              | Header to DB9                                        |
+----------------------------------------+-----------------------------------------------+------------------------------------------------------+

Table:  Various DCAN EVM Connection Configuration

.. rubric:: **Equipment**
   :name: equipment

.. rubric:: **Female DB9 Cable**
   :name: female-db9-cable

A male DB9 connector is used on select evms. Therefore, a female
DB9/Serial Port/RS 232 cable must be used to connect with the evm.
Wheather the other end of the cable is female or male will depend on if
the other CAN device the user will be connecting to.

.. Image:: /images/DB9_cable.jpg
   :scale: 50%
   :align: center 


.. rubric:: **Jumper Wires**
   :name: jumper-wires

.. Image:: /images/Female_to_female_jumper.png
   :scale: 20%
   :align: center


For evms whose DCAN pins are broken out via a header then a female
jumper wire would be best to use to connect to the various DCAN pins on
the evm. Note some evms have CAN H (typically header pin 1), GND
(typically middle header) and CAN L (typically the third header). Its
important to always connect the CAN's GND pin to what other device your
connecting to. Only exception are the evms that don't include the CAN
GND pin.

+--------------------------------------------------------------------------+
| .. raw:: html                                                            |
|                                                                          |
|    <div class="center">                                                  |
|                                                                          |
| .. raw:: html                                                            |
|                                                                          |
|    <div class="floatnone">                                               |
|                                                                          |
| .. Image:: /images/Dcan_j6eco.png                                        |
|                                                                          |
| .. raw:: html                                                            |
|                                                                          |
|    </div>                                                                |
|                                                                          |
| .. raw:: html                                                            |
|                                                                          |
|    </div>                                                                |
+--------------------------------------------------------------------------+
| Example of DCAN header on DRA72 EVM                                      |
+--------------------------------------------------------------------------+

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
Its important for the user to verify which header pin is associated with
the various CAN signals. Unless there are already silk screens the user
may need to double check the evm's schematic.

.. raw:: html

   </div>

| 

.. rubric:: **Custom DB9 to Header Cable**
   :name: custom-db9-to-header-cable

Typically CAN devices use a DB9 connection therefore for evms whose CAN
pins are broken out via a header it is helpful to create a header to DB9
connector cable. This custom cable is simple to make. Either a male or
female DB9 connector (not cable) must be purchased along with three
female jumper wires.

Snip one end of each of the jumper wires and expose some of the wiring.
Now solder each of the exposed wires to pin 7 (CAN H), pin 2 (CAN L) and
pin 3 (GND). Make sure your soldering on the side of the DB9 that has
the metal lip meant to push some of the exposed wire into and soldering
to the correct pins correctly. Use the below diagram as a reference.

+-------------------------------------------------------------+------------------------------------------------+
| .. raw:: html                                               | .. raw:: html                                  |
|                                                             |                                                |
|    <div class="center">                                     |    <div class="center">                        |
|                                                             |                                                |
| .. raw:: html                                               | .. raw:: html                                  |
|                                                             |                                                |
|    <div class="floatnone">                                  |    <div class="floatnone">                     |
|                                                             |                                                |
| .. Image:: /images/DCAN_custom_cable_diagram.png            | .. Image:: /images/Custom_cable.png            |
|                                                             |                                                |
| .. raw:: html                                               | .. raw:: html                                  |
|                                                             |                                                |
|    </div>                                                   |    </div>                                      |
|                                                             |                                                |
| .. raw:: html                                               | .. raw:: html                                  |
|                                                             |                                                |
|    </div>                                                   |    </div>                                      |
+-------------------------------------------------------------+------------------------------------------------+
| Wiring Diagram                                              | Example of completed cable.                    |
+-------------------------------------------------------------+------------------------------------------------+

| 

.. rubric:: **CAN Utilities**
   :name: can-utilities

There may be other userspace applications that can be used to interact
with the CAN bus but the SDK supports using Canutils which is already
included in the sdk filesystem.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
These instructions are for can0 (first and perhaps only CAN instance
enabled). If the board has multiple CAN instances enabled then they can
be referenced by incrementing the CAN instance number. For example 2 CAN
instances will have can0 and can1.

.. raw:: html

   </div>

.. rubric:: **Quick Steps**
   :name: quick-steps

.. rubric:: **Initialize CAN Bus**
   :name: initialize-can-bus

-  Set bit-timing

Set the bit-rate to 50Kbits/sec using the following command:

::

    $ ip link set can0 type can bitrate 50000

-  Set bit-timing (loopback mode)

Set the bit-rate to 50Kbits/sec in the loopback mode using the following
command

::

    $ ip link set can0 type can bitrate 50000 loopback on

.. rubric:: **Start CAN Bus**
   :name: start-can-bus

-  Device bring up

Bring up the device using the command:

::

    $ ip link set can0 up

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
The default state when starting a previously powered off CAN device is
called "Error-Active". So don't worry when you see this command when you
first start the CAN instance.

.. raw:: html

   </div>

.. rubric:: **Send or Receive Packets**
   :name: send-or-receive-packets

-  Transfer packets

Packet transmission can be achieve by using cansend and cansequence
utilities.

Transmit 4 bytes with standard packet id number as 0x123

::

    $ cansend can0 123#DEADBEEF


Transmit a sequence of can frames with random IDs and random data.

::

    $ cangen can0

-  Receive packets

Packet reception can be achieve by using candump utility

::

    $ candump can0


.. rubric:: **Stop CAN Bus**
   :name: stop-can-bus

::

    $ ip link set can0 down

| 

.. rubric:: **Advanced Usage**
   :name: advanced-usage

The following are some examples exploring the capabilties of can-utils. See can-utils documentation for a comprehensive set of options.

Transmit fixed CAN ID and length with an incrementing data

::

    $ cangen can0 -g 4 -I 42A -L 1 -D i -v -v

Log only error frames but no data frames

::

    $ candump -l any,0~0,#FFFFFFFF

.. rubric:: **Statistics of CAN**
   :name: statistics-of-can

Statistics of CAN device can be seen from these commands

::

    $ ip -d -s link show can0

Below command also used to know the details

::

    $ cat /proc/net/can/stats

.. rubric:: **Error frame details**
   :name: error-frame-details

.. rubric:: *DCAN IP Error details*
   :name: dcan-ip-error-details

If the CAN bus is not properly connected or some hardware issues DCAN
has the intelligence to generate an Error interrupt and corresponding
error details on hardware registers.

In CAN terminology errors are divided into three categories

-  Error warning state, this state is reached if the error count of
   transmit or receive is more than 96.
-  Error passive state, this state is reached if the core still
   detecting more errors and error counter reaches 127 then bus will
   enter into
-  Bus off state, still seeing the problems then it will go to Bus off
   mode.

.. rubric:: *DCAN driver provides*
   :name: dcan-driver-provides

For the above error state, driver will send the error frames to inform
that there is error encountered. Frame details with respect to different
states are listed here:

-  Error warning frame

::

    <0x004> [8] 00 08 00 00 00 00 60 00

ID for error warning is 0x004 [8] represents 8 bytes have received 0x08
at 2nd byte represents type of error warning. 0x08 for transmission
error warning, 0x04 for receive error warning frame 0x60 at 7th byte
represent tx error count.

-  Error passive frame

::

    <0x004> [8] 00 10 00 00 00 00 00 64

ID for error passive frame is 0x004 [8] represents 8 bytes have received
0x10 at 2nd byte represents type of error passive. 0x10 for receive
error passive, 0x20 for transmission error passive 0x64 at 8th byte
represent rx error count.

-  Buss off state

::

    <0x040> [8] 00 00 00 00 00 00 00 00

ID for bus-off state is 0x040

.. rubric:: *Error frames display with candump*
   :name: error-frames-display-with-candump

candump has the capability to display the error frames along with data
frames on the console. Some of the error frames details are mentioned in
the previous section

::

    $ candump can0 -e

| 

.. rubric:: **Linux Driver Configuration**
   :name: linux-driver-configuration

-  DCAN device driver in Linux is provided as a networking driver that
   confirms to the socketCAN interface
-  The driver is currently build-into the kernel with the right
   configuration items enabled (details below)

.. rubric:: Detailed Kernel Configuration
   :name: detailed-kernel-configuration

The SoC specific kernel configuration included in the SDK by default
enables full support for the DCAN driver. Therefore, manually enabling
these options are not required if your using the provided kernel config
(defconfig).

The below CAN specific drivers are the bare minimum needed to enable
DCAN driver:

-  CAN bus subsystem support
-  Bosch C\_CAN/D\_CAN devices
-  CAN\_C\_CAN\_PLATFORM

Four additional drivers are required to utilize all the CAN features:

-  Raw CAN Protocol (raw access with CAN-ID filtering)
-  Broadcast Manager CAN Protocol (with content filtering)
-  CAN Gateway/Router (with netlink configuration)
-  CAN bit-timing calculation

::

    [*] Networking support ->
       <*|M> CAN bus subsystem support ->
          <*|M> Raw CAN Protocol (raw access with CAN-ID filtering)
          <*|M> Broadcast Manager CAN Protocol (with content filtering)
          <*|M> CAN Gateway/Router (with netlink configuration)
             CAN Device Drivers ->
                <*|M>   Platform CAN drivers with Netlink support
                [*]     CAN bit-timing calculation
                <*|M>   Bosch C_CAN/D_CAN devices ->
                   <M> Generic Platform Bus based C_CAN/D_CAN driver

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
\*\|M means can be either be built into the kernel or enabled as a
kernel module.

.. raw:: html

   </div>

| 

.. rubric:: **DCAN driver Architecture**
   :name: dcan-driver-architecture

DCAN driver architecture shown in the figure below, is mainly divided
into three layers Viz user space, kernel space and hardware.

.. raw:: html

   <div class="center">

.. raw:: html

   <div class="thumb tnone">

.. raw:: html

   <div class="thumbinner" style="width:592px;">

.. Image:: /images/Dcan_driver_architecture.png

.. raw:: html

   <div class="thumbcaption">

.. raw:: html

   <div class="magnify">



.. rubric:: **User Space**

CAN utils are used as the application binaries for transfer/receive
frames. These utils are very useful for debugging the driver.

.. rubric:: **Kernel Space**
   :name: kernel-space

This layer mainly consists of the socketcan interface, network layer and
DCAN driver.

Socketcan interface provides a socket interface to user space
applications and which builds upon the Linux network layer. DCAN device
driver for CAN controller hardware registers itself with the Linux
network layer as a network device. So that CAN frames from the
controller can be passed up to the network layer and on to the CAN
protocol family module and vice-versa.

The protocol family module provides an API for transport protocol
modules to register, so that any number of transport protocols can be
loaded or unloaded dynamically.

In fact, the can core module alone does not provide any protocol and
cannot be used without loading at least one additional protocol module.
Multiple sockets can be opened at the same time, on different or the
same protocol module and they can listen/send frames on different or the
same CAN IDs.

Several sockets listening on the same interface for frames with the same
CAN ID are all passed the same received matching CAN frames. An
application wishing to communicate using a specific transport protocol,
e.g. ISO-TP, just selects that protocol when opening the socket. Then
can read and write application data byte streams, without having to deal
with CAN-IDs, frames, etc.

.. rubric:: **Hardware**

This layer mainly consisting of DCAN core and DCAN IO pins for packet
Transmission or reception.

.. rubric:: **Driver Location**
   :name: driver-location

+--------+---------------------------------------------+--------------------------------+
| S.No   | Location                                    | Description                    |
+========+=============================================+================================+
| 1      | drivers/net/can/c\_can/c\_can.c             | DCAN driver core file          |
+--------+---------------------------------------------+--------------------------------+
| 2      | drivers/net/can/c\_can/c\_can\_platform.c   | Platform/SoC DCAN bus driver   |
+--------+---------------------------------------------+--------------------------------+

