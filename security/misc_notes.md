# applied crypto notes

## The difference between MAC, digital signature, and hash (use-case wise)

Very good explanation from: [[crypto.stackexchange.com](https://crypto.stackexchange.com/questions/5646/what-are-the-differences-between-a-digital-signature-a-mac-and-a-hash)]

| Security goal  | Hash | MAC            | Digital Signature |
|----------------|------|----------------|-------------------|
| Integrity      | Yes  | Yes            | Yes               |
| Authentication | No   | Yes            | Yes               |
| Non-repudation | No   | No             | Yes               |
| Kind of keys   | none | symmetric keys | asymmetric keys   |

As a reminder:
- Integrity: makes sure data is not tampered
- Authentication: makes sure the data comes from the stated sender
- Non-repudiation: A send a message and a proof to B. B sends the received message and proof to C. C is still confident that this message and proof come from A (C does not have to trust B). [[security.stackexchange.com](https://security.stackexchange.com/questions/6730/what-is-the-difference-between-authenticity-and-non-repudiation)][[crypto.stackexchange.com](https://crypto.stackexchange.com/questions/5646/what-are-the-differences-between-a-digital-signature-a-mac-and-a-hash)]


# DoS
 
- Asymmetry is the front door into DoS. Example: the server needs to compute every request that comes, but the client does not need to do anything. The client can easily flood the server.


# Platform Security
## Trusted Platform Module (TPM)
source: https://trustedcomputinggroup.org/resource/trusted-platform-module-tpm-summary/

"TPM is a computer chip that securely stores artifacts used to authenticate the platform (PC/laptop/etc)". The artifacts include passwords, certificates, encryption keys.