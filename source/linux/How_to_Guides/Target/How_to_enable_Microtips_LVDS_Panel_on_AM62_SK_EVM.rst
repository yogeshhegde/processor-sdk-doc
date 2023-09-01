How to enable Microtips LVDS Panel on AM62 SK EVM
=================================================

The following panel is currently supported with the AM625 SK EVM revision E3 board:
**Microtips Technology USA (13-101HIEB0HF0-S) 10.1"  WUXGA (1920x1200) TFT LCD panel**

**Steps to enable OLDI Panel DT overlay:**

#. Follow the `How to enable DT overlays in linux
   <How_to_enable_DT_overlays_in_linux.html>`__ guide for steps on building
   and adding the overlay in your SD card. Make sure that the overlay file
   ``k3-am625-sk-microtips-mf101hie-panel.dtbo`` has been appended in the ``name_overlays``
   variable as suggested in the same page.

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
