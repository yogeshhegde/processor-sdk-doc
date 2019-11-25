.. http://processors.wiki.ti.com/index.php/How_to_use_a_Mouse_instead_of_the_Touchscreen_with_Matrix

How to use a Mouse instead of the Touchscreen with Matrix
==================================================================
.. rubric:: Introduction
   :name: introduction-use-mouse-instead-of-touch

A mouse can be used instead of touchscreen input with the Matrix GUI by
following these steps. It is also possible to use touchscreen and mouse
input simultaneously.

**Restrictions:** For AM37x and AM35x: The mouse must be connected
through a USB 2.0 hub to the EVM. It must not be connected directly to
the EVM.

.. rubric:: Enable Mouse
   :name: enable-mouse

On your Target File system, edit the file: /etc/init.d/matrix-gui-2.0
This script file will set Mouse support by default, but if it detects a
touchscreen, then it will setup touchscreen support. If you comment out
the touchscreen support then the default will remain mouse support. Use
the '#' to comment out the line below:

For Mouse support, Replace:

::

       if [ -e /dev/input/touchscreen0 ]
       then
           export QWS_MOUSE_PROTO=Tslib:/dev/input/touchscreen0
       fi

with

::

    #   if [ -e /dev/input/touchscreen0 ]
    #   then
    #       export QWS_MOUSE_PROTO=Tslib:/dev/input/touchscreen0
    #   fi

To Enable both Mouse and touchscreen simultaneously: Replace

::

     export  QWS_MOUSE_PROTO=Tslib:/dev/input/touchscreen0

with

::

     export  QWS_MOUSE_PROTO="Tslib:/dev/input/touchscreen0 Auto"

**Warning**: If you enable both, the touchscreen now requires a double
touch instead of a single touch.

.. rubric:: Kernel
   :name: kernel

The Kernel has been configured to enable mouse support in your SDK, so
this step is not necessary if you are using the SDK.

If you have built your own kernel: The kernel must be configured to
include the PS/2 mouse support. To verify this, run the menuconfig
utility.

| Instructions on executing menuconfig can be found here: `Customizing
  the Kernel
  Configuration <../../Foundational_Components_Kernel_Users_Guide.html#customizing-the-configuration>`__

| 
| Look under:

Device Drivers ---> Input device support ---> <\*> Mouse interface

Device Drivers ---> Input device support ---> <\*> Mice --->

If mouse support is not already included in the kernel, enable the above
two configuration by typing 'y' and rebuild the kernel. You can find
instructions for rebuilding kernel here:

`Linux Kernel User's Guide <../../Foundational_Components_Kernel_Users_Guide.html>`__

