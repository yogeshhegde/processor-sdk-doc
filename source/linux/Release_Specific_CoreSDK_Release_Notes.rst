************************************
Release Notes
************************************
.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Release_Notes

Overview
========

The **Processor-CoreSDK for Linux**
provides a fundamental software platform for development, deployment and
execution of Linux based applications and includes the following:

  * Bootloaders & Filesystems.
  * Prebuilt Binaries.
  * Detailed Release Notes.

Licensing
=========

Please refer to the software manifest, which outlines the licensing
status for all packages included in the prebuilt binaries location.

Release 09.01.00 Refresh 3
==========================
Released December 2023

.. rubric:: What's New
   :name: whats-new

**Processor SDK 9.1 Sitara Release supports the following platforms**
  * AM65x (GP, HS)

**Processor SDK 9.1 Sitara Release has following Major Updates**

  * LTS Refresh with Stable Kernel 6.1, U-boot 2023.04, Yocto Dunfell 4.0

Release 09.00.00 Refresh 2
==========================
Released October 2023

.. rubric:: What's New
   :name: whats-new

**Processor SDK 9.0 Sitara Release supports the following platforms**
  * AM335x (GP, HS), AM437x (GP, HS)

**Processor SDK 9.0 Sitara Release has following Major Updates**

  * LTS Refresh with Stable Kernel 6.1, U-boot 2023.04, Yocto Dunfell 4.0


Release 09.00.00 Refresh 1
==========================

Released October 2023

.. rubric:: What's New
   :name: whats-new

**Processor SDK 9.0 Sitara Release supports the following platforms**

  * AM62SIP 2.0 (HS-FS, HS-SE)

**Processor SDK 9.0 Sitara Release has following Major Updates**

  * LTS Refresh with Stable Kernel 6.1, U-boot 2023.04, Yocto Dunfell 4.0
  * Binman Migration
  * HS-FS Default Boot Experience
  * Graphics: Weston 10 and DDK 23.1 Upgrade
  * Multimedia: Gstreamer v1.20.5 Upgrade


Release 09.01.00
==================

Released December 2023

.. rubric:: What's New
   :name: whats-new

**Processor SDK 9.1 Sitara Release supports the following platforms**

  * tag: 09.01.00.007
  * AM65x 2.0 (GP, HS) 

**Processor SDK 9.1 Sitara Release has following Major Updates**

  * LTS Refresh with Stable Kernel 6.1, U-boot 2023.04, Yocto Dunfell 4.0
  * OPTEE 4.0, ATF 2.9+
  * Graphics: DDK 1.17 with 6.1 Kernel Upgrade
  * Bug Fixes and Stability Improvements  

Release 09.00.00
==================

Released July 2023

.. rubric:: What's New
   :name: whats-new

**Processor SDK 9.0 Sitara Release supports the following platforms**

  * AM64x 2.0 (HS-FS)
  * AM62x (GP, HS-FS, HS-SE)
  * AM62x LP (HS-FS, HS-SE)
  * AM62A (HS-FS, HS-SE)

**Processor SDK 9.0 Sitara Release has following Major Updates**

  * LTS Refresh with Stable Kernel 6.1, U-boot 2023.04, Yocto Dunfell 4.0
  * Binman Migration
  * HS-FS Default Boot Experience for AM64, AM62, AM62A, AM62 LP
  * Graphics: Weston 10 and DDK 23.1 Upgrade
  * Multimedia: Gstreamer v1.20.5 Upgrade

**AM62A**

  * U-Boot: Remoteproc boot with C7x
  * Kernel: E5010 JPEG Encoder
  * Low Power: DFS and CPUIdle on HS FS
  * Camera: V4L2 multi-stream controls

**AM62**

  * Uboot: A53 Early splash screen and bmp display
  * Low Power: Deep Sleep mode: HS FS Support, Main IO Daisychain support, Remoteproc with M4 and R5 Cores
  * Low Power: Wakeup Sources: MCU GPIO, Main I/O Daisy wakeup, MCU M4 IPC Wakeup
  * Low Power: DFS and CPUIdle on HS FS
  * Low Power: MCU Only mode
  * Kernel: Multi MCAN
  * IPC: A53 --> DM R5
  * Camera: Libcamera support
  * Audio: Recording bug-fixes

**AM64**

  * Bug Fixes and Stability Improvements
  * PRU-ICSSG: HSR Port-to-Port offload , Switch Mode, Multicast filtering in EMAC mode, Tx/Rx coalescing and Dump IET Statistic via ethtool

**AM65**

  * PRU-ICSSG: Multicast filtering in EMAC mode, Tx/Rx coalescing and Dump IET Statistic via ethtool


Build Information
=====================================

U-Boot
-------------------------
| Head Commit: c1c2bdf272561724f531fe8e7a649ef687d1a67e board: ti: am62x/am62ax: Update MCU GPIO interrupt allocation in board config
| Date: 2023-12-01 08:20:03 -0600
| uBoot Version: 2023.04
| uBoot Description: 09.01.00.007
| Clone: git://git.ti.com/ti-u-boot/ti-u-boot.git
| Branch: ti-u-boot-2023.04
| uBoot Tag: 09.01.00.007
|


Kernel
-------------------------
.. rubric:: Linux Kernel
   :name: linux-kernel

| Head Commit: 5da2f861d7d06b97ea386294469e1644b18666fc arm64: dts: ti: k3-am62p: add dll delay mapping for MMC1/MMC2
| Date: 2023-12-01 08:19:54 -0600
| Kernel Version: 6.1.46
| Kernel Description: 09.01.00.007

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-linux-6.1.y
| Tag: 09.01.00.007
| use-kernel-config=defconfig
| config-fragment=kernel/configs/ti_arm64_prune.config
|


.. rubric:: Real Time (RT) Linux Kernel
   :name: real-time-rt-linux-kernel

| Head Commit: b4f1767f9ebaadcb85e2b10eadc5b168a2a7cdb4 Merge branch 'ti-linux-6.1.y-cicd' into ti-rt-linux-6.1.y-cicd
| Date: 2023-12-01 08:19:57 -0600
| Kernel Version: 6.1.46-rt13
| Kernel Description: 09.01.00.007-rt

| Repo: git://git.ti.com/ti-linux-kernel/ti-linux-kernel.git
| Branch: ti-rt-linux-6.1.y
| Tag: 09.01.00.007-rt
| use-kernel-config=defconfig
| config-fragment=config-fragment=kernel/configs/ti_arm64_prune.config kernel/configs/ti_rt.config
|



Yocto
------------------------
.. rubric:: meta-ti
   :name: meta-ti

| Head Commit: 30d69054de6902a65d22e8e8da149099ddc0573f CI/CD Auto-Merger: cicd.kirkstone.202311301712
| Date: 2023-12-01 08:20:04 -0600

| Clone: git://git.yoctoproject.org/meta-ti
| Branch: kirkstone
| Release Tag: 09.01.00.007
|

.. rubric:: meta-arago
   :name: meta-arago

| Head Commit: ec4e55b66242388a4d7e91544e6b084409af97dd CI/CD Auto-Merger: cicd.kirkstone.202311301712
| Date: 2023-12-01 08:19:42 -0600

| Clone: git://git.yoctoproject.org/meta-arago
| Branch: kirkstone
| Release Tag: 09.01.00.007
|

Issues Tracker
=====================================

Errata Workarounds Available in this Release
------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 30, 150

   "LCPD-22905","UDMA: TR15 hangs if ICNT0 is less than 64 bytes","am654x-evm,j721e-idk-gw"
   "LCPD-19965","OSPI PHY Controller Bug Affecting Read Transactions","am654x-idk,am64xx-evm,j721e-idk-gw,j7200-evm"
   "LCPD-19447","DSS: Disabling a layer connected to Overlay may result in synclost during the next frame","am654x-evm,am654x-idk"
   "LCPD-18979","MCAN: Message Transmitted with Wrong Arbitration and Control Fields (Early Start of Frame)","am654x-idk"
   "LCPD-17788","PCI-Express: GEN3 (8GT/s) Operation Not Supported.","am654x-evm,am654x-idk"
   "LCPD-17783","USB: USB2PHY Charger Detect is enabled by default without VBUS presence","am654x-evm,am654x-idk"
   "LCPD-14579","DSS : DSS Does Not Support YUV Pixel Data Formats","am654x-evm,am654x-idk"
   "LCPD-14184","USB:  SuperSpeed USB Non-Functional","am654x-evm"


|


U-Boot Known Issues
------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 15, 30, 70, 30

   "LCPD-28436","am654x-idk","AM65x Uboot PRUETH is broken",""
   "LCPD-24717","am654x-evm,am654x-idk","am654: PCI-E ethernet interface shows link down in U-Boot",""
   "LCPD-24628","am654x-evm,am654x-idk","am654x-idk DFU boot is failing",""
   "LCPD-17770","am654x-evm,am654x-idk,am654x-hsevm","U-Boot: Fix order of MCU R5 shutdown depending on cluster mode",""
   "LCPD-16696","am654x-evm,am654x-idk","U-Boot does not recognize SD-Card after re-insert/change",""
   "LCPD-16524","am654x-evm,am654x-idk,am654x-hsevm","Need to adjust RMW bit when using enabling ECC","None"
   "LCPD-14843","am654x-evm,am654x-idk","U-boot should support  default settings for netboot ","None"


|

Linux Known Issues
---------------------------
.. csv-table::
   :header: "Record ID", "Platform", "Title", "Workaround"
   :widths: 5, 10, 70, 35

   "LCPD-36622","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm","Errata i2028: USB3.0 Host and Device Non-Functional",""
   "LCPD-32868","am654x-idk,am64xx-evm","Kernel crash from PRU auto-forwarding packet",""
   "LCPD-24718","am654x-evm,am654x-idk","am654x hwspinlock test failing",""
   "LCPD-24541","am654x-evm","am65xx OSPI boot does not work",""
   "LCPD-24537","am654x-evm,am64xx-evm,am64xx-hsevm","am654x-idk nslookup times out when all netwokring interfaces are active",""
   "LCPD-24456","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,am62xx-sk,am64xx_sk-fs,beaglebone,bbai,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm,j721e-hsevm,j721e-idk-gw,j721e-sk,j721s2-evm,j721s2-hsevm,j721s2_evm-fs,j7200-evm,j7200-hsevm,omapl138-lcdk","Move IPC validation source from github to git.ti.com",""
   "LCPD-24319","am654x-evm","am654x-evm DRM tests fail due to frequency mismatch (Impact 7)",""
   "LCPD-24134","am654x-evm","AM654x CAL DMABUF tests fail (Impact 4.0)",""
   "LCPD-24130","am654x-evm","AM654x: USB MSC boot mode fails",""
   "LCPD-24128","am654x-idk","Performance issues with CPSW/ICSSG Linux Driver",""
   "LCPD-23008","am654x-evm","AM65xx - display port scenario not enabled",""
   "LCPD-23007","am654x-evm","k3-am654-evm-hdmi.dtbo file is missing in CoreSDK for am654x",""
   "LCPD-22959","am654x-evm","UART Read/Write tests at baud rate 115200 fails",""
   "LCPD-22947","am654x-evm","Alsa performance test fails [waiting for TF]",""
   "LCPD-22892","am654x-evm,am654x-idk,am64xx-evm","icssg: due to FW bug both interfaces has to be loaded always",""
   "LCPD-22324","am654x-idk","ICSSG port does not drop packets with SA matching interface MAC",""
   "LCPD-20014","am654x-evm,am654x-idk,am654x-hsevm","remoteproc: TX_PRU: IRQ vring, IRQ kick not found error message on console",""
   "LCPD-19580","am654x-evm","am654- unable to select a mode (sdhci?)",""
   "LCPD-18665","am654x-evm,am654x-idk","Am65x Pg2: Board cannot do soft reboot when booting from SD card",""
   "LCPD-18297","am654x-evm","AM6: OV5640: 176x144 does not work",""
   "LCPD-17673","am654x-evm,am335x-evm,am43xx-gpevm,am571x-idk,am572x-idk,am574x-idk,am57xx-evm,beaglebone-black,dra71x-evm,dra72x-evm,dra7xx-evm,j721e-evm","No software documentation for the Timer module",""
   "LCPD-17449","am654x-evm,am654x-idk,am654x-hsevm,am335x-evm,am335x-hsevm,am335x-ice,am335x-sk,am43xx-epos,am43xx-gpevm,am43xx-hsevm,am437x-idk,am437x-sk,am571x-idk,am572x-idk,am574x-idk,am574x-hsidk,am57xx-evm,am57xx-beagle-x15,am57xx-hsevm,beaglebone,beaglebone-black,dra71x-evm,dra71x-hsevm,dra72x-evm,dra72x-hsevm,dra76x-evm,dra76x-hsevm,dra7xx-evm,dra7xx-hsevm","libasan_preinit.o is missing in devkit",""
   "LCPD-16534","am654x-evm,am654x-idk","remoteproc/k3-r5f: PDK IPC echo_test image fails to do IPC in remoteproc mode on second run","None"


|

Issues opened in previous releases that were closed on this release
---------------------------------------------------------------------

.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-29872","PTP Time Synchronization needs to be restarted after link downs","am654x-evm,am654x-idk"
   "LCPD-29635","PCIe: x2 lane configuration is non functional","am654x-idk"
   "LCPD-29588","CPSW documentation: Time Sync Router no longer firewalled","am654x-evm,am654x-idk,am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-lp-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-29580","ICSSG IET Statistics are not getting counted","am654x-evm,am654x-idk,am64xx-evm"
   "LCPD-29446","Linux SDK docs should explicitly state what peripherals are supported","am654x-evm,am654x-idk,am64xx-evm,am62xx_sk-fs,am62xx_sk-se,am335x-evm,am335x-ice,am335x-sk,am43xx-gpevm,am437x-idk,am437x-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-29397","AM65x Linux SDK lists unsupported industrial protocols","am654x-evm,am654x-idk"
   "LCPD-28492","AM65: ICSSG: phc_ctl: Seeing clock jumps in get","am654x-evm,am64xx-evm"
   "LCPD-28107","Upstream: Broken USB boot modes on AM654","am654x-idk"
   "LCPD-25526","rproc_get() failure on certain race conditions","am654x-idk"
   "LCPD-25314","ICSSG: Timestamp for back-to-back with IPG < 100us not received","am654x-evm,am654x-idk,am654x-hsevm"
   "LCPD-25276","Kernel warning with panel_simple probe","am654x-evm,am654x-idk"
   "LCPD-24199","AM654x UART HWFLOW FUNC, PERF, STRESS tests fail (Impact 2)","am654x-evm"
   "LCPD-24127","AM654x IPSEC Software Crypto tests fail (Impact 4)","am654x-evm,j721e-idk-gw"
   "LCPD-22931","RemoteProc documentation missing","am654x-evm,am654x-idk,am64xx-evm,am64xx_sk-fs"
   "LCPD-22829","Convert toshiba,tc358767.txt:  ""toshiba,tc358767"" to yaml","am654x-evm,am654x-idk"
   "LCPD-22423","Removing FixMe and TODO from ICSSG Driver code","am654x-idk"
   "LCPD-20686","am65xx mainline build with dunfell is missing rproc test images","am654x-evm"
   "LCPD-19861","ICSSG: Unregistered multicast MAC packets are still visible in non-promiscuous mode","am654x-evm"
   "LCPD-19859","ETH ICSSG netperf benchmark returns lower performance than expected","am654x-evm"
   "LCPD-19177","u-boot:pytest: test_efi_helloworld_net failed on am6 and J7","am654x-evm,j721e-idk-gw"
   "LCPD-18788","Uboot: Could not bring up PCIe interface","am654x-idk"
   "LCPD-18627","uboot does not read the reserve-memory from the fdt ","am654x-idk"
   "LCPD-18289","pcie-usb tests sometimes fail","am654x-evm,k2g-evm"
   "LCPD-18258","IPSEC perfomance failures","am654x-evm,j721e-idk-gw"
   "LCPD-17798","2020 LTS: INTA/INTR smp_affinity failure and IRQ allocation issues.","am654x-evm,am654x-idk,j7am-evm,j721e-evm,j721e-hsevm,j721e-evm-ivi,j721e-idk-gw,j721e-vlab,j7200-evm,j7200-hsevm"
   "LCPD-16406","Seeing ""e1000#0: ERROR: Hardware Initialization Failed"" sometimes when do dhcp via pcie-eth","am654x-idk"
   "LCPD-15873","There is no dtbo in u-boot for PCIe x1 + usb3 daughter card","am654x-evm"
   "LCPD-14843","U-boot should support  default settings for netboot ","am654x-evm,am654x-idk"



|


Issues found and closed on this release that may be applicable to prior releases
-----------------------------------------------------------------------------------
.. csv-table::
   :header: "Record ID", "Title", "Platform"
   :widths: 15, 70, 20

   "LCPD-36968","am65x/debug: Display breaks with sysfw","am654x-evm,am654x-idk,am654x-hsevm"
   "LCPD-36947","AM65: eMMC/MMC tests fail","am654x-evm,am654x-idk"
   "LCPD-36914","am654: ICSSG Performance degradation","am654x-idk"
   "LCPD-36612","TMDX654IDKEVM: Clock jump of PTP device for ICSSG #2","am654x-idk"
   "LCPD-36578","AM65: USB hub on the daughter card does not work OOB ","am654x-evm,am654x-idk"
   "LCPD-36549","ICSSG: Ping to bridge not working in switch mode","am654x-idk,am64xx-hsevm"
   "LCPD-36517","TCP Performance Failure","am654x-idk"
   "LCPD-36510","BitBake Network Connectivity Check","am654x-hsevm"
   "LCPD-36403","Rx Stall during Uboot in presence of Broadcast Traffic","am654x-evm,am654x-idk"
   "LCPD-36325","MMC Error Getting Device Node","am654x-idk,j784s4-evm"
   "LCPD-34852","Few times payload is packed at size boundary by binman ","am654x-evm,am64xx-evm,am62xx_sk-se,j721e-idk-gw,j721s2-evm,j7200-evm"
   "LCPD-34593","DISTRO BOOT: Not enabled on all Sitara Platforms","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am62xx_sk-fs,beagleplay-gp,am62axx_sk-fs,am62xx-sk"
   "LCPD-34531","AM62a: eMMC LTP tests failure","am654x-evm,am62axx_sk-fs"
   "LCPD-34520","AM65: USB and PCIE DT overlays doesnt exist","am654x-evm,am654x-idk"
   "LCPD-34414","AM65: Missing k3-am654-pcie-usb3 from kirkstone build","am654x-evm"
   "LCPD-34413","RT Linux: Interrupt latency issue with >200us outliers","am654x-evm,am654x-hsevm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_lp_sk-fs,am62axx_sk-fs,am62xx-sk,am64xx_sk-fs,j721e-sk,j721s2-evm,j721s2_evm-fs,j7200-evm,j784s4-evm"
   "LCPD-34316","AM65x : ICSSG : Switching between Dual EMAC and Switch mode fails","am654x-idk"
   "LCPD-34125","AM65x Linux SDK : Missing ICSSG Performance numbers","am654x-evm,am654x-idk"
   "LCPD-32958","AM6xx/J7: Issue with MCSPI clocking in Linux driver","am654x-evm,am654x-idk,am654x-hsevm,am64xx-evm,am64xx-hsevm,am64xx-hssk,am62xx_sk-fs,am62xx_sk-se,am62xx_lp_sk-fs,am62xx_lp_sk-se,am62axx_sk-fs,am62axx_sk-se,am62xx-lp-sk,am62xx-sk,am64xx_sk-fs"
   "LCPD-32946","RT Linux: PRU Ethernet link down causes kernel crash","am654x-evm,am654x-idk,am64xx-evm"
   "LCPD-32823","ICSS firmware does not process Rx packets once Min error frame is received","am654x-idk,am64xx-evm"
   "LCPD-32773","Rx stall seen when there is network traffic during startup","am654x-idk,am64xx-evm"


|

