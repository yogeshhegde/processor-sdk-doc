.. http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_MCASP 

| .. rubric:: **Overview**          | .. rubric:: **User Interface**    |
|    :name: overview                |    :name: user-interface          |
|                                   |                                   |
| -  `Introduction </index.php/Proc | -  `Driver                        |
| essor_SDK_RTOS_MCASP#Introduction |    Configuration </index.php/Proc |
| >`__                              | essor_SDK_RTOS_MCASP#Driver_Confi |
| -  `Additional                    | guration>`__                      |
|    References </index.php/Process | -  `APIs </index.php/Processor_SD |
| or_SDK_RTOS_MCASP#Additional_Refe | K_RTOS_MCASP#APIs>`__             |
| rences>`__                        |                                   |
+-----------------------------------+-----------------------------------+
| .. rubric:: **Application**       | .. rubric:: **Debug**             |
|    :name: application             |    :name: debug                   |
|                                   |                                   |
| -  `Examples </index.php/Processo |                                   |
| r_SDK_RTOS_MCASP#Example>`__      |                                   |
+-----------------------------------+-----------------------------------+

.. rubric:: Introduction
   :name: introduction

The multichannel audio serial port (McASP) functions as a
general-purpose audio serial port optimized for the needs of
multichannel audio applications. The McASP is useful for time-division
multiplexed (TDM) stream, Inter-Integrated Sound (I2S) protocols, and
intercomponent digital audio interface transmission (DIT).The
multichannel buffered serial port (McASP) peripheral allows direct
interface to other TI DSPs, codecs, and other devices in a system. The
following sub sections explain the hardware (McASP peripheral) and
software context of the McASP LLD.

The device driver exposes a set of well-defined APIs which are used by
the application layer to send and receive data via the McASP peripheral.
The driver also exposes a set of well-defined OS abstraction APIs which
are used to ensure that the driver is OS independent and portable. The
McASP driver uses the CSL McASP register layer for all McASP MMR access.
The McASP driver also interfaces with the EDMA3 library to be able to
transfer data to and from McASP peripheral and data memory.

.. rubric:: Driver Configuration
   :name: driver-configuration

The McASP driver provides a sample implementation sequence which
initializes the MCASP IP block. The McASP Device initialization API is
implemented as a sample prototype:

::

    void McaspDevice_init (void)

The function initializes all the instance specific information like base
address of instance CFG registers, FIFO address for the instance, TX and
RX CPU event numbers, TX and RX EDMA event numbers etc.

For details about individual fields of this structure, see the Doxygen
help by opening
PDK_INSTALL_DIR\Packages\ti\drv\mcasp\docs\doxygen\html\index.html.

::

     int32_t Mcasp_socGetInitCfg(uint32_t index, Mcasp_HwInfo *cfg)

The function obtains the soc configuration parameters such as interrupt
numbers, mux configuration parameters etc.

::

     int32_t Mcasp_socSetInitCfg(uint32_t index, const Mcasp_HwInfo *cfg)

The function set the soc configuration parameters such as interrupt
numbers, mux configuration parameters etc.

.. rubric:: APIs
   :name: apis

Refer to below API files:

::

    #include <ti/drv/mcasp/mcasp_drv.h>
    #include <ti/drv/mcasp/soc/mcasp_soc.h>

.. rubric:: McASP Buffer formats
   :name: mcasp-buffer-formats

The McASP driver provides various buffer formats for sending the data
to/from the audio device. The differences between these formats arise
from the way the audio samples are collected from various serializers
and their timeslots and arranged in the system's memory. This way the
application can choose to run audio processing algorithms over the data
without the need for re-arranging those data every frame. The buffer
format is provided in the **Mcasp_ChanParams.dataFormat** in the form of
**Mcasp_BufferFormat** defined in mcasp_drv.h The below section provides
an overview of the various formats. In the explanatory diagrams in each
section, McASP controller recieves samples in frame intervals denoted by
t1,t2..tn. The McASP driver collects these and arranges those samples in
the memory in various formats in to the host's System memory. We have
chosen 32 bit samples and 32-bit word addresses throughout for
simplicity.

.. rubric:: Mcasp_BufferFormat_1SER_1SLOT
   :name: mcasp_bufferformat_1ser_1slot

This is applicable if only one serializer and one timeslot is used. The
samples are ordered in the order they received or sent.

.. Image:: ../images/1SLOT_1SER.PNG

.. rubric:: Mcasp_BufferFormat_1SER_MULTISLOT_INTERLEAVED
   :name: mcasp_bufferformat_1ser_multislot_interleaved

This is applicable if multiple slots are used with one serializer. The
samples from the different timeslots are stored interleaved in the
memory as below. Different timeslots' samples are denoted by different
colors and are labelled t1,t2..tn according to the time they arrive at
the serializer.

.. Image:: ../images/1SER_MULTISLOT_INTERLEAVED.PNG

.. rubric:: Mcasp_BufferFormat_1SER_MULTISLOT_NON_INTERLEAVED
   :name: mcasp_bufferformat_1ser_multislot_non_interleaved

This is applicable if multiple slots are used with one serializer. The
samples from the different timeslots are grouped together on the basis
of the timeslot and stored in the memory as shown below. Different
timeslots' samples are denoted by different colors and are labelled
t1,t2..tn according to the time they arrive at the serializer.

.. Image:: ../images/1SER_MULTISLOT_NON_INTERLEAVED.PNG

NOTE: if the non-interleaved format is used, the Mcasp_ChanParams->
hwFifoEventDMARatio must be set to 1.

.. rubric:: Mcasp_BufferFormat_MULTISER_1SLOT_SER_INTERLEAVED
   :name: mcasp_bufferformat_multiser_1slot_ser_interleaved

This is applicable if multiple serializers are used with one time slot
is used for each of the serializers. The samples from the different
serializers are stored in the memory in interleaved fashion as shown
below Different serializers' samples are denoted by different colors and
are labelled S1,S2..Sn according to the time they arrive at the
serializer.

.. Image:: ../images/1SER_MULTISER_1SLOT_SER_INTERLEAVED_2.PNG

| 

.. rubric:: Mcasp_BufferFormat_MULTISER_1SLOT_SER_NON_INTERLEAVED
   :name: mcasp_bufferformat_multiser_1slot_ser_non_interleaved

This is applicable if multiple serializers are used with one timeslots
each per serializer. The samples from the different timeslots are
grouped together on the basis of the serializer and stored in the memory
as shown below Different serializers' samples are denoted by different
colors and are labelled S1,S2..Sn according to the time they arrive at
the serializer.

.. Image:: ../images/1SER_MULTISER_1SLOT_SER_NON_INTERLEAVED.PNG

.. rubric:: Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_1
   :name: mcasp_bufferformat_multiser_multislot_semi_interleaved_1

This is applicable if multiple serializers are used and each serializer
containing multiple timeslots. The samples are stored in the memory
interleaved based on serializer and timeslots as shown below. In this
example, there are 3 serializers and 2 timeslots per serializers whose
samples are noted by Ln (left) and Rn (right). Different serializers'
samples are denoted by different colors.

.. Image:: ../images/1SER_MULTISER_MULTISLOT_SEMI_INTERLEAVED_1_UPDATED.PNG

.. rubric:: Mcasp_BufferFormat_MULTISER_MULTISLOT_SEMI_INTERLEAVED_2
   :name: mcasp_bufferformat_multiser_multislot_semi_interleaved_2

This is applicable if multiple serializers are used and each serializer
containing multiple timeslots. The samples are grouped based on the
serializer and within one serializer, the timeslots are interleaved as
shown below. In this example, there are 3 serializers and 2 timeslots
per serializers whose samples are noted by Ln (left) and Rn
(right).Different serializers' samples are denoted by different colors.

.. Image:: ../images/1SER_MULTISER_MULTISLOT_SEMI_INTERLEAVED_2.PNG

NOTE: if the non-interleaved format is used, the Mcasp_ChanParams->
hwFifoEventDMARatio must be set to 1.

.. rubric:: Mcasp WordBits Selection
   :name: mcasp-wordbits-selection

With all the frame formats explained above, there is an option to choose
which bits to pack from the 32-bit serializer data obtained from/to the
McASP serializer, when the word size is less than the slot size. This
option is exercised by setting the Mcasp_chanParams->wordBitsSelect to
Mcasp_wordBitsSelect_LSB/Mcasp_wordBitsSelect_MSB.

If the default Mcasp_wordBitsSelect_LSB option is selected, the LSBs are
packed in to the system memory.

Below is an example of word size = 16bits and slot size = 32 bits and
the Mcasp_wordBitsSelect_LSB option is used. On the receiving side, the
serializer holds the 32 bit data whose LSB 16 bits are picked up and
packed in to the system memory. The MSB 16 bits are ignored.

.. Image:: ../images/WordSelect_LSB.PNG

If the Mcasp_wordBitsSelect_MSB option is used, the serializer's
MSB-16bits are packed in to the system memory. The LSBs are ignored.

.. Image:: ../images/WordSelect_MSB.PNG

| 

.. rubric:: Example
   :name: example

+-----------------------+-----------------------+-----------------------+
| Name                  | Description           | Expected Results      |
+=======================+=======================+=======================+
| AIC31 Stereo loopback | | Example             | | Audio sent in to    |
|                       |   demonstrating       |   the EVM being       |
|                       |   sample McASP        |   played out via the  |
|                       |   loopback .          |   stereo output of    |
|                       |   Reference example   |   the EVM             |
|                       |   for developers      |                       |
+-----------------------+-----------------------+-----------------------+
| Device loopback       | | Example             | | Digital ramp        |
|                       |   demonstrating       |   pattern sent to     |
|                       |   sample McASP device |   McASP and getting   |
|                       |   loopback .          |   looped back         |
|                       |   Reference example   |   internally using    |
|                       |   for developers      |   device loopback     |
+-----------------------+-----------------------+-----------------------+
| `AudioEQ              | | Example             | | Three band          |
| example <http://www.t |   demonstrating       |   Equalization of     |
| i.com/tool/tidep0069> |   stereo audio        |   stereo channel      |
| `__                   |   equalization using  |   using biquad        |
|                       |   using biquad        |   filters with gain   |
|                       |   filters . Reference |   control using       |
|                       |   design for          |   serial console      |
|                       |   developers. **TI    |   inputs              |
|                       |   Design Guide**:     |                       |
|                       |   `TIDEP0069 <http:// |                       |
|                       | www.ti.com/lit/ug/tid |                       |
|                       | ubq2/tidubq2.pdf>`__  |                       |
+-----------------------+-----------------------+-----------------------+

.. rubric:: Introduction
   :name: introduction-1

The sample application demonstrates the use of the MCASP driver for
audio playback. The application uses McASP LLD, and programs the AIC
codec on the EVM to send and receive the audio input. The audio received
from the AIC codec is loop back-ed at the application and sent back to
the AIC codec via MCASP LLD.

.. rubric:: Audio test setup
   :name: audio-test-setup

Please ensure the below before running the demo

#. Connect the EVM’s stereo audio input to the PC’s stereo audio output
#. Connect the EVM’s stereo audio output to powered speakers. Please
   make sure the amplification on the speakers is high enough for the
   audio output to be heard

.. rubric:: Building and running the Example
   :name: building-and-running-the-example

#. Run pdkProjectCreate to create the
   MCASP_Audio_<evm>_<device>ExampleProject
#. Load the project on to CCS and build the same.
#. Build the example
#. Load the MCASP_Audio_<evm>_<device>ExampleProject
#. Run the example

.. rubric:: Testing the example
   :name: testing-the-example

#. Play an audio file on the PC.
#. You should be able to hear the same audio on the speakers connected
   to the EVM. It is the PC’s audio output which is loop backed at the
   EVM’s MCASP example outputted to the speakers.

NOTE: Please make sure the speakers’ output volume is high enough for
the audio to be audible.

.. rubric:: Additional References
   :name: additional-references

+-----------------------------------+-----------------------------------+
| **Document**                      | **Location**                      |
+-----------------------------------+-----------------------------------+
| API Reference Manual              | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\mcasp\docs\doxygen\html\inde |
|                                   | x.html                            |
+-----------------------------------+-----------------------------------+
| Release Notes                     | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\mcasp\docs\ReleaseNotes_MCAS |
|                                   | P_LLD.pdf                         |
+-----------------------------------+-----------------------------------+
| Software design Specification     | $(TI_PDK_INSTALL_DIR)\packages\ti |
|                                   | \drv\mcasp\docs\MCASP_LLD_SDS.pdf |
+-----------------------------------+-----------------------------------+

| 
| Templates used on this page:

Return to Processor SDK RTOS MCASP.

Navigation menu Log inRequest accountPageDiscussionReadView sourceView
history

Search Go Main Page All pages All categories Recent changes Random page
Help Toolbox What links here Related changes Special pages Page
information This page has been accessed 927 times. Privacy policyAbout
Texas Instruments WikiDisclaimersTerms of UseCreative Commons
Attribution-ShareAlike Powered by MediaWiki

| 
| Moved to
  http://processors.wiki.ti.com/index.php/Processor_SDK_RTOS_MCASP

.. raw:: html

