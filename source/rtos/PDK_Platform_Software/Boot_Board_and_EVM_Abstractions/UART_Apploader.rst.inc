
Overview
--------

UART AppLoader is a standalone application used to download application image over UART
from the host PC. Host PC uses the serial console utility to transfer application image to apploader.

The Apploader application loads and executes the application binary to be tested, 
over UART on the target platform.

Supported Platforms
-------------------

+----------------+------------------+-----------------------+
|      SOC       |      PLATFORM    |   Verified Boot Modes |
+================+==================+=======================+
| AM335x         | AM335x GP EVM    |       MMCSD           |
|                +------------------+-----------------------+
|                | AM335x ICEv2     |       MMCSD           |
|                +------------------+-----------------------+
|                | AMIC110 ICE      |       SPI             |
+----------------+------------------+-----------------------+
| AM437x         | AM437x EVM       |       MMCSD           |
|                +------------------+-----------------------+
|                | AM437x IDK       |       MMCSD           |
+----------------+------------------+-----------------------+
| AM571x         | AM571x IDK       |       MMCSD           |
+----------------+------------------+-----------------------+
| AM572x         | AM572x EVM       |       MMCSD           |
+                +------------------+-----------------------+
|                | AM572x IDK       |       MMCSD           |
+----------------+------------------+-----------------------+
| AM574x         | AM574x IDK       |       MMCSD           |
+----------------+------------------+-----------------------+
| K2G            | K2G GP EVM       |       MMCSD           |
|                +------------------+-----------------------+
|                | K2G ICE          |       MMCSD           |
+----------------+------------------+-----------------------+
| OMAPL137       | OMAPL137 EVM     |       SPI             |
+----------------+------------------+-----------------------+
| OMAPL138       | OMAPL138 LCDK    |       MMCSD           |
+----------------+------------------+-----------------------+

Apploader Load Address
----------------------

+----------------+------------------+------------------+-----------------------+--------------------------+
|      SOC       |     PLATFORM     |      DDR Size    |   DDR Start Address   |  Apploader Load Address  |
+================+==================+==================+=======================+==========================+
| AM335x         | AM335x GP EVM    |       1GB        |       0x80010000      |         0xBFE00000       |
|                +------------------+------------------+-----------------------+--------------------------+
|                | AM335x ICEv2     |      256MB       |       0x80010000      |         0x8FD00000       |
|                +------------------+------------------+-----------------------+--------------------------+
|                | AMIC110 ICE      |      512MB       |       0x80010000      |         0x9FE00000       |
+----------------+------------------+------------------+-----------------------+--------------------------+
| AM437x         | AM437x EVM       |       2GB        |       0x80000000      |         0xFFE00000       |
|                +------------------+------------------+-----------------------+--------------------------+
|                | AM437x IDK       |       1GB        |       0x80000000      |         0xBFE00000       |
+----------------+------------------+------------------+-----------------------+--------------------------+
| AM571x         | AM571x IDK       |       1GB        |       0x80000000      |         0xBFDFFFFF       |
+----------------+------------------+------------------+-----------------------+--------------------------+
| AM572x         | AM572x EVM       |       2GB        |       0x80000000      |         0xFFDFFFFF       |
+                +------------------+------------------+-----------------------+--------------------------+
|                | AM572x IDK       |       2GB        |       0x80000000      |         0xFFDFFFFF       |
+----------------+------------------+------------------+-----------------------+--------------------------+
| AM574x         | AM574x IDK       |       2GB        |       0x80000000      |         0xFFDFFFFF       |
+----------------+------------------+------------------+-----------------------+--------------------------+
| K2G            | K2G GP EVM       |       2GB        |       0x80000000      |         0xFFD00000       |
|                +------------------+------------------+-----------------------+--------------------------+
|                | K2G ICE          |      512MB       |       0x80000000      |         0x9FE00000       |
+----------------+------------------+------------------+-----------------------+--------------------------+
| OMAPL137       | OMAPL137 EVM     |      64MB        |       0xC3000000      |         0xC6E00000       |
+----------------+------------------+------------------+-----------------------+--------------------------+
| OMAPL138       | OMAPL138 LCDK    |      128MB       |       0xC0000000      |         0xC7E00000       |
+----------------+------------------+------------------+-----------------------+--------------------------+

Pre-Requisites
--------------
1. Download and install the Processor-SDK RTOS package. See the software product page for your device to get the latest version of this software:

-  `Processor SDK for
   AM335x <http://www.ti.com/tool/processor-sdk-am335x>`__
-  `Processor SDK for
   AM437x <http://www.ti.com/tool/processor-sdk-am437x>`__
-  `Processor SDK for
   AM57xx <http://www.ti.com/tool/processor-sdk-am57x>`__
-  `Processor SDK for
   AMIC110 <http://www.ti.com/tool/PROCESSOR-SDK-AMIC110>`__
-  `Processor SDK RTOS for
   C6747/OMAP-L17 <http://www.ti.com/tool/processor-sdk-omapl137>`__
-  `Processor SDK RTOS for
   C6748/OMAP-L138 <http://www.ti.com/tool/processor-sdk-omapl138>`__
-  `Processor SDK RTOS for
   K2G <http://www.ti.com/tool/PROCESSOR-SDK-K2G>`__

   From the appropriate software product page, go to the download page by
   clicking "Get Software" for the RTOS package.

2. The Uart Apploader binaries are found under <pdk_install_path>/packages/ti/board/utils/uartAppLoader/bin/<board_name>/sd/apploader_Test

**Serial Connection**

Launch the serial console utility with the following configurations:


* Baud Rate: 115200

* Data : 8 bits

* Parity : None

* Stop : 1 bit

* Flow Control : None

.. note::   Any Serial Console utility that supports xmodem protocol can be used.
            Verified utility is Teraterm
    
.. note::	TI Binaries does not work with Apploader on AM335x/AM437x platforms.
            Make sure to use non TI binaries for testing on these platforms.

AppLoader Usage
---------------
1. Set the sysboot pins to the relevant boot mode(SPI / MMCSD).
2. Make sure UART connection is established between Target platform and Host PC.
3. Power cycle the board.
4. Check the below output on the serial console. The application starts sending character 'C'

::

        **** PDK SBL ****                                                
        SBL Revision: 01.00.09.00 (May 10 2018 - 15:48:57)               
        Begin parsing user application                                   
                                                                                    
        SD Boot - file open completed successfully                       
        Jumping to user application...                                   
        ********* PDK UART Apploader ********                            
        version 0.1 (May 14 2018 - 21:40:11)                             
                                                                                     
        Please transfer file with XMODEM protocol...                     
        CCCC

.. note::  The above log is for reference purpose and content might change based on latest software available in processor SDK release

5. Now transfer the application binary to be tested over UART using serial console utility.

.. note::	For example in Teraterm, use the following option to transfer the application binary.
			File -> Transfer -> XMODEM -> Send

6. Upon success, the apploader loads and executes the application.
7. Following is the sample output (using UART Diagnostic application), on the serial console.

::

        Xmodem received 46848 bytes                                      
                                                                                
        Copying application image from UART to RAM is done               
        Begin parsing user application                                  
        Jumping to user application...                                   
                                                                                  
        *********************************************                    
        *                 UART Test                 *                    
        *********************************************                    
                                                                                    
        Testing UART print to console at 115.2k baud rate                
        Press 'y' to verify pass: y                                      
        Received: y                                                      
                                                                                    
        Test PASSED!

.. note::	For SPI Boot Mode:
			1. Program Apploader to SPI flash using `Uniflash <index_board.html#programming-binaries-to-flash-device>`__ and boot the device from SPI flash.
			2. Set the sysboot pins to SPI Boot mode

.. note::	For MMCSD Boot Mode:
			1. Copy MLO to SD card.
			2. Rename apploader_Test to app and copy to SD card.
			3. Set the sysboot pins to MMCSD Boot mode

Rebuilding AppLoader
---------------------
Apploader pre-built binaries are currently not available for OMAPL137/L138 platforms.
Binaries needs to be manually built for these platforms.

Refer `Rebuilding Board Utils <index_board.html#rebuilding-board-utils>`__ section to build Apploader.

.. raw:: html