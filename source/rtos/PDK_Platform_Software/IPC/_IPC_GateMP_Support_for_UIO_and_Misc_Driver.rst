.. http://processors.wiki.ti.com/index.php/IPC_GateMP_Support_for_UIO_and_Misc_Driver

Introduction
^^^^^^^^^^^^^^^

Starting in IPC 3.42, the GateMP module added support for accessing
device memory without using /dev/mem. Instead of accessing /dev/mem, a
uio driver for Shared Region 0 access and a misc driver to expose a
hwspinlock user interface can be used. These drivers are added in the
Android SDK and GLSDK kernels. This feature was added because in some
environments, /dev/mem may not be accessible to the LAD.

.. note::
   There is no change to how LAD is launched in this case, and if the uio
   and misc driver are not available in the kernel, it will fall back to
   using /dev/mem.


.. note::
   This applies only to Linux/Android IPC.

Config
^^^^^^^

Enable the uio and misc drivers in the kernel by enabling the following
config options:

CONFIG_HWSPINLOCK_USER=y
CONFIG_UIO=y
CONFIG_UIO_PDRV_GENIRQ=y
Update your dts file to define the hwspinlocks being used by the misc
driver. Must start from hwspinlock "0" and go up sequentially:

::

    gatemp {
            compatible = "hwspinlock-user";
            hwlocks = <&hwspinlock 0>,
                      <&hwspinlock 1>,
                      <&hwspinlock 2>,
                      <&hwspinlock 3>,
                      <&hwspinlock 4>,
                      <&hwspinlock 5>,
                      <&hwspinlock 6>,
                      <&hwspinlock 7>,
                      <&hwspinlock 8>,
                      <&hwspinlock 9>;
    };

The hwspinlock configuration in the dts file MUST match the BIOS-side
IPC HWSpinlock configuration. Configuration the BIOS-side IPC module by
adding the following to your cfg file (where <N> is equal to the number
of spinlocks in the dts listing):

::

     var HWSpinlock = xdc.useModule(‘ti.sdo.ipc.gates.GateHWSpinlock’);
     HWSpinlock.numLocks = <N>;

Update your dts file to add the UIO-based node for Shared Region 0
(modify address and size so that it matches the Shared Region 0
definition in the remote core image):

Kernel 3.14-based releases:

::

    sr0 {
            compatible = "generic-uio";
            reg = <0xbfd00000 0x100000>;
    };

Kernel 4.4-based releases:

::

    sr0 {
            compatible = "generic-uio";
            reg = <0x0 0xbfb00000 0x0 0x100000>;
    };

.. note::
   Make sure that the "compatible" property in the sr0 dts node matches the
   UIO’s of_id string defined in the kernel command line.

Append the following to the kernel's CONFIG_CMDLINE:

::

    uio_pdrv_genirq.of_id=generic-uio

For example:

::

    CONFIG_CMDLINE="root=/dev/mmcblk0p2 rw console=ttyS0,119200 androidboot.console=ttyS0 init=/init rootfstype=ext4 rootwait drm.rnodes=1 snd.slots_reserved=1,1 androidboot.selinux=permissive androidboot.hardware=jacinto6evmboard uio_pdrv_genirq.of_id=generic-uio"

.. note::
   Changes for the command line are already present in the Android 6AM.1.0
   release. For GLSDK, the command line comes from the bootargs set in the
   uenv.txt file in the boot partition.

Also, specific owner/group must be set for the following files:

-  /dev/uio0
-  /dev/hwspinlock
-  **Android:** /data/lad, /data/lad/LAD
-  **Linux:** /tmp/LAD


