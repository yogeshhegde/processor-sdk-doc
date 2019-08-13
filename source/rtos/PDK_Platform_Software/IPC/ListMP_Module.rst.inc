.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide/ListMP_Module 

.. |lmpCfg_Img1| Image:: ../images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |lmpRun_Img1| Image:: ../images/Book_run.png
                 :target: http://downloads.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/doxygen/html/_list_m_p_8h.html

| 

   +---------------+---------------+
   |     API Reference Links       |
   +===============+===============+
   | |lmpCfg_Img1| | |lmpRun_Img1| |
   +---------------+---------------+

The ti.sdo.ipc.ListMP module is a linked-list based module designed to be used in a multi-processor environment. 
It is designed to provide a means of communication between different processors.
ListMP uses shared memory to provide a way for multiple processors to share, pass, or store data buffers, messages, or state information. 
ListMP is a low-level module used by several other IPC modules, including MessageQ, HeapBufMP, and transports, as a building block for 
their instance and state structures.

A common challenge that occurs in a multi-processor environment is preventing concurrent data access in shared memory between different processors. 
ListMP uses a multi-processor gate to prevent multiple processors from simultaneously accessing the same linked-list. 
All ListMP operations are atomic across processors.

You create a ListMP instance dynamically as follows:

# Initialize a ListMP_Params structure by calling ListMP_Params_init().
# Specify the name, regionId, and other parameters in the ListMP_Params structure.
# Call ListMP_create().

ListMP uses a ti.sdo.utils.NameServer instance to store the instance information. 
The ListMP name supplied must be unique for all ListMP instances in the system.

::
  
  ListMP_Params params;
  GateMP_Handle gateHandle;
  ListMP_Handle handle1;
   
  /* If gateHandle is NULL, the default remote gate will be
     automatically chosen by ListMP */
  gateHandle = GateMP_getDefaultRemote();
  ListMP_Params_init(&params);
  params.gate = gateHandle;
  params.name = "myListMP";
  params.regionId = 1;
  handle1 = ListMP_create(&params, NULL);

Once created, another processor or thread can open the ListMP instance by calling ListMP_open().

::
  
  while (ListMP_open("myListMP", &handle1, NULL) < 0) {
      ; 
  }

ListMP uses SharedRegion pointers (see SharedRegion Module), which are portable across processors, to translate addresses for shared memory. 
The processor that creates the ListMP instance must specify the shared memory in terms of its local address space. 
This shared memory must have been defined in the SharedRegion module by the application.
The ListMP module has the following constraints:

- ListMP elements to be added/removed from the linked-list must be stored in a shared memory region.
- The linked list must be on a worst-case cache line boundary for all the processors sharing the list.
- ListMP_open() should be called only when global interrupts are enabled.

A list item must have a field of type ListMP_Elem as its first field. For example, the following structure could be used for list elements:

::
  
  typedef struct Tester {
    ListMP_Elem elem;
    Int         scratch[30];
    Int         flag;
  } Tester;

Besides creating, opening, and deleting a list instance, the ListMP module provides functions for the following common list operations:

- **ListMP_empty().** Test for an empty ListMP.
- **ListMP_getHead().** Get the element from the front of the ListMP.
- **ListMP_getTail().** Get the element from the end of the ListMP.
- **ListMP_insert().** Insert element into a ListMP at the current location.
- **ListMP_next().** Return the next element in the ListMP (non-atomic).
- **ListMP_prev().** Return previous element in the ListMP (non-atomic).
- **ListMP_putHead().** Put an element at the head of the ListMP.
- **ListMP_putTail().** Put an element at the end of the ListMP.
- **ListMP_remove().** Remove the current element from the middle of the ListMP.

This example prints a "flag" field from the list elements in a ListMP instance in order:

::
  
  System_printf("On the List: ");
  testElem = NULL;
  while ((testElem = ListMP_next(handle, (ListMP_Elem *)testElem)) != NULL) {
      System_printf("%d ", testElem->flag);
  }

This example prints the same items in reverse order:

::
  
  System_printf("in reverse: ");
  elem = NULL;
  while ((elem = ListMP_prev(handle, elem)) != NULL) {
      System_printf("%d ", ((Tester  *)elem)->flag);
  }

This example determines if a ListMP instance is empty:

::
  
  if (ListMP_empty(handle1) == TRUE) {
    System_printf("Yes, handle1 is empty\n");
  }

This example places a sequence of even numbers in a ListMP instance:

::
  
  /* Add 0, 2, 4, 6, 8 */
  for (i = 0; i < COUNT; i = i + 2) {
      ListMP_putTail(handle1, (ListMP_Elem *)&(buf[i]));
  }

The instance state information contains a pointer to the head of the linked-list, which is stored in shared memory. 
Other attributes of the instance stored in shared memory include the version, status, and the size of the shared address.
Other processors can obtain a handle to the linked list by calling ListMP_open().

The following figure shows local memory and shared memory for processors Proc 0 and Proc 1, in which Proc 0 calls ListMP_create() and Proc 1 calls ListMP_open().

.. Image:: ../images/IpcUG_ipc_2_4_1.png


The cache alignment used by the list is taken from the SharedRegion on a per-region basis. The alignment must be the same across all processors and should be the worst-case cache line boundary.


