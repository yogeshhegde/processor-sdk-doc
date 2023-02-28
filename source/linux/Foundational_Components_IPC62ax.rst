.. include:: /replacevars.rst.inc

.. _foundational-components-ipc:

IPC for AM62ax
==============

The AM62ax processors have Cortex-R5F and C7x DSP subsystems in addition to
a Quad core Cortex-A53 subsystem. Please refer to the AM62ax Technical Reference Manual for details.

This article is geared toward AM62ax users that are running Linux on the Cortex
A53 cores. The goal is to help users understand how to establish IPC communication
with the C7x DSP and R5F cores.

There are many facets to this task: building, loading, debugging, memory
sharing, etc. This article intends to take incremental steps toward
understanding all of those pieces.

Software Dependencies to Get Started
------------------------------------

Prerequisites

-  Processor SDK Linux for AM62ax |__SDK_DOWNLOAD_URL__|.
-  `Processor SDK MCU+ for
   AM62ax <https://www.ti.com/tool/download/MCU-PLUS-SDK-AM62AX>`__

.. note::
   Please be sure that you have the same version number
   for both Processor SDK RTOS and Linux.

Please refer to the MCU+SDK documentation, section "Developer Guides" -> "Understanding
inter-processor communication (IPC)" for IPC architecture and builds.

Typical Boot Flow on AM62ax for ARM Linux users
-----------------------------------------------

AM62ax SOC's have multiple processor cores - Cortex-A53, Cortex-R5F and DSP cores.
The A53 typically runs a HLOS like Linux/Android. The C7x and R5F remote cores run No-OS
or RTOS (FreeRTOS etc). In normal operation, the boot loader (U-Boot/SPL) boots
and loads the A53 with the HLOS. The A53 then boots the C7x and R5F cores.

The wakeup R5F firmware runs device manager software (SciServer) along
with vision apps application.

The wakeup R5F firmware is integrated as part of tispl.bin binary
and is started early in the boot process by u-boot R5 SPL right after DDR initialization.


Getting Started with IPC Linux Examples
---------------------------------------

The figure below illustrates how the Remoteproc/RPMsg driver from the ARM Linux
kernel communicates with the IPC driver on a remote processors (e.g. R5F)
running RTOS.

.. Image:: /images/LinuxIPC_with_RTOS_Slave.png

In order to setup IPC on remote cores, we provide some pre-built examples
in the SDK package that can be run from ARM Linux.

The remoteproc driver is hard-coded to look for specific files when
loading the R5F and C7x cores. Here are the files it looks for on an AM62ax device:

::

	+------------------+-----------------+----------------------+----------------------+
	| Core Name        | RemoteProc Name | Description          | Firmware File Name   |
	+==================+=================+======================+======================+
	| C7x              | 7e000000.c7x    | C7x core             | am62a-c71_0-fw       |
	+------------------+-----------------+----------------------+----------------------+
	| R5F	           | 79000000.r5f    | R5F core(MCU domain) | am62a-mcu-r5f0_0-fw  |
	+------------------+-----------------+----------------------+----------------------+

Generally on a target file system the above files are soft linked to the
intended executable FW files:

::

	root@am62axx-evm:~# ls -l /lib/firmware/
	lrwxrwxrwx 1 root root      60 Feb  2  2023 am62a-c71_0-fw -> /lib/firmware/pdk-ipc/ipc_echo_test_c7x_1_release_strip.xe71
	lrwxrwxrwx 1 root root      41 Feb  2  2023 am62a-mcu-r5f0_0-fw -> /lib/firmware/pdk-ipc/am62a-mcu-r5f0_0-fw

For updating wakeup (DM) R5F firmware binary, tispl.bin needs to be recompiled with the new firmware binary as mentioned below :

#. Go to linux installer and replace the existing R5F wakeup (DM) firmware binary with the new one

::

    host#  cp <path_to_new_fw_binary>/ipc_echo_testb_freertos_mcu1_0_release.xer5f <path_to_linux_installer>/board-support/prebuilt-images/ipc_echo_testb_mcu1_0_release_strip.xer5f

#. Recompile u-boot to regenerate tispl.bin using the top level makefile.

::

    host# make u-boot

Please refer to `Top-Level Makefile <../../Overview/Top_Level_Makefile.html>`__ for more details on Top Level makefile.

#. Replace the updated tispl.bin containing new R5F firmware binary in the boot partition of sdcard and reboot

::

    host# sudo cp board-support/u-boot_build/a53/tispl.bin  /media/$USER/boot

.. _booting_remote_cores_from_Linux_console:

Booting Remote Cores from Linux console/User space
--------------------------------------------------

To reload a remote core with new executables, please follow the below steps.

First, identify the remotproc node associated with the remote core:

::

	root@am62axx-evm:~# head /sys/class/remoteproc/remoteproc*/name   
	==> /sys/class/remoteproc/remoteproc0/name <==
	7e000000.dsp

	==> /sys/class/remoteproc/remoteproc1/name <==
	79000000.r5f

	==> /sys/class/remoteproc/remoteproc2/name <==
	78000000.r5f


Then, use the sysfs interface to stop the remote core. For example, to stop the C71x

::

	root@am62axx-evm:~# echo stop > /sys/class/remoteproc/remoteproc0/state 
	[   61.497327] remoteproc remoteproc0: stopped remote processor 7e000000.dsp

If needed, update the firmware symbolic link to point to a new firmware:

::

	root@am62xx-evm:/lib/firmware# ln -sf /lib/firmware/pdk-ipc/ipc_echo_test_c7x_1_release_strip.xe71 am62a-c71_0-fw

Finally, use the sysfs interface to start the remote core:

::

	root@am62axx-evm:~# echo start > /sys/class/remoteproc/remoteproc0/state                                                           
	[   66.768814] remoteproc remoteproc0: powering up 7e000000.dsp
	[   66.776893] remoteproc remoteproc0: Booting fw image am62a-c71_0-fw, size 2100144
	[   66.785144] k3-dsp-rproc 7e000000.dsp: booting DSP core using boot addr = 0x9a000000
	[   66.836110]  remoteproc0#vdev0buffer: assigned reserved memory node c7x-dma-memory@99800000
	[   66.845052] virtio_rpmsg_bus virtio2: rpmsg host is online
	[   66.850813] virtio_rpmsg_bus virtio2: creating channel ti.ipc4.ping-pong addr 0xd
	[   66.851203]  remoteproc0#vdev0buffer: registered virtio2 (type 7)
	[   66.858507] virtio_rpmsg_bus virtio2: creating channel rpmsg_chrdev addr 0xe
	[   66.864574] remoteproc remoteproc0: remote processor 7e000000.dsp is now up

.. note::

   The RemoteProc driver does not support a graceful shutdown of R5 and DSP cores
   in the current Linux Processor SDK. For now, it is recommended to reboot the
   board when loading new binaries into an R5F or DSP core.

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
	| C7x Pool         | 0x99800000         | 1MB     | IPC (Virtio/Vring buffers) |
	+------------------+--------------------+---------+----------------------------+
	| C7x Pool         | 0x99900000         | 31MB    | C7x externel code/data mem |
	+------------------+--------------------+---------+----------------------------+
	| R5F(mcu) Pool    | 0x9b800000         | 1MB     | IPC (Virtio/Vring buffers) |
	+------------------+--------------------+---------+----------------------------+
	| R5F(mcu) Pool    | 0x9b900000         | 15MB    | R5F externel code/data mem |
	+------------------+--------------------+---------+----------------------------+
	| R5F(wkup) Pool   | 0x9c800000         | 1MB     | IPC (Virtio/Vring buffers) |
	+------------------+--------------------+---------+----------------------------+
	| R5F(wkup) Pool   | 0x9c900000         | 30MB    | R5F externel code/data mem |
	+------------------+--------------------+---------+----------------------------+

	root@am62axx-evm:/lib/firmware# dmesg | grep Reserved
	[    0.000000] Reserved memory: created DMA memory pool at 0x0000000099800000, size 1 MiB
	[    0.000000] Reserved memory: created DMA memory pool at 0x0000000099900000, size 30 MiB
	[    0.000000] Reserved memory: created DMA memory pool at 0x000000009b800000, size 1 MiB
	[    0.000000] Reserved memory: created DMA memory pool at 0x000000009b900000, size 15 MiB
	[    0.000000] Reserved memory: created DMA memory pool at 0x000000009c800000, size 1 MiB
	[    0.000000] Reserved memory: created DMA memory pool at 0x000000009c900000, size 30 MiB
	[    0.000000] Reserved memory: created DMA memory pool at 0x00000000a0300000, size 32 MiB
	[    0.000000] Reserved memory: created DMA memory pool at 0x00000000ae300000, size 288 MiB
	[    0.000000] cma: Reserved 512 MiB at 0x00000000dd000000

.. note:: The reserved memory sizes listed above are provided as a reference only and subject to change between releases. For latest memory reservations, please refer to the kernel device tree repository :
          'https://git.ti.com/cgit/ti-linux-kernel/ti-linux-kernel/tree/arch/arm64/boot/dts/ti/k3-am62a7-sk.dts?h=ti-linux-5.10.y'

By default the first 1MB of each pool is used for the Virtio and Vring buffers
used to communicate with the remote processor core. The remaining carveout is 
used for the remote core external memory (program code, data, etc).

.. note::
    The resource table entity (which describes the system resources needed by
    the remote processor) needs to be at the beginning of the remote processor
    external memory section.


For details on how to adjust the sizes and locations of the remote core pool
carveouts, please see section :ref:`changing_the_memory_map`.

.. _changing_the_memory_map:

Changing the Memory Map
---------------------------

The address and size of the DMA memory carveouts needs to match with the MCU
M4F and R5F external memory section sizes in their respective linker mapfiles.

arch/arm64/boot/dts/ti/k3-am62a7-sk.dts

::

	reserved-memory {
			#address-cells = <2>;
			#size-cells = <2>;
			ranges;

                	wkup_r5fss0_core0_dma_memory_region: r5f-dma-memory@9c800000 {
                        	compatible = "shared-dma-pool";
                        	reg = <0x00 0x9c800000 0x00 0x100000>;
                        	no-map;
                	};

                	wkup_r5fss0_core0_memory_region: r5f-dma-memory@9c900000 {
                        	compatible = "shared-dma-pool";
                        	reg = <0x00 0x9c900000 0x00 0x01e00000>;
                        	no-map;
                	};

                	mcu_r5fss0_core0_dma_memory_region: r5f-dma-memory@9b800000 {
                        	compatible = "shared-dma-pool";
                        	reg = <0x00 0x9b800000 0x00 0x100000>;
                        	no-map;
                	};

                	mcu_r5fss0_core0_memory_region: r5f-dma-memory@9b900000 {
                        	compatible = "shared-dma-pool";
                        	reg = <0x00 0x9b900000 0x00 0x0f00000>;
                        	no-map;
                	};

                	c7x_0_dma_memory_region: c7x-dma-memory@99800000 {
                        	compatible = "shared-dma-pool";
                        	reg = <0x00 0x99800000 0x00 0x100000>;
                        	no-map;
                	};

                	c7x_0_memory_region: c7x-memory@99900000 {
                        	compatible = "shared-dma-pool";
                        	reg = <0x00 0x99900000 0x00 0x01efffff>;
                        	no-map;
                	};
	};


.. warning:: Be careful not to overlap carveouts!

.. note:: The reserved memory sizes listed above are provided as a reference only and subject to change between releases. For latest memory reservations, please refer to the kernel device tree repository :
          'https://git.ti.com/cgit/ti-linux-kernel/ti-linux-kernel/tree/arch/arm64/boot/dts/ti/k3-am62a7-sk.dts?h=ti-linux-5.10.y'

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

This library support TI K3 family of devices (i.e AM65x, AM64x, AM62x, AM62ax, J721E, and
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
	| R5F_WKUP0_0      | 78000000.r5f       | Yes     | R5F core in Wakeup Domain         |
	+------------------+--------------------+---------+-----------------------------------+
	| R5F_MCU0_0       | 79000000.r5f       | Yes     | R5F core in MCU Domain            |
	+------------------+--------------------+---------+-----------------------------------+
	| DSP_c71_0        | 7e000000.dsp       | Yes     | DSP core in Main Domain            |
	+------------------+--------------------+---------+-----------------------------------+

RPMsg examples:
---------------

.. rubric:: RPMsg user space example

.. note::

   These steps were tested on Ubuntu 18.04.
   Later versions of Ubuntu may need different steps

 .. note::
	rpmsg_char_simple comes prepackaged in prebuilt wic image (tisdk-default-image-am62xx-evm.wic.xz)
	that comes with the release and below example can be directly run (Step 6) if using this prebuilt wic image

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

	# MCU R5F<->A53_0 IPC
	root@am62axx-evm:~# rpmsg_char_simple -r0 -n10
	Created endpt device rpmsg-char-0-1069, fd = 3 port = 1024
	Exchanging 10 messages with rpmsg device ti.ipc4.ping-pong on rproc id 0 ...

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

	Communicated 10 messages successfully on rpmsg-char-0-1069

	TEST STATUS: PASSED

	# for DM R5F<->A53 IPC, use the below command. For remote proc ids, please refer to : 'https://git.ti.com/cgit/rpmsg/ti-rpmsg-char/tree/include/rproc_id.h'
	root@am62axx-evm:~# rpmsg_char_simple -r15 -p21 -n10
	Created endpt device rpmsg-char-15-127176, fd = 3 port = 1024
	Exchanging 10 messages with rpmsg device ti.ipc4.ping-pong on rproc id 15 ...

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

	Communicated 10 messages successfully on rpmsg-char-15-127176

	TEST STATUS: PASSED

	# C7x<->A53_0 IPC
	root@am62axx-evm:~# rpmsg_char_simple -r8 -p21 -n10
	Created endpt device rpmsg-char-8-127180, fd = 3 port = 1024
	Exchanging 10 messages with rpmsg device ti.ipc4.ping-pong on rproc id 8 ...

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

	Communicated 10 messages successfully on rpmsg-char-8-127180

	TEST STATUS: PASSED

.. rubric:: RPMsg kernel space example

The kernel space example is in the Linux Processor SDK under
samples/rpmsg/rpmsg_client_sample.c

Build the kernel module rpmsg_client_sample:
 .. note::
	rpmsg_client_sample comes prepackaged in prebuilt wic image (tisdk-default-image-am62axx-evm.wic.xz)
	that comes with the release and below example can be directly run (Step 5) if using this prebuilt wic image

 #. Set up the kernel config to build the rpmsg client sample. Use menuconfig to
    verify Kernel hacking > Sample kernel code > Build rpmsg client sample is M:

::

    $ export PATH=<sdk path>/linux-devkit/sysroots/x86_64-arago-linux/usr/bin:$PATH
    $ make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- distclean
    $ make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- tisdk_am62axx-evm_defconfig
    $ make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- menuconfig

#. Make the kernel and modules. Multithreading with –j is optional:

::

    $ make ARCH=arm64 CROSS_COMPILE=aarch64-none-linux-gnu- -j8

Linux RPMsg can be tested with prebuilt binaries that are packaged in the
"tisdk-default-image-am62ax-evm" filesystem:

#. Copy the Linux RPMsg kernel driver from
   <Linux_SDK>/board-support/linux-x.x.x/samples/rpmsg/rpmsg_client_sample.ko
   into the board's Linux filesystem.

#. Ensure that the remote core symbolic link points to the desired binary file
   in /lib/firmware/pdk-ipc/. Update the symbolic link if needed. Reference
   section :ref:`booting_remote_cores_from_Linux_console` for more information.

#. Run the example on the board:

::

	root@am62axx-evm:/lib/firmware# modprobe rpmsg_client_sample count=10
	[ 2081.593551] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: new channel: 0x400 -> 0xd!
	[ 2081.602005] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 1 (src: 0xd)
	[ 2081.602092] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: new channel: 0x400 -> 0xd!
	[ 2081.612625] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 2 (src: 0xd)
	[ 2081.619039] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: new channel: 0x400 -> 0xd!
	[ 2081.628769] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 1 (src: 0xd)
	[ 2081.644037] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 3 (src: 0xd)
	[ 2081.655179] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 1 (src: 0xd)
	[ 2081.663550] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 2 (src: 0xd)
	[ 2081.671991] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 4 (src: 0xd)
	[ 2081.680333] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 2 (src: 0xd)
	[ 2081.688807] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 3 (src: 0xd)
	[ 2081.697141] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 5 (src: 0xd)
	[ 2081.705553] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 3 (src: 0xd)
	[ 2081.713878] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 4 (src: 0xd)
	[ 2081.722297] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 6 (src: 0xd)
	[ 2081.730617] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 4 (src: 0xd)
	[ 2081.739021] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 5 (src: 0xd)
	[ 2081.747344] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 7 (src: 0xd)
	[ 2081.755746] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 5 (src: 0xd)
	[ 2081.764092] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 6 (src: 0xd)
	[ 2081.772514] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 8 (src: 0xd)
	[ 2081.780834] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 6 (src: 0xd)
	[ 2081.789263] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 7 (src: 0xd)
	[ 2081.797633] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 9 (src: 0xd)
	[ 2081.806046] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 7 (src: 0xd)
	[ 2081.814375] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 8 (src: 0xd)
	[ 2081.822851] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: incoming msg 10 (src: 0xd)
	[ 2081.831239] rpmsg_client_sample virtio0.ti.ipc4.ping-pong.-1.13: goodbye!
	[ 2081.838223] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 8 (src: 0xd)
	[ 2081.846559] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 9 (src: 0xd)
	[ 2081.855040] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 9 (src: 0xd)
	[ 2081.863369] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: incoming msg 10 (src: 0xd)
	[ 2081.871858] rpmsg_client_sample virtio1.ti.ipc4.ping-pong.-1.13: goodbye!
	[ 2081.878713] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: incoming msg 10 (src: 0xd)
	[ 2081.887258] rpmsg_client_sample virtio2.ti.ipc4.ping-pong.-1.13: goodbye!

