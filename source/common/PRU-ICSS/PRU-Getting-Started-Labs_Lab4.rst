.. _pru_getting_started_labs_lab_4:

Lab 4: How to Initialize the PRU
--------------------------------

.. contents:: :local:

This lab demonstrates how to initialize the PRU from CCS, or another core
running Linux.

.. note::

   AM62x: At the time of writing, CCS does not support connecting to AM62x PRU
   cores. Please load and debug PRU cores from Linux.

.. note::

   Steps to initialize the PRU from another core running an OS from an MCU+ SDK
   (i.e., RTOS or NORTOS) will be
   added at a later time. Not all cores running RTOS or NORTOS can initialize
   the PRU. Reference the MCU+ SDK release notes to see which cores support
   initializing the PRU with the **PRUICSS** driver.

.. note::

   This lab does **not** cover cores running an OS from a Processor SDK RTOS
   (i.e., TI-RTOS). Legacy steps to initialize the PRU from a core running TI-RTOS
   are provided here as a resource for customers using AM335x, AM437x, and
   AM57xx: :ref:`pru_getting_started_labs_initialize_from_rtos`. However,
   the TI-RTOS steps have **not** been tested for several years.


.. _pru_getting_started_labs_initialize_from_ccs:

Initializing the PRU from CCS
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^


Set up the Target Configuration
"""""""""""""""""""""""""""""""

Select **View -> Target Configurations** to see a list of available
configurations. If a target configuration was created as a part of
:ref:`pru_getting_started_labs_creating_ccs_project`, it will show up here.

If there is no target configuration:

   #. Right click in the white space
      in the **Target Configurations** window. Select
      **New Target Configuration**.

   #. Specify a filename (e.g., am335x_bbb_xds100v2.ccxml, am62x_sk.ccxml,
      am64x_evm.ccxml, etc) and select **Finish**.

   #. Select a connection type:

      * If the EVM requires a separate JTAG debugger, select the JTAG debugger
        that is being used

        * AM335x example: A BeagleBone Black being debugged with an XDS100v2
          emulator would select **Texas Instruments XDS100v2 USB Debug Probe**

      * If the EVM uses an on-board debugger, select the installed debugger

        * AM62x, AM64x, AM65x example:
          Select  **Texas Instruments XDS110 USB Debug Probe**

   #. Select the Board

   #. AM335x BeagleBone Black only: Select the **Advanced** tab and follow
      the steps in the PRU Hands-On Labs: :ref:`pru_hands_on_labs_lab_1`,
      section "Load the PRU Firmware".

   #. Save the Target Configuration.


Connect to the EVM
""""""""""""""""""

If the processor has a Processor MCU+ SDK (AM62x, AM64x):

  #. Reference the Processor MCU+ SDK documentation, section "Getting Started" >
     "EVM Setup".

  #. Follow the steps to get the EVM properly set up for a CCS connection.

  #. Connect the JTAG debug port to the computer running CCS.

Otherwise:

 * AM65x: Reference the Processor SDK RTOS documentation, section
   "CCS Setup for AM65XX".

 * AM335x on a Beaglebone Black: Reference the PRU Hands-On Labs:
   :ref:`pru_hands_on_labs_lab_1`, section "Load the PRU Firmware".

 * Other AM335x, AM437x, AM57x boards: Check to see if the board is documented
   in the SDK documentation, section "How to Guides" > "Hardware EVM Setup"

.. TODO: Any other boards or cases we want to document here?


Test the Target Configuration
"""""""""""""""""""""""""""""

#. Power on the board. Note that different boards may have different Power-on /
   power-off procedures. Reference the EVM User's Guide for details.

#. Make sure that the JTAG debug port is plugged in.

#. If the Target Configuration is not open, open it by double clicking on the
   filename in the **Target Configurations** window.

#. click button **Test Connection**.

.. note::

   If the target configuration does not successfully connect, the processor may
   require initialization scripts to run before CCS can connect. Double-check
   that you followed all the steps in
   :ref:`pru_getting_started_labs_creating_ccs_project` and the above
   "Connect to the EVM" section.

.. TODO: Is the above note actually correct?


Load the PRU firmware
"""""""""""""""""""""

#. In the "Target Configurations" view, right click the Target Configuration
   file. Select **Launch Selected Configuration**.

   .. note::

     **Launch Selected Configuration** might not appear if you right click the
     file in a view other than "Target Configurations".

   .. the below steps apply to AM64x. Any others?

#. After the Target Configuration loads, right click on the DMSC core. Select
   **Connect Target**.

#. The initialization script should run automatically. Among other things, the
   initialization script sets up the PRU core clock so the CCS debugger can
   connect to the PRU cores.

#. After the initialization script runs, right click on the DMSC core. Select
   **Disconnect Target**.

#. Right click on the appropriate PRU core (e.g., PRU_0) and select
   **Connect Target**.

      .. note::

         AM62x: At the time of writing, the **PRU** cores are associated with
         **AM62**, but not **AM62_SK_EVM**. If the PRU cores do not show up in
         the Debug view, edit the Target Configuration to use **AM62** instead
         of **AM62_SK_EVM**. Save the configuration before re-starting the debug
         session in CCS.

#. Load the built example by selecting **Run -> Load -> Load Program**.

#. Select **Browse Project**. Navigate to the built project. Select
   the .out file from the Debug folder.

#. The PRU firmware has been loaded into the PRU!

#. Jump to :ref:`pru_getting_started_labs_lab_5` to debug the PRU firmware.


.. _pru_getting_started_labs_initialize_from_linux:

Initializing the PRU from Linux Core
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Configure the Kernel
""""""""""""""""""""

The remoteproc and rpmsg modules are enabled by default. These modules are
included out-of-the-box in the Linux Processor SDK.

.. TODO: Provide documentation for manually configuring the Linux kernel.
   Talk about which modules are required when


Modify Device Tree Files to account for Pinmuxing
"""""""""""""""""""""""""""""""""""""""""""""""""

TI processors route multiple signals to each pin on the processor. Each pin
has a multiplexer that selects which of the internal signals is routed to
the pin. The pin multiplexer settings are called "pinmux settings".

The PRU Getting Started Labs do not interface with the processor pins, so
pinmux settings are not required.

For an example of adding PRU pinmux settings to the Linux devicetree, reference
`the software for TI design TIDA-01555 <https://git.ti.com/cgit/apps/tida01555/tree/dts/am335x-boneblack-pruadc.dts>`__.
Note that different processors may have different ways of notating address
offsets for pinmux values.

General documentation for compiling a device tree binary is in the Linux
Processor SDK, section "Foundational Components" -> "Kernel" -> "Users Guide".
For the TIDA-01555 example, build am335x-boneblack-pruadc.dts

.. TODO: Generalize the pinmux guidance. Point to pinmux documentation in the
   Linux Academy once that is added. 


Copy files to the target filesystem
"""""""""""""""""""""""""""""""""""

There are many ways to boot Linux on a TI processor. These steps will boot Linux
with an SD card.

#. Create a bootable SD card. Follow the steps in the Linux Processor SDK,
   section "Overview" -> "Getting Started Guide" -> "Create SD Card".

#. Once the card is created, mount the SD card on the Linux computer.

#. The rootfs partition on the SD card contains the target filesystem. Copy
   the files from the Linux computer to the SD card:

   * Copy the PRU firmware binaries xxx.out to the /lib/firmware/pru directory
     of the rootfs partition.

   * If the Linux devicetree was modified:

     * Copy the xxx.dtb file to the boot
       directory of the rootfs partition of the SD card. It is suggested to give
       development DTBs a unique name.

     * Change the "EVM.dtb" symlink in the rootfs/boot directory to point to the
       new dtb file instead of the default.

       * AM335x example:

         ::

            sudo ln -f -s am335x-boneblack-prucape.dtb am335x-boneblack.dtb

#. Unmount the SD card from the Linux computer before removing the SD card. This
   step ensures that the files finish writing to the SD card before the SD card
   is removed.

.. TODO: Is the above statement correct?


Boot the new device tree and FS on the Target
"""""""""""""""""""""""""""""""""""""""""""""

#. Move the SD card from the host PC to the target board.

#. Check that the EVM BOOTMODE switches are set for SD card boot. Reference
   the EVM's **Quick Start Guide** or **User Guide** for more information.

#. Power on the board. Note that different EVMs may have different power-on /
   power-off procedures. Reference the EVM **User Guide** for more information.

#. Establish a serial connection between the EVM and the development computer.
   Reference the EVM **Quick Start Guide** for more information.

#. Wait for the kernel to boot. At the prompt, login with "root" and no
   password.

#. Use the remoteproc sysfs interface to specify which PRU firmwares the
   remoteproc driver should load:

   * Check which remoteproc node is associated with which core with the below
     command. "pru" can be replaced with "rtu" or "txpru" to find RTU & TX_PRU
     cores on ICSSG devices.

     ::

        grep -Isr pru /sys/kernel/debug/remoteproc/

   * Next, use the sysfs interface to set **firmware** equal to the name of the
     PRU firmware.
     RemoteProc starts looking for firmware at /lib/firmware.
     For example, to tell the RemoteProc driver that the PRU core at remoteproc1
     should load /lib/firmware/pru/firmwareName.out, use this command:

     ::

        echo 'pru/firmwareName.out' > /sys/class/remoteproc/remoteproc1/firmware

#. Use the remoteproc sysfs interface to load and then run the PRU cores. Once
   'start' has been echoed into the **state** attribute, the remoteproc firmware
   will load the PRU cores and then run them.

   ::

      echo 'start' > /sys/class/remoteproc/remoteproc1/state

.. toctree::
   :maxdepth: 1

   PRU-Getting-Started-Labs_Lab4_TIRTOS
