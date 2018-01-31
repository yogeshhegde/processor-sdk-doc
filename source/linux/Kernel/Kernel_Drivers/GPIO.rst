.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_GPIO_Driver_Overview

.. please note that there is no GPIO user guide from LCPD
.. rubric:: GPIO Driver Overview
   :name: gpio-driver-overview

The GPIO Driver enables the GPIO controllers available on the device.
The driver configures the GPIO hardware and interfaces and makes them
available to the sysfs interface for user space interaction or other
device drivers that need to access pins. For example, a MMC/SD driver
may need to read a GPIO as in input to determine if a card is present.
The H/W GPIO controllers available will vary by SoC and system
configuration.

.. rubric:: Overview
   :name: overview

The GPIO controllers allow interaction with GPIO pins for input/output
and interrupt generation.

.. Image:: ../images/GPIO_driver_diagram.png

.. rubric:: User Layer
   :name: user-layer

The GPIO driver can be used via the sysfs interface in user space or by
other drivers that may need to access pins as either input/outputs or
interrupts. More information about this driver and GPIO usage in Linux
can be found in the kernel documentation:

-  `GPIO Interface
   Documentation <http://git.ti.com/ti-linux-kernel/ti-linux-kernel/blobs/linux-3.14.y/Documentation/gpio/gpio.txt>`__
-  `GPIO Driver
   Documentation <http://git.ti.com/ti-linux-kernel/ti-linux-kernel/blobs/linux-3.14.y/Documentation/gpio/driver.txt>`__

.. rubric:: sysfs
   :name: sysfs

The sysfs interface is for GPIO is located in the kernel at
/sys/class/gpio. More information about this interface can also be found
in the kernel sources:

-  `GPIO sysfs
   Documentation <http://git.ti.com/ti-linux-kernel/ti-linux-kernel/blobs/linux-3.14.y/Documentation/gpio/sysfs.txt>`__

For controlling LEDs and Buttons, the kernel has standard drivers,
"leds-gpio" and "gpio\_keys", respectively, that should be used instead
of GPIO directly.

.. rubric:: Consuming Drivers
   :name: consuming-drivers

The GPIO Driver can also be easily leveraged by other drivers to
"consume" a GPIO.

-  `GPIO Consumer
   Documentation <http://git.ti.com/ti-linux-kernel/ti-linux-kernel/blobs/linux-3.14.y/Documentation/gpio/consumer.txt>`__

For an example of a driver using a GPIO pin, examine this entry in a dts
file for how the MMC/SD interface could use a GPIO as a card detect pin
`here <http://git.ti.com/ti-linux-kernel/ti-linux-kernel/blobs/linux-3.14.y/arch/arm/boot/dts/am335x-bone-common.dtsi#line293>`__.

| 

.. rubric:: Features
   :name: features

-  Access GPIO from user space as input or output
-  Leverage GPIO from another "consumer" driver

`Go Back to the Processor SDK Linux GPIO
Interface </index.php/Processor_SDK_Linux_GPIO>`__

.. rubric:: Power Management
   :name: power-management

| GPIO pins to be used to wake the system from low-power sleep states
  must be configured as a wake source in the device tree. Verify
  low-power wake capability in the device Technical Reference Manual.
  Some devices maps specific wake capabilities to each GPIO bank.

| To configure a GPIO pin as a wake up source, setup a gpio-key instance
  in the device tree. This will associate a GPIO pin with wake up
  capability and an interrupt.

| For example, look at the ``gpio_keys: volume_keys@0`` node in the
  device tree ``LINUX/arch/arm/boot/dts/am335x-evm.dts`` as a reference.
  GPIO0\_31 is configured as a wake source below:

`` @am33xx_pinmux { ``

::

     pinctrl-names = "default";
     pinctrl-0 = <&test_keys>;
     ...
     test_keys: test_keys {
       0x74 (PIN_INPUT_PULLDOWN | MUX_MODE7);  /* gpmc_wpn.gpio0_31 */
     };
     ...
     keys: test_keys@0 {
       compatible = "gpio-keys";
       #address-cells = <1>;
       #size-cells = <0>;
       autorepeat;
       test@0 {
         label = "J4-pin21";
         linux,code = <155>;
         gpios = <&gpio0 31 GPIO_ACTIVE_LOW>;
         gpio-key,wakeup;
       };
     };
     ...

};

| 

