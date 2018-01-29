.. http://processors.wiki.ti.com/index.php/How_to_Change_dtb_File
.. rubric:: Introduction
   :name: introduction

In some scenarios, it is required to manually change the dtb file used
by the target. For example, AM437X GP EVM uses LCD display by default.
But it also supports HDMI display. In order to switch from LCD display
to HDMI display, user needs to set the dtb file as desired.

| 

.. rubric:: Specify dtb File
   :name: specify-dtb-file

The dtb files are located on the target filesystem under "/boot"
directory. First, identify the dtb file to be used, e.g.,
am437x-gp-evm-hdmi.dtb for AM437X GP EVM with HDMI display.

Then, modify "uEnv.txt" on the boot partition ("/run/media/mmcblk0p1"
directory on filesystem) to specify fdtfile with the desired dtb file
name.

Using AM4 as the example, the default uEnv.txt has the lines below.
Follow the instructions to set fdtfile so that HDMI display can be
enabled. In order to go back to LCD dispaly, unset fdtfile to use the
default am437x-gp-evm.dtb.

::

    # Uncomment the following line to enable HDMI display and disable LCD display.
    #fdtfile=am437x-gp-evm-hdmi.dtb

After the dtb file is changed, reboot the EVM so that the new dtb file
will be used for booting the EVM.

.. raw:: html

