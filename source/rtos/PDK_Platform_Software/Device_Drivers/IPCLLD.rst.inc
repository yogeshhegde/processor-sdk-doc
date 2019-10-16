.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_IPCLLD

Overview
-----------


TI Jacinto7/AM65XX family of devices consists of many cores - ARM53/72, R5Fs (MCU or Main Domain) and/or DSPs (C66x / C7x). The actual cores varies with actual device. Refer to datasheet of the device for actual cores present on soc. Inter-Processor Communication (IPC) provides communication channel between various cores. IPCLLD is low-level driver for IPC which provides core-agnostic and OS-agnostic framework for communication.

More information regarding the `TI multicore processors <http://www.ti.com/processors/automotive-processors/overview.html>`_ is available .


Terms and Abbreviation
------------------------

=======   =============================================
Term      Definition or Explanation
=======   =============================================
IPC       Inter-Processor Communication
RirtIO    Virtual I/O driver
MailBox   IP which provides queued interrupt mechanism  for communication channel
RA        Ring accelerator
VRing     Ring Buffer on shared memory
RM        Resource Management
PDK       Platform Development Kit
PSDKRA    Processor SDK RTOS Automotive
PSDKLA    Processor SDK Linux Automotive
=======   =============================================


References
-----------
* `Sitara Processor Datasheet <http://www.ti.com/lit/gpn/am6548>`_
*  For J721e datasheet, please contact TI presentative


Features
^^^^^^^^^

* Provides ipc low-level driver which can be compiled for any cores on AM65xx or J721E devices
* Supports Bios/Bios communication and Linux/Bios concurrently for all cores
* Supports TI RTOS, Linux, QNX and baremetal use(No-OS).
* It can be extended for any third-party RTOS by adding OS adaptation layer
* IPCLLD also provides many examples for quick reference


Installation
^^^^^^^^^^^^^

IPCLLD is part of TI pdk (platform Development Kit) package. Once PSDKRA is installed, pdk and all dependent packages and tool-chains are installed automatically. 
IPCLLD can also be located at <PSDKRA_HOME>/pdk/packages/ti/drv/ipc. IPCLLD is also available publically at `<http://git.ti.com/keystone-rtos/ipc-lld>`_. 

It can also be cloned using following git command:

* git clone git://git.ti.com/keystone-rtos/ipc-lld.git
* Provides many examples for quick reference

The file  and directory oraganization are as below.

 .. image:: ../images/ipclld_file_org.png
                :height: 944
                :width: 435


Build
^^^^^^

IPCLLD uses pdk build systems to build IPCLLD library and example applications.

Compilers and Tool-chains Required:
-----------------------------------

========================   =============================================
Compiler/Tool-Chain         Tool Version and Download Links
========================   =============================================
SysBios                     `Bios 6.76.02.02 <http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/sysbios/6_76_02_02/exports/bios_6_76_02_02.run>`_
XDC tool                    `XDCtools 3.55.02.22 <http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/rtsc/3_55_02_22/exports/xdccore/xdctools_3_55_02_22_core_linux.zip>`_
XDAIS tool                  `XDAIS 7.24.00.04 <http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/xdais/7_24_00_04/index_FDS.html>`_
TI Code-Gen tool for ARM    `TI Arm CGT 18.2.1.LTS <http://software-dl.ti.com/codegen/esd/cgt_public_sw/TMS470/18.12.1.LTS/ti_cgt_tms470_18.12.1.LTS_linux_installer_x86.bin>`_
 Linaro Tools                * `aarch64-elf <https://releases.linaro.org/components/toolchain/binaries/7.2-2017.11/aarch64-elf/gcc-linaro-7.2.1-2017.11-x86_64_aarch64-elf.tar.xz>`_
                             * `aarch64-linux-gnu <https://releases.linaro.org/components/toolchain/binaries/7.2-2017.11/aarch64-linux-gnu/gcc-linaro-7.2.1-2017.11-x86_64_aarch64-linux-gnu.tar.xz>`_
========================   =============================================



Dependency of External PDK Components
-------------------------------------
IPCLLD does access any hardware diretly. It uses pdk/csl component to configure Mailbox registers. It uses sciclient to set/release Mailbox interrupt. Also it uses pdk/osal to congire OS related steps like Semaphore etc.

- pdk/csl : Configures Mailbox registers
- pdk/sciclient : Set Mailbox interrupts
- pdk/osal : To register for HWI and other kernel stuffs.



Command to build IPCLLD:
-------------------------

- Build IPCLLD library

    make -C ./ti/drv/ipc lib

- Build IPCLLD examples

    make -C ./ti/drv/ipc examples

- Clean IPCLLD library and examples

    make -C ./ti/drv/ipc clean

- Build IPCLLD and examples 

    make -C ./ti/drv/ipc all

Following environment variables must be defined.

- SDK_INSTALL_PATH: Installation root for sdk
- TOOLS_INSTALL_PATH: where all the tool chains are installed
- PDK_INSTALL_PATH: Installtion root for pdk

If pdk build system is used to build, then use following steps to build

- Go to <pdk_root>/package/ti/build
- To build the IPCLLD library, run command
  
    make -s -j BUILD_PROFILE=<debug/release> BOARD=<am65xx/j721e-evm> CORE=<core_name> ipc
- To build the IPCLLD examples, run command
  
    make -s -j BUILD_PROFILE=<debug/release> BOARD=<am65xx/j721e-evm> CORE=<core_name> ipc_echo_test
- To clean IPCLLD examples, run command
  
    make -s -j BUILD_PROFILE=<debug/release> BOARD=<am65xx/j721e-evm> CORE=<core_name> ipc_echo_test_clean
    
Core names:
-----------
        - mpu1_0: available on AM65xx and J721E device
        - mcu1_0: available on AM65xx and J721E device
        - mcu1_1: available on AM65xx and J721E device
        - mcu2_0: available on J721E device
        - mcu2_1: available on J721E device
        - mcu3_0: available on J721E device
        - mcu3_1: available on J721E device
        - c66xdsp_1: available on J721E device
        - c66xdsp_2: available on J721E device   
        - c7x_1: available on J721E device    

Running the IPCLLD examples
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

IPCLLD comes with four examples.

Example Details:
----------------

- **ipc_echo_test:** This is most generic example application where A72 is running Linux, and all other cores running bios. All cores talk to each other bi-diectionally. It is send ping message and remote end responds pong message. There are 10 ping/pong messages exchanged between each core-pair. 
- **ex01_bios_2core_echo_test:** This is the simplistic ping/pong application between any two cores running BIOS
- **ex02_bios_multicore_echo_test:** All cores running Bios, mani-to-many communication, each sending ping/pong with each other. A72 is also running Bios.
- **ex03_linux_bios_2core_echo_test:** THis is simplistic ping/pong application where A72 running Linux and any other core is running Bios.

Loading Remote Firmware
-----------------------

Remote firmware can be loading using ccs or using uBoot SPL.

1. **Loading using CCS** : 
   
    Sciclient module contains default system firmware and ccs script to load the system firmware. THe load scripts should be modified to reflect the correct full-path of the scipt location. Once the script is updated, 

    * start TI CCS 9.1
    * open ccs script console using menu **View --> Scripting Console**
    * Run the script using following command
        - loadJSFile("<pdk_root>/packages/ti/drv/sciclient/tools/ccsLoadDmsc/j721e/launch.js")

      .. image:: ../images/ipclld_LoadingSysFw_sciclient.png
                :height: 160
                :width: 941
    * Connect the cores
        - select the core
        - right-click and connect
    * Load the remote binaries
        - Menu **Run --> Load Program**
    * Run the cores.
    * After running the cores, the sample output should look something like below.

      .. image:: ../images/ipclld_Sample_output_mpu.png
                :height: 377
                :width: 672


2. **Loading using SPL/uBoot** 
    
  Run following steps to configure remote firmware for SPL loading

  1) Copy the remote firmware to rootfs at /lib/firmware/pdk-ipc folder
  2) cd /lib/firmware
  3) Remove old soft link for remote cores

     * rm j7*
  4) Create new soft links

     * ln -s /lib/firmware/pdk-ipc/ipc_echo_test_c66xdsp_1_release.xe66 j7-c66_0-fw  
     * ln -s /lib/firmware/pdk-ipc/ipc_echo_test_c66xdsp_2_release.xe66 j7-c66_1-fw    
     * ln -s /lib/firmware/pdk-ipc/ipc_echo_test_c7x_1_release.xe71     j7-c71_0-fw     
     * ln -s /lib/firmware/pdk-ipc/ipc_echo_test_mcu2_0_release.xer5f   j7-main-r5f0_0-fw
     * ln -s /lib/firmware/pdk-ipc/ipc_echo_test_mcu2_1_release.xer5f   j7-main-r5f0_1-fw
     * ln -s /lib/firmware/pdk-ipc/ipc_echo_test_mcu3_0_release.xer5f   j7-main-r5f1_0-fw
     * ln -s /lib/firmware/pdk-ipc/ipc_echo_test_mcu3_1_release.xer5f   j7-main-r5f1_1-fw
     * ln -s /lib/firmware/pdk-ipc/ipc_echo_testb_mcu1_0_release.xer5f  j7-mcu-r5f0_0-fw
     * ln -s /lib/firmware/pdk-ipc/ipc_echo_test_mcu1_1_release.xer5f   j7-mcu-r5f0_1-fw 

  5) sync : write the changes to filesystem
  6) Reboot the system


Running the ipc_echo_test
-------------------------
  1) Login as root
  2) Start sample app as below

     - modprobe rpmsg_client_sample count=5

     .. image:: ../images/ipclld_Linux_Start.png
                :height: 270
                :width: 581

   3) After running the sample app, it should display something below

    .. image:: ../images/ipclld_linux_output.png
                :height: 796px
                :width: 983px
        
  
IPCLLD Design Details
^^^^^^^^^^^^^^^^^^^^^

- Ring Buffer is used as shared memory to transfer the data. It must be reserved system wide. The base-address and size of ring Buffer must be provided to IPCLLD. It must be same for all core applications. the invidual memory-range for Ring Buffer between core combinations are calculated internally inside the library. The default base-address is 0xAA000000 and size is 0x1C00000
- For each RPmessage object, the memory must be provided to library from local heap. All subsequent send/recv API is using rpmessage buffer provided during the create function.
- RPMessage can transfer maximum of 512 bytes of data. 


Typical Data-Flow in IPCLLD communication between two cores
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Following picture illustrates the data flow between two cres using mailbox IP as transport.

.. image:: ../images/ipclld_data_flow.png
                :height: 470
                :width: 687

Writing HelloWorld App using IPCLLD
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
- **Step1: Initialize MultiProc ? SelfId, how many remote cores?**
     Ipc_mpSetConfig(selfProcId, numProc, remoteProc);

- **Step2: Initialize VirtIO ? Base Address for Shared Memory used for RingBuffer**
     vqParam.vqObjBaseAddr = (void*)sysVqBuf;
     vqParam.vqBufSize     = numProc * Ipc_getVqObjMemoryRequiredPerCore();
     vqParam.vringBaseAddr = (void*)VRING_BASE_ADDRESS;
     vqParam.vringBufSize  = VRING_BUFFER_SIZE;
     Ipc_initVirtIO(&vqParam);

- **Step3: Initialize RPMessage**
     RPMessage_init(&cntrlParam);

- **Step4: Send Message**
     RPMessage_send(handle, dstProc, ENDPT1, myEndPt, (Ptr)buf, len);

- **Step5: Receive Message**
     RPMessage_recv(handle, (Ptr)buf, &len, &remoteEndPt,
                         &remoteProcId, timeout);


