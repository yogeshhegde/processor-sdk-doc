.. http://processors.wiki.ti.com/index.php/SGXDbgInfo

SGX Debug Info
===============

.. rubric:: Introduction
   :name: introduction-linux-sgx-dbg

The TI OMAP/AM/DM SGX Graphics Driver is closely tied to the environment
it is running under, and the configuration it is built with. This
article mentions debugging methods specific to Linux.

.. rubric:: Baselining the current SGX driver environment
   :name: baselining-the-current-sgx-driver-environment

The current SGX driver environment on the target can be observed using
the below script.

https://gforge.ti.com/gf/download/docmanfileversion/203/3715/gfx_check.sh

This script performs the below actions:

::

    #!/bin/sh
    echo "WSEGL settings"
    cat /etc/powervr.ini
    echo "------"
    echo "ARM CPU information"
    cat /proc/cpuinfo
    echo "------"
    echo "SGX driver information"
    cat /proc/pvr/version
    echo "------"
    echo "Framebuffer settings"
    fbset -i
    echo "------"
    echo "Rotation settings"
    cat /sys/class/graphics/fb0/rotate
    echo "------"
    echo "Kernel Module information"
    lsmod
    echo "------"
    echo "Boot settings"
    cat /proc/cmdline
    echo "------"
    echo "Linux Kernel version"
    uname -a

.. rubric:: Run-time checks/configuration of the SGX driver
   :name: run-time-checksconfiguration-of-the-sgx-driver

One can confirm whether the SGX drivers have been properly installed by
checking the following

-  One should have seen the message on serial console- "Initializing the
   graphics driver ..." just before getting the linux command prompt.
-  lsmod shows pvrsrvkm module inserted successfully without any error
   messages on console.

The SGX driver can be configured at run-time on the target using a
configuration file.

The optional configuration file is installed by the Processor SDK
installer at,

/etc/powervr.ini

Configuration items are specified using the below syntax

KeyWord=ParamValue

Important configuration parameters are mentioned below.

.. rubric:: WindowSystem
   :name: windowsystem

::

    * WindowSystem - This configuration item controls the low level window system that the EGL implementation should hook it up. This item takes the below values 

    * libpvrDRMWSEGL.so (DRM-based WS for VSync synchronised writes to Framebuffer - slower, but avoids tearing)

    * libpvrGBMWSEGL.so (GBM-based WS where it is up to application to perform KMS operations)

.. rubric:: DisableHWTextureUpload
   :name: disablehwtextureupload

::

    * DisableHWTextureUpload - This configuration item enables/disables the use of SGX Transfer queue hardware. 
    * If set to 1, uses software upload (copying from driver to SGX) of textures, rather than transfer queue (using the SGX hardware). 
    * Useful to rule out problems in TQ.

.. rubric:: DefaultPixelFormat
   :name: defaultpixelformat

::

    * DefaultPixelFormat - This configuration item sets the default display pixel format. 

For eg if one wants to configure the default pixel format, then edit /etc/powervr.ini to have following line
     DefaultPixelFormat=ARGB8888

For AM3 Beagle Bone Black EVM
     DefaultPixelFormat=RGB565

.. rubric:: SGX Driver Failure Modes (Installation)
   :name: sgx-driver-failure-modes-installation

.. rubric:: Unable to install the kernel modules (pvrsrvkm.ko)
   :name: unable-to-install-the-kernel-modules-pvrsrvkm.ko

1. The Linux kernel has to be built with "modules" support (make
ti-sgx-ddk-km and make ti-sgx-ddk-km\_install)

2. The kernel modules of the Graphics driver have to be built, after the
linux kernel is built in the above manner. ie, the kernel modules need
to match the kernel version that will actually run on the target.

3. If the services kernel module (pvrsrvkm.ko) does not load, it is
likely because of mismatches between user mode binaries and kernel
modules. If the kernel modules are built correctly as specified, post
the issue on the E2E forum with the output of the gfx\_check.sh script
linked in earlier section.

.. rubric:: SGX Driver Failure Modes (Run time)
   :name: sgx-driver-failure-modes-run-time

.. rubric:: Vertical Tearing/ Artifacts/ Clipping issues/ Missing
   objects
   :name: vertical-tearing-artifacts-clipping-issues-missing-objects

This could potentially be due to an incorrect usage in the OpenGL
application, or point to an issue in the driver. Note that the deferred
rendering mode of the SGX HW, will cause different behaviour compared to
the immediate renderers found on desktops.

Please contact TI through the Linux E2E forums (http://e2e.ti.com/)

.. rubric:: Demos are not running at required speed, How to check SGX
   clock rate?
   :name: demos-are-not-running-at-required-speed-how-to-check-sgx-clock-rate

If the demos are running slower than expected, check and ensure that
the clock frequency set for the SGX driver is correct. This can be
done by the following code in the KM kernel drivers -

File - eurasia\_km/services4/system/omap/sysutils\_linux.c
Function - EnableSGXClocks()

You can print the SGX clock rate in debug build as below -

::

    IMG_UINT32 rate = clk_get_rate(psSysSpecData->psSGX_FCK);
    PVR_TRACE(("Sgx clock is %dMHz", HZ_TO_MHZ(rate)));

Depending on the TI platform used, this will vary from 200 to 532 MHz.
Ensure that SGX is running at the right clock.

If this is right & still demos are not running with expected
performance, it is needed to optimize the application, and its usage of
OpenGL API.

.. rubric:: Qt demos do not work when powerVR is enabled
   :name: qt-demos-do-not-work-when-powervr-is-enabled

1. Confirm that the GLES2 demos provided in the Graphics SDK are running
properly with default SDK configuration of the window system.

2. Confirm that kernel module (pvrsrvkm.ko) is successfully loaded.

3. Confirm with fbset command to check alpha to be non zero. If not set
to appropriate value using fbset. QT supports 16, 32 bpp but expects
alpha to be non zero for 32 bpp.

4. If above steps are correct, post to E2E forum with the output of the
gfx\_check.sh script linked in earlier section. Also attach the console
log, with the below option enabled in the environment

::

    "QT_DEBUG_PLUGINS=1"

.. rubric:: Posting to E2E forum
   :name: posting-to-e2e-forum

For suggestions or recommendations or bug reports, post details of your
application as below to the E2E forums (http://e2e.ti.com/), with below
information:

-  Output of gfx environment baseline script available below, run on the
   target:

https://gforge.ti.com/gf/download/docmanfileversion/203/3715/gfx_check.sh

-  Details of UI application, as shown in below sheet.

https://gforge.ti.com/gf/download/docmanfileversion/220/3798/UI_graphics_reqs_sheet_v1.xls

These two outputs will help in debugging common issues.

