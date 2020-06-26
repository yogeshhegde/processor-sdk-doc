Optical Flow with OpenVX
=========================

OpenVX Example Block Diagram
-------------------------------

OpenVx tutorial example demontrates the optical flow based on
image pyramids and Harris corner tracking. It builds upon TIOVX, and utilizes OpenCV for reading
the input (from file or camera) and rending the output for display. Input frame from OpenCV
invokes OpenVX graph, and the processing is done once per input frame. OpenVX defines the graph
topology and all configuration details. All resources are allocated and initialzied before processing.


.. Image:: /images/OpenVx-Example-Block-Diagram.png

|


Run OpenVx Tutorial Example
----------------------------

The binary for OpenVX tutorial example is located at /usr/bin/tiovx-opticalflow. It is a statically linked Linux application running on Arm.


Before running the tutorial example, download `the test clip <http://ewh.ieee.org/r6/scv/sps/openvx-material/PETS09-S1-L1-View001.avi>`__
and copy it to file system (e.g. ~/tiovx). Then, execute the commands below to load OpenVx firmware and run the optical flow example.

::

    reload-dsp-fw.sh tiovx                                       # load openvx firmware and restart dsps
    tiovx-opticalflow /home/root/tiovx/PETS09-S1-L1-View001.avi  # Run tutorial example


Screen capture after running the optical flow example:


.. Image:: /images/OpenVx-Example-Screen-Shot.png


Logs:

::

    root@am57xx-evm:~# tiovx-opticalflow /home/root/PETS09-S1-L1-View001.avi
     VX_ZONE_INIT:Enabled
     VX_ZONE_ERROR:Enabled
     VX_ZONE_WARNING:Enabled
    VSPRINTF_DBG:SYSTEM NOTIFY_INIT: starting
    VSPRINTF_DBG: SYSTEM: IPC: Notify init in progress !!!

    VSPRINTF_DBG:[0] DUMP ALL PROCS[3]=DSP1
    VSPRINTF_DBG:[1] DUMP ALL PROCS[4]=DSP2
    VSPRINTF_DBG:Next rx queue to open:QUE_RX_HOST

    VSPRINTF_DBG:Just created MsgQue
    VSPRINTF_DBG:Created RX task
    VSPRINTF_DBG:Next tx queue to open:QUE_RX_DSP1, procId=3
    VSPRINTF_DBG:Next tx queue to open:QUE_RX_DSP2, procId=4
    VSPRINTF_DBG:Dump all TX queues: procId=3 name=QUE_RX_DSP1 queId=262272, msgSize=68, heapId=0
    VSPRINTF_DBG:Dump all TX queues: procId=4 name=QUE_RX_DSP2 queId=196736, msgSize=68, heapId=0
    VSPRINTF_DBG:SYSTEM: IPC: SentCfgMsg, procId=3 queuId=262272
    VSPRINTF_DBG:SYSTEM: IPC: SentCfgMsg, procId=4 queuId=196736
    VSPRINTF_DBG: SYSTEM: IPC: Notify init DONE !!!

    VSPRINTF_DBG:>>>> ipcNotifyInit returned: 0

    VSPRINTF_DBG:SYSTEM NOTIFY_INIT: done
    OK: FILE /home/root/PETS09-S1-L1-View001.avi 768x480
    init done
    Using Wayland-EGL
    wlpvr: PVR Services Initialised
    LOG: [ status = -1 ] Hello there!


Run the optical flow example with camera input:


::

    reload-dsp-fw.sh tiovx        # load openvx firmware and restart dsps
    tiovx-opticalflow             # Run tutorial example with camera input

Logs:

::

    root@am57xx-evm:~# tiovx-opticalflow
     VX_ZONE_INIT:Enabled
     VX_ZONE_ERROR:Enabled
     VX_ZONE_WARNING:Enabled
    VSPRINTF_DBG:SYSTEM NOTIFY_INIT: starting
    VSPRINTF_DBG: SYSTEM: IPC: Notify init in progress !!!

    VSPRINTF_DBG:[0] DUMP ALL PROCS[3]=DSP1
    VSPRINTF_DBG:[1] DUMP ALL PROCS[4]=DSP2
    VSPRINTF_DBG:Next rx queue to open:QUE_RX_HOST

    VSPRINTF_DBG:Just created MsgQue
    VSPRINTF_DBG:Created RX task
    VSPRINTF_DBG:Next tx queue to open:QUE_RX_DSP1, procId=3
    VSPRINTF_DBG:Next tx queue to open:QUE_RX_DSP2, procId=4
    VSPRINTF_DBG:Dump all TX queues: procId=3 name=QUE_RX_DSP1 queId=262272, msgSize=68, heapId=0
    VSPRINTF_DBG:Dump all TX queues: procId=4 name=QUE_RX_DSP2 queId=196736, msgSize=68, heapId=0
    VSPRINTF_DBG:SYSTEM: IPC: SentCfgMsg, procId=3 queuId=262272
    VSPRINTF_DBG:SYSTEM: IPC: SentCfgMsg, procId=4 queuId=196736
    VSPRINTF_DBG: SYSTEM: IPC: Notify init DONE !!!

    VSPRINTF_DBG:>>>> ipcNotifyInit returned: 0

    VSPRINTF_DBG:SYSTEM NOTIFY_INIT: done
    OK: CAMERA#1 640x480
    init done
    Using Wayland-EGL
    wlpvr: PVR Services Initialised
    LOG: [ status = -1 ] Hello there!


After finishing running the OpenVX tutorial example, switch the firmware back to the default for OpenCL:

::

    reload-dsp-fw.sh opencl        # load opencl firmware and restart dsps

