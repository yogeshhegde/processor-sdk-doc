***************************************************
Processor SDK Android Getting Started Guide
***************************************************

.. rubric:: Welcome to the Android Getting Started Guide
   :name: welcome-to-the-android-getting-started-guide

Thanks for your interest in learning more about the Android Software
Development Kit (SDK). The SDK as we affectionately call it is our
attempt to provide a great starting point to develop an embedded
system on a TI Processor running Android. Given this goal, we wanted
to provide something that is more than just a typical Board Support
Package (BSP) containing a bootloader, Linux kernel, and Android
filesystem. While these are certainly necessary elements, we feel they
are just a starting point, especially for those that aren’t experts in
developing with Android. So, the SDK also contains tools for
developing on TI Processors (a validated cross-compiling toolchain,
for example), pre-built libraries that you can use without having to
rebuild them yourself, and some documentation to help explain how all
of these pieces work together. We package all of this together with a
working Android Embedded System that has been built with all of the
things mentioned above.

What it really serves as is a “known good” starting point. One of the
big challenges with starting development on a new platform (not to
mention, a new Operating System (OS) for many), is getting an
environment set up where you can build and debug code on hardware. The
SDK attacks this problem with providing everything you need to do
development, and it is validated on standard `TI hardware platforms
(EVMs) <Release_Specific.html#supported-platforms-and-versions>`__.
It wraps all of this up into one simple installer that helps get
everything you need in the right place to do development. For example,
you can start off with simply re-building the Android Embedded System
that we provide to validate that everything is working on your system.
This simple step gives you confidence that you can move forward from a
good baseline.

As you go along your development journey and have questions, there is
documentation and support available to you. Make sure to save a pointer
to the `Android SDK Software Developer’s Guide
(SDG) <Overview.html#processor-sdk-android-software-developers-guide>`__.
If you don’t find what you need, take a look at the active `E2E Processor
Support <https://e2e.ti.com/support/processors/>`__
Forum and see if the topic has been covered before. If not, post
a new thread and we’ll do our best to provide some guidance.

.. rubric:: What would you like to do with the SDK?
   :name: what-would-you-like-to-do-with-the-sdk

As described above, the SDK has a lot to it. Let’s break it down to two
pieces to simplify things a bit:

-  The example `embedded Android
   system <Overview.html#software-stack>`__.
   Essentially, a working bootloader (U-Boot), Linux kernel, and Android
   filesystem that can be put on an SD card and ran on a TI AM57xx EVM.
-  Everything needed to create the above embedded system from “scratch”:

   -  U-Boot sources and configuration files
   -  Kernel sources and configuration files
   -  An Android cross-compiling toolchain as well as other host
      binaries and components
   -  The Android Open Source Project (AOSP) filesystem and sources for
      example applications (after syncing using the repo tool)
   -  A variety of scripts and Makefiles to automate certain tasks
   -  Other components needed to build an embedded Android system that
      don’t fit neatly into one of the above buckets

With these two pieces more clearly defined, we can now get back to that
all important question, “What would you like to do with the SDK?”. If
the answer is clearly “I want to build something and I’m ready to start
developing now!”, then go ahead and skip down to the “I want to
Develop!” (or, `Developing with the
SDK <Overview.html#start-your-android-development>`__)
section below for instructions on installing the SDK on a Linux Host
System. This is a somewhat involved process focusing on the second of
the two parts of the SDK listed above and may be more than some people
want to start with. However, it provides access to the full spectrum of
development from rebuilding the SDK from sources to fully adapting it
with new device drivers and applications.

So, if you’re not quite there yet, let’s discuss some other options.
Maybe you’d like to evaluate the SDK a bit to see if it is how you’d
like to get started.

If this is not good enough and you really want to get your hands on
something, check out the next section which shares how to play with the
embedded Android system. All you’ll need is access to a Windows/Linux
computer, an SD card, an SD card reader, some free, open-source
software, and a supported `Hardware
platform <Release_Specific.html#supported-platforms-and-versions>`__.

.. rubric:: Evaluating the SDK Embedded Android System
   :name: evaluating-the-sdk-embedded-android-system

If you’re a hands on person, reading documentation and looking at
presentations gets old fast. So, if you want to see an example of what
you can build with the SDK and actually hold it in your hands and play
with it (or show it to someone else that needs help understanding what
you want to do with it), with minimal effort, you can simply run the
SDK Embedded Android System on a `supported Hardware
platform <Release_Specific.html#supported-platforms-and-versions>`__.
This will allow you to poke and prod and interact. It’s a powerful way
to get the imagination active and engaged.

If you’ve recently purchased a TI AM572x GP EVM or an AM57xx IDK, move
on to the next step to install the SDK and boot your board using the
provided prebuilt images.

.. rubric:: Start your Android Development
   :name: start-your-android-development

OK, you’re all in. Either you’ve known this is what you wanted to do, or
you’ve gone through the above steps and you want to do more. It’s time
to develop! Here’s a high level overview:

-  Get a Linux host up and running if you don’t already have one
-  Install the SDK and run some scripts to get everything set up
-  Put the SDK Embedded Android System on an Evaluation Module to play
   with
-  Build something to validate set up – the SDK for example
-  Add something to the SDK, like a simple Hello World app

After completing these steps, you’ll have a known good baseline from
which you can start development.

#. **Configure a Linux Host** - If you already have a Linux host
   machine, go to Step 2.
   To do Android development with the SDK, you’ll need a host PC running
   Linux. The Linux host is generally much faster and has a lot more
   memory (both RAM and hard disk space) than the typical embedded
   system. While it is certainly possible to do all development
   natively, we feel the advantages of using a host provide a better way
   to go and what is supported out of the box with the SDK.
   There are many, many ways to get access to a Linux host. We simply
   can’t validate all possibilities and iterations, therefore we focus
   on validating using `Ubuntu <http://www.ubuntu.com>`__ as the host
   Linux distribution, running natively. We validate the Long-term
   Support (LTS) versions of Ubuntu at the time of a SDK release (Ubuntu
   14.04 is the currently supported LTS version).
   Can you use other versions of Ubuntu or even other distributions?
   Theoretically, yes, as long as you can get it to work and there may
   be more “assembly” required. If you can use the Ubuntu version
   validated against the SDK, it will be the smoothest path and we will
   be able to help you more if you do run into trouble.
   Likewise, we would strongly recommend getting a **native 64-bit**
   Ubuntu LTS machine set up for development. For the cost of a little
   bit of hard drive space, Ubuntu can have direct access to the host’s
   hardware. Virtual Machines (VMs) have come a long way over the years,
   and many people use them daily without problems. However, when you
   are working with a target embedded system (that may be a prototype
   board), whether it be a TI board or eventually your own, removing the
   complexity of a VM from the get go can avoid a lot of frustration
   (i.e. wasted time). When using a VM while connecting and
   disconnecting hardware components, you have to be very diligent about
   making sure what is connected to what. You might prefer using an hour
   to get more work done than debugging a perceived problem caused by
   the fact the virtual host grabbed a USB port when you weren’t
   watching.
   When you’re ready to proceed,
   `Ubuntu <http://www.ubuntu.com/download/desktop/install-desktop-long-term-support>`__
   provides a great overview for how to install natively.
   If you eventually want to rebuild the Android filesystem from source,
   you'll also need to follow the instructions from the official Android
   page
   `here <https://source.android.com/source/initializing.html#setting-up-a-linux-build-environment>`__
   for setting up the packages required for building Android.
#. **Install the SDK** - Within your Linux host machine, `Install the
   Android SDK <Overview.html#install-the-android-sdk>`__
   Processor SDK Installer is 64-bit, and installs only on 64-bit host
   machine. Support for 32-bit host is dropped as of the Gingerbread
   Android release
   At least 70 GB of free space is required on the host machine in order
   to pull and then rebuild the full AOSP filesystem
#. **Create an SD Card using the** `SDK Create SD Card
   Script <Overview.html#sd-card-creation>`__
   You will need a >4GB SD Card and the capability to connect that card
   to your Linux Host machine (using a USB SD Card reader, for example).
   If using a virtual machine as your Linux host, you may need to import
   the SD Card reader into your virtual machine (disconnect it from the
   host and connect it to the VM so that the Linux VM can see it).
#. **Configure your development environment**
   There are many ways to connect the host development platform and the
   target board. These connections will vary depending on how you like
   to develop and what you are trying to do. Here is an example of a
   common set up with a serial connection for console, an Ethernet for
   networking, and a USB connection for flashing and ADB:

   .. Image:: ../images/Android_Dev_Environment_Cropped.png

#. **Run the Setup Script** - Once the SDK has been installed and the SD
   card has been created and placed into the device, `**run the setup.sh
   Script** <Overview.html#run-setup-scripts>`__ on your
   host to guide you through the process of flashing the bootloader,
   kernel, and Android filesystem to the onboard eMMC.

.. note::

   The eMMC flashing process utilizes the fastboot
   utility of U-Boot in order to place the bootloader (U-Boot), kernel,
   and Android filesystem into non-volatile eMMC memory. For this
   reason, U-Boot running on the SD card is only needed for the initial
   flashing procedure, after this, the bootloader can be run from the
   eMMC in order to flash updated bootloaders, kernels, or filesystems.


.. note::

   Booting Android solely from the SD card is not
   supported on the Processor SDK Android v4.2 release. The SD card
   should only be used to run U-Boot in order to flash the onboard eMMC.


#. **Rebuild sources** using the `top-level
   makefile <Overview.html#top-level-makefile>`__ in
   the SDK root directory. For example:

-  ``make all`` rebuilds all components in the SDK
-  ``make linux`` configures and builds the kernel
-  ``make u-boot-spl`` builds u-boot and u-boot-spl

The Android filesystem can be rebuilt, and then flashed to the onboard
eMMC, by following `these
instructions <Overview.html#processor-sdk-android-building-the-sdk>`__.

.. rubric:: What Would You Like to do Next?
   :name: what-would-you-like-to-do-next

Now that you have a solid baseline set up, you can choose what you'd
like to do next based on what you need to do. Here are some of the many
possibilities:

.. csv-table::
   :header: "Link", "Summary"
   :widths: 50, 70

   "`AM57X <http://www.ti.com/tool/PROCESSOR-SDK-AM57X>`__", Download the SDK
   "`Processor SDK Android Software DeveloperâGuide <Overview.html#processor-sdk-android-software-developers-guide>`__", "The SDK's Homepage, a must have link for SDK users."
   "`Processor SDK Android How-To Guides <Processor_SDK_Android_How_To_Guides.html>`__", "The SDK How-To pages. The Hands On with the SDK has some great information for developing your first Android application."
