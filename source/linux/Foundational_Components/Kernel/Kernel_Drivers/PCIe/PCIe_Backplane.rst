.. include:: /linux/replacevars.rst.inc

PCIe Backplane
---------------------------------

.. rubric:: **Introduction**
   :name: introduction-linux-pcie-backplane

PCIe backplane allows multiple hosts with RC ports to communicate and share
data with each other.

.. Image:: /images/j7-linux-pcie-backplane.png

PCIe backplane is implemented using multiple instances of multi-function
endpoint controller. Each host should be connected to a separate endpoint
controller instance and each host will enumerate the other host as an
independent function.

PCIe uses NTB (non transparent bridge) for two hosts to communicate with each
other. Though J721E doesn't have an explicit NTB controller, NTB functionality
can be achieved using multiple endpoint controller instances. And for PCIe
backplane (to connect more than 2 hosts), aggregation of NTB controllers
can be modeled using multiple instances of multi-function endpoint controller.

In the below diagram, PCI NTB function configures the SoC with multiple
PCIe Endpoint (EP) instances in such a way that transaction from one EP
controller is routed to the other EP controller. Once PCI NTB function
configures the SoC with multiple EP instances, HOST1 and HOST2 can
communicate with each other using SoC as a bridge.

.. code-block:: text

    +-------------+                                   +-------------+
    |             |                                   |             |
    |    HOST1    |                                   |    HOST2    |
    |             |                                   |             |
    +------^------+                                   +------^------+
           |                                                 |
           |                                                 |
 +---------|-------------------------------------------------|---------+
 |  +------v------+                                   +------v------+  |
 |  |             |                                   |             |  |
 |  |     EP      |                                   |     EP      |  |
 |  | CONTROLLER1 |                                   | CONTROLLER2 |  |
 |  |             <----------------------------------->             |  |
 |  |             |                                   |             |  |
 |  |             |                                   |             |  |
 |  |             |  SoC With Multiple EP Instances   |             |  |
 |  |             |  (Configured using NTB Function)  |             |  |
 |  +-------------+                                   +-------------+  |
 +---------------------------------------------------------------------+

.. rubric:: **NTB SW Architecture**
   :name: ntb-sw-architecture

The SW architecture for NTB both on the host side and EP side is given
below. The top half is the host side NTB architecture, and the bottom half is
the endpoint side NTB architecture.

.. Image:: /images/ntb_sw_architecture.png

.. rubric:: **Backplane Setup**
   :name: backplane-setup

The following picture shows J721E EVM connected to two DRA7 EVMs. Here the two
DRA7x boards communicate with each other using J721E as backplane.

.. Image:: /images/j7-backplane.jpg


.. rubric:: **Backplane Configuration**
   :name: backplane-configuration

.. rubric:: *Backplane DTS Overlay File*
   :name: backplane-configuration

The following DTS overlay file configures the PCIe controller in EP mode and
also contains a device tree node to create a NTB function device:

::

  arch/arm64/boot/dts/ti/k3-j721e-pcie-backplane.dtso

In order to apply the dts overlay file, the following command should be given
in u-boot prompt:

::

  #setenv name_overlays k3-j721e-pcie-backplane.dtbo

.. rubric:: *EP Side Configuration (J721E Backplane)*
   :name: ep-side-configuration

J721E backplane should be booted before any of the hosts are booted-up. Once the
kernel comes to prompt, the following commands should be given to start LTSSM
of PCIe0 and PCIe1:

::

  cd /sys/kernel/config/pci_ep/
  echo 1 > controllers/d800000.pcie-ep/start
  echo 1 > controllers/d000000.pcie-ep/start

(PCIe2 can also be configured for NTB, but that is not
tested yet).

.. rubric:: *RC Side Configuration*
   :name: rc-side-configuration

The hosts that have to communicate with each other can be bought up in any order
after EP has been brought up. Once the host boots up, the below steps have
to be done in each of the hosts.

Since the same vendor ID and device ID are used for multiple function drivers
(pci-endpoint-test and ntb_hw_epf), the device should be first ubound from
existing driver.

::

  echo 0000:01:00.0 > /sys/bus/pci/devices/0000\:01\:00.0/driver/unbind

After unbinding from existing driver, it should be bound to ntb_hw_epf driver.

::

  echo 0000:01:00.0 > /sys/bus/pci/drivers/ntb_hw_epf/bind

Then bind one of the NTB application driver. Here ntb_netdev is bound to emulate
ethernet over PCIe. This will create a new ethernet interface for each of the
hosts.

::

  modprobe ntb_transport
  modprobe ntb_netdev

.. rubric:: **Kernel Configs**
   :name: kernel-configs

.. rubric:: *EP Side (J721E Backplane)*
   :name: ep-side-configs

::

  CONFIG_PCI_ENDPOINT=y
  CONFIG_PCI_ENDPOINT_CONFIGFS=y
  CONFIG_PCI_EPF_NTB=y
  CONFIG_PCI_J721E=y
  CONFIG_PCIE_CADENCE=y
  CONFIG_PCIE_CADENCE_EP=y


.. rubric:: *Host Side*
   :name: rc-side-configs

::

  CONFIG_PCI=y
  CONFIG_PCI_MSI=y
  CONFIG_NTB=m
  CONFIG_NTB_EPF=m
  CONFIG_NTB_TRANSPORT=m
  CONFIG_NTB_NETDEV=m
  RC controller configs

.. rubric:: **Additional Information**
   :name: Additional Information

For additional information, please refer to:

::

  <Processor_SDK_install_dir>/board-support/linux-[ver]/Documentation/PCI/endpoint/pci-test-ntb.txt

