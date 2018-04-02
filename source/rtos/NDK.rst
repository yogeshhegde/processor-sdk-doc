===============================================
Processor SDK RTOS NDK - Texas Instruments Wiki
===============================================

.. raw:: html

   <div id="mw-page-base" class="noprint">

.. raw:: html

   </div>

.. raw:: html

   <div id="mw-head-base" class="noprint">

.. raw:: html

   </div>

.. raw:: html

   <div id="content" class="mw-body" role="main">

.. raw:: html

   <div id="siteNotice">

.. raw:: html

   <div id="localNotice" lang="en" dir="ltr">

| 

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div class="mw-indicators">

.. raw:: html

   </div>

.. rubric:: Processor SDK RTOS NDK
   :name: firstHeading
   :class: firstHeading

.. raw:: html

   <div id="bodyContent" class="mw-body-content">

.. raw:: html

   <div id="siteSub">

From Texas Instruments Wiki

.. raw:: html

   </div>

.. raw:: html

   <div id="contentSub">

.. raw:: html

   </div>

.. raw:: html

   <div id="jump-to-nav" class="mw-jump">

Jump to: `navigation <#mw-head>`__, `search <#p-search>`__

.. raw:: html

   </div>

.. raw:: html

   <div id="mw-content-text" class="mw-content-ltr" lang="en" dir="ltr">

.. raw:: html

   <div class="hf-nsheader">

.. raw:: html

   </div>

.. raw:: html

   <div class="hf-header">

.. raw:: html

   </div>

| 

+-----------------------+-----------------------+-----------------------+
| `RTOS Software        | →                     | Networking            |
| Developer             |                       |                       |
| Guide </index.php/Pro |                       |                       |
| cessor_SDK_RTOS_Softw |                       |                       |
| are_Developer_Guide>` |                       |                       |
| __                    |                       |                       |
+-----------------------+-----------------------+-----------------------+

| 

| 

+-----------------------------------+-----------------------------------+
| .. rubric:: **Overview**          | .. rubric:: **User Interface**    |
|    :name: overview                |    :name: user-interface          |
|                                   |                                   |
| -  `NDK                           |                                   |
|    Overview </index.php/Processor |                                   |
| _SDK_RTOS_NDK#NDK_Overview>`__    |                                   |
| -  `NIMU                          |                                   |
|    Transport </index.php/Processo |                                   |
| r_SDK_RTOS_NDK#NIMU_Transport>`__ |                                   |
|                                   |                                   |
|    -  `NIMU for                   |                                   |
|       CPSW </index.php/Processor_ |                                   |
| SDK_RTOS_NDK#NIMU_FOR_CPSW>`__    |                                   |
|    -  `NIMU for                   |                                   |
|       ICSS </index.php/Processor_ |                                   |
| SDK_RTOS_NDK#NIMU_FOR_ICSS>`__    |                                   |
|                                   |                                   |
| -  `Additional Documentation      |                                   |
|    References </index.php/Process |                                   |
| or_SDK_RTOS_NDK#Additional_Docume |                                   |
| ntation_References>`__            |                                   |
+-----------------------------------+-----------------------------------+
| .. rubric:: **Application**       | .. rubric:: **Debug**             |
|    :name: application             |    :name: debug                   |
|                                   |                                   |
| -  `Examples </index.php/Processo | -  `FAQ </index.php/Processor_SDK |
| r_SDK_RTOS_NDK#Examples>`__       | _RTOS_NDK#FAQ>`__                 |
|                                   |                                   |
|    -  `PING                       |                                   |
|       Example </index.php/Process |                                   |
| or_SDK_RTOS_NDK#PING_Example>`__  |                                   |
|    -  `CCLink                     |                                   |
|       Example </index.php/Process |                                   |
| or_SDK_RTOS_NDK#CCLink_Example>`_ |                                   |
| _                                 |                                   |
+-----------------------------------+-----------------------------------+

.. rubric:: NDK Overview
   :name: ndk-overview

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

| The NDK itself does not include any platform or device specific
  software. The NDK interfaces through well-defined transport interface,
  Network Interface Management UNIT(NIMU) to the PDK and platform
  software elements needed for operation. NIMU support. NIMU provides an
  interface between the stack and the device drivers through which the
  stack can talk to multiple instances of a single or various device
  drivers concurrently.

**Network Development Kit Summary**

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

**Component Type**

Library

**Install Package**

NDK

**Install Directory**

ndk_<version>\packages\ti\ndk

**Project Type**

`Eclipse RTSC <http://www.eclipse.org/rtsc/>`__

**Endian Support**

Little

**Library Name**

For details of the libraries delivered as part of the NDK component,
please refer to `[1] <http://www-s.ti.com/sc/techlit/spru523.pdf>`__

**Library Path**

$(NDK_INSTALL_DIR)\packages\ti\ndk

**Include Paths**

| NDK_INSTALL_DIR is set automatically by CCS based on the version of
  NDK you have checked to build with.

| ${NDK_INSTALL_DIR}\packages\ti\ndk\inc
| ${NDK_INSTALL_DIR}\packages\ti\ndk\inc\tools

| 

NIMU Transport
==============

| The NDK transport component of the PDK currently provided 2
  implementations for the NIMU layer as described in the sections below.
  The following diagram is a high level depiction of the NDK/NIMU
  architecture with reference to the NIMU implementations. For details
  for the NDK/NIMU architecture, please refer to NDK Programmer's
  Reference Guide `[2] <http://www-s.ti.com/sc/techlit/spru524.pdf>`__
| |NDK ARCH.png|

NIMU for CPSW
-------------

NIMU for CPSW provides a common CPSW interface library for NDK to
communicate with when network stack is being implemented in the TI's
Common Platform Ethernet Switch for ethernet packet processing. The
library uses the CSL-R based API interfaces to provide NIMU interface
for NDK. This package has NDK unit test examples for all supported EVMS
as indicated in the table above.

| **Note**: This module is only intended to be used with NDK. As such,
  users should not tie up to its API directly.

**NIMU for CPSW Summary**

**Component Type**

Library

**Install Package**

PDK

**Install Directory**

$(TI_PDK_INSTALL_DIR)\packages\ti\transport\ndk\nimu

**Project Type**

`Eclipse RTSC <http://www.eclipse.org/rtsc/>`__

**Endian Support**

Little

**Library Path**

$(TI_PDK_INSTALL_DIR)\packages\ti\transport\ndk\nimu\lib

**Reference Guides**

None

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
`ICCS-EMAC <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_ICSS-EMAC>`__.

| **Note**: This module is only intended to be used with NDK and
  requires ICSS-EMAC low level driver. As such, users should not tie up
  to its API directly.

**NIMU for ICSS Summary**

**Component Type**

Library

**Install Package**

PDK

**Install Directory**

$(TI_PDK_INSTALL_DIR)\packages\ti\transport\ndk\nimu_icss

**Project Type**

`Eclipse RTSC <http://www.eclipse.org/rtsc/>`__

**Endian Support**

Little

**Library Path**

$(TI_PDK_INSTALL_DIR)\packages\ti\transport\ndk\nimu_icss\lib

**Reference Guides**

None

| 

Examples
========

PING Example
------------

All NDK examples using CPSW interface can be found at the following
location:

-  $(TI_PDK_INSTALL_DIR)/packages/ti/transport/ndk/nimu/example

All NDK examples using PRU-ICSS interface can be found at the following
location:

-  $(TI_PDK_INSTALL_DIR)/packages/ti/transport/ndk/nimu_icss/example

Building the NDK examples
~~~~~~~~~~~~~~~~~~~~~~~~~

| Use pdkProjectCreate.sh for Linux environment or pdkProjectCreate.bat
  for Windows.
| This can be found under the <PDK>/packages folder. The only
  modification to these scripts, if any, is to update the
  CCS_INSTALL_PATH variable to point to CCS location if its not in the
  c:\ti\ccsv6 directory . Please refer to `Rebuilding
  PDK <http://processors.wiki.ti.com/index.php/Rebuilding_The_PDK>`__ for details of example project
  creation and how to run the example projects using CCS.

NDK Example Description
~~~~~~~~~~~~~~~~~~~~~~~

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
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

Before running the NDK example on ARM core of Keystone II
devices(K2H/L/E/G), the following steps need to be performed.

-  Increase the NS_BootTask stack from 2048 to 4096 in netctrl.c:

::

    TaskCreate( NS_BootTask, "ConfigBoot", OS_TASKPRINORM, 4096,(UINT32)hCfg, 0, 0 );

-  Rebuild the NDK
-  Rebuild NIMU driver

| 

CCLink Example
--------------

Refer
`Processor_SDK_RTOS_CCLINK <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_CCLINK>`__ for
details on steps for running cclink master and slave examples on NDK.

FAQ
---

How to check which versions of NIMU driver is for my SOC?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

There are several versions of NIMU driver for different SOCs. Please
check packages\ti\transport\ndk\nimu\build\makefile.mk

-  V0: C6657
-  V1: C6678
-  V2: K2H, K2K
-  V3: K2L, K2E
-  V4: AM572x, AM571x, AM437x, AM335x
-  V5: K2G

Is there any multicast streams limitation using the NDK?
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

In the NDK, the limit is defined by a macro at ti/ndk/stack/igmp/igmp.c:
#define IGMP_MAX_GROUP 32 It is then used to create an array of IGMP
records: static IGMP_REC igmp[IGMP_MAX_GROUP]; The IGMP_MAX_GROUP value
can be increased, then rebuild the NDK stack.

Additional Documentation References
===================================

+-----------------------------------+-----------------------------------+
| **Document**                      | **Location**                      |
+-----------------------------------+-----------------------------------+
| NDK Programmer's Reference Guide  | http://www-s.ti.com/sc/techlit/sp |
|                                   | ru524.pdf                         |
+-----------------------------------+-----------------------------------+
| NDK User's Guide                  | http://www-s.ti.com/sc/techlit/sp |
|                                   | ru523.pdf                         |
+-----------------------------------+-----------------------------------+
| Network Developers Kit FAQ        | http://processors.wiki.ti.com/ind |
|                                   | ex.php/Network_Developers_Kit_FAQ |
+-----------------------------------+-----------------------------------+
| NDK Support Package Ethernet      | http://www-s.ti.com/sc/techlit/sp |
| Driver Design Guide               | rufp2.pdf                         |
+-----------------------------------+-----------------------------------+
| Rebuilding_the_NDK_Core           | http://processors.wiki.ti.com/ind |
| Rebuilding NDK Core               | ex.php/Rebuilding_the_NDK_Core    |
+-----------------------------------+-----------------------------------+

.. raw:: html

   <div class="hf-footer">

.. raw:: html

   </div>

.. raw:: html

   <div class="hf-nsfooter">

+-----------------------------------+-----------------------------------+
| |E2e.jpg|                         | *For technical support please     |
|                                   | post your questions at            |
|                                   | http://e2e.ti.com. Please post    |
|                                   | only comments about the article   |
|                                   | **Processor SDK RTOS NDK** here.* |
+-----------------------------------+-----------------------------------+

|Hyperlink blue.png|

.. raw:: html

   </div>

**Links**

+-----------------+-----------------+-----------------+-----------------+
| | `Amplifiers & | | `DLP &        | `Processors <ht | | `Switches &   |
|   Linear <http: |   MEMS <http:// | tp://www.ti.com |   Multiplexers  |
| //www.ti.com/ls | www.ti.com/lsds | /lsds/ti/dsp/em | <http://www.ti. |
| ds/ti/analog/am | /ti/analog/mems | bedded_processo | com/lsds/ti/ana |
| plifier_and_lin | /mems.page>`__  | r.page>`__      | log/switches_an |
| ear.page>`__    | | `High-Reliabi |                 | d_multiplexers. |
| | `Audio <http: | lity <http://ww | -  `ARM         | page>`__        |
| //www.ti.com/ls | w.ti.com/lsds/t |    Processors < | | `Temperature  |
| ds/ti/analog/au | i/analog/high_r | http://www.ti.c |   Sensors &     |
| dio/audio_overv | eliability.page | om/lsds/ti/dsp/ |   Control       |
| iew.page>`__    | >`__            | arm.page>`__    |   ICs <http://w |
| | `Broadband    | | `Interface <h | -  `Digital     | ww.ti.com/lsds/ |
|   RF/IF &       | ttp://www.ti.co |    Signal       | ti/analog/tempe |
|   Digital       | m/lsds/ti/analo |    Processors   | rature_sensor.p |
|   Radio <http:/ | g/interface/int |    (DSP) <http: | age>`__         |
| /www.ti.com/lsd | erface.page>`__ | //www.ti.com/ls | | `Wireless     |
| s/ti/analog/rfi | | `Logic <http: | ds/ti/dsp/home. |   Connectivity  |
| f.page>`__      | //www.ti.com/ls | page>`__        | <http://focus.t |
| | `Clocks &     | ds/ti/logic/hom | -  `Microcontro | i.com/wireless/ |
|   Timers <http: | e_overview.page | llers           | docs/wirelessov |
| //www.ti.com/ls | >`__            |    (MCU) <http: | erview.tsp?fami |
| ds/ti/analog/cl | | `Power        | //www.ti.com/ls | lyId=2003&secti |
| ocksandtimers/c |   Management <h | ds/ti/microcont | onId=646&tabId= |
| locks_and_timer | ttp://www.ti.co | roller/home.pag | 2735>`__        |
| s.page>`__      | m/lsds/ti/analo | e>`__           |                 |
| | `Data         | g/powermanageme | -  `OMAP        |                 |
|   Converters <h | nt/power_portal |    Applications |                 |
| ttp://www.ti.co | .page>`__       |    Processors < |                 |
| m/lsds/ti/analo |                 | http://www.ti.c |                 |
| g/dataconverter |                 | om/lsds/ti/omap |                 |
| s/data_converte |                 | -applications-p |                 |
| r.page>`__      |                 | rocessors/the-o |                 |
|                 |                 | map-experience. |                 |
|                 |                 | page>`__        |                 |
+-----------------+-----------------+-----------------+-----------------+

.. raw:: html

   <div id="tiPrivacy">

.. raw:: html

   </div>

.. raw:: html

   <div class="printfooter">

Retrieved from
"http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_NDK&oldid=232568"

.. raw:: html

   </div>

.. raw:: html

   <div id="catlinks" class="catlinks">

.. raw:: html

   <div id="mw-normal-catlinks" class="mw-normal-catlinks">

`Category <http://processors.wiki.ti.com/index.php/Special:Categories>`__:

-  `PROCESSOR-SDK <http://processors.wiki.ti.com/index.php/Category:PROCESSOR-SDK>`__

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div class="visualClear">

.. raw:: html

   </div>

.. raw:: html

   <div id="mw-navigation">

.. rubric:: Navigation menu
   :name: navigation-menu

.. raw:: html

   <div id="mw-head">

.. raw:: html

   <div id="p-personal" role="navigation"
   aria-labelledby="p-personal-label">

.. rubric:: Personal tools
   :name: p-personal-label

-  `Log
   in <http://processors.wiki.ti.com/index.php?title=Special:UserLogin&returnto=Processor+SDK+RTOS+NDK>`__
-  `Request account <http://processors.wiki.ti.com/index.php/Special:RequestAccount>`__

.. raw:: html

   </div>

.. raw:: html

   <div id="left-navigation">

.. raw:: html

   <div id="p-namespaces" class="vectorTabs" role="navigation"
   aria-labelledby="p-namespaces-label">

.. rubric:: Namespaces
   :name: p-namespaces-label

-  `Page <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_NDK>`__
-  `Discussion <http://processors.wiki.ti.com/index.php?title=Talk:Processor_SDK_RTOS_NDK&action=edit&redlink=1>`__

.. raw:: html

   </div>

.. raw:: html

   <div id="p-variants" class="vectorMenu emptyPortlet"
   role="navigation" aria-labelledby="p-variants-label">

.. rubric:: Variants\ ` <#>`__
   :name: p-variants-label

.. raw:: html

   <div class="menu">

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div id="right-navigation">

.. raw:: html

   <div id="p-views" class="vectorTabs" role="navigation"
   aria-labelledby="p-views-label">

.. rubric:: Views
   :name: p-views-label

-  `Read <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_NDK>`__
-  `View source <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_NDK&action=edit>`__
-  `View
   history <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_NDK&action=history>`__

.. raw:: html

   </div>

.. raw:: html

   <div id="p-cactions" class="vectorMenu emptyPortlet"
   role="navigation" aria-labelledby="p-cactions-label">

.. rubric:: More\ ` <#>`__
   :name: p-cactions-label

.. raw:: html

   <div class="menu">

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div id="p-search" role="search">

.. rubric:: Search
   :name: search

.. raw:: html

   <div id="simpleSearch">

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div id="mw-panel">

.. raw:: html

   <div id="p-logo" role="banner">

` <http://processors.wiki.ti.com/index.php/Main_Page>`__

.. raw:: html

   </div>

.. raw:: html

   <div id="p-navigation" class="portal" role="navigation"
   aria-labelledby="p-navigation-label">

.. rubric:: Navigation
   :name: p-navigation-label

.. raw:: html

   <div class="body">

-  `Main Page <http://processors.wiki.ti.com/index.php/Main_Page>`__
-  `All pages <http://processors.wiki.ti.com/index.php/Special:AllPages>`__
-  `All categories <http://processors.wiki.ti.com/index.php/Special:Categories>`__
-  `Recent changes <http://processors.wiki.ti.com/index.php/Special:RecentChanges>`__
-  `Random page <http://processors.wiki.ti.com/index.php/Special:Random>`__
-  `Help <https://www.mediawiki.org/wiki/Special:MyLanguage/Help:Contents>`__

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div id="p-coll-print_export" class="portal" role="navigation"
   aria-labelledby="p-coll-print_export-label">

.. rubric:: Print/export
   :name: p-coll-print_export-label

.. raw:: html

   <div class="body">

-  `Create a
   book <http://processors.wiki.ti.com/index.php?title=Special:Book&bookcmd=book_creator&referer=Processor+SDK+RTOS+NDK>`__
-  `Download as
   PDF <http://processors.wiki.ti.com/index.php?title=Special:Book&bookcmd=render_article&arttitle=Processor+SDK+RTOS+NDK&oldid=232568&writer=rl>`__
-  `Printable
   version <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_NDK&printable=yes>`__

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div id="p-tb" class="portal" role="navigation"
   aria-labelledby="p-tb-label">

.. rubric:: Toolbox
   :name: p-tb-label

.. raw:: html

   <div class="body">

-  `What links
   here <http://processors.wiki.ti.com/index.php/Special:WhatLinksHere/Processor_SDK_RTOS_NDK>`__
-  `Related
   changes <http://processors.wiki.ti.com/index.php/Special:RecentChangesLinked/Processor_SDK_RTOS_NDK>`__
-  `Special pages <http://processors.wiki.ti.com/index.php/Special:SpecialPages>`__
-  `Permanent
   link <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_NDK&oldid=232568>`__
-  `Page
   information <http://processors.wiki.ti.com/index.php?title=Processor_SDK_RTOS_NDK&action=info>`__

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div id="footer" role="contentinfo">

-  This page was last modified on 27 December 2017, at 15:28.
-  This page has been accessed 6,887 times.
-  Content is available under `Creative Commons
   Attribution-ShareAlike <http://creativecommons.org/licenses/by-sa/3.0/>`__
   unless otherwise noted.

-  `Privacy policy <http://processors.wiki.ti.com/index.php/Project:Privacy_policy>`__
-  `About Texas Instruments Wiki <http://processors.wiki.ti.com/index.php/Project:About>`__
-  `Disclaimers <http://processors.wiki.ti.com/index.php/Project:General_disclaimer>`__
-  `Terms of Use <http://processors.wiki.ti.com/index.php/Project:Terms_of_Service>`__

-  |Creative Commons Attribution-ShareAlike|
-  |Powered by MediaWiki|

.. raw:: html

   <div style="clear:both">

.. raw:: html

   </div>

.. raw:: html

   </div>

.. |NDK ARCH.png| image:: /images/0/0a/NDK_ARCH.png
   :width: 561px
   :height: 504px
   :target: /index.php/File:NDK_ARCH.png
.. |E2e.jpg| image:: /images/8/82/E2e.jpg
   :width: 305px
   :height: 63px
   :target: /index.php/File:E2e.jpg
.. |Hyperlink blue.png| image:: /images/9/9f/Hyperlink_blue.png
   :width: 96px
   :height: 96px
   :target: /index.php/File:Hyperlink_blue.png
.. |Creative Commons Attribution-ShareAlike| image:: /resources/assets/licenses/cc-by-sa.png
   :width: 88px
   :height: 31px
   :target: http://creativecommons.org/licenses/by-sa/3.0/
.. |Powered by MediaWiki| image:: /resources/assets/poweredby_mediawiki_88x31.png
   :width: 88px
   :height: 31px
   :target: //www.mediawiki.org/
