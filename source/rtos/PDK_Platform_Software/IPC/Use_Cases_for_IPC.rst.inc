.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide/Use_Cases_for_IPC 

Minimal Use Scenario (BIOS-to-BIOS only)
-----------------------------------------

This scenario performs inter-processor notification using a Notify
driver, which is used by the Notify module. This scenario is best used
for simple synchronization in which you want to send a message to
another processor to tell it to perform some action and optionally have
it notify the first processor when it is finished.

.. Image:: ../images/IpcUG_over_1_2_1.png

In this scenario, you make API calls to the Notify module. For example,
the Notify_sendEvent() function sends an event to the specified
processor. You can dynamically register callback functions with the
Notify module to handle such events.

You must statically configure MultiProc module properties, which are
used by the Notify module.

The amount of data passed with a notification is minimal. You can send
an event number, which is typically used by the callback function to
determine what action it needs to perform. Optionally, a small
"payload"? of data can also be sent.

See `Notify Module </index.php/IPC_Users_Guide/Notify_Module>`__ and
`MultiProc Module </index.php/IPC_Users_Guide/MultiProc_Module>`__.


.. note::

  If you are using a Concerto F28M35x device, this scenario is supported.
  See `Using IPC on Concerto
  Devices </index.php/IPC_Users_Guide/Using_IPC_on_Concerto_Devices>`__
  for details.

Data Passing Scenario (BIOS-to-BIOS only)
--------------------------------------------

In addition to the IPC modules used in the previous scenario, you can
use the ListMP module to share a linked list between processors.

.. Image:: ../images/IpcUG_over_1_2_2.png

In this scenario, you make API calls to the Notify and ListMP modules.

The ListMP module is a doubly-linked-list designed to be shared by
multiple processors. ListMP differs from a conventional "local"? linked
list in the following ways:

-  Address translation is performed internally upon pointers contained
   within the data structure.
-  Cache coherency is maintained when the cacheable shared memory is
   used.
-  A multi-processor gate (GateMP) is used to protect read/write
   accesses to the list by two or more processors.

ListMP uses SharedRegion's lookup table to manage access to shared
memory, so configuration of the SharedRegion module is required.

Internally, ListMP can optionally use the NameServer module to manage
name/value pairs. The ListMP module also uses a GateMP object, which
your application must configure. The GateMP is used internally to
synchronize access to the list elements.

See `ListMP Module </index.php/IPC_Users_Guide/ListMP_Module>`__,
`GateMP Module </index.php/IPC_Users_Guide/GateMP_Module>`__,
`SharedRegion
Module </index.php/IPC_Users_Guide/SharedRegion_Module>`__, and
`NameServer Module </index.php/IPC_Users_Guide/NameServer_Module>`__.

.. note::

  If you are using a Concerto F28M35x device, this scenario is not
  supported due to shared memory limitations. See `Using IPC on Concerto
  Devices </index.php/IPC_Users_Guide/Using_IPC_on_Concerto_Devices>`__
  for details.

Dynamic Allocation Scenario (BIOS-to-BIOS only)
-------------------------------------------------

To the previous scenario, you can add dynamic allocation of ListMP
elements using one of the Heap*MP modules.

.. Image:: ../images/IpcUG_over_1_2_3.png

In this scenario, you make API calls to the Notify and ListMP modules
and a Heap*MP module.

In addition to the modules that you configured for the previous
scenario, the Heap*MP modules use a GateMP that you must configure. You
may use the same GateMP instance used by ListMP.

See `Heap*MP Modules </index.php/IPC_Users_Guide/HeapMP_Modules>`__ and
`GateMP Module </index.php/IPC_Users_Guide/GateMP_Module>`__.

.. note::

  If you are using a Concerto F28M35x device, this scenario is not
  supported due to shared memory limitations. See `Using IPC on Concerto
  Devices </index.php/IPC_Users_Guide/Using_IPC_on_Concerto_Devices>`__
  for details.

Powerful But Easy-to-Use Messaging with MessageQ (HLOS and BIOS)
-----------------------------------------------------------------

Finally, to use the most sophisticated inter-processor communication
scenario supported by IPC, you can add the MessageQ module. Note that
the following diagram shows one particular transport (TransportShm) and
may not apply to all devices and/or environments.

.. Image:: ../images/IpcUG_over_1_2_4.png

In this scenario, you make API calls to the MessageQ module for
inter-processor communication.

API calls made to the Notify, ListMP, and Heap*MP modules in the
previous scenarios are not needed. Instead, your application only needs
to configure the MultiProc and (if the underlying MessageQ transport
requires it) the SharedRegion modules.

.. note::

  Some MessageQ transports do not use SharedRegion, but instead copy the
  message payloads. This may be done because of hardware limitations (e.g.
  no shared memory is available) or software design (e.g. transports built
  on Linux kernel-friendly rpmsg drivers).


The ``Ipc_start()`` API call configures all the necessary underlying
modules (e.g. Notify, HeapMemMP, ListMP, TransportShm, NameServer, and
GateMP). The actual details of what modules ``Ipc_start()`` initializes
varies from environment to environment.

It is possible to use MessageQ in a single-processor SYS/BIOS
application. In such a case, only API calls to MessageQ and
configuration of any xdc.runtime.IHeap implementation are needed.


.. note::

  If you are using a Concerto F28M35x device, this scenario is supported,
  but fewer modules are used due to shared memory limitations. See `Using
  IPC on Concerto
  Devices </index.php/IPC_Users_Guide/Using_IPC_on_Concerto_Devices>`__
  for details.

.. raw:: html
