..
    This subsection provides details on the QT graphics frameworks

#####################
QT Graphics Framework
#####################

Qt is a powerful C++ toolkit for writing cross-platform graphics
applications, enabling a single code base to run predictably and perform
well on Windows and embedded platforms,

Please refer `<https://www.qt.io/>`_ for additional details on Qt.

The PSDK target file system includes the pre-built Qt libraries under
:file:`/usr/lib` and a rich set of QT demo applications under
:file:`/usr/share/qt5/examples`.

******
QT QPA
******

The QT5 within PSDK is prebuilt with Wayland enabled and therefore
wayland-egl is the default QPA. Hence all QT applications should be run
on top of Weston. To run QT application without Weston, the user can use
``-platform`` option to specify the desired QPA as ``linuxfb`` or ``eglfs``.

.. note::

   The ``linuxfb`` inteface is deprecated and requires switching the display
   into legacy fb mode.

For example:

.. code-block:: console

   target # /usr/share/qt5/examples/opengl/2dpainting/2dpainting -platform eglfs

