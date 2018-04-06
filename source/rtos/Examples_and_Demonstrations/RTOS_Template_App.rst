.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Template_App 

Overview
========

The RTOS template application is intended for customers to use as a
starting point during software development using Processor SDK RTOS
software. The template application can be quickly brought up by
importing the included CCS project into CCS development environment. The
application currently includes the typical low level drivers (UART,
GPIO, I2C), OSAL layer, and Board Library. For additional details refer
to the README.txt file in the installed package.

Supported platforms
===================

-  evmAM572x
-  evmAM335x

Requirements
============

Following are required to run the application:

Hardware

-  TI EVM (see list above)
-  Serial UART cable (provided in EVM kit)

Software

-  Processor-SDK RTOS
-  Code Composer Studio

Components Used
===============

RTOS Components:

-  SYS/BIOS
-  XDCTools
-  Processor SDK RTOS PDK: Drivers, OSAL, etc.

Software Design
===============

The Template Application is designed to provide a foundation with
clean separation of application specific sub-module. This allows users
the ability to focus on application specific code and quickly get it
to run.
This is achieved by separating "main" and "app" sub modules in
different files.

The source files are organized as follows:

::

              └── template_app
                  ├── main.c --> Main file including startup and init code
                  ├── main.cfg --> Main BIOS config file
                  ├── app.c  --> Application tasks are here
                  ├── app.h  --> Application header file
                  ├── app.cfg --> Application specific config file
                  ├── app.defs --> Definitions (Currently empty)
                  ├── rtos_template_app_<SOC>_<core>_<board>.projectspec --> Project spec file

In general to write a new application, **app.c** and **app.h** can be
modified, recompiled, and run.

How to Build the Template Application
=====================================

Please follow below step by step procedure to build the application.

#. Processor SDK RTOS and Code Composer Studio.
#. Install Processor SDK RTOS ( AM57x, AM335x) respectively, in a
   location where CCS expects: (by default $HOME/ti or c:/ti) Refer
   :ref:`Processor SDK RTOS Getting Started Guide <Processor-SDK-RTOS-Getting-Started-Guide-label>` 
   for details.
#. Open CCS:
#. Click Project-->Import CCS Projects and select rtos_template_app
   under directory :
   <Processor_sdk_rtos_<platform>_<version>/demos/rtos_template_app/
   (NOTE: This will create project under current workspace and also copy
   relevant files for the project.)
#. Build the application . ( By right clicking on imported project and
   clicking "Build project") (NOTE: This will create executable binary
   under
   rtos_template_app_<platform>/Debug/rtos_template_app_<platform>_<core>.out)

How to Run the Template Application
===================================

You will need the following:

#. Install Code Composer Studio to load and run the Template
   Application. Refer to :ref:`Processor SDK RTOS Getting Started
   Guide <Processor-SDK-RTOS-Getting-Started-Guide-label>` for
   installing CCS.
#. evmAM572x or evm AM335x board
#. JTAG Emulator

To load and run Template Application:

#. Connect the computer to the JTAG port on the board using the JTAG
   emulator.
#. Power on evm574x or evm335x board. Ensure that no boot mode is
   entered (do not have SD card loaded or QSPI flashed)
#. Open up a serial terminal for UART communication (Refer to :ref:`Processor
   SDK RTOS Getting Started Guide <Processor-SDK-RTOS-Getting-Started-Guide-label>`, setup
   EVM hardware)
#. Open CCS and launch target config file for the EVM (Refer to
   `Processor SDK RTOS Setup
   CCS <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_Setup_CCS>`__ for setting up CCS)
#. Connect to A15_0 core for AM572x ( A8 core for AM335x).
#. Load executable by clicking("Run --> Load --> Load Program.). Click
   on Browse Project and select outfile under:
   rtos_template_app_<platform><core>/Debug/rtos_template_app<platform>_<core>.out
#. Run application by clicking the Run icon. ( Or Click Run --> Resume)

Now application will run and print progress through the UART.

-  Press enter to get UART prompt.

uart_task :Enter a word or Esc to quit >

-  Enter any word following by <CR>

The application will print back the entered word

-  Enter [ESC-<CR>]

The application will exit.

Terminal Screenshot
===================

::

    Board Init complete
    Uart Init complete
    I2C Init complete
    Gpio Init complete
    MCSPI Init complete
    ======== Peripheral Initialization complete ========
       
    ======== Starting to create application tasks ========
       
        gpio_toggle_led_task task created.
        uart_task task created.
        spi_test_task task created.
        i2c_eeprom_read_and_display_task task created.
        ======== Application tasks created successfully ========
       
        gpio_toggle_led task started
        uart_task task started uart_task :Enter a word or Esc to quit >
        i2c_eeprom_read_and_display task started
        spi_test task started
        Board Name read: AM572PM_
        Board version read: A.3A
        spi_test task ended
        i2c_eeprom_read_and_display task ended
        uart_task :Enter a word or Esc to quit >
        uart_task :Enter a word or Esc to quit >testing
        Data received is:testing
        uart_task :Enter a word or Esc to quit >command
        Data received is:command
        uart_task :Enter a word or Esc to quit >^[
        uart_task task ended
        Template app ended

Porting to Custom Board
=======================

| The Template Application can be easily modified to run on a custom
  board. The main change is to link in a new Board Library. Modification
  for customer board can be achieved by just removing ti.board library
  and PATH from the project and replacing with customer specific board
  library and PATH under the linker Build Options under CCS.
| e.g. Currently the library linked for AM572x is specified in the
  .projectspec file as follows.

::

           linkerBuildOptions=
           " -L${TI_PDK_INSTALL_DIR}/packages/ti/board/lib/evmAM572x/a15/release/
             -l:ti.board.aa15fg

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
Currently for AM572x there is also dependency on the
GPIO_evmAM572x_board.c & GPIO_board.h. These files can be modified to
customize for the customer board.

.. raw:: html

   </div>

.. raw:: html

