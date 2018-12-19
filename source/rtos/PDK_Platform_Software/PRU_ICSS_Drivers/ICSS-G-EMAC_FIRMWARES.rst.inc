.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_ICSS-G-EMAC_FIRMWARES 

Introduction
=============
| The ICSS-G FIRMWARE serves as example to implement various network
  functionalities. Package includes source release for DUAL EMAC

|

DUAL_EMAC
=========

ICSS DUAL EMAC FIRMWARE is a single port Ethernet MAC (Media Access
Control) i.e. Layer 2 of OSI Model. It implements a 2 port Ethernet
mac supporting 100Mbps and 1Gbps. DUAL MAC FIRMWARE is standardized
to IEEE 802.1 Ethernet Standards. Primary use case of the protocol
is to demonstrate basic Ethernet functionality via both PRU/RTU cores.
ICSS-G DUAL EMAC FIRMWARE can be used independently on two PRUs to
implement two independent MACs with two different MAC addresses
and two different IP addresses.

Following are high level features:

+-----------------------------------+-----------------------------------+
| **Requirements**                  | **Remarks**                       |
+-----------------------------------+-----------------------------------+
| 4 egress DMA threads per port     | Supported                         |
+-----------------------------------+-----------------------------------+
| 4 ingress “buckets” per port      | Supported                         |
+-----------------------------------+-----------------------------------+
| Statistics                        | Supported                         |
+-----------------------------------+-----------------------------------+
| Storm Prevention                  | Future                            |
+-----------------------------------+-----------------------------------+
| Promiscuous Mode                  | Supported                         |
+-----------------------------------+-----------------------------------+
| TTS (Time Triggered Send)         | Future                            |
+-----------------------------------+-----------------------------------+
| Error Handling                    | Supported                         |
+-----------------------------------+-----------------------------------+
| Multicast filtering               | Supported                         |
+-----------------------------------+-----------------------------------+
| VLAN filtering                    | Future                            |
+-----------------------------------+-----------------------------------+
| PTP Handling                      | Supported                         |
+-----------------------------------+-----------------------------------+

|


Firmware Code Location and Build Instruction
============================================

Firmware is located at <PDK>packages/ti/drv/emac/firmware/icss_eth/src directory.

The CLPRU toolchain has to be used to build the firmware. The toolchain can be
downloaded from <http://software-dl.ti.com/codegen/esd/cgt_public_sw/PRU/2.2.1/ti_cgt_pru_2.2.1_linux_installer_x86.bin>

To build the firmware:

- cd to <PDK>packages/ti/drv/emac/firmware/icss_eth/src directory

- make CLPRU_INSTALL_PATH=<dir_where_the_toolchain_installed>.

The firmware will be located in the <PDK>packages/ti/drv/emac/firmware/icss_eth/src/dm directory. 

| 

.. raw:: html

