.. http://processors.wiki.ti.com/index.php/PRU-ICSS_Remoteproc_and_RPMsg
.. rubric:: Introduction
   :name: introduction-pru-icss-remoteproc-rpmsg

.. raw:: html

   <div>

.. Image:: ../images/Overview.PNG

.. raw:: html

   </div>

The host processor on TI's Sitara family of devices is an ARM Cortex-A
processor. Typically the ARM core is running Linux based on the
`Processor
SDK <Overview.html#processor-sdk-linux-software-developer-s-guide>`__.
TI has developed custom pruss and pru\_rproc (PRU Subsystem Remote
Processor) drivers which will plug into this kernel. This provides an
interface for the kernel to load firmware into the PRU core(s) and
provides basic control such as start and halt. A message passing driver,
named rpmsg\_pru (remote processor message), has also been developed
that allows the PRU and ARM cores to pass messages and buffers back and
forth.

.. rubric:: What do we need Linux to do?
   :name: what-do-we-need-linux-to-do

The following is a list of services that Linux needs to provide in order
to enable the PRU cores:

-  Load firmware into the PRU cores
-  Control PRU execution (start, stop, etc.)
-  Manage resources (memory, interrupt mappings, etc.)
-  Provide a method to send/receive messages

All of these services are provided through a combination of the pruss,
pru\_rproc, and rpmsg\_pru Linux drivers that TI provides in the
`Processor
SDK <Overview.html#processor-sdk-linux-software-developer-s-guide>`__.

.. rubric:: Remoteproc
   :name: remoteproc

.. rubric:: Overview
   :name: overview

Remoteproc is a framework that allows the ARM host processor(s) to load
firmware into PRU cores, start the PRU cores, stop the PRU cores, and
configure resources that the PRUs might need during their execution
(such as configuring the PRUSS INTC module and providing shared buffers
in DDR memory for message passing). The next section will discuss the
process that happens when the remoteproc module loads the PRU cores with
a firmware. Most of this happens transparently to the user when the
pruss and pru\_rproc modules are inserted but an understanding of the
concepts below should help users to better understand how to debug
problems with remoteproc should they arise.

.. rubric:: Load Procedure
   :name: load-procedure

This section will walk through each step that the drivers takes as they
load firmwares into the PRU cores and then run them.

.. rubric:: Step 0
   :name: step-0

.. raw:: html

   <div>

.. raw:: html

   <div class="floatright">

.. Image:: ../images/Step0_2_0_2_11.PNG

.. raw:: html

   </div>

.. raw:: html

   </div>

The four blocks in the image to right represent: The ARM core running
Linux, the Linux filesystem where the PRU firmware binaries are
initially stored, the PRU subsystem, and DDR memory. This image shows
the initial state of the system before the pruss\_remoteproc module is
inserted.

-  Remoteproc driver is included as a kernel driver. This is a core
   remoteproc driver that provides the load/run/halt/etc API to other
   more specific remoteproc drivers.
-  A sysfs interface is also exposed to User Space to start/stop the PRU
   cores as well as specify the firmware file to load.

   -  The sysfs interface is found at
      **/sys/class/remoteproc/remoteprocN/** (e.g. remoteproc1 is PRU0
      and remoteproc2 is PRU1 on the AM335x device (remoteproc0 is the
      M3 core used for power management functions)).

-  PRU firmware binaries exist in the filesystem in the
   **/lib/firmware/** directory.

| 

--------------

.. rubric:: Step 1
   :name: step-1

.. raw:: html

   <div class="floatright">

.. Image:: ../images/Step1_2_0_2_11.PNG

.. raw:: html

   </div>

| In this step, the sysfs interface (mentioned above in step 0) is used
  to specify the name of the firmware to be loaded as well as to signal
  that the user wants to load and start the PRU cores
| ``echo 'am335x-pru0-fw' > /sys/class/remoteproc/remoteproc1/firmware``
| ``echo 'am335x-pru1-fw' > /sys/class/remoteproc/remoteproc2/firmware``
| ``echo 'start' > /sys/class/remoteproc/remoteproc1/state``
| ``echo 'start' > /sys/class/remoteproc/remoteproc2/state``

| 

--------------

.. rubric:: Step 2
   :name: step-2

.. raw:: html

   <div class="floatright">

.. Image:: ../images/Step2_2_0_2_11.PNG

.. raw:: html

   </div>

The pru\_rproc module verifies two things before it proceeds with the
firmware loading process.

-  The pru\_rproc modules checks for the existence of PRU firmware
   binaries in the filesystem (as specified by the firmware entry in the
   sysfs in step 1 above)

   -  These binaries must be located in the /lib/firmware/ directory
   -  am335x-pru0-fw and am335x-pru1-fw are the default names used for
      the AM335x device but any name can be used as long as the firmware
      exists in /lib/firmware/

-  The pru\_rproc module also parses the firmware binaries looking for a
   section named **.resource\_table**

   -  This **.resource\_table** section of the firmware specifies the
      system resources that the PRUs will need during their program
      execution

| 

--------------

| 

.. rubric:: Step 3
   :name: step-3

.. raw:: html

   <div class="floatright">

.. Image:: ../images/Step3_2_0_2_11.PNG

.. raw:: html

   </div>

-  The pru\_rproc module configures all of the resources that are being
   requested by the firmwares
-  In this case, that includes creating vrings in DDR memory for
   communication as well as setting up the interrupt mapping in the PRU
   subsystem INTC module

| 

--------------

.. rubric:: Step 4
   :name: step-4

.. raw:: html

   <div class="floatright">

.. Image:: ../images/Step4_2_0_2_11.PNG

.. raw:: html

   </div>

| The pru\_rproc module then loads the binary into the instruction RAM
  of the PRUs and also copies the resource table into the PRUs data RAM
  space
| **Note: Configuration details can be shared from the ARM to the PRUs
  through the resource table that gets copied into the data RAM of each
  PRU**

| 

--------------

| 

.. rubric:: Step 5
   :name: step-5

.. raw:: html

   <div class="floatright">

.. Image:: ../images/Step5_2_0_2_11.PNG

.. raw:: html

   </div>

Now that everything is configured and the application code is in place,
the pru\_rproc module instructs the PRU cores to begin execution.

| **Notice that the PRU state was previously set to 'Halted' but now it
  is 'Run'**

.. rubric:: RPMsg
   :name: rpmsg

RPMsg is a message passing mechanism that requests resources through
remoteproc and builds on top of the virtio framework. Shared buffers are
requested through the resource\_table and provided by the remoteproc
module during PRU firmware loading (as shown in the remoteproc procedure
above). The shared buffers are contained inside a vring data structure
in DDR memory. There are two vrings provided per PRU core, one vring is
used for messages passed to the ARM and the other vring is used for
messages received from the ARM. System level mailboxes are used to
notify cores (ARM or PRU) when new messages are waiting in the shared
buffers.

There are two RPMsg software implementations provided in the Linux
Processor SDK. On the ARM Linux side, RPMsg communication is received in
kernel space. An interface module is provided (rpmsg\_pru) that creates
a character device in user space so that users can write/read to/from a
character device in the file system to send/receive messages to/from the
PRUs. On the PRU side, an RPMsg library is provided in the PRU Software
Support Package that aims to abstract the communication to a point where
a user's code can just call the pru\_rpmsg\_receive and pru\_rpmsg\_send
functions in order to communicate with the ARM core. Source code for the
PRU RPMsg library is provided in the support package along with the
ability to rebuild the library if changes are desired.

.. Image:: ../images/Rpmsg_diagram_2_0_2_11.PNG

--------------

.. rubric:: ARM to PRU
   :name: arm-to-pru

.. raw:: html

   <div class="floatright">

.. Image:: ../images/Arm-to-pru.PNG

.. raw:: html

   </div>

The diagram to the right shows the process that occurs when the ARM
sends a message to the PRU. These steps are shown for illustrative
purposes as the provided software in the SDK hides them in an
abstraction layer.

-  ARM Host Steps

   -  Step 1a: Allocate a new buffer
      -or-
   -  Step 1b: Get a Used buffer from the slave Vring
   -  Step 2: Copy data to be transferred into the buffer from Step 1
   -  Step 3: Add the newly filled buffer to the Available list in the
      slave Vring
   -  Step 4: Kick the slave Vring by writing its index (1) into a
      message in Mailbox 2

-  PRU Steps

   -  Step 5: A Kick is discovered in Mailbox 2 with the index of the
      Kicked Vring (1). This indicates to the PRU that data is available
      for receive
   -  Step 6: Get the Available buffer from the slave Vring
   -  Step 7: Copy data to be received out of the buffer from Step 2
   -  Step 8: Add the now empty buffer to the Used list in the slave
      Vring
   -  Step 9: Kick the slave Vring by writing its index (1) into a
      message in Mailbox 3

| 

.. rubric:: PRU to ARM
   :name: pru-to-arm

.. raw:: html

   <div class="floatright">

.. Image:: ../images/Pru-to-arm.PNG

.. raw:: html

   </div>

The diagram to the right shows the process that occurs when the PRU
sends a message to the ARM. These steps are shown for illustrative
purposes as the provided software in the SDK hides them in an
abstraction layer.

-  PRU Steps

   -  Step 1: Get an Available buffer from the host Vring
   -  Step 2: Copy data to be transferred into the buffer from Step 1
   -  Step 3: Add the newly filled buffer to the Used list in the host
      Vring
   -  Step 4: Kick the host Vring by writing its index (0) into a
      message in Mailbox 3

-  ARM Host Steps

   -  Step 5: An interrupt signals that Mailbox 3 was kicked with the
      index of Vring (0). This indicates to the ARM Host that data is
      available for receive
   -  Step 6: Get the Used buffer from the host Vring
   -  Step 7: Copy data to be received out of the buffer from Step 2
   -  Step 8: Add the now empty buffer to the Available list in the host
      Vring
   -  Step 9: Kick the host Vring by writing its index (0) into a
      message in Mailbox 2

| 

.. rubric:: RPMsg PRU Code Example
   :name: rpmsg-pru-code-example

| The RPMsg library provided for the PRU cores attempts to abstract the
  underlying implementation (Vring transport layer, mailboxes, etc.) to
  make programming as simple as possible. See the code below for an
  example PRU firmware the that can receive, and then echo back,
  messages from the ARM core. This code is provided as an example in the
  PRU Software Support Package that is include in the Linux Processor
  SDK.

.. Image:: ../images/Rpmsg_code.PNG

.. rubric:: Next Steps
   :name: next-steps

To get started quickly with remoteproc and RPMsg you can use the `RPMsg
Quick Start Guide <http://processors.wiki.ti.com/index.php/RPMsg_Quick_Start_Guide>`__.

For Hands-on Labs that work with the BeagleBone Black and a PRU Cape
start `here <http://processors.wiki.ti.com/index.php/PRU_Training:_Hands-on_Labs>`__.

