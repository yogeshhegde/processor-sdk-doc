
.. _mcan-on-am62x:

MCAN on AM62x
==========================

The CAN-FD transceiver and CAN-FD controller make up a CAN node. A CAN-FD transceiver is the interface between the CAN-FD controller and
the CAN bus. It translates the logic level messages from the CAN-FD controller into the CAN differential scheme on the CANH and
CANL pins of the CAN-FD transceiver. The CAN-FD controller can be thought of as an MCU, the part of the CAN node that processes all the
information to and from the CAN bus.

.. Image:: /images/mcan-environment.JPG
        :scale: 40%

For more information on MCAN, refer to TRM Peripherals -> Industrial and Control Interfaces -> Modular Controller Area Network (MCAN)

The Linux Kernel driver for MCAN can be found in <path-to-linux>/drivers/net/can/m_can.

        Important! MCU MCANs are unsupported from Linux as their IRQs are not routed to the A53 GIC, as can be seen on the AM62x TRM
        Table 10-18 `Interrupt Connections Summary`.

Transceiver on AM62x
-------------------------
The AM62x SK does not carry a CAN-FD transciever to experiment with. The SoC does support CAN-FD, but it is required to connect an external
CAN transceiver to the AM62x SK to test the full functionality of CAN. In this guide, we will connnect an external CAN transceiver as shown
in the figure below to test CAN functionality on AM62x SK.

The CAN transceiver tested is included in `SN65HVD230 CAN Board Kit`, which is the transceiver soldered into a breakout board which can be purchased
`here <https://a.co/d/aNM1gl2>`__. If only the transceiver needs to be purchased, it can be purchased in
`Digi-key <https://www.digikey.com/en/product-highlight/t/texas-instruments/sn65hvd23x-3-3-v-can-bus-transceivers?utm_adgroup=Texas%20Instruments&utm_source=google&utm_medium=cpc&utm_campaign=Dynamic%20Search_EN_Focus%20Suppliers&utm_term=&utm_content=Texas%20Instruments&gclid=Cj0KCQiAn4SeBhCwARIsANeF9DIfq0FYRUK0h1HCFLLR5baWVfSHr1EPhbWKQyS_PgpNWTNdgrmbcZ8aAgJZEALw_wcB>`__,
or `Mouser Electronics <https://www.mouser.com/c/semiconductors/interface-ics/can-interface-ic/?m=Texas%20Instruments&series=SN65HVD230>`__.

.. Image:: /images/mcan-external-transceiver.jpg
        :scale: 30%

|

Connections
---------------
AM62x:
______

On AM62x SK we will need to use MCAN0 RX and MCAN0 TX pins.

According to the AM62x SK device tree `k3-am625-sk.dtb`, there is an MCAN0 instance in the MAIN domain. According to the AM62x SK EVM User's
Guide at `Table 2-25. 40 Pin User Expansion Connector` and the AM62x datasheet on `Table 6-32. MCAN0 Signal Descriptions`, we can see the
following:

- MCAN0_RX is associated with the ALW ball # E15
- MCAN0_RX is pinmuxed with UART5_TXD
- MCAN0_TX is associated with the ALW ball # C15
- MCAN0_TX is pinmuxed with UART5_RXD

.. Image:: /images/mcan-signal-descriptions.JPG
        :scale: 70%
.. Image:: /images/mcan-pin-attributes.JPG
        :scale: 60%

On the diagram below from AM62x schematics, section `SOC - General`, we can see MCAN0_RX and MCAN0_TX become signal names EXP_UART_TXD and
EXP_UART5_RXD.

.. Image:: /images/mcan-schematic-soc-general.JPG
        :scale: 60%


On the AM62x schematics, EXP_UART_TXD and EXP_UART5_RXD signals can be traced to the User Expansion Connector, pins 8 and 10. Therefore, pin
8 brings out MCAN0 RX and pin 10 brings out MCAN0 TX on the User Expansion Connector.

.. Image:: /images/mcan-schematic-user-expansion.JPG
        :scale: 50%

External Transceiver:
________________________

The CAN external transceiver used in this project is SN65HVD230 CAN Board. The scematic for this CAN board is the following:

.. Image:: /images/mcan-schematic-external-transceiver.PNG
        :scale: 50%

#. Pin 1 on Header 4 is CAN_TX
#. Pin 2 on Header 4 is CAN_RX
#. Pin 3 on Header 4 is DGND
#. Pin 4 on Header 4 is 3.3V
#. Pin 1 on Header 2 is CANL
#. Pin 2 on Header 2 is CANH

AM64x EVM:
__________

There are 2x MCANs MAIN domain, MCAN0 and MCAN1. On the AM64x GP EVM User's Guide section 3.4.14: `CAN Interface` and `CAN INTERFACE`
section on the AM64x schematics, we can see the following:

#. MCAN0_H is brought out by pin 1 on J31 connector
#. MCAN0_L is brought out by pin 3 on J31 connector

+------------------------------------------------------+
| .. Image:: /images/mcan-schematic-can-interface.JPG  |
|                 :width: 380px                        |
|                 :align: center                       |
+------------------------------------------------------+
| Schematic for AM64x GP EVM - CAN Interface for MCAN0 |
+------------------------------------------------------+

|

Testing 1x MCAN on AM62x and 1x MCAN on AM64x
--------------------------------------------------------

*AM62x Hardware Setup*

To test the MCAN0 on AM62x SK, we are using the CAN-FD controller on the AM62x and 1x external CAN transceiver, which completes one node on the CAN bus.
Connect the CAN transceiver to AM62x as shown in the following diagram:

.. Image:: /images/mcan-diagram-am62x-transceiver-am64x.png

#. AM62x pin 8 (MCAN0_RX) on User Expansion to pin 2 (CAN_RX) on the CAN transceiver Header 1
#. AM62x pin 10 (MCAN0_TX) on User Expansion to pin 1 (CAN_TX) on the CAN transceiver Header 1

The CAN external transceiver will then need to be powered, connect 3.3V and GND pins to a reliable power supply.

*AM64x hardware Setup*

Now connect AM64x EVM to receive CAN packages from AM62x according to the following diagram:

.. Image:: /images/mcan-diagram-evm-to-evm.png
|

#. CAN transceiver pin 1 (CANL) on Header 2 to pin 3 (MCAN0_L) on AM64x J31 connector
#. CAN transceiver pin 2 (CANH) on Header 2 to pin 1 (MCAN0_H) on AM64x J31 connector

*Final Setup*

The following images shows the final setup for testing 1x MCAN on AM62x and 1x MCAN on AM64x:

+-----------------------------------+---------------------------------------+
| .. Image:: /images/mcan-test0.JPG | .. Image:: /images/mcan-test1.JPG     |
|       :width: 380px               |       :width: 380px                   |
|       :align: center              |       :align: center                  |
+-----------------------------------+---------------------------------------+
| AM62x and external transceiver    | AM64x receving CAN packets from AM62x |
+-----------------------------------+---------------------------------------+

|

Enable Device Tree Overaly on AM62x
---------------------------------------------

Since the AM62x does not have an on-board CAN-FD transceiver there is no transceiver node on the AM62x Device Tree Source file; `k3-am625-evm.dts`.
However a device tree overlay named `k3-am625-sk-mcan.dtbo` supported in the TI SDK which can be used to dynamically overlay the AM62x Device Tree.
If an AM62x .wic image was flashed to an SD card, the `k3-am625-sk-mcan.dtbo` should be found in the root partition. This overlay can be loaded by
stopping AM62x bootup during U-boot and executing the following commands:

    ::

        Hit any key to stop autoboot:  0
        =>
        => setenv name_overlays k3-am625-sk-mcan.dtbo
        => boot

|

Testing MCAN on AM62x
-------------------------

*MCAN0 on AM64x to display received CAN packet*

    ::

        root@am64xx-evm:~# ip link set can0 down
        root@am64xx-evm:~# ip link set can0 type can bitrate 125000
        root@am64xx-evm:~# ip link set can0 up
        [   40.940389] IPv6: ADDRCONF(NETDEV_CHANGE): can0: link becomes ready
        root@am64xx-evm:~# candump can0
        [   47.533511] can: controller area network core
        [   47.538112] NET: Registered protocol family 29
        [   47.555073] can: raw protocol
        can0  123   [4]  DE AD BE EF
        [  138.824591] Initializing XFRM netlink socket
        [  140.303978] bridge: filtering via arp/ip/ip6tables is no longer available by default. Update your scripts to load br_netfilter if you need this.
        [  140.321844] Bridge firewalling registered
        [  141.457406] process 'docker/tmp/qemu-check709863015/check' started with executable stack

Note: Use Ctrl-C to terminate candump

*MCAN0 on AM62x to send CAN packet:*

    ::

        # To send:
        root@am62xx-evm:~# ip link set can0 down
        root@am62xx-evm:~# ip link set can0 type can bitrate 125000
        root@am62xx-evm:~# ip link set can0 up
        root@am62xx-evm:~# cansend can0 123#DEADBEEF
        [ 1392.577915] can: controller area network core
        [ 1392.582388] NET: Registered protocol family 29
        [ 1392.594650] can: raw protocol
        root@am62xx-evm:~#

For more MCAN driver instructions, go to :ref:`mcan`.