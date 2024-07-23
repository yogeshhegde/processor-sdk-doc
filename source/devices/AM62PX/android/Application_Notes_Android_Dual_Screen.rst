===========================
Android Dual Screen Support
===========================

This application note contains steps to enable dual screen with Android in mirror mode or extended mode.


The following panel is currently supported with the AM62Px SK EVM board:

- **Microtips Technology USA (13-101HIEB0HF0-S) 10.1"  WUXGA (1920x1200) TFT LCD panel**

.. note::

   By default Android configures the displays in mirror mode.


How to enable Microtips LVDS panel on AM62Px SK EVM
===================================================

To enable OLDI Panel DT overlay, follow the :ref:`android-dtbo` guide

How to enable Extended Display in Android
==========================================

**Step to setup an android build environment:**

#. Follow the :ref:`android-download-aosp` download guide.

**Step to enable Extended Display:**

#. Edit :file:`device.mk` file to add this:

   .. code-block:: makefile

      # Display settings (windowing, system decorations, IME ...)
      PRODUCT_COPY_FILES += \
         device/ti/am62x/display_settings.xml:$(TARGET_COPY_OUT_VENDOR)/etc/display_settings.xml

      # Enable activities on secondary displays
      PRODUCT_COPY_FILES += \
         frameworks/native/data/etc/android.software.activities_on_secondary_displays.xml:system/etc/permissions/android.software.activities_on_secondary_displays.xml

#. Rebuild Android:
   Relaunch command from :ref:`android-build-aosp` build guide.

#. Follow :ref:`android-flashing` guide to flash Android images.
