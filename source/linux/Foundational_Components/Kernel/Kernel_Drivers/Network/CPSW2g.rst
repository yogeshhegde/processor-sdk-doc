.. include:: /replacevars.rst.inc

.. _cpsw2g:

CPSW2g Ethernet
---------------

.. contents:: :local:
    :depth: 3

Introduction
============

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

#. 10/100/1000 Mbps mode of operation.
#. Auto negotiation.
#. Linux NAPI support
#. VLAN filtering
#. Ethertool
#. CPTS/PTP as per 802.1AS-2011 (TSN)
#. EST/TAS offload as per 802.1Q-2018 (TSN)
#. IET/preemption offload as per 802.1Q-2018 (TSN)
#. Forwarding and Queuing Enhancements for Time-Sensitive Streams (FQTSS) as per 802.1Q-2018 previously referred to as CBS or 802.1Qav


*Not supported*:

- Interrupt Pacing is not supported by HW. NAPI is used by driver.

Driver Configuration
====================

The TI Processor SDK has |__PART_FAMILY_DEVICE_NAMES__| MCU CPSW2g driver enabled by default.
In case of custom builds, please ensure following configs are enabled.

::

    CONFIG_TI_DAVINCI_MDIO
    CONFIG_TI_CPSW_ALE
    CONFIG_TI_AM65_CPSW_NUSS
    CONFIG_TI_AM65_CPTS
    CONFIG_TI_AM65_CPSW_TAS
    CONFIG_PHY_TI_GMII_SEL

.. rubric:: **Module Build**
   :name: k3-module-build

Module build for the cpsw driver is supported. To do this, use option 'm' for above configs, where applicable.

Device tree bindings
====================

The DT bindings description can be found at:

|   `Documentation/devicetree/bindings/net/ti,k3-am654-cpsw-nuss.yaml <https://git.ti.com/ti-linux-kernel/ti-linux-kernel/blobs/ti-linux-5.10.y/Documentation/devicetree/bindings/net/ti,k3-am654-cpsw-nuss.yaml>`__

|   `Documentation/devicetree/bindings/net/ti,k3-am654-cpts.yaml <https://git.ti.com/ti-linux-kernel/ti-linux-kernel/blobs/ti-linux-5.10.y/Documentation/devicetree/bindings/net/ti,k3-am654-cpts.yaml>`__
|

MAC mode
========

.. include:: K3-CPSW-common.inc.rst
