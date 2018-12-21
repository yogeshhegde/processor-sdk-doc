******************************
Arm NN and Arm Compute Library
******************************

Introduction
=============
Arm NN and Arm Compute Library, as a set of machine learning software, tools and libraries, enable Machine Learning on Arm. 

For Sitara devices without accelerators like C66x or EVE (AM3/4/6), one can use Arm provided libraries created for supporting inference only tasks on Arm CPUs.
Arm NN and Arm Compute Library can also be used on AM57xx devices as well, as complementary approach to TIDL-API.

Arm Compute Library
===================

Arm Compute Library is a software library for computer vision and machine learning, optimized for NEON SIMD architecture (Mali GPU OpenCL is not applicable to TI devices).
Exact list of functions can be found at https://developer.arm.com/technologies/compute-library. Arm Compute Libraries and sample executables are included in PLSDK filesystem.
AM3/4/5/6 devices can utilize this library to unleash full potential of Arm CPUs.

Sample NN related executables (using Arm Compute Library only):

::

   /usr/bin/graph2tree
   /usr/bin/graph_alexnet
   /usr/bin/graph_googlenet
   /usr/bin/graph_inception_v3
   /usr/bin/graph_inception_v4
   /usr/bin/graph_lenet
   /usr/bin/graph_mobilenet
   /usr/bin/graph_mobilenet_qasymm8
   /usr/bin/graph_resnet50
   /usr/bin/graph_resnext50
   /usr/bin/graph_squeezenet
   /usr/bin/graph_squeezenet_v1_1
   /usr/bin/graph_vgg16
   /usr/bin/graph_vgg19


Arm NN
======

Arm NN is library built on top of Arm Compute Library leveraging its NEON optimized kernels. Importing of Caffe and Tensorflow inference models is significantly simplified.
Library and executables are part of AM3/4/5/6 target filesystem. More information can be found at: https://developer.arm.com/products/processors/machine-learning/arm-nn

Sample Arm NN executables using Caffe models:

::

   /usr/bin/CaffeAlexNet-Armnn
   /usr/bin/CaffeCifar10AcrossChannels-Armnn
   /usr/bin/CaffeInception_BN-Armnn
   /usr/bin/CaffeMnist-Armnn
   /usr/bin/CaffeResNet-Armnn
   /usr/bin/CaffeVGG-Armnn
   /usr/bin/CaffeYolo-Armnn

Sample executables using TF models:

::

   /usr/bin/ArmnnExamples
   /usr/bin/TfCifar10-Armnn
   /usr/bin/TfInceptionV3-Armnn
   /usr/bin/TfMnist-Armnn
   /usr/bin/TfMobileNet-Armnn
   /usr/bin/TfResNext-Armnn
  
Please note that these examples (Arm baseline code) use hardcoded paths, so source modification might be required (one can use Yocto based compilation - look for armnn recipe in meta-arago layer).

Arm NN MobileNet Demo
=====================

Upon boot, Matrix-GUI is started with multiple buttons that can start many demos. In PLSDK 5.2, under sub-menu "Machine Learning",
there are two Arm NN GUI buttons:

* Arm NN MobileNet Real Common Objects 
* Arm NN MobileNet Camera Input

These examples demonstrate Deep Learning Imagenet classification (1000 classes) with MobileNet model <http://download.tensorflow.org/models/mobilenet_v1_2018_02_22/mobilenet_v1_1.0_224.tgz> on Arm.
One example uses pre-recorded real-world video clip and the other uses live camera input. The pre-recorded video clip (320x320 resolution) and live camera input (default 640x480 resolution)
are scaled down and central-cropped in run-time (using OpenCV API) to 224x224. Result of this
processing is standard Imagenet classification output (1D vector with 1000 elements). 

Executable invoked from Matrix-GUI is in: /usr/bin/ArmnnExamples.

::

	root@am57xx-evm:/usr/bin# ArmnnExamples --help
	Executes a neural network model using the provided input tensor.
	Prints the resulting output tensor.

	Options:
	  --help                          Display usage information
	  -f [ --model-format ] arg       caffe-binary, caffe-text, onnx-binary,
                                          onnx-text, tflite-binary, tensorflow-binary
                                          or tensorflow-text. E.g.: -f
                                          tensorflow-binary
	  -m [ --model-path ] arg         Model Name w/ full path, e.g.of supported
                                          model types: .caffemodel, .prototxt, .tflite,
                                          .onnx. E.g.: -m /usr/share/arm/armnn/models/m
                                          obilenet_v1_1.0_224_frozen.pb
	  -c [ --compute ] arg            The preferred order of devices to run layers
                                          on by default. Possible choices: CpuAcc,
                                          CpuRef, GpuAcc. E.g.: -c CpuAcc
	  -i [ --input-name ] arg         Identifier of the input tensor in the
                                          network. E.g.: -i input
	  -s [ --input-tensor-shape ] arg The shape of the input tensor in the network
                                          as a flat array of integers separated by
                                          whitespace. This parameter is optional,
                                          depending on the network. E.g.: -s '1 224 224 3'
	  -d [ --input-tensor-data ] arg  Input test file name. It can be image/video
                                          clip file name or use 'camera_live_input' to
                                          select camera input. E.g.: -d
                                          /usr/share/arm/armnn/testvecs/camera_live_input
	  -o [ --output-name ] arg        Identifier of the output tensor in the
                                          network. E.g.: -o MobilenetV1/Predictions/Reshape_1
	  --number_frame arg (=1)         Number of frames to process. E.g.:
                                          --number_frame 100.

Here is an example of classification using live camera input - stop at any time with mouse right-click on output image window.
::
      ArmnnExamples -f tensorflow-binary -i input -s '1 224 224 3' -o MobilenetV1/Predictions/Reshape_1 -d /usr/share/arm/armnn/testvecs/camera_live_input -m /usr/share/arm/armnn/models/mobilenet_v1_1.0_224_frozen.pb -c CpuAcc --number_frame 100

Here is an example of classification using video clip - stop at any time with mouse right-click on output image window.
::
      ArmnnExamples -f tensorflow-binary -i input -s '1 224 224 3' -o MobilenetV1/Predictions/Reshape_1 -d /usr/share/arm/armnn/testvecs/test2.mp4 -m /usr/share/arm/armnn/models/mobilenet_v1_1.0_224_frozen.pb -c CpuAcc --number_frame 100

Here is an example of classification using JPG image - use <--number_frame> to select number of runs.
::
	  root@am57xx-evm:/usr/bin# ArmnnExamples -f tensorflow-binary -i input -s '1 224 224 3' -o MobilenetV1/Predictions/Reshape_1 -d /usr/share/arm/armnn/testvecs/baseball.jpg -m /usr/share/arm/armnn/models/mobilenet_v1_1.0_224_frozen.pb -c CpuAcc --number_frame 10
	  ArmNN v20180800

	  Predicted: 430:baseball
	  Performance (FPS): 3.69008
	  Predicted: 430:baseball
	  Performance (FPS): 4.06392
	  Predicted: 430:baseball
	  Performance (FPS): 4.0249
	  Predicted: 430:baseball
	  Performance (FPS): 4.06136
	  Predicted: 430:baseball
	  Performance (FPS): 4.04393
	  Predicted: 430:baseball
	  Performance (FPS): 4.05345
	  Predicted: 430:baseball
	  Performance (FPS): 4.07095
	  Predicted: 430:baseball
	  Performance (FPS): 4.06762
	  Predicted: 430:baseball
	  Performance (FPS): 4.04837
	  Predicted: 430:baseball
	  Performance (FPS): 4.07617
