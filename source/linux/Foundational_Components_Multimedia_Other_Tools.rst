FFmpeg Plugins for Multimedia
=============================
ffmpeg is an open-source multimedia framework. This is useful for decoding, encoding and transcoding videos.

The library comes with ffplay and ffprobe.

ffplay is a very simple and portable media player using the ffmpeg libraries and the SDL library. It is mostly used as a testbed for the various ffmpeg APIs.

ffprobe gathers information from multimedia streams and prints it in human- and machine-readable fashion.

For example, it can be used to check the format of the container used by a multimedia stream and the format and type of each media stream contained in it.

To enable ffplay, the following needs to be added to **ffmpeg_%.bbappend**:\

``PACKAGECONFIG:append = "sdl2"``

This is a command line tool.

https://ffmpeg.org/ffmpeg.html
https://ffmpeg.org/ffplay.html
https://ffmpeg.org/ffprobe.html

Useful Flags
------------
**ffmpeg**

Help Flags

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

**ffplay**

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

**ffprobe**

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

Example Commands
----------------
``ffmpeg -i foo.265 -f rawvideo -pix_fmt nv12 foo.yuv``

The command above takes in a hevc file and converts it to a raw video with pixel format nv12 called foo.yuv. This uses software hardware acceleration.

``ffmpeg -codec:v h264_v4l2m2m -i bar.h264 -f rawvideo -pix_fmt nv12 -fps_mode passthrough bar.yuv``

The command above takes in a h264 file and converts it to a raw video with pixel format nv12 called bar.yuv. This command also utilizes the hardware GPU with h264_v4l2m2. Since it uses the hardware GPU and takes in an h264/5 input stream, fps_mode is needed to decode all frames. If not included, it will only decode up to first 3 frames.

``ffmpeg -re -codec:v hevc_v4l2m2m -i input.h265 -fps_mode passthrough -pix_fmt nv12 -f rawvideo - | ffplay -framerate 30 -video_size 1920x1080 -pixel_format nv12 -f rawvideo -autoexit -``

The command above decodes a hevc stream at the native refresh rate and pipes it to ffplay. ffplay will output a 30 fps 1080p stream and will quit once the video is done playing.

``ffplay -fs -autoexit foobar.264``

The command above decodes a h264 file and outputs to a display in fullscreen mode and will automatically quit once the video is done playing.

``ffprobe -show_data -show_packets foo.h265``

The command above prints the packet's data and payload data in hexadecimal from the given stream.

``ffprobe -show_frames bar.h264``

The command above prints information about each frame and subtitle in the given input multimedia stream.



MPV Plugins for Multimedia
==========================
mpv is a media player based on MPlayer and mplayer2. It supports a wide variety of video file formats, audio and video codecs, and subtitle types. 
Special input URL types are available to read input from a variety of sources other than disk files. 
Depending on platform, a variety of different video and audio output methods are supported.

This is a command line tool that can also use keyboard shortcuts.

https://mpv.io/manual/stable/

``yt-dlp`` can be combined with mpv to play videos from the web. (YouTube, TikTok, etc.)

To install ``yt-dlp`` run the following command

``python3 -m pip install yt-dlp``

Useful Flags
------------

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

Example Commands
----------------
``mpv --no-correct-pts --fps=30 foo.h264``

The command above decodes an h264 file and outputs to the display and is set to 30 frames per second.

``mpv --vo=gpu --hwdec=auto --no-correct-pts --fps=30 bar.h265``

The command above decodes an hevc file and outputs to display using the available hardware acceleration
at 30 frames per second.

``mpv --vo=gpu --gpu-context=wayland --fs foobar.mp4``

The command above displays a mp4 video to display and sets the gpu context to wayland and sets the video to Fullscreen

``yt-dlp -o - <link> | mpv --no-correct-pts --fps=30 -``

The command above downloads a video from a link and pipes the video to mpv with no correct points at 30 frames per seconds

``yt-dlp -f 270 -o - <link> | mpv -``

The command above downloads a video from a link at 1080p and plays the video with mpv. ``-f 232`` can be used for 720p

In instances where running yt-dlp doesn't work because of a protocol issue, updating to the newest version of yt-dlp or changing
the format/quality by running ``-f 270`` or ``-f 232`` for example, or playing other videos might solve the issue.