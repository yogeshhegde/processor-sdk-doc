.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_ICSS-EMAC_User_Space
.. rubric:: Overview
   :name: overview

The ICSS\_EMAC (Industrial Communications SubSystem Ethernet Media
Access Controller) driver provides APIs to transmit and receive packets
with a firmware based Ethernet switch that has been implemented on TI’s
PRU-ICSS (Programmable Real-Time Unit Subsystem and Industrial
Communication SubSystem) 32-bit RISC cores. The user space ICSS-EMAC
driver has the same software architecture and features as the `RTOS
ICSS-EMAC <http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_ICSS-EMAC>`__,
but implements the memory access and interrupt handling through Linux
Userspace I/O (UIO) driver.

| 

.. rubric:: Software Stack
   :name: software-stack

The picture below illustrates the software stack of ICSS-EMAC Linux user
space. Majority of the upper layer components are common between RTOS
and Linux user space, with the difference on Linux OS with the UIO
driver vs. RTOS.

| 

.. Image:: ../images/Icss-emac_sw_stack.png

.. rubric:: Memory Access and Interrupt Handling through UIO
   :name: memory-access-and-interrupt-handling-through-uio

While RTOS can directly access memory locations, e.g.,
HW\_RD\_REG32(0x4b220000), Linux needs memory mapping of memory regions
to user space, and this is done using the UIO driver with linux file-I/O
like API such as open(), close(), read(), write(), and etc.

As for the interrupt handling, RTOS registers interrupt service routines
(ISRs) that are triggered when an interrupt occurs, while Linux must
have a thread that waits (read()) on the file descriptor for an
interrupt. Device interrupts are accessed from Linux user-space, and
linux file-I/O like API such as open(), close(), read(), write(), and
etc. are used here also.

The picture below shows how the memory regions and interrupts are
defined in kernel device tree, and how the application/driver can map
and access the memory regions, as well as handle the interrupts through
the UIO driver.

.. Image:: ../images/Icss-emac_uio.png

| 

.. rubric:: Rebuild ICSS-EMAC in Linux User Space
   :name: rebuild-icss-emac-in-linux-user-space

Processor SDK Linux has packaged the pre-built binary for ICSS-EMAC LLD
unit test, which can be found on filesystem at
/usr/bin/icss\_emacMainTest\_[platform].out.

The source code of the ICSS-EMAC LLD and the unit test can be found at
http://git.ti.com/keystone-rtos/icss-emac. The changes specific to Linux
user space can be found by looking for the define of
"\_\_LINUX\_USER\_SPACE". The files to implement the UIO based memory
access and interrupt handling are placed under the test/src/armv7/linux
directory.

When there is need to modify the source code of the ICSS-EMAC LLD and/or
the unit test, the LLD and the unit test can be rebuilt through Yocto
recipes. In order to do so, please refer to `Processor SDK Building The
SDK <http://processors.wiki.ti.com/index.php/Processor_SDK_Building_The_SDK>`__
to set up the build environment, and `Processor SDK Yocto
Recipes <http://processors.wiki.ti.com/index.php/Processor_SDK_Building_The_SDK#Recipes>`__
to bitbake the recipes and install the newly built packages for
icss-emac-lld and icss-emac-lld-test.

For example, the commands below are for rebuilding icss-emac-lld and
icss-emac-lld-test for AM57xx.

::

    MACHINE=am57xx-evm bitbake icss-emac-lld
    MACHINE=am57xx-evm bitbake icss-emac-lld-test

After the bitbake commands above are successfully done, the
icss-emac-lld lib and the icss-emac-lld-test binaries can found from
./build/arago-tmp-external-arm-toolchain/work/am57xx\_evm-linux-gnueabi/icss-emac-lld/<ver\_number>/packages-split/icss-emac-lld/usr/lib
and
./build/arago-tmp-external-arm-toolchain/work/am57xx\_evm-linux-gnueabi/icss-emac-lld-test/<ver\_number>/packages-split/icss-emac-lld-test/usr/bin
directories, respectively.

| 

.. rubric:: Running ICSS-EMAC Unit Test in Linux User Space
   :name: running-icss-emac-unit-test-in-linux-user-space

ICSS-EMAC unit test demonstrates loopback capability by sending dummy
broadcast packets, which are then looped back with loopback plugs (aka loopback cables).
Unit test registers receive packet callback routine with LLD to be
called for RX packet. Call back routine will extract packet received,
perform simple memory comparison against packet sent for integrity
check. Unit test will iterate 10 times for packet transmission and
reception check. It also demonstrates time trigger send (TTS) after
broadcast packets send/receive are completed. At the end of unit test,
"All tests have passed" will be printed on console.


.. note::

  Please note that time trigger send (TTS) is supported for PROCESSOR-SDK-LINUX-RT builds only due to its real-time requirement. Running TTS with PROCESSOR-SDK-LINUX builds can fail with "Packet cyclic timestamp error".


ICSS-EMAC user space driver and unit test are now supported on multiple
TI platforms, including

-  AM335x ICE V2
-  AM437x IDK
-  AM571x IDK
-  AM572x IDK
-  K2G ICE

The sections below describe the procedure and sample logs of running
the ICSS-EMAC unit test on these platforms.

|

.. rubric:: AM335x ICE V2

Before powering up the AM335x ICE V2 EVM, ensure that Pin 2 and Pin 3 of
the two CPSW/ICSS Jumpers are connected. Location of these two jumpers
can be found from
http://processors.wiki.ti.com/index.php/AM335x_Industrial_Communication_Engine_EVM_Rev2_1_HW_User_Guide#Component_Positions.

#. Plug in loopback plugs (aka loopback cables) to the two ICSS-EMAC ports of AM335x ICEv2
   EVM
#. On the filesystem under /boot directory, link
   am335x-icev2-pru-excl-uio.dtb as the default dtb to support PRUSS Ethernet ports, i.e.,
   am335x-icev2-prueth.dtb.
#. Reboot the EVM
#. Run "icss\_emacMainTest\_am335x.out"

| 

.. rubric:: AM437x IDK

#. Plug in loopback plugs (aka loopback cables) to the two ICSS-EMAC ports of AM4 IDK EVM
#. On the filesystem under /boot directory, link
   am437x-idk-pru-excl-uio.dtb as the default dtb file, i.e.,
   am437x-idk-evm.dtb
#. Reboot the EVM
#. Run "icss\_emacMainTest\_am437x.out"

| 

.. rubric:: AM571x IDK

First ensure that Jumper J51 is not placed. That selects between LCD
function (J51 placed) and ICSS1 Ethernet (J51 removed). This also
indicates that ICSS-EMAC unit test cannot run with LCD connected on the
AM571x IDK board.

#. Plug in four loopback plugs (aka loopback cables) to the four ICSS-EMAC ports
#. On the filesystem under /boot directory, link
   am571x-idk-pru-excl-uio.dtb as the default dtb file, e.g.,
   am571x-idk.dtb when using AM571x IDK without LCD display
#. Reboot the EVM
#. Run "icss\_emacMainTest\_am571x.out"

| 

.. rubric:: AM572x IDK

#. Reserve core 1 for the unit test, and this can be done by adding
   "isolcpus=1" in uEnv.txt (under boot partition).
#. On the filesystem under /boot directory, link
   am572x-idk-pru-excl-uio.dtb as the default dtb file, e.g.,
   am572x-idk.dtb.
#. Reboot the EVM.
#. Before running the unit test, open an SSH window to the EVM.
#. From console 1: run "icss\_emacMainTest\_am572x.out". It will display
   a message and wait for the keyboard input.
#. From console 2: set affinity of the unit test process to core 1:
   first find pid from the output log of "ps aux \| grep icss", and then
   run "taskset -p 2 [pid]".
#. From console 1: continue running "icss\_emacMainTest\_am572x.out" by
   pressing any keys.

| 

.. rubric:: K2G ICE
   :name: k2g-ice

#. Plug in loopback plugs (aka loopback cables) to the four ICSS-EMAC ports of K2G ICE EVM
#. On the filesystem under /boot directory, link
   keystone-k2g-ice-pru-excl-uio.dtb as the default dtb file, i.e.,
   keystone-k2g-ice.dtb
#. Reboot the EVM
#. Run "icss\_emacMainTest\_k2g.out"

| 

.. rubric:: Sample Log from AM572x IDK
   :name: sample-log-from-am572x-idk

-  Console 1

::

    root@am57xx-evm:~# icss_emacMainTest_am572x.out
    Set core affinity before continuing the process: taskset -p 2 [pid]
    Enter character:

| 

-  Console 2

::

    root@am57xx-evm:~# ps aux | grep icss
    root      1425  0.0  0.0   1472  1068 ttyS2    S+   18:24   0:00 icss_emacMainTest_am572x.out
    root      1427  0.0  0.0   1968  1100 pts/0    S+   18:30   0:00 grep icss
    root@am57xx-evm:~# taskset -p 2 1425
    pid 1425's current affinity mask: 3
    pid 1425's new affinity mask: 2

| 

-  Console 1 after hitting any key to continue the test:

::

    ICSS_EMAC_testTaskPruss2: ICSS_EMAC_testPgVersion: 0x2
    ICSS_EMAC_testTaskPruss2: PRU2 ETH0: LINK IS UP, eth0 state: 1, link up count: 1
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH0): 0
    ICSS_EMAC_testTaskPruss1(PRU2 ETH0): received pkt: 0
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH0): 1
    ICSS_EMAC_testTaskPruss1(PRU2 ETH0): received pkt: 1
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH0): 2
    ICSS_EMAC_testTaskPruss1(PRU2 ETH0): received pkt: 2
    ICSS_EMAC_testTaskPruss1(PRU2 ETH0): received pkt: 3
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH0): 3
    ICSS_EMAC_testTaskPruss1(PRU2 ETH0): received pkt: 4
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH0): 4
    ICSS_EMAC_testTaskPruss1(PRU2 ETH0): received pkt: 5
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH0): 5
    ICSS_EMAC_testTaskPruss1(PRU2 ETH0): received pkt: 6
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH0): 6
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH0): 7
    ICSS_EMAC_testTaskPruss1(PRU2 ETH0): received pkt: 7
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH0): 8
    ICSS_EMAC_testTaskPruss1(PRU2 ETH0): received pkt: 8
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH0): 9
    ICSS_EMAC_testTaskPruss1(PRU2 ETH0): received pkt: 9
    ICSS_EMAC_testTaskPruss2: PRU2 ETH1: LINK IS UP, eth0 state: 1, link up count: 2
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH1): 0
    ICSS_EMAC_testTaskPruss1(PRU2 ETH1): received pkt: 10
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH1): 1
    ICSS_EMAC_testTaskPruss1(PRU2 ETH1): received pkt: 11
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH1): 2
    ICSS_EMAC_testTaskPruss1(PRU2 ETH1): received pkt: 12
    ICSS_EMAC_testTaskPruss1(PRU2 ETH1): received pkt: 13
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH1): 3
    ICSS_EMAC_testTaskPruss1(PRU2 ETH1): received pkt: 14
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH1): 4
    ICSS_EMAC_testTaskPruss1(PRU2 ETH1): received pkt: 15
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH1): 5
    ICSS_EMAC_testTaskPruss1(PRU2 ETH1): received pkt: 16
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH1): 6
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH1): 7
    ICSS_EMAC_testTaskPruss1(PRU2 ETH1): received pkt: 17
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH1): 8
    ICSS_EMAC_testTaskPruss1(PRU2 ETH1): received pkt: 18
    packet transmission complete for packet(ICSS_EMAC_TEST_PRU2ETH1): 9
    ICSS_EMAC_testTaskPruss1(PRU2 ETH1): received pkt: 19

    ============================================================
    Initiating TTS tests on ICSS_EMAC_TEST_PRU2ETH0 and ICSS_EMAC_TEST_PRU2ETH1
    ============================================================
    TTS Port 1: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 799999 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS Port 2: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 799999 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS Port 1: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 800000 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS Port 2: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 799999 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS Port 1: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 799999 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS Port 2: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 799999 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS Port 1: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 799999 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS Port 2: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 799999 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS Port 1: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 799999 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS Port 2: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 799999 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS Port 1: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 799999 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS Port 2: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 799999 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS Port 1: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 799999 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS Port 2: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 799999 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS Port 1: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 800000 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS Port 2: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 800000 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS Port 1: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 800000 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS Port 2: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 800000 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS Port 1: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 800000 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS Port 2: Test Passed!!
    Programmed Cycle Period: 800000 ns
    Average Cycle Period: 800000 ns
    Maximum Jitter: 40 ns
    ============================================================
    TTS tests finished on ICSS_EMAC_TEST_PRU2ETH0 and ICSS_EMAC_TEST_PRU2ETH1
    ============================================================
    Done with PRU-ICSS Instance 2 Testing

    PRU-ICSS STATS for PRU2ETH0
    txBcast:0xa
    txMcast:0x18a88
    txUcast:0x0
    txOctets:0x789d80
    rxBcast:0xa
    rxMcast:0x18a88
    rxUcast:0x0
    rxOctets:0x789d80
    tx64byte:0x186aa
    tx65_127byte:0x0
    tx128_255byte:0x0
    tx512_1023byte:0x0
    tx1024byte:0x3e8
    rx64byte:0x186aa
    rx65_127byte:0x0
    rx128_255byte:0x0
    rx512_1023byte:0x0
    rx1024byte:0x3e8
    lateColl:0x0
    singleColl:0x0
    multiColl:0x0
    excessColl:0x0
    rxMisAlignmentFrames:0x0
    stormPrevCounter:0x0
    macRxError:0x0
    SFDError:0x0
    defTx:0x0
    macTxError:0x0
    rxOverSizedFrames:0x0
    rxUnderSizedFrames:0x0
    rxCRCFrames:0x0
    droppedPackets:0x0
    txOverFlow:0x0
    txUnderFlow:0x0
    sqeTestError:0x0
    TXqueueLevel:0x0
    CSError:0x0


    PRU-ICSS STATS for PRU2ETH1
    txBcast:0xa
    txMcast:0x18a88
    txUcast:0x0
    txOctets:0x789d80
    rxBcast:0xa
    rxMcast:0x18a88
    rxUcast:0x0
    rxOctets:0x789d80
    tx64byte:0x186aa
    tx65_127byte:0x0
    tx128_255byte:0x0
    tx512_1023byte:0x0
    tx1024byte:0x3e8
    rx64byte:0x186aa
    rx65_127byte:0x0
    rx128_255byte:0x0
    rx512_1023byte:0x0
    rx1024byte:0x3e8
    lateColl:0x0
    singleColl:0x0
    multiColl:0x0
    excessColl:0x0
    rxMisAlignmentFrames:0x0
    stormPrevCounter:0x0
    macRxError:0x0
    SFDError:0x0
    defTx:0x0
    macTxError:0x0
    rxOverSizedFrames:0x0
    rxUnderSizedFrames:0x0
    rxCRCFrames:0x0
    droppedPackets:0x0
    txOverFlow:0x0
    txUnderFlow:0x0
    sqeTestError:0x0
    TXqueueLevel:0x0
    CSError:0x0

    All tests have passed

