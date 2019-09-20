.. http://processors.wiki.ti.com/index.php/Processor_SDK_Linux_UART_Driver_Overview

.. Please note that there is no UART driver from Linux Core user guide 

UART
---------------------------------

.. rubric:: UART Driver Overview
   :name: uart-driver-overview

The UART Driver enables the UART's available on the device. The driver
configures the UART hardware and interfaces with a number of standard
linux tools (ex. stty, minicom, etc.) to enable the configuration and
usage of the hardware. The H/W UARTs available will vary by SoC and
system configuration.

.. rubric:: Overview
   :name: overview-linux-uart

The UART driver can be used to send/receive raw ASCII characters from
the User Interface as shown by the below diagram.

.. Image:: ../../../../images/Uart_driver_diagram.png

.. rubric:: User Layer
   :name: user-layer

The UART driver leverages the TTY framework within Linux. This framework
uses typical file I/O operations to interact with the UART. This
interface allows userspace modules to easily be developed to read/write
the /dev/ttyxx to exchange data over the UART. Since this is a very
common Linux framework, there are many standard tools that can be used
to interact with it. These tools, like stty, minicom, picocom, and many
others, can easily be used to exercise a UART for data exchange.

.. rubric:: Features
   :name: features

-  Exposes UART to User Space via /dev/tty\*
-  Supports multiple baud rates and UART capabilities
-  Hardware Flow Control

