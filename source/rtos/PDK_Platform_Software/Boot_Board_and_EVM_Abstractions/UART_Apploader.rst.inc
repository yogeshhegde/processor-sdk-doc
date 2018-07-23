
Overview
^^^^^^^^

UART AppLoader is a standalone application used to download application image over UART
from the host PC. Host PC shall use Teraterm tool to transfer application image to apploader.

The UART AppLoader will be loaded by MMCSD SBL to the target platform. The Apploader
application will load and execute the application binary to be tested, over UART on the target platform.

Supported Platforms
^^^^^^^^^^^^^^^^^^^

+----------------+------------------+
|      SOC       |      PLATFORM    |
+================+==================+
| AM335x         |    EVMAM335x     |
|                +------------------+
|                |    ICEV2AM335x   |
|                +------------------+
|                |    ICEAMIC110    |
+----------------+------------------+
| AM437x         |    EVMAM437x     |
|                +------------------+
|                |    IDKAM437x     |
+----------------+------------------+
| AM571x         |    IDKAM571x     |
+----------------+------------------+
| AM572x         |    EVMAM572x     |
+                +------------------+
|                |    IDKAM572x     |
+----------------+------------------+
| AM574x         |    IDKAM574x     |
+----------------+------------------+
| K2G            |    EVMK2G        |
|                +------------------+
|                |    ICEK2G        |
+----------------+------------------+
| OMAPL137       |    EVMOMAPL137   |
+----------------+------------------+
| OMAPL138       |    LCDKOMAPL138  |
+----------------+------------------+

.. note::   In case of ICEAMIC110 and EVMOMAPL137 platforms, Sdcard boot mode is not available and so the below procedure cannot be used.
            In both the cases, program Apploader to SPI flash using `Uniflash <Board_EVM_Abstration.html#programming-binaries-to-flash-device>`__ and boot the device from SPI flash.



Pre-Requisites
^^^^^^^^^^^^^^
* Download and install the latest nightly PDK package on the test PC
* The Uart Apploader binaries will be found under <pdk_install_path>/ti/board/bin/<board_name>/sd/apploader_Test

**SD Card preparation**

* Copy MLO to MMCSD card.
* Rename apploader_Test to app and copy to MMCSD card.

**Target Platform Connection**

1. Connect the MMCSD to the target platform.
2. Make sure UART connection is established between Target platform and Host PC.
3. Make sure the target platform is in MMCSD boot mode.

**Serial Connection**

Establish the Teraterm connection with the following configurations:


* Baud Rate: 115200

* Data : 8 bits

* Parity : None

* Stop : 1 bit

* Flow Control : None
    
    
Test Procedure
^^^^^^^^^^^^^^
1. Set the sysboot pins to MMCSD boot mode.
2. Power cycle the board.
3. MLO will be loaded from MMCSD, which loads the appLoader application.
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

5. Now transfer the application binary to be tested over UART using Teraterm application.
6. Use the following option in Teraterm to transfer the application binary.
  File -> Transfer -> XMODEM -> Send
7. Upon success, the application will be loaded and executed by the appLoader.
8. Check the below output on the serial console


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
        

    
.. note::  UART diagnostic application is loaded in this case
