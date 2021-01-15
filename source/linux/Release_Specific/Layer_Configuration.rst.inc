**************************
Yocto Layer Configuration
**************************

.. http://processors.wiki.ti.com/index.php/Processor_SDK_Building_The_SDK#Layer_Configuration

Processor SDK uses the following oe-layersetup configs to configure the
meta layers. These are the <config> used in the command:

``$ ./oe-layertool-setup.sh -f <config>``

.. ifconfig:: CONFIG_sdk in ('PLSDK')

    |
    | The following config files are located in the **configs/processor-sdk**
      directory of the `oe-layersetup git repo <http://arago-project.org/git/projects/oe-layersetup.git>`_.

    +----------------------------------------+---------------------------------+------------------------------------------------+
    | Config File                            | Description                     | Supported machines/platforms                   |
    +========================================+=================================+================================================+
    |                                        |                                 | am57xx-evm                                     |
    | processor-sdk-06.03.00.106-config.txt  | Processor SDK 6.3.0.106 Release |                                                |
    +----------------------------------------+---------------------------------+------------------------------------------------+

.. ifconfig:: CONFIG_sdk in ('PSDKL')

    |
    | The following config files are located in the **configs/**
      directory of the **configs** directory.  The yocto config can also be
      downloaded directly from the SDK release page.

    +------------------------+----------------------------------------------------+--------------------------------+
    |      Config File       |                    Description                     | Supported machines             |
    +========================+====================================================+================================+
    | psdkla-07_01_00.txt    | Processor SDK Linux 07_01_00 Release               | j7-evm, j7200-evm, am65xx-evm  |
    +------------------------+----------------------------------------------------+--------------------------------+
