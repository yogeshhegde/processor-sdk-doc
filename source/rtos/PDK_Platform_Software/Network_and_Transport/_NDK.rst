.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_NDK

NDK Overview
--------------

The Network Development Kit (NDK) is a platform for development and
demonstration of network enabled RTOS applications on TI processors and
includes demonstration software showcasing capabilities across a range
of network enabled applications. The NDK serves as a rapid prototype
platform for the development of network and packet processing
applications, or to add network connectivity to existing applications
for communications, configuration, and control. Using the components
provided in the NDK, developers can quickly move from development
concepts to working implementations attached to the network.

The NDK provides an IPv6 and IPv4 compliant TCP/IP stack working with
the TI-RTOS Kernel real-time operating system. Its primary focus is on
providing the core Layer 3 and Layer 4 stack services along with
additional higher-level network applications such as HTTP server and
DHCP.

The NDK itself does not include any platform or device specific
software. The NDK interfaces through well-defined transport interface,
Network Interface Management UNIT(NIMU) to the PDK and platform
software elements needed for operation. NIMU support. NIMU provides an
interface between the stack and the device drivers through which the
stack can talk to multiple instances of a single or various device
drivers concurrently.

+-------------------------------------------------------------------------------------------------------+
|                                   **Network Development Kit Summary**                                 |
+-------------------------------+-----------------------------------------------------------------------+
|**Component Type**             | Library                                                               |
+-------------------------------+-----------------------------------------------------------------------+
|**Install Package**            |  NDK                                                                  |
+-------------------------------+-----------------------------------------------------------------------+
|**Install Directory**          | ndk_<version>\packages\ti\ndk                                         |
+-------------------------------+-----------------------------------------------------------------------+
|**Project Type**               |`Eclipse RTSC <http://www.eclipse.org/rtsc/>`__                        |
+-------------------------------+-----------------------------------------------------------------------+
|**Endian Support**             | Little                                                                |
+-------------------------------+-----------------------------------------------------------------------+
|**Library Name**               | For details of the libraries delivered as part of the NDK component,  |
|                               | please refer to `[1] <http://www-s.ti.com/sc/techlit/spru523.pdf>`__  |
+-------------------------------+-----------------------------------------------------------------------+
|**Library Path**               | $(NDK_INSTALL_DIR)\packages\ti\ndk                                    |
+-------------------------------+-----------------------------------------------------------------------+
|**Include Paths**              | NDK_INSTALL_DIR is set automatically by CCS based on the version of   |
|                               | NDK you have checked to build with.                                   |
|                               | ${NDK_INSTALL_DIR}\packages\ti\ndk\inc                                |
|                               | ${NDK_INSTALL_DIR}\packages\ti\ndk\inc\tools                          |
+-------------------------------+-----------------------------------------------------------------------+

|

NIMU Transport
---------------

The NDK transport component of the PDK currently provided 2
implementations for the NIMU layer as described in the sections below.
The following diagram is a high level depiction of the NDK/NIMU
architecture with reference to the NIMU implementations. For details
for the NDK/NIMU architecture, please refer to NDK Programmer's
Reference Guide `[2] <http://www-s.ti.com/sc/techlit/spru524.pdf>`__

.. Image:: /images/NDK_ARCH.png

NIMU for CPSW
-------------

NIMU for CPSW provides a common CPSW interface library for NDK to
communicate with when network stack is being implemented in the TI's
Common Platform Ethernet Switch for ethernet packet processing. The
library uses the CSL-R based API interfaces to provide NIMU interface
for NDK. This package has NDK unit test examples for all supported EVMS
as indicated in the table above.

.. note::

  This module is only intended to be used with NDK. As such,
  users should not tie up to its API directly.


+-------------------------------------------------------------------------------------------------------+
|                                       **NIMU for CPSW Summary**                                       |
+-------------------------------+-----------------------------------------------------------------------+
|**Component Type**             | Library                                                               |
+-------------------------------+-----------------------------------------------------------------------+
|**Install Package**            | PDK                                                                   |
+-------------------------------+-----------------------------------------------------------------------+
|**Install Directory**          | $(TI_PDK_INSTALL_DIR)/packages/ti/transport/ndk/nimu                  |
+-------------------------------+-----------------------------------------------------------------------+
|**Project Type**               |`Eclipse RTSC <http://www.eclipse.org/rtsc/>`__                        |
+-------------------------------+-----------------------------------------------------------------------+
|**Endian Support**             | Little                                                                |
+-------------------------------+-----------------------------------------------------------------------+
|**Library Path**               | $(TI_PDK_INSTALL_DIR)/packages/ti/transport/ndk/nimu/lib              |
+-------------------------------+-----------------------------------------------------------------------+
|**Reference Guides**           | None                                                                  |
+-------------------------------+-----------------------------------------------------------------------+

|

NIMU for ICSS
-------------

NIMU for ICSS (PRU-ICSS is Programmable Real-Time Unit Industrial
Communications Subsystem) provides a common PRU-ICSS interface library
for NDK to communicate with when network stack is being implemented in
the PRU-ICSS subsytem for ethernet packet processing (firmware based
switch running on PRU's which are part of the ICSS). The library used
the ICSS_EMAC LLD to provide NIMU interface for NDK. This package has
NDK unit test examples for all supported Devices as indicated in the
table above. For details of the PRU-ICSS, please refer to
`ICCS-EMAC </index.php/Processor_SDK_RTOS_ICSS-EMAC>`__.

| **Note**: This module is only intended to be used with NDK and
  requires ICSS-EMAC low level driver. As such, users should not tie up
  to its API directly.


+-------------------------------------------------------------------------------------------------------+
|                                       **NIMU for ICSS Summary**                                       |
+-------------------------------+-----------------------------------------------------------------------+
|**Component Type**             | Library                                                               |
+-------------------------------+-----------------------------------------------------------------------+
|**Install Package**            | PDK                                                                   |
+-------------------------------+-----------------------------------------------------------------------+
|**Install Directory**          | $(TI_PDK_INSTALL_DIR)/packages/ti/transport/ndk/nimu_icss             |
+-------------------------------+-----------------------------------------------------------------------+
|**Project Type**               |`Eclipse RTSC <http://www.eclipse.org/rtsc/>`__                        |
+-------------------------------+-----------------------------------------------------------------------+
|**Endian Support**             | Little                                                                |
+-------------------------------+-----------------------------------------------------------------------+
|**Library Path**               | $(TI_PDK_INSTALL_DIR)/packages/ti/transport/ndk/nimu_icss/lib         |
+-------------------------------+-----------------------------------------------------------------------+
|**Reference Guides**           | None                                                                  |
+-------------------------------+-----------------------------------------------------------------------+

|

Examples
---------

PING Example
^^^^^^^^^^^^^

All NDK examples using CPSW interface can be found at the following
location:

-  $(TI_PDK_INSTALL_DIR)/packages/ti/transport/ndk/nimu/example

All NDK examples using PRU-ICSS interface can be found at the following
location:

-  $(TI_PDK_INSTALL_DIR)/packages/ti/transport/ndk/nimu_icss/example

Building the NDK examples
"""""""""""""""""""""""""""

| Use pdkProjectCreate.sh for Linux environment or pdkProjectCreate.bat
  for Windows.
| This can be found under the <PDK>/packages folder. The only
  modification to these scripts, if any, is to update the
  CCS_INSTALL_PATH variable to point to CCS location if its not in the
  c:/ti/ccsv6 directory . Please refer to `Rebuilding
  PDK <index_how_to_guides.html#rebuild-drivers-from-pdk-directory>`__ for details of example project
  creation and how to run the example projects using CCS.

NDK Example Description
""""""""""""""""""""""""

For each EVM Type supported, there is a example which demonstates "ping"
use case. Once the application is loaded via CCS and run, you will be
able to ping the configured IP address as specificed int he examples
config file. For example, the config file for NIMU for CPSW for
idkAM572x, can be found in
ti/transport/ndk/nimu/example/am572x/armv7/bios/nimu_idk.cfg. If you
wish to re-configure the IP address of the CPSW interface you will need
to modify the following configuration parameters

-  Ip.address = "new ip address"
-  Ip.mask = "new ip mask"
-  Ip.gatewayIpAddr = "new gatewayIpAddr"

| If you you do change these settings, you will be required to re-build
  the Example Project using CCS.

.. list-table::
   :header-rows: 1

   * - Name

     - Description

     - EVM Configuration

     - Expected Results

     - SOC Supported

   * - NIMU_BasicExample_evmXXXX_<core>exampleproject

     - Example demonstrates ping from external source to Gigabit Ethernet port
       on EVM.

     - icev2AM335x: Jumpers J18 and J19 need to be set properly to select CPSW
       or ICSS mode. Pin2 and Pin3 need to be connected for ICSS mode and Pin1
       and Pin2 for CPSW mode. Update \*.cfg file with static IP to test. NIMU
       for CPSW test requires connection of configured Ethernet port under test
       to external PC on same subnet.

     - Run ping from any other PC in the same subnet.

       Ping response from the EVM verifies successful execution of example.

     - AM335x

       AM437x

       AM57x

       K2G

   * - NIMU_ICSS_BasicExample_evmXXXX_<core>Exampleproject

     - Example demonstrates ping from external source to PRU-ICSS Ethernet port
       on EVM.

     - icev2AM335x: Jumpers J18 and J19 need to be set properly to select CPSW
       or ICSS mode. Pin2 and Pin3 need to be connected for ICSS mode and Pin1
       and Pin2 for CPSW mode. Update \*.cfg file with static IP to test. NIMU
       for CPSW test requires connection of configured Ethernet port under test
       to external PC on same subnet.

     - Run ping from any other PC in the same subnet . Ping response from the
       EVM verifies successful execution of example.

     - AMIC110

       AM335x

       AM437x

       AM57x

       K2G

   * - NIMU_Cpsw_ExampleApp

     - Example demonstrates ping from external source to Gigabit Ethernet port
       on EVM.

     - Update \*.cfg file with static IP to test. NIMU for CPSW test requires
       connection of configured Ethernet port under test to external PC on same
       subnet.

     - Run ping from any other PC in the same subnet. Ping response from the
       EVM verifies successful execution of example.

     - AM65x

       J721E

   * - NIMU_IcssgExampleApp

     - Example demonstrates ping from external source to PRU-ICSS Ethernet port
       on EVM.

     - Update \*.cfg file with static IP to test. NIMU for CPSW test requires
       connection of configured Ethernet port under test to external PC on same
       subnet.

     - Run ping from any other PC in the same subnet . Ping response from the
       EVM verifies successful execution of example.

     - AM65x

   * - NIMU_BasicClientExample_evmXXXX_<core>Exampleproject

     - Example demonstrates creating local servers: TCP, UDP, data, null and
       OOB.

     - Same as above. Use DHCP by default.

     - See TI NDK user guide, section 2 Example Applications for how to test.

     - AM57x

   * - NIMU_emacExampleClient_evmXXXX_<core>Exampleproject

     - Example demonstrates creating local servers: TCP, UDP, data, null and
       OOB.

     - Same as above. Use DHCP by default.

     - See TI NDK user guide, section 2 Example Applications for how to test.

     - C665x

       C667x

       OMAP-L137/8

   * - NIMU_BasicHelloWorldExample_evmXXXX_<core>Exampleproject

     - Example demonstrates UDP helloworld echo test.

     - Same as above. Use DHCP by default.

     - See TI NDK user guide, section 2 Example Applications for how to test.

     - AM57x

   * - NIMU_emacExampleevmXXXX_<core>Exampleproject

     - Example demonstrates UDP helloworld echo test.

     - Same as above. Use DHCP by default.

     - See TI NDK user guide, section 2 Example Applications for how to test.

     - C665x

       C667x

       K2H/K/E/L

       OMAP-L137/8

   * - NIMU_DualMacExample_evmXXXX_<core>Exampleproject

     - Example demonstrates using two EMAC ports with different subnets.

     - Same as above. Use DHCP by default.

     - Run ping from any other PC in the same subnet. Ping response from the
       EVM verifies successful execution of example.

     - AM57x

   * - NIMU_FtpExample_evmXXXX_<core>Exampleproject

     - Example demonstrates FTP server with put and get.

     - Same as above. Use DHCP by default.

     - From host PC make a FTP connection to EVM: ftp <EVM IP address>.
       User:user Password:password Test put and get command and show the
       throughput.

     - AM335x

       AM437x

       AM57x

       K2G

   * - NIMU_ICSSFtpExample_evmXXXX_<core>Exampleproject

     - Example demonstrates FTP server with put and get.

     - Same as above. Use static IP by default.

     - From host PC make a FTP connection to EVM: ftp <EVM IP address>.
       User:user Password:password Test put and get command and show the
       throughput.

     - AM335x

       AM437x

       AM57x

       K2G

   * - NIMU_FtpCpsw_ExampleApp

     - Example demonstrates FTP server with put and get.

     - Same as above. Use static IP by default.

     - From host PC make a FTP connection to EVM: ftp <EVM IP address>.
       User:user Password:password Test put and get command and show the
       throughput.

     - AM65x

       J7

   * - NIMU_FtpIcssg_ExampleApp

     - Example demonstrates FTP server with put and get.

     - Same as above. Use static IP by default.

     - From host PC make a FTP connection to EVM: ftp <EVM IP address>.
       User:user Password:password Test put and get command and show the
       throughput.

     - AM65x

.. note:: Not all the test examples are supported on all the platforms. The NDK
   code is hardware agnostic, the NIMU driver however depends on the specific
   SOC. The NDK code can be ported to different platforms. Some Windows host
   test applications are available under ndk_3_xx_xx_xx\packages\ti\ndk\winapps.


Running NDK example on ARM core of Keystone II devices
""""""""""""""""""""""""""""""""""""""""""""""""""""""""

Before running the NDK example on ARM core of Keystone II
devices(K2H/L/E/G), the following steps need to be performed.

-  Increase the NS_BootTask stack from 2048 to 4096 in netctrl.c:

::

    TaskCreate( NS_BootTask, "ConfigBoot", OS_TASKPRINORM, 4096,(UINT32)hCfg, 0, 0 );

-  Rebuild the NDK
-  Rebuild NIMU driver

|

CCLink Example
---------------

Refer
`Processor_SDK_RTOS_CCLINK <index_Foundational_Components.html#cclink>`__ for
details on steps for running cclink controller and device examples on NDK.

FAQ
---

How to check which versions of NIMU driver is for my SOC?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

There are several versions of NIMU driver for different SOCs. Please
check packages\ti\transport\ndk\nimu\build\makefile.mk

-  V0: C6657
-  V1: C6678
-  V2: K2H, K2K
-  V3: K2L, K2E
-  V4: AM572x, AM571x, AM437x, AM335x
-  V5: K2G
-  V6: OMAP-L137/138
-  V7: AM65x, J7
|

Is there any multicast streams limitation using the NDK?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

In the NDK, the limit is defined by a macro at ti/ndk/stack/igmp/igmp.c:
#define IGMP_MAX_GROUP 32 It is then used to create an array of IGMP
records: static IGMP_REC igmp[IGMP_MAX_GROUP]; The IGMP_MAX_GROUP value
can be increased, then rebuild the NDK stack.


How to share a TCP/IP socket across tasks?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The basic building block of NDK stack code internally is an object handle.
Internally to the stack, both sockets and pipes are addressed by object handles.
However, at the application level, sockets and pipes are treated as file
descriptors. To share a SOCKET, i.e. a file descriptor, a task must first
allocate a file descriptor table by calling the function fdOpenSession(), then
use the function fdShare() to share the file descriptor among multiple tasks.
As described in NDK API reference guide, fdShare() is useful in a case where
Task A opens a session and calls recv() in a loop on a socket. Task B has a
loop that calls send() on the same socket. The call to send() from Task B will
fail and then fdError() will return -1 if you do not call fdOpenSession() and
then fdShare() from the second Task after the first Task has opened the socket.
For an example that calls fdShare(), see the contest.c file in the
<NDK_INSTALL_DIR>/packages/ti/ndk/tools/console directory.


How to tune TCP buffer size for an optimal throughput?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The default TCP buffer size, CFGITEM_IP_SOCKTCPTXBUF/CFGITEM_IP_SOCKTCPRXBUF
is 8192 defined in packages/ti/ndk/inc/stack/inc/resif.h of NDK package and
can be re-configured in RTOS config file,e.g.
Tcp.transmitBufSize = 16384;
Tcp.receiveBufSize = 65536;
NDK also provides a global TCP statistics counter structure NDK_tcps
(ti/ndk/inc/stack/inc/tcpif.h) that can be analyzed in CCS View Expressions
window, similaly, there is a global IP statistics counter structure NDK_ips
(ti/ndk/inc/stack/inc/ipif.h).


Why a pipe creation fails and fdError() returns -1?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Although sockets can be used for inter-task communications, it is not the most
efficient method. The stack provides a second data communications model called
pipes, which allow for local connection oriented communications.
As a pipe is a full duplex connection oriented file descriptor, fdOpenSession()
needs to be called, which opens a file descriptor session on a task thread so
that the task can begin using file descriptor and other stream IO functions.

How do I change the PBM buffer?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

You can configure the PBM buffer used by the NDK by opening the .cfg file with XGCONF, then clicking the Buffers button. This page lets you configure the buffer size, number of buffers and locations of the NDK Packet Buffer Manager (PBM) and the Memory Manager Buffer. Or, you can edit ndk_3_xx_xx_xx\packages\ti\ndk\stack\pbm\pbm_data.c (PKT_NUM_FRAMEBUF and PKT_SIZE_FRAMEBUF) and rebuild the NDK.

Do you have any raw packet example?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

A raw socket is used to receive raw packets. This means packets received at the Ethernet layer will directly pass to the raw socket. Stating it precisely, a raw socket bypasses the normal TCP/IP processing and sends the packets to the specific user application. Please check the TI Network Developer's Kit (NDK) API Reference Guide http://www-s.ti.com/sc/techlit/spru524.pdf A.15 Raw Ethernet Module for details. Code example available in NIMU_emacClientExample_evmXXXX_<CPU>ExampleProject

How do I enable the jumbo packet support?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Jumbo frames have packet sizes larger than 1500 bytes. Jumbo frame support can be built into an application by linking with libraries compiled for Jumbo frame support.  Two parts of changes are needed for NDK/NIMU example:
1. NDK libraries: The NDK libraries would have to be recompiled with the following pre-processor definition added: _INCLUDE_JUMBOFRAME_SUPPORT.
2. NIMU library: the CPSW switch has to be configured to support jumbo packet size and rebuilt. The coding is SOC specific, V0, V4, V5, V6 and V7 NIMU drivers use structure EMAC_OpenConfigInfo and pass the maximum packet size into max_pkt_size field. V1, V2 and V3 NIMU drivers use structure NETIF_DEVICE and pass the maximum packet size into mtu field.
Finally, please rebuild the test application with updated NDK and NIMU libraries. A reference example for C6678 is available at: http://processors.wiki.ti.com/index.php/Enabling_Jumbo_Packet_Support_for_C6678. Note the work was implemented on earlier BIOS MCSDK package which was obsolete.

Keystone PA or NDK example doesn’t work in other boot mode than no-boot mode using CCS/JTAG?
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

When running the program with CCS/JTAG, the default GEL file initializes the SOC. Same initialization, like turning on all the relevant power domains, and configuring the SGMII, Serdes, may not be implemented in other boot modes. First check GEL file under ccs_base\emulation\boards\<boards>\gel, function Global_Default_Setup() function to add the missing initializations into the application. Next, look for any boot mode dependent code in the application.  For example, passPowerUp() is called in no_boot mode to turn on PA, this has to be executed in your application when booting from other boot modes as well.



Additional Documentation References
--------------------------------------

+-----------------------------------+--------------------------------------------+
| **Document**                      | **Location**                               |
+-----------------------------------+--------------------------------------------+
| NDK Programmer's Reference Guide  | http://www-s.ti.com/sc/techlit/spru524.pdf |
+-----------------------------------+--------------------------------------------+
| NDK User's Guide                  | http://www-s.ti.com/sc/techlit/spru523.pdf |
+-----------------------------------+--------------------------------------------+
| Network Developers Kit FAQ        | `Network Developers Kit FAQ`_              |
+-----------------------------------+--------------------------------------------+
| NDK Support Package Ethernet      | http://www-s.ti.com/sc/techlit/sprufp2.pdf |
| Driver Design Guide               |                                            |
+-----------------------------------+--------------------------------------------+
| Rebuilding_the_NDK_Core           | http://processors.wiki.ti.com/index.php/   |
| Rebuilding NDK Core               | Rebuilding_the_NDK_Core                    |
+-----------------------------------+--------------------------------------------+

.. _Network Developers Kit FAQ: http://processors.wiki.ti.com/index.php/Network_Developers_Kit_FAQ

