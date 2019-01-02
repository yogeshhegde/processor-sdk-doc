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

+----------------------------------------+---------------------------------+------------------------------------------------+
| Config File                            | Description                     | Supported machines/platforms                   |
+========================================+=================================+================================================+
|                                        |                                 | am335x-evm, am437x-evm, am57xx-evm,            |
| processor-sdk-05.02.00.10-config.txt   | Processor SDK 5.2.0.10 Release  | am65xx-evm, k2hk-evm, k2e-evm, k2l-evm,        |
|                                        |                                 | k2g-evm, omapl138-lcdk                         |
+----------------------------------------+---------------------------------+------------------------------------------------+

