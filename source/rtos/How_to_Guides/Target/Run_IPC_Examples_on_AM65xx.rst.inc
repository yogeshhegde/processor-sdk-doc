
AM65xx IPC Examples
---------------------------

In the processor SDK release ipc examples can be built from the Processor SDK top level makefile.

See link for building IPC examples

:ref:`ipc-rtos-examples`

Once the examples are built, they can be run by loading and running the binaries using CCS through JTAG.
Please refer to the section "Advanced AM65x Debug Setup with DMSC Firmware Load" of the TMDX654 EVM Hardware Setup Guide for setting up the JTAG.

`Advanced AM65x Debug Setup with DMSC Firmware Load`_

.. rubric:: IPC Message Queue Example:
   :name: ipc-message-queue-example

**ex02_messageq**

Message queue example sends round-trip message from client to server and
back. MessageQ example uses client/server pattern. It is a two
processors example: the HOST and R5F-0 processor. 

The R5F-0 processor is configured as server. It creates a named message
queue. The server does not open any queues because it extracts the
return address from the message header. The server returns all messages
to the sender. It does not access the message pool.

The HOST processor is configured as client application. The client
creates an anonymous message queue. The client also creates and manages
the message pool. The client's return address is set in the message
header for each message before sending it to the server.

1. Run top level  make command to build R5F-0 and HOST binaries. Output files are created under debug and release sub folders

 - AM65XX_bios_elf\\ex02_messageq\\host\\bin\\debug : HOST A15 binary
 - AM65XX_bios_elfex02_messageq\\r5f-0\\bin\\debug : R5 binary

2. Follow procedure to initialize platform and launch target configuration through steps outlined
   in the hardware setup guide.

3. Right click R5 core 0 and connect target.

4. **Load R5F-0** messageQ Example out file(server_r5f-0.xer5fg) onto R5F core 0.

5. Right click CortexA53_0 and connect target.

6. **Load HOST** messageQ Example out file(app_host.xa53fg) onto ARM CortexA53_0.

7. Run both R5F-0 and HOST.

8. On CCS --> Tools --> RTOS Object view (ROV).

9. Suspend (halt) ARM Cortex_53 to view test messages on ROV Viewable Modules -->LoggerBuf 

10. Suspend (halt) R5F-0 and click on ROV icon to view log messages.
