.. http://processors.wiki.ti.com/index.php/Linux_Core_PWM_User%27s_Guide
.. rubric:: **Introduction**
   :name: introduction-linux-core-pwm-ug

| Linux has support for Enhanced Pulse Width Modulator (ePWM) and
  Auxiliary Pulse Width Modulator (APWM) modules. APWM is Enhanced
  Capture (eCAP) module configured in PWM mode. These devices are part
  of The Pulse-Width Modulation Subsystem (PWMSS)

.. rubric:: **PWMSS software architecture**
   :name: pwmss-software-architecture

.. Image:: ../images/AM335X_PWM-SS_arch.JPG

.. rubric:: Driver Configuration
   :name: driver-configuration-pwm

.. rubric:: Procedure to build eHRPWM driver
   :name: procedure-to-build-ehrpwm-driver

::

             Device Drivers --->
                     <*> Pulse Width Modulation(PWM) Support --->
                        <*> eHRPWM PWM support   

.. rubric:: Procedure to build eCAP driver
   :name: procedure-to-build-ecap-driver

::

             Device Drivers --->
                     <*> Pulse Width Modulation(PWM) Support --->
                        <*> eCAP PWM support   

| 

.. rubric:: **Driver Usage**
   :name: driver-usage-pwm

.. rubric:: **eCAP**
   :name: ecap

The current release of the driver supports only PWM mode. eCAP can be
controlled from the user space through SYSFS interface. SYSFS interface
for eCAP is available at

::

    target$ cat /sys/class/pwm/pwmchipN

Where,

::

    ‘N’ is the eCAP instance.

| **Various SYSFS Attributes**

| 2 types of SYSFS attributes are available

#. Request and Control attributes
#. Configuration attributes

.. raw:: html

   <div
   style="padding-right: 5px; padding-left: 5px; background: rgb(238,238,238); padding-bottom: 5px; color: rgb(21,27,84); padding-top: 5px">

**Note**

-  Below examples uses eCAP instance 0 (i = 0).

.. raw:: html

   </div>

**Type 1 attributes**

-  ***export*** Attribute.

Ask the kernel to export a PWM channel. Writing 0 to the export
attribute Acquires the channel and writing 0 to the unexport attribute
Frees/Releases the channel. Before performing any operations, device has
to be requested first.

| 
| **Example**

-  Request the Device:

::

    target$ echo 0 > /sys/class/pwm/pwmchip0/export

-  free the device:

::

    target$ echo 0 > /sys/class/pwm/pwmchip0/unexport

-  ***run*** Attribute

Enable/disable the PWM channel

| **Example**

-  Enable the PWM

::

    target$ echo 1 > /sys/class/pwm/pwmchip0/pwm0/enable

-  Disable the PWM

::

    target$ echo 0 > /sys/class/pwm/pwmchip0/pwm0/enable

.. raw:: html

   <div style="padding:5px; background: #eeeeee; color: #E8A317">

| **CAUTION**
| Before enabling the module, the module needs to be configured using
  below configuration attributes. Else proper operation is not assured.

.. raw:: html

   </div>

| 

**Type 2 attributes**

| i.\ **Setting the Period**
| Following attributes set the period of the PWM waveform.

-  ***period*** Attribute

Enter the period in nano seconds value.

| **Example**
| if the period is 1 sec , enter

::

    target$ echo 1000000000 > /sys /class/pwm/pwmchip0/pwm0/period

| ii.\ **Setting the Duty**
| Following attributes set the duty of the PWM waveform.

-  ***duty\_cycle*** Attribute

Enter the Duty cycle value in nanoseconds.

::

    target$ echo val > /sys/class/pwm/pwmchip0/pwm0/duty_cycle

| iii.\ **Setting the Polarity**

-  ***Polarity*** Attribute.

Setup Signal Polarity

| **Example**
| To set the polarity to Active High, Enter

::

    target$ echo 1 > /sys /class/pwm/pwmchip0/pwm0/polarity

| 

| **Example**
| To set the polarity to Active Low, Enter

::

    target$ echo 0 > /sys /class/pwm/pwmchip0/pwm0/polarity

| 

.. rubric:: Controlling backlight
   :name: controlling-backlight

| Following are the 2 procedures to vary brightness of the LCD screen.

| i. Setting duty percentage of pwm wave from eCAP sysfs files

::

    target$ echo val > /sys/class/pwm/pwmchip0/pwm0/duty_cycle

| 'val' can range from 0 to 100.
| ii. Setting brightness from backlight sysfs files

::

    target$ echo val > /sys/class/backlight/backlight.8/brightness

'val' can range from 0 to 8.

.. raw:: html

   </div>

