.. include:: /replacevars.rst.inc

Voltage & Thermal Management (VTM)
----------------------------------

Introduction
^^^^^^^^^^^^

.. rubric:: VTM Driver Overview

The Voltage and Thermal Management (VTM) system provides the control,
status and interrupt generation for the various independent temperature
sensors located at different hotspots on the SoC. This allows the kernel
to take actions based on thermal events configured via the kernel's
device tree.

Driver Features
^^^^^^^^^^^^^^^

.. rubric:: Sysfs Monitoring

One of the most basic roles the VTM system can give the kernel is
temperature readings (in milliCelcius) in the sysfs filesystem.

.. code-block:: bash

   cat /sys/class/thermal/thermal_zone*/temp

Running this command on your SoC will print each temperature in
milliCelcius for that region on the SoC.

.. rubric:: Preset Thresholds & Triggers

We can also program up to 3 threshold temperatures, 2 for greater than
thresholds and 1 for a less than threshold, to allow the VTM to alert
the kernel to take action. For example when the 1\ :sup:`st` threshold is
exceeded the kernel can be alerted to begin reducing the voltage and
clocks speed of CPUs, allowing the SoC's overall temperature to
stabilize.  If the SoC temperature continues to increase we can then use
the 2\ :sup:`nd` threshold to take more aggressive action.  For example
we could issue a poweroff command to turn the device off completely once
the 2\ :sup:`nd` threshold is exceeded.

Threshold temperatures can be set in the kernel with the values we
define inside the device tree. For example to set a 'critical'
temperature, where the kernel will poweroff the SoC, we can add a node
like this:

.. code-block:: text

  example_thermal: ex-thermal {
        polling-delay-passive = <250>;  /* milliSeconds */
        polling-delay = <500>;          /* milliSeconds */
        thermal-sensors = <&wkup_vtm0 0>;

        trips {
                example_crit: ex-crit {
                        temperature = <125000>; /* milliCelsius */
                        hysteresis = <2000>;    /* milliCelsius */
                        type = "critical";
                };
        };
  };

This example node will instruct the kernel to periodically poll this
temperature sensor and to shutdown the SoC once it has exceeded 125
degrees Celsius.

Finding More Information
^^^^^^^^^^^^^^^^^^^^^^^^

More information can be found for this VTM device inside the Technical
Reference Manual for your device or the `device tree binding
documentation`_ in the kernel's source.

.. _`device tree binding documentation`: https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/tree/Documentation/devicetree/bindings/thermal

