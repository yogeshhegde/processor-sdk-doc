.. http://processors.wiki.ti.com/index.php/Processor_SDK_Bare_Metal_Examples 

.. rubric:: Overview
   :name: overview

The bare-metal examples gets user started with development of code
without an operating system. These are simple examples that does not get
into details of software components provided in the SDK. Consequently,
make sure there are no SD cards installed on the EVM with an OS prior to
exploring the following examples.

If you face any problems with CCS or JTAG, see try these
`troubleshooting
steps </index.php/Processor_SDK_RTOS_Setup_CCS#Troubleshooting>`__.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
All instructions on this wiki have been created using CCSv6 but should
apply to CCSv7. Please report any issues by posting on `E2E
forums <https://e2e.ti.com/>`__

.. raw:: html

   </div>

| 

.. rubric:: ARM Cortex-A15
   :name: arm-cortex-a15

In this article, we take a look at creating bare-metal hello world
examples for Cortex A15 core using pre-built templates in CCS. As a
sample we will use the AM572x device to describe the steps but the same
steps can be used for create hello world examples for Cortex A15 cores
in the Keystone 2 family of devices.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**

-  Only major difference between A15 examples for AM572x and Keystone 2
   is that the Keystone 2 device contain MSMC memory instead of OCMC
   memory as the shared memory.
-  For K2G devices, the hello world template will be created with the
   .lds file that specifies MSMC and DDR memory sections. For K2E and
   K2H, the CCS template doesn`t populate the .lds file. K2H & K2E users
   can choose to use 66AK2G02.lds located at ccsv6\ccs_base\arm\include
   as reference to add .lds file to their hello world projects.

.. raw:: html

   </div>

| 
| 1. Start CCS and create a work space for generating the project.

2. Click on File menu option and select New--> CCS Project.

3. Select Target as AM572x -Cortex A15 and GPEVM_AM572x as shown in the
image

4. Select **Cortex A setting** in the options below and provide name of
the project as "hello_world" and use default Advanced settings for the
project. If the Default settings uses "TI ARM compiler 5.x.x" switch to
**GNU Linaro 4.8.4** (or higher) tool chain for A15 and check the build
**little** endian **ELF** binary for the A15 core. Under Project
templates and examples, select **Basic Examples-> Hello World**

Click Finish after you are done to allow CCS to auto generate the
project from the template **Basic Examples-> Hello World**.

.. Image:: ../images/NewCCSProject_Hello_world.png

5. The generated CCS project contains source file **main.c**, ARM
assembly code **startup_ARMCA15.S** and a linker command file
**AM572x.lds**. Please modify the main.c file by adding the following
highlighted code lines and save main.c file.

.. raw:: html

   <div class="mw-geshi mw-code mw-content-ltr" dir="ltr">

.. raw:: html

   <div class="c source-c">

.. code:: de1

      /*
      * hello.c
      */ 
      #include <stdio.h>
     
      int main(void) { 
     
          printf("Hello_world\n");
          return 0; 
     }

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
For Keystone2 users, the startup_ARMCA15.S and .lds file is not auto
populated by CCS. To add these file, right click the project and add
files and locate the 66AK2Gxx.lds and startup_ARMCA15.S under the file
path ccsvX/ccs_base/arm/include and add them to the project

.. raw:: html

   </div>

6. Ensure that CCSv6 generated linker command file **AM572x.lds**
contains the following Memory configurations.

.. raw:: html

   <div class="mw-geshi mw-code mw-content-ltr" dir="ltr">

.. raw:: html

   <div class="c source-c">

.. code:: de1

     MEMORY
     {
        OCMC_RAM1 :  o = 0x40300000,  l = 0x00080000  /* 512kB L3 OCMC RAM1 */
        OCMC_RAM2 :  o = 0x40400000,  l = 0x00100000  /* 1MB L3 OCMC RAM2 */
        OCMC_RAM3 :  o = 0x40500000,  l = 0x00100000  /* 1MB L3 OCMC RAM3 */
        DDR0 :       o = 0x80000000,  l = 0x40000000  /* 1GB external DDR Bank 0 */
        DDR1 :       o = 0xC0000000,  l = 0x40000000  /* 1GB external DDR Bank 1 */
     }

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
For Keystone 2 devices, replace all the OCMC_RAM# regions in the lds
file and replace it with MSMC memory section as shown below. Refer to
66AK2G02.lds file in ccs installation under directory path
ccsv6\ccs_base\arm\include

.. raw:: html

   </div>

::

       MSMC  :      o=0x0c000000,    l = 0x00600000  /* 6MB Muticore shared memory */ 

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
The .lds file expects users to provide STACKSIZE and HEAPSIZE from
linker settings. To provide these settings got to Build Settings GNU
Linker add the following to the Symbols section. Keystone II devices
require this to be done explicitly in the linker settings

.. raw:: html

   </div>

::

    STACKSIZE=10000
    HEAPSIZE=400

7. Right click on the project and select Build Project, to build the
project and generate hello_world.out.

8. Launch target configuration using your emulator to connect to AM572X
EVM as described in the :ref:`Processor-SDK-RTOS-Getting-Started-Guide-label`.

9. Right click **CortexA15_0** and select connect target.

10. Initialize DDR configuration. On CCS --> Scripts --> DDR
configurations --> AM572_DDR3_532MHz_config

11. Load and run hello_world.out example file. You should see
**Hello_world** string displayed on CCS console window.

.. Image:: ../images/HelloWorldOutput.jpg

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**

-  If the example does not load correctly in the first attempt, reload
   and **ensure ARM core starts at main**.
-  If the ARM loads correctly but you don`t see any output then check to
   see if the GNU linker is linking to Semihosting library (librdimon)
   in the linker setting. If it is not linked go to GNU linker settings
   in CCS project and add **"rdimon"** to the libraries that are linked

.. raw:: html

   </div>
   
| 

.. rubric:: ARM Cortex-A9
   :name: arm-cortex-a9

1. Start CCSv6 and create a work space for generating the project.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
CCSv6.1.1 doesn`t contain a hello world project template for Cortex A9
core using GNU Linaro 4.8.x tool chain. Due to code compatibility of
Cortex A8 and cortex A9 platforms, We recommend that you create a
project for Cortex A8 platform like AM335x using the GNU Linaro tool
chain and then use the code to test hello world application on the
Cortex A9 on the AM437x platform. If you wish to use TI ARM compiler
5.2.x, then you can use the default hello world template in CCSv6 for
the Cortex A9 on AM437x

.. raw:: html

   </div>

2. Click on File menu option and select New--> CCS Project. Steps assume
that user is using GN Linaro tool chain for Cortex A9.

3. Select Target as AM33xx -Cortex A8 and appropriate target Board
setting as shown in the image

4. Select **Cortex A8** setting in the options below and provide name of
the project as "hello_world_a9" and use default Advanced settings for
the project. If the Default settings uses "TI ARM compiler 5.x.x" switch
to **GNU Linaro 4.8.4** (or higher) tool chain for A9 and check the
build **little** endian **ELF** binary for the A9 core. Click Finish
after you are done to allow CCS to auto generate the project from the
template **Basic Examples-> Hello World**.

.. Image:: ../images/Bare-Metal_A9_templateselect.jpg

5. The generated CCS project contains source file **main.c**, ARM
assembly code **startup_ARMCA8.S** and a linker command file
**AM335x.lds**. The startup file does some basic setup and there is no
difference between A8 and A9, so it can be used directly on A9 target.
Ensure the main.c file contains the following code

.. raw:: html

   <div class="mw-geshi mw-code mw-content-ltr" dir="ltr">

.. raw:: html

   <div class="c source-c">

.. code:: de1

      /*
      * hello.c
      */ 
      #include <stdio.h>
     
      int main(void) { 
     
          printf("Hello_world\n");
          return 0; 
     }

.. raw:: html

   </div>

.. raw:: html

   </div>

6. Ensure that CCSv6 generates the linker command file **AM335x.lds**.

.. raw:: html

   <div class="mw-geshi mw-code mw-content-ltr" dir="ltr">

.. raw:: html

   <div class="c source-c">

.. code:: de1

     MEMORY
     {
        SRAM :     o = 0x402F0400,  l = 0x0000FC00  /* 64kB internal SRAM */
        L3OCMC0 :  o = 0x40300000,  l = 0x00010000  /* 64kB L3 OCMC SRAM */
        M3SHUMEM : o = 0x44D00000,  l = 0x00004000  /* 16kB M3 Shared Unified Code Space */
        M3SHDMEM : o = 0x44D80000,  l = 0x00002000  /* 8kB M3 Shared Data Memory */
        DDR0 :     o = 0x80000000,  l = 0x40000000  /* 1GB external DDR Bank 0 */
     }

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
An optional step is to modify the section definition in AM437x.lds file
if you wish to introduce more sections or partition the existing
sections. If you renamed the startup file from startup_ARMCA8.S to
startup_ARMCA9.S in your project, then the linker command file needs to
be updated as well for code section placement: from startup_ARMCA8.o
(.text) to startup_ARMCA9.o (.text)

.. raw:: html

   </div>

7. Now build the project to generate hello_world.out file.

8. Launch target configurations using your emulator to connect to AM335X
EVM as described in the `Getting Started
Guide </index.php/Processor_SDK_RTOS_Getting_Started_Guide>`__.

9. Right click CortexA9 and connect target. The on target functionality
in the GEL will initialize the clocks and DDR.

10. Load and run hello_world_a9.out file. You should see **Hello
World!** string displayed on CCS console window.

.. Image:: ../images/Hello_world_a9.jpg

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
If the example does not load correctly in the first attempt, reload and
**ensure ARM core starts at main**.

.. raw:: html

   </div>

| 

.. rubric:: ARM Cortex-A8
   :name: arm-cortex-a8

1. Start CCSv6 and create a work space for generating the project.

2. Click on File menu option and select New--> CCS Project.

3. Select Target as AM33xx -Cortex A8 and appropriate target Board
setting as shown in the image

4. Select **Cortex A8** setting in the options below and provide name of
the project as "hello_world_a8" and use default Advanced settings for
the project. If the Default settings uses "TI ARM compiler 5.x.x" switch
to **GNU Linaro 4.8.4** (or higher) tool chain for A8 and check the
build **little** endian **ELF** binary for the A8 core. Click Finish
after you are done to allow CCS to auto generate the project from the
template **Basic Examples-> Hello World**.

.. Image:: ../images/Bare-Metal_A8_templateselect.jpg

5. The generated CCS project contains source file **hello.c**, ARM
assembly code **startup_ARMCA8.S** and a linker command file
**AM335x.lds**. Ensure the main.c file contains the following code

.. raw:: html

   <div class="mw-geshi mw-code mw-content-ltr" dir="ltr">

.. raw:: html

   <div class="c source-c">

.. code:: de1

      /*
      * hello.c
      */ 
      #include <stdio.h>
     
      int main(void) { 
     
          printf("Hello_world\n");
          return 0; 
     }

.. raw:: html

   </div>

.. raw:: html

   </div>

6. Ensure that CCSv6 generates the linker command file **AM335x.lds**.

.. raw:: html

   <div class="mw-geshi mw-code mw-content-ltr" dir="ltr">

.. raw:: html

   <div class="c source-c">

.. code:: de1

     MEMORY
     {
        SRAM :     o = 0x402F0400,  l = 0x0000FC00  /* 64kB internal SRAM */
        L3OCMC0 :  o = 0x40300000,  l = 0x00010000  /* 64kB L3 OCMC SRAM */
        M3SHUMEM : o = 0x44D00000,  l = 0x00004000  /* 16kB M3 Shared Unified Code Space */
        M3SHDMEM : o = 0x44D80000,  l = 0x00002000  /* 8kB M3 Shared Data Memory */
        DDR0 :     o = 0x80000000,  l = 0x40000000  /* 1GB external DDR Bank 0 */
     }

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
An optional step is to modify the section definition in AM335x.lds file
if you wish to introduce more sections or partition the existing
sections.

.. raw:: html

   </div>

7. Now build the project to generate hello_world_a8.out file.

8. Launch target configurations using your emulator to connect to AM335X
EVM as described in the `Getting Started
Guide </index.php/Processor_SDK_RTOS_Getting_Started_Guide>`__.

9. Right click CortexA8 and select connect target. The on target
functionality in the GEL will initialize the clocks and DDR.

10. Load and run hello_world_a8.out file. You should see **Hello
World!** string displayed on CCS console window.

.. Image:: ../images/Hello_world_a8.jpg

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
If the example does not load correctly in the first attempt, reload and
**ensure ARM core starts at main**.

.. raw:: html

   </div>

| 

.. rubric:: ARM Coretex-M4
   :name: arm-coretex-m4

1. Start CCSv6 and create a work space for generating the project.

2. Click on File menu option and select New--> CCS Project.

3. Select Target as AM572x -Cortex M4 and GPEVM_AM572x as shown in the
image

4. Select **Cortex M** setting in the options below and provide name of
the project as "hello_world_m4" and use default Advanced settings for
the project. Click Finish after you are done to allow CCS to auto
generate the project from the template **Basic Examples-> Hello World**.
The Default settings uses "TI ARM compiler 5.x.x" tool chain for cortex
M4 and sets the build for **little** endian **ELF** binary for the M4
core.

.. Image:: ../images/Bare-Metal_M4_templateselect.jpg

5. The generated CCS project contains only one source file **hello.c**.
Ensure the main.c file contains the following code

.. raw:: html

   <div class="mw-geshi mw-code mw-content-ltr" dir="ltr">

.. raw:: html

   <div class="c source-c">

.. code:: de1

      /*
      * hello.c
      */ 
      #include <stdio.h>
     
      int main(void) { 
     
          printf("Hello_world\n");
          return 0; 
     }

.. raw:: html

   </div>

.. raw:: html

   </div>

6. CCSv6 includes a default linker command file(AM57xx_CM4.cmd) for the
M4 (IPU) core which will place code into appropriate device memory. The
linker command file has the following memory sections.

.. raw:: html

   <div class="mw-geshi mw-code mw-content-ltr" dir="ltr">

.. raw:: html

   <div class="c source-c">

.. code:: de1

    MEMORY
    {
        IRAM:      o = 0x00000000 l = 0x00001000   /* 4kB internal SRAM */
        OCMC_RAM1: o = 0x40300000 l = 0x00080000   /* 512kB L3 OCMC SRAM1 */
        OCMC_RAM2: o = 0x40400000 l = 0x00100000   /* 1MB L3 OCMC SRAM2 */
        OCMC_RAM3: o = 0x40500000 l = 0x00100000   /* 1MB L3 OCMC SRAM3 */
        DDR0:      o = 0x80000000 l = 0x40000000   /* 1GB external DDR Bank 0 */
    }

.. raw:: html

   </div>

.. raw:: html

   </div>

The linker command file is designed to place code in OCMC memory with
interrupt vectors and .intc_txt generated by the compiler being place in
device internal memory.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**

-  Please note that if the device GEL files are setting up MMU for the
   core then the code will not load correctly on the core and will cause
   a CPU exception. We recommend that you modify the linker command file
   appropriately to match the MMU settings in the GEL file. The linker
   command file in all CCS releases prior to CCS 6.1.3 don`t account for
   this MMU Setting in AM57xx GEL files. Please modify the OCMC
   addresses to the logical address set in the GEL file
-  An optional step is to modify the section definition in
   AM57xx_CM4.cmd file if you wish to introduce/partition existing
   sections or place the code in different memory section.

.. raw:: html

   </div>

7. Now build the project to generate hello_world_m4.out.

8. Launch target configurations using your emulator to connect to AM572X
EVM as described in the `Getting Started
Guide </index.php/Processor_SDK_RTOS_Getting_Started_Guide>`__.

9. In order to wake up the M4 core from A15, Go to Menu option
Scripts->AM572x_Multicore_Initialization->IPU1SSClkEnable_API. Refer to
the
`Processor_SDK_RTOS_Setup_CCS </index.php/Processor_SDK_RTOS_Setup_CCS#Connect_to_Slave_cores_on_AM57xx_devices>`__.

You should see the following log in the Console

::

     CortexA15_0: GEL Output: --->>> IPU1SS Initialization is in progress ... <<<---
     CortexA15_0: GEL Output: --->>> IPU1SS Initialization is DONE! <<<---

11. Select and Connect to Cortex_M4_IPU1_C0. Load and run
Hello_Example_m4.out file. You should see **Hello World** string
displayed on console window.

.. Image:: ../images/Hello_world_m4.jpg

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
If the example does not load correctly in the first attempt, reload and
**ensure ARM core starts at main**.

.. raw:: html

   </div>

| 

.. rubric:: DSP C66x
   :name: dsp-c66x

In this article, we take a look at creating bare-metal hello world
examples for C66x core using pre-built templates in CCS. As a sample we
will use the AM572x device to describe the steps but the same steps can
be used for create hello world examples for C66x cores in the Keystone 2
family of devices.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
Only major difference C66x examples for AM572x and Keystone 2 is that
the Keystone 2 device contain MSMC memory instead of OCMC memory as the
shared on chip memory.

.. raw:: html

   </div>

1. Start CCSv6 and create a work space for generating the project.

2. Click on File menu option and select New--> CCS Project.

3. Select Target as AM572x -C66xx and GPEVM_AM572x as shown in the image

4. Select **C66XX [C6000]** DSP setting in the options below and provide
name of the project as "hello_world_dsp" and use default Advanced
settings for the project. Click Finish after you are done to allow CCS
to auto generate the project from the template **Basic Examples-> Hello
World**. The Default settings uses "TI CG Tools compiler 8.x.x" tool
chain for C66x and sets the build for **little** endian **ELF** binary
for the C66x core.

.. Image:: ../images/Bare-Metal_C66x_templateselect.jpg

5. The generated CCS project contains only one source file **hello.c**.
Ensure the main.c file contains the following code

.. raw:: html

   <div class="mw-geshi mw-code mw-content-ltr" dir="ltr">

.. raw:: html

   <div class="c source-c">

.. code:: de1

      /*
      * hello.c
      */ 
      #include <stdio.h>
     
      int main(void) { 
     
          printf("Hello_world\n");
          return 0; 
     }

.. raw:: html

   </div>

.. raw:: html

   </div>

6. CCSv6 includes a default linker command file(AM57xx_C66.cmd) for the
C66x DSP core which will place code into appropriate device memory. The
linker command file has the following memory sections.

.. raw:: html

   <div class="mw-geshi mw-code mw-content-ltr" dir="ltr">

.. raw:: html

   <div class="c source-c">

.. code:: de1

    MEMORY
    {
        IRAM_MEM:  o = 0x00800000 l = 0x00008000   /* 32kB internal SRAM */
        OCMC_RAM1: o = 0x40300000 l = 0x00080000   /* 512kB L3 OCMC SRAM1 */
        OCMC_RAM2: o = 0x40400000 l = 0x00100000   /* 1MB L3 OCMC SRAM2 */
        OCMC_RAM3: o = 0x40500000 l = 0x00100000   /* 1MB L3 OCMC SRAM3 */
        DDR0:      o = 0x80000000 l = 0x40000000   /* 1GB external DDR Bank 0 */
    }

.. raw:: html

   </div>

.. raw:: html

   </div>

The linker command file is designed to place code in OCMC memory.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
For Keystone 2 devices, replace all the OCMC_RAM# regions in the lds
file and replace it with MSMC memory section as shown below.

.. raw:: html

   </div>

::

       MSMC  :      o=0x0c000000,    l = 0x00600000  /* 6MB Muticore shared memory */ 

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
An optional step is to modify the section definition in linker command
file if you wish to introduce/partition existing sections or place the
code in different memory section.

.. raw:: html

   </div>

7. Now build the project to generate hello_world_dsp.out.

8. Launch target configurations using your emulator to connect to AM572X
EVM as described in the `Getting Started
Guide </index.php/Processor_SDK_RTOS_Getting_Started_Guide>`__.

9. In order to wake up the DSP1 core from A15, Go to Menu option
Scripts->AM572x_Multicore_Initialization->DSP1SSClkEnable_API. Refer to
the
`Processor_SDK_RTOS_Setup_CCS </index.php/Processor_SDK_RTOS_Setup_CCS#Connect_to_Slave_cores_on_AM57xx_devices>`__.

You should see the following log in the Console

::

     CortexA15_0: GEL Output: --->>> DSP1SS Initialization is in progress ... <<<---
     CortexA15_0: GEL Output: DEBUG: Clock is active ... 
     CortexA15_0: GEL Output: DEBUG: Checking for data integrity in DSPSS L2RAM ... 
     CortexA15_0: GEL Output: DEBUG: Data integrity check in GEM L2RAM is sucessful! 
     CortexA15_0: GEL Output: --->>> DSP1SS Initialization is DONE! <<<---

11. Select and Connect to C66x_DSP1. Load and run hello_world_dsp.out
file. You should see **Hello World** string displayed on console window.

.. Image:: ../images/Hello_world_dsp.jpg

| 

.. rubric:: DSP C674x
   :name: dsp-c674x

In this article, we take a look at creating bare-metal hello world
examples for C674x core using pre-built templates in CCS. As a sample we
will use the C6748 LCDK device to describe the steps but the same steps
can be used for create hello world examples for C674x cores in the
OMAPL13x/C647x/DA8x family of devices.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
All the C674x DSP cores on in OMAPL13x/C674x/DA8x have the same memory
map so modification are limited to selecting the correct platform when
generating the project

.. raw:: html

   </div>

1. Start CCS and create a work space for generating the project.

2. Click on File menu option and select New--> CCS Project.

3. Select Target as OMAPLx -C674xx and LCDK674x as shown in the image

4. Select **C67XX [C6000]** DSP setting in the options below and provide
name of the project as "hello_world_lcdk674x" and use default Advanced
settings for the project. Click Finish after you are done to allow CCS
to auto generate the project from the template **Basic Examples-> Hello
World**. The Default settings uses "TI CG Tools compiler 8.x.x" tool
chain for C674x and sets the build for **little** endian **ELF** binary
for the C674x core.

.. Image:: ../images/Baremetal_helloWorld_ProjectCreate_step1.png

5. The generated CCS project contains only one source file **hello.c**.
Ensure the main.c file contains the following code

.. raw:: html

   <div class="mw-geshi mw-code mw-content-ltr" dir="ltr">

.. raw:: html

   <div class="c source-c">

.. code:: de1

      /*
      * hello.c
      */ 
      #include <stdio.h>
     
      int main(void) { 
     
          printf("Hello_world\n");
          return 0; 
     }

.. raw:: html

   </div>

.. raw:: html

   </div>

6. CCS includes a default linker command file(C6748.cmd) for the C674x
DSP core which will place code into appropriate device memory. The
linker command file has the following memory sections.

.. raw:: html

   <div class="mw-geshi mw-code mw-content-ltr" dir="ltr">

.. raw:: html

   <div class="c source-c">

.. code:: de1

    MEMORY
    {
        DSPL2ROM     o = 0x00700000  l = 0x00100000   /* 1MB L2 Internal ROM */
        DSPL2RAM     o = 0x00800000  l = 0x00040000   /* 256kB L2 Internal RAM */
        DSPL1PRAM    o = 0x00E00000  l = 0x00008000   /* 32kB L1 Internal Program RAM */
        DSPL1DRAM    o = 0x00F00000  l = 0x00008000   /* 32kB L1 Internal Data RAM */
        SHDSPL2ROM   o = 0x11700000  l = 0x00100000   /* 1MB L2 Shared Internal ROM */
        SHDSPL2RAM   o = 0x11800000  l = 0x00040000   /* 256kB L2 Shared Internal RAM */
        SHDSPL1PRAM  o = 0x11E00000  l = 0x00008000   /* 32kB L1 Shared Internal Program RAM */
        SHDSPL1DRAM  o = 0x11F00000  l = 0x00008000   /* 32kB L1 Shared Internal Data RAM */
        EMIFACS0     o = 0x40000000  l = 0x20000000   /* 512MB SDRAM Data (CS0) */
        EMIFACS2     o = 0x60000000  l = 0x02000000   /* 32MB Async Data (CS2) */
        EMIFACS3     o = 0x62000000  l = 0x02000000   /* 32MB Async Data (CS3) */
        EMIFACS4     o = 0x64000000  l = 0x02000000   /* 32MB Async Data (CS4) */
        EMIFACS5     o = 0x66000000  l = 0x02000000   /* 32MB Async Data (CS5) */
        SHRAM        o = 0x80000000  l = 0x00020000   /* 128kB Shared RAM */
        DDR2         o = 0xC0000000  l = 0x20000000   /* 512MB DDR2 Data */
    }

.. raw:: html

   </div>

.. raw:: html

   </div>

The linker command file is designed to place code in OCMC memory.

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
For OMAPL13x/C674x devices, the linker command file places code in the
SHRAM memory section as shown below.

.. raw:: html

   </div>

::

       SECTIONS                                       
      {                                              
       .text          >  SHRAM                    
       .stack         >  SHRAM                    
       .bss           >  SHRAM      
        .......

}

.. raw:: html

   <div
   style="margin: 5px; padding: 2px 10px; background-color: #ecffff; border-left: 5px solid #3399ff;">

**NOTE**
An optional step is to modify the section definition in linker command
file if you wish to introduce/partition existing sections or place the
code in different memory section.

.. raw:: html

   </div>

7. Now build the project by right clicking on the Project and selecting
"Build Project" to generate hello_world_lcdk674x.out.

8. Launch target configurations using your emulator to connect to
OMAPLx/C674x LCDK as described in the `Getting Started
Guide </index.php/Processor_SDK_RTOS_Getting_Started_Guide>`__.

9. Developers can Connect to the C674x on OMAPL137/C6747/C6748 can
connect directly to the DSP. For OMAPL138 device, you will need to
connect to the ARM as this is ARM master boot device and ARM needs to
power up the DSP You should see the following log in the Console

::

    C674X_0: Output:   Target Connected.
    C674X_0: Output:    ---------------------------------------------
    C674X_0: Output:    Memory Map Cleared.
    C674X_0: Output:    ---------------------------------------------
    C674X_0: Output:    Memory Map Setup Complete.
    C674X_0: Output:    ---------------------------------------------
    C674X_0: Output:    PSC Enable Complete.
    C674X_0: Output:    ---------------------------------------------
    C674X_0: Output:    PLL0 init done for Core:300MHz, EMIFA:25MHz
    C674X_0: Output:    DDR initialization is in progress....
    C674X_0: Output:    PLL1 init done for DDR:150MHz
    C674X_0: Output:    Using DDR2 settings
    C674X_0: Output:    DDR2 init for 150 MHz is done
    C674X_0: Output:    ---------------------------------------------

| 

11. Select and Connect to C674x. Load and run hello_world_dsp.out file.
You should see **Hello World** string displayed on console window.

.. Image:: ../images/Hello_world_dsp674x.png

| 

.. raw:: html

