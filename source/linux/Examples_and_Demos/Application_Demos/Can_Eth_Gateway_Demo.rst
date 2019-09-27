.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_CAN_Eth_Gateway_Demo

CAN to ethernet Gateway demo
============================

Overview
--------

Gateway is one of the major use-cases in the modern cars. Performance
requirements for gateway applications are ever increasing due to the advanced
connected car architecture having multiple domain controllers.

The CAN-Ethernet gateway demo showcases P2P (Protocol to Protocol) translation
i.e. translating data and control information between incompatible networks
like Ethernet and CAN for communication on AM65xx & J721E devices. The demo
application enables full duplex routing between CAN and Ethernet:
CAN-to-Ethernet, Ethernet-to-CAN, CAN-to-CAN and Ethernet-to-Ethernet. This
demo also shows handling of high bandwidth data traffic on Cortex-R5 with low
CPU load and latency for a bridging application, leaving the Cortex-A53 free
for application processing.

On the Ethernet front, this application also demonstrates basic Layer-2
switching with VLAN, multicast among the ports in the Ethernet Switch (CPSW9G)
integrated in the J721E device. The traffic forwarding process among the ports
doesn't require CPU involvement or DMA bandwidth, as everything is completely
handled by the CPSW hardware.


Architecture Overview
---------------------

The following block diagram shows the various functional blocks and the data
flow used in the gateway demo application. As shown in the diagram, PC Ethernet
applications are used for transmitting and receiving Ethernet frames between
PC and the J721E EVM. Similarly, any compatible CAN tool can be used for CAN
message reception and transmission.

.. Image:: ../../../images/CanEth_J7GatewayArchitecture.jpg
   :height: 1000px
   :width: 1500px
   :scale: 50 %
   :alt: J7 Gateway Demo Architecture
   :align: center

The CAN/Ethernet demo application is supported only on the mcu2_0 core of J721E.

Software Features
-----------------

-  Routing application for CAN-to-Ethernet, Ethernet-to-CAN, CAN-to-CAN and
   Ethernet-to-Ethernet.
-  Network APIs for creating TCP/IP applications.
-  CPU load benchmark utils.


Directory Structure
-------------------

The CAN_ETH Gateway demo is located in the Processor SDK RTOS release under the
following directory path: ::

    <SDK_INSTALL_PATH>/gateway-demos/can-eth-gateway

Detailed description of the directory structure is given below:

-  output - directory contains prebuilt out file and PC tools executables
-  build - directory contains makefiles, SYSBIOS configuration, linker files for
   build
-  pctools - directory contains Ethernet PC tools
-  src - Source files for gateway application, utils and network APIs

.. note::
    Pre-built binary tools are provided for Linux only. For Windows, user needs
    to build them locally.


Components
----------

RTOS components:

-  SYSBIOS
-  XDC
-  NDK

Processor SDK RTOS drivers:

-  CPSW LLD
-  NIMUCPSW Library from CPSW LLD
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

The following are steps to clean the demo: ::

    cd <SDK_INSTALL_PATH>/gateway-demos/can-eth-gateway
    make clean BOARD=j721e_evm

The following are steps to compile the demo: ::

    cd <SDK_INSTALL_PATH>/gateway-demos/can-eth-gateway
    make gatewayapp CORE=mcu2_0 BOARD=j721e_evm

If static IP configuration is not feasible, set ``enableStaticIP`` flag to 0 in
the BIOS config file in below path, and then rebuild the example. ::

    <SDK_INSTALL_PATH>/gateway-demos/can-eth-gateway/build/j721e/nimuExample_r5.cfg


Host Applications
-----------------

The PC tools for Ethernet reception and transmission are located under pctools
directory. These tools can be built for Linux and Windows. ::

    cd <SDK_INSTALL_PATH>/gateway-demos/can-eth-gateway/pctools
    make all


Running the Demo
----------------

This demo exercises MCAN6 and MCAN9 as well as CPSW9G's MAC ports 1-3.

The following table describes the message IDs which are hardcoded in the demo
application.

+------------+-------------------------+-------------+-------------+------------+
| Direction  |          Route          |    Source   | Destination | Message ID |
+============+=========================+=============+=============+============+
|            |  PCAN1 -> MCAN6 ->      |    PCAN1    |    MCAN6    |     004    |
|            |  **Gateway Router** ->  +-------------+-------------+------------+
|            |  MCAN9 -> PCAN2         |    MCAN9    |    PCAN2    |     009    |
| CAN to CAN +-------------------------+-------------+-------------+------------+
|            |  PCAN2 -> MCAN9 ->      |    PCAN2    |    MCAN9    |     005    |
|            |  **Gateway Router** ->  +-------------+-------------+------------+
|            |  MCAN6 -> PCAN1         |    MCAN6    |    PCAN1    |     006    |
+------------+-------------------------+-------------+-------------+------------+
|            |  PCAN1 -> MCAN6 ->      |    PCAN1    |    MCAN6    |     004    |
|            |  **Gateway Router** ->  +-------------+-------------+------------+
|            |  Eth -> eth_rx          |    Eth      |    eth_rx   |     009    |
| CAN to Eth +-------------------------+-------------+-------------+------------+
|            |  PCAN2 -> MCAN9 ->      |    PCAN2    |    MCAN9    |     005    |
|            |  **Gateway Router** ->  +-------------+-------------+------------+
|            |  Eth -> eth_rx          |    Eth      |    eth_rx   |     006    |
+------------+-------------------------+-------------+-------------+------------+
|            |  eth_tx -> Eth ->       |    eth_tx   |    Eth      |     006    |
|            |  **Gateway Router** ->  +-------------+-------------+------------+
|            |  MCAN6 -> PCAN1         |    MCAN6    |    PCAN1    |     006    |
| Eth to CAN +-------------------------+-------------+-------------+------------+
|            |  eth_tx -> Eth ->       |    eth_tx   |    Eth      |     009    |
|            |  **Gateway Router** ->  +-------------+-------------+------------+
|            |  MCAN9 -> PCAN2         |    MCAN9    |    PCAN2    |     009    |
+------------+-------------------------+-------------+-------------+------------+


Prerequisities
^^^^^^^^^^^^^^

Hardware
''''''''

* J721E EVM Board (SOM Board and Common Board).
* J721E GESI Board (Gateway/Ethernet Switch/Industrial expansion board).
* CAN Receiver/Transmitter - PC tool to receive and transmit the CAN messages.
  Refer to :ref:`PCAN tool setup <pcan-tool-setup>` section for further details.
* LAN Cables (preferably CAT6).
* SD card.
* Linux/Windows PCs.

  * **Optional** - USB 3.0 Gigabit Ethernet adapters can be used to extend
    Ethernet port capability, instead of relying on multiple PCs.

Software
''''''''

* Code Composer Studio (CCS) version 9.0.1.00004.
* PC Ethernet tools - Required for receiving and transmitting data over
  Ethernet.

    * Use/run ``eth_rx.out`` and ``eth_tx.out`` utilities on host PC. These
      utilities are available at: ::

        <SDK_INSTALL_PATH>/gateway-demos/can-eth-gateway/pctools

* CAN tool software (PCAN drivers and PCAN View if using PCAN-USB tool).
* DHCP server. Refer to online documentation from respective Linux or Windows
  communities.
* Plex TV media server.


J721E Board Setup
^^^^^^^^^^^^^^^^^

The GESI expansion board is required for connecting to J721E MAIN domain MCAN
modules and using CPSW9G Ethernet Switch.

In case the J721E GESI board is not installed into the J721E EVM, attach it to
bottom side of the J721E Common board.

.. Image:: ../../../images/CanEth_GESIBoard.jpg
   :height: 1000px
   :width: 1500px
   :scale: 45 %
   :alt: J721E GESI board
   :align: center

Ethernet Setup
''''''''''''''

There are four RGMII PHYs in the J721E GESI board. They will be referred to as
**MAC Port 0**, **MAC Port 1**, **MAC Port 2** and **MAC Port 3** thoughout this
document.

.. _gesi-board-side-view:
.. Image:: ../../../images/CanEth_GESIBoardSideView.png
   :height: 1000px
   :width: 1500px
   :scale: 40 %
   :alt: RJ45 connectors on GESI board
   :align: center

#. Connect laptops/PCs as per connection shown in the diagram below.

    .. _eth-connection:
    .. Image:: ../../../images/CanEth_EthConnection.png
       :height: 1000px
       :width: 1500px
       :scale: 35 %
       :alt: Ethernet MAC port connections
       :align: center

    .. note::

       Do not connect any device to **MAC Port 0** as it may not be fully
       functional, please refer to the :ref:`known-issues-limitations` section
       for further details.

    .. note::

       If using DHCP configuration, DHCP server must be connected to **MAC Port 1**.

#. As depicted in the previous :ref:`connections diagram <eth-connection>`, the
   static IPs for all devices required in this demo can be set as follows:

    =================================  =============
     Device                             IP address
    =================================  =============
    Laptop running CAN Eth tools       192.168.1.200
    Laptop running Plex client         192.168.1.201
    Laptop running Plex server         192.168.1.202
    J721E when **enableStaticIP** = 1  192.168.1.203
    Default Gateway                    192.168.1.1
    Subnet Mask                        255.255.255.0
    =================================  =============

    * Refer to the following website for suggested instructions about static IP
      configuration under a Windows environment:
      https://www.howtogeek.com/howto/19249/how-to-assign-a-static-ip-address-in-xp-vista-or-windows-7/

#. **Optional** - If static IP configuration is not possible, a local DHCP
   server can be setup in a Linux PC as shown in the
   :ref:`connections diagram <eth-connection>` above. Otherwise, it's also
   possible to connect the **MAC Port 1** to a wider network running DHCP.

MCAN Setup
''''''''''

The MCAN6 and MCAN9 instances which are used for this demo are labeled ``MC6`` (J10)
and ``MC9`` (J6), respectively, in the J721E GESI board. The MCAN pin connection
is as follows:

    * Pin 1 (CAN_H)
    * Pin 2 (GRD)
    * Pin 3 (CAN_L)

The following diagram shows the MCAN6 and MCAN9 connections on GESI board.

.. Image:: ../../../images/CanEth_GESIBoardMcanConnection.png
  :height: 500px
  :width: 800px
  :scale: 70 %
  :alt: CAN connections on GESI board
  :align: center

If using PCAN tool, the DB-9 connection is as follows:

.. can-eth-pcan-connection:
.. Image:: ../../../images/CanEth_PCANConnection.png
   :height: 1000px
   :width: 1500px
   :scale: 30 %
   :alt: PCAN tool pinout
   :align: center

Finally, the following picture shows all connections in the demo, including MCANs
and MAC ports.

.. can-eth-demo-connections:
.. Image:: ../../../images/CanEth_GESIBoardConnections.jpg
   :height: 1000px
   :width: 1500px
   :scale: 50 %
   :alt: CAN/ETH demo connections
   :align: center

.. _pcan-tool-setup:

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
      It provides a convenient was to see sent and received messages. It also
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
              selection from a drop down menu
            * Select **Nominal Bit Rate** as **1 MBits/s**
            * Select **Data Bit Rate** as **5 MBits/s**. If this bit-rate is not
              listed in your menu refer to 'Creating Bit Rate Configurations'
              step below for creating custom bit rate.

                  * **Note:** Bit rates may vary from use-case to use-case based
                    on MCAN configuration on the J721E side.
            * Click on **OK** button.

            .. Image:: ../../../images/CanEth_PCANViewDeviceSelection.png
               :height: 500px
               :width: 500px
               :scale: 70 %
               :alt: PCAN View - Device Selection
               :align: center

        * Create and send message at period of 2 seconds

            * Click on **New Message** under **Transmit** menu
            * Enable the **CAN FD** checkbox
            * Enable the **Bit Rate Switch** checkbox
            * Set the following parameters in the **New Transmit Message** window:

                * **ID** as hex **004** for MCAN6 and **005** for MCAN9
                * **Length** as **64**
                * **Cycle Time** as **2000**
                * **Data** can be selected randomly

            .. Image:: ../../../images/CanEth_PCANViewTransmitMessageConfig.png
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
          Bit rates**. This will open a pop-up window
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
    .. Image:: ../../../images/CanEth_PCANViewBitRateConfig.png
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

For more details about installation of CCS and J721E target creation, refer to
"Ethernet Firmware_CCS setup.pdf" user guide at installer folder.

#. Connect a micro USB cable to JTAG port of J721E_EVM. The XDS110 JTAG
   connector is labeled ``XDS110`` (J3).
#. Connect a micro USB cable to MAIN Domain UART port on J721E_EVM. It's
   labeled ``UART`` (J44).
#. Set EVM's DIP switches ``SW8`` and ``SW9`` for no-boot mode:

    * SW8 = 10001000
    * SW9 = 01110000

#. Power on the J721E EVM board. Ensure that SD card is not present or QSPI
   flashed.
#. Open up a serial terminal for UART2 communication.

    * Set serial parameters to: 115200 8N1.
    * Set hardware and software flow control to "No".
    * Below figure shows serial parameters set in Minicom.

   .. Image:: ../../../images/CanEth_Minicom.png
      :scale: 100 %
      :alt: Serial Port Settings in Minicom
      :align: center

#. Open CCS and launch target config file for J721E_EVM.
#. Connect to **MAIN_Cortex_R5_0_0**.
#. Load the System firmware using launch script provided with this package.
#. Load and launch the demo executable: ::

    <SDK_INSTALL_PATH>/binary/gatewayapp/bin/j721e_evm/gatewayapp_mcu2_0_release.xer5f

#. The application logs will be displayed on the CCS and UART console. The UART
   console used depends on the core in which the application is run.
#. Confirm the network connectivity of PC with board. ::

    ping 192.168.1.203

SD Card Boot
''''''''''''

#. Create a bootable SD card with Linux bootloader, kernel and filesystem.
   For details about SD card creation, refer to the Processor SDK Linux
   Automotive User's Guide.
#. Copy the CAN/Eth gateway demo application to the **firmware** directory of
   Linux filesystem in SD card: ::

    cp <SDK_INSTALL_PATH>/binary/gatewayapp/bin/j721e_evm/gatewayapp_mcu2_0_release.xer5f <MOUNT>/rootfs/lib/firmware/

#. Update the soft-link ``j7-main-r5f0_0-fw`` to point to the demo application
   copied to SD card in the previous step: ::

    cd <MOUNT>/rootfs/lib/firmware/
    ln -sf gatewayapp_mcu2_0_release.xer5f j7-main-r5f0_0-fw

#. Connect a micro USB cable to MAIN Domain UART port on J721E_EVM. It's
   labeled ``UART`` (J44).
#. Set EVM's DIP switches ``SW8`` and ``SW9`` for SD card boot:

    * SW8 = 10000010
    * SW9 = 00000000

#. Open up a serial terminal for UART0 communication. This terminal will show
   logs from Linux bootloader and kernel.

    * Set serial parameters to: 115200 8N1.

#. Open up a serial terminal for UART2 communication. This terminal will show
   logs from MCU2_0 core where the demo application runs.

    * Set serial parameters to: 115200 8N1.
    * Set hardware and software flow control to "No".
    * Below figure shows serial parameters set in Minicom.

   .. Image:: ../../../images/CanEth_Minicom.png
      :scale: 100 %
      :alt: Serial Port Settings in Minicom
      :align: center

#. Insert SD card into slot labeled ``MICRO SD`` and power-on the J721E
   EVM board.
#. Confirm the network connectivity of PC with board. ::

    ping 192.168.1.203

Eth to Eth
''''''''''

Eth-to-Eth is simple L2 level routing of packets via external ports of CPSW9G
switch in the J721E device.

To use this, connect any two devices to the two ports of switch and send
packets between them. Video streaming using Plex Media Server can be done.

.. rubric:: Plex Server Setup
   :name: plex-server-setup-mcan-demo

#. Install Plex Media Server. The Ubuntu/Windows installation executable and
   instructions can be found in their webpage: https://www.plex.tv/
#. Once setup, the media server will be started every time that the PC is
   powered on.
#. Add video samples to the **Library** as needed.

.. rubric:: Plex Client
   :name: plex-client-mcan-demo

Plex clients can access media content via web at http://192.168.1.202:32400/web.

The Plex client interface is shown in the following figure.

.. Image:: ../../../images/CanEth_PlexClient.png
   :height: 500px
   :width: 800px
   :scale: 100 %
   :alt: Plex Client Interface
   :align: center


CAN to CAN
''''''''''

CAN-to-CAN direction involves the following routes:

+-------------------------+-------------+-------------+------------+
|          Route          |    Source   | Destination | Message ID |
+=========================+=============+=============+============+
|  PCAN1 -> MCAN6 ->      |    PCAN1    |    MCAN6    |     004    |
|  **Gateway Router** ->  +-------------+-------------+------------+
|  MCAN9 -> PCAN2         |    MCAN9    |    PCAN2    |     009    |
+-------------------------+-------------+-------------+------------+
|  PCAN2 -> MCAN9 ->      |    PCAN2    |    MCAN9    |     005    |
|  **Gateway Router** ->  +-------------+-------------+------------+
|  MCAN6 -> PCAN1         |    MCAN6    |    PCAN1    |     006    |
+-------------------------+-------------+-------------+------------+

Follow the next steps to test CAN-to-CAN routes:

#. Connect PCAN tools to MCAN6 and MCAN9 as per connection diagram.
#. Choose option **1** in the UART menu to enable CAN-to-CAN routing.

    .. Image:: ../../../images/CanEth_UartMenu.png
      :height: 500px
      :width: 800px
      :scale: 65 %
      :alt: Switch options menu
      :align: center

#. Send messages from each PCAN to other PCAN tool with message id's of MCAN6
   and MCAN9, respectively.

    * **ID** as hex **004** for MCAN6 and **005** for MCAN9
    * **Length** as **64**
    * **Cycle Time** as **2000**
    * **Data** can be any user specified data

#. Verify that packet content has been received on the receiver PCAN tool1
   connected to MCAN6 with ID **006**.
#. Verify that packet content has been received on receiver PCAN tool2 connected
   to MCAN9 with ID **009**.

.. note::

   For CAN-to-CAN routing, the application changes message id from MCAN6 to
   **009** and sends the message back. Similarly for MCAN9, application changes
   message id to **006**.

The diagram below shows CAN-to-CAN routing where messages from one PCAN GUI are
received on the another PCAN tool. The diagram also shows the transmit message
contents along with CAN message id's **004** and **005**.

.. Image:: ../../../images/CanEth_PCANViewCanCan.png
  :height: 500px
  :width: 800px
  :scale: 120 %
  :alt: PCAN View - CAN-to-CAN messages
  :align: center


CAN to Eth
''''''''''

CAN-to-Eth direction involves the following routes:

+-------------------------+-------------+-------------+------------+
|          Route          |    Source   | Destination | Message ID |
+=========================+=============+=============+============+
|  PCAN1 -> MCAN6 ->      |    PCAN1    |    MCAN6    |     004    |
|  **Gateway Router** ->  +-------------+-------------+------------+
|  Eth -> eth_rx          |    Eth      |    eth_rx   |     009    |
+-------------------------+-------------+-------------+------------+
|  PCAN2 -> MCAN9 ->      |    PCAN2    |    MCAN9    |     005    |
|  **Gateway Router** ->  +-------------+-------------+------------+
|  Eth -> eth_rx          |    Eth      |    eth_rx   |     006    |
+-------------------------+-------------+-------------+------------+

Follow the next steps to test CAN-to-Eth routes:

#. Connect the CAN PC tool from which you want to send message. For multi CAN
   connect PCAN tools to MCAN6 and MCAN9.
#. On UART console menu, select option **3** to reset the network connection.

    .. Image:: ../../../images/CanEth_UartMenu.png
      :height: 500px
      :width: 800px
      :scale: 65 %
      :alt: Switch options menu
      :align: center

#. Start the Ethernet receive application. The port number to be used must match
   the one set in the demo application. ::

    ./eth_rx.out --ip <ip_address> [--port <portNum>]
      ip_address    IPv4 address
      portNum       Port number. Optional argument
                    Default value is 2000 for receive

#. Start CAN message transmission from the CAN tool with below information.

    * **ID** as hex **004** for MCAN6 and **005** for MCAN9
    * **Length** as **64**
    * **Cycle Time** as **2000**
    * **Data** can be any user specified data

    .. Image:: ../../../images/CanEth_PCANViewNewTransmitMessage.png
      :height: 500px
      :width: 800px
      :scale: 50 %
      :alt: PCAN View - New Transmit Message
      :align: center

#. Verify that packet content has been received on respective PC console of
   eth_rx tool. The message with first 8 bytes as **44** are sent by MCAN6 and
   **55** are sent by MCAN9.

Below is a sample output of the ``eth_rx`` PC tool with received MCAN messages
printed out. ::


    $ cd pctools
    $ ./eth_rx.out --ip 192.168.1.203

    #
    # Gateway: Ethernet Receive Application Rev1.0
    #
    Connecting to Gateway server for Reception of CAN data
    Connected!
    CAN message data (0):
    55  55  55  55  55  55  55  55
    df  64  56  66  66  66  66  66
    66  66  66  66  66  66  66  66
    66  66  66  66  66  66  66  66
    66  66  66  66  66  66  66  66
    66  66  66  66  66  66  66  66
    66  66  55  44  44  45  55  55
    55  55  55  55  55  55  55  55


Eth to CAN
''''''''''

Eth-to-CAN direction involves the following routes:

+-------------------------+-------------+-------------+------------+
|         Route           |    Source   | Destination | Message ID |
+=========================+=============+=============+============+
|  eth_tx -> Eth ->       |    eth_tx   |    Eth      |     006    |
|  **Gateway Router** ->  +-------------+-------------+------------+
|  MCAN6 -> PCAN1         |    MCAN6    |    PCAN1    |     006    |
+-------------------------+-------------+-------------+------------+
|  eth_tx -> Eth ->       |    eth_tx   |    Eth      |     009    |
|  **Gateway Router** ->  +-------------+-------------+------------+
|  MCAN9 -> PCAN2         |    MCAN9    |    PCAN2    |     009    |
+-------------------------+-------------+-------------+------------+

Follow the next steps to test Eth-to-CAN routes:

#. Connect the CAN PC tool from which you want to send message. For multi CAN
   connect PCAN tools to MCAN6 and MCAN9.
#. On UART console menu, select option **3** to reset the network connection.

    .. Image:: ../../../images/CanEth_UartMenu.png
      :height: 500px
      :width: 800px
      :scale: 65 %
      :alt: Switch options menu
      :align: center

#. Start the Ethernet transmit application. The port number must match the one
   set in the demo application. ::

    ./eth_tx.out --ip <ip_address> [--port <portNum>] [--framerate <framerate>]
      ip_address    IPv4 address
      portNum       Port number. Optional argument
                    Default value is 1000 for transmit
      framerate     Ethernet packets per second. Optional argument
                    Default frame rate is 100 packets/second

#. Verify that the frame rate set in the Ethernet transmit application matches
   the rate of received packets on the PCAN tool.
#. Verify that packet content has been received on the respective PCAN tool. The
   message id **006** will come on MCAN6 PCAN and message id **009** will come
   on MCAN9 PCAN.

Below is a sample output of the ``eth_tx`` PC tool with transmitted MCAN
messages printed out. ::

    $ cd pctools
    $ ./eth_tx.out --ip 192.168.1.203 --framerate 100

    #
    # Gateway: Ethernet Transmit Application Rev1.0
    #
    Setting framerate to 10 per seconds
    Connecting to Gateway server for transmission
    Connected!
    Starting transmit...
    Eth message data (0) to CAN 9:
    9   a5  a5  a5  a5  a5  a5  a5
    a5  a5  a5  a5  a5  a5  a5  a5
    a5  a5  a5  a5  a5  a5  a5  a5
    a5  a5  a5  a5  a5  a5  a5  a5
    a5  a5   0  c9  9f  33  63  2e
    5a  76  8d  e7  e8  1b  f8  54
    c2  7c  46  e3  fb  f2  ab  ba
    cd  29  ec  4a  ff  51  73  69

    Eth message data (1) to CAN 6:
    6   a5  a5  a5  a5  a5  a5  a5
    a5  a5  a5  a5  a5  a5  a5  a5
    a5  a5  a5  a5  a5  a5  a5  a5
    a5  a5  a5  a5  a5  a5  a5  a5
    a5  a5   0  3d  21  41  74  82
    e   11  54  b4  9b  c6  cd  b2
    ab  d4  5e  e9  58  17   5  5d
    25  5a  a3  58  31  b7   d  32


Sample UART logs
----------------

Below is a UART terminal output after one simulation: ::

    Board_init success
    Host MAC address: 04:01:02:03:04:05
    CPSW_9G Test on MAIN NAVSS
    PHY 0 is alive
    PHY 3 is alive
    PHY 12 is alive
    PHY 15 is alive
    PHY 23 is alive
    Cpsw_periodicTick() port 1's PHY is up

    GatewayApp: BOARD IP address I/F 1: 192.168.1.203

    GatewayApp: Starting GATEWAY Tasks...
    Gateway Tx: Server listening (port=1000) !!!

    GatewayApp: Network Tx socket open done..
    Gateway Tx: Server listening (port=2000) !!!

    GatewayApp: Network Rx socket open done..
    ==================================
    GatewayApp: MCANSS Config for MCAN6
    GatewayApp: CrossBar/Interrupt Configuration done.
    GatewayApp: MCANSS Revision ID:
    GatewayApp: scheme:0x1
    GatewayApp: Business Unit:0x2
    GatewayApp: Module ID:0x8e0
    GatewayApp: RTL Revision:0x9
    GatewayApp: Major Revision:0x1
    GatewayApp: Custom Revision:0x0
    GatewayApp: Minor Revision:0x1
    GatewayApp: CAN-FD operation is enabled through E-Fuse.
    GatewayApp: Endianess Value: 0x87654321
    ==================================
    GatewayApp: MCANSS Config for MCAN9
    GatewayApp: CrossBar/Interrupt Configuration done.
    GatewayApp: MCANSS Revision ID:
    GatewayApp: scheme:0x1
    GatewayApp: Business Unit:0x2
    GatewayApp: Module ID:0x8e0
    GatewayApp: RTL Revision:0x9
    GatewayApp: Major Revision:0x1
    GatewayApp: Custom Revision:0x0
    GatewayApp: Minor Revision:0x1
    GatewayApp: CAN-FD operation is enabled through E-Fuse.
    GatewayApp: Endianess Value: 0x87654321

    GatewayApp: MCAN Transmitter app started..

    =================================================
                       Switch Options
    =================================================
     1. Enable CAN - CAN routing
     2. Enable CAN - Eth Routing
     3. Reset Network connections - Use this if PC tools doesn't connect
     Enter your choice:

.. _known-issues-limitations:

Known issues & limitations
^^^^^^^^^^^^^^^^^^^^^^^^^^

#. Polling mode is not supported in the Gateway application.
#. Re-transmission of failed CAN message is not supported.
#. Stability issues can be observed due to PDK-4356 [CPSW] NIMU example Rx fails
   during stress test. The Eth TX app may fail when sending heavy BW traffic.
   Workaround is to keep frame rate low.
