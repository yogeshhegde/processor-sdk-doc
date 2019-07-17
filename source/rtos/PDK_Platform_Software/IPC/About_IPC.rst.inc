.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide/About_IPC 

IPC is a set of modules designed to facilitate inter-process communication. It contains packages designed to allow communication between processors in a multi-processor environment and facilitates communication to peripherals. This communication includes message passing, streams, and linked lists. These work transparently in both uni-processor and multi-processor configurations.

IPC is designed for use on processors running SYS/BIOS applications. This is typically a DSP, but may be an ARM device in some cases. Previous versions of SYS/BIOS were called DSP/BIOS. The new name reflects that this operating system can also be use on processors other than DSPs.

IPC can be used to communicate with the following:

- other threads on the same processor
- threads on other processors running SYS/BIOS
- threads on GPP processors running a High-Level Operating System (HLOS)

.. image:: ../images/IpcUG_over_1_1_1.png

IPC was designed with the needs of a wide variety of users in mind. 
In the interest of providing modules that are usable by all groups, 
the IPC modules are designed to limit the API actions to the basic functionality required. 
For example, they do not perform their own resource management. 
It is the responsibility of the calling thread to manage resources and similar issues that 
are not managed by the IPC modules.

|

Requirements
---------------

.. image:: ../images/Download_button.jpg
   :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/index.html

IPC can be used on Windows and Linux-based hosts. IPC builds upon other
software components and tools, which must be installed in order to use
IPC. See the IPC Release Notes for specific versions required by your
particular IPC release. These dependencies are often provided by an SDK
and/or CCS release.

For more information about installing IPC and getting started, select an
appropriate Install Guide:

-  `IPC Install Guide BIOS <index_Foundational_Components.html#bios-install-guide>`__ (for
   homogeneous and heterogeneous all-BIOS environments)
-  `IPC Install Guide Linux <index_Foundational_Components.html#linux-install-guide>`__ (for
   heterogeneous Linux+BIOS environments)
-  `IPC Install Guide QNX <index_Foundational_Components.html#qnx-install-guide>`__ (for
   heterogeneous QNX + BIOS environments)

Related Documents
------------------

API documentation for IPC is provided in two different systems--one for
configuration APIs and the other for run-time C APIs.

.. |ipcAbout_cfg_Img1| Image:: ../images/Book_cfg.png
                      :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

- |ipcAbout_cfg_Img1| 
   **Configuration APIs** are documented in the IPC online CDOC
   documentation (also called "CDOC"?). In this user's guide, you can
   click the icon shown to the left to open the latest configuration
   documentation for a particular IPC module. You can also view CDOC in
   the CCS online help or by running
   ``<ipc_install_dir>/docs/cdoc/index.html`` in your IPC installation.
   CDOC provides information about static configuration of IPC modules
   and objects.

.. note::
   Do not use the CDOC help system to look for information about C
   runtime APIs in the ti.ipc package. Use the Doxygen-based help for C
   runtime APIs.


.. |ipcAbout_run_Img1| image:: ../images/Book_run.png
   :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/index.html

- |ipcAbout_run_Img1|
   **C APIs** are documented via Doxygen. In this user's guide, you can
   click the icon shown to the left to open the latest C API
   documentation for a particular IPC module. You can also view the C
   API documentation in your IPC installation at
   ``<ipc_install_dir>/docs/doxygen/html/index.html``. This help system
   does not contain information about static configuration. Use the C
   API documentation for information about the following aspects of IPC:

   -  Runtime APIs
   -  Status codes
   -  Instance creation parameters
   -  Type definitions

The following additional documentation is available for components used
with IPC.

-  `RTSC-Pedia Wiki: <http://rtsc.eclipse.org/docs-tip>`__
-  `Texas Instruments Developer Wiki <index.html#processor-sdk-rtos-software-developer-s-guide>`__
-  *SYS/BIOS 6 Release Notes:*
   ``BIOS_INSTALL_DIR/Bios_6_##_release_notes.html``
-  *SYS/BIOS 6 Getting Started Guide:*
   ``BIOS_INSTALL_DIR/docs/Bios_Getting_Started_Guide.pdf``
-  *XDCtools and SYS/BIOS online help:* Open with CCS online help.
-  *TMS320 SYS/BIOS 6 User's Guide*
   (`SPRUEX3 <http://www.ti.com/lit/pdf/spruex3>`__)

| 

.. raw:: html

