
Overview
^^^^^^^^

UART AppLoader is a standalone application used to download application image over UART
from the host PC. Host PC uses the serial console utility to transfer application image to apploader.

The Apploader application loads and executes the application binary to be tested, 
over UART on the target platform.

Supported Platforms
^^^^^^^^^^^^^^^^^^^

+----------------+------------------+-----------------------+
|      SOC       |      PLATFORM    |   Verified Boot Modes |
+================+==================+=======================+
| AM335x         |    EVMAM335x     |       MMCSD           |
|                +------------------+-----------------------+
|                |    ICEV2AM335x   |       MMCSD           |
|                +------------------+-----------------------+
|                |    ICEAMIC110    |       SPI             |
+----------------+------------------+-----------------------+
| AM437x         |    EVMAM437x     |       MMCSD           |
|                +------------------+-----------------------+
|                |    IDKAM437x     |       MMCSD           |
+----------------+------------------+-----------------------+
| AM571x         |    IDKAM571x     |       MMCSD           |
+----------------+------------------+-----------------------+
| AM572x         |    EVMAM572x     |       MMCSD           |
+                +------------------+-----------------------+
|                |    IDKAM572x     |       MMCSD           |
+----------------+------------------+-----------------------+
| AM574x         |    IDKAM574x     |       MMCSD           |
+----------------+------------------+-----------------------+
| K2G            |    EVMK2G        |       MMCSD           |
|                +------------------+-----------------------+
|                |    ICEK2G        |       MMCSD           |
+----------------+------------------+-----------------------+
| OMAPL137       |    EVMOMAPL137   |       SPI             |
+----------------+------------------+-----------------------+
| OMAPL138       |    LCDKOMAPL138  |       MMCSD           |
+----------------+------------------+-----------------------+


Pre-Requisites
^^^^^^^^^^^^^^
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

2. The Uart Apploader binaries are found under <pdk_install_path>/ti/board/bin/<board_name>/sd/apploader_Test

**Serial Connection**

Launch the serial console utility with the following configurations:


* Baud Rate: 115200

* Data : 8 bits

* Parity : None

* Stop : 1 bit

* Flow Control : None

.. note::   Any Serial Console utility that supports xmodem protocol can be used.
            Verified utility is Teraterm
    
AppLoader Usage
^^^^^^^^^^^^^^^
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
			1. Program Apploader to SPI flash using `Uniflash <Board_EVM_Abstration.html#programming-binaries-to-flash-device>`__ and boot the device from SPI flash.
			2. Set the sysboot pins to SPI Boot mode

.. note::	For MMCSD Boot Mode:
			1. Copy MLO to SD card.
			2. Rename apploader_Test to app and copy to SD card.
			3. Set the sysboot pins to MMCSD Boot mode

 
