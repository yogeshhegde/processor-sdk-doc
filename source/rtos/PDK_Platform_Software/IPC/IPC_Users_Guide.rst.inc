.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide 

Inter-Processor Communication (IPC) provides a processor-agnostic API which can be used for communication between processors in a multi-processor environment (inter-core), communication to other threads on same processor (inter-process), and communication to peripherals (inter-device). 
The API supports message passing, streams, and linked lists.
IPC can be used to communicate with the following:

- Other threads on the same processor
- Threads on other processors running SYS/BIOS
- Threads on other processors running an HLOS (e.g., Linux, QNX, Android)

.. image:: ../images/IPC_comm_features.JPG

.. rubric:: About this User's Guide
   :name: about-this-users-guide

This user's guide is the new home of the *Inter-Processor
Communication (IPC) User's Guide*
(`SPRUGO6 <http://www.ti.com/lit/pdf/sprugo6>`__). That PDF-based
document will no longer be updated.
        
.. |ipcCfg_Img| Image:: ../images/Book_cfg.png

.. |ipcRun_Img| Image:: ../images/Book_run.png

This user's guide contains the topics in the following list. It also
links to API reference documentation for static configuration (|ipcCfg_Img|)
and run-time C processing (|ipcRun_Img|) for each module.

-  `About IPC <http://processors.wiki.ti.com/index.php/IPC_Users_Guide/About_IPC>`__ provides an
   overview of the IPC component.

   -  `Use Cases for IPC <http://processors.wiki.ti.com/index.php/IPC_Users_Guide/Use_Cases_for_IPC>`__

-  `The ti.sdo.ipc
   Package <http://processors.wiki.ti.com/index.php/IPC_Users_Guide/The_ti.sdo.ipc_Package>`__
   describes the modules in the ti.sdo.ipc package.

.. |ipcWiki_Img1| Image:: ../images/Book_wiki.png
                 :target: http://processors.wiki.ti.com/index.php/IPC_Users_Guide/Ipc_Module

.. |ipcCfg_Img1| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img1| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_ipc_8h.html


.. |ipcWiki_Img2| Image:: ../images/Book_wiki.png
                 :target: http://processors.wiki.ti.com/index.php/IPC_Users_Guide/MessageQ_Module

.. |ipcCfg_Img2| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img2| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_message_q_8h.html


.. |ipcWiki_Img3| Image:: ../images/Book_wiki.png
                 :target: http://processors.wiki.ti.com/index.php/IPC_User%27s_Guide/ListMP_Module

.. |ipcCfg_Img3| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img3| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_list_m_p_8h.html


.. |ipcWiki_Img4| Image:: ../images/Book_wiki.png
                 :target: http://processors.wiki.ti.com/index.php/IPC_Users_Guide/HeapMP_Modules

.. |ipcCfg_Img4| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img4a| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_heap_buf_m_p_8h.html

.. |ipcRun_Img4b| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_heap_mem_m_p_8h.html

.. |ipcRun_Img4c| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_heap_multi_buf_m_p_8h.html


.. |ipcWiki_Img5| Image:: ../images/Book_wiki.png
                 :target: http://processors.wiki.ti.com/index.php/IPC_Users_Guide/GateMP_Module

.. |ipcCfg_Img5| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img5| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_gate_m_p_8h.html


.. |ipcWiki_Img6| Image:: ../images/Book_wiki.png
                 :target: http://processors.wiki.ti.com/index.php/IPC_Users_Guide/Notify_Module

.. |ipcCfg_Img6| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img6| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_notify_8h.html


.. |ipcWiki_Img7| Image:: ../images/Book_wiki.png
                 :target: http://processors.wiki.ti.com/index.php/IPC_Users_Guide/SharedRegion_Module

.. |ipcCfg_Img7| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img7| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_shared_region_8h.html
|

   +-------------------------+----------------+---------------+---------------+
   |         Module          |    Wiki doc    |   Config API  |     C API     |
   +=========================+================+===============+===============+
   |**Ipc Module**           | |ipcWiki_Img1| | |ipcCfg_Img1| | |ipcRun_Img1| |
   +-------------------------+----------------+---------------+---------------+
   |**MessageQ Module**      | |ipcWiki_Img2| | |ipcCfg_Img2| | |ipcRun_Img2| |
   +-------------------------+----------------+---------------+---------------+
   |**ListMP Module**        | |ipcWiki_Img3| | |ipcCfg_Img3| | |ipcRun_Img3| |
   |(BIOS only)              |                |               |               |
   +-------------------------+----------------+---------------+---------------+
   |**HeapMP Modules**       | |ipcWiki_Img4| | |ipcCfg_Img4| | |ipcRun_Img4a||
   |(BIOS only)              |                |               | |ipcRun_Img4b||
   |                         |                |               | |ipcRun_Img4c||
   +-------------------------+----------------+---------------+---------------+
   |**GateMP Module**        | |ipcWiki_Img5| | |ipcCfg_Img5| | |ipcRun_Img5| |
   +-------------------------+----------------+---------------+---------------+
   |**Notify Module**        | |ipcWiki_Img6| | |ipcCfg_Img6| | |ipcRun_Img6| |
   |(BIOS only)              |                |               |               |
   +-------------------------+----------------+---------------+---------------+
   |**SharedRegion Module**  | |ipcWiki_Img7| | |ipcCfg_Img7| | |ipcRun_Img7| |
   |(BIOS only)              |                |               |               |
   +-------------------------+----------------+---------------+---------------+
   

-  `The ti.sdo.utils
   Package <http://processors.wiki.ti.com/index.php/IPC_Users_Guide/The_ti.sdo.utils_Package>`__
   describes the modules in the ti.sdo.utils package.

.. |ipcWiki_Img8| Image:: ../images/Book_wiki.png
                 :target: http://processors.wiki.ti.com/index.php/IPC_Users_Guide/List_Module

.. |ipcCfg_Img8| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img8| Image:: ../images/Book_run.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/syslink/latest/docs/html/_list_8h.html

.. |ipcWiki_Img9| Image:: ../images/Book_wiki.png
                 :target: http://processors.wiki.ti.com/index.php/IPC_Users_Guide/MultiProc_Module

.. |ipcCfg_Img9| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img9| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_multi_proc_8h.html 

.. |ipcWiki_Img10| Image:: ../images/Book_wiki.png
                 :target: http://processors.wiki.ti.com/index.php/IPC_Users_Guide/NameServer_Module

.. |ipcCfg_Img10| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img10| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_shared_region_8h.html

|

   +-------------------------+----------------+---------------+---------------+
   |         Module          |    Wiki doc    |   Config API  |     C API     |
   +=========================+================+===============+===============+
   |**List Module**          | |ipcWiki_Img8| | |ipcCfg_Img8| | |ipcRun_Img8| |
   |(BIOS only)              |                |               |               |
   +-------------------------+----------------+---------------+---------------+
   |**MultiProc Module**     | |ipcWiki_Img9| | |ipcCfg_Img9| | |ipcRun_Img9| |
   +-------------------------+----------------+---------------+---------------+
   |**NameServer Module**    | |ipcWiki_Img10|| |ipcCfg_Img10|| |ipcRun_Img10||
   +-------------------------+----------------+---------------+---------------+
|

-  `Porting IPC <http://processors.wiki.ti.com/index.php/IPC_Users_Guide/Porting_IPC>`__ provides
   an overview of the steps required to port IPC to new devices or
   systems.
-  `Optimizing IPC
   Applications <http://processors.wiki.ti.com/index.php/IPC_Users_Guide/Optimizing_IPC_Applications>`__
   provides hints for improving the runtime performance and shared
   memory usage of applications that use IPC.
-  `Rebuilding IPC <http://processors.wiki.ti.com/index.php/IPC_Users_Guide/Rebuilding_IPC>`__
   explains how to rebuild the IPC libraries if you modify the source
   files.
-  `Using IPC on Concerto
   Devices <http://processors.wiki.ti.com/index.php/IPC_Users_Guide/Using_IPC_on_Concerto_Devices>`__
   explains how to use IPC if you are designing applications for
   Concerto F28M35x devices.
-  `Examples <http://processors.wiki.ti.com/index.php/IPC_Users_Guide/Examples>`__ explains how
   to build and generate the IPC examples.
-  `Tests <http://processors.wiki.ti.com/index.php/IPC_Users_Guide/Tests>`__ explains details of
   unit tests part of IPC
-  `RTOS IPC
   Transports <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_IPC_Transports>`__
   explains details of the additional RTOS IPC transports provided via
   the Processor SDK PDK component.

.. rubric:: Other TI IPC related links for Host Running Linux
   :name: other-ti-ipc-related-links-for-host-running-linux

-  `IPC Custom
   ResourceTable <http://processors.wiki.ti.com/index.php/IPC_Resource_customTable>`__
   Provides details of customizing the resource table.
-  `IPC GateMP Support for UIO and Misc
   Driver <http://processors.wiki.ti.com/index.php/IPC_GateMP_Support_for_UIO_and_Misc_Driver>`__
   Provides details of IPC GateMP support with UIO driver
-  `Early Boot and Late
   Attach <http://processors.wiki.ti.com/index.php/Early_Boot_and_Late_Attach>`__
   Provides details of Early Boot and Late Attach
-  `Early Boot and Late Attach in
   Linux <http://processors.wiki.ti.com/index.php/Early_Boot_and_Late_Attach_in_Linux>`__
   Provides details of Early Boot and Late Attach in Linux
-  `IPC
   Daemon <http://processors.wiki.ti.com/index.php/IPC_Daemon>`__
   Provides details of IPC Daemon

.. rubric:: Other TI IPC useful links
   :name: other-ti-ipc-useful-links

-  `IPC 3.x <http://processors.wiki.ti.com/index.php/IPC_3.x>`__
   Provides details of IPC 3.x releases
-  `IPC 3.x Migration
   Guide <http://processors.wiki.ti.com/index.php/IPC_3.x_Migration_Guide>`__
   Provides details of migrating to IPC 3.x from previous releases
-  `IPC 3.x
   FAQ <http://processors.wiki.ti.com/index.php/IPC_3.x_FAQ>`__
   Frequently asked question on IPC 3.x
-  `IPC
   Benchmarking <http://processors.wiki.ti.com/index.php/IPC_BenchMarking>`__
   IPC Benchmarking with IPC 3.x

.. rubric:: IPC Install Guides
   :name: ipc-install-guides

-  `IPC Install Guide
   Linux <http://processors.wiki.ti.com/index.php/IPC_Install_Guide_Linux>`__
-  `IPC Install Guide
   Android <http://processors.wiki.ti.com/index.php/IPC_Install_Guide_Android>`__
-  `IPC Install Guide
   QNX <http://processors.wiki.ti.com/index.php/IPC_Install_Guide_QNX>`__
-  `IPC Install Guide
   BIOS <http://processors.wiki.ti.com/index.php/IPC_Install_Guide_BIOS>`__

| 

.. note::
   Please see the release notes in your IPC installation before starting to
   use IPC. The release notes contain important information about feature
   support, issues, and compatibility information for a particular release.

| 

.. raw:: html

