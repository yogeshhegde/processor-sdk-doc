.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_PA 

.. rubric:: Introduction
   :name: introduction

The packet accelerator (PA) is one of the main components of the network
coprocessor (NETCP) peripheral in KeyStone devices, including C6678,
K2H/K/E/L. The PA works together with the security accelerator (SA) and
the gigabit Ethernet switch subsystem to form a network processing
solution. The purpose of PA in the NETCP is to perform packet processing
operations such as packet header classification, checksum generation,
and multi-queue routing.

.. rubric:: Driver Configuration
   :name: driver-configuration

The driver configures the PASS subsystem using Pa_config_t structure.
This structure must be initialized before the Pa_create() function is
called and cannot be changed afterwards. Also, there are bunch of
system/global configurations and per entry configurations for PA. For
details about individual fields of this structure and other
configuration API structures, see the Doxygen help by opening
PDK_INSTALL_DIR\packages\ti\drv\PA\docs\doxygen\html\index.html.

.. rubric:: **APIs**
   :name: apis

API reference for application can be found in below file:

::

    #include <ti/drv/PA/PA.h>

.. rubric:: Example
   :name: example

+-----------------------+-----------------------+-----------------------+
| Name                  | Description           | Expected Results      |
+=======================+=======================+=======================+
| PA_Example            | | Example             | | User observes the   |
| application           |   demonstrating       |   output printed over |
|                       |   *simple emac        |   the CCS console     |
|                       |   loopback* use case. |                       |
|                       |   Reference example   |                       |
|                       |   for developers      |                       |
+-----------------------+-----------------------+-----------------------+
| PA_UnitTestApplicatio | | Unit Test           | | User observes the   |
| n                     |   application to test |   output printed over |
|                       |   all APIs            |   the CCS console     |
+-----------------------+-----------------------+-----------------------+
| PA_PktCapTestApplicat | | Packet Capture Unit | | User observes the   |
| ion                   |   Test application.   |   output printed over |
|                       |                       |   the CCS console     |
+-----------------------+-----------------------+-----------------------+

.. rubric:: FAQ
   :name: faq

.. rubric:: What is the difference between internal loopback and
   external loopback?
   :name: what-is-the-difference-between-internal-loopback-and-external-loopback

-  CPSW_LOOPBACK_INTERNAL (default): The transmitted packet is
   loopbacked at the SGMII through SGMII internal loopback
-  CPSW_LOOPBACK_EXTERNAL: The transmitted packet should be loopbacked
   by an application outside of the SOC, e.g., PC, PHY.

.. rubric:: How to test PA EMAC example with a PC?
   :name: how-to-test-pa-emac-example-with-a-pc

The EVM has to be connected to PC via RJ-45 port. By default, the PA
example uses the internal loopback mode, please change code: int
cpswLpbkMode = CPSW_LOOPBACK_INTERNAL to CPSW_LOOPBACK_EXTERNAL.

To test the egress path (from SOC to PC):

-  Rebuilt the CCS project, load and run.
-  The PC should receive 10 identical UDP packets sending out by the PA
   example, the packet is defined by an array pktMatch[] in the code.

To test the ingress direction (from PC to SOC): The PC needs a tool to
send out packets with controlled MAC address, IP address and UDP port
matching the PA layer 2, 3 and 4 classifications, defined by the
following functions:

-  Add_MACAddress(): ethInfo.dst
-  Add_IPAddress(): ipInfo.dst
-  Add_Port (): ports

.. rubric:: How to use PA EMAC example to test other Ethernet ports than
   default?
   :name: how-to-use-pa-emac-example-to-test-other-ethernet-ports-than-default

The Keystone devices may have multiple Ethernet ports, connected through
an internal GbE switch with a host port. There is a pre-defined symbol
"NUM_PORTS" in the text file when creating the PA project. This controls
how many ports used in loopback mode test. In non-loopback case, the
port number may be hardcoded by gNum_Mac_Ports. This has to be changed
for the test. On EVMs, those additional Ethernet ports may be accessed
by various ways: Rear-Transition Module – Breakout Card (RTM-BOC) or
Advanced Mezzanine Card – Breakout Card (AMC-BOC), or AMC backplane,
they are EVM hardware dependent. For example, K2E has 8 SGMII ports. In
the K2E EVM, two Ethernet PHYs (PHY1 and PHY2) are connected to SoC
SGMII 0 and 1 respectively, to provide a copper interface and routed to
a Gigabit RJ-45 connector. The SGMII 2 and 3 of SoC are routed to Port 0
and 1 of the AMC edge connector backplane interface. The SGMII 4 to 7
are routed to RTM connector which can be accessed by RTM BOC. The PA
EMAC example by default tests all 8 ports in loopback. To test
additional ports in non-loopback, check/modify the gNum_Mac_Ports
defined to include the SGMII testing port.

.. rubric:: Can PA be used to forward all incoming packets to host?
   :name: can-pa-be-used-to-forward-all-incoming-packets-to-host

The design of PA is to use firmware to offload host for classifying
packets, the PA has layer 2, 3 and 4 classifications. PA LLD supports
two APIs to add MAC LUT1 classification and routing. The application can
call either the first generation API Pa_addMac() or the second
generation Pa_addMac2() APIs. When using the first API, initialize all
the elements of paEthInfo_t with zero and update the routing info
paRouteInfo_t with pa_DEST_HOST. When using the second generation API,
paEthInfo2_t with validBitMap = 0 and paRouteInfo2_t (in paParamDesc)
with pa_DEST_HOST can be passed. Please refer to Pa_addMac and
Pa_addMac2() API explanations as provided under the doxygen folder of PA
(Or refer to Pa.h interface header file).

.. rubric:: Additional References
   :name: additional-references

+-----------------------------------+-----------------------------------+
| **Document**                      | **Location**                      |
+-----------------------------------+-----------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\PA\docs\doxygen\html\index.h |
|                                   | tml                               |
+-----------------------------------+-----------------------------------+
| Release Notes                     | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\PA\docs\ReleaseNotes_PA_LLD. |
|                                   | pdf                               |
+-----------------------------------+-----------------------------------+

.. raw:: html

