.. include:: /replacevars.rst.inc

SERDES
------

.. rubric:: **Introduction**

SERDES converts device (SoC) parallel data into serialized data that can be
output over a high-speed electrical interface. In the opposite direction,
SerDes converts high-speed serial data into parallel data that can be
processed by the device.

SERDES is used for transmitting/receiving data for PCIe, USB3, CPSW
(QSGMII, SGMII, USXGMII, XFI), eDP in K3 SoC.

.. rubric:: **Types**

There are two types of SERDES used in K3 SoC:

        1) 2 Lane SERDES: J721E
        2) 4 Lane SERDES: J721E, J7200, J721S2, AM64

.. rubric:: *2 Lane Serdes*

.. code-block:: text

                       ┌───────────────────┐
                       │                   │
                       │                   │
     <-> Peripheral IP1│                   │   <-> RX1/TX1
     ──────────────────┤                   ├────────────────
                       │                   │
                       │                   │
                       │                   │
                       │    2L SERDES      │
                       │                   │
                       │                   │
                       │                   │
     <-> Peripheral IP2│                   │   <-> RX2/TX2
     ──────────────────┤                   ├────────────────
                       │                   │
                       │                   │
                       │                   │
                       └───────────────────┘

.. rubric:: *4 Lane Serdes*

.. code-block:: text

                       ┌───────────────────┐
     <-> Peripheral IP1│                   │   <-> RX1/TX1
     ──────────────────┤                   ├────────────────
                       │                   │
                       │                   │
     <-> Peripheral IP2│                   │   <-> RX2/TX2
     ──────────────────┤                   ├────────────────
                       │                   │
                       │    4L SERDES      │
     <-> Peripheral IP3│                   │   <-> RX3/TX3
     ──────────────────┤                   ├────────────────
                       │                   │
                       │                   │
     <-> Peripheral IP4│                   │   <-> RX4/TX4
     ──────────────────┤                   ├────────────────
                       │                   │
                       │                   │
                       └───────────────────┘

Here Peripheral IP refers to PCIe, USB3, CPSW or eDP. A single SERDES
can support either one protocol (connects to one Peripheral IP) or two
protocols (connects to multiple Peripheral IP) at the same time.

If a SERDES supports one protocol, it's called a single link PHY and
if a SERDES supports two protocols, it's called multi-link PHY.
Note that a single link PHY can comprise multiple lanes. And for
multi-link PHY, the lanes can be split up in different ways but the
only constraint is the SERDES can support only two protocols.

So for the 2L SERDES above, Peripheral IP1 and Peripheral IP2 can be
connected to the same peripheral IP in the case of single link PHY or
to two different Peripheral IPs in the case of multi-link PHY.

It's also not always necessary to use all the lanes of a SERDES and
some lanes can be left unused.

.. ifconfig:: CONFIG_part_family in ('J7_family')

    .. rubric:: **J721e SERDES**

    J721e has four instances of 2L SERDES and one 4L Serdes.


    .. rubric:: *SERDES Muxing*

    The Following Section lists the possible ways SERDES can be muxed

        .. rubric:: *SERDES 0*

        .. code-block:: text

                               ┌───────────────────┐
                  QSGMII_LANE1/│                   │
                   PCIE0_LANE0/│                   │
                   USB3_0_SWAP │                   │   <-> RX1/TX1
             ──────────────────┤                   ├────────────────
                               │                   │
                               │    2L SERDES      │
                  QSGMII_LANE2/│                   │
                   PCIE0_LANE1/│                   │
                        USB3_0 │                   │   <-> RX2/TX2
             ──────────────────┤                   ├────────────────
                               │                   │
                               │                   │
                               └───────────────────┘

        .. rubric:: *SERDES 1*

        .. code-block:: text

                               ┌───────────────────┐
                  QSGMII_LANE3/│                   │
                   PCIE1_LANE0/│                   │
                   USB3_1_SWAP/│                   │
                   SGMII_LANE0 │                   │   <-> RX1/TX1
             ──────────────────┤                   ├────────────────
                               │                   │
                               │    2L SERDES      │
                  QSGMII_LANE4/│                   │
                   PCIE1_LANE1/│                   │
                        USB3_1/│                   │
                   SGMII_LANE1 │                   │   <-> RX2/TX2
             ──────────────────┤                   ├────────────────
                               │                   │
                               │                   │
                               └───────────────────┘

        .. rubric:: *SERDES 2*

        .. code-block:: text

                               ┌───────────────────┐
                   PCIE2_LANE0/│                   │
                   USB3_1_SWAP/│                   │
                   SGMII_LANE0 │                   │   <-> RX1/TX1
             ──────────────────┤                   ├────────────────
                               │                   │
                               │    2L SERDES      │
                   PCIE2_LANE1/│                   │
                        USB3_1/│                   │
                   SGMII_LANE1 │                   │   <-> RX2/TX2
             ──────────────────┤                   ├────────────────
                               │                   │
                               │                   │
                               └───────────────────┘

        .. rubric:: *SERDES 3*

        .. code-block:: text

                               ┌───────────────────┐
                   PCIE3_LANE0/│                   │
                   USB3_0_SWAP │                   │   <-> RX1/TX1
             ──────────────────┤                   ├────────────────
                               │                   │
                               │    2L SERDES      │
                   PCIE3_LANE1/│                   │
                        USB3_0 │                   │   <-> RX2/TX2
             ──────────────────┤                   ├────────────────
                               │                   │
                               │                   │
                               └───────────────────┘

        .. rubric:: *SERDES 4*

        .. code-block:: text

                               ┌───────────────────┐
                     EDP_LANE0/│                   │
                  QSGMII_LANE5 │                   │   <-> RX1/TX1
             ──────────────────┤                   ├────────────────
                               │                   │
                               │                   │
                     EDP_LANE1/│                   │
                  QSGMII_LANE6 │                   │   <-> RX2/TX2
             ──────────────────┤                   ├────────────────
                               │                   │
                               │    4L SERDES      │
                     EDP_LANE2/│                   │
                  QSGMII_LANE7 │                   │   <-> RX3/TX3
             ──────────────────┤                   ├────────────────
                               │                   │
                               │                   │
                     EDP_LANE3/│                   │
                  QSGMII_LANE8 │                   │   <-> RX4/TX4
             ──────────────────┤                   ├────────────────
                               │                   │
                               └───────────────────┘

    .. rubric:: *DT Muxing Configuration*

    The Muxing configuration for each SERDES lanes can be described using
    device tree. The following shows the default SERDES configuration for
    the J721E common processor board.

    .. code-block:: text

        &serdes_ln_ctrl {
                idle-states = <J721E_SERDES0_LANE0_PCIE0_LANE0>, <J721E_SERDES0_LANE1_PCIE0_LANE1>,
                              <J721E_SERDES1_LANE0_PCIE1_LANE0>, <J721E_SERDES1_LANE1_PCIE1_LANE1>,
                              <J721E_SERDES2_LANE0_PCIE2_LANE0>, <J721E_SERDES2_LANE1_PCIE2_LANE1>,
                              <J721E_SERDES3_LANE0_USB3_0_SWAP>, <J721E_SERDES3_LANE1_USB3_0>,
                              <J721E_SERDES4_LANE0_EDP_LANE0>, <J721E_SERDES4_LANE1_EDP_LANE1>,
                              <J721E_SERDES4_LANE2_EDP_LANE2>, <J721E_SERDES4_LANE3_EDP_LANE3>;
        };

    Here the 1st two cells specifies the muxing configuration of SERDES 0 (lane 0 and lane 1),
    the 2nd two cells specifies the muxing configuration of SERDES 1 (lane 0 and lane 1),
    the 3rd two cells specifies the muxing configuration of SERDES 2 (lane 0 and lane 1),
    the 4th two cells specifies the muxing configuration of SERDES 3 (lane 0 and lane 1) and
    the rest of the cells (last 4 cells) specifies the muxing configuration of SERDES 4
    (lane 0, lane 1, lane 2 and lane 3).

    The exact mux values to be programmed can be obtained from the dt-bindings include directory
    of kernel repository

    .. code-block:: text

        include/dt-bindings/mux/ti-serdes.h

    The configuration uses the mux framework of Linux. More information can be found in the
    Documentation of kernel repository.

    .. code-block:: text

        Documentation/devicetree/bindings/mux/mux-controller.yaml

    .. rubric:: **2L SERDES Clocking Options**

    The following picture shows the clock options of 2L SERDES.

    .. code-block:: text

                                                   /|   HFOSC0_CLKOUT
        ┌───────────────────────┐                 / ┌────────────────
        │                       │                 │ │
        │                       │    core_refclk /│ │   HFOSC1_CLKOUT
        │      ┌─────────┐      │    core_refclk1 │ ├────────────────
        │      │  PLL0   │      │◄────────────────┤ │
        │      │         │      │                 │ │MAIN_PLL3_HSDIV4_CLKOUT (100/125/156.25 MHz)
        │      └─────────┘      │                 │ ├────────────────
        │                       │                 │ │
        │                       │                 │ │MAIN_PLL2_HSDIV4_CLKOUT (100 MHz)
        │                       │                 \ ├────────────────
        │      ┌─────────┐      │                  \│
        │      │  PLL1   │      │
        │      │         │      │    cmn_refclk
        │      └─────────┘      │◄─────────────────X Not Connected
        │                       │
        │                       │
        │                       │
        │                       │    cmn_refclk1
        │                       │◄───────────────── External Source (CLKGEN or Remote CLK)
        │      2L SERDES        │
        │                       │
        │                       │ref_der_out_clock/
        │                       │refclk1_out        ┌─────────┐
        │                       │─────────────────► │ ACSPCIE │
        └───────────────────────┘                   └─────────┘

     Each SERDES has two PLLs within it and is responsible for sending data at the high speed data
     rates as defined in the specification (8Gbps for PCIe GEN3, 5Gbps for PCIe GEN2, 2.5Gbps for
     PCIe GEN1, 5Gbps for USB3 SS, 5Gbps for QSGMII [Ethernet]). There are different combinations
     in which these PLLs are progammed but is abstracted from the user and the user only has to
     deal with the input reference clock frequencies and the protocols that the serdes instance
     should support.

     As seen in the figure above, 2L SERDES IP supports 4 clock inputs (core_refclk, core_refclk1,
     cmn_refclk, cmn_refclk1), of which in J7 cmn_refclk is not brought out of SoC). So core_refclk
     should be used for internal reference clock and cmn_refclk1 should be used for external
     reference clock.

    .. rubric:: *Internal Reference Clock*

    In order to use internal reference clock, core_refclk input to 2L SERDES should be used.
    core_refclk can use one of the four inputs.

    .. code-block:: text

        serdes_wiz0: wiz@5000000 {
                compatible = "ti,j721e-wiz-16g";
                .
                .
                assigned-clocks = <&k3_clks 292 11>, <&k3_clks 292 0>;
                assigned-clock-parents = <&k3_clks 292 15>, <&k3_clks 292 4>;
                .
                .
        };

    The "assigned-clocks" and "assigned-clock-parents" sets the parent clock of the
    two internal reference clocks; "core_refclk" and "core_refclk1". The above
    sets the parent of "core_refclk" and "core_refclk1" to MAIN_PLL2_HSDIV4_CLKOUT
    to provide 100MHz clock.

    .. rubric:: *External Reference Clock*

    The 2L SERDES IP supports two external reference clock inputs. However J7 has only one
    external reference clock input connected.

    The two external reference clock inputs are represented in DT (k3-j721e-main.dtsi) like below

    .. code-block:: text

      / {
          cmn_refclk: clock-cmnrefclk {
                  #clock-cells = <0>;
                  compatible = "fixed-clock";
                  clock-frequency = <0>;
          };

          cmn_refclk1: clock-cmnrefclk1 {
                  #clock-cells = <0>;
                  compatible = "fixed-clock";
                  clock-frequency = <0>;
          };
      };

    Note the "clock-frequency = <0>;" is set to "0" since the external clocks need not always
    be connected and is based on the board design. In the case of J721E CPB, there is CLKGEN
    that provides 100MHz clocks to these inputs. So the frequency is actually set in
    k3-j721e-common-proc-board.dts

    .. code-block:: text

       &cmn_refclk1 {
           clock-frequency = <100000000>;
       };

    .. rubric:: *Selecting Between Internal and External Reference Clock*

    Internal or External reference clock is selected using wiz0_pll0_refclk, wiz0_pll1_refclk,
    wiz0_refclk_dig. By default it's connected to internal reference clock in k3-j721e-main.dtsi.

    .. code-block:: text

                wiz0_pll0_refclk: pll0-refclk {
                        clocks = <&k3_clks 292 11>, <&cmn_refclk>;
                        #clock-cells = <0>;
                        assigned-clocks = <&wiz0_pll0_refclk>;
                        assigned-clock-parents = <&k3_clks 292 11>;
                };

                wiz0_pll1_refclk: pll1-refclk {
                        clocks = <&k3_clks 292 0>, <&cmn_refclk1>;
                        #clock-cells = <0>;
                        assigned-clocks = <&wiz0_pll1_refclk>;
                        assigned-clock-parents = <&k3_clks 292 0>;
                };

                wiz0_refclk_dig: refclk-dig {
                        clocks = <&k3_clks 292 11>, <&k3_clks 292 0>, <&cmn_refclk>, <&cmn_refclk1>;
                        #clock-cells = <0>;
                        assigned-clocks = <&wiz0_refclk_dig>;
                        assigned-clock-parents = <&k3_clks 292 11>;
                };

    Each of wiz0_pll0_refclk, wiz0_pll1_refclk, wiz0_refclk_dig has two refernce clock inputs;
    internal clock (k3_clks) and external clock (cmn_refclk).

    The "assigned-clock-parents" by default sets the clock to internal clock.

    However since in J721E Common Processor Board, there is an external clock generator and feeds
    both to the SERDES input and to the PCIe connector, in order to use common reference clock in
    PCIe RC mode, the inputs are configured to use external reference clock.

    For using the external reference clock, the below DT modification are done in
    k3-j721e-common-proc-board.dts

    .. code-block:: text

        &wiz0_pll1_refclk {
            assigned-clocks = <&wiz0_pll1_refclk>;
            assigned-clock-parents = <&cmn_refclk1>;
        };

        &wiz0_refclk_dig {
            assigned-clocks = <&wiz0_refclk_dig>;
            assigned-clock-parents = <&cmn_refclk1>;
        };

        &serdes0 {
            assigned-clocks = <&serdes0 CDNS_SIERRA_PLL_CMNLC>, <&serdes0 CDNS_SIERRA_PLL_CMNLC1>;
            assigned-clock-parents = <&wiz0_pll1_refclk>, <&wiz0_pll1_refclk>;
        };

    Here "wiz0_pll1_refclk" is configured to use external reference clock "cmn_refclk1" and
    "wiz0_refclk_dig" is configured to use external reference clock "&cmn_refclk1"

    CDNS_SIERRA_PLL_CMNLC represents the PLL0 within SERDES and CDNS_SIERRA_PLL_CMNLC1 represents
    the PLL1 within SERDES. Since external clock is not connected to cmn_refclk which is input to
    wiz0_pll0_refclk, PLL0 within SERDES cannot use wiz0_pll0_refclk. Hence we have assign both
    CDNS_SIERRA_PLL_CMNLC and CDNS_SIERRA_PLL_CMNLC1 to use &wiz0_pll1_refclk.

    .. rubric:: **Special Case CPSW9G (PCIe + QSGMII)**

    In the J721E Common Processor Board (for J721E SoC), the 1st SERDES instance is shared between
    PCIe and CPSW9G (1L for PCIe and 1L for CPSW). Since CPSW is configured and used by Ethernet
    Firmware and PCIe is configured and used by Linux, SERDES configuration for this instance
    has to be done before loading ethernet firmware and Linux. Hence the shared SERDES
    configuration is done in u-boot. Since by default firmwares are not loaded in u-boot and
    there is no way to configure only the external PHY in Linux, the QSGMII PHY (VSC8514) in
    Quad Port Add-On Ethernet Card has to be brought out of reset in u-boot.

    The following command should be used to bring the external PHY out of reset

    .. code-block:: text

       setenv dorprocboot 1

    .. rubric:: **Driving Clock Out**

    Support for driving clock out via ACSPCIE using ref_der_out_clock/refclk1_out is not present
    in SDK.

.. ifconfig:: CONFIG_part_variant in ('J721S2')

    .. rubric:: **J721s2 SERDES**

    J721s2 has one 4L Serdes.


    .. rubric:: *SERDES Muxing*

    The Following Section lists the possible ways SERDES can be muxed

        .. rubric:: *SERDES 0*

        .. code-block:: text

                               ┌───────────────────┐
                     EDP_LANE0/│                   │
                   PCIE1_LANE0 │                   │   <-> RX1/TX1
             ──────────────────┤                   ├────────────────
                               │                   │
                               │                   │
                     EDP_LANE1/│                   │
                   PCIE1_LANE1/│                   │
                           USB │                   │   <-> RX2/TX2
             ──────────────────┤                   ├────────────────
                               │                   │
                               │    4L SERDES      │
                     EDP_LANE2/│                   │
                     EDP_LANE0/│                   │
                   PCIE1_LANE2 │                   │   <-> RX3/TX3
             ──────────────────┤                   ├────────────────
                               │                   │
                               │                   │
                     EDP_LANE3/│                   │
                     EDP_LANE1/│                   │
                   PCIE1_LANE3/│                   │
                           USB │                   │   <-> RX4/TX4
             ──────────────────┤                   ├────────────────
                               │                   │
                               └───────────────────┘

    .. rubric:: *DT Muxing Configuration*

    The following shows the default SERDES configuration for
    the J721S2 common processor board.

    .. code-block:: text

        &serdes_ln_ctrl {
            idle-states = <J721S2_SERDES0_LANE0_PCIE1_LANE0>, <J721S2_SERDES0_LANE1_USB>,
                      <J721S2_SERDES0_LANE2_EDP_LANE2>, <J721S2_SERDES0_LANE3_EDP_LANE3>;
        };

        &edp_serdes_mux {
            idle-states = <1>; /* EDP0 to SERDES lane 2/3 /
        };

    Additional edp mux configuration is required to use serdes lane 2 and 3 for edp

    .. rubric:: *Serdes limitation on J721S2*

    - Only 2 IPs can share serdes at a time, below are the possible option

        - USB + PCIe
        - EDP + PCIe (Default SDK combination)
        - EDP + USB (https://git.ti.com/cgit/ti-linux-kernel/ti-upstream-tools/tree/arch/arm64/boot/dts/ti/k3-j721s2-usb3.dtso?h=ti-linux-5.10.y)

      By default EDP + PCIe is enabled for J721S2 common processor board, USB
      is enabled in high speed mode which does not use serdes

    - Serdes can not be shared between RTOS and linux (SW limitation). Currently all
      configuration for serdes sharing is done in linux driver, if serdes is
      used in RTOS running in mcu cores it can not be used in linux
