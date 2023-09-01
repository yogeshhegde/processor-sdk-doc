.. include:: /_replacevars.rst

.. _WiFi-OOB-Demo-User-Guide-label:

WiFi Out Of Box Demo - User Guide
===================================

Overview
--------

The |__PART_FAMILY_NAME__| SK board has a WiLink Module (WL1837MODGIMOCT) from TI connected to the MMC0 port of the SoC.
Using this, a WiFi Out of Box Demo has been set up such that the board acts as both a WiFi Access
Point( AP) and a WiFi Station that can connect to an external access point like a router or hotspot, on boot
up. The board also starts iperf3 automatically on the access point interface and the user can run iperf3 on
their devices to test the throughput.

All of the necessary equipment requirement and instructions are provided here.

Hardware Prerequisites
----------------------

-  TI |__PART_FAMILY_NAME__| SK

-  PC (Windows or Linux, to use serial terminal console)

-  PC (Windows or Linux, to connect to the SK board's WiFi AP)

-  SD card (minimum 16GB)

.. _Connect-to-WiFi-AP:

Connect to the board's WiFi Access Point
-----------------------------------------

Follow the steps below to connect to the WiFi Access Point of the SK board:

1. Power on the board. The SK will start the WiFi Access Point(AP) automatically on system boot.

2. Scan for WiFi network from your phone or PC. Each board has a specific AP SSID. For |__PART_FAMILY_NAME__| SK
   it will be "\ |__PART_FAMILY_NAME__|\ SK-AP_xxxxxx".

3. Connect to this network using the password "tiwilink8".

.. ifconfig:: CONFIG_part_variant in ('AM64X')

    .. Image:: /images/am64sk-ap.jpg
       :width: 407
       :height: 400

.. ifconfig:: CONFIG_part_variant in ('AM62X')

    .. Image:: /images/am62sk-ap.png
       :width: 407
       :height: 400

4. Once connected, you can access the Matrix GUI from http://192.168.43.1

.. ifconfig:: CONFIG_part_variant in ('AM64X')

    5. Also, the benchmark demo can be accessed from http://192.168.43.1:8081


Using the board as WiFi Station to connect to external WiFi AP
--------------------------------------------------------------

Users can configure the board to connect to AP of their choice (like a home router or a hotspot) using the
following steps:

1. Modify the wificfg file on the boot partition of the SD card. You can use a card reader to mount the boot
   partition on Windows or Linux PC.

   The default contents of the file are shown below:

   ::

     # This file is used for configuring the credentials required when the
     # board is acting as a WiFi station.
     # Customize this as per your need
     # Set the demo_enable to yes so that the board connects to the AP automatically
     # after the boot

     [Wifi-STA]
     demo_enable = no
     ssid = homewifi
     password = password123

   Set demo_enable to yes. Enter the Wi-Fi credentials (Network name and Password) of the AP you want to connect to.
   Do not change the file formatting. In case of AP with no password, leave the password line blank. For example if you
   want to connect to a hotspot named **MyHomeWifi** with **Password123** password, the content should be as shown below:

   ::

     # This file is used for configuring the credentials required when the
     # board is acting as a WiFi station.
     # Customize this as per your need
     # Set the demo_enable to yes so that the board connects to the AP automatically
     # after the boot

     [Wifi-STA]
     demo_enable = yes
     ssid = MyHomeWifi
     password = Password123

2. Save the file, safely eject micro SD card, plug it into the SK board and reboot.

3. The SK will read the config file and connect to the external AP automatically on system boot.

4. The user can confirm that the SK is connected to the configured AP by running commands on the board such as:

   ::

    iw wlan0 link

   You will see the connection details displayed like this:

.. figure:: /images/wifi-oob-iw-command.png

Measuring Througput using iperf3
--------------------------------

The SK board starts iperf3 automatically on AP interface (IP address 192.168.43.1) on port 6001. Users can run iperf3
on their PC by following the below steps:

1. Connect a PC to the wifi network of the SK board. Refer :ref:`Connect-to-WiFi-AP` for steps to connect to the AP.

2. Run iperf3 on the PC connected to the AP. For example, the below command tests UDP @ 20Mbps for 30 secs:

   ::

         iperf3 -c 192.168.43.1 -u -b 20M -t 30 -i 5 -p 6001
