.. include:: /_replacevars.rst

**********
Filesystem
**********

The |__SDK_FULL_NAME__| provides Filesystem Images that contain
programs, scripts, Linux user-space components that abstract various
hardware accelerators available in the SoC. The Filesystem can be
fully assembled via Yocto, following the instructions
`Processor\_SDK\_Building\_The\_SDK <Overview_Building_the_SDK.html>`__.

There are different filesystem images provided in the SDK. You'll find them at
the SDK Installation directory/filesystem/ folder.


.. ifconfig:: CONFIG_sdk in ('PLSDK')

    .. rubric:: tisdk-bootstrap-image

    This image is a complete minimal system containing a rootfs and an initrd
    with platform test utilities that can be used for new platform bringup
    activities. Typically one would use the bootstrap initrd till the
    storage media access is debugged, following which one would switch
    over to using the storage media of choice with the same content. This
    image has systemd replaced with sysvinit.

    .. rubric:: tisdk-base-image

    This is the barebones images, intended to be a starting point for
    users to add packages and create a custom filesystem that suits their
    project needs.

    .. rubric:: tisdk-thinlinux-image

    This is a minimal system image enabled with containers to provide
    an environment to start the next level of complex systems up. Depending
    on the platform capabilities, graphics is enabled by default as well.


.. rubric:: tisdk-default-image

This is the complete filesystem image, that contains standard Linux
commands and features. This also contains the TI component libraries,
binaries and out of box examples.

.. ifconfig:: CONFIG_sdk in ('PLSDK')

    .. ifconfig:: CONFIG_part_family in ('General_family')

        For keystone devices (e.g., K2H/K2K,
        K2E, K2L, and K2G), two filesystem tarballs are provided due to size
        limit of the rootfs ubi image:

        -  tisdk-server-rootfs-image-k2g-evm.tar.gz: base filesystem image used
           to create the ubi image.
        -  tisdk-server-extra-rootfs-image-k2g-evm.tar.gz: complete filesystem
           image that can be used with NFS and/or SD card (K2G only).

.. only:: _comment

    [comment] current SDK 7.x build for 'PLSDK' doesn't have docker/tiny image, so comment out the following section

    .. rubric:: tisdk-docker-rootfs-image

    This is a minimal image with support for Docker.
    See `Docker Linux Container Runtime <Foundational_Components/Virtualization/Docker.html>`__ for more information.

    .. rubric:: arago-tiny-image

    This is the absolute minimal filesystem. The boot files are omitted from this
    image and systemd has been replaced with sysvinit.
