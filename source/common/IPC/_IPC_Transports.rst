.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_IPC_Transports 

Introduction
-----------------

IPC transports are the underlying configurable data paths over shared
memory and hardware resources, which implement the IPC MessageQ APIs.
MessageQ provides a common IPC interface between processors within a
system containing a single or multiple KeyStone devices. Communication
between the processors is enabled through the use of IPC transports. The
transports supplied with the IPC component are shared memory based,
capable of intra-device communication. Additional transports, utilizing
the QMSS and SRIO LLDs, are supplied via Yocto/bitbake for ARMv7 Linux
IPC and PROCSDK PDK for SYS/BIOS DSP IPC, enabling intra-SoC and
inter-SoC communication, respectively.

The below table gives an overview of the transport offerings, their
location, and the communication path they enable.

+---------------+--------------+--------------+----------------+-----------------+------------------+
| **Transport** | **MessageQ   | **Location** | **Communication| **Enabled       | **Special        |
|               | Interface    |              | Route**        | Communication   | Considerations** |
|               | Type**       |              |                | Path**          |                  |
+---------------+--------------+--------------+----------------+-----------------+------------------+
| Transport     | MessageQ     | IPC          | Shared         | SYS/BIOS        | There are        |
| Shm...        | (priority    | component    | memory         | DSP to          | multiple         |
|               | based)       | -            |                | DSP             | implementations  |
|               |              | SYS/BIOS     |                |                 | of Transport Shm |
|               |              | subdirect    |                |                 | delivered within |
|               |              | ories        |                |                 | the IPC component|
|               |              |              |                |                 | Please see the   |
|               |              |              |                |                 | IPC documentation|
|               |              |              |                |                 | provided with the|
|               |              |              |                |                 | component for    |
|               |              |              |                |                 | more information |
|               |              |              |                |                 | on these shared  |
|               |              |              |                |                 | memory transport |
|               |              |              |                |                 | implementions    |
+---------------+--------------+--------------+----------------+-----------------+------------------+
| Transport     | MessageQ     | - IPC        | Shared         | - ARMv7         | MessageQ messages|
| Rpmsg         | (priority    |   component -| memory         |   Linux to/from | sent over        |
|               | based)       |   ARMv7 Linux|                |   SYS/BIOS DSP  | Transport Rpmsg  |
|               |              |   subdirect  |                |                 | traveling        |
|               |              |   ories      |                |                 | from/to ARMv7    |
|               |              | - IPC        |                |                 | user space       |
|               |              |   component -|                |                 | go through       |
|               |              |   SYS/BIOS   |                |                 | the Linux kernel |
|               |              |   subdirect  |                |                 | before reaching  |
|               |              |   ories      |                |                 | the DSP.         |
|               |              | - Yocto/     |                |                 | This provides    |
|               |              |   bitbake    |                |                 | *clean*          |
|               |              |   ti-ipc     |                |                 | partitioning     |         
|               |              |   recipe     |                |                 | between user     |
|               |              |              |                |                 | memory and DSP   |
|               |              |              |                |                 | memory. However, |
|               |              |              |                |                 | Transport Rpmsg  |
|               |              |              |                |                 | is considered    |     
|               |              |              |                |                 | a *slow path*    |
|               |              |              |                |                 | since the user   |
|               |              |              |                |                 | space MessageQ   |
|               |              |              |                |                 | messages must be |
|               |              |              |                |                 | copied from/to   |
|               |              |              |                |                 | DSP memory by    |
|               |              |              |                |                 | kernel and DSP.  |
+---------------+--------------+--------------+----------------+-----------------+------------------+
| SYS/BIOS      | Network      | PROCSDK      | SRIO LLD       | - SYS/BIOS      | TransportSrio    |
| DSP           |              | RTOS PDK     |                |   DSP to/from   | can send MessageQ|         
| Transport     |              |              |                |   SYS/BIOS DSP  | messages to ARMv7|
| Srio          |              |              |                |   (intra and    | and DSP          |
|               |              |              |                |   inter-device) | processors on    |
|               |              |              |                | - SYS/BIOS      | remote devices   |
|               |              |              |                |   DSP to/from   | in a multiple    |
|               |              |              |                |   ARMv7 Linux   | device system.   |
|               |              |              |                |   (intra- and   | IPC MultiProc    |
|               |              |              |                |   inter- device)| must be          | 
|               |              |              |                |                 | configured to be |
|               |              |              |                |                 | aware of all     |
|               |              |              |                |                 | processors       | 
|               |              |              |                |                 | existing on all  |
|               |              |              |                |                 | devices and all  |
|               |              |              |                |                 | devices must be  |      
|               |              |              |                |                 | connected over a |
|               |              |              |                |                 | SRIO             |
|               |              |              |                |                 | interconnect.    |
|               |              |              |                |                 |                  |
|               |              |              |                |                 | The main         |
|               |              |              |                |                 | purpose of       |
|               |              |              |                |                 | TransportSrio    |
|               |              |              |                |                 | is for           |
|               |              |              |                |                 | multi-device     |
|               |              |              |                |                 | communication    |
|               |              |              |                |                 | over MessageQ.   |
|               |              |              |                |                 | The transmission |
|               |              |              |                |                 | latency is       |
|               |              |              |                |                 | greater for      |
|               |              |              |                |                 | this transport   |
|               |              |              |                |                 | due to the       |
|               |              |              |                |                 | latter capability|
|               |              |              |                |                 | Therefore it is  |
|               |              |              |                |                 | recommended a    |
|               |              |              |                |                 | shared memory or |    
|               |              |              |                |                 | other LLD-based  |
|               |              |              |                |                 | transport        |
|               |              |              |                |                 | is used for      |    
|               |              |              |                |                 | intra-device     |
|               |              |              |                |                 | communication    |
|               |              |              |                |                 | due to their     |
|               |              |              |                |                 | lower latency    |
|               |              |              |                |                 | costs.           |
+---------------+--------------+--------------+----------------+-----------------+------------------+
| ARMv7         | Network      | Yocto/bit    | SRIO LLD       | - ARMv7         | TransportSrio    | 
| Linux         |              | bake         |                |   Linux to/from | can send         |
| Transport     |              | ti-transp    |                |   ARMv7 Linux   | MessageQ messages|         
| Srio          |              | ort-srio     |                |   (intra- and   | to ARMv7 and DSP |
|               |              | recipe       |                |   inter-device) | processors on    |
|               |              |              |                | - SYS/BIOS      | remote devices   |
|               |              |              |                |   DSP to/from   | in a multiple    |
|               |              |              |                |   ARMv7 Linux   | device system.   |
|               |              |              |                |   (intra- and   | IPC MultiProc    |
|               |              |              |                |   inter-device) | must be          |
|               |              |              |                |                 | configured to be |
|               |              |              |                |                 | aware of all     |
|               |              |              |                |                 | processors       |
|               |              |              |                |                 | existing on all  |          
|               |              |              |                |                 | devices and all  |
|               |              |              |                |                 | devices must be  |
|               |              |              |                |                 | connected        |
|               |              |              |                |                 | over a SRIO      |
|               |              |              |                |                 | interconnect.    |
|               |              |              |                |                 |                  |
|               |              |              |                |                 | The main         |
|               |              |              |                |                 | purpose of       |
|               |              |              |                |                 | TransportSrio    |
|               |              |              |                |                 | is for           |
|               |              |              |                |                 | multi-device     |      
|               |              |              |                |                 | communication    |
|               |              |              |                |                 | over MessageQ.   |
|               |              |              |                |                 | The transmission |
|               |              |              |                |                 | latency is       |
|               |              |              |                |                 | greater for      |
|               |              |              |                |                 | this transport   |     
|               |              |              |                |                 | due to the latter|
|               |              |              |                |                 | capability.      |
|               |              |              |                |                 | Therefore, it is |        
|               |              |              |                |                 | recommended      |
|               |              |              |                |                 | a shared memory  |
|               |              |              |                |                 | or other         |  
|               |              |              |                |                 | LLD-based        |
|               |              |              |                |                 | transport        |      
|               |              |              |                |                 | is used for      |
|               |              |              |                |                 | intra-device     |
|               |              |              |                |                 | communication    |
|               |              |              |                |                 | due to their     |
|               |              |              |                |                 | lower latency    | 
|               |              |              |                |                 | costs.           |
+---------------+--------------+--------------+----------------+-----------------+------------------+
| SYS/BIOS      | Network      |              | QMSS LLD       | - SYS/BIOS      |                  |
| DSP           |              |              |                |   DSP to/from   |                  |
| Transport     |              |              |                |   SYS/BIOS DSP  |                  |
| Qmss          |              |              |                | - SYS/BIOS      |                  |
|               |              |              |                |   DSP to/from   |                  |
|               |              |              |                |   ARMv7 Linux   |                  |
+---------------+--------------+--------------+----------------+-----------------+------------------+
|               |              |              |                | - ARMv7 Linux   |                  |
|               |              |              |                |   process       |                  |
|               |              |              |                |   to process.   |                  |
|               |              |              |                | - ARMv7         |                  |
|               |              |              |                |   Linux to/from |                  |
|               |              |              |                |   SYS/BIOS DSP  |                  |
+---------------+--------------+--------------+----------------+-----------------+------------------+

The IPC component (ARMv7 and SYS/BIOS) is available in PROCSDK RTOS and
Linux installations. It will be installed in <PROCSDK RTOS or Linux
install root>/ipc_#_##_##_##<version>. Additionally, the IPC component's
ARMv7 source is packaged in a Yocto/bitbake recipe. A user can develop
ARMv7 Linux user-space applications with IPC on Keystone I and KeyStone
II devices by building the ti-ipc package in Yocto.

Modes of Operation
--------------------

SYS/BIOS DSP TransportSrio
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The following SRIO socket types are supported:

**TransportSrio_srioSockType_TYPE_9**: In this mode, the SRIO IPC
transport will use Type 9 sockets to communicate with other SRIO IPC
transport endpoints.

**TransportSrio_srioSockType_TYPE_11**: In this mode, the SRIO IPC
transport will use Type 11 sockets to communicate with other SRIO IPC
transport endpoints.

ARM Linux TransportSrio
^^^^^^^^^^^^^^^^^^^^^^^^^

The following SRIO socket types are supported:

**sock_TYPE_9**: In this mode, the ARM Linux SRIO IPC transport will use
Type 9 sockets to communicate with other SRIO IPC transport endpoints.

**sock_TYPE_11**: In this mode, the ARM Linux SRIO IPC transport will
use Type 11 sockets to communicate with other SRIO IPC transport
endpoints.

SYS/BIOS DSP TransportQmss
^^^^^^^^^^^^^^^^^^^^^^^^^^^

The following QMSS receive queue types are supported:

**TransportQmss_queueRcvType_ACCUMULATOR**: In this mode, the QMSS
accumulator logic is used as the reception mechanism for the QMSS
Transport.

**TransportQmss_queueRcvType_QPEND**: In this mode, a QMSS QPEND (direct
interrupt) queue is used as the reception mechanism for the QMSS
Transport.

ARM Linux TransportQmss
^^^^^^^^^^^^^^^^^^^^^^^^^

A QMSS QPEND queue will always be used as the reception mechanism for
the ARM Linux QMSS Transport.

Transport Configuration
------------------------

SYS/BIOS DSP TransportSrio
^^^^^^^^^^^^^^^^^^^^^^^^^^^

SRIO SERDES and Lane Configuration
""""""""""""""""""""""""""""""""""""

Configuration of the SRIO SERDES and lanes are required before calling
any driver APIs. Examples of the initialization sequences for supported
EVMs are provided in the TransportSrio example folder. The examples call
the SrioDevice_init() API prior to configuring the transport.
SrioDevice_init() reference:

::
  
    ti/transport/ipc/c66/srio/example/src/device_srio.c

Developers can modify the configurations made in the stock device_srio.c
to change SRIO endpoint IDs, routing information, lane rates, loopback
modes, etc.

APIs
""""""

API reference for application:

::

    #include <ti/transport/ipc/c66/srio/TransportSrio.h>

ARM Linux TransportSrio
^^^^^^^^^^^^^^^^^^^^^^^^^^^

SRIO SERDES and Lane Configuration
""""""""""""""""""""""""""""""""""""

Configuration of the SRIO SERDES and lanes are required before calling
any driver APIs. Examples of the initialization sequences for supported
EVMs are provided in the TransportSrio test folder. The examples call
the SrioDevice_init() API prior to configuring the transport.
SrioDevice_init() reference from keystone-linux/ipc-transport git
repository:

::

    linux/srio/test/[consumer or producer]_device_srio.c

Developers can modify the configurations made in the stock device_srio.c
to change SRIO endpoint IDs, routing information, lane rates, loopback
modes, etc.

MPM Transport SRIO Configuration
"""""""""""""""""""""""""""""""""

TransportSrio leverages MPM Transport in order to manage configuration
of the QMSS, CPPI, and SRIO LLDs. As a result, the transport's
descriptor and descriptor buffer management is pushed to MPM Transport
in the ARM Linux version of TransportSrio. The MPM Transport JSON
configuration file can be modified to change QMSS descriptor and buffer
related parameters.

The MPM Transport JSON configuration file is located in the Linux file
system at /etc/mpm/mpm_config.json

APIs
"""""

API reference for application from keystone-linux/ipc-transport git
repository:

::

    #include <linux/srio/TransportSrio.h>

SYS/BIOS DSP TransportQmss
^^^^^^^^^^^^^^^^^^^^^^^^^^^

APIs
""""""

API reference for application:

::

    #include <ti/transport/ipc/c66/qmss/TransportQmss.h>

ARM Linux TransportQmss
^^^^^^^^^^^^^^^^^^^^^^^^^

MPM Transport QMSS Configuration
"""""""""""""""""""""""""""""""""

TransportQmss leverages MPM Transport in order to manage configuration
of the QMSS and CPPI LLDs. As a result, the transport's descriptor and
descriptor buffer management is pushed to MPM Transport in the ARM Linux
version of TransportQmss. The MPM Transport JSON configuration file can
be modified to change QMSS descriptor and buffer related parameters.

The MPM Transport JSON configuration file is located in the Linux file
system at /etc/mpm/mpm_config.json

APIs
""""""

API reference for application from keystone-linux/ipc-transport git
repository:

::

    #include <linux/qmss/TransportQmss.h>

Source Delivery and Recompilation
-----------------------------------

SYS/BIOS DSP TransportSrio
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The SYS/BIOS DSP TransportSrio source code and examples are delivered
within the PROCSDK RTOS PDK component. DSP TransportSrio can be rebuilt
using the environment setup scripts provided with the PDK package. DSP
TransportSrio example applications are created as part of the
pdkProjectCreate scripts. They can be imported and built the same as PDK
LLD example and test CCS projects.

Recompiling on Windows
"""""""""""""""""""""""

#. Open a Windows command terminal and navigate to
   <pdk_install_dir>/packages.
#. Run pdksetupenv.bat
   >pdksetupenv.bat
#. Navigate to <pdk_install_path>/packages/ti/transport/ipc/c66/srio/
#. Build the IPC SRIO Transport library
   >gmake

Issue the following commands if the SRIO transport ever needs to be
rebuilt:

>gmake clean
>gmake

Recompiling on Linux
"""""""""""""""""""""""

#. Open a Linux bash terminal and navigate to
   <pdk_install_dir>/packages.
#. Run pdksetupenv.sh
   $ source pdksetupenv.sh
#. Navigate to <pdk_install_path>/packages/ti/transport/ipc/c66/srio/
#. Build the IPC SRIO Transport library
   $ make

Issue the following commands if the SRIO transport ever needs to be
rebuilt:

$ make clean
$ make

ARM Linux TransportSrio Source Delivery and Recompilation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The ARM Linux TransportSrio source code can be downloaded and built two
ways. The transport source code is delivered and built as part of
Yocto/bitbake. The source code can also be downloaded and built directly
from the GIT repository.

Recompiling Through Yocto/bitbake
""""""""""""""""""""""""""""""""""""

#. Follow the instructions in the Exploring section of the user guide to
   configure the `Yocto build
   environment <http://software-dl.ti.com/processor-sdk-linux/esd/docs/latest/linux/Overview_Building_the_SDK.html>`__.
   The tisdk-server-rootfs-image does not need to be built. Instead look
   at the section for `building other
   components <http://software-dl.ti.com/processor-sdk-linux/esd/docs/latest/linux/Overview_Building_the_SDK.html#recipes>`__
#. Build the TransportSrio libraries, ipc-transport-srio recipe, and
   user-space tests, ipc-transport-srio-test recipe:
   $ MACHINE=k2hk-evm TOOLCHAIN_BRAND=linaro ARAGO_BRAND=mcsdk bitbake
   ipc-transport-srio
   $ MACHINE=k2hk-evm TOOLCHAIN_BRAND=linaro ARAGO_BRAND=mcsdk bitbake
   ipc-transport-srio-test

   .. note:: 
      The initial build may take quite some time since the kernel is built as a dependency

   .. note:: 
     Building with just the ipc-transport-srio-test recipe will also build the 
     ipc-transport-srio recipe since the test recipe depends on the library recipe.

#. The built TransportSrio static library will be located in
   <base_path>/oe-layersetup/build/arago-tmp-external-linaro-toolchain/work/cortexa15hf-vfp-neon-3.8-oe-linux-gnueabi/ipc-transport-srio/<tag-ver_recipe-ver>/packages-split/ipc-transport-srio-staticdev/usr/lib/libTransportSrio.a
   The built TransportSrio shared library will be located in
   <base_path>/oe-layersetup/build/arago-tmp-external-linaro-toolchain/work/cortexa15hf-vfp-neon-3.8-oe-linux-gnueabi/ipc-transport-srio/<tag-ver_recipe-ver>/packages-split/ipc-transport-srio/usr/lib/libTransportSrio.so.1.0.0
#. The ipc-transport-srio-test recipe will build test static and shared
   library executables for all supported devices. The executables will
   be located in
   base_path>/oe-layersetup/build/arago-tmp-external-linaro-toolchain/work/cortexa15hf-vfp-neon-3.8-oe-linux-gnueabi/ipc-transport-srio-test/<tag-ver_recipe-ver>/packages-split/ipc-transport-srio-test/usr/bin/

Recompiling Through GIT Repository
"""""""""""""""""""""""""""""""""""""

Recompiling through the ARM Linux TransportSrio GIT repository requires
that the latest PROCSDK Linux installation. The PROCSDK Linux PDK
component and the Linux devkit must be installed. The Linux devkit
installation script can be found in <PROCSDK Linux install
root>/procsdk_linux_3_XX_YY_ZZ/linux-devkit/

#. Clone the keystone-linux/ipc-transport repository from git.ti.com
   $ git clone git://git.ti.com/keystone-linux/ipc-transport.git
#. Navigate to the PROCSDK Linux installation of pdk_3_XX_YY_ZZ/packages
   and source armv7setupenv.sh.

   .. note:: 
      The armv7setupenv.sh script must be modified to
      point to the linaro toolchain and installed devkit path

      $ source armv7setupenv.sh

#. Navigate back to the SRIO transport directory in the ipc-transport
   GIT repository
   $ cd <repo_root_path>/ipc-transport/linus/srio
#. Build the TransportSrio library and user-space test executables:
   $ make lib
   $ make tests
#. The TransportSrio static and shared libraries will be copied directly
   into the Linux devkit's /usr/lib folder as long as the devkit install
   path was setup correctly prior to running the armv7setupenv.sh script
#. The test executables will be generated in the
   <base_repo_path>/ipc-transport/bin/<k2 device>/test/ folder. Only the
   device specified in the armv7setupenv.sh will be built.

.. note:: 
  Setting the USEDYNAMIC_LIB environment variable to
  "yes" will generate the shared library test executables
  
  $ export USEDYNAMIC_LIB=yes

SYS/BIOS DSP TransportQmss Source Delivery and Recompilation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The SYS/BIOS DSP TransportQmss source code and examples are delivered
within the PROCSDK RTOS PDK component. DSP TransportQmss can be rebuilt
using the environment setup scripts provided with the PDK package. DSP
TransportQmss example applications are created as part of the
pdkProjectCreate scripts. They can be imported and built the same as PDK
LLD example and test CCS projects.

Recompiling on Windows
"""""""""""""""""""""""

#. Open a Windows command terminal and navigate to
   <pdk_install_dir>/packages.
#. Run pdksetupenv.bat
   >pdksetupenv.bat
#. Navigate to <pdk_install_path>/packages/ti/transport/ipc/c66/qmss/
#. Build the IPC QMSS Transport library
   >gmake

Issue the following commands if the QMSS transport ever needs to be
rebuilt:

>gmake clean
>gmake

Recompiling on Linux
""""""""""""""""""""""

#. Open a Linux bash terminal and navigate to
   <pdk_install_dir>/packages.
#. Run pdksetupenv.sh
   $ source pdksetupenv.sh
#. Navigate to <pdk_install_path>/packages/ti/transport/ipc/c66/qmss/
#. Build the IPC QMSS Transport library
   $ make

Issue the following commands if the QMSS transport ever needs to be
rebuilt:

$ make clean
$ make

ARM Linux TransportQmss Source Delivery and Recompilation
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

The ARM Linux TransportQmss source code can be downloaded and built two
ways. The transport source code is delivered and built as part of
Yocto/bitbake. The source code can also be downloaded and built directly
from the GIT repository.

Recompiling Through Yocto/bitbake
""""""""""""""""""""""""""""""""""

#. Follow the instructions in the Exploring section of the user guide to
   configure the `Yocto build
   environment <http://processors.wiki.ti.com/index.php/MCSDK_UG_Chapter_Exploring#Yocto>`__.
   The tisdk-server-rootfs-image does not need to be built. Instead look
   at the section for `building other
   components <http://processors.wiki.ti.com/index.php/MCSDK_UG_Chapter_Exploring#Building_other_components_in_Yocto>`__
#. Build the TransportQmss libraries, ipc-transport-qmss recipe, and
   user-space tests, ipc-transport-qmss-test recipe:
   $ MACHINE=k2hk-evm TOOLCHAIN_BRAND=linaro ARAGO_BRAND=mcsdk bitbake
   ipc-transport-qmss
   $ MACHINE=k2hk-evm TOOLCHAIN_BRAND=linaro ARAGO_BRAND=mcsdk bitbake
   ipc-transport-qmss-test

   .. note:: 
     The initial build may take quite some time since
     the kernel is built as a dependency

   .. note:: 
     Building with just the ipc-transport-qmss-test
     recipe will also build the ipc-transport-qmss recipe since the test
     recipe depends on the library recipe.

#. The built TransportQmss static library will be located in
   <base_path>/oe-layersetup/build/arago-tmp-external-linaro-toolchain/work/cortexa15hf-vfp-neon-3.8-oe-linux-gnueabi/ipc-transport-qmss/<tag-ver_recipe-ver>/packages-split/ipc-transport-qmss-staticdev/usr/lib/libTransportQmss.a
   The built TransportQmss shared library will be located in
   <base_path>/oe-layersetup/build/arago-tmp-external-linaro-toolchain/work/cortexa15hf-vfp-neon-3.8-oe-linux-gnueabi/ipc-transport-qmss/<tag-ver_recipe-ver>/packages-split/ipc-transport-qmss/usr/lib/libTransportQmss.so.1.0.0
#. The ipc-transport-qmss-test recipe will build test static and shared
   library executables for all supported devices. The executables will
   be located in
   base_path>/oe-layersetup/build/arago-tmp-external-linaro-toolchain/work/cortexa15hf-vfp-neon-3.8-oe-linux-gnueabi/ipc-transport-qmss-test/<tag-ver_recipe-ver>/packages-split/ipc-transport-qmss-test/usr/bin/

Recompiling Through GIT Repository
"""""""""""""""""""""""""""""""""""

Recompiling through the ARMv7 Linux TransportQmss GIT repository
requires that the latest PROCSDK Linux installation. The PROCSDK Linux
PDK component and the Linux devkit must be installed. The Linux devkit
installation script can be found in <PROCSDK Linux install
root>/processor_sdk_linux_3_XX_YY_ZZ/linux-devkit/

#. Clone the keystone-linux/ipc-transport repository from git.ti.com
   $ git clone git://git.ti.com/keystone-linux/ipc-transport.git
#. Navigate to the PROCSDK Linux installation of pdk_3_XX_YY_ZZ/packages
   and source armv7setupenv.sh.

   .. note:: 
     The armv7setupenv.sh script must be modified build
     for the correct K2 device, and to point to the linaro toolchain and
     installed devkit path

     $ source armv7setupenv.sh

#. Navigate back to the QMSS transport directory in the ipc-transport
   GIT repository
   $ cd <repo_root_path>/ipc-transport/linus/qmss
#. Build the TransportQmss library and user-space test executables:
   $ make lib
   $ make tests
#. The TransportQmss static and shared libraries will be copied directly
   into the Linux devkit's /usr/lib folder as long as the devkit install
   path was setup correctly prior to running the armv7setupenv.sh script
#. The test executables will be generated in the
   <base_repo_path>/ipc-transport/bin/<k2 device>/test/ folder. Only the
   device specified in the armv7setupenv.sh will be built.

.. note:: 
  Setting the USEDYNAMIC_LIB environment variable to
  "yes" will generate the shared library test executables

   $ export USEDYNAMIC_LIB=yes

Tests & Examples
--------------------

SYS/BIOS DSP TransportSrio
^^^^^^^^^^^^^^^^^^^^^^^^^^^

+-----------------------+-----------------------+-----------------------+
| Name                  | Description           | Expected Results      |
+=======================+=======================+=======================+
| SYS/BIOS DSP          | | Example             | | Successful          |
| TransportSrio         |   demonstrating       |   completion on two   |
| Benchmark Example     |   intra-SoC, DSP to   |   DSP cores for all   |
|                       |   DSP, transport over |   example iterations. |
|                       |   SRIO use while also |                       |
|                       |   measuring latency   |                       |
|                       |   and throughput      |                       |
|                       |   performance. The    |                       |
|                       |   example consists of |                       |
|                       |   multiple iterations |                       |
|                       |   where each          |                       |
|                       |   iteration runs SRIO |                       |
|                       |   with different lane |                       |
|                       |   configurations.     |                       |
|                       |   Reference example   |                       |
|                       |   for developers      |                       |
+-----------------------+-----------------------+-----------------------+
| SYS/BIOS DSP          | | Example             | Successful completion |
| TransportSrio         |   demonstrates        | for all example       |
| Producer/Consumer     |   inter-SoC, DSP to   | iterations on two DSP |
| Example               |   DSP, transport over | cores per producer    |
|                       |   SRIO. The example   | and consumer devices. |
|                       |   consists of         |                       |
|                       |   multiple iterations |                       |
|                       |   where each          |                       |
|                       |   iteration runs SRIO |                       |
|                       |   with different lane |                       |
|                       |   configurations.     |                       |
+-----------------------+-----------------------+-----------------------+

ARM Linux TransportSrio
^^^^^^^^^^^^^^^^^^^^^^^^^^

+-----------------------+-----------------------+-----------------------+
| Name                  | Description           | Expected Results      |
+=======================+=======================+=======================+
| ARM Linux             | | Example             | Successful completion |
| TransportSrio         |   demonstrates        | for all example       |
| Producer/Consumer     |   inter-SoC, ARM      | iterations on two     |
| Example               |   Linux to ARM Linux, | Linux processes per   |
|                       |   transport over      | producer and consumer |
|                       |   SRIO. The example   | devices.              |
|                       |   consists of         |                       |
|                       |   multiple iterations |                       |
|                       |   where each          |                       |
|                       |   iteration runs SRIO |                       |
|                       |   with different lane |                       |
|                       |   configurations.     |                       |
+-----------------------+-----------------------+-----------------------+

SYS/BIOS DSP TransportQmss
^^^^^^^^^^^^^^^^^^^^^^^^^^^^

+-----------------------+-----------------------+-----------------------+
| Name                  | Description           | Expected Results      |
+=======================+=======================+=======================+
| SYS/BIOS DSP          | | Example             | | Successful          |
| TransportQmss         |   demonstrating       |   completion on two   |
| Benchmark Example     |   intra-SoC, DSP to   |   DSP cores for all   |
|                       |   DSP, transport over |   example iterations. |
|                       |   QMSS use while also |                       |
|                       |   measuring latency   |                       |
|                       |   and throughput      |                       |
|                       |   performance. The    |                       |
|                       |   example consists of |                       |
|                       |   multiple iterations |                       |
|                       |   where each          |                       |
|                       |   iteration runs QMSS |                       |
|                       |   with different      |                       |
|                       |   reception           |                       |
|                       |   mechanisms          |                       |
|                       |   (accumulator or     |                       |
|                       |   QPEND queue).       |                       |
|                       |   Reference example   |                       |
|                       |   for developers      |                       |
+-----------------------+-----------------------+-----------------------+
| SYS/BIOS DSP          | | Tests inter-SoC,    | Successful completion |
| TransportQmss         |   ARM Linux to DSP,   | on two DSP cores and  |
| DSP-Side of           |   transport over      | two Linux processes.  |
| Heterogeneous         |   QMSS. Reference     |                       |
| Processor Test        |   test for developers |                       |
+-----------------------+-----------------------+-----------------------+

ARM Linux TransportQmss
^^^^^^^^^^^^^^^^^^^^^^^^^

+-----------------------+-----------------------+-----------------------+
| Name                  | Description           | Expected Results      |
+=======================+=======================+=======================+
| ARM Linux             | | Tests Linux         | | Successful          |
| TransportQmss         |   inter-process       |   completion on four  |
| Multi-Process Test    |   communication via   |   Linux processes.    |
|                       |   IPC transport over  |                       |
|                       |   QMSS. Reference     |                       |
|                       |   test for developers |                       |
+-----------------------+-----------------------+-----------------------+
| ARM Linux             | | Tests inter-SoC,    | Successful completion |
| TransportQmss         |   ARM Linux to DSP,   | on two DSP cores and  |
| Linux-Side of         |   transport over      | two Linux processes.  |
| Heterogeneous         |   QMSS. Reference     |                       |
| Processor Test        |   test for developers |                       |
+-----------------------+-----------------------+-----------------------+

Additional References
-----------------------

+-----------------------------------+-----------------------------------+
| **Document**                      | **Location**                      |
+-----------------------------------+-----------------------------------+
| TransportQmss API Reference       | $(TI_PDK_INSTALL_DIR)/packages/ti |
| Manual                            | /transport/ipc/c66/qmss/docs/doxy |
|                                   | gen/html/index.html               |
+-----------------------------------+-----------------------------------+
| TransportQmss Release Notes       | $(TI_PDK_INSTALL_DIR)/packages/ti |
|                                   | /transport/ipc/c66/qmss/docs/Rele |
|                                   | aseNotes_TransportQmss.pdf        |
+-----------------------------------+-----------------------------------+
| TransportSrio API Reference       | $(TI_PDK_INSTALL_DIR)/packages/ti |
| Manual                            | /transport/ipc/c66/srio/docs/doxy |
|                                   | gen/html/index.html               |
+-----------------------------------+-----------------------------------+
| TransportSrio Release Notes       | $(TI_PDK_INSTALL_DIR)/packages/ti |
|                                   | /transport/ipc/c66/srio/docs/Rele |
|                                   | aseNotes_TransportSrio.pdf        |
+-----------------------------------+-----------------------------------+


