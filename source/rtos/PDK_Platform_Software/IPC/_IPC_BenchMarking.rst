.. http://processors.wiki.ti.com/index.php/IPC_BenchMarking 


RTOS IPC Benchmark applications in SDK
--------------------------------------

Processor SDK RTOS includes a ping_benchmark_example under processor_sdk_rtos_<platform>_<version>/demos/ipc-examples/ping_benchmark_example.
This example shows multiple cores running RTOS communicating with each other through the IPC MessageQ API.
The example measures and displays the round trip delay numbers for the IPC. Note the main example sends multiple messages from each of the cores, with all the cores sending messages simultaneously.
The example can be built with option to just R5F0 as the originator and all the other cores just respond back with reply.

Build
^^^^^^^
The example can be built by running the top level make from the processor_sdk_rtos_<platform>_<version> directory.

Linux Host
""""""""""
::

	cd processor_sdk_rtos_<platform>_<version>
	make sdk_ipc_examples_all

Windows Host
""""""""""""

cd processor_sdk_rtos_<platform>_<version>
setupenv.bat
gmake sdk_ipc_examples_all

Once the build commands are executed, the binaries will be in their respective directories as follows.

AM65X:

::

	Host A53: ./demos/ipc-examples/ping_benchmark_example/hosta53/bin/am65xx_evm/release/server_host.xa53fg
	R5F-0:    ./demos/ipc-examples/ping_benchmark_example/r5f-0/bin/am65xx_evm/release/server_r5f-0.xer5f
	R5F-1:    ./demos/ipc-examples/ping_benchmark_example/r5f-1/bin/am65xx_evm/release/server_r5f-1.xer5f


And also the R5F0 only as sender images are here:

::

	Host A53: ./demos/ipc-examples/ping_benchmark_example/hosta53/bin/am65xx_evm/app_r5f0_only/release/server_host.xa53fg
	R5F-0:    ./demos/ipc-examples/ping_benchmark_example/r5f-0/bin/am65xx_evm/app_r5f0_only/release/server_r5f-0.xer5f
	R5F-1:    ./demos/ipc-examples/ping_benchmark_example/r5f-1/bin/am65xx_evm/app_r5f0_only/release/server_r5f-1.xer5f


Also the SBL bootable images can be created by using the following commands

Linux Host:

::

	make sdk_ipc_examples_app
	make sdk_ipc_examples_app_r5f0_only

Windows host:

::
	gmake sdk_ipc_examples_app
	gmake sdk_ipc_examples_app_r5f0_only

The application images will be located under:

::

	demos/ipc-examples/ping_benchmark_example/output.appimage
	demos/ipc-examples/ping_benchmark_example/am65xx_evm/app_r5f0_only/output.appimage

Run
^^^^

Pre-requisites: Bootable SD card loaded with SBL.

AM65x
""""""""""

Load the app from this directory into the SD card with filename "app" and load into the EVM to boot.
(Note: Make sure the UART port is connected to the terminal to observe the application prints)

On running the application the benchmark data will be displayed on the UART port.

For the main application the benchmark data will be displayed on UART port0:

::

	 Overhead:34

	 Payload Size: 176 

	 Proc id 0, Delta count: 3829025 

	 Proc id 0 to Proc Id 0: Average Roundtrip time is: 19 us 

	 Proc id 1, Delta count: 8920087 

	 Proc id 0 to Proc Id 1: Average Roundtrip time is: 44 us 

	 Proc id 2, Delta count: 7091251 

	 Proc id 0 to Proc Id 2: Average Roundtrip time is: 35 us 

	 AppHost_run: Test Passed 

	 MainHost_appTskFxn: Test Passed


For the R5F0 app only build, the benchmark data will be displayed on UART port1:

::

	 Overhead:144

	 Payload Size: 176 

	 Proc id 0, Delta count: 8460883 

	 Proc id 1 to Proc Id 0: Average Roundtrip time is: 42 us 

	 Proc id 1, Delta count: 1046906 

	 Proc id 1 to Proc Id 1: Average Roundtrip time is: 5 us 

	 Proc id 2, Delta count: 6297313 

	 Proc id 1 to Proc Id 2: Average Roundtrip time is: 31 us 

	 AppR5f_0_run: Test Passed

Linux Benchmark test: MessageQBench
-----------------------------------

The application utilizes the IPC 3.x stack to communicate from the main
processor to the slave core via the MessageQ interface. The application
measures the time taken to accomplish this. The MessageQBench binaries 
are included in the Linux file system and they are located in:

|   Linux Application: /usr/bin/MessageQBench
|   DSP binary:        /lib/firmware/ipc/ti_platforms_[platform]_core0/messageq_single.xe66
|

The MessageQBench can be built following the instruction described in
the below Build section or using high level build in Linux Processor
SDK as described in `IPC Quick Start Guide
<http://software-dl.ti.com/processor-sdk-linux/esd/docs/latest/linux/
Foundational_Components_IPC.html#ipc-quick-start-guide>`__

Build
^^^^^^^

This section outlines the build process for the MessageQBench
application.

Linux
"""""""

To build the application, follow the `Linux IPC Install
Guide <index_Foundational_Components.html#linux-install-guide>`__ to configure and build the
Linux-side applications for your device. You'll also need to build the
corresponding BIOS side of IPC as indicated in the guide.

QNX
"""""

To build the application, follow the `QNX IPC Install
Guide <index_Foundational_Components.html#qnx-install-guide>`__ to configure and build the
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
Guide <index_Foundational_Components.html#linux-install-guide>`__.

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
  Guide <index_Foundational_Components.html#linux-install-guide>`__.

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
  Guide <index_Foundational_Components.html#qnx-install-guide>`__.

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


IPC Performance
----------------

The performance numbers in this section are gathered using Processor SDK
5.2 release. 

IPC Average Round Trip Time
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The average round trip time is measured using MessageQBench which calculates
the time for sending 1000 messages from the main processor to slave core and
divided by the number of messages sent (1000).

Average Round Trip Time (ARTT) for K2H/E/G and OMAP-L138 EVMs

.. csv-table::
    :header: "PLSDK 5.2","K2H","K2E","K2G","OMAP-L138"

    "CPU Speed","1.2GHz","1.4GHz","1GHz","456MHz"
    "ARTT (us)","115","68","81","904"
    "ARTT @ 1GHz (us)","121","94","81","N/A"

Table: IPC Average Round Trip Time (ARTT)

.. note::
   The MessageQBench is a user space application which needs to call into
   kernel space and involves linux context switch, process priority, and
   multiple copies during the delivery of a message. Each message may show
   different latency deviated from the average round trip time. 


Throughput
^^^^^^^^^^^^^^

Throughput benchmark uses a max transmit window of 130 outstanding messages
to get the maximum throughput. Beyond the max transit window of 130, there
won't be enough resource to allocate additional messages before the
resource is returned by the outstanding messages. In this case, the
benchmark application will fail to run. Different payload sizes from 8 bytes
to max of 448 bytes are measured for each direction, and the numbers apply to
either direction. The throughput are measured with ARM/DSP running at 1 GHz.

Throughput for K2H/E/G and OMAP-L138 EVMs

.. csv-table::
    :header: "Payload (Bytes)","K2H (MB/s)","K2E (MB/s)","K2G (MB/s)","OMAP-L138 (MB/s)"

    "8","0.234","0.442","0.265","0.065"
    "16","0.362","0.681","0.333","0.099"
    "32","0.599","1.078","0.548","0.163"
    "64","1.073","1.928","1.101","0.286"
    "128","1.833","3.57","2.116","0.524"
    "256","3.288","6.693","5.855","0.988"
    "448(Max)","5.038","11.056","18.967","1.676"

Table: IPC Throughput

IPC Throughput CPU Utilization
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The CPU utilization is measured using max payload size of 448 bytes with
transmit window of 130 messages.

.. csv-table::
    :header: "","K2H (1.2GHz)","K2E (1.4GHz)","K2H (1GHz)","K2E (1GHz)","K2G","OMAP-L138"

    "CPU Utilization","42%","47%","44%","49%","89.5%","100%"

Table: IPC Throughput CPU Utilization


