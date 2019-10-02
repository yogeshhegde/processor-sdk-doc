*********************
IPC Low Level Driver
*********************

Overview
==================================

On AM65X/Jacinto 7 platforms, a lower level IPC driver (IPC LLD) using rpmsg-based transport is included in PSDKRA. For details 
on PSDKRA package, refer to `PSDKRA summary <Overview_PSDKLA_PSDKRA_Summary.html>`_. Sample firmware binaries for all remote 
cores are located at <PSDKLA root filesystem>/lib/firmware. Jacinto 7 remote cores can be loaded by u-boot from the filesystem 
as part of the boot sequence. The PSDKLA release also supports loading the remote firmware by remoteproc kernel driver. The 
remote firmware demonstrates the interprocessor communication between the cores - Linux to/from RTOS and RTOS to/from RTOS.

J721e u-boot can load the following cores:
 - Main-R5F1 (Lockstep)
 - C66x_1
 - C66x_2
 - C7x_1

Linux remoteproc kernel driver can support loading to all cores.

Please refer to the following link for additional details `IPCLLD <http://software-dl.ti.com/processor-sdk-rtos/esd/docs/latest/rtos/index_device_drv.html#ipclld>`_.
