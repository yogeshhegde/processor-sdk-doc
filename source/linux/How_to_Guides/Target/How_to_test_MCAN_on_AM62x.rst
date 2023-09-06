
.. _mcan-on-am62x:

3x MCAN on AM62x and AM62ax devices
======================================

The following guide applies to AM62x and AM62ax devices. However, to test 3x MCAN on AM62ax, please first enable MCU MCAN nodes as per instructions here:
:ref:`Enable MCU MCANs on AM62ax`. Then proceed with the rest of the guide.

*Processor SDK supporting 3x MCAN*

The Processor SDK 9.0 release fully supports 3x MCAN on AM62 devices. For AM62ax, some changes have to be made as mentioned here
:ref:`Enable MCU MCANs on AM62ax`.

*Linux Kernel version supporting 3x MCAN*

On AM62 SoCs, MCANs in MCU domain do not have hardware interrupt routed to A53 Linux. Instead timer polling functionality
has been added to the MCAN driver in Linux Kernel to enable 3x MCAN. The driver changes have been merged to TI Linux Kernel on
ti-linux-6.1.y branch.

*Latency and CPU load benchmarks Results*

1 MBPS timer polling interval was determined to be the better timer polling interval since it has comparable latency to hardware interrupt
with the worse case being 1ms + CAN frame propagation time and CPU load is not substantial. Latency can be improved further with less than
1 ms  polling intervals, howerver it is at the cost of CPU usage since CPU load increases at 0.5 ms.

*Power implications*

Enabling MCU MCANs with timer-polling might have a negative impact since the CPU has to wake up every 1 ms whether there are CAN packets
pending in the RX FIFO or not. This might prevent the CPU from entering into deeper idle states for extended periods of time.

|


MCAN Overview
--------------

The CAN-FD transceiver and CAN-FD controller make up a CAN node. A CAN-FD transceiver is the interface between the CAN-FD controller and
the CAN bus. It translates the logic level messages from the CAN-FD controller into the CAN differential scheme on the CANH and
CANL pins of the CAN-FD transceiver. The CAN-FD controller can be thought of as an MCU, the part of the CAN node that processes all the
information to and from the CAN bus.

.. Image:: /images/mcan-environment.JPG
        :scale: 40%

For more information on MCAN, refer to TRM Peripherals -> Industrial and Control Interfaces -> Modular Controller Area Network (MCAN)

The Linux Kernel driver for MCAN can be found in <path-to-linux>/drivers/net/can/m_can.

|


CAN Transceiver
----------------
The AM62 SKs do not carry a CAN-FD transciever to experiment with. The SoC does support CAN-FD, but it is required to connect an
external CAN-FD transceiver to the AM62x SK to test the full functionality of CAN. In this guide, we will connnect an external CAN transceiver
(not CAN-FD capable) as shown in the figure below to test CAN functionality on AM62x SK.

The CAN transceiver tested is included in `SN65HVD230 CAN Board Kit`, which is the transceiver soldered into a breakout board which can be purchased
`here <https://a.co/d/aNM1gl2>`__. If only the transceiver needs to be purchased, it can be purchased in
`Digi-key <https://www.digikey.com/en/product-highlight/t/texas-instruments/sn65hvd23x-3-3-v-can-bus-transceivers?utm_adgroup=Texas%20Instruments&utm_source=google&utm_medium=cpc&utm_campaign=Dynamic%20Search_EN_Focus%20Suppliers&utm_term=&utm_content=Texas%20Instruments&gclid=Cj0KCQiAn4SeBhCwARIsANeF9DIfq0FYRUK0h1HCFLLR5baWVfSHr1EPhbWKQyS_PgpNWTNdgrmbcZ8aAgJZEALw_wcB>`__,
or `Mouser Electronics <https://www.mouser.com/c/semiconductors/interface-ics/can-interface-ic/?m=Texas%20Instruments&series=SN65HVD230>`__.

.. Image:: /images/mcan-external-transceiver.jpg
        :scale: 30%

|

Connections
------------

AM62x:
_______

There is 1x MCAN in the MAIN domain and 2x MCAN in MCU domain. According to the AM62x datasheet on `Table 6-1. Pin Attributes` we can see
the following:

#. MCAN0_RX is pinmuxed with UART5_TXD
#. MCAN0_TX is pinmuxed with UART5_RXD
#. MCU_MCAN1_RX is pinmuxed with MCU_GPIO0_16
#. MCU_MCAN1_TX is pinmuxed with MCU_GPIO0_15

+-------------------------------------------------+
| .. Image:: /images/mcan-pin-attributes.JPG      |
|                 :width: 380px                   |
|                 :align: center                  |
+-------------------------------------------------+
| Ex: Pin attributes for MCAN0 (MAIN domain MCAN) |
+-------------------------------------------------+

On the AM62x schematics, `SOC - General`, `User Expansion Connector`, and `MCU Header` we can see the following:

#. MCAN0_RX becomes signal name EXP_UART5_TXD
#. MCAN0_TX becomes signal name EXP_UART5_RXD
#. EXP_UART5_TXD is pin 8 on User Expansion
#. EXP_UART5_RXD is pin 10 on User Expansion
#. MCU_MCAN0_RX is brought out by pin 22 on MCU Header
#. MCU_MCAN0_TX is brought out by pin 16 on MCU Header
#. MCU_GPIO0_16 is brought out by pin 11 on MCU Header
#. MCU_GPIO0_15 is brought out by pin 10 on MCU Header

+---------------------------------------------------+-------------------------------------------------------+-----------------------------------------+
| .. Image:: /images/mcan-schematic-soc-general.JPG | .. Image:: /images/mcan-schematic-user-expansion.JPG  | .. Image:: /images/mcan-mcu-header.JPG  |
|                  :width: 380px                    |                     :width: 380px                     |              :width: 380px              |
|                  :align: center                   |                     :align: center                    |              :align: center             |
+---------------------------------------------------+-------------------------------------------------------+-----------------------------------------+
| Schematic: SOC - General                          | Schematic: User Expansion Connector                   | Schematic: MCU Header                   |
+---------------------------------------------------+-------------------------------------------------------+-----------------------------------------+

In summary:

#. MCAN0_RX is brought out by pin 8 on User Expansion
#. MCAN0_TX is brought out by pin 10 on User Expansion
#. MCU_MCAN0_RX is brought out by pin 22 on MCU Header
#. MCU_MCAN0_TX is brought out by pin 16 on MCU Header
#. MCU_MCAN1_RX is brought out by pin 11 on MCU Header
#. MCU_MCAN1_TX is brought out by pin 10 on MCU Header

External CAN Transceiver:
_________________________

The CAN external transceiver used in this project is SN65HVD230 CAN Board. The schematic for this CAN board is the following:

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

With all boards powered on and booted to Linux kernel, the following commands could be executed to test CAN functionality.

.. code-block:: console
        :caption: MCAN0 on AM64x to display received CAN packet

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

.. code-block:: console
        :caption: MCAN0 on AM62x to send CAN packet

        root@am62xx-evm:~# ip link set can0 down
        root@am62xx-evm:~# ip link set can0 type can bitrate 125000
        root@am62xx-evm:~# ip link set can0 up
        root@am62xx-evm:~# cansend can0 123#DEADBEEF
        [ 1392.577915] can: controller area network core
        [ 1392.582388] NET: Registered protocol family 29
        [ 1392.594650] can: raw protocol
        root@am62xx-evm:~#

For more documentation on using the CAN utilities software, go to :ref:`mcan`.

Testing 3x MCAN on AM62x
-------------------------

To test the 3x MCANs, connect 3x external CAN transceivers to each MCAN on AM62x:

#. AM62x pin 8 (MCAN0_RX) on User Expansion to pin 2 (CAN_RX) on the CAN transceiver Header 1
#. AM62x pin 10 (MCAN0_TX) on User Expansion to pin 1 (CAN_TX) on the CAN transceiver Header 1
#. AM62x pin 22 (MCU_MCAN0_RX) on MCU Header to pin 2 (CAN_RX) on the CAN transceiver Header 1
#. AM62x pin 16 (MCU_MCAN0_TX) on MCU Header to pin 1 (CAN_TX) on the CAN transceiver Header 1
#. AM62x pin 11 (MCU_MCAN1_RX) on MCU Header to pin 2 (CAN_RX) on the CAN transceiver Header 1
#. AM62x pin 10 (MCU_MCAN1_TX) on MCU Header to pin 1 (CAN_TX) on the CAN transceiver Header 1

The new CAN nodes can then be inserted to a working CAN setup or to test only on AM62x, the following can be done:

#. 3x CAN transceiver pin 1 (CANL) on Header 2 together
#. 3x CAN transceiver pin 2 (CANH) on Header 2 together

Below is an image of 3x MCAN on AM62x as described by the setup above:

+-----------------------------------+
| .. Image:: /images/mcan-test2.JPG |
|          :width: 380px            |
|          :align: center           |
+-----------------------------------+
| Test 3x MCAN on AM62x             |
+-----------------------------------+

Now CAN utilities software can be used to test, use CANDUMP command for one or two MCANs to display the received packets,
and use the last MCAN to send CAN packets using the CANSEND or CANGEN commands. For more information on using CANUTILS
go here: :ref:`mcan`.

|

Enable Device Tree Overlay
---------------------------

Since AM62 SKs do not have on-board CAN transceivers, there are no transceiver nodes in their respective DTB source files.

A device tree overlay named `k3-am625-sk-mcan.dtbo` is supported in the Processor SDK 9.0 for AM62 devices that can be used to dynamically
overlay each DTB. If an AM62 .wic image was flashed to an SD card, the overlay should be found in the root/boot/dtb/ti partition of the
SD card. This overlay can be loaded by stopping bootup at U-boot prompt and executing the following commands:

.. warning::

        For AM62a, you will first need to add the MCU-MCAN nodes before applying this overlay to enable 3x MCAN on AM62ax. Go here
        :ref:`Enable MCU MCANs on AM62ax`.

.. code-block:: console
        :emphasize-lines: 3

        Hit any key to stop autoboot:  0
                =>
                => setenv name_overlays k3-am625-sk-mcan.dtbo
                => boot

|

.. _Enable MCU MCANs on AM62ax:

Enable MCU MCANs on AM62ax
---------------------------

AM62ax 3x MCAN was not enabled for TI PSDK 9.0 release. Before following the guide above please follow the following steps to enable 3x MCAN on AM62ax.

1. Add MCU_MCAN nodes to AM62ax DTS:

Apply the following change to <path-to-ti-linux>/arch/arm64/boot/dts/ti/k3-am62a-mcu.dtsi

.. code-block:: diff

        diff --git a/arch/arm64/boot/dts/ti/k3-am62a-mcu.dtsi b/arch/arm64/boot/dts/ti/k3-am62a-mcu.dtsi
        index 4d0a291bceea..c7e768b7ac9b 100644
        --- a/arch/arm64/boot/dts/ti/k3-am62a-mcu.dtsi
        +++ b/arch/arm64/boot/dts/ti/k3-am62a-mcu.dtsi
        @@ -145,6 +145,30 @@ mcu_gpio0: gpio@4201000 {
                        status = "disabled";
                };

        +       mcu_mcan1: can@4e00000 {
        +               compatible = "bosch,m_can";
        +               reg = <0x00 0x4e00000 0x00 0x8000>,
        +                     <0x00 0x4e08000 0x00 0x200>;
        +               reg-names = "message_ram", "m_can";
        +               power-domains = <&k3_pds 188 TI_SCI_PD_EXCLUSIVE>;
        +               clocks = <&k3_clks 188 6>, <&k3_clks 188 1>;
        +               clock-names = "hclk", "cclk";
        +               bosch,mram-cfg = <0x0 128 64 64 64 64 32 32>;
        +               status = "disabled";
        +       };
        +
        +       mcu_mcan2: can@4e10000 {
        +               compatible = "bosch,m_can";
        +               reg = <0x00 0x4e10000 0x00 0x8000>,
        +                     <0x00 0x4e18000 0x00 0x200>;
        +               reg-names = "message_ram", "m_can";
        +               power-domains = <&k3_pds 189 TI_SCI_PD_EXCLUSIVE>;
        +               clocks = <&k3_clks 189 6>, <&k3_clks 189 1>;
        +               clock-names = "hclk", "cclk";
        +               bosch,mram-cfg = <0x0 128 64 64 64 64 32 32>;
        +               status = "disabled";
        +       };
        +
                mcu_r5fss0: r5fss@79000000 {
                        compatible = "ti,am62-r5fss";
                        #address-cells = <1>;

2. Build the DTB for AM62ax:

.. code-block:: console

        $ make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu-  defconfig ti_arm64_prune.config
        $ make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu-  dtbs

3. Copy `k3-am62a7-sk.dtb` and `k3-am625-sk-mcan.dtbo` to SD card root/boot/dtb/ti partition
