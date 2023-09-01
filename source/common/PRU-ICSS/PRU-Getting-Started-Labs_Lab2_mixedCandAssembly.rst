.. _pru_getting_started_labs_writing_c_and_assembly_code:

Writing Mixed C and Assembly Code
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

There are multiple ways to combine C code and assembly code. One option is to
write a function in assembly, and to call that function from C code like any
other function. The "assembly function" option is fairly straightforward as long
as all the function calling conventions and register conventions are respected.

Another option is to insert single lines of assembly language directly into the
C code. Be extremely careful if using inline assembly. It can be easy to
disrupt the C/C++ environment since the C compiler does not check or analyze the
inline assembly code.

This section shows how to create a PRU project that combines C with an external
assembly function. To see how to create a PRU project with inline assembly,
reference section :ref:`pru_getting_started_labs_writing_c_and_inline_assembly_code`.


This section assumes that you have already read through
:ref:`pru_getting_started_labs_writing_c_code`
and
:ref:`pru_getting_started_labs_writing_assembly_code`.

Start with a blank project as per the steps in
:ref:`pru_getting_started_labs_lab_1`. This should be a different project than
the projects created for
:ref:`pru_getting_started_labs_writing_c_code`
and
:ref:`pru_getting_started_labs_writing_assembly_code`.

The steps for Writing Mixed C and Assembly Code apply to both PRU projects
that were created in CCS, and PRU projects that were created in the Linux
terminal.

* :ref:`write_the_main_function_in_c_mixed`
* :ref:`write_the_external_function_in_asm`
* :ref:`more_resources_for_c_and_assembly_mixed`


.. _write_the_main_function_in_c_mixed:

Write the Main Function in C
""""""""""""""""""""""""""""

#. Add the main.c file from
   **<PSSP_PATH>/labs/Getting_Started_Labs/c_and_assembly/**

#. If the project was created in the Linux terminal, delete the existing
   Makefile. Copy the Makefile from
   <PSSP_PATH>/labs/Getting_Started_Labs/c_and_assembly/solution/<processor>/
   to the project directory.

#. Add the linker command file.

   * If the project was created in CCS:

     #. Remove any linker command file that was automatically added to the project.

     #. Delete the include link that points to automatically generated linker files.

     #. Add the linker command file that matches the PRU core you are using from
        **<PSSP_PATH>/Getting_Started_Labs/linker_cmd**.

   * If the project was created in the Linux terminal:

     #. Verify that the project linker command file matches the PRU core.

#. Include header files if the project uses them. The Getting Started Labs do
   not use header files.

#. Configure the PRU INTC if the PRU project uses interrupts. The Getting
   Started Labs do not configure the PRU INTC.

#. Add the resource table if the project is loaded by a Linux core running
   Linux kernel 5.4 or earlier, or if the project is loaded by a Linux core
   running Linux kernel 5.10 or later AND the project uses RPMsg. The Getting
   Started Labs do not use RPMsg.

#. Write the main.c firmware code:

   * Section :ref:`write_the_external_function_in_asm` will explain how to
     ensure that the main.c file can find the external assembly function.

   * Look for the TODO comments in the main.c code for guidance on completing
     the example code. The complete solution for the main.c code can be found
     in <PSSP_PATH>/labs/Getting_Started_Labs/c_and_assembly/solution.


.. _write_the_external_function_in_asm:

Write the External Function in Assembly
"""""""""""""""""""""""""""""""""""""""

The PRU project's main function, linker command file, INTC configuration
(optional) and resource table (optional) are all handled in the main.c file.

#. Add the assm_add.asm file from
   **<PSSP_PATH>/labs/Getting_Started_Labs/c_and_assembly/**

#. Make sure that the following conditions are met. These conditions are
   required in order for the main.c file to be able to use the externally
   defined assembly function:

   * The .sect name must match the function declaration in main.c.

   * The section must be defined as .global

#. write the assm_add.asm firmware code:

   * Look for the TODO comments in the assm_add.asm code for guidance on
     completing the example code. The complete solution for the assm_add.asm
     code can be found in
     <PSSP_PATH>/labs/Getting_Started_Labs/c_and_assembly/solution.


.. _more_resources_for_c_and_assembly_mixed:

More Resources for Writing Mixed C and Assembly Code
""""""""""""""""""""""""""""""""""""""""""""""""""""

For more information about writing mixed C and assembly code,
reference the `PRU Optimizing C/C++ Compiler User's Guide <https://www.ti.com/lit/spruhv7>`__,
section "Interfacing C and C++ With Assembly Language".

Ready to compile the PRU firmware? Go to :ref:`pru_getting_started_labs_lab_3`.


.. _pru_getting_started_labs_writing_c_and_inline_assembly_code:

Writing Mixed C and Inline Assembly Code
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

There are multiple ways to combine C code and assembly code. One option is to
write a function in assembly, and to call that function from C code like any
other function. The "assembly function" option is fairly straightforward as long
as all the function calling conventions and register conventions are respected.

Another option is to insert single lines of assembly language directly into the
C code. Be extremely careful if using inline assembly. It can be easy to
disrupt the C/C++ environment since the C compiler does not check or analyze the
inline assembly code.

This section shows how to create a PRU project that combines C with inline
assembly code. To see how to create a PRU project with an assembly function,
reference section :ref:`pru_getting_started_labs_writing_c_and_assembly_code`.

This section assumes that you have already read through
:ref:`pru_getting_started_labs_writing_c_code`
and
:ref:`pru_getting_started_labs_writing_assembly_code`.

Start with a blank project as per the steps in
:ref:`pru_getting_started_labs_lab_1`. This should be a different project than
the projects created for
:ref:`pru_getting_started_labs_writing_c_code`
and
:ref:`pru_getting_started_labs_writing_assembly_code`.

The steps for Writing Mixed C and Inline Assembly Code apply to both PRU
projects that were created in CCS, and PRU projects that were created in the
Linux terminal.

* :ref:`write_the_main_function_in_c_inline`
* :ref:`write_the_inline_function_in_asm`
* :ref:`more_resources_for_c_and_inline_assembly`


.. _write_the_main_function_in_c_inline:

Write the Main Function in C
""""""""""""""""""""""""""""

#. Add the main.c file from
   **<PSSP_PATH>/labs/Getting_Started_Labs/c_and_inline_assembly/**

#. If the project was created in the Linux terminal, delete the existing
   Makefile. Copy the Makefile from
   <PSSP_PATH>/labs/Getting_Started_Labs/c_and_inline_assembly/solution/<processor>/
   to the project directory.

#. Add the linker command file.

   * If the project was created in CCS:

     #. Remove any linker command file that was automatically added to the project.

     #. Delete the include link that points to automatically generated linker files.

     #. Add the linker command file that matches the PRU core you are using from
        **<PSSP_PATH>/Getting_Started_Labs/linker_cmd**.

   * If the project was created in the Linux terminal:

     #. Verify that the project linker command file matches the PRU core.

#. Include header files if the project uses them. The Getting Started Labs do
   not use header files.

#. Configure the PRU INTC if the PRU project uses interrupts. The Getting
   Started Labs do not configure the PRU INTC.

#. Add the resource table if the project is loaded by a Linux core running
   Linux kernel 5.4 or earlier, or if the project is loaded by a Linux core
   running Linux kernel 5.10 or later AND the project uses RPMsg. The Getting
   Started Labs do not use RPMsg.

#. Write the main.c firmware code:

   * Section :ref:`write_the_inline_function_in_asm` will explain how to
     ensure that the main.c file can find the external assembly function.

   * Look for the TODO comments in your main.c code for guidance on completing
     the example code. The complete solution for the main.c code can be found
     in <PSSP_PATH>/labs/Getting_Started_Labs/c_and_assembly/solution.

.. _write_the_inline_function_in_asm:

Write the Inline Function in Assembly
"""""""""""""""""""""""""""""""""""""""

#. write the assm_add.asm firmware code:

   * Look for the TODO comments in your assm_add.asm code for guidance on
     completing the example code. The complete solution for the assm_add.asm
     code can be found in
     <PSSP_PATH>/labs/Getting_Started_Labs/c_and_assembly/solution.


.. _more_resources_for_c_and_inline_assembly:

More Resources for Writing Mixed C and Inline Assembly Code
"""""""""""""""""""""""""""""""""""""""""""""""""""""""""""

For more information about writing mixed C and assembly code,
reference the `PRU Optimizing C/C++ Compiler User's Guide <https://www.ti.com/lit/spruhv7>`__,
section "Interfacing C and C++ With Assembly Language". Pay special attention
to the warnings about using inline assembly code in section "Using Inline
Assembly Language".

Ready to compile the PRU firmware? Go to :ref:`pru_getting_started_labs_lab_3`.
