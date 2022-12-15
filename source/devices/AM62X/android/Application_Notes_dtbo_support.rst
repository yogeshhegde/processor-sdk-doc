===========================
Device Tree Overlay Support
===========================



It's possible to change the ``dtbo_index`` from the U-Boot shell.
For example:

.. parsed-literal::

    env set dtbo_index 1
    saveenv
    reset

To enable multiple DTBOs, pass a space-separated index list. For
example,

.. parsed-literal::

    env set dtbo_index '1 2'


**- AM62X-SK EVM**

The following Device-Tree Overlays are supported:

+-----------+----------------------------------------------------------------------+
|dtbo_index |  description                                                         |
+-----------+----------------------------------------------------------------------+
|    0      |   HDMI audio output (bridge by shorting a (J24) header on the board.)|
+-----------+----------------------------------------------------------------------+
|    1      |   Digilent PCam 5C OV5640 Camera                                     | 
+-----------+----------------------------------------------------------------------+
|    2      |   TEVI-OV5640C-S84-IR-RPI Camera                                     |
+-----------+----------------------------------------------------------------------+

**- AM62X-LP-SK EVM**

No Device-Tree Overlays are supported for now.
