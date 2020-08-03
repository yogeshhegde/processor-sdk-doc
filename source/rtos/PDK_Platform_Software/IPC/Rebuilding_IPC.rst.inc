.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide/Rebuilding_IPC 

This page describes how to rebuild the IPC source code.

The IPC product includes source files and build scripts that allow you to modify the IPC sources and rebuild its libraries. You can do this in order to modify, update, or add functionality. If you edit the IPC source code and/or corresponding build scripts, you must also rebuild IPC in order to create new libraries containing these modifications.

Note that you can cause the BIOS-side IPC (and BIOS) libraries to be rebuilt as part of the application build - this is called a 'Custom Build'. The custom-built libraries will be stored with other output from executing your config script, and will contain only modules and APIs that your application needs to access. You can cause such a Custom Build to occur using the BIOS.libType config param as follows.

.. code:: c

   var BIOS = xdc.useModule('ti.sysbios.BIOS');
   BIOS.libType = BIOS.LibType_Custom;

.. note:: This page provides details about rebuilding the IPC source code. We strongly recommend that you copy the IPC installation to a directory with a different name and rebuild that copy, rather than rebuilding the original installation.

Build Procedure
------------------

The IPC package now comes bundled with Processor SDK RTOS and can be rebuilt using the top-level makefile located in the Processor SDK RTOS folder. The following commands will build the BIOS-side IPC package. 

Windows
::

    cd (Processor SDK RTOS folder)
    setupenv.bat
    gmake ipc_bios

Linux
::

    cd (Processor SDK RTOS folder)
    source ./setupenv.sh
    make ipc_bios
	
The IPC package can also be cleaned using the following commands.

Windows
::

    cd (Processor SDK RTOS folder)
	setupenv.bat
	gmake ipc_clean

Linux
::

	cd (Processor SDK RTOS folder)
	source ./setupenv.sh
	make ipc_clean
	
The install guides below have been kept here for those using older, legacy versions of IPC outside of Processor SDK. 

The various IPC Install Guides describe the mechanics of rebuilding IPC
libraries. Please consult the Install Guide appropriate for your
environment.

-  `IPC Install Guide BIOS <index_Foundational_Components.html#bios-install-guide>`__ - for
   all-BIOS environments
-  `IPC Install Guide Linux <index_Foundational_Components.html#linux-install-guide>`__ -
   for environments with a combination of Linux and BIOS
-  `IPC Install Guide QNX <index_Foundational_Components.html#qnx-install-guide>`__ - for
   environments with a combination of QNX and BIOS

Pointing a CCS Project at a Rebuilt IPC
----------------------------------------

To build your application using the version of IPC you have rebuilt, you
must point your project to this rebuilt version by following these
steps:

#. Open CCS and select the application project you want to rebuild.
#. Right-click on your project and choose **Build Properties**. If you
   have a configuration project that is separate from your application
   project, open the build properties for the configuration project.
#. In the **CCS Build** category of the Properties dialog, choose the
   **RTSC** tab.
#. Under the **Products and Repositories** tab, uncheck *all* the boxes
   for IPC. This ensures that no version is selected.

   .. image:: /images/Rebuild_deselect.png

#. Click the **Add** button next to the **Products and Repositories**
   tab.
#. Choose **Select repository from file-system**, and browse to the
   "packages" directory of the location where you copied and rebuilt
   IPC. For example, the location may be
   C:\myIpcBuilds\custom_ipc_1_22_##-##\packages.

   .. image:: /images/Rebuild_addrep.png

#. Click **OK** to apply these changes to the project.
#. You may now rebuild your project using the re-built version of IPC.

| 

