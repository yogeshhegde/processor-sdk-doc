.. _pru_getting_started_labs_lab_1:

Lab 1: How to Create a PRU Project
----------------------------------

.. contents:: :local:

.. rubric:: Introduction

This lab shows how to create a PRU project in CCS, or in the Linux terminal.
The CCS section and the Linux section are totally independent.

PRU projects that are developed in CCS require a computer with a screen (i.e.,
CCS development requires a graphical user interface, or GUI). These projects can
be developed on any computer that can run CCS (both Windows and Linux).
CCS provides additional tools for debugging PRU code like breakpoints,
memory browsers, etc.

PRU projects that are developed through the Linux terminal do not require
a display, so they can be run on a traditional Linux computer, through an SSH
connection to a remote server, etc. These PRU projects use Linux makefiles.
The steps for the Linux terminal sections will ONLY use the terminal (e.g.,
instead of opening a folder by clicking on it, use **$ cd** to change
directories).

In order to create a PRU project in CCS, follow section
:ref:`pru_getting_started_labs_creating_ccs_project`.

In order to create a PRU project using the Linux terminal, follow section
:ref:`pru_getting_started_labs_creating_linux_project`.


.. _pru_getting_started_labs_creating_ccs_project:

Creating a CCS PRU Project
^^^^^^^^^^^^^^^^^^^^^^^^^^

Install and Set up CCS
""""""""""""""""""""""

If the processor has a Processor MCU+ SDK:

  #. Reference the Processor MCU+ SDK documentation, section "Getting Started" >
     "Download, Install and Setup CCS".

  #. Follow the steps to ensure that CCS has been properly installed and set up.

  #. If section "Create Target Configuration" says to "Bypass not used CPUs",
     **do not bypass the ICSS / ICSS_G cores**. The CCS debugger cannot connect
     to a PRU core if it has been bypassed.

  #. Jump to section :ref:`pru_getting_started_labs_creating_ccs_project_create_the_project`

For AM65x:

  #. Reference the Processor SDK RTOS documentation, section
     "CCS Setup for AM65XX".

     .. note::

        These labs do not document initializing or debugging the PRU cores from
        AM65x cores running TI-RTOS. However, the "CCS Setup" section provides
        steps to prepare CCS to initialize the PRU cores.

  #. Jump to section :ref:`pru_getting_started_labs_creating_ccs_project_create_the_project`

For other processors:

 * Reference
   `the Code Composer Studio "Installation" documentation <https://software-dl.ti.com/ccs/esd/documents/users_guide/index_installation.html>`__.


.. _pru_getting_started_labs_creating_ccs_project_create_the_project:

Create the PRU Project
""""""""""""""""""""""

#. Launch CCS and select the default Workspace.

#. Create a new PRU project.

   #. Select **File -> New -> Project -> Code Composer Studio -> CCS Project**.
      Click **Next**.

   #. In the upper left dropdown next to "Target", select the target processor
      family. In the upper right dropdown, select the desired board.

      * AM335x example: Select **AM33xx - Cortex A8** in the upper left
        dropdown. Select **BeagleBone_Black** in the upper right dropdown.

      * AM62x & AM64x example: If a target processor family does
        not show up in the upper left dropdown, it may be hiding under
        **Unclassified Devices**. At the time of writing, after
        **Unclassified Devices** is selected in the left dropdown, boards
        like **AM64x_GP_EVM** can be selected in the
        right dropdown.

      * If your board is not defined, select the processor you are using in
        the second dropdown.

      .. note::

         AM62x: At the time of writing, the **PRU** tab populates for **AM62**, but not for
         **AM62_SK_EVM**. It is suggested to first select the AM62x board that the
         PRU code will run on. If a **PRU** tab does not show up below, then select
         **AM62** instead.

   #. Select the **PRU** tab. Specify a **Project Name (such as "pru_add")**.
   
   #. Verify that a Compiler version is listed (e.g., **TI v2.3.3**).

      .. note::

         If the PRU compiler is not currently installed, select the **Cancel** button.
         Go to **View->CCS App Center**. Select the **PRU Compiler**. Download the
         PRU compiler by selecting the **Install Software** button. Then redo the
         previous steps.
   
   #. Select an "Empty Projects" template. Select **Empty Project**.

      .. TODO: Add screenshot(s) here.

   #. Select **Finish**

Go to :ref:`pru_getting_started_labs_lab_2` to start writing the PRU firmware.


.. _pru_getting_started_labs_creating_linux_project:

Creating a Linux PRU Project
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

#. Navigate to the PSSP examples directory for your specific processor.

   * AM335x example:

     ::

         $ cd <PSSP_PATH>/examples/am335x

   * AM62x example:

     ::

         $ cd <PSSP_PATH>/examples/am62x

#. The PSSP is a git repo. Create a new development branch. Switch over to
   the new branch (i.e., "checkout" the new branch).

   ::
   
      $ git branch getting_started_labs
      $ git checkout getting_started_labs

#. Create a new project by copying one of the existing project folders.

   * Will the project use RPMsg to communicate with the Linux ARM core on the
     processor?

     * If yes, **copy the RPMsg_Echo project for whichever core you are programming**.

     * If no, **copy the Halt project**. The PRU Getting Started Labs do not
       use RPMsg.

   * Example: AM62x with RPMsg on PRU0, project name PRU_Add:

     ::
 
        $ cp -r PRU_RPMsg_Echo_Interrupt0 PRU_Add

   * Example: AM64x on RTU1, no RPMsg, project name RTU_Add:

     ::

        $ cp -r RTU_Halt RTU_Add

#. Check that the files were copied over properly:

   ::

      $ ls <source project>
      $ ls <destination project>

Go to :ref:`pru_getting_started_labs_lab_2` to start writing the PRU firmware.
