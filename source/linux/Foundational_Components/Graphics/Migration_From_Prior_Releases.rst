..
    This subsection provides details on the migration of the SDK from older
    releases.

Migration from prior releases
=============================

from Processor SDK 1.x to 2.x for AM3, AM4
------------------------------------------

The SGX driver has been enhanced to support DRM based Full Window
Display in processor SDK 2.0 and the FBdev based Full Window modes are
no longer supported. The System startup and most of the Graphics
applications are backward-compatible except with the following changes.

.. rubric:: Window System Libraries
   :name: window-system-libraries

The FBdev based Full Screen window systems are no longer supported:

-  libpvrPVR2D\_FRONTWSEGL.so (for direct writes to FrameBuffer - FRONT
   mode of operation - directly writes to FrameBuffer without waiting
   for vsync - fastest mode of operation)
-  libpvrPVR2D\_FLIPWSEGL.so (for VSync synchronised writes to
   Framebuffer - slower, but avoids tearing)
-  libpvrPVR2D\_BLITWSEGL.so (for direct writes to back-buffer, which
   later gets written to \*FrameBuffer with sync)

Instead the DRM based Full Screen window system are provided:

-  libpvrDRMWSEGL\_FRONT.so (for direct writes to DRM FrameBuffer -
   FRONT mode of operation - directly writes to FrameBuffer without
   waiting for vsync - fastest mode of operation)
-  libpvrDRMWSEGL.so (for VSync synchronised writes to DRM Framebuffer -
   slower, but avoids tearing)

The window system is specified by the PVR configuration parameter
WindowSystem at the PVR configuration file /etc/powervr.ini. By default,
that parameter is set to libpvrDRMWSEGL\_FRONT.so for nullDRM Front
mode. To configure the PVR SGX to operate in nullDRM FLIP mode, edit the
PVR configuration file to set the parameter WindowSystem to
libpvrDRMWSEGL.so. The change will take effect when any graphic
application is launched next time.

.. rubric:: Obsolete Test Programs
   :name: obsolete-test-programs

The following test programs are no longer applicable and removed from
the SDK file system

-  /usr/bin/sgx\_blit\_test
-  /usr/bin/sgx\_flip\_test
-  /usr/bin/sgx\_render\_flip\_test
-  /usr/bin/sgx\_render\_test

from Processor SDK 2.0.0 to 2.0.x for AM4
-----------------------------------------

The SGX driver has been enhanced to support DRM/WAYLAND based
Multi-Window Display in processor SDK 2.0.1. The System startup and most
of the Graphics applications are backward-compatible except with the
following changes.

.. rubric:: Window System Libraries
   :name: window-system-libraries-1

The DRM based Full Screen window systems are no longer supported:

-  libpvrDRMWSEGL\_FRONT.so (for direct writes to DRM FrameBuffer -
   FRONT mode of operation - directly writes to FrameBuffer without
   waiting for vsync - fastest mode of operation)
-  libpvrDRMWSEGL.so (for VSync synchronised writes to DRM Framebuffer -
   slower, but avoids tearing)

Instead the DRM/WAYLAND based multi-window system are provided:

-  libpvrws\_KMS.so
-  libpvrws\_WAYLAND.so

The window system will be dynamically loaded by DDK based on the
application use case, so that the PVR configuration parameter
WindowSystem at the PVR configuration file /etc/powervr.ini is no longer
used.

from Processor SDK 2.0.1 to 2.0.x for AM3/4/5
----------------------------------------------

The SGX driver has been enhanced to support DRM-based Full
Screen(NullDRM) and Multi-Window(Wayland) Display in processor SDK
2.0.2. The System startup and most of the Graphics applications are
backward-compatible except with the following changes.

.. rubric:: Window System Libraries
   :name: window-system-libraries-2

The DRM based Full Screen window system is supported:

-  libpvrDRMWSEGL.so (for VSync synchronised writes to DRM Framebuffer -
   slower, but avoids tearing)

The DRM/WAYLAND based multi-window systems are also provided:

-  libpvrGBMWSEGL.so
-  libpvrws\_WAYLAND.so

The window system will be dynamically loaded by DDK based on the
application use case, so that the PVR configuration parameter
WindowSystem at the PVR configuration file /etc/powervr.ini is no longer
required.

from Processor SDK 3.1 to 3.x for AM3/4/5
-----------------------------------------

The QT QPA eglfs\_kms, which supports multiple screens, has been enabled
and used as the default eglfs platform plugin in processor SDK 3.2. To
fallback to the standard single-screen eglfs plugin, issue the following
instruction at the command line or add the same at the QT environment
configuration file qt\_env.sh at /etc/profile.d

-  export QT\_QPA\_EGLFS\_INTEGRATION=none
