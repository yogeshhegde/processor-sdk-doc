*******************************
Migration Guide
*******************************
.. rubric:: Overview
   :name: overview

This page covers migration information for applications built on top
of the Processor SDK for Android.

.. rubric:: Processor SDK Android 05.01.00
   :name: processor-sdk-android-05.01.00

-  This is a maintenance update release of Processor SDK Android for AM57xx
   with Oreo. More details about Oreo can be obtained from
   `here <https://developer.android.com/about/versions/oreo/index.html>`__
-  Multimedia with hardware acceleration is not supported
-  Video decoding up to 720p resolution


.. rubric:: Processor SDK Android 05.00.00
   :name: processor-sdk-android-05.00.00

-  Linux Kernel and U-boot are updated to v4.14 and 2018.01 respectively, while
   the pastry continues to be Android-Oreo
-  More details about Oreo can be obtained from
   `here <https://developer.android.com/about/versions/oreo/index.html>`__
-  SD card creation now creates boot partition only with MLO, u-boot.img,
   and uEnv.txt. After flashing the eMMC device by
   `Running Setup Scripts <Overview.html#run-setup-scripts>`__,
   SD card is required to boot AM57x IDKs. Keep the SD card plugged in,
   power cycle AM57x IDKs to use MLO and u-boot.img from the SD card
   and the rest from the eMMC. For AM57x GP EVM, SD card can be removed
   before the power cycle to boot Android with everything from the eMMC.
-  VPE is not supported

|

.. rubric:: Processor SDK Android 04.03.00
   :name: processor-sdk-android-04.03.00

-  This is a maintenance update release of Processor SDK Android for AM57xx
   with Oreo. More details about Oreo can be obtained from
   `here <https://developer.android.com/about/versions/oreo/index.html>`__

|

.. rubric:: Processor SDK Android 04.02.00
   :name: processor-sdk-android-04.02.00

-  This is the first release of the Processor SDK Android for AM57xx
   with Oreo. Both U-Boot and Android Kernel are the same LTS as prior
   Processor SDK releases, i.e. 2016.05 and 4.4 respectively.
-  More details about Oreo can be obtained from
   `here <https://developer.android.com/about/versions/oreo/index.html>`__
-  See the `Release
   Notes <Release_Specific.html#processor-sdk-android-release-notes>`__ for full
   list of modifications.

| 

.. rubric:: Processor SDK Android 04.01.00
   :name: processor-sdk-linux-04.01.00

-  This is the final release of the Processor SDK Android for AM57xx
   with Marshmallow. The next release will be based on Oreo
-  See the `Release
   Notes <Release_Specific.html#processor-sdk-android-release-notes>`__ for full
   list of modifications.

| 

.. rubric:: Processor SDK Android 04.00.00
   :name: processor-sdk-linux-04.00.00

-  This is the first release of the Processor SDK Android which supports
   AM57xx devices.
-  See the `Release
   Notes <Release_Specific.html#processor-sdk-android-release-notes>`__ for full
   list of modifications.

| 

