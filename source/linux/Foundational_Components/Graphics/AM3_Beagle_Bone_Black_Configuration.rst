..
    This subsection includes content specific to AM3 Beagle Bone Black board


AM3 Beagle Bone Black Board Configuration
=========================================

AM335x has a HW bug, chapter 3.1.1 in the errata: "The blue and red
color assignments to the LCD data pins are reversed when operating in
RGB888 (24bpp) mode compared to RGB565 (16bpp) mode." Therefore, the
applications need to always use either 24 or 16 bpp modes, depending on
the display HW connected to the board. The default pixel format XRGB8888
of the graphics application back ends and drivers within PSDK is not
supported at the AM3 Beagle Bone Black Board where it is in 16bpp mode.
To enable appropriate graphics display, make the following changes at
various graphics related configuration files:

-  /etc/powervr.ini: add DefaultPixelFormat=RGB565
-  /etc/weston.ini: add gbm-format=rgb565 at section [core]
-  /etc/profile.d/qt\_env.sh: add export
   QT\_QPA\_EGLFS\_INTEGRATION=none

Another restriction of AM335x-based platform is that the width of
display resolution must be multiple of 32. For example, 1360x768 will
not work. The simple workaround is to specify the display resolution as
one of the kernel boot parameters for non-Weston application and at
/etc/weston.ini for Weston server. For example,

-  the following commands need to be executed at boot prompt

::

    => setenv optargs video=HDMI-A-1:1024x768
    => saveenv

-  add the HDMI-A configuration to /etc/weston.ini in a new "output"
   section, as shown below:

::

    [output]
    name=HDMI-A-1
    mode=1024x768

|
