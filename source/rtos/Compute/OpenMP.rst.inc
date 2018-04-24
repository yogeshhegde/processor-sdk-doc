.. http://processors.wiki.ti.com/index.php/OpenMP_on_C6000 

.. rubric:: Introduction
   :name: introduction

As of April 2016, this article is out of date. Please visit
`here <http://downloads.ti.com/mctools/esd/docs/openmp-dsp/index.html>`__.

This page is intended to be the starting point for all information about
OpenMP on C6000. However, at this writing, that is not the case. The
information in this article is correct if you are using C667x devices
which only contain C66x CorePac DSPs, and not any ARM cores. If you are
using a 66AK2H device, then please see `MCSDK HPC 3.x 
OpenMP <http://processors.wiki.ti.com/index.php/MCSDK_HPC_3.x_OpenMP>`__. OpenMP is not supported on
any other C6000 devices.

Still here? After reading this article, you will be able to execute your
own OpenMP code on C6000 under control of Code Composer Studio.

.. rubric:: Presumptions
   :name: presumptions

-  You are experienced at programming OpenMP applications on hosted
   systems like Windows or Linux PC's.
-  You have never programmed anything on an embedded system like those
   that use C6000 devices.
-  You have never used any TI development tools such as Code Composer
   Studio (CCS).

.. rubric:: Acronyms Used in This Article
   :name: acronyms-used-in-this-article

-  CCS - Code Composer Studio. Software development environment for
   creating code to execute on TI devices.
-  SYS/BIOS - Or BIOS for short. Scalable real-time kernel which runs on
   the DSP.
-  MCSDK - Multicore Software Development Kit. Bundles all the software
   supplied by TI which runs on the DSP.

.. rubric:: Conceptual Overview
   :name: conceptual-overview

This section discusses, at a high level, how different pieces of
software from TI work together to form the OpenMP solution.

The OpenMP source code, at the level of OpenMP pragmas and function
calls, is the same. Your code must be organized into a *project*, as
that term is defined by CCS. A central element of this project is the
SYS/BIOS configuration. SYS/BIOS (or BIOS for short) is a scalable
real-time kernel produced by TI. BIOS implements the multi-threading
features of OpenMP. An initial BIOS configuration (*.cfg) is supplied.
Changing this BIOS configuration may never be required. The build is
done within CCS. At the start, system execution is also done within CCS.
Besides BIOS, many other software components execute on the DSP to
comprise the OpenMP solution. All of these components are delivered
together under the name Multicore Software Development Kit (MCSDK).

.. rubric:: Installation
   :name: installation

Getting the MCSDK installed calls for you to install and configure
everything else, so this section focuses on the MCSDK.

Start with the `general download
page <http://www.ti.com/tool/bioslinuxmcsdk>`__ for all flavors of the
MCSDK. Follow the link for *SYS/BIOS MCSDK for C66x*. Get MCSDK version
2.1 or later. That page includes a link to a *Getting Started Guide*.
That is where you will find directions on hardware setup, installing
CCS, and so on. Follow all the steps in the Getting Started Guide, up to
Running the Demonstration Application. (Actually, go ahead and run the
Demo if you want. But it isn't required.)

.. rubric:: Confidence Test
   :name: confidence-test

If you are familiar with CCS, you may skip over this section. But,
installing and configuring all that software may leave you wondering if
you did it all correctly. In this section, simplify things by pretending
your system only has one core. This allows you to check whether you have
installed most of the software correctly, while ignoring many of the
complicated details.

Please check out `this set of Getting Started
Guides <http://processors.wiki.ti.com/index.php/Category:Code_Composer_Studio_v5#Getting_Started>`__
just for CCS. You only need to go through one of them. Choose the one
that seems best for you. These guides provide a gentle introduction to
those who are new to CCS.

When you load and run your first program, CCS needs to know which core
to run it on. You see a dialog box similar this one:

.. Image:: ../images/Select_core.JPG

Check the box only for core 0.

.. rubric:: First OpenMP Project
   :name: first-openmp-project

This section walks through a simple hello world example project. Four
threads run concurrently. Each thread prints hello world and the thread
ID.

.. rubric:: Version and HW Information
   :name: version-and-hw-information

This section was developed with CCS version 5.2.0.00069, MCSDK version
2.1.0.3, and executed on an C6678 EVM. If your environment differs, you
may have to make a few adjustments.

.. rubric:: Project Setup
   :name: project-setup

In this section you create a new CCS project. This project is not
written from scratch, but uses example source files that come with CCS.

Put CCS in the Edit Perspective. Select: **Window \| Open Perspective \|
Other \| CCS Edit**. To start this new project select: **Project \| New
CCS Project**. Enter a **Project Name**. For **Family** select
**C6000**. For **Variant**, ignore the first drop-down box, and in the
second choose **Generic C66xx Device**. In the box just under **Project
templates and examples** type in *hello*. Under *OMP Examples* you will
see some *Hello world example* projects. Select the best one for your HW
platform. In this screen shot, the selection is for C6678. Select
**Next**.

.. Image:: ../images/Omp_h1_project_setup.jpg

The next dialog shows the RTSC Configuration Settings. If only one
version of the MCSDK is installed, then nothing more is required. If
more than one version of the MCSDK is installed, review the version
numbers of the selected packages and insure they are from the desired
MCSDK. Do not forget the drop-down box at the top for the version of the
XDCtools.

Click **Finish**. CCS creates the project, complete with source code,
and adds an entry to the **Project Explorer** window.

.. rubric:: Project Modifications
   :name: project-modifications

One modification to the example project is required.

In the **Project Explorer** window, expand the set of files available
under the new project. Open the file *omp_config.cfg* by double-clicking
on it. The edit window has two tabs on the bottom left. Select the
**Source** tab. Find the source line which begins *var OpenMP ...*
Change the code as follows ...

::

    var OpenMP = xdc.useModule('ti.omp.utils.OpenMP');    // no change
    OpenMP.setNumProcessors(4);                           // no change
    OpenMP.autoDnldCore = false;                          // add this line

The new line disables the feature called auto-download. A side effect of
auto-download is that printf works only on core 0.

Save the change to the configuration file by entering control+S or
selecting **File \| Save**.

.. rubric:: Build and Load
   :name: build-and-load

The target configuration that should launch when this OpenMP project is
debugged is the same one used for previous single core projects. To
check on this detail, choose **View \| Target Configurations**. Find
that target configuration and insure it is the default.

In the **Project Explorer** window, insure the new project is selected.

Select the Debug icon.

.. Image:: ../images/Omp_h2_debug_icon.JPG

Next a dialog will come up which asks which CPU cores to load the
program on. Select cores 0-3, then click **OK**. It will appear similar
to this ...

.. Image:: ../images/Omp_h3_select_cores.JPG

The following actions take place automatically:

-  CCS changes to the Debug perspective
-  The project is built
-  The target configuration is launched
-  The target connection is made
-  The program is loaded on cores 0-3
-  The system begins execution and runs to the start of main on core 0

.. rubric:: Execute and See Output
   :name: execute-and-see-output

Now you are ready to execute. In the Debug window, click the Resume
execution icon.

.. Image:: ../images/Omp_h4_resume_icon.JPG

The console window will show output similar to, but not exactly the same
as, the following ...

::

    [C66xx_0] Hello World from thread = 0
    [C66xx_0] Number of threads = 4
    [C66xx_1] Hello World from thread = 1
    [C66xx_2] Hello World from thread = 2
    [C66xx_3] Hello World from thread = 3

Because the threads are executing on the cores concurrently, there is no
control over the order in which the output appears. But you should see
all of these lines.

.. rubric:: Tips on System Startup
   :name: tips-on-system-startup

If things do not go smoothly, please see the article
`SystemAnalyzerTutorial7 <http://processors.wiki.ti.com/index.php/SystemAnalyzerTutorial7>`__. That
article is about running a tutorial for a tool named Unified
Instrumentation Architecture (UIA). UIA is for analyzing system
performance and behavior. This tutorial contains several tips on how to
use CCS to run OpenMP programs. It is relevant to the versions of the
MCSDK components listed near the beginning.

.. rubric:: Second OpenMP Project
   :name: second-openmp-project

Now try another project like hello world, but a bit more complicated. It
will serve as the basis for your future OpenMP projects.

.. rubric:: Project Setup
   :name: project-setup-1

Start it the same way as the hello world project. But give it a
different name, look for *matrix* among the examples, and choose the
*OpenMP matrix vector multiplication example* for your system.

.. Image:: ../images/Omp_h5_matvec_setup.JPG

.. rubric:: Build and Execute
   :name: build-and-execute

All the remaining steps are the same as with the hello world project.

Upon executing, output in the console window should appear similar to
...

::

    [C66xx_0] 
    [C66xx_0] Starting values of matrix A and vector b:
    [C66xx_0]   A[0]= 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0   b[0]= 1.0
    [C66xx_0]   A[1]= 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0   b[1]= 2.0
    [C66xx_0]   A[2]= 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0   b[2]= 3.0
    [C66xx_0]   A[3]= 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0   b[3]= 4.0
    [C66xx_0]   A[4]= 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0   b[4]= 5.0
    [C66xx_0]   A[5]= 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0   b[5]= 6.0
    [C66xx_0]   A[6]= 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0   b[6]= 7.0
    [C66xx_0]   A[7]= 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0   b[7]= 8.0
    [C66xx_0]   A[8]= 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0   b[8]= 9.0
    [C66xx_0]   A[9]= 1.0 2.0 3.0 4.0 5.0 6.0 7.0 8.0 9.0 10.0   b[9]= 10.0
    [C66xx_0] 
    [C66xx_0] Results by thread/row:
    [C66xx_0]   thread 0 did row 0   c[0]=55.00 Running total= 55.00
    [C66xx_3]   thread 3 did row 9   c[9]=550.00    Running total= 605.00
    [C66xx_1]   thread 1 did row 3   c[3]=220.00    Running total= 825.00
    [C66xx_0]   thread 0 did row 1   c[1]=110.00    Running total= 935.00
    [C66xx_1]   thread 1 did row 4   c[4]=275.00    Running total= 1210.00
    [C66xx_2]   thread 2 did row 6   c[6]=385.00    Running total= 1595.00
    [C66xx_0]   thread 0 did row 2   c[2]=165.00    Running total= 1760.00
    [C66xx_1]   thread 1 did row 5   c[5]=330.00    Running total= 2090.00
    [C66xx_2]   thread 2 did row 7   c[7]=440.00    Running total= 2530.00
    [C66xx_2]   thread 2 did row 8   c[8]=495.00    Running total= 3025.00
    [C66xx_0] 
    [C66xx_0] Matrix-vector total - sum of all c[] = 3025.00
    [C66xx_0] 

The parts before and after *Results by thread/row* should match,
particularly the final result of 3025.00. The *thread N* lines will
vary, but there should be one line for each row 0-9.

.. rubric:: Start Your OpenMP Project
   :name: start-your-openmp-project

Build your OpenMP project out of the matrix multiply project. In the
**Project Explorer** window, select the matrix multiply project,
right-click and choose **Copy**. Right-click again and choose **Paste**.
Give the new project a name. It starts as a copy of the matrix multiply
project in every respect, except the name. Remove files, add files, and
make the project your own. Modifications to the omp_config.cfg file are
not required for base functionality.

.. rubric:: Debugging Tips
   :name: debugging-tips

Suppose you want to immediately execute one of those example projects
again. You need to reset the CPU cores, reload the program, and run
again. Here is a good way to do that.

In the **Debug** window, select cores 0-3, right-click and choose
**Group Core(s)**.

.. Image:: ../images/Omp_h6_group_cores.JPG

Now reset the cores in the newly formed group. Select the group and
click the **CPU Reset** icon near the top right of the **Debug** window.

CPU Reset icon

.. Image:: ../images/Omp_h7_cpu_reset.JPG

Then reload the program with the menu selection **Run \| Load \| Reload
Program**. Now you are ready to resume execution as before. Compare with
the output you got last time, and see how some lines are in a different
order.

.. rubric:: How to Obtain Support
   :name: how-to-obtain-support

Post your questions and suspected bugs to the `compiler
forum <http://e2e.ti.com/support/development_tools/compiler/f/343.aspx>`__
with the tag ``openmp``. Please use the tag. Use of the tag triggers an
e-mail to the current support team. Without the tag, the issue may go
unnoticed for some time.

.. raw:: html

