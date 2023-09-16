.. http://processors.wiki.ti.com/index.php/Lauterbach

How to Setup and Debug using Lauterbach
==========================================

.. rubric:: Introduction Lauterbach
   :name: introduction-lauterbach

This guide discusses how to use TRACE32 and Lauterbach for Debugging.

Lauterbach provides integrated debug environments for embedded designs.

The tool chain in Lauterbach includes:
	- Debugger
	- Real-time trace for program/data flow
	- Logic analyzer

These capabilities are implemented by dedicated hardware components.

.. rubric:: TRACE32
   :name: introduction-TRACE32

The TRACE32 toolset supports a large number of microprocessors, real-time operating systems,
integrations, and eco-systems.

.. rubric:: Connecting Lauterbach to Board
   :name: connect-Lauterbach

For connecting Lauterbach to the board, following things are required:

- 7-9 V power supply

- Debug Cable (JTAG)

- 20 pin JTAG Header

- USB Cable


Connect the USB Cable to the host machine. The Debug Cable (JTAG) will be connected to the board via the 20 pin JTAG Header.

.. ifconfig:: CONFIG_part_family in ('AM62X_family')

   Following image shows the setup of AM62x with Lauterbach

   .. Image:: /images/am62x_setup.jpg
      :width: 380

.. ifconfig:: CONFIG_part_family in ('AM64X_family')

   Following image shows the setup of AM64x EVM with Lauterbach

   .. Image:: /images/am64x_setup.jpg
      :width: 900

|

For more information regarding the setup please refer `this. <https://www2.lauterbach.com/pdf/installation.pdf>`__

.. rubric:: Downloading and Installing TRACE32
   :name: download-install-TRACE32

You can download and install the latest version of TRACE32 from `here. <https://www.lauterbach.com/frames.html?home.html>`__

.. rubric:: Debugging with TRACE32
   :name: debug-TRACE32

To open the TRACE32 software after installing, search for **Trace 32 (ARM V8 USB) Launcher Application** on your system and open it.

A window will popup as shown below

.. Image:: /images/TRACE32_launch.png
   :width: 900

Now as per your debugging requirements, select the desired cmm files.
For this, from menu bar go to **File --> Open Script**.
Select the desired cmm file and select **Do**.
This will set target type, open some windows, assemble some
code in SRAM, execute that code. You should be able to trace this
code in the list window.

.. rubric:: CMM Files
   :name: cmm-TRACE32

.. ifconfig:: CONFIG_part_family in ('AM62X_family')

   To download cmm files for AM62x go to `AM62 cmm files <https://www.lauterbach.com/frames.html?scripts.html>`__ and search **am62xx**.

.. ifconfig:: CONFIG_part_family in ('AM64X_family')

   To download cmm files for AM64x go to `AM64 cmm files <https://www.lauterbach.com/frames.html?scripts.html>`__ and search **am64xx**.

.. rubric:: Tracing a Simple demo script for Cortex-A53
   :name: sample_cmm-TRACE32

.. ifconfig:: CONFIG_part_family in ('AM62X_family')

   1. Go to Lauterbach website and download the **hardware-arm-am62xx-am62x-skevm-am62x-ca53_20221026000946_all_files.zip** and **hardware-arm-am62xx-am62x-skevm-scripts_20221026000946_all_files.zip** and place them in a single directory.

   2. Extract both the directories and rename the **hardware-arm-am62xx-am62x-skevm-scripts_20221026000946_all_files** to **scripts** because the cmm files expect it.

   3. Open the **Trace 32 (ARM V8 USB) Launcher Application** on your system. From menu bar go to **File --> Open Script**. Select any cmm file from **hardware-arm-am62xx-am62x-skevm-am62x-ca53_20221026000946_all_files** directory **(Eg: am62x_sieve_sram.cmm)**.

   4. The am62x_sieve_sram.cmm file loads the sieve demo application into PSRAM and sets up a demo debug scenario.

   5. Click on **Do** in the Menu bar to start the execution. The *B::List:auto command* inside the **am62x_sieve_sram.cmm** file will open the **sieve.c** file for debugging.

   6. Inside the B::List:auto window, there are local buttons for all basic debug commands. We can click on *Step* to Single stepping and *Over* to Step over call.

   7. You can stop the execution at any point by clicking on **Break** in B::List:auto window.

   8. A sample output after breaking at a particular point is shown below.

   .. Image:: /images/am62x_sieve_sram_TRACE32.png
      :width: 900

.. ifconfig:: CONFIG_part_family in ('AM64X_family')

   1. Go to Lauterbach website and download the **hardware-arm-am64xx-am64x-skevm-am64x-ca53_20220914014048_all_files.zip** and **hardware-arm-am64xx-am64x-skevm-scripts_20220914014048_all_files.zip** and place them in a single directory.

   2. Extract both the directories and rename the **hardware-arm-am64xx-am64x-skevm-scripts_20220914014048_all_files** to **scripts** because the cmm files expect it.

   3. Open the **Trace 32 (ARM V8 USB) Launcher Application** on your system. From menu bar go to *File --> Open Script*. Select any cmm file from **hardware-arm-am64xx-am64x-skevm-am64x-ca53_20220914014048_all_files** directory **(Eg: am6442_sieve_sram.cmm)**.

   4. The am6442_sieve_sram.cmm file loads the sieve demo application into RAM and sets up a demo debug scenario.

   5. Click on **Do** in the Menu bar to start the execution. The *B::List:auto command* inside the **am6442_sieve_sram.cmm** file will open the **sieve.c** file for debugging.

   6. Inside the B::List:auto window, there are local buttons for all basic debug commands. We can click on *Step* to Single stepping and *Over* to Step over call.

   7. You can stop the execution at any point by clicking on **Break** command in B::List:auto window.

   8. A sample output after breaking at a particular point is shown below.

   .. Image:: /images/am64x_sieve_sram_TRACE32.png
      :width: 900

|

For more information on debugging with TRACE32 refer `this. <https://www2.lauterbach.com/pdf/training_debugger.pdf>`__
