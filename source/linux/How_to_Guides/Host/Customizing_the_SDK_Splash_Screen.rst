.. http://processors.wiki.ti.com/index.php/Customizing_the_SDK_Splash_Screen

Customizing the SDK Splash Screen
=============================================
.. rubric:: Overview
   :name: overview

This article discusses how to customize the splash screen for the Linux
SDK. The info was derived from `this e2e forum
post <http://e2e.ti.com/support/arm/sitara_arm/f/791/p/325588/1133908.aspx#1133908>`__.

.. rubric:: Steps
   :name: steps

The "psplash" user space application is called at boot time, showing the
TI logo splash screen. In order to change the displayed image, you need
to first download the "psplash" package source code from
`here <http://git.yoctoproject.org/cgit/cgit.cgi/psplash/>`__. The next
steps are as follows:

1. Use the ./make-image-header.sh script included in the package to
create a new header file with your new image: (you need to install
libgdk-pixbuf2.0-dev library first)

::

    ./make-image-header.sh <path_to_image_file> <NAME>

Note: The <NAME> argument can be whatever you want it to be, but for the
fastest approach you should use "POKY" as this is what is used by
default in the psplash.c file. Unfortunately this isn't configurable and
you have to edit the file manually if you wish to use different name.

- The above command will generate the header file with the image
  contents (<your\_logo\_filename>-img.h).
- Open the psplash.c file and replace the file name in the following line
  at the top of the file:

::

    #include "psplash-poky-img.h"

with

::

    #include "<your_logo_filename>-img.h"

2.Export the needed variables and then configure and build psplash:

::

    export CROSS_COMPILE=arm-linux-gnueabihf-
    export ARCH=arm
    export PATH=$PATH:$HOME/ti-sdk-am335x-evm-06.00.00.00/linux-devkit/sysroots/i686-arago-linux/usr/bin
    ./autogen.sh --host=arm-linux CC=arm-linux-gnueabihf-gcc
    make

3. Replace the /usr/bin/psplash file in your root file system with the
generated psplash file.

