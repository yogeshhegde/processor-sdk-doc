Download and Install the SDK
======================================

**Processor SDK SITARA AM64x Release support both Linux and Windows versions of installers**

+------------------------------------------+-----------------------------------------------------------------------+
| **Installer Details**                    |   **Installers Name**                                                 |
+------------------------------------------+-----------------------------------------------------------------------+
| Linux + RTOS Installer (Windows version) | processor_sdk_sitara_am64x_xx_yy_zz_nn-windows-x64-installer.exe      |
+------------------------------------------+-----------------------------------------------------------------------+
| Linux + RTOS Installer (Linux version)   | processor_sdk_sitara_am64x_xx_yy_zz_nn-linux-x64-installer.run        |
+------------------------------------------+-----------------------------------------------------------------------+
| Linux only Installer   (Linux version)   | processor_sdk_sitara_am64x_linux_xx_yy_zz_nn-linux-x64-installer.run  |
+------------------------------------------+-----------------------------------------------------------------------+

.. note:: For windows installer, install always in C:/ti. Do not install in any deeper directory structure as build might fail due to the 260 character path length limit exist in Windows operating system


**Package Overview**

This AM64x Software development kit contains Linux, RTOS and Baremetal device drivers, industrial protocols, industrial drives, sample examples and application specific demos.  The SDK has below folder structure


+---------------------+-----------------------------------------------------------------------+
| **Folder Name**     |   **Description**                                                     |
+---------------------+-----------------------------------------------------------------------+
| linux               | Linux board supported packages (Linux kernel and u-boot in source),   |
|                     | linux-devkit, prebuilt-images, file-system,                           |
|                     | resource-partitioning tool, set-up scripts,                           |
+---------------------+-----------------------------------------------------------------------+
| rtos                | RTOS/BM platform development kit, industrial protocols and drives,    |
|                     | RTOS build tools                                                      |
+---------------------+-----------------------------------------------------------------------+
| sitara-apps         | Sample examples and                                                   |
|                     | application specific demos (servo drive & benchmarking demos)         |
+---------------------+-----------------------------------------------------------------------+


Refer :ref:`[Release Note] <Release-note-label>` for complete feature-set and further details


**Instructions to set-up CCS**

-  Refer /<INSTALL-DIR>/rtos/pdk_am64x_xx_xx_xx_xx/docs/userguide/am64x/ccs_setup_am64x.html - `[Use Link] <../../rtos/pdk_am64x/docs/userguide/am64x/ccs_setup_am64x.html>`__


**Build Instructions**

Processor SDK AM64x support GNU make based build system. Refer /<INSTALL-DIR>/sitara-apps/makerules folder for all supported demos and build targets

Below the list of build targets supported by processor SDK AM64x

+-----------------------+-----------------------------------------------------------------------+
| **Build Target**      |   **Description**                                                     |
+-----------------------+-----------------------------------------------------------------------+
| common_libs           | Common libs like log, profile, sci-client time-sync                   |
|                       | used across multiple demos and applications                           |
+-----------------------+-----------------------------------------------------------------------+
| r5f_hello_world       | R5F Hello world Application (for ramp-up)                             |
+-----------------------+-----------------------------------------------------------------------+
| timesync_example      | TimeSync/Time Distribution to derive multiple sync events             |
+-----------------------+-----------------------------------------------------------------------+
| ipc_rpmsg_lib         | RPMSG lib for interprocessor communication                            |
+-----------------------+-----------------------------------------------------------------------+
| servo_drive_demo      | 3-axes servo drive demo                                               |
+-----------------------+-----------------------------------------------------------------------+
| benchmark_demo        | Benchmarking demos                                                    |
+-----------------------+-----------------------------------------------------------------------+

For Windows version use “gmake” from /<INSTALL-DIR>/rtos/xdctools_x_yy_zz_nn_core to build SDK


For example: How to build **R5F Hello world Application**


For Linux

    ::

        $ cd /<INSTALL-DIR>/sitara-apps
        $ make common_libs
        $ make r5f_hello_world

For Windows

    ::

        $ cd /<INSTALL-DIR>/sitara-apps
        $ gmake common_libs
        $ gmake r5f_hello_world

The built binary files will be in /<INSTALL-DIR>/sitara-apps/examples/r5f_hello_world/out/AM64X/R5F/NO_OS/release

Run R5F Hello World App using CCS with JTAG

-  Power up the AM64x EVM, Launch the CCS, Launch the AM64x_EVM.ccxml
-  Run load script - loadJSFile “/<INSTALL-DIR>/rtos/pdk_am64x_xx_xx_xx_xx/packages/ti/drv/sciclient/tools/ccsLoadDmsc/am64x launch.js”
-  By default, the MAIN_Cor_R5_0_0 will be halt at 0x00000000. Load the OUT files for mcu1_0 to MAIN_Cor_R5_0_0 and run

Run R5F Hello World App using SD card boot

-  Copy all 3 files (app, sysfw.bin & tiboot3.bin) from /<INSTALL-DIR>/sitara-apps/examples/r5f_hello_world/out/AM64X/SDCardImage into an SD card
-  Insert the SD card and power up the AM64x EVM


**Benchmark demos**

-  Refer :ref:`[Benchmark Demo User Guide] <Benchmark-Demo-User-Guide-label>`


**Servo drive demo**

-  Refer :ref:`[Servo Drive Demo User Guide] <Servo-Drive-Demo-User-Guide-label>`


**How to build dependent components**

Set-up Linux build environment to rebuild kernel, u-boot & DTB

    ::

        $ cd /<INSTALL-DIR>/linux/bin/scripts
        $ ./setup-ubuntu.sh

Refer the respective user guides to build Linux and other RTOS/BM packages

-  For Linux Kernel, u-boot & DTB     `[Use Link] <index_Linux.html>`__
-  For Platform Development Kit (PDK) `[Use Link] <../../rtos/pdk_am64x/docs/userguide/am64x/index_am64x.html>`__
-  For EtherCAT Slave                 `[Use Link] <../../rtos/pru_icss_docs/indsw/EtherCAT_Slave/EtherCAT_Slave.html>`__
-  For ProfiNetSlave                  `[Use Link] <../../rtos/pru_icss_docs/indsw/profinet_slave/profinet_slave.html>`__
-  For Ethernet_ip_adapter            `[Use Link] <../../rtos/pru_icss_docs/indsw/ethernetIP_adapter/ethernetIP_adapter.html>`__
-  For Industrial Drives (EnDAT,HDSL) `[Use Link] <../../rtos/pru_icss_docs/indsw/Industrial_Drives/Industrial_Drives.html>`__



