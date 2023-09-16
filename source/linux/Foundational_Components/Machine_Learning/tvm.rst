TVM Runtime
===========

Introduction
-------------
TVM is an open deep learning compiler stack for CPUs, GPUs, and specialized accelerators.
It aims to close the gap between the productivity-focused deep learning frameworks, and the
performance- or efficiency-oriented hardware backends. TVM provides the compilation of deep
learning models in Keras, MXNet, PyTorch, Tensorflow, CoreML, DarkNet into minimum deployable
modules on diverse hardware backends.

Processor SDK Linux has integrated `TVM runtime <https://docs.tvm.ai/dev/runtime.html>`
for deep learning inference at the edge. Currently, TVM runtime is available on ARM cores for all
Sitara devices (AM3/AM4/AM5/AM6).

To run deep learning inference on Sitara devices, a network model needs to be
compiled by TVM compiler.

Build and Install TVM Compiler
------------------------------

Follow instructions at https://docs.tvm.ai/install/from_source.html to build and
install TVM compiler from source. Please note that USE_LLVM needs to be set to ON
in config.cmake.

Running Inference on the Target
-------------------------------

- Start RPC on the target

::

  python3 -m tvm.exec.rpc_server --host 0.0.0.0 --port=9090

- Run model compilation on the host using :download:`this Python script <deploy_tfmodel_sitara.py>`.

::

  python3 deploy_tfmodel_sitara.py '<remote target ip address>', e.g. python3 deploy_tfmodel_sitara.py '10.1.1.1'

Please note that this script worked with commit id 76c239269935288e51fbce14f135d75ad9742b2a,
but may not work with latest code. One can modify the script accordingly or follow
`this example <https://docs.tvm.ai/tutorials/frontend/deploy_model_on_rasp.html#sphx-glr-tutorials-frontend-deploy-model-on-rasp-py>`__
in order to work with newer code.
