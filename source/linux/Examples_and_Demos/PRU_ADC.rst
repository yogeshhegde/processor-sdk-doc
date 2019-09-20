PRU-ADC Demo
============

Introduction
------------
This demo shows flexible interface for Simultaneous, Coherent DAQ Using Multiple ADCs via PRU-ICSS. More details can be found at http://www.ti.com/tool/TIDA-01555


Hardware Needed
-----------------
Please refer to the `TI Design <http://www.ti.com/tool/TIDA-01555>`__ to set up the hardware needed to run this demo.

- `Beaglebone Black <http://beagleboard.org/Products/BeagleBone%20Black>`__
- TIDA-01555 adapter card
- TIDA-01555 ADC board
- Desktop power supply to provide 5.5 volts to the ADC board
- Desktop signal generator to produce a 45-55Hz sine wave as an input


Steps to Run the Demo
----------------------
Below are the steps to run the demo with Processor SDK Linux RT build for AM335x.


First, use /boot/am335x-boneblack-pru-adc.dtb as the default dtb:

.. code-block:: console

    cd /boot
    cp am335x-boneblack.dtb am335x-boneblack.dtb.orig
    cp am335x-boneblack-pru-adc.dtb am335x-boneblack.dtb


Then, link am335x-pru*_fw to the PRU-ADC firmware binaries:

.. code-block:: console

    cd /lib/firmware
    ln -sf /lib/firmware/pru/PRU_ADS8688_Controller.out am335x-pru0-fw
    ln -sf /lib/firmware/pru/PRU_ADS8688_Interface.out am335x-pru1-fw

After that, reboot the EVM, and then execute the ARM binary:

.. code-block:: console

   run-pru-adc.sh
