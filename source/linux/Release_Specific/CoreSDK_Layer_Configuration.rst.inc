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

    +-----------------------------------+-------------------------+--------------------------------------------------+
    | Config File                       | Description             | Supported machines/platforms                     |
    +===================================+=========================+==================================================+
    |  coresdk-08.00.00.004-config.txt  | CoreSDK 08.00.00 Release| am335x, am437x, am57xx, am654x, j7, j7200, am64xx|
    +-----------------------------------+-------------------------+--------------------------------------------------+

.. note::

    AM64xx uses the internal OE layer to build the u-boot with the latest updates from the ti-u-boot repository. To build the u-boot with yocto for AM64xx, user has to follow the below step,
   
    - Update the meta-ti layer's u-boot yocto recipe with the latest commit ID. 
	
	- For commit ID and other u-boot build information, refer to the AM64x `Release notes <Linux_Release_Notes.html#build-information>`__.
