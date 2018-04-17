*********************************************************************************
How to enable the PRU Ethernet ports on your AM571x/AM572x IDK board
*********************************************************************************
.. rubric:: Overview
   :name: overview

By default in the Android Processor SDK release, kernel drivers are
configured as built-in modules. However, there is a known issue in the
current PRU driver framework that causes boot delays and loading
failures if the PRU drivers are configured as built-in. For that reason,
the following set of steps must be followed to get the necessary kernel
modules onto the device running Android in order to use the PRU Ethernet
peripherals.

.. rubric:: On the Linux host machine
   :name: on-the-linux-host-machine

Before completing the following steps, it is assumed that you've booted
your board running Android and that the device shows up in the list when
you query for devices using the adb utility: **adb devices**.

#. Navigate to the install directory of the Android Processor SDK
   **cd ~/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/**
#. Build the required Linux driver modules from source
   **make linux**
#. Push the recently built modules to your board running Android using
   adb
   **./bin/adb root**
   **./bin/adb remount**
   **./bin/adb push
   board-support/linux-4.x.yy+gitAUTOINC+zzzzzzzzzz-zzzzzzzzzzz/drivers/remoteproc/pruss\_intc.ko
   /system/lib/modules**
   **./bin/adb push
   board-support/linux-4.x.yy+gitAUTOINC+zzzzzzzzzz-zzzzzzzzzzz/drivers/remoteproc/pruss.ko
   /system/lib/modules**
   **./bin/adb push
   board-support/linux-4.x.yy+gitAUTOINC+zzzzzzzzzz-zzzzzzzzzzz/drivers/remoteproc/pru\_rproc.ko
   /system/lib/modules**
   **./bin/adb push
   board-support/linux-4.x.yy+gitAUTOINC+zzzzzzzzzz-zzzzzzzzzzz/drivers/net/ethernet/ti/prueth.ko
   /system/lib/modules**
   **./bin/adb shell sync**
#. Reboot your board
   **./bin/adb reboot**

.. rubric:: On the Android device terminal
   :name: on-the-android-device-terminal

These steps should be carried out once the kernel modules have been
copied to the /system/lib/modules/ directory and the board has been
rebooted as described in the previous series of steps.

#. Change to the root user
   **su**
#. Bring up the PRU Ethernet port and acquire an IP address (eth3 given
   as an example)
   **dhcpcd eth3**
#. Check the newly acquired IP
   **ifconfig**

.. rubric:: More Information
   :name: more-information

The PRU Ethernet peripherals are only supported on the AM57xx IDK boards
for the Android Processor SDK release. For more information about the
PRU Ethernet implementation please visit
`PRU-ICSS\_Ethernet </index.php/PRU-ICSS_Ethernet>`__. That page is
written for the Linux Processor SDK but the Linux kernel is shared
between the two SDKs so the implementation details on that page will
remain true for Android.

.. raw:: html

