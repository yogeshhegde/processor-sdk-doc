.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Filesystem

**********************************
Filesystem
**********************************

.. rubric:: Introduction
   :name: introduction

| The Processor SDK Linux provides Filesystem Images that contain
  programs, scripts, Linux user-space components that abstract various
  hardware accelerators available in the SoC. The Filesystem can be
  fully assembled via Yocto, following the instructions
  `Processor\_SDK\_Building\_The\_SDK </index.php/Processor_SDK_Building_The_SDK>`__.

.. rubric:: Filesystem Images
   :name: filesystem-images

There are two filesystem images provided in the SDK. You'll find them at
the SDK Installation directory/filesystem folder.

.. rubric:: arago-base-tisdk-image
   :name: arago-base-tisdk-image

| This is the barebones images, intended to be a starting point for
  users to add packages and create a custom filesystem that suits their
  project needs.

.. rubric:: tisdk-rootfs-image
   :name: tisdk-rootfs-image

This is the complete filesystem image, that contains standard Linux
commands and features. This also contains the TI component libraries,
binaries and out of box examples. For keystone devices (e.g., K2H/K2K,
K2E, K2L, and K2G), two filesystem tarballs are provided due to size
limit of the rootfs ubi image:

-  tisdk-server-rootfs-image-k2g-evm.tar.gz: base filesystem image used
   to create the ubi image.
-  tisdk-server-extra-rootfs-image-k2g-evm.tar.gz: complete filesystem
   image that can be used with NFS and/or SD card (K2G only).

| 

.. rubric:: Key components in the Filesystem
   :name: key-components-in-the-filesystem

.. rubric:: OpenCL, OpenMP, OpenMP Accelerator
   :name: opencl-openmp-openmp-accelerator

| See `OpenCL Runtime
  Documentation <http://downloads.ti.com/mctools/esd/docs/opencl/index.html>`__

.. rubric:: OpenCV with DSP Offload
   :name: opencv-with-dsp-offload

| OpenCV (Open Source Computer Vision Library) provides several hundreds
  of computer vision algorithms with strong focus on real-time
  applications. TI’s OpenCV implementation further offloads
  signal-processing-rich algorithms to DSP for TI's ARM-DSP devices
  (e.g., AM57X, K2H/K2H, K2E, K2L, K2G). Please refer to
  `OpenCV <http://processors.wiki.ti.com/index.php/OpenCV>`__ for more
  details.

.. rubric:: Multimedia
   :name: multimedia

| Multimedia decoding and encoding on IVA (Image and Video Accelerator)
  and video processing on VPE (Video Processing Engine). ARM based
  Gstreamer plugins are provided to abstract the hardware accelerator
  offload. Please refer to `Multimedia
  Training </index.php/Processor_Training:_Multimedia>`__ for details.

.. rubric:: GUI Framework
   :name: gui-framework

QT5 based graphics development tools, demos and libraries are included
in the filesystem on Sitara devices. Please refer to the QT5
Documentation for details.

-  `**QT Reference Documentation** <http://doc.qt.io/qt-5/>`__

| 

.. rubric:: Graphics and Display
   :name: graphics-and-display

| TI Sitara SOCs like AM355x, AM437x and AM57xx are enabled with 3D
  cores, capable of accelerating 3D operations with dedicated hardware
  and the Display Sub-System (DSS). Please refer to the following link
  for Graphics and Display support in details. `Processor Linux SDK
  Graphics and
  Display </index.php/Processor_Linux_SDK_Graphics_and_Display>`__

.. rubric:: Target Compilation
   :name: target-compilation

| 

.. rubric:: Debug
   :name: debug

| gdb, gdbc6x, dsptop

.. rubric:: Out of Box Examples
   :name: out-of-box-examples

| `Processor SDK Linux Example Applications User's
  Guides </index.php/Processor_SDK_Linux_Example_Applications_User%27s_Guides>`__
  lists demo applications and examples available for the platforms
  supported in Processor SDK Linux releases.

.. rubric:: Miscellaneous Documentation
   :name: miscellaneous-documentation

| 

