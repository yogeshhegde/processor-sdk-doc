.. http://processors.wiki.ti.com/index.php/ROS_Radar_demo_user_guide.html

ROS and Radar
=============

Introduction
------------

The ROS is meta-ros running on top of Linux. It is a collection of software
libraries and packages to help you write robotic applications. Both mobile
platforms and static manipulators can leverage wide colelction of open-source
drivers and tools. ROS framework is mainly based on publisher-subscriber
model, and in some cases server-client mode.

It is frequently the case that ROS based applications require sensors enabling
interaction with the environment. Various types of sensors can be used:
cameras, ultrasound, time-of-flight RGBD cameras, lidars, ...

In case of 3D sensors, typical output is point cloud. Consumer of this information
(e.g. for navigation) is decoupled from point cloud producer since format is well
defined. Due to modular nature of ROS it is easy to replace one sensor with the
other as long as format of information (in this case point cloud) is the same.

An important type of 3D sensor, especially suited for outdoor use cases is 
mmWave radar (77-81GHz). For this demo IWR/AWR-1443 or 1642 EVM is needed.
It is connected to Sitara device over USB connection creating virtual UART.

Optionally to make this platform movable, Kobuki mobile base can be added.
Sitara EVM and Radar EVM would be attached to Kobuki, and Sitara EVM running ROS
would control Kobuki movement via USB connection. Please note that mobile base
is not essentail for verification of ROS on Sitara plus Radar EVM operation.

It is desirable to have Ubuntu Linux box (typically Linux PC desktop or laptop) with Ubuntu 14.04LTS
and ROS indigo installed (please note that ROS Indigo is natively supported in Ubuntu 14.04).


HW Setup
--------

*  `Sitara device, e.g. AM5728 GP EVM <http://processors.wiki.ti.com/index.php/AM572x_GP_EVM_Hardware_Setup>`__

.. Image:: /images//am572x-evm.png

*  `IWR1443 Radar EVM <http://www.ti.com/tool/IWR1443BOOST#0>`__ or
   `IWR1642 Radar EVM <http://www.ti.com/tool/IWR1642BOOST#0>`__

.. Image:: /images/radar-evm-1443.png


* USB to microUSB cable (connecting USB connector on Sitara side with microUSB connector on Radar EVM

* [optional] Kobuki mobile base (as used by Turtlebot2), http://kobuki.yujinrobot.com/

.. figure:: /images/ros_radar_1.png
    :width: 800px
    :align: center
    :height: 450px
    :alt: alternate text
    :figclass: align-center

    Kobuki mobile base with Sitara, Radar EVMs and monitoring Ubuntu Linux box (PC desktop or laptop)

.. rubric:: Compatibility
   :name: compatibility

The ti_mmwave_rospkg ROS driver package on Sitara is tested with Processor Linux SDK
which includes meta-ros layer, indigo, (from https://github.com/bmwcarit/meta-ros).

.. _ros-indigo-installation-ubuntu:

For visualization we use ROS indigo distro on Ubuntu Linux box, preffered for compatibility reasons. Run the commands
below to install ROS indigo on Ubuntu Linux box. More details can be found from http://wiki.ros.org/indigo/Installation/Ubuntu.

.. code-block:: console

        sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu trusty main" > /etc/apt/sources.list.d/ros-latest.list'
        wget https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -O - | sudo apt-key add -
        sudo apt-get update
        sudo apt-get install ros-indigo-desktop-full

For this demo, IWR EVM requires mmWave SDK firmware. If different firmware is used on Radar EVM, please follow
procedure using UniFlash tool to install `mmWave SDK <http://www.ti.com/tool/MMWAVE-SDK>`__.

ROS configuration verification
------------------------------

ROS is part of PLSDK 4.3 target filesystem, including mmWave ROS driver, so no additional
installation steps are required. ROS is installed in /opt/ros/indigo folder.
Only setting up configuration related to specific IP address
of target EVM, and Ubuntu Linux box host IP address is needed.
ROS is distributed meta-ros, with single ROS host acting as a broker for all internode transcations.
It runs roscore node and in this case roscore is executed on Sitara. Ubuntu Linux box will only run
ROS RViz node since RViz requires OpenGL desktop support (Sitara only supports OpenGL ES 2.0).

.. note:: If visualization using RViz is not needed, Ubuntu Linux box is not necessary for this demo (except to start
          multiple SSH terminals).


.. _reconfigure-plsdk-for-python3:

.. topic:: Reconfigure PLSDK for Python3

    PLSDK includes ROS packages from meta-ros layer, compiled with Python3 support (build/conf/local.conf : ROS_USE_PYTHON3 = "yes")
    As PLSDK default python setting is Python 2.7, filesystem update is required for ROS tests to run:


.. code-block:: console

   root@am57xx-evm:/usr/bin# ln -sf python3 python.python
   root@am57xx-evm:/usr/bin# ln -sf python3-config python-config.python

ROS between distributed nodes (Sitara and Ubuntu Linux box)
--------------------------------------------------------------
     
.. rubric:: 1st SSH terminal, to Sitara EVM
   :name: 1st-ssh-terminal-1-ros-demo1

.. _modify-setup-bash:

Modify /opt/ros/indigo/setup.bash

.. code-block:: console

        export ROS_ROOT=/opt/ros/indigo
        export PATH=$PATH:/opt/ros/indigo/bin
        export LD_LIBRARY_PATH=/opt/ros/indigo/lib
        export PYTHONPATH=/usr/lib/python3.5/site-packages:/opt/ros/indigo/lib/python3.5/site-packages
        export ROS_MASTER_URI=http://$SITARA_IP_ADDR:11311
        export ROS_IP=$SITARA_IP_ADDR
        export CMAKE_PREFIX_PATH=/opt/ros/indigo
        export ROS_PACKAGE_PATH=/opt/ros/indigo/share
        touch /opt/ros/indigo/.catkin

Then, execute 

.. code-block:: console

        source /opt/ros/indigo/setup.bash
        roscore

.. rubric:: 2nd SSH terminal, to Sitara EVM 
   :name: 2nd-ssh-terminal-1-demo1

.. code-block:: console

        source /opt/ros/indigo/setup.bash
        rosrun roscpp_tutorials talker

You will see log similar to following:

.. code-block:: console

    ....[ INFO] [1516637959.231163685]: hello world 5295
    [ INFO] [1516637959.331163994]: hello world 5296
    [ INFO] [1516637959.431165605]: hello world 5297
    [ INFO] [1516637959.531161359]: hello world 5298
    [ INFO] [1516637959.631162807]: hello world 5299
    [ INFO] [1516637959.731166207]: hello world 5300
    [ INFO] [1516637959.831215641]: hello world 5301
    [ INFO] [1516637959.931165361]: hello world 5302
    [ INFO] [1516637960.031165019]: hello world 5303
    [ INFO] [1516637960.131164027]: hello world 5304

.. rubric:: 3rd SSH terminal, to Linux BOX (Optional)
   :name: 3rd-ssh-terminal-1-demo1

.. code-block:: console

         export ROS_MASTER_URI=http://$SITARA_IP_ADDR:11311
         export ROS_IP=$LINUXBOX_IP_ADDR
         source /opt/ros/indigo/setup.bash
         rosrun roscpp_tutorials listener

You will see log similar to following:

.. code-block:: console

   ...
   data: hello world 5338
   ---
   data: hello world 5339
   ---
   data: hello world 5340
   ---
   data: hello world 5341
   ---
   data: hello world 5342
   ---
   data: hello world 5343
   ---
   data: hello world 5344


mmWave ROS node on Sitara and RViz on Ubuntu Linux box
------------------------------------------------------

.. rubric:: 1st SSH terminal, to Sitara EVM
   :name: 1st-ssh-terminal-1-ros-demo2

Start roscore, only if it is not already started

   source /opt/ros/indigo/setup.bash
   roscore


.. rubric:: 2nd SSH terminal, to Sitara EVM
   :name: 2nd-ssh-terminal-1-ros-demo2

.. code-block:: console

   source /opt/ros/indigo/setup.bash
   roslaunch  ti_mmwave_rospkg rviz_1443_3d.launch

   Change "rviz_1443_3d.launch to "rviz_1642_2d.launch", based on Radar EVM type (1443 or 1642).
   
   
If Kobuki mobile is available, use the command below instead:

.. code-block:: console

	roslaunch  ti_mmwave_rospkg plsdk_rviz_1443_3d.launch

Sample log is included:

.. code-block:: console

	source /opt/ros/indigo/setup.bash
	roslaunch ti_mmwave_rospkg plsdk_rviz_1443_3d.launch

	... logging to /home/root/.ros/log/97dfe396-2711-11e8-bd4a-a0f6fdc25c34/roslaunch-am57xx-evm-7487.log
	Checking log directory for disk usage. This may take awhile.
	Press Ctrl-C to interrupt
	Done checking log file disk usage. Usage is <1GB.

	started roslaunch server http://192.168.0.222:35481/

	SUMMARY
	========

	PARAMETERS
	 * /fake_localization/use_map_topic: True
	 * /mmWave_Manager/command_port: /dev/ttyACM0
	 * /mmWave_Manager/command_rate: 115200
	 * /mmWave_Manager/data_port: /dev/ttyACM1
	 * /mmWave_Manager/data_rate: 921600
	 * /mmWave_Manager/max_allowed_azimuth_angle_deg: 90
	 * /mmWave_Manager/max_allowed_elevation_angle_deg: 90
	 * /rosdistro: b'<unknown>\n'
	 * /rosversion: b'1.11.21\n'

	NODES
	  /
	    fake_localization (fake_localization/fake_localization)
	    mmWaveQuickConfig (ti_mmwave_rospkg/mmWaveQuickConfig)
	    mmWave_Manager (ti_mmwave_rospkg/ti_mmwave_rospkg)
	    octomap_server (octomap_server/octomap_server_node)
	    static_tf_map_to_base_radar_link (tf/static_transform_publisher)
	    static_tf_map_to_odom (tf/static_transform_publisher)

	ROS_MASTER_URI=http://192.168.0.222:11311

	core service [/rosout] found
	process[mmWave_Manager-1]: started with pid [7505]
	process[mmWaveQuickConfig-2]: started with pid [7506]
	process[static_tf_map_to_odom-3]: started with pid [7507]
	process[static_tf_map_to_base_radar_link-4]: started with pid [7508]
	[ INFO] [1520981858.224293205]: mmWaveQuickConfig: Configuring mmWave device using config file: /opt/ros/indigo/share/ti_mmwave_rospkg/cfg/1443_3d.cfg
	process[octomap_server-5]: started with pid [7509]
	process[fake_localization-6]: started with pid [7517]
	[ INFO] [1520981858.367713151]: waitForService: Service [/mmWaveCommSrv/mmWaveCLI] has not been advertised, waiting...
	[ INFO] [1520981858.436009564]: Initializing nodelet with 2 worker threads.
	[ INFO] [1520981858.480256524]: mmWaveCommSrv: command_port = /dev/ttyACM0
	[ INFO] [1520981858.480407967]: mmWaveCommSrv: command_rate = 115200
	[ INFO] [1520981858.497923263]: waitForService: Service [/mmWaveCommSrv/mmWaveCLI] is now available.
	[ INFO] [1520981858.498667137]: mmWaveQuickConfig: Ignored blank or comment line: '% ***************************************************************'
	[ INFO] [1520981858.499059815]: mmWaveQuickConfig: Ignored blank or comment line: '% Created for SDK ver:01.01'
	[ INFO] [1520981858.499462577]: mmWaveQuickConfig: Ignored blank or comment line: '% Created using Visualizer ver:1.1.0.1'
	[ INFO] [1520981858.505357942]: mmWaveQuickConfig: Ignored blank or comment line: '% Frequency:77'
	[ INFO] [1520981858.506164932]: mmWaveQuickConfig: Ignored blank or comment line: '% Platform:xWR14xx'
	[ INFO] [1520981858.506843089]: mmWaveQuickConfig: Ignored blank or comment line: '% Scene Classifier:best_range_res'
	[ INFO] [1520981858.507514414]: mmWaveQuickConfig: Ignored blank or comment line: '% Azimuth Resolution(deg):15 + Elevation'
	[ INFO] [1520981858.508289684]: mmWaveQuickConfig: Ignored blank or comment line: '% Range Resolution(m):0.044'
	[ INFO] [1520981858.508999398]: mmWaveQuickConfig: Ignored blank or comment line: '% Maximum unambiguous Range(m):9.01'
	[ INFO] [1520981858.509816310]: mmWaveQuickConfig: Ignored blank or comment line: '% Maximum Radial Velocity(m/s):5.06'
	[ INFO] [1520981858.510520982]: mmWaveQuickConfig: Ignored blank or comment line: '% Radial velocity resolution(m/s):0.64'
	[ INFO] [1520981858.518476684]: mmWaveQuickConfig: Ignored blank or comment line: '% Frame Duration(msec):33.333'
	[ INFO] [1520981858.519262364]: mmWaveQuickConfig: Ignored blank or comment line: '% Range Detection Threshold (dB):9'
	[ INFO] [1520981858.519957764]: mmWaveQuickConfig: Ignored blank or comment line: '% Range Peak Grouping:disabled'
	[ INFO] [1520981858.520157681]: mmWaveDataHdl: data_port = /dev/ttyACM1
	[ INFO] [1520981858.520252841]: mmWaveDataHdl: data_rate = 921600
	[ INFO] [1520981858.520315142]: mmWaveDataHdl: max_allowed_elevation_angle_deg = 90
	[ INFO] [1520981858.520375654]: mmWaveDataHdl: max_allowed_azimuth_angle_deg = 90
	[ INFO] [1520981858.520943849]: mmWaveQuickConfig: Ignored blank or comment line: '% Doppler Peak Grouping:disabled'
	[ INFO] [1520981858.521671945]: mmWaveQuickConfig: Ignored blank or comment line: '% Static clutter removal:disabled'
	[ INFO] [1520981858.522412729]: mmWaveQuickConfig: Ignored blank or comment line: '% ***************************************************************'
	[ INFO] [1520981858.523396537]: mmWaveQuickConfig: Sending command: 'sensorStop'
	[ INFO] [1520981858.533674630]: mmWaveCommSrv: Sending command to sensor: 'sensorStop'
	[ INFO] [1520981858.536083724]: DataUARTHandler Read Thread: Port is open
	[ INFO] [1520981858.548926257]: mmWaveCommSrv: Received response from sensor: 'sensorStop
	Done
	mmwDemo:/>'
	[ INFO] [1520981858.550875817]: mmWaveQuickConfig: Command successful (mmWave sensor responded with 'Done')
	[ INFO] [1520981858.551745758]: mmWaveQuickConfig: Sending command: 'flushCfg'
	[ INFO] [1520981858.559882020]: mmWaveCommSrv: Sending command to sensor: 'flushCfg'
	[ INFO] [1520981858.562726084]: mmWaveCommSrv: Received response from sensor: 'flushCfg
	Done
	mmwDemo:/>'
	[ INFO] [1520981858.564378289]: mmWaveQuickConfig: Command successful (mmWave sensor responded with 'Done')
	[ INFO] [1520981858.565240748]: mmWaveQuickConfig: Sending command: 'dfeDataOutputMode 1'
	[ INFO] [1520981858.573026625]: mmWaveCommSrv: Sending command to sensor: 'dfeDataOutputMode 1'
	[ INFO] [1520981858.576915985]: mmWaveCommSrv: Received response from sensor: 'dfeDataOutputMode 1
	Done
	mmwDemo:/>'
        ...
	mmwDemo:/>'
	[ INFO] [1520981858.776118886]: mmWaveQuickConfig: Command successful (mmWave sensor responded with 'Done')
	[ INFO] [1520981858.776938726]: mmWaveQuickConfig: Sending command: 'compRangeBiasAndRxChanPhase 0.0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0'
	[ INFO] [1520981858.782736816]: mmWaveCommSrv: Sending command to sensor: 'compRangeBiasAndRxChanPhase 0.0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0'
	[ INFO] [1520981858.792102024]: mmWaveCommSrv: Received response from sensor: 'compRangeBiasAndRxChanPhase 0.0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0 1 0
	Done
	mmwDemo:/>'
	[ INFO] [1520981858.793846462]: mmWaveQuickConfig: Command successful (mmWave sensor responded with 'Done')
	[ INFO] [1520981858.794657355]: mmWaveQuickConfig: Sending command: 'measureRangeBiasAndRxChanPhase 0 1.5 0.2'
	[ INFO] [1520981858.800233568]: mmWaveCommSrv: Sending command to sensor: 'measureRangeBiasAndRxChanPhase 0 1.5 0.2'
	[ INFO] [1520981858.806256139]: mmWaveCommSrv: Received response from sensor: 'measureRangeBiasAndRxChanPhase 0 1.5 0.2
	Done
	mmwDemo:/>'
	[ INFO] [1520981858.807890614]: mmWaveQuickConfig: Command successful (mmWave sensor responded with 'Done')
	[ INFO] [1520981858.808687680]: mmWaveQuickConfig: Sending command: 'sensorStart'
	[ INFO] [1520981858.814534734]: mmWaveCommSrv: Sending command to sensor: 'sensorStart'
	[ INFO] [1520981858.822598283]: mmWaveCommSrv: Received response from sensor: 'sensorStart
	Done
	mmwDemo:/>'
	[ INFO] [1520981858.824211611]: mmWaveQuickConfig: Command successful (mmWave sensor responded with 'Done')
	[ INFO] [1520981858.824545077]: mmWaveQuickConfig: mmWaveQuickConfig will now terminate. Done configuring mmWave device using config file: /opt/ros/indigo/share/ti_mmwave_rospkg/cfg/1443_3d.cfg
	[mmWaveQuickConfig-2] process has finished cleanly



.. rubric:: 3rd SSH terminal, to Sitara EVM
   :name: 3rd-ssh-terminal-1

Bring up all ROS components for communicting and controlling Kobuki

.. code-block:: console

        source /opt/ros/indigo/setup.bash
        roslaunch kobuki_node minimal.launch


        
.. rubric:: 4th SSH terminal, to Sitara EVM
   :name: 4th-ssh-terminal-1

Start Kobuki teleop console (remotely control Kobuki movement using keyboard)

.. code-block:: console

        source /opt/ros/indigo/setup.bash
        roslaunch kobuki_keyop safe_keyop.launch

		Operating kobuki from keyboard:
		Forward/back arrows : linear velocity incr/decr.
		Right/left arrows : angular velocity incr/decr.
		Spacebar : reset linear/angular velocities.
		d : disable motors.
		e : enable motors.
		q : quit.
        
.. rubric:: 5th SSH terminal, to Ubuntu Linux box
   :name: 5th-ssh-terminal-1

First, :ref:`install ROS Indigo distribution on Ubuntu Linux box <ros-indigo-installation-ubuntu>` if it has not been done before.

Setup ROS variables on Ubuntu Linux box (to enable communication with ROS host on Sitara) then start RViz

.. code-block:: console

	export ROS_MASTER_URI=http://$SITARA_IP_ADDR:11311 (IP address of Sitara EVM, modify as needed)
	export ROS_IP=$LINUX_BOX_IP_ADDR (IP address of Ubuntu Linux box, modify as needed)
	source /opt/ros/indigo/setup.bash
	
        rosrun rviz rviz

Alternatively, in order to get Kobuki avatar on the screen, install kobuki_description on Ubuntu Linux box
and start RViz by launching view_model from kobuki_description.

.. code-block:: console

	git clone https://github.com/yujinrobot/kobuki
	cd kobuki
	cp -r kobuki_description /opt/ros/indigo/share

.. code-block:: console

	roslaunch kobuki_description view_model.launch

In RViz add point cloud from mmWave radar: 

* Click Add->PointCloud2 
* Select /mmWaveDataHdl/RScan from the Topic field dropdown for the PointCloud2 on the left hand panel
* Increase Size to 0.03, increase Decay Time to 0.25, and Select Style as "Spheres".
* In rviz, select map for Fixed Frame in Global Options.
* If Kobuki is also started, set Reference Frame (left panel) to "map".

You should see a point cloud image:

.. Image:: /images/ros_radar_rviz.png

More information can be found in  `ROS driver document <http://dev.ti.com/tirex/content/mmwave_training_1_6_1/labs/lab0006-ros-driver/lab0006_ros_driver_pjt/TI_mmWave_ROS_Driver_Setup_Guide.pdf>`__
in chapters: "Visualizating the data", "Reconfiguring the chirp profile", and "How it works"

.. rubric:: Starting GStreamer pipeline for streaming front view camer
   :name: gst-ssh-terminal-1

It is possible to start GStreamer pipeline on Sitara and receive front-camera view on Ubuntu Linux box or Windows PC using VLC.

        
.. code-block:: console

   gst-launch-1.0 -e v4l2src device=/dev/video1  io-mode=5 ! 'video/x-raw, \
   format=(string)NV12, width=(int)640, height=(int)480, framerate=(fraction)30/1' ! ducatih264enc bitrate=1000 ! queue ! h264parse config-interval=1 ! mpegtsmux  ! udpsink host=192.168.0.100 sync=false port=5000


E.g. on Windows PC (192.168.0.100), you can watch the stream using: "\Program Files (x86)\VideoLAN\VLC\vlc.exe" udp://@192.168.0.100:5000



.. figure:: /images/ros_radar_2.jpg
    :align: center
    :alt: alternate text
    :figclass: align-center

    Multiple windows on Ubuntu Linux box showing ROS RViz, front camera view and external camera view 


Sense and Avoid Demo with mmWave and Sitara
------------------------------------------------------
Processor SDK Linux provides a complete sense and avoid navigation demo which runs on AM572x EVM with mmWave sensors.
Details of this demo can be found from `Autonomous robotics reference design with Sitara processors and mmWave sensors using ROS <http://www.ti.com/tool/TIDEP-01006>`__.
