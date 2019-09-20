.. http://processors.wiki.ti.com/index.php/Linux_Core_SATA_User%27s_Guide

SATA
---------------------------------

.. rubric:: **Introduction**
   :name: introduction-linux-core-sata

| Serial ATA (Advance Technology Attachment)(SATA) is a computer bus
  interface that connects host bus adapters to mass storage devices such
  as hard disk drives and optical drives. Serial ATA[2] replaces the
  older AT Attachment standard (ATA later referred to as Parallel ATA or
  PATA), offering several advantages over the older interface: reduced
  cable size and cost (seven conductors instead of 40), native hot
  swapping, faster data transfer through higher signalling rates, and
  more efficient transfer through an (optional) I/O queuing protocol.


.. rubric:: **Acronyms & Definitions**
   :name: acronyms-definitions

+---------------------+------------------------------------------+
| Acronym             | Definition                               |
+=====================+==========================================+
| SATA                | Serial Advanced Technology Attachement   |
+---------------------+------------------------------------------+
| PATA                | Parallel AT Attachement                  |
+---------------------+------------------------------------------+
| SSD                 | Solid State Disk                         |
+---------------------+------------------------------------------+
| HDD                 | Hard Disk Drive                          |
+---------------------+------------------------------------------+
| Gen-1/Gen-2/Gen-3   | Generation of SATA device.               |
+---------------------+------------------------------------------+

| 

.. rubric:: **Features NOT supported**
   :name: features-not-supported

| Following features are not supported currently:

-  Gen-3 SATA HDD/SSD is not guaranteed to be supported on OMAP5 and
   DRA7 due to a silicon bug which prevents correct PHY speed
   negotiation.
-  Aggressive Power management

.. rubric:: Supported EVMs
   :name: supported-evms

+----------------+--------------------------------------+
| EVM            | Number of Instances                  |
+================+======================================+
| AM57 GP EVM    | 1 Instance (either eSATA or mSATA)   |
+----------------+--------------------------------------+
| Beagle X15     | 1 Instance (eSATA)                   |
+----------------+--------------------------------------+
| DRA74 GP EVM   | 1 Instance (SATA)                    |
+----------------+--------------------------------------+

Table:  caption

.. rubric:: Kernel Configuration
   :name: kernel-configuration

::

    Device Drivers  --->
        <M> Serial ATA and Parallel ATA drivers (libata)  --->
            <M>   AHCI SATA support
            <M>   Platform AHCI SATA support

.. rubric:: Accessing SATA Hard Drive
   :name: accessing-sata-hard-drive

These instructions assume the SATA hard drive being used has already
been partitions. Information on partition the hard drive is beyond the
scope of this article.

.. rubric:: Kernel
   :name: kernel

.. rubric:: Detecting Hard Drive
   :name: detecting-hard-drive

Before you can start reading and writing to a partition you first need
to know which sdX device is associate with the hard drive. The easiest
approach is to use "parted -l".

This command will show all the various storage medias Linux has
detected. The output that will be shown may be quite large if you have
sd cards, eMMC, USB thumbdrives, etc.. connected to the board. However,
for SATA your only interested in devices that have "(scsi)" at the end
of the Model field.

Example output of the command is shown below. Non SATA related output
was truncated.

::

    root@am57xx-evm:~# parted -l
    ...
    Model: ATA PLEXTOR PX-64M6M (scsi)
    Disk /dev/sda: 64.0GB
    Sector size (logical/physical): 512B/512B
    Partition Table: msdos
    Disk Flags: 

    Number  Start   End     Size    Type     File system  Flags
     1      1049kB  83.9MB  82.8MB  primary  fat32        boot, lba
     2      84.9MB  17.3GB  17.2GB  primary  fat32
     3      17.3GB  64.0GB  46.8GB  primary  ext2
    ...

Above the model field shows the name of the particular hard drive and in
the disk field it shows the specific device (/dev/sdX) its associated
with along with the size. In the above example this Plextor hard drive
is associated with "/dev/sda". The other additional information that can
be gathered from the parted -l command is information regarding the
various partitions. In the table that has column Number, Start, End,
etc... you can see this hard drive has 3 partitions. The command shows
various information including the partition size along with the file
system type.

This is useful since each partition can be accessed via /dev/sdXY. Where
X is the specific disk letter and Y is the partition number. Therefore,
the device that is associated with the Plextor hard drive's second
partition is "/dev/sda2" which is a ~17GB FAT32 partition.

.. rubric:: Determining Mounted Partition Location
   :name: determining-mounted-partition-location

Now its likely if you have partitions on the hard drive that their
already been automated. Use "lsblk /dev/sdX" to determine if a partition
has been mounted and if so where.

Example output of the command is shown below:

::

    root@am57xx-evm:~# lsblk /dev/sda
    NAME   MAJ:MIN RM  SIZE RO TYPE MOUNTPOINT
    sda      8:0    0 59.6G  0 disk 
    |-sda2   8:2    0   16G  0 part /run/media/sda2
    |-sda3   8:3    0 43.6G  0 part
    `-sda1   8:1    0   79M  0 part /run/media/sda1

The above output shows the three sda partitions. Under mountpoint it
list the directory that the partition has been mounted to. However, a
blank entry under mount point indicates the partition has not been
mounted.

.. rubric:: U-Boot
   :name: u-boot-linux-core-sata

Information regarding accessing SATA hard drive in U-boot can be found
in the Linux Core U-boot User's Guide SATA Section.
