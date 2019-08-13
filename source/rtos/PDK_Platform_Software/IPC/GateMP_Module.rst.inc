.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide/GateMP_Module 

.. |gpmCfg_Img1| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

                 
.. |gmpRun_Img1| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_gate_m_p_8h.html

.. |gmpRun_Img2| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_gate_m_p_8h.html

| 

   +---------------+---------------+
   |     API Reference Links       |
   +===============+===============+
   | |gpmCfg_Img1| | |gmpRun_Img1| |
   +---------------+---------------+

A GateMP instance can be used to enforce both local and remote context protection. 
That is, entering a GateMP can prevent preemption by another thread/process running on the 
same processor and simultaneously prevent a remote processor from entering the same gate. 
GateMP's are typically used to protect reads/writes to a shared resource, such as shared memory.
 
.. note::
  Initial IPC 3.x releases only supported GateMP on BIOS. It was introduced on QNX in IPC 3.10, and on Linux/Android in 3.21.

Creating a GateMP Instance
^^^^^^^^^^^^^^^^^^^^^^^^^^^
As with other IPC modules, GateMP instances can only be created dynamically.

Before creating the GateMP instance, you initialize a GateMP_Params structure and set fields in the structure to the desired values. 
You then use the GateMP_create() function to dynamically create a GateMP instance.

When you create a gate, shared memory is initialized, but the GateMP object is created in local memory. Only the gate information resides in shared memory.

The following code creates a GateMP object:

::
  
  GateMP_Params gparams;
  GateMP_Handle gateHandle;
   
  GateMP_Params_init(&gparams);
  gparams.localProtect = GateMP_LocalProtect_THREAD;
  gparams.remoteProtect = GateMP_RemoteProtect_SYSTEM;
  gparams.name = "myGate";
  gparams.regionId = 1;
  gateHandle = GateMP_create(&gparams, NULL);

A gate can be configured to implement remote processor protection in various ways. 
This is done via the params.remoteProtect configuration property. 
The options for params.remoteProtect are as follows:

- GateMP_RemoteProtect_NONE. Creates only the local gate specified by the localProtect property.
- GateMP_RemoteProtect_SYSTEM. Uses the default device-specific gate protection mechanism for your device. 
  Internally, GateMP automatically uses device-specific implementations of multi-processor mutexes implemented via a variety of hardware mechanisms. 
  Devices typically support a single type of system gate, so this is usually the correct configuration setting for params.remoteProtect.
- GateMP_RemoteProtect_CUSTOM1 and GateMP_RemoteProtect_CUSTOM2 (BIOS-only). Some devices support multiple types of system gates. 
  If you know that GateMP has multiple implementations of gates for your device, you can use one of these options.

Several gate implementations used internally for remote protection are provided in the ti.sdo.ipc.gates package.

A gate can be configured to implement local protection at various levels. 
This is done via the params.localProtect configuration property (BIOS-only). 
The options for params.localProtect are as follows:

- GateMP_LocalProtect_NONE. Uses the XDCtools GateNull implementation, which does not offer any local context protection. 
  For example, you might use this option for a single-threaded local application that still needs remote protection.
- GateMP_LocalProtect_INTERRUPT. Uses the SYS/BIOS GateHwi implementation, which disables hardware interrupts.
- GateMP_LocalProtect_TASKLET. Uses the SYS/BIOS GateSwi implementation, which disables software interrupts.
- GateMP_LocalProtect_THREAD. Uses the SYS/BIOS GateMutexPri implementation, which is based on Semaphores. 
  This option may use a different gate than the following option on some operating systems. When using SYS/BIOS, they are equivalent.
- GateMP_LocalProtect_PROCESS. Uses the SYS/BIOS GateMutexPri implementation, which is based on Semaphores.

This property is currently ignored (as of IPC 3.23) on non-BIOS OSes. 
A thread-level mutex is used for local protection independent of this property setting.

Other fields you are required to set in the GateMP_Params structure are:

- name. The name of the GateMP instance.
- regionId. The ID of the SharedRegion to use for shared memory used by this GateMP instance (BIOS-only).

|gmpRun_Img2| The latest version of the GateMP module run-time API documentation is available 
`online <http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_gate_m_p_8h.html>`_

Opening a GateMP Instance
^^^^^^^^^^^^^^^^^^^^^^^^^^
Once an instance is created on a processor, the gate can be opened on another processor to obtain a local handle to the same instance.

The GateMP module uses a NameServer instance to allow a remote processor to address the local GateMP instance using 
a user-configurable string value as an identifier rather than a potentially dynamic address value.

::
  
  status = GateMP_open("myGate", &gateHandle);
  if (status < 0) {
      System_printf("GateMP_open failed\n");
  }

Closing a GateMP Instance
^^^^^^^^^^^^^^^^^^^^^^^^^^
GateMP_close() frees a GateMP object stored in local memory.

GateMP_close() should never be called on an instance whose creator has been deleted.

Deleting a GateMP Instance
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
GateMP_delete() frees a GateMP object stored in local memory and flags the shared memory to indicate that the gate is no longer initialized.

A thread may not use GateMP_delete() if it acquired the handle to the gate using GateMP_open(). Such threads should call GateMP_close() instead.

Entering a GateMP Instance
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Either the GateMP creator or opener may call GateMP_enter() to enter a gate. 
While it is necessary for the opener to wait for a gate to be created to enter a created gate, 
it isn't necessary for a creator to wait for a gate to be opened before entering it.

GateMP_enter() enters the caller's local gate. The local gate (if supplied) blocks if entered on the local processor. 
If entered by the remote processor, GateMP_enter() spins until the remote processor has left the gate.

No matter what the params.localProtection configuration property is set to, after GateMP_enter() returns, 
the caller has exclusive access to the data protected by this gate.

A thread may reenter a gate without blocking or failing.

GateMP_enter() returns a "key" that is used by GateMP_leave() to leave this gate; 
this value is used to restore thread preemption to the state that existed just prior to entering this gate.

::
  
  IArg key;
   
  /* Enter the gate */
  key = GateMP_enter(gateHandle);

Leaving a GateMP Instance
^^^^^^^^^^^^^^^^^^^^^^^^^^
GateMP_leave() may only called by a thread that has previously entered this gate via GateMP_enter().

After this method returns, the caller must not access the data structure 
protected by this gate (unless the caller has entered the gate more than once and other calls to leave remain to balance the number of previous calls to enter).

::
  
  IArg key;
   
  /* Leave the gate */
  GateMP_leave(gateHandle, key);

Querying a GateMP Instance
^^^^^^^^^^^^^^^^^^^^^^^^^^^
GateMP_query() returns TRUE if a gate has a given quality, and FALSE otherwise, including cases when the gate does not recognize the constant describing the quality. The qualities you can query are:

- GateMP_Q_BLOCKING. If GateMP_Q__BLOCKING is FALSE, the gate never blocks.
- GateMP_Q_PREEMPTING. If GateMP_Q_PREEMPTING is FALSE, the gate does not allow other threads to preempt the thread that has already entered the gate.

NameServer Interaction
^^^^^^^^^^^^^^^^^^^^^^^^
The GateMP module uses a ti.sdo.utils.NameServer instance to store instance information when an instance is created and the name parameter is non-NULL. 
The length of this name is limited to 16 characters (by default) including the null terminator ('\0'). 
This length can be increased by configuring the GateMP.maxNameLen module configuration property. 
If a name is supplied, it must be unique for all GateMP instances.

Other modules can use GateMP instances to protect access to their shared memory resources. 
For example, the NameServer name tables are protected by setting the "gate" property of the ti.sdo.utils.NameServer module.

These examples set the "gate" property for various modules:

::
  
  heapBufMPParams.gate  = GateMP_getDefaultRemote();
  listMPParams.gate     = gateHandle;

Sample Runtime Program Flow (Dynamic)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
The following diagram shows the program flow for a two-processor (or two-thread) application. 
This application creates a Gate dynamically.

.. Image:: ../images/IpcUG_ipc_2_6_1.png


