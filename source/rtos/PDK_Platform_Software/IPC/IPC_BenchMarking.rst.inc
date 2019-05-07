.. http://processors.wiki.ti.com/index.php/IPC_BenchMarking 

MessageQBench
-----------------

The application utilizes the IPC 3.x stack to communicate from the main
processor to the slave core via the MessageQ interface. The application
measures the time taken to accomplish this.

Build
^^^^^^^

This section outlines the build process for the MessageQBench
application.

Linux
"""""""

To build the application, follow the `Linux IPC Install
Guide </index.php/IPC_Install_Guide_Linux>`__ to configure and build the
Linux-side applications for your device. You'll also need to build the
corresponding BIOS side of IPC as indicated in the guide.

QNX
"""""

To build the application, follow the `QNX IPC Install
Guide </index.php/IPC_Install_Guide_QNX>`__ to configure and build the
QNX-side test applications for your device. You'll also need to build
the corresponding BIOS side of IPC as indicated in the guide.

Android
"""""""""

The IPC development sources should be included in the Android Filesystem
(AFS) indicated by the manifest provided in your AFS distribution. The
sources are located in $(AFS_ROOT)/hardware/ti/ipc directory.

To build the IPC applications, follow the same procedure to build the
entire AFS. If you want to specifically build the IPC content, you can
issue the following command to build the needed IPC libraries and
application from the top your AFS installation (must configure and pick
the correct **lunch** target for your device).

::

    $buildhost make -j messageQApp \
                         messageQBench \
                         messageQMulti \
                         nameServerApp \
                         ping_rpmsg \
                         lad_dra7xx \
                         libmmrpc

To build the corresponding SysBios side of IPC follow the `IPC Install
Guide </index.php/IPC_Install_Guide_Linux>`__.

Run
^^^^^

This section illustrates the steps to run the MessageQBench application.

Linux/Android
"""""""""""""""

The built IPC libraries and applications must be copied (installed) onto
the devices filesystem. The LAD Daemon must be running and application's
corresponding slave-side binary must be loaded via the remoteproc kernel
module. The slave-side binary (messageq_single.x<suffix>), is located in
the $(IPC_ROOT)/packages/ti/ipc/tests/bin/<device> directory.

| 
| Detailed information regarding this can be found in the **Installing
  Tests** and **IPC Daemons and Drivers** section of the `IPC Install
  Guide </index.php/IPC_Install_Guide_Linux>`__.

| 

.. note::
  Android users - The Android binaries (lad_dra7xx and messageQBench) will
  be located in the $(AFS_ROOT)/out/target/product/<device>/system/binary
  directory. There are also dependent libraries (libtiipc.so,
  libtiipcutils.so, and libtiipcutils_lad.so) in the
  $(AFS_ROOT)/out/target/product/<device>/system/lib directory. These
  files need to be copied to your device filesystem for execution.

| 
| Once the LAD daemon is running and the slave core binary has been
  loaded. You can execute the following to run the application:

::

    target# /usr/bin/MessageQBench

The application will exchange 1000 messages with a payload of 8 by
default with an average round trip time per message. The following is
the usage parameters for the application.

::

    Usage: ./bin/MessageQBench [<numLoops>] [<payloadSize>] [<ProcId>]
           Defaults: numLoops: 1000; payloadSize: 8, ProcId: 1

QNX
"""""

The built IPC libraries and test applications must be copied (installed)
onto the devices filesystem. The IPC resource manager must be running
and the application's corresponding slave-side binary must be loaded
using the resource manager. The slave-side binary
(messageq_single.x<suffix>), is located in the
$(IPC_ROOT)/packages/ti/ipc/tests/bin/<device> directory.

| 
| Detailed information regarding this can be found in the **Installing
  Tests in QNX**, **IPC resource manager** and **Running Test
  Applications** sections of the `IPC Install
  Guide </index.php/IPC_Install_Guide_QNX>`__.

Once the IPC resource manager is running and the slave core binary has
been loaded. You can execute the following to run the application:

::

    target#  tests/MessageQBench 1000 8 <slave core procId>

The application will exchange 1000 messages with a payload of 8 with the
core identified by 'procId' and show an average round trip time per
message. The following shows the usage parameters for the application.

::

    Syntax:
      MessageQBench [<numLoops>] [<payloadSize>] [<procId>]

.. raw:: html

