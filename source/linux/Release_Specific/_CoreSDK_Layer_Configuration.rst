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
    |  coresdk-09.00.00.006-config.txt  | CoreSDK 09.00.00 Sitara Release       | am64x 2.0, am62x, am62a                       |
    +-----------------------------------+---------------------------------------+-----------------------------------------------+
    |  coresdk-09.00.00.011-config.txt  | CoreSDK 09.00.00 Sitara Release       | am62sip                                       |
    +-----------------------------------+---------------------------------------+-----------------------------------------------+
    |  coresdk-09.01.00.001-config.txt  | CoreSDK 09.00.00 Sitara Release       | am335x, am437x                                |
    +-----------------------------------+---------------------------------------+-----------------------------------------------+

