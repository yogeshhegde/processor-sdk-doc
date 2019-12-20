# Licensed to the Apache Software Foundation (ASF) under one
# or more contributor license agreements.  See the NOTICE file
# distributed with this work for additional information
# regarding copyright ownership.  The ASF licenses this file
# to you under the Apache License, Version 2.0 (the
# "License"); you may not use this file except in compliance
# with the License.  You may obtain a copy of the License at
#
#   http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing,
# software distributed under the License is distributed on an
# "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
# KIND, either express or implied.  See the License for the
# specific language governing permissions and limitations
# under the License.

######################################################################
# Set up arguments and add additional information to help message
import argparse
import textwrap

parser = argparse.ArgumentParser(
      prog='ProgramName',
      formatter_class=argparse.RawDescriptionHelpFormatter,
      epilog=textwrap.dedent('''\
         Additional information: issue this command on the remote target before running this program:
             python3 -m tvm.exec.rpc_server --host 10.1.1.1 --port=9090
         '''))

parser.add_argument("remoteIp", help="Remote IP Address")

try:
    args = parser.parse_args()
except SystemExit:
    quit()

######################################################################
# Import modules
import tvm
from tvm import relay
import numpy as np
import os.path
import tensorflow as tf
import tvm.relay.testing.tf as tf_testing

######################################################################
# Obtain model, input image and all related files.

# Base location for model related files.
repo_base = 'https://github.com/dmlc/web-data/raw/master/tensorflow/models/InceptionV1/'

# Test image
img_name = 'elephant-299.jpg'
image_url = os.path.join(repo_base, img_name)

# Model
model_name = 'classify_image_graph_def-with_shapes.pb'
model_url = os.path.join(repo_base, model_name)

# Image label map
map_proto = 'imagenet_2012_challenge_label_map_proto.pbtxt'
map_proto_url = os.path.join(repo_base, map_proto)

# Human readable text for labels
label_map = 'imagenet_synset_to_human_label_map.txt'
label_map_url = os.path.join(repo_base, label_map)

# Download files listed above.
from tvm.contrib.download import download_testdata

img_path = download_testdata(image_url, img_name, module='data')
model_path = download_testdata(model_url, model_name, module=['tf', 'InceptionV1'])
map_proto_path = download_testdata(map_proto_url, map_proto, module='data')
label_path = download_testdata(label_map_url, label_map, module='data')

######################################################################
# Import model
# ------------
# Creates tensorflow graph definition from protobuf file.
with tf.gfile.FastGFile(model_path, 'rb') as f:
    graph_def = tf.GraphDef()
    graph_def.ParseFromString(f.read())
    graph = tf.import_graph_def(graph_def, name='')
    # Call the utility to import the graph definition into default graph.
    graph_def = tf_testing.ProcessGraphDefParam(graph_def)
    # Add shapes to the graph.
    with tf.Session() as sess:
        graph_def = tf_testing.AddShapesToGraphDef(sess, 'softmax')

# Load image
from PIL import Image
image = Image.open(img_path).resize((299, 299))
x = np.array(image)

######################################################################
# Import the graph to Relay
# -------------------------
# Import tensorflow graph definition to relay frontend.
#
# Results:
#   sym: relay expr for given tensorflow protobuf.
#   params: params converted from tensorflow params (tensor protobuf).
shape_dict = {'DecodeJpeg/contents': x.shape}
dtype_dict = {'DecodeJpeg/contents': 'uint8'}
mod, params = relay.frontend.from_tensorflow(graph_def,
                                             layout=None,
                                             shape=shape_dict)

print("======== Tensorflow protobuf imported to relay frontend. ========")

######################################################################
# Relay Build
# -----------
# Compile the graph to llvm target with given input specification.
#
# Results:
#   graph: Final graph after compilation.
#   params: final params after compilation.
#   lib: target library which can be deployed on target with TVM runtime.
target = tvm.target.create('llvm -device=arm_cpu -target=armv7l-linux-gnueabihf -mattr=+neon')
with relay.build_config(opt_level=3):
    graph, lib, params = relay.build(mod,
                                     target=target,
                                     params=params)

# Save the library at local directory.
lib_fname = './net.tar'
lib.export_library(lib_fname)

######################################################################
# Deploy the Model Remotely by RPC
# --------------------------------
# The remot target should run the following command: 
#    python3 -m tvm.exec.rpc_server --host 0.0.0.0 --port=9090
from tvm.contrib import graph_runtime as runtime
from tvm import rpc

# obtain an RPC session from remote device.
host = args.remoteIp
port = 9090
remote = rpc.connect(host, port)

# upload the library to remote device and load it
remote.upload(lib_fname)
rlib = remote.load_module('net.tar')

# create the remote runtime module
ctx = remote.cpu(0)
dtype = 'uint8'
module = runtime.create(graph, rlib, ctx)
# set parameter (upload params to the remote device. This may take a while)
module.set_input(**params)
# set input data
module.set_input('DecodeJpeg/contents', tvm.nd.array(x.astype(dtype)))

# run
print('====== Run model on the target ======')
module.run()

# get output
print('====== Get results from the target ======')
tvm_output = module.get_output(0, tvm.nd.empty(((1, 1008)), 'float32', remote.cpu(0)))

######################################################################
# Process the output
# ------------------
# Process the model output to human readable text for InceptionV1.
predictions = tvm_output.asnumpy()
predictions = np.squeeze(predictions)

# Creates node ID --> English string lookup.
node_lookup = tf_testing.NodeLookup(label_lookup_path=map_proto_path,
                                    uid_lookup_path=label_path)

# Print top 5 predictions from TVM output.
top_k = predictions.argsort()[-5:][::-1]
for node_id in top_k:
    human_string = node_lookup.id_to_string(node_id)
    score = predictions[node_id]
    print('%s (score = %.5f)' % (human_string, score))

