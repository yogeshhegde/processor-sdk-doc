.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_RT_Kernel_Release_Notes
.. rubric:: Real Time (RT) Linux Kernel Release Notes
   :name: real-time-rt-linux-kernel-release-notes

.. rubric:: Build Information
   :name: build-information

| The kernel git repository, branch and commit id can be found below:
| Based on:
| Kernel Version: 4.9.59
| RT Kernel Version: 4.9.59-rt23

| URL: git://git.ti.com/processor-sdk/processor-sdk-linux.git
| Branch: processor-sdk-linux-rt-04.02.00
| Commit ID: 273202a0d36d6cc2c0ca8bd2a9fd6333a7b69407

| Compiler Information: arm-linux-gnueabihf-gcc (Linaro GCC 6.2-2016.11)
  6.2.1 20161016
| Compiler Download Location:
  https://releases.linaro.org/components/toolchain/binaries/6.2-2016.11/
| Information on how to download and build the kernel can be found here:
  http://processors.wiki.ti.com/index.php/Linux_Kernel_Users_Guide

| 

.. rubric:: Generic Kernel Release Notes
   :name: generic-kernel-release-notes

| Generic kernel release notes from kernelnewbies.org can be found at:
  http://kernelnewbies.org/Linux_4.9
| Archived versions can be found at:
  http://kernelnewbies.org/LinuxVersions

.. rubric:: Issue Tracker
   :name: issue-tracker

.. rubric:: Known Issues
   :name: known-issues

+-------------+----------------+---------------------------------------------------------------------------+--------------------------+--------------------+----------------+------------------+
| **Key**     | **Priority**   | **Summary**                                                               | **Component/s**          | **Subcomponent**   | **Platform**   | **Workaround**   |
+-------------+----------------+---------------------------------------------------------------------------+--------------------------+--------------------+----------------+------------------+
| LCPD-7623   | P3-Medium      | Seeing SPI transfer failed error sometimes on k2hk when using rt kernel   | Connectivity             |                    | k2hk-evm       |                  |
+-------------+----------------+---------------------------------------------------------------------------+--------------------------+--------------------+----------------+------------------+
| LCPD-6663   | P3-Medium      | [RT] Kmemleak is buggy and boot is crashed randomly                       | Baseport, Connectivity   |                    |                |                  |
+-------------+----------------+---------------------------------------------------------------------------+--------------------------+--------------------+----------------+------------------+

