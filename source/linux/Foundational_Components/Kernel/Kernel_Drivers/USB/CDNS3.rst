###
USB
###

Introduction
************

The USB subsystem has a SuperSpeed (SS) USB3.1 Gen1 Dual-Role-Device (DRD)
controller with on-chip SS (USB3.1 Gen1) PHY and HS/FS/LS (USB2.0) PHY.

.. note::
    LowSpeed (LS) is only supported in host mode.

TI SoC Integration
******************

The USB subsystem is integrated in J721E SoC from TI.

J721E EVM
*********

The following diagram depicts USB integration in J721E EVM.

.. image:: /images/usb_j721e_evm.png

USB0 controller operates in super-speed dual role mode and is available on
a Type-C connector.

.. note::
   The Type-C config DIP switch (SW3) must be set for DRP (Dual-role-Port)
   operation. SW3.3 = OFF, SW3.4 = ON.

USB1 operates in high-speed host mode and is connected to an onboard 4-port
HUB.  Of the 4 hub ports, 2 ports are available on stacked Type-A connectors,
1 is available on J2 header for USB-WiFi/Bluetooth adapter and 1 is available
on the **EVM EXPANSION** connector J51.

USB2 controller is not present on J721E SoC so micro-AB 3.0 connector is not
usable.

