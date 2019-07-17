.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide/HeapMP_Modules 

.. |hmpCfg_Img1| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |hmpCfg_Img2| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |hmpCfg_Img3| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |hmpRun_Img1| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_heap_buf_m_p_8h.html

.. |hmpRun_Img2| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_heap_mem_m_p_8h.html

.. |hmpRun_Img3| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_heap_multi_buf_m_p_8h.html

| 

   +---------------+---------------+--------------+
   |     API Reference Links                      |
   +===============+===============+==============+
   | |hmpCfg_Img1| | |hmpRun_Img1| | HeapBuf      |
   +---------------+---------------+--------------+
   | |hmpCfg_Img2| | |hmpRun_Img2| | HeapMem      |
   +---------------+---------------+--------------+
   | |hmpCfg_Img3| | |hmpRun_Img3| | HeapMultiBuf |
   +---------------+---------------+--------------+


The ti.sdo.ipc.heaps package provides three implementations of 
the `xdc.runtime.IHeap interface <http://rtsc.eclipse.org/docs-tip/Using_xdc.runtime_Memory>`_.

- **HeapBufMP.** Fixed-size memory manager. All buffers allocated from a HeapBufMP instance are of the same size. 
  There can be multiple instances of HeapBufMP that manage different sizes. 
  The ti.sdo.ipc.heaps.HeapBufMP module is modeled after SYS/BIOS 6's HeapBuf module (ti.sysbios.heaps.HeapBuf).
- **HeapMultiBufMP.** Each instance supports up to 8 different fixed sizes of buffers. 
  When an allocation request is made, the HeapMultiBufMP instance searches the different buckets to find the smallest one that satisfies the request. 
  If that bucket is empty, the allocation fails. The ti.sdo.ipc.heaps.HeapMultiBufMP module is modeled after SYS/BIOS 6's HeapMultiBuf module (ti.sysbios.heaps.HeapMultiBuf).
- **HeapMemMP.** Variable-size memory manager. HeapMemMP manages a single buffer in shared memory from which blocks of user-specified length are allocated and freed. 
  The ti.sdo.ipc.heaps.HeapMemMP module is modeled after SYS/BIOS 6's HeapMem module (ti.sysbios.heaps.HeapMem).

The main addition to these modules is the use of shared memory and the management of multi-processor exclusion.

The SharedRegion modules, and therefore the MessageQ module and other IPC modules that use SharedRegion, use a HeapMemMP instance internally.

The following subsections use "Heap*MP" to refer to the HeapBufMP, HeapMultiBufMP, and HeapMemMP modules.

.. note::
  These Heap*MP Modules are only available on SYS/BIOS-based cores, they are not available when running an HLOS (e.g. Linux). 
  As an HLOS shared memory solution, many Linux SDKs are recommending/providing CMEM. 
  There are limitations (e.g. you cannot alloc on HLOS and free on RTOS), but these are in line with using the HLOS as a master (owning all resources) and 
  RTOS as a slave (using resources provided by the master).

.. note::
  The Heap*MP modules are not supported for Concerto F28M35x devices because Concerto does not support shared memory heaps.
  
Configuring a Heap*MP Module
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
In addition to configuring Heap*MP instances, you can set module-wide configuration properties. 
For example, the maxNameLen property lets you set the maximum length of heap names. 
The track[Max]Allocs module configuration property enables/disables tracking memory allocation statistics.

A Heap*MP instance uses a NameServer instance to manage name/value pairs.

The Heap*MP modules make the following assumptions:

- The SharedRegion module handles address translation between a virtual shared address space and the local processor's address space. 
  If the memory address spaces are identical across all processors, or if a single processor is being used, 
  no address translation is required and the SharedRegion module must be appropriately configured.
- Both processors must have the same endianness.

Creating a Heap*MP Instance
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Heaps can be created dynamically. You use the Heap*MP_create() functions to dynamically create Heap*MP instances. 
As with other IPC modules, before creating a Heap*MP instance, you initialize a Heap*MP_Params structure and set fields in 
the structure to the desired values. When you create a heap, the shared memory is initialized and the Heap*MP object is created in local memory. 
Only the actual buffers and some shared information reside in shared memory.

The following code example initializes a HeapBufMP_Params structure and sets fields in it. 
It then creates and registers an instance of the HeapBufMP module.

::
  
  /* Create the heap that will be used to allocate messages. */
  HeapBufMP_Params_init(&heapBufMPParams);
  heapBufMPParams.regionId      = 0;        /* use default region */
  heapBufMPParams.name          = "myHeap";
  heapBufMPParams.align         = 256;
  heapBufMPParams.numBlocks     = 40;
  heapBufMPParams.blockSize     = 1024;
  heapBufMPParams.gate          = NULL;     /* use system gate */
  heapHandle = HeapBufMP_create(&heapBufMPParams);
  if (heapHandle == NULL) {
      System_abort("HeapBufMP_create failed\n");
  }
   
  /* Register this heap with MessageQ */
  MessageQ_registerHeap(HeapBufMP_Handle_upCast(heapHandle), HEAPID);

The parameters for the various Heap*MP implementations vary. For example, when you create a HeapBufMP instance, 
you can configure the following parameters after initializing the HeapBufMP_Params structure:

- **regionId.** The index corresponding to the shared region from which shared memory will be allocated.
- **name.** A name of the heap instance for NameServer (optional).
- **align.** Requested alignment for each block.
- **numBlocks.** Number of fixed size blocks.
- **blockSize.** Size of the blocks in this instance.
- **gate.** A multiprocessor gate for context protection.
- **exact.** Only allocate a block if the requested size is an exact match. Default is false.

Of these parameters, the ones that are common to all three Heap*MP implementations are gate, name and regionId.

Opening a Heap*MP Instance
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Once a Heap*MP instance is created on a processor, the heap can be opened on another processor to obtain a local handle to the same shared instance. 
In order for a remote processor to obtain a handle to a Heap*MP that has been created, the remote processor needs to open it using Heap*MP_open().

The Heap*MP modules use a NameServer instance to allow a remote processor to address the local Heap*MP instance using a user-configurable string value as an identifier. 
The Heap*MP name is the sole parameter needed to identify an instance.

The heap must be created before it can be opened. An open call matches the call's version number with the creator's version number in order to ensure compatibility. 
For example:

HeapBufMP_Handle heapHandle;
...

::
   
  /* Open heap created by other processor. Loop until open. */
  do {
      status = HeapBufMP_open("myHeap", &heapHandle);
  }
  while (status < 0);
   
  /* Register this heap with MessageQ */
  MessageQ_registerHeap(HeapBufMP_Handle_upCast(heapHandle), HEAPID);

Closing a Heap*MP Instance
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Heap*MP_close() frees an opened Heap*MP instance stored in local memory. Heap*MP_close() may only be used to finalize instances that were opened with Heap*MP_open() by this thread. For example:

::
  
  HeapBufMP_close(&heapHandle);

Never call Heap*MP_close() if some other thread has already called Heap*MP_delete().

Deleting a Heap*MP Instance
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
The Heap*MP creator thread can use Heap*MP_delete() to free a Heap*MP object stored in local memory and to flag the shared memory to indicate that the heap is no longer initialized. 
Heap*MP_delete() may not be used to finalize a heap using a handle acquired using Heap*MP_open()--Heap*MP_close() should be used by such threads instead.

Allocating Memory from the Heap
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
The HeapBufMP_alloc() function obtains the first buffer off the heap's freeList.

The HeapMultiBufMP_alloc() function searches through the buckets to find the smallest size that honors the requested size. 
It obtains the first block on that bucket.

If the "exact" field in the Heap*BufMP_Params structure was true when the heap was created, the alloc only returns the block if the blockSize for a bucket is the exact size requested. 
If no exact size is found, an allocation error is returned.

The HeapMemMP_alloc() function allocates a block of memory of the requested size from the heap.

For all of these allocation functions, the cache coherency of the message is managed by the SharedRegion module that manages the shared memory region used for the heap.

Freeing Memory to the Heap
^^^^^^^^^^^^^^^^^^^^^^^^^^^^
The HeapBufMP_free() function returns an allocated buffer to its heap.

The HeapMultiBufMP_free() function searches through the buckets to determine on which bucket the block should be returned. 
This is determined by the same algorithm as the HeapMultiBufMP_alloc() function, namely the smallest blockSize that the block can fit into.

If the "exact" field in the Heap*BufMP_Params structure was true when the heap was created, and the size of the block to free does not match any bucket's blockSize, an assert is raised.

The HeapMemMP_free() function returns the allocated block of memory to its heap.

For all of these deallocation functions, cache coherency is managed by the corresponding Heap*MP module.

Querying Heap Statistics
^^^^^^^^^^^^^^^^^^^^^^^^^^^
Both heap modules support use of the xdc.runtime.Memory module's Memory_getStats() and Memory_query() functions on the heap.

In addition, the Heap*MP modules provide the Heap*MP_getStats(), Heap*MP_getExtendedStats(), and Heap*MP_isBlocking() functions to enable you to gather information about a heap.

By default, allocation tracking is often disabled in shared-heap modules for performance reasons. 
You can set the HeapBufMP.trackAllocs and HeapMultiBufMP.trackMaxAllocs configuration properties to true in order to turn on allocation tracking for their respective modules. 
Refer to the CDOC documentation for further information.

Sample Runtime Program Flow
The following diagram shows the program flow for a two-processor (or two-thread) application. 
This application creates a Heap*MP instance dynamically.

.. Image:: ../images/heapmp_bigfig.png

.. raw:: html
