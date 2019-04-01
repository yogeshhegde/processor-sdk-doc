.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide/Rebuilding_IPC 

Build Procedure
------------------

The various IPC Install Guides describe the mechanics of rebuilding IPC
libraries. Please consult the Install Guide appropriate for your
environment.

-  `IPC Install Guide BIOS </index.php/IPC_Install_Guide_BIOS>`__ - for
   all-BIOS environments
-  `IPC Install Guide Linux </index.php/IPC_Install_Guide_Linux>`__ -
   for environments with a combination of Linux and BIOS
-  `IPC Install Guide QNX </index.php/IPC_Install_Guide_QNX>`__ - for
   environments with a combination of QNX and BIOS
-  `IPC Install Guide Android </index.php/IPC_Install_Guide_Android>`__
   - for environments with a combination of Android and BIOS

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

.. image:: ../images/Rebuild_deselect.png

#. Click the **Add** button next to the **Products and Repositories**
   tab.
#. Choose **Select repository from file-system**, and browse to the
   "packages" directory of the location where you copied and rebuilt
   IPC. For example, the location may be
   C:\myIpcBuilds\custom_ipc_1_22_##-##\packages.

.. image:: ../images/Rebuild_addrep.png

#. Click **OK** to apply these changes to the project.
#. You may now rebuild your project using the re-built version of IPC.

| 

.. raw:: html

