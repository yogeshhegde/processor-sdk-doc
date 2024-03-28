.. include:: /_replacevars.rst

.. role:: console(code)
  :language: console
  :class: highlight

.. _Chromium_Browser-label:

Chromium Browser - User Guide
=============================

Overview
--------

On TI devices with IMG Rogue class GPU's.  The Chromium browser (available from https://chromium.googlesource.com/chromium/src/)
is accelerated using OpenGLES.

The version of Chromium that is build can be obtained with this command:

.. code-block:: console

    $ chromium --version
    Chromium 111.0.5563.64 stable

The version of Chromium shown here is the one that GPU acceleration is verified to work with.

Executing Chromium
------------------

*For security reasons it is suggested never to run Chromium as the root user.*

To run the Chromium browser:

Assuming you are logged in as the root user.

Switch to the weston user:

.. code-block:: console

    $ su weston

And then run the chromium binary:

.. code-block:: console

    $ /usr/bin/chromium [url] [options]

e.g.

.. code-block:: console

    $ chromium https://www.ti.com

Will open www.ti.com in a windowed browser on the Weston desktop.

.. code-block:: console

    $ chromium https://webglsamples.org/aquarium/aquarium.org --start-fullscreen

Will open the aquarium 3d benchmark in a fullscreen window on the Weston desktop.

The :console:`--start-fullscreen` switch will make the chromium browser consume the entire screen including overwriting the Weston menu bar.

This will start chromium and provided you have network connectivity to the internet from the TI platform it will
connect to an example application that uses WebGL/Javascript and renders fish swimming in a fish bowl using the 3D GPU.

To see the GPU features that are in use, enter :code:`chrome://gpu` into the Chromium URL/Navigation bar. A web page will be
rendered with this information. The below example shows what is enabled/disabled when GPU acceleration is working correctly:

Graphics Feature Status
-----------------------

.. code-block::

    *   Canvas: Hardware accelerated
    *   Canvas out-of-process rasterization: Disabled
    *   Direct Rendering Display Compositor: Disabled
    *   Compositing: Hardware accelerated
    *   Multiple Raster Threads: Enabled
    *   OpenGL: Enabled
    *   Rasterization: Hardware accelerated
    *   Raw Draw: Disabled
    *   Video Decode: Hardware accelerated
    *   Video Encode: Software Only. Hardware acceleration disabled
    *   Vulkan: Disabled
    *   WebGL: Hardware accelerated
    *   WebGL2: Hardware accelerated
    *   WebGPU: Disabled


If for some reason you suspect the GPU is rending something incorrectly, you can run chromium with GPU disabled
using the :console:`--disable-gpu` flag:

.. code-block:: console

    $ chromium https://webglsamples.org/aquarium/aquarium.html --start-fullscreen --disable-gpu


To get raw performance numbers from the GPU, you may want to disable frame sync locking in Chromium. This will tell Chromium never to wait for VSYNC and render as fast as the GPU can achieve.

.. code-block:: console

    $ chromium https://webglsamples.org/aquarium/aquarium.html --start-fullscreen --disable-gpu-vsync --disable-frame-rate-limit 


Running Chromium as the root user
---------------------------------

This is absolutely not recommended, as to do so gives a web page too much access to your system.  
To run in this mode you also have to provide the :console:`--no-sandbox` switch, which disables all sandboxing
of the browser from the base system and could leave you open for a malicious webpage to do something
nefarious.


How to build Chromuim under Yocto
---------------------------------

Pull in the meta-browser and meta-clang layer into a Kirkstone Yocto build.

meta-browser should be pinned to commit:

.. code-block::

    commit d3d16b47e17dc899e5298cff698dc32e5e639ab4 (HEAD)
    Author: Max Ihlenfeldt <max@igalia.com>
    Date:   Wed Mar 8 11:02:47 2023 +0000

        chromium: update to 111.0.5563.64


meta-clang needs to be pinned to HEAD commit of branch kirkstone-clang12, as of the time of writing that equates to this commit:

.. code-block::

    commit c2e89dc7e1dfcc1bbe432afca2dc43d6560cb007 (HEAD -> origin/kirkstone-clang12)
    Author: Randy MacLeod <Randy.MacLeod@windriver.com>
    Date:   Tue Jan 17 13:25:56 2023 -0800

With these layers pinned to the correct commit, you need to make sure they are referenced in :console:`build/conf/bblayers.conf``
This is done automatically if you use the oe-layersetup tool.

.. code-block:: console

    $ cd yocto_dir
    $ ./oe-layersetup -f config/arago-kirkstone-chromium-config.txt

Once this is done, use bitbake to create the tisdk-default-image. This will 
detect the meta-browser and meta-clang layers, automatically building and 
adding Chromium to the root filesystem image.

.. note::

    Build times of Chromium can be very long depending on the size of your build machine.   It has been found that you need
    at least 64Gigs of RAM, and on a 28 thread Intel Core-I9 with an SSD for the build driver it will still take upwards of 2 hours just
    to build Chromium.   A full Yocto kirkstone build that includes Chromium can easily take 400GBytes of SSD.

The following will initiate a full tisdk-default-image build that would include
Chromium if the meta-browser and meta-clang layers are present:

.. code-block:: console

    $ MACHINE=<machine> bitbake tisdk-default-image

If you want to significantly reduced image size, the IPKs can be built
directly using the following:

.. code-block:: console

    $ MACHINE=<machine> bitbake core-image-weston
    $ MACHINE=<machine> bitbake chromium-ozone-wayland

Where <machine> is defined in the :ref:`Build Options section of "Building the SDK with Yocto" <Build_Options>`

:console:`tisdk-default-image` is the only image that chromium will get built
into by default.  If you want to build it into another image, then you would need to modify the .bb recipe for the image.  Or alternatively
add the line:

.. code-block:: console
    
    IMAGE_INSTALL:append = " chromium-ozone-wayland"

Somewhere into your :file:`build/conf/local.conf` file.

Limitations
-----------

* Audio/video within the browser is not supported.
* Hardware acceleration of video either decode or encode is not supported.
* Versions newer than Chromium v111 have rendering artifacts around chromium UI elements and are currently not supported.

Performance
-----------

**Performance of WebGL Aquarium**

Standard WebGL benchmarks available at these URLS: https://webglsamples.org/aquarium/aquarium.html

Run as the weston user with the command line :console:`chromium https://webglsamples.org/aquarium/aquarium.html --start-fullscreen`


.. ifconfig:: CONFIG_part_variant in ('AM62PX')

        +---------------------------------+----------------------+------------------------------------------------+
        | **Platform**                    | **Performance FPS**  | **GPU Utilisation**                            |
        +---------------------------------+----------------------+------------------------------------------------+
        | |__PART_FAMILY_DEVICE_NAMES__|  | 40 @ 1080p60         | 72%                                            |
        +---------------------------------+----------------------+------------------------------------------------+

    .. note::

          GPU Utilisation is captured using,

          .. code-block:: console

              root@am62pxx-evm:~# cat /sys/kernel/debug/pvr/status

.. ifconfig:: CONFIG_part_variant in ('AM62X')

        +---------------------------------+----------------------+------------------------------------------------+
        | **Platform**                    | **Performance FPS**  | **GPU Utilisation**                            |
        +---------------------------------+----------------------+------------------------------------------------+
        | |__PART_FAMILY_DEVICE_NAMES__|  | 9 @ 1080p60          | 100%                                           |
        +---------------------------------+----------------------+------------------------------------------------+

       .. note::

          GPU Utilisation is captured using,

          .. code-block:: console

              root@am62xx-evm:~# cat /sys/kernel/debug/pvr/status

.. ifconfig:: CONFIG_part_variant in ('J722S')

        +---------------------------------+-----------------------------------------------------------------------+
        | **Platform**                    | **Performance FPS**                                                   |
        +---------------------------------+-----------------------------------------------------------------------+
        | |__PART_FAMILY_DEVICE_NAMES__|  | 36 @ 1080p60                                                          |
        +---------------------------------+-----------------------------------------------------------------------+

.. ifconfig:: CONFIG_part_variant in ('J721S2')

        +---------------------------------+-----------------------------------------------------------------------+
        | **Platform**                    | **Performance FPS**                                                   |
        +---------------------------------+-----------------------------------------------------------------------+
        | |__PART_FAMILY_DEVICE_NAMES__|  | 53 @ 1080p60                                                          |
        +---------------------------------+-----------------------------------------------------------------------+

.. ifconfig:: CONFIG_part_variant in ('J784S4')

        +---------------------------------+-----------------------------------------------------------------------+
        | **Platform**                    | **Performance FPS**                                                   |
        +---------------------------------+-----------------------------------------------------------------------+
        | |__PART_FAMILY_DEVICE_NAMES__|  | 60 @ 1080p60                                                          |
        +---------------------------------+-----------------------------------------------------------------------+

**Performance of MotionMarkv1.3**

Standard Javascript benchmarks available at these URLS: https://browserbench.org/MotionMark/

Run as the weston user with the command line :console:`chromium https://browserbench.org/MotionMark/ --start-fullscreen`
use the mouse to click the "Run Benchmark" button.

.. ifconfig:: CONFIG_part_variant in ('AM62PX')

        +---------------------------------+-----------------------------------------------------------------------+
        | **Platform**                    | **MotionMark v1.3**                                                   |
        +---------------------------------+-----------------------------------------------------------------------+
        | |__PART_FAMILY_DEVICE_NAMES__|  | 40.35 @ 1080p60                                                       |
        +---------------------------------+-----------------------------------------------------------------------+

.. ifconfig:: CONFIG_part_variant in ('AM62X')

        +---------------------------------+-----------------------------------------------------------------------+
        | **Platform**                    | **MotionMark v1.3**                                                   |
        +---------------------------------+-----------------------------------------------------------------------+
        | |__PART_FAMILY_DEVICE_NAMES__|  | 1.82 @ 1080p60                                                        |
        +---------------------------------+-----------------------------------------------------------------------+

.. ifconfig:: CONFIG_part_variant in ('J722S')

        +---------------------------------+-----------------------------------------------------------------------+
        | **Platform**                    | **MotionMark v1.3**                                                   |
        +---------------------------------+-----------------------------------------------------------------------+
        | |__PART_FAMILY_DEVICE_NAMES__|  | 31.40 @ 1080p60                                                       |
        +---------------------------------+-----------------------------------------------------------------------+

.. ifconfig:: CONFIG_part_variant in ('J721S2')

        +---------------------------------+-----------------------------------------------------------------------+
        | **Platform**                    | **MotionMark v1.3**                                                   |
        +---------------------------------+-----------------------------------------------------------------------+
        | |__PART_FAMILY_DEVICE_NAMES__|  | 64.23 @ 1080p60                                                       |
        +---------------------------------+-----------------------------------------------------------------------+

.. ifconfig:: CONFIG_part_variant in ('J784S4')

        +---------------------------------+-----------------------------------------------------------------------+
        | **Platform**                    | **MotionMark v1.3**                                                   |
        +---------------------------------+-----------------------------------------------------------------------+
        | |__PART_FAMILY_DEVICE_NAMES__|  |  129.27 @ 1080p60                                                     |
        +---------------------------------+-----------------------------------------------------------------------+

