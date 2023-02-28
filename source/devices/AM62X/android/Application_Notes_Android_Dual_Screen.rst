===========================
Android Dual Screen Support
===========================

This applications Notes contains step to enable Dual Display with Android in mirror mode or extented mode.

.. note::

	By default android set display in mirroring mode.

.. note::

	The following panel is currently supported with the AM625 SK EVM revision E3 board:

	**Microtips Technology USA (13-101HIEB0HF0-S) 10.1"  WUXGA (1920x1200) TFT LCD panel**


How to enable Microtips LVDS Panel on AM62 SK EVM
=================================================

**Steps to enable OLDI Panel DT overlay:**

#. Follow the `How to enable DT overlays in Android
   <Application_Notes_dtbo_support.html>`__ guide

**Steps to enable Touch on the Microtips Panel on AM625 SK EVM:**

**Note**: The following steps are only applicable on AM625 SK EVM revision E3 board.

#. Power off the LVDS board by disconnecting the 12V barrel jack (do not power off the SK EVM)
#. Run the following commands from the Linux prompt:

	.. code-block:: bash

		console:/ $ su
		console:/ $ rmmod ili210x
		console:/ $ i2cset 0 0x3f 0x0e0109 w
		console:/ $ i2cset 0 0x3f 0x6873504704 w

#. Power on the LVDS board
#. Run the following command:

	.. code-block:: bash

		console:/ $ insmod /vendor/lib/modules/ili210x.ko

After re-initializing the module, the touch IC should now be registered as an input and touch should be functional.

.. note::

	This step need to de done each time you reboot board.

How to enable Extended Display in Android
==========================================

**Step to setup an android build environnement:**

#. Follow the `How to build Android <../../../android/Overview_Building_the_SDK.html#android-file-system>`_ Guide.

**Step to enable Extended Display:**

#. Edit device.mk file to add this:

	.. code-block:: makefile

		# Display settings (windowing, system decorations, IME ...)
		PRODUCT_COPY_FILES += \
			device/ti/am62x/display_settings.xml:$(TARGET_COPY_OUT_VENDOR)/etc/display_settings.xml

		# Enable activities on secondary displays
		PRODUCT_COPY_FILES += \
			frameworks/native/data/etc/android.software.activities_on_secondary_displays.xml:system/etc/permissions/android.software.activities_on_secondary_displays.xml

#. Rebuild Android:

	Relaunch command from `How to build SDK <../../../android/Overview_Building_the_SDK.html#id3>`_ guide.

#. Follow this `How to flash eMMC <../../../android/Overview_Flashing.html#emmc-flashing>`_ guide to flash Android image.


