.. http://processors.wiki.ti.com/index.php/AMSDK_to_Processor_SDK_Migration_Guide

AMSDK to Processor SDK Migration Guide
===============================================================

For many years, the AMSDK has been a great way to get started with
Embedded Linux development on TI's broad market line of ARM Cortex-A
microprocessors, also referred to as Sitara. If you go by "what's in a
name?", you can easily see the connection. The "AM" of AMSDK is the
first two letters of part numbers in the Sitara line-up. For example,
take the AM335x which is an ARM Cortex-A8 based processor which drives
the popular Beaglebone Black board. The "SDK" refers to Software
Development Kit. The AMSDK was designed from the ground up to provide
a great starting point for developing an embedded Linux system on a
Sitara Processor. One of the goals of the AMSDK was to enable a
developer to quickly (under 10 minutes) explore and evaluate the
possibilities as well as start development on a customized Linux
software platform in under an hour. It's up to each developer to
decide if the AMSDK achieved these goals, but the feedback overall has
been positive.

Like the Linux kernel itself, which evolves every 77 days or so with a
new release, it's time for the AMSDK to evolve, without departing from
it's heritage. TI has a rich offering of microprocessors from multicore
ARMs to tiny, power-efficient DSPs, and different combinations of ARM,
DSP, and specialized cores to provide the broad market a variety of
solutions. Since many developers will touch several of these devices
from project to project, it is beneficial to standardize the experience
to maximize the benefit of learning. The limited time developers have in
today's time-to-market driven environment is very important and
shouldn't be wasted.

To this end, the AMSDK is being renamed to the Processor SDK for Linux.
This new title will allow future devices, which may not carry the "AM"
naming convention, to benefit from the same software development
experience. Each developer that uses the Processor SDK from project to
project can leverage that experience and know with confidence what they
can expect.

With this background in place, let's dig into more specifics.

Migrating from AMSDK 8.0 to Processor SDK 1.0
---------------------------------------------------

As suggested above, this transition at this point in time, is largely a
name change. The good news is, migration should be very simple. From a
component point of view, Processor SDK for Linux 1.0 is very similar to
AMSDK 8.0:

+----------------------------+-------------------------------------+-------------------------------------+
| Component                  | AMSDK 8.0                           | Processor SDK 1.0                   |
+============================+=====================================+=====================================+
| U-Boot Bootloader          | v2014.07                            | v2014.07                            |
+----------------------------+-------------------------------------+-------------------------------------+
| Linux Kernel               | 3.14.26                             | 3.14.26                             |
+----------------------------+-------------------------------------+-------------------------------------+
| Toolchain                  | Linaro GCC 4.7 2013.03 hard-float   | Linaro GCC 4.7 2013.03 hard-float   |
+----------------------------+-------------------------------------+-------------------------------------+
| GUI Development Platform   | Qt 4.8                              | Qt 5.4                              |
+----------------------------+-------------------------------------+-------------------------------------+
| Graphics SDK               | 05.01.01.02                         | 05.01.01.02                         |
+----------------------------+-------------------------------------+-------------------------------------+
| Supported Platforms        | AM335x and AM437x                   | AM335x and AM437x                   |
+----------------------------+-------------------------------------+-------------------------------------+
| Supported Hosts            | Ubuntu 12.04 and 14.04              | Ubuntu 12.04 and 14.04              |
+----------------------------+-------------------------------------+-------------------------------------+

Table:  AMSDK 8.0 to Processor SDK 1.0 Component Comparison

It is clear from the above that these SDKs are very similar. The biggest
difference by far is the transition from Qt 4.8 to Qt 5.4. If you'd like
to learn more about this specifically, please see the `Qt 4 to 5
Migration <http://processors.wiki.ti.com/index.php/Qt_4_to_5_Migration>`__. If you have a "headless"
system, or don't use Qt, then this is really a "don't care".

The rest of the Arago filesystem provided with the SDK was updated as
well. Please consult the Software Manifest for specific changes.

Documentation
^^^^^^^^^^^^^^^^^^

Since the components are mostly common, the documentation is also very
similar. The headings and such have been updated to include the new
Processor SDK naming, but the content, except when improved or
necessary, is largely the same.

Hardware Platforms
^^^^^^^^^^^^^^^^^^^

Both SDKs support the same hardware platforms from TI. Here's the
`list <Release_Specific.html#supported-platforms-and-versions>`__
from the Processor SDK, for completeness.

Board Porting
^^^^^^^^^^^^^^^^^

One of the major efforts to developing a customer Linux Embedded System
is porting the bootloader, U-Boot in this case, and the Linux kernel to
a new hardware platform. Since the U-Boot and Kernel sources provided
with the Processor SDK 1.0 are identical, this effort is minimal to
non-existent. Custom drivers and any other bootloader or kernel code
should move over seamlessly.

Application Development
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

If using the Arago Filesystem provided with the SDK (i.e. you haven't
yet used Yocto/Open Embedded to create your own), the specific versions
of the packages provided might change slightly. Please consult the
Software Manifest for any packages your are concerned with.

.. rubric:: GUI Development
   :name: gui-development

As highlighted above, this is the largest change between the two SDKs.
If Qt 4.x is used currently, it is possible that adaptation to Qt 5.4
will be necessary. It depends largely on the Qt components used and how
they transition to Qt 5.4. Again, please consult the `Qt 4 to 5
Migration Guide <http://processors.wiki.ti.com/index.php/Qt_4_to_5_Migration>`__ for more
information.

Summary
------------

The AMSDK that you may be familiar with is getting a new name, the
Processor SDK for Linux. This name change paves the way for adding more
devices from TI's processor line-up and allow developer's to enjoy the
same experience with more options. What seems like a simple name change
at this point, will continue to grow to become an extensive software
offering covering a broad range of devices, as well as operating
systems, examples, tools, and other important components developers need
in this fast-paced, time-to-market driven environment. The experience
gained will translate nicely to the next project or the next set of
challenges, enabling developers to be more efficient and successful.

The migration from the AMSDK to the Processor SDK is expected to be
minimal, with a few noted exceptions. It's a great time to explore the
"new" AMSDK, and see how it will help solve the challenges faced today,
and preparing for those in the future.

