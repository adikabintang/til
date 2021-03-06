# Offloading

When observing network with wireshark on the sending or receiving node, sometimes the packet seen is larger then ethernet MTU (1500 bytes).

Why?

Because there is TCP offloading: the segmentation is done by the NIC not the CPU. This is an optimization technique to reduce the CPU work for sending and receiving packets.

Ref: 
- https://blog.packet-foo.com/2014/05/the-drawbacks-of-local-packet-captures/
- https://packetbomb.com/how-can-the-packet-size-be-greater-than-the-mtu/

# How to know the available bandwidth from one point to another

On the server:

```
iperf -s
```

On the client:

```
iperf -c server_ip
```

# TCP tuning in linux

https://linux2me.wordpress.com/2018/06/03/tuning-the-tcp-stack-system-administrator/



