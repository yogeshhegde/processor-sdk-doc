.. include:: /_replacevars.rst

GCC ToolChain
=============


The |__SDK_FULL_NAME__| package contains cross compile toolchains for the ARMv8
and ARMv7 architectures. These toolchains are used by the top level makefile when
compiling the binaries for the target. These also package an environment setup
script that, when sourced, sets all the right variables to compile binaries for
the target architecture. The toolchains installers are built through the yocto
build system, same as the target filesystem images themselves. Below sections give
more details about their usage.



linux-devkit
------------

.. rubric:: Overview

The |__SDK_FULL_NAME__| package comes with this toolchain preinstalled at linux-devkit/
directory within the SDK. Below paths are relative to the <SDK INSTALL DIR> and will be
referred to using the first column in the following sections.

.. list-table:: Linux Devkit Contents
   :widths: 20 30 50
   :header-rows: 1

   * - Variable
     - Location
     - Description
   * - TOOLCHAIN_PREFIX
     - linux-devkit/sysroots/x86_64-arago-linux/usr/bin/aarch64-oe-linux/aarch64-oe-linux-
     - Cross compiler toolchain for the ARMv8 architecture
   * - target_sysroot
     - linux-devkit/sysroots/aarch64-oe-linux/
     - Sysroot with the cross compiled libraries and headers for the ARMv8 architecture with Linux OS
   * - environment_setup_script
     - linux-devkit/environment-setup-aarch64-oe-linux
     - Shell script that sets environment variables to compile binaries for the ARMv8 linux target

.. rubric:: Target Sysroot
   :name: cross-compiled-libraries

The toolchain within the Linux SDK contains more than just the
cross-compiler, it also contains pre-built libraries that can be used
in your applications without requiring you to cross-compile them
yourself. These libraries include packages from alsa to zlib.
or a list of the
libraries you can refer to the software manifest found in the **<SDK
INSTALL DIR>/manifest** directory or look at the list of libraries
available in the **<target_sysroot>/usr/lib** directory. You will
also find the header files corresponding to these libraries in the
**<target_sysroot>/usr/include** directory. As
an example if your application wants access to the alsa asound library
then you can now do the following command:

.. code-block:: console

   host# ${TOOLCHAIN_PREFIX}gcc -lasound app.c -o app.out

.. rubric:: Environment-setup script
   :name: environment-setup-script

When cross-compiling packages that use configuration tools and autotools
there are many settings that are required to make sure that the proper
cross-compile libraries are used. The **environment-setup** script
located in the **<SDK INSTALL DIR>/linux-devkit** directory handles this
for you. This script exports variables to perform actions such as:

-  Adding the toolchain to the PATH
-  Setting up CPATH
-  Setting up PKG\_CONFIG\_\* paths
-  Setting standard variable such as CC, CPP, AR to the cross-compile
   values

To **use** the environment-setup script you only need to source it. This
is as simple as:

.. code-block:: console

   host# source ${environment_setup_script}

.. note::
   :name: when-compiling-the-linux-kernel

   Because environment-setup changes standard variables such as CC you
   should not use this script when compiler projects that build host-side
   as well as target-side tools. A prime example of this is the Linux
   kernel, which builds some host side tools to help during the kernel
   build. If the environment-setup script has been sourced then the CC
   value will specify the cross-compiler for the host-side tool build. This
   means that the tools compiled and used during the kernel build will be
   compiled for the ARM platform while the kernel build tries to run these
   tools on an Intel platform. This will cause the tools to fail to run and
   the kernel to fail to compile.


.. rubric:: Example usage
   :name: usage

In the simplest case the cross-compiler can be used to compile simple
applications that just need access to standard libraries. The
example below covers an application that uses only the standard libgcc
libraries.

1. First, create a **helloworld.c** file

   .. code-block:: c

      #include <stdio.h>
      
      int main() {
          printf ("Hello World from TI!!!\n");
          return 0;
      }

2. Compile the c file to generate an executable for the target architecture,
   using one of the below 2 methods:

   - **Compile Directly** : Cross-compile the **helloworld.c** file using the
     cross-compile toolchain directly

     .. code-block:: console

        host# ${TOOLCHAIN_PREFIX}gcc --sysroot=${target_sysroot} helloworld.c -o helloworld

     Be sure to give the correct path to the gcc cross compiler and target
     sysroot as listed earlier.

   - **Using the environement setup script** : Cross-compile after sourcing
     the setup script

     .. code-block:: console

        host# source ${environment_setup_script}
        host# ${CC} helloworld.c -o helloworld

3. After the above steps are run you should now have a **helloworld**
   executable in your directory that has been compiled for the ARM. A
   simple way to check this is to run the "file" command. It should
   return an output similar to below:

   .. code-block:: console

      host# file helloworld
      helloworld: ELF 64-bit LSB executable, ARM aarch64, version 1 (SYSV), dynamically linked, interpreter /lib/ld-linux-aarch64.so.1, BuildID[sha1]=bb96180ad71bd44e07fc148015a55c844134f30d, for GNU/Linux 3.14.0, with debug_info, not stripped

|



k3r5-devkit
-----------

.. rubric:: Overview

The |__SDK_FULL_NAME__| package comes with an ARMv7 toolchain preinstalled at k3r5-devkit/
directory within the SDK. Below paths are relative to the <SDK INSTALL DIR>.

.. list-table:: k3r5 Devkit Contents
   :widths: 20 30 50
   :header-rows: 1

   * - Variable
     - Location
     - Description
   * - TOOLCHAIN_PREFIX
     - k3r5-devkit/sysroots/x86_64-arago-linux/usr/bin/arm-oe-eabi/arm-oe-eabi-
     - Cross compiler toolchain for the ARMv7 architecture
   * - target_sysroot
     - k3r5-devkit/sysroots/armv7at2hf-vfp-oe-eabi/
     - Sysroot with the cross compiled libraries and headers for the ARMv7 architecture
   * - environment_setup_script
     - k3r5-devkit/environment-setup-armv7at2hf-vfp-oe-eabi
     - Shell script that sets environment variables to compile binaries for the target

|


