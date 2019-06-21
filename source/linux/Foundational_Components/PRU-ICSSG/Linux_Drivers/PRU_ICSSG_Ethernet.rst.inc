Introduction
^^^^^^^^^^^^

PRU_ICSSG Ethernet driver architecture is similar to PRU-ICSS Ethernet driver discussed at `PRU-ICSS Ethernet <Foundational_Components_PRU-ICSS_PRU_ICSSG.html#pru-icss-ethernet>`__

Driver is developed complying to Linux Driver model and implements netdev and NAPI APIs along with other basic driver functions. Driver supports multiple instances of ICSSG each of which has a pair of Programmable Real-Time Units (PRU), namely PRU0 and PRU1, and Auxillary Programmable Real-time Units (RTU), namely RTU_PRU0 and RTU_PRU1. Driver defines a slice consisting of a PRU and an associated RTU_PRU and is allocated for each Ethernet interface. So each ICSSG has two slices and supports two Ethernet interfaces. As part of probe() driver loads firmware on each of these cores and run the firmware.

One of the key difference in the driver implementation compared to PRU-ICSS driver is the use of UDMA driver interface and ring accelerator driver available on Keystone III SoC to send/receive frames between ARM Host processor and PRU_ICSSG. This allows for efficient moving of data and is more efficient than the shared memory transport used in PRU-ICSS.

Boards Supported
^^^^^^^^^^^^^^^^

.. rubric:: `AM65x evaluation module
   (EVM) <http://www.ti.com/tool/TMDX654GPEVM>`__

The AM65x Evaluation Module provides a platform to quickly start evaluation of Sitara™ Arm® Cortex®-A53 AM65x Processors (AM6548, AM6546, AM6528, AM6527, AM6526) and accelerate development for HMI, networking, patient monitoring, and other industrial applications. It is a development platform based on the quad core Cortex-A53, dual Cortex-R5F processor that is integrated with ample connectivity such as PCIe, USB 3.0/2.0, Gigabit Ethernet,  PRU_ICSSG Ethernet
etc.

.. Image:: ../images/Am65x_GP_EVM.jpg

.. rubric:: `AM65x industrial development kit
   (IDK) <http://www.ti.com/tool/TMDX654IDKEVM>`__

The AM65x Industrial Development Kit (IDK) is a development platform for evaluating the industrial communication and control capabilities of Sitara AM65x processors for applications in factory automation, drives, robotics, grid infrastructure, and more. AM65x processors include three PRU_ICSSG (Programmable Real-time Unit for Industrial Communications) sub-systems which can be used for gigabit industrial Ethernet protocols such as Profinet, EtherCAT, Ethernet/IP, and others.

.. Image:: ../images/Am65x_idk.jpg

Features supported
^^^^^^^^^^^^^^^^^^

- Two 100M/1G Ethernet ports on AM65x GP EVM (six ports on AM65x IDK) - 10M link speed is not supported
- Promiscuous mode
- RGMII mode with delay (configured in DTS)

What You Get
^^^^^^^^^^^^

With the PRU_ICSSG Ethernet support, you get two (or six on the AM65x IDK) additional 100 Mbps/1 Gbps Ethernet interfaces that show up just like
any other Ethernet interface in Linux.

|

how It Works
^^^^^^^^^^^^

Texas Instruments provides all of the necessary software and firmware in the Linux Processor SDK to enable the PRU_ICSSG Ethernet ports.

