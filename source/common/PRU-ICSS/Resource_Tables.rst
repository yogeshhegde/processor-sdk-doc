.. _pru_resource_tables:

Resource Tables
===============

When are resource tables used?
------------------------------

PRU cores must be initialized by an outside source. There are 3 different ways
to initialize a PRU and load the PRU firmware:

#. Code Composer Studio (CCS)

#. A processor core running Linux

#. A processor core running RTOS or bare metal (i.e., NORTOS)

PRU resource tables are only used if the PRU firmware is loaded by a processor
core running Linux. If the processor core is running Linux kernel 5.4 or
earlier, then resource tables are used differently than if the processor core is
running Linux kernel 5.10 or later.

Examples of different resource tables can be found in the PRU Software Support
Package (PSSP). The PSSP can be found:

 * In the Processor SDK Linux under example-applications/pru-icss-x.x.x

 * At the `PSSP git repo <https://git.ti.com/cgit/pru-software-support-package/pru-software-support-package>`__


Linux kernel 5.10 or later
--------------------------

If the PRU firmware is loaded by a core running Linux kernel 5.10 or later,
then resource tables are only used if the PRU project uses RPMsg to communicate
with the Linux core.

For Linux kernel 5.10 or later, INTC configuration is passed to the Linux
RemoteProc driver in a separate INTC map file. For more information on the INTC
map file, reference :ref:`pru_intc_configuration`.

.. note::

   PSSP projects for Linux 5.4 or earlier have different resource tables than
   PSSP projects for Linux 5.10 or later. Check the tag on your PSSP to make
   sure you are using PSSP v6.0.0 or later.

Does the PRU project use RPMsg?

 * Yes --> A resource table is required. Refer to the example resource table at
   **<PSSP_PATH>/examples/<processor>/xxx_RPMsg_Echo_InterruptX**

 * No --> If the PRU project does not use RPMsg, then a resource table is not
   required. Do not include a resource table in the PRU project. If there are
   references to a resource table in the linker command file and the firmware,
   then remove those references. A sample project with no resource table is at
   **<PSSP_PATH>/examples/<processor>/xxx_Halt**


Linux kernel 5.4 or earlier
---------------------------

Resource tables are required if the PRU firmware is loaded by a core
running Linux kernel 5.4 or earlier.

.. note::

   PSSP projects for Linux 5.4 or earlier have different resource tables than
   PSSP projects for Linux 5.10 or later. Check the tag on your PSSP to make
   sure you are using PSSP v5.9.0 or earlier.

Does the PRU project use RPMsg?

 * Yes --> Refer to the example resource table at
   **<PSSP_PATH>/examples/<processor>/xxx_RPMsg_Echo_InterruptX**

 * No -->

   * Does the PRU project configure the INTC?

     * Yes --> Refer to the AM335x example at
       **<PSSP_PATH>/examples/am335x/PRU_Direct_Connect0**

     * No --> If the project does not use RPMsg, or configure the INTC, then
       use an empty resource table. Refer to the example resource table at
       **<PSSP_PATH>/examples/<processor>/xxx_Halt**
