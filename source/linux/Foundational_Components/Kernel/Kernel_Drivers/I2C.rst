.. http://processors.wiki.ti.com/index.php/Linux_Core_I2C_User%27s_Guide

I2C
---------------------------------

**Introduction**

The device contains high-speed (HS) inter-integrated circuit (I2C)
controllers (I2Ci modules, where i = 1, 2, 3 ...), each of which
provides an interface between a local host (LH), such as a digital
signal processor (DSP), and any I2C-bus-compatible device that connects
through the I2C serial bus. External components attached to the I2C bus
can serially transmit and receive up to 8 bits of data to and from the
LH device through the 2-wire I2C interface.

Each HS I2C controller can be configured to act like a slave or master
I2C-compatible device. I2C controllers can work at different frequencies
such as 100 KHz, 400 KHz and 3.4 MHz.

For more info, refer to the I2C controller chapter in the respective SOC
TRM.

**Setting up**

Omap I2C is enabled by default in omap2plus\_defconfig.

**Testing**

::

     Test1:
       Check for the following in the boot log
       omap_i2c reg.i2c: bus0 rev0.12 at X KHz

::

     Test2:
       Use the following utilities to check the i2c functionality.
       i2cdump -f -y bus slaveaddr b
          This will dump the register content of the slave at respective bus.
       i2cset -f -y bus slaveaddr register value b
          This will write a 'value' to the 'register' of the device with address 'slaveaddr'.
       i2cget -f -y bus slaveaddr register b
          This will read from the 'register' of the device with address 'slaveaddr'.
       Above testing helps if the slave address clocks are enabled and you can use the
       above tools to quickly get/set the value to just sanity check the i2c functionality.

::

     Test3:
         Check for the devices connected to the I2C.
         Run tests applicable for those devices to see if I2c read/write works fine.


