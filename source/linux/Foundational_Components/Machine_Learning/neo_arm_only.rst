Neo-AI Deep Learning Runtime
============================

Introduction
-------------
`Neo-AI-DLR <https://github.com/neo-ai/neo-ai-dlr>`__ is an open source common runtime 
for deep learning models and decision tree models compiled by TVM, AWS SageMaker Neo, 
or Treelite. Processor SDK Linux Automotive has integrated Neo-AI-DLR. DLR stands for Deep Learning 
Runtime. With this integration, the models compiled by AWS SageMaker Neo and TVM can run 
on Jacinto Arm core.


Examples
--------

Examples of running inference with Neo-AI-DLR are available in /usr/share/dlr
of the target filesystem:

::

  cd /usr/share/dlr/tests/python/integration/
  python3 load_and_run_tvm_model.py

