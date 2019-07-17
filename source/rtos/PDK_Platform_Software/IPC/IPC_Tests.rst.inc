.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide/Tests 

Overview
-----------

The IPC product contains unit tests under the following directories.

-  linux/src/tests
-  qnx/src/tests
-  packages/ti/ipc/tests

These are meant to be used as unit tests and documentation of the tests
are currently sparse.

Linux Unit tests
^^^^^^^^^^^^^^^^^^^^

These tests under linux/src/tests have a Linux host application binary
and the binaries for the respective slave cores used in the test are
located under packages/ti/ipc/tests.

**NOTE**: Loading of the slave cores in general is achieved by using
remoteproc or MPM control procedures, which are specific to the platform
and are out of scope for this page.

Single thread MessageQ tests
"""""""""""""""""""""""""""""

MessageQApp: Sends single messages to slave cores and gets messages sent
back from slave cores.

Msgq100: Specific unit test to test MessageQ_get when messages are
available from more than one remote core.

MessageQBench: Send and get back single messages and measures round trip
delay.

These unit test binaries can be built with the following commands ( See
`IPC Linux Install Guide <index_Foundational_Components.html#linux-install-guide>`_ for more
details on setting up variables)

::

       make -f ipc-linux.mak config
       make
       make install

NOTE: The Host linux binaries are located at the DESTDIR/bin.

| 
| All these tests use the messageq_single.\* binaries loaded on the
  slave cores.

For example:

For the ipu1 core on AM57x/DRA7xx use:

::

       ./packages/ti/ipc/tests/bin/ti_platforms_evmDRA7XX_ipu1/messageq_single.xem4

For all the DSP cores on K2HK use:

::

       ./packages/ti/ipc/tests/bin/ti_platforms_evmTCI6638K2K_core0/messageq_single.xe66

Running single Message tests
'''''''''''''''''''''''''''''

The following procedures assume that all the relevant slave cores are
already loaded and running.

MessageQApp

Syntax:

::

       MessageQApp <number of Messages> <Core num>

(e.g)

::

       MessageQApp 100 1

Msgq

::

       Msgq100 [-l|h] procId1 procId2 ....

(e.g)

::

       Prints list of available remote processors
       Msgq100 -l
       Run test with remote processor with id 1
       Msgq100 1
       Run test with remote processors with id 1 and 2
       Msgq100 1 2

MessageQBench

Syntax:

::

       MessageQBench <number of Messages> <Core num>

(e.g)

::

       MessageQBench 100 1

| 

ping_rpmsg
"""""""""""""

./linux/src/tests/usr/bin/ping_rpmsg: Sends ping messages and receives
back messages.

This test uses **ping_rpmsg**.\* binaries loaded on the slave cores.

For example for the ipu1 core on AM57x/DRA7xx use:

::

       ./packages/ti/ipc/tests/bin/ti_platforms_evmDRA7XX_ipu1/ping_rpmsg.xem4

Run ping_rpmsg
''''''''''''''''''

On the linux console run the following command

syntax:

::

       ping_rpmsg [num_iterations]

(e.g)

::

       ping_rpmsg
       ping_rpmsg 100

| 

NameServerApp
""""""""""""""""

./linux/src/tests/.libs/NameServerApp: NameServer test

This test uses NameServerApp.\* binaries loaded on the slave cores.

For example for the ipu1 core on AM57x/DRA7xx use:

::

       ./packages/ti/ipc/tests/bin/ti_platforms_evmDRA7XX_ipu1/NameServerApp.xem4

Run NameServerApp
'''''''''''''''''''

With the slave processors loaded execute the following command.

::

       NameServerApp

| 

MessageQMulti
""""""""""""""""

./linux/src/tests/.libs/MessageQMulti: Sends and receives with multiple
threads

This test uses messageq_multi.\* images loaded on the slave cores.

For example for the ipu1 core on AM57x/DRA7xx use:

::

       ./packages/ti/ipc/tests/bin/ti_platforms_evmDRA7XX_ipu1/messageq_multi.xem4

Running MessageQMulti
''''''''''''''''''''''

With the slave cores loaded and running. Use the following command to
run the Linux application.

(e.g)

::

       MessageQMulti

| 

MessageQMultiMulti
"""""""""""""""""""

./linux/src/tests/.libs/MessageQMultiMulti: Sends and receives multiple
messages with multiple threads to multiple cores.

NOTE: This test needs all the slave cores in the SOC to be loaded and
running.

This uses **messageq_multimulti.\*** images loaded on the slave cores.

For example for the ipu1 core on AM57x/DRA7xx use:

::

       ./packages/ti/ipc/tests/bin/ti_platforms_evmDRA7XX_ipu1/messageq_multimulti.xem4

Running MessageQMultiMulti
''''''''''''''''''''''''''''

With all the slave cores loaded and running. Use the following command
to run the Linux application.

(e.g)

::

       MessageQMultiMulti

| 

fault
"""""""

./linux/src/tests/.libs/fault: Test fault handling

NOTE: This test needs all the slave cores in the SOC to be loaded and
running.

This uses fault.\* images loaded on the slave cores.

For example for the ipu1 core on AM57x/DRA7xx use:

::

       ./packages/ti/ipc/tests/bin/ti_platforms_evmDRA7XX_ipu1/fault.xem4

Running fault
''''''''''''''

With all the slave cores loaded and running. Use the following command
to run the Linux application.

(e.g)

::

       fault

| 

Qnx Unit tests
^^^^^^^^^^^^^^^^^^^^

These tests under qnx/src/tests have a Qnx host application binary and
the binaries for the respective slave cores used in the test are located
under packages/ti/ipc/tests.

.. note::
  Loading of the slave cores in general is achieved by using the
  ipc binary.

Single thread MessageQ tests
"""""""""""""""""""""""""""""

MessageQApp: Sends single messages to slave cores and gets messages sent
back from slave cores.

MessageQBench: Send and get back single messages and measures round trip
delay.

These unit test binaries can be built with the following commands ( See
`IPC QNX Install Guide <index_Foundational_Components.html#qnx-install-guide>`_ for more
details on setting up variables)

::

       make -f ipc-qnx.mak all
       make -f ipc-qnx.mak install

All these tests use the messageq_single.\* binaries loaded on the
  slave cores.

For example:

For the ipu1 core on DRA7xx use:

::

       ./packages/ti/ipc/tests/bin/ti_platforms_evmDRA7XX_ipu1/messageq_single.xem4

Follow the instructions in the Install Guide for how to load images to
the remote cores.

Running single Message tests
'''''''''''''''''''''''''''''

The following procedures assume that all the relevant slave cores are
already loaded and running.

MessageQApp

Syntax:

::

       MessageQApp <number of Messages> <Core num>

(e.g)

::

       MessageQApp 100 1

MessageQBench

Syntax:

::

       MessageQBench <number of Messages> <Core num>

(e.g)

::

       MessageQBench 100 1

NameServerApp
""""""""""""""""

./qnx/src/tests/NameServerApp: NameServer test

This test uses NameServerApp.\* binaries loaded on the slave cores.

For example for the ipu1 core on DRA7xx use:

::

       ./packages/ti/ipc/tests/bin/ti_platforms_evmDRA7XX_ipu1/NameServerApp.xem4

Run NameServerApp
''''''''''''''''''

With the slave processors loaded execute the following command.

::

       NameServerApp

| 

MessageQMulti
""""""""""""""""

./qnx/src/tests/MessageQMulti: Sends and receives with multiple threads

This test uses messageq_multi.\* images loaded on the slave cores.

For example for the ipu1 core on DRA7xx use:

::

       ./packages/ti/ipc/tests/bin/ti_platforms_evmDRA7XX_ipu1/messageq_multi.xem4

Running MessageQMulti
''''''''''''''''''''''''

With the slave cores loaded and running. Use the following command to
run the Qnx application.

Syntax:

::

       Usage: MessageQMulti <number of threads> <number of loops> <number of processes>
       Defaults: number of threads: 10
                 number of loops: 1000
                 number of processes: 1
       Note: If number of processes is set, number of threads is forced to 1

(e.g)

::

       MessageQMulti 10 10

Fault
"""""""

./qnx/src/tests/Fault: Test fault handling

This uses fault.\* images loaded on the slave cores.

For example for the ipu1 core on DRA7xx use:

::

       ./packages/ti/ipc/tests/bin/ti_platforms_evmDRA7XX_ipu1/fault.xem4

Running fault
''''''''''''''''

With all the slave cores loaded and running. Use the following command
to run the Qnx application.

Syntax:

::

       Fault <-f <fault_num>> <number of loops> <core num>
       Where <fault num> is:
           0: No fault
           1: MMU read fault
           2: MMU write fault
           3: MMU program fault
           4: Exception
           5: Watchdog

(e.g)

::

       Fault -f1 10 2

GateMPApp
""""""""""

./qnx/src/tests/GateMPApp: Test the GateMP Module

This uses the gatempapp.xe66 image loaded on the DSP1 slave core.

For example for the dsp1 core on DRA7xx use:

::

       ./packages/ti/ipc/tests/bin/ti_platforms_evmDRA7XX_dsp1/gatempapp.xe66

Running GateMPApp
'''''''''''''''''''

With the DSP1 slave core loaded and running. Use the following command
to run the Qnx application.

Syntax:

::

       GateMPApp 

mmrpc_test
"""""""""""

./qnx/src/tests/mmrpc_test: Test the MmRpc API

This uses the test_omx_<core>_vayu.\* images loaded on the slave cores.

For example for the dsp1 core on DRA7xx use:

::

       ./packages/ti/ipc/tests/bin/ti_platforms_evmDRA7XX_dsp1/test_omx_ipu1_vayu.xem4

Running mmrpc_test
""""""""""""""""""""

With the slave cores loaded and running. Use the following command to
run the Qnx application.

Syntax:

::

       mmrpc_test <Core num>

(e.g.)

::

       mmrpc_test 1

.. raw:: html

