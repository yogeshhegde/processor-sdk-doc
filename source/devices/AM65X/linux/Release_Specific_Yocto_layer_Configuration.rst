.. _yocto-layer-configuration:

**************************
Yocto Layer Configuration
**************************

.. http://processors.wiki.ti.com/index.php/Processor_SDK_Building_The_SDK#Layer_Configuration

Processor SDK uses the following oe-layersetup configs to configure the
meta layers. These are the <config> used in the command:

``$ ./oe-layertool-setup.sh -f <config>``

|
| The following config files are located in the **yocto-build/configs/processor-sdk-linux**
  directory.

+-------------------------------------+----------------------------------------------------+--------------------------------+
|      Config File                    |                    Description                     | Supported machines             |
+=====================================+====================================================+================================+
| processor-sdk-linux-08_02_00.txt    | Processor SDK Linux 08_02_00 Release               | am65xx-evm                     |
+-------------------------------------+----------------------------------------------------+--------------------------------+
