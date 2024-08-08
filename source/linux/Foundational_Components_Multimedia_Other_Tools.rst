#############################
FFmpeg Plugins for Multimedia
#############################

:command:`ffmpeg` is an open-source multimedia framework. This is useful for decoding, encoding and transcoding videos. This is a command line tool.

The library comes with :command:`ffplay` and :command:`ffprobe`.

:command:`ffplay` is a very simple and portable media player using the :command:`ffmpeg` libraries and the SDL library. It is mostly used as a testbed for the various :command:`ffmpeg` APIs.

:command:`ffprobe` gathers information from multimedia streams and prints it in human and machine-readable fashion.

For example, it can be used to check the format of the container used and the format and type of each media stream contained in it.

To enable :command:`ffplay`, the following needs to be added to :file:`local.conf`:

.. code-block::  text

   PACKAGECONFIG:append:pn-ffmpeg = " sdl2"

More information about the :command:`ffmpeg` tools can be found here:
   - https://ffmpeg.org/ffmpeg.html
   - https://ffmpeg.org/ffplay.html
   - https://ffmpeg.org/ffprobe.html

************
Useful Flags
************

ffmpeg
======

Help Flags
----------
``-h`` or ``-?`` or ``-help``
   Topic show help
``-codecs``
   Displays all codecs supported
``-decoders``
   Displays all decoders supported
``-formats``
   Displays all available formats
``-pix_fmts``
   Displays all available pixel formats

``-codec:v``
   Specifies the stream decoder. For decoding, we only ``hevc_v4l2m2m`` and ``h264_v4l2m2m``. :v stands for video

Stream Specific Flags
---------------------
``-re``
   Reads input at native frame rate
``-i [filename]``
   Input stream
``-fps_mode passthrough``
   Allows for frames to pass even if out of sync. Needed since there are no timestamps in decoded h264/5 streams that use the hardware GPU to decode. Must be placed in between input and output stream
``-pix_fmt``
   Specifies the pixel format for the output stream. NV12 is recommended for wave5
``-f``
   Forces format of output stream
``-frames``
   Set the number of frames to record

ffplay
======
``-framerate``
   Specifies framerate of display stream
``-video_size``
   Specifies video size of video. It may be the string of the form or *widthxheigh*. For example, 2k or 2048x1080 are equivalent.
``-pixel_format``
   Specifies pixel format of display stream
``-f``
   Forces format of display stream
``-fs``
   Start in fullscreen mode
``-autoexit``
   Exits ffplay after stream is finished

ffprobe
=======
``-show_data``
   Show payload data, as a hexadecimal and ASCII dump. Coupled with -show_packets, it will dump the packets’ data. Coupled with -show_streams, it will dump the codec extradata
   The dump is printed as the "data" field. It may contain newlines
``-show_packets``
   Show information about each packet contained in the input multimedia stream
   The information for each single packet is printed within a dedicated section with name "PACKET"
``-show_frames``
   Show information about each frame and subtitle contained in the input multimedia stream
   The information for each single frame is printed within a dedicated section with name "FRAME" or "SUBTITLE"
``-show_format``
   Show information about the container format of the input multimedia stream
   All the container format information is printed within a section with name "FORMAT"

****************
Example Commands
****************

To convert a HEVC file to a raw video with pixel format NV12 named :file:`foo.yuv` with software acceleration, the following can be used:

.. code-block:: console
   
   ffmpeg -i foo.265 -f rawvideo -pix_fmt nv12 foo.yuv

To convert a H264 file to a raw video named :file:`bar.yuv` with hardware acceleration and each frame passed, the following can be used:

.. code-block:: console

   ffmpeg -codec:v h264_v4l2m2m -i bar.h264 -f rawvideo -fps_mode passthrough bar.yuv

To play a H264 video and output to the display at fullscreen and exit once the video is done playing, the following can be used:

.. code-block:: console
   
   ffplay -fs -autoexit foobar.264

To pipe the output from ffmpeg to ffplay with hardware acceleration, the following can be used:

.. code-block:: console

   ffmpeg -re -codec:v hevc_v4l2m2m -i input.h265 -fps_mode passthrough -f rawvideo - | ffplay -framerate 30 -video_size 1920x1080 -f rawvideo -autoexit -

To print out the packet's data and payload data in hexadecimal from a given multimedia stream named :file:`foo.h265`, the following can be used:

.. code-block:: console
   
   ffprobe -show_data -show_packets foo.h265

To print information about each frame and/or subtitle in the given multimedia stream named :file:`bar.h264`, the following can be used:

.. code-block:: console

   ffprobe -show_frames bar.h264

##########################
MPV Plugins for Multimedia
##########################
mpv is a media player based on MPlayer and mplayer2. It supports a wide variety of video file formats, audio and video codecs, and subtitle types. 
Special input URL types are available to read input from a variety of sources other than disk files. 
Depending on platform, a variety of different video and audio output methods are supported.

This is a command line tool that can also use keyboard shortcuts.

https://mpv.io/manual/stable/

:command:`yt-dlp` can be combined with mpv to play videos from the web. (YouTube, TikTok, etc.)

To install :command:`yt-dlp` run the following command

.. code-block:: console

   python3 -m pip install yt-dlp

************
Useful Flags
************

``--vo=[driver]``

Specify the video output backend to be used. See `VIDEO OUTPUT DRIVERS <https://mpv.io/manual/stable/#video-output-drivers>`_ for details and descriptions of available drivers.

``--hwdec=[api1,api2,...|no|auto|auto-safe|auto-copy]``

Specify the hardware video decoding API that should be used if possible. Whether hardware decoding is actually done depends on the video codec. If hardware decoding is not possible, mpv will fall back on software decoding.
Hardware decoding is not enabled by default, to keep the out-of-the-box configuration as reliable as possible. However, when using modern hardware, hardware video decoding should work correctly, offering reduced CPU usage, and possibly lower power consumption.

``--gpu-context=[sys]``

The value auto (the default) selects the GPU context. You can also pass help to get a complete list of compiled in backends (sorted by autoprobe order).

``--fs``

Fullscreen playback.

``--autofit=<[W[xH]]>``

Set the initial window size to a maximum size specified by WxH, without changing the window's aspect ratio. The size is measured in pixels, or if a number is followed by a percentage sign (%), in percents of the screen size.
This option never changes the aspect ratio of the window. If the aspect ratio mismatches, the window's size is reduced until it fits into the specified size.

``--no-correct-pts``

Switches mpv to a mode where video timing is determined using a fixed framerate value (either using the --container-fps-override option, or using file information). Sometimes, files with very broken timestamps can be played somewhat well in this mode.

``--fps=[framerate]``

Set framerate of output stream. Can be combined with --no-correct-pts for streams with incorrect/no timestamps

****************
Example Commands
****************

To play a H264 video to display at 30 frames per seconds, the following can be used:

.. code-block:: console

   mpv --no-correct-pts --fps=30 foo.h264

To play a HEVC video with full/assisted hardware acceleration at 30 frames per second, the following can be used:

.. code-block:: console

   mpv --vo=gpu --hwdec=auto --no-correct-pts --fps=30 bar.h265

To play a mp4 video to display in fullscreen and set the gpu context to wayland, the following can be used:

.. code-block:: console

   mpv --vo=gpu --gpu-context=wayland --fs foobar.mp4

To download a video from a link and pipe the video to mpv with no correct points at 30 frames per seconds, the following can be used:

.. code-block:: console

   yt-dlp -o - <link> | mpv --no-correct-pts --fps=30 -

Tp download a video from a link at 1080p and play the video with mpv, the following can be used:

.. code-block:: console

   yt-dlp -f 270 -o - <link> | mpv -

``-f 232`` can be used to get a 720p video.

In instances where running yt-dlp doesn't work because of a protocol issue, updating to the newest version of yt-dlp or changing
the format/quality by running ``-f 270`` or ``-f 232`` for example, or playing other videos might solve the issue.