.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_FATFS 

| 

.. rubric:: Introduction
   :name: introduction

| FATFS module provides an interface to configure a driver for FAT file
  system compatible device that connects via MMCSD, USB, etc. It
  configures FATFS for disk operations driver disk Initialize, disk
  read, disk write

.. rubric:: Driver Configuration
   :name: driver-configuration

.. rubric:: **Board Specific Configuration**
   :name: board-specific-configuration

All board specific configurations eg:enabling clock and pin-mux for UART
pins are required before calling any driver APIs.By default Board_Init()
API supports all initialization sequence for TI supported EVMs. In
addition it initializes UART instance for Console/STDIO.Refer `Processor
SDK RTOS Board Support </index.php/Processor_SDK_RTOS_Board_Support>`__
for additional details.Once board specific configuration is complete 
FATFS_init() API can be called to initialize FATFS for the driver.

| 
| **FATFS Configuration Structure**

| Application is expected to perform driver specific configuration for
  FATFS_config structure. The structure supports initialization of
  multiple drivers for FATFS, i.e. both MMCSD and USB can be configured
  to use FATFS file system by configuring each driver to different drive
  instance. This structure must be provided to the FATFS driver. It must
  be initialized before the FATFS_init() function is called and cannot
  be changed subsequently. For details about individual fields of this
  structure, see the Doxygen
  help:PDK_INSTALL_DIR\packages\ti\fs\fatfs\docs\doxygen\html\index.html.

.. rubric:: **APIs**
   :name: apis

In order to use the FATFS module APIs, the FATFS.h and ff.h header file
should be included in an application as follows:

::

    #include <ti/fs/fatfs/FATFS.h>
    #include <ti/fs/fatfs/ff.h>

| 

.. rubric:: API Call Flow
   :name: api-call-flow

Below sequence indicates the calling sequence of FATFS driver APIs:

::

     FATFS_Handle FATFS;
     FATFS_Params FATFSParams; 
     FATFS_Params_init(&FATFSParams); 
     FATFS = FATFS_open(peripheralNum, &FATFSParams);
     
     

| At this point application can invoke additional FAT File system API
  eg: f_open(), f_write(), f_read() etc to perform file operations on
  device

.. rubric:: Examples
   :name: examples

+-----------------------+-----------------------+-----------------------+
| Name                  | Description           | Expected Results      |
+=======================+=======================+=======================+
| FATFS Example         | | Example will        | When a card is        |
| application           |   initialize card and | detected with valid   |
|                       |   checks for valid    | FAT partition console |
|                       |   FAT partition. When | interface output will |
|                       |   a valid FAT         | indicate "0:> "       |
|                       |   partition is        |                       |
|                       |   detected console    |                       |
|                       |   interface for       |                       |
|                       |   command execution   |                       |
|                       |   is provided.        |                       |
|                       |   Supported console   |                       |
|                       |   commands include ls |                       |
|                       |   (to list files of   |                       |
|                       |   directory), cd      |                       |
|                       |   (change directory), |                       |
|                       |   pwd (present        |                       |
|                       |   working directory)  |                       |
|                       |   and cat (text file  |                       |
|                       |   read operation).    |                       |
+-----------------------+-----------------------+-----------------------+

.. rubric:: 
   :name: section

.. rubric:: 
   :name: section-1

.. rubric:: 
   :name: section-2

.. rubric:: 
   :name: section-3

.. rubric:: 
   :name: section-4

.. rubric:: 
   :name: section-5

.. rubric:: 
   :name: section-6

.. rubric:: 
   :name: section-7

| 

.. rubric:: Additional documentation reference
   :name: additional-documentation-reference

+-----------------------------------+-----------------------------------+
| **Document**                      | **Location**                      |
+-----------------------------------+-----------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \fs\fatfs\docs\doxygen\html\index |
|                                   | .html                             |
+-----------------------------------+-----------------------------------+
| Release Notes                     | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \fs\fatfs\docs\ReleaseNotes_FATFS |
|                                   | _LLD.pdf                          |
+-----------------------------------+-----------------------------------+

.. raw:: html

