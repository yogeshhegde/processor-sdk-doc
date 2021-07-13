.. http://processors.wiki.ti.com/index.php/Rebuilding_The_PDK 

Overview
^^^^^^^^

The instructions below are for building for one platform. If you are
developing for multiple platforms (e.g., AM437x and AM335x), please
invoke builds in a serial fashion.

Building PDK using gmake in Windows environment
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The build environment for windows must be setup providing RULES_MAKE
macro with the location of the top level Rules.make file. Additionally the
environment PATH variable must be updated with the install location of
gmake binary. The build environemnt shall also be set running pdksetupenv
script file provided within the PDK. The build/Rules.make has all the set
of default configurations. The defaults in the Rules.make assume all
Processor SDK components have been installed in the SDK_INSTALL_PATH
location .

-  In command prompt navigate to *pdk_[soc]_[version]/packages*
-  Run pdksetupenv.bat

::

    C:\ti\pdk_[soc]_[version]\packages> pdksetupenv.bat

-  Alternatively set RULES_MAKE and PATH variable for Windows..

::

    > set RULES_MAKE = C:/ti/pdk_[soc]_[version]/packages/Rules.make
    > set PATH=%PATH%;C:/ti/xdc_[xdc_version]

.. note::
   -  The PDK package uses ARM Linaro compiler for the A15/A9/A8 core, TI
      ARM Compiler for M4/IPU and TI Compiler for C66x core.

-  After the build environment has been configured, the entire PDK, or
   individual components, can be rebuilt through the top-level makefile
   in pdk_[soc]_[version]/packages

All PDK components can be cleaned and rebuilt with the following
commands:

::

    C:\ti\pdk_[soc]_[version]\packages>gmake clean
    C:\ti\pdk_[soc]_[version]\packages>gmake all

Please note that the user can specify parallelism with the make option -j to reduce 
the build time for targets 'all' and 'clean'. For example,

::

    C:\ti\pdk_[soc]_[version]\packages>gmake clean -j4
    C:\ti\pdk_[soc]_[version]\packages>gmake all -j4

Individual PDK components can be cleaned and rebuilt from within the component's directory 
with the following commands

::

    cd  C:\ti\pdk_[soc]_[version]\packages\ti\<component>
    C:\ti\pdk_[soc]_[version]\packages\ti\<component>gmake clean
    C:\ti\pdk_[soc]_[version]\packages\ti\<component>gmake all

    Example:

    cd C:\ti\pdk_[soc]_[version]\packages\ti\drv\i2c
    C:\ti\pdk_[soc]_[version]\packages\ti\drv\i2c>gmake clean
    C:\ti\pdk_[soc]_[version]\packages\ti\drv\i2c>gmake all

Please note that parallel make (-j4) is not supported within individual 
PDK components. It is supported only at the top level (C:\\ti\\pdk_[soc]_[version]\\packages)
for targets 'all' and 'clean'

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


Building PDK using make in Linux environment
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The Linux environment shall be setup by exporting RULES_MAKE variable with
the location of top level Rules.make or by using the pdksetupenv.sh script
provided within the PDK. The Rules.make has a set of default configurations
The defaults in the Rules.make script assume all Processor SDK components have
been installed in the SDK_INSTALL_PATH directory.

-  Navigate to *pdk_[soc]_[version]/packages*
-  Run pdksetupenv.sh

::

    ~/ti/pdk_[soc]_[version]/packages$ source pdksetupenv.sh

-  Alternatively the RULES_MAKE variable can be exported from the command line.

::

    $ export RULES_MAKE = /home/ti/pdk_[soc]_[version]/packages/Rules.make

.. note::
   The PDK package uses ARM Linaro compiler for the A15/A9/A8 core, TI ARM
   Compiler for M4/IPU and TI Compiler for C66x core.

-  After the build environment has been configured, the entire PDK, or
   individual components, can be rebuilt through the top-level makefile
   in pdk_[soc]_[version]/packages

All PDK components can be cleaned and rebuilt with the following
commands:

::

    ~/ti/pdk_[soc]_[version]/packages$ make clean
    ~/ti/pdk_[soc]_[version]/packages$ make all

Please note that the user can specify parallelism with the make option -j to reduce 
the build time for targets 'all' and 'clean'. For example,

::

    ~/ti/pdk_[soc]_[version]/packages$ make clean -j4
    ~/ti/pdk_[soc]_[version]/packages$ make all -j4

Individual PDK components can be cleaned and rebuilt from within the components' directory as below

::

    cd ~/ti/pdk_[soc]_[version]/packages/ti/drv/<component>
    ~/ti/pdk_[soc]_[version]/packages/ti/<component>$ make clean
    ~/ti/pdk_[soc]_[version]/packages/ti/<component>$ make all

    Example:
    cd ~/ti/pdk_[soc]_[version]/packages/ti/drv/i2c
    ~/ti/pdk_[soc]_[version]/packages/ti/drv/i2c$ make clean
    ~/ti/pdk_[soc]_[version]/packages/ti/drv/i2c$ make all

Please note that parallel make (-j) is not supported within individual 
PDK components. It is supported only at the top level (~/ti/pdk_[soc]_[version]/packages)
for targets 'all' and 'clean'

PDK users can invoke the build for specific core and specific platform
using the following syntax. This will help save lot of build time on
heterogeneous platforms with ARM, DSP and IPU cores or on platforms
where multiple Evaluation platforms are supported.

::

    make LIMIT_BOARDS="<BOARD>" LIMIT_SOCS="<SOC>" LIMIT_CORES="<CORE>"

-  LIMIT_SOCS can be am335x, am437x, am571x, am572x, k2g,k2h,k2e, etc.
-  LIMIT_CORES can be “a15_0”, “c66x”, or “ipu1_0”, for a15, c66, m4
   respectively.
-  LIMIT_BOARDS can be any evaluation hardware platform that your SOC supports.

Please issue "make help" to list the LIMIT_SOCS/LIMIT_CORES/LIMIT_BOARDS supported.

For Example:

To build only, ARM version of evmAM572x board library

::

    make LIMIT_BOARDS="evmAM572x" LIMIT_SOCS="am572x" LIMIT_CORES="a15_0"  

To build only, DSP version of evmK2G board library

::

    make LIMIT_BOARDS="evmK2G" LIMIT_SOCS="k2g" LIMIT_CORES="c66x" 



Building PDK components from git repo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The components PDK can be rebuilt from their git repositories. This is especially useful for development and/or picking up some bug fixes since the previous release.
Below are the steps on how to set up a development environment with the git repositories
-  Install the most recent version of processor-sdk
-  Replace ~/processor-sdk-installation-dir/pdk_<soc>_<version>  with the PDK git repository https://git.ti.com/cgit/processor-sdk/pdk/

::

   cd ~/ti/<procsdk_install_dir>/
   git clone  https://git.ti.com/git/processor-sdk/pdk.git

- Clone the PDK components which were present in pdk_<soc>_<version> and  not in the pdk.git. This includes components like csl,sa,pm etc.

::

   cd ~/ti/<procsdk_install_dir>/pdk/packages/ti/
   git clone https://git.ti.com/git/keystone-rtos/common-csl-ip.git csl
   cd drv
   git clone https://git.ti.com/git/keystone-rtos/pm-lld.git pm
   git clone https://git.ti.com/git/keystone-rtos/sa-lld.git sa

- Set up the development environment with the appropriate PDK_SOC (PDK_SOC is the <soc> field in the pdk_<soc>_<version> directory  which was replaced by pdk.git)

::

   cd ~/ti/<procsdk_install_dir>/pdk/packages/
   export PDK_SOC=<soc>     //NOTE:PDK_SOC is the <soc> field in the pdk_<soc>_<version> directory  which was replaced by pdk.git
   source ./pdksetupenv.sh

- Re-build the libraries
::

   make all -j4

.. note::
   When updating PDK for picking up bug fixes or for development, please be aware that the supporting components like tools versions might have changed since the previous release.The tools versions used by PDK are specified in pdk/packages/ti/build/pdk_tools_path.mk . Please ensure that those are downloaded in the processor sdk installation directory.
  

PDK Example and Test Project Creation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The PDK contains Windows and Linux scripts used to create example and
test CCS projects for all PDK sub-components. The following steps detail
how the scripts are used to create CCS project content.

-  Ensure all dependent/prerequisite products are installed and
   registered with CCS before proceeding with the examples and/or unit
   test. Starting CCS after installing the Processor SDK products will
   cause CCS to find and register any new products. Errors will occur
   during PDK project creation if any dependent products have not been
   registered with CCS.
-  Navigate to *pdk_[soc]_[version]/packages*
-  [**Optional**] Edit the product versions within the pdkProjectCreate
   script. The default settings in the pdkProjectCreate script will have
   the product versions installed with the PDK. The pdkProjectCreate
   script can be modified to use older or newer product versions based
   on the user's development environment. 
  
.. note::
   Project compilation and successful execution cannot be
   guaranteed for products not installed with the PDK.

.. note::

   -  If the CCS installation is located somewhere other than "C:\\ti",
      ensure that the pdkProjectCreate script has this location correctly
      specified by updating the CCS_INSTALL_PATH or set TOOLS_INSTALL_PATH
      variable
   -  You may see errors (failed to start server) during the running of the
      script if an instance of CCS is running, so please ensure that CCS is
      closed prior to running the pdkProjectCreate script
   -  When soc is "AM572x" and board is "all", the script uses evmAM572x as
      the default platform. Please specify board to idkAM572x to create the
      project for AM572x IDK EVM.
   -  Run the pdksetupenv script to setup the PDK and SDK path variables
   -  Run the pdkProjectCreate script. The script takes parameters which
      allow targeted creation of PDK example and test project content.
      Below are the command formats for Window's pdkProjectCreate.bat and
      Linux's pdkProjectCreate.sh:

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
                      transportsrio / tsip / uart / usb / wdtimer / vps / dcan / dss / lcdc
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
                      transportsrio / tsip / uart / usb / wdtimer / vps / dcan / dss / lcdc
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
   C:\\ti\\pdk_[soc]_[version]\\packages\\MyExampleProjects\\ in Windows and
   ~/ti/pdk_[soc]_[version]/packages/MyExampleProjects/ in Linux.


Steps to run example and/or unit test projects on C66x/A15 Target
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

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
      4. Click on OK.
      5. Once the project is loaded; click on Target -> Run to execute
         it.

| 

.. raw:: html

