**************************
Yocto Layer Configuration
**************************

.. http://processors.wiki.ti.com/index.php/Processor_SDK_Building_The_SDK#Layer_Configuration

Processor SDK uses the following oe-layersetup configs to configure the
meta layers. These are the <config> used in the command:

``$ ./oe-layersetup.sh -f <config>``


    |
    | The following config files are located in the **configs/coresdk**
      directory of the `oe-layersetup git repo <https://git.ti.com/git/arago-project/oe-layersetup.git>`_.

    +-----------------------------------+---------------------------------------+-----------------------------------------------+
    | Config File                       | Description				| Supported machines/platforms			|
    +===================================+=======================================+===============================================+
    |  coresdk-08.06.00.006-config.txt  | CoreSDK 08.06.00 Jacinto Release	| j7, j7200, j721s2, j784s4			|
    +-----------------------------------+---------------------------------------+-----------------------------------------------+
    |  coresdk-08.06.00.007-config.txt	| CoreSDK 08.06.00 Sitara Release	| am65x, am64x 2.0, am62x, am62a		|
    +-----------------------------------+---------------------------------------+-----------------------------------------------+

