.. http://processors.wiki.ti.com/index.php/Processor_Linux_SDK_kernel_FAQs

**Q: Howto let Linux not load kernel modules automatically during system
boot time?**

| **A:** Add the module name into the modprobe blacklist in file
  */etc/modprobe.d/modprobe.conf*. For exmaple,

::

    # cat /etc/modprobe.d/modprobe.conf
    blacklist musb_am335x

**Q: Howto disable a peripheral then enable it again?**

| **A:** Use its driver's bind/unbind sysfs entries. For example, to
  disable rtc on AM57x,

::

    root@dra7xx-evm:~# find /sys -name unbind | grep rtc
    /sys/bus/platform/drivers/omap_rtc/unbind
    root@dra7xx-evm:~# cd /sys/bus/platform/drivers/omap_rtc/
    root@dra7xx-evm:/sys/bus/platform/drivers/omap_rtc# ls
    48838000.rtc  bind          module        uevent        unbind
    root@dra7xx-evm:/sys/bus/platform/drivers/omap_rtc# echo 48838000.rtc > unbind
    root@dra7xx-evm:/sys/bus/platform/drivers/omap_rtc#

to enable it again,

::

    root@dra7xx-evm:/sys/bus/platform/drivers/omap_rtc# echo 48838000.rtc > bind             
    [ 7792.863975] omap_rtc 48838000.rtc: already running
    [ 7792.869822] omap_rtc 48838000.rtc: rtc core: registered 48838000.rtc as rtc1
    root@dra7xx-evm:/sys/bus/platform/drivers/omap_rtc#

**Q: Without SD card in K2H/E, What options are availabe for Keystone-II platforms to boot kernel?**

| **A:** Keystone-2 platforms support the following Kernel boot:
|

   a. Network Boot
      Netowrk Boot is to boot the kernel from network which downloads the kernel, boot monitor,
      and dtb images from TFTP server and uses NFS mounted filesystem. 

      This requires the TFTP and NFS servers set up first. The u-boot scripts assume TFTP and NFS servers are
      on the same system and the IP address is set in "server_ip".

      The prebuilt kernel, boot monitor, and dtb files are located in Processor_SDK/board-support/prebuilt_images folder.
      The filesystem tarballs are the .tar.xz files and in Processor_SDK/filesystem folder.
      It needs to be extracted from the tarball to the NFS mount point, e.g. /nfs/k2e_fs.
      The corresponding NFS mount point needs to be exported on server through /etc/exports.

      To boot from network, the following u-boot environment variables need to be set:

::

      => setenv boot net
      => setenv server_ip <TFTP Server IP address>
      => setenv tftp_root <TFTP root directory where the UBI image is copied to>
      => setenv nfs_root <NFS filesystem mount point>
      => saveenv
      => boot
|

   b. UBI Boot
      UBI boot is the default setting which boots kernel using the UBIFS filesystem on the NAND.
      K2H/E platforms have NAND programmed for out-of-box demo. If the NAND image is corrupted,
      it can be reprogrammed using prebuilt UBI image (.ubi files) in Processor_SDK/filesystem folder.

      Execute the following u-boot scripts to reprogramm the NAND with UBI image:

::

         /* Download the UBI image from TFTP server */
         /* Beware of the UBI image size not to exceed the NAND capacity */
         => setenv server_ip <TFTP Server IP address>
         => setenv name_ubi <the UBI image name>
         => setenv tftp_root <TFTP root directory where the UBI image is copied to>
         => run get_ubi_net
         /* Program NAND with the downloaded image */
         => run burn_ubi
|
|      To boot kernel using UBIFS filesystem on the NAND, the u-boot environment variable "boot" needs to be set to ubi:
|
::

         => setenv boot ubi
         => saveenv
         => boot
|

   c. RAMFS boot
      RAMFS boot is similar to Network boot which downloads kernel, boot monitor, and dtb images from TFTP server.
      The difference from Network boot is that it uses a compressed cpio archive file, not the NFS mounted filesystem through netowrk.
      The cpio archive is downloaded to the Kernel RAM space instead.

      The compressed cpio archive is not included in the Processor SDK, but can be created from the released filesystem.
      The size of released rootfs filesystem has increased beyond 80MB. As a result, special attention need to be on the 
      filesystem size used to create the cpio archive. The filesystem needs to be under 80MB for use with ramfs.

      On the Host machine where the Processor SDK is installed, issue the following commands to create the cpio archive file:

::

         host$ mkdir target_fs
         host$ cd target_fs
         host$ tar xf <Processor_SDK>/filesystem/arago-base-tisdk-image-k2e-evm.tar.xz 
         host$ find . | cpio -H newc -o > ../target_fs.cpio
         host$ cd ..
         host$ gzip target_fs.cpio
         
|
|     The target_fs.cpio.gz file need to be copied to tftp directory and be used for ramfs boot.
|     The u-boot environment variables need to be set as:
|
::

         => setenv boot ramfs
         => setenv server_ip <TFTP Server IP address>
         => setenv tftp_root <TFTP root directory where the UBI image is copied to>
         => setenv name_fs target_fs.cpio.gz
         => saveenv
         => boot
