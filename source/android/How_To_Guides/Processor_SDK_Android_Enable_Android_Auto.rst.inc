**********************************************
How to Enable Android Automotive
**********************************************

Abstract
=========

This guide will walk through the steps necessary to enable Android Automotive on your TI development board.

The Android Automotive OS and Human-Machine Interface provide users with a simplified interface for accessing applications while on the road. The OS is an Android-based infotainment system that allows for a vehicle-optimized, stand-alone Android device to be placed inside the head unit. In place of the phone apps, users install driver-optimized versions of the app directly onto the console. This streamlined experience enables the driver to perform efficient tasks, such as climate control, maps, phone, audio, etc..., in the convenience of their vehicle.

Introduction
============

In this user guide, we will show the key differences between the standard (tablet) configuration and the Android Automotive interface. The look and feel of the applications will differ in the sense that they'll be specially tuned towards an automotive experience. We will also show how to switch at build time between the different target types (tablet and automotive). The AM57xx BeagleBoard-X15 Sitara platform was used since this is the only currently supported TI platform for development in the Android Open Source Project. The same work accomplished on the AM57xx BeagleBoard-X15 can be extended to a new platform; we will use the AM65x EVM module as an example. Finally, we will discuss the future work involved when enabling these features on a more automotive-tuned platform once it's available.

* By default, the TI development board will launch with a tablet user interface:

.. Image:: ../images/Tablet_Home.png

**Figure 1.** Home Screen for Tablet Configuration.

* After creation of the automotive target on the TI development board, the following user interface will be available:

.. Image:: ../images/Auto_Start_Car.png

**Figure 2.** Start Screen for Automotive Configuration, Depicting a Car With PSI Information Near Tires.

.. Image:: ../images/Auto_Car_Launcher.png

**Figure 3.** "Let's Drive" Interface for Automotive Configuration (allowing you to interact with applications by selecting the icon in the middle)

.. Image:: ../images/Auto_Climate_Control.png

**Figure 4.** Climate Control Interface for Automotive Configuration (allowing you to adjust temperature, fan speed and direction, seat warmers, and so forth)

.. Image:: ../images/Auto_Notifications.png

**Figure 5.** Notification Pane for Automotive Configuration (presenting you with up-to-date notifications regarding your vehicle)

Implementation
===============
Prerequities
-------------
1. Check to make sure your setup meets the `hardware and software requirements <https://source.android.com/setup/build/requirements>`__ as given by Android.

2. Environment setup:
	a. **Android Pastry Version**: Pie (based on http://git.ti.com/cgit/cgit.cgi/android/manifest.git/log/?h=pie-core-release)
	b. **Linux Kernel**: ti-android-linux-4.19.y
	c. **Toolchain**: gcc-arm-8.3-2019.03-x86_64-arm-linux-gnueabihf
3. Follow the steps provided in the Processor SDK Android `1.1 Getting Started Guide <http://software-dl.ti.com/processor-sdk-android/esd/docs/latest/android/Overview_Getting_Started_Guide.html>`__ to install the necessary components and `1.3 Building the SDK <http://software-dl.ti.com/processor-sdk-android/esd/docs/latest/android/Overview_Building_the_SDK.html>`__ to prepare for development on the TI microprocessor.
4. `Establish your Build Environment for Android <https://source.android.com/setup/build/initializing>`__.
5. Ensure that your device meets the `Automotive Requirements defined by the Android Compatibility Definition <https://source.android.com/compatibility/android-cdd#2_5_automotive_requirements>`__.

Software Changes
-----------------

.. note:: Please change directory to your Android File System before continuing.

1. Changes inside *device/ti/beagle_x15/AndroidProducts.mk*:

* These changes add a new lunch combo called "beagle_x15_auto-userdebug" and it's path to the relative top-level makefile.

.. code-block:: console

	 PRODUCT_MAKEFILES += \
	-    $(LOCAL_DIR)/beagle_x15.mk \
	+    beagle_x15:$(LOCAL_DIR)/beagle_x15.mk \
	+    beagle_x15_auto:$(LOCAL_DIR)/auto/beagle_x15.mk \

	 COMMON_LUNCH_CHOICES := \
	     beagle_x15-userdebug \
	+    beagle_x15_auto-userdebug \

2. Changes inside *device/ti/beagle_x15/BoardConfig.mk*:

* Conditional is needed to differentiate the content that is included depending on the **TARGET_PRODUCT** (macro set by lunch combo)
* `DEVICE_MANIFEST_FILE <https://source.android.com/devices/architecture/vintf/objects#device-manifest-file>`__ adds the auto-specific manifest file to the build

.. code-block:: console

	BOARD_SEPOLICY_DIRS += \
	    device/ti/beagle_x15/sepolicy
 
	+ifeq ($(TARGET_PRODUCT),beagle_x15_auto)
	+BOARD_SEPOLICY_DIRS += \
	+   packages/services/Car/car_product/sepolicy
	+
	+DEVICE_MANIFEST_FILE += device/ti/beagle_x15/auto/manifest.xml
	+endif
	+

3. Create an *auto* directory inside of *device/ti/beagle_x15*.

.. note:: The following steps will all be completed inside the *device/ti/beagle_x15/auto* directory.

4. Create a top-level makefile for the "beagle_x15_auto-userdebug" lunch combo.

* The top-level makefiles are inherited to include all necessary components (**PRODUCT_PACKAGES**, **PRODUCT_COPY_FILES**, **PRODUCT_PROPERTY_OVERRIDES**, and so forth) to enable desired features.
	* *auto/device.mk* and *car.mk* are crucial to enabling all automotive-specific features.
	* The content inside the *car.mk*, the common makefile for all car builds, can be found `here <https://android.googlesource.com/platform/packages/services/Car/+/refs/heads/pie-release/car_product/build/car.mk>`__.
	* *car.mk* then inherits *car_base.mk*, the base platform for car builds, whose content can be found `here <https://android.googlesource.com/platform/packages/services/Car/+/refs/heads/pie-release/car_product/build/car_base.mk>`__.
	* Inside *car_base.mk*, the `auto-specific PRODUCT_PROPERTY_OVERLAYS <https://android.googlesource.com/platform/packages/services/Car/+/refs/heads/pie-release/car_product/overlay/frameworks/base/core/res/res/values/config.xml>`__ are added to customize the product at build time.

* Insert the following content:

.. code-block:: html


	$(call inherit-product, device/ti/beagle_x15/device.mk)
	$(call inherit-product, device/ti/beagle_x15/auto/device.mk)
	$(call inherit-product, $(SRC_TARGET_DIR)/product/full_base.mk)
	$(call inherit-product, packages/services/Car/car_product/build/car.mk)

	PRODUCT_NAME := beagle_x15_auto
	PRODUCT_DEVICE := beagle_x15
	PRODUCT_BRAND := Android
	PRODUCT_MODEL := AOSP Auto on BeagleBoard X15
	PRODUCT_MANUFACTURER := Texas Instruments Inc

5. Create the *device.mk* to declare the auto-specific files and modules needed for the device.

* The *android.hardware.automotive.vehicle@2.0-service* **PRODUCT_PACKAGE** is the `Android Automotive hardware abstraction layer (HAL)  <https://source.android.com/devices/automotive>`__, which is the interface definition between the car and the vehicle network service.
* The *frameworks/../../../android.hardware.type.automotive.xml* **PRODUCT_COPY_FILE** determines that the Android device implementation is classified as "Automotive".

* Insert the following content:

.. code-block:: html

	PRODUCT_PACKAGES += \
		android.hardware.automotive.vehicle@2.0-service \

	PRODUCT_COPY_FILES += \
		frameworks/native/data/etc/android.hardware.type.automotive.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.type.automotive.xml \
		frameworks/native/data/etc/android.hardware.screen.landscape.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.screen.landscape.xml \

	PRODUCT_PROPERTY_OVERRIDES += \
		android.car.drawer.unlimited=true \
		android.car.hvac.demo=true \
		com.android.car.radio.demo=true \
		com.android.car.radio.demo.dual=true \

6. Create the *manifest.xml* to provide the HAL(s) specific to automotive.

* Beagle_x15 requires the *android.hardware.automotive.vehicle* inclusion to define the product as automotive.

* Insert the following content:

.. code-block:: console

	<manifest version="1.0" type="device">
	    <hal format="hidl">
	        <name>android.hardware.automotive.vehicle</name>
	        <transport>hwbinder</transport>
	        <version>2.0</version>
	        <interface>
	            <name>IVehicle</name>
	            <instance>default</instance>
	        </interface>
	    </hal>
	</manifest>

Deploy Instructions
====================
Build Instructions
-------------------

1. Change directory to your Android File System:

2. To setup your build environment, run the following script:

.. code-block:: console
	
	$ . ./build/envsetup.sh

3. To view the "lunch" menu and select a combo (TARGET_PRODUCT):

.. code-block:: console

	$ lunch

* Select the desired TARGET_PRODUCT (<board>_auto-userdebug)

4. Export the path to your Kernel directory:

.. code-block:: console

	$ export KERNELDIR=<path_to_kernel_directory>

5. Build:

.. code-block:: console

	$ make -j<number_of_cores>

Boot Instructions
------------------

1. Once build is complete, prepare your eMMC binaries and images:

* Make a copy of the prebuilt-images directory to be used as a working directory for flashing.

.. note:: Review the <Android_FS>/device/ti/<board>/fastboot.sh for exact images to copy into flashing directory.

**AM5**

.. code-block:: console

	cd ~/ti-processor-sdk-android-beagle_x15-<version>/board-support/
	cp -r prebuilt-images emmc_files
	cp -v ./aosp-<version>/out/target/product/beagle_x15/boot.img emmc_files
	cp -v ./aosp-<version>/out/target/product/beagle_x15/system.img emmc_files
	cp -v ./aosp-<version>/out/target/product/beagle_x15/userdata.img emmc_files
	cp -v ./aosp-<version>/out/target/product/beagle_x15/recovery.img emmc_files
	cp -v ./aosp-<version>/out/target/product/beagle_x15/vendor.img emmc_files
	cp -v ./aosp-<version>/out/target/product/beagle_x15/boot_fit.img emmc_files
	cp -v ./aosp-<version>/device/ti/beagle_x15/fastboot.sh emmc_files
	cp -v ./aosp-<version>/out/host/linux-x86/bin/{simg2img,mkbootimg,fastboot,adb} emmc_files
	cp -v ./linux-<version>/arch/arm/boot/zImage emmc_files/zImage-beagle_x15.bin
	cp -v ./linux-<version>/arch/arm/boot/dts/am57*.dtb emmc_files
	cp -v ./u-boot-<version>/MLO emmc_files
	cp -v ./u-boot-<version>/u-boot.img emmc_files

**AM6**

.. code-block:: console

	cd ~/ti-processor-sdk-android-am65xx-evm-<version>/board-support/
	cp -r prebuilt-images emmc_files
	cp -v ./aosp-<version>/out/target/product/am65xevm/system.img emmc_files
	cp -v ./aosp-<version>/out/target/product/am65xevm/userdata.img emmc_files
	cp -v ./aosp-<version>/out/target/product/am65xevm/vendor.img emmc_files
	cp -v ./aosp-<version>/out/target/product/am65xevm/boot_fit.img emmc_files
	cp -v ./aosp-<version>/device/ti/am65xevm/fastboot.sh emmc_files
	cp -v ./aosp-<version>/out/host/linux-x86/bin/{simg2img,mkbootimg,fastboot,adb} emmc_files
	cp -v ./aosp-<version>/out/host/linux-x86/lib64/{libc++.so,libcutils.so,liblog.so,libselinux.so,libpcre2.so} emmc_files
	cp -v ./u-boot_build/a53/u-boot.img emmc_files
	cp -v ./u-boot_build/a53/tispl.bin emmc_files
	cp -v ./u-boot_build/r5/tiboot3.bin emmc_files

2. Ensure the device is plugged in with USB Host and Debug UART/Serial Debug
3. Open a terminal debugger to view console output from the device (dmesg: kernel ring buffer, logcat: log of system messages)

.. code-block:: console

	$ sudo picocom -b 115200 /dev/ttyUSB0

4. Enable fastboot on the device through the terminal debugger:

.. code-block:: console

	=> fastboot 0

5. In a different terminal, change directory to the device tarball and run the fastboot.sh script:

.. code-block:: console

	cd ~/ti-processor-sdk-android-<board>-<version>/board-support/emmc_files
	~/ti-processor-sdk-android-<board>-<version>/board-support/emmc_files$ sudo ./fastboot.sh; sudo ./fastboot reboot

Testing
========
Prerequisites/Setup
--------------------

Compatibility Test Suite (CTS)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
* Runs on your desktop and executes a series of test cases on the connected device(s)
* The intent is to reveal incompatibilities or malfunctions, ensure API compatibility and CDD compliance while developing the automotive configuration and additional related software components (`Overview of CTS <https://source.android.com/compatibility/cts>`__)

1. `Desktop machine setup <https://source.android.com/compatibility/cts/setup>`__:

* Ensure the latest versions of both Android Debug Bridge (adb) and Android Asset Packaging Tool (AAPT) are installed and those tools' location(s) are added to the system path of your machine.

.. code-block:: console

	$ sudo apt-get install adb aapt

.. note:: The SDK should already come with adb and aapt so the above command will either update/upgrade them or return the message:

	"aapt is already the newest version <version_number>"

	"adb is already the newest version <version_number>"

* `Download the CTS packages <https://source.android.com/compatibility/cts/downloads.html>`__ matching your devices' Android version and the Application Binary Interfaces (ABIs) your devices support.
	
* Unzip the CTS packages inside of *~/ti-processor-sdk-android-<board>-<version>/board-support/emmc_files*.

.. code-block:: console

	$ cd ~/ti-processor-sdk-android-<board>-<version>/board-support/emmc_files
	$ unzip ~/Downloads/android-cts-<version>.zip .

* You may need to override the `ro.product.first_api_level <https://source.android.com/compatibility/cts/setup#first-api-level>`__ property in order to ensure upgrade requirements are applied.
	* Find the valid override values on `Codenames, Tags, and Build Numbers <https://source.android.com/setup/start/build-numbers>`__.
	* The following would be done inside the relative *device.mk* file:

.. code-block:: console

	PRODUCT_PROPERTY_OVERRIDES += ro.product.first_api_level=<Valid_Override_Value>

Vendor Test Suite (VTS)
^^^^^^^^^^^^^^^^^^^^^^^^
* Used for automated HAL and OS Kernel testing

1. Complete the steps given at `Systems Testing with VTS <https://source.android.com/compatibility/vts/systems>`__

Automotive Testing
-------------------

Compatibility Test Suite (CTS)
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

1. `Running CTS Tests <https://source.android.com/compatibility/cts/run>`__

* While inside the *~/ti-processor-sdk-android-<board>-<version>/board-support/emmc_files* directory, run the following commands:

.. code-block:: console

	$ cd android-cts/tools
	$ sudo ./cts-tradefed

* Ensure that the Device Under Test (DUT) is found when launching cts-tradefed.

The following output should be seen:

.. code-block:: console

	Android Compatibility Test Suite [Version] (5550264)
	Use "help" or "help all" to get more information on running commands.
	[Date] [Time] I/DeviceManager: Detected new device #
	cts-tf >

If the above message isn't seen, inside *~/ti-processor-sdk-android-<board>-<version>/board-support/emmc_files*, run the following command:

.. code-block:: console

	$ sudo ./adb devices

If your device does not show up here, run the following commands inside *~/ti-processor-sdk-android-<board>-<version>/board-support/emmc_files*:

.. code-block:: console

	$ sudo ./adb kill-server
	$ sudo ./adb start-server

* Retry $ sudo ./adb devices.
	* If your device still does not show up, reboot the device and retry the above steps.
* Once the DUT is found, continue:

.. code-block:: console

	cts-tf > run cts --module CtsCarTestCases

* "cts-tf > list modules" will list all modules and "cts-tf > list plans" will list all plans.
* **CtsCarTestCases** will run car-specific test cases.

* To exit CTS, "cts-tf > exit".

2. Test Results

Located in *android-cts/results/<time_stamp>*.

.. code-block:: console

	~/ti-processor-sdk-android-<board>-<version>/board-support/emmc_files$ cd android-cts/results/<time_stamp>

Vendor Test Suite (VTS)
^^^^^^^^^^^^^^^^^^^^^^^^
1. Running VTS Tests

.. code-block:: console

	~$ vts-tradefed
	vts-tf > list plans

We are interested in the *vts-hal-auto*, described as the "VTS automotive vehicle HAL test." The full list of plans can be found `here <https://android.googlesource.com/platform/test/vts/+/master/tools/vts-tradefed/res/config/plans.md>`__

.. code-block:: console

	vts-tf > run vts-hal-auto

2. Test Results

Path should be given on completion of test

.. code-block:: console

	~$ cd <Android_FS>/out/host/linux-x86/vts/android-vts/results/<time_stamp>

Open Source
================
* `Automotive feature enablement on AM57xx BeagleBoard-X15 is merged to Android Open Source Project <https://android.googlesource.com/device/ti/beagle-x15/+/6733fad681437d283daab7ad026d2446a89b38d2>`__.

Extending to a New Platform
============================
The work that was completed on the AM57xxx BeagleBoard-X15 in the Implementation -> Software Changes section can be extended to new platforms. The AM65x EVM is used as an example here. The differences between what was given in Implementation -> Software Changes and what is used for AM65x EVM are as follows:

* Automotive feature enablement on AM65x EVM is merged to Texas Instruments Repository

1. Changes inside *device/ti/am65xevm/AndroidProducts.mk*:

.. code-block:: console

	 PRODUCT_MAKEFILES := \
	+       am65xevm_auto:$(LOCAL_DIR)/auto/am65xevm_auto.mk \
	  
	 COMMON_LUNCH_CHOICES := \
	+       am65xevm_auto-userdebug \

2. Changes inside *device/ti/am65xevm/BoardConfig.mk*:

.. code-block:: console
			  
	+ifeq ($(TARGET_PRODUCT), am65xevm_auto)
	+BOARD_SEPOLICY_DIRS += \
	+       packages/services/Car/car_product/sepolicy
	+
	+DEVICE_MANIFEST_FILE += device/ti/am65xevm/auto/manifest.xml
	+endif

3. Changes inside *device/ti/am65xevm/auto/am65xevm.mk*:

.. code-block:: console

	+$(call inherit-product, device/ti/am65xevm/auto/device.mk)
	+$(call inherit-product, packages/services/Car/car_product/build/car.mk)
	+
	+PRODUCT_NAME := am65xevm_auto
	+PRODUCT_DEVICE := am65xevm
	+PRODUCT_BRAND := TI
	+PRODUCT_MODEL := AOSP Auto on AM65x EVM
	+PRODUCT_MANUFACTURER := Texas Instruments Inc

4. Changes inside *device/ti/am65xevm/auto/device.mk*:

.. code-block:: console
	
	+#Automotive
	+PRODUCT_PACKAGES += \
	+       android.hardware.automotive.vehicle@2.0-service \
	+
	+PRODUCT_COPY_FILES += \
	+       frameworks/native/data/etc/android.hardware.type.automotive.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.type.automotive.xml \
	+       frameworks/native/data/etc/android.hardware.screen.landscape.xml:$(TARGET_COPY_OUT_VENDOR)/etc/permissions/android.hardware.screen.landscape.xml \
	+
	+PRODUCT_PROPERTY_OVERRIDES += \
	+       android.car.drawer.unlimited=true \
	+       android.car.hvac.demo=true \
	+       com.android.car.radio.demo=true \
	+       com.android.car.radio.demo.dual=true \

5. Content inside *device/ti/am65xevm/auto/manifest.xml*:

.. code-block:: console

	+<manifest version="1.0" type="device">
	+    <hal format="hidl">
	+        <name>android.hardware.automotive.vehicle</name>
	+        <transport>hwbinder</transport>
	+        <version>2.0</version>
	+        <interface>
	+            <name>IVehicle</name>
	+            <instance>default</instance>
	+        </interface>
	+    </hal>
	+</manifest>

Known Bugs
===========

.. note:: These are known issues and may be resolved in the future depending on their impacts.

1. Sepolicy output while the device is running

.. code-block:: console

	~/ti-processor-sdk-android-<board>-<version>/board-support/emmc_files$ sudo ./adb shell dmesg | grep denied | audit2allow -p <Android_FS>/out/target/product/beagle_x15/obj/ETC/sepolicy_intermediates/sepolicy

* You may see the following errors:

.. code-block:: console

	#============== carservice_app ==============
	allow carservice_app runtime_event_log_tags_file:file map;

	#============== hal_vehicle_default ==============
	allow hal_vehicle_default node:tcp_socket node_bind;
	allow hal_vehicle_default self:tcp_socket { accept bind create listen };

* These cannot be resolved at this time due to `SEPolicy neverallow <https://source.android.com/security/selinux/customize#neverallow>`__

2. Power manager service is failing

* You may see the following errors:

.. code-block:: console

	E CarPowerManagerNative: Received unknown bootReason = 0
	E PowerTestService: ERROR: Could not read bootReason!!

3. CTS test_result_failures.html output when tested on pie-core-release branch with an AM57xx BeagleBoard-X15 and an AM65x EVM

* test_result_failures.html returned one failed test
	* android.car.cts.CarBluetoothTest#testRequiredBluetoothProfilesExist
* Details
	* java.lang.NullPointerException: Attempt to invoke virtual method 'boolean android.bluetooth.BluetoothAdapter.disable()' on a null object reference

* This is expected since the AM57xx BeagleBoard-X15 and AM65x EVM do not support Bluetooth at this time.

Future Work
============
* Enable Android Auto Human-Machine Interface on new automotive-tuned TI platforms
* Migrate to Android Q Pastry Version
	* Add multiple hardware display support
		* **Interactive:** Individual input mapping, decorative elements and IME (soft keyboard)
		* **Driver:** Main IVI display with all UX restrictions applied
		* **Passenger:** Add support for more types of apps and individual launchers for each screen
	* Multiple users with "headless" system, where a user is not associated with a real user and doesn't have a lock screen
	* Multi-zone Audio
		* A zone is a collection of audio devices and each user device can only be in one zone
		* Within each zone, audio usage determines which device the audio is routed to

FAQ
====
1. What is important about this topic?
	a. This topic allows the entire Android Open Source community to benefit from an additional feature: Android Automotive on all currently supported Texas Instruments ARM32B and ARM64B platforms, including AM57xx BeagleBoard-X15 and AM65x EVM. Android Automotive will also be applicable to all new automotive-tuned TI platforms.
2. Who is the intended end user?
	a. The intended end user(s) include the Automotive Business Unit for Digital Cockpit implementation targeted at infotainment customers who need a graphically rich user interface with an Android extensive app store on a Texas Instruments digital application processor.
3. When will this document be used?
	a. This document is intended to implement Android Automotive on any application processor that is designed to showcase and use the functionality of Android.

References
===========
1. Jacinto 6 EVM on d-oreo-mr1-release: `Changes for defining auto platform <http://git.omapzoom.org/?p=device/ti/jacinto6evm.git;a=commit;h=d0e55148e19bb6ba3401b6ad913154697cb65af0>`__
2. `Google Cuttlefish Auto (cf_x86_64_auto-userdebug) <https://android.googlesource.com/device/google/cuttlefish/+/refs/heads/pie-release/vsoc_x86_64/auto/device.mk>`__
3. `AOSP Generic Car (aosp_car_x86_64-userdebug) <https://android.googlesource.com/device/generic/car/+/refs/heads/pie-release>`__
