**************************
Yocto Layer Configuration
**************************

.. http://processors.wiki.ti.com/index.php/Processor_SDK_Building_The_SDK#Layer_Configuration

Processor SDK uses the following oe-layersetup configs to configure the
meta layers. These are the <config> used in the command:

``$ ./oe-layertool-setup.sh -f <config>``

|
| The following config files are located in the **configs/**
  directory of the **configs** directory.  The yocto config can also be
  downloaded directly from the SDK release page.

+------------------------+----------------------------------------------------+--------------------------------+
|      Config File       |                    Description                     | Supported machines             |
+========================+====================================================+================================+
| psdkla-07_01_01.txt    | Processor SDK Linux 07_01_01 Release               | am65xx-evm                     |
+------------------------+----------------------------------------------------+--------------------------------+
