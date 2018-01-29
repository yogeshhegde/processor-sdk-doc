.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide
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
   +--------------------+--------------------+--------------------+--------------------+
   | Module             | Wiki doc           | Config API         | C API              |
   +====================+====================+====================+====================+
   | **`Ipc             | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   | Module </index.php |                    |                    |                    |
   | /IPC_Users_Guide/I |    <div            |    <div            |    <div            |
   | pc_Module>`__**    |    class="center"> |    class="center"> |    class="center"> |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    <div            |    <div            |    <div            |
   |                    |    class="floatnon |    class="floatnon |    class="floatnon |
   |                    | e">                | e">                | e">                |
   |                    |                    |                    |                    |
   |                    | |Book wiki.png|    | |Book config.png|  | |Book run.png|     |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |    </div>          |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |    </div>          |
   +--------------------+--------------------+--------------------+--------------------+
   | **`MessageQ        | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   | Module </index.php |                    |                    |                    |
   | /IPC_Users_Guide/M |    <div            |    <div            |    <div            |
   | essageQ_Module>`__ |    class="center"> |    class="center"> |    class="center"> |
   | **                 |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    <div            |    <div            |    <div            |
   |                    |    class="floatnon |    class="floatnon |    class="floatnon |
   |                    | e">                | e">                | e">                |
   |                    |                    |                    |                    |
   |                    | |Book wiki.png|    | |Book config.png|  | |Book run.png|     |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |    </div>          |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |    </div>          |
   +--------------------+--------------------+--------------------+--------------------+
   | **`ListMP          | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   | Module </index.php |                    |                    |                    |
   | /IPC_Users_Guide/L |    <div            |    <div            |    <div            |
   | istMP_Module>`__   |    class="center"> |    class="center"> |    class="center"> |
   | (BIOS only)**      |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    <div            |    <div            |    <div            |
   |                    |    class="floatnon |    class="floatnon |    class="floatnon |
   |                    | e">                | e">                | e">                |
   |                    |                    |                    |                    |
   |                    | |Book wiki.png|    | |Book config.png|  | |Book run.png|     |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |    </div>          |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |    </div>          |
   +--------------------+--------------------+--------------------+--------------------+
   | **`Heap\*MP        | .. raw:: html      | .. raw:: html      | |Book run.png|     |
   | Modules </index.ph |                    |                    | |Book run.png|     |
   | p/IPC_Users_Guide/ |    <div            |    <div            | |Book run.png|     |
   | HeapMP_Modules>`__ |    class="center"> |    class="center"> |                    |
   | (BIOS only)**      |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      |                    |
   |                    |                    |                    |                    |
   |                    |    <div            |    <div            |                    |
   |                    |    class="floatnon |    class="floatnon |                    |
   |                    | e">                | e">                |                    |
   |                    |                    |                    |                    |
   |                    | |Book wiki.png|    | |Book config.png|  |                    |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      |                    |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |                    |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      |                    |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |                    |
   +--------------------+--------------------+--------------------+--------------------+
   | **`GateMP          | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   | Module </index.php |                    |                    |                    |
   | /IPC_Users_Guide/G |    <div            |    <div            |    <div            |
   | ateMP_Module>`__** |    class="center"> |    class="center"> |    class="center"> |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    <div            |    <div            |    <div            |
   |                    |    class="floatnon |    class="floatnon |    class="floatnon |
   |                    | e">                | e">                | e">                |
   |                    |                    |                    |                    |
   |                    | |Book wiki.png|    | |Book config.png|  | |Book run.png|     |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |    </div>          |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |    </div>          |
   +--------------------+--------------------+--------------------+--------------------+
   | **`Notify          | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   | Module </index.php |                    |                    |                    |
   | /IPC_Users_Guide/N |    <div            |    <div            |    <div            |
   | otify_Module>`__   |    class="center"> |    class="center"> |    class="center"> |
   | (BIOS only)**      |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    <div            |    <div            |    <div            |
   |                    |    class="floatnon |    class="floatnon |    class="floatnon |
   |                    | e">                | e">                | e">                |
   |                    |                    |                    |                    |
   |                    | |Book wiki.png|    | |Book config.png|  | |Book run.png|     |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |    </div>          |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |    </div>          |
   +--------------------+--------------------+--------------------+--------------------+
   | **`SharedRegion    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   | Module </index.php |                    |                    |                    |
   | /IPC_Users_Guide/S |    <div            |    <div            |    <div            |
   | haredRegion_Module |    class="center"> |    class="center"> |    class="center"> |
   | >`__               |                    |                    |                    |
   | (BIOS only)**      | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    <div            |    <div            |    <div            |
   |                    |    class="floatnon |    class="floatnon |    class="floatnon |
   |                    | e">                | e">                | e">                |
   |                    |                    |                    |                    |
   |                    | |Book wiki.png|    | |Book config.png|  | |Book run.png|     |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |    </div>          |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |    </div>          |
   +--------------------+--------------------+--------------------+--------------------+

-  **`The ti.sdo.utils
   Package </index.php/IPC_Users_Guide/The_ti.sdo.utils_Package>`__**
   describes the modules in the ti.sdo.utils package.
   +--------------------+--------------------+--------------------+--------------------+
   | Module             | Wiki doc           | Config API         | C API              |
   +====================+====================+====================+====================+
   | **`List            | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   | Module </index.php |                    |                    |                    |
   | /IPC_Users_Guide/L |    <div            |    <div            |    <div            |
   | ist_Module>`__     |    class="center"> |    class="center"> |    class="center"> |
   | (BIOS only)**      |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    <div            |    <div            |    <div            |
   |                    |    class="floatnon |    class="floatnon |    class="floatnon |
   |                    | e">                | e">                | e">                |
   |                    |                    |                    |                    |
   |                    | |Book wiki.png|    | |Book config.png|  | |Book run.png|     |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |    </div>          |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |    </div>          |
   +--------------------+--------------------+--------------------+--------------------+
   | **`MultiProc       | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   | Module </index.php |                    |                    |                    |
   | /IPC_Users_Guide/M |    <div            |    <div            |    <div            |
   | ultiProc_Module>`_ |    class="center"> |    class="center"> |    class="center"> |
   | _**                |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    <div            |    <div            |    <div            |
   |                    |    class="floatnon |    class="floatnon |    class="floatnon |
   |                    | e">                | e">                | e">                |
   |                    |                    |                    |                    |
   |                    | |Book wiki.png|    | |Book config.png|  | |Book run.png|     |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |    </div>          |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |    </div>          |
   +--------------------+--------------------+--------------------+--------------------+
   | **`NameServer      | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   | Module </index.php |                    |                    |                    |
   | /IPC_Users_Guide/N |    <div            |    <div            |    <div            |
   | ameServer_Module>` |    class="center"> |    class="center"> |    class="center"> |
   | __**               |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    <div            |    <div            |    <div            |
   |                    |    class="floatnon |    class="floatnon |    class="floatnon |
   |                    | e">                | e">                | e">                |
   |                    |                    |                    |                    |
   |                    | |Book wiki.png|    | |Book config.png|  | |Book run.png|     |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |    </div>          |
   |                    |                    |                    |                    |
   |                    | .. raw:: html      | .. raw:: html      | .. raw:: html      |
   |                    |                    |                    |                    |
   |                    |    </div>          |    </div>          |    </div>          |
   +--------------------+--------------------+--------------------+--------------------+

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

+--------------------------------------------+----+---------------------------------------------------------------+
| |Table of Contents| **IPC User's Guide**   |    | `About IPC </index.php/IPC_Users_Guide/About_IPC>`__ |Next|   |
+--------------------------------------------+----+---------------------------------------------------------------+

| 

| 

.. raw:: html

