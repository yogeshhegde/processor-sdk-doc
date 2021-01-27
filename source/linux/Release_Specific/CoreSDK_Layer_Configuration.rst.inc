**************************
Yocto Layer Configuration
**************************

.. http://processors.wiki.ti.com/index.php/Processor_SDK_Building_The_SDK#Layer_Configuration

Processor SDK uses the following oe-layersetup configs to configure the
meta layers. These are the <config> used in the command:

``$ ./oe-layersetup.sh -f <config>``


    |
    | The following config files are located in the **configs/coresdk**
      directory of the `oe-layersetup git repo <http://arago-project.org/git/projects/oe-layersetup.git>`_.

    +-----------------------------------+-------------------------+--------------------------------------------------+
    | Config File                       | Description             | Supported machines/platforms                     |
    +===================================+=========================+==================================================+
    |  coresdk-07.02.00.004-config.txt  | CoreSDK 07.02.00 Release| am335x, am437x, am57xx, am654x, j7, j7200, am64xx|
    +-----------------------------------+-------------------------+--------------------------------------------------+

