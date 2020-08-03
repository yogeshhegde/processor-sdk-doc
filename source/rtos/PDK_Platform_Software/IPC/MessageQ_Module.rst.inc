.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide/MessageQ_Module 

.. |msgCfg_Img1| Image:: /images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |msgCfg_Img2| Image:: /images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

                 
.. |msgRun_Img1| Image:: /images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_message_q_8h.html

.. |msgRun_Img2| Image:: /images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_message_q_8h.html

| 

   +---------------+---------------+
   |     API Reference Links       |
   +===============+===============+
   | |msgCfg_Img1| | |msgRun_Img1| |
   +---------------+---------------+


The MessageQ module supports the structured sending and receiving of variable length messages. 
It is OS independent and works with any threading model. For each MessageQ you create, 
there is a single reader and may be multiple writers.

MessageQ is the recommended messaging API for most applications. 
It can be used for both homogeneous and heterogeneous multi-processor messaging, 
along with single-processor messaging between threads.

.. note::
   The MessageQ module in IPC is similar in functionality to the MSGQ module in DSP/BIOS 5.x.

The following are key features of the MessageQ module:

- Writers and readers can be relocated to another processor with no runtime code changes.
- Timeouts are allowed when receiving messages.
- Readers can determine the writer and reply back.
- Receiving a message is deterministic when the timeout is zero.
- Messages can reside on any message queue.
- Supports zero-copy transfers (BIOS only)
- Messages can be sent and received from any type of thread.
- The notification mechanism is specified by the application (BIOS only)
- Allows QoS (quality of service) on message buffer pools. For example, using specific buffer pools for specific message queues. (BIOS only)

Messages are sent and received via a message queue. A reader is a thread that gets (reads) messages 
from a message queue. A writer is a thread that puts (writes) a message to a message queue. 
Each message queue has one reader and can have many writers. 
A thread may read from or write to multiple message queues.

- **Reader.** The single reader thread calls MessageQ_create(), MessageQ_get(), MessageQ_free(), and MessageQ_delete().
- **Writer.** Writer threads call MessageQ_open(), MessageQ_alloc(), MessageQ_put(), and MessageQ_close().

The following figure shows the flow in which applications typically use the main runtime MessageQ APIs:

.. Image:: /images/IpcUG_ipc_2_3_1.png

Conceptually, the reader thread creates and owns the message queue. Writer threads then open a created message queue to get access to them.

Configuring the MessageQ Module (BIOS only)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
On BIOS-based systems, you can configure a number of module-wide properties for MessageQ in your XDCtools configuration file.

|msgCfg_Img2| A snapshot of the MessageQ module configuration 
documentation is available `online <http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html>`_.

To configure the MessageQ module, you must enable the module as follows:

::
  
  var MessageQ = xdc.useModule('ti.sdo.ipc.MessageQ');

Some example Module-wide configuration properties you can set follow; refer to the IPC documentation for details.

::
  
  // Maximum length of MessageQ names
  MessageQ.maxNameLen = 32;
   
  // Max number of MessageQs that can be dynamically created
  MessageQ.maxRuntimeEntries = 10;

Creating a MessageQ Object
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
You can create message queues dynamically. Static creation is not supported. 
A MessageQ object is not a shared resource. That is, it resides on the processor, within the process, that creates it.

The reader thread creates a message queue. To create a MessageQ object dynamically, 
use the MessageQ_create() C API, which has the following syntax:

::
  
  MessageQ_Handle MessageQ_create(String name, MessageQ_Params *params);

When you create a queue, you specify a name string. This name will be needed by the MessageQ_open() function, 
which is called by threads on the same or remote processors that want to send messages to the created message queue. 
While the name is not required (that is, it can be NULL), an unnamed queue cannot be opened.

An ISync handle is associated with the message queue via the synchronizer parameter.

If the call is successful, the MessageQ_Handle is returned. If the call fails, NULL is returned.

You initialize the params struct by using the MessageQ_Params_init() function, which initializes the params structure with the default values. A NULL value for params can be passed into the create call, which results in the defaults being used. 
The default synchronizer is SyncSem.

The following code creates a MessageQ object using SyncSem as the synchronizer.

::
  
  MessageQ_Handle   messageQ;
  MessageQ_Params   messageQParams;
  SyncSem_Handle    syncSemHandle;
   
  ...
   
  syncSemHandle = SyncSem_create(NULL, NULL);
  MessageQ_Params_init(&messageQParams);
  messageQParams.synchronizer = SyncSem_Handle_upCast(syncSemHandle);
  messageQ = MessageQ_create(CORE0_MESSAGEQNAME, &messageQParams);

In this example, the CORE0_MESSAGEQNAME constant may be defined in header shared by multiple cores.

|msgRun_Img2| A snapshot of the MessageQ module run-time 
API documentation is available `online <http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_message_q_8h.html>`_.


Opening a Message Queue
^^^^^^^^^^^^^^^^^^^^^^^^
Writer threads open a created message queue to get access to them. 
In order to obtain a handle to a message queue that has been created, 
a writer thread must call MessageQ_open(), which has the following syntax.

::

  Int MessageQ_open(String name, MessageQ_QueueId *queueId);

This function expects a name, which must match with the name of the created object. 
Internally MessageQ calls NameServer_get() to find the 32-bit queueId associated with the created message queue. 
NameServer looks both locally and remotely.

If no matching name is found on any processor, MessageQ_open() returns MessageQ_E_NOTFOUND. 
If the open is successful, the Queue ID is filled in and MessageQ_S_SUCCESS is returned.

The following code opens the MessageQ object created by the processor.

::
  
  MessageQ_QueueId   remoteQueueId;
  Int                status;
   
  ...
   
  /* Open the remote message queue. Spin until it is ready. */
  do {
     status = MessageQ_open(CORE0_MESSAGEQNAME, &remoteQueueId);
  }
  while (status < 0);

Allocating a Message
^^^^^^^^^^^^^^^^^^^^^^
MessageQ manages message allocation via the MessageQ_alloc() and MessageQ_free() functions. 
MessageQ uses Heaps for message allocation. MessageQ_alloc() has the following syntax:

:: 
  
  MessageQ_Msg MessageQ_alloc(UInt16        heapId,
                              UInt32        size);

The allocation size in MessageQ_alloc() must include the size of the message header, which is 32 bytes.

The following code allocates a message:

::
  
  #define MSGSIZE                  256
  #define HEAPID                     0
  ...
  MessageQ_Msg     msg;
   
  ...
   
  msg = MessageQ_alloc(HEAPID, sizeof(MessageQ_MsgHeader));
  if (msg == NULL) {
      System_abort("MessageQ_alloc failed\n");
  }

Once a message is allocated, it can be sent on any message queue. 
Once the reader receives the message, it may either free the message or re-use the message.
Messages in a message queue can be of variable length. 
The only requirement is that the first field in the definition of a message must be a MsgHeader structure. 
For example:

::
  
  typedef struct MyMsg {
      MessageQ_MsgHeader header;     // Required
      SomeEnumType       type        // Can be any field
      ...                            // ...
  } MyMsg;

The MessageQ APIs use the MessageQ_MsgHeader internally. Your application should not 
modify or directly access the fields in the MessageQ_MsgHeader structure.

MessageQ Allocation and Heaps
"""""""""""""""""""""""""""""""
All messages sent via the MessageQ module must be allocated from a xdc.runtime.IHeap implementation, such as ti.sdo.ipc.heaps.HeapBufMP. 
The same heap can also be used for other memory allocation not related to MessageQ.

The MessageQ_registerHeap() API assigns a MessageQ heapId to a heap. When allocating a message, the heapId is used, not the heap handle. The heapIds should start at zero and increase. 
The maximum number of heaps is determined by the numHeap module configuration property. 
See the online documentation for MessageQ_registerHeap() for details.

::
  
  /* Register this heap with MessageQ */
  status = MessageQ_registerHeap( HeapBufMP_Handle_upCast(heapHandle), HEAPID);

If the registration fails (for example, the heapId is already used), this function returns FALSE.

An application can use multiple heaps to allow an application to regulate its message usage. 
For example, an application can allocate critical messages from a heap of fast on-chip memory and non-critical messages from a heap of slower external memory. 
Additionally, heaps MessageQ uses can be shared with other modules and/or the application.

MessageQ alternatively supports allocating messages without the MessageQ_alloc() function.

Heaps can be unregistered via MessageQ_unregisterHeap().

MessageQ Allocation Without a Heap
""""""""""""""""""""""""""""""""""""
It is possible to send MessageQ messages that are allocated statically instead of being allocated at run-time via MessageQ_alloc(). 
However the first field of the message must still be a MsgHeader. 
To make sure the MsgHeader has valid settings, the application must call MessageQ_staticMsgInit(). 
This function initializes the header fields in the same way that MessageQ_alloc() does, 
except that it sets the heapId field in the header to the MessageQ_STATICMSG constant.

If an application uses messages that were not allocated using MessageQ_alloc(), it cannot free the messages via the MessageQ_free() function, 
even if the message is received by a different processor. Also, the transport may internally call MessageQ_free() 
and encounter an error.

If MessageQ_free() is called on a statically allocated message, it asserts that the heapId of the message is not MessageQ_STATICMSG.

Sending a Message
^^^^^^^^^^^^^^^^^^^
Once a message queue is opened and a message is allocated, the message can be sent to the MessageQ via 
the MessageQ_put() function, which has the following syntax.

::
  
  Int MessageQ_put(MessageQ_QueueId queueId,
                 MessageQ_Msg     msg);

For example:

::
  
  status = MessageQ_put(remoteQueueId, msg);

Opening a queue is not required. Instead the message queue ID can be "discovered" 
via the MessageQ_getReplyQueue() function, which returns the 32-bit queueId.

::
  
  MessageQ_QueueId replyQueue;
  MessageQ_Msg     msg;
   
  /* Use the embedded reply destination */
  replyMessageQ = MessageQ_getReplyQueue(msg);
  if (replyMessageQ == MessageQ_INVALIDMESSAGEQ) {
      System_abort("Invalid reply queue\n");
  }
   
  /* Send the response back */
  status = MessageQ_put(replyQueue, msg);
      if (status < 0) {
          System_abort("MessageQ_put was not successful\n");
      }

If the destination queue is local, the message is placed on the appropriate priority linked list and the ISync signal function is called. 
If the destination queue is on a remote processor, the message is given to the proper transport and returns.

If MessageQ_put() succeeds, it returns MessageQ_S_SUCCESS. If MessageQ_E_FAIL is returned, 
an error occurred and the caller still owns the message.

There can be multiple senders to a single message queue. MessageQ handles the thread safety.

Before you send a message, you can use the MessageQ_setMsgId() function to assign a numeric value to the message that can be checked by the receiving thread.

::
  
  /* Increment...the remote side will check this */
  msgId++;
  MessageQ_setMsgId(msg, msgId);

You can use the MessageQ_setMsgPri() function to set the priority of the message.

Receiving a Message
^^^^^^^^^^^^^^^^^^^^
To receive a message, a reader thread calls the MessageQ_get() API.

::
  
  Int MessageQ_get(MessageQ_Handle handle,
                   MessageQ_Msg    *msg,
                   UInt            timeout)

If a message is present, it returned by this function. In this case the ISync's wait() function is not called.
For example:

::
  
  /* Get a message */
  status = MessageQ_get(messageQ, &msg, MessageQ_FOREVER);
  if (status < 0) {
       System_abort("Should not happen; timeout is forever\n");
  }

If no message is present and no error occurs, this function blocks while waiting for the timeout period for the message to arrive.
If the timeout period expires, MessageQ_E_FAIL is returned. If an error occurs, the msg argument will be unchanged.

After receiving a message, you can use the following APIs to get information about the message from the message header:

- MessageQ_getMsgId() gets the ID value set by MessageQ_setMsgId(). For example:

::
  
    /* Get the id and increment it to send back */
    msgId = MessageQ_getMsgId(msg);
    msgId += NUMCLIENTS;
    MessageQ_setMsgId(msg, msgId);

- MessageQ_getMsgPri() gets the priority set by MessageQ_setMsgPri().
- MessageQ_getMsgSize() gets the size of the message in bytes.
- MessageQ_getReplyQueue() gets the ID of the queue provided by MessageQ_setReplyQueue().

Deleting a MessageQ Object
^^^^^^^^^^^^^^^^^^^^^^^^^^^
MessageQ_delete() frees a MessageQ object stored in local memory. If any messages are still on the internal linked lists, they will be freed. 
The contents of the handle are nulled out by the function to prevent use after deleting.

::
  
  Void MessageQ_delete(MessageQ_Handle *handle);

The queue array entry is set to NULL to allow re-use.

Once a message queue is deleted, no messages should be sent to it. A MessageQ_close() is recommended, but not required.

Message Priorities
^^^^^^^^^^^^^^^^^^^
MessageQ supports three message priorities as follows:

- MessageQ_NORMALPRI = 0
- MessageQ_HIGHPRI = 1
- MessageQ_URGENTPRI = 3

You can set the priority level for a message before sending it by using the MessageQ_setMsgPri() function:

::
  
  Void MessageQ_setMsgPri(MessageQ_Msg        msg,
                        MessageQ_Priority   priority)

Internally a MessageQ object maintains two linked lists: normal and high-priority. 
A normal priority message is placed onto the "normal" linked list in FIFO manner. 
A high priority message is placed onto the "high-priority" linked list in FIFO manner. 
An urgent message is placed at the beginning of the high linked list.


.. note::
  Since multiple urgent messages may be sent before a message is read, the order of urgent messages is not guaranteed.

When getting a message, the reader checks the high priority linked list first. 
If a message is present on that list, it is returned. If not, the normal priority linked list is checked. 
If a message is present there, it is returned. Otherwise the synchronizer's wait function is called.

.. note::
  The MessageQ priority feature is enabled by the selecting different MessageQ transports. 
  Some MessageQ implementations (e.g. Linux) may not support multiple transports and therefore may not support this feature.

Thread Synchronization (BIOS only)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
MessageQ supports reads and writes of different thread models. 
It can work with threading models that include SYS/BIOS's Hwi, Swi, and Task threads.

This flexibility is accomplished by using an implementation of the xdc.runtime.knl.ISync interface. 
The creator of the message queue must also create an object of the desired ISync implementation and assign that object as the "synchronizer" of the MessageQ. 
Each message queue has its own synchronizer object.

An ISync object has two main functions: signal() and wait(). 
Whenever MessageQ_put() is called, the signal() function of the ISync implementation is called. 
If MessageQ_get() is called when there are no messages on the queue, the wait() function of the ISync implementation is called. 
The timeout passed into the MessageQ_get() is directly passed to the ISync wait() API.

.. note::
  Since ISync implementations must be binary, the reader thread must drain the MessageQ of all messages before waiting for another signal.

For example, if the reader is a SYS/BIOS Swi, the instance could be a SyncSwi. 
When a MessageQ_put() is called, the Swi_post() API would be called. 
The Swi would run and it must call MessageQ_get() until no messages are returned. 
If the Swi does not get all the messages, the Swi will not run again, or at least will not run until a new message is placed on the queue.

The calls to ISync functions occurs directly in MessageQ_put() when the call occurs on the same processor where the queue was created. In the remote case, the transport calls MessageQ_put(), which is then a local put, and the signal function is called.

The following are ISync implementations provided by XDCtools and SYS/BIOS:

- **xdc.runtime.knl.SyncNull.** The signal() and wait() functions do nothing. Basically this implementation allows for polling.
- **xdc.runtime.knl.SyncSemThread.** An implementation built using the xdc.runtime.knl.Semaphore module, which is a binary semaphore.
- **xdc.runtime.knl.SyncGeneric.xdc.** This implementation allows you to use custom signal() and wait() functions as needed.
- **ti.sysbios.syncs.SyncSem.** An implementation built using the ti.sysbios.ipc.Semaphore module. The signal() function runs a Semaphore_post(). The wait() function runs a Semaphore_pend().
- **ti.sysbios.syncs.SyncSwi.** An implementation built using the ti.sysbios.knl.Swi module. The signal() function runs a Swi_post(). The wait() function does nothing and returns FALSE if the timeout elapses.
- **ti.sysbios.syncs.SyncEvent.** An implementation built using the ti.sysbios.ipc.Event module. The signal() function runs an Event_post(). The wait() function does nothing and returns FALSE if the timeout elapses. This implementation allows waiting on multiple events.

The following code from the "message" example creates a SyncSem instance and assigns it to the synchronizer field in the MessageQ_Params structure before creating the MessageQ instance:

::
  
  #include <ti/sysbios/syncs/SyncSem.h>
  ...
   
  MessageQ_Params   messageQParams;
  SyncSem_Handle    syncSemHandle;
   
  /* Create a message queue using SyncSem as synchronizer */
  syncSemHandle = SyncSem_create(NULL, NULL);
  MessageQ_Params_init(&messageQParams);
  messageQParams.synchronizer = SyncSem_Handle_upCast(syncSemHandle);
  messageQ = MessageQ_create(CORE1_MESSAGEQNAME, &messageQParams, NULL);

ReplyQueue
^^^^^^^^^^^^^
For some applications, doing a MessageQ_open() on a queue is not realistic. 
For example, a server may not want to open all the clients' queues for sending responses. 
To support this use case, the message sender can embed a reply queueId in the message 
using the MessageQ_setReplyQueue() function.

::
  
  Void MessageQ_setReplyQueue(MessageQ_Handle handle,
                            MessageQ_Msg msg)

This API stores the message queue's queueId into fields in the MsgHeader.

The MessageQ_getReplyQueue() function does the reverse. For example:

::
  
  MessageQ_QueueId replyQueue;
  MessageQ_Msg     msg;
  ...
   
  /* Use the embedded reply destination */
  replyMessageQ = MessageQ_getReplyQueue(msg);
  if (replyMessageQ == MessageQ_INVALIDMESSAGEQ) {
     System_abort("Invalid reply queue\n");
  }

The MessageQ_QueueId value returned by this function can then be used in a MessageQ_put() call.

The queue that is embedded in the message does not have to be the sender's queue.

Remote Communication via Transports (BIOS only)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

MessageQ is designed to support multiple processors. To allow this, different transports can be plugged into MessageQ.

In a multi-processor system, MessageQ communicates with other processors via ti.sdo.ipc.interfaces.IMessageQTransport instances. 
There can be up to two IMessageQTransport instances for each processor to which communication is desired. 
One can be a normal-priority transport and the other for handling high-priority messages. 
This is done via the priority parameter in the transport create() function. 
If there is only one register to a remote processor (either normal or high), all messages go via that transport.

There can be different transports on a processor. For example, there may be a shared memory transport to processor A and an sRIO one to processor B.

When your application calls Ipc_start(), the default transport instance used by MessageQ is created automatically. 
Internally, transport instances are responsible for registering themselves with MessageQ via the MessageQ_registerTransport() function.

IPC provides an implementation of the IMessageQTransport interface called ti.sdo.ipc.transports.TransportShm (shared memory). 
You can write other implementations to meet your needs.

When a transport is created via a transport-specific create() call, a remote processor ID (defined via the MultiProc module) is specified. 
This ID denotes which processor this instance communicates with. 
Additionally there are configuration properties for the transport--such as the message priority handled--that can be defined in a Params structure. 
The transport takes these pieces of information and registers itself with MessageQ. 
MessageQ now knows which transport to call when sending a message to a remote processor.

Trying to send to a processor that has no transport results in an error.

Custom Transport Implementations
"""""""""""""""""""""""""""""""""
Transports can register and unregister themselves dynamically. That is, if the transport instance is deleted, 
it should unregister with MessageQ.

When receiving a message, transports need to form the MessageQ_QueueId that allows them to call MessageQ_put(). 
This is accomplished via the MessageQ_getDstQueue() API.

::
  
  MessageQ_QueueId MessageQ_getDstQueue(MessageQ_Msg msg)

Sample Runtime Program Flow (Dynamic)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
The following figure shows the typical sequence of events when using a MessageQ. 
A message queue is created by a Task. An open on the same processor then occurs. 
Assume there is one message in the system. The opener allocates the message and 
sends it to the created message queue, which gets and frees it.

.. Image:: /images/IpcUG_ipc_2_3_2.png

