How to enable Microtips LVDS Panel on AM62 SK EVM
=================================================

The following panel is currently supported with the AM625 SK EVM revision E3 board: 
**Microtips Technology USA (13-101HIEB0HF0-S) 10.1"  WUXGA (1920x1200) TFT LCD panel**

**Steps to enable OLDI Panel DT overlay:**

#. Follow the `How to enable DT overlays in linux
   <How_to_enable_DT_overlays_in_linux.html>`__ guide for steps on building
   and adding the overlay in your SD card. Make sure that the overlay file 
   ``k3-am625-sk-oldi-panel.dtbo`` has been appended in the ``name_overlays`` 
   variable as suggested in the same page.

**Steps to stabilize OLDI signal output from AM625 SoC:**

During internal tests, certain LVDS panels showed distorted output or had no output on the screen. 
The issue was related to the bandgap register and the below steps show how to resolve the issue:

#. After the kernel has booted up, from the linux prompt, run the following command

    .. code-block:: bash

        root@am62xx-evm:~# devmem2 0x00108700 w      
        /dev/mem opened.
        Memory mapped at address 0xffffa29a9000.
        Read at address  0x00108700 (0xffffa29a9700): 0x00000100

    - If the register value is indeed 0x00000100, the bandgap circuit enable bit (BIT[8]) has not been cleared.
    - Clear the bit using the following command.

    .. code-block:: bash

        root@am62xx-evm:~# devmem2 0x00108700 w 0x0
        /dev/mem opened.
        Memory mapped at address 0xffffaa28e000.
        Read at address  0x00108700 (0xffffaa28e700): 0x00000100
        Write at address 0x00108700 (0xffffaa28e700): 0x00000000, readback 0x00000000

    - The above step is temporary and has to be executed everytime the board is booted up.

#. Alternatively, the linux kernel can be updated to CICD tag: ``tag: cicd.2022.12.10.19.06.00``, and re-built. 
   This tag contains the fix patch (``drm/tidss: Add bandgap power control for OLDI LVDS buffers``) that enables the 
   bandgap circuit as and when required.

**Steps to enable Touch on the Microtips Panel on AM625 SK EVM:**

**Note**: The following steps are only applicable on AM625 SK EVM revision E3 board

#. Power off the LVDS board by disconnecting the 12V barrel jack (do not power off the SK EVM)
#. Run the following commands from the Linux prompt:

	.. code-block:: bash

		root@am62xx-evm:~# modprobe -r ili210x
		root@am62xx-evm:~# i2ctransfer -f -y 0 w3@0x3f 0x09 0x1 0x0e
		root@am62xx-evm:~# i2ctransfer -f -y 0 w6@0x3f 0x08 0x04 0x47 0x50 0x73 0x68
		root@am62xx-evm:~# i2ctransfer -f -y 0 w1@0x3f 0x72 r9
		
#. Power on the LVDS board
#. Run the following command:

	.. code-block:: bash

		root@am62xx-evm:~# modprobe ili210x

After re-initializing the module, the touch IC should now be registered as an input and touch should be functional.
