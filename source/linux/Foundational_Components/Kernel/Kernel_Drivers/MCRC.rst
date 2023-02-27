.. http://processors.wiki.ti.com/index.php/Linux_Core_MCRC_User_Guide

.. include:: /replacevars.rst.inc

MCRC
---------------------------------

.. rubric:: Introduction
   :name: introduction-linux-mcrc

The MCRC driver provides access to the hardware MCRC engine
available on |__PART_FAMILY_DEVICE_NAMES__| devices. This driver is
available as kernel module in the current SDK release.

It supports crc64 Hardware acceleration.

.. rubric:: Building MCRC driver
   :name: building-mcrc-driver

For devices with available MCRC engine, a Linux driver and additionally a
kernel module, user-space interface for hash algorithms is used to access them.
Other devices use the pure software implementation of these crc64 calculations.

.. ifconfig:: CONFIG_mcrc in ('mcrc')

    |__PART_FAMILY_DEVICE_NAMES__| SoCs support a hardware accelerator called
    MCRC engine for crc64 calculations.

The kernel configuration has already been set up in the SDK and no further
configuration is needed for the driver to be built as kernel module.

For reference, the configuration details are shown below. The
configuration of the MCRC driver is done under the
Hardware crypto devices sub-menu of the Cryptographic API menu in the
kernel configuration.

.. ifconfig:: CONFIG_mcrc in ('mcrc')

    .. code-block:: text

	  |Symbol: CRYPTO_DEV_TI_MCRC64 [=m]
	  | Type  : tristate
	  | Defined at drivers/crypto/ti/Kconfig:2
	  |   Prompt: Support for TI MCRC64 crc accelerators
	  |   Depends on: CRYPTO [=y] && CRYPTO_HW [=y] && ARCH_K3 [=y]
	  |   Location:
	  |     -> Cryptographic API (CRYPTO [=y])
	  | (1)   -> Hardware crypto devices (CRYPTO_HW [=y])
	  | Selects: CRYPTO_HASH [=y]

    To check if mcrc module is properly installed,
    run the below command from the Linux command prompt:

    ::

        lsmod | grep mcrc

    Output should show something similar to below:

    ::

        mcrc  20480  0

.. rubric:: Build the algif_hash kernel module using SDK
   :name: build-the-algif_hash-kernel-module-using-sdk

For using user application to access the MCRC Drivers above, the algif_hash
kernel module is required (can be built as module). It is built as part of the
SDK and no further configuration is needed.

algif_hash: User-space interface for hash algorithms

For reference, the configuration details are shown below.

.. code-block:: text

   |Symbol: CRYPTO_USER_API_HASH [=m]
   | Type  : tristate
   | Defined at crypto/Kconfig:1869
   |   Prompt: User-space interface for hash algorithms
   |   Depends on: CRYPTO [=y] && NET [=y]
   |   Location:
   |     -> Cryptographic API (CRYPTO [=y])
   | Selects: CRYPTO_HASH [=y] && CRYPTO_USER_API [=m]


The following shows the command used to query the system for the state of
the algif_hash module. If not already loaded, these modules will get loaded
automatically while running user space application.

    ::

       root@am62xx-evm:~$ lsmod |grep alg
       algif_hash             20480  0
       af_alg                 32768  1 algif_hash

.. rubric:: Working of MCRC controller
   :name: working-of-mcrc-controller

MCRC Controller is a module which is used to perform CRC (Cyclic
Redundancy Check) to verify the integrity of memory system. A signature (CRC)
representing the contents of the memory is obtained when the contents of the
memory are read into MCRC Controller.

Writing the data into 64-bit Signature Register calculates the Signature (CRC).
The 64-bit Signature Register is based on the primitive polynomial to produce
the maximum length LFSR (Linear Feedback Shift Register).

Below is the mathematical representation of used primitive polynomial.

::

   f(x) = x^64 + x^4 + x^3 + x + 1


.. rubric:: Using MCRC engine from user space application
   :name: using-mcrc-engine-from-user-space-application

In order to use MCRC driver from user space, AF_ALG is used.
AF_ALG is User-space interface for Crypto API. Each algorithm type will provide its
own implementation that plugs into af_alg. They're keyed using a string such as
"skcipher" or "hash". The filesystem which comes with the SDK comes built with the
af_alg, algif_hash kernel modules and the TI driver which directly accesses the MCRC
engine is built as kernel module.

The following code is for user-space application to access mcrc engine

::

    #include <unistd.h>
    #include <stdio.h>
    #include <sys/socket.h>
    #include <linux/if_alg.h>
    #include <string.h>

    #define BUFFER_SIZE  8192

    int main (int argc, char **argv) {

        int desc[2] = { -1, -1 };

        struct sockaddr_alg sock = {
            .salg_family = AF_ALG,
            .salg_type   = "hash",
            .salg_name   = "crc64"
        };

        if ((desc[0] = socket(AF_ALG, SOCK_SEQPACKET, 0)) == -1 ) {
            perror("socket");
            return -1;
        }

        if( bind(desc[0], (struct sockaddr *) &sock, sizeof(sock)) != 0 ) {
            perror("bind");
            return -1;
        }

        if( (desc[1] = accept(desc[0], NULL, 0)) == -1 )
            return -1;

        if (argc != 2 || strlen(argv[1]) == 0) {
            printf("Please specify filename\n");
            return -1; // empty string
        }

        FILE* file;
        unsigned char buffer[BUFFER_SIZE];
        file = fopen(argv[1], "rb");
        if(file == NULL)
        {
            printf("An error occured while opening file: %s\n", argv[1]);
            return -1;
        }

        while(!feof(file))
        {
            unsigned int count = fread(buffer, sizeof(char), BUFFER_SIZE, file);
            if(ferror(file))
            {
                printf("An error occurred while accessing the file: %s\n", argv[1]);
                fclose(file);
                return 0;
            }

	    if (send(desc[1], buffer, count, MSG_MORE) != count)
		return -1;
        }

        long int crc64 = 0x0000000000000000;
        if(read(desc[1], &crc64, 8) != 8)
            return -1;

        printf("0x%llx\n", crc64);
        return 0;
    }

Compile the code using below command

::

   cc <filename> -o calculate_crc

Run the executable

::

   ./calculate_crc <path-to-file-for-crc-calculation>

Example

::

   root@am62xx-evm:~$ ./calculate_crc cscope.files
   0xfa68a95edc9f3b45

Using the Linux time function gives more information about CPU usage
during the test.

::

   root@am62xx-evm:~$ time ./calculate_crc cscope.files
   0xfa68a95edc9f3b45

   real    0m0.213s
   user    0m0.000s
   sys     0m0.213s

To verify the result against pycrc module available `here <https://github.com/tpircher/pycrc.git>`_ on host PC.

::

   debian@BeagleBone:~$ time python3 ~/pycrc/src/pycrc.py --width 64 --poly 0x000000000000001b --reflect-in False --xor-in 0x0000000000000000 --reflect-out False --xor-out 0x0000000000000000 --check-file cscope.files
   0xfa68a95edc9f3b45

   real    1m36.405s
   user    1m36.216s
   sys     0m0.052s



.. rubric:: MCRC engine speed testing

Testing using the tcrypt module:

::

   root@am62xx-evm:~$ sudo modprobe tcrypt mode=329 sec=1
   [  542.497394]
   [  542.497394] testing speed of async crc64 (mcrc)
   [  542.503450] tcrypt: test  0 (   16 byte blocks,   16 bytes per update,   1 updates):
   [  543.500041] 869397 opers/sec,  13910352 bytes/sec
   [  543.512573] tcrypt: test  1 (   64 byte blocks,   16 bytes per update,   4 updates): 289782 opers/sec,  18546048 bytes/sec
   [  544.523063] tcrypt: test  2 (   64 byte blocks,   64 bytes per update,   1 updates):
   [  545.519994] 349609 opers/sec,  22374976 bytes/sec
   [  545.532520] tcrypt: test  3 (  256 byte blocks,   16 bytes per update,  16 updates):  82569 opers/sec,  21137664 bytes/sec
   [  546.543023] tcrypt: test  4 (  256 byte blocks,   64 bytes per update,   4 updates):  97018 opers/sec,  24836608 bytes/sec
   [  547.550993] tcrypt: test  5 (  256 byte blocks,  256 bytes per update,   1 updates):
   [  548.547937] 102905 opers/sec,  26343680 bytes/sec
   [  548.560469] tcrypt: test  6 ( 1024 byte blocks,   16 bytes per update,  64 updates):  21393 opers/sec,  21906432 bytes/sec
   [  549.570987] tcrypt: test  7 ( 1024 byte blocks,  256 bytes per update,   4 updates):  26477 opers/sec,  27112448 bytes/sec
   [  550.578949] tcrypt: test  8 ( 1024 byte blocks, 1024 bytes per update,   1 updates):
   [  551.575891]  26936 opers/sec,  27582464 bytes/sec
   [  551.588421] tcrypt: test  9 ( 2048 byte blocks,   16 bytes per update, 128 updates):  10758 opers/sec,  22032384 bytes/sec
   [  552.598909] tcrypt: test 10 ( 2048 byte blocks,  256 bytes per update,   8 updates):  13346 opers/sec,  27332608 bytes/sec
   [  553.606886] tcrypt: test 11 ( 2048 byte blocks, 1024 bytes per update,   2 updates):  13519 opers/sec,  27686912 bytes/sec
   [  554.614877] tcrypt: test 12 ( 2048 byte blocks, 2048 bytes per update,   1 updates):
   [  555.611804]  13581 opers/sec,  27813888 bytes/sec
   [  555.624336] tcrypt: test 13 ( 4096 byte blocks,   16 bytes per update, 256 updates):   5396 opers/sec,  22102016 bytes/sec
   [  556.634909] tcrypt: test 14 ( 4096 byte blocks,  256 bytes per update,  16 updates):   6697 opers/sec,  27430912 bytes/sec
   [  557.642905] tcrypt: test 15 ( 4096 byte blocks, 1024 bytes per update,   4 updates):   6784 opers/sec,  27787264 bytes/sec
   [  558.650786] tcrypt: test 16 ( 4096 byte blocks, 4096 bytes per update,   1 updates):
   [  559.647749]   6815 opers/sec,  27914240 bytes/sec
   [  559.660275] tcrypt: test 17 ( 8192 byte blocks,   16 bytes per update, 512 updates):   2702 opers/sec,  22134784 bytes/sec
   [  560.670880] tcrypt: test 18 ( 8192 byte blocks,  256 bytes per update,  32 updates):   3356 opers/sec,  27492352 bytes/sec
   [  561.678918] tcrypt: test 19 ( 8192 byte blocks, 1024 bytes per update,   8 updates):   3399 opers/sec,  27844608 bytes/sec
   [  562.686812] tcrypt: test 20 ( 8192 byte blocks, 4096 bytes per update,   2 updates):   3412 opers/sec,  27951104 bytes/sec
   [  563.694918] tcrypt: test 21 ( 8192 byte blocks, 8192 bytes per update,   1 updates):
   [  564.691734]   3411 opers/sec,  27942912 bytes/sec
    ...
