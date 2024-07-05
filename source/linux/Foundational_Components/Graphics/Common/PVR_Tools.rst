#############
PowerVR Tools
#############

The suite of PowerVR Tools is designed to enable rapid graphics application
development. It targets a range of areas including asset exporting and
optimization, PC emulation, prototyping environments, on-line and off-line
performance analysis tools and many more. Please refer to PowerVR-SDK_ for
additional details on the tools and detailed documentation.

There are a number of useful tools available in the Imagination PowerVR SDK that
are compatible with our devices. Two of the most useful tools available are
PVRTune and PVRCarbon, which can be used for to profiling and tracing GFX
activities.

Previously these were included in the target's rootfs, but these were removed
due to tight version dependencies between the target and host tools. Imagination
has moved to packaging the target binaries with their host installer, so we
recommend using those binaries directly for guaranteed compatibility.

*******
PVRTune
*******

The PVRTune utility is a real-time GPU performance analysis tool. It captures
hardware timing data and counters which facilitate the identification of
performance bottlenecks. PVRPerfServer should be used along with the PVRTune
running on the PC to gather data on the SGX loading and activity threads. The
target binaries can be found in the host's PVRTune installation directory under
PVRPerfServer.

For more information please refer to Imagination's upstream documentation on
PVRTune and PVRPerfServer.

   - `<https://docs.imgtec.com/tools-manuals/pvrtune-manual/html/pvrtune-manual/topics/introduction.html>`_

*********
PVRCarbon
*********

The PVRCarbon is an OpenGL\ |reg| ES and Vulkan |reg| API recording and analysis
utility. PVRCarbon GUI provides off-line tools to inspect captured data,
identify redundant calls, highlight costly shaders and many more. This tool can
capture traces on target and then play them back on multiple different devices
by introducing shim libraries in place of the standard offering for that API.

This requires a little bit of setup on the target though. Please refer to
Imagination's upstream target setup guide for the most recent instructions.

   - `<https://docs.imgtec.com/tools-manuals/pvrcarbon-manual/html/topics/pvrcarbon-recorder/opengl-es.html>`_

.. _PowerVR-SDK: https://www.imgtec.com/developers/powervr-sdk-tools/installers/

.. |reg| unicode:: U+000AE .. REGISTERED SIGN
