
PLL Programing Sequence Update To Avoid PLL Instability
=======================================================

In 10.00 SDK release, PLL programing sequence has been updated to follow the
correct programing sequence to avoid PLL instability. The PLL programing
sequence has been updated in following components of the SDK.

   #. DMSC firmware (ti-linux firmware repo)

SDK 10.0 has all the updated components by default.

Below section provides information on how to pick up these updates for last two
major SDK releases - SDK 08.06 and SDK 09.02.

SDK 08.06.00.42
---------------

Linux SDK 08.06 was the last SDK release with LTS Kernel version 5.10 and
u-boot version 2021.x. To pick up the PLL updates on top of this SDK, pick the
components listed below when building the u-boot binaries.


   #. DMSC Firmware

      - Pick up the SDK 10.0 DMSC firmware from tag ``10.00.07`` of ti-linux-firmware repo

         - https://git.ti.com/cgit/processor-firmware/ti-linux-firmware/tag/?h=10.00.07


Refer to `SDK 08.06 u-boot build instructions <https://software-dl.ti.com/processor-sdk-linux/esd/AM64X/08_06_00_42/exports/docs/linux/Foundational_Components/U-Boot/UG-General-Info.html#build-u-boot>`__
for more information on building u-boot binaries.


SDK 09.02.01.10
---------------

Linux SDK 09.02 was the last SDK release with LTS Kernel version 6.1 and
u-boot version 2024.x. To pick up the PLL updates on top of this SDK, pick the
components listed below when building the u-boot binaries.


   #. DMSC Firmware

      - Pick up the SDK 10.0 DMSC firmware from tag ``10.00.07`` of ti-linux-firmware repo

         - https://git.ti.com/cgit/processor-firmware/ti-linux-firmware/tag/?h=10.00.07


Refer to `SDK 09.02 u-boot build instructions <https://software-dl.ti.com/processor-sdk-linux/esd/AM64X/09_02_01_10/exports/docs/linux/Foundational_Components/U-Boot/UG-General-Info.html#build-u-boot>`__
for more information on building u-boot binaries.
