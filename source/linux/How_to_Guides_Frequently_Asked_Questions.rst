***************************************
Frequently Asked Questions
***************************************

.. include:: replacevars.rst.inc

How to verify IPC between Linux and MCU R5 in Keystone devices?
---------------------------------------------------------------------

Automotive applications have different memory needs and use a different memory
map defined in the auto-common.dtbo file. Therefore, the default |__SDK_FULL_NAME__|
is shipped with firmwares for only a few auxiliary cores in the Keystone devices.

Although the out-of-the-box experience does not allow to verify the
interprocessor communication (IPC) between Linux and the MCU R5,
the following steps describe how this can be done using the SDK.

.. rubric:: Steps to build IPC echotest binaries
   :name: faq-steps-to-build-ipc-echotest-binaries

All the IPC echotest binaries are built as a Yocto package **ipc-lld-fw**.
Since these binaries conflict with the automotive demos, this package is not
built in the SDK installed by default. This can be built using Yocto and installed
into the filesystem on target.

Make sure that you have setup the Yocto build environment for this. Refer to
`Building the SDK <Overview_Building_the_SDK.html>`__ section for all details.

Once the Yocto build is setup, use bitbake to build the specific package ipc-lld-fw
as shown below:

::

    TOOLCHAIN_BASE=<PATH_TO_TOOLCHAIN> MACHINE=<machine> bitbake -k ipc-lld-fw

This will create the firmware package for all the remoteproc cores in the system
where the IPC echotest functionality is implemented. The package will be located
at the directory **<Yocto work directory>/j7_evm-linux/ipc-lld-fw/<version>/deploy-ipks/**.

.. rubric:: Installing the IPC echotest binaries
   :name: faq-installing-ipc-echotest-binaries


Once the package is built on the host machine, copy it to the target filesystem.
Run thethe  following commands to install the package to target filesystem.

The **update-alternatives** command in the below instructions will set the priority
for the IPC firmware very high. This is to ensure that the symlinks are updated
appropriately. Typical firmwares will have priorities up to 20, setting the IPC
firmware priority to 100 gives it highest priority.

.. note::

    priority override is done only for the automotive firmwares like ethernet firmware
    and display sharing firmware. If you have installed additional firmwares,
    you should do it for others as well.

::

    opkg install ipc-lld-fw*.ipk
    update-alternatives --install /lib/firmware/j7-main-r5f0_0-fw j7-main-r5f0_0-fw /lib/firmware/pdk-ipc/ipc_echo_test_mcu2_0_release.strip.xer5f 100
    update-alternatives --install /lib/firmware/j7-main-r5f0_1-fw j7-main-r5f0_1-fw /lib/firmware/pdk-ipc/ipc_echo_test_mcu2_1_release.strip.xer5f 100


After this, make sure that all the firmwares are pointing to the pdk-ipc/
version of the binaries by running the following:

::

    ls -l /lib/firmware/j7*

Reboot the board and you will see the IPC echotest binaries loaded onto different
CPU cores.

How to configure K3 MSMC memory for use as SRAM or L3 cache?
---------------------------------------------------------------------

In Keystone devices, there exists on-chip memory at the MSMC interconnect.
This can be configured either as SRAM or as L3 cache.

Automotive ADAS applications, which use C7x, benefit a lot when the MSMC memory
is configured as SRAM. Alternatively, the CPU benchmark applications get performance
boost when the memory is configured as cache.

Typically, MSMC memory needs to be split between SRAM and cache with the split boundary
being aligned at 1MB. System firmware partitions SRAM between cache and SRAM at
the bootup based on the board config data structure.

Rebuild the system firmware image (sysfw.itb) with right board config to
change to desired behavior. Following are the steps to achieve this:

Modify the file **soc/j721e/evm/board-cfg.c** in **system-firmware-image-gen** repo
from the installer.

::

    /* boardcfg_msmc */
    .msmc = {
            .subhdr = {
                    .magic = BOARDCFG_MSMC_MAGIC_NUM,
                    .size = sizeof(struct boardcfg_msmc),
            },
            .msmc_cache_size = 0x0,
    },

Here, the msmc_cache_size variable can take values from 0x0 to 0xf, where 0x0
describes zero cache and 0xf describes full cache. Note that due to hardware
restriction, the total memory that gets configured as cache is rounded up to 1MB.

Following table describes an example of this for J721e platform.

+-----------------+-----------------------------------------------------------+
| msmc_cache_size | Description                                               |
+=================+===========================================================+
| 0x0             | All of MSMC memory (i.e. 8MB) configured as SRAM          |
+-----------------+-----------------------------------------------------------+
| 0x3             | 2MB of MSMC memory configured as cache, rest 6MB is SRAM  |
+-----------------+-----------------------------------------------------------+
| 0x6             | 3MB of MSMC memory configured as cache, rest 5MB is SRAM  |
+-----------------+-----------------------------------------------------------+
| 0xf             | All of MSMC memory (i.e. 8MB) configured as cache         |
+-----------------+-----------------------------------------------------------+
