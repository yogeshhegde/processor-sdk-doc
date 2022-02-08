.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_CCLINK

Introduction
-------------

CC-Link is an open-architecture network that was originally developed
by the Mitsubishi Electric Corporation.It have been widely used in
Process control, building automation etc. CLPA (CC-Link Partner
Association) maintains the network technology and support many
manufacturer supporting the application. CC-Link is available in
multiple flavours i.e. CC-Link, CC-Link LT, CC-Link Safety, CC-Link IE
(Industrial Ethernet) - Control and CC-Link IE Field. For further
details regarding CCLink and its flavours please refer the CLPA
website.\ `[1] <http://am.cc-link.org/en/index.html>`__

Protocol Overview
------------------

The implementation will demonstrate how to create, run and test CC-Link
IE Field Network Basic examples on TI platforms. The following shows the
CC-Link IE Field Network Basic Overview:

-  1 Gbit/s Ethernet based network
-  Ethernet physical layer (Cat5e cable & RJ45 connectors)
-  254 stations per network
-  100 meters between stations
-  Completely deterministic without using switches
| 
Code Organization
------------------

The Directory structure for CC-Link IE Field Network Basic source code
and examples for both NIMU and NIMU_ICSS is shown in the following
table.

+---------------------------------------------------------------------------------------------------------------------------+
|                                            **CCLink for CPSW i.e. NIMU**                                                  |
+-----------------------------------+---------------------------------------------------------------------------------------+
+**Controller Station Source code** | $(TI_PDK_INSTALL_DIR)/packages/ti/transport/ndk/nimu/example/CCLink/cclink_controller |
+-----------------------------------+---------------------------------------------------------------------------------------+
+**SLave Station Source code**      |$(TI_PDK_INSTALL_DIR)/packages/ti/transport/ndk/nimu/example/CCLink/cclink_device      |
+-----------------------------------+---------------------------------------------------------------------------------------+
+**Test Examples script**           |$(TI_PDK_INSTALL_DIR)/packages/ti/transport/ndk/nimu/example/CCLink/<SOC>              |
+-----------------------------------+---------------------------------------------------------------------------------------+
+**Test Examples main code**        |$(TI_PDK_INSTALL_DIR)/packages/ti/transport/ndk/nimu/example/CCLink/src                |
+-----------------------------------+---------------------------------------------------------------------------------------+


+--------------------------------------------------------------------------------------------------------------------------------+
|                                            **CCLink for ICSS i.e. NIMU_ICSS**                                                  |
+-----------------------------------+--------------------------------------------------------------------------------------------+
+**Controller Station Source code** | $(TI_PDK_INSTALL_DIR)/packages/ti/transport/ndk/nimu_icss/example/CCLink/cclink_controller |
+-----------------------------------+--------------------------------------------------------------------------------------------+
+**Device Station Source code**     |$(TI_PDK_INSTALL_DIR)/packages/ti/transport/ndk/nimu_icss/example/CCLink/cclink_device      |
+-----------------------------------+--------------------------------------------------------------------------------------------+
+**Test Examples script**           |$(TI_PDK_INSTALL_DIR)/packages/ti/transport/ndk/nimu_icss/example/CCLink/<SOC>              |
+-----------------------------------+--------------------------------------------------------------------------------------------+
+**Test Examples main code**        |$(TI_PDK_INSTALL_DIR)/packages/ti/transport/ndk/nimu_icss/example/CCLink/src                |
+-----------------------------------+--------------------------------------------------------------------------------------------+

| 

Building the Examples
----------------------

Use pdkProjectCreate.sh for Linux environment or pdkProjectCreate.bat
for Windows.
This can be found under the <PDK>/packages folder. The only
modification to these scripts, if any, is to update the
CCS_INSTALL_PATH variable to point to CCS location if its not in the
c:\ti\ccsv6 directory . Please refer to `Rebuilding
PDK <index_how_to_guides.html#rebuild-drivers-from-pdk-directory>`__ for details of example project
creation and how to run the example projects using CCS.

CC-Link IE Field Network Basic Example Description
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

For each EVM Type supported, there is a cclink example which demonstates
cyclic data communication between controller and device station. Once the
application is loaded via CCS and run, you will be able to see controller
sending cyclic data packets and device receiving the packet. For example,
the config file for NIMU for CPSW for idkAM572x, can be found in
ti/transport/ndk/nimu/example/CCLink/am572x/armv7/bios/cclink_idkAM572x.cfg.
The default IP address for controller is 192.168.3.100 and for device it is
192.168.3.4. If you wish to re-configure the IP address of the CPSW
interface you will need to modify the following configuration
parameters. make sure controller and device are in same network.

-  Ip.address = "new ip address"
-  Ip.mask = "new ip mask"
-  Ip.gatewayIpAddr = "new gatewayIpAddr"

If you do change these settings, you will be required to re-build the
Example Project using CCS.

+-----------------------+-----------------------+-----------------------+
| Name                  | Description           | EVM Configuration     |
+=======================+=======================+=======================+
| NIMU_CCLinkController | | Example             | | icev2AM335x:        |
| _<evm/idk>XXXX_<arm/  |   demonstrates CCLink |   Jumpers J18 and J19 |
| c66x/m4>Exampleprojec |   controller station  |   need to be set      |
| t.txt                 |   sending cyclic      |   properly to select  |
|                       |   packet to device.   |   CPSW or ICSS mode.  |
|                       |                       |                       |
|                       |                       | | Pin2 and Pin3 need  |
|                       |                       |   to be connected for |
|                       |                       |   ICSS mode and Pin1  |
|                       |                       |   and Pin2 for CPSW   |
|                       |                       |   mode.               |
|                       |                       |                       |
|                       |                       | Update \*.cfg file    |
|                       |                       | with static IP to     |
|                       |                       | test. NIMU for CPSW   |
|                       |                       | test Tests requires   |
|                       |                       | connection of         |
|                       |                       | configured Ethernet   |
|                       |                       | port under test to    |
|                       |                       | external PC on same   |
|                       |                       | subnet.               |
+-----------------------+-----------------------+-----------------------+
| NIMU_CCLinkDevice_<ev | | Example             | | icev2AM335x:        |
| m/idk>XXXX_<arm/c66x/ |   demonstrates CCLink |   Jumpers J18 and J19 |
| m4>Exampleproject.txt |   device station      |   need to be set      |
|                       |   receiving cyclic    |   properly to select  |
|                       |   packet from         |   CPSW or ICSS mode.  |
|                       |   controller and      |                       |
|                       |   sending a response  | | Pin2 and Pin3 need  |
|                       |   back.               |   to be connected for |
|                       |                       |   ICSS mode and Pin1  |
|                       |                       |   and Pin2 for CPSW   |
|                       |                       |   mode.               |
|                       |                       |                       |
|                       |                       | Update \*.cfg file    |
|                       |                       | with static IP to     |
|                       |                       | test. NIMU for CPSW   |
|                       |                       | test Tests requires   |
|                       |                       | connection of         |
|                       |                       | configured PRU-ICSS   |
|                       |                       | Ethernet port under   |
|                       |                       | test to external PC   |
|                       |                       | on same subnet.       |
+-----------------------+-----------------------+-----------------------+
| NIMU_ICSS_CCLinkMaste | | Example             | | icev2AM335x:        |
| r_<evm/idk>XXXX_<arm/ |   demonstrates CCLink |   Jumpers J18 and J19 |
| c66x/m4>Exampleprojec |   controller station  |   need to be set      |
| t.txt                 |   sending cyclic      |   properly to select  |
|                       |   packet to device.   |   CPSW or ICSS mode.  |
|                       |                       |                       |
|                       |                       | | Pin2 and Pin3 need  |
|                       |                       |   to be connected for |
|                       |                       |   ICSS mode and Pin1  |
|                       |                       |   and Pin2 for CPSW   |
|                       |                       |   mode.               |
|                       |                       |                       |
|                       |                       | Update \*.cfg file    |
|                       |                       | with static IP to     |
|                       |                       | test. NIMU for CPSW   |
|                       |                       | test Tests requires   |
|                       |                       | connection of         |
|                       |                       | configured Ethernet   |
|                       |                       | port under test to    |
|                       |                       | external PC on same   |
|                       |                       | subnet.               |
+-----------------------+-----------------------+-----------------------+
| NIMU_ICSS_CCLinkDevic | | Example             | | icev2AM335x:        |
| e_<evm/idk>XXXX_<arm/ |   demonstrates CCLink |   Jumpers J18 and J19 |
| c66x/m4>Exampleprojec |   device station      |   need to be set      |
| t.txt                 |   receiving cyclic    |   properly to select  |
|                       |   packet from         |   CPSW or ICSS mode.  |
|                       |   controller and      |                       |
|                       |   sending a response  | | Pin2 and Pin3 need  |
|                       |   back.               |   to be connected for |
|                       |                       |   ICSS mode and Pin1  |
|                       |                       |   and Pin2 for CPSW   |
|                       |                       |   mode.               |
|                       |                       |                       |
|                       |                       | Update \*.cfg file    |
|                       |                       | with static IP to     |
|                       |                       | test. NIMU for CPSW   |
|                       |                       | test Tests requires   |
|                       |                       | connection of         |
|                       |                       | configured PRU-ICSS   |
|                       |                       | Ethernet port under   |
|                       |                       | test to external PC   |
|                       |                       | on same subnet.       |
+-----------------------+-----------------------+-----------------------+

| 

Running CC-Link IE Field Network Basic example
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The following is the test setup needed to run the example for CCLink
demonstration on TI platform. Connect the tested eth port of the evm to
a switch for controller station. Do the same connection for device station to
same switch.

.. Image:: /images/Cclink_setup_pic.PNG

| 
| Once the connection is done, load controller and device station code on
  both evm and run them simultaneously. You would see following output
  on uart port of controller station.

.. Image:: /images/Cclink_controller_screeshot_linux.png

You would see following output on uart port of device station.

.. Image:: /images/Cclink_device_screenshot_linux.png

| 

.. raw:: html
