.. rubric:: Early Boot and Late Attach in Linux
   :name: firstHeading

.. rubric:: Introduction
   :name: introduction

DRA7xx/AM57xx SOCs have multiple processor cores - Cortex A15, C66x DSPs and
ARM M4 cores. The A15 typically runs a HLOS like Linux/Android and
the remotecores(DSPs and M4s) run an RTOS. In the normal operation,
bootloader (U-Boot/SPL) boots and loads the A15 with the HLOS. The A15
boots the DSP and the M4 cores. In this sequence, the interval between
the Power on Reset and the remotecores (i.e. the DSPs and the M4s)
executing is dependent on the HLOS initialization time. This delay may
not be suitable for realizing some usecases with tight time constraints.
e.g. Rear View Camera.

.. Image:: /images/Normal-boot.png
   :class: thumbimage
   :width: 511px
   :height: 263px


To address the early boot usecase, one may need the bootloader to boot a remote
core before booting the A15 with the linux kernel, i.e. booting the
remotecore early. The kernel then attaches to the already booted remote
core for further communication i.e. connecting to the remotecore later
in its execution. We refer to this feature as the "Early Boot - Late
Attach" functionality. The "Early Boot" functionality is provided by the
boot loader. The "Late Attach" functionality is a feature of the Linux
Kernel.

.. Image:: /images/Early-boot.png
   :class: thumbimage
   :width: 511px
   :height: 263px

The following sections describe how to use this
feature and how to troubleshoot any issues with early boot and late
attach.

.. rubric:: Using Early Boot/Late Attach
   :name: using-early-bootlate-attach

Early Boot/Late Attach functionality is supported for IPUs and enabled by default
for IPU1 remote processor on the TI SDKs for all TI DRA7xx/AM57xx platforms.
The functionality relies on matching configuration/code between
SPL and Linux kernel in terms of memory and timers used by the firmwares,
and matching firmwares in boot media (used by SPL) and in the rootfs
in /lib/firmware folder (used by kernel).

.. rubric:: Pre-flight checks
   :name: pre-flight-checks

1. Before attempting to early boot a remotecore from U-Boot SPL, please
   ensure that the remotecore binary can be loaded by Linux without any
   issues. This ensures that the memory map and MMU configuration are
   done correctly. The test should be done by using a carveout (DMA pool)
   for the remoteproc instead of the default preferred CMA pool.
   This is achieved by replacing the "reusable" property with a
   "no-map" property in the reserved-memory node used by the remoteproc
   in the board dts file.

2. MLO uses the same memory allocation strategy as the kernel for the
   carveouts specified in the resource table from the memory pool used
   by the kernel. The location of the memory pools for each of the
   remotecores is hardcoded in MLO to kernel defaults. In case the
   memory allocations in kernel are modified, U-Boot should be modified
   to match with the configuration specified in the kernel.

   The U-Boot DTS file to modify is ``arch/arm/dts/dra7-ipu-common-early-boot.dtsi``.
   ::

        ipu1_memory_region: ipu1-memory@9d000000 {
            compatible = "shared-dma-pool";
            reg = <0x0 0x9d000000 0x0 0x2000000>;
            reusable;
            status = "okay";
            u-boot,dm-spl;
        };
        
        ipu2_memory_region: ipu2-memory@95800000 {
            compatible = "shared-dma-pool";
            reg = <0x0 0x95800000 0x0 0x3800000>;
            reusable;
            status = "okay";
            u-boot,dm-spl;
        };


   The reserved memory nodes above should match the reserved-memory node region
   definitions in the corresponding dts board file in the kernel. For example,
   see the defined reserved-memory nodes in arch/arm/boot/dts/am57xx-beagle-x15-common.dtsi
   file used for all AM57xx EVM boards:
   ::

       ipu1_cma_pool: ipu1_cma@9d000000 {
           compatible = "shared-dma-pool";
           reg = <0x9d000000 0x2000000>;
           reusable;
           status = "okay";
       };
       
       ipu2_cma_pool: ipu2_cma@95800000 {
           compatible = "shared-dma-pool";
           reg = <0x95800000 0x3800000>;
           reusable;
           status = "okay";
       };


   If the allocations do not match, the MLO execution may fail when trying to allocate memory for the carveouts.
   Further, the kernel can overwrite the memory being used by firmwares and can result in crashes.


3. For each core, we reserve 16 KB for the Level 1 page table and an
   additional 16 KB for Level 2 page tables i.e. 32 KB for core. This
   information is passed to the boot loader via the below macros in
   ``arch/arm/dts/dra7-ipu-common-early-boot.dtsi``.


   ::

        ipu1_pgtbl: ipu1-pgtbl@95700000 {
            reg = <0x0 0x95700000 0x0 0x40000>;
            no-map;
            u-boot,dm-spl;
        };
        
        ipu2_pgtbl: ipu2-pgtbl@95740000 {
            reg = <0x0 0x95740000 0x0 0x40000>;
            no-map;
            u-boot,dm-spl;
        };

  The memory for the page tables (256 KB per IPU) is placed just before
  the carveout memories for the remote processors. 16 KB of memory is
  needed for the L1 page table (4096 entries * 4 bytes per 1 MB section).
  Any smaller page (64 KB or 4 KB) entries are supported through L2 page
  tables (1 KB per table). The remaining 240 KB can provide support for
  240 L2 page tables. Any remoteproc firmware image requiring more than
  240 L2 page table entries would need more memory to be reserved.
  The carveout in memory can be reduced to 128 KB if the system is under a memory
  constraint.


4. MLO first loads the remotecore binaries from storage media to a
   temporary DDR address. Then MLO parses the binaries and copies the
   code/data sections to the their final locations. Please ensure that
   the physical addresses used by the remotecore binaries during
   execution do not overlap with these temporary load addresses.

   The location of the macros controlling these temporary load locations
   is listed below.

   In U-Boot, each core is assigned a distinct temporary load
   address. The source file in which the macro is defined is also
   modified.

.. list-table:: U-boot: Temporary load address for Early boot binaries
   :header-rows: 1

   * - Core

     - IPU1

     - IPU2

   * - Load Address

     - ``IPU1_LOAD_ADDR``

     - ``IPU2_LOAD_ADDR``

   * - Defined in

     - ``arch/arm/mach-omap2/boot-common.c and drivers/remoteproc/ipu_rproc.c``

     - ``arch/arm/mach-omap2/boot-common.c and drivers/remoteproc/ipu_rproc.c``

.. rubric:: Enabling Early Boot
   :name: enabling-early-boot

Early boot is enabled by default on all DRA7xx and AM57xx EVM boards in the
dra7xx_evm_defconfig and am57xx_evm_defconfig. Typical options needed for
early-booting IPU remoteprocs are:

::

   CONFIG_SPL_DRIVERS_MISC_SUPPORT=y
   CONFIG_SPL_DM_RESET=y
   CONFIG_SPL_REMOTEPROC=y
   CONFIG_FS_LOADER=y
   CONFIG_REMOTEPROC_TI_IPU=y
   CONFIG_DM_RESET=y
   CONFIG_RESET_DRA7=y

The default firmware location, timers, remoteprocs to be enabled are defined in dts file.
Please see the file arch/arm/dts/dra7-ipu-common-early-boot.dtsi, which defines the
peripherals used for booting the IPU1, and is then included in the corresponding board's
U-Boot dts file.


.. rubric:: Customizing Early Boot for a Usecase
   :name: customizing-early-boot-for-a-usecase

The Early boot code in U-Boot does the necessary configuration to bring
up a remotecore. This includes the timers and the MMUs. It does not
configure any other peripherals by default. Some usecases may require
additional peripheral configuration before running the remotecore.
U-Boot includes placeholder functions that can be populated for this
purpose. These can be found in the file
``drivers/remoteproc/ipu_rproc.c``.



::

    * If the remotecore binary expects any peripherals to be setup before it has
    * booted, configure them here.
    *
    * These functions are left empty by default as their operation is usecase
    * specific.
    u32 ipu1\_config\_peripherals(u32 core\_id, struct rproc \*cfg) {

       return 0;
    }
    u32 ipu2\_config\_peripherals(u32 core\_id, struct rproc \*cfg) {

       return 0;
    }


.. rubric:: Testing early boot
   :name: testing-early-boot

#. Place the MLO built with early boot enabled and the remotecore
   binaries in the specified locations and power on the EVM.
#. The MLO should locate the remotecore binary and proceed to load it
   and then jump to U-Boot or Kernel.

| An easy way to verify that early boot is working is by stopping the
  A15 execution at the U-Boot prompt and connecting to the remotecore
  via a JTAG. If connecting to a remotecore via JTAG does not work,
  please refer to the section of "Debugging Early Boot" later in the
  document.
| Another way to check the functionality is to execute the below command
  after kernel boot-up.

::

    root@dra7xx-evm:~# cat /sys/kernel/debug/remoteproc/remoteproc0/trace0
    [0][      0.000] Watchdog enabled: TimerBase = 0x68824000 SMP-Core = 0 Freq = 19200000
    [0][      0.000] Watchdog enabled: TimerBase = 0x68826000 SMP-Core = 1 Freq = 19200000
    [0][      0.000] Watchdog_restore registered as a resume callback
    [0][      0.000] 18 Resource entries at 0x3000
    [0][      0.000] messageq_single.c:main: MultiProc id = 2
    [0][      0.000] Time at reset() is 51615 ticks
    [0][      0.000] Time at startup()  is 51726 ticks
    [0][      0.000] Time at main()  is 51804 ticks
    [0][      0.000] registering rpmsg-proto:rpmsg-proto service on 61 with HOST
    [0][      0.000] tsk1Fxn: created MessageQ: SLAVE_IPU1; QueueID: 0x20080
    [0][      0.000] Awaiting sync message from host...

In the next section, we describe the kernel modifications necessary to
allow it to connect to a remotecore already loaded by MLO.

.. rubric:: Early boot with SPI boot mode

In DRA7xx/AM57xx, the boot ROM copies the first stage boot loader(MLO/SPL) from
QSPI flash at a conservative speed of 48MHz. For certain use cases the time spent
in ROM copy plays a significant role in the usecases time. To speed up the time
to copy the firststage boot loader we use a ``umlo`` (micro MLO).

The umlo configures the DRA7xx/AM57xx to operate at the maximum QSPI interface
speed, which is 76.8MHz interface frequency, Quad mode, and Mode 0 operation. The
umlo copies the MLO to the execution address in OCMC and jumps to it. With this
the time taken to enter a 168 KB size of MLO is significantly reduced to 5.5 ms
approximately.

The umlo source can be cloned from the below link. The tool shall be compiled with
any baremetal compiler that supports Cortex A15. Ensure that the toolchain is installed
and have ``arm-none-eabi-gcc`` in the PATH. Follow ``README.md`` from the repo to
compile and build umlo binary.

::

    git clone git://git.ti.com/glsdk/dra7xx-umlo.git

The firmware that needs to be loaded into other cores should be converted into
uImage format. Refer the below command to convert the firmware into uImage format

::

    mkimage -d dra7-ipu1-fw.xem4 dra7-ipu1_0-fw.uImage

Flash the binaries into the QSPI memory offset as below.

	+--------------------------+-------------+
	| Name                     |     Offset  |
	+==========================+=============+
	| umlo                     | 0x00        |
	|                          |             |
	+--------------------------+-------------+
	| MLO                      | 0x10000     |
	|                          |             |
	+--------------------------+-------------+
	| u-boot.img               | 0x40000     |
	|                          |             |
	+--------------------------+-------------+
	| IPU1-firmware            | 0xA60000    |
	|                          |             |
	+--------------------------+-------------+
	| IPU2-firmware            | 0xE60000    |
	|                          |             |
	+--------------------------+-------------+

To flash the QSPI memory:
#. Create a folder named "qspi" in the SD card bootable partition & copy
all required images into this folder.
#. Boot the board with the SD card boot mode.
#. Stop the boot at u-boot prompt and run the below commands.

::

    mmc dev 0
    sf probe 0
    
    /* Flashing MLO */
    fatload mmc 0 0x82000000 qspi/MLO
    sf erase 0x10000 0x30000
    sf write 0x82000000 0x10000 0x30000
    
    /* Flash u-boot */
    fatload mmc 0 0x83000000 qspi/u-boot.img
    sf erase 0x40000 0x200000
    sf write 0x83000000 0x40000 0x200000
    
    /* Flashing umlo */
    fatload mmc 0 0x82000000 qspi/umlo
    sf erase 0x0 0x10000
    sf write 0x82000000 0x0 0x10000
    
    /* Flashing remote core firmware */
    fatload mmc 0 0x83000000 qspi/dra7-ipu1-fw.uImage
    sf erase 0xA60000 0x800000
    sf write 0x83000000 0xA60000 0x800000

#. Reboot the target board with QSPI boot mode. By default the SD boot is the primary boot
mode and the secondary boot mode is QSPI. To boot the target board in QSPI, remove the SD card
from the slot and power on the board.
#. Execute the below command after kernel boot-up to check the functionality.

::

    [2022-06-24 16:34:37.963] U-Boot SPL 2021.01-00003-ge559672da4 (Jun 24 2022 - 12:53:40 +0530)
    [2022-06-24 16:34:37.979] DRA722-GP ES2.0
    [2022-06-24 16:34:38.203] Trying to boot from SPI
    [2022-06-24 16:34:38.204] Loading Environment from FAT... no pinctrl state for default mode
    [2022-06-24 16:34:38.235] no pinctrl state for default mode
    [2022-06-24 16:34:38.235] MMC: no card present
    [2022-06-24 16:34:38.284] Loading Environment from MMC... *** Warning - bad CRC, using default environment

| The timestamp difference between the first line & third line
(Trying to boot from SPI) from the above log, ensures at this point of time the
firmware is already start executed. From the above log the time taken to boot the 
IPU is 240ms


.. rubric:: Enabling Late attach
   :name: enabling-late-attach

Loading the remotecores in the kernel is done via the ``remoteproc``
module. Each remotecore requires timers for OS tick and watchdog
purposes and MMU's for mapping virtual addresses to physical addresses.
The remoteproc module uses device tree determine the timers and mmu's
used for each remotecore.

The device tree nodes for each of the cores are shown below. The
allocation of timers to remotecores is from the file
``arch/arm/boot/dts/dra7-ipu-dsp-common.dtsi`` and
``arch/arm/boot/dts/dra74-ipu-dsp-common.dtsi``
in the kernel source tree.

+----------------+----------------+----------------+----------------+----------------+
| Core           | Remotecore     | OS timer node  | Watch dog      | MMU node(s)    |
|                | node           |                | timer node(s)  |                |
+================+================+================+================+================+
| IPU2           | ipu2           | timer3         | timer4,timer9  | mmu\_ipu2      |
+----------------+----------------+----------------+----------------+----------------+
| IPU1           | ipu1           | timer11        | timer7,timer8  | mmu\_ipu1      |
+----------------+----------------+----------------+----------------+----------------+
| DSP2           | dsp2           | timer6         |                | mmu0\_dsp2,mmu |
|                |                |                |                | 1\_dsp2        |
+----------------+----------------+----------------+----------------+----------------+
| DSP1           | dsp1           | timer5         | timer10        | mmu0\_dsp1,mmu |
|                |                |                |                | 1\_dsp1        |
+----------------+----------------+----------------+----------------+----------------+

During the normal boot flow, Linux kernel resets, idles and configures
all functional blocks to reach a known initial state. This sequence of
operations will terminate execution on a remotecore started by the boot
loader. To prevent this from happening, the following attributes need to
be set on **each** device tree node corresponding to the remotecore.

#. ``ti,no-idle-on-init``
#. ``ti,no-reset-on-init``.

These attributes together signal to the kernel that
remotecore and other nodes have been configured and are in use
before the kernel boot. These should not be reset or idled during
kernel boot.


#. ``ti,no-idle-on-init``
#. ``ti,no-reset-on-init``.

Refer dra7-ipu-common-early-boot.dtsi

An example showing the device tree modifications necessary when late
attaching to IPU1 are shown below. Please note that the attributes are
set on the ``ipu1`` node as well as the timers and mmu nodes used by
IPU1.

::

    &ipu1 {
        ti,no-idle-on-init;
        ti,no-reset-on-init;
    };

    &timer11 {
        ti,no-idle-on-init;
        ti,no-reset-on-init;
    };

    &timer7 {
        ti,no-idle-on-init;
        ti,no-reset-on-init;
    };

    &timer8 {
        ti,no-idle-on-init;
        ti,no-reset-on-init;
    };

    &mmu_ipu1{
        ti,no-idle-on-init;
        ti,no-reset-on-init;
    };



.. rubric:: Debugging Late Attach
   :name: debugging-late-attach

#. Ensure that both the late attach attributes are set on the device
   tree nodes corresponding to the remotecore node being loaded from the
   boot loader. Otherwise the kernel will reset and reload the
   remotecore as in the normal boot flow.
#. Ensure that both the late attach attributes are set **only** on the
   device tree nodes corresponding to the remotecore node being loaded
   from the boot loader. Otherwise the kernel will try to communicate
   with a remotecore that is not loaded and run into an error or a crash
   in a worst case scenario.
#. Ensure that the peripherals accessed by the remotecore are not being
   handled by the kernel. This can be accomplished by removing the
   corresponding nodes from the device tree.

|
