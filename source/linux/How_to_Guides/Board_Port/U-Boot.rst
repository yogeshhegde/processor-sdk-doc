U-Boot Board Port
=================

Overview
--------
SPL and U-Boot share a common code base. When adding a custom board to U-Boot
it is recommended to start out with a TI EVM that resembles the custom hardware
design in some capacity, for example in the areas of DDR (type and size of
memory), MMC (which module is used, is there an eMMC connected or is an SD card
being used), network setup (type and number of PHYs connected), and UART setup
(which UART is intended to be used for console purposes?). For the purposes of
this How-To document we refer to that EVM as the "originating TI EVM".

.. ifconfig:: CONFIG_part_family in ('AM335X_family')

    For custom AM335x boards, many base their design off the `AM335x
    General-Purpose EVM <http://www.ti.com/tool/TMDXEVM3358>`_, the `AM335x
    Starter Kit <http://www.ti.com/tool/TMDSSK3358>`_, or one of the
    AM335x-based `BeagleBone <https://beagleboard.org/bone>`_ boards for a more
    tailored, cut-down starting point.  For this discussion here we will be
    assuming the AM335x General-Purpose EVM to be our starting point however
    the same concepts also apply doing board ports starting off a different
    base platform. The new board will get integrated cleanly in a way like
    other existing boards are integrated into U-Boot.

.. ifconfig:: CONFIG_part_family in ('AM437X_family')

    For custom AM437x boards, many base their design off the `AM437x
    General-Purpose EVM <http://www.ti.com/tool/TMDSEVM437X>`_ or the `AM437x
    Starter Kit <http://www.ti.com/tool/TMDXSK437X>`_. For this discussion here
    we will be assuming the AM437x General-Purpose EVM to be our starting point
    however the same concepts also apply doing board ports starting off a
    different base platform. The new board will get integrated cleanly it in a
    way like other existing boards are integrated into U-Boot.

Integrating support for a new board into the U-Boot tree
--------------------------------------------------------

Adding support is done by essentially cloning, stripping down, and flattening
the TI EVM board support while integrating the resulting files into the U-Boot
build flow, resulting in a custom defconfig, a custom board-specific header
file, a custom top-level device tree file advertising the new board name, and a
custom set of board files for platform setup such as DDR and pinmux. Once such
flattened baseline has been established and has been verified to build
successfully and run on the originating platform, the next step is then to
perform the actual customization work.

Creating an initial baseline by cloning and flattening TI EVM support
*********************************************************************
The steps include various placeholders that need to be substituted during the
board port process as follows:

.. csv-table::
    :header: "Placeholder", "Usage"
    :widths: 20, 80

    "<MYBOARD>", "Name identifying your custom board in upper-case letters.
    It will be used as a name for a new U-Boot CONFIG symbol associated with
    your board allowing to customize various build and runtime aspects."
    "<myboard>", "Name identifying your custom board in lower-case letters.
    Used to establish the custom board platform files in the U-Boot source
    tree hierarchy and as part of board-specific file names, amongst other
    things."
    "<mycompany>", "Name of your company. Used to establish a folder in the
    U-Boot source tree hierarchy containing the board-specific files for
    <myboard> as part of the board port."

Steps to create an intitial baseline:

.. ifconfig:: CONFIG_part_family in ('AM335X_family')

    #. Establish a custom board specific CONFIG option that can be used to
       identify the custom hardware and direct code and build flow accordingly

        * Clone the entire ``config TARGET_AM335X_EVM`` section located in
          **arch/arm/mach-omap2/am33xx/Kconfig** into a new section called
          ``config TARGET_AM335X_<MYBOARD>``
        * Update the ``config TARGET_AM335X_<MYBOARD>`` option description in
          the newly cloned section from ``bool "Support am335x_evm"`` to ``bool
          "Support am335x_<myboard>"``
        * Similarly, update the ``help`` description of the newly cloned section
          to reflect that it is for a custom board
        * Remove the ``select TI_I2C_BOARD_DETECT`` entry from the new section.
          In most cases we do not need or want this feature for custom boards as
          we will be tailoring the solution around our specific platform so
          let's remove it right away.
        * Add ``source "board/<mycompany>/<myboard>/Kconfig"`` to section
          containing source locations located in **arch/arm/mach-omap2/Kconfig**

    #. Copy and update board files to a new folder

        * Copy all files from **board/ti/am335x/** to a new folder called
          **board/<mycompany>/<myboard>**
        * Remove (or update) the **README** and **MAINTAINERS** files (if they
          exist) as needed
        * Remove **u-boot.lds**. It is only needed for NOR boot which is a rare
          use case. However in case you use NOR boot, update the ``.text``
          section in that file from ``board/ti/am335x/built-in.o (.text*)`` to
          ``board/<mycompany>/am335x-myboard/built-in.o (.text*)``.
        * Remove ``#include "../common/board_detect.h"`` from **board.c**
        * Remove code enclosed between ``#ifdef TI_I2C_BOARD_DETECT`` and
          ``#endif`` from **board.c**
        * Rework and remove all board-detection related code in **board.c**,
          **board.h**, and **mux.c**, only keeping and flattening the pieces
          needed to support the actual platform the custom board is based on.
          The original **board.c**, **board.h**, and **mux.c** files are written
          such that they support a multitude of different boards as well as
          different revisions of a given board, all with their own board-
          specific set of features including but not limited to DDR
          configuration, pinmux, device operating points/speeds, and other
          peripheral initialization code. Do the rework by following the code
          path that is executed as a result of various ``board_is_*()``
          function calls. For example, to flatten the platform code and tailor
          it to the currently shipping revision of AM335x GP EVM hardware,
          assume ``board_is_evm_15_or_later()`` to evaluate as ``true``, and
          all other ``board_is_*()`` functions as ``false``, and simplify the
          platform code accordingly.
        * Edit **board/<mycompany>/<myboard>/Kconfig** as follows

                * Update ``if TARGET_AM335X_EVM`` to ``if
                  TARGET_AM335X_<MYBOARD>``
                * Update ``default "am335x"`` to ``default "<myboard>"`` under
                  ``config SYS_BOARD``
                * Update ``default "ti"`` to ``default "<mycompany>"`` under
                  ``config SYS_VENDOR``
                * Update ``default "am335x_evm"`` to ``default
                  "am335x_<myboard>"`` under ``config SYS_CONFIG_NAME``

    #. Copy and update board-specific header file

        * Copy **include/configs/am335x_evm.h** to a new file
          **include/configs/am335x_<myboard>.h**
        * Remove the ``#define CONFIG_SYS_LDSCRIPT`` definition, unless you are
          actually using NOR boot.
        * Remove the ``#define CONFIG_ENV_EEPROM_IS_ON_I2C``,
          ``#define CONFIG_SYS_I2C_EEPROM_ADDR``,
          ``#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN`` definitions as we usually
          do not want to use an external EEPROM for configuration storage, but
          instead want to use the boot media.
        * Update the ``findfdt`` U-Boot environmental variable definition made
          via ``CONFIG_EXTRA_ENV_SETTINGS`` to hard-code board-specific DTB file
          used to boot the Linux Kernel
          ``"findfdt=setenv fdtfile am335x-<myboard>.dtb\0"``
        * Remember that when trying to boot your system with this configuration,
          you must provide a Kernel DTB file named **am335x-<myboard>.dtb** in
          this case. Not providing this file may lead to a silent failure during
          ENV-based U-Boot loading and the Kernel not coming up

    #. Copy and update top-level device tree file and integrate into build process

        * Copy **arch/arm/dts/am335x-evm.dts** to 
          **arch/arm/dts/am335x-<myboard>.dts**
        * Edit **arch/arm/dts/am335x-<myboard>.dts** and update ``model`` node
          with a custom, board-specific string
        * Edit **arch/arm/dts/am335x-<myboard>.dts** to include contents from
          the implicitly included **am335x-evm-u-boot.dtsi** file.

        .. note::
            Many TI boards also come with a U-Boot specific device tree include
            file with the same base name as the main device tree file but ending
            in **-u-boot.dtsi** which gets implicitly included by U-Boot's
            device tree build process. For example in case of
            **arch/arm/dts/am335x-evm.dts** the file that is included implicitly
            is called **arch/arm/dts/am335x-evm-u-boot.dtsi**. It is recommended
            to simply take the contents from such an include file and add it to
            the main device tree file of a board, providing a bit more
            simplified and easier to manage view of the active configuration.

        * Edit **arch/arm/dts/Makefile** to add ``am335x-<myboard>.dtb`` to the
          ``dtb-$(CONFIG_AM33XX)`` build target

    #. Copy and update U-Boot defconfig file

        * Copy **configs/am335x_evm_defconfig** to
          **configs/am335x_<myboard>_defconfig**
        * Edit **configs/am335x_<myboard>_defconfig** as follows
            * Add ``CONFIG_TARGET_AM335X_<MYBOARD>=y`` right below
              ``CONFIG_AM33XX=y``
            * Update ``CONFIG_DEFAULT_DEVICE_TREE="am335x-<myboard>"``
            * Remove entry for ``CONFIG_OF_LIST``

.. ifconfig:: CONFIG_part_family in ('AM437X_family')

    #. Establish a custom-board specific CONFIG option that can be used to
       identify the custom hardware and direct code and build flow accordingly

        * Clone the entire ``config TARGET_AM43XX_EVM`` section located in
          **arch/arm/mach-omap2/am33xx/Kconfig** into a new section called
          ``config TARGET_AM43XX_<MYBOARD>``
        * Update the ``config TARGET_AM43XX_<MYBOARD>`` option description in
          the newly cloned section from ``bool "Support am43xx_evm"`` to
          ``bool "Support am43xx_<myboard>"``
        * Similarly, update the ``help`` description of the newly cloned
          section to reflect that it is for a custom board
        * Remove the ``select TI_I2C_BOARD_DETECT`` entry from the new section.
          In most cases we do not need or want this feature for custom boards
          as we will be tailoring the solution around our specific platform so
          let's remove it right away.
        * Add ``source "board/<mycompany>/<myboard>/Kconfig"`` to section
          containing source locations located in **arch/arm/mach-omap2/Kconfig**


    #. Copy and update board files to a new folder

        * Copy all files from **board/ti/am43xx/** to a new folder called
          **board/<mycompany>/<myboard>**
        * Remove (or update) the **README** and **MAINTAINERS** files (if they
          exist) as needed
        * Remove ``#include "../common/board_detect.h"`` from **board.c**
        * Remove code enclosed between ``#ifdef TI_I2C_BOARD_DETECT`` and
          ``#endif`` from **board.c**
        * Rework and remove all board-detection related code in **board.c**,
          **board.h**, and **mux.c**, only keeping and flattening the pieces
          needed to support the actual platform the custom board is based on.
          The original **board.c**, **board.h**, and **mux.c** files are written
          such that they support a multitude of different boards as well as
          different revisions of a given board, all with their own board-
          specific set of features including but not limited to DDR
          configuration, pinmux, device operating points/speeds, and other
          peripheral initialization code. Do the rework by following the code
          path that is executed as a result of various ``board_is_*()``
          function calls. For example, to flatten the platform code and tailor
          it to the currently shipping revision of AM437x GP EVM hardware,
          assume ``board_is_evm()`` to evaluate as ``true``, and all other
          ``board_is_*()`` functions as ``false``, and simplify the platform
          code accordingly.
        * Edit **board/<mycompany>/<myboard>/Kconfig** as follows

                * Update ``if TARGET_AM43XX_EVM`` to ``if
                  TARGET_AM43XX_<MYBOARD>``
                * Update ``default "am43xx"`` to ``default "<myboard>"`` under
                  ``config SYS_BOARD``
                * Update ``default "ti"`` to ``default "<mycompany>"`` under
                  ``config SYS_VENDOR``
                * Update ``default "am43xx_evm"`` to ``default
                  "am43xx_<myboard>"`` under ``config SYS_CONFIG_NAME``


    #. Copy and update board-specific header file

        * Copy **include/configs/am43xx_evm.h** to a new file
          **include/configs/am43xx_<myboard>.h**
        * Remove the ``#define CONFIG_ENV_EEPROM_IS_ON_I2C``,
          ``#define CONFIG_SYS_I2C_EEPROM_ADDR``,
          ``#define CONFIG_SYS_I2C_EEPROM_ADDR_LEN`` definitions as we usually
          do not want to use an external EEPROM for configuration storage, but
          instead want to use the boot media.
        * Update the ``findfdt`` U-Boot environmental variable definition made
          via ``CONFIG_EXTRA_ENV_SETTINGS`` to hard-code board-specific DTB file
          used to boot the Linux Kernel
          ``"findfdt=setenv fdtfile am437x-<myboard>.dtb\0"``
        * Remember that when trying to boot your system with this configuration,
          you must provide a Kernel DTB file named **am437x-<myboard>.dtb** in
          this case. Not providing this file may lead to a silent failure during
          ENV-based U-Boot loading and the Kernel not coming up

    #. Copy and update top-level device tree file and integrate into build process

        * Copy **arch/arm/dts/am437x-gp-evm.dts** to
          **arch/arm/dts/am437x-<myboard>.dts**
        * Edit **arch/arm/dts/am437x-<myboard>.dts** and update ``model`` node
          with a custom, board-specific string
        * Edit **arch/arm/dts/am437x-<myboard>.dts** to include contents from
          the implicitly included **am437x-gp-evm-u-boot.dtsi** file.

        .. note::
            Many TI boards also come with a U-Boot specific device tree include
            file with the same base name as the main device tree file but ending
            in **-u-boot.dtsi** which gets implicitly included by U-Boot's
            device tree build process. For example in case of
            **arch/arm/dts/am437x-gp-evm.dts** the file that is included
            implicitly is called **arch/arm/dts/am437x-gp-evm-u-boot.dtsi**. It
            is recommended to simply take the contents from such an include file
            and add it to the main device tree file of a board, providing a bit
            more simplified and easier to manage view of the active
            configuration.

        * Edit **arch/arm/dts/Makefile** to add ``am437x-<myboard>.dtb`` to the
          ``dtb-$(CONFIG_AM43XX)`` build target

    #. Copy and update U-Boot defconfig file

        * Copy **configs/am43xx_evm_defconfig** to
          **configs/am43xx_<myboard>_defconfig**
        * Edit **configs/am43xx_<myboard>_defconfig** as follows
            * Add ``CONFIG_TARGET_AM43XX_<MYBOARD>=y`` right below
              ``CONFIG_AM43XX=y``
            * Update ``CONFIG_DEFAULT_DEVICE_TREE="am437x-<myboard>"``
            * Remove entry for ``CONFIG_OF_LIST``

At this point the initial baseline is complete and we should have a custom
board that will run on the platform the board port was based on (TI EVM). Now
to complete this step, do the following:

#. Build our custom board port using the usual flow of first building the newly
   created defconfig file, and then performing the actual build of SPL and
   U-Boot. Fix any build errors you may encounter and re-build until the build
   performs cleanly, without any build warnings. Ensure that the `toolchain path
   <../../Overview/GCC_ToolChain.html>`__ has been set properly. 

    ::

        make ARCH=arm CROSS_COMPILE='arm-linux-gnueabihf-' mrproper
        make ARCH=arm CROSS_COMPILE='arm-linux-gnueabihf-' <device>_<myboard>_defconfig
        make ARCH=arm CROSS_COMPILE='arm-linux-gnueabihf-'

#. Check in the newly added files into Git to establish a known-good checkpoint

Customizing the newly-established baseline to support actual target platform
****************************************************************************
As a next step we want to create a minimal configuration that can be used for
an initial attempt at bringing up the board. Once the basics are working it
will become a good base to build on setup step by step to fully support all
desired features of a custom board. Note that the chances of getting everything
right in the first attempts are rather low, so typically an iterative approach
is taken, comprising making changes, make sure they build, checking them into
the Git source tree (so changes can be traced, understood, and reverted if
needed more easily), and testing them on hardware, until the a fully working
and functional board port has been achieved.

U-Boot uses the same code base to build images for SPL and U-Boot itself. As
you work with the different source and header files take note of how certain
statements are wrapped in ``#ifdef CONFIG_SPL ... #endif`` statement
preprocessor macros, which means the included sections are only applicable and
get build when SPL is being built. Similarly, when you encounter config symbols
that start with ``CONFIG_SPL_*`` either in the `Kconfig
<https://gitlab.denx.de/u-boot/u-boot/-/blob/master/doc/README.kconfig>`_ tool
(meaning, ``make [...] menuconfig``), in actual **Kconfig** files (in which
case the leading ``CONFIG_`` prefix is omitted) in the U-Boot tree, or in any
of the source and Makefile files this means a certain feature or section is
only activated or applicable to SPL.

.. note::
    Use the search function in the Kconfig tool to quickly find various
    ``CONFIG_*`` options that are discussed below. The search can be activated
    by pressing the '/' key.

.. ifconfig:: CONFIG_part_family in ('AM335X_family')

    * Port DDR configuration if your DDR setup (devices, clock speeds, etc.)
      differs from the originating platform (EVM)

        * DDR timing and configuration data is setup in the **board.c** file
        * Follow the steps outlined in the `AM335x EMIF Tools Application
          Report <http://www.ti.com/lit/pdf/sprack4>`_ and its associated
          `Configuration Tool <http://www.ti.com/lit/zip/sprack4>`__ in detail.
          This application report also includes information useful for DDR
          bringup.
        * If any additional customization steps are needed such as the
          addition of extra definitions try to limit any changes you do to the
          files in your custom board-specific folder at
          **board/<mycompany>/<myboard>**
        * When the DDR timings and parameters are setup correctly, U-Boot will
          automatically detect, verify, and configure the size of DDR during
          runtime in the architectural files by using ``get_ram_size()``.

.. ifconfig:: CONFIG_part_family in ('AM437X_family')

    * Port DDR configuration if your DDR setup (devices, clock speeds, etc.)
      differs from the originating platform (EVM)

        * DDR timing and configuration data is setup in the **board.c** file
        * Follow the steps outlined in the `AM43xx EMIF Tools Application
          Report <http://www.ti.com/lit/pdf/sprac70>`__ and its associated
          `Configuration Tool <http://www.ti.com/lit/zip/sprac70>`__ in detail.
          This application report also includes information useful for DDR
          bringup.
        * If any additional customization steps are needed such as the
          addition of extra definitions try to limit any changes you do to the
          files in your custom board-specific folder at
          **board/<mycompany>/<myboard>**
        * When the DDR timings and parameters are setup correctly, U-Boot will
          automatically detect, verify, and configure the size of DDR during
          runtime in the architectural files by using ``get_ram_size()``.

* Establish an initial minimal pinmux setup for the custom board

    * A minimal pinmux setup is needed to avoid any potential signal conflicts
      that may occur when running a configuration that was intended for a TI
      EVM that is simply run on a custom board
    * Pinmux performed in U-Boot is usually limited to the peripherals that are
      directly involved in the boot process (such as GPMC, DDR, MMC, SPI,
      etc.), an I2C module used for PMIC connectivity, as well as the console
      UART
    * For TI EVM-based defconfigs the pinmux is performed through the **mux.c**
      board file, which can be verified by the ``CONFIG_PINCTRL``,
      ``CONFIG_PINCTRL_FULL``, and ``CONFIG_PINCTRL_SINGLE`` options not being
      set in the **.config** file
    * Update the ``enable_board_pin_mux()`` function with the pinmux settings
      needed for your custom board. For TI EVMs this file usually uses
      different ``board_is_*()`` functions to activate different pinmux
      settings for different boards however we should have already flattened
      that functionality earlier. Now we need to remove everything that is not
      applicable to our custom board, and add/update the items we need to
      achieve a minimal environment allowing to boot by making the appropriate
      **configure_module_pin_mux()** calls proving correct (possibly updated)
      data structures.
    * In order to quickly derive the pinmux settings needed there are two
      possible paths:

        #. Use the TI-provided
           `Pin MUX Utility <http://www.ti.com/tool/PINMUXTOOL>`_ which is
           available in a version running in the cloud as well as a version that
           can be installed manually. Note that since the pinmux is performed
           via the **mux.c** board file one needs to convert and translate the
           pinmux settings shown in the Pin MUX Utility to what is expected by
           ``enable_board_pin_mux()`` by modeling and comparing with existing
           ``struct module_pin_mux`` definitions.
        #. Search through and use ``struct module_pin_mux`` definitions from
           board files of other boards using the same SoC

    .. note::
        Any pinmux settings made in the device tree file are not applicable and
        not used by U-Boot. The reason those are there is that usually the
        U-Boot device tree file is a copy of the Linux device tree file as this
        simplifies keeping those in sync. This does not mean however that all
        entries such as pinmux are applicable to U-Boot.

* Update PMIC configuration

    * TI AMxxx SoCs are typically supplied by an external Power Management IC
      (PMIC) connected via the I2C interface. One of the jobs of the PMIC is it
      to supply and provide the VDD_MPU and VDD_CORE voltages according to the
      desired Operating Performance Point (OPP) meeting datasheet requirements.
    * The PMIC is being configured through the ``scale_vcores()`` function
      inside the **board.c** file which gets invoked by the architectural
      drivers prior to setting up the SoC's PLLs.
    * The actual PMIC configuration  is made dependent on the clock frequency
      configured for a given board (see next step). It may also need to be made
      dependent on silicon revision, so review the originating TI EVM's code
      carefully, which is mostly directed based on ``board_is_*()`` invocations
    * Configure which PMIC driver to use by enabling the desired driver via
      ``#define CONFIG_POWER_*`` in the device specific header file
      **include/configs/<myboard>.h**.
    * Only the driver for the PMIC that is actually used on the board should be
      enabled. For a list of available drivers try searching for appropriate
      ``CONFIG`` options as follows: ``git grep 'CONFIG_POWER_TPS'
      drivers/power/pmic``.

* Update SoC clock configuration

    * TI AMxxx SoCs are available in different speed grades, each supporting a
      maximum operating frequency, associated with a specific OPP.
    * The implementation of the ``get_dpll_mpu_params()`` function inside the
      **board.c** file is responsible for determining the maximum allowable
      operating frequency, which is then used by the architecture drivers to
      set up the device's PLLs.
    * Do not attempt increase the device operating frequency beyond what is
      permissible via eFuse readout, however there may be cases where it is
      helpful to not operate at the highest OPP in which case this function can
      get updated to return a different ``struct dpll_params *`` object to
      accommodate this.

.. ifconfig:: CONFIG_part_family in ('AM335X_family')

    * Customize console UART settings

        * Configure desired console index using the Kconfig tool by updating
          ``CONFIG_CONS_INDEX``. This will take care of the UART-related pinmux
          performed inside ``set_uart_mux_conf()`` in **board.c**
        * Note that the function ``default_serial_console()`` is not used in
          case of ``CONFIG_DM_SERIAL`` as it is with the current AM335x EVM so
          it can be removed

        * Update the **arch/arm/dts/am335x-<myboard>.dts** device tree file as follows:
            * Update ``stdout-path`` propery with new phandle to new UART
            * Overlay the respective UART's device tree node with the correct
              pinmux reference and ensure it is set to ``status = "okay";``

        * Update the ``console=`` variable part of the
          ``CONFIG_EXTRA_ENV_SETTINGS`` definition in the board-specific header
          file **include/configs/<myboard>.h** to the desired UART to be used
          for Linux Kernel boot. Set this ENV variable to ``ttyS0,115200n8``
          for UART0, ``ttyS1,115200n8`` for UART1, and so on.

.. ifconfig:: CONFIG_part_family in ('AM437X_family')

    * Customize console UART settings

        * The UART pinmus is done through ``set_uart_mux_conf()`` in
          **board.c**, calling a pinmux configuration function
          ``enable_uart*_pin_mux`` for a specific UART interface inside
          **mux.c**. Update the call as well as the ``enable_uart*_pin_mux``
          function itself to use an updated pinmux structure as needed for the
          new UART interface.

        * Update the **arch/arm/dts/am437x-<myboard>.dts** device tree file as
          follows:

            * Update ``stdout-path`` propery with new phandle to new UART
            * Overlay the respective UART's device tree node with the correct
              pinmux reference and ensure it is set to ``status = "okay";``

        * Update the ``console=`` variable part of the
          ``CONFIG_EXTRA_ENV_SETTINGS`` definition in the board-specific header
          file **include/configs/<myboard>.h** to the desired UART to be used
          for Linux Kernel boot. Set this ENV variable to ``ttyS0,115200n8``
          for UART0, ``ttyS1,115200n8`` for UART1, and so on.

* Setup early (debug) UART

    * The main console UART is brought up only well into the SPL boot process
      due to driver and other dependencies, making it difficult to bring up and
      instrument early startup code including boot peripheral configuration,
      PMIC setup, DDR setup, board ID / EEPROM related code (which should have
      gotten removed by now, as per earlier steps), amongst other things
      without the ability to perform basic ``printf()`` style instrumentation.
    * To make board port and bringup easier it is HIGHLY RECOMMENDED to turn on
      U-Boot's debug UART functionality at least during development and bringup
      work, which is done by configuring and hard-coding various UART
      peripheral parameters. Doing so will enable the UART during
      ``early_system_init()`` execution early on in the SPL flow as part of
      SPL's  ``board_init_f()`` function.
    * Usually the debug UART is configured to match the main console UART
      (e.g., both are configured to use UART0) for a single console output
    * Note for debug UART functionality to work the ``set_uart_mux_conf()`` in
      **board.c** function must have gotten updated as per earlier steps to
      setup the pinmux needed for the debug UART
    * To enable the debug UART functionality using the UART0 module configure
      the below parameters using the Kconfig tool. To use any other UART module
      adjust the ``CONFIG_DEBUG_UART_BASE`` parameter to the base address
      appropriate for that UART, which can be found in the TRM (peripheral
      memory map section) or simply taken from the device-specific device tree
      include file ``uart*: { }`` definitions.

    ::

        CONFIG_DEBUG_UART_BASE=0x44e09000
        CONFIG_DEBUG_UART_CLOCK=48000000
        CONFIG_DEBUG_UART=y
        CONFIG_DEBUG_UART_OMAP=y
        CONFIG_DEBUG_UART_SHIFT=2
        CONFIG_DEBUG_UART_ANNOUNCE=y

    .. note::
        The recommended setup for the early (debug) UART includes
        ``CONFIG_DEBUG_UART_ANNOUNCE=y`` which leads to the output of
        ``<debug_uart>`` very very early on in the SPL boot flow, before
        most/any of the SoC and peripheral configuration happens. Having this
        enabled is a good way to see an "early sign of life" of sorts during
        board bringup, giving one confidence that the very basics of the boot
        process are working which is the ROM boot loader loading SPL from the
        desired boot media and SPL starting to execute.

* Deactivate all peripheral initializations except for basic boot support like
  UART, MMC, etc. from the **<device>-<myboard>.dts** device tree file using
  one of the following methods:

    #. Remove all device tree nodes that are not applicable, including their
       references such as clocks, power regulator, and pinmux settings
    #. De-activate peripherals that are not needed by adding a
       ``status = "disabled";`` property to their respective nodes

* De-activate possibly unnecessary functionality as needed through U-Boot menu
  configuration

    * Establish a new working **.config** file by building the new defconfig
      file ``make ARCH=arm CROSS_COMPILE='arm-linux-gnueabihf-'
      <device>_<myboard>_defconfig``
    * Perform U-Boot configuration by invoking the Kconfig tool via ``make
      ARCH=arm CROSS_COMPILE='arm-linux-gnueabihf-' menuconfig``. This will
      update the current working configuration file **.config** stored at the
      root of the U-Boot directory with any changes that are being performed
    * Turn the current **.config** U-Boot configuration into an updated
      defconfig file by executing ``make ARCH=arm
      CROSS_COMPILE='arm-linux-gnueabihf- savedefconfig``. This will
      generate/update a file called **defconfig**.
    * Copy the newly generated **defconfig** to
      **configs/<device>_<myboard>_defconfig**, effectively overwriting/updating
      the defconfig file established earlier when cloning the existing board we
      are basing the port on. Doing so will also allow us to see the changes
      that were introduced since since our earlier checkpoint commit via ``git
      diff``.

.. ifconfig:: CONFIG_part_family in ('AM335X_family')

    * Remove dependency on RTC
        * If a custom board does not use the SOC's built-in RTC peripheral,
          disable ``CONFIG_SPL_AM33XX_ENABLE_RTC32K_OSC`` via 
          ``make ARCH=arm CROSS_COMPILE='arm-linux-gnueabihf-' menuconfig``

            * Navigate to the **Device Drivers** section and
              deselect the option ``Enable support for checking boot
              count limit ----``. Exit to menuconfig page.
            * Navigate to the **SPL / TPL** section and
              deselect the option ``Enable the RTC32K OSC on AM33xx based
              platforms``. Save and exit menuconfig. 
        * Note that to fully disable RTC support there are also changes needed
          to the Linux Kernel, specifically the disabling of the ``rtc`` node
          from the Kernel device tree file by adding a ``status = "disabled";``
          property to the ``rtc`` node

* De-activate other possibly unnecessary functionality as needed through
  customizing the board-specific header file

    * Some SPL and U-Boot features have not yet been fully migrated to Kconfig
      and are controlled/enabled through the board-specific header file
      **include/configs/<myboard>.h** created earlier
    * Note that that board-specific header file may include additional header
      file(s) that activate and configure functionality. Make sure to
      understand the include hierarchy. To disable or re-configure certain
      features consider using a combination of ``#undef`` and ``#define``
      pre-processor statements in your custom board-specific header file past
      where a common header file is included. This way any modifications to the
      shared U-Boot files can be avoided.

* U-Boot Environment

    * The default U-Boot environment is to a large part defined through the
      ``CONFIG_EXTRA_ENV_SETTINGS`` definition in the board-specific header
      file **include/configs/<myboard>.h** and should be further tailored to
      specific system needs.
    * Make any changes required to support the primary boot mode, such as
      configuring ``bootpart=`` in case of MMC/SD card boot to the correct
      partition
    * While having extra definitions in the environment usually doesn't hurt
      one should use this opportunity to remove any definitions related to boot
      modes that are not needed to yield a less cluttered and easier to
      understand overall U-Boot environment.

        * Remove ``BOOT_TARGET_*`` definitions that are not applicable
        * Remove ``DEFAULT_*_TI_ARGS`` definitions that are not applicable
        * Remove ``*ARGS``  definitions that are not applicable
    * Add an ``optargs=`` ENV definition to ``CONFIG_EXTRA_ENV_SETTINGS`` if
      you need any extra arguments passed to the Kernel during boot
    * Use the Kconfig tool to disable all ``CONFIG_ENV_IS_IN_*`` definitions to
      essentially disable persistent ENV storage initially

With the customizations now made, the resulting SPL/U-Boot should no longer be
run on the originating TI EVM, but instead on the custom hardware. We should
now be able to attempt an initial boot of the custom hardware platform in the
context of the hardware bringup of the new board. The goal should be to get to
the U-Boot prompt.

Building out full support for target platform
*********************************************
Once we have reached U-Boot prompt we can then focus on (re-)adding any
features to U-Boot we may need to more fully support our custom system, and
then move to booting the Linux Kernel. It is recommended adding features one by
one while using Git to track any changes and testing/validating features on
actual hardware as they are added until all desired features have gotten added
and integrated.

Customization steps can involved but are not limited to adding...

* Support for additional storage media
* Support for additional boot modes
* Support for network interface(s)
* Support for extra U-Boot commands (``CONFIG_CMD_*``) to help debugging or
  running the system

When adding features it is usually a good idea to analyze other boards already
present in U-Boot that use the same TI SoC, and then port features over into
our own board files, board specific header file, and defconfig.

To identify which other boards in U-Boot use the same SoC use the below command:

.. ifconfig:: CONFIG_part_family in ('AM335X_family')

    ::

        git grep CONFIG_AM33XX=y

.. ifconfig:: CONFIG_part_family in ('AM437X_family')

    ::

        git grep CONFIG_AM43XX=y

It can also be helpful to inspect the most current upstream `U-Boot tree
<https://gitlab.denx.de/u-boot/u-boot>`_ for additional boards that may since
have become available. However care must be taken when backporting code to the
U-Boot part of the TI SDK to consider all required dependencies and changes
that may have since affected a specific feature.

U-Boot Bringup Debugging Tips
-----------------------------
Doing an U-Boot board port is usually an iterative process, involving some
amount of debugging and troubleshooting, especially on a custom hardware
platform that differs substantially from one of the TI EVMs. The following
list gives some ideas that could be helpful during debugging and U-Boot bringup.

.. ifconfig:: CONFIG_part_family in ('AM335X_family')

    * The most efficient and powerful tool for board bringup is to have access
      to the SoC via JTAG debugger, and use a tool such as TI's Code Composer
      Studio (CCS) to inspect the device and code.

        * Use in conjunction with SPL and U-Boot ELF files for fully symbolic
          debug
        * A very useful tool is using the  CCS-specific `AM335x Debug Server
          Scripting package
          <https://git.ti.com/cgit/sitara-dss-files/am335x-dss-files/>`_ for
          low-level device state and boot analysis. Refer to the included
          `README
          <https://git.ti.com/cgit/sitara-dss-files/am335x-dss-files/tree/README>`__
          file for further information.
        * It may be desirable to turn off the watchdog timer to avoid watchdog
          resets during the debug session (by disabling ``CONFIG_HW_WATCHDOG``,
          ``CONFIG_SPL_WATCHDOG_SUPPORT``, and ``CONFIG_OMAP_WATCHDOG`` through
          Kconfig)

.. ifconfig:: CONFIG_part_family in ('AM437X_family')

    * The most efficient and powerful tool for board bringup is to have access
      to the SoC via JTAG debugger, and use a tool such as TI's Code Composer
      Studio (CCS) to inspect the device and code.

        * Use in conjunction with SPL (**./spl/u-boot-spl**) and U-Boot
          (**./u-boot**) ELF files for fully symbolic debug
        * A very useful tool is using the  CCS-specific `AM43xx Debug Server
          Scripting package
          <https://git.ti.com/cgit/sitara-dss-files/am43xx-dss-files/>`_ for
          low-level device state and boot analysis. Refer to the included
          `README
          <https://git.ti.com/cgit/sitara-dss-files/am43xx-dss-files/tree/README>`__
          file for further information.

* Performing basic printf()-style debugging

    * Use when JTAG is not available or not practical
    * To maximize usefulness of this approach usually requires the early (debug)
      UART to be configured and activated (which will happen as part of SPL's
      ``board_init_f()``) as discussed earlier, as most of the critical
      low-level code on current TI EVMs is executed while the regular console
      UART is not yet available, in which case nothing would get printed during
      any failures relating to boot, PMIC setup, clock setup, DDR setup, and
      other critical stages, leading to "black screen" type of failures leaving
      no clue what to check.
    * Many U-Boot modules (source files) already contain various forms of
      ``debug()`` print statements which can be activated on a per-module basis
      by adding a ``#define DEBUG`` to the top of the source file
    * Beyond that, it can be helpful to add print statements throughout the
      boot flow to trace program execution. For example, the simple statement
      shown below can easily be replicated through copy and paste yet gives
      usually enough information to pinpoint a specific line of code:

    ::

        printf("%s: %d:\n", __func__, __LINE__);

.. ifconfig:: CONFIG_part_family in ('AM335X_family')

    * Double-check final device tree file contents
        Since the device tree file that gets built into U-Boot is created not
        just from the top level **<device>-<myboard>.dts** device tree source
        file but also from an entire hierachy of explicitly (and implicitly)
        included header files it is good to double-check what the actual final
        device tree blob looks like. The best way to do that is by de-compiling
        it back into source code, which in case of the U-Boot device trees can
        be done with the following command:

        ::

            dtc -I dtb u-boot.dtb

.. ifconfig:: CONFIG_part_family in ('AM437X_family')

    * Double-check final device tree file contents
        Since the device tree file that gets built into U-Boot (and SPL, as it
        is in case of ``CONFIG_SPL_OF_CONTROL`` is used on a given platform) is
        created not just from the top level **<device>-<myboard>.dts** device
        tree source file but also from an entire hierachy of explicitly (and
        implicitly) included header files (and SPL-specific DTS properties like
        ``u-boot,dm-spl`` and ``u-boot,dm-pre-reloc``) it is good to
        double-check what the actual final device tree blob looks like. The
        best way to do that is by de-compiling it back into source code, which
        in case of the SPL and U-Boot device trees can be done with the
        following commands:


        ::

            dtc -I dtb spl/u-boot-spl.dtb
            dtc -I dtb u-boot.dtb
