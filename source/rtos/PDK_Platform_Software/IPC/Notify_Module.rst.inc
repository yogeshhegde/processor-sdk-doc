.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide/Notify_Module 

.. |notCfg_Img1| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |notRun_Img1| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_notify_8h.html

| 

   +---------------+---------------+
   |     API Reference Links       |
   +===============+===============+
   | |notCfg_Img1| | |notRun_Img1| |
   +---------------+---------------+

he ti.sdo.ipc.Notify module manages the multiplexing/demultiplexing of software interrupts over hardware interrupts.
In order to use any Notify APIs, you must first call Ipc_start(). This sets up all the necessary Notify drivers, shared memory, and interprocessor interrupts. However, note that if you've configured Ipc.setupNotify = false, you will need to explicitly call Notify_start() outside the scope of Ipc_start().

To be able to receive notifications, a processor registers one or more callback functions to an eventId by calling Notify_registerEvent(). The callback function must have the following signature:

:: 
  
  Void cbFxn(UInt16 procId, UInt16 lineId, UInt32 eventId, UArg arg, UInt32 payload);
  
Notify_registerEvent(), like most other Notify APIs, uses a MultiProc ID and line ID to target a specific interrupt line to/from a specific processor on a device.

::
  
  Int status;
  armProcId = MultiProc_getId("ARM");
   
  Ipc_start();
   
  /* Register cbFxn with Notify. It will be called when ARM
   * sends event number EVENTID to line #0 on this processor.
   * The argument 0x1010 is passed to the callback function. */
  status = Notify_registerEvent(armProcId, 0, EVENTID,
                   (Notify_FnNotifyCbck)cbFxn, 0x1010);
  if (status < 0) {
      System_abort("Notify_registerEvent failed\n");
  }

The line ID number is typically 0 (zero), but is provided for use on systems that have multiple interrupt lines between processors.

When using Notify_registerEvent(), multiple callbacks may be registered with a single event. If you plan to register only one callback function for an event on this processor, you can call Notify_registerEventSingle() instead of Notify_registerEvent(). Better performance is provided with Notify_registerEventSingle(), and a Notify_E_ALREADYEXISTS status is returned if you try to register a second callback for the same event.

Once an event has been registered, a remote processor may "send" an event by calling Notify_sendEvent(). If the specified event and interrupt line are both enabled, all callback functions registered to the event will be called sequentially.

::
  
  while (seq < NUMLOOPS) {
    Semaphore_pend(semHandle, BIOS_WAIT_FOREVER);
    /* Semaphore_post is called by callback function*/
    status = Notify_sendEvent(armProcId, 0, EVENTID, seq, TRUE);
  }
  
In this example, the seq variable is sent as the "payload" along with the event. The payload is limited to a fixed size of 32 bits.

Since the fifth argument in the previous example call to Notify_sendEvent() is TRUE, if any previous event to the same event ID was sent, the Notify driver waits for an acknowledgement that the previous event was received.

A specific event may be disabled or enabled using Notify_disableEvent() and Notify_enableEvent(). All notifications on an entire interrupt line may be disabled or restored using Notify_disable() and Notify_restore() calls. Notify_disable() does not alter the state of individual events. Instead, it just disables the ability of the Notify module to receive events on the specified interrupt line.

"Loopback" mode, which is enabled by default, allows notifications to be registered and sent locally. This is accomplished by supplying the processor's own MultiProc ID to Notify APIs. Line ID 0 (zero) is always used for local notifications. It is important to be aware of some subtle (but important) differences between remote and local notifications:

 - Loopback callback functions execute in the context of the same thread that called Notify_sendEvent(). This is in contrast to callback functions called due to another processor's sent notification--such "remote" callback functions execute in an ISR context.
 - Loopback callback functions execute with interrupts disabled.
 - Disabling the local interrupt line causes all notifications that are sent to the local processor to be lost. By contrast, a notification sent to an enabled event on a remote processor that has called Notify_disableEvent() results in a pending notification until the disabled processor has called Notify_restore().
 - Local notifications do not support events of different priorities. By contrast, Notify driver implementations may correlate event IDs with varying priorities.

.. note::
  The Notify Module is only supported in SYS/BIOS environments. It is not provided on HLOS's.

