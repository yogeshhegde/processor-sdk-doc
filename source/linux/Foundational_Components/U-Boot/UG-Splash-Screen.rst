U-boot Splash Screen
====================
A splash screen is an introductory screen that user sees over display when device boots up.
Splash screens are typically used to provide feedback to the user that the board is booting up and
to showcase the vendor logo which helps with branding and also for the identification of which boot
image is being used for the boot up.

AM62x offers out of box splash screen experience with OLDI display in SDK release 9.0. It also
supports displaying splash screen until kernel is booted up with flicker free transition across
different boot stages.

Features Supported
------------------
Following features are supported for splash screen in u-boot:

#. Supports 32, 24 and 8 bits per pixel bmp image.
#. Supports frame-buffer of size 1920x1200 resolution, images with resolution lesser than this can
   still be displayed using the same frame-buffer.
#. Supports displaying only bmp and compressed bmp images(gzip and 8bit RLE).
#. Supports MMC and OSPI as bmp image source.
#. Supports splash screen only on OLDI panel.

.. note::
   * AM62x supports splash screen at both u-boot proper and A53 SPL with A53 SPL displaying splash
     screen **~1.4** seconds earlier than u-boot proper.

Enabling Splash Screen on ti-u-boot
-----------------------------------
In SDK release 9.0 ti-u-boot supports splash screen at A53 SPL stage and U-boot proper.

A53 SPL
^^^^^^^
By default splash screen is only enabled at A53 SPL. The default splash source is set to SD card and
displays a gzip TI logo BMP Image. The SPL splash screen features are compiled in the tispl.bin
which is built during u-boot compilation. Any changes made to SPL splash screen feature will require
to recompile tispl.bin. Use the new tispl.bin to boot the board to see splash screen at SPL stage.

At SPL stage splash screen is called from board/ti/am62x/evm.c in function spl_board_init

.. code-block:: c

      video_setup();
      enable_caches();
      if (IS_ENABLED(CONFIG_SPL_SPLASH_SCREEN) && IS_ENABLED(CONFIG_SPL_BMP))
         splash_display();

U-boot Proper
^^^^^^^^^^^^^
To enable splash screen at U-boot proper enable following configs in configs/am62x_evm_a53_defconfig.

.. code-block:: kconfig

        CONFIG_SPLASH_SCREEN=y
        CONFIG_SPLASH_SOURCE=y
        CONFIG_SPLASH_SCREEN_ALIGN=y
        CONFIG_HIDE_LOGO_VERSION=y

If user only want splash screen feature at u-boot proper, user can disable splash screen at A53 SPL
splash screen using kconfig **CONFIG_SPL_VIDEO**.

.. code-block:: kconfig

         # CONFIG_SPL_VIDEO=y

Splash screen feature at u-boot proper will be compiled in u-boot.img, built during u-boot
compilation. Any changes made to u-boot splash screen feature will require to recompile u-boot.img.
Use the new u-boot.img to boot the board, to see splash screen at U-boot proper.

.. note::
   * If splash screen is enabled at u-boot proper it will stay persistent until linux boot starts.

.. _Display custom logo as splash screen:

Display custom logo as splash screen
------------------------------------
In U-boot all information for image to be displayed as splash screen is passed through env variables,
defined below. These should be added in the .env file used by the board. For reference
board/ti/am62x.env .

.. code-block:: bash

      #Name of file to be displayed
      splashfile=ti_logo_414x97_32bpp.bmp.gz

      #DDR address to load image fom boot media
      splashimage=0x80200000

      #Position of image on display
      splashpos=m,m

      #Source of bmp image
      splashsource=mmc

To display custom logo change the **splashfile** variable to logo_file_name.

If using SD card as splash source, place the image in the boot partition of SD card, which contains
tispl.bin and u-boot.img.

To display image from a different source, add the source information in struct
default_splash_locations, which is defined in board.c. For reference board/ti/am62x/evm.c, by
default OSPI and SD card as source are added for AM62x.

.. code-block:: c

   static struct splash_location default_splash_locations[] = {
   	{
   		.name = "sf",
   		.storage = SPLASH_STORAGE_SF,
   		.flags = SPLASH_STORAGE_RAW,
   		.offset = 0x700000,
   	},
   	{
   		.name		= "mmc",
   		.storage	= SPLASH_STORAGE_MMC,
   		.flags		= SPLASH_STORAGE_FS,
   		.devpart	= "1:1",
   	},
   };

Change **splashsource** variable to the name of source defined in above struct.

.. note::
   .env file gets compiled into u-boot.img and tispl.bin for u-boot proper and A53 SPL respectively,
   any changes made in .env will require to recompile u-boot.img and tispl.bin depending on the
   stage splash screen is enabled.

Enabling Splash Screen on upstream U-Boot
-----------------------------------------
In upstream, splash screen is supported at driver level for both A53 SPL and u-boot proper.

However user needs to enable required kconfigs add DTS node manually, below commit can be used for
reference for making changes.

#. `arm: dts: k3-am62-main: Add device tree node for TIDSS  <https://git.ti.com/cgit/ti-u-boot/ti-u-boot/commit/?h=ti-u-boot-2023.04&id=53104ee32a8ceb350abcd00210bf1290de0373b6>`_
#. `arm: dts: k3-am625-sk: Add pin control for TIDSS and add panel device tree node <https://git.ti.com/cgit/ti-u-boot/ti-u-boot/commit/?h=ti-u-boot-2023.04&id=4ce7c709975429b4537f5555f7cee30f45d253b4>`_
#. `arch: arm: dts: k3-am625-sk: add bootph-pre-ram flags <https://git.ti.com/cgit/ti-u-boot/ti-u-boot/commit/?h=ti-u-boot-2023.04&id=dca8245419503c55e60ed6671dbde36f9143b439>`_

A53 SPL
^^^^^^^
To enable splash screen at A53 SPL enable following configs in configs/am62x_evm_a53_defconfig :

.. code-block:: kconfig

   CONFIG_CMD_BMP=y
   CONFIG_VIDEO=y
   CONFIG_SYS_WHITE_ON_BLACK=y
   CONFIG_VIDEO_TIDSS=y
   CONFIG_SPLASH_SCREEN=y
   CONFIG_SPLASH_SCREEN_ALIGN=y
   CONFIG_HIDE_LOGO_VERSION=y
   CONFIG_SPLASH_SOURCE=y
   CONFIG_VIDEO_BMP_GZIP=y
   CONFIG_BMP_24BPP=y
   CONFIG_BMP_32BPP=y
   CONFIG_SPL_GZIP=y
   CONFIG_SPL_VIDEO=y
   CONFIG_SPL_SPLASH_SCREEN=y
   CONFIG_SPL_SPLASH_SOURCE=y
   CONFIG_SPL_VIDEO_TIDSS=y
   CONFIG_SPL_BMP=y
   CONFIG_SPL_BOARD_INIT=y
   CONFIG_FS_LOADER=y
   CONFIG_SPL_SYS_WHITE_ON_BLACK=y
   CONFIG_SYS_SPL_MALLOC=y
   CONFIG_SPL_BMP_24BPP=y
   CONFIG_SPL_BMP_32BPP=y
   CONFIG_SPL_SPLASH_SCREEN_ALIGN=y
   CONFIG_SPL_DM_DEVICE_REMOVE=y
   CONFIG_SPL_VIDEO_BMP_GZIP=y
   CONFIG_SPL_HIDE_LOGO_VERSION=y
   CONFIG_BLOBLIST=y
   CONFIG_BLOBLIST_ADDR=0x80D00000

U-boot proper
^^^^^^^^^^^^^
To enable splash screen at u-boot proper enable following configs configs/am62x_evm_a53_defconfig:

.. code-block:: kconfig

   CONFIG_DM_GPIO=y
   CONFIG_CMD_BMP=y
   CONFIG_SYSCON=y
   CONFIG_VIDEO=y
   CONFIG_SYS_WHITE_ON_BLACK=y
   CONFIG_VIDEO_TIDSS=y
   CONFIG_SPLASH_SCREEN=y
   CONFIG_SPLASH_SCREEN_ALIGN=y
   CONFIG_HIDE_LOGO_VERSION=y
   CONFIG_SPLASH_SOURCE=y
   CONFIG_VIDEO_BMP_GZIP=y
   CONFIG_BMP_24BPP=y
   CONFIG_BMP_32BPP=y
   CONFIG_BMP=y
   CONFIG_VIDEO_BMP_GZIP=y

Enabling splash screen on custom board based on AM62x SoC
---------------------------------------------------------
To enable splash screen on custom board based on AM62x SoC follow steps below:

#. Add video driver and panel node in the dts file by referring following patches:

   #. `arm: dts: k3-am62-main: Add device tree node for TIDSS  <https://git.ti.com/cgit/ti-u-boot/ti-u-boot/commit/?h=ti-u-boot-2023.04&id=53104ee32a8ceb350abcd00210bf1290de0373b6>`_
   #. `arm: dts: k3-am625-sk: Add pin control for TIDSS and add panel device tree node <https://git.ti.com/cgit/ti-u-boot/ti-u-boot/commit/?h=ti-u-boot-2023.04&id=4ce7c709975429b4537f5555f7cee30f45d253b4>`_
   #. `arch: arm: dts: k3-am625-sk: add bootph-pre-ram flags <https://git.ti.com/cgit/ti-u-boot/ti-u-boot/commit/?h=ti-u-boot-2023.04&id=dca8245419503c55e60ed6671dbde36f9143b439>`_

#. Add configs mentioned in Upstream u-boot section in the board_defconfig, depending on the stage in
   which splash screen is to be displayed.

#. Define splash file locations struct in board.c file, to enable different boot media for splash, for reference
   board/ti/am62x/evm.c.

#. Define splash related env variables in board.env file, reference board/ti/am62x/evm.c.

Refer section `Display custom logo as splash screen`_
to know more about splash file location struct and env variables.

Display image using u-boot command line
---------------------------------------
To test display and video driver in U-boot, at U-boot console run the following commands.

.. code-block:: console

      #To see all the files in your boot partition run
      => ls mmc 1

      #To load image
      => fatload mmc 1 $loadaddr ti_logo_414x97_32bpp.bmp.gz

      #To display image
      =>  bmp display $loadaddr m m

The above command will display an image at centre of the screen.

.. code-block:: console

      #To get bmp image info
      => bmp info

Run splash screen using OSPI NOR
--------------------------------
#. To load bmp image on OSPI NOR run the following commands

.. code-block:: console

      => sf probe
      => fatload mmc 1 $loadaddr file_name.bmp
      => sf update $loadaddr 0x700000 $filesize

#. Change splashsource to sf in board.env, recompile tispl.bin for SPL stage and u-boot.img for U-boot
   proper.

.. note::
   OSPI NOR doesn't support displaying gzip bmp image.

Display RLE compressed image
-----------------------------
Enable following kconfigs to support **8bit** RLE compressed image.

.. code-block:: kconfig

      CONFIG_SPL_VIDEO_BMP_RLE8  #for SPL splash screen
      CONFIG_VIDEO_BMP_RLE8      #for U-boot splash screen

Flicker free display across boot stages and Linux Kernel
--------------------------------------------------------

#. AM62x 9.1 SDK release supports flicker free display with splash screen displayed persistently across all the bootloader stages starting from A53 SPL to U-boot proper using a bloblist based scheme, where framebuffer related information like size of framebuffer, address of framebuffer are passed from A53 SPL to U-boot proper using Video Bloblist.

#. It also supports persistent splash screen display while operating system is booting up, along with seamless transition to Linux Boot logo and thereafter to psplash boot animation using a simple-framebuffer based approach as described below :

#. To make sure that splash screen remains persistent while Linux Kernel boots up, framebuffer region was marked as reserved in linux device tree arch/arm64/boot/dts/ti/k3-am62x-sk-common.dtsi by defining the video frame-buffer address and size as shown below :

    .. code-block:: dts

          framebuffer: framebuffer@ff700000 {
                 reg = <0x00 0xff700000 0x00 0x008ca000>;
                 no-map;
          };

#. To enable seamless transition from bootloader splash screen to Linux boot logo and thereafter to Psplash based boot animation, simple-framebuffer driver was enabled in arch/arm64/configs/defconfig along with adding a device-tree node for simple-framebuffer describing the framebuffer context at arch/arm64/boot/dts/ti/k3-am62x-sk-common.dtsi:

    .. code-block:: kconfig

          CONFIG_FB_SIMPLE=y

    .. code-block:: dts

           framebuffer0: framebuffer@0 {
                 compatible = "simple-framebuffer";
                 power-domains = <&k3_pds 186 TI_SCI_PD_EXCLUSIVE>;
                 clocks = <&k3_clks 186 6>,
                 <&k3_clks 186 0>,
                 <&k3_clks 186 2>;
                 display = <&dss>;
                 reg = <0x00 0xff700000 0x00 0x008ca000>;
                 width = <1920>;
                 height = <1200>;
                 stride = <(1920 * 4)>;
                 format = "x8r8g8b8";
           };

    .. note::

       More information regarding simple-framebuffer can be viewed at `simple-framebuffer device-tree binding doc <https://github.com/torvalds/linux/blob/master/Documentation/devicetree/bindings/display/simple-framebuffer.yaml>`_

       Even if a non-linux based custom bootloader is used to display splash screen before transitioning to Linux, the framebuffer related information can be updated in aforementioned device-tree nodes to enable seamless and flicker free transition during operating system bootup along with reduced memory footprint.

#. The above scheme also ensures that bootloader allocated framebuffer region is re-used by Linux kernel for displaying the boot logo and animation even before linux kernel loads the display driver, thus    giving a seamless experience during transition.


Flicker free and persistent display until display server
--------------------------------------------------------
If user wants to keep the boot animation alive until display server starts up, then they need to manually disable "DRM framebuffer device emulation" feature in arch/arm64/configs/defconfig. This is required since the framebuffer emulation feature disables the simple-framebuffer region and resets the display hardware before taking control of the display.

.. code-block:: kconfig

      # CONFIG_DRM_FBDEV_EMULATION is not set

.. note::

   The above option is enabled by default in the SDK, so user will need to disable it manually in case they desire above feature and they are not using DRM fbdev emulation feature for any of their end applications.
