.. _pru_getting_started_labs_initialize_from_rtos:

Initializing the PRU from a TI-RTOS Core (Legacy)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

.. note::

   The PRU Getting Started Labs do not cover TI-RTOS cores controlling the PRU.
   TI-RTOS SDKs are available for the following processors: AM335x, AM437x, AM57x, AM65x.
   Some legacy information is provided here for AM335x, AM437x, AM57x customers
   using PROCESSOR-SDK-RTOS 6.3. **HOWEVER**, this information has not been
   tested or validated in several years. These steps are provided as-is. TI
   cannot answer questions about these steps. Because of the lack of support,
   These sections are marked as **legacy**.

   TI no longer provides support for TI-RTOS / baremetal SW development for
   AM335x & AM437x. `See this notice for more information.
   <https://e2e.ti.com/support/processors-group/processors/f/processors-forum/1071334/notice-regarding-processor-sdk-ti-rtos-for-am335x-am437x-omap-l13x-c674x-k2g-devices>`__


#. Launch CCS and open a Workspace

#. Go to **File > New > CCS Project**

#. Select your **Target** in the first dropdown menu and your **Board** in the
   second dropdown menu. Select your Connection in the third dropdown menu.


#. Select the **Cortex A [ARM] tab** and give your project a name. Select the
   **GNU (Linaro)** compiler.

#. Under **Project templates and examples** select **SYS/BIOS** and then
   **GNU Target Examples** and finally **Typical**.

.. .. figure:: ../images/PRURTOSScreenshot1.png
..    :scale: 70%

..    Screenshot of sample CCS settings for a PRU loading project

#. Select **Next >**. Under **Products and Repositories** select **<processor> PDK**,
   **SYS/BIOS**, and **XDAIS**.

#. Select the **Platform** that you're using from the drop down menu.

.. .. figure:: ../images/PRURTOSScreenshot10.png
..     :scale: 70%

..    Screenshot of sample libraries selected for a PRU loading project on the BeagleBone Black Platform

#. Right click the project folder in the **Project Explorer**. Select **Properties**
   from the drop down menu. Select **CCS Build > GNU Linker > Libraries**

#. Select **Add...** in the top bar of the **Libraries** box. Click **Browse**.
   Navigate to:
   **<PDK Directory>/packages/ti/osal/lib/tirtos/<processor>/<ARM core>/release**.
   You should see a file titled **ti.osal.a<ARM core>fg**. If you don't see the
   file, make sure you're browsing all file types. Select that file.

.. note::

   For AM335x / AM437x / AM572x, ARM core is a8 / a9 / a15, and the file
   is named **ti.osal.aa8fg** / **ti.osal.aa9fg** / **ti.osal.aa15fg**.

.. .. figure:: ../images/PRURTOSScreenshot4.png
..     :scale: 70%

..     Screenshot of the library screen in the GNU Linker for a PRU loading project

#. Open your **app.cfg** file in the project. Copy the code found in
   **pru-software-support-package/Getting_Started_Labs/PRU_FROM_RTOS/app<processor>.cfg**
   into your **app.cfg**:

.. TODO: Did I keep this PRU_FROM_RTOS folder?

There are a few things that should be noted in this configuration file. Jump to the
section for the processor that you are using:

 * :ref:`pru_getting_started_labs_initialize_from_rtos_am335x_code`
 * :ref:`pru_getting_started_labs_initialize_from_rtos_am437x_code`
 * :ref:`pru_getting_started_labs_initialize_from_rtos_am572x_code`

.. _pru_getting_started_labs_initialize_from_rtos_am335x_code:

.. rubric:: AM335x Configuration File

.. code-block:: cfg

  var Mmu = xdc.useModule('ti.sysbios.family.arm.a8.Mmu');
  Mmu.enableMMU = true;

  /* Force peripheral section to be NON cacheable strongly-ordered memory */
  var peripheralAttrs = {
  type : Mmu.FirstLevelDesc_SECTION, // SECTION descriptor
  tex: 1,
  bufferable : false,                // bufferable
  cacheable  : false,                // cacheable
  shareable  : false,                // shareable
  noexecute  : true,                 // not executable
  };

  /* Define the base address of the 1 Meg page the peripheral resides in. */
  var peripheralBaseAddr = 0x4A300000;

  /* Configure the corresponding MMU page descriptor accordingly */
  Mmu.setFirstLevelDescMeta(peripheralBaseAddr,
                        peripheralBaseAddr,
                        peripheralAttrs);


In the above code: **Mmu.enableMMU = true;** enables the MMU. **Mmu.setFirstLevelDescMeta**
sets the page of memory starting at **peripheralBaseAddr** to be non cacheable as
described in **peripheralAttrs**.

.. code-block:: cfg

  var socType           = "am335x";

  /* Load the PRUSS package */
  var Pruss = xdc.loadPackage('ti.drv.pruss');
  Pruss.Settings.socType = socType;

  /* Load the uart package */
  var Uart              = xdc.loadPackage('ti.drv.uart');
  Uart.Settings.socType = socType;

  /*use CSL package*/
  var Csl = xdc.loadPackage('ti.csl');
  Csl.Settings.deviceType = socType;

  /* Load the board package */
  var Board = xdc.loadPackage('ti.board');
  Board.Settings.boardName = "<YOUR_BOARD_HERE>";

The above configuration code loads in the modules neccesary to load the PRU from the A8.

Click here to move on to the next step:
:ref:`pru_getting_started_labs_initialize_from_rtos_continue`.


.. _pru_getting_started_labs_initialize_from_rtos_am437x_code:

.. rubric:: AM437x Configuration File

.. code-block:: cfg

    var Mmu = xdc.useModule('ti.sysbios.family.arm.a8.Mmu');
    Mmu.enableMMU = true;

    var peripheralAttrs = {
      type : Mmu.FirstLevelDesc_SECTION, // SECTION descriptor
      tex: 0,
      bufferable : false,                // bufferable
      cacheable  : false,                // cacheable
      shareable  : false,                // shareable
      noexecute  : true,                 // not executable
    };




    /* Define the base address of the 1 Meg page the peripheral resides in. */
    var peripheralBaseAddr = 0x54400000;

    /* Configure the corresponding MMU page descriptor accordingly */
    Mmu.setFirstLevelDescMeta(peripheralBaseAddr,
                            peripheralBaseAddr,
                            peripheralAttrs);

    System.SupportProxy = SysMin;

**Mmu.enableMMU = true;** enables the MMU. **Mmu.setFirstLevelDescMeta**
sets the page of memory starting at **peripheralBaseAddr** to be non cacheable as
described in **peripheralAttrs**. There is a quirk here where
the A9 uses the A8's MMU configuration. This is intended.

.. code-block:: cfg

  var socType           = "am437x";

  /* Load the PRUSS package */
  var Pruss = xdc.loadPackage('ti.drv.pruss');
  Pruss.Settings.socType = socType;

  /* Load the uart package */
  var Uart              = xdc.loadPackage('ti.drv.uart');
  Uart.Settings.socType = socType;

  /*use CSL package*/
  var Csl = xdc.loadPackage('ti.csl');
  Csl.Settings.deviceType = socType;

  /* Load the board package */
  var Board = xdc.loadPackage('ti.board');
  Board.Settings.boardName = "<YOUR_BOARD_HERE>";

The above configuration code loads in the modules neccesary to load the PRU from the A9.

Click here to move on to the next step:
:ref:`pru_getting_started_labs_initialize_from_rtos_continue`.


.. _pru_getting_started_labs_initialize_from_rtos_am572x_code:

.. rubric:: AM572x Configuration File

.. code-block:: cfg

  var socType           = "am572x";

  /* Load the PRUSS package */
  var Pruss = xdc.loadPackage('ti.drv.pruss');
  Pruss.Settings.socType = socType;

  /* Load the uart package */
  var Uart              = xdc.loadPackage('ti.drv.uart');
  Uart.Settings.socType = socType;

  /*use CSL package*/
  var Csl = xdc.loadPackage('ti.csl');
  Csl.Settings.deviceType = socType;

  /* Load the board package */
  var Board = xdc.loadPackage('ti.board');
  Board.Settings.boardName = "<YOUR_BOARD_HERE>";

The above configuration code loads in the modules neccesary to load the PRU from the A15.

.. _pru_getting_started_labs_initialize_from_rtos_continue:

.. rubric:: Continue

#. Board options for <YOUR_BOARD_HERE> can be found in <PDK>/Packages/ti/board/src.
   Change <YOUR_BOARD_HERE> to be one of those options listed.

#. You will need the PRU program that you wish to load to be in hex array format
   as a .h file that is included in your project folder. Instructions on how to do
   that can be found above in the :ref:`pru_getting_started_labs_compiling_to_hex_array_file`
   section.

.. TODO: Update the link to the "compiling to a hex array section". If I didn't write
   that section, did Max put it somewhere and I accidentally deleted it?

.. .. include:: ../common/PRU-ICSS/PRU_Load_Snippet.rst

#. You'll need to create a **target configuration** file in order to launch your board
    and initialize PRU-ICSS. You can do this by navigating to
    **Window > Show Viewv > Target Configurations**.
    Then select **New Target Configuration File**. Select your Board and Connection
    type and select **save**.

.. .. figure:: ../images/PRURTOSScreenshot9.png
..     :scale: 70%

..     Screenshot of a sample Target Configuration File setup screen for the BeagleBone Black.

#. Right-click the newly created .ccxml file and select **Launch selected configuration**

#. **Connect** to the Cortex A core, **Reset** the CPU, and then navigate to
   **Scripts > PRU_ICSS > PRU_ICSS_INIT** for AM335x & AM437x, or
   **Scripts > AM572X MULTICORE Initialization > AM572X_MULTICORE_EnableAllCores**
   for AM572x. Select the init script.

#. **Load** the PRU program and run it.

#. **Connect** to the PRU (for AM335x), or to a PRU in PRU-ICSS0 (for AM437x &
    AM572x). Pause the PRU. Navigate to **Window > Show View > Disassembly** and select it.

.. .. figure:: ../images/PRURTOSScreenshot14.png
..     :scale: 70%

..     All of the selections that you need to make are highlighted. Hover over each
..     one to see what it does.

#. The PRU Program that you compiled into a hex array should now appear in the
   IRAM of the PRU.

