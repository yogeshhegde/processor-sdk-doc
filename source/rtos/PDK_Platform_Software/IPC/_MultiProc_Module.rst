.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide/MultiProc_Module

.. |mpmCfg_Img1| Image:: /images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |mpmCfg_Img2| Image:: /images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html


.. |mpmRun_Img1| Image:: /images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_multi_proc_8h.html

.. |mpmRun_Img2| Image:: /images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_multi_proc_8h.html

|

   +---------------+---------------+
   |     API Reference Links       |
   +===============+===============+
   | |mpmCfg_Img1| | |mpmRun_Img1| |
   +---------------+---------------+

Introduction
^^^^^^^^^^^^^^

Many IPC modules require the ability to uniquely specify and identify processors in a
multi-processor environment. The MultiProc module centralizes processor ID management into one module.
Most multi-processor IPC applications require that you configure this module using the MultiProc.setConfig()
function in the *.cfg script. The setConfig() function tells the MultiProc module:

- The specific processor for which this application is being built.
- The processors in this cluster. A "cluster" is a set of processors within

a system that share some memory and for which notification between those processors is needed.

Most systems contain a single cluster. For systems with multiple clusters, you also need to configure the numProcessors and baseIdOfCluster properties.

Each processor reference by the MultiProc module can be uniquely identified by either its name string or an integer ranging from 0 to MultiProc.maxProcessors - 1.

The following XDCtools configuration statements set up a MultiProc array.
At runtime, the "DSP" processor running this configuration gets assigned an ID value of 2.
The other processors in the system are "VIDEO" with a processor ID of 0 and "DSS" with a
processor ID of 1.

::

  /* DSP will get assigned processor id 2. */
  var MultiProc = xdc.useModule('ti.sdo.utils.MultiProc');
  MultiProc.setConfig("DSP", ["VIDEO", "DSS", "DSP"]);

|

The ID is a software-only setting. It does not correlate to hardware core IDs or any other type of hardware identification. For devices with more than one core, each core must have its own unique processor ID. The ID is also independent of any OS setting.
The processor ID is not always known at configuration time. It might need to be determined at initialization time via a GPIO pin, flash setting, or some other method. You can call the MultiProc_setLocalId() API (with the restriction that it must be called before module startup) to set the processor ID. However, other modules that use MultiProc need to know that the static ID will be changed during initialization. Setting the local name to NULL in the MultiProc.setConfig statement in the configuration indicates that the MultiProc_setLocalId() API will be used at runtime. Other modules that use MultiProc should act accordingly by deferring processing until the actual ID is known.

For example, the following fragment of configuration code requires that the MultiProc_setLocalId() API be run during startup to fill in the NULL processor name.

::

  /* Specify startup function */
  var Startup = xdc.useModule('xdc.runtime.Startup');
  Startup.firstFxns.$add('&setMyId');

  /* Specify MultiProc config; current processor unknown */
  var MultiProc = xdc.useModule('ti.sdo.utils.MultiProc');
  MultiProc.setConfig(null, ["CORE0", "CORE1", "CORE2"]);

|

Then, the application code could contain the following setMyID() function to be run at startup:

::

  Void setMyId()
  {
      UInt16 procId;
      Int    status;

      //
      // Board specific determination of processor id.
      // Example: GPIO_READ reads register of GPIO pin 5
      //
      if (GPIO_READ(5) == 0) {
            procId = 0;
      }
      else {
         procId = 1;
      }

      MultiProc_setLocalId(procId);
  }

|

Your application can query the MultiProc table using various runtime APIs.
At runtime, the MultiProc_getId() call returns the MultiProc ID for any processor name. At config-time, the MultiProc.getIdMeta() call returns the same value. For example:

::

  core1ProcId = MultiProc_getId("CORE1");

|

MultiProc_self() returns the processor ID of the processor running the API. For example:

::

  System_printf("My MultiProc id = %d\n", MultiProc_self());

|

MultiProc_getBaseIdOfCluster() returns the MultiProc ID of the base processor in the cluster to which this processor belongs.
The MultiProc_getName() API returns that processor name if given the MultiProc ID. For example:

::

  core0Name = MultiProc_getName(0);

|

MultiProc_getNumProcessors() evaluates to the total number of processors.

::

  System_printf("Number of processors in the system = %d\n",
                MultiProc_getNumProcessors() );

|

MultiProc_getBaseIdOfCluster() returns the MultiProc ID of the base processor in the cluster to which this processor belongs.
The MultiProc_getName() API returns that processor name if given the MultiProc ID. For example:

::

  core0Name = MultiProc_getName(0);

|

MultiProc_getNumProcessors() evaluates to the total number of processors.

::

  System_printf("Number of processors in the system = %d\n",
                MultiProc_getNumProcessors() );

|

MultiProc_getNumProcsInCluster() returns the number of processors in the cluster to which this processor belongs.

Configuring Clusters With the MultiProc Module
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

A "cluster" is a set of processors within a system that share some memory and for which notification between those processors is needed. If your system has multiple clusters, you need to configure the MultiProc module's numProcessors and baseIdOfCluster properties in addition to calling the MultiProc.setConfig() function.

Notifications are not supported between different clusters.

For example, in a system with two 'C6678 devices that each use eight homogeneous cores, you could configure the first 'C6678 device as follows:

::

  var MultiProc = xdc.useModule('ti.sdo.utils.MultiProc');
  MultiProc.baseIdOfCluster = 0;
  MultiProc.numProcessors = 16;
  MultiProc.setConfig(null, ["CORE0", "CORE1", "CORE2",
           "CORE3", "CORE4", "CORE5", "CORE6", "CORE7"]);

|

You could configure the second 'C6678 device as follows:

::

  var MultiProc = xdc.useModule('ti.sdo.utils.MultiProc');
  MultiProc.baseIdOfCluster = 8;
  MultiProc.numProcessors = 16;
  MultiProc.setConfig(null, ["CORE0", "CORE1", "CORE2",
           "CORE3", "CORE4", "CORE5", "CORE6", "CORE7"]);

|

Notice that the MultiProc.numProcessors property specifies the total number of processors in the system, while the length of the array passed to setConfig() specifies the number of processors in the cluster. (If you are not using multiple clusters, the numProcessors property is configured automatically.)
The MultiProc.baseIdOfCluster property is set to the MultiProc ID number you want to use for the first processor in the array for this cluster. For example, if there are 8 processors in a cluster, the baseIdOfCluster property should be 0 for the first cluster and 8 for the second cluster.

|mpmCfg_Img2| The latest version of the MultiProc module configuration documentation
is available in `MultiProc page <http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/index.html#ti/sdo/utils/MultiProc.html>`_


Creating Connections with MultiProc
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
The Ipc_start() and Ipc_attach() APIs can only be used to attach and synchronizes with processors in the same cluster.

To create a connection between cores in different clusters, you must manually create a connection using the MessageQ and ti.sdo.ipc.NameServerMessageQ modules. The NameServerMessageQ module supports NameServer requests between different clusters by using MessageQ, which in turns uses the MessageQ transport to send a NameServer request.

You can control the timeout period for the NameServerMessageQ module by configuring its timeoutInMicroSecs parameter, which defaults to 1 second. If a response is not received within the timeout period, the NameServer request returns a failure status. The NameServerRemoteNotify module also has a timeoutInMicroSecs parameter that you can configure; it defaults to wait forever.

Creating a connection between cores in different clusters allows you to call MessageQ_open() even for a core on a different cluster. Note that these calls must occur after the MessageQ heap has been registered, because they allocate memory from the heap.

Once the connection has been created, MessageQ can be used between different processors on different clusters just as it is used between different processors in the same cluster.

|mpmRun_Img2| The latest version of the MultiProc module run-time API documentation is
available in `MultiProc run-time API  <http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_multi_proc_8h.html>`_


Example
^^^^^^^^^
The following example function creates a NameServerMessageQ and TransportXXX to communicate remotely with a processor in a different cluster. The "remoteProcId" would be specified to be the MultiProc ID of the processor in the system. "TransportXXX" must be a copy-based transport that does not require any shared memory. You would need to create such a transport, because IPC does not provide one.

::

  Void myRemoteCreateFunction(Uint16 remoteProcId)
  {
      NameServerMessageQ_Params  nsParams;
      NameServerMessageQ_Handle  nsHandle;
      TransportXXX_Handle        tranHandle;
      TransportXXX_Params        tranParams;
      Error_Block eb;

      Error_init(&eb);

      /*
       *  Note: You must register a MessageQ heap prior to
       *  calling NameServerMessageQ_create().
       */

      /* init nsParams */
      NameServerMessageQ_Params_init(&nsParams);

      /* create driver to remote processor */
      nsHandle = NameServerMessageQ_create(
          remoteProcId, /* MultiProc ID of proc on 2nd cluster */
          &nsParams,
          &eb);
        if (nsHandle == NULL) {
          SYS_abort("NameServerMessageQ_create() failed");
      }

        /* initialize the transport parameters */
      TransportXXX_Params_init(&tranParams);

      tranHandle = TransportXXX_create(
         remoteProcId, /* MultiProc ID of proc on 2nd cluster */
         &tranParams,
         &eb);
      if (tranHandle == NULL) {
          SYS_abort("TransportXXX_create() failed");
      }
  }

|


