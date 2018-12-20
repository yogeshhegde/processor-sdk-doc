.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_FATFS 

Overview
--------

Introduction
^^^^^^^^^^^^

FATFS module provides an interface to configure a driver for FAT file
system compatible device that connects via MMCSD, USB, etc. It
configures FATFS for disk operations driver disk Initialize, disk
read, disk write

Driver Overview
---------------

PDK FATFS driver provides support for both single and multiple partition on a given
SD/MMC card. The driver uses a volume to partition mapping technique to handle multiple
storage device with multiple partition which is detailed in the following section. The
driver supports file operations such as open, read and wirte on to the SD/MMC card.
The FATFS driver access the SD/MMC card through the PDK MMCSD driver which needs to be
configured from the application as part of the FATFS_config structure.

The FATFS_config structure array holds the information of the MMCSD controller instance number,
MMCSD driver function table, FATFS object which holds the information of filesystem of the
SD/MMC card.

The file operation API uses the filesystem object of each partition to read, write or
remove a file or a folder and update the same to the SD/MMC card.

::

   struct FATFS_Config {
       /*! Pointer to a table of driver-specific implementations of SD APIs */
       FATFS_DrvFxnTable    *drvFxnTablePtr;

       /*! Pointer to a driver specific data and file system object */
       FATFS_Object         *object;

       /*! Pointer to a driver specific hardware attributes structure */
       FATFS_HwAttrs        *hwAttrs;
   };


Partition management
^^^^^^^^^^^^^^^^^^^^^

The FATFS driver uses a VolToPart structure variable which is a volume management table
to map logical drives to the partitions. The volume management table has two fields, pt and pd,
which are physical drive number and partition number. By default the VolToPart structure will be
assigned with 0xF indicating that the index is not assigned with any physical drive or partition number.

-  Partition structure Definition and default Volume Management Table
::

   typedef struct {
        BYTE pd;        /* Physical drive# */
        BYTE pt;        /* Partition # (0-3) */
   } PARTITION;

   PARTITION VolToPart[] = {
        {0xf, 0xf},
        {0xf, 0xf},
        {0xf, 0xf},
        {0xf, 0xf},
   };


To access FATFS API's the application needs to get the FATFS handle before
any file operation is invoked and it can be obtained by calling FATFS_open()
function. The FATFS_open function reads the sector '0' which can be either
Master Boot Record or a Boot record of any given SD/MMC card.

The sector 0 block is parsed in the FATFS_open function to get the information
of the valid partition(s) number in the card. This partition entry information
is used to update the volume management table. In case of MBR, if a card contains
a valid partition then an entry will be available in the partition entry section.
So if a card has three valid partition then the MBR has 3 partition entry.

In MBR the partition entry starts from offset 446. Each partition entry information
is of 16 bytes. The FAT table supports upto maximum of 4 partitions. When a
partition entry is found, the VolToPart structure is updated with the logical drive
number and partition number in a incremental order starting from 0 to 3

-  Updated volume management table after parsing MBR and BR of two physical drives
::

   Below is the example of two physical drives, one(MBR) with 2 partition and other(BR) with no partition
   PARTITION VolToPart[] = {
        {0, 1},    /* "0:" ==> Physical drive 0, 1st partition */
        {0, 2},    /* "1:" ==> Physical drive 0, 2nd partition */
        {1, 0},    /* "2:" ==> Physical drive 1, no valid partition */
        {0xf, 0xf} /* No more partition available */
    };



User Interface
--------------

Driver Configuration
^^^^^^^^^^^^^^^^^^^^^

.. rubric:: **Board Specific Configuration**
   :name: board-specific-configuration

All board specific configurations eg:enabling clock and pin-mux for UART
pins are required before calling any driver APIs.By default Board_Init()
API supports all initialization sequence for TI supported EVMs. In
addition it initializes UART instance for Console/STDIO.Refer `Processor
SDK RTOS Board Support <index_board.html#board-support>`__
for additional details.Once board specific configuration is complete 
FATFS_init() API can be called to initialize FATFS for the driver.


.. rubric:: **FATFS Configuration Structure**
   :name: fatfs-configuration-structure

Application is expected to perform driver specific configuration for
FATFS_config structure. The structure supports initialization of
multiple drivers for FATFS, i.e. both MMCSD and USB can be configured
to use FATFS file system by configuring each driver to different drive
instance. This structure must be provided to the FATFS driver. It must
be initialized before the FATFS_init() function is called and cannot
be changed subsequently. For details about individual fields of this
structure, see the Doxygen
help:PDK_INSTALL_DIR\\packages\\ti\\fs\\fatfs\\docs\\doxygen\\html\\index.html.

APIs
^^^^^

In order to use the FATFS module APIs, the FATFS.h and ff.h header file
should be included in an application as follows:

::

    #include <ti/fs/fatfs/FATFS.h>
    #include <ti/fs/fatfs/ff.h>

.. rubric:: API Call Flow
   :name: api-call-flow

Below sequence indicates the calling sequence of FATFS driver APIs:

::

     FATFS_Handle FATFS;
     FATFS_Params FATFSParams; 
     FATFS_Params_init(&FATFSParams); 
     FATFS = FATFS_open(peripheralNum, &FATFSParams);
     
     

At this point application can invoke additional FAT File system API
eg: f_open(), f_write(), f_read() etc to perform file operations on
device


Application
------------

Examples
^^^^^^^^

+------------------------------+-----------------------+-----------------------+----------------+--------------+
| Name                         | | Description         | Expected Results      | Supported SOCs | Build Type   |
+==============================+=======================+=======================+================+==============+
| FATFS_Console_ExampleProject | | Example will        | When a card is        |                |              |
|                              |   initialize card and | detected with valid   |  AM335x        | CCS  Project |
|                              |   checks for valid    | FAT partition console |  AM437x        |              |
|                              |   FAT partition. When | interface output will |  AM571x        |              |
|                              |   a valid FAT         | indicate "0:> "       |  AM572x        |              |
|                              |   partition is        |                       |  AM574x        |              |
|                              |   detected console    |                       |                |              |
|                              |   interface for       |                       |                |              |
|                              |   command execution   |                       |                |              |
|                              |   is provided.        |                       |                |              |
|                              |   Supported console   |                       |                |              |
|                              |   commands include ls |                       |                |              |
|                              |   (to list files of   |                       |                |              |
|                              |   directory), cd      |                       |                |              |
|                              |   (change directory), |                       |                |              |
|                              |   pwd (present        |                       |                |              |
|                              |   working directory)  |                       |                |              |
|                              |   and cat (text file  |                       |                |              |
|                              |   read operation).    |                       |                |              |
+------------------------------+-----------------------+-----------------------+----------------+--------------+
| FATFS_Console_TestApp        | Same as above         | Same as above         | AM65x          | Makefile     |
+------------------------------+-----------------------+-----------------------+----------------+--------------+


Building CCS projects based examples
------------------------------------

CCS Projects mentioned in the above table are built using pdkProjectCreate.bat/sh as explained in 
`PDK Example and Test Project Creation <index_overview.html#pdk-example-and-test-project-creation>`__


Building FATFS Test applications via makefiles
----------------------------------------------

-  FATFSD Test applications and dependent libraries are built from the top level fatfs makefile
-  Refer to the `Processor SDK RTOS Getting Started Guide <index_overview.html#setup-environment>`__  for details
   of how to setup the build environment. Once you have setup the build environment, issue the following commands:  
	-  cd <pdk>/packages/
	-  To build: make fatfs 
	-  To clean: make fatfs_clean 

- Similarly, to build at the module level, issue the following commands for rebuilding :
	
	- cd <pdk>/packages/ti/fs/fatfs
	- To build: make all
	- To clean: make clean



  
Additional References
---------------------

+-----------------------------------+-----------------------------------------+
| **Document**                      | **Location**                            |
+-----------------------------------+-----------------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)\\packages\\ti     |
|                                   | \\fs\\fatfs\\docs\\doxygen\\html\\index |
|                                   | .html                                   |
+-----------------------------------+-----------------------------------------+
| Release Notes                     | $(TI_PDK_INSTALL_DIR)\\packages\\ti     |
|                                   | \\fs\\fatfs\\docs\\ReleaseNotes_FATFS   |
|                                   | _LLD.pdf                                |
+-----------------------------------+-----------------------------------------+

| 

