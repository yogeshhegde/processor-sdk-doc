.. http://processors.wiki.ti.com/index.php/PRU-ICSS_Header_Files

.. rubric:: Introduction
   :name: introduction

The header files for the PRU-ICSS were written in such a way so as to
sit on top of the memory-mapped registers. They can be directly linked
to that address range via the Linker Command File, but in the existing
examples are accessed via the Constant Table registers. The Constant
Table is better described here.

.. rubric:: Layout
   :name: layout

The register sets are grouped up into structures containing the
appropriate gaps for reserved registers. Each register can be accessed
as a full 32-bit register (although the ECAP peripheral does have some
16-bit registers) or at the bit-field level. This is so as to eliminate
the need to do bit-masking at the register level.

.. rubric:: Using the Headers
   :name: using-the-headers

In order to tie the structures to the appropriate Constant Table
register we have to use a special trick with the PRU Code Generation
Tools package. This process is described in more detail in the CGT
Documentation here. For our purposes the linker command file found in
each example project contains a "Memory" range for each of the Constant
Table entries.

Once this is completed you will be able to access a peripheral register
via the structure by accessing that structure's members. The basic
layout is like this:

| struct{

union{
u32 register\_name;
struct {
bit\_field\_names : bit\_size;
. . .
} register\_name\_bit;
};
. . .
| } register\_set;

Thus you can access a register programmatically through the structure
(e.g., register\_set.register\_name[\_bit.bitfield\_name] = value).

.. raw:: html

