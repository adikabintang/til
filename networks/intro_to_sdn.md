Computerphile: https://www.youtube.com/watch?v=Nh2hXUuKXyQ 

https://www.youtube.com/watch?v=DiChnu_PAzA

# What is SDN
From wikipedia: Software-defined networking technology is an approach to network management that enables dynamic, programmatically efficient network configuration in order to improve network performance and monitoring making it more like cloud computing than traditional network management.

Key takeaways from [computerphile's video](https://www.youtube.com/watch?v=Nh2hXUuKXyQ):
1. Controlling the network data flow and configuration in a centralized manner
2. The control is done by software
3. The controller is a centralized software able to control the software in the routers/switches with OpenFlow protocol
4. The controller sends rules to the software in routers/switches to control the network behavior explicitly

# Goal of SDN
- open
- programmable

# layer details

```
                                                    
netapp <-> network operating system (controller) <-> forwarding devices (data plane)
```

# Packet flow

When packet arrives, the forwarding devices queries the network operating system to ask what to do with this packet.

There is also fast path: the forwarding knows what to do with this packet and does not have to query network operating system beforehand. This is because there is a cache and the rules are cached.



# 3 layer SDN model



# packet walkthrough example

# availability and scalability

# SDN vs traditional networks

