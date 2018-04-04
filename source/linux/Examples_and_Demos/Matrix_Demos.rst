.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Example_Applications_User%27s_Guides
.. rubric:: Applications available by development platform
   :name: applications-available-by-development-platform

There are a number of Example Applications provided within the Processor SDK for Linux. Below are the applications available on each platform and the User's Guides associated with each component.

.. note::
 The example applications below assume that you are using the default pinmux/profile configuration that the board ships with, unless otherwise noted in the individual application's User's Guide

|

.. csv-table::
   :header: "Applications", "AM335x EVM", "AM335x ICE", "AM335x SK","BeagleBone Black","AM437x EVM","AM437x Starter Kit","AM437x IDK","AM572x EVM","AM572x IDK","AM571x IDK","66AK2Hx EVMK2K EVM","K2Ex EVM","66AK2L06 EVM","K2G EVM","OMAP-L138 LCDK","Users Guide","Description"

    Matrix GUI,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,Matrix User's Guide,Provides an overview and details of the graphical user interface (GUI) implementation of the application launcher provided in the Sitara Linux SDK
    Power & Clocks,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,Sitara Power Management User Guide,Provides details of power management features for all supported platforms.
    Multimedia,X,,X,X,X,X,X,X,X,X,,,,,,Multimedia User's Guide,Provides details on implementing ARM/Neon based multimedia using GStreamer pipelines and FFMPEG open source codecs.
    Accelerated Multimedia,,,,,,,,X,X,X,X,X,X,X,,Multimedia Training,Provides details on hardware accelerated (IVAHD/VPE/DSP) multimedia processing using GStreamer pipelines.
    Graphics,X,,X,X,X,X,X,X,X,X,,,,,,Graphics Getting Started Guide,Provides details on hardware accelerated 3D graphics demos.
    OpenCL,,,,,,,,X,X,X,X,X,X,X,,OpenCL Examples,Provides OpenCL example descriptions. Matrix GUI provides two out of box OpenCL demos: Vector Addition and Floating Point Computation.
    Camera,,,,,X,X,X,X,X,X,,,,,,Camera User's Guide,Provides details on how to support smart sensor camera sensor using the Media Controller Framework
    Video Analytics,,,,,,,,X,X,X,,,,,,Video Analytics Demo,Demonstrates the capability of AM57x for video analytics. It builds on Qt and utilizes various IP blocks on AM57x.
    Machine Vision - DLP 3D Scanner,,,,,,,,X,X,X,,,,,,3D Machine Vision Reference Design,Demonstrates the capability of AM57x for DLP 3D scanning.
    Machine Vision - Simple People Tracking,X,,X,X,X,X,X,X,X,X,,,,,,3D TOF Reference Design,Demonstrates the capability of people tracking and detection with TI's ToF (Time-of-Flight) sensor
    Machine Vision - Barcode Reader,X,X,X,X,X,X,X,X,X,X,X,X,X,X,,Barcode Reader,Demonstrates the capability of detecting and decoding barcodes
    USB Profiler,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,NA,
    ARM Benchmarks,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,NA,
    Display,X,,X,,X,X,,X,X,X,,,,,,NA,
    Cryptography,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,Cryptography User's Guide,Provide details on how to implement cryptography through use of OpenSSL and various example applications.
    WLAN and Bluetooth,X,,X,,X,X,,X,,,,,,,,WL127x WLAN and Bluetooth Demos,Provides details on how to enable the WL1271 daughtercard which is connected to the EVM
    QT Demos,X,,X,X,X,X,X,X,X,X,,,,,,NA,"Provides out of box Qt5.4 demos from Matrix GUI, including Calculator, Web Browser, Deform (shows vector deformation in the shape of a lens), and Animated Tiles."
    Web Browser,X,,X,X,X,X,X,X,X,X,,,,,,NA,
    System Settings,X,X,X,X,X,X,X,X,X,X,X,X,X,X,X,NA,
    EVSE Demo,X,,X,X,X,X,X,X,X,X,,,,,,HMI for EV charging infrastructure,Provides out of box demo to showcase Human Machine Interface (HMI) for Electric Vehicle Supply Equipment(EVSE) Charging Stations.
    Protection Relay Demo,X,,X,X,,,,,,,,,,,,,Matrix UI provides out of box demo to showcase Human Machine Interface (HMI) for Protection Relays.

