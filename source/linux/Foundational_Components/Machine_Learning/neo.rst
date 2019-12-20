SageMaker Neo Runtime
=======================

Introduction
-------------
Processor SDK Linux has integrated open source SageMaker Neo runtime, or 
`Neo-AI-DLR <https://github.com/neo-ai/neo-ai-dlr>`__, for deep learning 
inference at the edge. Currently, NEO-AI-DLR runs on ARM for Sitara devices 
(AM3/AM4/AM5/AM6), with subgraph offload using TIDL supported compute offload 
on AM5729 and AM5749. In this release, only TensorFlow models can be offloaded, 
and all operators in the network need to be supported by TIDL to utilize the offload.

Examples
--------

Examples of running inference with Neo runtime are available in /usr/share/dlr
of the target filesystem:

- demos folder: contains examples of Neo runtime on top of TIDL, which can only
  run on AM5729/49 devices. To run the examples, a neural network model must be
  compiled to generate runtime artifacts according to instructions in 
  :ref:`Compiling Network Models`. Once a model is compiled, copy the generated 
  artifacts to this folder and run one of the examples, e.g:

:: 

  ./do_tidl4.sh  <artifacts folder>

- tests folder: contains examples of Neo runtime for ARM cores, which can run on
  any Sitara device. Go to folder python/integration and run the example (http_proxy 
  needs to be set properly):

::
   
  python3 load_and_run_tvm_model.py


.. _Compiling Network Models:

Compiling Network Models to Run with DLR
----------------------------------------

SageMaker Neo compiler can compile neural network models to run with DLR on Sitara devices. 
Neo compiler source code supporting Sitara devices is hosted at https://github.com/TexasInstruments/tvm 
and will be periodically upstreamed to https://github.com/neo-ai/tvm. 

- Build Neo Compiler from source

:: 

    git clone --recursive https://github.com/TexasInstruments/tvm.git --branch dev
    cd tvm/
    mkdir build && cd build
    cp ../cmake/config.cmake .
    cmake ..
    make –j8

- Install Python Package

Follow instructions at https://docs.tvm.ai/install/from_source.html#python-package-installation for installation. 

- Compile Neural Network Models

Currently Neo compiler with Sitara support can compile any models supported by Neo, 
but only TensorFlow models can be compiled to run on TIDL for acceleration if the model
can be supported by TIDL. Follow instructions at https://github.com/TexasInstruments/tvm/tree/dev/apps/tidl_deploy to 
compile neural network models. A simple example generating the artifacts needed 
to run the demo above is shown below:

::

  python3 NeoTvmCodeGen.py mobileNet1

Benchmarking
------------

Performance with and without TIDL offload is shown below for TensorFlow MobileNet v1 and v2. The performance depends 
significantly on batch size (if batch size is 1, only one EVE is operating and performance would be very poor).

==========    ======================    =====================    ======================    =====================
Batch Size    TIDL MobileNetV1 (fps)    ARM MobileNetV1 (fps)    TIDL MobileNetV2 (fps)    ARM MobileNetV2 (fps)
==========    ======================    =====================    ======================    =====================
   4                 30.1260                  2.2018                    30.5178                   3.6843
   16                34.8465                  2.2210                    36.0127                   3.6775
   32                35.5279                                            37.5482
   64                36.5489                                            38.5027
==========    ======================    =====================    ======================    =====================

.. note::

   - There is no TVM auto-tuning for ARM (using default scheduling) and it is single A15 core execution.

Rebuilding DLR from Source
------------------------------

DLR for Sitara devices is included in Proc-SDK Linux target file system. Source 
code is hosted at https://github.com/TexasInstruments/neo-ai-dlr and will be periodically 
upstreamed to https://github.com/neo-ai/neo-ai-dlr. Users may rebuild the latest 
source code before official Proc-SDK release, following steps below:

- Clone git repo on x86 host to target NFS (git cloning may not work on EVM):

::

    git clone --recursive https://github.com/TexasInstruments/neo-ai-dlr.git --branch dev

- Build and Install DLR on AM57x9 EVM:

::

    cd neo-ai-dlr
    mkdir build && cd build
    cmake ..
    make –j2
    make demo democv
    cd ../python
    python3 setup.py install --user
