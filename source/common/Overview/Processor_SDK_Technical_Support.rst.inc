.. include:: /replacevars.rst.inc

************************************
Processor SDK Technical Support
************************************

Technical support is a broad term. Our desire is to provide a solid
product, good documentation, and useful training that defines a clear
path for developing a product based on the Linux/RTOS/Android SDKs.
However, we know we'll never cover everything that can be done, and
occasionally we even make mistakes <gasp>. So, when you can't seem to
find what you need, there's a good place to search through previously
answered questions and ask a new one - The E2E Support Forums.

There is an active community of TIers and other customers like you
already using a TI Processor, on these forums. You may find your
question has already been answered with a quick Search of the Forums. If
not, a quick post will likely provide you the answers you need.

-  `E2E Processor Support
   <https://e2e.ti.com/support/processors/>`__

Open Source Software Support Disclaimer
=======================================

.. ifconfig:: CONFIG_sdk in ('PLSDK')

    Processor SDK Linux integrates various free and open source software (FOSS) to demonstrate the hardware capabilities of Sitara devices. The FOSS offers many advantages to the customers such as flexibility, interoperability, robustness, reduced development time and support from the respective FOSS community.

.. ifconfig:: CONFIG_sdk in ('PSDKLA')

    Processor SDK Linux Automotive integrates various free and open source software (FOSS) to demonstrate the hardware capabilities of Jacinto devices. The FOSS offers many advantages to the customers such as flexibility, interoperability, robustness, reduced development time and support from the respective FOSS community.


TI uses Yocto Project to integrate various software components and to build |__SDK_FULL_NAME__|. Yocto Project has two releases per year in April and October. TI’s Long-term Support (LTS) build for next year is based on current year’s October release of the Yocto Project. During a given year, TI’s LTS version migration only happens once per year and it occurs towards the end of the second quarter. The LTS migration usually signifies newer version of Kernel, U-boot, Toolchain, Yocto Project and etc. For more information on the current release, please refer to the Release Notes in the `Release Specific section  <Release_Specific.html>`__. Therefore, the various open source components included in the |__SDK_FULL_NAME__| are only updated once per year.

While TI integrates the FOSS in |__SDK_FULL_NAME__|, TI does not own, maintain and support the entire FOSS. If users have educational queries, feature enhancement requests or discover a bug on any components, TI encourages the users to reach out to the respective FOSS community for any additional support. Below are helpful resources to seek support on a few of the individual FOSS components. Please keep in mind that we are only showing a few of the components below but the same concept applies to all of the FOSS integrated in the |__SDK_FULL_NAME__|. 

**Gstreamer Framework**

- https://gstreamer.freedesktop.org/documentation/
- Gstreamer application tutorials: https://gstreamer.freedesktop.org/documentation/tutorials/

**QT Framework**

- https://www.qt.io
- https://doc.qt.io
- https://forum.qt.io

**Wayland Weston**

- https://wayland.freedesktop.org

**Robot Operating System (ROS)**

- http://www.ROS.org
- For meta-ros (embedded version of ROS, that runs on our ARM): https://github.com/bmwcarit/meta-ros

**V4L2**

For programming external video devices, a V4L2 sub-device driver is needed to be used in conjunction with the V4L2 driver. It also uses some of the helper kernel libraries videobuf2 (VB2) for common buffer operations, queue management and memory management.

- https://linuxtv.org/downloads/v4l-dvb-apis/
- https://linuxtv.org/downloads/v4l-dvb-apis-new/uapi/v4l/v4l2.html
- https://linuxtv.org/downloads/v4l-dvb-apis/kapi/v4l2-videobuf2.html
- https://linuxtv.org/downloads/v4l-dvb-apis-new/kapi/v4l2-subdev.html

**Graphics**

- Direct Rendering Infrastructure (DRI): https://dri.freedesktop.org/wiki/Documentation/
- Direct Rendering Manager (DRM): http://dri.freedesktop.org/wiki/DRM/
- Kernel Mode Setting (KMS): https://www.kernel.org/doc/html/v4.14/gpu/drm-kms.html
- Graphics Execution Manager (GEM): https://www.kernel.org/doc/html/v4.14/gpu/drm-mm.html#the-graphics-execution-manager-gem

Example applications:

- https://github.com/tomba/kmsxx
- https://git.ti.com/glsdk/example-applications/trees/master/drm-tests
- http://git.ti.com/sitara-linux/dual-camera-demo/trees/master
- The modetest tool is available inside git://anongit.freedesktop.org/git/mesa/drm

**OpenCV**

- OpenCV: https://opencv.org/
- Documentation, tutorials and examples of how to use OpenCV 3.1: https://docs.opencv.org/3.1.0/#gsc.tab=0
- OpenCL offload through OpenCV 3.1 transparent API: https://opencv.org/platforms/opencl.html

**Hypervisor**

- Jailhouse: https://github.com/siemens/jailhouse
- IVshmem based UIO driver: https://github.com/henning-schild-work/ivshmem-guest-code

How do I integrate a different version of open source software than what is packaged in |__SDK_FULL_NAME__|?
=============================================================================================================

If users have a need to move to a different component version (older or newer) because of an existing bug, feature limitations or other reasons, TI will not support the version migration. As a reference, TI provides the list of a few recipes that were updated while integrating the components to the |__SDK_FULL_NAME__|.

::


		├── QT5:  
		│    ├──Baseline:
		│    │     └──meta-qt5:recipes-qt/qt5/: recipes and patches from community
		│    │      
		│    └──Arago (TI) updates:
		│         ├──meta-arago:
		│    	  │	├──meta-arago-distro/recipes-qt/qt5: recipes update and additional patches
		│         │	├──meta-arago-extra/recipes-qt/examples:local qt5 examples
		│         │	├──meta-arago-distro/recipes-qt/examples:local qt5 examples recipe update and patches
		│         │	├──meta-arago-distro/recipes-core/packagegroups: no changes are expected
		│         │	│	├──packagegroup-arago-qte.bb
		│         │	│	├──packagegroup-arago-tisdk-qte.bb
		│    	  │	│	└──packagegroup-arago-tisdk-qte-sdk-host.bb
		│    	  │	├──meta-arago-extras\recipes-core\packagegroups: no changes are expected
		│    	  │	│	└──packagegroup-arago-qte-toolchain-target.bb
		│    	  │	│								    
		│         │	├──meta-arago-distro/conf/layer.conf: No changes needed for QT configurations
		│         │	└──meta-arago-distro/conf/distro/arago.conf
		│         └──meta-processor-sdk:
		│         		└──recipes-qt/qt5: additional recipe updates and patches

::


		├──Wayland/Weston:
		│    ├──Baseline:
		│    │     └──oe-core/meta/recipes-graphics/wayland: recipes and patches from community
		│    │      
		│    └──Arago (TI) updates:
		│         ├──meta-arago:
		│         │	├──meta-arago-distro/recipes-graphics/wayland: recipes update and additional patches
		│         │	├──meta-arago-extras/recipes-graphics/wayland/wayland-protocols
		│         │	├──meta-arago-distro/recipes-graphics/wayland/wayland-ivi-extension: wayland-ivi recipes
		│         │	├──meta-arago-distro/recipes-graphics/wayland/weston-conf: weston configuration
		│    	  │	└──meta-arago-distro/conf/distro/arago.conf: DISTRO_FEATURES
		
		Note: There are many modules that depend on wayland. For example: chromium-wayland, qt5/qtwayland, gstreamer1.0-plugins-bad(waylandsink), glmark2 and gtk+3

::


		├──SGX (Not recommended to modify):
		│    ├──Baseline:
		│    │      
		│    ├──meta-ti:
		│    │	├──recipes-graphics/libgles/ti-sgx-ddk-um_<version>  
		│    │	└──recipes-bsp/powervr-drivers/ti-sgx-ddk-km_<version>
		│    │
		│    ├──meta-arago:
		│    │	├──meta-arago-extras/recipes-graphics/img-pvr-sdk
		│    │	├──meta-arago-distro/recipes-tisdk/ti-tisdk-makefile/ti-tisdk-makefile/Makefile_ti-sgx-ddk-km
		│    │	└──meta-arago-distro/conf/distro/include/arago-prefs.inc: define virtual/egl, virtual/libgles1 and virtual/libgles2
		│    │
		│    │ Note: There are many modules that depend on sgx, but that does not affect sgx update.      
		│    │	      
		│    └──Arago (TI) updates: 
		│    	└──meta-processor-sdk:
		│   		└──recipes-graphics/libgles/ti-sgx-ddk-um_version: for non-sgx build only

::


			├──Gstreamer:
			│    ├──Baseline:
			│    │      
			│    ├──meta-openembedded:
			│    │	└──meta-multimedia/recipes-multimedia/gstreamer-0.10: recipes and patches from community 
			│    │     
			│    │
			│    ├──oe-core:
			│    │	└──meta/recipes-multimedia/gstreamer: recipes and patches from community
			│    │		├──gstreamer1.0-plugins-base
			│    │		├──gstreamer1.0-plugins-bad
			│    │		├──gstreamer1.0-plugins-good
			│    │		├──gstreamer1.0-plugins-ugly
			│    │		└──gstreamer1.0-libav	   
			│    │	      
			│    └──Arago (TI) updates: 
			│    	└──meta-arago:
			│		├──meta-arago-extras/recipes-multimedia/gst-plugins-ti: TI-specific recipes for TI plugins
			│		├──meta-arago-extras/recipes-multimedia/gstreamer/gstreamer1.0-plugins-bad: recipes update and additional patches
			│		├──meta-arago-distro/conf/distro/arago.conf: configuration
			│		└──meta-arago-distro/recipes-core/packagegroups/packagegroup-arago-tisdk-multimedia-sdk-target.bb: package


If users wish to learn more about Yocto project or Arago build, please refer to the below video link and the documentation on `Building Processor SDK Linux through Yocto <Overview_Building_the_SDK.html>`__.
    
- https://training.ti.com/customizing-yocto-for-production-introduction

