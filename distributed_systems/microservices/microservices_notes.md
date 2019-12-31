# How to make microservices more resilient

Articles to read:
- [blog.christianposta.com](https://blog.christianposta.com/microservices/3-easy-things-to-do-to-make-your-microservices-more-resilient/)
- ...

## Principles

- **Promises and fallbacks**: _promise_ is what the services intend to do. In case they fail, there should be fallback to handle this. Related tools: Apache Camel and Netflix Hystrix. TODO: learn either of these.
- **Consumer contracts**: Changes to the services does not cause ripple effects of changes for other services. It should follow the principle "sending conservatively and accepting liberally".
- **Idempotent consumers**: avoid idempotent message/command or deploy Apache ActiveMQ to remove duplicate message so that it is only one message/command.

Another thing that might also be considered:
- Isolation
- bulkhead patterns
- load-balancing
- service discovery
- eventual consistency
- apologies

## Related tools
- [Netflix's Chaos Monkey](https://github.com/Netflix/chaosmonkey)
- [Netflix's Hystrix](https://github.com/Netflix/Hystrix)

# Data in microservices

## Shared database in microservices problems

- https://blog.christianposta.com/microservices/the-hardest-part-about-microservices-data/