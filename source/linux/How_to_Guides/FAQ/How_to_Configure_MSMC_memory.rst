How to configure K3 MSMC memory for use as SRAM or L3 cache?
==================================================================

In K3 devices, there exists on-chip memory at the MSMC interconnect.
This can be configured either as SRAM or as L3 cache.
Automotive ADAS applications, which use C7x, benefit a lot when the MSMC memory
is configured as SRAM. Alternatively, the CPU benchmark applications get performance
boost when the memory is configured as cache.
Typically, MSMC memory needs to be split between SRAM and cache. System firmware partitions SRAM between L3 cache and SRAM at
the bootup based on the board config data structure.

Rebuild R5 bootloader images (tiboot3.bin and in case of legacy boot flow,
sysfw.itb) with the right board configuration to change to desired behaviour.
Following are the steps to achieve this:

Modify the file **board/ti/<soc>/board-cfg.yaml** in the **U-Boot** repo:

.. code-block:: yaml

    msmc:
        subhdr:
            magic: 0xA5C3
            size: 5
        msmc_cache_size: 0x0

Here, the ``msmc_cache_size`` variable can take values in step sizes, that vary
between platforms. The following table mentions each of them:

+-----------------+--------------+------------------------------------+-----------------------+
| Platform        | Step Size    | Value of MSMC configured as cache  | Total SRAM available  |
+=================+==============+====================================+=======================+
| J721E           | 0x4          | 1 MB                               | 8 MB                  |
+-----------------+--------------+------------------------------------+-----------------------+
| J7200           | 0x8          | ~256 KB                            | 1 MB                  |
+-----------------+--------------+------------------------------------+-----------------------+
| J721S2          | 0x8          | 1 MB                               | 4 MB                  |
+-----------------+--------------+------------------------------------+-----------------------+
| J784S4          | 0x8          | 1 MB                               | 8 MB                  |
+-----------------+--------------+------------------------------------+-----------------------+

Following table describes an example of this for J721e platform.

+-----------------+-----------------------------------------------------------+
| msmc_cache_size | Description                                               |
+=================+===========================================================+
| 0x0             | All of MSMC memory (i.e. 8MB) configured as SRAM          |
+-----------------+-----------------------------------------------------------+
| 0x8             | 2MB of MSMC memory configured as cache, rest 6MB is SRAM  |
+-----------------+-----------------------------------------------------------+
| 0xc             | 3MB of MSMC memory configured as cache, rest 5MB is SRAM  |
+-----------------+-----------------------------------------------------------+
| 0x20            | All of MSMC memory (i.e. 8MB) configured as cache         |
+-----------------+-----------------------------------------------------------+

Please note that the final allocation may vary slightly due to hardware alignment as well as keeping
aside 64kB for communication infrastructure.
See `this link <https://software-dl.ti.com/tisci/esd/21_05_01/2_tisci_msgs/general/core.html?highlight=msmc#tisci-msg-query-msmc>`__ for more information.
