===========================
Android Low Power Support
===========================

This application note contains steps to enable low power support in BSP.

Supported low power mode:

#. **Suspend to RAM (S2R):** All power domains are off except for wake-up domain that has wake-up co-processor (DM R5) running. DDR is in self refresh.

Enable Suspend/Resume support
-----------------------------

#. Edit android build system

	- Update ``device/ti/am62x`` and apply this change:

	.. code-block:: diff

		diff --git a/device-common.mk b/device-common.mk
		index b111bbc332e5..22c75bfadf31 100644
		--- a/device-common.mk
		+++ b/device-common.mk
		@@ -238,7 +238,6 @@ PRODUCT_COPY_FILES += \
		
		PRODUCT_COPY_FILES += \
				device/ti/am62x/init.am62x.rc:$(TARGET_COPY_OUT_VENDOR)/etc/init/hw/init.$(PRODUCT_PLATFORM).rc \
		-       	device/ti/am62x/init.am62x.zygote_wakelock.rc:$(TARGET_COPY_OUT_VENDOR)/etc/init/init.$(PRODUCT_PLATFORM).zygote_wakelock.rc \
				device/ti/am62x/init.am62x.usb.rc:$(TARGET_COPY_OUT_VENDOR)/etc/init/init.$(PRODUCT_PLATFORM).usb.rc \
				device/ti/am62x/ueventd.am62x.rc:$(TARGET_COPY_OUT_VENDOR)/etc/ueventd.rc


#. At Android prompt, using RTC as wake-up source, test S2R using following command::

		console:/ # rtcwake -s 10 -m mem
		wakeup using "mem" from /dev/rtc0 at Tue Dec  5 18:33:50 2023
		[   95.695175][ T1849] PM: suspend entry (deep)
		[   95.703599][ T1849] Filesystems sync: 0.004 seconds
		[   95.717906][  T130] ueventd: LoadWithAliases was unable to load rpmsg:rpmsg_ctrl
		[   95.726350][  T130] ueventd: LoadWithAliases was unable to load rpmsg:rpmsg_ns
		[   95.732045][ T1849] remoteproc remoteproc2: stopped remote processor 5000000.m4fss
		[   95.734338][  T130] ueventd: LoadWithAliases was unable to load rpmsg:ti.ipc4.ping-pong
		[   95.742092][ T1849] Freezing user space processes
		[   95.751455][  T130] ueventd: LoadWithAliases was unable to load rpmsg:rpmsg_chrdev
		[   95.765034][ T1849] Freezing user space processes completed (elapsed 0.011 seconds)
		[   95.772742][ T1849] OOM killer disabled.
		[   95.776670][ T1849] Freezing remaining freezable tasks
		[   95.785716][ T1849] Freezing remaining freezable tasks completed (elapsed 0.003 seconds)
		[   95.793846][ T1849] printk: Suspending console(s) (use no_console_suspend to debug)
		[   95.821084][ T1849] omap8250 2800000.serial: PM domain pd:146 will not be powered off
		[   95.830378][   T74] android_work: sent uevent USB_STATE=DISCONNECTED
		[   95.849319][ T1849] Disabling non-boot CPUs ...
		[   95.851966][ T1849] psci: CPU1 killed (polled 4 ms)
		[   95.859202][ T1849] psci: CPU2 killed (polled 0 ms)
		[   95.863988][ T1849] psci: CPU3 killed (polled 4 ms)
		[   95.866492][    C0] PM: pm_system_irq_wakeup: 240 triggered 2b1f0000.rtc
		[   95.866603][ T1849] Enabling non-boot CPUs ...
		[   95.867110][    T0] Detected VIPT I-cache on CPU1
		[   95.867180][    T0] GICv3: CPU1: found redistributor 1 region 0:0x00000000018a0000
		[   95.867254][    T0] CPU1: Booted secondary processor 0x0000000001 [0x410fd034]
		[   95.869278][ T1849] CPU1 is up
		[   95.869698][    T0] Detected VIPT I-cache on CPU2
		[   95.869762][    T0] GICv3: CPU2: found redistributor 2 region 0:0x00000000018c0000
		[   95.869840][    T0] CPU2: Booted secondary processor 0x0000000002 [0x410fd034]
		[   95.871633][ T1849] CPU2 is up
		[   95.872166][    T0] Detected VIPT I-cache on CPU3
		[   95.872235][    T0] GICv3: CPU3: found redistributor 3 region 0:0x00000000018e0000
		[   95.872312][    T0] CPU3: Booted secondary processor 0x0000000003 [0x410fd034]
		[   95.874544][ T1849] CPU3 is up
		[   95.875533][ T1849] ti-sci 44043000.system-controller: ti_sci_resume: wakeup source: 0x50
		[   96.112364][ T1849] am65-cpsw-nuss 8000000.ethernet: set new flow-id-base 19
		[   96.118882][ T1849] am65-cpsw-nuss 8000000.ethernet eth0: PHY [8000f00.mdio:00] driver [Generic PHY] (irq=POLL)
		[   96.118920][ T1849] am65-cpsw-nuss 8000000.ethernet eth0: configuring for phy/rgmii-rxid link mode
		[   96.122398][ T1849] am65-cpsw-nuss 8000000.ethernet eth1: PHY [8000f00.mdio:01] driver [Generic PHY] (irq=POLL)
		[   96.122442][ T1849] am65-cpsw-nuss 8000000.ethernet eth1: configuring for phy/rgmii-rxid link mode
		[   96.291499][ T1849] OOM killer enabled.
		[   96.295346][ T1849] Restarting tasks ... 
		[   96.298020][  T130] ueventd: LoadWithAliases was unable to load virtio:d00000007v00000000
		[   96.303187][ T1849] done.
		[   96.311720][  T130] ueventd: LoadWithAliases was unable to load platform:rproc-virtio
		[   96.315356][  T114] android_work: sent uevent USB_STATE=CONNECTED
		[   96.329971][ T1849] random: crng reseeded on system resumption
		[   96.336133][ T1849] Resume caused by IRQ 240, 2b1f0000.rtc
		[   96.340093][  T130] ueventd: LoadWithAliases was unable to load of:Nethernet-phyT(null)
		[   96.343128][ T1849] remoteproc remoteproc2: powering up 5000000.m4fss
		[   96.355258][  T130] ueventd: LoadWithAliases was unable to load of:Nethernet-phyT(null)
		[   96.390489][  T542] dwc3 31000000.usb: request 0000000000000000 was not queued to ep0out
		[   96.399033][ T1879] android_work: sent uevent USB_STATE=DISCONNECTED
		[   96.400681][  T557] read descriptors
		[   96.409119][  T557] read strings
		[   96.505086][ T1849] remoteproc remoteproc2: Booting fw image am62-mcu-m4f0_0-fw, size 55016
		[   96.515404][ T1849] rproc-virtio rproc-virtio.4.auto: assigned reserved memory node m4f-dma-memory@9cb00000
		[   96.518238][  T130] ueventd: LoadWithAliases was unable to load platform:rproc-virtio
		[   96.526698][ T1849] virtio_rpmsg_bus virtio0: rpmsg host is online
		[   96.537008][  T130] ueventd: LoadWithAliases was unable to load platform:rproc-virtio
		[   96.539484][   T96] virtio_rpmsg_bus virtio0: creating channel ti.ipc4.ping-pong addr 0xd
		console:/ # [   96.543700][ T1849] rproc-virtio rproc-virtio.4.auto: registered virtio0 (type 7)
		[   96.543731][ T1849] remoteproc remoteproc2: remote processor 5000000.m4fss is now up
		[   96.543796][ T1849] PM: suspend exit
		[   96.551052][  T130] ueventd: LoadWithAliases was unable to load virtio:d00000007v00000000
		[   96.556102][   T96] virtio_rpmsg_bus virtio0: creating channel rpmsg_chrdev addr 0xe
		[   96.567673][  T130] ueventd: LoadWithAliases was unable to load rpmsg:rpmsg_ctrl
		[   96.602513][  T130] ueventd: LoadWithAliases was unable to load rpmsg:rpmsg_ns
		[   96.613150][  T130] ueventd: LoadWithAliases was unable to load rpmsg:rpmsg_ns
		[   96.623603][  T130] ueventd: LoadWithAliases was unable to load virtio:d00000007v00000000
		[   96.635333][  T130] ueventd: LoadWithAliases was unable to load rpmsg:ti.ipc4.ping-pong
		[   96.646928][  T130] ueventd: LoadWithAliases was unable to load rpmsg:rpmsg_chrdev
		[   96.661957][  T130] ueventd: LoadWithAliases was unable to load rpmsg:rpmsg_chrdev
		[   97.260423][   T96] android_work: sent uevent USB_STATE=CONNECTED
		[   97.415786][   T96] android_work: sent uevent USB_STATE=CONFIGURED


This puts system to sleep for 10s and then wakes it up via RTC interrupt.
