.. _pru_getting_started_labs_lab_2:

Lab 2: How to Write PRU Firmware
--------------------------------

.. toctree::
   :maxdepth: 2

   PRU-Getting-Started-Labs_Lab2_cCode
   PRU-Getting-Started-Labs_Lab2_assemblyCode
   PRU-Getting-Started-Labs_Lab2_mixedCandAssembly

This lab will explain how to write firmware for a simple PRU program. The
example PRU program will continuously add two numbers and save the result.

PRU cores run bare metal software (i.e., TI does not support running an
operating system on the PRU cores). PRU firmware may be written in C code, or
in assembly code.

* C code is compiled into machine language by the TI PRU C/C++ Compiler. C code
  provides the benefits of a high level language. For example, C code is
  typically easier to read and write than Assembly code.
  
* Each assembly instruction directly correlates to a machine language instruction.
  That means that assembly code precisely controls the PRU core and the timing
  of the PRU core. For example, if the PRU implements a custom
  communication protocol, assembly code allows the PRU to always read input
  signals and write output signals at the exact correct time.

* C code and assembly code can be combined to provide the benefits of both
  forms of programming.
  

.. seealso::

   More information about the TI PRU Code Generation Tools (including
   the TI PRU C/C++ Compiler and Assembly Language Tool) can be found at:

   `TI PRU Code Generation Tools <https://www.ti.com/tool/PRU-CGT>`__

.. note::

   The C compiler can be used to generate assembly code from C code.
   Generated assembly code may be a helpful starting point for assembly code
   development. See :ref:`pru_getting_started_labs_lab_3`
 
Start this lab with either :ref:`pru_getting_started_labs_writing_c_code`, or
with :ref:`pru_getting_started_labs_writing_assembly_code`.

If interested in writing mixed C and assembly programs, go through the
"Writing C Code" and "Writing Assembly Code" sections first. Then, go
through :ref:`pru_getting_started_labs_writing_c_and_assembly_code` and
:ref:`pru_getting_started_labs_writing_c_and_inline_assembly_code`.
