How to playback audio over HDMI
===============================

SK-AM62 and SK-AM62A support audio playback over HDMI. This requires shorting a
jumper on the board, and applying an additional DT overlay (.dtbo) file:
``k3-am625-sk-hdmi-audio.dtbo``.

**Steps to enable audio over HDMI:**

#. Toggle the FET switch that shares audio lines between the 3.5mm Jack and
   HDMI connector. For this you have to short the **J24** jumper on the
   SK-AM62, or the **J12** jumper on the SK-AM62A, at the location marked
   below:

    .. Image:: ../../../images/AM62x_HDMI_Audio_Jumper.jpg
            :scale: 10%

#. Follow the `How to enable DT overlays in linux
   <How_to_enable_DT_overlays_in_linux.html>`__ guide for steps on building
   and adding the overlay in your SD card.

    (You may skip this step if the overlay is already present in
    ``/boot/dtb/ti`` under the root partition of your SD card)

#. Enable the HDMI audio overlay by updating the ``name_overlays`` variable in
   the ``uEnv.txt`` file under the BOOT partition on your SD card.

    .. code-block:: text

        name_overlays=ti/k3-am625-sk-hdmi-audio.dtbo

#. Finally, reboot the board and playback a .WAV or raw PCM data using aplay:

    .. code-block:: text

        aplay <path to wav file>

    You can also check out the `Audio Linux Driver Guide
    <../../Foundational_Components/Kernel/Kernel_Drivers/Audio.html>`__ for
    more information on using ``aplay``.


**Note:** To playback or capture audio on 3.5mm jack, you will need to remove
the jumper cable and the overlay from ``uEnv.txt``. Only one of the peripherals
can be used at any given time.
