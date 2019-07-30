# Stream id

When we follow stream, it shows something like:

```
udp.stream eq 49
```

That filters the udp stream id 49. How stream ID is created?

It combines source IP, source port, destination IP and destination port ([ref](https://stackoverflow.com/questions/6076897/follow-tcp-stream-where-does-field-stream-index-come-from)). Therefore measuring HTTP response time be seeing the TCP session duration (or UDP for QUIC) is a bad idea. 

# TCP segmentation captured by libpcap

If one packet contains more than Ethernet MTU (1500 bytes), probably TCP segmentation offloading (TSO) is the one who does it.

See [here](https://blog.packet-foo.com/2014/05/the-drawbacks-of-local-packet-captures/) for details on how it works.

Here is how to turn that off: [link](https://docs.gz.ro/tuning-network-cards-on-linux.html). Remember that turning it off means we are disabling one of the TCP optimization on the OS level.