.. http://processors.wiki.ti.com/index.php/ROS_Radar_demo_user_guide.html

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

.. Image:: ../images//am572x-evm.png

*  `IWR1443 Radar EVM <http://www.ti.com/tool/IWR1443BOOST#0>`__ or
   `IWR1642 Radar EVM <http://www.ti.com/tool/IWR1642BOOST#0>`__

.. Image:: ../images/radar-evm-1443.png


* USB to microUSB cable (connecting USB connector on Sitara side with microUSB connector on Radar EVM

* [optional] Kobuki mobile base (as used by Turtlebot2), http://kobuki.yujinrobot.com/

.. figure:: ../images/ros_radar_1.png
    :width: 800px
    :align: center
    :height: 450px
    :alt: alternate text
    :figclass: align-center

    Kobuki mobile base with Sitara, Radar EVMs and monitoring Ubuntu Linux box (PC desktop or laptop)

.. rubric:: Compatibility
   :name: compatibility

The ti_mmwave_rospkg ROS driver package on Sitara is tested with Processor Linux SDK 4.3
which includes meta-ros layer, indigo, (from https://github.com/bmwcarit/meta-ros).
For visualization we used ROS indigo distro on Ubuntu Linux box, preffered for compatibility reasons. 
Please follow installation instructions (for Ubuntu Linux box) at http://wiki.ros.org/indigo/Installation/Ubuntu 
For this demo, IWR EVM requires mmWave SDK firmware. If different firmware is used on Radar EVM, please follow
procedure using UniFlash tool to install `mmWave SDK <http://www.ti.com/tool/MMWAVE-SDK>`__

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

First, install RViz on Ubuntu Linux box if this has not been done before:

.. code-block:: console

        sudo sh -c 'echo "deb http://packages.ros.org/ros/ubuntu trusty main" > /etc/apt/sources.list.d/ros-latest.list'
        wget https://raw.githubusercontent.com/ros/rosdistro/master/ros.key -O - | sudo apt-key add -
        sudo apt-get update
        sudo apt-get install ros-indigo-desktop-full

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

.. Image:: ../images/ros_radar_rviz.png

More information can be found in  `ROS driver document <http://dev.ti.com/tirex/content/mmwave_training_1_6_1/labs/lab0006-ros-driver/lab0006_ros_driver_pjt/TI_mmWave_ROS_Driver_Setup_Guide.pdf>`__
in chapters: "Visualizating the data", "Reconfiguring the chirp profile", and "How it works"

.. rubric:: Starting GStreamer pipeline for streaming front view camer
   :name: gst-ssh-terminal-1

It is possible to start GStreamer pipeline on Sitara and receive front-camera view on Ubuntu Linux box or Windows PC using VLC.

        
.. code-block:: console

   gst-launch-1.0 -e v4l2src device=/dev/video1  io-mode=5 ! 'video/x-raw, \
   format=(string)NV12, width=(int)640, height=(int)480, framerate=(fraction)30/1' ! ducatih264enc bitrate=1000 ! queue ! h264parse config-interval=1 ! mpegtsmux  ! udpsink host=192.168.0.100 sync=false port=5000


E.g. on Windows PC (192.168.0.100), you can watch the stream using: "\Program Files (x86)\VideoLAN\VLC\vlc.exe" udp://@192.168.0.100:5000



.. figure:: ../images/ros_radar_2.jpg
    :align: center
    :alt: alternate text
    :figclass: align-center

    Multiple windows on Ubuntu Linux box showing ROS RViz, front camera view and external camera view 


Sense and Avoid Demo with mmWave and Sitara
------------------------------------------------------
This section shows a complete sense and avoid navigation demo which runs on AM572x EVM with mmWave sensors.
It will be available as a TI-design (TIDEP-01006) in the coming quarter.


Preparation on Ubuntu
^^^^^^^^^^^^^^^^^^^^^^^^^

In order to run the RViz for this navigation demo, rviz_plugin_covariance is needed on Ubuntu Linux box.
First, create ROS workspace on Ubunut Linux box:

.. code-block:: console

    source /opt/ros/indigo/setup.bash
    mkdir -p ~/catkin_ws/src
    cd ~/catkin_ws/
    catkin_make

Second, clone and build rviz_plugin_covariance:

.. code-block:: console

    cd ~/catkin_ws/src
    git clone https://github.com/laas/rviz_plugin_covariance
    cd ~/catkin_ws/
    catkin_make

At the end of catkin_make, there should be:

.. code-block:: console

    [100%] Built target rviz_plugin_covariance


After the plugin is successfully built, set up ROS variables on Ubuntu Linux box by adding the following two lines to  ~/.bashrc

.. code-block:: console

    source /opt/ros/indigo/setup.bash
    source ~/catkin_ws/devel/setup.bash


The last step of Ubuntu prepartation is copying the navigation demo packages from Sitara target filesystem (located under /opt/ros/indigo/share/) to Ubuntu Linux box (destitation is also /opt/ros/indigo/share/), including

.. code-block:: console

    /opt/ros/indigo/share/turtlebot_description/
    /opt/ros/indigo/share/turtlebot_bringup/
    /opt/ros/indigo/share/turtlebot_mmwave_launchers/


Run Sense and Avoid Navigation Demo
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

Follow the steps in previous sections to :ref:`reconfigure PLSDK for Python3 <reconfigure-plsdk-for-python3>` and :ref:`prepare setup.bash <modify-setup-bash>` if they have not been done earlier.
Then, close all the ROS terminal consoles for both Sitara EVM and Ubuntu Linux box.


.. rubric:: Run roscore on Sitara EVM
   :name: run-roscore-on-sitara-evm

Open the first SSH terminal on Sitara EVM and run roscore:

.. code-block:: console

        source /opt/ros/indigo/setup.bash
        roscore


.. rubric:: Launch Robot Description on Ubuntu Linux Box
   :name: launch-robot-description-on-ubunut-linux-box

Open a new terminal console on Ubuntu Linux box, export ROS_MASTER_URI and ROS_IP, and then launch robot description:

.. code-block:: console

    export ROS_MASTER_URI=http://$SITARA_IP_ADDR:11311  (IP address of Sitara EVM)
    export ROS_IP=$LINUX_BOX_IP_ADDR (IP address of Ubuntu Linux box)

    roslaunch turtlebot_bringup description.launch


.. rubric:: Turtlebot Minimal Launch on Sitara EVM
   :name: turtlebot-minimal-launch-on-sitara-evm

Open the second SSH terminal on Sitara EVM and set up mmWave sensor and Kobuki via minimal.launch of turtlebot_bringup:

.. code-block:: console

    source /opt/ros/indigo/setup.bash
    roslaunch turtlebot_bringup minimal.launch


.. rubric:: Launch Radar Navigation on Sitara EVM
   :name: launch-radar-navigation-on-sitara-evm

Open the third SSH terminal on Sitara EVM and launch radar navigation:

.. code-block:: console

    source /opt/ros/indigo/setup.bash
    roslaunch turtlebot_mmwave_launchers radar_navigation.launch

Sample log is as attached below:

.. code-block:: console

    root@am57xx-evm:~# roslaunch turtlebot_mmwave_launchers radar_navigation.launch
    ... logging to /home/root/.ros/log/556bfd2c-bd4f-11e8-ad8a-a0f6fdc25c34/roslaunch-am57xx-evm-2190.log
    Checking log directory for disk usage. This may take awhile.
    Press Ctrl-C to interrupt
    Done checking log file disk usage. Usage is <1GB.

    started roslaunch server http://192.168.0.222:35107/

    SUMMARY
    ========

    PARAMETERS
     * /fake_localization/use_map_topic: True
     * /i_filt/filter_field_name: intensity
     * /i_filt/filter_limit_max: 100
     * /i_filt/filter_limit_min: 28
     * /i_filt/filter_limit_negative: False
     * /move_base/DWAPlannerROS/acc_lim_theta: 2.0
     * /move_base/DWAPlannerROS/acc_lim_x: 2.0
     * /move_base/DWAPlannerROS/acc_lim_y: 0.0
     * /move_base/DWAPlannerROS/forward_point_distance: 0.12
     * /move_base/DWAPlannerROS/global_frame_id: odom
     * /move_base/DWAPlannerROS/goal_distance_bias: 0.01
     * /move_base/DWAPlannerROS/holonomic_robot: False
     * /move_base/DWAPlannerROS/latch_xy_goal_tolerance: True
     * /move_base/DWAPlannerROS/max_rot_vel: 2.0
     * /move_base/DWAPlannerROS/max_scaling_factor: 0.20000000000000001
     * /move_base/DWAPlannerROS/max_trans_vel: 0.5
     * /move_base/DWAPlannerROS/max_vel_x: 0.20000000000000001
     * /move_base/DWAPlannerROS/max_vel_y: 0.0
     * /move_base/DWAPlannerROS/min_rot_vel: 0.40000000000000002
     * /move_base/DWAPlannerROS/min_trans_vel: 0.10000000000000001
     * /move_base/DWAPlannerROS/min_vel_x: 0.0
     * /move_base/DWAPlannerROS/min_vel_y: 0.0
     * /move_base/DWAPlannerROS/occdist_scale: 0.01
     * /move_base/DWAPlannerROS/oscillation_reset_angle: 0.0
     * /move_base/DWAPlannerROS/oscillation_reset_dist: 0.0
     * /move_base/DWAPlannerROS/path_distance_bias: 32.0
     * /move_base/DWAPlannerROS/publish_cost_grid_pc: True
     * /move_base/DWAPlannerROS/publish_traj_pc: True
     * /move_base/DWAPlannerROS/rot_stopped_vel: 0.40000000000000002
     * /move_base/DWAPlannerROS/scaling_speed: 0.25
     * /move_base/DWAPlannerROS/sim_time: 1.7
     * /move_base/DWAPlannerROS/stop_time_buffer: 0.20000000000000001
     * /move_base/DWAPlannerROS/trans_stopped_vel: 0.050000000000000003
     * /move_base/DWAPlannerROS/vtheta_samples: 20
     * /move_base/DWAPlannerROS/vx_samples: 3
     * /move_base/DWAPlannerROS/vy_samples: 0
     * /move_base/DWAPlannerROS/xy_goal_tolerance: 0.17000000000000001
     * /move_base/DWAPlannerROS/yaw_goal_tolerance: 0.40000000000000002
     * /move_base/GlobalPlanner/allow_unknown: True
     * /move_base/GlobalPlanner/cost_factor: 3.0
     * /move_base/GlobalPlanner/default_tolerance: 0.0
     * /move_base/GlobalPlanner/lethal_cost: 253
     * /move_base/GlobalPlanner/neutral_cost: 66
     * /move_base/GlobalPlanner/old_navfn_behavior: False
     * /move_base/GlobalPlanner/planner_costmap_publish_frequency: 0.0
     * /move_base/GlobalPlanner/planner_window_x: 0.0
     * /move_base/GlobalPlanner/planner_window_y: 0.0
     * /move_base/GlobalPlanner/publish_potential: True
     * /move_base/GlobalPlanner/publish_scale: 100
     * /move_base/GlobalPlanner/use_dijkstra: True
     * /move_base/GlobalPlanner/use_grid_path: False
     * /move_base/GlobalPlanner/use_quadratic: True
     * /move_base/NavfnROS/allow_unknown: False
     * /move_base/NavfnROS/default_tolerance: 0.0
     * /move_base/NavfnROS/planner_window_x: 0.0
     * /move_base/NavfnROS/planner_window_y: 0.0
     * /move_base/NavfnROS/visualize_potential: False
     * /move_base/aggressive_reset/layer_names: ['obstacle_layer']
     * /move_base/base_global_planner: navfn/NavfnROS
     * /move_base/base_local_planner: dwa_local_planner...
     * /move_base/conservative_reset/layer_names: ['obstacle_layer']
     * /move_base/controller_frequency: 5.0
     * /move_base/controller_patience: 3.0
     * /move_base/global_costmap/global_frame: map
     * /move_base/global_costmap/height: 10.0
     * /move_base/global_costmap/inflation_layer/cost_scaling_factor: 9.8000000000000007
     * /move_base/global_costmap/inflation_layer/enabled: True
     * /move_base/global_costmap/inflation_layer/inflation_radius: 0.37
     * /move_base/global_costmap/map_type: voxel
     * /move_base/global_costmap/max_obstacle_height: 1
     * /move_base/global_costmap/obstacle_layer/bump/clearing: False
     * /move_base/global_costmap/obstacle_layer/bump/data_type: PointCloud2
     * /move_base/global_costmap/obstacle_layer/bump/marking: True
     * /move_base/global_costmap/obstacle_layer/bump/max_obstacle_height: 0.14999999999999999
     * /move_base/global_costmap/obstacle_layer/bump/min_obstacle_height: 0.0
     * /move_base/global_costmap/obstacle_layer/bump/topic: mobile_base/senso...
     * /move_base/global_costmap/obstacle_layer/combination_method: 1
     * /move_base/global_costmap/obstacle_layer/enabled: True
     * /move_base/global_costmap/obstacle_layer/mark_threshold: 2
     * /move_base/global_costmap/obstacle_layer/max_obstacle_height: 1
     * /move_base/global_costmap/obstacle_layer/observation_sources: scan bump
     * /move_base/global_costmap/obstacle_layer/obstacle_range: 1.0
     * /move_base/global_costmap/obstacle_layer/origin_z: 0.0
     * /move_base/global_costmap/obstacle_layer/publish_voxel_map: True
     * /move_base/global_costmap/obstacle_layer/raytrace_range: 3.0
     * /move_base/global_costmap/obstacle_layer/scan/clearing: False
     * /move_base/global_costmap/obstacle_layer/scan/data_type: PointCloud2
     * /move_base/global_costmap/obstacle_layer/scan/marking: True
     * /move_base/global_costmap/obstacle_layer/scan/max_obstacle_height: 1
     * /move_base/global_costmap/obstacle_layer/scan/min_obstacle_height: 0.0
     * /move_base/global_costmap/obstacle_layer/scan/topic: xyzi_filt_out
     * /move_base/global_costmap/obstacle_layer/track_unknown_space: True
     * /move_base/global_costmap/obstacle_layer/unknown_threshold: 15
     * /move_base/global_costmap/obstacle_layer/z_resolution: 0.014999999999999999
     * /move_base/global_costmap/obstacle_layer/z_voxels: 16
     * /move_base/global_costmap/plugins: [{'name': 'static...
     * /move_base/global_costmap/publish_frequency: 5
     * /move_base/global_costmap/resolution: 0.02
     * /move_base/global_costmap/robot_base_frame: base_footprint
     * /move_base/global_costmap/robot_radius: 0.17999999999999999
     * /move_base/global_costmap/rolling_window: True
     * /move_base/global_costmap/static_layer/enabled: True
     * /move_base/global_costmap/static_map: False
     * /move_base/global_costmap/transform_tolerance: 10
     * /move_base/global_costmap/update_frequency: 7
     * /move_base/global_costmap/width: 10.0
     * /move_base/local_costmap/global_frame: odom
     * /move_base/local_costmap/height: 4.0
     * /move_base/local_costmap/inflation_layer/cost_scaling_factor: 8.0
     * /move_base/local_costmap/inflation_layer/enabled: True
     * /move_base/local_costmap/inflation_layer/inflation_radius: 0.22
     * /move_base/local_costmap/map_type: voxel
     * /move_base/local_costmap/max_obstacle_height: 1
     * /move_base/local_costmap/obstacle_layer/bump/clearing: False
     * /move_base/local_costmap/obstacle_layer/bump/data_type: PointCloud2
     * /move_base/local_costmap/obstacle_layer/bump/marking: True
     * /move_base/local_costmap/obstacle_layer/bump/max_obstacle_height: 0.14999999999999999
     * /move_base/local_costmap/obstacle_layer/bump/min_obstacle_height: 0.0
     * /move_base/local_costmap/obstacle_layer/bump/topic: mobile_base/senso...
     * /move_base/local_costmap/obstacle_layer/combination_method: 1
     * /move_base/local_costmap/obstacle_layer/enabled: True
     * /move_base/local_costmap/obstacle_layer/mark_threshold: 2
     * /move_base/local_costmap/obstacle_layer/max_obstacle_height: 1
     * /move_base/local_costmap/obstacle_layer/observation_sources: scan bump
     * /move_base/local_costmap/obstacle_layer/obstacle_range: 1.0
     * /move_base/local_costmap/obstacle_layer/origin_z: 0.0
     * /move_base/local_costmap/obstacle_layer/publish_voxel_map: True
     * /move_base/local_costmap/obstacle_layer/raytrace_range: 3.0
     * /move_base/local_costmap/obstacle_layer/scan/clearing: False
     * /move_base/local_costmap/obstacle_layer/scan/data_type: PointCloud2
     * /move_base/local_costmap/obstacle_layer/scan/marking: True
     * /move_base/local_costmap/obstacle_layer/scan/max_obstacle_height: 1
     * /move_base/local_costmap/obstacle_layer/scan/min_obstacle_height: 0.0
     * /move_base/local_costmap/obstacle_layer/scan/topic: xyzi_filt_out
     * /move_base/local_costmap/obstacle_layer/track_unknown_space: True
     * /move_base/local_costmap/obstacle_layer/unknown_threshold: 15
     * /move_base/local_costmap/obstacle_layer/z_resolution: 0.014999999999999999
     * /move_base/local_costmap/obstacle_layer/z_voxels: 16
     * /move_base/local_costmap/plugins: [{'name': 'static...
     * /move_base/local_costmap/publish_frequency: 10
     * /move_base/local_costmap/resolution: 0.02
     * /move_base/local_costmap/robot_base_frame: base_footprint
     * /move_base/local_costmap/robot_radius: 0.17999999999999999
     * /move_base/local_costmap/rolling_window: True
     * /move_base/local_costmap/static_layer/enabled: True
     * /move_base/local_costmap/static_map: False
     * /move_base/local_costmap/transform_tolerance: 1
     * /move_base/local_costmap/update_frequency: 12
     * /move_base/local_costmap/width: 4.0
     * /move_base/oscillation_distance: 0.20000000000000001
     * /move_base/oscillation_timeout: 10.0
     * /move_base/planner_frequency: 1.0
     * /move_base/planner_patience: 5.0
     * /move_base/recovery_behavior_enabled: True
     * /move_base/recovery_behaviors: [{'name': 'cleari...
     * /move_base/shutdown_costmaps: False
     * /navigation_velocity_smoother/accel_lim_v: 1.0
     * /navigation_velocity_smoother/accel_lim_w: 2.0
     * /navigation_velocity_smoother/decel_factor: 1.5
     * /navigation_velocity_smoother/frequency: 20.0
     * /navigation_velocity_smoother/robot_feedback: 2
     * /navigation_velocity_smoother/speed_lim_v: 0.80000000000000004
     * /navigation_velocity_smoother/speed_lim_w: 5.4000000000000004
     * /rosdistro: b'<unknown>\n'
     * /rosversion: b'1.11.21\n'
     * /x_filt/filter_field_name: x
     * /x_filt/filter_limit_max: 4
     * /x_filt/filter_limit_min: 0.10000000000000001
     * /x_filt/filter_limit_negative: False
     * /y_filt/filter_field_name: y
     * /y_filt/filter_limit_max: 3
     * /y_filt/filter_limit_min: -3
     * /y_filt/filter_limit_negative: False
     * /z_filt/filter_field_name: z
     * /z_filt/filter_limit_max: 0.10000000000000001
     * /z_filt/filter_limit_min: -0.40000000000000002
     * /z_filt/filter_limit_negative: False

    NODES
     /
        fake_localization (fake_localization/fake_localization)
        i_filt (nodelet/nodelet)
        kobuki_safety_controller (nodelet/nodelet)
        move_base (move_base/move_base)
        navigation_velocity_smoother (nodelet/nodelet)
        octomap_server (octomap_server/octomap_server_node)
        pcl_manager (nodelet/nodelet)
        voxel_grid_2_point_cloud (costmap_2d/costmap_2d_cloud)
        x_filt (nodelet/nodelet)
        y_filt (nodelet/nodelet)
        z_filt (nodelet/nodelet)

    ROS_MASTER_URI=http://192.168.0.222:11311
    
    core service [/rosout] found
    process[pcl_manager-1]: started with pid [2208]
    process[x_filt-2]: started with pid [2209]
    process[y_filt-3]: started with pid [2210]
    process[z_filt-4]: started with pid [2212]
    process[i_filt-5]: started with pid [2218]
    [ INFO] [1537502385.764232051]: Loading nodelet /x_filt of type pcl/PassThrough to manager pcl_manager with the following remappings:
    [ INFO] [1537502385.764535262]: /x_filt/input -> /mmWaveDataHdl/RScan
    [ INFO] [1537502385.764637905]: /x_filt/output -> /x_filt_out
    process[octomap_server-6]: started with pid [2222]
    [ INFO] [1537502385.807461531]: waitForService: Service [/pcl_manager/load_nodelet] has not been advertised, waiting...
    process[fake_localization-7]: started with pid [2234]
    [ INFO] [1537502385.876881320]: Loading nodelet /y_filt of type pcl/PassThrough to manager pcl_manager with the following remappings:
    [ INFO] [1537502385.877401203]: /y_filt/input -> /x_filt_out
    [ INFO] [1537502385.877811123]: /y_filt/output -> /xy_filt_out
    process[navigation_velocity_smoother-8]: started with pid [2245]
    process[kobuki_safety_controller-9]: started with pid [2254]
    [ INFO] [1537502386.021405773]: waitForService: Service [/pcl_manager/load_nodelet] has not been advertised, waiting...
    process[move_base-10]: started with pid [2260]
    [ INFO] [1537502386.050920176]: Loading nodelet /z_filt of type pcl/PassThrough to manager pcl_manager with the following remappings:
    [ INFO] [1537502386.051338880]: /z_filt/input -> /xy_filt_out
    [ INFO] [1537502386.051423954]: /z_filt/output -> /xyz_filt_out
    process[voxel_grid_2_point_cloud-11]: started with pid [2275]
    [ INFO] [1537502386.110001522]: Loading nodelet /i_filt of type pcl/PassThrough to manager pcl_manager with the following remappings:
    [ INFO] [1537502386.110382000]: /i_filt/input -> /xyz_filt_out
    [ INFO] [1537502386.110469189]: /i_filt/output -> /xyzi_filt_out
    [ INFO] [1537502386.210300162]: waitForService: Service [/pcl_manager/load_nodelet] has not been advertised, waiting...
    [ INFO] [1537502386.330222095]: waitForService: Service [/pcl_manager/load_nodelet] has not been advertised, waiting...
    [ INFO] [1537502386.339760543]: Initializing nodelet with 2 worker threads.
    [ INFO] [1537502386.370224431]: waitForService: Service [/pcl_manager/load_nodelet] is now available.
    [ INFO] [1537502386.386837903]: waitForService: Service [/pcl_manager/load_nodelet] is now available.
    [ INFO] [1537502386.396840601]: waitForService: Service [/pcl_manager/load_nodelet] is now available.
    [ INFO] [1537502386.414131417]: waitForService: Service [/pcl_manager/load_nodelet] is now available.
    [ INFO] [1537502388.467073886]: Using plugin "static_layer"
    [ INFO] [1537502388.552441027]: Requesting the map...
    [ INFO] [1537502389.009091093]: Resizing static layer to 38 X 29 at 0.050000 m/pix
    [ INFO] [1537502389.109529463]: Received a 38 X 29 map at 0.050000 m/pix
    [ INFO] [1537502389.152919170]: Using plugin "obstacle_layer"
    [ INFO] [1537502389.184083012]:     Subscribed to Topics: scan bump
    [ INFO] [1537502389.743721736]: Using plugin "inflation_layer"
    [ INFO] [1537502390.205726137]: Using plugin "static_layer"
    [ INFO] [1537502390.229255871]: Requesting the map...
    [ INFO] [1537502390.245325223]: Resizing static layer to 38 X 29 at 0.050000 m/pix
    [ INFO] [1537502390.343836481]: Received a 38 X 29 map at 0.050000 m/pix
    [ INFO] [1537502390.370283641]: Using plugin "obstacle_layer"
    [ INFO] [1537502390.385764465]:     Subscribed to Topics: scan bump
    [ INFO] [1537502390.651627515]: Using plugin "inflation_layer"
    [ INFO] [1537502390.942044935]: Created local_planner dwa_local_planner/DWAPlannerROS
    [ INFO] [1537502390.967666237]: Sim period is set to 0.20
    [ INFO] [1537502392.012863983]: odom received!

.. rubric:: Launch RViz for Sense and Avoid Navigation on Ubuntu Linux Box
   :name: launch-rviz-for-sense-and-avoid-navigation-on-ubuntu-linux-box

Open a new terminal console on Ubunut Linux box, export ROS_MASTER_URI and ROS_IP, and then start Rviz with navigation_visualization_2.rviz:

.. code-block:: console

    export ROS_MASTER_URI=http://$SITARA_IP_ADDR:11311  (IP address of Sitara EVM)
    export ROS_IP=$LINUX_BOX_IP_ADDR (IP address of Ubuntu Linux box)

    rosrun rviz rviz -d /opt/ros/indigo/share/turtlebot_mmwave_launchers/launch/navigation_visualization_2.rviz 

.. rubric:: Set Initial Position and Goal for Navigation on Sitara EVM
   :name: set-initial-position-and-goal-for-navigation-on-sitara-evm

The demo uses a pre-defined map file of size 4 feet by 6 feet, with three locations (a, b, and c) on each side. 

Open the fourth SSH terminal on Sitara EVM, and set the initial posistion with side (left or right) and position (a, b, or c), 
and then set the goal position (a, b, or c) on the other side, by running the scripts below:

.. code-block:: console

   source /opt/ros/indigo/setup.bash
   cd /opt/ros/indigo/share/turtlebot_mmwave_launchers/scripts/
   ./start_nav.sh
