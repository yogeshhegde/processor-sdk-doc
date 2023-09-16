.. http://processors.wiki.ti.com/index.php/CCSv6_Getting_Started_Guide

.. rubric:: Introduction
   :name: introduction

Welcome to Code Composer Studio v6! Code Composer Studio v6 is a major
new release of Code Composer Studio (CCS) that is based on the Eclipse
open source software framework. The Eclipse software framework is used
for many different applications but it was originally developed as a
open framework for creating development tools. We have chosen to base
CCS on Eclipse as it offers an excellent software framework for building
software development environments and is becoming a standard framework
used by many embedded software vendors. CCSv5 combines the advantages of
the Eclipse software framework with advanced embedded debug capabilities
from Texas Instruments resulting in a compelling feature rich
development environment for embedded developers.

**Note:** This guide is designed for the latest release of CCSv6.

.. rubric:: Obtaining CCS
   :name: obtaining-ccs

Code Composer Studio v6 can be downloaded directly to your PC.

`GSG:CCSv6 Download <http://processors.wiki.ti.com/index.php/GSG:CCSv6_Download>`__

.. rubric:: Installing CCS
   :name: installing-ccs

The installation process is the same for both delivery methods (DVD or
download).

`GSG:CCSv6 installation <http://processors.wiki.ti.com/index.php/GSG:CCSv6_installation>`__

.. rubric:: Running CCS for the first time
   :name: running-ccs-for-the-first-time

When executed for the first time, Code Composer Studio v6 requires a few
additional steps to operate properly:

-  Select a workspace, where all the projects will be placed
-  An active license

Follow the link below to learn about these last steps:

`GSG:CCSv6 Running for the first
time <http://processors.wiki.ti.com/index.php/GSG:CCSv6_Running_for_the_first_time>`__

.. rubric:: Working with CCS
   :name: working-with-ccs

.. rubric:: Code Development
   :name: code-development

All work on Code Composer Studio is based on projects - a collection of
source, include and configuration files.

| The most interesting way to get started on CCSv6 is to follow one of
  the basic training modules that are published in this wiki server.

`Device_Specific_Workshops_with_CCS <http://processors.wiki.ti.com/index.php/Device_Specific_Workshops_with_CCS>`__
`CCS_Fundamentals_Workshop <http://processors.wiki.ti.com/index.php/CCS_Fundamentals_Workshop>`__

| **Important!** The modules above require software libraries and
  components that are not installed with CCSv6 by default: MSP430Ware,
  Tivaware, ControlSUITE, Starterware, SYSBIOS, MCSDK, etc. These
  components must be downloaded separately, and the easiest way to find
  them is through the CCS App Center. To explore that and a few other
  features, check the short video below:

Additional quick start guides and videos can be found at the `CCS
Training category <http://processors.wiki.ti.com/index.php/Category:CCS_Training>`__.

.. rubric:: Advanced Topics
   :name: advanced-topics

The following topics are identical between CCSv5 and CCSv6, therefore
they link to the same page between the two versions.

.. rubric:: Advanced target configurations
   :name: advanced-target-configurations

The sections below describe several procedures used in complex target
configurations.

`GSG:Common_target_configurations_v5 <http://processors.wiki.ti.com/index.php/GSG:Common_target_configurations_v5>`__
`GSG:Adding GEL files to a target configuration
v5 <http://processors.wiki.ti.com/index.php/GSG:Adding_GEL_files_to_a_target_configuration_v5>`__
`GSG:Connecting to target cores in SoC devices
v5 <http://processors.wiki.ti.com/index.php/GSG:Connecting_to_target_cores_in_SoC_devices_v5>`__
`http://processors.wiki.ti.com/index.php/Target_Configuration_-_Custom_Configurations <http://processors.wiki.ti.com/index.php/Target_Configuration_-_Custom_Configurations>`__

.. rubric:: Linux development
   :name: linux-development

One additional feature in CCSv6 is the ability to create projects and
debug code for embedded Linux environments.

The topics below shows how to create projects for Linux that use the
open source compiler suite (GCC), as well as perform debugging in this
environment.

`How to create GCC projects in
CCSv5 <http://processors.wiki.ti.com/index.php/How_to_create_GCC_projects_in_CCSv5>`__
`Sitara_Linux_SDK_CCS_Debug <http://processors.wiki.ti.com/index.php/Sitara_Linux_SDK_CCS_Debug>`__

.. rubric:: Resources and References
   :name: resources-and-references

-  Main Code Composer Studio v6 wiki page:

`http://processors.wiki.ti.com/index.php/Category:Code_Composer_Studio_v6 <http://processors.wiki.ti.com/index.php/Category:Code_Composer_Studio_v6>`__

-  Frequently asked questions:

`http://processors.wiki.ti.com/index.php/FAQ_-_CCSv6 <http://processors.wiki.ti.com/index.php/FAQ_-_CCSv6>`__

-  Eclipse Concepts:

`http://processors.wiki.ti.com/index.php/Eclipse_Concepts <http://processors.wiki.ti.com/index.php/Eclipse_Concepts>`__

.. rubric:: Example projects, libraries and source code
   :name: example-projects-libraries-and-source-code

**1.** Stellarisware libraries and example code:

http://focus.ti.com/docs/toolsw/folders/print/sw-lm3s.html
**2.** MSP430 source code:

http://focus.ti.com/mcu/docs/mcuprodcodeexamples.tsp?sectionId=96&tabId=1468
**3.** TMS320C2000 libraries and example code:

http://focus.ti.com/mcu/docs/mcuprodcodeexamples.tsp?sectionId=96&tabId=1470
**4.** TMS320C5500 Libraries:

Chip Support Library (CSL):
http://focus.ti.com/docs/toolsw/folders/print/sprc133.html
DSP Library (DSPLIB):
http://focus.ti.com/docs/toolsw/folders/print/sprc100.html
Image Library (IMGLIB):
http://focus.ti.com/docs/toolsw/folders/print/sprc101.html
**5.** TMS320C6000 Libraries:

http://focus.ti.com/dsp/docs/dspfindtoolswresults.tsp?sectionId=3&tabId=1620&familyId=44&toolTypeId=24&go=Go
