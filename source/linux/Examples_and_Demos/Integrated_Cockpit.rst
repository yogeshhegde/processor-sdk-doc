Integrated cockpit demo
=======================

Overview
--------

Integrated cockpit demo attempts to demonstrate the virtualization and isolation
features of J721e SoC. This example applications show how infotainment applications
like HLOS compositors and graphics and multimedia applications
can concurrently run on a single SoC while running safety applications like cluster.
It also demonstrates how a cluster application can run its safety components on a
separate core running a safety-certified OS, thereby isolating the safety features from non-safe
components like HLOS rendering.

Following block diagram describes the high
level software stack for this demo.

.. Image:: ../../images/Integrated-Cockpit-Block-Diagram.png

Integrated cockpit is realized with two virtual machines (VMs) running
on a lightweight hypervisor `Jailhouse <https://github.com/siemens/jailhouse>`__.
All the resources like memory, interrupts, peripheral devices are partitioned
across the **cluster VM** and **Infotainment VM**. Both virtual machines run the
Linux kernel and use different device-tree binaries to own and manage a particular set
of resources.

Cluster safety software is running on one main-domain R5F sub-system. This software runs using
TI SYSBIOS RTOS and serves several safety-critical functions like:

- Running MCAN driver and collecting vehicular parameters
- Rendering tell-tales based on relevant CAN messages and displaying tell-tales on cluster display
- Running a remote-device server so that the cluster VM can share cluster display
- Sending relevant vehicular parameters to cluster VM application which can be used for rendering dials and needles
- Sending IVI VM monitor service so that it can detect IVI VM crash and notify user


Cluster VM is running a Linux kernel and a linux cluster application that uses CPU-copy to render the buffers and DRM APIs to display the rendered buffers. The cluster application
collects vehicular parameters from the remote R5F core to render the dials and the needles in two separate
planes. The DRM APIs internally use the remote-device service running on the remote R5F core.
Cluster VM is also running a heartbeat application that keeps monitoring the IVI VM status and sending a notification to remote core
if a crash is detected.

The Infotainment VM is running a Linux kernel and an infotainment setup running HLOS
compositor, which is used to run graphics demo applications and multimedia playback applications like gstreamer.


Resource partitioning
---------------------

The following is the resource partitioning across different software entities in the system.

+---------------+--------------------+--------------+---------------------+
| Resource      | Cluster VM         | IVI VM       | RTOS                |
+---------------+--------------------+--------------+---------------------+
| CPU           | A72_0              | A72_1        | Main_R5_0_1         |
+---------------+--------------------+--------------+---------------------+
| DRAM memory   | 2347 MB            | 1744MB       | X                   |
+---------------+--------------------+--------------+---------------------+
| UART          | main_uart0         | main_uart1   | X                   |
+---------------+--------------------+--------------+---------------------+
| Storage       | SD card            | EMMC         | X                   |
+---------------+--------------------+--------------+---------------------+
| Display       | VID1 *marshalled*, | VIDL1, OVR1, | *marshalled* VID1,  |
|               | VIDL2 *marshalled* | VP1, DP      | *marshalled* VIDL2, |
|               |                    |              | VID2, OVR2, VP2,    |
|               |                    |              | HDMI                |
|               |                    |              |                     |
+---------------+--------------------+--------------+---------------------+
| SYSFW host_id | A72_2              | A72_3        | Main_R5_0_1         |
+---------------+--------------------+--------------+---------------------+
| Multimedia    | X                  | D552 decoder | X                   |
+---------------+--------------------+--------------+---------------------+
| Graphics      | X                  | GPU          | X                   |
+---------------+--------------------+--------------+---------------------+

**Note:** **X** represents that this resource is not available to this core / virtual machine. 

Board setup
-----------

Please follow the instructions in *Setting up J721E EVM with Infotainment daughter card for Processor SDK Linux Automotive 06.00.00.00* 

**Optional:** To run the cockpit demo in external CAN configuration, you should connect the D-Sub interface of the `PEAK System <https://www.peak-system.com>`__'s PCAN-USB tool
to the MCAN2 interface on the common processor board as follows:

.. Image:: ../../images/Integrated-Cockpit-D-Sub.png

.. Image:: ../../images/Integrated-Cockpit-MCAN2-CPB.png
 :scale: 30%

PC Setup
--------

Please follow the instruction in section *Setting up Ubuntu PC for Processor SDK Linux Automotive 06.00.00.00* 

**Optional:** To run the cockpit demo in external CAN configuration, you should connect the USB interface of the `PEAK System <https://www.peak-system.com>`__'s PCAN-USB tool
to your PC.

Ubuntu has in-built driver support for PCAN tool. Once the USB device is plugged in, you should be able to see the device getting detected and an appropriate net-device getting created on your PC

.. code-block:: bash

 # dmesg
 
 ...
 
 [3274019.198839] usb 1-9: new high-speed USB device number 124 using xhci_hcd
 [3274019.327468] usb 1-9: New USB device found, idVendor=0c72, idProduct=0012
 [3274019.327472] usb 1-9: New USB device strings: Mfr=1, Product=2, SerialNumber=0
 [3274019.327475] usb 1-9: Product: PCAN-USB FD
 [3274019.327478] usb 1-9: Manufacturer: PEAK-System Technik GmbH
 [3274019.328957] peak_usb 1-9:1.0: PEAK-System PCAN-USB FD v1 fw v2.1.0 (1 channels)
 [3274019.329155] peak_usb 1-9:1.0 can0: attached to PCAN-USB FD channel 0 (device 0)
 
 ...
 
 # ifconfig -a
 
 ...
 
 can0      Link encap:UNSPEC  HWaddr 00-00-00-00-00-00-00-00-00-00-00-00-00-00-00-00  
           NOARP  MTU:16  Metric:1
           RX packets:0 errors:0 dropped:0 overruns:0 frame:0
           TX packets:0 errors:0 dropped:0 overruns:0 carrier:0
           collisions:0 txqueuelen:10 
           RX bytes:0 (0.0 B)  TX bytes:0 (0.0 B)
 
 ...

You can now set up the CAN interface by runnning the following command.

.. code-block:: bash

 # sudo ip link set can0 up type can bitrate 1000000
 
 # demsg
 
 ...
 
 [3274263.223087] IPv6: ADDRCONF(NETDEV_CHANGE): can0: link becomes ready
 
 ...

Flashing instructions
---------------------
This demo uses Jailhouse hypervisor to create 2 virtual machines.
Refer to `How to flash eMMC device <../How_to_Guides/Target/How_to_flash_emmc_device.html>`__
for Flashing eMMC partition, so that Infotainment Virtual machine
can use the eMMC based rootfs.

Running the demo
----------------

For running the demo, you have to boot the board in demo mode.

- Copy the uenv.txt.cockpit as uenv.txt in *boot* partition of SD card
- **Optional:** By default, the cockpit demo is configured to emulate CAN messages internally. To run the cockpit demo in external CAN
  configuration, change the firmware in the *rootfs* partition of SD card

  .. code-block:: bash

   # cd /media/`whoami`/rootfs
   # ln -sf /lib/media/cockpit_app_cockpit_can_params_demo.out lib/firmware/j7-main-r5f0_1-fw

- Reboot the board. It will boot in demo mode.

  **Optional:** If running in external CAN configuration, run the host application *car-emulator* after the display is turned on. The host application sends CAN messages to the board to simulate toggling tell-tales and needle sweep

  .. code-block:: bash

   # car-emulator

- After the board boots to prompt, you can automatically run the demo applications by running the following scripts:

  - Run following in the *cluster-VM* console

    .. code-block:: bash

     $ /usr/share/ti/util-scripts/demo/cockpit-demo-cluster-VM.sh

    This will also start the *infotainment VM*.

  - After the *infotainment VM* boots to prompt, run following in the *Infotainment-VM* console

    .. code-block:: bash

     $ /usr/share/ti/util-scripts/demo/cockpit-demo-infotainment-VM.sh

- Alternatively, you can follow the next section to run the demo components manually.


RTOS tell-tales application
---------------------------

The First application after bootup is RTOS based tell-tales. It uses a dedicated
display pipeline to render tell-tales using UDMA into the display buffers. The tell-tales
are displayed on the HDMI panel.

The data for the tell-tales are obtained from the CAN-reader module. The tell-tale application
also filters out the speed and engine-speed data and feeds them to the HLOS cluster app.

In emulated-CAN mode, the data is generated internally, and you should see a blinking set of tell-tales
at bootup:

.. Image:: ../../images/Integrated-Cockpit-tell-tales.jpg
 :scale: 50%

In external-CAN mode, the data is read from MCAN2, and initially all tell-tale symbols are set to **off** state. To turn on all tell-tales, run the following command on your PC:

.. code-block:: bash

 # cansend can0 1f0#01ffffff00000000

To turn off all tell-tales, run the following command on your PC:

.. code-block:: bash

 # cansend can0 1f0#0100000000000000

.. |key inline image| image:: ../../images/Integrated-Cockpit-general-warning.png

**Note:** In both emulated-CAN and external-CAN mode, the general-warning tell-tale |key inline image| will not be effected. It is a special tell-tale
which is trigerred by crashing *Infotainment-VM*. This is documented in section :ref:`crashing-infotainment-vm`. 

Linux Cluster application
-------------------------

This is a Linux DRM-based GPU-less cluster application which uses two pipelines
to draw needle and dials. It gets speed and RPM data from an RTOS tell-tales app
and updates the rendering parameters based on this. Run this application from the
*cluster-VM* console:

.. code-block:: bash

 $ cluster -d /dev/dri/card0

.. Image:: ../../images/Integrated-Cockpit-full.jpg
 :scale: 50%

If running in external-CAN mode, run the following command on your PC to take the speed needle to 100 KMPH:


.. code-block:: bash

 # cansend can0 1f0#0200000000640000

To take the engine-speed (RPM) needle to 2000, run the following command on your PC:

.. code-block:: bash

 # cansend can0 1f0#04000000000007d0


**Note:** The rules on forming the CAN messages are provided in section :ref:`framing-can-messages`. 

Starting the *Infotainment VM*
------------------------------

Run the script below to start jailhouse and launch *infotainment VM*. You should see the linux boot logs in the *Infotainment-VM*
console and the Display-Port monitor should show weston wallpaper.

.. code-block:: bash

 $ /usr/share/ti/util-scripts/demo/jailhouse-launch-VM.sh

Starting the heartbeat applications
-----------------------------------

The heartbeat provider and listener applications run on the *Infotainment-VM* and the *Cluster-VM* respectively. The heartbeat
provider application sends out a **tick** periodically, whereas the heartbeat listener tracks the **ticks**. If no heartbeat is received
within one second, the *Infotainment VM* is declared to be crashed and appropriate action is taken.

To start the heartbeat provider application, run the following command in the *Infotainment-VM* console:

.. code-block:: bash

 $ ti-heartbeat-i-am-here

To start the heartbeat listener application, run the following command in the *Cluster-VM* console, after the heartbeat provice application is
started in the *Infotainment VM*

.. code-block:: bash

 $ ti-heartbeat-are-you-there


Graphics application
--------------------

The SDK filesystem contains the following applications to showcase the graphics capability of the system. All of these are wayland based OpenGL ES applications
which can be run while weston is running

- /usr/bin/SGX/demos/Wayland/OpenGLESDeferredShading
- /usr/bin/SGX/demos/Wayland/OpenGLESImageBasedLighting
- /usr/bin/SGX/demos/Wayland/OpenGLESIntroducingPVRUtils
- /usr/bin/SGX/demos/Wayland/OpenGLESIntroducingUIRenderer
- /usr/bin/SGX/demos/Wayland/OpenGLESParticleSystem
- /usr/bin/weston-simple-egl
- /usr/bin/wgles1test1
- /usr/bin/wgles2test1
- /usr/bin/wgles3test1

Multimedia decode
-----------------

The SDK filesystem contains H264 and H265 video clips that can be decoded and displayed using *gst-launch-1.0* application. The example
pipelines below use V4L2-based decoder plugins for decoding and waylandsink for displaying the decoded buffers.

.. code-block:: bash

 $ gst-launch-1.0 filesrc location=/usr/share/ti/video/TearOfSteel-Short-1280x720.265 ! h265parse ! v4l2h265dec ! waylandsink

 $ gst-launch-1.0 filesrc location=/usr/share/ti/video/TearOfSteel-Short-1280x540.h264 ! h264parse ! v4l2h264dec ! waylandsink


.. _crashing-infotainment-vm:

Crashing the individual linux VMs
---------------------------------

The utility script *crash-VM.sh* can be used to read GPIO inputs and simulate VM crash. You can start the script in *cluster VM* console to run it in the background

.. code-block:: bash

 $ /usr/share/ti/util-scripts/demo/crash-VM.sh

You can crash the individual Linux VMs by pushing the buttons as shown below

.. Image:: ../../images/Integrated-Cockpit-crash-gpio.png
 :scale: 50%

**Note:** If the *Infotainment VM* is crashed, the heartbeat listener application running on the *cluster VM* detects the crash and sends a notification to the remote core. The general-warning tell-tale |key inline image|
is turned on to indicate the crash.

.. _framing-can-messages:

Framing CAN messages for cockpit demo
-------------------------------------

+---------------------------------------------------------------------------------------+---------------------------------------------------------------------------------------+
|Byte 7                                                                                 |Byte 6                                                                                 |
+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+
|63        |62        |61        |60        |59        |58        |57        |56        |55        |54        |53        |52        |51        |50        |49        |48        |
+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+
|RESERVED                                              |ES_EN     |S_EN      |T_EN      |RESERVED             |TT_MASK                                                          | 
+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+
|Byte 5                                                                                 |Byte 4                                                                                 |
+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+
|47        |46        |45        |44        |43        |42        |41        |40        |39        |38        |37        |36        |35        |34        |33        |32        |
+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+
|TT_MASK (Continued)                                                                                                                                                            |
+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+
|Byte 3                                                                                 |Byte 2                                                                                 |
+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+
|31        |30        |29        |28        |27        |26        |25        |24        |23        |22        |21        |20        |19        |18        |17        |16        |
+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+
|RESERVED                                                                               |SPEED                                                                                  |
+---------------------------------------------------------------------------------------+---------------------------------------------------------------------------------------+
|Byte 1                                                                                 |Byte 0                                                                                 |
+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+
|15        |14        |13        |12        |11        |10        |9         |8         |7         |6         |5         |4         |3         |2         |1         |0         |
+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+
|RESERVED                        |ENGINE_SPEED                                                                                                                                  |
+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+----------+

+-----------------+---------------------+--------------------------------+----------------------------------+
|Field            |Field Name           |Description                     |Values                            |
+-----------------+---------------------+--------------------------------+----------------------------------+
|59:63            |RESERVED             |Reserved                        | | This field has no effect.      |
|                 |                     |                                | | Write 0                        |
+-----------------+---------------------+--------------------------------+----------------------------------+
|58               |ES_EN                |Write 1 for ENGINE_SPEED field  | | 0: ENGINE_SPEED is ignored     |
|                 |                     |to take effect. Write 0 to      | | 1: ENGINE_SPEED is valid       |
|                 |                     |ignore ENGINE_SPEED field       |                                  |
+-----------------+---------------------+--------------------------------+----------------------------------+
|57               |S_EN                 |Write 1 for SPEED field         | | 0: SPEED is ignored            |
|                 |                     |to take effect. Write 0 to      | | 1: SPEED is valid              |
|                 |                     |ignore SPEED field              |                                  |
+-----------------+---------------------+--------------------------------+----------------------------------+
|56               |T_EN                 |Write 1 for TT_MASK field       | | 0: TT_MASK is ignored          |
|                 |                     |to take effect. Write 0 to      | | 1: TT_MASK is valid            |
|                 |                     |ignore TT_MASK field            |                                  |
+-----------------+---------------------+--------------------------------+----------------------------------+
|54:55            |RESERVED             |Reserved                        | | This field has no effect.      |
|                 |                     |                                | | Write 0                        |
+-----------------+---------------------+--------------------------------+----------------------------------+
|32:53            |TT_MASK              |Bitmask for turning tell-tale   | | Valid Values:                  |
|                 |                     |signs on / off. For each bit in | | 0x000000 - 0x3fffff            |
|                 |                     |mask, write 1 to turn on, write |                                  | 
|                 |                     |0 to turn off a particular      |                                  |
|                 |                     |tell-tale.                      |                                  | 
+-----------------+---------------------+--------------------------------+----------------------------------+
|24:31            |RESERVED             |Reserved                        | | This field has no effect.      |
|                 |                     |                                | | Write 0                        |
+-----------------+---------------------+--------------------------------+----------------------------------+
|16:23            |SPEED                |Speed value in Kmph             | | 0 - 255: engine speed          |
+-----------------+---------------------+--------------------------------+----------------------------------+
|13:15            |RESERVED             |Reserved                        | | This field has no effect.      |
|                 |                     |                                | | Write 0                        |
+-----------------+---------------------+--------------------------------+----------------------------------+
|0:12             |ENGINE_SPEED         |Engine Speed value in RPM       | | 0 - 8192: engine speed         |
+-----------------+---------------------+--------------------------------+----------------------------------+

