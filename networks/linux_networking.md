# Offloading

When observing network with wireshark on the sending or receiving node, sometimes the packet seen is larger then ethernet MTU (1500 bytes).

Why?

Because there is TCP offloading: the segmentation is done by the NIC not the CPU. This is an optimization technique to reduce the CPU work for sending and receiving packets.

Ref: 
- https://blog.packet-foo.com/2014/05/the-drawbacks-of-local-packet-captures/
- https://packetbomb.com/how-can-the-packet-size-be-greater-than-the-mtu/