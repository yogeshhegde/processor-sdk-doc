**************************
Yocto Layer Configuration
**************************

.. http://processors.wiki.ti.com/index.php/Processor_SDK_Building_The_SDK#Layer_Configuration

Processor SDK uses the following oe-layersetup configs to configure the
meta layers. These are the <config> used in the command:

``$ ./oe-layersetup.sh -f <config>``

.. ifconfig:: CONFIG_sdk in ('PLSDK')

    |
    | The following config files are located in the **configs/processor-sdk**
      directory of the `oe-layersetup git repo <http://arago-project.org/git/projects/oe-layersetup.git>`_.

    +----------------------------------------+---------------------------------+------------------------------------------------+
    | Config File                            | Description                     | Supported machines/platforms                   |
    +========================================+=================================+================================================+
    |                                        |                                 | am57xx-evm, am65xx-evm                         |
    | processor-sdk-06.02.00.81-config.txt   | Processor SDK 6.2.0.81 Release  |                                                |
    +----------------------------------------+---------------------------------+------------------------------------------------+

.. ifconfig:: CONFIG_sdk in ('PSDKLA')

    |
    | The following config files are located in the **configs/psdkla**
      directory of the **configs** directory.

    +------------------------+----------------------------------------------------+--------------------+
    |      Config File       |                    Description                     | Supported machines |
    +========================+====================================================+====================+
    | psdkla-06_01_00_05.txt | Processor SDK Linux Automotive 06_01_00_05 Release | j7-evm             |
    +------------------------+----------------------------------------------------+--------------------+
