===========================
Android Dual Screen Support
===========================

This application note contains steps to enable dual screen with Android in mirror mode or extended mode.

.. note::

	By default Android configures the displays in mirror mode.

.. note::

	The following panel is currently supported with the AM62Px SK EVM board.

	**Microtips Technology USA (13-101HIEB0HF0-S) 10.1"  WUXGA (1920x1200) TFT LCD panel**


How to enable Microtips LVDS panel on AM62Px SK EVM
===================================================

To enable OLDI Panel DT overlay, follow the `How to enable DT overlays in Android <Application_Notes_dtbo_support.html>`__ guide

How to enable Extended Display in Android
==========================================

**Step to setup an android build environment:**

#. Follow the `How to build Android <../../../android/Overview_Building_the_SDK.html#android-file-system>`_ Guide.

**Step to enable Extended Display:**

#. Edit ``device.mk`` file to add this:

	.. code-block:: makefile

		# Display settings (windowing, system decorations, IME ...)
		PRODUCT_COPY_FILES += \
			device/ti/am62x/display_settings.xml:$(TARGET_COPY_OUT_VENDOR)/etc/display_settings.xml

		# Enable activities on secondary displays
		PRODUCT_COPY_FILES += \
			frameworks/native/data/etc/android.software.activities_on_secondary_displays.xml:system/etc/permissions/android.software.activities_on_secondary_displays.xml

#. Rebuild Android:

	Relaunch command from `How to build SDK <../../../android/Overview_Building_the_SDK.html#id3>`_ guide.

#. Follow this `How to flash eMMC <../../../android/Overview_Flashing.html#emmc-flashing>`_ guide to flash Android images.
