.. http://processors.wiki.ti.com/index.php/GSG:_OMAP35x_DVEVM_Additional_Procedures#Using_Telnet
.. rubric:: Updating/Restoring the Flash Image (From DVSDK version
   3.01.00.01)
   :name: updatingrestoring-the-flash-image-from-dvsdk-version-3.01.00.01

`GSG:\_AM35x\_EVM\_Additional\_Procedures#Updating.2FRestoring\_the\_Flash\_Image </index.php?title=GSG:_AM35x_EVM_Additional_Procedures&action=edit&redlink=1>`__

.. rubric:: Updating/Restoring the Flash Image
   :name: updatingrestoring-the-flash-image

This section describes how to install software images onto the flash
memory on the EVM. This procedure can be used to install an updated
version of the software from TI, to install a customized version built
by the customer or to restore the flash image if it is destroyed or
damaged. This procedure will work even if the flash is completely
erased.

.. rubric:: Requirements
   :name: requirements

-  A Windows PC
-  OMAP35x SDK contents copied from the Linux PC
-  Make a copy of the OMAP35x SDK nfs\_dvsdk\_#\_##\_##\_##.tar.gz and
   rootfs\_dvsdk\_#\_##\_##\_##.jffs2 target file systems under
   AM35x-OMAP35x-PSP-SDK-##.##.##.##/images/fs folder in your windows
   PC.
-  Make sure you perform the changes to the reflash-micron.txt and
   reflash-samsung.txt (depending on the type of memory used) scripts
   under AM35x-OMAP35x-PSP-SDK-##.##.##.##/scripts/omap3530, on your
   Windows PC as mentioned in Section `Running the Re-flash
   Procedure <#Running_the_Re-flash_Procedure>`__, Step 5.1.
-  Make sure you perform the changes to the initenv-micron.txt and
   initenv-samsung.txt (depending on the type of memory used) scripts
   under OMAP35x-PSP-SDK-##.##.##.##/scripts/omap3530, on your Windows
   PC as mentioned in Section `Running the Re-flash
   Procedure <#Running_the_Re-flash_Procedure>`__, Step 6.

.. rubric:: Preparing to Install
   :name: preparing-to-install

If the EVM has an active u-boot, please disable it from booting the
kernel by following the steps given below.

#. Ensure that the host PC is connected to the board via UART as
   mentioned in Section
   `UART1 </index.php/GSG:_OMAP35x_DVEVM_Hardware_Setup#UART1>`__
#. Power On the board. Once you power on the board, the following will
   be printed on the hyperterminal or teraterm.

   ::

       Texas Instruments X-Loader 1.41
       Detected Samsung MuxOneNAND1G Flash
       Starting OS Bootloader...
       U-Boot 1.1.4 (Jun 5 2008 - 17:53:37)
       OMAP3-GP rev 2, CPU-OPP2 L3-165MHz
       OMAP3EVM 1.0 Version + mPOP (Boot ONND)
       DRAM: 128 MB
       OneNAND Manufacturer: Samsung (0xec)
       Muxed OneNAND 128MB 1.8V 16-bit (0x30)
       OneNAND version = 0x0221
       Scanning device for bad blocks
       num of blocks = 2048
       In: serial
       Out: serial
       Err: serial
       Resetting CHIP... Done
       LAN9x18 (0x01150002) detected.
       Setting mac address: 00:50:c2:7e:85:66
       start Auto negotiation... (take ~2sec)
       Auto negotiation complete, 100BaseTX, full duplex

#. Stop the boot process by pressing the Enter key on the development PC
   keyboard. The u-boot prompt will appear.
#. Disable the u-boot from booting the kernel by using the following
   commands at the u-boot prompt.

   ::

       OMAP3EVM # setenv bootcmd echo no boot command configured
       OMAP3EVM # setenv bootdelay 99
       OMAP3EVM # saveenv

   **NOTE: Make sure you follow this step. The download will not work
   and button S2 on the EVM will not operate if the Linux kernel begins
   to boot.**

.. rubric:: Downloading U-boot via the UART Downloader
   :name: downloading-u-boot-via-the-uart-downloader

#. Turn off the EVM by unplugging the power adapter.
#. Close any open terminal programs.
#. Move the serial port cable to UART3.
#. Ensure SW4 is set as described in Section `Main Board
   SW4 </index.php/GSG:_OMAP35x_DVEVM_Hardware_Setup#Main_Board_SW4>`__
#. Start the DownloadUtility.exe program in
   AM35x-OMAP35x-PSP-SDK-##.##.##.##/host-tools/windows/utilities
#. Select the correct COM port
#. Press the “open” button and select the following file:

   -  AM35x-OMAP35x-PSP-SDK-##.##.##.##/images/omap3530/u-boot/u-boot.bin

#. Press the Download button, Press OK on the dialog that say “Press OK
   and reset the target”
#. Power on the EVM
#. If the download does not immediately start, Press S2 on the EVM
#. The download utility (DownloadUtility.exe) should show progress and
   eventually will show “Main Image has been sent”
#. Close Download Utility (DownloadUtility.exe) and restart your
   terminal program. Do not power cycle the EVM.
#. Move the serial cable to UART1 and press enter to get a U-boot prompt

   .. raw:: html

      <div class="center">

   .. raw:: html

      <div class="thumb tnone">

   .. raw:: html

      <div class="thumbinner" style="width:343px;">

   |OMAP3530 EVM GSG Additional information 01.JPG|

   .. raw:: html

      <div class="thumbcaption">

   .. raw:: html

      <div class="magnify">

   ` </index.php/File:OMAP3530_EVM_GSG_Additional_information_01.JPG>`__

   .. raw:: html

      </div>

   .. raw:: html

      </div>

   .. raw:: html

      </div>

   .. raw:: html

      </div>

   .. raw:: html

      </div>

   .. raw:: html

      <div class="center">

   .. raw:: html

      <div class="thumb tnone">

   .. raw:: html

      <div class="thumbinner" style="width:344px;">

   |OMAP3530 EVM GSG Additional information 02.JPG|

   .. raw:: html

      <div class="thumbcaption">

   .. raw:: html

      <div class="magnify">

   ` </index.php/File:OMAP3530_EVM_GSG_Additional_information_02.JPG>`__

   .. raw:: html

      </div>

   .. raw:: html

      </div>

   .. raw:: html

      </div>

   .. raw:: html

      </div>

   .. raw:: html

      </div>

   **NOTE:** If you do not get the uboot prompt on pressing "Enter"
   after connecting the serial port cable to UART1, check if you have
   followed all the above steps properly. If the problem persists, your
   NAND could be corrupted. In the event of NAND corruption, perform
   SD/MMC card boot using the steps mentioned in
   `OMAP35x\_DVEVM\_Boot\_from\_SD/MMC\_card </index.php/OMAP35x_DVEVM_Boot_from_SD/MMC_card>`__
   and erase the NAND using the following command

   ::

       For Micron NAND, 
       OMAP3EVM# nand erase

   ::

       For Samsung OneNAND, 
       OMAP3EVM# onenand erase

.. rubric:: Using U-boot to Update the Flash Memory
   :name: using-u-boot-to-update-the-flash-memory

Now that U-boot is running on the target, you can use it to update any
or all of the software in flash. The steps provided here will use the
Ethernet connection with the TFTP protocol to transfer the files.

.. rubric:: Setup the TFTP Server
   :name: setup-the-tftp-server

This section will describe setting up the TFTP server using a Windows
host. You may also use a Linux TFTP server but that process is not
described here.

The OMAP35x SDK comes with the PumpKIN TFTP server. This program is easy
to setup and can be started and stopped easily.

To setup PumpKIN follow these steps:

#. Start the PumpKIN executable. The first time it is started it should
   show a Window. Subsequent starts may only show in the system tray.
   You may open the window from the right click menu of the system tray
   icon.
#. Hit the Options button and configure the path to the base of the SDK
   directory structure.
#. Select “Allow Access to sub-directories” and “Give all files”
#. Hit OK

.. raw:: html

   <div class="center">

.. raw:: html

   <div class="thumb tnone">

.. raw:: html

   <div class="thumbinner" style="width:502px;">

|OMAP3530 EVM GSG Additional information 03.JPG|

.. raw:: html

   <div class="thumbcaption">

.. raw:: html

   <div class="magnify">

` </index.php/File:OMAP3530_EVM_GSG_Additional_information_03.JPG>`__

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div class="center">

.. raw:: html

   <div class="thumb tnone">

.. raw:: html

   <div class="thumbinner" style="width:139px;">

|OMAP3530 EVM GSG Additional information 04.JPG|

.. raw:: html

   <div class="thumbcaption">

.. raw:: html

   <div class="magnify">

` </index.php/File:OMAP3530_EVM_GSG_Additional_information_04.JPG>`__

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div class="center">

.. raw:: html

   <div class="thumb tnone">

.. raw:: html

   <div class="thumbinner" style="width:502px;">

|OMAP3530 EVM GSG Additional information 05.JPG|

.. raw:: html

   <div class="thumbcaption">

.. raw:: html

   <div class="magnify">

` </index.php/File:OMAP3530_EVM_GSG_Additional_information_05.JPG>`__

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. rubric:: Running the Re-flash Procedure
   :name: running-the-re-flash-procedure

#. Ensure that the terminal program is configured with ~ 100 ms of delay
   after sending each line as described in Section `Setup Terminal
   Program </index.php/GSG:_OMAP35x_DVEVM_Hardware_Setup#Setup_Terminal_Program>`__
#. Ensure the environment is set as appropriate for your EVM and network
   setup

   ::

       OMAP3EVM # setenv ethaddr   00:50:c2:XX:XX:XX   (see sticker on EVM)
       OMAP3EVM # setenv ipaddr    192.168.1.10        (as appropriate)
       OMAP3EVM # setenv serverip  192.168.1.100       (PumpKIN PC’s addr)
       OMAP3EVM # setenv netmask   255.255.255.0       (as appropriate)
       OMAP3EVM # setenv gatewayip 192.168.1.1     (if needed)
       OMAP3EVM # nand unlock                  (ONLY MICRON!)
       OMAP3EVM # saveenv

#. The windows IP address can be obtained using the following steps

   #. Go to Start->Run
   #. Type cmd to open the command window
   #. Type ipconfig on command prompt to get the IP address of the
      Windows host PC

#. Check the IP settings

   ::

       OMAP3EVM # ping $(serverip)                (expect “x.x.x.x is alive”)

#. Use the terminal program to send the text file reflash.txt file to
   the EVM

   #. Make sure you know if your board has Samsung or Micron memory
      parts

      -  See Section `Identifying Board
         Variations </index.php/GSG:_OMAP35x_DVEVM_Overview#Identifying_Board_Variations>`__

   #. path: AM35x-OMAP35x-PSP-SDK-##.##.##.##/scripts/omap3530

      -  reflash-micron.txt (for Micron memory boards)
      -  reflash-samsung.txt (for Samsung memory boards)

      **Note:**\ The scripts are saved in Unix format.If you want to run
      from windows please convert it to dos format using unix2dos
      command in the scripts directory.Usage as given below:

      ::

          unix2dos *

   #. If you need to use these scripts for re-flashing the demos that
      come along with the OMAP3530 DVSDK, the following changes are
      required to be modified in the re-flash scripts. The changes are
      marked in bold. The example is shown for only reflash-samsung.txt.
      Performing similar changes for reflash-micron.txt is needed if
      Micron-NAND OMAP35x EVM is being used.

      ::

          setenv rf_unlock      onenand unlock 0x0 0x8000000
          setenv rf_blank_ram   mw.b 0x81600000 0xff 0x1400000
          setenv rf_er_xloader  onenand erase block 0-3
          setenv rf_er_uboot    onenand erase block 4-18
          setenv rf_er_env      onenand erase block 19-19
          setenv rf_er_kernel   onenand erase block 20-59
          setenv rf_er_ramdisk  onenand erase block 60-1023
          setenv rf_er_fs       onenand erase block 60-1023
          setenv rf_get_xloader tftpboot 0x81600000 images/boot-strap/x-load.bin.ift
          setenv rf_get_uboot   tftpboot 0x81600000 images/u-boot/u-boot.bin
          setenv rf_get_kernel  tftpboot 0x81600000 images/kernel/uImage
          setenv rf_get_ramdisk tftpboot 0x81600000 images/fs/ramdisk.gz
          setenv rf_get_min_rd  tftpboot 0x81600000 images/fs/ramdisk-base.gz
          setenv rf_get_fs      tftpboot 0x81600000 images/fs/rootfs.jffs2
          setenv rf_wr_xloader  onenand write 0x81600000 0x000000 0x0020000
          setenv rf_wr_uboot    onenand write 0x81600000 0x080000 0x0040000
          setenv rf_wr_kernel   onenand write 0x81600000 0x280000 0x0220000
          setenv rf_wr_ramdisk  onenand write 0x81600000 0x780000 0x1000000
          setenv rf_wr_fs       onenand write 0x81600000 0x780000 0x1400000
          setenv rf_ev          run rf_unlock\; run rf_er_env
          setenv rf_xl          run rf_unlock\; run rf_blank_ram\; run rf_er_xloader\; run rf_get_xloader\; run rf_wr_xloader
          setenv rf_ub          run rf_unlock\; run rf_blank_ram\; run rf_er_uboot\; run rf_get_uboot\; run rf_wr_uboot
          setenv rf_kn          run rf_unlock\; run rf_blank_ram\; run rf_er_kernel\; run rf_get_kernel\; run rf_wr_kernel
          setenv rf_rd          run rf_unlock\; run rf_blank_ram\; run rf_er_ramdisk\; run rf_get_ramdisk\; run rf_wr_ramdisk
          setenv rf_min_rd      run rf_unlock\; run rf_blank_ram\; run rf_er_ramdisk\; run rf_get_min_rd\; run rf_wr_ramdisk
          setenv rf_fs          run rf_unlock\; run rf_blank_ram\; run rf_er_fs\; run rf_get_fs\; run rf_wr_fs
          setenv rf_all_rd      run rf_xl\; run rf_ub\; run rf_kn\; run rf_rd
          setenv rf_all_min_rd  run rf_xl\; run rf_ub\; run rf_kn\; run rf_min_rd
          setenv rf_all_fs      run rf_xl\; run rf_ub\; run rf_kn\; run rf_fs
          printenv
          echo done 
          echo Make sure to set MAC address

      If you need to re-flash the target file systems that contains the
      demos that come along with the OMAP3530 DVSDK, or your own target
      file systems, refer section `Flashing the Pre-built/rebuilt NAND
      Flash File
      System <#Flashing_the_Pre-built.2Frebuilt_NAND_Flash_File_System>`__

   #. For HyperTerm use Transfer / Send Text File …
   #. For TeraTerm use File / Send file …
   #. For minicom use the paste file command (Ctrl-A Y)

#. Run the reflash command sequence

   ::

       OMAP3EVM # run rf_all_fs (for jffs file-system)
       OMAP3EVM # run rf_all_rd (for ramdisk)

   (Individual components can be reflashed by using commands like
   rf\_ub, rf\_kn, etc)

   **Note:** For reflashing choices for Micron nand please select the
   commands which are marked by \_new.(For example 'rf\_all\_fs\_new'
   for using JFFS filesystem and 'rf\_all\_rd\_new' for using full
   ramdisk).

   **Note:** Ramdisk should be used for Micron boards as JFFS produces
   warnings and very long boot times.

   **Note:** If the flashed rootfs.jffs2 or the NFS setup uses the
   target file system which is present in the CD , or uses the NFS
   setup, which has demos that have dependency on the CMEM module, then
   the bootargs within the initenv-xxx.txt scripts need to be modified
   as follows. The changes are reflected in bold.

   **The bootargs for DVSDK releases from 3.01.00.09 onwards are as
   given below**

   ::

       setenv bootargs_rd     mem=99M console=ttyS0,115200n8 root=/dev/ram0 initrd=0x81600000,16M ramdisk_size=40960 mpurate=600 omapfb.rotate=1 omapfb.vrfb=y vram=10M omapfb.vram=0:10M omap_vout.vid1_static_vrfb_alloc=y
       setenv bootargs_fs     mem=99M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 mpurate=600 omapfb.rotate=1 omapfb.vrfb=y vram=10M omapfb.vram=0:10M omap_vout.vid1_static_vrfb_alloc=y
       setenv bootargs_nfs    mem=99M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock mpurate=600 omapfb.rotate=1 omapfb.vrfb=y vram=10M omapfb.vram=0:10M omap_vout.vid1_static_vrfb_alloc=y

   **The bootargs for DVSDK releases from 3.01.00.02 onwards are as
   given below**

   ::

       setenv bootargs_rd     mem=100M console=ttyS0,115200n8 root=/dev/ram0 initrd=0x81600000,16M ramdisk_size=40960 mpurate=600 omapfb.rotate=1 omapfb.vrfb=y omap_vout.vid1_static_vrfb_alloc=y
       setenv bootargs_fs     mem=100M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 mpurate=600 omapfb.rotate=1 omapfb.vrfb=y omap_vout.vid1_static_vrfb_alloc=y 
       setenv bootargs_nfs    mem=100M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock mpurate=600 omapfb.rotate=1 omapfb.vrfb=y omap_vout.vid1_static_vrfb_alloc=y

   **The bootargs for DVSDK release 3.00.02.44 is as given below**

   ::

       setenv bootargs_rd     mem=99M console=ttyS0,115200n8 root=/dev/ram0 initrd=0x81600000,16M ramdisk_size=40960 mpurate=600 omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y
       setenv bootargs_fs     mem=99M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 mpurate=600 omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y
       setenv bootargs_nfs    mem=99M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock mpurate=600 omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y 

   **The bootargs for DVSDK releases from 3.00.00.36 up to and including
   3.00.01.42 are as given below**

   ::

       setenv bootargs_rd     mem=88M console=ttyS0,115200n8 root=/dev/ram0 initrd=0x81600000,16M ramdisk_size=40960 omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y
       setenv bootargs_fs     mem=88M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y
       setenv bootargs_nfs    mem=88M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y 

   If the script is not used, use the above appropriate command
   (depending on ramdisk, NAND flash or NFS file system) to set the
   bootargs by using the following command

   For Ramdisk:

   ::

       setenv bootargs ‘bootargs_rd’

   For NFS:

   ::

       setenv bootargs ‘bootargs_nfs’

   For NAND Flash:

   ::

       setenv bootargs ‘bootargs_fs’

   Even if the script is not being used, it is important to set the
   bootargs in u-boot params to use **mem=88M** (in case of DVSDK
   releases from v3.00.00.33 to 3.00.01.42),\ **mem=99M** (in case of
   DVSDK release 3.00.02.44 onwards), **mem=100M** (in case of DVSDK
   v3.01 release) or the appropriate value that is equal to the (size of
   DDR used in OMAP35x EVM – size allocated for CMEM).

#. Reset the board Note: The current U-boot only allows 40 environment
   variables. Do not saveenv after the reflash script has been
   submitted. Instead complete the reflash and reboot before making env
   changes.
#. Use the terminal program to send the text file initenv.txt to the EVM

   #. path: AM35x-OMAP35x-PSP-SDK-##.##.##.##/scripts/omap3530/…

   -  initenv-micron.txt (for Micron memory boards)
   -  initenv-samsung.txt (for Samsung memory boards)

#. Save the environment

   ::

       OMAP3EVM # nand unlock                  (ONLY MICRON!)
       OMAP3EVM # saveenv

#. Reset the board and it should boot into the kernel and file-system

.. rubric:: Using Telnet
   :name: using-telnet

The initialization file (/etc/init.d/rcS) starts a telnet server. If
your development host is in the same sub-net as the EVM, you can telnet
to it using the IP address assigned in the U-boot environment.  The
following is an example from a Linux host.

::

    $ telnet 192.168.1.10

You will be prompted for a user name and password. The user name should
be root and the password should be left blank (just hit Enter).

| 

From a Windows XP host, click the Start button, then click Run... Type
telnet and click OK. This will open a telnet window.

Type "o < ip-addr >" and hit enter.  Example:

::

    Microsoft Telnet> o 128.247.107.12 

Type root for the password and leave the password blank (just hit Enter)

.. rubric:: Booting the New Linux Kernel
   :name: booting-the-new-linux-kernel

After building the new kernel, in order to use it to boot the OMAP35x
EVM, you must transfer it to the board via TFTP. Once you transfer the
kernel image to the board via TFTP, you could either perform a TFTP
kernel boot or flash the kernel image to the NAND and subsequently use
the NAND boot. It is assumed you have completed the steps under
`Rebuilding the Linux
Kernel </index.php/GSG:_OMAP35x_DVEVM_Software_Setup#Rebuilding_the_Linux_Kernel>`__,
and the boot file, uImage has been copied to /tftpboot (or some other
site-specific TFTP accessible location).

.. rubric:: Checking the TFTP server setup in the Linux development PC
   :name: checking-the-tftp-server-setup-in-the-linux-development-pc

You can check to see if a TFTP server is set up with this command

::

    # rpm -q tftp-server

#. To install TFTP, use this command, where -#.#-# is the version number
   portion of the filename:

   ::

       # rpm -ivh /db/ztree/useracct/tftp-server-#.#-#.rpm

#. Confirm that TFTP is installed with this command:

   ::

       # /sbin/chkconfig --list | grep tftp

   You should see the following output:

   ::

       tftp: off

   If you need to turn on the TFTP server, use this command:

   ::

       # /sbin/chkconfig tftp on

   The default root location for servicing TFTP files is /tftpboot.

.. rubric:: Using TFTP to boot the New Linux Kernel
   :name: using-tftp-to-boot-the-new-linux-kernel

#. Power on the EVM board, and abort the automatic boot sequence by
   pressing the “Enter key” in the console window.
#. Set the following environment variables to ensure that you are
   starting from a default, clean U-Boot environment.

   ::

       OMAP3EVM # setenv serverip <tftp server ip address>
       OMAP3EVM # setenv bootfile uImage

   **The bootargs for DVSDK releases from 3.01.00.09 onwards are as
   given below**

   ::

       setenv bootargs mem=99M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 mpurate=600 omapfb.rotate=1 omapfb.vrfb=y vram=10M omapfb.vram=0:10M omap_vout.vid1_static_vrfb_alloc=y

   **The bootargs for DVSDK releases from 3.01.00.02 onwards are as
   given below**

   ::

       setenv bootargs mem=100M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 mpurate=600 omapfb.rotate=1 omapfb.vrfb=y omap_vout.vid1_static_vrfb_alloc=y

   **The bootargs for DVSDK release 3.00.02.44 is as given below**

   ::

       OMAP3EVM # setenv bootargs mem=99M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 mpurate=600 omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y

   **The bootargs for DVSDK releases from 3.00.00.36 up to and including
   3.00.01.42 are as given below**

   ::

       OMAP3EVM # setenv bootargs mem=88M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y

   ::

       OMAP3EVM # setenv bootcmd ‘tftpboot 0x80000000 uImage;bootm’

   This configuration boots a new Linux kernel via TFTP with a NAND
   flash based file system

#. | The initenv-samsung.txt and initenv-micron scripts provide the
     options for setting the bootargs for the appropriate target file
     system that is being used for the boot. Kindly refer to the
     appropriate script files for the flash parts that is being used on
     the board for more details. In case of use of ramdisk file system
     use the following commands:
   | **The bootargs for DVSDK releases from 3.01.00.09 onwards are as
     given below**

   ::

       setenv bootargs mem=99M console=ttyS0,115200n8 root=/dev/ram0 initrd=0x81600000,16M ramdisk_size=40960 mpurate=600 omapfb.rotate=1 omapfb.vrfb=y vram=10M omapfb.vram=0:10M omap_vout.vid1_static_vrfb_alloc=y

   **The bootargs for DVSDK releases from 3.01.00.02 onwards are as
   given below**

   ::

       setenv bootargs mem=100M console=ttyS0,115200n8 root=/dev/ram0 initrd=0x81600000,16M ramdisk_size=40960 mpurate=600 omapfb.rotate=1 omapfb.vrfb=y omap_vout.vid1_static_vrfb_alloc=y

   **The bootargs for DVSDK release 3.00.02.44 is as given below**

   ::

       OMAP3EVM # setenv bootargs mem=99M console=ttyS0,115200n8 root=/dev/ram0 initrd=0x81600000,16M mpurate=600 ramdisk_size=40960 omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y

   **The bootargs for DVSDK releases from 3.00.00.36 up to and including
   3.00.01.42 are as given below**

   ::

       OMAP3EVM # setenv bootargs mem=88M console=ttyS0,115200n8 root=/dev/ram0 initrd=0x81600000,16M ramdisk_size=40960 omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y

   You could use TFTP to transfer the ramdisk image from the development
   PC or flash it on the NAND flash. Refer section 5.4.2, Running the
   Re-flash Procedure for more details on flashing the file systems on
   the target

   **NOTE:** Currently there is no full ramdisk image that includes
   OMAP3530 DVSDK demonstrations.

   In case of use of NFS, use the following commands:

   **The bootargs for DVSDK releases from 3.01.00.09 onwards are as
   given below**

   ::

       setenv bootargs mem=99M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock mpurate=600 omapfb.rotate=1 omapfb.vrfb=y vram=10M omapfb.vram=0:10M omap_vout.vid1_static_vrfb_alloc=y

   **The bootargs for DVSDK releases from 3.01.00.02 onwards are as
   given below**

   ::

       setenv bootargs mem=100M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock mpurate=600 omapfb.rotate=1 omapfb.vrfb=y omap_vout.vid1_static_vrfb_alloc=y

   **The bootargs for DVSDK release 3.00.02.44 is as given below**

   ::

       OMAP3EVM # setenv bootargs    mem=99M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs  nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock mpurate=600 omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y

   **The bootargs for DVSDK releases from 3.00.00.36 up to and including
   3.00.01.42 are as given below**

   ::

       OMAP3EVM # setenv bootargs    mem=88M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs  nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y

.. rubric:: Flashing the New Linux Kernel
   :name: flashing-the-new-linux-kernel

The Linux kernel can also be flashed on the NAND and then could be used
for the boot. Perform the following steps for flashing the new or
rebuilt Linux Kernel

#. Make sure that the environment variables are properly set

   ::

       OMAP3EVM # setenv serverip <tftp server ip address>
       OMAP3EVM # setenv bootfile uImage

#. Flash the Kernel Image onto the Samsung NAND flash using the
   following commands.

   ::

       OMAP3EVM # mw.b 0x81600000 0xff 0x1400000
       OMAP3EVM # onenand erase block 20-59
       OMAP3EVM # tftpboot 0x81600000 uImage
       OMAP3EVM # onenand write 0x81600000 0x280000 0x0300000

#. Flash the Kernel Image onto the Micron NAND flash using the following
   commands.

   ::

       OMAP3EVM # nand unlock
       OMAP3EVM # mw.b 0x81600000 0xff 0x1400000
       OMAP3EVM # nand erase 280000 300000
       OMAP3EVM # tftpboot 0x81600000 uImage
       OMAP3EVM # nandecc sw
       OMAP3EVM # nand write.i 0x81600000 280000 300000

#. Once the image is flashed, refer to `Booting From Flash using Board’s
   NAND Flash File
   System <#Booting_From_Flash_using_Board.E2.80.99s_NAND_Flash_File_System>`__
   or `Booting from Flash Using NFS File
   System <#Booting_from_Flash_Using_NFS_File_System>`__ for booting
   using the kernel image in NAND flash.

.. rubric:: Flashing the Pre-built/rebuilt NAND Flash File System
   :name: flashing-the-pre-builtrebuilt-nand-flash-file-system

Perform the following steps to program the flash for pre-built or a
rebuilt NAND flash file system. The pre-built NAND flash file system
(rootfs.jffs2) for OMAP3530 DVSDK is available under
/home/<useracct>/dvsdk/dvsdk\_#\_##\_##\_##/targetfs folder. Copy it to
the default location for servicing the tftp files on the host PC. (refer
to section `TFTP server setup on Linux
PC <#TFTP_server_setup_on_Linux_PC>`__ or section `Setup the TFTP
Server <#Setup_the_TFTP_Server>`__)

#. Make sure that the environment variables are properly set

   ::

       OMAP3EVM # setenv serverip <tftp server ip address>
       OMAP3EVM # setenv bootfile uImage

#. Flash the NAND flash file system Image onto the Samsung NAND flash
   using the following commands.

   ::

       OMAP3EVM # mw.b 0x81600000 0xff 0x6000000
       OMAP3EVM # onenand erase block 60-1023
       OMAP3EVM # tftpboot 0x81600000 rootfs.jffs2
       OMAP3EVM # onenand write 0x81600000 0x780000 0x6000000

#. Flash the NAND flash file system Image onto the Micron NAND flash
   using the following commands.

   ::

       OMAP3EVM # nand unlock
       OMAP3EVM # mw.b 0x81600000 0xff 0x6000000
       OMAP3EVM # nand erase 780000 6000000
       OMAP3EVM # tftpboot 0x81600000 rootfs.jffs2
       OMAP3EVM # nandecc sw
       OMAP3EVM # nand write.i 0x81600000 780000 6000000

   Once the image is flashed, refer to section `Booting From Flash using
   Board’s NAND Flash File
   System <#Booting_From_Flash_using_Board.E2.80.99s_NAND_Flash_File_System>`__
   or section `Booting via TFTP Using Board’s NAND Flash File
   System <#Booting_via_TFTP_Using_Board.E2.80.99s_NAND_Flash_File_System>`__
   for booting using the NAND flash file system

.. rubric:: Changing Options in U-boot
   :name: changing-options-in-u-boot

If you use the environment provided by the initenv.txt script you have
several choices for boot options. Most of the boilerplate has been
provided; you just need to set your choices.

**Note:** Refer Section `Running the Re-flash
Procedure <#Running_the_Re-flash_Procedure>`__ for modifications in the
initenv.txt script files required to be able to run the dvsdk demos that
comes OMAP3530 DVSDK. Also Refer `Alternate Boot
Methods <#Alternate_Boot_Methods>`__

Kernel choices:

::

    OMAP3EVM # setenv get_kernel run nand_kernel    (get kernel from flash)
    OMAP3EVM # setenv get_kernel run tftp_kernel    (get custom kernel from TFTP)

Initrd choices:

::

    OMAP3EVM # setenv get_initrd run nand_initrd    (get kernel from flash)
    OMAP3EVM # setenv get_initrd run tftp_initrd    (get custom image from TFTP)

File-system choices:

::

    OMAP3EVM # setenv bootcmd    run bootargs_rd        (use an initrd ramdisk)
    OMAP3EVM # setenv bootcmd    run bootargs_fs        (use a JFFS file-system in flash)
    OMAP3EVM # setenv bootcmd    run bootargs_nfs       (use an NFS root directory)

Save your choices:

::

    OMAP3EVM # nand unlock                  (only MICRON!)
    OMAP3EVM # saveenv                  (save to flash)

To run a JFFS file-system or a ramdisk image from flash you need to make
sure the appropriate image is in flash. You can use the reflash.txt
script to load the appropriate image.

Re-flash choices:

::

    OMAP3EVM # run rf_all_rd                (update all using full ramdisk)
    OMAP3EVM # run rf_all_min_rd                (update all using minimal ramdisk)
    OMAP3EVM # run rf_all_fs                (update all using JFFS image)
    OMAP3EVM # run rf_rd                    (update just the full ramdisk)
    OMAP3EVM # run rf_min_rd                (update just the full ramdisk)
    OMAP3EVM # run rf_fs                    (update just the JFFS image)

**Note 1:** The two ramdisk images and JFFS are all mutually exclusive
in Flash as they occupy the same partition. (Running ramdisk from tftp
does not require flash space).

**Note 2:** The current U-boot only allows 40 environment variables. Do
not saveenv after the reflash script has been submitted. Instead
complete the reflash and reboot before making env changes.

**Note 3:** For reflashing choices for Micron nand please select the
commands which are marked by \_new.(For example 'rf\_all\_fs\_new' for
using JFFS filesystem and 'rf\_all\_rd\_new' for using full ramdisk).

.. rubric:: Alternate Boot Methods
   :name: alternate-boot-methods

.. rubric:: Booting From Flash using Board’s NAND Flash File System
   :name: booting-from-flash-using-boards-nand-flash-file-system

This is the default, out-of-the-box boot configuration Make sure that
the kernel image and the JFFS2 root file system is flashed To boot in
this mode, set the following parameters after you abort the automatic
boot sequence:

For Micron NAND EVM:

::

     OMAP3EVM # setenv nand_kernel nand read.i 0x80000000 280000 300000 

For Samsung NAND EVM:

::

     OMAP3EVM # setenv nand_kernel onenand read 0x80000000 0x280000 0x0300000 

Set the following environment variables, irrespective of Micron NAND or
Samsung NAND EVM:

::

    OMAP3EVM # setenv get_kernel run nand_kernel
    OMAP3EVM # setenv bootcmd ‘run get_kernel;bootm 0x80000000’

**The bootargs for DVSDK releases from 3.01.00.09 onwards are as given
below**

::

    OMAP3EVM # setenv bootargs mem=99M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2
               mpurate=600 omapfb.rotate=1 omapfb.vrfb=y vram=10M omapfb.vram=0:10M omap_vout.vid1_static_vrfb_alloc=y

**The bootargs for DVSDK releases from 3.01.00.02 onwards are as given
below**

::

    OMAP3EVM # setenv bootargs mem=100M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2
                              mpurate=600 omapfb.rotate=1 omapfb.vrfb=y omap_vout.vid1_static_vrfb_alloc=y

**The bootargs for DVSDK release 3.00.02.44 is as given below**

::

    OMAP3EVM # setenv bootargs mem=99M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 mpurate=600
                               omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y

::

    OMAP3EVM # boot

**The bootargs for DVSDK releases from 3.00.00.36 up to and including
3.00.01.42 are as given below**

::

    OMAP3EVM # setenv bootargs mem=88M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 
                               omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y

NOTE: All setenv commands should be entered on a single line. They are
shown on multiple lines here for ease of reading.

.. rubric:: Booting from Flash Using NFS File System
   :name: booting-from-flash-using-nfs-file-system

Make sure that the kernel image is flashed. To boot in this mode, set
the following parameters after you abort the automatic boot sequence:

For Micron NAND EVM:

::

     OMAP3EVM # setenv nand_kernel nand read.i 0x80000000 280000 300000 

For Samsung NAND EVM:

::

     OMAP3EVM # setenv nand_kernel onenand read 0x80000000 0x280000 0x0300000 

Set the following environment variables, irrespective of Micron NAND sor
Samsung NAND EVM:

::

    OMAP3EVM # setenv get_kernel      run nand_kernel
    OMAP3EVM # setenv bootcmd ‘run get_kernel;bootm 0x80000000’

**The bootargs for DVSDK releases from 3.01.00.09 onwards are as given
below**

::

    OMAP3EVM # setenv bootargs_nfs mem=99M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs
                               nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock mpurate=600 
                               omapfb.rotate=1 omapfb.vrfb=y vram=10M omapfb.vram=0:10M omap_vout.vid1_static_vrfb_alloc=y

**The bootargs for DVSDK releases from 3.01.00.02 onwards are as given
below**

::

    OMAP3EVM # setenv bootargs_nfs mem=100M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs
                               nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock mpurate=600 
                               omapfb.rotate=1 omapfb.vrfb=y omap_vout.vid1_static_vrfb_alloc=y

**The bootargs for DVSDK release 3.00.02.44 is as given below**

::

    OMAP3EVM # setenv bootargs console=ttyS0,115200n8 noinitrd rw ip=dhcp  root=/dev/nfs nfsroot=<nfshost>:<rootpath>,nolock 
                               mem=99M mpurate=600 omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y

**The bootargs for DVSDK releases from 3.00.00.36 up to and including
3.00.01.42 are as given below**

::

    OMAP3EVM # setenv bootargs console=ttyS0,115200n8 noinitrd rw ip=dhcp  root=/dev/nfs nfsroot=<nfshost>:<rootpath>,nolock 
                               mem=88M omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y

::

    OMAP3EVM # boot

NOTE: All setenv commands should be entered on a single line. They are
shown on multiple lines here for ease of reading.

The <nfshost> shall be set to the ip address of the NFS host machine.
The <rootpath> must match the filesystem that you set up on your
workstation. For example, /home/<useracct>/workdir/filesys

.. rubric:: Booting via TFTP Using Board’s NAND Flash File System
   :name: booting-via-tftp-using-boards-nand-flash-file-system

To boot in this mode, set the following parameters after you abort the
automatic boot sequence:

NOTE: You can find a pre-build kernel image (uImage) in the
OMAP35x-PSP-SDK-##.##.##.##/images/kernel directory.

Make sure to check the tftp server setup on the Linux development host
(Refer `Checking the TFTP server setup in the Linux development
PC <#Checking_the_TFTP_server_setup_in_the_Linux_development_PC>`__)

::

    OMAP3EVM # setenv serverip <tftp server ip address>
    OMAP3EVM # setenv bootfile  <kernel image>
    OMAP3EVM # setenv bootcmd ‘tftpboot 0x80000000 uImage;bootm 0x80000000’ 

**The bootargs for DVSDK releases from 3.01.00.09 onwards are as given
below**

::

    setenv bootargs_fs     mem=99M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 mpurate=600 omapfb.rotate=1 omapfb.vrfb=y vram=10M omapfb.vram=0:10M omap_vout.vid1_static_vrfb_alloc=y

**The bootargs for DVSDK releases from 3.01.00.02 onwards are as given
below**

::

    setenv bootargs_fs     mem=100M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 mpurate=600 omapfb.rotate=1 omapfb.vrfb=y omap_vout.vid1_static_vrfb_alloc=y

**The bootargs for DVSDK release 3.00.02.44 is as given below**

::

    OMAP3EVM # setenv bootargs   mem=99M console=ttyS0,115200n8 noinitrd ip=dhcp root=/dev/mtdblock4 rw rootfstype=jffs2 
                                 mpurate=600 omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y

**The bootargs for DVSDK releases from 3.00.00.36 up to and including
3.00.01.42 are as given below**

::

    OMAP3EVM # setenv bootargs   mem=88M console=ttyS0,115200n8 noinitrd ip=dhcp root=/dev/mtdblock4 rw rootfstype=jffs2 
                                 omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y

::

    OMAP3EVM # boot

NOTE: All setenv commands should be entered on a single line. They are
shown on multiple lines here for ease of reading.

.. rubric:: Booting via TFTP using NFS file system
   :name: booting-via-tftp-using-nfs-file-system

To boot in this mode, set the following parameters after you abort the
automatic boot sequence:

NOTE: You can find a pre-build kernel image (uImage) in the
OMAP35x-PSP-SDK-##.##.##.##/images/kernel directory.

::

    OMAP3EVM # setenv bootcmd 'dhcp;bootm'
    OMAP3EVM # setenv serverip <ip addr of tftp server>
    OMAP3EVM # setenv bootfile <name of kernel image>
    OMAP3EVM # setenv rootpath <root directory to mount>
    OMAP3EVM # setenv nfshost <ip addr of nfs host>

**The bootargs for DVSDK releases from 3.01.00.09 onwards are as given
below**

::

    setenv bootargs_nfs    mem=99M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs
                           nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock mpurate=600 
                           omapfb.rotate=1 omapfb.vrfb=y vram=10M omapfb.vram=0:10M omap_vout.vid1_static_vrfb_alloc=y

**The bootargs for DVSDK releases from 3.01.00.02 onwards are as given
below**

::

    setenv bootargs_nfs    mem=100M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs
                           nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock mpurate=600 
                           omapfb.rotate=1 omapfb.vrfb=y omap_vout.vid1_static_vrfb_alloc=y

**The bootargs for DVSDK releases from 3.00.02.44 onwards are as given
below**

::

    OMAP3EVM # setenv bootargs console=ttyS0,115200n8 noinitrd rw ip=dhcp  root=/dev/nfs nfsroot=$(nfshost):$(rootpath),nolock
                               mem=99M mpurate=600 omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y

**The bootargs for DVSDK releases from 3.00.00.36 up to and including
3.00.01.42 are as given below**

::

    OMAP3EVM # setenv bootargs console=ttyS0,115200n8 noinitrd rw ip=dhcp  root=/dev/nfs nfsroot=$(nfshost):$(rootpath),nolock
                               mem=88M omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y

::

    OMAP3EVM # boot

NOTE: All setenv commands should be entered on a single line. They are
shown on multiple lines here for ease of reading.

The <root directory to mount> must match the file system that you set up
on your workstation. For example, /home/<useracct>/workdir/filesys.

.. rubric:: Working With 256MB Micron mDDR Memory
   :name: working-with-256mb-micron-mddr-memory

| In case the EVM that you have has ES3.1 silicon and 256MB Micron
  memory part, and you wish to utilize the entire 256MB, the bootargs
  need to be changed to create a memory hole.

**In case of DVSDK release 3.01.00.09, perform the following steps**

-  Create a memory hole from 99MB to 128MB for DSP side code and the
   remaining to be visible to the Linux kernel. To enable this, replace
   the **‘mem=99M’** in the bootargs mentioned in the above sections
   with **‘mem=99M@0x80000000 mem=128M@0x88000000’**

-  Make the following change to the loadmodules.sh file

Replace

::

    insmod cmemk.ko phys_start=0x86300000 phys_end=0x87200000 pools=20x4096,8x131072,5x1048576,1x1429440,1x256000,1x3600000,5x829440 

with

::

    insmod cmemk.ko phys_start=0x86300000 phys_end=0x87200000 pools=20x4096,8x131072,5x1048576,1x1429440,1x256000,1x3600000,5x829440 allowOverlap=1 

| 

**In case of DVSDK release 3.01.00.02, perform the following steps**

-  Create a memory hole from 100MB to 128MB for DSP side code and the
   remaining to be visible to the Linux kernel. To enable this, replace
   the **‘mem=100M’** in the bootargs mentioned in the above sections
   with **‘mem=100M@0x80000000 mem=128M@0x88000000’**

-  Make the following change to the loadmodules.sh file

Replace

::

    insmod cmemk.ko phys_start=0x86400000 phys_end=0x87300000 pools=20x4096,8x131072,5x1048576,1x1429440,1x256000,1x3600000,5x829440 

with

::

    insmod cmemk.ko phys_start=0x86400000 phys_end=0x87300000 pools=20x4096,8x131072,5x1048576,1x1429440,1x256000,1x3600000,5x829440 allowOverlap=1 

| 

**In case of DVSDK release 3.00.02.44, perform the following steps**

-  Create a memory hole from 99MB to 128MB for DSP side code and the
   remaining to be visible to the Linux kernel. To enable this, replace
   the **‘mem=99M’** in the bootargs mentioned in the above sections
   with **‘mem=99M@0x80000000 mem=128M@0x88000000’**

-  Make the following change to the loadmodules.sh file

Replace

::

    insmod cmemk.ko phys_start=0x86300000 phys_end=0x87300000 pools=20x4096,8x131072,5x1048576,1x1429440,1x256000,1x3600000,5x829440 

with

::

    insmod cmemk.ko phys_start=0x86300000 phys_end=0x87300000 pools=20x4096,8x131072,5x1048576,1x1429440,1x256000,1x3600000,5x829440 allowOverlap=1 

| 

**In case of DVSDK releases from 3.00.00.33 to 3.00.01.42, perform the
following steps**

-  Create a memory hole from 88MB to 128MB for DSP side code and the
   remaining to be visible to the Linux kernel. To enable this, replace
   the **‘mem=88M’** in the bootargs mentioned in the above sections
   with **‘mem=88M@0x80000000 mem=128M@0x88000000’**

-  Make the following change to the loadmodules.sh file

Replace

::

    insmod cmemk.ko phys_start=0x85800000 phys_end=0x86800000 pools=20x4096,8x131072,5x1048576,1x1429440,1x256000,1x3600000,5x829440

with

::

    insmod cmemk.ko phys_start=0x85800000 phys_end=0x86800000 pools=20x4096,8x131072,5x1048576,1x1429440,1x256000,1x3600000,5x829440 allowOverlap=1

| 

.. rubric:: Putting Demo Applications in the Third-Party Menu
   :name: putting-demo-applications-in-the-third-party-menu

You can add your own demos to the Third-Party Menu by following the
steps in this section. Only four demos can be shown at once in the
user-interface. If you add more than four demos, the first four in
alphabetical order are shown.

#. Create the following files for your demo:

   -  **logo.jpg.** This is the logo of the third party company which
      will be showed next to the demo description. The picture needs to
      be in JPEG format and of size 50x50.
   -  **readme.txt.** This is a text file. The first 40 characters of
      the file should briefly describe the demo. The demo interface
      displays up to 40 characters, but stops if it encounters a new
      line character. For example, the file might contain "Video Phone
      demo" or "Network Audio demo".
   -  **app.sh.** This is an executable that launches your demo. It can
      either be the demo executable itself or a shell script that
      executes the executable. (If this is a shell script, make sure its
      executable bit is set for all). A script could look something
      like:

   ::

       #!/bin/sh
       exec ./mydemoname

   -  **other files.** If app.sh is a shell script, your demo executable
      will have some other name. You may also need to include data files
      or other files used by the executable.

   **Note:** The demo application must use relative paths to access any
   files it needs at runtime. This because the archive is extracted to
   another location from which the demo is executed.

#. Create a gzipped tar file (ends with .tar.gz) that archives all the
   files in the previous list. For example, if your files are logo.jpg,
   readme.txt, and app.sh, you could use the following command:

   ::

       tar cvzf ti_videophone.tar.gz logo.jpg readme.txt app.sh

   Name the tar file using <company>\_<demoname>.tar.gz (with no spaces
   in the file name) as the convention. For example, a video phone demo
   created by Texas Instruments would be named ti\_videophone.tar.gz.
   The name must be unique since all demos are installed in the same
   directory.

   The three required files must be in the top-level directory of the
   archive. Other files may be in subdirectories, so long as the demo
   uses relative references to access them. For example, the following
   directory structure might be used in the archive:

   ::

       |-- app.sh
       |-- data
       |    |-- datafile1
       |    `-- datafile2
       |-- logo.jpg
       `-- readme.txt

   To check the format of the file you create, execute the following
   command in Linux. The result should say "gzip compressed data".

   ::

       file <filename>.tar.gz

#. Put your archive in the "thirdpartydemos" subdirectory of the target
   installation directory. This is where the DVEVM software was
   installed on the target file system. The default target installation
   directory is /opt/dvsdk/omap3530, so the default location for demo
   archives is /opt/dvsdk/omap3530/thirdpartydemos. Do not extract the
   contents of the archive in this location. Extraction is performed
   behind-the-scenes each time the demo is run.

.. rubric:: Changing the Output Display to DVI
   :name: changing-the-output-display-to-dvi

The output display is set by default as LCD.You can change it to DVI
either through Boot Mode Argument for the kernel or command line
arguments once the kernel has booted.

.. rubric:: Boot Mode Arguments for DVI
   :name: boot-mode-arguments-for-dvi

Please add the following commands to the bootargs
'omap-dss.def\_disp="dvi" omapfb.video\_mode="720x480MR-16@60"'

Please note that some versions of the EVM may require a hardware
modification for DVI output to work. You can find information on the
hardware modification required in the `EVM Modifications for DVI-D
output </index.php/GSG:_OMAP35x_DVEVM_Hardware_Setup#EVM_Modifications_for_DVI-D_output>`__
section.

The bootargs mentioned in section `Running the Re-flash
Procedure <#Running_the_Re-flash_Procedure>`__ can be modified as below
for running the pre-built Nand filesystem or NFS filesystem which is
part of the download page.

**The bootargs for DVSDK releases from 3.01.00.09 onwards are as given
below**

::

    setenv bootargs_rd     mem=99M console=ttyS0,115200n8 root=/dev/ram0 initrd=0x81600000,16M ramdisk_size=40960 mpurate=600 omapfb.rotate=1 omapfb.vrfb=y vram=10M omapfb.vram=0:10M omap_vout.vid1_static_vrfb_alloc=y omapfb.mode=dvi:720x480MR-16@60 omapdss.def_disp="dvi"
    setenv bootargs_fs     mem=99M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 mpurate=600 omapfb.rotate=1 omapfb.vrfb=y vram=10M omapfb.vram=0:10M omap_vout.vid1_static_vrfb_alloc=y omapfb.mode=dvi:720x480MR-16@60 omapdss.def_disp="dvi"
    setenv bootargs_nfs    mem=99M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock mpurate=600 omapfb.rotate=1 omapfb.vrfb=y vram=10M omapfb.vram=0:10M omap_vout.vid1_static_vrfb_alloc=y omapfb.mode=dvi:720x480MR-16@60 omapdss.def_disp="dvi"

**The bootargs for DVSDK releases from 3.01.00.02 onwards are as given
below**

::

    setenv bootargs_rd     mem=100M console=ttyS0,115200n8 root=/dev/ram0 initrd=0x81600000,16M ramdisk_size=40960 mpurate=600 omapfb.rotate=1 omapfb.vrfb=y omap_vout.vid1_static_vrfb_alloc=y omapfb.mode=dvi:720x480MR-16@60 omapdss.def_disp="dvi"
    setenv bootargs_fs     mem=100M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 mpurate=600 omapfb.rotate=1 omapfb.vrfb=y omap_vout.vid1_static_vrfb_alloc=y omapfb.mode=dvi:720x480MR-16@60 omapdss.def_disp="dvi"
    setenv bootargs_nfs    mem=100M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock mpurate=600 omapfb.rotate=1 omapfb.vrfb=y omap_vout.vid1_static_vrfb_alloc=y omapfb.mode=dvi:720x480MR-16@60 omapdss.def_disp="dvi"

**The bootargs for DVSDK release 3.00.02.44 is as given below**

::

    setenv bootargs_rd     mem=99M console=ttyS0,115200n8 root=/dev/ram0 initrd=0x81600000,16M ramdisk_size=40960 mpurate=600 omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y omap-dss.def_disp="dvi" omapfb.video_mode="720x480MR-16@60"
    setenv bootargs_fs     mem=99M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 mpurate=600 omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y omap-dss.def_disp="dvi" omapfb.video_mode="720x480MR-16@60"
    setenv bootargs_nfs    mem=99M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock mpurate=600 omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y omap-dss.def_disp="dvi" omapfb.video_mode="720x480MR-16@60"

**The bootargs for DVSDK releases from 3.00.00.36 to 3.00.01.42 are as
given below**

::

    setenv bootargs_rd     mem=88M console=ttyS0,115200n8 root=/dev/ram0 initrd=0x81600000,16M ramdisk_size=40960 omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y omap-dss.def_disp="dvi" omapfb.video_mode="720x480MR-16@60"
    setenv bootargs_fs     mem=88M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y omap-dss.def_disp="dvi" omapfb.video_mode="720x480MR-16@60"
    setenv bootargs_nfs    mem=88M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock omapfb.rotate=1 omapfb.rotate_type=1 omap_vout.vid1_static_vrfb_alloc=y omap-dss.def_disp="dvi" omapfb.video_mode="720x480MR-16@60"

.. rubric:: Command Line Arguments
   :name: command-line-arguments

Once the EVM is booted, you can change the output display from LCD to
DVI from the Linux shell in a terminal window connected to the EVM
board’s serial port.

| **Note:The bootargs for DVSDK releases from 3.01.00.09 onwards
  requires modifications for switching from LCD to DVI using the command
  line at run-time**

| Add the following command **omapfb.mode=dvi:720x480MR-16@60** to the
  bootargs if you intend to switch the display from LCD to DVI during
  run time. This is required for the DVSDK decode demos not to return
  errors at the end of playback or when it returns to the interface
  application.

**For Example,**

::

    setenv bootargs_rd     mem=99M console=ttyS0,115200n8 root=/dev/ram0 initrd=0x81600000,16M ramdisk_size=40960 mpurate=600 omapfb.rotate=1 omapfb.vrfb=y vram=10M omapfb.vram=0:10M omap_vout.vid1_static_vrfb_alloc=y omapfb.mode=dvi:720x480MR-16@60
    setenv bootargs_fs     mem=99M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 mpurate=600 omapfb.rotate=1 omapfb.vrfb=y vram=10M omapfb.vram=0:10M omap_vout.vid1_static_vrfb_alloc=y omapfb.mode=dvi:720x480MR-16@60
    setenv bootargs_nfs    mem=99M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock mpurate=600 omapfb.rotate=1 omapfb.vrfb=y vram=10M omapfb.vram=0:10M omap_vout.vid1_static_vrfb_alloc=y omapfb.mode=dvi:720x480MR-16@60

| **Note:The bootargs for DVSDK releases from 3.01.00.02 onwards
  requires modifications for switching from LCD to DVI using the command
  line at run-time**

| Add the following command **omapfb.mode=dvi:720x480MR-16@60** to the
  bootargs if you intend to switch the display from LCD to DVI during
  run time. This is required for the DVSDK decode demos not to return
  errors at the end of playback or when it returns to the interface
  application.

**For Example,**

::

    setenv bootargs_rd     mem=100M console=ttyS0,115200n8 root=/dev/ram0 initrd=0x81600000,16M ramdisk_size=40960 mpurate=600 omapfb.rotate=1 omapfb.vrfb=y vram=10M omapfb.vram=0:10M omapfb.mode=dvi:720x480MR-16@60
    setenv bootargs_fs     mem=100M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 mpurate=600 omapfb.rotate=1 omapfb.vrfb=y vram=10M omapfb.vram=0:10M omapfb.mode=dvi:720x480MR-16@60
    setenv bootargs_nfs    mem=100M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock mpurate=600 omapfb.rotate=1 omapfb.vrfb=y vram=10M omapfb.vram=0:10M omapfb.mode=dvi:720x480MR-16@60

| **The Commands for DVSDK releases since 3.01.00.02 are to be given as
  below for switching from command line at Run Time**

::

    target $ echo 0 > /sys/devices/platform/omapdss/display0/enabled
    target $ echo "" > /sys/devices/platform/omapdss/manager0/display
    target $ fbset -fb /dev/fb0 -xres 720 -yres 480 -vxres 720 -vyres 480
    target $ echo "dvi" > /sys/devices/platform/omapdss/manager0/display
    target $ echo 1 > /sys/devices/platform/omapdss/display2/enabled
    target $ fbset -fb /dev/fb0 -xres 720 -yres 480 -vxres 720 -vyres 480

**The Commands for DVSDK releases till 3.00.02.44 are to be given as
below for switching from command line at Run Time**

::

    target $ echo "gfx e:0" > /sys/devices/platform/omapfb/overlays
    target $ echo "lcd e:0" > /sys/devices/platform/omapfb/displays
    target $ echo "lcd t:none" > /sys/devices/platform/omapfb/managers
    target $ echo "dvi e:1" > /sys/devices/platform/omapfb/displays
    target $ echo "lcd t:dvi" > /sys/devices/platform/omapfb/managers
    /* Set the Frame buffer parameters like xres, xres_virtual, y_res, yres_virtualagain before running below command. For example for 720P as DVI resolution setxres=1280 yres=720 xres_virtual=1280 yres_virtual=1440.*/
    target $ echo "gfx e:1" > /sys/devices/platform/omapfb/overlays 

.. rubric:: Enabling Audio Capture for Speech encode
   :name: enabling-audio-capture-for-speech-encode

Audio Capture for speech encode is not enabled by default.You can use
amixer utilty which is present by default enable the Audio Capture.

Once the EVM is booted issue following commands to enable Audio Capture.

::

    target $amixer controls
    target $amixer cset name='Analog Left Capture Route AUXL' 1
    target $amixer cset name='Analog Right Capture Route AUXR' 1

::

    target $amixer controls
    amixer cset name='Analog Left AUXL Capture Switch' 1
    amixer cset name='Analog Right AUXR Capture Switch' 1

.. rubric:: Enabling TV Out
   :name: enabling-tv-out

| For enabling S-Video please issue the following command in bootargs
  'omapdss.def\_disp="tv" omapfb.mode=tv:pal'
| **Note :** Please change mode for NTSC as omapfb.mode=tv:ntsc **The
  bootargs for DVSDK releases from 3.01.00.09 onwards are as given
  below**

::

    setenv bootargs_rd     mem=99M console=ttyS0,115200n8 root=/dev/ram0 initrd=0x81600000,16M ramdisk_size=40960 mpurate=600 vram=20M omapfb.vram=0:20M omap_vout.vid1_static_vrfb_alloc=y omapdss.def_disp="tv" omapfb.mode=tv:pal
    setenv bootargs_fs     mem=99M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 mpurate=600 vram=20M omapfb.vram=0:20M omap_vout.vid1_static_vrfb_alloc=y omapdss.def_disp="tv" omapfb.mode=tv:pal
    setenv bootargs_nfs    mem=99M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock mpurate=600 vram=20M omapfb.vram=0:20M omap_vout.vid1_static_vrfb_alloc=y omapdss.def_disp="tv" omapfb.mode=tv:pal

**The bootargs for DVSDK releases from 3.01.00.06 onwards are as given
below**

::

    setenv bootargs_rd     mem=100M console=ttyS0,115200n8 root=/dev/ram0 initrd=0x81600000,16M ramdisk_size=40960 mpurate=600 vram=20M omapfb.vram=0:20M omap_vout.vid1_static_vrfb_alloc=y omapdss.def_disp="tv" omapfb.mode=tv:pal
    setenv bootargs_fs     mem=100M console=ttyS0,115200n8 noinitrd root=/dev/mtdblock4 rw rootfstype=jffs2 mpurate=600 vram=20M omapfb.vram=0:20M omap_vout.vid1_static_vrfb_alloc=y omapdss.def_disp="tv" omapfb.mode=tv:pal
    setenv bootargs_nfs    mem=100M console=ttyS0,115200n8 noinitrd ip=dhcp rw root=/dev/nfs nfsroot=<nfsserver_ip>:/home/<useracct>/workdir/filesys,nolock mpurate=600 vram=20M omapfb.vram=0:20M omap_vout.vid1_static_vrfb_alloc=y omapdss.def_disp="tv" omapfb.mode=tv:pal

| For Enabling Composite out kernel modification has to be done as
  follows.
| **Note:** The option to be selected is given in ""

::

    $host: make menuconfig ARCH=arm CROSS_COMPILE=arm-none-linux-gnueabi-

-  Select Device Drivers from the main menu.

::

       ...
       ...
       Kernel Features --->
       Boot options --->
       CPU Power Management --->
       Floating point emulation --->
       Userspace binary formats --->
       Power management options --->
       [*] Networking support --->
       "Device Drivers --->"
       ...
       ...

-  Select Graphics support from the menu.

::

       ...
       ...
       Sonics Silicon Backplane --->
       Multifunction device drivers --->
       [*] Voltage and Current Regulator Support --->
       <*> Multimedia support --->
       " Graphics support --->"
       <*> Sound card support --->
       [*] HID Devices --->
       [*] USB support --->
       ...
       ...

-  Select Support for frame buffer devices from the menu.

::

       ...
       ...
       <M> Lowlevel video output switch controls
       '''<*> Support for frame buffer devices --->'''   < > E-Ink Broadsheet/Epson S1D13521 controller support
       [ ] Check bootloader initialization
       -*- OMAP2/3 Display Subsystem support (EXPERIMENTAL) --->
       [ ] Backlight & LCD device support --->
       ...
       ...

-  Select OMAP2/3 Display Subsystem support (EXPERIMENTAL) from the same
   menu.

::

       ...
       ...
       <M> Lowlevel video output switch controls
       <*> Support for frame buffer devices --->
       [ ] Check bootloader initialization
       "-*- OMAP2/3 Display Subsystem support (EXPERIMENTAL) --->"
       [ ] Backlight & LCD device support --->
       ...
       ...

-  Select VENC support from the menu.

::

       ...
       ...
       [ ] Debug support
       [ ] RFBI support
       "[*] VENC support"
       "OMAP2_VENC_OUT_TYPE (Use S-Video output interface) --->"
       [ ] SDI support
       ...
       ...

| The default TV out interface is S-Video. change the option to
  Composite.
| **NOTE:**\ Bootargs are same for S-video and composite out.

.. raw:: html

