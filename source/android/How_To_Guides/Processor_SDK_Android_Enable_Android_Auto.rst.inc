**********************************************
How to Enable Android Automotive
**********************************************
Introduction
============

The Android Automotive OS and HMI provide users with a simplified interface for accessing applications while on the road. The OS is an Android-based infotainment system that allows for a vehicle-optimized, stand-alone Android device to be placed inside the head unit. In place of the phone apps, users install driver-optimized versions of the app directly onto the console. This streamlined experience enables the driver to perform efficient tasks, such as climate control, maps, phone, audio, etc..., in the convenience of their vehicle.

This guide will walk through the steps necessary to enable Android Automotive on your TI development board (AM57x BeagleBoard-X15).

By default, the beagle_x15 lunch combo will launch with a tablet UI:

.. Image:: ../images/Tablet_Home.png

After creation of the beagle_x15_auto lunch combo, the automotive UI will launch:

.. Image:: ../images/Auto_Start_Car.png
.. Image:: ../images/Auto_Car_Launcher.png
.. Image:: ../images/Auto_Climate_Control.png
.. Image:: ../images/Auto_Notifications.png

Getting Started
===============

1. Check to make sure your setup meets the `hardware and software requirements <https://source.android.com/setup/build/requirements>`__ as given by Android

2. Follow the steps provided in the Processor SDK Android `1.1 Getting Started Guide <http://software-dl.ti.com/processor-sdk-android/esd/docs/latest/android/Overview_Getting_Started_Guide.html>`__ to install necessary components and `1.3 Building the SDK <http://software-dl.ti.com/processor-sdk-android/esd/docs/latest/android/Overview_Building_the_SDK.html>`__ to prepare for development on the TI microprocessor
3. `Establish your Build Environment for Android <https://source.android.com/setup/build/initializing>`__
4. Ensure that your device meets the `Automotive Requirements defined by the Android Compatibility Definition <https://source.android.com/compatibility/android-cdd#2_5_automotive_requirements>`__

Modification of Source Files
=============================

.. note:: Please change directory to your Android Filesystem before continuing

1. Changes inside *device/ti/beagle_x15/AndroidProducts.mk*

.. code-block:: console

	 PRODUCT_MAKEFILES += \
	-    $(LOCAL_DIR)/beagle_x15.mk \
	+    beagle_x15:$(LOCAL_DIR)/beagle_x15.mk \
	+    beagle_x15_auto:$(LOCAL_DIR)/auto/beagle_x15.mk \

	 COMMON_LUNCH_CHOICES := \
	     beagle_x15-userdebug \
	+    beagle_x15_auto-userdebug \

* These changes add a new lunch combo called "beagle_x15_auto-userdebug" and it's path to the relative top-level makefile

2. Changes inside *device/ti/beagle_x15/BoardConfig.mk*

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

* Conditional is needed to differentiate the content that is included depending on the **TARGET_PRODUCT** (macro set by lunch combo)
* `DEVICE_MANIFEST_FILE <https://source.android.com/devices/architecture/vintf/objects#device-manifest-file>`__ adds the auto-specific manifest file to the build

3. Create an *auto* directory inside of *device/ti/beagle_x15*

.. note:: The following steps will all be completed inside the *device/ti/beagle_x15/auto* directory

4. Create a top-level makefile for the beagle_x15_auto-userdebug lunch combo and insert the following content

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

* The top-level makefiles are inherited above to include all necessary components (**PRODUCT_PACKAGES**, **PRODUCT_COPY_FILES**, **PRODUCT_PROPERTY_OVERRIDES**, etc...) to enable desired features
	* *auto/device.mk* and *car.mk* are crucial to enabling all automotive-specific features
	* The content inside the *car.mk*, the common makefile for all car builds, can be found `here <https://android.googlesource.com/platform/packages/services/Car/+/refs/heads/pie-release/car_product/build/car.mk>`__
	* *car.mk* then inherits *car_base.mk*, the base platform for car builds, whose content can be found `here <https://android.googlesource.com/platform/packages/services/Car/+/refs/heads/pie-release/car_product/build/car_base.mk>`__
	* Inside *car_base.mk*, the `auto-specific PRODUCT_PROPERTY_OVERLAYS <https://android.googlesource.com/platform/packages/services/Car/+/refs/heads/pie-release/car_product/overlay/frameworks/base/core/res/res/values/config.xml>`__ are added to customize the product at build time

5. Create the *device.mk* to declare the auto-specific files and modules needed for the device and insert the following content

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

* The *android.hardware.automotive.vehicle@2.0-service* **PRODUCT_PACKAGE** is the `Android Automotive hardware abstraction layer (HAL)  <https://source.android.com/devices/automotive>`__, which is the interface definition between the car and the vehicle network service
* The *frameworks/../../../android.hardware.type.automotive.xml* **PRODUCT_COPY_FILE** determines that the Android device implementation is classified as "Automotive"

6. Create the *manifest.xml* to provide the HAL(s) specific to automotive and insert the following content

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

* Beagle_x15 requires the *android.hardware.automotive.vehicle* inclusion to define the product as automotive

Testing
========
Compatibility Test Suite (CTS)
------------------------------
* Runs on your desktop and executes a series of test cases on the connected device(s)
* The intent is to reveal incompatibilities or malfunctions while developing automotive configuration and related additional software components (`Overview of CTS <https://source.android.com/compatibility/cts>`__)

1. `Desktop machine setup <https://source.android.com/compatibility/cts/setup>`__

* Ensure the latest versions of both Android Debug Bridge (adb) and Android Asset Packaging Tool (AAPT) are installed and those tools' location(s) are added to the system path of your machine

.. code-block:: console

	$ sudo apt-get install adb aapt

.. note:: The SDK should already come with adb and aapt so the above command will either update/upgrade them or return the message:

	"aapt is already the newest version (version_number)"

	"adb is already the newest version (version_number)"

* `Download the CTS packages <https://source.android.com/compatibility/cts/downloads.html>`__ matching your devices' Android version and the Application Binary Interfaces (ABIs) your devices support
* Unzip the CTS packages inside of *<SDK_install_dir>/bin*

.. code-block:: console

	$ cd <SDK_install_dir>/bin
	$ unzip ~/Downloads/android-cts-<version>.zip

* You may need to override the `ro.product.first_api_level <https://source.android.com/compatibility/cts/setup#first-api-level>`__ property in order to ensure upgrade requirements are applied
	* Find the valid override values on `Codenames, Tags, and Build Numbers <https://source.android.com/setup/start/build-numbers>`__
	* This would be done inside the relative *device.mk* file

.. code-block:: console

	PRODUCT_PROPERTY_OVERRIDES += ro.product.first_api_level=<Valid_Override_Value>

2. `Running CTS Tests <https://source.android.com/compatibility/cts/run>`__

* While inside the *<SDK_install_dir>/bin* directory, run the following commands

.. code-block:: console

	$ cd android-cts/tools
	$ sudo ./cts-tradefed

* Ensure that the Device Under Test (DUT) is found when launching cts-tradefed

The following output should be seen

.. code-block:: console

	Android Compatibility Test Suite [Version] (5550264)
	Use "help" or "help all" to get more information on running commands.
	[Date] [Time] I/DeviceManager: Detected new device #
	cts-tf >

If the above message isn't seen, inside *<SDK_install_dir>/bin*, run the following command

.. code-block:: console

	$ sudo ./adb devices

If your device doesn't show up here, run the following commands inside *<SDK_install_dir>/bin*

.. code-block:: console

	$ sudo ./adb kill-server
	$ sudo ./adb start-server

* Retry $ sudo ./adb devices
	* If your devices still doesn't show up, reboot the device and retry the above steps
* Once the DUT is found, continue

.. code-block:: console

	cts-tf > run cts --module CtsCarTestCases

* **cts-tf > list modules** will list all modules and **cts-tf >  list plans** will list all plans
* **CtsCarTestCases** will run car-specific test cases

* To exit CTS, **cts-tf > exit**

3. Test Results

Located in *android-cts/results/<time_stamp>*

.. code-block:: console

	<SDK_install_dir>/bin/$ cd android-cts/results/<time_stamp>

Vendor Test Suite (VTS)
------------------------
* Used for automated HAL and OS Kernel testing

1. `Systems Testing with VTS <https://source.android.com/compatibility/vts/systems>`__
2. Running VTS Tests

.. code-block:: console

	~$ vts-tradefed
	vts-tf > list plans

We are interested in the *vts-hal-auto*, described as the "VTS automotive vehicle HAL test." The full list of plans can be found `here <https://android.googlesource.com/platform/test/vts/+/master/tools/vts-tradefed/res/config/plans.md>`__

.. code-block:: console

	vts-tf > run vts --plan vts-hal-auto

3. Test Results

Path should be given on completion of test

.. code-block:: console

	~$ cd <Android_FS>/out/host/linux-x86/vts/android-vts/results/<time_stamp>

Known Bugs
===========

.. note:: These are known issues and may be resolved in the future depending on their impacts

1. Sepolicy output while the device is running

.. code-block:: console

	~/<SDK_install_dir>/bin$ sudo ./adb shell dmesg | grep denied | audit2allow -p <Android_FS>/out/target/product/beagle_x15/obj/ETC/sepolicy_intermediates/sepolicy

May see the following

.. code-block:: console

	#============== carservice_app ==============
	allow carservice_app runtime_event_log_tags_file:file map;

	#============== hal_vehicle_default ==============
	allow hal_vehicle_default node:tcp_socket node_bind;
	allow hal_vehicle_default self:tcp_socket { accept bind create listen };

These cannot be resolved at this time due to `SEPolicy neverallow <https://source.android.com/security/selinux/customize#neverallow>`__

2. Power manager service is failing

You may see the following errors

.. code-block:: console

	E CarPowerManagerNative: Received unknown bootReason = 0
	E PowerTestService: ERROR: Could not read bootReason!!

3. CTS test_result_failures.html output when tested on pie-core-release branch with an AM57x BeagleBoard-X15

* test_result_failures.html returned one failed test
	* android.car.cts.CarBluetoothTest#testRequiredBluetoothProfilesExist
* Details
	* java.lang.NullPointerException: Attempt to invoke virtual method 'boolean android.bluetooth.BluetoothAdapter.disable()' on a null object reference

This is expected since the AM57x BeagleBoard-X15 doesn't support Bluetooth at this time

Upstream Status
================
* `Patch for AM57x BeagleBoard-X15 is ready to be merged to AOSP <https://android-review.googlesource.com/c/device/ti/beagle-x15/+/985026>`__

Future Work
============
* Enable Android Automotive on TI 64 bit platforms, including AM6 and J7
* Migrate to Android Q
	* Add support for 3 or more hardware displays
		* **Interactive:** Individual input mapping, decorative elements and IME (soft keyboard)
		* **Driver:** Main IVI display with all UX restrictions applied
		* **Passenger:** Add support for more types of apps and individual launchers for each screen
	* Multiple users with "headless" system, where a user is not associated with a real user and doesn't have a lock screen
	* Multi-zone Audio
		* A zone is a collection of audio devices and each user device can only be in one zone
		* Within each zone, audio usage determines which device the audio is routed to
	* HwAudioSourcePlayer HAL, which connects the audio source device direcly to an Android mixer
		* Broadcast radio can take advantage of this player and operate as a regular Android media application
		* Add support for multiple applications communicating with a single tuner and a single application communicating with multiple tuners
		* Integrate a "Lazy HAL" that is started asynchronously or on demand. Introduced to solve hardware initialization issues. (Only for Broadcast radio HAL)

FAQ
====
1. What is important about this topic?
	a. This topic allows the entire Android Open Source community to benefit from an additional feature: Android Automotive on all currently supported Texas Instruments ARM32B and ARM64B platforms, including AM57x X15, AM6 and J721E.
2. Who is the intended end user?
	a. The intended end user(s) include the Automotive Business Unit for Digital Cockpit implementation targeted at infotainment customers who need a graphically rich user interface with an Android extensive app store on a Texas Instruments digital application processor.
3. When will this document be used?
	a. The reader will use this document whenever they intend to implement Android Automotive on any application processor which is designed to showcase and use the functionality of Android.
4. Why is this implementation on a Sitara device?
	a. This is the only available device at the moment but in the future, this work will be extended to J721E Auto.

References
===========
1. `Jacinto 6 EVM on d-oreo-mr1-release <http://git.omapzoom.org/?p=device%2Fti%2Fjacinto6evm.git&a=search&h=refs%2Fheads%2Fd-oreo-mr1-release&st=commit&s=auto>`__
	a. `Changes for defining auto platform <http://git.omapzoom.org/?p=device/ti/jacinto6evm.git;a=commit;h=d0e55148e19bb6ba3401b6ad913154697cb65af0>`__
	b. `Initial changes for automotive configuration <http://git.omapzoom.org/?p=device/ti/jacinto6evm.git;a=commit;h=1acce155fa3d1c5925e474ecc66ba28e05f368a2>`__
	c. `Initial changes for O MR1 <http://git.omapzoom.org/?p=device/ti/jacinto6evm.git;a=commit;h=bb52b0b3590c7f169182400bf6fc436278a07bce>`__
2. `Google Cuttlefish Auto (cf_x86_64_auto-userdebug) <https://android.googlesource.com/device/google/cuttlefish/+/refs/heads/pie-release/vsoc_x86_64/auto/device.mk>`__
3. `AOSP Generic Car (aosp_car_x86_64-userdebug) <https://android.googlesource.com/device/generic/car/+/refs/heads/pie-release>`__
