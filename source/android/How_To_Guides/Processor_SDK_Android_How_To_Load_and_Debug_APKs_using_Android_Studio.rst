************************************************
How to Load and Debug APKs using Android Studio
************************************************
.. rubric:: Introduction
   :name: introduction

Using Android Studio on a TI development board running Android is very
similar to using Android Studio on any other Android based phone or
tablet. This guide will walk through the steps necessary to use Android
Studio to load a provided example onto your TI development board (either
an AM572x GP EVM or an AM57xx IDK + LCD) and run it.

This guide is not meant to replicate Google's documentation for Android
Studio or Android hardware debugging.

.. rubric:: What you will need
   :name: what-you-will-need

At a high level, you will need the following hardware and software:

-  `Android Studio <https://developer.android.com/studio/index.html>`__
-  A TI EVM (AM572x GP EVM or AM57xx IDK + LCD) booted to the Android
   Home Screen with a micro USB cable connected

   -  There is only one micro USB cable on the AM572x GP EVM
   -  You should connect to the micro USB cable on the opposite side of
      the four RJ-45 jacks on the AM57xx IDK boards (the other micro USB
      is for UART/serial and JTAG)
   -  If you are having trouble getting your board booted see the
      `Processor SDK Android Getting Started
      Guide </index.php/Processor_SDK_Android_Getting_Started_Guide>`__

.. rubric:: Put Your Board into Development Mode
   :name: put-your-board-into-development-mode

Go to Apps -> Settings -> About Tablet -> then tap 'Build number' 7
times to put the EVM into Developer Mode. The following screenshots
illustrate the process.

#. Tap the button highlighted below to access the list of installed
   applications
.. Image:: ../images/Screen_home_2.png
#. Tap the settings icon
.. Image:: ../images/Screen_apps.png
#. Tap 'About tablet'
.. Image:: ../images/Screen_settings.png
#. Tap 'Build number' 7 times in a row
.. Image:: ../images/Screen_about_tablet.png
#. After tapping 3 times there will be a pop up on the screen counting
   down the number of taps left to become a developer. On the 7th tap
   you should see the pop up shown below indicating that your board is
   now in development mode.
.. Image:: ../images/Screen_developer_mode.png

| 

.. rubric:: Verify that ADB Sees Your Board
   :name: verify-that-adb-sees-your-board

| This step makes sure that your board is being recognized by the ADB
  server running on your Linux host machine.
| Navigate to the install directory of the Android Processor SDK on your
  Linux host
| **cd ~/ti-processor-sdk-android-am57xx-evm-04.00.00.xx/**
| Use the adb utility in the bin directory to check if your Android
  board is being recognized (remember your board should be booted and
  connected to your Linux host machine using a micro USB cable)
| **./bin/adb devices**
| You should see output similar to this:

::

    List of devices attached
    02006013660e0121        device

If you do not see a device listed, you can try the following things to
get your device to show up:

-  Restart the ADB server on your Linux Host Machine
   **sudo ./bin/adb kill-server**
   **sudo ./bin/adb start-server**
-  Unplug and the replug the micro USB cable between the board and your
   Linux host
-  Reboot your Android board
-  Reflash your Android board

.. rubric:: Import an Example in Android Studio
   :name: import-an-example-in-android-studio

#. Open Android Studio
#. Click File->New->Import Sample...
.. Image:: ../images/Android_Studio_Import_Sample.PNG
#. Scroll down and select the **Basic Gesture Detect** and follow the
   prompts to import the sample
.. Image:: ../images/Android_Studio_Sample_Selection.PNG
#. Once you've imported the sample project it should show up in your
   Project explorer tab and you can browse the source files like this:
.. Image:: ../images/Android_Studio_Project_View.PNG

| 

.. rubric:: Build and Run the Example on your Board
   :name: build-and-run-the-example-on-your-board

#. Click **Run->Run 'Application'** or **Run->Debug 'Application'** to
   build and run/debug your program
.. Image:: ../images/Android_Studio_Run_Debug.PNG
#. Select your device from the **Select Deployment Target** pop up and
   click **OK**
.. Image:: ../images/Android_Studio_Deployment_Target_Select.PNG

| 
| At this point Android Studio will build your project, load it onto
  your board, and then start the application
| This is a screenshot of the application running on the board before
  tapping the screen:
.. Image:: ../images/Screen_gesture_detect_app.png
| This screenshot show that after tapping the screen in the specified
  box, the application records the touches:
.. Image:: ../images/Screen_gesture_detect_app2.png

| 

.. rubric:: More Information
   :name: more-information

You've now built, loaded, and run your first APK on your TI EVM running
the Android Processor SDK! As you've seen, this process works just like
on any other Android enabled device (phone, tablet, etc.). If you would
like more information about Android Studio, or developing Android
applications, please visit `Google's Android Developer
documentation <https://developer.android.com/index.html>`__.

