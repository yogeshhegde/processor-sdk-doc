.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide/Examples

Overview
---------

The IPC product contains an examples/archive directory with device-specific examples. 
Once identifying your device, the examples can be unzipped anywhere on your build host. 
Typically once unzipped, the user edits the example's individual **products.mak** file and simply invokes **make**.

.. note::
  A common place to unzip the examples is into the **IPC_INSTALL_DIR/examples/** directory. 
  Each example's **products.mak** file is smart enough to look up two directories (in this case, into **IPC_INSTALL_DIR**) 
  for a master **products.mak** file, and if found it uses those variables. 
  This technique enables users to set the dependency variables in one place, namely **IPC_INSTALL_DIR/products.mak**.

Each example contains a **readme.txt** with example-specific details.

Generating Examples
-----------------------

The IPC product will come with the generated examples directory. 
The IPC product is what is typically delivered with SDKs such as Processor SDK. 
However, some SDKs point directly to the IPC git tree for the IPC source. 
In this case, the IPC Examples can be generated separately.

Tools
------

The following tools need to be installed:
 - `XDC tools <http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/rtsc/>`__(check the IPC release notes for compatible version)

Source Code
----------------

::
  
  mkdir ipc
  cd ipc
  git clone git://git.ti.com/ipc/ipc-metadata.git
  git clone git://git.ti.com/ipc/ipc-examples.git

Then checkout the IPC release tag that is associated with the IPC version being used. Do this for both repos. For example:

::
  
  git checkout 3.42.01.03

Build
-------

::
  
  cd ipc-examples/src
  make .examples XDC_INSTALL_DIR=<path_to_xdc_tools> IPCTOOLS=<path_to_ipc-metadata>/src/etc

For example:
::
  
  make .examples XDC_INSTALL_DIR=/opt/ti/xdctools_3_32_00_06_core IPCTOOLS=/home/user/ipc/ipc-metadata/src/etc

The "examples" director will be generated in the path "ipc-examples/src/":
::
  
  ipc-examples/src/examples

IPC examples: Details
----------------------

This section explains some of the common details about IPC examples.
The sub-directories under the examples are organised into the code for each of the cores in the SOC.
For example
|-Host
|-DSP1
|-DSP2
|-IPU1
|-IPU2

Typically we have a host core which is the main core in the SOC and other slave cores. 
The directory name of the slave cores have a base name (like DSP, IPU etc) which indicates the type of core and a core number.
Depending on the example, the Host can run TI BIOS or Linux or QNX and the slave cores in general run TI BIOS only. 
So the specific build related files need to be interpreted accordingly.

BIOS Application configuration files
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
The cores running BIOS in general has a config file which brings in all the modules needed to complete the application running on the specific core.
This section explains the details of the entries in the config file.
Note: The details here are just representative of a typical configuration. In general the configuration is customized based on the particular example.

Bios configuration
"""""""""""""""""""
The following configuration are related to configuring BIOS
::
  
   var BIOS        = xdc.useModule('ti.sysbios.BIOS');
   /*  This adds ipc Startup to be done part of BIOS  startup before main*/
   BIOS.addUserStartupFunction('&IpcMgr_ipcStartup');
   
   /* The following configures Debug libtype with Debug build */
   if (Program.build.profile == "debug") {
        BIOS.libType = BIOS.LibType_Debug;
   } else {
       BIOS.libType = BIOS.LibType_Custom;
   }
   
   var Sem = xdc.useModule('ti.sysbios.knl.Semaphore');
   var instSem0_Params = new Sem.Params();
   instSem0_Params.mode = Sem.Mode_BINARY;
   Program.global.runOmpSem = Sem.create(0, instSem0_Params);
   Program.global.runOmpSem_complete = Sem.create(0, instSem0_Params);
   
   var Task = xdc.useModule('ti.sysbios.knl.Task');
   Task.common$.namedInstance = true;
   
   /* default memory heap */
   var Memory = xdc.useModule('xdc.runtime.Memory');
   var HeapMem = xdc.useModule('ti.sysbios.heaps.HeapMem');
   var heapMemParams = new HeapMem.Params();
   heapMemParams.size = 0x8000;
   Memory.defaultHeapInstance = HeapMem.create(heapMemParams);
   
   /* create a heap for MessageQ messages */
   var HeapBuf = xdc.useModule('ti.sysbios.heaps.HeapBuf');
   var params = new HeapBuf.Params;
   params.align = 8;
   params.blockSize = 512;
   params.numBlocks = 20;

XDC runtime
"""""""""""""
The following configuration are in general used by an IPC application in BIOS
::
  
   /* application uses the following modules and packages */
   xdc.useModule('xdc.runtime.Assert');
   xdc.useModule('xdc.runtime.Diags');
   xdc.useModule('xdc.runtime.Error');
   xdc.useModule('xdc.runtime.Log');
   xdc.useModule('xdc.runtime.Registry');
   
   xdc.useModule('ti.sysbios.knl.Semaphore');
   xdc.useModule('ti.sysbios.knl.Task');

IPC configuration
""""""""""""""""""
The following IPC modules are used in a typical IPC application.
::
  
   xdc.useModule('ti.sdo.ipc.Ipc');
   xdc.useModule('ti.ipc.ipcmgr.IpcMgr');
   var MultiProc = xdc.useModule('ti.sdo.utils.MultiProc');
   /* The following configures the PROC List */
   MultiProc.setConfig("CORE0", ["HOST", "CORE0"]);
   
   var msgHeap = HeapBuf.create(params);
   
   var MessageQ  = xdc.useModule('ti.sdo.ipc.MessageQ');
   /* Register msgHeap with messageQ */
   MessageQ.registerHeapMeta(msgHeap, 0);

The following lines configure placement of Resource table in memory.
Note that some platforms or applications the placement of memory can be in a different section in the memory map.
::
  
   /* Enable Memory Translation module that operates on the Resource Table */
   var Resource = xdc.useModule('ti.ipc.remoteproc.Resource');
   Resource.loadSegment = Program.platform.dataMemory;

Transport configuration
""""""""""""""""""""""""
Typically the transport to be used by IPC is specified here. The following snippet configures RPMsg based transport.
::
  
   /* Setup MessageQ transport */
   var VirtioSetup = xdc.useModule('ti.ipc.transports.TransportRpmsgSetup');
   MessageQ.SetupTransportProxy = VirtioSetup;

NameServer configuration
""""""""""""""""""""""""""
The Name server to be used is specified here.
::
  
   /* Setup NameServer remote proxy */
   var NameServer = xdc.useModule("ti.sdo.utils.NameServer");
   var NsRemote = xdc.useModule("ti.ipc.namesrv.NameServerRemoteRpmsg");
   NameServer.SetupProxy = NsRemote;


Instrumentation Configuration
""""""""""""""""""""""""""""""
The following configuration are required for system logging and diagnostics.
::
  
     /* system logger */
   var LoggerSys = xdc.useModule('xdc.runtime.LoggerSys');
   var LoggerSysParams = new LoggerSys.Params();
   var Defaults = xdc.useModule('xdc.runtime.Defaults');
   Defaults.common$.logger = LoggerSys.create(LoggerSysParams);
   
   /* enable runtime Diags_setMask() for non-XDC spec'd modules */
   var Diags = xdc.useModule('xdc.runtime.Diags');
   Diags.setMaskEnabled = true;
   
   /* override diags mask for selected modules */
   xdc.useModule('xdc.runtime.Main');
   Diags.setMaskMeta("xdc.runtime.Main",
       Diags.ENTRY | Diags.EXIT | Diags.INFO, Diags.RUNTIME_ON);
   
   var Registry = xdc.useModule('xdc.runtime.Registry');
   Registry.common$.diags_ENTRY = Diags.RUNTIME_OFF;
   Registry.common$.diags_EXIT  = Diags.RUNTIME_OFF;
   Registry.common$.diags_INFO  = Diags.RUNTIME_OFF;
   Registry.common$.diags_USER1 = Diags.RUNTIME_OFF;
   Registry.common$.diags_LIFECYCLE = Diags.RUNTIME_OFF;
   Registry.common$.diags_STATUS = Diags.RUNTIME_OFF;
   
   var Main = xdc.useModule('xdc.runtime.Main');
   Main.common$.diags_ASSERT = Diags.ALWAYS_ON;
   Main.common$.diags_INTERNAL = Diags.ALWAYS_ON;

Other optional configurations
""""""""""""""""""""""""""""""
In addition to the above configurations there are other platform specific configurations may be used to enable certain features.

For example the following sections shows the sections used to enable device exception handler. ( But the deh module may not be available on all devices)
::
  
   var Idle = xdc.useModule('ti.sysbios.knl.Idle');
   var Deh = xdc.useModule('ti.deh.Deh');
   
   /* Must be placed before pwr mgmt */
   Idle.addFunc('&ti_deh_Deh_idleBegin');


