.. http://processors.wiki.ti.com/index.php/IPC_Daemon

IPC Daemon (aka LAD)
====================

This topic is an overview of the daemon used by IPC on Linux. The IPC
daemon maintains any processor-wide state that's not specific to any
process or thread on the HLOS. For example, it contains the
`MultiProc <index_Foundational_Components.html#multiproc-module>`__
configuration (small database of what cores are in the system and their
unique IDs), the HLOS's
`NameServer <index_Foundational_Components.html#nameserver-module>`__ database,
among other misc.

The IPC daemon was forked from the `Link Arbiter
Daemon <http://processors.wiki.ti.com/index.php/Link_Arbiter_Daemon>`__, used in DSP Link systems -
and while the daemon still contains 'lad' in it's name, LAD isn't really
an applicable acronym for anything. (But creative suggestions are
welcome!)

Approach
--------

The IPC Daemon is a separate process from other IPC-using applications.

The IPC Daemon must be started **after** the slaves have been loaded,
but before any application using IPC is run. Applications connect to the
IPC Daemon during the call to Ipc_start() and disconnect during the call
to Ipc_stop().

At startup, the daemon creates a FIFO (named pipe) for listening for
connection requests from other user-mode clients. When a connection
request comes in, the daemon opens a dedicated FIFO for sending
responses to the client.

At run-time, LAD processes command in FIFO order, and these commands run
to completion before the next command is accepted.

Limitations
-----------

Startup Before Any Clients
^^^^^^^^^^^^^^^^^^^^^^^^^^

The IPC daemon needs to be explicitly started before any client
applications call Ipc_start().

Maximum Number of Simultaneous Connections
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The maximum number of simultaneous client connections to the IPC daemon
is currently 32 (the value of LAD_MAXNUMCLIENTS). Meaning, at most 32
client applications can call Ipc_start() at any given time.

Hard-coded MultiProc configuration
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

For a given device, the MultiProc configuration is predefined in a C
struct within the daemon. If you want to subset the MultiProc list, you
have to modify this struct and rebuild the daemon. And be sure to be
consistent with that MultiProc configuration in each of the slave images
as well.


