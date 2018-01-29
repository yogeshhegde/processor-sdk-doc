.. http://processors.wiki.ti.com/index.php/Linux_Core_LCD_Controller_User_Guide
.. rubric:: AM335x LCDC DRM Display Driver
   :name: am335x-lcdc-drm-display-driver

.. rubric:: **Introduction**
   :name: introduction

This page gives a brief description of LCDC usage with tilcdc DRM
driver. The obsolete fbdev driver wiki page also remains at the end of
this page.

This document applies TI's v4.4 kernel and mainline v4.9 kernel with
tilcdc DRM atomic modeset support.

.. rubric:: **Generic DRM Information**
   :name: generic-drm-information

What is DRM: http://dri.freedesktop.org/wiki/DRM/

What do the abbreviations KMS/GEM/DRM actually stand for: Kernel Mode
Setting, Graphics Execution Manager, Direct Rendering Manager.

Where can I find DRM documentation?

-  Online at: https://www.kernel.org/doc/htmldocs/drm/index.html
-  Or in kernel directory:

   -  make htmldocs

Use web browser to view: Documentation/DocBook/drm.html

-  DRM (dri/kms/gem) documentation is available here

   -  http://dri.freedesktop.org/wiki/Documentation/

.. rubric:: **Hardware and How It Is Used**
   :name: hardware-and-how-it-is-used

The LCD controller can be used in two independent modes. Either in the
raster controller mode or in LCD interface display driver (LIDD) mode.
The tilcdc driver support only raster controller mode.

Compared to most other DRM supported devices the LCDC provides very
limited functionality. It supports only one simple framebuffer or
alternatively two framebuffers that are automatically flipped back and
forth. The tilcdc driver uses single buffer mode and flips framebuffer
by changing the framebuffer's DMA address. This does not interfere with
the DMA of the currently drawn frame.

The LCDC supports 1-, 2-, 4-, 8-, 12-, 16-, and 24-bits per pixel modes.
The 1-, 2-, 4-, and 8-bpp modes are palette modes and are not supported
by the tilcdc driver. With the 12-, 16-, and 24-bit modes the choice is
limited to 16 and 24 bpp modes, and the 24 bpp mode is only supported by
revision 2 LCDC. There is also a problem is using 16- and 24-bit modes
with same HW, see `tilcdc Supported
Features </index.php/Linux_Core_LCD_Controller_User_Guide#tilcdc_Supported_Features:>`__
below.

.. rubric:: **LCDC memory bandwidth issues**
   :name: lcdc-memory-bandwidth-issues

LCDC sometimes suffers from memory bandwidth issues when high pixel
clocks and high bits per pixel colour formats are used. These bandwidth
issues manifest themselves as DMA FIFO underflow and frame
synchronization lost errors. The problem is solved on Beaglebone-Black
and am335x-evm with this
`patch <https://lists.denx.de/pipermail/u-boot/2016-December/275681.html>`__.
The patch is available in core sdk release version 2016.05 (Processor
SDK version 3.3) onward. A similar u-boot change is needed for any other
HW suffering from the same problem. Please check the ddr\_data for
am3-evm or beaglebone-black in the u-boot config. If after using the
patch you still see issues, you may need to further tune the value of
REG\_PR\_OLD\_COUNT per your system need.

.. rubric:: 
   **tilcdc Supported Features:**
   :name: tilcdc-supported-features

-  RGB565 color format
-  or RGB888/XRGB8888 color formats (LCDC rev2 only)

   -  The 16-bit and 24-bit video has Red and Blue wires swapped and
      depending on the wiring of the board ether 16-bit or 24-video is
      in BGR format (see section 3.1.1 in `AM335x Silicon
      Errata <http://www.ti.com/general/docs/lit/getliterature.tsp?baseLiteratureNumber=sprz360>`__)

-  Panel timings controlled from dts file
-  TDA998x HDMI encoder support on BeagleBone Black
-  Pixel clock to 126MHz allowing resolutions up to 1920x1080p24
-  Fbdev emulation is provided through /dev/fb0
-  HDMI audio support with corresponding ALSA sink (not in mainline for
   the time being)
-  HDMI EDID support
-  DRM Atomic modeset support since Linux 4.9 and in ti2016.04

.. rubric:: 
   **tilcdc Unsupported Features:**
   :name: tilcdc-unsupported-features

-  No HDMI hotplug
-  1920x1080@60 is not supported due to pixel clock requirements being
   too high for the AM335x hardware.

| 

.. rubric:: **Configuring into kernel build:**
   :name: configuring-into-kernel-build

-  By default DRM support for LCDC is not built in to the kernel when
   using omap2plus\_defconfig.
-  Make sure that the following are **disabled** from .config as the
   fbdev driver cannot coexist with the DRM driver.

   -  CONFIG\_FB\_DA8XX
   -  CONFIG\_FB\_DA8XX\_TDA998X

-  And add:

   -  CONFIG\_DRM=y/m
   -  CONFIG\_DRM\_I2C\_NXP\_TDA998X=y/m
   -  CONFIG\_DRM\_TILCDC=y/m

If using modules, it is enough to load tilcdc module, and tda998x module
if using beaglebone-black. It does not matter in which order the modules
are loaded.

| 

| 

.. rubric:: 
   **Required Device Tree Nodes:**
   :name: required-device-tree-nodes

-  See .txt files in - Documentation/devicetree/bindings/drm/tilcdc
-  For Beaglebone-Black see also:
   Documentation/devicetree/bindings/display/bridge/tda998x.txt
-  The
   `am335x-boneblack.dts <https://git.ti.com/ti-linux-kernel/ti-linux-kernel/blobs/master/arch/arm/boot/dts/am335x-boneblack.dts>`__,
   `am335x-evm.dts <https://git.ti.com/ti-linux-kernel/ti-linux-kernel/blobs/master/arch/arm/boot/dts/am335x-evm.dts>`__,
   and
   `am335x-evmsk.dts <https://git.ti.com/ti-linux-kernel/ti-linux-kernel/blobs/master/arch/arm/boot/dts/am335x-evmsk.dts>`__
   have the necessary nodes for LCDC DRM driver

Example Device Tree nodes to enable HDMI with DRM on BeagleBone Black:

::

    &lcdc {
        status = "okay";

        port {
            lcdc_0: endpoint@0 {
                remote-endpoint = <&hdmi_0>;
            };
        };
    }; 
    &i2c0 {
        tda19988: tda19988 {
            compatible = "nxp,tda998x";
            reg = <0x70>;

            #sound-dai-cells = <0>;
            audio-ports = <  TDA998x_I2S 0x03>;

            ports {
                port@0 {
                    hdmi_0: endpoint@0 {
                        remote-endpoint = <&lcdc_0>;
                    };
                };
            };
        };
    };

.. rubric:: 
   **Examples for using DRM:**
   :name: examples-for-using-drm

The drm userspace components and test applications are available from:
http://cgit.freedesktop.org/mesa/drm/

A useful tool contained in this suite is modetest.

-  On BeagleBone Black you can use modetest to try the different
   resolutions that are supported by the attached monitor.
-  For example:
-  modetest –s 5:1280x720@XB24
-  Will change the HDMI output to 1280x720 – the XB24 tells modetest to
   use the correct pixel format of XBGR8888.

.. rubric:: Legacy AM335x LCDC fbdev Display Driver
   :name: legacy-am335x-lcdc-fbdev-display-driver

This driver is currently obsolete (has been since ti-linux-3.14.y), and
is not actively maintained any more. Please use `LCDC DRM
driver </index.php/Linux_Core_LCD_Controller_User_Guide#AM335x_LCDC_Display_Driver_.28DRM.29>`__
instead.

.. rubric:: **Introduction:**
   :name: introduction-1

-  Where can I find fbdev documentation:

See Documentation/fb/framebuffer.txt Or online at:
https://www.kernel.org/doc/Documentation/fb/framebuffer.txt

.. rubric:: **LCDC fbdev Supported Features:**
   :name: lcdc-fbdev-supported-features

-  RGB32 pixel format (XBGR32 format)
-  Panel timings controlled from dts file
-  TDA998x HDMI encoder support on BeagleBone Black
-  Pixel clock to 126MHz allowing resolutions up to 1920x1080p24
-  Access to driver and framebuffer is through /dev/fb0

.. rubric:: **LCDC fbdev Unsupported Features:**
   :name: lcdc-fbdev-unsupported-features

-  No HDMI audio support in fbdev driver
-  No HDMI EDID support
-  No HDMI hotplug

.. rubric:: **Configuring into kernel build:**
   :name: configuring-into-kernel-build-1

-  The necessary .config options are:

   -  CONFIG\_FB\_DA8XX
   -  CONFIG\_FB\_DA8XX\_TDA998X

.. rubric:: **Required Device Tree Nodes (no HDMI)**
   :name: required-device-tree-nodes-no-hdmi

-  See Documentation/devicetree/bindings/video/da8xx\_fb.txt

.. rubric:: **Required Device Tree Nodes (with HDMI)**
   :name: required-device-tree-nodes-with-hdmi

-  See arch/arm/boot/dts/am335x-boneblack.dts for complete example of
   how to use.

::

    &i2c0 {
       hdmi1: hdmi@70 {
            compatible = "nxp,tda998x";
            reg = <0x70>;
      };
    };

    &lcdc {
       hdmi = <&hdmi1>;
       display-timings {
            /* provide your display timings here for HDMI */
       };
    };

| 

.. raw:: html

