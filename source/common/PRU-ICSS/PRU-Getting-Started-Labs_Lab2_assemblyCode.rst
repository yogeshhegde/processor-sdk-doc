.. _pru_getting_started_labs_writing_assembly_code:

Writing Assembly Code
^^^^^^^^^^^^^^^^^^^^^

If the PRU project was created in CCS, follow section
:ref:`pru_getting_started_labs_writing_assembly_code_in_ccs`.

If the PRU project was created in the Linux terminal, follow section
:ref:`pru_getting_started_labs_writing_assembly_code_in_linux`.


.. _pru_getting_started_labs_writing_assembly_code_in_ccs:

Writing Assembly Code in CCS
""""""""""""""""""""""""""""

* :ref:`add_the_main_asm_file_ccs`
* :ref:`add_the_linker_command_file_asm_ccs`
* :ref:`configure_the_pru_intc_asm_ccs`
* :ref:`add_the_resource_table_asm_ccs`
* :ref:`add_the_resource_table_linux_5_4_asm_ccs`
* :ref:`write_the_pru_firmware_asm_ccs`

Start with the empty PRU project created in
:ref:`pru_getting_started_labs_creating_ccs_project`.


.. _add_the_main_asm_file_ccs:

.. rubric:: Add the main ASM file

The PRU project needs an .asm file for the firmware assembly code. Use
"Add Files" to copy the main.asm file from
<PSSP_PATH>/labs/Getting_Started_Labs/assembly_code/.

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

#. Navigate to **<PSSP_PATH>/Getting_Started_Labs/assembly_code** folder.
   Select **main.asm**. Select **open**.

#. Select **Copy files** and click **OK**.

#. Go to the Project Explorer view and double click on main.asm. The text in
   the file should match the text in
   <PSSP_PATH>/labs/Getting_Started_Labs/assembly_code/main.asm


.. _add_the_linker_command_file_asm_ccs:

.. rubric:: Add the linker command file

The linker combines all of the PRU code into a single executable object file
(i.e., the linker creates the binary file that is loaded into the PRU). The
linker command file is used to tell the linker where to place code, how to
resolve addresses, and more.

#. If a linker command file was added to the project folder automatically,
   delete that linker command file. The automatically generated linker files
   are not updated like the linker files in the PSSP.

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

#. Navigate to the **<PSSP_PATH>/Getting_Started_Labs/linker_cmd** folder.
   Select the linker command file that matches the project's PRU core.
   Copy the file into the project.

    * Example: AM335x PRU: Select AM335x_PRU.cmd

   * Example: AM62x PRU0: Select AM62x_PRU0.cmd

   * Example: AM64x TX_PRU0: Select AM64x_TX_PRU0.cmd

.. note::

   AM335x, AM57x: Use the same linker command file for all PRU cores.

   AM437x: Use AM437x_PRU_SS0.cmd for PRU cores in PRU-ICSS0. Use
   AM437x_PRU_SS1.cmd for PRU cores in PRU-ICSS1.

   AM62x: Use PRU0.cmd for PRU0, use PRU1.cmd for PRU1.

   AM64x, AM65x: Use PRU0.cmd for PRU0 in any PRU_ICSSG. Use PRU1.cmd for PRU1
   in any PRU_ICSSG. Similarly, use RTU0.cmd for any RTU0, RTU1.cmd for any
   RTU1, TX_PRU0.cmd for any TX_PRU0, and TX_PRU1.cmd for any TX_PRU1.


.. _configure_the_pru_intc_asm_ccs:

.. rubric:: Configure the PRU INTC (optional)

The PRU Interrupt Controller (INTC) can be configured by the core that loads the
PRU, or by the PRU itself.

The PRU Getting Started Labs do not configure the INTC. However,
these steps are provided as a resource for customers who will configure the INTC
in their projects.

Does the PRU project use interrupts?

 * Yes --> Continue reading.

 * No --> INTC configuration is not needed. Jump to section
   :ref:`add_the_resource_table_asm_ccs`

Will the PRU project be loaded by a core running an OS from the MCU+ SDK?

 * Yes -->

   * Should the INTC be configured by the MCU+ core?

     * Yes --> Reference the documentation in the MCU+ SDK docs, section
       "SOC Peripheral Drivers" > "PRUICSS". Continue the PRU Getting Started
       Labs by jumping to :ref:`add_the_resource_table_asm_ccs`.

     * No --> Continue reading.

.. TODO: Add more details to how to configure the INTC from MCU+?

Will the PRU project be loaded by a core running Linux?

 * Yes --> At this point in time, the Linux RemoteProc driver only accepts INTC
   configurations from PRU projects written in C code. PRU projects written in
   assembly code will need to configure the PRU INTC from the PRU instead of
   from the Linux driver. Continue reading.

 * No --> Continue reading.

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


.. _add_the_resource_table_asm_ccs:

.. rubric:: Add the resource table (optional)

Will the PRU project be loaded by a core running Linux kernel 5.4 or earlier?

 * Yes --> Jump to section :ref:`add_the_resource_table_linux_5_4_asm_ccs`

 * No --> Resource tables are not used. Continue reading.

Will the PRU project be loaded by a core running Linux kernel 5.10 or later?

 * Yes --> Ensure the PSSP version is v6.0.0 or later. No additional steps are
   needed. Jump to section :ref:`write_the_pru_firmware_asm_ccs`.

 * No --> Continue reading.

If you got to this step, then the PRU project will not be loaded by a core
running Linux. The project does not need a resource table.

Check which version of PSSP is used:

 * v6.0.0 or later: No additional steps are needed. Jump to section
   :ref:`write_the_pru_firmware_asm_ccs`.

 * v5.9.0 or earlier: An empty resource table is included by default in these
   versions of the PSSP.

   #. Go to the main.asm file

   #. Delete the resource table lines:

      ::

         ; Resource table needed for remoteproc Linux driver
	         .global	||pru_remoteproc_ResourceTable||
	         .sect	".resource_table:retain", RW
	         .retain
	         .align	1
	         .elfsym	||pru_remoteproc_ResourceTable||,SYM_SIZE(20)
         ||pru_remoteproc_ResourceTable||:
	         .bits	1,32			; pru_remoteproc_ResourceTable.base.ver @ 0
	         .bits	0,32			; pru_remoteproc_ResourceTable.base.num @ 32
	         .bits	0,32			; pru_remoteproc_ResourceTable.base.reserved[0] @ 64
	         .bits	0,32			; pru_remoteproc_ResourceTable.base.reserved[1] @ 96
	         .bits	0,32			; pru_remoteproc_ResourceTable.offset[0] @ 128


   #. Jump to section :ref:`write_the_pru_firmware_asm_ccs`.


.. _add_the_resource_table_linux_5_4_asm_ccs:

.. rubric:: Add the resource table with Linux 5.4 or earlier

A resource table is required if the PRU project is loaded by a Linux core
running Linux kernel 5.4 or earlier.

.. note::

   PSSP projects for Linux 5.4 or earlier have different resource tables than
   PSSP projects for Linux 5.10 or later. Check the tag on your PSSP to make
   sure you are using PSSP v5.9.0 or earlier.

Does the PRU project use RPMsg?

 * Yes --> TI only supports PRU RPMsg with C code. Steps for building a C code
   project (including how to add RPMsg Resource Tables) are at
   :ref:`pru_getting_started_labs_writing_c_code`.

 * No --> Define an empty resource table.

The getting started labs include empty resource tables.

#. Check that the main.asm file includes an empty resource table:

      ::

         ; Resource table needed for remoteproc Linux driver
	         .global	||pru_remoteproc_ResourceTable||
	         .sect	".resource_table:retain", RW
	         .retain
	         .align	1
	         .elfsym	||pru_remoteproc_ResourceTable||,SYM_SIZE(20)
         ||pru_remoteproc_ResourceTable||:
	         .bits	1,32			; pru_remoteproc_ResourceTable.base.ver @ 0
	         .bits	0,32			; pru_remoteproc_ResourceTable.base.num @ 32
	         .bits	0,32			; pru_remoteproc_ResourceTable.base.reserved[0] @ 64
	         .bits	0,32			; pru_remoteproc_ResourceTable.base.reserved[1] @ 96
	         .bits	0,32			; pru_remoteproc_ResourceTable.offset[0] @ 128


#. Check that the linker command file includes a section for the resource
   table.

    * Example: AM335x PRU0

      ::

         .resource_table > PRU_DMEM_0_1, PAGE 1

    * Example: AM65x PRU0

      ::

         /* Ensure resource_table section is aligned on 8-byte address for
            ARMv8 (64-bit) kernel */
         .resource_table : ALIGN (8) >  PRU0_DMEM_0, PAGE 1

#. The resource table includes rsc_types.h. Add the appropriate include path:

   #. Select **Project->Properties**.

   #. Select **Build->PRU Compiler->Include Options**.

   #. In the box marked **"Add dir to #include search path"**, click the
      **file icon with a green +**.

.. TODO: Add image above

   #. Specify the directory **<PSSP_PATH>/include**.

#. The empty resource table that is used in the PRU Getting Started Guide
   does not need to be modified.

Jump to section :ref:`write_the_pru_firmware_asm_ccs`


.. _write_the_pru_firmware_asm_ccs:

.. rubric:: Write the PRU firmware

Look for the TODO comments in the main.asm code for guidance on completing
the example code. The complete solution for the main.asm code can be found in
<PSSP_PATH>/labs/Getting_Started_Labs/assembly_code/solution.

Ready to compile the PRU firmware? Go to :ref:`pru_getting_started_labs_lab_3`.


.. _pru_getting_started_labs_writing_assembly_code_in_linux:

Writing Assembly Code in Linux
""""""""""""""""""""""""""""""

* :ref:`add_the_main_asm_file_linux`
* :ref:`add_the_makefile_asm_linux`
* :ref:`add_the_linker_command_file_asm_linux`
* :ref:`configure_the_pru_intc_asm_linux`
* :ref:`add_the_resource_table_asm_linux`
* :ref:`add_the_resource_table_linux_5_4_asm_linux`
* :ref:`write_the_pru_firmware_asm_linux`

Start with the basic PRU project created in
:ref:`pru_getting_started_labs_creating_linux_project`. Start in the same
directory as in Lab 1: **<PSSP_PATH>/examples/<processor>**


.. _add_the_main_asm_file_linux:

.. rubric:: Add the main ASM file

The PRU project needs an .asm file for the firmware assembly code.

#. The basic PRU project should already have a main.c file. Delete the
   existing main.c file.

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

#. Copy the main.asm file from
   <PSSP_PATH>/labs/Getting_Started_Labs/assembly_code/ to
   the current directory.

   ::

      $ cp ../../../labs/Getting_Started_Labs/assembly_code/main.asm .

#. The main.asm file in the current directory should match the main.asm file
   in labs/Getting_Started_Labs/assembly_code/.

   * Example: AM335x with PRU0, based on PRU_Halt:

     ::

        $ diff ../../../labs/Getting_Started_Labs/assembly_code/main.asm main.asm
        # there should be no output


.. _add_the_makefile_asm_linux:

.. rubric:: Add the Makefile

The PRU project needs a Makefile in order to build the firmware through the
Linux terminal.

#. The basic PRU project should already have a Makefile. Delete the existing
   Makefile.

   * Example: AM335x with PRU0:

     ::

        $ cd PRU_Add
        $ ls
        $ rm Makefile

   * Example: AM64x with RTU1:

      ::

        $ cd RTU_Add
        $ ls
        $ rm Makefile

#. Copy the Makefile file from
   <PSSP_PATH>/labs/Getting_Started_Labs/assembly_code/solution/<processor>/
   to the current directory.

   * Example: AM335x with PRU0:

     ::

        $ cp ../../../labs/Getting_Started_Labs/assembly_code/solution/am335x/Makefile .

   * Example: AM64x with RTU1:

      ::

        $ cp ../../../labs/Getting_Started_Labs/assembly_code/solution/am64x/Makefile .

#. The Makefile in the current directory should match the Makefile in
   labs/Getting_Started_Labs/assembly_code/solution/<processor>/.

   * Example: AM335x with PRU0, based on PRU_Halt:

     ::

        $ diff ../../../labs/Getting_Started_Labs/assembly_code/solution/am335x/Makefile Makefile
        # there should be no output

        $ diff ../PRU_Halt/Makefile Makefile
        # Makefile in PRU_Halt should be different

The Makefile may need modifications depending on which PRU core the project
uses. See more information in :ref:`add_the_linker_command_file_asm_linux`.


.. _add_the_linker_command_file_asm_linux:

.. rubric:: Add the linker command file

The linker combines all of the PRU code into a single executable object file
(i.e., the linker creates the binary file that is loaded into the PRU). The
linker command file is used to tell the linker where to place code, how to
resolve addresses, and more.

#. The basic PRU project should already have a linker command file. Make sure
   that the linker command file matches the project's PRU core.



    * Example: AM335x PRU: Select AM335x_PRU.cmd

    * Example: AM62x PRU0: Select AM62x_PRU0.cmd

    * Example: AM64x TX_PRU0: Select AM64x_TX_PRU0.cmd

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

      * Example: AM64x TX_PRU0 using AM64x_TX_PRU0.cmd:

        ::

           LINKER_COMMAND_FILE=./AM64x_TX_PRU0.cmd

   #. If the Makefile required changes, save the changes. Close the Makefile.


.. _configure_the_pru_intc_asm_linux:

.. rubric:: Configure the PRU INTC (optional)

The PRU Interrupt Controller (INTC) can be configured by the core that loads the
PRU, or by the PRU itself.

The PRU Getting Started Labs do not configure the INTC. However,
these steps are provided as a resource for customers who will configure the INTC
in their projects.

Does the PRU project use interrupts?

 * Yes --> Continue reading.

 * No --> INTC configuration is not needed. Jump to section
   :ref:`add_the_resource_table_asm_linux`

Will the PRU project be loaded by a core running an OS from the MCU+ SDK?

 * Yes -->

   * Should the INTC be configured by the MCU+ core?

     * Yes --> Reference the documentation in the MCU+ SDK docs, section
       "SOC Peripheral Drivers" > "PRUICSS". Continue the PRU Getting Started
       Labs by jumping to :ref:`add_the_resource_table_asm_linux`.

     * No --> Continue reading.

.. TODO: Add more details to how to configure the INTC from MCU+?

Will the PRU project be loaded by a core running Linux?

 * Yes --> At this point in time, the Linux RemoteProc driver only accepts INTC
   configurations from PRU projects written in C code. PRU projects written in
   assembly code will need to configure the PRU INTC from the PRU instead of
   from the Linux driver. Continue reading.

 * No --> Continue reading.

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


.. _add_the_resource_table_asm_linux:

.. rubric:: Add the resource table (optional)

Will the PRU project be loaded by a core running Linux kernel 5.4 or earlier?

 * Yes --> Jump to section :ref:`add_the_resource_table_linux_5_4_asm_linux`

 * No --> Resource tables are not used. Continue reading.

Will the PRU project be loaded by a core running Linux kernel 5.10 or later?

 * Yes --> Ensure the PSSP version is v6.0.0 or later. No additional steps are
   needed. Jump to section :ref:`write_the_pru_firmware_asm_linux`.

 * No --> Continue reading.

If you got to this step, then the PRU project will not be loaded by a core
running Linux. The project does not need a resource table.

Check which version of PSSP is used:

 * v6.0.0 or later: No additional steps are needed. Jump to section
   :ref:`write_the_pru_firmware_asm_linux`.

 * v5.9.0 or earlier: An empty resource table is included by default in these
   versions of the PSSP.

   #. Go to the main.asm file

   #. Delete the resource table lines:

      ::

         ; Resource table needed for remoteproc Linux driver
	         .global	||pru_remoteproc_ResourceTable||
	         .sect	".resource_table:retain", RW
	         .retain
	         .align	1
	         .elfsym	||pru_remoteproc_ResourceTable||,SYM_SIZE(20)
         ||pru_remoteproc_ResourceTable||:
	         .bits	1,32			; pru_remoteproc_ResourceTable.base.ver @ 0
	         .bits	0,32			; pru_remoteproc_ResourceTable.base.num @ 32
	         .bits	0,32			; pru_remoteproc_ResourceTable.base.reserved[0] @ 64
	         .bits	0,32			; pru_remoteproc_ResourceTable.base.reserved[1] @ 96
	         .bits	0,32			; pru_remoteproc_ResourceTable.offset[0] @ 128


   #. Jump to section :ref:`write_the_pru_firmware_asm_linux`.


.. _add_the_resource_table_linux_5_4_asm_linux:

.. rubric:: Add the resource table with Linux 5.4 or earlier

A resource table is required if the PRU project is loaded by a Linux core
running Linux kernel 5.4 or earlier.

.. note::

   PSSP projects for Linux 5.4 or earlier have different resource tables than
   PSSP projects for Linux 5.10 or later. Check the tag on your PSSP to make
   sure you are using PSSP v5.9.0 or earlier.

Does the PRU project use RPMsg?

 * Yes --> TI only supports PRU RPMsg with C code. Steps for building a C code
   project (including how to add RPMsg Resource Tables) are at
   :ref:`pru_getting_started_labs_writing_c_code`.

 * No --> Define an empty resource table.

The getting started labs include empty resource tables.


#. Check that the main.asm file includes an empty resource table:

      ::

         ; Resource table needed for remoteproc Linux driver
	         .global	||pru_remoteproc_ResourceTable||
	         .sect	".resource_table:retain", RW
	         .retain
	         .align	1
	         .elfsym	||pru_remoteproc_ResourceTable||,SYM_SIZE(20)
         ||pru_remoteproc_ResourceTable||:
	         .bits	1,32			; pru_remoteproc_ResourceTable.base.ver @ 0
	         .bits	0,32			; pru_remoteproc_ResourceTable.base.num @ 32
	         .bits	0,32			; pru_remoteproc_ResourceTable.base.reserved[0] @ 64
	         .bits	0,32			; pru_remoteproc_ResourceTable.base.reserved[1] @ 96
	         .bits	0,32			; pru_remoteproc_ResourceTable.offset[0] @ 128


#. Check that the linker command file includes a section for the resource
   table.

    * Example: AM335x PRU0

      ::

         .resource_table > PRU_DMEM_0_1, PAGE 1

    * Example: AM65x PRU0

      ::

         /* Ensure resource_table section is aligned on 8-byte address for
            ARMv8 (64-bit) kernel */
         .resource_table : ALIGN (8) >  PRU0_DMEM_0, PAGE 1

#. The resource table includes rsc_types.h. Add the include path for
   rsc_types.h so that the compiler can find the header file.

   #. Open the Makefile in a text editor.

   #. Ensure that the project Makefile **INCLUDE** points to the
      **directory with rsc_types.h**.

      * Example: AM335x:

         ::

            INCLUDE=--include_path=../../../include --include_path=../../../include/am335x

   #. If the Makefile required changes, save the changes. Close the Makefile.

#. The empty resource table that is used
   in the PRU Getting Started Guide does not need to be modified.

Jump to section :ref:`write_the_pru_firmware_asm_linux`


.. _write_the_pru_firmware_asm_linux:

.. rubric:: Write the PRU firmware

Look for the TODO comments in the main.asm code for guidance on completing
the example code. The complete solution for the main.asm code can be found in
<PSSP_PATH>/labs/Getting_Started_Labs/assembly_code/solution.

Ready to compile the PRU firmware? Go to :ref:`pru_getting_started_labs_lab_3`.
