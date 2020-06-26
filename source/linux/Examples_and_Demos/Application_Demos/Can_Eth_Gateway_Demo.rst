.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_CAN_Eth_Gateway_Demo

CAN to ethernet Gateway demo
============================

Overview
--------

Gateway is one of the major use cases in modern cars. Performance
requirements for gateway applications are ever increasing due to the advanced
connected car architecture having multiple domain controllers.

The CAN-Ethernet gateway demo showcases P2P (Protocol to Protocol) translation
i.e. translating data and control information between incompatible networks
like Ethernet and CAN for communication on the J721E device through the IEEE-1722 protocol.

The demo application enables full duplex routing between: CAN-to-Ethernet, 
Ethernet-to-CAN and CAN-to-CAN. The demo uses MCAL drivers running on MCU R5F.

Changes over previous release
-----------------------------
* Previous gateway demo used CPSW 9G Ethernet switch and used PDK components. Current 
  demo uses CPSW 2G Ethernet port and MCAL components.
* Support for Ethernet-to-Ethernet routing has been deprecated since only one port of CPSW 2G is
  available on the EVM.
* Application has moved from Main domain R5F to MCU domain R5F.
* Instead of TCP/IP, this demo uses IEEE 1722 protocol. A very basic 1722 parser has been implemented
  in the application.
* Since raw sockets are used, Windows PC cannot be used to run PC tools. Sudo access is also required
  for the same reason.
* Support for CPSW 9G and Main domain R5F will be enabled in future releases.
* **Important** - Support for Maxwell has been deprecated.

Assumptions and Prerequisities
------------------------------
Before getting into more details, readers should familiarize themselves 
with the assumptions made in this document and general demo requirements.

Assumptions
^^^^^^^^^^^

* Basic familiarity with operating any CAN device capable of sending and
  receiving CAN-FD messages. This includes knowledge of wiring and signals.
  In this demo, the PCAN tool is used to show the same.
* Basic familiarity with Ethernet interface and IEEE 1722 protocol
* Knowledge of raw sockets is helpful, but not essential
* Operation of a PC/System running Linux. Since raw sockets are used, Windows is not supported.
* Basic familiarity with Jacinto 7 Architecture 
* For details on individual parts of the Jacinto 7, such as MCAN, MCU island, and other parts, 
  readers are asked to read SoC documentation first (if they haven't done so already).

Hardware
^^^^^^^^

* J721E EVM Board (SOM Board and Common Board)
* CAN Receiver/Transmitter with minimum of 2x ports and a GUI to display messages. This demo
  shows this with 2x PCAN tools, but it can be ideally be any tool.
  Refer to :ref:`PCAN tool setup <pcan-tool-setup>` section for further details.
* 1x LAN Cables (preferably CAT6)
* 2x Micro USB cable (for UART and JTAG)
* SD card (This is the recommended boot option.)
* Linux PC with minimum of 1x Gigabit port and root access
.. important::
  Root access is required because the demo uses raw sockets, and raw sockets are only accessible with
  root privileges.
* Windows PC to run PCAN-View software. PCAN-View is also available on Linux but not used in this demo.
  It's also possible that user may choose to use a different PCAN device, in which case this is optional.

Software
^^^^^^^^

* Code Composer Studio (CCS) version 9.0.1.00004. (Optional if SD card is not available)
* PC Ethernet tools - Required for receiving and transmitting data over Ethernet

    * Use/run ``recv_1722.out``, ``send_1722.out`` and ``control_gateway_app.out`` utilities on host PC. These
      utilities are available at: ::

        <SDK_INSTALL_PATH>/gateway-demos/pctools

* CAN tool software (PCAN drivers and PCAN View if using PCAN-USB tool)

Architecture Overview
---------------------

The following block diagram shows the various functional blocks and the data
flow used in the gateway demo application. As shown in the diagram, PC Ethernet
applications are used for transmitting and receiving Ethernet frames between
PC and the J721E EVM. Similarly, any compatible CAN tool can be used for CAN
message reception and transmission.

.. Image:: /images/CanEth_MCAL_SW_Arch.png
   :height: 912px
   :width: 1635px
   :scale: 40 %
   :alt: J721E Demo setup graphic
   :align: center

The routing is done based on a queue-based architecture, where the gateway task periodically polls the
CAN and Ethernet queues, which are, in turn, populated by the respective drivers in the interrupt context. This
architecture allows full packet inspection of packet and allows matching two asynchronous interfaces like Ethernet
and CAN.

The CAN/Ethernet demo application is supported only on the mcu1_0 core of the J721E device.

Software Features
-----------------

-  Routing at L2 within application, through IEEE 1722 protocol for CAN-to-Ethernet and Ethernet-to-CAN
-  CAN-to-CAN routing through application
-  PC-based raw socket applications for sending/receiving 1722 frames and controlling gateway app
-  Weighted average bridge delay computation for all routed packets


Directory Structure
-------------------

The CAN_ETH Gateway demo is located in the Processor SDK RTOS release under the
following directory path: ::

    <SDK_INSTALL_PATH>/gateway-demos/can_eth_gateway

User must issue make command from <SDK_INSTALL_PATH>/gateway-demos location. Detailed description of the directory structure is given below:

-  binary - directory where gateway app and other compiled binaries are generated
-  pctools - directory containing Ethernet PC tools sources and executables
-  src - Source files for gateway application and utils
-  docs - Contains User Guide PDF
-  mcuss_demos - Contains MCUSW components which are specific to gateway app
-  build - Contains the makefile infrastructure

.. note::
    Pre-built binary tools are provided for Linux only.


Components
----------

RTOS components:

-  SYSBIOS
-  XDC

Processor SDK RTOS drivers:

-  MCUSW components like CAN, Eth
-  UART
-  Board
-  OSAL
-  CSL
-  udma
-  sciclient


Building the Demo
-----------------

The demo application is built using makefile.

.. Note::
    Refer to PDK rules.mk for setting tools paths. Run following commands
    after this has been done.

Type the following in <SDK_INSTALL_PATH>/gateway-demos to see makefile options: ::

    make help

The following are steps to clean the demo: ::

    cd <SDK_INSTALL_PATH>/gateway-demos
    make allclean

The following are steps to compile the demo with all dependencies: ::

    cd <SDK_INSTALL_PATH>/gateway-demos
    make all -s -j

Host Applications
-----------------

The PC tools for Ethernet reception, transmission and control are located under pctools
directory. These tools can be built for Linux only through: ::

    cd <SDK_INSTALL_PATH>/gateway-demos/pctools
    make all

Running the Demo
----------------

This demo uses MCAN0, MCAN1 and CPSW2G's port on the board. They are connected
to two PCAN-USB tools and PC's Ethernet gigabit port respectively. See below:

J721E Board Setup
^^^^^^^^^^^^^^^^^

Conceptually the wiring should be done as shown below:

.. Image:: /images/CanEth_MCAL_demo_setup_graphic.png
   :height: 595px
   :width: 1004px
   :scale: 70 %
   :alt: Graphical representation of J721E demo setup showing all connections
   :align: center

When actual connections are made it looks like below:

.. Image:: /images/CANEth_MCAL_complete_setup_annotated.jpg
   :height: 1125px
   :width: 1500px
   :scale: 50 %
   :alt: Picture of J721E Demo setup on ESD mat with all wires connected
   :align: center

Ethernet Setup
''''''''''''''
As shown in the figure above, connect the CPSW 2G Ethernet port to PC's 1G Ethernet port and
assign a fixed local IP to the interface to avoid unnecessary ARP traffic.

MCAN Setup
''''''''''

As shown in the picture, connect the two USB-CAN analyzers to MCAN0 and MCAN1 instances, which are labeled as J30
and J32 respectively on the J721E base EVM board. The MCAN pin connection is as follows:

    * Pin 1 (CAN_H)
    * Pin 2 (GRD)
    * Pin 3 (CAN_L)

The following diagram shows the MCAN0 and MCAN1 connections on base EVM.

.. Image:: /images/CANEth_MCAL_MCAN_ports.jpg
  :height: 3456px
  :width: 4608px
  :scale: 20 %
  :alt: CAN connections on base board
  :align: center

If using PCAN tool, the DB-9 connection is as follows:

.. can-eth-pcan-connection:
.. Image:: /images/CanEth_PCANConnection.png
   :height: 1000px
   :width: 1500px
   :scale: 30 %
   :alt: PCAN tool pinout
   :align: center

Use below image as reference to connect the wires.

.. Image:: /images/CanEth_MCAL_MCAN_Wiring.jpg
   :height: 595px
   :width: 1602px
   :scale: 80 %
   :alt: PCAN tool pinout
   :align: center

PCAN Tool Setup
^^^^^^^^^^^^^^^

The PCAN-USB FD tool has been used to validate this demo. This tool provides a
connection of CAN FD and CAN networks to a computer through USB.

For further information on the PCAN-USB product, please visit the manufacturer's
website: https://www.peak-system.com/PCAN-USB-FD.365.0.html?&L=1

.. note::

    Please check licensing information & terms of usage of PCAN-USB product and
    make sure it adheres to your organization's policy before downloading the
    drivers.

#. Prerequisite (PC setup):

    * Download and install PCAN driver from: https://www.peak-system.com/quick/DrvSetup
    * Download PCAN-View from: https://www.peak-system.com/fileadmin/media/files/pcanview.zip

#. PCAN Setup:

    * PCAN-View is a GUI-based tool used to configure bit-rate of the PCAN tool.
      It provides a convenient way to see sent and received messages. It also
      provides an option to enable tracing of CAN messages along with timestamp.
      Please refer to PCAN-USB FD manual for more details.
    * Once driver is installed, connect the PCAN device to PC. It should be auto
      detected as **PCAN-USB FD** in Windows' **Device Manager**. If it is not
      auto detected, try re-installing the PCAN driver.
    * Open PCAN-View and follow below steps:

        * Click on **Connect** from **CAN** menu (as shown in below figure)

            * Pop-up window shall show connected PCAN hardware. Select the
              desired device.
            * Enable the **Data Bit rate** checkbox. This will enable Bit rate
              selection from a drop down menu.
            * Select **Nominal Bit Rate** as **1 MBits/s**.
            * Select **Data Bit Rate** as **5 MBits/s**. If this bit-rate is not
              listed in your menu, refer to 'Creating Bit Rate Configurations'
              step below for creating custom bit rate.

                  * **Note:** Bit rates may vary from use case to use case based
                    on MCAN configuration on the J721E side.
            * Click on **OK** button.

            .. Image:: /images/CanEth_PCANViewDeviceSelection.png
               :height: 500px
               :width: 500px
               :scale: 70 %
               :alt: PCAN View - Device Selection
               :align: center

        * Create and send message at period of 1 ms

            * Click on **New Message** under **Transmit** menu
            * Enable the **CAN FD** checkbox
            * Enable the **Bit Rate Switch** checkbox
            * Set the following parameters in the **New Transmit Message** window:

                * **ID** as hex **000000C0** for MCAN0 and **000000B0** for MCAN1
                * **Length** as **64**
                * **Cycle Time** as **1**
                * **Data** can be selected randomly

            .. Image:: /images/CanEth_PCANViewTransmitMessageConfig.png
               :height: 500px
               :width: 600px
               :scale: 80 %
               :alt: PCAN View - Transmit Mesage Config
               :align: center

#. Creating Bit Rate Configurations

    * Create a 5 Mbps bit rate configuration for **Data Bit Rate** (shown in below
      :ref:`diagram <pcan-view-bit-rate-config>`)

        * Click on **Connect** under **CAN** menu
        * Enable the **Data Bit rate** checkbox
        * Click on the **Play** button below **Data Bit rate** and then **Manage
          Bit rates**. This will open a pop-up window.
        * Click on **Data** in the **Manage Bit Rates** window
        * Select **Clock Frequency** as **80 MHz**
        * Click on **Add** button
        * Set the new bit rate parameters as follows:

              * **Caption** to **5 MBits/s**
              * **Prescalar** to **1**
              * **tseg1** to **12**
              * **tseg2** to **3**
              * **Sync Jump Width** to **1**

        * **Bit Rate** textbox shall show **5 Mbit/s** after programming above values.
        * Click on **OK** and then again on **OK**

    .. _pcan-view-bit-rate-config:
    .. Image:: /images/CanEth_PCANViewBitRateConfig.png
      :height: 500px
      :width: 800px
      :scale: 80 %
      :alt: PCAN View - Bit Rate Config
      :align: center

#. CAN Bus Connections - Please refer to the PCAN-USB FD manual for more
   details about connections.

#. CAN Bus Connections (applies if single PCAN device is used for 2 CAN's using
   breadboard):

    * **CAN_H** of all the nodes on the bus shall be connected together
    * Similarly, **CAN_L** of all the nodes on the bus shall be connected
      together


Load and Run the Demo
^^^^^^^^^^^^^^^^^^^^^

CCS Boot
''''''''

For more details about installation of CCS and J721E target creation, refer to the Processor SDK RTOS
   Automotive User's Guide inside "psdk_rtos_auto/docs/user_guide" folder, which can be found in SDK installation.

#. Connect a micro USB cable to JTAG port of J721E_EVM. The XDS110 JTAG
   connector is labeled ``XDS110`` (J3).
#. Connect a micro USB cable to MCU Domain UART port on J721E_EVM. It's
   labeled ``MCU UART`` (J43).
#. Set EVM's DIP switches ``SW8`` and ``SW9`` for no-boot mode:

    * SW8 = 10001000
    * SW9 = 01110000

#. Power on the J721E EVM board. Ensure that SD card is not present or QSPI
   flashed.
#. Open up a serial terminal to ttyUSB1 for UART communication. This will show logs from MCU1_0 core where the demo application runs.

    * Set serial parameters to: 115200 8N1.
    * Set hardware and software flow control to "No".
    * Below figure shows serial parameters set in Minicom.

   .. Image:: /images/CanEth_MCAL_minicom_setting.png
      :scale: 50 %
      :alt: Serial Port Settings in Minicom
      :align: center

#. Open CCS and launch target config file for J721E_EVM.
#. Load the System firmware using launch script provided with this package.
#. Wait for initialization and then connect to MCU domain R5F_0_1.
#. Load and launch the demo executable: ::

    <SDK_INSTALL_PATH>/binary/gatewayapp/bin/j721e_evm/gatewayapp_mcu1_0_release.xer5f

#. The application should boot up with the console log shown below. Note that the Ethernet interface takes a few seconds to come up.

.. Image:: /images/CanEth_MCAL_after_bootup.png
   :height: 233px
   :width: 1096px
   :scale: 100 %
   :alt: Bootup console log
   :align: center

SD Card Boot
''''''''''''

#. Create a bootable SD card with SBL bootloader and System Firmware.
   For details about SD card creation, refer to the Processor SDK RTOS
   Automotive User's Guide inside "psdk_rtos_auto/docs/user_guide" folder, which can be found in SDK installation.
#. Copy the CAN/Eth gateway demo application to the /boot folder in SD Card and rename
   it to "app".
#. Connect a micro USB cable to MCU Domain UART port on J721E_EVM. It's
   labeled ``MCU UART`` (J43).
#. Set EVM's DIP switches ``SW8`` and ``SW9`` for SD card boot:

    * SW8 = 10000010
    * SW9 = 00000000

#. Open up a serial terminal to port ttyUSB0 for UART1 communication. This terminal will show
   logs from system firmware.

    * Set serial parameters to: 115200 8N1.

#. Open up a serial terminal to port ttyUSB1 for UART2 communication. This terminal will show
   logs from MCU1_0 core where the demo application runs.

    * Set serial parameters to: 115200 8N1.
    * Set hardware and software flow control to "No".
    * Below figure shows serial parameters set in Minicom.

   .. Image:: /images/CanEth_Minicom.png
      :scale: 100 %
      :alt: Serial Port Settings in Minicom
      :align: center

#. Insert SD card into slot labeled ``MICRO SD`` and power-on the J721E
   EVM board.
#. The application should boot up with a console log as shown below:

.. Image:: /images/CanEth_MCAL_after_bootup.png
   :height: 233px
   :width: 1096px
   :scale: 100 %
   :alt: Bootup console log
   :align: center

.. _routing:

Routing
^^^^^^^

The demo performs three kinds of routing: CAN-to-CAN, CAN-to-Eth and Eth-to-CAN. The behavior can be 
controlled by PCAN tool and PC tools provided along with the demo sources. 

Eth to CAN
''''''''''

Eth-to-CAN direction involves the following routes:

+-------------------------+-------------+-------------+------------+
|          Route          |    Source   | Destination | Message ID |
+=========================+=============+=============+============+
|  Eth ->                 |             |             |            |
|  Gateway ->             |     Eth     |    PCAN 1   |    0xD0    |
|  MCAN0 -> PCAN1         |             |             |            |
+-------------------------+-------------+-------------+------------+
|  Eth ->                 |             |             |            |
|  Gateway ->             |     Eth     |    PCAN 2   |    0xE0    |
|  MCAN1 -> PCAN2         |             |             |            |
+-------------------------+-------------+-------------+------------+
|  Eth ->                 |             |             |            |
|  Gateway ->             |     Eth     |  PCAN 1+2   |    0xF0    |
|  MCAN0+1-> PCAN1+2      |             |             |            |
+-------------------------+-------------+-------------+------------+

Follow the next steps to test Eth-to-CAN routes:

#. In Linux PC, open console and run: ::

    cd <SDK_INSTALL_PATH>/gateway-demos/pctools
    sudo ./send_1722.out <eth_interface> 1 MCAN0

  Where <eth_interface> is the name of ethernet interface on the Linux PC. On most PC's, it's either eth0 or eth1, but it can be anything and thus no standard convention.
  ``1`` is the number of messages to be sent and ``MCAN0`` indicates that a CAN ID of 0xD0 should be embedded inside the 1722 message.

  This will send one 1722 message with CAN ID of 0xD0. When gateway demo sees this message, it will route it to MCAN0 interface.

#. Now try the same command with MCAN1 option: ::

    sudo ./send_1722.out <eth_interface> 1 MCAN1

#. Finally, route the packet to both interfaces with the command: ::

    sudo ./send_1722.out <eth_interface> 1 BOTH

#. A screenshot of send_1722.out console application is shown below:

.. Image:: /images/CanEth_MCAL_send_1722.png
   :height: 338px
   :width: 1102px
   :scale: 70 %
   :alt: Bootup console log
   :align: center

CAN to Eth and CAN to CAN
'''''''''''''''''''''''''

CAN-to-Eth and CAN-to-CAN routing are bundled together in the demo application. When a CAN message
is received by the gateway demo, it forwards it without any modification to the other CAN port and also forwards
it as a formatted 1722 ethernet message to the Ethernet port.

.. note::
    MCAN0 is configured to receive only messages with CAN ID of 0xC0, and MCAN1 is configured for 0xB0.

CAN-to-Eth and CAN-to-CAN direction involves the following routes:

+-------------------------+--------+-------------+------------+
|          Route          | Source | Destination | Message ID |
+=========================+========+=============+============+
|  PCAN1 -> MCAN0 ->      |        |             |            |
|  Gateway ->             |  PCAN1 | Eth + MCAN1 |    0xC0    |
|  Eth + MCAN1 -> PCAN2   |        |             |            |
+-------------------------+--------+-------------+------------+
|  PCAN2 -> MCAN1 ->      |        |             |            |
|  Gateway ->             |  PCAN2 | Eth + MCAN0 |    0xB0    |
|  Eth + MCAN0 -> PCAN1   |        |             |            |
+-------------------------+--------+-------------+------------+

Follow the next steps to test CAN-to-Eth and CAN-to-CAN routes:

#. In Linux PC, open console and run: ::

    cd <SDK_INSTALL_PATH>/gateway-demos/pctools
    sudo ./a.out <eth_interface> non-verbose

   In this case, non-verbose indicates that console application should not print too many details from the 1722 frame. If verbose
   mode is chosen, then details of the 1722 packet are printed.


   This allows reception of 1722 frames on Linux PC's ethernet interface where the console application parses them and displays a continuous count.

#. Send a message with CAN ID of 0xC0 on PCAN1. The message will be routed to both PCAN2 and the Ethernet port where
   it will be shown by the application. See figures below:

   .. Image:: /images/CanEth_MCAL_recv_1722.png
      :height: 269px
      :width: 727px
      :scale: 80 %
      :alt: 1722 Receive App
      :align: center

   
#. Now repeat same process with PCAN2. This time, send a message with CAN ID of 0xB0. See figure below:

    .. Image:: /images/CanEth_MCAL_PCAN_Tool.png
       :height: 1044px
       :width: 1904px
       :scale: 40 %
       :alt: PCAN Tool view
       :align: center

Statistics
^^^^^^^^^^
Since gateway demo is an application which runs in a forever loop waiting for frames, it's not possible to show stats periodically, 
as it would impact performance. To workaround this problem, a separate console application called ``control_gateway_app.out`` is
provided which sends a signal to the application to print statistics. To run the app use the command below: ::

    cd <SDK_INSTALL_PATH>/gateway-demos/pctools
    sudo ./control_gateway_app.out <eth_interface> stat

``control_gateway_app.out`` provides two options to the user: ``kill`` and ``stat`` (both are documented inside the application).
When ``stat`` is used, the demo application prints performance and statistics including CPU Load. 

``kill`` terminates the application (it's reserved for future use)

See figure below:

.. Image:: /images/CanEth_MCAL_Stats.png
    :height: 329px
    :width: 1114px
    :scale: 60 %
    :alt: PCAN Tool view
    :align: center

.. _known-issues-limitations:

Known issues & limitations
^^^^^^^^^^^^^^^^^^^^^^^^^^

#. Polling mode is not supported in Gateway application.
#. Due to simultaneous Rx and Tx, the CAN-USB Tool might go into an error state. When this happens, the CAN-USB Tool
   blinks red constantly, and no CAN messages are seen on the bus. To recover, first ``Disconnect (Ctrl + D)`` and then ``Connect (Ctrl + B)``
   the device. See below:

    .. Image:: /images/CanEth_MCAL_reset_pcan.png
      :height: 658px
      :width: 897px
      :scale: 50 %
      :alt: PCAN Tool view
      :align: center


