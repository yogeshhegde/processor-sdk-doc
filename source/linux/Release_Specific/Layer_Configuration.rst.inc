**************************
Yocto Layer Configuration
**************************

.. http://processors.wiki.ti.com/index.php/Processor_SDK_Building_The_SDK#Layer_Configuration

Processor SDK uses the following oe-layersetup configs to configure the
meta layers. These are the <config> used in the command:

``$ ./oe-layersetup.sh -f <config>``

| 
| The following config files are located in the **configs/processor-sdk**
  directory of the `oe-layersetup git repo <http://arago-project.org/git/projects/oe-layersetup.git>`_.

+----------------------------------------+---------------------------------+------------------------------------------------------------------------------------------+
| Config File                            | Description                     | Supported machines/platforms                                                             |
+========================================+=================================+==========================================================================================+
| processor-sdk-04.03.00.05-config.txt   | Processor SDK 4.3.0.5 Release   | am335x-evm, am437x-evm, am57xx-evm, k2hk-evm, k2e-evm, k2l-evm, k2g-evm, omapl138-lcdk   |
+----------------------------------------+---------------------------------+------------------------------------------------------------------------------------------+

