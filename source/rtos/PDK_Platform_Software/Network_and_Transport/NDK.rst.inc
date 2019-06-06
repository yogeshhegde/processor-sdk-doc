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

.. Image:: ../images/NDK_ARCH.png

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
|**Install Directory**          | $(TI_PDK_INSTALL_DIR)\packages\ti\transport\ndk\nimu                  |
+-------------------------------+-----------------------------------------------------------------------+
|**Project Type**               |`Eclipse RTSC <http://www.eclipse.org/rtsc/>`__                        |
+-------------------------------+-----------------------------------------------------------------------+
|**Endian Support**             | Little                                                                |
+-------------------------------+-----------------------------------------------------------------------+
|**Library Path**               | $(TI_PDK_INSTALL_DIR)\packages\ti\transport\ndk\nimu\lib              |
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
|**Install Directory**          | $(TI_PDK_INSTALL_DIR)\packages\ti\transport\ndk\nimu_icss             |
+-------------------------------+-----------------------------------------------------------------------+
|**Project Type**               |`Eclipse RTSC <http://www.eclipse.org/rtsc/>`__                        |
+-------------------------------+-----------------------------------------------------------------------+
|**Endian Support**             | Little                                                                |
+-------------------------------+-----------------------------------------------------------------------+
|**Library Path**               | $(TI_PDK_INSTALL_DIR)\packages\ti\transport\ndk\nimu_icss\lib         |
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
  c:\ti\ccsv6 directory . Please refer to `Rebuilding
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

+-----------------+-----------------+-----------------+-----------------+
| Name            | Description     | EVM             | Expected        |
|                 |                 | Configuration   | Results         |
+=================+=================+=================+=================+
| NIMU_BasicExamp | | Example       | | icev2AM335x:  | | Run ping from |
| le_evmXXXX_armE |   demonstrates  |   Jumpers J18   |   any other PC  |
| xampleproject   |   ping from     |   and J19 need  |   in the same   |
|                 |   external      |   to be set     |   subnet        |
|                 |   source to     |   properly to   |                 |
|                 |   Gigabit       |   select CPSW   | Ping response   |
|                 |   Ethernet port |   or ICSS mode. | from the EVM    |
|                 |   on EVM.       |                 | verifies        |
|                 |                 | | Pin2 and Pin3 | successful      |
|                 |                 |   need to be    | execution of    |
|                 |                 |   connected for | example.        |
|                 |                 |   ICSS mode and |                 |
|                 |                 |   Pin1 and Pin2 |                 |
|                 |                 |   for CPSW      |                 |
|                 |                 |   mode.         |                 |
|                 |                 |                 |                 |
|                 |                 | Update \*.cfg   |                 |
|                 |                 | file with       |                 |
|                 |                 | static IP to    |                 |
|                 |                 | test. NIMU for  |                 |
|                 |                 | CPSW test Tests |                 |
|                 |                 | requires        |                 |
|                 |                 | connection of   |                 |
|                 |                 | configured      |                 |
|                 |                 | Ethernet port   |                 |
|                 |                 | under test to   |                 |
|                 |                 | external PC on  |                 |
|                 |                 | same subnet.    |                 |
+-----------------+-----------------+-----------------+-----------------+
| NIMU_ICSS_Basic | | Example       | | icev2AM335x:  | Run ping from   |
| Example_evmXXXX |   demonstrates  |   Jumpers J18   | any other PC in |
| _armExampleproj |   ping from     |   and J19 need  | the same subnet |
| ect             |   external      |   to be set     |                 |
|                 |   source to     |   properly to   | Ping response   |
|                 |   PRU-ICSS      |   select CPSW   | from the EVM    |
|                 |   Ethernet port |   or ICSS mode. | verifies        |
|                 |   on EVM.       |                 | successful      |
|                 |                 | | Pin2 and Pin3 | execution of    |
|                 |                 |   need to be    | example.        |
|                 |                 |   connected for |                 |
|                 |                 |   ICSS mode and |                 |
|                 |                 |   Pin1 and Pin2 |                 |
|                 |                 |   for CPSW      |                 |
|                 |                 |   mode.         |                 |
|                 |                 |                 |                 |
|                 |                 | Update \*.cfg   |                 |
|                 |                 | file with       |                 |
|                 |                 | static IP to    |                 |
|                 |                 | test. NIMU for  |                 |
|                 |                 | CPSW test Tests |                 |
|                 |                 | requires        |                 |
|                 |                 | connection of   |                 |
|                 |                 | configured      |                 |
|                 |                 | PRU-ICSS        |                 |
|                 |                 | Ethernet port   |                 |
|                 |                 | under test to   |                 |
|                 |                 | external PC on  |                 |
|                 |                 | same subnet.    |                 |
+-----------------+-----------------+-----------------+-----------------+

| 

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
details on steps for running cclink master and slave examples on NDK.

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

.. raw:: html
