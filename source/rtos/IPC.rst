========================================
IPC Users Guide - Texas Instruments Wiki
========================================

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

.. rubric:: IPC Users Guide
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
| |Table of Contents|   |                       | `About                |
| **IPC User's Guide**  |                       | IPC </index.php/IPC_U |
|                       |                       | sers_Guide/About_IPC> |
|                       |                       | `__                   |
|                       |                       | |Next|                |
+-----------------------+-----------------------+-----------------------+

| 

| 

.. raw:: html

   <div class="floatright">

|IPC comm features.JPG|

.. raw:: html

   </div>

Inter-Processor Communication (IPC) provides a processor-agnostic API
which can be used for communication between processors in a
multi-processor environment (inter-core), communication to other threads
on same processor (inter-process), and communication to peripherals
(inter-device). The API supports message passing, streams, and linked
lists.
IPC can be used to communicate with the following:

-  Other threads on the same processor
-  Threads on other processors running SYS/BIOS
-  Threads on other processors running an HLOS (e.g., Linux, QNX,
   Android)

.. rubric:: About this User's Guide
   :name: about-this-users-guide

This wiki-based user's guide is the new home of the *Inter-Processor
Communication (IPC) User's Guide*
(`SPRUGO6 <http://www.ti.com/lit/pdf/sprugo6>`__). That PDF-based
document will no longer be updated.

This user's guide contains the topics in the following list. It also
links to API reference documentation for static configuration (|Book
config.png|) and run-time C processing (|Book run.png|) for each module.

-  **`About IPC </index.php/IPC_Users_Guide/About_IPC>`__** provides an
   overview of the IPC component.

   -  **`Use Cases for
      IPC </index.php/IPC_Users_Guide/Use_Cases_for_IPC>`__**

-  **`The ti.sdo.ipc
   Package </index.php/IPC_Users_Guide/The_ti.sdo.ipc_Package>`__**
   describes the modules in the ti.sdo.ipc package.
   +-----------------+-----------------+-----------------+-----------------+
   | Module          | Wiki doc        | Config API      | C API           |
   +=================+=================+=================+=================+
   | **`Ipc          | .. raw:: html   | .. raw:: html   | .. raw:: html   |
   | Module </index. |                 |                 |                 |
   | php/IPC_Users_G |    <div         |    <div         |    <div         |
   | uide/Ipc_Module |    class="cente |    class="cente |    class="cente |
   | >`__**          | r">             | r">             | r">             |
   |                 |                 |                 |                 |
   |                 | .. raw:: html   | .. raw:: html   | .. raw:: html   |
   |                 |                 |                 |                 |
   |                 |    <div         |    <div         |    <div         |
   |                 |    class="float |    class="float |    class="float |
   |                 | none">          | none">          | none">          |
   |                 |                 |                 |                 |
   |                 | |Book wiki.png| | |Book           | |Book run.png|  |
   |                 |                 | config.png|     |                 |
   |                 | .. raw:: html   |                 | .. raw:: html   |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |    </div>       |
   |                 |                 |    </div>       |                 |
   |                 | .. raw:: html   |                 | .. raw:: html   |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |    </div>       |
   |                 |                 |    </div>       |                 |
   +-----------------+-----------------+-----------------+-----------------+
   | **`MessageQ     | .. raw:: html   | .. raw:: html   | .. raw:: html   |
   | Module </index. |                 |                 |                 |
   | php/IPC_Users_G |    <div         |    <div         |    <div         |
   | uide/MessageQ_M |    class="cente |    class="cente |    class="cente |
   | odule>`__**     | r">             | r">             | r">             |
   |                 |                 |                 |                 |
   |                 | .. raw:: html   | .. raw:: html   | .. raw:: html   |
   |                 |                 |                 |                 |
   |                 |    <div         |    <div         |    <div         |
   |                 |    class="float |    class="float |    class="float |
   |                 | none">          | none">          | none">          |
   |                 |                 |                 |                 |
   |                 | |Book wiki.png| | |Book           | |Book run.png|  |
   |                 |                 | config.png|     |                 |
   |                 | .. raw:: html   |                 | .. raw:: html   |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |    </div>       |
   |                 |                 |    </div>       |                 |
   |                 | .. raw:: html   |                 | .. raw:: html   |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |    </div>       |
   |                 |                 |    </div>       |                 |
   +-----------------+-----------------+-----------------+-----------------+
   | **`ListMP       | .. raw:: html   | .. raw:: html   | .. raw:: html   |
   | Module </index. |                 |                 |                 |
   | php/IPC_Users_G |    <div         |    <div         |    <div         |
   | uide/ListMP_Mod |    class="cente |    class="cente |    class="cente |
   | ule>`__         | r">             | r">             | r">             |
   | (BIOS only)**   |                 |                 |                 |
   |                 | .. raw:: html   | .. raw:: html   | .. raw:: html   |
   |                 |                 |                 |                 |
   |                 |    <div         |    <div         |    <div         |
   |                 |    class="float |    class="float |    class="float |
   |                 | none">          | none">          | none">          |
   |                 |                 |                 |                 |
   |                 | |Book wiki.png| | |Book           | |Book run.png|  |
   |                 |                 | config.png|     |                 |
   |                 | .. raw:: html   |                 | .. raw:: html   |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |    </div>       |
   |                 |                 |    </div>       |                 |
   |                 | .. raw:: html   |                 | .. raw:: html   |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |    </div>       |
   |                 |                 |    </div>       |                 |
   +-----------------+-----------------+-----------------+-----------------+
   | **`Heap*MP      | .. raw:: html   | .. raw:: html   | |Book run.png|  |
   | Modules </index |                 |                 | |Book run.png|  |
   | .php/IPC_Users_ |    <div         |    <div         | |Book run.png|  |
   | Guide/HeapMP_Mo |    class="cente |    class="cente |                 |
   | dules>`__       | r">             | r">             |                 |
   | (BIOS only)**   |                 |                 |                 |
   |                 | .. raw:: html   | .. raw:: html   |                 |
   |                 |                 |                 |                 |
   |                 |    <div         |    <div         |                 |
   |                 |    class="float |    class="float |                 |
   |                 | none">          | none">          |                 |
   |                 |                 |                 |                 |
   |                 | |Book wiki.png| | |Book           |                 |
   |                 |                 | config.png|     |                 |
   |                 | .. raw:: html   |                 |                 |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |                 |
   |                 |                 |    </div>       |                 |
   |                 | .. raw:: html   |                 |                 |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |                 |
   |                 |                 |    </div>       |                 |
   +-----------------+-----------------+-----------------+-----------------+
   | **`GateMP       | .. raw:: html   | .. raw:: html   | .. raw:: html   |
   | Module </index. |                 |                 |                 |
   | php/IPC_Users_G |    <div         |    <div         |    <div         |
   | uide/GateMP_Mod |    class="cente |    class="cente |    class="cente |
   | ule>`__**       | r">             | r">             | r">             |
   |                 |                 |                 |                 |
   |                 | .. raw:: html   | .. raw:: html   | .. raw:: html   |
   |                 |                 |                 |                 |
   |                 |    <div         |    <div         |    <div         |
   |                 |    class="float |    class="float |    class="float |
   |                 | none">          | none">          | none">          |
   |                 |                 |                 |                 |
   |                 | |Book wiki.png| | |Book           | |Book run.png|  |
   |                 |                 | config.png|     |                 |
   |                 | .. raw:: html   |                 | .. raw:: html   |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |    </div>       |
   |                 |                 |    </div>       |                 |
   |                 | .. raw:: html   |                 | .. raw:: html   |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |    </div>       |
   |                 |                 |    </div>       |                 |
   +-----------------+-----------------+-----------------+-----------------+
   | **`Notify       | .. raw:: html   | .. raw:: html   | .. raw:: html   |
   | Module </index. |                 |                 |                 |
   | php/IPC_Users_G |    <div         |    <div         |    <div         |
   | uide/Notify_Mod |    class="cente |    class="cente |    class="cente |
   | ule>`__         | r">             | r">             | r">             |
   | (BIOS only)**   |                 |                 |                 |
   |                 | .. raw:: html   | .. raw:: html   | .. raw:: html   |
   |                 |                 |                 |                 |
   |                 |    <div         |    <div         |    <div         |
   |                 |    class="float |    class="float |    class="float |
   |                 | none">          | none">          | none">          |
   |                 |                 |                 |                 |
   |                 | |Book wiki.png| | |Book           | |Book run.png|  |
   |                 |                 | config.png|     |                 |
   |                 | .. raw:: html   |                 | .. raw:: html   |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |    </div>       |
   |                 |                 |    </div>       |                 |
   |                 | .. raw:: html   |                 | .. raw:: html   |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |    </div>       |
   |                 |                 |    </div>       |                 |
   +-----------------+-----------------+-----------------+-----------------+
   | **`SharedRegion | .. raw:: html   | .. raw:: html   | .. raw:: html   |
   | Module </index. |                 |                 |                 |
   | php/IPC_Users_G |    <div         |    <div         |    <div         |
   | uide/SharedRegi |    class="cente |    class="cente |    class="cente |
   | on_Module>`__   | r">             | r">             | r">             |
   | (BIOS only)**   |                 |                 |                 |
   |                 | .. raw:: html   | .. raw:: html   | .. raw:: html   |
   |                 |                 |                 |                 |
   |                 |    <div         |    <div         |    <div         |
   |                 |    class="float |    class="float |    class="float |
   |                 | none">          | none">          | none">          |
   |                 |                 |                 |                 |
   |                 | |Book wiki.png| | |Book           | |Book run.png|  |
   |                 |                 | config.png|     |                 |
   |                 | .. raw:: html   |                 | .. raw:: html   |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |    </div>       |
   |                 |                 |    </div>       |                 |
   |                 | .. raw:: html   |                 | .. raw:: html   |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |    </div>       |
   |                 |                 |    </div>       |                 |
   +-----------------+-----------------+-----------------+-----------------+

-  **`The ti.sdo.utils
   Package </index.php/IPC_Users_Guide/The_ti.sdo.utils_Package>`__**
   describes the modules in the ti.sdo.utils package.
   +-----------------+-----------------+-----------------+-----------------+
   | Module          | Wiki doc        | Config API      | C API           |
   +=================+=================+=================+=================+
   | **`List         | .. raw:: html   | .. raw:: html   | .. raw:: html   |
   | Module </index. |                 |                 |                 |
   | php/IPC_Users_G |    <div         |    <div         |    <div         |
   | uide/List_Modul |    class="cente |    class="cente |    class="cente |
   | e>`__           | r">             | r">             | r">             |
   | (BIOS only)**   |                 |                 |                 |
   |                 | .. raw:: html   | .. raw:: html   | .. raw:: html   |
   |                 |                 |                 |                 |
   |                 |    <div         |    <div         |    <div         |
   |                 |    class="float |    class="float |    class="float |
   |                 | none">          | none">          | none">          |
   |                 |                 |                 |                 |
   |                 | |Book wiki.png| | |Book           | |Book run.png|  |
   |                 |                 | config.png|     |                 |
   |                 | .. raw:: html   |                 | .. raw:: html   |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |    </div>       |
   |                 |                 |    </div>       |                 |
   |                 | .. raw:: html   |                 | .. raw:: html   |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |    </div>       |
   |                 |                 |    </div>       |                 |
   +-----------------+-----------------+-----------------+-----------------+
   | **`MultiProc    | .. raw:: html   | .. raw:: html   | .. raw:: html   |
   | Module </index. |                 |                 |                 |
   | php/IPC_Users_G |    <div         |    <div         |    <div         |
   | uide/MultiProc_ |    class="cente |    class="cente |    class="cente |
   | Module>`__**    | r">             | r">             | r">             |
   |                 |                 |                 |                 |
   |                 | .. raw:: html   | .. raw:: html   | .. raw:: html   |
   |                 |                 |                 |                 |
   |                 |    <div         |    <div         |    <div         |
   |                 |    class="float |    class="float |    class="float |
   |                 | none">          | none">          | none">          |
   |                 |                 |                 |                 |
   |                 | |Book wiki.png| | |Book           | |Book run.png|  |
   |                 |                 | config.png|     |                 |
   |                 | .. raw:: html   |                 | .. raw:: html   |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |    </div>       |
   |                 |                 |    </div>       |                 |
   |                 | .. raw:: html   |                 | .. raw:: html   |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |    </div>       |
   |                 |                 |    </div>       |                 |
   +-----------------+-----------------+-----------------+-----------------+
   | **`NameServer   | .. raw:: html   | .. raw:: html   | .. raw:: html   |
   | Module </index. |                 |                 |                 |
   | php/IPC_Users_G |    <div         |    <div         |    <div         |
   | uide/NameServer |    class="cente |    class="cente |    class="cente |
   | _Module>`__**   | r">             | r">             | r">             |
   |                 |                 |                 |                 |
   |                 | .. raw:: html   | .. raw:: html   | .. raw:: html   |
   |                 |                 |                 |                 |
   |                 |    <div         |    <div         |    <div         |
   |                 |    class="float |    class="float |    class="float |
   |                 | none">          | none">          | none">          |
   |                 |                 |                 |                 |
   |                 | |Book wiki.png| | |Book           | |Book run.png|  |
   |                 |                 | config.png|     |                 |
   |                 | .. raw:: html   |                 | .. raw:: html   |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |    </div>       |
   |                 |                 |    </div>       |                 |
   |                 | .. raw:: html   |                 | .. raw:: html   |
   |                 |                 | .. raw:: html   |                 |
   |                 |    </div>       |                 |    </div>       |
   |                 |                 |    </div>       |                 |
   +-----------------+-----------------+-----------------+-----------------+

-  **`Porting IPC </index.php/IPC_Users_Guide/Porting_IPC>`__** provides
   an overview of the steps required to port IPC to new devices or
   systems.
-  **`Optimizing IPC
   Applications </index.php/IPC_Users_Guide/Optimizing_IPC_Applications>`__**
   provides hints for improving the runtime performance and shared
   memory usage of applications that use IPC.
-  **`Rebuilding IPC </index.php/IPC_Users_Guide/Rebuilding_IPC>`__**
   explains how to rebuild the IPC libraries if you modify the source
   files.
-  **`Using IPC on Concerto
   Devices </index.php/IPC_Users_Guide/Using_IPC_on_Concerto_Devices>`__**
   explains how to use IPC if you are designing applications for
   Concerto F28M35x devices.
-  **`Examples </index.php/IPC_Users_Guide/Examples>`__** explains how
   to build and generate the IPC examples.
-  **`Tests </index.php/IPC_Users_Guide/Tests>`__** explains details of
   unit tests part of IPC
-  **`RTOS IPC
   Transports </index.php/Processor_SDK_RTOS_IPC_Transports>`__**
   explains details of the additional RTOS IPC transports provided via
   the Processor SDK PDK component.

.. rubric:: Other TI IPC related links for Host Running Linux
   :name: other-ti-ipc-related-links-for-host-running-linux

-  **`IPC Custom
   ResourceTable <http://processors.wiki.ti.com/index.php/IPC_Resource_customTable>`__**
   Provides details of customizing the resource table.
-  **`IPC GateMP Support for UIO and Misc
   Driver <http://processors.wiki.ti.com/index.php/IPC_GateMP_Support_for_UIO_and_Misc_Driver>`__**
   Provides details of IPC GateMP support with UIO driver
-  **`Early Boot and Late
   Attach <http://processors.wiki.ti.com/index.php/Early_Boot_and_Late_Attach>`__**
   Provides details of Early Boot and Late Attach
-  **`Early Boot and Late Attach in
   Linux <http://processors.wiki.ti.com/index.php/Early_Boot_and_Late_Attach_in_Linux>`__**
   Provides details of Early Boot and Late Attach in Linux
-  **`IPC
   Daemon <http://processors.wiki.ti.com/index.php/IPC_Daemon>`__**
   Provides details of IPC Daemon

.. rubric:: Other TI IPC useful links
   :name: other-ti-ipc-useful-links

-  **`IPC 3.x <http://processors.wiki.ti.com/index.php/IPC_3.x>`__**
   Provides details of IPC 3.x releases
-  **`IPC 3.x Migration
   Guide <http://processors.wiki.ti.com/index.php/IPC_3.x_Migration_Guide>`__**
   Provides details of migrating to IPC 3.x from previous releases
-  **`IPC 3.x
   FAQ <http://processors.wiki.ti.com/index.php/IPC_3.x_FAQ>`__**
   Frequently asked question on IPC 3.x
-  **`IPC
   Benchmarking <http://processors.wiki.ti.com/index.php/IPC_BenchMarking>`__**
   IPC Benchmarking with IPC 3.x

.. rubric:: IPC Install Guides
   :name: ipc-install-guides

-  **`IPC Install Guide
   Linux <http://processors.wiki.ti.com/index.php/IPC_Install_Guide_Linux>`__**
-  **`IPC Install Guide
   Android <http://processors.wiki.ti.com/index.php/IPC_Install_Guide_Android>`__**
-  **`IPC Install Guide
   QNX <http://processors.wiki.ti.com/index.php/IPC_Install_Guide_QNX>`__**
-  **`IPC Install Guide
   BIOS <http://processors.wiki.ti.com/index.php/IPC_Install_Guide_BIOS>`__**

| 

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
Please see the release notes in your IPC installation before starting to
use IPC. The release notes contain important information about feature
support, issues, and compatibility information for a particular release.

.. raw:: html

   </div>

| 

+-----------------------+-----------------------+-----------------------+
| |Table of Contents|   |                       | `About                |
| **IPC User's Guide**  |                       | IPC </index.php/IPC_U |
|                       |                       | sers_Guide/About_IPC> |
|                       |                       | `__                   |
|                       |                       | |Next|                |
+-----------------------+-----------------------+-----------------------+

| 

| 

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
|                                   | **IPC Users Guide** here.*        |
+-----------------------------------+-----------------------------------+

|Hyperlink blue.png|

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

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
"http://processors.wiki.ti.com/index.php?title=IPC_Users_Guide&oldid=230648"

.. raw:: html

   </div>

.. raw:: html

   <div id="catlinks" class="catlinks">

.. raw:: html

   <div id="mw-normal-catlinks" class="mw-normal-catlinks">

`Category </index.php/Special:Categories>`__:

-  `IPC </index.php/Category:IPC>`__

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
   in </index.php?title=Special:UserLogin&returnto=IPC+Users+Guide>`__
-  `Request account </index.php/Special:RequestAccount>`__

.. raw:: html

   </div>

.. raw:: html

   <div id="left-navigation">

.. raw:: html

   <div id="p-namespaces" class="vectorTabs" role="navigation"
   aria-labelledby="p-namespaces-label">

.. rubric:: Namespaces
   :name: p-namespaces-label

-  `Page </index.php/IPC_Users_Guide>`__
-  `Discussion </index.php?title=Talk:IPC_Users_Guide&action=edit&redlink=1>`__

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

-  `Read </index.php/IPC_Users_Guide>`__
-  `View source </index.php?title=IPC_Users_Guide&action=edit>`__
-  `View history </index.php?title=IPC_Users_Guide&action=history>`__

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

` </index.php/Main_Page>`__

.. raw:: html

   </div>

.. raw:: html

   <div id="p-navigation" class="portal" role="navigation"
   aria-labelledby="p-navigation-label">

.. rubric:: Navigation
   :name: p-navigation-label

.. raw:: html

   <div class="body">

-  `Main Page </index.php/Main_Page>`__
-  `All pages </index.php/Special:AllPages>`__
-  `All categories </index.php/Special:Categories>`__
-  `Recent changes </index.php/Special:RecentChanges>`__
-  `Random page </index.php/Special:Random>`__
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
   book </index.php?title=Special:Book&bookcmd=book_creator&referer=IPC+Users+Guide>`__
-  `Download as
   PDF </index.php?title=Special:Book&bookcmd=render_article&arttitle=IPC+Users+Guide&oldid=230648&writer=rl>`__
-  `Printable
   version </index.php?title=IPC_Users_Guide&printable=yes>`__

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
   here </index.php/Special:WhatLinksHere/IPC_Users_Guide>`__
-  `Related
   changes </index.php/Special:RecentChangesLinked/IPC_Users_Guide>`__
-  `Special pages </index.php/Special:SpecialPages>`__
-  `Permanent link </index.php?title=IPC_Users_Guide&oldid=230648>`__
-  `Page information </index.php?title=IPC_Users_Guide&action=info>`__

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

-  This page was last modified on 19 September 2017, at 12:54.
-  This page has been accessed 21,478 times.
-  Content is available under `Creative Commons
   Attribution-ShareAlike <http://creativecommons.org/licenses/by-sa/3.0/>`__
   unless otherwise noted.

-  `Privacy policy </index.php/Project:Privacy_policy>`__
-  `About Texas Instruments Wiki </index.php/Project:About>`__
-  `Disclaimers </index.php/Project:General_disclaimer>`__
-  `Terms of Use </index.php/Project:Terms_of_Service>`__

-  |Creative Commons Attribution-ShareAlike|
-  |Powered by MediaWiki|

.. raw:: html

   <div style="clear:both">

.. raw:: html

   </div>

.. raw:: html

   </div>

.. |Table of Contents| image:: /images/2/21/Ipcug_contents_icon.png
   :width: 20px
   :height: 20px
   :target: /index.php/File:Ipcug_contents_icon.png
.. |Next| image:: /images/d/d8/Ipcug_nextarrow.png
   :width: 15px
   :height: 15px
   :target: /index.php/IPC_User%27s_Guide/About_IPC
.. |IPC comm features.JPG| image:: /images/2/27/IPC_comm_features.JPG
   :width: 500px
   :height: 190px
   :target: /index.php/File:IPC_comm_features.JPG
.. |Book config.png| image:: /images/e/ec/Book_config.png
   :width: 24px
   :height: 24px
   :target: /index.php/File:Book_config.png
.. |Book run.png| image:: /images/f/f0/Book_run.png
   :width: 24px
   :height: 24px
   :target: /index.php/File:Book_run.png
.. |Book wiki.png| image:: /images/6/65/Book_wiki.png
   :width: 30px
   :height: 30px
   :target: /index.php/IPC_User%27s_Guide/Ipc_Module
.. |Book config.png| image:: /images/e/ec/Book_config.png
   :width: 30px
   :height: 30px
   :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/index.html#ti/sdo/ipc/Ipc.html
.. |Book run.png| image:: /images/f/f0/Book_run.png
   :width: 30px
   :height: 30px
   :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_ipc_8h.html
.. |Book wiki.png| image:: /images/6/65/Book_wiki.png
   :width: 30px
   :height: 30px
   :target: /index.php/IPC_User%27s_Guide/MessageQ_Module
.. |Book config.png| image:: /images/e/ec/Book_config.png
   :width: 30px
   :height: 30px
   :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/index.html#ti/sdo/ipc/MessageQ.html
.. |Book run.png| image:: /images/f/f0/Book_run.png
   :width: 30px
   :height: 30px
   :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_message_q_8h.html
.. |Book wiki.png| image:: /images/6/65/Book_wiki.png
   :width: 30px
   :height: 30px
   :target: /index.php/IPC_User%27s_Guide/ListMP_Module
.. |Book config.png| image:: /images/e/ec/Book_config.png
   :width: 30px
   :height: 30px
   :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/index.html#ti/sdo/ipc/ListMP.html
.. |Book run.png| image:: /images/f/f0/Book_run.png
   :width: 30px
   :height: 30px
   :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_list_m_p_8h.html
.. |Book wiki.png| image:: /images/6/65/Book_wiki.png
   :width: 30px
   :height: 30px
   :target: /index.php/IPC_User%27s_Guide/HeapMP_Modules
.. |Book config.png| image:: /images/e/ec/Book_config.png
   :width: 30px
   :height: 30px
   :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/index.html#ti/sdo/ipc/heaps/package.html
.. |Book run.png| image:: /images/f/f0/Book_run.png
   :width: 30px
   :height: 30px
   :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_heap_buf_m_p_8h.html
.. |Book run.png| image:: /images/f/f0/Book_run.png
   :width: 30px
   :height: 30px
   :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_heap_mem_m_p_8h.html
.. |Book run.png| image:: /images/f/f0/Book_run.png
   :width: 30px
   :height: 30px
   :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_heap_multi_buf_m_p_8h.html
.. |Book wiki.png| image:: /images/6/65/Book_wiki.png
   :width: 30px
   :height: 30px
   :target: /index.php/IPC_User%27s_Guide/GateMP_Module
.. |Book config.png| image:: /images/e/ec/Book_config.png
   :width: 30px
   :height: 30px
   :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/index.html#ti/sdo/ipc/GateMP.html
.. |Book run.png| image:: /images/f/f0/Book_run.png
   :width: 30px
   :height: 30px
   :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_gate_m_p_8h.html
.. |Book wiki.png| image:: /images/6/65/Book_wiki.png
   :width: 30px
   :height: 30px
   :target: /index.php/IPC_User%27s_Guide/Notify_Module
.. |Book config.png| image:: /images/e/ec/Book_config.png
   :width: 30px
   :height: 30px
   :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/index.html#ti/sdo/ipc/Notify.html
.. |Book run.png| image:: /images/f/f0/Book_run.png
   :width: 30px
   :height: 30px
   :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_notify_8h.html
.. |Book wiki.png| image:: /images/6/65/Book_wiki.png
   :width: 30px
   :height: 30px
   :target: /index.php/IPC_User%27s_Guide/SharedRegion_Module
.. |Book config.png| image:: /images/e/ec/Book_config.png
   :width: 30px
   :height: 30px
   :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/index.html#ti/sdo/ipc/SharedRegion.html
.. |Book run.png| image:: /images/f/f0/Book_run.png
   :width: 30px
   :height: 30px
   :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_shared_region_8h.html
.. |Book wiki.png| image:: /images/6/65/Book_wiki.png
   :width: 30px
   :height: 30px
   :target: /index.php/IPC_User%27s_Guide/List_Module
.. |Book config.png| image:: /images/e/ec/Book_config.png
   :width: 30px
   :height: 30px
   :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/index.html#ti/sdo/utils/List.html
.. |Book run.png| image:: /images/f/f0/Book_run.png
   :width: 30px
   :height: 30px
   :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/syslink/latest/docs/html/_list_8h.html
.. |Book wiki.png| image:: /images/6/65/Book_wiki.png
   :width: 30px
   :height: 30px
   :target: /index.php/IPC_User%27s_Guide/MultiProc_Module
.. |Book config.png| image:: /images/e/ec/Book_config.png
   :width: 30px
   :height: 30px
   :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/index.html#ti/sdo/utils/MultiProc.html
.. |Book run.png| image:: /images/f/f0/Book_run.png
   :width: 30px
   :height: 30px
   :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_multi_proc_8h.html
.. |Book wiki.png| image:: /images/6/65/Book_wiki.png
   :width: 30px
   :height: 30px
   :target: /index.php/IPC_User%27s_Guide/NameServer_Module
.. |Book config.png| image:: /images/e/ec/Book_config.png
   :width: 30px
   :height: 30px
   :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/index.html#ti/sdo/utils/NameServer.html
.. |Book run.png| image:: /images/f/f0/Book_run.png
   :width: 30px
   :height: 30px
   :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_name_server_8h.html
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
