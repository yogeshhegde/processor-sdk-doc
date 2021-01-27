General Information
-------------------

Getting the U-Boot Source Code
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

| The easiest way to get access to the U-boot source code is by
  downloading and installing the Processor SDK Linux. Once installed,
  the U-Boot source code is included in the SDK's board-support
  directory. For your convenience the sources also includes the U-Boot's
  git repository including commit history.
| Alternatively, U-Boot sources can directly be fetched from GIT.

  .. ifconfig:: CONFIG_sdk in ('PLSDK')

      The GIT repo URL, branch and commit id can be found in the
      :ref:`release-specific-build-information-u-boot` section of the release notes.

|

Build U-Boot
^^^^^^^^^^^^

.. ifconfig:: CONFIG_part_family in ('General_family', 'AM335X_family', 'AM437X_family')

    We strongly recommend the use of separate object directories when
    building. This is done with O= parameter to make. We also recommend that
    you use an output directory name that is identical to the configuration
    target name. That way if you are working with multiple configuration
    targets it is very easy to know which folder contains the u-boot
    binaries that you are interested in.

    .. rubric:: Setting the tool chain path

    We strongly recommend using the toolchain that came with the Linux Core
    release that corresponds to this U-Boot release. For e.g:

    ::

        export PATH=$HOME/<TOOLCHAIN_PATH>/bin:$PATH

    .. rubric:: Cleaning the Sources

    If you did not use a separate object directory:

    ::

        $ make CROSS_COMPILE=arm-linux-gnueabihf- distclean

    If you used 'O=am335x\_evm' as your object directory:

    ::

        $ rm -rf ./am335x_evm

    .. rubric:: Compiling MLO and u-boot

    Building of both u-boot and SPL is done at the same time. You must
    however first configure the build for the board you are working with.
    Use the following table to determine what defconfig to use to configure
    with:

    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+
    | Board                      | SD Boot                     | eMMC Boot                | NAND Boot                                  | UART Boot                | Ethernet Boot            | USB Ethernet Boot        | USB Host Boot                           | SPI Boot                                 |
    +============================+=============================+==========================+============================================+==========================+==========================+==========================+=========================================+==========================================+
    | AM335x GP EVM              | am335x\_evm\_defconfig      |                          | am335x\_evm\_defconfig                     | am335x\_evm\_defconfig   | am335x\_evm\_defconfig   | am335x\_evm\_defconfig   |                                         |                                          |
    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+
    | AM335x EVM-SK              | am335x\_evm\_defconfig      |                          |                                            | am335x\_evm\_defconfig   |                          | am335x\_evm\_defconfig   |                                         |                                          |
    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+
    | AM335x ICE                 | am335x\_evm\_defconfig      |                          |                                            | am335x\_evm\_defconfig   |                          |                          |                                         |                                          |
    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+
    | BeagleBone Black           | am335x\_evm\_defconfig      | am335x\_evm\_defconfig   |                                            | am335x\_evm\_defconfig   |                          |                          |                                         |                                          |
    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+
    | BeagleBone White           | am335x\_evm\_defconfig      |                          |                                            | am335x\_evm\_defconfig   |                          |                          |                                         |                                          |
    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+
    | AM437x GP EVM              | am43xx\_evm\_defconfig      |                          | am43xx\_evm\_defconfig                     | am43xx\_evm\_defconfig   | am43xx\_evm\_defconfig   | am43xx\_evm\_defconfig   | am43xx\_evm\_usbhost\_boot\_defconfig   |                                          |
    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+
    | AM437x EVM-Sk              | am43xx\_evm\_defconfig      |                          |                                            |                          |                          |                          | am43xx\_evm\_usbhost\_boot\_defconfig   |                                          |
    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+
    | AM437x IDK                 | am43xx\_evm\_defconfig      |                          |                                            |                          |                          |                          |                                         | am43xx\_evm\_qspiboot\_defconfig (XIP)   |
    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+
    | AM437x ePOS EVM            | am43xx\_evm\_defconfig      |                          | am43xx\_evm\_defconfig                     |                          |                          |                          | am43xx\_evm\_usbhost\_boot\_defconfig   |                                          |
    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+
    | AM572x GP EVM              | am57xx\_evm\_defconfig      |                          |                                            | am57xx\_evm\_defconfig   |                          |                          |                                         |                                          |
    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+
    | AM572x IDK                 | am57xx\_evm\_defconfig      |                          |                                            |                          |                          |                          |                                         |                                          |
    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+
    | AM571x IDK                 | am57xx\_evm\_defconfig      |                          |                                            |                          |                          |                          |                                         |                                          |
    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+
    | DRA74x/DRA72x/DRA71x EVM   | dra7xx\_evm\_defconfig      | dra7xx\_evm\_defconfig   | dra7xx\_evm\_defconfig (DRA71x EVM only)   |                          |                          |                          |                                         | dra7xx\_evm\_defconfig(QSPI)             |
    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+
    | K2HK EVM                   |                             |                          | k2hk\_evm\_defconfig                       | k2hk\_evm\_defconfig     | k2hk\_evm\_defconfig     |                          |                                         | k2hk\_evm\_defconfig                     |
    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+
    | K2L EVM                    |                             |                          | k2l\_evm\_defconfig                        | k2l\_evm\_defconfig      |                          |                          |                                         | k2l\_evm\_defconfig                      |
    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+
    | K2E EVM                    |                             |                          | k2e\_evm\_defconfig                        | k2e\_evm\_defconfig      |                          |                          |                                         | k2e\_evm\_defconfig                      |
    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+
    | K2G GP EVM                 | k2g\_evm\_defconfig         |                          |                                            | k2g\_evm\_defconfig      | k2g\_evm\_defconfig      |                          |                                         | k2g\_evm\_defconfig                      |
    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+
    | K2G ICE                    | k2g\_evm\_defconfig         |                          |                                            |                          |                          |                          |                                         |                                          |
    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+
    | OMAP-L138 LCDK             | omapl138\_lcdk\_defconfig   |                          | omapl138\_lcdk\_defconfig                  |                          |                          |                          |                                         |                                          |
    +----------------------------+-----------------------------+--------------------------+--------------------------------------------+--------------------------+--------------------------+--------------------------+-----------------------------------------+------------------------------------------+

    Then (Use 'am335x_evm' and 'AM335x GP EVM' in this example):

    ::

        $ make CROSS_COMPILE=arm-linux-gnueabihf- O=am335x_evm am335x_evm_defconfig
        $ make CROSS_COMPILE=arm-linux-gnueabihf- O=am335x_evm

    .. note::
        Not all possible build targets for a given platform are listed
        here as the community has additional build targets that are not
        supported by TI. To find these read the 'boards.cfg' file and look for
        the build target listed above. And please note that the main config file
        will leverage other files under include/configs, as seen by #include
        statements.


.. ifconfig:: CONFIG_part_family not in ('General_family', 'AM335X_family', 'AM437X_family')

    Several prebuilt images are required from the TI Processor SDK for building U-Boot on K3 based platforms.
    Go `here <Overview/Download_and_Install_the_SDK.html>`__ to download and install the SDK.

    TI-u-boot is included in the SDK in <path to tisdk>/board-support. Ensure that the u-boot version matches the
    :ref:`release-specific-build-information-u-boot`.

    .. rubric:: Setting the tool chain path

    We strongly recommend using the toolchain that came with the Linux Core
    release that corresponds to this U-Boot release. For e.g:

    ::

        export PATH=$HOME/gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf/bin:$PATH
        export PATH=$HOME/gcc-arm-8.3-2019.03-x86_64-aarch64-linux-gnu/bin:$PATH

    .. rubric:: Compiling R5 and ARM64 images

    Use the following table to determine what defconfig to use to configure with:

    .. ifconfig:: CONFIG_part_variant in ('AM65X')

        +----------------------------+---------------------------------+--------------------------------+--------------------------------+--------------------------------+--------------------------------+
        |  Board                     |            SD/eMMC Boot         |           UART boot            |           OSPI boot            |         Hyper Flash            |           USB DFU              |
        +============================+=================================+================================+================================+================================+================================+
        |    AM65x EVM/IDK           |    am65x\_evm\_r5\_defconfig    |   am65x\_evm\_r5\_defconfig    |   am65x\_evm\_r5_defconfig     |                                |                                |
        |                            |    am65x\_evm\_a53\_defconfig   |   am65x\_evm\_a53\_defconfig   |   am65x\_evm\_a53\_defconfig   |                                |                                |
        +----------------------------+---------------------------------+--------------------------------+--------------------------------+--------------------------------+--------------------------------+

       *R5*

       .. code-block:: console

          $ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- am65x_evm_r5_defconfig O=<output directory>/r5
          $ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- O=<output directory>/r5

       *A53*

       .. code-block:: console

          $ make ARCH=arm CROSS_COMPILE=aarch64-linux-gnu- am65x_evm_a53_defconfig O=<output directory>/a53
          $ make ARCH=arm CROSS_COMPILE=aarch64-linux-gnu- ATF=<path to tisdk>/board-support/prebuilt-images/bl31.bin TEE=<path to tisdk>/board-support/prebuilt-images/bl32.bin O=<output directory>/a53

    .. ifconfig:: CONFIG_part_variant in ('J721E')

        +----------------------------+---------------------------------+--------------------------------+--------------------------------+--------------------------------+--------------------------------+
        |  Board                     |            SD/eMMC Boot         |           UART boot            |           OSPI boot            |         Hyper Flash            |           USB DFU              |
        +============================+=================================+================================+================================+================================+================================+
        |    J721E EVM               |    j721e\_evm\_r5\_defconfig    |   j721e\_evm\_r5\_defconfig    |   j721e\_evm\_r5\_defconfig    |   j721e\_evm\_r5\_defconfig    |   j721e\_evm\_r5\_defconfig    |
        |                            |    j721e\_evm\_a72\_defconfig   |   j721e\_evm\_a72\_defconfig   |   j721e\_evm\_a72\_defconfig   |   j721e\_evm\_a72\_defconfig   |   j721e\_evm\_a72\_defconfig   |
        +----------------------------+---------------------------------+--------------------------------+--------------------------------+--------------------------------+--------------------------------+

       *R5*

       .. code-block:: console

          $ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- j721e_evm_r5_defconfig O=<output directory>/r5
          $ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- O=<output directory>/r5

       *A72*

       .. code-block:: console

          $ make ARCH=arm CROSS_COMPILE=aarch64-linux-gnu- j721e_evm_a72_defconfig O=<output directory>/a72
          $ make ARCH=arm CROSS_COMPILE=aarch64-linux-gnu- ATF=<path to tisdk>/board-support/prebuilt-images/bl31.bin TEE=<path to tisdk>/board-support/prebuilt-images/bl32.bin DM=<path to tisdk>/board-support/prebuilt-images/ipc_echo_testb_mcu1_0_release_strip.xer5f O=<output directory>/a72

    .. ifconfig:: CONFIG_part_variant in ('J7200')

        +----------------------------+---------------------------------+--------------------------------+
        |  Board                     |            SD/eMMC Boot         |           UART boot            |
        +============================+=================================+================================+
        |    J7200 EVM               |    j7200\_evm\_r5\_defconfig    |   j7200\_evm\_r5\_defconfig    |
        |                            |    j7200\_evm\_a72\_defconfig   |   j7200\_evm\_a72\_defconfig   |
        +----------------------------+---------------------------------+--------------------------------+

       *R5*

       .. code-block:: console

          $ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- j7200_evm_r5_defconfig O=<output directory>/r5
          $ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- O=<output directory>/r5

       *A72*

       .. code-block:: console

          $ make ARCH=arm CROSS_COMPILE=aarch64-linux-gnu- j7200_evm_a72_defconfig O=<output directory>/a72
          $ make ARCH=arm CROSS_COMPILE=aarch64-linux-gnu- ATF=<path to tisdk>/board-support/prebuilt-images/bl31.bin TEE=<path to tisdk>/board-support/prebuilt-images/bl32.bin DM=<path to tisdk>/board-support/prebuilt-images/ipc_echo_testb_mcu1_0_release_strip.xer5f O=<output directory>/a72
          $ cd <path to K3-image-gen project>
          $ make ARCH=arm CROSS_COMPILE=aarch64-linux-gnu- SOC=j7200 SBL=<output directory>/r5/spl/u-boot-spl.bin


    .. ifconfig:: CONFIG_part_variant in ('AM64X')

        +----------------------------+---------------------------------+--------------------------------+--------------------------------+
        |  Board                     |            SD/eMMC Boot         |           UART boot            |           OSPI boot            |
        +============================+=================================+================================+================================+
        |    AM64X EVM               |    am64x\_evm\_r5\_defconfig    |   am64x\_evm\_r5\_defconfig    |   am64x\_evm\_r5\_defconfig    |
        |                            |    am64x\_evm\_a53\_defconfig   |   am64x\_evm\_a53\_defconfig   |   am64x\_evm\_a53\_defconfig   |
        +----------------------------+---------------------------------+--------------------------------+--------------------------------+

       *R5*

       .. code-block:: console

          $ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- am64x_evm_r5_defconfig O=<output directory>/r5
          $ make ARCH=arm CROSS_COMPILE=arm-linux-gnueabihf- O=<output directory>/r5

       *A53*

       .. code-block:: console

          $ make ARCH=arm CROSS_COMPILE=aarch64-linux-gnu- am64x_evm_a53_defconfig O=<output directory>/a53
          $ make ARCH=arm CROSS_COMPILE=aarch64-linux-gnu- ATF=<path to tisdk>/board-support/prebuilt-images/bl31.bin TEE=<path to tisdk>/board-support/prebuilt-images/bl32.bin  O=<output directory>/a53
          $ cd <path to K3-image-gen project>
          $ make ARCH=arm CROSS_COMPILE=aarch64-linux-gnu- SOC=am64x SBL=<output directory>/r5/spl/u-boot-spl.bin


    .. rubric:: Dependent Project location

    - K3-image-gen (For generating tiboot3.bin and sysfw.itb) project is
      located `here <https://git.ti.com/cgit/k3-image-gen/k3-image-gen>`__
    - Linux Firmware (for device specific ti-dm and ti-sysfw binaries) project
      is located `here <https://git.ti.com/cgit/processor-firmware/ti-linux-firmware/log/?h=ti-linux-firmware>`__ 

    .. rubric:: Target Images

    Copy the below images to the boot partition of an SD card and boot.
    Instructions to format the SD card can be found `here <Overview/Processor_SDK_Linux_create_SD_card_script.html>`__.

    .. ifconfig:: CONFIG_part_variant in ('AM65X')

       - tiboot3.bin from <output directory>/r5
       - tispl.bin, u-boot.img from <output directory>/a53
       - sysfw.itb from <path to tisdk>/board-support/prebuilt-images/

    .. ifconfig:: CONFIG_part_variant in ('J721E')

       - tiboot3.bin from <output directory>/r5
       - tispl.bin, u-boot.img from <output directory>/a72
       - sysfw.itb from <path to tisdk>/board-support/prebuilt-images/

    .. ifconfig:: CONFIG_part_variant in ('J7200')

       - tiboot3.bin from <path to K3-image-gen> (This is combined image of tiboot3.bin and sysfw.itb)
       - tispl.bin, u-boot.img from <output directory>/a72

    .. ifconfig:: CONFIG_part_variant in ('AM64X')

       - tiboot3.bin from <path to K3-image-gen> (This is combined image of tiboot3.bin and sysfw.itb)
       - tispl.bin, u-boot.img from <output directory>/a53

    .. ifconfig:: CONFIG_part_variant not in ('J7200', 'AM64X')

       .. rubric:: Image Formats

       - tiboot3.bin

       .. code-block:: console

            +-----------------------+
            |        X.509          |
            |      Certificate      |
            | +-------------------+ |
            | |                   | |
            | |        R5         | |
            | |   u-boot-spl.bin  | |
            | |                   | |
            | +-------------------+ |
            | |                   | |
            | |     FIT header    | |
            | | +---------------+ | |
            | | |               | | |
            | | |   DTB 1...N   | | |
            | | +---------------+ | |
            | +-------------------+ |
            +-----------------------+

       - tispl.bin

       .. code-block:: console

            +-----------------------+
            |                       |
            |       FIT HEADER      |
            | +-------------------+ |
            | |                   | |
            | |      ARM64 ATF    | |
            | +-------------------+ |
            | |                   | |
            | |     ARM64 OPTEE   | |
            | +-------------------+ |
            | |                   | |
            | |      ARM64 SPL    | |
            | +-------------------+ |
            | |                   | |
            | |   SPL DTB 1...N   | |
            | +-------------------+ |
            +-----------------------+

       - sysfw.itb

       .. code-block:: console

            +-----------------------+
            |                       |
            |       FIT HEADER      |
            | +-------------------+ |
            | |                   | |
            | |     sysfw.bin     | |
            | +-------------------+ |
            | |                   | |
            | |    board config   | |
            | +-------------------+ |
            | |                   | |
            | |     PM config     | |
            | +-------------------+ |
            | |                   | |
            | |     RM config     | |
            | +-------------------+ |
            | |                   | |
            | |    Secure config  | |
            | +-------------------+ |
            +-----------------------+

Boot Flow
^^^^^^^^^
.. ifconfig:: CONFIG_part_family in ('General_family', 'AM335X_family', 'AM437X_family')

    Booting the Linux kernel on an embedded platform is not as simple as simply
    pointing a program counter to the kernel location and letting the processor
    run. This section will review the four bootloader software stages that must
    be run before the kernel can be booted and run on the device.

    Application processors such as the the AM335x are complex pieces of hardware,
    but have limited internal RAM (e.g., 128KB). Because of this limited amount
    of RAM, multiple bootloader stages are needed. These bootloader stages
    systematically unlock the full functionality of the device so that all
    complexities of the device are available to the kernel.

    There are four distinct bootloader stages:

    .. Image:: /images/U-Boot_Boot_Order_32bit.png

    1. ROM Code

    The first stage bootloader is housed in ROM on the device. The ROM code is
    the first block of code that is automatically run on device start-up or
    after power-on reset (POR). The ROM bootloader code is hardcoded into the
    device and cannot be changed by the user. Because of this, it is important
    to get an understanding of what exactly the ROM code is doing.

    The ROM code has two main functions:

    * Configuration of the device and initialization of primary peripherals
      such as stack setup, configuring the Watchdog Timer (see TRM for details)
      as well as the PLL and system clocks configuration
    * Readies the device for next bootloader by checking boot sources for next
      stage of bootloader (SPL) as well as loading the actual next stage
      bootloader code into memory and starting it

    The list of booting devices that the ROM code will search through for the
    second stage bootloader is configured by the voltage levels set on the
    devices SYSBOOT pins on startup. These pins also set other boot parameters
    (i.e. expected crystal frequency, bus width of external memory). For more
    information on the SYSBOOT pins and associated boot parameters see the
    device TRM.

    2. SPL or MLO

    The second stage bootloader is known as the SPL (Secondary Program Loader),
    but is sometimes referred to as the MLO (MMC Card Loader). The SPL is the
    first stage of U-Boot, and must be loaded from one of the boot sources into
    internal RAM. The SPL has very limited configuration or user interaction,
    and mainly serves to initialize the external DDR memory and set-up the boot
    process for the next bootloader stage: U-Boot.

    3. U-Boot

    U-Boot allows for powerful command-based control over the kernel boot
    environment via a serial terminal. The user has control over a number of
    parameters such as boot arguments and the kernel boot command. In addition,
    U-Boot environment variables can be configured. These environment variables
    are stored in the **uEnv.txt** file on your storage medium or directly in
    a Flash-based memory if configured such. These environment variables can be
    viewed, modified, and saved using the **env print**, **env set**, and
    **env save** commands, respectively. U-Boot is also a very useful tool to
    program and manipulate a wide range of external memory devices as well as
    a helpful aid during custom board bringup.

    4. Linux Kernel

    **zImage** is the compressed kernel image wrapped with header info that
    describes the kernel. This header includes the target architecture, the
    operating system, kernel size, entry points, etc. The loading of the kernel
    image is typically performed through the use of scripts stored in the U-Boot
    environment (all starting with the **bootcmd** ENV variable that gets
    executed after the autoboot countdown expires or manually by entering the
    **boot** command at the U-Boot prompt). This also involves passing a board-
    specific device tree blob (DTB) as an argument to U-Boot's **bootz**
    command that will extract and start the actual kernel.

.. ifconfig:: CONFIG_part_family not in ('General_family', 'AM335X_family', 'AM437X_family')

    On K3 architecture based devices, ROM supports boot only via MCU(R5). This means that
    bootloader has to run on R5 core. In order to meet this constraint, keeping
    safety in picture and to have faster boot time, the software boot architecture
    is designed as below:

    .. code-block:: console

        +------------------------------------------------------------------------+
        |        DMSC            |         R5            |        ARM64          |
        +------------------------------------------------------------------------+
        |    +--------+          |                       |                       |
        |    |  Reset |          |                       |                       |
        |    +--------+          |                       |                       |
        |         :              |                       |                       |
        |    +--------+          |   +-----------+       |                       |
        |    | *ROM*  |----------|-->| Reset rls |       |                       |
        |    +--------+          |   +-----------+       |                       |
        |    |        |          |         :             |                       |
        |    |  ROM   |          |         :             |                       |
        |    |services|          |         :             |                       |
        |    |        |          |   +-------------+     |                       |
        |    |        |          |   |  *R5 ROM*   |     |                       |
        |    |        |          |   +-------------+     |                       |
        |    |        |<---------|---|Load and auth|     |                       |
        |    |        |          |   | tiboot3.bin |     |                       |
        |    |        |          |   +-------------+     |                       |
        |    |        |          |         :             |                       |
        |    |        |          |         :             |                       |
        |    |        |          |         :             |                       |
        |    |        |          |   +-------------+     |                       |
        |    |        |          |   |  *R5 SPL*   |     |                       |
        |    |        |          |   +-------------+     |                       |
        |    |        |          |   |    Load     |     |                       |
        |    |        |          |   |  sysfw.itb  |     |                       |
        |    | Start  |          |   +-------------+     |                       |
        |    | System |<---------|---|    Start    |     |                       |
        |    |Firmware|          |   |    SYSFW    |     |                       |
        |    +--------+          |   +-------------+     |                       |
        |        :               |   |             |     |                       |
        |    +---------+         |   |   Load      |     |                       |
        |    | *SYSFW* |         |   |   system    |     |                       |
        |    +---------+         |   | Config data |     |                       |
        |    |         |<--------|---|             |     |                       |
        |    |         |         |   +-------------+     |                       |
        |    |         |         |   |             |     |                       |
        |    |         |         |   |    DDR      |     |                       |
        |    |         |         |   |   config    |     |                       |
        |    |         |         |   +-------------+     |                       |
        |    |         |         |   |             |     |                       |
        |    |         |<--------|---| Start A53   |     |                       |
        |    |         |         |   |  and Reset  |     |                       |
        |    |         |         |   +-------------+     |                       |
        |    |         |         |                       |     +-----------+     |
        |    |         |---------|-----------------------|---->| Reset rls |     |
        |    |         |         |                       |     +-----------+     |
        |    |  DMSC   |         |                       |          :            |
        |    |Services |         |                       |     +-----------+     |
        |    |         |<--------|-----------------------|---->|*ATF/OPTEE*|     |
        |    |         |         |                       |     +-----------+     |
        |    |         |         |                       |          :            |
        |    |         |         |                       |     +-----------+     |
        |    |         |<--------|-----------------------|---->| *A53 SPL* |     |
        |    |         |         |                       |     +-----------+     |
        |    |         |         |                       |     |   Load    |     |
        |    |         |         |                       |     | u-boot.img|     |
        |    |         |         |                       |     +-----------+     |
        |    |         |         |                       |          :            |
        |    |         |         |                       |     +-----------+     |
        |    |         |<--------|-----------------------|---->| *U-Boot*  |     |
        |    |         |         |                       |     +-----------+     |
        |    |         |         |                       |     |  prompt   |     |
        |    |         |         |                       |     +-----------+     |
        |    +---------+         |                       |                       |
        |                        |                       |                       |
        +------------------------------------------------------------------------+

    Here DMSC acts as master and provides all the critical services. R5/ARM64
    requests DMSC to get these services done as shown in the above diagram.

U-Boot Environment
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Please note that on many boards we modify the environment during system
start for a variety of variables such as **board\_name** and if unset,
**ethaddr**. When we restore defaults some variables will become unset,
and this can lead to other things not working such as **findfdt** that
rely on these run-time set variables.

.. rubric:: Restoring defaults
   :name: restoring-defaults

It is possible to reset the set of U-Boot environment variables to their
defaults and if desired, save them to where the environment is stored,
if applicable. It is also required to restore the default setting when
u-boot version changes from an upgrade or downgrade. To do so, issue the
following commands:

::

    U-Boot # env default -f -a
    U-Boot # saveenv

| 

.. rubric:: Networking Environment
   :name: networking-environment

When using a USB-Ethernet dongle a valid MAC address must be set in the
environment. To create a valid address please read `**this
page** <http://www.denx.de/wiki/view/DULG/WhereCanIGetAValidMACAddress>`__.
Then issue the following command:

::

    U-Boot # setenv usbethaddr value:from:link:above

You can use the **printenv** command to see if **usbethaddr** is already
set.

Then start the USB subsystem:

::

    U-Boot # usb start

The default behavior of U-Boot is to utilize all information that a DHCP
server passes to us when the user issues the **dhcp** command. This will
include the dhcp parameter *next-server* which indicates where to fetch
files from via TFTP. There may be times however where the dhcp server on
your network provides incorrect information and you are unable to modify
the server. In this case the following steps can be helpful:

::

    U-Boot # setenv autoload no
    U-Boot # dhcp
    U-Boot # setenv serverip correct.server.ip
    U-Boot # tftp

Another alternative is to utilize the full syntax of the tftp command:

::

    U-Boot # setenv autoload no
    U-Boot # dhcp
    U-Boot # tftp ${loadaddr} server.ip:fileName

Available RAM for image download
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

To know the amount of RAM available for downloading images or for other
usage, use ``bdinfo`` command.

::

    => bdinfo
    arch_number = 0x00000000
    boot_params = 0x80000100
    DRAM bank   = 0x00000000
    -> start    = 0x80000000
    -> size     = 0x7F000000
    baudrate    = 115200 bps
    TLB addr    = 0xFEFF0000
    relocaddr   = 0xFEF30000
    reloc off   = 0x7E730000
    irq_sp      = 0xFCEF8880
    sp start    = 0xFCEF8870
    Early malloc usage: 890 / 2000

After booting, U-Boot relocates itself (along with its various reserved
RAM areas) and places itself at end of available RAM (starting at
``relocaddr`` in ``bdinfo`` output above). Only the stack is located
just before that area. The address of top of the stack is in
``sp start`` in ``bdinfo`` output and it grows downwards. Users should
reserve at least about 1MB for stack, so in the example output above,
RAM in the range of ``[0x80000000, 0xFCE00000]`` is safely available for
use.

Device Trees
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

A note about device trees. Now all supported boards are required to use a
device tree to boot. To facilitate this in supported platforms, a command
in U-Boot environment **findfdt** is available that will set the **fdtfile**
variable to the name of the device tree to use, as found with the kernel
sources. In the Keystone-2 family devices (K2H/K/E/L/G), it is specified
by **name\_fdt** variable for each platform. The device tree is expected
to be loaded from the same media as the kernel, and from the same relative path.


