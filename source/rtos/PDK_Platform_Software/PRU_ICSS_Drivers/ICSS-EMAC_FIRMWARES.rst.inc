.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_ICSS-EMAC_FIRMWARES 

Introduction
=============

| The ICSS FIRMWARES serves as example to implement various network
  functionalities. Package includes source release for Dual_emac and
  basic switch firmwares.

| 

DUAL_EMAC
=========

ICSS DUAL EMAC FIRMWARE is a single port Ethernet MAC (Media Access
Control) i.e. Layer 2 of OSI Model. It implements a 2 port ethernet mac
supporting 10/100 Mbps. DUAL EMAC FIRMWARE is standardized to IEEE 802.1
Ethernet Standards. Primary use case of the protocol is to demonstrate
basic ethernet functionality via both PRU cores on 10/100 Mbit Ethernet
cable. ICSS DUAL EMAC FIRMWARE can be used independently on two PRU's to
implement two independent MAC's with two different MAC addresses and two
different IP addresses. To provide an analogy, this is somewhat similar
to a two port Ethernet PCIe NIC card on a PC.Ethernet interface in this
case is available along with Host processor on a single SoC. Following
are high level features:

+-----------------------------------+-----------------------------------+
| **Requirements**                  | **Remarks**                       |
+-----------------------------------+-----------------------------------+
| 1 ms buffering per port           | Supported                         |
+-----------------------------------+-----------------------------------+
| Host IRQ                          | Supported                         |
+-----------------------------------+-----------------------------------+
| Ethernet QoS                      | With 2 queues instead of 8. So,   |
|                                   | it is not a standard Ethernet QoS |
|                                   | implementation.                   |
+-----------------------------------+-----------------------------------+
| Statistics                        | Supported                         |
+-----------------------------------+-----------------------------------+
| Storm Prevention                  | Supported                         |
+-----------------------------------+-----------------------------------+
| Promiscuous Mode                  | Supported                         |
+-----------------------------------+-----------------------------------+
| TTS (Time Triggered Send)         | Supported                         |
+-----------------------------------+-----------------------------------+
| Error Handling                    | Supported                         |
+-----------------------------------+-----------------------------------+
| Multicast filtering               | Supported                         |
+-----------------------------------+-----------------------------------+
| VLAN filtering                    | Supported                         |
+-----------------------------------+-----------------------------------+
| PTP Handling                      | Supported                         |
+-----------------------------------+-----------------------------------+

| 

SWITCH
======

ICSS SWITCH FIRMWARE is a three port learning Ethernet switch i.e. Layer
2 of OSI Model. It implements a 2 port cut through ethernet switch
supporting at 100 Mbps. SWITCH FIRMWARE is standardized to IEEE 802.1
Ethernet Standards. The primary use case of the protocol is to use
Ethernet to automate applications which require short cut-through
latency and low hardware costs. ICSS SWITCH FIRMWARE uses two PRU to
implement three port Ethernet switch with one single MAC and IP address.
To provide an analogy, this is somewhat standard network switch only
here the network functionality is available to the host core within the
single SOC. The following are the high level features it supports.

+-----------------------------------+-----------------------------------+
| **Requirements**                  | **Remarks**                       |
+-----------------------------------+-----------------------------------+
| Cut-Through                       | Supported                         |
+-----------------------------------+-----------------------------------+
| Store and Forward                 | Supported                         |
+-----------------------------------+-----------------------------------+
| 1 ms buffering per port           | Supported                         |
+-----------------------------------+-----------------------------------+
| Host IRQ                          | Supported                         |
+-----------------------------------+-----------------------------------+
| Ethernet QoS                      | With 4 queues instead of 8. So,   |
|                                   | it is not a standard Ethernet QoS |
|                                   | implementation.                   |
+-----------------------------------+-----------------------------------+
| 802.1 learning switch             | Supported                         |
+-----------------------------------+-----------------------------------+
| Statistics                        | Supported                         |
+-----------------------------------+-----------------------------------+
| Queue-Contention Handling on each | Supported                         |
| port                              |                                   |
+-----------------------------------+-----------------------------------+
| Three-Port Switch                 | Supported                         |
+-----------------------------------+-----------------------------------+
| Storm Prevention                  | Supported                         |
+-----------------------------------+-----------------------------------+
| Error Handling                    | Supported                         |
+-----------------------------------+-----------------------------------+

| 

Code Organization
=================

+-----------------------+-----------------------------------+-----------------------+
| **Requirements**      | **Location in SDK**               | **Remarks**           |
+-----------------------+-----------------------------------+-----------------------+
| Common baseline code  | <PDK>/packages/ti/drv             | common code for       |
|                       | /icss_emac/firmware/icss_dualemac | dual_emac and switch  |
+-----------------------+-----------------------------------+-----------------------+
| DUAL_EMAC             | <PDK>/packages/ti/drv             | dual_emac firmware    |
|                       | /icss_emac/firmware/icss_dualemac | specific code         |
+-----------------------+-----------------------------------+-----------------------+
| SWITCH                | <PDK>/packages/ti/drv             | switch firmware       |
|                       | /icss_emac/firmware/icss_switch   | specific code         |
+-----------------------+-----------------------------------+-----------------------+

| 

Firmware Build Instruction
==========================

Build instruction from Processor SDK Release package
---------------------------------------------------

.. rubric:: Pre-requisites to Building
   :name: pre-requisites-to-building

::

    Refer to the Processor SDK RTOS Building page for information on setting up build environment. 

.. rubric:: Compiling ICSS-EMAC FIRMWARES
   :name: compiling-icss-emac-firmwares

-  cd <PDK>/packages/ti/drv/icss_emac
-  make firm

Firmware binaries at the end of the build will be located at:

-  <PDK>/packages/ti/drv/icss_emac/firmware/<FIRMWARE_TYPE>/bin/<SOC>/<HOST_CORE>/<REVISION>

-  <FIRMWARE_TYPE> indicates the firmware type i.e. icss_dualemac for
   DUAL_EMAC or icss_switch for SWITCH

-  <SOC> indicates the SOC type.

-  <HOST_CORE> indicates the Host core type on which the built binary
   can be loaded.

-  <REVISION> indicates the revision of the firmware binary based on
   core. (There are 2 revision of PRU ICSS core)

| 

Build instruction from GIT
--------------------------

Following are the steps for building firmware from any external
environment outside PROC SDK RTOS.

-  Creation of directories

   -  Create a working directory e.g. <WORK_DIR>
   -  Create a new directory named ti inside working directory. i.e.
      <WORK_DIR/ti>
   -  Create a new directory called drv inside ti. i.e.
      <WORK_DIR/ti/drv>

-  Clone of Repos

   -  Git clone pdk build repo into ti directory. i.e.
      <WORK_DIR/ti/build>
   -  Git clone icss_emac repo into ti/drv directory. i.e.
      <WORK_DIR/ti/drv/icss_emac>

-  Setting Environment Variables

   -  Export CLPRU install path. i.e. export CL_PRU_INSTALL_PATH=clpru
      toolchain directory
   -  Export pdk install path. i.e. export PDK_INSTALL_PATH=<WORK_DIR>
   -  Export LIMIT_SOCS Variable i.e. LIMIT_SOCS=<SOC> [Optional for
      limiting to some SOCs]

-  Build command

   -  Run make firm/firm_clean to build/clean firmware from icss_emac
      directory i.e. <WORK_DIR/ti/drv/icss_emac>

-  Generated binaries

   -  the firmware binaries which will be located in
      <WORK_DIR/ti/drv/icss_emac/firmware/<FIRMWARE_TYPE>/bin/<SOC>/<HOST_CORE>/<REVISION>>

| 

Supported EVMs
==============

The following is a list of EVMS supported and the PRU-ICSS ethernet
ports to be used:

+-----------------------+-----------------------+-----------------------+
| EVM Name              | PRU-ICSS Instance     | Supported PRU ICSS    |
|                       |                       | core revision         |
+-----------------------+-----------------------+-----------------------+
| icev2AM335x           | PRU-ICSS instance 1   | REV1                  |
+-----------------------+-----------------------+-----------------------+
| idkAM437x             | PRU-ICSS instance 2   | REV1                  |
+-----------------------+-----------------------+-----------------------+
| idkAM571x             | PRU-ICSS instance 2   | REV2                  |
+-----------------------+-----------------------+-----------------------+
| idkAM572x             | PRU-ICSS instance 2   | REV1 & REV2 (Earlier  |
|                       |                       | version of AM572x soc |
|                       |                       | had REV1 pru cores    |
|                       |                       | while later had REV2  |
|                       |                       | pru cores)            |
+-----------------------+-----------------------+-----------------------+
| iceK2G                | PRU-ICSS instance 2   | REV2                  |
+-----------------------+-----------------------+-----------------------+

| 

Running ICSS-EMAC FIRMWARES Example
===================================

Please go through the following page for example demonstrating the use
of the firmware via icss-emac driver.
`[1] <index_device_drv.html#icss-emac>`__

| 

.. rubric:: Firmware Design Guide
   :name: firmware-design-guide

+-----------------------------------+-----------------------------------+
| **Document**                      | **Location**                      |
+-----------------------------------+-----------------------------------+
| ICSS DUAL EMAC FIRMWARE Design    | <PDK>/packages/ti/drv/icss_emac/f |
| Guide                             | irmware/icss_dualemac/docs/ICSS_D |
|                                   | UAL_EMAC_Firmware_Design_Guide.pd |
|                                   | f                                 |
+-----------------------------------+-----------------------------------+
| ICSS SWITCH FIRMWARE Design Guide | <PDK>/packages/ti/drv/icss_emac/f |
|                                   | irmware/icss_switch/docs/ICSS_SWI |
|                                   | TCH_Firmware_Design_Guide.pdf     |
+-----------------------------------+-----------------------------------+

**NOTE: For normal use case, there is no need to refer this document.
Unless you wish to go through the internal working for firmware and/or
wanted to modify it.**

| 

.. raw:: html

