.. include:: /replacevars.rst.inc

.. _foundational-components-ipc:

IPC for AM62x
=============

The AM62x processor has a Cortex-M4F subsystem, in addition to a Quad core
Cortex-A53 subsystem. Please refer to the AM62x Technical Reference Manual
for details.

This article is geared toward AM62x users that are running Linux on the Cortex
A53 cores. The goal is to help users understand how to establish communication
with the M4F core.

There are many facets to this task: building, loading, debugging, memory
sharing, etc. This article intends to take incremental steps toward
understanding all of those pieces.

Software Dependencies to Get Started
------------------------------------

Prerequisites

-  Processor SDK Linux for AM62x |__SDK_DOWNLOAD_URL__|.
-  `Processor SDK MCU+ for
   AM62x <https://www.ti.com/tool/download/MCU-PLUS-SDK-AM62X>`__

.. note::
   Please be sure that you have the same version number
   for both Processor SDK RTOS and Linux.

Please refer to the MCU+SDK documentation, section "Developer Guides" -> "Understanding
inter-processor communication (IPC)" for M4F IPC architecture and builds.

Typical Boot Flow on AM62x for ARM Linux users
----------------------------------------------

AM62x SOC's have multiple processor cores - Cortex-A53, and a Cortex-M4F ARM core.
The A53 typically runs a HLOS like Linux/Android. The M4F remote core runs No-OS
or RTOS (FreeRTOS etc). In normal operation, the boot loader (U-Boot/SPL) boots
and loads the A53 with the HLOS. The A53 then boots the M4F core.

.. note::
    Please note early boot is not yet supported on AM62x devices.

Getting Started with IPC Linux Examples
---------------------------------------

The figure below illustrates how the Remoteproc/RPMsg driver from the ARM Linux
kernel communicates with the IPC driver on a remote processor (e.g. M4F)
running RTOS.

.. Image:: /images/LinuxIPC_with_RTOS_Slave.png

In order to setup IPC on remote cores, we provide some pre-built examples
in the SDK package that can be run from ARM Linux.

The remoteproc driver is hard-coded to look for specific files when
loading the M4F core. Here are the files it looks for on an AM62x device:

::

	+------------------+-----------------+--------------------+----------------------+
	| Core Name        | RemoteProc Name | Description        | Firmware File Name   |
	+==================+=================+====================+======================+
	| M4F              | 5000000.m4f     | M4F core           | am62-mcu-m4f0_0-fw   |
	+------------------+-----------------+--------------------+----------------------+

Generally on a target file system the above files are soft linked to the
intended executable FW files:

::

	root@am62xx-evm:/opt/ltp# ls -l /lib/firmware
	...
	lrwxrwxrwx 1 root root      72 May 21  2022 am62-mcu-m4f0_0-fw -> /lib/firmware/pdk-ipc/ipc_echo_baremetal_test_mcu2_0_release_strip.xer5f


.. _booting_remote_cores_from_Linux_console:

Booting Remote Cores from Linux console/User space
--------------------------------------------------

To reload a remote core with new executables, please follow the below steps.

First, identify the remotproc node associated with the remote core:

::

	root@am62xx-evm:~# head /sys/class/remoteproc/remoteproc*/name
	==> /sys/class/remoteproc/remoteproc0/name <==
	5000000.m4fss

	==> /sys/class/remoteproc/remoteproc1/name <==
	30074000.pru

	==> /sys/class/remoteproc/remoteproc2/name <==
	30078000.pru

Then, use the sysfs interface to stop the remote core. For example, to stop the M4F

::

	root@am62xx-evm:~# echo stop > /sys/class/remoteproc/remoteproc0/state
	[  440.832317] remoteproc remoteproc0: stopped remote processor 5000000.m4fss

If needed, update the firmware symbolic link to point to a new firmware:

::

	root@am62xx-evm:/lib/firmware# ln -sf /lib/firmware/pdk-ipc/ipc_echo_baremetal_test_mcu2_0_release_strip.xer5f am62-mcu-m4f0_0-fw

Finally, use the sysfs interface to start the remote core:

::

	root@am62xx-evm:~# echo start > /sys/class/remoteproc/remoteproc0/state
	[  450.930070] remoteproc remoteproc0: powering up 5000000.m4fss
	[  450.936112] remoteproc remoteproc0: Booting fw image am62-mcu-m4f0_0-fw, size 78960
	[  450.960447]  remoteproc0#vdev0buffer: assigned reserved memory node m4f-dma-memory@9cb00000
	[  450.969408] virtio_rpmsg_bus virtio0: rpmsg host is online
	[  450.975089] virtio_rpmsg_bus virtio0: creating channel ti.ipc4.ping-pong addr 0xd
	[  450.975850]  remoteproc0#vdev0buffer: registered virtio0 (type 7)
	[  450.982840] virtio_rpmsg_bus virtio0: creating channel rpmsg_chrdev addr 0xe
	[  450.988824] remoteproc remoteproc0: remote processor 5000000.m4fss is now up

.. note::

   The RemoteProc driver does not support a graceful shutdown of the M4 core
   in the current Linux Processor SDK. For now, it is recommended to reboot the
   board when loading new binaries into the M4F core.

DMA memory Carveouts
--------------------

System memory is carved out for each remote processor core for IPC and for the
remote processor's code/data section needs. The default
memory carveouts (DMA pools) are shown below.

See the devicetree bindings documentation for more details: `Documentation/devicetree/bindings/remoteproc/ti,k3-r5f-rproc.yaml <https://git.ti.com/cgit/ti-linux-kernel/ti-linux-kernel/tree/Documentation/devicetree/bindings/remoteproc/ti,k3-r5f-rproc.yaml?h=ti-linux-5.10.y>`__

::

	+------------------+--------------------+---------+----------------------------+
	| Memory Section   | Physical Address   | Size    | Description                |
	+==================+====================+=========+============================+
	| M4F Pool         | 0x9cb00000         | 1MB     | IPC (Virtio/Vring buffers) |
	+------------------+--------------------+---------+----------------------------+
	| M4F Pool         | 0x9cc00000         | 15MB    | M4F externel code/data mem |
	+------------------+--------------------+---------+----------------------------+

	root@am62xx-evm:~# dmesg | grep Reserved
	[    0.000000] Reserved memory: created DMA memory pool at 0x000000009cb00000, size 1 MiB
	[    0.000000] Reserved memory: created DMA memory pool at 0x000000009cc00000, size 15 MiB
	[    0.000000] Reserved memory: created DMA memory pool at 0x000000009db00000, size 12 MiB
	[    0.000000] cma: Reserved 144 MiB at 0x00000000f4000000

By default the first 1MB of each pool is used for the Virtio and Vring buffers
used to communicate with the remote processor core. The remaining 15MB of the
carveout is used for the remote core external memory (program code, data, etc).

.. note::
    The resource table entity (which describes the system resources needed by
    the remote
    processor) needs to be at the beginning of the 15MB remote processor
    external memory section.


For details on how to adjust the sizes and locations of the remote core pool
carveouts, please see section :ref:`changing_the_memory_map`.

.. _changing_the_memory_map:

Changing the Memory Map
---------------------------

The address and size of the DMA memory carveouts needs to match with the MCU
M4F external memory section sizes in their linker mapfiles.

linux/arch/arm64/boot/dts/ti/k3-am625-sk.dts

::

		reserved-memory {
				#address-cells = <2>;
				#size-cells = <2>;
				ranges;

			mcu_m4fss_dma_memory_region: m4f-dma-memory@9cb00000 {
				compatible = "shared-dma-pool";
				reg = <0x00 0x9cb00000 0x00 0x100000>;
				no-map;
			};

			mcu_m4fss_memory_region: m4f-memory@9cc00000 {
				compatible = "shared-dma-pool";
				reg = <0x00 0x9cc00000 0x00 0xf00000>;
				no-map;
			};
		};


.. warning:: Be careful not to overlap carveouts!

RPMsg Char Driver
-----------------

The below picture depicts the kernel driver components and the user space device
model for using RPMsg Char driver for communicating with the remote processor.

.. Image:: /images/RPMsgstack-linux.png

The RPMsg char driver exposes RPMsg endpoints to user-space processes. Multiple
user-space applications can use one RPMsg device uniquely by requesting
different interactions with the remote service. The RPMsg char driver supports
the creation of multiple endpoints for each probed RPMsg char device, enabling
the use of the same device for different instances.

.. rubric:: RPMsg devices

Each created endpoint device shows up as a single character device in /dev.

The RPMsg bus sits on top of the VirtIO bus. Each virtio name service
announcement message creates a new RPMsg device, which is supposed to bind to a
RPMsg driver. RPMsg devices are created dynamically:

The remote processor announces the existence of a remote RPMsg service by
sending a name service announcement message containing the name of the service
(i.e. name of the device), source and destination addresses. The message is
handled by the RPMsg bus, which dynamically creates and registers an RPMsg
device which represents the remote service. As soon as a relevant RPMsg driver
is registered, it is immediately probed by the bus and the two sides can start
exchanging messages.

.. rubric:: The control interface

The RPMsg char driver provides control interface (in the form of a character
device under /dev/rpmsg_ctrlX) allowing user-space to export an endpoint
interface for each exposed endpoint. The control interface provides a
dedicated ioctl to create an endpoint device.

ti-rpmsg-char library
---------------------
The ti-rpmsg-char package is located at the `ti-rpmsg-char git repo
<https://git.ti.com/cgit/rpmsg/ti-rpmsg-char>`.

A thin userspace rpmsg char library is provided. The library abstracts the rpmsg
char driver usage from userspace. This library provides an easy means to
identify and open rpmsg character devices created by the kernel rpmsg-char
driver.

This library support TI K3 family of devices (i.e AM65x, AM64x, AM62x, J721E, and
J7200 SoCs).

The library provides 4 basic APIs wrapping all the rpmsg char driver calls.
`Please check documentation in 'include/ti_rpmsg_char.h' for details.
<https://git.ti.com/cgit/rpmsg/ti-rpmsg-char/tree/include/ti_rpmsg_char.h>`__.

rpmsg_char_init()
    This function checks that the needed kernel drivers (remoteproc. rpmsg,
    virtio) are installed and accessible from the user space. Further it
    also checks the SoC device supports the requested remote processor.

rpmsg_char_exit()
    This function finalizes and performs all the de-initialization and any
    cleanup on the library. This is the last function that needs to be invoked
    after all usage is done as part of the application's cleanup. This only need
    to be invoked once in an application, there is no reference counting. The
    function also needs to be invoked in any application's signal handlers to
    perform the necessary cleanup of stale rpmsg endpoint devices.

rpmsg_char_open()
    Function to create and access a rpmsg endpoint device for a given rpmsg
    device.

rpmsg_char_close()
    Function to close and delete a previously created local endpoint

`All remote proc ids are defined in rproc_id.h <https://git.ti.com/cgit/rpmsg/ti-rpmsg-char/tree/include/rproc_id.h>`__

The below table lists the device enumerations as defined in the rpmsg_char_library. The validity of the enumerations wrt AM62x is also specified.
::

	+------------------+--------------------+---------+-----------------------------------+
	| Enumeration ID   | Device Name        | Valid   | Description                       |
	+==================+====================+=========+===================================+
	| M4F_MCU0_0       | 5000000.m4f        | Yes     | M4F core in MCU Domain            |
	+------------------+--------------------+---------+-----------------------------------+

RPMsg examples:
---------------

.. rubric:: RPMsg user space example

.. note::

   These steps were tested on Ubuntu 18.04.
   Later versions of Ubuntu may need different steps

Access source code in the git repo `here <https://git.ti.com/cgit/rpmsg/ti-rpmsg-char>`.
rproc_id is defined at `include/rproc_id.h <https://git.ti.com/cgit/rpmsg/ti-rpmsg-char/tree/include/rproc_id.h>`.

Build the Linux Userspace example for Linux RPMsg by following the steps
in the top-level README:

#. Download the git repo

#. Install GNU autoconf, GNU automake, GNU libtool, and v8 compiler as per the
   README

#. Perform the Build Steps as per the README

Linux RPMsg can be tested with prebuilt binaries that are packaged in the
"tisdk-default-image-am62xx-evm" filesystem:

#. Copy the Linux RPMsg Userspace application from
   <ti-rpmsg-char_repo>/examples/rpmsg_char_simple into the board's Linux
   filesystem.

#. Ensure that the remote core symbolic link points to the desired binary file
   in /lib/firmware/pdk-ipc/. Update the symbolic link if needed. Reference
   section :ref:`booting_remote_cores_from_Linux_console` for more information.

#. Run the example on the board:

::

	Usage: rpmsg_char_simple [-r <rproc_id>] [-n <num_msgs>] [-d <rpmsg_dev_name] [-p <remote_endpt]
			Defaults: rproc_id: 0 num_msgs: 100 rpmsg_dev_name: NULL remote_endpt: 14

	root@am62xx-evm:~# rpmsg_char_simple -r 9 -n 10
	Created endpt device rpmsg-char-9-989, fd = 3 port = 1024
	Exchanging 10 messages with rpmsg device ti.ipc4.ping-pong on rproc id 9 ...

	Sending message #0: hello there 0!
	Receiving message #0: hello there 0!
	Sending message #1: hello there 1!
	Receiving message #1: hello there 1!
	Sending message #2: hello there 2!
	Receiving message #2: hello there 2!
	Sending message #3: hello there 3!
	Receiving message #3: hello there 3!
	Sending message #4: hello there 4!
	Receiving message #4: hello there 4!
	Sending message #5: hello there 5!
	Receiving message #5: hello there 5!
	Sending message #6: hello there 6!
	Receiving message #6: hello there 6!
	Sending message #7: hello there 7!
	Receiving message #7: hello there 7!
	Sending message #8: hello there 8!
	Receiving message #8: hello there 8!
	Sending message #9: hello there 9!
	Receiving message #9: hello there 9!

	Communicated 10 messages successfully on rpmsg-char-9-989


.. rubric:: RPMsg kernel space example

The kernel space example is in the Linux Processor SDK under
samples/rpmsg/rpmsg_client_sample.c

Build the kernel module rpmsg_client_sample:

#. Set up the kernel config to build the rpmsg client sample. Use menuconfig to
   verify Kernel hacking > Sample kernel code > Build rpmsg client sample is M:

::

    $ export PATH=<sdk path>/linux-devkit/sysroots/x86_64-arago-linux/usr/bin:$PATH
    $ make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- distclean
    $ make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- tisdk_am62xx-evm_defconfig
    $ make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- menuconfig

#. Make the kernel and modules. Multithreading with –j is optional:

::

    $ make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- -j8

Linux RPMsg can be tested with prebuilt binaries that are packaged in the
"tisdk-default-image-am62xx-evm" filesystem:

#. Copy the Linux RPMsg kernel driver from
   <Linux_SDK>/board-support/linux-x.x.x/samples/rpmsg/rpmsg_client_sample.ko
   into the board's Linux filesystem.

#. Ensure that the remote core symbolic link points to the desired binary file
   in /lib/firmware/pdk-ipc/. Update the symbolic link if needed. Reference
   section :ref:`booting_remote_cores_from_Linux_console` for more information.

#. Run the example on the board:

::

	root@am62xx-evm:~# modprobe rpmsg_client_sample count=10
	[  192.754123] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: new channel: 0x400 -> 0xd!
	[  192.762614] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 1 (src: 0xd)
	[  192.767945] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: new channel: 0x400 -> 0xd!
	[  192.778102] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 2 (src: 0xd)
	[  192.787125] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: new channel: 0x400 -> 0xd!
	[  192.793103] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 3 (src: 0xd)
	[  192.799752] rpmsg_client_sample virtio3.ti.ipc4.ping-pong.-1.13: new channel: 0x400 -> 0xd!
	[  192.809324] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 4 (src: 0xd)
	[  192.823064] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 5 (src: 0xd)
	[  192.833132] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 6 (src: 0xd)
	[  192.843179] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 7 (src: 0xd)
	[  192.853170] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 8 (src: 0xd)
	[  192.863228] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 9 (src: 0xd)
	[  192.873335] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 10 (src: 0xd)
	[  192.883392] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: goodbye!
	[  192.891964] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 1 (src: 0xd)
	[  192.902022] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 2 (src: 0xd)
	[  192.912136] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 3 (src: 0xd)
	[  192.922181] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 4 (src: 0xd)
	[  192.932270] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 5 (src: 0xd)
	[  192.942319] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 6 (src: 0xd)
	[  192.952403] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 7 (src: 0xd)
	[  192.962433] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 8 (src: 0xd)
	[  192.972538] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 9 (src: 0xd)
	[  192.982616] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 10 (src: 0xd)
	[  192.992836] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: goodbye!
	[  193.001472] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 1 (src: 0xd)
	[  193.011614] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 2 (src: 0xd)
	[  193.020184] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 3 (src: 0xd)
	[  193.028628] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 4 (src: 0xd)
	[  193.037089] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 5 (src: 0xd)
	[  193.045484] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 6 (src: 0xd)
	[  193.053874] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 7 (src: 0xd)
	[  193.062261] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 8 (src: 0xd)
	[  193.070614] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 9 (src: 0xd)
	[  193.079000] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 10 (src: 0xd)
	[  193.087397] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: goodbye!
	[  193.094355] rpmsg_client_sample virtio3.ti.ipc4.ping-pong.-1.13: incoming msg 1 (src: 0xd)
	[  193.102729] rpmsg_client_sample virtio3.ti.ipc4.ping-pong.-1.13: incoming msg 2 (src: 0xd)
	[  193.111134] rpmsg_client_sample virtio3.ti.ipc4.ping-pong.-1.13: incoming msg 3 (src: 0xd)
	[  193.119512] rpmsg_client_sample virtio3.ti.ipc4.ping-pong.-1.13: incoming msg 4 (src: 0xd)
	[  193.127928] rpmsg_client_sample virtio3.ti.ipc4.ping-pong.-1.13: incoming msg 5 (src: 0xd)
	[  193.136292] rpmsg_client_sample virtio3.ti.ipc4.ping-pong.-1.13: incoming msg 6 (src: 0xd)
	[  193.144761] rpmsg_client_sample virtio3.ti.ipc4.ping-pong.-1.13: incoming msg 7 (src: 0xd)
	[  193.153207] rpmsg_client_sample virtio3.ti.ipc4.ping-pong.-1.13: incoming msg 8 (src: 0xd)
	[  193.161691] rpmsg_client_sample virtio3.ti.ipc4.ping-pong.-1.13: incoming msg 9 (src: 0xd)
	[  193.170119] rpmsg_client_sample virtio3.ti.ipc4.ping-pong.-1.13: incoming msg 10 (src: 0xd)
	[  193.178632] rpmsg_client_sample virtio3.ti.ipc4.ping-pong.-1.13: goodbye!
