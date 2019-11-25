.. http://processors.wiki.ti.com/index.php/PRU-ICSS_Ethernet
.. rubric:: Introduction
   :name: introduction-pru-icss-ethernet-linux

As of version 3.1.0.6 of the Linux Processor SDK, the evaluation modules
listed below support additional 100 Mbps Ethernet ports through the
PRU-ICSS while running Linux as your host operating system.

This page **DOES NOT** cover any of the industrial protocols that are
supported by the PRU-ICSS while running other host operating systems
(bare metal, StarterWare, TI RTOS, third party, etc).

For previous versions of the Linux Processor SDK, please see the
Archives section at the bottom of this page.

.. rubric:: Boards Supported
   :name: boards-supported

.. Image:: ../images/Am335x_ice.jpg

.. rubric:: `AM3359 Industrial Communications Engine
   (ICE) <http://www.ti.com/tool/tmdsice3359>`__
   :name: am3359-industrial-communications-engine-ice

The AM3359 Industrial Communications Engine (ICE) is a development
platform targeted for systems that specifically focus on the industrial
communications capabilities of the Sitara AM335x ARM® Cortex™-A8
Processors

The AM335x ARM Cortex-A8 Processors integrate the Programmable Real-time
Unit (PRU) that has been architected to implement the real-time
communication technologies used in a broad range of industrial
automation equipment. It enables low foot print designs with minimal
external components and with best in class low power performance.

.. Image:: ../images/Am437x_idk_500x300.jpg

.. rubric:: `AM437x Industrial Development Kit
   (IDK) <http://www.ti.com/tool/tmdsidk437x>`__
   :name: am437x-industrial-development-kit-idk

The AM437x Industrial Development Kit (IDK) is an application
development platform for evaluating the industrial communication and
control capabilities of Sitara™ AM4379 and AM4377 processors for
industrial applications.

The AM4379 and AM4377 processors are ideal for industrial
communications, industrial control, and industrial drives applications.
The AM437x processors integrate a quad-core Programmable Real-time Unit
(PRU) that has been architected to implement the real-time communication
technologies used in a broad range of industrial automation equipment.
It enables low foot print designs with minimal external components and
with best in class low power performance.

.. Image:: ../images/Am571x_idk.JPG

.. rubric:: `AM571x Industrial Development Kit
   (IDK) <http://www.ti.com/tool/TMDXIDK5718>`__
   :name: am571x-industrial-development-kit-idk

The AM571x IDK is a standalone test, development, and evaluation module
that enables developers to write software and develop hardware for
industrial control and industrial communications applications. It has
been equipped with a TI AM5718 processor and a defined set of features
to allow you to experience industrial communication solutions using
various serial or Ethernet based interfaces. Using standard interfaces,
the AM571x IDK may interface to other processors or systems and act as a
communication gateway or controller. In addition, it can directly
operate as a standard remote I/O system or a sensor connected to an
industrial communication network.

.. note::
    Due to pin muxing between the optional LCD and the PRUSS1 Ethernet
    ports, the AM571x IDK supports two configurations. The first
    configuration is 4-port Ethernet + LCD. In this configuration, two
    Ethernet ports are provided by the CPSW, two Ethernet ports are provided
    by PRUSS2, and the LCD is enabled. To use this configuration, place a
    jumper across **J51** on the board. The second configuration is 6-port
    Ethernet. In this configuration, two Ethernet ports are provided by the
    CPSW, two Ethernet ports are provided by PRUSS1, two Ethernet ports are
    provided by PRUSS2, and the LCD is disabled. To use this configuration,
    leave **J51** open.

| 

.. Image:: ../images/Am572x_idk.PNG

.. rubric:: `AM572x Industrial Development Kit
   (IDK) <http://www.ti.com/tool/TMDXIDK5728>`__
   :name: am572x-industrial-development-kit-idk

The AM572x Industrial Development Kit (IDK) is a development platform
for evaluating the industrial communication and control capabilities of
Sitara AM572x processors for applications in factory automation, drives,
robotics, grid infrastructure, and more. AM572x processors include dual
PRU-ICSS (Programmable Real-time Unit for Industrial Communications)
sub-systems which can be used for industrial Ethernet protocols such as
Profinet, EtherCAT, Ethernet/IP, and others. The TMDXIDK5728 breaks out
six ports of Ethernet, four of which can be used concurrently: 2x Gb
Ethernet ports and 2x 10/100 Ethernet ports from the PRU-ICSS
subsystems.

.. note::
    Due to changes in the PRU-ICSS between silicon revisions, the PRU
    Ethernet firmwares provided for the AM5728 device are only meant to be
    used on silicon revision SR 2.0.

| 

.. Image:: ../images/K2g_ice.PNG

.. rubric:: `K2G Industrial Communication Engine
   (ICE) <http://www.ti.com/tool/k2gice>`__
   :name: k2g-industrial-communication-engine-ice

The K2G Industrial Communications Engine (ICE) enables 66AK2Gx processor
developers to immediately start development, demonstration and test of
industrial communication protocols for products such as PLC, bus
controllers, motion control and other real-time industrial networked
applications. The evaluation module is supported by Processor SDK for RT
Linux and TI-RTOS operating systems and is supplied with an SD micro
card for easy boot up and out of box experience. The two PRU-ICSS
subystems can be used for industrial Ethernet protocols such as
Profinet, EtherCAT, Ethernet/IP, and others.

| 

| 

.. rubric:: What You Get
   :name: what-you-get

With the PRU-ICSS Ethernet support, you get two (or four, on the AM571x
IDK and K2G ICE) additional 100 Mbps Ethernet interfaces that show up
just like any other Ethernet interface in Linux. These interfaces are
there 'out-of-the-box' in the latest Linux Processor SDK when ran on any
of the boards shown above. All you need to do is plug in an Ethernet
cable and bring the interface up from the console (discussed below).

The current implementation does **not** support Ethernet switching
within the PRU-ICSS. The provided PRU firmwares only support 'dual emac'
mode in this release of the Linux Processor SDK.

| 

| 

.. rubric:: How It Works
   :name: how-it-works

Texas Instruments provides all of the necessary software and firmware in
the Linux Processor SDK to enable the PRU-ICSS Ethernet ports. The PRU
firmware binaries can be found in the **/lib/firmware/ti-pruss/** folder
in the filesystem. A Linux kernel networking driver is provided that can
be found at
**<%LINUX\_PROC\_SDK\_X\_X\_X\_X%>/board-support/linux-x.y.z..../drivers/net/ethernet/ti/prueth.c**.
The required device tree modifications are also given in the dts files
of the supported boards from above.

As the boards boot, the prussN\_eth device tree node causes the
ti-prueth driver to be probed. This probe function does several things
to prepare the PRU-ICSS Ethernet ports:

-  Configures the mux mode of the PRU pins for MII mode
-  Requests ownership of the PRUSS memory regions from the pruss driver
-  Allocates a pool of memory in OCMC SRAM for the Ethernet buffers to
   be passed from the PRU to Linux
-  Initializes a netdev devices
-  Registers the network device with Linux

At this point the Linux driver is ready for the new Ethernet interface
to be started. Once the user issues the interface up command ('ifup
eth2' for example), the **emac\_ndo\_open** function is called in the
ti-prueth driver which uses the remoteproc interface to boot the PRU
cores with the firmware provided in the **/lib/firmware/ti-pruss/**
folder of the EVM filesystem. The PRUs running this firmware, coupled
with the ti-prueth Linux driver, allows up to 2 (or 4, on the AM571x
IDK) additional 100 Mbps Ethernet interfaces to be exposed to the user.

| 

.. rubric:: Block Diagram
   :name: block-diagram

| This is a high level block diagram to show how everything fits
  together. For more information see the schematics for the boards as
  well as the Linux driver source code.

.. Image:: ../images/Pru_eth_block_diagram_3_0_0_4.PNG

| 

.. rubric:: Try It Out
   :name: try-it-out

Here are the steps needed to test out the new Ethernet interfaces:

-  Get your hands on one of the industrial boards

   -  `AM3359 Industrial Communications Engine
      (ICE) <http://www.ti.com/tool/tmdsice3359>`__
   -  `AM437x Industrial Development Kit
      (IDK) <http://www.ti.com/tool/tmdsidk437x>`__
   -  `AM571x Industrial Development Kit
      (IDK) <http://www.ti.com/tool/TMDXIDK5718>`__
   -  `AM572x Industrial Development Kit
      (IDK) <http://www.ti.com/tool/TMDXIDK5728>`__
   -  `K2G Industrial Communication Engine
      (ICE) <http://www.ti.com/tool/k2gice>`__

-  Download the Linux Processor SDK (v3.1.0.6 or higher)

   -  `Linux Processor SDK for AM335x
      devices <http://www.ti.com/tool/PROCESSOR-SDK-AM335x>`__
   -  `Linux Processor SDK for AM437x
      devices <http://www.ti.com/tool/PROCESSOR-SDK-AM437X>`__
   -  `Linux Processor SDK for AM57x
      devices <http://www.ti.com/tool/PROCESSOR-SDK-AM57X>`__
   -  `Linux Processor SDK for K2G
      devices <http://www.ti.com/tool/PROCESSOR-SDK-K2G>`__

-  Run the 'create SD card' script provided in the SDK to create a
   bootable SD card

   -  Plug your SD card into your Ubuntu development machine with a USB
      card reader
   -  **cd <%LINUX\_PROC\_SDK\_X\_X\_X\_X%>/bin/**
   -  **sudo ./create-sdcard.sh**
   -  follow the script directions to format your SD card and then
      install the pre-built binaries from the SDK
   -  for more information on creating an SD card:
      `Processor\_SDK\_Linux\_create\_SD\_card\_script <Overview_Getting_Started_Guide.html#linux-sd-card-creation-guide>`__

-  Boot from the newly created SD card

   -  Put the SD card into your board, power it on, and wait for the
      login prompt then type **root** to log in.

      .. note::
          You'll need to clear the SPI flash on the AM3359 ICE board before
          you can boot from an SD card: `AM3359 ICE clear SPI
          flash <How_to_Guides/Host/AM335x_ICEv2_flash_erase.html#am335x-icev2-flash-erase>`__

-  Plug an Ethernet cable into the ports supported by the PRU-ICSS

   -  On the AM3359 ICE there are only two Ethernet ports on the board

      -  In order to use the PRU-ICSS with these ports (instead of the
         CPSW) you need to correctly configure both of the jumpers that
         are located right next to the RJ45 jacks

         -  Jumpers J18 and J19 both need to be set to MII to use
            PRU-ICSS on the ports, you need to reboot the device for
            jumper changes to take effect
         -  If you set both of these jumpers to RMII then the CPSW will
            drive the ports, not the PRU-ICSS
         -  It is not supported to set the two jumpers to different
            values. Both need to be MII (PRU-ICSS) or both need to be
            RMII (CPSW).

   -  On the AM437x IDK the silkscreen says **PRUETH0** and **PRUETH1**
      for the supported PRU ports
   -  On the AM571x IDK the silkscreen says **PRU1 ETH0**, **PRU1
      ETH1**, **PRU2 ETH0**, and **PRU2 ETH1** for the supported PRU
      ports

      .. note::
          On the AM571x IDK board, the pins used for PRU1 ETH0 and PRU1 ETH1
          are shared with pins used for the optional LCD touchscreen. U-Boot
          uses jumper **J51** to determine if the LCD touchscreen should be
          enabled or not. If **J51** is closed (jumper is present across the
          two pins), then U-Boot will load a device tree that enables the
          LCD touchscreen and disables PRUSS1 Ethernet ports. This means
          that only **PRU2 ETH0** and **PRU2 ETH1** will be supported if
          jumper **J51** is closed. If **J51** is open (jumper is not
          present across the two pins), then U-Boot will load a device tree
          that enables all four PRUSS Ethernet ports, two from PRUSS1 and
          two from PRUSS2. In this mode, the LCD touchscreen is disabled.

   -  On the AM572x IDK the silkscreen says **PRU2 ETH0** and **PRU2
      ETH1** for the supported PRU ports
   -  On the K2G ICE the supported PRU ports are the two stacked RJ45
      connectors

-  Bring up the PRU Ethernet interface in Linux

   -  Depending on your board and the contents of your
      **/etc/networking/interfaces** file, the PRU-ICSS Ethernet ports
      may already be brought up. If not:
   -  On the AM3359 ICE type **ifup eth0** to bring up **Ethernet\_0**
      and type **ifup eth1** to bring up **Ethernet\_1**
   -  On the AM437x IDK type **ifup eth1** to bring up **PRUETH0** and
      type **ifup eth2** to bring up **PRUETH1**
   -  On the AM571x IDK type **ifup eth2** to bring up **PRU1 ETH0**,
      type **ifup eth3** to bring up **PRU1 ETH1**, type **ifup eth4**
      to bring up **PRU2 ETH0**, and type **ifup eth5** to bring up
      **PRU2 ETH1**

      .. note::
          As mentioned in the note above, jumper **J51** on the board
          determines if two or four PRUSS Ethernet ports are supported. If
          **J51** is closed then only two of the four interfaces listed here
          will be available for use.

   -  On the AM572x IDK type **ifup eth2** to bring up **PRU2 ETH0** and
      type **ifup eth3** to bring up **PRU2 ETH1**
   -  On the K2G ICE type **ifup eth1**, **ifup eth2**, **ifup eth3**,
      and **ifup eth4** to bring up the PRU Ethernet interfaces

-  If all goes well you should see the PRU-ICSS ports in the output of
   the **ifconfig** command

| 

| 

.. rubric:: Network Topologies
   :name: network-topologies

The following network topologies are possible with the PRU-ICSS Ethernet
ports.

.. rubric:: Single Port Mode
   :name: single-port-mode

| In this mode only one of the PRU-ICSS Ethernet ports are used. This is
  the simplest mode and works as you would expect it to.

.. Image:: ../images/Pru_eth_block_single_port_3_0_0_4.PNG

--------------

.. rubric:: Dual MAC Mode (Gateway)
   :name: dual-mac-mode-gateway

One use case made possible with two ports on the same device is to allow
your device to act as a gateway between two different subnets. In this
use case you just need to bring up both ports and then plug them into
the two subnets as shown below.

.. note::
    It is not a normal use case to plug both PRU-ICSS Ethernet ports into
    the same switch (same subnet) out-of-the-box. While it may appear to
    work at first, it will lead to unexpected behavior including (but not
    limited to) packets entering/exiting the device on the opposite port
    that you would expect due to ARP broadcasts and other topics that are
    outside the scope of this wiki page. If you would like to use both ports
    on the same subnet, keep scrolling to the Bonding section below.

| 

.. Image:: ../images/Pru_eth_block_gateway_3_0_0_4.PNG

--------------

| 

.. rubric:: Dual MAC Mode (Bonding)
   :name: dual-mac-mode-bonding

Bonding, also called link aggregation or port trunking, is a networking
feature that uses multiple Ethernet ports to provide link redundancy or
an increase in throughput.

| The next section shows how to use the two PRU-ICSS Ethernet ports to
  provide link redundancy by using the 'active-backup' bonding mode. If
  one of the cables is unplugged the Ethernet traffic will fail over to
  the other port and continue. To learn more about the other types
  bonding available check out the `Linux bonding
  documentation <https://www.kernel.org/doc/Documentation/networking/bonding.txt>`__.

.. Image:: ../images/Pru_eth_block_bonding_3_0_0_4.PNG

To learn even more about bonding see the `Wikipedia Link
aggregation <https://en.wikipedia.org/wiki/Link_aggregation>`__ page.

--------------

| 

.. rubric:: Steps to enable 'active-backup' bonding mode
   :name: steps-to-enable-active-backup-bonding-mode

While testing the below steps, I plugged both PRU-ICSS Ethernet ports
into the same switch that has access to a DHCP server. During boot and
bonding setup I left the cables connected. I only started unplugging
cables when I was testing the bond0 interface for redundancy in the last
step.

On your Linux development machine

#. Enable **Bonding driver support** using menuconfig, rebuild Linux,
   and boot your board

   -  The menuconfig option can be found under **Device Drivers ->
      Network device support -> Bonding driver support'**
   -  You can either configure the driver as built-in to the kernel (\*)
      or as a module (M). Keep in mind that if you build the driver into
      the kernel that you will not be able to pass any parameters to it
      as it is loaded. For the example shown here, we will be using the
      sysfs interface to configure the bonding so it doesn't matter
      which method you choose (we used the module (M) method though).
   -  Once **Bonding driver support** is enabled, rebuild your Linux
      kernel and modules

      -  If you need help, see this page:
         `Linux\_Kernel\_Users\_Guide <Foundational_Components_Kernel_Users_Guide.html>`__

   -  Now boot your board with the new kernel and bonding driver built
      above

On your development board console

#. Insert the bonding module (unless you built it into the kernel above,
   then it's already there)

   -  **modprobe bonding**

#. Get the IP address and netmask of one of your PRU-ICSS Ethernet ports
   (we will need it in a second)

   -  If the ports are already up

      -  **ifconfig**

   -  If the ports are not up yet

      -  **ifup eth2** where 2 is the interface number for one of your
         PRU-ICSS Ethernet ports (this is board dependent)
      -  **ifconfig**

         .. note::
             AM3359ICE: **eth0** and **eth1** are the PRU-ICSS Ethernet ports

             AM437x IDK: **eth1** and **eth2** are the PRU-ICSS Ethernet ports

             AM572x IDK: **eth2** and **eth3** are the PRU-ICSS Ethernet ports

#. Take down your PRU-ICSS Ethernet ports (this is necesary for bonding)

   -  **ifconfig eth2 down**
   -  **ifconfig eth3 down**

#. Configure bonding to use mode 1: active-backup mode

   -  **echo 1 > /sys/class/net/bond0/bonding/mode**

#. Configure the MII link monitoring frequency in milliseconds

   -  **echo 100 > /sys/class/net/bond0/bonding/miimon**

#. Bring up the **bond0** interface using the IP address and netmask
   that you noted down from above

   -  **ifconfig bond0 192.168.0.100 netmask 255.255.254.0 up**

#. Bind your two PRU-ICSS Ethernet ports to the bond0 interface

   -  **echo +eth2 > /sys/class/net/bond0/bonding/slaves**
   -  **echo +eth3 > /sys/class/net/bond0/bonding/slaves**

#. Test out the link redundancy of the bond0 interface

   -  Start a ping test between your board and your development machine
   -  Watch the board's console and unplug one of the Ethernet cables
   -  Now plug that cable back in and unplug the other Ethernet cable
   -  You should observe the ping program continuously receiving
      responses despite the cables being plugged and unplugged
   -  The console output will show when an interface goes does down as
      well as if the active interface changes

--------------

.. rubric:: Frequently Asked Questions
   :name: frequently-asked-questions

.. rubric:: Are the HSR or PRP protocols supported?
   :name: are-the-hsr-or-prp-protocols-supported

Yes! The HSR and PRP protocols are currently supported on the AM572x IDK
board. To learn more about the HSR and PRP PRU firmware implementation
click `here <Industrial_Protocols_HSR_PRP.html>`__. To learn more about
running the protocols/firmwares while using the Linux Processor SDK
click `here <Industrial_Protocols_HSR_PRP.html#linux-software>`__.

HSR stands for High Availability Seamless Redundancy. This is a protocol
used to support redundant networks needed for industrial applications
such as factory automation, substation automation etc. The standard is
defined in IEC 62439-3 clause 5.

PRP stands for Parallel Redundancy Protocol which is another redundancy
protocol defined by IEC 62439-3 clause 4.

.. rubric:: I am using the AM571x IDK, why do I only see 4 Ethernet
   interfaces instead of 6?
   :name: i-am-using-the-am571x-idk-why-do-i-only-see-4-ethernet-interfaces-instead-of-6

Due to pin sharing between the optional LCD and the PRUSS1 Ethernet
pins, the AM571x IDK supports two different configurations: 4-port
Ethernet + LCD or 6-port Ethernet with no LCD. Jumper **J51** controls
which configuration is selected. If **J51** is closed then the 4-port +
LCD configuration is selected and if **J51** is open then the 6-port
Ethernet configuration is selected and the LCD is disabled.

.. rubric:: What if I want the PRU-ICSS to run a custom firmware (not
   Ethernet) on one of these industrial boards?
   :name: what-if-i-want-the-pru-icss-to-run-a-custom-firmware-not-ethernet-on-one-of-these-industrial-boards

The pru\_rproc driver uses the of\_machine\_is\_compatible() function to
check if the device that it is running on is compatible with one of the
boards above. If it is compatible, then the pru\_rproc driver loads the
Texas Instruments provided PRU-ICSS Ethernet firmwares. If you would
like to run your own PRU firmwares on one of the IDKs or the ICE board
then you will need to modify the device tree file to remove the IDK or
ICE compatibility declaration:

-  AM3359 ICE board

   -  Remove the **"ti,am3359-icev2"** compatible declaration at the top
      of the **arch/arm/boot/dts/am335x-icev2.dts** file

-  AM437x IDK board

   -  Remove the **"ti,am437x-idk-evm"** compatible declaration at the
      top of the **arch/arm/boot/dts/am437x-idk-evm.dts** file

-  AM572x IDK board

   -  Remove the **"ti,am5718-idk"** compatible declaration at the top
      of the **arch/arm/boot/dts/am571x-idk.dts** file

-  AM572x IDK board

   -  Remove the **"ti,am5728-idk"** compatible declaration at the top
      of the **arch/arm/boot/dts/am572x-idk.dts** file

Once these compatibility declarations are removed you will need to
rebuild your .dtb file and place it wherever it needs to be when you
reboot your board (filesystem, nfs directory, tftp directory, etc.)

Keep in mind that the PRU pin muxing on these boards is configured to
bring the MII pins out of the device. Changing the pin muxing to
accommodate your custom PRU firmware will be left as an exercise for the
user.

.. rubric:: What is the expected PRU-ICSS Ethernet throughput? How can I
   test the throughput on my setup?
   :name: what-is-the-expected-pru-icss-ethernet-throughput-how-can-i-test-the-throughput-on-my-setup

The maximum bandwidth of the PRU-ICSS Ethernet ports is 100 Mbps. The
observed throughput that I have achieved consistently is around 94 Mbps
using TCP or UDP and testing with iperf. Here are the commands needed to
test for yourself (this assumes you've followed the steps on this page
to get your PRU-ICSS interface up and running already):

-  Make sure that your board and your Linux development machine can
   'see' each other on the network (I connect both to the same switch
   and allow them to use DHCP to acquire IP addresses on the same
   network)
-  Use **ifconfig** on both your Linux development machine and your
   board and note down each IP address

   -  For the purposes of this example I will use 192.168.0.105 as the
      Linux host IP and 192.168.1.110 as the board's IP

-  Testing TCP transmit throughput

   -  Start an iperf server on your Linux development machine (**sudo
      apt-get install iperf** if you don't already have iperf installed)

      -  **iperf -s**

   -  Run the iperf client from your board to connect to the iperf
      server you just started

      -  **iperf -c 192.168.0.105**

   -  You should see your board connect to the server and a few seconds
      later both the server and the client will output the Bandwidth
      achieved

      -  For me this is output is around 94 Mbits/sec

   -  Quit the iperf server that is running on your Linux development
      machine

      -  **Ctrl + c**

-  Testing TCP receive throughput

   -  Use the same procedure as provided for testing TCP transmit
      throughput except swap the commands on the two devices (**iperf
      -s** from the board and **iperf -c 192.168.1.110** from the Linux
      development machine)

-  Testing UDP transmit throughput

   -  Start a UDP iperf server on your Linux development machine

      -  **iperf -s -u**

   -  Run a UDP iperf client from your board and specify the bandwidth
      you'd like to achieve

      -  **iperf -c 192.168.0.105 -u -b 100M**

   -  Once again my results are around 94 Mbit/sec
   -  Quit the iperf server that is running on your Linux development
      machine

      -  **Ctrl + c**

-  Testing UDP receive throughput

   -  Use the same procedure as provided for testing UDP transmit
      throughput except swap the commands on the two devices (**iperf -s
      -u** from the board and **iperf -c 192.168.0.110 -u -b 100M** from
      the Linux development machine)

.. rubric:: Is flow control supported in the PRU-ICSS Ethernet ports?
   :name: is-flow-control-supported-in-the-pru-icss-ethernet-ports

| Flow control is not currently supported in this version of the
  PRU-ICSS Ethernet firware that is provided by Texas Instruments.

.. rubric:: Are multicast and VLAN filtering as well as storm prevention
   supported in the PRU-ICSS Ethernet ports?
   :name: are-multicast-and-VLAN-filtering-as-well-as-storm-prevention-supported-in-the-pru-icss-ethernet-ports

Yes, the Dual EMAC firmware supports per port multicast and VLAN filtering, as well
as network storm prevention. These features also exist in the HSR/PRP firmware
and are detailed for both HSR/PRP and Dual EMAC here:
`HSR/PRP Linux Software <Industrial_Protocols_HSR_PRP.html#linux_software>`__

.. rubric:: How do I check the link status and hardware statistics of my
   PRU-ICSS Ethernet ports?
   :name: how-do-i-check-the-link-status-and-hardware-statistics-of-my-pru-icss-ethernet-ports

You can use the **ethtool** utility:

-  **ethtool eth2** (for link status)
-  **ethtool -S eth2** (for hardware statistics)

.. rubric:: Is RX interrupt pacing supported?
   :name: is-rx-interrupt-pacing-support

Yes, usage is the same as for HSR/PRP protocols, see 
`HSR/PRP Linux Software>Receive Interrupt Pacing <Industrial_Protocols_HSR_PRP.html#receive-interrupt-pacing>`__.


