************************************
Release Notes
************************************
.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Release_Notes

Overview
========

The **Processor-CoreSDK for Linux**
provides a fundamental software platform for development, deployment and
execution of Linux based applications and includes the following:

-  Bootloaders & Filesystems
-  Prebuilt Binaries
-  Detailed Release Notes

Licensing
=========

Please refer to the software manifest, which outlines the licensing
status for all packages included in the prebuilt binaries location. 

Release 07.01.00
==================

Released November 2020

.. rubric:: What's New
   :name: whats-new

Processor SDK 7.1 Release has following new features:

- J7200 Support
- Redesigned SPL for HSM Rearchitecture for J721E and J7200 with boot modes SD and UART
- AM654x PG20 HS Support
- Introduces 2020 LTS Support for AM335x, AM437x, AM57x
- PRU HW UART support for AM335x


.. rubric:: SDK Components & Versions
   :name: sdk-components-versions

+--------------------------+----------------------------+
| Component                | Version                    |
+==========================+============================+
| Linux Kernel             | 5.4.74                     |
+--------------------------+----------------------------+
| U-Boot                   | 2020.01                    |
+--------------------------+----------------------------+
| Yocto Project            | 3.1 (dunfell)              |
+--------------------------+----------------------------+
| ARM Toolchain (gcc)      | 9.2-2019.12 hard-float     |
+--------------------------+----------------------------+

|

Build Information
=====================================

U-Boot
-------------------------

| Head Commit: 3c9ebdb87d65aacc4ec302be8bef3df15364bacd tools: k3_fit_atf: fix FIT image ordering for UART boot
| Date: Tue Nov 17 07:26:32 CST 2020
| uBoot Version: 2020.01
| uBoot Description: 07.01.00.006
| Clone: http://git.ti.com/git/ti-u-boot/ti-u-boot.git
| Branch: 07.01.00.006
| uBoot Tag: 07.01.00.006
|
Kernel
-------------------------

.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 9574bba32a1898794895ca3816e815154c80226d Merge tag 'v5.4.74' of http://git.kernel.org/pub/scm/linux/kernel/git/stable/linux-stable into ti-linux-5.4.y
| Date: Tue Nov 17 07:47:44 CST 2020
| Kernel Version: 5.4.74
| Kernel Description: 07.01.00.006
| Repo: https://git.ti.com/git/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-5.4.y
| Tag: 07.01.00.006
| Kernel defconfig: multi_v7_defconfig
| Compiler Information: arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025

.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: 9002faf1c069e1b0d435199a80a89268e69aeecf Merged TI feature linux_rt-5.4 into ti-rt-linux-5.4.y
| Date: Tue Nov 17 08:33:58 CST 2020
| Kernel Version: 5.4.74
| RT Kernel Version: 5.4.74-rt42
| Kernel Description: 07.01.00.006-rt

| Repo: https://git.ti.com/git/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-5.4.y
| Tag: 07.01.00.006-rt
| Kernel defconfig: multi_v7_defconfig
| Compiler Information: arm-none-linux-gnueabihf-gcc (GNU Toolchain for the A-profile Architecture 9.2-2019.12 (arm-9.10)) 9.2.1 20191025
|

.. rubric:: Generic Kernel Release Notes
   :name: generic-kernel-release-notes

| Generic kernel release notes from kernelnewbies.org can be found at:
  http://kernelnewbies.org/Linux_5.4
| Archived versions can be found at:
  http://kernelnewbies.org/LinuxVersions

|

Yocto
-------------------------

.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 07209f738f14c98e84874573c98a948ba894ecf3 ti-rtos: update metadata and firmware to 07.01.00.38
| Date: 2020-11-18
| Version: dunfell-3.1
| Clone: git://git.yoctoproject.org/meta-ti
| Branch: dunfell
| Release Tag: 07.01.00.006
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: de1a01088d09969462bd8eb262078c4290074aa6 packagegroup-*-connectivity: include devlink from iproute2
| Date: 2020-11-18
| Version: 2020.05
| Clone: git://arago-project.org/git/meta-arago.git
| Branch: dunfell
| Release Tag: 07.01.00.006
|
|

Issues Tracker
=====================================

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Platform", "Title"
   :widths: 15, 30, 100

   LCPD-18857,am571x-idk,ICSSM: PRUETH - Kernel crash when deleting interface to a linux bridge
   LCPD-18856,am571x-idk,ICSSM: PRUETH (switch) - Kernel crash when creating
   LCPD-18858,j721e-evm,DMA heaps are not cached in Core SDK Linux
   LCPD-18342,j721e-idk-gw,IPC tests failed on j721e
   LCPD-18787,j721e-idk-gw,SPL DFU boot test failed
   LCPD-18848,am654x-hsevm,Fit Image is missing default config (k3-am654-base-board-sr1.dtb)
   LCPD-17236,"am654x-evm, am654x-idk, j721e-evm, j721e-evm-ivi, j721e-idk-gw",PDK-IPC build from sources is not creating stripped images and links
   LCPD-18216,"am335x-evm, am43xx-gpevm, am57xx-evm, am654x-evm, dra7xx-evm, j721e-evm, j721e-idk-gw",arm and aarch64 target-side c compilation fails
   LCPD-18694,"am654x-evm, am654x-idk, am654x-hsevm, j721e-evm, j721e-idk-gw",AM65x: cpsw2g: ale parameters init issue
   LCPD-18376,"am654x-evm, am654x-idk, j721e-idk-gw",K3 boards can't boot RT-Linux over NFS
   LCPD-18799,"am57xx-evm, dra7xx-evm",ipumm-fw breaks with latest tools
   LCPD-18784,am654x-idk,SD boot and eMMC alternative boot do not work if tftp images instead of fatload
   LCPD-18447,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",J721e: SD/MMC back up boot mode not functional when eMMC is primary boot mode
   LCPD-18690,am654x-evm,AM65x SR1.0: MMC UHS mode enabled but not functional
   LCPD-18656,j721e-idk-gw,OSPI/SPI ubifs test failed due to cannot read 64 bytes from mtd6/mtd0
   LCPD-18377,am654x-evm,pcie EP is not enumerated on RC on am6
   LCPD-18832,am654x-idk,NVMe SSD could not be detected reliably
   LCPD-16592,"am654x-evm, am654x-idk",Unable to access MMC1 (SD Card) after UART-Based Boot
   LCPD-18669,am654x-evm,SA2UL causes boot failure if built-in to kernel
   LCPD-18260,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15, dra71x-evm, dra72x-evm, dra76x-evm, dra7xx-evm",remoteproc/omap: Error recovery is broken with DSPs
   LCPD-16382,dra7xx-evm,pcie usb/sata read write tests failed
   LCPD-18755,am654x-idk,ICSSG: packet loss on ping over VLAN
   LCPD-18039,omapl138-lcdk,omapl138: ANKER USB3.0 to ethernet adapter does not work
   LCPD-18849,j721e-idk-gw,OpenSSL HW crypto perfomance out of expected range
   LCPD-15551,"k2e-evm, k2g-evm, k2g-ice, k2hk-evm, k2l-evm",Upstream: remoteproc/keystone: DSP remoteproc driver is broken with upstream 4.19+ kernels
   LCPD-14935,am654x-evm,8250_omap: BUG_ON() due to pm_runtime_irq_safe()
   LCPD-14842,"am335x-evm, am335x-sk, beaglebone-black",musb: unplug usb-serial device cause console lockup
   LCPD-18164,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15, dra71x-evm, dra72x-evm, dra76x-evm, dra7xx-evm",vlan_core throws a WARN_ON upon system suspend on all DRA7xx/AM57xx platforms
   LCPD-18594,"am654x-evm, am654x-idk, am654x-hsevm, j721e-evm, j721e-hsevm, j721e-evm-ivi, j721e-idk-gw",CPSW2G: CPTS: sync PPS to adjusted PTP clock
   LCPD-18593,"am654x-evm, am654x-idk, am654x-hsevm, j721e-evm, j721e-hsevm, j721e-evm-ivi, j721e-idk-gw",CPSW2G: restore vlan cfg after ifconfig up/down
   LCPD-17783,"am654x-evm, am654x-idk",USB: USB2PHY Charger Detect is enabled by default without VBUS presence
   LCPD-18427,am574x-idk,icss-m: prueth: 100M Half-Duplex support is missing
   LCPD-18660,,K2H MDIO signal integrity workaround doesn't work in kernel 4.19
   LCPD-18695,"am654x-evm, am654x-idk, am654x-hsevm, j721e-evm, j721e-hsevm, j721e-evm-ivi, j721e-idk-gw",AM65x: cpsw2g: allmulti mode is broken
   LCPD-17010,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",J7ES: USB: gadget mode breaks with PC host with USB3.0 LPM
   LCPD-18176,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15, dra71x-evm, dra72x-evm, dra76x-evm, dra7xx-evm",iommu/omap: BUG: sleeping function called from invalid context
   LCPD-18264,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15, dra71x-evm, dra72x-evm, dra76x-evm, dra7xx-evm",Upstream: remoteproc: Fix issues caused by fixed memory region support for vdevs
   LCPD-16590,"am335x-evm, am335x-sk, beaglebone-black",am335x: usb bus power lost after system suspend resume
   LCPD-18527,,Remove Ethernet Bonding from PRU Documentation
   LCPD-18757,am654x-idk,ICSSG: hangs on netperf/iperf3 test at 100M FD
   LCPD-18853,"am654x-evm, am654x-idk, am654x-hsevm, j721e-evm, j721e-hsevm, j721e-evm-ivi, j721e-idk-gw",UDMA: slave_sg generates TR interrupt at the end of the transfer
   LCPD-18793,j721e-idk-gw,pcie ep tests failed with big size with DMA mode
   LCPD-18783,"am654x-evm, am654x-idk",Kernel Oops: Unable to handle kernel paging request at virtual address ffbf821d24d6e040
   LCPD-17118,"am57xx-evm, dra7xx-evm",Kernel MMC/SD user's guide incorrectly refers to OMAP-HSMMC
   LCPD-17877,"am654x-evm, am654x-idk",Crash observed when trying to perform multiple CAL capture
   LCPD-15737,"am654x-evm, am654x-idk",AM65x: MMC OTAPDLY values must match values in the Data Manual
   LCPD-18211,j721e-idk-gw,Uboot OSPI performance decreased for both read/write
   LCPD-18782,am654x-idk,ICSSG: invalid packets captured with promisc mode disabled
   LCPD-16120,"j721e-evm, j721e-evm-ivi","DP: Link fails right after link training, unless voltage swing is 2 or 3"
   LCPD-17788,"am654x-evm, am654x-idk",PCI-Express: GEN3 (8GT/s) Operation Not Supported.
   LCPD-18431,am57xx-evm,Display artifacts on QT window
   LCPD-18753,"am654x-evm, am654x-idk, am654x-hsevm",AM65x: cpsw2g: iet changes bloks rrobin cfg is <2 TX queues
   LCPD-12783,k2g-evm,Missing instruction for pcie-ep config on k2g-evm for 4.19 kernel
   LCPD-17772,j721e-idk-gw,systemd doesn't show ansi sequences correctly
   LCPD-18847,"am654x-evm, am654x-idk, am654x-hsevm, j721e-evm, j721e-hsevm, j721e-evm-ivi, j721e-idk-gw",UDMA: atype is ignored even if it is correctly specified for non slave channels

|


Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   LCPD-18985,"am654x-evm, am654x-idk",AM65x: PG2.0: CAN ifconfig down causes kernel crash
   LCPD-19582,"j7200-evm, j7200-hsevm",j7200: TR mode channels can not be requested for peripherals
   LCPD-19637,"j721e-evm, j721e-hsevm, j721e-evm-ivi, j721e-idk-gw",AM64: presil: J721E: NETDEV WATCHDOG: eth0 (am65-cpsw-nuss): transmit queue 0 timed out
   LCPD-19247,"am654x-evm, am654x-idk, am654x-hsevm",UDMA: recent changes broke icssg pru ethernet
   LCPD-18986,"am654x-evm, am654x-idk",AM65x: PG2.0: Linux boot process pauses between MMCSD and DSS probe
   LCPD-19490,am654x-evm,AM6: DSS clock configuration failures (SYSFW timeouts)
   LCPD-19520,j7200-evm,CPSW5g: virt-mac interface not coming up on on j7200
   LCPD-19451,am572x-idk,ICSS-M: Dual Emac: PTP over VLAN received PDELAY_RESP without timestamp
   LCPD-19432,"am654x-evm, am654x-idk, j721e-evm, j721e-evm-ivi, j721e-idk-gw, j7200-evm",Linux kernel fails to boot with SYSFW 2020.07-rc1
   LCPD-19458,,Upstream: remoteproc/omap: Fix kernel BUG page reporting on OMAP4 Pandaboard
   LCPD-19444,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",TI SDK Kernel boot broken during module loading due to cdns3-ti.ko
   LCPD-19224,am572x-idk,hsr to prp switch cause kernel crash
   LCPD-19074,k2g-evm,board failed to obtain dhcp address and can't nfs boot
   LCPD-19091,am654x-idk,MMCSD could not be enumerated
   LCPD-19085,am57xx-evm,Mainline Uboot failed to boot on am5
   LCPD-18910,"am335x-evm, am43xx-gpevm, am57xx-evm, am654x-evm, j721e-idk-gw",NFS boot is broken
   LCPD-19075,"am654x-evm, j721e-idk-gw",am6/J7 upstream builds are using wrong u-boot
   LCPD-19078,"am335x-evm, am43xx-gpevm, am57xx-evm",NFS does not work when using custom build for mainline kernel
   LCPD-18887,am654x-hsevm,am654x-hsevm fails to boot
   LCPD-19690,am43xx-gpevm,Network failure on am43xx: 2020-0929
   LCPD-19442,"j721e-idk-gw, j7200-evm","J7ES,J7VCL: Can't boot from eMMC alternate boot mode"
   LCPD-19641,"j721e-evm, j721e-hsevm, j721e-evm-ivi, j721e-idk-gw",Backport: AM64: presil: J721E: NETDEV WATCHDOG: eth0 (am65-cpsw-nuss): transmit queue 0 timed out
   LCPD-19744,"j7200-evm, j7200-hsevm",Custom image names to use $TAG_modules.tar
   LCPD-19760,am654x-hsevm,AM6 HS Fails to build and boot
   LCPD-19545,,Upstream Kernel Build Failed with overlay repo (ti-upstream-tools)
   LCPD-19445,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",remoteproc/k3-dsp: C66x IPC is not functional with newer SYSFW in remoteproc mode
   LCPD-19488,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm",CPSW: Switch config kernel headers warnings
   LCPD-19237,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",J721E fails to boot with SYSFW 2020.06
   LCPD-19261,,Cryptodev is broken in upstream
   LCPD-19234,"j721e-evm, j721e-hsevm, j721e-evm-ivi, j721e-idk-gw, j7200-evm, j7200-hsevm",j721e/j7200: Missing PSI-L configuration for the second DMA port of MCU SA2UL
   LCPD-19568,"j721e-idk-gw, j7200-evm",CPSW5g: Cannot get DHCP address
   LCPD-19538,j721e-idk-gw,j721e-cpsw-virt-mac: dma descriptors not enough
   LCPD-19676,"am57xx-evm, am57xx-beagle-x15, dra7xx-evm",Boot failure on J6EVM: 2020-0925
   LCPD-19466,am572x-idk,"ICSS-M: HSR: PTP over VLAN ""rogue peer delay response"""
   LCPD-19467,am572x-idk,"ICSS-M: PRP: PTP over VLAN ""timed out while polling for tx timestamp"""
   LCPD-19843,,upstream: regression: cpts irq not working after a suspend/resume cycle
   LCPD-18902,am654x-hsevm,Unhandled Exception from EL1 observed during boot
   LCPD-18888,"am335x-evm, am335x-hsevm, beaglebone, beaglebone-black",Qt application fails to launch with HDMI display
   LCPD-19485,am57xx-evm,omapdrm: v5.9-rc1 fails with lock issue
   LCPD-19646,j721e-evm,U-Boot: reset command fails
   LCPD-19449,j7200-evm,J7VCL: U-Boot: DFU boot broken
   LCPD-18987,"am437x-idk, am437x-sk",CPU load regression in omap2-mcspi due to readl_poll_timeout()
   LCPD-19226,"am654x-evm, am654x-idk, j721e-evm, j721e-evm-ivi, j721e-idk-gw",remoteproc/k3-r5f: Fix TCM initialization upon reset release failure
   LCPD-19063,"am335x-ice, am437x-idk, am571x-idk, am572x-idk, am574x-idk, am574x-hsidk","pruss: uart: build warning ""conversion from long unsigned int to int"""
   LCPD-18932,am572x-idk,ICSS-M: Switch: ping doesn't work from DUT to PC
   LCPD-19214,"am654x-evm, am654x-idk, am654x-hsevm, j721e-evm, j721e-hsevm, j721e-evm-ivi, j721e-idk-gw",arm64: dts: Fix interconnect node names
   LCPD-19184,"am654x-evm, am654x-idk, am654x-hsevm, j721e-evm, j721e-hsevm, j721e-evm-ivi, j721e-idk-gw",Upstream: arm64: dts: Fix interconnect node names
   LCPD-19179,am571x-idk,PRP: Packet size off by 6 bytes
   LCPD-18909,"am654x-evm, j721e-idk-gw",Uboot: SPL: failed to boot from all boot devices
   LCPD-18914,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15, bbai, dra71x-evm, dra72x-evm, dra76x-evm, dra7xx-evm",Upstream: remoteproc/omap: Auto-suspend is broken with 5.8-rc1
   LCPD-18913,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15, dra71x-evm, dra72x-evm, dra76x-evm, dra7xx-evm",Upstream: remoteproc/omap: Fix couple of dra7 dts issues
   LCPD-18920,am654x-evm,Add missing overlay files k3-am654-pcie-usb3.dtbo and k3-am654-evm-oldi-lcd1evm.dtbo
   LCPD-19076,,Add parted to base rootfs for mainline
   LCPD-19079,am43xx-gpevm,The base dtb is not being built with symbols and could not apply overlay
   LCPD-19077,,Add dropbear ssh server to base rootfs for mainline
   LCPD-19648,am654x-idk,SDK 7.0.1 Eth stability with SR2 firmware
   LCPD-19687,"am654x-evm, am654x-idk, j721e-evm, j721e-evm-ivi, j721e-idk-gw, j7200-evm",Upstream: hwspinlock/omap: Fix dt binding warnings on linux-next with k3.yaml
   LCPD-19699,am574x-idk,AM57 Kernel v5.4 crash on ethtool -T
   LCPD-19579,"am654x-evm, am654x-idk",U-Boot: AM65x eMMC boot does not work
   LCPD-19638,"j721e-evm, j721e-hsevm, j721e-evm-ivi, j721e-idk-gw",u-boot: AM64: presil: J721E: NETDEV WATCHDOG: eth0 (am65-cpsw-nuss): transmit queue 0 timed out
   LCPD-19672,am335x-evm,AM335x-evm has no networking support
   LCPD-19673,am43xx-gpevm,am437x-evm has no networking support
   LCPD-19720,"am654x-evm, am654x-idk, j721e-idk-gw, j7200-evm",sdhci_am654 driver does not autoload when built as a module
   LCPD-19729,"am335x-ice, am437x-idk, am571x-idk, am572x-idk, am574x-idk",ICSS-M PRUETH: IRQF_ONESHOT : remove the flag in request_irq()
   LCPD-19745,beaglebone-black,uart custom images are missing
   LCPD-19724,"am654x-evm, am654x-idk, j721e-evm, j721e-evm-ivi, j721e-idk-gw, j7200-evm",hwspinlock/omap: Fix dt binding warnings with k3.yaml
   LCPD-19754,j721e-evm,U-boot tries to apply disabled memory regions
   LCPD-19753,"am654x-evm, am654x-idk, j721e-evm, j721e-evm-ivi, j721e-idk-gw",U-Boot: Overlay loading fails on latest ti-u-boot
   LCPD-19603,"j7200-evm, j7200-hsevm",J7VCL: OSPI PHY calibration is flaky
   LCPD-19709,am335x-evm,spi: build errors in 'drivers/spi/omap3_spi'
   LCPD-19658,am654x-idk,ICSSG: xmit timeout error
   LCPD-19611,"am654x-evm, am654x-idk, am654x-hsevm, j721e-evm, j721e-hsevm, j721e-idk-gw, j7200-evm, j7200-hsevm",U-Boot: Memory leak during OSPI PHY calibration
   LCPD-19570,j721e-evm,J721e: R5 SPL: Environment bad CRC error
   LCPD-19585,"am654x-evm, am654x-idk",icssg: prueth: cleanup code not complete and re-use possibilities
   LCPD-19134,j721e-idk-gw,USB device does not work at super speed at default
   LCPD-19092,am654x-idk,USB msc could not be enumerated
   LCPD-19252,,PRUETH: hsr/prp: nt_update worker left running even after interface is down
   LCPD-19087,j721e-idk-gw,Audio devices are not initialized
   LCPD-19541,"am654x-evm, am654x-hsevm, j721e-hsevm, j721e-idk-gw, j7200-evm, j7200-hsevm","U-Boot: Incorrect default value for mtdparts for J721E, AM65x, and J7200"
   LCPD-19558,am654x-idk,ICSSG SR1: ifconfig eth1 down and up fails
   LCPD-19498,am572x-idk,Upstream: New CPSW: unable to create linux bridge over cpsw ports.
   LCPD-19246,"am335x-ice, am437x-idk, am571x-idk, am572x-idk, am574x-idk, k2g-ice",net: prueth: build error with CONFIG_HSR not set
   LCPD-19459,"am571x-idk, am572x-idk, am574x-idk",CPSW: MC entries for VLAN not removed from ALE table
   LCPD-19516,am571x-idk,"CPSW: Send cpsw, cpsw-new patches upstream"
   LCPD-19067,j721e-idk-gw,CPSW2G: UDP iperf between two EVMs shows huge packet loss
   LCPD-19804,"am654x-evm, am654x-idk, j721e-evm, j721e-evm-ivi, j721e-idk-gw, j7200-evm",ti-rpmsg-char: Cleanup of endpoint devices is broken for multiple handles
   LCPD-19779,,ALL legacy: CPTS: PTPv1 is advertised by mistake
   LCPD-19778,"k2e-evm, k2e-hsevm, k2g-evm, k2g-hsevm, k2g-ice, k2hk-evm, k2hk-hsevm, k2l-evm, k2l-hsevm",K2G: CPTS: crash
   LCPD-19837,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",k3conf: DSP frequencies are printed incorrectly as 0
   LCPD-19518,k2e-evm,[ti:ti-linux-5.4.y 3441/9102] drivers/phy/ti/phy-keystone-serdes.c:1442:6: warning: variable 'ret' set but not used
   LCPD-19790,"j721e-idk-gw, j7200-evm",UART boot fails for j721e and j7200 in 07.01-rc4
   LCPD-19748,"am654x-evm, am654x-idk",SR1: AM654x mmc boot - Uboot shows some fdt command error
   LCPD-19088,"am335x-evm, am43xx-gpevm, beaglebone-black",Display flickering issues
   LCPD-19787,"j721e-evm, j7200-evm",ATF: Reboot Command Fails
   LCPD-19789,j721e-evm,Kernel: Reboot Command Fails
   LCPD-19717,"am654x-evm, j721e-idk-gw, j7200-evm",am654-gpevm: kernel image boot reports corruption
   LCPD-19064,,kernel test robot reports warning 'Clarify calculation precedence for '&' and '?'. [clarifyCalculation] '
   LCPD-19583,am654x-idk,AM65 ICSSG Ethernet Transmit timestamp stops working on RT Linux with PG2 IDK
   LCPD-19251,,Fix compilation warnings in hsr and prueth drivers
   LCPD-19809,am571x-idk,Fix probing of lp3943 pwm

|

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
   :header: "Record ID",  "Title"
   :widths: 15, 80

   LCPD-19811,CPSW: ALE incorrectly routes packets with CRC errors
   LCPD-19586,USB: 2.0 PHY hangs if received signal amplitude crosses squelch threshold multiple times within the same packet
   LCPD-19517,R5FSS: The same interrupt cannot be nested back-2-back within another interrupt
   LCPD-19447,DSS: Disabling a layer connected to Overlay may result in synclost during the next frame
   LCPD-19068,DSS: Disabling a layer connected to Overlay may result in synclost during the next frame
   LCPD-19056,USB: DMA hangs if USB reset is received during DMA transfer in device mode
   LCPD-19048,USB: Invalid termination of DMA transfer for endpoint following Isochronous endpoint in Superspeed device mode
   LCPD-19047,USB: Race condition while reading TRB from system memory in device mode
   LCPD-19041,PCIe: End of Interrupt (EOI) not enabled for PCIe legacy interrupts
   LCPD-19032,CPSW: CPSW Does Not Support Intersperced Express Traffic (IET â€“ P802.3br/D2.0) In 10/100Mbps Mode
   LCPD-19031,[CPTS] GENF (and ESTF)  Reconfiguration Issue
   LCPD-19030,USB: USB2PHY Charger Detect is enabled by default without VBUS presence
   LCPD-19029,PCI-Express (PCIe) May Corrupt Inbound Data
   LCPD-19028,DSS : DSS DPI Interface does not support BT.656 and BT.1120 output modes
   LCPD-19027,CPSW does not support CPPI receive checksum (Host to Ethernet) offload feature
   LCPD-19026,MMCSD: Negative Current from UHS-I PHY May Create an Over-Voltage Condition on VDDS6 and VDDS7 which exposes the Device to a Significant Reliability Risk
   LCPD-19025,"IO, MMCSD: Incorrect IO Power Supply Connectivity Prevent Dynamic Voltage Change on VDDSHV6 and VDDSHV7"
   LCPD-19024,RINGACC and UDMA ring state interoperability issue after channel teardown
   LCPD-19022,UDMA-P Real-time Remote Peer Registers not Functional Across UDMA-P Domains
   LCPD-18999,PCIe: Endpoint destination select attribute (ASEL) based routing issue
   LCPD-18996,Hyperflash: Hyperflash is not functional
   LCPD-18995,OSPI: OSPI Boot doesn't support some xSPI modes or xSPI devices
   LCPD-18992,DSS: Frame Buffer Flip/Mirror Feature Using RGB24/BGR24 Packed Format can Result in Pixel Corruption
   LCPD-18981,UDMAP: Packet mode descriptor Address Space Select Field Restrictions
   LCPD-18979,MCAN: Message Transmitted with Wrong Arbitration and Control Fields (Early Start of Frame)
   LCPD-18955,DSS : DSS Does Not Support YUV Pixel Data Formats
   LCPD-18954,DSS : DSS Does Not Support YUV Pixel Data Formats
   LCPD-18953,DSS : DSS Does Not Support YUV Pixel Data Formats
   LCPD-18952,DSS : DSS Does Not Support YUV Pixel Data Formats
   LCPD-17806,Cortex-R5F: Deadlock might occur  when one or more MPU regions is configured for write allocate mode
   LCPD-17788,PCI-Express: GEN3 (8GT/s) Operation Not Supported.
   LCPD-17787,SA2UL: Auth/decrypt operations with 2nd input thread does not send the DMA packet out
   LCPD-17786,UART: Spurious UART Interrupts When Using DMA
   LCPD-17785,UART: Spurious UART Interrupts When Using DMA
   LCPD-17784,CPSW: CPSW Does Not Support Intersperced Express Traffic (IET â€“ P802.3br/D2.0) In 10/100Mbps Mode
   LCPD-17783,USB: USB2PHY Charger Detect is enabled by default without VBUS presence
   LCPD-17333,[CPTS] GENF (and ESTF)  Reconfiguration Issue
   LCPD-17220,U-Boot Hyperbus: Hyperflash reads limited to 125MHz max. frequency
   LCPD-16904,PCIe: Unsupported request (UR) or Configuration Request Retry Status (CRS) in configuration completion response packets results in external abort
   LCPD-16643,Hyperbus: Hyperflash reads limited to 125MHz max. frequency
   LCPD-16605,MMC: MMC1/2 Speed Issue
   LCPD-16538,PCI-Express (PCIe) May Corrupt Inbound Data
   LCPD-16364,MMCSD: Negative Current from UHS-I PHY May Create an Over-Voltage Condition on VDDS6 and VDDS7 which exposes the Device to a Significant Reliability Risk
   LCPD-16363,"IO, MMCSD: Incorrect IO Power Supply Connectivity Prevent Dynamic Voltage Change on VDDSHV6 and VDDSHV7"
   LCPD-16350,DSS: Frame Buffer Flip/Mirror Feature Using RGB24/BGR24 Packed Format can Result in Pixel Corruption
   LCPD-14941,RINGACC and UDMA ring state interoperability issue after channel teardown
   LCPD-14580,DSS : DSS Does Not Support YUV Pixel Data Formats
   LCPD-14579,DSS : DSS Does Not Support YUV Pixel Data Formats
   LCPD-14578,DSS : DSS DPI Interface does not support BT.656 and BT.1120 output modes
   LCPD-14577,CPSW does not support CPPI receive checksum (Host to Ethernet) offload feature
   LCPD-14187,UDMA-P Real-time Remote Peer Registers not Functional Across UDMA-P Domains
   LCPD-14186,UDMA-P Host Packet Descriptorâ€™s â€œ0x3FFFFFâ€ Packet Length Mode not Functional
   LCPD-14185,MSMC: Non-coherent memory access to coherent memory can cause invalidation of snoop filter
   LCPD-14184,USB:  SuperSpeed USB Non-Functional
   LCPD-14159,The assertion of warm reset coinciding with a debug configuration access targeting the STM Subsystem may result in a hang of said debug configuration access
   LCPD-13887,DDR Controller ECC Scrubbing feature can cause DRAM data corruption
   LCPD-13884,CPTracer Bus Probes MAIN_CAL0_0 and MCU_SRAM_SLV_1 are not able to distinguish between secure and non-secure transactions
   LCPD-9173,i897: USB Stop Endpoint doesnt work in certain circumstances
   LCPD-9084,i887: Software workaround to limit mmc3 speed to 64MHz
   LCPD-8294,37 pins + VOUT pins need slow slew enabled for timing and reliability respectively
   LCPD-8277,u-boot: j6: SATA is not shutdown correctly as per errata i818
   LCPD-7642,MMC/SD: i832: return DLL to default reset state with CLK gated if not in SDR104/HS200 mode.
   LCPD-6907,Workaround errata i880 for RGMII2 is missing
   LCPD-5931,DRA7xx: AM57xx: mmc: upstream errata workaround for i834
   LCPD-5924,ALL: CONNECTIVITY: CPSW: errata i877 workarround for cpsw
   LCPD-5836,CAL: Errata: i913: CSI2 LDO needs to be disabled when module is powered on
   LCPD-5460,Implement WA for Vayu errata i829 (Reusing Pipe Connected To Writeback Pipeline On The Fly To An Active Panel)
   LCPD-5311,i893: DCAN ram init issues in HW AUTO and when traffic hitting CAN bus (open investigation)
   LCPD-5310,"i900:  CTRL_CORE_MMR_LOCK_5 region after locking results in ctrl module inaccessible, recoverable only post a reset"
   LCPD-5309,   LCPD:  i896: USB Port disable doesnt work
   LCPD-5308,i897: USB Stop Endpoint doesnt work in certain circumstances
   LCPD-5052,Upstream: Post the dmtimer errata fix for i874
   LCPD-4975,DSS AM5/DRA7: implement WA for errata i886
   LCPD-4912,DRA7: USB: Implement ErrataID_i896_PED_issue
   LCPD-4911,DRA7: USB: Investigate applicability of Errata i897: StopEndpoint_issue
   LCPD-4910,J6/OMAP5: errata i810 implementation
   LCPD-4648,[rpmsg 2014 LTS] Implement errata i879 - DSP MStandby requires CD_EMU in SW_WKUP
   LCPD-4647,[rpmsg 2015 LTS] Implement errata i879 - DSP MStandby requires CD_EMU in SW_WKUP
   LCPD-4225,J6: Errata: i834: Investigate possibility of software workaround
   LCPD-4218,Implement Workaround for Errata i813 - Spurious Thermal Alert Generation When Temperature Remains in Expected Range
   LCPD-4217,Implement Workaround for Errata i814 - Bandgap Temperature read Dtemp can be corrupted
   LCPD-4195,J6: SATA: Investigate applicability of i807
   LCPD-4184,Implement workaround for errata i814 - Bandgap Temperature read Dtemp can be corrupted
   LCPD-1776,"[J6 SATA Adaptation] J6 - Errata i783, SATA Lockup After SATA DPLL Unlock/Relock"
   LCPD-1188,J6: Baseport: Errata i877: RGMII clocks must be enabled to avoid IO timing degradation due to Assymetric Aging
   LCPD-1171,DRA7: DMM errata i878 (framebuffer part)
   LCPD-1146,DMM hang: Errata VAYU-BUG02976 (i878) (register part)
   LCPD-1108,J6: Wrong Access In 1D Burst For YUV4:2:0-NV12 Format (Errata i631)
   LCPD-1087,J6: MMC: Errata: i802: OMAP5430 MMCHS: DCRC errors during tuning procedure
   LCPD-1022,J6: Errata: i694: System I2C hang due to miss of Bus Clear support @ OMAP level
   LCPD-976,J6/J6eco: 32clk is psuedo (erratum i856) - clock source
   LCPD-975,J6/J6eco: 32clk is psuedo (erratum i856) - realtime counter
   LCPD-941,"OMAP4,5: DSS: implement workaround for errata i740"
   LCPD-876,OMAP5: Errata i810: DPLL Controller Sticks when left clock requests are removed

|

SDK Known Issues
-----------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   LCPD-19835,am574x-hsidk,"AM57-HS fails to boot due to E/TC:0 ti_sip_handler",
   LCPD-19743,"j7200-evm, j7200-hsevm",Packages.gz is missing,
   LCPD-16454,j721e-evm,DSS underflows with 1080p/2.5k display on inmate cell,
   LCPD-17387,"j721e-evm-ivi, j721e-idk-gw",Underflow and CRTC SYNC LOST observed while running GLMark2 ("1x1080p + 1x4k"),
   LCPD-15410,dra7xx-evm,vdd_shv_power is ~200mw higher than on previous lts,
   LCPD-18115,j721e-idk-gw,PVR Error observed while running glmark2,
   LCPD-18214,dra7xx-evm,SGX-HW recovery seen with NV12 buffer usage with wayland-drm applications,
   LCPD-16130,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",Exception triggered by drm_dev_unregister during poweroff,
   LCPD-17412,am654x-evm,QT5 Webengine-based browser crashing with any resize operation,
   LCPD-17413,"am335x-evm, am43xx-gpevm, am57xx-evm, am654x-evm",QT Webengine-based browser: the mouse does not work within the web page with QPA EGLFS,
   LCPD-9819,"am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm",drmextended app cannot enable plane,
   LCPD-9819,"am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm",drmextended app cannot enable plane,
   LCPD-16366,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",RGX kick test fails when 32 sync dependencies are set for each command,
   LCPD-12270,dra72x-evm,VDD_SHV5 power consumption is around 200mw higher than on previous releases,
   LCPD-8352,"am43xx-gpevm, am57xx-evm, dra7xx-evm","weston stress testing with 75 concurrent instances of simple-egl leads to unresponsive HMI due to running out of memory,1. Restart Wayland application. 2. Restart board if Weston is killed by oom-killer oom-killer stops an application to free up memory. It could be either Wayland client or Weston itself. If Weston is killed, a board reboot would be required."
   LCPD-17213,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",Weston sometimes fails to start when booting with nfs filesystem,
   LCPD-18056,"j721e-evm-ivi, j721e-idk-gw",PVR Errors observed while running deqp-gles,
   LCPD-19716,"j7200-evm, j7200-hsevm",GFX_XS_FUNC_UYVY_TEXTURE test fails,
   LCPD-16877,k2hk-evm,ti-ipc-examples-linux intermittent build failure,
   LCPD-19781,"am654x-evm, am654x-idk, j721e-evm, j721e-hsevm, j721e-evm-ivi, j7200-evm, j7200-hsevm",OE: ti-rpmsg-char: Library header files and primary so file are missing in FS,
   LCPD-13443,am57xx-hsevm,Camera is not detected on AM572x-HSEVM,
   LCPD-9753,"am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm",GLSDK gst test suite waylandsink and 1080i kmssink tests fail,
   LCPD-13816,am654x-evm,Chromium-wayland broswer does not work on AM654x with page size = 64k,
   LCPD-13817,am654x-evm,Qt5 Webengine-based broswer does not work on AM654x with pagesize = 64k,
   LCPD-16531,j721e-evm,"video decode: vxd_dec warnings displayed at end of gstreamer hevc playback to kmssink for certain video",
   LCPD-15795,"am57xx-evm, dra71x-evm, dra72x-evm, dra76x-evm, dra7xx-evm",Allow non-root user access to IPC resources to enable multimedia use case,
   LCPD-17283,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",Running Gstreamer's gst-discoverer causes a crash,
   LCPD-9754,"am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm, dra71x-evm, dra71x-hsevm, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm",GLSDK Sometimes capture + encode fails,
   LCPD-5654,AM335x,AM3 Beaglebone black: MPEG4+AAC Dec does not play out any audio for some HDMI monitors,
   LCPD-15810,"am335x-evm, am43xx-gpevm, k2g-evm",Illegal instruction reported when trying to decode h264 stream with gstreamer,
   LCPD-12709,am43xx-hsevm,Boards resets when standby state is attempted,
   LCPD-17817,"am335x-hsevm, am43xx-epos, am43xx-hsevm, k2e-hsevm, k2g-hsevm, k2hk-hsevm, k2l-hsevm",Images created with Proc-SECDEV grow with number of times SECDEV has been used,
   LCPD-17781,am43xx-epos,am43xx-epos boot instability,
   LCPD-16207,am574x-hsidk,Board does not boot sometimes due to crypto crash when debug options are enabled,
   LCPD-9364,am57xx-hsevm,There are SCM FW warnings during the am57xx-hsevm boot,
   LCPD-9254,am43xx-hsevm,Kernel warnings in boot for am437x-hsevm,
   LCPD-9782,k2e-hsevm,CPU hotplug generates an exception and system crashes,
   LCPD-19822,j721e-idk-gw,ARM benchmark testcases returning lower than expected performance,
   LCPD-14254,"am654x-evm, am654x-idk",meta-ti: Need a recipe update to pick up the new AM65x PRU Ethernet firmwares,
   LCPD-12383,omapl138-lcdk,Umount failed if sata is mounted as vfat after boot without enough delay before umount,
   LCPD-12405,"am335x-evm, am335x-ice, am43xx-epos, am43xx-gpevm, am57xx-evm, dra71x-evm, k2e-evm, k2e-hsevm, k2g-evm, k2g-hsevm, k2l-evm",Openssl certgen fails due to coredump in openssl_gen_cert.sh,
   LCPD-13947,am335x-evm,nativesdk-opkg is broken in the devkit,
   LCPD-17449,"am335x-evm, am335x-hsevm, am335x-ice, am335x-sk, am43xx-epos, am43xx-gpevm, am43xx-hsevm, am437x-idk, am437x-sk, am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm, am654x-evm, am654x-idk, am654x-hsevm, beaglebone, beaglebone-black, dra71x-evm, dra71x-hsevm, dra72x-evm, dra72x-hsevm, dra76x-evm, dra76x-hsevm, dra7xx-evm, dra7xx-hsevm",libasan_preinit.o is missing in devkit,
   LCPD-16114,"am335x-evm, am335x-ice, am335x-sk",RTC Init Script Needs to Wait for Module Load,
   LCPD-15918,"am43xx-gpevm, dra7xx-evm, k2g-evm, k2l-hsevm",ti-ipc-rtos gets stuck in xdctools,
   LCPD-16053,"k2e-evm, k2g-evm, k2hk-evm, k2l-evm",IP address is not getting displayed on EVM LCD for K2 EVMs,
   LCPD-9923,"am335x-evm, am43xx-gpevm, am57xx-evm, k2e-evm, k2g-evm, k2hk-evm, k2l-evm",Error message in boot log for K2 and AM platforms,
   LCPD-9072,"k2e-evm, k2e-hsevm, k2hk-evm, k2hk-hsevm, k2l-evm, k2l-hsevm",netapi requires changes due to new libnl and xfrm,
   LCPD-7255,"am335x-evm, am335x-ice, am335x-sk, am43xx-gpevm, am43xx-hsevm, am437x-idk, am437x-sk, am571x-idk, am572x-idk, am57xx-evm, beaglebone, beaglebone-black, beaglebone-black-ice, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm, k2e-evm, k2g-evm, k2g-ice, k2hk-evm, k2l-evm","Telnet login takes too long (~40 seconds)","Booting with rootfs mounted over NFS might cause ~40 seconds delay on telnet login because DNS entries might not be properly populated. To work around this issue, enter appropriate DNS server IP in resolv.conf. For example: echo 'nameserver 192.0.2.2' > /etc/resolv.conf;"
   LCPD-7025,am43xx-gpevm,System takes more than 10 seconds to go from login prompt to system prompt,Automated tests need to account for this boot delay
   LCPD-5091,AM335x,Installing AM335x CoreSDK 15.01 leads to dumped core,
   LCPD-8345,"am335x-evm, am437x-idk, dra7xx-evm, dra7xx-hsevm, k2e-evm, k2e-hsevm, k2hk-evm, k2l-evm","Board fails to start login console after waiting 3.5 minutes ( hard to reproduce, ~4/1000)",Restart the EVM
   LCPD-12443,omapl138-lcdk,SD boot time with coresdk rootfs increases ~30% on omapl138-lcdk,
   LCPD-4327,AM572x,remove temporary files from kernel package,
   LCPD-4952,"K2E, K2G, K2HK, K2L",tisdk-image.bbclass limitation on TARGET_IMAGES,
   LCPD-5649,"K2E, K2HK, K2L",Integration: Release content for core-sdk should not be the content of SD card for k2 platform,
   LCPD-17304,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",Error Recovery Test for VDEC_ERROR_SR_ERROR does not trigger error,
   LCPD-8398,"dra7xx-evm, dra7xx-hsevm",gsttestplayer: Reverse playback stops after next seek,
   LCPD-8278,k2e-hsevm,Secure boot takes more than 10 minutes,
   LCPD-15367,"am335x-evm, am574x-idk",Boot time increased about 15s,

|


U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID","Platform", "Title","Workaround"
   :widths: 15, 30, 70, 30

   LCPD-19872,"j721e-idk-gw,j7200-evm",uboot: OSPI Boot broken post SPL rearch,
   LCPD-19636,"j721e-hsevm",OSPI Boot broken,
   LCPD-19776,"j721e-idk-gw",uboot: some socketed evms fail to boot,
   LCPD-19133,"am335x-evm, am335x-hsevm, am335x-ice, am335x-sk",Netconsole output corrupted when CONFIG_NETCONSOLE_BUFFER_SIZE >= 281,
   LCPD-17770,"am654x-evm, am654x-idk, am654x-hsevm, j721e-evm, j721e-hsevm, j721e-evm-ivi, j721e-idk-gw",U-Boot: Fix order of MCU R5 shutdown depending on cluster mode,
   LCPD-17406,j721e-idk-gw,U-boot: Uboot has no knowledge of memory reserved for remote cores,
   LCPD-17210,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm","AM57x EVM could not boot when using DEFAULT_DEVICE_TREE=""am57xx-beagle-x15""",
   LCPD-16524,"am654x-evm, am654x-idk, am654x-hsevm",Need to adjust RMW bit when using enabling ECC,None
   LCPD-15725,,[Klokworks uboot] Resolve or indicate false positives on arch/arm/mach-omap2/emif-common.c,
   LCPD-15720,,[Klokworks uboot] Resolve or indicate false positives on drivers/dfu/dfu_ram.c,
   LCPD-15719,,[Klokworks uboot] Resolve or indicate false positives on arch/arm/mach-omap2/hwinit-common.c,
   LCPD-15711,,[Klokworks uboot] Resolve or indicate false positives on arch/arm/mach-omap2/omap5/sdram.c,
   LCPD-15710,,[Klokworks uboot] Resolve or indicate false positives on board/ti/common/board_detect.c,
   LCPD-15054,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm",[u-boot] AM57xx phy_ctrl structures must be board-specific,None
   LCPD-14843,"am654x-evm, am654x-idk",U-boot should support default settings for netboot,None
   LCPD-14638,"k2g-evm, k2g-ice",Invalid DDR_PHY_MR2 setting in K2G board library,None
   LCPD-10726,"am572x-idk, am57xx-evm",Update DDR3 emif regs structure for EMIF2 for the beagle_x15 board in U-Boot board file,None
   LCPD-9369,,AM437x GP EVM older PG version Uboot UART boot fails intermittently,
   LCPD-8701,k2g-ice,Soft reboot broken,
   LCPD-8295,"dra71x-evm, dra71x-hsevm, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm",vout1 pins missing manual i/o configuration,
   LCPD-7776,"dra7xx-evm, dra7xx-hsevm",U-boot: DRA7XX: secure boot fails on Rev-G J6 EVM,
   LCPD-18643,"am335x-evm, am335x-hsevm, am335x-ice, am335x-sk, am43xx-epos, am43xx-gpevm, am43xx-hsevm, am437x-idk, am437x-sk",U-Boot: AM335x/AM473x: Both SPI CS signals get asserted,
   LCPD-17789,j721e-idk-gw,UBOOT J7: Could not see UFS device by scsi scan,
   LCPD-16696,"am654x-evm, am654x-idk",U-Boot does not recognize SD-Card after re-insert/change,
   LCPD-15873,am654x-evm,There is no dtbo in u-boot for PCIe x1 + usb3 daughter card,None
   LCPD-12348,"dra71x-evm, dra72x-evm, dra76x-evm, dra7xx-evm",U-boot: MMC/SD: MMC erase fails with timeout,
   LCPD-11197,dra72x-evm,Uboot: Writing GPT partitions to emmc causing CACHE: Misaligned messages,
   LCPD-10668,k2g-evm,Ethernet boot: Sometimes the board could not boot uboot from Ethernet on k2g-evm,None
   LCPD-9539,k2g-evm,dhcp does not work after soft reboot,None
   LCPD-7864,"am335x-evm, am335x-ice, am335x-sk, am43xx-gpevm, am437x-idk, am437x-sk",U-Boot: Ethernet boot fails on AM335x and AM437x,
   LCPD-7547,k2g-evm,uboot nand write hangs for big size on k2g,
   LCPD-7366,am335x-evm,uboot McSPI driver drives multiple chip selects simultaneously,None
   LCPD-5517,AM572x,Board fails to load bootloader sometimes when eSATA is connected,None
   LCPD-5416,K2G,"U-BOOT: K2G: ""reset"" fails for certain SD cards",None
   LCPD-5116,AM335x,BBB: U-Boot: Board fails to acquire dhcp address sometimes,None
   LCPD-19848,j721e-idk-g,: Uboot UFS raw read write performance out of expected range,
   LCPD-19846,j721e-idk-gw, Uboot emmc raw read write performance is out of expected range,


|


Linux Kernel Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround" 
   :widths: 5, 10, 70, 35

   LCPD-19854,"j721e-evm, j721e-hsevm, j721e-evm-ivi, j721e-idk-gw",PCIe: EP: Low Throughput using DMA,
   LCPD-9877,omapl138-lcdk,rtc alarm does not wakeup board from poweroff state,
   LCPD-17471,"am654x-evm, am654x-idk",device hang when restarting crashed R5F,
   LCPD-19823,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm",ICSS PTP: Fix order of registering ICSS PTP,
   LCPD-19784,am654x-idk,DFU MMC test fails,
   LCPD-19497,j7200-evm,CPSW2g: interface goes up and down sporadically,Seen only on very few EVMs. No workaround.
   LCPD-9972,k2g-evm,Soft reboot failed on k2g-evm with class 10 SD cards,Do not use soft reboot
   LCPD-19046,j721e-idk-gw,Very low IPSEC throughput,
   LCPD-13653,"am654x-evm, am654x-idk",am65x-evm could not boot from MMC/SD when MMC/SD is backup boot mode,No workaround
   LCPD-19820,j721e-idk-gw,DP tests fail due to unexpected mode frequency,
   LCPD-13412,am57xx-evm,VIP camera sensor (mt9t11) is not initialized properly,
   LCPD-17373,"dra71x-hsevm, dra72x-hsevm, dra76x-hsevm, dra7xx-hsevm",ARM Exception from PPA Signature Verification Call on HS Device,"In our SDK solution OP-TEE replaces the Secure ROM. OP-TEE does not use the Crypto HWA so we let the kernel manage and disable/enable them as needed. If one would like to continue using the Secure ROM then, as you have figured out in the description, you need to add the Crypto HWAs to the list of non-hwmod controlled devices (like we do for TRNG and GPTIMER12 that OP-TEE does use). We cant do this by default as our default configuration is to let the kernel crypto driver use these devices."
   LCPD-16560,omapl138-lcdk,OMAPL-138 Resume from UART,
   LCPD-15695,,[Klokworks] Resolve or indicate false positives on drivers/clk/ti/clkctrl.c,
   LCPD-12784,omapl138-lcdk,Board can't resume from suspend state sometimes,
   LCPD-12273,dra7xx-evm,i2c controller timed out during DVFS,
   LCPD-10997,dra76x-evm,ABB voltage did not increase for 1800 MHz,
   LCPD-9527,"am335x-evm, am335x-sk, beaglebone, beaglebone-black",Potential deadlock reported by pm_suspend on am335x,
   LCPD-7323,dra72x-evm,Inconsistent resuts in power measurement during suspended mode,
   LCPD-7314,am335x-evm,Active power is slighly higher than on 2015 LTS release (Linux 4.1),
   LCPD-7256,"am335x-evm, am335x-hsevm, am57xx-evm, dra72x-evm, dra7xx-evm",Board sometimes hangs after suspend/resume cycle,
   LCPD-4870,DRA74x,"DRA74x EVM: suspend causes ""suspicious RCU usage""",
   LCPD-1245,am335x-evm,AM335x: Power: Reverse current leakage on poweroff,
   LCPD-1204,,AM335x - Some voltage rails remain active during poweroff,
   LCPD-965,,AM335x: Power: Poweroff is not shutting down voltage domains,
   LCPD-19781,"am654x-evm, am654x-idk, j721e-evm, j721e-hsevm, j721e-evm-ivi, j7200-evm, j7200-hsevm",OE: ti-rpmsg-char: Library header files and primary so file are missing in FS,
   LCPD-17284,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",remoteproc/k3-r5: Cores are started out-of-order when core 0 file size >> core 1 file size,
   LCPD-16877,k2hk-evm,ti-ipc-examples-linux intermittent build failure,
   LCPD-16545,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",remoteproc/k3-r5f: PDK IPC echo_test image fails to boot up in remoteproc mode on second run,
   LCPD-16535,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",remoteproc/k3-dsp: PDK IPC echo test binaries fails to do IPC in remoteproc mode on second run,
   LCPD-16534,"am654x-evm, am654x-idk",remoteproc/k3-r5f: PDK IPC echo_test image fails to do IPC in remoteproc mode on second run,None
   LCPD-19803,"am335x-evm, am335x-hsevm, am335x-ice, am335x-sk, am43xx-epos, am43xx-gpevm, am43xx-hsevm, am437x-idk, am437x-sk, am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm, am654x-evm, am654x-idk, am654x-hsevm, beaglebone, bbai, beaglebone-black",SDK GPIO documentation must be updated,
   LCPD-19785,am654x-idk,Uboot: usbhost has problem with detection,
   LCPD-19751,j721e-idk-gw,[ti:ti-linux-5.4.y 3067/10775] drivers/pci/endpoint/pci-epf-bus.c:36:34: warning: unused variable 'pci_epf_bus_id_table',
   LCPD-19733,"j7200-evm, j7200-hsevm",[ti:ti-rt-linux-5.4.y 3364/11241] drivers/pci/endpoint/functions/pci-epf-ntb.c:860 epf_ntb_init_epc_bar_interface() warn: unsigned 'barno' is never less than zero.,
   LCPD-19660,"am335x-ice, am437x-idk, am571x-idk, am572x-idk, am574x-idk",Remove unused definitions and related code for SV frame MAC address,
   LCPD-19519,"j721e-idk-gw, j7200-evm, j7200-hsevm",Kernel: RT Linux build error with SPI NOR hack to find the PHY pattern location,
   LCPD-19499,"j7200-evm, j7200-hsevm",Kernel: OSPI write throughput is less than 1MB/s,
   LCPD-19260,am571x-idk,PRUETH: Single EMAC doesn't ping with ICSS-1 Port 2 (MII-1),
   LCPD-19180,am654x-evm,AM65 PG1 fails to boot with MMC/SD,
   LCPD-18044,omapl138-lcdk,Seeing kernel oops when bring up USB Ethernet interface,
   LCPD-18020,dra72x-evm,fatwrite failed to write ipu firmware to boot partition on dra72,
   LCPD-17995,omapl138-lcdk,Failed to insert 'g_multi' on omapl138,
   LCPD-17908,"am654x-evm, am654x-idk",ICSSG: dual-emac: udp packets ocassionally sent out of order on egress,
   LCPD-17873,omapl138-lcdk,SATA delays resume time by 10+ seconds sometimes,
   LCPD-17814,j721e-idk-gw,Kingston 16G card could not boot to uboot prompt,
   LCPD-17800,"am654x-evm, am654x-idk",CPSW: Master/Slave resolution failed message seen at console,
   LCPD-17794,j721e-idk-gw,ext4write failed to write firmware to SD card,
   LCPD-17790,am335x-evm,AM335x: USB Device: 15% performance drop,
   LCPD-17421,j721e-idk-gw,CPSW9G: Can't bring up interface over NFS,
   LCPD-17172,j721e-idk-gw,Uboot USBhost: Sandisk Extreme USB 3.0 msc stick could not be detected at second time,
   LCPD-17171,j721e-idk-gw,Uboot dhcp occasionally failed,
   LCPD-17113,j721e-idk-gw,[Cpsw9g][VirtualDriver][VirtualMAC] rpmsg_kdrv_switch is not autoloaded,
   LCPD-16640,j721e-idk-gw,PCIe RC: GIC ITS misbehaves when more than 4 devices use it simultaneously,
   LCPD-16628,j721e-idk-gw,Could not enumerate PLEXTOR pcie SSD,
   LCPD-16594,dra7xx-evm,Seeing kernel traces during pcie wifi tests,
   LCPD-16591,j721e-idk-gw,PCIe wifi ping stress test failed,
   LCPD-16406,am654x-idk,"Seeing ""e1000#0: ERROR: Hardware Initialization Failed"" sometimes when do dhcp via pcie-eth",
   LCPD-16396,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",J721E: RC: Unsupported request in configuration completion packets results in an abort,"Workaround for Multifunction: Configure all the physical functions supported by the endpoint. For configuring all the 6 functions of PCIe controller instance '1' in J721E, the following can be used. mount -t configfs none /sys/kernel/config; cd /sys/kernel/config/pci_ep/; mkdir functions/pci_epf_test/func1; echo 0x104c > functions/pci_epf_test/func1/vendorid; echo 0xb00d > functions/pci_epf_test/func1/deviceid; echo 1 > functions/pci_epf_test/func1/msi_interrupts; echo 16 > functions/pci_epf_test/func1/msix_interrupts; ln -s functions/pci_epf_test/func1 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func2; echo 0x104c > functions/pci_epf_test/func2/vendorid; echo 0xb00d > functions/pci_epf_test/func2/deviceid; echo 1 > functions/pci_epf_test/func2/msi_interrupts; echo 16 > functions/pci_epf_test/func2/msix_interrupts; ln -s functions/pci_epf_test/func2 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func3; echo 0x104c > functions/pci_epf_test/func3/vendorid; echo 0xb00d > functions/pci_epf_test/func3/deviceid; echo 1 > functions/pci_epf_test/func3/msi_interrupts; echo 16 > functions/pci_epf_test/func3/msix_interrupts; ln -s functions/pci_epf_test/func3 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func4; echo 0x104c > functions/pci_epf_test/func4/vendorid; echo 0xb00d > functions/pci_epf_test/func4/deviceid; echo 1 > functions/pci_epf_test/func4/msi_interrupts; echo 16 > functions/pci_epf_test/func4/msix_interrupts; ln -s functions/pci_epf_test/func4 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func5; echo 0x104c > functions/pci_epf_test/func5/vendorid; echo 0xb00d > functions/pci_epf_test/func5/deviceid; echo 1 > functions/pci_epf_test/func5/msi_interrupts; echo 16 > functions/pci_epf_test/func5/msix_interrupts; ln -s functions/pci_epf_test/func5 controllers/d800000.pcie-ep/; mkdir functions/pci_epf_test/func6; echo 0x104c > functions/pci_epf_test/func6/vendorid; echo 0xb00d > functions/pci_epf_test/func6/deviceid; echo 1 > functions/pci_epf_test/func6/msi_interrupts; echo 16 > functions/pci_epf_test/func6/msix_interrupts; ln -s functions/pci_epf_test/func6 controllers/d800000.pcie-ep/; echo 1 > controllers/d800000.pcie-ep/start; echo 1 > /sys/bus/pci/devices/0000:00:00.0/remove; echo 1 > /sys/bus/pci/rescan; Workaround for switch card: No workarounds available."
   LCPD-16048,"am654x-evm, am654x-idk",UDP iperf with smaller packet sizes < 512 bytes does not complete consistently,
   LCPD-15887,omapl138-lcdk,The boot time increase ~30s on omapl138-lcdk,
   LCPD-15885,k2hk-evm,Uboot usb start trigger the board resetting with one usb stick,
   LCPD-15857,,Kernel Panic with Multiple PRUETH Ports,
   LCPD-15787,am335x-evm,Power suspend fails due to USB (scsi_bus_suspend) failure when HDD is in use,
   LCPD-15768,,RNDIS performance dropped in 2019 LTS,
   LCPD-15660,k2g-evm,pcie sata or usb drive no device node being created,
   LCPD-15649,am57xx-evm,Uboot: sata could not be detected,
   LCPD-15540,"am57xx-evm, am654x-evm, dra71x-evm, dra7xx-evm",uvc-gadget results in segmentation fault,
   LCPD-15461,dra7xx-evm,pcie usb failed to enumerate sometimes on dra7xx,
   LCPD-14961,k2g-ice,k2g-ice: Ethernet port Eth0 doesn't get IP address when Jumper J3 is not mounted,None
   LCPD-14855,"am335x-evm, am335x-ice, am335x-sk",omap_i2c_prepare_recovery() function can Lock System,
   LCPD-14183,am654x-idk,am654x-idk failed to login to kernel a few times (7/1000),
   LCPD-14171,"am57xx-evm, dra7xx-evm",Failed to read uboot from SD card 1/1000 times,
   LCPD-13938,"am654x-evm, dra71x-evm, dra7xx-evm, k2g-evm",PCIe EP read/write/copy test failed with larger sizes,
   LCPD-13936,am654x-evm,Uboot dhcp timeout 1 of 100 times,
   LCPD-13720,beaglebone-black,SPI DMA TX Mode Halts During Continuous 16/32/64 bit Transfers,
   LCPD-13603,am654x-evm,One board could not boot rootfs from more than one SDHC card,
   LCPD-13478,dra76x-evm,kexec fails on some setups,
   LCPD-13458,dra76x-evm,MCAN FIFO errors seen in receive CANFD tests,
   LCPD-13452,k2g-evm,USB Gadget Camera Capture - guvcview causes kernel oops,
   LCPD-13445,am654x-evm,Seldom kernel oops triggered by prueth_netdev_init,
   LCPD-12777,dra72x-evm,PCIe link is not up for Inateck pcie-usb card,
   LCPD-12718,dra7xx-evm,8250: serialcheck external loop back testing failure,
   LCPD-12673,omapl138-lcdk,Board refuses to suspend on setup with SATA device,
   LCPD-12423,dra72x-evm,PCIe fails to reach suspend target state sometimes,
   LCPD-12226,"am43xx-gpevm, am574x-idk, am57xx-evm, omapl138-lcdk",mmcsd first write perf decreased on some platforms,
   LCPD-11952,"am571x-idk, dra72x-evm",AM57x: disabling USB super-speed phy in DT causes kernel crash,
   LCPD-11564,am57xx-evm,AM57xx-evm: eth1 1G connection failure to netgear switch,
   LCPD-10974,am43xx-gpevm,am43xx-gpevm - usb camera gadget shows halting frames,None
   LCPD-10781,k2g-evm,NetCP module removal results in backtrace and kernel panic,
   LCPD-10777,omapl138-lcdk,mtd_stresstest failed on omapl138,
   LCPD-10707,"dra76x-evm, dra7xx-evm",Few PCIe cards could not enumerated on dra7xx and dra76x,
   LCPD-10551,k2e-evm,"K2E eth0 does down when running udp traffic, eth1 stops working",
   LCPD-10221,am335x-evm,Longer resume times observed on setup with usb device cable,
   LCPD-9974,am571x-idk,PCIe x2 width is not at expected width on am571x-idk,
   LCPD-9816,omapl138-lcdk,USBdevice omapl138 - Flood ping from server to dut usbdevice at 65500 bytes has packet loss,
   LCPD-9815,omapl138-lcdk,Failed to start Login Service when using debug systest build on omapl138,
   LCPD-9804,omapl138-lcdk,SATA performance decreased by ~34% for read and ~54% for write compared to v2.6.33 kernel,
   LCPD-9658,omapl138-lcdk,OMAP-L138 LCDK: MUSB does not enumerate mouse connected to Keyboard hub,
   LCPD-9591,,CONNECTIVITY: USB NCM gadget ping with packet sizes > 10000 fails,
   LCPD-9466,"am57xx-evm, dra7xx-evm",SATA PMP causes suspend failures,
   LCPD-9455,am335x-evm,Kernel Warning reported for a USB audio device when listing with pulseaudio,
   LCPD-9428,"k2e-evm, k2hk-evm, k2l-evm",Ethernet performace UDP: iperf command fails with two threads for lower buffer length,
   LCPD-9372,am335x-evm,Nand stress tests failed on a particular am335x-evm board,
   LCPD-9366,k2g-evm,PCIe USB drive sometimes could not be enumerated,
   LCPD-9027,"dra71x-evm, dra72x-evm, dra7xx-evm",There is some warning regarding spi_flash_read when do ubimkvol,
   LCPD-9011,k2g-evm,K2G-evm: usb devices do not enumerate behind a TUSB8041 usb3.0 hub,None
   LCPD-8984,"k2e-evm, k2l-evm",Kernel boot to initramfs with PA enabled results in no DHCP IP address assigned to network interfaces,
   LCPD-8637,,K2HK: Long-term ping test fails due to ethernet link going down,
   LCPD-8133,am335x-evm,"USB: ""cannot reset"" errors observed sometimes",
   LCPD-8100,k2g-evm,CONNECTIVITY: K2G ethernet performance numbers are low,
   LCPD-8033,,AM3 SK: Unexpected USB2-1 Messages on UART,
   LCPD-7955,"am335x-evm, am43xx-gpevm, k2e-evm, k2g-evm, k2g-ice, k2hk-evm, k2hk-hsevm, k2l-evm","Uncorrectable Bitflip errors seen after switch to SystemD,Workaround to erase the NAND flash completely if flashed with an incompatible flash writer. SystemD tries to mount all partitions and that is the reason this is being seen now"
   LCPD-7829,am57xx-evm,uboot: UHS card did not work on the expected speed in uboot,
   LCPD-7744,am57xx-evm,UHS SDR104 card works on different speed after soft reboot,
   LCPD-7623,k2hk-evm,Seeing SPI transfer failed error sometimes on k2hk when using rt kernel,
   LCPD-7575,dra72x-evm,PCIe-USB card sometime could not be detected,
   LCPD-7559,"k2e-evm, k2hk-evm",K2E/K2HK does not enumerate usb3 devices through usb3.0 hub,
   LCPD-7374,"dra72x-evm, dra7xx-evm",DRA7x: Transcend 16G UHS card enumerated as SDR104 but there are errors showing up,
   LCPD-7265,am57xx-evm,Uboot eMMC does not use HS200 on am57xx-gpevm,
   LCPD-7147,"dra72x-evm, dra7xx-evm",Intel LAN Card D33745 could not enumerated on J6,
   LCPD-7065,"dra72x-evm, dra7xx-evm",PCIe-sata: Samsung SSD 120G harddisk could not enumerated,
   LCPD-6334,k2g-evm,k2g-evm: NAND is untestable due to data corruption issues,
   LCPD-6301,"dra72x-evm, dra7xx-evm",J6: A few SDR104 cards only enumerated as high speed card when use them as rootfs,
   LCPD-6300,am57xx-evm,am57xx-evm: A few UHS cards could not be numerated in kernel and mmc as rootfs failed.,
   LCPD-6120,dra7xx-evm,Ethernet Link not stable at 1G on Rev G DRA74x EVMs,
   LCPD-5699,"AM571x, AM572x",pci: am572x-idk: pci broadcom card doesn't enumerate,
   LCPD-5677,K2E,K2E-evm: Marvel SATA controller could not be detected sometimes when Power On Reset is involved,
   LCPD-5566,"DRA72x, DRA74x",Suspend failed when running pcie-usb test,
   LCPD-5522,"am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm",pcie-usb sometimes the usb drive/stick could not be enumerated,
   LCPD-5362,am335x-evm,MUSB: Isoch IN only utilises 50% bandwidth,
   LCPD-4849,,K2hk: Connectivity: UART data corruption observed sometimes in loopback mode,
   LCPD-4503,dra7xx-evm,ALL: 8250 UART driver not enabeld as wake source by default,
   LCPD-1239,"am572x-idk, am57xx-evm, dra72x-evm, dra7xx-evm",Connectivity: DUT could not resume when PCI-SATA card is in,
   LCPD-1198,,"am43xx-gpevm:Connectivity: when kmemleak debug is enabled and mmc stress test is run, OOM killer is seen to kick in. Does not happen without kernel debug.",
   LCPD-1144,,Logitech USB-PS/2 Optical Mouse cannot be detected every other time the system is suspended/resumed (AM335x-EVM),
   LCPD-1106,"am57xx-evm, dra71x-evm, dra71x-hsevm, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm",Connectivity:PCIe-SATA ext2 1G write performance is poor due to ata failed command,None
   LCPD-932,,AM33X: CONNECTIVITY: MUSB MSC read numbers are lower in 3.14 compared to 3.12,
   LCPD-885,dra7xx-evm,J6/J6eco: suspend-to-ram: l3init: USB clocks are active,
   LCPD-869,,AM335x: Connectivity: USB data transfer fails if board is suspended/resumed,
   LCPD-816,"dra72x-evm, dra7xx-evm",J6/J6eco:Connectivity:PCIe-PCI eth bridge doesn't work on J6/J6eco,
   LCPD-799,dra7xx-evm,J6 and J6ECO: CONNECTIVITY: Backtrace during disconnect of usb camera during iso transaction,
   LCPD-662,,CONNECTIVITY: AM335X: distortion in USB audio when msc connect/disconnect happens in parallel,
   LCPD-19800,j7200-evm,tisci_sysreset_request blocks boot for several tests,
   LCPD-19757,am335x-evm,OpenSSL DES performance numbers are lower in 07.01,
   LCPD-19723,j7200-evm,RTI watchdog test fails on J7VCL E5 SOM,
   LCPD-17782,,INTRTR: Spurious interrupts generated when programming certain Interrupt Routers,
   LCPD-17780,"am654x-evm, j721e-idk-gw",Mbox timedout in resp,
   LCPD-17777,am654x-evm,AES HW is not exercised,
   LCPD-17673,"am335x-evm, am43xx-gpevm, am571x-idk, am572x-idk, am574x-idk, am57xx-evm, am654x-evm, beaglebone-black, dra71x-evm, dra72x-evm, dra7xx-evm, j721e-evm",No software documentation for the Timer module,
   LCPD-17543,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",Some cpuhotplug tests failed,
   LCPD-17418,j721e-idk-gw,J7 sometimes failed to boot,Flash firmware into mmc rootfs
   LCPD-17403,"j721e-evm-ivi, j721e-idk-gw",PAT: DMA-API warning,
   LCPD-16845,"am654x-evm, am654x-idk",OPP freq update in DT impacts only cluster0,
   LCPD-16505,j721e-evm,"Wrong clock rate is reported for 157:400, 157:401 (HSDIVIDER after PLL4 and 15)",
   LCPD-14191,"am335x-evm, am57xx-evm",IPSec hardware-based throughput is 30% lower than 2018.03,
   LCPD-13410,"am654x-evm, am654x-idk",Reboot command is not operational,
   LCPD-10158,,Matrix power demos fails on DRA71x platform,
   LCPD-9981,"j721e-vlab, omapl138-lcdk",Some LTP's memory management tests fail due to low amount of free memory,
   LCPD-9980,omapl138-lcdk,LTP's math tests float_exp_log and float_trigo fail due to OOM,
   LCPD-9756,omapl138-lcdk,"pm_runtime does not kicks in for some IPs (serial, gpio and wdt)",
   LCPD-9427,dra71x-evm,vip error logs during gst-capture-encode testcases,
   LCPD-8406,"k2g-evm, k2g-ice",K2G: PADCONFIG_202 register cannot be re-programmed,This has proven to be a silicon issue related to locking RSTMUX. It is currently being discussed if it will be fixed in a newer silicon revision. Currently to avoid this issue the affected pins pinmux are not changed in the kernel. This is because U-boot locks RSTMUX which causes problems if the kernel tries to change the pinmuxing for the pins.
   LCPD-8350,am57xx-evm,UART boot does not work on am57xx-evm,
   LCPD-8347,"k2e-evm, k2g-evm",BUG: sleeping function called from invalid context triggered by keystone_pcie_fault,
   LCPD-8336,am43xx-hsevm,Soft reboot does not work on am43xx-hsevm rev1.5b,
   LCPD-8257,k2g-evm,Boot failed 1 of 1000 times on k2g,
   LCPD-7293,dra7xx-evm,[rpmsg 2016 LTS] ALL: iommu/remoteproc: _wait_target_disable failed trace,
   LCPD-6998,k2g-evm,K2G sometimes boot failed with kernel oops error,None
   LCPD-6663,,[RT] Kmemleak is buggy and boot is crashed randomly,
   LCPD-19068,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",DSS: Disabling a layer connected to Overlay may result in synclost during the next frame,
   LCPD-17387,"j721e-evm-ivi, j721e-idk-gw",Underflow and CRTC SYNC LOST observed while running GLMark2 (1x1080p + 1x4k),
   LCPD-17017,"j721e-evm-ivi, j721e-idk-gw",J7: DSS underflows seen on various use cases,
   LCPD-17006,j721e-evm,4k DP Display Shows Blank Screen sometimes when booting,
   LCPD-16836,j721e-idk-gw,DP: GeChic display EDID read failures with custom DP cable,
   LCPD-16642,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm, dra71x-evm, dra71x-hsevm, dra72x-evm, dra72x-hsevm, dra76x-evm, dra76x-hsevm, dra7xx-evm, dra7xx-hsevm","omapdrm: in some cases, DPI output width does not need to be divisible by 8",
   LCPD-16616,"j721e-evm, j721e-evm-ivi, j721e-idk-gw",Jailhouse: Failure in mhdp probe while restarting the Linux VM,
   LCPD-16454,j721e-evm,DSS underflows with 1080p/2.5k display on inmate cell,
   LCPD-16451,j721e-evm,"DP: if cable is not connected, DPCD transactions mess up the driver",
   LCPD-16208,j721e-evm,FIFO Underflows during video playback on 4k panel,
   LCPD-15819,am654x-evm,"tidss: the driver should reject dual-display setup, as it is not supported",
   LCPD-15518,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm, dra71x-evm, dra71x-hsevm, dra72x-evm, dra72x-hsevm, dra76x-evm, dra76x-hsevm, dra7xx-evm, dra7xx-hsevm",omapdrm: WB M2M: Headless mode is not working,
   LCPD-12680,k2g-evm,Seeing i2c timeout error and board failed to boot,
   LCPD-11138,"am571x-idk, am572x-idk, am574x-idk, am574x-hsidk, am57xx-evm, am57xx-beagle-x15, am57xx-hsevm, dra7, dra71x-evm, dra71x-hsevm, dra72x-evm, dra72x-hsevm, dra76x-evm, dra76x-hsevm, dra7xx-evm, dra7xx-hsevm",VIP driver multi-channel capture issue with TVP5158,
   LCPD-9402,dra72x-evm,DRA72x: HDMI display EDID read fails on Rev B EVM,Add the required HDMI modes into the kernel binary as per instructions in http://lxr.free-electrons.com/source/Documentation/EDID/
   LCPD-9284,dra7xx-evm,DRA7xx: HDMI starting with non-preferred mode on boot,
   LCPD-8550,am335x-sk,CPSW memory allocation errors seen during boot,
   LCPD-8078,am335x-sk,AM3 SK: Touchscreen isn't responsive,
   LCPD-7735,"am57xx-evm, dra71x-evm, dra71x-hsevm, dra72x-evm, dra7xx-evm",Powerdomain (vpe_pwrdm) didn't enter target state 0,
   LCPD-7696,"am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm, dra71x-evm, dra71x-hsevm, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm",DRA7xx: VPE: File2File checksum changes across multiple runs,There is no workaround for this issue yet
   LCPD-7695,dra7xx-evm,DRA7xx: building Ov1603x as a module causes a green tint in captured image,"The workround is to use the camera driver as builtin. Also, a delay of 1s can stop this issue from occuring"
   LCPD-5380,AM572x,omapdss error: HDMI I2C Master Error,Occurs only with this monitor - http://www.amazon.com/gp/product/B00PFLZV2G
   LCPD-1191,am335x-evm,AM335x: Power: System resumes due to wakeup source USB1_PHY without any external trigger,Use GPIO interrupt instead of USB PHY for wakeup source.
   LCPD-1013,,AM335x: Power: Seldom short-duration power increase (~38mw) in VDDSHV4 domain,
   LCPD-19216,k2e-evm,K2E PCIe is not enumerated when EVM boots up cold,
   LCPD-16437,am335x-evm,Nand with prefetch dma: read perf drop ~20% comparing to 2018,
   LCPD-15648,am335x-evm,Uboot mmc write performance decreased,
   LCPD-15635,dra71x-evm,mmc hotplug causes one board reboot,
   LCPD-12392,am335x-evm,USBhost video: higher resolution tests fail with some cameras,
   LCPD-11570,k2g-evm,Base ubi filesystem could not be mounted as ubifs on k2g-evm,
   LCPD-9589,am335x-evm,I2C: Sometimes i2c read write failed on farm01 and farm02,
   LCPD-9222,am572x-idk,PRUSS Ethernet does not work on AM572x ES1.1,
   LCPD-8636,"am335x-evm, dra72x-evm, dra7xx-evm",Serial corruption being seen in kernel,
   LCPD-8477,"k2e-evm, k2e-hsevm, k2g-evm, k2g-ice, k2hk-evm, k2hk-hsevm, k2l-evm, k2l-hsevm",K2: serdes nodes doesn't have a functional clock,
   LCPD-8270,k2g-evm,K2: SerDes driver need to enable PD of the peripheral before access the SerDes h/w,
   LCPD-7998,am572x-idk,Realtime OSADL Test results degraded slightly for am572x-idk,
   LCPD-7903,"k2g-evm, k2hk-evm",Uboot phy startup failed and dhcp failed occasionally on k2 board,
   LCPD-7705,"dra7xx-evm, dra7xx-hsevm",DRA7X: SATA: specific Port multiplier (JMicron) connected to dra7x enumerates at 1.5Gbps,None
   LCPD-7480,"k2e-evm, k2l-evm",K2L/E EVMs doesn't boot to Linux when both 1G Ethernet interfaces are connected,
   LCPD-7188,"am57xx-evm, dra72x-evm, dra7xx-evm",PCIe-SATA test failed,TI custom board would help with signal integrity issues being seen with the EVM.
   LCPD-1207,"am43xx-gpevm, am57xx-evm, dra7xx-evm",AM43XX/AM57XX/DRA7: CONNECTIVITY: dwc3_omap on am43xx and xhci_plat_hcd on dra7 - removal results in segmentation fault,
   LCPD-1067,"dra71x-evm, dra71x-hsevm, dra72x-evm, dra72x-hsevm, dra7xx-evm, dra7xx-hsevm",J6: PCIe: Broadcom Ethernet cards cause kernel to hang after suspend/resume cycle,
   LCPD-998,AM335x,MUSB does not free urbs causing usb audio playback to fail,
   LCPD-727,,J6:Connectivity:SATA readwrite tests sometimes fail and dut hangs with cpuidle enabled,
   LCPD-671,,AM33XX: CONNECTIVITY: MUSB in PIO mode - video issues,
   LCPD-525,,AM438x: Connectivity: I2C operates 9% beyond desired frequency,
   LCPD-10223,k2hk-evm,Keystone-2 Linking RAM region 0 size register REGION0_SIZE programming,
   LCPD-5521,dra7xx-evm,Sporadic boot failure using debug image (~ 1/50),
   LCPD-8000,"dra7xx-evm, dra7xx-hsevm",VIP: RGB: RGB capture error due to wrong data path setting,
   LCPD-7697,"dra7xx-evm, dra7xx-hsevm",OV1063x configuration breaks if kernel is compiled with CONFIG_DEBUG_GPIO=n,Enable the CONFIG_DEBUG_GPIO
   LCPD-15402,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15, dra71x-evm, dra72x-evm, dra76x-evm, dra7xx-evm",rpmsg-rpc: test application does not bail out gracefully upon error recovery,
   LCPD-15400,"am571x-idk, am572x-idk, am574x-idk, am57xx-evm, am57xx-beagle-x15, dra71x-evm, dra72x-evm, dra76x-evm, dra7xx-evm",remoteproc/omap: System suspend fails for IPU1 domain without any remoteprocs loaded,
   LCPD-10455,"k2g-evm, k2g-ice, k2hk-evm, k2l-evm",remoteproc/keystone: Hang observed while running RPMSG_PROTO example app,
   LCPD-9801,omapl138-lcdk,remoteproc/davinci: DSP boot is broken after a suspend/resume cycle,
   LCPD-9481,"am571x-idk, am572x-idk, am57xx-evm, am57xx-hsevm",Sometime the system hangs while loading the rpmsg rpc modules,
   LCPD-7495,k2hk-evm,Sometimes a Kernel Warning + Oops is seen when removing keystone_remoteproc module,
   LCPD-4855,"am572x-idk, dra72x-evm",[rpmsg 2015 LTS] J6Eco: IPC: Board hangs when an MMU fault occurs in the first message,
   LCPD-4699,"am571x-idk, am572x-idk, am57xx-evm, dra72x-evm, dra7xx-evm",[rpmsg 2015 LTS] rpmsg-rpc: kernel crash during error recovery with dynamic debug traces enabled,
   LCPD-1027,dra72x-evm,[rpmsg 2014 LTS] J6Eco: IPC: Board hangs when an MMU fault occurs in the first message,
   LCPD-19862,j7200-evm,USB SuperSpeed enumeration not working on j7200e,
   LCPD-19861,am654x-evm,Unregistered multicast MAC packets are still visible in non-promiscuous mode,
   LCPD-19859,am654x-evm,ETH ICSSG netperf benchmark returns lower performance than expected,
   LCPD-19818,j721e-idk-gw,CPSW2G netperf egress performance lower,
   LCPD-19792,j721e-idk-gw,j721e boot fails sometimes due to EL1 exception,
   LCPD-6075,"am572x-idk, am57xx-evm, dra7xx-evm",BUG: using smp_processor_id() in preemptible [00000000] code during remoteproc suspend/resume,

