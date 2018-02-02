.. http://processors.wiki.ti.com/index.php/Linux_Core_PCIe_EP_User%27s_Guide
.. rubric:: **Introduction**
   :name: introduction

PCI controller IPs integrated in DRA7x/AM57x and 66AK2G SoCs are capable
of operating either in Root Complex mode (host) or Endpoint mode
(device). When operating in endpoint mode, the controller can be
configured to be used as any function depending on the use case ('Test
endpoint' is the only PCIe EP function supported in Linux kernel right
now)

This wiki page provides usage information of PCIe EP Linux driver.

.. rubric:: **Setup Details**
   :name: setup-details

The following boards have standard female connector

+-----------------+
| dra74x-evm      |
+-----------------+
| dra72x-evm      |
+-----------------+
| am571x-idk      |
+-----------------+
| am572x-idk      |
+-----------------+
| 66ak2g-gp-evm   |
+-----------------+

These boards are by default intended to be operated in Root Complex
mode. So in order to connect two boards, a specialized cable like below
is required.

|PCIe male-to-male connector|

This cable can be obtained from http://www.adexelec.com/pciexp.htm. Use
either X1 cable or X4 cable depending on the slot provided in the board.
The part number is PE-FLEX1-MM-CX-3" (for 3" cable length x1)

Modify the cable to remove resistors in CK+ and CK- in order to avoid
ground loops (power) and smoking clock drivers (clk+/-).

The ends of the modified cable should look like below

   |image2|

   B side

   |image3|

   A side

   |image4|

   A side side2

   |image5|

   B side side2


Image of a dra72-evm and dra7-evm connected back to back. There is no
restriction on which end of the cable should be connected to host and
device.


.. Image:: ../images/Back-to-back.jpeg

| 
| |Note|\ **Note:** For AM572x GP EVM, there is a Mini PCIe connector on
  the LCD board. To connect 2 boards involving a AM572x GP EVM, a
  mPCIe-to-PCIe adapter is needed.

.. Image:: ../images/MPCIe-to-PCIe_Adapter.jpg

.. rubric:: **EP Device**
   :name: ep-device

.. rubric:: *DTS Modification*
   :name: dts-modification

The default dts is configured to be used in root complex mode. In order
to use it in endpoint mode, the following changes has to be made in dts
file.

To configure dra7-evm in EP mode:

::

    diff --git a/arch/arm/boot/dts/dra7-evm.dts b/arch/arm/boot/dts/dra7-evm.dts
    index eedd930..93d9f17 100644
    --- a/arch/arm/boot/dts/dra7-evm.dts
    +++ b/arch/arm/boot/dts/dra7-evm.dts
    @@ -1084,7 +1084,7 @@
            vdd-supply = <&smps7_reg>;
     };

    -&pcie1_rc {
    +&pcie1_ep {
            status = "okay";
     };

To configure dra72-evm in EP mode:

::

    diff --git a/arch/arm/boot/dts/dra72-evm-common.dtsi b/arch/arm/boot/dts/dra72-evm-common.dtsi
    index f914e6a..9697ea3 100644
    --- a/arch/arm/boot/dts/dra72-evm-common.dtsi
    +++ b/arch/arm/boot/dts/dra72-evm-common.dtsi
    @@ -708,6 +708,6 @@
            watchdog-timers = <&timer10>;
     };

    -&pcie1_rc {
    +&pcie1_ep {
            status = "okay";
     };

To configure am572x-idk in EP mode:

::

    diff --git a/arch/arm/boot/dts/am572x-idk.dts b/arch/arm/boot/dts/am572x-idk.dts
    index b2edeab..1ef70b3 100644
    --- a/arch/arm/boot/dts/am572x-idk.dts
    +++ b/arch/arm/boot/dts/am572x-idk.dts
    @@ -428,11 +428,11 @@
     };

     &pcie1_rc {
    -       status = "okay";
            gpios = <&gpio3 23 GPIO_ACTIVE_HIGH>;
     };

     &pcie1_ep {
    +       status = "okay";
            gpios = <&gpio3 23 GPIO_ACTIVE_HIGH>;
     };

.. rubric:: *Linux Driver Configuration*
   :name: linux-driver-configuration

The following config options has to be enabled in order to configure the
PCI controller to be used as a "Endpoint Test" function driver.

::

    CONFIG_PCI_ENDPOINT=y
    CONFIG_PCI_EPF_TEST=y
    CONFIG_PCI_DRA7XX_EP=y

.. rubric:: *Endpoint Controller devices and Function drivers*
   :name: endpoint-controller-devices-and-function-drivers

To find the list of endpoint controller devices in the system:

::

    # ls /sys/class/pci_epc/
      51000000.pcie_ep

To find the list of endpoint function drivers in the system:

::

    # ls /sys/bus/pci-epf/drivers
      pci_epf_test

.. rubric:: *Using the pci-epf-test function driver*
   :name: using-the-pci-epf-test-function-driver

The pci-epf-test function driver can be used to test the endpoint
functionality of the PCI controller. Some of the tests that's currently
supported are

-  BAR tests
-  Interrupt tests (legacy/MSI)
-  Read tests
-  Write tests
-  Copy tests

.. rubric:: 4.4 Kernel
   :name: kernel

.. rubric:: creating pci-epf-test device
   :name: creating-pci-epf-test-device

PCI endpoint function device can be created using the configfs. To
create pci-epf-test device, the following commands can be used

::

    # mount -t configfs none /sys/kernel/config
    # cd /sys/kernel/config/pci_ep/
    # mkdir pci_epf_test.0

The "mkdir pci\_epf\_test.0" above creates the pci-epf-test function
device. The name given to the directory preceding '.' should match with
the name of the driver listed in '/sys/bus/pci-epf/drivers' in order for
the device to be bound to the driver.

The PCI endpoint framework populates the directory with configurable
fields.

::

    # cd pci_epf_test.0
    # ls
      baseclass_code    function    revid      vendorid
      cache_line_size   interrupt_pin   subclass_code
      deviceid             peripheral   subsys_id
      epc               progif_code subsys_vendor_id

The driver populates these entries with default values when the device
is bound to the driver. The pci-epf-test driver populates vendorid with
0xffff and interrupt\_pin with 0x0001

::

    # cat vendorid
      0xffff
    # cat interrupt_pin
      0x0001

| 

.. rubric:: configuring pci-epf-test device
   :name: configuring-pci-epf-test-device

The user can configure the pci-epf-test device using the configfs. In
order to change the vendorid and the number of MSI interrupts used by
the function device, the following command can be used.

::

    # echo 0x104c > vendorid
    # echo 16 >  msi_interrupts

.. rubric:: Binding pci-epf-test device to a EP controller
   :name: binding-pci-epf-test-device-to-a-ep-controller

In order for the endpoint function device to be useful, it has to be
bound to a PCI endpoint controller driver. Use the configfs to bind the
function device to one of the controller driver present in the system.

::

    # echo "51000000.pcie_ep" > epc

Once the above step is completed, the PCI endpoint is ready to establish
a link with the host.

.. rubric:: 4.9 Kernel
   :name: kernel-1

.. rubric:: creating pci-epf-test device
   :name: creating-pci-epf-test-device-1

PCI endpoint function device can be created using the configfs. To
create pci-epf-test device, the following commands can be used

::

    # mount -t configfs none /sys/kernel/config
    # cd /sys/kernel/config/pci_ep/
    # mkdir dev
    # mkdir dev/epf/pci_epf_test.0

The "mkdir dev/epf/pci\_epf\_test.0" above creates the pci-epf-test
function device. The name given to the directory preceding '.' should
match with the name of the driver listed in '/sys/bus/pci-epf/drivers'
in order for the device to be bound to the driver.

The PCI endpoint framework populates the directory with configurable
fields.

::

    # ls dev/epf/pci_epf_test.0/
      baseclass_code    function    revid      vendorid
      cache_line_size   interrupt_pin   subclass_code
      deviceid             peripheral   subsys_id
      epc               progif_code subsys_vendor_id

The driver populates these entries with default values when the device
is bound to the driver. The pci-epf-test driver populates vendorid with
0xffff and interrupt\_pin with 0x0001

::

    # cat dev/epf/pci_epf_test.0/vendorid
      0xffff
    # cat dev/epf/pci_epf_test.0/interrupt_pin
      0x0001

| 

.. rubric:: configuring pci-epf-test device
   :name: configuring-pci-epf-test-device-1

The user can configure the pci-epf-test device using the configfs. In
order to change the vendorid and the number of MSI interrupts used by
the function device, the following command can be used.

Configure Texas Instruments as the vendor.

::

    # echo 0x104c > dev/epf/pci_epf_test.0/vendorid

If the endpoint is a DRA74x or AM572x device:

::

    # echo 0xb500 > dev/epf/pci_epf_test.0/deviceid

If the endpoint is a DRA72x or AM572x device:

::

    # echo 0xb501 > dev/epf/pci_epf_test.0/deviceid

Then finally:

::

    # echo 16 >  dev/epf/pci_epf_test.0/msi_interrupts

| 

.. rubric:: Binding pci-epf-test device to a EP controller
   :name: binding-pci-epf-test-device-to-a-ep-controller-1

In order for the endpoint function device to be useful, it has to be
bound to a PCI endpoint controller driver. Use the configfs to bind the
function device to one of the controller driver present in the system.

::

    # echo "51000000.pcie_ep" > dev/epc

Once the above step is completed, the PCI endpoint is ready to establish
a link with the host.

| 

.. rubric:: *66AK2G Limitation*
   :name: ak2g-limitation

K2G outbound transfers has a limitation that the target address should
be aligned to a minimum of 1MB address. This restriction is because of
PCIE\_OB\_OFFSET\_INDEXn where BITS 1 to 19 is reserved. (Please note
1MB is minimum alignment and it can be changed to 1MB/2MB/4MB/8MB by
specifying it in PCIE\_OB\_SIZE register).

Outbound transfers are used by PCI endpoint to access RC's memory and
for raising MSI interrupts. So with 1MB restriction both RC memory and
MSI interrupts will be impacted since standard linux API's like
dma\_alloc\_coherent, get\_free\_pages etc.. doesn't give 1MB aligned
memory. While custom driver can be created to get 1MB aligned memory for
accessing RC's memory, MSI memory is allocated by RC controller driver
and there is no way to tell it to give 1MB aligned address.

These restrictions are not specified in PCI standard and is bound to
cause issues for 66AK2G users.

.. rubric:: **HOST Device**
   :name: host-device

The PCI EP device must be powered-on and configured before the PCI HOST
device. This restriction is because the PCI HOST doesn't have hot plug
support.

.. rubric:: *Linux Driver Configuration*
   :name: linux-driver-configuration-1

The following config options has to be enabled in order to use the
"Endpoint Test" PCI device.

::

    CONFIG_PCI=y
    CONFIG_PCI_ENDPOINT_TEST=y
    CONFIG_PCI_DRA7XX_HOST=y

.. rubric:: *lspci output*
   :name: lspci-output

::

    00:00.0 PCI bridge: Texas Instruments Device 8888 (rev 01)
    01:00.0 Unassigned class [ff00]: Texas Instruments Device b500

.. rubric:: *Using the Endpoint Test function device*
   :name: using-the-endpoint-test-function-device

pci\_endpoint\_test driver creates the Endpoint Test function device
(/dev/pci-endpoint-test.0) which will be used by the following pcitest
utility. pci\_endpoint\_test can either be built-in to the kernel or
built as a module. For testing legacy interrupt, MSI interrupt has to
disabled in the host.

In order to not enable MSI (for testing legacy interrupt in DRA7)

::

    insmod pci_endpoint_test.ko no_msi=1

Please note MSI interrupt by default is not enabled for K2G.

pcitest.sh added in tools/pci/ can be used to run all the default PCI
endpoint tests. Before pcitest.sh can be used pcitest.c should be
compiled using

::

    cd <kernel-dir>
    make headers_install ARCH=arm
    arm-linux-gnueabihf-gcc -Iusr/include tools/pci/pcitest.c -o pcitest
    cp pcitest  <rootfs>/usr/sbin/
    cp tools/pci/pcitest.sh <rootfs>

.. rubric:: pcitest.sh output
   :name: pcitest.sh-output

::

    root@dra7xx-evm:~# ./pcitest.sh
    BAR tests

::

    BAR0:           OKAY
    BAR1:           OKAY
    BAR2:           OKAY
    BAR3:           OKAY
    BAR4:           NOT OKAY
    BAR5:           NOT OKAY

    Interrupt tests

    LEGACY IRQ:     NOT OKAY
    MSI1:           OKAY
    MSI2:           OKAY
    MSI3:           OKAY
    MSI4:           OKAY
    MSI5:           OKAY
    MSI6:           OKAY
    MSI7:           OKAY
    MSI8:           OKAY
    MSI9:           OKAY
    MSI10:          OKAY
    MSI11:          OKAY                                                                                                  
    MSI12:          OKAY                                                                                                  
    MSI13:          OKAY                                                                                                  
    MSI14:          OKAY                                                                                                  
    MSI15:          OKAY                                                                                                  
    MSI16:          OKAY
    MSI17:          NOT OKAY
    MSI18:          NOT OKAY
    MSI19:          NOT OKAY
    MSI20:          NOT OKAY
    MSI21:          NOT OKAY
    MSI22:          NOT OKAY
    MSI23:          NOT OKAY
    MSI24:          NOT OKAY
    MSI25:          NOT OKAY
    MSI26:          NOT OKAY
    MSI27:          NOT OKAY
    MSI28:          NOT OKAY
    MSI29:          NOT OKAY
    MSI30:          NOT OKAY
    MSI31:          NOT OKAY
    MSI32:          NOT OKAY

    Read Tests

    READ (      1 bytes):           OKAY
    READ (   1024 bytes):           OKAY
    READ (   1025 bytes):           OKAY
    READ (1024000 bytes):           OKAY
    READ (1024001 bytes):           OKAY

    Write Tests

    WRITE (      1 bytes):          OKAY
    WRITE (   1024 bytes):          OKAY
    WRITE (   1025 bytes):          OKAY
    WRITE (1024000 bytes):          OKAY
    WRITE (1024001 bytes):          OKAY

    Copy Tests

    COPY (      1 bytes):           OKAY
    COPY (   1024 bytes):           OKAY
    COPY (   1025 bytes):           OKAY
    COPY (1024000 bytes):           OKAY
    COPY (1024001 bytes):           OKAY

.. rubric:: **Files**
   :name: files

S.No
Location
Description
1
drivers/pci/endpoint/pci-epc-core.c
drivers/pci/endpoint/pci-ep-cfs.c

drivers/pci/endpoint/pci-epc-mem.c

drivers/pci/endpoint/pci-epf-core.c

PCI Endpoint Framework
2
drivers/pci/endpoint/functions/pci-epf-test.c
PCI Endpoint Function Driver
3
drivers/misc/pci\_endpoint\_test.c
PCI Driver
4
tools/pci/pcitest.c
tools/pci/pcitest.sh

PCI Userspace Tools
5
***4.4 Kernel***
drivers/pci/controller/pci-dra7xx.c

drivers/pci/controller/pcie-designware.c

drivers/pci/controller/pcie-designware-ep.c

drivers/pci/controller/pcie-designware-host.c

***4.9 Kernel***

drivers/pci/dwc/pci-dra7xx.c

drivers/pci/dwc/pcie-designware.c

drivers/pci/dwc/pcie-designware-ep.c

drivers/pci/dwc/pcie-designware-host.c

PCI Controller Driver


