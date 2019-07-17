.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide/Ipc_Module 

.. |ipcCfg_Ipc_Img1| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/index.html#ti/sdo/ipc/Ipc.html

.. |ipcCfg_Ipc_Img2| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

                 
.. |ipcRun_Ipc_Img1| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_ipc_8h.html

.. |ipcRun_Ipc_Img2| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_ipc_8h.html

| 

   +-------------------+-------------------+
   |         API Reference Links           |
   +===================+===================+
   | |ipcCfg_Ipc_Img1| | |ipcRun_Ipc_Img1| |
   +-------------------+-------------------+

The main purpose of the Ipc module is to initialize the various subsystems of IPC. All applications that use IPC modules must call the Ipc_start() API, which does the following:

- Initializes a number of objects and modules used by IPC
- Synchronizes multiple processors so they can boot in any order

An application that uses IPC APIs--such as MessageQ--must include the Ipc module header file and call Ipc_start() 
before any calls to IPC modules. Here is a BIOS-side example:

::
  
    #include <ti/ipc/Ipc.h>
  
  int main(int argc, char* argv[])
 {
      Int status;
  
      /* Call Ipc_start() */
     status = Ipc_start();
      if (status < 0) {
         System_abort("Ipc_start failed\n");
      }
    
     BIOS_start();
      return (0);
 }
|

By default, the BIOS implementation of Ipc_start() internally calls Notify_start() if it has not already been called, 
then loops through the defined SharedRegions so that it can set up the HeapMemMP and GateMP instances used internally by the IPC modules. 
It also sets up MessageQ transports to remote processors.

The SharedRegion with an index of 0 (zero) is often used by BIOS-side IPC_start() to create resource management tables 
for internal use by other IPC modules. Thus SharedRegion "0" must be accessible by all processors. 
See SharedRegion Module for more about the SharedRegion module.

.. note:
   The Ipc module is not used on Concerto F28M35x devices. 
   Instead, the IpcMgr module (in the ti.sdo.ipc.family.f28m35x package) is used to configure 
   the devices as described in Using IPC on Concerto Devices. 
   Concerto applications should not call any Ipc or IpcMgr APIs at runtime.

Ipc Module Configuration (BIOS-side only)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
In an XDCtools configuration file, you configure the Ipc module for use as follows:

::
  
  Ipc = xdc.useModule('ti.sdo.ipc.Ipc');


You can configure what the Ipc_start() API will do--which modules it will start and which objects it will create--by using the Ipc.setEntryMeta 
method in the configuration file to set the following properties:

- **setupNotify.** If set to false, the Notify module is not set up. The default is true.
- **setupMessageQ.** If set to false, the MessageQ transport instances to remote processors are not set up and 
  the MessageQ module does not attach to remote processors. The default is true.

For example, the following statements from the notify example configuration turn off the setup of the MessageQ transports and connections to remote processors:

::
  
  /* To avoid wasting shared memory for MessageQ transports */
  for (var i = 0; i < MultiProc.numProcessors; i++) {
      Ipc.setEntryMeta({
          remoteProcId: i,
          setupMessageQ: false,
      });
  }

You can configure how the IPC module synchronizes processors by configuring the Ipc.procSync property. For example:

::
  
  Ipc.procSync = Ipc.ProcSync_ALL;


The options are:

- Ipc.ProcSync_ALL. If you use this option, the Ipc_start() API automatically attaches to and synchronizes all remote processors. 
  If you use this option, your application should never call Ipc_attach(). 
  Use this option if all IPC processors on a device start up at the same time and connections should be established between every possible pair of processors.
- Ipc.ProcSync_PAIR. (Default) If you use this option, you must explicitly call Ipc_attach() to attach to a specific remote processor. 
   If you use this option, Ipc_start() performs system-wide IPC initialization, but does not make connections to remote processors. 
   Use this option if any or all of the following are true:
 - You need to control when synchronization with each remote processor occurs.
 - Useful work can be done while trying to synchronize with a remote processor by yielding a thread after each attempt to Ipc_attach() to the processor.
 - Connections to some remote processors are unnecessary and should be made selectively to save memory.
- Ipc.ProcSync_NONE. If you use this option, Ipc_start() doesn't synchronize any processors before setting up the objects needed by other modules. 
  Use this option with caution. It is intended for use in cases where the application performs its own synchronization and you want to avoid a potential 
  deadlock situation with the IPC synchronization.

  If you use the ProcSync_NONE option, Ipc_start() works exactly as it does with ProcSync_PAIR. :
  However, in this case, Ipc_attach() does not synchronize with the remote processor. 
  As with other ProcSync options, Ipc_attach() still sets up access to GateMP, SharedRegion, 
  Notify, NameServer, and MessageQ transports, so your application must still call Ipc_attach() 
  for each remote processor that will be accessed. Note that an Ipc_attach() call for a remote processor 
  whose ID is less than the local processor's ID must occur after the corresponding remote processor has called Ipc_attach() to the local processor. 
  For example, processor #2 can call Ipc_attach(1) only after processor #1 has called Ipc_attach(2).:

You can configure a function to perform custom actions in addition to the default actions performed when attaching to or detaching from a remote processor. 
These functions run near the end of Ipc_attach() and near the beginning of Ipc_detach(), respectively. 
Such functions must be non-blocking and must run to completion. The following example configures two attach functions and two detach functions. 
Each set of functions will be passed a different argument:

::
  
  var Ipc = xdc.useModule('ti.sdo.ipc.Ipc');
   
  var fxn = new Ipc.UserFxn;
  fxn.attach = '&userAttachFxn1';
  fxn.detach = '&userDetachFxn1';
  Ipc.addUserFxn(fxn, 0x1);
   
  fxn.attach = '&userAttachFxn2';
  fxn.detach = '&userDetachFxn2';
  Ipc.addUserFxn(fxn, 0x2);

|ipcCfg_Ipc_Img2| The latest version of the IPC module configuration documentation is available 
`online <http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html>`_

Ipc Module APIs
^^^^^^^^^^^^^^^^
In addition to the Ipc_start() API, which all applications that use IPC modules are required to call, 
the Ipc module also provides the following APIs for processor synchronization:

- Ipc_attach() Creates a connection to the specified remote processor.
- Ipc_detach() Deletes the connection to the specified remote processor.

You must call Ipc_start() on a processor before calling Ipc_attach().

.. note::
   Call Ipc_attach() to the processor that owns shared memory region 0--usually 
   the processor with an id of 0--before making a connection to any other remote processor. 
   For example, if there are three processors configured with MultiProc, processor 1 should 
   attach to processor 0 before it can attach to processor 2.

Use these functions unless you are using the Ipc.ProcSync_ALL configuration setting. 
With that option, Ipc_start() automatically attaches to and synchronizes all remote processors, 
and your application should never call Ipc_attach().

The Ipc.ProcSync_PAIR configuration option expects that your application will call 
Ipc_attach() for each remote processor with which it should be able to communicate.

.. note::
  In ARM-Linux/DSP-RTOS scenario, Linux application gets the IPC configuration from LAD which has Ipc.ProcSync_ALL configured. 
  DSP has Ipc.ProcSync_PAIR configured.

Processor synchronization means that one processor waits until the other processor signals that a particular module is ready for use. 
Within Ipc_attach(), this is done for the GateMP, SharedRegion (region 0), and Notify modules and the MessageQ transports.

You can call the Ipc_detach() API to delete internal instances created by Ipc_attach() and to free the memory used by these instances.

|ipcRun_Ipc_Img2| The latest version of the IPC module run-time API documentation is available 
`online <http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_ipc_8h.html>`_

.. raw:: html
