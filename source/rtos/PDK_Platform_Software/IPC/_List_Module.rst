.. http://processors.wiki.ti.com/index.php/IPC_Users_Guide/List_Module

.. |lisCfg_Img1| Image:: /images/Book_cfg.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/ipc/latest/docs/cdoc/indexChrome.html

.. |lisRun_Img1| Image:: /images/Book_run.png
                 :target: http://software-dl.ti.com/dsps/dsps_public_sw/sdo_sb/targetcontent/syslink/latest/docs/html/_list_8h.html

|

   +---------------+---------------+
   |     API Reference Links       |
   +===============+===============+
   | |lisCfg_Img1| | |lisRun_Img1| |
   +---------------+---------------+

The ti.sdo.utils.List module provides support for creating lists of objects.
A List is implemented as a doubly-linked list, so that elements can be inserted or removed
from anywhere in the list. Lists do not have a maximum size.


Basic FIFO Operation of a List
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
To add a structure to a List, its first field needs to be of type List_Elem.
The following example shows a structure that can be added to a List.
A List has a "head", which is the front of the list.
List_put() adds elements to the back of the list, and List_get() removes and returns
the element at the head of the list. Together, these functions support a FIFO queue.

**Run-time example:** The following example demonstrates the basic List operations--List_put() and List_get().

::

  /* This structure can be added to a List because the first
   * field is a List_Elem. Declared globally. */
  typedef struct Rec {
      List_Elem elem;
      Int data;
  } Rec;

  ...

  List_Handle myList;              /* in main() */
  Rec r1, r2;
  Rec* rp;

  r1.data = 100;
  r2.data = 200;

  /* No parameters are needed to create a List. */
  myList = List_create(NULL, NULL);

  /* Add r1 and r2 to the back of myList. */
  List_put(myList, &(r1.elem));
  List_put(myList, &(r2.elem));

  /* get the records and print their data */
  while ((rp = List_get(myList)) != NULL) {
      System_printf("rec: %d\n", rp->data);
  }

The example prints the following:

::

  rec: 100
  rec: 200

|

Iterating Over a List
^^^^^^^^^^^^^^^^^^^^^^^^
The List module also provides several APIs for looping over a List.

List_next() with NULL returns the element at the front of the List (without removing it).
List_next() with an elem returns the next elem. NULL is returned when the end of the List is reached.

Similarly, List_prev() with NULL returns the tail. List_prev() with an elem returns the previous elem.
NULL is returned when the beginning of the List is reached.

**Run-time example:** The following example demonstrates one way to iterate over a List
once from beginning to end. In this example, "myList" is a List_Handle.

::

  List_Elem   *elem = NULL;
  Rec* rp;

  ...

  /* To start the search at the beginning of the List */
  rp = NULL;

  /* Begin protection against modification of the List */
  key = Gate_enterSystem();

  while ((elem = List_next(myList, elem)) != NULL) {
       System_printf("rec: %d\n", rp->data);
  }
  /* End protection against modification of the List */
  Gate_leaveSystem(key);

|

Inserting and Removing List Elements
^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
Elements can also be inserted or removed from anywhere in the middle of a List using List_insert() and List_remove().
List_insert() inserts an element in front of the specified element.
Use List_putHead() to place an element at the front of the List and List_put() to
place an element at the end of the List.

List_remove() removes the specified element from whatever List it is in.

Note that List does not provide any APIs for inserting or removing elements at a given index in the List.

**Run-time example:** The following example demonstrates List_insert() and List_remove():

::

  /* Insert r2 in front of r1 in the List. */
  List_insert(myList, &(r1.elem), &(r2.elem));

  /* Remove r1 from the List. */
  List_remove(myList, &(r1.elem));

|

**Run-time example:** The following example treats the List as a LIFO stack using List_putHead() and List_get():

::

  List_Elem  elem[NUMELEM];
  List_Elem *tmpElem;

  // push onto the top (i.e. head)
  for (i = 0; i < NUMELEM; i++) {
      List_putHead(listHandle, &(elem[i]));
  }

  // remove the buffers in FIFO order.
  while((tmpElem = List_get(listHandle)) != NULL) {
      // process tmpElem
  }

|

Atomic List Operations
^^^^^^^^^^^^^^^^^^^^^^^^
Lists are commonly shared across multiple threads in the system, which might lead to concurrent
modifications of the List by different threads, which would corrupt the List.
List provides several "atomic" APIs that disable interrupts before operating on the List.
These APIs are List_get() List_put(), List_putHead(), and List_empty().

An atomic API completes in core functionality without being interrupted.
Therefore, atomic APIs are thread-safe. An example is List_put().
Multiple threads can call this API at the same time.
The threads do not have to manage the synchronization.

Other APIs--List_prev(), List_next(), List_insert(), and List_remove()--should be protected by the application.


