############
Smart Reflex
############

.. rubric:: Overview

DRA7 platforms use Class 0 SmartReflex. It is a very simple class of
AVS. The SR compensated voltages for different OPPs of various Voltage
domains are burnt in the EFUSE registers. So whenever a new OPP is set
the SR compensate voltage value for that particular OPP is read from the
EFUSE registers and set.

On entering an OPP, the voltage value to be selected is no longer the
traditional nominal voltage, but the voltage meant from the efuse offset
encoded in millivolts. Each device will have it's own unique voltage for
given OPP. Therefore, it is not possible to encode a range of voltage
representing an OPP voltage.

DRA processors may be powered using various PMICs - I2C based ones such
as TPS659039 or SPI / GPIO controlled ones as well.


Cpufreq/devfreq drivers which control voltage and frequency pairs traditionally
used:

.. code-block:: text

   cpufreq/devfreq --> PMIC regulator
                   \-> clock framework

This opens up a few issues:

- The PMIC regulator is designed for platforms that may not use SmartReflex
  based SoCs, encoding the efuse offsets into every possible PMIC regulator
  driver is practically in-efficient.

- Voltage values are not known a-priori to be encoded into DTB as they
  device specific.

To simplify this, we introduce:

.. code-block:: text

   cpufreq/devfreq --> SmartReflex Class 0 regulator --> PMIC regulator
                   \-> clock framework

Class 0 Regulator has information of translating the "nominal voltage" i voltage
value stored in efuse offset. The following is an example encoding:

.. code-block:: text

   uVolts      mVolt   --> stored as 16 bit hex value of mV
   975000      975     --> 0x03CF
   1075000     1075    --> 0x0433
   1200000     1200    --> 0x04B0

[1] http://www.ti.com/lit/ds/sprt659/sprt659.pdf
[2] http://www.ti.com/lit/wp/swpy015a/swpy015a.pdf

Source Location :file:`drivers/cpufreq/ti-cpufreq.c`
