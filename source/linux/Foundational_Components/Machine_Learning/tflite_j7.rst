TensorFlow Lite
==============================
.. ifconfig:: CONFIG_part_family in ('J7_family')
Introduction
-------------

`TensorFlow Lite <https://www.tensorflow.org/lite>`__ is an open source library for deep learning models.
TensorFlow Lite runs on Jacinto Arm cores. 

Supported version
------------------

  - TensorFlow Lite 1.15

TensorFlow Lite example applications
-------------------------------------

TensoreFlow Lite example applications are installed on filesystem at /usr/share/tensorflow-lite/examples.
One TensorFlow Lite model (mobilenet_v1_1.0_224_quant.tflite) is also installed at the same place for demonstration.
To use other TensorFlow Lite models, such as `TensorFlow Lite Hosted Models <https://www.tensorflow.org/lite/guide/hosted_models>`__,
please download those models and then copy them to the target.

.. code-block:: bash

    root@am57xx-evm:/usr/share/tensorflow-lite/examples# ls -l
    total 8356
    -rwxr-xr-x 1 root root 2423336 Aug 28 08:27 benchmark_model
    -rw-r--r-- 1 root root  940650 Aug 28 07:56 grace_hopper.bmp
    -rwxr-xr-x 1 root root 2288600 Aug 28 08:27 label_image
    -rw-r--r-- 1 root root   10484 Aug 28 07:56 labels.txt
    -rwxr-xr-x 1 root root 2251048 Aug 28 08:27 minimal
    -rw-r--r-- 1 root root 4276352 Aug 28 07:56 mobilenet_v1_1.0_224_quant.tflite
    -rwxr-xr-x 1 root root    2152 Aug 28 07:56 tflite-benchmark.she

Running benchmark_model
^^^^^^^^^^^^^^^^^^^^^^^

The *benchmark_model* binary performs computation benchmarking for Tensorflow Lite models. Usage of *benchmark_model*:

::

    usage: ./benchmark_model
    Flags:
            --num_runs=50   int32   number of runs
            --run_delay=-1  float   delay between runs in seconds
            --num_threads=1 int32   number of threads
            --benchmark_name=       string  benchmark name
            --output_prefix=        string  benchmark output prefix
            --warmup_runs=1 int32   how many runs to initialize model
            --graph=        string  graph file name
            --input_layer=  string  input layer names
            --input_layer_shape=    string  input layer shape
            --use_nnapi=false       bool    use nnapi api

Example of running *benchmark_model* on target using the pre-installed mobilenet_v1_1.0_224_quant.tflite model:

::

    # cd /usr/share/tensorflow-lite/examples
    # ./benchmark_model --graph=mobilenet_v1_1.0_224_quant.tflite
    STARTING!
    Min num runs: [50]
    Min runs duration (seconds): [1]
    Max runs duration (seconds): [150]
    Inter-run delay (seconds): [-1]                                                 
    Num threads: [1]                                                                
    Benchmark name: []                                                              
    Output prefix: []                                                               
    Min warmup runs: [1]                                                            
    Min warmup runs duration (seconds): [0.5]                                       
    Graph: [mobilenet_v1_1.0_224_quant.tflite]                                      
    Input layers: []                                                                
    Input shapes: []                                                                
    Use nnapi : [0]                                                                 
    Use legacy nnapi : [0]                                                          
    Use gpu : [0]                                                                   
    Allow fp16 : [0]                                                                
    Require full delegation : [0]                                                   
    Enable op profiling: [0]                                                        
    Max profiling buffer entries: [1024]                                            
    Loaded model mobilenet_v1_1.0_224_quant.tflite                                  
    resolved reporter                                                               
    Initialized session in 126.941ms                                                
    Running benchmark for at least 1 iterations and at least 0.5 seconds but termin.
    count=7 first=80936 curr=73720 min=73663 max=80936 avg=74766.3 std=2519         


Running label_image example
^^^^^^^^^^^^^^^^^^^^^^^^^^^

The *label_image* provides an image classification example using TensorFlow Lite.
Options for *label_image*:

::

    --accelerated, -a: [0|1], use Android NNAPI or not
    --count, -c: loop interpreter->Invoke() for certain times
    --input_mean, -b: input mean
    --input_std, -s: input standard deviation
    --image, -i: image_name.bmp
    --labels, -l: labels for the model
    --tflite_model, -m: model_name.tflite
    --profiling, -p: [0|1], profiling or not
    --num_results, -r: number of results to show
    --threads, -t: number of threads
    --verbose, -v: [0|1] print more information   

Example of running *label_image* on target, using the pre-installed mobilenet_v1_1.0_224_quant.tflite model,
`grace_hopper.bmp <https://raw.githubusercontent.com/tensorflow/tensorflow/r1.12/tensorflow/contrib/lite/examples/label_image/testdata/grace_hopper.bmp>`__, and labels.txt.

::

    # cd /usr/share/tensorflow-lite/examples
    # ./label_image -i grace_hopper.bmp -l labels.txt -m mobilenet_v1_1.0_224_quant.tflite
    Loaded model mobilenet_v1_1.0_224_quant.tflite
    resolved reporter
    invoked 
    average time: 164.164 ms 
    0.780392: 653 military uniform
    0.105882: 907 Windsor tie
    0.0156863: 458 bow tie
    0.0117647: 466 bulletproof vest
    0.00784314: 835 suit


