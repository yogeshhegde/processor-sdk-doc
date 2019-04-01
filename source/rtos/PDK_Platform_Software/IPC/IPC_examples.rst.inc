.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide/Examples

IPC RTOS Examples
---------------------------
.. rubric:: IPC Examples with ARM Host running TI-RTOS
   :name: IPC Examples with ARM Host running TI-RTOS

The IPC package includes examples for the use-case with both the Host and slave cores running TI-RTOS. 
They can be built from the Processor SDK RTOS package.

.. Note:: To Install RTOS Proc SDK, please follow the instructions in the `RTOS SDK Getting Started Guide <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/index_overview.html#processor-sdk-rtos-getting-started-guide>`_ 

In the RTOS Processor SDK, the ipc examples are located under <RTOS_SDK_INSTALL_DIR>/processor_sdk_rtos_<platform>_x_xx_xx_xx/ipc_<version>/examples/<platform>_bios_elf.

Once the RTOS Processor SDK is installed at the default location, the IPC examples can be built with the following commands:

 
1. Change to Processor SDK RTOS directory

        $ cd <RTOS_SDK_INSTALL_DIR>/processor_sdk_rtos_<platform>_x_xx_xx_xx 

2. Start the top level build:

        $ make ipc_examples
