.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_DSS

Overview
--------

Introduction
^^^^^^^^^^^^

Camera Adapter Layer (CAL) is a very flexible subsystem that enables connection
to multiple cameras supporting MIPI CSI-2 over D-PHY serial interface,
a LVDS serial interface, and a traditional parallel interface.
It also includes an internal write DMA engine connected to VBUSM interface.
This document has detailed API description that user can use
to make use of the CAL driver.


User Interface
--------------

Driver Configuration
^^^^^^^^^^^^^^^^^^^^^

.. rubric::  **CAL Configuration Structure**
   :name: cal-configuration-structure

For details about individual fields of CAL library structure, see the
Doxygen help by opening
PDK_INSTALL_DIR\\packages\\ti\\drv\\cal\\docs\\doxygen\\html\\index.html.

APIs
^^^^^

The CAL driver API can be broadly divided into the following categories

- Complex IO configuration APIs
- Capture DMA configuration APIs.

In addition to above the CAL package also includes many sample
examples which show how to use the drivers in different ways. Many of
these sample examples use a common set of APIs which a user may find
useful to refer to for use in their final application.

API reference for application:

::

    #include <ti/drv/cal/include/cal_drv.h>

Application
------------

Examples
^^^^^^^^

+-----------------------+-----------------------+-------------------------+
| Name                  | | Description         | | Expected Results      |
+=======================+=======================+=========================+
| Capture Color Bar     | | Example             | | Example captures      |
| from UB954            |   demonstrating       |   required frames from  |
|                       |   Capture from UB954  |   UB954 and runs till   |
|                       |   This captures a     |   completion.           |
|                       |   Fixed pattern.      |   The Captured buffers  |
|                       |                       |   can be saved on PC    |
|                       |                       |   using the load raw    |
|                       |                       |   commands.             |
+-----------------------+-----------------------+-------------------------+
| Capture image from    | | Example demonstrates| | Example captures      |
| UB964 + SAT88 &       |   capturing the image |   required frames from  |
| OV10635 sensors.      |   from the sensor.    |   the 4 Ov10635 sensors |
|                       |                       |   and runs till         |
|                       |                       |   completion.           |
|                       |                       |   The captured buffers  |
|                       |                       |   can be saved on PC    |
|                       |                       |   using the load raw    |
|                       |                       |   commands.             |
+-----------------------+-----------------------+-------------------------+

Additional References
---------------------

+-----------------------------------+----------------------------------------+
| **Document**                      | **Location**                           |
+-----------------------------------+----------------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)\\packages\\ti    |
|                                   | \\drv\\cal\\docs\\doxygen\\html\\index.|
|                                   | html                                   |
+-----------------------------------+----------------------------------------+

Building CAL examples
---------------------

-  CAL examples and dependent libraries are built from the top level cal
   makefile
-  cd <pdk>/packages/ti/drv/cal
-  To build: make -s PDK_INSTALL_PATH=<pdk>/packages
-  To clean: make -s clean PDK_INSTALL_PATH=<pdk>/packages

CAL examples
------------

.. rubric::  *Description*
   :name: description

CAL examples uses the CSI2 Capture port present on the EVM which is
connected to CAL. The sensors are connected to the CSI2 capture port.
The examples supports capturing from either UB954 or
UB964 + SAT88 + 4 OV10635 sensors connected over the FPD link.
The Example captures the input frame data coming from CSI2 port and
writes back to the memory.

|

.. rubric::  **Running the Cal examples**
   :name: running-the-cal-examples

**Configuring Sensor**:

-  Make sure the UB954 Evm is connected to the CSI2 capture port and it is
   powered on before running the example for option 0.
-  Make sure the UB964 Evm is connected to the CSI2 capture port along with
   4 OV10635x cameras over the FPD link to the RIN0 to RIN3 ports and
   the EVM is powered on before running the example for option 1.

**CCS connection**:

-  Load the System firmware as specified in SCICLIENT documentation
-  Load the generated executable file in CCS
-  Run the application.
-  select the input based on the sensor connected.
-  Example will run till completion after capturing the frames.
-  Dump the buffers scripting console using the loadraw command specified.
-  Verify the output by viewing the captured image on PC.

