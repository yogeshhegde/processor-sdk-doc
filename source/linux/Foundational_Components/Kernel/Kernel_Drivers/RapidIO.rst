.. http://processors.wiki.ti.com/index.php/Linux_Core_RapidIO_User%27s_Guide
.. rubric:: Introduction
   :name: introduction

The Keystone 2 Hawking/Kepler (K2HK) SoC includes a RapidIO subsystem.
This subsystem consists of the a Serial RapidIO module, a 4 lane SerDes
macro, CPDMA and local SCR. The SRIO subsystem is compliant with SRIO
2.1 specification.

.. rubric:: RapidIO Driver
   :name: rapidio-driver

The Keystone Linux RapidIO driver is integrated into the Linux RapidIO
master port (mport) subsystem. It supports RIONET and DirectIO
(one-to-one memory mapping).

.. rubric:: Driver Source Location
   :name: driver-source-location

Driver files are located in Linux kernel source directory
drivers/rapidio/devices/. They are:

-  keystone\_rio.c
-  keystone\_rio\_dma.c
-  keystone\_rio\_mp.c
-  keystone\_rio\_serdes.c

.. rubric:: Kernel Configuration
   :name: kernel-configuration

To enable support of RapidIO in the K2HK kernel build, the following
features must be set in the kernel configuration file (.config)

::

         CONFIG_HAS_RAPIDIO=y
         CONFIG_RAPIDIO=y
         CONFIG_TI_KEYSTONE_RAPIDIO=y
         CONFIG_RAPIDIO_DISC_TIMEOUT=200
         CONFIG_RAPIDIO_ENABLE_RX_TX_PORTS=y
         CONFIG_RAPIDIO_DMA_ENGINE=y
         CONFIG_RAPIDIO_DEV=y
         CONFIG_RAPIDIO_ENUM_BASIC=y
         CONFIG_RAPIDIO_MPORT_CDEV=y
         CONFIG_RIONET=y
         CONFIG_RIONET_TX_SIZE=128
         CONFIG_RIONET_RX_SIZE=128

.. rubric:: Devicetree Configurations
   :name: devicetree-configurations

Normally most of the RapidIO devicetree entries need not be changed for
a normal usage.

Some entries under 'rapidio: rapidio@2900000' in
arch/arm/boot/dts/keystone-k2hk-srio.dtsi can be configured for your
usage:

-  baudrate = <baudrate\_mode>; where baudrate can have the following
   values 0 (1.25Gbps), 1 (2.5Gbps), 2 (3.125Gbps) and 3 (5Gbps)
-  path\_mode = <path\_mode>; where path\_mode refers to the various
   SerDes-lanes-to-port mapping modes. Refer to the peripheral's
   `Keystone Architecture Serial RIO User
   Guide <http://www.ti.com/lit/ug/sprugw1b/sprugw1b.pdf>`__ for more
   information. The most useful modes are 0 (1 port in 1x) or 4 (1 port
   in 4x).
-  ports = <port\_bitfield>; where port\_bitfield indicates the mapping
   of ports we want to use in Linux to SerDes lanes. It is recommended
   to use only one port (0x1, 0x2, 0x4, 0x8 values) because multi-port
   is not fully supported yet.

.. rubric:: Kernel command line parameters
   :name: kernel-command-line-parameters

The Linux RapidIO framework needs to set some specific parameters into
the Linux command line (through U-Boot).

-  rapidio.hdid=<host\_id>[,<host\_id2>,...]

   -  this parameter is used to define the host device Id. A host\_id
      value greater or equal to zero indicates that this host will
      perform enumeration of the whole RapidIO topology using the
      host\_id device Id. A '-1' value indicates that no device Id will
      be set and the host will wait for being enumerated by a remote
      device then it will discover the RapidIO topology. In case of
      multiple mport instances, a list of host device Id can be
      specified.

-  rio-scan.scan=<boolean>

   -  if explicitly set to 1 the scanning (discovery/enumeration) will
      be performed at boot time. If set to 0 (which is the default value
      if this parameter is not specified), the scanning must be
      triggered by user.

-  rio-scan.static\_enum=<boolean>

   -  this parameter allows to use static enumeration if set to 1. By
      default this parameter is set to 0. Static enumeration allows to
      discover the RapidIO topology without waiting for being enumerated
      by a remote host and using the remote host id instead of
      dynamically creating one like with standard enumeration.

If you want to perform scanning at boot time the recommended kernel
parameters are

::

         EVM1: 'rapidio.hdid=0 rio-scan.scan=1'
         EVM2: 'rapidio.hdid=-1 rio-scan.scan=1'

In this case the EVM2 must be booted before EVM1. No need to wait EVM2
to fully complete its boot but at least few seconds are necessary to
ensure that EVM2 port will be activated when EVM1 starts testing it.

Note that you can still rescan the full sRIO bus from userspace after
boot by typing the following command on the both targets:

::

         echo '-1' > /sys/bus/rapidio/scan

If you want to perform scanning from user space, the recommended kernel
parameters are:

::

         EVM1: 'rapidio.hdid=-1 rio-scan.scan=0'
         EVM2: 'rapidio.hdid=0 rio-scan.scan=0'

Once the two boards are booted, trigger the scanning
(enumeration/discovery) from user space on both boards using the
following command:

::

         echo '-1' > /sys/bus/rapidio/scan

In this case, there is no requirements on the order in which the boards
must be booted.

.. rubric:: MPORT Character Device
   :name: mport-character-device

The character device implemented by Linux RapidIO mport subsystem
provides character device read/write and some IOCtl operations to

-  read/write local and remote RapidIO configuration registers
-  send Doorbells
-  perform DirectIO

See Documentation/rapidio/mport\_cdev.txt in Linux kernel source code
for more details.

| 

.. rubric:: Using RIONET
   :name: using-rionet

After booting up both EVMs, you must see boot traces similar to the
following:

::

         [   11.938748] eth6: rionet Ethernet over RapidIO Version 0.3, MAC 00:01:00:01:00:00, RIO0 mport
         [   11.945718] Using 00:e:0002 (vid 0030 did b981)
         [   11.949829] keystone-rapidio 2900000.rapidio: Opened tx channel: ed9c5a34
         [   11.955693] keystone-rapidio 2900000.rapidio: Opened rx channel: ed9c5e34 (mbox=1, flow=19, rx_q=8715, pkt_type=11)

On EVM1 run the following command:

::

         ifconfig eth6 192.168.1.1

You must substitute 'eth6' with the interface that corresponds to the
MAC address 00:01:00:01:00: 00 (check by performing command "ifconfig
-a")

On EVM2 run the following command:

::

         ifconfig eth6 192.168.1.2

You must substitute eth6 with the interface that corresponds to MAC
address 00:01:00:01:00: 01

You can then use "ping 192.168.1.2" on EVM1 or "ping 192.168.1.1" on
EVM2. Make sure that ping receives responses successfully.

On EVM2, run the command "telnet 192.168.1.1". Make sure that the telnet
session can be opened successfully. Ping and telnet can be performed on
either EVM as long as the appropriate remote IP address is used in the
command.

| 

.. rubric:: Using DirectIO
   :name: using-directio

Once both boards have been booted and the RapidIO bus has been
enumerated, the scanned remote ID can be used in performing DirectIO
operation. The following sample code demonstrate how to use DirectIO to
send a file to another K2HK EVM.

This example sends a file named "filename" to address 0x80000000 on a
remote K2HK EVM with RapidIO device ID 1.

::

         struct rio_transaction tran;
         struct rio_transfer_io xfer;
         int mport_fd, input_fd;
         u16 target_destid;
         u32 target_addr;
         char *buf;
         
         mport_fd = open(/dev/rio_mport0, O_RDWR | O_CLOEXEC | oflags);
         target_destid = 1;
         target_addr = 0x80000000;
         input_fd = ("filename", O_RDONLY);
         buf = malloc(1024 * 1024);
         
         i = 0;
         total = 0;
         dst_off = 0;
         while((ret_in = read (input_fd, buf, 4 * 1024)) > 0){
            xfer.rioid = target_destid;
            xfer.rio_addr = target_addr + dst_off;
            xfer.loc_addr = buf;
            xfer.length = ret_in;
            xfer.handle = 0;
            xfer.offset = 0;
            xfer.method = RIO_EXCHANGE_NWRITE_R;
            
            tran.transfer_mode = RIO_TRANSFER_MODE_TRANSFER;
            tran.sync = RIO_TRANSFER_SYNC
            tran.dir = RIO_TRANSFER_DIR_WRITE;
            tran.count = 1;
            tran.block = &xfer;
            
            ioctl(mport_fd, RIO_TRANSFER, &tran);
         
            dst_off += ret_in;
            ++i;
         }

.. rubric:: Using Doorbells
   :name: using-doorbells

The following sample snippet sends a doorbell with a doorbell info value
of 0x0002 to a remote K2HK EVM with RapidIO device ID 1.

**Note**: The 16-bit RapidIO doorbell info is hardware implementation
specific. On TI's RapidIO module, each bit of the 16-bit value is mapped
to an interrupt. By the default configuration in the devicetree
bindings, these interrupts are mapped to the 16 interrupts starting from
153. Thus bit-0 in the doorbell info will trigger the interrupt 153,
while bit-1 will trigger interrupt 154 and so on, on the remote K2HK
EVM.

::

         struct rio_event sevent;
         u16 target_destid;
         u16 db_info;
         char *p = (char*)&sevent;
         unsigned int len = 0;
         
         mport_fd = open("/dev/rio_mport0", O_RDWR | O_CLOEXEC | oflags);
         
         target_destid = 1;
         
         db_info = 0x0002;
         
         sevent.header = RIO_DOORBELL;
         sevent.u.doorbell.rioid = target_destid;
         sevent.u.doorbell.payload = db_info;
         
         while (len < sizeof(sevent)) {
                 ret = write(mport_fd, p + len, sizeof(sevent) - len);
                 len += ret;
         }

.. raw:: html

