********************
Machine Learning
********************
Sitara Machine Learning toolkit brings machine learning to the edge by enabling machine learning inference on all Sitara devices (Arm only, Arm + specialized hardware accelerators). It is provided as part of TI's Processor SDK Linux, free to download and use. Sitara machine learning today consists of TI Deep Learning (TIDL), Arm NN, TensorFlow Lite, and RNN library.

.. figure:: ../images/Sitara_machine_learning_stack_diagram.png
    :width: 1120px
    :align: center
    :height: 576px

    Sitara Machine Learnining Offering

.. rubric:: `TI Deep Learning (TIDL) <Foundational_Components/Machine_Learning/tidl.html>`__

* Accelerates deep learning inference on C66x DSP cores and/or on Embedded Vision Engine (EVE) subsystems.
* Available on AM57x device only.
* Supports CNN at the moment, and imports Caffe, ONNX, and Tensorflow models.

.. rubric:: `Arm NN <Foundational_Components/Machine_Learning/armnn.html>`__

* Open source inference engine available from Arm.
* Runs on all Cortex-A ARM cores (AM3x, AM4x, AM5x, AM6x Sitara devices).
* Imports Caffe, ONNX, TensorFlow, and TensorFlow Lite models.

.. rubric:: `TensorFlow Lite <Foundational_Components/Machine_Learning/tflite.html>`__

* Open source deep learning runtime for on-device inference.
* Runs on all Cortex-A ARM cores (AM3x, AM4x, AM5x, AM6x Sitara devices).
* Imports Tensorflow Lite models.

.. rubric:: `RNN Library <Examples_and_Demos_Application_Demos.html#deploy-and-integration>`__

* Provides Long Short-Term Memory (LSTM) and fully connected layers in a standalone library to allow for rapid prototyping of inference applications that require Recurrent Neural Networks.
* Runs on all Cortex-A ARM cores (AM3x, AM4x, AM5x, AM6x Sitara devices).
* Integrated into TI's Processor SDK Linux in an OOB demo for `Predictive Maintenance <Examples_and_Demos_Application_Demos.html#predictive-maintenance-demo>`__.

.. toctree::
   :hidden:

   Foundational_Components/Machine_Learning/tidl
   Foundational_Components/Machine_Learning/armnn
   Foundational_Components/Machine_Learning/tflite
