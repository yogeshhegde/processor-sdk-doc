.. http://processors.wiki.ti.com/index.php/IPC_3.x 

Introduction
-------------

This page contains details about the IPC 3.x product, TI's solution for
interprocessor communication between cores on homogenous and
heterogeneous devices.

IPC 3.x is an evolution of the IPC product, so it helps to understand
the scope of previous generations.

-  `The IPC
   product <http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/index.html>`__
   defines `several
   interfaces <http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/index.html>`__
   to facilitate multiprocessor communication.
-  The IPC 1.x product includes implementations of those interfaces for
   the SYS/BIOS RTOS. It supports communicating between cores running
   SYS/BIOS, as well to HLOS processors running SysLink 2.x.
-  The SysLink 2.x provides services to control slave processors (e.g. load, start,
   stop). It also provides an implementation of the IPC interfaces for
   High Level OSs (HLOS) like Linux and QNX. SysLink 2.x supports
   communicating with slave processors running SYS/BIOS and IPC 1.x.

IPC 3.x merges the IPC 1.x and SysLink 2.x products, creating a single
product that defines multiprocessor communication APIs and provides
implementations for several OS's, including SYS/BIOS and HLOS's.

.. note::
  The SysLink name is being retired. The SysLink 2.x product will not
  be supported on existing devices, and development has stopped and
  support for new devices will not be added.


Changes
-----------

The key changes between IPC 1.x/SysLink 2.x and IPC 3.x is the HLOS
implementation. This table summarizes the IPC 1.x/SysLink 2.x supported APIs against
those provided in IPC 3.x.

+-----------------------+-----------------------+-----------------------+
| Feature               | IPC 1.x/SysLink 2.x   | IPC 3.x               |
+=======================+=======================+=======================+
| Slave loading         | ProcMgr               | Slaves are loaded on  |
|                       |                       | demand, currently     |
|                       |                       | without a user API    |
+-----------------------+-----------------------+-----------------------+
| Low-level primitives  | Notify, Heap*MP,      | Available for         |
|                       | Gate*MP,              | BIOS-to-BIOS          |
|                       | SharedRegion,         | communication, only   |
|                       | NameServer            | GateMP available on   |
|                       |                       | HLOS                  |
+-----------------------+-----------------------+-----------------------+
| Messaging             | MessageQ              | MessageQ              |
+-----------------------+-----------------------+-----------------------+
| Higher level data     | RingIO, FrameQ        | None, though IPC      |
| passing               |                       | provides primitives   |
|                       |                       | to enable higher      |
|                       |                       | level frameworks      |
+-----------------------+-----------------------+-----------------------+

BIOS
^^^^^^^

For BIOS-to-BIOS communication, the same features available in IPC 1.x
are available in IPC 3.x.

Linux
^^^^^^^

On Linux, IPC 3.x is built upon services available (and evolving!) in
the mainline Linux kernel (3.4+). These core services include remoteproc
and rpmsg.

Above those Linux services, a few key services from the IPC API (e.g.
MessageQ) are provided in user mode.

QNX
^^^^^^^

On QNX, IPC 3.x provides feature parity to Linux. The QNX OS doesn't
inherently provide primitives like Linux's 'remoteproc' and 'rpmsg', so
IPC 3.x also includes a loader and rpmsg-compatible communication
infrastructure. This rpmsg-compatible MessageQ implementation enables
the same BIOS-side image to communicate with either Linux or QNX on the
HLOS.

Development
-------------

IPC 3.x development is being managed at https://git.ti.com/ipc.

There is an `open mailing
list <https://gforge.ti.com/mailman/listinfo/ipc-developers>`__ where
active discussion about the code base takes place. Patches are also
submitted there for review.

IPC Training
--------------

| IPC training material is updated from time to time. Check back for new
  updates.

| **IPC Training** v2.21 - IPC 3.x Full Training Material :download:`(PowerPoint) <../files/IPC_Training_2_21.pptx>` :download:`(PowerPointShow) <../files/IPC_Training_2_21.ppsx>` :download:`(PDF) <../files/IPC_Training_2_21.pdf>`

| IPC Lab 1 - Hello :download:`(PowerPoint) <../files/IPC_Lab_1_Hello.pptx>` :download:`(PowerPointShow) <../files/IPC_Lab_1_Hello.ppsx>` :download:`(PDF) <../files/IPC_Lab_1_Hello.pdf>`

| IPC Lab 2 - MessageQ :download:`(PowerPoint) <../files/IPC_Lab_2_MessageQ.pptx>` :download:`(PowerPointShow) <../files/IPC_Lab_2_MessageQ.ppsx>` :download:`(PDF) <../files/IPC_Lab_2_MessageQ.pdf>`

| IPC Lab 3 - Scalability :download:`(PowerPoint) <../files/IPC_Lab_3_Scalability.pptx>` :download:`(PowerPointShow) <../files/IPC_Lab_3_Scalability.ppsx>` :download:`(PDF) <../files/IPC_Lab_3_Scalability.pdf>`

|

See Also
------------
-  `IPC User's Guide <index_Foundational_Components.html#ipc-user-guide>`__
-  `Embedded Linux Conference Europe Presentation on
   rpmsg <http://free-electrons.com/pub/video/2011/elce/elce-2011-ben-cohen-remote-processor-messaging-450p.webm>`__


