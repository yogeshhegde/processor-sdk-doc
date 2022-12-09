How to enable DT overlays on AM625 SK
=====================================

The Processor SDK (PSDK) Linux supports the various features in the form of DT overlays connected on top of the AM62 SK EVMs. These features can only be used after enabling their respective DT overlay (.dtbo) files. The standard wic image does not provide this .dtbo file, but if one does have the required hardware, the overlay can be compiled from the PSDK linux source tree without any changes.

The features are:

- CSI based Technexion TEVI-OV5640-\*-RPI - OV5640 camera module
- ECAP capture Mode
- HDMI Audio Playback
- MCAN transceiver
- Microtips Technology USA 10.1"  WUXGA (1920x1200) OLDI panel

Note that the ALINX AN5641 & Digilent PCam 5C - OV5640 camera module DT overlay will be present in the wic image, and steps 3 through 5 can be skipped. Only ``uEnv.txt`` update will be required as shown in step 6.

**Steps to enable DT overlays:**

#. Flash the SD card with the standard wic image.
#. If the SD card got auto-ejected after flashing, re-plug it.
#. On the host machine, build dtbs in the PSDK linux source tree, without any changes.

    ::

        $ make CROSS_COMPILE=aarch64-none-linux-gnu- ARCH=arm64 clean
        $ make CROSS_COMPILE=aarch64-none-linux-gnu- ARCH=arm64 dtbs

#. If the build is successful, the required DT overlay files shall be found as below:

    ::

        $ ls arch/arm64/boot/dts/ti/k3-am625-sk-*.dtbo
        arch/arm64/boot/dts/ti/k3-am625-sk-csi2-ov5640.dtbo
        arch/arm64/boot/dts/ti/k3-am625-sk-csi2-tevi-ov5640.dtbo
        arch/arm64/boot/dts/ti/k3-am625-sk-ecap-capture.dtbo
        arch/arm64/boot/dts/ti/k3-am625-sk-hdmi-audio.dtbo
        arch/arm64/boot/dts/ti/k3-am625-sk-mcan.dtbo
        arch/arm64/boot/dts/ti/k3-am625-sk-oldi-panel.dtbo

#. Copy this DT overlay file to the boot directory of the root partition of the SD card.

    ::

        $ sudo cp arch/arm64/boot/dts/ti/k3-am625-sk-<required-overlay>.dtbo <path-to-sd>/root/boot/

#. Update the ``uEnv.txt`` file to let u-boot recognize the overlay. Depending on the use-case, multiple DT overlays can also be added, using "space" as the delimiter.

    ::

        name_overlays=k3-am625-sk-hdmi-audio.dtbo k3-am625-sk-mcan.dtbo k3-am625-sk-oldi-panel.dtbo

#. Unmount and eject the SD card. Plug it on the AM62 SK EVM and power on the EVM.

This will enable the required overlays on top of the AM62 SK EVM.