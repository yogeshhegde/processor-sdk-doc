.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide/Porting_IPC 

Interfaces to Implement
-------------------------

When porting IPC to new devices, you may need to create custom
implementations of the following interfaces. You may find that the
provided implementations of these interfaces meet your needs, so don't
assume that you will need to create custom implementation in all cases.

-  "IInterrupt"? for use by Notify. The interface definition is in
   ti.sdo.ipc.notifyDrivers.IInterrupt.
-  "IGateMPSupport"? for use by GateMP. The interface definition is in
   ti.sdo.ipc.interfaces.IGateMPSupport.
-  "IMessageQTransport"? and "ITransportSetup"? for use by MessageQ.
   Interface definitions are in ti.sdo.ipc.interfaces.IMessageQTransport
   and ti.sdo.ipc.interfaces.ITransportSetup.
-  "INotifyDriver"? for use by Notify. The interface definition is in
   ti.sdo.ipc.interfaces.INotifyDriver.
-  "INotifySetup"? module, which defines interrupt mappings, for use by
   Notify. The interface definition is in
   ti.sdo.ipc.interfaces.INotifySetup.

For details about the interfaces, see the IPC online documentation.

Other Porting Tasks
---------------------

You will likely need to specify custom shared region(s) in your
configuration file. For details, see `SharedRegion
Module <index_Foundational_Components.html#shared-region-module>`__.

Optionally, you may implement custom Heaps and hardware-specific
versions of other IPC modules.

| 

