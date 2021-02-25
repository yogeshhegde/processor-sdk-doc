.. include:: /replacevars.rst.inc

CPSW2g Ethernet
---------------------------------------

Introduction
"""""""""""""

The TI |__PART_FAMILY_DEVICE_NAMES__| SoC Gigabit Ethernet Switch subsystem (CPSW NUSS) has two ports and
provides Ethernet packet communication for the device. It supports MII interfaces
the Reduced Gigabit Media Independent Interface (RGMII), Reduced Media Independent
Interface (RMII), and the Management Data Input/Output (MDIO) interface for
physical layer device (PHY) management.

The TI |__PART_FAMILY_DEVICE_NAMES__| SoC has integrated two-port Gigabit Ethernet Switch subsystem
into device MCU domain named MCU_CPSW0 and has only one external Ethernet port (port 1)
with selectable RGMII and RMII interfaces and an internal Communications
Port Programming Interface (CPPI) port (Host port 0). Host Port 0 CPPI Packet
Streaming Interface interface supports 8 TX channels and one RX channel
operating by TI |__PART_FAMILY_DEVICE_NAMES__| NAVSS Unified DMA Peripheral Root Complex (UDMA-P) controller.

The driver follows the standard Linux network interface architecture and
supports the following features:

#. 100/1000 Mbps mode of operation.
#. Auto negotiation.
#. Linux NAPI support
#. VLAN filtering
#. Ethertool
#. CPTS
#. EST/TAS offload as per 802.1Q-2018

*Not supported*:

- Interrupt Pacing is not supported by HW. NAPI is used by driver.

.. rubric:: **Driver Configuration**
   :name: k3-driver-configuration-cpsw

The TI Processor SDK has |__PART_FAMILY_NAME__|  MCU CPSW2g driver enabled by default.

To enable/disable Networking support manually, start the *Linux Kernel Configuration*
tool:

::

    $ make ARCH=arm64 menuconfig

| Select *Device Drivers* from the main menu ->
| Select *Network device support* ->
| Select *Ethernet driver support* ->
| Select ** as shown here:

::

       ...
       [*]   Texas Instruments (TI) devices
       -*-     TI DaVinci MDIO Support
       -*-     TI CPSW ALE Support
       <*>     TI K3 CPSW Ethernet driver
       [*]       Enable TAS offload in AM65 CPSW
       <*>     TI K3 AM65x CPTS
       ...

Kernel Kconfig options:

::

    CONFIG_TI_DAVINCI_MDIO
    CONFIG_TI_CPSW_ALE
    CONFIG_TI_AM65_CPSW_NUSS
    CONFIG_TI_AM65_CPTS
    CONFIG_TI_AM65_CPSW_TAS

.. rubric:: **Module Build**
   :name: k3-module-build

Module build for the cpsw driver is supported. To do this, at all the
places mentioned in the section above select module build (short-cut key
**M**).

.. rubric:: **Device tree bindings**
   :name: k3-dt-binding

The DT bindings description can be found at:

|   `Documentation/devicetree/bindings/net/ti,am654-cpsw-nuss.txt <https://git.ti.com/ti-linux-kernel/ti-linux-kernel/blobs/ti-linux-5.4.y/Documentation/devicetree/bindings/net/ti,am654-cpsw-nuss.txt>`__

|   `Documentation/devicetree/bindings/net/ti,am654-cpts.txt <https://git.ti.com/ti-linux-kernel/ti-linux-kernel/blobs/ti-linux-5.4.y/Documentation/devicetree/bindings/net/ti,am654-cpts.txt>`__
|

.. include:: K3-CPSW-common.rst.inc
