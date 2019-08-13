.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide 

Inter-Processor Communication (IPC) provides a processor-agnostic API which can be used for communication between processors in a multi-processor environment (inter-core), communication to other threads on same processor (inter-process), and communication to peripherals (inter-device). 
The API supports message passing, streams, and linked lists.
IPC can be used to communicate with the following:

- Other threads on the same processor
- Threads on other processors running SYS/BIOS
- Threads on other processors running an HLOS (e.g., Linux, QNX, Android)

.. image:: ../images/IPC_comm_features.JPG

About this User's Guide
------------------------

This user's guide is the new home of the *Inter-Processor
Communication (IPC) User's Guide*
(`SPRUGO6 <http://www.ti.com/lit/pdf/sprugo6>`__). That PDF-based
document will no longer be updated.
        
.. |ipcCfg_Img| Image::  ../images/Book_cfg.png
               :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img| Image::  ../images/Book_run.png
               :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/index.html


This user's guide contains the topics in the following list. It also
links to API reference documentation for static configuration (|ipcCfg_Img|)
and run-time C processing (|ipcRun_Img|) for each module.

-  `About IPC <index_Foundational_Components.html#about-ipc>`__ provides an
   overview of the IPC component.

   -  `Use Cases for IPC <index_Foundational_Components.html#use-cases-for-ipc>`__

-  `The ti.sdo.ipc
   Package <index_Foundational_Components.html#ti-sdo-ipc-package>`__
   describes the modules in the ti.sdo.ipc package.

.. |ipcWiki_Img1| Image:: ../images/Book_wiki.png
                 :target: index_Foundational_Components.html#ipc-module

.. |ipcCfg_Img1| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img1| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_ipc_8h.html


.. |ipcWiki_Img2| Image:: ../images/Book_wiki.png
                 :target: index_Foundational_Components.html#messageq-module

.. |ipcCfg_Img2| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img2| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_message_q_8h.html


.. |ipcWiki_Img3| Image:: ../images/Book_wiki.png
                 :target: index_Foundational_Components.html#listmp-module

.. |ipcCfg_Img3| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img3| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_list_m_p_8h.html


.. |ipcWiki_Img4| Image:: ../images/Book_wiki.png
                 :target: index_Foundational_Components.html#heapmp-module

.. |ipcCfg_Img4| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img4a| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_heap_buf_m_p_8h.html

.. |ipcRun_Img4b| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_heap_mem_m_p_8h.html

.. |ipcRun_Img4c| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_heap_multi_buf_m_p_8h.html


.. |ipcWiki_Img5| Image:: ../images/Book_wiki.png
                 :target: index_Foundational_Components.html#gatemp-module

.. |ipcCfg_Img5| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img5| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_gate_m_p_8h.html


.. |ipcWiki_Img6| Image:: ../images/Book_wiki.png
                 :target: index_Foundational_Components.html#notify-module

.. |ipcCfg_Img6| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img6| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_notify_8h.html


.. |ipcWiki_Img7| Image:: ../images/Book_wiki.png
                 :target: index_Foundational_Components.html#shared-region-module

.. |ipcCfg_Img7| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img7| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_shared_region_8h.html

|

   +-------------------------+----------------+---------------+---------------+
   |         Module          |      doc       |   Config API  |     C API     |
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
   Package <index_Foundational_Components.html#ti-sdo-utils-package>`__
   describes the modules in the ti.sdo.utils package.

.. |ipcWiki_Img8| Image:: ../images/Book_wiki.png
                 :target: index_Foundational_Components.html#list-module 

.. |ipcCfg_Img8| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img8| Image:: ../images/Book_run.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/syslink/latest/docs/html/_list_8h.html

.. |ipcWiki_Img9| Image:: ../images/Book_wiki.png
                 :target: index_Foundational_Components.html#multiproc-module

.. |ipcCfg_Img9| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img9| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_multi_proc_8h.html 

.. |ipcWiki_Img10| Image:: ../images/Book_wiki.png
                 :target: index_Foundational_Components.html#nameserver-module

.. |ipcCfg_Img10| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |ipcRun_Img10| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_shared_region_8h.html

|

   +-------------------------+----------------+---------------+---------------+
   |         Module          |      doc       |   Config API  |     C API     |
   +=========================+================+===============+===============+
   |**List Module**          | |ipcWiki_Img8| | |ipcCfg_Img8| | |ipcRun_Img8| |
   |(BIOS only)              |                |               |               |
   +-------------------------+----------------+---------------+---------------+
   |**MultiProc Module**     | |ipcWiki_Img9| | |ipcCfg_Img9| | |ipcRun_Img9| |
   +-------------------------+----------------+---------------+---------------+
   |**NameServer Module**    | |ipcWiki_Img10|| |ipcCfg_Img10|| |ipcRun_Img10||
   +-------------------------+----------------+---------------+---------------+

|

-  `Porting IPC <index_Foundational_Components.html#porting-ipc>`__ provides
   an overview of the steps required to port IPC to new devices or
   systems.
-  `Optimizing IPC
   Applications <index_Foundational_Components.html#optimizing-ipc-applications>`__
   provides hints for improving the runtime performance and shared
   memory usage of applications that use IPC.
-  `Rebuilding IPC <index_Foundational_Components.html#rebuilding-ipc>`__
   explains how to rebuild the IPC libraries if you modify the source
   files.
-  `Examples <index_Foundational_Components.html#ipc-examples>`__ explains how
   to build and generate the IPC examples.
-  `Tests <index_Foundational_Components.html#ipc-tests>`__ explains details of
   unit tests part of IPC
-  `RTOS IPC
   Transports <index_Foundational_Components.html#ipc-transports>`__
   explains details of the additional RTOS IPC transports provided via
   the Processor SDK PDK component.

Other TI IPC related links for Host Running Linux
--------------------------------------------------

-  `IPC Custom
   ResourceTable <index_Foundational_Components.html#resource-custom-table>`__
   Provides details of customizing the resource table.
-  `IPC GateMP Support for UIO and Misc
   Driver <index_Foundational_Components.html#gatemp-support-for-uio-and-misc-driver>`__
   Provides details of IPC GateMP support with UIO driver
-  `Early Boot and Late
   Attach <http://processors.wiki.ti.com/index.php/Early_Boot_and_Late_Attach>`__
   Provides details of Early Boot and Late Attach
-  `Early Boot and Late Attach in
   Linux <http://processors.wiki.ti.com/index.php/Early_Boot_and_Late_Attach_in_Linux>`__
   Provides details of Early Boot and Late Attach in Linux
-  `IPC
   Daemon <index_Foundational_Components.html#ipc-daemon>`__
   Provides details of IPC Daemon

Other TI IPC useful links
--------------------------

-  `IPC 3.x <index_Foundational_Components.html#ipc-3-x>`__
   Provides details of IPC 3.x releases
-  `IPC 3.x Migration
   Guide <http://processors.wiki.ti.com/index.php/IPC_3.x_Migration_Guide>`__
   Provides details of migrating to IPC 3.x from previous releases
-  `IPC 3.x
   FAQ <index_Foundational_Components.html#ipc-faq>`__
   Frequently asked question on IPC 3.x
-  `IPC
   Benchmarking <index_Foundational_Components.html#ipc-benchmarking>`__
   IPC Benchmarking with IPC 3.x

IPC Install Guides
---------------------

-  `IPC Install Guide
   Linux <index_Foundational_Components.html#linux-install-guide>`__
-  `IPC Install Guide
   QNX <index_Foundational_Components.html#qnx-install-guide>`__
-  `IPC Install Guide BIOS <index_Foundational_Components.html#bios-install-guide>`__

| 

.. note::
   Please see the release notes in your IPC installation before starting to
   use IPC. The release notes contain important information about feature
   support, issues, and compatibility information for a particular release.

| 


