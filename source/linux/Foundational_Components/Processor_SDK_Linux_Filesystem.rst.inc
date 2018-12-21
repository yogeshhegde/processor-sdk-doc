.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_Filesystem

**********************************
Filesystem
**********************************

.. rubric:: Introduction
   :name: introduction-linux-fs

| The Processor SDK Linux provides Filesystem Images that contain
  programs, scripts, Linux user-space components that abstract various
  hardware accelerators available in the SoC. The Filesystem can be
  fully assembled via Yocto, following the instructions
  `Processor\_SDK\_Building\_The\_SDK <Overview_Building_the_SDK.html>`__.


.. rubric:: Filesystem Images
   :name: filesystem-images

There are four filesystem images provided in the SDK. You'll find them at
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

.. rubric:: tisdk-docker-rootfs-image
   :name: tisdk-docker-rootfs-image

This is a minimal image with support for Docker.
See `Docker Linux Container Runtime <Foundational_Components_Virtualization.html#docker-linux-container-runtime>`__ for more information.

.. rubric:: arago-tiny-image
   :name: arago-tiny-image

This is the absolute minimal filesystem. The boot files are omitted from this
image and systemd has been replaced with sysvinit.
