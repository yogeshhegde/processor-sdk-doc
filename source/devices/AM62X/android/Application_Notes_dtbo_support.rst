===========================
Device Tree Overlay Support
===========================

This application note contains steps to configure Device Tree Overlays (DTBO).
DTBOs can be enabled from U-Boot when extra peripherals are connected to the board.

DTBOs are **board specific**.

It's possible to change the ``dtbo_index`` from the U-Boot shell.
For example:

.. code-block:: console

   => env set dtbo_index 1
   => saveenv
   => reset

To enable multiple DTBOs, pass a space-separated index list.
For example:

.. code-block:: console

   => env set dtbo_index '1 2'


**- AM62x-SK EVM**

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
|    3      |   Microtips Technology USA 10.1"  WUXGA (1920x1200) OLDI panel       |
+-----------+----------------------------------------------------------------------+
|    4      |   Enable MAIN and MCU GPIO + CANUART wakeup source                   |
+-----------+----------------------------------------------------------------------+

.. warning::
    LVDS Display is supported only on E3 board revision.

**- AM62x-LP-SK EVM**

The following Device-Tree Overlays are supported:

+-----------+----------------------------------------------------------------------+
|dtbo_index |  description                                                         |
+-----------+----------------------------------------------------------------------+
|    5      |   Microtips Technology USA 10.1"  WUXGA (1920x1200) OLDI panel       |
+-----------+----------------------------------------------------------------------+

**- Beagle Play**

+-----------+------------------------------------------------------------------------+
|dtbo_index |  description                                                           |
+-----------+------------------------------------------------------------------------+
|    6      |   Digilent PCam 5C OV5640 Camera                                       |
+-----------+------------------------------------------------------------------------+
|    7      |   TEVI-OV5640C-S84-IR-RPI Camera                                       |
+-----------+------------------------------------------------------------------------+
|    8      |   Lincoln Technology Solutions LCD185-101CT WUXGA(1920x1200) OLDI panel|
+-----------+------------------------------------------------------------------------+
