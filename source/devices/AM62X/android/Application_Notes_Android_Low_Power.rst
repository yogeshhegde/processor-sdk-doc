===========================
Android Low Power Support
===========================

This application note contains steps to enable low power support in BSP.

AM62x has limited support for Low Power Mode (LPM) in current SDK release.
Since not all peripheral drivers are updated to work across suspend/resume cycle,
a cut-down version of DT file is provided with limited peripherals and cores enabled
to demonstrate Suspend to RAM (S2R) capability.

.. note::
	Deep sleep is currently supported only on AM62x GP Devices and support for HS-FS, HS-SE
	is still under way.

Supported low power mode:

#. **Suspend to RAM (S2R):** All power domains are off except for wake-up domain that has wake-up co-processor (DM R5) running. DDR is in self refresh.

Switching to LPM demo dts
-------------------------

LPM demo is only possible with cut-down dtb: ``k3-am625-sk-lpmdemo.dtb``.

**Steps to switch to LPM DT:**

#. Setup an `Android kernel build system <../../../android/Overview_Building_the_SDK.html#kernel>`_  and `Android build system <../../../android/Overview_Building_the_SDK.html#android-file-system>`_

#. Edit android build system

	- Update ``device/ti/am62x`` and apply this change:

	.. code-block:: bash

		diff --git a/device.mk b/device.mk
		index 686e3dbd99b2..d638ecd99390 100644
		--- a/device.mk
		+++ b/device.mk
		@@ -266,7 +266,6 @@ PRODUCT_COPY_FILES += \

		PRODUCT_COPY_FILES += \
				device/ti/am62x/init.am62x.rc:$(TARGET_COPY_OUT_VENDOR)/etc/init/hw/init.am62x.rc \
		- 		device/ti/am62x/init.am62x.zygote_wakelock.rc:$(TARGET_COPY_OUT_VENDOR)/etc/init/init.am62x.zygote_wakelock.rc \
				device/ti/am62x/init.am62x.usb.rc:$(TARGET_COPY_OUT_VENDOR)/etc/init/init.am62x.usb.rc \
				device/ti/am62x/ueventd.am62x.rc:$(TARGET_COPY_OUT_VENDOR)/ueventd.rc


#. At Android prompt, using RTC as wake-up source, test S2R using following command::

		console:/ $ su
		console:/ # rtcwake -s 10 -m mem
		wakeup using "mem" from /dev/rtc0 at Mon Feb 27 20:47:02 2023
		[  171.729145] PM: suspend entry (deep)
		[  171.737476] Filesystems sync: 0.004 seconds
		[  171.742214] Freezing user space processes ... (elapsed 0.004 seconds) done.
		[  171.754087] OOM killer disabled.
		[  171.757326] Freezing remaining freezable tasks ... (elapsed 0.003 seconds) done.
		[  171.784455] android_work: sent uevent USB_STATE=DISCONNECTED
		[  171.961454] Disabling non-boot CPUs ...
		[  171.970763] psci: CPU1 killed (polled 4 ms)
		[  171.993689] psci: CPU2 killed (polled 0 ms)
		[  172.014894] psci: CPU3 killed (polled 4 ms)
		[I/TC: Secondary CPU 1 initializing
		I/TC: Secondary CPU 1 switching to normal world boot
		I/TC: Secondary CPU 2 initializing
		I/TC: Secondary CPU 2 switching to normal world boot
		I/T[  200.035482] am65-cpsw-nuss 8000000.ethernet: set new flow-id-base 19
		C: Secondary CPU 3 initializing
		I/TC: Secondary CPU 3 switching to normal world boot
		[  200.067533] am65-cpsw-nuss 8000000.ethernet eth0: PHY [8000f00.mdio:00] driver [TI DP83867] (irq=POLL)
		[  200.076971] am65-cpsw-nuss 8000000.ethernet eth0: configuring for phy/rgmii-rxid link mode
		[  200.103015] am65-cpsw-nuss 8000000.ethernet eth1: PHY [8000f00.mdio:01] driver [TI DP83867] (irq=POLL)
		[  200.112422] am65-cpsw-nuss 8000000.ethernet eth1: configuring for phy/rgmii-rxid link mode
		[  200.454835] OOM killer enabled.
		[  200.457993] Restarting tasks ...
		[  200.505711] android_work: sent uevent USB_STATE=CONNECTED
		[  200.527147] dwc3 31000000.usb: request 0000000000000000 was not queued to ep0out
		[  200.687139] done.
		[  200.689205] Resume caused by IRQ 15, 2b1f0000.rtc
		[  200.701243] read descriptors
		[  200.705646] read strings
		[  200.711041] android_work: sent uevent USB_STATE=DISCONNECTED
		[  200.734919] PM: suspend exit
		console:/ # [  201.555258] android_work: sent uevent USB_STATE=CONNECTED
		[  201.595880] android_work: sent uevent USB_STATE=CONFIGURED
		console:/ $

This puts system to sleep for 10s and then wakes it up via RTC interrupt.

More information on `Linux how to low power <https://software-dl.ti.com/processor-sdk-linux/esd/AM62X/latest/exports/docs/linux/How_to_Guides/Target/How_to_suspend_to_ram_on_AM62x.html>`_ guide.
