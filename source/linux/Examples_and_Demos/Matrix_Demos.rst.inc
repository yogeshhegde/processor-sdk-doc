.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Example_Applications_User%27s_Guides
.. rubric:: Applications available by development platform
   :name: applications-available-by-development-platform

There are a number of Example Applications provided within the Processor SDK for Linux. Below are the applications available on each platform and the User's Guides associated with each component.

.. note::
 The example applications below assume that you are using the default pinmux/profile configuration that the board ships with, unless otherwise noted in the individual application's User's Guide

|

.. csv-table::
   :header: "Applications", "`AM335x EVM <http://www.ti.com/tool/tmdxevm3358>`__", "`AM335x ICE <http://www.ti.com/tool/TMDSICE3359>`__", "`AM335x SK <http://www.ti.com/tool/tmdssk3358>`__","`BeagleBone Black <http://beagleboard.org/Products/BeagleBone%20Black>`__","`AM437x EVM <http://www.ti.com/am437xevm>`__","`AM437x Starter Kit <http://www.ti.com/tool/tmdxsk437x>`__","`AM437x IDK <http://www.ti.com/tool/tmdsidk437x>`__","`AM572x EVM <http://www.ti.com/tool/TMDSEVM572X>`__","`AM572x IDK <http://www.ti.com/tool/TMDXIDK5728>`__","`AM571x IDK <http://www.ti.com/tool/TMDXIDK5718>`__","`66AK2Hx EVM <http://www.ti.com/tool/evmk2h>`__ & `K2K EVM <http://www.ti.com/product/tci6638k2k>`__","`K2Ex EVM <http://www.ti.com/tool/xevmk2ex>`__","`66AK2L06 EVM <http://www.ti.com/tool/xevmk2lx>`__","`K2G EVM <http://www.ti.com/tool/EVMK2G>`__","`OMAP-L138 LCDK <http://www.ti.com/tool/tmdslcdk138>`__", "Users Guide","Description"


    Matrix GUI ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,`Matrix User's Guide <Examples_and_Demos.html#matrix-user-guide>`__ ,Provides an overview and details of the graphical user interface (GUI) implementation of the application launcher provided in the Sitara Linux SDK
    Power & Clocks ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,`Sitara Power Management User Guide <Examples_and_Demos.html#power-management>`__ ,Provides details of power management features for all supported platforms.
    Multimedia ,X ,  ,X ,X ,X ,X ,X ,X ,X ,X ,  ,  ,  ,  ,  ,`Multimedia User's Guide <Examples_and_Demos.html#arm-multimedia-users-guide>`__ ,Provides details on implementing ARM/Neon based multimedia using GStreamer pipelines and FFMPEG open source codecs.
    Accelerated Multimedia ,  ,  ,  ,  ,  ,  ,  ,X ,X ,X ,X ,X ,X ,X ,  ,`Multimedia Training <Examples_and_Demos.html#accelerated-multimedia>`__,Provides details on hardware accelerated (IVAHD/VPE/DSP) multimedia processing using GStreamer pipelines.
    Graphics ,X ,  ,X ,X ,X ,X ,X ,X ,X ,X ,  ,  ,  ,  ,  ,`Graphics Getting Started Guide <Examples_and_Demos.html#graphics-and-display>`__ ,Provides details on hardware accelerated 3D graphics demos.
    OpenCL ,  ,  ,  ,  ,  ,  ,  ,X ,X ,X ,X ,X ,X ,X ,  ,`OpenCL Examples <Examples_and_Demos.html#dsp-offload-with-opencl>`__ ,Provides OpenCL example descriptions. Matrix GUI provides two out of box OpenCL demos: Vector Addition and Floating Point Computation.
    Camera ,  ,  ,  ,  ,X ,X ,X ,X ,X ,X ,  ,  ,  ,  ,  ,`Camera User's Guide <Examples_and_Demos.html#camera-users-guide>`__ ,Provides details on how to support smart sensor camera sensor using the Media Controller Framework
    Video Analytics ,  ,  ,  ,  ,  ,  ,  ,X ,X ,X ,  ,  ,  ,  ,  ,`Video Analytics Demo <Examples_and_Demos.html#video-analytics>`__ ,Demonstrates the capability of AM57x for video analytics. It builds on Qt and utilizes various IP blocks on AM57x.
    DLP 3D Scanner ,  ,  ,  ,  ,  ,  ,  ,X ,X ,X ,  ,  ,  ,  ,  ,`3D Machine Vision Reference Design <Examples_and_Demos.html#dlp-3d-scanner>`__ ,Demonstrates the capability of AM57x for DLP 3D scanning.
    Simple People Tracking ,X ,  ,X ,X ,X ,X ,X ,X ,X ,X ,  ,  ,  ,  ,  ,`3D TOF Reference Design <Examples_and_Demos.html#people-tracking>`__ ,Demonstrates the capability of people tracking and detection with TI?s ToF (Time-of-Flight) sensor
    Barcode Reader ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,  ,`Barcode Reader <Examples_and_Demos.html#people-tracking>`__ ,Demonstrates the capability of detecting and decoding barcodes
    USB Profiler ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,NA , 
    ARM Benchmarks ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,NA , 
    Display ,X ,  ,X ,  ,X ,X ,  ,X ,X ,X ,  ,  ,  ,  ,  ,NA , 
    WLAN and Bluetooth ,X ,  ,X ,  ,X ,X ,  ,X ,  ,  ,  ,  ,  ,  ,  ,`WL127x WLAN and Bluetooth Demos <Examples_and_Demos.html#wlan-and-bluetooth>`__ ,Provides details on how to enable the WL1271 daughtercard which is connected to the EVM
    QT Demos ,X ,  ,X ,X ,X ,X ,X ,X ,X ,X ,  ,  ,  ,  ,  ,`Hands on with QT <Examples_and_Demos.html#hands-on-with-qt>`__,"Provides out of box Qt5.4 demos from Matrix GUI, including Calculator, Web Browser, Deform (shows vector deformation in the shape of a lens), and Animated Tiles."
    Web Browser ,X ,  ,X ,X ,X ,X ,X ,X ,X ,X ,  ,  ,  ,  ,  ,NA , 
    System Settings ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,X ,NA , 
    EVSE Demo ,X ,  ,X ,X ,X ,X ,X ,X ,X ,X ,  ,  ,  ,  ,  ,`HMI for EV charging infrastructure <Examples_and_Demos.html#evse-demos>`__ ,Provides out of box demo to showcase Human Machine Interface (HMI) for Electric Vehicle Supply Equipment(EVSE) Charging Stations.
    Protection Relay Demo ,X ,  ,X ,X ,  ,  ,  ,  ,  ,  ,  ,  ,  ,  ,  ,`HMI  for Protection Relay Demo <Examples_and_Demos.html#protection-relay-demo>`__,Matrix UI provides out of box demo to showcase Human Machine Interface (HMI) for Protection Relays.
    Qt5 Thermostat HMI Demo,X ,  ,X ,X ,X ,X ,X ,X ,X ,X ,  ,  ,  ,  ,  ,`Qt5 Thermostat HMI Demo <Examples_and_Demos.html#qt5-thermostat-hmi-demo>`__,Provides out of box Qt5-based HMI for Thermostat
    Deep Learning ,  ,  ,  ,  ,  ,  ,  ,X ,X ,X ,X ,X ,X ,X ,  ,`Vision Deep Learning Examples <Examples_and_Demos.html#tidl-eve-dsp-demo>`__ ,Provides TIDL example descriptions. Matrix GUI provides three out of box TIDL demos: two with precanned video clips and third with live camera input.

