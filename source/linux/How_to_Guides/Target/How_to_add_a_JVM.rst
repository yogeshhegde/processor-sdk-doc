.. http://processors.wiki.ti.com/index.php/How_to_add_a_JVM

How to add a JVM
=================================
.. rubric:: Introduction
   :name: introduction

This article shows the steps necessary to add an Oracle Hotspot Java
Virtual Machine (JVM) to your Sitara SDK. Due to the licensing of this
JVM, it can not be delivered with the Sitara SDK. You must download it
and install it separately. Customers wishing to evaluate this JVM should
also investigate and evaluate the Oracle Hotspot license. You must
download the JVM that matches the ABI of the SDK version you are using.
(see Download for more information)

.. rubric:: Download the JVM
   :name: download-the-jvm

#. Select the version that matches your processor.

   -  ARMv7 for Cortex-A8
   -  ARMv5 for ARM9

#. Select a version that matches the ABI of the SDK, either hard float
   or soft float.

   -  Hard float - for SDK 06.00 and later
   -  Soft float - for SDK 05.07 and earlier

#. Select the headless version. To use the full capabilites of the
   headful version, you need to have some windowing support like X11 in
   your filesystem. Sitara SDK currently does not support X11. However
   if you download the headful version, you can run Caffeinemark, but
   you will not be able to use the display capabilites.
#. Before you can download, you have to agree to their license and click
   through a few required inputs.
#. Download the JVM

This can be done from the **Oracle** link:

For soft float:
http://www.oracle.com/technetwork/java/embedded/downloads/javase/index.html

For Early Access Release for the Hard float ABI: link:
https://jdk8.java.net/download.html

.. rubric:: Install the JVM
   :name: install-the-jvm

#. Untar the JVM to your target filesystem. It can go anyplace you want.
   For this wiki we are assuming you install at /home/root

   See this article if you're not sure how to untar
       -  http://www.freebsddiary.org/untar.php

#. Setup your PATH environment variable on your target filesystem to
   point to the location of the "java" executable which can be found in
   the "bin" directory located in the root directory of the JVM.

   to automate setting of the PATH, add the following line to the file:
   /etc/profile (NOTE: for this example version 1.7.0\_04 was used, your
   version may be different)

   ::

       PATH=$PATH:/home/root/ejre1.7.0_04/bin

   add the above line before the following line which is found near the
   bottom of /etc/profile

   ::

       export PATH PS1 OPIEDIR QPEDIR QTDIR EDITOR TERM

#. Now each time you login, your path will be automatically set up to
   include the "java" executable from your installed JVM. By typing
   "java -version", you can verify you are setup correctly.

   -  you should see the JVM version displayed similar to the results
      below. Your version may be different depending on which one you
      downloaded:

::

    root@am335x-evm:~# java -version
    java version "1.7.0_04-ea"
    Java(TM) SE Runtime Environment for Embedded (build 1.7.0_04-ea-b20, headless)
    Java HotSpot(TM) Embedded Client VM (build 23.0-b21, mixed mode)

.. rubric:: Running a benchmark - Pendragon Software's CaffeineMark(tm)
   ver. 3.0
   :name: running-a-benchmark---pendragon-softwares-caffeinemarktm-ver.-3.0

Caffeinemark is a Opensource benchmark which can be downloaded here:
http://www.benchmarkhq.ru/cm30/info.html

#. Download the embedded version to your target file system.
#. To run:

   ::

       java CaffeineMarkEmbeddedApp

#. Benchmark information:

   -  There are 6 tests associated with the Embedded version. Each tests
      runs for about the same amount of time and reports back how many
      iterations of the test could be completed in allocated time
      period. The higher the score the better. There is also an overall
      result which takes in to account all the test results.

.. rubric:: Results for Caffeinemark running on Sitara
   :name: results-for-caffeinemark-running-on-sitara

The following results were performed without independent verification by
Pendragon Software and Pendragon Software makes no representations or
warranties as to the result of the test

.. rubric:: AM37x EVM running with a MPU clock rate of 1GHz
   :name: am37x-evm-running-with-a-mpu-clock-rate-of-1ghz

AM37x EVM achieved a CaffeineMark(tm) 3.0 score of 16046 running on
linux-2.6.37

::

    root@am37x-evm:~/ttt# java CaffeineMarkEmbeddedApp
    Sieve score = 13991 (98)
    Loop score = 29054 (2017)
    Logic score = 24167 (0)
    String score = 8910 (708)
    Float score = 10483 (185)
    Method score = 18603 (166650)
    Overall score = 16046

.. rubric:: AM335x EVM running with a MPU clock rate of 720MHz
   :name: am335x-evm-running-with-a-mpu-clock-rate-of-720mhz

AM335x EVM achieved a CaffeineMark(tm) 3.0 score of 11172 running on
linux-3.2

::

    root@am335x-evm:~/ttt# java CaffeineMarkEmbeddedApp
    Sieve score = 9747 (98)
    Loop score = 20384 (2017)
    Logic score = 17383 (0)
    String score = 6047 (708)
    Float score = 7091 (185)
    Method score = 13136 (166650)
    Overall score = 11172

.. rubric:: AM180x EVM running with a MPU clock rate of 300MHz
   :name: am180x-evm-running-with-a-mpu-clock-rate-of-300mhz

AM180x EVM achieved a CaffeineMark(tm) 3.0 score of 2213 running on
linux-2.6.37

::

    root@am180x-evm:~/CaffieneMark# ../ejre1.7.0_06/bin/java -version
    java version "1.7.0_06"
    Java(TM) SE Embedded Runtime Environment (build 1.7.0_06-b24, headless)
    Java HotSpot(TM) Embedded Client VM (build 23.2-b09, mixed mode)

::

    root@am180x-evm:~/CaffieneMark# ../ejre1.7.0_06/bin/java CaffeineMarkEmbeddedApp
    Sieve score = 2185 (98)
    Loop score = 4852 (2017)
    Logic score = 3624 (0)
    String score = 1533 (708)
    Float score = 570 (185)
    Method score = 3502 (166650)
    Overall score = 2213

