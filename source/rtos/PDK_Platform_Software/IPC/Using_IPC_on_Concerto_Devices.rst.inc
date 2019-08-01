.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide/Using_IPC_on_Concerto_Devices 

This page provides target-specific information about using IPC on Concerto devices.

SYS/BIOS supports both the ARM M3 and the 'C28x cores on Concerto F28M35x devices. This allows you to use the same SYS/BIOS and IPC APIs on both processors and to use IPC for communication between the two cores. The following table identifies which IPC modules are used and not used with Concerto devices:

+---------------------------------------------------+------------------------------------+--------------------------------------------------------------------------------------------------+
| Modules Used with Concerto                        | Modules Not Used or Supported      | Notes                                                                                            |
+===================================================+====================================+==================================================================================================+
| MessageQ                                          |                                    | MessageQ usage is the same.                                                                      |
+---------------------------------------------------+------------------------------------+--------------------------------------------------------------------------------------------------+
| Notify                                            |                                    | Notify usage is the same.                                                                        |
+---------------------------------------------------+------------------------------------+--------------------------------------------------------------------------------------------------+
| MultiProc                                         |                                    | MultiProc configuration is the same.                                                             |
+---------------------------------------------------+------------------------------------+--------------------------------------------------------------------------------------------------+
| IpcMgr (in ti.sdo.ipc.family.f28m35x)             | Ipc                                | IpcMgr must be configured in place of the Ipc module when using Concerto.                        |
+---------------------------------------------------+------------------------------------+--------------------------------------------------------------------------------------------------+
| NotifyDriverCirc (in ti.sdo.ipc.family.f28m35x)   | NotifyDriverShm, NotifyDriverMbx   | See [[../Optimizing IPC Applications\|Optimizing IPC Applications]].                             |
+---------------------------------------------------+------------------------------------+--------------------------------------------------------------------------------------------------+
| TransportCirc (in ti.sdo.ipc.family.f28m35x)      | TransportShm, TransportShmNotify   | See [[../Optimizing IPC Applications\|Optimizing IPC Applications]].                             |
+---------------------------------------------------+------------------------------------+--------------------------------------------------------------------------------------------------+
| List                                              |                                    | List usage is the same.                                                                          |
+---------------------------------------------------+------------------------------------+--------------------------------------------------------------------------------------------------+
| NameServer                                        |                                    | NameServer usage is the same.                                                                    |
+---------------------------------------------------+------------------------------------+--------------------------------------------------------------------------------------------------+
|                                                   | GateMP                             | Shared gates are not supported with Concerto.                                                    |
+---------------------------------------------------+------------------------------------+--------------------------------------------------------------------------------------------------+
| HeapBuf (from SYS/BIOS)                           | Heap\*MP                           | Shared heaps are not supported with Concerto.                                                    |
+---------------------------------------------------+------------------------------------+--------------------------------------------------------------------------------------------------+
|                                                   | ListMP                             | Shared lists are not supported with Concerto.                                                    |
+---------------------------------------------------+------------------------------------+--------------------------------------------------------------------------------------------------+
|                                                   | SharedRegion                       | IpcMgr is used instead of SharedRegion to specify the location of shared memory with Concerto.   |
+---------------------------------------------------+------------------------------------+--------------------------------------------------------------------------------------------------+

In addition, you should be aware of the following special issues:

* No caching is performed on Concerto devices. Ignore any information about caching in the IPC documentation.
* Concerto provides a shared timestamp counter that can be read by either core. SYS/BIOS manages this counter with the ti.sysbios.family.[c28|arm].f28m35x.TimestampProvider modules. The Timestamp_get32() APIs use this counter to provide a common timestamp on both M3 and C28x cores. This is useful when logging on both cores and debugging multi-core issues.


Configuring Applications with IpcMgr
-------------------------------------

The ti.sdo.ipc.family.f28m35x.IpcMgr module is used only for Concerto
F28M35x devices. You use IpcMgr instead of the ti.sdo.ipc.Ipc module.
That is, your application should not call Ipc_start() or Ipc_attach().

The IpcMgr module statically configures which shared memory segments to
enable between the M3 and 'C28 processors. No IpcMgr APIs need to be
called at runtime. Instead, the drivers for IPC are created during this
module's startup function, which runs internally. The internal startup
function also synchronizes the M3 and 'C28 processors.

Concerto devices have 8 segments of shared RAM. Each segment has 8 KB.
Only one core can have read/write access to a shared memory segment at a
time. The other core has read access to that segment. When configuring
M3 and 'C28 applications, you must specify the shared memory read and
write addresses that IPC should use. Your application can use other
shared memory segments as needed.

For example, suppose you want to configure the Concerto with the M3
processor writing to the S6 segment of shared RAM and the 'C28x writing
to the S7 segment of shared RAM. The following diagram shows the local
addresses used to point to the start of the shared memory segment from
both processors:

.. image:: ../images/sharedmem_access.png

The IpcMgr module configuration for such an 'C28 application would be as
follows:

:: 

    var IpcMgr = xdc.useModule('ti.sdo.ipc.family.f28m35x.IpcMgr');
    IpcMgr.readAddr  = 0x12000;     /* S6 RAM */
    IpcMgr.writeAddr = 0x13000;     /* S7 RAM */

| 

The corresponding configuration for the M3 application would be:

::

    var IpcMgr = xdc.useModule('ti.sdo.ipc.family.f28m35x.IpcMgr');
    IpcMgr.readAddr  = 0x20016000;  /* S7 RAM */
    IpcMgr.writeAddr = 0x20014000;  /* S6 RAM */
    IpcMgr.sharedMemoryOwnerMask = 0x80;

| 

The readAddr and writeAddr segments specified for a processor must be
different. The readAddr segment on one processor must correspond to the
writeAddr segment on the other processor. The memory addresses you use
must be the physical addresses understood by the local core.
By default, the M3 has write access to all segments initially. IPC's
IpcMgr module provides a sharedMemoryOwnerMask that the M3 core must set
to provide write access to the 'C28 core. This mask writes to the M3's
MSxMSEL register. This register determines which processor has write
access to each of the 8 shared RAM segments. In the previous example,
the M3 application sets the sharedMemoryOwnerMask to 0x80, which sets
the bit for the S7 RAM segment to "1"?, allowing the 'C28 to write to
that segment.

Additional configuration properties you can set for the IpcMgr module
include:

-  **sharedMemoryEnable.** This property lets the M3 processor disable
   one or more shared RAM segments. By default, all segments are
   enabled. This property writes to the MEMCNF register from the M3. To
   disable a shared RAM segment, set the corresponding bit to 0. You
   cannot load data into a disabled RAM segment. (Do not use in C28
   applications.)
-  **sharedMemoryAccess.** This property lets the M3 processor specify
   the type of access the owner can have to shared RAM segments. This
   property writes to the MSxSRCR register from the M3. (Do not use in
   C28 applications.)

By default, the segment owner has fetch, DMA write, and CPU write access
to all segments owned. You should *not* disable fetch or CPU write
access for the two segments used by IpcMgr. DMA write access is not used
by IpcMgr.:
The IpcMgr.sharedMemoryAccess configuration property is an array of
eight 32-bit masks. Mask[0] corresponds to the S0 shared RAM segment,
and so on. In each mask, bits 0 through 2 are used to control fetch (bit
0), DMA write (bit 1), and CPU write (bit 2) access. All other bits are
ignored. By default, all three types of access are allowed, which
corresponds to a bit setting of zero (0). Setting a bit to 1 disables
that type of access for the shared RAM segment corresponding to that
mask. For example, the following statements remove DMA write and CPU
write access for the S4 segment.

::
  
  var IpcMgr = xdc.useModule('ti.sdo.ipc.family.f28m35x.IpcMgr');
  IpcMgr.sharedMemoryAccess[4] = 0x6;


-  **IpcMgr.ipcSetFlag.** This property determines which flag generates
   an IPC interrupt. The default is 3. You can use a value from 0 to 3,
   but the value must be the same on both processors.

In addition, the IpcMgr module provides configuration properties that
set the number of Notify and MessageQ messages stored in the circular
buffers and the largest MessageQ size (in bytes) supported by the
transport. These can be modified to reduce shared memory use if the
application passes relatively few messages between the processors.

-  **IpcMgr.numNotifyMsgs.** By default, the Notify driver's circular
   buffer can hold up to 32 messages, which means there can be up to 31
   outstanding notifications. You can change this value by setting the
   IpcMgr.numNotifyMsgs property to some other power of 2.

The IpcMgr.numNotifyMsgs property affects the size of the shared memory
circular buffer used to store notifications regardless of the event IDs.
Changing this value allows you to optimize either the memory use or the
performance. That is, with fewer messages, the buffer is smaller but
there is a higher chance that the system will have a full circular
buffer and need to wait for space to be freed. :
Note that the IpcMgr.numNotifyMsgs property is different from the
Notify.numEvents property. The Notify.numEvents property determines the
number of unique event IDs that can be used in a system. When this
property is set to the default value of 32, Notify event IDs can range
from 0 to 31.:

-  **IpcMgr.numMessageQMsgs.** By default, the MessageQ transport's
   circular buffer can hold up to 4 messages. The number of MessageQ
   messages must be a power of 2. If your application does not use
   MessageQ, you should set this property to 0 in order to reduce the
   application's memory footprint.
-  **IpcMgr.messageQSize.** By default, each message in the MessageQ
   transport's circular buffer can hold 128 bytes. If your application
   stores less information in each MessageQ message, you should set this
   property to reduce the application's memory footprint.

If you want to know how much memory is used by IpcMgr, open the .map
file that is created when you build your application, and search for the
section names that contain ti.sdo.ipc.family.f28m35x.IpcMgr.readSect and
ti.sdo.ipc.family.f28m35x.IpcMgr.writeSect.

Examples for Concerto
------------------------

IPC provides Notify and MessageQ examples for both the ARM M3 and the
C28x cores. Both are dual-core examples in which the same program (with
a slightly different configuration) is executed on both cores.

The Notify example uses the ti.ipc.Notify module to send a notification
back and forth between the M3 and the C28 a number of times (10 by
default). When a processor receives an event, it posts a Semaphore that
allows a Task function to continue running and send a reply notification
to the other processor.

The MessageQ example uses the ti.ipc.MessageQ module to send messages
between processors. Each processor creates its own MessageQ first, and
then tries to open the remote processor's MessageQ.

If you compare the CFG files for the Concerto examples with the examples
for some other device, you will notice that the Concerto configuration
is simpler because it does not need to synchronize the processors or
configure the NotifySetup and SharedRegion modules.

If you compare the C code for the Concerto examples with the examples
for some other device, you will find the following categories of
differences:

-  The Concerto MessageQ example allocates MessageQ messages using the
   ti.sysbios.heaps.HeapBuf module instead of the ti.sdo.ipc.HeapBufMP
   module, because HeapBufMP is not supported for Concerto.
-  The Concerto examples do not call Ipc_start() or include the
   ti.sdo.ipc.Ipc module.
-  In the Concerto examples, the other processor is called the "remote"?
   processor instead of the "next"? processor, since there are only two
   processors.

| 


