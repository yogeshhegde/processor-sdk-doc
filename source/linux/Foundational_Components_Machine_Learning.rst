.. _foundational-components-machine-learning:

********************
Machine Learning
********************

.. ifconfig:: CONFIG_part_family in ('General_family', 'AM335X_family', 'AM437X_family')
 
   Sitara Machine Learning toolkit brings machine learning to the edge by enabling 
   machine learning inference on all Sitara devices (Arm only, Arm + specialized hardware 
   accelerators). It is provided as part of TI's Processor SDK Linux, free to download 
   and use. Sitara machine learning today consists of TI Deep Learning (TIDL), Neo-AI-DLR, 
   TVM runtime, TensorFlow Lite, Arm NN, and RNN library.
 
   .. figure:: ../images/Sitara_machine_learning_stack_diagram.png
       :width: 1120px
       :align: center
       :height: 576px
 
       Sitara Machine Learnining Offering
 
   .. ifconfig:: CONFIG_part_family in ('General_family')
 
           .. rubric:: `TI Deep Learning (TIDL) <Foundational_Components/Machine_Learning/tidl.html>`__
 
           * Accelerates deep learning inference on C66x DSP cores and/or on Embedded Vision Engine (EVE) subsystems.
           * Available on AM57x device only.
           * Supports CNN at the moment, and imports Caffe, ONNX, and Tensorflow models.
 
   .. rubric:: `Neo-AI Deep Learning Runtime (DLR) <Foundational_Components/Machine_Learning/neo.html>`__
 
   * Neo-AI-DLR is a new open source machine learning runtime for on-device inference.
   * Supports Keras, Tensorflow, TFLite, GluonCV, MXNet, Pytorch, ONNX, and XGBoost models optimized 
     automatically by `Amazon SageMaker Neo <https://aws.amazon.com/sagemaker/neo/>`__ 
     or `TVM compiler <https://github.com/apache/incubator-tvm/>`__.
   * Supports all Cortex-A ARM cores (AM3x, AM4x, AM5x, AM6x Sitara devices).
   * On AM5729 and AM5749 devices, uses TIDL to accelerate supported models automatically.
 
   .. rubric:: `TVM Runtime <Foundational_Components/Machine_Learning/tvm.html>`__
 
   * Open source deep learning runtime for on-device inference, supporting models compiled by 
     `TVM compiler <https://github.com/apache/incubator-tvm/>`__.
   * Available on all Cortex-A ARM cores (AM3x, AM4x, AM5x, AM6x Sitara devices).
 
   .. rubric:: `TensorFlow Lite <Foundational_Components/Machine_Learning/tflite.html>`__
 
   * Open source deep learning runtime for on-device inference.
   * Runs on all Cortex-A ARM cores (AM3x, AM4x, AM5x, AM6x Sitara devices).
   * Imports Tensorflow Lite models.
   * Uses TIDL import tool to create TIDL offloadable Tensorflow Lite models,
     which can be executed via Tensorflow Lite runtime with TIDL acceleration on AM5729 and AM5749 devices.
 
   .. rubric:: `Arm NN <Foundational_Components/Machine_Learning/armnn.html>`__
 
   * Open source inference engine available from Arm.
   * Runs on all Cortex-A ARM cores (AM3x, AM4x, AM5x, AM6x Sitara devices).
   * Imports Caffe, ONNX, TensorFlow, and TensorFlow Lite models.
 
   .. rubric:: `RNN Library <Examples_and_Demos_Application_Demos.html#deploy-and-integration>`__
 
   * Provides Long Short-Term Memory (LSTM) and fully connected layers in a standalone library to allow for rapid prototyping of inference applications that require Recurrent Neural Networks.
   * Runs on all Cortex-A ARM cores (AM3x, AM4x, AM5x, AM6x Sitara devices).
   * Integrated into TI's Processor SDK Linux in an OOB demo for `Predictive Maintenance <Examples_and_Demos_Application_Demos.html#predictive-maintenance-demo>`__.


.. ifconfig:: CONFIG_part_family in ('J7_family')

   Jacinto Machine Learning toolkit brings machine learning to the edge by enabling 
   machine learning inference on all Jacinto devices. It is provided as part of
   TI's Processor SDK Linux, free to download and use. Jacinto machine learning today consists
   of Neo-AI-DLR library.
   
.. ifconfig:: CONFIG_part_family in ('AM64X_family')

   The Machine Learning toolkit brings machine learning to the edge by enabling
   machine learning inference on Sitara devices. It is provided as part of
   TI's Processor SDK Linux, free to download and use. The Machine Learning
   toolkit consists of TensorFlow Lite library.

.. toctree::
   :maxdepth: 2

   Foundational_Components/Machine_Learning/tidl
   Foundational_Components/Machine_Learning/neo
   Foundational_Components/Machine_Learning/tvm
   Foundational_Components/Machine_Learning/tflite
   Foundational_Components/Machine_Learning/tflite_j7
   Foundational_Components/Machine_Learning/armnn

