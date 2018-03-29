.. http://processors.wiki.ti.com/index.php/Cryptography_Users_Guide
.. rubric:: Overview
   :name: overview-cryptography

This article provides a description of the example applications under
the cryptography page of the Matrix application that comes with the
Processor SDK.  This page is labled "Cryptos" in the top-level Matrix GUI.

.. Image:: ../images/MatrixMain.PNG

.. rubric:: Devices Supported
   :name: devices-supported

All Sitara SDK's provide cryptography through OpenSSL, but the following
devices have cryptographic hardware accelerators and drivers:

-  AM3517 - AES, DES, 3DES, SHA, MD5
-  AM37x - AES, DES, 3DES, SHA, MD5
-  AM335x - AES, SHA, MD5, RNG

The example applications have been designed to use hardware accelerators
when they are available and fall back to a pure software implementation
when hardware accelerators are not available.

.. rubric:: Cryptography Examples
   :name: cryptography-examples

All of the examples under the Cryptos page use the OpenSSL command line
application to perform cryptographic functions.  A comprehensive list of
cryptographic functionality using OpenSSL is beyond the scope of the
out-of-box experience intended with the Matrix GUI.  However, the
examples present a nice variety of cryptographic functions that are
available with OpenSSL on the Sitara platform.

.. Image:: ../images/MatrixCryptos.PNG

.. rubric:: OpenSSL Performance
   :name: openssl-performance

This example executes the OpenSSL built-in speed test for a variety of
cryptographic algorithms.  The results of the test are displayed on the
screen and also written to the file OpenSSLspeedResults.txt in the top
level directory of the target filesystem.

.. rubric:: Certificate Generation
   :name: certificate-generation

This example generates a web page certificate for use with a secure web
server.  The certificate is held in the file matrixcert.pem.  This file
will appear in the top level directory of the target file system.  If
the certificate already exists, then the example will fail and prompt
the user to delete the existing certificate (matrixcert.pem) before
generating a new one.

.. rubric:: Public Key Generation
   :name: public-key-generation

This example generates a public key based on the certificate
(matrixcert.pem) generated in the previous example.  If the certificate
does not exist the example will fail and pronpt the user to first
generate the certificate before trying to generate the public key.  The
public key will be saved to a file pubkey.pem in the top level directory
of the target file system.

.. rubric:: Secure Server
   :name: secure-server

Once the web certificate (matrixcert.pem) has been generated, the secure
web server can be started on the target board.  Pointing a modern web
browser at the target should generate a warning that the certificate is
self-signed.  This means that the certificate has not been verified by a
trusted third party such as Verisign.  Depending on the browser, you can
view details of the certificate.  In the example below the target board
has an IP address of 128.247.106.217.  When Internet Explorer is pointed
to the URL https://128.247.106.247:4433 , it first warns the user that
there is a problem with the website's security certificate.  Make sure
that you use http\ **s**:// and the port number :4433 with the IP
address in the URL of the browser.  Clicking the link to continue anyway
provides the page below.  And clicking the "Certificate Error" button at
the top of the page will provide details of the certificate.

.. Image:: ../images/SecureServer.PNG

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
OpenSSL 1.0.0j contains a bug in the secure client code that will crash
the secure server. AMSDK 6.0 is affected by this bug. That patch and
build instructions are
[`[1] <http://processors.wiki.ti.com/index.php/AMSDK_6.0_OpenSSL_1.0.0j_secure_client_patch%7Chere>`__].

.. raw:: html

   </div>

.. rubric:: Certificate Info
   :name: certificate-info

This example simply prints out details of the generated certificate
(matrixcert.pem).

.. rubric:: AES 256
   :name: aes-256

This example will perform an encrypt/decrypt cycle on a 10M file of
random data with the AES 256 algorithm.  The 10M file called rnddata
will be generated if it doesn't already exist.  The result of the
decryption is compared to the original file and the results are
displayed to the screen.

.. rubric:: SHA Hash
   :name: sha-hash

This example will perform a SHA1 hash function on the 10M file of random
data (rnddata).  If the file doesn't exist, it is generated.  The result
of the hash is displayed to the screen.

.. rubric:: Building the Driver
   :name: building-the-driver

For devices with available cryptographic hardware accelerators, a Linux
driver and additionally an OCF kernel module (for OpenSSL) is needed to
access them.  Other devices use the pure software implementation of
OpenSSL for the crypto demos.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
{{{1}}}

.. raw:: html

   </div>

.. rubric:: AM35x/37x, AM335x - AES, SHA/MD5 Drivers
   :name: am35x37x-am335x---aes-shamd5-drivers

Starting with **SDK 5.05.00.00**, the driver for AM335x is completely
integrated into the kernel source.  The pre-built kernel that comes with
the SDK already has the AES and SHA/MD5 drivers built-in to the kernel. 
The kernel configuration has already been set up in the SDK and no
further configuration is needed for the drivers to be built-in to the
kernel.  The configuration of the random number generator does require
an extra step and this is detailedd in the next section.

For reference, the configuration details are shown below.  The
configuration of the AES and SHA/MD5 driver is done under the Hardware
crypto devices sub-menu of the Cryptographic API menu in the kernel
configuration. 

::

    --- Cryptographic API
        [*] Hardware crypto devices --->
            --- Hardware crypto devices
                <*> Support for OMAP4 AES hw engine
                <*> Support for OMAP4 SHA/MD5 hw engine

Messages printed during bootup will indicate that initialization of the
crypto modules has taken place.

::

    [ 1.695495] omap4_aes_mod_init: loading AM33X AES driver
    [ 1.701202] omap4-aes omap4-aes: AM33X AES hw accel rev: 3.02
    [ 1.707733] omap4_aes_probe: probe() done
    [ 1.712402] omap4_sham_mod_init: loading AM33X SHA/MD5 driver
    [ 1.718536] omap4-sham omap4-sham: AM33X SHA/MD5 hw accel rev: 4.03
    [ 1.733276] omap4_sham_probe: probe() done

.. rubric:: Build the OCF kernel module using SDK
   :name: build-the-ocf-kernel-module-using-sdk

For using OpenSSL to access the Crypto Hardware Accelerator Drivers
above, the Open Cryptographic Framework (OCF) is required (can be built
as module). The framework is not officially in the kernel and was ported
to Linux under the name "ocf-linux".  As long as the OCF pieces are
enabled in menuconfig whenever the kernel is built the OCF components
are built during that process.

.. rubric:: Using Cryptographic Hardware Accelerators
   :name: using-cryptographic-hardware-accelerators

.. rubric:: Using the TRNG Hardware Accelerator
   :name: using-the-trng-hardware-accelerator

For the True Random Number Generator (TRNG) in the AM335x there is an
extra step needed in the Linux kernel configuration that needs to be
performed to get the driver included in the kernel.

Use the menuconfig command accroding to the "Customizing the
Configuration" section to get into the configuration menu for the
kernel.

`processors.wiki.ti.com/index.php/AMSDK\_Linux\_User%27s\_Guide#Customizing\_the\_Configuration <http://processors.wiki.ti.com/index.php/AMSDK_Linux_User%27s_Guide#Customizing_the_Configuration>`__

In the configuration menu, scroll down to Device Drivers and hit enter. 
Now scroll to Character devices and hit enter.  

::

     Device Drivers --->
        Character devices --->
            < > Hardware Random Number Generator Core support

Use the spacebar to select the Hardware Random Number Generator support
and also select OMAP4 Random Number Generator support.  The screen
should look like below.

::

            <*> Hardware Random Number Generator Core support
               < > Timer IOMEM HW Random Number Generator support (NEW) 
               <*> OMAP4 Random Number Generator support (NEW) 

Now rebuild the kernel accoring to the User's Guide and boot up the
board with the resulting kernel.  The following message should be part
of the boot-up messages.

::

    [ 0.944152] omap4_rng omap4_rng: OMAP4 Random Number Generator ver. 2.00

Once the system is booted up, the hwrng device should now show up in
the filesystem.

::

    root@am335x-evm:~# ls -l /dev/hwrng
    crw------- 1 root root 10, 183 Jan 1 2000 /dev/hwrng
    root@am335x-evm:~#

Use cat on this device to generate random numbers.

::

    root@am335x-evm:~# cat /dev/hwrng | od -x
    0000000 b2bd ae08 4477 be48 4836 bf64 5d92 01c9
    0000020 0cb6 7ac5 16f9 8616 a483 7dfd 6bf4 3aa5
    0000040 d693 db24 d917 5ee7 feb7 34c3 34e9 e7a5
    0000060 36b7 ea85 fc17 0e66 555c 0934 7a0c 4c69
    0000100 523b 9f21 1546 fddb d58b e5ed 142a 6712
    0000120 8d76 8f80 a6d2 30d8 d107 32bc 7f45 f997
    0000140 9d5d 0d0c f1f0 64f9 a77f 408f b0c1 f5a0
    0000160 39c6 f0ae 4b59 1a76 84a7 a364 8964 f557
    root@am335x-evm:~#

.. rubric:: AES, SHA, TRNG Hardware Accelerators using OpenSSL (requires
   OCF-linux kernel support)
   :name: aes-sha-trng-hardware-accelerators-using-openssl-requires-ocf-linux-kernel-support

The device drivers for AES and SHA/MD5 hardware acceleration is
configured and built into the kernel by default in SDK 5.05.00.00. No
other special setup is needed for OpenSSL to access the crypto modules.

First, the kernel from the SDK must be configured and built according to
the SDK User's Guide.

`processors.wiki.ti.com/index.php/AMSDK\_Linux\_User%27s\_Guide <http://processors.wiki.ti.com/index.php/AMSDK_Linux_User%27s_Guide>`__

The General Purpose (GP) EVMs on TI SoCs allows access to built in
cryptographic accelerators. Inorder to use these drivers from OpenSSL,
the drivers on their own have no contact with userspace. For this, a
special driver is available which abstracts the access to these
accelerators through the Open Cryptographic Framework for Linux
(OCF-Linux).

The demo application under the crypto menu of Matrix will load and use
the OCF driver kernel modules automatically to perform hardware
accelerated crypto functions. The process of manually loading the kernel
modules and using the driver is explained below.

OCF-Linux is itself a special device driver which provides a general
interface for higher level applications such as OpenSSL to access
hardware accelerators.

Kernel modules are required for OCF-linux, OCF cryptosoft and OCF
cryptodev. All these 3 modules are a part of the OCF-linux package.

The filesystem which comes with the SDK comes built with the OCF-Linux
kernel modules and the TI driver which directly accesses the hardware
accelerators is built into the kernel.

From the target boards perspective the drivers are located in the
following directories:

::

    /lib/modules/3.8.4-01427-g1eb3bbb-dirty/kernel/crypto/ocf/cryptosoft.ko
    /lib/modules/3.8.4-01427-g1eb3bbb-dirty/kernel/crypto/ocf/cryptodev.ko
    /lib/modules/3.8.4-01427-g1eb3bbb-dirty/kernel/crypto/ocf/ocf.ko

To use the drivers they must first be installed. Use the insmod command
to install the drivers.  The TI crypto driver allows a parameter to be
passed in to indicate if DMA should be used.  The following log shows
the commands used to install the modules and query the system for the
state of all system modules.

::

    root@am37x-evm:~# lsmod
    Module                  Size  Used by
    cryptosoft             14350  0 
    cryptodev              11962  0 
    ocf                    25277  2 cryptosoft,cryptodev
    root@am37x-evm:~#

After the modules are installed, OpenSSL commands may be executed which
take advantage of the hardware accelerators through the OCF-Linux
driver.  The following example demonstrates the OpenSSL built-in speed
test to demonstrate performance.  The addition of the parameter
**-engine cryptodev** tells OpenSSL to use the OCF-Linux driver if it
exists.

::

    root@am37x-evm:~# openssl speed -evp aes-128-cbc -engine cryptodev
    engine "cryptodev" set.
    Doing aes-128-cbc for 3s on 16 size blocks: 108107 aes-128-cbc's in 0.16s
    Doing aes-128-cbc for 3s on 64 size blocks: 103730 aes-128-cbc's in 0.20s
    Doing aes-128-cbc for 3s on 256 size blocks: 15181 aes-128-cbc's in 0.03s
    Doing aes-128-cbc for 3s on 1024 size blocks: 15879 aes-128-cbc's in 0.03s
    Doing aes-128-cbc for 3s on 8192 size blocks: 4879 aes-128-cbc's in 0.02s
    OpenSSL 1.0.0b 16 Nov 2010
    built on: Thu Jan 20 10:23:44 CST 2011
    options:bn(64,32) rc4(ptr,int) des(idx,risc1,2,long) aes(partial) idea(int) blowfish(idx)
    compiler: arm-none-linux-gnueabi-gcc -march=armv7-a -mtune=cortex-a8 -mfpu=neon -mfloat-abi=softfp -mthumb-interwork -mno-thumb -fPS
    The 'numbers' are in 1000s of bytes per second processed.
    type 16 bytes 64 bytes 256 bytes 1024 bytes 8192 bytes
    aes-128-cbc 10810.70k 33193.60k 129544.53k 542003.20k 1998438.40k
    root@am37x-evm:~#
    root@am37x-evm:~#
    root@am37x-evm:~#

Using the Linux time -v function gives more information about CPU usage
during the test.

::

    root@am37x-evm:~# time -v openssl speed -evp aes-128-cbc -engine cryptodev
    engine "cryptodev" set.
    Doing aes-128-cbc for 3s on 16 size blocks: 108799 aes-128-cbc's in 0.17s
    Doing aes-128-cbc for 3s on 64 size blocks: 102699 aes-128-cbc's in 0.18s
    Doing aes-128-cbc for 3s on 256 size blocks: 16166 aes-128-cbc's in 0.03s
    Doing aes-128-cbc for 3s on 1024 size blocks: 15080 aes-128-cbc's in 0.03s
    Doing aes-128-cbc for 3s on 8192 size blocks: 4838 aes-128-cbc's in 0.03s
    OpenSSL 1.0.0b 16 Nov 2010
    built on: Thu Jan 20 10:23:44 CST 2011
    options:bn(64,32) rc4(ptr,int) des(idx,risc1,2,long) aes(partial) idea(int) blowfish(idx)
    compiler: arm-none-linux-gnueabi-gcc -march=armv7-a -mtune=cortex-a8 -mfpu=neon -mfloat-abi=softfp -mthumb-interwork -mno-thumb -fPS
    The 'numbers' are in 1000s of bytes per second processed.
    type 16 bytes 64 bytes 256 bytes 1024 bytes 8192 bytes
    aes-128-cbc 10239.91k 36515.20k 137949.87k 514730.67k 1321096.53k
    Command being timed: "openssl speed -evp aes-128-cbc -engine cryptodev"
    User time (seconds): 0.46
    System time (seconds): 5.89
    Percent of CPU this job got: 42%
    Elapsed (wall clock) time (h:mm:ss or m:ss): 0m 15.06s
    Average shared text size (kbytes): 0
    Average unshared data size (kbytes): 0
    Average stack size (kbytes): 0
    Average total size (kbytes): 0
    Maximum resident set size (kbytes): 7104
    Average resident set size (kbytes): 0
    Major (requiring I/O) page faults: 0
    Minor (reclaiming a frame) page faults: 479
    Voluntary context switches: 36143
    Involuntary context switches: 211570
    Swaps: 0
    File system inputs: 0
    File system outputs: 0
    Socket messages sent: 0
    Socket messages received: 0
    Signals delivered: 0
    Page size (bytes): 4096
    Exit status: 0

When the cryptodev driver is removed, OpenSSL reverts to the software
implementation of the crypto algorithm.  The performance using the
software only implementation can be compared to the previous test.

::

    root@am37x-evm:~# rmmod cryptodev
    root@am37x-evm:~# time -v openssl speed -evp aes-128-cbc
    Doing aes-128-cbc for 3s on 16 size blocks: 697674 aes-128-cbc's in 2.99s
    Doing aes-128-cbc for 3s on 64 size blocks: 187556 aes-128-cbc's in 3.00s
    Doing aes-128-cbc for 3s on 256 size blocks: 47922 aes-128-cbc's in 3.00s
    Doing aes-128-cbc for 3s on 1024 size blocks: 12049 aes-128-cbc's in 3.00s
    Doing aes-128-cbc for 3s on 8192 size blocks: 1509 aes-128-cbc's in 3.00s
    OpenSSL 1.0.0b 16 Nov 2010
    built on: Thu Jan 20 10:23:44 CST 2011
    options:bn(64,32) rc4(ptr,int) des(idx,risc1,2,long) aes(partial) idea(int) blowfish(idx)
    compiler: arm-none-linux-gnueabi-gcc -march=armv7-a -mtune=cortex-a8 -mfpu=neon -mfloat-abi=softfp -mthumb-interwork -mno-thumb -fPS
    The 'numbers' are in 1000s of bytes per second processed.
    type 16 bytes 64 bytes 256 bytes 1024 bytes 8192 bytes
    aes-128-cbc 3733.37k 4001.19k 4089.34k 4112.73k 4120.58k
    Command being timed: "openssl speed -evp aes-128-cbc"
    User time (seconds): 15.03
    System time (seconds): 0.00
    Percent of CPU this job got: 99%
    Elapsed (wall clock) time (h:mm:ss or m:ss): 0m 15.07s
    Average shared text size (kbytes): 0
    Average unshared data size (kbytes): 0
    Average stack size (kbytes): 0
    Average total size (kbytes): 0
    Maximum resident set size (kbytes): 7216
    Average resident set size (kbytes): 0
    Major (requiring I/O) page faults: 1
    Minor (reclaiming a frame) page faults: 484
    Voluntary context switches: 13
    Involuntary context switches: 35
    Swaps: 0
    File system inputs: 0
    File system outputs: 0
    Socket messages sent: 0
    Socket messages received: 0
    Signals delivered: 0
    Page size (bytes): 4096
    Exit status: 0

.. rubric:: Crypto Performance
   :name: crypto-performance

-  `AM335x Crypto Performance using
   openssl <http://processors.wiki.ti.com/index.php/AM335x_Crypto_Performance>`__

Read `AM3517 performance tests using
cryptotest <http://processors.wiki.ti.com/index.php/Build_Crypto_Module_for_Sitara#Test_the_Module>`__

