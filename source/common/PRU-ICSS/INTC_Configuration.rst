.. _pru_intc_configuration:

INTC Configuration
==================

The Linux RemoteProc driver that initializes the PRU cores and loads the PRU
firmware can be used to initialize the PRU interrupt controller (INTC). However,
if the processor core is running Linux kernel 5.4 or earlier, then RemoteProc
INTC configuration works differently than if the processor core is running
Linux kernel 5.10 or later.

Examples of different INTC configurations can be found in the PRU Software
Support Package (PSSP). The PSSP can be found:

 * In the Processor SDK Linux under example-applications/pru-icss-x.x.x

 * At the `PSSP git repo <https://git.ti.com/cgit/pru-software-support-package/pru-software-support-package>`__


Linux kernel 5.10 or later
--------------------------

If the PRU firmware is loaded by a core running Linux kernel 5.10 or later,
then the INTC configuration is passed to the Linux RemoteProc driver in an INTC
map file that is separate from the PRU resource table. If the PRU project
does not configure the INTC, then an INTC map file is not required.

.. note::

   PSSP projects for Linux 5.4 or earlier have different resource tables than
   PSSP projects for Linux 5.10 or later. Check the tag on your PSSP to make
   sure you are using PSSP v6.0.0 or later.

.. note::

   The INTC map file should only define interrupts going to ICSS / ICSSG cores.
   If a PRU system event goes to the ARM Linux host, then that interrupt should
   be defined in the Linux device tree node of the client PRU driver, in the
   "interrupts" property.

Refer to the INTC map file in this project as a template:
**<PSSP_PATH>/examples/<processor>/PRU_Direct_Connect0/intc_map_0.h**

Make sure to follow the example project by:

 * Including the INTC map file in the main.c file

 * Adding the INTC map structure to the linker command file. Reference
   **<PSSP_PATH>/examples/<processor>/PRU_Direct_Connect0/xxx_PRU0_intc.cmd**


Linux kernel 5.4 or earlier
---------------------------

INTC configuration is handed within the PRU project resource tables. The
resource tables should include INTC mapping information for all PRU system
events, regardless of whether the interrupt goes to the ICSS /
ICSSG cores, or to the ARM Linux host. For more
information on PRU resource tables, reference :ref:`pru_resource_tables`.

.. note::

   PSSP projects for Linux 5.4 or earlier have different resource tables than
   PSSP projects for Linux 5.10 or later. Check the tag on your PSSP to make
   sure you are using PSSP v5.9.0 or earlier.

Does the PRU project use RPMsg?

 * Yes --> Refer to the INTC configuration in the example resource table at
   **<PSSP_PATH>/examples/<processor>/xxx_RPMsg_Echo_InterruptX**

 * No --> Refer to the INTC configuration in the example resource table at
   **<PSSP_PATH>/examples/am335x/PRU_Direct_Connect0**
