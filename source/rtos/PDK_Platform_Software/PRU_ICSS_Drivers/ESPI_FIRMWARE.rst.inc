.. http://ap-fpdsp-swapps.dal.design.ti.com/index.php/Processor_SDK_RTOS_ESPI_FIRMWARE

Requirements
============
- Windows 7
- Processor SDK v5.2 for AM335x
- Code Composer Studio v8.1.0.00011
- Beagle Bone Black rev. C

Build/Load
==========
These instructions assume Processor SDK v5 is already installed on Windows 7

      <PDK> = C:\ti\pdk_am335x_1_0_12\

Driver/Firmware
---------------
1. Copy the SPI package into <PDK>\packages\drv\spi\
2. To build the driver and firmware, open a CMD window and enter the following:
   1. cd <PDK>\packages\
   2. pdksetupenv.bat
   3. gmake spi
   4. cd ti\drv\spi\
   5. gmake xdc_meta

Application
-----------
1. To create the application CCS project, open a CMD window and enter the following:
      1. cd <PDK>\packages\
      2. pdksetupenv.bat
      3. pdkProjectCreate.bat <SOC> all little spi
      	    1. <SOC> = processor used (e.g. AM335x)
      	    2. This builds all SPI applications
      
2. To build the CCS application:
      1. Open CCS 8.1.0
      2. Create a new Workspace
      3. In the menu bar select Project > Import CCS Projects…
      4. Click “Browse…”
      5. Navigate to and select: <PDK>\MyExampleProjects\
      6. Select “ESPI_FwExample_bbbAM335x_armExampleProject” from Discovered Projects
      7. From the Project Explorer, select ESPI_FwExample_AM335x_armExampleProject
      8. Right-click the project name, and select Build Project
   
To load/run the binary
-----------------------
1. In the Target Configurations window, right click and select “New Target Configuration” and set up as follows:
      1. Connection: Select whichever debugger you have hooked up
      2. Board or device: BeagleBone_Black
2. Right-click your created CCXML from the Target Configurations window and select “Launch selected configuration”
3. Menu-bar: Run > Reset > System Reset
4. Right-click the CortexA8 core in the Debug window, select “Connect Target”
5. Menu-bar: Scripts > PRU_ICSS > PRU_ICSS_Init
6. Menu-bar: Run > Load > Load Program… and navigate to: <PDK>\packages\MyExampleProjects\ESPI_FwExample_bbbAM335x_armExampleProject\Debug\ESPI_FwExample_bbbAM335x_armExampleProject.out
7. Menu-bar: Run > Resume (if not already running automatically)
8. Connect to PRU0
9. Run > Resume
10. Connect to PRU1
11. Run > Resume

eSPI Applications
=================
We have included a simple example test application which handles PUT_IORD_SHORT, PUT_IOWR_SHORT, PUT_MEMRD32_SHORT, and PUT_MEMWR32_SHORT packets with expected address/data values. This can be used as a starting point to build your own applications, along with the following:
- eSPI uses the MCSPI API
    - Open as MCSPI instance 2
- HW interrupts must be enabled
    - i.e. HwiP_enableInterrupt(espi_cfg.intNum)
- MCSPI_transfer() is blocking and takes a SPI_Transaction parameter which is used as follows:
    - RX Transfer:
      - transaction.rxBuf = <some pre-allocated buffer>
      - transaction.txBuf = Null
      - transaction.count = max packet size
    - TX Transfer:
      - transaction.rxBuf = Null
      - transaction.txBuf = <some pre-allocated buffer>
      - transaction.count = <size of packet>
- The application must parse the full eSPI packet, and must respond with the full proper eSPI packet (the RSP code and CRC will be taken care of by the firmware)

Limitations
===========
1. Dual and Quad mode not tested
eSPI supports Single, Dual, and Quad I/O modes, all are supported but only Single mode has been tested and proven to work at this point in time.

2. Supported Commands
The following is a list of the supported eSPI commands, all other commands will result in NO_RESONSE:
    - GET_STATUS
    - GET_CONFIGURATION
    - SET_CONFIGURATION
    - PUT_IORD_SHORT (peripheral non-posted)
    - PUT_IOWR_SHORT (peripheral non-posted)
    - PUT_MEMRD32_SHORT (peripheral non-posted)
    - PUT_MEMWR32_SHORT (peripheral posted)
    - GET_PC
    - RESET

3. Single-depth Queues
Only one packet per queue type can be handled. Currently supported queues are the Peripheral Non-Posted (NP) RX & TX queues, and the Peripheral Posted-Completion (PC) RX & TX queues. If the RX queue is full the corresponding bit will be updated in the Status Register, thus any attempt to put another packet in the same RX queue will result in a FATAL_ERROR. Once the RX queue is cleared by the Host, any attempt to put another packet in the RX queue will result in NON_FATAL_ERROR, until the packet has been read from the corresponding TX queue.

4. No Response Modifier Support
eSPI supports Response Modifier packets attached to the GET_STATUS response, however we do not support them. Any SET_CONFIGURATION requests to enable Response Modifiers will be ignored and not updated.

5. I/O[1] Alert Not Supported
eSPI allows for either the I/O[1] line or the Alert# pin to signal an ALERT, however we only support signaling with the Alert# pin. This is NOT the default configuration, and the master needs to adjust accordingly by issuing a SET_CONFIGURATION with the Alert Mode bit set to 1 in the General Capabilities and Configurations register.

Known Issues
============
1. Reset Interrupts
Currently Reset# interrupts are handled in the eSPI driver via GPIO, these will be moved to the application and the user will be responsible for handling a hard Reset.

2. ESPI Close
The ESPI_close_v2() function isn’t properly implemented. This shouldn’t be too much of an issue for evaluation purposes, but keep in mind that closing an eSPI instance will leave HWI’s intact.
