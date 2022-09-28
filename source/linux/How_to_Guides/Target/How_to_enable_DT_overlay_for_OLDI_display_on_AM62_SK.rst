How to enable DT overlay for OLDI Display on AM62 SK
=====================================================

The Processor SDK (PSDK) Linux supports the OLDI Panels connected on top of the AM62 SK EVMs. These displays can only be enabled with the additional DT overlay (.dtbo) file: ``k3-am625-sk-oldi-panel.dtbo``. The standard wic image does not provide this .dtbo file, but if one does have the panel, the overlay can be compiled from the PSDK linux source tree without any changes.

Supported OLDI Display: **Microtips Technology USA (13-101HIEB0HF0-S) 10.1"  WUXGA (1920x1200) TFT LCD panel**

Other OLDI panels can be supported as well, provided the compatibility with the 40-pin OLDI connector on the EVM. The support can be added in linux via following 2 methods:

#. ``panel-lvds`` DT node that provides all the timing information.
#. ``panel-simple`` DT node along with their timing information appended in the ``panel-simple.c`` linux driver.

The aforementioned Microtips panel has been supported using Method 2, and the ``k3-am625-sk-oldi-panel.dts`` and ``panel-simple.c`` files (in the PSDK linux source tree) can be referenced for adding custom display support.

**Steps to enable OLDI Panel DT overlay:**

#. Flash the SD card with the standard wic image and keep it plugged onto the host machine.
#. On the host machine, build dtbs in the PSDK linux source tree, without any changes.

    ::

        $ make CROSS_COMPILE=aarch64-none-linux-gnu- ARCH=arm64 dtbs

#. If the build is successful, the ``k3-am625-sk-oldi-panel.dtbo`` DT overlay file shall be found as below:

    ::

        $ ls arch/arm64/boot/dts/ti/k3-am625-sk-oldi-panel.dtbo
        arch/arm64/boot/dts/ti/k3-am625-sk-oldi-panel.dtbo

#. Copy this DT overlay file to the boot directory of the root partition of the SD card.

    ::

        $ sudo cp arch/arm64/boot/dts/ti/k3-am625-sk-oldi-panel.dtbo <path-to-sd>/root/boot/

#. Update the ``uEnv.txt`` file to let u-boot recognize the overlay. Add the following code right after the initial comment description about ``uEnv.txt``.

    ::

        name_overlays=k3-am625-sk-oldi-panel.dtbo

#. Unmount and eject the SD card. Plug it on the AM62 SK EVM and power on the EVM.

This will enable the OLDI display connected on top of the AM62 SK EVM.