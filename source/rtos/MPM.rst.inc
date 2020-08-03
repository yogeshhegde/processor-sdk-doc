.. http://processors.wiki.ti.com/index.php/MultiprocMgr

.. rubric:: Introduction
   :name: introduction

| The Multiple Proc Manager (MPM) Package distributed with Processor SDK
  RTOS installer has multiple software modules.
| Broadly the modules can be grouped into two categories:

-  Multi Proc Manager Linux module
-  Modules that facilitate Interprocess communication between the
   multiple cores.

.. rubric:: Multi Proc Manager Linux module
   :name: multi-proc-manager-linux-module

The Multi Proc Manager Linux module is used to load and run DSP images
from ARM Linux user space. The download and run operations can be
exercised by using user space API calls. MPM also provides a MPM Client
Application which can be used to load and run DSP through command line.

.. rubric:: Interprocessor Communication related packages
   :name: interprocessor-communication-related-packages

The Multi Proc Manager package also includes couple of software modules
that facilitates Inter processor communication between ARM running linux
and DSP running RTOS. These components provide APIs in both ARM linux as
well as on DSP RTOS.

.. rubric:: MPM Mailbox module
   :name: mpm-mailbox-module

Mailbox is used for exchanging control messages between the host and
individual DSP cores.

.. rubric:: MPM Sync module
   :name: mpm-sync-module

Sync Module implements support for Multicore Barriers and Locks.

