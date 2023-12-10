**************************
Yocto Layer Configuration
**************************

Processor SDK uses the following oe-layersetup configs to configure the
meta layers. These are the <config> used in the command:

``$ ./oe-layersetup.sh -f <config>``


    |
    | The following config files are located in the **configs/coresdk**
      directory of the `oe-layersetup git repo <https://git.ti.com/cgit/arago-project/oe-layersetup/>`_.

    +-----------------------------------+---------------------------------------+-----------------------------------------------+
    | Config File                       | Description                           | Supported machines/platforms                  |
    +===================================+=======================================+===============================================+
    |  coresdk-09.01.00.001-config.txt  | CoreSDK 09.00.00 Sitara Release       | am335x, am437x                                |
    +-----------------------------------+---------------------------------------+-----------------------------------------------+
    |  coresdk-09.01.00.007-config.txt  | CoreSDK 09.01.00 Sitara Release       | am65x                                         |
    +-----------------------------------+---------------------------------------+-----------------------------------------------+

