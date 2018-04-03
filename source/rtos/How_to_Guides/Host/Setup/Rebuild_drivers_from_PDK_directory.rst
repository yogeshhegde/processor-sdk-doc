.. http://processors.wiki.ti.com/index.php/Rebuilding_The_PDK 

.. rubric:: Overview
   :name: overview

Thee instructions below are for building for one platform. If you are
developing for multiple platforms (e.g., AM437x and AM335x), please
invoke builds in a serial fashion.

.. rubric:: Building PDK using gmake in Windows environment
   :name: building-pdk-using-gmake-in-windows-environment

The Windows environment must be setup using the pdksetupenv.bat script
provided within the PDK. The pdksetupenv.bat script has a set of default
configurations it will set if the script is run standalone without any
environment variables being set prior to script execution. The defaults
in the pdksetupenv.bat script assume all Processor SDK components have
been installed in the ``C:\ti`` directory, including CCS.

-  Navigate to pdk_[soc]_[version]/packages
-  Run pdksetupenv.bat

::

    C:\ti\pdk_[soc]_[version]\packages> pdksetupenv.bat

    Optional parameter not configured : CG_XML_BIN_INSTALL_PATH
    REQUIRED for xdc release build
    Example: set CG_XML_BIN_INSTALL_PATH=C:/ti/cg_xml/bin
    Optional parameter not configured : DOXYGEN_INSTALL_PATH
    REQUIRED for xdc release build
    Example: set DOXYGEN_INSTALL_PATH=C:/ti/Doxygen/doxygen/1.5.1-p1/bin
    **************************************************************************
    Environment Configuration:
        PDK Directory             : /ti/PDK_AM~3/packages/
        CGTOOL INSTALL Directory  : C:/ti/ccsv6/tools/compiler/ti-cgt-c6000_[version]
        TOOLCHAIN A15 Directory   : C:/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-[version]
        TOOLCHAIN A8 Directory    : C:/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-[version]
        TOOLCHAIN A9 Directory    : C:/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-[version]
        TOOLCHAIN M4 Directory    : C:/ti/ccsv6/tools/compiler/ti-cgt-arm_[version]
        FPULIB_PATH               : C:/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-[version]/lib/gcc/arm-none-eabi/[version]/fpu
        CROSS_TOOL_PRFX           : arm-none-eabi-
        XDC_INSTALL_PATH          : C:/ti/xdctools_[version]_core
        BIOS_INSTALL_PATH         : C:/ti/bios_[version]
        IPC_INSTALL_PATH          : C:/ti/ipc_[version]
        EDMA3LLD_BIOS6_INSTALLDIR : C:/ti/edma3_lld_[version]
        NDK_INSTALL_PATH          : C:/ti/ndk_[version]
        IMGLIB_INSTALL_PATH       : C:/ti/imglib_c66x_[version]
        UIA_INSTALL_PATH          : C:/ti/uia_[version]
    **************************************************************************
    Changing to short name to support directory names containing spaces
    current directory: /ti/PDK_AM~3/packages/
    PDK BUILD ENVIRONMENT CONFIGURED
    **************************************************************************

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**

-  The PDK package uses ARM Linaro compiler for the A15/A9/A8 core, TI
   ARM Compiler 5.x for M4/IPU and TI Compiler for C66x core.
-  The pdksetupenv.bat requires *path2dos.exe* utility available from
   XDC tools. If *path2dos.exe* is not available in the build
   environment then short names for paths **SHOULD** be provided to
   environment variables e.g. *C:/ti/PDK_AM~2/packages*. In Windows
   environment, "dir /x" and "dir /-n" displays the short names
   generated for non-8dot3 file and directory names.

.. raw:: html

   </div>
   
-  After the build environment has been configured, the entire PDK, or
   individual components, can be rebuilt through the top-level makefile
   in pdk_[soc]_[version]/packages

All PDK components can be cleaned and rebuilt with the following
commands:

::

    C:\ti\pdk_[soc]_[version]\packages>gmake clean
    C:\ti\pdk_[soc]_[version]\packages>gmake all

Individual PDK components can be cleaned and rebuilt with the following
commands:

::

    C:\ti\pdk_[soc]_[version]\packages>gmake <component>_clean
    C:\ti\pdk_[soc]_[version]\packages>gmake <component>

    Example:

    C:\ti\pdk_[soc]_[version]\packages>gmake i2c_clean
    C:\ti\pdk_[soc]_[version]\packages>gmake i2c

PDK users can invoke the build for specific core and specific platform
using the following syntax. This will help save lot of build time on
heterogeneous platforms with ARM, DSP and IPU cores or on platforms
where multiple Evaluation platforms are supported.

::

    gmake LIMIT_BOARDS="<BOARD>" LIMIT_SOCS="<SOC>" LIMIT_CORES="<CORE>"

-  SOC can be am335x, am437x, am571x, am572x, k2g,k2h,k2e, etc.
-  CORE can be “a15_0”, “c66x”, or “ipu1_0”, for a15, c66, m4
   respectively.
-  BOARD can be any evaluation hardware platform that your SOC supports.

For Example:

To build only, ARM version of evmAM572x board library

::

    gmake LIMIT_BOARDS="evmAM572x" LIMIT_SOCS="am572x" LIMIT_CORES="a15_0"  

To build only, DSP version of evmK2G board library

::

    gmake LIMIT_BOARDS="evmK2G" LIMIT_SOCS="k2g" LIMIT_CORES="dsp_0" 

| 

| 

.. rubric:: Building PDK using make in Linux environment
   :name: building-pdk-using-make-in-linux-environment

The Linux environment must be setup using the pdksetupenv.sh script
provided within the PDK. The pdksetupenv.sh script has a set of default
configurations it will set if the script is run standalone without any
environment variables being set prior to script execution. The defaults
in the pdksetupenv.sh script assume all Processor SDK components have
been installed in the ``~/ti`` directory, including CCS.

-  Navigate to pdk_[soc]_[version]/packages
-  Run pdksetupenv.sh

::

    ~/ti/pdk_[soc]_[version]/packages$ source pdksetupenv.sh

    Optional parameter not configured : CG_XML_BIN_INSTALL_PATH
    REQUIRED for xdc release build
    Example: export CG_XML_BIN_INSTALL_PATH="~/ti/cg_xml/bin"
    Optional parameter not configured : DOXYGEN_INSTALL_PATH
    REQUIRED for xdc release build
    Example: export DOXYGEN_INSTALL_PATH="~/ti/Doxygen/doxygen/1.5.1-p1/bin"
    **************************************************************************
    Environment Configuration:
        PDK Directory             : /home/[user]/ti/pdk_[soc]_[version]/packages
        CGTOOL INSTALL Directory  : /home/[user]/ti/ccsv6/tools/compiler/ti-cgt-c6000_[version]
        TOOLCHAIN A15 Directory   : /home/[user]/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-[version]
        TOOLCHAIN A8 Directory    : /home/[user]/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-[version]
        TOOLCHAIN A9 Directory    : /home/[user]/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-[version]
        TOOLCHAIN M4 Directory    : /home/[user]/ti/ccsv6/tools/compiler/ti-cgt-arm_[version]
        FPULIB_PATH               : /home/[user]/ti/ccsv6/tools/compiler/gcc-arm-none-eabi-[version]/lib/gcc/arm-none-eabi/[version]/fpu
        CROSS_TOOL_PRFX           : arm-none-eabi-
        XDC_INSTALL_PATH          : /home/[user]/ti/xdctools_[version]_core
        BIOS_INSTALL_PATH         : /home/[user]/ti/bios_[version]
        IPC_INSTALL_PATH          : /home/[user]/ti/ipc_[version]
        EDMA3LLD_BIOS6_INSTALLDIR : /home/[user]/ti/edma3_lld_[version]
        NDK_INSTALL_PATH          : /home/[user]/ti/ndk_[version]
        IMGLIB_INSTALL_PATH       : /home/[user]/ti/imglib_c66x_[version]
        UIA_INSTALL_PATH          : /home/[user]/ti/uia_[version]
    PDK BUILD ENVIRONMENT CONFIGURED
    *******************************************************************************

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
The PDK package uses ARM Linaro compiler for the A15/A9/A8 core, TI ARM
Compiler 5.x for M4/IPU and TI Compiler for C66x core.

.. raw:: html

   </div>

-  After the build environment has been configured, the entire PDK, or
   individual components, can be rebuilt through the top-level makefile
   in pdk_[soc]_[version]/packages

All PDK components can be cleaned and rebuilt with the following
commands:

::

    ~/ti/pdk_[soc]_[version]/packages$ make clean
    ~/ti/pdk_[soc]_[version]/packages$ make all

Individual PDK components can be cleaned and rebuilt with the following
commands:

::

    ~/ti/pdk_[soc]_[version]/packages$ make <component>_clean
    ~/ti/pdk_[soc]_[version]/packages$ make <component>

    Example:

    ~/ti/pdk_[soc]_[version]/packages$ make i2c_clean
    ~/ti/pdk_[soc]_[version]/packages$ make i2c

PDK users can invoke the build for specific core and specific platform
using the following syntax. This will help save lot of build time on
heterogeneous platforms with ARM, DSP and IPU cores or on platforms
where multiple Evaluation platforms are supported.

::

    make LIMIT_BOARDS="<BOARD>" LIMIT_SOCS="<SOC>" LIMIT_CORES="<CORE>"

-  SOC can be am335x, am437x, am571x, am572x, k2g,k2h,k2e, etc.
-  CORE can be “a15_0”, “c66x”, or “ipu1_0”, for a15, c66, m4
   respectively.
-  BOARD can be any evaluation hardware platform that your SOC supports.

For Example:

To build only, ARM version of evmAM572x board library

::

    make LIMIT_BOARDS="evmAM572x" LIMIT_SOCS="am572x" LIMIT_CORES="a15_0"  

To build only, DSP version of evmK2G board library

::

    make LIMIT_BOARDS="evmK2G" LIMIT_SOCS="k2g" LIMIT_CORES="dsp_0" 

.. rubric:: PDK Example and Test Project Creation
   :name: pdk-example-and-test-project-creation

The PDK contains Windows and Linux scripts used to create example and
test CCS projects for all PDK sub-components. The following steps detail
how the scripts are used to create CCS project content.

-  Ensure all dependent/prerequisite products are installed and
   registered with CCS before proceeding with the examples and/or unit
   test. Starting CCS after installing the Processor SDK products will
   cause CCS to find and register any new products. Errors will occur
   during PDK project creation if any dependent products have not been
   registered with CCS.
-  Navigate to *pdk_[soc]_[version]\packages*
-  [**Optional**] Edit the product versions within the pdkProjectCreate
   script. The default settings in the pdkProjectCreate script will have
   the product versions installed with the PDK. The pdkProjectCreate
   script can be modified to use older or newer product versions based
   on the user's development environment. 
  
**Note:** Project compilation and successful execution cannot be 
  guaranteed for products not installed with the PDK.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**

-  If the CCS installation is located somewhere other than "C:\ti",
   ensure that the pdkProjectCreate script has this location correctly
   specified by updating the CCS_INSTALL_PATH or set TOOLS_INSTALL_PATH
   variable
-  You may see errors (failed to start server) during the running of the
   script if an instance of CCS is running, so please ensure that CCS is
   closed prior to running the pdkProjectCreate script
-  When soc is "AM572x" and board is "all", the script uses evmAM572x as
   the default platform. Please specify board to idkAM572x to create the
   project for AM572x IDK EVM.
-  Run the pdkProjectCreate script. The script takes parameters which
   allow targeted creation of PDK example and test project content.
   Below are the command formats for Window's pdkProjectCreate.bat and
   Linux's pdkProjectCreate.sh:

.. raw:: html

   </div>

::

    Windows Usage:
      pdkProjectCreate.bat [soc] [board] [endian] [module] [project type] [processor] [pdkDir]

     Description:     (first option is default)
      soc         -   AM335x / AM437x / AM571x / AM572x / K2E / K2G / K2K / K2H / K2L /
                      C6678 / C6657 / DRA72x / DRA75x / DRA78x / OMAPL137 / OMAPL138
      board       -   all (use "all" for K2X and C66X SOCs)
                      -or-
                      Refer to pdk_<soc>_<version>\packages\ti\board\lib
                      for valid board inputs for the soc
      endian      -   little / big
      module      -   all
                      -or-
                      aif2 / bcp / cppi / csl / dfe / emac / fatfs / fm / fftc / 
                      gpio / hyplnk / i2c / icss_emac / iqn2 / mcasp / mcbsp / mmap / mmcsd /
                      nimu / nimu_icss / nwal / osal / pa / pcie / pktlib / pruss / qm / rm /
                      sa /serdes-diag / spi / srio / tcp3d / tfw / transportqmss /
                      transportsrio / tsip / uart / usb / wdtimer / vps
      project type -  all / example / test
      processor   -   arm / dsp / m4
      pdkDir      -   THIS FILE LOCATION / "C:\ti\pdk_<soc>_<version>\packages"

     Example:
      a) pdkProjectCreate.bat
                  - Creates all module projects for the AM335x soc for arm little endian
      b) pdkProjectCreate.bat AM437x
                  - Creates all module projects for the AM437x soc for arm little endian
      c) pdkProjectCreate.bat AM437x idkAM437x
                  - Creates all module projects for idkAM437x device for arm little endian
      d) pdkProjectCreate.bat AM571x evmAM571x little
                  - Creates all module projects for evmAM571x device for arm little endian
      e) pdkProjectCreate.bat AM571x evmAM571x little i2c all dsp
                  - Creates all i2c module projects for evmAM571x device for dsp little endian
      f) pdkProjectCreate.bat K2H all little i2c example arm
                  - Creates i2c module example projects for K2H device for arm little endian
      g) pdkProjectCreate.bat C6678 all little hyplnk test dsp
                  - Creates hyplnk module test projects for C6678 device for dsp little endian
      h) pdkProjectCreate.bat OMAPL138 all little uart all dsp
                  - Creates all uart module projects for C6748 and OMAPL138 device for dsp little endian

::

    Linux Usage:
     pdkProjectCreate.sh [soc] [board] [endian] [module] [project type] [processor]
     
      Description:    (first option is default)
      soc         -   AM335x / AM437x / AM571x / AM572x / K2E / K2G / K2K / K2H / K2L /
                      C6678 / C6657 / DRA72x / DRA75x / DRA78x / OMAPL137 / OMAPL138
      board       -   all (use "all" for K2X and C66X SOCs)
                      -or-
                      Refer to pdk_<soc>_<version>\packages\ti\board\lib
                      for valid board inputs for the soc
      endian      -   little / big
      module      -   all
                      -or-
                      aif2 / bcp / cppi / csl / dfe / emac / fatfs / fm / fftc /
                      gpio / hyplnk / i2c / icss_emac / iqn2 / mcasp / mcbsp / mmap / mmcsd /
                      nimu / nimu_icss / nwal / osal / pa / pcie / pktlib / pruss / qm / rm /
                      sa / serdes-diag / spi / srio / tcp3d / tfw / transportqmss /
                      transportsrio / tsip / uart / usb / wdtimer / vps
      project type -  all / example / test
      processor   -   arm / dsp / m4
     
      Example:
       a) pdkProjectCreate.sh
                   - Creates all module projects for the AM335x soc for arm little endian
       b) pdkProjectCreate.sh AM437x
                   - Creates all module projects for the AM437x soc for arm little endian
       c) pdkProjectCreate.sh AM437x idkAM437x
                   - Creates all module projects for idkAM437x device for arm little endian
       d) pdkProjectCreate.sh AM571x evmAM571x little
                   - Creates all module projects for evmAM571x device for arm little endian
       e) pdkProjectCreate.sh AM571x evmAM571x little i2c all dsp
                   - Creates all i2c module projects for evmAM571x device for dsp little endian
       f) pdkProjectCreate.sh K2H all little i2c example arm
                   - Creates i2c module example projects for K2H device for arm little endian
       g) pdkProjectCreate.sh C6678 all little hyplnk test dsp
                   - Creates hyplnk module test projects for C6678 device for dsp little endian
       h) pdkProjectCreate.sh OMAPL138 all little uart all dsp
                   - Creates all uart module projects for C6748 and OMAPL138 device for dsp little endian

Please note the "module" in above examples may not be showing the full
list. Please refer to pdkProjectCreate.bat (windows) or
pdkProjectCreate.sh (Linux) to get the correct list of "modules" being
supported on a particular device with a particular software release.

The scripts will throw errors for invalid input parameters and for
invalid configurations. For example, attempting to build DSP projects
for the am335x device will throw an error since the am335x device does
not contain a DSP processor.

-  The script will search all PDK sub-directories for example and test
   project files matching the pdkProjectCreate input parameters. CCS
   projects created during the search will be placed into an centralized
   CCS project folder. By default this folder is
   C:\ti\pdk_[soc]_[version]\packages\MyExampleProjects\\ in Windows and
   ~/ti/pdk_[soc]_[version]/packages/MyExampleProjects/ in Linux.

| 

.. rubric:: Steps to run example and/or unit test projects on C66x/A15
   Target
   :name: steps-to-run-example-andor-unit-test-projects-on-c66xa15-target

#. **Import Project**
   Below are the steps for importing project assumes that CCS project is
   already available.

   #. Select C/C++ Development perspective
   #. Click on File -> Import
   #. On the Import Dialog Box select Existing CCS/CCE Eclipse Project
   #. Click on Next
   #. This will pop up a new dialog box; ensure that 'Select Root
      Directory' option is selected
   #. Click on Browse and select the top level directory where the
      project is present. For example

      ::

          C:\ti\pdk_[soc]_[version]\packages\MyExampleProjects\

   #. Under the projects section you should see the project. For example

      ::

          GPIO_LedBlink_evmAM572x_c66xExampleProject

   #. Click Finish

#. **Build Project**

   #. To build the project; ensure that the project you want to build,
      i.e., **GPIO_LedBlink_evmAM572x_c66xExampleProject** is set as the
      active project. Click on Project -> Build Active Project.Naming
      convention of Projects created:

      ::

          <Module>_<exampleName>_<BOARD>_<Processor>TestProject or <Module>_<exampleName>_<BOARD>_<Processor>ExampleProject

      ::

          Eg GPIO_LedBlink_evmAM572x_c66xExampleProject, I2C_BasicExample_evmAM572x_armTestProject

#. **Run Project**

   #. Launch the Debugger and switch to the Debug Perspective.
   #. To execute the project ensure the following is done:

      #. Click on Target -> Reset CPU
      #. Click on Target -> Load Program
      #. Select the executable file to be loaded. Example:

	  ::

         C:\ti\pdk_[soc]_[version]\packages\MyExampleProjects\GPIO_LedBlink_AM572X_GpEvm_c66xExampleProject\Debug\GPIO_LedBlink_evmAM572x_c66xExampleProject.out

      #. Click on OK.
      #. Once the project is loaded; click on Target -> Run to execute
         it.</pre>

| 

.. raw:: html

