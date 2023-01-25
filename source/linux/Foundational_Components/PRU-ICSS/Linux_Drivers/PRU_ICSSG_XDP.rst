.. _pru_icssg_xdp:

*************
PRU_ICSSG XDP
*************

.. contents:: :local:
    :depth: 3

Introduction
############

XDP stands for eXpress Data Path and provides a framework for BPF that enables high-performance programmable packet processing in the Linux kernel. It runs the BPF program at the earliest possible point in software, namely at the moment the network driver receives the packet.

XDP allows running a BPF program just before the skbs are allocated in the driver, the BPF program can look at the packet and return the following things.

- XDP_DROP :- The packet is dropped right away, without wasting any resources. Useful for firewall etc.
- XDP_ABORTED :- Similar to drop, an exception is generated.
- XDP_PASS :- Pass the packet to kernel stack, i.e. the skbs are allocated and it works normally.
- XDP_TX :- Send the packet back to same NIC with modification(if done by the program).
- XDP_REDIRECT :- Send the packet to another NIC or to the userspace through AF_XDP Socket(discussed below).

.. Image:: /images/xdp-packet-processing.png

As explained above, the XDP_REDIRECT can be used to send a packet directly to the userspace.
This works by using the AF_XDP socket type which was introduced specifically for this usecase.

In this process, the packet is directly sent to the userspace without going through the kernel network stack.

.. Image:: /images/xdp-packet.png

Running XDP on EVM
##################

The ICSSG driver supports XDP. Any application based on XDP can use ICSSG XDP Capablities. By default CONFIG_XDP_SOCKETS is enabled in .config of ti-linux-kernel.
