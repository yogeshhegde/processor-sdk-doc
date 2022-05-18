.. _pru_getting_started_labs_writing_c_code:

Writing C Code
^^^^^^^^^^^^^^

If the PRU project was created in CCS, follow section
:ref:`pru_getting_started_labs_writing_c_code_in_ccs`.

If the PRU project was created in the Linux terminal, follow section
:ref:`pru_getting_started_labs_writing_c_code_in_linux`.


.. _pru_getting_started_labs_writing_c_code_in_ccs:

Writing C Code in CCS
"""""""""""""""""""""

* :ref:`add_the_main_c_file_ccs`
* :ref:`add_the_linker_command_file_ccs`
* :ref:`include_the_header_files_ccs`
* :ref:`configure_the_pru_intc_ccs`
* :ref:`add_the_intc_config_file_ccs`
* :ref:`add_the_resource_table_ccs`
* :ref:`add_the_resource_table_linux_5_4_ccs`
* :ref:`add_the_resource_table_linux_5_10_ccs`
* :ref:`write_the_pru_firmware_ccs`

Start with the empty PRU project created in
:ref:`pru_getting_started_labs_creating_ccs_project`.


.. _add_the_main_c_file_ccs:

.. rubric:: Add the main C file

The PRU project needs a .c file for the firmware C code. Use "Add Files"
to copy the main.c file from <PSSP_PATH>/labs/Getting_Started_Labs/c_code/.

#. Select **Project->Add Files...**

.. note::

   If there are multiple projects open in CCS, make sure to select the correct
   project in the Project Explorer view before adding the file.

.. note::

   Many steps that involve **Project->something** can also be done by clicking
   on the Project Explorer view. For example, "Add Files" can also be accessed
   by right clicking on the project top-level folder and selecting
   **Add Files**. To keep things simple, later steps will only document
   **Project->Add Files...**. Either process can be used.
   
#. Navigate to **<PSSP_PATH>/labs/Getting_Started_Labs/c_code** folder. Select
   **main.c**. Select **open**.
   
#. Select **Copy files** and click **OK**.

#. Go to the Project Explorer view and double click on main.c. The text in the
   file should match the text in
   <PSSP_PATH>/labs/Getting_Started_Labs/c_code/main.c


.. _add_the_linker_command_file_ccs:

.. rubric:: Add the linker command file

The linker combines all of the PRU code into a single executable object file
(i.e., the linker creates the binary file that is loaded into the PRU). The
linker command file is used to tell the linker where to place code, how to
resolve addresses, and more.

#. If a linker command file was added to the project folder automatically,
   delete that linker command file. The automatically generated linker files
   are not kept up-to-date like the linker files in the PSSP.
   
   * Example: AM335x. Look for AM335x_PRU.cmd and delete it.

#. Delete the include link that points to automatically generated linker files:

   #. Select **Project->Properties**.
   #. Select **Build->PRU Compiler->Include Options**.
   #. In the box marked **"Add dir to #include search path"**, select
      **${CCS_BASE_ROOT}/pru/include**
   #. Delete the include path by clicking the **file icon with a red X.**
   #. Save the changes by clicking **Apply and close**.

.. TODO: add image with the file icon with an X highlighted

#. Select **Project->Add Files...**.

#. Navigate to the **<PSSP_PATH>/labs/Getting_Started_Labs/linker_cmd** folder.
   Select the linker command file that matches the project's PRU core. Copy
   the file into the project.

   * Example: AM335x PRU: Select AM335x_PRU.cmd

   * Example: AM62x PRU0: Select AM62x_PRU0.cmd

   * Example: AM64x TX_PRU1: Select AM64x_TX_PRU1.cmd

.. note::

   AM335x, AM57x: Use the same linker command file for all PRU cores.

   AM437x: Use AM437x_PRU_SS0.cmd for PRU cores in PRU-ICSS0. Use
   AM437x_PRU_SS1.cmd for PRU cores in PRU-ICSS1.

   AM62x: Use PRU0.cmd for PRU0, use PRU1.cmd for PRU1.

   AM64x, AM65x: Use PRU0.cmd for PRU0 in any PRU_ICSSG. Use PRU1.cmd for PRU1
   in any PRU_ICSSG. Similarly, use RTU0.cmd for any RTU0, RTU1.cmd for any
   RTU1, TX_PRU0.cmd for any TX_PRU0, and TX_PRU1.cmd for any TX_PRU1.


.. _include_the_header_files_ccs:

.. rubric:: Include the header files (optional)


TI provides header files for the PRU. Header files simplify development by
providing easy names for registers and register bits. This lab will show how
to include the header files, even though the header files are not actually
used in the Getting Started Labs. The header files are used in projects in
<PSSP_PATH>/examples and <PSSP_PATH>/labs/Hands_on_Labs.


#. Add the include path for the PRU header files so that the compiler can
   find the header files.

   #. Select **Project->Properties**.

   #. Select **Build->PRU Compiler->Include Options**.

   #. In the box marked **"Add dir to #include search path"**, click the
      **file icon with a green +**.

   #. Specify the **directory to the include file**. Select **Apply and close**.

      * Example: AM335x header files are at **<PSSP_PATH>/include/am335x**

#. Include any header files used by the project in the main.c file.

   * Example: AM335x using header file pru_intc.h

	::

	   #include <pru_intc.h>


.. _configure_the_pru_intc_ccs:

.. rubric:: Configure the PRU INTC (optional)

The PRU Interrupt Controller (INTC) can be configured by the core that loads the
PRU, or by the PRU itself.

The PRU Getting Started Labs do not configure the INTC. However,
these steps are provided as a resource for customers who will configure the INTC
in their projects.

Does the PRU project use interrupts?

 * Yes --> Continue reading.

 * No --> INTC configuration is not needed. Jump to section
   :ref:`add_the_resource_table_ccs`

Will the PRU project be loaded by a core running Linux kernel 5.10 or later?

 * Yes -->

   * Should the INTC be configured by the Linux RemoteProc driver?

     * Yes (e.g., if using RPMsg. If unsure, pick this option) --> Jump to section
       :ref:`add_the_intc_config_file_ccs`

     * No --> Continue reading.

Will the PRU project be loaded by a core running Linux kernel 5.4 or earlier?

 * Yes -->

   * Should the INTC be configured by the Linux RemoteProc driver?

     * Yes (e.g., if using RPMsg. If unsure, pick this option) --> INTC is
       configured in the resource table. Jump to section
       :ref:`add_the_resource_table_linux_5_4_ccs`

     * No --> Continue reading.

Will the PRU project be loaded by a core running an OS from the MCU+ SDK?

 * Yes -->

   * Should the INTC be configured by the MCU+ core?

     * Yes --> Reference the documentation in the MCU+ SDK docs, section
       "SOC Peripheral Drivers" > "PRUICSS". Continue the PRU Getting Started
       Labs by jumping to :ref:`add_the_resource_table_ccs`.

     * No --> Continue reading.

.. TODO: Add more details to how to configure the INTC from MCU+?

If you got to this step, then the project uses interrupts, and the PRU INTC
will be configured by the PRU firmware instead of by another core. Be **very**
careful if deciding to configure the PRU INTC from two different cores! There
are no settings to prevent one core from overwriting the other core's INTC
settings.

.. TODO: provide additional details later, since Lab 2 is pretty confusing
   as it includes an INTC config file, but still sets the INTC settings
   manually. Is that an addition I made on accident later on?

For an example of configuring the PRU INTC from
PRU firmware, reference the PRU Hands-on Labs :ref:`pru_hands_on_labs_lab_2`,
section "Build the PRU Firmware". Note that different processors will have
different names for the INTC registers.

Continue the PRU Getting Started Labs by jumping to
:ref:`add_the_resource_table_ccs`.


.. _add_the_intc_config_file_ccs:

.. rubric:: Add the INTC configuration file (optional)

Starting in Linux kernel 5.10, the Linux RemoteProc driver can initialize the
PRU interrupt controller (PRU INTC) using a specific INTC map structure.

Add an INTC configuration file if:

 * the PRU project will be loaded by Linux core running Linux kernel 5.10
   or later, AND

 * The project requires INTC configuration

Reference
<PSSP_PATH>/examples/<processor>/PRU_Direct_Connect0 for an example
project that uses an INTC configuration file.

#. Add the INTC map file to the project. Use this file as a template:
   **<PSSP_PATH>/examples/<processor>/PRU_Direct_Connect0/intc_map_0.h**
   
#. Include the INTC map file in the main.c file.

   * Example: AM64x using INTC map file "intc_map_0.h"

	::
	
	   #include "intc_map_0.h"

#. Add the INTC map structure to the linker command file. Reference
   **<PSSP_PATH>/examples/<processor>/PRU_Direct_Connect0/xxx_PRU0_intc.cmd**

   ::

      /* Specify the sections allocation into memory */
      SECTIONS {

        ...

        .pru_irq_map (COPY) :
        {
                *(.pru_irq_map)
        }
      }

#. Write the INTC mapping settings following the comments in the template INTC
   map file.


.. _add_the_resource_table_ccs:

.. rubric:: Add the resource table (optional)

Will the PRU project be loaded by a core running Linux kernel 5.4 or earlier?

* Yes --> Jump to section :ref:`add_the_resource_table_linux_5_4_ccs`

* No --> Continue reading.

Will the PRU project be loaded by a core running Linux kernel 5.10 or later?

* Yes --> Jump to section :ref:`add_the_resource_table_linux_5_10_ccs`

* No --> Resource tables are not used. Continue reading.

If you got to this step, then the project does not need a resource table.
Check which version of PSSP is used:

* v6.0.0 or later: No additional steps are needed. Jump to section
  :ref:`write_the_pru_firmware_ccs`

* v5.9.0 or earlier: An empty resource table is included by default in these
  versions of the PSSP.

  #. Go to the main.c file

  #. Comment out the resource table include:

     ::
   
         /* #include "resource_table_empty.h" */

  #. Jump to section :ref:`write_the_pru_firmware_ccs`


.. _add_the_resource_table_linux_5_4_ccs:

.. rubric:: Add the resource table with Linux 5.4 or earlier

A resource table is required if the PRU project is loaded by a Linux core
running Linux kernel 5.4 or earlier.

.. note::

   PSSP projects for Linux 5.4 or earlier have different resource tables than
   PSSP projects for Linux 5.10 or later. Check the tag on your PSSP to make
   sure you are using PSSP v5.9.0 or earlier.

Does the PRU project use RPMsg?

* Yes --> Refer to
  **<PSSP_PATH>/examples/<processor>/xxx_RPMsg_Echo_InterruptX**

* No -->

  * Does the PRU project configure the INTC?

    * Yes --> Refer to the AM335x example at
      **<PSSP_PATH>/examples/am335x/PRU_Direct_Connect0**

    * No --> If the project does not use RPMsg, or configure the INTC, then
      use an empty resource table. The getting started labs include
      empty resource tables.

#. Add the resource table file to the project.

   #. Select **Project->Add Files...**

   #. Navigate to **<PSSP_PATH>/Getting_Started_Labs/c_code** folder. Select
      **resource_table_empty.h**.

   #. Select **Copy files** and click **OK**.

#. Check that the main.c file includes the resource table file:

   ::

      #include "resource_table_empty.h"

#. Check that the linker command file includes a section for the resource
   table.
   
   * Example: AM335x PRU0

     ::

        .resource_table > PRU_DMEM_0_1, PAGE 1

   * Example: AM62x PRU0

     ::

        /* Ensure resource_table section is aligned on 8-byte address for
           ARMv8 (64-bit) kernel */
        .resource_table : ALIGN (8) >  PRU0_DMEM_0, PAGE 1

   * Example: AM64x RTU1

     ::

        /* Ensure resource_table section is aligned on 8-byte address for
           ARMv8 (64-bit) kernel */
        .resource_table : ALIGN (8) >  RTU1_DMEM_1, PAGE 1

#. The resource table includes rsc_types.h. Add the appropriate include path:

   #. Select **Project->Properties**.

   #. Select **Build->PRU Compiler->Include Options**.

   #. In the box marked **"Add dir to #include search path"**, click the
      **file icon with a green +**.

   #. Specify the directory **<PSSP_PATH>/include**.

#. Modify the resource table as needed. The empty resource table that is used
   in the PRU Getting Started Guide does not need to be modified.

Jump to section :ref:`write_the_pru_firmware_ccs`


.. _add_the_resource_table_linux_5_10_ccs:

.. rubric:: Add the resource table with Linux 5.10 or later (optional)

This section documents the case that the PRU project is loaded by a Linux core
running Linux kernel 5.10 or later.

.. note::

   PSSP projects for Linux 5.4 or earlier have different resource tables than
   PSSP projects for Linux 5.10 or later. Check the tag on your PSSP to make
   sure you are using PSSP v6.0.0 or later.

Will the PRU project use RPMsg to communicate with the Linux core?

* Yes --> A resource table is required. continue reading.

* No --> If the PRU project does not use RPMsg, then a resource table is not
  required. Jump to section :ref:`write_the_pru_firmware_ccs`


The PRU Getting Started Labs do not use RPMsg, so they do not have a resource
table. These steps are provided as a resource for customers who will use a
resource table in their projects. Reference
**<PSSP_PATH>/examples/<processor>/xxx_RPMsg_EchoX** for an example
project that uses a resource table.

.. note::

   If the PRU project for Linux 5.10 or later uses RPMsg, then the project
   requires both a resource table and an INTC configuration file. Reference
   section :ref:`add_the_intc_config_file_ccs` for steps on adding the INTC
   configuration file.


#. Add the resource table file to the project.

   #. Select **Project->Add Files...**
   
   #. Navigate to **<PSSP_PATH>/examples/<processor>/xxx_RPMsg_Echo_InterruptX** folder.
      Select **resource_table.h**.

   #. Select **Copy files** and click **OK**.

#. Include the resource table in the main.c file:

   ::

      #include "resource_table.h"

#. Add the resource table to the linker command file. Reference
   **<PSSP_PATH>/examples/<processor>/xxx_RPMsg_Echo_InterruptX/xxx_PRU0_intc_rscTbl.cmd**

   * Example: AM335x PRU0

     ::

        .resource_table > PRU_DMEM_0_1, PAGE 1

   * Example: AM62x PRU0

     ::

        /* Ensure resource_table section is aligned on 8-byte address for
           ARMv8 (64-bit) kernel */
        .resource_table : ALIGN (8) >  PRU0_DMEM_0, PAGE 1

   * Example: AM64x RTU1

     ::

        /* Ensure resource_table section is aligned on 8-byte address for
           ARMv8 (64-bit) kernel */
        .resource_table : ALIGN (8) >  RTU1_DMEM_1, PAGE 1 

#. The resource table includes rsc_types.h. Add the appropriate include path:

   #. Select **Project->Properties**.

   #. Select **Build->PRU Compiler->Include Options**.

   #. In the box marked **"Add dir to #include search path"**, click the
      **file icon with a green +**.

   #. Specify the directory **<PSSP_PATH>/include**.


.. _write_the_pru_firmware_ccs:

.. rubric:: Write the PRU firmware

Look for the TODO comments in the main.c code for guidance on completing the
example code. The complete solution for the main.c code can be found in
<PSSP_PATH>/labs/Getting_Started_Labs/c_code/solution.

Ready to compile the PRU firmware? Go to :ref:`pru_getting_started_labs_lab_3`.


.. _pru_getting_started_labs_writing_c_code_in_linux:

Writing C Code in Linux
"""""""""""""""""""""""

* :ref:`add_the_main_c_file_linux`
* :ref:`add_the_linker_command_file_linux`
* :ref:`include_the_header_files_linux`
* :ref:`configure_the_pru_intc_linux`
* :ref:`add_the_intc_config_file_linux`
* :ref:`add_the_resource_table_linux`
* :ref:`add_the_resource_table_linux_5_4_linux`
* :ref:`add_the_resource_table_linux_5_10_linux`
* :ref:`write_the_pru_firmware_linux`

Start with the basic PRU project created in
:ref:`pru_getting_started_labs_creating_linux_project`. Start in the same
directory as in Lab 1: **<PSSP_PATH>/examples/<processor>**


.. _add_the_main_c_file_linux:

.. rubric:: Add the main C file

The PRU project needs a .c file for the firmware C code.

#. The basic PRU project should already have a main.c file. Delete the existing
   main.c file.
   
   * Example: AM335x with PRU0:

     ::

        $ cd PRU_Add
        $ ls
        $ rm main.c

   * Example: AM64x with RTU1:

     ::

        $ cd RTU_Add
        $ ls
        $ rm main.c

#. Copy the main.c file from <PSSP_PATH>/labs/Getting_Started_Labs/c_code/ to
   the current directory.

   ::

      $ cp ../../../labs/Getting_Started_Labs/c_code/main.c .

#. The main.c file in the current directory should match the main.c file in
   labs/Getting_Started_Labs/c_code/.

   * Example: AM335x with PRU0, based on PRU_Halt:
   
     ::

        $ diff ../../../labs/Getting_Started_Labs/c_code/main.c main.c
        # there should be no output

        $ diff ../PRU_Halt/main.c main.c
        # main.c in PRU_Halt should be different


.. _add_the_linker_command_file_linux:

.. rubric:: Add the linker command file

The linker combines all of the PRU code into a single executable object file
(i.e., the linker creates the binary file that is loaded into the PRU). The
linker command file is used to tell the linker where to place code, how to
resolve addresses, and more.

#. The basic PRU project should already have a linker command file. Make sure
   that the linker command file matches the project's PRU core.


   * Example: AM335x PRU: Select AM335x_PRU.cmd

   * Example: AM62x PRU0: Select AM62x_PRU0.cmd

   * Example: AM64x TX_PRU1: Select AM64x_TX_PRU1.cmd

   .. note::

      AM335x, AM57x: Use the same linker command file for all PRU cores.

      AM437x: Use AM437x_PRU_SS0.cmd for PRU cores in PRU-ICSS0. Use
      AM437x_PRU_SS1.cmd for PRU cores in PRU-ICSS1.

      AM62x: Use PRU0.cmd for PRU0, use PRU1.cmd for PRU1.

      AM64x, AM65x: Use PRU0.cmd for PRU0 in any PRU_ICSSG. Use PRU1.cmd for PRU1
      in any PRU_ICSSG. Similarly, use RTU0.cmd for any RTU0, RTU1.cmd for any
      RTU1, TX_PRU0.cmd for any TX_PRU0, and TX_PRU1.cmd for any TX_PRU1.

#. Make sure that the project Makefile **LINKER_COMMAND_FILE** matches the
   linker command file used:
   
   #. Open the Makefile in a text editor.

   #. If **LINKER_COMMAND_FILE** does not match the project linker command
      file, update it.

      * Example: AM335x using AM335x_PRU.cmd:

        ::

           LINKER_COMMAND_FILE=./AM335x_PRU.cmd

      * Example: AM62x using AM62x_PRU0.cmd:

        ::

           LINKER_COMMAND_FILE=./AM62x_PRU0.cmd

      * Example: AM64x TX_PRU0 using AM64x_TX_PRU0.cmd:

        ::

           LINKER_COMMAND_FILE ?= ./AM64x_TX_PRU0.cmd

   #. If the Makefile required changes, save the changes. Close the Makefile.


.. _include_the_header_files_linux:

.. rubric:: Include the header files (optional)

TI provides header files for the PRU. Header files simplify development by
providing easy names for registers and register bits. This lab will show how
to include the header files, even though the header files are not actually
used in the Getting Started Labs. The header files are used in projects in
<PSSP_PATH>/examples and <PSSP_PATH>/labs/Hands_on_Labs.

#. Add the include path for the PRU header files so that the compiler can
   find the header files.

   #. Open the Makefile in a text editor.

   #. Ensure that the project Makefile **INCLUDE** points to the
      **directory to the include file**.

       * Example: AM335x header files are at **<PSSP_PATH>/include/am335x**:

         ::

            INCLUDE=--include_path=../../../include --include_path=../../../include/am335x

   #. If the Makefile required changes, save the changes. Close the Makefile.

#. Include any header files used by the project in the main.c file.

   #. Open the main.c file in a text editor.

      * Example: AM335x using header file pru_intc.h

	    ::

	       #include <pru_intc.h>

   #. If the main.c file required changes, save the changes. Close the
      main.c file.


.. _configure_the_pru_intc_linux:

.. rubric:: Configure the PRU INTC (optional)

The PRU Interrupt Controller (INTC) can be configured by the core that loads the
PRU, or by the PRU itself.

The PRU Getting Started Labs do not configure the INTC. However,
these steps are provided as a resource for customers who will configure the INTC
in their projects.

Does the PRU project use interrupts?

 * Yes --> Continue reading.

 * No --> INTC configuration is not needed. Jump to section
   :ref:`add_the_resource_table_linux`

Will the PRU project be loaded by a core running Linux kernel 5.10 or later?

 * Yes -->

   * Should the INTC be configured by the Linux RemoteProc driver?

     * Yes (e.g., if using RPMsg. If unsure, pick this option) --> Jump to section
       :ref:`add_the_intc_config_file_linux`

     * No --> Continue reading.

Will the PRU project be loaded by a core running Linux kernel 5.4 or earlier?

 * Yes -->

   * Should the INTC be configured by the Linux RemoteProc driver?

     * Yes (e.g., if using RPMsg. If unsure, pick this option) --> INTC is
       configured in the resource table. Jump to section
       :ref:`add_the_resource_table_linux_5_4_linux`

     * No --> Continue reading.

Will the PRU project be loaded by a core running an OS from the MCU+ SDK?

 * Yes -->

   * Should the INTC be configured by the MCU+ core?

     * Yes --> Reference the documentation in the MCU+ SDK docs, section
       "SOC Peripheral Drivers" > "PRUICSS". Continue the PRU Getting Started
       Labs by jumping to :ref:`add_the_resource_table_linux`.

     * No --> Continue reading.

.. TODO: Add more details to how to configure the INTC from MCU+?

If you got to this step, then the project uses interrupts, and the PRU INTC
will be configured by the PRU firmware instead of by another core. Be **very**
careful if deciding to configure the PRU INTC from two different cores! There
are no settings to prevent one core from overwriting the other core's INTC
settings.

.. TODO: provide additional details later, since Lab 2 is pretty confusing
   as it includes an INTC config file, but still sets the INTC settings
   manually. Is that an addition I made on accident later on?

For an example of configuring the PRU INTC from
PRU firmware, reference the PRU Hands-on Labs :ref:`pru_hands_on_labs_lab_2`,
section "Build the PRU Firmware". Note that different processors will have
different names for the INTC registers.

Continue the PRU Getting Started Labs by jumping to
:ref:`add_the_resource_table_linux`.


.. _add_the_intc_config_file_linux:

.. rubric:: Add the INTC configuration file (optional)

Starting in Linux kernel 5.10, the Linux RemoteProc driver can initialize the
PRU interrupt controller (PRU INTC) using a specific INTC map structure.

Add an INTC configuration file if:

 * the PRU project will be loaded by Linux core running Linux kernel 5.10
   or later, AND

 * The project requires INTC configuration

Reference
<PSSP_PATH>/examples/<processor>/PRU_Direct_Connect0 for an example
project that uses an INTC configuration file.

#. Add the INTC map file to the project. Use this file as a template:
   **<PSSP_PATH>/examples/<processor>/PRU_Direct_Connect0/intc_map_0.h**

#. Include the INTC map file in the main.c file.

   * Example: AM64x using INTC map file "intc_map_0.h"

	::
	
	   #include "intc_map_0.h"

#. Add the INTC map structure to the linker command file. Reference
   **<PSSP_PATH>/examples/<processor>/PRU_Direct_Connect0/xxx_PRU0_intc.cmd**

   ::

      /* Specify the sections allocation into memory */
      SECTIONS {

        ...

        .pru_irq_map (COPY) :
        {
                *(.pru_irq_map)
        }
      }

#. Open the INTC map file. Write the INTC mapping settings following the
   comments in the template INTC map file.


.. _add_the_resource_table_linux:

.. rubric:: Add the resource table (optional)

Will the PRU project be loaded by a core running Linux kernel 5.4 or earlier?

 * Yes --> Jump to section :ref:`add_the_resource_table_linux_5_4_linux`

 * No --> Continue reading.

Will the PRU project be loaded by a core running Linux kernel 5.10 or later?

 * Yes --> Jump to section :ref:`add_the_resource_table_linux_5_10_linux`

 * No --> Resource tables are not used. Continue reading.
 
If you got to this step, then the project does not need a resource table.
Check which version of PSSP is used:

 * v6.0.0 or later: No additional steps are needed. Jump to section
   :ref:`write_the_pru_firmware_linux`

 * v5.9.0 or earlier: An empty resource table is included by default in these
   versions of the PSSP.
   
   #. Go to the main.c file
   
   #. Comment out the resource table include:
   
      ::
   
         /* #include "resource_table_empty.h" */

   #. Jump to section :ref:`write_the_pru_firmware_linux`


.. _add_the_resource_table_linux_5_4_linux:

.. rubric:: Add the resource table with Linux 5.4 or earlier

A resource table is required if the PRU project is loaded by a Linux core
running Linux kernel 5.4 or earlier.

.. note::

   PSSP projects for Linux 5.4 or earlier have different resource tables than
   PSSP projects for Linux 5.10 or later. Check the tag on your PSSP to make
   sure you are using PSSP v5.9.0 or earlier.

Does the PRU project use RPMsg?

 * Yes --> Refer to
   **<PSSP_PATH>/examples/<processor>/xxx_RPMsg_Echo_InterruptX**
   
 * No -->
 
    * Does the PRU project configure the INTC?

      * Yes --> Refer to the AM335x example at
        **<PSSP_PATH>/examples/am335x/PRU_Direct_Connect0**
 
      * No --> If the project does not use RPMsg, or configure the INTC, then
        use an empty resource table. The getting started labs include
        empty resource tables.

#. The basic PRU project should already have an empty resource table file. If
   needed, the getting started labs include an empty resource table under
   **<PSSP_PATH>/Getting_Started_Labs/c_code**.

#. Check that the main.c file includes the resource table file:

   ::

      #include "resource_table_empty.h"

#. Check that the linker command file includes a section for the resource
   table.
   
   * Example: AM335x PRU0

     ::

        .resource_table > PRU_DMEM_0_1, PAGE 1

   * Example: AM62x PRU0

     ::

        /* Ensure resource_table section is aligned on 8-byte address for
           ARMv8 (64-bit) kernel */
        .resource_table : ALIGN (8) >  PRU0_DMEM_0, PAGE 1

   * Example: AM64x RTU1

     ::

       /* Ensure resource_table section is aligned on 8-byte address for
          ARMv8 (64-bit) kernel */
       .resource_table : ALIGN (8) >  RTU1_DMEM_1, PAGE 1

#. The resource table includes rsc_types.h. Add the include path for
   rsc_types.h so that the compiler can find the header file.

   #. Open the Makefile in a text editor.

   #. Ensure that the project Makefile **INCLUDE** points to the
      **directory with rsc_types.h**.

      * Example: AM335x:

         ::

            INCLUDE=--include_path=../../../include --include_path=../../../include/am335x

   #. If the Makefile required changes, save the changes. Close the Makefile.


#. Modify the resource table as needed. The empty resource table that is used
   in the PRU Getting Started Guide does not need to be modified.

Jump to section :ref:`write_the_pru_firmware_linux`


.. _add_the_resource_table_linux_5_10_linux:

.. rubric:: Add the resource table with Linux 5.10 or later (optional)

This section documents the case that the PRU project is loaded by a Linux core
running Linux kernel 5.10 or later.

.. note::

   PSSP projects for Linux 5.4 or earlier have different resource tables than
   PSSP projects for Linux 5.10 or later. Check the tag on your PSSP to make
   sure you are using PSSP v6.0.0 or later.

Will the PRU project use RPMsg to communicate with the Linux core?

 * Yes --> A resource table is required. continue reading.
 
 * No --> If the PRU project does not use RPMsg, then a resource table is not
   required. Jump to section :ref:`write_the_pru_firmware_linux`


The PRU Getting Started Labs do not use RPMsg, so they do not have a resource
table. These steps are provided as a resource for customers who will use a
resource table in their projects. Reference
**<PSSP_PATH>/examples/<processor>/xxx_RPMsg_Echo_InterruptX** for an example
project that uses a resource table.

.. note::

   If the PRU project for Linux 5.10 or later uses RPMsg, then the project
   requires both a resource table and an INTC configuration file. Reference
   section :ref:`add_the_intc_config_file_linux` for steps on adding the INTC
   configuration file.


#. Add the resource table file to the project.

   Copy the resource table from the
   **<PSSP_PATH>/examples/<processor>/xxx_RPMsg_Echo_InterruptX** folder.

      * Example: AM335x PRU0 with RPMsg:

        ::

           cp ../PRU_RPMsg_Echo_Interrupt0/resource_table.h .

#. Include the resource table in the main.c file:

   ::

      #include "resource_table.h"

#. Add the resource table to the linker command file. Reference
   **<PSSP_PATH>/examples/<processor>/xxx_RPMsg_Echo_InterruptX/xxx_PRU0_intc_rscTbl.cmd**
   
   * Example: AM335x PRU0

     ::

         .resource_table > PRU_DMEM_0_1, PAGE 1

   * Example: AM62x PRU0

     ::

        /* Ensure resource_table section is aligned on 8-byte address for
           ARMv8 (64-bit) kernel */
        .resource_table : ALIGN (8) >  PRU0_DMEM_0, PAGE 1

   * Example: AM64x RTU1

     ::

        /* Ensure resource_table section is aligned on 8-byte address for
           ARMv8 (64-bit) kernel */
        .resource_table : ALIGN (8) >  RTU1_DMEM_1, PAGE 1 

#. The resource table includes rsc_types.h. Add the include path for
   rsc_types.h so that the compiler can find the header file.

   #. Open the Makefile in a text editor.

   #. Ensure that the project Makefile **INCLUDE** points to the
      **directory with rsc_types.h**.

      * Example: AM335x:

        ::

           INCLUDE=--include_path=../../../include --include_path=../../../include/am335x

   #. If the Makefile required changes, save the changes. Close the Makefile.


.. _write_the_pru_firmware_linux:

.. rubric:: Write the PRU firmware

Look for the TODO comments in the main.c code for guidance on completing the
example code. The complete solution for the main.c code can be found in
<PSSP_PATH>/labs/Getting_Started_Labs/c_code/solution.

Ready to compile the PRU firmware? Go to :ref:`pru_getting_started_labs_lab_3`.
