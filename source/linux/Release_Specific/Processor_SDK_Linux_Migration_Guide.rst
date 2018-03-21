.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Migration_Guide

************************************
Migration Guide
************************************

.. rubric:: Overview
   :name: overview

This page covers migration information for applications built on top
of the Processor SDK for Linux.


.. rubric:: Processor SDK Linux 04.02.00
   :name: processor-sdk-linux-04.02.00

.. rubric:: Linux
   :name: linux

.. rubric:: PRUETH Driver
   :name: prueth-driver

| The module parameter syntax has changed from "prueth.pruss1\_ethtype"
  and "prueth.pruss2\_ethtype" in older release to
  "ti\_prueth.pruss1\_ethtype" and "ti\_prueth.pruss2\_ethtype".

|

.. rubric:: Processor SDK Linux 04.01.00
   :name: processor-sdk-linux-04.01.00

.. rubric:: IPC
   :name: ipc

.. rubric:: PRUSS remoteproc
   :name: pruss-remoteproc

-  PRUs are no longer automatically booted (remoteproc 'auto\_boot' is
   set to false) by remoteproc core. A PRU has to be booted either by
   PRU Client Drivers or a PRU applications in userspace. The
   kernel-space boot is triggered using the rproc\_boot() kernel API,
   and the user-space applications can use the sysfs to start and stop
   the corresponding remoteproc. Please see
   Documentation/ABI/testing/sysfs-class-remoteproc file in kernel for
   sysfs usage details.
-  PRU remoteproc driver no longer configures the PRU Ethernet firmwares
   automatically using board-machine compatibles. The needed firmware
   names are configured by the PRU Ethernet driver now using the
   rproc\_set\_firmware() function.
-  Userspace PRU applications have to make sure to unload any existing
   PRU client drivers using a specific PRU, and set their firmware using
   sysfs before starting and using a PRU

| 

.. rubric:: Processor SDK Linux 04.00.00
   :name: processor-sdk-linux-04.00.00

-  This is the first release for 2017 LTS (Kernel: 4.9, U-boot: 2017.01,
   gcc: 6.2.1 and Yocto: 2.2 (morty)), with following major changes.

.. rubric:: IPC
   :name: ipc-1

.. rubric:: remoteproc
   :name: remoteproc

-  The debugfs 'state' variable is replaced with a sysfs 'state'
   variable accepting 'start' and 'stop' to boot and shutdown a remote
   processor from userspace
-  A new sysfs variable 'firmware' is also added to set a new firmware.
   remoteprocs need to be in stopped state before a firmware can be set.
   New firmwares still need to reside in /lib/firmware
-  Booting a remote processor is now triggered by the insertion of the
   respective remoteproc platform driver. On 4.4, with virtio-rpmsg
   enabled firmwares, this only happened when both the remoteproc
   platform driver and virtio\_rpmsg\_bus module were installed.
-  Upstream 4.9 remoteproc and rpmsg cores are not suitable for TI
   platforms. A minimum of 4.10-rc4 (or the required remoteproc/rpmsg
   patches from 4.10-rc4) is needed if porting TI remoteproc drivers
   onto upstream.

.. rubric:: rpmsg
   :name: rpmsg

-  virtio\_rpmsg\_bus module split into a 'rpmsg\_core' and virtio-rpmsg
   transport specific 'virtio\_rpmsg\_bus' modules.
-  Removal of virtio\_rpmsg\_bus no longer stops a remote processor and
   should be avoided if a remote processor is running. \* If removed and
   installed again, the rpmsg communication devices will not be
   reprobed.

.. rubric:: Keystone\_remoteproc
   :name: keystone_remoteproc

-  A new 'label' binding property is now mandatory. It will have the
   string names for the DSPs in the format "dsp<X>" (eg: dsp0, dsp7 etc)
-  K2G DSP nodes will require a new "ti,sci-id" property, and a
   different value for "power-domains" property (this is generic to all
   K2G devices)

.. rubric:: PRUSS remoteproc
   :name: pruss-remoteproc-1

-  The AM437x specific am437x\_pruss\_wrapper module has been replaced
   with a generic pruss\_soc\_bus module, and is required to be
   installed on all SoCs.
-  New compatibles on AM335x and AM437x SoCs - The previous 'am3352-xxx'
   and 'am4372-xxx' have been replaced with a 'am3356-xxx' and
   'am4376-xxx' compatibles since PRUSS are not present on AM3352 and
   AM4372 SoCs. The PRU nodes are also not enabled by default in base
   'am33xx.dtsi' and 'am4372.dtsi' files.
-  New device hierarchy structure - The PRUSS node hierarchy from 4.4 is
   moved one-level down under a new parent pruss\_soc\_bus node.

.. rubric:: CPSW CPDMA Descriptor Usage
   :name: cpsw-cpdma-descriptor-usage

There is a notable change in how to place cpsw cpdma descriptors in DDR
and configure descs number: **TI K4.4** device tree property was used
"descs\_pool\_size" - descs\_pool\_size : total number of CPDMA CPPI
descriptors to be used for both ingress/egress packets processing. if
not specified the default value 256 will be used which will allow to
place descriptors pool into the internal CPPI RAM.

**New approach**
http://processors.wiki.ti.com/index.php/Linux_Core_CPSW_User%27s_Guide#Configure_number_of_TX.2FRX_descriptors

.. rubric:: PCI ENDPOINT
   :name: pci-endpoint

The usage of 'pci-ep' configfs directory to configure PCI Endpoint has
been changed in accordance with upstream review comments. Please see
http://processors.wiki.ti.com/index.php/Linux_Core_PCIe_EP_User%27s_Guide#4.9_Kernel,
for additional details

.. rubric:: Display
   :name: display

fbdev is only set up for the primary display, instead of all displays.
This results in the secondary displays to be left disabled by the
kernel, until an userspace application enables the displays.

.. rubric:: U-Boot RNDIS boot
   :name: u-boot-rndis-boot

AM335x USB client (RNDIS) boot and Ethernet boot modes are now supported
using default defconfig (am335x\_evm\_defconfig). Similarly AM437x USB
client (RNDIS) boot is now supported by am43xx\_evm\_defconfig. Separate
defconfigs for above boot modes no longer exist.

.. rubric:: Keystone-2 features
   :name: keystone-2-features

The following features are not ported to 2017 LTS

-  SRIO Kernel driver
-  10G Uboot
-  IPSec sideband and inflow mode
-  QoS

| 

.. rubric:: Processor SDK Linux 03.03.00
   :name: processor-sdk-linux-03.03.00

-  HDMI-connected monitor no longer takes precedence over built-in LCD
   as a default graphics display for e.g. Matrix
-  See the `Release
   Notes <http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Release_Notes>`__
   for full list of modifications.

| 

.. rubric:: Processor SDK Linux 03.02.00
   :name: processor-sdk-linux-03.02.00

-  The QT QPA eglfs\_kms, which supports multiple screens, has been
   enabled and used as the default eglfs platform plugin. For more
   information, see `QT and Graphics
   Migration <http://processors.wiki.ti.com/index.php/Processor_Linux_SDK_Graphics_and_Display#Migration_Guide_from_Processor_SDK_3.1_to_3.x_for_AM3.2F4.2F5>`__
-  bootmonitor now goes thru mkimage and as a result the load address
   changed. Users should manually execute following commands in their
   u-boot environment to properly install the secure monitor on k2
   platforms:

::

    setenv addr_mon 0xc08000
    setenv addr_mon_mkimg 0xc07ffc0
    setenv mon_size 0x1210
    setenv sec_bm_install 'go ${addr_mon}4 0xc084000 ${mon_size}; mon_install ${addr_mon_mkimg}'
    run sec_bm_install

-  HDMI-connected monitor no longer takes precedence over built-in LCD
   as a default graphics display for e.g. Matrix

| 

.. rubric:: Processor SDK Linux 03.01.00
   :name: processor-sdk-linux-03.01.00

-  defconfig\_builder is now used to generate working kernel defconfigs
-  In K2 U-Boot, added multi slave support.
-  In K2 Linux PA driver, added pre-classification support. So explicit
   lut rules for broadcast and multicast are removed and the same is
   achieved through this feature in PA
-  10G Ethernet driver now supports auto configuration using MCU
   firmware (a.k.a 10G KR firmware). The firmware file name is
   ks2\_xgbe\_serdes\_mcu\_fw.bin which is available at the same
   location as other serdes firmwares.
-  The current version of the serdes firmware is 03.03.00.02C and the
   same is not backward compatible with the firmware in the previous SDK
   release (03.00.00)

| 

.. rubric:: Processor SDK Linux 03.00.00
   :name: processor-sdk-linux-03.00.00

-  First 2016 LTS Release (Linux Kernel: 4.4, U-Boot: 2016.05, GCC 5.3,
   Yocto 2.1)
-  Unified kernel configuration based on multi\_v7\_defconfig
-  Migrated from SysVinit to systemd for user space initialization.
-  U-Boot drivers now uses DT, but is transparent to users
-  The content of <evm>-<os>-sdk-arago-src-<ver>.tar.gz on the download
   page changed from sources to a fetcher script that obtains the
   sources. This is to efficiently share the sources between different
   platforms and OSes supported by Processor SDK. See the README inside
   the tar-ball for instructions
-  This release adds support for RT Linux on AM335x ICE and K2G GPEVM
-  In K2 U-Boot, multi slave support is currently missing. To use
   multiple interfaces, please disable CONFIG\_DM\_ET option in u-boot
   .config and build.
-  See the Release Notes for full list of modifications.
-  For information on migrating from MCSDK (K2x) to Processor SDK, see
   `this migration
   page <MCSDK_to_Processor_SDK_Migration.html>`__.

| 

.. rubric:: Processor SDK Linux 02.00.02
   :name: processor-sdk-linux-02.00.02

-  This release adds RT Linux support on AM335x, K2H/K, K2E, K2L
-  This release supports AM572x IDK and K2G EVM
-  OpenCV now uses OpenCL under the hood, to offload compute tasks to
   C66x cores. This is transparent to the application
-  The SGX driver for AM335x has been enhanced to support DRM/WAYLAND
   based Multi-Window Display. For more information, see `AM3 Graphics
   Migration <http://processors.wiki.ti.com/index.php/Processor_Linux_SDK_Graphics_and_Display#Migration_Guide_from_Processor_SDK_2.0.0_to_2.0.x_for_AM4>`__
-  See the `Release
   Notes <http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Release_Notes#Release_02.00.02>`__
   for full list of modifications.
-  For information on migrating from MCSDK (K2x) to Processor SDK, see
   `this migration
   page <MCSDK_to_Processor_SDK_Migration.html>`__.

| 

.. rubric:: Processor SDK Linux 02.00.01
   :name: processor-sdk-linux-02.00.01

-  This release adds support for devices from the KeyStone architecture:
   K2E, K2H/K, and K2L
-  This release also supports RT Linux is supported on AM4 and AM5
   device
-  The SGX driver for AM4 has been enhanced to support DRM/WAYLAND based
   Multi-Window Display. For more information, see `AM4 Graphics
   Migration <http://processors.wiki.ti.com/index.php/Processor_Linux_SDK_Graphics_and_Display#Migration_Guide_from_Processor_SDK_2.0.0_to_2.0.x_for_AM4>`__
-  There is no migration impact to customers using AM3, and AM5.
-  See the `Release
   Notes <http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Release_Notes#Release_02.00.01>`__
   for full list of modifications.
-  For information on migrating from MCSDK (K2x) to Processor SDK, see
   `this migration
   page <MCSDK_to_Processor_SDK_Migration.html>`__.

| 

.. rubric:: Processor SDK Linux 02.00.00
   :name: processor-sdk-linux-02.00.00

-  This release adds support for AM57x
-  First 2015 LTS (Kernel 4.1, U-boot 2015.07) Release
-  Starting this release, Processor SDK Installer is 64-bit, and
   installs only on 64-bit host machine. Support for 32-bit host is
   dropped as Linaro toolchain is available only for 64-bit machines
-  For AM3, AM4, Graphics SDK is now obsolete and Graphics stack is
   integrated into Processor SDK, and supports null DRM based Full
   Window, with Front and Flip modes. For more information, see
   `Graphics
   Migration <http://processors.wiki.ti.com/index.php/Processor_Linux_SDK_Graphics_and_Display#Migration_Guide_from_Processor_SDK_1.x_to_2.x_for_AM3.2C_AM4>`__
-  Ethernet performance degraded ~10% on am335x-evm due to move from
   preempt\_voluntary
-  See the `Release
   Notes <http://processors.wiki.ti.com/index.php?title=Processor_SDK_Linux_Release_Notes%26oldid%3D207973&action=edit&redlink=1>`__
   for full list of modifications.

