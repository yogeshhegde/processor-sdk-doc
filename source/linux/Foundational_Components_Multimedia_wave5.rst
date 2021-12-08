.. include:: /replacevars.rst.inc

.. _foundational-components-multimedia:

*************************
Multimedia
*************************

Introduction
============
The Encoder/Decoder (VENC/VDEC) is a stateful encoder/decoder. It is found on the |__PART_FAMILY_DEVICE_NAMES__| SoC.
Combined H.264 and H.265 encoder/decoder used in the Texas Instruments |__PART_FAMILY_DEVICE_NAMES__| SoC.

-  Hardware capabilities:
-  Maximum resolution: 8192x8192
-  It can handle this resolution, but not necessarily in real-time.

-  Minimum resolution: 256x128

-  Constraints :
-  A picture width shall be multiple of 8.
-  A picture height shall be multiple of 8.

-  Multiple concurrent encode/decode streams :
-  Number of concurrent streams dependant on resolution and framerate.

-  Encoder :
-  Capable of encoding H.265 Main and Main Still Picture Profile @ L5.1 High tier.
-  Capable of encoding H.264 Baseline/Constrained Baseline/Main/High Profiles Level @ L5.2.

-  Decoder :
-  Capable of decoding H.265 Main and Main Still Picture Profile @ L5.1 High tier.
-  Capable of decoding H.264 Baseline/Constrained Baseline/Main/High Profiles @ L5.2.

|

The V4L2 compliance tests report the following controls as available:

.. code-block:: text

 Driver Info:
	Driver name      : vpu-dec
	Card type        : vpu-dec
	Bus info         : platform:vpu-dec
	Driver version   : 5.14.0
	Capabilities     : 0x84204000
		Video Memory-to-Memory Multiplanar
		Streaming
		Extended Pix Format
		Device Capabilities
	Device Caps      : 0x04204000
		Video Memory-to-Memory Multiplanar
		Streaming
		Extended Pix Format
	Detected Stateful Decoder
 Required ioctls:
	test VIDIOC_QUERYCAP: OK
 Allow for multiple opens:
	test second /dev/video0 open: OK
	test VIDIOC_QUERYCAP: OK
	test VIDIOC_G/S_PRIORITY: OK
	test for unlimited opens: OK
	test invalid ioctls: OK
 Debug ioctls:
	test VIDIOC_DBG_G/S_REGISTER: OK (Not Supported)
	test VIDIOC_LOG_STATUS: OK (Not Supported)
 Input ioctls:
	test VIDIOC_G/S_TUNER/ENUM_FREQ_BANDS: OK (Not Supported)
	test VIDIOC_G/S_FREQUENCY: OK (Not Supported)
	test VIDIOC_S_HW_FREQ_SEEK: OK (Not Supported)
	test VIDIOC_ENUMAUDIO: OK (Not Supported)
	test VIDIOC_G/S/ENUMINPUT: OK (Not Supported)
	test VIDIOC_G/S_AUDIO: OK (Not Supported)
	Inputs: 0 Audio Inputs: 0 Tuners: 0
 Output ioctls:
	test VIDIOC_G/S_MODULATOR: OK (Not Supported)
	test VIDIOC_G/S_FREQUENCY: OK (Not Supported)
	test VIDIOC_ENUMAUDOUT: OK (Not Supported)
	test VIDIOC_G/S/ENUMOUTPUT: OK (Not Supported)
	test VIDIOC_G/S_AUDOUT: OK (Not Supported)
	Outputs: 0 Audio Outputs: 0 Modulators: 0
 Input/Output configuration ioctls:
	test VIDIOC_ENUM/G/S/QUERY_STD: OK (Not Supported)
	test VIDIOC_ENUM/G/S/QUERY_DV_TIMINGS: OK (Not Supported)
	test VIDIOC_DV_TIMINGS_CAP: OK (Not Supported)
	test VIDIOC_G/S_EDID: OK (Not Supported)
 Control ioctls:
	test VIDIOC_QUERY_EXT_CTRL/QUERYMENU: OK
	test VIDIOC_QUERYCTRL: OK
	test VIDIOC_G/S_CTRL: OK
	test VIDIOC_G/S/TRY_EXT_CTRLS: OK
	test VIDIOC_(UN)SUBSCRIBE_EVENT/DQEVENT: OK
	test VIDIOC_G/S_JPEGCOMP: OK (Not Supported)
	Standard Controls: 2 Private Controls: 1
 Format ioctls:
	test VIDIOC_ENUM_FMT/FRAMESIZES/FRAMEINTERVALS: OK
	test VIDIOC_G/S_PARM: OK (Not Supported)
	test VIDIOC_G_FBUF: OK (Not Supported)
	test VIDIOC_G_FMT: OK
	test VIDIOC_TRY_FMT: OK
	test VIDIOC_S_FMT: OK
	test VIDIOC_G_SLICED_VBI_CAP: OK (Not Supported)
	test Cropping: OK (Not Supported)
	test Composing: OK
	test Scaling: OK (Not Supported)
 Codec ioctls:
	test VIDIOC_(TRY_)ENCODER_CMD: OK (Not Supported)
	test VIDIOC_G_ENC_INDEX: OK (Not Supported)
	test VIDIOC_(TRY_)DECODER_CMD: OK
 Buffer ioctls:
	test VIDIOC_REQBUFS/CREATE_BUFS/QUERYBUF: OK
	test VIDIOC_EXPBUF: OK
	test Requests: OK (Not Supported)

|

Software Architecture
=====================

Software Stack of Accelerated Codec Encoding/Decoding
-----------------------------------------------------

As shown in the figures below, the software stack of the accelerated
encoding and decoding has two parts:

-  A V4L2 (Video4Linux version 2) software driver running on Linux on the A72 MPU subsystem
-  The firmware running on the DECODER and ENCODER

The driver communicates with the firmware running on the ENCODER/DECODER
through its own IPC (inter-processor communication).
For the DECODER, at the highest level in the MPU subsystem on the A72,
there is a Linux user space application which is based on GStreamer. GStreamer
is an open source framework that simplifies the development of multimedia
applications. The GStreamer library loads and interfaces with the GStreamer
plugin (V4L2 plugin), which handles all the details specific to the use of
the hardware accelerator. Specifically, the GStreamer plugin interfaces
with the V4L2 decoder kernel driver interface.

.. raw:: html

   <div class="center">

.. raw:: html

   <div class="floatnone">

.. figure:: ../images/MM_Wave5_SW_overview.png
   :alt: codec software stack

   CODEC Software Stack

|

.. rubric:: Overview of the Multimedia Software Stack
   :name: overview-of-the-mm-sw-stack

The Multimedia software contains many software components. Some are
developed by Texas Instruments, and some are developed in and by the
open source community (White). TI contributes, and sometimes even
maintains, some of these open source community projects, but the
support model is different from a project developed solely by TI.


Linux Kernel Drivers
--------------------

.. rubric:: TI-Provided V4L2 Drivers for Multimedia
   :name: ti-provided-v4l2-drivers-for-multimedia

Video4Linux version 2 (V4L2) is an open source framework that
provides a media interface to all Linux-based applications. V4L2 is
a collection of device drivers and an API for supporting realtime
video capture and video memory-to-memory operations on Linux systems.

Video encode and decode using the ENCODER and DECODER hardware, respectively,
are enabled as V4L2 drivers. The V4L2 is integrated with the ENCODER and
DECODER drivers by a thin layer that implements the V4L2 node ioctls
and translates the V4L2 data structures to those understood by the
ENCODER/DECODER.

GStreamer Plugins for Multimedia
--------------------------------

.. rubric:: Open Source GStreamer Overview
   :name: open-source-gstreamer-overview

GStreamer is an open source framework that simplifies the development of
multimedia applications, such as media players and capture encoders. It
encapsulates existing multimedia software components, such as codecs,
filters, and platform-specific I/O operations, by using a standard
interface and providing a uniform framework across applications.

The modular nature of GStreamer facilitates the addition of new
functionality, transparent inclusion of component advancements and
allows for flexibility in application development and testing.
Processing nodes are implemented via GStreamer plugins with several sink
and/or source pads. Many plugins are running as ARM software
implementations, but for more complex SoCs, certain functions are better
executed on hardware-accelerated IPs like wave5 (DECODER and ENCODER).

GStreamer is a multimedia framework based on data flow paradigm. It allows
easy plugin registration just by deploying new shared objects to the
/usr/lib/gstreamer-1.0 folder. The shared libraries in this folder are
scanned for reserved data structures identifying capabilities of
individual plugins. Individual processing nodes can be interconnected as
a pipeline at run-time, creating complex topologies. Node interfacing
compatibility is verified at that time - before the pipeline is started.

GStreamer brings a lot of value-added features to |__SDK_FULL_NAME__|,
including audio encoding/decoding, audio/video synchronization, and
interaction with a wide variety of open source plugins (muxers,
demuxers, codecs, and filters). New GStreamer features are continuously
being added, and the core libraries are actively supported by
participants in the GStreamer community. Additional information about
the GStreamer framework is available on the GStreamer project site:
http://gstreamer.freedesktop.org/.

.. rubric:: Hardware-Accelerated GStreamer Plugins
   :name: video-decode-gstreamer-plugins

One benefit of using GStreamer as a multimedia framework is that the
core libraries already build and run on ARM Linux. Only a GStreamer
plugin is required to enable additional hardware features on TI's
embedded processors with both ARM and hardware accelerators for
multimedia. The open source GStreamer plugins provide elements for
GStreamer pipelines that enable the use of hardware-accelerated video
decoding through the V4L2 GStreamer plugin.

Below is a list of GStreamer plugins that utilize the hardware-accelerated
video decoding/encoding in the |__PART_FAMILY_DEVICE_NAMES__|.

-  DECODER

#. v4l2h264dec
#. v4l2h265dec

-  ENCODER

#. v4l2h264enc
#. v4l2h265enc

V4L2 Video Encoder/Decoder
^^^^^^^^^^^^^^^^^^^^^^^^^^

The V4L2 encoder/decoder driver supports the following bitstream
formats:

-  V4L2_PIX_FMT_H264
-  V4L2_PIX_FMT_HEVC

GStreamer Pipelines
===================

.. code-block:: text

    H.264 encode:
        target # gst-launch-1.0 filesrc location=/<path_to_file>  ! rawvideoparse width=1920 height=1080 format=i420 framerate=30/1 ! v4l2h264enc ! filesink location=/<path_to_file>  sync=true
    H.265 encode:
        target # gst-launch-1.0 filesrc location=/<path_to_file>  ! rawvideoparse width=1920 height=1080 format=i420 framerate=30/1 ! v4l2h265enc ! filesink location=/<path_to_file>  sync=true

.. code-block:: text

   H.264 decode:
        target # gst-launch-1.0 filesrc location=/<path_to_file>  ! matroskademux ! h264parse ! queue ! v4l2h264dec ! filesink location=/<path_to_file>
   H.265 decode:
        target # gst-launch-1.0 filesrc location=/<path_to_file>  ! matroskademux ! h265parse ! queue ! v4l2h265dec ! filesink location=/<path_to_file>

.. note::

 Known Limitations:

   #.  CTRL-C results in rmmod/insmod being needed to reinitialize the driver.

       In the case that EOF is not handled in GStreamer, the user is left with no option but to hit ctrl-c to terminate the pipeline.
       However after this has been done no subsequent operation can be performed using GStreamer with the wave5 encoder/decoder without first doing rmmod wave5 and then insmod wave5.ko,
       after this has been done. New GStreamer pipelines can be correctly instantiated.

   #.  kmssink rendering has color space mismatch.

       When rendering to kmssink the output of wave5 driver is limited to I420 - the TI kmssink only handles NV12 - even if the caps are forced to NV12 the wave5 driver always
       seems to output I420. When using the wayland sink (which does handle i420) the colors appear to be correct on the screen.
       The colors in the image are messed up with this pipeline:

       gst-launch-1.0 filesrc location=/<path_to_file> ! matroskademux ! h264parse ! v4l2h264dec ! kmssink driver-name=tidss
       as does this:
       gst-launch-1.0 filesrc location=/<path_to_file> ! matroskademux ! h264parse ! v4l2h264dec ! video/x-raw,format=NV12 ! kmssink driver-name=tidss

       This works - but of course it is incredibly slow:
       gst-launch-1.0 filesrc location=/<path_to_file> ! matroskademux ! h264parse ! v4l2h264dec ! video/x-raw,format=I420 ! videoconvert ! video/x-raw,format=NV12 \
       ! kmssink driver-name=tidss

   #.  GStreamer End of File does not result in pipeline termination.

       When a gst filesrc is used for both the encoder and the decoder,  when the file hits EOF the pipeline just hangs and never terminates. Only way out is a ctrl-c.

   #.  The full set of encoder configurations is not currently exposed through the V4L2 interface
       See compliance data for what is available and what is not.
