=====================================
MultiprocMgr - Texas Instruments Wiki
=====================================

.. raw:: html

   <div id="mw-page-base" class="noprint">

.. raw:: html

   </div>

.. raw:: html

   <div id="mw-head-base" class="noprint">

.. raw:: html

   </div>

.. raw:: html

   <div id="content" class="mw-body" role="main">

.. raw:: html

   <div id="siteNotice">

.. raw:: html

   <div id="localNotice" lang="en" dir="ltr">

| 

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div class="mw-indicators">

.. raw:: html

   </div>

.. rubric:: MultiprocMgr
   :name: firstHeading
   :class: firstHeading

.. raw:: html

   <div id="bodyContent" class="mw-body-content">

.. raw:: html

   <div id="siteSub">

From Texas Instruments Wiki

.. raw:: html

   </div>

.. raw:: html

   <div id="contentSub">

.. raw:: html

   </div>

.. raw:: html

   <div id="jump-to-nav" class="mw-jump">

Jump to: `navigation <#mw-head>`__, `search <#p-search>`__

.. raw:: html

   </div>

.. raw:: html

   <div id="mw-content-text" class="mw-content-ltr" lang="en" dir="ltr">

.. raw:: html

   <div class="hf-nsheader">

.. raw:: html

   </div>

.. raw:: html

   <div class="hf-header">

.. raw:: html

   </div>

NOTE: This page is under construction

.. raw:: html

   <div id="toc" class="toc">

.. raw:: html

   <div id="toctitle">

.. rubric:: Contents
   :name: contents

.. raw:: html

   </div>

-  `1 Introduction <#Introduction>`__

   -  `1.1 Multi Proc Manager Linux
      module <#Multi_Proc_Manager_Linux_module>`__
   -  `1.2 Interprocessor Communication related
      packages <#Interprocessor_Communication_related_packages>`__

      -  `1.2.1 MPM Mailbox module <#MPM_Mailbox_module>`__
      -  `1.2.2 MPM Sync module <#MPM_Sync_module>`__

.. raw:: html

   </div>

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

.. raw:: html

   <div class="hf-footer">

.. raw:: html

   </div>

.. raw:: html

   <div class="hf-nsfooter">

+-----------------------------------+-----------------------------------+
| |E2e.jpg|                         | *For technical support please     |
|                                   | post your questions at            |
|                                   | http://e2e.ti.com. Please post    |
|                                   | only comments about the article   |
|                                   | **MultiprocMgr** here.*           |
+-----------------------------------+-----------------------------------+

|Hyperlink blue.png|

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

**Links**
+-----------------+-----------------+-----------------+-----------------+
| | `Amplifiers & | | `DLP &        | `Processors <ht | | `Switches &   |
|   Linear <http: |   MEMS <http:// | tp://www.ti.com |   Multiplexers  |
| //www.ti.com/ls | www.ti.com/lsds | /lsds/ti/dsp/em | <http://www.ti. |
| ds/ti/analog/am | /ti/analog/mems | bedded_processo | com/lsds/ti/ana |
| plifier_and_lin | /mems.page>`__  | r.page>`__      | log/switches_an |
| ear.page>`__    | | `High-Reliabi |                 | d_multiplexers. |
| | `Audio <http: | lity <http://ww | -  `ARM         | page>`__        |
| //www.ti.com/ls | w.ti.com/lsds/t |    Processors < | | `Temperature  |
| ds/ti/analog/au | i/analog/high_r | http://www.ti.c |   Sensors &     |
| dio/audio_overv | eliability.page | om/lsds/ti/dsp/ |   Control       |
| iew.page>`__    | >`__            | arm.page>`__    |   ICs <http://w |
| | `Broadband    | | `Interface <h | -  `Digital     | ww.ti.com/lsds/ |
|   RF/IF &       | ttp://www.ti.co |    Signal       | ti/analog/tempe |
|   Digital       | m/lsds/ti/analo |    Processors   | rature_sensor.p |
|   Radio <http:/ | g/interface/int |    (DSP) <http: | age>`__         |
| /www.ti.com/lsd | erface.page>`__ | //www.ti.com/ls | | `Wireless     |
| s/ti/analog/rfi | | `Logic <http: | ds/ti/dsp/home. |   Connectivity  |
| f.page>`__      | //www.ti.com/ls | page>`__        | <http://focus.t |
| | `Clocks &     | ds/ti/logic/hom | -  `Microcontro | i.com/wireless/ |
|   Timers <http: | e_overview.page | llers           | docs/wirelessov |
| //www.ti.com/ls | >`__            |    (MCU) <http: | erview.tsp?fami |
| ds/ti/analog/cl | | `Power        | //www.ti.com/ls | lyId=2003&secti |
| ocksandtimers/c |   Management <h | ds/ti/microcont | onId=646&tabId= |
| locks_and_timer | ttp://www.ti.co | roller/home.pag | 2735>`__        |
| s.page>`__      | m/lsds/ti/analo | e>`__           |                 |
| | `Data         | g/powermanageme | -  `OMAP        |                 |
|   Converters <h | nt/power_portal |    Applications |                 |
| ttp://www.ti.co | .page>`__       |    Processors < |                 |
| m/lsds/ti/analo |                 | http://www.ti.c |                 |
| g/dataconverter |                 | om/lsds/ti/omap |                 |
| s/data_converte |                 | -applications-p |                 |
| r.page>`__      |                 | rocessors/the-o |                 |
|                 |                 | map-experience. |                 |
|                 |                 | page>`__        |                 |
+-----------------+-----------------+-----------------+-----------------+

.. raw:: html

   <div id="tiPrivacy">

.. raw:: html

   </div>

.. raw:: html

   <div class="printfooter">

Retrieved from
"http://processors.wiki.ti.com/index.php?title=MultiprocMgr&oldid=213023"

.. raw:: html

   </div>

.. raw:: html

   <div id="catlinks" class="catlinks catlinks-allhidden">

.. raw:: html

   </div>

.. raw:: html

   <div class="visualClear">

.. raw:: html

   </div>

.. raw:: html

   <div id="mw-navigation">

.. rubric:: Navigation menu
   :name: navigation-menu

.. raw:: html

   <div id="mw-head">

.. raw:: html

   <div id="p-personal" role="navigation"
   aria-labelledby="p-personal-label">

.. rubric:: Personal tools
   :name: p-personal-label

-  `Log in </index.php?title=Special:UserLogin&returnto=MultiprocMgr>`__
-  `Request account </index.php/Special:RequestAccount>`__

.. raw:: html

   </div>

.. raw:: html

   <div id="left-navigation">

.. raw:: html

   <div id="p-namespaces" class="vectorTabs" role="navigation"
   aria-labelledby="p-namespaces-label">

.. rubric:: Namespaces
   :name: p-namespaces-label

-  `Page </index.php/MultiprocMgr>`__
-  `Discussion </index.php?title=Talk:MultiprocMgr&action=edit&redlink=1>`__

.. raw:: html

   </div>

.. raw:: html

   <div id="p-variants" class="vectorMenu emptyPortlet"
   role="navigation" aria-labelledby="p-variants-label">

.. rubric:: Variants\ ` <#>`__
   :name: p-variants-label

.. raw:: html

   <div class="menu">

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div id="right-navigation">

.. raw:: html

   <div id="p-views" class="vectorTabs" role="navigation"
   aria-labelledby="p-views-label">

.. rubric:: Views
   :name: p-views-label

-  `Read </index.php/MultiprocMgr>`__
-  `View source </index.php?title=MultiprocMgr&action=edit>`__
-  `View history </index.php?title=MultiprocMgr&action=history>`__

.. raw:: html

   </div>

.. raw:: html

   <div id="p-cactions" class="vectorMenu emptyPortlet"
   role="navigation" aria-labelledby="p-cactions-label">

.. rubric:: More\ ` <#>`__
   :name: p-cactions-label

.. raw:: html

   <div class="menu">

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div id="p-search" role="search">

.. rubric:: Search
   :name: search

.. raw:: html

   <div id="simpleSearch">

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div id="mw-panel">

.. raw:: html

   <div id="p-logo" role="banner">

` </index.php/Main_Page>`__

.. raw:: html

   </div>

.. raw:: html

   <div id="p-navigation" class="portal" role="navigation"
   aria-labelledby="p-navigation-label">

.. rubric:: Navigation
   :name: p-navigation-label

.. raw:: html

   <div class="body">

-  `Main Page </index.php/Main_Page>`__
-  `All pages </index.php/Special:AllPages>`__
-  `All categories </index.php/Special:Categories>`__
-  `Recent changes </index.php/Special:RecentChanges>`__
-  `Random page </index.php/Special:Random>`__
-  `Help <https://www.mediawiki.org/wiki/Special:MyLanguage/Help:Contents>`__

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div id="p-coll-print_export" class="portal" role="navigation"
   aria-labelledby="p-coll-print_export-label">

.. rubric:: Print/export
   :name: p-coll-print_export-label

.. raw:: html

   <div class="body">

-  `Create a
   book </index.php?title=Special:Book&bookcmd=book_creator&referer=MultiprocMgr>`__
-  `Download as
   PDF </index.php?title=Special:Book&bookcmd=render_article&arttitle=MultiprocMgr&oldid=213023&writer=rl>`__
-  `Printable version </index.php?title=MultiprocMgr&printable=yes>`__

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div id="p-tb" class="portal" role="navigation"
   aria-labelledby="p-tb-label">

.. rubric:: Toolbox
   :name: p-tb-label

.. raw:: html

   <div class="body">

-  `What links here </index.php/Special:WhatLinksHere/MultiprocMgr>`__
-  `Related
   changes </index.php/Special:RecentChangesLinked/MultiprocMgr>`__
-  `Special pages </index.php/Special:SpecialPages>`__
-  `Permanent link </index.php?title=MultiprocMgr&oldid=213023>`__
-  `Page information </index.php?title=MultiprocMgr&action=info>`__

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   </div>

.. raw:: html

   <div id="footer" role="contentinfo">

-  This page was last modified on 19 February 2016, at 12:47.
-  This page has been accessed 1,585 times.
-  Content is available under `Creative Commons
   Attribution-ShareAlike <http://creativecommons.org/licenses/by-sa/3.0/>`__
   unless otherwise noted.

-  `Privacy policy </index.php/Project:Privacy_policy>`__
-  `About Texas Instruments Wiki </index.php/Project:About>`__
-  `Disclaimers </index.php/Project:General_disclaimer>`__
-  `Terms of Use </index.php/Project:Terms_of_Service>`__

-  |Creative Commons Attribution-ShareAlike|
-  |Powered by MediaWiki|

.. raw:: html

   <div style="clear:both">

.. raw:: html

   </div>

.. raw:: html

   </div>

.. |E2e.jpg| image:: /images/8/82/E2e.jpg
   :width: 305px
   :height: 63px
   :target: /index.php/File:E2e.jpg
.. |Hyperlink blue.png| image:: /images/9/9f/Hyperlink_blue.png
   :width: 96px
   :height: 96px
   :target: /index.php/File:Hyperlink_blue.png
.. |Creative Commons Attribution-ShareAlike| image:: /resources/assets/licenses/cc-by-sa.png
   :width: 88px
   :height: 31px
   :target: http://creativecommons.org/licenses/by-sa/3.0/
.. |Powered by MediaWiki| image:: /resources/assets/poweredby_mediawiki_88x31.png
   :width: 88px
   :height: 31px
   :target: //www.mediawiki.org/
