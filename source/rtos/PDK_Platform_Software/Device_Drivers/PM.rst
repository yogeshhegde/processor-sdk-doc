.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_PM 

Overview
--------

Introduction
^^^^^^^^^^^^

The Power Management (PM) low level driver provide power and thermal
management capabilities for RTOS applications.

.. rubric:: **Supported Devices**
   :name: supported-devices

+------------+---------+--------+--------+----------+--------+------------------------------+
| **Device** | **A15** | **A8** | **A9** | **C66x** | **M4** | **Tested On**                |
+------------+---------+--------+--------+----------+--------+------------------------------+
| AM57xx     | X       |        |        | X        | X      | AM572x GP EVM, AM571x GP EVM |
+------------+---------+--------+--------+----------+--------+------------------------------+
| AM335x     |         | X      |        |          |        | AM335x GP EVM                |
+------------+---------+--------+--------+----------+--------+------------------------------+
| AM437x     |         |        | X      |          |        | AM437x GP EVM                |
+------------+---------+--------+--------+----------+--------+------------------------------+
| K2G        | X       |        |        | X        |        | K2G EVM                      |
+------------+---------+--------+--------+----------+--------+------------------------------+

User Interface
--------------

Driver Configuration
^^^^^^^^^^^^^^^^^^^^^

.. rubric:: **Board Specific Configuration**
   :name: board-specific-configuration

The following board-specific actions must take place prior to calling
any PM Power APIs:

-  A board-specific I2C implementation must be registered with the PM
   HAL layer
-  The PMIC Ops structure matching the executing device's PMIC must be
   registered with PM HAL layer
-  Device clock rates must be initialized through the PM LIB layer

For working examples of how to implement the listed items, see the
"main" functions of any PM example in
``[PDK_INSTALL_DIR]\packages\ti\drv\pm\examples``.

.. rubric:: **PM Configuration Structure**
   :name: pm-configuration-structure

The pm\src\pmrtos\prcm\PowerDevice.c file configures the PM driver
through the PowerDevice_config structure. This structure must be
provided to PM driver. The structure is a global defined within
PowerDevice.c and must be initialized prior to calling Power_init(). The
structure cannot be changed after calling Power_init(). For details
about individual fields of this structure, see the Doxygen help by
opening
``[PDK_INSTALL_DIR]\packages\ti\drv\pm\docs\doxygen\html\index.html``.

APIs
^^^^^

The following lists the main application interfaces; see the end of this
page for a link to the API Reference Manual with full details.

PM TI RTOS base API reference for applications can be found in below
file:

::

    #include <ti/drv/pm/Power.h>  /* Contains the core TI RTOS Power implementation APIs */

PM TI RTOS extended API reference for applications can be found in the
below file:

::

    #include <ti/drv/pm/PowerExtended.h>  /* Contains TI RTOS Power API extensions such as thermal management */

PM TI RTOS device-specific API reference for applications can be found
in the below file:

::

    #include <ti/drv/pm/PowerDevice.h>  /* Contains device-specific TI RTOS Power API definitions and structures */

| 

Application
------------

Examples
^^^^^^^^

+-----------------------+-----------------------+-----------------------+
| Name                  | | Description         || Expected Results     |
+=======================+=======================+=======================+
| PM RTOS Application   | | Example             || Application cycles   |
|                       |   demonstrating power |   the processor       |
|                       |   management use      |   running the         |
|                       |   cases. Reference    |   application through |
|                       |   example for         |   various power       |
|                       |   developers          |   states using the PM |
|                       |                       |   APIs. User observes |
|                       |                       |   the output printed  |
|                       |                       |   over the device's   |
|                       |                       |   UART connection.    |
|                       |                       || **Note:** The        |
|                       |                       |   example should be   |
|                       |                       |   run in "Free Run"   |
|                       |                       |   mode when loaded    |
|                       |                       |   and executed in     |
|                       |                       |   Code Composer       |
|                       |                       |   Studio in order to  |
|                       |                       |   prevent sleep API   |
|                       |                       |   testing             |
|                       |                       |   interruptions from  |
|                       |                       |   the JTAG.           |
|                       |                       |                       |
|                       |                       || Use the following    |
|                       |                       | steps to execute the  |
|                       |                       | application on the    |
|                       |                       | AM57xx's M4 and C66   |
|                       |                       | processors in Code    |
|                       |                       | Composer Studio:      |
|                       |                       |                       |
|                       |                       | -  Connect to         |
|                       |                       |    CortexA15_0        |
|                       |                       |    waiting until the  |
|                       |                       |    GEL file           |
|                       |                       |    initialization     |
|                       |                       |    completes          |
|                       |                       | -  Run the GEL:       |
|                       |                       |    Scripts-->AM572x   |
|                       |                       |    MULTICORE          |
|                       |                       |    Initialization-->A |
|                       |                       || M572x_MULTICORE_Enabl|
|                       |                       | eAllCores             |
|                       |                       | -  Connect to         |
|                       |                       |    M4_IPU1_C0 or the  |
|                       |                       |    C66xx_DSP1         |
|                       |                       | -  Load the PM RTOS   |
|                       |                       |    application's M4   |
|                       |                       |    or c66 executable  |
|                       |                       | -  Free run the       |
|                       |                       |    M4_IPU1_C0 or the  |
|                       |                       |    C66xx_DSP1         |
+-----------------------+-----------------------+-----------------------+
| PM RTOS Thermal       | | Example             || Application sets     |
| Application           |   demonstrating       |   high and low        |
|                       |   thermal management  |   thermal set points  |
|                       |   use case. Reference |   using the PM APIs.  |
|                       |   example for         |   The set points are  |
|                       |   developers          |   triggered by        |
|                       |                       |   internally heating  |
|                       |                       |   up the processor.   |
|                       |                       |   User observes the   |
|                       |                       |   output printed over |
|                       |                       |   the device's UART   |
|                       |                       |   connection.         |
|                       |                       |                       |
|                       |                       || Use the following    |
|                       |                       | steps to execute the  |
|                       |                       | application on the    |
|                       |                       | AM57xx's M4 and C66   |
|                       |                       | processors in Code    |
|                       |                       | Composer Studio:      |
|                       |                       |                       |
|                       |                       | -  Connect to         |
|                       |                       |    CortexA15_0        |
|                       |                       |    waiting until the  |
|                       |                       |    GEL file           |
|                       |                       |    initialization     |
|                       |                       |    completes          |
|                       |                       | -  Run the GEL:       |
|                       |                       |    Scripts-->AM572x   |
|                       |                       |    MULTICORE          |
|                       |                       |    Initialization-->A |
|                       |                       | M572x_MULTICORE_Enabl |
|                       |                       | eAllCores             |
|                       |                       | -  Connect to         |
|                       |                       |    M4_IPU1_C0 or the  |
|                       |                       |    C66xx_DSP1         |
|                       |                       | -  Load the PM RTOS   |
|                       |                       |    Thermal            |
|                       |                       |    application's M4   |
|                       |                       |    or c66 executable  |
|                       |                       | -  Run the M4_IPU1_C0 |
|                       |                       |    or the C66xx_DSP1  |
+-----------------------+-----------------------+-----------------------+
| PM Measurement        | | Menu-based          || Application allows   |
| Application           |   application         |   the user to control |
|                       |   allowing selection  |   the processor's OPP |
|                       |   of processor OPPs   |   settings via the PM |
|                       |   and benchmark       |   driver. The         |
|                       |   tests.              |   application also    |
|                       |                       |   allows the user to  |
|                       |                       |   select execution of |
|                       |                       |   the Dhrystone       |
|                       |                       |   benchmark for       |
|                       |                       |   performance and     |
|                       |                       |   power profiling     |
|                       |                       |   under different OPP |
|                       |                       |   settings. The       |
|                       |                       |   application's menu  |
|                       |                       |   is printed over the |
|                       |                       |   device's UART       |
|                       |                       |   connection.         |
|                       |                       | | **Note:** The       |
|                       |                       |   measurement         |
|                       |                       |   application is only |
|                       |                       |   supported on the    |
|                       |                       |   AM335x device at    |
|                       |                       |   the moment.         |
+-----------------------+-----------------------+-----------------------+

Additional References
---------------------

+-----------------------------------+-----------------------------------------+
| **Document**                      | **Location**                            |
+-----------------------------------+-----------------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)\\packages\\ti     |
|                                   | \\drv\\pm\\docs\\doxygen\\html\\index.h |
|                                   | tml                                     |
+-----------------------------------+-----------------------------------------+
| Release Notes                     | $(TI_PDK_INSTALL_DIR)\\packages\\ti     |
|                                   | \\drv\\pm\\docs\\ReleaseNotes_PM_LLD.   |
|                                   | pdf                                     |
+-----------------------------------+-----------------------------------------+

| 

